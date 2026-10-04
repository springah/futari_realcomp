#!/usr/bin/env python3
"""boss_plate_gate.py -- the BOSS PLATE GATE scorer (PLAN_after_boss1_0920.md Phase 1 item 2).

A content-specific plate for game-side promotions: the stage-1 boss's front-on head, the thing the
09-06..10-04 defect broke (inside-out head: two face-mosaic halves 9 px out / 40 px up, invisible to
the early-stage pixel gate).  Two independent witnesses, scored over a boss1_drive_mac.sh bank
(_local/boss1_mac/<tag>/{png/nvk_f<N>.png, guest.log}):

  1. PIXEL PLATE -- the head is a MIRRORED TWIN by construction (two halves, same tiles, one V-flipped),
     so a correct head is left/right symmetric and the broken one is not.  Per dump frame: detect the
     boss head (skin-coloured fraction of the 480..820 x 100..420 box >= RED_MIN), then the best
     mirror-symmetry score of a 220-px-wide band about any axis in 540..740 (1 - mean|L - mirror(R)|/255).
     Summary = the 90th percentile over boss frames (the straight-ahead frames are the top of the
     distribution; side poses and shot flashes fill the bottom in BOTH arms).  Calibrated 2026-10-04 on
     the banked Mac arms: six correct arms p90 0.908..0.924 / skin median 0.27..0.28; eight broken arms
     p90 0.864..0.888 / skin 0.16..0.23.  Verdict is RELATIVE to the control arm run in the same session
     (pilot_p90 >= control_p90 - SYM_MARGIN and pilot_skin >= control_skin - SKIN_MARGIN), never an
     absolute number -- LAWS G1/G2 (arm-symmetric, same route, same levers).

  2. STRUCTURAL PLATE -- the per-push signature from the harness levers RT_EMITTRACE=lr:<lo>-<hi> and
     RT_DCD70TRACE=1 (merged_game.cpp wrappers on sub_881538C0 / sub_880DCD70; the method that NAMED the
     10-04 culprit).  Every logged push is keyed by (caller lr, sprite id, dx, dy, prio, uv, wh) with
     dx/dy RELATIVE to the frame's anchor push (the id-20649 head push), so boss position cancels and
     frames need no alignment between arms; dcd70 calls are keyed (lr, desc, dx, dy, mirror) the same
     way, in EXACT 16.16 units.  Frames are compared pairwise by index only while both arms are in
     LOCKSTEP (anchor at the identical 16.16 position): the offsets carry continuous animation terms,
     so two arms on different game frames differ for reasons that are not the TU's.  Needs both arms
     driven with the levers set and an input-free boss intro (boss_plate_gate.sh: QUIET=10); with
     < 8 lockstep frames the witness is NO-VERDICT and the gate cannot PASS.

Usage:
  boss_plate_gate.py score <tag> [<tag>...]            per-run numbers (banks under _local/boss1_mac)
  boss_plate_gate.py compare <pilot_tag> <control_tag> the gate: writes _local/boss1_mac/<pilot>/plate_verdict.txt
  boss_plate_gate.py --selftest                        LAWS M4 controls on the banked 10-03/10-04 arms

Verdicts: PASS | FAIL | NO-VERDICT (too few boss frames in an arm, or the control arm itself does not
show a credible head -- a control that is not right proves nothing, same rule as stagepix).
"""
import os, re, sys, collections
import numpy as np
from PIL import Image

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
BANK = os.path.join(ROOT, '_local', 'boss1_mac')
X0, X1, Y0, Y1 = 480, 820, 100, 420        # head search box, 1280x720 dump
HW = 110                                   # half-width of the symmetry band
AXES = range(540, 741, 4)
RED_MIN = 0.12                             # skin fraction that says "the head is in the box"
MIN_BOSS_FRAMES = 20
SYM_MARGIN = 0.012                         # pilot may trail control by this much (gap between classes is 0.020)
SKIN_MARGIN = 0.04
CONTROL_MIN_SYM = 0.890                    # below this the control arm is not showing a credible head

EMIT = re.compile(r'\[emittrace\] lr=([0-9A-F]+) id=(\d+) x=([0-9A-F]+) y=([0-9A-F]+) prio=(\d+) rec=[0-9A-F]+ attr=[0-9A-F]+ tl=\([0-9A-F]+,[0-9A-F]+\) c=\([0-9A-F]+,[0-9A-F]+\) uv=\((\d+),(\d+)\) wh=\((\d+),(\d+)\)')
DCD = re.compile(r'\[dcd70\] lr=([0-9A-F]+) desc=([0-9A-F]+) x=([0-9A-F]+) y=([0-9A-F]+) prio=(\d+) mirror=(\d+)')
ANCHOR_ID = 20649


# ----------------------------------------------------------------- pixel plate
def load(p):
    return np.asarray(Image.open(p).convert('RGB'), dtype=np.int16)


def skin_fraction(im):
    b = im[Y0:Y1, X0:X1]
    r, g, bl = b[..., 0], b[..., 1], b[..., 2]
    return float(((r > 120) & (r > g * 1.3) & (r > bl * 1.4)).mean())


def symmetry(im):
    best = (0.0, 0)
    for a in AXES:
        L = im[Y0:Y1, a - HW:a].astype(np.float32)
        R = im[Y0:Y1, a:a + HW][:, ::-1].astype(np.float32)
        s = 1.0 - float(np.abs(L - R).mean()) / 255.0
        if s > best[0]:
            best = (s, a)
    return best


def pixel_score(tag):
    d = os.path.join(BANK, tag, 'png')
    frames = sorted(int(m.group(1)) for f in os.listdir(d) for m in [re.match(r'nvk_f(\d+)\.png$', f)] if m)
    rows = []
    for f in frames:
        im = load(os.path.join(d, 'nvk_f%d.png' % f))
        sk = skin_fraction(im)
        if sk >= RED_MIN:
            s, a = symmetry(im)
            rows.append((f, sk, s, a))
    out = {'frames': len(frames), 'boss': len(rows), 'rows': rows}
    if rows:
        ss = np.array([r[2] for r in rows]); sk = np.array([r[1] for r in rows])
        out.update(skin=float(np.median(sk)), p50=float(np.median(ss)), p75=float(np.percentile(ss, 75)),
                   p90=float(np.percentile(ss, 90)), max=float(ss.max()), first=rows[0][0], last=rows[-1][0])
    return out


# ------------------------------------------------------------ structural plate
def frames(tag):
    """-> list of frames; each = {'anchor': (lr, x16, y16), 'emit': Counter, 'dcd': Counter} with keys RELATIVE to
    the anchor push in EXACT 16.16 units (the boss's own fractional position cancels; floors would not)."""
    path = os.path.join(BANK, tag, 'guest.log')
    out = []; cur = None
    if not os.path.exists(path):
        return out
    for line in open(path, errors='replace'):
        m = EMIT.search(line)
        if m:
            lr, id_, x, y, prio, u, v, w, h = m.groups()
            id_ = int(id_); x = int(x, 16); y = int(y, 16)
            if id_ == ANCHOR_ID and (cur is None or cur['anchor'][0] == lr):
                cur = {'anchor': (lr, x, y), 'emit': collections.Counter(), 'dcd': collections.Counter()}; out.append(cur)
            if cur is None:
                continue
            cur['emit'][(lr, id_, x - cur['anchor'][1], y - cur['anchor'][2], int(prio), int(u), int(v), int(w), int(h))] += 1
            continue
        m = DCD.search(line)
        if m and cur is not None:
            lr, desc, x, y, prio, mirror = m.groups()
            cur['dcd'][(lr, desc, int(x, 16) - cur['anchor'][1], int(y, 16) - cur['anchor'][2], int(prio), int(mirror))] += 1
    # The emittrace wrapper stops at its line cap (3000) mid-frame, while dcd70 (cap 600) keeps logging into later
    # frames whose anchor push was never seen -- everything after the last anchor is a PARTIAL frame keyed to a stale
    # anchor.  Drop it: only frames closed by a following anchor are compared (plate_v3 f12: 260 spurious rows a side).
    return out[:-1]


MIN_LOCKSTEP = 8      # traced frames whose anchor matches EXACTLY in both arms before a structural verdict


def structural(pilot, control):
    """-> (status, lines, diffs).  status: 'identical' | 'differ' | 'nolock' | 'none'.
    Frames are compared pairwise by index ONLY while both arms' anchor pushes sit at the same 16.16 position
    (lockstep); the head's relative offsets carry continuous animation terms, so two arms on different game
    frames differ for reasons that are not the TU's.  The first non-lockstep frame ends the comparison."""
    P, C = frames(pilot), frames(control)
    if not P or not C:
        return 'none', ['   structural: n/a (emittrace frames pilot=%d control=%d -- run both arms under RT_EMITTRACE=lr:<lo>-<hi> RT_DCD70TRACE=1)' % (len(P), len(C))], []
    lock = 0
    for p, c in zip(P, C):
        if p['anchor'][1:] != c['anchor'][1:]:
            break
        lock += 1
    n = min(len(P), len(C))
    # When the arms diverge at frame k, the game state already forked INSIDE frame k-1 (its anchor still
    # matches, its pushes do not: plate_final 10-05, 202 rows all in the last lockstep frame). Only frames
    # strictly before that are evidence about the TU.
    cmp_n = lock if lock == n else max(0, lock - 1)
    diffs = []            # (frame, side, kind, key, count)
    for i in range(cmp_n):
        for kind in ('emit', 'dcd'):
            a, b = P[i][kind], C[i][kind]
            for k in (a - b): diffs.append((i, 'pilot-only', kind, k, (a - b)[k]))
            for k in (b - a): diffs.append((i, 'control-only', kind, k, (b - a)[k]))
    lines = ['   structural: traced frames pilot=%d control=%d, lockstep=%d (anchor identical to the 16.16 bit)%s' % (
        len(P), len(C), lock, '' if lock == n else ' -- arms diverge at frame %d: boss y %.2f vs %.2f (drive nondeterminism, not the TU; rerun with QUIET)' % (
            lock, P[lock]['anchor'][2] / 65536.0, C[lock]['anchor'][2] / 65536.0))]
    if cmp_n < MIN_LOCKSTEP:
        return 'nolock', lines, diffs
    if not diffs:
        lines.append('   structural: IDENTICAL push sets over %d compared frames (%d emit + %d dcd70 keys)' % (
            cmp_n, sum(len(f['emit']) for f in P[:cmp_n]), sum(len(f['dcd']) for f in P[:cmp_n])))
        return 'identical', lines, diffs
    byframe = collections.Counter((i, side) for i, side, kind, k, c in diffs)
    lines.append('   structural: %d differing push rows over %d compared frames: %s' % (
        len(diffs), cmp_n, ' '.join('f%d:%s=%d' % (i, side[0], c) for (i, side), c in sorted(byframe.items()))))
    shown = collections.Counter()
    for i, side, kind, k, c in diffs:
        if shown[(side, kind)] >= 6:
            continue
        shown[(side, kind)] += 1
        lines.append('      f%02d %-12s x%-3d %s' % (i, side, c, fmt_key(k, kind)))
    return 'differ', lines, diffs


def fmt_key(k, kind):
    if kind == 'emit':
        lr, id_, dx, dy, prio, u, v, w, h = k
        return 'emit lr=%s id=%d d=(%+.2f,%+.2f) prio=%d uv=(%d,%d) wh=(%dx%d)' % (lr, id_, dx / 65536.0, dy / 65536.0, prio, u, v, w, h)
    lr, desc, dx, dy, prio, mirror = k
    return 'dcd70 lr=%s desc=%s d=(%+.2f,%+.2f) prio=%d mirror=%d' % (lr, desc, dx / 65536.0, dy / 65536.0, prio, mirror)


# ----------------------------------------------------------------------- gate
def compare(pilot, control, quiet=False):
    P, C = pixel_score(pilot), pixel_score(control)
    lines = ['== boss plate gate: pilot=%s control=%s' % (pilot, control)]
    for name, S in (('pilot', P), ('control', C)):
        if S['boss']:
            lines.append('   %-8s frames=%d boss=%d skin=%.2f sym p50=%.3f p75=%.3f p90=%.3f max=%.3f (f%d..f%d)' % (
                name, S['frames'], S['boss'], S['skin'], S['p50'], S['p75'], S['p90'], S['max'], S['first'], S['last']))
        else:
            lines.append('   %-8s frames=%d boss=0' % (name, S['frames']))
    verdict = 'PASS'; reasons = []
    if P['boss'] < MIN_BOSS_FRAMES or C['boss'] < MIN_BOSS_FRAMES:
        verdict = 'NO-VERDICT'; reasons.append('too few boss frames (pilot %d, control %d, need %d): the route did not reach or hold the boss' % (P['boss'], C['boss'], MIN_BOSS_FRAMES))
    elif C['p90'] < CONTROL_MIN_SYM:
        verdict = 'NO-VERDICT'; reasons.append('control arm p90 %.3f < %.3f: the control does not show a credible head, nothing to compare against' % (C['p90'], CONTROL_MIN_SYM))
    else:
        if P['p90'] < C['p90'] - SYM_MARGIN:
            verdict = 'FAIL'; reasons.append('PIXEL: head symmetry p90 pilot %.3f < control %.3f - %.3f' % (P['p90'], C['p90'], SYM_MARGIN))
        if P['skin'] < C['skin'] - SKIN_MARGIN:
            verdict = 'FAIL'; reasons.append('PIXEL: head skin coverage pilot %.2f < control %.2f - %.2f (halves displaced out of the box)' % (P['skin'], C['skin'], SKIN_MARGIN))
    # structural
    st, slines, diffs = structural(pilot, control)
    lines.extend(slines)
    if st == 'none' or st == 'nolock':
        if verdict == 'PASS':
            verdict = 'NO-VERDICT'
            reasons.append('structural witness %s: a plate PASS needs both witnesses' % ('missing' if st == 'none' else 'has < %d lockstep frames' % MIN_LOCKSTEP))
    elif st == 'differ':
        if verdict != 'NO-VERDICT':
            verdict = 'FAIL'
        reasons.append('STRUCTURAL: %d push rows differ between the arms on lockstep frames (listed above)' % len(diffs))
    lines.append('VERDICT %s%s' % (verdict, (' -- ' + '; '.join(reasons)) if reasons else ' (pixel plate within margin; structural identical)'))
    text = '\n'.join(lines)
    if not quiet:
        print(text)
    try:
        open(os.path.join(BANK, pilot, 'plate_verdict.txt'), 'w').write(text + '\n')
    except OSError:
        pass
    return verdict, P, C, reasons


# ------------------------------------------------------------------- selftest
RIGHT = ['fixed', 'ko_objaction_queue', 'ko_allgame', 'trace_gen', 'dcd_gen', 'dcd_read']
WRONG = ['pilot', 'trace2', 'ko_famk2', 'ko_page_bake', 'ko_bossvein_object', 'ko_actor3pose_draw',
         'ko_asset_decode', 'ko_asset_upload']
# ko_nvk_game_hooks is excluded on purpose: knocking out the renderer bridge changes what the dump IS
# (skin median 0.54, 120 "boss" frames from f1560) -- not a head defect, a different instrument.


def selftest():
    """LAWS M4: the pixel plate must PASS every banked correct arm against `fixed` and FAIL every banked
    broken arm (the 10-03/10-04 lane's knock-outs, all user-eyes-confirmed inside-out heads).  These banks
    carry no wide-window emittrace, so the structural witness is n/a here; the end-to-end structural
    control is boss_plate_gate.sh NEGCTL=1 (the pre-fix objaction_queue TU rebuilt from git)."""
    ok = True
    avail = lambda t: os.path.isdir(os.path.join(BANK, t, 'png'))
    for group, want in (('RIGHT', 'pass'), ('WRONG', 'fail')):
        for t in (RIGHT if group == 'RIGHT' else WRONG):
            if not avail(t):
                print('   skip  %-20s (not banked here)' % t); continue
            v, P, C, reasons = compare(t, 'fixed', quiet=True)
            pixel_ok = not any(r.startswith('PIXEL') for r in reasons)
            good = pixel_ok if want == 'pass' else not pixel_ok
            print('   %s  %-20s %s  p90 %.3f vs control %.3f  skin %.2f vs %.2f  boss=%d' % (
                'pass' if good else 'FAIL', t, 'pixel ' + ('within margin' if pixel_ok else 'FAILS'), P['p90'], C['p90'], P['skin'], C['skin'], P['boss']))
            ok &= good
    # STRUCTURAL controls (banked 10-04 gate runs, drives under the levers):
    #   plate_v1  = the TU BEFORE the arm3 fix vs the generated body, 13 lockstep frames -> must report 'differ'
    #               with the +9/+5 px rows on frames 3..11 (the sel==3 mirrored pose) and NOTHING on frames 0..2;
    #   plate_v2  = two arms whose boss paths diverged at frame 2 (shots a frame apart) -> must report 'nolock',
    #               never 'differ' (a misaligned comparison is not a FAIL).
    for tag, want, check in (('plate_v1', 'differ', lambda d: len(d) > 2000 and all(i >= 3 for i, *_ in d)),
                             ('plate_v2', 'nolock', lambda d: True)):
        if not os.path.exists(os.path.join(BANK, tag + '_pilot', 'guest.log')):
            print('   skip  %-20s (not banked here)' % tag); continue
        st, lines, diffs = structural(tag + '_pilot', tag + '_control')
        good = (st == want) and check(diffs)
        print('   %s  %-20s structural=%s rows=%d  (want %s)' % ('pass' if good else 'FAIL', tag, st, len(diffs), want))
        ok &= good
    print('SELFTEST %s' % ('PASS' if ok else 'FAIL'))
    return 0 if ok else 1


def main(argv):
    if not argv:
        sys.exit(__doc__)
    if argv[0] == '--selftest':
        return selftest()
    if argv[0] == 'score':
        for t in argv[1:]:
            S = pixel_score(t); F = frames(t); nf = len(F); ne = sum(sum(f['emit'].values()) for f in F); nd = sum(sum(f['dcd'].values()) for f in F); e = set().union(*[set(f['emit']) for f in F]) if F else set()
            if S['boss']:
                print('%-22s frames=%d boss=%d skin=%.2f sym p50=%.3f p75=%.3f p90=%.3f max=%.3f  f%d..f%d | emit frames=%d pushes=%d keys=%d dcd70=%d' % (
                    t, S['frames'], S['boss'], S['skin'], S['p50'], S['p75'], S['p90'], S['max'], S['first'], S['last'], nf, ne, len(e), nd))
            else:
                print('%-22s frames=%d boss=0' % (t, S['frames']))
        return 0
    if argv[0] == 'compare' and len(argv) == 3:
        v, _p, _c, _r = compare(argv[1], argv[2])
        return 0 if v == 'PASS' else (2 if v == 'NO-VERDICT' else 1)
    sys.exit(__doc__)


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
