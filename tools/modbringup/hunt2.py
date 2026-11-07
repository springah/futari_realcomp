#!/usr/bin/env python3
"""hunt2.py MOD TREE -- RT_DIVGUARD twin hunt for a module where ShipCtor 0x8814DDC8 has no unique body twin:
neighbour-delta candidates for the ctor, every lis/addi code-address registration in the candidate (index, target),
and for each registered target: size + whether it has a 'lwz r,164(rX) ... divwu' blink-period shape with a data or
an immediate divisor."""
import sys, os, bisect
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import modtools as M
D = M.D
mod, tdir = sys.argv[1], sys.argv[2]
src = M.tree('reco_normal', 'out_reco'); dst = M.tree(mod, tdir)
uniq = M.uniq_map(src, dst); uk = sorted(uniq)
a = 0x8814DDC8
i = bisect.bisect_left(uk, a)
cands = set()
for j in range(i - 3, i + 3):
    if 0 <= j < len(uk):
        n = uk[j]; c = a + (uniq[n] - n)
        print('neighbour 0x%08X -> 0x%08X (%+#x): ctor candidate 0x%08X start=%s ext=%d (reco %d)' % (n, uniq[n], uniq[n] - n, c, c in dst.set, dst.ext.get(c, 0) // 4, src.ext[a] // 4))
        if c in dst.set: cands.add(c)
def shape(f):
    reg = {}; out = []
    for k in range(dst.ext[f] // 4):
        x = dst.w(f + 4 * k); op = x >> 26; rt = (x >> 21) & 31; ra = (x >> 16) & 31; rb = (x >> 11) & 31
        si = x & 0xFFFF; si = si - 0x10000 if si & 0x8000 else si
        if op == 15 and ra == 0: reg[rt] = ('hi', (si << 16) & 0xFFFFFFFF); continue
        if op == 14 and ra == 0: reg[rt] = ('imm', si); continue
        if op == 32 and ra in reg and reg[ra][0] == 'hi': reg[rt] = ('ld', (reg[ra][1] + si) & 0xFFFFFFFF); continue
        if op == 31 and ((x >> 1) & 0x3FF) == 459 and k < 120:
            out.append('divwu@%d by %s' % (k, ('%s 0x%X' % reg[rb]) if rb in reg else 'r%d' % rb))
    return out
for c in sorted(cands):
    regs = [(k, ea) for k, ea in D.refs(dst, c) if ea in dst.set]
    print('ctor 0x%08X registers %d code addresses: %s' % (c, len(regs), ' '.join('%d:0x%08X' % r for r in regs)))
    for k, ea in regs:
        sh = shape(ea)
        if sh: print('   0x%08X (%d insns) %s' % (ea, dst.ext[ea] // 4, '; '.join(sh)))
rs = [(k, ea) for k, ea in D.refs(src, a) if ea in src.set]
print('reco ctor registers: %s' % ' '.join('%d:0x%08X' % r for r in rs))
