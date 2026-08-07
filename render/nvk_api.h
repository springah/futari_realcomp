// nvk_api.h — HARD PIVOT stage 1+2 (2026-07-28): the recorder->renderer frame handoff.
//
// decomp/shell/nvk.cpp records the guest's D3D-wrapper calls (RT_NVK=2) into an NvkFrame;
// at Present it hands the frame to nvk_frame_submit() (bottom of render/vk_render.cpp),
// which renders it with the existing Vulkan primitives. No PM4, no windows, no heuristics:
// every field here is either a wrapper-call argument or a register-true device-object read.
// Stage 2: draws are captured at the CORE (shell sub_8209D800 / game sub_8807ECA0) exit with
// the scratch-VB address; vertex bytes are read lazily at Present (complete by then — the
// commit/kick always precedes Present, s1_abi §4). Resolves are ordered events that segment
// the frame (s2_game_abi: game XGResolve, flags 0x100=setup-only, 0x200=clear-EDRAM-after).
#pragma once
#include <stdint.h>

#define NVK_MAX_DRAWS 6144
// Dirty-gated VS/PS float-const snapshot pairs per frame. 256 OVERFLOWED in ROM attract (s2B
// leg 7): the game's packet-level SET_CONSTANT dirties per sprite batch — 400-500 draw frames
// exhausted the pool and every later draw shared the last bank (wrong matrices = the gameplay
// layer transformed away). 768 covers the observed worst case with headroom; overflow stays
// loud. Cost note: ~7.7KB byteswap-copy per snapshot is the known perf debt (delta snapshots
// keyed on the dirty-range qwords are the register-true optimization when it bites).
#define NVK_MAX_BANKS 768

enum { NVK_KIND_DRAW = 0, NVK_KIND_RESOLVE = 2, NVK_KIND_CLEAR = 3, NVK_KIND_SETRT = 4 };

typedef struct NvkDraw {
  uint32_t kind;                  // NVK_KIND_*
  // kind DRAW:
  uint32_t prim;                  // Xenos VGT prim (5 fan / 6 strip / 8 rectlist observed)
  uint32_t count;                 // vertex count (rectlist: 3 per rect, 4th synthesized)
  uint32_t strideB;               // TRUE vertex stride in bytes (wrapper arg — no guessing)
  uint32_t scratchGuest;          // guest addr of the vertex scratch (core return r3)
  uint32_t vtxOff;                // byte offset in vtxBlob (filled at Present from scratchGuest)
  uint32_t tf[6];                 // stage-0 fetch constant (device shadow dev+0x480, host-endian)
  uint32_t blendReg;              // RB_BLENDCONTROL0 shadow (dev+0x2938)
  uint32_t colorCtl;              // RB_COLORCONTROL shadow (dev+0x293C): bit3 ALPHA_TEST_ENABLE, [2:0] ALPHA_FUNC
  uint32_t alphaRef;              // RB_ALPHA_REF shadow  (dev+0x2904): float bits, = refByte/255
  uint32_t blendConst[4];         // RB_BLEND_RED..ALPHA shadows (dev+0x28E0..0x28EC): float bits (D3DRS_BLENDFACTOR)
  uint32_t vsUcode, vsUcodeSize;  // bound VS object's microcode (guest addr/bytes); 0 = none
  uint32_t psUcode, psUcodeSize;
  float    vp[4];                 // guest viewport X,Y,W,H (dev+0x3218..)
  float    vte[4];                // PA_CL_VPORT xscale,xoffset,yscale,yoffset (dev+0x2908 shadow)
  uint32_t vteCntl;               // PA_CL_VTE_CNTL (dev+0x294C): bit0 off = VS outputs SCREEN px
  uint32_t bank;                  // index into vsBanks/psBanks (paired snapshot)
  // kind SETRT (s2B leg 6, size decode corrected leg 9): guest binds a colour render target —
  // segments the frame; draws that follow render into this target's host image until the next
  // SETRT. Register-true surface ABI (decode + evidence in decomp/shell/nvk.cpp nvk_on_setrt):
  //   +0x18 RB_SURFACE_INFO  (surface_pitch[13:0], msaa[17:16], hiz_pitch[31:18])
  //   +0x1C RB_COLOR_INFO    (EDRAM tile base[11:0], color_format[19:16]) — NOT a height
  //   +0x24 packed size      ((W-1)<<18 | (H-1)<<3)  <- the true render extent
  //   +0x2C surface byte size (W*H*bpp) — corroborator only
  // The DISPLAY surface is not identified here: it is whichever surface is bound when Present
  // fires (NvkFrame.displaySurf) — dev+0x3ABC turned out to be the resolve-dest back buffer
  // object (0x...540), a DIFFERENT object from the default EDRAM RT the compose binds (0x...590).
  uint32_t rtSurf, rtW, rtH;
  uint32_t rtInfo;                // surf+0x18 RB_SURFACE_INFO (kept for the [nvkfmt] resolve log)
  uint32_t rtColorInfo;           // surf+0x1C RB_COLOR_INFO   (EDRAM base + colour format)
  // kind RESOLVE:
  uint32_t resolveDst;            // dest texture texel base (fetch dw1 decode)
  // ★ 2026-08-03 (banner root-fix follow-up): D3DDevice_Resolve pDestPoint (r7). ResolveEx
  // maps the source rect ONTO this point (dest base back-computed from destPoint - src.origin).
  // Games pass destPoint = rect origin so resolved content keeps its position; pasting at (0,0)
  // shifted the select-screen scroll cache by the rect origin (user: "not aligned to border").
  int32_t resolveDpX, resolveDpY;
  uint32_t resolveW, resolveH;    // dest dims (fetch dw2 decode)
  int32_t  srcRect[4];            // source rect x1,y1,x2,y2 (0,0,0,0 = full dest-sized region)
  uint32_t clearAfter;            // flags bit 0x200: clear EDRAM after the copy
  uint32_t clearColor;            // ARGB clear colour for clearAfter
} NvkDraw;

typedef struct NvkFrame {
  long     frame;
  uint32_t displaySurf;           // surface bound at Present = the display target (0xFFFFFFFF none)
  uint32_t clearARGB;             // D3DDevice_Clear r7 (packed ARGB)
  int      hasClear;
  int      nDraws;
  NvkDraw  draws[NVK_MAX_DRAWS];
  uint8_t* vtxBlob;               // raw guest (big-endian) vertex bytes, per-draw at vtxOff
  uint32_t vtxBytes;
  float*   vsBanks;               // nBanks * 1024 floats (c0..c255, host-endian)
  float*   psBanks;               // nBanks * 896  floats (c0..c223, host-endian)
  int      nBanks;
} NvkFrame;

#ifdef __cplusplus
extern "C" {
#endif
void nvk_frame_submit(uint8_t* base, NvkFrame* f);   // impl: render/vk_render.cpp (nvk section)
// COPY-AT-RECORD (2026-08-07): decode+upload a draw's texture AT RECORD TIME, while the guest
// bytes are still live, instead of at Present. Cheap on a cache hit (one map lookup) and a no-op
// until Vulkan is up. Full rationale above the impl. RT_NVKPREFETCH=0 reverts.
void nvk_tex_prefetch(uint32_t base, uint32_t w, uint32_t h, uint32_t fmt,
                      uint32_t tf0, uint32_t blendReg, uint32_t tf3);
#ifdef __cplusplus
}
#endif
