#!/usr/bin/env bash
# Open a shell in the dev container with the tree mounted, or run a command
# there.
#
#   ./dev.sh                         an interactive shell
#   ./dev.sh scripts/build/cmake.sh elf
set -euo pipefail

cd "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
. scripts/host/container.sh

[ $# -gt 0 ] || set -- bash

if in_container; then
    exec "$@"
fi

require_builder
ensure_image

# bash 3.2, which is what macOS ships, treats an empty array as unset under
# `set -u`, hence the guarded expansion below.
TTY=(-i)
if [ -t 0 ] && [ -t 1 ]; then TTY=(-it); fi

exec "$BUILDER" run --rm ${TTY[@]+"${TTY[@]}"} \
    -v "$PWD:$CONTAINER_WORKDIR:Z" \
    -w "$CONTAINER_WORKDIR" \
    -e HOME=/tmp \
    "$IMAGE" "$@"
