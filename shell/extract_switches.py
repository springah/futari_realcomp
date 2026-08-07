#!/usr/bin/env python3
"""Extract jump-table switches from rexglue's generated default/ tree and emit
a XenonRecomp switch TOML. Ground truth: rexglue recompiled the same default.xex
and its analyzer detected the jump tables; XenonAnalyse found 0 on Futari.

bctr addresses are computed exactly by forward-scanning each function with an
address counter: each instruction comment ("\t// mnemonic") advances +4, and
absolute anchors reset it: PPC_FUNC(sub_X) headers, "loc_X:" labels, and
"ctx.lr = 0xY;" (the next instruction after a bl is at Y). Inline jump-table
data after a bctr is skipped by rexglue, but the next "loc_X:" label re-anchors.
"""
import re, sys, glob

SRC = "/mnt/c/Users/shant/Desktop/projects/futari_recomp/generated/default"
out = []
anom = []

re_func = re.compile(r"PPC_FUNC(?:_IMPL)?\((?:__imp__)?sub_([0-9A-F]+)\)")
re_loc = re.compile(r"^loc_([0-9A-F]+):")
re_lr = re.compile(r"ctx\.lr = 0x([0-9A-F]+);")
re_instr = re.compile(r"^\t// \S")
re_switch = re.compile(r"switch \(ctx\.r(\d+)\.u32\) \{")
re_case = re.compile(r"case (\d+):")
re_goto = re.compile(r"goto loc_([0-9A-F]+);|^sub_([0-9A-F]+)\(ctx, base\);$")

for path in sorted(glob.glob(SRC + "/*.cpp")):
    lines = open(path, errors="replace").read().splitlines()
    addr = None          # address of the NEXT instruction comment
    i = 0
    while i < len(lines):
        line = lines[i]
        s = line.strip()
        mf = re_func.search(line)
        if mf and "PPC_EXTERN" not in line and "WEAK" not in line:
            addr = int(mf.group(1), 16)
            i += 1
            continue
        ml = re_loc.match(s)
        if ml:
            addr = int(ml.group(1), 16)
            i += 1
            continue
        mr = re_lr.search(line)
        if mr:
            addr = int(mr.group(1), 16)
            i += 1
            continue
        if re_instr.match(line):
            this_addr = addr
            if addr is not None:
                addr += 4
            if s == "// bctr" and i + 1 < len(lines):
                m = re_switch.search(lines[i + 1])
                if m:
                    reg = int(m.group(1))
                    j = i + 2
                    cases = {}
                    cur = None
                    while j < len(lines):
                        t = lines[j].strip()
                        if t == "}":
                            break
                        mc = re_case.match(t)
                        if mc:
                            cur = int(mc.group(1))
                        else:
                            mg = re_goto.search(t)
                            if mg and cur is not None:
                                cases[cur] = int(mg.group(1) or mg.group(2), 16)
                                cur = None
                        j += 1
                    n = len(cases)
                    dense = n > 0 and sorted(cases.keys()) == list(range(n))
                    if this_addr is None:
                        anom.append(f"{path}:{i+1} r{reg} n={n} NO-ANCHOR")
                    elif not dense:
                        anom.append(f"{path}:{i+1} r{reg} SPARSE cases={sorted(cases.keys())} base=0x{this_addr:08X}")
                    else:
                        out.append((this_addr, reg, [cases[c] for c in range(n)]))
                    i = j
        i += 1

# Switches whose case targets are all standalone function entries dispatch fine
# at runtime via the indirect table — a TOML entry would ERROR-return on the
# targets outside the enclosing function. 0x8219D540's targets are separate
# sub_* funcs (plus 0x8219D5E0, added as a manual function in shell.toml).
SKIP = {0x8219D540}
out = [o for o in out if o[0] not in SKIP]
out.sort()
dedup = {}
for base, reg, labels in out:
    if base in dedup and dedup[base] != (reg, labels):
        anom.append(f"CONFLICT at 0x{base:08X}")
    dedup[base] = (reg, labels)
with open(sys.argv[1] if len(sys.argv) > 1 else "shell_switches.toml", "w") as f:
    for base in sorted(dedup):
        reg, labels = dedup[base]
        f.write("[[switch]]\n")
        f.write(f"base = 0x{base:08X}\n")
        f.write(f"r = {reg}\n")
        f.write("labels = [" + ", ".join(f"0x{x:08X}" for x in labels) + "]\n\n")
print(f"switches: {len(dedup)}, anomalies: {len(anom)}")
for a in anom:
    print("ANOM:", a)
known = [(b, v) for b, v in dedup.items() if 0x820A1E5C in v[1]]
print("contains 0x820A1E5C:", [(hex(b), f"r{v[0]}", len(v[1])) for b, v in known])
print("0x820CB1C0 present:", 0x820CB1C0 in dedup, "| 0x820CB1EC present:", 0x820CB1EC in dedup)
