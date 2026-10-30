#!/usr/bin/env python3
"""Jump-table recogniser for a futari game module's flat image -> XenonRecomp [[switch]] toml.

This is out_reco_abn/tools_abn/scan.py (the 2026-07-30 recogniser that produced futari_switches_abn.toml),
ported to the Mac and parametrised, PLUS a decoder for the session-6 "byte-map" dispatch shape that abn could only
carry over by hand (labels SDK-flattened, not inline dwords). Both recognisers are positive-controlled: run with
--control and they must reproduce config/futari_switches.toml (reco_normal, 57) and config/futari_switches_abn.toml
(reco_abnormal, 57) EXACTLY -- every base, every `r`, every label -- or the script exits non-zero.

  INLINE   (scan.py, same logic): all inside one .pdata function
               cmplwi crX,rY,N-1 ... rlwinm rD,rZ,2,0,29 ... mtctr ; bctr ; <N inline BE dwords at bctr+4>
           r = rZ (the register literally read by rlwinm -- futari_switches.toml's convention)
  BYTEMAP  (new): cmplwi crX,rY,N-1 ; bgt ; lis/addi rM=map ; [rlwinm rI,rY,1,0,30] ; lbzx|lhzx rT,rM,rI ;
               [rlwinm rT,rT,2,0,29] ; lis/addi rB=base ; add rC,rB,rT ; mtctr rC ; bctr
           label[i] = base + map[i] (x4 when the loaded value is scaled); r = rY (the BOUND-CHECK register,
           futari_switches.toml's session-6 convention for these tables)

Every other bctr is classified (census()) so the unresolved ones are listed, never silently dropped.

usage:  scan_switches.py --img X.img.bin --module NAME --out out.toml [--fp-ref reco_normal.img.bin]
        scan_switches.py --control --imgdir DIR --config DIR       (positive control on the reco pair)
"""
import argparse, os, re, sys
from collections import Counter
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ppcmini import Img, dec, BCTR


def scan_inline(im, back=48):
    TB, TE = im.text
    out = []
    for a in range(TB, TE, 4):
        if im.w(a) != BCTR:
            continue
        fs, fe = im.encl(a)
        if fs is None:
            continue
        run = 0
        while True:
            p = a + 4 + 4 * run
            if p + 4 > fe:
                break
            v = im.w(p)
            if v % 4 or not (fs <= v < fe):
                break
            run += 1
        if run < 2:
            continue
        cnt = None
        reg = None
        for k in range(1, back + 1):
            p = a - 4 * k
            if p < fs:
                break
            x = im.w(p)
            op = x >> 26
            if reg is None and op == 21:
                sh = (x >> 11) & 31
                mb = (x >> 6) & 31
                me = (x >> 1) & 31
                if sh == 2 and mb == 0 and me == 29:
                    reg = (x >> 21) & 31
            if cnt is None and op == 10 and ((x >> 21) & 1) == 0:
                cnt = (x & 0xFFFF) + 1
        if reg is None:
            continue
        n = cnt if (cnt is not None and 2 <= cnt <= run) else run
        note = ("cmplwi bound check n=%d" % cnt) if (cnt is not None and cnt <= run) else \
            ("no cmplwi in window -- count from the inline dword run (n=%d)" % run)
        out.append(dict(kind="INLINE", base=a, r=reg, labels=[im.w(a + 4 + 4 * i) for i in range(n)],
                        fs=fs, fe=fe, note=note))
    return out


def decode_bytemap(im, a, back=24):
    """Symbolically execute the straight-line window [cmplwi .. bctr] that ends at the bctr at a.
    Returns (table, None) or (None, reason)."""
    fs, fe = im.encl(a)
    if fs is None:
        return None, "no enclosing fn"
    start = None
    for k in range(1, back + 1):
        p = a - 4 * k
        if p < fs:
            break
        if dec(im.w(p))[0] == "cmplwi":
            start = p
            break
    if start is None:
        return None, "no cmplwi in window"
    _, f = dec(im.w(start))
    idx, n = f["ra"], f["ui"] + 1
    R = {idx: ("idx",)}
    for p in range(start + 4, a, 4):
        m, f = dec(im.w(p))
        if m == "bc":
            continue
        if m == "ori" and f["ra"] == 0 and f["rs"] == 0 and f["ui"] == 0:
            continue  # nop
        if m == "lis":
            R[f["rt"]] = ("c", (f["si"] << 16) & 0xFFFFFFFF)
            continue
        if m == "addi" and R.get(f["ra"], ("?",))[0] == "c":
            R[f["rt"]] = ("c", (R[f["ra"]][1] + f["si"]) & 0xFFFFFFFF)
            continue
        if m == "rlwinm":
            s = R.get(f["rs"], ("?",))
            if s[0] == "idx" and (f["sh"], f["mb"], f["me"]) == (1, 0, 30):
                R[f["ra"]] = ("idx2",)
                continue
            if s[0] == "ld" and (f["sh"], f["mb"], f["me"]) == (2, 0, 29):
                R[f["ra"]] = ("ld", s[1], s[2], 4)
                continue
            return None, "unexpected rlwinm @0x%08X" % p
        if m in ("lbzx", "lhzx"):
            ra, rb = R.get(f["ra"], ("?",)), R.get(f["rb"], ("?",))
            if ra[0] != "c":
                ra, rb = rb, ra
            want = "idx" if m == "lbzx" else "idx2"
            if ra[0] == "c" and rb[0] == want:
                R[f["rt"]] = ("ld", ra[1], 1 if m == "lbzx" else 2, 1)
                continue
            return None, "unexpected %s @0x%08X" % (m, p)
        if m == "add":
            ra, rb = R.get(f["ra"], ("?",)), R.get(f["rb"], ("?",))
            if ra[0] != "c":
                ra, rb = rb, ra
            if ra[0] == "c" and rb[0] == "ld":
                R[f["rt"]] = ("tgt", ra[1], rb[1], rb[2], rb[3])
                continue
            return None, "unexpected add @0x%08X" % p
        if m == "mtctr":
            t = R.get(f["rs"], ("?",))
            if t[0] != "tgt":
                return None, "mtctr of a non-table value @0x%08X" % p
            _, base, mp, width, scale = t
            labels = []
            for i in range(n):
                off = mp + i * width
                v = im.w(off & ~3)
                if width == 1:
                    v = (v >> (8 * (3 - (off & 3)))) & 0xFF
                else:
                    v = (v >> (8 * (2 - (off & 2)))) & 0xFFFF
                labels.append((base + v * scale) & 0xFFFFFFFF)
            if not all(fs <= L < fe and L % 4 == 0 for L in labels):
                return None, "decoded label outside the enclosing fn"
            note = "byte-map dispatch: %s map @0x%08X, base 0x%08X%s, cmplwi n=%d" % (
                "lbzx u8" if width == 1 else "lhzx u16", mp, base, " x4" if scale == 4 else "", n)
            return dict(kind="BYTEMAP", base=a, r=idx, labels=labels, fs=fs, fe=fe, note=note), None
        return None, "unhandled %s @0x%08X between cmplwi and bctr" % (m, p)
    return None, "cmplwi found but no mtctr before the bctr"


def ctr_source(im, a):
    """For a bctr that is not a table: what loaded ctr? (classification only)"""
    fs, _ = im.encl(a)
    for k in range(1, 12):
        p = a - 4 * k
        if fs is None or p < fs:
            break
        m, f = dec(im.w(p))
        if m == "mtctr":
            src = f["rs"]
            for j in range(k + 1, k + 16):
                q = a - 4 * j
                if q < fs:
                    break
                x = im.w(q)
                op = x >> 26
                if op in (32, 58) and ((x >> 21) & 31) == src:
                    return "indirect: ctr <- lwz/ld (fn pointer / vtable slot)"
                if op == 31 and ((x >> 1) & 0x3FF) in (23, 21) and ((x >> 21) & 31) == src:
                    return "indirect: ctr <- lwzx/ldx (fn-pointer table)"
                md, fd = dec(x)
                if md == "rlwinm" and fd["ra"] == src and (fd["sh"], fd["mb"], fd["me"]) == (0, 0, 31):
                    src = fd["rs"]          # clrlwi rX,rY,0 (32-bit mask of a loaded pointer): keep tracing
                    continue
                if md == "or" and fd["ra"] == src and fd["rs"] == fd["rb"]:
                    src = fd["rs"]          # mr: keep tracing
                    continue
                if md in ("add", "addi", "lis", "rlwinm", "ori") and fd.get("rt", fd.get("ra")) == src:
                    return "computed: ctr <- arithmetic"
            return "indirect: ctr source outside window (register argument)"
    return "no mtctr in window"


def census(im):
    inline = scan_inline(im)
    have = {t["base"] for t in inline}
    tables = list(inline)
    other = Counter()
    unresolved = []
    TB, TE = im.text
    for a in range(TB, TE, 4):
        if im.w(a) != BCTR or a in have:
            continue
        t, why = decode_bytemap(im, a)
        if t:
            tables.append(t)
            continue
        src = ctr_source(im, a)
        if src.startswith("computed"):
            # a computed jump target that neither recogniser resolved = a suspect switch
            unresolved.append((a, src, why))
        else:
            other[src] += 1
    return sorted(tables, key=lambda t: t["base"]), other, unresolved


def parse_toml(path):
    out = {}
    pat = r"\[\[switch\]\]\s*\nbase = (0x[0-9A-Fa-f]+)\s*\nr = (\d+)\s*\nlabels = \[([^\]]*)\]"
    for m in re.finditer(pat, open(path).read()):
        b, r, labs = m.groups()
        out[int(b, 16)] = (int(r), [int(x, 16) for x in re.findall(r"0x[0-9A-Fa-f]+", labs)])
    return out


def compare(tables, truth):
    got = {t["base"]: (t["r"], t["labels"]) for t in tables}
    exact = sum(1 for b in truth if got.get(b) == truth[b])
    miss = sorted(b for b in truth if b not in got)
    bad = sorted(b for b in truth if b in got and got[b] != truth[b])
    extra = sorted(b for b in got if b not in truth)
    return exact, miss, bad, extra


def fp(t):
    return (len(t["labels"]), tuple(L - t["fs"] for L in t["labels"]), t["r"], t["kind"])


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--control", action="store_true")
    ap.add_argument("--imgdir")
    ap.add_argument("--config")
    ap.add_argument("--img")
    ap.add_argument("--module")
    ap.add_argument("--out")
    ap.add_argument("--fp-ref")
    a = ap.parse_args()
    if a.control:
        ok = True
        for mod, toml in (("reco_normal", "futari_switches.toml"), ("reco_abnormal", "futari_switches_abn.toml")):
            im = Img(os.path.join(a.imgdir, mod + ".img.bin"))
            tables, other, unres = census(im)
            truth = parse_toml(os.path.join(a.config, toml))
            exact, miss, bad, extra = compare(tables, truth)
            k = Counter(t["kind"] for t in tables)
            print(f"CONTROL {mod}: found {len(tables)} {dict(k)} vs {toml} {len(truth)}: exact {exact}, "
                  f"missed {[hex(x) for x in miss]}, mismatched {[hex(x) for x in bad]}, extra {[hex(x) for x in extra]}")
            print(f"        other bctr: {dict(other)}")
            print(f"        unresolved switch-shaped: {[(hex(x), y, z) for x, y, z in unres]}")
            ok &= (exact == len(truth) and not extra and not miss and not bad)
        print("POSITIVE CONTROL", "PASS" if ok else "FAIL")
        sys.exit(0 if ok else 1)

    im = Img(a.img)
    tables, other, unres = census(im)
    refb, ref = {}, {}
    if a.fp_ref:
        ri = Img(a.fp_ref)
        rt, _, _ = census(ri)
        for t in rt:
            ref.setdefault(fp(t), []).append(t)
        refb = {t["base"]: t for t in rt}
    k = Counter(t["kind"] for t in tables)
    print(f"{a.module}: {len(tables)} tables {dict(k)}; other bctr {dict(other)}; unresolved switch-shaped {len(unres)}")
    for x, y, z in unres:
        print(f"  UNRESOLVED 0x{x:08X}: {y}; {z}")
    prov = Counter()
    rows = []
    for t in tables:
        tag = "NEW"
        rb = refb.get(t["base"])
        if rb and rb["labels"] == t["labels"] and rb["r"] == t["r"]:
            tag = "SAME-AS-RECO"
        elif fp(t) in ref:
            c = sorted(ref[fp(t)], key=lambda s: abs(s["base"] - t["base"]))[0]
            tag = f"FP-reco-0x{c['base']:08X} ({t['base'] - c['base']:+#x})"
        prov[tag.split("-0x")[0]] += 1
        rows.append((t, tag))
    if ref:
        print("  provenance vs reco_normal:", dict(prov))
    kinds = ", ".join(f"{v} {k_}" for k_, v in sorted(k.items()))
    H = [f"# Jump-table overrides for {a.module}.xex -- GENERATED by out_kiniro/tools_kiniro/scan_switches.py; do not hand-edit.",
         "#   (scripts/regen_kiniro_mac.sh step 2; method + positive control: docs/PLAN_kiniro_bringup.md)",
         "# Every entry is read from THIS module's own flat image (out_kiniro/tools_kiniro/xexflat). Recognisers:",
         "#   INLINE  = abn's scan.py (cmplwi .. rlwinm rZ,2,0,29 .. mtctr; bctr; N inline dwords); r = the rlwinm source reg",
         "#   BYTEMAP = cmplwi rY; lbzx|lhzx map; [x4]; add base; mtctr; bctr; label[i] = base + map[i]*scale; r = rY",
         "# Positive control (--control): both reproduce futari_switches.toml (57) and futari_switches_abn.toml (57) exactly.",
         f"# Count: {len(tables)} tables ({kinds}); unresolved switch-shaped bctr: {len(unres)}.",
         "# Provenance tag (annotation only): SAME-AS-RECO = identical bctr address, r and labels in reco_normal;",
         "#   FP-reco-0x... = a reco_normal table with the identical relative case-target fingerprint elsewhere; NEW = neither.",
         ""]
    for t, tag in rows:
        H += [f"# sub_{t['fs']:08X}  [{t['kind']}] [{tag}]", f"#   {t['note']}", "[[switch]]",
              f"base = 0x{t['base']:08X}", f"r = {t['r']}",
              "labels = [" + ", ".join(f"0x{v:08X}" for v in t["labels"]) + "]", ""]
    open(a.out, "w").write("\n".join(H))
    print(f"  wrote {a.out}")


if __name__ == "__main__":
    main()
