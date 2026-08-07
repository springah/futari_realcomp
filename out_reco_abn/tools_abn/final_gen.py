"""Emit futari_switches_abn.toml from the direct scan + the 3 byte-map carry-overs, with
provenance correlation against reco_normal's 57 hand-derived tables."""
import pickle, struct, bisect, re
from collections import Counter
SC = r"C:\Users\shant\AppData\Local\Temp\claude\C--Users-shant-Desktop\63fc654b-54ee-4851-8035-38769b5962ed\scratchpad\abn"
BASE = 0x88000000
NS, AS, gt, gt_inline = pickle.load(open(SC + r"\scan.pkl", "rb"))
nor = open(SC + r"\nor.img.bin", "rb").read()
abn = open(SC + r"\abn.img.bin", "rb").read()
nfn = sorted(int(x, 16) for x in open(SC + r"\nor_funcs.txt"))
afn = sorted(int(x, 16) for x in open(SC + r"\abn_funcs.txt"))
def w(i, a): return struct.unpack(">I", i[a-BASE:a-BASE+4])[0]
def encl(fns, a, end):
    i = bisect.bisect_right(fns, a) - 1
    return fns[i], (fns[i+1] if i+1 < len(fns) else end)

nor_by_base = {t["base"]: t for t in NS}
# fingerprint = (case count, tuple of label offsets relative to enclosing fn start, index reg)
def fp(t): return (len(t["labels"]), tuple(L - t["fs"] for L in t["labels"]), t["r"])
nor_by_fp = {}
for t in NS: nor_by_fp.setdefault(fp(t), []).append(t)

rows = []
for t in sorted(AS, key=lambda x: x["base"]):
    b = t["base"]
    nt = nor_by_base.get(b)
    if nt is not None:
        if nt["labels"] == t["labels"] and nt["r"] == t["r"]:
            tag, note = "SAME-ADDR", f"identical dispatch + identical table (n={len(t['labels'])}) in both modules"
        else:
            tag, note = "SAME-ADDR", (f"same bctr address; table RE-READ from reco_abnormal "
                                      f"(nor n={len(nt['labels'])} r={nt['r']} -> abn n={len(t['labels'])} r={t['r']})")
    else:
        cand = nor_by_fp.get(fp(t), [])
        if cand:
            # several near-clone functions can share a fingerprint (the 11-case r=11 family at
            # 0x88245FF8..0x88248130); break the tie on nearest guest address.
            cand = sorted(cand, key=lambda s: abs(s["base"] - b))
            src = cand[0]
            amb = ("" if len(cand) == 1 else
                   f"; fingerprint shared by {len(cand)} reco_normal tables, paired on nearest address")
            tag = f"SHIFTED-from-0x{src['base']:08X}"
            note = (f"twin fn 0x{src['fs']:08X}->0x{t['fs']:08X} delta={t['fs']-src['fs']:+#x}; "
                    f"relative case-target fingerprint identical (n={len(t['labels'])}){amb}")
        else:
            tag, note = "NEW", ("no reco_normal counterpart by relative fingerprint -- discovered "
                                "directly in reco_abnormal")
    rows.append(dict(t, tag=tag, note=note,
                     name=f"sub_{t['fs']:08X}",
                     cntsrc=("cmplwi bound check n=%d" % t["cnt"]) if t["exact"] else
                            ("no cmplwi in window -- count from the inline dword run (n=%d)" % t["run"])))

# the 3 session-6 byte-map tables: flattened labels, carried over after byte-verifying the fn
BYTEMAP = [
    (0x8807D954, "sub_8807D838", "enclosing fn 0x8807D838..0x8807DCB0 byte-identical (1144B)"),
    (0x8808B424, "sub_8808B330", "enclosing fn 0x8808B330..0x8808BC90 byte-identical (2400B)"),
    (0x88071924, "sub_880714E0", "enclosing fn 0x880714E0..0x88072038 differs in exactly 2 of 726 "
                 "words -- 0x8807156C `addi r11,r11,-0x2980`->`-0x2920` and 0x8807202C "
                 "`stw r3,-0x2880(r11)`->`-0x2820`, both DATA-address immediates (+0x60), neither "
                 "control flow nor inside the dispatch/label region; the 56 case targets are unmoved"),
]
bm_rows = []
for b, nm, why in BYTEMAP:
    r, labs = gt[b]
    afs, afe = encl(afn, b, 0x8824EEB8)
    assert w(abn, b) == 0x4E800420
    assert all(afs <= L < afe for L in labs), nm
    bm_rows.append(dict(base=b, r=r, labels=labs, name=nm, tag="SAME-ADDR",
                        note=f"session-6 byte-map table (labels SDK-flattened, NOT inline dwords); {why}",
                        cntsrc="carried over from futari_switches.toml; bctr present at the same "
                               "address and all 12/16/56 targets revalidated inside the abn function"))

allrows = sorted(rows + bm_rows, key=lambda x: x["base"])
c = Counter(x["tag"].split("-from-")[0] for x in allrows)
print("=== CENSUS (reco_abnormal, %d tables) ===" % len(allrows))
for k, v in sorted(c.items()): print(f"  {k:16s} {v}")
lost = [t for t in NS if t["base"] not in {x["base"] for x in allrows}
        and fp(t) not in {fp(x) for x in rows}]
print(f"\nreco_normal tables with no reco_abnormal counterpart: {len(lost)} "
      f"{[hex(t['base']) for t in lost]}")
print()
for x in allrows:
    print(f"  {x['tag']:26s} 0x{x['base']:08X} r={x['r']:2d} n={len(x['labels']):3d}  {x['name']}")

H = '''# Jump-table overrides for reco_abnormal.xex
#   = Mushihimesama Futari Ver 1.5 "Xbox 360 mode" / MODULE_154_3_HI / modeIdx 1
#     (assets/media/Module/reco_abnormal.xex, ROM Rom\\cg_v154hi.bin).
# Authored 2026-07-30 for out_reco_abn/ (futari_reco_abn.toml).  Sibling of futari_switches.toml
# (reco_normal, 57 hand-derived tables).  Full method + census: _tmpscripts/abn_recomp_notes.md.
#
# XenonRecomp semantics (xr-derisk/XenonRecomp/recompiler.cpp:628-653 and :2466-2470):
#   `base` = guest address of the `bctr`; `labels` is consumed VERBATIM keyed on register `r`
#   (emits `switch (ctx.rN.u64) { case i: goto loc_<labels[i]>; }`) and guest memory is NEVER
#   re-read.  Any label outside the enclosing function is reported as
#   `ERROR: Switch case at X is trying to jump outside function: Y`.  Without an entry the bctr
#   degrades to `PPC_CALL_INDIRECT_FUNC(ctr)` -- i.e. an indirect call through the table's first
#   dword -- and the inline table itself gets decoded as instructions.
#
# DERIVATION -- these are NOT reco_normal's tables re-pointed.  reco_abnormal shares only 28.1%
# of reco_normal's .pdata function starts and 22.4% of its .text words, so signature-porting
# recovers barely a fifth of them.  Instead the tables were discovered DIRECTLY from
# reco_abnormal's raw flat image (ghidra_futari_decomp/xexdump.exe) with this recogniser,
# all constrained to one .pdata function:
#     cmplwi crX, rY, N-1        <- bound check; pins the case COUNT exactly
#     rlwinm rD, rZ, 2, 0, 29    <- index*4; rZ is the register to switch on (same convention as
#                                   futari_switches.toml: "the register literally read by rlwinm",
#                                   cross-checked there against table B / 0x880EC87C SDK truth)
#     mtctr ; bctr
#     <N inline big-endian dwords> at bctr+4, each 4-aligned and inside the same function
#
# POSITIVE CONTROL (this is the reason to trust the list): the identical scanner run against
# reco_normal.xex finds exactly 54 tables and reproduces all 54 of futari_switches.toml's
# inline-dword tables EXACTLY -- same base, same `r`, every label -- with zero misses and zero
# extras.  (The remaining 3 hand-derived reco_normal entries are the session-6 "byte-map"
# tables, whose labels are SDK-flattened and therefore not present as dwords in the image; they
# are carried over separately below, each re-validated against reco_abnormal's image.)
# Scanner + control: scratchpad/abn/scan.py, final_gen.py.
#
# Provenance tags:
#   SAME-ADDR                 the bctr sits at the same guest address in both modules.
#   SHIFTED-from-0x........   paired to a reco_normal table by relative case-target fingerprint
#                             ([label - fn_start] identical case-for-case) at a shifted address.
#   NEW                       no reco_normal counterpart -- reco_abnormal's own table.
# Tags are provenance ANNOTATION only; every entry's data comes from reco_abnormal's own image.
'''
out = [H]
for x in allrows:
    out.append("")
    out.append(f"# {x['name']}  [{x['tag']}]")
    out.append(f"#   {x['note']}")
    out.append(f"#   {x['cntsrc']}")
    out.append("[[switch]]")
    out.append(f"base = 0x{x['base']:08X}")
    out.append(f"r = {x['r']}")
    out.append("labels = [" + ", ".join(f"0x{v:08X}" for v in x["labels"]) + "]")
open(SC + r"\futari_switches_abn.toml", "w").write("\n".join(out) + "\n")
print(f"\nwrote futari_switches_abn.toml: {len(allrows)} tables")
