#!/usr/bin/env python3
"""Side-by-side PPC disassembly of an image function against our compiled object.

Same inputs as `ppcmatch.py --check`, but prints mnemonics instead of hex.  Written after a
whole leg was spent hand-decoding rlwinm masks: the diff tells you WHICH words disagree, this
tells you WHAT they do, and register-allocation work is unreadable without it.

  python matchlab/disas.py game 0x8808DC10 Page_Bake src/game_8808DC10_Page_Bake.cpp \
      --insn 216 --flags "-O2 -Oc" --from 140 --to 180

Columns: index, original word + disasm, our word + disasm, and the ppcmatch verdict for that
slot (blank = identical, `~` = reloc-masked, `r` = same opcode different registers/fields,
`S` = structural).  Addresses in the original column are guest addresses so they can be pasted
straight into Ghidra; ours are object-relative and mean nothing on their own.
"""
import argparse
import capstone
import ppcmatch as pm

MD = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)


def disasm(word, addr):
    b = word.to_bytes(4, "big")
    for ins in MD.disasm(b, addr):
        return f"{ins.mnemonic} {ins.op_str}".strip()
    return f".long 0x{word:08x}"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("module")
    ap.add_argument("addr")
    ap.add_argument("symbol")
    ap.add_argument("src")
    ap.add_argument("--flags", default="-O2 -Oc")
    ap.add_argument("--insn", type=int, default=None)
    ap.add_argument("--from", dest="lo", type=int, default=0)
    ap.add_argument("--to", dest="hi", type=int, default=10**9)
    a = ap.parse_args()

    addr = int(a.addr, 16)
    flags = a.flags.split()
    t = {"name": a.symbol, "module": a.module, "addr": a.addr, "symbol": a.symbol,
         "src": a.src, "flags": flags}
    orig = pm.original_bytes(a.module, addr, a.insn)
    got, relocs = pm.compile_target(t, flags, tag="disas")
    ow, mw = pm.words(orig), pm.words(got)

    print(f"{a.symbol} @ {a.addr}  orig={len(ow)} ours={len(mw)}")
    print(f"{'idx':>4}  {'guest':>8}  {'orig':<34}  {'ours':<34}  v")
    for i in range(max(len(ow), len(mw))):
        if not (a.lo <= i <= a.hi):
            continue
        o = ow[i] if i < len(ow) else None
        m = mw[i] if i < len(mw) else None
        if o == m:
            v = " "
        elif i in relocs:
            v = "~"
        elif o is not None and m is not None:
            v = "r" if (o >> 26) == (m >> 26) else "S"
        else:
            v = "L"
        od = f"{o:08x} {disasm(o, addr + i * 4)}" if o is not None else ""
        md = f"{m:08x} {disasm(m, i * 4)}" if m is not None else ""
        print(f"{i:4d}  {addr + i * 4:08x}  {od:<34}  {md:<34}  {v}")


if __name__ == "__main__":
    main()
