#!/usr/bin/env python3
"""kiniro_pix.py -- the two PIXEL rungs of the Black Label gate (docs/PLAN_kiniro_bringup.md "Quality bar").

  richness <tag> <first_shot_index>
      stagepix_mac.py's richness metric (distinct 6-bit colours, luma edge energy, black/white fractions of the
      playfield crop) over every shot_N.png of the bank from <first_shot_index> on. PASS if the richest frame clears
      the Ver 1.5 CONTROL FLOOR that stagepix uses to accept a control arm (colours >= 15000 and edges >= 15): a
      stage frame of real texture exists in the run. Menus read ~10k / ~10, a stage ~24k / ~29 (stagepix 10-05 sanity).
  regress <tag> <shot_index> <ref_png>
      self-reference regression: compare shot_<index>.png with a banked reference; if the reference does not exist it
      is BANKED from this run (verdict BANKED). PASS if < KIN_PIX_TOL (12 %) of the pixels differ by > 40 in any
      channel. Meant for the static hub frame (shot taken 3 s after START at the module title).
Exit 0 on PASS/BANKED, 1 on FAIL, 2 on no frames. One line per verdict, greppable: PIX-RICH / PIX-REGRESS.
"""
import os, sys, glob, re, shutil
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import numpy as np
from PIL import Image
import stagepix_mac as S

# 12 %: the hub sits on an animated, translucent backdrop whose phase differs run to run; same-build samples read 0.00 / 2.41 /
# 3.93 / 4.46 / 5.16 / 7.57 % (2026-10-31, both modes), so 3 % and then 6 % were a flicker away from a false FAIL. A real drift
# (a different screen, a missing panel) reads far above 12 %. A phase-insensitive rung (compare the panel's text/edges, or the min
# over several frames) is owed; until then this is a coarse "same screen" check, not a pixel diff.
TOL = float(os.environ.get('KIN_PIX_TOL', '0.12'))

def shots(tag):
    d = os.path.join(S.BANK, tag)
    out = []
    for p in glob.glob(os.path.join(d, 'shot_*.png')):
        m = re.search(r'shot_(\d+)\.png$', p)
        if m: out.append((int(m.group(1)), p))
    return sorted(out)

def richness(tag, first):
    best = None
    for n, p in shots(tag):
        if n < first: continue
        c, e, b, w = S.metric(p)
        if w >= 0.97: continue                       # the display-off trap, as in stagepix
        if best is None or (c, e) > (best[1], best[2]): best = (n, c, e, b, w)
    if best is None:
        print('PIX-RICH NO-FRAMES (no shot_N.png with N >= %d in %s)' % (first, tag)); return 2
    n, c, e, b, w = best
    ok = c >= S.MIN_CTRL_COLOURS and e >= S.MIN_CTRL_EDGES
    print('PIX-RICH %s shot_%d colours=%d edges=%.1f black=%.2f white=%.2f (floor %d / %.0f)'
          % ('PASS' if ok else 'FAIL', n, c, e, b, w, S.MIN_CTRL_COLOURS, S.MIN_CTRL_EDGES))
    return 0 if ok else 1

def regress(tag, idx, ref):
    p = os.path.join(S.BANK, tag, 'shot_%d.png' % idx)
    if not os.path.exists(p):
        print('PIX-REGRESS NO-FRAME (%s missing)' % p); return 2
    if not os.path.exists(ref):
        os.makedirs(os.path.dirname(ref), exist_ok=True); shutil.copyfile(p, ref)
        print('PIX-REGRESS BANKED shot_%d -> %s (no reference existed; the next run compares)' % (idx, ref)); return 0
    a = np.asarray(Image.open(p).convert('RGB'), dtype=np.int16)
    r = np.asarray(Image.open(ref).convert('RGB'), dtype=np.int16)
    if a.shape != r.shape:
        print('PIX-REGRESS FAIL shape %s vs reference %s' % (a.shape, r.shape)); return 1
    diff = (np.abs(a - r) > 40).any(axis=2).mean()
    ok = diff < TOL
    print('PIX-REGRESS %s shot_%d vs %s: %.2f%% of pixels differ by >40 (tolerance %.0f%%)'
          % ('PASS' if ok else 'FAIL', idx, os.path.basename(ref), diff * 100, TOL * 100))
    return 0 if ok else 1

if __name__ == '__main__':
    if len(sys.argv) >= 4 and sys.argv[1] == 'richness': sys.exit(richness(sys.argv[2], int(sys.argv[3])))
    if len(sys.argv) >= 5 and sys.argv[1] == 'regress': sys.exit(regress(sys.argv[2], int(sys.argv[3]), sys.argv[4]))
    print(__doc__); sys.exit(2)
