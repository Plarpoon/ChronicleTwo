#!/bin/sh
# Write ps2/re/functions/: one Markdown file per game function, holding its
# relevant symbols, Ghidra's and m2c's decompilations and the retail
# disassembly.
#
#   scripts/re/export.sh             everything
#   scripts/re/export.sh --no-ghidra reuse the Ghidra output already exported
#
# Runs on the host, after a build has split the executable. Ghidra must not
# have ps2/re/ghidra open: the export works on that project headlessly.
set -eu

cd "$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)"

ghidra=1
if [ "${1:-}" = --no-ghidra ]; then ghidra=0; fi

python3 scripts/re/manifest.py
python3 scripts/re/symbols.py
python3 scripts/re/m2c_all.py
if [ "$ghidra" = 1 ]; then
    scripts/re/ghidra/populate.sh
    scripts/re/ghidra/export.sh
fi
python3 scripts/re/combine.py
