#!/usr/bin/env python3
# make_shellps_containers.py — carve the four SHELL HSV-colour-filter PS containers
# (shader-table rows 22 / 26 / 28 / 40) for the XenosRecomp input set.
#
# WHY (s2B leg 14, SETP_INV census): the leg-13 chroma fix repointed table row 20 (guest
# 0x8203DBD8) at the regenerated ps49 module because its ucode uses the predicate stack and the
# BAKED translation carried XenosRecomp's missing `p0 ? 0.0 :` guard on SETP_INV. The census
# (_tmpscripts/setpinv_scan.py, report _tmpscripts/setpinv_audit_report.md) found FOUR MORE baked
# rows with the identical ladder — 5x SETP_INV, 6x PRED_SET*_PUSH, 5x SETP_POP each — and confirmed
# 5 unguarded SETP_INV sites in each of their shipping baked SPIR-V modules:
#   idx 22 guest 0x8203E2C8  g_futari_spirv_28   9 tex fetches  (multi-texture variant)
#   idx 26 guest 0x8203EE88  g_futari_spirv_4    1 tex fetch
#   idx 28 guest 0x8203F588  g_futari_spirv_23   3 tex fetches
#   idx 40 guest 0x82043A38  g_futari_spirv_5    1 tex fetch
#
# Like vs45/vs47 — and UNLIKE vs48, whose container exists nowhere and had to be synthesized —
# all four are present BYTE-EXACT as real on-disk containers in the shell image (cap_image.bin,
# guest base 0x82000000). No metadata is authored here: this is a pure byte carve of
# [base, base+vsz+psz), asserted identical across every capture that has the file.
#
# All four are PIXEL shaders (flags 0x102A1100, i.e. flags & 1 == 0) and all four carry
# spec_mask == 2 in g_futari_shaders, so gen_xrgen.sh translates them with --athresh (the
# appended fixed-function alpha test, a no-op unless RB_COLORCONTROL arms it) exactly like
# rom_ps49 / rom_ps50.
#
# Each container carries its own definition table (the c252..c255 DEF pool: the HSV sector
# thresholds 6/3/2, 1/3, 2/3, 5, 4 and the 0/-0.5/1/0.5 helpers). Those travel INSIDE the
# generated module as literals — loadShaderDefs() returns early for pixel shaders, so there is
# no constant-bank plumbing to add. See _tmpscripts/setpinv_fix_notes.md for the DEF-pool
# equivalence evidence against the baked modules these replace.
import struct, os, sys

here = os.path.dirname(os.path.abspath(__file__))
caps = [os.path.join(here, '..', '..', '..', c, 'cap_image.bin')
        for c in ('caps_gp', 'caps_gp2', 'caps_s8')]

# name -> (offset in cap_image.bin, expected virtualSize, expected physicalSize)
# offset == guest_addr - 0x82000000; psz == the row's ucode_size in g_futari_shaders.
WANT = {'shell_ps22': (0x3E2C8, 0x19C, 0x4CC),
        'shell_ps26': (0x3EE88, 0x1B4, 0x3B8),
        'shell_ps28': (0x3F588, 0x1B4, 0x3DC),
        'shell_ps40': (0x43A38, 0x1B4, 0x404)}

blobs = {}
seen_caps = []
for cap in caps:
    if not os.path.exists(cap):
        continue
    seen_caps.append(os.path.basename(os.path.dirname(cap)))
    data = open(cap, 'rb').read()
    for name, (off, vsz, psz) in WANT.items():
        flags, v, p = struct.unpack('>III', data[off:off + 12])
        assert flags == 0x102A1100, '%s: %s flags=0x%08X (not a PS container)' % (cap, name, flags)
        assert (v, p) == (vsz, psz), '%s: %s size mismatch %s' % (cap, name, (hex(v), hex(p)))
        b = data[off:off + vsz + psz]
        if name in blobs:
            assert blobs[name] == b, '%s: %s differs between captures' % (cap, name)
        else:
            blobs[name] = b

for name, (off, vsz, psz) in WANT.items():
    if name not in blobs:
        sys.stderr.write('make_shellps_containers: FATAL: no capture supplied %s\n' % name)
        sys.exit(2)
    out = os.path.join(here, name + '.xpu')
    open(out, 'wb').write(blobs[name])
    so = struct.unpack('>I', blobs[name][0x18:0x1C])[0]
    po, sz = struct.unpack('>II', blobs[name][so:so + 8])
    print('wrote %s (%d bytes: vsz=0x%X psz=0x%X so=0x%X ucode physOff=0x%X size=%d)'
          % (out, len(blobs[name]), vsz, psz, so, po, sz))
print('captures agreeing byte-for-byte: %s' % ', '.join(seen_caps))
