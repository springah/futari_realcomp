// decomp/game/nvk_game_hooks.cpp — HARD PIVOT stage 2 (2026-07-28): GAME-module D3D twin taps.
//
// The game links a byte-identical D3D lib subset operating on the SHELL's device (C2 census,
// ATLAS_d3d_wrapper.md "GAME twin map"). rt.cpp cannot hook 0x88-range functions (it links AFTER
// the game tree; first-def-wins would silently discard the hook — the leg-35 landmine), so the
// strong wrappers live HERE in the decomp tree, which links FIRST. Each wrapper taps nvk_ev
// (RT_NVK=1 trace / stage-2 recon) and calls through to the generated __imp__ body.
//
// Stage-2 recon goal: which of these fire during ROM attract + gameplay, with what ABIs — the
// game side has DrawPrimitiveUP (8807F138), a streamed Begin/EndVertices path (8807ECA0/EC90,
// deferred 8807A1E0), packet-level SET_CONSTANT (8807A578) + fetch (8807A910), RECTLIST sprite
// batches (880702B0 / 8808E298), and its own Clear/Resolve/SetTexture/SetRT twins. Trace before
// translate. Inert without RT_NVK.
#include "ppc_recomp_shared.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>

extern "C" void nvk_ev(const char*, unsigned long long, unsigned long long, unsigned long long,
                       unsigned long long, unsigned long long, unsigned long long, unsigned long long);
extern "C" int  nvk_mode();
extern "C" void nvk_on_draw_core(uint8_t* base, unsigned dev, unsigned prim, unsigned count, unsigned strideB, unsigned scratch, unsigned dirtyPre, unsigned isGame);
extern "C" void nvk_on_resolve(uint8_t* base, unsigned dev, unsigned flags, unsigned pDestTex, unsigned pSrcRect, unsigned clearColor, unsigned pDestPoint);
extern "C" unsigned nvk_pack_cc(uint8_t* base, unsigned pcc);
extern "C" void nvk_on_clear(unsigned colorARGB);
#define NVK_TAP(name) nvk_ev(name, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64)
#define NVK_GHOOK(addr, name) \
  PPC_FUNC_IMPL(__imp__sub_##addr); \
  PPC_FUNC(sub_##addr){ NVK_TAP(name); __imp__sub_##addr(ctx,base); }

// sub_8807ECA0 = the game's D800-core twin (s2_game_abi): (dev, prim, count, strideB) -> r3 =
// scratch VB the caller fills after return. Capture at EXIT — same protocol as the shell core.
// The sprite-queue drain (880702B0) and DrawPrimitiveUP (F138) both funnel through here, so this
// ONE capture covers the game's whole draw mass.
PPC_FUNC_IMPL(__imp__sub_8807ECA0);
PPC_FUNC(sub_8807ECA0){
  NVK_TAP("G_BeginVertices");
  if(nvk_mode()>=2){
    uint32_t dv=ctx.r3.u32, pr=ctx.r4.u32, ct=ctx.r5.u32, st=ctx.r6.u32;
    auto be=[&](uint32_t ga){ uint32_t v; std::memcpy(&v, base+ga, 4); return v; };  // nonzero test only
    uint32_t dp=(be(dv)||be(dv+4)?1u:0u)|(be(dv+8)||be(dv+12)?2u:0u);
    __imp__sub_8807ECA0(ctx,base);
    nvk_on_draw_core(base, dv, pr, ct, st, ctx.r3.u32, dp, 1);
    return;
  }
  __imp__sub_8807ECA0(ctx,base);
}
// sub_8807DD88 = D3DDevice_Resolve (XDK-verified): r4=Flags (0x100 clear-RT-after, 0x200
// clear-depth-after, low3 surface sel), r5=pSourceRect, r6=pDestTexture, r7=pDestPoint,
// r10=pClearColor (POINTER to D3DVECTOR4, 4 BE floats).
PPC_FUNC_IMPL(__imp__sub_8807DD88);
PPC_FUNC(sub_8807DD88){
  NVK_TAP("G_Resolve");
  if(nvk_mode()>=2){
    uint32_t cc=0;
    // ★ CODE_REVIEW_0804 B9: the old read took r1+0x64 — that is arg 11 (pParameters), not a
    // colour — gated on 0x200 (the DEPTH clear flag). pClearColor is R10 and matters on 0x100.
    // RT_NVKCC=0 restores the old read for bisection.
    static const bool ccOff = [](){ const char* e = std::getenv("RT_NVKCC"); return e && e[0]=='0' && !e[1]; }();
    if(ccOff){
      if(ctx.r4.u32 & 0x200){ uint32_t w; std::memcpy(&w,(const void*)(base+ctx.r1.u32+0x64),4);
#if defined(_MSC_VER)
        cc=_byteswap_ulong(w);
#else
        cc=__builtin_bswap32(w);
#endif
      }
    } else if(ctx.r4.u32 & 0x300){
      cc=nvk_pack_cc(base, ctx.r10.u32);
    }
    // ★ 2026-08-03 char-select water-banner ROOT FIX: pSourceRect is in R5, not R10.
    // 8807DD88 IS D3DDevice_Resolve (XDK 20209.3 d3d9.lib resolve.obj, symbol-named:
    // (pDevice r3, Flags r4, pSourceRect r5, pDestTexture r6, pDestPoint r7, ..., pClearColor
    // r10)). Reading r10 meant every GAME resolve saw pRect=NULL → executor defaulted to a
    // dest-sized window at (0,0) → the select-screen scroll-cache pages resolved the WRONG
    // pane window (fresh strip at x>512 excluded) → the periodic "water banner"/black band.
    // The SHELL hook (820A2280) always read r5 correctly — why only ROM screens showed it.
    // ResolveEx semantics (decompiled: C:/Users/shant/Desktop/projects/_tools/xdk/xdk20209/resolveex_dec.txt): src rect is the
    // EDRAM window in screen coords; dest base is back-computed from (destPoint - src.origin).
    // RT_NVKR5=0 bisect lever (2026-08-03, added after the Score-Attack corruption report):
    // fall back to the OLD (wrong) r10 read so the r5 fix can be isolated from RT_NVKDP.
    static const bool r5Off = [](){ const char* e = std::getenv("RT_NVKR5"); return e && e[0]=='0' && !e[1]; }();
    nvk_on_resolve(base, ctx.r3.u32, ctx.r4.u32, ctx.r6.u32,
                   r5Off ? ctx.r10.u32 : ctx.r5.u32, cc, ctx.r7.u32);
  }
  __imp__sub_8807DD88(ctx,base);
}
// sub_8807D4F8 = game Clear-class (colour in r7, same family as shell 820A19F0).
PPC_FUNC_IMPL(__imp__sub_8807D4F8);
PPC_FUNC(sub_8807D4F8){
  NVK_TAP("G_Clear");
  if(nvk_mode()>=2) nvk_on_clear(ctx.r7.u32);
  __imp__sub_8807D4F8(ctx,base);
}

NVK_GHOOK(8807F138, "G_DrawPrimitiveUP")
NVK_GHOOK(8807EC90, "G_EndVertices")
// s2B leg 7 RETIRED (round 8) — all six constant-window hooks are back to plain taps.
// sub_8807A910 IS the game's ALU float emitter (two calls from the draw core 8807ECA0), but
// mirroring its ring output is pointless: it READS dev+0x780 (VS, reg base 0x4000) and
// dev+0x1780 (PS, base 0x4400) and walks the dirty masks at dev+0/dev+8 — the recorder already
// snapshots exactly those shadows on exactly those bits, so the device-shadow path is the
// register-true one. (The old "G_FetchConstPkt" label on A910 was also backwards: the
// fetch/boolean space 0x4800/0x4900 belongs to sub_8807A578 / sub_8807A7B8.)
// The other five were never constant emitters at all: FDF8 = ring/scratch allocator (never
// moves the cursor), FFB0 = ring-segment link/grow whose r3 is NOT the device (dev+13424 /
// dev+13568 sub-structs — the cursor read was garbage), B738 = TYPE-3 draw-state emitter,
// A638 = context registers (0x2388), A7B8 = fetch space (0x4800), A1E0 = SET_CONSTANT at
// cbase 0x2000.
NVK_GHOOK(8807A910, "G_AluFloatFlush")
NVK_GHOOK(8807A638, "G_ConstEmit638")
NVK_GHOOK(8807A7B8, "G_ConstEmit7B8")
NVK_GHOOK(8807A1E0, "G_DeferredCommit")
NVK_GHOOK(8807FDF8, "G_CoreEmitFDF8")
NVK_GHOOK(8807FFB0, "G_CoreEmitFFB0")
NVK_GHOOK(8807B738, "G_CoreEmitB738")
// G_SetConstantPkt (sub_8807A578) — writes SET_CONSTANT packets into the ring from the device
// shadow block (r6 = dev+0x28xx), walking the 64-bit dirty mask in r4. Its register bases are
// CONTEXT + fetch/boolean space (8192..9088, 18688), never the ALU float ranges.
// ⚠ CORRECTION (round 8): the earlier note here claimed "dev+0x780/0x1780 shadows are NEVER
// updated by the game module". That is FALSE and it misdirected all of leg 7 — sub_8807A910
// flushes the game's floats OUT OF those very shadows. RT_NVKGC=1 logs (mask, base, src, lr).
PPC_FUNC_IMPL(__imp__sub_8807A578);
PPC_FUNC(sub_8807A578){
  NVK_TAP("G_SetConstantPkt");
  static bool gc = std::getenv("RT_NVKGC")!=nullptr;
  if(gc){
    // Probe round 2: round-1 verdict = r5 8192..8960 are CONTEXT registers flushed FROM the
    // device shadow block (r6 = dev+0x28xx) — shadows are real. Question left: do FLOAT
    // constants (r5 >= 0x4000) ever flow here? Log those unconditionally + a base histogram.
    static long n=0; ++n;
    static long hist[8] = {0,0,0,0,0,0,0,0};   // r5>>12 buckets 0..7
    unsigned b = (unsigned)ctx.r5.u32 >> 12; if (b > 7) b = 7; ++hist[b];
    if(ctx.r5.u32 >= 16384){
      static long fc=0;
      if(fc++<40)
        std::fprintf(stderr,"[nvkgc] A578-FLOAT #%ld mask=%016llX base(r5)=%u src(r6)=%08X lr=%08X\n",
          n,(unsigned long long)ctx.r4.u64,(unsigned)ctx.r5.u32,(unsigned)ctx.r6.u32,(unsigned)ctx.lr);
    }
    if((n % 5000)==0)
      std::fprintf(stderr,"[nvkgc] A578 hist(4KB buckets r5>>12): %ld %ld %ld %ld %ld %ld %ld %ld\n",
        hist[0],hist[1],hist[2],hist[3],hist[4],hist[5],hist[6],hist[7]);
  }
  __imp__sub_8807A578(ctx,base);
}
// (8807A910 is hooked above as the ALU-constant emitter — its old "G_FetchConstPkt" label was
//  backwards; A578 is the fetch/boolean-space emitter.)
NVK_GHOOK(88079970, "G_CreateTexture")
NVK_GHOOK(88079B70, "G_SetTexture")
// G_SetRenderTarget probe (s2B leg 6, RT segmentation): dump args + object dwords under
// RT_NVKRTLOG; feed the recorder. Signature per C2 map: "SetRenderTarget-class (binds
// DAT_887ad5dc)" — registers logged to pin the real ABI before trusting it.
extern "C" void nvk_on_setrt(uint8_t* base, unsigned dev, unsigned idx, unsigned surf);
PPC_FUNC_IMPL(__imp__sub_88077E78);
PPC_FUNC(sub_88077E78){
  NVK_TAP("G_SetRenderTarget");
  uint32_t r3=ctx.r3.u32, r4=ctx.r4.u32, r5=ctx.r5.u32;
  static bool rtlog = std::getenv("RT_NVKRTLOG")!=nullptr;
  if(rtlog){
    static long n=0;
    if(n++<40){
      auto gbe=[&](uint32_t ga){ uint32_t v; std::memcpy(&v, base+ga, 4);
#if defined(_MSC_VER)
        return _byteswap_ulong(v);
#else
        return __builtin_bswap32(v);
#endif
      };
      std::fprintf(stderr,"[nvkrt] G_SetRT #%ld r3=%08X r4=%08X r5=%08X r6=%08X lr=%08X\n",
        n,r3,r4,r5,(unsigned)ctx.r6.u32,(unsigned)ctx.lr);
      uint32_t objs[2] = {r4, r5};
      for(int oi=0; oi<2; ++oi){ uint32_t p=objs[oi];
        if(p>0x1000u && p<0x20000000u){
          std::fprintf(stderr,"[nvkrt]   obj %08X:",p);
          for(int i=0;i<14;i++) std::fprintf(stderr," %08X",gbe(p+(uint32_t)i*4));
          std::fprintf(stderr,"\n");
        }
      }
    }
  }
  __imp__sub_88077E78(ctx,base);
  if(nvk_mode()>=2) nvk_on_setrt(base, r3, r4, r5);
}
NVK_GHOOK(88077AA8, "G_RS_BlendControl")
NVK_GHOOK(880702B0, "G_BatchQuadRectlist")
NVK_GHOOK(8808E298, "G_SpriteEmit")
