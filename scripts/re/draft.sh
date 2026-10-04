#!/usr/bin/env bash
# Compile a game unit's drafts and compare them with retail, in the dev
# container. See scripts/re/draft_check.py for what is printed.
#
#   scripts/re/draft.sh <unit>             compile the drafts and compare
#   scripts/re/draft.sh <unit> --promote   also check the unit's game build
#   scripts/re/draft.sh <unit> --promote-one <symbol>   try one draft and keep it only if exact
#   scripts/re/draft.sh <unit> --promote-all   try every guarded function once
# Attempts are reserved in scripts/re/promotion_attempts.tsv before compilation.
#   scripts/re/draft.sh <unit> --diff <symbol>   one function beside retail's
#   scripts/re/draft.sh --header ps2/include/<file>   compile one header alone
set -euo pipefail

cd "$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
. scripts/host/container.sh

if in_container; then
    exec python3 scripts/re/draft_check.py "$@"
fi

require_builder
ensure_image

exec "$BUILDER" run --rm \
    -v "$PWD:$CONTAINER_WORKDIR:Z" \
    -w "$CONTAINER_WORKDIR" \
    -e HOME=/tmp \
    "$IMAGE" python3 scripts/re/draft_check.py "$@"
