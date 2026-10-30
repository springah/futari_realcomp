#!/usr/bin/env python3
"""derive_desc.py - STRUCTURAL CANDIDATES for kiniro_normal's FutariModuleDesc (Black Label step 4a).

Nothing here is proven at runtime.  It produces the values host/futari_module_desc.h carries for
kiniro_normal, every one marked UNVERIFIED there, plus the evidence for docs/PLAN_kiniro_bringup.md.

1. XEX headers (read straight from the .xex; the header block is plaintext):
     entry point  = optional header 0x00010100                         -> descriptor `xstart`
     GameEntry    = export ordinal 1 through the security info's export table (+0x160 -> a guest
                    address inside the image: ordOffset[1-base] + (imagebaseaddr << 16), the same
                    walk Xenia's XexModule::GetProcAddress does)          -> `entry_ord1`
   Positive control: reco_normal must give 0x88070588 / 0x8824E698 and reco_abnormal 0x8824E6A0,
   the values the descriptor has carried since L3.
2. .data addresses by TWIN: every reco_normal function that names a reco address through a
   lis-tracked D-form (lis rX,hi; addi/lwz/stb... d(rX)) and has a UNIQUE whole-body twin in
   kiniro_normal (gen_symbol_map.py's matcher) votes for the address the twin names at the same
   instruction index.  Positive control: the same walk onto reco_abnormal must give the +0x60 law
   for every address >= 0x88351830 (and +0 below), i.e. the abn descriptor.

usage:  python3 out_kiniro/tools_kiniro/derive_desc.py [--imgdir _local/kiniro/img] [--xexdir assets/media/Module]
"""
import os, sys, struct, collections
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import gen_symbol_map as G
REPO = G.REPO

TARGETS = [  # (name, reco_normal address)  -- the 6 FutariModuleAddrs, the nav observer set, START
    ('field_active', 0x885C1A20), ('gm_frame_gate', 0x887AC958), ('asset_commit', 0x887AC973),
    ('mb_reload', 0x887AD58C), ('mb_credited', 0x887AD547), ('mb_mode64', 0x887AD584),
    ('nav.scene_fsm', 0x884D66A8), ('nav.select_d76', 0x884D678C), ('nav.death', 0x884D6878),
    ('nav.slot0', 0x884D6CE8), ('nav.credit', 0x884D6CEA),
    ('start.exch', 0x88699894), ('start.cb_slot', 0x887AD5A8),
]


def xex_info(path, img):
    b = open(path, 'rb').read()
    assert b[:4] == b'XEX2', path
    sec_off, nhdr = struct.unpack('>II', b[0x10:0x18])
    entry = None
    for i in range(nhdr):
        k, v = struct.unpack('>II', b[0x18 + 8 * i:0x20 + 8 * i])
        if k == 0x00010100: entry = v
    exp = struct.unpack('>I', b[sec_off + 0x160:sec_off + 0x164])[0]
    ord1 = None
    if exp and G.BASE <= exp < G.BASE + len(img.b):
        imgbase, count, base = img.w(exp + 0x20), img.w(exp + 0x24), img.w(exp + 0x28)
        if 0 <= 1 - base < count:
            ord1 = (img.w(exp + 0x2C + 4 * (1 - base)) + (imgbase << 16)) & 0xFFFFFFFF
    return entry, exp, ord1


def refs(t, s):
    """[(insn index, effective address)] of lis-tracked D-form references in function s."""
    reg, out = {}, []
    for k in range(t.ext[s] // 4):
        x = t.w(s + 4 * k); op = x >> 26; rt = (x >> 21) & 31; ra = (x >> 16) & 31
        si = x & 0xFFFF; si = si - 0x10000 if si & 0x8000 else si
        if op == 15 and ra == 0: reg[rt] = (si << 16) & 0xFFFFFFFF; continue
        if op == 14 and ra != 0 and ra in reg:
            ea = (reg[ra] + si) & 0xFFFFFFFF; out.append((k, ea)); reg[rt] = ea; continue
        if 32 <= op <= 55 and ra != 0 and ra in reg:
            out.append((k, (reg[ra] + si) & 0xFFFFFFFF))
            if op in (32, 33, 34, 35, 40, 41, 42, 43, 46): reg.pop(rt, None)   # integer loads write rt
            if op in (33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55): reg.pop(ra, None)   # update forms
            continue
        if op == 18 or op == 16 or op == 19: reg.clear(); continue        # control flow: forget
        if op in (7, 8, 12, 13, 14, 15): reg.pop(rt, None)                  # li/addis/mulli/subfic/addic: rt
        elif op in (20, 21, 23, 24, 25, 26, 27, 28, 29, 30): reg.pop(ra, None)   # rlw*/ori/xori/andi/rld*: ra
        elif op == 31: reg.pop(rt, None); reg.pop(ra, None)                 # X-form: either, conservatively
    return out


def translate(src, dst, uniq):
    want = {a for _, a in TARGETS}
    votes = {a: collections.Counter() for a in want}
    for s, t in uniq.items():
        rs = [(k, ea) for k, ea in refs(src, s) if ea in want]
        if not rs: continue
        rd = dict(refs(dst, t))
        for k, ea in rs:
            if k in rd: votes[ea][rd[k]] += 1
    return votes


def main():
    imgdir = G.arg('--imgdir', os.path.join(REPO, '_local', 'kiniro', 'img'))
    xexdir = G.arg('--xexdir', os.path.join(REPO, 'assets', 'media', 'Module'))
    trees = {}
    for m, d in (('reco_normal', 'out_reco'), ('reco_abnormal', 'out_reco_abn'), ('kiniro_normal', 'out_kiniro')):
        trees[m] = G.Tree(os.path.join(imgdir, m + '.img.bin'), os.path.join(REPO, d, 'ppc_func_mapping.cpp'),
                          os.path.join(REPO, d, 'ppc_config.h'))
    print('== 1. XEX headers (control: reco_normal 0x88070588/0x8824E698, reco_abnormal ord1 0x8824E6A0)')
    for m in trees:
        e, x, o = xex_info(os.path.join(xexdir, m + '.xex'), trees[m])
        print('  %-14s entry=0x%08X  export_table=0x%08X  ordinal1=%s' % (m, e or 0, x, ('0x%08X' % o) if o else 'NOT IN IMAGE'))
    src = trees['reco_normal']
    for m in ('reco_abnormal', 'kiniro_normal'):
        dst = trees[m]
        idx = collections.defaultdict(list)
        for s in dst.starts: idx[(dst.ext[s], dst.body(s))].append(s)
        uniq = {}
        for s in src.starts:
            c = idx.get((src.ext[s], src.body(s)))
            if c and len(c) == 1: uniq[s] = c[0]
        rev = collections.Counter(uniq.values()); uniq = {s: t for s, t in uniq.items() if rev[t] == 1}
        votes = translate(src, dst, uniq)
        print('== 2. .data by twin: reco_normal -> %s (%d unique twins)%s' % (m, len(uniq),
              '  [control: +0x60 at/above 0x88351830]' if m == 'reco_abnormal' else ''))
        for name, a in TARGETS:
            v = votes[a].most_common(4)
            tot = sum(votes[a].values())
            best = ('0x%08X (%+#x) %d/%d' % (v[0][0], v[0][0] - a, v[0][1], tot)) if v else 'NO REFERENCING TWIN'
            rest = '  others: ' + ', '.join('0x%08X x%d' % kv for kv in v[1:]) if len(v) > 1 else ''
            print('  %-15s 0x%08X -> %s%s' % (name, a, best, rest))


if __name__ == '__main__':
    main()
