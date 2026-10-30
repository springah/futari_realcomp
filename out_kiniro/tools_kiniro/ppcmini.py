"""Minimal shared helpers for the kiniro static tools: flat-image access, PE section table, .pdata
function starts, and a tiny PPC decoder for the handful of opcodes the switch recognisers need."""
import struct, bisect
BASE = 0x88000000
BCTR = 0x4E800420

class Img:
    def __init__(self, path):
        self.b = open(path, "rb").read()
        e_lfanew = struct.unpack("<I", self.b[0x3C:0x40])[0]          # PE header fields are little-endian
        nsec = struct.unpack("<H", self.b[e_lfanew+6:e_lfanew+8])[0]
        optsz = struct.unpack("<H", self.b[e_lfanew+20:e_lfanew+22])[0]
        sh = e_lfanew + 24 + optsz
        self.sec = {}
        for i in range(nsec):
            o = sh + 40*i
            name = self.b[o:o+8].rstrip(b"\0").decode()
            vsize, va = struct.unpack("<II", self.b[o+8:o+16])
            self.sec[name] = (BASE + va, BASE + va + vsize)
        ps, pe = self.sec[".pdata"]
        fns = []
        for a in range(ps, pe, 8):
            begin = self.w(a)
            if begin == 0: continue
            nins = (self.w(a + 4) >> 8) & 0x3FFFFF                    # Xenon .pdata: FunctionLength (insns) in bits 8..29
            fns.append((begin, begin + 4*nins))
        fns.sort()
        self.fn_starts = [f for f, _ in fns]
        self.fn_ends = {f: e for f, e in fns}
        self.text = self.sec[".text"]

    def w(self, a):
        o = a - BASE
        return struct.unpack(">I", self.b[o:o+4])[0]

    def encl(self, a):
        """enclosing .pdata function [start, end) of guest address a (end = next start, as scan.py did)."""
        i = bisect.bisect_right(self.fn_starts, a) - 1
        if i < 0: return None, None
        fs = self.fn_starts[i]
        fe = self.fn_starts[i+1] if i + 1 < len(self.fn_starts) else self.text[1]
        return fs, fe

def simm(x): return x - 0x10000 if x & 0x8000 else x

def dec(x):
    """-> (mnemonic, fields-dict) for the opcodes the recognisers look at; ('?', {}) otherwise."""
    op = x >> 26; rt = (x >> 21) & 31; ra = (x >> 16) & 31; rb = (x >> 11) & 31
    if op == 10 and not (x >> 21) & 1: return "cmplwi", dict(crf=rt >> 2, ra=ra, ui=x & 0xFFFF)
    if op == 11 and not (x >> 21) & 1: return "cmpwi", dict(crf=rt >> 2, ra=ra, si=simm(x & 0xFFFF))
    if op == 14: return ("li" if ra == 0 else "addi"), dict(rt=rt, ra=ra, si=simm(x & 0xFFFF))
    if op == 15: return ("lis" if ra == 0 else "addis"), dict(rt=rt, ra=ra, si=simm(x & 0xFFFF))
    if op == 21: return "rlwinm", dict(ra=ra, rs=rt, sh=rb, mb=(x >> 6) & 31, me=(x >> 1) & 31)
    if op == 24: return "ori", dict(ra=ra, rs=rt, ui=x & 0xFFFF)
    if op == 16: return "bc", dict(bo=rt, bi=ra, bd=simm(x & 0xFFFC))
    if op == 31:
        xo = (x >> 1) & 0x3FF
        names = {87: "lbzx", 279: "lhzx", 343: "lhax", 23: "lwzx", 266: "add", 467: "mtspr", 444: "or"}
        if xo in names:
            n = names[xo]
            if n == "mtspr":
                spr = ((x >> 16) & 31) | (((x >> 11) & 31) << 5)
                return ("mtctr" if spr == 9 else "mtspr"), dict(rs=rt)
            if n == "or": return "or", dict(ra=ra, rs=rt, rb=rb)
            return n, dict(rt=rt, ra=ra, rb=rb)
    if x == BCTR: return "bctr", {}
    return "?", dict(op=op)
