#!/usr/bin/env python3
"""Measure the image's nonvolatile RANK against candidate priority functions.

ALLOCATOR.md Step 1 says branch-crossing values are ranked by loop-weighted reference count,
descending, and its own caveats section admits that does not reproduce full permutations in real
functions ("there is a further ordering term").  Seven of the eight ship-gate functions are now
blocked on register numbering alone, so that term is the single thing standing between the gate
and a much higher score.  This measures it instead of arguing about it.

For each function it decodes the GUEST bytes, and for every nonvolatile GPR r14..r31 collects:

  n     number of instructions mentioning the register  (ALLOCATOR.md's "machine references")
  base  how many of those use it as an ADDRESS BASE, i.e. appear as "(rNN)" -- correction #2
  def   index of the first instruction that writes it
  last  index of the last instruction mentioning it
  span  last - def, the live range length in instructions

Then it scores each candidate priority function by how well its descending order reproduces the
actual r31..r14 assignment, using Kendall tau over the pairs plus an exact-order flag.

This is a MEASUREMENT, not a matcher: it reads only the image side, so it says what the original
allocator did, independent of anything we compile.  A candidate that reproduces the image's order
on every function is a rule; one that reproduces most is a lead.

VERDICT 2026-08-07, five real functions carrying 3+ nonvolatiles (Page_Bake 13, Sprite_EmitQuad
11, Render_SelectBlend 9, Page_EnsureTexture 6, Sprite_FlushBatch 5):

    3*base + other - span/8      mean tau 0.706     exact 0/5
    n - span/8                            0.676     exact 0/5
    (3*base + other) / span               0.664     exact 0/5
    n   (ALLOCATOR.md Step 1)             0.623     exact 0/5
    3*base + other                        0.620     exact 0/5
    base references only                  0.579     exact 0/5

Two things follow, and the second is the one that matters.

1. ★ ALLOCATOR.md's correction #2 (address-base references weigh ~3x) is CORROBORATED on data it
   was not derived from: weighting bases 3x lifts mean tau from 0.623 to 0.706, and it is the
   best candidate on three of the five functions.  A live-range-SPAN penalty helps independently
   (n - span/8 beats plain n), which is a term the document does not currently have.  Both are
   LEADS, not rules -- five functions and tau gaps of ~0.05 are not enough to promote either, and
   neither is exact anywhere.

2. ⚠ NO closed-form function of (reference count, base share, definition index, last-use index,
   live-range span) reproduces the image's ordering on a single one of the five.  Plain count
   sits at 0.623, barely above the 0.5 a coin gets.  ⇒ THE MISSING TERM IS NOT OBSERVABLE FROM
   THE EMITTED STREAM, which is the same conclusion the Page_Bake leg reached from the other
   direction ("the difference lives in the IR handed to the allocator, not in any statistic of
   what it emitted").  Do not spend another leg fitting curves to disassembly.  The route that
   works is the one this document was built with: SYNTHETIC probes that vary one factor at a
   time against a known baseline.

⚠ KNOWN LIMIT OF THIS INSTRUMENT: it profiles REGISTERS, not VALUES.  If a nonvolatile holds two
different values in two disjoint ranges, its span here is the union and its count is the sum.
That is rare for nonvolatiles and cannot explain a 0.3 tau shortfall, but it does mean small tau
differences between candidates are noise.

  python rank.py                # every gate function
  python rank.py Compose_Veil   # one, with the per-register table
"""
import re
import sys

import capstone

import ppcmatch as pm

MD = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)

# (name, module, addr, declared insn) -- the ship gate, plus the two matched controls at the
# bottom.  The controls matter: a candidate rule MUST also hold on functions we already match
# byte-for-byte, where our register map provably equals the image's.
FUNCS = [
    ("Compose_Veil",           "shell", 0x82182A68,  89),
    ("Page_Bake",              "game",  0x8808DC10, 216),
    ("Sprite_FlushBatch",      "game",  0x8808E468, 169),
    ("Render_SelectBlend",     "game",  0x88070000, 171),
    ("Sprite_EmitQuad",        "game",  0x8808E298, 116),
    ("Page_EnsureTexture",     "game",  0x8808D838,  50),
    ("Root_Join",              "shell", 0x821CE400,  46),
    ("Compose_Root",           "shell", 0x821CDBE8,  81),   # CONTROL: ASM-EXACT
    ("Driver_ArmSession",      "shell", 0x821C2E20,  51),   # CONTROL: ASM-EXACT
    ("Input_Poll",             "shell", 0x821915C0,  31),
]

NONVOL = [f"r{i}" for i in range(14, 32)]

# Millicode: `bl __savegprlr_N` / `b __restgprlr_N` save and restore nonvolatiles wholesale.
# Those are prologue/epilogue bookkeeping, not references the allocator was pricing, and the
# save/restore words do not name the registers in their operands anyway -- but the explicit
# `stw r31,..(r1)` / `lwz r31,..(r1)` frame spills a function may emit instead DO, and counting
# them would inflate every long-lived value identically.  They are dropped here.
def is_frame_spill(mnem, ops):
    return mnem in ("stw", "lwz", "stfd", "lfd") and ops.endswith("(r1)")


def decode(module, addr, declared):
    body = pm.original_bytes(module, addr, declared)
    if isinstance(body, tuple):
        body = body[0]
    out = []
    for i in range(0, len(body), 4):
        w = int.from_bytes(body[i:i + 4], "big")
        ins = next(MD.disasm(w.to_bytes(4, "big"), addr + i), None)
        out.append((ins.mnemonic, ins.op_str) if ins else (".long", ""))
    return out


def profile(insns):
    """{reg: (n, def_idx, last_idx, span)} for every nonvolatile that appears."""
    hits, bases = {}, {}
    for idx, (mnem, ops) in enumerate(insns):
        if is_frame_spill(mnem, ops):
            continue
        for b in set(re.findall(r"\((r\d+)\)", ops)):
            if b in NONVOL:
                bases[b] = bases.get(b, 0) + 1
        # operand tokens: split on anything that is not [a-z0-9]
        toks = set()
        cur = ""
        for ch in ops:
            if ch.isalnum():
                cur += ch
            else:
                if cur:
                    toks.add(cur)
                cur = ""
        if cur:
            toks.add(cur)
        for r in toks & set(NONVOL):
            hits.setdefault(r, []).append(idx)
    prof = {}
    for r, idxs in hits.items():
        nbase = bases.get(r, 0)
        prof[r] = (len(idxs), nbase, len(idxs) - nbase, idxs[0], idxs[-1], idxs[-1] - idxs[0])
    return prof


# --- candidate priority functions -------------------------------------------------------
# Each takes (n, defidx, lastidx, span, ninsn) and returns a score; HIGHER == higher register.
CANDIDATES = {
    "n (ALLOCATOR.md Step 1)":      lambda n, b, o, d, l, s, N: n,
    "3*base + other - span/8":      lambda n, b, o, d, l, s, N: 3 * b + o - s / 8.0,
    "n - span/8":                   lambda n, b, o, d, l, s, N: n - s / 8.0,
    "(3*base + other) / span":      lambda n, b, o, d, l, s, N: (3 * b + o) / max(s, 1),
    "3*base + other":               lambda n, b, o, d, l, s, N: 3 * b + o,
    "2*base + other":               lambda n, b, o, d, l, s, N: 2 * b + o,
    "base references only":         lambda n, b, o, d, l, s, N: b,
    "n / span (density)":           lambda n, b, o, d, l, s, N: n / max(s, 1),
    "-span (shortest range)":       lambda n, b, o, d, l, s, N: -s,
    "-last (dies earliest)":        lambda n, b, o, d, l, s, N: -l,
    "-def (defined earliest)":      lambda n, b, o, d, l, s, N: -d,
}


def kendall(order_a, order_b):
    """Fraction of concordant pairs between two orderings of the same items."""
    items = list(order_a)
    pos_b = {x: i for i, x in enumerate(order_b)}
    conc = disc = 0
    for i in range(len(items)):
        for j in range(i + 1, len(items)):
            if pos_b[items[i]] < pos_b[items[j]]:
                conc += 1
            else:
                disc += 1
    return conc / max(conc + disc, 1)


def main():
    only = sys.argv[1] if len(sys.argv) > 1 else None
    totals = {k: [0, 0] for k in CANDIDATES}   # [sum tau, exact count]
    nfun = 0
    for name, mod, addr, insn in FUNCS:
        if only and only != name:
            continue
        insns = decode(mod, addr, insn)
        prof = profile(insns)
        if len(prof) < 3:
            continue
        nfun += 1
        # actual: descending register number == descending rank
        actual = sorted(prof, key=lambda r: -int(r[1:]))
        if only:
            print(f"\n{name}  ({mod}, {insn} insn)")
            print(f"  {'reg':>4}{'n':>5}{'base':>6}{'def':>6}{'last':>6}{'span':>6}")
            for r in actual:
                n, b, o, d, l, s = prof[r]
                print(f"  {r:>4}{n:>5}{b:>6}{d:>6}{l:>6}{s:>6}")
        line = []
        for cname, fn in CANDIDATES.items():
            pred = sorted(prof, key=lambda r: -fn(*prof[r], insn))
            tau = kendall(actual, pred)
            exact = pred == actual
            totals[cname][0] += tau
            totals[cname][1] += int(exact)
            line.append((cname, tau, exact))
        if only:
            print("  candidate                       tau   exact")
            for cname, tau, exact in sorted(line, key=lambda x: -x[1]):
                print(f"  {cname:<30}{tau:>6.2f}   {'YES' if exact else ''}")
    if not only:
        print(f"across {nfun} functions\n")
        print(f"{'candidate':<32}{'mean tau':>10}{'exact':>8}")
        print("-" * 50)
        for cname, (tsum, ex) in sorted(totals.items(), key=lambda x: -x[1][0]):
            print(f"{cname:<32}{tsum / nfun:>10.3f}{ex:>6}/{nfun}")


if __name__ == "__main__":
    main()
