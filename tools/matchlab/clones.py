#!/usr/bin/env python3
"""Find byte-identical CLONES of functions we have already matched.

A clone family is free board growth: one source file, N guest addresses.  The shell is full of
them because the menu code instantiates the same driver logic per mode.

WHY EXACT BYTES ARE A SOUND TEST.  Byte-identity at two different addresses means the bodies are
the same instruction for instruction, so one source file compiles to both.  It is a CONSERVATIVE
detector -- no false positives -- but it misses families whose copies differ only in a `bl`
displacement.  `--near N` relaxes it to "identical except at most N words", which DOES admit false
positives and is a lead generator only.

⚠ A CORRECTION, because this file first claimed otherwise: byte-identity does NOT imply the body
has no direct calls.  `bl` is PC-relative, so two copies each calling *its own* callee at the same
relative displacement encode identically while targeting different functions.  The 25x3 family at
0x82062198 / 0x82065D80 / 0x82069318 is exactly that -- each copy `bl`s a helper 0x18 past its own
end.  So when a family contains a `bl`, the callees are DIFFERENT functions per copy, and the
shared source must reach them through something that varies per instantiation (a template
parameter, a distinct inline callee) rather than one named function.  Check the branch targets
with disas.py before assuming a family shares a callee.

NOTHING HERE PROMOTES ANYTHING.  Every hit must still be verified with
`ppcmatch.py --check <module> <addr> <symbol> <src>` at its own address before it goes on the
board -- an earlier clone sweep emitted two false EXACTs, which is why `ppcmatch --selftest`
exists.  Report, verify, then promote.

  python matchlab/clones.py                # families containing an already-matched target
  python matchlab/clones.py --all          # every family in both images, matched or not
  python matchlab/clones.py --near 3       # allow up to 3 differing words (leads only)
"""
import argparse
import hashlib
import json
import os
from collections import defaultdict

import ppcmatch as pm


def body(module, addr):
    """Bytes of the function at addr, or None if the extent cannot be established."""
    try:
        return pm.original_bytes(module, addr, None)
    except Exception:
        return None


def load_board():
    """{(module, addr): name} for every target already on the board."""
    with open(os.path.join(pm.HERE, "functions.json"), encoding="utf-8") as f:
        d = json.load(f)
    return {(t["module"], int(t["addr"], 16)): t["name"] for t in d["targets"]}


def normalise_calls(b, addr):
    """Blank the displacement of every I-form branch that LEAVES this function.

    This is the difference between finding a handful of families and finding all of them.  Eight
    copies of one wrapper, each `bl`-ing its own per-mode helper, are the SAME SOURCE -- and
    ppcmatch can already prove it, because our .obj holds a relocation there and
    `equal_modulo_relocs` compares that field as masked.  So a family that differs only in call
    displacements is just as claimable as a byte-identical one: one source file, N addresses.

    Only branches whose target lands OUTSIDE [addr, addr+len) are blanked.  Intra-function
    branches are real control flow -- masking those would collapse genuinely different functions
    into one bogus family.
    """
    out = bytearray(b)
    n = len(b)
    for i in range(0, n, 4):
        w = int.from_bytes(b[i:i + 4], "big")
        if (w >> 26) != 18:                       # I-form b / bl / ba / bla only
            continue
        li = w & 0x03FFFFFC
        if li & 0x02000000:                       # sign-extend the 26-bit displacement
            li -= 0x04000000
        tgt = li if (w & 2) else addr + i + li    # AA=1 => absolute
        if addr <= tgt < addr + n:
            continue                              # internal branch: keep it
        out[i:i + 4] = (w & ~0x03FFFFFC).to_bytes(4, "big")
    return bytes(out)


def near_equal(a, b, budget):
    if len(a) != len(b):
        return False
    diff = sum(1 for i in range(0, len(a), 4) if a[i:i + 4] != b[i:i + 4])
    return diff <= budget


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--all", action="store_true",
                    help="report every family, not just ones touching a matched target")
    ap.add_argument("--near", type=int, default=0,
                    help="allow up to N differing words (LEADS ONLY -- can be wrong)")
    ap.add_argument("--min-insn", type=int, default=3,
                    help="ignore bodies shorter than this (default 3)")
    ap.add_argument("--exact-calls", action="store_true",
                    help="do NOT blank outbound call displacements (stricter, finds fewer)")
    a = ap.parse_args()

    board = load_board()
    total_free = 0

    for module in ("shell", "game"):
        starts = pm.func_starts(module)
        bodies = {}
        for addr in starts:
            b = body(module, addr)
            if b is not None and len(b) >= a.min_insn * 4:
                bodies[addr] = b if a.exact_calls else normalise_calls(b, addr)

        groups = defaultdict(list)
        for addr, b in bodies.items():
            groups[hashlib.sha1(b).hexdigest()].append(addr)

        if a.near:
            # Fold each exact group into the first near-equal group of the same length.
            reps, folded = [], defaultdict(list)
            for h, addrs in groups.items():
                b = bodies[addrs[0]]
                for rh, rb in reps:
                    if near_equal(b, rb, a.near):
                        folded[rh].extend(addrs)
                        break
                else:
                    reps.append((h, b))
                    folded[h].extend(addrs)
            groups = folded

        print(f"=== {module} : {len(bodies)} bodies with a usable extent ===")
        for h, addrs in sorted(groups.items(), key=lambda kv: -len(kv[1])):
            if len(addrs) < 2:
                continue
            known = [(x, board[(module, x)]) for x in sorted(addrs) if (module, x) in board]
            if not known and not a.all:
                continue
            n = len(bodies[addrs[0]]) // 4
            unclaimed = [x for x in sorted(addrs) if (module, x) not in board]
            tag = f"{known[0][1]}" if known else "(none matched)"
            print(f"  {n:4d} insn x {len(addrs):2d} copies  {tag}")
            print(f"        on board : {', '.join(hex(x) for x, _ in known) or '-'}")
            print(f"        UNCLAIMED: {', '.join(hex(x) for x in unclaimed) or '-'}")
            if known:
                total_free += n * len(unclaimed)

    print(f"\nfree instructions available from already-matched sources: {total_free}")
    print("VERIFY each with `ppcmatch.py --check` at its own address before promoting it.")


if __name__ == "__main__":
    main()
