#!/usr/bin/env bash
# Diff a function against the retail original.
#
#   diff.sh <symbol>                       show the function's diff
#   diff.sh <symbol> -o - --format json    extra flags go to objdiff-cli
#   diff.sh --report                       whole-project progress report
#
# Symbols are the mangled names the compiler uses, e.g. search_txt__Fc; look
# one up with `grep <name> ps2/config/pal/main.symbols.txt`. The work happens
# in the container, where objdiff and the EE binutils live.
#
# objdiff compares object files, not disassembly text: the target is the
# unit's retail reference, the base is its source compiled alone, and
# objdiff.json pairs them.
set -euo pipefail

cd "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
. scripts/host/container.sh

usage() {
    echo "Usage: $0 [--report] symbol [objdiff flags...]" >&2
    exit 1
}

require_rom

# bash 3.2, which is what macOS ships, treats an empty array as unset under
# `set -u`, hence the guarded expansions below.
TTY=()

case "${1:-}" in
    --report)
        shift
        # objdiff.json and both objects of every unit have to be current
        # first; scripts/build/cmake.sh owns the configuring.
        ARGS=(sh -c '
            scripts/build/cmake.sh objdiff
            exec python3 scripts/build/progress_report.py
        ' report)
        ;;
    ''|-*)
        usage
        ;;
    *)
        symbol=$1
        shift
        ARGS=(sh -c '
            sym=$1; shift
            located=$(scripts/diff/locate.sh "$sym") || exit 1
            scripts/build/cmake.sh objdiff >/dev/null
            exec objdiff-cli diff -p . -u "${located%% *}" "$sym" "$@"
        ' diff "$symbol" "$@")

        # objdiff's interactive view needs a terminal, but `diff.sh ... | cat`
        # must not be given one.
        if [[ -t 0 && -t 1 ]]; then TTY=(-it); fi
        ;;
esac

if in_container; then
    exec "${ARGS[@]}"
fi

require_builder
ensure_image

exec "$BUILDER" run --rm ${TTY[@]+"${TTY[@]}"} \
    -v "$PWD:$CONTAINER_WORKDIR:Z" \
    -w "$CONTAINER_WORKDIR" \
    -e HOME=/tmp \
    "$IMAGE" "${ARGS[@]}"
