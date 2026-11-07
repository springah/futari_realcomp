#!/usr/bin/env python3
"""audit.py NEWMAP [REFMAP] -- literal-store audit of merged_game.cpp hooks a module map INSTALLS (renamed or same-address)
that the reference map (kiniro, whose installed set the step-3 audit cleared) does NOT install. For each such hook body,
print every line that STORES (PPC_STORE_*) or overrides a return register, plus the env levers named in the body and
whether the store line itself sits under an rt_kgate."""
import re, sys
def installed(path):
    t = open(path).read()
    ren = set(m.group(1) for m in re.finditer(r'^#define (sub_[0-9A-F]{8}) +sub_[0-9A-F]{8}(_HCH)? ', t, re.M))
    same = set(re.findall(r'^//   (sub_[0-9A-F]{8})  same address', t, re.M))
    return ren | same
new = installed(sys.argv[1]); ref = installed(sys.argv[2]) if len(sys.argv) > 2 else set()
delta = sorted(new - ref)
src = open('out_reco/merged/merged_game.cpp', encoding='utf-8', errors='replace').read().split('\n')
# body extents: PPC_FUNC(sub_X){ ... matching braces; macro wraps (XXX_WRAP(sub_X)) noted separately
print('installed by %s: %d; by ref: %d; delta (new-only): %d' % (sys.argv[1], len(new), len(ref), len(delta)))
for name in delta:
    starts = [i for i, l in enumerate(src) if re.match(r'^\s*PPC_FUNC\(%s\)' % name, l)]
    wraps = [l.strip() for l in src if re.match(r'^[A-Z0-9_]+_WRAP\(%s\)' % name, l.strip())]
    if not starts:
        print('-- %s: no PPC_FUNC body%s' % (name, (' (wrapped: %s)' % ' '.join(wraps)) if wraps else ''))
        continue
    for st in starts:
        depth = 0; body = []
        for j in range(st, min(st + 400, len(src))):
            body.append((j + 1, src[j])); depth += src[j].count('{') - src[j].count('}')
            if depth <= 0 and j > st: break
        envs = sorted(set(re.findall(r'getenv\("([A-Z0-9_]+)"\)', '\n'.join(l for _, l in body))))
        hits = [(n, l.strip()) for n, l in body if re.search(r'PPC_STORE_U\d+\(\s*0x88|ctx\.r3\.u(32|64)\s*=|ctx\.lr\s*=', l)]
        print('-- %s @%d: %d lines, levers %s, %d store/override lines' % (name, st + 1, len(body), envs or '-', len(hits)))
        for n, l in hits: print('     %d%s: %s' % (n, ' [kgate]' if 'rt_kgate' in l else '', l[:150]))
