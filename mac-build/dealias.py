#!/usr/bin/env python3
"""dealias.py <outdir> <src.cpp>... -- the Mach-O de-alias pre-pass (build_mac.sh header item 4).

Mach-O has no __attribute__((alias)), and every recompiled TU opens each function with
    __attribute__((alias("__imp__sub_X"))) PPC_WEAK_FUNC(sub_X);
This rewrites that one line shape (column 0 only, so decomp notes quoting it are untouched) into a
weak forwarding stub, in a COPY under <outdir>/ named after the source path with '/' -> '__':
    PPC_FUNC_IMPL(__imp__sub_X); PPC_WEAK_FUNC(sub_X) { __imp__sub_X(ctx, base); }
Same linkage (weak C++-mangled sub_X, strong extern "C" __imp__sub_X), same override semantics (a
strong sub_X elsewhere still wins), one extra `b` per call (clang tail-calls it). The tracked
sources are never modified. A TU with no alias line gets no copy (the build compiles the original).
Shared by build_mac.sh (the merged single executable) and build_mac_dll.sh (host + module dylibs).
"""
import re, sys, os
out = sys.argv[1]
# The target is either a string literal or the one stringified macro the shell tree uses for its CRT
# entry (shell/gen/ppc_recomp.5.cpp: alias(RT_XSTART_ALIAS_STR) == "__imp___xstart", renamed by -D in
# the merged build); as a plain token it goes through the same -D rename, so the stub needs no special case.
pat = re.compile(r'^__attribute__\(\(alias\((?:"(\w+)"|(\w+))\)\)\)\s*PPC_WEAK_FUNC\((\w+)\);', re.M)
macro_targets = {'RT_XSTART_ALIAS_STR': '__imp___xstart'}
def stub(m):
    tgt = m.group(1) or macro_targets[m.group(2)]
    return f'PPC_FUNC_IMPL({tgt}); PPC_WEAK_FUNC({m.group(3)}) {{ {tgt}(ctx, base); }}'
os.makedirs(out, exist_ok=True)
files = total = 0
for f in sys.argv[2:]:
    if not os.path.isfile(f): continue
    t = open(f).read()
    if 'alias(' not in t: continue
    t2, n = pat.subn(stub, t)
    if n == 0: continue
    open(os.path.join(out, f.replace('/', '__')), 'w').write(t2); files += 1; total += n
print(f"rewrote {total} alias lines in {files} TUs -> {out}/")
