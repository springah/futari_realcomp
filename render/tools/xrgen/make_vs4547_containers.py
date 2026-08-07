#!/usr/bin/env python3
# make_vs4547_containers.py — carve the vs=45 / vs=47 XenosRecomp input containers.
#
# UNLIKE vs48 (whose container does not exist anywhere and has to be synthesized — see
# make_vs48_container.py), the two GAME-MODULE vertex shaders are present BYTE-EXACT in the
# guest-memory captures, as real on-disk containers inside the game image (cap_gimage.bin,
# guest base 0x88000000):
#   0x9638 (guest 0x88009638) VS  vsz=0xB8 psz=0xAC -> table idx 45 (ucode_size 172)
#   0x98A8 (guest 0x880098A8) VS  vsz=0x90 psz=0x60 -> table idx 47 (ucode_size 96)
# Both are identical across caps_gp / caps_gp2 / caps_s8 (asserted below). No metadata is
# authored here — this is a pure byte carve of [base, base+vsz+psz).
#
# vs45's container carries its own definition table (c255 DEF pool = {2.0, 1/256, -0.5, 0.0}
# at physical offset 0, ucode at physical offset 0x40) — i.e. the SAME c255 the vs48
# container was synthesized around. vs47 has no definition table (dto == 0) and no constants.
#
# fam_vs96.xvu (the make_vs48_container.py metadata donor) IS the vs47 container; it is left
# alone so the vs48 synthesis keeps its historical input byte-for-byte.
import struct, os, sys

here = os.path.dirname(os.path.abspath(__file__))
caps = [os.path.join(here, '..', '..', '..', c, 'cap_gimage.bin')
        for c in ('caps_gp', 'caps_gp2', 'caps_s8')]

# name -> (offset in cap_gimage.bin, expected virtualSize, expected physicalSize)
WANT = {'rom_vs45': (0x9638, 0xB8, 0xAC),
        'rom_vs47': (0x98A8, 0x90, 0x60)}

blobs = {}
for cap in caps:
    if not os.path.exists(cap):
        continue
    data = open(cap, 'rb').read()
    for name, (off, vsz, psz) in WANT.items():
        flags, v, p = struct.unpack('>III', data[off:off + 12])
        assert flags == 0x102A1101, '%s: %s flags=0x%08X (not a VS container)' % (cap, name, flags)
        assert (v, p) == (vsz, psz), '%s: %s size mismatch %s' % (cap, name, (hex(v), hex(p)))
        b = data[off:off + vsz + psz]
        if name in blobs:
            assert blobs[name] == b, '%s: %s differs between captures' % (cap, name)
        else:
            blobs[name] = b

for name, (off, vsz, psz) in WANT.items():
    if name not in blobs:
        sys.stderr.write('make_vs4547_containers: FATAL: no capture supplied %s\n' % name)
        sys.exit(2)
    out = os.path.join(here, name + '.xvu')
    open(out, 'wb').write(blobs[name])
    so = struct.unpack('>I', blobs[name][0x18:0x1C])[0]
    po, sz = struct.unpack('>II', blobs[name][so:so + 8])
    print('wrote %s (%d bytes: vsz=0x%X psz=0x%X so=0x%X ucode physOff=0x%X size=%d)'
          % (out, len(blobs[name]), vsz, psz, so, po, sz))
