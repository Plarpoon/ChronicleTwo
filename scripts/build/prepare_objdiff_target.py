#!/usr/bin/env python3
"""Keep exported switch labels from splitting objdiff's function boundaries.

The linked assembly exports jlabels so separately assembled jump tables can
refer to them. An objdiff target contains the whole unit, so those labels can
be local without losing references. Only symbol metadata is changed.
"""

import argparse
from pathlib import Path
import re
import subprocess


def switch_labels(source):
    """Select splat's explicit jump labels, never ordinary function labels."""
    return sorted(set(re.findall(
        r"^[ \t]*jlabel[ \t]+(\.L[0-9A-Fa-f]{8})[ \t]*$", source, re.MULTILINE)))


def prepare_target(object_path, assembly_path, objcopy):
    labels = switch_labels(assembly_path.read_text())
    if labels:
        subprocess.run([
            objcopy,
            *[f"--localize-symbol={name}" for name in labels],
            str(object_path),
        ], check=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("object", type=Path)
    parser.add_argument("assembly", type=Path)
    parser.add_argument("--objcopy", default="mips-ps2-decompals-objcopy")
    args = parser.parse_args()
    prepare_target(args.object, args.assembly, args.objcopy)


if __name__ == "__main__":
    main()
