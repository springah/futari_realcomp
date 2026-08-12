#!/usr/bin/env python3
"""canon_seq.py A B — compare two gate-drive sequence logs, masking guest-heap pointers.

Promoted out of _local/_tmpscripts (where it was written for the C1 pilot, 2026-07-28) into the
tracked tree on 2026-08-12 by the D1 leg, which needed it in a second worktree. Behaviour
unchanged; the original docstring follows.

The C1 pilot proved (2026-07-28) that exe-image geometry seeds the guest allocator, so heap
pointers differ between ANY two binaries with ZERO translation difference. Raw byte-equality
can therefore never gate across builds; mask the heap range and compare everything else.
Previously this masking was done ad hoc in-session, which is why it kept having to be
re-derived. Exit 0 = canonical-identical.
"""
import re, sys
HEAP_LO, HEAP_HI = 0x200000, 0x4000000
PAT = re.compile(r'(0x)?([0-9A-Fa-f]{6,8})\b')

def canon(line):
    def sub(m):
        v = int(m.group(2), 16)
        return ((m.group(1) or "") + "PTR") if HEAP_LO <= v < HEAP_HI else m.group(0)
    return PAT.sub(sub, line)

def load(p):
    return [canon(l) for l in open(p, encoding="utf-8", errors="replace")]

a, b = load(sys.argv[1]), load(sys.argv[2])
if a == b:
    print(f"CANONICAL-IDENTICAL {len(a)}/{len(a)} lines - GATE PASS")
    sys.exit(0)
print(f"DIFFER: control {len(a)} lines, pilot {len(b)} lines")
for i, (x, y) in enumerate(zip(a, b)):
    if x != y:
        print(f"  [{i}] C: {x.rstrip()[:140]}")
        print(f"  [{i}] P: {y.rstrip()[:140]}")
sys.exit(1)
