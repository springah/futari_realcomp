#!/usr/bin/env python3
"""Dropped-instruction census for a XenonRecomp output tree (the census block of scripts/regen_abn_mac.sh,
as a reusable file): an asm comment line `\t// <mnemonic> ...` that is followed by another asm comment, a label,
a closing brace or a blank line emitted NO C for that instruction, i.e. the recompiler silently dropped it.
Prints one line; exits 1 when anything was dropped.  usage: census_dropped.py TREE [TREE ...]"""
import re, glob, collections, sys

NOOP = {'nop', 'eieio', 'sync', 'tdlgei', 'isync', 'lwsync', 'mtmsr', 'mfmsr', 'twllei', 'tweqi', 'tdllei', 'twlgei',
        'twi', 'tw', 'td', 'b', 'db16cyc', 'cctpl', 'cctpm'}
bad = 0
for tree in sys.argv[1:]:
    c = collections.Counter()
    where = []
    for f in sorted(glob.glob(f'{tree}/ppc_recomp.*.cpp')):
        L = open(f, encoding='utf-8', errors='replace').read().split('\n')
        fn = '?'
        for i, l in enumerate(L):
            if l.startswith('PPC_FUNC_IMPL('):
                fn = l[len('PPC_FUNC_IMPL('):].split(')')[0]
            m = re.match(r'^\t// ([a-z][a-z0-9.]*) ', l)
            if not m or m.group(1) in NOOP or m.group(1).startswith('dcb'):
                continue
            nxt = L[i+1] if i + 1 < len(L) else ''
            if nxt.startswith('\t// ') or nxt.startswith('loc_') or nxt in ('}', ''):
                c[m.group(1)] += 1
                where.append(f'{fn}: {l.strip()}')
    n = sum(c.values())
    bad += n
    print(f'   {tree}: silently-dropped instructions: {n} {dict(c)}')
    for w in where[:10]:
        print(f'      {w}')
sys.exit(1 if bad else 0)
