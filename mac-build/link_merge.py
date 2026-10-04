#!/usr/bin/env python3
"""link_merge.py -- first-definition-wins linking on Mach-O (build_mac.sh header item 1).

    link_merge.py --cxx CXX --objcopy OBJCOPY --out OUT --objdir OBJDIR [--shared] -- <objects in link order> -- <libs/flags>

Apple's ld has no --allow-multiple-definition and llvm-objcopy cannot weaken Mach-O symbols, but it
CAN rename them (--redefine-sym). So: link once; parse ld's "duplicate symbol" errors (it prints
C symbols as-is and DEMANGLES C++ ones, and three-way duplicates happen -- every object in a group is
taken); map each printed name back to the object's real symbol through llvm-nm + llvm-cxxfilt; rename
every definition except the one in the object that appears EARLIEST on the link line to
<sym>__dup_dropped__<object>; relink. The rename list is derived every build, so new decomp promotions
(which add __imp__sub_* duplicates) need no maintenance. Objects are mutated in place: a relink of a
bisect arm must start from an un-renamed copy of the object dir (COMPILE_ONLY in build_mac.sh).
Prints LINK_OK -> OUT or LINK_FAILED; the raw ld output is in <objdir>/link.err and the rename list in
<objdir>/dup_renames.txt. Shared by build_mac.sh and build_mac_dll.sh (--shared = -dynamiclib).
"""
import re, sys, collections, subprocess, os
a = sys.argv[1:]
def take(flag):
    i = a.index(flag); v = a[i + 1]; del a[i:i + 2]; return v
cxx = take('--cxx'); objcopy = take('--objcopy'); out = take('--out'); objdir = take('--objdir')
shared = '--shared' in a
if shared: a.remove('--shared')
assert a[0] == '--'; a = a[1:]; sep = a.index('--'); linkline, libs = a[:sep], a[sep + 1:]
err_path = os.path.join(objdir, 'link.err'); renames_path = os.path.join(objdir, 'dup_renames.txt')
def link():
    cmd = [cxx, '-O2', '-std=c++20'] + (['-dynamiclib'] if shared else []) + linkline + ['-o', out] + libs + ['-Wl,-map,' + out + '.map']
    r = subprocess.run(cmd, stderr=open(err_path, 'w'))
    return r.returncode == 0
print("== LINK pass 1 (expect duplicate symbols; they are the merge) ==")
if link(): print(f"LINK_OK (no duplicates?) -> {out}"); sys.exit(0)
err = open(err_path).read()
order = {p: i for i, p in enumerate(linkline)}
def idx(o):
    for p, i in order.items():
        if p == o or o.endswith('/' + p) or p.endswith('/' + o) or os.path.basename(p) == os.path.basename(o): return i
    return None
groups = []
for m in re.finditer(r"duplicate symbol '([^']+)' in:\n((?:[ \t]+\S+\n?)+)", err):
    groups.append((m.group(1), m.group(2).split()))
for m in re.finditer(r"duplicate symbol '([^']+)' in (\S+) and (\S+)", err):
    groups.append((m.group(1), [m.group(2), m.group(3)]))
cxxfilt = os.path.join(os.path.dirname(objcopy), 'llvm-cxxfilt'); nm = os.path.join(os.path.dirname(objcopy), 'llvm-nm')
_maps = {}
def mangled(obj, printed):
    if obj not in _maps:
        syms = subprocess.run([nm, '--defined-only', '--format=just-symbols', obj], capture_output=True, text=True).stdout.split()
        dem = subprocess.run([cxxfilt], input='\n'.join(syms), capture_output=True, text=True).stdout.split('\n')
        _maps[obj] = ({s: s for s in syms}, dict(zip(dem, syms)))
    direct, demap = _maps[obj]
    return direct.get(printed) or demap.get(printed)
losers = collections.defaultdict(set); unresolved = []
for sym, objs in groups:
    ranked = [(idx(o), o) for o in objs]
    if any(i is None for i, _ in ranked): unresolved.append((sym, objs)); continue
    ranked.sort()
    for _, o in ranked[1:]:
        real = mangled(o, sym)
        if real is None: unresolved.append((sym, [o])); continue
        losers[o].add(real)
n = 0
with open(renames_path, 'w') as f:
    for o, syms in sorted(losers.items()):
        for s in sorted(syms): f.write(f"{o} {s}\n"); n += 1
print(f"duplicate groups: {len(groups)}; definitions to rename: {n} across {len(losers)} objects")
for sym, objs in unresolved: print(f"  UNRESOLVED: {sym} in {objs}")
if n == 0:
    print("LINK_FAILED (no duplicate-symbol lines parsed -- read " + err_path + ")"); print(err[-3000:]); sys.exit(1)
print("== renaming losing definitions (llvm-objcopy --redefine-sym) ==")
for o, syms in sorted(losers.items()):
    tag = os.path.basename(o)[:-2]   # per-object suffix: the same symbol can lose in two objects
    src = o if os.path.isfile(o) else os.path.join(objdir, os.path.basename(o))
    args = [f"--redefine-sym={s}={s}__dup_dropped__{tag}" for s in sorted(syms)]
    if subprocess.run([objcopy] + args + [src, src]).returncode != 0: print(f"objcopy FAILED on {src}"); sys.exit(1)
print("== LINK pass 2 ==")
if link(): print(f"LINK_OK -> {out}"); sys.exit(0)
print("LINK_FAILED"); print(open(err_path).read()[-4000:]); sys.exit(1)
