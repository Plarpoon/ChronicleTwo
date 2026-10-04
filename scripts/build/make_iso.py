#!/usr/bin/env python3
"""Master a disc image: the retail one, with built files in place of its own.

    make_iso.py --source <retail.iso> --out <built.iso> <file>...

Each file named on the command line replaces the disc file of the same name
(`SCES_511.90` replaces `/SCES_511.90;1`). Every other sector is the retail
image's, so mastering the retail executable gives back the retail image byte
for byte, and the game finds everything else exactly where it shipped.

The disc is a single-layer DVD carrying two descriptions of one set of files:
an ISO 9660 tree, which is what the console reads, and a UDF 1.02 one, which
is what most PC tools read. Both are kept true:

- A file that still fits in the sectors between its own start and the next
  thing on the disc is written where it was, and its ISO 9660 directory
  record and UDF file entry take the new size. Sectors it no longer uses are
  zeroed.
- A file that has outgrown that space moves to the end of the disc, past
  everything else. The volume and the UDF partition grow to hold it, and the
  UDF anchor that closes the disc moves to the new last sector. Its old
  sectors are zeroed.

The ISO 9660 path tables stay at sectors 257 and 259, where the console reads
them on DVD media whatever the volume descriptor says, because nothing here
moves them.

Copying the 4.4 GB image is the slow part, so it is done once. The sectors a
run writes are recorded beside the output (`<out>.patched`); the next run puts
those back from the retail image and patches again, rather than copying the
whole disc. An output without that record, or one whose retail image has
changed since, is copied afresh.
"""

import argparse
import json
import os
import shutil
import struct
import sys

SECTOR = 2048

# ISO 9660 volume descriptors start at sector 16 and run to a terminator.
VD_START = 16
VD_PRIMARY, VD_SUPPLEMENTARY, VD_TERMINATOR = 1, 2, 255

# UDF (ECMA-167) descriptor tag identifiers.
TAG_PD = 5          # partition descriptor
TAG_LVD = 6         # logical volume descriptor
TAG_TD = 8          # terminating descriptor
TAG_LVID = 9        # logical volume integrity descriptor
TAG_FSD = 256       # file set descriptor
TAG_FID = 257       # file identifier descriptor
TAG_FE = 261        # file entry
ANCHOR_LBA = 256

# ICB allocation descriptor forms, the low bits of an ICB tag's flags.
AD_SHORT, AD_LONG = 0, 1
FID_DIRECTORY, FID_DELETED, FID_PARENT = 0x02, 0x04, 0x08


def crc16(data):
    """CRC-16/CCITT (polynomial 0x1021, initial 0), as UDF descriptor tags use."""
    crc = 0
    for byte in data:
        crc ^= byte << 8
        for _ in range(8):
            crc = ((crc << 1) ^ 0x1021) if crc & 0x8000 else crc << 1
            crc &= 0xFFFF
    return crc


def retag(desc, crc_length=None):
    """Recompute a UDF descriptor tag's CRC and checksum in place."""
    if crc_length is None:
        crc_length = struct.unpack_from('<H', desc, 10)[0]
    struct.pack_into('<HH', desc, 8, crc16(bytes(desc[16:16 + crc_length])), crc_length)
    desc[4] = (sum(desc[0:4]) + sum(desc[5:16])) & 0xFF


def both_endian32(buf, offset, value):
    """Write an ISO 9660 both-byte-order 32-bit field."""
    struct.pack_into('<I', buf, offset, value)
    struct.pack_into('>I', buf, offset + 4, value)


class Disc:
    """What the source image says about where each file is."""

    def __init__(self, path):
        self.fp = open(path, 'rb')
        self.sectors = os.path.getsize(path) // SECTOR
        # name -> [{'path', 'extent', 'size', 'record'}]: `record` is the byte
        # offset of the file's ISO 9660 directory record in the image.
        self.iso_files = {}
        # Everything the ISO 9660 tree allocates, as (first sector, count).
        self.allocated = []
        self.volume_descriptors = []
        self._read_iso9660()
        self.udf_files = {}
        self._read_udf()

    def read(self, lba, count=1):
        self.fp.seek(lba * SECTOR)
        return self.fp.read(count * SECTOR)

    # ISO 9660

    def _read_iso9660(self):
        lba = VD_START
        while True:
            desc = self.read(lba)
            if desc[1:6] != b'CD001':
                sys.exit(f'sector {lba} is not an ISO 9660 volume descriptor')
            if desc[0] == VD_TERMINATOR:
                break
            if desc[0] in (VD_PRIMARY, VD_SUPPLEMENTARY):
                self.volume_descriptors.append(lba)
            lba += 1
        pvd = self.read(self.volume_descriptors[0])
        self.volume_sectors = struct.unpack_from('<I', pvd, 80)[0]
        self._walk(pvd[156:190], '/')

    def _walk(self, record, path):
        extent, size = struct.unpack_from('<I', record, 2)[0], struct.unpack_from('<I', record, 10)[0]
        count = (size + SECTOR - 1) // SECTOR
        self.allocated.append((extent, count))
        data = self.read(extent, count)[:size]
        offset = 0
        while offset < len(data):
            length = data[offset]
            if length == 0:
                offset = (offset // SECTOR + 1) * SECTOR
                continue
            child = data[offset:offset + length]
            name = child[33:33 + child[32]]
            if name not in (b'\0', b'\1'):
                text = name.decode('latin-1')
                if child[25] & 2:
                    self._walk(child, f'{path}{text}/')
                else:
                    c_extent = struct.unpack_from('<I', child, 2)[0]
                    c_size = struct.unpack_from('<I', child, 10)[0]
                    self.allocated.append((c_extent, (c_size + SECTOR - 1) // SECTOR))
                    key = text.split(';')[0].rstrip('.')
                    self.iso_files.setdefault(key, []).append({
                        'path': f'{path}{text}', 'extent': c_extent, 'size': c_size,
                        'record': extent * SECTOR + offset})
            offset += length

    # UDF

    def _tag(self, lba, ident):
        desc = self.read(lba)
        if struct.unpack_from('<H', desc, 0)[0] != ident:
            sys.exit(f'sector {lba}: expected UDF descriptor {ident}')
        return bytearray(desc)

    def _read_udf(self):
        anchor = self.read(ANCHOR_LBA)
        if struct.unpack_from('<H', anchor, 0)[0] != 2:
            self.udf = False
            return
        self.udf = True
        self.anchors = [lba for lba in (ANCHOR_LBA, self.sectors - 257, self.sectors - 1)
                        if struct.unpack_from('<HxxxxxxxxxxI', self.read(lba), 0) == (2, lba)]
        main_len, main_loc, res_len, res_loc = struct.unpack_from('<IIII', anchor, 16)
        self.partition_descriptors = []
        self.integrity = []
        lvd = None
        for loc, length in ((main_loc, main_len), (res_loc, res_len)):
            for lba in range(loc, loc + length // SECTOR):
                ident = struct.unpack_from('<H', self.read(lba), 0)[0]
                if ident == TAG_TD:
                    break
                if ident == TAG_PD:
                    self.partition_descriptors.append(lba)
                elif ident == TAG_LVD and lvd is None:
                    lvd = self._tag(lba, TAG_LVD)
        pd = self._tag(self.partition_descriptors[0], TAG_PD)
        self.partition_start, self.partition_length = struct.unpack_from('<II', pd, 188)
        # A partition header naming a space table or bitmap would need
        # updating as well when the partition grows; this disc has none.
        self.partition_header_empty = not any(pd[56:56 + 40])
        int_len, int_loc = struct.unpack_from('<II', lvd, 432)
        for lba in range(int_loc, int_loc + int_len // SECTOR):
            if struct.unpack_from('<H', self.read(lba), 0)[0] == TAG_LVID:
                self.integrity.append(lba)
        fsd_block = struct.unpack_from('<I', lvd, 252)[0]
        fsd = self._tag(self.partition_start + fsd_block, TAG_FSD)
        root_block = struct.unpack_from('<I', fsd, 404)[0]
        self._walk_udf(self.partition_start + root_block, '/')

    def _extents(self, fe):
        """The (partition block, length) extents a file entry allocates."""
        flags = struct.unpack_from('<H', fe, 34)[0] & 7
        l_ea, l_ad = struct.unpack_from('<II', fe, 168)
        base = 176 + l_ea
        size = {AD_SHORT: 8, AD_LONG: 16}.get(flags)
        if size is None:
            sys.exit('unsupported UDF allocation descriptor form')
        out = []
        for offset in range(base, base + l_ad, size):
            length, block = struct.unpack_from('<II', fe, offset)
            out.append((block, length & 0x3FFFFFFF, offset))
        return flags, out

    def _walk_udf(self, fe_lba, path):
        fe = self._tag(fe_lba, TAG_FE)
        _flags, extents = self._extents(fe)
        self.allocated.append((fe_lba, 1))
        for block, length, _ in extents:
            self.allocated.append((self.partition_start + block, (length + SECTOR - 1) // SECTOR))
        data = b''.join(self.read(self.partition_start + block, (length + SECTOR - 1) // SECTOR)[:length]
                        for block, length, _ in extents)
        offset = 0
        while offset + 38 <= len(data):
            if struct.unpack_from('<H', data, offset)[0] != TAG_FID:
                break
            chars, l_fi = data[offset + 18], data[offset + 19]
            icb_block = struct.unpack_from('<I', data, offset + 24)[0]
            l_iu = struct.unpack_from('<H', data, offset + 36)[0]
            raw = data[offset + 38 + l_iu:offset + 38 + l_iu + l_fi]
            offset += (38 + l_iu + l_fi + 3) & ~3
            if chars & (FID_PARENT | FID_DELETED):
                continue
            name = raw[1:].decode('latin-1') if raw[:1] == b'\x08' else raw[1:].decode('utf-16-be')
            child = self.partition_start + icb_block
            if chars & FID_DIRECTORY:
                self._walk_udf(child, f'{path}{name}/')
            else:
                self.allocated.append((child, 1))
                self.udf_files.setdefault(name.rstrip('.').split(';')[0].upper(), []).append(
                    {'path': f'{path}{name}', 'entry': child})


def master(source, out, replacements):
    disc = Disc(source)

    targets = []
    for local in replacements:
        name = os.path.basename(local)
        iso = disc.iso_files.get(name, [])
        if len(iso) != 1:
            sys.exit(f'{name}: {"not on the disc" if not iso else "more than one file has this name"}')
        udf = disc.udf_files.get(name.upper(), []) if disc.udf else []
        if disc.udf and len(udf) != 1:
            sys.exit(f'{name}: no single UDF file entry matches it')
        targets.append((local, iso[0], udf[0] if udf else None))

    # Where each allocation starts, where the last one ends, and the first
    # sector no file may use: the closing UDF anchor, when it follows them.
    starts = sorted({lba for lba, _count in disc.allocated})
    end_of_files = max(lba + count for lba, count in disc.allocated)
    disc_end = disc.anchors[-1] if disc.udf and disc.anchors[-1] >= end_of_files else disc.sectors

    record_path = out + '.patched'
    source_stat = os.stat(source)
    # Size and whole-second modification time: the same image seen through a
    # container's bind mount reports the same identity as on the host.
    identity = {'size': source_stat.st_size, 'mtime': int(source_stat.st_mtime)}
    previous = None
    try:
        with open(record_path) as f:
            previous = json.load(f)
    except (OSError, ValueError):
        pass
    if (previous is None or previous.get('identity') != identity
            or not os.path.isfile(out) or os.path.getsize(out) != previous.get('out_size')):
        previous = None

    # Until this run finishes, the output is neither the retail image nor a
    # finished master, so the record of what was patched goes first.
    if os.path.exists(record_path):
        os.remove(record_path)

    os.makedirs(os.path.dirname(out) or '.', exist_ok=True)
    src = open(source, 'rb')
    if previous is None:
        print(f'  copying {source}', flush=True)
        shutil.copyfile(source, out)
    else:
        with open(out, 'r+b') as image:
            image.truncate(source_stat.st_size)
            for lba, count in previous['sectors']:
                if lba >= disc.sectors:
                    continue
                count = min(count, disc.sectors - lba)
                src.seek(lba * SECTOR)
                image.seek(lba * SECTOR)
                image.write(src.read(count * SECTOR))

    written = []
    image = open(out, 'r+b')

    def put(lba, data):
        """Write whole sectors at lba, zero-padding the last one."""
        data = bytes(data)
        if len(data) % SECTOR:
            data += b'\0' * (SECTOR - len(data) % SECTOR)
        image.seek(lba * SECTOR)
        image.write(data)
        written.append([lba, len(data) // SECTOR])

    def get(lba):
        image.seek(lba * SECTOR)
        return bytearray(image.read(SECTOR))

    new_end = disc.sectors
    tail = end_of_files
    for local, iso, udf in targets:
        with open(local, 'rb') as f:
            data = f.read()
        old_count = (iso['size'] + SECTOR - 1) // SECTOR
        new_count = (len(data) + SECTOR - 1) // SECTOR
        following = next((lba for lba in starts if lba > iso['extent']), disc_end)
        room = min(following, disc_end) - iso['extent']

        if new_count <= room:
            extent = iso['extent']
            put(extent, data + b'\0' * (max(old_count - new_count, 0) * SECTOR))
            where = 'in place'
        else:
            # The file outgrows its slot: free that and move to the end.
            put(iso['extent'], b'\0' * (old_count * SECTOR))
            extent = tail
            put(extent, data)
            tail = extent + new_count
            where = f'moved to sector {extent}'
            if not disc.udf or not disc.partition_header_empty:
                sys.exit(f'{os.path.basename(local)} does not fit and this disc cannot grow')
        print(f'  {iso["path"]}: {len(data)} bytes from {local}, {where}', flush=True)

        record_lba = iso['record'] // SECTOR
        sector = get(record_lba)
        offset = iso['record'] % SECTOR
        both_endian32(sector, offset + 2, extent)
        both_endian32(sector, offset + 10, len(data))
        put(record_lba, sector)

        if udf:
            fe = get(udf['entry'])
            flags, extents = disc._extents(fe)
            if len(extents) != 1:
                sys.exit(f'{udf["path"]}: expected one allocation extent')
            ad = extents[0][2]
            struct.pack_into('<I', fe, ad, len(data))
            struct.pack_into('<I', fe, ad + 4, extent - disc.partition_start)
            struct.pack_into('<QQ', fe, 56, len(data), new_count)
            retag(fe)
            put(udf['entry'], fe)

    if tail > end_of_files:
        # The volume now ends past the moved files, with a UDF anchor in its
        # last sector as before.
        new_end = max(tail + 1, disc.sectors)
        for lba in disc.volume_descriptors:
            vd = get(lba)
            both_endian32(vd, 80, new_end)
            put(lba, vd)
        length = new_end - 1 - disc.partition_start
        for lba in disc.partition_descriptors:
            pd = get(lba)
            struct.pack_into('<I', pd, 192, length)
            retag(pd)
            put(lba, pd)
        for lba in disc.integrity:
            lvid = get(lba)
            parts = struct.unpack_from('<I', lvid, 72)[0]
            # Size table entry for the one partition, after the free space table.
            struct.pack_into('<I', lvid, 80 + 4 * parts, length)
            retag(lvid)
            put(lba, lvid)
        # The old closing anchor is either under the moved files now or, when
        # they ended short of it, still the last sector, rewritten below.
        anchor = bytearray(disc.read(disc.anchors[-1]))
        image.truncate(new_end * SECTOR)
        struct.pack_into('<I', anchor, 12, new_end - 1)
        retag(anchor)
        put(new_end - 1, anchor)

    image.close()
    src.close()
    disc.fp.close()

    with open(record_path, 'w') as f:
        json.dump({'identity': identity, 'out_size': os.path.getsize(out),
                   'sectors': written}, f)
    print(f'Wrote {out} ({os.path.getsize(out)} bytes)')


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument('--source', required=True, help='the retail disc image')
    ap.add_argument('--out', required=True, help='the image to write')
    ap.add_argument('files', nargs='+', help='built files to use instead of the disc\'s own')
    args = ap.parse_args()
    master(args.source, args.out, args.files)


if __name__ == '__main__':
    main()
