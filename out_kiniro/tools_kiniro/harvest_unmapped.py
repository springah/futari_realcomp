#!/usr/bin/env python3
"""harvest_unmapped.py -- Black Label step 3 harvest loop helper (docs/PLAN_kiniro_bringup.md "Step 3").

Reads one or more guest logs (or harvest.txt files) from a kiniro boot, collects every DISTINCT
`[indirect] UNMAPPED ... target=0x88......` address, and turns the ones XenonRecomp's static analysis
missed into `{ address = 0x..., size = 0x... }` rows for config/futari_kiniro.toml (size = distance to the
next function start the analysis DID find, per PLAN §5.1; the first `blr` at/after the target is reported
beside it so a wrong extent is visible by eye). Targets that already ARE function starts are listed
separately: those are unmapped for a different reason (the recompiled body exists but the table slot is
not installed), not a harvest item.

    python3 out_kiniro/tools_kiniro/harvest_unmapped.py _local/nav_mac/k3_boot1/guest.log            # report only
    python3 out_kiniro/tools_kiniro/harvest_unmapped.py ... --apply                                   # append to the tomls
    python3 out_kiniro/tools_kiniro/harvest_unmapped.py ... --img _local/kiniro/img/kiniro_normal.img.bin

--apply appends the new rows to config/futari_kiniro.toml and, by the +8 law (PLAN §5.1: +8 at or above
0x880E1C60, same address below 0x880E1B68, refuse in between), to config/futari_kiniro_abn.toml. Then run
`bash scripts/regen_kiniro_mac.sh`, `gen_symbol_map.py --control` + `gen_symbol_map.py`, and rebuild.
"""
import argparse, re, sys, os, struct

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, "..", ".."))
TEXT_LO, TEXT_HI = 0x88070000, 0x88070000 + 0x1DDEA4     # kiniro_normal .text (futari_module_desc.h)
SPLIT_LO, SPLIT_HI = 0x880E1B68, 0x880E1C60              # +8 law split window (PLAN_kiniro_bringup §5.1)
BLR = 0x4E800020

def func_starts(mapping_cpp):
    s = open(mapping_cpp, encoding="utf-8", errors="replace").read()
    return sorted(set(int(x, 16) for x in re.findall(r"\{\s*0x([0-9A-Fa-f]{8}),\s*sub_", s)))

def toml_funcs(path):
    if not os.path.exists(path): return []
    s = open(path, encoding="utf-8").read()
    return [(int(a, 16), int(z, 16)) for a, z in re.findall(r"address\s*=\s*0x([0-9A-Fa-f]+)\s*,\s*size\s*=\s*0x([0-9A-Fa-f]+)", s)]

def targets_from_logs(paths):
    seen = {}
    rx = re.compile(r"UNMAPPED (?:NEW #\d+ )?(?:guest )?target=0x([0-9A-Fa-f]{8}) \(lr=0x([0-9A-Fa-f]{8})\)")
    for p in paths:
        for line in open(p, encoding="utf-8", errors="replace"):
            m = rx.search(line)
            if m:
                t, lr = int(m.group(1), 16), int(m.group(2), 16)
                e = seen.setdefault(t, {"n": 0, "lr": lr})
                e["n"] += 1
    return seen

def first_blr(img, addr, limit=0x4000):
    if img is None: return None
    off = addr - 0x88000000
    for a in range(off, min(off + limit, len(img) - 4), 4):
        if struct.unpack(">I", img[a:a+4])[0] == BLR: return 0x88000000 + a
    return None

def append_rows(path, rows, note):
    s = open(path, encoding="utf-8").read()
    body = "".join(f"    {{ address = 0x{a:08X}, size = 0x{z:X} }},   # {c}\n" for a, z, c in rows)
    if re.search(r"^functions\s*=\s*\[", s, re.M):
        i = s.rindex("]")
        s = s[:i] + body + s[i:]
    else:
        if not s.endswith("\n"): s += "\n"
        s += f"\n# {note}\nfunctions = [\n{body}]\n"
    open(path, "w", encoding="utf-8", newline="\n").write(s)

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("logs", nargs="+")
    ap.add_argument("--mapping", default=os.path.join(ROOT, "out_kiniro", "ppc_func_mapping.cpp"))
    ap.add_argument("--toml", default=os.path.join(ROOT, "config", "futari_kiniro.toml"))
    ap.add_argument("--abn-toml", default=os.path.join(ROOT, "config", "futari_kiniro_abn.toml"))
    ap.add_argument("--img", default=None, help="kiniro_normal flat image (for the blr column)")
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--tag", default="step-3 harvest")
    a = ap.parse_args()

    starts = func_starts(a.mapping)
    known = {x for x, _ in toml_funcs(a.toml)}
    img = open(a.img, "rb").read() if a.img else None
    tg = targets_from_logs(a.logs)
    if not tg:
        print("no UNMAPPED targets in", a.logs); return 0
    import bisect
    new_rows, already, outside, dup = [], [], [], []
    for t in sorted(tg):
        e = tg[t]
        if not (TEXT_LO <= t < TEXT_HI): outside.append(t); continue
        if t in known: dup.append(t); continue
        i = bisect.bisect_right(starts, t)
        if i > 0 and starts[i-1] == t: already.append(t); continue
        nxt = starts[i] if i < len(starts) else TEXT_HI
        size = nxt - t
        blr = first_blr(img, t)
        c = f"{a.tag}: {e['n']} call(s), first lr=0x{e['lr']:08X}, next fn 0x{nxt:08X}" + (f", first blr 0x{blr:08X}" if blr else "")
        new_rows.append((t, size, c))
    print(f"distinct UNMAPPED targets: {len(tg)}  -> NEW functions: {len(new_rows)}  already-function-start: {len(already)}  already-in-toml: {len(dup)}  outside .text: {len(outside)}")
    for t, z, c in new_rows:
        print(f"  NEW   0x{t:08X} size 0x{z:<6X} {c}")
    for t in already: print(f"  START 0x{t:08X}  is a function start already ({tg[t]['n']} calls, lr 0x{tg[t]['lr']:08X}) -> table-slot problem, not a harvest row")
    for t in dup:     print(f"  DUP   0x{t:08X}  already in {os.path.basename(a.toml)}")
    for t in outside: print(f"  OUT   0x{t:08X}  outside kiniro .text ({tg[t]['n']} calls, lr 0x{tg[t]['lr']:08X})")
    if a.apply and new_rows:
        append_rows(a.toml, new_rows, "Black Label step 3: indirect-call-only targets harvested from kiniro_normal boots ([indirect] UNMAPPED)")
        abn_rows, held = [], []
        for t, z, c in new_rows:
            if t >= SPLIT_HI: abn_rows.append((t + 8, z, c + " (+8 law)"))
            elif t < SPLIT_LO: abn_rows.append((t, z, c + " (below split, same address)"))
            else: held.append(t)
        if abn_rows: append_rows(a.abn_toml, abn_rows, "kiniro_abnormal rows ported from futari_kiniro.toml by the +8 law (PLAN_kiniro_bringup §5.1)")
        print(f"APPLIED {len(new_rows)} row(s) to {a.toml}; {len(abn_rows)} ported to {a.abn_toml}" + (f"; {len(held)} inside the split window NOT ported: " + " ".join(f"0x{h:08X}" for h in held) if held else ""))
    return 0

if __name__ == "__main__":
    sys.exit(main())
