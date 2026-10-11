#!/usr/bin/env python3
"""quadgap.py <quad_lines.txt> <texbase hex, e.g. 0x34E0000> [context] -- RC1 Q9/G11 attribution reader for the one-shot
RVK_QUADCENSUS output. Per armed frame: the raw-stream draw total (nDraws, the guest's own wrapper-call count) and how many
draws sample <texbase>. A frame whose count drops to 0 between frames that have it is a GAP; the draw total on that frame is
compared with its neighbours (a port-side renderer drop would leave nDraws unchanged and only the per-draw lines would be
missing from the GPU side; a stream gap lowers nDraws by exactly the vanished draws). Prints each gap with neighbour draws."""
import re, sys, collections
f, base = sys.argv[1], sys.argv[2].upper().replace('0X', '')
ctx = int(sys.argv[3]) if len(sys.argv) > 3 else 1
n = {}; c = collections.Counter(); draws = collections.defaultdict(list)
for l in open(f, errors='replace'):
    m = re.match(r'\[quadcensus\] f(\d+) nDraws=(\d+)', l)
    if m: n[int(m.group(1))] = int(m.group(2)); continue
    m = re.match(r'\[quadcensus\] f(\d+) d(\d+) .*tex=0x(%s)\b' % base.lstrip('0'), l)
    if m:
        fr = int(m.group(1)); c[fr] += 1
        xy = re.search(r'xy=\{([^}]*)\}', l).group(1); uv = re.search(r'uv=\{([^}]*)\}', l).group(1); col = re.search(r'raw0=\{\S+ \S+ \S+ (\S+)\}', l).group(1)
        draws[fr].append('d%s xy=%s uv=%s c=%s' % (m.group(2), xy, uv, col))
frs = sorted(n)
print('armed frames f%d..f%d (%d); texbase 0x%s' % (frs[0], frs[-1], len(frs), base))
print('  ' + ' '.join('f%d:%d/%d' % (x, n[x], c[x]) for x in frs))
gaps = [x for x in frs if c[x] == 0 and any(c[y] for y in frs if y < x) and any(c[y] for y in frs if y > x)]
for g in gaps:
    steady = [c[y] for y in frs if c[y]]
    print('GAP f%d: nDraws=%d (neighbours %s), 0 draws on 0x%s' % (g, n[g], [n.get(g + d) for d in (-1, 1)], base))
    for d in range(-ctx, ctx + 1):
        if d == 0: continue
        print('   f%d (%d draws):' % (g + d, c[g + d])); [print('      ' + s) for s in draws[g + d]]
if not gaps: print('NO GAP inside the armed window')
