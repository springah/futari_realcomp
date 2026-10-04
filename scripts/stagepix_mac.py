#!/usr/bin/env python3
"""stagepix_mac.py -- the STAGE PIXEL GATE (the ladder's stagepix rung), Mac port of the Windows
_local/_tmpscripts/stagepix_{gate.sh,cap.ps1,metric.py} (NOTE_campaign_decomp.md ~8326; never present here).

Scores a stage-1 burst from a nav_mac.sh bank: the RICHNESS of the playfield centre crop, which a
placeholder-black, placeholder-white or half-composed stage cannot fake --
    colours  = distinct 6-bit RGB colours in the crop
    edges    = mean |dI/dx| + |dI/dy| of the luma (texture detail)
    black / white = fraction of near-black / near-white pixels (placeholder creep)
Rules (verbatim from the Windows gate): PASS if pilot >= STAGEPIX_RATIO (0.70) x control on BOTH colours
and edges; a frame >= 97% white is INVALID (the display-off trap) and dropped; a control arm that is not
rich itself (colours < 15000 or edges < 15) is NO-VERDICT -- a control that proves nothing passes nothing.

Usage:  stagepix_mac.py score <tag>              per-frame numbers for _local/nav_mac/<tag>/png
        stagepix_mac.py compare <pilot> <control>  the gate; writes _local/nav_mac/<pilot>/stagepix_verdict.txt
Drive both arms with scripts/stagepix_mac.sh (Normal Play route, NVKPNG=20 burst at the stage).
"""
import os, re, sys
import numpy as np
from PIL import Image

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
BANK = os.path.join(ROOT, '_local', 'nav_mac')
CROP = (440, 120, 850, 620)          # playfield centre (the game screen is 408..880 x 40..680 in the 1280x720 dump)
RATIO = float(os.environ.get('STAGEPIX_RATIO', '0.70'))
MIN_CTRL_COLOURS, MIN_CTRL_EDGES = 15000, 15.0   # a stage reads ~24k / ~29; the Options menus ~10k / ~10 (10-05 sanity)
BURST = int(os.environ.get('STAGEPIX_BURST', '6'))


def metric(path):
    im = np.asarray(Image.open(path).convert('RGB'), dtype=np.int16)
    c = im[CROP[1]:CROP[3], CROP[0]:CROP[2]]
    q = (c >> 2); colours = len(np.unique(q[..., 0] * 4096 + q[..., 1] * 64 + q[..., 2]))
    lum = (c[..., 0] * 299 + c[..., 1] * 587 + c[..., 2] * 114) // 1000
    edges = float(np.abs(np.diff(lum, axis=1)).mean() + np.abs(np.diff(lum, axis=0)).mean())
    mx = c.max(axis=2); mn = c.min(axis=2)
    black = float((mx < 24).mean()); white = float((mn > 231).mean())
    return colours, edges, black, white


def frames(tag):
    d = os.path.join(BANK, tag, 'png')
    fs = sorted(int(m.group(1)) for f in os.listdir(d) for m in [re.match(r'nvk_f(\d+)\.png$', f)] if m)
    return [(f, os.path.join(d, 'nvk_f%d.png' % f)) for f in fs]


def burst(tag):
    """the last BURST valid frames of the bank (the dwell at the stage); INVALID (>=97% white) dropped."""
    rows = []
    for f, p in frames(tag)[-BURST * 3:]:
        col, ed, bl, wh = metric(p)
        rows.append((f, col, ed, bl, wh, wh >= 0.97))
    valid = [r for r in rows if not r[5]][-BURST:]
    return rows, valid


def summarize(valid):
    if not valid: return None
    return dict(colours=float(np.median([r[1] for r in valid])), edges=float(np.median([r[2] for r in valid])),
                black=float(np.median([r[3] for r in valid])), white=float(np.median([r[4] for r in valid])), n=len(valid))


def compare(pilot, control):
    rp, vp = burst(pilot); rc, vc = burst(control)
    P, C = summarize(vp), summarize(vc)
    lines = ['== stagepix gate: pilot=%s control=%s (burst=%d, ratio=%.2f)' % (pilot, control, BURST, RATIO)]
    for name, S, rows in (('pilot', P, rp), ('control', C, rc)):
        inv = sum(1 for r in rows if r[5])
        lines.append('   %-8s %s  invalid(white>=97%%)=%d' % (name, ('n=%d colours=%.0f edges=%.1f black=%.3f white=%.3f' % (S['n'], S['colours'], S['edges'], S['black'], S['white'])) if S else 'NO VALID FRAMES', inv))
    verdict = 'PASS'; why = []
    if not P or not C or P['n'] < 3 or C['n'] < 3:
        verdict = 'NO-VERDICT'; why.append('fewer than 3 valid stage frames in an arm')
    elif C['colours'] < MIN_CTRL_COLOURS or C['edges'] < MIN_CTRL_EDGES:
        verdict = 'NO-VERDICT'; why.append('control arm is not rich (colours %.0f / edges %.1f): nothing to compare against' % (C['colours'], C['edges']))
    else:
        if P['colours'] < RATIO * C['colours']: verdict = 'FAIL'; why.append('colours %.0f < %.2f x %.0f' % (P['colours'], RATIO, C['colours']))
        if P['edges'] < RATIO * C['edges']: verdict = 'FAIL'; why.append('edges %.1f < %.2f x %.1f' % (P['edges'], RATIO, C['edges']))
        if P['black'] > C['black'] + 0.15: verdict = 'FAIL'; why.append('black creep %.2f vs %.2f' % (P['black'], C['black']))
    lines.append('VERDICT %s%s' % (verdict, (' -- ' + '; '.join(why)) if why else ''))
    text = '\n'.join(lines); print(text)
    open(os.path.join(BANK, pilot, 'stagepix_verdict.txt'), 'w').write(text + '\n')
    return 0 if verdict == 'PASS' else (2 if verdict == 'NO-VERDICT' else 1)


if __name__ == '__main__':
    a = sys.argv[1:]
    if a and a[0] == 'score':
        for t in a[1:]:
            for f, col, ed, bl, wh, inv in burst(t)[0]:
                print('%-14s f%-6d colours=%-5d edges=%6.1f black=%.3f white=%.3f%s' % (t, f, col, ed, bl, wh, '  INVALID' if inv else ''))
        sys.exit(0)
    if a and a[0] == 'compare' and len(a) == 3:
        sys.exit(compare(a[1], a[2]))
    sys.exit(__doc__)
