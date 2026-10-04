#!/usr/bin/env python3
"""Compile a game unit's drafts and say which already match retail.

    draft_check.py <unit>             compile with UNMATCHING and compare
    draft_check.py <unit> --promote   also build the unit as the game build
                                      does and check that object against retail
    draft_check.py --header ps2/include/<file>
                                      compile one header on its own

A draft is the C++ a source gives for a function inside `#ifdef UNMATCHING`,
with the function's INCLUDE_ASM marker in the `#else`. The first form
compiles the unit with UNMATCHING defined, so every draft is compiled, and
compares each function with retail's bytes, relocated fields masked:

    MATCH     the same bytes; a candidate for promotion
    DIFF      compiles, differs
    NO DRAFT  the source defines no such function

`--promote` is the test a promoted function has to pass: the unit is built
without UNMATCHING through tools/mwccgap, exactly as the build does, and the
whole object -- code, data, relocation targets and layout -- is checked
against retail (scripts/build/check_objects.py). A function whose bytes match
can still fail it, when promoting it brings data of its own into the object.

Runs in the dev container (scripts/re/draft.sh starts one). Objects go to
build/re/draft and build/re/check, never to the build's own directory.
"""

import argparse
import os
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools" / "mwccgap"))
sys.path.insert(0, str(ROOT / "scripts" / "build"))

from mwccgap.elf import Elf  # noqa: E402

import check_objects  # noqa: E402
import layout  # noqa: E402

MW_DIR = "tools/compilers/mw/3.0-011126"
LIB_INCLUDE_DIRS = "ps2/include/std;ps2/include/sce"
CC_FLAGS = ["-O3,p", "-strings", "readonly", "-c", "-Cpp_exceptions", "off", "-RTTI", "off", "-i", "ps2/include"]
DRAFT_DIR = Path("build/re/draft")
CHECK_DIR = Path("build/re/check")
STT_FUNC = 2


def project_name(name):
    """A compiler's symbol name as main.symbols.txt spells it."""
    name = re.sub(r"[,<>.$]", "_", name)
    return "at_" + name[1:] if name.startswith("@") else name


def manifest(unit):
    """{symbol: (address, size)} for the unit's functions."""
    out = {}
    for line in Path("build/re/manifest.tsv").read_text().splitlines():
        row_unit, symbol, address, size, _section, _assembly = line.split("\t")
        if row_unit == unit:
            out[symbol] = (int(address, 16), int(size, 16))
    return out


def compile_drafts(unit):
    obj = DRAFT_DIR / f"{unit}.o"
    obj.parent.mkdir(parents=True, exist_ok=True)
    obj.unlink(missing_ok=True)
    command = ["wibo", f"{MW_DIR}/mwccps2.exe", *CC_FLAGS, "-lang", "c++", "-DUNMATCHING",
               "-o", str(obj), f"ps2/src/{unit}.cpp"]
    result = subprocess.run(command, env={**os.environ, "MWCIncludes": LIB_INCLUDE_DIRS},
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    output = result.stdout.replace("\r", "").strip()
    if result.returncode != 0 or not obj.is_file():
        print(output)
        print(f"\n{unit}: does not compile with UNMATCHING defined")
        return None
    if output:
        print(output)
    return obj


def compare(unit, obj):
    retail = layout.Retail()
    functions = manifest(unit)
    elf = Elf(obj.read_bytes())
    relocations = {}
    for record in elf.relocations:
        relocations.setdefault(record.sh_info, []).extend(record.relocations)

    status = {}
    for symbol in elf.symtab.symbols:
        index = symbol.st_shndx
        if symbol.type != STT_FUNC or not (0 < index < len(elf.sections)):
            continue
        name = project_name(symbol.name)
        if name not in functions:
            # main.symbols.txt tells same-named locals apart with `__<n>`.
            twins = [f for f in functions if re.fullmatch(re.escape(name) + r"__\d+", f)]
            if len(twins) != 1:
                continue
            name = twins[0]
        address, extent = functions[name]
        data = bytearray(elf.sections[index].data)
        size = len(data)
        if size > extent:
            status[name] = f"DIFF      0x{size:X} bytes, retail 0x{extent:X}"
            continue
        theirs = bytearray(retail.bytes(address, address + extent))
        ours = data + bytearray(extent - size)
        mine = {}
        for relocation in relocations.get(index, []):
            mine[relocation.r_offset] = relocation.reloc_type
        wanted = {a - address: kind for a, kind in retail.relocations.items()
                  if address <= a < address + extent}
        for offset, kind in mine.items():
            mask = check_objects.MASKS.get(kind, 0xFFFFFFFF)
            for buffer in (ours, theirs):
                value = int.from_bytes(buffer[offset:offset + 4], "little") & ~mask
                buffer[offset:offset + 4] = value.to_bytes(4, "little")
        differing = sum(ours[i:i + 4] != theirs[i:i + 4] for i in range(0, extent, 4))
        if differing == 0 and mine == wanted:
            status[name] = "MATCH"
        elif differing == 0:
            status[name] = "DIFF      same instructions, different relocations"
        else:
            note = "" if size == extent else f", 0x{size:X} bytes against retail's 0x{extent:X}"
            status[name] = f"DIFF      {differing} of {extent // 4} words differ{note}"

    counts = {"MATCH": 0, "DIFF": 0, "NO DRAFT": 0}
    for name in functions:
        line = status.get(name, "NO DRAFT")
        counts[line.split("  ")[0].strip() if line != "NO DRAFT" else "NO DRAFT"] += 1
        print(f"  {line.split()[0] if line != 'NO DRAFT' else 'NO DRAFT':<9} {name}"
              + (f"  ({line.split(None, 1)[1]})" if line.startswith("DIFF") else ""))
    print(f"{unit}: {len(functions)} functions: {counts['MATCH']} match, "
          f"{counts['DIFF']} differ, {counts['NO DRAFT']} without a draft")
    return counts


def header_check(header):
    """Compile a header on its own, after common.h."""
    DRAFT_DIR.mkdir(parents=True, exist_ok=True)
    stem = re.sub(r"\W", "_", header)
    source = DRAFT_DIR / f"header_{stem}.cpp"
    obj = DRAFT_DIR / f"header_{stem}.o"
    relative = os.path.relpath(header, "ps2/include")
    source.write_text(f'#include "common.h"\n#include "{relative}"\n')
    command = ["wibo", f"{MW_DIR}/mwccps2.exe", *CC_FLAGS, "-lang", "c++", "-DUNMATCHING",
               "-o", str(obj), str(source)]
    result = subprocess.run(command, env={**os.environ, "MWCIncludes": LIB_INCLUDE_DIRS},
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    output = result.stdout.replace("\r", "").strip()
    if output:
        print(output)
    ok = result.returncode == 0 and obj.is_file()
    print(f"{header}: {'compiles' if ok else 'DOES NOT COMPILE'}")
    return ok


def promote_check(unit):
    obj = CHECK_DIR / f"{unit}.cpp.o"
    obj.parent.mkdir(parents=True, exist_ok=True)
    obj.unlink(missing_ok=True)
    dep = CHECK_DIR / f"{unit}.cpp.o.d"
    build = subprocess.run(
        ["sh", "scripts/build/mwccgap.sh", str(obj), str(dep), f"ps2/src/{unit}.cpp", *CC_FLAGS],
        stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    if build.returncode == 0:
        build = subprocess.run(["sh", "scripts/build/fixup_sections.sh", str(obj)],
                               stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    if build.returncode != 0 or not obj.is_file():
        print(build.stdout.replace("\r", "").strip())
        print(f"\n{unit}: PROMOTE FAILED - the game build of the unit does not compile")
        return False
    ctx = check_objects.Context(CHECK_DIR)
    # The split's notes on names it made up live with the build proper.
    undefined = layout.BUILD / "splat" / "main.undefined_syms.txt"
    if undefined.is_file():
        for line in undefined.read_text().splitlines():
            name, _, value = line.split("//")[0].strip().rstrip(";").partition("=")
            if value:
                ctx.addresses.setdefault(name.strip(), int(value, 0))
    errors, nbytes, nrelocs = check_objects.check_unit(ctx, unit, False)
    if errors:
        for line in errors[:20]:
            print(f"     {line}")
        print(f"{unit}: PROMOTE FAILED - the unit's object no longer matches retail")
        return False
    print(f"{unit}: PROMOTE OK - 0x{nbytes:X} bytes and {nrelocs} relocations match retail")
    return True


def main():
    os.chdir(ROOT)
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("unit", help="a game unit, or with --header a file under ps2/include")
    ap.add_argument("--header", action="store_true",
                    help="compile the named header on its own instead")
    ap.add_argument("--promote", action="store_true",
                    help="build the unit as the game build does and check it against retail")
    args = ap.parse_args()
    if args.header:
        return 0 if header_check(args.unit) else 1
    if not Path(f"ps2/src/{args.unit}.cpp").is_file():
        sys.exit(f"no source ps2/src/{args.unit}.cpp")
    obj = compile_drafts(args.unit)
    if obj is None:
        return 1
    compare(args.unit, obj)
    if args.promote and not promote_check(args.unit):
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
