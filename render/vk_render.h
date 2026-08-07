// Futari port — our own Vulkan renderer (rexglue-free, UnleashedRecomp-architecture only).
// Clean C ABI so the recompiled shell's D3D9 hooks (shell/gen/rt.cpp) can drive it.
#pragma once
#include <cstdint>

extern "C" {

// Called from the shell's D3D9 Present hook (guest sub_820A5408) once per presented frame.
// base = guest flat-memory base; frame_start/frame_end = the PM4 command window for the
// frame just built (guest addrs; = ring_base+0x8000 .. device+0x30 write cursor). Lazily
// brings Vulkan up on first call, then walks the window and draws the game's textured quads.
void rvk_present(uint8_t* base, uint32_t frame_start, uint32_t frame_end);

// Optional explicit teardown (harness exit). Safe to skip.
void rvk_shutdown(void);

// ---- Decode-free render path (RT_HOOKRENDER) ----
// The shell's D3D draw hooks (shell/gen/rt.cpp) capture EVERY draw the game issues with exact
// params + CPU-read vertex bytes (bypassing the lossy PM4 window that only sees ~5-13 of ~99
// menu draws). On Present they hand the frame's full draw list here. Milestone 1: transform each
// quad by its matrix and render with vertex color + white texture, proving full capture.
struct RvkHookDraw {
  uint32_t prim;    // Xenos VGT primitive (5 = triangle fan)
  uint32_t count;   // vertex count
  uint32_t stride;  // vertex stride in DWORDS
  uint32_t voff;    // start offset into vpool, in DWORDS
  float    mtx[16]; // M2LibMatrix rows c0..c3 (native float), ndc.x=c0·v, ndc.y=c1·v, w=c3·v
  uint32_t tf[6];   // bound texture fetch constant (xe_gpu_texture_fetch_t); tf[0]==0 => white
  uint32_t blend;   // RB_BLENDCONTROL (reg 0x2201): [4:0]cSrc [7:5]cOp [12:8]cDst [20:16]aSrc [23:21]aOp [28:24]aDst; 0 => default SRC_ALPHA
  // RT_COMPOSE (2026-07-13): current render-target dims (h<<16|w, dev+0x28C8) and viewport VTE
  // floats {scaleX, offsetX, scaleY(neg = y-flip), offsetY} in screen pixels (dev+0x2908..14).
  // rtwh != (720<<16|1280) marks an OFFSCREEN pass (playfield bloom/downsample ring) that the
  // hook path must SKIP — the legacy PM4 decode renders those into g_resolveTex. For on-screen
  // blit-class (RECTLIST, translation-degenerate matrix) draws, vp IS the destination rectangle.
  uint32_t rtwh;
  float    vp[4];
};
// vpool = native-order (already byte-swapped) vertex dwords for the whole frame.
void rvk_present_hooked(uint8_t* base, const uint32_t* vpool, uint32_t vpoolDwords,
                        const RvkHookDraw* draws, int nDraws);

}
