#!/usr/bin/env python3
"""nav360band.py <bank_dir>... -- the 360 shell-screen stability measurement (RC1 Q7v (c)).
Each bank_dir is a nav360_mac.sh bank (shot_NN_<node>.png). Per shot index: the SAME-BUILD BAND = the max over all
leg pairs of mean|dRGB| (the w155 comparator's imgdiff metric, gate_w155_compare.py) -- the counterpart of the shell gates'
band. Band 0.00 = byte-identical screen in every leg = deterministic. Prints a table and a verdict line per index."""
import sys, os, re, glob, itertools
import numpy as np
from PIL import Image
banks = sys.argv[1:]
def shots(b):
    d = {}
    for p in glob.glob(os.path.join(b, 'shot_*.png')):
        m = re.match(r'shot_(\d+)_(.*)\.png', os.path.basename(p)); d[int(m.group(1))] = (m.group(2), p)
    return d
S = [shots(b) for b in banks]
idx = sorted(set.intersection(*[set(s) for s in S]))
print('legs:', banks)
print('%-3s %-16s %s  %s' % ('idx', 'node', ' '.join('%7s' % ('%s-%s' % (a, b)) for a, b in [(i + 1, j + 1) for i, j in itertools.combinations(range(len(S)), 2)]), 'band  class'))
nd = 0
for i in idx:
    I = [np.asarray(Image.open(s[i][1]).convert('RGB'), dtype=np.int16) for s in S]
    ds = [float(np.abs(I[a] - I[b]).mean()) for a, b in itertools.combinations(range(len(I)), 2)]
    band = max(ds); cls = 'DETERMINISTIC (identical)' if band == 0.0 else ('stable (<=1.0)' if band <= 1.0 else 'VARIES')
    nd += band == 0.0
    print('%-3d %-16s %s  %5.2f  %s' % (i, S[0][i][0][:16], ' '.join('%7.2f' % d for d in ds), band, cls))
print('SUMMARY: %d indices, %d byte-identical in all %d legs' % (len(idx), nd, len(S)))
