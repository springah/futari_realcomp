#!/usr/bin/env python3
"""ppcmatch — verify hand-written C++ against the original PPC bytes.

Compiles a source with the period-correct XDK 9328 PowerPC compiler, pulls the named
function out of the resulting COFF, and compares it byte-for-byte with the bytes at the
function's guest address in the module image.

    python matchlab/ppcmatch.py                  verify every target
    python matchlab/ppcmatch.py --diff NAME      side-by-side for one target
    python matchlab/ppcmatch.py --sweep NAME     flag matrix for one target
    python matchlab/ppcmatch.py --selftest       prove the harness rejects known decoys

⚠ READ THIS BEFORE TRUSTING A VERDICT. An adversarial review on 2026-08-04 made the first
version of this script emit TWO FALSE `EXACT`s, so the extraction rules below are deliberate:

  * Extent is NOT "up to the first blr". 0x820AC018 has four unconditional blrs (early
    returns) in a 25-instruction body; the first-blr rule reported 4 instructions and then
    certified a 4-instruction garbage stub as EXACT. 13-15%% of blrs in these modules are
    interior. Extent is now "to the first padding word, bounded by the next known function
    start", cross-checked against the declared `insn`.
  * Symbol lookup is NOT a substring match. `want in name` graded a helper called
    `Task_Kill_reference`, and — worse — graded a `const u32 Task_Kill_golden[]` DATA array
    holding hand-typed expected words. Lookup is now exact-anchored, requires the symbol be
    a FUNCTION in a CODE section, and hard-errors when more than one candidate survives.
  * `insn` is NOT authoritative on its own. It is reconciled against the independently
    derived extent; disagreement is a loud failure, never a silent truncation.

`--selftest` re-runs those exact decoys. Run it after touching this file.
"""
import argparse, bisect, hashlib, json, os, re, struct, subprocess, sys

HERE   = os.path.dirname(os.path.abspath(__file__))
XR     = os.path.dirname(HERE)                       # xr-work/
GHIDRA = os.path.join(os.path.dirname(XR), "ghidra_futari_decomp")
# XDK 9328's cl 15.00.8327 for PowerPC -- the build the XEX names, and the one all ASM-EXACT
# targets were matched with.  MATCHLAB_CL overrides it so a different compiler build can be
# tested without editing the harness (9328 also ships 15.00.8153 as xdk9328_ship/cl.exe).
CL     = os.environ.get("MATCHLAB_CL", r"C:\Users\shant\Desktop\projects\_tools\xdk\xdk9328\raw\cl.exe")   # README: re-extraction
BLR    = 0x4E800020                                  # blr, unconditional

# The REAL XDK 9328 Xbox headers, so a source can `#include <d3d9.h>` instead of
# hand-reproducing an inline and hoping. Only added when the tree is present, so the harness
# still works on a machine that only has the flattened cl.exe extraction.
#
# WARNING: THE FLATTENED EXTRACTION IN README ("7z e") IS LOSSY AND CANNOT PROVIDE THESE.
# "7z e" drops every directory, so same-named files from different directories COLLIDE: the XDK
# ships BOTH include/win32/vs2005/xnamath.h and include/xbox/xnamath.h, and the flattened copy
# kept the WINDOWS one, which #errors out on a PowerPC build. Re-extract with 7z x (paths
# preserved). ObjBase.h is a Platform-SDK header the XDK assumes but does not ship; the compat
# dir forwards it to the Xbox xobjbase.h.
_XDK_TREE   = "C:/Users/shant/Desktop/projects/_tools/xdk/xdk9328/tree/XDK/include/xbox"
_XDK_COMPAT = "C:/Users/shant/Desktop/projects/_tools/xdk/xdk9328/compat"
XDK_INCLUDES = (["/I" + _XDK_COMPAT, "/I" + _XDK_TREE]
                if os.path.isdir(_XDK_TREE) else [])

# module -> (image file, load base, function-start list)
IMAGES = {
    "shell": (os.path.join(GHIDRA, "default.img.bin"),     0x82000000,
              os.path.join(GHIDRA, "shell_funcs.txt")),
    "game":  (os.path.join(GHIDRA, "reco_normal.img.bin"), 0x88000000,
              os.path.join(GHIDRA, "reco_normal_funcs.txt")),
}

IMAGE_SCN_CNT_CODE  = 0x00000020
IMAGE_SCN_LNK_COMDAT = 0x00001000
SYM_DTYPE_FUNCTION  = 0x20

FLAG_MATRIX = [
    ["-O2"], ["-Ox"], ["-O1"], ["-Od"],
    ["-O2", "-Ob1"], ["-O2", "-Ob0"], ["-Ox", "-GS-"], ["-Ox", "-GS-", "-Gy"],
    ["-O2", "-Oy-"], ["-O2", "-Oi-"], ["-Os"], ["-Ot"],
]

_funcs_cache = {}


class MatchError(Exception):
    pass


def die(msg):
    print("ERROR:", msg, file=sys.stderr)
    sys.exit(1)


BCTR = 0x4E800420   # bctr — unconditional indirect tail call (the msg-sender idiom)


def is_terminal(word):
    """A word that can end a function body.

    blr, bctr (indirect tail call — `return obj->GameEntry(msg, arg)`), or an
    unconditional relative branch (opcode 18, LK=0 — a direct tail call).
    """
    return word in (BLR, BCTR) or ((word >> 26) == 18 and not (word & 1))


# COFF relocation types we know how to neutralise, and the bits each one patches.
# A relocated word cannot be compared byte-for-byte: in our .obj the target field is a
# placeholder the linker would fill, while the image holds a resolved offset. We compare
# everything EXCEPT those bits, and report the guest target so a human can audit it.
REL_MASKS = {
    0x0003: 0x03FFFFFC,   # IMAGE_REL_PPC_ADDR24 — LI field
    0x0006: 0x03FFFFFC,   # IMAGE_REL_PPC_REL24  — LI field (bl)
    0x0005: 0x0000FFFC,   # IMAGE_REL_PPC_ADDR14 — BD field
    0x0007: 0x0000FFFC,   # IMAGE_REL_PPC_REL14  — BD field
    0x0002: 0xFFFFFFFF,   # IMAGE_REL_PPC_ADDR32 — whole word
    0x0008: 0x0000FFFF,   # IMAGE_REL_PPC_TOCREL16
    0x0004: 0x0000FFFF,   # IMAGE_REL_PPC_ADDR16
    0x0010: 0x0000FFFF,   # IMAGE_REL_PPC_REFHI  — high half of an address (lis)
    0x0011: 0x0000FFFF,   # IMAGE_REL_PPC_REFLO  — low half  of an address (lwz/addi)
}
REL_PAIR = 0x0012         # IMAGE_REL_PPC_PAIR — carries an addend, patches no instruction


def func_starts(module):
    if module not in _funcs_cache:
        _, _, path = IMAGES[module]
        if os.path.exists(path):
            _funcs_cache[module] = sorted(
                int(l.strip(), 16) for l in open(path) if l.strip().startswith("0x"))
        else:
            _funcs_cache[module] = []
    return _funcs_cache[module]


def original_bytes(module, addr, declared=None):
    """Instruction bytes of the function at `addr`.

    Extent = from `addr` to the FIRST padding word (0x00000000), bounded by the next known
    function start. Never "to the first blr" — interior blrs are common (see module docstring).
    If `declared` (functions.json "insn") is given it must agree exactly.
    """
    if module not in IMAGES:
        raise MatchError(f"unknown module {module!r}")
    path, base, _ = IMAGES[module]
    if not os.path.exists(path):
        raise MatchError(f"module image missing: {path}")
    d = open(path, "rb").read()
    off = addr - base
    if not 0 <= off < len(d):
        raise MatchError(f"{addr:#x} outside the {module} image")

    starts = func_starts(module)
    i = bisect.bisect_right(starts, addr)
    boundary = starts[i] if i < len(starts) else None
    limit = (boundary - addr) // 4 if boundary else (len(d) - off) // 4
    limit = max(0, min(limit, (len(d) - off) // 4))

    n = 0
    while n < limit:
        w = int.from_bytes(d[off + n * 4: off + n * 4 + 4], "big")
        if w == 0:                       # padding run ends the function
            break
        n += 1
    if n == 0:
        raise MatchError(f"{addr:#x}: derived a zero-length function "
                         f"(padding at entry?) — check the address")

    last = int.from_bytes(d[off + (n - 1) * 4: off + n * 4], "big")
    if not is_terminal(last):
        raise MatchError(
            f"{addr:#x}: derived extent {n} does not end in blr/tail (last={last:#010x}). "
            f"Next known function start = "
            f"{boundary:#x} — the boundary table may be missing an entry here.")

    original_bytes.last_note = ""
    if declared is not None and declared != n:
        # The boundary table (.pdata) has no entry for LEAF functions, so a leaf sitting
        # immediately after this one makes the derived extent over-run. A declared extent may
        # override that, but ONLY with independent proof that a new function starts there:
        #   (a) the declared slice must end in blr/bctr/tail, and
        #   (b) the address right after it must be REFERENCED from elsewhere in the image
        #       (a branch target, or a code pointer stored in any section).
        # (b) is what keeps this from re-opening the interior-blr hole: at 0x820AC018 the
        # interior returns are at +4/+9/+14 and NONE of those addresses is referenced, so a
        # bogus override is still refused.
        if declared <= 0 or declared > n:
            raise MatchError(f"{addr:#x}: declared insn={declared} is outside the derived "
                             f"extent {n} — refusing.")
        last_decl = int.from_bytes(d[off + (declared - 1) * 4: off + declared * 4], "big")
        split_at = addr + declared * 4
        if not is_terminal(last_decl):
            raise MatchError(f"{addr:#x}: declared insn={declared} does not end in blr/bctr/tail "
                             f"(last={last_decl:#010x}); image derives {n}.")
        if split_at in referenced_addrs(module):
            original_bytes.last_note = f"split-REFERENCED at {split_at:#x} (derived {n})"
        elif tail_unreachable(d, base, addr, declared, n):
            # Second, independent proof: nothing in [0,declared) can branch into the tail, so
            # the extra words cannot be part of THIS function's behaviour and no trailing
            # difference can hide there. Checked against the 0x820AC018 decoy at BOTH plausible
            # truncations (4 and 14) — each has a branch into its tail and is refused.
            original_bytes.last_note = f"split-UNREACHABLE tail after {declared} (derived {n})"
        else:
            raise MatchError(
                f"{addr:#x}: declared insn={declared} but the image derives {n}. "
                f"{split_at:#x} is not referenced anywhere AND the tail is reachable from this "
                f"function, so this would be an unproven truncation. Refusing.")
        n = declared

    return d[off: off + n * 4]


original_bytes.last_note = ""
_refs_cache = {}


def tail_unreachable(d, base, addr, declared, derived):
    """True when no instruction in [0,declared) can transfer control into [declared,derived).

    Sound because the guard is on the FUNCTION'S OWN control flow, not on outside evidence:
    if nothing inside the declared body branches into the tail, the tail cannot be part of this
    function's behaviour and no trailing difference can hide there. An interior computed branch
    (bctr/bctrl anywhere but the final slot) makes the CFG incomplete, so we refuse rather than
    guess. Validated against the 0x820AC018 decoy at both plausible truncations.
    """
    lo = addr + declared * 4
    hi = addr + derived * 4
    for i in range(declared):
        w = int.from_bytes(d[addr - base + i * 4: addr - base + i * 4 + 4], "big")
        op = w >> 26
        if op in (16, 18):
            if op == 18:
                off = w & 0x03FFFFFC
                if off & 0x02000000:
                    off -= 0x04000000
            else:
                off = w & 0xFFFC
                if off & 0x8000:
                    off -= 0x10000
            tgt = off if (w & 2) else addr + i * 4 + off
            if lo <= tgt < hi:
                return False
        elif w in (0x4E800420, 0x4E800421) and i < declared - 1:
            return False
    return True


def referenced_addrs(module):
    """Addresses in .text that something else points at: branch targets plus any 4-aligned
    word anywhere in the image that lands inside .text (vtables, state tables, jump tables).

    Used only to CORROBORATE a declared extent — never to shorten one on its own.
    """
    if module in _refs_cache:
        return _refs_cache[module]
    path, base, _ = IMAGES[module]
    d = open(path, "rb").read()
    pe, = struct.unpack_from("<I", d, 0x3C)
    nsec, = struct.unpack_from("<H", d, pe + 6)
    opt,  = struct.unpack_from("<H", d, pe + 20)
    p = pe + 24 + opt
    secs, text = [], None
    for _ in range(nsec):
        nm = d[p:p + 8].rstrip(b"\0").decode("ascii", "replace")
        vsz, va, rawsz, rawptr = struct.unpack_from("<IIII", d, p + 8)
        secs.append((va, vsz, rawptr, rawsz))
        if nm == ".text":
            text = (va, vsz)
        p += 40
    refs = set()
    if text:
        lo, hi = base + text[0], base + text[0] + text[1]
        for o in range(text[0], min(text[0] + text[1], len(d)) - 3, 4):
            w = int.from_bytes(d[o:o + 4], "big")
            if (w >> 26) == 18:                       # b / bl, absolute or relative
                li = w & 0x03FFFFFC
                if li & 0x02000000:
                    li -= 0x04000000
                refs.add(base + o + li)
        for va, vsz, rawptr, rawsz in secs:           # code pointers held in data
            for o in range(rawptr, min(rawptr + rawsz, len(d)) - 3, 4):
                w = int.from_bytes(d[o:o + 4], "big")
                if lo <= w < hi and not (w & 3):
                    refs.add(w)
    _refs_cache[module] = refs
    return refs


def coff_function(path, want):
    """Instruction bytes of FUNCTION symbol `want` in a COFF .obj.

    Exact-anchored name match, must be a function symbol in a code section, and exactly one
    candidate must survive. Extent comes from the section (COMDAT) or the next function
    symbol in the same section — not from a blr scan.
    """
    d = open(path, "rb").read()
    nsec,   = struct.unpack_from("<H", d, 2)
    symptr, = struct.unpack_from("<I", d, 8)
    nsym,   = struct.unpack_from("<I", d, 12)
    opt,    = struct.unpack_from("<H", d, 16)

    sects, p = [], 20 + opt
    for _ in range(nsec):
        rawsz, rawptr = struct.unpack_from("<II", d, p + 16)
        relptr,       = struct.unpack_from("<I", d, p + 24)
        nrel,         = struct.unpack_from("<H", d, p + 32)
        chars,        = struct.unpack_from("<I", d, p + 36)
        sects.append((rawptr, rawsz, chars, relptr, nrel))
        p += 40

    strtab = symptr + nsym * 18
    syms, i = [], 0
    while i < nsym:
        s = d[symptr + i * 18: symptr + i * 18 + 18]
        if s[0:4] == b"\0\0\0\0":
            o, = struct.unpack_from("<I", s, 4)
            name = d[strtab + o: d.index(b"\0", strtab + o)].decode("ascii", "replace")
        else:
            name = s[0:8].rstrip(b"\0").decode("ascii", "replace")
        val,  = struct.unpack_from("<I", s, 8)
        secn, = struct.unpack_from("<h", s, 12)
        typ,  = struct.unpack_from("<H", s, 14)
        syms.append((name, val, secn, typ))
        i += 1 + s[17]

    def anchored(name):
        # exact symbol (extern "C" / explicit mangled name), or C++ mangling of exactly `want`
        return name == want or name.startswith("?" + want + "@")

    cands = []
    for name, val, secn, typ in syms:
        if not anchored(name) or secn <= 0 or secn > len(sects):
            continue
        _, _, chars, _, _ = sects[secn - 1]
        if typ != SYM_DTYPE_FUNCTION:
            raise MatchError(f"symbol {name!r} matches {want!r} but is not a FUNCTION "
                             f"(type={typ:#x}) — refusing to grade non-code")
        if not (chars & IMAGE_SCN_CNT_CODE):
            raise MatchError(f"symbol {name!r} matches {want!r} but its section is not CODE "
                             f"(characteristics={chars:#x})")
        cands.append((name, val, secn))

    if not cands:
        raise MatchError(f"no FUNCTION symbol anchored to {want!r} in {os.path.basename(path)}")
    if len({c[0] for c in cands}) > 1:
        raise MatchError(f"{want!r} is ambiguous — {sorted({c[0] for c in cands})}. "
                         f"Use the full mangled name in functions.json.")

    name, val, secn = cands[0]
    rawptr, rawsz, chars, relptr, nrel = sects[secn - 1]

    if (chars & IMAGE_SCN_LNK_COMDAT) and val == 0:
        end = rawsz
    else:
        later = [v for (_, v, sn, ty) in syms
                 if sn == secn and ty == SYM_DTYPE_FUNCTION and v > val]
        end = min(later) if later else rawsz

    body = d[rawptr + val: rawptr + end]
    while len(body) >= 4 and body[-4:] == b"\x00\x00\x00\x00":   # trailing alignment padding
        body = body[:-4]
    if not body:
        raise MatchError(f"{want!r}: empty body extracted")

    last = int.from_bytes(body[-4:], "big")
    if not is_terminal(last):
        raise MatchError(f"{want!r}: extracted body does not end in blr/bctr/tail "
                         f"(last={last:#010x}) — extent derivation is wrong")

    # relocations that land inside this function, as {instruction index: (mask, symbol)}
    relocs = {}
    for k in range(nrel):
        rva, symidx, rtype = struct.unpack_from("<IIH", d, relptr + k * 10)
        if rtype == REL_PAIR:                 # addend carrier, patches no instruction
            continue
        if not (val <= rva < val + len(body)) or (rva - val) % 4:
            continue
        if rtype not in REL_MASKS:
            raise MatchError(f"{want!r}: unhandled relocation type {rtype:#x} at +{rva - val:#x}"
                             f" — refusing to compare a word we cannot neutralise")
        sname = syms[symidx][0] if symidx < len(syms) else f"sym{symidx}"
        relocs[(rva - val) // 4] = (REL_MASKS[rtype], sname)
    return body, relocs


def compile_target(t, flags, tag="v"):
    src = os.path.join(HERE, t["src"])
    if not os.path.exists(src):
        raise MatchError(f"source missing: {src}")
    out = os.path.join(HERE, "_build")
    os.makedirs(out, exist_ok=True)
    # The target name can be a MANGLED C++ symbol (e.g. a vcall thunk "??_9X@@$B..@AA"),
    # which contains characters illegal in a Windows path — sanitise it for the object name.
    safe = re.sub(r"[^A-Za-z0-9_.-]", "_", t["name"])[:64]
    obj = os.path.join(out, f"{safe}_{tag}.obj")
    if os.path.exists(obj):
        os.remove(obj)
    cmd = [CL, "/nologo", "/c", "/TP"] + XDK_INCLUDES + flags + t.get("defines", []) + \
          [src, "/Fo" + obj, "/FAcs", "/Fa" + obj[:-4] + ".cod"]
    r = subprocess.run(cmd, cwd=out, capture_output=True, text=True)
    if not os.path.exists(obj):
        raise MatchError("compile failed: " + (r.stdout + r.stderr).strip()[:500])
    return coff_function(obj, t["symbol"])  # (body, relocs)


def words(b):
    return [int.from_bytes(b[i:i + 4], "big") for i in range(0, len(b) - 3, 4)]


def branch_target(base, idx, word):
    """Resolve the guest address a bl/b at `idx` points at, for auditing."""
    li = word & 0x03FFFFFC
    if li & 0x02000000:
        li -= 0x04000000
    return base + idx * 4 + li


def equal_modulo_relocs(orig, ours, relocs, base=0):
    """(is_equal, masked) — masked = [(idx, symbol, guest_target)] for relocated words.

    A relocated word holds a link-time placeholder in our .obj and a resolved offset in
    the image, so its target field cannot be compared. Everything else in the word IS
    compared. Masked words are reported, never silently accepted.
    """
    ow, mw = words(orig), words(ours)
    if len(ow) != len(mw):
        return False, []
    masked = []
    for i, (o, m) in enumerate(zip(ow, mw)):
        if i in relocs:
            mask, sym = relocs[i]
            if (o & ~mask & 0xFFFFFFFF) != (m & ~mask & 0xFFFFFFFF):
                return False, masked
            if mask == 0x03FFFFFC:
                detail = f"bl->{branch_target(base, i, o):#x}"      # resolved guest callee
            elif mask == 0x0000FFFF:
                detail = f"imm={o & 0xFFFF:#06x}"                   # half of a guest address
            else:
                detail = f"word={o:#010x}"
            masked.append((i, sym, detail))
        elif o != m:
            return False, masked
    return True, masked


def compare(ow, mw):
    pref = 0
    while pref < min(len(ow), len(mw)) and ow[pref] == mw[pref]:
        pref += 1
    return pref, sum(1 for i in range(min(len(ow), len(mw))) if ow[i] == mw[i])


def _reject_duplicate_targets(targets):
    """A (module, addr) may appear at most once.

    Seven exact duplicate rows once sat in functions.json and inflated the headline by 218
    instructions (223 targets / 5074 insn reported, 216 / 4856 real) until an audit caught it.
    A board that over-reports is worse than a smaller one, so this is a hard error.
    """
    seen = {}
    for t in targets:
        key = (t["module"], int(t["addr"], 16))
        if key in seen:
            die(f"duplicate target {t['module']} {t['addr']}: "
                f"{seen[key]!r} and {t['name']!r} — a guest address may appear only once")
        seen[key] = t["name"]


def load_targets():
    with open(os.path.join(HERE, "functions.json")) as f:
        targets = json.load(f)["targets"]
    _reject_duplicate_targets(targets)
    return targets


def cmd_verify(targets):
    print(f"{'target':28s} {'addr':>10s} {'insn':>5s}  {'flags':16s} verdict")
    print("-" * 96)
    rc = 0
    for t in targets:
        addr = int(t["addr"], 16)
        try:
            orig = original_bytes(t["module"], addr, t.get("insn"))
            flags = t.get("flags", ["-O2"])
            got, relocs = compile_target(t, flags)
        except MatchError as e:
            print(f"{t['name']:28s} {t['addr']:>10s} {'-':>5s}  {'-':16s} ERROR  {e}")
            rc = 1
            continue
        ow, mw = words(orig), words(got)
        eq, masked = equal_modulo_relocs(orig, got, relocs, addr)
        if eq:
            tag = (f"EXACT  sha1 {hashlib.sha1(orig).hexdigest()[:12]}" if not masked else
                   f"EXACT* {len(masked)} reloc  "
                   + ", ".join(f"+{i} {det}" for i, _, det in masked))
            print(f"{t['name']:28s} {t['addr']:>10s} {len(ow):5d}  {' '.join(flags):16s} {tag}")
        else:
            pref, pos = compare(ow, mw)
            print(f"{t['name']:28s} {t['addr']:>10s} {len(ow):5d}  {' '.join(flags):16s} "
                  f"DIFF   ours={len(mw)} prefix={pref} same={pos}/{len(ow)}")
            rc = 1
    print("\n* EXACT* = every bit compared except link-time branch targets, which hold a "
          "placeholder\n  in our .obj. The resolved guest target is printed — audit it "
          "against the expected callee.")
    return rc


def cmd_diff(targets, name):
    t = next((x for x in targets if x["name"] == name), None)
    if not t:
        die(f"no target {name!r}")
    try:
        orig = original_bytes(t["module"], int(t["addr"], 16), t.get("insn"))
        got, relocs = compile_target(t, t.get("flags", ["-O2"]))
    except MatchError as e:
        die(str(e))
    ow, mw = words(orig), words(got)
    pref, pos = compare(ow, mw)
    print(f"{t['name']}  orig={len(ow)} ours={len(mw)} prefix={pref} same={pos}\n")
    print("idx  original  ours      note")
    for i in range(max(len(ow), len(mw))):
        o = ow[i] if i < len(ow) else None
        m = mw[i] if i < len(mw) else None
        os_ = f"{o:08x}" if o is not None else "--------"
        ms_ = f"{m:08x}" if m is not None else "--------"
        if o == m:
            note = ""
        elif o is not None and m is not None:
            note = ("reg/field only (same opcode)" if (o >> 26) == (m >> 26)
                    else "STRUCTURAL (different opcode)")
        else:
            note = "LENGTH"
        print(f"{i:3d}  {os_}  {ms_}  {note}")


def cmd_sweep(targets, name):
    t = next((x for x in targets if x["name"] == name), None)
    if not t:
        die(f"no target {name!r}")
    try:
        orig = original_bytes(t["module"], int(t["addr"], 16), t.get("insn"))
    except MatchError as e:
        die(str(e))
    ow = words(orig)
    print(f"{t['name']} target = {len(ow)} instructions\n")
    for flags in FLAG_MATRIX:
        try:
            got, relocs = compile_target(t, flags, tag="".join(flags).replace("-", ""))
        except MatchError as e:
            print(f"{' '.join(flags):20s} ERROR {e}")
            continue
        pref, pos = compare(ow, words(got))
        eq, masked = equal_modulo_relocs(orig, got, relocs, int(t["addr"], 16))
        print(f"{' '.join(flags):20s} insn={len(words(got)):3d} prefix={pref:3d} same={pos:3d}"
              + ("   *** EXACT ***" + (f" ({len(masked)} reloc)" if masked else "") if eq else ""))


# ---------------------------------------------------------------- self-test

DECOY_STUB = """// self-test decoy: a 4-instruction stub that the OLD harness certified EXACT
// against the 25-instruction function at 0x820AC018 (which has four interior blrs).
typedef unsigned int u32;
int Decoy_Stub(int a) { if (a) return 0; return 0; }
"""

DECOY_DATA = """// self-test decoy: a DATA array named like the wanted symbol, holding the answer.
// The OLD harness graded this and reported EXACT.
typedef unsigned int u32;
extern "C" const u32 Task_Kill[3] = { 0x39600002u, 0x91630008u, 0x4e800020u };
"""

DECOY_TWIN = """// self-test decoy: a second symbol whose name CONTAINS the wanted one.
typedef unsigned int u32;
struct Task { u32 pad00[2]; u32 state; };
void Task_Kill_reference(Task* t) { t->state = 3; }
void Task_Kill(Task* t) { t->state = 2; }
"""


def _build_scratch(name, text, symbol, flags=("-O2",)):
    out = os.path.join(HERE, "_build")
    os.makedirs(out, exist_ok=True)
    src = os.path.join(out, name + ".cpp")
    obj = os.path.join(out, name + ".obj")
    open(src, "w").write(text)
    if os.path.exists(obj):
        os.remove(obj)
    r = subprocess.run([CL, "/nologo", "/c", "/TP", *flags, src, "/Fo" + obj],
                       cwd=out, capture_output=True, text=True)
    if not os.path.exists(obj):
        return None, "compile failed: " + (r.stdout + r.stderr)[:300]
    return obj, None


def cmd_selftest():
    """Prove the harness rejects the decoys that fooled its first version."""
    print("ppcmatch self-test — the harness must REJECT every case below\n")
    ok = True

    def report(label, passed, detail):
        nonlocal ok
        ok &= passed
        print(f"  [{'PASS' if passed else 'FAIL'}] {label}\n         {detail}")

    # 1. interior-blr extent: the image side must derive 25, not 4, at 0x820AC018
    try:
        b = original_bytes("shell", 0x820AC018)
        report("interior-blr extent (0x820AC018)", len(b) // 4 == 25,
               f"derived {len(b)//4} instructions (old harness said 4, truth is 25)")
    except MatchError as e:
        report("interior-blr extent (0x820AC018)", False, f"unexpected error: {e}")

    # 2. declared-insn reconciliation must refuse a wrong count
    try:
        original_bytes("shell", 0x820AC018, declared=4)
        report("declared-insn reconciliation", False, "accepted insn=4 for a 25-insn function")
    except MatchError as e:
        report("declared-insn reconciliation", True, f"refused: {str(e)[:90]}")

    # 2b. a declared extent IS accepted when the split point is independently referenced
    try:
        b = original_bytes("shell", 0x821B9E58, declared=8)
        report("verified split accepted (0x821B9E58)", len(b) // 4 == 8,
               f"took declared 8 insn; note: {original_bytes.last_note}")
    except MatchError as e:
        report("verified split accepted (0x821B9E58)", False, f"refused: {str(e)[:90]}")

    # 2c. an UNPROVEN split stays refused at BOTH plausible truncations of the decoy
    for dec in (4, 14):
        try:
            original_bytes("shell", 0x820AC018, declared=dec)
            report(f"unproven split refused (declared {dec})", False,
                   f"accepted a {dec}-insn slice of a 25-insn function - hole reopened")
        except MatchError as e:
            report(f"unproven split refused (declared {dec})", True, f"refused: {str(e)[:80]}")

    # 2d. an UNREACHABLE tail IS accepted (second proof path, no outside reference needed)
    try:
        b = original_bytes("game", 0x8808D838, declared=50)
        report("unreachable-tail split accepted (0x8808D838)", len(b) // 4 == 50,
               f"took 50 insn; note: {original_bytes.last_note}")
    except MatchError as e:
        report("unreachable-tail split accepted (0x8808D838)", False, f"refused: {str(e)[:80]}")

    # 3. a DATA array named like the symbol must be refused
    obj, err = _build_scratch("selftest_data", DECOY_DATA, "Task_Kill")
    if err:
        report("data-array decoy", False, err)
    else:
        try:
            coff_function(obj, "Task_Kill")
            report("data-array decoy", False, "GRADED A DATA ARRAY — harness is unsound")
        except MatchError as e:
            report("data-array decoy", True, f"refused: {str(e)[:90]}")

    # 4. a substring twin must not be silently graded
    obj, err = _build_scratch("selftest_twin", DECOY_TWIN, "Task_Kill")
    if err:
        report("substring-twin decoy", False, err)
    else:
        try:
            body, _ = coff_function(obj, "Task_Kill")
            # exact anchoring should pick the real Task_Kill (3 insn ending in blr)
            passed = len(body) // 4 == 3 and words(body)[0] == 0x39600002
            report("substring-twin decoy", passed,
                   f"selected a {len(body)//4}-insn body, first word {words(body)[0]:#010x} "
                   f"(want 3 insn / 0x39600002)")
        except MatchError as e:
            report("substring-twin decoy", True, f"refused as ambiguous: {str(e)[:90]}")

    # 5. wrong-address control: a real target compared at a shifted address must not pass
    try:
        t = next(x for x in load_targets() if x["name"] == "Task_Kill")
        got, _ = compile_target(t, ["-O2"])
        bad = original_bytes("shell", int(t["addr"], 16) + 8)
        report("wrong-address control", got != bad,
               "shifted address does not compare equal")
    except MatchError as e:
        report("wrong-address control", True, f"refused: {str(e)[:90]}")

    print(f"\nself-test: {'ALL PASS' if ok else 'FAILURES PRESENT'}")
    return 0 if ok else 1


def cmd_check(module, addr_s, symbol, src, flags, show_diff, declared=None):
    """Ad-hoc verification of one function without touching functions.json.

    This is what parallel workers use: each owns its own source file, and nobody has to
    write to the shared registry while iterating.
    """
    addr = int(addr_s, 16)
    t = {"name": symbol, "module": module, "addr": addr_s, "symbol": symbol,
         "src": src, "flags": flags}
    try:
        orig = original_bytes(module, addr, declared)
        got, relocs = compile_target(t, flags, tag="check")
    except MatchError as e:
        print(f"ERROR {symbol} @ {addr_s}: {e}")
        return 2
    ow, mw = words(orig), words(got)
    eq, masked = equal_modulo_relocs(orig, got, relocs, addr)
    if eq:
        star = "*" if masked else ""
        detail = ("  " + ", ".join(f"+{i} {det}" for i, _, det in masked)) if masked else ""
        print(f"EXACT{star} {symbol} @ {addr_s}  {len(ow)} insn  "
              f"sha1 {hashlib.sha1(orig).hexdigest()[:12]}{detail}")
        return 0
    pref, pos = compare(ow, mw)
    print(f"DIFF {symbol} @ {addr_s}  orig={len(ow)} ours={len(mw)} "
          f"prefix={pref} same={pos}/{len(ow)}")
    if show_diff:
        print("\nidx  original  ours      note")
        for i in range(max(len(ow), len(mw))):
            o = ow[i] if i < len(ow) else None
            m = mw[i] if i < len(mw) else None
            os_ = f"{o:08x}" if o is not None else "--------"
            ms_ = f"{m:08x}" if m is not None else "--------"
            if o == m:
                note = ""
            elif i in relocs:
                note = "reloc-masked (compared modulo the patched field)"
            elif o is not None and m is not None:
                note = ("reg/field only (same opcode)" if (o >> 26) == (m >> 26)
                        else "STRUCTURAL (different opcode)")
            else:
                note = "LENGTH"
            print(f"{i:3d}  {os_}  {ms_}  {note}")
    return 1


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--diff", metavar="NAME")
    ap.add_argument("--sweep", metavar="NAME")
    ap.add_argument("--selftest", action="store_true")
    ap.add_argument("--check", nargs=4, metavar=("MODULE", "ADDR", "SYMBOL", "SRC"),
                    help="verify one function ad hoc, e.g. "
                         "--check shell 0x82076C10 Foo src/foo.cpp")
    ap.add_argument("--flags", default="-O2", help="compiler flags for --check (default -O2)")
    ap.add_argument("--show", action="store_true", help="print the side-by-side on a DIFF")
    ap.add_argument("--insn", type=int, default=None,
                    help="declared extent for --check (split-verified against the image)")
    a = ap.parse_args()
    if a.check:
        if not os.path.exists(CL):
            die(f"XDK 9328 compiler not found at {CL} — see matchlab/README.md")
        sys.exit(cmd_check(*a.check, a.flags.split(), a.show, a.insn))
    if not os.path.exists(CL):
        die(f"XDK 9328 compiler not found at {CL} — see matchlab/README.md to re-extract")
    if a.selftest:
        sys.exit(cmd_selftest())
    targets = load_targets()
    if a.diff:
        cmd_diff(targets, a.diff)
    elif a.sweep:
        cmd_sweep(targets, a.sweep)
    else:
        sys.exit(cmd_verify(targets))


if __name__ == "__main__":
    main()
