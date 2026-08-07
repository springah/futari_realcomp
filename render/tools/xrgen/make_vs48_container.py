#!/usr/bin/env python3
# make_vs48_container.py — build the vs=48 XenosRecomp input container.
#
# The vs=48 asset-sprite VS (runtime guest 0xF4C1040, 108B ucode) has NO on-disk/in-memory
# container in any capture (swept caps_gp/gp2/s8 + cap_replay_screen + caparena_low, incl.
# backward header-scans around the staging addresses) — the D3D9 shell assembles its fetch
# clause from the bound vertex declaration at runtime. Its structural siblings DO exist as
# real containers (same CF skeleton: vfetch slots 3=POSITION0 / 4=TEXCOORD0, ALU exports
# oPos + TEXCOORD0): shell 132B variant (cap_image@0x3BC00) and the game module's 96B
# variant (cap_gimage@0x98A8).
#
# This script synthesizes the container METADATA ONLY, patterned byte-for-byte on the real
# sibling fam_vs96.xvu (header, CTAB, VertexShader struct incl. the element/interpolator
# tables — verified to decode to the same fetch slot addresses 3/4 as the vs48 ucode), and
# wraps the GENUINE dumped runtime ucode plus a definition table for the shader-embedded
# c255 DEF = {2.0, 1/256, -0.5, 0.0} (oracle-verified: the SDK rdc xe_float_cbuffer at the
# legal draws; also the value loadShaderDefs uploads). The MATH translated by XenosRecomp
# is 100% the real ucode; nothing arithmetic is authored here.
import struct, sys, os

here = os.path.dirname(os.path.abspath(__file__))
fam = open(os.path.join(here, 'fam_vs96.xvu'), 'rb').read()
ucode = open(os.path.join(here, 'ucode_vs48_1171F040.bin'), 'rb').read()
assert len(ucode) == 108, len(ucode)

be32 = lambda v: struct.pack('>I', v)

# fam_vs96 layout: header 0x24 | CTAB 0x24..0x58 | VertexShader struct 0x58..0x90
ctab = fam[0x24:0x58]
shstruct = bytearray(fam[0x58:0x90])
assert struct.unpack('>I', shstruct[4:8])[0] == 0x60      # sibling code size
shstruct[0:4] = be32(0x10)     # Shader.physicalOffset: code sits after the 16B DEF pool
shstruct[4:8] = be32(len(ucode))

# definition table: 5-dword header {0,1,0,0,0x14} + float4 def {reg=255, cnt=4 dwords,
# physOff=0} + f4 terminator + int4 terminator  (shape copied from rom_ps49.xpu @dto)
deftab = b''.join([be32(0), be32(1), be32(0), be32(0), be32(0x14),
                   struct.pack('>HH', 255, 4), be32(0),   # Float4Definition
                   be32(0),                               # float4 stream terminator
                   be32(0)])                              # int4 stream terminator

cto = 0x24
dto = cto + len(ctab)
so  = dto + len(deftab)
vsz = so + len(shstruct)

# physical region: 16B c255 DEF pool (big-endian floats) + the genuine ucode
pool = struct.pack('>ffff', 2.0, 0.00390625, -0.5, 0.0)
phys = pool + ucode

hdr = b''.join([be32(0x102A1101),         # flags: VS
                be32(vsz), be32(len(phys)),
                be32(struct.unpack('>I', fam[0xC:0x10])[0]),  # fieldC (copied)
                be32(cto), be32(dto), be32(so), be32(0), be32(0)])
assert len(hdr) == 0x24

blob = hdr + ctab + deftab + shstruct + phys
out = os.path.join(here, 'rom_vs48.xvu')
open(out, 'wb').write(blob)
print('wrote %s (%d bytes: vsz=0x%X psz=0x%X dto=0x%X so=0x%X)' % (out, len(blob), vsz, len(phys), dto, so))
