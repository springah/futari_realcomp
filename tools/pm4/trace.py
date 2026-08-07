#!/usr/bin/env python3
import sys, os
sys.path.insert(0,os.path.dirname(__file__))
from pm4 import GuestMem, Walker

# Enhanced: snapshot copy regs at each mode6 draw, print full ordered trace,
# mark draws sampling a watch address, list ALL resolve dests.
def run(capdir, start, end, label, watch=0x00DBD000):
    mem=GuestMem(capdir); w=Walker(mem,sys.stdout)
    # monkeypatch: record copy regs at draw time
    orig=w.draw_here
    snaps=[]
    def dh(i,n,prim):
        pre=dict(cc=w.reg.get(0x2318,0),cb=w.reg.get(0x2319,0),cp=w.reg.get(0x231A,0),
                 ci=w.reg.get(0x231B,0),mode=w.reg.get(0x2208,0),
                 surf=w.reg.get(0x2000,0),col=w.reg.get(0x2001,0))
        orig(i,n,prim)
        w.draws[-1]['snap']=pre
    w.draw_here=dh
    w.walk(start,end)
    print("\n############### %s [0x%X,0x%X) draws=%d ###############"%(label,start,end,w.ndraw))
    all_dests=set()
    passidx=0
    for e in w.events:
        k=e[0]
        if k=='IB':
            _,i,b,s,_=e; print("  @0x%X  IB -> 0x%X (%d dw)"%(i,b,s))
        elif k=='REG' and e[2] in (0x2000,0x2001):
            _,i,r,val,old=e
            nm='RB_SURFACE_INFO' if r==0x2000 else 'RB_COLOR_INFO'
            base_tile=val&0xFFF if r==0x2001 else None
            extra=(" edram_base_tile=%d"%(val&0xFFF)) if r==0x2001 else (" pitch=%d"%(val&0x3FFF))
            print("  @0x%X  ** RT SWITCH %s=0x%08X%s"%(i,nm,val,extra))
        elif k=='REG' and e[2]==0x2208:
            _,i,r,val,old=e
            mn={0:'IGNORE',4:'COLOR_DEPTH',5:'DEPTH',6:'COPY(resolve)'}.get(val&7,'?%d'%(val&7))
            print("  @0x%X  RB_MODECONTROL=0x%X mode=%s"%(i,val,mn))
        elif k=='DRAW':
            _,i,d=e
            sn=d.get('snap',{})
            tag=''
            if d['mode']==6:
                all_dests.add(sn.get('cb',0))
                tag=' <== RESOLVE dest=0x%08X pitch=0x%08X info=0x%08X ctrl=0x%08X'%(
                    sn.get('cb',0),sn.get('cp',0),sn.get('ci',0),sn.get('cc',0))
            watched = any(b==watch for (s,b,f) in d['allbases'])
            if watched: tag += '  <<<< SAMPLES 0x%X'%watch
            # only print resolves, sampling draws, or every draw if few
            if d['mode']==6 or watched or w.ndraw<80:
                ab=" ".join("0x%X/f%d"%(b,f) for s,b,f in d['allbases'])
                print("  @0x%X  DRAW n=%d prim=%d mode=%d tex[%s]%s"%(i,d['n'],d['prim'],d['mode'],ab,tag))
    print("  --- ALL resolve dests: %s"%[hex(x) for x in sorted(all_dests)])
    print("  --- resolves to FRONT BUFFER 0x006E2000? %s"%(0x006E2000 in all_dests))
    return w

if __name__=='__main__':
    run('/home/shant/xr-work/caps_gp','/x'and 0x79BB000,0x79BE624,'HUD/COMPOSITE caps_gp')
