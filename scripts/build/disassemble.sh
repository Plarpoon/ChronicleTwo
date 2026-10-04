#!/bin/sh
# Split the retail executable into reference assembly under ps2/asm/<region>,
# as ps2/config/<region>/main.yaml describes it.
#
#   scripts/build/disassemble.sh
#   REGION=PAL scripts/build/disassemble.sh
#
# The disc is extracted first if it has not been, and the symbol list is
# checked against the executable's own symbol table.
set -eu

cd "$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)"

REGION=${REGION:-PAL}
export REGION
DIR=$(printf %s "$REGION" | tr '[:upper:]' '[:lower:]')

python3 scripts/build/extract.py --elf
python3 scripts/build/symbols.py --check

# splat resolves the yaml's paths from its own directory.
cd "ps2/config/$DIR"
exec python3 -m splat split main.yaml
