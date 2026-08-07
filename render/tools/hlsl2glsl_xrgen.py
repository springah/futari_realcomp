#!/usr/bin/env python3
# hlsl2glsl_xrgen.py  —  RVK_XRGEN thin plumbing shim.
#
# Adapts the D3D9-style HLSL that XenosRecomp (branch glvl-d3d9) emits from a real Xenos
# shader container into the Vulkan GLSL ABI our renderer already uses for the hand-synth
# ROM shaders (buffer_reference push constants, bindless texture[]/sampler[], athresh,
# the vs px->ndc epilogue).
#
# DISCIPLINE: this shim rewrites ONLY the shader *interface* and HLSL->GLSL surface syntax —
#   - `register(cN)` constants -> RawBufferLoad accessors on the right constant bank
#   - `sampler2D`/`tex2D` -> our bindless texture/sampler model
#   - I/O semantics -> locations (matching ps_rom48.frag / vs_rom48.vert exactly)
#   - VS: attribute prologue (uv-swap repair) + the px->ndc epilogue (halfpx, pc.ndc, y-flip)
#     appended AFTER the guest math — the same append-pattern as the ps alpha test
#   - VS DEF constants -> constant-bank reads (the runtime's loadShaderDefs uploads the DEF
#     value at IM_LOAD, mirroring D3D9's SetShader def upload — value path identical)
#   - PS DEF constants -> literals (verbatim from the container's definition table)
#   - HLSL-isms mapped 1:1: comparison-as-float assignments -> float()/vecN(equal(...)),
#     rcp() helper. No arithmetic is authored, reordered, or simplified here.
# Anything outside the ROM sprite/filter class (non-flattened control flow, cube/texCUBE,
# int/bool consts, float4-array CTAB consts, >1 color target) ABORTS rather than mistranslate.
#
# usage: hlsl2glsl_xrgen.py <in.hlsl> <out.glsl> [--athresh]
import re, sys

def die(msg):
    sys.stderr.write("hlsl2glsl_xrgen: ABORT: %s\n" % msg); sys.exit(3)

src = open(sys.argv[1], encoding='utf-8').read()
outpath = sys.argv[2]
want_athresh = '--athresh' in sys.argv[3:]

# strip the prepended shader_common.h (everything up to and including its #endif)
m = re.search(r'#endif\s*\n', src)
body_src = src[m.end():] if m else src

# --- hard unsupported checks ---------------------------------------------------------
for pat, what in [(r'sampler(?:3D|CUBE)\b', '3D/Cube sampler'), (r'\btexCUBE\b', 'texCUBE'),
                  (r'\bint4\s+i\d', 'int4 def constant'), (r'\bbool\s+\w+\s*:\s*register\(b', 'bool constant'),
                  (r'\bwhile\s*\(', 'non-flattened control flow (while/pc loop)')]:
    if re.search(pat, body_src): die(what + " unsupported")

# --- parse constant / sampler declarations -------------------------------------------
float4_consts = {}   # name -> register index (c#)
samplers = {}        # name -> register index (s#)
for name, arr, reg in re.findall(r'float4\s+(\w+)(\[\d+\])?\s*:\s*register\(c(\d+)\);', body_src):
    if arr:
        die("float4 array constant %s%s unsupported (array plumbing not implemented)" % (name, arr))
    float4_consts[name] = int(reg)
for name, reg in re.findall(r'sampler(?:2D)\s+(\w+)\s*:\s*register\(s(\d+)\);', body_src):
    samplers[name] = int(reg)

# --- parse main() signature ----------------------------------------------------------
sig = re.search(r'void\s+main\s*\((.*?)\)\s*\{', body_src, re.S)
if not sig: die("could not find main() signature")
params = [p.strip() for p in sig.group(1).split(',') if p.strip()]
is_pixel = 'VPOS' in sig.group(1) or ': COLOR0' in sig.group(1)

in_interp = []    # PS: (glsl_var, location, hlsl_ident)
vs_inputs = []    # VS: (attr_var, location, hlsl_ident)
vs_outs = []      # VS: (oT/oC var, hlsl_ident)
frag_coord_ident = None
out_color_ident = None
vs_pos_ident = None
def sem_loc(sem, idx):
    return idx if sem == 'TEXCOORD' else (16 + idx if sem == 'COLOR' else None)
for p in params:
    mm = re.match(r'(in|out)\s+float4?\s+(\w+)\s*:\s*([A-Z]+?)(\d*)$', p)
    if not mm: die("unparsable main() param: %r" % p)
    direction, ident, sem, idx = mm.group(1), mm.group(2), mm.group(3), mm.group(4)
    idx = int(idx) if idx else 0
    if sem == 'VPOS':
        frag_coord_ident = ident
    elif sem == 'COLOR' and direction == 'out':
        if out_color_ident is not None: die("multiple color outputs unsupported")
        out_color_ident = ident
    elif sem == 'POSITION' and direction == 'out':
        vs_pos_ident = ident
    elif direction == 'in' and is_pixel:
        loc = sem_loc(sem, idx)
        if loc is None: die("unsupported ps input semantic %s%d" % (sem, idx))
        in_interp.append(('v%s%d' % (sem.title(), idx), loc, ident))
    elif direction == 'in':  # VS attribute: POSITIONn -> loc n, TEXCOORDn -> loc 4+n (pipeline ABI)
        if sem == 'POSITION': loc = 0 + idx
        elif sem == 'TEXCOORD': loc = 4 + idx
        else: die("unsupported vs input semantic %s%d" % (sem, idx))
        vs_inputs.append(('aIn%d' % loc, loc, ident))
    elif direction == 'out':  # VS interpolator out -> oTn / oCn (vs_rom48.vert ABI)
        if sem == 'TEXCOORD': var = 'oT%d' % idx
        elif sem == 'COLOR': var = 'oC%d' % idx
        else: die("unsupported vs out semantic %s%d" % (sem, idx))
        vs_outs.append((var, ident))

if is_pixel and out_color_ident is None: die("no COLOR0 output found")
if not is_pixel and vs_pos_ident is None: die("no POSITION output found")

# --- extract executable body ---------------------------------------------------------
b0 = body_src.index('{', sig.start()) + 1
b1 = body_src.rindex('}')
body = body_src[b0:b1]

lines = [ln.rstrip() for ln in body.split('\n')]
def_lines = []   # float4 cN = float4(...) shader-embedded DEF constants
reg_decls = []
exec_lines = []
for ln in lines:
    s = ln.strip()
    if not s: continue
    if s.startswith('CubeMapData'): continue          # scaffold, unused when no cube ops
    if re.match(r'float4\s+c\d+\s*=', s):
        def_lines.append(s); continue
    if re.match(r'float4\s+r\d+\s*=', s) or re.match(r'(int|bool|float)\s+(a0|aL|p0|ps)\s*=', s):
        reg_decls.append(s); continue
    exec_lines.append(s)
while exec_lines and exec_lines[-1] == 'return;':
    exec_lines.pop()
if any(s == 'return;' for s in exec_lines):
    die("mid-body return (multiple exec-end blocks) unsupported")

# --- statement transforms (interface + HLSL->GLSL surface syntax only) ---------------
CMP_FUNCS = {'==': 'equal', '!=': 'notEqual', '>=': 'greaterThanEqual',
             '<=': 'lessThanEqual', '>': 'greaterThan', '<': 'lessThan'}

def rewrite_cmp(s):
    # HLSL implicitly converts comparison results to float on assignment; GLSL does not.
    # Applies only to plain `<target>.<mask> = <a> OP <b>;` statements (no ternary, not p0).
    mm = re.match(r'([A-Za-z_]\w*(?:\.[xyzw]+)?)\s*=\s*(.+);$', s)
    if not mm: return s
    lhs, rhs = mm.group(1), mm.group(2)
    if lhs.split('.')[0] == 'p0' or '?' in rhs: return s
    for op in ('==', '!=', '>=', '<=', '>', '<'):
        parts = rhs.split(' %s ' % op)
        if len(parts) == 2 and not re.search(r'[<>=!]=|[<>]', parts[0] + parts[1]):
            ncomp = len(lhs.split('.')[1]) if '.' in lhs else 1
            if lhs.split('.')[0] == 'ps': ncomp = 1
            if ncomp == 1:
                return '%s = float(%s %s %s);' % (lhs, parts[0], op, parts[1])
            return '%s = vec%d(%s(%s, %s));' % (lhs, ncomp, CMP_FUNCS[op], parts[0], parts[1])
    return s

def subst(s):
    s = re.sub(r'\bfloat4\b', 'vec4', s)
    if re.match(r'vec4\s', s):
        s = re.sub(r'=\s*0\.0\s*;', '= vec4(0.0);', s)
    if frag_coord_ident:
        s = re.sub(r'\b%s\b' % re.escape(frag_coord_ident), 'gl_FragCoord', s)
    for glsl_var, loc, ident in in_interp:
        s = re.sub(r'\b%s\b' % re.escape(ident), glsl_var, s)
    for attr_var, loc, ident in vs_inputs:
        s = re.sub(r'\b%s\b' % re.escape(ident), attr_var, s)
    for var, ident in vs_outs:
        s = re.sub(r'\b%s\b' % re.escape(ident), var, s)
    if out_color_ident:
        s = re.sub(r'\b%s\b' % re.escape(out_color_ident), 'oCol', s)
    if vs_pos_ident:
        s = re.sub(r'\b%s\b' % re.escape(vs_pos_ident), 'oPosG', s)
    def texrepl(mo):
        sname, coord = mo.group(1), mo.group(2)
        sreg = samplers[sname]
        return 'texture(sampler2D(gTex[nonuniformEXT(xrTex%d)], gSmp[nonuniformEXT(xrSmp%d)]), %s)' % (sreg, sreg, coord)
    s = re.sub(r'tex2D\(\s*(\w+)\s*,\s*([^)]*?)\)', texrepl, s)
    s = rewrite_cmp(s)
    return s

def_lines  = [subst(x) for x in def_lines]
reg_decls  = [subst(x) for x in reg_decls]
exec_lines = [subst(x) for x in exec_lines]

# VS DEF constants: read from the VS constant bank (loadShaderDefs uploads the DEF value at
# IM_LOAD, mirroring D3D9's SetShader def upload — keeps the runtime value path identical to
# the hand-synth, in both the register-true and the legacy c255-repair modes).
if not is_pixel:
    bank_defs = []
    for d in def_lines:
        dm = re.match(r'vec4\s+c(\d+)\s*=\s*vec4\(([^;]*)\);', d)
        if not dm: die("unparsable def line: %r" % d)
        reg = int(dm.group(1))
        bank_defs.append('vec4 c%d = V4Ptr(pc.VertexShaderConstants + %dul).v;  // DEF {%s} (bank-fed by loadShaderDefs)'
                         % (reg, reg * 16, dm.group(2).strip()))
    def_lines = bank_defs

body_text = '\n'.join(def_lines + reg_decls + exec_lines)
used_rcp = bool(re.search(r'\brcp\(', body_text))
for tok in ('frac(', 'saturate(', 'lerp(', 'clip('):
    if tok in body_text: die("intrinsic %s not mapped yet" % tok)

# --- emit GLSL -----------------------------------------------------------------------
o = []
o.append('#version 450')
o.append('// GENERATED by hlsl2glsl_xrgen.py from XenosRecomp(glvl-d3d9) HLSL — do not hand-edit.')
o.append('// Interface/plumbing shim only; the guest arithmetic is XenosRecomp output verbatim.')
o.append('#extension GL_EXT_buffer_reference : require')
o.append('#extension GL_ARB_gpu_shader_int64 : require')
o.append('#extension GL_EXT_nonuniform_qualifier : require')
o.append('')
o.append('layout(buffer_reference, buffer_reference_align = 4)  buffer U32Ptr { uint v; };')
o.append('layout(buffer_reference, buffer_reference_align = 4)  buffer F32Ptr { float v; };')
o.append('layout(buffer_reference, buffer_reference_align = 8)  buffer V2Ptr { vec2 v; };')
o.append('layout(buffer_reference, buffer_reference_align = 16) buffer V4Ptr { vec4 v; };')
o.append('')
o.append('layout(push_constant, std430) uniform PushConstants {')
o.append('    uint64_t VertexShaderConstants;')
o.append('    uint64_t PixelShaderConstants;')
o.append('    uint64_t SharedConstants;')
if not is_pixel:
    o.append('    vec2 ndcS;   // px->ndc scale  (identity {1,1} on the legacy path)')
    o.append('    vec2 ndcO;   // px->ndc offset (identity {0,0} on the legacy path)')
o.append('} pc;')
o.append('')
if used_rcp:
    o.append('float rcp(float x) { return 1.0 / x; }')
    o.append('')

if is_pixel:
    o.append('layout(set = 0, binding = 0) uniform texture2D gTex[];')
    o.append('layout(set = 3, binding = 0) uniform sampler gSmp[];')
    o.append('')
    for glsl_var, loc, ident in in_interp:
        o.append('layout(location = %d) in vec4 %s;' % (loc, glsl_var))
    o.append('layout(location = 0) out vec4 oCout;')
    o.append('')
    o.append('void main() {')
    for sname, sreg in sorted(samplers.items(), key=lambda kv: kv[1]):
        o.append('    uint xrTex%d = U32Ptr(pc.SharedConstants + %dul).v;' % (sreg, sreg * 4))
        o.append('    uint xrSmp%d = U32Ptr(pc.SharedConstants + %dul).v;' % (sreg, 192 + sreg * 4))
    for cname, creg in sorted(float4_consts.items(), key=lambda kv: kv[1]):
        o.append('    vec4 %s = V4Ptr(pc.PixelShaderConstants + %dul).v;' % (cname, creg * 16))
    o.append('    float xrAthresh = F32Ptr(pc.SharedConstants + 272ul).v;')
    o.append('    vec4 oCol = vec4(0.0);')
    o.append('    // --- shader-embedded DEF constants (container definition table, verbatim) ---')
    for d in def_lines: o.append('    %s' % d)
    o.append('    // --- register file ---')
    for d in reg_decls: o.append('    %s' % d)
    o.append('    // --- XenosRecomp body (verbatim arithmetic) ---')
    for e in exec_lines: o.append('    %s' % e)
    o.append('    // --- fixed-function alpha test (RB_COLORCONTROL/RB_ALPHA_REF -> athresh) ---')
    if want_athresh:
        o.append('    if (oCol.w < xrAthresh) discard;')
    o.append('    oCout = oCol;')
    o.append('}')
else:
    if samplers: die("vs texture fetch unsupported")
    for attr_var, loc, ident in vs_inputs:
        o.append('layout(location = %d) in vec4 %s;' % (loc, attr_var))
    for i in range(16):
        o.append('layout(location = %d) out vec4 oT%d;' % (i, i))
    o.append('layout(location = 16) out vec4 oC0;')
    o.append('layout(location = 17) out vec4 oC1;')
    o.append('')
    o.append('void main() {')
    for cname, creg in sorted(float4_consts.items(), key=lambda kv: kv[1]):
        o.append('    vec4 %s = V4Ptr(pc.VertexShaderConstants + %dul).v;' % (cname, creg * 16))
    o.append('    // --- renderer plumbing: uv-swap repair + half-texel (same levers as vs_rom48.vert) ---')
    o.append('    uint xrSwap = U32Ptr(pc.SharedConstants + 260ul).v;')
    o.append('    vec2 xrHalfpx = V2Ptr(pc.SharedConstants + 264ul).v;')
    for attr_var, loc, ident in vs_inputs:
        if loc >= 4:  # TEXCOORD attrs get the host-side endian-swizzle repair
            o.append('    vec4 %s_s = ((xrSwap & 1u) != 0u) ? %s.yxzw : %s;' % (attr_var, attr_var, attr_var))
    o.append('    vec4 oPosG = vec4(0.0);')
    for i in range(16): o.append('    vec4 oT%d_ = vec4(0.0);' % i)
    o.append('    // --- shader-embedded DEF constants (bank-fed, see header) ---')
    for d in def_lines: o.append('    %s' % d)
    o.append('    // --- register file ---')
    for d in reg_decls: o.append('    %s' % d)
    o.append('    // --- XenosRecomp body (verbatim arithmetic) ---')
    for e in exec_lines:
        for attr_var, loc, ident in vs_inputs:
            if loc >= 4:
                e = re.sub(r'\b%s\b(?!_s)' % attr_var, attr_var + '_s', e)
        e = re.sub(r'\boT(\d+)\b(?!_)', r'oT\1_', e)
        o.append('    %s' % e)
    o.append('    // --- px->ndc epilogue (pc.ndc push constants; appended AFTER the guest math) ---')
    o.append('    vec2 xrP = oPosG.xy + xrHalfpx;')
    o.append('    xrP = xrP * pc.ndcS + pc.ndcO;')
    o.append('    gl_Position = vec4(xrP.x, -xrP.y, oPosG.z, oPosG.w);')
    o.append('    // --- interpolator ABI padding (vs_rom48.vert contract) ---')
    for i in range(16):
        o.append('    oT%d = oT%d_;' % (i, i))
    o.append('    oC0 = vec4(1.0);')
    o.append('    oC1 = vec4(1.0);')
    o.append('}')
open(outpath, 'w', encoding='utf-8', newline='\n').write('\n'.join(o) + '\n')
sys.stderr.write('hlsl2glsl_xrgen: wrote %s (%s, %d consts, %d samplers, %d defs, %d exec lines)\n'
                 % (outpath, 'ps' if is_pixel else 'vs', len(float4_consts), len(samplers), len(def_lines), len(exec_lines)))
