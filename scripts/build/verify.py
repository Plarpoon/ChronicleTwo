#!/usr/bin/env python3
"""Check the extracted files, or the built executable, against retail.

    verify.py [-c] [--build-dir DIR]   the built image against retail's,
                                       section by section (the default)
    verify.py -e                       the extracted files against
                                       rom/<region>/extracted.sha256

The built executable matches when its `main` section holds retail's bytes
from 0x00100000 to the end of .sdata and its loaded segment reaches as far
into memory as retail's, through .sbss and .bss.
"""

import argparse
import hashlib
import os
import struct
import sys
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import layout  # noqa: E402

GREEN, RED, GREY, END = "\033[92m", "\033[91m", "\033[90m", "\033[0m"
if not sys.stdout.isatty():
    GREEN = RED = GREY = END = ""

ROM = Path(f"rom/{layout.REGION}")
PT_LOAD = 1


class Image:
    """An executable's `main` section and the memory its segment spans."""

    def __init__(self, path):
        data = Path(path).read_bytes()
        phoff, shoff = struct.unpack_from("<II", data, 0x1C)
        phentsize, phnum, shentsize, shnum, shstrndx = struct.unpack_from("<HHHHH", data, 0x2A)
        sections = []
        for i in range(shnum):
            name, _type, _flags, addr, offset, size = struct.unpack_from(
                "<6I", data, shoff + i * shentsize)
            sections.append((name, addr, offset, size))
        names = sections[shstrndx][2]

        def name_of(s):
            return data[names + s[0]:data.index(b"\0", names + s[0])].decode()

        _n, self.base, offset, size = next(s for s in sections if name_of(s) == "main")
        self.bytes = data[offset:offset + size]
        self.memory_end = self.base + size
        for i in range(phnum):
            p_type, _off, vaddr, _paddr, _filesz, memsz = struct.unpack_from(
                "<6I", data, phoff + i * phentsize)
            if p_type == PT_LOAD and vaddr == self.base:
                self.memory_end = vaddr + memsz

    def span(self, lo, hi):
        return self.bytes[lo - self.base:hi - self.base]


def owner(lay, section, address):
    for unit, lo, hi in lay.section_units(section):
        if lo <= address < hi:
            return unit
    return "?"


def compare(build_dir):
    built_path = Path(build_dir) / layout.BASENAME
    if not built_path.exists():
        print(f"{built_path}: {RED}FAILED{END} - file doesn't exist")
        return False
    retail = Image(layout.ELF_PATH)
    built = Image(built_path)
    lay = layout.Layout()
    symbols = layout.SymbolIndex()
    ok = True
    print(f"Verifying {built_path}")
    for name, lo, hi in layout.SECTIONS:
        if name in layout.NOBITS:
            continue
        want, got = retail.span(lo, hi), built.span(lo, hi)
        if want == got:
            print(f"  {name:<9} {GREEN}OK{END}")
            continue
        ok = False
        differing = sum(a != b for a, b in zip(want, got)) + abs(len(want) - len(got))
        first = next((i for i, (a, b) in enumerate(zip(want, got)) if a != b), min(len(want), len(got)))
        address = lo + first
        near = symbols.at_or_before(address)
        where = f"{near[1]}+{address - near[0]:#x}" if near else ""
        print(f"  {name:<9} {RED}FAILED{END} {differing:#x} bytes differ, the first at "
              f"{address:#010x} in {owner(lay, name, address)} {GREY}({where}){END}")
    if len(built.bytes) != len(retail.bytes):
        ok = False
        print(f"  main      {RED}FAILED{END} {len(built.bytes):#x} bytes long, retail "
              f"{len(retail.bytes):#x}")
    if built.memory_end != retail.memory_end:
        ok = False
        print(f"  .bss      {RED}FAILED{END} memory ends at {built.memory_end:#010x}, retail "
              f"{retail.memory_end:#010x}")
    else:
        print(f"  {'.bss':<9} {GREEN}OK{END} {GREY}(memory ends at {built.memory_end:#010x}){END}")
    print(f"{layout.BASENAME}: {GREEN + 'OK' if ok else RED + 'FAILED'}{END}")
    return ok


def verify_extracted():
    ok = True
    print("Verifying extracted files")
    for line in (ROM / "extracted.sha256").read_text().splitlines():
        if not line.strip():
            continue
        digest, name = line.split(None, 1)
        path = ROM.parent / name.lstrip("*")
        if not path.exists():
            ok = False
            print(f"  {name}: {RED}FAILED{END} - file doesn't exist")
            continue
        h = hashlib.sha256()
        with open(path, "rb") as f:
            for block in iter(lambda: f.read(1 << 20), b""):
                h.update(block)
        good = h.hexdigest() == digest.lower()
        ok &= good
        print(f"  {name}: {GREEN + 'OK' if good else RED + 'FAILED'}{END}")
    return ok


def main():
    os.chdir(os.path.abspath(os.path.join(os.path.dirname(__file__), os.pardir, os.pardir)))
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("-c", "--compare", action="store_true",
                    help="compare the built image with retail's (the default)")
    ap.add_argument("-e", "--verify-extracted", action="store_true",
                    help="check the extracted files against their hashes")
    ap.add_argument("--build-dir", default=os.environ.get("BUILD_DIR", str(layout.BUILD)))
    args = ap.parse_args()
    ok = True
    if args.verify_extracted:
        ok &= verify_extracted()
    if args.compare or not args.verify_extracted:
        ok &= compare(args.build_dir)
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
