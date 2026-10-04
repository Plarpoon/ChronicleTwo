#!/usr/bin/env python3
"""Extract the contents of the game disc into rom/<region>/extracted/iso.

    extract.py            extract what is missing
    extract.py --force    extract every file again
    extract.py --elf      extract only SYSTEM.CNF and the executable

The files are read through the image's ISO 9660 directory tree, so nothing
beyond the standard library is needed.
"""

import argparse
import os
import struct
import sys
from pathlib import Path

# Constants
COLOR_GREEN = '\033[92m'
COLOR_END = '\033[0m'
SECTOR = 2048

# Directories
REGION = os.environ.get('REGION', 'PAL').lower()
ISO_PATH = Path(f'rom/{REGION}/Dark Chronicle ({REGION.upper()}).iso')
EXTRACT_DIR = Path(f'rom/{REGION}/extracted')
ISO_EXTRACT_DIR = EXTRACT_DIR / 'iso'

# Files
ELF_NAMES = {'pal': 'SCES_511.90'}
ELF_PATH = ISO_EXTRACT_DIR / ELF_NAMES[REGION]


def ensure_dir(path):
    path.mkdir(parents=True, exist_ok=True)


def is_current(file_path, size):
    """Whether this file was already extracted from the image at hand.

    Size alone settles it: the one thing this has to catch is a file that is
    missing or was written by an interrupted run.
    """
    try:
        return file_path.stat().st_size == size
    except OSError:
        return False


def prune(entries):
    """Drop files the image no longer has, left by an earlier extraction."""
    wanted = {path.resolve() for _iso_path, path, _size, _extent in entries}
    removed = 0
    for path in ISO_EXTRACT_DIR.rglob('*'):
        if path.is_file() and path.resolve() not in wanted:
            path.unlink()
            removed += 1
    return removed


class Iso9660:
    """The ISO 9660 directory tree of a disc image."""

    def __init__(self, path):
        self.fp = open(path, 'rb')
        pvd = self._read(16 * SECTOR, SECTOR)
        if pvd[1:6] != b'CD001':
            raise SystemExit(f'{path} is not an ISO 9660 image')
        self.root = self._record(pvd[156:190])

    def _read(self, offset, size):
        self.fp.seek(offset)
        return self.fp.read(size)

    @staticmethod
    def _record(raw):
        extent, = struct.unpack_from('<I', raw, 2)
        size, = struct.unpack_from('<I', raw, 10)
        flags = raw[25]
        name = raw[33:33 + raw[32]]
        return name, extent, size, bool(flags & 2)

    def children(self, directory):
        _name, extent, size, _is_dir = directory
        data = self._read(extent * SECTOR, size)
        offset = 0
        while offset < len(data):
            length = data[offset]
            if length == 0:
                offset = (offset // SECTOR + 1) * SECTOR
                continue
            record = self._record(data[offset:offset + length])
            offset += length
            if record[0] not in (b'\0', b'\1'):
                yield record

    def collect(self, directory, iso_path, dest, entries):
        """Every file in the image, as (iso path, destination, size, extent)."""
        for name, extent, size, is_dir in self.children(directory):
            identifier = name.decode()
            if is_dir:
                self.collect((name, extent, size, is_dir), f'{iso_path}{identifier}/',
                             dest / identifier, entries)
                continue
            file_name = identifier.split(';')[0]

            # Strip empty file extensions (e.g. DMMY. -> DMMY)
            if file_name.endswith('.'):
                file_name = file_name[:-1]
            entries.append((f'{iso_path}{identifier}', dest / file_name, size, extent))

    def extract(self, extent, size, out_path):
        with open(out_path, 'wb') as f:
            self.fp.seek(extent * SECTOR)
            left = size
            while left:
                chunk = self.fp.read(min(left, 1 << 24))
                if not chunk:
                    raise SystemExit(f'{out_path}: the image ends before the file does')
                f.write(chunk)
                left -= len(chunk)

    def close(self):
        self.fp.close()


def extract_iso(force=False, elf_only=False):
    # Ensure the original ISO exists
    if not ISO_PATH.exists():
        sys.exit(f'ISO does not exist!\nEnsure {ISO_PATH.name} is placed within {ISO_PATH.parent}.')

    ensure_dir(ISO_EXTRACT_DIR)

    # What is already there is left alone: the disc is 4.4GB, most of it
    # DATA.DAT, SOUND.DAT and the movies, and every build would otherwise
    # write the whole of it again.
    print('Extracting ISO contents', flush=True)
    iso = Iso9660(ISO_PATH)
    entries = []
    iso.collect(iso.root, '/', ISO_EXTRACT_DIR, entries)
    if elf_only:
        entries = [e for e in entries if e[1].name in ('SYSTEM.CNF', ELF_PATH.name)]

    kept = 0
    for absolute_iso_path, file_path, size, extent in entries:
        if not force and is_current(file_path, size):
            kept += 1
            continue
        ensure_dir(file_path.parent)
        print(f'  {absolute_iso_path}: ', end='', flush=True)
        iso.extract(extent, size, file_path)
        print(f'{COLOR_GREEN}DONE{COLOR_END}', flush=True)
    iso.close()

    stale = 0 if elf_only else prune(entries)
    print(f'Extracted {len(entries) - kept} file(s); {kept} already present, '
          f'{stale} stale file(s) removed', flush=True)


if __name__ == "__main__":
    # Change to work from the root directory
    root_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), os.pardir, os.pardir))
    os.chdir(root_dir)

    parser = argparse.ArgumentParser(description='Extract the game disc for decompilation')
    parser.add_argument('-f', '--force', action='store_true',
                        help='Extract every file again, rather than only what is missing')
    parser.add_argument('--elf', action='store_true',
                        help='Extract only SYSTEM.CNF and the executable')
    args = parser.parse_args()

    extract_iso(args.force, args.elf)
