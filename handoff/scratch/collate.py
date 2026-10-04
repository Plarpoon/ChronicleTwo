import re,sys,collections
def rows(f):
    out=[]
    for l in open(f):
        if l.startswith("# NOTES"): break
        p=l.rstrip("\n").split("\t")
        try: a=int(p[0],16); b=int(p[1],16)
        except Exception: continue
        out.append([a,b,p[2],p[3],p[4]])
    return out
units=[]
for f in ["out_lib_text","out_A1","out_A2","out_A3","out_B1","out_B2"]:
    for r in rows(f+".tsv"):
        if units and any(u[0]==r[0] for u in units):
            u=next(u for u in units if u[0]==r[0])
            assert u[1]==r[1] and u[2]==r[2],(u,r); continue
        units.append(r)
units.sort()
RENAME={(0x2f26f0,"editmap"):"editmap2",(0x1a3460,"chrviewer"):"charaviewlp",(0x1a3490,"texviewer"):"texviewlp",
        (0x1a34c0,"mapview"):"mapviewlp",(0x2a9270,"soundviewer"):"sndviewlp"}
for u in units:
    k=(u[0],u[2])
    if k in RENAME: u[2]=RENAME[k]; 
# contiguity
for x,y in zip(units,units[1:]):
    if x[1]!=y[0]: print("GAP/OVERLAP",hex(x[1]),hex(y[0]),x[2],y[2])
print("first",hex(units[0][0]),"last",hex(units[-1][1]),"n",len(units))
d=collections.Counter(u[2] for u in units)
print("dups",[k for k,v in d.items() if v>1])
funcs=set()
for l in open("symtab.txt"):
    p=l.rstrip("\n").split("\t")
    if p[3]=="FUNC" and int(p[2],16): funcs.add((int(p[1],16),int(p[2],16),p[6]))
starts=[u[0] for u in units]
import bisect
bad=0;n=0
for a,s,nm in sorted(funcs):
    if a>=0x325c80: continue
    n+=1
    i=bisect.bisect_right(starts,a)-1
    if not(units[i][0]<=a and a+s<=units[i][1]): bad+=1; print("STRADDLE",hex(a),hex(s),nm,units[i][2])
print("text funcs",n,"bad",bad, "outside text:",sum(1 for a,s,nm in funcs if a>=0x325c80))
import json; json.dump(units,open("units.json","w"))
print(collections.Counter(u[3] for u in units if not u[2].startswith("lib/") ))
