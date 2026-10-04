#!/usr/bin/env python3
"""Join the per-function reverse-engineering exports into one Markdown file per function.

Inputs (under build/re): manifest.tsv, symbols/<unit>.json, m2c/<unit>/<symbol>.c,
ghidra/<unit>/<symbol>.c plus each tool's failures.tsv, and the retail assembly
named by the manifest. Output: <out>/<unit>/<symbol>.md, <out>/<unit>/index.md
and <out>/index.md. Any input may be absent; the output says so instead.

Usage: scripts/re/combine.py [-o DIR] [UNIT ...]
"""
import argparse
import json
import os
import sys
from urllib.parse import quote

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
RE = os.path.join(ROOT, "build", "re")
NO_OUTPUT = "Not available: no output was produced."


def read_text(path):
    try:
        with open(path, encoding="utf-8", errors="replace") as f:
            return f.read()
    except OSError:
        return None


def load_failures(path):
    out = {}
    text = read_text(path)
    for line in (text or "").splitlines():
        parts = line.split("\t", 2)
        if len(parts) == 3:
            out[(parts[0], parts[1])] = parts[2].strip()
    return out


def load_manifest():
    rows = []
    for line in (read_text(os.path.join(RE, "manifest.tsv")) or "").splitlines():
        p = line.split("\t")
        if len(p) >= 6:
            rows.append(dict(unit=p[0], symbol=p[1], address=p[2], size=p[3],
                             section=p[4], asm=p[5]))
    return rows


def load_symbols(unit):
    text = read_text(os.path.join(RE, "symbols", unit + ".json"))
    if text is None:
        return None
    try:
        return json.loads(text).get("functions", {})
    except ValueError:
        return None


def cell(value):
    if value is None:
        return ""
    if isinstance(value, list):
        value = ", ".join(str(v) for v in value)
    return str(value).replace("|", "\\|").replace("\n", " ")


def code(value):
    value = str(value)
    if "`" in value:
        return "`` " + value.replace("|", "\\|") + " ``"
    return "`" + value.replace("|", "\\|") + "`"


def fence(content, lang):
    longest = run = 0
    for ch in content:
        run = run + 1 if ch == "`" else 0
        longest = max(longest, run)
    f = "`" * max(3, longest + 1)
    body = content if content.endswith("\n") else content + "\n"
    return f"{f}{lang}\n{body}{f}\n"


def table(headers, rows):
    out = ["| " + " | ".join(headers) + " |", "|" + "|".join("---" for _ in headers) + "|"]
    out += ["| " + " | ".join(r) + " |" for r in rows]
    return "\n".join(out) + "\n"


def strip_boilerplate(text):
    lines = text.splitlines()
    i = 0
    while i < len(lines):
        s = lines[i].strip()
        if s == "" or s.startswith(".include") or s.startswith(".set "):
            i += 1
        else:
            break
    return "\n".join(lines[i:]) + "\n"


def display_name(name, demangled):
    return demangled or name


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("units", nargs="*", help="restrict to these units")
    ap.add_argument("-o", "--out", default=os.path.join("ps2", "re", "functions"))
    args = ap.parse_args()
    out_dir = os.path.abspath(os.path.join(ROOT, args.out))

    manifest = load_manifest()
    if not manifest:
        sys.exit("combine.py: build/re/manifest.tsv is missing or empty")
    known = {(r["unit"], r["symbol"]): r for r in manifest}
    by_unit = {}
    for r in manifest:
        by_unit.setdefault(r["unit"], []).append(r)
    selected = [u for u in by_unit if not args.units or u in args.units]
    for u in args.units:
        if u not in by_unit:
            sys.exit(f"combine.py: unknown unit {u}")

    m2c_fail = load_failures(os.path.join(RE, "m2c", "failures.tsv"))
    ghidra_fail = load_failures(os.path.join(RE, "ghidra", "failures.tsv"))

    written = 0
    missing = dict(ghidra=0, m2c=0, symbols=0, disassembly=0)
    expected = set()

    def write(path, content):
        nonlocal written
        expected.add(os.path.abspath(path))
        if read_text(path) == content:
            return
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, "w", encoding="utf-8", newline="\n") as f:
            f.write(content)
        written += 1

    def link_to(src_path, unit, name):
        r = known.get((unit, name))
        if not r:
            return None
        dst = os.path.join(out_dir, unit, name + ".md")
        return quote(os.path.relpath(dst, os.path.dirname(src_path)).replace(os.sep, "/"))

    def ref_table(src_path, entries):
        has_kind = any(e.get("kind", "call") != "call" for e in entries)
        headers = ["Name", "Address", "Unit"] + (["Kind"] if has_kind else [])
        rows = []
        for e in entries:
            name = e.get("name", "")
            text = code(name)
            href = link_to(src_path, e.get("unit"), name)
            if href:
                text = f"[{text}]({href})"
            if e.get("demangled"):
                text += " " + cell(e["demangled"])
            row = [text, cell(e.get("address")), cell(e.get("unit"))]
            if has_kind:
                k = e.get("kind", "call")
                row.append("" if k == "call" else cell(k))
            rows.append(row)
        return table(headers, rows)

    def data_table(entries):
        headers = ["Name", "Address", "Section", "Size", "Unit", "Access", "Offsets", "Value"]
        rows = []
        for e in entries:
            v = e.get("value")
            rows.append([code(e.get("name", "")), cell(e.get("address")), cell(e.get("section")),
                         cell(e.get("size")), cell(e.get("unit")), cell(e.get("access")),
                         cell(e.get("offsets")), code(v) if v not in (None, "") else ""])
        return table(headers, rows)

    for unit in selected:
        funcs = load_symbols(unit)
        for r in by_unit[unit]:
            sym = r["symbol"]
            path = os.path.join(out_dir, unit, sym + ".md")
            info = funcs.get(sym) if funcs is not None else None
            demangled = (info or {}).get("demangled")
            md = [f"# {display_name(sym, demangled)}\n\n",
                  f"- Symbol: {code(sym)}\n- Address: `0x{r['address']}`\n"
                  f"- Size: `0x{r['size']}`\n- Section: {r['section']}\n- Unit: {unit}\n\n",
                  "## Symbols\n\n"]
            if info is None:
                missing["symbols"] += 1
                md.append("Not available: no symbol information was produced.\n\n")
            else:
                for title, key in (("Calls", "calls"), ("Called by", "callers"), ("Data", "data")):
                    md.append(f"### {title}\n\n")
                    items = info.get(key) or []
                    if not items:
                        md.append("None.\n\n")
                    else:
                        md.append((data_table(items) if key == "data"
                                   else ref_table(path, items)) + "\n")

            for title, tool, fails, key in (("Ghidra", "ghidra", ghidra_fail, "ghidra"),
                                            ("m2c", "m2c", m2c_fail, "m2c")):
                md.append(f"## {title}\n\n")
                text = read_text(os.path.join(RE, tool, unit, sym + ".c"))
                if text is None:
                    missing[key] += 1
                    reason = fails.get((unit, sym))
                    md.append((f"Not available: {reason}" if reason else NO_OUTPUT) + "\n\n")
                else:
                    md.append(fence(text, "c") + "\n")

            md.append("## Disassembly\n\n")
            asm = read_text(os.path.join(ROOT, r["asm"]))
            if asm is None:
                missing["disassembly"] += 1
                md.append(NO_OUTPUT + "\n")
            else:
                md.append(fence(strip_boilerplate(asm), "mips"))
            write(path, "".join(md))

        # unit index
        ipath = os.path.join(out_dir, unit, "index.md")
        rows = []
        for r in by_unit[unit]:
            info = (funcs or {}).get(r["symbol"]) or {}
            dm = info.get("demangled")
            href = quote(r["symbol"] + ".md")
            rows.append([f"`0x{r['address']}`", f"`0x{r['size']}`",
                         f"[{cell(display_name(r['symbol'], dm))}]({href})", code(r["symbol"])])
        write(ipath, f"# {unit}\n\n{len(rows)} functions.\n\n"
              + table(["Address", "Size", "Function", "Symbol"], rows))

    # top index
    rows = []
    for unit in by_unit:
        rs = by_unit[unit]
        lo = min(int(r["address"], 16) for r in rs)
        hi = max(int(r["address"], 16) + int(r["size"], 16) for r in rs)
        rows.append([f"[{cell(unit)}]({quote(unit)}/index.md)", str(len(rs)),
                     f"`0x{lo:08X}` - `0x{hi:08X}`"])
    write(os.path.join(out_dir, "index.md"),
          f"# Functions\n\n{len(manifest)} functions in {len(by_unit)} units, in link order.\n\n"
          + table(["Unit", "Functions", "Address range"], rows))

    # stale cleanup (only when the full set was generated)
    removed = 0
    if not args.units and os.path.isdir(out_dir):
        for dp, _, fns in os.walk(out_dir):
            for fn in fns:
                p = os.path.abspath(os.path.join(dp, fn))
                if fn.endswith(".md") and p not in expected:
                    os.remove(p)
                    removed += 1
        for dp, dns, fns in os.walk(out_dir, topdown=False):
            if dp != out_dir and not os.listdir(dp):
                os.rmdir(dp)

    print(f"combine: wrote {written} files, removed {removed} stale; functions lacking: "
          f"ghidra {missing['ghidra']}, m2c {missing['m2c']}, "
          f"symbols {missing['symbols']}, disassembly {missing['disassembly']}")


if __name__ == "__main__":
    main()
