#!/usr/bin/env python3
"""compare.py <out/compiler/flagset dir>... : match compiled functions against DC2 retail by mangled name."""
import struct,sys,glob,os,re,collections
ELF="rom/pal/extracted/iso/SCES_511.90"
d=open(ELF,"rb").read()
def secs_of(data):
    shoff,=struct.unpack_from("<I",data,0x20); es,n,sx=struct.unpack_from("<HHH",data,0x2e)
    S=[dict(zip(("name","type","flags","addr","offset","size","link","info","align","entsize"),struct.unpack_from("<10I",data,shoff+i*es))) for i in range(n)]
    no=S[sx]["offset"]
    for s in S: s["name"]=data[no+s["name"]:data.index(b"\0",no+s["name"])].decode()
    return S
def syms_of(data,S):
    st=next(s for s in S if s["type"]==2); so=S[st["link"]]["offset"]; out=[]
    for k in range(st["size"]//16):
        nm,v,sz,info,oth,shx=struct.unpack_from("<IIIBBH",data,st["offset"]+k*16)
        out.append((data[so+nm:data.index(b"\0",so+nm)].decode("latin1"),v,sz,info&15,shx))
    return out
RS=secs_of(d); RSY=syms_of(d,RS)
retail={}
dup=collections.Counter(n for n,v,sz,t,sh in RSY if t==2)
for n,v,sz,t,sh in RSY:
    if t==2 and sz and dup[n]==1 and v>=0x12c2c0: retail[n]=(v,sz)
rrel=set()
rs=next(s for s in RS if s["name"]==".relmain")
for k in range(rs["size"]//8):
    o,i=struct.unpack_from("<II",d,rs["offset"]+k*8); rrel.add(o)
MASK={4:0xfc000000,5:0xffff0000,6:0xffff0000,7:0xffff0000,2:0}
def rbytes(v,sz): return d[v-0x100000+0x80:v-0x100000+0x80+sz]
def funcs(path):
    o=open(path,"rb").read(); S=secs_of(o); Y=syms_of(o,S)
    rel=collections.defaultdict(dict)
    for s in S:
        if s["type"]==9:
            for k in range(s["size"]//8):
                off,i=struct.unpack_from("<II",o,s["offset"]+k*8); rel[s["info"]][off]=i&0xff
    for n,v,sz,t,sh in Y:
        if t==2 and sz and 0<sh<len(S):
            sec=S[sh]; yield n,o[sec["offset"]+v:sec["offset"]+v+sz],{k-v:t for k,t in rel[sh].items() if v<=k<v+sz}
def score(dirp,verbose=False):
    exact=same_size=total=0; near=[]; names=[]
    for p in sorted(glob.glob(dirp+"/*.o")):
        for n,code,rel in funcs(p):
            if n not in retail: continue
            v,sz=retail[n]; total+=1
            if sz!=len(code): names.append((n,"size",len(code),sz)); continue
            same_size+=1; rb=rbytes(v,sz); diff=0
            for i in range(0,sz,4):
                a,=struct.unpack_from("<I",code,i); b,=struct.unpack_from("<I",rb,i)
                m=0xffffffff
                if i in rel: m=MASK.get(rel[i],0)
                if v+i in rrel: m&=0xfc000000 if (b>>26) in (2,3) else 0xffff0000 if m else 0
                if (a&m)!=(b&m): diff+=1
            if diff==0: exact+=1; names.append((n,"ok",sz,sz))
            else: names.append((n,"diff",diff,sz//4))
    return exact,same_size,total,names
if __name__=="__main__":
    for dp in sys.argv[1:]:
        e,s,t,names=score(dp)
        print(f"{dp}: exact {e} / same-size {s} / common {t}")
        if os.environ.get("V"):
            for n in names: print("   ",*n)
