#!/usr/bin/env bash
# Write Ghidra's decompilation of every manifest function to
# build/re/ghidra/<unit>/<symbol>.c; failures go to build/re/ghidra/failures.tsv.
#
#   scripts/re/ghidra/export.sh [workers] [timeout seconds]
#
# Runs on the host against the populated project (scripts/re/ghidra/populate.sh);
# opens it read-only. GHIDRA_PROJECT_DIR overrides the project location.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/../../.." && pwd)"
cd "$ROOT"
GHIDRA="${GHIDRA:-$ROOT/tools/ghidra}"
PROJECT_DIR="${GHIDRA_PROJECT_DIR:-$ROOT/ps2/re/ghidra}"
OUT="${GHIDRA_EXPORT_DIR:-$ROOT/build/re/ghidra}"
WORKERS="${1:-8}"
TIMEOUT="${2:-120}"
MANIFEST="$ROOT/build/re/manifest.tsv"

[ -f "$MANIFEST" ] || python3 scripts/re/manifest.py
# Every run starts from an empty tree so no stale file outlives its function.
rm -rf "$OUT"
mkdir -p "$OUT" "$ROOT/build/re/ghidra-work/log"
"$GHIDRA/support/analyzeHeadless" "$PROJECT_DIR" "Dark Cloud 2" \
    -process SCES_511.90 -noanalysis -readOnly \
    -scriptPath "$ROOT/scripts/re/ghidra" \
    -postScript ExportDecomp.java "$MANIFEST" "$OUT" "$WORKERS" "$TIMEOUT" \
    -log "$ROOT/build/re/ghidra-work/log/export.log" \
    -scriptlog "$ROOT/build/re/ghidra-work/log/export.script.log"
