#!/usr/bin/env python3
"""stagepix360.py -- the XBOX 360 MODE stage-pixel gate (RC1 Q7v). The 360 analogue of scripts/stagepix_mac.py.

Banks are nav360_mac.sh banks run with NVKPNG=20 (dumps nvk_f<N>.png + guest.log). The stage-1 window is
read from guest.log: from the '[nav360] D=0x60 st=5 d76=4' entry marker (+ SETTLE frames of fade-in) to the
first in-stage pause marker. The playfield-centre richness metric, the rules (PASS if pilot >= 0.70 x control
on colours AND edges, control must itself be rich) and the INVALID white-frame rule are stagepix_mac.py's, imported.
  stagepix360.py score   <bank_dir>
  stagepix360.py compare <pilot_bank_dir> <control_bank_dir>
"""
import os, re, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import stagepix_mac as S

SETTLE = int(os.environ.get('SP360_SETTLE', '260'))   # frames after entry before scoring (~4 s)
BURST = S.BURST
SPAN = int(os.environ.get('SP360_SPAN', '1000'))   # frames after entry that still count: with no input the ship dies at ~entry+1140 and the CONTINUE? overlay (not stage richness) follows

def window(bank):
    lines = open(os.path.join(bank, 'guest.log'), errors='replace').read().splitlines()
    cur = None; ent = None; pause = None
    for ln in lines:
        m = re.search(r'submit f(\d+)', ln)
        if m: cur = int(m.group(1))
        if ent is None and '[nav360] D=0x60 st=5 d76=4 ' in ln and cur is not None: ent = cur
        if ent is not None and pause is None and 'BA4D8(ACTIVE)' in ln and '0x82061D50->0x82061D50' in ln and cur is not None: pause = cur
    return ent, pause

def frames(bank):
    d = os.path.join(bank, 'png')
    fs = sorted(int(m.group(1)) for f in os.listdir(d) for m in [re.match(r'nvk_f(\d+)\.png$', f)] if m)
    return d, fs

def burst(bank):
    ent, pause = window(bank)
    d, fs = frames(bank)
    if ent is None: return None, [], []
    hi = min(pause, ent + SPAN) if pause else min(fs[-1], ent + SPAN)
    sel = [f for f in fs if ent + SETTLE <= f <= hi]
    rows = []
    for f in sel:
        col, ed, bl, wh = S.metric(os.path.join(d, 'nvk_f%d.png' % f)); rows.append((f, col, ed, bl, wh, wh >= 0.97))
    valid = [r for r in rows if not r[5]][-BURST:]
    return (ent, pause), rows, valid

def compare(pb, cb):
    wp, rp, vp = burst(pb); wc, rc, vc = burst(cb)
    P, C = S.summarize(vp), S.summarize(vc)
    L = ['== stagepix360 gate: pilot=%s control=%s (burst=%d, ratio=%.2f, settle=%d f, span=%d f)' % (pb, cb, BURST, S.RATIO, SETTLE, SPAN)]
    for name, W, S_, rows in (('pilot', wp, P, rp), ('control', wc, C, rc)):
        L.append('   %-8s window(entry,pause)=%s frames-in-window=%d  %s' % (name, W, len(rows),
                 ('n=%d colours=%.0f edges=%.1f black=%.3f white=%.3f' % (S_['n'], S_['colours'], S_['edges'], S_['black'], S_['white'])) if S_ else 'NO VALID FRAMES'))
    v = 'PASS'; why = []
    if not P or not C or P['n'] < 3 or C['n'] < 3: v = 'NO-VERDICT'; why.append('fewer than 3 valid stage frames in an arm')
    elif C['colours'] < S.MIN_CTRL_COLOURS or C['edges'] < S.MIN_CTRL_EDGES: v = 'NO-VERDICT'; why.append('control not rich (colours %.0f / edges %.1f)' % (C['colours'], C['edges']))
    else:
        if P['colours'] < S.RATIO * C['colours']: v = 'FAIL'; why.append('colours')
        if P['edges'] < S.RATIO * C['edges']: v = 'FAIL'; why.append('edges')
        if P['black'] > C['black'] + 0.15: v = 'FAIL'; why.append('black creep')
    L.append('VERDICT %s%s' % (v, (' -- ' + '; '.join(why)) if why else ''))
    if P and C: L.append('   ratio pilot/control: colours %.3f edges %.3f' % (P['colours'] / C['colours'], P['edges'] / C['edges']))
    t = '\n'.join(L); print(t); open(os.path.join(pb, 'stagepix360_verdict.txt'), 'w').write(t + '\n')

if __name__ == '__main__':
    if len(sys.argv) >= 4 and sys.argv[1] == 'compare': compare(sys.argv[2], sys.argv[3])
    elif len(sys.argv) >= 3 and sys.argv[1] == 'score':
        w, rows, valid = burst(sys.argv[2]); print('window', w)
        for r in rows: print('f%d colours=%d edges=%.1f black=%.3f white=%.3f%s' % (r[0], r[1], r[2], r[3], r[4], ' INVALID' if r[5] else ''))
        print(S.summarize(valid))
    else: print(__doc__)
