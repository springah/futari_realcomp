#!/usr/bin/env python3
"""Offline software rasterizer for captured Futari game frames (xr-work).

Walks the frame command window in a cap_low.bin memory dump, tracks fetch
constants per draw, and alpha-blends the textured quads into a PNG. This is
the tool that produced the first real Futari pixels (2026-07-05, "CO., LTD.").

Frame model (see futari-mode-game-module-bringup.md SESSION 7):
  - Present resets the device ring cursor (dev+0x30) to a fixed frame-body
    start each frame (= ring_base + 0x8000). cap_manifest.txt's ring_cur is
    the frame END at capture time. Window = [ring_base+0x8000, ring_cur).
  - Each draw: TYPE0 state + texture fetch slot0 (0x4800..0x4805) + vertex
    fetch in slot31 dwords 4-5 (0x48BE/0x48BF) + PM4_IM_LOAD(0x27) + DRAW_INDX
    (op 0x22, prim 5 = triangle fan of 4 = sprite quad).
  - Vertices: 24-byte stride, BE: float x, y, z, u32 D3DCOLOR, float u, v.
    Positions are SCREEN-SPACE (VTE XY_FMT).
  - Textures: 360-tiled (dword0 bit31); format = dword1 & 0x3F; base =
    (dword1 >> 12) << 12; size dword2: w = bits[0:13]+1, h = bits[13:26]+1.

Usage: swraster.py [--low cap_low.bin] [--manifest cap_manifest.txt]
                   [--out frame.png] [--start 0xADDR] [--end 0xADDR]
"""
import argparse, struct, sys, zlib

def be32(d, a): return struct.unpack_from('>I', d, a)[0]
def bef(d, a): return struct.unpack_from('>f', d, a)[0]

def parse_manifest(path):
    m = {}
    for line in open(path):
        if '=' in line:
            k, v = line.strip().split('=', 1)
            m[k] = v
    return m

# Xbox 360 2D tiled-texture offset (Xenia texture_conversion formulas).
def tiled_off(x, y, width, log2_bpp):
    macro_o = ((y // 32) * (width // 32)) << (log2_bpp + 7)
    micro_o = ((y & 6) << 2) << log2_bpp
    base = macro_o + ((micro_o & ~15) << 1) + (micro_o & 15) + \
        ((y & 8) << (3 + log2_bpp)) + ((y & 1) << 4)
    macro = (x // 32) << (log2_bpp + 7)
    micro = (x & 7) << log2_bpp
    off = base + (macro + ((micro & ~15) << 1) + (micro & 15) + ((x & 8) << 3))
    return ((off & ~511) << 3) + ((off & 448) << 2) + (off & 63) + \
        ((y & 16) << 7) + (((((y & 8) >> 2) + (x >> 3)) & 3) << 6)

def collect_draws(d, start, end):
    tf = [0] * 6
    vf = [0, 0]
    # Two vertex coordinate spaces share the one vertex shader (0xABC000):
    #  - SCREEN space: verts already in [0,W]x[0,H] (e.g. the copyright text line); no offset.
    #  - MODEL space:  verts centered on the origin (negative coords), positioned by the
    #    viewport center (XOFFSET reg 0x2110 / YOFFSET reg 0x2112, = 640/360 at 1280x720) —
    #    the logo / REPLAY panel / title graphics. Detected per-draw by "any negative vertex".
    vp_x = 640.0
    vp_y = 360.0
    draws = []
    i = start
    while i < end:
        w = be32(d, i)
        t = w >> 30
        if t == 0:
            reg = w & 0x7fff
            cnt = ((w >> 16) & 0x3fff) + 1
            if i + 4 + cnt * 4 > end + 64:
                break  # truncated trailing packet
            for k in range(cnt):
                r = reg + k
                v = be32(d, i + 4 + k * 4)
                if 0x4800 <= r < 0x4806: tf[r - 0x4800] = v
                if r == 0x48BE: vf[0] = v
                if r == 0x48BF: vf[1] = v
                if r == 0x2110: vp_x = struct.unpack('>f', struct.pack('>I', v))[0]
                if r == 0x2112: vp_y = struct.unpack('>f', struct.pack('>I', v))[0]
            i += 4 * (1 + cnt)
        elif t == 3:
            opc = (w >> 8) & 0x7f
            cnt = ((w >> 16) & 0x3fff) + 1
            if opc in (0x22, 0x36):
                init = be32(d, i + 8)
                draws.append((list(tf), list(vf), (init >> 16) & 0xFFFF, init & 0x3F, vp_x, vp_y))
            i += 4 * (1 + cnt)
        elif t == 2:
            i += 4
        else:
            print(f"  [walk] unknown packet @{i:#x} {w:08X} — stopping")
            break
    return draws

def make_sampler(d, tf):
    base = ((tf[1] >> 12) & 0xFFFFF) << 12
    if not base:
        return None
    fmt = tf[1] & 0x3F
    tiled = (tf[0] >> 31) & 1
    tw = (tf[2] & 0x1FFF) + 1
    th = ((tf[2] >> 13) & 0x1FFF) + 1
    if fmt == 6:      # k_8_8_8_8
        log2_bpp, bpp = 2, 4
    elif fmt == 2:    # k_8
        log2_bpp, bpp = 0, 1
    elif fmt == 4:    # k_4_4_4_4 (approx)
        log2_bpp, bpp = 1, 2
    else:
        return ('unknown_fmt', fmt, base, tw, th)

    def sample(u, v):
        x = max(0, min(tw - 1, int(u * tw)))
        y = max(0, min(th - 1, int(v * th)))
        off = tiled_off(x, y, tw, log2_bpp) if tiled else (y * tw + x) * bpp
        a = base + off
        if a + bpp > len(d):
            return (0, 0, 0, 0)
        if fmt == 6:
            px = be32(d, a)
            b0 = (px >> 24) & 0xFF; b1 = (px >> 16) & 0xFF
            b2 = (px >> 8) & 0xFF; b3 = px & 0xFF
            # empirical channel mapping (matches the CO., LTD. frame): A,R,G,B
            return (b1, b2, b3, b0) if b0 else (b1, b2, b3, max(b1, b2, b3))
        if fmt == 2:
            a8 = d[a]
            return (255, 255, 255, a8)
        if fmt == 4:
            px = struct.unpack_from('>H', d, a)[0]
            return (((px >> 8) & 0xF) * 17, ((px >> 4) & 0xF) * 17,
                    (px & 0xF) * 17, ((px >> 12) & 0xF) * 17)
    return sample

def write_png(path, w, h, rgb):
    def chunk(t, data):
        c = t + data
        return struct.pack('>I', len(data)) + c + struct.pack('>I', zlib.crc32(c) & 0xFFFFFFFF)
    raw = b''.join(b'\x00' + bytes(rgb[y * w * 3:(y + 1) * w * 3]) for y in range(h))
    open(path, 'wb').write(
        b'\x89PNG\r\n\x1a\n' +
        chunk(b'IHDR', struct.pack('>IIBBBBB', w, h, 8, 2, 0, 0, 0)) +
        chunk(b'IDAT', zlib.compress(raw, 6)) + chunk(b'IEND', b''))

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--low', default='/tmp/cap_low.bin')
    ap.add_argument('--manifest', default='/tmp/cap_manifest.txt')
    ap.add_argument('--out', default='/tmp/futari_sw_frame.png')
    ap.add_argument('--start', default=None, help='window start (hex); default ring_base+0x8000')
    ap.add_argument('--end', default=None, help='window end (hex); default manifest ring_cur')
    ap.add_argument('--bg', default='000020', help='background RRGGBB hex')
    args = ap.parse_args()

    d = open(args.low, 'rb').read()
    m = parse_manifest(args.manifest)
    ring_base = int(m['ring_base'], 16)
    start = int(args.start, 16) if args.start else ring_base + 0x8000
    end = int(args.end, 16) if args.end else int(m['ring_cur'], 16)
    W, H = int(m.get('width', 1280)), int(m.get('height', 720))
    print(f"window [{start:#x},{end:#x}) fb {W}x{H}")

    draws = collect_draws(d, start, end)
    print(f"draws: {len(draws)}")

    bg = bytes.fromhex(args.bg)
    fb = bytearray(W * H * 3)
    for p in range(W * H):
        fb[p * 3:p * 3 + 3] = bg

    unknown = {}
    skipped = 0
    for tf, vf, n, prim, vp_x, vp_y in draws:
        vaddr = vf[0] & ~3
        if not vaddr or n < 3:
            skipped += 1
            continue
        s = make_sampler(d, tf)
        if isinstance(s, tuple):
            unknown[s[1]] = unknown.get(s[1], 0) + 1
            s = None
        raw = [(bef(d, vaddr + k * 24), bef(d, vaddr + k * 24 + 4),
                be32(d, vaddr + k * 24 + 12),
                bef(d, vaddr + k * 24 + 16), bef(d, vaddr + k * 24 + 20))
               for k in range(n)]
        # Model-space draw (any negative vertex) → offset by the viewport center; screen-space
        # draw (already in-range) → no offset.
        model_space = any(v[0] < 0 or v[1] < 0 for v in raw)
        ox, oy = (vp_x, vp_y) if model_space else (0.0, 0.0)
        verts = [(v[0] + ox, v[1] + oy, v[2], v[3], v[4]) for v in raw]
        xs = [v[0] for v in verts]; ys = [v[1] for v in verts]
        if max(xs) - min(xs) < 0.5 or max(ys) - min(ys) < 0.5 or \
           max(xs) < 0 or min(xs) > W or max(ys) < 0 or min(ys) > H:
            skipped += 1
            continue
        us = [v[3] for v in verts]; vs = [v[4] for v in verts]
        u0, u1 = min(us), max(us); v0, v1 = min(vs), max(vs)
        col = verts[0][2]
        cr = (col >> 16) & 0xFF; cg = (col >> 8) & 0xFF
        cb = col & 0xFF; ca = (col >> 24) & 0xFF
        x0, x1 = int(min(xs)), int(max(xs)); y0, y1 = int(min(ys)), int(max(ys))
        for py in range(max(0, y0), min(H, y1 + 1)):
            fy = (py + 0.5 - min(ys)) / max(1e-6, max(ys) - min(ys))
            for px_ in range(max(0, x0), min(W, x1 + 1)):
                fx = (px_ + 0.5 - min(xs)) / max(1e-6, max(xs) - min(xs))
                if s:
                    tr, tg, tb, ta = s(u0 + fx * (u1 - u0), v0 + fy * (v1 - v0))
                else:
                    tr, tg, tb, ta = 255, 255, 255, 255
                a = (ta * ca) // 255
                if a == 0:
                    continue
                r = (tr * cr) // 255; g = (tg * cg) // 255; b = (tb * cb) // 255
                o = (py * W + px_) * 3
                fb[o] = (r * a + fb[o] * (255 - a)) // 255
                fb[o + 1] = (g * a + fb[o + 1] * (255 - a)) // 255
                fb[o + 2] = (b * a + fb[o + 2] * (255 - a)) // 255

    if unknown:
        print(f"  [warn] draws with unknown texture formats skipped-textureless: {unknown}")
    if skipped:
        print(f"  [info] {skipped} degenerate/offscreen draws skipped")
    write_png(args.out, W, H, fb)
    print(f"wrote {args.out}")

if __name__ == '__main__':
    main()
