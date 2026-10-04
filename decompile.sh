#!/usr/bin/env bash
# Decompile a function from the retail assembly with m2c.
#
#   decompile.sh <symbol>                    print the function as C
#   decompile.sh <symbol> --stack-structs    extra flags go to m2c
#
# Symbols are the mangled names diff.sh takes; look one up with
# `grep <name> ps2/config/pal/main.symbols.txt`. m2c reads the project's
# declarations from build/pal/ctx.c, which the build generates from
# ps2/include.
set -euo pipefail

cd "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
. scripts/host/container.sh

[[ $# -ge 1 && "$1" != -* ]] || { echo "Usage: $0 symbol [m2c flags...]" >&2; exit 1; }

CTX=build/pal/ctx.c

run() {
    symbol=$1
    shift
    if [ ! -f tools/m2c/m2c.py ]; then
        echo "$0: tools/m2c is empty. Run: git submodule update --init" >&2
        exit 1
    fi
    located=$(scripts/diff/locate.sh "$symbol") || exit 1
    if [ ! -f "$CTX" ]; then
        echo "$0: $CTX is missing; generating it." >&2
        scripts/build/cmake.sh ctx >&2
    fi
    exec python3 tools/m2c/m2c.py --target mipsee-mwcc-c++ \
        --context "$CTX" -f "$symbol" "${located#* }" "$@"
}

if in_container; then
    run "$@"
fi

require_rom
require_builder
ensure_image

exec "$BUILDER" run --rm \
    -v "$PWD:$CONTAINER_WORKDIR:Z" \
    -w "$CONTAINER_WORKDIR" \
    -e HOME=/tmp \
    "$IMAGE" "$CONTAINER_WORKDIR/decompile.sh" "$@"
