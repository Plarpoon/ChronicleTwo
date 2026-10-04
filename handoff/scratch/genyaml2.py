import json,sys
units=json.load(open("units.json"))
names=[u[2] for u in units]; idx={n:i for i,n in enumerate(names)}
OFF=0xfff80; FILE_END=0x37cd80
def rows(f,unitcol=3):
    out=[]
    for l in open(f):
        if l.startswith("# NOTES"): break
        p=l.rstrip("\n").split("\t")
        try: a=int(p[1],16); b=int(p[2],16)
        except Exception: continue
        assert p[unitcol] in idx or p[unitcol].startswith('lib/'),(f,p[unitcol])
        out.append((p[0],a,b,p[unitcol]))
    return out
lib=rows("out_lib_data.tsv")
allr=lib+rows("data2_data.tsv")+rows("data2_rodata.tsv")+rows("data2_small.tsv")+rows("data2_bss.tsv")+rows("data2_rdata.tsv")
def sect(name,lo,hi):
    r=sorted([x for x in allr if x[0]==name and lo<=x[1]<hi],key=lambda x:x[1])
    m=[]
    for s,a,b,u in r:
        if m and m[-1][3]==u and m[-1][2]==a: m[-1]=(s,m[-1][1],b,u)
        else: m.append((s,a,b,u))
    for x,y in zip(m,m[1:]):
        assert x[2]==y[1],(name,hex(x[2]),hex(y[1]),x[3],y[3])
        if x[3] in idx and y[3] in idx and not x[3].startswith('lib') and not y[3].startswith('lib') and x[3]!='crt0': assert idx[x[3]]<idx[y[3]],(name,x,y)
    assert m[0][1]==lo and m[-1][2]==hi,(name,hex(m[0][1]),hex(lo),hex(m[-1][2]),hex(hi))
    return m
L=[]
def sub(start,typ,name,extra=""):
    L.append(f"      - {{start: 0x{start-OFF:x}, type: {typ}, name: {name}{extra}}}")
def nobits(vram,typ,name,extra=""):
    L.append(f"      - {{start: 0x{FILE_END-OFF:x}, type: {typ}, name: {name}, vram: 0x{vram:x}{extra}}}")
for a,b,n,src,conf in units: sub(a,"asmtu",n)
sub(0x325c80,"data","vutext",", dir: main, linker_section: .vutext")
for s,a,b,u in sect(".data",0x32a320,0x363480): sub(a,".data",u)
sub(0x363480,"data","vudata",", dir: main, linker_section: .vudata")
# rodata: lib, game A, libgcc, game B
for s,a,b,u in sect(".rodata",0x363580,0x3728a0)+sect(".rodata",0x3728a0,0x372ca0)+sect(".rodata",0x372ca0,0x379680): sub(a,".rodata",u)
for s,a,b,u in sect(".init",0x379680,0x37afe0): sub(a,".sinit",u)
for s,a,b,u in sect(".ctor",0x37afe0,0x37b0b0): sub(a,".data",u,", linker_section: .ctor")
for s,a,b,u in sect(".vtable",0x37b0b0,0x37c6f0): sub(a,".data",u,", linker_section: .vtables")
sub(0x37c6f0,"rdata","rdata",", dir: main")
for s,a,b,u in sect(".sdata",0x37c700,0x37cd80): sub(a,".sdata",u)
for s,a,b,u in sect(".sbss",0x37cd80,0x37ead5): nobits(a,".sbss",u)
b1=sect(".bss",0x37eb00,0x385ec0)
nobits(0x37ead5,".bss",b1[0][3])
for s,a,b,u in b1[1:]: nobits(a,".bss",u)
for s,a,b,u in sect(".bss",0x385ec0,0x1f35080)+sect(".bss",0x1f35080,0x1f350c0)+sect(".bss",0x1f350c0,0x1f649d0): nobits(a,".bss",u)
nobits(0x1f649d0,".bss","lib/libc/errno/errno")
L.append(f"  - [0x{FILE_END-OFF:x}]")
head=open("head.yaml").read()
head=head.replace("asm_path: asm/pal","asm_path: ps2/asm/pal")
head=head.replace("  create_c_files: False\n","  create_c_files: False\n  # tools/splat_ext/sinit.py: a unit's `__sinit_<file>.cpp` function, which\n  # MWCC emits into `.init` rather than `.text`.\n  extensions_path: tools/splat_ext\n")
head=head.replace("  # what they hold.\n","  # what they hold.\n  #\n  # Every unit's sections carry its name: `.data`, `.rodata`, `.sdata`,\n  # `.sbss` and `.bss`, the static initialiser (`.sinit`, linked as `.init`),\n  # its entry in the `__static_init` table (`.ctor`) and its vtables\n  # (`.vtables`). splat writes them all into the unit's one file.\n")
open(sys.argv[1],"w").write(head+"\n".join(L)+"\n")
from collections import Counter
print(len(L),Counter(l.split("type: ")[1].split(",")[0] for l in L if "type:" in l))
