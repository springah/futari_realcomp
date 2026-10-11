#!/usr/bin/env python3
# markframes.py guest.log -- present-frame index (last [rvk] wrote nvk_fN before the line; resolution 30) at each
# stage-event marker, relative to the GameEntry(msg=17) stage start. Used for replay-playback determinism (RC1 Q3).
import re,sys
f=0; t0=None; out=[]
pats=[('msg17',r'GameEntry\(msg=17, r4'),('d76=4',r'd76 3->4'),('cred=0@5',r'd76 4->5'),('d76=8',r'd76 5->8'),('death',r'LOOP/DEATH'),('msg10',r'GameEntry\(msg=10, r4'),('msg11',r'GameEntry\(msg=11, r4')]
for l in open(sys.argv[1],errors='replace'):
    m=re.search(r'nvk_f(\d+)\.png',l)
    if m: f=int(m.group(1))
    for n,p in pats:
        if re.search(p,l):
            if n=='d76=4' and t0 is None: t0=f
            out.append((n,f))
seen=set()
for n,f in out:
    if n in seen and n!='msg11': continue
    seen.add(n); print(f"{n:10s} frame~{f}  rel={f-(t0 or 0)}")
