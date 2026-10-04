#!/usr/bin/env python3
import sys,glob,os,struct,collections
sys.argv=[sys.argv[0]]
exec(open("build/cctest/compare.py").read().split('if __name__')[0])
MAP={"stSetBuffer__9mgCMemoryFPvi":"stSetBuffer__9mgCMemoryFP1i"}
# include duplicated static names by address
EXTRA={"random__Fv":0x321280,"search_txt__Fc":0x320d40,"GetCRC__FPUci":0x3211c0,"abs__Ff":0x321b60,"rnd__Fv":0x3249b0,"irnd__Fv":0x324960}
allf={n:(v,sz) for n,v,sz,t,sh in RSY if t==2 and sz}
def comment(path):
    o=open(path,"rb").read(); S=secs_of(o)
    c=[s for s in S if s["name"]==".comment"]
    return o[c[0]["offset"]:c[0]["offset"]+c[0]["size"]].replace(b"\0",b" ").decode("latin1").strip() if c else ""
def cmpf(code,rel,v,sz):
    if sz!=len(code):
        # allow trailing nop padding differences
        return None
    rb=rbytes(v,sz); diff=0
    for i in range(0,sz,4):
        a,=struct.unpack_from("<I",code,i); b,=struct.unpack_from("<I",rb,i)
        m=0xffffffff
        if i in rel: m=MASK.get(rel[i],0)
        if v+i in rrel: m&=0xfc000000 if (b>>26) in (2,3) else 0xffff0000 if m else 0
        if (a&m)!=(b&m): diff+=1
    return diff
res=collections.defaultdict(dict)  # comp -> func -> {fs: diff}
coms={}
only=os.environ.get("ONLY")
for p in sorted(glob.glob("build/cctest/out2/*/*/*.o")):
    comp,fs=p.split("/")[3:5]
    coms[comp]=comment(p)
    for n,code,rel in funcs(p):
        rn=MAP.get(n,n)
        if rn in EXTRA: v=EXTRA[rn]; sz=next(s for nn,vv,s,t,sh in RSY if vv==v and t==2)
        elif rn in allf: v,sz=allf[rn]
        else: continue
        # strip retail size to code size if retail longer only by nops? compare min len with sizes equal required
        r=cmpf(code,rel,v,sz); old=res[comp].setdefault(rn,{}).get(fs,'x')
        if old=='x' or old is None or (r is not None and r<old): res[comp][rn][fs]=r
fnames=sorted({f for c in res for f in res[c]})
for comp in sorted(res):
    tot=sum(1 for f in fnames if any(d==0 for d in res[comp].get(f,{}).values()))
    print(f"{comp:18s} [{coms[comp]}] matched {tot}/{len(fnames)}")
    if only and only!=comp and only!="all": continue
    if only:
        for f in fnames:
            r=res[comp].get(f,{})
            print("    %-36s %s"%(f," ".join(f"{k}:{'OK' if v==0 else ('sz' if v is None else v)}" for k,v in r.items())))
