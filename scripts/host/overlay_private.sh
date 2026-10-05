#!/bin/sh
# Install the PAL retail executable from a private repository checkout.
# Usage: scripts/host/overlay_private.sh [checkout] (default: .private)
set -eu

cd "$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)"
source_dir=${1:-.private}
relative_path=rom/pal/extracted/iso/SCES_511.90
source_file=$source_dir/$relative_path
destination=$relative_path

if [ ! -f "$source_file" ]; then
    echo "overlay_private.sh: missing $source_file" >&2
    exit 1
fi

expected=$(cut -d ' ' -f 1 rom/pal/extracted.sha256)
actual=$(sha256sum "$source_file" | cut -d ' ' -f 1)
if [ "$actual" != "$expected" ]; then
    echo "overlay_private.sh: $source_file does not match the PAL retail checksum." >&2
    echo "Fetch its Git LFS content before running this script." >&2
    exit 1
fi

mkdir -p "$(dirname "$destination")"
temporary=$(mktemp "$destination.tmp.XXXXXX")
trap 'rm -f "$temporary"' EXIT HUP INT TERM
cp "$source_file" "$temporary"
mv "$temporary" "$destination"
trap - EXIT HUP INT TERM
echo "overlay_private.sh: installed $destination"
