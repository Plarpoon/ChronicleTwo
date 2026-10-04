#!/usr/bin/env bash
# Build the game in the container, master a disc image with the rebuilt
# executable, then boot it in PCSX2. One command, from a clean checkout to the
# title screen.
#
#   ./run.sh
#   JOBS=8 ./run.sh
#
# The first run builds the image, extracts and splits the disc, and copies the
# 4.4 GB disc image once; later runs are incremental. PCSX2 runs on the host
# (it needs a display); set PCSX2=/path/to/pcsx2-qt if it is not found.
set -euo pipefail

cd "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
. scripts/host/container.sh

# PCSX2 is the reason this one is host-only: it needs a display, so there is
# nothing sensible for it to do from inside the container.
require_builder
require_iso
ensure_image
report_parallelism

BUILD_DIR=${BUILD_DIR:-build/pal}
ISO="$BUILD_DIR/Dark Chronicle (PAL Build).iso"

# bash 3.2, which is what macOS ships, treats an empty array as unset under
# `set -u`, hence the guarded expansions below.
TTY=()
if [ -t 1 ]; then TTY=(-t); fi

ENV_ARGS=(-e "BUILD_DIR=$BUILD_DIR")
if [ -n "${JOBS:-}" ]; then ENV_ARGS+=(-e "JOBS=$JOBS"); fi

# `iso` links the executable and masters the disc without the verification
# `build` adds, so code that does not match retail still boots, which is the
# point of running it. Verification follows as a report only; the boot goes
# ahead either way. If the build fails the run stops, rather than booting
# whatever stale image is lying around.
"$BUILDER" run --rm ${TTY[@]+"${TTY[@]}"} "${ENV_ARGS[@]}" \
    -v "$PWD:$CONTAINER_WORKDIR:Z" \
    -w "$CONTAINER_WORKDIR" \
    -e HOME=/tmp \
    "$IMAGE" sh -c '
        set -e
        scripts/build/cmake.sh iso
        BUILD_DIR="$BUILD_DIR" python3 scripts/build/verify.py -c \
            || echo "The executable does not match retail; booting it anyway."
    '

exec scripts/host/pcsx2.sh "$ISO"
