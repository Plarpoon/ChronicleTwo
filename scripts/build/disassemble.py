#!/usr/bin/env python3
"""Split the retail executable into the assembly the build reads.

    disassemble.py              run splat, then write every game unit's
                                per-symbol files
    disassemble.py --no-splat   only write the per-symbol files

splat (run from ps2/config/<region>, as main.yaml expects) writes the
whole-unit file `ps2/asm/<region>/<unit>.s` for every unit and, for a game
unit whose source marks a function `INCLUDE_ASM`, that function's file under
`ps2/asm/<region>/nonmatchings/<unit>/`. This script adds the rest of what a
game unit's markers name, in the same directory:

- its static initialiser (the `.sinit` subsegment, linked as `.init`), cut out
  of the whole-unit file, since splat writes no file of its own for it;
- one file per initialised datum in `.data`, `.rodata`, `.ctor`, `.vtables`
  and `.sdata`, written from the retail executable's bytes and relocations.

A unit's run of a data section is cut at every symbol main.symbols.txt lists
in it, and at every unnamed address (`D_<ADDR8>`) that splat's assembly refers
to, so each such address is a symbol the unit defines; a run that does not
start on a symbol starts with an invented `D_<ADDR8>`. Each piece runs to the
next cut, so padding belongs to the datum before it. `.sbss` and `.bss` are cut
the same way; the source defines those pieces itself (`pieces`).
"""

import argparse
import os
import re
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(Path(__file__).resolve().parent))

import layout  # noqa: E402

CODE_SECTIONS = (".text", ".init")
DATA_SECTIONS = (".data", ".rodata", ".ctor", ".vtables", ".sdata")
BSS_SECTIONS = (".sbss", ".bss")

NONMATCHINGS = layout.ASM / "nonmatchings"
MATCHINGS = layout.ASM / "matchings"

R_MIPS_32 = 2

HEADER = '.include "macro.inc"\n\n.set noat\n.set noreorder\n\n'

INVENTED = re.compile(r"\bD_([0-9A-F]{8})\b")
SECTION_LINE = re.compile(r"^\s*\.section\s+([^\s,]+)")
GLABEL = re.compile(r"^\s*glabel\s+(\S+)\s*$")


def invented_name(address):
    return f"D_{address:08X}"


def invented_address(name):
    """The address an invented `D_<ADDR8>` name spells, or None."""
    m = re.fullmatch(r"D_([0-9A-F]{8})", name)
    return int(m.group(1), 16) if m else None


def referenced_addresses(lay):
    """Every unnamed address splat's assembly refers to.

    A game unit's own data is written here rather than taken from splat, so
    only its code is read; every other unit's file is read whole.
    """
    paths = [(ROOT / lay.reference(u), lay.kinds[u] == "cpp") for u in lay.units()]
    paths += [(p, False) for p in sorted((ROOT / layout.ASM / "data").rglob("*.s"))]
    found = set()
    for path, code_only in paths:
        if not path.is_file():
            continue
        section = ".text"
        for line in path.read_text(encoding="utf-8").splitlines():
            m = SECTION_LINE.match(line)
            if m:
                section = m.group(1)
                continue
            if code_only and section not in CODE_SECTIONS:
                continue
            if GLABEL.match(line):
                continue
            for m in INVENTED.finditer(line):
                found.add(int(m.group(1), 16))
    return found


class Pieces:
    """How each game unit's sections divide into symbols."""

    def __init__(self, lay=None, symbols=None, references=None):
        self.layout = lay or layout.Layout()
        self.symbols = symbols or layout.SymbolIndex()
        if references is None:
            references = referenced_addresses(self.layout)
        self.references = sorted(references)
        self._cache = {}

    def listed(self, lo, hi):
        return [(a, n) for a, n, _s, _f in self.symbols.within(lo, hi)
                if n not in layout.LINKER_SYMBOLS]

    def of(self, unit, section, lo, hi):
        """[(name, start, end)] for one of the unit's section runs."""
        key = (unit, section)
        if key in self._cache:
            return self._cache[key]
        names = dict(self.listed(lo, hi))
        if section not in CODE_SECTIONS:
            names.setdefault(lo, invented_name(lo))
            for address in self.references:
                if lo <= address < hi:
                    names.setdefault(address, invented_name(address))
        starts = sorted(names)
        out = [(names[a], a, starts[i + 1] if i + 1 < len(starts) else hi)
               for i, a in enumerate(starts)]
        self._cache[key] = out
        return out

    def unit(self, unit):
        """[(section, [(name, start, end)])] in address order."""
        return [(s, self.of(unit, s, lo, hi)) for s, lo, hi in self.layout.sections(unit)]

    def defined(self):
        """[(address, name)] of every symbol the link defines, sorted.

        The listed symbols, less those the linker script defines, and the
        names invented for game units' data.
        """
        out = {a: n for a, n, _s, _f in self.symbols.rows if n not in layout.LINKER_SYMBOLS}
        for unit in self.layout.units("cpp"):
            for section, pieces in self.unit(unit):
                for name, start, _end in pieces:
                    out.setdefault(start, name)
        return sorted(out.items())


class Resolver:
    """Spell an address as `<symbol> + <offset>` against the defined symbols."""

    def __init__(self, defined):
        import bisect
        self._bisect = bisect
        self.addresses = [a for a, _n in defined]
        self.names = [n for _a, n in defined]

    def __call__(self, address):
        i = self._bisect.bisect_right(self.addresses, address) - 1
        if i < 0:
            return None
        offset = address - self.addresses[i]
        name = self.names[i]
        return name if offset == 0 else f"{name} + 0x{offset:X}"


def data_file(name, start, end, retail, resolve):
    """One datum's assembly, as tools/mwccgap's INCLUDE_RODATA reads it."""
    # `.align 0` stops gas aligning `.word` to four bytes, so a datum that
    # starts off a word boundary still assembles to exactly its extent.
    lines = ['.include "macro.inc"', "", ".section .rodata", ".align 0", "",
             f"glabel {name}"]
    data = retail.bytes(start, end)
    address = start
    while address < end:
        kind = retail.relocations.get(address)
        if address % 4 == 0 and address + 4 <= end:
            if kind is not None:
                if kind != R_MIPS_32:
                    raise ValueError(f"{name}: relocation type {kind} at 0x{address:08X}")
                target = resolve(retail.word(address))
                if target is None:
                    raise ValueError(f"{name}: no symbol for 0x{retail.word(address):08X}")
                lines.append(f"    /* {address:08X} */ .word {target}")
            else:
                value = int.from_bytes(data[address - start:address - start + 4], "little")
                lines.append(f"    /* {address:08X} */ .word 0x{value:08X}")
            address += 4
        else:
            if kind is not None:
                raise ValueError(f"{name}: relocation at 0x{address:08X} straddles a symbol")
            lines.append(f"    /* {address:08X} */ .byte 0x{data[address - start]:02X}")
            address += 1
    return "\n".join(lines) + "\n"


def sinit_files(lay, unit):
    """{name: assembly} for the functions of the unit's `.init` run."""
    text = (ROOT / lay.reference(unit)).read_text(encoding="utf-8").splitlines()
    out = {}
    section = None
    current = None
    for line in text:
        m = SECTION_LINE.match(line)
        if m:
            section = m.group(1)
            current = None
            continue
        if section != ".init":
            continue
        m = GLABEL.match(line)
        if m:
            current = m.group(1)
            out[current] = []
        if current is not None:
            out[current].append(line)
    return {name: HEADER + "\n".join(lines).rstrip() + "\n" for name, lines in out.items()}


def write_if_changed(path, text):
    if path.is_file() and path.read_text(encoding="utf-8") == text:
        return
    path.write_text(text, encoding="utf-8")


def write_unit_files(pieces, retail, resolve, unit):
    lay = pieces.layout
    directory = ROOT / NONMATCHINGS / unit
    directory.mkdir(parents=True, exist_ok=True)
    count = 0
    for section, run in pieces.unit(unit):
        if section in DATA_SECTIONS:
            for name, start, end in run:
                write_if_changed(directory / f"{name}.s",
                                 data_file(name, start, end, retail, resolve))
                count += 1
        elif section == ".init":
            expected = {name for name, _s, _e in run}
            files = sinit_files(lay, unit)
            if set(files) != expected:
                raise ValueError(f"{unit}: .init holds {sorted(files)}, expected {sorted(expected)}")
            for name, text in files.items():
                write_if_changed(directory / f"{name}.s", text)
                count += 1
    return count


def run_splat():
    """Run splat in this process, from the directory main.yaml expects."""
    try:
        import splat.scripts.split as split
    except ImportError:
        # The development image installs splat into a virtual environment
        # that is not first on PATH.
        venv = Path("/opt/venv")
        if (venv / "bin/python3").is_file() and Path(sys.prefix) != venv:
            python = str(venv / "bin/python3")
            os.execv(python, [python, str(Path(__file__).resolve())] + sys.argv[1:])
        raise
    import spimdisasm
    from rabbitizer import TrinaryValue
    from splat.segtypes.common.c import CommonSegC

    original = CommonSegC.split

    # gas spells the R5900's special registers `$ACC`, `$I`, `$Q`. splat turns
    # that on only around the whole-unit file it writes last, so it is set
    # here before the per-function files are written too.
    def split_unit(self, rom_bytes):
        if self.spim_section is not None:
            for symbol in self.spim_section.get_section().symbolList:
                if isinstance(symbol, spimdisasm.mips.symbols.SymbolFunction):
                    for instruction in symbol.instructions:
                        instruction.flag_r5900UseDollar = TrinaryValue.TRUE
        return original(self, rom_bytes)

    CommonSegC.split = split_unit

    # A function moves between nonmatchings/ and matchings/ as it is
    # decompiled, and splat leaves the stale copy behind.
    for path in (ROOT / NONMATCHINGS, ROOT / MATCHINGS):
        shutil.rmtree(path, ignore_errors=True)

    cwd = os.getcwd()
    os.chdir(ROOT / layout.CONFIG)
    try:
        split.main([Path("main.yaml")], None, False, use_cache=False)
    finally:
        os.chdir(cwd)


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--no-splat", action="store_true",
                    help="only write the per-symbol files splat does not")
    ap.add_argument("units", nargs="*", help="game units to write (default: all)")
    args = ap.parse_args()

    os.chdir(ROOT)
    if not args.no_splat:
        run_splat()

    lay = layout.Layout()
    pieces = Pieces(lay)
    retail = layout.Retail()
    resolve = Resolver(pieces.defined())
    units = args.units or lay.units("cpp")
    total = 0
    for unit in units:
        total += write_unit_files(pieces, retail, resolve, unit)
    print(f"wrote {total} files for {len(units)} units")
    return 0


if __name__ == "__main__":
    sys.exit(main())
