#!/usr/bin/env python3
"""Give each section of a compiled game unit retail's name, type, flags and alignment.

    postprocess_object.py <object>

MWCC emits every function and every datum in a section of its own, named for
what the compiler made of it: a datum tools/mwccgap supplies is a `const`
array to the compiler, so it lands in `.rodata` whatever retail's section is.
Each allocated section here is looked up by the symbol it defines -- in
main.symbols.txt, or by the address an invented `D_<ADDR8>` name spells -- and
given the section retail holds that address in:

- the name `layout.section_of` gives, and the matching `.rel<name>` for its
  relocations;
- NOBITS for `.sbss` and `.bss`, PROGBITS otherwise;
- the flags of that kind of section, `.sdata` and `.sbss` carrying the MIPS
  gp-relative flag as MWCC sets it, `.init` being code;
- alignment 1 for a datum, whose extent already runs to the next symbol, so
  no padding is added between pieces; a function keeps the compiler's.

A section whose symbol retail does not name -- a compiler-generated one, in a
decompiled function's future -- is left as the compiler emitted it.

A datum's placeholder is defined under an alias (`layout.PLACEHOLDER_SUFFIX`),
so that the source can also see the datum's typed declaration; the alias is
dropped here, before anything is looked up by name.

tools/mwccgap adds a symbol a datum's relocations refer to a second time, and
a datum that refers to itself carries the assembler's section index rather
than the object's. Every such duplicate is folded into the symbol the object
already defines, so a reference resolves to the unit's own definition.
"""

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools" / "mwccgap"))
sys.path.insert(0, str(Path(__file__).resolve().parent))

from mwccgap.elf import Elf, RelocationRecord, SHT_NOBITS  # noqa: E402

import layout  # noqa: E402

SHT_PROGBITS = 1
SHF_WRITE = 0x1
SHF_ALLOC = 0x2
SHF_EXECINSTR = 0x4
SHF_MIPS_GPREL = 0x10000000

STT_SECTION = 3
STB_LOCAL = 0

FLAGS = {
    ".text": SHF_ALLOC | SHF_EXECINSTR,
    ".init": SHF_ALLOC | SHF_EXECINSTR,
    ".data": SHF_WRITE | SHF_ALLOC,
    ".rodata": SHF_ALLOC,
    ".ctor": SHF_WRITE | SHF_ALLOC,
    ".vtables": SHF_WRITE | SHF_ALLOC,
    ".sdata": SHF_WRITE | SHF_ALLOC | SHF_MIPS_GPREL,
    ".sbss": SHF_WRITE | SHF_ALLOC | SHF_MIPS_GPREL,
    ".bss": SHF_WRITE | SHF_ALLOC,
}
CODE = (".text", ".init")

INVENTED = re.compile(r"D_([0-9A-F]{8})")


def name_sections(elf):
    """Name every section; mwccgap's reader leaves its `.text` sections unnamed."""
    for section in elf.sections:
        section.name = elf.shstrtab.get_symbol_by_index(section.sh_name)


def retail_addresses():
    return {name: address for address, name, _s, _f in layout.read_symbols(ROOT / layout.SYMBOLS)}


def address_of(name, addresses):
    address = addresses.get(name)
    if address is None:
        m = INVENTED.fullmatch(name)
        if m:
            address = int(m.group(1), 16)
    return address


def drop_placeholder_aliases(elf):
    """Give every placeholder's symbol the name of the datum it stands for."""
    suffix = layout.PLACEHOLDER_SUFFIX
    for symbol in elf.symtab.symbols:
        if symbol.name.endswith(suffix):
            symbol.name = symbol.name[:-len(suffix)]
            symbol.st_name = elf.strtab.add_symbol(symbol.name)


def fold_duplicates(elf):
    """Keep one symbol per global name; repoint relocations at it."""
    symbols = elf.symtab.symbols
    keep = {}
    for index, symbol in enumerate(symbols):
        if index == 0 or symbol.bind == STB_LOCAL or not symbol.name:
            continue
        held = keep.get(symbol.name)
        if held is None or (symbols[held].st_shndx == 0 and symbol.st_shndx != 0):
            keep[symbol.name] = index
    remap = {}
    kept = []
    for index, symbol in enumerate(symbols):
        if index and symbol.bind != STB_LOCAL and symbol.name and keep[symbol.name] != index:
            continue
        remap[index] = len(kept)
        kept.append(symbol)
    if len(kept) == len(symbols):
        return
    # sh_info counts the leading entries the table treats as local.
    elf.symtab.sh_info = sum(1 for i in range(elf.symtab.sh_info) if i in remap)
    for index, symbol in enumerate(symbols):
        if index not in remap:
            remap[index] = remap[keep[symbol.name]]
    elf.symtab.symbols = kept
    for record in elf.relocations:
        for relocation in record.relocations:
            relocation.symbol_index = remap[relocation.symbol_index]


def retail_sections(elf, addresses):
    """{section index: retail section name} for every section retail names."""
    out = {}
    for symbol in elf.symtab.symbols:
        index = symbol.st_shndx
        if not symbol.name or symbol.type == STT_SECTION or not (0 < index < len(elf.sections)):
            continue
        if symbol.st_value != 0:
            continue
        section = elf.sections[index]
        if not section.sh_flags & SHF_ALLOC:
            continue
        address = address_of(symbol.name, addresses)
        if address is None:
            continue
        name = layout.section_of(address)
        if name is None:
            raise ValueError(f"{symbol.name}: 0x{address:08X} is in no retail section")
        if out.get(index, name) != name:
            raise ValueError(f"section {index} holds symbols of {out[index]} and {name}")
        out[index] = name
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("object", type=Path)
    args = ap.parse_args()

    elf = Elf(args.object.read_bytes())
    name_sections(elf)
    drop_placeholder_aliases(elf)
    fold_duplicates(elf)
    renamed = retail_sections(elf, retail_addresses())

    for index, name in renamed.items():
        section = elf.sections[index]
        nobits = name in layout.NOBITS
        if nobits != (section.sh_type == SHT_NOBITS):
            raise ValueError(f"section {index} ({section.name}) cannot become {name}")
        section.sh_name = elf.add_sh_symbol(name)
        section.name = name
        section.sh_flags = FLAGS[name]
        if name not in CODE:
            section.sh_addralign = 1

    for record in elf.relocations:
        if record.sh_info in renamed:
            record.sh_name = elf.add_sh_symbol(".rel" + renamed[record.sh_info])
            record.name = ".rel" + renamed[record.sh_info]

    empty = [s.name for s in elf.sections if s.sh_flags & SHF_ALLOC
             and (s.sh_size if s.sh_type == SHT_NOBITS else len(s.data)) == 0]
    if empty:
        raise ValueError(f"zero-sized sections, which MWLD rejects: {empty}")

    args.object.write_bytes(elf.pack())
    return 0


if __name__ == "__main__":
    sys.exit(main())
