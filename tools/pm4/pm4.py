#!/usr/bin/env python3
import sys, struct, mmap, os

class GuestMem:
    """Flat guest address space assembled from capture windows.
    Prefer cap_ring over cap_low where they overlap (fresher PM4)."""
    def __init__(self, capdir):
        self.windows = []  # (start, end, mmap)
        def add(fname, base):
            p = os.path.join(capdir, fname)
            if not os.path.exists(p): return
            f = open(p, 'rb')
            m = mmap.mmap(f.fileno(), 0, prot=mmap.PROT_READ)
            self.windows.append((base, base+len(m), m))
        # order matters: ring first so it wins overlap with low
        add('cap_ring.bin',  0x079B3000)
        add('cap_low.bin',   0x00000000)
        add('cap_image.bin', 0x82000000)
        add('cap_gimage.bin',0x88000000)
    def _find(self, a, n):
        for base,end,m in self.windows:
            if a>=base and a+n<=end:
                return m, a-base
        return None,0
    def be32(self, a):
        m,off = self._find(a,4)
        if m is None: return None
        return struct.unpack_from('>I', m, off)[0]
    def has(self, a, n=4):
        m,_ = self._find(a,n); return m is not None

def base10(v):
    return "0x%X" % v

class Walker:
    def __init__(self, mem, out):
        self.mem = mem
        self.reg = {}          # reg index -> value (shadow of g_regFile)
        self.events = []       # chronological log
        self.out = out
        # per-draw / pass state
        self.ndraw = 0
        self.draws = []        # list of dicts
        # tracked registers
        self.tracked = set([0x2000,0x2001,0x2002,0x2003,0x2004,0x2005,0x2006,
                            0x2208, 0x2318,0x2319,0x231A,0x231B,0x231C,0x2000+0x100])
    def be32(self,a):
        v = self.mem.be32(a)
        return 0 if v is None else v
    def writeReg(self, r, val):
        if r < 0x6100:
            old = self.reg.get(r)
            self.reg[r] = val
            if r in self.tracked and old != val:
                self.events.append(('REG', self.cur_i, r, val, old))
    def draw_here(self, i, n, prim):
        vf0 = self.reg.get(0x48BE, 0)
        vf1 = self.reg.get(0x48BF, 0)
        va = vf0 & ~3
        tf1 = self.reg.get(0x4801, 0)
        texbase = ((tf1 >> 12) & 0xFFFFF) << 12
        tw = (self.reg.get(0x4802,0) & 0x1FFF)+1
        th = ((self.reg.get(0x4802,0) >> 13)&0x1FFF)+1
        fmt = tf1 & 0x3F
        # scan all 32 texture fetch slots for nonzero bases
        allbases = []
        for slot in range(32):
            r1 = 0x4800 + slot*6 + 1
            v1 = self.reg.get(r1, 0)
            b = ((v1 >> 12) & 0xFFFFF) << 12
            if b:
                allbases.append((slot, b, v1 & 0x3F))
        mode = self.reg.get(0x2208,0) & 0x7
        d = dict(i=i, n=n, prim=prim, va=va, vf0=vf0, vf1=vf1,
                 texbase=texbase, tw=tw, th=th, fmt=fmt, mode=mode,
                 color_info=self.reg.get(0x2001,0), surf=self.reg.get(0x2000,0),
                 copy_ctrl=self.reg.get(0x2318,0), copy_base=self.reg.get(0x2319,0),
                 allbases=allbases)
        self.draws.append(d)
        self.events.append(('DRAW', i, d))
        self.ndraw += 1
    def walk(self, start, end):
        i = start
        ibstack = []
        guard = 0
        while True:
            guard += 1
            if guard > 5_000_000:
                self.events.append(('ERR','guard',0,0,0)); break
            if i + 4 > end:
                if not ibstack: break
                ri, re = ibstack.pop()
                i, end = ri, re
                continue
            self.cur_i = i
            w = self.be32(i); t = w >> 30
            if t == 0:
                reg = w & 0x7fff; cnt = ((w>>16)&0x3fff)+1
                for k in range(cnt):
                    self.writeReg(reg+k, self.be32(i+4+k*4))
                i += 4*(1+cnt)
            elif t == 3:
                op = (w>>8)&0x7f; cnt = ((w>>16)&0x3fff)+1
                if op == 0x2D and cnt >= 2:  # SET_CONSTANT
                    offType = self.be32(i+4)
                    idx = offType & 0x7FF; typ = (offType>>16)&0xFF
                    base = {0:0x4000,1:0x4800,2:0x4900,3:0x4908,4:0x2000}.get(typ)
                    if base is not None:
                        for k in range(cnt-1):
                            self.writeReg(base+idx+k, self.be32(i+8+k*4))
                    i += 4*(1+cnt)
                elif op == 0x32 and cnt >= 3:  # LOAD_ALU_CONSTANT
                    maddr = self.be32(i+4) & 0x3FFFFFFF
                    offType = self.be32(i+8)
                    idx = offType & 0x7FF; typ = (offType>>16)&0xFF
                    szDw = self.be32(i+12) & 0xFFF
                    base = {0:0x4000,1:0x4800,2:0x4900,3:0x4908,4:0x2000}.get(typ)
                    if base is not None and maddr:
                        for k in range(szDw):
                            self.writeReg(base+idx+k, self.be32(maddr+k*4))
                    i += 4*(1+cnt)
                elif op == 0x27:  # IM_LOAD (shader) - skip detail
                    i += 4*(1+cnt)
                elif op == 0x46:  # EVENT_WRITE
                    ev = self.be32(i+4) & 0x3F
                    self.events.append(('EVENT', i, ev, cnt, 0))
                    i += 4*(1+cnt)
                elif op == 0x22 or op == 0x36:  # DRAW_INDX / DRAW_INDX_2
                    d2 = self.be32(i+8)
                    n = (d2>>16)&0xFFFF
                    prim = d2 & 0x3F
                    self.draw_here(i, n, prim)
                    i += 4*(1+cnt)
                elif op == 0x3F:  # INDIRECT_BUFFER
                    ibBase = self.be32(i+4) & ~3
                    ibSize = self.be32(i+8) & 0xFFFFF
                    nxt = i + 4*(1+cnt)
                    if ibBase and ibSize and ibSize < 0x100000 and len(ibstack) < 8:
                        self.events.append(('IB', i, ibBase, ibSize, 0))
                        ibstack.append((nxt, end))
                        i = ibBase; end = ibBase + ibSize*4
                    else:
                        i = nxt
                    continue
                else:
                    i += 4*(1+cnt)
            elif t == 2:
                i += 4
            else:
                # t==1 TYPE1 (2 reg writes) - rare; approximate skip
                i += 4

def main():
    capdir = sys.argv[1]
    start = int(sys.argv[2],0)
    end = int(sys.argv[3],0)
    mem = GuestMem(capdir)
    w = Walker(mem, sys.stdout)
    w.walk(start, end)
    # emit event log
    print("=== WALK %s window [0x%X,0x%X) draws=%d events=%d ===" % (capdir,start,end,w.ndraw,len(w.events)))
    for e in w.events:
        kind = e[0]
        if kind == 'REG':
            _,i,r,val,old = e
            print("  @%s REG 0x%04X = 0x%08X (was %s)" % (base10(i), r, val, "0x%08X"%old if old is not None else "unset"))
        elif kind == 'DRAW':
            _,i,d = e
            ab = " ".join("s%d:0x%X/f%d"%(s,b,f) for s,b,f in d['allbases'])
            print("  @%s DRAW n=%d prim=%d va=0x%X tex0=0x%X %dx%d fmt=%d mode=%d COLOR_INFO=0x%08X SURF=0x%08X | slots[%s]" % (
                base10(i), d['n'], d['prim'], d['va'], d['texbase'], d['tw'], d['th'], d['fmt'], d['mode'],
                d['color_info'], d['surf'], ab))
        elif kind == 'IB':
            _,i,b,s,_ = e
            print("  @%s INDIRECT_BUFFER base=0x%X size=%d dw (0x%X bytes)" % (base10(i), b, s, s*4))
        elif kind == 'EVENT':
            _,i,ev,cnt,_ = e
            print("  @%s EVENT_WRITE event=0x%X" % (base10(i), ev))
        elif kind == 'ERR':
            print("  ERROR", e)

if __name__ == '__main__':
    main()
