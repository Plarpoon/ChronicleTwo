#!/usr/bin/env bash
# Populate the Ghidra project's SCES_511.90 with the project's symbols and the
# types the mangled names and the SDK headers state.
#
#   scripts/re/ghidra/populate.sh [reanalyze]
#
# Runs on the host (Ghidra needs Java). Close the project in Ghidra first.
# GHIDRA_PROJECT_DIR overrides the project location (ps2/re/ghidra).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/../../.." && pwd)"
cd "$ROOT"
GHIDRA="${GHIDRA:-$ROOT/tools/ghidra}"
PROJECT_DIR="${GHIDRA_PROJECT_DIR:-$ROOT/ps2/re/ghidra}"
PROJECT_NAME="Dark Cloud 2"
PROGRAM="SCES_511.90"
WORK="$ROOT/build/re/ghidra-work"
BACKUP="$ROOT/build/re/ghidra-project-backup"

if [ "$PROJECT_DIR" = "$ROOT/ps2/re/ghidra" ] && [ ! -e "$BACKUP" ]; then
    mkdir -p "$(dirname "$BACKUP")"
    cp -a "$PROJECT_DIR" "$BACKUP"
fi

python3 scripts/re/ghidra/prepare.py -o "$WORK"
mkdir -p "$WORK/log"
"$GHIDRA/support/analyzeHeadless" "$PROJECT_DIR" "$PROJECT_NAME" \
    -process "$PROGRAM" -noanalysis \
    -scriptPath "$ROOT/scripts/re/ghidra" \
    -postScript Populate.java "$WORK" "${1:-}" \
    -log "$WORK/log/populate.log" -scriptlog "$WORK/log/populate.script.log"
