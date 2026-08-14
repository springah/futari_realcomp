// decomp/shell/logo_indicator.cpp — the boot-logo tick FSM (fade-in / hold / fade-out) and the
// NOW-LOADING indicator (per-frame alpha ramp + show/hide). FIVE of the six family functions;
// the one-shot constructor sub_821D1890 (Logo_Build) STAYS GENERATED — its body is dense
// object-construction surgery scoped to its own follow-up leg (see
// decomp/shell/NOTE_logo_indicator_naturalization.md §7).
//
// Ground truth: shell/gen/ppc_recomp.36.cpp (sub_821D1780 :7267, sub_821D1740 :7229,
// sub_821D1670 :7105) and ppc_recomp.35.cpp (sub_821CCC48 :12478, sub_821CD120 :13209) —
// every body below transcribed from a full read of the generated instructions THIS session,
// not from the note alone. Two corrections earned by that read (note updated separately):
//   * the float-constant table is +0x40 off in the note/SPEC — the real pool base is
//     0x8204F7B0 (fadeStep +136 = 0x8204F838, logoByteScale +292 = 0x8204F8D4, indicator
//     alphaScale +184 = 0x8204F868, clip constants +116/+120/+124);
//   * sub_821CCC48's layout-bit sense is INVERTED vs the note: the (widescreen) A-constant
//     path is taken when FX+0x5A8 bit0 is CLEAR, not set.
//
// BOUNDARY TRUTH (recompiler > Ghidra): Ghidra's LAB_821D1740/LAB_821D1670 are REAL FUNCTIONS
// (own PPC_FUNC_IMPL, prologue, blr — the .pdata-driven recompiler split proves it), and no
// function exists at 0x821CD140 (the known mis-bound; real entry 0x821CD120).
//
// SEAM (measured, map-verified pattern):
//   sub_821D1780 / sub_821D1740 / sub_821D1670 — UNHOOKED → plain PPC_FUNC (strong beats the
//     generated weak alias; decomp_*.o links first).
//   sub_821CD120 — OWNED by merged_shell.cpp's RT_D1PROBE wrapper → __imp__ override form.
//   sub_821CCC48 — OWNED by shell/gen/rt.cpp's LP2_SHOWHIDE macro → __imp__ override form.
//   The owners' telemetry keeps firing around these bodies. sub_821796B0 (the per-element
//   modulate) stays generated, called via its plain symbol.
//
// ⚠ DO-NOT-FIX LIST (authentic, preserved):
//   * the record-count `twi` trap: the recompiler emits NO instruction for it (falls through)
//     — reproduced as nothing at all (the divw side effects are dead);
//   * the task+0x68 logo-skip byte is CLEARED only by FADE-IN; HOLD and FADE-OUT force the
//     fast-forward but never clear it;
//   * CD120's exact-0.0f re-hide store is authentic-unreachable on hardware (the up-ramp
//     never runs because +0x71 stays 0) — the port renders from the alpha byte; keep both;
//   * logo fades multiply RGB with alpha PINNED at 0x80 (0x80-unity semantics); the indicator
//     ramp writes a real 0..255 alpha byte — two different scales, never unify.
#include "ppc_recomp_shared.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Shell callee, declared locally: under build_win_dll.sh this TU compiles with GAME include
// paths (the documented, rt_indirect-neutralized seam), whose headers do not declare shell
// sub_ symbols. Same linkage as the generated definition.
PPC_FUNC(sub_821796B0);

namespace {

// ---- guest field offsets (decimal, matching the generated loads) ---------------------------
constexpr uint32_t TASK_STATE = 72;    // 0x48 state-fn pointer
constexpr uint32_t TASK_CAVE  = 92;    // 0x5C "cave" element (indicator: its "loading" element)
constexpr uint32_t TASK_CNT   = 100;   // 0x64 frame counter within the stage
constexpr uint32_t TASK_SKIP  = 104;   // 0x68 restart/skip byte (see DO-NOT-FIX)
constexpr uint32_t IND_ENABLE = 113;   // 0x71 show/hide enable byte
constexpr uint32_t IND_ALPHA  = 120;   // 0x78 f32 alpha
constexpr uint32_t ELEM_HIDE  = 12;    // 0x0C
constexpr uint32_t ELEM_COLOR = 252;   // 0xFC packed RGBA; LOW byte = alpha
constexpr uint32_t ELEM_RECB  = 268;   // 0x10C record-array begin
constexpr uint32_t REC_CLIPRUN   = 477;  // 0x1DD "clip is running"
constexpr uint32_t REC_CLIPSTART = 480;  // 0x1E0 f32
constexpr uint32_t REC_CLIPEND   = 484;  // 0x1E4 f32

// ---- ROM float pool, base 0x8204F7B0 (lis -32251, -2064) — REAL addresses, not the note's --
constexpr uint32_t F_CLIP_A     = 0x8204F824;  // +116: clip start, widescreen && !(FX+0x5A8 & 1)
constexpr uint32_t F_CLIP_END   = 0x8204F828;  // +120: clip end (both layouts)
constexpr uint32_t F_CLIP_B     = 0x8204F82C;  // +124: clip start, the other arm
constexpr uint32_t F_FADESTEP   = 0x8204F838;  // +136: the 1/60 per-tick step (logo + indicator)
constexpr uint32_t F_ALPHASCALE = 0x8204F868;  // +184: indicator alpha byte scale
constexpr uint32_t F_LOGOSCALE  = 0x8204F8D4;  // +292: logo fade byte scale (0x80-unity)
constexpr uint32_t F_UNITY      = 0x8203AAB4;  // 1.0f
constexpr uint32_t F_ZERO       = 0x82045508;  // 0.0f

constexpr uint32_t G_WIDESCREEN = 0x821ECF39;  // widescreen byte
constexpr uint32_t G_FXROOT     = 0x821F858C;  // FX/config root ptr; +0xC -> block; +0x5A8 bit0

// state-fn addresses (the FSM ring)
constexpr uint32_t ST_FADEIN  = 0x821D1780;
constexpr uint32_t ST_HOLD    = 0x821D1740;
constexpr uint32_t ST_FADEOUT = 0x821D1670;
constexpr uint32_t ST_NEXT    = 0x821D1540;   // CAVE->M2 swap stage (still generated)

inline float ld_f32(uint8_t* base, uint32_t ea) {
    uint32_t u = PPC_LOAD_U32(ea); float f; __builtin_memcpy(&f, &u, 4); return f; }
inline void st_f32(uint8_t* base, uint32_t ea, float f) {
    uint32_t u; __builtin_memcpy(&u, &f, 4); PPC_STORE_U32(ea, u); }

// The two fmuls + fctidz byte, exactly as generated: float(cnt) [fcfid+frsp exact for these
// magnitudes] * step (single-precision) * scale (single-precision), truncated toward zero to
// s64, low byte taken.
inline uint8_t fade_byte(uint8_t* base, int32_t cnt, uint32_t scaleEa) {
    const float a1 = (float)cnt * ld_f32(base, F_FADESTEP);
    const float a2 = a1 * ld_f32(base, scaleEa);
    return (uint8_t)(int64_t)a2;
}

} // namespace

// Per-CALLSITE counters (an inline-fn static would be ONE shared counter across all five tags
// — the indicator, ticking from frame one, ate the whole print budget on the first pilot run).
#define LI_CANARY(tag)                                                                  \
    do { static const bool on_ = std::getenv("RT_UPCANARY") != nullptr;                 \
         if (on_) { static int n_ = 0;                                                  \
             if (n_ < 6 || (n_ % 120) == 0)                                             \
                 std::fprintf(stderr, "[upcanary] " tag " #%d\n", n_);                  \
             ++n_; } } while (0)

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_821D1780 — logo FADE-IN, 60 frames. UNHOOKED → plain PPC_FUNC. NON-LEAF (one bl).
// Ground truth ppc_recomp.36.cpp:7267-7415. On the stage's first tick (cnt==0): unhide the cave
// element and start its clip. Skip byte: CLEARED here (the only stage that clears it) + cnt=60.
// Modulate cave with (a,a,a,0x80), a = (u8)(cnt * 1/60 * 128) — RGB ramp, alpha pinned.
// Transition at pre-increment cnt >= 60 → cnt=0, state=HOLD.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC(sub_821D1780)
{
    PPC_FUNC_PROLOGUE();
    LI_CANARY("Logo_FadeIn");
    const uint32_t task = ctx.r3.u32;

    const uint32_t sp = ctx.r1.u32 - 112;             // stwu r1,-112(r1)
    PPC_STORE_U32(sp, ctx.r1.u32);
    ctx.r1.u32 = sp;

    if (PPC_LOAD_U32(task + TASK_CNT) == 0)
    {
        const uint32_t cave = PPC_LOAD_U32(task + TASK_CAVE);
        PPC_STORE_U8(cave + ELEM_HIDE, 0);                       // UNHIDE
        const uint32_t rec = PPC_LOAD_U32(cave + ELEM_RECB);
        // (record-count twi: recompiler emits nothing — nothing reproduced)
        PPC_STORE_U8(rec + REC_CLIPRUN, 1);                      // START the clip
    }

    if (PPC_LOAD_U8(task + TASK_SKIP) != 0)
    {
        PPC_STORE_U8(task + TASK_SKIP, 0);                       // ★ the ONLY clear site
        PPC_STORE_U32(task + TASK_CNT, 60);
    }

    // modulate: r3 = cave+16, r4 = (a,a,a,0x80), lr = 0x821D1850
    {
        const int32_t  cnt  = (int32_t)PPC_LOAD_U32(task + TASK_CNT);
        const uint32_t cave = PPC_LOAD_U32(task + TASK_CAVE);
        const uint8_t  a    = fade_byte(base, cnt, F_LOGOSCALE);
        ctx.r3.u32 = cave + 16;
        ctx.r4.u32 = ((uint32_t)a << 24) | ((uint32_t)a << 16) | ((uint32_t)a << 8) | 0x80u;
        ctx.lr = 0x821D1850; sub_821796B0(ctx, base);
    }

    const uint32_t cnt = PPC_LOAD_U32(task + TASK_CNT);
    PPC_STORE_U32(task + TASK_CNT, cnt + 1);
    if ((int32_t)cnt >= 60)
    {
        PPC_STORE_U32(task + TASK_CNT, 0);
        PPC_STORE_U32(task + TASK_STATE, ST_HOLD);
    }

    ctx.r1.u32 = sp + 112;
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_821D1740 (Ghidra: "LAB_821D1740" — a REAL function) — HOLD, 120 frames. UNHOOKED → plain
// PPC_FUNC. LEAF, frameless. Ground truth ppc_recomp.36.cpp:7229-7264. Skip byte read, cnt=120
// forced, NOT cleared. cnt++ always; at pre-increment cnt >= 120 → cnt=0, state=FADE-OUT.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC(sub_821D1740)
{
    PPC_FUNC_PROLOGUE();
    LI_CANARY("Logo_Hold");
    const uint32_t task = ctx.r3.u32;

    if (PPC_LOAD_U8(task + TASK_SKIP) != 0)
        PPC_STORE_U32(task + TASK_CNT, 120);                     // forced; NOT cleared here

    const uint32_t cnt = PPC_LOAD_U32(task + TASK_CNT);
    PPC_STORE_U32(task + TASK_CNT, cnt + 1);
    if ((int32_t)cnt < 120)
        return;
    PPC_STORE_U32(task + TASK_CNT, 0);
    PPC_STORE_U32(task + TASK_STATE, ST_FADEOUT);
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_821D1670 (Ghidra: "LAB_821D1670" — a REAL function) — FADE-OUT, 60 frames. UNHOOKED →
// plain PPC_FUNC. NON-LEAF (one bl). Ground truth ppc_recomp.36.cpp:7105-7220. Skip byte read,
// cnt=60 forced, NOT cleared. a' = (u8)(0x80 - a) (subfic-exact; a<=0x80 so no wrap); no
// unhide/clip block (the element is already visible). Transition → cnt=0, state=ST_NEXT.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC(sub_821D1670)
{
    PPC_FUNC_PROLOGUE();
    LI_CANARY("Logo_FadeOut");
    const uint32_t task = ctx.r3.u32;

    const uint32_t sp = ctx.r1.u32 - 112;             // stwu r1,-112(r1)
    PPC_STORE_U32(sp, ctx.r1.u32);
    ctx.r1.u32 = sp;

    if (PPC_LOAD_U8(task + TASK_SKIP) != 0)
        PPC_STORE_U32(task + TASK_CNT, 60);                      // forced; NOT cleared here

    {
        const int32_t  cnt  = (int32_t)PPC_LOAD_U32(task + TASK_CNT);
        const uint32_t cave = PPC_LOAD_U32(task + TASK_CAVE);
        const uint8_t  a    = fade_byte(base, cnt, F_LOGOSCALE);
        const uint8_t  ap   = (uint8_t)(128 - (int32_t)a);       // subfic 0x80 - a
        ctx.r3.u32 = cave + 16;
        ctx.r4.u32 = ((uint32_t)ap << 24) | ((uint32_t)ap << 16) | ((uint32_t)ap << 8) | 0x80u;
        ctx.lr = 0x821D1700; sub_821796B0(ctx, base);
    }

    const uint32_t cnt = PPC_LOAD_U32(task + TASK_CNT);
    PPC_STORE_U32(task + TASK_CNT, cnt + 1);
    if ((int32_t)cnt >= 60)
    {
        PPC_STORE_U32(task + TASK_CNT, 0);
        PPC_STORE_U32(task + TASK_STATE, ST_NEXT);
    }

    ctx.r1.u32 = sp + 112;
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_821CD120 — indicator per-frame alpha ramp + the only writer of the re-hide. OWNED by
// merged_shell's RT_D1PROBE wrapper → __imp__ FORM. NON-LEAF (one bl per taken arm).
// Ground truth ppc_recomp.35.cpp:13209-13412 (real entry 0x821CD120; no fn at 0x821CD140).
//   enable!=0: if alpha < 1.0 → alpha += 1/60, clamp 1.0, modulate; else nothing.
//   enable==0: if alpha <= 0.0 → nothing (the FNF-12 guard). Else alpha -= 1/60, clamp 0.0,
//   modulate; after the call, reload alpha and at EXACT 0.0f re-hide + stop the clip
//   (authentic-unreachable in practice — preserved verbatim, do NOT "fix").
// Modulate arg: (u8)(alpha * *(F_ALPHASCALE)) | (elem+0xFC & 0xFFFFFF00). lr = 0x821CD1B0 (up)
// / 0x821CD21C (down).
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC_IMPL(__imp__sub_821CD120)
{
    PPC_FUNC_PROLOGUE();
    LI_CANARY("Indicator_Tick");
    const uint32_t self = ctx.r3.u32;
    const uint32_t elem = PPC_LOAD_U32(self + TASK_CAVE);        // +92: the "loading" element
    if (elem == 0) return;

    const uint32_t sp = ctx.r1.u32 - 112;             // stwu r1,-112(r1)
    PPC_STORE_U32(sp, ctx.r1.u32);
    ctx.r1.u32 = sp;

    const bool enabled = PPC_LOAD_U8(self + IND_ENABLE) != 0;
    const float unity  = ld_f32(base, F_UNITY);
    const float zero   = ld_f32(base, F_ZERO);
    const float step   = ld_f32(base, F_FADESTEP);

    if (enabled)
    {
        float alpha = ld_f32(base, self + IND_ALPHA);
        if (alpha < unity)
        {
            alpha = alpha + step;                                // fadds, single precision
            st_f32(base, self + IND_ALPHA, alpha);
            if (alpha > unity) { st_f32(base, self + IND_ALPHA, unity); }
            const float a2 = ld_f32(base, self + IND_ALPHA) * ld_f32(base, F_ALPHASCALE);
            const uint8_t a = (uint8_t)(int64_t)a2;              // fctidz low byte
            ctx.r3.u32 = elem + 16;
            ctx.r4.u32 = (uint32_t)a | (PPC_LOAD_U32(elem + ELEM_COLOR) & 0xFFFFFF00u);
            ctx.lr = 0x821CD1B0; sub_821796B0(ctx, base);
        }
        ctx.r1.u32 = sp + 112;
        return;
    }

    float alpha = ld_f32(base, self + IND_ALPHA);
    if (alpha > zero)
    {
        alpha = alpha - step;                                    // fsubs
        st_f32(base, self + IND_ALPHA, alpha);
        if (alpha < zero) { st_f32(base, self + IND_ALPHA, zero); }
        const float a2 = ld_f32(base, self + IND_ALPHA) * ld_f32(base, F_ALPHASCALE);
        const uint8_t a = (uint8_t)(int64_t)a2;
        ctx.r3.u32 = elem + 16;
        ctx.r4.u32 = (uint32_t)a | (PPC_LOAD_U32(elem + ELEM_COLOR) & 0xFFFFFF00u);
        ctx.lr = 0x821CD21C; sub_821796B0(ctx, base);

        if (ld_f32(base, self + IND_ALPHA) == zero)              // exact-equality, via the clamp
        {
            const uint32_t e2 = PPC_LOAD_U32(self + TASK_CAVE);  // reload, as generated
            PPC_STORE_U8(e2 + ELEM_HIDE, 1);                     // THE RE-HIDE (unreachable live)
            const uint32_t rec = PPC_LOAD_U32(e2 + ELEM_RECB);
            PPC_STORE_U8(rec + REC_CLIPRUN, 0);                  // stop the clip
        }
    }

    ctx.r1.u32 = sp + 112;
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_821CCC48 — indicator SHOW/HIDE. OWNED by rt.cpp's LP2_SHOWHIDE macro → __imp__ FORM.
// LEAF, frameless. Ground truth ppc_recomp.35.cpp:12478-12643.
// Idempotent on the enable byte; elem null-guard BEFORE the store. ALWAYS re-derives the clip
// window on SHOW and HIDE: start = *(F_CLIP_A) when widescreen byte != 0 AND (FX+0x5A8 & 1)==0
// (⚠ bit sense INVERTED vs the note — generated truth), else *(F_CLIP_B); end = *(F_CLIP_END)
// both arms. HIDE (onOff==0) returns after the window stores — arms the ramp only, never
// touches the hide byte. SHOW: instant unhide + clip start.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC_IMPL(__imp__sub_821CCC48)
{
    PPC_FUNC_PROLOGUE();
    LI_CANARY("Indicator_ShowHide");
    const uint32_t self  = ctx.r3.u32;
    const uint32_t onOff = ctx.r4.u32 & 0xFF;

    if (PPC_LOAD_U8(self + IND_ENABLE) == onOff) return;         // idempotent
    const uint32_t elem = PPC_LOAD_U32(self + TASK_CAVE);
    if (elem == 0) return;

    PPC_STORE_U8(self + IND_ENABLE, (uint8_t)onOff);

    // clip window, re-derived on BOTH arms
    bool useA = false;
    if (PPC_LOAD_U8(G_WIDESCREEN) != 0)
    {
        const uint32_t fx = PPC_LOAD_U32(G_FXROOT);
        const uint32_t blk = PPC_LOAD_U32(fx + 12);
        useA = (PPC_LOAD_U32(blk + 1448) & 1u) == 0;             // bit CLEAR selects A
    }
    const uint32_t rec = PPC_LOAD_U32(elem + ELEM_RECB);
    st_f32(base, rec + REC_CLIPSTART, ld_f32(base, useA ? F_CLIP_A : F_CLIP_B));
    st_f32(base, rec + REC_CLIPEND,   ld_f32(base, F_CLIP_END));

    if (onOff == 0) return;                                      // HIDE: ramp armed, nothing else

    const uint32_t e2 = PPC_LOAD_U32(self + TASK_CAVE);          // reload, as generated
    PPC_STORE_U8(e2 + ELEM_HIDE, 0);                             // SHOW: instant unhide
    const uint32_t r2 = PPC_LOAD_U32(e2 + ELEM_RECB);
    PPC_STORE_U8(r2 + REC_CLIPRUN, 1);                           // start the clip
}
