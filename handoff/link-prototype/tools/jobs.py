#!/usr/bin/env python3
"""Print `src<TAB>obj<TAB>kind` for every prototype object (whole-unit asm),
and write build/pal-link/main_o_files."""
import os, re, sys
sys.path.insert(0, "scripts/build")
import layout
import lcf

L = layout.Layout()
SNAP = "build/snap/asm"
OUT = "build/pal-link"
PATCHED = f"{OUT}/src"


def relocate(path):
    return path.replace("build/pal/", f"{OUT}/")


BRANCH_TARGET = re.compile(
    r"^(\s*/\*.*?\*/\s+b(?!reak\b)[a-z0-9]*\s+(?:[^,\s]+,\s*)*)"
    r"([A-Za-z_$.][\w.$]*)[ \t]*$", re.M)
GLOBAL_LABEL = re.compile(r"^[ \t]*(?:glabel|jlabel) (\S+)$", re.M)


def twin(name):
    return f".L{name}$b"


def twin_branched_labels(text):
    defined = set(GLOBAL_LABEL.findall(text))
    branched = {m.group(2) for m in BRANCH_TARGET.finditer(text)} & defined
    if not branched:
        return text
    text = BRANCH_TARGET.sub(
        lambda m: m.group(1) + (twin(m.group(2)) if m.group(2) in branched else m.group(2)), text)
    alt = "|".join(re.escape(n) for n in branched)
    return re.sub(rf"^([ \t]*(?:glabel|jlabel) ({alt}))$",
                  lambda m: f"{m.group(1)}\n{twin(m.group(2))}:", text, flags=re.M)


def patch(unit, src):
    """Drop linker-defined labels (and the padding after __static_init_end)."""
    text = open(src).read()
    new = re.sub(r"\nglabel __static_init_end\n(    /\* [^\n]* \*/ \.word 0x00000000\n)+", "\n", text)
    if os.environ.get("TWIN"):
        new = twin_branched_labels(new)
    if new == text:
        return src
    dst = f"{PATCHED}/{unit}.s"
    os.makedirs(os.path.dirname(dst), exist_ok=True)
    open(dst, "w").write(new)
    return dst


objs = []
for u in L.units():
    kind = L.kinds[u]
    obj = relocate(L.object_path(u))
    print(f"{patch(u, f'{SNAP}/{u}.s')}\t{obj}\t{kind}")
    objs.append(obj)
seen = set()
for addr, k, n, s in L.rows:
    if n not in L.data_only or (n, s) in seen or n in lcf.LINKER_WRITTEN:
        continue
    seen.add((n, s))
    obj = relocate(L.data_object_path(n, s))
    kk = k.lstrip(".")
    src = f"{SNAP}/data/{n}.{kk}.s"
    if not os.path.exists(src):
        src = f"{SNAP}/data/main/{n}.{kk}.s"
    print(f"{src}\t{obj}\tdata")
    objs.append(obj)
open(f"{OUT}/main_o_files", "w").write("\n".join(objs) + "\n")
