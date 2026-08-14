// decomp/shell/nvk.cpp — HARD PIVOT (2026-07-28): the new wrapper-altitude renderer.
//
// Stage 0 (RT_NVK=1): API TRACE ONLY — every hooked D3D wrapper call logs one line to
// C:/tmp/nvk_trace.log, frame-bracketed by Present.
//
// Stage 1+2 (RT_NVK=2): RECORDER. Draws are captured at the CORE draw kernels — shell
// sub_8209D800 and its byte-twin game sub_8807ECA0 — at EXIT (scratch VB addr in r3); the
// caller fills the scratch AFTER return and always commits before the kick that precedes
// Present, so vertex bytes are read lazily at Present (s1_abi §4 stability verdict). All
// other per-draw state is read REGISTER-TRUE off the shared guest device object at draw
// time (both modules maintain the same device; the game's "packet" functions are flush
// emitters reading these same shadows — s2 recon + s2_game_abi):
//   dev+0x480  stage-0 texture fetch shadow (object dwords merged with sampler bits)
//   dev+0x3244 PS object / dev+0x3248 VS object (microcode ptr+size inside the objects)
//   dev+0x2938 RB_BLENDCONTROL0   dev+0x3218.. viewport floats X,Y,W,H
//   dev+0x780 VS float bank c0..255 / dev+0x1780 PS bank c0..223 — snapshot per draw,
//   gated on the guest's OWN dirty qwords dev+0x00 (VS) / dev+0x08 (PS) read at draw entry
//   dev+0x2ABC bit0 = command-list build mode -> draw goes to a patch list, NOT the frame; skip.
// Resolves (shell sub_820A2280 / game sub_8807DD88 XGResolve) are ordered events that
// segment the frame; flags 0x100=setup-only (skip), low3==4=depth (skip), 0x200=clear-after.
// Clear (shell 820A19F0 / game 8807D4F8): colour in r7.
// Without RT_NVK this file is inert.
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <atomic>
#include "../../render/nvk_api.h"

static FILE* g_nf = nullptr;
static int  g_mode = 0;           // RT_NVK: 0=off, 1=trace, 2=render
static bool g_on = false;         // trace active (mode==1)
static std::atomic<long> g_nvkFrame{0};

static bool nvkInit() {
    const char* e = std::getenv("RT_NVK");
    g_mode = e ? std::atoi(e) : 0;
    g_on = (g_mode == 1);
    if (g_on) {
        g_nf = std::fopen("C:/tmp/nvk_trace.log", "w");
        if (g_nf) std::setvbuf(g_nf, nullptr, _IOFBF, 1 << 20);
        std::fprintf(stderr, "[nvk] API trace ACTIVE -> C:/tmp/nvk_trace.log\n");
    } else if (g_mode >= 2) {
        std::fprintf(stderr, "[nvk] RENDER MODE ACTIVE (RT_NVK=%d) — old renderer bypassed\n", g_mode);
    }
    return true;
}
static inline void nvkEnsureInit() { static bool i = nvkInit(); (void)i; }

extern "C" int nvk_mode() { nvkEnsureInit(); return g_mode; }

extern "C" void nvk_ev(const char* fn, unsigned long long r3, unsigned long long r4,
                       unsigned long long r5, unsigned long long r6, unsigned long long r7,
                       unsigned long long r8, unsigned long long r9) {
    nvkEnsureInit();
    if (!g_on || !g_nf) return;
    std::fprintf(g_nf, "f%ld %s r3=%llX r4=%llX r5=%llX r6=%llX r7=%llX r8=%llX r9=%llX\n",
                 g_nvkFrame.load(std::memory_order_relaxed), fn, r3, r4, r5, r6, r7, r8, r9);
}

extern "C" void nvk_present() {   // called from the Present hook AFTER __imp__ (frame boundary)
    nvkEnsureInit();
    if (g_mode == 0) return;
    long f = g_nvkFrame.fetch_add(1) + 1;
    if (g_on && g_nf) {
        std::fprintf(g_nf, "== present -> f%ld\n", f);
        if ((f % 300) == 0) std::fflush(g_nf);
    }
}

// ===== Stage-2 recorder (RT_NVK=2) =====================================================
// Single-threaded by construction: all wrapper calls and Present arrive on the guest's
// render thread (same assumption the old g_hkd hook capture shipped on).

static NvkFrame g_f;                              // frame under construction
static uint8_t  g_vtxBlob[2 << 20];               // 2MB raw guest vertex bytes / frame
static float    g_vsBanks[NVK_MAX_BANKS][1024];   // paired dirty-gated const snapshots
static float    g_psBanks[NVK_MAX_BANKS][896];
static int      g_nBanks = 0;

static inline uint32_t gbe32(const uint8_t* base, uint32_t ga) {
    uint32_t v; std::memcpy(&v, base + ga, 4);
#if defined(_MSC_VER)
    return _byteswap_ulong(v);
#else
    return __builtin_bswap32(v);
#endif
}

extern "C" void nvk_on_clear(unsigned colorARGB) {
    if (g_mode < 2) return;
    // ORDERED event (user-reported wallpaper-then-black, 07-28): the guest clears at a specific
    // position in the stream (menu-transition veils interleave with wallpaper draws); a
    // frame-level clear flag reorders it ahead of everything and wipes content the guest drew
    // before it. Recorded in place; the renderer segments on it.
    if (g_f.nDraws >= NVK_MAX_DRAWS) return;
    NvkDraw& d = g_f.draws[g_f.nDraws];
    std::memset(&d, 0, sizeof d);
    d.kind = NVK_KIND_CLEAR;
    d.clearColor = colorARGB;
    ++g_f.nDraws;
    g_f.clearARGB = colorARGB;   // kept for heartbeat display only
    g_f.hasClear = 1;            // kept so empty clear-only frames still render
}

// Deferred-copy discipline: a draw's scratch bytes are complete once the guest issues its NEXT
// wrapper call, and the kick arena recycles ~2MB/present IN-FIELD — reading everything at Present
// loses early draws to arena wrap (the WASH lesson at wrapper altitude). So bytes are copied at
// the NEXT draw-core call (arena cannot wrap between two consecutive allocations) and Present
// flushes the remainder.
// ★ RECORDER-SIDE PER-FRAME DROP/DIVERT COUNTERS (2026-07-31, compose census leg). The nvk
// census in render/vk_render.cpp measures MISSING draws on the frame it renders; when an element
// goes missing the first question is whether the GUEST stopped emitting it or whether the
// RECORDER diverted/dropped it. These three counters answer that on the same frame:
//   fBuild     draws captured into the static cmd-blob instead of this frame (build-mode,
//              dev+0x2ABC bit0) — they only reach the screen via the 8209B098 splice
//   fNoScratch draws the guest itself aborted (scratch/count/stride == 0) — register-true drop
//   fSpliced   blob draws spliced back into this frame
// Read by nvk_frame_submit (which runs BEFORE the per-frame reset in nvk_on_present_frame).
extern "C" { long g_nvk_fBuild = 0, g_nvk_fNoScratch = 0, g_nvk_fSpliced = 0; }
static int g_copiedUpTo = 0;   // draws [0, g_copiedUpTo) have their bytes in the blob
static void nvkCopyPending(uint8_t* base) {
    for (; g_copiedUpTo < g_f.nDraws; ++g_copiedUpTo) {
        NvkDraw& d = g_f.draws[g_copiedUpTo];
        if (d.kind != NVK_KIND_DRAW || !d.count || !d.scratchGuest) continue;   // !scratch = spliced blob draw, bytes final
        uint64_t bytes = (uint64_t)d.count * d.strideB;
        if (g_f.vtxBytes + bytes > sizeof g_vtxBlob) {
            static long vo = 0; if ((++vo % 1000) == 1) std::fprintf(stderr, "[nvk] VTX BLOB OVERFLOW x%ld\n", vo);
            d.count = 0; continue;
        }
        d.vtxOff = g_f.vtxBytes;
        std::memcpy(g_vtxBlob + g_f.vtxBytes, base + d.scratchGuest, (size_t)bytes);
        g_f.vtxBytes += (uint32_t)bytes;
    }
}

// ===== Static UI cmd-blob capture + replay (s2B leg 4, wallpaper-then-black) =============
// CmdListBuild sub_8209B180 allocates an 8KB blob (dev+13988) at CreateDevice: a state section
// (descr dev+13992/13996), 97 fetch-constant packets (patch table dev+14120..), and 24
// placeholder DRAW_INDX_2 packets {0xC0003600, 0x00010081} (descr dev+15024/15028). The blob is
// re-executed via the 3 INDIRECT_BUFFER packets SetShaderGPRAllocation sub_8209B098 emits —
// per-frame caller = compose core sub_8216B148 P1, right before its Resolve. Draws authored
// through the core while dev+0x2ABC bit0 (command-list build mode) is set patch that blob, never
// execute at author time; the recorder used to SKIP them (the hole: settled menus repaint the
// background only via blob re-execution). Now: capture them persistently (a 0->1 transition of
// the build bit starts a fresh burst that REPLACES the list = re-author semantics) and splice
// them into the frame stream at the 8209B098 position. RT_NVKNOBLOB=1 reverts the splice
// (capture + [nvkblob] probe stay live).
#define NVK_BLOB_MAX_DRAWS 96
#define NVK_BLOB_MAX_BANKS 8
static NvkDraw  g_blobDraws[NVK_BLOB_MAX_DRAWS];
static uint8_t  g_blobVtx[128 << 10];
static uint32_t g_blobVtxBytes = 0;
static float    g_blobVs[NVK_BLOB_MAX_BANKS][1024];
static float    g_blobPs[NVK_BLOB_MAX_BANKS][896];
static int      g_blobBanks = 0;
static int      g_blobN = 0;
static int      g_blobCopied = 0;      // pending-copy watermark (same next-call discipline)
static bool     g_inCmdlist = false;   // last core draw was build-mode (burst detector)

static void nvkCopyPendingBlob(uint8_t* base) {
    for (; g_blobCopied < g_blobN; ++g_blobCopied) {
        NvkDraw& d = g_blobDraws[g_blobCopied];
        if (d.kind != NVK_KIND_DRAW || !d.count || !d.scratchGuest) continue;
        uint64_t bytes = (uint64_t)d.count * d.strideB;
        if (g_blobVtxBytes + bytes > sizeof g_blobVtx) {
            static long bo = 0; if ((++bo % 100) == 1) std::fprintf(stderr, "[nvkblob] VTX OVERFLOW x%ld\n", bo);
            d.count = 0; continue;
        }
        d.vtxOff = g_blobVtxBytes;
        std::memcpy(g_blobVtx + g_blobVtxBytes, base + d.scratchGuest, (size_t)bytes);
        g_blobVtxBytes += (uint32_t)bytes;
    }
}

// Register-true device state at draw time (the core's own flush ladder runs from these).
// Shared by the frame path and the cmd-blob capture path.
static void nvkReadDrawState(uint8_t* base, unsigned dev, NvkDraw& d) {
    uint32_t texObj = gbe32(base, dev + 0x31B0);
    if (texObj) for (int i = 0; i < 6; ++i) d.tf[i] = gbe32(base, dev + 0x480 + (uint32_t)i * 4);
    uint32_t psObj = gbe32(base, dev + 0x3244);   // AB80 slot = pixel shader (s1_abi §8)
    uint32_t vsObj = gbe32(base, dev + 0x3248);   // AD40 slot = vertex shader
    d.vsUcode = vsObj ? gbe32(base, vsObj + 32) : 0;
    d.vsUcodeSize = vsObj ? gbe32(base, vsObj + 872 + 8) : 0;
    d.psUcode = psObj ? gbe32(base, psObj + 24) : 0;
    d.psUcodeSize = psObj ? gbe32(base, psObj + 40 + 8) : 0;
    d.blendReg = gbe32(base, dev + 0x2938);
    // Fixed-function ALPHA TEST (2026-07-29): the nvk draw path was memset-zeroing athresh on
    // every draw, i.e. dropping the discard the old renderer computes at vk_render.cpp:5138-5159.
    // Same register pair, read out of the device shadow instead of the PM4 register file:
    // RB_COLORCONTROL sits one dword above RB_BLENDCONTROL0, RB_ALPHA_REF is the float.
    d.colorCtl = gbe32(base, dev + 0x293C);
    d.alphaRef = gbe32(base, dev + 0x2904);
    for (int i = 0; i < 4; ++i)                       // RB_BLEND_RED..ALPHA (game sub_88075C38 stfs floats)
      d.blendConst[i] = gbe32(base, dev + 0x28E0 + (uint32_t)i * 4u);
    for (int i = 0; i < 4; ++i) {
        uint32_t w = gbe32(base, dev + 0x3218 + (uint32_t)i * 4);
        std::memcpy(&d.vp[i], &w, 4);
    }
    for (int i = 0; i < 4; ++i) {   // PA_CL_VPORT scale/offset shadow (register-true VTE ladder)
        // dev+0x2908 = {xscale, xoffset, yscale, yoffset} — located by runtime scan 2026-07-28
        // (shell default {640, 640, -360, 360}); the s1_abi 0x2920 group label was 0x18 off.
        uint32_t w = gbe32(base, dev + 0x2908 + (uint32_t)i * 4);
        std::memcpy(&d.vte[i], &w, 4);
    }
    d.vteCntl = gbe32(base, dev + 0x294C);   // PA_CL_VTE_CNTL (0x43F shell / 0x400 game field)

    // ★ COPY-AT-RECORD (2026-08-07): decode this draw's texture NOW, while the guest bytes are
    // still live. Our decode otherwise runs at Present, and anything the guest frees in between
    // decodes as noise — the char/shot-select first-entry corruption the 08-04 allocator
    // quarantine was papering over (and that quarantine fails the P7 512MB gate: measured
    // 08-07, high-water 513MB vs 496, because it rejects the streamer's ~16ms hot rotation).
    // The decode itself lives in the renderer; this only moves WHEN it happens. It is a cheap
    // map lookup once the texture is resident, and a no-op until Vulkan is up.
    // The fetch-constant decode below mirrors the executor's exactly (vk_render.cpp nvk path):
    // base = tf[1] bits 12.. << 12, W/H = tf[2] 13-bit fields + 1, fmt = tf[1] & 0x3F.
    if (d.tf[1]) {
        uint32_t tb = ((d.tf[1] >> 12) & 0xFFFFFu) << 12;
        if (tb) nvk_tex_prefetch(tb, (d.tf[2] & 0x1FFFu) + 1u, ((d.tf[2] >> 13) & 0x1FFFu) + 1u,
                                 d.tf[1] & 0x3Fu, d.tf[0], d.blendReg, d.tf[3]);
    }
}

// Core draw capture — shell D800 / game ECA0 exit. scratch==0 = guest dropped the draw.
// dirtyPre: bit0 = VS const dirty, bit1 = PS const dirty — read by the HOOK at core ENTRY,
// because the core's own flush ladder clears the device dirty qwords before it returns
// (exit reads always saw 0 → one bank/frame → every draw shared the first draw's constants:
// the flat-field/ps50-c14 bug).
extern "C" void nvk_on_draw_core(uint8_t* base, unsigned dev, unsigned prim, unsigned count,
                                 unsigned strideB, unsigned scratch, unsigned dirtyPre,
                                 unsigned isGame) {
    if (g_mode >= 2) { nvkCopyPending(base); nvkCopyPendingBlob(base); }   // previous draw's bytes are complete now
    // (round 4: constant mirror feeds from the emitter-window hooks, not the core-call ring —
    // the inter-call window contains raw inline vertex blobs and is not self-describing.)
    if (g_mode < 2) return;
    if (!count || !strideB || !scratch) { ++g_nvk_fNoScratch; return; }
    if (base[dev + 0x2ABC] & 1) {   // command-list build mode: patches the static blob, not this frame
        ++g_nvk_fBuild;
        if (!g_inCmdlist) {         // burst start = re-author: the new list REPLACES the old blob content
            if (g_blobN) std::fprintf(stderr, "[nvkblob] AUTH re-burst f%ld: %d draws replaced\n",
                                      g_nvkFrame.load(std::memory_order_relaxed), g_blobN);
            g_blobN = 0; g_blobVtxBytes = 0; g_blobBanks = 0; g_blobCopied = 0;
            g_inCmdlist = true;
        }
        if (g_blobN >= NVK_BLOB_MAX_DRAWS) {
            static long bd = 0; if ((++bd % 100) == 1) std::fprintf(stderr, "[nvkblob] DRAW OVERFLOW x%ld (cap %d)\n", bd, NVK_BLOB_MAX_DRAWS);
            return;
        }
        NvkDraw& d = g_blobDraws[g_blobN];
        std::memset(&d, 0, sizeof d);
        d.kind = NVK_KIND_DRAW;
        d.prim = prim & 0x3F; d.count = count; d.strideB = strideB;
        d.scratchGuest = scratch;
        nvkReadDrawState(base, dev, d);
        if (g_blobBanks == 0 || (dirtyPre & 3u)) {
            if (g_blobBanks < NVK_BLOB_MAX_BANKS) {
                float* vb = g_blobVs[g_blobBanks]; float* pb = g_blobPs[g_blobBanks];
                for (int i = 0; i < 1024; ++i) { uint32_t w = gbe32(base, dev + 0x780 + (uint32_t)i * 4); std::memcpy(&vb[i], &w, 4); }
                for (int i = 0; i < 896;  ++i) { uint32_t w = gbe32(base, dev + 0x1780 + (uint32_t)i * 4); std::memcpy(&pb[i], &w, 4); }
                ++g_blobBanks;
            }
        }
        d.bank = (uint32_t)(g_blobBanks - 1);
        ++g_blobN;
        if (g_blobN <= 8 || (g_blobN % 32) == 0)
            std::fprintf(stderr, "[nvkblob] AUTH f%ld d%d prim=%u n=%u st=%u scratch=%08X tex=%07X vs=%X ps=%X\n",
                         g_nvkFrame.load(std::memory_order_relaxed), g_blobN - 1, d.prim, d.count, d.strideB,
                         d.scratchGuest, d.tf[1] ? (((d.tf[1] >> 12) & 0xFFFFF) << 12) : 0u, d.vsUcode, d.psUcode);
        return;
    }
    g_inCmdlist = false;
    static long dropN = 0;
    if (g_f.nDraws >= NVK_MAX_DRAWS) { if ((++dropN % 1000) == 1) std::fprintf(stderr, "[nvk] DRAW OVERFLOW x%ld (cap %d)\n", dropN, NVK_MAX_DRAWS); return; }
    NvkDraw& d = g_f.draws[g_f.nDraws];
    std::memset(&d, 0, sizeof d);
    d.kind = NVK_KIND_DRAW;
    d.prim = prim & 0x3F; d.count = count; d.strideB = strideB;
    d.scratchGuest = scratch;
    nvkReadDrawState(base, dev, d);
    // const banks (s2B leg 7, module-split):
    // GAME module — floats come from the packet mirror (LOAD_ALU/SET_CONSTANT into the game
    // file), snapshotted when its generation moved. dev+0x780 never sees game values.
    // SHELL — unchanged: dev shadow snapshot gated on the guest's own dirty qwords at ENTRY.
    // ★ CONSTANT SOURCE — REGISTER-TRUE AND MODULE-AGNOSTIC (leg 7 final ruling, round 8).
    // The game module does NOT have a private float path: sub_8807A910 (its ALU-constant
    // emitter, called twice from the draw core 8807ECA0) reads its source arrays from
    // dev+1920 (= dev+0x780, VS, register base 0x4000) and dev+6016 (= dev+0x1780, PS, base
    // 0x4400), walking the 64-bit dirty masks at dev+0 / dev+8 — i.e. exactly the shadows and
    // exactly the dirty bits this snapshot already uses. The whole "game floats bypass the
    // shadows" premise of leg-7 rounds 1-7 was inverted; the mirror built on it delivered
    // c14={0,0,0,0} (a black multiply of the entire gameplay sprite layer in rom_ps50) and has
    // been retired. Proof on disk: with this path, ps50 c14 = {1.004,1.004,1.004,0} — matching
    // the working old renderer value-for-value (hole_probe.log vs floatsrc2.log).
    bool vsDirty = (dirtyPre & 1u) != 0;
    bool psDirty = (dirtyPre & 2u) != 0;
    (void)isGame;
    if (g_nBanks == 0 || vsDirty || psDirty) {
        if (g_nBanks < NVK_MAX_BANKS) {
            float* vb = g_vsBanks[g_nBanks]; float* pb = g_psBanks[g_nBanks];
            for (int i = 0; i < 1024; ++i) { uint32_t w = gbe32(base, dev + 0x780 + (uint32_t)i * 4); std::memcpy(&vb[i], &w, 4); }
            for (int i = 0; i < 896;  ++i) { uint32_t w = gbe32(base, dev + 0x1780 + (uint32_t)i * 4); std::memcpy(&pb[i], &w, 4); }
            ++g_nBanks;
        } else { static long bo = 0; if ((++bo % 1000) == 1) std::fprintf(stderr, "[nvk] BANK OVERFLOW x%ld\n", bo); }
    }
    d.bank = (uint32_t)(g_nBanks - 1);
    // [nvkdd] capped draw census: first 8 draws of every 600th frame — vte/vp/matrix row0 truth
    long fr = g_nvkFrame.load(std::memory_order_relaxed);
    if ((fr % 600) == 0 && g_f.nDraws < 8) {
        float m0 = g_vsBanks[d.bank][0], m5 = g_vsBanks[d.bank][5], m12 = g_vsBanks[d.bank][12], m13 = g_vsBanks[d.bank][13];
        std::fprintf(stderr, "[nvkdd] f%ld d%d prim=%u n=%u st=%u vte={%.0f,%.0f,%.0f,%.0f} vteCntl@294C=0x%X vp=%.0fx%.0f vs=%X ps=%X c0=%.4f c1.y=%.4f c3.xy=%.2f,%.2f dirty=%d%d\n",
                     fr, g_f.nDraws, d.prim, d.count, d.strideB, d.vte[0], d.vte[1], d.vte[2], d.vte[3],
                     gbe32(base, dev + 0x294C),
                     d.vp[2], d.vp[3], d.vsUcode, d.psUcode, m0, m5, m12, m13, (int)vsDirty, (int)psDirty);
    }
    ++g_f.nDraws;
}

// Blob re-execution — hook on SetShaderGPRAllocation sub_8209B098 (rt.cpp), AFTER __imp__.
// The guest just emitted the 3 INDIRECT_BUFFER packets re-running the static blob; splice the
// captured blob draws into the frame stream at this exact position (renderer unchanged — they
// render as ordinary ordered draws). Also the model-check probe: dumps the blob draw section
// so a boot log proves whether the 24 DRAW_INDX_2 placeholders ever get patched into real
// draws (D800-authored vs CPU-patched vs never — decides if this capture path is the cure).
extern "C" void nvk_on_blob_submit(uint8_t* base, unsigned dev) {
    if (g_mode < 2) return;
    // 8209B098 is the guest's next wrapper call after any pending draw: bytes are complete now.
    nvkCopyPending(base);
    nvkCopyPendingBlob(base);
    static long subN = 0; ++subN;
    long fr = g_nvkFrame.load(std::memory_order_relaxed);
    static bool dbg = std::getenv("RT_NVKDBG") != nullptr;
    if (subN <= 3 || (dbg && (fr % 600) == 0)) {
        uint32_t blob = gbe32(base, dev + 13988);
        uint32_t dsz  = gbe32(base, dev + 15024) & 0xFFFFFFu;         // draw-section dwords
        uint32_t dad  = gbe32(base, dev + 15028) & 0x1FFFFFFFu;       // draw-section guest addr
        std::fprintf(stderr, "[nvkblob] SUBMIT #%ld f%ld captured=%d blob=%08X drawsec=%08X(%u dw):",
                     subN, fr, g_blobN, blob, dad, dsz);
        if (dad > 0x1000u && dad < 0x20000000u)
            for (int i = 0; i < 12 && i < (int)dsz; ++i) std::fprintf(stderr, " %08X", gbe32(base, dad + (uint32_t)i * 4));
        std::fprintf(stderr, "\n");
    }
    static bool noBlob = std::getenv("RT_NVKNOBLOB") != nullptr;
    if (noBlob || !g_blobN) return;
    // splice: blob const banks -> frame banks once per submit, then draws at this position
    int bankBase = g_nBanks;
    for (int b = 0; b < g_blobBanks && g_nBanks < NVK_MAX_BANKS; ++b, ++g_nBanks) {
        std::memcpy(g_vsBanks[g_nBanks], g_blobVs[b], sizeof g_blobVs[b]);
        std::memcpy(g_psBanks[g_nBanks], g_blobPs[b], sizeof g_blobPs[b]);
    }
    int spliced = 0;
    for (int i = 0; i < g_blobN && g_f.nDraws < NVK_MAX_DRAWS; ++i) {
        NvkDraw d = g_blobDraws[i];
        if (d.kind != NVK_KIND_DRAW || !d.count) continue;
        uint64_t bytes = (uint64_t)d.count * d.strideB;
        if (g_f.vtxBytes + bytes > sizeof g_vtxBlob) break;
        std::memcpy(g_vtxBlob + g_f.vtxBytes, g_blobVtx + d.vtxOff, (size_t)bytes);
        d.vtxOff = g_f.vtxBytes; g_f.vtxBytes += (uint32_t)bytes;
        d.scratchGuest = 0;                      // marks bytes-final for nvkCopyPending
        uint32_t nb = d.bank + (uint32_t)bankBase;
        d.bank = nb < (uint32_t)g_nBanks ? nb : (uint32_t)(g_nBanks - 1);
        g_f.draws[g_f.nDraws++] = d;
        ++spliced; ++g_nvk_fSpliced;
    }
    static long sp = 0;
    if ((++sp % 300) == 1)
        std::fprintf(stderr, "[nvkblob] splice f%ld: %d draws @pos %d (banks +%d)\n",
                     fr, spliced, g_f.nDraws - spliced, g_blobBanks);
}

// s2B leg 7 RETIRED (round 8): the game float-constant mirror is GONE. It was built on an
// inverted premise — sub_8807A910 reads the game's ALU floats OUT OF dev+0x780 / dev+0x1780
// (the shadows the recorder already snapshots), so there was never a private path to mirror.
// The mirror shipped c14={0,0,0,0} to rom_ps50 = a black multiply over the whole gameplay
// sprite layer. History + the evidence tables live in NOTE_campaign_decomp.md leg 7.

// SetRenderTarget ordered event (s2B leg 6). ABI probe-pinned (RT_NVKRTLOG, /c/tmp/rtprobe.log):
// both wrappers are (dev, idx, pSurface); shell binds the default surface from compose core
// 8216D340, the game binds its field surface per frame from emitter 8808E4E4.
// Display discrimination: surf == the surface bound at Present (NvkFrame.displaySurf).
// Consecutive re-binds of the same surface are deduped (the emitter re-binds every frame).
//
// ★ SURFACE-SIZE DECODE — REGISTER-TRUE (s2B leg 9, 2026-07-29). The leg-6 reading
// "+0x1C = alloc height" was WRONG and is what produced the impossible [nvkrt] dims
// (640x720 for the 640x512 field target, 320x1808 for the 320x240 ring slots).
//   +0x18 = RB_SURFACE_INFO. Both wrappers copy it VERBATIM into the RB_SURFACE_INFO reg
//           shadow: shell FUN_82099A48 / game FUN_88077DE8 do `dev+0x2880 = *(surf+0x18)`
//           and derive the MSAA field from bits 17:16 (ghidra default_decomp_all.txt:42669,
//           reco_normal_decomp_all.txt:5343). Xenos layout = surface_pitch[13:0],
//           msaa_samples[17:16], hiz_pitch[31:18] — so the low 14 bits are the WIDTH and
//           there is no height in this dword. (s1_abi §SetRenderTarget: "+24 = size/pitch/
//           MSAA dword, +28 = RB_COLOR_INFO dword (EDRAM base + format)".)
//   +0x1C = RB_COLOR_INFO, written straight to the dev+0x2884+4k reg shadow. Its low 12 bits
//           are the EDRAM TILE BASE — that is the whole "720": a 1280x720 8888 target at base
//           0 occupies (1280/80)*(720/16) = 720 tiles, so the next target's base IS 720 and
//           the ring slots' bases are 1808 etc. Never a height.
//   +0x24 = the packed extent, (W-1)<<18 | (H-1)<<3. Proven on both surfaces the RT_NVKRTLOG
//           probe dumped (/c/tmp/rtprobe.log:114 / :1823):
//             shell display 0x358590  +0x18=0x14000500 (pitch 1280)  +0x24=0x13FC1678
//                 -> ((0x13FC1678>>18)&0x3FFF)+1 = 1280 ; ((0x13FC1678>>3)&0x7FFF)+1 = 720
//             game field    0x2725030 +0x18=0x0A000280 (pitch  640)  +0x24=0x09FC0FF8
//                 -> 640 x 512  (= the true field render size)
//           Two independent cross-checks hold on BOTH samples: the packed width equals
//           RB_SURFACE_INFO.surface_pitch, and +0x2C is the byte size (0x384000 = 1280*720*4,
//           0x140000 = 640*512*4) which divides back to the same heights.
// The OLD renderer never needed a surface height: it renders into the single 1280x720 offscreen
// and takes every pass extent from the RESOLVE dest instead (RB_COPY_DEST_PITCH reg 0x231A,
// w=&0x3FFF h=(>>16)&0x3FFF — render/vk_render.cpp:4441), which yields exactly 640x512 and
// 320x240 for these same passes. This decode reproduces the old renderer's numbers at wrapper
// altitude. RT_NVKOLDRTSZ=1 restores the leg-6 decode.
static uint32_t g_lastRtSurf = 0xFFFFFFFFu;
extern "C" void nvk_on_setrt(uint8_t* base, unsigned dev, unsigned idx, unsigned surf) {
    if (g_mode < 2) return;
    if (idx != 0) return;              // colour RT 0 only (no other index ever observed)
    if (surf == g_lastRtSurf) return;  // redundant re-bind: no segment break needed
    g_lastRtSurf = surf;
    nvkCopyPending(base); nvkCopyPendingBlob(base);   // wrapper-call boundary: prior scratch complete
    if (g_f.nDraws >= NVK_MAX_DRAWS) return;
    (void)dev;
    NvkDraw& d = g_f.draws[g_f.nDraws];
    std::memset(&d, 0, sizeof d);
    d.kind = NVK_KIND_SETRT;
    d.rtSurf = surf;
    // ★ CODE_REVIEW_0804 (6-swap bounce P6): the upper bound was 0x20000000 — a wild-pointer
    // guard written when the guest heap stayed under 512MB. The heap legitimately crosses that
    // line (user real-play sessions hit 544MB; multi-swap sessions push the bump pointer past
    // 0x24000000), and a D3D surface STRUCT allocated up there failed this guard: dims read
    // 0x0, getNvkRT declined, and every draw to that RT fell back to the display target
    // (1500+ "[nvkrt] offscreen target ... unavailable" in one bounce session). This is a CPU
    // struct pointer (flat-mapped virtual), NOT a GPU physical address — widening the guard is
    // the fix, no masking involved.
    // ⚠ DEFAULT OFF (08-04 eyeball): with the widened bound, high-heap draws route to real
    // offscreen RTs that nothing yet consumes — content that used to fall back to the display
    // target (visible, beta1 behaviour) VANISHES into black. Correct routing needs the
    // select-compose consumer from the decomp leg. RVK_RTHIGH=1 enables for that research.
    static const bool rtHigh = [](){ const char* e = std::getenv("RVK_RTHIGH"); return e && e[0]=='1' && !e[1]; }();
    if (surf > 0x1000u && surf < (rtHigh ? 0x80000000u : 0x20000000u)) {
        uint32_t info  = gbe32(base, surf + 0x18);   // RB_SURFACE_INFO
        uint32_t cinfo = gbe32(base, surf + 0x1C);   // RB_COLOR_INFO
        uint32_t szpk  = gbe32(base, surf + 0x24);   // (W-1)<<18 | (H-1)<<3
        uint32_t bytes = gbe32(base, surf + 0x2C);   // W*H*bpp
        d.rtInfo = info; d.rtColorInfo = cinfo;
        uint32_t pitch = info & 0x3FFFu;
        uint32_t newW = ((szpk >> 18) & 0x3FFFu) + 1u;
        uint32_t newH = ((szpk >> 3)  & 0x7FFFu) + 1u;
        uint32_t oldW = info & 0xFFFFu, oldH = cinfo ? (cinfo & 0xFFFFu) : 720u;
        // corroborator: byte size / (pitch * bpp); bpp from RB_COLOR_INFO.color_format[19:16]
        uint32_t cfmt = (cinfo >> 16) & 0xFu;
        uint32_t bpp = (cfmt == 5u || cfmt == 7u) ? 8u : 4u;   // 64bpp EDRAM formats
        uint32_t szH = (pitch && bytes) ? bytes / (pitch * bpp) : 0u;
        bool sane = (newW == pitch) && newW >= 16u && newW <= 4096u && newH >= 16u && newH <= 4096u;
        static bool oldSz = std::getenv("RT_NVKOLDRTSZ") != nullptr;   // leg-6 decode (revert lever)
        d.rtW = (oldSz || !sane) ? oldW : newW;
        d.rtH = (oldSz || !sane) ? oldH : newH;
        // one-shot per surface: old-vs-new dims + every dword the decode rests on
        static uint32_t seen[64]; static int nSeen = 0;
        bool fresh = true;
        for (int i = 0; i < nSeen; ++i) if (seen[i] == surf) { fresh = false; break; }
        if (fresh) {
            if (nSeen < 64) seen[nSeen++] = surf;
            std::fprintf(stderr,
                "[nvkrt] SIZE surf=%08X +18=%08X +1C=%08X +24=%08X +2C=%08X | old=%ux%u new=%ux%u "
                "(pitch=%u szH=%u cfmt=%u bpp=%u) sane=%d applied=%ux%u%s\n",
                surf, info, cinfo, szpk, bytes, oldW, oldH, newW, newH,
                pitch, szH, cfmt, bpp, (int)sane, d.rtW, d.rtH,
                oldSz ? " [RT_NVKOLDRTSZ]" : (szH && szH != newH ? " [!! szH DISAGREES]" : ""));
        }
    }
    ++g_f.nDraws;
    static int rl = 0;
    if (rl < 8) { ++rl; std::fprintf(stderr, "[nvkrt] REC setrt surf=%08X %ux%u\n", surf, d.rtW, d.rtH); }
}

// Resolve event — both 820A2280 (shell) and 8807DD88 (game) are D3DDevice_Resolve
// (r3=dev, r4=Flags, r5=pSourceRect, r6=pDestTexture, r7=pDestPoint, r10=pClearColor).
// ★ CODE_REVIEW_0804 B8 — FLAG TRUTH (XDK 20209.3 d3d9types.h:222-223, era-matched):
//   0x0100 = D3DRESOLVE_CLEARRENDERTARGET  "Clear the specified render target AFTER resolving"
//   0x0200 = D3DRESOLVE_CLEARDEPTHSTENCIL  (depth/stencil clear — no colour involved)
// The old gate treated 0x100 as "setup-only, no copy" and DROPPED the whole resolve — but the
// guest body (ppc_recomp.2 loc_8807E130) does the copy UNCONDITIONALLY; 0x100 only ADDS a
// clear. Every clear-after resolve therefore never reached this recorder → its dest surface
// never updated (prime suspect for the six never-baked 512x512 backdrop pages / water banner).
// clearAfter was ALSO keyed on 0x200 (the depth flag). RVK_RES100=0 restores both old readings.
extern "C" unsigned nvk_pack_cc(uint8_t* base, unsigned pcc) {
    // pClearColor is a POINTER to a D3DVECTOR4 (4 BE floats R,G,B,A), not a packed dword.
    // Pack to the ARGB the executor's setClear() consumes. NULL = transparent black.
    if (!pcc) return 0;
    auto ldf = [&](unsigned ga) { uint32_t v = gbe32(base, ga); float f; std::memcpy(&f, &v, 4); return f; };
    auto u8 = [](float f) { int i = (int)(f * 255.0f + 0.5f); return (unsigned)(i < 0 ? 0 : i > 255 ? 255 : i); };
    return (u8(ldf(pcc + 12)) << 24) | (u8(ldf(pcc)) << 16) | (u8(ldf(pcc + 4)) << 8) | u8(ldf(pcc + 8));
}
// ⚠ DEFAULT OFF (user eyeball 08-04): recording the 0x100 resolves with the CURRENT executor
// scrambles the 360 char-select backdrop (torn strips/black blocks) — the paste/alias pipeline
// downstream is calibrated to their absence. The flag semantics are still XDK-true; turning
// this ON is the entry point for the bake-pages research leg, which must land executor-side
// clear-after semantics at the same time. RVK_RES100=1 enables.
static bool nvk_res100_on() {
    static const bool on = [](){ const char* e = std::getenv("RVK_RES100"); return e && e[0]=='1' && !e[1]; }();
    return on;
}
// ★ CODE_REVIEW_0804 EVE — THE 512MB PHYSICAL-ALIAS IDENTITY FIX (RVK_PHYSKEY=0 reverts).
// Root cause of the entire post-swap visual family (grey-noise shot plates, black title,
// select staleness), proven in one instrumented session (/c/tmp/BANK_wedge_session.log):
// this recorder decodes the resolve DEST from the D3D texture HEADER — a CPU-side field that
// carries the RAW virtual address (0x243xxxxx observed once the guest heap crosses 512MB) —
// while the FETCH side flows through GPU registers/fetch constants the guest's own D3D code
// masks with &0x1FFFFFFF (hardware's physical aliasing, applied UNIFORMLY there). Above the
// line the two identities diverge: the strips' fetch key (0x043xxxxx) missed our raw-keyed
// resolve entry (0x243xxxxx) and the sampler decoded unrelated guest RAM = the noise.
// Masking the dest decode restores hardware's identity: below 512MB the mask is a no-op,
// above it both sides alias identically (collisions included — hardware has those too).
static unsigned nvk_phys_key(unsigned a) {
    static const bool on = [](){ const char* e = std::getenv("RVK_PHYSKEY"); return !(e && e[0]=='0' && !e[1]); }();
    return on ? (a & 0x1FFFFFFFu) : a;
}
extern "C" void nvk_on_resolve(uint8_t* base, unsigned dev, unsigned flags, unsigned pDestTex,
                               unsigned pSrcRect, unsigned clearColor, unsigned pDestPoint) {
    (void)dev;
    // ★ RVK_RESLOG=1 (2026-08-03, char-select bake hunt): ENTRY-altitude log, BEFORE every gate
    // below — distinguishes "the bake's resolve arrives but is filtered (flags/g_mode)" from
    // "the call never reaches this wrapper at all" (PPC_FUNC clone-bypass landmine, or the bake
    // rides a different API). Logs the first 40 calls plus EVERY call whose dest decodes into
    // the six unwritten 512x512 backdrop pages. Diagnostic only, default off.
    static const bool resLog = [](){ const char* e = std::getenv("RVK_RESLOG"); return e && atoi(e) != 0; }();
    if (resLog) {
        uint32_t dst0 = 0, w0 = 0, h0 = 0;
        if (pDestTex) {
            uint32_t dw1 = gbe32(base, pDestTex + 32), dw2 = gbe32(base, pDestTex + 36);
            dst0 = nvk_phys_key(((dw1 >> 12) & 0xFFFFF) << 12);
            w0 = (dw2 & 0x1FFF) + 1; h0 = ((dw2 >> 13) & 0x1FFF) + 1;
        }
        bool sixPage = (w0 == 512 && h0 == 512);
        static long rn = 0;
        if (++rn <= 40 || sixPage)
            std::fprintf(stderr, "[reslog] #%ld mode=%d flags=0x%X dst=0x%08X %ux%u pRect=%08X%s\n",
                         rn, g_mode, flags, dst0, w0, h0, pSrcRect, sixPage ? "  <== 512x512" : "");
    }
    if (g_mode < 2) return;
    if (!nvk_res100_on() && (flags & 0x100)) return;   // legacy misread: dropped clear-after resolves
    if ((flags & 7) == 4) return;         // depth-surface resolve: no colour to copy
    if (!pDestTex) return;
    if (g_f.nDraws >= NVK_MAX_DRAWS) return;
    NvkDraw& d = g_f.draws[g_f.nDraws];
    std::memset(&d, 0, sizeof d);
    d.kind = NVK_KIND_RESOLVE;
    uint32_t dw1 = gbe32(base, pDestTex + 32), dw2 = gbe32(base, pDestTex + 36);
    d.resolveDst = nvk_phys_key(((dw1 >> 12) & 0xFFFFF) << 12);   // see nvk_phys_key — the identity fix
    d.resolveW = (dw2 & 0x1FFF) + 1; d.resolveH = ((dw2 >> 13) & 0x1FFF) + 1;
    for (int i = 0; i < 6; ++i) d.tf[i] = gbe32(base, pDestTex + 28 + (uint32_t)i * 4);
    if (pSrcRect) for (int i = 0; i < 4; ++i) d.srcRect[i] = (int32_t)gbe32(base, pSrcRect + (uint32_t)i * 4);
    d.clearAfter = nvk_res100_on() ? ((flags & 0x100) ? 1u : 0u)    // colour clear-after (header truth)
                                   : ((flags & 0x200) ? 1u : 0u);  // legacy: keyed on the DEPTH flag
    d.clearColor = clearColor;
    // pDestPoint (D3DPOINT = 2 BE32 ints). NULL = the lib's static {0,0} default.
    d.resolveDpX = 0; d.resolveDpY = 0;
    if (pDestPoint) {
        d.resolveDpX = (int32_t)gbe32(base, pDestPoint);
        d.resolveDpY = (int32_t)gbe32(base, pDestPoint + 4);
    }
    // ★ RVK_RESLOG shape census (2026-08-03, Score-Attack corruption scoping): rect+dp of every
    // resolve whose rect origin or dp is nonzero, or whose paste would CLAMP at the page edge —
    // the candidates for the linear-RAM spill the host page-paste cannot express.
    {
        static const bool resLogS = [](){ const char* e = std::getenv("RVK_RESLOG"); return e && atoi(e) != 0; }();
        if (resLogS) {
            int32_t sx0 = d.srcRect[0], sy0 = d.srcRect[1], sx1 = d.srcRect[2], sy1 = d.srcRect[3];
            bool rect = sx1 > sx0 && sy1 > sy0;
            bool interesting = rect && ((sx0 | sy0 | d.resolveDpX | d.resolveDpY) != 0 ||
                                        (uint32_t)(sx1 - sx0) != d.resolveW ||
                                        (uint32_t)(sy1 - sy0) != d.resolveH);
            bool clamps = rect && (d.resolveDpX + (sx1 - sx0) > (int32_t)d.resolveW ||
                                   d.resolveDpY + (sy1 - sy0) > (int32_t)d.resolveH);
            // 2026-08-03 night: DEDUP BY SHAPE, NO CAP — the 120-line cap filled with one
            // second of pane resolves and never reached the late-stage corruption zone (the
            // capped-log trap, again). Every DISTINCT (dst,dims,rect,dp) prints exactly once.
            (void)interesting;
            if (rect) {
                struct SK { uint32_t a, b, c, d2, e; bool operator==(const SK& o) const {
                    return a==o.a && b==o.b && c==o.c && d2==o.d2 && e==o.e; } };
                static SK seen[256]; static int nSeen = 0; static long sn = 0;
                SK k{d.resolveDst, (d.resolveW<<16)|d.resolveH,
                     ((uint32_t)sx0<<16)|(uint32_t)(sy0&0xFFFF),
                     ((uint32_t)sx1<<16)|(uint32_t)(sy1&0xFFFF),
                     ((uint32_t)(d.resolveDpX&0xFFFF)<<16)|(uint32_t)(d.resolveDpY&0xFFFF)};
                bool fresh = true;
                for (int i = 0; i < nSeen; ++i) if (seen[i] == k) { fresh = false; break; }
                if (fresh && nSeen < 256) {
                    seen[nSeen++] = k;
                    std::fprintf(stderr, "[resshape] #%ld dst=0x%08X %ux%u rect={%d,%d,%d,%d} dp={%d,%d}%s\n",
                                 ++sn, d.resolveDst, d.resolveW, d.resolveH, sx0, sy0, sx1, sy1,
                                 d.resolveDpX, d.resolveDpY, clamps ? "  <== CLAMPS" : "");
                }
            }
        }
    }
    ++g_f.nDraws;
}

// RT_EXPECTCENSUS counters — strong defs in shell/gen/rt.cpp (emit hook + drain reporter).
extern "C" {
  extern volatile int g_ec_calls, g_ec_n;
  extern volatile unsigned g_ec_P[16];
  extern volatile int g_ec_entries[16], g_ec_expq[16], g_ec_drains[16], g_ec_qdepth[16];
}
extern "C" void nvk_on_present_frame(uint8_t* base) {
    if (g_mode < 2) return;
    nvkCopyPending(base);   // flush the tail draws' bytes
    nvkCopyPendingBlob(base);
    // display identity (s2B leg 6): the surface bound RIGHT NOW — at Present — is the frame's
    // display target; the renderer maps its segments onto g.image, all others get RT images.
    g_f.displaySurf = g_lastRtSurf;
    g_f.frame = g_nvkFrame.load(std::memory_order_relaxed);
    g_f.vtxBlob = g_vtxBlob;
    g_f.vsBanks = &g_vsBanks[0][0];
    g_f.psBanks = &g_psBanks[0][0];
    g_f.nBanks = g_nBanks;
    static long hb = 0;
    if ((++hb % 300) == 1)
        std::fprintf(stderr, "[nvk] f%ld draws=%d vtx=%uB banks=%d clear=%08X\n",
                     g_f.frame, g_f.nDraws, g_f.vtxBytes, g_nBanks, g_f.clearARGB);
    nvk_frame_submit(base, &g_f);
    // ★ RT_VEILLOG half 2 (compose lane, 2026-08-14): the veil-active windows — poll
    // *(*(*(0x821F858C)+0xC)+0x598) each present and print TRANSITIONS with the frame number.
    // Pairs with [veilblob] (rt.cpp) to give the future RVK_VEILCOVER draw its arm windows.
    {
        static const bool vl = std::getenv("RT_VEILLOG") != nullptr;
        if (vl) {
            static uint32_t last = 0xFFFFFFFFu;
            auto be32 = [&](uint32_t ea) { uint32_t u; std::memcpy(&u, base + ea, 4); return __builtin_bswap32(u); };
            uint32_t v = 0;
            const uint32_t fx = be32(0x821F858Cu);
            if (fx) { const uint32_t blk = be32(fx + 12); if (blk) v = be32(blk + 0x598); }
            if (v != last) {
                std::fprintf(stderr, "[veilwin] f%ld veil %s (0x598=%08X was %08X)\n",
                             g_f.frame, v ? "ACTIVE" : "clear", v, last);
                last = v;
            }
        }
    }
    // ★ RT_EXPECTCENSUS frame close (backlog #0 missing-draw census, 2026-08-14): the present
    // IS the frame boundary, so the emit/drain pairing is printed + reset here — independent
    // of RVK_DRAWTRIP (unlike [mvtick]). One line per frame with any activity; a picture node
    // with expected quads and ZERO drains this frame is the dropout, flagged MISS on its FIRST
    // frame. ⚠ Judge MISS lines against RVK_TITLEPROBE — authored hide square waves (PRESS
    // START blink, logo swap) are AUTHENTIC transients, not defects.
    {
        static const bool ecOn = std::getenv("RT_EXPECTCENSUS") != nullptr;
        if (ecOn) {
            int en = g_ec_n; if (en > 16) en = 16;
            bool any = false; char rb[512]; int ro = 0; int miss = 0;
            for (int i = 0; i < en && ro < (int)sizeof(rb) - 56; ++i) {
                if (!g_ec_entries[i] && !g_ec_expq[i] && !g_ec_drains[i]) continue;
                any = true;
                bool m = g_ec_expq[i] > 0 && g_ec_drains[i] == 0;
                if (m) ++miss;
                ro += std::snprintf(rb + ro, sizeof(rb) - ro, " |%X:e%d:x%d:d%d:q%d%s",
                    (unsigned)(g_ec_P[i] & 0xFFFFF), (int)g_ec_entries[i], (int)g_ec_expq[i],
                    (int)g_ec_drains[i], (int)g_ec_qdepth[i], m ? ":MISS" : "");
            }
            if (any)
                std::fprintf(stderr, "[expcen] f%ld emits=%d nP=%d miss=%d%s\n",
                             g_f.frame, (int)g_ec_calls, en, miss, rb);
            g_ec_calls = 0;
            for (int i = 0; i < en; ++i) { g_ec_entries[i] = 0; g_ec_expq[i] = 0; g_ec_drains[i] = 0; g_ec_qdepth[i] = 0; }
        }
    }
    g_f.nDraws = 0; g_f.vtxBytes = 0; g_f.hasClear = 0;
    g_nvk_fBuild = 0; g_nvk_fNoScratch = 0; g_nvk_fSpliced = 0;   // per-frame recorder counters
    g_nBanks = 0; g_copiedUpTo = 0;
    g_lastRtSurf = 0xFFFFFFFFu;   // next frame's first bind always records (renderer resets to display)
}
