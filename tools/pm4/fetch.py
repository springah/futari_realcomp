#!/usr/bin/env python3
import sys, os
sys.path.insert(0,os.path.dirname(__file__))
from pm4 import GuestMem, Walker

def decode_fetch(tf0,tf1,tf2):
    tiled=(tf0>>30)&1
    pitch=((tf0>>21)&0x1FF)*32     # texels
    base=((tf1>>12)&0xFFFFF)<<12
    fmt=tf1&0x3F
    w=(tf2&0x1FFF)+1; h=((tf2>>13)&0x1FFF)+1
    return dict(tiled=tiled,pitch=pitch,base=base,fmt=fmt,w=w,h=h)

# walk caps_gp; when we hit the draw at 0x79BE3B0 (composite), dump live fetch consts for all slots
mem=GuestMem('/home/shant/xr-work/caps_gp'); w=Walker(mem,sys.stdout)
target=0x79BE3B0
orig=w.draw_here
def dh(i,n,prim):
    orig(i,n,prim)
    if i==target:
        print("COMPOSITE DRAW @0x%X n=%d prim=%d"%(i,n,prim))
        for slot in range(4):
            b=0x4800+slot*6
            tf=[w.reg.get(b+k,0) for k in range(6)]
            if any(tf):
                dec=decode_fetch(tf[0],tf[1],tf[2])
                print("  fetch slot%d: %s"%(slot," ".join("%08X"%x for x in tf)))
                print("     -> base=0x%08X %dx%d fmt=%d tiled=%d pitch=%d"%(dec['base'],dec['w'],dec['h'],dec['fmt'],dec['tiled'],dec['pitch']))
        # also the vertex fetch + verts (the fullscreen quad)
        vf0=w.reg.get(0x48BE,0); va=vf0&~3
        print("  vertex fetch 0x48BE=%08X va=0x%X"%(vf0,va))
        for k in range(n):
            rec=[mem.be32(va+k*24+c*4) for c in range(6)]
            import struct
            xs=struct.unpack('>f',struct.pack('>I',rec[0]))[0]
            ys=struct.unpack('>f',struct.pack('>I',rec[1]))[0]
            us=struct.unpack('>f',struct.pack('>I',rec[4]))[0]
            vs=struct.unpack('>f',struct.pack('>I',rec[5]))[0]
            print("     v%d pos=(%.2f,%.2f) col=0x%08X uv=(%.3f,%.3f) raw=%s"%(k,xs,ys,rec[3],us,vs," ".join("%08X"%x for x in rec)))
w.draw_here=dh
w.walk(0x79BB000,0x79BE624)

# Also: what is currently at guest 0x00DBD000 in caps_gp (was it resolved by a prior frame)?
print("\nFirst 8 dwords @0x00DBD000 in caps_gp cap_low:")
print("  "," ".join("%08X"%(mem.be32(0x00DBD000+k*4)) for k in range(8)))
print("First 8 dwords @0x00DBD000 in caps_gp2 cap_low:")
mem2=GuestMem('/home/shant/xr-work/caps_gp2')
print("  "," ".join("%08X"%(mem2.be32(0x00DBD000+k*4)) for k in range(8)))
