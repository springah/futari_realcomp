#!/usr/bin/env python3
"""Pressure probe: nonvolatile priority measured at the register pressure real functions run at.

`probe_rank.py` killed three candidate models but could not replace them, and said why: it holds
THREE nonvolatiles where the ship-gate functions hold five to thirteen.  A priority allocator only
has to choose when values compete, so a three-value probe measures a regime that does not exist in
the code we are trying to match.  This raises the pressure to 9-13 and re-runs the sweeps there.

TWO DESIGN FIXES over probe_rank.py, both load-bearing:

  * **The bases are call results, not global addresses.**  `const unsigned* A = gA;` is a
    REMATERIALIZABLE constant (ALLOCATOR.md Step 3) and this compiler will re-emit `lis`/`addi`
    rather than keep it live -- probe_rank.py caught it doing exactly that after a branch.  Here
    every base comes from `mk(i)`, a call, so it is a genuine value that must occupy a register.
  * **Each base is identified by its displacement class**, base `i` using offsets `i*0x100`, so
    the register map is read off the disassembly with no symbol table and no guessing.

Every base is referenced in a controlled WINDOW of call slots, which fixes both variables
independently: the number of references (count) and the distance from first to last (span).

  python probe_pressure.py             # all three experiments
  python probe_pressure.py --show      # the generated source for experiment C
"""
import re
import sys
from collections import Counter

import capstone

import ppcmatch as pm

MD = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)

SLOTS = 26          # call sites the body is divided into
NONVOL = {f"r{i}" for i in range(14, 32)}


def gen(specs, slots=SLOTS):
    """specs: list of (count, start_slot, end_slot).  One base per entry.

    Base i is referenced `count` times, spread evenly over slots [start, end].
    """
    k = len(specs)
    decls = "\n".join(f"    const unsigned* A{i} = mk({i});" for i in range(k))
    # slot -> list of "s += Ai[idx];"
    at = {t: [] for t in range(slots)}
    for i, (n, lo, hi) in enumerate(specs):
        if n == 1:
            picks = [lo]
        else:
            step = (hi - lo) / (n - 1)
            picks = [int(round(lo + step * j)) for j in range(n)]
        for j, t in enumerate(picks):
            at[t].append(f"    s += A{i}[{i * 64 + j}];")
    body = []
    for t in range(slots):
        body.append("    f();")
        body.extend(at[t])
    return f"""extern unsigned* mk(int);
extern void f(void);

unsigned probe(unsigned k)
{{
{decls}
    unsigned s = 0;

{chr(10).join(body[:len(body) // 2])}

    if (k) {{ s += 7; }}

{chr(10).join(body[len(body) // 2:])}

    return s;
}}
"""


def disasm(obj):
    body, _ = pm.coff_function(obj, "probe")
    out = []
    for i in range(0, len(body), 4):
        w = int.from_bytes(body[i:i + 4], "big")
        ins = next(MD.disasm(w.to_bytes(4, "big"), i), None)
        out.append(f"{ins.mnemonic} {ins.op_str}".strip() if ins else ".long")
    return out


def read_map(ins, k):
    """{base_index: register} -- modal base register per displacement class.

    Modal, not first-seen: the first reference to a value is often based on a scratch volatile
    the compiler materialised for it alone, and reading that reports a volatile (the bug that
    made probe_rank.py's first version measure nothing).
    """
    seen = {i: Counter() for i in range(k)}
    for x in ins:
        m = re.match(r"lwz r\d+, (-?0x[0-9a-f]+|\d+)\((r\d+)\)", x)
        if not m:
            continue
        off, reg = int(m.group(1), 0), m.group(2)
        if reg == "r1" or off < 0:
            continue
        idx = off // 0x100
        if idx in seen:
            seen[idx][reg] += 1
    return {i: c.most_common(1)[0][0] for i, c in seen.items() if c}


def run(specs, tag):
    obj, err = pm._build_scratch(tag, gen(specs), "probe", ("-O2", "-Oc"))
    if err:
        return None, err
    ins = disasm(obj)
    return read_map(ins, len(specs)), None


def report(title, specs, tag):
    print(f"\n{title}")
    m, err = run(specs, tag)
    if err:
        print("  " + err[:200])
        return
    rows = []
    for i, (n, lo, hi) in enumerate(specs):
        reg = m.get(i)
        rows.append((i, n, hi - lo, reg))
    nv = [r for r in rows if r[3] and r[3] in NONVOL]
    print(f"  {'base':>5}{'count':>7}{'span':>6}{'reg':>6}")
    for i, n, sp, reg in rows:
        flag = "" if (reg in NONVOL) else "  <- volatile / rematerialised"
        print(f"  {i:>5}{n:>7}{sp:>6}{str(reg):>6}{flag}")
    print(f"  nonvolatiles in play: {len(nv)}")
    if len(nv) >= 3:
        by_reg = sorted(nv, key=lambda r: -int(r[3][1:]))
        print("  rank order (r31 first): " +
              ", ".join(f"base{r[0]}(n={r[1]},span={r[2]})" for r in by_reg))
        cnt = sorted(nv, key=lambda r: (-r[1], r[0]))
        print("  descending COUNT would be: " + ", ".join(f"base{r[0]}" for r in cnt))
        dens = sorted(nv, key=lambda r: (-(r[1] / max(r[2], 1)), r[0]))
        print("  descending DENSITY would be: " + ", ".join(f"base{r[0]}" for r in dens))
        print("  matches count?   ", [r[0] for r in by_reg] == [r[0] for r in cnt])
        print("  matches density? ", [r[0] for r in by_reg] == [r[0] for r in dens])


def main():
    K = 10
    if "--show" in sys.argv:
        print(gen([(4, i, i + 8) for i in range(K)]))
        return

    # A: equal counts, equal spans -- what breaks a total tie at pressure?
    report("EXPERIMENT A -- 10 bases, 3 references each, identical full-body spans.",
           [(3, 0, SLOTS - 1) for _ in range(K)], "pp_A")

    # B: counts vary, spans identical -- does Step 1 (descending count) hold at pressure?
    report("EXPERIMENT B -- 10 bases, counts 2..11, identical full-body spans.",
           [(2 + i, 0, SLOTS - 1) for i in range(K)], "pp_B")

    # C: counts identical, spans vary -- does span matter at pressure?
    report("EXPERIMENT C -- 10 bases, 4 references each, spans 3..21 (all starting at slot 0).",
           [(4, 0, 3 + 2 * i) for i in range(K)], "pp_C")


if __name__ == "__main__":
    main()
