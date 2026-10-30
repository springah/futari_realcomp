#!/usr/bin/env python3
"""gen_symbol_map.py - emit out_kiniro/kiniro_symbol_map.h + out_kiniro/kiniro_hook_stubs.cpp
(Black Label bring-up step 4a/4b; docs/PLAN_kiniro_bringup.md "Step 4a").

The analogue of out_reco_abn/tools_abn/gen_symbol_map.py for a module that is NOT a twin of
reco_normal.  The host hook layer that rides into a module dylib (out_reco/merged/merged_game.cpp
+ futari_decomp decomp/game/nvk_game_hooks.cpp, the only decomp TU a non-reco module links, w186
LAW 1) names reco_NORMAL guest function symbols.  kiniro_normal is a different game build, so
there is no address law: each referenced symbol is located by BODY in the kiniro image.

  demand side   every sub_88XXXXXX (and paste-macro hex tail) named in the CODE regions of the
                two TUs above (comment/string stripping + regexes reused from abn's generator)
                that is a real reco_normal function start (out_reco/ppc_func_mapping.cpp).
  truth side    a mnemonic matcher over the two flat images (xexflat output): each function's
                extent is [start, next mapping start); each word is normalised by masking the
                16-bit immediate / displacement of D/DS-form ops and the target of b/bc
                (registers and opcodes kept); a word that is an aligned code address (an inline
                jump-table entry) is masked as such.  A reco body matches a kiniro function when the
                normalised sequences are equal over the WHOLE extent of both.
  classes       UNIQUE      exactly one kiniro function has the same body
                TIEBROKEN   several do; exactly one (or one dominant: >= 3 votes, >= 3x the runner-up)
                            gets call-graph votes (a uniquely matched
                            caller's `bl` at the same instruction index lands on it, or its own
                            `bl`s at the same indices land on the twins of the reco callees, or
                            the nearest uniquely matched neighbours' delta lands on it) and no
                            other candidate gets any
                AMBIGUOUS   several, and the tiebreak does not single one out -> dropped
                NOMATCH     none (the code changed) -> dropped
  emitted       UNIQUE/TIEBROKEN with a different address:  #define sub_X sub_Y + the __imp__ form
                UNIQUE/TIEBROKEN at the same address:        nothing
                dropped (AMBIGUOUS/NOMATCH):                 #define sub_X sub_X_KDROP (+ __imp__),
                    so a hook's override lands on a name NOTHING in the kiniro tree references (it
                    can never be installed into PPCFuncMappings, and it can never silently override
                    an unrelated kiniro function that happens to sit at reco's address), and every
                    call into it resolves to a LOUD stub in kiniro_hook_stubs.cpp.
Hard aborts: a target that is not a kiniro function start; two reco symbols onto one kiniro symbol
(two overrides of one name); CHAINED EXPANSION (a target that is itself a renamed key - object-like
macros expand recursively, so the second rename would apply too).

--control maps reco_normal -> reco_abnormal with the same code and checks every UNIQUE/TIEBROKEN
answer against the known +8 split law (addr < 0x880DEF88 -> same, >= 0x880DF080 -> +8).  Writes
nothing.  It must report 0 disagreements before the kiniro run is trusted.

usage (repo root; the images come from out_kiniro/tools_kiniro/xexflat, see regen_kiniro_mac.sh):
    python3 out_kiniro/tools_kiniro/gen_symbol_map.py --imgdir _local/kiniro/img --control
    python3 out_kiniro/tools_kiniro/gen_symbol_map.py --imgdir _local/kiniro/img [--check] [--outdir DIR]
"""
import os, re, sys, struct, bisect, collections

HERE = os.path.dirname(os.path.abspath(__file__))
KIN = os.path.dirname(HERE)
REPO = os.path.dirname(KIN)
sys.path.insert(0, os.path.join(REPO, 'out_reco_abn', 'tools_abn'))
import importlib.util
_spec = importlib.util.spec_from_file_location('abn_gsm', os.path.join(REPO, 'out_reco_abn', 'tools_abn', 'gen_symbol_map.py'))
abn_gsm = importlib.util.module_from_spec(_spec); _spec.loader.exec_module(abn_gsm)   # main() is guarded
code_only, SYM, PASTE = abn_gsm.code_only, abn_gsm.SYM, abn_gsm.PASTE

BASE = 0x88000000
DECOMP = os.environ.get('DECOMP_DIR') or os.path.join(REPO, '..', 'futari_decomp', 'decomp')
SCAN = [os.path.join(REPO, 'out_reco', 'merged', 'merged_game.cpp'),
        os.path.join(DECOMP, 'game', 'nvk_game_hooks.cpp')]


def die(m):
    sys.stderr.write('gen_symbol_map(kiniro): FATAL: %s\n' % m); sys.exit(2)


def arg(flag, default=None):
    if flag in sys.argv:
        return sys.argv[sys.argv.index(flag) + 1]
    return default


class Tree:
    """one recompiled module: flat image + its function starts (ppc_func_mapping.cpp) + code end."""
    def __init__(self, img, mapping, config):
        self.b = open(img, 'rb').read()
        self.starts = sorted(int(h, 16) for h in re.findall(r'\{ 0x([0-9A-Fa-f]{8}), sub_', open(mapping).read()))
        cfg = open(config).read()
        cb = int(re.search(r'PPC_CODE_BASE (0x[0-9A-Fa-f]+)', cfg).group(1), 16)
        cs = int(re.search(r'PPC_CODE_SIZE (0x[0-9A-Fa-f]+)', cfg).group(1), 16)
        self.code_base, self.code_end = cb, cb + cs
        self.set = set(self.starts)
        self.ext = {}
        for i, s in enumerate(self.starts):
            self.ext[s] = (self.starts[i + 1] if i + 1 < len(self.starts) else self.code_end) - s
        self.calls = {}      # start -> [(idx, target)]
        self.callers = collections.defaultdict(list)   # target -> [(caller, idx)]
        for s in self.starts:
            cl = []
            for k in range(self.ext[s] // 4):
                x = self.w(s + 4 * k)
                if x >> 26 == 18:
                    li = x & 0x03FFFFFC
                    if li & 0x02000000: li -= 0x04000000
                    t = (li if x & 2 else s + 4 * k + li) & 0xFFFFFFFF
                    if t in self.set:
                        cl.append((k, t)); self.callers[t].append((s, k))
            self.calls[s] = cl

    def w(self, a):
        o = a - BASE
        return struct.unpack('>I', self.b[o:o + 4])[0]

    def body(self, s):
        # a word that IS an aligned code address is an inline jump-table entry (XenonRecomp emits
        # those tables inside the function extent): it relocates with the layout, so it is masked
        return tuple(('CA' if self.code_base <= x < self.code_end and not x & 3 else norm(x))
                     for x in (self.w(s + 4 * k) for k in range(self.ext[s] // 4)))

    def call_at(self, s, k):
        for kk, t in self.calls.get(s, ()):
            if kk == k: return t
        return None


D_IMM = {2, 3, 7, 8, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29} | set(range(32, 56))


def norm(x):
    op = x >> 26
    if op == 18: return x & 0xFC000003           # b/bl: target masked, AA/LK kept
    if op == 16: return x & 0xFFFF0003           # bc: displacement masked
    if op in (58, 62): return x & 0xFFFF0003     # DS-form ld/std: displacement masked
    if op in D_IMM: return x & 0xFFFF0000        # D-form: immediate/displacement masked
    return x


def match(src, dst, demand):
    """-> {addr: (cls, target or None, candidates, note)} for every demand addr, plus the global
    unique map used for the tiebreak."""
    idx = collections.defaultdict(list)
    for s in dst.starts: idx[(dst.ext[s], dst.body(s))].append(s)
    uniq = {}
    for s in src.starts:
        c = idx.get((src.ext[s], src.body(s)))
        if c and len(c) == 1: uniq[s] = c[0]
    # a kiniro target claimed by two different reco bodies is not unique for either
    rev = collections.Counter(uniq.values())
    uniq = {s: t for s, t in uniq.items() if rev[t] == 1}
    ukeys = sorted(uniq)
    out = {}
    for a in sorted(demand):
        cands = idx.get((src.ext[a], src.body(a)), [])
        if len(cands) == 1 and uniq.get(a) == cands[0]:
            out[a] = ('UNIQUE', cands[0], cands, ''); continue
        if not cands:
            # triage hint only (never emitted): where a uniquely matched caller's bl lands
            hint = collections.Counter()
            for p, k in src.callers.get(a, ()):
                if p in uniq:
                    t = dst.call_at(uniq[p], k)
                    if t is not None: hint[t] += 1
            out[a] = ('NOMATCH', None, [], ('callers point at ' + ', '.join('0x%08X x%d' % kv for kv in hint.most_common(3))) if hint else 'no matched caller'); continue
        votes = collections.Counter()
        why = collections.defaultdict(list)
        for p, k in src.callers.get(a, ()):
            if p in uniq:
                t = dst.call_at(uniq[p], k)
                if t in cands: votes[t] += 1; why[t].append('caller')
        for k, t in src.calls.get(a, ()):
            if t in uniq:
                for c in cands:
                    if dst.call_at(c, k) == uniq[t]: votes[c] += 1; why[c].append('callee')
        i = bisect.bisect_left(ukeys, a)
        for j in (i - 1, i + 1 if i < len(ukeys) and ukeys[i] == a else i):
            if 0 <= j < len(ukeys) and ukeys[j] != a:
                n = ukeys[j]; c = a + (uniq[n] - n)
                if c in cands: votes[c] += 1; why[c].append('neighbour')
        live = sorted((c for c in cands if votes[c] > 0), key=lambda c: -votes[c])
        # winner: the only voted candidate, or a DOMINANT one (>= 3 votes and >= 3x the runner-up;
        # the neighbour vote is coarse and can put one stray vote on a sibling body)
        if live and (len(live) == 1 or (votes[live[0]] >= 3 and votes[live[0]] >= 3 * votes[live[1]])):
            out[a] = ('TIEBROKEN', live[0], cands, '+'.join(sorted(set(why[live[0]]))) + ' x%d' % votes[live[0]]
                      + ('' if len(live) == 1 else ' (runner-up 0x%08X x%d)' % (live[1], votes[live[1]])))
        else:
            out[a] = ('AMBIGUOUS', None, cands, 'votes ' + (', '.join('0x%08X:%d' % (c, votes[c]) for c in cands[:6]) + (' ...' if len(cands) > 6 else '')))
    return out, uniq


def demand_side(src):
    refs = collections.defaultdict(set)
    for f in SCAN:
        code = code_only(open(f, encoding='utf-8', errors='replace').read())
        names = set(SYM.findall(code)) | set('sub_' + h.upper() for h in PASTE.findall(code))
        for n in names:
            a = int(n[4:], 16)
            if a in src.set: refs[a].add(os.path.basename(f))
    if not refs: die('no sub_88 references found in %s' % SCAN)
    return refs


def main():
    imgdir = arg('--imgdir', os.path.join(REPO, '_local', 'kiniro', 'img'))
    control = '--control' in sys.argv
    src = Tree(os.path.join(imgdir, 'reco_normal.img.bin'), os.path.join(REPO, 'out_reco', 'ppc_func_mapping.cpp'),
               os.path.join(REPO, 'out_reco', 'ppc_config.h'))
    tgt_name = 'reco_abnormal' if control else 'kiniro_normal'
    tdir = 'out_reco_abn' if control else 'out_kiniro'
    dst = Tree(os.path.join(imgdir, tgt_name + '.img.bin'), os.path.join(REPO, tdir, 'ppc_func_mapping.cpp'),
               os.path.join(REPO, tdir, 'ppc_config.h'))
    refs = demand_side(src)
    res, uniq = match(src, dst, refs)
    cnt = collections.Counter(v[0] for v in res.values())
    print('%s: %d referenced reco_normal function symbols -> %s' % (tgt_name, len(res), dict(cnt)))
    print('  global unique body matches (all %d reco functions): %d' % (len(src.starts), len(uniq)))

    if control:
        bad = []
        for a, (cls, t, _, _) in res.items():
            if t is None: continue
            exp = a if a < 0x880DEF88 else (None if a < 0x880DF080 else a + 8)
            if exp is not None and t != exp: bad.append((a, t, exp, cls))
        for a, t, e, c in bad: print('  DISAGREE 0x%08X -> 0x%08X (law 0x%08X, %s)' % (a, t, e, c))
        print('CONTROL: %d matched, %d disagreements with the +8 law' % (sum(1 for v in res.values() if v[1] is not None), len(bad)))
        sys.exit(1 if bad else 0)

    shared = open(os.path.join(KIN, 'ppc_recomp_shared.h'), encoding='utf-8').read()
    kin_syms = set(int(h, 16) for h in re.findall(r'PPC_EXTERN_FUNC\(sub_([0-9A-Fa-f]{8})\)', shared))
    renamed, same, dropped = {}, [], []
    for a, (cls, t, c, note) in sorted(res.items()):
        if t is None: dropped.append(a); continue
        if t not in kin_syms: die('target 0x%08X of 0x%08X is not a kiniro function symbol' % (t, a))
        if t == a: same.append(a)
        else: renamed[a] = t
    dup = [t for t, n in collections.Counter(renamed.values()).items() if n > 1]
    dup += [a for a in same if a in renamed.values()]
    if dup: die('two reco symbols onto one kiniro symbol: %s' % ', '.join('0x%08X' % t for t in dup))
    keys = set(renamed) | set(dropped)
    chain = sorted(a for a, t in renamed.items() if t in keys)
    if chain:
        die('CHAINED EXPANSION: %s' % ', '.join('0x%08X->0x%08X' % (a, renamed[a]) for a in chain))

    by = collections.defaultdict(list)
    for a, v in sorted(res.items()): by[v[0]].append(a)
    H = []; w = H.append
    w('// kiniro_symbol_map.h - GENERATED by out_kiniro/tools_kiniro/gen_symbol_map.py.  DO NOT EDIT.')
    w('//')
    w('// Force-included (clang -include) by build_mac_dll.sh\'s kiniro arm ONLY, onto the two host TUs')
    w('// that ride into futari_game_kiniro.dylib and name reco_normal guest function symbols:')
    w('// out_reco/merged/merged_game.cpp and futari_decomp decomp/game/nvk_game_hooks.cpp.  No other')
    w('// build sees it.  Truth = a mnemonic body match reco_normal -> kiniro_normal (see the script).')
    w('// Positive control (--control, reco_normal -> reco_abnormal): 0 disagreements with the +8 law.')
    w('//')
    w('// %d referenced symbols: %d UNIQUE, %d TIEBROKEN, %d AMBIGUOUS, %d NOMATCH.'
      % (len(res), cnt['UNIQUE'], cnt['TIEBROKEN'], cnt['AMBIGUOUS'], cnt['NOMATCH']))
    w('// %d renamed (address differs), %d at the same address (no #define), %d DROPPED -> sub_X_KDROP.'
      % (len(renamed), len(same), len(dropped)))
    w('//')
    w('// DROPPED means: the hook\'s override is renamed onto a name nothing in the kiniro tree references,')
    w('// so it is never installed (and can never override whatever kiniro function sits at the reco')
    w('// address); any call into it reaches out_kiniro/kiniro_hook_stubs.cpp, which is LOUD.  That is the')
    w('// per-module exclusion list: these hooks are OFF in Black Label until someone derives a twin.')
    w('//')
    w('// Note: `#FN` stringification in the wrapper macros is not expanded, so log text keeps the')
    w('// reco_normal symbol name while the kiniro twin executes (same convention as abn_symbol_map.h).')
    w('#pragma once')
    w('#include <cstdint>')
    w('struct PPCContext;')
    w('')
    for cls in ('UNIQUE', 'TIEBROKEN', 'AMBIGUOUS', 'NOMATCH'):
        w('// ---- %s (%d) ----' % (cls, len(by[cls])))
        for a in by[cls]:
            _, t, c, note = res[a]
            src_n = 'sub_%08X' % a
            files = '/'.join(sorted(f.replace('.cpp', '') for f in refs[a]))
            if t is not None and t == a:
                w('//   %s  same address  [%s]%s' % (src_n, files, ('  ' + note) if note else ''))
            elif t is not None:
                dst_n = 'sub_%08X' % t
                w('#define %-20s %-20s // %+#x [%s]%s' % (src_n, dst_n, t - a, files, ('  ' + note) if note else ''))
                w('#define __imp__%-13s __imp__%s' % (src_n, dst_n))
            else:
                dn = src_n + '_KDROP'
                w('#define %-20s %-26s // [%s] %d cand. %s' % (src_n, dn, files, len(c), note))
                w('#define __imp__%-13s __imp__%s' % (src_n, dn))
                w('void %s(PPCContext& __restrict ctx, uint8_t* base);' % dn)
                w('extern "C" void __imp__%s(PPCContext& __restrict ctx, uint8_t* base);' % dn)
        w('')
    hdr = '\n'.join(H) + '\n'

    S = []; w = S.append
    w('// kiniro_hook_stubs.cpp - GENERATED by out_kiniro/tools_kiniro/gen_symbol_map.py.  DO NOT EDIT.')
    w('//')
    w('// One WEAK definition per DROPPED reco_normal hook symbol (kiniro_symbol_map.h): the hook\'s own')
    w('// override, when merged_game.cpp has one, is a strong definition of sub_X_KDROP and wins; nothing')
    w('// in the kiniro tree calls either name, so these run only if a LIVE hook calls a dropped one.')
    w('// That is a hook whose callee has no kiniro twin: it is reported and the process stops (exit 97),')
    w('// unless RT_KDROP_CONT=1, which makes the stub a logged no-op (triage lever, step 3+).')
    w('// Compiled into futari_game_kiniro.dylib only (build_mac_dll.sh kiniro arm).')
    w('#include "ppc_recomp_shared.h"')
    w('#include <cstdio>')
    w('#include <cstdlib>')
    w('static void kdrop(const char* n) {')
    w('    static const bool cont = std::getenv("RT_KDROP_CONT") != nullptr;')
    w('    std::fprintf(stderr, "[kdrop] %s: reco_normal hook symbol with no kiniro_normal twin was CALLED%s\\n",')
    w('                 n, cont ? " (RT_KDROP_CONT=1: no-op)" : " -> exit 97 (RT_KDROP_CONT=1 continues)");')
    w('    std::fflush(stderr);')
    w('    if (!cont) std::_Exit(97);')
    w('}')
    for a in dropped:
        dn = 'sub_%08X_KDROP' % a
        w('extern "C" __attribute__((weak)) PPC_FUNC(__imp__%s) { (void)ctx; (void)base; kdrop("__imp__%s"); }' % (dn, dn))
        w('__attribute__((weak)) PPC_FUNC(%s) { __imp__%s(ctx, base); }' % (dn, dn))
    stubs = '\n'.join(S) + '\n'

    rep = []; w = rep.append
    w('# hook_match_kiniro.txt - GENERATED by gen_symbol_map.py (evidence for kiniro_symbol_map.h)')
    w('# addr class target delta candidates note files')
    for a, (cls, t, c, note) in sorted(res.items()):
        w('0x%08X %-9s %s %s %d %s [%s]' % (a, cls, ('0x%08X' % t) if t else '-', ('%+#x' % (t - a)) if t else '-',
                                         len(c), note or '-', '/'.join(sorted(refs[a]))))
    report = '\n'.join(rep) + '\n'

    od = arg('--outdir')     # scratch output (the Mac run writes here, the files are committed from Windows)
    outs = {os.path.join(od or KIN, 'kiniro_symbol_map.h'): hdr, os.path.join(od or KIN, 'kiniro_hook_stubs.cpp'): stubs,
            os.path.join(od or HERE, 'hook_match_kiniro.txt'): report}
    if '--check' in sys.argv:
        stale = [p for p, t in outs.items() if not os.path.exists(p) or open(p, encoding='utf-8').read() != t]
        print('CHECK: %s' % ('MATCH' if not stale else 'STALE ' + ' '.join(stale))); sys.exit(1 if stale else 0)
    for p, t in outs.items():
        with open(p, 'w', encoding='utf-8', newline='\n') as fh: fh.write(t)
        print('wrote %s' % os.path.relpath(p, REPO))
    print('dropped (%d): %s' % (len(dropped), ' '.join('0x%08X' % a for a in dropped)))


if __name__ == '__main__':
    main()
