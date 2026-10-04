#!/usr/bin/env python3
"""Decompile every game function with m2c, one C file per function.

    m2c_all.py [--jobs N] [--timeout S] [unit ...]

Reads build/re/manifest.tsv and writes build/re/m2c/<unit>/<symbol>.c with
m2c's output as printed. A function m2c could not decompile at all (non-zero
exit, crash, timeout, or nothing but a failure comment) gets no .c; it is
listed in build/re/m2c/failures.tsv as `unit<TAB>symbol<TAB>reason`. Output
that is a decompilation carrying inline warnings or errors is kept as the .c.
Naming units restricts the run to them; their stale .c files are replaced
and the others are left alone, while failures.tsv always describes this run.

m2c reads each function's own assembly together with every data section of
its unit, so jump tables, float and string constants and initialised globals
resolve. MWCC names its jump tables like any other local constant (`at_288`),
and m2c only recognises a table by a `jtbl_`-style name, so each table in the
unit's data is renamed `jtbl_<name>` in both the data and the code. A `jr`
that m2c still cannot resolve is a tail call through a function pointer and
is respelled as a call followed by a return.

Run on the host it reruns itself in the dev container.
"""

import argparse
import os
import re
import shutil
import subprocess
import sys
import tempfile
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MANIFEST = ROOT / "build/re/manifest.tsv"
OUT = ROOT / "build/re/m2c"
CONTEXT = ROOT / "build/pal/ctx.c"
M2C = ROOT / "tools/m2c/m2c.py"
UNIT_ASM = ROOT / "ps2/asm/pal"
IMAGE = "chronicletwo_dev"
WORKDIR = "/chronicletwo"
TARGET = "mipsee-mwcc-c++"

CODE_SECTIONS = {".text", ".init"}
SECTION = re.compile(r"^\s*\.section\s+(\.\w+)")
GLABEL = re.compile(r"^\s*glabel\s+(\S+)")
DATA_WORD = re.compile(r"^\s*(?:/\*.*?\*/)?\s*\.word\s+(\S+)")
NO_JTBL = re.compile(r"Unable to determine jump table for jr instruction at \S+ line (\d+)")
INSTRUCTION = re.compile(r"^\s*/\*.*?\*/\s+[a-z]")
FAILURE = re.compile(r"\A\s*/\*\s*\nDecompilation failure in function [^\n]*\n(.*?)\*/\s*", re.S)


def in_container():
    return (os.path.exists("/run/.containerenv") or os.path.exists("/.dockerenv")
            or bool(os.environ.get("container")))


def rerun_in_container():
    builder = os.environ.get("BUILDER") or ("podman" if shutil.which("podman") else "docker")
    script = Path(__file__).resolve().relative_to(ROOT)
    cmd = [builder, "run", "--rm", "-v", f"{ROOT}:{WORKDIR}:Z", "-w", WORKDIR,
           "-e", "HOME=/tmp", IMAGE, "python3", f"{WORKDIR}/{script}", *sys.argv[1:]]
    return subprocess.call(cmd)


def unit_data(unit):
    """The unit's data sections, and the names of the jump tables among them."""
    data, tables = [], set()
    section = None
    label, words = None, []

    def close():
        # A table may be padded out with zero words after its last target.
        targets = list(words)
        while targets and targets[-1] == "0x00000000":
            targets.pop()
        if label and targets and all(w.startswith(".L") for w in targets):
            tables.add(label)

    for line in (UNIT_ASM / f"{unit}.s").read_text().splitlines():
        m = SECTION.match(line)
        if m:
            close()
            label, words = None, []
            section = m.group(1)
        if section is None or section in CODE_SECTIONS:
            continue
        data.append(line)
        m = GLABEL.match(line)
        if m:
            close()
            label, words = m.group(1), []
            continue
        if label is None:
            continue
        m = DATA_WORD.match(line)
        if m:
            words.append(m.group(1))
        elif re.sub(r"/\*.*?\*/", "", line).strip().split(" ")[0] not in ("", ".align", ".section"):
            # Any other data makes the label something other than a jump table.
            words.append("")
    close()
    return "\n".join(data) + "\n", tables


def renamer(tables):
    if not tables:
        return lambda text: text
    names = "|".join(re.escape(t) for t in sorted(tables, key=len, reverse=True))
    pattern = re.compile(rf"(?<![\w$.@])({names})(?![\w$@])")
    return lambda text: pattern.sub(r"jtbl_\1", text)


def first_line(text):
    for line in text.splitlines():
        if line.strip():
            return line.strip()
    return ""


def as_tail_call(lines, number):
    """Spell the register jump on line `number` (1-based) as a call and return.

    A `jr` through anything but $ra that loads no jump table is a tail call
    through a function pointer, usually a virtual one. m2c only rewrites tail
    calls to a named function (`j fn`), so this does the same for `jr $reg`:
    `jalr $reg`, the original delay slot, then `jr $ra`.
    """
    i = number - 1
    lines[i] = re.sub(r"\bjr(\s+)", r"jalr\1", lines[i], count=1)
    j = next((k for k in range(i + 1, len(lines)) if INSTRUCTION.match(lines[k])), i)
    lines[j + 1:j + 1] = ["    jr $31", "    nop"]


def decompile(job):
    unit, symbol, asm, data_path, tables, timeout, tmp = job
    lines = renamer(tables)((ROOT / asm).read_text()).splitlines()
    fn_path = Path(tmp) / f"{unit}__{symbol}.s"
    cmd = [sys.executable, str(M2C), "--target", TARGET, "--context", str(CONTEXT),
           "-f", symbol, str(fn_path), data_path]
    try:
        # Each pass turns the one tail call m2c stopped at into a call.
        for _ in range(64):
            fn_path.write_text("\n".join(lines) + "\n")
            try:
                proc = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout)
            except subprocess.TimeoutExpired:
                return unit, symbol, None, f"timeout after {timeout} s"
            m = NO_JTBL.search(proc.stdout)
            if not m:
                break
            as_tail_call(lines, int(m.group(1)))
    finally:
        fn_path.unlink(missing_ok=True)
    out = proc.stdout
    m = FAILURE.match(out)
    if m and "{" not in out[m.end():]:
        return unit, symbol, None, first_line(m.group(1)) or "decompilation failure"
    if proc.returncode != 0 and not m:
        # A Python traceback ends with the exception; that line is the reason.
        err = [l for l in proc.stderr.splitlines() if l.strip()]
        reason = err[-1].strip() if err and err[0].startswith("Traceback") else first_line(proc.stderr)
        return unit, symbol, None, f"exit {proc.returncode}: {reason or first_line(out)}"
    if not out.strip():
        return unit, symbol, None, "no output"
    return unit, symbol, out, None


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--jobs", "-j", type=int, default=os.cpu_count())
    ap.add_argument("--timeout", type=int, default=120, help="seconds per function")
    ap.add_argument("units", nargs="*", help="restrict to these units")
    args = ap.parse_args()

    if not in_container():
        return rerun_in_container()

    rows = [line.split("\t") for line in MANIFEST.read_text().splitlines() if line.strip()]
    if args.units:
        unknown = set(args.units) - {r[0] for r in rows}
        if unknown:
            sys.exit(f"unknown units: {' '.join(sorted(unknown))}")
        rows = [r for r in rows if r[0] in args.units]

    OUT.mkdir(parents=True, exist_ok=True)
    tmp = tempfile.mkdtemp(prefix="m2c_all.")
    jobs = []
    try:
        units = {}
        for unit, symbol, _addr, _size, _section, asm in rows:
            if unit not in units:
                data, tables = unit_data(unit)
                data_path = Path(tmp) / f"{unit}.data.s"
                data_path.write_text(renamer(tables)(data))
                units[unit] = (str(data_path), frozenset(tables))
                shutil.rmtree(OUT / unit, ignore_errors=True)
                (OUT / unit).mkdir(parents=True)
            data_path, tables = units[unit]
            jobs.append((unit, symbol, asm, data_path, tables, args.timeout, tmp))

        failures = []
        done = 0
        with ProcessPoolExecutor(max_workers=args.jobs) as pool:
            for unit, symbol, text, reason in pool.map(decompile, jobs, chunksize=4):
                done += 1
                if text is None:
                    failures.append((unit, symbol, reason.replace("\t", " ")))
                else:
                    (OUT / unit / f"{symbol}.c").write_text(text)
                if done % 500 == 0:
                    print(f"{done}/{len(jobs)}", flush=True)
    finally:
        shutil.rmtree(tmp, ignore_errors=True)

    (OUT / "failures.tsv").write_text("".join(f"{u}\t{s}\t{r}\n" for u, s, r in failures))
    print(f"{len(jobs) - len(failures)} decompiled, {len(failures)} failed "
          f"(see {(OUT / 'failures.tsv').relative_to(ROOT)})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
