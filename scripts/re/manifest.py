#!/usr/bin/env python3
"""List every function of every game unit, in link order.

    manifest.py [-o build/re/manifest.tsv]

One row per function: `unit<TAB>symbol<TAB>address<TAB>size<TAB>section<TAB>assembly`,
address and size in hex. The size runs to the next function, padding
included; the assembly is the file the split writes for the function. Every
exporter under scripts/re reads this list, so they agree on what a function
is called and where its output goes.
"""

import argparse
import os
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts" / "build"))

import disassemble  # noqa: E402
import layout  # noqa: E402


def rows():
    pieces = disassemble.Pieces()
    for unit in pieces.layout.units("cpp"):
        for section, run in pieces.unit(unit):
            if section not in disassemble.CODE_SECTIONS:
                continue
            for name, start, end in run:
                assembly = disassemble.NONMATCHINGS / unit / f"{name}.s"
                if not (ROOT / assembly).is_file():
                    assembly = disassemble.MATCHINGS / unit / f"{name}.s"
                yield unit, name, start, end - start, section, assembly


def main():
    os.chdir(ROOT)
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("-o", "--output", default="build/re/manifest.tsv")
    args = ap.parse_args()
    out = Path(args.output)
    out.parent.mkdir(parents=True, exist_ok=True)
    lines = [f"{u}\t{n}\t{a:08X}\t{s:X}\t{sec}\t{asm}" for u, n, a, s, sec, asm in rows()]
    out.write_text("\n".join(lines) + "\n")
    print(f"wrote {len(lines)} functions to {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
