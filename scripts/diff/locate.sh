#!/bin/sh
# Print `<unit> <reference file>` for a function, by its mangled name.
#
#   scripts/diff/locate.sh <symbol>
#
# The split writes each function of a game unit to
# ps2/asm/pal/{nonmatchings,matchings}/<unit>/<symbol>.s, so the path names
# the unit.
set -eu

cd "$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)"

symbol=$1
for kind in nonmatchings matchings; do
    root=ps2/asm/pal/$kind
    [ -d "$root" ] || continue
    file=$(find "$root" -type f -name "$symbol.s" | head -1)
    if [ -n "$file" ]; then
        unit=${file#"$root"/}
        echo "${unit%/*} $file"
        exit 0
    fi
done

echo "$symbol is in no game unit -- check the spelling with" >&2
echo "  grep $symbol ps2/config/pal/main.symbols.txt" >&2
exit 1
