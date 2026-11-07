#!/usr/bin/env python3
"""hunt.py MOD TREE -- ad-hoc w1107 hunts: (1) fine .data deltas around the nav cluster, (2) RT_DIVGUARD twin by
neighbour delta + the lis/lwz->divwu shape (PLAN_kiniro_bringup step 3f routes 2 and 4)."""
import sys, os, collections, bisect
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__))))
import modtools as M
G, D = M.G, M.D
mod, tdir = sys.argv[1], sys.argv[2]
src = M.tree('reco_normal', 'out_reco'); dst = M.tree(mod, tdir)
uniq = M.uniq_map(src, dst)
lo, hi = int(sys.argv[3], 16) if len(sys.argv) > 3 else 0x884D6600, int(sys.argv[4], 16) if len(sys.argv) > 4 else 0x884D6F00
h = collections.defaultdict(collections.Counter)
for s, t in uniq.items():
    rd = dict(D.refs(dst, t))
    for k, ea in D.refs(src, s):
        if lo <= ea < hi and k in rd: h[ea][rd[k] - ea] += 1
print('== fine deltas in [0x%08X,0x%08X)' % (lo, hi))
for ea in sorted(h):
    print('  0x%08X: %s' % (ea, ', '.join('%+#x x%d' % kv for kv in h[ea].most_common(3))))
# divguard
uk = sorted(uniq)
for a in (0x882272E8, 0x881378A0):
    i = bisect.bisect_left(uk, a)
    nb = [uk[j] for j in (i - 2, i - 1, i, i + 1) if 0 <= j < len(uk)]
    print('== neighbours of 0x%08X: %s' % (a, ', '.join('0x%08X->0x%08X(%+#x)' % (n, uniq[n], uniq[n] - n) for n in nb)))
    for n in nb:
        c = a + (uniq[n] - n)
        print('   candidate 0x%08X is_start=%s ext=%s (reco ext %d insns)' % (c, c in dst.set, dst.ext.get(c, 0) // 4, src.ext[a] // 4))
print('== functions with a lis/lwz -> divwu (size 500..800 insns)')
for s in dst.starts:
    n = dst.ext[s] // 4
    if not 500 <= n <= 800: continue
    reg = {}
    for k in range(n):
        x = dst.w(s + 4 * k); op = x >> 26; rt = (x >> 21) & 31; ra = (x >> 16) & 31; rb = (x >> 11) & 31
        si = x & 0xFFFF; si = si - 0x10000 if si & 0x8000 else si
        if op == 15 and ra == 0: reg[rt] = ('hi', (si << 16) & 0xFFFFFFFF); continue
        if op == 32 and ra in reg and reg[ra][0] == 'hi': reg[rt] = ('ld', (reg[ra][1] + si) & 0xFFFFFFFF, k); continue
        if op == 31 and ((x >> 1) & 0x3FF) == 459 and rb in reg and reg[rb][0] == 'ld':
            print('  0x%08X (%d insns): divwu insn %d divisor 0x%08X' % (s, n, k, reg[rb][1])); break
