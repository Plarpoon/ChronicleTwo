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
- for a placeholder, the alignment its retail address allows (up to 16), which
  adds no padding after a placeholder whose extent already runs to it and
  restores the compiler's after a compiled datum; a function or a compiled
  datum keeps the compiler's.

A section whose symbol retail does not name -- a compiler-generated one, in a
decompiled function's future -- is left as the compiler emitted it, but for
the alignment of a `.rodata` one: retail has every compiler-generated literal
of `.rodata` on a multiple of eight, and this compiler gives one of four
bytes or fewer, such as the string "BIN", a multiple of four, so its
alignment is raised to eight.

A datum's placeholder is defined under an alias (`layout.PLACEHOLDER_SUFFIX`),
so that the source can also see the datum's typed declaration; the alias is
dropped here, before anything is looked up by name.

A compiled function may use data the unit still supplies through a
placeholder: a string or floating-point literal, a function-local static, a
file-local variable. The compiler emits its own copy of each, under a name of
its own. Every reference a compiled function makes to such a copy is repointed
at the placeholder holding the address retail's instruction refers to, and a
copy nothing refers to any more is checked against retail's bytes and marked
`.dead` for scripts/build/fixup_sections.sh to remove -- so a function can be
compiled before the data it uses is migrated (`bind_local_data`).

tools/mwccgap adds a symbol a datum's relocations refer to a second time, and
a datum that refers to itself carries the assembler's section index rather
than the object's. Every such duplicate is folded into the symbol the object
already defines, so a reference resolves to the unit's own definition.
"""

import argparse
import bisect
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools" / "mwccgap"))
sys.path.insert(0, str(Path(__file__).resolve().parent))

from mwccgap.elf import Elf, Symbol, RelocationRecord, SHT_NOBITS  # noqa: E402

import layout  # noqa: E402

SHT_PROGBITS = 1
SHF_WRITE = 0x1
SHF_ALLOC = 0x2
SHF_EXECINSTR = 0x4
SHF_MIPS_GPREL = 0x10000000

STT_SECTION = 3
STT_OBJECT = 1
STT_FUNC = 2
STB_MWCC_COALESCED = 13
STB_LOCAL = 0
STB_WEAK = 2

R_MIPS_32 = 2
R_MIPS_HI16 = 5
R_MIPS_LO16 = 6
R_MIPS_GPREL16 = 7

DEAD = ".dead"

# The least alignment retail gives a compiler-generated literal of `.rodata`.
RODATA_ALIGNMENT = 8

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
    """Give every placeholder's symbol the name of the datum it stands for.

    Returns the indices of the sections the placeholders occupy.
    """
    suffix = layout.PLACEHOLDER_SUFFIX
    sections = set()
    for symbol in elf.symtab.symbols:
        if symbol.name.endswith(suffix):
            symbol.name = symbol.name[:-len(suffix)]
            symbol.st_name = elf.strtab.add_symbol(symbol.name)
            if 0 < symbol.st_shndx < len(elf.sections):
                sections.add(symbol.st_shndx)
    return sections


def project_name(name):
    """A compiler's symbol name as main.symbols.txt spells it."""
    name = re.sub(r"[,<>.$]", "_", name)
    return "at_" + name[1:] if name.startswith("@") else name


def sext16(value):
    value &= 0xFFFF
    return value - 0x10000 if value & 0x8000 else value


def section_size(section):
    return section.sh_size if section.sh_type == SHT_NOBITS else len(section.data)


def rename_shared_names(elf, rows, address_of_section, retail, gp):
    """Spell an undefined symbol the way main.symbols.txt does.

    Two retail symbols of one name are told apart there by a `__<n>` suffix,
    which compiled code cannot know: it refers to the plain name. Which of
    them a reference means is read off the address retail's instruction has
    at the same place.
    """
    plain = {name: address for address, name, _s, _f in rows}
    candidates = {}
    for address, name, _size, _func in rows:
        m = re.fullmatch(r"(.+)__\d+", name)
        if m:
            candidates.setdefault(m.group(1), []).append((address, name))
    for name, options in candidates.items():
        if name in plain:
            options.append((plain[name], name))
    symbols = elf.symtab.symbols
    for record in elf.relocations:
        base = address_of_section.get(record.sh_info)
        section = elf.sections[record.sh_info]
        if base is None or not section.sh_flags & SHF_EXECINSTR:
            continue
        relocations = record.relocations
        for k, relocation in enumerate(relocations):
            symbol = symbols[relocation.symbol_index]
            options = candidates.get(project_name(symbol.name))
            if symbol.st_shndx != 0 or not options:
                continue
            offset = relocation.r_offset
            word = retail.word(base + offset)
            if relocation.reloc_type == 4:
                target = ((base + offset) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)
            elif relocation.reloc_type == R_MIPS_GPREL16:
                target = gp + sext16(word)
            elif relocation.reloc_type in (R_MIPS_HI16, R_MIPS_LO16):
                kind = R_MIPS_LO16 if relocation.reloc_type == R_MIPS_HI16 else R_MIPS_HI16
                order = list(range(k + 1, len(relocations))) + list(range(k - 1, -1, -1))
                other = next((relocations[j] for j in order
                              if relocations[j].reloc_type == kind
                              and relocations[j].symbol_index == relocation.symbol_index), None)
                if other is None:
                    continue
                hi, lo = ((offset, other.r_offset) if relocation.reloc_type == R_MIPS_HI16
                          else (other.r_offset, offset))
                target = ((retail.word(base + hi) & 0xFFFF) << 16) + sext16(retail.word(base + lo))
            else:
                continue
            chosen = [name for address, name in options if address == target]
            if len(chosen) == 1:
                symbol.name = chosen[0]
                symbol.st_name = elf.strtab.add_symbol(symbol.name)


def bind_local_data(elf, unit, placeholder_sections):
    """Point compiled code at the placeholders of the data it uses.

    Returns the names of the compiler's copies that were dropped.
    """
    lay = layout.Layout(ROOT / layout.YAML)
    if lay.kinds.get(unit) != "cpp":
        return []
    ranges = [(lo, hi) for _s, lo, hi in lay.sections(unit)]

    def in_unit(address):
        return any(lo <= address < hi for lo, hi in ranges)

    rows = layout.read_symbols(ROOT / layout.SYMBOLS)
    gp = next(a for a, n, _s, _f in rows if n == "_gp")
    # The unit's own names; a local that shares its name with another unit's
    # carries a `__<n>` suffix in main.symbols.txt and none in the object.
    names = {}
    for address, name, _size, _func in rows:
        if in_unit(address):
            names[name] = address
            names.setdefault(re.sub(r"__\d+$", "", name), address)

    sections = elf.sections
    symbols = elf.symtab.symbols
    address_of_section = {}
    defining_symbol = {}
    for index, symbol in enumerate(symbols):
        at = symbol.st_shndx
        if (not symbol.name or symbol.type == STT_SECTION or symbol.st_value != 0
                or not 0 < at < len(sections) or not sections[at].sh_flags & SHF_ALLOC
                or symbol.name.startswith(".")):
            continue
        code = bool(sections[at].sh_flags & SHF_EXECINSTR)
        if not code and at not in placeholder_sections:
            continue
        name = project_name(symbol.name)
        address = names.get(name)
        if address is None:
            m = INVENTED.fullmatch(name)
            if m and in_unit(int(m.group(1), 16)):
                address = int(m.group(1), 16)
        if address is not None and at not in address_of_section:
            address_of_section[at] = address
            defining_symbol[at] = index

    held = sorted((address_of_section[i], i) for i in placeholder_sections
                  if i in address_of_section)
    starts = [a for a, _i in held]

    def placeholder_at(address):
        k = bisect.bisect_right(starts, address) - 1
        if k < 0:
            return None
        start, index = held[k]
        return (start, index) if address < start + max(section_size(sections[index]), 1) else None

    retail = layout.Retail(ROOT / layout.ELF_PATH)
    bound = {}
    for record in elf.relocations:
        at = record.sh_info
        if at not in address_of_section or not sections[at].sh_flags & SHF_EXECINSTR:
            continue
        base = address_of_section[at]
        data = bytearray(sections[at].data)
        relocations = record.relocations
        # Pairs are found by the symbols the compiler wrote, which the loop
        # below replaces as it goes.
        original = [r.symbol_index for r in relocations]

        def word(offset):
            return struct.unpack_from("<I", data, offset)[0]

        def partner(k, kind):
            """The nearest relocation of `kind` against the same symbol."""
            symbol = original[k]
            order = list(range(k + 1, len(relocations))) + list(range(k - 1, -1, -1))
            if kind == R_MIPS_HI16:
                order = list(range(k - 1, -1, -1)) + list(range(k + 1, len(relocations)))
            for j in order:
                if relocations[j].reloc_type == kind and original[j] == symbol:
                    return relocations[j]
            return None

        changed = False
        for k, relocation in enumerate(relocations):
            target = symbols[original[k]]
            to = target.st_shndx
            if (not 0 < to < len(sections) or to in placeholder_sections
                    or not sections[to].sh_flags & SHF_ALLOC
                    or sections[to].sh_flags & SHF_EXECINSTR):
                continue
            kind = relocation.reloc_type
            offset = relocation.r_offset
            if kind == R_MIPS_GPREL16:
                theirs = gp + sext16(retail.word(base + offset))
                ours = sext16(word(offset))
            elif kind in (R_MIPS_HI16, R_MIPS_LO16):
                other = partner(k, R_MIPS_LO16 if kind == R_MIPS_HI16 else R_MIPS_HI16)
                if other is None:
                    continue
                hi, lo = (offset, other.r_offset) if kind == R_MIPS_HI16 else (other.r_offset, offset)
                theirs = ((retail.word(base + hi) & 0xFFFF) << 16) + sext16(retail.word(base + lo))
                ours = ((word(hi) & 0xFFFF) << 16) + sext16(word(lo))
            else:
                continue
            found = placeholder_at(theirs)
            if found is None:
                continue
            start, index = found
            addend = theirs - start
            if kind == R_MIPS_HI16:
                field = ((addend + 0x8000) >> 16) & 0xFFFF
            else:
                field = addend & 0xFFFF
            struct.pack_into("<I", data, offset, (word(offset) & 0xFFFF0000) | field)
            if kind != R_MIPS_HI16:
                bound.setdefault(to, theirs - ours - target.st_value)
            relocation.symbol_index = defining_symbol[index]
            changed = True
        if changed:
            sections[at].data = bytes(data)

    rename_shared_names(elf, rows, address_of_section, retail, gp)

    referenced = {symbols[r.symbol_index].st_shndx
                  for record in elf.relocations for r in record.relocations}
    dropped = []
    for index, start in bound.items():
        if index in referenced:
            continue
        section = sections[index]
        label = next((s.name for s in symbols if s.st_shndx == index and s.name
                      and s.type != STT_SECTION), f"section {index}")
        has_relocations = any(r.sh_info == index and r.relocations for r in elf.relocations)
        if section.sh_type != SHT_NOBITS and not has_relocations:
            size = len(section.data)
            if bytes(section.data) != retail.bytes(start, start + size):
                raise ValueError(f"{label}: the compiled datum differs from retail's at "
                                 f"0x{start:08X}")
        section.sh_name = elf.add_sh_symbol(DEAD)
        section.name = DEAD
        for record in elf.relocations:
            if record.sh_info == index:
                record.sh_name = elf.add_sh_symbol(".rel" + DEAD)
                record.name = ".rel" + DEAD
        dropped.append(label)

    starts = {index: start for index, start in bound.items() if sections[index].name == DEAD}
    while True:
        live = {symbols[r.symbol_index].st_shndx for record in elf.relocations
                if sections[record.sh_info].name != DEAD for r in record.relocations}
        found = {}
        for record in elf.relocations:
            base = starts.get(record.sh_info)
            if base is None:
                continue
            data = sections[record.sh_info].data
            for relocation in record.relocations:
                target = symbols[relocation.symbol_index]
                to = target.st_shndx
                if (relocation.reloc_type != R_MIPS_32 or not 0 < to < len(sections)
                        or to in live or to in starts or to in found or to in placeholder_sections
                        or not sections[to].sh_flags & SHF_ALLOC
                        or sections[to].sh_flags & SHF_EXECINSTR):
                    continue
                ours = struct.unpack_from("<I", data, relocation.r_offset)[0]
                found[to] = retail.word(base + relocation.r_offset) - ours - target.st_value
        if not found:
            break
        for index, start in found.items():
            section = sections[index]
            label = next((s.name for s in symbols if s.st_shndx == index and s.name
                          and s.type != STT_SECTION), f"section {index}")
            has_relocations = any(r.sh_info == index and r.relocations for r in elf.relocations)
            if section.sh_type != SHT_NOBITS and not has_relocations:
                size = len(section.data)
                if bytes(section.data) != retail.bytes(start, start + size):
                    raise ValueError(f"{label}: the compiled datum differs from retail's at "
                                     f"0x{start:08X}")
            section.sh_name = elf.add_sh_symbol(DEAD)
            section.name = DEAD
            for record in elf.relocations:
                if record.sh_info == index:
                    record.sh_name = elf.add_sh_symbol(".rel" + DEAD)
                    record.name = ".rel" + DEAD
            starts[index] = start
            dropped.append(label)
    return dropped


def bind_suffixed_references(elf, unit):
    lay = layout.Layout(ROOT / layout.YAML)
    if lay.kinds.get(unit) != "cpp":
        return set()
    ranges = [(lo, hi) for _s, lo, hi in lay.sections(unit)]
    own = {name for address, name, _size, _func in layout.read_symbols(ROOT / layout.SYMBOLS)
           if re.fullmatch(r".+__\d+", name) and any(lo <= address < hi for lo, hi in ranges)}
    symbols = elf.symtab.symbols
    defined = {}
    for index, symbol in enumerate(symbols):
        if (symbol.name and symbol.type != STT_SECTION and 0 < symbol.st_shndx < len(elf.sections)
                and elf.sections[symbol.st_shndx].name != DEAD):
            defined.setdefault(symbol.name, index)
    remap = {}
    shadowed = set()
    for name in sorted(own - set(defined)):
        plain = re.sub(r"__\d+$", "", name)
        if plain not in defined:
            continue
        definition = symbols[defined[plain]]
        if definition.bind == STB_LOCAL:
            for index, symbol in enumerate(symbols):
                if symbol.st_shndx == 0 and symbol.name == name:
                    remap[index] = defined[plain]
            continue
        alias = Symbol(0, definition.st_value, definition.st_size,
                       (definition.bind << 4) | definition.type, definition.st_other,
                       definition.st_shndx)
        alias.name = name
        elf.add_symbol(alias, force=True)
        shadowed.add(plain)
    for record in elf.relocations:
        for relocation in record.relocations:
            if relocation.symbol_index in remap:
                relocation.symbol_index = remap[relocation.symbol_index]
    return shadowed


def fold_duplicates(elf):
    """Keep one symbol per global name; repoint relocations at it."""
    symbols = elf.symtab.symbols
    local = {}
    for index, symbol in enumerate(symbols):
        if (index and symbol.bind == STB_LOCAL and symbol.name and symbol.type != STT_SECTION
                and 0 < symbol.st_shndx < len(elf.sections)):
            local.setdefault(symbol.name, index)
    own = {index: local[symbol.name] for index, symbol in enumerate(symbols)
           if index and symbol.st_shndx == 0 and symbol.bind != STB_LOCAL
           and symbol.name in local}
    if own:
        for record in elf.relocations:
            for relocation in record.relocations:
                relocation.symbol_index = own.get(relocation.symbol_index, relocation.symbol_index)
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


def placeholder_alignment(elf, index, addresses):
    for symbol in elf.symtab.symbols:
        if symbol.st_shndx == index and symbol.name and symbol.type != STT_SECTION:
            address = address_of(symbol.name, addresses)
            if address is not None:
                return min(16, address & -address) if address else 16
    return 1


def retail_sections(elf, addresses, shadowed=frozenset()):
    """{section index: retail section name} for every section retail names."""
    out = {}
    for symbol in elf.symtab.symbols:
        if symbol.name in shadowed and symbol.bind != STB_LOCAL:
            continue
        index = symbol.st_shndx
        if not symbol.name or symbol.type == STT_SECTION or not (0 < index < len(elf.sections)):
            continue
        if symbol.st_value != 0:
            continue
        section = elf.sections[index]
        if not section.sh_flags & SHF_ALLOC or section.name == DEAD:
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
    placeholder_sections = drop_placeholder_aliases(elf)
    shadowed = set()
    name = args.object.name
    if name.endswith(".cpp.o"):
        bind_local_data(elf, name[:-len(".cpp.o")], placeholder_sections)
        shadowed = bind_suffixed_references(elf, name[:-len(".cpp.o")])
    fold_duplicates(elf)
    addresses = retail_addresses()
    renamed = retail_sections(elf, addresses, shadowed)

    for index, name in renamed.items():
        section = elf.sections[index]
        nobits = name in layout.NOBITS
        if nobits != (section.sh_type == SHT_NOBITS):
            raise ValueError(f"section {index} ({section.name}) cannot become {name}")
        section.sh_name = elf.add_sh_symbol(name)
        section.name = name
        section.sh_flags = FLAGS[name]
        if name not in CODE and index in placeholder_sections:
            section.sh_addralign = placeholder_alignment(elf, index, addresses)

    for index, section in enumerate(elf.sections):
        if (index not in renamed and section.name == ".rodata" and section.sh_flags & SHF_ALLOC
                and section.sh_addralign < RODATA_ALIGNMENT):
            section.sh_addralign = RODATA_ALIGNMENT

    for record in elf.relocations:
        if record.sh_info in renamed:
            record.sh_name = elf.add_sh_symbol(".rel" + renamed[record.sh_info])
            record.name = ".rel" + renamed[record.sh_info]

    empty = [s.name for s in elf.sections if s.sh_flags & SHF_ALLOC and s.name != DEAD
             and (s.sh_size if s.sh_type == SHT_NOBITS else len(s.data)) == 0]
    if empty:
        raise ValueError(f"zero-sized sections, which MWLD rejects: {empty}")

    for symbol in elf.symtab.symbols:
        if symbol.bind == STB_MWCC_COALESCED and symbol.type in (STT_FUNC, STT_OBJECT):
            symbol.bind = STB_WEAK

    args.object.write_bytes(elf.pack())
    return 0


if __name__ == "__main__":
    sys.exit(main())
