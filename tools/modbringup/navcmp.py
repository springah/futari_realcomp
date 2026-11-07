#!/usr/bin/env python3
"""navcmp.py CTRL_LOG LOG... -- compare the RT_NAVMOD edge sequence and the RT_DESCPROBE slow-field edges of each module
drive against the reco control (step-3c method). Per field the sequence of distinct values is compared; times are shown."""
import re, sys
def nav(path):
    rows = []
    for l in open(path, errors='replace'):
        m = re.match(r'\[navmod\] (\S+) pump#\d+ t\+(\d+)ms scene=(\d+) d76a=(\d+) d76b=(\d+) death=(\d+) slot0=(\d+) cred=(\d+)', l)
        if m: rows.append((m.group(1), int(m.group(2)) / 1000.0) + tuple(int(x) for x in m.groups()[2:]))
    return rows
def desc(path):
    rows = []
    for l in open(path, errors='replace'):
        m = re.match(r'\[descprobe\] (\S+) pump#\d+ t\+(\d+)ms field_active=(\d+) asset_commit=0x([0-9A-F]+) mb_reload=(\d+) mb_credited=(\d+) mb_mode64=0x([0-9A-F]+)', l)
        if m: rows.append((int(m.group(2)) / 1000.0, int(m.group(3)), int(m.group(4), 16), int(m.group(5)), int(m.group(6)), int(m.group(7), 16)))
        m = re.match(r'\[descprobe\] (\S+) pump#\d+ t\+(\d+)ms gm_gate=(\d+) toggles=(\d+)', l)
        if m: rows.append(('gm', int(m.group(2)) / 1000.0, int(m.group(4))))
    return rows
def seq(vals):
    out = []
    for v in vals:
        if not out or out[-1] != v: out.append(v)
    return out
names = ['scene', 'd76a', 'd76b', 'death', 'slot0', 'cred']
ref = None
for p in sys.argv[1:]:
    r = nav(p)
    if not r: print('%s: no [navmod] lines' % p); continue
    mod = r[0][0]
    fs = {n: seq([x[2 + i] for x in r]) for i, n in enumerate(names)}
    full = seq([tuple(x[2:]) for x in r])
    print('== %s (%s): %d edges' % (mod, p.split('/')[-2], len(full)))
    for n in names: print('   %-6s %s%s' % (n, fs[n], '' if ref is None else ('   SAME as control' if fs[n] == ref[n] else '   ** DIFFERS **')))
    s2 = [x[1] for x in r if x[2] == 2 and x[1] > 5]
    print('   scene=2 (teardown) first at t+%s s' % (('%.1f' % s2[0]) if s2 else '-'))
    d = desc(p)
    sl = [x for x in d if x[0] != 'gm']
    for i, n in enumerate(['field_active', 'asset_commit', 'mb_reload', 'mb_credited', 'mb_mode64']):
        print('   %-12s %s' % (n, seq([x[1 + i] for x in sl])))
    gm = [x for x in d if x[0] == 'gm']
    if gm: print('   gm_frame_gate toggles: max %d (last sample t+%.0f s)' % (max(x[2] for x in gm), gm[-1][1]))
    if ref is None: ref = fs
