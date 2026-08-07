import struct, sys
SC = r"C:\Users\shant\AppData\Local\Temp\claude\C--Users-shant-Desktop\63fc654b-54ee-4851-8035-38769b5962ed\scratchpad\abn"
BASE = 0x88000000
nor = open(SC + r"\nor.img.bin", "rb").read()
abn = open(SC + r"\abn.img.bin", "rb").read()

def w(img, a):
    o = a - BASE
    return struct.unpack(">I", img[o:o+4])[0]

def expect_savegprlr(img, a):
    """stw rN,-(4*(32-N))(r1) for N=14..31, then stw r0,8(r1)? then blr"""
    ok = []
    for i, N in enumerate(range(14, 32)):
        off = -(4 * (32 - N)) & 0xFFFF
        want = (36 << 26) | (N << 21) | (1 << 16) | off   # stw rN, off(r1)
        got = w(img, a + 4*i)
        ok.append((N, hex(want), hex(got), want == got))
    tail = [hex(w(img, a + 4*(18+k))) for k in range(2)]
    return ok, tail

def expect_restgprlr(img, a):
    ok = []
    for i, N in enumerate(range(14, 32)):
        off = -(4 * (32 - N)) & 0xFFFF
        want = (32 << 26) | (N << 21) | (1 << 16) | off   # lwz rN, off(r1)
        got = w(img, a + 4*i)
        ok.append((N, hex(want), hex(got), want == got))
    tail = [hex(w(img, a + 4*(18+k))) for k in range(3)]
    return ok, tail

def expect_fpr(img, a, store):
    op = 54 if store else 50   # stfd / lfd
    ok = []
    for i, N in enumerate(range(14, 32)):
        off = -(8 * (32 - N)) & 0xFFFF
        want = (op << 26) | (N << 21) | (1 << 16) | off
        got = w(img, a + 4*i)
        ok.append((N, hex(want), hex(got), want == got))
    tail = [hex(w(img, a + 4*(18+k))) for k in range(2)]
    return ok, tail

ANCH = {
    "savegprlr_14": (0x88071120, expect_savegprlr),
    "restgprlr_14": (0x88071170, expect_restgprlr),
    "savefpr_14":   (0x88088230, lambda im, a: expect_fpr(im, a, True)),
    "restfpr_14":   (0x8808827C, lambda im, a: expect_fpr(im, a, False)),
}

print("=== ANCHOR VERIFICATION (byte pattern + cross-image identity) ===")
for name, (addr, fn) in ANCH.items():
    span = 4 * 21
    nb = nor[addr-BASE: addr-BASE+span]
    ab = abn[addr-BASE: addr-BASE+span]
    identical = nb == ab
    for label, img in (("nor", nor), ("abn", abn)):
        ok, tail = fn(img, addr)
        bad = [x for x in ok if not x[3]]
        print(f"{name:14s} @0x{addr:08X} [{label}] pattern={'PASS' if not bad else 'FAIL '+str(bad[:3])}  tail={tail}")
    print(f"{name:14s} @0x{addr:08X} nor==abn over 0x{span:X} bytes: {identical}")
    print()

# how far does the byte-identical prologue region extend?
print("=== byte-identity map of .text (0x88070000..0x8824EEB0) ===")
TB, TE = 0x88070000, 0x8824EEB0
same = 0
first_diff = None
for a in range(TB, TE, 4):
    if w(nor, a) == w(abn, a):
        same += 1
    elif first_diff is None:
        first_diff = a
tot = (TE - TB) // 4
print(f"identical words: {same}/{tot} = {100.0*same/tot:.2f}%   first differing word @ 0x{first_diff:08X}")

# contiguous identical run from .text base
a = TB
while a < TE and w(nor, a) == w(abn, a):
    a += 4
print(f"contiguous identical run from 0x{TB:08X} to 0x{a:08X} ({a-TB} bytes)")

# GameEntry check
for a in (0x8824E698, 0x8824E6A0):
    print(f"0x{a:08X} nor={w(nor,a):08X} abn={w(abn,a):08X}")
print("nor@0x8824E698 first6:", [f"{w(nor,0x8824E698+4*i):08X}" for i in range(6)])
print("abn@0x8824E6A0 first6:", [f"{w(abn,0x8824E6A0+4*i):08X}" for i in range(6)])
