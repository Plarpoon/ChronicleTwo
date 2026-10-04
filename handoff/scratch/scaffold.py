#!/usr/bin/env python3
"""One-off: write ps2/src/<unit>.cpp for every game unit (run from the repo root)."""
import sys
from pathlib import Path
sys.path.insert(0, "scripts/build")
import layout
import disassemble

TITLES = {".text": "Code", ".data": "Initialised data", ".rodata": "Constants",
          ".init": "Static initialiser", ".ctor": "Static initialiser table",
          ".vtables": "Virtual tables", ".sdata": "Small initialised data",
          ".sbss": "Small uninitialised data", ".bss": "Uninitialised data"}

def main():
    pieces = disassemble.Pieces()
    lay = pieces.layout
    only = sys.argv[1:]
    for unit in lay.units("cpp"):
        if only and unit not in only:
            continue
        asm_dir = f"ps2/asm/pal/nonmatchings/{unit}"
        runs = dict(pieces.unit(unit))
        order = [s for s in (".text", ".init", ".data", ".rodata", ".ctor", ".vtables",
                             ".sdata", ".sbss", ".bss") if s in runs]
        out = ['#include "common.h"']
        for section in order:
            out.append("")
            out.append(f"// {TITLES[section]} ({section})")
            for name, start, end in runs[section]:
                if section in disassemble.CODE_SECTIONS:
                    out.append(f'INCLUDE_ASM("{asm_dir}", {name});')
                elif section in disassemble.DATA_SECTIONS:
                    out.append(f'INCLUDE_RODATA("{asm_dir}", {name});')
                else:
                    out.append(f"unsigned char {name}[0x{end - start:X}];")
        Path(lay.source(unit)).write_text("\n".join(out) + "\n")

main()
