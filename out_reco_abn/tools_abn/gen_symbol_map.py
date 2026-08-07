#!/usr/bin/env python3
"""gen_symbol_map.py - emit out_reco_abn/abn_symbol_map.h

The reco_normal -> reco_abnormal CODE address law (derived + positive-controlled twice; see
_tmpscripts/abn_hook_census.md S3 and _tmpscripts/abn_recomp_notes.md S2):

    addr <  0x880DEF88   ->  addr        (same address)
    addr >= 0x880DF080   ->  addr + 8
    sub_880DEF88 itself  ->  same address, body grew by the 2-instruction insertion

The host hook layer (out_reco/merged/merged_xex.cpp + decomp/*/*.cpp) names reco_NORMAL
addresses.  Rather than fork those shared TUs, the abn build force-includes the header this
script emits, which #defines each shifted reco_normal symbol onto its reco_abnormal twin:

    #define sub_88168C80        sub_88168C88
    #define __imp__sub_88168C80 __imp__sub_88168C88

BOTH forms are required: merged_xex.cpp's wrapper-macro family builds the import name by token
pasting (`__imp__##FN`), and ## operands are NOT macro-expanded before the paste - only the
pasted RESULT is rescanned.  So renaming only `sub_X` would define sub_(X+8) while still
referencing __imp__sub_X.  The __imp__ define catches the rescan of the pasted token.

Demand side  = a fresh scan of the TUs that actually reference 0x88 function symbols.
Truth side   = _tmpscripts/abn_hook_census.json (expected_abn_addr per address) + the rule
               above for any address the census did not inventory.
Existence    = every emitted target must be declared in out_reco_abn/ppc_recomp_shared.h.

Hard aborts (any of these means the mechanical law does not apply and a human must look):
  * census expected_abn_addr disagrees with addr+8
  * an emitted target is not a real out_reco_abn symbol
  * CHAINED EXPANSION: some renamed address X has X+8 also in the rename set.  Object-like
    macros expand recursively, so `#define sub_X sub_X8` + `#define sub_X8 sub_X16` would send
    sub_X to sub_X16.  Currently zero such pairs exist; the abort keeps it that way.

usage:  python out_reco_abn/tools_abn/gen_symbol_map.py [--check]
        --check  : do not write, just verify the on-disk header matches what would be emitted
"""
import json, os, re, sys, glob

HERE = os.path.dirname(os.path.abspath(__file__))
ABN  = os.path.dirname(HERE)                    # xr-work/out_reco_abn
REPO = os.path.dirname(ABN)                     # xr-work

SPLIT_EDIT_LO = 0x880DEF88      # start of the one function that grew
SPLIT_SHIFT_LO = 0x880DF080     # first reco_normal address that lives at +8 in reco_abnormal
DELTA = 8

# TUs that get -include abn_symbol_map.h in _tmpscripts/build_win_abn.sh.
# game_entry_msgs.cpp is DELIBERATELY absent: see the header comment emitted below.
# merged_xex.cpp was split 3 ways at L2 (dll_packaging_plan.md §2.3); ONLY the game half
# (merged_game.cpp) is force-included with abn_symbol_map.h, so it is the only one scanned.
# merged_bridge.cpp / merged_shell.cpp name zero sub_88 symbols in code regions (measured
# _tmpscripts/l2_flags.py: all 85 renamed symbols are referenced from game-half blocks only).
SCAN = ['out_reco/merged/merged_game.cpp'] + \
       [f for f in sorted(glob.glob(os.path.join(REPO, 'decomp/game/*.cpp')) +
                          glob.glob(os.path.join(REPO, 'decomp/shell/*.cpp')))
        if os.path.basename(f) != 'game_entry_msgs.cpp']
SCAN = [f if os.path.isabs(f) else os.path.join(REPO, f) for f in SCAN]

SYM = re.compile(r'\b(?:__imp__)?(sub_88[0-9A-Fa-f]{6})\b')
# nvk_game_hooks.cpp builds names by pasting a bare hex tail: NVK_HOOK(8807ECA0, ...)
PASTE = re.compile(r'\bNVK_HOOK\(\s*(88[0-9A-Fa-f]{6})\b')


def code_only(t):
    """Return the file's CODE regions concatenated: comments and string/char literals removed by
    a real left-to-right tokenizer, not by regex.

    LANDMINE (cost one build): the first cut used
        re.sub(r'/\\*.*?\\*/','',t,flags=re.S) ; re.sub(r'//[^\\n]*','',t)
    A `/*` sequence inside a STRING LITERAL in merged_xex.cpp opened a bogus block comment that
    swallowed a multi-thousand-line region, silently dropping 8 of the 84 shifted hooks
    (sub_880E31B0 sub_880E4948 sub_880E49D8 sub_881526C0 sub_881527B8 sub_88152900 sub_881538C0
    sub_8822BE60).  The only thing that caught it was the link still reporting 8 unresolved
    __imp__ twins.  Do not go back to regex stripping.

    Comments must be excluded (not merely tolerated): merged_xex.cpp's own commentary names
    reco_ABNORMAL twins too (e.g. "abn twin sub_88168C88"), and folding those into the rename set
    creates a false X / X+8 chain collision."""
    out, i, n, start = [], 0, len(t), 0
    while i < n:
        c = t[i]
        if c == '/' and i + 1 < n and t[i + 1] == '/':
            out.append(t[start:i]); j = t.find('\n', i); i = n if j < 0 else j; start = i
        elif c == '/' and i + 1 < n and t[i + 1] == '*':
            out.append(t[start:i]); j = t.find('*/', i + 2); i = n if j < 0 else j + 2; start = i
        elif c in '"\'':
            out.append(t[start:i]); q = c; i += 1
            while i < n:
                if t[i] == '\\':
                    i += 2; continue
                if t[i] == q:
                    i += 1; break
                i += 1
            start = i
        else:
            i += 1
    out.append(t[start:n])
    return '\n'.join(out)


def die(msg):
    sys.stderr.write('gen_symbol_map: FATAL: %s\n' % msg)
    sys.exit(2)


def main():
    check = '--check' in sys.argv

    # ---- demand side: which guest function symbols do the host TUs actually name? ----
    refs = {}   # addr -> set(files)
    commentary = set()
    for f in SCAN:
        raw = open(f, encoding='utf-8', errors='replace').read()
        code = code_only(raw)
        names = set(SYM.findall(code)) | set('sub_' + h.upper() for h in PASTE.findall(code))
        commentary |= (set(SYM.findall(raw)) - names)
        for n in names:
            refs.setdefault(int(n[4:], 16), set()).add(os.path.relpath(f, REPO).replace('\\', '/'))
    if not refs:
        die('scanned %d files and found no sub_88XXXXXX references' % len(SCAN))

    # ---- truth side: the census's per-address expectation ----
    cen = {}
    cpath = os.path.join(REPO, '_tmpscripts/abn_hook_census.json')
    for row in json.load(open(cpath))['rows']:
        if row.get('kind') == 'CODE' and row.get('expected_abn_addr'):
            cen[row['addr_int']] = int(row['expected_abn_addr'], 16)

    # ---- existence side: real out_reco_abn symbols ----
    shared = open(os.path.join(ABN, 'ppc_recomp_shared.h'), encoding='utf-8').read()
    abn_syms = set(re.findall(r'PPC_EXTERN_FUNC\((sub_[0-9A-Fa-f]{8})\)', shared))

    same, shifted, in_edit, novel = [], [], [], []
    for a in sorted(refs):
        if a < SPLIT_EDIT_LO:
            same.append(a)
        elif a < SPLIT_SHIFT_LO:
            in_edit.append(a)
        else:
            shifted.append(a)
            exp = cen.get(a)
            if exp is None:
                novel.append(a)
            elif exp != a + DELTA:
                die('census expected_abn_addr for 0x%08X is 0x%08X, not 0x%08X (+8 rule broken '
                    '- do NOT rename mechanically)' % (a, exp, a + DELTA))

    # ---- hard abort: chained macro expansion ----
    rset = set(shifted)
    chain = sorted(a for a in shifted if a + DELTA in rset)
    if chain:
        die('CHAINED EXPANSION: %s each have their +8 twin also in the rename set. Object-like '
            'macros expand recursively; plain #defines would double-shift. Emit asm-label '
            'aliases for these instead.' % ', '.join('0x%08X' % a for a in chain))

    # ---- hard abort: target must exist in out_reco_abn ----
    missing = [a for a in shifted if 'sub_%08X' % (a + DELTA) not in abn_syms]
    if missing:
        die('no out_reco_abn twin for %s' % ', '.join('0x%08X' % a for a in missing))

    # below-split symbols must exist too (they are NOT renamed, so a miss = a dead hook)
    dead_same = [a for a in same if 'sub_%08X' % a not in abn_syms]

    body = []
    w = body.append
    w('// abn_symbol_map.h - GENERATED by out_reco_abn/tools_abn/gen_symbol_map.py.  DO NOT EDIT.')
    w('//')
    w('// Force-included (clang -include) ONLY by _tmpscripts/build_win_abn.sh, and only onto the')
    w('// host TUs that name reco_normal guest function symbols.  The reco_normal build')
    w('// (bash build_win.sh) never sees this file, so futari_merged.exe is unaffected.')
    w('//')
    w('// LAW (positive-controlled twice: _tmpscripts/abn_hook_census.md S3, abn_recomp_notes.md S2)')
    w('//   addr <  0x880DEF88  -> same address        (no #define emitted)')
    w('//   addr >= 0x880DF080  -> addr + 8            (#define emitted, both plain and __imp__)')
    w('//   sub_880DEF88        -> same address, body grew by the 2-insn insertion')
    w('//')
    w('// WHY BOTH `sub_X` AND `__imp__sub_X` ARE DEFINED: merged_xex.cpp\'s wrapper macros')
    w('// (SM_WRAP / TB_WRAP / E8_WRAP / CLOB_WRAP / SPLIT_WRAP / R26_BRACKET_WRAP /')
    w('// SLOT_WATCH_WRAP / DECODER_LOG_WRAP / RT_EEPROM_TRACE) build the import name with token')
    w('// pasting (`__imp__##FN`).  ## operands are not macro-expanded before the paste; only the')
    w('// pasted result is rescanned - which the __imp__ #define below then catches.')
    w('//')
    w('// NOT INCLUDED ON decomp/game/game_entry_msgs.cpp (the C1 MATCHED GameEntry).  Renaming it')
    w('// onto 0x8824E6A0 would ship a body whose ~45 guest .data literals (0x887AD547, 0x887AD58C,')
    w('// ...) are reco_normal offsets; those globals move +0x60 in reco_abnormal, so the stores')
    w('// would be subtly wrong.  In the abn build the GENERATED body owns __imp__sub_8824E6A0 and')
    w('// that TU is left out of the abn link entirely.  merged_xex.cpp\'s [gemsg]/[msglog]')
    w('// instrument wrapper IS renamed - instruments alive on the generated body is the goal.')
    w('//')
    w('// Note: `#FN` stringification inside those wrappers is also unexpanded, so instrument log')
    w('// text keeps the reco_normal symbol name (e.g. "[SPLIT-CHUNK] sub_8813A5F0") while the abn')
    w('// twin executes.  Deliberate: boot-gate log parsers stay identical across the two builds.')
    w('#pragma once')
    w('')
    w('// %d shifted symbols renamed (%d #defines); %d referenced symbols are below the split and'
      % (len(shifted), 2 * len(shifted), len(same)))
    w('// need no rename; %d referenced symbols land inside the edited function sub_880DEF88.'
      % len(in_edit))
    if novel:
        w('// %d not inventoried by the census - resolved by the +8 rule and existence-checked'
          % len(novel))
        w('// against out_reco_abn/ppc_recomp_shared.h: %s'
          % ' '.join('0x%08X' % a for a in novel))
    if dead_same:
        w('// WARNING - referenced but NOT a function start in out_reco_abn (still dead hooks):')
        w('//   %s' % ' '.join('0x%08X' % a for a in dead_same))
    if in_edit:
        w('// WARNING - inside sub_880DEF88 (same address, DIFFERENT body): %s'
          % ' '.join('0x%08X' % a for a in in_edit))
    w('')
    for a in shifted:
        src, dst = 'sub_%08X' % a, 'sub_%08X' % (a + DELTA)
        w('#define %-20s %s' % (src, dst))
        w('#define __imp__%-13s __imp__%s' % (src, dst))
    w('')

    out = '\n'.join(body)
    path = os.path.join(ABN, 'abn_symbol_map.h')
    if check:
        cur = open(path, encoding='utf-8').read() if os.path.exists(path) else None
        print('CHECK: %s' % ('MATCH' if cur == out else 'STALE'))
        sys.exit(0 if cur == out else 1)
    with open(path, 'w', encoding='utf-8', newline='\n') as fh:
        fh.write(out)
    print('wrote %s' % path)
    print('  renamed (shifted +8) : %d symbols -> %d #defines' % (len(shifted), 2 * len(shifted)))
    print('  same-address (no-op) : %d' % len(same))
    print('  inside edit fn       : %d %s' % (len(in_edit), ['0x%08X' % a for a in in_edit]))
    print('  census-verified      : %d   novel-by-rule: %d' % (len(shifted) - len(novel), len(novel)))
    print('  dead below split     : %d %s' % (len(dead_same), ['0x%08X' % a for a in dead_same]))
    print('  chain collisions     : 0 (asserted)')
    print('  comment-only mentions (NOT renamed): %d' % len(commentary))


if __name__ == '__main__':
    main()
