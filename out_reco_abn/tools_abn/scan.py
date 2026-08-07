"""DIRECT jump-table discovery from a raw XEX flat image, positive-controlled on reco_normal.

Rather than trying to "port" reco_normal's 57 hand-derived tables onto reco_abnormal by
signature matching (which fails for most of them -- the twins' internal layouts differ, hence
only 22% word identity), discover reco_abnormal's OWN tables the same way the original leg
discovered reco_normal's, but from the raw image instead of from mis-decoded generated source.

Recogniser (all inside one .pdata function):
    cmplwi crX, rY, N-1          <- bound check: pins the case COUNT exactly
    ...
    rlwinm rD, rZ, 2, 0, 29      <- index*4 ; rZ is the register XenonRecomp must switch on
    ...                             (per futari_switches.toml's header: "the register literally
    ...                              read by rlwinm", cross-checked on table B/0x880EC87C)
    mtctr / bctr                 <- the dispatch
    <N inline big-endian dwords>  at bctr+4, each 4-aligned and inside the same function

POSITIVE CONTROL: run on reco_normal and require exact reproduction of the 54 inline-dword
tables in futari_switches.toml (base, r, and every label).
"""
import re, struct, sys, bisect
SC = r"C:\Users\shant\AppData\Local\Temp\claude\C--Users-shant-Desktop\63fc654b-54ee-4851-8035-38769b5962ed\scratchpad\abn"
BASE = 0x88000000
BCTR = 0x4E800420

def load(tag, tend):
    img = open(f"{SC}\\{tag}.img.bin", "rb").read()
    fns = sorted(int(x, 16) for x in open(f"{SC}\\{tag}_funcs.txt"))
    return img, fns, tend

def w(img, a): return struct.unpack(">I", img[a-BASE:a-BASE+4])[0]

def encl(fns, a, end):
    i = bisect.bisect_right(fns, a) - 1
    if i < 0: return None, None
    return fns[i], (fns[i+1] if i+1 < len(fns) else end)

def scan(img, fns, TB, TE, back=48):
    out = []
    for a in range(TB, TE, 4):
        if w(img, a) != BCTR:
            continue
        fs, fe = encl(fns, a, TE)
        if fs is None:
            continue
        # inline dword run at a+4, constrained to the enclosing function
        run = 0
        while True:
            p = a + 4 + 4*run
            if p + 4 > fe:
                break
            v = w(img, p)
            if v % 4 or not (fs <= v < fe):
                break
            run += 1
        if run < 2:
            continue                      # bare bctr: indirect call, or a byte-map dispatch
        # walk back for the bound check and the index scaler
        cnt = None; reg = None
        for k in range(1, back + 1):
            p = a - 4*k
            if p < fs:
                break
            x = w(img, p)
            op = x >> 26
            if reg is None and op == 21:                      # rlwinm rA,rS,SH,MB,ME
                sh = (x >> 11) & 31; mb = (x >> 6) & 31; me = (x >> 1) & 31
                if sh == 2 and mb == 0 and me == 29:
                    reg = (x >> 21) & 31                      # rS = the index register
            if cnt is None and op == 10 and ((x >> 21) & 1) == 0:   # cmplwi crf, rA, UIMM
                cnt = (x & 0xFFFF) + 1
        if reg is None:
            continue
        n = cnt if (cnt is not None and 2 <= cnt <= run) else run
        labels = [w(img, a + 4 + 4*i) for i in range(n)]
        out.append(dict(base=a, r=reg, labels=labels, fs=fs, fe=fe,
                        run=run, cnt=cnt, exact=(cnt is not None and cnt <= run)))
    return out

# ---------- ground truth from the hand-derived toml ----------
TOMLP = r"C:\Users\shant\Desktop\projects\futari_realcomp\xr-work\futari_switches.toml"
gt = {}
for m in re.finditer(r"\[\[switch\]\]\s*\nbase = (0x[0-9A-Fa-f]+)\s*\nr = (\d+)\s*\nlabels = \[([^\]]*)\]",
                     open(TOMLP).read(), re.M):
    b, r, labs = m.groups()
    gt[int(b, 16)] = (int(r), [int(x, 16) for x in re.findall(r"0x[0-9A-Fa-f]+", labs)])

nor, nfn, _ = load("nor", 0x8824EEB0)
abn, afn, _ = load("abn", 0x8824EEB8)
NS = scan(nor, nfn, 0x88070000, 0x8824EEB0)
AS = scan(abn, afn, 0x88070000, 0x8824EEB8)

print(f"reco_normal   : {len(NS)} inline jump tables discovered")
print(f"reco_abnormal : {len(AS)} inline jump tables discovered")

# ---------- POSITIVE CONTROL ----------
found = {t["base"]: t for t in NS}
gt_inline = {b: v for b, v in gt.items()
             if [w(nor, b + 4 + 4*i) for i in range(len(v[1]))] == v[1]}
print(f"\n=== POSITIVE CONTROL vs futari_switches.toml ({len(gt_inline)} inline hand-derived tables) ===")
miss = [b for b in gt_inline if b not in found]
bad  = []
for b, (r, labs) in gt_inline.items():
    if b in found:
        f = found[b]
        if f["r"] != r or f["labels"] != labs:
            bad.append((b, r, f["r"], len(labs), len(f["labels"])))
extra = [b for b in found if b not in gt]
print(f"  reproduced exactly : {len(gt_inline) - len(miss) - len(bad)}/{len(gt_inline)}")
print(f"  missed             : {[hex(x) for x in sorted(miss)]}")
print(f"  mismatched         : {[(hex(b), 'r', rg, rf, 'n', ng, nf) for b, rg, rf, ng, nf in bad]}")
print(f"  extra (not in hand-derived toml): {len(extra)} -> {[hex(x) for x in sorted(extra)]}")
for b in sorted(extra):
    f = found[b]
    print(f"      0x{b:08X} fn 0x{f['fs']:08X} r={f['r']} n={len(f['labels'])} run={f['run']} cnt={f['cnt']}")

import pickle
pickle.dump((NS, AS, gt, gt_inline), open(SC + r"\scan.pkl", "wb"))
