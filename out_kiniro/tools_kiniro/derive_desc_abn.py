#!/usr/bin/env python3
"""derive_desc_abn.py - kiniro_abnormal's FutariModuleDesc .data candidates from kiniro_normal's, by TWIN VOTE.

kiniro_abnormal's code is kiniro_normal's +8 above the split (PLAN_kiniro_bringup section 4), but its .data moves
PIECEWISE (+0x100 dominant, +0xF0 in a sub-range, -0x28 in .rdata), so no single dshift derives the descriptor.
This walks every kiniro_normal function whose +8-law twin exists in kiniro_abnormal, finds each lis-tracked D-form
reference to one of the kiniro_normal CANDIDATE addresses (host/futari_module_desc.h g_futari_desc_kiniro_normal,
plus START EXCH and the nav set), and takes the address the twin names at the same instruction index as a vote.
Same machinery as derive_desc.py (refs/translate), different source and target.

Positive control (--control): the same walk reco_normal -> reco_abnormal with the +8 law of THAT pair (split
0x880DEF88 / 0x880DF080) must reproduce the +0x60 law for every address >= 0x88351830.

    python3 out_kiniro/tools_kiniro/derive_desc_abn.py [--imgdir _local/kiniro/img] [--control]
"""
import os, sys, collections
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import gen_symbol_map as G
import derive_desc as D
REPO = G.REPO

KIN_TARGETS = [  # (name, kiniro_normal CANDIDATE)   -- g_futari_desc_kiniro_normal + START + nav (all UNVERIFIED/partly controlled)
    ('field_active', 0x885B7838), ('gm_frame_gate', 0x887A2770), ('asset_commit', 0x887A278B),
    ('mb_reload', 0x887A33B4), ('mb_credited', 0x887A336F), ('mb_mode64', 0x887A33AC),
    ('start.exch', 0x8868F6AC), ('start.cb_slot', 0x887A33D0),
]
RECO_TARGETS = D.TARGETS

def main():
    imgdir = G.arg('--imgdir', os.path.join(REPO, '_local', 'kiniro', 'img'))
    control = '--control' in sys.argv
    if control:
        sname, sdir, tname, tdir, lo, hi, targets = 'reco_normal', 'out_reco', 'reco_abnormal', 'out_reco_abn', 0x880DEF88, 0x880DF080, RECO_TARGETS
    else:
        sname, sdir, tname, tdir, lo, hi, targets = 'kiniro_normal', 'out_kiniro', 'kiniro_abnormal', 'out_kiniro_abn', 0x880E1B68, 0x880E1C60, KIN_TARGETS
    src = G.Tree(os.path.join(imgdir, sname + '.img.bin'), os.path.join(REPO, sdir, 'ppc_func_mapping.cpp'), os.path.join(REPO, sdir, 'ppc_config.h'))
    dst = G.Tree(os.path.join(imgdir, tname + '.img.bin'), os.path.join(REPO, tdir, 'ppc_func_mapping.cpp'), os.path.join(REPO, tdir, 'ppc_config.h'))
    dstarts = set(dst.starts)
    uniq = {}
    for s in src.starts:
        t = s if s <= lo else (s + 8 if s >= hi else None)
        if t is not None and t in dstarts: uniq[s] = t
    print('== %s -> %s: %d/%d function starts paired by the +8 law' % (sname, tname, len(uniq), len(src.starts)))
    D.TARGETS = targets
    votes = D.translate(src, dst, uniq)
    bad = 0
    for name, a in targets:
        v = votes[a].most_common(4); tot = sum(votes[a].values())
        if not v: print('  %-15s 0x%08X -> NO REFERENCING TWIN' % (name, a)); continue
        best = v[0][0]
        line = '  %-15s 0x%08X -> 0x%08X (%+#x) %d/%d' % (name, a, best, best - a, v[0][1], tot)
        if len(v) > 1: line += '  others: ' + ', '.join('0x%08X x%d' % kv for kv in v[1:])
        if control:
            exp = a + 0x60 if a >= 0x88351830 else a
            ok = best == exp; bad += 0 if ok else 1; line += '  [control %s]' % ('OK' if ok else 'DISAGREE, law 0x%08X' % exp)
        print(line)
    if control: print('CONTROL: %d disagreement(s) with the +0x60 law' % bad); return 1 if bad else 0
    return 0

if __name__ == '__main__':
    sys.exit(main())
