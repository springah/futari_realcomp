#!/usr/bin/env python3
import sys, struct, mmap, os
capdir = sys.argv[1]
addr = int(sys.argv[2],0)
count = int(sys.argv[3],0) if len(sys.argv)>3 else 32
which = sys.argv[4] if len(sys.argv)>4 else 'ring'
fmap = {'ring':('cap_ring.bin',0x079B3000),'low':('cap_low.bin',0x0),
        'image':('cap_image.bin',0x82000000),'gimage':('cap_gimage.bin',0x88000000)}
fname,base = fmap[which]
f=open(os.path.join(capdir,fname),'rb'); m=mmap.mmap(f.fileno(),0,prot=mmap.PROT_READ)
off = addr-base
for k in range(count):
    a=addr+k*4; o=off+k*4
    if o+4>len(m): break
    v=struct.unpack_from('>I',m,o)[0]
    t=v>>30
    ann=""
    if t==3:
        op=(v>>8)&0x7f; cnt=((v>>16)&0x3fff)+1
        ann="TYPE3 op=0x%02X cnt=%d"%(op,cnt)
    elif t==0:
        reg=v&0x7fff; cnt=((v>>16)&0x3fff)+1
        ann="TYPE0 reg=0x%04X cnt=%d"%(reg,cnt)
    elif t==2:
        ann="TYPE2 (nop)"
    elif t==1:
        ann="TYPE1"
    print("0x%08X: %08X  %s"%(a,v,ann))
