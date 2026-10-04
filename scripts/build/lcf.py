#!/usr/bin/env python3
"""Write the linker script that lays the main image out as retail has it.

    lcf.py            write ps2/config/<region>/SCES_511.90.lcf
    lcf.py --check    fail if the checked-in script differs from what this writes
    lcf.py -o FILE    write it somewhere else

Every translation unit's run of every section is named in the script at the
retail address it starts at, in the order main.yaml lists them. Between two
runs the script states how `.` gets from where the first run's own contents
end to where the second starts: nothing when they meet, else the smallest
`ALIGN(n)` that lands on the retail address, else an absolute assignment.
"""

import argparse
import difflib
import os
import sys
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import layout  # noqa: E402

LCF = layout.CONFIG / f"{layout.BASENAME}.lcf"
UNDEFINED_SYMS = layout.BUILD / "splat" / "main.undefined_syms.txt"

# Units the linker writes itself rather than links: retail's `.rdata` holds
# only the overlay group table, one word giving main's load address.
LINKER_WRITTEN = {"rdata"}

INDENT = " " * 8
OBJECT_COLUMN = 36


def align_up(value, n):
    return (value + n - 1) & ~(n - 1)


def advance(here, target):
    """The directive that takes `.` from `here` to `target`, or None."""
    if here == target:
        return None
    if here < target:
        n = 2
        while n <= 0x1000:
            if align_up(here, n) == target:
                return f". = ALIGN({n:#x});"
            n *= 2
    return f". = {target:#010x};"


class Generator:
    def __init__(self, yaml=layout.YAML):
        self.layout = layout.Layout(yaml)
        self.symbols = layout.SymbolIndex()
        # Retail's linker-defined names, by address: one that falls inside a
        # unit's run marks where that run's own contents end.
        self.linker_marks = sorted(a for a, n, _s, _f in self.symbols.rows
                                   if n in layout.LINKER_SYMBOLS and n != "_gp")
        self.lines = []
        self.names = {}
        self.here = None

    def object_name(self, unit, section):
        if unit in self.layout.kinds:
            path = self.layout.object_path(unit)
        else:
            path = self.layout.data_object_path(unit, section)
        name = os.path.basename(path)
        # MWLD knows an object by its file name alone.
        if self.names.setdefault(name, path) != path:
            raise SystemExit(f"{path} and {self.names[name]} share the name {name}")
        return name

    def contents_end(self, unit, lo, hi):
        """Where the unit's own bytes in [lo, hi) end.

        An assembly unit's object is the whole run splat wrote, padding and
        all. A compiled unit's object holds its functions and data and
        nothing after them: retail's padding before the next unit, where it
        has any, belongs to the script.
        """
        for mark in self.linker_marks:
            if lo < mark < hi:
                return mark
        if self.layout.kinds.get(unit) != "cpp":
            return hi
        rows = self.symbols.within(lo, hi)
        if not rows or rows[-1][2] == 0:
            return hi
        return min(hi, max(a + s for a, _n, s, _f in rows))

    def emit(self, text=""):
        self.lines.append(f"{INDENT}{text}" if text else "")

    def comment(self, *text):
        for t in text:
            self.emit(f"// {t}" if t else "//")

    def move_to(self, target, note=None):
        step = advance(self.here, target)
        if step:
            self.emit(f"{step:<{OBJECT_COLUMN + 12}}// {target:#010x}"
                      + (f" {note}" if note else ""))
        self.here = target

    def symbol(self, name, value=None, note=None):
        """`name = .;`, or an absolute value; retail's value in the comment."""
        retail = self.symbols.by_name.get(name)
        if value is None:
            text = f"{name} = .;"
            shown = self.here
        else:
            text = f"{name} = {value};"
            shown = None
        tail = []
        if shown is not None:
            tail.append(f"{shown:#010x}")
        if note:
            tail.append(note)
        self.emit(f"{text:<{OBJECT_COLUMN + 12}}// {' '.join(tail)}" if tail else text)
        if retail and shown is not None and retail[0] != shown:
            raise SystemExit(f"{name}: placed at {shown:#x}, retail has {retail[0]:#x}")

    def runs(self, section, wildcard=True):
        for unit, lo, hi in self.layout.section_units(section):
            if unit in LINKER_WRITTEN:
                continue
            self.move_to(lo)
            name = self.object_name(unit, section)
            self.emit(f"{name:<{OBJECT_COLUMN}}({section})".ljust(OBJECT_COLUMN + 12)
                      + f"// {lo:#010x}")
            self.here = self.contents_end(unit, lo, hi)
        if wildcard:
            self.emit(f"*({section})")

    def generate(self):
        sections = {name: (lo, hi) for name, lo, hi in layout.SECTIONS}
        out = self.lines
        out += [
            f"// The main image of {layout.BASENAME}, laid out as retail has it.",
            "//",
            "// Generated by scripts/build/lcf.py from main.yaml and retail's symbol",
            "// table, then kept by hand: rerun the script after a unit is added,",
            "// removed or moves, and carry any hand edits across.",
            "",
            "MEMORY",
            "{",
            "    main (RWX) : ORIGIN = 0x00100000, LENGTH = 0",
            "    heap (RW)  : ORIGIN = AFTER(main), LENGTH = 0",
            "}",
            "",
            "SECTIONS",
            "{",
            "    .main :",
            "    {",
        ]
        self.comment(
            "Every unit's run of every section, at the retail address beside it,",
            "in main.yaml's order. Each input section is placed on the alignment",
            "its own object states (MWLD's default; ALIGNALL only ever raises",
            "it), so an object must never ask for more than its retail address",
            "has:",
            "  - a compiled unit has one section per function, aligned to 16, and",
            "    one per datum, aligned to 1 and running to the next datum, so",
            "    nothing inside a unit needs aligning;",
            "  - an assembly unit (crt0, the libraries, the data-only units) is",
            "    one section per name holding the unit's whole run, padding",
            "    included, aligned to no more than its run's start.",
            "Where retail leaves padding between two units, the directive before",
            "the second states it: the smallest ALIGN that reaches the address",
            "from where the first unit's own contents end. MWLD fills it with",
            "zeros. The wildcard after each list takes anything not named.",
        )
        self.here = layout.VRAM
        self.emit()
        self.emit("# text")
        self.runs(".text")

        self.emit()
        self.emit("# VU microprograms")
        self.runs(".vutext")

        self.emit()
        self.emit("# data")
        self.move_to(sections[".data"][0])
        self.symbol("__data_start")
        self.runs(".data")

        self.emit()
        self.emit("# the frame's DMA chains")
        self.runs(".vudata")

        self.emit()
        self.emit("# rodata")
        self.runs(".rodata")

        self.emit()
        self.emit("# static initialisers, and the table __init_cpp calls them through")
        self.runs(".init")
        self.move_to(sections[".ctor"][0])
        self.symbol("__static_init")
        self.runs(".ctor")
        self.symbol("__static_init_end")

        self.emit()
        self.emit("# vtables")
        self.runs(".vtables")

        self.emit()
        self.emit("# exception tables: retail has none")
        self.move_to(sections[".rdata"][0])
        self.symbol("__exception_table_start__")
        self.emit("EXCEPTION")
        self.symbol("__exception_table_end__")
        self.comment(
            "The overlay group table: retail has no overlays, so it is the one",
            "word giving main's own address, written by the linker without a",
            "relocation.",
        )
        self.symbol("_overlay_group_addresses")
        self.emit("WRITEW(ADDR(.main));")
        self.here += 4
        self.symbol("__data_end")

        self.emit()
        self.emit("# sdata")
        self.move_to(sections[".sdata"][0])
        self.symbol("_gp", ". + 0x7ff0", f"{sections['.sdata'][0] + 0x7ff0:#010x}")
        self.runs(".sdata")

        self.emit()
        self.emit("# sbss")
        self.move_to(sections[".sbss"][0])
        self.symbol("_fbss")
        self.runs(".sbss")

        self.emit()
        self.emit("# bss")
        self.move_to(sections[".bss"][0])
        self.symbol("__bss_start")
        self.runs(".bss")
        self.move_to(sections[".bss"][1], "the end of main")
        self.symbol("__bss_end")

        self.emit()
        self.emit("# the sizes crt0 clears and copies by, and the run-time's memory")
        self.symbol("__data_size", "__data_end - __data_start",
                    f"{self.value('__data_size'):#010x}")
        self.symbol("__bss_size", "__bss_end - __bss_start",
                    f"{self.value('__bss_size'):#010x}")
        self.symbol("_stack", "0x01F80000")
        self.symbol("_stack_size", "0x00080000")
        self.comment("-1: the heap runs from _end to the bottom of the stack.")
        self.symbol("_heap_size", "0xFFFFFFFF")
        self.symbol("_align_segment", "0x00000080")

        undefined = self.undefined()
        if undefined:
            self.emit()
            self.comment(
                "Addresses the split assembly reaches by a name splat made up,",
                "because no symbol in retail's table stands there.",
            )
            for name, value in undefined:
                self.symbol(name, f"{value:#010x}")

        out += [
            "    } > main",
            "",
            "    .heap :",
            "    {",
        ]
        self.symbol("_end")
        self.symbol("end")
        self.emit(". = ALIGN(0x10);")
        out += [
            "    } > heap",
            "}",
            "",
        ]
        return "\n".join(out)

    def value(self, name):
        """A linker symbol's retail value; these are not in the symbol list."""
        values = {
            "__data_size": 0x0037C6F4 - 0x0032A320,
            "__bss_size": 0x01F64A00 - 0x0037EAD5,
        }
        return values[name]

    def undefined(self):
        if not UNDEFINED_SYMS.exists():
            return []
        rows = []
        for line in UNDEFINED_SYMS.read_text().splitlines():
            line = line.split("//")[0].strip().rstrip(";")
            if "=" not in line:
                continue
            name, value = (s.strip() for s in line.split("=", 1))
            rows.append((name, int(value, 0)))
        return rows


def main():
    os.chdir(os.path.abspath(os.path.join(os.path.dirname(__file__), os.pardir, os.pardir)))
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("-o", "--output", default=str(LCF))
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    text = Generator().generate()
    if args.check:
        current = Path(args.output).read_text() if Path(args.output).exists() else ""
        if current != text:
            sys.stdout.writelines(difflib.unified_diff(
                current.splitlines(True), text.splitlines(True), args.output, "lcf.py"))
            return 1
        return 0
    Path(args.output).write_text(text)
    return 0


if __name__ == "__main__":
    sys.exit(main())
