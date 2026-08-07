#!/usr/bin/env python3
"""Synthetic probe: does nonvolatile priority weigh reference COUNT or reference DENSITY?

`rank.py` measured the image and found every span-aware candidate beating its span-blind twin,
best at mean tau 0.706 but exact on none of five functions -- a lead, not a rule.  The route
ALLOCATOR.md prescribes for turning a lead into a coefficient is a controlled probe, and the data
named the experiment: count against span at fixed count.

THE DESIGN.  Two branch-crossing address bases in one function:

  * A is referenced in a TIGHT cluster   -> short live range
  * B is referenced spread across calls  -> long live range

Calls between the references force both into nonvolatiles.  Two tests:

  EQUAL COUNTS (the decisive one).  Same number of references each, so Step 1 is a tie and can
  say nothing.  If span matters, the tight array wins.  Declaration order is swapped as a
  control: Step 2 breaks ties by definition order, so a span effect only survives if the tight
  array wins in BOTH orders.

  UNEQUAL COUNTS.  Sweep B's count upward against a fixed A to find the crossover, which would
  give the exchange rate between one reference and one unit of span.

A is identified by its displacements (0x00..) and B by its (0x80..), so the reading needs no
symbol table.

  python probe_rank.py            # both sweeps
  python probe_rank.py --show 5   # generated source and disassembly for the unequal case nb=5
"""
import re
import sys
from collections import Counter

import capstone

import ppcmatch as pm

MD = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)

PROLOGUE = """extern unsigned gA[];
extern unsigned gB[];
extern void f(void);

unsigned probe(unsigned k)
{
"""


def _tight(name, n, first=0):
    """n references to `name`, with calls interleaved so the range crosses them but stays short.

    A value whose references all sit ahead of every call never needs a nonvolatile at all -- the
    first version of this probe did that and the array landed in r11, measuring nothing.
    """
    out = []
    for i in range(n):
        out.append(f"    s += {name}[{first + i}];")
        if i != n - 1:
            out.append("    f();")
    return out


def _spread(name, n, first=0):
    """n references to `name`, one per call, so the range spans the rest of the function."""
    out = []
    for i in range(n):
        out.append("    f();")
        out.append(f"    s += {name}[{first + i}];")
    return out


def source_eq(n, a_first=True):
    decls = ["    const unsigned* A = gA;", "    const unsigned* B = gB;"]
    if not a_first:
        decls.reverse()
    body = (decls + ["    unsigned s = 0;", ""]
            + _tight("A", n)
            + ["", "    if (k) { s += 7; }", ""]
            + _spread("B", n, 0x80 // 4)
            + ["", "    return s;", "}"])
    return PROLOGUE + "\n".join(body) + "\n"


def source(na, nb):
    body = (["    const unsigned* A = gA;", "    const unsigned* B = gB;",
             "    unsigned s = 0;", ""]
            + _tight("A", na)
            + ["", "    if (k) { s += 7; }", ""]
            + _spread("B", nb, 0x80 // 4)
            + ["", "    return s;", "}"])
    return PROLOGUE + "\n".join(body) + "\n"


def disasm(obj):
    body, _ = pm.coff_function(obj, "probe")
    out = []
    for i in range(0, len(body), 4):
        w = int.from_bytes(body[i:i + 4], "big")
        ins = next(MD.disasm(w.to_bytes(4, "big"), i), None)
        out.append(f"{ins.mnemonic} {ins.op_str}".strip() if ins else ".long")
    return out


def bases(ins):
    """(regA, regB) -- the register each array's loads are based on.

    Take the MODAL base per offset class, not the first seen: the first reference to an array is
    commonly based on a scratch volatile materialised for it alone (`lis r11,gA` /
    `lwz r31,0(r11)`), and reading that as the array's home register reports a volatile and
    measures nothing -- which is exactly what the first version of this did.
    """
    ca, cb = Counter(), Counter()
    for x in ins:
        m = re.match(r"lwz r\d+, (-?0x[0-9a-f]+|\d+)\((r\d+)\)", x)
        if not m:
            continue
        off, reg = int(m.group(1), 0), m.group(2)
        if reg == "r1":
            continue
        (ca if off < 0x40 else cb)[reg] += 1
    return (ca.most_common(1)[0][0] if ca else None,
            cb.most_common(1)[0][0] if cb else None)


def build(tag, text):
    obj, err = pm._build_scratch(tag, text, "probe", ("-O2", "-Oc"))
    if err:
        return None, err
    return disasm(obj), None


def main():
    if "--show" in sys.argv:
        nb = int(sys.argv[sys.argv.index("--show") + 1])
        print(source(3, nb))
        ins, err = build(f"probe_3_{nb}", source(3, nb))
        ra, rb = bases(ins)
        print(f"A -> {ra}   B -> {rb}\n")
        for i, x in enumerate(ins):
            print(f"{i:3} {x}")
        return

    print("EQUAL COUNTS, DIFFERENT SPANS -- the decisive test.")
    print("Same reference count each, so Step 1 is a tie. A's are tight, B's are spread.\n")
    print(f"{'n each':>7}{'decl':>7}{'A reg':>8}{'B reg':>8}{'winner':>9}   note")
    print("-" * 62)
    for n in range(2, 8):
        for a_first in (True, False):
            ins, err = build(f"probe_eq_{n}_{int(a_first)}", source_eq(n, a_first))
            lbl = "A,B" if a_first else "B,A"
            if err:
                print(f"{n:>7}{lbl:>7}   {err[:44]}")
                continue
            ra, rb = bases(ins)
            if not ra or not rb:
                print(f"{n:>7}{lbl:>7}   (bases not identified)")
                continue
            win = "A" if int(ra[1:]) > int(rb[1:]) else "B"
            print(f"{n:>7}{lbl:>7}{ra:>8}{rb:>8}{win:>9}   "
                  f"{'tight wins' if win == 'A' else 'spread wins'}")

    NA = 3
    print(f"\nUNEQUAL COUNTS.  A: {NA} references tight.  B: nb references, one per call.\n")
    print(f"{'nb':>4}{'A reg':>8}{'B reg':>8}{'winner':>9}   count model   density model")
    print("-" * 62)
    for nb in range(2, 10):
        ins, err = build(f"probe_{NA}_{nb}", source(NA, nb))
        if err:
            print(f"{nb:>4}   {err[:44]}")
            continue
        ra, rb = bases(ins)
        if not ra or not rb:
            print(f"{nb:>4}   (bases not identified)")
            continue
        win = "A" if int(ra[1:]) > int(rb[1:]) else "B"
        says = "A" if NA > nb else ("B" if nb > NA else "tie")
        print(f"{nb:>4}{ra:>8}{rb:>8}{win:>9}   {says:<13} A")


if __name__ == "__main__":
    main()
