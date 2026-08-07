#!/usr/bin/env python3
"""Addressing probe: when does this compiler COLLAPSE base+index into an address register?

`Page_EnsureTexture` is three words from exact and two of them are one decision: the image emits

    add r30,r31,r30        <- &tbl[i], collapsing the hoisted base and the byte index
    lwz r11,0(r30)
    ... bl ...
    stw r3,0(r30)

where we emit `lwzx r11,r31,r30` / `stwx r3,r31,r30` and never form the address.  The same
decision parks `Driver_SendStageRecord` (16/22, x8 clones = 176 instructions).  Source shape did
not reach it on either function -- eleven spellings on one, thirty-seven on the other -- so this
asks the compiler directly, on bodies small enough to read.

⚠ THE IMAGE'S FORM IS ONE INSTRUCTION *WORSE*: `lwzx` needs no `add`.  So "the optimiser would
prefer it" is not available as an explanation, and a NEGATIVE result here is a real outcome worth
having -- it would mean both functions are permanently short by their three and six words, and
should stop being re-opened.

Each variant is scored by whether the emitted body contains an address collapse: an `add rD,rA,rB`
whose result is subsequently used as the BASE of an offset-form load or store.

VERDICT 2026-08-07 -- the rule, and why it does NOT rescue Page_EnsureTexture.

Sixteen variants. The collapse happens under exactly two conditions, and neither is "more
accesses":

  ✅ the address ESCAPES to a callee (`take(&tbl[idx])`)                     -> collapse
  ✅ the pointer is used at TWO OR MORE **DISTINCT OFFSETS** across a call   -> collapse
     (p[0] then p[1]; p[0]/p[1]/p[2]; p[0]..p[3] -- all collapse)
  ❌ the SAME offset touched repeatedly, even four times across three calls  -> indexed, always
  ❌ two, four or six accesses to one element with calls between             -> indexed, always
  ❌ distinct offsets with NO call between                                   -> no collapse
  ❌ explicit byte-pointer arithmetic ((char*)tbl + idx*4)                   -> indexed

So it is not use count and not call-crossing on its own: it is **distinct offsets off one
computed address, live across a call**. That is a genuine, reusable rule for the campaign -- and
it is the answer to matchlab tell #10's other half (indexed form means flat-array access; offset
form means a real record pointer whose fields are actually used).

⚠ AND IT DOES NOT CLOSE `Page_EnsureTexture`. The image collapses the address there but touches
only ONE offset through it (`lwz r11,0(r30)` at +27, `stw r3,0(r30)` at +40), which fits neither
condition. The likely reading is that the original source DID use a record pointer at two offsets
and the compiler served the second one off the already-live `tbl+4` column base (r28, indexed) --
CSE picking the cheaper of two equivalent forms. Writing that shape does not reproduce it:

    record pointer, tex + sizeState through it   19 mismatched words   (frame drops to -0x80,
    same with the success test on the result   22 mismatched words    the r26 zero is lost)
    canonical (flat array)                      9 mismatched words
    _ptr sibling                                3 mismatched words

⇒ The rule is banked; the function is unchanged. Do not re-run the record-pointer shapes.

  python probe_addr.py            # the sweep
  python probe_addr.py --show C   # generated source + disassembly for one variant
"""
import re
import sys

import capstone

import ppcmatch as pm

MD = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)

HEAD = """extern unsigned tbl[];
extern void f(void);
extern void sink(unsigned);

unsigned probe(unsigned i, unsigned k)
{
    unsigned idx = i * 5;
"""


def body(accesses, call_between=True, second_column=False, index_used_after=False,
         other_column_base=False):
    """Compose one variant.

    accesses           how many times the SAME element tbl[idx] is touched
    call_between       put an opaque call between the accesses (forces nonvolatiles)
    second_column      also touch tbl[idx+1] through the same index
    index_used_after   touch tbl[idx+2] at the very end, so the index outlives the element
    other_column_base  read tbl[idx+1] FIRST, so a second column base gets hoisted early
                       (this is the shape Page_EnsureTexture actually has)
    """
    out = ["    unsigned s = 0;"]
    if other_column_base:
        out.append("    s += tbl[idx + 1];")
        if call_between:
            out.append("    f();")
    for n in range(accesses):
        if n and call_between:
            out.append("    f();")
        if n % 2 == 0:
            out.append("    s += tbl[idx];")
        else:
            out.append("    tbl[idx] = s;")
    if second_column:
        out.append("    s += tbl[idx + 1];")
    if index_used_after:
        out.append("    tbl[idx + 2] = s;")
    out.append("    return s;")
    out.append("}")
    return HEAD + "\n".join(out) + "\n"


VARIANTS = {
    "A  2 accesses, no call":        body(2, call_between=False),
    "B  2 accesses, call between":   body(2, call_between=True),
    "C  4 accesses, call between":   body(4, call_between=True),
    "D  2 acc + second column":      body(2, True, second_column=True),
    "E  2 acc + index used after":   body(2, True, index_used_after=True),
    "F  2 acc + other col base":     body(2, True, other_column_base=True),
    "G  full EnsureTexture shape":   body(2, True, other_column_base=True,
                                          index_used_after=True),
    "H  6 accesses, call between":   body(6, call_between=True),
    "I  3 accesses, no call":        body(3, call_between=False),
}


def disasm(obj):
    b, _ = pm.coff_function(obj, "probe")
    out = []
    for i in range(0, len(b), 4):
        w = int.from_bytes(b[i:i + 4], "big")
        ins = next(MD.disasm(w.to_bytes(4, "big"), i), None)
        out.append(f"{ins.mnemonic} {ins.op_str}".strip() if ins else ".long")
    return out


def collapsed(ins):
    """(bool, detail) -- is there an `add` whose result is later an offset-form base?"""
    adds = {}
    for n, x in enumerate(ins):
        m = re.match(r"add (r\d+), (r\d+), (r\d+)$", x)
        if m:
            adds[m.group(1)] = n
    for n, x in enumerate(ins):
        m = re.match(r"(lwz|stw) r\d+, (-?0x[0-9a-f]+|\d+)\((r\d+)\)$", x)
        if m and m.group(3) in adds and adds[m.group(3)] < n and m.group(3) != "r1":
            return True, f"add at +{adds[m.group(3)]} -> {m.group(1)} {m.group(2)}({m.group(3)}) at +{n}"
    return False, ""


def counts(ins):
    ix = sum(1 for x in ins if x.startswith(("lwzx", "stwx")))
    off = sum(1 for x in ins if re.match(r"(lwz|stw) r\d+, .*\(r(?!1\b)\d+\)$", x))
    return ix, off


def main():
    if "--show" in sys.argv:
        key = sys.argv[sys.argv.index("--show") + 1]
        name = next(k for k in VARIANTS if k.startswith(key))
        print(VARIANTS[name])
        obj, err = pm._build_scratch("pa_show", VARIANTS[name], "probe", ("-O2", "-Oc"))
        if err:
            print(err)
            return
        for n, x in enumerate(disasm(obj)):
            print(f"{n:3} {x}")
        return

    print(f"{'variant':<30}{'insn':>5}{'lwzx/stwx':>11}{'offset':>8}   collapse?")
    print("-" * 84)
    for name, src in VARIANTS.items():
        obj, err = pm._build_scratch("pa_" + name[0], src, "probe", ("-O2", "-Oc"))
        if err:
            print(f"{name:<30} {err[:40]}")
            continue
        ins = disasm(obj)
        ix, off = counts(ins)
        yes, detail = collapsed(ins)
        print(f"{name:<30}{len(ins):>5}{ix:>11}{off:>8}   "
              f"{'YES  ' + detail if yes else 'no'}")


if __name__ == "__main__":
    main()
