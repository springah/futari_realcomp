"""Inspect the 3 session-6 'byte-map' tables (labels are SDK-FLATTENED, not inline dwords)."""
import struct, bisect
SC = r"C:\Users\shant\AppData\Local\Temp\claude\C--Users-shant-Desktop\63fc654b-54ee-4851-8035-38769b5962ed\scratchpad\abn"
BASE = 0x88000000
nor = open(SC + r"\nor.img.bin", "rb").read()
abn = open(SC + r"\abn.img.bin", "rb").read()
nfn = sorted(int(x, 16) for x in open(SC + r"\nor_funcs.txt"))
afn = sorted(int(x, 16) for x in open(SC + r"\abn_funcs.txt"))

def w(img, a): return struct.unpack(">I", img[a-BASE:a-BASE+4])[0]
def encl(fns, a, end=0x8824EEB8):
    i = bisect.bisect_right(fns, a) - 1
    return fns[i], (fns[i+1] if i+1 < len(fns) else end)

for nm, b in (("sub_8807D838", 0x8807D954), ("sub_8808B330", 0x8808B424), ("sub_880714E0", 0x88071924)):
    nfs, nfe = encl(nfn, b, 0x8824EEB0)
    afs, afe = encl(afn, b)
    same = nor[nfs-BASE:nfe-BASE] == abn[nfs-BASE:nfe-BASE]
    print(f"\n{nm}: bctr@0x{b:08X}")
    print(f"  nor fn 0x{nfs:08X}..0x{nfe:08X} ({nfe-nfs}B) | abn fn 0x{afs:08X}..0x{afe:08X} ({afe-afs}B)")
    print(f"  fn bytes identical: {same}   abn word @bctr: 0x{w(abn,b):08X} (bctr=0x4E800420)")
    if not same:
        # first differing word inside the nor function, and per-word identity ratio
        d = [a for a in range(nfs, min(nfe, afe), 4) if w(nor, a) != w(abn, a)]
        tot = (min(nfe, afe) - nfs) // 4
        print(f"  differing words: {len(d)}/{tot}; first @0x{d[0]:08X} nor=0x{w(nor,d[0]):08X} abn=0x{w(abn,d[0]):08X}")
        # locate abn's own bctr(s) in the abn function
        bc = [a for a in range(afs, afe, 4) if w(abn, a) == 0x4E800420]
        print(f"  abn bctr sites in that fn: {[hex(x) for x in bc]}")
        nbc = [a for a in range(nfs, nfe, 4) if w(nor, a) == 0x4E800420]
        print(f"  nor bctr sites in that fn: {[hex(x) for x in nbc]}")
