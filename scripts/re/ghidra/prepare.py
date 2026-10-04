#!/usr/bin/env python3
"""Write the inputs the Ghidra scripts under scripts/re/ghidra read.

    prepare.py [-o build/re/ghidra-work]

Writes, into the output directory:

  symbols.tsv    one row per symbol of ps2/config/<region>/main.symbols.txt:
                 `address<TAB>project name<TAB>retail name<TAB>kind<TAB>size<TAB>unit`
                 where kind is func, object or label, the size is the ELF
                 symbol's own and unit is the owning unit for manifest functions.
  signatures.jsonl  one JSON object per function whose retail name is a
                 CodeWarrior-mangled C++ name, with what the mangling encodes:
                 the qualifying class, constness, parameter types and the
                 demangled prototype.
  vtables.tsv    `address<TAB>project name<TAB>class path<TAB>size` for every
                 `__vt__<class>` symbol.
  sdk.h          the first game's SDK and C library headers, reduced to plain C
                 that Ghidra's C parser accepts.

CodeWarrior's mangling: `<name>__<qualifier><C>F<parameters>` for a member
(`C` marking a const member) and `<name>__F<parameters>` for a free function.
Qualifiers and class types are `<length><name>` or `Q<count><length><name>...`;
template arguments are spelled inside the class name's `<...>` in the same
code. Return types are not encoded.
"""

import argparse
import json
import os
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "scripts" / "build"))

import symbols  # noqa: E402

FIRST_GAME_INCLUDE = Path("/home/adubbz/development/chronicle/ps2/include")
SDK_HEADERS = ["types.h", "sce/csl.h", "sce/eekernel.h", "sce/libcdvd.h", "sce/libdma.h",
               "sce/libgraph.h", "sce/libmc.h", "sce/libpad.h", "sce/libpkt.h", "sce/libsdr.h",
               "sce/libvu0.h", "sce/modmsin.h", "sce/sifdev.h", "sce/sifdma.h", "sce/sifrpc.h",
               "std/cassert", "std/cmath", "std/cstdio", "std/cstdlib", "std/cstring"]

PRIMITIVES = {"v": "void", "b": "bool", "c": "char", "s": "short", "i": "int", "l": "long",
              "x": "longlong", "f": "float", "d": "double", "r": "longdouble", "w": "wchar",
              "e": "..."}
UNSIGNED = {"c": "uchar", "s": "ushort", "i": "uint", "l": "ulong", "x": "ulonglong"}
SIGNED = {"c": "schar", "s": "short", "i": "int", "l": "long", "x": "longlong"}
C_SPELLING = {"void": "void", "bool": "bool", "char": "char", "short": "short", "int": "int",
              "long": "long", "longlong": "long long", "float": "float", "double": "double",
              "longdouble": "long double", "wchar": "wchar_t", "...": "...",
              "uchar": "unsigned char", "ushort": "unsigned short", "uint": "unsigned int",
              "ulong": "unsigned long", "ulonglong": "unsigned long long",
              "schar": "signed char"}
OPERATORS = {"as": "=", "eq": "==", "ne": "!=", "pl": "+", "mi": "-", "ml": "*", "dv": "/",
             "md": "%", "apl": "+=", "ami": "-=", "amu": "*=", "adv": "/=", "amd": "%=",
             "lt": "<", "gt": ">", "le": "<=", "ge": ">=", "vc": "[]", "cl": "()",
             "nw": " new", "dl": " delete", "nwa": " new[]", "dla": " delete[]", "rf": "->",
             "ad": "&", "or": "|", "er": "^", "aad": "&=", "aor": "|=", "aer": "^=",
             "ls": "<<", "rs": ">>", "als": "<<=", "ars": ">>=", "nt": "!", "co": "~",
             "aa": "&&", "oo": "||", "pp": "++", "mm": "--", "cm": ",", "rm": "->*"}


class Bad(Exception):
    pass


class Parser:
    """Recursive descent over one mangled suffix."""

    def __init__(self, text):
        self.s, self.p = text, 0

    def peek(self):
        return self.s[self.p] if self.p < len(self.s) else ""

    def take(self):
        if self.p >= len(self.s):
            raise Bad("end of input")
        c = self.s[self.p]
        self.p += 1
        return c

    def number(self):
        start = self.p
        while self.peek().isdigit():
            self.p += 1
        if start == self.p:
            raise Bad("number expected")
        return int(self.s[start:self.p])

    def source_name(self):
        n = self.number()
        if n <= 0 or self.p + n > len(self.s):
            raise Bad("bad length")
        name = self.s[self.p:self.p + n]
        self.p += n
        return pretty_class_name(name)

    def qualified(self):
        """A class or namespace path."""
        if self.peek() == "Q":
            self.p += 1
            if self.peek() == "_":
                self.p += 1
                count = self.number()
                if self.take() != "_":
                    raise Bad("Q_ count")
            else:
                count = int(self.take())
            return [self.source_name() for _ in range(count)]
        return [self.source_name()]

    def type(self):
        c = self.peek()
        if c == "C":
            self.p += 1
            t = self.type()
            return dict(t, const=True)
        if c == "V":
            self.p += 1
            return dict(self.type(), volatile=True)
        if c == "U":
            self.p += 1
            k = self.take()
            if k not in UNSIGNED:
                raise Bad("unsigned " + k)
            return {"k": "prim", "n": UNSIGNED[k]}
        if c == "S":
            self.p += 1
            k = self.take()
            if k not in SIGNED:
                raise Bad("signed " + k)
            return {"k": "prim", "n": SIGNED[k]}
        if c == "P":
            self.p += 1
            return {"k": "ptr", "t": self.type()}
        if c == "R":
            self.p += 1
            return {"k": "ref", "t": self.type()}
        if c == "A":
            self.p += 1
            n = self.number()
            if self.take() != "_":
                raise Bad("array")
            return {"k": "arr", "n": n, "t": self.type()}
        if c == "F":
            self.p += 1
            params = self.params(stop="_")
            if self.take() != "_":
                raise Bad("function type")
            return {"k": "fn", "params": params, "ret": self.type()}
        if c == "M":
            raise Bad("pointer to member")
        if c.isdigit() or c == "Q":
            return {"k": "class", "path": self.qualified()}
        if c in PRIMITIVES:
            self.p += 1
            return {"k": "prim", "n": PRIMITIVES[c]}
        raise Bad("type code " + repr(c))

    def params(self, stop=""):
        out = []
        while self.p < len(self.s) and self.peek() != stop:
            out.append(self.type())
        return out


def pretty_class_name(name):
    """`CList<15mgCTexAnimeData>` -> `CList<mgCTexAnimeData>`."""
    lt = name.find("<")
    if lt < 0 or not name.endswith(">"):
        return name
    args, depth, cur = [], 0, ""
    for ch in name[lt + 1:-1]:
        if ch == "," and depth == 0:
            args.append(cur)
            cur = ""
            continue
        depth += ch == "<"
        depth -= ch == ">"
        cur += ch
    args.append(cur)
    shown = []
    for a in args:
        if re.fullmatch(r"-?\d+", a):
            shown.append(a)
            continue
        try:
            p = Parser(a)
            t = p.type()
            if p.p != len(a):
                raise Bad("template argument")
            shown.append(c_type(t))
        except Bad:
            shown.append(a)
    # Ghidra symbol names take no spaces.
    inner = ",".join(shown).replace(" *", "*").replace(" &", "&").replace(" ", "_")
    return name[:lt] + "<" + inner + ">"


def c_type(t, inner=""):
    """C++ spelling of a parsed type, wrapped around a declarator."""
    k = t["k"]
    cv = "const " if t.get("const") else ""
    if k == "prim":
        return (cv + C_SPELLING[t["n"]] + (" " + inner if inner else "")).strip()
    if k == "class":
        return (cv + "::".join(t["path"]) + (" " + inner if inner else "")).strip()
    if k in ("ptr", "ref"):
        mark = "*" if k == "ptr" else "&"
        decl = mark + (" const" if t.get("const") else "") + inner
        if t["t"]["k"] in ("arr", "fn"):
            decl = "(" + decl + ")"
        return c_type(t["t"], decl)
    if k == "arr":
        return c_type(t["t"], inner + "[" + str(t["n"]) + "]")
    if k == "fn":
        return c_type(t["ret"], inner + "(" + ", ".join(c_type(p) for p in t["params"]) + ")")
    raise ValueError(k)


def demangle(name):
    """The signature a mangled function name encodes, or None."""
    if name.startswith("__sinit_") or name.startswith("@"):
        return None
    for m in re.finditer(r"__", name):
        i = m.start()
        if i == 0:
            continue
        # `a___3FooFv`: the separator is the last of a run of underscores.
        if name[i + 2:i + 3] == "_":
            continue
        base, rest = name[:i], name[i + 2:]
        p = Parser(rest)
        try:
            cls, const = None, False
            if p.peek() != "F":
                cls = p.qualified()
                if p.peek() == "C":
                    p.p += 1
                    const = True
            if p.take() != "F":
                raise Bad("F expected")
            params = p.params()
            if p.p != len(rest):
                raise Bad("trailing")
        except Bad:
            continue
        return build(base, cls, const, params)
    return None


def build(base, cls, const, params):
    # The mangling spells a namespace like a class; `std` is the one namespace here.
    kind = "method" if cls and cls != ["std"] else "function"
    shown = base
    if kind == "method" and base == "__ct":
        kind, shown = "ctor", cls[-1].split("<")[0]
    elif kind == "method" and base == "__dt":
        kind, shown = "dtor", "~" + cls[-1].split("<")[0]
    elif base.startswith("__op"):
        shown = "operator " + base[4:]
    elif base.startswith("__") and base[2:] in OPERATORS:
        shown = "operator" + OPERATORS[base[2:]]
    varargs = bool(params) and params[-1] == {"k": "prim", "n": "..."}
    if varargs:
        params = params[:-1]
    if params == [{"k": "prim", "n": "void"}]:
        params = []
    plist = [c_type(t) for t in params] + (["..."] if varargs else [])
    proto = ("::".join(cls) + "::" if cls else "") + shown + "(" + ", ".join(plist) + ")"
    if const:
        proto += " const"
    return {"class": cls, "const": const, "kind": kind, "base": base, "params": params,
            "varargs": varargs, "demangled": proto}


def class_paths(t, out):
    if t["k"] == "class":
        out.add(tuple(t["path"]))
    for key in ("t", "ret"):
        if key in t:
            class_paths(t[key], out)
    for p in t.get("params", []):
        class_paths(p, out)


def sdk_header():
    """The SDK headers as one plain-C translation unit."""
    out = ["/* Generated by scripts/re/ghidra/prepare.py from the first game's headers. */",
           "typedef unsigned char bool;"]
    tags = set()
    texts = []
    for rel in SDK_HEADERS:
        path = FIRST_GAME_INCLUDE / rel
        if not path.exists():
            continue
        text = path.read_text()
        # Comments, then preprocessor lines (the project's macros are not SDK types).
        text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
        text = re.sub(r"//[^\n]*", "", text)
        text = re.sub(r"\\\n", " ", text)
        text = re.sub(r"^\s*#[^\n]*", "", text, flags=re.M)
        text = re.sub(r"^\s*STATIC_ASSERT\([^\n]*", "", text, flags=re.M)
        text = re.sub(r"__attribute__\s*\(\(.*?\)\)", "", text)
        # extern "C" blocks and single declarations.
        text = re.sub(r'extern\s+"C"\s*\{', "", text)
        text = re.sub(r"^\}\s*$", "", text, flags=re.M)
        text = re.sub(r'extern\s+"C"\s+', "", text)
        text = text.replace("unsigned __int128", "uint16")
        tags.update(re.findall(r"\bstruct\s+(\w+)", text))
        texts.append(f"/* {rel} */\n" + text)
    # C++ refers to a struct by its tag alone; C needs the typedef.
    out += [f"typedef struct {t} {t};" for t in sorted(tags)]
    out += texts
    return "\n".join(out) + "\n"


def main():
    os.chdir(ROOT)
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("-o", "--output", default="build/re/ghidra-work")
    args = ap.parse_args()
    out = Path(args.output)
    out.mkdir(parents=True, exist_ok=True)

    syms, (lo, hi) = symbols.read_symbols(symbols.ELF_PATH)
    names = symbols.spelled(syms)
    project = {}
    for line in Path(symbols.OUT_PATH).read_text().splitlines():
        m = re.match(r"^(\S+) = 0x([0-9a-fA-F]+);(.*)$", line)
        if m:
            project[int(m.group(2), 16)] = (m.group(1), m.group(3))
    retail = {}
    for s in syms:
        if s["idx"] in names and s["value"] in project and names[s["idx"]] == project[s["value"]][0]:
            retail[s["value"]] = s
    units = {}
    for line in Path("build/re/manifest.tsv").read_text().splitlines():
        unit, sym, addr, _size, _sec, _asm = line.split("\t")
        units[int(addr, 16)] = (unit, sym)

    rows, sigs, vtables = [], [], []
    stats = {"functions": 0, "mangled": 0, "unparsed": []}
    for addr in sorted(project):
        name, attrs = project[addr]
        s = retail.get(addr)
        rname = s["name"] if s else name
        size = s["size"] if s else 0
        kind = "func" if "type:func" in attrs else ("object" if "size:" in attrs else "label")
        unit = units.get(addr, ("", ""))[0]
        if unit and units[addr][1] != name:
            sys.exit(f"manifest and symbol list disagree at {addr:#x}")
        rows.append(f"{addr:08X}\t{name}\t{rname}\t{kind}\t{size:X}\t{unit}")
        if kind == "func":
            stats["functions"] += 1
            sig = demangle(rname)
            if sig:
                stats["mangled"] += 1
                classes = set()
                for p in sig["params"]:
                    class_paths(p, classes)
                sig.update(address=f"{addr:08X}", name=name, retail=rname,
                           types=sorted(list(c) for c in classes))
                sigs.append(json.dumps(sig))
            elif "__" in rname[1:] and not rname.startswith("__sinit_"):
                stats["unparsed"].append(rname)
        elif name.startswith("__vt__"):
            p = Parser(rname[len("__vt__"):])
            try:
                path = p.qualified()
                if p.p != len(rname) - len("__vt__"):
                    raise Bad("trailing")
            except Bad:
                continue
            vtables.append(f"{addr:08X}\t{name}\t{json.dumps(path)}\t{size:X}")
    missing = set(units) - set(project)
    if missing:
        sys.exit(f"{len(missing)} manifest functions have no symbol")

    (out / "symbols.tsv").write_text("\n".join(rows) + "\n")
    (out / "signatures.jsonl").write_text("\n".join(sigs) + "\n")
    (out / "vtables.tsv").write_text("\n".join(vtables) + "\n")
    (out / "sdk.h").write_text(sdk_header())
    print(f"{len(rows)} symbols, {stats['functions']} functions, {stats['mangled']} demangled, "
          f"{len(vtables)} vtables; {len(stats['unparsed'])} names with '__' left as plain names")
    for n in stats["unparsed"]:
        print("  plain:", n)
    return 0


if __name__ == "__main__":
    sys.exit(main())
