// Futari port — our own Vulkan renderer (rexglue-free; UnleashedRecomp is architectural
// inspiration only, no code adopted).
//
// TASK 8: real XenosRecomp-translated shaders. Two pipelines live side by side:
//   - "Real" pipeline (default): shared bindless pipeline layout (BDA push constants,
//     4 bindless descriptor sets), VkShaderModules built from render/shaders_futari.h,
//     raw (byteswapped) guest vertex data fed straight to the real VS, real constants
//     (VS/PS ALU float banks + SharedConstants) snapshotted into a per-frame BDA arena.
//   - "Passthrough" pipeline (RVK_PASSTHROUGH=1): the original CPU-transform sprite
//     VS/PS + per-texture descriptor sets, kept verbatim as an A/B / regression fallback.
// Both share the device/instance/offscreen target/renderpass/readback/PNG writer.
#include "vk_render.h"
#include "shaders_spv.h"
#include "xrgen_shaders.h"   // GENERATED (XenosRecomp glvl-d3d9) SPIR-V for the ROM shader set
#include "shaders_futari.h"  // shader table — ROM entries 48/49/50 reference the xrgen blobs above;
                             // entries 45/47 are repointed at runtime in getOrCreateModule (FIX-A)
#include <vulkan/vulkan.h>
// RVK_WINDOW (2026-07-13): optional on-screen present — a real Win32 window + VkSwapchainKHR the
// offscreen frame is blitted into every guest present. Default OFF (env-gated at initVk); the
// offscreen->PNG pipeline is untouched, so every existing runner/capture flow behaves identically.
#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <vulkan/vulkan_win32.h>
// RenderDoc in-application API (vendored from the 1.45 install, MIT). Declarations only — nothing
// is linked; the pointers are resolved from renderdoc.dll at runtime IF the process is hooked, so
// an unhooked build is unaffected. Used by RVK_RDCCAP to self-trigger a capture on the exact frame
// under investigation, since renderdoccmd has no capture-frame-N option.
#include "third_party/renderdoc_app.h"
#endif
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <set>
#include <atomic>
#include <mutex>
#include <algorithm>
#include <condition_variable>
#include <deque>
#include <string>
#include <thread>
// ---- GUEST .data ADDRESS PARAMETERIZATION (sibling-module builds) ----
// reco_abnormal (Ver 1.5 HI) has the SAME guest .data base but a 0x60-longer section: every
// global from 0x88351830 to the .data end sits at nor_addr + 0x60 (13756 code-side +0x60
// displacement deltas; _tmpscripts/abn_recomp_notes.md S2c).  build_win_abn.sh passes
// -DGA_DSHIFT=0x60u.  DEFAULT IS 0 => this is a no-op for the reco_normal build (verified by
// md5 of every obj_win/*.o).  Only the load-bearing addresses below are parameterized; the
// select-FSM 0x884D67xx / scene-FSM 0x884D66xx clusters are NOT (whole-cluster sweep pending
// - see _tmpscripts/abn_hooks_revive_notes.md).  Addresses in the genuinely-differing .data
// region 0x88250767..0x88351830 (0x88252504/8, 0x88252560) must NEVER be shifted by rule.
#ifndef GA_DSHIFT
#define GA_DSHIFT 0u   /* inert since L4 — see below */
#endif
// ★ L4 (2026-07-31) — THE LAST -DGA_DSHIFT CONSUMER IS RETIRED.  This was the documented L3
// follow-up (_tmpscripts/l3_descriptorise_notes.md §7.1): the renderer was still folding the
// guest address at COMPILE time, which is exactly wrong for a COMBINED exe, where one
// vk_render.o has to serve both modules and the correct address changes at runtime.  It now
// reads the live descriptor like every other host consumer.
//   per-module exe / DLL : futari_desc() is constexpr, so this folds to the same immediate the
//                          -D produced — provably behaviour-neutral (gate: -S digest).
//   combined exe         : a volatile pointer load + a field load, per use site.  ~20 sites,
//                          all per-frame or per-pass, none per-pixel.
#include "../host/futari_module_desc.h"
// GA_FIELD_ACTIVE  gameplay-field-active flag: present routing / pillarbox / compose + clear gating (vk_render), romactive clear (stubs.cpp XexUnloadImage). No sibling field is referenced anywhere.
#define GA_FIELD_ACTIVE  (futari_desc()->addrs.field_active)   // L4: was (0x885C1A20u + GA_DSHIFT)
// ---- end guest .data parameterization ----

// ★ L5 module swap: drop the guest-surface -> render-target map.  Declared here, at FILE scope,
// because g_nvkRT and its NvkRT value type live ~7000 lines below and OUTSIDE the anonymous
// namespace that opens on the next line — a `static` declaration inside that namespace would be
// a different entity (and clang says so: -Wundefined-internal).  Consumed by the swap
// invalidation inside getTexIndexReal.
static size_t rvkSwapDropNvkRT();
static size_t rvkSwapDestroyNvkRT();   // CODE_REVIEW_0804: destroy variant — caller guarantees device idle

namespace {

// RT_VTXSNAP DEFAULT-ON (select-compose flicker fix, 2026-07-15): the legacy decoder reads draw
// vertices from guest RAM at PRESENT time, but the guest recycles one ~10KB vertex-scratch window
// (~0xACBxxx, ~105 rebinds/frame) — by present time many draws' vertices are overwritten, producing
// per-frame degenerate-triangle shards + bright smears in the FIXB2 640x512 select-screen atlas
// (which RVK_PILLARBOX presents directly on field_active frames = the select/compose flicker).
// A/B-proven on the held char-select (2026-07-15): VTXSNAP=0 -> repeated shard/white-smear builds;
// VTXSNAP=1 -> 0 shard builds in 250+ (browse-driven) builds; matches rt.cpp's own RT_VTXSNAP doc
// ("degenerate triangles that smear bright HUD-atlas texels"). The lever lives in shell/gen/rt.cpp
// (rt_vtxsnap_on, lazy first-call read). The RT_VTXSNAP DEFAULT-ON flip now lives in rt.cpp's
// rt_vtxsnap_on() (2026-07-22) — the putenv hack that used to force it here (while rt.cpp was
// session-locked) has been removed. This static-init now only sets stderr unbuffered.
#ifdef _WIN32
// ★ 2026-07-27 survivability (playtest crash on B->TOP MENU died with ZERO trace): the async
// worker thread has no SEH containment, so a worker-side AV kills the process silently. This
// filter fires only for UNHANDLED exceptions (RT_EHCONTAIN's frame handlers still claim guest
// faults first), logs module-relative address + thread + AV kind, flushes, and lets the default
// termination proceed (nonzero exit). Next crash = one diagnosable log line instead of nothing.
static LONG WINAPI rvkCrashFilter(EXCEPTION_POINTERS* ep) {
  EXCEPTION_RECORD* er = ep->ExceptionRecord;
  HMODULE mod = nullptr;
  GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                     (LPCSTR)er->ExceptionAddress, &mod);
  char name[MAX_PATH]; name[0] = '?'; name[1] = 0;
  if (mod) GetModuleFileNameA(mod, name, sizeof name);
  std::fprintf(stderr, "\n[rvk] ==================== UNHANDLED CRASH ====================\n"
    "[rvk] code=0x%08lX addr=%p (%s+0x%llX) thread=%lu\n",
    er->ExceptionCode, er->ExceptionAddress, name,
    (unsigned long long)((uintptr_t)er->ExceptionAddress - (uintptr_t)mod), GetCurrentThreadId());
  if (er->ExceptionCode == EXCEPTION_ACCESS_VIOLATION && er->NumberParameters >= 2)
    std::fprintf(stderr, "[rvk] AV %s target=0x%llX\n", er->ExceptionInformation[0] ? "WRITE" : "READ",
                 (unsigned long long)er->ExceptionInformation[1]);
  std::fprintf(stderr, "[rvk] =========================================================\n");
  std::fflush(nullptr);
  return EXCEPTION_CONTINUE_SEARCH;
}
#endif
static const int s_vtxsnapDefault = [](){
  // stderr unbuffered (2026-07-21): one-shot diagnostics were lost to block buffering on quiet boots
  setvbuf(stderr, NULL, _IONBF, 0);
#ifdef _WIN32
  SetUnhandledExceptionFilter(rvkCrashFilter);
#endif
  return 0;
}();

constexpr uint32_t kW = 1280, kH = 720;
constexpr uint32_t kMaxVerts = 1u << 17;   // 128k verts / frame
constexpr uint32_t kMaxIndices = 1u << 18; // 256k indices / frame
constexpr uint32_t kMaxTextures = 256;
constexpr uint32_t kMaxBindlessImages = 1024;
constexpr uint32_t kMaxBindlessSamplers = 64;

struct Vtx { float x, y, u, v, r, g, b, a; };  // pos NDC, uv, color — PASSTHROUGH path only

struct Tex {
  VkImage image = VK_NULL_HANDLE;
  VkDeviceMemory mem = VK_NULL_HANDLE;
  VkImageView view = VK_NULL_HANDLE;
  VkDescriptorSet set = VK_NULL_HANDLE;
  // RVK_TEXREVALIDATE (2026-07-12, Windows menu-chrome white-box bug): dims/fmt + a cheap
  // content signature captured at upload time, so a later getTexture() call for the same
  // guest base address can detect staleness (see getTexture() below) instead of trusting
  // the cache forever.
  uint32_t w = 0, h = 0, fmt = 0, sig = 0;
};

struct RTex {  // bindless texture record — REAL path only
  VkImage image = VK_NULL_HANDLE;
  VkDeviceMemory mem = VK_NULL_HANDLE;
  VkImageView view = VK_NULL_HANDLE;
};

struct Vk {
  bool ok = false, failed = false;
  VkInstance instance = VK_NULL_HANDLE;
  VkPhysicalDevice phys = VK_NULL_HANDLE;
  VkDevice dev = VK_NULL_HANDLE;
  uint32_t qfam = 0;
  VkQueue queue = VK_NULL_HANDLE;
  // offscreen target (shared)
  VkImage image = VK_NULL_HANDLE;
  VkDeviceMemory imageMem = VK_NULL_HANDLE;
  VkImageView imageView = VK_NULL_HANDLE;
  VkBuffer readback = VK_NULL_HANDLE;
  VkDeviceMemory readbackMem = VK_NULL_HANDLE;
  // render pass / framebuffer (shared)
  VkRenderPass pass = VK_NULL_HANDLE;
  VkRenderPass passLoad = VK_NULL_HANDLE;  // LOAD_OP_LOAD variant: framebuffer persistence for 2D shell frames
  VkFramebuffer fb = VK_NULL_HANDLE;
  // ---- RVK_HDR tonemap: float g.image -> UNORM8 LDR intermediate (present/readback source) ----
  VkImage imageLdr = VK_NULL_HANDLE; VkDeviceMemory imageLdrMem = VK_NULL_HANDLE; VkImageView imageLdrView = VK_NULL_HANDLE;
  // Async-worker display image: the worker publishes each COMPLETE frame here (tonemapped under
  // HDR); the present thread's async fast path blits ONLY this, so it can run without g_mtx and
  // never shows a half-rendered g.image.
  VkImage imageShow = VK_NULL_HANDLE; VkDeviceMemory imageShowMem = VK_NULL_HANDLE;
  VkRenderPass passLdr = VK_NULL_HANDLE; VkFramebuffer fbLdr = VK_NULL_HANDLE;
  VkPipeline tmPipe = VK_NULL_HANDLE; VkPipelineLayout tmLayout = VK_NULL_HANDLE;
  VkDescriptorSetLayout tmDsl = VK_NULL_HANDLE; VkDescriptorPool tmPool = VK_NULL_HANDLE; VkDescriptorSet tmSet = VK_NULL_HANDLE;
  // ---- PASSTHROUGH pipeline (original) ----
  VkDescriptorSetLayout dsl = VK_NULL_HANDLE;
  VkPipelineLayout plLayout = VK_NULL_HANDLE;
  VkPipeline pipeline = VK_NULL_HANDLE;
  std::unordered_map<uint32_t, VkPipeline> hookPipelines;  // passthrough pipeline per RB_BLENDCONTROL (RT_HOOKRENDER)
  std::unordered_map<uint32_t, VkPipeline> ptPipelines;    // passthrough pipeline per RB_COLOR_MASK nibble (rank 21; mask==0xF reuses `pipeline`)
  VkDescriptorPool descPool = VK_NULL_HANDLE;
  VkSampler sampler = VK_NULL_HANDLE;
  Tex white;
  Tex black;   // FNF-1 (2026-07-27): transparent-black fallback for non-texture-typed fetch constants
  std::unordered_map<uint32_t, Tex> texCache;  // guest base addr -> GPU texture
  // ---- REAL (translated-shader) pipeline ----
  VkDescriptorSetLayout rDsl[4] = {VK_NULL_HANDLE, VK_NULL_HANDLE, VK_NULL_HANDLE, VK_NULL_HANDLE}; // 0=2D,1=3D,2=Cube,3=Sampler
  VkPipelineLayout rPlLayout = VK_NULL_HANDLE;
  VkDescriptorPool rDescPool = VK_NULL_HANDLE;
  VkDescriptorSet rSets[4] = {VK_NULL_HANDLE, VK_NULL_HANDLE, VK_NULL_HANDLE, VK_NULL_HANDLE};
  VkSampler rSampler = VK_NULL_HANDLE;
  VkSampler rSamplerPoint = VK_NULL_HANDLE;   // bindless sampler slot 1 (fetch-const POINT filter)
  // ★ RVK_TFCLAMP (2026-08-03, char-select water banner): slots 2/3 = CLAMP_TO_EDGE variants of
  // 0/1, picked per draw from the fetch constant's ClampX field (tf0[12:10], 2+ = clamp family).
  VkSampler rSamplerLinC = VK_NULL_HANDLE, rSamplerPointC = VK_NULL_HANDLE;
  std::unordered_map<uint64_t, VkPipeline> rPipelines;     // key (vsIdx<<32|psIdx)
  std::unordered_map<uint32_t, VkShaderModule> rModules;   // key shader idx into g_futari_shaders
  std::unordered_map<uint64_t, uint32_t> rTexIndex;        // key (base<<8|fmt) -> bindless index
  std::vector<RTex> rTexRecords;
  uint32_t rNextTexIndex = 1; // index 0 reserved for the white texture
  // constants arena (host-visible, buffer-device-address addressable)
  VkBuffer rArenaBuf = VK_NULL_HANDLE; VkDeviceMemory rArenaMem = VK_NULL_HANDLE; void* rArenaMap = nullptr;
  VkDeviceAddress rArenaAddr = 0;
  VkDeviceSize rArenaOffset = 0;
  VkDeviceSize rArenaSize = 0;
  // dynamic geometry (host-visible, shared by both paths — mutually exclusive per call)
  VkBuffer vbuf = VK_NULL_HANDLE; VkDeviceMemory vbufMem = VK_NULL_HANDLE; void* vbufMap = nullptr;
  VkBuffer ibuf = VK_NULL_HANDLE; VkDeviceMemory ibufMem = VK_NULL_HANDLE; void* ibufMap = nullptr;
  // staging for texture upload (shared)
  VkBuffer staging = VK_NULL_HANDLE; VkDeviceMemory stagingMem = VK_NULL_HANDLE; void* stagingMap = nullptr;
  VkDeviceSize stagingSize = 0;
  // cmd (shared): g.cmd/g.fence are REPOINTED per pass into this ring (2026-07-17 fence batching).
  // A pass that defers its wait marks its slot pending; the slot's fence is waited only when the
  // ring wraps back to it. GPU-side ordering across the fence-less submissions is guaranteed by
  // rvkRingGuard's catch-all barrier at the top of each converted pass.
  VkCommandPool pool = VK_NULL_HANDLE;
  VkCommandBuffer cmd = VK_NULL_HANDLE;
  VkFence fence = VK_NULL_HANDLE;
  VkCommandBuffer ringCmd[6] = {};
  VkFence ringFence[6] = {};
  bool ringPending[6] = {};
  int ringIdx = 0;
  VkFence segFence = VK_NULL_HANDLE;   // segBatchFlush's own fence (segCmd is its own buffer)
  // RVK_SEGBATCH (2026-07-17 attract 12fps fix): deferred command buffer for the per-frame
  // offscreen ops (segment renders + resolve blits). The legacy spine issued each op as its own
  // record+submit+VKWAITFORFENCES round-trip — ~20 full GPU syncs per attract frame = ~80ms =
  // the 12fps legacy present rate that throttled game logic (the msg-5 handshake rides presents).
  // With batching, ops record into segCmd and flush ONCE before anything consumes their output.
  VkCommandBuffer segCmd = VK_NULL_HANDLE;
  bool segOpen = false;
  char devname[256] = {0};
} g;

// [slowframe] per-frame spike attribution (2026-07-27 transition-spike leg): cheap counters,
// reset each renderFrameReal, dumped when a frame exceeds 100ms — names whether a 250ms+
// transition frame is texture uploads (count/bytes/ms), pipeline creations (count/ms), decode,
// or fences. Always-on (a few adds per upload/pipeline; prints only on spikes).
static long g_sfTexN = 0; static double g_sfTexMs = 0; static long long g_sfTexBytes = 0;
static long g_sfPipeN = 0; static double g_sfPipeMs = 0;

// One flush point: end+submit+wait the deferred seg command buffer (no-op when nothing recorded).
// Fence-wait timing shim (2026-07-17 attract-smoothness): every render pass in this file is a
// synchronous submit+wait pair — this accumulates the total blocked-on-GPU time per perflog window
// so the fence-latency share of the ~100ms frame cost is measurable. All vkWaitForFences call
// sites route through here (sed-swapped); behavior identical.
static double g_fenceMsAcc = 0.0; static long g_fenceN = 0;
static void rvkVkResultCheck(VkResult r, const char* where);   // defined below rvkVkFatal
static VkResult rvkWaitFences(VkDevice dev, uint32_t n, const VkFence* f, VkBool32 all, uint64_t to) {
  auto t0 = std::chrono::steady_clock::now();
  // Spin-poll before blocking (2026-07-17 attract-smoothness): the render path is ~18 serial
  // submit+wait pairs of sub-ms GPU work per frame; a BLOCKING wait pays a ~1-2.5ms scheduler
  // wakeup on each (measured [perflog] fences ≈ the whole ~50ms render tail). Polling with
  // timeout 0 for up to ~1.5ms retires sub-ms passes at actual GPU latency; longer waits fall
  // through to the blocking path unchanged. RVK_FENCESPIN=0 disables.
  static bool spin = !(std::getenv("RVK_FENCESPIN") && atoi(std::getenv("RVK_FENCESPIN")) == 0);
  VkResult r;
  if (spin) {
    do {
      r = vkWaitForFences(dev, n, f, all, 0);
      if (r == VK_SUCCESS) {
        g_fenceMsAcc += std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t0).count();
        ++g_fenceN;
        return r;
      }
    } while (std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t0).count() < 1.5);
  }
  r = vkWaitForFences(dev, n, f, all, to);
  g_fenceMsAcc += std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t0).count();
  ++g_fenceN;
  rvkVkResultCheck(r, "waitFences");   // CODE_REVIEW_0804 A6: a swallowed 10s VK_TIMEOUT was the hang's silence
  return r;
}
// [perflog3] (RVK_PERFLOG3=1) tail-phase attribution: between decode-end and renderFrameReal's
// return, wall time is attributed to the most recent pass boundary (every rvkRingNext carries its
// pass tag; segBatchFlush marks itself). Fence waits land inside whichever pass blocked, so the
// per-tag numbers are the true per-pass cost incl. record+submit+wait. vkQueueSubmit call time is
// accumulated separately (it is driver time NOT covered by the fence shim). All state is
// thread_local: only the worker's renderFrameReal activates it, other threads' ringNext no-op.
static thread_local bool g_p3active = false;
static thread_local const char* g_p3cur = nullptr;
static thread_local std::chrono::steady_clock::time_point g_p3t0;
struct P3Slot { const char* tag; double ms; long n; };
static thread_local P3Slot g_p3s[24]; static thread_local int g_p3nSlots = 0;
static thread_local double g_p3submitMs = 0; static thread_local long g_p3submitN = 0;
static void p3Close() {
  if (!g_p3active || !g_p3cur) return;
  double ms = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - g_p3t0).count();
  for (int i = 0; i < g_p3nSlots; ++i) if (g_p3s[i].tag == g_p3cur) { g_p3s[i].ms += ms; g_p3s[i].n++; g_p3cur = nullptr; return; }
  if (g_p3nSlots < 24) g_p3s[g_p3nSlots++] = {g_p3cur, ms, 1};
  g_p3cur = nullptr;
}
static void p3Mark(const char* tag) {
  if (!g_p3active || !tag) return;
  p3Close(); g_p3cur = tag; g_p3t0 = std::chrono::steady_clock::now();
}
static void p3FrameBegin() {
  static bool on = std::getenv("RVK_PERFLOG3") != nullptr;
  if (!on) return;
  g_p3active = true; g_p3cur = "tail-misc"; g_p3t0 = std::chrono::steady_clock::now();
}
static void p3FrameEnd(long frame) {
  if (!g_p3active) return;
  p3Close(); g_p3active = false;
  static thread_local long n = 0;
  if ((++n % 32) == 0) {
    char line[640]; int off = std::snprintf(line, sizeof line, "[perflog3] f%ld tail(avg/32):", frame);
    for (int i = 0; i < g_p3nSlots && off < (int)sizeof line - 48; ++i)
      off += std::snprintf(line + off, sizeof line - off, " %s=%.2f(n=%.1f)", g_p3s[i].tag, g_p3s[i].ms / 32, (double)g_p3s[i].n / 32);
    std::snprintf(line + off, sizeof line - off, " | qsubmit=%.2fms(n=%.1f)", g_p3submitMs / 32, (double)g_p3submitN / 32);
    std::fprintf(stderr, "%s\n", line);
    g_p3nSlots = 0; g_p3submitMs = 0; g_p3submitN = 0;
  }
}
// Queue-submission lock (2026-07-17 async render worker): once the render worker thread exists,
// two threads submit to g.queue (worker render passes; present thread window blits). VkQueue
// requires external sync — every vkQueueSubmit site routes through here (sed-swapped), and the
// window-present path wraps its vkQueuePresentKHR/vkQueueWaitIdle in the same lock. Held only
// across the submit call itself (fence WAITS happen outside), so cross-thread stalls are ~µs.
static std::mutex g_qMtx;
static VkResult rvkQueueSubmit(VkQueue q, uint32_t n, const VkSubmitInfo* si, VkFence f) {
  if (g_p3active) {
    auto t0 = std::chrono::steady_clock::now();
    std::lock_guard<std::mutex> ql(g_qMtx);
    VkResult r = vkQueueSubmit(q, n, si, f);
    g_p3submitMs += std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t0).count();
    ++g_p3submitN;
    rvkVkResultCheck(r, "queueSubmit");
    return r;
  }
  VkResult r;
  { std::lock_guard<std::mutex> ql(g_qMtx); r = vkQueueSubmit(q, n, si, f); }
  rvkVkResultCheck(r, "queueSubmit");   // CODE_REVIEW_0804 A6: 3 call sites ignored this result then
  return r;                             // blocked 5-10s on a fence the failed submit never signals
}
// Ring rotation (2026-07-17 fence batching): repoint g.cmd/g.fence to the next slot, waiting that
// slot's fence only if a previous pass deferred its wait there. Every pass site calls this before
// its reset; passes with no CPU-side dependency then SKIP their trailing wait (mark pending) —
// the ~1-2.5ms fence round-trip per pass collapses to one wait per ring wrap. RVK_CMDRING=0
// restores per-pass waits (rotation still happens; pending is never set).
static bool rvkRingOn() { static bool on = !(std::getenv("RVK_CMDRING") && atoi(std::getenv("RVK_CMDRING")) == 0); return on; }
static void rvkRingNext(const char* p3tag = nullptr) {
  p3Mark(p3tag);
  if (!g.ringCmd[0]) return;   // ring not allocated (pre-init call) — keep legacy single cmd
  int s = g.ringIdx = (g.ringIdx + 1) % 6;
  if (g.ringPending[s]) { rvkWaitFences(g.dev, 1, &g.ringFence[s], VK_TRUE, 10000000000ull); g.ringPending[s] = false; }
  g.cmd = g.ringCmd[s]; g.fence = g.ringFence[s];
}
// Catch-all execution+memory barrier at the top of a wait-deferred pass: makes the pass's GPU
// ordering vs ALL earlier submissions exactly as strong as the fence it replaced (a pipeline
// barrier's source scope covers previously submitted commands on the queue).
static void rvkRingGuard() {
  VkMemoryBarrier mb{VK_STRUCTURE_TYPE_MEMORY_BARRIER};
  mb.srcAccessMask = VK_ACCESS_MEMORY_WRITE_BIT;
  mb.dstAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
  vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                       0, 1, &mb, 0, nullptr, 0, nullptr);
}
static void segBatchFlush(){
  if(!g.segOpen) return;
  p3Mark("segflush");
  g.segOpen = false;
  vkEndCommandBuffer(g.segCmd);
  VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.segCmd;
  // Own fence (fence batching): g.fence is now a repointed ring slot; segCmd's reuse (next segOpen)
  // is what this wait protects, so it keeps a private fence and stays synchronous.
  vkResetFences(g.dev, 1, &g.segFence);
  rvkQueueSubmit(g.queue, 1, &si, g.segFence);
  rvkWaitFences(g.dev, 1, &g.segFence, VK_TRUE, 10000000000ull);
}
// Acquire the deferred buffer (begins recording on first use per flush cycle).
static VkCommandBuffer segBatchCmd(){
  if(!g.segOpen){
    vkResetCommandBuffer(g.segCmd, 0);
    VkCommandBufferBeginInfo bi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO};
    bi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    vkBeginCommandBuffer(g.segCmd, &bi);
    g.segOpen = true;
  }
  return g.segCmd;
}
static bool segBatchOn(){ static bool on = !(std::getenv("RVK_SEGBATCH") && atoi(std::getenv("RVK_SEGBATCH")) == 0); return on; }

std::mutex g_mtx;
std::atomic<long> g_frame{0};
// ★ r23-w17 mission C1(d): the shell-side DARKBD JOIN taps ([bdjoin]/[bddraw]/[closer] in
//   out_reco/merged/merged_shell.cpp) must be able to say WHICH RENDERER FRAME they fired on.
//   The join question is "does the backdrop path execute in the SAME FRAMES the wash predicate
//   fires on?", and the predicate is scored on RT_NVKPNG dumps whose FILENAMES ARE FRAME NUMBERS.
//   Without a shared clock the only common timebase is the `[nvk] f%ld draws=` heartbeat, which
//   prints once per 300 frames — five seconds of slack on a defect that can last one frame.
//   The consumer declares this __attribute__((weak)) (shell/gen/rt.cpp's rvk_present pattern), so
//   the headless build_win.sh link, which omits this TU entirely, still resolves.
// ⚠ g_frame IS THE WRONG CLOCK AT RT_NVK=2, and leg c1a proved it: every [bdjoin]/[bddraw]/
//   [closer] record came back stamped `f0`.  g_frame is incremented by rvk_present /
//   rvk_present_hooked; the nvk spine numbers its frames with nf->frame and never touches it.
//   g_nvkFrame below is stamped by nvk_frame_submit itself, so the shell taps and the RT_NVKPNG
//   filenames now share ONE counter -- which is the entire point of the join.
std::atomic<long> g_nvkFrame{0};
extern "C" long rvk_cur_frame(void) {
  long n = g_nvkFrame.load(std::memory_order_relaxed);
  return n ? n : g_frame.load(std::memory_order_relaxed);
}
// ★ CODE_REVIEW_0804 A5: swap guard — the module swap's memset/table-install/re-image used to
// run CONCURRENTLY with an in-flight frame walk whenever the 400ms invalidation ack timed out
// (it times out on effectively every swap: presents pause during the swap, so the worker can't
// reach the service point). A walk that loses that race reads half-zeroed guest memory and
// poisons the PERSISTENT register shadow (sticky garbage SETRT — seen as 1500+ [nvkrt]
// "unavailable" hits in the 6-swap bounce). The registry/bridge now hold g_mtx across their
// guest-memory mutation windows. MUST be taken AFTER rvk_module_swap_invalidate's ack wait —
// the worker needs g_mtx to reach the ack point. Callers never run guest code under the guard.
extern "C" void rvk_swap_guard_begin(void) { g_mtx.lock(); }
extern "C" void rvk_swap_guard_end(void)   { g_mtx.unlock(); }

// ---- RVK_WINDOW on-screen present state (2026-07-13, Windows-only) --------------------------
// A real window + swapchain the offscreen frame (g.image, TRANSFER_SRC_OPTIMAL after every
// rendered frame) is blitted into once per guest present. Lives beside the offscreen pipeline;
// nothing here runs unless RVK_WINDOW=1 was set at process start (initVk gates the required
// instance/device extensions on the same env, so a non-windowed run is byte-identical).
bool rvk_window_on() { static bool v = std::getenv("RVK_WINDOW") != nullptr; return v; }

// "Arcade ROM main is live" (set in merged_xex.cpp on sub_88168D48 entry, cleared never). Weak so the
// headless/non-merged builds that omit merged_xex still link — a null resolve reads 0, i.e. "not the
// ROM scene", which is the safe default for the pillarbox gate below.
extern "C" { volatile int g_rt_romactive __attribute__((weak)); }
// Pure extern (NOT a weak tentative def): the weak-def pattern above is COFF-fragile under
// lld-link /FORCE:MULTIPLE (the renderer's own zero copy can win the merge), which silently
// masked the menu-live signal. merged_xex.cpp always ships in this binary and owns the strong
// definition, so a plain declaration binds to it unambiguously.
extern "C" volatile unsigned int g_rt_menu_heartbeat;
// Last wall/wpNN.bin index the guest opened (strong def in rt.cpp file-open hook; 0 = none).
// The WALLBG=4 border blit follows it live (wp-index tracking, 2026-07-20).
extern "C" { volatile int g_rt_wpindex __attribute__((weak)); }
// ★ RT_MVTICK exports (FNF-7, 2026-07-26): M2Lib movie tick state, strong defs in rt.cpp's
// sub_8217F948 hook. Weak here so a build without that hook still links (values read as 0).
// Consumed by RVK_MVLOG in the RVK_DRAWTRIP block, which also RESETS the two call counters.
extern "C" {
  volatile int      g_mv_calls   __attribute__((weak));
  volatile int      g_mv_n       __attribute__((weak));
  volatile unsigned g_mv_o[12]   __attribute__((weak));
  volatile int      g_mv_p[12]   __attribute__((weak));
  volatile int      g_mv_t[12]   __attribute__((weak));
  volatile int      g_mv_b[12]   __attribute__((weak));
  volatile int      g_mv_v[12]   __attribute__((weak));
  volatile int      g_mv_c[12]   __attribute__((weak));
}
// ★ RT_SEGTAB exports (FNF-7 decisive experiment, 2026-07-26): the per-window table of segments
// rt_ks_append actually copied into the kick arena. Strong defs in rt.cpp; weak here so a build
// without that instrument still links (reads as 0 / nseg=0). Read-only from this side.
extern "C" {
  volatile int      g_seg_n      __attribute__((weak));
  volatile unsigned g_seg_wbase  __attribute__((weak));
  volatile unsigned g_seg_off[64] __attribute__((weak));
  volatile unsigned g_seg_len[64] __attribute__((weak));
  volatile unsigned g_seg_src[64] __attribute__((weak));
  volatile unsigned g_seg_pre[64] __attribute__((weak));
  volatile unsigned g_seg_obj[64] __attribute__((weak));
  volatile unsigned g_seg_lat[64] __attribute__((weak));
  volatile unsigned g_seg_objdw[64] __attribute__((weak));
}

// [fps] present pacing (2026-07-16). The port must match the ORIGINAL's transition speed, and until
// now there was no way to measure it — the RVK_PNGEVERY=1 default silently throttled presents to
// ~6fps and went unnoticed for exactly that reason. One line per RVK_FPS seconds (default 5) costs
// nothing and makes pacing regressions visible in every log. Console target is 60. Called from BOTH
// present entry points (rvk_present_hooked owns boot/title/menus; rvk_present owns the legacy/field
// spine) and tagged with which, since RT_HYBRID routes different screens down different paths.
// RVK_TIMERRES=<ms> — DIAGNOSTIC (2026-07-16): raise the Windows timer resolution via winmm's
// timeBeginPeriod (resolved dynamically so the link line needs no -lwinmm). Purpose: PROVE what sets
// our frame clock. The vblank pump (rt.cpp:331) is a `sleep_for(2ms)` loop that fires the guest's
// graphics-interrupt callback each iteration, and nothing in this codebase raises the timer
// resolution — so that 2ms sleep actually lands on Windows' ~15.6ms default granularity, making the
// guest's vblank ~64Hz BY ACCIDENT rather than by design (observed: 62.5 presents/sec uncapped).
// If this hypothesis is right, forcing 1ms resolution makes the vblank fire far faster and the game
// runs WAY too fast. Do not ship this on: it is the probe, not the fix.
static void rvk_timer_res_probe() {
  static bool done = false; if (done) return; done = true;
  const char* e = std::getenv("RVK_TIMERRES"); if (!e) return;
  unsigned ms = (unsigned)std::atoi(e); if (!ms) return;
  HMODULE wm = LoadLibraryA("winmm.dll");
  if (!wm) { std::fprintf(stderr, "[timerres] winmm.dll load FAILED\n"); return; }
  typedef unsigned (__stdcall *TBP)(unsigned);
  TBP tbp = (TBP)(void*)GetProcAddress(wm, "timeBeginPeriod");
  if (!tbp) { std::fprintf(stderr, "[timerres] timeBeginPeriod not found\n"); return; }
  unsigned r = tbp(ms);
  std::fprintf(stderr, "[timerres] timeBeginPeriod(%u) -> %u (0=OK). Sleep granularity now ~%ums.\n", ms, r, ms);
}

static void rvk_fps_tick(const char* which) {
  rvk_timer_res_probe();
  static int fpsPeriod = std::getenv("RVK_FPS") ? std::atoi(std::getenv("RVK_FPS")) : 5;
  if (fpsPeriod <= 0) return;
  static long fpsT0 = 0; static long fpsN = 0; static const char* fpsWhich = nullptr;
  long nowMs = (long)std::chrono::duration_cast<std::chrono::milliseconds>(
                 std::chrono::steady_clock::now().time_since_epoch()).count();
  if (!fpsT0) fpsT0 = nowMs;
  ++fpsN; fpsWhich = which;
  long dt = nowMs - fpsT0;
  if (dt >= (long)fpsPeriod * 1000L) {
    std::fprintf(stderr, "[fps] %.1f presents/sec (%ld in %.1fs, path=%s)\n",
                 (double)fpsN * 1000.0 / (double)dt, fpsN, (double)dt / 1000.0, fpsWhich ? fpsWhich : "?");
    fpsT0 = nowMs; fpsN = 0;
  }
}
bool g_anyRender = false;          // at least one render has filled g.image (blit source valid)
bool g_dumpWhiteTrig = false;      // RVK_DUMP_ON_WHITE: set by the first unsupported-fmt white fallback
#ifdef _WIN32
struct Win {
  HWND hwnd = nullptr;
  bool closed = false, failed = false, inited = false;
  VkSurfaceKHR surface = VK_NULL_HANDLE;
  VkSwapchainKHR swapchain = VK_NULL_HANDLE;
  VkFormat scFormat = VK_FORMAT_UNDEFINED;
  VkExtent2D scExtent{};
  std::vector<VkImage> scImages;
  VkSemaphore semAcquire = VK_NULL_HANDLE;
  // ONE blit->present semaphore PER SWAPCHAIN IMAGE, indexed by acquired image (FNF-2,
  // 2026-07-26): a single shared semaphore can be re-signaled while a prior present of a
  // DIFFERENT image still holds it — VUID-vkQueueSubmit-pSignalSemaphores-00067, caught live
  // by VVL on the ROM-handoff soak (fnf2_devloss_hunt.sh iter 6); prime suspect for the
  // intermittent VK_ERROR_DEVICE_LOST lottery. semAcquire may stay single: the deferred
  // fence wait below proves its waiter retired before every re-signal.
  std::vector<VkSemaphore> semBlit;
  VkCommandPool pool = VK_NULL_HANDLE;    // OWN pool: pools need external sync vs the worker's g.pool
  VkCommandBuffer cmd = VK_NULL_HANDLE;   // own cmdbuf so we never disturb g.cmd mid-frame
  VkFence fence = VK_NULL_HANDLE;
} gw;
#endif

// ★ 2026-07-27 SURVIVABILITY (FNF-2 fallback + FNF-8 P1; F&F ship gate: renderer death must be
// LOUD + nonzero exit, never a live guest behind a dead/hung window). Measured failure shape
// (d1b_shellreg_fnf_new.log): one -4 submit -> g.failed -> every later render call silently
// no-ops -> nobody pumps messages -> IsHungAppWindow, while guest logic runs on for minutes.
// Root cause of the loss itself is still open (FNF-2); this makes any hit survivable for a
// tester: banner, flush, exit nonzero. RVK_DIEHARD=1 restores the old keep-running-disabled
// behaviour (debugging / instrument drives that want the corpse). Exit codes: 3 = Vulkan call
// failed post-init, 4 = window bring-up failed, 5 = Vulkan init failed while hooked.
// std::_Exit after fflush: guest threads are recompiled Xbox threads that cannot be joined;
// a CRT exit path would hang on them, which is the exact defect this exists to remove.
static bool rvkDiehardOn() { static bool on = std::getenv("RVK_DIEHARD") && atoi(std::getenv("RVK_DIEHARD")) != 0; return on; }
[[noreturn]] static void rvkDieLoud(const char* what, int code) {
  std::fprintf(stderr,
    "\n[rvk] ==================== RENDERER FATAL ====================\n"
    "[rvk] %s\n"
    "[rvk] Exiting (code %d) so the game never runs on behind a dead\n"
    "[rvk] window. RVK_DIEHARD=1 keeps the old disabled-but-running\n"
    "[rvk] behaviour for debugging.\n"
    "[rvk] ========================================================\n", what, code);
  std::fflush(nullptr);
  std::_Exit(code);
}
static void rvkVkFatal(const char* what, int r) {
  char buf[160];
  std::snprintf(buf, sizeof buf, "Vulkan call '%s' failed with %d%s", what, r,
                r == -4 ? " (VK_ERROR_DEVICE_LOST — the FNF-2 lottery)" : "");
  rvkDieLoud(buf, 3);
}
// RVK_TESTDIE=1 (default-off fault injection): report a fake -4 on the first present after a
// healthy init — positive control for the die-loud path. A safety feature that has never fired
// is presumed broken until a control proves otherwise (5 instances of that class in the ledger).
static void rvkTestDieMaybe() {
  static bool on = std::getenv("RVK_TESTDIE") && atoi(std::getenv("RVK_TESTDIE")) != 0;
  if (on) { g.failed = true; if (!rvkDiehardOn()) rvkVkFatal("RVK_TESTDIE fault injection", -4); }
}
// ★ CODE_REVIEW_0804 A6 die-loud funnel: every rvkQueueSubmit / blocking rvkWaitFences result
// lands here. Before this, a failed submit was followed by a multi-second wait on a fence that
// could never signal, VK_TIMEOUT was swallowed everywhere (ringNext even cleared its pending
// flag as if the wait had succeeded), and DEVICE_LOST ground on silently at 10s/pass — the
// exact "renderer dead, process alive, zero log lines" shape of the 4th-swap hang.
// DEVICE_LOST now routes to the existing die-loud path (RVK_DIEHARD=1 keeps the corpse);
// everything else logs rate-limited.
static void rvkVkResultCheck(VkResult r, const char* where) {
  if (r == VK_SUCCESS) return;
  static std::atomic<long> n{0}; long i = n.fetch_add(1) + 1;
  if (i <= 16 || (i % 100) == 0)
    std::fprintf(stderr, "[rvk] VK FAIL %s -> %d (hit #%ld)\n", where, (int)r, i);
  if (r == VK_ERROR_DEVICE_LOST) {
    g.failed = true;
    if (!rvkDiehardOn()) rvkVkFatal(where, (int)r);
  }
}

#define VKC(expr, what) do { VkResult _r=(expr); if(_r!=VK_SUCCESS){ \
  std::fprintf(stderr,"[rvk] FAIL %s = %d\n", what, (int)_r); g.failed=true; \
  if (g.ok && !rvkDiehardOn()) rvkVkFatal(what, (int)_r); return false; } } while(0)

// ---------- guest memory helpers (big-endian) ----------
uint8_t* g_base = nullptr;
// Set by merged_xex RT_NAVREAL once the arcade-select FSM submits to the REAL stage (maxD76>=8);
// gates RVK_ARENADUMP to the held stage-1 field rather than attract/menu frames.
extern "C" volatile int g_rt_realstage;
inline uint32_t be32(uint32_t a){ return __builtin_bswap32(*(const uint32_t*)(g_base+a)); }
inline uint16_t be16(uint32_t a){ return __builtin_bswap16(*(const uint16_t*)(g_base+a)); }
inline float   bef(uint32_t a){ uint32_t v=be32(a); float f; std::memcpy(&f,&v,4); return f; }

// RVK_TITLETL (legacy-title-blink probe 2026-07-21): per-window count of decoded vs5rect16
// frame-base restore rects + the last base they sampled; logged and reset by the [titletl]
// timeline line in the doRender block.
static long g_ttl_rect16 = 0;
static uint32_t g_ttl_rectBase = 0;
// EDRAM-dup fix (2026-07-21): frame number of the most recent NON-EMPTY FIXB2 segment build per
// scratch size-class key — an empty segment in the SAME frame receives the same scratch content
// (back-to-back RB_COPYs of unchanged EDRAM). See the char-card painting fix in the FIXB2 path.
static std::unordered_map<uint32_t, long> g_fixb2ScratchF;

// 360 2D tiled-texture offset (Xenia texture_conversion formulas). log2_bpp: 0=8bpp,1=16bpp,2=32bpp.
uint32_t tiledOff(uint32_t x, uint32_t y, uint32_t width, uint32_t lb = 2, uint32_t pitchTexels = 0) {
  // Xenos 2D-tiled surfaces store macro-tile ROWS at a stride rounded UP to the next power of
  // two, NOT the logical width. Non-pow2 widths (e.g. 640) drift the macro-row read diagonally
  // -> regular black blocks. Round the macro pitch up to pow2 (Fable-5 verified on real tex).
  // Canonical Xenia GetTiledOffset2D. TWO fixes vs the old RVK version (which happened to work
  // only at 32bpp/lb=2 but corrupted 16bpp/lb=1 = the fmt-3 gameplay sprites into a black-dash
  // grid): (1) the x+y micro terms are COMBINED before the (&~15<<1)+(&15) swizzle, not swizzled
  // separately (the swizzle is non-linear); (2) there is NO separate ((x&8)<<3) term. Verified
  // clean on both the fmt-6 font atlas (lb=2) and the fmt-3 water/playfield textures (lb=1).
  // pitchTexels (2026-07-13, wallpaper banding root cause): when the caller knows the texture's
  // TRUE row pitch (the fetch constant's dword_0 bits 22..30, in 32-texel units), the macro-row
  // stride must be THAT pitch, not pow2(width) -- the pow2 rounding above was only ever verified
  // on pow2-width textures, where it is a no-op. The 1280x720 menu wallpaper is tiled at its
  // real pitch 1280; untiling it with a 2048 macro stride shears it into the horizontal-band
  // scramble (PROVEN offline: tile@1280 + untile@2048 of the linear wp01.bin body reproduces the
  // RVK_DUMPTEX scramble structurally, /c/tmp/wp01_tile1280_untile2048.png). 0 = legacy pow2
  // behavior for callers without a fetch constant.
  uint32_t pw;
  if (pitchTexels >= 32) pw = pitchTexels & ~31u;
  else { pw = width - 1; pw |= pw >> 1; pw |= pw >> 2; pw |= pw >> 4; pw |= pw >> 8; pw |= pw >> 16; ++pw; }
  uint32_t macro = ((x >> 5) + (y >> 5) * (pw >> 5)) << (lb + 7);
  uint32_t micro = (((y & 6) << 2) + (x & 7)) << lb;
  uint32_t off = macro + ((micro & ~15u) << 1) + (micro & 15u) + ((y & 8) << (3 + lb)) + ((y & 1) << 4);
  // RVK_TILEFIX (portrait-grid RE 2026-07-15): the final 64-byte micro-swizzle term's Y contribution.
  // The historical RVK value is ((y&8)>>2) = {0,2}; canonical Xenia GetTiledOffset2D uses ((y>>3)&1) =
  // ((y&8)>>3) = {0,1}. The >>2 form permutes 64-byte sub-blocks by parity of (y>>3) differently than
  // hardware -> the char-select 256x256 fmt-3 (k_1_5_5_5) portrait pages decode with vertical comb-
  // striping (dump of 0x17DB5000 = shredded portrait art). RVK_TILEFIX=1 selects the canonical >>3.
  // Default 0 = byte-identical to the shipped path.
  static const int tileFix = std::getenv("RVK_TILEFIX") ? std::atoi(std::getenv("RVK_TILEFIX")) : 0;
  uint32_t yTerm = tileFix ? ((y & 8) >> 3) : ((y & 8) >> 2);
  return ((off & ~0x1FFu) << 3) + ((off & 0x1C0u) << 2) + (off & 0x3Fu) + ((y & 16) << 7) + (((yTerm + (x >> 3)) & 3) << 6);
}

// RVK_TEXREVALIDATE: cheap content signature for cache-staleness detection (see getTexture()).
// Samples a fixed handful of texels (four corners + center) through the SAME tiled-address
// math getTexture() uses, so it costs ~5 guest reads instead of a full untile — affordable to
// call on every getTexture() cache hit (i.e. every draw that references a cached texture).
uint32_t texSignature(uint32_t base, uint32_t w, uint32_t h) {
  uint32_t sig = 0x811C9DC5u; // FNV-ish rolling mix, doesn't need to be cryptographic
  uint32_t xs[5] = {0, w - 1, 0, w - 1, w / 2};
  uint32_t ys[5] = {0, 0, h - 1, h - 1, h / 2};
  for (int i = 0; i < 5; ++i) {
    uint32_t px = be32(base + tiledOff(xs[i], ys[i], w));
    sig = (sig ^ px) * 0x01000193u;
  }
  return sig;
}

// ★ RVK_TRIPUV (FNF-7 atlas-staleness discriminator, 2026-07-26) — MEASURE ONLY, DEFAULT OFF.
// FNF-7's anomaly frames draw ONE EXTRA n=4 sprite quad from the menu atlases (guest bases
// 0x6921000 tex15 / 0x4C41000 tex9, both fmt=6) and a user capture proved such a quad rendered
// OPAQUE BLACK. The leading hypothesis is the known never-invalidated-texture-cache class
// (RVK_TEXREVALIDATE:~80, RVK_TILEPROBE): the guest wrote real art into the atlas AFTER our
// one-time upload, so the quad's UV region is art in GUEST RAM but black in our cached copy.
// Testing that needs both halves of the comparison, so this lever keeps a raw byte SNAPSHOT of
// every watched atlas taken at the exact instant getTexIndexReal() decodes it (re-taken on every
// RVK_TEXREVAL3 re-decode, so the snapshot always equals what the GPU currently holds) and, on an
// anomaly frame, censuses the extra draw's UV rect through BOTH the snapshot and LIVE guest RAM
// using the SAME tiledOff()/fmt-6 addressing the upload used. Reading back the VkImage would be
// equivalent but needs a staging round-trip on the render thread; the snapshot is byte-exact for
// the same question and costs one memcpy per upload.
// Snapshot is of the RAW guest bytes (pre-untile), so live/snapshot censuses share one address path.
struct RvkAtlasSnap {
  std::vector<uint8_t> bytes;
  uint32_t w = 0, h = 0, fmt = 0, lb = 2, fpitch = 0;
  int linear = 0;
  long uploads = 0, frame = -1;
};
static std::unordered_map<uint32_t, RvkAtlasSnap> g_tripSnap;   // guest base -> upload-time bytes
// RVK_TRIPUV level: 0=off, 1=extra-draw census, 2=+ same-atlas control draw (positive control).
static int rvkTripUvLevel() {
  static int lv = std::getenv("RVK_TRIPUV") ? std::atoi(std::getenv("RVK_TRIPUV")) : 0;
  return lv;
}
// Watched bases, comma-separated hex; default = the two FNF-7 menu atlases.
static bool rvkTripUvWatched(uint32_t base) {
  static std::vector<uint32_t> bs;
  static bool init = false;
  if (!init) {
    init = true;
    const char* e = std::getenv("RVK_TRIPUV_BASES");
    if (!e) e = "6921000,4C41000";
    for (const char* p = e; p && *p;) {
      bs.push_back((uint32_t)std::strtoul(p, nullptr, 16));
      const char* c = std::strchr(p, ',');
      p = c ? c + 1 : nullptr;
    }
  }
  for (uint32_t b : bs) if (b == base) return true;
  return false;
}
struct RvkCensus { uint32_t n = 0, nZeroPx = 0, nRgbBlack = 0, nOpaqueBlack = 0, nAlpha0 = 0; double meanLuma = 0; uint32_t sig = 0x811C9DC5u; };
// Census a texel rect of a fmt-6 (32bpp) surface. src==nullptr -> LIVE guest RAM at `base`;
// otherwise `src`/`srcBytes` = the upload-time snapshot (offsets are identical, both are raw
// guest bytes starting at `base`). Sample stride is chosen so no census exceeds ~4096 reads.
static RvkCensus rvkCensusRect(const uint8_t* src, size_t srcBytes, uint32_t base,
                               uint32_t w, uint32_t h, uint32_t lb, uint32_t fpitch, int linear,
                               uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1) {
  RvkCensus c{};
  if (x1 <= x0 || y1 <= y0 || !w || !h) return c;
  uint32_t rw = x1 - x0, rh = y1 - y0;
  uint32_t step = 1;
  while ((size_t)((rw + step - 1) / step) * ((rh + step - 1) / step) > 4096u) ++step;
  uint64_t lumaSum = 0;
  for (uint32_t y = y0; y < y1; y += step) for (uint32_t x = x0; x < x1; x += step) {
    // addressing mirrors getTexIndexReal()'s decode loop EXACTLY (linear = y*w+x, else tiledOff)
    uint32_t off = linear ? (uint32_t)(((size_t)y * w + x) << lb)
                          : tiledOff(x, y, w, lb, fpitch);
    uint32_t px;
    if (src) { if ((size_t)off + 4 > srcBytes) continue;
               px = ((uint32_t)src[off] << 24) | ((uint32_t)src[off+1] << 16) | ((uint32_t)src[off+2] << 8) | src[off+3]; }
    else     { px = be32(base + off); }
    uint8_t A = (px >> 24) & 0xFF, R = (px >> 16) & 0xFF, G = (px >> 8) & 0xFF, B = px & 0xFF;
    ++c.n;
    if (px == 0) ++c.nZeroPx;
    if (!R && !G && !B) ++c.nRgbBlack;
    if (!R && !G && !B && A == 0xFF) ++c.nOpaqueBlack;
    if (!A) ++c.nAlpha0;
    lumaSum += (uint32_t)R + G + B;
    c.sig = (c.sig ^ px) * 0x01000193u;
  }
  c.meanLuma = c.n ? (double)lumaSum / (3.0 * c.n) : 0.0;
  return c;
}

uint32_t findMem(uint32_t bits, VkMemoryPropertyFlags want) {
  VkPhysicalDeviceMemoryProperties mp{}; vkGetPhysicalDeviceMemoryProperties(g.phys, &mp);
  for (uint32_t i = 0; i < mp.memoryTypeCount; ++i)
    if ((bits & (1u << i)) && (mp.memoryTypes[i].propertyFlags & want) == want) return i;
  return UINT32_MAX;
}

bool makeBuffer(VkDeviceSize sz, VkBufferUsageFlags usage, VkMemoryPropertyFlags props,
                VkBuffer* buf, VkDeviceMemory* mem, void** map) {
  VkBufferCreateInfo bi{VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO};
  bi.size = sz; bi.usage = usage; bi.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
  VKC(vkCreateBuffer(g.dev, &bi, nullptr, buf), "vkCreateBuffer");
  VkMemoryRequirements mr{}; vkGetBufferMemoryRequirements(g.dev, *buf, &mr);
  VkMemoryAllocateInfo ai{VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO};
  ai.allocationSize = mr.size; ai.memoryTypeIndex = findMem(mr.memoryTypeBits, props);
  // HOST_CACHED is a performance preference (CPU-read-heavy download buffers), not a requirement:
  // fall back to the same request without it rather than failing the allocation.
  if (ai.memoryTypeIndex == UINT32_MAX && (props & VK_MEMORY_PROPERTY_HOST_CACHED_BIT))
    ai.memoryTypeIndex = findMem(mr.memoryTypeBits, props & ~VK_MEMORY_PROPERTY_HOST_CACHED_BIT);
  VKC(vkAllocateMemory(g.dev, &ai, nullptr, mem), "vkAllocateMemory(buf)");
  VKC(vkBindBufferMemory(g.dev, *buf, *mem, 0), "vkBindBufferMemory");
  if (map) VKC(vkMapMemory(g.dev, *mem, 0, VK_WHOLE_SIZE, 0, map), "vkMapMemory");
  return true;
}

// Buffer usable via vk::RawBufferLoad (SHADER_DEVICE_ADDRESS usage + DEVICE_ADDRESS alloc flag).
bool makeBdaBuffer(VkDeviceSize sz, VkBuffer* buf, VkDeviceMemory* mem, void** map, VkDeviceAddress* addr) {
  VkBufferCreateInfo bi{VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO};
  bi.size = sz; bi.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT;
  bi.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
  VKC(vkCreateBuffer(g.dev, &bi, nullptr, buf), "vkCreateBuffer(bda)");
  VkMemoryRequirements mr{}; vkGetBufferMemoryRequirements(g.dev, *buf, &mr);
  VkMemoryAllocateFlagsInfo flagsInfo{VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO};
  flagsInfo.flags = VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT;
  VkMemoryAllocateInfo ai{VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO};
  ai.pNext = &flagsInfo; ai.allocationSize = mr.size;
  ai.memoryTypeIndex = findMem(mr.memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
  VKC(vkAllocateMemory(g.dev, &ai, nullptr, mem), "vkAllocateMemory(bda)");
  VKC(vkBindBufferMemory(g.dev, *buf, *mem, 0), "vkBindBufferMemory(bda)");
  VKC(vkMapMemory(g.dev, *mem, 0, VK_WHOLE_SIZE, 0, map), "vkMapMemory(bda)");
  VkBufferDeviceAddressInfo bdai{VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO}; bdai.buffer = *buf;
  *addr = vkGetBufferDeviceAddress(g.dev, &bdai);
  return true;
}

VkShaderModule makeShader(const uint32_t* code, size_t bytes) {
  VkShaderModuleCreateInfo ci{VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO};
  ci.codeSize = bytes; ci.pCode = code;
  VkShaderModule m = VK_NULL_HANDLE;
  vkCreateShaderModule(g.dev, &ci, nullptr, &m);
  return m;
}

// RVK_HDR tonemap (2026-07-14, Part 2 of the 7e3-float overexposure fix): a fullscreen pass that
// samples the FLOAT g.image, applies exposure + a tonemap curve (Reinhard / ACES), and writes UNORM8
// g.imageLdr — which the present blit then shows. The DISPLAYALL path flattens the guest's HDR
// multi-pass into one additive pile-up with no tonemap; this compresses [0,inf)->[0,1] so the bloom
// reads as glow instead of hard-clamping to white.
// SHADER SOURCE OF RECORD (F7, compile with: glslc -O tonemap.vert -mfmt=c -o -):
//   --- tonemap.vert ---
//   #version 450
//   layout(location = 0) out vec2 vUV;
//   void main() {
//     vUV = vec2((gl_VertexIndex << 1) & 2, gl_VertexIndex & 2);
//     gl_Position = vec4(vUV * 2.0 - 1.0, 0.0, 1.0);
//   }
//   --- tonemap.frag ---  (source of record: _tmpscripts gen in the 2026-07-19 register-true pass;
//   modes 0/1/2 unchanged; mode 3 added = REGISTER-TRUE present.)
//   #version 450
//   layout(location = 0) in vec2 vUV;
//   layout(location = 0) out vec4 oColor;
//   layout(set = 0, binding = 0) uniform sampler2D tex;
//   layout(push_constant) uniform PC { float exposure; int mode; } pc;
//   const float kGamma[256] = float[256]( /* game DC_LUT ramp, see below */ );
//   void main() {
//     vec3 c = max(texture(tex, vUV).rgb, vec3(0.0)) * pc.exposure;   // NOTE (F1): exposure applied
//     vec3 m;                                                          // BEFORE the branch, so mode 2 is
//     if (pc.mode == 1) {            // ACES filmic (Narkowicz)         // identity only when exposure==1
//       const float a=2.51,b=0.03,cc=2.43,d=0.59,e=0.14;
//       m = clamp((c*(a*c+b))/(c*(cc*c+d)+e), 0.0, 1.0);
//     } else if (pc.mode == 2) {     // exposure + hard clamp
//       m = clamp(c, 0.0, 1.0);
//     } else if (pc.mode == 3) {     // register-true: clamp -> 8-bit quantize -> game DC_LUT ramp
//       ivec3 q = ivec3(clamp(c, 0.0, 1.0) * 255.0 + 0.5);
//       m = vec3(kGamma[q.r], kGamma[q.g], kGamma[q.b]);
//     } else {                       // Reinhard
//       m = c / (c + vec3(1.0));
//     }
//     oColor = vec4(m, 1.0);
//   }
// kGamma = the GAME-PROGRAMMED 256-entry DC_LUT display gamma ramp (R==G==B, 10-bit /1023), extracted
// from the SDK-oracle field capture: field_frame69722.rdc gamma-table upload buffer via
// _tmpscripts/extract_oracle_gamma.py (C:\tmp\oracle_gamma\buf_439_2560B.bin). It is NOT the SDK's
// linear boot default (i*0x3FF/0xFF) => the game programmed it (after VdGetCurrentDisplayGamma
// reports type 2 = BT.709). Mode 3 replicates real scanout exactly: the 8888 framebuffer is 8-bit,
// the DC_LUT is indexed per 8-bit channel — quantize-then-index, no interpolation. REMAINING GAP
// (documented, not fudged): the game's DC_LUT writes don't flow through the PM4 ring we decode, so
// the table is baked from the oracle extraction instead of decoded at runtime; re-extract with the
// script above if a scene ever programs a different ramp.
static const uint32_t kTonemapVertSpv[] = {
0x07230203,0x00010000,0x000d000b,0x0000002c,0x00000000,0x00020011,0x00000001,0x0006000b,
0x00000001,0x4c534c47,0x6474732e,0x3035342e,0x00000000,0x0003000e,0x00000000,0x00000001,
0x0008000f,0x00000000,0x00000004,0x6e69616d,0x00000000,0x00000009,0x0000000c,0x0000001d,
0x00040047,0x00000009,0x0000001e,0x00000000,0x00040047,0x0000000c,0x0000000b,0x0000002a,
0x00030047,0x0000001b,0x00000002,0x00050048,0x0000001b,0x00000000,0x0000000b,0x00000000,
0x00050048,0x0000001b,0x00000001,0x0000000b,0x00000001,0x00050048,0x0000001b,0x00000002,
0x0000000b,0x00000003,0x00050048,0x0000001b,0x00000003,0x0000000b,0x00000004,0x00020013,
0x00000002,0x00030021,0x00000003,0x00000002,0x00030016,0x00000006,0x00000020,0x00040017,
0x00000007,0x00000006,0x00000002,0x00040020,0x00000008,0x00000003,0x00000007,0x0004003b,
0x00000008,0x00000009,0x00000003,0x00040015,0x0000000a,0x00000020,0x00000001,0x00040020,
0x0000000b,0x00000001,0x0000000a,0x0004003b,0x0000000b,0x0000000c,0x00000001,0x0004002b,
0x0000000a,0x0000000e,0x00000001,0x0004002b,0x0000000a,0x00000010,0x00000002,0x00040017,
0x00000017,0x00000006,0x00000004,0x00040015,0x00000018,0x00000020,0x00000000,0x0004002b,
0x00000018,0x00000019,0x00000001,0x0004001c,0x0000001a,0x00000006,0x00000019,0x0006001e,
0x0000001b,0x00000017,0x00000006,0x0000001a,0x0000001a,0x00040020,0x0000001c,0x00000003,
0x0000001b,0x0004003b,0x0000001c,0x0000001d,0x00000003,0x0004002b,0x0000000a,0x0000001e,
0x00000000,0x0004002b,0x00000006,0x00000020,0x40000000,0x0004002b,0x00000006,0x00000022,
0x3f800000,0x0004002b,0x00000006,0x00000025,0x00000000,0x00040020,0x00000029,0x00000003,
0x00000017,0x0005002c,0x00000007,0x0000002b,0x00000022,0x00000022,0x00050036,0x00000002,
0x00000004,0x00000000,0x00000003,0x000200f8,0x00000005,0x0004003d,0x0000000a,0x0000000d,
0x0000000c,0x000500c4,0x0000000a,0x0000000f,0x0000000d,0x0000000e,0x000500c7,0x0000000a,
0x00000011,0x0000000f,0x00000010,0x0004006f,0x00000006,0x00000012,0x00000011,0x000500c7,
0x0000000a,0x00000014,0x0000000d,0x00000010,0x0004006f,0x00000006,0x00000015,0x00000014,
0x00050050,0x00000007,0x00000016,0x00000012,0x00000015,0x0003003e,0x00000009,0x00000016,
0x0004003d,0x00000007,0x0000001f,0x00000009,0x0005008e,0x00000007,0x00000021,0x0000001f,
0x00000020,0x00050083,0x00000007,0x00000024,0x00000021,0x0000002b,0x00050051,0x00000006,
0x00000026,0x00000024,0x00000000,0x00050051,0x00000006,0x00000027,0x00000024,0x00000001,
0x00070050,0x00000017,0x00000028,0x00000026,0x00000027,0x00000025,0x00000022,0x00050041,
0x00000029,0x0000002a,0x0000001d,0x0000001e,0x0003003e,0x0000002a,0x00000028,0x000100fd,
0x00010038};
static const uint32_t kTonemapFragSpv[] = {
0x07230203,0x00010000,0x000d000b,0x00000191,
0x00000000,0x00020011,0x00000001,0x0006000b,
0x00000001,0x4c534c47,0x6474732e,0x3035342e,
0x00000000,0x0003000e,0x00000000,0x00000001,
0x0007000f,0x00000004,0x00000004,0x6e69616d,
0x00000000,0x00000011,0x00000181,0x00030010,
0x00000004,0x00000007,0x00040047,0x0000000d,
0x00000021,0x00000000,0x00040047,0x0000000d,
0x00000022,0x00000000,0x00040047,0x00000011,
0x0000001e,0x00000000,0x00030047,0x0000001a,
0x00000002,0x00050048,0x0000001a,0x00000000,
0x00000023,0x00000000,0x00050048,0x0000001a,
0x00000001,0x00000023,0x00000004,0x00040047,
0x00000181,0x0000001e,0x00000000,0x00020013,
0x00000002,0x00030021,0x00000003,0x00000002,
0x00030016,0x00000006,0x00000020,0x00040017,
0x00000007,0x00000006,0x00000003,0x00090019,
0x0000000a,0x00000006,0x00000001,0x00000000,
0x00000000,0x00000000,0x00000001,0x00000000,
0x0003001b,0x0000000b,0x0000000a,0x00040020,
0x0000000c,0x00000000,0x0000000b,0x0004003b,
0x0000000c,0x0000000d,0x00000000,0x00040017,
0x0000000f,0x00000006,0x00000002,0x00040020,
0x00000010,0x00000001,0x0000000f,0x0004003b,
0x00000010,0x00000011,0x00000001,0x00040017,
0x00000013,0x00000006,0x00000004,0x0004002b,
0x00000006,0x00000016,0x00000000,0x0006002c,
0x00000007,0x00000017,0x00000016,0x00000016,
0x00000016,0x00040015,0x00000019,0x00000020,
0x00000001,0x0004001e,0x0000001a,0x00000006,
0x00000019,0x00040020,0x0000001b,0x00000009,
0x0000001a,0x0004003b,0x0000001b,0x0000001c,
0x00000009,0x0004002b,0x00000019,0x0000001d,
0x00000000,0x00040020,0x0000001e,0x00000009,
0x00000006,0x0004002b,0x00000019,0x00000022,
0x00000001,0x00040020,0x00000023,0x00000009,
0x00000019,0x00020014,0x00000026,0x0004002b,
0x00000006,0x0000002c,0x4020a3d7,0x0004002b,
0x00000006,0x0000002f,0x3cf5c28f,0x0004002b,
0x00000006,0x00000034,0x401b851f,0x0004002b,
0x00000006,0x00000037,0x3f170a3d,0x0004002b,
0x00000006,0x0000003b,0x3e0f5c29,0x0004002b,
0x00000006,0x0000003f,0x3f800000,0x0004002b,
0x00000019,0x00000046,0x00000002,0x0004002b,
0x00000019,0x00000051,0x00000003,0x00040017,
0x00000055,0x00000019,0x00000003,0x0004002b,
0x00000006,0x0000005c,0x437f0000,0x0004002b,
0x00000006,0x0000005e,0x3f000000,0x00040015,
0x00000062,0x00000020,0x00000000,0x0004002b,
0x00000062,0x00000063,0x00000100,0x0004001c,
0x00000064,0x00000006,0x00000063,0x0004002b,
0x00000006,0x00000065,0x3a802021,0x0004002b,
0x00000006,0x00000066,0x3b403006,0x0004002b,
0x00000006,0x00000067,0x3b80200b,0x0004002b,
0x00000006,0x00000068,0x3bc03006,0x0004002b,
0x00000006,0x00000069,0x3be0380f,0x0004002b,
0x00000006,0x0000006a,0x3c00200b,0x0004002b,
0x00000006,0x0000006b,0x3c202809,0x0004002b,
0x00000006,0x0000006c,0x3c302c0d,0x0004002b,
0x00000006,0x0000006d,0x3c50340a,0x0004002b,
0x00000006,0x0000006e,0x3c60380f,0x0004002b,
0x00000006,0x0000006f,0x3c703c13,0x0004002b,
0x00000006,0x00000070,0x3c882208,0x0004002b,
0x00000006,0x00000071,0x3c90240a,0x0004002b,
0x00000006,0x00000072,0x3ca02809,0x0004002b,
0x00000006,0x00000073,0x3cb02c0d,0x0004002b,
0x00000006,0x00000074,0x3cc0300c,0x0004002b,
0x00000006,0x00000075,0x3cd0340a,0x0004002b,
0x00000006,0x00000076,0x3ce0380f,0x0004002b,
0x00000006,0x00000077,0x3cf03c0d,0x0004002b,
0x00000006,0x00000078,0x3d002009,0x0004002b,
0x00000006,0x00000079,0x3d082208,0x0004002b,
0x00000006,0x0000007a,0x3d142508,0x0004002b,
0x00000006,0x0000007b,0x3d1c270b,0x0004002b,
0x00000006,0x0000007c,0x3d282a0b,0x0004002b,
0x00000006,0x0000007d,0x3d342d0b,0x0004002b,
0x00000006,0x0000007e,0x3d3c2f0b,0x0004002b,
0x00000006,0x0000007f,0x3d48320e,0x0004002b,
0x00000006,0x00000080,0x3d54350e,0x0004002b,
0x00000006,0x00000081,0x3d60380f,0x0004002b,
0x00000006,0x00000082,0x3d6c3b0f,0x0004002b,
0x00000006,0x00000083,0x3d7c3f10,0x0004002b,
0x00000006,0x00000084,0x3d842108,0x0004002b,
0x00000006,0x00000085,0x3d8c2309,0x0004002b,
0x00000006,0x00000086,0x3d922489,0x0004002b,
0x00000006,0x00000087,0x3d9a268a,0x0004002b,
0x00000006,0x00000088,0x3da2288b,0x0004002b,
0x00000006,0x00000089,0x3daa2a8a,0x0004002b,
0x00000006,0x0000008a,0x3db22c8b,0x0004002b,
0x00000006,0x0000008b,0x3dba2e8c,0x0004002b,
0x00000006,0x0000008c,0x3dc2308c,0x0004002b,
0x00000006,0x0000008d,0x3dca328d,0x0004002b,
0x00000006,0x0000008e,0x3dd2348e,0x0004002b,
0x00000006,0x0000008f,0x3dda368d,0x0004002b,
0x00000006,0x00000090,0x3de2388e,0x0004002b,
0x00000006,0x00000091,0x3dea3a8e,0x0004002b,
0x00000006,0x00000092,0x3df23c8f,0x0004002b,
0x00000006,0x00000093,0x3dfa3e90,0x0004002b,
0x00000006,0x00000094,0x3e012048,0x0004002b,
0x00000006,0x00000095,0x3e052149,0x0004002b,
0x00000006,0x00000096,0x3e092248,0x0004002b,
0x00000006,0x00000097,0x3e0d2349,0x0004002b,
0x00000006,0x00000098,0x3e112449,0x0004002b,
0x00000006,0x00000099,0x3e152549,0x0004002b,
0x00000006,0x0000009a,0x3e19264a,0x0004002b,
0x00000006,0x0000009b,0x3e1d274a,0x0004002b,
0x00000006,0x0000009c,0x3e21284a,0x0004002b,
0x00000006,0x0000009d,0x3e25294a,0x0004002b,
0x00000006,0x0000009e,0x3e292a4b,0x0004002b,
0x00000006,0x0000009f,0x3e2d2b4b,0x0004002b,
0x00000006,0x000000a0,0x3e312c4b,0x0004002b,
0x00000006,0x000000a1,0x3e352d4c,0x0004002b,
0x00000006,0x000000a2,0x3e392e4b,0x0004002b,
0x00000006,0x000000a3,0x3e3d2f4c,0x0004002b,
0x00000006,0x000000a4,0x3e41304c,0x0004002b,
0x00000006,0x000000a5,0x3e45314c,0x0004002b,
0x00000006,0x000000a6,0x3e49324d,0x0004002b,
0x00000006,0x000000a7,0x3e4e338d,0x0004002b,
0x00000006,0x000000a8,0x3e52348d,0x0004002b,
0x00000006,0x000000a9,0x3e56358d,0x0004002b,
0x00000006,0x000000aa,0x3e5a368e,0x0004002b,
0x00000006,0x000000ab,0x3e5e378e,0x0004002b,
0x00000006,0x000000ac,0x3e62388e,0x0004002b,
0x00000006,0x000000ad,0x3e66398e,0x0004002b,
0x00000006,0x000000ae,0x3e6a3a8e,0x0004002b,
0x00000006,0x000000af,0x3e6e3b8f,0x0004002b,
0x00000006,0x000000b0,0x3e723c8f,0x0004002b,
0x00000006,0x000000b1,0x3e773dd0,0x0004002b,
0x00000006,0x000000b2,0x3e7b3ecf,0x0004002b,
0x00000006,0x000000b3,0x3e7f3fd0,0x0004002b,
0x00000006,0x000000b4,0x3e81a068,0x0004002b,
0x00000006,0x000000b5,0x3e83a0e8,0x0004002b,
0x00000006,0x000000b6,0x3e85a168,0x0004002b,
0x00000006,0x000000b7,0x3e87a1e9,0x0004002b,
0x00000006,0x000000b8,0x3e8a2289,0x0004002b,
0x00000006,0x000000b9,0x3e8ca329,0x0004002b,
0x00000006,0x000000ba,0x3e8ea3a9,0x0004002b,
0x00000006,0x000000bb,0x3e90a429,0x0004002b,
0x00000006,0x000000bc,0x3e92a4a9,0x0004002b,
0x00000006,0x000000bd,0x3e94a529,0x0004002b,
0x00000006,0x000000be,0x3e9725ca,0x0004002b,
0x00000006,0x000000bf,0x3e992649,0x0004002b,
0x00000006,0x000000c0,0x3e9b26ca,0x0004002b,
0x00000006,0x000000c1,0x3e9d274a,0x0004002b,
0x00000006,0x000000c2,0x3e9f27ca,0x0004002b,
0x00000006,0x000000c3,0x3ea1284a,0x0004002b,
0x00000006,0x000000c4,0x3ea3a8ea,0x0004002b,
0x00000006,0x000000c5,0x3ea5a96a,0x0004002b,
0x00000006,0x000000c6,0x3ea7a9ea,0x0004002b,
0x00000006,0x000000c7,0x3ea9aa6b,0x0004002b,
0x00000006,0x000000c8,0x3eabaaeb,0x0004002b,
0x00000006,0x000000c9,0x3eae2b8b,0x0004002b,
0x00000006,0x000000ca,0x3eb02c0b,0x0004002b,
0x00000006,0x000000cb,0x3eb22c8b,0x0004002b,
0x00000006,0x000000cc,0x3eb42d0b,0x0004002b,
0x00000006,0x000000cd,0x3eb62d8b,0x0004002b,
0x00000006,0x000000ce,0x3eb8ae2b,0x0004002b,
0x00000006,0x000000cf,0x3ebaaeac,0x0004002b,
0x00000006,0x000000d0,0x3ebcaf2c,0x0004002b,
0x00000006,0x000000d1,0x3ebeafac,0x0004002b,
0x00000006,0x000000d2,0x3ec1304c,0x0004002b,
0x00000006,0x000000d3,0x3ec330cc,0x0004002b,
0x00000006,0x000000d4,0x3ec5314c,0x0004002b,
0x00000006,0x000000d5,0x3ec731cd,0x0004002b,
0x00000006,0x000000d6,0x3ec9b26c,0x0004002b,
0x00000006,0x000000d7,0x3ecbb2ed,0x0004002b,
0x00000006,0x000000d8,0x3ecdb36d,0x0004002b,
0x00000006,0x000000d9,0x3ecfb3ed,0x0004002b,
0x00000006,0x000000da,0x3ed2348d,0x0004002b,
0x00000006,0x000000db,0x3ed4350d,0x0004002b,
0x00000006,0x000000dc,0x3ed6358d,0x0004002b,
0x00000006,0x000000dd,0x3ed8360e,0x0004002b,
0x00000006,0x000000de,0x3edab6ae,0x0004002b,
0x00000006,0x000000df,0x3edcb72e,0x0004002b,
0x00000006,0x000000e0,0x3edeb7ae,0x0004002b,
0x00000006,0x000000e1,0x3ee0b82e,0x0004002b,
0x00000006,0x000000e2,0x3ee338ce,0x0004002b,
0x00000006,0x000000e3,0x3ee5394e,0x0004002b,
0x00000006,0x000000e4,0x3ee739ce,0x0004002b,
0x00000006,0x000000e5,0x3ee93a4f,0x0004002b,
0x00000006,0x000000e6,0x3eebbaef,0x0004002b,
0x00000006,0x000000e7,0x3eedbb6f,0x0004002b,
0x00000006,0x000000e8,0x3eefbbef,0x0004002b,
0x00000006,0x000000e9,0x3ef23c8f,0x0004002b,
0x00000006,0x000000ea,0x3ef43d0f,0x0004002b,
0x00000006,0x000000eb,0x3ef63d90,0x0004002b,
0x00000006,0x000000ec,0x3ef83e0f,0x0004002b,
0x00000006,0x000000ed,0x3efabeb0,0x0004002b,
0x00000006,0x000000ee,0x3efcbf30,0x0004002b,
0x00000006,0x000000ef,0x3efebfb0,0x0004002b,
0x00000006,0x000000f0,0x3f00a028,0x0004002b,
0x00000006,0x000000f1,0x3f01a068,0x0004002b,
0x00000006,0x000000f2,0x3f02a0a8,0x0004002b,
0x00000006,0x000000f3,0x3f03e0f8,0x0004002b,
0x00000006,0x000000f4,0x3f04e138,0x0004002b,
0x00000006,0x000000f5,0x3f05e178,0x0004002b,
0x00000006,0x000000f6,0x3f06e1b8,0x0004002b,
0x00000006,0x000000f7,0x3f082209,0x0004002b,
0x00000006,0x000000f8,0x3f092248,0x0004002b,
0x00000006,0x000000f9,0x3f0a2289,0x0004002b,
0x00000006,0x000000fa,0x3f0b62d9,0x0004002b,
0x00000006,0x000000fb,0x3f0c6319,0x0004002b,
0x00000006,0x000000fc,0x3f0d6359,0x0004002b,
0x00000006,0x000000fd,0x3f0ea3a9,0x0004002b,
0x00000006,0x000000fe,0x3f0fa3e9,0x0004002b,
0x00000006,0x000000ff,0x3f10a429,0x0004002b,
0x00000006,0x00000100,0x3f11e479,0x0004002b,
0x00000006,0x00000101,0x3f12e4b9,0x0004002b,
0x00000006,0x00000102,0x3f13e4f9,0x0004002b,
0x00000006,0x00000103,0x3f152549,0x0004002b,
0x00000006,0x00000104,0x3f162589,0x0004002b,
0x00000006,0x00000105,0x3f1725c9,0x0004002b,
0x00000006,0x00000106,0x3f18661a,0x0004002b,
0x00000006,0x00000107,0x3f19665a,0x0004002b,
0x00000006,0x00000108,0x3f1aa6aa,0x0004002b,
0x00000006,0x00000109,0x3f1ba6ea,0x0004002b,
0x00000006,0x0000010a,0x3f1ca72a,0x0004002b,
0x00000006,0x0000010b,0x3f1de77a,0x0004002b,
0x00000006,0x0000010c,0x3f1ee7ba,0x0004002b,
0x00000006,0x0000010d,0x3f1fe7fa,0x0004002b,
0x00000006,0x0000010e,0x3f21685a,0x0004002b,
0x00000006,0x0000010f,0x3f22689a,0x0004002b,
0x00000006,0x00000110,0x3f23a8ea,0x0004002b,
0x00000006,0x00000111,0x3f24a92a,0x0004002b,
0x00000006,0x00000112,0x3f25a96a,0x0004002b,
0x00000006,0x00000113,0x3f26e9ba,0x0004002b,
0x00000006,0x00000114,0x3f27e9fb,0x0004002b,
0x00000006,0x00000115,0x3f28ea3b,0x0004002b,
0x00000006,0x00000116,0x3f2a2a8b,0x0004002b,
0x00000006,0x00000117,0x3f2b2acb,0x0004002b,
0x00000006,0x00000118,0x3f2c6b1b,0x0004002b,
0x00000006,0x00000119,0x3f2d6b5b,0x0004002b,
0x00000006,0x0000011a,0x3f2e6b9b,0x0004002b,
0x00000006,0x0000011b,0x3f2fabeb,0x0004002b,
0x00000006,0x0000011c,0x3f30ac2b,0x0004002b,
0x00000006,0x0000011d,0x3f31ac6b,0x0004002b,
0x00000006,0x0000011e,0x3f32ecbb,0x0004002b,
0x00000006,0x0000011f,0x3f33ecfb,0x0004002b,
0x00000006,0x00000120,0x3f352d4b,0x0004002b,
0x00000006,0x00000121,0x3f362d8b,0x0004002b,
0x00000006,0x00000122,0x3f372dcb,0x0004002b,
0x00000006,0x00000123,0x3f386e1c,0x0004002b,
0x00000006,0x00000124,0x3f396e5c,0x0004002b,
0x00000006,0x00000125,0x3f3aaeac,0x0004002b,
0x00000006,0x00000126,0x3f3baeec,0x0004002b,
0x00000006,0x00000127,0x3f3caf2c,0x0004002b,
0x00000006,0x00000128,0x3f3def7c,0x0004002b,
0x00000006,0x00000129,0x3f3eefbc,0x0004002b,
0x00000006,0x0000012a,0x3f40300c,0x0004002b,
0x00000006,0x0000012b,0x3f41304c,0x0004002b,
0x00000006,0x0000012c,0x3f42709c,0x0004002b,
0x00000006,0x0000012d,0x3f4370dc,0x0004002b,
0x00000006,0x0000012e,0x3f44711c,0x0004002b,
0x00000006,0x0000012f,0x3f45b16c,0x0004002b,
0x00000006,0x00000130,0x3f46b1ac,0x0004002b,
0x00000006,0x00000131,0x3f47f1fd,0x0004002b,
0x00000006,0x00000132,0x3f48f23d,0x0004002b,
0x00000006,0x00000133,0x3f4a328d,0x0004002b,
0x00000006,0x00000134,0x3f4b32cd,0x0004002b,
0x00000006,0x00000135,0x3f4c330d,0x0004002b,
0x00000006,0x00000136,0x3f4d735d,0x0004002b,
0x00000006,0x00000137,0x3f4e739d,0x0004002b,
0x00000006,0x00000138,0x3f4fb3ed,0x0004002b,
0x00000006,0x00000139,0x3f50b42d,0x0004002b,
0x00000006,0x0000013a,0x3f51f47d,0x0004002b,
0x00000006,0x0000013b,0x3f52f4bd,0x0004002b,
0x00000006,0x0000013c,0x3f53f4fd,0x0004002b,
0x00000006,0x0000013d,0x3f55354d,0x0004002b,
0x00000006,0x0000013e,0x3f56358d,0x0004002b,
0x00000006,0x0000013f,0x3f5775dd,0x0004002b,
0x00000006,0x00000140,0x3f58761e,0x0004002b,
0x00000006,0x00000141,0x3f59b66e,0x0004002b,
0x00000006,0x00000142,0x3f5ab6ae,0x0004002b,
0x00000006,0x00000143,0x3f5bf6fe,0x0004002b,
0x00000006,0x00000144,0x3f5cf73e,0x0004002b,
0x00000006,0x00000145,0x3f5e378e,0x0004002b,
0x00000006,0x00000146,0x3f5f37ce,0x0004002b,
0x00000006,0x00000147,0x3f60380e,0x0004002b,
0x00000006,0x00000148,0x3f61785e,0x0004002b,
0x00000006,0x00000149,0x3f62789e,0x0004002b,
0x00000006,0x0000014a,0x3f63b8ee,0x0004002b,
0x00000006,0x0000014b,0x3f64b92e,0x0004002b,
0x00000006,0x0000014c,0x3f65f97e,0x0004002b,
0x00000006,0x0000014d,0x3f66f9be,0x0004002b,
0x00000006,0x0000014e,0x3f683a0e,0x0004002b,
0x00000006,0x0000014f,0x3f693a4f,0x0004002b,
0x00000006,0x00000150,0x3f6a7a9f,0x0004002b,
0x00000006,0x00000151,0x3f6b7adf,0x0004002b,
0x00000006,0x00000152,0x3f6cbb2f,0x0004002b,
0x00000006,0x00000153,0x3f6dbb6f,0x0004002b,
0x00000006,0x00000154,0x3f6efbbf,0x0004002b,
0x00000006,0x00000155,0x3f6ffbff,0x0004002b,
0x00000006,0x00000156,0x3f70fc3f,0x0004002b,
0x00000006,0x00000157,0x3f723c8f,0x0004002b,
0x00000006,0x00000158,0x3f733ccf,0x0004002b,
0x00000006,0x00000159,0x3f747d1f,0x0004002b,
0x00000006,0x0000015a,0x3f757d5f,0x0004002b,
0x00000006,0x0000015b,0x3f76bdaf,0x0004002b,
0x00000006,0x0000015c,0x3f77bdf0,0x0004002b,
0x00000006,0x0000015d,0x3f78fe40,0x0004002b,
0x00000006,0x0000015e,0x3f79fe80,0x0004002b,
0x00000006,0x0000015f,0x3f7b3ed0,0x0004002b,
0x00000006,0x00000160,0x3f7c3f10,0x0004002b,
0x00000006,0x00000161,0x3f7d7f60,0x0004002b,
0x00000006,0x00000162,0x3f7e7fa0,0x0103002c,
0x00000064,0x00000163,0x00000016,0x00000065,
0x00000066,0x00000067,0x00000068,0x00000069,
0x0000006a,0x0000006b,0x0000006c,0x0000006d,
0x0000006e,0x0000006f,0x00000070,0x00000071,
0x00000072,0x00000073,0x00000074,0x00000075,
0x00000076,0x00000077,0x00000078,0x00000079,
0x0000007a,0x0000007b,0x0000007c,0x0000007d,
0x0000007e,0x0000007f,0x00000080,0x00000081,
0x00000082,0x00000083,0x00000084,0x00000085,
0x00000086,0x00000087,0x00000088,0x00000089,
0x0000008a,0x0000008b,0x0000008c,0x0000008d,
0x0000008e,0x0000008f,0x00000090,0x00000091,
0x00000092,0x00000093,0x00000094,0x00000095,
0x00000096,0x00000097,0x00000098,0x00000099,
0x0000009a,0x0000009b,0x0000009c,0x0000009d,
0x0000009e,0x0000009f,0x000000a0,0x000000a1,
0x000000a2,0x000000a3,0x000000a4,0x000000a5,
0x000000a6,0x000000a7,0x000000a8,0x000000a9,
0x000000aa,0x000000ab,0x000000ac,0x000000ad,
0x000000ae,0x000000af,0x000000b0,0x000000b1,
0x000000b2,0x000000b3,0x000000b4,0x000000b5,
0x000000b6,0x000000b7,0x000000b8,0x000000b9,
0x000000ba,0x000000bb,0x000000bc,0x000000bd,
0x000000be,0x000000bf,0x000000c0,0x000000c1,
0x000000c2,0x000000c3,0x000000c4,0x000000c5,
0x000000c6,0x000000c7,0x000000c8,0x000000c9,
0x000000ca,0x000000cb,0x000000cc,0x000000cd,
0x000000ce,0x000000cf,0x000000d0,0x000000d1,
0x000000d2,0x000000d3,0x000000d4,0x000000d5,
0x000000d6,0x000000d7,0x000000d8,0x000000d9,
0x000000da,0x000000db,0x000000dc,0x000000dd,
0x000000de,0x000000df,0x000000e0,0x000000e1,
0x000000e2,0x000000e3,0x000000e4,0x000000e5,
0x000000e6,0x000000e7,0x000000e8,0x000000e9,
0x000000ea,0x000000eb,0x000000ec,0x000000ed,
0x000000ee,0x000000ef,0x000000f0,0x000000f1,
0x000000f2,0x000000f3,0x000000f4,0x000000f5,
0x000000f6,0x000000f7,0x000000f8,0x000000f9,
0x000000fa,0x000000fb,0x000000fc,0x000000fd,
0x000000fe,0x000000ff,0x00000100,0x00000101,
0x00000102,0x00000103,0x00000104,0x00000105,
0x00000106,0x00000107,0x00000108,0x00000109,
0x0000010a,0x0000010b,0x0000010c,0x0000010d,
0x0000010e,0x0000010f,0x00000110,0x00000111,
0x00000112,0x00000113,0x00000114,0x00000115,
0x00000116,0x00000117,0x00000118,0x00000119,
0x0000011a,0x0000011b,0x0000011c,0x0000011d,
0x0000011e,0x0000011f,0x00000120,0x00000121,
0x00000122,0x00000123,0x00000124,0x00000125,
0x00000126,0x00000127,0x00000128,0x00000129,
0x0000012a,0x0000012b,0x0000012c,0x0000012d,
0x0000012e,0x0000012f,0x00000130,0x00000131,
0x00000132,0x00000133,0x00000134,0x00000135,
0x00000136,0x00000137,0x00000138,0x00000139,
0x0000013a,0x0000013b,0x0000013c,0x0000013d,
0x0000013e,0x0000013f,0x00000140,0x00000141,
0x00000142,0x00000143,0x00000144,0x00000145,
0x00000146,0x00000147,0x00000148,0x00000149,
0x0000014a,0x0000014b,0x0000014c,0x0000014d,
0x0000014e,0x0000014f,0x00000150,0x00000151,
0x00000152,0x00000153,0x00000154,0x00000155,
0x00000156,0x00000157,0x00000158,0x00000159,
0x0000015a,0x0000015b,0x0000015c,0x0000015d,
0x0000015e,0x0000015f,0x00000160,0x00000161,
0x00000162,0x0000003f,0x00040020,0x00000168,
0x00000007,0x00000064,0x00040020,0x0000016a,
0x00000007,0x00000006,0x0006002c,0x00000007,
0x0000017d,0x0000003f,0x0000003f,0x0000003f,
0x00040020,0x00000180,0x00000003,0x00000013,
0x0004003b,0x00000180,0x00000181,0x00000003,
0x0006002c,0x00000007,0x0000018d,0x0000002f,
0x0000002f,0x0000002f,0x0006002c,0x00000007,
0x0000018e,0x00000037,0x00000037,0x00000037,
0x0006002c,0x00000007,0x0000018f,0x0000003b,
0x0000003b,0x0000003b,0x0006002c,0x00000007,
0x00000190,0x0000005e,0x0000005e,0x0000005e,
0x00050036,0x00000002,0x00000004,0x00000000,
0x00000003,0x000200f8,0x00000005,0x0004003b,
0x00000168,0x00000169,0x00000007,0x0004003b,
0x00000168,0x00000170,0x00000007,0x0004003b,
0x00000168,0x00000176,0x00000007,0x0004003d,
0x0000000b,0x0000000e,0x0000000d,0x0004003d,
0x0000000f,0x00000012,0x00000011,0x00050057,
0x00000013,0x00000014,0x0000000e,0x00000012,
0x0008004f,0x00000007,0x00000015,0x00000014,
0x00000014,0x00000000,0x00000001,0x00000002,
0x0007000c,0x00000007,0x00000018,0x00000001,
0x00000028,0x00000015,0x00000017,0x00050041,
0x0000001e,0x0000001f,0x0000001c,0x0000001d,
0x0004003d,0x00000006,0x00000020,0x0000001f,
0x0005008e,0x00000007,0x00000021,0x00000018,
0x00000020,0x00050041,0x00000023,0x00000024,
0x0000001c,0x00000022,0x0004003d,0x00000019,
0x00000025,0x00000024,0x000500aa,0x00000026,
0x00000027,0x00000025,0x00000022,0x000300f7,
0x00000029,0x00000000,0x000400fa,0x00000027,
0x00000028,0x00000043,0x000200f8,0x00000028,
0x0005008e,0x00000007,0x0000002e,0x00000021,
0x0000002c,0x00050081,0x00000007,0x00000031,
0x0000002e,0x0000018d,0x00050085,0x00000007,
0x00000032,0x00000021,0x00000031,0x0005008e,
0x00000007,0x00000036,0x00000021,0x00000034,
0x00050081,0x00000007,0x00000039,0x00000036,
0x0000018e,0x00050085,0x00000007,0x0000003a,
0x00000021,0x00000039,0x00050081,0x00000007,
0x0000003d,0x0000003a,0x0000018f,0x00050088,
0x00000007,0x0000003e,0x00000032,0x0000003d,
0x0008000c,0x00000007,0x00000042,0x00000001,
0x0000002b,0x0000003e,0x00000017,0x0000017d,
0x000200f9,0x00000029,0x000200f8,0x00000043,
0x000500aa,0x00000026,0x00000047,0x00000025,
0x00000046,0x000300f7,0x00000049,0x00000000,
0x000400fa,0x00000047,0x00000048,0x0000004e,
0x000200f8,0x00000048,0x0008000c,0x00000007,
0x0000004d,0x00000001,0x0000002b,0x00000021,
0x00000017,0x0000017d,0x000200f9,0x00000049,
0x000200f8,0x0000004e,0x000500aa,0x00000026,
0x00000052,0x00000025,0x00000051,0x000300f7,
0x00000054,0x00000000,0x000400fa,0x00000052,
0x00000053,0x0000017a,0x000200f8,0x00000053,
0x0008000c,0x00000007,0x0000005b,0x00000001,
0x0000002b,0x00000021,0x00000017,0x0000017d,
0x0005008e,0x00000007,0x0000005d,0x0000005b,
0x0000005c,0x00050081,0x00000007,0x00000060,
0x0000005d,0x00000190,0x0004006e,0x00000055,
0x00000061,0x00000060,0x00050051,0x00000019,
0x00000167,0x00000061,0x00000000,0x0003003e,
0x00000169,0x00000163,0x00050041,0x0000016a,
0x0000016b,0x00000169,0x00000167,0x0004003d,
0x00000006,0x0000016c,0x0000016b,0x00050051,
0x00000019,0x0000016f,0x00000061,0x00000001,
0x0003003e,0x00000170,0x00000163,0x00050041,
0x0000016a,0x00000171,0x00000170,0x0000016f,
0x0004003d,0x00000006,0x00000172,0x00000171,
0x00050051,0x00000019,0x00000175,0x00000061,
0x00000002,0x0003003e,0x00000176,0x00000163,
0x00050041,0x0000016a,0x00000177,0x00000176,
0x00000175,0x0004003d,0x00000006,0x00000178,
0x00000177,0x00060050,0x00000007,0x00000179,
0x0000016c,0x00000172,0x00000178,0x000200f9,
0x00000054,0x000200f8,0x0000017a,0x00050081,
0x00000007,0x0000017e,0x00000021,0x0000017d,
0x00050088,0x00000007,0x0000017f,0x00000021,
0x0000017e,0x000200f9,0x00000054,0x000200f8,
0x00000054,0x000700f5,0x00000007,0x0000018c,
0x00000179,0x00000053,0x0000017f,0x0000017a,
0x000200f9,0x00000049,0x000200f8,0x00000049,
0x000700f5,0x00000007,0x0000018b,0x0000004d,
0x00000048,0x0000018c,0x00000054,0x000200f9,
0x00000029,0x000200f8,0x00000029,0x000700f5,
0x00000007,0x0000018a,0x00000042,0x00000028,
0x0000018b,0x00000049,0x00050051,0x00000006,
0x00000183,0x0000018a,0x00000000,0x00050051,
0x00000006,0x00000184,0x0000018a,0x00000001,
0x00050051,0x00000006,0x00000185,0x0000018a,
0x00000002,0x00070050,0x00000013,0x00000186,
0x00000183,0x00000184,0x00000185,0x0000003f,
0x0003003e,0x00000181,0x00000186,0x000100fd,
0x00010038};
// Build the LDR intermediate + tonemap pipeline (called from initVk under RVK_HDR only).
bool initTonemap() {
  VkImageCreateInfo ii{VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO}; ii.imageType = VK_IMAGE_TYPE_2D; ii.format = VK_FORMAT_R8G8B8A8_UNORM;
  ii.extent = {kW, kH, 1}; ii.mipLevels = 1; ii.arrayLayers = 1; ii.samples = VK_SAMPLE_COUNT_1_BIT; ii.tiling = VK_IMAGE_TILING_OPTIMAL;
  ii.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT; ii.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
  VKC(vkCreateImage(g.dev, &ii, nullptr, &g.imageLdr), "tm image");
  VkMemoryRequirements mr{}; vkGetImageMemoryRequirements(g.dev, g.imageLdr, &mr);
  VkMemoryAllocateInfo ai{VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO}; ai.allocationSize = mr.size; ai.memoryTypeIndex = findMem(mr.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
  VKC(vkAllocateMemory(g.dev, &ai, nullptr, &g.imageLdrMem), "tm mem"); VKC(vkBindImageMemory(g.dev, g.imageLdr, g.imageLdrMem, 0), "tm bind");
  VkImageViewCreateInfo iv{VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO}; iv.image = g.imageLdr; iv.viewType = VK_IMAGE_VIEW_TYPE_2D; iv.format = VK_FORMAT_R8G8B8A8_UNORM; iv.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  VKC(vkCreateImageView(g.dev, &iv, nullptr, &g.imageLdrView), "tm view");
  VkAttachmentDescription att{}; att.format = VK_FORMAT_R8G8B8A8_UNORM; att.samples = VK_SAMPLE_COUNT_1_BIT;
  att.loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE; att.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
  att.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE; att.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
  att.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED; att.finalLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
  VkAttachmentReference ref{0, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL};
  VkSubpassDescription sub{}; sub.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS; sub.colorAttachmentCount = 1; sub.pColorAttachments = &ref;
  // dependency so the subsequent present-BLIT (transfer-read of g.imageLdr) waits on the tonemap write.
  VkSubpassDependency dep{}; dep.srcSubpass = 0; dep.dstSubpass = VK_SUBPASS_EXTERNAL;
  dep.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT; dep.dstStageMask = VK_PIPELINE_STAGE_TRANSFER_BIT;
  dep.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT; dep.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
  VkRenderPassCreateInfo rp{VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO}; rp.attachmentCount = 1; rp.pAttachments = &att; rp.subpassCount = 1; rp.pSubpasses = &sub; rp.dependencyCount = 1; rp.pDependencies = &dep;
  VKC(vkCreateRenderPass(g.dev, &rp, nullptr, &g.passLdr), "tm pass");
  VkFramebufferCreateInfo fbi{VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO}; fbi.renderPass = g.passLdr; fbi.attachmentCount = 1; fbi.pAttachments = &g.imageLdrView; fbi.width = kW; fbi.height = kH; fbi.layers = 1;
  VKC(vkCreateFramebuffer(g.dev, &fbi, nullptr, &g.fbLdr), "tm fb");
  VkDescriptorSetLayoutBinding b0{}; b0.binding = 0; b0.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER; b0.descriptorCount = 1; b0.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
  VkDescriptorSetLayoutCreateInfo dl{VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO}; dl.bindingCount = 1; dl.pBindings = &b0;
  VKC(vkCreateDescriptorSetLayout(g.dev, &dl, nullptr, &g.tmDsl), "tm dsl");
  VkDescriptorPoolSize psz{VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1};
  VkDescriptorPoolCreateInfo dp{VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO}; dp.maxSets = 1; dp.poolSizeCount = 1; dp.pPoolSizes = &psz;
  VKC(vkCreateDescriptorPool(g.dev, &dp, nullptr, &g.tmPool), "tm pool");
  VkDescriptorSetAllocateInfo da{VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO}; da.descriptorPool = g.tmPool; da.descriptorSetCount = 1; da.pSetLayouts = &g.tmDsl;
  VKC(vkAllocateDescriptorSets(g.dev, &da, &g.tmSet), "tm set");
  VkDescriptorImageInfo dii{g.sampler, g.imageView, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL};
  VkWriteDescriptorSet wr{VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET}; wr.dstSet = g.tmSet; wr.dstBinding = 0; wr.descriptorCount = 1; wr.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER; wr.pImageInfo = &dii;
  vkUpdateDescriptorSets(g.dev, 1, &wr, 0, nullptr);
  VkPushConstantRange pcr{VK_SHADER_STAGE_FRAGMENT_BIT, 0, 8};
  VkPipelineLayoutCreateInfo pl{VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO}; pl.setLayoutCount = 1; pl.pSetLayouts = &g.tmDsl; pl.pushConstantRangeCount = 1; pl.pPushConstantRanges = &pcr;
  VKC(vkCreatePipelineLayout(g.dev, &pl, nullptr, &g.tmLayout), "tm layout");
  VkShaderModule vs = makeShader(kTonemapVertSpv, sizeof kTonemapVertSpv);
  VkShaderModule fs = makeShader(kTonemapFragSpv, sizeof kTonemapFragSpv);
  VkPipelineShaderStageCreateInfo stg[2] = {
    {VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO, nullptr, 0, VK_SHADER_STAGE_VERTEX_BIT, vs, "main", nullptr},
    {VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO, nullptr, 0, VK_SHADER_STAGE_FRAGMENT_BIT, fs, "main", nullptr}};
  VkPipelineVertexInputStateCreateInfo vin{VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO};
  VkPipelineInputAssemblyStateCreateInfo ia{VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO}; ia.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
  VkViewport vp{0, 0, (float)kW, (float)kH, 0, 1}; VkRect2D sc{{0, 0}, {kW, kH}};
  VkPipelineViewportStateCreateInfo vps{VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO}; vps.viewportCount = 1; vps.pViewports = &vp; vps.scissorCount = 1; vps.pScissors = &sc;
  VkPipelineRasterizationStateCreateInfo rs{VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO}; rs.polygonMode = VK_POLYGON_MODE_FILL; rs.cullMode = VK_CULL_MODE_NONE; rs.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE; rs.lineWidth = 1.f;
  VkPipelineMultisampleStateCreateInfo msa{VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO}; msa.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
  VkPipelineColorBlendAttachmentState cba{}; cba.blendEnable = VK_FALSE; cba.colorWriteMask = 0xF;
  VkPipelineColorBlendStateCreateInfo cb{VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO}; cb.attachmentCount = 1; cb.pAttachments = &cba;
  VkGraphicsPipelineCreateInfo gp{VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO}; gp.stageCount = 2; gp.pStages = stg; gp.pVertexInputState = &vin; gp.pInputAssemblyState = &ia; gp.pViewportState = &vps; gp.pRasterizationState = &rs; gp.pMultisampleState = &msa; gp.pColorBlendState = &cb; gp.layout = g.tmLayout; gp.renderPass = g.passLdr; gp.subpass = 0;
  VKC(vkCreateGraphicsPipelines(g.dev, VK_NULL_HANDLE, 1, &gp, nullptr, &g.tmPipe), "tm pipe");
  vkDestroyShaderModule(g.dev, vs, nullptr); vkDestroyShaderModule(g.dev, fs, nullptr);
  std::fprintf(stderr, "[rvk][hdr] tonemap pass ready (g.imageLdr + fullscreen tonemap pipeline)\n");
  return true;
}

// ============================================================================
// REAL shader-matching / PM4-tracked GPU register shadow state (persists across
// renderFrame calls like real GPU register state would — the frame's PM4 *window*
// is just a slice of the ring; IM_LOAD / ALU consts may not be reissued every frame).
// ============================================================================
float g_vsConstF[1024] = {0};   // VS c0..c255 (256 float4)
float g_c255v[4] = {2.f/320.f, 1.f/256.f, -1.f, 0.f};  // idx48 screen transform (RVK_C255)
int   g_c255fix = 0;                                    // set once when RVK_C255 parsed
float g_psConstF[896]  = {0};   // PS c0..c223 (224 float4)
bool  g_vsDirty = false, g_psDirty = false;
int   g_curVsIdx = -1, g_curPsIdx = -1;         // index into g_futari_shaders, -1 = unmatched
uint32_t g_boolConst0 = 0;                      // PM4 boolean constants bank 0 (reg 0x4900) -> PS g_Booleans
int   g_lastLoggedVsIdx = -999, g_lastLoggedPsIdx = -999;
float g_xscale = 640.f, g_xoffset = 640.f, g_yscale = -360.f, g_yoffset = 360.f, g_zscale = 1.f, g_zoffset = 0.f;
uint32_t g_vteCntl = 0x43F;
uint32_t g_regFile[0x6100] = {0}; // persistent full register shadow (fetch consts, RB state)

// RVK_HDR (2026-07-14, overexposure fix via rexglue-sdk): the X360 renders the additive bloom pool
// into 7e3-FLOAT EDRAM targets (RB_COLOR_INFO color_format=3, range [0,32)), then its own shaders
// tonemap on resolve. Our render targets are all R8G8B8A8_UNORM -> the additive accumulation CLIPS
// [0,32)->[0,1] = the white field wash (confirmed via RVK_RTFMT + SDK render_target_cache.cpp). Fix:
// render the whole field pipeline in R16G16B16A16_SFLOAT so accumulation doesn't clip; the guest's
// own tonemap then produces the correct LDR image, and the final present-blit clamps to the UNORM8
// swapchain. g_rtFmt is the color-target format for the offscreen + render pass + resolve texs; it's
// chosen once in initVk. Default (RVK_HDR unset) = R8G8B8A8_UNORM = byte-identical to before.
VkFormat g_rtFmt = VK_FORMAT_R8G8B8A8_UNORM;
// RVK_REGPROBE breadcrumb: which PM4 decode path is currently writing registers.
static const char* g_pm4Src = nullptr;
static inline bool rvk_hdr() { return g_rtFmt != VK_FORMAT_R8G8B8A8_UNORM; }

// ============================================================================================
// ★ s2B LEG 10 ITEM 1 — REGISTER-TRUE PER-TARGET COLOUR FORMATS (nvk path only)
// --------------------------------------------------------------------------------------------
// [nvkfmt] (leg 9) pinned the class-B residual: the 320x240 RESOLVE RING (surf 0x269FB50) carries
// guest RB_COLOR_INFO=0x00030710 -> color_format nibble [19:16] = 3, and every consumer fetches it
// with texture format 54. nvk created BOTH sides as R8G8B8A8_UNORM (vkfmt 37).
//
// WHAT cfmt 3 ACTUALLY IS (the task brief said "2_10_10_10"; the tree's own decode table says
// otherwise and the tree is right — vk_render.cpp:4491 RVK_RTFMT names it, and the register-true
// present ruling at :3516-3523 was DERIVED from it):
//     ColorRenderTargetFormat 0=8_8_8_8  1=8_8_8_8_GAMMA  2=2_10_10_10
//                             3=2_10_10_10_FLOAT  <-- 7e3: 3-bit exp + 7-bit mantissa, range [0,32)
//                             4=16_16  5=16_16_16_16  6=16_16_FLOAT  7=16_16_16_16_FLOAT
// and :3518-3519 states it as banked truth: "the 7e3 HDR range exists ONLY inside the 320x240 tile
// passes (RB_COLOR_INFO fmt=3) and saturates to [0,1] at their k_2_10_10_10 resolve".
// So the register-true host pair is NOT "both A2B10G10R10":
//   * RING RT      = a FLOAT target with headroom above 1.0  -> VK_FORMAT_R16G16B16A16_SFLOAT.
//     f16 (5e10) strictly contains 7e3 (3e7) over [0,32), so no guest value is lost. Using an
//     8-bit UNORM target instead CLAMPS EVERY BLEND STEP at 1.0; because the clamp is per-channel
//     and the ring pass blends repeatedly, channels that would have gone >1 and come back down
//     are truncated at different points -> a hue shift on saturated pixels. That is exactly the
//     "residual chroma fringing" signature, and it is the mechanism this change removes.
//   * RESOLVE TEX  = fetch fmt 54 = k_2_10_10_10_AS_16_16_16_16. The "_AS_16_16_16_16" suffix is
//     an EDRAM-export-width tag, not a channel layout: the texel is k_2_10_10_10 UNORM. Vulkan's
//     A2B10G10R10_UNORM_PACK32 is bit-identical to D3D's R10G10B10A2_UNORM (R in bits 0-9, A in
//     30-31), i.e. the exact Xenos layout. -> VK_FORMAT_A2B10G10R10_UNORM_PACK32.
// COMPONENT-ORDER RISK IS NIL: the resolve is a vkCmdBlitImage between two host images, which is a
// by-NAME component conversion (src.R -> dst.R ...), and the sampler reads by name too. Byte layout
// and the fetch's endian=2 never enter the host path — we never reinterpret the ring's bytes. What
// the format choice DOES control is precision + clamping, which is the whole point: the F16->A2B10
// blit performs the guest resolve's own saturate-to-[0,1] + 10-bit quantize in one step.
// exp_bias is 0 on every resolve class in this game (measured, :3517), so no 2^bias scale is owed.
//
// Framebuffer/pipeline plumbing: a VkFramebuffer's attachment format must match its render pass,
// and a pipeline is only usable in a render pass COMPATIBLE with the one it was built against
// (identical attachment formats). So a non-g_rtFmt target needs its own {CLEAR, LOAD} pass pair and
// its own pipeline cache entries. loadOp/layouts are excluded from compatibility, so ONE pass per
// format is enough to build pipelines for both members of the pair (same rule g.pass/g.passLoad
// already relies on).
// LEVER: RT_NVKRING8=1 -> every nvk target falls back to g_rtFmt (byte-identical to leg 9).
// ============================================================================================
static inline bool nvkRing8On() {   // revert lever
  static bool on = std::getenv("RT_NVKRING8") != nullptr;
  return on;
}
// Does the physical device support `f` for the uses we need it for? A miss must never be fatal:
// we log once and fall back to g_rtFmt (= leg-9 behaviour for that target).
static bool nvkFmtUsable(VkFormat f, VkFormatFeatureFlags need) {
  if (f == VK_FORMAT_UNDEFINED) return false;
  static std::unordered_map<uint64_t, int> cache;
  uint64_t k = ((uint64_t)(uint32_t)f << 32) | (uint64_t)need;
  auto it = cache.find(k);
  if (it != cache.end()) return it->second != 0;
  VkFormatProperties fp{};
  vkGetPhysicalDeviceFormatProperties(g.phys, f, &fp);
  bool ok = (fp.optimalTilingFeatures & need) == need;
  cache[k] = ok ? 1 : 0;
  if (!ok) std::fprintf(stderr, "[nvkfmt] device lacks features 0x%X for VkFormat %d — falling back to %d\n",
                        (unsigned)need, (int)f, (int)g_rtFmt);
  return ok;
}
// Colour-attachment target format for a guest RB_COLOR_INFO word (see the table above).
static const VkFormatFeatureFlags kNvkRtFeat =
    VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT | VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT |
    VK_FORMAT_FEATURE_BLIT_SRC_BIT | VK_FORMAT_FEATURE_TRANSFER_SRC_BIT | VK_FORMAT_FEATURE_TRANSFER_DST_BIT;
static const VkFormatFeatureFlags kNvkTexFeat =
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT | VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT |
    VK_FORMAT_FEATURE_BLIT_DST_BIT | VK_FORMAT_FEATURE_TRANSFER_SRC_BIT | VK_FORMAT_FEATURE_TRANSFER_DST_BIT;
static VkFormat nvkRtFormatFor(uint32_t colorInfo) {
  if (nvkRing8On() || rvk_hdr()) return g_rtFmt;   // lever, or HDR already gives every target f16
  VkFormat want = VK_FORMAT_UNDEFINED;
  switch ((colorInfo >> 16) & 0xFu) {
    case 3: want = VK_FORMAT_R16G16B16A16_SFLOAT;        break;  // 2_10_10_10_FLOAT (7e3) — THE RING
    case 6: case 7: want = VK_FORMAT_R16G16B16A16_SFLOAT; break; // 16_16_FLOAT / 16_16_16_16_FLOAT
    case 2: want = VK_FORMAT_A2B10G10R10_UNORM_PACK32;   break;  // plain 2_10_10_10 UNORM
    default: return g_rtFmt;                                     // 0/1 = 8888(_GAMMA), 4/5 = 16-bit UNORM
  }
  return nvkFmtUsable(want, kNvkRtFeat) ? want : g_rtFmt;
}
// Resolve-destination texture format for a guest texture-fetch format nibble (fetch dw1 bits 0-5).
static VkFormat nvkResolveTexFormatFor(uint32_t fetchFmt) {
  if (nvkRing8On() || rvk_hdr()) return g_rtFmt;
  //  7 = k_2_10_10_10, 54 = k_2_10_10_10_AS_16_16_16_16 (same texel, EDRAM-export tag only)
  if (fetchFmt != 7u && fetchFmt != 54u) return g_rtFmt;
  VkFormat want = VK_FORMAT_A2B10G10R10_UNORM_PACK32;
  return nvkFmtUsable(want, kNvkTexFeat) ? want : g_rtFmt;
}
// {CLEAR, LOAD} render-pass pair per colour format. g_rtFmt reuses g.pass/g.passLoad verbatim so
// the default path is untouched. Callable only after initVk (g.pass is the compatibility anchor).
struct NvkPassPair { VkRenderPass clear = VK_NULL_HANDLE, load = VK_NULL_HANDLE; };
static NvkPassPair nvkPassesFor(VkFormat f) {
  if (f == VK_FORMAT_UNDEFINED || f == g_rtFmt) return {g.pass, g.passLoad};
  static std::unordered_map<uint32_t, NvkPassPair> cache;
  auto it = cache.find((uint32_t)f);
  if (it != cache.end()) return it->second;
  NvkPassPair pp{};
  VkAttachmentDescription att{}; att.format = f; att.samples = VK_SAMPLE_COUNT_1_BIT;
  att.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR; att.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
  att.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE; att.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
  att.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED; att.finalLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
  VkAttachmentReference ref{0, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL};
  VkSubpassDescription sub{}; sub.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
  sub.colorAttachmentCount = 1; sub.pColorAttachments = &ref;
  VkSubpassDependency dep{}; dep.srcSubpass = VK_SUBPASS_EXTERNAL; dep.dstSubpass = 0;
  dep.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT; dep.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
  dep.srcAccessMask = 0; dep.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
  VkRenderPassCreateInfo rp{VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO};
  rp.attachmentCount = 1; rp.pAttachments = &att; rp.subpassCount = 1; rp.pSubpasses = &sub;
  rp.dependencyCount = 1; rp.pDependencies = &dep;
  if (vkCreateRenderPass(g.dev, &rp, nullptr, &pp.clear) != VK_SUCCESS) {
    std::fprintf(stderr, "[nvkfmt] vkCreateRenderPass(clear, fmt %d) FAILED — target falls back to g_rtFmt\n", (int)f);
    return (cache[(uint32_t)f] = NvkPassPair{});
  }
  VkAttachmentDescription attL = att;
  attL.loadOp = VK_ATTACHMENT_LOAD_OP_LOAD; attL.initialLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
  VkRenderPassCreateInfo rpL = rp; rpL.pAttachments = &attL;
  if (vkCreateRenderPass(g.dev, &rpL, nullptr, &pp.load) != VK_SUCCESS) {
    std::fprintf(stderr, "[nvkfmt] vkCreateRenderPass(load, fmt %d) FAILED — target falls back to g_rtFmt\n", (int)f);
    vkDestroyRenderPass(g.dev, pp.clear, nullptr);
    return (cache[(uint32_t)f] = NvkPassPair{});
  }
  std::fprintf(stderr, "[nvkfmt] render-pass pair created for VkFormat %d\n", (int)f);
  return (cache[(uint32_t)f] = pp);
}
// Small stable tag so a colour format can be folded into the pipeline cache key (a raw VkFormat is
// 32 bits and the key has no room). Anything unlisted collapses to 0 = "same as g_rtFmt".
static inline uint32_t nvkFmtTag(VkFormat f) {
  switch (f) {
    case VK_FORMAT_R16G16B16A16_SFLOAT:        return 1;
    case VK_FORMAT_A2B10G10R10_UNORM_PACK32:   return 2;
    default:                                   return 0;
  }
}

// Load a shader's DEFINITION-TABLE float4 constants (c255 etc.) — shader-EMBEDDED constants the
// guest never sets via PM4, so a faithful PM4 decoder can't recover them. Extracted OFFLINE from
// the shader containers in the guest-memory captures by render/tools/extract_cache.cpp and BAKED
// into g_futari_shaders[idx].defs (the containers are FREED at runtime, so a guest-mem scan finds
// nothing). Loaded into the persistent constant registers on shader match. RVK_SHDEFS gates it.
static bool rvkTrue48On();   // fwd (defined with RBatch below)

// ★ FIX-A REVERT LEVER (2026-07-29). RT_NVKOLDVS=1 puts table entries 45/47 (the GAME MODULE's
// own vertex shaders, guest 0x88009638 / 0x880098A8) back on their BAKED SPIR-V translations and
// back outside the register-true px->ndc class. Default OFF = both run the XenosRecomp-generated
// modules from render/xrgen_shaders.h. Root cause the default fixes: spirv-dis of the baked
// g_futari_spirv_24 / g_futari_spirv_9 shows a push-constant block of only {0,8,16} (the three
// BDAs) — pc.ndc at offsets 24/32 is not DECLARED, so the ndc floats both renderers push for
// VTE-off draws are dropped on the floor and gl_Position leaves the VS in SCREEN PIXELS.
static bool rvkNvkOldVs() {
  static bool on = std::getenv("RT_NVKOLDVS") && atoi(std::getenv("RT_NVKOLDVS")) != 0;
  return on;
}

static void loadShaderDefs(int shaderIdx, bool isPixel) {
  // REVIVED for the register-true vs=48 class (2026-07-18). The asset-sprite VS's c255 screen
  // transform is a shader-embedded DEF constant — {2.0, 1/256, -0.5, 0.0}, read out of the SDK
  // oracle's xe_float_cbuffer at the legal draws — which the D3D runtime uploads CPU-side at
  // SetShader time and which therefore NEVER appears in the PM4 stream (verified: RVK_C255WATCH
  // logged 0 nonzero c255 writes across a full boot->menus->attract run; the only c255 traffic
  // is boot-era full-bank ZERO uploads). Loading it on every IM_LOAD match mirrors the runtime's
  // per-SetShader def upload. Gated on RVK_TRUE48 — the legacy path repairs c255 instead.
  // (The original note here — "defs were a red herring for gameplay" — was about GAMEPLAY
  // shaders; this IS the menu/sprite class the defs belong to.)
  // FIX-A (2026-07-29): idx 45 joins the class. Its REAL container (cap_gimage.bin @0x9638)
  // carries the SAME c255 DEF — {2.0, 1/256, -0.5, 0.0} at physical offset 0x30 of its 4-float4
  // DEF pool, ucode at physOff 0x40 — and the baked translation it replaces had exactly those
  // four values as SPIR-V literals (%float_2 / %float_0_00390625 / %float_n0_5 / 0), so moving
  // them to the bank is value-identical. The generated vs45 reads c255 from the VS bank, so it
  // MUST be fed here or its positions collapse to 0. idx 47's container has NO definition table
  // (dto == 0) and its generated module reads no constants at all — nothing to load.
  // NOTE the gating asymmetry: idx 48's load stays under RVK_TRUE48 (the legacy path repairs
  // c255 for it instead), but idx 45's is gated ONLY on the module choice — with the generated
  // module bound there is no other c255 source, so RVK_TRUE48=0 must not be able to starve it.
  if (isPixel) return;
  bool needDefs = (shaderIdx == 48 && rvkTrue48On()) || (shaderIdx == 45 && !rvkNvkOldVs());
  if (!needDefs) return;
  g_vsConstF[1020] = 2.0f;       // posScale: 320-canvas -> 640px
  g_vsConstF[1021] = 0.00390625f; // uvScale: 1/256 (font atlas)
  g_vsConstF[1022] = -0.5f;      // posOffset: half-pixel
  g_vsConstF[1023] = 0.0f;
  g_vsDirty = true;
}

void matchImLoad(uint32_t addr, uint32_t stype, uint32_t sizeDwords) {
  // FNF-3 renumber tripwire (runtime half; the static_asserts in shaders_futari.h cover the
  // count). ~40 sites below are keyed on literal table indices, so a reordered table must fail
  // LOUDLY on the first IM_LOAD rather than drift silently.
  static bool anchorsOk = [] {
    struct { int i; unsigned long long a; } k[] = {
      {5, 0x8203bc00ULL}, {16, 0x8203d5e8ULL}, {44, 0x880094d0ULL},
      {48, 0xf4c1040ULL}, {49, 0x86d2040ULL},  {50, 0x11720000ULL},
      // CHROMA FIX 2 (leg 14): getOrCreateModule repoints these four by literal index, so pin
      // them here too — a renumbered table must abort, not silently repoint the wrong shader.
      {22, 0x8203e2c8ULL}, {26, 0x8203ee88ULL}, {28, 0x8203f588ULL}, {40, 0x82043a38ULL},
    };
    for (auto& e : k)
      if (g_futari_shaders[e.i].guest_addr != e.a) {
        std::fprintf(stderr, "[rvk][FATAL] shader table renumbered: idx %d guest_addr=0x%llX "
                             "expected 0x%llX -- index predicates in vk_render.cpp are invalid\n",
                     e.i, (unsigned long long)g_futari_shaders[e.i].guest_addr, e.a);
        std::abort();
      }
    return true;
  }();
  (void)anchorsOk;
  bool wantPixel = (stype & 1u) != 0;
  // ★ IM_LOAD RESULT CACHE (2026-07-27 task #17, measured before built): the guest re-issues
  // IM_LOAD for the same handful of shaders every frame — ~576 calls/frame at the training menu,
  // costing 2.26-2.40ms/frame in full-ucode FNV + 51-entry scans ([perflog2] im=, /c/tmp/
  // perfsplit.log). Cache the final match by (addr, sizeDwords, stype), validated on every hit
  // by memcmp of the first 32 + last 16 ucode bytes against guest memory — strictly STRONGER
  // than the pre-FNF-3 shipped matcher's 32-byte-prefix-only key, so a stale hit requires a
  // same-addr same-size rewrite agreeing in all 48 checked bytes (not a real pattern; the FNF-3
  // full-hash still runs on every miss/invalidation). RVK_NOIMCACHE=1 reverts to always-scan.
  static bool imCacheOff = std::getenv("RVK_NOIMCACHE") && atoi(std::getenv("RVK_NOIMCACHE")) != 0;
  struct ImEnt { uint8_t pre[32]; uint8_t tail[16]; uint32_t preN, tailN; int idx; };
  static std::unordered_map<uint64_t, ImEnt> imCache;
  const uint32_t imBytes = sizeDwords * 4;
  const uint64_t imKey = (uint64_t)addr | ((uint64_t)sizeDwords << 32) | ((uint64_t)(stype & 3u) << 56);
  if (!imCacheOff) {
    auto it = imCache.find(imKey);
    if (it != imCache.end()) {
      const ImEnt& e = it->second;
      const uint8_t* p = (const uint8_t*)(g_base + addr);
      if ((e.preN == 0 || std::memcmp(p, e.pre, e.preN) == 0) &&
          (e.tailN == 0 || std::memcmp(p + imBytes - e.tailN, e.tail, e.tailN) == 0)) {
        (wantPixel ? g_lastLoggedPsIdx : g_lastLoggedVsIdx) = e.idx;
        (wantPixel ? g_curPsIdx : g_curVsIdx) = e.idx;
        if (e.idx >= 0) loadShaderDefs(e.idx, wantPixel);
        return;
      }
      imCache.erase(it);   // content changed under the key: fall through to the full matcher
    }
  }
  int bestIdx = -1, bestScore = -1;
  // ★ s2B leg 11 — VERTEX-SHADER DISAMBIGUATION BY FULL-UCODE BYTE DISTANCE.
  // THE BORDER-SHADOW ROOT CAUSE, and the VS half of the FNF-3 class. The full-ucode FNV
  // tiebreak below is PIXEL-ONLY (a VS is never byte-equal to its captured copy: the D3D9
  // runtime patches its vfetch stubs from the vertex declaration at load time), so vertex
  // shaders are still matched on (32-byte prefix, size) alone — and TWELVE 132-byte shell VS
  // share a byte-identical prefix, so the lowest index, idx5 0x8203BC00, wins them all.
  //   idx5  inputs Location 0 + 4 (POSITION + TEXCOORD0), writes interpolator 0, ZEROES 16
  //   idx15 inputs Location 0 + 8 (POSITION + COLOR0),    writes interpolator 16 ONLY
  // The panel drop-shadow ring (guest FUN_82182008: 4 edge tristrips prim=6 n=4 st=12 + 4
  // six-segment corner fans prim=5 n=7 st=12, untextured — FUN_8209D660(dev,0,0,..) unbinds
  // stage 0 — inner verts 0xFF080808, outer 0x00000000 pushed 16px out) is idx15 + PS idx14
  // (0x8203D338, `out = interpolator16 * c2`). With idx5 substituted, interpolator 16 is a
  // hard zero, the PS shades every ring pixel to (0,0,0,0), and its SRC_ALPHA/INV_SRC_ALPHA
  // blend (blendReg 0x07060706) leaves the destination EXACTLY as it was: the ring is
  // recorded, batched, pipelined, rasterized — and invisible. Same shape as the FNF-3 TOP
  // MENU background bug, mirrored onto the VS side.
  // FIX: byte DISTANCE over the whole captured ucode. The vfetch patch touches a handful of
  // fetch-instruction fields, so the true entry is nearest by a wide margin while an unrelated
  // sibling differs in the trailing compiler signature and the export ALUs. Still a TIEBREAK,
  // never a filter: the winner is chosen only from candidates that already passed the same
  // prefix+size test as before, so no draw that renders today can start being skipped.
  // Scoped to the nvk renderer (RT_NVK>=2) — the legacy PM4 path keeps ~14 `g_curVsIdx == 5`
  // predicates that were derived under the old ambiguous matcher and it is the A/B control arm.
  // LEVER: RVK_NOSHADOWFIX=1 reverts to the historical lowest-index behaviour.
  static bool noShadowFix = std::getenv("RVK_NOSHADOWFIX") && atoi(std::getenv("RVK_NOSHADOWFIX")) != 0;
  static bool vsDistOn = [] {
    const char* e = std::getenv("RT_NVK");
    return e && atoi(e) >= 2;
  }();
  int vsDistIdx = -1; uint32_t vsDist1 = 0xFFFFFFFFu, vsDist2 = 0xFFFFFFFFu; int vsDist2Idx = -1;
  static int ucodeMatch = std::getenv("RVK_UCODEMATCH") ? atoi(std::getenv("RVK_UCODEMATCH")) : 1;
  // Hash the runtime ucode ONCE per call, bounded. Never hash at the guest-supplied length
  // directly: the shell issues an IM_LOAD with size=262140 at 0xC0006000 on every drive, and
  // the old matcher only ever touched 32 bytes. 4096 > the largest table ucode (3332).
  const uint32_t rtBytes = sizeDwords * 4;
  bool rtHashValid = false; unsigned long long rtHash = 0ull;
  if (ucodeMatch && rtBytes > 0 && rtBytes <= 4096) {
    rtHash = 0xcbf29ce484222325ull;
    const unsigned char* p = (const unsigned char*)(g_base + addr);
    for (uint32_t b = 0; b < rtBytes; ++b) rtHash = (rtHash ^ p[b]) * 0x100000001b3ull;
    rtHashValid = true;
  }
  for (unsigned si = 0; si < g_futari_shader_count; ++si) {
    const FutariShader& s = g_futari_shaders[si];
    if ((s.is_pixel != 0) != wantPixel) continue;
    size_t n = s.ucode_size < 32 ? s.ucode_size : 32;
    if (n == 0) continue;
    if (std::memcmp(g_base + addr, s.ucode_prefix, n) != 0) continue;
    int score = (s.ucode_size == sizeDwords * 4) ? 2 : 1;
    // ★ FNF-3 (2026-07-27): FULL-UCODE tiebreak. The 32-byte prefix + size key is ambiguous —
    // 7 collision groups, 22 of 51 entries permanently unreachable. The TOP MENU background's
    // PS lost this way: entries 2 and 16 share a prefix AND size 60, entry 2 wins and multiplies
    // the texel by interpolator 16 which the background's VS never writes => the draw wipes the
    // RT to black (C:/tmp/fnf3_scope/FNF3_SCOPE.md; C:/tmp/fnf3_fix/). Measured: the runtime
    // background PS blob is byte-exact to entry 16 (distance 0; 9 to idx18, 10 to idx2/idx6).
    //
    // THIS IS A SCORE BOOST, NEVER A FILTER. It sits inside the prefix-match body, after every
    // continue, and only ever RAISES a score — so the candidate set is bit-identical to the old
    // matcher and bestIdx can never go from >=0 to -1. A draw that renders today cannot start
    // being skipped. That property is the whole safety argument; do not "simplify" this into an
    // exact-match filter.
    //
    // PIXEL SHADERS ONLY by default: vertex-shader ucode is PATCHED at load time (the D3D9
    // runtime fills the vfetch stubs' format/stride/offset/prefetch fields from the vertex
    // declaration), so a VS can never be byte-equal to its captured copy — measured 0/6 VS vs
    // 6/6 PS runtime dumps. Boosting VS would be inert at best; keeping it off makes the VS side
    // PROVABLY unchanged, which is what preserves the ~14 `g_curVsIdx == 5` predicates below.
    //   RVK_UCODEMATCH=0  old prefix-only matcher, bit-exact (A/B escape hatch)
    //   RVK_UCODEMATCH=1  pixel shaders only            (DEFAULT)
    //   RVK_UCODEMATCH=2  pixel + vertex                (EXPERIMENTAL — moves g_curVsIdx off 5
    //                     for most 132-byte VS loads and silently disables the vs5 levers.
    //                     Do not ship without re-deriving those predicates.)
    // hash 0 in the table = no capture provenance (ROM rows 48/49/50) = never boosted.
    if (ucodeMatch && s.ucode_size == sizeDwords * 4 && g_futari_ucode_hash[si] != 0ull &&
        (wantPixel || ucodeMatch >= 2) && rtHashValid && g_futari_ucode_hash[si] == rtHash)
      score = 4;
    // ROM-vs-shell PREFIX COLLISION (2026-07-16, attract legal-panel fix): the ROM's runtime
    // 72B sprite/fade ps (out = tex*c14, a = tex.a*c15.x+c15.y — table entry 50, guest 0x11720000)
    // shares its first 32 ucode bytes with the SHELL's 72B vertex-color modulate-2x sprite ps
    // (entry 3), so prefix matching alone substituted the wrong shader and the attract's fade
    // overlay rendered solid opaque white (the legal-panel wash). Disambiguate on the tail: the
    // ROM variant's ALU dwords at +36/+40 are C8078000 00C0C000 (MUL o0.xyz, tex, c14).
    // RVK_ROMPS=0 disables the override for A/B.
    // (2026-07-27) STILL REQUIRED after the FNF-3 full-ucode tiebreak: the runtime ROM PS at
    // 0x11720000 is BYTE-IDENTICAL to table entry 44 (0/72 diffs, measured against
    // caps_s8/cap_gimage.bin) — one guest shader, two independent translations (44 ->
    // g_futari_spirv_6 555w, 50 -> g_xrgen_spirv_rom_ps50 565w, the validated one). No
    // ucode-based rule can separate them; without this override the lowest-index tie hands the
    // draw to 44 and the attract legal-panel wash comes back. Score 5 > the new score 4.
    if (wantPixel && si == 50 && sizeDwords * 4 >= 64) {
      static bool romPs = !(std::getenv("RVK_ROMPS") && atoi(std::getenv("RVK_ROMPS")) == 0);
      uint32_t t36 = __builtin_bswap32(*(uint32_t*)(g_base + addr + 36));
      uint32_t t40 = __builtin_bswap32(*(uint32_t*)(g_base + addr + 40));
      if (romPs && t36 == 0xC8078000u && t40 == 0x00C0C000u) score = 5;
      else continue;   // tail mismatch: entry 50 must never win on prefix alone
    }
    // s2B leg 11: distance bookkeeping over the SAME candidate set (see the block above).
    if (!wantPixel && vsDistOn && !noShadowFix && s.ucode_size == sizeDwords * 4 &&
        g_futari_vs_ucode_off[si] >= 0 && rtBytes <= 4096u) {
      const unsigned char* rt = (const unsigned char*)(g_base + addr);
      const unsigned char* cap = g_futari_vs_ucode + g_futari_vs_ucode_off[si];
      uint32_t dsum = 0;
      for (uint32_t b = 0; b < s.ucode_size; ++b) dsum += (rt[b] != cap[b]) ? 1u : 0u;
      if (dsum < vsDist1) { vsDist2 = vsDist1; vsDist2Idx = vsDistIdx; vsDist1 = dsum; vsDistIdx = (int)si; }
      else if (dsum == vsDist1 && vsDistIdx >= 0) {
        // Equal-distance tie. The capture set contains byte-IDENTICAL duplicate rows that map to
        // the SAME SPIR-V (idx 21/25/27/29/41 and 31/33, 37/39 — gen_vs_ucode.py CTL-3 proves the
        // property), and those must resolve to the lowest index exactly like the old matcher, NOT
        // fall back to the prefix winner. A tie between rows whose captured bytes DIFFER is a real
        // ambiguity: give up and leave the prefix result alone.
        if (std::memcmp(g_futari_vs_ucode + g_futari_vs_ucode_off[vsDistIdx], cap, s.ucode_size) != 0)
          vsDist2 = dsum;   // genuine ambiguity -> kills the `vsDist1 < vsDist2` gate below
      }
      else if (dsum < vsDist2) { vsDist2 = dsum; vsDist2Idx = (int)si; }
    }
    if (score > bestScore) { bestScore = score; bestIdx = (int)si; }
  }
  if (vsDistIdx >= 0 && vsDistIdx != bestIdx && vsDist1 < vsDist2) {
    static std::set<uint32_t> vsDistLogged;
    if (vsDistLogged.insert(addr).second)
      std::fprintf(stderr, "[vsdist] VS addr=0x%X size=%u: prefix-match picked idx%d, "
                           "nearest-ucode is idx%d (dist %u; runner-up idx%d dist %u) -> idx%d\n",
                   addr, sizeDwords * 4, bestIdx, vsDistIdx, vsDist1, vsDist2Idx, vsDist2, vsDistIdx);
    bestIdx = vsDistIdx;
  } else if (vsDistIdx >= 0) {
    static std::set<uint32_t> vsSameLogged;
    if (vsSameLogged.insert(addr).second)
      std::fprintf(stderr, "[vsdist] VS addr=0x%X size=%u: KEPT prefix idx%d (nearest idx%d dist %u, "
                           "runner-up idx%d dist %u%s)\n",
                   addr, sizeDwords * 4, bestIdx, vsDistIdx, vsDist1, vsDist2Idx, vsDist2,
                   (vsDistIdx == bestIdx) ? "" : " — AMBIGUOUS, no strict nearest");
  }
  int& lastLogged = wantPixel ? g_lastLoggedPsIdx : g_lastLoggedVsIdx;
  int& curIdx = wantPixel ? g_curPsIdx : g_curVsIdx;
  // RVK_IMLOADLOG (2026-07-17, decode-phase logging-spam fix): the attract's PM4 window contains
  // several IM_LOAD packets per frame that alternate between a handful of shader addresses (the
  // ROM's shell-vs-runtime shader mix), so the old "log on every transition away from lastLogged"
  // gate fired ~10+ [rvk] IM_LOAD lines EVERY frame, unbuffered (stderr piped to a log file = a
  // syscall per line). curIdx MUST still update every call (real state, drives which shader
  // renders) — only the logging is rate-limited, and only to once per unique runtime addr ever
  // seen (a shader reload at the same addr is not new information). RVK_IMLOADLOG=1 restores the
  // old spam-every-transition behavior for A/B.
  static bool imLoadLogFull = std::getenv("RVK_IMLOADLOG") != nullptr;
  bool shouldLog = imLoadLogFull ? (bestIdx != lastLogged) : false;
  if (!imLoadLogFull) {
    static std::unordered_map<uint64_t, bool> loggedAddr;   // key: (wantPixel<<32)|addr
    uint64_t key = ((uint64_t)wantPixel << 32) | addr;
    if (!loggedAddr.count(key)) { loggedAddr[key] = true; shouldLog = true; }
  }
  if (shouldLog) {
    if (bestIdx >= 0) {
      const FutariShader& s = g_futari_shaders[bestIdx];
      std::fprintf(stderr, "[rvk] IM_LOAD %s matched guest_addr=0x%llX (idx %d ucode_size=%u) <- runtime addr=0x%X size=%u\n",
                   wantPixel ? "PS" : "VS", (unsigned long long)s.guest_addr, bestIdx, s.ucode_size, addr, sizeDwords * 4);
    } else {
      char hex[65]; for (int b = 0; b < 32; ++b) std::snprintf(hex + b * 2, 3, "%02x", *(g_base + addr + b));
      std::fprintf(stderr, "[rvk] IM_LOAD %s UNMATCHED addr=0x%X size=%u prefix=%s\n",
                   wantPixel ? "PS" : "VS", addr, sizeDwords * 4, hex);
    }
  }
  lastLogged = bestIdx;
  // RVK_DUMPUCODE=1: dump MATCHED runtime-loaded shaders too (e.g. the real vs48 0xF4C1040 the
  // synth substitutes) so the true ucode can be disassembled offline (fade/material-color hunt).
  if (bestIdx >= 0 && std::getenv("RVK_DUMPUCODE")) {
    static std::unordered_map<uint32_t, bool> mdumped;
    if (!mdumped.count(addr)) { mdumped[addr] = true;
      char fn[96]; std::snprintf(fn, sizeof fn, "/tmp/ucode_%s_idx%d_%08X_%u.bin", wantPixel ? "ps" : "vs", bestIdx, addr, sizeDwords * 4);
      if (FILE* f = fopen(fn, "wb")) { fwrite(g_base + addr, 1, (size_t)sizeDwords * 4, f); fclose(f);
        std::fprintf(stderr, "[rvk] MATCHED ucode dumped -> %s\n", fn); }
    }
  }
  // LEG-44: dump any unmatched shader's raw ucode once per addr so it can be harvested
  // offline instead of its draws being skipped forever.
  if (bestIdx < 0) {
    static std::unordered_map<uint32_t, bool> dumped;
    if (!dumped.count(addr)) { dumped[addr] = true;
      char fn[96]; std::snprintf(fn, sizeof fn, "/tmp/%s_%08X_%u.bin", wantPixel ? "ps" : "vs", addr, sizeDwords * 4);
      if (FILE* f = fopen(fn, "wb")) { fwrite(g_base + addr, 1, (size_t)sizeDwords * 4, f); fclose(f);
        std::fprintf(stderr, "[rvk] UNMATCHED ucode dumped -> %s\n", fn); }
    }
  }
  if (bestIdx < 0) {
    // asset-loaded shaders aren't in the static cache; RVK_VSFB/RVK_PSFB substitute a
    // same-family table index so their draws render instead of being skipped
    static int vsfb = std::getenv("RVK_VSFB") ? atoi(std::getenv("RVK_VSFB")) : -1;
    static int psfb = std::getenv("RVK_PSFB") ? atoi(std::getenv("RVK_PSFB")) : -1;
    int fb = wantPixel ? psfb : vsfb;
    if (fb >= 0 && fb < (int)g_futari_shader_count && (g_futari_shaders[fb].is_pixel != 0) == wantPixel) {
      static std::unordered_map<uint32_t, bool> fblog;
      if (!fblog.count(addr)) { std::fprintf(stderr, "[rvk] %s FALLBACK addr=0x%X -> idx %d\n", wantPixel ? "PS" : "VS", addr, fb); fblog[addr] = true; }
      bestIdx = fb;
    }
  }
  curIdx = bestIdx;
  if (bestIdx >= 0) loadShaderDefs(bestIdx, wantPixel);   // baked definition-table constants (c255 etc.)
  // IM_LOAD cache store — AFTER the fallback substitution so hits replay the full shipped result.
  if (!imCacheOff) {
    ImEnt e{}; const uint8_t* p = (const uint8_t*)(g_base + addr);
    e.preN = imBytes < 32 ? imBytes : 32;
    e.tailN = imBytes > 48 ? 16 : 0;
    if (e.preN) std::memcpy(e.pre, p, e.preN);
    if (e.tailN) std::memcpy(e.tail, p + imBytes - e.tailN, e.tailN);
    e.idx = bestIdx;
    imCache[imKey] = e;
  }
}

VkShaderModule getOrCreateModule(int idx) {
  auto it = g.rModules.find((uint32_t)idx);
  if (it != g.rModules.end()) return it->second;
  const FutariShader& s = g_futari_shaders[idx];
  // The ROM shader set (entries 48/49/50 = asset-sprite VS 0xF4C1040, gameplay HSV color-filter PS
  // 0x86D2040, sprite/fade PS 0x11720000) carries the XenosRecomp(glvl-d3d9) GENERATED translations
  // directly in g_futari_shaders (see render/xrgen_shaders.h / gen_xrgen.sh). The hand-synth
  // sources they replaced were retired: entry 49's generated shader is texel-identical to the SDK
  // SM6 oracle (g_futari_spirv_36, the shell's own copy of the same 0x86D2040 ucode) across identity
  // and non-identity HSV, where the old hand-synth was only a hue-identity approximation.
  //
  // ★ FIX-A (2026-07-29): entries 45/47 are repointed HERE rather than in the table, because
  // shaders_futari.h rows 0..47 are extract_cache.cpp OUTPUT (regenerating it would silently drop
  // a hand-edited pointer) and because the repoint needs a revert lever. Their containers are
  // REAL and byte-exact in every capture (no synthesis: make_vs4547_containers.py carves
  // cap_gimage.bin @0x9638 / @0x98A8), and the generated vs45 reproduces the baked module's c255
  // literals exactly. RT_NVKOLDVS=1 -> the baked modules, and rvkTrue48() drops 45/47 with it.
  const unsigned* spv = s.spirv; unsigned spvDwords = s.spirv_dwords;
  if (!rvkNvkOldVs()) {
    if (idx == 45)      { spv = g_xrgen_spirv_rom_vs45; spvDwords = (unsigned)(sizeof g_xrgen_spirv_rom_vs45 / sizeof(unsigned)); }
    else if (idx == 47) { spv = g_xrgen_spirv_rom_vs47; spvDwords = (unsigned)(sizeof g_xrgen_spirv_rom_vs47 / sizeof(unsigned)); }
    if (spv != s.spirv)
      std::fprintf(stderr, "[rvk][fixa] shader idx %d (guest 0x%llX) -> xrgen module (%u dwords, was %u); RT_NVKOLDVS=1 reverts\n",
                   idx, (unsigned long long)s.guest_addr, spvDwords, s.spirv_dwords);
  }
  // ★ CHROMA FIX (s2B leg 13, 2026-07-29). Entry 20 (guest 0x8203DBD8) is the SHELL's copy of the
  // very same HSV colour-filter ucode as the ROM's entry 49 (0x86D2040) — gen_xrgen.sh's own note:
  // "rom_ps49.xpu — byte-exact from caps_gp/cap_image.bin @0x3DBD8 (guest 0x8203DBD8; code-after-
  // DEF-pool == runtime ucode 0x86D2040 family, verified byte-identical)". Entry 20 was still
  // bound to the BAKED translation (g_futari_spirv_36), which carries the XenosRecomp SETP_INV
  // bug fixed this leg (shader_recompiler.cpp: the `p0 ? 0.0 :` predicate-stack RESET was missing,
  // so the HSV->RGB sector chain died after two branches and every hue in sectors 2-5 emitted
  // (q,t,p) instead of its own permutation — V never reached the output). That is the ring pass
  // vs=21/ps=20 that feeds the 320x240 resolve ring, i.e. THE panel-art chroma mangle: measured
  // ring == (G, R+B-G, R) of the colour-correct EF4D000 field resolve to MAD 0.0/255, and
  // achromatic pixels (S==0) skip the block entirely — exactly why LEGAL/CAVELOGO always passed.
  // Repointing entry 20 at the regenerated xrgen module is the register-true fix (same ucode, no
  // hand-synth). LEVER RT_NVKNOCHROMAFIX=1 -> keep the baked module (the A/B control arm).
  {
    static bool noChromaFix = std::getenv("RT_NVKNOCHROMAFIX") && atoi(std::getenv("RT_NVKNOCHROMAFIX")) != 0;
    if (!noChromaFix && idx == 20) {
      spv = g_xrgen_spirv_rom_ps49;
      spvDwords = (unsigned)(sizeof g_xrgen_spirv_rom_ps49 / sizeof(unsigned));
      std::fprintf(stderr, "[rvk][chromafix] shader idx 20 (guest 0x%llX, HSV colour filter) -> xrgen ps49 module "
                           "(%u dwords, was %u); RT_NVKNOCHROMAFIX=1 reverts\n",
                   (unsigned long long)s.guest_addr, spvDwords, s.spirv_dwords);
    }
  }
  // ★ CHROMA FIX 2 (s2B leg 14, 2026-07-30). The SETP_INV census of the BAKED table
  // (_tmpscripts/setpinv_scan.py, report _tmpscripts/setpinv_audit_report.md) found that idx 20 was
  // NOT alone: rows 22/26/28/40 are the rest of the shell's HSV colour-filter family and carry the
  // IDENTICAL predicate-stack ladder — 5x SETP_INV, 6x PRED_SET*_PUSH, 5x SETP_POP, the whole block
  // under one CondExecPred (the `if (S != 0)` achromatic bypass). Two independent methods agreed
  // exactly: the ucode census, and a spirv-dis pattern match that found 5 UNGUARDED SETP_INV sites
  // in each of their shipping baked modules (0 in the post-fix ps49, 0 in all 38 modules whose ucode
  // has no SETP_INV). They differ from idx 20 only in their sampling front-end (22 fetches 9
  // textures, 28 fetches 3, 26/40 fetch 1) and in register allocation; the ladder HLSL is
  // line-identical to idx 20's.
  //
  // Same remediation as idx 20, so the same shape of fix: containers carved BYTE-EXACT from
  // cap_image.bin (@0x3E2C8 / @0x3EE88 / @0x3F588 / @0x43A38 — real containers, identical across
  // caps_gp/caps_gp2/caps_s8, no synthesis) by make_shellps_containers.py, translated by the FIXED
  // vendored XenosRecomp via gen_xrgen.sh. DEF-pool constants verified value-identical to the baked
  // modules they replace (_tmpscripts/setpinv_defcheck.py: container DEF pool == generated HLSL
  // literals EXACTLY on all four, and every distinct DEF value is already a SPIR-V literal in the
  // baked module) — and loadShaderDefs() returns early for pixel shaders, so there is no
  // constant-bank plumbing to add: the pool travels inside the module exactly as it does for ps49.
  //
  // LEVER RT_NVKNOCHROMAFIX2=1 -> keep all four baked modules (the A/B control arm). Deliberately a
  // SEPARATE lever from RT_NVKNOCHROMAFIX so the user-accepted idx-20 fix and these four can be
  // A/B'd independently. NOTE these are chromatic-only changes: the G6 per-band R-B half-plane gate
  // in c3_verdict.py is the acceptance instrument — luma bands are blind to this class by
  // construction (the trap that let leg 12 pass the idx-20 defect).
  {
    static bool noChromaFix2 = std::getenv("RT_NVKNOCHROMAFIX2") && atoi(std::getenv("RT_NVKNOCHROMAFIX2")) != 0;
    if (!noChromaFix2) {
      const unsigned* spv2 = nullptr; unsigned spv2Dwords = 0;
      switch (idx) {
        case 22: spv2 = g_xrgen_spirv_shell_ps22; spv2Dwords = (unsigned)(sizeof g_xrgen_spirv_shell_ps22 / sizeof(unsigned)); break;
        case 26: spv2 = g_xrgen_spirv_shell_ps26; spv2Dwords = (unsigned)(sizeof g_xrgen_spirv_shell_ps26 / sizeof(unsigned)); break;
        case 28: spv2 = g_xrgen_spirv_shell_ps28; spv2Dwords = (unsigned)(sizeof g_xrgen_spirv_shell_ps28 / sizeof(unsigned)); break;
        case 40: spv2 = g_xrgen_spirv_shell_ps40; spv2Dwords = (unsigned)(sizeof g_xrgen_spirv_shell_ps40 / sizeof(unsigned)); break;
        default: break;
      }
      if (spv2) {
        spv = spv2; spvDwords = spv2Dwords;
        std::fprintf(stderr, "[rvk][chromafix2] shader idx %d (guest 0x%llX, HSV colour filter) -> xrgen shell_ps%d module "
                             "(%u dwords, was %u); RT_NVKNOCHROMAFIX2=1 reverts\n",
                     idx, (unsigned long long)s.guest_addr, idx, spvDwords, s.spirv_dwords);
      }
    }
  }
  VkShaderModule m = makeShader(spv, (size_t)spvDwords * 4);
  if (!m) std::fprintf(stderr, "[rvk] FAIL makeShader for shader idx %d (guest 0x%llX)\n", idx, (unsigned long long)s.guest_addr);
  g.rModules[(uint32_t)idx] = m;
  return m;
}

// Xenos RB_BLENDCONTROL (0x2201) blend-factor / combine-fn -> Vulkan. Wired per-draw under
// RVK_BLEND so additive glow layers (Cave logo/HUD haze: colorDst=ONE) render bright instead
// of the hardcoded SRC_ALPHA/1-SRC_ALPHA alpha blend that dims them.
static VkBlendFactor xenosBlendFactor(uint32_t f) {
  switch (f) {
    case 0:  return VK_BLEND_FACTOR_ZERO;
    case 1:  return VK_BLEND_FACTOR_ONE;
    case 4:  return VK_BLEND_FACTOR_SRC_COLOR;
    case 5:  return VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR;
    case 6:  return VK_BLEND_FACTOR_SRC_ALPHA;
    case 7:  return VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
    case 8:  return VK_BLEND_FACTOR_DST_COLOR;
    case 9:  return VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR;
    case 10: return VK_BLEND_FACTOR_DST_ALPHA;
    case 11: return VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA;
    case 12: return VK_BLEND_FACTOR_CONSTANT_COLOR;
    case 13: return VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR;
    case 14: return VK_BLEND_FACTOR_CONSTANT_ALPHA;
    case 15: return VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA;
    case 16: return VK_BLEND_FACTOR_SRC_ALPHA_SATURATE;
    default: return VK_BLEND_FACTOR_ONE;
  }
}
static VkBlendOp xenosBlendOp(uint32_t c) {
  switch (c) {
    case 1:  return VK_BLEND_OP_SUBTRACT;
    case 2:  return VK_BLEND_OP_MIN;
    case 3:  return VK_BLEND_OP_MAX;
    case 4:  return VK_BLEND_OP_REVERSE_SUBTRACT;
    default: return VK_BLEND_OP_ADD;   // 0 = DST_PLUS_SRC
  }
}

// `rtFmt` (s2B leg 10 item 1): the colour-attachment format of the target this pipeline will be
// bound in. VK_FORMAT_UNDEFINED (or == g_rtFmt) keeps the historical g.pass, so every legacy caller
// is byte-identical; a per-target format routes through that format's render pass instead.
VkPipeline createRealPipeline(uint32_t vsIdx, uint32_t psIdx, uint32_t blendReg, uint32_t colorMask,
                              VkFormat rtFmt = VK_FORMAT_UNDEFINED) {
  VkShaderModule vsm = getOrCreateModule((int)vsIdx);
  VkShaderModule psm = getOrCreateModule((int)psIdx);
  if (!vsm || !psm) return VK_NULL_HANDLE;

  uint32_t specVal = 0;
  VkSpecializationMapEntry sme{0, 0, sizeof(uint32_t)};
  VkSpecializationInfo si{1, &sme, sizeof(uint32_t), &specVal};
  VkPipelineShaderStageCreateInfo stages[2] = {
    {VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO, nullptr, 0, VK_SHADER_STAGE_VERTEX_BIT, vsm, "main", &si},
    {VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO, nullptr, 0, VK_SHADER_STAGE_FRAGMENT_BIT, psm, "main", &si}};

  VkVertexInputBindingDescription vib{0, 24, VK_VERTEX_INPUT_RATE_VERTEX};
  VkVertexInputAttributeDescription via[3] = {
    {0, 0, VK_FORMAT_R32G32B32_SFLOAT, 0},    // loc0 POSITION0.xyz
    {8, 0, VK_FORMAT_B8G8R8A8_UNORM, 12},     // loc8 COLOR0 (D3DCOLOR)
    {4, 0, VK_FORMAT_R32G32_SFLOAT, 16}};     // loc4 TEXCOORD0.xy
  if (vsIdx == 48) {
    // extraction pre-pass normalizes every record shape into {x,y,u,v} floats at dwords 0-3
    via[0] = {0, 0, VK_FORMAT_R32G32_SFLOAT, 0};
    via[2] = {4, 0, VK_FORMAT_R32G32_SFLOAT, 8};
  }
  VkPipelineVertexInputStateCreateInfo vi{VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO};
  vi.vertexBindingDescriptionCount = 1; vi.pVertexBindingDescriptions = &vib;
  vi.vertexAttributeDescriptionCount = 3; vi.pVertexAttributeDescriptions = via;

  VkPipelineInputAssemblyStateCreateInfo ia{VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO};
  ia.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;

  VkRect2D scissor{{0, 0}, {kW, kH}};
  VkPipelineViewportStateCreateInfo vps{VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO};
  vps.viewportCount = 1; vps.pViewports = nullptr; vps.scissorCount = 1; vps.pScissors = &scissor;
  // BLEND_CONSTANTS is dynamic (2026-07-16 attract legal-panel fix): Xenos RB_BLEND_RED..ALPHA
  // (0x2105-0x2108) feed the CONSTANT_COLOR/ALPHA blend factors (xenosBlendFactor cases 12-15) and
  // the guest ANIMATES them (fade overlays). We previously left Vulkan blendConstants at the
  // pipeline default {0,0,0,0}, so ONE_MINUS_CONSTANT_* factors were stuck at 1.0 — the attract
  // legal panel's fade-from-white tile overlay rendered solid white forever (the "white grid"
  // wash). Every batch now carries the register values captured at decode time (RBatch.bc) and
  // sets them per draw; RVK_NOBLENDCONST=1 restores the old zeroed behavior for A/B.
  VkDynamicState dynStates[2] = {VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_BLEND_CONSTANTS};
  VkPipelineDynamicStateCreateInfo dyn{VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO};
  dyn.dynamicStateCount = 2; dyn.pDynamicStates = dynStates;

  VkPipelineRasterizationStateCreateInfo rs{VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO};
  rs.polygonMode = VK_POLYGON_MODE_FILL; rs.cullMode = VK_CULL_MODE_NONE; rs.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE; rs.lineWidth = 1.0f;
  VkPipelineMultisampleStateCreateInfo ms{VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO}; ms.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
  VkPipelineDepthStencilStateCreateInfo dsst{VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO};
  dsst.depthTestEnable = VK_FALSE; dsst.depthWriteEnable = VK_FALSE;

  VkPipelineColorBlendAttachmentState cba{}; cba.blendEnable = VK_TRUE;
  if (blendReg) {
    // decode RB_BLENDCONTROL: [4:0]colorSrc [7:5]colorComb [12:8]colorDst
    //                         [20:16]alphaSrc [23:21]alphaComb [28:24]alphaDst
    cba.srcColorBlendFactor = xenosBlendFactor(blendReg & 0x1f);
    cba.dstColorBlendFactor = xenosBlendFactor((blendReg >> 8) & 0x1f);
    cba.colorBlendOp        = xenosBlendOp((blendReg >> 5) & 7);
    cba.srcAlphaBlendFactor = xenosBlendFactor((blendReg >> 16) & 0x1f);
    cba.dstAlphaBlendFactor = xenosBlendFactor((blendReg >> 24) & 0x1f);
    cba.alphaBlendOp        = xenosBlendOp((blendReg >> 21) & 7);
  } else {
    cba.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA; cba.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA; cba.colorBlendOp = VK_BLEND_OP_ADD;
    cba.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE; cba.dstAlphaBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA; cba.alphaBlendOp = VK_BLEND_OP_ADD;
  }
  // RVK_FIELDNOADD (2026-07-13, field-exposure-diagnosis workflow wf_04a0809d): the escalating
  // 2x-screen (2560x1440) vs=5/34 field background layers use additive blend (colorDst=ONE) and
  // stack within one 640x512 resolve, saturating mid-tones to white. Clamp their destination
  // factor to ONE_MINUS_SRC_ALPHA so they lerp instead of pile. Gated on vs=5/34 (the full-screen
  // field stackers); menu/wallpaper/HUD draw through other VS indices and are untouched. Default
  // off = byte-identical.
  static bool fieldNoAdd = std::getenv("RVK_FIELDNOADD") != nullptr;
  if (fieldNoAdd && (vsIdx == 5 || vsIdx == 34) && cba.dstColorBlendFactor == VK_BLEND_FACTOR_ONE) {
    cba.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
  }
  // RVK_BLENDLOG (portrait-atlas RE 2026-07-15): one-shot per (vsIdx,blendReg) — dump the decoded
  // RB_BLENDCONTROL so we can see whether the char-select portrait/button sprites (vs=48) and the
  // composite (vs=47) use ADDITIVE (colorDst=ONE) blend (which piles 30+ overlapping sprite draws
  // to white — the observed wash) vs an alpha lerp. Default off = byte-identical.
  if (std::getenv("RVK_BLENDLOG")) {
    static std::set<uint64_t> blLogged;
    uint64_t blk = ((uint64_t)(uint32_t)vsIdx << 32) | (blendReg & 0xFFFFFFFu);
    if (blLogged.insert(blk).second)
      std::fprintf(stderr, "[blendlog] vs=%u blendReg=0x%X colorSrc=%u colorDst=%u colorOp=%u alphaSrc=%u alphaDst=%u alphaOp=%u\n",
        vsIdx, blendReg, blendReg & 0x1f, (blendReg >> 8) & 0x1f, (blendReg >> 5) & 7,
        (blendReg >> 16) & 0x1f, (blendReg >> 24) & 0x1f, (blendReg >> 21) & 7);
  }
  // RVK_SPRITENOADD (portrait-atlas RE 2026-07-15): the char-select composite renders 30+ vs=48
  // portrait/nameplate sprites into a 640x512 (or 512x512) atlas. If those carry ADDITIVE blend
  // (colorDst=ONE), overlapping sprites pile to white (the washed-out portrait/button pods). Clamp
  // the additive DST factor to ONE_MINUS_SRC_ALPHA for the composite-sprite VS family (47/48) so
  // they lerp. Value selects the family: 48=only vs48, 47=only vs47, default(1)=both. Default off.
  // ---- Round-14 (2026-07-15) on-window wash diagnosis (empirical, futari_merged char/mode-select) ----
  // Blend truth captured live (RVK_BLENDLOG at char-select): the vs=47 self-composite is blendReg
  // 0x10001 = ONE/ZERO = OPAQUE OVERWRITE (it does NOT accumulate via blend). vs=48 portrait sprites
  // carry THREE variants: 0x7060706 (SRC_ALPHA/INV_SRC_ALPHA lerp), 0x4000400 (ZERO/SRC_COLOR multiply),
  // and 0x1060106 (SRC_ALPHA/ONE = ADDITIVE). vs=5 bg has the same additive 0x1060106 variant.
  // REFUTATIONS (on-window screenshots, mode-select is stable so it was the A/B surface):
  //   * NOT cross-frame self-feedback: RVK_FBKILL=1 (routes the vs47/vs5 self-sample of the persistent
  //     atlas to a black 8x8 target) left the wash UNCHANGED. The FIXB2 atlas 0xF95D000 self-sample is
  //     therefore NOT the accumulator (contra the round-13 hand-off hypothesis).
  //   * NOT the HDR R16F no-clamp path: RVK_HDR=0 (harness default) washes IDENTICALLY to RVK_HDR=1.
  //   * mode-select's frosty-white "Original/Maniac" plaques are LARGELY AUTHENTIC (real Mushi Futari
  //     uses ice/crystal mode plaques) — do NOT chase them. The clean TOP-MENU plaques (Ver1.5/Arrange)
  //     and the clean version-select "Arcade" two-character portrait art prove the simple textured-quad
  //     path is fine; the defect is SPECIFIC to the FIXB2 640x512 self-composite atlas.
  // THE REAL DEFECT (res_E0280200_640x512 dump, aka r13_default_atlas.png, shear-fixed by round-13):
  //   the char-select portrait atlas is a regular GRID of blown-pure-white blobs (bubbles/backdrop) with
  //   the 2 real portraits faintly visible (cyan-accented) underneath at lower-left. This is WITHIN-FRAME
  //   over-brightness in the atlas render, NOT a decode/shear bug. RVK_SPRITENOADD/RVK_FIELDNOADD were
  //   tested on mode-select (no clear win, but mode-select frost is authentic) and NOT yet A/B'd against
  //   the char-select ATLAS dump — that is the decisive round-15 experiment (see below).
  // ROUND-15 NEXT STEPS (blocked here by the bounce, which corrupts every full-frame + DUMPRES capture):
  //   1. Reliable atlas A/B: the DUMPRES per-resolve dump (res_%08X) only fires on a sigdump frame that
  //      is ALSO a legacy render=true frame with the 640x512 scratch live — the ~2s char-select bounce
  //      makes that frame rare. Add a dedicated "dump the E028xxxx/E020xxxx scratch every Nth char-select
  //      atlas build" hook so baseline vs RVK_SPRITENOADD=1 vs a per-layer skip can be compared on the
  //      ATLAS directly, independent of the front-buffer bounce. Then isolate which segment layer
  //      (vs=5 additive bg / vs=48 additive 0x1060106 sprites / the grid-of-bubbles) over-brightens.
  //   2. SDK-oracle bounce referee (NOT run this round): futari.exe exists at
  //      Desktop/projects/futari_recomp/out/futari-test/futari.exe — drive it to char-select and observe
  //      whether IT reverts in ~2s. NOTE the port's "59 Time" countdown is FROZEN at 59 (never ticks) in
  //      every screenshot, which REFUTES a timeout-expiry cause for the bounce; the revert is a cancel/
  //      confirm mis-latch in the d76==2 browse sub-state (both mode- and char-select are d76==2), a
  //      DIFFERENT state from the d76==4 slot underflow that RT_SLOT2FIX handles. Instrument the d76==2
  //      cancel path (scene-FSM -84 flag 0x884D66EC is already cleared by RT_CONFIRMPATH; the bounce
  //      survives it, so look elsewhere in the d76==2 sub-FSM).
  static int spriteNoAdd = std::getenv("RVK_SPRITENOADD") ? std::atoi(std::getenv("RVK_SPRITENOADD")) : 0;
  if (spriteNoAdd && cba.dstColorBlendFactor == VK_BLEND_FACTOR_ONE) {
    bool hit = (spriteNoAdd == 1) ? (vsIdx == 47 || vsIdx == 48)
             : (spriteNoAdd == 48) ? (vsIdx == 48)
             : (spriteNoAdd == 47) ? (vsIdx == 47) : false;
    if (hit) cba.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
  }
  // RANK 21 (RB_COLOR_MASK, 0x2104): Xenos write_red0..write_alpha0 are bits 0-3, 1:1 with
  // VK_COLOR_COMPONENT_R/G/B/A_BIT (0x1/0x2/0x4/0x8) — a direct nibble copy, no remap needed.
  cba.colorWriteMask = (VkColorComponentFlags)(colorMask & 0xFu);
  VkPipelineColorBlendStateCreateInfo cb{VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO}; cb.attachmentCount = 1; cb.pAttachments = &cba;

  VkGraphicsPipelineCreateInfo gp{VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO};
  gp.stageCount = 2; gp.pStages = stages; gp.pVertexInputState = &vi; gp.pInputAssemblyState = &ia; gp.pViewportState = &vps;
  gp.pRasterizationState = &rs; gp.pMultisampleState = &ms; gp.pDepthStencilState = &dsst; gp.pColorBlendState = &cb; gp.pDynamicState = &dyn;
  // Render-pass compatibility (VUID-vkCmdDraw-renderPass-02684) is by ATTACHMENT FORMAT; loadOp and
  // layouts are excluded, so the CLEAR member of a pass pair also serves its LOAD member.
  VkRenderPass usePass = g.pass;
  if (rtFmt != VK_FORMAT_UNDEFINED && rtFmt != g_rtFmt) {
    NvkPassPair pp = nvkPassesFor(rtFmt);
    if (pp.clear) usePass = pp.clear;
  }
  gp.layout = g.rPlLayout; gp.renderPass = usePass; gp.subpass = 0;
  VkPipeline pipe = VK_NULL_HANDLE;
  auto sfP0 = std::chrono::steady_clock::now();
  VkResult r = vkCreateGraphicsPipelines(g.dev, VK_NULL_HANDLE, 1, &gp, nullptr, &pipe);
  g_sfPipeN++; g_sfPipeMs += std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - sfP0).count();
  if (r != VK_SUCCESS) {
    std::fprintf(stderr, "[rvk] FAIL vkCreateGraphicsPipelines(real vs=%u ps=%u fmt=%d) = %d\n",
                 vsIdx, psIdx, (int)rtFmt, (int)r);
    return VK_NULL_HANDLE;
  }
  return pipe;
}

VkPipeline getOrCreateRealPipeline(int vsIdx, int psIdx, uint32_t blendReg, uint32_t colorMask,
                                   VkFormat rtFmt = VK_FORMAT_UNDEFINED) {
  // s2B leg 10 item 1: the colour-target format is part of the pipeline's identity (see above), so
  // it MUST be in the cache key or a 10-bit/f16 target would be handed an 8-bit-pass pipeline (a
  // stale-cache collision, silent on some drivers and a hard validation error on others). Tag 0 =
  // "same as g_rtFmt" keeps every historical key bit-identical.
  uint64_t tag = (rtFmt == VK_FORMAT_UNDEFINED || rtFmt == g_rtFmt) ? 0ull : (uint64_t)nvkFmtTag(rtFmt);
  uint64_t key = ((uint64_t)(uint32_t)vsIdx << 56) | ((uint64_t)(uint32_t)psIdx << 48) |
                 (tag << 40) |
                 ((uint64_t)(colorMask & 0xFull) << 28) | (blendReg & 0xFFFFFFFull);
  auto it = g.rPipelines.find(key);
  if (it != g.rPipelines.end()) return it->second;
  VkPipeline p = createRealPipeline((uint32_t)vsIdx, (uint32_t)psIdx, blendReg, colorMask, rtFmt);
  g.rPipelines[key] = p;
  return p;
}

// PASSTHROUGH pipeline (sprite shaders + Vtx layout + g.plLayout) parameterized by RB_BLENDCONTROL,
// for the RT_HOOKRENDER path so each hooked draw blends per its guest blend state (e.g. additive
// glow layers = the menu's green-ring background) instead of the fixed SRC_ALPHA/INV_SRC_ALPHA.
// blendReg==0 reproduces g.pipeline exactly. Cached by blendReg.
VkPipeline getOrCreateHookPipeline(uint32_t blendReg, uint32_t colorMask) {
  blendReg &= 0xFFFFFFFu;
  colorMask &= 0xFu;
  uint32_t key = blendReg | (colorMask << 28);   // RANK 21: fold RB_COLOR_MASK nibble into the cache key
  auto it = g.hookPipelines.find(key);
  if (it != g.hookPipelines.end()) return it->second;
  VkShaderModule vs = makeShader(kSpriteVertSpv, sizeof kSpriteVertSpv);
  VkShaderModule fs = makeShader(kSpriteFragSpv, sizeof kSpriteFragSpv);
  VkPipelineShaderStageCreateInfo stages[2] = {
    {VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO, nullptr, 0, VK_SHADER_STAGE_VERTEX_BIT, vs, "main", nullptr},
    {VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO, nullptr, 0, VK_SHADER_STAGE_FRAGMENT_BIT, fs, "main", nullptr}};
  VkVertexInputBindingDescription vib{0, sizeof(Vtx), VK_VERTEX_INPUT_RATE_VERTEX};
  VkVertexInputAttributeDescription via[3] = {
    {0, 0, VK_FORMAT_R32G32_SFLOAT, offsetof(Vtx, x)},
    {1, 0, VK_FORMAT_R32G32_SFLOAT, offsetof(Vtx, u)},
    {2, 0, VK_FORMAT_R32G32B32A32_SFLOAT, offsetof(Vtx, r)}};
  VkPipelineVertexInputStateCreateInfo vi{VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO}; vi.vertexBindingDescriptionCount = 1; vi.pVertexBindingDescriptions = &vib; vi.vertexAttributeDescriptionCount = 3; vi.pVertexAttributeDescriptions = via;
  VkPipelineInputAssemblyStateCreateInfo ia{VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO}; ia.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
  VkViewport vp{0, 0, (float)kW, (float)kH, 0, 1}; VkRect2D sc{{0, 0}, {kW, kH}};
  VkPipelineViewportStateCreateInfo vps{VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO}; vps.viewportCount = 1; vps.pViewports = &vp; vps.scissorCount = 1; vps.pScissors = &sc;
  VkPipelineRasterizationStateCreateInfo rs{VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO}; rs.polygonMode = VK_POLYGON_MODE_FILL; rs.cullMode = VK_CULL_MODE_NONE; rs.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE; rs.lineWidth = 1.0f;
  VkPipelineMultisampleStateCreateInfo ms{VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO}; ms.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
  VkPipelineColorBlendAttachmentState cba{}; cba.blendEnable = VK_TRUE;
  if (blendReg) {
    cba.srcColorBlendFactor = xenosBlendFactor(blendReg & 0x1f);
    cba.dstColorBlendFactor = xenosBlendFactor((blendReg >> 8) & 0x1f);
    cba.colorBlendOp        = xenosBlendOp((blendReg >> 5) & 7);
    cba.srcAlphaBlendFactor = xenosBlendFactor((blendReg >> 16) & 0x1f);
    cba.dstAlphaBlendFactor = xenosBlendFactor((blendReg >> 24) & 0x1f);
    cba.alphaBlendOp        = xenosBlendOp((blendReg >> 21) & 7);
  } else {
    cba.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA; cba.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA; cba.colorBlendOp = VK_BLEND_OP_ADD;
    cba.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE; cba.dstAlphaBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA; cba.alphaBlendOp = VK_BLEND_OP_ADD;
  }
  // RANK 21 (RB_COLOR_MASK, 0x2104): direct 1:1 nibble copy (write_red0..write_alpha0 == R/G/B/A bits).
  cba.colorWriteMask = (VkColorComponentFlags)colorMask;
  VkPipelineColorBlendStateCreateInfo cb{VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO}; cb.attachmentCount = 1; cb.pAttachments = &cba;
  VkGraphicsPipelineCreateInfo gp{VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO};
  gp.stageCount = 2; gp.pStages = stages; gp.pVertexInputState = &vi; gp.pInputAssemblyState = &ia; gp.pViewportState = &vps;
  gp.pRasterizationState = &rs; gp.pMultisampleState = &ms; gp.pColorBlendState = &cb; gp.layout = g.plLayout; gp.renderPass = g.pass; gp.subpass = 0;
  VkPipeline pipe = VK_NULL_HANDLE;
  VkResult r = vkCreateGraphicsPipelines(g.dev, VK_NULL_HANDLE, 1, &gp, nullptr, &pipe);
  vkDestroyShaderModule(g.dev, vs, nullptr); vkDestroyShaderModule(g.dev, fs, nullptr);
  if (r != VK_SUCCESS) { std::fprintf(stderr, "[rvk] FAIL hook pipeline blend=0x%X mask=0x%X = %d\n", blendReg, colorMask, (int)r); pipe = g.pipeline; }
  g.hookPipelines[key] = pipe;
  return pipe;
}

// PASSTHROUGH pipeline variant keyed by the RB_COLOR_MASK (0x2104) write nibble (RANK 21). mask==0xF
// reuses g.pipeline (the original init-time pipeline, unchanged blend/state) so the overwhelmingly
// common case (full write mask) allocates nothing new; other masks lazily build+cache a variant with
// the same fixed passthrough blend (SRC_ALPHA/INV_SRC_ALPHA) but the guest's real colorWriteMask.
VkPipeline getOrCreatePassthroughPipeline(uint32_t colorMask) {
  colorMask &= 0xFu;
  if (colorMask == 0xFu) return g.pipeline;
  auto it = g.ptPipelines.find(colorMask);
  if (it != g.ptPipelines.end()) return it->second;
  VkShaderModule vs = makeShader(kSpriteVertSpv, sizeof kSpriteVertSpv);
  VkShaderModule fs = makeShader(kSpriteFragSpv, sizeof kSpriteFragSpv);
  VkPipelineShaderStageCreateInfo stages[2] = {
    {VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO, nullptr, 0, VK_SHADER_STAGE_VERTEX_BIT, vs, "main", nullptr},
    {VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO, nullptr, 0, VK_SHADER_STAGE_FRAGMENT_BIT, fs, "main", nullptr}};
  VkVertexInputBindingDescription vib{0, sizeof(Vtx), VK_VERTEX_INPUT_RATE_VERTEX};
  VkVertexInputAttributeDescription via[3] = {
    {0, 0, VK_FORMAT_R32G32_SFLOAT, offsetof(Vtx, x)},
    {1, 0, VK_FORMAT_R32G32_SFLOAT, offsetof(Vtx, u)},
    {2, 0, VK_FORMAT_R32G32B32A32_SFLOAT, offsetof(Vtx, r)}};
  VkPipelineVertexInputStateCreateInfo vi{VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO}; vi.vertexBindingDescriptionCount = 1; vi.pVertexBindingDescriptions = &vib; vi.vertexAttributeDescriptionCount = 3; vi.pVertexAttributeDescriptions = via;
  VkPipelineInputAssemblyStateCreateInfo ia{VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO}; ia.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
  VkViewport vp{0, 0, (float)kW, (float)kH, 0, 1}; VkRect2D sc{{0, 0}, {kW, kH}};
  VkPipelineViewportStateCreateInfo vps{VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO}; vps.viewportCount = 1; vps.pViewports = &vp; vps.scissorCount = 1; vps.pScissors = &sc;
  VkPipelineRasterizationStateCreateInfo rs{VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO}; rs.polygonMode = VK_POLYGON_MODE_FILL; rs.cullMode = VK_CULL_MODE_NONE; rs.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE; rs.lineWidth = 1.0f;
  VkPipelineMultisampleStateCreateInfo ms{VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO}; ms.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
  VkPipelineColorBlendAttachmentState cba{}; cba.blendEnable = VK_TRUE;
  cba.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA; cba.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA; cba.colorBlendOp = VK_BLEND_OP_ADD;
  cba.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE; cba.dstAlphaBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA; cba.alphaBlendOp = VK_BLEND_OP_ADD;
  cba.colorWriteMask = (VkColorComponentFlags)colorMask;
  VkPipelineColorBlendStateCreateInfo cb{VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO}; cb.attachmentCount = 1; cb.pAttachments = &cba;
  VkGraphicsPipelineCreateInfo gp{VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO};
  gp.stageCount = 2; gp.pStages = stages; gp.pVertexInputState = &vi; gp.pInputAssemblyState = &ia; gp.pViewportState = &vps;
  gp.pRasterizationState = &rs; gp.pMultisampleState = &ms; gp.pColorBlendState = &cb; gp.layout = g.plLayout; gp.renderPass = g.pass; gp.subpass = 0;
  VkPipeline pipe = VK_NULL_HANDLE;
  VkResult r = vkCreateGraphicsPipelines(g.dev, VK_NULL_HANDLE, 1, &gp, nullptr, &pipe);
  vkDestroyShaderModule(g.dev, vs, nullptr); vkDestroyShaderModule(g.dev, fs, nullptr);
  if (r != VK_SUCCESS) { std::fprintf(stderr, "[rvk] FAIL passthrough pipeline mask=0x%X = %d\n", colorMask, (int)r); pipe = g.pipeline; }
  g.ptPipelines[colorMask] = pipe;
  return pipe;
}

// DOCUMENTED DEVIATION (2026-07-05, verified against cap_replay_screen.bin): at the
// shell's replay screen the guest writes an M2LibMatrix whose x/y rows have NO positional
// dependence — c0=(0,0,0,146.25) c1=(0,0,0,-280) c2=0 c3=(0,0,-1,360). 146.25 = 0.5625*260
// and -280 = -1*280, i.e. it is P*T with the projection DIAGONAL zeroed (a game-state
// artifact under this harness; on this matrix every vertex collapses to one clip position
// and nothing rasterizes — nothing on screen). The SW-raster ground truth resolves such
// frames with the proven per-draw heuristic: screen-space quads (all verts >= 0) at their
// raw coordinates; model-space quads (any negative vert) offset by the viewport center
// (640,360). We reproduce that: when the snapshot matrix is position-degenerate, build TWO
// repaired variants of the projection (x*0.5625, y*-1, w=360-z) — T=0 for screen-space
// draws and T=(XOFFSET,YOFFSET) baked into c0.w/c1.w for model-space draws — and pick per
// draw. Applied to arena SNAPSHOTS only; the tracked shadow keeps the guest's real values.
// ★ 2026-07-26 (D1-B, legs 39/40/41): THE DEVIATION ABOVE IS NOW DEFAULT-OFF on the shipped PM4
// path. Both premises it rests on are gone:
//   (a) "a game-state artifact under this harness" — REFUTED. c0=(0,0,0,146.25) c1=(0,0,0,-280) is
//       the GUEST's own deliberate zero-scale park of the replay_speed widget's transform node
//       (P = *(W+0x50), P+0x2C = P+0x30 = 0.0f, written by the motion-clip interpolator
//       sub_82179168). MEASURED BIT-IDENTICAL on port and on hardware (futari_ref.exe) across 4
//       PID-pinned boots (leg 39, _tmpscripts/d1b_geom_parity.py). 146.25 = 0.5625*260 and
//       -280 = -1*280 are P*T of a widget parked at scale 0 with translation (260,280) — that is
//       the hide mechanism, not a lost upload. RenderDoc on both machines (leg 40): hardware
//       submits ZERO quads for this subtree; the port submits >=8 and repairMatrix() un-zeroes
//       them to full scale (eid 1711/1714/1717 screen variant m0=0.5625 m3=0; eid 1723 model
//       variant m3=360) => the 'ι:減速 κ:加速 ζ:×1' strip, two '×1再生' runs and the REPLAY
//       watermark that hardware does not draw.
//   (b) the OFFLINE capture case — cap_replay_screen.bin via scratch/replay_cap.cpp, whose frame
//       window's c0-c3 upload lived in an EARLIER frame, compared against swraster.py, which never
//       reads register 0x4000 at all (swraster.py:71-72) and places the REPLAY panel by fiat
//       (:51-57). That binary is not built by build_win.sh; futari_merged.exe cannot enter it.
//   (c) the LIVE trigger (gameplay squished into the left 40%, logging the SAME tx=146.25
//       ty=-280.00 because the stale-state case inherits the shell's zero-scale matrix verbatim)
//       was root-caused and properly fixed 2026-07-08 by the TYPE3 0x3F INDIRECT_BUFFER handler +
//       ibStack (:3453), which dropped the degenerate count from constant -> 1. That fix is still
//       in; removing the repair does not remove it.
// ★ BLAST RADIUS — leg-42 RE-MEASUREMENT (2026-07-26). The leg-41 figure quoted here before
//   ("16066 VS const-sets, 112 degenerate, 100% the replay-widget subtree plus one 2-frame
//   transient") was WRONG and is retracted: it came from RVK_DEBUG_CONSTS (:3883), which is gated
//   on the SAMPLED-frame set and therefore undercounted by ~90x. Re-run with rvkDegenNote's
//   ungated RVK_DEGENLOG (below), the true census is:
//     shell drive (boot/title/TOP MENU/card/legal/ROM attract incl. the demo GAME OVER + ranking
//       cycle/held SYSTEM MENU/REPLAY LOAD MENU): 9955 degenerate const-sets, in EVERY phase.
//       Classes by (tx,ty): (146.25,-280) x8909 = the replay_speed park; (0,-260) x1024;
//       (-211.5,256) x11; (0,0) x7; (-0,32) x3; (-112.78,290) x1.  vs idx 1 x9313, 48 x642.
//     play drive (real NORMAL PLAY -> death -> GAME OVER -> ranking): 23373 events, of which the
//       in-stage window is 908 and 100% of THOSE are (146.25,-280).
//   So the DRAW-level radius is wide. The PIXEL-level radius is not: with two boots per side
//   (4 drives, /c/tmp/d1b_cshell_{old,old2,new,new2}, _tmpscripts/d1b_lever22.py) the wallpaper
//   and character-art regions are BIT-IDENTICAL across the lever (MAE 0.000), title/TOP MENU/legal
//   /attract show ZERO lever-attributable 16x16 blocks despite firing 15/408/591/6236 times there
//   (i.e. those degenerate const-sets are visually inert either way), and every lever-caused
//   cluster that survives is the replay_speed subtree: the strip at (720,400), the REPLAY plate at
//   (1168..1216,720..736) and the clipped corner run on the card screen — none of which the
//   hardware referee draws. In-stage the strip/watermark boxes are statistically identical between
//   the two settings. Coverage gap, stated plainly: the port has no saved replay, so actual replay
//   PLAYBACK could only be captured on futari_ref.exe (C:/tmp/d1b_ref_play) — it shows no strip
//   either. Playback cannot regress by construction: a live widget authors a NON-degenerate
//   matrix, which this gate never touches.
// NEXT READER: do NOT "fix" this back. The guest authored the zero. A/B lever below.
//   RVK_NOMTXREPAIR / RVK_MTXREPAIR = 1  -> restore the OLD behaviour (repair runs).  =0 / unset
//   -> new register-true default (guest matrix passes through unmodified). Value-checked, so both
//   "=0" and "=1" behave (landmine (c): presence-only getenv makes "=0" fail to disable).
//   The name RVK_NOMTXREPAIR names the CHANGE being reverted (the no-matrix-repair narrowing),
//   not the resulting state: setting it to 1 turns the repair back ON.
// matrixIsDegenerate() itself stays live — the hook-path copy at RVK_HKMTXREPAIR still calls it.
static bool rvkMtxRepairOn() {
  static bool on = [] {
    if (const char* e = std::getenv("RVK_NOMTXREPAIR")) return atoi(e) != 0;   // =1 -> OLD behaviour
    if (const char* e = std::getenv("RVK_MTXREPAIR"))   return atoi(e) != 0;   // alias, same polarity
    return false;                                                             // DEFAULT: repair OFF
  }();
  return on;
}
bool matrixIsDegenerate(const float* m) {
  return m[0] == 0.f && m[1] == 0.f && m[2] == 0.f &&    // c0.xyz — no x contribution
         m[4] == 0.f && m[5] == 0.f && m[6] == 0.f &&    // c1.xyz — no y contribution
         m[14] != 0.f;                                   // c3 looks like a real w row
}
// ★ 2026-07-26 leg 42 (adversarial review): the shipped gate must NOT be written
// `rvkMtxRepairOn() && matrixIsDegenerate(..)` — with the repair default-off that short-circuits
// the predicate away and a future stale-state case would be SILENT. rvkDegenNote() is called
// whenever the predicate fires, repair on or off: it counts (never "once"), emits a periodic
// stderr warning by default, and under RVK_DEGENLOG=1 logs EVERY event — this is the leg-42
// census instrument, and unlike RVK_DEBUG_CONSTS (:3883) it is NOT gated on the sampled-frame
// set, so it cannot undercount.
static std::atomic<long> g_degenN{0};
static void rvkDegenNote(const float* m, long frame, int ndraw, int vsIdx, unsigned nverts,
                         float v0x, float v0y, bool repairOn) {
  long k = ++g_degenN;
  static bool degenlog = [] { const char* e = std::getenv("RVK_DEGENLOG"); return e && atoi(e) != 0; }();
  if (degenlog)
    std::fprintf(stderr, "[rvk][degen] #%ld f=%ld draw=%d vs=%d n=%u v0=(%.1f,%.1f) tx=%.2f ty=%.2f "
                         "c3=(%.2f,%.2f,%.2f,%.2f) repair=%d\n",
      k, frame, ndraw, vsIdx, nverts, v0x, v0y, m[3], m[7], m[12], m[13], m[14], m[15], (int)repairOn);
  else if (k == 1 || (k % 256) == 0)
    std::fprintf(stderr, "[rvk] WARNING degenerate M2LibMatrix x%ld (tx=%.2f ty=%.2f) repair=%s\n",
      k, m[3], m[7], repairOn ? "ON" : "OFF (register-true, guest matrix passes through)");
}
void repairMatrix(float* m, float tx, float ty) {
  // The projection-diagonal scales. Default (0.5625, -1) is the shell/menu-proven pair; a
  // capture whose real matrix was set in an earlier frame arrives position-degenerate and
  // needs these re-supplied. Gameplay HUD verts are pixel-space with opposite Y handedness
  // vs the menu, so allow env override (RVK_RSX / RVK_RSY) to A/B on the deterministic replay.
  static float sx = std::getenv("RVK_RSX") ? (float)atof(std::getenv("RVK_RSX")) : 0.5625f;
  static float sy = std::getenv("RVK_RSY") ? (float)atof(std::getenv("RVK_RSY")) : -1.f;
  m[0] = sx; m[3] = sx * tx;  // c0 = (sx, 0, 0, sx*tx)
  m[5] = sy; m[7] = -ty;      // c1 = (0, sy, 0, -ty)
}

// arena allocator over the per-frame BDA constants buffer
struct ArenaSlice { void* host; VkDeviceAddress addr; };
ArenaSlice arenaAlloc(VkDeviceSize sz) {
  VkDeviceSize align = 16;
  VkDeviceSize off = (g.rArenaOffset + align - 1) & ~(align - 1);
  if (off + sz > g.rArenaSize) {
    std::fprintf(stderr, "[rvk] WARNING constants arena wrapped (off=%llu sz=%llu cap=%llu)\n",
                 (unsigned long long)off, (unsigned long long)sz, (unsigned long long)g.rArenaSize);
    off = 0;
  }
  g.rArenaOffset = off + sz;
  return {(uint8_t*)g.rArenaMap + off, g.rArenaAddr + off};
}

static long g_texUpN = 0; static double g_texUpMB = 0.0;   // [texcensus] totals, also read by [bindcensus]
// upload a linear RGBA8 buffer (already in g.stagingMap) to a bindless-registrable image
bool uploadTexToBindless(uint32_t w, uint32_t h, RTex& out) {
  auto sfT0 = std::chrono::steady_clock::now();
  struct SfAcc { std::chrono::steady_clock::time_point t0; uint32_t w, h;
    ~SfAcc(){ g_sfTexN++; g_sfTexBytes += (long long)w*h*4;
      g_sfTexMs += std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now()-t0).count(); } } sfAcc{sfT0, w, h};
  // Leak census (2026-07-20 late-stage soak: RSS +~75MB/attract-cycle, 371MB->1.98GB/26min):
  // count every bindless image created + cumulative MB — the registry is append-only (no
  // vkDestroy anywhere), so if this tracks the RSS staircase the textures are the leak.
  { g_texUpMB += (double)w * h * 4.0 / (1024.0 * 1024.0);
    if ((++g_texUpN % 100) == 0) std::fprintf(stderr, "[texcensus] uploads=%ld cumMB=%.1f\n", g_texUpN, g_texUpMB); }
  VkImageCreateInfo ii{VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO}; ii.imageType = VK_IMAGE_TYPE_2D; ii.format = VK_FORMAT_R8G8B8A8_UNORM;
  ii.extent = {w, h, 1}; ii.mipLevels = 1; ii.arrayLayers = 1; ii.samples = VK_SAMPLE_COUNT_1_BIT; ii.tiling = VK_IMAGE_TILING_OPTIMAL;
  // TRANSFER_SRC added 2026-07-19: RVK_WALLBG=5 blits the guest's uploaded wallpaper compose
  // layer (0xF005000) FROM a bindless record as the border bg — same VUID class the g_wallTex
  // path hit (VUID-vkCmdBlitImage-srcImage-00219).
  ii.usage = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_SAMPLED_BIT; ii.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
  VKC(vkCreateImage(g.dev, &ii, nullptr, &out.image), "vkCreateImage(rtex)");
  VkMemoryRequirements mr{}; vkGetImageMemoryRequirements(g.dev, out.image, &mr);
  VkMemoryAllocateInfo ai{VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO}; ai.allocationSize = mr.size; ai.memoryTypeIndex = findMem(mr.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
  VKC(vkAllocateMemory(g.dev, &ai, nullptr, &out.mem), "vkAllocateMemory(rtex)");
  VKC(vkBindImageMemory(g.dev, out.image, out.mem, 0), "vkBindImageMemory(rtex)");

  segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
  rvkRingNext("rupl"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(rupl)");
  VkCommandBufferBeginInfo bi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; bi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
  VKC(vkBeginCommandBuffer(g.cmd, &bi), "begin(rupl)");
  VkImageMemoryBarrier b1{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; b1.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED; b1.newLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
  b1.srcQueueFamilyIndex = b1.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED; b1.image = out.image; b1.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  b1.srcAccessMask = 0; b1.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
  vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b1);
  VkBufferImageCopy cp{}; cp.imageSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; cp.imageExtent = {w, h, 1};
  vkCmdCopyBufferToImage(g.cmd, g.staging, out.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &cp);
  VkImageMemoryBarrier b2 = b1; b2.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL; b2.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
  b2.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT; b2.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
  vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b2);
  VKC(vkEndCommandBuffer(g.cmd), "end(rupl)");
  VkSubmitInfo subi{VK_STRUCTURE_TYPE_SUBMIT_INFO}; subi.commandBufferCount = 1; subi.pCommandBuffers = &g.cmd;
  VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(rupl)");
  VKC(rvkQueueSubmit(g.queue, 1, &subi, g.fence), "submit(rupl)");
  VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 5000000000ull), "wait(rupl)");

  VkImageViewCreateInfo iv{VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO}; iv.image = out.image; iv.viewType = VK_IMAGE_VIEW_TYPE_2D; iv.format = VK_FORMAT_R8G8B8A8_UNORM;
  iv.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  VKC(vkCreateImageView(g.dev, &iv, nullptr, &out.view), "vkCreateImageView(rtex)");
  return true;
}

void writePng(const char* path, const uint8_t* rgba, uint32_t w, uint32_t h);  // fwd (defined below)

// ---- Emulated EDRAM resolve (RB_COPY) target cache ----
// Xenos games render each layer to EDRAM, RB_COPY-resolve it to a guest texture, then a composite
// pass SAMPLES those textures. We give each resolve destination a bindless texture that the
// composite draws sample instead of guest RAM. Persists across frames (resolve in frame N is
// sampled in frame N/N+1). getTexIndexReal routes any sample of a resolved dst here.
struct ResolveTex { VkImage image = VK_NULL_HANDLE; VkDeviceMemory mem = VK_NULL_HANDLE; VkImageView view = VK_NULL_HANDLE; VkFramebuffer fb = VK_NULL_HANDLE; uint32_t idx = 0, w = 0, h = 0; bool everRendered = false;
  // ★ RVK_TFW (2026-08-03): sibling view with components.a = ONE for fetches whose tf3 dest-W
  // select is the constant 1 ({Z,Y,X,1}). Lazily created; idxA1 == 0 means "not yet".
  VkImageView viewA1 = VK_NULL_HANDLE; uint32_t idxA1 = 0;
  // RVK_BINDFIX (r23-w30): the A=1 slot inherited from a retired same-dst surface (so the lazy
  // sibling view does not burn a fresh index), and the device bytes this surface requested.
  uint32_t idxA1Reserved = 0; VkDeviceSize bytes = 0;
  // s2B leg 10 item 1: the host format this target was created with. g_rtFmt for every legacy
  // target; A2B10G10R10_UNORM_PACK32 for the nvk ring slots (guest fetch fmt 54 = k_2_10_10_10).
  // Consumers that reinterpret the bytes (writePng) MUST check this — the readback of a packed
  // 10-bit image is not RGBA8 and would render as garbage.
  VkFormat fmt = VK_FORMAT_UNDEFINED;
  // lastF (present-path-lottery fix 2026-07-21): frame number of the most recent content write
  // (render/blit). The pillarbox panel pick follows the freshest 640x512 target instead of a
  // hardcoded base — the guest's panel double-buffer base alternates per boot.
  long lastF = -1;
  // RT_COMPOSE (2026-07-13): lazily-created HOOK-path descriptor set wrapping `view`, so the
  // shell's composite quads (playfield window, wallpaper-transform ring) can sample the RENDERED
  // resolve through renderHookedFrame's per-texture descriptor pipeline. VK_NULL_HANDLE until the
  // first hooked draw references this base (see getTexture).
  VkDescriptorSet hkSet = VK_NULL_HANDLE; };
static std::unordered_map<uint32_t, ResolveTex> g_resolveTex;  // guest dst addr -> resolved surface
// ★ Alias-relevant generation (2026-07-27 task #17): bumped on every g_resolveTex entry creation
// and on every everRendered false->true transition — the only two events that can change a
// RVK_RESALIAS sibling decision (the registry is append-only, everRendered never clears). Lets
// getTexIndexReal cache its per-base alias verdict instead of linear-scanning all ~94 resolve
// targets on every one of ~530 texture lookups per frame (measured ~50K map iterations/frame
// inside the [perflog2] tex bucket at the training menu).
static uint32_t g_resolveGen = 1;
// ★★★ r23-w19 DRIVER — RVK_ONWASH: let the WASH PREDICATE arm the census instruments.
//
// WHY THIS AND NOT A NEW INSTRUMENT.  w18 closed the three missing-texture->white routes and
// left the mechanism unnamed; the two instruments that COULD name it already exist and are
// already trusted — the RT_NVKDBG per-draw batch census ([nvkdbg], vk_render.cpp:~11384) and
// the nvk resolve-target PNG dumper (~12159).  What they lacked was a TRIGGER: both fire on a
// fixed frame cadence, and the wash is a CONDITION, not a frame number.  RVK_ONWASH=<N> makes
// a [washtrig] FIRE arm BOTH for the frames the fire already forces the filmstrip to dump, so
// the census, the resolve PNGs and the composed PNG all describe THE SAME FRAME.
//
// ARM-SYMMETRY IS STRUCTURAL, not promised: RT_NVKDBGEVERY / RT_NVKRESEVERY keep firing the
// SAME code on the periodic (clean) cadence, so every washed-frame line has a same-build,
// same-code clean-frame twin to diff against.  A leg that produces only one population has
// measured nothing about the other (LAWS §10 zero law), and the verdict script says so.
//
// ⚠ COST.  Each armed frame costs one full-frame readback per resolve target (fence-waited).
// N is a HARD CAP on the number of armed windows for exactly that reason; [fps]/[perflog] were
// already VOID on any RVK_WASHTRIG leg (C-16) and stay void here.
static long g_rvkWashForce = 0;    // frames left in the current wash-armed instrument window
static long g_rvkWashSets  = 0;    // armed windows so far, capped by RVK_ONWASH
static inline void rvkResMarkRendered(ResolveTex& r, long f) {
  if (!r.everRendered) { r.everRendered = true; g_resolveGen++; }
  r.lastF = f;
}
// ★ FNF-11 host-cache invalidation request (2026-07-27, decomp-grounded: ghidra_futari_decomp/
// NOTE_fnf11_handback_decomp.md). RETURN TO TOP MENU's state-2 teardown destroy-marks EVERY
// cached guest GPU texture (FUN_8813a3c0 2..0x22 -> upload table 0x887518D0), zeroes the asset
// job ring (FUN_8813a5f0), then rebuilds the title scene in place with a fresh re-upload burst.
// A host texture cache keyed on pre-teardown identity then serves freed/stale content — the
// stuck green-panel compose. The merged_xex sub_8813A5F0 wrapper bumps this counter from the
// GUEST thread; getTexIndexReal (render-worker thread, the only cache user) consumes it at its
// next lookup and drops every content cache. Bump-counter (not flag) so back-to-back teardowns
// can never be coalesced-then-missed. RVK_NOHBINV=1 ignores requests (repro/A-B lever).
static std::atomic<uint32_t> g_hbInvReq{0};
extern "C" void rvk_handback_invalidate(void) { g_hbInvReq.fetch_add(1, std::memory_order_release); }

// ★ L5 MODULE-SWAP host cache invalidation (2026-07-31, _tmpscripts/dll_packaging_plan.md §3.3c,
// _tmpscripts/l4l5_combined_notes.md §6).
//
// WHY IT IS NOT JUST rvk_handback_invalidate(): the handback drop clears the address->image
// INDEX maps (g.rTexIndex + the reval signatures) but NOT g.texCache, whose own source comment
// at getTexture() says it is "keyed ONLY on guest base address, with zero invalidation".  Within
// one module that is survivable — the guest re-uploads to the same addresses with the same art.
// Across a MODULE SWAP it is a guaranteed visual defect: reco_normal and reco_abnormal put
// DIFFERENT art at the SAME guest addresses, so every cached entry is now a lie.
//
// DESTRUCTION (CODE_REVIEW_0804, was the "post-beta debt"): this entry point still only RAISES
// the request — the guest thread never touches renderer objects. The worker services it at a
// FRAME BOUNDARY (rvkServiceInvalidations), where it can vkDeviceWaitIdle and then genuinely
// destroy the dropped images AND reset the bindless slot allocator. The old leak-and-climb
// behaviour (maps dropped, allocator never reset) burned ~250 of the 1024 bindless slots per
// module session and killed the renderer on the 4th swap. RVK_SWAPDESTROY=0 restores it.
//
// THREADING: the maps below are owned by the render worker (getTexIndexReal is their only
// mutator).  We therefore do NOT touch them here.  We raise a request counter and let the worker
// service it at its own frame boundary — the same shape as g_hbInvReq — and then WAIT for the
// acknowledgement so the caller cannot re-image guest memory underneath a decode in flight.
// If no renderer is running (RT_VK off, or the worker is parked) the wait times out and says so
// rather than deadlocking the mode switch.
static std::atomic<uint32_t> g_swapInvReq{0};
static std::atomic<uint32_t> g_swapInvAck{0};
extern "C" void rvk_module_swap_invalidate(void) {
  uint32_t want = g_swapInvReq.fetch_add(1, std::memory_order_release) + 1;
  // Belt: also raise the existing handback request, so even a build where the swap consumer is
  // somehow not reached still drops the index maps.
  g_hbInvReq.fetch_add(1, std::memory_order_release);
  const int timeoutMs = std::getenv("RVK_SWAPINV_MS") ? atoi(std::getenv("RVK_SWAPINV_MS")) : 400;
  int waited = 0;
  while (g_swapInvAck.load(std::memory_order_acquire) < want && waited < timeoutMs) {
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
    waited += 2;
  }
  if (g_swapInvAck.load(std::memory_order_acquire) >= want)
    std::fprintf(stderr, "[swapinv] req#%u acknowledged by the render worker after %dms\n", want, waited);
  else
    std::fprintf(stderr, "[swapinv] req#%u NOT acknowledged within %dms — renderer idle or "
                         "disabled; caches will drop on its next frame\n", want, timeoutMs);
  std::fflush(stderr);
}
// Serviced by the render worker at the existing invalidation point in getTexIndexReal().
// (rvkSwapDropNvkRT is forward-declared at file scope, above the anonymous namespace — g_nvkRT
// lives ~7000 lines below and OUTSIDE that namespace, so the declaration has to match.)

// ★ RVK_BINDFIX (2026-08-22, r23-w30 — the FNF-2 fix slate; bank/r23/w29/FNF2_STATIC_WORKUP.md).
// Three defects in the bindless slot economy, every one env-revertible with RVK_BINDFIX=0:
//  (1) getOrCreateResolveTex's REPLACE path (same dst, new w/h) overwrote the cache slot and
//      leaked the old {image, mem, view, viewA1, fb} for the rest of the session, AND burnt a
//      fresh bindless index per re-creation.  Now the old surface is RETIRED — destroyed at the
//      next module-swap quiesce, where the renderer already vkDeviceWaitIdle's (this file never
//      destroys a bindless resource mid-session; see uploadTexToBindless's leak-census note) —
//      and its slot numbers are REUSED by the replacement (the reval3 precedent, line ~3700).
//  (2) g.rNextTexIndex had no in-leg bound.  The allocator resets only on a module swap, and a
//      long play leg never swaps; kMaxBindlessImages (1024, NOT kMaxTextures=256 — the w29 workup
//      mis-cited the legacy descriptor-pool size) is the descriptor array's size, a write past it
//      is undefined behaviour, and DEVICE_LOST at the next submit is its expected presentation.
//      rvkBindlessAlloc() refuses at the cap — loud, rate-limited — and returns slot 0 (the fixed
//      white), so a draw degrades to white instead of the device dying.
//  (3) the resolve path's vkCreateImage / vkAllocateMemory / vkBindImageMemory were unchecked.
// RVK_BINDCENSUS=<N> (default 0 = off): one stderr line every N frame-starts with the cursor,
// the cache sizes and the cumulative upload/resolve MB — the instrument that measures whether the
// cursor or the byte sum actually climbs toward a strike (the workup's own acceptance condition;
// a prior verdict is a hypothesis about a build, re-measure it).
static bool rvkBindFixOn() {
  static const bool on = !(std::getenv("RVK_BINDFIX") && atoi(std::getenv("RVK_BINDFIX")) == 0);
  return on;
}
// ★ RVK_BINDFIX part 2 — IN-LEG SLOT RECLAMATION (host v2, r23-w30).  The v1 slate refused at the
// cap; then g1's own [bindcensus] showed the cursor at 841/1024 EIGHT MINUTES into a plain
// Original drive (720 uploads, 650 records, 418 live keys) — refusing at the cap is a white-out
// at ~10 min of play, not a fix, and ~10 min is exactly where the w21 strikes and the 4th-swap
// "idx 931" log sit.  So: every slot getTexIndexReal hands out is registered here with its cache
// key and a last-use stamp (touched on every cache hit).  When the cursor crosses kGcHighWater
// and the free list is dry, the frame-start service quiesces the device (the swap path's own
// vkDeviceWaitIdle, no pass recording, under g_mtx) and frees every registered slot that is
// unreferenced by the index map or idle >= kGcIdleFrames; freed slots go to a free list the
// allocator drains before touching the cursor.  Resolve targets / A=1 siblings are never
// registered, never collected; slot 0 (white) and the transparent-black slot are pinned.
// Records overwritten IN PLACE (reval3 / epoch re-decodes) park their old handles on g_texRetire
// and die at the same quiesce — closing that leak too.  ⚠ g.rTexRecords is NOT slot-aligned
// (resolve slots never push a record), so every destroy here finds-and-nulls the matching
// rTexRecords entry BY HANDLE, and the swap destroy loop can never double-free.
struct TexSlot { VkImage image = VK_NULL_HANDLE; VkDeviceMemory mem = VK_NULL_HANDLE; VkImageView view = VK_NULL_HANDLE;
                 uint64_t key = 0; long lastUse = 0; bool live = false, pinned = false; };
static std::vector<TexSlot> g_slots;         // indexed by bindless slot (sized kMaxBindlessImages lazily)
static std::vector<uint32_t> g_slotFree;     // reclaimed slots, drained first by rvkBindlessAlloc
static std::vector<RTex> g_texRetire;        // in-place-overwritten records, destroyed at the next quiesce
static long g_frameStarts = 0, g_gcRuns = 0, g_gcFreed = 0, g_gcLast = -1000000;
static constexpr uint32_t kGcHighWater = 768;
static constexpr long kGcIdleFrames = 600, kGcCooldown = 600;
static void rvkSlotRegister(uint32_t idx, const RTex& t, uint64_t key, bool pinned) {
  if (g_slots.size() < kMaxBindlessImages) g_slots.resize(kMaxBindlessImages);
  if (idx == 0 || idx >= g_slots.size()) return;
  TexSlot& s = g_slots[idx];
  if (s.live && s.image && s.image != t.image) g_texRetire.push_back({s.image, s.mem, s.view});
  s.image = t.image; s.mem = t.mem; s.view = t.view; s.key = key; s.lastUse = g_frameStarts; s.live = true; s.pinned = pinned;
}
static inline void rvkSlotTouch(uint32_t idx) { if (idx < g_slots.size()) g_slots[idx].lastUse = g_frameStarts; }
static void rvkSlotReset() { g_slots.clear(); g_slotFree.clear(); g_texRetire.clear(); }   // the swap destroy freed the handles
static void rvkSlotGC(const char* why);   // defined after the reval/epoch maps it erases from
static long g_bindExhausted = 0;
static uint32_t rvkBindlessAlloc(const char* who) {
  if (rvkBindFixOn() && !g_slotFree.empty()) { uint32_t i = g_slotFree.back(); g_slotFree.pop_back(); return i; }
  if (rvkBindFixOn() && g.rNextTexIndex >= kMaxBindlessImages) {
    long i = ++g_bindExhausted;
    if (i <= 8 || (i % 1000) == 0)
      std::fprintf(stderr, "[rvk][bindless] EXHAUSTED: %s wants a slot, cursor=%u cap=%u (hit #%ld) -> slot 0 (white)\n",
                   who, g.rNextTexIndex, kMaxBindlessImages, i);
    return 0;
  }
  return g.rNextTexIndex++;
}
struct ResolveRetire { VkImage image; VkDeviceMemory mem; VkImageView view, viewA1; VkFramebuffer fb; VkDeviceSize bytes; };
static std::vector<ResolveRetire> g_resolveRetire;   // drained at the swap quiesce only
static long g_resolveReplaceN = 0;
static double g_resolveAllocMB = 0.0;                 // cumulative device MB requested for resolve targets
static void rvkResolveRetireDrain(bool destroy) {     // destroy == the caller has the device idle
  if (g_resolveRetire.empty()) return;
  double mb = 0.0;
  for (auto& r : g_resolveRetire) {
    mb += (double)r.bytes / (1024.0 * 1024.0);
    if (!destroy) continue;
    if (r.fb)     vkDestroyFramebuffer(g.dev, r.fb, nullptr);
    if (r.viewA1) vkDestroyImageView(g.dev, r.viewA1, nullptr);
    if (r.view)   vkDestroyImageView(g.dev, r.view, nullptr);
    if (r.image)  vkDestroyImage(g.dev, r.image, nullptr);
    if (r.mem)    vkFreeMemory(g.dev, r.mem, nullptr);
  }
  std::fprintf(stderr, "[rvk][resolve] retire list: %zu surfaces / %.1f MB %s\n", g_resolveRetire.size(), mb,
               destroy ? "DESTROYED at the swap quiesce" : "dropped (legacy leak)");
  g_resolveRetire.clear();
}
static bool rvkResolveCheck(VkResult r, const char* what) {   // VKC's semantics for a non-bool function
  if (r == VK_SUCCESS) return true;
  std::fprintf(stderr, "[rvk] FAIL %s = %d\n", what, (int)r); g.failed = true;
  if (g.ok && !rvkDiehardOn()) rvkVkFatal(what, (int)r);
  return false;
}
static void rvkBindCensus() {   // frame-start, under g_mtx (called from rvkServiceInvalidations)
  static const int every = std::getenv("RVK_BINDCENSUS") ? atoi(std::getenv("RVK_BINDCENSUS")) : 0;
  static long n = 0;
  if (every <= 0 || (++n % every) != 0) return;
  std::fprintf(stderr, "[bindcensus] fs=%ld cursor=%u/%u free=%zu gc=%ld/%ld texCache=%zu rTexIndex=%zu rTexRecords=%zu resolve=%zu retire=%zu/%zu replaces=%ld exhausted=%ld uploads=%ld upMB=%.1f resMB=%.1f fix=%d\n",
               n, g.rNextTexIndex, kMaxBindlessImages, g_slotFree.size(), g_gcRuns, g_gcFreed, g.texCache.size(), g.rTexIndex.size(), g.rTexRecords.size(),
               g_resolveTex.size(), g_resolveRetire.size(), g_texRetire.size(), g_resolveReplaceN, g_bindExhausted, g_texUpN, g_texUpMB,
               g_resolveAllocMB, rvkBindFixOn() ? 1 : 0);
}

// `want` (s2B leg 10 item 1): host format for this resolve target. VK_FORMAT_UNDEFINED = g_rtFmt =
// every historical caller, unchanged. The nvk resolve site passes the format implied by the guest's
// own texture fetch so the ring's 10-bit reinterpretation is honoured end to end.
ResolveTex& getOrCreateResolveTex(uint32_t dst, uint32_t w, uint32_t h, VkFormat want = VK_FORMAT_UNDEFINED) {
  auto it = g_resolveTex.find(dst);
  if (it != g_resolveTex.end() && it->second.w == w && it->second.h == h) return it->second;
  VkFormat useFmt = (want == VK_FORMAT_UNDEFINED) ? g_rtFmt : want;
  ResolveTex t{}; t.w = w; t.h = h; t.fmt = useFmt;
  if (it != g_resolveTex.end() && rvkBindFixOn()) {
    // RVK_BINDFIX (1): a size change retires the old surface and hands its slots to the new one.
    ResolveTex& o = it->second;
    g_resolveRetire.push_back({o.image, o.mem, o.view, o.viewA1, o.fb, o.bytes});
    t.idx = o.idx; t.idxA1Reserved = o.idxA1 ? o.idxA1 : o.idxA1Reserved;
    ++g_resolveReplaceN;
    std::fprintf(stderr, "[rvk][resolve] REPLACE dst=0x%X %ux%u -> %ux%u: old surface retired, slot %u reused (#%ld)\n",
                 dst, o.w, o.h, w, h, o.idx, g_resolveReplaceN);
  }
  VkImageCreateInfo ii{VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO}; ii.imageType = VK_IMAGE_TYPE_2D; ii.format = useFmt;
  ii.extent = {w, h, 1}; ii.mipLevels = 1; ii.arrayLayers = 1; ii.samples = VK_SAMPLE_COUNT_1_BIT; ii.tiling = VK_IMAGE_TILING_OPTIMAL;
  // LEG-40 Fix B: resolve texs are RENDER TARGETS (layer segments render directly into them at
  // their native w×h) as well as sampled by the composite. + TRANSFER_SRC for front-buffer readback.
  ii.usage = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT; ii.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
  rvkResolveCheck(vkCreateImage(g.dev, &ii, nullptr, &t.image), "vkCreateImage(resolve)");
  VkMemoryRequirements mr{}; vkGetImageMemoryRequirements(g.dev, t.image, &mr);
  VkMemoryAllocateInfo ai{VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO}; ai.allocationSize = mr.size; ai.memoryTypeIndex = findMem(mr.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
  rvkResolveCheck(vkAllocateMemory(g.dev, &ai, nullptr, &t.mem), "vkAllocateMemory(resolve)");
  rvkResolveCheck(vkBindImageMemory(g.dev, t.image, t.mem, 0), "vkBindImageMemory(resolve)");
  t.bytes = mr.size; g_resolveAllocMB += (double)mr.size / (1024.0 * 1024.0);
  // clear to opaque black + move to SHADER_READ so a pre-first-resolve sample is clean
  segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
  // CODE_REVIEW_0804 A3: this site (and getNvkRT) were the only two submitters that skipped the
  // ring rotation — resetting a cmd buffer/fence a deferred pass had left IN FLIGHT on the same
  // slot (VUID-00045/-01123), N times per swap when every target re-creates.
  rvkRingNext("resnew");
  vkResetCommandBuffer(g.cmd, 0);
  VkCommandBufferBeginInfo bi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; bi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT; vkBeginCommandBuffer(g.cmd, &bi);
  VkImageMemoryBarrier b{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; b.srcQueueFamilyIndex = b.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED; b.image = t.image; b.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  b.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED; b.newLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL; b.srcAccessMask = 0; b.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
  vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b);
  VkClearColorValue cc{}; cc.float32[3] = 1.f; VkImageSubresourceRange sr{VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  vkCmdClearColorImage(g.cmd, t.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, &cc, 1, &sr);
  b.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL; b.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL; b.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT; b.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
  vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b);
  vkEndCommandBuffer(g.cmd);
  VkSubmitInfo subi{VK_STRUCTURE_TYPE_SUBMIT_INFO}; subi.commandBufferCount = 1; subi.pCommandBuffers = &g.cmd;
  vkResetFences(g.dev, 1, &g.fence); rvkQueueSubmit(g.queue, 1, &subi, g.fence); rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 5000000000ull);
  VkImageViewCreateInfo iv2{VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO}; iv2.image = t.image; iv2.viewType = VK_IMAGE_VIEW_TYPE_2D; iv2.format = useFmt; iv2.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  vkCreateImageView(g.dev, &iv2, nullptr, &t.view);
  // LEG-40 Fix B: per-target framebuffer (g.pass is format-compatible; loadOp handled per-use).
  // leg 10 item 1: a framebuffer's attachment format must MATCH its render pass, so an off-g_rtFmt
  // target gets that format's pass instead of g.pass (nvkPassesFor returns {g.pass,g.passLoad} for
  // g_rtFmt, so the default case is the identical call it always was).
  { NvkPassPair pp = nvkPassesFor(useFmt);
    if (pp.clear) {
      VkFramebufferCreateInfo fbi{VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO}; fbi.renderPass = pp.clear; fbi.attachmentCount = 1; fbi.pAttachments = &t.view; fbi.width = w; fbi.height = h; fbi.layers = 1;
      vkCreateFramebuffer(g.dev, &fbi, nullptr, &t.fb);
    } }
  if (!t.idx) t.idx = rvkBindlessAlloc("resolve");   // RVK_BINDFIX: a replacement keeps its slot
  VkDescriptorImageInfo dii{VK_NULL_HANDLE, t.view, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL};
  VkWriteDescriptorSet wr{VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET}; wr.dstSet = g.rSets[0]; wr.dstBinding = 0; wr.dstArrayElement = t.idx; wr.descriptorCount = 1; wr.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE; wr.pImageInfo = &dii;
  vkUpdateDescriptorSets(g.dev, 1, &wr, 0, nullptr);
  auto& ref = (g_resolveTex[dst] = t);
  g_resolveGen++;   // new alias candidate exists: invalidate cached RVK_RESALIAS verdicts
  std::fprintf(stderr, "[rvk][resolve] target dst=0x%X %ux%u vkfmt=%d -> bindless idx %u\n", dst, w, h, (int)useFmt, t.idx);
  return ref;
}

// ★ RVK_TFW FIX (2026-08-03, ranking transparent-box): honor the texture fetch-constant's DEST-W
// swizzle select when it is CONSTANT 1. Register truth (TFALL census 08-03): every game-pane /
// resolve fetch — the ROM's 640x512 self-composite (vs47, blend 00010001 opaque), the shell's
// 1280x720 pane (vs17), the fmt54 movie frames — carries tf3 swizzle {Z,Y,X,1}: hardware forces
// sampled ALPHA to 1.0 before the shader sees it. We ignored fetch swizzles entirely, so the
// pane chain propagated the ROM RT's alpha scratch (the additive plaque-glow pass ps50 writes
// oC0.w = texel.a*c15.x+c15.y across its whole quad — margins included — into EDRAM alpha;
// authentic, invisible on hardware) all the way to the shell's SrcAlpha/InvSrcAlpha pane blend
// = the dark TRANSPARENT BOX around each ranking plaque (user report; SDK reference capture's
// pane alpha is uniform 1.0 = frame2344 refrt_r552_A). Only the W=constant case is honored:
// the RGB selects ({Z,Y,X} vs our BGRA upload order) are already baked into the decode paths,
// and every atlas fetch is plain {Z,Y,X,W} = untouched. RVK_TFW=0 reverts.
uint32_t resolveIdxA1(ResolveTex& t) {
  if (t.idxA1) return t.idxA1;
  if (!t.image) return t.idx;
  VkImageViewCreateInfo iv{VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO};
  iv.image = t.image; iv.viewType = VK_IMAGE_VIEW_TYPE_2D; iv.format = t.fmt;
  iv.components = {VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY,
                   VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_ONE};
  iv.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  if (vkCreateImageView(g.dev, &iv, nullptr, &t.viewA1) != VK_SUCCESS) { t.viewA1 = VK_NULL_HANDLE; return t.idx; }
  t.idxA1 = t.idxA1Reserved ? t.idxA1Reserved : rvkBindlessAlloc("resolveA1");
  if (!t.idxA1) {   // RVK_BINDFIX: array full -- alias the base view (loses the A=1 swizzle, never the device)
    vkDestroyImageView(g.dev, t.viewA1, nullptr); t.viewA1 = VK_NULL_HANDLE; t.idxA1 = t.idx; return t.idx; }
  VkDescriptorImageInfo dii{VK_NULL_HANDLE, t.viewA1, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL};
  VkWriteDescriptorSet wr{VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET};
  wr.dstSet = g.rSets[0]; wr.dstBinding = 0; wr.dstArrayElement = t.idxA1; wr.descriptorCount = 1;
  wr.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE; wr.pImageInfo = &dii;
  vkUpdateDescriptorSets(g.dev, 1, &wr, 0, nullptr);
  std::fprintf(stderr, "[rvk][tfw] A=1 sibling view: resolve idx %u -> idx %u (%ux%u)\n", t.idx, t.idxA1, t.w, t.h);
  return t.idxA1;
}

// Get (cache) a bindless texture index for a guest tiled texture. fmt: 6=k_8_8_8_8, 2=k_8, 4=k_4444,
// 26=k_16_16_16_16 (64bpp, four BE16 channels — title/menu art). Always expands to linear RGBA8
// host-side — one upload path for all formats. RVK_F26 picks the fmt-26 channel order (0=RGBA
// 1=ARGB 2=ABGR 3=BGRA) until one is proven on screen.
// tf0: the sampling draw's texture fetch-constant dword_0 (reg 0x4800), when the caller has it
// (renderFrameReal passes the PM4 walker's tf[0]; 0 = unknown => historical pow2-stride untile).
// Per the Xenos fetch-constant layout: bit 31 = tiled, bits 22..30 = row pitch in 32-texel units
// — used by RVK_TEXPITCH below to give tiledOff the TRUE macro-row stride for non-pow2 pitches.
// RVK_FETCHRAW (2026-07-27, FNF-1 loading blob): dump the RAW 6-dword texture fetch constant the
// first time each (base,fmt) with an UNSUPPORTED format reaches a texture bind — register-true
// evidence of what the guest actually wrote (fmt 22 = Xenos k_24_8 depth-stencil per SDK
// rex/graphics/xenos.h:492; the blob window binds a 1x1 k_24_8 at alias base 0x10000000).
// Default off; capped at 32 distinct keys.
static void rvkFetchRawNote(const uint32_t* tf, uint32_t base, uint32_t tw, uint32_t th, uint32_t fmt, const char* path) {
  static bool on = std::getenv("RVK_FETCHRAW") != nullptr;
  if (!on || fmt == 6 || fmt == 2 || fmt == 4 || fmt == 26 || fmt == 3) return;
  static std::unordered_map<uint64_t, int> seen;
  uint64_t key = ((uint64_t)base << 8) | fmt;
  if (seen.size() >= 32 || seen.count(key)) return;
  seen[key] = 1;
  std::fprintf(stderr, "[fetchraw][%s] fmt=%u base=0x%08X dims=%ux%u tf={%08X %08X %08X %08X %08X %08X}\n",
               path, fmt, base, tw, th, tf[0], tf[1], tf[2], tf[3], tf[4], tf[5]);
  // Measured 07-27: the blob-window tf has TYPE bits = 3 = kVertex (SDK FetchConstantType) — the
  // decode read a VERTEX fetch constant as a texture. The REAL texture constant, if the guest
  // wrote one, is in another slot of the full register shadow: scan all 32 texture-fetch slots
  // and print every one whose type bits = 2 (kTexture), so the fix knows where to look.
  if ((tf[0] & 3u) != 2u) {
    for (uint32_t s = 0; s < 32; ++s) {
      const uint32_t* t6 = &g_regFile[0x4800 + s * 6];
      if ((t6[0] & 3u) != 2u || !t6[1]) continue;
      std::fprintf(stderr, "[fetchraw][%s]   slot%u IS kTexture: fmt=%u base=0x%08X dims=%ux%u tf0=%08X tf1=%08X tf2=%08X\n",
                   path, s, t6[1] & 0x3F, ((t6[1] >> 12) & 0xFFFFF) << 12,
                   (t6[2] & 0x1FFF) + 1, ((t6[2] >> 13) & 0x1FFF) + 1, t6[0], t6[1], t6[2]);
    }
  }
}

// ★ [shtex] AUTO-REQUEST (2026-08-01, ranking-shadow leg). The first cut of this instrument keyed
// on a hardcoded texture base (0x134E8000, read out of a previous boot's log) and produced ZERO
// hits — guest texture bases are per-boot wall-clock allocations, so an address banked in the
// ledger is not an invariant (the same landmine as the menu-flash leg). The draw CLASS is the
// invariant: the nvk draw loop sets this request when it sees the watched RB_BLENDCONTROL, with
// the UV bbox taken from the draw's own vertices, and getTexIndexReal's analyser consumes it on
// the next decode of that base. Same thread (the render worker owns both), so no locking.
struct ShtexReq { uint32_t base = 0, x0 = 0, y0 = 0, x1 = 0, y1 = 0; };
static ShtexReq g_shtexReq;

// Revalidation signature maps (were function-local statics inside getTexIndexReal; promoted to
// file scope 2026-08-04 so the frame-boundary invalidation service below can clear them).
static std::unordered_map<uint64_t, uint32_t> revalSig;
static std::unordered_map<uint64_t, uint32_t> reval3HitCount;
static std::unordered_map<uint64_t, uint32_t> reval3Sig;
static std::unordered_map<uint64_t, uint32_t> reval3FireCount;
static uint32_t g_swapDestroyGen = 0;   // bumped ONLY by the swap destroy+allocator-reset below;
                                        // statics caching bindless indices (blackIdx) key on this,
                                        // NOT on g_resolveGen (which bumps on everRendered flips).

// ★ CODE_REVIEW_0804 A1/A4: invalidation service — FRAME-BOUNDARY ONLY, replaces the consumer
// blocks that used to sit inside getTexIndexReal (i.e. mid-frame, per-draw). Two verified
// defects lived in that placement:
//  (1) the mid-frame g_nvkRT.clear() dangled the nvk executor's curRT (a raw NvkRT*) for the
//      rest of the frame — freed-heap framebuffer/image reads on every swap frame;
//  (2) with no GPU quiesce, dropped objects could still be in flight, so images were leaked
//      and — the actual 4th-swap hang — g.rNextTexIndex kept climbing (~250 slots per module
//      session, maps cleared but the ALLOCATOR never reset) into the hard 1024-slot bindless
//      cap: hang log futari_beta1_20260803_201252 shows idx 931 just before swap #4's burst.
// Now: callers invoke this at frame starts only (renderFrameReal entry, nvk_frame_submit,
// inline present — all under g_mtx, no pass recording, no curRT live). On a module swap we
// quiesce the device, DESTROY the dropped Vulkan objects (closing the RSS staircase too),
// reset the slot allocator, and rebuild the fixed white texture at index 0 in place.
// RVK_SWAPDESTROY=0 reverts to the historical leak-and-climb drop (minus the mid-frame clear).
static void rvkServiceInvalidations() {
  ++g_frameStarts;
  rvkBindCensus();   // RVK_BINDCENSUS (r23-w30): the bindless-economy census, frame-start cadence
  // RVK_BINDFIX part 2: reclaim slots at the high-water mark (cooldown so an all-hot set cannot
  // quiesce every frame; an all-hot set past the cap still degrades to white via the allocator).
  if (rvkBindFixOn() && g.ok && !g.failed && g_slotFree.size() < 16 && g.rNextTexIndex >= kGcHighWater &&
      g_frameStarts - g_gcLast >= kGcCooldown) { g_gcLast = g_frameStarts; rvkSlotGC("highwater"); }
  // [hbinv] handback drop (FNF-11) — index maps only, images stay registered (append-only).
  { static bool hbInvOff = std::getenv("RVK_NOHBINV") && atoi(std::getenv("RVK_NOHBINV")) != 0;
    static uint32_t hbSeen = 0;
    uint32_t hbCur = g_hbInvReq.load(std::memory_order_acquire);
    if (!hbInvOff && hbCur != hbSeen) { hbSeen = hbCur;
      size_t n0 = g.rTexIndex.size();
      g.rTexIndex.clear(); revalSig.clear(); reval3Sig.clear(); reval3HitCount.clear(); reval3FireCount.clear();
      g_resolveGen++;
      std::fprintf(stderr, "[hbinv] guest teardown -> host tex caches dropped (%zu entries) req#%u\n",
                   n0, hbCur); } }
  // Module-swap drop+destroy.
  { static uint32_t swapSeen = 0;
    uint32_t swCur = g_swapInvReq.load(std::memory_order_acquire);
    if (swCur != swapSeen) { swapSeen = swCur;
      static bool keepRes = std::getenv("RVK_SWAPKEEPRES") && atoi(std::getenv("RVK_SWAPKEEPRES")) != 0;
      static bool destroyOff = std::getenv("RVK_SWAPDESTROY") && atoi(std::getenv("RVK_SWAPDESTROY")) == 0;
      size_t nT = g.texCache.size(), nR = g_resolveTex.size(), nN = 0;
      uint32_t idx0 = g.rNextTexIndex;
      // keepRes (08-04 recomposed for the swap-dance A/B): resolve entries survive the swap —
      // their images/views are kept and RE-REGISTERED into fresh slots after the allocator
      // reset, so the experiment now composes with the exhaustion fix instead of reviving it.
      bool destroy = !destroyOff && g.ok && !g.failed;
      if (destroy) {
        { std::lock_guard<std::mutex> ql(g_qMtx); vkDeviceWaitIdle(g.dev); }
        for (int s = 0; s < 6; ++s) g.ringPending[s] = false;   // all fences signaled after idle
        for (auto& kv : g.texCache) { Tex& t = kv.second;       // hook-path sets stay allocated
          if (t.view)  vkDestroyImageView(g.dev, t.view, nullptr);   // (pool has no FREE bit)
          if (t.image) vkDestroyImage(g.dev, t.image, nullptr);
          if (t.mem)   vkFreeMemory(g.dev, t.mem, nullptr); }
        if (!keepRes)
          for (auto& kv : g_resolveTex) { ResolveTex& t = kv.second;   // fb references t.view; passes are shared
            if (t.fb)     vkDestroyFramebuffer(g.dev, t.fb, nullptr);
            if (t.viewA1) vkDestroyImageView(g.dev, t.viewA1, nullptr);
            if (t.view)   vkDestroyImageView(g.dev, t.view, nullptr);
            if (t.image)  vkDestroyImage(g.dev, t.image, nullptr);
            if (t.mem)    vkFreeMemory(g.dev, t.mem, nullptr); }
        rvkResolveRetireDrain(true);   // RVK_BINDFIX: the retired same-dst surfaces die here, device idle
        nN = rvkSwapDestroyNvkRT();
        for (auto& t : g.rTexRecords) {   // includes the white at [0] — rebuilt just below
          if (t.view)  vkDestroyImageView(g.dev, t.view, nullptr);
          if (t.image) vkDestroyImage(g.dev, t.image, nullptr);
          if (t.mem)   vkFreeMemory(g.dev, t.mem, nullptr); }
        g.rTexRecords.clear();
        g.rNextTexIndex = 1;
        rvkSlotReset();   // RVK_BINDFIX part 2: the handles above are gone; drop the slot table + free list
        g_swapDestroyGen++;
        // rebuild the fixed white texture (index 0) immediately so no caller ever sees an empty
        // registry mid-session; the lazy boot-time guards stay for first init only.
        ((uint32_t*)g.stagingMap)[0] = 0xFFFFFFFFu;
        RTex wt{};
        if (uploadTexToBindless(1, 1, wt)) {
          g.rTexRecords.push_back(wt);
          VkDescriptorImageInfo dii{VK_NULL_HANDLE, wt.view, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL};
          VkWriteDescriptorSet wr{VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET};
          wr.dstSet = g.rSets[0]; wr.dstBinding = 0; wr.dstArrayElement = 0; wr.descriptorCount = 1;
          wr.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE; wr.pImageInfo = &dii;
          vkUpdateDescriptorSets(g.dev, 1, &wr, 0, nullptr);
        } else {
          std::fprintf(stderr, "[swapinv] WARN white-texture rebuild failed after swap destroy\n");
        }
        if (keepRes) {
          // re-register the kept resolve pages' views into fresh slots (post-reset)
          size_t rr = 0;
          for (auto& kv : g_resolveTex) { ResolveTex& t = kv.second;
            VkWriteDescriptorSet wr{VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET};
            wr.dstSet = g.rSets[0]; wr.dstBinding = 0; wr.descriptorCount = 1;
            wr.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
            if (t.view) { t.idx = rvkBindlessAlloc("swapkeep");
              VkDescriptorImageInfo di{VK_NULL_HANDLE, t.view, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL};
              wr.dstArrayElement = t.idx; wr.pImageInfo = &di;
              vkUpdateDescriptorSets(g.dev, 1, &wr, 0, nullptr); ++rr; }
            if (t.viewA1) { t.idxA1 = rvkBindlessAlloc("swapkeepA1");
              VkDescriptorImageInfo di{VK_NULL_HANDLE, t.viewA1, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL};
              wr.dstArrayElement = t.idxA1; wr.pImageInfo = &di;
              vkUpdateDescriptorSets(g.dev, 1, &wr, 0, nullptr); }
          }
          std::fprintf(stderr, "[swapinv] KEEPRES: %zu resolve pages kept + re-registered\n", rr);
        }
      } else {
        rvkResolveRetireDrain(false);
        nN = rvkSwapDropNvkRT();
      }
      g.texCache.clear();
      if (!keepRes) g_resolveTex.clear();
      g.rTexIndex.clear(); revalSig.clear(); reval3Sig.clear(); reval3HitCount.clear(); reval3FireCount.clear();
      g_resolveGen++;
      std::fprintf(stderr, "[swapinv] MODULE SWAP -> %s texCache=%zu resolveTex=%zu nvkRT=%zu "
                           "(+ index maps); bindless slots %u -> %u, req#%u\n",
                   destroy ? "destroyed" : "dropped (legacy leak)", nT, nR, nN,
                   idx0, g.rNextTexIndex, swCur);
      std::fflush(stderr);
      g_swapInvAck.store(swCur, std::memory_order_release); } }
}
// Identity-collision detector state (RVK_IDLOG=1). Parallel to g.rTexIndex so the cache struct
// is untouched: key -> allocation epoch of the guest bytes at the moment we decoded them.
extern "C" uint32_t rt_mem_epoch(uint32_t addr, uint32_t bytes);
static std::unordered_map<uint64_t, uint32_t> g_texEpoch;
// RVK_BINDFIX part 2 — the collector (declared with the slot table above; defined here, after the
// reval/epoch maps it has to erase from).  Caller: rvkServiceInvalidations at a frame start.
static void rvkSlotGC(const char* why) {
  if (g_slots.empty() || !g.dev) return;
  { std::lock_guard<std::mutex> ql(g_qMtx); vkDeviceWaitIdle(g.dev); }
  for (int s = 0; s < 6; ++s) g.ringPending[s] = false;   // all fences signaled after idle
  std::vector<uint8_t> refd(g_slots.size(), 0);
  for (auto& kv : g.rTexIndex) if (kv.second < refd.size()) refd[kv.second] = 1;
  auto nullRec = [](VkImage im) { if (!im) return;
    for (auto& r : g.rTexRecords) if (r.image == im) { r.image = VK_NULL_HANDLE; r.mem = VK_NULL_HANDLE; r.view = VK_NULL_HANDLE; } };
  auto destroy = [&](VkImage im, VkDeviceMemory mem, VkImageView view) { nullRec(im);
    if (view) vkDestroyImageView(g.dev, view, nullptr);
    if (im)   vkDestroyImage(g.dev, im, nullptr);
    if (mem)  vkFreeMemory(g.dev, mem, nullptr); };
  size_t retired = g_texRetire.size();
  for (auto& r : g_texRetire) destroy(r.image, r.mem, r.view);
  g_texRetire.clear();
  long freed = 0, hot = 0, unref = 0;
  for (uint32_t i = 1; i < g_slots.size() && i < g.rNextTexIndex; ++i) {
    TexSlot& s = g_slots[i];
    if (!s.live || s.pinned) continue;
    const bool ref = refd[i] != 0, idle = (g_frameStarts - s.lastUse) >= kGcIdleFrames;
    if (ref && !idle) { ++hot; continue; }
    if (ref) { g.rTexIndex.erase(s.key); g_texEpoch.erase(s.key); revalSig.erase(s.key); reval3Sig.erase(s.key);
               reval3HitCount.erase(s.key); reval3FireCount.erase(s.key); } else ++unref;
    destroy(s.image, s.mem, s.view);
    s = TexSlot{}; g_slotFree.push_back(i); ++freed;
  }
  rvkResolveRetireDrain(true);   // same quiesce pays for the retired resolve surfaces
  ++g_gcRuns; g_gcFreed += freed;
  std::fprintf(stderr, "[rvk][gc] #%ld (%s) fs=%ld cursor=%u/%u freed=%ld (unreferenced %ld, idle %ld) hot=%ld retired=%zu free=%zu rTexIndex=%zu\n",
               g_gcRuns, why, g_frameStarts, g.rNextTexIndex, kMaxBindlessImages, freed, unref, freed - unref, hot, retired,
               g_slotFree.size(), g.rTexIndex.size());
}
static bool rvkIdLog(){ static bool v = std::getenv("RVK_IDLOG") && std::atoi(std::getenv("RVK_IDLOG")) != 0; return v; }

uint32_t getTexIndexReal(uint32_t base, uint32_t w, uint32_t h, uint32_t fmt, uint32_t tf0 = 0,
                         uint32_t blendReg = 0xFFFFFFFFu, uint32_t tf3 = 0) {
  // ★ RVK_TFW (2026-08-03): tf3 dest-W select == constant 1 ⇒ sample resolves through the A=1
  // sibling view (see resolveIdxA1 above). Swizzle field is (tf3>>1)&0xFFF (bit 0 = num_format,
  // the banked 08-01 lesson); W select = bits [11:9] of that; code 5 = constant ONE.
  static const bool tfwOff = [](){ const char* e = std::getenv("RVK_TFW"); return e && e[0]=='0' && !e[1]; }();
  const bool wantA1 = !tfwOff && tf3 != 0 && ((((tf3 >> 1) & 0xFFFu) >> 9) & 7u) == 5u;
  // RVK_RAWDUMP2=0xBASE (streaming-race RE 2026-07-15): dump the LIVE guest bytes of a watched base
  // every 300 samples (BEFORE the cache short-circuit), sequence-numbered — to see whether the
  // asset's RAM evolves after the first (possibly mid-stream) decode. Diagnostic only, default off.
  // 2026-07-27 hot-path fix (task #17, third instance of the RVK_REGPROBE getenv class): these
  // two diagnostics called std::getenv UNCONDITIONALLY on every getTexIndexReal — ~500 draws x2
  // CRT-locked calls per frame, measured inside the 3ms [perflog2] tex bucket. Cache once.
  static const char* rawDump2Env = std::getenv("RVK_RAWDUMP2");
  if (const char* rd2 = rawDump2Env) {
    uint32_t rb2 = (uint32_t)std::strtoul(rd2, nullptr, 0);
    if (base == rb2 && g_base) {
      static int seq = 0, cnt = 0;
      if ((cnt++ % 300) == 0 && seq < 8) {
        char nm[128]; std::snprintf(nm, sizeof nm, "/tmp/raw2_%08X_s%d.bin", base, seq++);
        FILE* f = std::fopen(nm, "wb");
        if (f) { std::fwrite(g_base + base, 1, (size_t)0x60000u, f); std::fclose(f);
          std::fprintf(stderr, "[rawdump2] %s\n", nm); } }
    }
  }
  // RVK_ZSCAN (portrait streaming-race DECIDER 2026-07-15, Round-11): the async-load-race question
  // asks whether a portrait texture whose bytes are ~30% ZERO on first decode FILLS IN over time
  // (race: bytes arrive after we cache the striped decode) or stays zero forever (permanent non-
  // standard layout). Answer it STATISTICALLY across every fmt-3 256x256 portrait base and over
  // time, so it doesn't depend on the exact striped base recurring: for each such base, scan the
  // LIVE guest 0x20000-byte region (256*256*2) every 300 samples counting zero 16-bit texel words,
  // BEFORE the cache short-circuit. Log first occurrence (first-decode zero ratio) and any change
  // since first (>1% delta = the RAM evolved = RACE). Diagnostic only, default off.
  static bool zscanOn = std::getenv("RVK_ZSCAN") != nullptr;
  // 2026-08-03 water-banner leg: also admit the 512x512 backdrop pages at any base — the
  // char-select band traced to page 0x08D60000 being 100% ZERO (never written; fmt3 zeros are
  // colorkey-transparent, so the layer behind shows through = the "water banner"). This census
  // answers "which of the six pages are empty and do they ever fill in".
  if (zscanOn && fmt == 3 && g_base &&
      ((w == 256 && h == 256 && base >= 0x12000000u && base < 0x18100000u) ||
       (w == 512 && h == 512))) {
    struct ZS { double first; double last; int loggedFirst; long calls; int rescans; };
    static std::unordered_map<uint32_t, ZS> zmap;
    auto& z = zmap[base];
    long c = z.calls++;
    // Re-scan every 90 of THIS base's own calls (guaranteed periodic, not global-counter dependent),
    // capped at 12 rescans so a base held on screen forever doesn't spam. First call always scans.
    if (z.loggedFirst == 0 || (c % 90 == 0 && z.rescans < 12)) {
      const uint16_t* p = (const uint16_t*)(g_base + base);
      size_t zc = 0; const size_t N = (256u * 256u); // count zero 16-bit words contiguously
      for (size_t i = 0; i < N; ++i) if (p[i] == 0) ++zc;
      double ratio = 100.0 * (double)zc / (double)N;
      if (z.loggedFirst == 0) { z.first = z.last = ratio; z.loggedFirst = 1;
        std::fprintf(stderr, "[zscan] base=0x%X FIRST-decode zero=%.1f%%\n", base, ratio);
      } else {
        z.rescans++;
        double d = ratio - z.first;
        std::fprintf(stderr, "[zscan] base=0x%X rescan#%d zero=%.1f%% (delta-from-first %+.1f%%)%s\n",
          base, z.rescans, ratio, d, (z.first > 5.0 && ratio < z.first - 5.0) ? "  <== FILLING IN (RACE)" : "");
        z.last = ratio;
      }
    }
  }
  // If this base was written by an emulated RB_COPY resolve, sample the RENDERED surface, not
  // the (empty) guest RAM — this is what makes the composite pass show the real layers.
  // RVK_RESREAL=1 (2026-07-13): a registered resolve target that was rendered this session returns
  // its rendered image; a NEVER-rendered one is CLEARED TO BLACK (getOrCreateResolveTex clears
  // RGB=0,A=1). The field's additive bloom/glow layers (vs=5/ps=34) sample the 320x240 downsample
  // pool as feedback; a never-rendered pool target must read BLACK (= no glow contribution), NOT
  // the index-0 WHITE the fmt fallback below returns (fmt=54 is unsupported) — that white is what
  // blew the field to white. So: prefer a RENDERED sibling (RESALIAS, real content); if none, fall
  // back to THIS target's own black-cleared image (nrBlackIdx) rather than index-0 white. Default
  // off = byte-identical (the whole guard collapses to the plain exact-match return).
  static bool resReal = std::getenv("RVK_RESREAL") != nullptr;
  // RVK_TEXWATCH=0xADDR (2026-07-14, Fable-guided field-wash diag): trace the SELECTION for one
  // watched base (e.g. the vs=5 field-bg full-frame resolve 0xF005000). Logs ONLY when the returned
  // (idx, everRendered) for that base CHANGES -> if idx is stable across the burst, selection is
  // deterministic (exact-match is monotonic) and the wash is a CONTENT stomp upstream, NOT a binding
  // flicker. Default off = byte-identical (parse once, no log unless base==watch AND changed).
  static uint32_t texWatch = [](){ const char* e = std::getenv("RVK_TEXWATCH"); return e ? (uint32_t)std::strtoul(e, nullptr, 0) : 0u; }();
  if (texWatch && base == texWatch) {
    auto wit = g_resolveTex.find(base);
    int widx = wit != g_resolveTex.end() ? (int)wit->second.idx : -1;
    int wever = wit != g_resolveTex.end() ? (int)wit->second.everRendered : -1;
    static int lIdx = -2, lEver = -2;
    if (widx != lIdx || wever != lEver) {
      std::fprintf(stderr, "[rvk][texwatch/get] base=0x%X %ux%u fmt=%u -> idx=%d everRendered=%d (was idx=%d ever=%d)\n",
        base, w, h, fmt, widx, wever, lIdx, lEver);
      lIdx = widx; lEver = wever;
    }
  }
  int nrBlackIdx = -1;
  { auto rit = g_resolveTex.find(base); if (rit != g_resolveTex.end()) {
      if (!resReal || rit->second.everRendered)
        return wantA1 ? resolveIdxA1(rit->second) : rit->second.idx;
      nrBlackIdx = (int)rit->second.idx;   // never-rendered = black-cleared; last-resort fallback
      static std::unordered_map<uint32_t, int> skipped;
      if (skipped.size() < 12 && !skipped.count(base)) { skipped[base] = 1;
        std::fprintf(stderr, "[rvk][resreal] base=0x%X %ux%u never rendered -> sibling|black\n", base, w, h); }
  } }
  // RVK_RESALIAS=1 (LEG-43): the game ROTATES between sibling resolve buffers (0x50000/0xA0000
  // strides); frames sample bases that never received a decoded RB_COPY (only their siblings
  // did), so the exact-match above misses and we'd upload raw guest RAM (the magenta placeholder
  // fill / garbage-fmt white). Route such a base to a resolve target with IDENTICAL w×h within
  // ±0x100000 — the closest sibling. Not cached in rTexIndex so a later real resolve to this
  // base takes over via the exact match.
  static bool resAlias = std::getenv("RVK_RESALIAS") != nullptr;
  // ★ 512x512 EXCLUDED from sibling aliasing (2026-08-11 — consume-side attribution CLOSED).
  // quadcensus f6492 + [resalias] caught the streamed plate atlas 0x170BC000 hijacked onto the
  // backdrop-page 0x1717C000's resolve entry (dist=0xC0000, shared idx 241) — "blocks of
  // legitimate page art where the plates belong", the 08-07 select-screen corruption, and the
  // reason it moved with allocation layout (the hijack needs the atlas to land within 0x100000
  // of a page dest). 512x512 is the PAGE class: pages are always sampled at their EXACT dest
  // base (NOTES_select_compose.md, identity dest==fetch; bake proven live 08-07/08-11), so a
  // 512 proximity alias can only ever capture a genuine guest atlas that shares the page dims.
  // The LEG-43 rotation this alias exists for is the pane/downsample pool class (640x480 etc.),
  // which keeps aliasing. RVK_RESALIAS512=1 restores the old behaviour for A/B.
  static bool alias512 = std::getenv("RVK_RESALIAS512") && atoi(std::getenv("RVK_RESALIAS512")) != 0;
  if (resAlias && base && w >= 64 && h >= 64 && (alias512 || !(w == 512 && h == 512))) {
    // ★ Cached alias verdict (2026-07-27 task #17): the linear scan below ran for EVERY texture
    // lookup (~530/frame) over EVERY resolve target (~94 at the menu) = ~50K map iterations per
    // frame. The verdict for a (base,w,h) can only change when g_resolveTex gains an entry or an
    // everRendered flips (g_resolveGen tracks exactly those), so replay it until then. The scan
    // itself is unchanged — a gen bump falls straight through to it. RVK_NOALIASCACHE=1 reverts.
    static bool aliasCacheOff = std::getenv("RVK_NOALIASCACHE") && atoi(std::getenv("RVK_NOALIASCACHE")) != 0;
    struct AliasEnt { uint32_t gen; int idx; uint32_t w, h; uint32_t sibBase; };   // idx -1 = "no sibling"
    static std::unordered_map<uint32_t, AliasEnt> aliasCache;
    if (!aliasCacheOff) {
      auto ait = aliasCache.find(base);
      if (ait != aliasCache.end() && ait->second.gen == g_resolveGen &&
          ait->second.w == w && ait->second.h == h) {
        if (ait->second.idx >= 0) {
          if (wantA1) {   // RVK_TFW: route the cached sibling through its A=1 view
            auto sit = g_resolveTex.find(ait->second.sibBase);
            if (sit != g_resolveTex.end()) return resolveIdxA1(sit->second);
          }
          return (uint32_t)ait->second.idx;
        }
        goto aliasMiss;   // cached "no sibling": skip the scan, keep the normal fallthrough
      }
    }
    {
    ResolveTex* bestRt = nullptr; uint32_t bestDist = 0x100001u; uint32_t bestBase = 0;
    for (auto& kv : g_resolveTex) {
      if (kv.second.w != w || kv.second.h != h || !kv.second.image) continue;
      if (resReal && !kv.second.everRendered) continue;  // RVK_RESREAL: no white-init siblings
      uint32_t d = kv.first > base ? kv.first - base : base - kv.first;
      if (d < bestDist) { bestDist = d; bestRt = &kv.second; bestBase = kv.first; }
    }
    if (!aliasCacheOff) aliasCache[base] = {g_resolveGen, bestRt ? (int)bestRt->idx : -1, w, h, bestBase};
    if (bestRt) {
      static std::unordered_map<uint32_t, int> aliased;
      if (!aliased.count(base)) { aliased[base] = 1;
        std::fprintf(stderr, "[rvk][resalias] base=0x%X %ux%u -> resolve sibling (dist=0x%X idx=%u)\n",
          base, w, h, bestDist, bestRt->idx); }
      return wantA1 ? resolveIdxA1(*bestRt) : bestRt->idx;
    }
    }
    aliasMiss:;
  }
  // No rendered sibling found: if this base IS a never-rendered resolve target, return its own
  // black-cleared image (correct for additive glow) instead of index-0 white below.
  if (nrBlackIdx >= 0) return (uint32_t)nrBlackIdx;
  // RVK_TEXWHITE (2026-07-16): count draws that fall back to WHITE (index 0) because their texture
  // FETCH CONSTANT is zero/implausible. This path has no log, and it is the prime suspect for "the
  // wash": the presented field panel is 76% pure white in a REGULAR 10x10 QUAD GRID with only 37
  // distinct colours = a grid of quads all sampling the 1x1 white placeholder, NOT over-brightness.
  // Suspected mechanism (sibling of RT_VTXSNAP, which exists because only 3/150 draws had their
  // VERTEX-fetch setter inside the captured arena): the TEXTURE-fetch setter is set in a prior kick
  // or inside an INDIRECT_BUFFER whose live guest memory is recycled by present time, so the decoder
  // reads base=0 here and silently binds white.
  if (!base || w == 0 || h == 0 || w > 2048 || h > 2048) {
    if (std::getenv("RVK_TEXWHITE")) {
      static long twN = 0, twBase0 = 0, twDim = 0;
      ++twN; if (!base) ++twBase0; else ++twDim;
      if ((twN % 200) == 0)
        std::fprintf(stderr, "[texwhite] WHITE-FALLBACK draws=%ld (base==0: %ld, bad-dims: %ld) last base=0x%X %ux%u fmt=%u\n",
                     twN, twBase0, twDim, base, w, h, fmt);
    }
    return 0; // white @ index 0
  }
  if (fmt != 6 && fmt != 2 && fmt != 4 && fmt != 26 && fmt != 3) {
    static std::unordered_map<uint32_t, bool> warned;
    if (!warned.count(fmt)) { std::fprintf(stderr, "[rvk] unsupported texture fmt=%u base=0x%X %ux%u — using white\n", fmt, base, w, h); warned[fmt] = true;
      // RVK_DUMP_ON_WHITE (2026-07-23 dim-quad hunt): first unsupported-fmt fallback arms the
      // per-draw ops dump for the next few frames — catches the offending draw's vs/ps/blend.
      extern bool g_dumpWhiteTrig; if (std::getenv("RVK_DUMP_ON_WHITE")) g_dumpWhiteTrig = true; }
    // RVK_ALIASPROBE (2026-07-16): Fable's verdict is that "the wash" is this white fallback taken for
    // a RESOLVE-COPY texture whose fetch-constant base carries a PHYSICAL-ALIAS bit (e.g. 0x1116D000)
    // that g_resolveTex.find(base) misses because the resolve registered at the un-aliased 0x116D000.
    // Log whether masking the alias bits WOULD have hit a registered resolve. res=1 = alias miss proven.
    if (std::getenv("RVK_ALIASPROBE")) {
      static std::unordered_map<uint32_t,int> seen;
      if (seen.size() < 40 && !seen.count(base)) { seen[base]=1;
        std::fprintf(stderr, "[aliasprobe] WHITE base=0x%X fmt=%u %ux%u | raw_res=%d masked(0x1FFFFFFF)=0x%X masked_res=%d\n",
          base, fmt, w, h, (int)g_resolveTex.count(base), base & 0x1FFFFFFFu, (int)g_resolveTex.count(base & 0x1FFFFFFFu)); }
    }
    // ★ FNF-1 FIX (2026-07-27, loading-blob): if the "fetch constant" is not TYPED as a texture
    // (tf0 bits[1:0] != 2 = FetchConstantType::kTexture, SDK rex/graphics/xenos.h:1093), this
    // decode read a VERTEX fetch constant as a texture. Measured live in the blob window
    // ([fetchraw][segman]): tf0=0x0110037B type=3=kVertex, decoding to a phantom 1x1 fmt-22
    // (k_24_8) @0x10000000 — and NO kTexture-typed constant exists in any of the 32 shadow
    // slots at that moment (the guest's texture-setter kick is not yet decoded; the port
    // converges to correct rings ~frame 105 when it arrives). Hardware would never read those
    // bits as a texture; sampling WHITE painted the loading rings/text as the solid white BLOB
    // (SDK oracle snap t1: clean rings + crisp text in the same window). Bind a transparent
    // BLACK 1x1 for the transient instead: additive/src-alpha blends contribute nothing and
    // opaque draws match the black loading background, so the pre-bind window is simply blank —
    // converging to the oracle look. tf0==0 keeps the old white (legacy callers that pass no
    // tf0 must be byte-identical). RVK_NOTYPEBLACK=1 reverts to white for A/B.
    static bool typeBlackOff = std::getenv("RVK_NOTYPEBLACK") && atoi(std::getenv("RVK_NOTYPEBLACK")) != 0;
    // ★ SWAP WHITE-FLASH FIX (2026-08-03, beta1): repeat mode swaps (arcade->360->arcade)
    // surface draws whose TYPED texture fetch carries garbage format bits (fmt=54 base=0x20B7000
    // 320x240 in the user's beta1 log — a runtime-heap descriptor from the module's PREVIOUS
    // attach; heap state is not part of the re-imaged xex DATA sections). The white placeholder
    // turned each into a fullscreen-class WHITE FLASH. Hardware would sample stale memory (dark
    // garbage), never solid white — so substitute the FNF-1 transparent black for any
    // unsupported-fmt fetch BIGGER than 1x1. The 1x1 white stays: the RVK_DIMFIX veil multiplies
    // vertex color by the sample and needs white. RVK_UNSUPWHITE=1 reverts to the old behaviour.
    static bool unsupWhite = std::getenv("RVK_UNSUPWHITE") && atoi(std::getenv("RVK_UNSUPWHITE")) != 0;
    // ★ BLEND-AWARE PLACEHOLDER (2026-08-03, ranking-shadow convergence). There is NO single
    // neutral placeholder colour: WHITE is neutral for modulate-class blends (dst scaled by the
    // incoming colour — sample 1.0 leaves the frame untouched), BLACK/transparent for additive
    // and src-alpha. The 5addec0 black substitution fixed the swap white FLASH but manufactured
    // a black SQUARE SHADOW on modulate draws (user: shadow appeared on ARCADE ranking) — and
    // the ORIGINAL 360-only plaque shadow is plausibly the same neutral-mismatch via the FNF-1
    // type-black (07-27). So: when the draw's blend is KNOWN (blendReg passed by both call
    // sites; recorded d.blendReg on the nvk path, live g_regFile[0x2201] on the walk path) and
    // it is modulate-class (srcColor factor DST_COLOR/1-DST_COLOR, or dstColor factor
    // SRC_COLOR/1-SRC_COLOR), keep the WHITE placeholder — white on a modulate draw is
    // invisible by construction, so the swap flash cannot return through this exception.
    // Unknown blend stays conservative (black). RVK_NOMODWHITE=1 reverts the exception.
    static bool modWhiteOff = std::getenv("RVK_NOMODWHITE") && atoi(std::getenv("RVK_NOMODWHITE")) != 0;
    bool modulate = false;
    if (!modWhiteOff && blendReg != 0xFFFFFFFFu) {
      uint32_t srcF = blendReg & 0xFFu, dstF = (blendReg >> 8) & 0xFFu;
      modulate = (srcF == 8 || srcF == 9) || (dstF == 4 || dstF == 5);
    }
    bool wantBlack = !modulate &&
                  ( (!typeBlackOff && tf0 != 0 && (tf0 & 3u) != 2u)
                  || (!unsupWhite && (w > 1 || h > 1)) );
    if (wantBlack) {
      static int blackIdx = -1;
      static uint32_t blackGen = 0;   // CODE_REVIEW_0804: swap destroy+reset invalidates the cached slot
      if (blackGen != g_swapDestroyGen) { blackGen = g_swapDestroyGen; blackIdx = -1; }
      if (blackIdx < 0) {
        ((uint32_t*)g.stagingMap)[0] = 0x00000000u;
        RTex bt{};
        uint32_t bslot = 0;
        if (uploadTexToBindless(1, 1, bt) && (bslot = rvkBindlessAlloc("black")) == 0) {
          // RVK_BINDFIX: array full -- drop the upload (fence-waited, unreferenced), fall back to the white
          vkDestroyImageView(g.dev, bt.view, nullptr); vkDestroyImage(g.dev, bt.image, nullptr); vkFreeMemory(g.dev, bt.mem, nullptr);
          blackIdx = 0;
        } else if (bslot != 0) {
          blackIdx = (int)bslot;
          g.rTexRecords.push_back(bt);
          rvkSlotRegister(bslot, bt, 0, true);   // pinned: a function-static holds this slot
          VkDescriptorImageInfo dii{VK_NULL_HANDLE, bt.view, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL};
          VkWriteDescriptorSet wr{VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET};
          wr.dstSet = g.rSets[0]; wr.dstBinding = 0; wr.dstArrayElement = (uint32_t)blackIdx; wr.descriptorCount = 1;
          wr.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE; wr.pImageInfo = &dii;
          vkUpdateDescriptorSets(g.dev, 1, &wr, 0, nullptr);
          std::fprintf(stderr, "[rvk][fnf1] non-texture fetch constant (type=%u) -> transparent-black idx=%d (was white)\n",
                       tf0 & 3u, blackIdx);
        }
      }
      if (blackIdx >= 0) return (uint32_t)blackIdx;
    }
    return 0;
  }
  if (fmt == 26) {
    static std::unordered_map<uint32_t, int> seen26;
    if (seen26.size() < 16 && !seen26.count(base)) { std::fprintf(stderr, "[rvk] fmt26 tex base=0x%X %ux%u\n", base, w, h); seen26[base] = 1; }
  }
  uint64_t key = ((uint64_t)base << 8) | fmt;
  // RVK_TEXREFRESH=0xADDR (2026-07-14, frozen-bg RE): the vs=5 field background samples a full-frame
  // guest framebuffer (e.g. 0xF005000) that the game REWRITES each frame, but our g.rTexIndex cache
  // uploads it ONCE and reuses forever -> the "background" is frozen at its first-seen contents (the
  // menu wallpaper). For the matched base, bypass the cache so it re-decodes from live guest RAM every
  // call. NOTE: the minimal path below re-uploads into a NEW bindless image each call (old one leaks) —
  // fine for the dynamic-vs-static DIAGNOSTIC; a committed version reuses the image. Default off =
  // byte-identical.
  static uint32_t texRefresh = [](){ const char* e = std::getenv("RVK_TEXREFRESH"); return e ? (uint32_t)std::strtoul(e, nullptr, 0) : 0u; }();
  // gate to the ACTIVE field (0x885C1A20) so the per-frame re-upload doesn't slow boot/menus (which
  // also sample this base) and starve the autopilot reach.
  bool doRefresh = texRefresh && base == texRefresh &&
                   g_base && __builtin_bswap32(*(const uint32_t*)(g_base + GA_FIELD_ACTIVE)) != 0u;
  // RVK_TEXREVAL2 (portrait streaming-race candidate — RETIRED AS A FIX, Round-11 2026-07-15): the
  // Round-10 hypothesis was that a texture whose FIRST sample lands mid-async-stream (RT_ASYNCIO) is
  // decoded from PARTIAL guest RAM, cached with no invalidation, and reused striped forever. Round-11
  // REFUTED that race with RVK_ZSCAN (top of getTexIndexReal): across ~15 distinct fmt-3 256x256
  // portrait bases held for the full char-select duration (~60 per-base rescans), EVERY base's live
  // zero-texel ratio stayed at its first-decode value (delta-from-first +0.0%, ZERO "FILLING IN" hits).
  // The guest RAM is COMPLETE at first decode and never evolves -> there is no transient for this lever
  // to revalidate, which is exactly why it logged zero useful re-decodes. Independently, RVK_RAWDUMP=1
  // (broadened to the whole 0x12000000..0x18100000 range) captured all 16 portrait/sprite/font fmt-3
  // 256x256 bases of a boot and decoded them offline through THIS tiledOff(): ALL 16 are CLEAN (fonts,
  // bullet-rings, character sprites, scenery, mode-select panels — /c/tmp/roster_montage.png). So
  // tiledOff() is proven correct roster-wide and the decode/layout is NOT the portrait defect either.
  // WHERE THE REAL DEFECT IS (Round-11, on-window char-select): the big portrait renders as magenta/
  // diagonal-scramble or dark blocks that VARY frame-to-frame. RVK_COMPDBG shows the vs=47 composite
  // samples tex=0xF95D000 (640x512) — the SAME atlas the vs=48 portrait sprites resolve into
  // ("FIXB2 SEG 0 batches[0,69) -> tex dst=0xF95D000 640x512") — so it is NOT an atlas-aliasing miss;
  // the atlas CONTENT itself is bad. Next round belongs on the FIXB2 / resolve-atlas RENDER (the
  // fragile central-playfield compose path), NOT on texture decode or cache revalidation. This lever
  // and RVK_TILEFIX are both dead ends for the portrait defect; kept env-gated, default off = byte-
  // identical to shipped.
  static int texReval2 = std::getenv("RVK_TEXREVAL2") ? std::atoi(std::getenv("RVK_TEXREVAL2")) : 0;
  // (revalSig and the reval3 maps are file-scope now — see rvkServiceInvalidations above.)
  auto revalHash = [&]() -> uint32_t {
    uint32_t lbh = (fmt == 26) ? 3u : (fmt == 6) ? 2u : 1u;
    uint32_t s = 0x811C9DC5u;
    for (int i = 0; i < 32; ++i) {
      uint32_t sx = (uint32_t)((i * 37) % (w ? w : 1)), sy = (uint32_t)((i * 53) % (h ? h : 1));
      uint32_t a = base + tiledOff(sx, sy, w, lbh, 0);
      uint32_t v = (lbh >= 2) ? be32(a) : be16(a);
      s = (s ^ v) * 0x01000193u;
    }
    return s;
  };
  // RVK_TEXREVAL3 (2026-07-21, char-select "card" painting mid-load freeze FIX): root cause proven
  // by prior probes -- the char-select big painting samples texture page 0x12634000 (fmt-3
  // k_1_5_5_5, 256x256) which is FIRST-SAMPLED MID-LOAD during the card's entry animation. The
  // legacy cache below (g.rTexIndex) decodes it once from whatever guest bytes are present at that
  // instant and never revalidates, so a half-loaded page freezes half-black forever. RVK_TEXREVAL2
  // above already explored (and refuted, for the *portrait* class) a similar content-hash idea but
  // used a 32-sample per-pixel scan seeded off the DECODED layout; this lever instead hashes the
  // SOURCE GUEST BYTES directly (layout-agnostic, cheap) and is scoped to ALL legacy-cache textures,
  // rate-limited to ~once per 30 cache hits per key so steady-state cost stays negligible. On a
  // genuine content change it forces the key down the miss/decode path below but REUSES the existing
  // bindless index in place (see the upload tail) rather than growing rNextTexIndex, since
  // kMaxBindlessImages is a hard 1024-slot cap and draws already re-query getTexIndexReal every
  // frame (no separate "rebind" step needed for the refreshed content to reach the screen).
  // Default ON; RVK_TEXREVAL3=0 restores the shipped never-revalidate behavior byte-identically.
  static int texReval3 = std::getenv("RVK_TEXREVAL3") ? std::atoi(std::getenv("RVK_TEXREVAL3")) : 1;
  // 2026-07-30 adaptive density (HI stream-pool residue): 64 samples over a 2MB page miss
  // partial band rewrites (the leftover speckle/stale tiles after the every-hit change), but
  // dense-hashing every static atlas would be waste. Pages with >=2 observed content changes
  // are PROVEN stream-cycled — they get a 1024-sample hash (~4KB of reads, still trivial).
  auto reval3Hash = [&](int samples) -> uint32_t {
    uint32_t bpt = (fmt == 26) ? 8u : (fmt == 6) ? 4u : (fmt == 4 || fmt == 3) ? 2u : 1u;
    size_t regionBytes = (size_t)w * h * bpt;
    size_t stride = regionBytes >= (size_t)samples * 4 ? ((regionBytes / samples) & ~(size_t)3) : 4;
    if (stride < 4) stride = 4;
    uint32_t s = 0x811C9DC5u;
    for (int i = 0; i < samples; ++i) {
      size_t off = (size_t)i * stride;
      if (off + 4 > regionBytes) off = regionBytes >= 4 ? (regionBytes - 4) : 0;
      uint32_t v = be32(base + (uint32_t)off);
      s = (s ^ v) * 0x01000193u;
    }
    return s;
  };
  int reval3ReuseIdx = -1;   // set below when RVK_TEXREVAL3 forces a re-decode; tells the upload
                             // tail to reuse this bindless slot instead of growing rNextTexIndex.
  // (The [hbinv] and module-swap consumers that lived here moved to rvkServiceInvalidations() —
  // CODE_REVIEW_0804: consuming them per-draw dangled the executor's curRT and reset nothing.
  // The RVK_SWAPKEEPRES rationale (2026-08-03 black-flash experiment) moved with them.)
  auto it = g.rTexIndex.find(key);
  if (doRefresh && it != g.rTexIndex.end()) {   // re-uploading an already-cached base: log the rate
    static int refreshCnt = 0;
    if ((refreshCnt++ % 120) == 0) std::fprintf(stderr, "[texrefresh] base=0x%X re-decode+upload #%d (field-active)\n", base, refreshCnt);
  }
  // ★ IDENTITY-COLLISION DETECTOR (2026-08-07, RVK_IDLOG=1, default off).
  // The cache below is keyed on GUEST BASE. If the guest freed that memory and the allocator
  // re-handed the address to a different asset, we keep serving the old decode under a base that
  // now means something else. rt_mem_epoch() (out_reco/harness.cpp) counts frees per 16KB bucket;
  // recorded at upload, re-checked here. A change means the backing memory was freed between the
  // decode and this sample — i.e. this texture's identity is no longer trustworthy.
  // This exists because every prior verdict on the select corruption was a human looking at a
  // screen, on a defect whose severity moves with allocation layout. See the harness comment.
  // ★ 08-11: the detector's verdict now ACTS — EPOCH INVALIDATOR (RT_EPOCHINVAL, default ON).
  // The post-swap HUD corruption (arcade→360 re-entry, user-sighted; ledger 08-11 late) is this
  // exact class with reval3's sampled hash missing the change (64 dwords at the wrong byte size
  // for DXT — a 16KB band in a 2MB atlas is invisible). Instead of widening hash signatures, act
  // on the allocator truth the detector already reads: an epoch mismatch means the backing guest
  // memory was FREED since our decode, and a free is the NECESSARY event for any identity change
  // — so re-decode, reusing the bindless slot via the same fall-through reval3 uses. No hash, no
  // coverage holes, one array-walk per cached hit. The w*h*4 range OVERestimates DXT footprints,
  // so a neighbouring free can cause a spurious re-decode (bounded cost, never staleness).
  // RT_EPOCHINVAL=0 reverts to detector-only ([idcol] logging stays under RVK_IDLOG).
  static const bool epochInval = [](){ const char* e = std::getenv("RT_EPOCHINVAL"); return e ? atoi(e) != 0 : true; }();
  bool epochStale = false;
  if ((epochInval || rvkIdLog()) && base) {
    uint32_t now = rt_mem_epoch(base, w * h * 4u);
    auto eit = g_texEpoch.find(key);
    if (eit != g_texEpoch.end() && eit->second != now) {
      if (rvkIdLog()) {
        static long nCol = 0; static std::unordered_map<uint32_t,int> seen;
        ++nCol;
        if (seen.size() < 64 && !seen.count(base)) { seen[base] = 1;
          std::fprintf(stderr, "[idcol] COLLISION base=0x%X %ux%u fmt=%u epoch %u -> %u "
                               "(guest memory freed since decode; cache still serving old bytes) "
                               "total=%ld\n", base, w, h, fmt, eit->second, now, nCol); }
        else if ((nCol % 500) == 0)
          std::fprintf(stderr, "[idcol] collisions=%ld (latest base=0x%X %ux%u fmt=%u)\n",
                       nCol, base, w, h, fmt);
      }
      if (epochInval && it != g.rTexIndex.end()) {
        epochStale = true;
        reval3ReuseIdx = (int)it->second;   // re-decode into the SAME bindless slot below
        static long epFires = 0; ++epFires;
        if (epFires <= 40 || (epFires % 600) == 0)
          std::fprintf(stderr, "[epochinval] base=0x%X %ux%u fmt=%u freed-since-decode -> re-decode (#%ld)\n",
                       base, w, h, fmt, epFires);
      }
      g_texEpoch[key] = now;   // report each transition once, not every frame after it
    }
  }
  if (it != g.rTexIndex.end() && !doRefresh && !epochStale) {
    if (texReval2 && (fmt == 3 || fmt == 4 || fmt == 6) && w >= 32 && h >= 32 && base && g_base) {
      uint32_t sig = revalHash();
      auto sit = revalSig.find(key);
      if (sit != revalSig.end() && sit->second == sig) { rvkSlotTouch(it->second); return it->second; }   // content stable -> reuse
      static std::unordered_map<uint32_t, int> revalLogged;
      if (revalLogged.size() < 24 && !revalLogged.count(base)) { revalLogged[base] = 1;
        std::fprintf(stderr, "[texreval2] base=0x%X %ux%u fmt=%u content changed since decode -- re-decoding\n", base, w, h, fmt); }
      // fall through to re-decode; signature (re)stored after upload below.
    } else if (texReval3 && base && g_base) {
      // RVK_REVALFORCE=1 (FNF-12 seam experiment 2026-07-27, default off): force a re-decode on
      // EVERY hit for large fmt-6 atlases. Discriminator only: if the M2 seam lines heal under
      // this, the stale-decode/streaming-race hypothesis is proven and the real fix is a
      // correct-coverage reval hash (reval3Hash samples 64 dwords with the WRONG byte size for
      // DXT — a ~16KB band change in a 2MB atlas is invisible to it).
      static int revalForce = std::getenv("RVK_REVALFORCE") ? std::atoi(std::getenv("RVK_REVALFORCE")) : 0;
      if (revalForce && fmt == 6 && w >= 2048) {
        reval3ReuseIdx = (int)it->second;
        // fall through to re-decode/upload below (same reuse-in-place path as a reval3 hit)
      } else {
      // 2026-07-30 HI-mode stream-pool fix: the %30 hit-throttle made stream-CYCLED pages
      // (reco_abnormal's 211MB cg_v154hi.bin rotates textures through a guest pool — 8+
      // [texreval3] fires on 0x26EE000/0xF32000 in one training run vs ZERO on ARCADE, whose
      // 58MB ROM sits resident) render as permanent strips-of-stale: between revals the pool
      // page holds a newer scroll window than the cached decode. The HASH is ~free (64 sampled
      // dwords); only the DECODE is expensive and only fires on real content change — so hash
      // EVERY hit and let genuinely-dynamic pages re-decode at their true rewrite rate (work
      // the real console's unified memory did implicitly). RVK_TEXREVAL3THROTTLE=<n> restores
      // an every-n-hits hash (the old behavior at n=30) as the perf escape hatch.
      static const uint32_t reval3Throttle = std::getenv("RVK_TEXREVAL3THROTTLE")
        ? (uint32_t)std::atoi(std::getenv("RVK_TEXREVAL3THROTTLE")) : 1u;
      uint32_t& hitc = reval3HitCount[key];
      uint32_t c = hitc++;
      if (reval3Throttle <= 1u || (c % reval3Throttle) == 0) {
        uint32_t& fires = reval3FireCount[key];
        uint32_t sig3 = reval3Hash(fires >= 2 ? 1024 : 64);
        auto s3 = reval3Sig.find(key);
        if (s3 == reval3Sig.end()) { reval3Sig[key] = sig3; rvkSlotTouch(it->second); return it->second; }  // first hit: just baseline
        if (s3->second == sig3) { rvkSlotTouch(it->second); return it->second; }                            // unchanged -> reuse
        s3->second = sig3;
        if (fires < 2 && ++fires == 2)
          s3->second = reval3Hash(1024);   // re-baseline at the density all later compares use
        reval3ReuseIdx = (int)it->second;
        static long reval3Fires = 0;
        ++reval3Fires;
        if (reval3Fires <= 40 || (reval3Fires % 600) == 0) {
          std::fprintf(stderr, "[texreval3] base=0x%X fmt=%u re-decoded (#%ld)\n", base, fmt, reval3Fires); }
        // fall through to re-decode/upload below, reusing reval3ReuseIdx.
      } else { rvkSlotTouch(it->second); return it->second; }
      }
    } else { rvkSlotTouch(it->second); return it->second; }
  }

  uint8_t* dst = (uint8_t*)g.stagingMap;
  uint32_t lb = (fmt == 26) ? 3u : (fmt == 6) ? 2u : (fmt == 4 || fmt == 3) ? 1u : 0u;
  static int f26ord = getenv("RVK_F26") ? atoi(getenv("RVK_F26")) : 0;
  // Xenos fetch-constant bit30 = tiled. The gameplay textures carry tiled=0 (LINEAR), so
  // untiling them via tiledOff() scrambles them into blocks. Default = auto (honor bit30 of
  // the current fetch constant @0x4800); RVK_TEXLINEAR=1 forces linear, =2 forces tiled.
  // NOTE (2026-07-08): the large playfield/background textures ARE tiled (reading them linear
  // streaks them into cyan/magenta bands); bit30 of the fetch constant turned out NOT to be a
  // reliable tiled flag here. Default = TILED (tiledOff, the original + best-looking path).
  // RVK_TEXLINEAR=1 forces linear (cleaner for the small HUD atlas but wrong for backgrounds).
  static int texMode = getenv("RVK_TEXLINEAR") ? atoi(getenv("RVK_TEXLINEAR")) : 0;
  bool linear = (texMode == 1);
  // RVK_TEXPITCH (rank 6, register-true default as of 2026-07-18): the tiledOff() untile below
  // historically used pow2(width) as the macro-row stride, correct ONLY for pow2-width textures.
  // Non-pow2-pitch gameplay textures (e.g. 1280- or 640-wide) untile with the wrong stride and
  // shear into vertical black/green/magenta comb striping. Mirror getTexture()'s proven wallpaper
  // fix: take the sampling draw's fetch-constant pitch (dword_0 bits 22..30, in 32-texel units) as
  // the true macro-row stride via tiledOff's pitchTexels param. This is now the DEFAULT (the value
  // is register-true and already proven on the sibling wallpaper path) — RVK_TEXPITCH=0 restores
  // the legacy pow2(width) stride for A/B.
  static int texPitch = getenv("RVK_TEXPITCH") ? atoi(getenv("RVK_TEXPITCH")) : 1;
  uint32_t fpitch = (texPitch != 0 && tf0 != 0) ? (((tf0 >> 22) & 0x1FFu) << 5) : 0;
  if (fpitch && fpitch < w) fpitch = 0;  // implausible pitch -> distrust the field entirely
  // one-shot per base: log only when the fetch pitch DIFFERS from the pow2 stride the legacy
  // code would have used — these are exactly the textures this lever changes on screen.
  if (fpitch) {
    uint32_t pw2 = w - 1; pw2 |= pw2 >> 1; pw2 |= pw2 >> 2; pw2 |= pw2 >> 4; pw2 |= pw2 >> 8; pw2 |= pw2 >> 16; ++pw2;
    if (fpitch != pw2) {
      static std::unordered_map<uint32_t, int> pitchLogged;
      if (!pitchLogged.count(base)) { pitchLogged[base] = 1;
        std::fprintf(stderr, "[texpitch] base=0x%X %ux%u fmt=%u fetch-pitch=%u (pow2 stride was %u) -- untile corrected\n",
          base, w, h, fmt, fpitch, pw2); }
    }
  }
  // RVK_REALALPHA=1: use the texture's TRUE stored alpha instead of the luminance-key trick
  // (A0 ? A0 : max(RGB)). The trick treats zero-alpha pixels as opaque-if-bright, which is
  // right for luminance-keyed font/HUD atlases (transparent regions are black) but WRONG for
  // the shell title logo/panels whose transparent regions are WHITE -> they became opaque
  // white/coloured boxes. Hardware-true alpha blending just uses the stored A.
  static bool realAlpha = getenv("RVK_REALALPHA") != nullptr;
  // RVK_CYANDBG (2026-07-14): one-shot per base — dump the decoded fmt/dims/tiling of every sampled
  // texture. Distinguishes cyan-tint hypothesis rank2 (is the cave terrain 0x120F7000 fmt6 or a
  // hand-guessed fmt like 26?) from rank1 (resolve dest-swap). Diagnostic only, default off.
  if (std::getenv("RVK_CYANDBG")) {
    static std::unordered_map<uint32_t,int> cyanTexLogged;
    if (!cyanTexLogged.count(base)) { cyanTexLogged[base] = 1;
      std::fprintf(stderr, "[cyandbg][tex] base=0x%X %ux%u fmt=%u %s tf0=0x%X fpitch=%u\n",
        base, w, h, fmt, linear?"LINEAR":"TILED", tf0, fpitch); }
  }
  // RVK_RAWDUMP=0xBASE (portrait-decode RE 2026-07-15): one-shot raw contiguous guest-byte dump of a
  // watched texture base, so the untiling can be brute-forced offline. Diagnostic only, default off.
  if (const char* rd = std::getenv("RVK_RAWDUMP")) {
    uint32_t rb = (uint32_t)std::strtoul(rd, nullptr, 0);
    // rb==1 => AUTO: capture up to 16 distinct fmt3 256x256 portrait bases across the FULL portrait
    // range (0x12000000..0x18100000, matching RVK_ZSCAN) so a whole char-select roster can be decoded
    // offline in one boot and compared clean-vs-striped through the identical tiledOff.
    bool hit = (rb == 1) ? (fmt == 3 && w == 256 && h == 256 && base >= 0x12000000u && base < 0x18100000u)
             : (rb == 2) ? (fmt == 3 && w == 256 && h == 256 && base >= 0x17000000u && base < 0x18100000u)
             : (rb == 3) ? (fmt == 6 && w == 2048)   // FNF-12 seam RE: the 2048x2048 shell logo atlas
                         : (base == rb);
    if (hit) {
      // RVK_RAWDUMP_LEN: capture length override (default 0x60000). The 2048x2048 DXT1 atlas is
      // 2MB; the M2 seam bytes live at ~0x124000, far past the old fixed length.
      static size_t rdLen = [](){ const char* e = std::getenv("RVK_RAWDUMP_LEN");
        return e ? (size_t)std::strtoul(e, nullptr, 0) : (size_t)0x60000u; }();
      static std::unordered_map<uint32_t,int> rdone;
      // rb==3: the FIRST decode races the streaming IO (2026-07-28 proof: both 2048 atlases dumped
      // as 128KB stripe holes mid-load). Capture the Nth decode instead (RVK_RAWDUMP_AT, default
      // 240) — with RVK_REVALFORCE=1 the decode reruns every frame, so N≈240 lands in the M2 hold.
      static int rdAt = [](){ const char* e = std::getenv("RVK_RAWDUMP_AT");
        return e ? std::atoi(e) : 240; }();
      int& rc = rdone[base];
      ++rc;
      bool fire = (rb == 3) ? (rc == rdAt) : (rc == 1 && rdone.size() <= 16);
      if (fire) {
        char nm[128]; std::snprintf(nm, sizeof nm, "/tmp/raw_%08X_%ux%u_f%u_tf%08X_c%d.bin", base, w, h, fmt, tf0, rc);
        FILE* f = std::fopen(nm, "wb");
        if (f) { std::fwrite(g_base + base, 1, rdLen, f); std::fclose(f);
          std::fprintf(stderr, "[rawdump] %s tf0=0x%X (0x%zx bytes)\n", nm, tf0, rdLen); } }
    }
  }
  // ★ RVK_TRIPUV upload-time SNAPSHOT (FNF-7, 2026-07-26, default off): copy the RAW guest bytes
  // of a watched atlas at the exact instant this decode reads them, so a later anomaly frame can
  // compare "what the GPU holds" against "what guest RAM holds now" without a VkImage readback.
  // Re-taken on every pass through this decode (incl. RVK_TEXREVAL3 re-decodes), so the snapshot
  // never goes stale relative to the upload it is standing in for. See rvkCensusRect above.
  if (rvkTripUvLevel() > 0 && fmt == 6 && rvkTripUvWatched(base) && g_base && w && h) {
    RvkAtlasSnap& s = g_tripSnap[base];
    // tiled surfaces address up to the 32-aligned macro extent; pad generously and bound-check.
    size_t need = (size_t)((w + 31u) & ~31u) * ((h + 31u) & ~31u) * 4u + 0x10000u;
    if (s.bytes.size() < need) s.bytes.resize(need);
    std::memcpy(s.bytes.data(), g_base + base, need);
    s.w = w; s.h = h; s.fmt = fmt; s.lb = lb; s.fpitch = fpitch; s.linear = linear ? 1 : 0;
    ++s.uploads;
    // RVK_TRIPUV_POISON=1 (instrument-lie check, default off): flip one bit in every 4096th dword
    // of the SNAPSHOT ONLY (never guest RAM, never the upload — the decode loop below re-reads
    // guest memory, so rendering is untouched). A LIVE-vs-SNAP comparison that cannot report a
    // difference is worthless evidence; with this armed the census MUST come back sigMatch=0 on
    // most rects. Doctrine: an instrument lies until a positive control says otherwise.
    if (std::getenv("RVK_TRIPUV_POISON")) {
      for (size_t pi = 0; pi + 4 <= s.bytes.size(); pi += 16 * 4) s.bytes[pi + 1] ^= 0x40;   // every 16th dword
      std::fprintf(stderr, "[tripuv][snap] base=0x%X SNAPSHOT POISONED (RVK_TRIPUV_POISON) -- expect sigMatch=0\n", base);
    }
    // log the first 50 uploads then every 500th — a watched atlas that RVK_TEXREVAL3 re-decodes
    // constantly cannot be stale at all, and that fact must stay visible without a 100k-line log.
    static long snapLogged = 0;
    bool logIt = (snapLogged < 50) || (snapLogged % 500 == 0); ++snapLogged;
    RvkCensus whole = logIt ? rvkCensusRect(s.bytes.data(), s.bytes.size(), base, w, h, lb, fpitch, linear ? 1 : 0, 0, 0, w, h) : RvkCensus{};
    if (logIt)
    std::fprintf(stderr, "[tripuv][snap] base=0x%X %ux%u fmt=%u lb=%u fpitch=%u linear=%d upload#%ld"
      " whole: n=%u zeroPx=%u rgbBlack=%u opaqueBlack=%u alpha0=%u meanLuma=%.2f sig=0x%08X\n",
      base, w, h, fmt, lb, fpitch, linear ? 1 : 0, s.uploads,
      whole.n, whole.nZeroPx, whole.nRgbBlack, whole.nOpaqueBlack, whole.nAlpha0, whole.meanLuma, whole.sig);
  }
  for (uint32_t y = 0; y < h; ++y) for (uint32_t x = 0; x < w; ++x) {
    uint32_t off = linear ? (uint32_t)(((size_t)y * w + x) << lb) : tiledOff(x, y, w, lb, fpitch);
    uint32_t a = base + off;
    uint8_t R, G, B, A;
    if (fmt == 6) {
      uint32_t px = be32(a);
      uint8_t A0 = (px >> 24) & 0xFF, R0 = (px >> 16) & 0xFF, G0 = (px >> 8) & 0xFF, B0 = px & 0xFF;
      A = realAlpha ? A0 : (A0 ? A0 : (uint8_t)std::max(std::max(R0, G0), B0));
      R = R0; G = G0; B = B0;
    } else if (fmt == 2) {
      uint8_t a8 = *(g_base + a);
      R = G = B = 255; A = a8;
    } else if (fmt == 4) { // Xenos k_4_4_4_4 — see RVK_FMT16TRUE below: guest layout is R4G4B4A4
      uint16_t px = be16(a);
      static const bool fmt16TrueA = std::getenv("RVK_FMT16TRUE") && atoi(std::getenv("RVK_FMT16TRUE")) != 0;
      if (fmt16TrueA) { // ALPHA IN THE LOW NIBBLE (SDK texture_cache: kLoadShaderIndexRGBA4ToBGRA4)
        R = ((px >> 12) & 0xF) * 17; G = ((px >> 8) & 0xF) * 17; B = ((px >> 4) & 0xF) * 17; A = (px & 0xF) * 17;
      } else {          // legacy misread (A4R4G4B4)
        A = ((px >> 12) & 0xF) * 17; R = ((px >> 8) & 0xF) * 17; G = ((px >> 4) & 0xF) * 17; B = (px & 0xF) * 17;
      }
    } else if (fmt == 3) { // Xenos k_1_5_5_5
      uint16_t px = be16(a);
      // RVK_FMT16TRUE (2026-07-18 black-box hunt, DEFAULT OFF — REFUTED, kept as documentation):
      // hypothesis was "1555 alpha = bit 0" from the SDK's R5G5B5A1ToB5G5R5A1 load-shader name.
      // WRONG: DXGI format names list components LSB-first, so guest R5G5B5A1 = R[4:0] G[9:5]
      // B[14:10] A[15] — ALPHA IS BIT 15, as the legacy decode already had. The legacy R/B order
      // (R from [14:10]) is guest-BLUE, but the tf3 fetch swizzle {Z,Y,X,W} (which we ignore)
      // swaps R<->B right back — two swaps cancel, so the legacy decode is NET-CORRECT.
      // Enabling this lever scrambles the demo terrain into magenta noise (bit0 is color data).
      // The sprite black boxes are therefore NOT a texel-format defect — their padding is
      // genuinely opaque black in the data; the divergence from hardware is in the DRAW state
      // (see the boxdbg notes / futari-seg-transform-semantics memory).
      static const bool fmt16True = std::getenv("RVK_FMT16TRUE") && atoi(std::getenv("RVK_FMT16TRUE")) != 0;
      if (fmt16True) {
        R = (uint8_t)((((px >> 11) & 0x1F) << 3) | (((px >> 11) & 0x1F) >> 2));
        G = (uint8_t)((((px >> 6) & 0x1F) << 3) | (((px >> 6) & 0x1F) >> 2));
        B = (uint8_t)((((px >> 1) & 0x1F) << 3) | (((px >> 1) & 0x1F) >> 2));
        A = (px & 1) ? 255 : 0;
      } else {
      R = (uint8_t)((((px >> 10) & 0x1F) << 3) | (((px >> 10) & 0x1F) >> 2));
      G = (uint8_t)((((px >> 5) & 0x1F) << 3) | (((px >> 5) & 0x1F) >> 2));
      B = (uint8_t)(((px & 0x1F) << 3) | ((px & 0x1F) >> 2));
      }
      // RVK_FMT3ALPHA (Round-17 char-select portrait-blackout RE 2026-07-15): the CHARACTER-select big
      // portrait is a vs=48 multi-quad mesh (RECTLIST, ~80 quads, stride-24 {x,y,z=0,color=0xFFFFFFFF,
      // u_norm,v_norm}) binding the fmt-3 (k_1_5_5_5) CHARACTER-PAGE textures in 0x17xxxxxx (0x17A21000,
      // 0x17E92000, 0x17E22000, 0x179AD000, 0x17DB5000, ...) — NOT the 0x12xxxxxx pages (those are the
      // MODE-select art). It renders INTO the 640x512 self-composite atlas 0xF95D000, which the vs=47
      // draw1 composites into the frame's inner window. GEOMETRY IS FINE (BIGSPRITEFIX bsfPhase=-8, clean
      // on-atlas quads); the failure is at the texture sample. This lever tested the alpha hypothesis:
      // 1=luminance alpha (max RGB) even under RVK_REALALPHA, 2=force fully opaque. REFUTED on-window at
      // char-select (subscreen 25): NEITHER value restores the portrait — it stays black. So alpha-bit-0
      // is NOT the (sole) cause; the 0x17xxxxxx portrait pages are mis-UNTILED ("shredded", see the
      // tiledOff/RVK_TILEFIX comb-striping note ~L195) so their RGB is garbage too, and RVK_TILEFIX=1
      // makes it a checkerboard (wrong swizzle), not clean. Root cause = the still-unsolved fmt-3
      // portrait-page untiling. Default 0 = byte-identical; kept as a documented diagnostic.
      static const int fmt3Alpha = std::getenv("RVK_FMT3ALPHA") ? std::atoi(std::getenv("RVK_FMT3ALPHA")) : 0;
      if (!fmt16True)   // legacy alpha path only: the true layout sets A = px bit 0 above
      A = (px & 0x8000) ? 255
        : fmt3Alpha == 2 ? 255
        : fmt3Alpha == 1 ? (uint8_t)std::max(std::max(R, G), B)
        : (realAlpha ? 0 : (uint8_t)std::max(std::max(R, G), B)); // same A-zero trick as fmt 6
      // RVK_FMT3KEY (Round-18 char-portrait RE 2026-07-15): the 0x17xxxxxx char-select portrait/atlas
      // pages UNTILE CLEAN (proven: all 12 pages decode to readable UI/name-labels/portraits via the
      // shipped tiledOff -- the round-17 "shredded untiling" attribution above is REFUTED; fetch consts
      // are byte-identical to the clean 0x12 pages). The real defect: EVERY non-zero texel carries the
      // k_1_5_5_5 alpha bit = 1 (incl. the transparent regions), so the 1-bit alpha can't gate
      // transparency. The game keys transparency on a MAGENTA color (dominant value 0xFC7C: R=0x1F,
      // G<=6, B>=0x1C) via a shader, which our fixed-function upload ignores -> magenta renders as
      // opaque blocks (the on-window char-select "garbage"). This lever discards the magenta key by
      // forcing A=0 on magenta-ish texels. Default 0 = byte-identical.
      // Scoped to the 0x17xxxxxx select-screen portrait/atlas pages so gameplay fmt-3 sprites/bullets
      // (other base ranges) can never be keyed. RVK_FMT3KEY=1 enables; 2 = whole-range (any base).
      // Round-19: DEFAULT ON (=1, 0x17xxxxxx scope). RVK_FMT3KEY=0 forces off (value-checked, not presence).
      // Under RVK_FMT16TRUE the magenta "color key" is unnecessary — those texels carry a real
      // bit-0 alpha of 0 (the key was compensating for the misread alpha bit). Legacy path only.
      static const int fmt3Key = std::getenv("RVK_FMT3KEY") ? std::atoi(std::getenv("RVK_FMT3KEY")) : 1;
      if (!fmt16True && fmt3Key && (fmt3Key == 2 || (base >= 0x17000000u && base < 0x18000000u))) {
        uint32_t r5 = (px >> 10) & 0x1F, g5 = (px >> 5) & 0x1F, b5 = px & 0x1F;
        if (r5 >= 0x1C && b5 >= 0x1C && g5 <= 6) A = 0;   // magenta transparent color-key -> clear
      }
    } else { // fmt == 26, k_16_16_16_16 — top byte of each BE16 channel
      uint8_t c0 = be16(a) >> 8, c1 = be16(a + 2) >> 8, c2 = be16(a + 4) >> 8, c3 = be16(a + 6) >> 8;
      uint8_t A0;
      switch (f26ord) {
        case 1:  A0 = c0; R = c1; G = c2; B = c3; break; // ARGB (fmt6-analog)
        case 2:  A0 = c0; B = c1; G = c2; R = c3; break; // ABGR
        case 3:  B = c0; G = c1; R = c2; A0 = c3; break; // BGRA
        default: R = c0; G = c1; B = c2; A0 = c3; break; // RGBA (Xenos natural)
      }
      A = realAlpha ? A0 : (A0 ? A0 : (uint8_t)std::max(std::max(R, G), B));
    }
    uint8_t* o = dst + ((size_t)y * w + x) * 4; o[0] = R; o[1] = G; o[2] = B; o[3] = A;
  }
  // ★ RVK_TEXRECT=<hexbase>,<x0>,<y0>,<x1>,<y1> (2026-08-01) — THE RANKING-SHADOW DECISIVE TEST.
  //
  // The ranking-plaque shadow class is vs=45 ps=50 tex=0x134E8000, blend 0x05000500 = src ZERO /
  // dst ONE_MINUS_SRC_COLOR, i.e. dst *= (1 - src.rgb). Under that blend ALPHA IS NEVER READ: a
  // texel with alpha 0 still darkens the destination if its RGB is non-zero. The ROM's working
  // sprite class uses the same shader pair, same vte=0x400 and the same texel-UV convention but
  // an ordinary alpha blend, where those same texels contribute nothing. That asymmetry is the
  // one surviving explanation for "exactly one blend class renders as a solid square".
  //
  // ⚠ THE TRAP THIS INSTRUMENT EXISTS TO AVOID. `realAlpha` above defaults OFF, so for fmt 3 the
  // decode is A = (px & 0x8000) ? 255 : max(R,G,B) — decoded A is zero ONLY when RGB is already
  // zero. Asking "is RGB zero wherever A is zero" of the DECODED buffer is therefore a tautology
  // that always answers yes and would kill the hypothesis on a measurement artifact. So this dump
  // reads the RAW guest alpha (the stored bit/byte, per format) and reports it separately from the
  // decoded A. The two columns disagreeing IS the finding, not a bug in the dump.
  //
  // Fires on log-spaced decodes (1,4,16,64) because the first decode of a CPU-streamed atlas can
  // race the load (the RVK_RAWDUMP_AT lesson) — if the four agree, streaming is not in play.
  // Default off => byte-identical.
  {
    static const char* trEnv = std::getenv("RVK_TEXRECT");
    static uint32_t trBase = 0, trX0 = 0, trY0 = 0, trX1 = 0, trY1 = 0;
    static bool trOk = [&]() {
      if (!trEnv) return false;
      unsigned b = 0, a0 = 0, c0 = 0, a1 = 0, c1 = 0;
      if (std::sscanf(trEnv, "%x,%u,%u,%u,%u", &b, &a0, &c0, &a1, &c1) != 5) {
        std::fprintf(stderr, "[shtex] RVK_TEXRECT malformed (want <hexbase>,x0,y0,x1,y1): %s\n", trEnv);
        return false;
      }
      trBase = b; trX0 = a0; trY0 = c0; trX1 = a1; trY1 = c1;
      return true;
    }();
    // Two ways in: the explicit env rect, or the draw-class auto-request set by the nvk draw loop.
    const bool trHit = trOk && base == trBase;
    const bool reqHit = !trHit && g_shtexReq.base && base == g_shtexReq.base;
    if ((trHit || reqHit) && w && h) {
      static std::unordered_map<uint32_t, long> trSeen;
      long dn = ++trSeen[base];
      if (dn == 1 || dn == 4 || dn == 16 || dn == 64) {
        const uint32_t rx0 = trHit ? trX0 : g_shtexReq.x0, ry0 = trHit ? trY0 : g_shtexReq.y0;
        const uint32_t rx1 = trHit ? trX1 : g_shtexReq.x1, ry1 = trHit ? trY1 : g_shtexReq.y1;
        uint32_t x0 = rx0 < w ? rx0 : w, y0 = ry0 < h ? ry0 : h;
        uint32_t x1 = rx1 < w ? rx1 : w, y1 = ry1 < h ? ry1 : h;
        std::fprintf(stderr,
          "[shtex] base=0x%X %ux%u fmt=%u lb=%u fpitch=%u %s realAlpha=%d decode#%ld rect=[%u,%u..%u,%u]\n",
          base, w, h, fmt, lb, fpitch, linear ? "LINEAR" : "TILED", realAlpha ? 1 : 0, dn, x0, y0, x1, y1);
        if (x1 > x0 && y1 > y0) {
          uint32_t n = 0, nRawA0 = 0, nRawA0RgbNZ = 0, nRawANZ = 0, nRawANZRgbZ = 0, nDecA0 = 0;
          uint32_t maxRgbAtRawA0 = 0; double sumRgbAtRawA0 = 0.0;
          std::unordered_map<uint32_t, uint32_t> hist;
          uint32_t rw = x1 - x0, rh = y1 - y0;
          std::vector<uint8_t> crop((size_t)rw * rh * 4, 0);
          std::vector<char> cls((size_t)rw * rh, ' ');
          for (uint32_t y = y0; y < y1; ++y) for (uint32_t x = x0; x < x1; ++x) {
            uint32_t off = linear ? (uint32_t)(((size_t)y * w + x) << lb) : tiledOff(x, y, w, lb, fpitch);
            uint32_t a = base + off;
            // RAW stored alpha, straight from the guest bytes, per texel format. No decode policy.
            uint32_t raw = 0, rawA = 0;
            if (fmt == 6)       { raw = be32(a);            rawA = (raw >> 24) & 0xFF; }
            else if (fmt == 2)  { raw = *(g_base + a);      rawA = raw; }
            else if (fmt == 4)  { raw = be16(a);            rawA = (raw >> 12) & 0xF; }   // legacy A4R4G4B4 read
            else if (fmt == 3)  { raw = be16(a);            rawA = (raw & 0x8000) ? 1 : 0; }
            else                { raw = be16(a);            rawA = be16(a + 6) >> 8; }    // fmt26, RGBA order
            const uint8_t* o = dst + ((size_t)y * w + x) * 4;
            uint32_t rgbMax = std::max(std::max(o[0], o[1]), o[2]);
            ++n;
            if (hist.size() < 4096) ++hist[raw];
            size_t ci = (size_t)(y - y0) * rw + (x - x0);
            std::memcpy(&crop[ci * 4], o, 4);
            if (o[3] == 0) ++nDecA0;
            if (rawA == 0) {
              ++nRawA0;
              sumRgbAtRawA0 += rgbMax;
              if (rgbMax > maxRgbAtRawA0) maxRgbAtRawA0 = rgbMax;
              if (rgbMax) { ++nRawA0RgbNZ; cls[ci] = (rgbMax >= 32) ? '!' : '+'; }
              else cls[ci] = '.';
            } else {
              ++nRawANZ;
              if (!rgbMax) { ++nRawANZRgbZ; cls[ci] = 'o'; } else cls[ci] = '#';
            }
          }
          // THE DECISIVE LINE. nRawA0RgbNZ > 0 => transparent texels carry colour => under
          // dst *= (1-src.rgb) the whole quad darkens => square shadow. == 0 => hypothesis dead.
          std::fprintf(stderr,
            "[shtex] DECISIVE n=%u rawA0=%u rawA0_rgbNONZERO=%u (%.2f%% of rawA0) rawA0_maxRGB=%u "
            "rawA0_meanRGB=%.2f | rawAnz=%u rawAnz_rgbZero=%u | decodedA0=%u\n",
            n, nRawA0, nRawA0RgbNZ, nRawA0 ? 100.0 * nRawA0RgbNZ / nRawA0 : 0.0,
            maxRgbAtRawA0, nRawA0 ? sumRgbAtRawA0 / nRawA0 : 0.0, nRawANZ, nRawANZRgbZ, nDecA0);
          // What the blend would actually do to the destination across the transparent region.
          if (nRawA0)
            std::fprintf(stderr, "[shtex] blend impact over rawA0 texels: mean dst multiplier "
                                 "(1 - meanRGB/255) = %.4f  (1.0 = invisible, <1 = darkens)\n",
                         1.0 - (sumRgbAtRawA0 / nRawA0) / 255.0);
          // Top raw values — an all-one-value region says "constant fill", a spread says "art".
          {
            std::vector<std::pair<uint32_t, uint32_t>> hv(hist.begin(), hist.end());
            std::sort(hv.begin(), hv.end(), [](const std::pair<uint32_t,uint32_t>& a,
                                               const std::pair<uint32_t,uint32_t>& b) { return a.second > b.second; });
            std::fprintf(stderr, "[shtex] raw-value histogram (%zu distinct), top 8:", hv.size());
            for (size_t i = 0; i < hv.size() && i < 8; ++i)
              std::fprintf(stderr, "  0x%04X x%u", hv[i].first, hv[i].second);
            std::fprintf(stderr, "\n");
          }
          // Shape map: '.' rawA=0 rgb=0 (clean transparent)  '+' rawA=0 rgb<32  '!' rawA=0 rgb>=32
          //            'o' rawA!=0 rgb=0 (opaque black)      '#' rawA!=0 rgb!=0 (sprite body)
          // A field of '!' over the whole rect IS the square shadow, drawn in the source data.
          {
            uint32_t ys = (rh + 39) / 40, xs = (rw + 111) / 112;
            if (!ys) ys = 1; if (!xs) xs = 1;
            std::fprintf(stderr, "[shtex] shape map (x step %u, y step %u; '.'=clear '+'=dim '!'=LIT "
                                 "'o'=opaqueBlack '#'=sprite):\n", xs, ys);
            for (uint32_t y = 0; y < rh; y += ys) {
              char line[160]; uint32_t li = 0;
              for (uint32_t x = 0; x < rw && li < sizeof(line) - 1; x += xs) line[li++] = cls[(size_t)y * rw + x];
              line[li] = 0;
              std::fprintf(stderr, "[shtex]   %3u |%s|\n", y0 + y, line);
            }
          }
          char nm[192];
          std::snprintf(nm, sizeof nm, "/tmp/shtex_%08X_%u_%u_%u_%u_d%ld.png", base, x0, y0, x1, y1, dn);
          writePng(nm, crop.data(), rw, rh);
          // Same crop with alpha forced opaque: this is literally what the modulate blend sees,
          // because it reads src.rgb and ignores src.a entirely.
          for (size_t i = 0; i < (size_t)rw * rh; ++i) crop[i * 4 + 3] = 255;
          char nm2[192];
          std::snprintf(nm2, sizeof nm2, "/tmp/shtex_%08X_%u_%u_%u_%u_d%ld_RGBONLY.png", base, x0, y0, x1, y1, dn);
          writePng(nm2, crop.data(), rw, rh);
          std::fprintf(stderr, "[shtex] wrote %s and %s\n", nm, nm2);
        }
      }
    }
  }
  // RVK_DUMPTEXBASE=<hex guest addr> (s2B leg 5): dump EVERY decode of one named base,
  // counter-stamped — the once-per-base RVK_DUMPTEX only ever shows the FIRST decode, which for
  // CPU-streamed textures is the fade-in window. Pair with RT_NVKFRESH2 to sample the timeline.
  {
    static const char* dumpBaseEnv = getenv("RVK_DUMPTEXBASE");
    if (dumpBaseEnv) {
      static uint32_t wantBase = (uint32_t)strtoul(dumpBaseEnv, nullptr, 16);
      if (base == wantBase) {
        static int dn = 0;
        if (dn < 40) {
          char nm[160]; std::snprintf(nm, sizeof nm, "/tmp/texbase_%08X_%02d.png", base, dn++);
          writePng(nm, dst, w, h);
          std::fprintf(stderr, "[rvk] dumped watched base -> %s\n", nm);
        }
      }
    }
  }
  static bool dumpTex = getenv("RVK_DUMPTEX") != nullptr;
  if (dumpTex) {
    static uint32_t dumpedBases[400]; static int nDumped = 0; bool seen = false;
    for (int i = 0; i < nDumped; ++i) if (dumpedBases[i] == base) { seen = true; break; }
    if (!seen && nDumped < 400) { dumpedBases[nDumped++] = base;
      char nm[160]; std::snprintf(nm, sizeof nm, "/tmp/tex_%08X_%ux%u_f%u.png", base, w, h, fmt);
      writePng(nm, dst, w, h);
      std::fprintf(stderr, "[rvk] dumped texture %s\n", nm);
    }
  }
  // RVK_ALPHACENSUS=1 (2026-07-18 round 2): one line per fmt-3 base at decode — tally the raw
  // guest texel population: nOpaqueBlack (0x8000), nTranspBlack (0x0000), nOther, bit15-set frac.
  // Distinguishes pages whose black is genuinely opaque (bit15=1) from transparent padding.
  {
    static const bool alphaCensus = std::getenv("RVK_ALPHACENSUS") && atoi(std::getenv("RVK_ALPHACENSUS")) != 0;
    if (alphaCensus && fmt == 3 && lb == 1) {
      static std::set<uint32_t> censusDone;
      if (censusDone.size() < 200 && censusDone.insert(base).second) {
        uint32_t nOB = 0, nTB = 0, nOther = 0, nB15 = 0, tot = 0;
        for (uint32_t y = 0; y < h; y += 2) for (uint32_t x = 0; x < w; x += 2) {   // quarter sample
          uint32_t off = linear ? (uint32_t)(((size_t)y * w + x) << lb) : tiledOff(x, y, w, lb, fpitch);
          uint16_t px = be16(base + off);
          ++tot;
          if (px == 0x8000) ++nOB; else if (px == 0x0000) ++nTB; else ++nOther;
          if (px & 0x8000) ++nB15;
        }
        std::fprintf(stderr, "[alphacensus] base=0x%X %ux%u opaqueBlack=%.2f transpBlack=%.2f other=%.2f bit15set=%.2f\n",
          base, w, h, (double)nOB/tot, (double)nTB/tot, (double)nOther/tot, (double)nB15/tot);
      }
    }
  }
  // RVK_RAWTEXEL=<hexbase> (2026-07-18 black-box hunt round 2): one-shot — print the RAW guest
  // 16-bit texel values (be16, i.e. big-endian as stored) at known probe coords of the named
  // atlas, so the oracle's per-texel alpha (padding=0 vs digit-shadow=1) can be compared against
  // the actual guest bits. Uses the SAME addressing (linear/tiled) the decode above used.
  {
    static const uint32_t rawTexelBase = std::getenv("RVK_RAWTEXEL")
        ? (uint32_t)std::strtoul(std::getenv("RVK_RAWTEXEL"), nullptr, 16) : 0u;
    static bool rawTexelDone = false;
    if (rawTexelBase && base == rawTexelBase && !rawTexelDone && lb == 1) {
      rawTexelDone = true;
      static const struct { const char* nm; uint32_t x, y; } P[] = {
        {"padding_between_orbs", 16, 40}, {"digit_shadow", 216, 2}, {"grey_left_of_card", 60, 200},
        {"uv0_box", 80, 144}, {"padding_right_pad", 250, 120}, {"inside_cave_card", 130, 200},
        {"padding_below_digits", 200, 30}};
      for (auto& p : P) {
        uint32_t off = linear ? (uint32_t)(((size_t)p.y * w + p.x) << lb) : tiledOff(p.x, p.y, w, lb, fpitch);
        uint16_t px = be16(base + off);
        std::fprintf(stderr, "[rawtexel] base=0x%X (%s) (%u,%u) linear=%d be16=0x%04X bit15=%d rgb555=(%u,%u,%u) bit0=%d\n",
          base, p.nm, p.x, p.y, (int)linear, px, (px >> 15) & 1,
          (px >> 10) & 0x1F, (px >> 5) & 0x1F, px & 0x1F, px & 1);
      }
    }
  }
  // RVK_REVAL3DUMP=1 (2026-07-31 HI stream-page probe): dump the DECODED page on every reval3
  // re-decode (cap 12 per base) — discriminates torn-decode vs fill-frontier vs stale-generation
  // by watching the decoded content evolve. Diagnostic only, default off.
  { static const bool r3dump = std::getenv("RVK_REVAL3DUMP") && atoi(std::getenv("RVK_REVAL3DUMP")) != 0;
    if (r3dump && reval3ReuseIdx >= 0) {
      static std::unordered_map<uint32_t, int> dumped;
      int& n = dumped[base];
      if (n < 12) { char nm[128];
        std::snprintf(nm, sizeof nm, "/tmp/reval3_%08X_n%02d.png", base, n++);
        writePng(nm, (const uint8_t*)g.stagingMap, w, h);
        std::fprintf(stderr, "[reval3dump] %s\n", nm); } } }
  RTex t{};
  if (!uploadTexToBindless(w, h, t)) return 0;
  uint32_t idx;
  if (reval3ReuseIdx >= 0 && (uint32_t)reval3ReuseIdx < g.rTexRecords.size()) {
    // RVK_TEXREVAL3 re-decode: reuse the SAME bindless array element so draws that already picked
    // up this index (they re-query getTexIndexReal every frame, but the descriptor slot is what
    // the GPU actually samples) see the refreshed content without any renumbering. The old RTex's
    // image/view/mem are intentionally left allocated rather than vkDestroy'd -- this file never
    // destroys bindless GPU resources mid-session (see uploadTexToBindless's "append-only" leak-
    // census note above); the array element is what must stay stable, and this leak is bounded by
    // the number of textures that genuinely change content over a session, not by elapsed frames.
    idx = (uint32_t)reval3ReuseIdx;
    g.rTexRecords[idx] = t;
  } else {
    idx = rvkBindlessAlloc("tex");
    if (idx == 0) {
      // RVK_BINDFIX: the array is full -- drop this upload (fence-waited, nothing references it) and
      // cache the miss, so the draw samples the white at slot 0 instead of re-uploading every frame
      vkDestroyImageView(g.dev, t.view, nullptr); vkDestroyImage(g.dev, t.image, nullptr); vkFreeMemory(g.dev, t.mem, nullptr);
      g.rTexIndex[key] = 0;
      return 0;
    }
    g.rTexRecords.push_back(t);
  }
  VkDescriptorImageInfo dii{VK_NULL_HANDLE, t.view, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL};
  VkWriteDescriptorSet wr{VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET};
  wr.dstSet = g.rSets[0]; wr.dstBinding = 0; wr.dstArrayElement = idx; wr.descriptorCount = 1;
  wr.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE; wr.pImageInfo = &dii;
  vkUpdateDescriptorSets(g.dev, 1, &wr, 0, nullptr);
  rvkSlotRegister(idx, t, key, false);   // RVK_BINDFIX part 2: collectable from here on
  g.rTexIndex[key] = idx;
  if (base) g_texEpoch[key] = rt_mem_epoch(base, w * h * 4u);   // decode-time identity — always
  // recorded (one map write per upload) so the epoch invalidator above has a baseline; was
  // RVK_IDLOG-gated when the mechanism was detector-only (08-07 -> 08-11).

  if (texReval2 && (fmt == 3 || fmt == 4 || fmt == 6) && w >= 32 && h >= 32 && base && g_base)
    revalSig[key] = revalHash();   // record content signature at this decode for later revalidation
  return idx;
}

// upload a linear RGBA8 buffer (already in g.stagingMap) to a fresh sampled texture + descriptor set
// (PASSTHROUGH path — unchanged)
bool uploadTexToDesc(uint32_t w, uint32_t h, Tex& out) {
  VkImageCreateInfo ii{VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO}; ii.imageType = VK_IMAGE_TYPE_2D; ii.format = VK_FORMAT_R8G8B8A8_UNORM;
  ii.extent = {w, h, 1}; ii.mipLevels = 1; ii.arrayLayers = 1; ii.samples = VK_SAMPLE_COUNT_1_BIT; ii.tiling = VK_IMAGE_TILING_OPTIMAL;
  // TRANSFER_SRC added 2026-07-17: g_wallTex (RVK_WALLBG=4) is blitted FROM as the border bg —
  // missing usage was validation-UB (VUID-vkCmdBlitImage-srcImage-00219), device-lost under the
  // async worker's concurrent submissions.
  ii.usage = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_SAMPLED_BIT; ii.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
  VKC(vkCreateImage(g.dev, &ii, nullptr, &out.image), "vkCreateImage(tex)");
  VkMemoryRequirements mr{}; vkGetImageMemoryRequirements(g.dev, out.image, &mr);
  VkMemoryAllocateInfo ai{VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO}; ai.allocationSize = mr.size; ai.memoryTypeIndex = findMem(mr.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
  VKC(vkAllocateMemory(g.dev, &ai, nullptr, &out.mem), "vkAllocateMemory(tex)");
  VKC(vkBindImageMemory(g.dev, out.image, out.mem, 0), "vkBindImageMemory(tex)");

  // one-shot upload command
  segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
  rvkRingNext("upl"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(upl)");
  VkCommandBufferBeginInfo bi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; bi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
  VKC(vkBeginCommandBuffer(g.cmd, &bi), "begin(upl)");
  VkImageMemoryBarrier b1{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; b1.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED; b1.newLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
  b1.srcQueueFamilyIndex = b1.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED; b1.image = out.image; b1.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  b1.srcAccessMask = 0; b1.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
  vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b1);
  VkBufferImageCopy cp{}; cp.imageSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; cp.imageExtent = {w, h, 1};
  vkCmdCopyBufferToImage(g.cmd, g.staging, out.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &cp);
  VkImageMemoryBarrier b2 = b1; b2.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL; b2.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
  b2.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT; b2.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
  vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b2);
  VKC(vkEndCommandBuffer(g.cmd), "end(upl)");
  VkSubmitInfo subi{VK_STRUCTURE_TYPE_SUBMIT_INFO}; subi.commandBufferCount = 1; subi.pCommandBuffers = &g.cmd;
  VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(upl)");
  VKC(rvkQueueSubmit(g.queue, 1, &subi, g.fence), "submit(upl)");
  VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 5000000000ull), "wait(upl)");

  VkImageViewCreateInfo iv{VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO}; iv.image = out.image; iv.viewType = VK_IMAGE_VIEW_TYPE_2D; iv.format = VK_FORMAT_R8G8B8A8_UNORM;
  iv.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  VKC(vkCreateImageView(g.dev, &iv, nullptr, &out.view), "vkCreateImageView(tex)");
  VkDescriptorSetAllocateInfo da{VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO}; da.descriptorPool = g.descPool; da.descriptorSetCount = 1; da.pSetLayouts = &g.dsl;
  VKC(vkAllocateDescriptorSets(g.dev, &da, &out.set), "allocDescSet");
  VkDescriptorImageInfo dii{g.sampler, out.view, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL};
  VkWriteDescriptorSet wr{VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET}; wr.dstSet = out.set; wr.dstBinding = 0; wr.descriptorCount = 1; wr.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER; wr.pImageInfo = &dii;
  vkUpdateDescriptorSets(g.dev, 1, &wr, 0, nullptr);
  return true;
}

// Get (cache) a GPU texture for a guest tiled k_8_8_8_8 texture; returns its descriptor set.
// (PASSTHROUGH path — unchanged)
// tf0: the texture fetch-constant's dword_0, when the caller has it (hookrender passes
// RvkHookDraw.tf[0]; 0 = unknown => keep the historical always-untile behavior). Per the Xenos
// fetch-constant layout (xe_gpu_texture_fetch_t): bit 31 = tiled, bits 22..30 = row pitch in
// 32-texel units — used by RVK_HKTILEFLAG below.
VkDescriptorSet getTexture(uint32_t base, uint32_t w, uint32_t h, uint32_t fmt, uint32_t tf0 = 0) {
  // RT_COMPOSE (2026-07-13, gameplay-composition pivot): if this base was written by an emulated
  // RB_COPY resolve, sample the RENDERED resolve image — NOT guest RAM (which holds nothing our
  // decode understands). This is the hook-path mirror of getTexIndexReal's resolve check (its very
  // first lookup), and it is what textures the shell's own gameplay composite: the playfield-window
  // RECTLIST quad (e.g. 0xEEAD000 640x512) and the 320x240 wallpaper-transform ring, both PROVEN
  // via RT_COMPOSEPROBE tex-base == "[rvk][resolve] target dst=" matches. Checked before the
  // fmt/dims gate on purpose: base identity is the authority for resolve sampling. Only ever hits
  // when the legacy decoder has populated g_resolveTex (compose/hybrid runs) — pure-hookrender
  // menu runs have an empty map, so their behavior is untouched.
  { auto rit = g_resolveTex.find(base);
    if (rit != g_resolveTex.end() && rit->second.image) {
      ResolveTex& rt = rit->second;
      if (!rt.hkSet) {
        VkDescriptorSetAllocateInfo da{VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO};
        da.descriptorPool = g.descPool; da.descriptorSetCount = 1; da.pSetLayouts = &g.dsl;
        if (vkAllocateDescriptorSets(g.dev, &da, &rt.hkSet) == VK_SUCCESS) {
          VkDescriptorImageInfo dii{g.sampler, rt.view, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL};
          VkWriteDescriptorSet wr{VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET};
          wr.dstSet = rt.hkSet; wr.dstBinding = 0; wr.descriptorCount = 1;
          wr.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER; wr.pImageInfo = &dii;
          vkUpdateDescriptorSets(g.dev, 1, &wr, 0, nullptr);
          std::fprintf(stderr, "[rvk][compose] hook-path resolve sample base=0x%X %ux%u (idx %u)\n", base, rt.w, rt.h, rt.idx);
        } else { rt.hkSet = VK_NULL_HANDLE; return g.white.set; }
      }
      return rt.hkSet;
    } }
  // ★ FNF-1 (2026-07-27), same rule as getTexIndexReal above: a fetch constant not TYPED as a
  // texture (tf0 bits[1:0] != 2 = kTexture) must not sample WHITE — the blob window's remaining
  // white mass came through THIS path (legacy caller now passes tf[0]). Transparent black; the
  // pre-bind transient becomes invisible, matching the SDK oracle. tf0==0 keeps old behaviour
  // (callers that pass no tf0 stay byte-identical). Shares the RVK_NOTYPEBLACK revert lever.
  {
    static bool typeBlackOff2 = std::getenv("RVK_NOTYPEBLACK") && atoi(std::getenv("RVK_NOTYPEBLACK")) != 0;
    if (!typeBlackOff2 && tf0 != 0 && (tf0 & 3u) != 2u) {
      if (!g.black.set) {
        ((uint32_t*)g.stagingMap)[0] = 0x00000000u;
        if (uploadTexToDesc(1, 1, g.black))
          std::fprintf(stderr, "[rvk][fnf1] non-texture fetch constant (type=%u) -> transparent-black desc (legacy/hook path)\n", tf0 & 3u);
      }
      if (g.black.set) return g.black.set;
    }
  }
  if (!base || fmt != 6 || w == 0 || h == 0 || w > 2048 || h > 2048) return g.white.set;
  // RVK_HKTILEFLAG (2026-07-13, wallpaper banding root cause): this path historically untiled
  // EVERY texture (tiledOff below), which is correct for the render-generated shell atlases but
  // scrambles LINEAR textures into the horizontal-band/checkerboard mess seen on the menu
  // wallpaper — wp01.bin is PROVEN linear (the file body decodes as clean row-major 1280x720
  // ARGB, /c/tmp/wp01_linear.png, and the RVK_DUMPTEX of the untile decode reproduces the
  // on-screen scramble exactly). Honor the fetch constant's own tiled bit instead: dword_0
  // bit 31 = tiled, bits 22..30 = linear row pitch in 32-texel units. NOTE the older legacy-path
  // comment ("bit30 turned out NOT to be a reliable tiled flag", getTexIndexReal above) tested
  // bit THIRTY — the top bit of the pitch field — not bit 31, so it does not contradict this.
  // Default tracks RT_WALLPAPER (same regression bar as RT_HKRECTLIST: RT_WALLPAPER off must stay
  // byte-identical); RVK_HKTILEFLAG=0/1 overrides explicitly for A/B.
  static bool wallpaperOn = getenv("RT_WALLPAPER") != nullptr;
  static int tileFlagMode = getenv("RVK_HKTILEFLAG") ? atoi(getenv("RVK_HKTILEFLAG")) : (wallpaperOn ? 1 : 0);
  bool linearTex = tileFlagMode == 1 && tf0 != 0 && !(tf0 >> 31);
  // fpitch: the fetch constant's true row pitch, used BOTH as the linear row stride and as the
  // tiled macro-row stride (see tiledOff's pitchTexels note -- pow2(width) is wrong for non-pow2
  // pitches like the 1280-wide wallpaper). RANK 6 (2026-07-18): aligned with getTexIndexReal's
  // RVK_TEXPITCH default-on fix — the pitch value now comes from RVK_TEXPITCH (default on)
  // independent of RVK_HKTILEFLAG/RT_WALLPAPER, which only gate the separate tiled-vs-linear
  // DECISION below (its own regression bar). RVK_TEXPITCH=0 restores the legacy pow2/width stride.
  static int texPitchHk = getenv("RVK_TEXPITCH") ? atoi(getenv("RVK_TEXPITCH")) : 1;
  uint32_t fpitch = (texPitchHk != 0 && tf0 != 0) ? (((tf0 >> 22) & 0x1FFu) << 5) : 0;
  if (fpitch && fpitch < w) fpitch = 0;  // implausible pitch -> distrust the field entirely
  uint32_t pitch = fpitch ? fpitch : w;
  // RVK_TEXREVALIDATE (2026-07-12, default OFF): the cache below is keyed ONLY on guest base
  // address, with zero invalidation. Hypothesis: an asset that is still being asynchronously
  // streamed in (RT_ASYNCIO) gets its FIRST draw's texture cached (possibly blank/incomplete
  // bytes) at that address, and every later draw at the same address is served the stale GPU
  // copy forever -- even after the real bytes finish loading, or even if a DIFFERENT asset
  // later reuses the same guest address (streaming pool reuse). Symptom under investigation:
  // Windows menu chrome (panel backgrounds) render as flat white/gray boxes instead of their
  // real dark/gold texture, while the game-select card art (loaded once, early, never revisited)
  // renders fine. This lever re-validates dims/fmt + a cheap corner-texel signature on every
  // cache HIT and re-uploads on mismatch, instead of trusting the cache unconditionally.
  static bool revalidate = getenv("RVK_TEXREVALIDATE") != nullptr;
  auto it = g.texCache.find(base);
  if (it != g.texCache.end()) {
    if (!revalidate) return it->second.set;
    uint32_t sig = texSignature(base, w, h);
    if (it->second.w == w && it->second.h == h && it->second.fmt == fmt && it->second.sig == sig)
      return it->second.set;
    static bool dbg = getenv("RVK_TEXREVALIDATE_DBG") != nullptr;
    if (dbg) std::fprintf(stderr, "[texreval] base=0x%X STALE was=%ux%u fmt=%u sig=0x%X now=%ux%u fmt=%u sig=0x%X -- reuploading\n",
      base, it->second.w, it->second.h, it->second.fmt, it->second.sig, w, h, fmt, sig);
    // fall through: re-upload and replace the cache entry below. (Old image/view/descriptor
    // set is intentionally leaked -- the descriptor pool has no FREE_DESCRIPTOR_SET_BIT, and
    // this is a default-off diagnostic lever for a short menu session, not a steady-state path.)
  }
  // untile guest k_8_8_8_8 (ARGB be dword) into linear RGBA8 in the staging buffer
  uint8_t* dst = (uint8_t*)g.stagingMap;
  // RVK_REALALPHA: use the texture's TRUE stored alpha. The luminance-key trick (A?A:max(RGB))
  // treats zero-alpha bright pixels as OPAQUE — right for luminance-keyed HUD atlases, but the
  // shell/menu atlases store transparent regions as WHITE with A=0, so the trick paints the whole
  // menu (incl. the full-screen background quad) OPAQUE WHITE. Honor realAlpha here as the other path does.
  static bool realAlphaP = getenv("RVK_REALALPHA") != nullptr;
  uint64_t sumR = 0, sumA = 0; uint32_t nOpaqueTrick = 0;
  { static std::unordered_map<uint32_t, int> upLogged;   // one line per unique base at upload time
    if (!upLogged.count(base)) { upLogged[base] = 1;
      std::fprintf(stderr, "[gettex] upload base=0x%X %ux%u tf0=0x%08X tiled=%u pitch=%u -> %s\n",
        base, w, h, tf0, (unsigned)(tf0 >> 31), pitch, linearTex ? "LINEAR" : "untile"); } }
  for (uint32_t y = 0; y < h; ++y) for (uint32_t x = 0; x < w; ++x) {
    uint32_t px = be32(base + (linearTex ? ((y * pitch + x) << 2) : tiledOff(x, y, w, 2, fpitch)));  // tiledOff already includes the 32bpp byte scale
    uint8_t A = (px >> 24) & 0xFF, R = (px >> 16) & 0xFF, G = (px >> 8) & 0xFF, B = px & 0xFF;
    uint8_t a = realAlphaP ? A : (A ? A : (uint8_t)std::max(std::max(R, G), B));  // realAlpha => true stored A
    if (!A && a) ++nOpaqueTrick;
    sumR += R; sumA += a;
    uint8_t* o = dst + ((size_t)y * w + x) * 4; o[0] = R; o[1] = G; o[2] = B; o[3] = a;
  }
  static bool dumpTexP = getenv("RVK_DUMPTEX") != nullptr;
  if (dumpTexP) {
    std::fprintf(stderr, "[gettex] base=0x%X %ux%u meanR=%.1f meanA=%.1f opaqueTrick=%u/%u\n",
      base, w, h, (double)sumR/((double)w*h), (double)sumA/((double)w*h), nOpaqueTrick, w*h);
    char nm[160]; std::snprintf(nm, sizeof nm, "/tmp/hktex_%08X_%ux%u.png", base, w, h);
    writePng(nm, dst, w, h);
  }
  Tex t{};
  if (!uploadTexToDesc(w, h, t)) return g.white.set;
  t.w = w; t.h = h; t.fmt = fmt;
  if (revalidate) t.sig = texSignature(base, w, h);
  g.texCache[base] = t;
  return t.set;
}

// ---------- self-contained PNG (stored deflate) ----------
uint32_t crc32_(const uint8_t* d, size_t n, uint32_t crc) {
  static uint32_t T[256]; static bool init = false;
  if (!init) { for (uint32_t i = 0; i < 256; ++i) { uint32_t c = i; for (int k = 0; k < 8; ++k) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1); T[i] = c; } init = true; }
  for (size_t i = 0; i < n; ++i) crc = T[(crc ^ d[i]) & 0xFF] ^ (crc >> 8); return crc;
}
void put32(std::vector<uint8_t>& o, uint32_t v) { o.push_back(v >> 24); o.push_back(v >> 16); o.push_back(v >> 8); o.push_back(v); }
void chunk(std::vector<uint8_t>& o, const char* t, const uint8_t* d, size_t n) {
  put32(o, (uint32_t)n); size_t at = o.size(); o.insert(o.end(), t, t + 4); o.insert(o.end(), d, d + n);
  put32(o, crc32_(&o[at], 4 + n, 0xFFFFFFFFu) ^ 0xFFFFFFFFu);
}
static void writePngSync(const char* path, const uint8_t* rgba, uint32_t w, uint32_t h) {
  std::vector<uint8_t> raw; raw.reserve((size_t)h * (1 + w * 3));
  for (uint32_t y = 0; y < h; ++y) { raw.push_back(0); const uint8_t* row = rgba + (size_t)y * w * 4;
    for (uint32_t x = 0; x < w; ++x) { raw.push_back(row[x*4]); raw.push_back(row[x*4+1]); raw.push_back(row[x*4+2]); } }
  std::vector<uint8_t> z; z.push_back(0x78); z.push_back(0x01); size_t off = 0;
  while (off < raw.size()) { size_t blk = raw.size() - off; if (blk > 65535) blk = 65535; bool last = (off + blk == raw.size());
    z.push_back(last ? 1 : 0); z.push_back(blk & 0xFF); z.push_back((blk >> 8) & 0xFF); z.push_back(~blk & 0xFF); z.push_back((~blk >> 8) & 0xFF);
    z.insert(z.end(), raw.begin() + off, raw.begin() + off + blk); off += blk; }
  uint32_t a = 1, b = 0; for (uint8_t v : raw) { a = (a + v) % 65521; b = (b + a) % 65521; } put32(z, (b << 16) | a);
  std::vector<uint8_t> png = {0x89,'P','N','G',0x0D,0x0A,0x1A,0x0A};
  uint8_t ihdr[13] = {(uint8_t)(w>>24),(uint8_t)(w>>16),(uint8_t)(w>>8),(uint8_t)w,(uint8_t)(h>>24),(uint8_t)(h>>16),(uint8_t)(h>>8),(uint8_t)h,8,2,0,0,0};
  chunk(png, "IHDR", ihdr, 13); chunk(png, "IDAT", z.data(), z.size()); chunk(png, "IEND", nullptr, 0);
  FILE* f = std::fopen(path, "wb"); if (f) { std::fwrite(png.data(), 1, png.size(), f); std::fclose(f); std::fprintf(stderr, "[rvk] wrote %s (%ux%u)\n", path, w, h); }
}

// Async PNG writer (2026-07-17 attract-pacing): the deflate+adler encode of a ~2.7MB frame ran
// INLINE on the present path — at RVK_PNGEVERY=60 that's a once-per-second multi-frame present
// stall, so the capture tooling was slowing the very pacing it measures. writePng() now snapshots
// the pixels (the caller's pointer is a persistently-mapped readback buffer that the next frame
// reuses — the copy must be synchronous) and hands the encode+file-IO to one worker thread.
// Same-path jobs still queued are COALESCED (rvk_last.png only needs its newest frame); when the
// queue is full the caller encodes synchronously (back-pressure — diagnostic dump floods keep
// every file, they just pay the old inline cost). RVK_PNGSYNC=1 restores the fully-inline path.
// Worker state is heap-leaked: a detached thread must not touch destructed function-local statics
// during process exit.
void writePng(const char* path, const uint8_t* rgba, uint32_t w, uint32_t h) {
  static bool syncMode = std::getenv("RVK_PNGSYNC") != nullptr;
  if (syncMode || !path || !rgba || !w || !h) { writePngSync(path, rgba, w, h); return; }
  struct PngJob { std::string path; std::vector<uint8_t> pix; uint32_t w, h; };
  static std::mutex* qm = new std::mutex;
  static std::condition_variable* qcv = new std::condition_variable;
  static std::deque<PngJob>* q = new std::deque<PngJob>;
  static bool started = false;
  bool runSync = false;
  {
    std::lock_guard<std::mutex> l(*qm);
    if (!started) {
      started = true;
      std::thread([]{
        for (;;) {
          PngJob j;
          { std::unique_lock<std::mutex> l2(*qm); qcv->wait(l2, []{ return !q->empty(); });
            j = std::move(q->front()); q->pop_front(); }
          writePngSync(j.path.c_str(), j.pix.data(), j.w, j.h);
        }
      }).detach();
    }
    bool coalesced = false;
    for (auto& j : *q)
      if (j.path == path) { j.pix.assign(rgba, rgba + (size_t)w * h * 4); j.w = w; j.h = h; coalesced = true; break; }
    if (!coalesced) {
      if (q->size() >= 16) runSync = true;   // bounded memory; flood pays the old inline cost
      else q->emplace_back(PngJob{path, std::vector<uint8_t>(rgba, rgba + (size_t)w * h * 4), w, h});
    }
  }
  if (runSync) { writePngSync(path, rgba, w, h); return; }
  qcv->notify_one();
}

bool initVk() {
  g_base = nullptr;
  VkApplicationInfo app{VK_STRUCTURE_TYPE_APPLICATION_INFO};
  app.pApplicationName = "futari-port"; app.apiVersion = VK_API_VERSION_1_2;
  VkInstanceCreateInfo ici{VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO}; ici.pApplicationInfo = &app;
  const char* layers[] = {"VK_LAYER_KHRONOS_validation"};
  if (std::getenv("RVK_VALIDATE")) { ici.enabledLayerCount = 1; ici.ppEnabledLayerNames = layers; }
#ifdef _WIN32
  // RVK_WINDOW: WSI instance extensions, only when the on-screen window is requested.
  const char* winExts[] = {VK_KHR_SURFACE_EXTENSION_NAME, VK_KHR_WIN32_SURFACE_EXTENSION_NAME};
  if (rvk_window_on()) { ici.enabledExtensionCount = 2; ici.ppEnabledExtensionNames = winExts; }
#endif
  VKC(vkCreateInstance(&ici, nullptr, &g.instance), "vkCreateInstance");

  uint32_t n = 0; vkEnumeratePhysicalDevices(g.instance, &n, nullptr);
  if (!n) { std::fprintf(stderr, "[rvk] no Vulkan devices\n"); g.failed = true; return false; }
  std::vector<VkPhysicalDevice> devs(n); vkEnumeratePhysicalDevices(g.instance, &n, devs.data());
  // GPU pick (2026-07-16 fix): this used to accept the FIRST device that was discrete OR integrated,
  // so on any hybrid box whichever enumerated first won — on this dev machine that selected the
  // "Intel UHD Graphics 730" iGPU while the display hangs off an RTX 3080, making every present a
  // cross-adapter copy (and starving the renderer). Prefer DISCRETE strictly, fall back to
  // INTEGRATED, then anything. RVK_GPU=<substring> overrides by name (case-sensitive), e.g.
  // RVK_GPU=Intel to force the iGPU for an A/B.
  g.phys = devs[0];
  {
    const char* want = getenv("RVK_GPU");
    VkPhysicalDevice disc = VK_NULL_HANDLE, integ = VK_NULL_HANDLE, named = VK_NULL_HANDLE;
    for (auto d : devs) {
      VkPhysicalDeviceProperties p{}; vkGetPhysicalDeviceProperties(d, &p);
      std::fprintf(stderr, "[rvk]   gpu candidate: \"%s\" type=%d\n", p.deviceName, (int)p.deviceType);
      if (want && std::strstr(p.deviceName, want) && !named) named = d;
      if (p.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU && !disc) disc = d;
      else if (p.deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU && !integ) integ = d;
    }
    if (named) g.phys = named; else if (disc) g.phys = disc; else if (integ) g.phys = integ;
  }
  { VkPhysicalDeviceProperties p{}; vkGetPhysicalDeviceProperties(g.phys, &p); std::snprintf(g.devname, sizeof g.devname, "%s", p.deviceName); }

  uint32_t qn = 0; vkGetPhysicalDeviceQueueFamilyProperties(g.phys, &qn, nullptr);
  std::vector<VkQueueFamilyProperties> qf(qn); vkGetPhysicalDeviceQueueFamilyProperties(g.phys, &qn, qf.data());
  bool got = false;
  for (uint32_t i = 0; i < qn; ++i) if (qf[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) { g.qfam = i; got = true; break; }
  if (!got) { std::fprintf(stderr, "[rvk] no graphics queue\n"); g.failed = true; return false; }

  // Query + enable device features needed by the REAL (translated-shader) pipeline: shaderInt64
  // (SPIR-V 64-bit integer ops for BDA math), Vulkan1.2 bufferDeviceAddress + descriptorIndexing
  // family (runtimeDescriptorArray, partiallyBound, sampledImageArrayNonUniformIndexing, and the
  // update-after-bind bits our bindless registry needs).
  VkPhysicalDeviceVulkan12Features avail12{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES};
  VkPhysicalDeviceFeatures2 avail2{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, &avail12};
  vkGetPhysicalDeviceFeatures2(g.phys, &avail2);
  if (!avail2.features.shaderInt64) std::fprintf(stderr, "[rvk] WARNING: shaderInt64 not supported by device!\n");
  if (!avail12.bufferDeviceAddress) std::fprintf(stderr, "[rvk] WARNING: bufferDeviceAddress not supported by device!\n");
  if (!avail12.runtimeDescriptorArray) std::fprintf(stderr, "[rvk] WARNING: runtimeDescriptorArray not supported by device!\n");

  VkPhysicalDeviceVulkan12Features feat12{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES};
  feat12.bufferDeviceAddress = VK_TRUE;
  feat12.descriptorIndexing = VK_TRUE;
  feat12.runtimeDescriptorArray = VK_TRUE;
  feat12.descriptorBindingPartiallyBound = VK_TRUE;
  feat12.descriptorBindingSampledImageUpdateAfterBind = VK_TRUE;
  feat12.descriptorBindingUpdateUnusedWhilePending = VK_TRUE;
  feat12.descriptorBindingVariableDescriptorCount = VK_TRUE;
  feat12.shaderSampledImageArrayNonUniformIndexing = VK_TRUE;
  VkPhysicalDeviceFeatures2 feat2{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, &feat12};
  feat2.features.shaderInt64 = VK_TRUE;

  float pri = 1.0f;
  VkDeviceQueueCreateInfo qci{VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO}; qci.queueFamilyIndex = g.qfam; qci.queueCount = 1; qci.pQueuePriorities = &pri;
  VkDeviceCreateInfo dci{VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO}; dci.queueCreateInfoCount = 1; dci.pQueueCreateInfos = &qci;
  dci.pNext = &feat2; dci.pEnabledFeatures = nullptr;
#ifdef _WIN32
  // RVK_WINDOW: swapchain device extension, same gate as the instance extensions above.
  const char* devExts[] = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
  if (rvk_window_on()) { dci.enabledExtensionCount = 1; dci.ppEnabledExtensionNames = devExts; }
#endif
  VKC(vkCreateDevice(g.phys, &dci, nullptr, &g.dev), "vkCreateDevice");
  vkGetDeviceQueue(g.dev, g.qfam, 0, &g.queue);

  // RVK_HDR: choose the color-target format for all render targets (offscreen + pass + resolve texs).
  // Round-9 (2026-07-15): DEFAULT FLIPPED ON after a full non-regression pass (title/mode/char/side
  // menus + TATE field all clean under HDR; menus are provably identity — clamp mode-2 + exposure 1.0
  // in recordTonemapToLdr). Value-checked getenv so the old UNORM8 path stays BYTE-IDENTICAL and
  // available: RVK_HDR=0 forces it off; RVK_HDR unset (or any nonzero value) = HDR on.
  const char* hdrEnv = std::getenv("RVK_HDR");
  bool hdrOn = hdrEnv ? (std::atoi(hdrEnv) != 0) : true;
  g_rtFmt = hdrOn ? VK_FORMAT_R16G16B16A16_SFLOAT : VK_FORMAT_R8G8B8A8_UNORM;
  if (rvk_hdr()) std::fprintf(stderr, "[rvk][hdr] render targets = R16G16B16A16_SFLOAT (float EDRAM, no bloom clip)\n");
  // ---- offscreen color image + view (shared) ----
  VkImageCreateInfo img{VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO};
  img.imageType = VK_IMAGE_TYPE_2D; img.format = g_rtFmt; img.extent = {kW, kH, 1};
  img.mipLevels = 1; img.arrayLayers = 1; img.samples = VK_SAMPLE_COUNT_1_BIT; img.tiling = VK_IMAGE_TILING_OPTIMAL;
  // TRANSFER_DST added 2026-07-17: the RVK_WALLBG=4 wallpaper pass blits INTO g.image — running
  // without the usage bit was validation-UB the driver tolerated inline but device-losts under
  // the async worker's concurrent submissions (VUID-vkCmdBlitImage-dstImage-00224).
  img.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT; // SAMPLED: RVK_HDR tonemap samples g.image
  img.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
  VKC(vkCreateImage(g.dev, &img, nullptr, &g.image), "vkCreateImage");
  VkMemoryRequirements mr{}; vkGetImageMemoryRequirements(g.dev, g.image, &mr);
  VkMemoryAllocateInfo mai{VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO}; mai.allocationSize = mr.size; mai.memoryTypeIndex = findMem(mr.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
  VKC(vkAllocateMemory(g.dev, &mai, nullptr, &g.imageMem), "vkAllocateMemory(image)");
  VKC(vkBindImageMemory(g.dev, g.image, g.imageMem, 0), "vkBindImageMemory");
  VkImageViewCreateInfo iv{VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO}; iv.image = g.image; iv.viewType = VK_IMAGE_VIEW_TYPE_2D; iv.format = g_rtFmt;
  iv.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  VKC(vkCreateImageView(g.dev, &iv, nullptr, &g.imageView), "vkCreateImageView");
  // async-worker display image (same format/size; pure transfer target/source)
  VkImageCreateInfo imgS = img;
  imgS.usage = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
  VKC(vkCreateImage(g.dev, &imgS, nullptr, &g.imageShow), "vkCreateImage(show)");
  VkMemoryRequirements mrS{}; vkGetImageMemoryRequirements(g.dev, g.imageShow, &mrS);
  VkMemoryAllocateInfo maiS{VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO}; maiS.allocationSize = mrS.size; maiS.memoryTypeIndex = findMem(mrS.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
  VKC(vkAllocateMemory(g.dev, &maiS, nullptr, &g.imageShowMem), "vkAllocateMemory(show)");
  VKC(vkBindImageMemory(g.dev, g.imageShow, g.imageShowMem, 0), "vkBindImageMemory(show)");

  // 8 bytes/pixel so RVK_HDR's R16G16B16A16_SFLOAT (8bpp) readback copies don't overrun; in the
  // default UNORM8 (4bpp) path the extra space is unused and behavior is byte-identical. (PNG/film
  // capture assumes RGBA8, so it is unreliable under RVK_HDR — the on-window present blit, which
  // converts float->swapchain directly, is the HDR A/B surface. Productionize the PNG path later.)
  if (!makeBuffer((VkDeviceSize)kW * kH * 8, VK_BUFFER_USAGE_TRANSFER_DST_BIT,
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &g.readback, &g.readbackMem, nullptr)) return false;

  // ---- render pass (clear -> draw -> leave in TRANSFER_SRC for readback) (shared) ----
  VkAttachmentDescription att{}; att.format = g_rtFmt; att.samples = VK_SAMPLE_COUNT_1_BIT;
  att.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR; att.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
  att.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE; att.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
  att.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED; att.finalLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
  VkAttachmentReference ref{0, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL};
  VkSubpassDescription sub{}; sub.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS; sub.colorAttachmentCount = 1; sub.pColorAttachments = &ref;
  VkSubpassDependency dep{}; dep.srcSubpass = VK_SUBPASS_EXTERNAL; dep.dstSubpass = 0;
  dep.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT; dep.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
  dep.srcAccessMask = 0; dep.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
  VkRenderPassCreateInfo rp{VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO}; rp.attachmentCount = 1; rp.pAttachments = &att; rp.subpassCount = 1; rp.pSubpasses = &sub; rp.dependencyCount = 1; rp.pDependencies = &dep;
  VKC(vkCreateRenderPass(g.dev, &rp, nullptr, &g.pass), "vkCreateRenderPass");
  // Persistence variant (RVK_PERSIST): LOAD prior contents instead of CLEAR. Pure-2D shell/menu
  // frames only periodically redraw the static full-screen background (sky, menu swirl) and rely
  // on framebuffer persistence for it between partial redraws; our per-frame CLEAR wiped it,
  // causing the title-sky flicker + the permanently-missing menu background. initialLayout matches
  // the TRANSFER_SRC finalLayout the offscreen is left in each frame. Format/subpass identical, so
  // g.fb is compatible with both passes.
  VkAttachmentDescription attL = att; attL.loadOp = VK_ATTACHMENT_LOAD_OP_LOAD; attL.initialLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
  VkRenderPassCreateInfo rpL = rp; rpL.pAttachments = &attL;
  VKC(vkCreateRenderPass(g.dev, &rpL, nullptr, &g.passLoad), "vkCreateRenderPass(load)");
  VkFramebufferCreateInfo fbi{VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO}; fbi.renderPass = g.pass; fbi.attachmentCount = 1; fbi.pAttachments = &g.imageView; fbi.width = kW; fbi.height = kH; fbi.layers = 1;
  VKC(vkCreateFramebuffer(g.dev, &fbi, nullptr, &g.fb), "vkCreateFramebuffer");

  // ==================== PASSTHROUGH pipeline (original, unchanged) ====================
  VkDescriptorSetLayoutBinding b0{}; b0.binding = 0; b0.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER; b0.descriptorCount = 1; b0.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
  VkDescriptorSetLayoutCreateInfo dl{VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO}; dl.bindingCount = 1; dl.pBindings = &b0;
  VKC(vkCreateDescriptorSetLayout(g.dev, &dl, nullptr, &g.dsl), "vkCreateDescriptorSetLayout");
  VkPipelineLayoutCreateInfo pl{VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO}; pl.setLayoutCount = 1; pl.pSetLayouts = &g.dsl;
  VKC(vkCreatePipelineLayout(g.dev, &pl, nullptr, &g.plLayout), "vkCreatePipelineLayout");

  VkShaderModule vs = makeShader(kSpriteVertSpv, sizeof kSpriteVertSpv);
  VkShaderModule fs = makeShader(kSpriteFragSpv, sizeof kSpriteFragSpv);
  VkPipelineShaderStageCreateInfo stages[2] = {
    {VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO, nullptr, 0, VK_SHADER_STAGE_VERTEX_BIT, vs, "main", nullptr},
    {VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO, nullptr, 0, VK_SHADER_STAGE_FRAGMENT_BIT, fs, "main", nullptr}};
  VkVertexInputBindingDescription vib{0, sizeof(Vtx), VK_VERTEX_INPUT_RATE_VERTEX};
  VkVertexInputAttributeDescription via[3] = {
    {0, 0, VK_FORMAT_R32G32_SFLOAT, offsetof(Vtx, x)},
    {1, 0, VK_FORMAT_R32G32_SFLOAT, offsetof(Vtx, u)},
    {2, 0, VK_FORMAT_R32G32B32A32_SFLOAT, offsetof(Vtx, r)}};
  VkPipelineVertexInputStateCreateInfo vi{VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO}; vi.vertexBindingDescriptionCount = 1; vi.pVertexBindingDescriptions = &vib; vi.vertexAttributeDescriptionCount = 3; vi.pVertexAttributeDescriptions = via;
  VkPipelineInputAssemblyStateCreateInfo ia{VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO}; ia.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
  VkViewport vp{0, 0, (float)kW, (float)kH, 0, 1}; VkRect2D sc{{0, 0}, {kW, kH}};
  VkPipelineViewportStateCreateInfo vps{VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO}; vps.viewportCount = 1; vps.pViewports = &vp; vps.scissorCount = 1; vps.pScissors = &sc;
  VkPipelineRasterizationStateCreateInfo rs{VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO}; rs.polygonMode = VK_POLYGON_MODE_FILL; rs.cullMode = VK_CULL_MODE_NONE; rs.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE; rs.lineWidth = 1.0f;
  VkPipelineMultisampleStateCreateInfo ms{VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO}; ms.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
  VkPipelineColorBlendAttachmentState cba{}; cba.blendEnable = VK_TRUE;
  cba.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA; cba.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA; cba.colorBlendOp = VK_BLEND_OP_ADD;
  cba.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE; cba.dstAlphaBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA; cba.alphaBlendOp = VK_BLEND_OP_ADD;
  // RANK 21 (RB_COLOR_MASK, 0x2104): this init-time pipeline is built before any PM4 register
  // decode has run, so it can't read the live register here — it stays the mask==0xF (full write)
  // pipeline, which getOrCreatePassthroughPipeline() (below) reuses as its mask==0xF fast path.
  // Draw sites read the guest's actual g_regFile[0x2104] and route through that cache; only the
  // constant identity value for the "everything enabled" case lives here.
  cba.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
  VkPipelineColorBlendStateCreateInfo cb{VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO}; cb.attachmentCount = 1; cb.pAttachments = &cba;
  VkGraphicsPipelineCreateInfo gp{VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO};
  gp.stageCount = 2; gp.pStages = stages; gp.pVertexInputState = &vi; gp.pInputAssemblyState = &ia; gp.pViewportState = &vps;
  gp.pRasterizationState = &rs; gp.pMultisampleState = &ms; gp.pColorBlendState = &cb; gp.layout = g.plLayout; gp.renderPass = g.pass; gp.subpass = 0;
  VKC(vkCreateGraphicsPipelines(g.dev, VK_NULL_HANDLE, 1, &gp, nullptr, &g.pipeline), "vkCreateGraphicsPipelines");
  vkDestroyShaderModule(g.dev, vs, nullptr); vkDestroyShaderModule(g.dev, fs, nullptr);

  VkDescriptorPoolSize ps{VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, kMaxTextures};
  VkDescriptorPoolCreateInfo dp{VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO}; dp.maxSets = kMaxTextures; dp.poolSizeCount = 1; dp.pPoolSizes = &ps;
  VKC(vkCreateDescriptorPool(g.dev, &dp, nullptr, &g.descPool), "vkCreateDescriptorPool");
  VkSamplerCreateInfo sm{VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO}; sm.magFilter = VK_FILTER_LINEAR; sm.minFilter = VK_FILTER_LINEAR;
  sm.addressModeU = sm.addressModeV = sm.addressModeW = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
  VKC(vkCreateSampler(g.dev, &sm, nullptr, &g.sampler), "vkCreateSampler");

  // ---- dynamic vertex/index buffers + a staging buffer for texture uploads (shared) ----
  if (!makeBuffer((VkDeviceSize)kMaxVerts * sizeof(Vtx), VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &g.vbuf, &g.vbufMem, &g.vbufMap)) return false;
  if (!makeBuffer((VkDeviceSize)kMaxIndices * sizeof(uint32_t), VK_BUFFER_USAGE_INDEX_BUFFER_BIT,
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &g.ibuf, &g.ibufMem, &g.ibufMap)) return false;
  g.stagingSize = (VkDeviceSize)2048 * 2048 * 4;
  if (!makeBuffer(g.stagingSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &g.staging, &g.stagingMem, &g.stagingMap)) return false;

  VkCommandPoolCreateInfo pci{VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO}; pci.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT; pci.queueFamilyIndex = g.qfam;
  VKC(vkCreateCommandPool(g.dev, &pci, nullptr, &g.pool), "vkCreateCommandPool");
  VkCommandBufferAllocateInfo cbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO}; cbi.commandPool = g.pool; cbi.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY; cbi.commandBufferCount = 1;
  VKC(vkAllocateCommandBuffers(g.dev, &cbi, &g.cmd), "vkAllocateCommandBuffers");
  VKC(vkAllocateCommandBuffers(g.dev, &cbi, &g.segCmd), "vkAllocateCommandBuffers(seg)");
  VkFenceCreateInfo fci{VK_STRUCTURE_TYPE_FENCE_CREATE_INFO};
  VKC(vkCreateFence(g.dev, &fci, nullptr, &g.fence), "vkCreateFence");
  VKC(vkCreateFence(g.dev, &fci, nullptr, &g.segFence), "vkCreateFence(seg)");
  // command-buffer ring (fence batching): g.cmd/g.fence repoint into these per pass
  {
    VkCommandBufferAllocateInfo rcb{VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO};
    rcb.commandPool = g.pool; rcb.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY; rcb.commandBufferCount = 6;
    VKC(vkAllocateCommandBuffers(g.dev, &rcb, g.ringCmd), "vkAllocateCommandBuffers(ring)");
    for (int rs = 0; rs < 6; ++rs) VKC(vkCreateFence(g.dev, &fci, nullptr, &g.ringFence[rs]), "vkCreateFence(ring)");
    g.cmd = g.ringCmd[0]; g.fence = g.ringFence[0]; g.ringIdx = 0;
  }

  // ==================== REAL (translated-shader) pipeline setup ====================
  // 4 bindless descriptor sets: 0=2D images, 1=3D images, 2=cube images, 3=samplers.
  VkDescriptorSetLayoutBinding rBind{}; rBind.binding = 0; rBind.stageFlags = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
  VkDescriptorBindingFlags bindFlags = VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT | VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT;
  VkDescriptorSetLayoutBindingFlagsCreateInfo bfci{VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO};
  bfci.bindingCount = 1; bfci.pBindingFlags = &bindFlags;
  for (int s = 0; s < 4; ++s) {
    rBind.descriptorType = (s == 3) ? VK_DESCRIPTOR_TYPE_SAMPLER : VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
    rBind.descriptorCount = (s == 3) ? kMaxBindlessSamplers : kMaxBindlessImages;
    VkDescriptorSetLayoutCreateInfo rdl{VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO};
    rdl.bindingCount = 1; rdl.pBindings = &rBind;
    rdl.flags = VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT;
    rdl.pNext = &bfci;
    VKC(vkCreateDescriptorSetLayout(g.dev, &rdl, nullptr, &g.rDsl[s]), "vkCreateDescriptorSetLayout(real)");
  }
  VkPushConstantRange pcr{VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT, 0, 40};  // 24B BDAs + 16B pc.ndc (RVK_TRUE48 epilogue; {1,1,0,0} = legacy identity)
  VkPipelineLayoutCreateInfo rpl{VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO};
  rpl.setLayoutCount = 4; rpl.pSetLayouts = g.rDsl; rpl.pushConstantRangeCount = 1; rpl.pPushConstantRanges = &pcr;
  VKC(vkCreatePipelineLayout(g.dev, &rpl, nullptr, &g.rPlLayout), "vkCreatePipelineLayout(real)");

  VkDescriptorPoolSize rps[2] = {
    {VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, kMaxBindlessImages * 3},
    {VK_DESCRIPTOR_TYPE_SAMPLER, kMaxBindlessSamplers}};
  VkDescriptorPoolCreateInfo rdp{VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO};
  rdp.flags = VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT; rdp.maxSets = 4; rdp.poolSizeCount = 2; rdp.pPoolSizes = rps;
  VKC(vkCreateDescriptorPool(g.dev, &rdp, nullptr, &g.rDescPool), "vkCreateDescriptorPool(real)");
  VkDescriptorSetAllocateInfo rda{VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO};
  rda.descriptorPool = g.rDescPool; rda.descriptorSetCount = 4; rda.pSetLayouts = g.rDsl;
  VKC(vkAllocateDescriptorSets(g.dev, &rda, g.rSets), "vkAllocateDescriptorSets(real)");

  VkSamplerCreateInfo rsm{VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO}; rsm.magFilter = VK_FILTER_LINEAR; rsm.minFilter = VK_FILTER_LINEAR;
  rsm.addressModeU = rsm.addressModeV = rsm.addressModeW = VK_SAMPLER_ADDRESS_MODE_REPEAT;
  VKC(vkCreateSampler(g.dev, &rsm, nullptr, &g.rSampler), "vkCreateSampler(real)");
  VkDescriptorImageInfo rsdii{g.rSampler, VK_NULL_HANDLE, VK_IMAGE_LAYOUT_UNDEFINED};
  VkWriteDescriptorSet rswr{VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET};
  rswr.dstSet = g.rSets[3]; rswr.dstBinding = 0; rswr.dstArrayElement = 0; rswr.descriptorCount = 1;
  rswr.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLER; rswr.pImageInfo = &rsdii;
  vkUpdateDescriptorSets(g.dev, 1, &rswr, 0, nullptr);
  // Sampler slot 1 = POINT/POINT (2026-07-17 CAVE-card seams): the guest's texture fetch constant
  // carries mag/min filter bits (dword_3 +19/+21) that the port always ignored — every draw sampled
  // LINEAR. The SDK/rexglue honors them (texture_cache.cpp: binding filter -> fetch-const fallback;
  // the ROM ps's tfetch says kUseFetchConst for all filters). Slot picked per batch from tf[3].
  rsm.magFilter = VK_FILTER_NEAREST; rsm.minFilter = VK_FILTER_NEAREST;
  VKC(vkCreateSampler(g.dev, &rsm, nullptr, &g.rSamplerPoint), "vkCreateSampler(realPoint)");
  VkDescriptorImageInfo rspii{g.rSamplerPoint, VK_NULL_HANDLE, VK_IMAGE_LAYOUT_UNDEFINED};
  rswr.dstArrayElement = 1; rswr.pImageInfo = &rspii;
  vkUpdateDescriptorSets(g.dev, 1, &rswr, 0, nullptr);
  // ★ RVK_TFCLAMP slots 2 (LINEAR+CLAMP) and 3 (NEAREST+CLAMP): the fetch constant's ClampX/Y
  // (tf0 [12:10]/[15:13]) were ALWAYS ignored — both wrap axes sampled REPEAT. The char-select
  // backdrop's edge-strip self-copy sources a hair outside [0,1]; hardware (ClampX=2 in every
  // ROM fetch: tf0=0x..4802) clamps to edge, our REPEAT wrapped in the OPPOSITE edge of the
  // pane = the periodic "water banner" band behind the title (user captures frame1228 vs SDK
  // frame2759; EID 1546/1550 = the two One/Zero strip copies caught painting the wrap).
  // Shell menu fetches carry ClampX=0 (tf0=0x..0002) and legitimately tile -> the bit MUST be
  // honored per draw, exactly like the filter bits above. RVK_TFCLAMP=0 reverts (slots unused).
  rsm.magFilter = VK_FILTER_LINEAR; rsm.minFilter = VK_FILTER_LINEAR;
  rsm.addressModeU = rsm.addressModeV = rsm.addressModeW = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
  VKC(vkCreateSampler(g.dev, &rsm, nullptr, &g.rSamplerLinC), "vkCreateSampler(realLinC)");
  VkDescriptorImageInfo rslc{g.rSamplerLinC, VK_NULL_HANDLE, VK_IMAGE_LAYOUT_UNDEFINED};
  rswr.dstArrayElement = 2; rswr.pImageInfo = &rslc;
  vkUpdateDescriptorSets(g.dev, 1, &rswr, 0, nullptr);
  rsm.magFilter = VK_FILTER_NEAREST; rsm.minFilter = VK_FILTER_NEAREST;
  VKC(vkCreateSampler(g.dev, &rsm, nullptr, &g.rSamplerPointC), "vkCreateSampler(realPointC)");
  VkDescriptorImageInfo rspc{g.rSamplerPointC, VK_NULL_HANDLE, VK_IMAGE_LAYOUT_UNDEFINED};
  rswr.dstArrayElement = 3; rswr.pImageInfo = &rspc;
  vkUpdateDescriptorSets(g.dev, 1, &rswr, 0, nullptr);

  // constants arena: generous size — VS(4KB)+PS(3.5KB) snapshotted rarely, SharedConstants(512B)
  // once per batch; a few thousand batches/frame fit comfortably in 8MB.
  g.rArenaSize = 8ull * 1024 * 1024;
  if (!makeBdaBuffer(g.rArenaSize, &g.rArenaBuf, &g.rArenaMem, &g.rArenaMap, &g.rArenaAddr)) return false;

  if (rvk_hdr() && !initTonemap()) return false;   // RVK_HDR Part 2: float->LDR tonemap pass
  g.ok = true;
  std::fprintf(stderr, "[rvk] Vulkan up: device=\"%s\" %ux%u pipeline ready (real+passthrough)\n", g.devname, kW, kH);
  return true;
}

// ============================================================================
// RVK_WINDOW on-screen present (2026-07-13, Windows-only)
// ============================================================================
#ifdef _WIN32
// ★ F11 fullscreen toggle (2026-08-03, beta1 user request). Borderless-fullscreen on the
// window's current monitor; F11 again restores the saved windowed style+rect. No exclusive
// mode, no new swapchain code: the style/size change makes the next acquire/present return
// OUT_OF_DATE/SUBOPTIMAL and the EXISTING recreate path (oldSwapchain handoff proven) picks
// up the new extent. WndProc runs on the presenting thread (the pump lives inside guest
// presents), so no cross-thread window state races. RVK_NOF11=1 disables the key.
static void rvkToggleFullscreen(HWND h) {
  static bool fs = false; static RECT winRect{}; static DWORD winStyle = 0;
  if (!fs) {
    winStyle = (DWORD)GetWindowLongA(h, GWL_STYLE);
    GetWindowRect(h, &winRect);
    HMONITOR mon = MonitorFromWindow(h, MONITOR_DEFAULTTONEAREST);
    MONITORINFO mi{sizeof(MONITORINFO)};
    if (!GetMonitorInfoA(mon, &mi)) return;
    SetWindowLongA(h, GWL_STYLE, WS_POPUP | WS_VISIBLE);
    SetWindowPos(h, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top,
                 mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top,
                 SWP_FRAMECHANGED | SWP_SHOWWINDOW);
    fs = true;
    std::fprintf(stderr, "[rvk][win] F11 -> fullscreen %ldx%ld\n",
                 mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top);
  } else {
    SetWindowLongA(h, GWL_STYLE, (LONG)winStyle | WS_VISIBLE);
    SetWindowPos(h, HWND_NOTOPMOST, winRect.left, winRect.top,
                 winRect.right - winRect.left, winRect.bottom - winRect.top,
                 SWP_FRAMECHANGED | SWP_SHOWWINDOW);
    fs = false;
    std::fprintf(stderr, "[rvk][win] F11 -> windowed\n");
  }
}

LRESULT CALLBACK rvkWndProc(HWND h, UINT m, WPARAM w, LPARAM l) {
  if (m == WM_KEYDOWN && w == VK_F11 && !(l & (1 << 30))) {   // bit30 = autorepeat
    static bool off = std::getenv("RVK_NOF11") && atoi(std::getenv("RVK_NOF11")) != 0;
    if (!off) rvkToggleFullscreen(h);
    return 0;
  }
  if (m == WM_CLOSE) {
    gw.closed = true; std::fprintf(stderr, "[rvk][win] window closed by user\n");
    // ★ 2026-07-27 FNF-8 P1: X must actually QUIT. There is no host main loop to see a WM_QUIT
    // (the pump lives inside guest-thread presents) and guest threads cannot be joined, so the
    // orderly exit IS flush + _Exit. Same semantics as arcade power-off; the guest's own
    // EEPROM/save validator handles a torn write. RVK_NOEXITONCLOSE=1 restores the old
    // flag-only behaviour (window closes, process lives) for drives that want it.
    static bool stay = std::getenv("RVK_NOEXITONCLOSE") && atoi(std::getenv("RVK_NOEXITONCLOSE")) != 0;
    if (!stay) { std::fflush(nullptr); std::_Exit(0); }
    return 0;
  }
  return DefWindowProcA(h, m, w, l);
}

bool rvkWindowCreateSwapchain() {
  VkSurfaceCapabilitiesKHR caps{};
  if (vkGetPhysicalDeviceSurfaceCapabilitiesKHR(g.phys, gw.surface, &caps) != VK_SUCCESS) return false;
  if (caps.currentExtent.width == 0 || caps.currentExtent.height == 0) return false;  // minimized
  uint32_t nf = 0; vkGetPhysicalDeviceSurfaceFormatsKHR(g.phys, gw.surface, &nf, nullptr);
  std::vector<VkSurfaceFormatKHR> fmts(nf); vkGetPhysicalDeviceSurfaceFormatsKHR(g.phys, gw.surface, &nf, fmts.data());
  VkSurfaceFormatKHR pick = fmts.empty() ? VkSurfaceFormatKHR{VK_FORMAT_B8G8R8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR} : fmts[0];
  for (auto& f : fmts) if (f.format == VK_FORMAT_B8G8R8A8_UNORM || f.format == VK_FORMAT_R8G8B8A8_UNORM) { pick = f; break; }
  uint32_t imgCount = caps.minImageCount + 1;
  if (caps.maxImageCount && imgCount > caps.maxImageCount) imgCount = caps.maxImageCount;
  VkSwapchainCreateInfoKHR sci{VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR};
  sci.surface = gw.surface; sci.minImageCount = imgCount;
  sci.imageFormat = pick.format; sci.imageColorSpace = pick.colorSpace;
  sci.imageExtent = caps.currentExtent; sci.imageArrayLayers = 1;
  sci.imageUsage = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
  sci.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
  sci.preTransform = caps.currentTransform; sci.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
  // Present mode (2026-07-16). The guest's frame clock is now the synthetic 59.94Hz vblank pump
  // (rt.cpp), and RT_GAMEPUMP ticks the game from inside VdSwap — so the guest RENDERS AND PRESENTS
  // from inside the vblank callback. A blocking FIFO present therefore inserts a SECOND, unlocked
  // ~60Hz wait into that same serialized path: the pump wants to fire every 16.68ms while the
  // present itself parks up to 16.67ms waiting for a refresh it isn't phase-locked to, so the two
  // clocks serialize and the game runs BELOW its intended rate. Measured on this build (RTX 3080,
  // 100Hz display): FIFO = ~42 presents/sec, MAILBOX = 59.9, IMMEDIATE = 59.9. i.e. the pump alone
  // holds a textbook 59.94; FIFO's blocking wait — which is NOT phase-locked to our synthetic vblank —
  // is what drags it off. (Not an iGPU artifact: first measured as 24/sec while mis-selecting the
  // Intel iGPU, and it persists at 42/sec on the discrete GPU.)
  // Default MAILBOX: tear-free like FIFO, but non-blocking, so the pump keeps owning pacing. Falls
  // back to FIFO where MAILBOX is absent (e.g. the Intel surface offers only IMMEDIATE+FIFO), which
  // costs pacing accuracy — a real consideration for iGPU users, tracked separately.
  //   RVK_VSYNC=1 -> force FIFO (blocking vsync)
  //   RVK_VSYNC=0 -> force IMMEDIATE (uncapped, tearing; the "is it fast enough" diagnostic)
  uint32_t pmCount = 0; vkGetPhysicalDeviceSurfacePresentModesKHR(g.phys, gw.surface, &pmCount, nullptr);
  std::vector<VkPresentModeKHR> pms(pmCount);
  if (pmCount) vkGetPhysicalDeviceSurfacePresentModesKHR(g.phys, gw.surface, &pmCount, pms.data());
  auto haveMode = [&](VkPresentModeKHR m){ for (auto p : pms) if (p == m) return true; return false; };
  { std::string ml; for (auto p : pms) { ml += (p==0?"IMMEDIATE ":p==1?"MAILBOX ":p==2?"FIFO ":p==3?"FIFO_RELAXED ":"? "); }
    std::fprintf(stderr, "[rvk] surface present modes (%u): %s | images min=%u max=%u req=%u extent=%ux%u\n",
                 pmCount, ml.c_str(), caps.minImageCount, caps.maxImageCount, imgCount,
                 caps.currentExtent.width, caps.currentExtent.height); }
  const char* vsEnv = getenv("RVK_VSYNC");
  int vsMode = vsEnv ? atoi(vsEnv) : -1;   // -1 = unset => default (MAILBOX preferred)
  sci.presentMode = VK_PRESENT_MODE_FIFO_KHR;   // always supported; the fallback
  const char* why = "FIFO (forced)";
  if (vsMode == 0) {
    if (haveMode(VK_PRESENT_MODE_IMMEDIATE_KHR)) { sci.presentMode = VK_PRESENT_MODE_IMMEDIATE_KHR; why = "IMMEDIATE (RVK_VSYNC=0)"; }
    else why = "FIFO (IMMEDIATE unsupported)";
  } else if (vsMode < 0) {
    if (haveMode(VK_PRESENT_MODE_MAILBOX_KHR)) { sci.presentMode = VK_PRESENT_MODE_MAILBOX_KHR; why = "MAILBOX (default: pump owns pacing)"; }
    else why = "FIFO (MAILBOX unsupported)";
  }
  std::fprintf(stderr, "[rvk] presentMode=%d %s\n", (int)sci.presentMode, why);
  sci.clipped = VK_TRUE; sci.oldSwapchain = gw.swapchain;
  VkSwapchainKHR ns = VK_NULL_HANDLE;
  if (vkCreateSwapchainKHR(g.dev, &sci, nullptr, &ns) != VK_SUCCESS) return false;
  if (gw.swapchain) vkDestroySwapchainKHR(g.dev, gw.swapchain, nullptr);
  gw.swapchain = ns; gw.scFormat = pick.format; gw.scExtent = sci.imageExtent;
  uint32_t ni = 0; vkGetSwapchainImagesKHR(g.dev, gw.swapchain, &ni, nullptr);
  gw.scImages.resize(ni); vkGetSwapchainImagesKHR(g.dev, gw.swapchain, &ni, gw.scImages.data());
  // (Re)size the per-image blit semaphores with the swapchain (see Win::semBlit). Recreate
  // callers vkQueueWaitIdle first, so the old semaphores' present waits have retired.
  for (VkSemaphore s : gw.semBlit) if (s) vkDestroySemaphore(g.dev, s, nullptr);
  gw.semBlit.assign(ni, VK_NULL_HANDLE);
  VkSemaphoreCreateInfo bsem{VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO};
  for (uint32_t bi = 0; bi < ni; ++bi) vkCreateSemaphore(g.dev, &bsem, nullptr, &gw.semBlit[bi]);
  std::fprintf(stderr, "[rvk][win] swapchain %ux%u x%u fmt=%d\n", gw.scExtent.width, gw.scExtent.height, ni, (int)gw.scFormat);
  return true;
}

bool rvkWindowInit() {
  if (gw.inited) return !gw.failed;
  gw.inited = true;
  WNDCLASSA wc{}; wc.lpfnWndProc = rvkWndProc; wc.hInstance = GetModuleHandleA(nullptr);
  wc.lpszClassName = "futari_rvk_window"; wc.hCursor = LoadCursorA(nullptr, (LPCSTR)IDC_ARROW);
  RegisterClassA(&wc);
  // fixed-size window; CLIENT area defaults to kW x kH (the native compose size). RVK_WINSIZE
  // ("WxH", e.g. 1920x1080; 2026-07-28 user request: 1080p test window) sets a different client
  // size — the present blit (dstOffsets = full swapchain extent, line ~3559) already scales the
  // 1280x720 compose to whatever the swapchain is, so this only changes the window/swapchain.
  // Same 16:9 assumed; no letterbox math here.
  uint32_t winW = kW, winH = kH;
  if (const char* ws = std::getenv("RVK_WINSIZE")) {
    unsigned pw = 0, ph = 0;
    if (std::sscanf(ws, "%ux%u", &pw, &ph) == 2 && pw >= 320 && ph >= 240 && pw <= 7680 && ph <= 4320) {
      winW = pw; winH = ph;
      std::fprintf(stderr, "[rvk][win] RVK_WINSIZE=%ux%u (compose stays %ux%u, blit-scaled)\n", winW, winH, kW, kH);
    } else std::fprintf(stderr, "[rvk][win] RVK_WINSIZE '%s' invalid — using %ux%u\n", ws, kW, kH);
  }
  DWORD style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
  RECT r{0, 0, (LONG)winW, (LONG)winH}; AdjustWindowRect(&r, style, FALSE);
  // ASCII hyphen: the previous em-dash was UTF-8 bytes through the ANSI API -> "â€\"" mojibake
  gw.hwnd = CreateWindowExA(0, wc.lpszClassName, "Mushihimesama Futari - futari_realcomp",
                            style, CW_USEDEFAULT, CW_USEDEFAULT, r.right - r.left, r.bottom - r.top,
                            nullptr, nullptr, wc.hInstance, nullptr);
  if (!gw.hwnd) { std::fprintf(stderr, "[rvk][win] CreateWindow FAILED\n"); gw.failed = true; return false; }
  ShowWindow(gw.hwnd, SW_SHOWNORMAL);
  VkWin32SurfaceCreateInfoKHR wsci{VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR};
  wsci.hinstance = wc.hInstance; wsci.hwnd = gw.hwnd;
  if (vkCreateWin32SurfaceKHR(g.instance, &wsci, nullptr, &gw.surface) != VK_SUCCESS) {
    std::fprintf(stderr, "[rvk][win] vkCreateWin32SurfaceKHR FAILED\n"); gw.failed = true; return false;
  }
  VkBool32 sup = VK_FALSE;
  vkGetPhysicalDeviceSurfaceSupportKHR(g.phys, g.qfam, gw.surface, &sup);
  if (!sup) { std::fprintf(stderr, "[rvk][win] queue family %u cannot present\n", g.qfam); gw.failed = true; return false; }
  if (!rvkWindowCreateSwapchain()) { std::fprintf(stderr, "[rvk][win] swapchain create FAILED\n"); gw.failed = true; return false; }
  VkSemaphoreCreateInfo semci{VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO};
  vkCreateSemaphore(g.dev, &semci, nullptr, &gw.semAcquire);
  // gw.semBlit is created per-image inside rvkWindowCreateSwapchain (already ran above).
  // DEDICATED command pool (2026-07-17 async render worker): gw.cmd used to come from g.pool —
  // command POOLS require external sync, and with the worker recording g.cmd (g.pool) while the
  // present thread records gw.cmd concurrently, the shared pool was a driver-side data race
  // (intermittent 0xC0000005 on mangled pointers, runs K/N). Own pool = fully independent.
  VkCommandPoolCreateInfo wpci{VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO};
  wpci.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT; wpci.queueFamilyIndex = g.qfam;
  if (vkCreateCommandPool(g.dev, &wpci, nullptr, &gw.pool) != VK_SUCCESS) { gw.failed = true; return false; }
  VkCommandBufferAllocateInfo cai{VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO};
  cai.commandPool = gw.pool; cai.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY; cai.commandBufferCount = 1;
  vkAllocateCommandBuffers(g.dev, &cai, &gw.cmd);
  VkFenceCreateInfo fci{VK_STRUCTURE_TYPE_FENCE_CREATE_INFO};
  vkCreateFence(g.dev, &fci, nullptr, &gw.fence);
  std::fprintf(stderr, "[rvk][win] window up (%ux%u client) — RT_PAD_HOST keys: arrows+Z(A)+X(B)+Enter(START)\n", winW, winH);
  return true;
}
#endif  // _WIN32

// ---- RVK_HDR shared tonemap recorder (F6 fix, 2026-07-14) ----
// Records the g.image(F16) -> g.imageLdr(UNORM8) tonemap into `cb`. On entry g.image MUST be in
// TRANSFER_SRC_OPTIMAL (true both after a fence-waited render submit AND after a render pass whose
// finalLayout is TRANSFER_SRC in the same cb). On exit g.imageLdr holds the tonemapped UNORM8 in
// TRANSFER_SRC (passLdr finalLayout) and g.image is restored to TRANSFER_SRC. Used by BOTH the
// on-window present blit AND every PNG readback copy — before this fix the readback copied the raw
// F16 g.image into the RGBA8-sized readback buffer and writePng reinterpreted half-floats as bytes,
// producing the red/magenta "HDR corruption" garbage in rvk_last.png / rvk_frameN.png / ours_*.png.
static void recordTonemapToLdr(VkCommandBuffer cb) {
  // REGISTER-TRUE PRESENT (2026-07-19, oracle-diff pass): the ACES+exposure grade was a host FUDGE.
  // Live-field probes (RVK_RTFMT + RVK_CYANDBG, corrected reg 0x231B) pin the guest chain: EVERY
  // exp_bias is 0 (both RB_COLOR_INFO.color_exp_bias and RB_COPY_DEST_INFO.copy_dest_exp_bias, all
  // resolve classes), the 7e3 HDR range exists ONLY inside the 320x240 tile passes (RB_COLOR_INFO
  // fmt=3) and saturates to [0,1] at their k_2_10_10_10 resolve, and the panel/composite EDRAM is
  // plain 8888 — there is NO guest tonemap shader anywhere (SDK: resolve dest-format packing
  // saturates; exp_bias would be a 2^bias scale, and it's zero). So the true present = hard clamp
  // + the game's DC_LUT display gamma ramp, globally (the DC_LUT is scanout state — menus go
  // through it too, hence no fieldActive fork in mode 3). Default: mode 3, exposure 1.0.
  // RVK_TONEMAP=0/1/2 restores the legacy curves (with the old fieldActive gating) for A/B.
  static float exposure = std::getenv("RVK_EXPOSURE") ? (float)atof(std::getenv("RVK_EXPOSURE")) : 1.0f;
  static int  tmMode   = std::getenv("RVK_TONEMAP") ? std::atoi(std::getenv("RVK_TONEMAP")) : 3;  // 0=Reinhard 1=ACES 2=clamp 3=clamp+DC_LUT ramp (register-true)
  static bool tmAll    = std::getenv("RVK_TONEMAP_ALL") != nullptr;
  uint32_t fieldActive = g_base ? __builtin_bswap32(*(const uint32_t*)(g_base + GA_FIELD_ACTIVE)) : 0u;
  int   useMode = (tmMode == 3 || tmAll || fieldActive) ? tmMode : 2;      // legacy modes: menus clamp
  float useExp  = (tmMode == 3 || tmAll || fieldActive) ? exposure : 1.0f; // legacy modes: no menu dim
  // g.image TRANSFER_SRC -> SHADER_READ (srcStage covers both the prior color-write render pass and
  // a prior transfer-read; either way the writes are complete before the tonemap samples g.image).
  VkImageMemoryBarrier tb{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; tb.srcQueueFamilyIndex = tb.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
  tb.image = g.image; tb.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  tb.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL; tb.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
  tb.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT | VK_ACCESS_TRANSFER_READ_BIT; tb.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
  vkCmdPipelineBarrier(cb, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT | VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &tb);
  VkRenderPassBeginInfo rpb{VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO}; rpb.renderPass = g.passLdr; rpb.framebuffer = g.fbLdr; rpb.renderArea = {{0, 0}, {kW, kH}}; rpb.clearValueCount = 0;
  vkCmdBeginRenderPass(cb, &rpb, VK_SUBPASS_CONTENTS_INLINE);
  vkCmdBindPipeline(cb, VK_PIPELINE_BIND_POINT_GRAPHICS, g.tmPipe);
  vkCmdBindDescriptorSets(cb, VK_PIPELINE_BIND_POINT_GRAPHICS, g.tmLayout, 0, 1, &g.tmSet, 0, nullptr);
  struct { float e; int32_t m; } pc{useExp, useMode};
  vkCmdPushConstants(cb, g.tmLayout, VK_SHADER_STAGE_FRAGMENT_BIT, 0, sizeof pc, &pc);
  vkCmdDraw(cb, 3, 1, 0, 0);
  vkCmdEndRenderPass(cb);   // g.imageLdr -> TRANSFER_SRC (passLdr finalLayout)
  // restore g.image to TRANSFER_SRC (the layout the render passes + non-HDR blit/copy expect)
  tb.oldLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL; tb.newLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
  tb.srcAccessMask = VK_ACCESS_SHADER_READ_BIT; tb.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
  vkCmdPipelineBarrier(cb, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &tb);
}

// IEEE-754 binary16 -> binary32. Used by the RVK_DUMPRES resolve dumper so it can PNG the
// R16G16B16A16_SFLOAT resolves that RVK_HDR creates — reading them as raw uint8 (the old path)
// reinterpreted half-floats as bytes and produced the red/magenta garbage that made every prior
// field capture unreadable (same root as the F6 display-readback fix above).
static inline float rvk_half2float(uint16_t h) {
  uint32_t sign = (uint32_t)(h & 0x8000u) << 16;
  uint32_t exp  = (h >> 10) & 0x1Fu;
  uint32_t man  = h & 0x3FFu;
  uint32_t f;
  if (exp == 0) {
    if (man == 0) { f = sign; }
    else { exp = 127 - 15 + 1; while (!(man & 0x400u)) { man <<= 1; --exp; } man &= 0x3FFu; f = sign | (exp << 23) | (man << 13); }
  } else if (exp == 0x1F) { f = sign | 0x7F800000u | (man << 13); }
  else { f = sign | ((exp - 15 + 127) << 23) | (man << 13); }
  float out; std::memcpy(&out, &f, 4); return out;
}

// Copy the current display image into g.readback (source of the rvk_*.png files). Under RVK_HDR the
// g.image is F16 — tonemap it to UNORM8 g.imageLdr first and copy THAT, so writePng sees real bytes.
static void copyDisplayToReadback(VkCommandBuffer cb) {
  VkImage src = g.image;
  if (rvk_hdr()) { recordTonemapToLdr(cb); src = g.imageLdr; }
  VkBufferImageCopy cp{}; cp.imageSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; cp.imageExtent = {kW, kH, 1};
  vkCmdCopyImageToBuffer(cb, src, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, g.readback, 1, &cp);
}

// Blit the offscreen frame to the window. Called at the end of every guest present (both the
// hookrender and legacy paths), on the same thread, under g_mtx. g.image is TRANSFER_SRC_OPTIMAL
// after any rendered frame (every render ends with the readback copy); between renders it still
// holds the last frame, so re-presenting it is exactly what a real display does.
static std::atomic<bool> g_showReady{false};   // worker has published >=1 complete frame to imageShow
static std::atomic<long> g_showFrame{-1};      // [pace] guest frame number of the published imageShow
// ★ PACED HANDOFF (2026-07-27 judder leg): latest-wins delivery judders — the worker's ~14ms
// completions beat against the 16.7ms present grid, producing repeat+skip pairs ([pace] measured
// 122/300 age-2 presents with paired repeats/skips in-stage; user-verified juddery vs the SDK).
// Fix: each present WAITS (cv, capped) for frame f-1 to be published — steady state shows every
// frame exactly once at constant 1-frame latency, the same cadence as hardware. HEALTH-GATED:
// when the worker's EWMA cost exceeds ~15.5ms (heavy stretch, content already <100%) the wait is
// skipped so tick rate is never taxed. RVK_PACE=0 reverts to latest-wins.
static std::mutex* g_showMtx = new std::mutex;
static std::condition_variable* g_showCv = new std::condition_variable;
static std::atomic<uint32_t> g_workerCostMs10{140};   // EWMA of drain cost, tenths of ms
void rvkWindowPresent(bool asyncShow = false) {
#ifdef _WIN32
  // ★ RVK_RDCCAP_ATFRAME=<N> (2026-08-01, OLD-vs-NVK shadow bisect) — PRESENT-COUNT capture
  // trigger that works on EVERY renderer path. The existing RVK_RDCCAP self-trigger lives inside
  // the nvk draw loop ([shtexiso], ~L10756) and therefore can never fire when RT_NVK is unset —
  // but the OLD path is precisely the arm we need as the oracle for the ranking-shadow class
  // (ledger §14: old = shadow correct, nvk = box). This site is the ONE present funnel shared by
  // rvk_present / rvk_present_hooked / the idle re-present, so counting calls here gives a stable
  // "present number" on any path. RenderDoc counts frames by the present that follows, so the
  // trigger is armed one present early — which is what TriggerMultiFrameCapture wants anyway.
  //   RVK_RDCCAP_ATFRAME=<N>  first fire at present #N (1-based)
  //   RVK_RDCCAP_ATEVERY=<M>  re-fire every M presents after that (sweep; 0 = one-shot)
  //   RVK_RDCCAP_N            frames per fire (shared with the nvk lever, default 3)
  //   RVK_RDCCAP_MAX          fire budget (shared with the nvk lever, default 8)
  // Default OFF: unset => byte-identical to before. Inert when the process is not hooked.
  {
    static const long capAt = std::getenv("RVK_RDCCAP_ATFRAME") ? std::atol(std::getenv("RVK_RDCCAP_ATFRAME")) : -1;
    if (capAt >= 0) {
      static const long capEvery = std::getenv("RVK_RDCCAP_ATEVERY") ? std::atol(std::getenv("RVK_RDCCAP_ATEVERY")) : 0;
      static const uint32_t capN = std::getenv("RVK_RDCCAP_N") ? (uint32_t)atoi(std::getenv("RVK_RDCCAP_N")) : 3u;
      static const long capMax = std::getenv("RVK_RDCCAP_MAX") ? std::atol(std::getenv("RVK_RDCCAP_MAX")) : 8;
      static long presN = 0;
      const long p = ++presN;
      // Resolved exactly the way the nvk RVK_RDCCAP block does (GetModuleHandleA + RENDERDOC_GetAPI).
      static RENDERDOC_API_1_1_2* rdocAt = []() -> RENDERDOC_API_1_1_2* {
        HMODULE m = GetModuleHandleA("renderdoc.dll");
        if (!m) { std::fprintf(stderr, "[rdccap] RVK_RDCCAP_ATFRAME set but renderdoc.dll is not loaded "
                                       "— launch via _tmpscripts/shadow_rdc.sh\n"); return nullptr; }
        pRENDERDOC_GetAPI getApi = (pRENDERDOC_GetAPI)GetProcAddress(m, "RENDERDOC_GetAPI");
        RENDERDOC_API_1_1_2* a = nullptr;
        if (!getApi || getApi(eRENDERDOC_API_Version_1_1_2, (void**)&a) != 1) {
          std::fprintf(stderr, "[rdccap] RENDERDOC_GetAPI failed (ATFRAME)\n"); return nullptr;
        }
        std::fprintf(stderr, "[rdccap] RenderDoc in-app API acquired (ATFRAME arm)\n");
        return a;
      }();
      static long capFires = 0;
      const bool due = (p == capAt) || (capEvery > 0 && p > capAt && ((p - capAt) % capEvery) == 0);
      if (rdocAt && due && capFires < capMax) {
        ++capFires;
        rdocAt->TriggerMultiFrameCapture(capN);
        std::fprintf(stderr, "[rdccap] ★ ATFRAME TRIGGERED %u-frame capture at present#%ld (fire %ld/%ld)\n",
                     capN, p, capFires, capMax);
      }
      // heartbeat so a mis-aimed N is diagnosable from the log alone
      if ((p % 500) == 0) std::fprintf(stderr, "[rdccap] present#%ld (atframe=%ld every=%ld fires=%ld)\n",
                                       p, capAt, capEvery, capFires);
    }
  }
  if (!rvk_window_on() || !g.ok || !g_anyRender) return;
  // Async fast path before the first worker publish: keep the last swapchain frame on screen
  // rather than blitting a possibly-mid-render g.image (the worker owns g.image in async mode).
  if (asyncShow && !g_showReady.load(std::memory_order_acquire)) return;
  // ★ 2026-07-27 survivability: a failed window bring-up used to leave a windowless process
  // running forever (every present a silent no-op). Die loudly once instead.
  if (gw.failed && !rvkDiehardOn()) rvkDieLoud("window bring-up failed (no window will ever exist)", 4);
  if (!rvkWindowInit() || gw.closed || gw.failed) return;
  // pump the message queue so the window stays responsive (move/close); guest present cadence
  // (~60/s) doubles as the pump cadence.
  MSG msg;
  while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) { TranslateMessage(&msg); DispatchMessageA(&msg); }
  if (gw.closed) return;
  // Deferred fence wait (async mode): the previous present's fence is waited HERE, one present
  // later, instead of at the tail of its own call — by now the prior blit is ~a frame old so this
  // is normally 0ms, and the present thread stops sitting behind the worker's in-flight GPU
  // passes. MUST happen BEFORE vkAcquireNextImageKHR: acquire re-signals semAcquire, which is
  // only legal once the previous submission's wait on it has retired (waiting its fence proves
  // that) — waiting after acquire device-losts (run J: FAIL submit = -4).
  static bool gwFencePending = false;
  if (gwFencePending) { rvkWaitFences(g.dev, 1, &gw.fence, VK_TRUE, 1000000000ull); gwFencePending = false; }
  uint32_t idx = 0;
  VkResult ar = vkAcquireNextImageKHR(g.dev, gw.swapchain, 100000000ull, gw.semAcquire, VK_NULL_HANDLE, &idx);
  // Recreate-and-reacquire ONLY on OUT_OF_DATE (which does NOT signal semAcquire). SUBOPTIMAL
  // acquires DO signal — the old path re-acquired with the already-signaled semAcquire (same
  // VUID-00067 UB class as the shared blit semaphore; FNF-2 2026-07-26). A suboptimal frame
  // presents fine; the present-side check below owns the recreate.
  if (ar == VK_ERROR_OUT_OF_DATE_KHR) {
    { std::lock_guard<std::mutex> ql(g_qMtx); vkQueueWaitIdle(g.queue); }
    if (!rvkWindowCreateSwapchain()) return;
    ar = vkAcquireNextImageKHR(g.dev, gw.swapchain, 100000000ull, gw.semAcquire, VK_NULL_HANDLE, &idx);
  }
  if (ar == VK_SUBOPTIMAL_KHR) ar = VK_SUCCESS;
  if (ar != VK_SUCCESS) { rvkVkResultCheck(ar, "acquireNextImage"); return; }   // was a silent return incl. DEVICE_LOST
  vkResetCommandBuffer(gw.cmd, 0);
  VkCommandBufferBeginInfo cbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO};
  cbi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
  vkBeginCommandBuffer(gw.cmd, &cbi);
  // RVK_HDR Part 2: tonemap the FLOAT g.image -> UNORM8 g.imageLdr (the blit source below), so the
  // flattened HDR bloom compresses to [0,1] via exposure+curve instead of hard-clamping to white.
  // RVK_HDR Part 2: tonemap the FLOAT g.image -> UNORM8 g.imageLdr (the blit source below), so the
  // flattened HDR bloom compresses to [0,1] via exposure+curve instead of hard-clamping to white.
  // Shared with the PNG readback path via recordTonemapToLdr (F6 fix) so on-window and screenshot
  // pixels are identical. Menus (field_active==0) use clamp+exposure-1 so they match the pre-HDR look.
  VkImage blitSrc = g.image;
  if (asyncShow) blitSrc = g.imageShow;   // worker already tonemapped/published a complete frame
  else if (rvk_hdr()) { recordTonemapToLdr(gw.cmd); blitSrc = g.imageLdr; }
  // ★ FrameDelay honoring (2026-08-15, user-signed design call). The guest's Screen->Extra
  // Setting "FrameDelay" (save 0x16E4; shell global DAT_821F8558, kept a verbatim copy by the
  // guest's own applier FUN_82187ee0) is a display-latency enum: 0V Tearing / 1V Fast / 2V PCB
  // / 3V Slow, shipped default 1V. On hardware it lands in a PM4 present-interval packet that
  // nothing walks at RT_NVK=2 (host pacing is frameclock-owned), so it was inert here. 2V/3V
  // are honored as a composed-frame DELAY RING: present the frame composed N presents ago
  // (N = value-1) — exactly N*16.68ms extra display latency, tear-free, zero contact with the
  // frameclock/grant path or game logic (the same tick/display split the hardware had).
  // 0V ≡ 1V on host BY DESIGN: MAILBOX present is already non-blocking with sub-refresh
  // latency; the 360 needed tearing only to dodge its blocking vsync wait. RVK_FRAMEDELAY=0
  // reverts to inert. Screenshot/PNG/RenderDoc paths read the live compose, NOT the ring —
  // instruments always see the current frame.
  VkImage presentSrc = blitSrc;
  VkImage fdSlot = VK_NULL_HANDLE; bool fdSlotHasContent = false;
  {
    static int fdLever = -1;
    if (fdLever < 0) { const char* e = getenv("RVK_FRAMEDELAY"); fdLever = (!e || atoi(e) != 0) ? 1 : 0; }
    static VkImage ring[2] = {}; static VkDeviceMemory ringMem[2] = {};
    static uint32_t prevVal = ~0u; static int fill = 0, slot = 0; static bool dead = false;
    uint32_t val = (fdLever && g_base) ? be32(0x821F8558) : 1u;
    if (val > 3u) val = 1u;                       // enum is 0..3; anything else = shipped default
    uint32_t delayN = (val >= 2u) ? val - 1u : 0u;
    if (dead) delayN = 0;
    if (val != prevVal) {
      std::fprintf(stderr, "[rvk] framedelay=%uV -> +%u frame(s) display latency%s\n",
                   val, delayN, fdLever ? "" : " (RVK_FRAMEDELAY=0: inert)");
      prevVal = val; fill = 0; slot = 0;          // depth change: re-warm the ring
    }
    if (delayN > 0 && !ring[0] && !dead) {
      VkImageCreateInfo ri{VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO};
      ri.imageType = VK_IMAGE_TYPE_2D; ri.format = g_rtFmt; ri.extent = {kW, kH, 1};
      ri.mipLevels = 1; ri.arrayLayers = 1; ri.samples = VK_SAMPLE_COUNT_1_BIT;
      ri.tiling = VK_IMAGE_TILING_OPTIMAL;
      ri.usage = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
      ri.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
      for (int i = 0; i < 2; ++i) {
        if (vkCreateImage(g.dev, &ri, nullptr, &ring[i]) != VK_SUCCESS) { dead = true; break; }
        VkMemoryRequirements mr{}; vkGetImageMemoryRequirements(g.dev, ring[i], &mr);
        VkMemoryAllocateInfo ai{VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO};
        ai.allocationSize = mr.size; ai.memoryTypeIndex = findMem(mr.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
        if (vkAllocateMemory(g.dev, &ai, nullptr, &ringMem[i]) != VK_SUCCESS ||
            vkBindImageMemory(g.dev, ring[i], ringMem[i], 0) != VK_SUCCESS) { dead = true; break; }
      }
      if (dead) { std::fprintf(stderr, "[rvk] framedelay ring bring-up FAILED — staying inert\n"); delayN = 0; }
    }
    if (delayN > 0) {
      // N slots = N frames delay: show ring[slot] (written N presents ago), then overwrite it
      // with this frame's compose below. Warm-up (fill<N) shows the live frame while filling.
      if (slot >= (int)delayN) slot = 0;
      fdSlot = ring[slot]; fdSlotHasContent = (fill >= (int)delayN);
      if (fdSlotHasContent) presentSrc = fdSlot;
      slot = (slot + 1) % (int)delayN;
      if (fill < (int)delayN) ++fill;
    }
  }
  VkImageMemoryBarrier toDst{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER};
  toDst.srcQueueFamilyIndex = toDst.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
  toDst.image = gw.scImages[idx]; toDst.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  toDst.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED; toDst.newLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
  toDst.srcAccessMask = 0; toDst.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
  vkCmdPipelineBarrier(gw.cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &toDst);
  // ★ Aspect-preserving fit (2026-08-03, with the F11 toggle): center the 16:9 compose in the
  // swapchain and letterbox/pillarbox the remainder instead of stretching. Windowed mode is
  // unchanged in practice (RVK_WINSIZE has always been 16:9); this matters when F11 lands on a
  // non-16:9 monitor. Bars are cleared to black below only when they exist.
  int32_t dW = (int32_t)gw.scExtent.width, dH = (int32_t)gw.scExtent.height;
  int32_t fitW = dW, fitH = (int32_t)((int64_t)dW * kH / kW);
  if (fitH > dH) { fitH = dH; fitW = (int32_t)((int64_t)dH * kW / kH); }
  int32_t fx = (dW - fitW) / 2, fy = (dH - fitH) / 2;
  bool bars = (fitW != dW) || (fitH != dH);
  if (bars) {
    VkClearColorValue black{}; VkImageSubresourceRange rr{VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
    vkCmdClearColorImage(gw.cmd, gw.scImages[idx], VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, &black, 1, &rr);
  }
  VkImageBlit blit{};
  blit.srcSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1};
  blit.srcOffsets[1] = {(int32_t)kW, (int32_t)kH, 1};
  blit.dstSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1};
  blit.dstOffsets[0] = {fx, fy, 0};
  blit.dstOffsets[1] = {fx + fitW, fy + fitH, 1};
  // ★ Upscale filter polish (2026-07-28, alpha-1): NEAREST at non-integer scales (e.g. the 1080p
  // test window = 1.5x of 720p) drops/doubles pixel columns unevenly — visibly lumpy on the shell
  // text. Auto: integer scale -> NEAREST (crisp, pixel-exact), non-integer -> LINEAR.
  // RVK_UPFILTER=0 forces NEAREST, =1 forces LINEAR, unset = auto.
  VkFilter upf;
  { static int upfEnv = std::getenv("RVK_UPFILTER") ? std::atoi(std::getenv("RVK_UPFILTER")) : -1;
    if (upfEnv == 0) upf = VK_FILTER_NEAREST;
    else if (upfEnv == 1) upf = VK_FILTER_LINEAR;
    else upf = ((uint32_t)fitW % kW == 0 && (uint32_t)fitH % kH == 0)
             ? VK_FILTER_NEAREST : VK_FILTER_LINEAR; }   // judge by the FIT rect, not the full extent
  vkCmdBlitImage(gw.cmd, presentSrc, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                 gw.scImages[idx], VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &blit, upf);
  if (fdSlot) {
    // FrameDelay ring write: this frame's compose goes into the slot just shown (or, during
    // warm-up, the still-empty slot), to come back out N presents from now. WAR on the shown
    // slot is ordered by the SRC->DST barrier; UNDEFINED oldLayout on first touch discards.
    VkImageMemoryBarrier rb{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER};
    rb.srcQueueFamilyIndex = rb.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    rb.image = fdSlot; rb.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
    rb.oldLayout = fdSlotHasContent ? VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL : VK_IMAGE_LAYOUT_UNDEFINED;
    rb.newLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    rb.srcAccessMask = fdSlotHasContent ? VK_ACCESS_TRANSFER_READ_BIT : 0;
    rb.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    vkCmdPipelineBarrier(gw.cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &rb);
    VkImageBlit rblit{};
    rblit.srcSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; rblit.srcOffsets[1] = {(int32_t)kW, (int32_t)kH, 1};
    rblit.dstSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; rblit.dstOffsets[1] = {(int32_t)kW, (int32_t)kH, 1};
    vkCmdBlitImage(gw.cmd, blitSrc, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                   fdSlot, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &rblit, VK_FILTER_NEAREST);
    VkImageMemoryBarrier rs = rb;
    rs.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL; rs.newLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
    rs.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT; rs.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
    vkCmdPipelineBarrier(gw.cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &rs);
  }
  VkImageMemoryBarrier toPresent = toDst;
  toPresent.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL; toPresent.newLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
  toPresent.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT; toPresent.dstAccessMask = 0;
  vkCmdPipelineBarrier(gw.cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 0, 0, nullptr, 0, nullptr, 1, &toPresent);
  vkEndCommandBuffer(gw.cmd);
  VkPipelineStageFlags waitStage = VK_PIPELINE_STAGE_TRANSFER_BIT;
  VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO};
  si.waitSemaphoreCount = 1; si.pWaitSemaphores = &gw.semAcquire; si.pWaitDstStageMask = &waitStage;
  si.commandBufferCount = 1; si.pCommandBuffers = &gw.cmd;
  si.signalSemaphoreCount = 1; si.pSignalSemaphores = &gw.semBlit[idx];
  vkResetFences(g.dev, 1, &gw.fence);
  if (rvkQueueSubmit(g.queue, 1, &si, gw.fence) != VK_SUCCESS) return;
  VkPresentInfoKHR pi{VK_STRUCTURE_TYPE_PRESENT_INFO_KHR};
  pi.waitSemaphoreCount = 1; pi.pWaitSemaphores = &gw.semBlit[idx];
  pi.swapchainCount = 1; pi.pSwapchains = &gw.swapchain; pi.pImageIndices = &idx;
  VkResult pr;
  { std::lock_guard<std::mutex> ql(g_qMtx); pr = vkQueuePresentKHR(g.queue, &pi); }
  if (pr == VK_ERROR_OUT_OF_DATE_KHR || pr == VK_SUBOPTIMAL_KHR) {
    { std::lock_guard<std::mutex> ql(g_qMtx); vkQueueWaitIdle(g.queue); }
    rvkWindowCreateSwapchain();
  }
  if (asyncShow) gwFencePending = true;   // wait deferred to the next present (see above)
  else rvkWaitFences(g.dev, 1, &gw.fence, VK_TRUE, 1000000000ull);  // sync mode: serialize with the renderer's own submits
#endif
}

// ============================================================================
// PASSTHROUGH per-frame draw (original code, unchanged) — RVK_PASSTHROUGH=1
// ============================================================================
struct Batch { VkDescriptorSet set; uint32_t firstIndex, indexCount; };

bool renderFrameOld(long frame, uint32_t start, uint32_t end) {
  // walk PM4 window, decode draws, build vertex/index arrays batched by texture
  Vtx* V = (Vtx*)g.vbufMap; uint32_t* I = (uint32_t*)g.ibufMap;
  uint32_t nv = 0, ni = 0;
  std::vector<Batch> batches;
  uint32_t tf[6] = {0,0,0,0,0,0}; uint32_t vf0 = 0, vf1 = 0; (void)vf1;
  float vpx = 640.0f, vpy = 360.0f;
  uint32_t curBase = 0xFFFFFFFF; VkDescriptorSet curSet = VK_NULL_HANDLE; uint32_t batchStart = 0;
  int ndraw = 0;

  uint32_t i = start;
  while (i + 4 <= end && nv + 4 <= kMaxVerts && ni + 6 <= kMaxIndices) {
    uint32_t w = be32(i); uint32_t t = w >> 30;
    if (t == 0) {
      uint32_t reg = w & 0x7fff, cnt = ((w >> 16) & 0x3fff) + 1;
      if (i + 4 + cnt * 4 > end + 64) break;
      for (uint32_t k = 0; k < cnt; ++k) { uint32_t r = reg + k, val = be32(i + 4 + k * 4);
        if (r >= 0x4800 && r < 0x4806) tf[r - 0x4800] = val;
        else if (r == 0x48BE) vf0 = val; else if (r == 0x48BF) vf1 = val;
        else if (r == 0x2110) vpx = bef(i + 4 + k * 4);
        else if (r == 0x2112) vpy = bef(i + 4 + k * 4); }
      i += 4 * (1 + cnt);
    } else if (t == 3) {
      uint32_t op = (w >> 8) & 0x7f, cnt = ((w >> 16) & 0x3fff) + 1;
      if (op == 0x22 || op == 0x36) {
        uint32_t n = (be32(i + 8) >> 16) & 0xFFFF;
        uint32_t va = vf0 & ~3u;
        if (va && n >= 3 && n <= 6) {
          // transform: model-space (any negative vert) -> +viewport-center; else screen-space
          float xs[8], ys[8], us[8], vs[8]; uint32_t cols[8];
          bool model = false;
          for (uint32_t k = 0; k < n; ++k) {
            xs[k] = bef(va + k * 24); ys[k] = bef(va + k * 24 + 4);
            cols[k] = be32(va + k * 24 + 12); us[k] = bef(va + k * 24 + 16); vs[k] = bef(va + k * 24 + 20);
            if (xs[k] < 0 || ys[k] < 0) model = true;
          }
          float ox = model ? vpx : 0.f, oy = model ? vpy : 0.f;
          // texture batch
          uint32_t base = ((tf[1] >> 12) & 0xFFFFF) << 12;
          uint32_t tw = (tf[2] & 0x1FFF) + 1, th = ((tf[2] >> 13) & 0x1FFF) + 1, fmt = tf[1] & 0x3F;
          if (base != curBase) {
            if (curSet && ni > batchStart) batches.push_back({curSet, batchStart, ni - batchStart});
            rvkFetchRawNote(tf, base, tw, th, fmt, "legacy");
            curSet = getTexture(base, tw, th, fmt, tf[0]); curBase = base; batchStart = ni;
          }
          uint32_t v0 = nv;
          for (uint32_t k = 0; k < n; ++k) {
            float sx = xs[k] + ox, sy = ys[k] + oy;
            Vtx& o = V[nv++];
            o.x = 2.f * sx / (float)kW - 1.f; o.y = 2.f * sy / (float)kH - 1.f;
            o.u = us[k]; o.v = vs[k];
            uint32_t c = cols[k];
            o.r = ((c >> 16) & 0xFF) / 255.f; o.g = ((c >> 8) & 0xFF) / 255.f; o.b = (c & 0xFF) / 255.f; o.a = ((c >> 24) & 0xFF) / 255.f;
          }
          // triangle-fan of n verts -> (n-2) triangles
          for (uint32_t k = 1; k + 1 < n; ++k) { I[ni++] = v0; I[ni++] = v0 + k; I[ni++] = v0 + k + 1; }
          ndraw++;
        }
      }
      i += 4 * (1 + cnt);
    } else if (t == 2) { i += 4; }
    else break;
  }
  if (curSet && ni > batchStart) batches.push_back({curSet, batchStart, ni - batchStart});

  // record + submit
  segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
  rvkRingNext("draw"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(draw)");
  VkCommandBufferBeginInfo bi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; bi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
  VKC(vkBeginCommandBuffer(g.cmd, &bi), "begin(draw)");
  VkClearValue clear{}; clear.color = {{0.0f, 0.0f, 0.10f, 1.0f}};  // dark navy bg
  VkRenderPassBeginInfo rpb{VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO}; rpb.renderPass = g.pass; rpb.framebuffer = g.fb; rpb.renderArea = {{0, 0}, {kW, kH}}; rpb.clearValueCount = 1; rpb.pClearValues = &clear;
  vkCmdBeginRenderPass(g.cmd, &rpb, VK_SUBPASS_CONTENTS_INLINE);
  // RANK 21: RB_COLOR_MASK (0x2104) drives the passthrough pipeline's colorWriteMask, 1:1 nibble.
  vkCmdBindPipeline(g.cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, getOrCreatePassthroughPipeline(g_regFile[0x2104] & 0xFu));
  VkDeviceSize voff = 0; vkCmdBindVertexBuffers(g.cmd, 0, 1, &g.vbuf, &voff);
  vkCmdBindIndexBuffer(g.cmd, g.ibuf, 0, VK_INDEX_TYPE_UINT32);
  for (auto& b : batches) {
    vkCmdBindDescriptorSets(g.cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, g.plLayout, 0, 1, &b.set, 0, nullptr);
    vkCmdDrawIndexed(g.cmd, b.indexCount, 1, b.firstIndex, 0, 0);
  }
  vkCmdEndRenderPass(g.cmd);
  // image is now TRANSFER_SRC (render pass finalLayout) -> copy to readback
  copyDisplayToReadback(g.cmd);   // F6: tonemaps to UNORM8 under RVK_HDR
  VKC(vkEndCommandBuffer(g.cmd), "end(draw)");
  VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
  VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(draw)");
  VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(draw)");
  VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(draw)");

  std::fprintf(stderr, "[rvk][passthrough] frame%ld: window[0x%X,0x%X) draws=%d verts=%u tris=%u textures=%zu batches=%zu\n",
               frame, start, end, ndraw, nv, ni / 3, g.texCache.size(), batches.size());
  void* map = nullptr; VKC(vkMapMemory(g.dev, g.readbackMem, 0, VK_WHOLE_SIZE, 0, &map), "map(readback)");
  char path[64]; std::snprintf(path, sizeof path, "/tmp/rvk_frame%ld.png", frame);
  writePng(path, (const uint8_t*)map, kW, kH);
  vkUnmapMemory(g.dev, g.readbackMem);
  return true;
}

// ============================================================================
// REAL per-frame draw — walks PM4, tracks IM_LOAD/ALU-consts/VTE, feeds raw guest
// vertex data + real constants to the real translated VS/PS pipelines.
// ============================================================================
struct RBatch { VkPipeline pipeline; uint64_t vsBDA, psBDA, sharedBDA; uint32_t firstIndex, indexCount; VkViewport vp; int vsIdx; uint32_t texIdx; float bc[4];
  // RVK_VTETRUE (2026-07-17 seg-transform rewrite): the raw guest VTE registers at batch-open
  // ({xscale, xoffset, yscale, yoffset}, signed, guest pixels) + the host pointer of the VS const
  // snapshot, so a render site can re-derive the SDK-true host viewport and ndc_scale/ndc_offset
  // (c255) for ITS render-target extent instead of trusting the pre-derived vp.
  float vte[4]; const float* vsHost; uint32_t vteCntl; uint32_t blendReg; int psIdx; uint32_t texBase, texFmt;
  float psC14[4], psC15[4]; };   // ps consts c14/c15 at batch open (RVK_BOXDBG: the ps=50 fade/glow inputs)
// RVK_TRUE48 (2026-07-18 register-true vs=48): the asset-sprite class whose TRUE pipeline was
// decoded from the SDK oracle (vte-DISABLED per PA_CL_VTE_CNTL bit0; guest c255={2,1/256,-0.5,0}
// = canvas->PIXELS; px->ndc epilogue in system consts). Under this lever those draws keep the
// GUEST c255 (no repair/clobber) and get the epilogue via the new pc.ndc push floats + a full-RT
// viewport. Default off until scene-verified vs the oracle resolves.
static bool rvkTrue48On() {   // DEFAULT ON (2026-07-18, oracle-verified on legal/card/demo/menus): RVK_TRUE48=0 reverts
  static bool on = !(std::getenv("RVK_TRUE48") && atoi(std::getenv("RVK_TRUE48")) == 0);
  return on;
}
// FIX-A (2026-07-29) OLD-RENDERER PARITY: 45/47 join the class, because once they run the
// generated modules they DECLARE pc.ndc at offsets 24/32 and need the px->ndc epilogue fed
// exactly like 48 (before this, every VTE-off 45/47 draw pushed ndc floats into a block that
// did not declare them). Tied to the SAME lever as the module repoint: under RT_NVKOLDVS=1 the
// baked modules are back and MUST keep their old viewport-baked treatment.
static bool rvkTrue48(const RBatch& b) {
  bool xrVs = !rvkNvkOldVs() && (b.vsIdx == 45 || b.vsIdx == 47);
  return rvkTrue48On() && (b.vsIdx == 48 || xrVs) && (b.vteCntl & 0x1u) == 0u;
}

// Viewport for the CURRENT tracked VTE state. Three facts iterated empirically against the
// live boot frames on 2026-07-05 (A/B'd vs the proven RVK_PASSTHROUGH decode of the SAME
// frames — loading panel + spinner glyph positions):
//  - XenosRecomp compiles the HLSL with dxc -fvk-invert-y, so the SPIR-V already flips Y
//    for Vulkan — no negative-height viewport is needed on our side.
//  - The M2LibMatrix bakes pixel coordinates into clip-space with w=360: ndc = (x/640, y/360)
//    for screen pixels. The viewport only converts that NDC back to pixels: scale by
//    (XSCALE, |YSCALE|) with NO offset -> VkViewport{-640,-360,1280,720}.
//  - PA_CL_VTE_CNTL toggles in the ring (0x300 <-> offset-enables set), but applying
//    XOFFSET/YOFFSET when the enable bits were set displaced whole batches by exactly
//    (+640,+360) vs the passthrough reference for the SAME draws. This game bakes ALL
//    placement translations into the matrix (verified: replay-screen matrix carries
//    c0.w/c1.w translations); the VTE offsets are never applied to the draws we render.
//  - CLIP-RANGE FIX: the guest matrix maps screen x∈[0,1280] to ndc [0,2] (w=360, scale
//    0.5625) — real Xenos with VTE clip disabled rasterizes that fine, but Vulkan clips
//    |ndc|>1 (observed: replay panel cut exactly at x=640/y=360). Standard emulator trick:
//    HALVE the matrix position rows (c0/c1) in every constants snapshot and DOUBLE the
//    viewport, so all on-screen guest content lands inside the clip volume.
VkViewport currentViewport() {
  float sxv = g_xscale < 0 ? -g_xscale : g_xscale;
  float syv = g_yscale < 0 ? -g_yscale : g_yscale;
  // In-game menu (FSM state 5) ZEROES the viewport scale regs (VTE-disabled screen-space
  // mode: xs=xo=ys=yo=0). A zero-area VkViewport is invalid and rasterizes nothing — that
  // (not clipping or constants) was why every menu draw vanished. Fall back to the last
  // non-zero scales so those draws keep the previous scene's mapping.
  static float lastSx = 640.f, lastSy = 360.f;
  if (sxv < 1.f || syv < 1.f) {
    static long zeroed = 0;
    if ((zeroed++ % 5000) == 0)
      std::fprintf(stderr, "[rvk] viewport scales zero (xs=%.0f ys=%.0f) -> using last good (%.0f,%.0f)\n",
        g_xscale, g_yscale, lastSx, lastSy);
    sxv = lastSx; syv = lastSy;
  } else { lastSx = sxv; lastSy = syv; }
  VkViewport vp{};
  vp.x = -2.f * sxv; vp.y = -2.f * syv; vp.width = 4.f * sxv; vp.height = 4.f * syv;
  vp.minDepth = 0.f; vp.maxDepth = 1.f;
  return vp;
}

// Hardware-true viewport for the asset sprite VS (idx48): px = XOFFSET + XSCALE*ndc.
// The doubled currentViewport() above is a clip-range fix for the SHELL's M2LibMatrix path
// (whose matrix maps pixels to ndc [0,2] and gets its position rows halved); the sprite VS
// emits ndc [-1,1] directly from record coords * c255 {2/320,-,-1,-}, so it needs the REAL
// offset+scale mapping — under the doubled viewport half its canvas lands outside the frame
// (menu text at x<160 was invisible; only records with ndc>0 showed = the "strip").
// dxc -fvk-invert-y already flips Y in the SPIR-V, so use |yscale| and the plain offset.
VkViewport spriteViewport() {
  float sxv = g_xscale < 0 ? -g_xscale : g_xscale;
  float syv = g_yscale < 0 ? -g_yscale : g_yscale;
  VkViewport vp{};
  vp.x = g_xoffset - sxv; vp.y = g_yoffset - syv;
  vp.width = 2.f * sxv; vp.height = 2.f * syv;
  vp.minDepth = 0.f; vp.maxDepth = 1.f;
  return vp;
}

// RVK_TRUEVP (2026-07-19, RENDERER KEYSTONE rank 1): register-true generalization of the
// GetHostViewportInfo model (rexglue-sdk src/graphics/util/draw.cpp) to the NON-vs48 legacy
// classes (vs=9/1/5 front-end/field bg). DEFAULT ON (RVK_TRUEVP=0 reverts to the halve+doubled-vp
// heuristic). Texel-verified equivalent to the heuristic on: title (max diff 0), credited stage-1
// field display (max diff 0), char-select/mode-select (structurally identical, no shear). SCOPE:
// this retires ONLY the halvePosRows + doubled-currentViewport pair; it does NOT retire
// repairMatrix/matrixIsDegenerate, the vertex-sign fork, the submitSegInto scale-to-fit, or the
// g_c255v clobber — those are ORTHOGONAL heuristics (still load-bearing for degenerate matrices,
// mixed-sign verts, resolve-target extent, and vs=48-vte-enabled c255) and must NOT be deleted here.
// FORK: the vs=47 composite keeps its spriteViewport heuristic (its VTE regs are offset-DISABLED yet
// its placement needs the offset — the register-true model does not explain it; kept + reported).
//
// The heuristic path halves the guest M2LibMatrix position rows (halvePosRows) and doubles the
// viewport (currentViewport {-2sx,-2sy,4sx,4sy}). That pair is a clip-range workaround for
// content whose matrix maps guest pixels to pre-divided ndc[0,2] (c0=0.5625, w=360 -> ndc=px/640).
// It is ALGEBRAICALLY the SDK viewport transform re-distributed into (matrix-halve + doubled-rect)
// instead of (unmodified-matrix + offset+-scale rect). Proof: heuristic screen = 2sx*(ndc'+1)-2sx
// with ndc'=0.5*ndc  =>  screen = sx*ndc; register-true rect {-sx,-sy,2sx,2sy} with the UNMODIFIED
// matrix gives screen = ((ndc+1)/2)*2sx - sx = sx*ndc. Identical mapping, but the guest matrix is
// passed UNMODIFIED and the viewport is derived purely from the VTE scale regs (g_xscale/g_yscale,
// PA_CL_VPORT_{X,Y}SCALE 0x210F/0x2111). This is the SDK "host viewport = offset+-scale" realization
// for these classes, whose translated VS emits pre-divided ndc (NOT screen pixels like vs_rom48, so
// they take the viewport-baked distribution rather than the px->ndc epilogue rvkTrue48 uses).
static bool rvkTrueVpOn() {   // DEFAULT ON (2026-07-19, oracle/heuristic-verified title+field+select); RVK_TRUEVP=0 reverts
  static bool on = !(std::getenv("RVK_TRUEVP") && atoi(std::getenv("RVK_TRUEVP")) == 0);
  return on;
}
// register-true host viewport: offset+-scale from the live VTE scale regs, matrix passed unmodified.
// Mirrors currentViewport()'s zero-scale fallback (menu VTE-disabled state zeroes the scale regs).
VkViewport registerTrueViewport() {
  float sxv = g_xscale < 0 ? -g_xscale : g_xscale;
  float syv = g_yscale < 0 ? -g_yscale : g_yscale;
  static float lastSx = 640.f, lastSy = 360.f;
  if (sxv < 1.f || syv < 1.f) { sxv = lastSx; syv = lastSy; } else { lastSx = sxv; lastSy = syv; }
  VkViewport vp{};
  vp.x = -sxv; vp.y = -syv; vp.width = 2.f * sxv; vp.height = 2.f * syv;
  vp.minDepth = 0.f; vp.maxDepth = 1.f;
  return vp;
}

static int nGateMax() {  // max verts per rendered draw (old hardcoded gate was 6)
  static int v = std::getenv("RVK_NMAX") ? atoi(std::getenv("RVK_NMAX")) : 1024;
  return v;
}
// [present-trace] flicker RE (2026-07-14): each on-screen present blits g.image, which is written
// by EITHER the hook path (borders/HUD; central playfield DEFERRED) OR the legacy DISPLAYALL path
// (full field). They interleave -> the window flickers between a border-only/navy-center frame and
// a full field frame. These globals let the two present sites (rvk_present_hooked / rvk_present) log
// which path last wrote g.image and how rich it was, so the interleave + richness is measurable
// before choosing a hold-last gate. Set by renderFrameReal below; read at the legacy present site.
static int  g_realLastDraws    = -1;    // ndraw of the last legacy renderFrameReal CALL
static bool g_realLastRendered = false; // did that call actually submit to g.image?
// walk the PM4 window (always — GPU register state accumulates across frames: IM_LOAD /
// ALU constants / VTE may be set in windows we don't render); submit+readback only if render.
// RVK_PERFLOG=1 (2026-07-17 attract 6-12fps hunt): wall-time of each legacy present, logged every
// 32nd render frame. The attract present path is self-clocked (ROM frame -> VdSwap -> msg-5 grant
// -> next frame), so whatever dominates this function's wall time IS the attract frame rate.
struct RvkPerfScope {
  const char* tag; long frame; bool on;
  std::chrono::steady_clock::time_point t0;
  RvkPerfScope(const char* t, long f) : tag(t), frame(f) {
    static bool en = std::getenv("RVK_PERFLOG") != nullptr;
    on = en; t0 = std::chrono::steady_clock::now();   // always captured (spike dump below needs it)
    g_sfTexN = 0; g_sfTexMs = 0; g_sfTexBytes = 0; g_sfPipeN = 0; g_sfPipeMs = 0;  // [slowframe] reset
    sfFenceN0 = g_fenceN; sfFenceMs0 = g_fenceMsAcc;  // fence DELTA baseline (acc is cumulative)
  }
  long sfFenceN0 = 0; double sfFenceMs0 = 0;
  double lapMs = -1.0;
  void lap() { lapMs = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t0).count(); }  // always: slowframe needs the decode split
  ~RvkPerfScope() {
    p3FrameEnd(frame);   // [perflog3] close+report the tail attribution (no-op when inactive)
    {
      // [slowframe] spike attribution (2026-07-27): any frame >100ms names its dominant cost —
      // texture uploads (n/MB/ms), pipeline creations (n/ms) — independent of RVK_PERFLOG.
      double sfMs = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t0).count();
      if (sfMs > 100.0) {
        static long sfN = 0;
        if (sfN++ < 40)
          std::fprintf(stderr, "[slowframe] %s f%ld %.1fms decode=%.1fms | texUp n=%ld %.1fMB %.1fms | pipeCreate n=%ld %.1fms | fences %ld/%.1fms\n",
                       tag, frame, sfMs, lapMs, g_sfTexN, (double)g_sfTexBytes / 1048576.0, g_sfTexMs,
                       g_sfPipeN, g_sfPipeMs, g_fenceN - sfFenceN0, g_fenceMsAcc - sfFenceMs0);
      }
    }
    if (!on) return;
    static long n = 0;
    double ms = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t0).count();
    static double acc = 0, accLap = 0; static long cnt = 0; acc += ms; if (lapMs >= 0) accLap += lapMs; cnt++;
    if ((n++ % 32) == 0) { std::fprintf(stderr, "[perflog] %s f%ld %.1fms decode=%.1fms fences=%ld/%.1fms (avg %.1f/%.1fms over %ld)\n", tag, frame, ms, lapMs, g_fenceN, g_fenceMsAcc, acc / cnt, accLap / cnt, cnt); acc = 0; accLap = 0; cnt = 0; g_fenceN = 0; g_fenceMsAcc = 0.0; }
  }
};
// RVK_PERFLOG2 (2026-07-17, decode-phase bottleneck hunt): opt-in phase-accumulator that subdivides
// the decode phase RvkPerfScope::lap() already times as one lump. Brackets the 3 measured hot
// sub-phases (texture-cache lookup, VS/PS constant snapshot memcpy, vertex extraction) with
// std::chrono::steady_clock — each bracket is a single cached-bool check (perflog2) when off, so
// this is zero-cost in normal runs. Prints accumulated per-frame averages every 32 calls, same
// cadence/style as [perflog]. Default off; RVK_PERFLOG2=1 to enable.
using RvkClock = std::chrono::steady_clock;
static inline double rvkMs(RvkClock::time_point t0) { return std::chrono::duration<double, std::milli>(RvkClock::now() - t0).count(); }
// ★ RVK_GDPROBE shadow state (2026-07-28, alt-B ghost-draw arm discriminator wf_b8847446):
// what the active VS-constant snapshot's c255 held BEFORE any zero-rescue, whether the rescue
// fired for it, and whether the current draw took the vs=48 c255 clobber. Written at the two
// c255 sites, read by the [gdprobe] per-draw print. Shadow only — never feeds rendering.
static float g_gdC255pre[4] = {0, 0, 0, 0};
static float g_gdEffC255[4] = {0, 0, 0, 0};   // the c255 the CURRENT draw actually binds (post-policy)
static bool g_gdRescued = false;
static bool g_gdClobbered = false;
static bool g_gdTookA = false;                 // per-draw: gdfix per-draw A engaged (census keying)
// ★ RVK_DRAWCENSUS (2026-07-28 compose-1:1 Leg 1, wf_9bf1bc43): MISSING-draw census — fills the
// extras-only drawtrip gap. Identity=(atlasBase,vs,ps); a steady identity (streak>=K presented
// frames) that vanishes for <=R frames and RETURNS = a one-frame-class dropout event (the user's
// multi-element transient flicker). Silent in steady state; identities that never return are
// legit dismissals (suppressed). RVK_CENSUSTEST=1 = fault injection positive control (skips
// counting the tracked steady identity every 300th frame -> MUST emit DROPOUT-CONFIRMED len=1).
struct RvkCensusEnt {
  long streak = 0;       // consecutive presented frames seen
  int cnt = 0;           // draws counted this frame
  int steadyCnt = 0;     // typical per-frame count while steady
  long missSince = -1;   // presented-frame counter when it went missing (-1 = present)
  long missStreak = 0;   // streak value at the moment of loss (reported)
  int missNseg = -1;     // segtab count on the MISSING frame (R1-vs-R2 discriminator)
  int missTotal = -1;    // total draws on the MISSING frame
  float v0x = 0, v0y = 0;
  bool gdA = false; uint32_t vte = 0;
};
static std::unordered_map<uint64_t, RvkCensusEnt> g_censMap;
static long g_censPc = 0;               // presented-frame counter (census clock)
static int g_censLastTotal = -1;        // scene-transition guard
static uint32_t g_censTestBase = 0;     // fault-injection target (first steady identity)
bool renderFrameReal(long frame, uint32_t start, uint32_t end, bool render) {
  RvkPerfScope perf_(render ? "real+render" : "real-walk", frame);
  rvkServiceInvalidations();   // CODE_REVIEW_0804: frame-boundary only (was mid-frame in getTexIndexReal)
  // RVK_SLOWRENDER=<ms> (2026-07-27 decoupling falsifier, default-off): sleep inside the RENDER
  // WORK (skipped on state-only walks) — models an expensive frame. Inline mode: this blocks the
  // guest logic loop (welded, ticks drop — proven 07-27 with RVK_SLOWPRESENT). Async/decoupled
  // mode: this blocks only the worker; guest ticks must HOLD 60/s — that is the decoupling
  // acceptance test. Test instrument only — never ship-on.
  { static int slowms = std::getenv("RVK_SLOWRENDER") ? atoi(std::getenv("RVK_SLOWRENDER")) : 0;
    if (slowms > 0 && frame > -1000000) std::this_thread::sleep_for(std::chrono::milliseconds(slowms)); }
  static bool perflog2 = std::getenv("RVK_PERFLOG2") != nullptr;
  double p2Tex = 0.0, p2Cst = 0.0, p2Vtx = 0.0;  // this-call totals for the 3 measured sub-phases
  // 2026-07-27 "other"-bucket split (task #17): im=matchImLoad (full-ucode FNV per IM_LOAD),
  // pipe=getOrCreateRealPipeline, reg=the three register-write burst loops. Same perflog2 gate.
  double p2Im = 0.0, p2Pipe = 0.0, p2Reg = 0.0;
  long p2NIm = 0, p2NPipe = 0;
  long p2NTexCalls = 0, p2NCstSnaps = 0;
  g_realLastRendered = false;   // set true below only if this call submits a frame to g.image
  g.rArenaOffset = 0; // previous submission already fenced-waited by the time we get here
  uint32_t* Vraw = (uint32_t*)g.vbufMap; // 6 dwords / vertex, raw+byteswapped guest bytes
  uint32_t* Iarr = (uint32_t*)g.ibufMap;
  uint32_t nv = 0, ni = 0;
  // texture/vertex fetch constants persist across frames like real GPU registers —
  // seed from the persistent register shadow instead of zeros (text draws set their
  // font texture in windows we already consumed).
  uint32_t tf[6] = {g_regFile[0x4800], g_regFile[0x4801], g_regFile[0x4802],
                    g_regFile[0x4803], g_regFile[0x4804], g_regFile[0x4805]};
  uint32_t vf0 = g_regFile[0x48BE], vf1 = g_regFile[0x48BF];
  int ndraw = 0;

  std::vector<RBatch> batches;
  // Pass segmentation: each RB_COPY resolve ends a pass. resolves[k] = (# batches before it, dst,
  // dims). The render loop draws each segment, blits the offscreen (shared EDRAM) into the dst's
  // resolve texture, and reads back the final (composite) segment.
  struct ResolvePt { size_t batchIdx; uint32_t dst, w, h; };
  std::vector<ResolvePt> resolves;
  VkPipeline curPipeline = VK_NULL_HANDLE;
  uint64_t curVsBDA = 0, curPsBDA = 0, curSharedBDA = 0;
  uint64_t curVsScreenBDA = 0, curVsModelBDA = 0;
  bool curVsDegen = false;
  float* curVsHost = nullptr; float* curVsScreenHost = nullptr; float* curVsModelHost = nullptr;
  uint64_t c255PatchSrc = 0, c255PatchOut = 0;  // per-window cache of the idx48-patched snapshot
  uint64_t gdPatchASrc = 0, gdPatchAOut = 0;    // per-window cache: collapse-class guest-c255 restore
  uint64_t gdPatchBSrc = 0, gdPatchBOut = 0;    // per-window cache: vport-class substitute enforce
  // batch-local copies: cur* trackers may already hold the NEXT draw's values by the time
  // the previous batch is flushed, so the flush must use the values captured at batch start.
  uint64_t curVsBDAForBatch = 0, curPsBDAForBatch = 0;
  uint32_t curTexIdxForBatch = 0xFFFFFFFFu;
  int curVsIdxForBatch = -2, curPsIdxForBatch = -2;
  VkViewport curVp{};
  uint32_t batchStart = 0;
  float curBc[4] = {0.f, 0.f, 0.f, 0.f};   // RB_BLEND_RED..ALPHA at batch-open time (dynamic blend constants)
  float curVteForBatch[4] = {0.f, 0.f, 0.f, 0.f};   // {xs, xo, ys, yo} at batch-open (RVK_VTETRUE)
  uint32_t curVteCntlForBatch = 0;                  // PA_CL_VTE_CNTL at batch-open (enable bits!)
  uint32_t curBlendForBatch = 0; uint32_t curTexBaseForBatch = 0, curTexFmtForBatch = 0;   // RVK_BOXDBG identity
  const float* curVsHostForBatch = nullptr;
  auto flushBatch = [&](uint32_t niNow) {
    if (curPipeline && niNow > batchStart) batches.push_back({curPipeline, curVsBDAForBatch, curPsBDAForBatch, curSharedBDA, batchStart, niNow - batchStart, curVp, curVsIdxForBatch, curTexIdxForBatch, {curBc[0], curBc[1], curBc[2], curBc[3]},
      {curVteForBatch[0], curVteForBatch[1], curVteForBatch[2], curVteForBatch[3]}, curVsHostForBatch, curVteCntlForBatch,
      curBlendForBatch, curPsIdxForBatch, curTexBaseForBatch, curTexFmtForBatch,
      {g_psConstF[56], g_psConstF[57], g_psConstF[58], g_psConstF[59]},
      {g_psConstF[60], g_psConstF[61], g_psConstF[62], g_psConstF[63]}});
  };

  auto bitf = [](uint32_t v) { float f; std::memcpy(&f, &v, 4); return f; };
  // LEG-45: RB_COPY-register freshness. The per-frame playfield feedback resolves
  // (rdst=0xEEDD000 640x512 + rotating 320x240) are SMALL-n (3/4-vertex) kCopy rect draws —
  // the strict LEG-40 shape gate (n>2048 || prim==0) rejects them, so the feedback buffer the
  // gameplay background quad (vs=5/ps=49) samples stays black/raw and renders as a flat stage
  // tint. A real RB_COPY sequence rewrites the copy regs (0x2318 control / 0x2319 dest /
  // 0x231A pitch) right before its rect draw; content quads running with a STALE kCopy mode
  // (the LEG-40 misclassification class) do not. Classify small-n kCopy draws as resolves
  // only when the copy regs are fresh since the last draw. Lever: RVK_RESFRESH=1.
  bool copyRegsFresh = false;
  // RVK_REGPROBE hot-path fix (2026-07-17, decode-phase getenv hunt): writeReg fires for EVERY
  // register-write dword in the PM4 window (TYPE0 bursts + SET_CONSTANT + LOAD_ALU_CONSTANT can be
  // hundreds to thousands of dwords per frame), and it was calling std::getenv() UNCONDITIONALLY on
  // every single call to test RVK_REGPROBE. getenv() takes a CRT lock on this target; thousands of
  // locked calls/frame is real, measurable overhead for a debug lever that is off by default. Cache
  // the flag once (same pattern as every other RVK_* lever in this file) — behavior is byte-identical
  // (the env var can't change mid-run), this only removes the redundant re-checks.
  static bool regProbe = std::getenv("RVK_REGPROBE") != nullptr;
  auto writeReg = [&](uint32_t r, uint32_t val) {
    // RVK_REGPROBE (2026-07-16): pinpoint WHO writes junk into RB_BLENDCONTROL0 (0x2201). Real
    // RB_BLENDCONTROL has pad bits [15:13] and [31:29] zero; the observed 0x3E808081/0x3E40C0C2/
    // 0x3EE0E0E2 are floats (64/255, 48/255, 112/255) that decode to src=ONE/dst=ZERO = an
    // alpha-IGNORING opaque quad, and 0x2201 is sticky, so every later draw inherits it. g_pm4Src
    // is a breadcrumb set by each decode path so we learn WHICH packet deposits it.
    if (regProbe && r == 0x2201 && (val & 0xE000E000u)) {
      static int rpN = 0;
      if (rpN++ < 40) std::fprintf(stderr, "[regprobe] frame%ld INVALID 0x2201 <- 0x%08X (%.6ff) via %s\n",
                                   frame, val, bitf(val), g_pm4Src ? g_pm4Src : "?");
    }
    if (r < 0x6100) g_regFile[r] = val;
    if (r == 0x2318 || r == 0x2319 || r == 0x231A) copyRegsFresh = true;
    if (r == 0x4900) g_boolConst0 = val; // boolean constants bank 0 -> g_Booleans (c16.x)
    if (r >= 0x4800 && r < 0x4806) tf[r - 0x4800] = val;
    else if (r == 0x48BE) vf0 = val;
    else if (r == 0x48BF) vf1 = val;
    else if (r >= 0x4000 && r < 0x4400) { g_vsConstF[r - 0x4000] = bitf(val); g_vsDirty = true;
      { static bool floatSrc2 = std::getenv("RVK_FLOATSRC") != nullptr;   // see PS branch note
        if (floatSrc2) {
          static long fvN = 0;
          if ((++fvN % 2000) == 1)
            std::fprintf(stderr, "[floatsrc] vs reg 0x%X = %g via %s (x%ld)\n", r, bitf(val), g_pm4Src ? g_pm4Src : "?", fvN);
        } }
      // RVK_C255WATCH: log every write into the vs c255 slot (floats 1020..1023) — the register-true
      // vs=48 class depends on the guest's real c255 {2, 1/256, -0.5, 0} reaching this shadow.
      static bool c255watch = std::getenv("RVK_C255WATCH") != nullptr;
      if (c255watch && r >= 0x43FC && val != 0) {   // nonzero only: boot floods full-bank zero uploads
        static long cw = 0;
        if (cw++ < 40) std::fprintf(stderr, "[c255watch] write reg 0x%X = %g (src %s)\n", r, bitf(val), g_pm4Src ? g_pm4Src : "?");
      }
    }
    else if (r >= 0x4400 && r < 0x4780) { g_psConstF[r - 0x4400] = bitf(val); g_psDirty = true;
      // RVK_FLOATSRC (s2B leg 7): census WHICH packet form delivers game float constants —
      // the nvk mirror found none of {A578,A638,A7B8,A1E0} windows carry them; this names the
      // true seam from the working walker's own ingestion (g_pm4Src breadcrumb, needs
      // RVK_REGPROBE=1 too so breadcrumbs are formatted).
      static bool floatSrc = std::getenv("RVK_FLOATSRC") != nullptr;
      if (floatSrc) {
        static long fsN = 0;
        if ((++fsN % 2000) == 1)
          std::fprintf(stderr, "[floatsrc] ps reg 0x%X = %g via %s (x%ld)\n", r, bitf(val), g_pm4Src ? g_pm4Src : "?", fsN);
      }
    }
    else if (r == 0x210F) g_xscale = bitf(val);
    else if (r == 0x2110) g_xoffset = bitf(val);
    else if (r == 0x2111) g_yscale = bitf(val);
    else if (r == 0x2112) g_yoffset = bitf(val);
    else if (r == 0x2113) g_zscale = bitf(val);
    else if (r == 0x2114) g_zoffset = bitf(val);
    else if (r == 0x2206) g_vteCntl = val;
  };
  // one-shot packet histogram for the first draw-containing window at/after frame RVK_DEBUG_OPS=N
  static long dumpOpsFrom = std::getenv("RVK_DEBUG_OPS") ? std::strtol(std::getenv("RVK_DEBUG_OPS"), nullptr, 10) : -1;
  bool dumpOps = dumpOpsFrom >= 0 && frame >= dumpOpsFrom;
  // RVK_DUMP_ON_WHITE: armed by the first unsupported-fmt white fallback (see rTexIndex) —
  // dump the trigger frame's remaining draws + the next 2 full frames.
  { extern bool g_dumpWhiteTrig; static long trigFrames = 0; static long lastTrigF = -1;
    long trigCap = std::getenv("RVK_WHITE_FRAMES") ? std::strtol(std::getenv("RVK_WHITE_FRAMES"), nullptr, 10) : 3;
    if (g_dumpWhiteTrig && trigFrames < trigCap) {
      dumpOps = true;
      if (frame != lastTrigF) { lastTrigF = frame; trigFrames++; }
    } }
  // RVK_DEBUG_OPS_FIELD=K (hatch RE 2026-07-11): trigger the same one-shot dump on the K-th
  // frame where the GAMEPLAY FIELD flag (guest 0x885C1A20) is active — targets a real stage
  // frame without knowing its frame number. Diagnostic only, default off.
  static long dumpFieldK = std::getenv("RVK_DEBUG_OPS_FIELD") ? std::strtol(std::getenv("RVK_DEBUG_OPS_FIELD"), nullptr, 10) : -1;
  bool fieldTrig = false;   // true on the K-th gameplay-field frame (shared by DUMPRES below)
  // Signal-file manual trigger (default off): `touch /tmp/rvk_dump_now` to arm the NEXT render=true
  // frame for the arena dump + DUMPRES. Lets us capture a chosen STABLE screen (e.g. the cyan TOP
  // MENU) for the offline SDK-oracle diff instead of racing the crash-prone live field. One-shot.
  {
    // MULTI-SHOT (2026-07-19, oracle-diff pass): was a process-lifetime one-shot latch
    // (sigConsumed), which silently disarmed after the FIRST touch — a stray early touch (or a
    // mistimed one) burned the only dump and every later `touch` sat unconsumed with no feedback.
    // The remove() below already makes each touch one-shot; re-arming per touch is what the
    // capture workflow needs (fire at the live field, refire to re-dump). Rate-limit: at most one
    // consume per 30 presented frames so a stuck/re-created file can't storm the readback path.
    // frame >= 0 guard: NEVER fire on the rvk_shadow_update keep-warm sentinel (frame == -1000000).
    // Forcing render=true there ran the full DUMPRES/arena path in the shadow context (unsafe) and
    // meant the arena dump missed the real menu window. Only arm on a real presented frame.
    static long sigLastFrame = -1000000;
    if (frame >= 0 && frame - sigLastFrame >= 30) {
      if (FILE* sf = std::fopen("/tmp/rvk_dump_now", "rb")) {
        std::fclose(sf); std::remove("/tmp/rvk_dump_now");
        sigLastFrame = frame; dumpOps = true; fieldTrig = true; render = true;
        std::fprintf(stderr, "[rvk][sigdump] /tmp/rvk_dump_now consumed on frame%ld -> arena/DUMPRES armed\n", frame);
      }
    }
  }
  if (g_base && be32(GA_FIELD_ACTIVE) != 0) {
    static long fieldFrames = 0;
    ++fieldFrames;
    // Promote the triggered frame to sampled: under RT_COMPOSE the legacy pass runs mostly
    // unsampled (render=false takes the early return long before the DUMPRES block), so without
    // this the K-th-field-frame dump can never fire outside the default {8,16,24,40,60} samples.
    if (dumpFieldK >= 0 && fieldFrames == dumpFieldK) { dumpOps = true; fieldTrig = true; render = true; }
    // RVK_DEBUG_OPS_ROM=K (2026-07-16): same K-th-frame trigger, but counts frames where the ROM
    // scene is live (g_rt_romactive) rather than the guest field_active flag — the ATTRACT never sets
    // field_active, so RVK_DEBUG_OPS_FIELD could never arm the manifest on an attract frame (the
    // washed surface). Lets us dump the per-batch manifest of a washing attract frame.
    static long dumpRomK = std::getenv("RVK_DEBUG_OPS_ROM") ? std::strtol(std::getenv("RVK_DEBUG_OPS_ROM"), nullptr, 10) : -1;
    static long romFrames = 0;
    if (dumpRomK >= 0 && g_rt_romactive) { if (romFrames++ == dumpRomK) { dumpOps = true; fieldTrig = true; render = true; } }
    // RVK_ARENADUMP auto-trigger: once merged (RT_NAVREAL) signals the REAL held stage
    // (g_rt_realstage), mark EVERY field frame as triggered so the one-shot arena capture
    // (guarded by arenaDumped) lands on the first proper kick-arena frame (ndraw>=80, start in
    // the rt_alloc heap) without having to guess the K-th field frame. Only active under
    // RVK_ARENADUMP, so it never perturbs normal runs.
    if ((g_rt_realstage || std::getenv("RVK_ARENA_ANYFIELD")) && std::getenv("RVK_ARENADUMP")) { fieldTrig = true; render = true; }
  }
  static bool dumpedOps = false;
  std::unordered_map<uint32_t, uint32_t> opHist;   // TYPE3 op -> count
  std::unordered_map<uint32_t, uint32_t> regHist;  // TYPE0 base reg -> count

  // Hot-path getenv caching (2026-07-17, decode-phase bottleneck fix, part of the RVK_REGPROBE fix
  // above): these debug levers are checked once per TYPE0 PACKET or once per DRAW (not once per
  // frame), so with ndraw in the hundreds the uncached std::getenv() calls added up to a real slice
  // of the "other" decode-phase bucket (measured: tex/cst/vtx sub-phases together are <5% of decode,
  // so the walk-loop/draw-prep overhead this trims is the dominant remainder). All default OFF,
  // same as before — this only removes the redundant re-checks; behavior is unchanged either way.
  static bool pm4Desync  = std::getenv("RVK_PM4DESYNC")  != nullptr;
  static bool resolveAny = std::getenv("RVK_RESOLVE_ANY") != nullptr;
  static bool rejRes     = std::getenv("RVK_REJRES")     != nullptr;
  static bool dclsLog    = std::getenv("RVK_DCLS")       != nullptr;
  static bool rtfmtLog   = std::getenv("RVK_RTFMT")      != nullptr;
  static bool cyanDbg    = std::getenv("RVK_CYANDBG")    != nullptr;
  static bool resClsLog  = std::getenv("RVK_RESCLS")     != nullptr;
  uint32_t i = start;
  std::vector<uint64_t> ibStack;   // INDIRECT_BUFFER recursion: (return_i<<32)|return_end
  // [ibtrace] LEG-40d: trace INDIRECT_BUFFER descent at gameplay to find where the missing
  // 0xEEAD000 playfield content is (an IB RVK skips? a ring region outside the window?).
  static bool ibTrace = std::getenv("RVK_IBTRACE") != nullptr;
  bool ibT = ibTrace && frame > 6000 && frame < 6030;
  if (ibT) std::fprintf(stderr, "[ibtrace] frame%ld WINDOW [0x%X,0x%X) = %u dwords\n", frame, start, end, (end - start) / 4);
  // ★ RVK_SEGALIGN (FNF-7 walk-alignment discriminator, 2026-07-26) — MEASURE ONLY, DEFAULT OFF.
  // Everything else is now refuted: lengths match the guest's own declaration (objDw == latDw,
  // 2152/2152 segments), addresses never relocate, and a correct consumer runs an IB's WHOLE
  // declared range (vendored Xenia CP) so there is no terminator to stop at. What remains is that
  // hardware executes each kicked segment as its OWN bounded INDIRECT_BUFFER, restarting the parse
  // at that segment's base, while this walk concatenates all of them into one linear stream. If a
  // packet near a segment's tail declares a length that overruns the boundary, our walk resumes
  // INSIDE the next segment at the wrong offset and reinterprets real guest bytes as packets.
  // Test: for every segment boundary the walk crosses, record (i at first arrival) - (segment base).
  // 0 == the walk landed exactly on the boundary (equivalent to hardware's IB restart); >0 == it
  // stepped over and is parsing that segment at the wrong alignment. Also names the packet that
  // did the overrunning. Sampling point is the START of the walk: frame N's window is closed and
  // N+1 has not begun (the same correct sampling point the segSnap fix established).
  // ★ RVK_PREDLOG (FNF-7 §5b, 2026-07-26) — MEASURE ONLY, DEFAULT OFF.
  // This walk extracts only op/count from a TYPE3 header and never tests bit 0, the PREDICATE
  // bit; nor does it implement PM4_SET_BIN_MASK/SELECT[_LO/_HI] (0x50/0x51/0x60-0x63). The SDK CP
  // skips a predicated TYPE3 entirely when (bin_select & bin_mask) == 0
  // (rexglue-sdk/src/graphics/command_processor.cpp:876-886). If the phantom draw is predicated
  // and evaluates to SKIP while the legit draws evaluate to EXECUTE, hardware skips exactly what
  // we draw. Census only — no draw is added, removed or altered by any of this.
  uint64_t binMask = 0xFFFFFFFFull, binSelect = 0xFFFFFFFFull;   // SDK initial values
  long predTot = 0, predBitSet = 0, predWouldSkip = 0, binSets = 0;
  static bool predLog = std::getenv("RVK_PREDLOG") != nullptr;
  static bool segAlign = std::getenv("RVK_SEGALIGN") != nullptr;
  uint32_t saB[64], saDelta[64], saPrevPkt[64], saPrevHdr[64];
  uint8_t  saHit[64]; int saN = 0; uint32_t saWbase = 0;
  uint32_t saPrevAddr = 0, saPrevWord = 0;
  if (segAlign) {
    int sn = (int)g_seg_n; if (sn > 64) sn = 64; if (sn < 0) sn = 0;
    saWbase = (uint32_t)g_seg_wbase;
    for (int k = 1; k < sn; ++k) {           // boundary = entry point of segments 1..n-1
      saB[saN] = saWbase + g_seg_off[k];
      saDelta[saN] = 0; saPrevPkt[saN] = 0; saPrevHdr[saN] = 0; saHit[saN] = 0; ++saN;
    }
  }
  while (nv + 6 <= kMaxVerts && ni + 6 <= kMaxIndices) {
    if (i + 4 > end) {             // end of range -> pop back to caller INDIRECT_BUFFER, else done
      if (ibStack.empty()) break;
      if (ibT) std::fprintf(stderr, "[ibtrace] frame%ld IB-END depth=%zu (now ndraw=%d nresolves=%zu)\n", frame, ibStack.size(), ndraw, resolves.size());
      uint64_t v = ibStack.back(); ibStack.pop_back();
      i = (uint32_t)(v >> 32); end = (uint32_t)v; continue;
    }
    uint32_t w = be32(i); uint32_t t = w >> 30;
    // ★ RVK_SEGALIGN: first arrival at (or past) each segment boundary. Only at ibStack depth 0 —
    // inside an INDIRECT_BUFFER `i` lives in a different address space and would false-trigger.
    if (segAlign && ibStack.empty()) {
      for (int k = 0; k < saN; ++k)
        if (!saHit[k] && i >= saB[k]) {
          saHit[k] = 1; saDelta[k] = i - saB[k];
          saPrevPkt[k] = saPrevAddr; saPrevHdr[k] = saPrevWord;
        }
      saPrevAddr = i; saPrevWord = w;
    }
    // A ZERO dword at header position is a 1-dword NO-OP, not a TYPE0 write (SDK
    // rexglue-sdk command_processor.cpp:784-788 special-cases packet==0). We decoded it as
    // TYPE0 base=0 cnt=1 and ATE THE NEXT DWORD as reg-0 payload — a 4-byte PHASE SHIFT that
    // desyncs everything after it. Zeros are common stream padding, so this was a live desync
    // source (2026-07-16, Fable-5 consult against the SDK spec).
    if (w == 0) { i += 4; continue; }
    if (t == 0) {
      // TYPE0 header: [14:0] base reg index, [15] ONE_REG_WR, [29:16] count-1.
      // ONE_REG_WR (2026-07-16 fix): when set, ALL count dwords go to the SAME register (a FIFO/port
      // style burst); only when it is CLEAR do they walk reg, reg+1, ... We ignored bit 15 and always
      // incremented, so a one-reg burst got SPRAYED across its neighbours — writing its payload into
      // registers the guest never touched. That is how float COLOUR data ended up in RB_BLENDCONTROL0
      // (0x2201): observed blendRegs 0x3E808081/0x3E40C0C2/0x3EE0E0E2 are floats, exactly 64/255,
      // 48/255, 112/255. Those decode (:697-702) to src=ONE/dst=ZERO — an opaque quad that IGNORES
      // ALPHA — and 0x2201 is sticky, so every following draw inherits it until the guest rewrites it.
      // Cave glow/bubble sprites are white-cored with their falloff carried entirely in ALPHA, so
      // stripping alpha turns each quad into a solid white blob = the "regular GRID of blown-pure-white
      // blobs" wash. Matches Xenia's ExecutePacketType0: target = one_reg ? base : base + m.
      uint32_t reg = w & 0x7fff, cnt = ((w >> 16) & 0x3fff) + 1;
      bool oneRegWr = (w >> 15) & 1;
      // DESYNC GUARD (2026-07-16). RVK_REGPROBE caught the parser reading the FLOAT 1.0f
      // (0x3F800000) as a TYPE0 header: top bits 00 => TYPE0, base = 0x3F800000 & 0x7fff = 0,
      // cnt = ((0x3F800000>>16) & 0x3fff)+1 = 16257 — i.e. we walked off the real command stream into
      // a block of float DATA and sprayed 16257 dwords across registers 0x0..0x3F80. That silently
      // clobbers the whole register file; the visible casualty was RB_BLENDCONTROL0 (0x2201) landing
      // on float colours (0x3E808081 = 64/255 etc), which decode to src=ONE/dst=ZERO — an
      // alpha-IGNORING opaque quad — and 0x2201 is STICKY, so every later draw inherited it. Cave
      // glow sprites carry their falloff entirely in ALPHA, so alpha-ignored quads paint solid white
      // blobs = the "regular GRID of blown-pure-white blobs" wash.
      // A real TYPE0 burst writes a handful of consecutive registers; 16257 is not a command, it is
      // data. Treat an implausible count as desync and stop decoding this window rather than corrupt
      // the register file. NOTE: this is a CONTAINMENT guard, not the cure — the cure is to stop the
      // window from running past the guest's real commands (the LEG-27/40 ring-window work).
      // ★ DESYNC DIAGNOSTIC (2026-07-16) — RVK_PM4DESYNC=1 to observe, default OFF (report only).
      // RVK_REGPROBE caught this parser reading the FLOAT 1.0f (0x3F800000) as a TYPE0 header: top
      // bits 00 => TYPE0, base = 0x3F800000 & 0x7fff = 0, cnt = ((0x3F800000>>16)&0x3fff)+1 = 16257.
      // So we walk off the guest's real commands into a block of float DATA and spray 16257 dwords
      // across registers 0x0..0x3F80, silently clobbering the whole register file. The visible
      // casualty is RB_BLENDCONTROL0 (0x2201) landing on float colours (0x3E808081 = 64/255,
      // 0x3E40C0C2 = 48/255, 0x3EE0E0E2 = 112/255), which decode (:697-702) to src=ONE/dst=ZERO — an
      // alpha-IGNORING opaque quad — and 0x2201 is STICKY, so every later draw inherits it. Cave glow
      // sprites are white-cored with their falloff carried entirely in ALPHA, so alpha-ignored quads
      // paint solid white blobs: the "regular GRID of blown-pure-white blobs" wash (:699-704). This
      // ALSO explains why the wash survived both prior refutations — an opaque overwrite is
      // bit-identical in UNORM and SFLOAT (so RVK_HDR=0 ≡ RVK_HDR=1, as observed) and involves no
      // feedback sampling (so RVK_FBKILL changes nothing).
      // CONTAINMENT DOES NOT WORK — both were tried and REVERTED, do not retry naively:
      //   * `break` on an implausible packet  -> the TOP MENU VANISHED. The float data is INTERLEAVED
      //     with real commands, so abandoning the window drops every real draw after the first hit.
      //   * `i += 4; continue;` (resync by scan) -> rendered NOTHING at all (zero frames captured).
      // The cure is upstream: stop the decode window from covering non-command memory (the LEG-27/40
      // ring-window work). Guarding the symptom here only trades the wash for missing geometry.
      if (pm4Desync && cnt > 256) {
        static long dsN = 0;
        if (dsN++ < 20)
          std::fprintf(stderr, "[pm4] DESYNC: TYPE0 hdr=0x%08X base=0x%X cnt=%u (%.3ff) at +0x%X\n",
                       w, reg, cnt, bitf(w), i);
      }
      if (dumpOps) regHist[reg]++;
      // RVK_REGPROBE hot-path fix (2026-07-17): this breadcrumb snprintf ran UNCONDITIONALLY on
      // every TYPE0/SET_CONSTANT/LOAD_ALU_CONSTANT packet (hundreds-to-thousands/frame) even
      // though g_pm4Src is only ever read inside the regProbe-gated branch above. Gate the
      // formatting itself on regProbe (cached bool, no getenv) — off by default, so this whole
      // line now costs one bool check instead of a snprintf call. Byte-identical when RVK_REGPROBE
      // is set (still formats + assigns exactly as before).
      if (regProbe) { static char tb[80]; std::snprintf(tb,sizeof tb,"TYPE0(%s base=0x%X cnt=%u hdr=0x%08X)",
          oneRegWr?"one_reg":"seq", reg, cnt, w); g_pm4Src=tb; }
      { RvkClock::time_point pr0; if (perflog2) pr0 = RvkClock::now();
        for (uint32_t k = 0; k < cnt; ++k) writeReg(oneRegWr ? reg : reg + k, be32(i + 4 + k * 4));
        if (perflog2) p2Reg += rvkMs(pr0); }
      i += 4 * (1 + cnt);
    } else if (t == 3) {
      uint32_t op = (w >> 8) & 0x7f, cnt = ((w >> 16) & 0x3fff) + 1;
      if (dumpOps) opHist[op]++;
      if (op == 0x2D && cnt >= 2) { // SET_CONSTANT: dword1 = type<<16 | index, then values
        uint32_t offType = be32(i + 4);
        uint32_t idx = offType & 0x7FF, type = (offType >> 16) & 0xFF;
        uint32_t base = (type == 0) ? 0x4000 : (type == 1) ? 0x4800 : (type == 2) ? 0x4900 :
                        (type == 3) ? 0x4908 : (type == 4) ? 0x2000 : 0xFFFFFFFFu;
        if (regProbe && base != 0xFFFFFFFFu)   // breadcrumb only; NOTE the for below is unconditional (pre-existing)
          { static char sb[64]; std::snprintf(sb,sizeof sb,"SET_CONSTANT(type=%u,idx=0x%X,cnt=%u)",type,idx,cnt); g_pm4Src=sb; }
          { RvkClock::time_point pr0; if (perflog2) pr0 = RvkClock::now();
            for (uint32_t k = 0; k + 1 < cnt; ++k) writeReg(base + idx + k, be32(i + 8 + k * 4));
            if (perflog2) p2Reg += rvkMs(pr0); }
      } else if (op == 0x32 && cnt >= 3) { // LOAD_ALU_CONSTANT: {addr, type<<16|index, size_dwords}
        uint32_t maddr = be32(i + 4) & 0x3FFFFFFFu;
        uint32_t offType = be32(i + 8);
        uint32_t idx = offType & 0x7FF, type = (offType >> 16) & 0xFF;
        uint32_t szDw = be32(i + 12) & 0xFFFu;
        uint32_t base = (type == 0) ? 0x4000 : (type == 1) ? 0x4800 : (type == 2) ? 0x4900 :
                        (type == 3) ? 0x4908 : (type == 4) ? 0x2000 : 0xFFFFFFFFu;
        if (regProbe && base != 0xFFFFFFFFu && maddr)   // breadcrumb only; the for below is unconditional (pre-existing)
          { static char lb[64]; std::snprintf(lb,sizeof lb,"LOAD_ALU(type=%u,idx=0x%X,dw=%u)",type,idx,szDw); g_pm4Src=lb; }
          { RvkClock::time_point pr0; if (perflog2) pr0 = RvkClock::now();
            for (uint32_t k = 0; k < szDw; ++k) writeReg(base + idx + k, be32(maddr + k * 4));
            if (perflog2) p2Reg += rvkMs(pr0); }
      } else if (op == 0x50 || op == 0x51 || (op >= 0x60 && op <= 0x63)) {
        // ★ RVK_PREDLOG (FNF-7 §5b, 2026-07-26) — MEASURE ONLY, no behaviour change.
        // Track the PFP bin mask/select pair exactly as the SDK command processor does
        // (rexglue-sdk/src/graphics/command_processor.cpp:964-996; initial values
        // include/rex/graphics/command_processor.h:290-291 = 0xFFFFFFFF each, so the default
        // state PASSES). Nothing else in this walk consumes binMask/binSelect — they exist only
        // so the census below can evaluate the SDK's predicate test without altering any draw.
        if (op == 0x60)      binMask   = (binMask   & 0xFFFFFFFF00000000ull) |  be32(i + 4);
        else if (op == 0x61) binMask   = (binMask   & 0xFFFFFFFFull) | ((uint64_t)be32(i + 4) << 32);
        else if (op == 0x62) binSelect = (binSelect & 0xFFFFFFFF00000000ull) |  be32(i + 4);
        else if (op == 0x63) binSelect = (binSelect & 0xFFFFFFFFull) | ((uint64_t)be32(i + 4) << 32);
        else if (op == 0x50) binMask   = ((uint64_t)be32(i + 4) << 32) | be32(i + 8);   // hi, lo
        else if (op == 0x51) binSelect = ((uint64_t)be32(i + 4) << 32) | be32(i + 8);   // hi, lo
        ++binSets;
      } else if (op == 0x27) { // IM_LOAD
        uint32_t d0 = be32(i + 4), d1 = be32(i + 8);
        uint32_t addr = d0 & ~3u; uint32_t stype = d0 & 3u; uint32_t sizeDwords = d1 & 0xFFFF;
        { RvkClock::time_point pi0; if (perflog2) pi0 = RvkClock::now();
          matchImLoad(addr, stype, sizeDwords);
          if (perflog2) { p2Im += rvkMs(pi0); ++p2NIm; } }
      } else if (op == 0x22 || op == 0x36) {
        // LEG-40e ROOT CAUSE (Fable-5 advisor): the VGT_DRAW_INITIATOR dword is at a DIFFERENT
        // offset for the two DRAW opcodes. 0x22 DRAW_INDX = [viz-query][INITIATOR][idx_base][idx_size]
        // -> initiator @ i+8. 0x36 DRAW_INDX_2 = [INITIATOR][inline indices...] -> initiator @ i+4.
        // RVK hard-coded i+8 for BOTH -> every 0x36 draw (the bullet sprites + the static-blob
        // gameplay geometry, authored as DRAW_INDX_2) read a GARBAGE vertex count and got skipped
        // by the n∈[3,6] gate -> black playfield while 0x22 HUD/overlay rendered. RVK_DRAW2_OLD
        // forces the old i+8 for A/B.
        static bool draw2Old = std::getenv("RVK_DRAW2_OLD") != nullptr;
        uint32_t initOff = (op == 0x36 && !draw2Old) ? 4u : 8u;
        uint32_t initw = be32(i + initOff);
        uint32_t n = (initw >> 16) & 0xFFFF;
        uint32_t va = vf0 & ~3u;
        uint32_t drawPrim = initw & 0x3F;   // Xenos prim type (0 = the EDRAM-tile resolve trick)
        // LEG-40 ROOT CAUSE: RB_MODECONTROL (0x2208) reads kCopy during GAMEPLAY CONTENT quads
        // (n=4 sprites/bullets) as well as real resolves — so the old "(0x2208&7)==6 => resolve"
        // gate misclassified ~214 content quads/window as resolves and SKIPPED them, leaving the
        // playfield layer textures empty (composite samples black). REAL RB_COPY resolves are the
        // giant EDRAM-tile draw (n=49152, prim=0); content quads are prim=RECTLIST(8)/tri with
        // small n. Only classify as a resolve when it's the tile-resolve SHAPE, so content quads
        // render into the offscreen even while the mode reg looks like copy. RVK_RESOLVE_ANY
        // restores the old (over-eager) behavior for A/B.
        // (LEG-27/40 companion) resolve SHAPE threshold was n>6 back when the render gate
        // capped content at n<=6; with the gate widened (RVK_NMAX) a mid-size content draw in
        // kCopy mode must not be eaten as a resolve. Real tile-resolves are n=49152 / prim=0.
        static bool resFresh = std::getenv("RVK_RESFRESH") != nullptr;
        bool isRealResolve = (g_regFile[0x2208] & 7u) == 6u &&
          (resolveAny ? true : (n > 2048u || drawPrim == 0u ||
                                                    (resFresh && copyRegsFresh)));
        // RVK_REJRES (portrait-pool RE 2026-07-15): log kCopy draws REJECTED by the resolve gate
        // (mode==kCopy but shape/freshness gate said "content"). If the char-select per-portrait
        // 320x240 RB_COPY resolves land here, the pool never fills = the segmentation gap. Shows
        // n/prim/dest/dims/fresh so we can widen the gate precisely. Default off.
        if (rejRes && (g_regFile[0x2208] & 7u) == 6u && !isRealResolve) {
          static long rj = 0;
          if (rj++ < 300) std::fprintf(stderr, "[rejres] f%ld REJECTED-kCopy n=%u prim=%u vs=%d dst=0x%X %ux%u fresh=%d\n",
            frame, n, drawPrim, g_curVsIdx, g_regFile[0x2319], g_regFile[0x231A] & 0x3FFFu, (g_regFile[0x231A] >> 16) & 0x3FFFu, (int)copyRegsFresh);
        }
        copyRegsFresh = false;   // consumed: every draw resets freshness (LEG-45)
        if (isRealResolve) {
          // RB_MODECONTROL edram_mode == kCopy => this "draw" is an RB_COPY RESOLVE (EDRAM ->
          // guest texture). End the current pass; the render loop blits the offscreen into the
          // resolve texture at RB_COPY_DEST_BASE (0x2319, raw byte addr, no shift). Dims from
          // RB_COPY_DEST_PITCH (0x231A: w=&0x3FFF, h=(>>16)&0x3FFF).
          flushBatch(ni);
          uint32_t rdst = g_regFile[0x2319];
          uint32_t rw = g_regFile[0x231A] & 0x3FFFu, rh = (g_regFile[0x231A] >> 16) & 0x3FFFu;
          // REGISTER-TRUE RESOLVE DEST OFFSET (2026-07-21, ported from rexglue-sdk
          // draw_util::GetResolveInfo, draw.cpp ~820-1030): the true copy destination is
          // RB_COPY_DEST_BASE + GetTiledOffset2D(rect_x0 & ~granularity_mask, rect_y0 & ~mask,
          // copy_dest_pitch, bpp_log2) — the rect origin comes from the resolve draw's 3 vf0
          // vertices (+half-pixel, +window offset, aligned down to 8). Our decoder used the raw
          // base only, so SUB-RECT resolves registered at the wrong address (char-card painting:
          // the guest's second back-to-back resolve lands at base+0x8000 and the compose samples
          // exactly that; we registered base -> never-rendered -> RESALIAS lottery -> black card
          // interior). Full-target resolves have origin 0 = byte-identical. RVK_NORESDSTOFF=1
          // reverts. bpp_log2 from RB_COPY_DEST_INFO copy_dest_format (16bpp formats -> 1).
          static bool resDstOff = !(std::getenv("RVK_NORESDSTOFF") && std::atoi(std::getenv("RVK_NORESDSTOFF")) != 0);
          if (resDstOff && va && rw) {
            float hp = (g_regFile[0x2302] & 1u) ? 0.f : 0.5f;   // PA_SU_VTX_CNTL.pix_center
            int32_t x0 = INT32_MAX, y0 = INT32_MAX;
            for (int k5 = 0; k5 < 3; ++k5) {
              float fx = bef(va + (uint32_t)k5 * 8 + 0) + hp, fy = bef(va + (uint32_t)k5 * 8 + 4) + hp;
              int32_t ix = (int32_t)lroundf(fx * 256.f), iy = (int32_t)lroundf(fy * 256.f);
              x0 = std::min(x0, (ix + 127) >> 8); y0 = std::min(y0, (iy + 127) >> 8);
            }
            if (g_regFile[0x2205] & (1u << 16)) {                // vtx_window_offset_enable
              uint32_t wo = g_regFile[0x2080];                   // PA_SC_WINDOW_OFFSET (s15 x, s15 y@16)
              x0 += ((int32_t)(wo << 17)) >> 17;
              y0 += ((int32_t)(wo << 1)) >> 17;
            }
            if (x0 < 0) x0 = 0; if (y0 < 0) y0 = 0;
            x0 &= ~7; y0 &= ~7;                                  // kResolveAlignmentPixels
            uint32_t dfmt = (g_regFile[0x231B] >> 7) & 0x3Fu;    // RB_COPY_DEST_INFO.copy_dest_format
            uint32_t lb5 = (dfmt == 3u || dfmt == 4u || dfmt == 5u || dfmt == 15u) ? 1u : 2u;
            uint32_t gmask = (1u << (7u - std::min(2u, lb5))) - 1u;  // 2D tiled base granularity
            uint32_t bx5 = (uint32_t)x0 & ~gmask, by5 = (uint32_t)y0 & ~gmask;
            if (bx5 || by5) {
              uint32_t doff = tiledOff(bx5, by5, rw, lb5, rw);
              static long rdoN = 0;
              if (rdoN++ < 40) std::fprintf(stderr, "[resdstoff] f%ld base=0x%X rect0=(%d,%d) fmt=%u lb=%u -> +0x%X = 0x%X\n",
                frame, rdst, x0, y0, dfmt, lb5, doff, rdst + doff);
              rdst += doff;
            }
          }
          // RVK_RTFMT (2026-07-14, overexposure RE via rexglue-sdk): log the EDRAM color FORMAT the
          // guest declared for the target being resolved (RB_COLOR_INFO=0x2001: color_format=[19:16],
          // color_exp_bias=[25:20] signed). Format 3=k_2_10_10_10_FLOAT (7e3 [0,32) HDR), 6/7=16f. If
          // the FIELD target is float, our unconditional R8G8B8A8_UNORM offscreen/resolve CLIPS the
          // additive bloom to white = the wash. Diagnostic only, default off.
          if (rtfmtLog) {
            uint32_t ci = g_regFile[0x2001]; uint32_t cfmt = (ci >> 16) & 0xF;
            int ebias = (int)((ci >> 20) & 0x3F); if (ebias & 0x20) ebias -= 64;
            static std::unordered_map<uint64_t,int> rtfLogged;
            uint64_t k = ((uint64_t)rdst << 8) | cfmt;
            if (!rtfLogged.count(k)) { rtfLogged[k] = 1;
              const char* fn = cfmt==0?"8888":cfmt==1?"8888_GAMMA":cfmt==2?"2_10_10_10":cfmt==3?"2_10_10_10_FLOAT(7e3)":cfmt==4?"16_16":cfmt==5?"16_16_16_16":cfmt==6?"16_16_FLOAT":cfmt==7?"16_16_16_16_FLOAT":"?";
              std::fprintf(stderr, "[rtfmt] frame%ld resolve dst=0x%X %ux%u RB_COLOR_INFO=0x%X color_format=%u(%s) exp_bias=%d\n",
                frame, rdst, rw, rh, ci, cfmt, fn, ebias); }
          }
          // RVK_CYANDBG (2026-07-14; reg corrected 2026-07-19): the SDK honors RB_COPY_DEST_INFO
          // .copy_dest_swap + copy_dest_endian(bits0-2) when laying resolved EDRAM into guest RAM;
          // our port NEVER reads it. If the FIELD resolve carries swap/endian != 0 (BGRA byte
          // reorder) while menus carry 0, that would be the whole-field cyan (R<->B). Log per-dst.
          // FIX: read 0x231B (RB_COPY_DEST_INFO per tools/pm4/analyze.py) — the old 0x231C was the
          // WRONG register (never RB_COPY_DEST_INFO), so every prior swap datum was garbage.
          // Xenos xe_gpu_copy_dest_info_t fields (analyze.py:57-63): endian[0:2] array[3] slice[4:6]
          // fmt[7:12] number[13:15] bias[16:21] swap[25:26]. Canonical xenia reads swap at bit24;
          // log BOTH (swap25 = tree-authority, swap24 = xenia) so the capture decides.
          if (cyanDbg) {
            uint32_t di = g_regFile[0x231B];   // was 0x231C (wrong reg); 0x231B = RB_COPY_DEST_INFO
            static std::unordered_map<uint32_t,int> cyanResLogged;
            if (!cyanResLogged.count(rdst)) { cyanResLogged[rdst] = 1;
              std::fprintf(stderr, "[cyandbg][resolve] dst=0x%X %ux%u RB_COPY_DEST_INFO=0x%X endian=%u fmt=%u number=%u bias=%d swap25=%u swap24=%u\n",
                rdst, rw, rh, di, di & 7u, (di >> 7) & 0x3Fu, (di >> 13) & 7u, (int)((di >> 16) & 0x3Fu), (di >> 25) & 3u, (di >> 24) & 1u); }
          }
          // [rescls] LEG-40: is this a REAL RB_COPY resolve (big EDRAM-tile draw) or a real
          // CONTENT draw misclassified because RB_MODECONTROL stuck in kCopy? Log n + vs + va.
          if (resClsLog) {
            static long rc = 0;
            if (rc++ < 400) std::fprintf(stderr, "[rescls] frame%ld RESOLVE-CLASS n=%u vs=%d va=0x%X rdst=0x%X %ux%u mode2208=0x%X\n",
              frame, n, g_curVsIdx, va, rdst, rw, rh, g_regFile[0x2208]);
          }
          if (rdst && rw && rh && rw <= 2048 && rh <= 2048) {
            getOrCreateResolveTex(rdst, rw, rh);   // create target now so later composite samples route to it
            resolves.push_back({batches.size(), rdst, rw, rh});
          }
          curPipeline = VK_NULL_HANDLE; batchStart = ni;   // start a fresh pass (no batch merge across resolve)
        } else if (dclsLog && va && (n < 3 || n > (uint32_t)nGateMax())) {
          // [dcls] LEG-40b: draws with n outside [3,6] are SKIPPED by the content gate below.
          // If the missing 0xEEAD000 terrain is a large-vertex draw (n>6), it dies here. Log
          // n + vs/ps + prim so we can see if real gameplay geometry is being dropped.
          static long dc = 0;
          if (frame > 6000 && dc++ < 300) std::fprintf(stderr, "[dcls] frame%ld SKIP-DRAW n=%u vs=%d ps=%d prim=%u va=0x%X mode2208=0x%X tex=0x%X\n",
            frame, n, g_curVsIdx, g_curPsIdx, drawPrim, va, g_regFile[0x2208], ((g_regFile[0x4801] >> 12) & 0xFFFFF) << 12);
          i += 4 * (1 + cnt); continue;
        } else if (va && n >= 3 && n <= (uint32_t)nGateMax()) {
          // ★ WALK-LITE (2026-07-27 worker perf leg): on STATE-ONLY walks (render=false), skip
          // the content-draw body entirely. MEASURED: a "state-only" walk cost the SAME as a
          // full render minus GPU (14.2 vs 14.8ms) because it ran all of this — vertex extract,
          // texture lookups, batch build — whose outputs die with the per-frame arena. That
          // parity is what made backlog drains cost walk+render ≈ 31ms while windows arrive
          // every 16.7ms: one transition spike (measured 250-263ms texture-upload renders) and
          // the worker stabilizes in a degraded attractor (the user's 33-41% content collapse).
          // Cross-window STATE is fully preserved above this line: type-0 register/constant
          // writes (writeReg), IM_LOAD shader identity, and resolve classification+registration
          // (the isRealResolve branch). RVK_WALKFULL=1 restores full walks for A/B.
          // ⚠ the discriminator is the FRAME SENTINEL, not the render param: the worker passes
          // render=false on its RENDER call too (rendering fires via wantLast = real frame +
          // ndraw>0). Gating on !render starved real renders to 1.4ms empty frames (caught by
          // implausible-speed check 07-27; that profiled run is VOID). Backlog walks and the
          // keep-warm path are exactly the frame==-1000000 calls.
          static bool walkFull = std::getenv("RVK_WALKFULL") && atoi(std::getenv("RVK_WALKFULL")) != 0;
          if (frame == -1000000 && !walkFull) { i += 4 * (1 + cnt); continue; }
          // LEG-27/40 companion fix: the old n<=6 gate silently dropped every reclaimed
          // ring-window draw with more than 6 verts (dcls logged n=7 vs=5 gameplay-field
          // skips) -- the widened decode window is useless if the gate eats its draws.
          // RVK_NMAX=6 restores the old gate for A/B.
          if (nv + n + n / 3 + 4 > kMaxVerts || ni + 3 * n + 6 > kMaxIndices) { i += 4 * (1 + cnt); continue; }
          // RVK_BLEND=1: honor the guest per-draw blend (RB_BLENDCONTROL 0x2201) instead of a
          // hardcoded alpha blend — makes additive glow layers (colorDst=ONE) bright. The blend
          // is folded into the pipeline cache key so a blend change auto-starts a new batch.
          static bool useBlendReg = std::getenv("RVK_BLEND") != nullptr;
          uint32_t blendKey = useBlendReg ? g_regFile[0x2201] : 0;
          // RVK_DIMFIX (2026-07-23 dim-quad hunt): the shell modal-dialog DIM VEIL draws as an
          // n=3 fan sampling an unsupported 1x1 fmt-22 fetch (binds the white placeholder) with
          // vertex color = white at ramping sub-opaque alpha (0x17..0x29 seen) — a fade veil.
          // The sticky RB_BLENDCONTROL reads 0x10001 (ONE/ZERO opaque; PM4 stale-reg class) so
          // the veil paints SOLID WHITE fullscreen, hiding the menu dialogs. Signature-keyed:
          // unsupported-fmt 1x1 fetch + opaque blendKey => force the src-alpha lerp.
          static bool dimFix = std::getenv("RVK_DIMFIX") != nullptr;
          if (dimFix && useBlendReg && blendKey == 0x00010001u) {
            uint32_t dtf1 = g_regFile[0x4801], dtf2 = g_regFile[0x4802];
            uint32_t dfmt = dtf1 & 0x3F, dtw = (dtf2 & 0x1FFF) + 1, dth = ((dtf2 >> 13) & 0x1FFF) + 1;
            bool supported = (dfmt == 6 || dfmt == 2 || dfmt == 4 || dfmt == 26 || dfmt == 3);
            if (!supported && dtw == 1 && dth == 1) {
              blendKey = 0x07060706u;   // SRC_ALPHA/INV_SRC_ALPHA (blend-truth catalog)
              static long dl = 0; if (dl++ < 6)
                std::fprintf(stderr, "[dimfix] 1x1 fmt=%u white-fallback veil: blend 0x10001 -> 0x7060706\n", dfmt);
              // RVK_DUMP_ON_VEIL: arm the per-draw ops dump when the SUMMON veil appears (not
              // the boot white fallback) — lands the dump on the frames where the menu panels
              // exist. Distinct from RVK_DUMP_ON_WHITE (boot-early).
              extern bool g_dumpWhiteTrig; if (std::getenv("RVK_DUMP_ON_VEIL")) g_dumpWhiteTrig = true;
            }
          }
          // ★ FNF-3 (2026-07-26 diagnosis, 2026-07-27 SHIPPED). The TOP MENU's illustrated
          // background is ONE fullscreen rect-list draw. matchImLoad() keyed on the first 32 ucode
          // bytes + size ONLY and took the LOWEST index on a tie, so entry 2 (0x8203A508,
          // `out = sample * interp16`) won over the real one: byte-identical prefix, identical
          // size 60. Interpolator 16 is never written by the background's VS (o16 = 0,0,0,0), so
          // our own background draw multiplied by zero and WIPED THE RT TO BLACK (measured:
          // pre-draw mean 9.894 -> post-draw 0.000).
          // ⚠ THE CORRECT ENTRY IS 16 (0x8203D5E8, `out = sample * c2`), NOT 6. The 07-26 scope
          // doc inferred 6 from a SPIR-V shape argument; direct byte measurement refutes it — the
          // runtime blob is byte-exact to 16 (distance 0 vs 9/10 for 18/2/6), and the SDK's own
          // background PS ends `mul r2, r0, CB3[0]` = sample * const. Entry 6 has NO multiply, so
          // the 07-26 proof lever produced a correct-looking picture for the wrong reason (c2 is
          // ~0.9, the guest's own wall-dim factor, so entry 6 rendered ~11% too bright).
          // FIXED BY: the full-ucode FNV-1a-64 tiebreak in matchImLoad (see there). 22 of 51 table
          // entries were unreachable for this same prefix-collision reason; 6 became reachable.
          // Evidence: C:/tmp/fnf3_scope/FNF3_SCOPE.md, C:/tmp/fnf3_fix/IMPLEMENTATION_PLAN.md.
          int psIdxDraw = g_curPsIdx;
          {
            // FNF-3 A/B lever. Was RVK_BGPSFIX=1 (force ps=6) while the diagnosis was being
            // proven; the shipped full-ucode matcher now resolves this draw to ps=16 on its own,
            // so the lever takes the TARGET INDEX as its value and accepts either incoming ps.
            // (Left unwidened it could never fire again — a control that looks live and silently
            // does nothing, which is exactly the lying-instrument class this project keeps
            // getting burned by.)
            //   RVK_BGPSFIX=6   force the passthrough PS (the shape the 07-26 proof drive used;
            //                   NOTE it drops the `* c2` the hardware performs, so it renders
            //                   the background ~11% too bright when c2 = 0.9)
            //   RVK_BGPSFIX=2   force the broken `sample * interp16` PS (reproduces the defect)
            //   unset           ship path: whatever matchImLoad resolved (expect 16)
            static int bgPsFix = std::getenv("RVK_BGPSFIX") ? atoi(std::getenv("RVK_BGPSFIX")) : 0;
            if (bgPsFix > 0 && g_curVsIdx == 5 && (g_curPsIdx == 2 || g_curPsIdx == 16)) {
              psIdxDraw = bgPsFix;
              static long bgn = 0;
              if (bgn++ < 4) std::fprintf(stderr, "[bgpsfix] f%ld vs=%d ps=%d -> ps=%d (FNF-3 A/B lever)\n",
                                          frame, g_curVsIdx, g_curPsIdx, psIdxDraw);
            }
          }
          // RANK 21: RB_COLOR_MASK (0x2104) drives the pipeline's colorWriteMask (RT0), 1:1 nibble.
          RvkClock::time_point pp0; if (perflog2) pp0 = RvkClock::now();
          VkPipeline pipe = (g_curVsIdx >= 0 && psIdxDraw >= 0) ? getOrCreateRealPipeline(g_curVsIdx, psIdxDraw, blendKey, g_regFile[0x2104] & 0xFu) : VK_NULL_HANDLE;
          if (perflog2) { p2Pipe += rvkMs(pp0); ++p2NPipe; }
          if (!pipe) {   // shader not matched/compiled yet — skip this draw (log once per vs/ps pair, LEG-44)
            static std::set<int> sklog;
            int key = (g_curVsIdx << 8) ^ (g_curPsIdx & 0xFF);
            if (!sklog.count(key)) { sklog.insert(key);
              std::fprintf(stderr, "[rvk][skip] draw skipped: unmatched pipeline vs=%d ps=%d n=%u (further skips of this pair silent)\n", g_curVsIdx, g_curPsIdx, n); }
            i += 4 * (1 + cnt); continue;
          }

          if (g_vsDirty || !curVsBDA) {
            g_vsDirty = false;
            // RVK_C255: the asset sprite VS modulates by c255 (master fade/tint). If the guest
            // never sets it in our PM4 window it reads 0 -> everything black. Force to 1.0.
            // c255 = the asset VS's screen transform {posScale, uvScale, posOffset, -}:
            // oPos.xy = pos*x + z; uv = texel*y. Guest never sets it (lived in the original
            // container's definition table). RVK_C255=x:y:z:w overrides; bare "1" = legacy 1.0s.
            static int c255init = [&]{
              const char* e = std::getenv("RVK_C255"); if (!e) return 0;
              float x,y,z,w2;
              if (std::sscanf(e, "%f:%f:%f:%f", &x, &y, &z, &w2) == 4) { g_c255v[0]=x; g_c255v[1]=y; g_c255v[2]=z; g_c255v[3]=w2; }
              else if (atoi(e) == 1) { /* keep computed defaults */ }
              g_c255fix = 1;
              return 1;
            }();
            (void)c255init;
            // RVK_TRUE48: keep the GUEST c255 for the register-true class (vs=48, vte-disabled) —
            // a genuinely-zero guest c255 collapses the draw exactly as real hardware would.
            bool true48Here = rvkTrue48On() && g_curVsIdx == 48 && ((g_vteCntl & 0x1u) == 0u);
            std::memcpy(g_gdC255pre, &g_vsConstF[1020], 16); g_gdRescued = false;   // [gdprobe] shadow
            // ★ GHOST-DRAW FIX (2026-07-28, wf_b8847446 Arm A + [gdprobe] discriminator boot):
            // with the viewport transform DISABLED (vte bit0 clear), a genuinely-zero guest c255
            // collapses the draw on hardware — the guest's HIDE idiom (D1-B scale-0 at the
            // VS-constant level). The M2 loading-circle / TOP-MENU glyph ghosts are exactly this
            // class (vs=1 ps=2 n=4 vte=0x300, guest c255 all-zero); substituting c255 un-hid
            // them. Keep the guest zero for the class — every legit rescue client observed
            // carries vte bit0 SET (0x43F). Never silent: kept-count noted below, per-draw
            // mismatch counters at the bind site. RVK_C255ZRESCUE=1 restores the old rescue.
            static int c255zRescue = std::getenv("RVK_C255ZRESCUE") ? atoi(std::getenv("RVK_C255ZRESCUE")) : 0;
            bool vteCollapseHere = !c255zRescue && ((g_vteCntl & 0x1u) == 0u);
            if (g_c255fix && !true48Here && g_vsConstF[1020] == 0.f && g_vsConstF[1021] == 0.f && g_vsConstF[1022] == 0.f && g_vsConstF[1023] == 0.f) {
              if (vteCollapseHere) {
                static long kept = 0;
                if ((kept++ % 512) == 0)
                  std::fprintf(stderr, "[rvk][gdfix] c255 zero KEPT #%ld (vs=%d vte=0x%X) — guest collapse honored\n", kept, g_curVsIdx, g_vteCntl);
              } else {
                g_vsConstF[1020] = g_c255v[0]; g_vsConstF[1021] = g_c255v[1]; g_vsConstF[1022] = g_c255v[2]; g_vsConstF[1023] = g_c255v[3];
                g_gdRescued = true;   // [gdprobe] shadow
                static long fixed = 0;
                if ((fixed++ % 2000) == 0) std::fprintf(stderr, "[rvk] c255 zero -> set (%g,%g,%g,%g)\n", g_c255v[0], g_c255v[1], g_c255v[2], g_c255v[3]);
              }
            }
            RvkClock::time_point p2t0; if (perflog2) p2t0 = RvkClock::now();
            auto sl = arenaAlloc(4096); std::memcpy(sl.host, g_vsConstF, 4096); curVsBDA = sl.addr; curVsHost = (float*)sl.host;
            if (perflog2) { p2Cst += rvkMs(p2t0); ++p2NCstSnaps; }
            // RVK_NOHALVE=1: skip the clip-range halving (pair with RVK_FIXVP=1). The halving +
            // doubled currentViewport() is a clip-range fix for content whose matrix maps guest
            // pixels to ndc[0,2] (the replay/gameplay panel). The shell TITLE authors its matrix
            // to ndc[-1,1] already, so halving shrinks it to half size in the top-left. Skipping
            // it + FIXVP ({0,0,kW,kH}) maps the title 1:1 across the full 1280x720 frame.
            static bool noHalve = std::getenv("RVK_NOHALVE") != nullptr;
            // RVK_GPFIELD=1 (LEG-39 M2): the gameplay-field VS (idx 5/34) authors its matrix to
            // ndc[0,2] corner-origin (c0.x=0.5625, c3.w=360 -> ndc.x = x/640 for x in [0,1280]),
            // exactly the content the halve+doubled-currentViewport() path was built for. The
            // global RVK_NOHALVE (needed for the ndc[-1,1] front-end) shifts it off-screen. So
            // for these VS indices, FORCE the halve regardless of noHalve.
            static bool gpField = std::getenv("RVK_GPFIELD") != nullptr;
            bool fieldVs = gpField && (g_curVsIdx == 5 || g_curVsIdx == 34);
            // RVK_AUTONDC: decide the clip-range halve PER-DRAW from the matrix class instead of a
            // global lever. Corner-origin ndc[0,2] content (M2LibMatrix c3.w large, ~360) needs the
            // halve + doubled currentViewport(); centered ndc[-1,1] content (c3.w ~1) needs neither.
            // The front-end MIXES both in the same window (title = centered; menu bg = corner-origin,
            // one 0x4000 matrix write per frame), so a global NOHALVE/FIXVP correctly maps one and
            // streaks the other. c3.w = g_vsConstF[15] discriminates them.
            static bool autoNdc = std::getenv("RVK_AUTONDC") != nullptr;
            bool cornerOrigin = autoNdc && (g_vsConstF[15] > 4.f);
            bool skipHalve = autoNdc ? !cornerOrigin : (noHalve && !fieldVs);
            // RVK_TRUEVP: pass the guest matrix UNMODIFIED (no clip-range halve) — the register-true
            // viewport {-sx,-sy,2sx,2sy} (registerTrueViewport) absorbs the mapping instead.
            if (rvkTrueVpOn()) skipHalve = true;
            // vs=47 = the playfield-panel COMPOSITE quad. It carries guest PIXEL-space geometry
            // (corner-dump: V0=(-0.5,-0.5) .. a 512-tile), so the menu-tuned corner-origin clip-range
            // HALVE must not apply — halving c0/c1 composes with the SPIR-V invert-y into the observed
            // 180-degree panel flip. Keep the real M2LibMatrix. Menus never author vs=47, so gating on
            // it here leaves them byte-identical. RVK_NOVS47FIX=1 restores the old path for A/B.
            static bool noVs47Fix = std::getenv("RVK_NOVS47FIX") != nullptr;
            if (g_curVsIdx == 47 && !noVs47Fix) skipHalve = true;
            auto halvePosRows = [skipHalve](float* m) { if (skipHalve) return; for (int c = 0; c < 8; ++c) m[c] *= 0.5f; };  // clip-range fix (see currentViewport)
            // RVK_FORCEMTX=W:H — bypass the M2LibMatrix guess/repair entirely and install a
            // clean pixel[0,W]x[0,H] -> NDC ortho (w=1, no perspective). For captures whose
            // real projection lived in the GPU register file (not snapshotted), this proves the
            // real translated VS renders. Pair with RVK_FIXVP=1 (viewport {0,0,kW,kH}). RVK_MY
            // overrides the Y sign for the invert-y convention.
            static const char* forceMtxE = std::getenv("RVK_FORCEMTX");
            // leg 42: evaluate + record the predicate BEFORE any repair decision, so the census
            // and the default warning survive the repair being off (no short-circuit).
            const bool degenHere = matrixIsDegenerate(g_vsConstF);
            if (degenHere) rvkDegenNote(g_vsConstF, frame, ndraw, g_curVsIdx, n, bef(va), bef(va + 4), rvkMtxRepairOn());
            if (forceMtxE) {
              float fw = 1280.f, fh = 720.f; std::sscanf(forceMtxE, "%f:%f", &fw, &fh);
              static float my = std::getenv("RVK_MY") ? (float)atof(std::getenv("RVK_MY")) : -1.f;
              float* m = (float*)sl.host;
              m[0]=2.f/fw; m[1]=0;       m[2]=0; m[3]=-1.f;      // c0: clip.x = 2x/W - 1
              m[4]=0;      m[5]=my*2.f/fh;m[6]=0; m[7]=-my;      // c1: clip.y = my*(2y/H) - my
              m[8]=0;  m[9]=0;  m[10]=1.f; m[11]=0;              // c2: clip.z = z
              m[12]=0; m[13]=0; m[14]=0;  m[15]=1.f;             // c3: clip.w = 1
              curVsScreenBDA = curVsModelBDA = sl.addr; curVsDegen = false;
              curVsScreenHost = curVsModelHost = m;
            } else if (degenHere && rvkMtxRepairOn()) {   // 2026-07-26 D1-B: default OFF (see rvkMtxRepairOn/rvkDegenNote)
              repairMatrix((float*)sl.host, 0.f, 0.f);                       // screen-space variant
              halvePosRows((float*)sl.host);
              auto slm = arenaAlloc(4096); std::memcpy(slm.host, g_vsConstF, 4096);
              repairMatrix((float*)slm.host, g_xoffset, g_yoffset);          // model-space variant (+viewport center)
              halvePosRows((float*)slm.host);
              curVsScreenBDA = sl.addr; curVsModelBDA = slm.addr; curVsDegen = true;
              curVsScreenHost = (float*)sl.host; curVsModelHost = (float*)slm.host;
            } else {
              // RVK_AUTOVERT: the front-end mixes screen-space [0,W] verts (need the ndc[0,2]
              // clip-range halve) and centered [-W/2,W/2] verts (already ndc[-1,1]) under ONE
              // constant matrix, so a global halve/no-halve streaks one set. Build BOTH variants
              // and pick per-draw by vertex sign — reusing the degenerate screen/model selector
              // below (negative vert => centered/non-halved; all-positive => screen/halved) plus a
              // matching per-draw viewport.
              static bool autoVert = std::getenv("RVK_AUTOVERT") != nullptr;
              if (autoVert) {
                halvePosRows((float*)sl.host);                                        // screen (halved)
                auto slc = arenaAlloc(4096); std::memcpy(slc.host, g_vsConstF, 4096); // centered (NOT halved)
                curVsScreenBDA = sl.addr;  curVsModelBDA = slc.addr;  curVsDegen = true;
                curVsScreenHost = (float*)sl.host; curVsModelHost = (float*)slc.host;
              } else {
                halvePosRows((float*)sl.host);
                curVsScreenBDA = curVsModelBDA = sl.addr; curVsDegen = false;
                curVsScreenHost = curVsModelHost = (float*)sl.host;
              }
            }
            if (render && std::getenv("RVK_DEBUG_CONSTS"))
              std::fprintf(stderr, "[rvk][debug] draw%d snap c0=(%.4f,%.4f,%.4f,%.4f) c1=(%.4f,%.4f,%.4f,%.4f) c3=(%.4f,%.4f,%.4f,%.4f) degen=%d v0=(%.1f,%.1f) n=%u\n",
                ndraw, g_vsConstF[0],g_vsConstF[1],g_vsConstF[2],g_vsConstF[3], g_vsConstF[4],g_vsConstF[5],g_vsConstF[6],g_vsConstF[7],
                g_vsConstF[12],g_vsConstF[13],g_vsConstF[14],g_vsConstF[15], (int)curVsDegen, bef(va), bef(va + 4), n);
          }
          if (g_psDirty || !curPsBDA) { g_psDirty = false;
            // RVK_PSC: like RVK_C255 but for the pixel shader — force PS c0/c223 to 1.0 when
            // unset so tex-modulate PSes don't multiply to black.
            static int pscfix = std::getenv("RVK_PSC") ? atoi(std::getenv("RVK_PSC")) : 0;
            if (pscfix) {
              if (g_psConstF[0]==0.f && g_psConstF[1]==0.f && g_psConstF[2]==0.f && g_psConstF[3]==0.f)
                g_psConstF[0]=g_psConstF[1]=g_psConstF[2]=g_psConstF[3]=1.0f;
              if (g_psConstF[892]==0.f && g_psConstF[893]==0.f && g_psConstF[894]==0.f && g_psConstF[895]==0.f)
                g_psConstF[892]=g_psConstF[893]=g_psConstF[894]=g_psConstF[895]=1.0f;
            }
            RvkClock::time_point p2t0; if (perflog2) p2t0 = RvkClock::now();
            auto sl = arenaAlloc(3584); std::memcpy(sl.host, g_psConstF, 3584); curPsBDA = sl.addr;
            if (perflog2) { p2Cst += rvkMs(p2t0); ++p2NCstSnaps; } }

          // degenerate-matrix repair: choose screen vs model variant by the draw's verts
          if (curVsDegen) {
            bool model = false;
            for (uint32_t k = 0; k < n && !model; ++k)
              if (bef(va + k * 24) < 0.f || bef(va + k * 24 + 4) < 0.f) model = true;
            curVsBDA = model ? curVsModelBDA : curVsScreenBDA;
            curVsHost = model ? curVsModelHost : curVsScreenHost;
          }

          // idx48's c255 IS its screen transform. In the MENU the guest reuses the c255 reg
          // slot as a COLOR for the sibling sprite shader between idx48 draws (observed
          // {0,0.376,1.0,0.88}, then zeros) — pos*0+1.0 collapses every idx48 vertex to one
          // point, which is why menu draws vanished under EVERY viewport. The all-zero-only
          // force misses those states, so deliver OUR transform on every idx48 draw via a
          // patched copy of the current constants snapshot (cached per source snapshot).
          uint64_t drawVsBDA = curVsBDA;
          // RVK_C255PROBE (2026-07-14, terrain-render RE): on the field-trigger frame, log each
          // vs=48 draw's GUEST c255 + sampled base + first vert, so we can see whether the terrain
          // tiles (0x120F7000/0x12117000) carry a DIFFERENT c255 (scroll transform) than the
          // sprites/HUD — the c255 clobber below forces them all to g_c255v, which would collapse
          // any tile whose real transform differs.
          if (fieldTrig && g_curVsIdx == 48 && curVsHost && std::getenv("RVK_C255PROBE")) {
            uint32_t pbase = ((tf[1] >> 12) & 0xFFFFF) << 12;
            static int cpl = 0; if (cpl++ < 40)
              std::fprintf(stderr, "[rvk][c255probe] vs48 base=0x%X guestC255={%.5f,%.5f,%.5f,%.5f} clobbered=%d (g_c255v={%.5f,%.5f,%.5f,%.5f})\n",
                pbase, curVsHost[1020], curVsHost[1021], curVsHost[1022], curVsHost[1023],
                std::memcmp(curVsHost + 1020, g_c255v, 16) != 0 ? 1 : 0,
                g_c255v[0], g_c255v[1], g_c255v[2], g_c255v[3]);
          }
          // RVK_C255KEEPBIG (Round-12 char-select portrait diagnosis 2026-07-15): the c255 clobber
          // below forces the global menu/HUD sprite transform g_c255v onto EVERY vs=48 draw. The
          // large multi-quad character-portrait sprites (n>4) are the draws that shear into the
          // on-window diagonal solid-colour bands at char/shot select (proven: RVK_ATLASSKIP=2
          // removing exactly these draws removes the bands). This lever TESTED the hypothesis that
          // the clobber overwrites a valid guest c255 on the big sprites -> REFUTED: =1 (keep guest
          // c255 for n>4) left the diagonal bands IDENTICAL on-window. So c255 is NOT the shear
          // source; the shear is in the M2LibMatrix / degenerate-repair + vertex-sign variant
          // selection (2297-2350) applied to these big mixed-sign-vertex sprites. Kept env-gated,
          // default off (byte-identical) to document the refutation.
          // RVK_C255KEEPBIG: 1 = keep guest c255 for big sprites (n>4); 2 = keep it for ALL vs=48
          // (2026-07-16 test: the ATTRACT/field white grid is the vs=48 FONT-TEXT quads rendering white
          // — RVK_ATLASSKIP=2 drops the panel from 76.6% white to 1.3%, and the font texture 0x12917000
          // decodes to a clean font atlas offline. So the quads sample white because their UV TRANSFORM
          // is wrong; the c255 clobber forces the menu/HUD g_c255v onto every vs=48 draw. =2 tested
          // whether these text quads need their OWN guest c255 — RESULT: panel stayed 76.6% white,
          // UNCHANGED. So c255 is NOT the cause; the wrong UVs live in the VERTEX DATA itself (the
          // RT_VTXSNAP vertex-volatility class — these quads' vertices/UVs are read from recycled guest
          // scratch at present time). Kept as a documented refutation.
          static int c255KeepBig = std::getenv("RVK_C255KEEPBIG") ? std::atoi(std::getenv("RVK_C255KEEPBIG")) : 0;
          bool keepGuestC255 = (c255KeepBig == 2) || (c255KeepBig == 1 && n > 4);
          bool true48Clob = rvkTrue48On() && ((g_vteCntl & 0x1u) == 0u);   // register-true class: never clobber
          g_gdClobbered = false;   // [gdprobe] shadow: per-draw reset
          g_gdTookA = false;       // census keying: per-draw reset
          if (g_c255fix && g_curVsIdx == 48 && curVsHost && !keepGuestC255 && !true48Clob &&
              std::memcmp(curVsHost + 1020, g_c255v, 16) != 0) {
            if (c255PatchSrc != curVsBDA) {
              auto p2 = arenaAlloc(4096); std::memcpy(p2.host, curVsHost, 4096);
              std::memcpy((float*)p2.host + 1020, g_c255v, 16);
              c255PatchSrc = curVsBDA; c255PatchOut = p2.addr;
              static long pl = 0;
              if ((pl++ % 4000) == 0)
                std::fprintf(stderr, "[rvk] c255 snapshot patched for idx48 (guest c255={%g,%g,%g,%g})\n",
                  curVsHost[1020], curVsHost[1021], curVsHost[1022], curVsHost[1023]);
            }
            drawVsBDA = c255PatchOut;
            g_gdClobbered = true;   // [gdprobe] shadow
          }
          // ★ GHOST-DRAW FIX, per-draw enforcement (2026-07-28 leg 2: the build-time gate alone
          // FAILED acceptance — all 16 collapse-class draws REUSE a snapshot built for an earlier
          // vport draw, so build-time vte is the wrong draw's vte; the MISMATCH-A counter caught
          // it). Policy is decided HERE from THIS draw's vte, patching the bound snapshot when it
          // disagrees (same per-window patch-cache pattern as the idx48 clobber above).
          // Direction A: collapse-class draw (vte bit0 clear) whose snapshot was zero-rescued
          //   gets the guest's own c255 back (zero -> hardware-true collapse; the ghost fix).
          // Direction B: vport draw on a kept-zero snapshot gets the substitute (old rescue
          //   semantics; protects legit sprites from the build-time keep).
          // RVK_C255ZRESCUE=1 disables both = the exact pre-fix pipeline for A/B.
          if (curVsHost) std::memcpy(g_gdEffC255, curVsHost + 1020, 16);
          else std::memcpy(g_gdEffC255, &g_vsConstF[1020], 16);
          {
            static int c255zRescue2 = std::getenv("RVK_C255ZRESCUE") ? atoi(std::getenv("RVK_C255ZRESCUE")) : 0;
            if (!c255zRescue2 && curVsHost && !g_gdClobbered) {
              bool gdVteClear = (g_vteCntl & 0x1u) == 0u;
              const float* gdSc = curVsHost + 1020;
              bool gdSnapZero = gdSc[0] == 0.f && gdSc[1] == 0.f && gdSc[2] == 0.f && gdSc[3] == 0.f;
              if (gdVteClear && g_gdRescued) {
                if (gdPatchASrc != curVsBDA) {
                  auto pg = arenaAlloc(4096); std::memcpy(pg.host, curVsHost, 4096);
                  std::memcpy((float*)pg.host + 1020, g_gdC255pre, 16);
                  gdPatchASrc = curVsBDA; gdPatchAOut = pg.addr;
                }
                drawVsBDA = gdPatchAOut;
                std::memcpy(g_gdEffC255, g_gdC255pre, 16);
                static long ra = 0;
                if ((ra++ % 512) == 0) std::fprintf(stderr, "[rvk][gdfix] per-draw A #%ld: guest c255 restored for collapse-class draw (vs=%d vte=0x%X)\n", ra, g_curVsIdx, g_vteCntl);
                g_gdTookA = true;   // census keying
              } else if (!gdVteClear && gdSnapZero && g_c255fix) {
                if (gdPatchBSrc != curVsBDA) {
                  auto pg = arenaAlloc(4096); std::memcpy(pg.host, curVsHost, 4096);
                  std::memcpy((float*)pg.host + 1020, g_c255v, 16);
                  gdPatchBSrc = curVsBDA; gdPatchBOut = pg.addr;
                }
                drawVsBDA = gdPatchBOut;
                std::memcpy(g_gdEffC255, g_c255v, 16);
                static long rb = 0;
                if ((rb++ % 512) == 0) std::fprintf(stderr, "[rvk][gdfix] per-draw B #%ld: substitute c255 enforced for vport draw on kept-zero snapshot (vs=%d)\n", rb, g_curVsIdx);
              }
            }
          }

          uint32_t base = ((tf[1] >> 12) & 0xFFFFF) << 12;
          uint32_t tw = (tf[2] & 0x1FFF) + 1, th = ((tf[2] >> 13) & 0x1FFF) + 1, fmt = tf[1] & 0x3F;
          // RVK_TFDUMP (Round-18 char-portrait fmt-3 untiling RE 2026-07-15): log ALL SIX fetch-constant
          // dwords for each distinct sampled fmt-3 256x256 portrait-range base, one-shot. dword_1 carries
          // the ENDIANNESS field (bits 6..7) that getTexIndexReal ignores (it always be16-swaps) -- the
          // prime suspect for why 0x17xxxxxx pages shred while 0x12xxxxxx pages decode clean. Diagnostic.
          if (std::getenv("RVK_TFDUMP") && fmt == 3 && tw == 256 && th == 256 &&
              base >= 0x12000000u && base < 0x18100000u) {
            static std::unordered_map<uint32_t,int> tfLogged;
            if (!tfLogged.count(base)) { tfLogged[base] = 1;
              std::fprintf(stderr, "[tfdump] base=0x%08X %ux%u fmt=%u | tf0=%08X tf1=%08X tf2=%08X tf3=%08X tf4=%08X tf5=%08X"
                " || tiled=%u pitch=%u endian=%u baseaddr>>12=0x%05X\n",
                base, tw, th, fmt, tf[0], tf[1], tf[2], tf[3], tf[4], tf[5],
                (tf[0] >> 31) & 1u, ((tf[0] >> 22) & 0x1FFu) << 5, (tf[1] >> 6) & 3u, (tf[1] >> 12) & 0xFFFFF); }
          }
          // RVK_WASHTF (2026-07-16, post-Fable SDK-spec): dump the FULL SDK-relevant fetch constant for
          // the wash texture(s) — ANY vs=48 fmt-3 draw — with the fields the SDK untiler agent flagged
          // as the remaining suspects for a pow2-pitch texture: STACKED (dword_1 bit10 → data in later
          // 4KB-aligned array slices we never decode) and MIP_ADDRESS/DIMENSION (dword_5 → base_page==0
          // means content lives at mip≥1 with pow2 strides). Our getTexIndexReal ignores BOTH.
          // RVK_WASHTF=<hex base> (2026-07-22, char-card hunt): if the value parses as a hex guest
          // address > 0x1000 the probe becomes BASE-TARGETED (like RVK_VS48BASEDUMP/RVK_VS5BASEDUMP)
          // -- log the full tf0..tf5 set + derived fields for THAT base on every (re)decode, bypassing
          // the 24-base cap that hid 0x12634000 (a char-select texture that boot never fills into the
          // first 24 slots). RVK_WASHTF=1 keeps the legacy everything-capped-at-24 sweep.
          static const char* washtfEnv = std::getenv("RVK_WASHTF");
          static uint32_t washtfBase = washtfEnv ? (uint32_t)strtoul(washtfEnv, nullptr, 16) : 0u;
          if (washtfEnv && fmt == 3) {
            bool washtfTargeted = washtfBase > 0x1000u;
            static std::unordered_map<uint32_t,int> wl;
            // Targeted mode: dedup on tf-change (stderr is unbuffered since 26967b9 -- an
            // every-draw print at the held card would throttle the guest like the old PNG bug).
            static uint32_t washtfLast[6] = {0,0,0,0,0,0}; static uint32_t washtfSeen = 0;
            bool hit;
            if (washtfTargeted) {
              hit = (base == washtfBase);
              if (hit) { washtfSeen++;
                hit = std::memcmp(washtfLast, tf, 6*sizeof(uint32_t)) != 0;
                if (hit) std::memcpy(washtfLast, tf, 6*sizeof(uint32_t)); }
            } else hit = (wl.size() < 24 && !wl.count(base));
            if (hit) {
              if (!washtfTargeted) wl[base] = 1;
              uint32_t stacked = (tf[1] >> 10) & 1u, dimen = (tf[5] >> 9) & 3u, packedMips = (tf[5] >> 11) & 1u;
              uint32_t stackDepth = ((tf[2] >> 26) & 0x3Fu) + 1u, mipAddr = ((tf[5] >> 12) & 0xFFFFF) << 12;
              std::fprintf(stderr, "[washtf] base=0x%08X seen=%u %ux%u fmt=3 tiled=%u pitch=%u | STACKED=%u stackDepth=%u dim=%u packedMips=%u mipAddr=0x%08X | tf0=%08X tf1=%08X tf2=%08X tf3=%08X tf4=%08X tf5=%08X\n",
                base, washtfSeen, tw, th, (tf[0] >> 31) & 1u, ((tf[0] >> 22) & 0x1FFu) << 5,
                stacked, stackDepth, dimen, packedMips, mipAddr, tf[0], tf[1], tf[2], tf[3], tf[4], tf[5]);
            }
          }
          RvkClock::time_point p2texT0; if (perflog2) p2texT0 = RvkClock::now();
          rvkFetchRawNote(tf, base, tw, th, fmt, "segman");
          uint32_t texIdx = getTexIndexReal(base, tw, th, fmt, tf[0], g_regFile[0x2201], tf[3]);
          if (perflog2) { p2Tex += rvkMs(p2texT0); ++p2NTexCalls; }
          // RVK_FBDECAY=<0..1> (2026-07-14, terrain-feedback-diagnosis workflow wf_669b5fbc): the
          // stage-1 terrain background is a per-frame FEEDBACK/echo pass — a vs=5/ps49 draw that
          // SAMPLES the playfield resolve (0xEEAD000) ITSELF and additively (colorDst=ONE) blends it
          // back, so EEAD(N)=terrain+EEAD(N-1) — a linear runaway that clips to white (only became
          // visible after this session's RESREAL black-fallback closed the loop). ps49 is identity
          // (out=tex*gain, gain=c1.x=1), so scaling the FEEDBACK draw's gain by d<1 turns it into a
          // convergent series EEAD(N)=d·EEAD(N-1)+terrain -> terrain/(1-d) (bounded). Gate: the
          // feedback quad SAMPLES A RESOLVE TARGET (g_resolveTex has base); the terrain SOURCE
          // samples guest-RAM (0x6321000, not a resolve) so it's untouched, as are sprites/bullets/
          // HUD (vs=48/ps=3) and menu/wallpaper. Per-draw decayed PS-const copy; default off.
          // [segman] RE (2026-07-14): the ACTUAL per-frame self-feedback into 0xEEAD000 is a vs=47
          // COMPOSITE draw (batch0, full-screen, samples 0xEEAD000 itself) — NOT the vs=5 draw the
          // first hypothesis targeted (which is why d=0 on vs=5 did nothing). Widen the gate to
          // vs=47 too. Both composite shaders read gain=c1.x, so scaling it decays the fed-back
          // sample. RVK_FBKILL routes the vs=47/5 self-sample to a black-cleared resolve instead
          // (return-black), the decisive "is the terrain fresh-drawn or frozen echo?" test.
          uint64_t drawPsBDA = curPsBDA;
          static const char* fbKillEnv = std::getenv("RVK_FBKILL");
          if (fbKillEnv && (g_curVsIdx == 47 || g_curVsIdx == 5) && g_resolveTex.count(base)) {
            // route the self-feedback sample to an 8x8 never-rendered (black-cleared) target:
            // if the terrain then disappears it was pure frozen echo; if fresh terrain shows,
            // the composite was overwriting good content with the stale wash.
            texIdx = getOrCreateResolveTex(0xEB000008u, 8, 8).idx;
          }
          // RVK_BGKILL=0xADDR (2026-07-14, overexposure RE): the vs=5 field-BG draw samples the BRIGHT
          // dynamic present buffer 0xF005000 (NOT a resolve, so FBKILL/FBDECAY above MISS it — they gate
          // on g_resolveTex.count(base) && ps==49; the bg is ps=2) at 2x vp and blends it ADDITIVELY ->
          // washes the field white. Route that specific bg sample to the 8x8 BLACK target: if the white
          // recedes and terrain shows clean, the vs=5 additive bg is the wash source. Default off.
          static uint32_t bgKill = [](){ const char* e = std::getenv("RVK_BGKILL"); return e ? (uint32_t)std::strtoul(e, nullptr, 0) : 0u; }();
          if (bgKill && g_curVsIdx == 5 && base == bgKill) {
            texIdx = getOrCreateResolveTex(0xEB000008u, 8, 8).idx;
            static int bgkLog = 0; if (bgkLog++ < 3)
              std::fprintf(stderr, "[rvk][bgkill] frame%ld vs=5 bg base=0x%X -> black (wash-source test)\n", frame, base);
          }
          static const char* fbDecayEnv = std::getenv("RVK_FBDECAY");
          if (fbDecayEnv && (g_curVsIdx == 5 || g_curVsIdx == 47) && g_curPsIdx == 49 && g_resolveTex.count(base)) {
            static float fbDecay = (float)atof(fbDecayEnv);
            float dps[896]; std::memcpy(dps, g_psConstF, 3584);
            dps[4] = (dps[4] == 0.f ? 1.f : dps[4]) * fbDecay;   // c1 = psC.v[1]; c1.x = gain = dps[4]
            auto sld = arenaAlloc(3584); std::memcpy(sld.host, dps, 3584); drawPsBDA = sld.addr;
            static int fbLog = 0; if (fbLog++ < 3)
              std::fprintf(stderr, "[rvk][fbdecay] frame%ld feedback draw vs=5 ps=49 base=0x%X (resolve) gain->%.3f\n", frame, base, (double)dps[4]);
          }
          // RVK_TEXLOG: log each unique texture base the first frame it is sampled, so we can
          // see across the whole boot which atlases actually reach a decoded draw (e.g. is the
          // CAVE/M2 logo atlas 0x0A6F1000 ever drawn, or only the text/title atlases?).
          static bool texLog = std::getenv("RVK_TEXLOG") != nullptr;
          if (texLog) {
            static std::unordered_map<uint32_t,int> seenBases;
            if (!seenBases.count(base)) { seenBases[base] = 1;
              std::fprintf(stderr, "[rvk][texlog] frame%ld NEW tex base=0x%X %ux%u fmt=%u vs=%d ps=%d\n",
                frame, base, tw, th, fmt, g_curVsIdx, g_curPsIdx); }
            // LEG-45: the color-filter PS (idx 49) draws the terrain/background layers — log
            // every base it samples (once per base) so the magenta background source is
            // identifiable even when another ps touched the base first.
            static std::unordered_map<uint32_t,int> seen49;
            if (g_curPsIdx == 49 && !seen49.count(base)) { seen49[base] = 1;
              std::fprintf(stderr, "[rvk][texlog49] frame%ld ps49 tex base=0x%X %ux%u fmt=%u vs=%d texIdx=%u n=%u\n",
                frame, base, tw, th, fmt, g_curVsIdx, texIdx, n); }
          }

          // RVK_C255DBG: per-draw c255 (const255 = float const[1020..1023]) correlation probe for
          // the MENU field-color investigation. c255 is dual-purposed (screen transform for some
          // VS, reused as a sprite COLOR by others). Log each distinct (vs,ps,tex,nonzero-mask)
          // combo once with the raw guest c255 snapshot, so we can see whether the bg field draw
          // (tex=10) reads the teal color {0,0.376,1,0.88}, zeros, or a transform. Diagnostic only.
          static bool c255dbg = std::getenv("RVK_C255DBG") != nullptr;
          if (c255dbg) {
            float* c = &g_vsConstF[1020];
            unsigned nz = (unsigned)((c[0]!=0.f) | ((c[1]!=0.f)<<1) | ((c[2]!=0.f)<<2) | ((c[3]!=0.f)<<3));
            unsigned long key = ((unsigned long)(g_curVsIdx & 0xFF) << 24)
                              | ((unsigned long)(g_curPsIdx & 0xFF) << 16)
                              | ((unsigned long)(texIdx & 0xFFF) << 4) | nz;
            static std::set<unsigned long> seen255;
            if (seen255.insert(key).second && seen255.size() <= 256)
              std::fprintf(stderr, "[c255dbg] f%ld vs=%d ps=%d tex=%u n=%u v0=(%.1f,%.1f) c3w=%.1f c255={%.4f,%.4f,%.4f,%.4f}\n",
                frame, g_curVsIdx, g_curPsIdx, texIdx, n, bef(va), bef(va + 4), g_vsConstF[15], c[0], c[1], c[2], c[3]);
          }

          // RVK_VTELOG: per-draw PA_CL_VTE_CNTL correlation probe (LEG-35). Hypothesis: the
          // guest toggles the VTE offset-enable bits per layer — offset-ENABLED for centered
          // ndc[-1,1] content (title/menu/HUD overlay), offset-DISABLED (0x300) for corner-
          // origin ndc[0,2] content (gameplay playfield). If vte discriminates the two draw
          // populations, the per-draw viewport can be keyed on it (real-HW semantics:
          // screen = (offset_ena ? offset : 0) + scale*ndc) and the global NOHALVE/FIXVP
          // levers become unnecessary.
          static bool vteLog = std::getenv("RVK_VTELOG") != nullptr;
          if (vteLog) {  // NOTE: not gated on `render` — that param is false for the
                         // RVK_RENDER_FROM frames (doRender/wantLast decide later); gating on it
                         // sampled only the first few boot frames.
            static long vl = 0; ++vl;
            if (vl <= 600 || (vl % 89) == 0)
              std::fprintf(stderr, "[rvk][vte] f%ld d%d vte=0x%X vs=%d ps=%d v0=(%.1f,%.1f) n=%u tex=0x%X\n",
                frame, ndraw, g_vteCntl, g_curVsIdx, g_curPsIdx, bef(va), bef(va + 4), n,
                ((tf[1] >> 12) & 0xFFFFF) << 12);
            // [gpdraw2] LEG-39 M2: focused dump of the GAMEPLAY draws (vs 5/34/48) — c255, the
            // active matrix c0/c1/c3, first vertex, and predicted screen pixel. Tells whether
            // the playfield transform is a wrong c255 (LEG-26 saw it squished under a menu-tuned
            // c255) or a wrong/degenerate matrix. Only these VS indices carry the playfield.
            if ((g_curVsIdx==5 || g_curVsIdx==34 || g_curVsIdx==48) && (vl % 20)==0) {
              float vx=bef(va), vy=bef(va+4);
              float c0=g_vsConstF[1020], c1=g_vsConstF[1021], c2=g_vsConstF[1022], c3=g_vsConstF[1023];
              std::fprintf(stderr, "[gpdraw2] f%ld vs=%d ps=%d vte=0x%X v0=(%.1f,%.1f) c255={%.5f,%.5f,%.2f,%.2f} mtx c0=(%.4f,%.4f,%.4f,%.4f) c1=(%.4f,%.4f,%.4f,%.4f) c3=(%.4f,%.4f,%.4f,%.4f) xs=%.0f xo=%.0f\n",
                frame, g_curVsIdx, g_curPsIdx, g_vteCntl, vx, vy, c0,c1,c2,c3,
                g_vsConstF[0],g_vsConstF[1],g_vsConstF[2],g_vsConstF[3],
                g_vsConstF[4],g_vsConstF[5],g_vsConstF[6],g_vsConstF[7],
                g_vsConstF[12],g_vsConstF[13],g_vsConstF[14],g_vsConstF[15], g_xscale, g_xoffset);
            }
          }
          // RVK_TRUEVP: register-true host viewport (offset+-scale from VTE regs), guest matrix
          // passed unmodified (skipHalve forced above). Replaces the doubled currentViewport() for
          // the non-vs48 legacy classes; vs=47 keeps its spriteViewport override below (offset+scale
          // WITH the VTE offset — already register-true), and rvkTrue48 (vs=48) keeps its px->ndc
          // epilogue path downstream. Default ON (rvkTrueVpOn); RVK_TRUEVP=0 restores the heuristic.
          VkViewport drawVp = rvkTrueVpOn() ? registerTrueViewport() : currentViewport();
          // RVK_SPRITEVP=1: idx48 sprite draws get the hardware-true offset+scale viewport
          // (see spriteViewport()); shell/matrix draws keep the doubled clip-fix viewport.
          static bool spriteVp = std::getenv("RVK_SPRITEVP") != nullptr;
          if (spriteVp && g_curVsIdx == 48) {
            drawVp = spriteViewport();
            static int svLog = 0;
            if (svLog++ < 3)
              std::fprintf(stderr, "[rvk] spriteVp: xs=%.0f xo=%.0f ys=%.0f yo=%.0f -> vp={%.0f,%.0f,%.0f,%.0f}\n",
                g_xscale, g_xoffset, g_yscale, g_yoffset, drawVp.x, drawVp.y, drawVp.width, drawVp.height);
          }
          // RVK_FIXVP=1: ignore guest viewport-scale regs and pin every draw to the standard
          // full-target viewport. Diagnostic for draws vanishing under the 2x viewport
          // ({-1280,-720,2560,1440}) that the guest sets for some layers (menu text) while our
          // forced c255 transform assumes the 1x mapping.
          static bool fixVp = std::getenv("RVK_FIXVP") != nullptr;
          if (fixVp) { drawVp = VkViewport{0.f, 0.f, (float)kW, (float)kH, 0.f, 1.f}; }
          // RVK_GPFIELD: the gameplay-field VS (5/34) uses the doubled currentViewport() that
          // pairs with the forced halve above (maps ndc[0,2]/halved -> full frame). Override the
          // front-end FIXVP for exactly those draws. (matches the halve decision at matrix snap.)
          // NOTE: gpFieldVp/autoNdcVp/autoVertVp/vteVp are RVK_TRUEVP=0-world diagnostics — they
          // pair a currentViewport()/doubled rect with the HALVED matrix. Under RVK_TRUEVP the
          // matrix is passed UNMODIFIED (skipHalve), so a doubled rect would render 2x — gate them
          // OFF so registerTrueViewport stays authoritative. (vs=47's spriteViewport override below
          // is NOT gated: it's the composite fork's real placement, kept under the lever.)
          static bool gpFieldVp = std::getenv("RVK_GPFIELD") != nullptr;
          if (!rvkTrueVpOn() && gpFieldVp && (g_curVsIdx == 5 || g_curVsIdx == 34)) {
            drawVp = currentViewport();
            static long gvLog = 0;
            // RVK_FIELDMANIFEST: full per-draw dump of the field layers (vs=5/34) on ONE frame —
            // ps, sampled texture base+dims+fmt (is it a resolve?), blend reg, viewport — to
            // identify which draws paint the washed terrain background and what they sample.
            static bool manifest = std::getenv("RVK_FIELDMANIFEST") != nullptr;
            if (manifest && render && gvLog < 40) {
              bool isRes = g_resolveTex.count(base) > 0;
              std::fprintf(stderr, "[rvk][fieldman] f%ld draw%d vs=%d ps=%d tex=0x%X %ux%u fmt=%u%s blend=0x%X vp={%.0f,%.0f,%.0f,%.0f}\n",
                frame, ndraw, g_curVsIdx, g_curPsIdx, base, tw, th, fmt, isRes ? "(RES)" : "", g_regFile[0x2201], drawVp.x, drawVp.y, drawVp.width, drawVp.height);
              gvLog++;
            } else if (!manifest && gvLog++ < 6)
              std::fprintf(stderr, "[rvk] gpFieldVp draw%d vs=%d -> vp={%.0f,%.0f,%.0f,%.0f}\n",
                ndraw, g_curVsIdx, drawVp.x, drawVp.y, drawVp.width, drawVp.height);
          }
          // RVK_AUTONDC viewport: pair the per-draw halve decision above with the matching viewport.
          // Corner-origin ndc[0,2] draws -> doubled currentViewport(); centered ndc[-1,1] -> full
          // frame. Authoritative when set (overrides FIXVP/GPFIELD), keyed on the same c3.w.
          static bool autoNdcVp = std::getenv("RVK_AUTONDC") != nullptr;
          if (!rvkTrueVpOn() && autoNdcVp) {
            drawVp = (g_vsConstF[15] > 4.f) ? currentViewport()
                                            : VkViewport{0.f, 0.f, (float)kW, (float)kH, 0.f, 1.f};
          }
          // RVK_AUTOVERT viewport: pair the per-draw halve choice — centered verts (non-halved,
          // ndc[-1,1]) get the full frame; screen-space verts (halved, ndc[0,2]) get the doubled vp.
          static bool autoVertVp = std::getenv("RVK_AUTOVERT") != nullptr;
          if (!rvkTrueVpOn() && autoVertVp) {
            bool centered = false;
            for (uint32_t k = 0; k < n && !centered; ++k)
              if (bef(va + k * 24) < 0.f || bef(va + k * 24 + 4) < 0.f) centered = true;
            drawVp = centered ? VkViewport{0.f, 0.f, (float)kW, (float)kH, 0.f, 1.f} : currentViewport();
          }
          // RVK_VTEVP=1 (LEG-39 render unification): per-draw viewport keyed on PA_CL_VTE_CNTL,
          // real-HW semantics. vte=0x43F (bits0-5 = XYZ viewport scale/offset ENABLES) = the VS
          // outputs true ndc and the hardware applies screen = offset + scale*ndc -> use the
          // hardware-true viewport (spriteViewport) built from the live PA_CL_VPORT_* regs.
          // vte=0x300 (XY_FMT/Z_FMT, no enables) = pre-transformed front-end content -> keep the
          // FIXVP/front-end mapping. Applied AFTER fixVp so the gameplay playfield wins.
          static bool vteVp = std::getenv("RVK_VTEVP") != nullptr;
          if (!rvkTrueVpOn() && vteVp && (g_vteCntl & 0x3Fu) == 0x3Fu) {
            drawVp = spriteViewport();
            static long vvLog = 0;
            if (vvLog++ < 6)
              std::fprintf(stderr, "[rvk] vteVp draw%d vte=0x%X vs=%d: xs=%.0f xo=%.0f ys=%.0f yo=%.0f -> vp={%.0f,%.0f,%.0f,%.0f}\n",
                ndraw, g_vteCntl, g_curVsIdx, g_xscale, g_xoffset, g_yscale, g_yoffset,
                drawVp.x, drawVp.y, drawVp.width, drawVp.height);
          }
          // vs=47 composite: hardware-true offset+scale viewport (SDK draw.cpp:400-418), placed LAST
          // so it overrides the front-end FIXVP / doubled-currentViewport / VTEVP levers. The panel
          // placement is carried by the quad verts + M2LibMatrix + THIS viewport; the doubled
          // currentViewport() mis-scales/rotates it and paints it full-frame. Menus never author
          // vs=47. RVK_NOVS47FIX=1 disables for A/B.
          static bool noVs47FixVp = std::getenv("RVK_NOVS47FIX") != nullptr;
          if (g_curVsIdx == 47 && !noVs47FixVp) {
            drawVp = spriteViewport();
            static int v47Log = 0;
            if (v47Log++ < 4)
              std::fprintf(stderr, "[rvk] vs47 composite vp: xs=%.0f xo=%.0f ys=%.0f yo=%.0f -> vp={%.0f,%.0f,%.0f,%.0f}\n",
                g_xscale, g_xoffset, g_yscale, g_yoffset, drawVp.x, drawVp.y, drawVp.width, drawVp.height);
          }
          // RVK_COMPCTR (LEG-47, 2026-07-14): CENTER the vs=47 panel composite. The guest renders the
          // resolved 640x512 playfield at {0,0,640,512} (top-left) — correct for a 640x512 INTERMEDIATE
          // target, but this port composites straight to the 1280x720 screen, so it lands top-left with
          // a black margin. No guest draw re-places that intermediate into a centered 1280x720 frame
          // (the SDK's 0x660000 bezel composite) on this path, so synthesize the pillarboxed placement
          // from the guest viewport: center the panel in the frame (x=(kW-w)/2, y=(kH-h)/2). Env-gated,
          // default OFF (byte-identical). Only meaningful with RVK_COMPSEG+RVK_COMPVS47 (the composite-
          // segment display path); under RVK_DISPLAYALL the full-frame terrain layers dominate anyway.
          static bool compCtr = std::getenv("RVK_COMPCTR") != nullptr;
          if (compCtr && g_curVsIdx == 47) {
            drawVp.x = (float)(kW - (uint32_t)drawVp.width) * 0.5f;
            drawVp.y = (float)(kH - (uint32_t)drawVp.height) * 0.5f;
            static int ccLog = 0;
            if (ccLog++ < 4)
              std::fprintf(stderr, "[rvk] compCtr: vs47 panel centered -> vp={%.0f,%.0f,%.0f,%.0f}\n",
                drawVp.x, drawVp.y, drawVp.width, drawVp.height);
          }
          // Honor the fetch constant's mag filter (tf[3] bits 19-20: 0=POINT, 1=LINEAR): POINT
          // selects the NEAREST sampler in bindless slot 1. Fixes the CAVE-logo-card tile grid
          // seams (LINEAR bled adjacent glyph-atlas cells at every 32px tile edge). The SDK
          // honors these bits; we never did. RVK_TFFILTER=0 restores always-LINEAR.
          static bool tfFilter = !(std::getenv("RVK_TFFILTER") && atoi(std::getenv("RVK_TFFILTER")) == 0);
          uint32_t samplerIdx = (tfFilter && ((tf[3] >> 19) & 3) == 0) ? 1u : 0u;
          // ★ RVK_TFCLAMP (2026-08-03): ClampX (tf0 [12:10]) 2+ -> CLAMP_TO_EDGE slots 2/3
          // (mirrors the nvk-path fix; see sampler-creation comment). RVK_TFCLAMP=0 reverts.
          static const bool tfClampOffW = [](){ const char* e = std::getenv("RVK_TFCLAMP"); return e && e[0]=='0' && !e[1]; }();
          if (!tfClampOffW && tf[0] && (((tf[0] >> 10) & 7u) >= 2u)) samplerIdx += 2u;
          static uint32_t curSmpIdxForBatch = 0xFFFFFFFFu;
          bool newBatch = (pipe != curPipeline) || (texIdx != curTexIdxForBatch) ||
                          (g_curVsIdx != curVsIdxForBatch) || (g_curPsIdx != curPsIdxForBatch) ||
                          (drawVsBDA != curVsBDAForBatch) || (drawPsBDA != curPsBDAForBatch) ||
                          (samplerIdx != curSmpIdxForBatch) ||
                          std::memcmp(&drawVp, &curVp, sizeof drawVp) != 0;
          if (newBatch) {
            flushBatch(ni);
            curSmpIdxForBatch = samplerIdx;
            uint8_t sc[512]; std::memset(sc, 0, sizeof sc);
            std::memcpy(sc + 0, &texIdx, 4);              // smpColorMap Texture2D index (s0)
            std::memcpy(sc + 192, &samplerIdx, 4); // smpColorMap sampler index (s0)
            static int boolfeed = std::getenv("RVK_BOOL") ? atoi(std::getenv("RVK_BOOL")) : 0;
            if (boolfeed) std::memcpy(sc + 256, &g_boolConst0, 4); // g_Booleans (c16.x)? — regressed when always-on; verify layout via HLSL first
            float half[2] = {0.f, 0.f}; std::memcpy(sc + 264, half, 8);
            // Alpha test (REGISTER-TRUE, 2026-07-18 black-box fix): Xenos RB_COLORCONTROL is reg
            // 0x2202 (bit3 = ALPHA_TEST_ENABLE, bits[2:0] = ALPHA_FUNC; 0x2201 = RB_BLENDCONTROL0
            // right beside it) and RB_ALPHA_REF is reg 0x210E (float). The old code read 0x2100 —
            // NOT a Xenos alpha-test register — so athresh was effectively never armed. The demo's
            // multiplicative shadow/light quads (blend 0x04000400 = dst*src.rgb, page 0x1632B000)
            // REQUIRE the alpha-test kill of their mask padding (a multiply blend cannot protect
            // dst via alpha), which is why they rendered as the attract-demo BLACK BOXES.
            // The ps discard is `o.a < athresh` (= pass on a >= thresh, the GREATEREQUAL family);
            // funcs 4 (GREATER) / 6 (GREATEREQUAL) map directly; other funcs are logged once and
            // left un-emulated (none observed in this title). RVK_ATEST=0 reverts to the legacy
            // 0x2100 read; RVK_ATHRESH=<f> still force-overrides for A/B.
            static const bool atestTrue = !(std::getenv("RVK_ATEST") && atoi(std::getenv("RVK_ATEST")) == 0);
            uint32_t colorCtl = g_regFile[atestTrue ? 0x2202 : 0x2100];
            bool atEnable = (colorCtl >> 3) & 1; uint32_t atFunc = colorCtl & 7;
            float athresh = 0.f;
            if (atEnable && atFunc != 7) {
              if (atestTrue) {
                float aref; uint32_t rv = g_regFile[0x210E]; std::memcpy(&aref, &rv, 4);
                if (atFunc == 6) athresh = aref;                       // GREATEREQUAL: pass a >= ref
                else if (atFunc == 4) athresh = aref + 1.f / 512.f;    // GREATER: pass a > ref
                else {
                  static std::set<uint32_t> fnWarned;
                  if (fnWarned.insert(atFunc).second)
                    std::fprintf(stderr, "[rvk][atest] unemulated ALPHA_FUNC %u (colorCtl=0x%X ref reg=0x%X) — no discard\n",
                                 atFunc, colorCtl, g_regFile[0x210E]);
                }
                static bool armedLogged = false;
                if (!armedLogged && athresh > 0.f) { armedLogged = true;
                  std::fprintf(stderr, "[rvk][atest] ARMED: colorCtl=0x%X func=%u ref=%.4f (first armed batch)\n", colorCtl, atFunc, aref); }
              } else athresh = 0.5f;
            }
            if (const char* ae = std::getenv("RVK_ATHRESH")) athresh = (float)atof(ae);
            std::memcpy(sc + 272, &athresh, 4);
            auto sl = arenaAlloc(512); std::memcpy(sl.host, sc, 512);
            curSharedBDA = sl.addr;
            curPipeline = pipe; curTexIdxForBatch = texIdx;
            curVsIdxForBatch = g_curVsIdx; curPsIdxForBatch = g_curPsIdx;
            curVsBDAForBatch = drawVsBDA; curPsBDAForBatch = drawPsBDA;
            curVp = drawVp;
            curVteForBatch[0] = g_xscale; curVteForBatch[1] = g_xoffset;
            curVteForBatch[2] = g_yscale; curVteForBatch[3] = g_yoffset;
            curVteCntlForBatch = g_vteCntl;
            curBlendForBatch = g_regFile[0x2201];
            curTexBaseForBatch = base; curTexFmtForBatch = fmt;
            curVsHostForBatch = curVsHost;
            // Blend constants: RB_BLEND_RED..ALPHA (0x2105-0x2108), float-typed registers the guest
            // animates for CONSTANT_* blend-factor fades. Captured per batch; RVK_NOBLENDCONST=1
            // keeps the old zeroed constants for A/B.
            static bool noBlendConst = std::getenv("RVK_NOBLENDCONST") != nullptr;
            if (noBlendConst) { curBc[0] = curBc[1] = curBc[2] = curBc[3] = 0.f; }
            else for (int c = 0; c < 4; ++c) {
              float f; uint32_t rv = g_regFile[0x2105 + c]; std::memcpy(&f, &rv, 4);
              curBc[c] = (f >= 0.f && f <= 1.f) ? f : (f > 1.f ? 1.f : 0.f);  // clamp; garbage regs read as bounds
            }
            batchStart = ni;
          }
          // RVK_VS5DUMP (tile-ring vertex-stride RE 2026-07-19): raw guest dwords of vs=5 n=6
          // draws (the ring-slot downscale quad class) so the true stride/layout can be solved
          // from the stream itself instead of inferred from the scrambled canonical verts.
          static bool vs5dump = std::getenv("RVK_VS5DUMP") != nullptr;
          if (vs5dump && g_curVsIdx == 5 && n >= 20 && n <= 160) {
            static long v5d = 0;
            if (v5d++ < 12) {
              std::fprintf(stderr, "[vs5dump] f%ld n=%u prim=%u va=0x%X tex=0x%X vp={%.0f,%.0f,%.0f,%.0f}\n",
                frame, n, drawPrim, va, base, drawVp.x, drawVp.y, drawVp.width, drawVp.height);
              for (int dwi = 0; dwi < 28; ++dwi) {
                uint32_t dv = be32(va + dwi * 4); float df; std::memcpy(&df, &dv, 4);
                std::fprintf(stderr, "[vs5dump]   dw%02d %08X %.4f\n", dwi, dv, df);
              }
            }
          }
          uint32_t v0 = nv;
          // idx48 sprite verts are 4-dword {x,y,u,v} INTEGER records, STRIDE 16 (corner-dump
          // proven: uv span == pixel span). Float-format records (old 24B layout) still appear
          // in the same windows — discriminate by dword0's float exponent.
          bool i48int = false;
          if (g_curVsIdx == 48) {
            uint32_t ex = be32(va) & 0x7F800000u;
            i48int = !(ex >= 0x38000000u && ex <= 0x47000000u);
          }
          // vs=47 gameplay sprite: the guest vertex is STRIDE 28 = {x,y,z,w,color,u,v}
          // (corner-dump proven: V0=(-0.5,-0.5)uv(0,0) V1=(511.5,-0.5)uv(1,0) V2=(-0.5,511.5),
          // a clean 512-tile quad). The real translated pipeline expects the 24B normalized
          // {pos.xyz, color@12, uv@16}, so drop w and pack. RVK_VS47=N overrides the stride
          // (0 disables) for empirical tuning.
          // RVK_VS47: default STRIDE-28 (2026-07-14 REAL credited-gameplay capture, refutes the
          // old "bad-state" note). The live composite draw (vs=47 ps=2, base 0xFA5D000 640x512
          // playfield resolve) decodes cleanly ONLY at stride 28: at stride 24 dword3 reads the
          // W component (3F800000=1.0) as the packed color and the UVs shear into dword4/5 garbage
          // -> the composite samples the wrong texels / a bogus color. At stride 28 the same draw
          // is a clean 640x480 pixel-space quad V0=(-0.5,-0.5)uv(0,0) V1=(639.5,-0.5)uv(1,0)
          // V2=(-0.5,479.5), color=0xFF808080. RVK_VS47=0 (or =24) restores the old stride-24 path.
          static int vs47stride = std::getenv("RVK_VS47") ? atoi(std::getenv("RVK_VS47")) : 28;
          bool vs47 = (g_curVsIdx == 47) && vs47stride >= 28;
          // RVK_BIGSPRITEFIX (Round-13 char/shot-select portrait shear, 2026-07-15): the big
          // multi-quad vs=48 portrait sprites are STRIDE-24 float {x,y,z=0,color=0xFFFFFFFF,u,v}
          // records (same family as the vs=47 composite), NOT the stride-16 int {x,y,u,v} the
          // i48int heuristic assumes. i48int keys on be32(va)'s float exponent; when va lands on the
          // record's z field (0x00000000) or an x==0.0, it misreads the record as int-16 -> the
          // float bytes of every later vertex (e.g. 0x4282FFFF=65.5) become ~1.1e9 ints that fly
          // off-atlas -> the diagonal solid-colour bands (proven: RVK_SHEARDBG dumped v1=(1.1e9,1.1e9)
          // for the i48int=1 draws vs clean rects for i48int=0). The guest fetch base (va) lands on a
          // VARYING phase of the 24-byte record between frames, so locate x via the unambiguous
          // z(0x0)/color(0xFFFFFFFF) anchor (record offset +8/+12): x = anchorDword - 2. Only draws
          // carrying that anchor take this path, so the small int-16 HUD sprites/menus are untouched.
          // Default ON (the shear is a hard defect at char/shot-select); RVK_NOBIGSPRITEFIX=1 restores
          // the old i48int/stride-16 path for A/B. Self-validating gate: a draw is only re-decoded if
          // it literally carries the stride-24 {..,z=0,color=0xFFFFFFFF,..} signature, so menus (proven
          // 1:1) and int-16 sprites stay byte-identical.
          static bool bigSpriteFix = !std::getenv("RVK_NOBIGSPRITEFIX");
          int bsfPhase = -999;   // byte offset from va to the x field; -999 = not a stride-24 portrait
          if (bigSpriteFix && g_curVsIdx == 48 && n >= 6) {
            for (int p = 0; p < 6; ++p)
              if (be32(va + p * 4) == 0x00000000u && be32(va + p * 4 + 4) == 0xFFFFFFFFu) { bsfPhase = (p - 2) * 4; break; }
          }
          // RVK_VS48BASEDUMP=<hex texbase> (blend-attribution probe): raw dwords + gate state +
          // LIVE BLEND REG for vs=48 draws sampling the given base (card-painting hunt).
          static uint32_t vs48BaseDump = std::getenv("RVK_VS48BASEDUMP")
            ? (uint32_t)strtoul(std::getenv("RVK_VS48BASEDUMP"), nullptr, 16) : 0u;
          if (vs48BaseDump && g_curVsIdx == 48 && base == vs48BaseDump) {
            static long v48bd = 0;
            if (v48bd++ < 12) {
              std::fprintf(stderr, "[vs48base] f%ld n=%u prim=%u va=0x%X tex=0x%X i48int=%d bsfPhase=%d blend=0x%X\n",
                frame, n, drawPrim, va, base, (int)i48int, bsfPhase, g_regFile[0x2201]);
            }
          }
          // RVK_NOVS5RECT disables (tile-ring stride fix 2026-07-19, vs5dump-proven): the ring-slot
          // downscale rect (vs=5 RECTLIST n=3 sampling the playfield resolve; guest rect
          // (0,0)-(640,480) uv (0,0)-(1,0.9375)) is a STRIDE-16 float {x,y,u,v} record. The default
          // stride-24 {x,y,z,color,u,v} decode scrambles it into a degenerate sliver that rasterizes
          // ZERO fragments => blitResolve stomps pure clear into every 320x240 ring tile ("black
          // ring"; the ORACLE attract capture attract_frame13949 shows all 91 tiles = full panel
          // downscale at cb~146-156). Signature-gated per record: plausible pixel xy + NORMALIZED uv
          // at stride 16 — a real stride-24 record's z/color dwords read as float fail the uv range
          // check, so the working vs=5 wallpaper/composite quads cannot false-positive.
          static bool vs5rectFix = !std::getenv("RVK_NOVS5RECT");
          // RVK_VS5RECTALL (2026-07-19 stride sweep follow-up): extend the stride-16 rect decode
          // to NON-resolve texture bases. The sweep's only other hit is the every-frame full-screen
          // rect (0,0)-(1280,720) sampling 0xF005000 — the guest's LIVE LANDSCAPE COMPOSE
          // FRAMEBUFFER (WALLBG=5 A/B-proven: its content is the rotated game frame, NOT the
          // wallpaper). The rect is the guest's frame-base RESTORE draw (repaint the previous
          // composed frame, then draw content over it) — the register-true counterpart of the
          // RVK_PERSIST heuristic (which the e64c9a5 study proved INERT in the ship recipe).
          // DEFAULT ON since 2026-07-20 (RVK_VS5RECTALL=0 reverts): the Reco-painting stride
          // check swept menus+select+charselect-browse+attract with this on — sweep shows the
          // restore class decoded and NO other candidate misdecodes; select HUD blink normal;
          // field tile-vs-panel gate neutral. The b0 panel-base restore (0xF005000 -> 640x512
          // panel segment) decodes under the same gate.
          static bool vs5rectAll = [](){ const char* e = std::getenv("RVK_VS5RECTALL");
            return e ? std::atoi(e) != 0 : true; }();
          // RVK_VS5BASEDUMP=<hex tex base> (select settle-composite RE 2026-07-20): raw guest
          // dwords of every vs=5 draw sampling the given base, ANY n. RVK_VS5DUMP's n>=20 gate
          // structurally excludes the n=3 RECTLIST class ("b118" = 14 aggregated n=3 draws,
          // indexCount 84 — an aggregate, not one draw), which is why it logged zero hits there.
          // Logs prim + resolve-tracked so the vs5rect16 gate rejection reason falls out of the data.
          static uint32_t vs5BaseDump = std::getenv("RVK_VS5BASEDUMP")
            ? (uint32_t)strtoul(std::getenv("RVK_VS5BASEDUMP"), nullptr, 16) : 0u;
          if (vs5BaseDump && g_curVsIdx == 5 && base == vs5BaseDump) {
            static long v5b = 0;
            if (v5b++ < 24) {
              std::fprintf(stderr, "[vs5base] f%ld n=%u prim=%u va=0x%X tex=0x%X isRes=%d vp={%.0f,%.0f,%.0f,%.0f}\n",
                frame, n, drawPrim, va, base, (int)g_resolveTex.count(base),
                drawVp.x, drawVp.y, drawVp.width, drawVp.height);
              for (int dwi = 0; dwi < 24; ++dwi) {
                uint32_t dv = be32(va + dwi * 4); float df; std::memcpy(&df, &dv, 4);
                std::fprintf(stderr, "[vs5base]   dw%02d %08X %.4f\n", dwi, dv, df);
              }
            }
          }
          // RVK_WALLDUMP=1 (Reco-painting stride check 2026-07-20): raw guest dwords of vs=5
          // draws sampling a PLAIN (non-resolve) texture under the deep-negative 2x-zoom
          // viewport — the WALLBG=3 discriminator for the guest's true wallpaper/Reco-art
          // compose quad ("rendered BLACK" 07-15; suspicion: a vertex-stride victim like the
          // ring rect (stride-16) / border matte (stride-12), not a viewport calibration issue).
          static bool wallDump = std::getenv("RVK_WALLDUMP") != nullptr;
          if (wallDump && g_curVsIdx == 5 && drawVp.x <= -512.f && !g_resolveTex.count(base)) {
            static long wdN = 0;
            static std::set<uint32_t> wdSeen;
            if (wdN < 12 && wdSeen.insert(base ^ (n << 28)).second) {
              ++wdN;
              std::fprintf(stderr, "[walldump] f%ld n=%u prim=%u va=0x%X tex=0x%X %ux%u fmt=%u vp={%.0f,%.0f,%.0f,%.0f}\n",
                frame, n, drawPrim, va, base, tw, th, fmt, drawVp.x, drawVp.y, drawVp.width, drawVp.height);
              for (int dwi = 0; dwi < 24; ++dwi) {
                uint32_t dv = be32(va + dwi * 4); float df; std::memcpy(&df, &dv, 4);
                std::fprintf(stderr, "[walldump]   dw%02d %08X %.4f\n", dwi, dv, df);
              }
            }
          }
          bool vs5rect16 = false;
          if (vs5rectFix && g_curVsIdx == 5 && n == 3 && drawPrim == 8 && (g_resolveTex.count(base) || vs5rectAll)) {
            vs5rect16 = true;
            for (uint32_t k5 = 0; k5 < n && vs5rect16; ++k5) {
              uint32_t t0 = be32(va + k5 * 16 + 0), t1 = be32(va + k5 * 16 + 4), t2 = be32(va + k5 * 16 + 8), t3 = be32(va + k5 * 16 + 12);
              float xf, yf, uf, vf;
              std::memcpy(&xf, &t0, 4); std::memcpy(&yf, &t1, 4); std::memcpy(&uf, &t2, 4); std::memcpy(&vf, &t3, 4);
              if (!(xf >= -2048.f && xf <= 2048.f && yf >= -2048.f && yf <= 2048.f &&
                    uf >= -0.01f && uf <= 1.01f && vf >= -0.01f && vf <= 1.01f)) vs5rect16 = false;
            }
            if (vs5rect16) { ++g_ttl_rect16; g_ttl_rectBase = base; }
          }
          // RVK_NOVS5XY12 disables (select settle-composite fix 2026-07-20, vs5base-dump proven):
          // the settle-composite's border draws into 0x660000 (vs=5 TRISTRIP n=4 bands spanning
          // x=-32..672 at y=-48..-32 / 512..528, + TRIFAN n=7 radius-16 quarter-circle corner
          // fans) are STRIDE-12 float {x,y,packed-color} records — NO z, NO uv. Colors are a
          // 0x00000000 <-> 0xFF080808 fade (the rounded-corner dark matte around the panel).
          // The default stride-24 decode shears them (color dword 0xFF080808 lands in the uv
          // slot — the "b118 garbage"). Signature-gated per record: plausible px xy at stride 12
          // AND every third dword is 0 or an alpha-topped packed color (top byte >= 0x7F, which
          // reads as a float-implausible huge/inf value — a real stride-24 record's color-as-x
          // fails the xy range check, so working quads cannot false-positive); at least one
          // non-zero color required so all-zero records stay on the old path.
          static bool vs5xy12Fix = !std::getenv("RVK_NOVS5XY12");
          bool vs5xy12 = false;
          if (vs5xy12Fix && g_curVsIdx == 5 && !vs5rect16 && (drawPrim == 5 || drawPrim == 6) &&
              n >= 3 && n <= 8) {
            vs5xy12 = true;
            bool anyColor = false;
            for (uint32_t k5 = 0; k5 < n && vs5xy12; ++k5) {
              uint32_t t0 = be32(va + k5 * 12 + 0), t1 = be32(va + k5 * 12 + 4), t2 = be32(va + k5 * 12 + 8);
              float xf, yf;
              std::memcpy(&xf, &t0, 4); std::memcpy(&yf, &t1, 4);
              if (!(xf >= -2048.f && xf <= 2048.f && yf >= -2048.f && yf <= 2048.f)) vs5xy12 = false;
              else if (t2 == 0u) { /* transparent vertex, layout-consistent */ }
              else if ((t2 >> 24) >= 0x7Fu) anyColor = true;
              else vs5xy12 = false;
            }
            if (!anyColor) vs5xy12 = false;
          }
          // RVK_STRIDESWEEP (2026-07-19, post-tile-fix class sweep): log every small draw whose
          // guest records pass the stride-16 {x,y,u,v} signature (plausible px pos + NORMALIZED uv
          // in every record) but is NOT being decoded stride-16 — candidate misdecodes of the same
          // class as the fixed ring-slot rect. Logging only, no behavior change. Cap 200.
          static bool strideSweep = std::getenv("RVK_STRIDESWEEP") != nullptr;
          if (strideSweep && n >= 3 && n <= 8 && bsfPhase == -999 && !i48int && !vs47 && !vs5rect16) {
            bool sig16 = true;
            for (uint32_t k6 = 0; k6 < n && sig16; ++k6) {
              uint32_t s0 = be32(va + k6 * 16 + 0), s1 = be32(va + k6 * 16 + 4), s2 = be32(va + k6 * 16 + 8), s3 = be32(va + k6 * 16 + 12);
              float xf, yf, uf, vf;
              std::memcpy(&xf, &s0, 4); std::memcpy(&yf, &s1, 4); std::memcpy(&uf, &s2, 4); std::memcpy(&vf, &s3, 4);
              if (!(xf >= -2048.f && xf <= 2048.f && yf >= -2048.f && yf <= 2048.f &&
                    uf >= -0.01f && uf <= 1.01f && vf >= -0.01f && vf <= 1.01f &&
                    (xf != 0.f || yf != 0.f || uf != 0.f || vf != 0.f))) sig16 = false;
            }
            if (sig16) {
              static long ssN = 0;
              if (ssN++ < 200) {
                uint32_t r0x = be32(va + 16), r1x = be32(va + 32); float fx1, fx2;
                std::memcpy(&fx1, &r0x, 4); std::memcpy(&fx2, &r1x, 4);
                std::fprintf(stderr, "[stridesweep] f%ld vs=%d ps=%d n=%u prim=%u tex=0x%X isRes=%d vp={%.0f,%.0f,%.0f,%.0f} r1x=%.1f r2x=%.1f\n",
                  frame, g_curVsIdx, g_curPsIdx, n, drawPrim, base, (int)(g_resolveTex.count(base) > 0),
                  drawVp.x, drawVp.y, drawVp.width, drawVp.height, fx1, fx2);
              }
            }
          }
          RvkClock::time_point p2vtxT0; if (perflog2) p2vtxT0 = RvkClock::now();
          for (uint32_t k = 0; k < n; ++k) {
            uint32_t* d = Vraw + (size_t)nv * 6;
            if (bsfPhase != -999) {                          // stride-24 {x,y,z,color,u,v} portrait
              uint32_t b = (uint32_t)((int32_t)va + bsfPhase) + k * 24;
              d[0] = be32(b + 0);    // x
              d[1] = be32(b + 4);    // y
              // u,v are stored NORMALIZED (0..1) in this record, but the vs=48 shader consumes
              // PIXEL-space uv (the working stride-16 int sprites pass pixel coords). Scale by the
              // sampled texture dims so the portrait art maps 1:1 instead of collapsing onto the
              // origin texel (which blew the composite out to white). RVK_BSFUVNORM=1 keeps raw
              // normalized uv for A/B.
              static bool bsfUvNorm = std::getenv("RVK_BSFUVNORM") != nullptr;
              uint32_t ub = be32(b + 16), vb = be32(b + 20); float uf, vf;
              std::memcpy(&uf, &ub, 4); std::memcpy(&vf, &vb, 4);
              if (!bsfUvNorm) { uf *= (float)tw; vf *= (float)th; }
              std::memcpy(&d[2], &uf, 4); std::memcpy(&d[3], &vf, 4);
              d[4] = 0; d[5] = 0;    // shader vertex is {x,y,u,v}
            } else if (i48int) {
              for (int c = 0; c < 4; ++c) { float f = (float)(int32_t)be32(va + k * 16 + c * 4); std::memcpy(&d[c], &f, 4); }
              d[4] = 0; d[5] = 0;
            } else if (vs47) {
              uint32_t s = (uint32_t)vs47stride;
              d[0] = be32(va + k * s + 0);   // x
              d[1] = be32(va + k * s + 4);   // y
              d[2] = be32(va + k * s + 8);   // z
              d[3] = be32(va + k * s + 16);  // color (D3DCOLOR @ guest dw4)
              d[4] = be32(va + k * s + 20);  // u (guest dw5)
              d[5] = be32(va + k * s + 24);  // v (guest dw6)
            } else if (vs5rect16) {              // stride-16 float {x,y,u,v} resolve-downscale rect
              d[0] = be32(va + k * 16 + 0);      // x (guest px)
              d[1] = be32(va + k * 16 + 4);      // y (guest px)
              float zf = 0.f; std::memcpy(&d[2], &zf, 4);
              d[3] = 0xFFFFFFFFu;                // packed color: opaque white (neutral modulate)
              d[4] = be32(va + k * 16 + 8);      // u (normalized)
              d[5] = be32(va + k * 16 + 12);     // v (normalized)
            } else if (vs5xy12) {                // stride-12 float {x,y,packed-color} matte band/fan
              d[0] = be32(va + k * 12 + 0);      // x (guest px)
              d[1] = be32(va + k * 12 + 4);      // y (guest px)
              float zf = 0.f; std::memcpy(&d[2], &zf, 4);
              d[3] = be32(va + k * 12 + 8);      // packed color (0x00000000..0xFF080808 fade)
              d[4] = 0; d[5] = 0;                // record has no uv
            } else {
              for (int c = 0; c < 6; ++c) d[c] = be32(va + k * 24 + c * 4); // per-dword byteswap (pos/color/uv alike)
            }
            ++nv;
          }
          if (perflog2) p2Vtx += rvkMs(p2vtxT0);
          // RVK_MESHDUMP=<hex base>[,<hex base>] (char-card painting hunt 2026-07-22): full
          // machine-readable per-vertex dump of EVERY vs=48 draw sampling either listed texture
          // base, appended to C:/tmp/meshdump.txt (flushed per draw) so the held card's ~103-tile
          // mesh can be composited offline. REUSES the shipping decode already written into Vraw
          // above (verts [v0,v0+n) are decoded {x,y,u,v,-,-} for the i48int/bsf24 class, or
          // {x,y,z,color,u,v} for the stride-24 gen path) — no stride re-derivation. base is the
          // raw fetch-constant page addr (tf[1]>>12<<12, line ~3894), so the gate matches the
          // exact page the guest samples. blend = live per-draw RB_BLENDCONTROL0 (g_regFile[0x2201],
          // the same reg RVK_BLENDLOG decodes). Off unless the env var is set; 200000-line cap.
          static uint32_t meshDumpBase[2] = {0u, 0u};
          static bool meshDumpInit = false;
          static FILE* meshDumpFp = nullptr;
          static long meshDumpLines = 0;
          if (!meshDumpInit) {
            meshDumpInit = true;
            if (const char* e = std::getenv("RVK_MESHDUMP")) {
              meshDumpBase[0] = (uint32_t)strtoul(e, nullptr, 16);
              if (const char* comma = std::strchr(e, ',')) meshDumpBase[1] = (uint32_t)strtoul(comma + 1, nullptr, 16);
              meshDumpFp = std::fopen("C:/tmp/meshdump.txt", "a");
            }
          }
          if (meshDumpFp && g_curVsIdx == 48 && meshDumpLines < 200000 &&
              (base == meshDumpBase[0] || (meshDumpBase[1] && base == meshDumpBase[1]))) {
            const char* cls = (bsfPhase != -999) ? "bsf24" : (i48int ? "i48int" : "gen24");
            int uOff = (bsfPhase != -999 || i48int) ? 2 : 4;   // uv slot in the decoded Vraw record
            std::fprintf(meshDumpFp, "draw seq=%d frame=%ld base=0x%X n=%u prim=%u class=%s blend=0x%X\n",
              ndraw, frame, base, n, drawPrim, cls, g_regFile[0x2201]);
            ++meshDumpLines;
            for (uint32_t k = 0; k < n && meshDumpLines < 200000; ++k) {
              const float* fv = (const float*)(Vraw + (size_t)(v0 + k) * 6);
              std::fprintf(meshDumpFp, "v %.3f %.3f %.3f %.3f\n", fv[0], fv[1], fv[uOff], fv[uOff + 1]);
              ++meshDumpLines;
            }
            std::fflush(meshDumpFp);
          }
          // RVK_ONLYBASE=<hex>[:<hexblend>] (char-card painting isolation 2026-07-22): render
          // ONLY vs=48 draws whose sampled page (and optionally the low-28 bits of RB_BLENDCONTROL0)
          // match; every OTHER vs=48 draw's topology is skipped (its verts stay allocated but
          // unreferenced -> zero fragments). NON-vs48 draws (panel compose vs=5/47, etc.) always
          // render so the isolated layer still reaches the visible window. Splits "the atlasA OVER
          // draw itself renders black" from "a later interior layer covers it". Off by default.
          static bool onlyBaseInit = false;
          static uint32_t onlyBase = 0u, onlyBaseBlend = 0u; static bool onlyBaseHasBlend = false;
          if (!onlyBaseInit) { onlyBaseInit = true;
            if (const char* e = std::getenv("RVK_ONLYBASE")) {
              onlyBase = (uint32_t)strtoul(e, nullptr, 16);
              if (const char* colon = std::strchr(e, ':')) { onlyBaseBlend = (uint32_t)strtoul(colon + 1, nullptr, 16); onlyBaseHasBlend = true; }
            }
          }
          bool onlyBaseSkip = onlyBase && g_curVsIdx == 48 &&
            !(base == onlyBase && (!onlyBaseHasBlend || (g_regFile[0x2201] & 0xFFFFFFFu) == (onlyBaseBlend & 0xFFFFFFFu)));
          // RVK_OVERLOG=<hex base> (char-card painting isolation 2026-07-22): one line per frame for
          // the first vs=48 draw sampling that page — the LIVE blend reg + decoded Vulkan blend
          // factors + the register-true alpha-test state (RB_COLORCONTROL 0x2202 / RB_ALPHA_REF
          // 0x210E) actually in effect for the atlasA OVER draw + its bindless texIdx. Answers
          // "does the multiply/over draw run with alpha-test armed?" without a rebuild-per-guess.
          static uint32_t overLogBase = std::getenv("RVK_OVERLOG")
            ? (uint32_t)strtoul(std::getenv("RVK_OVERLOG"), nullptr, 16) : 0u;
          if (overLogBase && g_curVsIdx == 48 && base == overLogBase) {
            // log once per (frame,blend) so BOTH the OVER (0x7060706) and ADDITIVE (0x1060106)
            // atlasA draws are captured, plus the pixel-shader index + its alpha-relevant consts.
            static long overLogFrame = -1; static uint32_t overLogBlendSeen = 0;
            uint32_t br0 = g_regFile[0x2201] & 0xFFFFFFFu;
            if (frame != overLogFrame) { overLogFrame = frame; overLogBlendSeen = 0; }
            if (!(overLogBlendSeen & (br0 == 0x060706u ? 1u : br0 == 0x060106u ? 2u : 4u))) {
              overLogBlendSeen |= (br0 == 0x060706u ? 1u : br0 == 0x060106u ? 2u : 4u);
              uint32_t br = g_regFile[0x2201];
              uint32_t cSrc = br & 0x1f, cOp = (br >> 5) & 7, cDst = (br >> 8) & 0x1f;
              uint32_t aSrc = (br >> 16) & 0x1f, aDst = (br >> 24) & 0x1f;
              uint32_t cc2202 = g_regFile[0x2202];
              bool atEn = (cc2202 >> 3) & 1; uint32_t atFn = cc2202 & 7;
              float aref; uint32_t rv210E = g_regFile[0x210E]; std::memcpy(&aref, &rv210E, 4);
              // ps=50 formula (line ~1185): out.rgb = tex.rgb * c14.rgb ; out.a = tex.a*c15.x + c15.y.
              // So log c14.rgb (the color modulate) and c15.x/c15.y (the alpha scale/bias) — a zero
              // c14 makes rgb black, a zero c15.x/c15.y makes fragment alpha 0 (SRC_ALPHA=0 + alpha
              // test GREATER 0 -> every fragment discarded -> black interior).
              std::fprintf(stderr, "[overlog] f%ld d%d ps=%d base=0x%X n=%u prim=%u blend=0x%X (cSrc=%u cOp=%u cDst=%u aSrc=%u aDst=%u) atEnable=%d atFunc=%u aref=%.4f texIdx=%u fmt=%u c14rgb=(%.3f,%.3f,%.3f) c15xy=(%.3f,%.3f) c0=(%.3f,%.3f,%.3f,%.3f)\n",
                frame, ndraw, g_curPsIdx, base, n, drawPrim, br, cSrc, cOp, cDst, aSrc, aDst, (int)atEn, atFn, aref, texIdx, fmt,
                g_psConstF[56], g_psConstF[57], g_psConstF[58], g_psConstF[60], g_psConstF[61],
                g_psConstF[0], g_psConstF[1], g_psConstF[2], g_psConstF[3]);
            }
          }
          uint32_t prim = drawPrim; // Xenos draw initiator prim type (LEG-40e: opcode-correct offset)
          if (onlyBaseSkip) { /* isolation lever: drop this draw's topology, keep its verts unreferenced */ }
          else if (prim == 8 && (n % 3) == 0 && nv + n / 3 <= kMaxVerts) {
            // RECTLIST: each 3 verts = rect corners; derive 4th (v3 = v1 + v2 - v0) and emit 2 tris
            for (uint32_t g2 = 0; g2 < n / 3; ++g2) {
              uint32_t a0 = v0 + g2 * 3;
              float* f0 = (float*)(Vraw + (size_t)a0 * 6);
              float* f1 = (float*)(Vraw + (size_t)(a0 + 1) * 6);
              float* f2 = (float*)(Vraw + (size_t)(a0 + 2) * 6);
              float* f3 = (float*)(Vraw + (size_t)nv * 6);
              if (g_curVsIdx == 48) { // {x,y,u,v,-,-} floats: lerp 0-3, copy rest
                for (int c = 0; c < 4; ++c) f3[c] = f1[c] + f2[c] - f0[c];
                ((uint32_t*)f3)[4] = ((uint32_t*)f1)[4]; ((uint32_t*)f3)[5] = ((uint32_t*)f1)[5];
              } else {              // {x,y,z,color,u,v}: lerp pos+uv, copy packed color
                for (int c : {0, 1, 2, 4, 5}) f3[c] = f1[c] + f2[c] - f0[c];
                ((uint32_t*)f3)[3] = ((uint32_t*)f1)[3];
              }
              uint32_t v3 = nv++;
              Iarr[ni++] = a0; Iarr[ni++] = a0 + 1; Iarr[ni++] = a0 + 2;
              Iarr[ni++] = a0 + 2; Iarr[ni++] = a0 + 1; Iarr[ni++] = v3;
            }
          } else if (g_curVsIdx == 47 && n == 4) {
            // vs=47 quads (incl. the composite fullscreen quad sampling the resolved playfield)
            // are Z-ordered corners TL,TR,BL,BR -> strip tris (TL,TR,BL)+(TR,BR,BL). Using the fan
            // path bowties them into a diagonal shear. (Independent of the RVK_VS47 stride flag.)
            Iarr[ni++] = v0; Iarr[ni++] = v0 + 1; Iarr[ni++] = v0 + 2;
            Iarr[ni++] = v0 + 1; Iarr[ni++] = v0 + 3; Iarr[ni++] = v0 + 2;
          } else if (vs5xy12 && prim == 6) {
            // TRISTRIP: the matte bands' corners are strip-ordered (TL,TR,BL,BR); the generic
            // fan indexing below bowties strip order into a hole. Culling is off, so plain
            // (k,k+1,k+2) strip triangles without winding alternation are sufficient.
            for (uint32_t k = 0; k + 2 < n; ++k) { Iarr[ni++] = v0 + k; Iarr[ni++] = v0 + k + 1; Iarr[ni++] = v0 + k + 2; }
          } else {
            for (uint32_t k = 1; k + 1 < n; ++k) { Iarr[ni++] = v0; Iarr[ni++] = v0 + k; Iarr[ni++] = v0 + k + 1; }
          }
          // RVK_C14LOG (2026-07-17 CAVE-card grey): change-triggered psc14/psc15 timeline at vs48
          // draws — the attract backdrop (legal panel/white flash/CAVE card) is the tile batch
          // through the ROM ps `out=tex*c14`, so this logs the guest's animated backdrop color
          // through the whole attract without aiming a frame window. Cheap, capped, default off.
          static long c14from = std::getenv("RVK_C14LOG") ? std::strtol(std::getenv("RVK_C14LOG"), nullptr, 10) : -1;
          if (c14from >= 0 && frame >= c14from && g_curVsIdx == 48) {
            static float c14last[8] = {-1e9f, 0, 0, 0, 0, 0, 0, 0};
            static int c14n = 0;
            // ★ r23-w17 C1: the 120-line budget was sized for the ATTRACT (a scripted sequence a
            //   few thousand frames long).  A wash leg runs for tens of thousands of frames and
            //   spends the whole budget in the boot menus before the stage even loads, so the
            //   window that matters is silent for a reason that has nothing to do with the guest.
            //   RVK_C14LOG_CAP raises it; default is unchanged so no existing reading moves.
            static int c14cap = std::getenv("RVK_C14LOG_CAP") ? std::atoi(std::getenv("RVK_C14LOG_CAP")) : 120;
            const float* c14p = &g_psConstF[56];
            if (c14n < c14cap && std::memcmp(c14last, c14p, 32) != 0) {
              std::memcpy(c14last, c14p, 32); ++c14n;
              // tf[3] bits 19-20/21-22 = fetch-constant mag/min filter (0=point 1=linear 3=fetchconst)
              std::fprintf(stderr, "[c14log] f%ld d%d ps=%d n=%u psc14=(%.4f,%.4f,%.4f,%.4f) psc15=(%.4f,%.4f,%.4f,%.4f) tf3=%08X mag=%u min=%u expadj=%d\n",
                frame, ndraw, g_curPsIdx, n, c14p[0], c14p[1], c14p[2], c14p[3], c14p[4], c14p[5], c14p[6], c14p[7],
                tf[3], (tf[3] >> 19) & 3, (tf[3] >> 21) & 3, (int)((int32_t)(tf[3] << 13) >> 26));
            }
          }
          // RVK_SHEARDBG (Round-13 char-select portrait shear, 2026-07-15): focused dump of the
          // big multi-quad vs=48 sprites that shear into diagonal bands in the FIXB2 atlas. For each
          // vs=48 draw with n>=5, log: n, drawPrim, va, which TOPOLOGY path was taken (rectlist vs
          // fan), the stride discriminator (i48int), the EXTRACTED positions of the first verts (what
          // actually reaches the GPU, post byte-swap/int-convert), the chosen matrix (curVsDegen +
          // variant model/screen + c0/c1/c3/c255), and the guest raw dwords so stride can be solved.
          // RVK_SHEARDBG=<N>: N>1 sets the start frame (default 1500), so the dump budget can be
          // aimed at a late scene (e.g. the ROM-attract legal panel ~frame 3000) instead of being
          // spent on the first menu draws past 1500. RVK_SHEARDBG_CAP overrides the line budget.
          static long shearFrom = std::getenv("RVK_SHEARDBG") ? std::strtol(std::getenv("RVK_SHEARDBG"), nullptr, 10) : -1;
          static long shearCap = std::getenv("RVK_SHEARDBG_CAP") ? std::strtol(std::getenv("RVK_SHEARDBG_CAP"), nullptr, 10) : 80;
          if (std::getenv("RVK_SHEARDBG") && frame > (shearFrom > 1 ? shearFrom : 1500) && g_curVsIdx == 48 && n >= 6) {
            static long shd = 0;
            if (shd++ < shearCap) {
              const char* topo = (prim == 8 && (n % 3) == 0) ? "RECTLIST"
                               : (g_curVsIdx == 47 && n == 4) ? "STRIP" : "FAN";
              // recompute the degenerate model/screen variant test exactly as line ~2344 does
              bool model = false;
              if (curVsDegen) for (uint32_t k = 0; k < n && !model; ++k)
                if (bef(va + k * 24) < 0.f || bef(va + k * 24 + 4) < 0.f) model = true;
              float* mtx = curVsHost;
              uint32_t vsz = vf1 & 0xFFFFFFu;   // fetch-constant size in dwords
              std::fprintf(stderr, "[sheardbg] f%ld d%d vs48 ps=%d n=%u prim=%u topo=%s i48int=%d vs47=%d bsfPhase=%d va=0x%X vf0=%08X vf1=%08X szDw=%u blend=0x%X degen=%d variant=%s\n",
                frame, ndraw, g_curPsIdx, n, prim, topo, (int)i48int, (int)vs47, bsfPhase, va, vf0, vf1, vsz, g_regFile[0x2201], (int)curVsDegen, curVsDegen ? (model ? "MODEL" : "SCREEN") : "single");
              std::fprintf(stderr, "[sheardbg]   psc0=(%.4f,%.4f,%.4f,%.4f) psc14=(%.4f,%.4f,%.4f,%.4f) psc15=(%.4f,%.4f,%.4f,%.4f) bc=(%.3f,%.3f,%.3f,%.3f)\n",
                g_psConstF[0],g_psConstF[1],g_psConstF[2],g_psConstF[3], g_psConstF[56],g_psConstF[57],g_psConstF[58],g_psConstF[59],
                g_psConstF[60],g_psConstF[61],g_psConstF[62],g_psConstF[63], curBc[0],curBc[1],curBc[2],curBc[3]);
              if (mtx) std::fprintf(stderr, "[sheardbg]   c0=(%.5f,%.5f,%.5f,%.5f) c1=(%.5f,%.5f,%.5f,%.5f) c3=(%.5f,%.5f,%.5f,%.5f) c255=(%.5f,%.5f,%.5f,%.5f)\n",
                mtx[0],mtx[1],mtx[2],mtx[3], mtx[4],mtx[5],mtx[6],mtx[7], mtx[12],mtx[13],mtx[14],mtx[15], mtx[1020],mtx[1021],mtx[1022],mtx[1023]);
              // extracted (GPU-bound) positions of the first up-to-6 verts
              std::fprintf(stderr, "[sheardbg]   extracted xy+uv:");
              for (uint32_t k = 0; k < n && k < 6; ++k) {
                float* fv = (float*)(Vraw + (size_t)(v0 + k) * 6);
                std::fprintf(stderr, " v%u(%.1f,%.1f uv %.1f,%.1f)", k, fv[0], fv[1], fv[2], fv[3]);
              }
              // raw dword window around va (va-16 .. va+80) so the true vertex start/stride is visible
              std::fprintf(stderr, "[sheardbg]   raw dw va-4..+20:");
              for (int dw = -4; dw <= 20; ++dw) std::fprintf(stderr, " %s%08X", dw==0?"|":"", be32(va + dw*4));
              std::fprintf(stderr, "\n[sheardbg]   as f24 x,y:");   // interpret as float stride-24 {x,y,z,color,u,v}
              for (uint32_t k = 0; k < 6; ++k) { float x,y; uint32_t xb=be32(va+k*24),yb=be32(va+k*24+4); std::memcpy(&x,&xb,4); std::memcpy(&y,&yb,4); std::fprintf(stderr, " (%.1f,%.1f)", x, y); }
              std::fprintf(stderr, "\n");
              // [vscdiff] find the guest's ANIMATED VS constant (the fade/material color the synth48
              // shader ignores): diff the full VS float-constant file across consecutive tile draws
              // and print the slots that changed. The legal fly-in fade must show up here.
              if (std::getenv("RVK_VSCDIFF")) {
                static float prevC[1024]; static bool has = false; static long lastF = -1;
                if (frame != lastF) {
                  if (has) {
                    int shown = 0;
                    for (int ci = 0; ci < 1024 && shown < 12; ++ci)
                      if (g_vsConstF[ci] != prevC[ci]) {
                        std::fprintf(stderr, "[vscdiff] f%ld c%d.%c %.5f -> %.5f\n", frame, ci >> 2, "xyzw"[ci & 3], prevC[ci], g_vsConstF[ci]);
                        ++shown;
                      }
                  }
                  std::memcpy(prevC, g_vsConstF, sizeof prevC); has = true; lastF = frame;
                }
                // Same diff over the PS half of the shared 512-slot Xenos constant file (0x4400+,
                // g_psConstF): the fade may live in a slot the guest addresses as c256+ (VS-visible
                // on real HW). Also mirrors of the RB_BLEND_RED..ALPHA float regs are candidates.
                static float prevP[896]; static bool hasP = false; static long lastP = -1;
                if (frame != lastP) {
                  if (hasP) {
                    int shown = 0;
                    for (int ci = 0; ci < 896 && shown < 12; ++ci)
                      if (g_psConstF[ci] != prevP[ci]) {
                        std::fprintf(stderr, "[pscdiff] f%ld c%d.%c (=c%d) %.5f -> %.5f\n", frame, ci >> 2, "xyzw"[ci & 3], 256 + (ci >> 2), prevP[ci], g_psConstF[ci]);
                        ++shown;
                      }
                  }
                  std::memcpy(prevP, g_psConstF, sizeof prevP); hasP = true; lastP = frame;
                }
              }
              // [vfetchdump] the decode follows ONLY vfetch pair 0x48BE/BF; the real guest vs48
              // (0xF4C1040) may fetch a per-vertex/material COLOR from a SECOND vfetch slot we
              // never read (the missing fade path). Dump the tail of the fetch-constant file.
              if (std::getenv("RVK_VFETCHDUMP")) {
                static long vfd = 0;
                if (vfd++ < 12) {
                  std::fprintf(stderr, "[vfetchdump] f%ld d%d FULL fetch file 0x4800-0x48BF:\n", frame, ndraw);
                  for (uint32_t row = 0; row < 12; ++row) {
                    std::fprintf(stderr, "[vfetchdump]   +%02X:", row * 16);
                    for (uint32_t c = 0; c < 16; ++c) std::fprintf(stderr, " %08X", g_regFile[0x4800 + row * 16 + c]);
                    std::fprintf(stderr, "\n");
                  }
                }
              }
              // [tileprobe] live re-read of the tile batch's sampled cell straight from GUEST RAM
              // through the SAME tiledOff used at upload: does the glyph-cache cell (0..32,0..32) of
              // the bound fmt-3 atlas hold DIFFERENT content NOW than at first-sample/upload time?
              // (dynamic glyph atlas ⇒ our never-invalidated texture cache would diverge.)
              if (std::getenv("RVK_TILEPROBE")) {
                uint32_t tb = 0;
                for (auto& kv : g.rTexIndex) if (kv.second == texIdx) { tb = (uint32_t)(kv.first >> 8); break; }
                if (tb) {
                  uint64_t sum = 0; uint32_t alpha1 = 0, nz = 0;
                  for (uint32_t ty = 0; ty < 32; ++ty) for (uint32_t tx = 0; tx < 32; ++tx) {
                    uint16_t px = be16(tb + tiledOff(tx, ty, 256, 1, 0));
                    uint32_t r5 = (px >> 10) & 0x1F, g5 = (px >> 5) & 0x1F, b5 = px & 0x1F;
                    sum += (r5 + g5 + b5); if (px & 0x8000) alpha1++; if (px) nz++;
                  }
                  std::fprintf(stderr, "[tileprobe] f%ld base=0x%X cell(0..32)^2 mean5=%.1f alphaSet=%u/1024 nonzero=%u/1024\n",
                    frame, tb, (double)sum / 3072.0, alpha1, nz);
                }
              }
            }
          }
          static long opsCap = std::getenv("RVK_OPS_CAP") ? std::strtol(std::getenv("RVK_OPS_CAP"), nullptr, 10) : 400;
          static long cornersDumped = 0;
          if (dumpOps && n >= 3 && cornersDumped++ < opsCap) { // all corner records raw (pre-normalization guest bytes)
            uint32_t cs = vs47 ? (uint32_t)vs47stride : 24;
            for (uint32_t rr = 0; rr < n && rr < 4; ++rr) {
              std::fprintf(stderr, "[rvk][ops]   corner%u: %08X %08X %08X %08X %08X %08X %08X\n", rr,
                be32(va + rr * cs), be32(va + rr * cs + 4), be32(va + rr * cs + 8),
                be32(va + rr * cs + 12), be32(va + rr * cs + 16), be32(va + rr * cs + 20),
                be32(va + rr * cs + 24));
            }
          }
          static long opsDumped = 0;   // cap total per-draw dump lines (the un-capped version
          if (dumpOps && opsDumped < opsCap) { opsDumped++;   // once produced an 845k-line log)
            std::fprintf(stderr, "[rvk][ops]   vp={%.0f,%.0f,%.0f,%.0f} prim=%u\n",
              drawVp.x, drawVp.y, drawVp.width, drawVp.height, drawPrim);
            // hatch RE 2026-07-11: vertex-fetch constant raw (vf1 low bits = buffer size in
            // dwords -> true stride = size/n) + draw opcode + raw guest dwords around va so
            // record alignment/stride can be solved offline. Also the inline indices for 0x36.
            std::fprintf(stderr, "[rvk][ops]   vfetch op=0x%02X vf0=%08X vf1=%08X va=0x%X n=%u initw=%08X\n",
              op, vf0, vf1, va, n, initw);
            if (op == 0x36 && cnt >= 2) {
              std::fprintf(stderr, "[rvk][ops]   inline idx dwords:");
              for (uint32_t k2 = 1; k2 < cnt && k2 < 9; ++k2) std::fprintf(stderr, " %08X", be32(i + 4 + k2 * 4));
              std::fprintf(stderr, "\n");
            }
            if (n <= 8) {   // small draws (composite quads): raw memory context around va
              for (int row = -1; row < 4; ++row) {
                std::fprintf(stderr, "[rvk][ops]   va%+04d:", row * 32);
                for (int c = 0; c < 8; ++c) std::fprintf(stderr, " %08X", be32(va + row * 32 + c * 4));
                std::fprintf(stderr, "\n");
              }
            }
            uint32_t* d0 = Vraw + (size_t)v0 * 6;
            std::fprintf(stderr, "[rvk][ops] draw%d n=%u rec=%08X %08X %08X %08X %08X %08X tex=%u fmt=%u base=0x%X %ux%u vs=%d ps=%d"
              " | RB 2200=%08X 2201=%08X 2202=%08X 2203=%08X 2204=%08X 2205=%08X 2208=%08X 2100=%08X 2102=%08X 2104=%08X 2180=%08X 2318=%08X\n",
              ndraw, n, d0[0], d0[1], d0[2], d0[3], d0[4], d0[5], texIdx, fmt, base, tw, th, g_curVsIdx, g_curPsIdx,
              g_regFile[0x2200], g_regFile[0x2201], g_regFile[0x2202], g_regFile[0x2203], g_regFile[0x2204], g_regFile[0x2205],
              g_regFile[0x2208], g_regFile[0x2100], g_regFile[0x2102], g_regFile[0x2104], g_regFile[0x2180], g_regFile[0x2318]);
            uint32_t tf0 = g_regFile[0x4800];
            std::fprintf(stderr, "[rvk][ops]   tf0=%08X tiled=%u pitch=%u(x32=%u) fmt=%u  %ux%u\n",
              tf0, (tf0 >> 30) & 1u, (tf0 >> 21) & 0x1FFu, ((tf0 >> 21) & 0x1FFu) * 32u, fmt, tw, th);
            // 2026-07-28 seam hunt (SPEC #3): the live VS matrix rows c0..c3 for this draw —
            // the FUN_8216BED0 (VMX, statically unreadable) product lands here via SET_CONSTANT.
            std::fprintf(stderr, "[rvk][ops]   c0={%g %g %g %g} c1={%g %g %g %g} c3={%g %g %g %g}\n",
              g_vsConstF[0], g_vsConstF[1], g_vsConstF[2], g_vsConstF[3],
              g_vsConstF[4], g_vsConstF[5], g_vsConstF[6], g_vsConstF[7],
              g_vsConstF[12], g_vsConstF[13], g_vsConstF[14], g_vsConstF[15]);
          }
          // ★ RVK_DRAWTRIP=N (FNF-7, 2026-07-26): shell frames have a small fixed draw count
          // (held TOP MENU = 8). The captured menu glitch is ONE EXTRA sprite-class draw
          // (frame2682 EID 85, opaque black quad). Buffer every shell-frame draw's identity;
          // when a frame exceeds N draws, dump the whole frame's records — the extra draw's
          // texIdx/base/v0 names the emitter that pixel history cannot (bindless). Default off.
          {
            static int tripN = std::getenv("RVK_DRAWTRIP") ? atoi(std::getenv("RVK_DRAWTRIP")) : 0;
            if (tripN > 0 && g_base && be32(GA_FIELD_ACTIVE) == 0 && g_rt_romactive == 0) {
              // ★ pkt = the ABSOLUTE guest address of this draw's PM4 packet header, ibd = indirect-
              // buffer depth. FNF-7 decisive experiment (2026-07-26): compared against rt.cpp's
              // RT_SEGTAB table it says whether the packet came from bytes the guest actually
              // submitted for this present (inside a captured segment) or from beyond them
              // (walk overrun / stale reservoir).
              // ⚠ NOT stored as (i - start): the IB-descend path rebases BOTH i and end into the
              // indirect buffer's address space (see the 0x3F handler below), so a window-relative
              // offset is only meaningful at ibd==0. Absolute + depth is unambiguous at any depth.
              // hdr = raw TYPE3 header dword (bit 0 = PREDICATE); skip = the SDK CP's verdict
              // EVALUATED AT THIS DRAW (bin state is stateful through the stream, so it cannot be
              // recomputed at dump time from the end-of-frame registers).
              struct TripRec { int nd; uint32_t n, va, texIdx, fmt, base, tw, th, pkt, hdr; int ibd, vs, ps, skip; float x0, y0; };
              static std::vector<TripRec> tripBuf; static long tripFrame = -1;
              // Window base of the frame currently BUFFERED — the dump fires one frame later, by
              // which point `start` already belongs to the next frame. `start` is the only stable
              // bound to latch: `end` is rebased in place by the IB-descend path below.
              static uint32_t tripWinStart = 0;
              // ★ Snapshot of rt.cpp's RT_SEGTAB table taken at the START of the buffered frame's
              // decode. Reading g_seg_* at DUMP time is an off-by-one: by then the kick thread has
              // already opened the NEXT window and reset the table (measured — the live wbase was
              // past every packet of the frame being dumped). At the first draw of frame N the
              // window for N is closed and N+1 has not started, so that is the correct sampling
              // point. 6x64 dwords once per frame.
              struct SegSnap { int n; uint32_t wbase, off[64], len[64], src[64], pre[64], obj[64], lat[64], objdw[64]; };
              static SegSnap segSnap{};
              if (frame != tripFrame) {
                // ★ RVK_MVLOG=1 (FNF-7 mid-tick discriminator, 2026-07-26, default off): ONE line
                // per RENDERED frame pairing this frame's guest draw count with the M2Lib movie
                // tick state exported by rt.cpp's RT_MVTICK hook (sub_8217F948). The renderer owns
                // the frame boundary, so it is also what resets the tick counters — that makes
                // evals[] strictly "ticks that happened between the previous rendered frame and
                // this one". Hypothesis under test: on a 62-draw frame, does the evaluator run a
                // different number of times (evals != 1), or is the tick count identical to a
                // clean frame and only the sampled visibility differs?
                // ⚠ ONE line/frame (~60/s) is ~1.6% of the 07-26 observer-effect load (61
                // lines/frame, ~3700/s) that suppressed the anomaly — but it is NOT free, so the
                // acceptance gate for this instrument is that the 62-draw rate and the 54-frame
                // period must survive it. Compare against the un-armed run before believing a null.
                static bool mvLog = std::getenv("RVK_MVLOG") != nullptr;
                if (mvLog && tripFrame >= 0) {
                  char rb[512]; int ro = 0;
                  int mn = (int)g_mv_n; if (mn > 12) mn = 12;
                  for (int i = 0; i < mn && ro < (int)sizeof(rb) - 48; ++i) {
                    float p; int bpat = g_mv_b[i]; std::memcpy(&p, &bpat, 4);
                    ro += std::snprintf(rb + ro, sizeof(rb) - ro, " |%X:c%d:n%d:v%d:t%d:p%.2f",
                      (unsigned)(g_mv_o[i] & 0xFFFFF), (int)g_mv_c[i], (int)g_mv_p[i],
                      (int)g_mv_v[i], (int)g_mv_t[i], p);
                  }
                  std::fprintf(stderr, "[mvtick] f%ld draws=%zu evals=%d nobj=%d%s\n",
                    tripFrame, tripBuf.size(), (int)g_mv_calls, mn, rb);
                }
                g_mv_calls = 0;
                for (int i = 0; i < 12; ++i) g_mv_c[i] = 0;
                if ((int)tripBuf.size() > tripN) {
                  std::fprintf(stderr, "[drawtrip] f%ld draws=%zu (>%d) win=[0x%X,0x%X) len=%u FRAME DUMP:\n",
                    tripFrame, tripBuf.size(), tripN, tripWinStart, 0u, 0u);
                  for (auto& r : tripBuf)
                    std::fprintf(stderr, "[drawtrip]   d%d n=%u va=0x%X v0=(%.1f,%.1f) tex=%u fmt=%u base=0x%X %ux%u vs=%d ps=%d pkt=0x%X ibd=%d hdr=%08X pred=%u sdk=%s\n",
                      r.nd, r.n, r.va, r.x0, r.y0, r.texIdx, r.fmt, r.base, r.tw, r.th, r.vs, r.ps, r.pkt, r.ibd,
                      r.hdr, r.hdr & 1u, r.skip ? "SKIP" : "EXEC");
                  // ★ RT_SEGTAB roster for this decode window: exactly what the guest submitted.
                  // Classify the extra draw's pkt against these ranges (FNF-7 verdict §3.4):
                  //   pkt >= wbase + last(off+len)          -> Site B (walk ran past the window)
                  //   pkt inside a seg with pre != src      -> Site A (relocation race)
                  //   pkt inside a clean, consistent seg    -> both die, escalate guest-side
                  { int sn = segSnap.n; if (sn > 64) sn = 64; if (sn < 0) sn = 0;
                    std::fprintf(stderr, "[segtab] f%ld wbase=0x%X nseg=%d\n", tripFrame, segSnap.wbase, sn);
                    for (int si = 0; si < sn; ++si) {
                      // ★ 2026-07-26 objDw: the GUEST'S OWN declared length. The SDK-runtime lane
                      // (C:/tmp/kicksem/KICK_SEMANTICS.md) traced the real ABI of sub_820A8638 from
                      // raw PPC (asm_vtables.txt:149338+): r4 = array of 8-byte descriptors
                      // {word0, addr}, r5 = segment COUNT, and the length is
                      // `lwz r11,0x0(r26); rlwinm r5,r11,0,8,31` = **word0 & 0x00FFFFFF**.
                      // r6 is NOT a parameter — the callee ASSIGNS it (li r6,0x1) and it carries a
                      // length only by accident on the sub_820A8B38 path; three other call sites
                      // never write it. Our capture uses r6 (rt.cpp:1847), so if that is stale this
                      // field will disagree. Prediction to test: objDw != latDw for s5, and
                      // objDw*4 <= 1012 (the phantom draw sits past the guest's real content end).
                      unsigned objDw = segSnap.objdw[si];   // kick-time snapshot (see rt.cpp)
                      std::fprintf(stderr, "[segtab]   s%d off=%u len=%u end=%u src=0x%X pre=0x%X obj=0x%X latDw=%u objDw=%u%s%s\n",
                        si, segSnap.off[si], segSnap.len[si], segSnap.off[si] + segSnap.len[si],
                        segSnap.src[si], segSnap.pre[si], segSnap.obj[si], segSnap.lat[si], objDw,
                        (objDw && objDw != segSnap.lat[si]) ? "  LENMISMATCH" : "",
                        (segSnap.pre[si] && segSnap.pre[si] != segSnap.src[si]) ? "  RELOCATED" : "");
                    } }
                }
                // ★ RVK_TAILDUMP=<pairs> (FNF-7 tail-byte forensics, 2026-07-26, default off).
                // The decisive experiment put the extra draw INSIDE the last kicked segment
                // (always s5, always 1252 B, packet ~240 B before its end) with no relocation and
                // no walk overrun — so the open question is where the guest's LIVE content ends
                // inside that segment and what marks it. Dump the segment's raw dwords for an
                // anomaly frame AND for the next CLEAN frame (the matched control: same window
                // shape one frame later). Byte-diffing the pair splits "our walk decodes bytes the
                // command processor would skip" (identical bytes, different decode) from "the
                // guest wrote different bytes that frame" (bytes differ).
                // Capped at N pairs so the log cost is bounded and cannot reproduce the
                // DRAWTRIP=8 observer effect; raw bytes only, all decoding happens offline.
                {
                  static int  tailPairs = std::getenv("RVK_TAILDUMP") ? atoi(std::getenv("RVK_TAILDUMP")) : 0;
                  static long tailDone = 0;
                  static bool wantClean = false;
                  if (tailPairs > 0 && tailDone < tailPairs && segSnap.n > 0 && tripFrame >= 0 && g_base) {
                    bool isAnom  = (int)tripBuf.size() >  tripN;
                    bool isClean = (int)tripBuf.size() == tripN;
                    if (isAnom || (wantClean && isClean)) {
                      int li = segSnap.n - 1;                 // the final kicked segment
                      uint32_t sOff = segSnap.off[li], sLen = segSnap.len[li];
                      uint32_t sAddr = segSnap.wbase + sOff;
                      if (sLen > 4096u) sLen = 4096u;         // bound the dump; s5 measures 1252
                      uint32_t lastPkt = tripBuf.empty() ? 0u : tripBuf.back().pkt;
                      uint32_t prevPkt = tripBuf.size() >= 2 ? tripBuf[tripBuf.size() - 2].pkt : 0u;
                      std::fprintf(stderr,
                        "[tail] f%ld %s draws=%zu wbase=0x%X seg=%d off=%u len=%u addr=0x%X src=0x%X latDw=%u lastPkt=0x%X prevPkt=0x%X lastOff=%d prevOff=%d\n",
                        tripFrame, isAnom ? "ANOM" : "CLEAN", tripBuf.size(), segSnap.wbase, li,
                        segSnap.off[li], segSnap.len[li], sAddr, segSnap.src[li], segSnap.lat[li],
                        lastPkt, prevPkt, (int)(lastPkt - sAddr), (int)(prevPkt - sAddr));
                      for (uint32_t k = 0; k < sLen; k += 32) {
                        char hb[128]; int ho = 0;
                        for (uint32_t j = 0; j < 32 && k + j < sLen; j += 4)
                          ho += std::snprintf(hb + ho, sizeof(hb) - ho, " %08X", be32(sAddr + k + j));
                        std::fprintf(stderr, "[tail]   +%04u:%s\n", k, hb);
                      }
                      if (isAnom) wantClean = true; else { wantClean = false; ++tailDone; }
                    }
                  }
                }
                tripBuf.clear(); tripFrame = frame; tripWinStart = start;
                { int sn = (int)g_seg_n; if (sn > 64) sn = 64; if (sn < 0) sn = 0;
                  segSnap.n = sn; segSnap.wbase = (uint32_t)g_seg_wbase;
                  for (int si = 0; si < sn; ++si) {
                    segSnap.off[si] = g_seg_off[si]; segSnap.len[si] = g_seg_len[si];
                    segSnap.src[si] = g_seg_src[si]; segSnap.pre[si] = g_seg_pre[si];
                    segSnap.obj[si] = g_seg_obj[si]; segSnap.lat[si] = g_seg_lat[si];
                    segSnap.objdw[si] = g_seg_objdw[si]; } }
              }
              // ★ RVK_TRIPUV (FNF-7 atlas-staleness discriminator, 2026-07-26, default off):
              // an anomaly frame is one whose draw count EXCEEDS tripN, so the draw being pushed
              // when tripBuf already holds tripN entries IS the extra one — and we are still at
              // DRAW TIME, with the guest's vertex records and atlas bytes exactly as the GPU is
              // about to see them (the [drawtrip] frame dump above fires a frame later, by which
              // point the vertex ring has been rewritten — do NOT read UVs from there).
              // Prints the extra quad's raw stride-24 records, its UV rect, and a black/nonblack
              // census of that rect read from BOTH live guest RAM and the upload-time snapshot.
              // Level 2 also censuses the last EARLIER draw sampling the SAME atlas — the
              // positive control: that quad is visible menu art, so it must census as non-black.
              // Measurement only; nothing here touches the vertex/index/descriptor state.
              if (rvkTripUvLevel() > 0 && (int)tripBuf.size() >= tripN && n >= 3 && n <= 8) {
                auto census1 = [&](const char* tag, int dIdx, uint32_t dva, uint32_t dn,
                                   uint32_t dtex, uint32_t dbase, uint32_t dtw, uint32_t dth) {
                  // stride-24 guest record {x,y,z,color,u,v}: uv are dwords 4 and 5.
                  float uMin = 1e30f, uMax = -1e30f, vMin = 1e30f, vMax = -1e30f;
                  for (uint32_t k = 0; k < dn; ++k) {
                    float uf = bef(dva + k * 24 + 16), vf = bef(dva + k * 24 + 20);
                    if (!(uf == uf) || !(vf == vf)) return;   // NaN -> record is not this layout
                    uMin = std::min(uMin, uf); uMax = std::max(uMax, uf);
                    vMin = std::min(vMin, vf); vMax = std::max(vMax, vf);
                  }
                  std::fprintf(stderr, "[tripuv] f%ld %s d%d n=%u va=0x%X tex=%u base=0x%X %ux%u uv=[%.5f,%.5f]x[%.5f,%.5f]\n",
                    frame, tag, dIdx, dn, dva, dtex, dbase, dtw, dth, uMin, uMax, vMin, vMax);
                  for (uint32_t k = 0; k < dn; ++k)
                    std::fprintf(stderr, "[tripuv]   %s rec%u: %08X %08X %08X %08X %08X %08X  xy=(%.2f,%.2f) uv=(%.5f,%.5f)\n",
                      tag, k, be32(dva + k*24), be32(dva + k*24+4), be32(dva + k*24+8),
                      be32(dva + k*24+12), be32(dva + k*24+16), be32(dva + k*24+20),
                      bef(dva + k*24), bef(dva + k*24+4), bef(dva + k*24+16), bef(dva + k*24+20));
                  auto sit = g_tripSnap.find(dbase);
                  if (sit == g_tripSnap.end()) {
                    std::fprintf(stderr, "[tripuv]   %s NO SNAPSHOT for base=0x%X (not watched / not yet uploaded)\n", tag, dbase);
                    return;
                  }
                  RvkAtlasSnap& s = sit->second;
                  // UVs in this record class are NORMALIZED; scale to texels. If they already look
                  // like texel coords (>1.01) use them raw so a layout surprise is still measured.
                  bool norm = (uMax <= 1.01f && vMax <= 1.01f);
                  double sx = norm ? (double)s.w : 1.0, sy = norm ? (double)s.h : 1.0;
                  long x0l = (long)std::floor(uMin * sx), x1l = (long)std::ceil(uMax * sx);
                  long y0l = (long)std::floor(vMin * sy), y1l = (long)std::ceil(vMax * sy);
                  if (x0l < 0) x0l = 0; if (y0l < 0) y0l = 0;
                  if (x1l > (long)s.w) x1l = s.w; if (y1l > (long)s.h) y1l = s.h;
                  if (x1l <= x0l || y1l <= y0l) {
                    std::fprintf(stderr, "[tripuv]   %s DEGENERATE rect x[%ld,%ld) y[%ld,%ld) norm=%d\n", tag, x0l, x1l, y0l, y1l, (int)norm);
                    return;
                  }
                  uint32_t x0 = (uint32_t)x0l, x1 = (uint32_t)x1l, y0 = (uint32_t)y0l, y1 = (uint32_t)y1l;
                  RvkCensus live = rvkCensusRect(nullptr, 0, dbase, s.w, s.h, s.lb, s.fpitch, s.linear, x0, y0, x1, y1);
                  RvkCensus snap = rvkCensusRect(s.bytes.data(), s.bytes.size(), dbase, s.w, s.h, s.lb, s.fpitch, s.linear, x0, y0, x1, y1);
                  std::fprintf(stderr, "[tripuv]   %s rect x[%u,%u) y[%u,%u) norm=%d uploads=%ld\n", tag, x0, x1, y0, y1, (int)norm, s.uploads);
                  std::fprintf(stderr, "[tripuv]   %s LIVE n=%u zeroPx=%u rgbBlack=%u opaqueBlack=%u alpha0=%u meanLuma=%.2f sig=0x%08X\n",
                    tag, live.n, live.nZeroPx, live.nRgbBlack, live.nOpaqueBlack, live.nAlpha0, live.meanLuma, live.sig);
                  std::fprintf(stderr, "[tripuv]   %s SNAP n=%u zeroPx=%u rgbBlack=%u opaqueBlack=%u alpha0=%u meanLuma=%.2f sig=0x%08X\n",
                    tag, snap.n, snap.nZeroPx, snap.nRgbBlack, snap.nOpaqueBlack, snap.nAlpha0, snap.meanLuma, snap.sig);
                  std::fprintf(stderr, "[tripuv]   %s VERDICT-BITS sigMatch=%d liveBlackFrac=%.4f snapBlackFrac=%.4f\n",
                    tag, (int)(live.sig == snap.sig),
                    live.n ? (double)live.nRgbBlack / live.n : -1.0,
                    snap.n ? (double)snap.nRgbBlack / snap.n : -1.0);
                };
                census1("EXTRA", ndraw, va, n, texIdx, base, tw, th);
                if (rvkTripUvLevel() >= 2) {   // positive control: last earlier draw on the same atlas
                  for (size_t bi = tripBuf.size(); bi-- > 0;) {
                    if (tripBuf[bi].base == base && tripBuf[bi].n >= 3 && tripBuf[bi].n <= 8) {
                      census1("CTRL", tripBuf[bi].nd, tripBuf[bi].va, tripBuf[bi].n,
                              tripBuf[bi].texIdx, tripBuf[bi].base, tripBuf[bi].tw, tripBuf[bi].th);
                      break;
                    }
                  }
                }
              }
              if (tripBuf.size() < 64)
                tripBuf.push_back({ndraw, n, va, texIdx, fmt, base, tw, th, i, be32(i), (int)ibStack.size(),
                                   g_curVsIdx, g_curPsIdx,
                                   (int)((be32(i) & 1u) && ((binSelect & binMask) == 0)), bef(va), bef(va + 4)});
            }
          }
          // ★ RVK_PREDLOG per-draw census — runs on EVERY frame (the [drawtrip] dump only fires
          // on anomaly frames, but the blast-radius question needs clean frames too). `i` is still
          // the packet header address here. Counting only; nothing is skipped or altered.
          if (predLog) {
            uint32_t hw = be32(i);
            ++predTot;
            if (hw & 1u) { ++predBitSet; if ((binSelect & binMask) == 0) ++predWouldSkip; }
          }
          // ★ RVK_GDPROBE (2026-07-28, alt-B ghost-draw arm discriminator wf_b8847446): on shell
          // frames, batch index >= 2 = the anomaly class (M2 hold has exactly 2 legit batches).
          // Print which c255 site produced this draw's constants + raw verts + va context so one
          // boot decides Arm A (zero-rescue/clobber re-projects a guest-collapsed draw) vs Arm B
          // (walk-time vertex bytes differ from kick-time). Printing only; nothing altered.
          {
            // env value doubles as the from-frame (=1: all frames; =160: skip the legit
            // multi-batch NOW-LOADING phase f12-165 that exhausted the cap on the first boot).
            static long gdProbe = std::getenv("RVK_GDPROBE") ? std::strtol(std::getenv("RVK_GDPROBE"), nullptr, 10) : 0;
            if (gdProbe && frame >= gdProbe && g_base && be32(GA_FIELD_ACTIVE) == 0 && g_rt_romactive == 0 && ndraw >= 2 && ndraw <= 6) {
              static long gdPrinted = 0;
              if (gdPrinted < 400) { gdPrinted++;
                std::fprintf(stderr, "[gdprobe] f%ld draw%d vs=%d ps=%d tex=%u fmt=%u base=0x%X va=0x%X n=%u vte=0x%X prim=%u"
                  " rescued=%d clob=%d c255pre={%g,%g,%g,%g} c255now={%g,%g,%g,%g}\n",
                  frame, ndraw, g_curVsIdx, g_curPsIdx, texIdx, fmt, base, va, n, g_vteCntl, drawPrim,
                  (int)g_gdRescued, (int)g_gdClobbered,
                  g_gdC255pre[0], g_gdC255pre[1], g_gdC255pre[2], g_gdC255pre[3],
                  g_gdEffC255[0], g_gdEffC255[1], g_gdEffC255[2], g_gdEffC255[3]);
                for (uint32_t vk2 = 0; vk2 < n && vk2 < 4; ++vk2) {
                  const float* fv = (const float*)(Vraw + (size_t)(v0 + vk2) * 6);
                  std::fprintf(stderr, "[gdprobe]   v%u=(%.4f,%.4f,%.4f) col=0x%08X uv=(%.4f,%.4f)\n",
                    vk2, fv[0], fv[1], fv[2], ((const uint32_t*)fv)[3], fv[4], fv[5]);
                }
                std::fprintf(stderr, "[gdprobe]   va raw:");
                for (int c2 = 0; c2 < 8; ++c2) std::fprintf(stderr, " %08X", be32(va + c2 * 4));
                std::fprintf(stderr, " | RB 2200=%08X 2201=%08X 2208=%08X 2318=%08X vp={%.0f,%.0f,%.0f,%.0f}\n",
                  g_regFile[0x2200], g_regFile[0x2201], g_regFile[0x2208], g_regFile[0x2318],
                  drawVp.x, drawVp.y, drawVp.width, drawVp.height);
              }
            }
          }
          // ★ RVK_DRAWCENSUS count hook (compose-1:1 Leg 1): counting only, nothing altered.
          {
            static int censOn = std::getenv("RVK_DRAWCENSUS") ? atoi(std::getenv("RVK_DRAWCENSUS")) : 0;
            if (censOn && g_base && be32(GA_FIELD_ACTIVE) == 0) {
              static int censTest = std::getenv("RVK_CENSUSTEST") ? atoi(std::getenv("RVK_CENSUSTEST")) : 0;
              // inject on the census's own presented-frame clock — the walk's frame numbers can
              // jump under pacing, so frame%N may never hit (2nd positive-control failure mode).
              bool inject = censTest && g_censTestBase && base == g_censTestBase && (g_censPc % 250) == 249;
              if (inject) { static long inj = 0;
                if ((inj++ % 8) == 0) std::fprintf(stderr, "[census] INJECT pc=%ld f%ld base=0x%X (control skip)\n", g_censPc, frame, base); }
              if (!inject) {
                uint64_t ck = ((uint64_t)base << 16) ^ ((uint64_t)(g_curVsIdx & 0xFF) << 8) ^ (uint64_t)(g_curPsIdx & 0xFF);
                auto it = g_censMap.find(ck);
                if (it == g_censMap.end()) {
                  if (g_censMap.size() < 512) it = g_censMap.emplace(ck, RvkCensusEnt{}).first;
                }
                if (it != g_censMap.end()) {
                  RvkCensusEnt& e = it->second;
                  if (e.cnt == 0) {  // first sighting this frame: record identity context
                    const float* fv = (const float*)(Vraw + (size_t)v0 * 6);
                    e.v0x = fv[0]; e.v0y = fv[1]; e.gdA = g_gdTookA; e.vte = g_vteCntl;
                  }
                  e.cnt++;
                }
              }
            }
          }
          ndraw++;
        }
      } else if (op == 0x3F) { // INDIRECT_BUFFER: dword1=base guest addr, dword2=size(dwords)
        uint32_t ibBase = be32(i + 4) & ~3u;
        uint32_t ibSize = be32(i + 8) & 0xFFFFFu;
        uint32_t next = i + 4 * (1 + cnt);
        bool descend = ibBase && ibSize && ibSize < 0x100000u && ibStack.size() < 8;
        if (ibT) std::fprintf(stderr, "[ibtrace] frame%ld IB base=0x%X size=%u dwords %s (at ndraw=%d nresolves=%zu depth=%zu)%s\n",
          frame, ibBase, ibSize, descend ? "DESCEND" : "SKIP", ndraw, resolves.size(), ibStack.size(),
          (!descend && ibBase && ibSize) ? (ibSize >= 0x100000u ? " [SKIP: size too big!]" : (ibStack.size() >= 8 ? " [SKIP: stack full!]" : "")) : "");
        if (descend) {
          ibStack.push_back(((uint64_t)next << 32) | end); i = ibBase; end = ibBase + ibSize * 4;
        } else { i = next; }
        continue;
      }
      i += 4 * (1 + cnt);
    } else if (t == 2) { i += 4; }   // TYPE2 = 1-dword NOP filler
    else {
      // TYPE1 = TWO register writes packed in the header: regs [10:0] and [21:11], two payload
      // dwords, 3 dwords total (SDK rexglue-sdk command_processor.cpp:835-847). We previously
      // `break`'d here, which silently ABANDONED THE WHOLE WINDOW — including any parent streams
      // still on ibStack — turning one stray TYPE1 into wholesale missing geometry. A float >= 2.0
      // (e.g. 640.0f = 0x44200000) has top bits 01, so a desynced parser lands on "TYPE1" often.
      writeReg(w & 0x7FF, be32(i + 4));
      writeReg((w >> 11) & 0x7FF, be32(i + 8));
      i += 12;
    }
  }
  // ★ RVK_SEGALIGN result for this frame: one compact line, plus a detail line per misalignment.
  // draws= lets the offline split into anomaly (62) vs clean (61) frames.
  if (segAlign && saN > 0) {
    char sb[512]; int so = 0;
    for (int k = 0; k < saN && so < (int)sizeof(sb) - 40; ++k)
      so += saHit[k] ? std::snprintf(sb + so, sizeof(sb) - so, " b%d=%u", k + 1, saDelta[k])
                     : std::snprintf(sb + so, sizeof(sb) - so, " b%d=MISS", k + 1);
    std::fprintf(stderr, "[segalign] f%ld draws=%d wbase=0x%X nb=%d%s\n", frame, ndraw, saWbase, saN, sb);
    for (int k = 0; k < saN; ++k)
      if (saHit[k] && saDelta[k] != 0)
        std::fprintf(stderr, "[segalign]   f%ld MISALIGNED b%d base=0x%X arrivedAt=0x%X delta=%u prevPkt=0x%X hdr=%08X type=%u op=0x%02X cnt=%u reach=%d\n",
          frame, k + 1, saB[k], saB[k] + saDelta[k], saDelta[k], saPrevPkt[k], saPrevHdr[k],
          saPrevHdr[k] >> 30, (saPrevHdr[k] >> 8) & 0x7F, ((saPrevHdr[k] >> 16) & 0x3FFF) + 2,
          (int)((saB[k] + saDelta[k]) - saB[k]));
  }
  if (predLog) {
    std::fprintf(stderr, "[predcensus] f%ld draws=%d predicated=%ld wouldSkip=%ld binSets=%ld binMask=0x%llX binSelect=0x%llX pass=%d\n",
      frame, ndraw, predBitSet, predWouldSkip, binSets, (unsigned long long)binMask,
      (unsigned long long)binSelect, (int)((binSelect & binMask) != 0));
  }
  flushBatch(ni);
  perf_.lap();   // decode/extract phase ends here; the rest is resolve/render/present tail
  p3FrameBegin();   // [perflog3] tail attribution starts here (no-op unless RVK_PERFLOG3=1)
  if (perflog2) {
    static double accTex = 0, accCst = 0, accVtx = 0, accDecode = 0; static long accNTex = 0, accNCst = 0, accNDraw = 0; static long p2n = 0;
    static double accIm = 0, accPipe = 0, accReg = 0; static long accNIm = 0, accNPipe = 0;
    accTex += p2Tex; accCst += p2Cst; accVtx += p2Vtx; accDecode += perf_.lapMs; accNTex += p2NTexCalls; accNCst += p2NCstSnaps; accNDraw += ndraw;
    accIm += p2Im; accPipe += p2Pipe; accReg += p2Reg; accNIm += p2NIm; accNPipe += p2NPipe;
    if ((p2n++ % 32) == 0) {
      double other = accDecode - accTex - accCst - accVtx - accIm - accPipe - accReg;
      std::fprintf(stderr, "[perflog2] f%ld decode=%.2fms tex=%.2fms(n=%.0f) cst=%.2fms(n=%.0f) vtx=%.2fms im=%.2fms(n=%.0f) pipe=%.2fms(n=%.0f) reg=%.2fms other=%.2fms draws=%.0f (avg over 32)\n",
                   frame, accDecode / 32, accTex / 32, (double)accNTex / 32, accCst / 32, (double)accNCst / 32, accVtx / 32,
                   accIm / 32, (double)accNIm / 32, accPipe / 32, (double)accNPipe / 32, accReg / 32, other / 32, (double)accNDraw / 32);
      accTex = accCst = accVtx = accDecode = 0; accNTex = accNCst = accNDraw = 0;
      accIm = accPipe = accReg = 0; accNIm = accNPipe = 0;
    }
  }

  // [s5r] correlate draws-per-frame with the game FSM state (shared address space): every
  // 600th frame print fsm + ndraw so we see whether the menu (state 5) actually emits draws.
  if (std::getenv("RVK_S5") && g_base) {
    static long fc = 0;
    if ((fc++ % 600) == 0) {
      uint32_t fsm = __builtin_bswap32(*(const uint32_t*)(g_base + 0x884D66A8u));
      // Transform ground truth: live viewport regs, live c255, and the predicted pixel of the
      // first extracted vertex (records are already floats in Vraw after i48int conversion).
      float vx = 0.f, vy = 0.f, px = -9999.f, py = -9999.f;
      if (nv > 0) {
        std::memcpy(&vx, Vraw + 0, 4); std::memcpy(&vy, Vraw + 1, 4);
        float ndcx = vx * g_vsConstF[1020] + g_vsConstF[1022];
        float ndcy = vy * g_vsConstF[1020] + g_vsConstF[1022];
        VkViewport vp = currentViewport();
        px = vp.x + (ndcx + 1.f) * 0.5f * vp.width;
        py = vp.y + (1.f - ndcy) * 0.5f * vp.height;  // invert-y
      }
      std::fprintf(stderr, "[s5r] frame%ld fsm=%u draws=%d verts=%u | xs=%.0f xo=%.0f ys=%.0f yo=%.0f c255={%.5f,%.5f,%.2f,%.2f} v0=(%.0f,%.0f)->px(%.0f,%.0f)\n",
        frame, fsm, ndraw, nv, g_xscale, g_xoffset, g_yscale, g_yoffset,
        g_vsConstF[1020], g_vsConstF[1021], g_vsConstF[1022], g_vsConstF[1023], vx, vy, px, py);
    }
  }

  // Render policy: sampled frames always produce /tmp/rvk_frameN.png. Additionally, with
  // RVK_RENDER_FROM=N set, every frame >= N whose window contains draws is rendered into the
  // persistent offscreen image and periodically saved to /tmp/rvk_last.png — this catches
  // screens the guest draws only once (e.g. the static replay screen), whose ring windows
  // are overwritten long before any fixed sample index lands on them.
  static long renderFrom = std::getenv("RVK_RENDER_FROM") ? std::strtol(std::getenv("RVK_RENDER_FROM"), nullptr, 10) : -1;
  static bool everRendered = false;
  bool wantLast = renderFrom >= 0 && frame >= renderFrom && ndraw > 0;
  if (dumpOps && !dumpedOps && ndraw > 0) {
    dumpedOps = true;
    std::fprintf(stderr, "[rvk][ops] frame%ld draws=%d TYPE3 ops:", frame, ndraw);
    for (auto& kv : opHist) std::fprintf(stderr, " 0x%02X x%u", kv.first, kv.second);
    std::fprintf(stderr, "\n[rvk][ops] TYPE0 base regs:");
    for (auto& kv : regHist) std::fprintf(stderr, " 0x%04X x%u", kv.first, kv.second);
    std::fprintf(stderr, "\n[rvk][ops] M2LibMatrix c0=(%.4f,%.4f,%.4f,%.4f) c1=(%.4f,%.4f,%.4f,%.4f) c2=(%.4f,%.4f,%.4f,%.4f) c3=(%.4f,%.4f,%.4f,%.4f) vte=0x%X\n",
      g_vsConstF[0],g_vsConstF[1],g_vsConstF[2],g_vsConstF[3], g_vsConstF[4],g_vsConstF[5],g_vsConstF[6],g_vsConstF[7],
      g_vsConstF[8],g_vsConstF[9],g_vsConstF[10],g_vsConstF[11], g_vsConstF[12],g_vsConstF[13],g_vsConstF[14],g_vsConstF[15], g_vteCntl);
    for (int cc = 0; cc < 8; ++cc)
      std::fprintf(stderr, "[rvk][ops] psC%d=(%.4f,%.4f,%.4f,%.4f) vsC%d=(%.4f,%.4f,%.4f,%.4f)\n",
        cc, g_psConstF[cc*4], g_psConstF[cc*4+1], g_psConstF[cc*4+2], g_psConstF[cc*4+3],
        cc+4, g_vsConstF[16+cc*4], g_vsConstF[16+cc*4+1], g_vsConstF[16+cc*4+2], g_vsConstF[16+cc*4+3]);
    for (uint32_t vi = 0; vi + 4 <= nv && vi < 24; vi += 4) {
      uint32_t* d0 = Vraw + (size_t)vi * 6;
      float x0,y0,z0; std::memcpy(&x0,&d0[0],4); std::memcpy(&y0,&d0[1],4); std::memcpy(&z0,&d0[2],4);
      std::fprintf(stderr, "[rvk][ops] vert%u raw pos=(%.3f,%.3f,%.3f) col=0x%08X\n", vi, x0,y0,z0, d0[3]);
    }
  }
  bool doRender = (render && (ndraw > 0 || !everRendered)) || wantLast;
  // ★ RVK_DRAWCENSUS frame close (compose-1:1 Leg 1): advance streaks only on frames that
  // RECOMPOSE (doRender && ndraw>0). A zero-draw window holds the previous image — no visual
  // hole — so it must not advance the census clock (else every steady identity fakes a drop).
  {
    static int censOn2 = std::getenv("RVK_DRAWCENSUS") ? atoi(std::getenv("RVK_DRAWCENSUS")) : 0;
    static int censK = std::getenv("RVK_DRAWCENSUS_K") ? atoi(std::getenv("RVK_DRAWCENSUS_K")) : 8;
    static int censR = std::getenv("RVK_DRAWCENSUS_R") ? atoi(std::getenv("RVK_DRAWCENSUS_R")) : 3;
    if (censOn2 && doRender && ndraw > 0 && g_base && be32(GA_FIELD_ACTIVE) == 0) {
      g_censPc++;
      bool sceneJump = g_censLastTotal > 0 &&
                       (ndraw > 3 * g_censLastTotal || 3 * ndraw < g_censLastTotal);
      g_censLastTotal = ndraw;
      uint8_t cb = *(g_base + 0x821EC65Bu);
      int sn = (int)g_seg_n;
      for (auto it = g_censMap.begin(); it != g_censMap.end(); ) {
        RvkCensusEnt& e = it->second;
        bool erase = false;
        if (sceneJump) { e.streak = e.cnt > 0 ? 1 : 0; e.missSince = -1; }
        else if (e.cnt > 0) {
          if (e.missSince >= 0) {   // returned after a gap
            long len = g_censPc - e.missSince;
            if (len <= censR)
              std::fprintf(stderr, "[census] f%ld DROPOUT-CONFIRMED len=%ld base=0x%X vs=%d ps=%d steady=%d streak=%ld lastv0=(%.1f,%.1f) clear=%u gdA=%d vte=0x%X missNseg=%d missTotal=%d retNseg=%d\n",
                frame, len, (uint32_t)(it->first >> 16), (int)((it->first >> 8) & 0xFF), (int)(it->first & 0xFF),
                e.steadyCnt, e.missStreak, e.v0x, e.v0y, cb, (int)e.gdA, e.vte, e.missNseg, e.missTotal, sn);
            e.missSince = -1; e.streak++;
          } else {
            e.streak++;
            e.steadyCnt = e.cnt;
          }
        } else {                    // cnt == 0 on a recomposed frame
          if (e.streak >= censK && e.missSince < 0) { e.missSince = g_censPc; e.missStreak = e.streak; e.missNseg = sn; e.missTotal = ndraw; }
          else if (e.missSince >= 0 && g_censPc - e.missSince > censR) { erase = true; }   // dismissal
          else if (e.missSince < 0) { erase = (e.streak == 0); e.streak = 0; }             // never-steady
        }
        e.cnt = 0;
        if (erase) it = g_censMap.erase(it); else ++it;
      }
      // fault-injection target = the CURRENTLY longest-steady identity (a first-steady lock
      // dies with its boot phase — the loading-phase element is dismissed long before the
      // injection frames; 1st positive-control failure, 2026-07-28).
      long best = censK - 1; g_censTestBase = 0;
      for (auto& kv : g_censMap)
        if (kv.second.streak > best && kv.second.missSince < 0) { best = kv.second.streak; g_censTestBase = (uint32_t)(kv.first >> 16); }
      if (censOn2 >= 2) {
        static long vst = 0;
        if ((vst++ % 120) == 0)
          std::fprintf(stderr, "[census] status pc=%ld ids=%zu maxstreak=%ld testbase=0x%X total=%d\n",
            g_censPc, g_censMap.size(), best, g_censTestBase, ndraw);
      }
    }
  }
  if (!render && !doRender) return true;  // state-only walk (unsampled frame)

  if (doRender) {
    VkClearValue clear{}; clear.color = {{0.0f, 0.0f, 0.10f, 1.0f}};
    // ★ GUEST CLEAR COLOUR (2026-07-27 night, FNF-12 seam fix, decomp SPEC_shell_compose_1to1 §4.1):
    // the guest's veil/clear pass calls D3DDevice_Clear with Color = *(u32*)(R+0x218) where
    // R = *(*(0x821F85B0)+0x9C) — during the M2 logo phase that colour is WHITE. Our hardcoded
    // navy showed through the M2 atlas quad's DXT1 punch-through gutters (packing seams at
    // x=513/y=447) = the black cross baked into resolve 0x723000 by the restore loop
    // (m2hold_forensics res_f000384/445/508 dumps). Hardware clears white -> seams invisible.
    // Scope: SHELL frames only (field/ROM keep the tuned navy). RVK_NOGCLRCOL=1 reverts.
    { static bool gclrOff = std::getenv("RVK_NOGCLRCOL") && atoi(std::getenv("RVK_NOGCLRCOL")) != 0;
      if (!gclrOff && g_base && be32(GA_FIELD_ACTIVE) == 0 && g_rt_romactive == 0) {
        uint32_t envP = be32(0x821F85B0u);
        uint32_t rP = envP ? be32(envP + 0x9Cu) : 0;
        if (rP) {
          uint32_t gc = be32(rP + 0x218u);   // D3DCOLOR ARGB
          clear.color.float32[0] = ((gc >> 16) & 0xFF) / 255.0f;
          clear.color.float32[1] = ((gc >> 8) & 0xFF) / 255.0f;
          clear.color.float32[2] = (gc & 0xFF) / 255.0f;
          clear.color.float32[3] = ((gc >> 24) & 0xFF) / 255.0f;
          static uint32_t gcLast = 0xDEADBEEFu; static int gcN = 0;
          if (gc != gcLast && gcN < 20) { gcLast = gc; ++gcN;
            std::fprintf(stderr, "[rvk][gclrcol] frame%ld guest clear colour = 0x%08X\n", frame, gc); }
        }
      } }
    // [compdbg] LEG-40 composite diagnosis: env RVK_COMPDBG. Build the set of resolve-texture
    // bindless indices for this frame so submitSeg can flag composite quads that sample them.
    static bool compDbg = std::getenv("RVK_COMPDBG") != nullptr;
    // Populated UNCONDITIONALLY (cheap; a few resolve dests): both the [compdbg] dump AND the
    // RVK_WALLBG=3 wallpaper filter (below, pillarbox path) use it to tell the true full-screen cave
    // wallpaper (a plain textured layer) apart from the vs=5 playfield-COMPOSITE draws that share the
    // same deep-negative 2x-zoom viewport but SAMPLE a resolved surface (tex is a resolve index).
    std::set<uint32_t> g_compResolveIdx;
    for (auto& r : resolves) { auto it = g_resolveTex.find(r.dst); if (it != g_resolveTex.end()) g_compResolveIdx.insert(it->second.idx); }
    // RVK_TITLETL (legacy-title-blink probe 2026-07-21): one timeline line per RENDERED window —
    // wall-ms, batch/resolve census, vs5rect16 restore presence, and a sparse checksum of guest
    // memory at the frame base (env value = hex base; "1" = default 0xF005000). Correlate with the
    // 0.5s rvk_last.png series from persist_title_ab.sh to split GUEST-side blink (sum/diff
    // alternate with the window) from PORT-side loss (sum steady + diff high while window blinks).
    // diff = samples differing from the first sample: ~0 means the buffer is a solid fill.
    static uint32_t titleTlBase = [](){ const char* e = std::getenv("RVK_TITLETL");
      if (!e) return 0u; uint32_t v = (uint32_t)strtoul(e, nullptr, 16);
      return v > 1u ? v : 0xF005000u; }();
    if (titleTlBase) {
      static RvkClock::time_point ttlT0 = RvkClock::now();
      uint32_t x = 0, nzS = 0, s0 = be32(titleTlBase);
      for (uint32_t i = 0; i < 1024; ++i) {          // ~3.6MB span, 1024 sparse dword samples
        uint32_t v = be32(titleTlBase + i * 3600u);
        x ^= v + i; if (v != s0) ++nzS;
      }
      // vhash: FNV over this window's DECODED vertex stream — discriminates guest-side content
      // animation (vhash cycles with the on-screen state) from port-side display cycling
      // (vhash constant while the window changes).
      uint32_t vh = 2166136261u;
      for (size_t vi2 = 0; vi2 < (size_t)nv * 6; ++vi2) vh = (vh ^ Vraw[vi2]) * 16777619u;
      std::fprintf(stderr, "[titletl] t=%.0fms f=%ld nb=%zu res=%zu ndraw=%ld r16=%ld r16base=0x%X sum=%08X diff=%u vhash=%08X\n",
        rvkMs(ttlT0), frame, batches.size(), resolves.size(), (long)ndraw,
        g_ttl_rect16, g_ttl_rectBase, x, nzS, vh);
      g_ttl_rect16 = 0;
    }
    // RVK_COMPQUAD=<n> (2026-07-17 off-centre panel): dump the geometry of every batch that SAMPLES
    // a resolve texture (i.e. the guest's own composite/placement quads) — viewport + the first 4
    // indexed vertices' pos/uv. This is the ground truth for how the guest maps the panel resolve's
    // CONTENT sub-rect onto the screen (the oracle scales the card's ~410-col content to the full
    // 480x640 panel; we currently blit 1:1 and show the undrawn band). n = max lines to print.
    {
      static long compQuadMax = std::getenv("RVK_COMPQUAD") ? std::strtol(std::getenv("RVK_COMPQUAD"), nullptr, 10) : 0;
      static long compQuadN = 0;
      static std::set<uint64_t> compQuadSeen;   // dedupe by geometry signature: each unique quad prints ONCE
      // Gate on the ROM attract (the scenes under diagnosis) + sample every 32nd frame — boot/shell
      // quads ANIMATE (drifting positions = fresh signature every frame) and drown the line cap.
      if (compQuadMax > 0 && compQuadN < compQuadMax && g_rt_romactive != 0 && (frame % 32) == 0) {
        std::set<uint32_t> anyResIdx; for (auto& kv : g_resolveTex) anyResIdx.insert(kv.second.idx);
        for (auto& b : batches) {
          if (!anyResIdx.count(b.texIdx) || compQuadN >= compQuadMax) continue;
          uint32_t rDst = 0, rW = 0, rH = 0;
          for (auto& kv : g_resolveTex) if (kv.second.idx == b.texIdx) { rDst = kv.first; rW = kv.second.w; rH = kv.second.h; break; }
          char vb[384]; int vo = 0; uint64_t sig = ((uint64_t)b.vsIdx << 56) ^ ((uint64_t)rW << 40) ^ ((uint64_t)rH << 24) ^ b.indexCount;
          for (uint32_t k = 0; k < 6 && k < b.indexCount; ++k) {
            const float* f = (const float*)(Vraw + (size_t)Iarr[b.firstIndex + k] * 6);
            float x = f[0], y = f[1], u, v;
            if (b.vsIdx == 48) { u = f[2]; v = f[3]; } else { u = f[4]; v = f[5]; }
            vo += std::snprintf(vb + vo, sizeof vb - vo, " (%.0f,%.0f uv %.3f,%.3f)", x, y, u, v);
            sig = sig * 0x100000001B3ull ^ (uint64_t)(int64_t)(x * 4) ^ ((uint64_t)(int64_t)(y * 4) << 16)
                ^ ((uint64_t)(int64_t)(u * 64) << 32) ^ ((uint64_t)(int64_t)(v * 64) << 48);
          }
          if (!compQuadSeen.insert(sig).second) continue;   // geometry already reported
          std::fprintf(stderr, "[compquad] f%ld vs=%d tex=%u res=0x%X(%ux%u) idxCnt=%u vp={%.0f,%.0f,%.0f,%.0f}%s\n",
                       frame, b.vsIdx, b.texIdx, rDst, rW, rH, b.indexCount, b.vp.x, b.vp.y, b.vp.width, b.vp.height, vb);
          ++compQuadN;
        }
      }
    }
    // Count non-clear pixels currently in g.readback (after a readback copy) — proves whether a
    // layer segment actually rendered content into the offscreen (vs black = wrong viewport).
    auto countOffscreenNonClear = [&]() -> long {
      void* map = nullptr; if (vkMapMemory(g.dev, g.readbackMem, 0, VK_WHOLE_SIZE, 0, &map) != VK_SUCCESS) return -1;
      const uint32_t* px = (const uint32_t*)map; long nz = 0; uint32_t c0 = px[0];
      for (uint32_t i = 0; i < kW * kH; ++i) if (px[i] != c0) ++nz;
      vkUnmapMemory(g.dev, g.readbackMem); return nz;
    };
    // Render batches [b0,b1) into the shared offscreen (= Xenos EDRAM, reused per pass); the
    // renderpass clears it. Optionally read back (final composite segment). Each segment is its
    // own fence-synced submit, so no intra-command-buffer barriers are needed.
    // forcePersist (legacy-title-blink fix 2026-07-21): -1 = heuristic (unchanged), 1 = force the
    // LOAD pass (EDRAM-persistence model; still CLEARs the very first window), 0 = force CLEAR.
    auto submitSeg = [&](size_t b0, size_t b1, bool readback, size_t e0 = 0, size_t e1 = 0, int forcePersist = -1) {
      segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
      rvkRingNext("rseg"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(rseg)");
      VkCommandBufferBeginInfo cbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; cbi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
      VKC(vkBeginCommandBuffer(g.cmd, &cbi), "begin(rseg)"); if (rvkRingOn()) rvkRingGuard();
      // RVK_PERSIST: on pure-2D shell frames (no EDRAM resolves) the guest only *periodically*
      // redraws the static full-screen background (title sky, etc.) and relies on framebuffer
      // persistence for it in between; our per-frame CLEAR wiped it -> title-sky flicker. But
      // steady screens (menu, dialogs) redraw fully every frame, and blind persistence there
      // stacks moving UI into ghost trails. So persist ONLY on genuine partial-redraw frames:
      // batch count well below this screen's recent peak. Peak raises instantly, decays slowly
      // (biased high = "clear more often", which is the safe direction). First rendered frame and
      // any resolve/gameplay frame always CLEAR, leaving those paths unchanged.
      // RETIRED-BY-EVIDENCE (2026-07-20 three-arm title-hold study, follows e64c9a5): the
      // heuristic no longer protects anything observable in ANY current run shape. Ship/hook
      // recipe: ZERO engagements (e64c9a5). Legacy plain-boot title (its home defect): the
      // title blinks on a ~2.5s cycle IDENTICALLY with PERSIST on, off, and with
      // RVK_VS5RECTALL=0 (sampled 0.5s x 140, state sequences byte-class-identical) — the
      // engagements (120+ cap) fire but change nothing on-window. Legacy nav with PERSIST=0
      // traverses save-dialogs->title->menus->mode-select cleanly. Scripts still export
      // RVK_PERSIST=1; that is now a documented no-op. Lever kept ONLY for future A/B on the
      // open legacy-title-blink defect (pre-existing, all arms; likely the same
      // periodic-redraw class this heuristic once masked at a different pipeline stage).
      // Value-checked since the PERSIST-retirement leg (2026-07-20): RVK_PERSIST=0 disables even
      // when a recipe script exports it — needed to A/B the heuristic against the register-true
      // VS5RECTALL frame-base restore without editing every script.
      static bool persistLever = [](){ const char* e = std::getenv("RVK_PERSIST");
        return e && std::atoi(e) != 0; }();
      static bool everRendered = false;
      static int peakBatches = 0, decayCtr = 0;
      int nb = (int)((b1 - b0) + (e1 - e0));
      if (persistLever && resolves.empty()) {
        if (nb > peakBatches) peakBatches = nb;
        else if (++decayCtr >= 120) { decayCtr = 0; if (peakBatches > 1) peakBatches--; }
      }
      bool persist = forcePersist >= 0
                     ? (forcePersist == 1 && everRendered)
                     : (persistLever && resolves.empty() && everRendered
                        && peakBatches > 0 && nb * 2 < peakBatches);   // partial redraw => preserve bg
      // ★ 1:1 CLEAR POLICY (2026-07-28, SPEC_shell_compose_1to1.md #2 — decomp is truth): on
      // hardware the shell screen clears iff the single byte DAT_821EC65B != 0, whose ONLY
      // writers are the veil pass FUN_82184CC8 (clear while no veil effect runs; no clear while
      // one does, because the veil's own fullscreen quad covers the previous frame). NOTHING
      // else clears, and the logo scenes clear nothing at all. Our persist heuristic guessed at
      // exactly this byte — and its misses are why dismissed NOW-LOADING pixels ghost through
      // the logo fades (stale EDRAM our compose never wipes). On shell-owned frames (field
      // inactive, ROM not live) read the byte and let the GUEST decide: clear iff set. Debt:
      // hardware's clear colour is *(R+0x218); we keep our existing clear value for now.
      // RVK_NOCLEARBYTE=1 reverts to the heuristic/forcePersist behavior.
      { static bool cbOff = std::getenv("RVK_NOCLEARBYTE") && atoi(std::getenv("RVK_NOCLEARBYTE")) != 0;
        if (!cbOff && g_base && be32(GA_FIELD_ACTIVE) == 0 && g_rt_romactive == 0) {
          uint8_t cb65b = *(g_base + 0x821EC65Bu);
          // ONCE PER FRAME (2026-07-28, first acceptance run went full-black): hardware's clear
          // fires once at the screen render; our compose builds a frame from MULTIPLE submitSeg
          // calls that must accumulate. Only the frame's FIRST seg takes the byte's decision;
          // later segs of the same frame always LOAD.
          static long cbFrameSeen = -2000000000L;
          bool firstSeg = (frame != cbFrameSeen);
          // ★ C3-s1 CLEAR-ORDERING FIX (campaign, 2026-07-28; the [r5pix]/roster datum): a
          // frame's first segment can be a STRADDLED TAIL RESOLVE of the previous guest frame
          // (lazily flushed at next-frame head — 44B, ZERO draws). Hardware stream order is
          // [tail resolve]->[clear]->[draws]; firing our once-per-frame clear before that
          // resolve wipes the EDRAM it is about to read = the one-frame element flash. So the
          // byte's clear decision applies at the frame's first DRAW-BEARING segment; draw-less
          // head segments LOAD and leave the decision pending. RVK_NOCLEARDEFER=1 reverts.
          static bool cdOff = std::getenv("RVK_NOCLEARDEFER") && atoi(std::getenv("RVK_NOCLEARDEFER")) != 0;
          if (!cdOff && firstSeg && nb == 0) {
            firstSeg = false;                 // this seg LOADs persisted content
            static long cdN = 0;              // never-silent
            if ((++cdN % 256) == 1) std::fprintf(stderr, "[cleardefer] x%ld f%ld draw-less head seg — clear deferred to first content seg\n", cdN, frame);
          } else if (firstSeg) cbFrameSeen = frame;
          bool p11 = firstSeg ? ((cb65b == 0) && everRendered) : everRendered;
          if (firstSeg && p11 != persist) { static long cbn = 0;
            if ((cbn++ % 300) == 0)
              std::fprintf(stderr, "[clearbyte] f%ld DAT_821EC65B=%u -> persist %d (was %d)\n",
                           frame, cb65b, (int)p11, (int)persist); }
          persist = p11;
        } }
      // RVK_PERSISTLOG (2026-07-19 PERSIST-retirement study): log every engagement so the A/B
      // (PERSIST heuristic vs the guest's own VS5RECTALL frame-base restore draw) knows WHICH
      // frames/screens the heuristic actually protects in a given run shape. Capped, default off.
      if (persist && std::getenv("RVK_PERSISTLOG")) {
        static long plN = 0;
        if (plN++ < 120) std::fprintf(stderr, "[persistlog] f%ld ENGAGED nb=%d peak=%d\n", frame, nb, peakBatches);
      }
      // RVK_TITLESEG=<startframe> (legacy-title-blink probe 2026-07-21): for 120 windows from the
      // given frame, dump the persist decision + every batch in this segment (vs, indexCount,
      // texIdx, viewport) — resolves which windows carry the full title content and whether the
      // LOAD path fires on the partial-redraw windows.
      static long titleSegF = std::getenv("RVK_TITLESEG") ? std::atol(std::getenv("RVK_TITLESEG")) : -1;
      if (titleSegF >= 0 && frame >= titleSegF && frame < titleSegF + 120) {
        std::fprintf(stderr, "[titleseg] f%ld seg=[%zu,%zu)+[%zu,%zu) nb=%d peak=%d persist=%d res=%zu\n",
          frame, b0, b1, e0, e1, nb, peakBatches, (int)persist, resolves.size());
        for (size_t tb = b0; tb < b1; ++tb) {
          auto& x = batches[tb];
          std::fprintf(stderr, "[titleseg]   b%zu vs=%d idx=%u tex=%u vp={%.0f,%.0f,%.0f,%.0f}\n",
            tb, x.vsIdx, x.indexCount, x.texIdx, x.vp.x, x.vp.y, x.vp.width, x.vp.height);
        }
      }
      VkRenderPassBeginInfo rpb{VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO}; rpb.renderPass = persist ? g.passLoad : g.pass; rpb.framebuffer = g.fb; rpb.renderArea = {{0, 0}, {kW, kH}}; rpb.clearValueCount = persist ? 0u : 1u; rpb.pClearValues = persist ? nullptr : &clear;
      everRendered = true;
      vkCmdBeginRenderPass(g.cmd, &rpb, VK_SUBPASS_CONTENTS_INLINE);
      vkCmdBindDescriptorSets(g.cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, g.rPlLayout, 0, 4, g.rSets, 0, nullptr);
      VkDeviceSize voff = 0; vkCmdBindVertexBuffers(g.cmd, 0, 1, &g.vbuf, &voff);
      vkCmdBindIndexBuffer(g.cmd, g.ibuf, 0, VK_INDEX_TYPE_UINT32);
      VkPipeline lastPipe = VK_NULL_HANDLE; VkViewport lastVp{}; bool vpSet = false;
      // optional second range [e0,e1): RVK_COMPSEG draws composite segment + final overlay
      // segment in ONE renderpass (composite first, overlay on top — batch order preserved).
      size_t ranges[2][2] = {{b0, b1}, {e0, e1}};
      for (int ri = 0; ri < 2; ++ri)
      for (size_t bi2 = ranges[ri][0]; bi2 < ranges[ri][1]; ++bi2) {
        auto& b = batches[bi2];
        if (b.pipeline != lastPipe) { vkCmdBindPipeline(g.cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, b.pipeline); lastPipe = b.pipeline; }
        if (!vpSet || std::memcmp(&b.vp, &lastVp, sizeof lastVp) != 0) { vkCmdSetViewport(g.cmd, 0, 1, &b.vp); lastVp = b.vp; vpSet = true; }
        vkCmdSetBlendConstants(g.cmd, b.bc);   // dynamic state: guest RB_BLEND_RED..ALPHA per batch
        struct { uint64_t vs, ps, shared; float ndc[4]; } pc{b.vsBDA, b.psBDA, b.sharedBDA, {1.f, 1.f, 0.f, 0.f}};
        if (rvkTrue48(b)) {   // register-true: px->ndc epilogue for the full 1280x720 target
          pc.ndc[0] = 2.f / (float)kW; pc.ndc[1] = -2.f / (float)kH;
          pc.ndc[2] = -1.f + 1.f / (float)kW; pc.ndc[3] = 1.f - 1.f / (float)kH;
          VkViewport tvp{0.f, 0.f, (float)kW, (float)kH, 0.f, 1.f};
          vkCmdSetViewport(g.cmd, 0, 1, &tvp); lastVp = tvp;
        }
        vkCmdPushConstants(g.cmd, g.rPlLayout, VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT, 0, sizeof(pc), &pc);
        if (std::getenv("RVK_BATCHDBG")) {
          std::fprintf(stderr, "[rvk][batchdbg] frame%ld seg-batch pipe=%p idxCount=%u firstIdx=%u vp={%.0f,%.0f,%.0f,%.0f} vs=%llx ps=%llx\n",
            frame, (void*)b.pipeline, b.indexCount, b.firstIndex, b.vp.x, b.vp.y, b.vp.width, b.vp.height,
            (unsigned long long)b.vsBDA, (unsigned long long)b.psBDA);
        }
        // [compdbg] LEG-40: per-batch vs-idx + tex-idx + whether tex is a RESOLVE texture (the
        // composite quads sample the resolved layers). g_compResolveIdx is filled below with the
        // resolve-tex bindless indices for THIS frame; a composite quad sampling one of them means
        // "this batch reads the resolved playfield". Env RVK_COMPDBG.
        if (compDbg) {
          bool isResolveSample = g_compResolveIdx.count(b.texIdx) > 0;
          std::fprintf(stderr, "[rvk][compdbg] frame%ld seg[%zu,%zu) bi=%zu vs=%d tex=%u%s vp={%.0f,%.0f,%.0f,%.0f} idx=%u\n",
            frame, b0, b1, bi2, b.vsIdx, b.texIdx, isResolveSample ? " <-SAMPLES-RESOLVE" : "",
            b.vp.x, b.vp.y, b.vp.width, b.vp.height, b.indexCount);
        }
        vkCmdDrawIndexed(g.cmd, b.indexCount, 1, b.firstIndex, 0, 0);
      }
      vkCmdEndRenderPass(g.cmd);   // offscreen -> TRANSFER_SRC
      if (readback) copyDisplayToReadback(g.cmd);   // F6: tonemaps to UNORM8 under RVK_HDR
      VKC(vkEndCommandBuffer(g.cmd), "end(rseg)");
      VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
      VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(rseg)");
      VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(rseg)");
      if (rvkRingOn()) g.ringPending[g.ringIdx] = true; else VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(rseg)");
      return true;
    };
    // Emulate RB_COPY: blit the just-rendered offscreen (TRANSFER_SRC) into a resolve texture.
    auto blitResolve = [&](ResolveTex& rt) {
      segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
      rvkRingNext("rblt"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(rblt)");
      VkCommandBufferBeginInfo cbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; cbi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
      VKC(vkBeginCommandBuffer(g.cmd, &cbi), "begin(rblt)"); if (rvkRingOn()) rvkRingGuard();
      VkImageMemoryBarrier b{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; b.srcQueueFamilyIndex = b.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED; b.image = rt.image; b.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
      b.oldLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL; b.newLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL; b.srcAccessMask = VK_ACCESS_SHADER_READ_BIT; b.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
      vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b);
      // LEG-46: RVK_FBFLIP2 — store the FRONT-BUFFER resolve (kW x kH) bottom-up: the game's
      // transition/echo effects re-sample it with V inverted relative to our upright offscreen
      // (evidence: vertically flipped REPLAY / Character Select echo). readbackResolveTex
      // applies the compensating flip so the DISPLAY path stays upright.
      static bool fbFlip2 = std::getenv("RVK_FBFLIP2") != nullptr;
      bool ffb = fbFlip2 && rt.w == kW && rt.h == kH;
      VkImageBlit bl{}; bl.srcSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1};
      if (ffb) { bl.srcOffsets[0] = {0, (int32_t)kH, 0}; bl.srcOffsets[1] = {(int32_t)kW, 0, 1}; }
      else     { bl.srcOffsets[1] = {(int32_t)kW, (int32_t)kH, 1}; }
      bl.dstSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; bl.dstOffsets[1] = {(int32_t)rt.w, (int32_t)rt.h, 1};
      vkCmdBlitImage(g.cmd, g.image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, rt.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &bl, VK_FILTER_LINEAR);
      b.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL; b.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL; b.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT; b.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
      vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b);
      VKC(vkEndCommandBuffer(g.cmd), "end(rblt)");
      VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
      VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(rblt)");
      VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(rblt)");
      if (rvkRingOn()) g.ringPending[g.ringIdx] = true; else VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(rblt)");
      return true;
    };
    // LEG-40 Fix B: render a layer segment [b0,b1) DIRECTLY into the resolve texture (its own
    // w×h framebuffer), so the content lands 1:1 at the layer's native resolution — no
    // full-frame rescale, no offscreen/EDRAM-tile mismatch. Viewport is the batch's vp scaled
    // proportionally from the 1280×720 offscreen to the target w×h. Empty segment => SKIP (do
    // NOT clear — preserve the tex's persistent content from the frame that did render it).
    // Fix B is OPT-IN (RVK_FIXB) until the missing main-playfield content (0xEEAD000 decode gap,
    // LEG-27 ring/IB class) is fixed and its benefit can be validated — the shipping default keeps
    // the old offscreen+blit path so working screens (boot/title/menu/dialogs) are unchanged.
    static bool fixB = std::getenv("RVK_FIXB") != nullptr;
    // RVK_ATLASSKIP (Round-12 char-select portrait diagnosis 2026-07-15): per-VS-class skip mask
    // applied ONLY to offscreen segment renders (submitSegInto; never the front buffer). Bitmask:
    //   bit0 (1): skip vs=1  -- the 3D pod. Round-12 finding: the pod-poison hypothesis (round-11
    //             hand-off) is REFUTED. The FIXB2 0xF95D000 640x512 char-select atlas segment is
    //             b0 vs=5 (bg feedback) + b1 vs=47 (self-composite) + b2..N vs=48 portrait sprites
    //             binding REAL fmt=3 textures -- there is NO vs=1 draw in the atlas segment, so the
    //             pod renders to the MAIN framebuffer, not into the atlas. This bit is a no-op at
    //             char-select; kept only to document/verify the refutation.
    //   bit1 (2): skip vs=48 draws with indexCount>6 -- the large multi-quad character portrait
    //             sprites. These are the draws that splay into the on-window diagonal solid-colour
    //             bands (the "scramble"): their baked transform is degenerate/menu-tuned so the
    //             big sprites shear diagonally when rendered into the 640x512 atlas. Diagnostic
    //             isolation lever (skipping REMOVES the portraits -- proves attribution, not a fix).
    //   bit2 (4): skip vs=5 -- the full-screen degenerate-viewport ({-1280,-720,2560,1440}) bg
    //             feedback layer that paints the diagonal magenta wash behind the portraits.
    // Default 0 = byte-identical to shipped. Not a fix; the real fix is the vs=48 sprite transform.
    static int atlasSkip = std::getenv("RVK_ATLASSKIP") ? std::atoi(std::getenv("RVK_ATLASSKIP")) : 0;
    // RVK_ATLASPERSIST (select-compose "raw atlas page" fix, 2026-07-15): the guest emits PARTIAL
    // atlas redraws — on the held char-select the 0xF95D000 segment shrinks 116 -> 91 -> 79 -> 53
    // -> 39 batches and then stops — relying on EDRAM persistence for the rest of the screen (same
    // contract RVK_PERSIST honors on the main FB). Rendering each segment into a CLEARED scratch
    // and blitting it over the atlas therefore REPLACED the composed screen with the partial layer
    // (bg-only "raw atlas page" frames = the other half of the select flicker; the settle state
    // showed bg with NO UI). seedFrom: pre-blit the current atlas content into the scratch inside
    // the same command buffer and render the segment with the LOAD pass on top of it. Default ON
    // via the FIXB2 call site (RVK_ATLASPERSIST=0 restores the old cleared-scratch behavior).
    // Per-frame cache of RVK_VTETRUE-patched VS const snapshots (key: vsBDA+extent+vte hash).
    std::unordered_map<uint64_t, uint64_t> vteC255Cache;
    auto submitSegInto = [&](ResolveTex& rt, size_t b0, size_t b1, ResolveTex* seedFrom = nullptr) {
      if (b1 <= b0) return true;   // empty resolve segment: preserve persistent content
      float sx = (float)rt.w / (float)kW, sy = (float)rt.h / (float)kH;
      // RVK_SEGBATCH: record into the deferred buffer; one submit+wait per frame instead of per segment.
      bool SB = segBatchOn();
      VkCommandBuffer SC = SB ? segBatchCmd() : g.cmd;
      if (!SB) {
        rvkRingNext("rti"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(rti)");
        VkCommandBufferBeginInfo cbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; cbi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
        VKC(vkBeginCommandBuffer(g.cmd, &cbi), "begin(rti)"); if (rvkRingOn()) rvkRingGuard();
      }
      bool seed = seedFrom && seedFrom->image && seedFrom->everRendered;
      if (seed) {
        auto sb = [&](VkImage im, VkImageLayout ol, VkImageLayout nl, VkAccessFlags sa, VkAccessFlags da) {
          VkImageMemoryBarrier b{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; b.srcQueueFamilyIndex = b.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
          b.image = im; b.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1}; b.oldLayout = ol; b.newLayout = nl; b.srcAccessMask = sa; b.dstAccessMask = da;
          vkCmdPipelineBarrier(SC, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, 0, 0, nullptr, 0, nullptr, 1, &b);
        };
        sb(seedFrom->image, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_ACCESS_SHADER_READ_BIT, VK_ACCESS_TRANSFER_READ_BIT);
        sb(rt.image, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 0, VK_ACCESS_TRANSFER_WRITE_BIT);  // prior scratch content is discarded (blit overwrites)
        VkImageBlit bl{}; bl.srcSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; bl.dstSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1};
        bl.srcOffsets[1] = {(int32_t)seedFrom->w, (int32_t)seedFrom->h, 1}; bl.dstOffsets[1] = {(int32_t)rt.w, (int32_t)rt.h, 1};
        vkCmdBlitImage(SC, seedFrom->image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, rt.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &bl, VK_FILTER_NEAREST);
        sb(seedFrom->image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_ACCESS_TRANSFER_READ_BIT, VK_ACCESS_SHADER_READ_BIT);
        // leave rt in TRANSFER_SRC = g.passLoad's declared initialLayout
        sb(rt.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_ACCESS_TRANSFER_WRITE_BIT, VK_ACCESS_TRANSFER_READ_BIT);
      }
      VkRenderPassBeginInfo rpb{VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO}; rpb.renderPass = seed ? g.passLoad : g.pass; rpb.framebuffer = rt.fb; rpb.renderArea = {{0, 0}, {rt.w, rt.h}}; rpb.clearValueCount = seed ? 0u : 1u; rpb.pClearValues = seed ? nullptr : &clear;
      vkCmdBeginRenderPass(SC, &rpb, VK_SUBPASS_CONTENTS_INLINE);
      vkCmdBindDescriptorSets(SC, VK_PIPELINE_BIND_POINT_GRAPHICS, g.rPlLayout, 0, 4, g.rSets, 0, nullptr);
      VkDeviceSize voff = 0; vkCmdBindVertexBuffers(SC, 0, 1, &g.vbuf, &voff);
      vkCmdBindIndexBuffer(SC, g.ibuf, 0, VK_INDEX_TYPE_UINT32);
      VkPipeline lastPipe = VK_NULL_HANDLE;
      for (size_t bi2 = b0; bi2 < b1; ++bi2) {
        auto& b = batches[bi2];
        // RVK_SEGPOS=<n> (2026-07-17 seg-content compression hunt): dump each seg-render batch's
        // RAW guest viewport, our scaled viewport (sx/sy heuristic), and the first 4 indexed
        // vertices' pos/uv — during the ROM attract, sampled every 32nd frame, n lines max. This
        // is the datum for WHY scene content lands small/offset in the resolve (card fills swap
        // rows [100,512) where HW fills the displayed 480; legal text ~0.91x the oracle span).
        {
          static long segPosMax = std::getenv("RVK_SEGPOS") ? std::strtol(std::getenv("RVK_SEGPOS"), nullptr, 10) : 0;
          static long segPosN = 0;
          // Per-frame slot cap: a legal fly-in frame alone has 380+ glyph batches — without this
          // one frame burns the whole budget and the card scene never prints.
          if (segPosMax > 0 && segPosN < segPosMax && g_rt_romactive != 0 && (frame % 32) == 0 && (bi2 - b0) < 8) {
            char pv[320]; int po = 0;
            for (uint32_t k = 0; k < 4 && k < b.indexCount; ++k) {
              const float* f = (const float*)(Vraw + (size_t)Iarr[b.firstIndex + k] * 6);
              float vx = f[0], vy = f[1], vu, vv;
              if (b.vsIdx == 48) { vu = f[2]; vv = f[3]; } else { vu = f[4]; vv = f[5]; }
              po += std::snprintf(pv + po, sizeof pv - po, " (%.1f,%.1f uv %.2f,%.2f)", vx, vy, vu, vv);
            }
            std::fprintf(stderr, "[segpos] f%ld ->%ux%u slot%zu vs=%d tex=%u idx=%u rawvp={%.0f,%.0f,%.0f,%.0f} scaledvp={%.0f,%.0f,%.0f,%.0f}%s\n",
                         frame, rt.w, rt.h, bi2 - b0, b.vsIdx, b.texIdx, b.indexCount,
                         b.vp.x, b.vp.y, b.vp.width, b.vp.height,
                         b.vp.x * sx, b.vp.y * sy, b.vp.width * sx, b.vp.height * sy, pv);
            ++segPosN;
          }
        }
        // RVK_BOXDBG=<n> (2026-07-18 sprite black-box hunt, v2): dump LARGE low-poly seg batches
        // (the shadow/light overlay quads that render as black boxes) with full identity: blend
        // reg, ps idx, texture base/fmt, ALL 4 corner positions AND UVs (texels). v2 DEDUPS by
        // (texBase, quad rect, uv0) so the budget captures DISTINCT boxes instead of one quad
        // repeated every frame. Filter: indexCount<=12 and quad extent >= 40 units.
        {
          static long boxDbgMax = std::getenv("RVK_BOXDBG") ? std::strtol(std::getenv("RVK_BOXDBG"), nullptr, 10) : 0;
          static long boxDbgN = 0;
          if (boxDbgMax > 0 && boxDbgN < boxDbgMax && g_rt_romactive != 0 && b.indexCount <= 12 && b.indexCount >= 3
              && b.vsIdx == 48 && frame >= 1600) {   // vs=48 sprites, DEMO era only (legal fly-in ghosts at f<700 flood the budget)
            float mnx = 1e9f, mxx = -1e9f, mny = 1e9f, mxy = -1e9f;
            for (uint32_t k = 0; k < 6 && k < b.indexCount; ++k) {
              const float* f = (const float*)(Vraw + (size_t)Iarr[b.firstIndex + k] * 6);
              mnx = std::min(mnx, f[0]); mxx = std::max(mxx, f[0]);
              mny = std::min(mny, f[1]); mxy = std::max(mxy, f[1]);
            }
            if (mxx - mnx >= 40.f && mxy - mny >= 40.f && mxx - mnx < 300.f) {   // big sprites, not full-canvas layers
              const float* f0 = (const float*)(Vraw + (size_t)Iarr[b.firstIndex] * 6);
              float u0, v0;
              if (b.vsIdx == 48) { u0 = f0[2]; v0 = f0[3]; } else { u0 = f0[4]; v0 = f0[5]; }
              // v2 dedup key: texBase ^ quantized rect ^ quantized uv0
              uint64_t dk = ((uint64_t)b.texBase << 32)
                          ^ ((uint64_t)(uint16_t)(int)mnx << 48) ^ ((uint64_t)(uint16_t)(int)mny << 32)
                          ^ ((uint64_t)(uint16_t)(int)mxx << 16) ^ (uint64_t)(uint16_t)(int)mxy
                          ^ ((uint64_t)(uint16_t)(int)u0 << 24) ^ ((uint64_t)(uint16_t)(int)v0 << 8);
              static uint64_t boxSeen[256]; static int nBoxSeen = 0; bool dup = false;
              for (int q = 0; q < nBoxSeen; ++q) if (boxSeen[q] == dk) { dup = true; break; }
              if (!dup && nBoxSeen < 256) {
                boxSeen[nBoxSeen++] = dk;
                char corners[512]; int co = 0;
                uint32_t nvtx = b.indexCount >= 6 ? 4u : b.indexCount;  // 6-idx quad = 4 unique verts (0,1,2 then 1,3,2 or similar); print first 4 distinct indices
                // print the first 4 DISTINCT vertex indices' pos+uv
                uint32_t seenIdx[4]; uint32_t nSeen = 0;
                for (uint32_t k = 0; k < b.indexCount && nSeen < 4; ++k) {
                  uint32_t vi = Iarr[b.firstIndex + k]; bool have = false;
                  for (uint32_t q = 0; q < nSeen; ++q) if (seenIdx[q] == vi) { have = true; break; }
                  if (have) continue;
                  seenIdx[nSeen++] = vi;
                  const float* f = (const float*)(Vraw + (size_t)vi * 6);
                  float vu, vv;
                  if (b.vsIdx == 48) { vu = f[2]; vv = f[3]; } else { vu = f[4]; vv = f[5]; }
                  co += std::snprintf(corners + co, sizeof corners - co, " c%u={%.1f,%.1f uv %.2f,%.2f}", nSeen - 1, f[0], f[1], vu, vv);
                }
                (void)nvtx;
                std::fprintf(stderr, "[boxdbg] f%ld vs=%d ps=%d tex=%u base=0x%X fmt=%u blend=0x%08X idx=%u quad={%.0f,%.0f..%.0f,%.0f}%s c14={%.3f,%.3f,%.3f,%.3f} c15={%.3f,%.3f,%.3f,%.3f}\n",
                  frame, b.vsIdx, b.psIdx, b.texIdx, b.texBase, b.texFmt, b.blendReg,
                  b.indexCount, mnx, mny, mxx, mxy, corners,
                  b.psC14[0], b.psC14[1], b.psC14[2], b.psC14[3], b.psC15[0], b.psC15[1], b.psC15[2], b.psC15[3]);
                ++boxDbgN;
              }
            }
          }
        }
        // RVK_BOXDBG2=<n> (2026-07-18 round 2): full-frame batch census — every 64th demo frame,
        // one line PER BATCH: slot, vs/ps, texIdx/base/fmt, blend, idxCount, pos extent, uv extent.
        // The box draws escaped the size-filtered boxdbg; this finds them by elimination.
        {
          static long boxDbg2Max = std::getenv("RVK_BOXDBG2") ? std::strtol(std::getenv("RVK_BOXDBG2"), nullptr, 10) : 0;
          static long boxDbg2From = std::getenv("RVK_BOXDBG2_FROM") ? std::strtol(std::getenv("RVK_BOXDBG2_FROM"), nullptr, 10) : 1600;
          static long boxDbg2N = 0;
          if (boxDbg2Max > 0 && boxDbg2N < boxDbg2Max && g_rt_romactive != 0 && frame >= boxDbg2From && (frame % 16) == 0) {
            float mnx = 1e9f, mxx = -1e9f, mny = 1e9f, mxy = -1e9f, mnu = 1e9f, mxu = -1e9f, mnv = 1e9f, mxv = -1e9f;
            for (uint32_t k = 0; k < b.indexCount; ++k) {
              const float* f = (const float*)(Vraw + (size_t)Iarr[b.firstIndex + k] * 6);
              mnx = std::min(mnx, f[0]); mxx = std::max(mxx, f[0]);
              mny = std::min(mny, f[1]); mxy = std::max(mxy, f[1]);
              float vu, vv;
              if (b.vsIdx == 48) { vu = f[2]; vv = f[3]; } else { vu = f[4]; vv = f[5]; }
              mnu = std::min(mnu, vu); mxu = std::max(mxu, vu);
              mnv = std::min(mnv, vv); mxv = std::max(mxv, vv);
            }
            std::fprintf(stderr, "[boxdbg2] f%ld slot%zu vs=%d ps=%d tex=%u base=0x%X fmt=%u blend=0x%08X idx=%u pos={%.0f,%.0f..%.0f,%.0f} uv={%.1f,%.1f..%.1f,%.1f} c14={%.2f,%.2f,%.2f,%.2f} c15={%.2f,%.2f,%.2f,%.2f}\n",
              frame, bi2 - b0, b.vsIdx, b.psIdx, b.texIdx, b.texBase, b.texFmt, b.blendReg, b.indexCount,
              mnx, mny, mxx, mxy, mnu, mnv, mxu, mxv,
              b.psC14[0], b.psC14[1], b.psC14[2], b.psC14[3], b.psC15[0], b.psC15[1], b.psC15[2], b.psC15[3]);
            ++boxDbg2N;
          }
        }
        // RVK_BOXSKIP=1 (2026-07-18 black-box hunt round 2, diagnostic): skip exactly the
        // boxdbg-class draws (vs=48, 3..12 idx, quad extent 40..300) during the ROM demo — the
        // A/B that proves whether these quads ARE the on-screen black boxes.
        {
          static const bool boxSkip = std::getenv("RVK_BOXSKIP") && atoi(std::getenv("RVK_BOXSKIP")) != 0;
          if (boxSkip && g_rt_romactive != 0 && b.vsIdx == 48 && b.indexCount <= 12 && b.indexCount >= 3 && frame >= 1600) {
            float mnx = 1e9f, mxx = -1e9f, mny = 1e9f, mxy = -1e9f;
            for (uint32_t k = 0; k < 6 && k < b.indexCount; ++k) {
              const float* f = (const float*)(Vraw + (size_t)Iarr[b.firstIndex + k] * 6);
              mnx = std::min(mnx, f[0]); mxx = std::max(mxx, f[0]);
              mny = std::min(mny, f[1]); mxy = std::max(mxy, f[1]);
            }
            if (mxx - mnx >= 40.f && mxy - mny >= 40.f && mxx - mnx < 300.f) continue;
          }
        }
        // RVK_ATLASSKIP diagnostic mask (see above): skip selected VS classes in offscreen renders.
        if (atlasSkip) {
          bool sk = ((atlasSkip & 1) && b.vsIdx == 1)
                 || ((atlasSkip & 2) && b.vsIdx == 48 && b.indexCount > 6)
                 || ((atlasSkip & 4) && b.vsIdx == 5);
          if (sk) {
            static long sd = 0;
            if (sd++ < 60) std::fprintf(stderr, "[rvk][atlasskip] seg-into %ux%u skip b%zu vs=%d tex=%u idx=%u vp={%.0f,%.0f,%.0f,%.0f}\n",
              rt.w, rt.h, bi2, b.vsIdx, b.texIdx, b.indexCount, b.vp.x, b.vp.y, b.vp.width, b.vp.height);
            continue;
          }
        }
        // RVK_SEGSKIPB=<bitmask> (2026-07-16, attract legal-panel isolation): skip batch SLOT
        // (bi2-b0) of every segment render when its bit is set — per-batch granularity where
        // ATLASSKIP is only per-VS-class. E.g. =4 skips slot 2 (the suspected white panel-bg
        // tilemap), =8 skips slot 3 (the text quads). Diagnostic, default off.
        {
          static long segSkipB = std::getenv("RVK_SEGSKIPB") ? std::strtol(std::getenv("RVK_SEGSKIPB"), nullptr, 0) : 0;
          if (segSkipB && ((bi2 - b0) < 63) && (segSkipB >> (bi2 - b0)) & 1) {
            static long ssb = 0;
            if (ssb++ < 40) std::fprintf(stderr, "[rvk][segskipb] %ux%u skip slot%zu vs=%d tex=%u idx=%u\n",
              rt.w, rt.h, bi2 - b0, b.vsIdx, b.texIdx, b.indexCount);
            continue;
          }
        }
        // RVK_SEGWHO (2026-07-16): identify EXACTLY the batches that render into a resolve target —
        // for 0xF95D000 (the washed field/attract panel) these are the FIXB2 SEG [0,3) batches. Dump
        // each batch's texture identity so we can see whether the white grid = these quads sampling
        // the 1x1 white (idx 0) / an empty resolve. This is the batch-level datum the gated manifest
        // could not reach. One-shot per (rt.dst,batch-slot) to keep the log short.
        if (std::getenv("RVK_SEGWHO")) {
          static std::set<uint64_t> shown;
          uint64_t k = ((uint64_t)rt.idx << 40) | ((uint64_t)(bi2 - b0) << 8) | (b.texIdx & 0xFF);
          if (shown.size() < 80 && shown.insert(k).second) {
            uint32_t tbase = 0; int isRes = 0; uint32_t tfmt = 0, tw = 0, th = 0;
            for (auto& kv : g_resolveTex) if (kv.second.idx == b.texIdx) { tbase = kv.first; isRes = 1; tw = kv.second.w; th = kv.second.h; break; }
            if (!isRes) for (auto& kv : g.rTexIndex) if (kv.second == b.texIdx) { tbase = (uint32_t)(kv.first >> 8); tfmt = (uint32_t)(kv.first & 0xFF); break; }
            uint32_t rtDst = 0; for (auto& kv : g_resolveTex) if (kv.second.idx == rt.idx) { rtDst = kv.first; break; }
            std::fprintf(stderr, "[segwho] ->rtDst=0x%X(%ux%u) b[%zu] vs=%d texIdx=%u %s tex=0x%X %ux%u fmt=%u idxCnt=%u vp={%.0f,%.0f,%.0f,%.0f}\n",
              rtDst, rt.w, rt.h, bi2 - b0, b.vsIdx, b.texIdx,
              b.texIdx == 0 ? "WHITE(idx0!)" : isRes ? "RESOLVE" : "tex", tbase, tw, th, tfmt, b.indexCount,
              b.vp.x, b.vp.y, b.vp.width, b.vp.height);
          }
        }
        if (b.pipeline != lastPipe) { vkCmdBindPipeline(SC, VK_PIPELINE_BIND_POINT_GRAPHICS, b.pipeline); lastPipe = b.pipeline; }
        // RVK_VTETRUE=1 (2026-07-17 VTE rewrite): SDK-true transform for VTE-ENABLED vs=48 draws.
        // rexglue-sdk GetHostViewportInfo (src/graphics/util/draw.cpp): host viewport =
        // [offset-|scale|, offset+|scale|] in GUEST PIXELS clamped to the RT extent, and the
        // shader's ndc system constant (c255 = {sx,sy,ox,oy}, the slot our static RVK_C255 value
        // fakes) rescales the guest clip space onto the clamped rect:
        //   ndc_scale  = scale * 2 / ext          (sign carried here, not in the rect)
        //   ndc_offset = (offset - (axis0 + ext/2)) * 2 / ext
        // Menus/VTE-disabled draws (xs==0) keep the legacy path (the static c255 + scaled vp is
        // their calibrated pipeline). Default off until scene-verified vs the oracle.
        static bool vteTrue = std::getenv("RVK_VTETRUE") != nullptr;
        // RVK_VTEYFLIP: A/B for the Vulkan-vs-D3D y convention (-fvk-invert-y interplay):
        // 1 = negate the computed y ndc_scale/ndc_offset pair.
        static bool vteYFlip = std::getenv("RVK_VTEYFLIP") != nullptr;
        uint64_t drawVsBDA2 = b.vsBDA;
        bool vteApplied = false; VkViewport vpTrue{};
        if (vteTrue && b.vsIdx == 48 && b.vsHost &&
            std::fabs(b.vte[0]) >= 1.f && std::fabs(b.vte[2]) >= 1.f) {
          const float off[2] = {b.vte[1], b.vte[3]}, scl[2] = {b.vte[0], b.vte[2]};
          const float mx[2] = {(float)rt.w, (float)rt.h};
          float c255n[4], xy0[2], ext[2]; bool ok = true;
          for (int a = 0; a < 2; ++a) {
            float sa = std::fabs(scl[a]);
            float a0 = std::floor(std::min(std::max(off[a] - sa, 0.f), mx[a]));
            float a1 = std::floor(std::min(std::max(off[a] + sa, 0.f), mx[a]));
            float ex = a1 - a0;
            if (ex < 1.f) { ok = false; break; }
            xy0[a] = a0; ext[a] = ex;
            c255n[a] = scl[a] * 2.f / ex;
            c255n[2 + a] = (off[a] - (a0 + ex * 0.5f)) * 2.f / ex;
          }
          if (ok) {
            // v2 (2026-07-17 late): c255 is the GAME's canvas->ndc screen transform (the runtime-
            // identity experiment collapsed content — c255 is NOT the SDK system constant slot).
            // Correct composition: guest c255 ∘ the viewport-clamp fold. The fold uses |scale|
            // (the D3D y-sign is already consumed by the SPIR-V's -fvk-invert-y — same convention
            // spriteViewport() documents); for a symmetric full-target clamp the fold is identity
            // and this reduces to "guest c255 + true 1:1 viewport".
            float fs[2], fo[2];
            for (int a = 0; a < 2; ++a) {
              fs[a] = std::fabs(scl[a]) * 2.f / ext[a];
              fo[a] = c255n[2 + a];
            }
            if (vteYFlip) { fs[1] = -fs[1]; fo[1] = -fo[1]; }
            const float* gc = b.vsHost + 1020;
            float c255c[4] = { gc[0] * fs[0], gc[1] * fs[1], gc[2] * fs[0] + fo[0], gc[3] * fs[1] + fo[1] };
            // per-frame patched-snapshot cache: key hashes (vsBDA, extent, vte)
            uint64_t key = b.vsBDA * 0x9E3779B97F4A7C15ull ^ ((uint64_t)rt.w << 32) ^ rt.h;
            for (int a = 0; a < 4; ++a) { uint32_t u; std::memcpy(&u, &b.vte[a], 4); key = key * 0x100000001B3ull ^ u; }
            auto it = vteC255Cache.find(key);
            if (it == vteC255Cache.end()) {
              auto p2 = arenaAlloc(4096); std::memcpy(p2.host, b.vsHost, 4096);
              std::memcpy((float*)p2.host + 1020, c255c, 16);
              it = vteC255Cache.emplace(key, p2.addr).first;
              static long vl = 0;
              if (vl++ < 24) std::fprintf(stderr, "[vtetrue] rt=%ux%u vte={%.0f,%.0f,%.0f,%.0f} -> vp={%.0f,%.0f,%.0f,%.0f} guestC255={%.5f,%.5f,%.3f,%.3f} -> {%.5f,%.5f,%.3f,%.3f}\n",
                rt.w, rt.h, b.vte[0], b.vte[1], b.vte[2], b.vte[3], xy0[0], xy0[1], ext[0], ext[1], gc[0], gc[1], gc[2], gc[3], c255c[0], c255c[1], c255c[2], c255c[3]);
            }
            drawVsBDA2 = it->second;
            vpTrue = {xy0[0], xy0[1], ext[0], ext[1], 0.f, 1.f};
            vteApplied = true;
          }
        }
        // RVK_SEGVPPX=1 (2026-07-18 oracle-decoded): for VTE-DISABLED vs=48 draws (guest VS
        // outputs SCREEN PIXELS — proven by the SDK rdc system constants at the legal draws:
        // xe_ndc_scale={2/8192,-2/8192}, offset=~{-1,+1} under the 8192^2 viewport = px->ndc 1:1,
        // vte scale/offset 1/0), our c255 basis {2/320,2/512,-1,0} needs viewport
        // {0,-H,W,2H} to net the hardware's exact px = 2*canvas mapping on BOTH axes
        // (solve: d(px)/d(canvas) = (2/512)*vpH/2 = 2 -> vpH=1024; px(0)=0 -> vpy=-512.
        // X already exact: (2/320)*640/2 = 2). Measured defect this fixes: our legal text lands
        // at y=1.6*canvas+151.6 in the resolve vs the oracle's 2.0*canvas+0 (rows 174..489 vs
        // 28..421; X cols 48..541 identical).
        static bool segVpPx = std::getenv("RVK_SEGVPPX") != nullptr;
        // Gate on the VTE_CNTL ENABLE BITS, not the scale values: the scale regs hold stale
        // values while the draw's PA_CL_VTE_CNTL disables them (bit0 = VPORT_X_SCALE_ENA) —
        // the SDK reads the cntl bits; the legal/text draws run with them OFF (px output).
        if (!vteApplied && segVpPx && b.vsIdx == 48 && (b.vteCntl & 0x1u) == 0u) {
          vpTrue = {0.f, -(float)rt.h, (float)rt.w, (float)rt.h * 2.f, 0.f, 1.f};
          vteApplied = true;
        }
        // RVK_SEGVP1TO1=1 (2026-07-17 seg-content compression experiment): use the guest viewport
        // 1:1 in guest pixels, letting the render target's natural extent clip it — the SDK/HW
        // semantics per rexglue-sdk GetHostViewportInfo (draw.cpp: host vp = offset±scale in
        // GUEST pixels clamped to the RT, NO rescale-to-fit). The default path scales the vp rect
        // to fit the RT (sx=rt.w/kW, sy=rt.h/kH) — which compresses seg content ~0.71x in y vs
        // hardware (the card strips authored at y 0..496 land at rows [100,512) instead of
        // filling the displayed area). Experiment lever, default off. (A/B RESULT: 1:1 vp ALONE
        // blows vs=48 content up — the c255 constant must be recomputed WITH it = RVK_VTETRUE.)
        static bool segVp1to1 = std::getenv("RVK_SEGVP1TO1") != nullptr;
        // Panel-space guest viewports (select TOP-STRIP fix, 2026-07-20): the (sx,sy) branch
        // assumes guest vps are 1280x720-SCREEN-relative, but the vs=47 panel self-feedback
        // restore arrives with the RT's OWN space ({0,0,640,512} on the 640x512 panel) — scaling
        // it lands the restore squeezed top-left ({0,0,320,364}) and the region the per-frame
        // overdraw misses stays frozen (the select top strip). HW semantics (GetHostViewportInfo):
        // the vp is guest pixels 1:1 clamped to the RT — a vp whose extent matches the RT is
        // already RT-space; pass it through. RVK_NOVPNATIVE=1 reverts.
        static bool noVpNative = std::getenv("RVK_NOVPNATIVE") != nullptr;
        bool vpNative = !noVpNative && !vteApplied
          && std::fabs(b.vp.width - (float)rt.w) <= 1.f && std::fabs(b.vp.height - (float)rt.h) <= 1.f;
        VkViewport vp = vteApplied ? vpTrue
          : (segVp1to1 || vpNative)
          ? VkViewport{b.vp.x, b.vp.y, b.vp.width, b.vp.height, 0.f, 1.f}
          : VkViewport{b.vp.x * sx, b.vp.y * sy, b.vp.width * sx, b.vp.height * sy, 0.f, 1.f};
        vkCmdSetViewport(SC, 0, 1, &vp);
        vkCmdSetBlendConstants(SC, b.bc);   // dynamic state: guest RB_BLEND_RED..ALPHA per batch
        struct { uint64_t vs, ps, shared; float ndc[4]; } pc{drawVsBDA2, b.psBDA, b.sharedBDA, {1.f, 1.f, 0.f, 0.f}};
        bool segT48 = rvkTrue48(b);
        if (segT48) {   // register-true: guest c255 + px->ndc epilogue + full-RT viewport
          pc.ndc[0] = 2.f / (float)rt.w; pc.ndc[1] = -2.f / (float)rt.h;
          pc.ndc[2] = -1.f + 1.f / (float)rt.w; pc.ndc[3] = 1.f - 1.f / (float)rt.h;
          VkViewport tvp{0.f, 0.f, (float)rt.w, (float)rt.h, 0.f, 1.f};
          vkCmdSetViewport(SC, 0, 1, &tvp);
        }
        // RVK_SEGVPLOG (select TOP-STRIP write-region probe 2026-07-20): per-batch APPLIED
        // viewport branch + decoded corner verts for the 640x512 panel seg. The strip band
        // (content x>=~296) stays stale even though bg-column batches nominally cover it —
        // this logs which vp branch each batch takes so the clipped writer can be identified.
        // Env value = START FRAME (log only frames >= it; "1" = from boot) — the 600-line cap
        // otherwise burns on nav-phase segs long before the held select (~f2600+).
        static long segVpLog = std::getenv("RVK_SEGVPLOG") ? std::atol(std::getenv("RVK_SEGVPLOG")) : -1;
        if (segVpLog >= 0 && frame >= segVpLog && rt.w == 640 && rt.h == 512) {
          static long svl = 0;
          if (svl++ < 600) {
            const float* q0 = (const float*)(Vraw + (size_t)Iarr[b.firstIndex] * 6);
            const float* q1 = (const float*)(Vraw + (size_t)Iarr[b.firstIndex + (b.indexCount > 1 ? 1 : 0)] * 6);
            const float* q2 = (const float*)(Vraw + (size_t)Iarr[b.firstIndex + (b.indexCount > 2 ? 2 : 0)] * 6);
            std::fprintf(stderr, "[segvplog] f%ld bi=%zu vs=%d idx=%u br=%s t48=%d vp={%.1f,%.1f,%.1f,%.1f} v0=(%.1f,%.1f) v1=(%.1f,%.1f) v2=(%.1f,%.1f) col=%08X uv0=(%.1f,%.1f)\n",
              frame, bi2, b.vsIdx, b.indexCount,
              vteApplied ? "vte" : vpNative ? "native" : (segVp1to1 ? "1to1" : "scaled"), (int)segT48,
              (segT48 ? 0.f : vp.x), (segT48 ? 0.f : vp.y),
              (segT48 ? (float)rt.w : vp.width), (segT48 ? (float)rt.h : vp.height),
              q0[0], q0[1], q1[0], q1[1], q2[0], q2[1],
              ((const uint32_t*)q0)[3], q0[4], q0[5]);
          }
        }
        vkCmdPushConstants(SC, g.rPlLayout, VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT, 0, sizeof(pc), &pc);
        vkCmdDrawIndexed(SC, b.indexCount, 1, b.firstIndex, 0, 0);
      }
      vkCmdEndRenderPass(SC);   // rt -> TRANSFER_SRC (renderpass finalLayout)
      // TRANSFER_SRC -> SHADER_READ so the composite can sample it.
      VkImageMemoryBarrier bar{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; bar.srcQueueFamilyIndex = bar.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
      bar.image = rt.image; bar.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
      bar.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL; bar.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
      bar.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT; bar.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
      vkCmdPipelineBarrier(SC, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &bar);
      if (!SB) {
        VKC(vkEndCommandBuffer(g.cmd), "end(rti)");
        VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
        VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(rti)");
        VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(rti)");
        if (rvkRingOn()) g.ringPending[g.ringIdx] = true; else VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(rti)");
      }
      rvkResMarkRendered(rt, frame);
      return true;
    };
    // LEG-46 Fix B2: per-frame FEEDBACK resolves (RESFRESH-classified, e.g. 0xEEDD000 640x512)
    // must render at native size — the old offscreen+full-frame blit compounds a rescale error
    // every feedback iteration (vertical streaking + drifting echo). Fix B as-committed can't
    // be used directly: it CLEARS the target then renders the segment into it, but the feedback
    // quad in that very segment SAMPLES the target (cleared history + sample-while-attached
    // hazard). Adaptation: render the segment into a same-size SCRATCH image (the EDRAM
    // surface), then blit scratch -> resolve tex (the RB_COPY) — the sampled tex holds the
    // previous frame during the render, exactly like real HW. Empty segment => skip (preserve
    // history; the old path blitted a CLEARED offscreen over it). Applies only to SUB-SCREEN
    // targets (w < 1280): the 1280x720 front-buffer resolve keeps the exact old path.
    // Levers: RVK_FIXB2=1 enables; RVK_FBFLIP=1 additionally flips Y in the scratch->tex blit
    // (feedback orientation A/B).
    static bool fixB2 = std::getenv("RVK_FIXB2") != nullptr;
    static bool fbFlip = std::getenv("RVK_FBFLIP") != nullptr;
    auto blitTexToTex = [&](ResolveTex& src, ResolveTex& dst, bool flip) {
      bool SB = segBatchOn();
      VkCommandBuffer SC = SB ? segBatchCmd() : g.cmd;
      if (!SB) {
        rvkRingNext("rtt"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(rtt)");
        VkCommandBufferBeginInfo cbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; cbi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
        VKC(vkBeginCommandBuffer(g.cmd, &cbi), "begin(rtt)"); if (rvkRingOn()) rvkRingGuard();
      }
      auto bar = [&](VkImage im, VkImageLayout ol, VkImageLayout nl, VkAccessFlags sa, VkAccessFlags da) {
        VkImageMemoryBarrier b{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; b.srcQueueFamilyIndex = b.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        b.image = im; b.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1}; b.oldLayout = ol; b.newLayout = nl; b.srcAccessMask = sa; b.dstAccessMask = da;
        vkCmdPipelineBarrier(SC, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, 0, 0, nullptr, 0, nullptr, 1, &b);
      };
      bar(src.image, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_ACCESS_SHADER_READ_BIT, VK_ACCESS_TRANSFER_READ_BIT);
      bar(dst.image, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_ACCESS_SHADER_READ_BIT, VK_ACCESS_TRANSFER_WRITE_BIT);
      VkImageBlit bl{}; bl.srcSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; bl.dstSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1};
      if (flip) { bl.srcOffsets[0] = {0, (int32_t)src.h, 0}; bl.srcOffsets[1] = {(int32_t)src.w, 0, 1}; }
      else      { bl.srcOffsets[1] = {(int32_t)src.w, (int32_t)src.h, 1}; }
      bl.dstOffsets[1] = {(int32_t)dst.w, (int32_t)dst.h, 1};
      vkCmdBlitImage(SC, src.image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, dst.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &bl, VK_FILTER_NEAREST);
      bar(src.image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_ACCESS_TRANSFER_READ_BIT, VK_ACCESS_SHADER_READ_BIT);
      bar(dst.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_ACCESS_TRANSFER_WRITE_BIT, VK_ACCESS_SHADER_READ_BIT);
      if (!SB) {
        VKC(vkEndCommandBuffer(g.cmd), "end(rtt)");
        VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
        VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(rtt)");
        VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(rtt)");
        if (rvkRingOn()) g.ringPending[g.ringIdx] = true; else VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(rtt)");
      }
      return true;
    };
    // RVK_COMPSEG=1 (LEG-43): the game draws the panel-composite quad (vs=47, samples the
    // playfield resolve, full-screen vp) as the FIRST draws of the frame — compositing the
    // PREVIOUS frame's resolves — so the composite lives in an EARLY layer segment, not the
    // final one. The old readback policy below (composite == final segment, else blit lastRt)
    // therefore displayed the last LAYER resolve stretched full-screen (no panel). Find the
    // segment containing a resolve-sampling full-screen batch; the display readback then
    // renders THAT segment + the final overlay segment together.
    static bool compSeg = std::getenv("RVK_COMPSEG") != nullptr;
    std::set<uint32_t> compResolveIdxAll;
    if (compSeg) for (auto& kv : g_resolveTex) compResolveIdxAll.insert(kv.second.idx);
    long compB0 = -1, compB1 = -1;
    auto segHasComposite = [&](size_t s0, size_t s1) -> bool {
      if (!compSeg) return false;
      for (size_t bi2 = s0; bi2 < s1; ++bi2) {
        auto& b = batches[bi2];
        float vpw = b.vp.width < 0 ? -b.vp.width : b.vp.width;
        // LEG-46 (RVK_COMPVS47=1, experimental): require the COMPOSITE VS family (vs=47/48).
        // Since idx49 landed, the vs=5/ps=49 FEEDBACK quad also samples a resolve tex at
        // full-screen vp and shadows the real composite — the display shows the raw playfield
        // layer full-screen instead of the framed layout (playfield inside the gold bezel,
        // SDK ground truth per futari-gameplay-frame). With the filter ON the true frame
        // composite IS found and displayed, but it currently renders 180-degree ROTATED with
        // unkeyed chroma-magenta filler (the vs=47 c255/VTE transform stack is tuned for
        // menus, not the frame composite) — a composite-transform rework, next session's
        // headline. Default OFF: ship the coherent full-screen-playfield display until then.
        static bool compVs47 = std::getenv("RVK_COMPVS47") != nullptr;
        if (compVs47 && !(b.vsIdx == 47 || b.vsIdx == 48)) continue;
        // Width gate: the vs=5/ps=49 FEEDBACK quad and the true composite both sample a resolve at
        // full-screen vp; the >=kW gate discriminates them when compVs47 is OFF. But the REAL vs=47
        // panel composite (LEG-47, confirmed 2026-07-14 from compdbg) renders the resolved playfield
        // at the 640x512 PLAYFIELD-RESOLVE viewport {0,0,640,512}, NOT full-screen — so >=kW rejects
        // it. When compVs47 is ON (vs family already required), accept the playfield-resolve topology:
        // any resolve-sampling vs=47/48 draw at >= the playfield width (512) IS the composite.
        float compMinW = compVs47 ? 512.f : (float)kW;
        if (compResolveIdxAll.count(b.texIdx) && vpw >= compMinW) return true;
      }
      return false;
    };
    size_t b0 = 0;
    int segN = 0;
    // RVK_FIELDMANIFEST [segman] (2026-07-14): dump the batch list of every resolve segment for
    // frames at/after the RVK_DEBUG_OPS_FIELD trigger. Arm OUTSIDE the resolve loop (an empty
    // `resolves` — the norm at steady gameplay — must still arm and be observable) and report
    // empty frames explicitly: "no resolves" on a gameplay frame IS the finding.
    static bool segMan = std::getenv("RVK_FIELDMANIFEST") != nullptr;
    static int segArmed = 0;
    if (segMan && fieldTrig) segArmed = 40;
    if (segMan && segArmed > 0 && render) {
      std::fprintf(stderr, "[rvk][segman] f%ld ARMED: %zu resolves, %zu batches this frame\n", frame, resolves.size(), batches.size());
      // FULL batch manifest (2026-07-14): the terrain isn't in any resolve seg, so dump EVERY
      // batch this frame — vs/tex/fmt/vp — to find the live scrolling-terrain draw (a large-
      // texture full-field layer that renders but never resolves into a captured target).
      static int fullDumped = 0;
      if (fullDumped < 2) { fullDumped++;
        for (size_t bi4 = 0; bi4 < batches.size(); ++bi4) {
          auto& bb = batches[bi4];
          uint32_t tbase = 0; int isRes = 0; uint32_t tfmt = 0, tw = 0, th = 0;
          for (auto& kv : g_resolveTex) if (kv.second.idx == bb.texIdx) { tbase = kv.first; isRes = 1; tw = kv.second.w; th = kv.second.h; break; }
          if (!isRes) for (auto& kv : g.rTexIndex) if (kv.second == bb.texIdx) { tbase = (uint32_t)(kv.first >> 8); tfmt = (uint32_t)(kv.first & 0xFF); break; }
          std::fprintf(stderr, "[rvk][fullbatch] f%ld b%zu vs=%d tex=0x%X%s %ux%u fmt=%u vp={%.0f,%.0f,%.0f,%.0f} idx=%u\n",
            frame, bi4, bb.vsIdx, tbase, isRes ? "(RES)" : "", tw, th, tfmt, bb.vp.x, bb.vp.y, bb.vp.width, bb.vp.height, bb.indexCount);
        }
      }
      if (resolves.empty()) segArmed--;   // empty frames consume the budget too
    }
    static uint32_t texWatchR = [](){ const char* e = std::getenv("RVK_TEXWATCH"); return e ? (uint32_t)std::strtoul(e, nullptr, 0) : 0u; }();
    // RVK_EMPTYRES EDRAM-proxy source: dst key of the most recent NON-EMPTY sub-screen resolve
    // (the field panel). Persistent across frames — an empty-segment resolve copies whatever
    // EDRAM last held, which survives frame boundaries on hardware.
    static uint32_t g_emptyResSrc = 0;
    // segsElsewhere (overdraw fix 2026-07-21, oracle: title screen is STEADY, only press-start
    // text blinks): true when any NON-EMPTY segment was consumed by FIXB/FIXB2 (rendered into its
    // own texture, NOT the shared offscreen). When false, the OLD path already drew every batch
    // into the persistent offscreen — the empty-final-segment display fork then presents it AS-IS
    // instead of re-drawing all batches on top (which alpha-accumulated the title's glyph passes
    // ~20x per blink phase = a text-brightness pulse the oracle doesn't have).
    bool segsElsewhere = false;
    for (auto& r : resolves) {
      if (texWatchR && r.dst == texWatchR) {
        std::fprintf(stderr, "[rvk][texwatch/resolve] f%ld dst=0x%X seg[%zu,%zu) segBatches=%zu %s w=%u\n",
          frame, r.dst, b0, r.batchIdx, r.batchIdx - b0, (r.batchIdx == b0) ? "EMPTY-STOMP" : "nonempty",
          (uint32_t)(g_resolveTex.count(r.dst) ? g_resolveTex[r.dst].w : 0u));
        // Per-batch detail for the watched dst's segment (tile-ring RE 2026-07-19): vs/tex/vp/idx,
        // resolving whether the 1-batch ring-slot draw samples a resolve (feedback) or a reg texture.
        // RVK_TWSEGCAP raises the print budget (default 24) — needed when the interesting segments
        // come late (e.g. char-select draw manifests after a long nav burns the cap on menus).
        static long twSeg = 0;
        static long twSegMax = [](){ const char* e = std::getenv("RVK_TWSEGCAP"); return e ? std::atol(e) : 24; }();
        if (twSeg++ < twSegMax) {
          for (size_t bi4 = b0; bi4 < r.batchIdx; ++bi4) {
            auto& bb = batches[bi4]; uint32_t tb = 0; int ir = 0; uint32_t tf = 0;
            for (auto& kv : g_resolveTex) if (kv.second.idx == bb.texIdx) { tb = kv.first; ir = 1; break; }
            if (!ir) for (auto& kv : g.rTexIndex) if (kv.second == bb.texIdx) { tb = (uint32_t)(kv.first >> 8); tf = (uint32_t)(kv.first & 0xFF); break; }
            char pv4[320]; int po4 = 0;
            for (uint32_t k4 = 0; k4 < 4 && k4 < bb.indexCount; ++k4) {
              const float* f4 = (const float*)(Vraw + (size_t)Iarr[bb.firstIndex + k4] * 6);
              float vu4, vv4;
              if (bb.vsIdx == 48) { vu4 = f4[2]; vv4 = f4[3]; } else { vu4 = f4[4]; vv4 = f4[5]; }
              po4 += std::snprintf(pv4 + po4, sizeof pv4 - po4, " (%.1f,%.1f uv %.2f,%.2f)", f4[0], f4[1], vu4, vv4);
            }
            std::fprintf(stderr, "[rvk][texwatch/seg]   b%zu vs=%d texIdx=%u tex=0x%X%s fmt=%u vp={%.0f,%.0f,%.0f,%.0f} idx=%u verts:%s\n",
              bi4, bb.vsIdx, bb.texIdx, tb, ir ? "(RES)" : "", tf, bb.vp.x, bb.vp.y, bb.vp.width, bb.vp.height, bb.indexCount, pv4);
          }
        }
      }
      if (segMan && segArmed > 0 && (segArmed--, true)) {
        std::fprintf(stderr, "[rvk][segman] f%ld dst=0x%X %ux%u seg batches[%zu,%zu):\n", frame, r.dst, r.w, r.h, b0, r.batchIdx);
        for (size_t bi3 = b0; bi3 < r.batchIdx; ++bi3) {
          auto& bb = batches[bi3];
          uint32_t tbase = 0; int isRes = 0; uint32_t tfmt = 0;
          for (auto& kv : g_resolveTex) if (kv.second.idx == bb.texIdx) { tbase = kv.first; isRes = 1; break; }
          if (!isRes) for (auto& kv : g.rTexIndex) if (kv.second == bb.texIdx) { tbase = (uint32_t)(kv.first >> 8); tfmt = (uint32_t)(kv.first & 0xFF); break; }
          std::fprintf(stderr, "[rvk][segman]   batch%zu vs=%d texIdx=%u tex=0x%X%s fmt=%u vp={%.0f,%.0f,%.0f,%.0f} idxCount=%u\n",
            bi3, bb.vsIdx, bb.texIdx, tbase, isRes ? "(RES)" : "", tfmt, bb.vp.x, bb.vp.y, bb.vp.width, bb.vp.height, bb.indexCount);
        }
      }
      if (compB0 < 0 && segHasComposite(b0, r.batchIdx)) { compB0 = (long)b0; compB1 = (long)r.batchIdx;
        if (compDbg) std::fprintf(stderr, "[rvk][compdbg] frame%ld COMPSEG tagged seg%d batches[%zu,%zu)\n", frame, segN, b0, r.batchIdx); }
      // LEG-46 Fix B2: sub-screen targets render natively via scratch + copy (see above).
      if (fixB2) {
        auto itc = g_resolveTex.find(r.dst);
        // Restrict to the FEEDBACK-class playfield targets (640x512 / 512x512): segment
        // boundaries dice the stream arbitrarily, and rendering whole segments scaled into
        // small 320x240 UI targets produced incoherent magnified junk (v1 finding). The
        // 320x240 rotation + front buffer keep the tolerant old offscreen+blit path.
        if (itc != g_resolveTex.end() && itc->second.w >= 512 && itc->second.w < kW && itc->second.image) {
          // RVK_ATLASLOG (portrait-atlas RE 2026-07-15): the char-select portrait region is fed by a
          // vs=47 composite that samples the 512x512 atlas 0x1CFF3000; the live scene paints the
          // sibling 0x1CEF3000. 0x1CFF3000 only gets a non-empty segment on periodic "build" frames.
          // Log those build segments (dst + batch vs/tex/vp) so we can see why the atlas comes out
          // empty on our port. Persistent (not one-shot like segman). Default off.
          // Env value = START FRAME (log only frames >= it; "1" = from boot) — added 2026-07-21
          // for the char-card painting hunt: the 200-line cap otherwise burns on mode-select
          // entry builds thousands of frames before the held char-select.
          static long atlasLogF = std::getenv("RVK_ATLASLOG") ? std::atol(std::getenv("RVK_ATLASLOG")) : -1;
          if (atlasLogF >= 0 && frame >= atlasLogF && r.batchIdx > b0 && itc->second.w >= 512) {
            static long al = 0;
            if (al++ < 3000) {
              std::fprintf(stderr, "[atlaslog] f%ld dst=0x%X %ux%u seg[%zu,%zu) %zu batches:\n",
                frame, r.dst, itc->second.w, itc->second.h, b0, r.batchIdx, r.batchIdx - b0);
              for (size_t bi5 = b0; bi5 < r.batchIdx; ++bi5) {
                auto& bb = batches[bi5]; uint32_t tb = 0; int ir = 0; uint32_t rfmt = 0; int reg = 0;
                for (auto& kv : g_resolveTex) if (kv.second.idx == bb.texIdx) { tb = kv.first; ir = 1; break; }
                if (!ir) for (auto& kv : g.rTexIndex) if (kv.second == bb.texIdx) { tb = (uint32_t)(kv.first >> 8); rfmt = (uint32_t)(kv.first & 0xFF); reg = 1; break; }
                std::fprintf(stderr, "[atlaslog]   b%zu vs=%d texIdx=%u tex=0x%X%s fmt=%u vp={%.0f,%.0f,%.0f,%.0f} idx=%u%s\n",
                  bi5, bb.vsIdx, bb.texIdx, tb, ir ? "(RES)" : (reg ? "(REG)" : "(NONE)"), rfmt, bb.vp.x, bb.vp.y, bb.vp.width, bb.vp.height, bb.indexCount,
                  bb.indexCount > 6 ? "  <-MULTITRI" : "");
              }
            }
          }
          if (r.batchIdx > b0) {
            uint32_t skey = 0xE0000000u | ((itc->second.w & 0xFFFu) << 12) | (itc->second.h & 0xFFFu);
            ResolveTex& scratch = getOrCreateResolveTex(skey, itc->second.w, itc->second.h);
            ResolveTex& real = g_resolveTex.find(r.dst)->second;  // re-find: insert may rehash
            // RVK_ATLASPERSIST (default OFF): seed the scratch from the current atlas so PARTIAL
            // segment redraws (the guest's shrinking 116->39 select rebuilds) layer onto the
            // composed screen instead of replacing it (see submitSegInto). Targets the "raw atlas
            // page / bg-only" half of the select flicker. LEFT OFF BY DEFAULT because it REGRESSES
            // the live field to grey placeholder tiles (A/B-proven 2026-07-15): the stage-1 field
            // ALSO resolves 0xF95D000 through this FIXB2 path, repaints fully every frame, and its
            // layers sample 0xF95D000 as feedback -> seeding the scratch creates a sample-vs-seed
            // hazard. field_active (0x885C1A20) can't scope it out (select screens also set it, for
            // the portrait present). A correct fix needs a partial-vs-full-rebuild discriminator
            // (peak-batch heuristic like RVK_RESKEEP=2) or the oracle resolve replay; until then the
            // dominant corruption is already gone via RT_VTXSNAP, and this stays an opt-in lever.
            static int atlasPersist = std::getenv("RVK_ATLASPERSIST") ? std::atoi(std::getenv("RVK_ATLASPERSIST")) : 0;
            // CHAR-CARD PAINTING FIX (2026-07-21): the card painting is drawn INCREMENTALLY —
            // vs48base probe shows the paint draws grow per frame during entry (n 12->33->54...)
            // and trickle at settle: the guest paints a few 16x16 tiles per frame RELYING ON
            // EDRAM PERSISTENCE (blend = plain lerp/additive, r14 multiply refuted; texture,
            // uv, alpha, geometry all probe-verified clean). Our per-frame CLEARED scratch keeps
            // only each frame's tiles -> black interior. This is the r20 ATLASPERSIST class; it
            // stayed opt-in because the field repaints fully and seeding hazards its feedback —
            // and field_active couldn't discriminate. THE DECOMP GAVE THE REGISTER-TRUE SCOPE
            // TONIGHT: the select FSM browse state 0x884D678C == 3 (FUN_88137168 sets it for the
            // select screens; gameplay/attract never do). Seed the scratch from the persistent
            // target ONLY while that state is live. RVK_NOSELECTPERSIST=1 reverts.
            // 2026-07-21 late: select-scoped seeding TESTED AND REVERTED TO OPT-IN — at settle
            // the FULL 103-tile mesh draws EVERY frame (persistence unneeded), the interior
            // stayed black (the tiles' uv sample the never-loaded half of the striped page =
            // Defect A alone), and seeding washed the No-Entry panel white (per-frame additive
            // draws accumulate across seeded frames). Lever kept for the entry-animation case.
            static bool selPersistOpt = [](){ const char* e = std::getenv("RVK_SELECTPERSIST");
              return e && std::atoi(e) != 0; }();
            bool selBrowse = selPersistOpt && g_base && be16(0x884D678Cu) == 3;
            submitSegInto(scratch, b0, r.batchIdx, (atlasPersist || selBrowse) ? &real : nullptr);
            // RVK_ATLASDUMP (Round-14, 2026-07-15): dump the freshly-built self-composite atlas on
            // EVERY build (rate-limited), independent of the sigdump/DUMPRES front-buffer trigger.
            // The ~2s char-select bounce made every sigdump-gated capture unreliable (the 640x512
            // atlas is rarely live on the sigdump frame); this fires here where `scratch` provably
            // holds the just-rendered atlas (SHADER_READ layout), so baseline vs RVK_SPRITENOADD=1
            // vs a per-layer skip can be A/B'd on the atlas itself. Writes /tmp/atlasdump_WxH_seq.png.
            // NOTE: valid bytes only under RVK_HDR=0 (LDR/UNORM8 scratch); under HDR the R16F scratch
            // is misread by writePng (same caveat as DUMPRES). Default off = byte-identical.
            if (std::getenv("RVK_ATLASDUMP") && scratch.w >= 512 && scratch.image) {
              segBatchFlush();   // RVK_SEGBATCH: the dump reads the scratch — settle deferred renders first
              static long adSeq = 0; static long adEvery = [](){ const char* e = std::getenv("RVK_ATLASDUMP_EVERY"); long v = e ? std::atol(e) : 30; return v > 0 ? v : 30; }();
              if ((adSeq % adEvery) == 0) {
                segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
                rvkRingNext("adump"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(adump)");
                VkCommandBufferBeginInfo cbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; cbi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
                VKC(vkBeginCommandBuffer(g.cmd, &cbi), "begin(adump)");
                VkImageMemoryBarrier ab{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; ab.srcQueueFamilyIndex = ab.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
                ab.image = scratch.image; ab.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
                ab.oldLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL; ab.newLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
                ab.srcAccessMask = VK_ACCESS_SHADER_READ_BIT; ab.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
                vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &ab);
                VkBufferImageCopy cp{}; cp.imageSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; cp.imageExtent = {scratch.w, scratch.h, 1};
                vkCmdCopyImageToBuffer(g.cmd, scratch.image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, g.readback, 1, &cp);
                ab.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL; ab.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
                ab.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT; ab.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
                vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &ab);
                VKC(vkEndCommandBuffer(g.cmd), "end(adump)");
                VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
                VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(adump)");
                VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(adump)");
                VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(adump)");
                void* map = nullptr;
                if (vkMapMemory(g.dev, g.readbackMem, 0, VK_WHOLE_SIZE, 0, &map) == VK_SUCCESS) {
                  char nm[128]; std::snprintf(nm, sizeof nm, "/tmp/atlasdump_%ux%u_%ld.png", scratch.w, scratch.h, adSeq);
                  writePng(nm, (const uint8_t*)map, scratch.w, scratch.h);
                  vkUnmapMemory(g.dev, g.readbackMem);
                }
              }
              ++adSeq;
            }
            blitTexToTex(scratch, real, fbFlip);
            rvkResMarkRendered(real, frame);
            g_emptyResSrc = r.dst;   // RVK_EMPTYRES: this target now holds the live EDRAM content
            g_fixb2ScratchF[skey] = frame;   // EDRAM-dup fix: this size-class scratch is live for THIS frame
          }
          // CHAR-CARD PAINTING FIX (2026-07-21, EDRAM-persistence class): the guest draws the
          // char-select painting ONCE (70-batch segment -> resolve dst A) and then immediately
          // resolves AGAIN to a second dst B with ZERO draws in between (back-to-back RB_COPYs of
          // the SAME EDRAM). Our "empty-preserve" skipped B forever -> B never rendered -> the
          // panel compose (which samples ~B, base+0x8000) got RESALIAS'd to a wrong 0x80000-distant
          // sibling -> gold frame interior BLACK while the painting sat perfect in A (atlasdump
          // proof). Hardware truth: consecutive resolves with no draws between copy IDENTICAL
          // EDRAM content. So: an empty segment whose size-class scratch was built THIS frame by a
          // preceding segment receives the SAME scratch blit. Cross-frame empties keep the old
          // preserve (EDRAM lineage across frames isn't modeled). RVK_NOEDRAMDUP=1 reverts.
          else {
            static bool noEdramDup = [](){ const char* e = std::getenv("RVK_NOEDRAMDUP");
              return e && std::atoi(e) != 0; }();
            uint32_t skey2 = 0xE0000000u | ((itc->second.w & 0xFFFu) << 12) | (itc->second.h & 0xFFFu);
            auto sfIt = g_fixb2ScratchF.find(skey2);
            if (!noEdramDup && sfIt != g_fixb2ScratchF.end() && sfIt->second == frame) {
              ResolveTex& scratch2 = getOrCreateResolveTex(skey2, itc->second.w, itc->second.h);
              ResolveTex& real2 = g_resolveTex.find(r.dst)->second;
              if (scratch2.image && real2.image) {
                blitTexToTex(scratch2, real2, fbFlip);
                rvkResMarkRendered(real2, frame);
                if (compDbg) std::fprintf(stderr, "[rvk][compdbg] frame%ld FIXB2 SEG %d EDRAM-DUP -> tex dst=0x%X %ux%u (same-frame scratch copy)\n",
                  frame, segN, r.dst, r.w, r.h);
              }
            }
          }
          if (compDbg) std::fprintf(stderr, "[rvk][compdbg] frame%ld FIXB2 SEG %d batches[%zu,%zu) -> tex dst=0x%X %ux%u%s\n",
            frame, segN, b0, r.batchIdx, r.dst, r.w, r.h, (r.batchIdx <= b0) ? " (empty-preserve)" : "");
          if (r.batchIdx > b0) segsElsewhere = true;   // drawn into the atlas tex, not the offscreen
          b0 = r.batchIdx; ++segN;
          continue;
        }
      }
      auto it = g_resolveTex.find(r.dst);
      if (fixB) {
        // Fix B: render the layer segment directly into its resolve texture at native w×h.
        if (it != g_resolveTex.end()) submitSegInto(it->second, b0, r.batchIdx);
        if (compDbg) std::fprintf(stderr, "[rvk][compdbg] frame%ld FIXB LAYER-SEG %d batches[%zu,%zu) -> tex dst=0x%X %ux%u%s\n",
          frame, segN, b0, r.batchIdx, r.dst, r.w, r.h, (r.batchIdx <= b0) ? " (empty-skip)" : "");
        if (r.batchIdx > b0) segsElsewhere = true;     // drawn into the resolve tex, not the offscreen
        b0 = r.batchIdx; ++segN;
        continue;
      }
      // ---- OLD path (RVK_NOFIXB): render into offscreen + full-frame blit ----
      // LEGACY-TITLE-BLINK FIX part 2 (2026-07-21): on SHELL frames (no field flag, no ROM), the
      // EDRAM-proxy segment render must LOAD, not clear — hardware EDRAM holds last frame's
      // content when the guest runs a partial pass (the title's 20-window copyright-glyph phase
      // draws 1 batch and resolves 0x660000; the CLEAR here wiped the title out of g.image
      // BEFORE the display fork, so the display fix alone still showed glyphs-on-navy, and
      // blitResolve stamped glyphs-on-navy into the resolve tex as well). Field/ROM frames keep
      // the historic CLEAR (the bloom-pool/feedback resolve chain was tuned around it — see the
      // RESKEEP/RESREAL history below). RVK_NOSHELLPERSIST=1 reverts.
      static bool noShellPersist = [](){ const char* e = std::getenv("RVK_NOSHELLPERSIST");
        return e && std::atoi(e) != 0; }();
      bool shellFrame = !noShellPersist && g_base && be32(GA_FIELD_ACTIVE) == 0 && g_rt_romactive == 0;
      // ★ RVK_R5PIX (compose-1:1 Leg 1c, 2026-07-28): pixel-truth probe for the empty-segment
      // front-buffer blit. Innocent case = the LOADed offscreen carries persisted content
      // (nonclear HIGH); flash case = the offscreen was cleared this frame and the redraw got
      // sliced into the next window, so the blit stomps a near-empty image over the screen
      // (nonclear LOW) = the user's one-frame element flicker. Logs EVERY empty-seg event
      // (~10/s) — offline bimodality is the verdict. Readback only on those frames.
      static int r5pix = std::getenv("RVK_R5PIX") ? std::atoi(std::getenv("RVK_R5PIX")) : 0;
      bool r5Empty = r5pix && shellFrame && r.batchIdx == b0;
      if (compDbg) {
        submitSeg(b0, r.batchIdx, true, 0, 0, shellFrame ? 1 : -1);
        long nz = countOffscreenNonClear();
        std::fprintf(stderr, "[rvk][compdbg] frame%ld LAYER-SEG %d batches[%zu,%zu) -> offscreen nonclear=%ld px, resolve dst=0x%X %ux%u\n",
          frame, segN, b0, r.batchIdx, nz, r.dst, r.w, r.h);
      } else {
        submitSeg(b0, r.batchIdx, r5Empty, 0, 0, shellFrame ? 1 : -1);
        if (r5Empty) {
          long nz = countOffscreenNonClear();
          std::fprintf(stderr, "[r5pix] f%ld nonclear=%ld dst=0x%X full=%d\n",
            frame, nz, r.dst, (int)(it != g_resolveTex.end() && it->second.w == kW));
          // ★ Leg-2 design datum: on a FLASH event (low content), dump the window's segment
          // roster (RT_SEGTAB) + this resolve's batch position — names the slice shape (early
          // orphaned resolve vs frame-straddle) that guest-frame-atomic windows must fix.
          if (nz < 200000) {
            int sn2 = (int)g_seg_n; if (sn2 > 64) sn2 = 64; if (sn2 < 0) sn2 = 0;
            std::fprintf(stderr, "[r5pix]   FLASH roster: nseg=%d wbase=0x%X segpos=%zu/%zu batches=%d |",
              sn2, (unsigned)g_seg_wbase, (size_t)segN, resolves.size(), ndraw);
            for (int s2 = 0; s2 < sn2 && s2 < 16; ++s2)
              std::fprintf(stderr, " s%d[len=%u src=0x%X lat=%u]", s2, g_seg_len[s2], g_seg_src[s2], g_seg_lat[s2]);
            std::fprintf(stderr, "\n");
            // ★ C3-s1 submit-history dump (the cleardefer no-fire lesson: the empty front-buffer
            // resolve is the SECOND submit, after a full content pass — the low offscreen content
            // needs per-submit attribution, not window-head theories). All resolves this frame:
            std::fprintf(stderr, "[r5pix]   resolves:");
            for (size_t rr2 = 0; rr2 < resolves.size() && rr2 < 8; ++rr2)
              std::fprintf(stderr, " r%zu[bi=%zu dst=0x%X %ux%u]", rr2, resolves[rr2].batchIdx, resolves[rr2].dst, resolves[rr2].w, resolves[rr2].h);
            std::fprintf(stderr, " | cb65b=%u\n", (unsigned)(g_base ? *(g_base + 0x821EC65Bu) : 255));
          }
        }
      }
      // RVK_RESREAL fix (2026-07-13, texlog RE): the OLD path blitResolves real content into the
      // target (e.g. the 320x240 bloom-pool feedback resolves the field samples as vs=5/ps=34) but
      // never marked everRendered — so RVK_RESREAL rejected them on the next frame's exact match,
      // they fell through to the fmt check (fmt=54 unsupported), and returned WHITE (index 0) =
      // the field wash. Mark the target rendered when the segment actually painted content
      // (non-empty: batchIdx > b0), mirroring FIXB2. Empty segments preserve prior content.
      // RVK_RESKEEP (2026-07-14, Fable-guided field-wash fix): the OLD path blitResolves the
      // just-rendered offscreen into the target UNCONDITIONALLY — but an EMPTY segment (r.batchIdx==b0)
      // still ran submitSeg, which begins a CLEARED renderpass (persist requires resolves.empty(),
      // false here) and draws nothing -> blitResolve then stomps navy/partial content OVER the good
      // resolve. FIXB2 guards this with `batchIdx>b0` but the full-frame (w==kW) front-buffer target is
      // deliberately EXCLUDED from FIXB2 -> it always takes this unguarded stomp path = the per-frame
      // field-BG wash flicker. RESKEEP=1: skip the blit on an EMPTY segment (preserve prior content,
      // as the RESREAL comment already claims it does). RESKEEP=2: also reject a TRUNCATED full-frame
      // segment (partial redraw < 50% of this target's recent peak batch-count), mirroring the
      // submitSeg persist peak logic. Default off = byte-identical.
      if (it != g_resolveTex.end()) {
        static int resKeep = std::getenv("RVK_RESKEEP") ? std::atoi(std::getenv("RVK_RESKEEP")) : 0;
        size_t segLen = r.batchIdx - b0;
        bool doBlit = true;
        // ★ RESKEEP=3 (compose-1:1 Leg 1c, 2026-07-28): shell-scoped empty-seg skip — the
        // PIXEL-PROVEN flash mitigation ([r5pix] bimodal: 1443 innocent full-content re-blits
        // vs 44 low-content partial-frame deliveries per 150s; RESKEEP arm = same mechanism
        // rate, ZERO deliveries, resolve texels clean). Scoped to shell frames = exactly the
        // measured population; field paths keep historic semantics (1/2 unchanged). INTERIM —
        // the register-true cure is guest-frame-atomic windows (Leg 2); this stops the visible
        // flash until that lands.
        if (resKeep == 3 && segLen == 0 && shellFrame) doBlit = false;
        // ★ R5 stomp counter (compose-1:1 Leg 1b, 2026-07-28, never-silent): an empty-segment
        // blit on a SHELL frame is the stale/cleared-pixel stomp candidate for the user's
        // multi-element one-frame flicker (draw census came back CLEAN — the flicker is not
        // missing draws, so pixel-level stomps are the live suspect). Counting only.
        if (segLen == 0 && shellFrame) {
          static long r5n = 0;
          if ((++r5n % 64) == 1)
            std::fprintf(stderr, "[rvk][r5stomp] x%ld f%ld dst=0x%X %ux%u fullframe=%d suppressed=%d (empty-seg blit candidate)\n",
              r5n, frame, r.dst, it->second.w, it->second.h, (int)(it->second.w == kW), (int)(resKeep >= 1));
        }
        if (resKeep >= 1 && resKeep != 3) {   // 3 = shell-scoped only (handled above)
          if (segLen == 0) doBlit = false;   // empty segment: no content painted -> would stomp
          else if (resKeep >= 2 && it->second.w == kW) {
            static std::unordered_map<uint32_t,int> peakSeg, decayC;
            int& pk = peakSeg[r.dst];
            if ((int)segLen > pk) pk = (int)segLen;
            else if (++decayC[r.dst] >= 120) { decayC[r.dst] = 0; if (pk > 1) pk--; }  // slow recover
            if (pk > 1 && (int)segLen * 2 < pk) doBlit = false;   // truncated full-frame redraw
          }
        }
        // RVK_EMPTYRES (2026-07-19, matched-state oracle-diff tile-ring fix): a real RB_COPY
        // resolve is an EDRAM copy REGARDLESS of draw count, but this path handles an EMPTY
        // segment by blitting the just-CLEARED offscreen into the dst — every 320x240 ring tile
        // dumps as uniform clear-navy (cb=8.3 flat) while the oracle's ATTRACT-DEMO capture
        // (attract_frame13949, same game state as run_fieldhold) shows all 91 tiles carrying
        // real panel content at cb~146-156. Materialize instead: scale-blit the EDRAM proxy
        // (g_emptyResSrc = last non-empty sub-screen resolve, the field panel) into the dst.
        // Front-buffer (w==kW) targets keep their existing preserve/stomp semantics.
        // NOTE (2026-07-19 outcome): the ring-slot segments turned out NON-empty (a stride-16
        // rect draw, see RVK_NOVS5RECT above) — this lever is NOT the tile fix and never fires
        // under run_fieldhold. It stays as the register-true handler for genuinely-empty
        // sub-screen resolves (real HW copies EDRAM regardless of draws). Default OFF until
        // a screen that exercises it is validated against the oracle; RVK_EMPTYRES=1 enables.
        static int emptyRes = std::getenv("RVK_EMPTYRES") ? std::atoi(std::getenv("RVK_EMPTYRES")) : 0;
        if (emptyRes && segLen == 0 && it->second.w < kW && g_emptyResSrc && g_emptyResSrc != r.dst) {
          auto sIt = g_resolveTex.find(g_emptyResSrc);
          if (sIt != g_resolveTex.end() && sIt->second.image && sIt->second.everRendered) {
            blitTexToTex(sIt->second, it->second, false);
            rvkResMarkRendered(it->second, frame);
            doBlit = false;
            if (texWatchR && r.dst == texWatchR)
              std::fprintf(stderr, "[rvk][emptyres] f%ld dst=0x%X materialized from src=0x%X (%ux%u -> %ux%u)\n",
                frame, r.dst, g_emptyResSrc, sIt->second.w, sIt->second.h, it->second.w, it->second.h);
          }
        }
        if (doBlit) {
          blitResolve(it->second);
          if (r.batchIdx > b0) {
            rvkResMarkRendered(it->second, frame);
            if (it->second.w < kW) g_emptyResSrc = r.dst;   // RVK_EMPTYRES: EDRAM proxy update
          }
          // Texwatch probe (tile-ring RE 2026-07-19): read back the just-blitted watched target and
          // print its mean — splits "blitResolve delivered clear" from "cleared later". Clobbers
          // g.readback for this frame (same caveat as RVK_DUMPRES). Diagnostic, texwatch-gated.
          if (texWatchR && r.dst == texWatchR && it->second.image) {
            static long bmN = 0;
            if (bmN++ < 24) {
              ResolveTex& rt2 = it->second;
              segBatchFlush();
              rvkRingNext("twbm"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(twbm)");
              VkCommandBufferBeginInfo cbi2{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; cbi2.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
              VKC(vkBeginCommandBuffer(g.cmd, &cbi2), "begin(twbm)");
              VkImageMemoryBarrier bb2{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; bb2.srcQueueFamilyIndex = bb2.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
              bb2.image = rt2.image; bb2.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
              bb2.oldLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL; bb2.newLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
              bb2.srcAccessMask = VK_ACCESS_SHADER_READ_BIT; bb2.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
              vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &bb2);
              VkBufferImageCopy cp2{}; cp2.imageSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; cp2.imageExtent = {rt2.w, rt2.h, 1};
              vkCmdCopyImageToBuffer(g.cmd, rt2.image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, g.readback, 1, &cp2);
              bb2.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL; bb2.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
              bb2.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT; bb2.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
              vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &bb2);
              VKC(vkEndCommandBuffer(g.cmd), "end(twbm)");
              VkSubmitInfo si2{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si2.commandBufferCount = 1; si2.pCommandBuffers = &g.cmd;
              VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(twbm)");
              VKC(rvkQueueSubmit(g.queue, 1, &si2, g.fence), "submit(twbm)");
              VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(twbm)");
              void* map2 = nullptr;
              if (vkMapMemory(g.dev, g.readbackMem, 0, VK_WHOLE_SIZE, 0, &map2) == VK_SUCCESS) {
                const uint8_t* px = (const uint8_t*)map2;
                unsigned long long s[4] = {0,0,0,0}; size_t np = (size_t)rt2.w * rt2.h;
                for (size_t p2 = 0; p2 < np; ++p2) for (int c2 = 0; c2 < 4; ++c2) s[c2] += px[p2*4+c2];
                std::fprintf(stderr, "[rvk][texwatch/blitmean] f%ld dst=0x%X post-blit mean RGBA=%.1f/%.1f/%.1f/%.1f\n",
                  frame, r.dst, (double)s[0]/np, (double)s[1]/np, (double)s[2]/np, (double)s[3]/np);
                vkUnmapMemory(g.dev, g.readbackMem);
              }
            }
          }
        }
        else if (texWatchR && r.dst == texWatchR)
          std::fprintf(stderr, "[rvk][reskeep] f%ld dst=0x%X preserved (segBatches=%zu) — no stomp\n", frame, r.dst, segLen);
      }
      b0 = r.batchIdx; ++segN;
    }
    // Read the LAST resolve texture (the front buffer / final composite) back into the offscreen,
    // then to the readback buffer. The frame's real display target is whatever the game RB_COPY-
    // resolved to (0x6E2000 front buffer for boot logos / loadscreen / menu bg), NOT the offscreen.
    auto readbackResolveTex = [&](ResolveTex& rt) {
      segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
      rvkRingNext("rbrt"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(rbrt)");
      VkCommandBufferBeginInfo cbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; cbi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
      VKC(vkBeginCommandBuffer(g.cmd, &cbi), "begin(rbrt)"); if (rvkRingOn()) rvkRingGuard();
      auto barrier = [&](VkImage im, VkImageLayout ol, VkImageLayout nl, VkAccessFlags sa, VkAccessFlags da, VkPipelineStageFlags ss, VkPipelineStageFlags ds) {
        VkImageMemoryBarrier b{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; b.srcQueueFamilyIndex = b.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        b.image = im; b.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1}; b.oldLayout = ol; b.newLayout = nl; b.srcAccessMask = sa; b.dstAccessMask = da;
        vkCmdPipelineBarrier(g.cmd, ss, ds, 0, 0, nullptr, 0, nullptr, 1, &b);
      };
      barrier(rt.image, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_ACCESS_SHADER_READ_BIT, VK_ACCESS_TRANSFER_READ_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT);
      barrier(g.image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_ACCESS_TRANSFER_READ_BIT, VK_ACCESS_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT);
      static bool fbFlip2r = std::getenv("RVK_FBFLIP2") != nullptr;
      bool ffbr = fbFlip2r && rt.w == kW && rt.h == kH;   // un-flip the bottom-up front buffer for display
      VkImageBlit bl{}; bl.srcSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1};
      if (ffbr) { bl.srcOffsets[0] = {0, (int32_t)rt.h, 0}; bl.srcOffsets[1] = {(int32_t)rt.w, 0, 1}; }
      else      { bl.srcOffsets[1] = {(int32_t)rt.w, (int32_t)rt.h, 1}; }
      bl.dstSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; bl.dstOffsets[1] = {(int32_t)kW, (int32_t)kH, 1};
      vkCmdBlitImage(g.cmd, rt.image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, g.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &bl, VK_FILTER_LINEAR);
      barrier(g.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_ACCESS_TRANSFER_WRITE_BIT, VK_ACCESS_TRANSFER_READ_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT);
      barrier(rt.image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_ACCESS_TRANSFER_READ_BIT, VK_ACCESS_SHADER_READ_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT);
      copyDisplayToReadback(g.cmd);   // F6: tonemaps to UNORM8 under RVK_HDR
      VKC(vkEndCommandBuffer(g.cmd), "end(rbrt)");
      VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
      VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(rbrt)");
      VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(rbrt)");
      if (rvkRingOn()) g.ringPending[g.ringIdx] = true; else VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(rbrt)");
      return true;
    };
    if (std::getenv("RVK_BATCHDBG")) {
      std::fprintf(stderr, "[rvk][segdbg] frame%ld resolves=%zu batches=%zu finalSeg=[%zu,%zu) (empty=%d)",
        frame, resolves.size(), batches.size(), b0, batches.size(), (int)(b0 >= batches.size()));
      for (auto& r : resolves) std::fprintf(stderr, " rdst=0x%X(%ux%u)", r.dst, r.w, r.h);
      std::fprintf(stderr, "\n");
    }
    ResolveTex* lastRt = nullptr;
    if (b0 >= batches.size() && !resolves.empty()) {
      auto it = g_resolveTex.find(resolves.back().dst);
      if (it != g_resolveTex.end() && it->second.image) lastRt = &it->second;
    }
    // RVK_PILLARBOX (LEG-48, 2026-07-14 TATE-panel milestone): honor the guest's ACTUAL swap.
    // The SDK-oracle cross-check (futari_trace_dump on a captured field arena) proved the guest's
    // real front-buffer / swap target is 0xF95D000 at 640x512 — the native vertical TATE playfield —
    // NOT a 1280x720 frontbuffer. 0x660000 (which the PM4 decoder had been flagging as a "1280x720
    // resolve") is actually a FONT GLYPH ATLAS: it reads back as a character sheet in the oracle and
    // has everRendered=0 in our own pipeline (never a real render target). There is therefore NO
    // separate centered-placement composite kick to honor: the console scales/pillarboxes the 640x512
    // swap buffer to the display. This lever reproduces that placement — present the 640x512 playfield
    // resolve centered in the 1280x720 window with a dark border (the SDK reference shows wallpaper +
    // standing-character side art there; a flat border is the honest synthesized approximation until
    // the border layer is REd). CAVEAT (documented, 2026-07-14): our 0xF95D000 buffer content is itself
    // still incoherent (RVK_DUMPRES shows dithered terrain over a green grid — the vs=48 terrain does
    // not yet render cleanly into the native 640x512 target); this lever fixes the PLACEMENT topology,
    // not that buffer's content. Default 0 = off (byte-identical); flip once the buffer is coherent.
    //
    // LEG-49 (round-4 milestone verdict, 2026-07-14, live SDK-oracle side-by-side): DO NOT flip the
    // default yet — the pillarbox present is NOT steady-state-robust and its ORIENTATION is wrong.
    // Driving the real SDK build (futari_recomp/out/futari-test/futari.exe) to stage-1 shows the
    // playfield as a PORTRAIT (TATE) panel with the HUD [PLAYER-1 / HIGH score / "Original Mode"] as a
    // HORIZONTAL strip at the TOP and gem side-borders. OUR 640x512 present is LANDSCAPE, and that same
    // HUD appears as a 90-degree-ROTATED + MIRRORED garbled strip on the panel's RIGHT edge (plus grey
    // placeholder rects and scene-to-scene variance). i.e. the 640x512 buffer is authored for a
    // rotated/portrait SCANOUT (Xbox360 TATE) that we present un-rotated -> the ~18% "top black band"
    // is a symptom of that orientation gap, not a standalone content hole. The concrete next step is a
    // 90-deg-CCW portrait present (rotated 640x512 -> 512x640, centered {384,40}) + HUD-strip un-mirror,
    // A/B'd against the SDK portrait reference — NOT a band patch. Refs saved: C:/tmp/milestone_sdk_ref.png
    // (SDK), C:/tmp/milestone_ours.png (ours). Until that lands, RVK_PILLARBOX stays an env-gated A/B lever.
    // RVK_PILLARBOX present mode. 0=off (legacy landscape composite), 1=landscape-centered A/B,
    // 2=TATE portrait (the console's native rotated scanout — LEG-50). Default (env unset): AUTO —
    // present the TATE portrait on FIELD frames (field_active 0x885C1A20 != 0) and stay off on
    // title/top-menu frames (field_active==0), which render via their own paths. Env forces a fixed
    // mode on all frames (RVK_PILLARBOX=0 disables the portrait even on the field).
    static const char* pbxEnv = std::getenv("RVK_PILLARBOX");
    static int pillarboxEnv = pbxEnv ? std::atoi(pbxEnv) : -1;   // -1 = unset -> auto
    int pillarbox = pillarboxEnv;
    if (pillarbox < 0)
      // Portrait on the live field OR the ROM attract. field_active (0x885C1A20) alone is NOT enough
      // (2026-07-16): the guest never sets it for the ROM's legal/ranking/demo ATTRACT screens, so the
      // attract fell through to the raw landscape present and displayed SIDEWAYS with no borders —
      // while the SDK oracle (RenderDoc path_frame8563/8570/8650/8736) shows the attract as the same
      // upright TATE panel + wallpaper borders as the field. g_rt_romactive (merged_xex.cpp, set on
      // arcade ROM-main sub_88168D48 entry) is the "ROM scene live" signal and is FALSE through the
      // shell front-end, so the title/top-menu keep their clean hook render.
      pillarbox = (g_base && (be32(GA_FIELD_ACTIVE) != 0 || g_rt_romactive != 0)) ? 2 : 0;
    // SETTLE-STATE NOTE (2026-07-15, evidence for the next compose round): at char-select SETTLE
    // the guest STOPS resolving 0xF95D000 (the atlas segment shrinks 116->91->79->53->39 batches,
    // then stops) and instead composes the full screen into the 1280x720 front-buffer composite
    // 0x660000 (frame2978: 49 batches = vs48 sprites + vs5 TATE bg {-640,-512,1280,1024} + vs1 HUD,
    // 908k px). The panel present then shows a stale bg-only atlas (UI missing until the next panel
    // rebuild). A terminal-resolve gate (panel resolved -> portrait, composite-only -> landscape
    // fall-through) was TRIED and REVERTED: active select frames alternate the two resolve classes,
    // so the display flip-flopped layouts; and our landscape composite render of frame2978-class
    // segments shows bg only (the vs48/vs1 UI draws don't land — the old pre-milestone landscape
    // transform class). The SDK reference (round16_charsel/sdk_charselect.png) proves the select
    // screens ARE the portrait panel, so the fix is routing the settle-composite CONTENT into the
    // panel (or reproducing the resolve chain via the SDK oracle), not a layout switch.
    ResolveTex* panelRt = nullptr;
    uint32_t panelBase = 0;
    // PRESENT-PATH-LOTTERY FIX (2026-07-21): the guest's panel double-buffer base alternates per
    // boot (0xF95D000 <-> 0xF96D000); the old hardcoded find(0xF95D000) missed ALL boot when the
    // guest landed on the sibling -> pillarbox/wallpaper never engaged (borders without wallpaper,
    // raw compose showing through). Pick the most recently RENDERED 640x512 target instead
    // (ResolveTex.lastF; ties prefer 0xF95D000 = old behavior). RVK_PANELFIXED=1 reverts.
    static bool panelFixed = [](){ const char* e = std::getenv("RVK_PANELFIXED");
      return e && std::atoi(e) != 0; }();
    if (pillarbox && panelFixed) { auto it = g_resolveTex.find(0xF95D000u);
      if (it != g_resolveTex.end() && it->second.image && it->second.everRendered) { panelRt = &it->second; panelBase = 0xF95D000u; } }
    else if (pillarbox) {
      long bestF = -1;
      for (auto& kv : g_resolveTex) {
        ResolveTex& rt = kv.second;
        if (rt.w != 640 || rt.h != 512 || !rt.image || !rt.everRendered) continue;
        if (rt.lastF > bestF || (rt.lastF == bestF && kv.first == 0xF95D000u)) {
          bestF = rt.lastF; panelRt = &rt; panelBase = kv.first;
        }
      }
    }
    // RVK_PBLOG=1 (present-path lottery probe 2026-07-21): log every pillarbox panel-lookup STATE
    // CHANGE (engage <-> miss) with a census of all 640x512 resolve targets and their everRendered
    // flags. The suspected lottery mechanism: the guest's panel double-buffer base alternates per
    // boot (0xF95D000 <-> 0xF96D000) and the hardcoded find(0xF95D000) misses all boot when the
    // guest lands on the sibling -> pillarbox/wallpaper never engage. Cheap, default off.
    static bool pbLog = std::getenv("RVK_PBLOG") != nullptr;
    if (pbLog && pillarbox) {
      static int pbLast = -1;
      // state = engaged(base) or miss; log on ANY change including a base SWITCH mid-boot
      int pbSt = panelRt ? (int)(panelBase & 0xFFFFF) : 0;
      if (pbSt != pbLast) {
        pbLast = pbSt;
        char eng[32]; std::snprintf(eng, sizeof eng, "ENGAGED@0x%X", panelBase);
        std::fprintf(stderr, "[pblog] f%ld pillarbox=%d panel=%s census:", frame, pillarbox,
          panelRt ? eng : "MISS");
        for (auto& kv : g_resolveTex) if (kv.second.w == 640 && kv.second.h == 512)
          std::fprintf(stderr, " 0x%X(ever=%d)", kv.first, (int)kv.second.everRendered);
        std::fprintf(stderr, "\n");
      }
    }
    if (pillarbox == 1 && panelRt) {
      const int32_t PW = (int32_t)panelRt->w, PH = (int32_t)panelRt->h;   // 640x512 native swap
      const int32_t CX = ((int32_t)kW - PW) / 2, CY = ((int32_t)kH - PH) / 2;  // {320,104}
      segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
      rvkRingNext("pbx"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(pbx)");
      VkCommandBufferBeginInfo cbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; cbi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
      VKC(vkBeginCommandBuffer(g.cmd, &cbi), "begin(pbx)"); if (rvkRingOn()) rvkRingGuard();
      auto pbar = [&](VkImage im, VkImageLayout ol, VkImageLayout nl, VkAccessFlags sa, VkAccessFlags da, VkPipelineStageFlags ss, VkPipelineStageFlags ds) {
        VkImageMemoryBarrier b{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; b.srcQueueFamilyIndex = b.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        b.image = im; b.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1}; b.oldLayout = ol; b.newLayout = nl; b.srcAccessMask = sa; b.dstAccessMask = da;
        vkCmdPipelineBarrier(g.cmd, ss, ds, 0, 0, nullptr, 0, nullptr, 1, &b);
      };
      // UNDEFINED old-layout: we clear the whole image next, so prior contents/layout are irrelevant.
      pbar(g.image, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 0, VK_ACCESS_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT);
      VkClearColorValue bc{}; bc.float32[0] = 0.03f; bc.float32[1] = 0.035f; bc.float32[2] = 0.045f; bc.float32[3] = 1.0f;  // dark neutral border
      VkImageSubresourceRange rng{VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
      vkCmdClearColorImage(g.cmd, g.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, &bc, 1, &rng);
      pbar(panelRt->image, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_ACCESS_SHADER_READ_BIT, VK_ACCESS_TRANSFER_READ_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT);
      VkImageBlit bl{}; bl.srcSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; bl.srcOffsets[1] = {PW, PH, 1};
      bl.dstSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; bl.dstOffsets[0] = {CX, CY, 0}; bl.dstOffsets[1] = {CX + PW, CY + PH, 1};
      vkCmdBlitImage(g.cmd, panelRt->image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, g.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &bl, VK_FILTER_LINEAR);
      pbar(panelRt->image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_ACCESS_TRANSFER_READ_BIT, VK_ACCESS_SHADER_READ_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT);
      // leave g.image in TRANSFER_SRC — copyDisplayToReadback's entry contract (HDR + non-HDR).
      pbar(g.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_ACCESS_TRANSFER_WRITE_BIT, VK_ACCESS_TRANSFER_READ_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT);
      copyDisplayToReadback(g.cmd);   // F6: tonemaps to UNORM8 under RVK_HDR
      VKC(vkEndCommandBuffer(g.cmd), "end(pbx)");
      VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
      VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(pbx)");
      VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(pbx)");
      if (rvkRingOn()) g.ringPending[g.ringIdx] = true; else VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(pbx)");
      if (compDbg) std::fprintf(stderr, "[rvk][pillarbox] frame%ld panel 0xF95D000 %dx%d -> centered {%d,%d}\n", frame, PW, PH, CX, CY);
    }
    // RVK_PILLARBOX>=2 (LEG-50, 2026-07-15 TATE-portrait milestone): present the 640x512 swap ROTATED
    // into the console's native PORTRAIT (TATE) orientation. Round-4 (LEG-49) proved the 0xF95D000
    // buffer is authored for a rotated scanout: presented landscape, the HUD [PLAYER-1 / HIGH score /
    // Maniac Mode] lands as a 90-deg-rotated+MIRRORED strip on the panel's RIGHT edge. A pixel-exact
    // dihedral A/B of the held-field readback against the SDK portrait reference (C:/tmp/dihedral_sheet.png)
    // picked the ANTI-DIAGONAL flip (PIL "TRANSVERSE"): only that transform puts the HUD as a readable,
    // un-mirrored HORIZONTAL strip at the TOP with "PLAYER-1"/"HIGH"/scores/"Maniac Mode" legible, matching
    // milestone_sdk_ref.png. Integer map for output px (ox in [0,OW), oy in [0,OH)): sx=(PW-1)-oy,
    // sy=(PH-1)-ox. vkCmdBlitImage cannot rotate, so we round-trip the swap through host memory: submit A
    // copies the panel image -> host buffer, the CPU applies the transverse transform into a second host
    // buffer, submit B clears the border + copyBufferToImage's the 512x640 portrait centered into g.image.
    // Both g.image and the resolve tex share g_rtFmt, so the byte-copy is format-consistent (bpp 4, or 8
    // under RVK_HDR) and copyDisplayToReadback tonemaps as usual. Env-gated; native 1:1 (no scale/blur).
    else if (pillarbox >= 2 && panelRt) {
      const int32_t PW = (int32_t)panelRt->w, PH = (int32_t)panelRt->h;   // 640x512 landscape swap
      // Displayed extent (2026-07-17 off-centre panel, ORACLE-PROVEN): the guest's own composite
      // quad (RVK_COMPQUAD, vs=47: pos {0,0,640,480}, uv v<=0.9375) samples only 480 of the 512
      // texel rows of the swap, and the SDK-oracle panel measures EXACTLY 720x960@(600,60) in the
      // 1080p rdc thumbs = 480x640 at (400,40) in our 720p = the arcade 240x320 doubled, 1:1
      // pixels. The sampled V axis is FLIPPED vs swap rows (measured: the settled legal text
      // starts at swap row 490 in our capture; the oracle text-left maps to row 485.7 under
      // "displayed rows [32,512)" but 453.7 under "[0,480)") — so the DISPLAYED rows are
      // [32,512) and the padding is rows [0,32) (the old panel's RIGHT-edge band). Narrowing the
      // portrait 512->480 with the original anti-diagonal map drops exactly that padding.
      // RVK_PANELROWS=512 restores the old full-swap blit for A/B.
      static const int32_t dispRows = [](){ const char* e = std::getenv("RVK_PANELROWS"); return e ? (int32_t)std::strtol(e, nullptr, 10) : 480; }();
      const int32_t SH = PH < dispRows ? PH : dispRows;                   // displayed landscape rows
      const int32_t OW = SH, OH = PW;                                     // 480x640 portrait output
      const int32_t CX = ((int32_t)kW - OW) / 2, CY = ((int32_t)kH - OH) / 2;  // {400,40}
      const int bpp = rvk_hdr() ? 8 : 4;
      // ── SHELL OVERLAY range (2026-07-23 SYSTEM-MENU milestone) ──────────────────────────────
      // In-session, the portrait present above rebuilds the frame from the 640x512 GAME panel +
      // wallpaper borders. But the START-summoned SYSTEM MENU (and every shell dialog) is drawn
      // by the SHELL into the 1280x720 FRONT-BUFFER composite resolve, NOT the game panel — so it
      // never reached the presented image (the documented char-select "the vs=48/vs=1 UI draws
      // don't land" failure class, ~40 lines up). The menu draws land in the LAST resolve segment
      // whose target is full-window (kW x kH, e.g. 0x6E2000/0x660000): that segment = the field
      // COMPOSITE (vs=5/47 quads that SAMPLE a resolve — already shown in the panel) + the shell
      // overlay SPRITES (vs=1 shell-atlas, NOT resolve-samplers). Isolate the segment here; the
      // compose pass after submit B draws its non-resolve-sampling sprites on top at native
      // 1280x720 (exactly the geometry the working RVK_PILLARBOX=0 path used). RVK_MENUOVERLAY=0
      // disables (A/B); default on. Verified structure (held menu): resolves [0,252)->0xE94D000
      // 640x512, [252,253)->0x101AD000, [253,272)->0x6E2000 1280x720 = 2 vs=5 field-composite +
      // 17 vs=1 menu sprites (7 bars + description box + navi footer + dim veil).
      static int menuOverlay = [](){ const char* e = std::getenv("RVK_MENUOVERLAY"); return e ? std::atoi(e) : 1; }();
      // Pick the full-window (kW x kH) resolve segment with the MOST overlay (non-resolve-sampling)
      // sprites. A single menu frame can emit the front buffer TWICE at the same batchIdx (a redraw
      // + an empty re-resolve); "last kW x kH" then lands on the empty tail segment and the menu
      // flickers off every other frame. Max-count always lands on the segment that carries the menu.
      size_t ovB0 = 0, ovB1 = 0; int ovN = 0;
      if (menuOverlay) { size_t prev = 0;
        for (auto& r : resolves) {
          if (r.w == kW && r.h == kH) {
            int cnt = 0;
            for (size_t bi = prev; bi < r.batchIdx; ++bi) if (!g_compResolveIdx.count(batches[bi].texIdx)) cnt++;
            if (cnt > ovN) { ovN = cnt; ovB0 = prev; ovB1 = r.batchIdx; }
          }
          prev = r.batchIdx;
        } }
      // GATE on the shell menu actually being on-screen (heartbeat advancing) — otherwise the ROM
      // ATTRACT's ranking UI, which is a non-resolve overlay in the SAME front-buffer segment AND is
      // already shown (rotated) in the panel, would be double-drawn at landscape coords (verified
      // regression). The menu-model wrappers in merged_xex bump g_rt_menu_heartbeat every tick the
      // system menu is visible; a per-present advance means it is live this frame.
      static uint32_t lastMenuHb = 0;
      bool menuLive = (g_rt_menu_heartbeat != lastMenuHb);
      lastMenuHb = g_rt_menu_heartbeat;
      const bool doOverlay = menuOverlay && ovN > 0 && menuLive;
      // RVK_OVLLOG (capped, timing-safe — not behind compDbg): why doOverlay is/ isn't set.
      if (std::getenv("RVK_OVLLOG")) { static long oi = 0; if (oi++ < 5000) {
        std::fprintf(stderr, "[ovllog] f%ld hb=%u resolves=%zu ov=[%zu,%zu) ovN=%d menuLive=%d do=%d |", frame, g_rt_menu_heartbeat, resolves.size(), ovB0, ovB1, ovN, (int)menuLive, (int)doOverlay);
        for (auto& r : resolves) std::fprintf(stderr, " 0x%X(%ux%u@%zu)", r.dst, r.w, r.h, r.batchIdx);
        std::fprintf(stderr, "\n"); } }
      // Lazy host staging buffers (persistently mapped). Sized to the full frame so they never realloc.
      static VkBuffer pbxDown = VK_NULL_HANDLE, pbxUp = VK_NULL_HANDLE;
      static VkDeviceMemory pbxDownMem = VK_NULL_HANDLE, pbxUpMem = VK_NULL_HANDLE;
      static void* pbxDownMap = nullptr; static void* pbxUpMap = nullptr;
      if (!pbxDown) {
        VkDeviceSize sz = (VkDeviceSize)kW * kH * 8;
        // pbxDown is CPU-READ-heavy (the transverse transform reads every pixel): request
        // HOST_CACHED so those reads hit normal cached memory instead of write-combined/uncached
        // (measured: the scattered WC reads made this transform the largest single cost of the
        // attract frame). makeBuffer falls back to plain HOST_VISIBLE if no cached type exists.
        makeBuffer(sz, VK_BUFFER_USAGE_TRANSFER_DST_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT | VK_MEMORY_PROPERTY_HOST_CACHED_BIT, &pbxDown, &pbxDownMem, &pbxDownMap);
        makeBuffer(sz, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &pbxUp,   &pbxUpMem,   &pbxUpMap);
      }
      // RVK_WALLBG (Task A, 2026-07-15): render the guest's field background full-window BEHIND the
      // portrait panel so the pillarbox side-borders show the cave wallpaper + standing-character art
      // (the SDK reference) instead of flat dark. On field frames the guest draws a full-screen bg
      // (vs=5/34 layers sampling the live 0xF005000 framebuffer). Render those into g.image first;
      // submit B then overlays the transverse portrait into the center and SKIPS the border clear so
      // the bg shows in the borders. 0=off (flat border, default), 1=vs5/34 bg layers only, 2=all
      // batches (the full guest frame). Env-gated diagnostic first — flip default only if clean+stable.
      // 0=off (flat border, default), 1=vs5/34 layers, 3=guest cave-wallpaper draw only (see below),
      // 4=blit the STATIC wp*.bin file full-window (the clean, decode-independent path — RECOMMENDED).
      // Default 4 (2026-07-17 attract-1:1): the oracle's attract/field borders are the wp01 Reco
      // wallpaper art; the file-blit path has been stable since 07-15 and is decode-independent.
      // RVK_WALLBG=0 restores the flat border.
      static int wallBg = [](){ const char* e = std::getenv("RVK_WALLBG"); return e ? std::atoi(e) : 4; }();
      VkCommandBufferBeginInfo wcbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; wcbi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
      // RVK_WALLBG=4 (2026-07-15, decomp+asset proof): the whole border decoration (green cave bg +
      // Reco character-art + logo) is ONE baked linear 1280x720 RGBA image, assets/media/wall/wp%02d.bin
      // (128-byte header + W*H*4 body; confirmed by decoding wp01.bin). Load it once → a sampled Tex →
      // blit full-window as the pillarbox border bg. This is the robust fix: WALLBG=3 (replay the guest
      // wallpaper vs=5 draw) rendered BLACK because that quad's 2x-zoom viewport+UVs are calibrated for
      // the guest's OWN composite layout, not our centered-panel pillarbox. TODO(index): wp01 is Reco;
      // the live index is guest state (13 variants) — track the shell's wp load or read the wp-index
      // global (via FindWriters) to pick per-screen; RVK_WALLFILE=<path> overrides for now.
      static Tex g_wallTex{}; static bool wallLoaded = false; static int wallLoadFail = 0;
      // wp-index tracking (2026-07-20): follow the guest's LIVE wallpaper selection — rt.cpp's
      // file-open hook records the last wall/wpNN.bin the shell opened in g_rt_wpindex (13
      // variants ship). Each variant uploads ONCE into a per-index cache (uploadTexToDesc
      // always creates a fresh image, and the previous one may be blit-in-flight — cache
      // instead of destroy; 13 x 3.7MB worst case). Before the first guest load (or if the
      // symbol is absent) fall back to wp01 as before. RVK_WALLFILE still overrides everything
      // (fixed file in slot 0, no tracking). Fail counter resets once per newly-tried index so
      // a missing variant can't wedge future switches or retry every frame.
      // ★ FNF-10 (2026-07-27): the cache is keyed on (wp index, dim quantum), NOT index alone.
      // The dim value is suppressed while the menu is live (`!menuLive` at the wallDimV read), so
      // every menu OPEN and CLOSE flips the quantum 16<->14, and with an index-only key each flip
      // evicted the entry and forced a full 3.6MB fread + swizzle + uploadTexToDesc. Since the old
      // texture can never be destroyed safely (it may be blit-in-flight), each reload permanently
      // burned one descriptor set from a pool of 256 SHARED WITH THE GUEST TEXTURE PATH; on
      // exhaustion vkAllocateDescriptorSets trips VKC -> g.failed -> silent renderer death, which
      // is visually indistinguishable from the FNF-2 device-loss lottery.
      // MEASURED on the ship path (_tmpscripts/save_persist_ab.sh, the drive that walks the OPTION
      // menu): boot 1 reloaded 7x alternating q=14,16,14,16,14,16,14 -- one wallpaper, one index.
      // With the pair keyed separately both quanta coexist and steady state is 2 uploads per index.
      // Bounded: WALLSLOTS entries total, evicted least-recently-used. Eviction still cannot destroy
      // (same in-flight reason), so the leak is CAPPED at WALLSLOTS rather than unbounded.
      // RVK_WALLQKEY=0 restores the old index-only key for A/B.
      static const int WALLSLOTS = 8;
      struct WallSlot { int idx = -1; int q = 0; Tex tex{}; unsigned long lru = 0; };
      static WallSlot wallSlots[WALLSLOTS]{};
      static unsigned long wallLruTick = 0;
      static bool wallQKey = !(std::getenv("RVK_WALLQKEY") && atoi(std::getenv("RVK_WALLQKEY")) == 0);
      auto wallFind = [&](int idx, int q) -> WallSlot* {
        for (auto& s : wallSlots)
          if (s.idx == idx && s.tex.image && (wallQKey ? s.q == q : true)) return &s;
        return nullptr;
      };
      auto wallVictim = [&]() -> WallSlot* {
        WallSlot* v = &wallSlots[0];
        for (auto& s : wallSlots) { if (!s.tex.image) return &s; if (s.lru < v->lru) v = &s; }
        return v;   // NOTE: never vkDestroy — may be blit-in-flight (same rule as before)
      };
      static int wallLoadedIdx = -1, wallTriedIdx = -1;
      // ---- D3 gameplay wallpaper dim (2026-07-23, workflow wf_fa673c1b-395 verdict) ----
      // On hardware the shell dims the side wallpaper by the operator "BG Brightness" setting
      // (SCREEN SETTING, percent, default 0x5A=90) applied as PS const c2 on its wallpaper quad:
      // v = cur(+0x1c) * fade(+0x08) + flash(+0x2c) on the manager singleton [0x821F8574]
      // (draw FUN_82184cc8, const-write FUN_82182150, defaults FUN_82185e80, easing
      // cur += (target-cur)*0.1/frame). The recompiled shell RUNS this manager every frame —
      // only its own quad draw is display-broken here — so we read the guest's eased state
      // per present and apply the SAME factor to the file-blit border. No constants: the
      // measured SDK plateau (~x0.885) is mid-convergence/save-state, deliberately NOT encoded.
      // Fullbright when: manager absent, never armed (target +0x18 == 0), hidden (+0x30 != 0),
      // or the menu overlay is live this present (menus use a separate fullbright bg path).
      // RVK_WALLDIM: unset/1 = live guest read (register-true), 0 = off. RVK_WALLDIMLOG=1 logs.
      auto beF32 = [&](uint32_t a) -> float { uint32_t v = be32(a); float f; std::memcpy(&f, &v, 4); return f; };
      static int wallDimMode = std::getenv("RVK_WALLDIM") ? std::atoi(std::getenv("RVK_WALLDIM")) : 1;
      float wallDimV = 1.0f;
      if (wallDimMode == 1 && g_base) {
        uint32_t mgr = be32(0x821F8574u);
        if (mgr) {
          float tgt = beF32(mgr + 0x18), cur = beF32(mgr + 0x1c), fad = beF32(mgr + 0x08), fls = beF32(mgr + 0x2c);
          uint8_t hid = *(uint8_t*)(g_base + mgr + 0x30);
          if (tgt > 0.f && !hid && !menuLive) {
            float v = cur * fad + fls;
            if (v > 0.f && v < 1.f) wallDimV = v;
          }
          if (std::getenv("RVK_WALLDIMLOG")) { static long wl = 0; if ((wl++ % 60) == 0)
            std::fprintf(stderr, "[walldim] mgr=0x%X tgt=%.3f cur=%.3f fade=%.3f flash=%.3f hid=%u menuLive=%d -> v=%.3f\n",
              mgr, tgt, cur, fad, fls, hid, (int)menuLive, wallDimV); }
        } else if (std::getenv("RVK_WALLDIMLOG")) { static bool o = false; if (!o) { o = true;
          std::fprintf(stderr, "[walldim] manager ptr [0x821F8574] is NULL — dim inactive\n"); } }
      }
      const bool wallFixed = std::getenv("RVK_WALLFILE") != nullptr;
      // RVK_WPFORCE=<n>: pin the wallpaper index (deterministic A/B of the reload/cache path;
      // also a user-facing manual override). Guest tracking wins otherwise.
      static int wpForce = std::getenv("RVK_WPFORCE") ? std::atoi(std::getenv("RVK_WPFORCE")) : 0;
      const int wallWantIdx = wallFixed ? 0
        : (wpForce >= 1 && wpForce < 100) ? wpForce
        : ((&g_rt_wpindex && g_rt_wpindex >= 1 && g_rt_wpindex < 100) ? g_rt_wpindex : 1);
      // D3 dim application (variant A of the wf_fa673c1b-395 verdict): a flat multiply on the
      // source pixels commutes with the linear-filter blit, so pre-dimming the pixels at load
      // is byte-equivalent to the shell's PS-const c2 modulation. The factor (quantized 1/16)
      // is part of the CACHE KEY: a change invalidates the current index and the wallpaper
      // re-loads through the normal file path with the multiply applied in the swizzle loop.
      // NO second upload site exists — two failed attempts (runs 1-2, solid-white present)
      // proved a mid-frame uploadTexToDesc call unsafe: it resets/waits g.fence while the
      // pillarbox ring holds pending submits on it (the load path only survives because it
      // runs before the frame's ring submits on load frames). Fade-in renders as ~14 discrete
      // reload steps; the settled plateau is the acceptance gate.
      static int wallBuiltQ = 1024;               // q is in 1/1024 units now; 1024 = fullbright
      int wallWantQ = 1024;
      // D3 EXACT-DIM (task #14, 2026-07-28): q moved from 1/16 to 1/1024 units. While the eased
      // dim value is MOVING (fade-in), bucket q at the old 1/16 granularity (64/1024 steps) so the
      // fade still costs ~14 reloads, not ~900. Once dimV has been STABLE for 30 presents, want the
      // EXACT factor — one extra reload lands the settled plateau at round(dimV*1024)/1024
      // (error <= 1/2048 vs the old 1/32 = the D3 quantization debt). Cache slots key on the same
      // q, so fade buckets and exact plateaus coexist in the (idx,q) LRU. RVK_WALLDIM16=1 restores
      // the old 1/16-only behavior for A/B.
      if (wallDimV < 0.999f) {
        static bool wallQ16 = std::getenv("RVK_WALLDIM16") && atoi(std::getenv("RVK_WALLDIM16")) != 0;
        static float dimPrev = -1.f; static int dimStableN = 0;
        if (std::fabs(wallDimV - dimPrev) < 0.0005f) { if (dimStableN < 1000) dimStableN++; }
        else dimStableN = 0;
        dimPrev = wallDimV;
        if (!wallQ16 && dimStableN >= 30) wallWantQ = (int)std::lround(wallDimV * 1024.f);
        else wallWantQ = (int)std::lround(wallDimV * 16.f) * 64;
        if (wallWantQ < 64) wallWantQ = 64; if (wallWantQ > 1008) wallWantQ = 1008;
      }
      // FNF-10: one lookup on (idx, q) replaces the old evict-on-quantum-change dance. A hit is
      // free (no file IO, no upload, no descriptor); a miss falls through to the load path below.
      if (wallLoadedIdx != wallWantIdx || wallBuiltQ != wallWantQ) {
        if (WallSlot* hit = wallFind(wallWantIdx, wallWantQ)) {
          g_wallTex = hit->tex; hit->lru = ++wallLruTick;
          wallLoaded = true; wallBuiltQ = hit->q; wallLoadedIdx = wallWantIdx;
          static long cacheHits = 0;
          if (cacheHits++ < 8)
            std::fprintf(stderr, "[rvk][wallfile] wp %02d q=%d/1024 (cached, hit#%ld)\n", wallWantIdx, hit->q, cacheHits);
        } else {
          wallLoaded = false;
          if (wallTriedIdx != wallWantIdx) { wallLoadFail = 0; wallTriedIdx = wallWantIdx;
            if (wallLoadedIdx >= 0) std::fprintf(stderr, "[rvk][wallfile] wp index %02d -> %02d (guest switch)\n", wallLoadedIdx, wallWantIdx); }
        }
      }
      if ((wallBg == 4 || wallBg == 5) && !wallLoaded && wallLoadFail < 3) {
        char path[512];
        const char* wfEnv = std::getenv("RVK_WALLFILE");
        if (wfEnv) std::snprintf(path, sizeof path, "%s", wfEnv);
        else { const char* root = std::getenv("RT_GAME_ROOT") ? std::getenv("RT_GAME_ROOT") : "assets";
               std::snprintf(path, sizeof path, "%s/media/wall/wp%02d.bin", root, wallWantIdx); }
        const uint32_t WW = 1280, WH = 720; const size_t need = (size_t)WW * WH * 4;
        FILE* wf = std::fopen(path, "rb");
        if (wf) {
          std::fseek(wf, 0, SEEK_END); long sz = std::ftell(wf);
          if (sz >= (long)need) { std::fseek(wf, sz - (long)need, SEEK_SET);   // skip the header
            // ★ 2026-07-27 transition-spike fix: fread used to land IN g.stagingMap and the
            // swizzle below did read-modify-write ON the write-combined mapping — ~2.7M uncached
            // reads = the measured 250-265ms wallpaper (re)load frames (every dim-fade quantum
            // step pays one). Same class as the banked pbxA lesson ("before blaming the GPU,
            // check for CPU reads of mapped Vulkan memory"). Read into heap; staging gets only
            // sequential WRITES.
            static std::vector<uint8_t> wallFileBuf;
            wallFileBuf.resize(need);
            size_t got = std::fread(wallFileBuf.data(), 1, need, wf);
            // The wp*.bin body is BGRX, not RGBA (2026-07-16, RenderDoc-oracle cross-check): decoding
            // wp01 and comparing per-channel means against the oracle's BORDER pixels (field capture
            // futari_frame69722) matches only under B,G,R,X — file c0=104.4 vs oracle B=95.8,
            // c1=118.9 vs G=111.2, c2=52.2 vs R=56.2 — and swapping R<->B on our own WALLBG=4 output
            // halves the border error vs the oracle (124.4 -> 61.1). The 4th byte is 0 for EVERY texel
            // (it is padding, NOT alpha). uploadTexToDesc creates R8G8B8A8_UNORM and is shared with the
            // guest-texture path, so swizzle here instead of widening it: B<->R, and force A=0xFF so the
            // border is opaque regardless of what the display path does with alpha.
            if (got == need) { const uint8_t* src = wallFileBuf.data(); uint8_t* wp = (uint8_t*)g.stagingMap;
              // BGRX->RGBA swizzle + D3 dim multiply in one pass (lut = identity at q=1024).
              uint8_t lut[256]; const float m = (float)wallWantQ / 1024.f;
              for (int i = 0; i < 256; i++) lut[i] = (uint8_t)std::lround(i * m);
              for (size_t i = 0; i < need; i += 4) { wp[i] = lut[src[i + 2]]; wp[i + 1] = lut[src[i + 1]]; wp[i + 2] = lut[src[i]]; wp[i + 3] = 0xFF; } }
            WallSlot* slot = wallVictim();
            if (got == need && uploadTexToDesc(WW, WH, slot->tex)) { wallLoaded = true;
              slot->idx = wallWantIdx; slot->q = wallWantQ; slot->lru = ++wallLruTick;
              g_wallTex = slot->tex; wallLoadedIdx = wallWantIdx; wallBuiltQ = wallWantQ;
              std::fprintf(stderr, "[rvk][wallfile] loaded %s %ux%u hdr=%ld (BGRX->RGBA swizzled, dim q=%d/1024)\n", path, WW, WH, sz - (long)need, wallWantQ); }
            else { wallLoadFail++; std::fprintf(stderr, "[rvk][wallfile] read/upload FAILED %s\n", path); }
          } else { wallLoadFail++; std::fprintf(stderr, "[rvk][wallfile] %s too small %ld<%zu\n", path, sz, need); }
          std::fclose(wf);
        } else { wallLoadFail++; std::fprintf(stderr, "[rvk][wallfile] cannot open %s\n", path); }
      }
      bool wallReady = false;
      if (wallBg && wallBg != 4) {
        segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
        rvkRingNext("pbxW"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(pbxW)");
        VKC(vkBeginCommandBuffer(g.cmd, &wcbi), "begin(pbxW)"); if (rvkRingOn()) rvkRingGuard();
        VkClearValue wclr{}; wclr.color.float32[0] = 0.03f; wclr.color.float32[1] = 0.035f; wclr.color.float32[2] = 0.045f; wclr.color.float32[3] = 1.0f;
        VkRenderPassBeginInfo rpb{VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO}; rpb.renderPass = g.pass; rpb.framebuffer = g.fb; rpb.renderArea = {{0, 0}, {kW, kH}}; rpb.clearValueCount = 1; rpb.pClearValues = &wclr;
        vkCmdBeginRenderPass(g.cmd, &rpb, VK_SUBPASS_CONTENTS_INLINE);
        vkCmdBindDescriptorSets(g.cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, g.rPlLayout, 0, 4, g.rSets, 0, nullptr);
        VkDeviceSize wvoff = 0; vkCmdBindVertexBuffers(g.cmd, 0, 1, &g.vbuf, &wvoff);
        vkCmdBindIndexBuffer(g.cmd, g.ibuf, 0, VK_INDEX_TYPE_UINT32);
        VkPipeline lastPipe = VK_NULL_HANDLE; VkViewport lastVp{}; bool vpSet = false; int wdrawn = 0;
        for (size_t bi2 = 0; bi2 < batches.size(); ++bi2) {
          auto& b = batches[bi2];
          if (wallBg == 1 && b.vsIdx != 5 && b.vsIdx != 34) continue;   // bg layers only
          // RVK_WALLBG=3 (2026-07-15, RenderDoc-oracle-guided border fix): render ONLY the full-screen
          // 2x-zoom cave WALLPAPER bg behind the portrait panel. RINGDUMP of a held field frame
          // (RVK_COMPDBG) proved the discriminator: the true wallpaper is a vs=5 quad at the deep-
          // negative 2x-zoom viewport vp={-1280,-720,2560,1440} sampling a PLAIN texture (bi=0 tex=10),
          // but the vs=5 playfield-COMPOSITE draws (bi=4/5) share that SAME viewport while SAMPLING a
          // RESOLVED surface (tex is a resolve index) — so the old `vp.x <= -512` gate alone let them
          // through and duplicated the playfield in the borders ("catches wrong layer"). Exclude the
          // resolve-samplers via g_compResolveIdx; vs=48/vs=1 sprites (vp.x=0) stay excluded by the vp
          // gate. Net: borders get just the cave decoration, center is the clean portrait panel.
          if (wallBg == 3 && (b.vp.x > -512.0f || g_compResolveIdx.count(b.texIdx))) continue;   // true cave wallpaper only
          if (b.pipeline != lastPipe) { vkCmdBindPipeline(g.cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, b.pipeline); lastPipe = b.pipeline; }
          if (!vpSet || std::memcmp(&b.vp, &lastVp, sizeof lastVp) != 0) { vkCmdSetViewport(g.cmd, 0, 1, &b.vp); lastVp = b.vp; vpSet = true; }
          vkCmdSetBlendConstants(g.cmd, b.bc);   // dynamic state: guest RB_BLEND_RED..ALPHA per batch
        struct { uint64_t vs, ps, shared; float ndc[4]; } pc{b.vsBDA, b.psBDA, b.sharedBDA, {1.f, 1.f, 0.f, 0.f}};
          if (rvkTrue48(b)) {
            pc.ndc[0] = 2.f / (float)kW; pc.ndc[1] = -2.f / (float)kH;
            pc.ndc[2] = -1.f + 1.f / (float)kW; pc.ndc[3] = 1.f - 1.f / (float)kH;
            VkViewport tvp{0.f, 0.f, (float)kW, (float)kH, 0.f, 1.f};
            vkCmdSetViewport(g.cmd, 0, 1, &tvp); lastVp = tvp;
          }
          vkCmdPushConstants(g.cmd, g.rPlLayout, VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT, 0, sizeof(pc), &pc);
          vkCmdDrawIndexed(g.cmd, b.indexCount, 1, b.firstIndex, 0, 0);
          wdrawn++;
        }
        vkCmdEndRenderPass(g.cmd);   // g.image -> TRANSFER_SRC (renderpass final layout)
        VKC(vkEndCommandBuffer(g.cmd), "end(pbxW)");
        VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
        VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(pbxW)");
        VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(pbxW)");
        if (rvkRingOn()) g.ringPending[g.ringIdx] = true; else VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(pbxW)");
        if (compDbg) std::fprintf(stderr, "[rvk][wallbg] frame%ld mode=%d drew %d/%zu batches full-window (bg behind portrait)\n", frame, wallBg, wdrawn, batches.size());
        wallReady = true;
      } else if ((wallBg == 4 && wallLoaded) || wallBg == 5) {
        // Blit the wallpaper full-window into g.image (our own clean geometry). Leaves
        // g.image in TRANSFER_SRC so the shared "wallReady" submit-B path copies the portrait on top.
        // RVK_WALLBG=5 (2026-07-19, stride-sweep follow-up) — REFUTED for borders, kept as an
        // A/B lever: sources the border bg from the guest texture at RVK_WALLBASE (default
        // 0xF005000). The A/B showed 0xF005000 is the guest's LIVE LANDSCAPE COMPOSE FRAMEBUFFER
        // (borders render a rotated copy of the game frame incl. HUD), NOT the static wallpaper —
        // the stride-16 full-screen rect sampling it is the guest's frame-base RESTORE draw
        // (previous composed frame repainted, then content over it = the register-true
        // counterpart of RVK_PERSIST). The wallpaper-under source stays the wp*.bin file (mode 4);
        // the wp-index TODO needs the shell's wp-load tracking, not this base.
        VkImage wsrc = VK_NULL_HANDLE; const char* wsrcTag = "file";
        if (wallBg == 5) {
          static uint32_t wallBase = [](){ const char* e = std::getenv("RVK_WALLBASE");
            return e ? (uint32_t)std::strtoul(e, nullptr, 0) : 0xF005000u; }();
          for (auto& kv : g.rTexIndex)
            if ((uint32_t)(kv.first >> 8) == wallBase && kv.second < g.rTexRecords.size()) {
              wsrc = g.rTexRecords[kv.second].image; wsrcTag = "guest"; break;
            }
          if (!wsrc && wallLoaded) wsrc = g_wallTex.image;
        } else wsrc = g_wallTex.image;
        if (wsrc) {
        segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
        rvkRingNext("pbxWf"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(pbxWf)");
        VKC(vkBeginCommandBuffer(g.cmd, &wcbi), "begin(pbxWf)"); if (rvkRingOn()) rvkRingGuard();
        auto wbar = [&](VkImage im, VkImageLayout ol, VkImageLayout nl, VkAccessFlags sa, VkAccessFlags da) {
          VkImageMemoryBarrier b{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; b.srcQueueFamilyIndex = b.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
          b.image = im; b.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1}; b.oldLayout = ol; b.newLayout = nl; b.srcAccessMask = sa; b.dstAccessMask = da;
          vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, 0, 0, nullptr, 0, nullptr, 1, &b); };
        wbar(wsrc, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_ACCESS_SHADER_READ_BIT, VK_ACCESS_TRANSFER_READ_BIT);
        wbar(g.image, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 0, VK_ACCESS_TRANSFER_WRITE_BIT);
        VkImageBlit wbl{}; wbl.srcSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; wbl.srcOffsets[1] = {1280, 720, 1};
        wbl.dstSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; wbl.dstOffsets[1] = {(int32_t)kW, (int32_t)kH, 1};
        vkCmdBlitImage(g.cmd, wsrc, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, g.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &wbl, VK_FILTER_LINEAR);
        wbar(g.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_ACCESS_TRANSFER_WRITE_BIT, VK_ACCESS_TRANSFER_READ_BIT);
        wbar(wsrc, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_ACCESS_TRANSFER_READ_BIT, VK_ACCESS_SHADER_READ_BIT);
        VKC(vkEndCommandBuffer(g.cmd), "end(pbxWf)");
        VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
        VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(pbxWf)");
        VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(pbxWf)");
        if (rvkRingOn()) g.ringPending[g.ringIdx] = true; else VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(pbxWf)");
        wallReady = true;
        if (compDbg) std::fprintf(stderr, "[rvk][wallfile] frame%ld blitted wallpaper (%s) 1280x720 -> full window\n", frame, wsrcTag);
        }
      }
      auto pbar = [&](VkImage im, VkImageLayout ol, VkImageLayout nl, VkAccessFlags sa, VkAccessFlags da, VkPipelineStageFlags ss, VkPipelineStageFlags ds) {
        VkImageMemoryBarrier b{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; b.srcQueueFamilyIndex = b.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        b.image = im; b.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1}; b.oldLayout = ol; b.newLayout = nl; b.srcAccessMask = sa; b.dstAccessMask = da;
        vkCmdPipelineBarrier(g.cmd, ss, ds, 0, 0, nullptr, 0, nullptr, 1, &b);
      };
      // --- submit A: copy the panel swap image -> host download buffer ---
      segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
      rvkRingNext("pbxA"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(pbxA)");
      VkCommandBufferBeginInfo cbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; cbi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
      VKC(vkBeginCommandBuffer(g.cmd, &cbi), "begin(pbxA)"); if (rvkRingOn()) rvkRingGuard();
      pbar(panelRt->image, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_ACCESS_SHADER_READ_BIT, VK_ACCESS_TRANSFER_READ_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT);
      VkBufferImageCopy dcp{}; dcp.imageSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; dcp.imageExtent = {(uint32_t)PW, (uint32_t)PH, 1};
      vkCmdCopyImageToBuffer(g.cmd, panelRt->image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, pbxDown, 1, &dcp);
      pbar(panelRt->image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_ACCESS_TRANSFER_READ_BIT, VK_ACCESS_SHADER_READ_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT);
      VKC(vkEndCommandBuffer(g.cmd), "end(pbxA)");
      { VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
        VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(pbxA)");
        VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(pbxA)");
        // pbxA is a READBACK whose consumer is the CPU transform immediately below — it must stay
        // synchronous. (The cmd-ring conversion briefly deferred this wait, which let the CPU read
        // pbxDownMap before the GPU copy finished.)
        VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(pbxA)"); }
      // --- CPU: transverse (anti-diagonal) transform  down(640x512) -> up(512x640) ---
      // RVK_PANELDUMP=<frame>: one-shot — write the raw landscape panel swap (pbxDown, post-GPU-copy)
      // to /c/tmp/paneldump_f<N>.png for direct texel comparison against the SDK-oracle resolve
      // (oracle_tex extraction). No crop/rotation — the pure seg-render output.
      {
        static long panelDumpAt = std::getenv("RVK_PANELDUMP") ? std::strtol(std::getenv("RVK_PANELDUMP"), nullptr, 10) : -1;
        // RVK_PANELDUMP_EVERY=<n> (2026-07-18 round 2): after the first dump, keep dumping every
        // n frames (max 12 files) so a box-bearing demo frame can be caught and matched to the
        // same-frame RVK_BOXDBG2 batch census. Default 0 = original one-shot behavior.
        static long panelDumpEvery = std::getenv("RVK_PANELDUMP_EVERY") ? std::strtol(std::getenv("RVK_PANELDUMP_EVERY"), nullptr, 10) : 0;
        static long panelDumpN = 0; static long panelDumpNext = -1;
        if (panelDumpNext < 0 && panelDumpAt >= 0) panelDumpNext = panelDumpAt;
        if (panelDumpNext >= 0 && panelDumpN < 12 && frame >= panelDumpNext) {
          ++panelDumpN;
          panelDumpNext = panelDumpEvery > 0 ? frame + panelDumpEvery : -1;
          char pd[96]; std::snprintf(pd, sizeof pd, "/tmp/paneldump_f%ld.png", frame);
          writePngSync(pd, (const uint8_t*)pbxDownMap, PW, PH);
          std::fprintf(stderr, "[paneldump] frame%ld wrote %s (%dx%d landscape swap)\n", frame, pd, PW, PH);
        }
      }
      // Blocked (64x64-tile) rotation: the naive row loop strides PW*bpp through the source on
      // every inner step (one cache line per pixel, ~330K misses/frame); tiling reuses each
      // fetched source line ~16x. Byte-identical output, order-only change.
      { const uint8_t* s = (const uint8_t*)pbxDownMap; uint8_t* d = (uint8_t*)pbxUpMap;
        const int32_t T = 64;
        for (int32_t ty = 0; ty < OH; ty += T)
          for (int32_t tx = 0; tx < OW; tx += T)
            for (int32_t oy = ty, ye = ty + T < OH ? ty + T : OH; oy < ye; ++oy) { const int32_t sx = (PW - 1) - oy;
              // sy over [PH-SH, PH): the displayed rows (V-flipped sampling — see block comment).
              // ox in [0,OW=SH) with the ORIGINAL (PH-1)-ox map lands exactly there, dropping the
              // padding rows [0, PH-SH) that used to show as the panel's right-edge band.
              // RVK_TRUE48: the register-true seg render restores the HW resolve orientation
              // (our old resolve was mirrored by the compensating repair stack) — the reading
              // axis maps STRAIGHT (sy = ox) and the displayed rows become the true [0,480).
              for (int32_t ox = tx, xe = tx + T < OW ? tx + T : OW; ox < xe; ++ox) { const int32_t sy = rvkTrue48On() ? ox : (PH - 1) - ox;
                std::memcpy(d + ((size_t)oy * OW + ox) * bpp, s + ((size_t)sy * PW + sx) * bpp, bpp); } } }
      // --- submit B: clear border + upload portrait centered into g.image -> readback ---
      segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
      rvkRingNext("pbxB"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(pbxB)");
      VKC(vkBeginCommandBuffer(g.cmd, &cbi), "begin(pbxB)"); if (rvkRingOn()) rvkRingGuard();
      if (wallReady) {
        // g.image already holds the wallpaper (TRANSFER_SRC from the pbxW/blit pass): PRESERVE it, only
        // transition to TRANSFER_DST so the portrait copy lands on top (borders keep the wallpaper).
        pbar(g.image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_ACCESS_TRANSFER_READ_BIT, VK_ACCESS_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT);
      } else {
        pbar(g.image, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 0, VK_ACCESS_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT);
        VkClearColorValue bc{}; bc.float32[0] = 0.03f; bc.float32[1] = 0.035f; bc.float32[2] = 0.045f; bc.float32[3] = 1.0f;  // dark neutral border
        VkImageSubresourceRange rng{VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
        vkCmdClearColorImage(g.cmd, g.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, &bc, 1, &rng);
        // order the border clear before the portrait copy (WAW on g.image, both transfer writes).
        pbar(g.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_ACCESS_TRANSFER_WRITE_BIT, VK_ACCESS_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT);
      }
      VkBufferImageCopy ucp{}; ucp.imageSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; ucp.imageOffset = {CX, CY, 0}; ucp.imageExtent = {(uint32_t)OW, (uint32_t)OH, 1};
      vkCmdCopyBufferToImage(g.cmd, pbxUp, g.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &ucp);
      // leave g.image in TRANSFER_SRC — copyDisplayToReadback's entry contract (HDR + non-HDR),
      // AND passLoad's declared initialLayout for the overlay pass below.
      pbar(g.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_ACCESS_TRANSFER_WRITE_BIT, VK_ACCESS_TRANSFER_READ_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT);
      // Skip the readback here when the overlay pass will run — it draws on the FLOAT g.image and
      // does the final (tonemapped) readback itself. Otherwise readback the portrait as before.
      if (!doOverlay) copyDisplayToReadback(g.cmd);   // F6: tonemaps to UNORM8 under RVK_HDR
      VKC(vkEndCommandBuffer(g.cmd), "end(pbxB)");
      { VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
        VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(pbxB)");
        VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(pbxB)");
        if (rvkRingOn()) g.ringPending[g.ringIdx] = true; else VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(pbxB)"); }
      if (compDbg) std::fprintf(stderr, "[rvk][pillarbox] frame%ld TATE-portrait %dx%d -> centered {%d,%d}\n", frame, OW, OH, CX, CY);
      // ── submit O: draw the shell overlay sprites over the composed portrait ──────────────────
      // g.image is TRANSFER_SRC (submit B) = g.passLoad initialLayout. LOAD it, draw the overlay
      // range's non-resolve-sampling sprites at native 1280x720 (rvkTrue48 is the vs=48 + FIX-A
      // vs=45/47 px-class only, so vs=1 menu sprites keep their authored {0,0,1280,720}
      // viewport), leave TRANSFER_SRC, readback.
      if (doOverlay) {
        segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
        rvkRingNext("pbxO"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(pbxO)");
        VKC(vkBeginCommandBuffer(g.cmd, &cbi), "begin(pbxO)"); if (rvkRingOn()) rvkRingGuard();
        VkRenderPassBeginInfo rpb{VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO}; rpb.renderPass = g.passLoad; rpb.framebuffer = g.fb; rpb.renderArea = {{0, 0}, {kW, kH}}; rpb.clearValueCount = 0; rpb.pClearValues = nullptr;
        vkCmdBeginRenderPass(g.cmd, &rpb, VK_SUBPASS_CONTENTS_INLINE);
        vkCmdBindDescriptorSets(g.cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, g.rPlLayout, 0, 4, g.rSets, 0, nullptr);
        VkDeviceSize ovoff = 0; vkCmdBindVertexBuffers(g.cmd, 0, 1, &g.vbuf, &ovoff);
        vkCmdBindIndexBuffer(g.cmd, g.ibuf, 0, VK_INDEX_TYPE_UINT32);
        VkPipeline lastPipe = VK_NULL_HANDLE; VkViewport lastVp{}; bool vpSet = false; int drew = 0;
        for (size_t bi = ovB0; bi < ovB1; ++bi) {
          auto& b = batches[bi];
          if (g_compResolveIdx.count(b.texIdx)) continue;   // skip field composite/feedback (already in panel)
          if (b.pipeline != lastPipe) { vkCmdBindPipeline(g.cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, b.pipeline); lastPipe = b.pipeline; }
          if (!vpSet || std::memcmp(&b.vp, &lastVp, sizeof lastVp) != 0) { vkCmdSetViewport(g.cmd, 0, 1, &b.vp); lastVp = b.vp; vpSet = true; }
          vkCmdSetBlendConstants(g.cmd, b.bc);
          struct { uint64_t vs, ps, shared; float ndc[4]; } pc{b.vsBDA, b.psBDA, b.sharedBDA, {1.f, 1.f, 0.f, 0.f}};
          if (rvkTrue48(b)) {
            pc.ndc[0] = 2.f / (float)kW; pc.ndc[1] = -2.f / (float)kH;
            pc.ndc[2] = -1.f + 1.f / (float)kW; pc.ndc[3] = 1.f - 1.f / (float)kH;
            VkViewport tvp{0.f, 0.f, (float)kW, (float)kH, 0.f, 1.f};
            vkCmdSetViewport(g.cmd, 0, 1, &tvp); lastVp = tvp;
          }
          vkCmdPushConstants(g.cmd, g.rPlLayout, VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT, 0, sizeof(pc), &pc);
          // RVK_OVBATCHLOG (D1-B strip identification, 2026-07-24): pure instrumentation — dump each
          // drawn overlay batch's guest atlas (texBase/fmt), vs class, viewport, and its first vertex
          // (raw dwords + float x/y) so the 加速×1 strip batch can be matched to the guest container.
          static bool ovBatchLog = std::getenv("RVK_OVBATCHLOG") != nullptr;
          if (ovBatchLog) { static long ol=0; if (ol++ < 4000) {
            const uint32_t* Ir = (const uint32_t*)g.ibufMap; const uint32_t* Vr = (const uint32_t*)g.vbufMap;
            uint32_t fv = Ir[b.firstIndex]; float vx, vy; std::memcpy(&vx,&Vr[fv*6+0],4); std::memcpy(&vy,&Vr[fv*6+1],4);
            std::fprintf(stderr, "[ovbatch] f%ld bi=%zu texBase=0x%X fmt=0x%X texIdx=%u vsIdx=%d blend=0x%X vp={%.0f,%.0f,%.0f,%.0f} idx=%u cnt=%u v0=(%.1f,%.1f) dw[%08X %08X %08X %08X]\n",
              frame, bi, b.texBase, b.texFmt, b.texIdx, b.vsIdx, b.blendReg, b.vp.x,b.vp.y,b.vp.width,b.vp.height, b.firstIndex, b.indexCount, vx,vy,
              Vr[fv*6+0],Vr[fv*6+1],Vr[fv*6+2],Vr[fv*6+3]); } }
          vkCmdDrawIndexed(g.cmd, b.indexCount, 1, b.firstIndex, 0, 0);
          drew++;
        }
        vkCmdEndRenderPass(g.cmd);   // g.image -> TRANSFER_SRC (passLoad finalLayout)
        copyDisplayToReadback(g.cmd);   // F6: tonemaps to UNORM8 under RVK_HDR
        VKC(vkEndCommandBuffer(g.cmd), "end(pbxO)");
        VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
        VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(pbxO)");
        VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(pbxO)");
        if (rvkRingOn()) g.ringPending[g.ringIdx] = true; else VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(pbxO)");
        if (compDbg) std::fprintf(stderr, "[rvk][menuovl] frame%ld drew %d/%d overlay sprites [%zu,%zu) over portrait\n", frame, drew, ovN, ovB0, ovB1);
      }
    }
    // RVK_DISPLAYALL (2026-07-14, terrain-render RE): render the WHOLE frame's batch list in guest
    // order [0, N) into the display, bypassing resolve segmentation and the stale vs=47 self-
    // composite entirely. Ground truth: the live terrain tiles (vs=48 0x120F7000) render correctly
    // but the COMPSEG display shows only the composite segment (stale washed 0xEEAD000). This shows
    // the frame exactly as the guest drew it (composite BG + all terrain tiles + sprites + HUD).
    // NOTE: value-checked (not just presence) so RVK_DISPLAYALL=0 actually DISABLES it — the
    // on-window scripts export RVK_DISPLAYALL=1 by default, and the composite (COMPSEG) A/B needs
    // to turn it off. A bare `!= nullptr` made "=0" still enable the full-frame path (spec edit 5).
    static bool displayAll = [](){ const char* e = std::getenv("RVK_DISPLAYALL"); return e && std::atoi(e) != 0; }();
    if (pillarbox && panelRt) { /* RVK_PILLARBOX already produced the display above */ }
    else if (displayAll) {
      submitSeg(0, batches.size(), true);
      if (compDbg) std::fprintf(stderr, "[rvk][compdbg] frame%ld READBACK=DISPLAYALL[0,%zu)\n", frame, batches.size());
    }
    else if (compB0 >= 0) {
      // RVK_COMPSEG: display = the composite segment (panel quad sampling the resolved
      // playfield) + the final overlay segment drawn on top, in one cleared pass.
      submitSeg((size_t)compB0, (size_t)compB1, true, b0, batches.size());
      if (compDbg) std::fprintf(stderr, "[rvk][compdbg] frame%ld READBACK=COMPSEG[%ld,%ld)+final[%zu,%zu)\n",
        frame, compB0, compB1, b0, batches.size());
    }
    // ★★ C4 CANONICAL COMPOSE (campaign, 2026-07-28; C3-s1 verdict 69faa59): on SHELL frames the
    // final-composite fork (lastRt empty-final vs normal-composite) alternated PER FRAME on the
    // f776 trailing-batch lottery — two slightly different pixel paths at frame rate = the
    // shimmer the user has reported since 07-26. Canonical register-true model (the code's own
    // EDRAM comments, now enforced as ONE path): the segment loop above already rendered [0,b0)
    // onto the persistent offscreen with resolves at stream positions; the final region is
    // ALWAYS submitSeg(b0, N, readback, LOAD) — for an empty final (b0==N) that is exactly the
    // old lastRt shell arm; for trailing batches it is exactly the old normal shell arm. The
    // segsElsewhere re-render-all arm is retired on shell (its own comment documents the alpha
    // overdraw bug; an empty final over FIXB2 layers now shows the persisted compose = correct
    // re-present semantics). Field/ROM frames keep the historic fork bit-for-bit.
    // RVK_NOCANON=1 reverts to the fork. RVK_CBRANCH=1 logs per-frame branch + transitions.
    else {
      static bool noShellPersistC = [](){ const char* e = std::getenv("RVK_NOSHELLPERSIST");
        return e && std::atoi(e) != 0; }();
      static bool preRomWinC = [](){ const char* e = std::getenv("RVK_PREROMWIN");
        return e ? std::atoi(e) != 0 : true; }();
      static bool noCanon = [](){ const char* e = std::getenv("RVK_NOCANON");
        return e && std::atoi(e) != 0; }();
      static bool cbLog = std::getenv("RVK_CBRANCH") != nullptr;
      bool shellFrameC = !noShellPersistC && preRomWinC && g_base
                         && be32(GA_FIELD_ACTIVE) == 0 && g_rt_romactive == 0;
      char br;
      if (shellFrameC && !noCanon) {
        br = 'C';
        submitSeg(b0, batches.size(), true, 0, 0, 1);   // THE canonical shell output path
      }
      else if (lastRt) {
      br = 'L';
      // LEGACY-TITLE-BLINK FIX (2026-07-21): an empty FINAL segment with resolves used to present
      // the resolve TEXTURE as the frame (readbackResolveTex) — correct only when that resolve
      // really is the front-buffer composite. The legacy title disproved it: its press-start
      // cadence is a 40-window cycle (19x full-redraw nb=4, 1x nb=5, 20x nb=1) where the nb=1
      // windows draw ONLY the copyright glyphs (idx 48-54, font tex) and resolve them to
      // 0x660000 — a texture BUILD, not a display swap. Presenting that pass showed
      // glyphs-on-clear = the ~0.33s title blink (aliased to ~2.5s by the 0.5s A/B sampler).
      // Register-true model: EDRAM persists across windows — the window's draws land on the
      // persistent back buffer AND resolve out. So render this window's batches over the
      // persistent display (forced LOAD; segment loop above already updated the resolve tex)
      // and present that. RVK_LASTRTPRESENT=1 restores the old present-the-resolve behavior.
      static bool lastRtPresent = [](){ const char* e = std::getenv("RVK_LASTRTPRESENT");
        return e && std::atoi(e) != 0; }();
      if (lastRtPresent) readbackResolveTex(*lastRt);
      // Overdraw fix (2026-07-21, oracle: steady title, only press-start text blinks): when every
      // non-empty segment went through the OLD path, the offscreen already holds this window's
      // draws — present it AS-IS (empty LOAD pass + readback). Re-drawing [0,N) on top alpha-
      // accumulated the title's glyph passes ~20x per blink phase (text-brightness pulse).
      else if (!segsElsewhere) submitSeg(batches.size(), batches.size(), true, 0, 0, 1);
      else submitSeg(0, batches.size(), true, 0, 0, 1);
      }
      else {
        br = 'N';
      // normal: final segment = composite -> readback.
      // ★ LEGACY-TITLE-BLINK FIX part 3 / RVK_PREROMWIN (2026-07-26). Part 2 (2026-07-21, ~line
      // 5831) forced LOAD for the LAYER segments on shell frames because hardware EDRAM holds the
      // previous content through a partial pass; this terminal branch was left CLEARING, and it is
      // the branch that runs whenever the window carries batches AFTER its last resolve. Under the
      // pre-ROM kick-capture window that happens whenever ONE draw of the next guest frame lands
      // after this frame's resolve: measured 2026-07-26 (RVK_COMPDBG, `abA_compdbg`) as
      //   f775 batches[0,6)+resolve            -> lastRt path, correct frame
      //   f776 batches[0,6)+resolve + seg[6,7) -> HERE, and a single full-screen quad rendered on a
      //                                           clear became the entire frame (uniform (0,0,25),
      //                                           luma mean exactly 8.33, menu/title gone).
      // That is what produced the "per-boot lottery" the 07-25 A/B saw on the version-select page —
      // it is per-WINDOW, not per-boot, and it hits the TITLE too. Rendering the trailing batches
      // over the persistent offscreen instead of over a clear is the same register-true EDRAM model
      // part 2 already ships. Scoped to shell frames (field flag clear AND ROM not live), so every
      // post-ROM frame keeps the historic CLEAR bit-for-bit. RVK_NOSHELLPERSIST=1 or
      // RVK_PREROMWIN=0 reverts.
      static bool noShellPersistD = [](){ const char* e = std::getenv("RVK_NOSHELLPERSIST");
        return e && std::atoi(e) != 0; }();
      static bool preRomWinD = [](){ const char* e = std::getenv("RVK_PREROMWIN");
        return e ? std::atoi(e) != 0 : true; }();
      bool shellFrameD = !noShellPersistD && preRomWinD && g_base
                         && be32(GA_FIELD_ACTIVE) == 0 && g_rt_romactive == 0;
      submitSeg(b0, batches.size(), true, 0, 0, shellFrameD ? 1 : -1);
      }
      if (cbLog) {   // ★ C4 branch census: per-frame letter + transition count
        static char lastBr = 0; static long trans = 0, cbn = 0; static long cnt3[3] = {0,0,0};
        int bi3 = br == 'C' ? 0 : br == 'L' ? 1 : 2;
        cnt3[bi3]++;
        if (lastBr && br != lastBr) trans++;
        lastBr = br;
        if ((++cbn % 120) == 0)
          std::fprintf(stderr, "[cbranch] f%ld C=%ld L=%ld N=%ld transitions=%ld\n", frame, cnt3[0], cnt3[1], cnt3[2], trans);
      }
      (void)br;
    }
    // RVK_SETTLEDUMP (2026-07-15, select settle-state diagnostic): one-shot dump of the LEGACY
    // composite in the readback buffer (g.image as produced by the display fork above, i.e. what
    // the window shows when RVK_PILLARBOX=0) on the first select/field frame whose terminal resolve
    // is the 0x660000 1280x720 front-buffer composite. Answers definitively whether submitSeg's
    // render of the settle [0,49) batch list is the full UI or bg-only (the deferred routing
    // question), deterministically + crash-independently. Default off. Best under RVK_HDR=0.
    if (std::getenv("RVK_SETTLEDUMP") && !(pillarbox && panelRt)) {
      static bool dumped = false;
      bool has660 = false; for (auto& r : resolves) if (r.dst == 0x660000u) has660 = true;
      if (!dumped && has660 && g_base && be32(GA_FIELD_ACTIVE) != 0) {
        void* map = nullptr;
        if (vkMapMemory(g.dev, g.readbackMem, 0, VK_WHOLE_SIZE, 0, &map) == VK_SUCCESS) {
          writePng("/tmp/settle_composite.png", (const uint8_t*)map, kW, kH);
          vkUnmapMemory(g.dev, g.readbackMem);
          std::fprintf(stderr, "[rvk][settledump] frame%ld wrote /tmp/settle_composite.png (terminal 0x660000, %zu batches)\n", frame, batches.size());
          dumped = true;
        }
      }
    }
    // RVK_DUMPRES=1 (hatch RE 2026-07-11): on the RVK_DEBUG_OPS_FIELD-triggered frame, dump
    // every resolve texture to /tmp/res_<addr>_<w>x<h>.png (via the readback buffer) so we can
    // see whether the hatch artifact lives INSIDE the layer textures (feedback/blit artifact)
    // or only in the composited output (draw/transform artifact). Diagnostic only, default off.
    // NOTE: clobbers g.readback — the display copy for THIS frame is sacrificed (one frame).
    // RVK_DUMPRES=2 (2026-07-19 oracle-diff pass): frame-numbered filenames (res_f<frame>_...), so a
    // BURST of multi-shot sigdump touches across the submit->death window keeps every dump set
    // instead of clobbering one path — pick the live-field set offline. =1 keeps the stable names.
    if (fieldTrig && std::getenv("RVK_DUMPRES")) {
      static int dumpResMode = std::atoi(std::getenv("RVK_DUMPRES"));
      for (auto& kv : g_resolveTex) {
        ResolveTex& rt = kv.second;
        if (!rt.image || (size_t)rt.w * rt.h * 4 > (size_t)kW * kH * 4) continue;
        segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
        rvkRingNext("rdmp"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(rdmp)");
        VkCommandBufferBeginInfo cbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; cbi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
        VKC(vkBeginCommandBuffer(g.cmd, &cbi), "begin(rdmp)");
        VkImageMemoryBarrier b{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; b.srcQueueFamilyIndex = b.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        b.image = rt.image; b.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
        b.oldLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL; b.newLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        b.srcAccessMask = VK_ACCESS_SHADER_READ_BIT; b.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b);
        VkBufferImageCopy cp{}; cp.imageSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; cp.imageExtent = {rt.w, rt.h, 1};
        vkCmdCopyImageToBuffer(g.cmd, rt.image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, g.readback, 1, &cp);
        b.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL; b.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        b.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT; b.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
        vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b);
        VKC(vkEndCommandBuffer(g.cmd), "end(rdmp)");
        VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
        VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(rdmp)");
        VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(rdmp)");
        VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(rdmp)");
        void* map = nullptr;
        if (vkMapMemory(g.dev, g.readbackMem, 0, VK_WHOLE_SIZE, 0, &map) == VK_SUCCESS) {
          char nm[128];
          if (dumpResMode >= 2) std::snprintf(nm, sizeof nm, "/tmp/res_f%06ld_%08X_%ux%u.png", frame, kv.first, rt.w, rt.h);
          else std::snprintf(nm, sizeof nm, "/tmp/res_%08X_%ux%u.png", kv.first, rt.w, rt.h);
          if (g_rtFmt == VK_FORMAT_R16G16B16A16_SFLOAT) {
            // F16 resolve (RVK_HDR): half->float, exposure + hue-preserving Reinhard -> UNORM8 so the
            // dump is READABLE (eyeball only). Default 1.0 to MATCH the display tonemap default (was
            // 0.5 while display=1.0 -> a phantom ~2x delta in capture-vs-window; fixed). NOTE: this is
            // a diagnostic tonemap, NOT raw texels — for an ORACLE TEXEL DIFF run RVK_HDR=0 so the
            // resolve dumps as raw R8G8B8A8_UNORM (comparable to the oracle's 8-bit resolve).
            static float dexp = std::getenv("RVK_EXPOSURE") ? (float)atof(std::getenv("RVK_EXPOSURE")) : 1.0f;
            std::vector<uint8_t> tmp((size_t)rt.w * rt.h * 4);
            const uint16_t* hp = (const uint16_t*)map;
            for (size_t p = 0; p < (size_t)rt.w * rt.h; ++p) {
              for (int c = 0; c < 4; ++c) {
                float v = rvk_half2float(hp[p * 4 + c]);
                if (c < 3) { v = v > 0.f ? v : 0.f; v *= dexp; v = v / (1.f + v); }   // Reinhard (rgb)
                int iv = (int)(v * 255.f + 0.5f); tmp[p * 4 + c] = (uint8_t)(iv < 0 ? 0 : iv > 255 ? 255 : iv);
              }
            }
            writePng(nm, tmp.data(), rt.w, rt.h);
          } else {
            writePng(nm, (const uint8_t*)map, rt.w, rt.h);
          }
          vkUnmapMemory(g.dev, g.readbackMem);
          std::fprintf(stderr, "[rvk][dumpres] frame%ld %s everRendered=%d idx=%u\n", frame, nm, (int)rt.everRendered, rt.idx);
        }
      }
    }
    everRendered = true;
    g_anyRender = true;  // g.image holds this frame in TRANSFER_SRC_OPTIMAL (RVK_WINDOW blit source)
    g_realLastRendered = true; g_realLastDraws = ndraw;  // [present-trace]: this legacy call wrote g.image
    // RVK_LUMATRACE (2026-07-25 flash-regression instrument, DEFAULT OFF) — LEGACY-path twin of the
    // probe in renderHookedFrame. The shell intro/menus present through THIS spine ([fps] reports
    // path=legacy), so the hook-path copy never fires for them. The readback buffer already holds
    // this render's pixels (submitSeg above copied them), so this costs one map + a 16x16-subsampled
    // read; no extra GPU work. Emits mean luma + draw/batch counts per presented frame, which is
    // what distinguishes CONTENT flashing (alternating luma at a healthy present rate) from a
    // pacing collapse, and shows which frames lost their draws.
    static bool lumaTraceL = getenv("RVK_LUMATRACE") != nullptr;
    if (lumaTraceL) {
      // FENCE BEFORE SAMPLING (2026-07-25 fix). submitSeg only waits when the command ring is
      // OFF: with RVK_CMDRING on (the default) it just sets g.ringPending[slot] and defers the
      // wait to the next rvkRingNext wrap. So the readback copy is still IN FLIGHT here, and the
      // first version of this probe sampled it mid-copy -- proven with RVK_LUMARACE, where two
      // back-to-back reads of the same mapped buffer disagreed by up to 218 luma units. Wait on
      // every pending ring fence first. Deliberately does NOT clear ringPending: rvkRingNext owns
      // that state, and re-waiting an already-signalled fence there is a no-op. Probe-only, and
      // the whole block is behind the default-off RVK_LUMATRACE gate, so the ship path is
      // unaffected -- but note this wait DOES serialise the frame, so timing-sensitive numbers
      // (fps, [perflog]) must not be read from a RVK_LUMATRACE run.
      if (rvkRingOn()) {
        for (int s = 0; s < 6; s++)
          if (g.ringPending[s]) rvkWaitFences(g.dev, 1, &g.ringFence[s], VK_TRUE, 10000000000ull);
      } else {
        rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull);
      }
      void* lmap = nullptr;
      if (vkMapMemory(g.dev, g.readbackMem, 0, VK_WHOLE_SIZE, 0, &lmap) == VK_SUCCESS) {
        const uint8_t* pb = (const uint8_t*)lmap; unsigned long sum = 0; int cnt = 0;
        for (uint32_t y = 0; y < kH; y += 16) for (uint32_t x = 0; x < kW; x += 16) {
          const uint8_t* px = pb + ((size_t)y * kW + x) * 4; sum += px[0] + px[1] + px[2]; cnt++; }
        double meanNow = cnt ? (double)sum / (cnt * 3) : 0.0;
        // RVK_LUMARACE: read the SAME mapped buffer a second time, immediately. If the two reads
        // disagree, the GPU is still writing the readback copy while we sample it -- i.e. the
        // isolated single-frame luma spikes this probe reports are TORN READS (instrument
        // artifact), not content flashes. Validate the acquisition path before trusting it.
        static bool lumaRace = getenv("RVK_LUMARACE") != nullptr;
        if (lumaRace) {
          unsigned long s2 = 0; int c2 = 0;
          for (uint32_t y = 0; y < kH; y += 16) for (uint32_t x = 0; x < kW; x += 16) {
            const uint8_t* px = pb + ((size_t)y * kW + x) * 4; s2 += px[0] + px[1] + px[2]; c2++; }
          double mean2 = c2 ? (double)s2 / (c2 * 3) : 0.0;
          if (std::fabs(mean2 - meanNow) > 0.01)
            std::fprintf(stderr, "[lumarace] f%ld TORN: read1=%.2f read2=%.2f delta=%.2f\n",
                         frame, meanNow, mean2, mean2 - meanNow);
        }
        // RVK_LUMASHOT=<step>: when the mean luma jumps by more than <step> between two
        // consecutive RENDERED frames, dump BOTH frames (the one before the jump and the one
        // after) as /tmp/lumashot_<n>_{a,b}.png. That is the on-phase/off-phase pair the flash
        // investigation needs -- the same evidence a RenderDoc capture would give for "what
        // changed", but without the capture overhead that would skew the frame timing.
        // Keeping the previous frame costs one full-size host copy (~3.7MB), only when armed.
        static double shotStep = [](){ const char* e = getenv("RVK_LUMASHOT");
                                       return e ? atof(e) : 0.0; }();
        // RVK_LUMASHOT_AFTER=<frame>: don't arm until this frame. Boot/title/card transitions
        // step the mean luma by 100+ and would otherwise consume every shot slot before the
        // screen under investigation is even up.
        static long shotAfter = [](){ const char* e = getenv("RVK_LUMASHOT_AFTER");
                                      return e ? atol(e) : 0L; }();
        static std::vector<uint8_t> prevPix; static double prevMean = -1.0; static int shotN = 0;
        if (shotStep > 0.0 && frame >= shotAfter) {
          const size_t nbytes = (size_t)kW * kH * 4;
          if (prevMean >= 0.0 && std::fabs(meanNow - prevMean) > shotStep &&
              shotN < 8 && prevPix.size() == nbytes) {
            char pa[128], pb2[128];
            std::snprintf(pa, sizeof pa, "/tmp/lumashot_%d_a_f%ld_%.0f.png", shotN, frame - 1, prevMean);
            std::snprintf(pb2, sizeof pb2, "/tmp/lumashot_%d_b_f%ld_%.0f.png", shotN, frame, meanNow);
            writePng(pa, prevPix.data(), kW, kH);
            writePng(pb2, (const uint8_t*)lmap, kW, kH);
            std::fprintf(stderr, "[lumashot] #%d f%ld mean %.2f -> %.2f (step %.2f) draws %d -> wrote %s / %s\n",
                         shotN, frame, prevMean, meanNow, meanNow - prevMean, ndraw, pa, pb2);
            shotN++;
          }
          prevPix.assign((const uint8_t*)lmap, (const uint8_t*)lmap + nbytes);
          prevMean = meanNow;
        }
        vkUnmapMemory(g.dev, g.readbackMem);
        std::fprintf(stderr, "[luma] L f%ld mean=%.2f draws=%d batches=%zu verts=%u\n",
                     frame, meanNow, ndraw, batches.size(), nv);
      }
    }
  }
  // Non-sampled draw-y frame: keep /tmp/rvk_last.png fresh (rate-limited; readback buffer
  // already holds this render's pixels from the copy above).
  if (!render) {
    // RT_COMPOSE: the hookrender composite owns /tmp/rvk_last.png (it renders the FINAL frame
    // every present); this legacy-side refresh would interleave the intermediate full-frame
    // decode into the capture stream and poison frame sampling. Legacy still renders (resolve
    // fills), it just stops publishing its intermediate to rvk_last.
    static bool composeOwnsLast = getenv("RT_COMPOSE") != nullptr;
    // Shares the RVK_PNGEVERY gate (2026-07-16): unset => no diagnostic PNG encode anywhere. This
    // refresh is already capped at 1.5s so it is not the ~6fps hook-path throttle, but it is still a
    // ~2.7MB encode + readback map on the field spine, and it is debug-only. Set RVK_PNGEVERY (any N>0)
    // to restore it at its 1.5s cadence.
    // ★ RVK_BEATPNG=<bursts> (FNF-7 VISIBILITY TEST, 2026-07-26) — MEASURE ONLY, DEFAULT OFF.
    // Does the 62nd draw ever reach a PIXEL? The held version-select menu is static (the 61
    // steady draws carry identical vertex positions frame to frame), so consecutive presents
    // differ only by the beat draw. On a beat frame (ndraw > RVK_BEATTRIP) dump this frame and
    // the next two: diff(beat, clean) isolates the extra draw's contribution, and diff(clean,
    // clean) is the built-in STATIC CONTROL that proves the scene really is still. The menu
    // ENTRY frames (ndraw=64, animating) trigger their own bursts and serve as the mandatory
    // positive control that this readback+diff pipeline can see a visible change at all.
    // Capped at N bursts; the readback buffer already holds this render's pixels.
    {
      static int  beatBursts = getenv("RVK_BEATPNG") ? atoi(getenv("RVK_BEATPNG")) : 0;
      static int  beatTrip   = getenv("RVK_BEATTRIP") ? atoi(getenv("RVK_BEATTRIP")) : 61;
      static long burstsDone = 0; static int burstLeft = 0; static int run61 = 0;
      if (beatBursts > 0 && burstsDone < beatBursts) {
        // Trigger on EXACTLY beatTrip+1 draws after a settled run of beatTrip-draw frames.
        // A bare "> beatTrip" fires on the menu-ENTRY animation (68..278 draws) and burns every
        // burst before the steady screen is reached — measured, first attempt.
        if (burstLeft == 0) {
          if (ndraw == beatTrip) { if (run61 < 100000) ++run61; }
          else if (ndraw == beatTrip + 1 && run61 >= 5) { burstLeft = 3; run61 = 0; }
          else run61 = 0;
        }
        if (burstLeft > 0) {
          void* bmap = nullptr;
          if (vkMapMemory(g.dev, g.readbackMem, 0, VK_WHOLE_SIZE, 0, &bmap) == VK_SUCCESS) {
            char nm[160];
            std::snprintf(nm, sizeof nm, "/tmp/fnf7beat_%03ld_f%ld_d%d.png", burstsDone, frame, ndraw);
            writePng(nm, (const uint8_t*)bmap, kW, kH);
            vkUnmapMemory(g.dev, g.readbackMem);
          }
          if (--burstLeft == 0) ++burstsDone;
        }
      }
    }
    static bool pngCapLegacy = getenv("RVK_PNGEVERY") && atoi(getenv("RVK_PNGEVERY")) > 0;
    static long lastSaveMs = 0;
    long nowMs = (long)std::chrono::duration_cast<std::chrono::milliseconds>(
                   std::chrono::steady_clock::now().time_since_epoch()).count();
    if (pngCapLegacy && !composeOwnsLast && nowMs - lastSaveMs >= 1500) {
      void* map = nullptr; VKC(vkMapMemory(g.dev, g.readbackMem, 0, VK_WHOLE_SIZE, 0, &map), "map(rblast)");
      writePng("/tmp/rvk_last.png", (const uint8_t*)map, kW, kH);
      vkUnmapMemory(g.dev, g.readbackMem);
      // state marker for the film sampler: lets saved frames carry frame# + game FSM state,
      // so film<->state correlation stops being guesswork.
      if (g_base) {
        uint32_t fsm = __builtin_bswap32(*(const uint32_t*)(g_base + 0x884D66A8u));
        if (FILE* mf = fopen("/tmp/rvk_state.txt", "w")) {
          std::fprintf(mf, "f%ld_fsm%u_d%d", frame, fsm, ndraw); fclose(mf);
        }
      }
      std::fprintf(stderr, "[rvk][real] frame%ld: draws=%d -> refreshed /tmp/rvk_last.png\n", frame, ndraw);
      lastSaveMs = nowMs;
    }
    return true;
  }
  // Sampled frame with an empty window: the offscreen image still holds the last rendered
  // content — read THAT back instead of clearing it away.
  if (!doRender && everRendered) {
    segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
    rvkRingNext("rbonly"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(rbonly)");
    VkCommandBufferBeginInfo bi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; bi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    VKC(vkBeginCommandBuffer(g.cmd, &bi), "begin(rbonly)");
    copyDisplayToReadback(g.cmd);   // F6: tonemaps to UNORM8 under RVK_HDR
    VKC(vkEndCommandBuffer(g.cmd), "end(rbonly)");
    VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
    VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(rbonly)");
    VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(rbonly)");
    VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(rbonly)");
  }

  // RVK_KICKLOG (LEG-48, 2026-07-14 composite-kick topology): per rendered frame, summarize the
  // resolve targets of the decoded kick-capture arena and flag whether the guest's 1280x720
  // FRONTBUFFER COMPOSITE resolve (0x660000) is present this frame. Proved: the arena concatenates
  // every kick the guest submitted this present; on most field presents it terminates at the
  // 0xF95D000 640x512 PLAYFIELD resolve (the field kick only), but on ~1-in-8 presents it runs
  // through to the 0x660000 1280x720 resolve — the FULL composite (wallpaper bg + vs=47
  // playfield-region draw at {0,0,640,512} + full-screen vs=48 terrain + vs=1 HUD). There is NO
  // separate centered-placement draw: the guest composites the whole frame in one batch list, so
  // "honoring the composite kick" == rendering that full [0,N) batch list (what DISPLAYALL already
  // does). Any TATE centering therefore lives in the vertex transforms, not a distinct kick.
  if (std::getenv("RVK_KICKLOG") && render) {
    bool has660 = false; uint32_t termDst = resolves.empty() ? 0u : resolves.back().dst;
    std::fprintf(stderr, "[rvk][kicklog] frame%ld batches=%zu resolves=%zu term=0x%X:", frame, batches.size(), resolves.size(), termDst);
    for (auto& r : resolves) { std::fprintf(stderr, " 0x%X(%ux%u)", r.dst, r.w, r.h); if (r.dst == 0x660000u) has660 = true; }
    std::fprintf(stderr, "%s\n", has660 ? "  <-HAS-0x660000-COMPOSITE" : "");
  }
  VkViewport lvp = currentViewport();
  std::fprintf(stderr, "[rvk][real] frame%ld: window[0x%X,0x%X) draws=%d verts=%u tris=%u textures=%u batches=%zu vsIdx=%d psIdx=%d lastViewport={%.0f,%.0f,%.0f,%.0f}\n",
               frame, start, end, ndraw, nv, ni / 3, g.rNextTexIndex - 1, batches.size(), g_curVsIdx, g_curPsIdx, lvp.x, lvp.y, lvp.width, lvp.height);
  // RVK_ARENADUMP (2026-07-14): one-shot COMPLETE single-frame capture for the offline SDK
  // CommandProcessor replay proof. Fires on the first gameplay-field frame whose PM4 window is the
  // kick-capture ARENA (start in the rt_alloc heap, >=0x10000000) with a full draw stream (ndraw>=80,
  // vs the 18-draw legacy window). Dumps: the guest PHYSICAL image [0,512MB) — which contains the
  // arena at [start,end) = the whole submission-order PM4 stream, PLUS every VB/texture/shader-ucode
  // the draws reference (all in the phys heap per rt.cpp:779); the register-file shadow; and a
  // manifest (arena range, ring/fb state, draw count). The whole 4GB guest space is mapped RW
  // (rt.cpp:22) so the 512MB read never faults. Unlike the stale cap_ring.bin, this walks to the
  // full ~130 draws. Feed to a SDK CommandProcessor: InitializeRingBuffer(start, log2), wptr=end,
  // TranslatePhysical(a)=low+(a & 0x1FFFFFFF). Default off = byte-identical.
  {
    static bool arenaDumped = false;
    // Gate on fieldTrig (guest 0x885C1A20 gameplay-field flag, K-th frame via RVK_DEBUG_OPS_FIELD):
    // the bare ndraw>=80 heuristic captured the CONFIG MENU, not the stage. fieldTrig also forces
    // render=true so this block is reachable under RVK_DISPLAYALL. Now dumps a real cave-terrain
    // frame for the offline SDK-oracle diff (targets the cyan-tint / untile artifact).
    // g_rt_realstage (merged_xex RT_NAVREAL, declared at file scope) gates the capture to the REAL
    // held stage-1 field (arcade-select FSM submitted, maxD76>=8) — excludes the attract-under-menu
    // field and any config-menu frame (both also satisfy fieldTrig/ndraw>=80). When RT_NAVREAL isn't
    // driving (flag never set), RVK_ARENA_ANYFIELD=1 falls back to the old ndraw-only heuristic.
    bool realStageGate = g_rt_realstage != 0 || std::getenv("RVK_ARENA_ANYFIELD");
    // RVK_ARENA_DST=0xADDR (LEG-48, 2026-07-14 composite-kick capture): only capture a frame whose
    // resolve list contains ADDR. The kick topology (RVK_KICKLOG/FIELDMANIFEST) proved the guest
    // resolves the FIELD kick to 0xF95D000 (640x512 playfield) on some presents and the FULL
    // COMPOSITE (wallpaper+playfield-region+terrain+HUD) to 0x660000 (1280x720 frontbuffer) on
    // others. To feed the SDK oracle the 1280x720 composite (read at 0x660000) we must land the
    // one-shot dump on a 0x660000-resolving present, not the first ndraw>=N field frame (usually the
    // truncated 0xF95D000 one). Default 0 = disabled (unchanged ndraw-only gate).
    static uint32_t arenaDst = std::getenv("RVK_ARENA_DST") ? (uint32_t)std::strtoul(std::getenv("RVK_ARENA_DST"), nullptr, 16) : 0u;
    bool arenaDstOk = arenaDst == 0;
    if (arenaDst) for (auto& r : resolves) if (r.dst == arenaDst) { arenaDstOk = true; break; }
    // Env-tunable thresholds (the held replay-save state has ~64 draws in the legacy window; full
    // gameplay has 110+). Diagnostic log of every field-frame window so we can see what's available.
    static long   arenaMinDraw  = std::getenv("RVK_ARENA_MINDRAW")  ? std::strtol(std::getenv("RVK_ARENA_MINDRAW"), nullptr, 10) : 80;
    static uint32_t arenaMinStart = std::getenv("RVK_ARENA_MINSTART") ? (uint32_t)std::strtoul(std::getenv("RVK_ARENA_MINSTART"), nullptr, 16) : 0x10000000u;
    if (!arenaDumped && std::getenv("RVK_ARENADUMP") && realStageGate && fieldTrig && g_base) {
      static long adiag = 0;
      if (adiag++ < 40) std::fprintf(stderr, "[rvk][arenagate] field-frame ndraw=%d start=0x%X end=0x%X (need draw>=%ld start>=0x%X)\n",
        ndraw, start, end, arenaMinDraw, arenaMinStart);
    }
    // RVK_ARENA_SKIP=N: skip the first N qualifying field frames before capturing. The first
    // qualifying attract frames are the "Now Loading… REPLAY" transition screen; the actual cave
    // terrain replays a few frames later, so a skip lands the capture on real stage geometry.
    static long arenaSkip = std::getenv("RVK_ARENA_SKIP") ? std::strtol(std::getenv("RVK_ARENA_SKIP"), nullptr, 10) : 0;
    if (!arenaDumped && std::getenv("RVK_ARENADUMP") && realStageGate && fieldTrig && g_base && arenaDstOk && ndraw >= arenaMinDraw && start >= arenaMinStart && end > start) {
      if (arenaSkip > 0) { --arenaSkip; std::fprintf(stderr, "[rvk][arenagate] qualifying frame skipped (ndraw=%d, %ld to go)\n", ndraw, arenaSkip); }
      else {
      arenaDumped = true;
      const uint32_t LOWSZ = 0x20000000u;  // 512MB Xbox360 physical space (TranslatePhysical mask 0x1FFFFFFF)
      size_t wl = 0, wr = 0;
      if (FILE* f = std::fopen("/tmp/caparena_low.bin", "wb")) { wl = std::fwrite(g_base, 1, LOWSZ, f); std::fclose(f); }
      if (FILE* f = std::fopen("/tmp/caparena_regs.bin", "wb")) { wr = std::fwrite(g_regFile, 4, 0x6100, f); std::fclose(f); }
      if (FILE* f = std::fopen("/tmp/caparena_manifest.txt", "w")) {
        std::fprintf(f, "arena_start=0x%X\narena_end=0x%X\narena_len=0x%X\n", start, end, end - start);
        std::fprintf(f, "low_base=0x0\nlow_size=0x%X\nregfile_dwords=0x6100\n", LOWSZ);
        std::fprintf(f, "phys_mask=0x1FFFFFFF\ndraws_decoded=%d\nresolves=%zu\n", ndraw, resolves.size());
        std::fprintf(f, "fb_dst=0x%X\nrb_color_info_0x2001=0x%X\nrb_surface_0x2000=0x%X\n",
          g_regFile[0x2319] & 0xFFFFFFFu, g_regFile[0x2001], g_regFile[0x2000]);
        std::fprintf(f, "vgt_dma_0x48BE=0x%X\n", g_regFile[0x48BE]);
        std::fprintf(f, "field_flag_0x885C1A20=0x%X\n", g_base ? be32(GA_FIELD_ACTIVE) : 0);
        std::fclose(f);
      }
      std::fprintf(stderr, "[rvk][arenadump] frame%ld wrote /tmp/caparena_{low(%zuMB),regs(%zu),manifest}: arena[0x%X,0x%X) len=0x%X draws=%d resolves=%zu\n",
        frame, wl >> 20, wr, start, end, end - start, ndraw, resolves.size());
      }
    }
  }
  if (std::getenv("RVK_DEBUG_CONSTS")) {
    std::fprintf(stderr, "[rvk][debug] M2LibMatrix row0=(%.6f,%.6f,%.6f,%.6f) row1=(%.6f,%.6f,%.6f,%.6f)\n",
      g_vsConstF[0],g_vsConstF[1],g_vsConstF[2],g_vsConstF[3], g_vsConstF[4],g_vsConstF[5],g_vsConstF[6],g_vsConstF[7]);
    std::fprintf(stderr, "[rvk][debug] row2=(%.6f,%.6f,%.6f,%.6f) row3=(%.6f,%.6f,%.6f,%.6f)\n",
      g_vsConstF[8],g_vsConstF[9],g_vsConstF[10],g_vsConstF[11], g_vsConstF[12],g_vsConstF[13],g_vsConstF[14],g_vsConstF[15]);
    for (uint32_t vi = 0; vi + 4 <= nv && vi < 32; vi += 4) {
      uint32_t* d0 = Vraw + (size_t)vi * 6;
      float x0,y0,z0,u0,vv0; std::memcpy(&x0,&d0[0],4); std::memcpy(&y0,&d0[1],4); std::memcpy(&z0,&d0[2],4);
      std::memcpy(&u0,&d0[4],4); std::memcpy(&vv0,&d0[5],4);
      float cw = g_vsConstF[12]*x0 + g_vsConstF[13]*y0 + g_vsConstF[14]*z0 + g_vsConstF[15];
      std::fprintf(stderr, "[rvk][debug] vert%u raw pos=(%.3f,%.3f,%.3f) col=0x%08X uv=(%.3f,%.3f) clipw(lastmat)=%.2f\n",
                   vi, x0,y0,z0, d0[3], u0,vv0, cw);
    }
  }
  void* map = nullptr; VKC(vkMapMemory(g.dev, g.readbackMem, 0, VK_WHOLE_SIZE, 0, &map), "map(readback)");
  char path[64]; std::snprintf(path, sizeof path, "/tmp/rvk_frame%ld.png", frame);
  writePng(path, (const uint8_t*)map, kW, kH);
  vkUnmapMemory(g.dev, g.readbackMem);
  return true;
}

} // namespace

// ---- Decode-free render path (RT_HOOKRENDER): render the D3D-hooked draw list directly ----
// vpool = native-order vertex dwords for the whole frame; each RvkHookDraw indexes into it.
// Milestone 1: CPU-transform each strip-quad by its matrix -> NDC, render with vertex color +
// white texture (reusing the passthrough pipeline). Proves the hooks capture ALL ~99 menu draws.
// RVK_SKIPEMPTY (2026-07-14, "wallpaper flashes every now and then" fix): the shell issues
// occasional near-empty hook-present calls between content frames -- RT_HKTRACE at a stable menu
// shows 0/0 (zero-draw) and 1/1 frames interspersed among the 28/28|46/46 full frames. The hook
// path clears g.image to navy (0,0,0.10) and blits EVERY present to the window, so those empty
// frames flash navy over the otherwise-stable menu. g_hkLastRendered exports the accepted-quad
// count of the last hook frame so rvk_present_hooked can skip presenting near-empty frames
// (holding the last good frame on the window). Default (env unset) presents always => byte-identical.
static int g_hkLastRendered = 0;
static bool renderHookedFrame(uint8_t* base, const uint32_t* vpool, uint32_t vpoolDwords,
                              const RvkHookDraw* draws, int nDraws) {
  (void)base;
  g_hkLastRendered = 0;  // reset up front so any early error-return leaves it 0 (=> skip present)
  if (!g.white.set) { ((uint32_t*)g.stagingMap)[0] = 0xFFFFFFFFu; if (!uploadTexToDesc(1, 1, g.white)) { g.failed = true; return false; } }
  Vtx* V = (Vtx*)g.vbufMap; uint32_t* I = (uint32_t*)g.ibufMap;
  uint32_t nv = 0, ni = 0; int rendered = 0;
  struct HB { VkDescriptorSet set; uint32_t blend, first, cnt; };
  std::vector<HB> hbatches; VkDescriptorSet curSet = VK_NULL_HANDLE; uint32_t curBlend = 0; uint32_t bstart = 0;
  // RB_BLENDCONTROL per-draw blend (RT_HKBLEND, default on): honor each draw's guest blend state so
  // additive layers (e.g. the menu's green-ring background) accumulate instead of alpha-dissolving.
  static bool hkBlend = getenv("RT_HKBLEND") ? atoi(getenv("RT_HKBLEND")) != 0 : true;
  auto unpack = [](uint32_t c, float& r, float& gg, float& b, float& a){ a = ((c>>24)&0xff)/255.f; r = ((c>>16)&0xff)/255.f; gg = ((c>>8)&0xff)/255.f; b = (c&0xff)/255.f; };
  // The guest M2LibMatrix produces Xbox360-D3D clip coords (+Y = up); Vulkan NDC is +Y = down, so
  // feeding them straight through flips the frame vertically (upside-down text). Negate NDC.y.
  static bool flipY = getenv("RVK_HKFLIPY") ? atoi(getenv("RVK_HKFLIPY")) != 0 : true;
  // RT_HKDUP diagnostic (2026-07-12, menu text-duplication investigation): record every quad
  // ACTUALLY rendered this present (post rejection-filter, so it matches exactly what the
  // MENU-BAND capture below writes to rvk_menu.png -- the rt.cpp-side pre-filter dump missed the
  // real text draws because "rendered" (this loop's accepted count) can differ from g_hkdN).
  static bool hkdup = getenv("RT_HKDUP") != nullptr;
  // RT_HKDUP2=<frameN> (2026-07-12, blank-stage-phase investigation): same full quad dump as
  // RT_HKDUP, but fired ONCE at/after hooked-frame N instead of at the menu-band capture --
  // lets us inspect the steady 35-quad frames of the credit-hold/stage phase, which never
  // enter the menu band. Includes vertex-alpha range + blend to discriminate a stuck fade
  // (alpha=0 / black overlay) from off-screen NDC from missing playfield content.
  static long hkdup2at = getenv("RT_HKDUP2") ? atol(getenv("RT_HKDUP2")) : -1;
  struct HkDupRow { uint32_t tex, tw, th, blend; int di; float bx0, bx1, by0, by1, bu0, bu1, bv0, bv1, ba0, ba1; };
  std::vector<HkDupRow> hkdupRows; if (hkdup || hkdup2at >= 0) hkdupRows.reserve((size_t)nDraws);
  // RT_COMPOSE (2026-07-13): per-draw render-target/viewport awareness (RvkHookDraw.rtwh/vp,
  // captured from dev+0x28C8 / dev+0x2908 by the shell hooks). Two consequences:
  // (1) draws whose RT is NOT the 1280x720 screen are OFFSCREEN passes (the playfield's 320x240
  //     bloom/downsample ring) — skip them; the legacy PM4 decode renders their results into
  //     g_resolveTex, which the on-screen composite samples via the resolve lookup above.
  // (2) on-screen blit-class draws (RECTLIST + translation-degenerate matrix) take their screen
  //     placement from the VIEWPORT RECTANGLE (StretchRect semantics), not the matrix — this is
  //     what places the playfield window centered while the wallpaper's full-screen viewport
  //     reproduces the existing full-screen mapping. Gated on RT_COMPOSE so menu-only runs
  //     (RT_WALLPAPER etc.) keep their proven transRepair behavior byte-identical.
  static bool composeOn = getenv("RT_COMPOSE") != nullptr;
  constexpr uint32_t kScreenRtWH = (720u << 16) | 1280u;
  // RVK_PANEL (2026-07-14): the field content lives in the HOOK DRAWS (the playfield resolve is only
  // transiently populated on the attract/replay path), rendered full-window. To present the faithful
  // centered vertical TATE panel + wallpaper borders, SQUEEZE the field passes (draws whose render
  // target is NOT the 1280x720 screen — the offscreen playfield/bloom passes) into a centered panel
  // rect, while screen-RT draws (wallpaper full-screen = borders, HUD) render normally. This makes
  // the panel come from the guest's own RT routing (faithful) rather than a hand-placed transform.
  // RVK_PANELRECT=x0:x1:y0:y1 overrides the NDC rect (default ~3:4 centered strip). Default off =
  // byte-identical. Best paired with RT_COMPOSE OFF (so the field passes aren't skipped).
  static bool panelOn = getenv("RVK_PANEL") != nullptr;
  float pnx0 = -0.42f, pnx1 = 0.42f, pny0 = -1.f, pny1 = 1.f;
  if (panelOn) { if (const char* pr = getenv("RVK_PANELRECT")) std::sscanf(pr, "%f:%f:%f:%f", &pnx0, &pnx1, &pny0, &pny1); }
  for (int d = 0; d < nDraws && nv + 4 <= kMaxVerts && ni + 6 <= kMaxIndices; ++d) {
    const RvkHookDraw& hd = draws[d];
    // RVK_CMPPROBE: catch every hook draw that SAMPLES A RESOLVE (the shell's gameplay composite)
    // BEFORE the offscreen-skip below, so we see whether the composite quad is being skipped
    // (rtwh!=screen), what primitive/vp it carries, and whether its resolve is populated. Diagnoses
    // why RT_COMPOSE goes blank (the panel composite not landing). Log once per resolve base.
    static bool cmpProbe = std::getenv("RVK_CMPPROBE") != nullptr;
    if (cmpProbe && hd.tf[1]) {
      uint32_t tbp = ((hd.tf[1] >> 12) & 0xFFFFF) << 12;
      auto rp = g_resolveTex.find(tbp);
      if (rp != g_resolveTex.end()) {
        static std::set<uint32_t> seenCmp;
        if (seenCmp.insert(tbp).second) {
          bool willSkip = composeOn && hd.rtwh && hd.rtwh != kScreenRtWH;
          std::fprintf(stderr, "[cmpprobe] d=%d RESOLVE-SAMPLE base=0x%X %ux%u img=%d prim=%u cnt=%u rtwh=0x%X skip=%d mtx[3,7,15]=(%.1f,%.1f,%.1f) vp={%.1f,%.1f,%.1f,%.1f}\n",
            d, tbp, rp->second.w, rp->second.h, rp->second.image ? 1 : 0, hd.prim, hd.count, hd.rtwh, (int)willSkip,
            (double)hd.mtx[3], (double)hd.mtx[7], (double)hd.mtx[15],
            (double)hd.vp[0], (double)hd.vp[1], (double)hd.vp[2], (double)hd.vp[3]);
        }
      }
    }
    // RVK_PANEL: field passes (non-screen RT) are SQUEEZED into the panel rect (below) instead of
    // being skipped/full-window. When panelOn we keep them; otherwise RT_COMPOSE's skip stands.
    bool panelSqueeze = panelOn && hd.rtwh && hd.rtwh != kScreenRtWH;
    if (!panelOn && composeOn && hd.rtwh && hd.rtwh != kScreenRtWH) continue;  // offscreen pass -> legacy owns it
    // RT_HKRECTLIST (2026-07-13, menu wallpaper root cause): a D3DPT_RECTLIST draw (Xenos hw rect
    // primitive, prim==8) submits exactly 3 explicit corners per rect and the HARDWARE derives the
    // 4th (v3 = v1 + v2 - v0) -- the SAME convention the legacy PM4 RECTLIST path already
    // implements (render/vk_render.cpp ~line 1744). The original "m1: fan-quads only" filter
    // required count>=4, so every RECTLIST draw (count==3) was silently DROPPED here before ever
    // reaching the texture/matrix pipeline. This was the actual reason the wallpaper (wp01.bin, a
    // full-screen RECTLIST quad -- confirmed via RT_HKDUP: prim=8 cnt=3 stride=4, raw FLOAT
    // pixel-space {x,y,u,v} 4-dword records v0=(0,0)uv(0,0) v1=(1280,0)uv(1,0)) never painted, even
    // though [dfout]'s texture-gate/SetTexture and the M2LibMatrix read both succeeded. Default
    // tracks RT_WALLPAPER (2026-07-13 fix: an earlier version defaulted this ON unconditionally --
    // a SECOND, unrelated always-present RECTLIST draw with the same scale signature turned out to
    // exist even with RT_WALLPAPER off, which un-dropped it too and broke the "RT_WALLPAPER off ==
    // byte-identical navy baseline" regression bar. RT_HKRECTLIST=0/1 still overrides explicitly
    // for A/B regardless of RT_WALLPAPER).
    static bool wallpaperLeverOn = getenv("RT_WALLPAPER") != nullptr;
    static bool hkRectList = getenv("RT_HKRECTLIST") ? atoi(getenv("RT_HKRECTLIST")) != 0 : wallpaperLeverOn;
    bool isRect = hkRectList && hd.prim == 8 && hd.count == 3;
    if (!isRect && hd.count < 4) continue;                             // m1: fan-quads (or RECTLIST triples)
    if (hd.stride < 4) continue;
    uint32_t vneed = isRect ? 3u : 4u;
    if ((uint64_t)hd.voff + (uint64_t)vneed * hd.stride > vpoolDwords) continue;  // bounds
    // decode the bound texture fetch constant (tf[0]/tf[1]==0 => white) and batch by descriptor set
    VkDescriptorSet set = g.white.set;
    if (hd.tf[1]) {
      uint32_t tb = ((hd.tf[1] >> 12) & 0xFFFFF) << 12;
      uint32_t tw = (hd.tf[2] & 0x1FFF) + 1, th = ((hd.tf[2] >> 13) & 0x1FFF) + 1, tfmt = hd.tf[1] & 0x3F;
      // RVK_WASHTF=<hex base> hook-path mirror (2026-07-22): the char-select textures decode
      // through getTexture() HERE, not the legacy getTexIndexReal segman path where the other
      // [washtf] probe lives -- so the base-targeted RVK_WASHTF must fire on BOTH paths to catch
      // 0x12634000. Same tf0..tf5 dump, tagged [washtf/hook]; base identity only (no fmt gate).
      static const char* washtfEnvHk = std::getenv("RVK_WASHTF");
      static uint32_t washtfBaseHk = washtfEnvHk ? (uint32_t)strtoul(washtfEnvHk, nullptr, 16) : 0u;
      if (washtfBaseHk > 0x1000u && tb == washtfBaseHk) {
        const uint32_t* t = hd.tf;
        // Dedup on tf-change: this site runs per-draw per-frame; unbuffered stderr at the held
        // card (~100 draws x 60fps) would throttle the guest like the old PNG-every-frame bug.
        static uint32_t hkLast[6] = {0,0,0,0,0,0}; static uint32_t hkSeen = 0;
        hkSeen++;
        if (std::memcmp(hkLast, t, 6*sizeof(uint32_t)) != 0) {
          std::memcpy(hkLast, t, 6*sizeof(uint32_t));
          std::fprintf(stderr, "[washtf/hook] base=0x%08X seen=%u %ux%u fmt=%u tiled=%u pitch=%u | STACKED=%u stackDepth=%u dim=%u packedMips=%u mipAddr=0x%08X | tf0=%08X tf1=%08X tf2=%08X tf3=%08X tf4=%08X tf5=%08X\n",
            tb, hkSeen, tw, th, tfmt, (t[0] >> 31) & 1u, ((t[0] >> 22) & 0x1FFu) << 5,
            (t[1] >> 10) & 1u, ((t[2] >> 26) & 0x3Fu) + 1u, (t[5] >> 9) & 3u, (t[5] >> 11) & 1u, ((t[5] >> 12) & 0xFFFFF) << 12,
            t[0], t[1], t[2], t[3], t[4], t[5]);
        }
      }
      rvkFetchRawNote(hd.tf, tb, tw, th, tfmt, "hook");
      set = getTexture(tb, tw, th, tfmt, hd.tf[0]);
    }
    uint32_t blend = hkBlend ? (hd.blend & 0xFFFFFFFu) : 0u;
    if (set != curSet || blend != curBlend) { if (curSet && ni > bstart) hbatches.push_back({curSet, curBlend, bstart, ni - bstart}); curSet = set; curBlend = blend; bstart = ni; }
    const float* m = hd.mtx;
    // RVK_HKMTXREPAIR (2026-07-12, blank-stage-phase root cause -- CONFIRMED via RT_HKDUP2 at
    // stage/credit-hold f=4000): during the game module's stage phase the guest leaves the
    // device+0x780 M2LibMatrix in its known position-degenerate state (c0=(0,0,0,146.25)
    // c1=(0,0,0,-280) c3=(0,0,-1,360) -- the SAME matrix documented at the 2026-07-05 replay
    // screen, see matrixIsDegenerate()/repairMatrix() above), so all 35 chrome quads collapse
    // to the single NDC point (0.406,0.778) and the frame rasterizes blank for 200+s while
    // [hktrace] shows healthy draw counts. Raw vertices are intact centered screen-space quads,
    // so re-supply the proven projection diagonal in THIS path's convention (ndx=0.5625x/360=
    // x/640, ndy_preflip=y/360 -- validated against the working menu frames) and drop the baked
    // P*T translation (T=(260,280) is the legacy corner-origin artifact, meaningless here).
    // Signs: A/B'd live 2026-07-12 on the credit/replay dialog -- (+0.5625,+1) = vertical flip
    // (upside-down text), (-0.5625,-1) = horizontal mirror; (+0.5625,-1) renders it upright and
    // unmirrored, and matches repairMatrix()'s proven legacy defaults. Safe for this class:
    // every draw this repair touches was previously point-collapsed (invisible), so no
    // previously-correct content can regress. Env-tunable (RVK_HKRSX/RVK_HKRSY) to A/B.
    // Default tracks RT_COMPOSE (2026-07-13, in-field HUD fix): field-active compose frames carry
    // the position-degenerate M2LibMatrix on ALL the HUD/chrome draws (hkdup2 @f2600: 25 glyph
    // quads collapsed to ndc(0.406,0.778)) — the exact class this repair was verified on (the
    // stage credit/replay dialog: vertices are intact centered screen-space quads, the matrix
    // should be the plain projection diagonal). Off-compose behavior unchanged (explicit env
    // still overrides both ways).
    static bool hkMtxRepair = getenv("RVK_HKMTXREPAIR") ? atoi(getenv("RVK_HKMTXREPAIR")) != 0
                                                        : (getenv("RT_COMPOSE") != nullptr);
    static float hkRsx = getenv("RVK_HKRSX") ? (float)atof(getenv("RVK_HKRSX")) : 0.5625f;
    static float hkRsy = getenv("RVK_HKRSY") ? (float)atof(getenv("RVK_HKRSY")) : -1.f;
    float mrep[16];
    if (hkMtxRepair && matrixIsDegenerate(hd.mtx)) {
      std::memcpy(mrep, hd.mtx, sizeof mrep);
      mrep[0] = hkRsx; mrep[3] = 0.f;   // c0: restore x scale, drop baked translation
      mrep[5] = hkRsy; mrep[7] = 0.f;   // c1: restore y scale, drop baked translation
      m = mrep;
      static long repaired = 0;
      if ((repaired++ % 5000) == 0)
        std::fprintf(stderr, "[rvk][hook] degenerate M2LibMatrix (t=%.2f,%.2f w=%.0f) -> repaired (%ld so far)\n",
          (double)hd.mtx[3], (double)hd.mtx[7], (double)hd.mtx[15], repaired);
    }
    // RT_HKTRANSREPAIR (2026-07-13, wallpaper root cause part 2): a DIFFERENT degenerate variant
    // than RVK_HKMTXREPAIR above -- the SCALE (m0/m5) is intact and already correctly maps
    // pixel-space to half-NDC-range (captured wallpaper matrix: 0.5625/360 == 1/640, matching a
    // 1280px-wide screen), but the TRANSLATION (m3/m7) that should recenter the resulting [0,2]
    // span into Vulkan's [-1,1] arrives zeroed, so a near-origin vertex (e.g. the wallpaper's
    // top-left corner) collapses toward NDC (0,0) instead of the screen edge -- confirmed via
    // RT_HKDUP on the captured wallpaper matrix: mtx r0=[0.5625,0,0,0] r1=[0,1,0,0]
    // r3=[0,0,1,360]. Tunable multipliers of m15 (RT_HKRTX/RT_HKRTY, default -1) so the sign can
    // be A/B'd live (no rebuild) if the guest's handedness differs from this first guess.
    static bool hkTransRepair = getenv("RT_HKTRANSREPAIR") ? atoi(getenv("RT_HKTRANSREPAIR")) != 0 : wallpaperLeverOn;
    static float hkRtx = getenv("RT_HKRTX") ? (float)atof(getenv("RT_HKRTX")) : -1.f;
    // hkRty default +1 with a NEGATED y scale (2026-07-13, verified on the pitch-fixed wallpaper):
    // the guest hands this matrix a POSITIVE identity y scale (r1=[0,1,0,0]) over y-DOWN pixel
    // coords, but every normally-translated draw reaches clip space y-UP (flipY then re-inverts).
    // Translation alone cannot flip; with m5 -> -m5 and m7 = +m15, y=0 maps to the top and
    // y=720 to the bottom after flipY. The original (-1, no scale negation) first guess rendered
    // the wallpaper upside-down (Reco inverted, logo top-left instead of bottom-left).
    static float hkRty = getenv("RT_HKRTY") ? (float)atof(getenv("RT_HKRTY")) : 1.f;
    float mrep2[16];
    // Scoped to isRect (RECTLIST) draws ONLY (2026-07-13 build: an earlier version of this check
    // omitted the isRect guard and matched plenty of ORDINARY fan-quad menu draws too -- m3=m7=0 is
    // a perfectly legitimate matrix for content whose translation is baked into vertex coordinates
    // instead -- which stomped their real (correct) translation and shredded the menu into the
    // tiled/striped mess seen in win_topmenu_WALLPAPER_2026-07-13.png). RECTLIST is the only class
    // empirically confirmed (via RT_HKDUP) to need this repair.
    bool transDeg = isRect && m[3] == 0.f && m[7] == 0.f && m[12] == 0.f && m[13] == 0.f && m[15] != 0.f && (m[0] != 0.f || m[5] != 0.f);
    if (hkTransRepair && transDeg) {
      std::memcpy(mrep2, m, sizeof mrep2);
      mrep2[3] = hkRtx * m[15];
      mrep2[5] = -m[5];          // y-down pixel coords -> y-up clip (see hkRty note above)
      mrep2[7] = hkRty * m[15];
      m = mrep2;
      static long repaired2 = 0;
      if ((repaired2++ % 2000) == 0)
        std::fprintf(stderr, "[rvk][hook] translation-degenerate M2LibMatrix (sx=%.4f sy=%.4f w=%.0f) -> repaired (%ld so far)\n",
          (double)hd.mtx[0], (double)hd.mtx[5], (double)hd.mtx[15], repaired2);
    }
    // Gather the quad's 4 corners as (x,y,u,v,color). For a RECTLIST draw only 3 are real
    // vertices; the 4th is hardware-derived (v3 = v1 + v2 - v0, matching the legacy PM4 path).
    // RECTLIST corners captured as 4-dword {x,y,u,v} FLOAT records (confirmed via RT_HKDUP raw hex
    // on the wallpaper draw) have no per-vertex color field -> constant opaque white (texture
    // modulates unchanged). stride>=6 falls back to the standard {x,y,z,color,u,v} layout.
    float qx[4], qy[4], qu[4], qv[4]; uint32_t qc[4];
    if (isRect) {
      for (int k = 0; k < 3; ++k) {
        const uint32_t* vp = vpool + hd.voff + (uint32_t)k * hd.stride;
        union { uint32_t u; float f; } cx, cy, cu, cv;
        if (hd.stride <= 4) { cx.u = vp[0]; cy.u = vp[1]; cu.u = vp[2]; cv.u = vp[3]; qc[k] = 0xFFFFFFFFu; }
        else { cx.u = vp[0]; cy.u = vp[1]; cu.u = vp[4]; cv.u = vp[5]; qc[k] = vp[3]; }
        qx[k] = cx.f; qy[k] = cy.f; qu[k] = cu.f; qv[k] = cv.f;
      }
      qx[3] = qx[1] + qx[2] - qx[0]; qy[3] = qy[1] + qy[2] - qy[0];
      qu[3] = qu[1] + qu[2] - qu[0]; qv[3] = qv[1] + qv[2] - qv[0];
      qc[3] = qc[1];
    } else {
      for (int k = 0; k < 4; ++k) {
        const uint32_t* vp = vpool + hd.voff + (uint32_t)k * hd.stride;
        union { uint32_t u; float f; } cx, cy, cu, cv; cx.u = vp[0]; cy.u = vp[1]; cu.u = vp[4]; cv.u = vp[5];
        qx[k] = cx.f; qy[k] = cy.f; qu[k] = cu.f; qv[k] = cv.f; qc[k] = vp[3];
      }
    }
    // RT_COMPOSE viewport-rect mapping for on-screen blit-class draws (see the composeOn note at
    // the loop top): the quad's DESTINATION is the viewport rectangle in screen pixels; vertex
    // x/y only parameterize the quad's own extent (and carry the UVs). Screen space is already
    // y-down, so flipY does not apply on this path.
    bool useVpRect = composeOn && isRect && transDeg && hd.vp[0] != 0.f && hd.vp[2] != 0.f;
    float vpx0=0, vpx1=0, vpy0=0, vpy1=0, qminx=0, qmaxx=0, qminy=0, qmaxy=0;
    if (useVpRect) {
      float sx = hd.vp[0] < 0 ? -hd.vp[0] : hd.vp[0], ox = hd.vp[1];
      float sy = hd.vp[2] < 0 ? -hd.vp[2] : hd.vp[2], oy = hd.vp[3];
      vpx0 = (ox - sx) / 640.f - 1.f; vpx1 = (ox + sx) / 640.f - 1.f;
      vpy0 = (oy - sy) / 360.f - 1.f; vpy1 = (oy + sy) / 360.f - 1.f;
      qminx = qmaxx = qx[0]; qminy = qmaxy = qy[0];
      for (int k2 = 1; k2 < 4; ++k2) {
        if (qx[k2] < qminx) qminx = qx[k2]; if (qx[k2] > qmaxx) qmaxx = qx[k2];
        if (qy[k2] < qminy) qminy = qy[k2]; if (qy[k2] > qmaxy) qmaxy = qy[k2];
      }
    }
    uint32_t v0 = nv;
    float bbMinX=1e9f,bbMaxX=-1e9f,bbMinY=1e9f,bbMaxY=-1e9f,bbMinA=1e9f,bbMaxA=-1e9f;
    float bbMinU=1e9f,bbMaxU=-1e9f,bbMinV=1e9f,bbMaxV=-1e9f;
    float dup_x0=0, dup_y0=0;
    for (int vv = 0; vv < 4; ++vv) {
      float x = qx[vv], y = qy[vv], z = 0.f;
      float clx = m[0]*x + m[1]*y + m[2]*z + m[3];
      float cly = m[4]*x + m[5]*y + m[6]*z + m[7];
      float clw = m[12]*x + m[13]*y + m[14]*z + m[15]; if (clw == 0.f) clw = 1.f;
      float r, gg, b, a; unpack(qc[vv], r, gg, b, a);
      float ndy = cly/clw; if (flipY) ndy = -ndy;
      float ndx = clx/clw;
      if (useVpRect) {
        float un = (qmaxx > qminx) ? (x - qminx) / (qmaxx - qminx) : 0.f;
        float vn = (qmaxy > qminy) ? (y - qminy) / (qmaxy - qminy) : 0.f;
        ndx = vpx0 + (vpx1 - vpx0) * un;
        ndy = vpy0 + (vpy1 - vpy0) * vn;
      }
      // RVK_PANEL squeeze: remap the field pass's full-window NDC [-1,1] into the centered panel rect.
      if (panelSqueeze) {
        ndx = pnx0 + (pnx1 - pnx0) * (ndx * 0.5f + 0.5f);
        ndy = pny0 + (pny1 - pny0) * (ndy * 0.5f + 0.5f);
      }
      if(ndx<bbMinX)bbMinX=ndx; if(ndx>bbMaxX)bbMaxX=ndx; if(ndy<bbMinY)bbMinY=ndy; if(ndy>bbMaxY)bbMaxY=ndy;
      if(a<bbMinA)bbMinA=a; if(a>bbMaxA)bbMaxA=a;
      if(qu[vv]<bbMinU)bbMinU=qu[vv]; if(qu[vv]>bbMaxU)bbMaxU=qu[vv]; if(qv[vv]<bbMinV)bbMinV=qv[vv]; if(qv[vv]>bbMaxV)bbMaxV=qv[vv];
      if (vv == 0) { dup_x0 = ndx; dup_y0 = ndy; }
      V[nv++] = Vtx{ ndx, ndy, qu[vv], qv[vv], r, gg, b, a };
    }
    (void)dup_x0; (void)dup_y0;
    if (hkdup || hkdup2at >= 0) {
      uint32_t tb = 0, tw = 0, th = 0;
      if (hd.tf[1]) { tb = ((hd.tf[1] >> 12) & 0xFFFFF) << 12; tw = (hd.tf[2] & 0x1FFF) + 1; th = ((hd.tf[2] >> 13) & 0x1FFF) + 1; }
      hkdupRows.push_back({tb, tw, th, hd.blend, d, bbMinX, bbMaxX, bbMinY, bbMaxY, bbMinU, bbMaxU, bbMinV, bbMaxV, bbMinA, bbMaxA});
    }
    // RT_HKBBOX: per-quad texture + NDC bbox + vertex-alpha range, deduped by (texture, x-bucket).
    // A card quad shows as a big-texture draw on the RIGHT (NDC x>0); off-screen x>1 => mispositioned;
    // alpha 0 => transparent; absent => the guest never issues it (find the gate in the decomp).
    static bool hkbbox = getenv("RT_HKBBOX") != nullptr;
    if (hkbbox) {
      static std::set<uint64_t> seenb;
      uint32_t tb = hd.tf[1] ? (((hd.tf[1]>>12)&0xFFFFF)<<12) : 0u;
      uint64_t k = ((uint64_t)tb<<8) ^ (uint64_t)(int)(bbMinX*10);
      if (seenb.insert(k).second)
        std::fprintf(stderr,"[hkbbox] tex=0x%07X x=[%.2f,%.2f] y=[%.2f,%.2f] alpha=[%.2f,%.2f] blend=0x%X\n",
          tb, (double)bbMinX,(double)bbMaxX,(double)bbMinY,(double)bbMaxY,(double)bbMinA,(double)bbMaxA,hd.blend);
    }
    // RECTLIST's derived 4th corner (v3=v1+v2-v0) is diagonal to v0 across the v1-v2 edge, NOT
    // adjacent in rotational order like a fan's corners -- so it needs triangles sharing the v1-v2
    // edge ((v0,v1,v2)+(v2,v1,v3)), not the fan's (v0,v1,v2)+(v0,v2,v3) (which would leave a gap
    // and an overlap; verified analytically against the corner assignment before this went in).
    if (isRect) { I[ni++]=v0; I[ni++]=v0+1; I[ni++]=v0+2; I[ni++]=v0+2; I[ni++]=v0+1; I[ni++]=v0+3; }
    else        { I[ni++]=v0; I[ni++]=v0+1; I[ni++]=v0+2; I[ni++]=v0;   I[ni++]=v0+2; I[ni++]=v0+3; }  // triangle FAN (Xenos prim 5)
    ++rendered;
  }
  if (curSet && ni > bstart) hbatches.push_back({curSet, curBlend, bstart, ni - bstart});
  segBatchFlush();   // RVK_SEGBATCH: order deferred seg ops before reusing g.cmd
  rvkRingNext("hk"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(hk)");
  VkCommandBufferBeginInfo bi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; bi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
  VKC(vkBeginCommandBuffer(g.cmd, &bi), "begin(hk)");
  VkClearValue clear{}; clear.color = {{0.0f, 0.0f, 0.10f, 1.0f}};
  VkRenderPassBeginInfo rpb{VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO}; rpb.renderPass = g.pass; rpb.framebuffer = g.fb; rpb.renderArea = {{0,0},{kW,kH}}; rpb.clearValueCount = 1; rpb.pClearValues = &clear;
  vkCmdBeginRenderPass(g.cmd, &rpb, VK_SUBPASS_CONTENTS_INLINE);
  VkDeviceSize voff = 0; vkCmdBindVertexBuffers(g.cmd, 0, 1, &g.vbuf, &voff);
  vkCmdBindIndexBuffer(g.cmd, g.ibuf, 0, VK_INDEX_TYPE_UINT32);
  VkPipeline curPipe = VK_NULL_HANDLE;
  // RANK 21: RB_COLOR_MASK (0x2104) — the persistent register shadow is kept warm by the legacy
  // PM4 walk every present (see the RT_HYBRID note below) even when the hook path owns the actual
  // draw, so it's a valid live read here too.
  uint32_t hkColorMask = g_regFile[0x2104] & 0xFu;
  for (auto& b : hbatches) {
    VkPipeline pipe = hkBlend ? getOrCreateHookPipeline(b.blend, hkColorMask) : getOrCreatePassthroughPipeline(hkColorMask);
    if (pipe != curPipe) { vkCmdBindPipeline(g.cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, pipe); curPipe = pipe; }
    vkCmdBindDescriptorSets(g.cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, g.plLayout, 0, 1, &b.set, 0, nullptr);
    vkCmdDrawIndexed(g.cmd, b.cnt, 1, b.first, 0, 0);
  }
  vkCmdEndRenderPass(g.cmd);
  copyDisplayToReadback(g.cmd);   // F6: tonemaps to UNORM8 under RVK_HDR
  VKC(vkEndCommandBuffer(g.cmd), "end(hk)");
  VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
  VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(hk)");
  VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(hk)");
  VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(hk)");
  static long hf = 0; long thisf = hf++;
  static bool hktrace = getenv("RT_HKTRACE") != nullptr;
  if (hktrace || (thisf % 120) == 0) std::fprintf(stderr, "[rvk][hook] f=%ld %d/%d quads rendered, verts=%u idx=%u\n", thisf, rendered, nDraws, nv, ni);
  // RT_HKDUP2: one-shot full dump of the accepted quads at/after the requested hooked frame
  // (blank-stage-phase investigation -- see the RT_HKDUP2 comment at the top of this function).
  if (hkdup2at >= 0) {
    static bool dup2done = false;
    if (!dup2done && thisf >= hkdup2at) {
      dup2done = true;
      std::fprintf(stderr, "[hkdup2] === f=%ld dump: %zu accepted quads (of %d draws) ===\n", thisf, hkdupRows.size(), nDraws);
      for (size_t i = 0; i < hkdupRows.size(); ++i) {
        const HkDupRow& r = hkdupRows[i];
        const RvkHookDraw& hdRT = draws[r.di];
        std::fprintf(stderr, "[hkdup2] i=%zu tex=0x%07X %ux%u ndc_bbox=[%.3f,%.3f]x[%.3f,%.3f] uv_bbox=[%.3f,%.3f]x[%.3f,%.3f] a=[%.2f,%.2f] blend=0x%08X rt=%ux%u vp=(%.0f,%.0f,%.0f,%.0f)\n",
          i, r.tex, r.tw, r.th, (double)r.bx0, (double)r.bx1, (double)r.by0, (double)r.by1,
          (double)r.bu0, (double)r.bu1, (double)r.bv0, (double)r.bv1, (double)r.ba0, (double)r.ba1, r.blend,
          hdRT.rtwh & 0xFFFFu, hdRT.rtwh >> 16, (double)hdRT.vp[0], (double)hdRT.vp[1], (double)hdRT.vp[2], (double)hdRT.vp[3]);
        // matrix + raw vertex positions: point-degenerate NDC with spanning UVs implicates the
        // captured M2LibMatrix (zero scale => every corner lands on the translation), so show it.
        const RvkHookDraw& hd2 = draws[r.di];
        const float* m2 = hd2.mtx;
        union { uint32_t u; float f; } rvx[4], rvy[4];
        for (int vv = 0; vv < 4; ++vv) { const uint32_t* vp2 = vpool + hd2.voff + (uint32_t)vv * hd2.stride; rvx[vv].u = vp2[0]; rvy[vv].u = vp2[1]; }
        std::fprintf(stderr, "[hkdup2]   mtx r0=[%.4f %.4f %.4f %.4f] r1=[%.4f %.4f %.4f %.4f] r3=[%.4f %.4f %.4f %.4f] rawv=(%.1f,%.1f)(%.1f,%.1f)(%.1f,%.1f)(%.1f,%.1f)\n",
          (double)m2[0],(double)m2[1],(double)m2[2],(double)m2[3], (double)m2[4],(double)m2[5],(double)m2[6],(double)m2[7],
          (double)m2[12],(double)m2[13],(double)m2[14],(double)m2[15],
          (double)rvx[0].f,(double)rvy[0].f,(double)rvx[1].f,(double)rvy[1].f,(double)rvx[2].f,(double)rvy[2].f,(double)rvx[3].f,(double)rvy[3].f);
      }
      std::fprintf(stderr, "[hkdup2] === end dump ===\n");
    }
  }
  g_anyRender = true;  // g.image now holds this frame in TRANSFER_SRC_OPTIMAL (RVK_WINDOW blit source)
  g_hkLastRendered = rendered;  // export accepted-quad count for RVK_SKIPEMPTY (see note above renderHookedFrame)
  void* map = nullptr; VKC(vkMapMemory(g.dev, g.readbackMem, 0, VK_WHOLE_SIZE, 0, &map), "map(hk)");
  // RVK_PNGEVERY: rate-limit the per-frame rvk_last.png encode (the ~2.7MB PNG dominates per-present
  // wall-time and throttles the guest to ~6fps, which desyncs wall-clock nav timing from the Linux
  // reference). Writing every Nth frame lets the boot run closer to real-time.
  // DEFAULT OFF (2026-07-16): these are DIAGNOSTIC captures, and defaulting them ON throttled the
  // SHIPPING path ~10x (60 -> ~6fps) on exactly the screens whose pacing must match the original —
  // boot/title/menus/attract all present via this hook path (field frames divert to the legacy spine,
  // whose own rvk_last refresh is already capped at 1.5s). The peak/menu captures below hitch the same
  // frames (a new peak fires repeatedly while a screen animates in), so they share the gate: unset
  // RVK_PNGEVERY => no diagnostic PNG encode at all. Set RVK_PNGEVERY=N when capturing (N=24/300 are
  // the usual drive-script values) and peak/menu capture comes back with it.
  static int pngEvery = getenv("RVK_PNGEVERY") ? atoi(getenv("RVK_PNGEVERY")) : 0;
  static bool pngCap = pngEvery > 0;
  if (pngCap && (thisf % pngEvery) == 0) writePng("/tmp/rvk_last.png", (const uint8_t*)map, kW, kH);
  // RVK_LUMATRACE (2026-07-25 flash-regression instrument, DEFAULT OFF). The user reports the
  // shell intro/menus "flashing, doesn't stop" while [fps] still reads a healthy 59.9 presents/sec
  // -- i.e. a CONTENT-level alternation, not a pacing collapse. PrintWindow burst capture cannot
  // measure that: it samples at ~5fps and intermittently blocks on this very window. This probe
  // reports, for EVERY presented hook frame, the mean luma of the image actually handed to the
  // swapchain plus the accepted-quad count that produced it -- a true 60Hz content trace.
  // Cost: a 16x16-subsampled read of an already-mapped buffer (~3.6k byte reads) + one stderr
  // line per frame. Emitted on ONE line so a blinking layer shows up as an alternating `q=` count
  // next to an alternating `mean=`, which names the dropout without a RenderDoc capture.
  static bool lumaTrace = getenv("RVK_LUMATRACE") != nullptr;
  if (lumaTrace) {
    const uint8_t* pb = (const uint8_t*)map; unsigned long sum = 0; int cnt = 0;
    for (uint32_t y = 0; y < kH; y += 16) for (uint32_t x = 0; x < kW; x += 16) {
      const uint8_t* px = pb + ((size_t)y * kW + x) * 4; sum += px[0] + px[1] + px[2]; cnt++; }
    std::fprintf(stderr, "[luma] f%ld mean=%.2f q=%d/%d verts=%u\n",
                 thisf, cnt ? (double)sum / (cnt * 3) : 0.0, rendered, nDraws, nv);
  }
  // RT_HKTRACE peak-capture: keep a copy of the frame with the MOST rendered quads. The menu
  // animates in and (with confirming nav input) gets navigated away, so the fullest menu is a
  // transient — this grabs it regardless of wall-clock sampling / nav timing.
  // Gated by its OWN env (RVK_PNGPEAK, default off) rather than sharing RVK_PNGEVERY: `rendered`
  // climbs monotonically while any screen animates in, so "write on every new peak" fires almost
  // every frame during boot — that storm, not the periodic write, is what drags a capture run to
  // ~6fps even at RVK_PNGEVERY=30. Keeping them separate makes a periodic capture nearly free, which
  // matters now that nav scripts are timed against real (unthrottled) pacing.
  static bool pngPeak = getenv("RVK_PNGPEAK") != nullptr;
  static int hkPeak = 0;
  if (pngPeak && rendered > hkPeak) { hkPeak = rendered; writePng("/tmp/rvk_peak.png", (const uint8_t*)map, kW, kH);
    std::fprintf(stderr, "[rvk][hook] NEW PEAK %d quads -> rvk_peak.png\n", rendered); }
  // Menu-band capture: the CLEAN single-frame TOP MENU is ~95-140 quads on a DARK-BLUE background,
  // whereas the title screen (similar quad count) has a BRIGHT sky. Gate on darkness (mean luma of a
  // subsample) to capture the menu and exclude the title. Keep the fullest qualifying dark frame.
  static int hkMenu = 0;
  if (pngPeak && rendered >= 95 && rendered <= 150 && rendered > hkMenu) {
    const uint8_t* pb = (const uint8_t*)map; unsigned long sum = 0; int cnt = 0;
    for (uint32_t y = 0; y < kH; y += 16) for (uint32_t x = 0; x < kW; x += 16) {
      const uint8_t* p = pb + ((size_t)y * kW + x) * 4; sum += p[0] + p[1] + p[2]; cnt++; }
    double mean = cnt ? (double)sum / (cnt * 3) : 0.0;
    (void)mean; hkMenu = rendered; writePng("/tmp/rvk_menu.png", pb, kW, kH);
    std::fprintf(stderr, "[rvk][hook] MENU-BAND %d quads mean=%.1f -> rvk_menu.png\n", rendered, mean);
    // RT_HKDUP: dump the EXACT quad list that produced THIS rvk_menu.png (texture base + vertex-0
    // NDC position), un-deduped, so duplicate (texture,position) pairs are visible directly.
    if (hkdup) {
      std::fprintf(stderr, "[hkdup] === rvk_menu.png source dump: %zu accepted quads ===\n", hkdupRows.size());
      for (size_t i = 0; i < hkdupRows.size(); ++i) {
        const HkDupRow& r = hkdupRows[i];
        std::fprintf(stderr, "[hkdup] i=%zu tex=0x%07X %ux%u ndc_bbox=[%.3f,%.3f]x[%.3f,%.3f] uv_bbox=[%.3f,%.3f]x[%.3f,%.3f] a=[%.2f,%.2f] blend=0x%08X\n",
          i, r.tex, r.tw, r.th, (double)r.bx0, (double)r.bx1, (double)r.by0, (double)r.by1,
          (double)r.bu0, (double)r.bu1, (double)r.bv0, (double)r.bv1, (double)r.ba0, (double)r.ba1, r.blend);
      }
      std::fprintf(stderr, "[hkdup] === end dump ===\n");
    }
  }
  vkUnmapMemory(g.dev, g.readbackMem);
  return true;
}

// RVK_SLOWPRESENT=<ms> (2026-07-27, FNF-5 tick/present-coupling falsifier, default-off): sleep
// N ms inside every present CALL, on the calling guest thread — a controlled render slowdown.
// With RT_TICKRATE=1: if guest ticks/s drops in proportion, guest logic is welded to the present
// path (the panel's correctness-class defect, proven); if ticks hold 60/s, the clock is decoupled
// on this path. Test instrument only — never ship-on.
static void rvkSlowPresentMaybe() {
  static int ms = std::getenv("RVK_SLOWPRESENT") ? atoi(std::getenv("RVK_SLOWPRESENT")) : 0;
  if (ms > 0) std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

extern "C" void rvk_present_hooked(uint8_t* base, const uint32_t* vpool, uint32_t vpoolDwords,
                                   const RvkHookDraw* draws, int nDraws) {
  rvkSlowPresentMaybe();
  std::lock_guard<std::mutex> lk(g_mtx);
  if (g.failed) return;
  if (!g.ok && !initVk()) {
    std::fprintf(stderr, "[rvk] init failed (hooked); disabling\n"); g.failed = true;
    // ★ 2026-07-27 survivability: a hooked run whose renderer never comes up is an invisible,
    // unexitable process — die loudly instead (RVK_DIEHARD=1 keeps the old disabled-run).
    if (!rvkDiehardOn()) rvkDieLoud("Vulkan init failed on the hooked path (no renderer will ever come up)", 5);
    return;
  }
  rvkTestDieMaybe();
  if (g.failed) return;
  g_base = base;  // getTexture()/be32() read guest texture memory through g_base; the hooked path
                  // never goes through rvk_present() (which sets it), so set it here or getTexture
                  // dereferences a null g_base (crash at the literal guest texture address).
  rvk_fps_tick("hook");
  renderHookedFrame(base, vpool, vpoolDwords, draws, nDraws);
  // RVK_SKIPEMPTY=N: skip the window present for any hook frame that rendered FEWER THAN N quads
  // (holds the last good frame -> kills the navy flash from the shell's 0-draw partial presents,
  // confirmed via RT_HKTRACE: 0/0 frames present the navy clear). Unset/<=0 = present always
  // (byte-identical); =1 skips only zero-draw frames. On-screen window only; readback/PNG untouched.
  static int skipEmptyN = std::getenv("RVK_SKIPEMPTY") ? std::atoi(std::getenv("RVK_SKIPEMPTY")) : 0;
  static bool presentTrace = std::getenv("RVK_PRESENTTRACE") != nullptr;
  if (presentTrace) {
    uint32_t fa = g_base ? __builtin_bswap32(*(const uint32_t*)(g_base + GA_FIELD_ACTIVE)) : 0;
    std::fprintf(stderr, "[present] src=HOOK hkRich=%d field_active=%u %s\n",
      g_hkLastRendered, fa, (skipEmptyN > 0 && g_hkLastRendered < skipEmptyN) ? "SKIP" : "present");
  }
  if (skipEmptyN <= 0 || g_hkLastRendered >= skipEmptyN) rvkWindowPresent();  // RVK_WINDOW on-screen present
}

// ---- Async render worker (2026-07-17 attract-smoothness) --------------------------------------
// The full legacy walk+render costs ~75-135ms; run INLINE on the present path it either serializes
// the shell loop (game logic ~10-13Hz, the original 6-10x-slow attract) or — under the render
// budget — leaves the screen a 0.5Hz slideshow. This worker takes the whole renderFrameReal off
// the present thread: presents run at the vblank rate ALWAYS, and frames render back-to-back as
// fast as they cost (~13Hz today, rises as the walk gets cheaper). Publishing: the worker's last
// act per frame blits (tonemapped under HDR) the completed g.image into g.imageShow under g_mtx;
// the present thread's fast path blits ONLY imageShow, so no half-rendered frame is ever shown.
// The worker reads live guest memory exactly like the old inline walk did (same race class —
// the guest's other threads keep running either way). RVK_ASYNCRENDER=0 reverts to inline.
static bool rvkAsyncPublishShow() {   // caller holds g_mtx; g.image is TRANSFER_SRC
  if (!g.ok || g.failed) return false;
  segBatchFlush();
  rvkRingNext("show"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(show)");
  VkCommandBufferBeginInfo bi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; bi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
  VKC(vkBeginCommandBuffer(g.cmd, &bi), "begin(show)");
  VkImage src = g.image;
  if (rvk_hdr()) { recordTonemapToLdr(g.cmd); src = g.imageLdr; }
  VkImageMemoryBarrier b{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER};
  b.srcQueueFamilyIndex = b.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
  b.image = g.imageShow; b.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  b.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED; b.newLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
  // srcStage TRANSFER + srcAccess READ|WRITE: the present thread's swapchain blit READS imageShow
  // from earlier submissions on this same queue (its fence wait is deferred in async mode) — this
  // execution dependency keeps the overwrite ordered after those reads.
  b.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT | VK_ACCESS_TRANSFER_WRITE_BIT; b.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
  vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b);
  VkImageBlit bl{};
  bl.srcSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1}; bl.srcOffsets[1] = {(int32_t)kW, (int32_t)kH, 1};
  bl.dstSubresource = bl.srcSubresource;                    bl.dstOffsets[1] = {(int32_t)kW, (int32_t)kH, 1};
  vkCmdBlitImage(g.cmd, src, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, g.imageShow, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &bl, VK_FILTER_NEAREST);
  b.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL; b.newLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
  b.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT; b.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
  vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b);
  VKC(vkEndCommandBuffer(g.cmd), "end(show)");
  VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
  vkResetFences(g.dev, 1, &g.fence);
  VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(show)");
  rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull);
  g_showReady.store(true, std::memory_order_release);
  return true;
}
struct RwJob { long f; uint32_t start, end; uint8_t* base; };
static std::mutex* g_rwMtx = new std::mutex;
static std::condition_variable* g_rwCv = new std::condition_variable;
// Window QUEUE (2026-07-17 state-continuity fix): the old 1-deep latest-wins slot DROPPED whole
// PM4 windows whenever the worker was mid-frame — and dropped windows lose REGISTER STATE (VTE
// writes, ALU-constant uploads like the vs=48 c255 screen transform), which the walker contract
// says accumulates across every present ("walk the PM4 window (always ...)"). The queue keeps
// every window: the worker STATE-WALKS backlogged windows in order (shadow walk, GPU-free) and
// fully renders the newest. Bounded at 8 (~135ms of ring history; the kickseg/vtxsnap rings hold
// well over that) — overflow drops the OLDEST with a warn, which only happens if the worker
// wedges. Steady-state drain is 1 window = every window rendered = content at present rate.
static std::deque<RwJob> g_rwQueue;
static void rvkAsyncDispatch(long f, uint32_t start, uint32_t end, uint8_t* base) {
  static bool started = false;
  {
    std::lock_guard<std::mutex> l(*g_rwMtx);
    if (!started) {
      started = true;
      std::thread([] {
        // RVK_TESTCRASH=1 (default-off): AV on the worker thread — positive control for
        // rvkCrashFilter (models the silent playtest death; worker has no SEH containment).
        if (std::getenv("RVK_TESTCRASH") && atoi(std::getenv("RVK_TESTCRASH")) != 0)
          { volatile int* p = nullptr; *p = 1; }
#ifdef _WIN32
        // ★ 2026-07-27 transition-spike leg: the 250-260ms transition frames are PREEMPTION,
        // not work — every internal cost measured small (decode 17ms, uploads 4-8, pipelines 1,
        // fences 12) while wall time balloons exactly when the guest's asset-loader threads
        // burst (stage/panel loads). Above-normal priority keeps the render worker scheduled
        // through the burst. RVK_WORKERPRIO=0 reverts to normal priority.
        { static bool prioOff = std::getenv("RVK_WORKERPRIO") && atoi(std::getenv("RVK_WORKERPRIO")) == 0;
          if (!prioOff) SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_ABOVE_NORMAL); }
#endif
        for (;;) {
          std::deque<RwJob> drain;
          { std::unique_lock<std::mutex> l2(*g_rwMtx); g_rwCv->wait(l2, [] { return !g_rwQueue.empty(); });
            // ★ NO-COALESCE DRAIN (2026-07-27 judder rev 3, DEFAULT-OFF since same evening):
            // the swap-everything drain renders ONLY the newest window and state-walks the
            // rest, so a 2-window burst permanently drops a frame ([pace] skips+repeats).
            // Rendering every window instead REGRESSED (playtest_0727_1942): the "worker cost
            // 4.6ms, headroom was never the problem" premise was a MENU-phase reading —
            // in-stage render is 17-19ms (> 16.6ms budget: decode 5-14ms + ~10 fence
            // waits/frame), so the queue backs up to ages 4+ and guest ticks starve to 42/s.
            // Until worker render cost is under budget, coalescing IS the pacing mechanism.
            // RVK_NOCOALESCE=1 re-enables (with RVK_COALESCE_AT depth cap) for A/B only.
            static bool noCoal = std::getenv("RVK_NOCOALESCE") && atoi(std::getenv("RVK_NOCOALESCE")) != 0;
            static size_t coalAt = std::getenv("RVK_COALESCE_AT") ? (size_t)atoi(std::getenv("RVK_COALESCE_AT")) : 4;
            if (noCoal && g_rwQueue.size() <= coalAt) { drain.push_back(g_rwQueue.front()); g_rwQueue.pop_front(); }
            else drain.swap(g_rwQueue); }
          {
            // [wperf] worker-cycle attribution (2026-07-27 perf leg, always-on-lite): lock wait +
            // walks + render + publish per drain; periodic summary every 300 drains and an
            // IMMEDIATE line for any drain >133ms (the queue-overflow/stall threshold) naming
            // where the time went — the stall class finally gets a face when it happens.
            auto wt0 = std::chrono::steady_clock::now();
            std::lock_guard<std::mutex> lk(g_mtx);
            auto wt1 = std::chrono::steady_clock::now();
            if (g.ok && !g.failed) {
              for (size_t i = 0; i + 1 < drain.size(); ++i) {   // backlog: state-only walks, in order
                g_base = drain[i].base;
                renderFrameReal(-1000000, drain[i].start, drain[i].end, false);
              }
              auto wt2 = std::chrono::steady_clock::now();
              RwJob& j = drain.back();
              g_base = j.base;
              renderFrameReal(j.f, j.start, j.end, false);
              auto wt3 = std::chrono::steady_clock::now();
              rvkAsyncPublishShow();
              { std::lock_guard<std::mutex> sl(*g_showMtx);
                g_showFrame.store(j.f, std::memory_order_release); }   // [pace] frame identity
              g_showCv->notify_all();
              auto wt4 = std::chrono::steady_clock::now();
              { double t = std::chrono::duration<double, std::milli>(wt4 - wt0).count();
                uint32_t e = g_workerCostMs10.load(std::memory_order_relaxed);
                g_workerCostMs10.store((uint32_t)(0.9 * e + 0.1 * t * 10.0), std::memory_order_relaxed); }
              double msLock = std::chrono::duration<double, std::milli>(wt1 - wt0).count();
              double msWalk = std::chrono::duration<double, std::milli>(wt2 - wt1).count();
              double msRend = std::chrono::duration<double, std::milli>(wt3 - wt2).count();
              double msPub  = std::chrono::duration<double, std::milli>(wt4 - wt3).count();
              double msTot  = std::chrono::duration<double, std::milli>(wt4 - wt0).count();
              static double aL=0, aW=0, aR=0, aP=0, aT=0; static long aN=0, aD=0;
              aL+=msLock; aW+=msWalk; aR+=msRend; aP+=msPub; aT+=msTot; aN++; aD+=(long)drain.size();
              static std::atomic<long> rw{0}; long r = rw.fetch_add(1) + 1;
              if (msTot > 133.0)
                std::fprintf(stderr, "[wperf] SLOW drain #%ld (f%ld): tot=%.1fms lock=%.1f walks=%.1f(x%zu) render=%.1f publish=%.1f\n",
                             r, j.f, msTot, msLock, msWalk, drain.size()-1, msRend, msPub);
              if (r <= 3 || (r % 300) == 0) {
                std::fprintf(stderr, "[rvk][async] worker frame #%ld (f%ld, drained %zu) | [wperf] avg over %ld: tot=%.1fms lock=%.1f walks=%.1f render=%.1f publish=%.1f drained=%.2f\n",
                             r, j.f, drain.size(), aN, aT/aN, aL/aN, aW/aN, aR/aN, aP/aN, (double)aD/aN);
                aL=aW=aR=aP=aT=0; aN=aD=0;
              }
            }
          }
        }
      }).detach();
    }
    g_rwQueue.push_back(RwJob{f, start, end, base});
    // Depth 24 (2026-07-27 worker perf leg, was 8): a measured 250-263ms transition render
    // backlogs ~15 windows — depth 8 dropped 7 of them (register skew). With WALK-LITE a
    // backlog walk is register-only (~sub-ms), so a burst drains in one cycle. Ceiling set by
    // the kickseg ring (6MB / 192KB per-window cap ≈ 31 windows of guaranteed history) — 24
    // keeps margin; deeper would let walks read recycled ring segments (worse than dropping).
    if (g_rwQueue.size() > 24) {
      g_rwQueue.pop_front();
      static long ovf = 0;
      if ((ovf++ % 300) == 0) std::fprintf(stderr, "[rvk][async] WARN window queue overflow (worker stalled?) — oldest window dropped, register state may skew\n");
    }
  }
  g_rwCv->notify_one();
}
extern "C" void rvk_present(uint8_t* base, uint32_t frame_start, uint32_t frame_end) {
  rvkSlowPresentMaybe();
  // ---- async fast path: MUST run before g_mtx (the worker holds it for ~75-135ms per frame).
  // Everything here is lock-free: env statics, the frame counter, guest-memory reads, and the
  // window blit of the worker-published imageShow (queue ops sync via g_qMtx internally).
  static bool asyncRender = !(std::getenv("RVK_ASYNCRENDER") && atoi(std::getenv("RVK_ASYNCRENDER")) == 0);
  {
    static long rbudgetEnvA = std::getenv("RVK_RENDERBUDGET_MS") ? std::atol(std::getenv("RVK_RENDERBUDGET_MS")) : -1;
    static bool everyA = std::getenv("RVK_EVERY") != nullptr;
    static bool passthroughA = std::getenv("RVK_PASSTHROUGH") != nullptr;
    uint32_t faA = base ? __builtin_bswap32(*(const uint32_t*)(base + GA_FIELD_ACTIVE)) : 0;
    long rbudgetA = rbudgetEnvA >= 0 ? rbudgetEnvA
                  : (g_rt_romactive != 0 && faA == 0) ? (asyncRender ? 8 : 2000) : 0;
    // ★ RVK_DECOUPLE (2026-07-27, FNF-5 frame-boundary decoupling; DEFAULT FLIPPED **ON**
    // 2026-07-29 after the user's input-feel acceptance on the decoupled env): the welded clock
    // is the faA exclusion above — IN-STAGE (field active) rbudgetA resolves 0, so the full
    // render runs INLINE inside the guest logic loop (update → render → vblank-gate) and the
    // simulation rate becomes a function of render cost (measured 07-27: 54.7-55/s in-stage,
    // 8-9% slow; RVK_SLOWPRESENT drags ticks in lockstep). =1 forces the async-worker path in
    // ALL phases including in-stage — the present call becomes enqueue+blit, the vblank gate
    // (wall-clock 60Hz, RT_VBISR) paces logic, the worker absorbs render cost. =0 forces inline
    // everywhere (bidirectional A/B). Overrides both RVK_RENDERBUDGET_MS and the faA phase gate.
    // DEFAULT (2026-07-29 flip): decoupled = 1. `RVK_DECOUPLE=0` still forces inline everywhere
    // (the revert lever). The unset default deliberately still HONORS the two legacy inline pins —
    // `RVK_ASYNCRENDER=0` and `RVK_RENDERBUDGET_MS=0` — so every forensic/instrument script that
    // pins them (fnf1/fnf2/fnf5/fnf7/d1b_*/qa_dieloud/port_rdc_strip2) keeps its inline semantics
    // unchanged; only envs with NO pin at all (the ship envs, now stripped) get the new default.
    static int decouple = std::getenv("RVK_DECOUPLE") ? atoi(std::getenv("RVK_DECOUPLE"))
                        : ((asyncRender && rbudgetEnvA != 0) ? 1 : 0);
    if (decouple == 1) rbudgetA = 8; else if (decouple == 0) rbudgetA = 0;
    // rbudgetA now only SELECTS async mode (>0) — dispatch pacing moved to the window queue
    // (every window enqueued for state continuity; the worker renders the newest per drain).
    if ((asyncRender || decouple == 1) && !passthroughA && !everyA && rbudgetA > 0 && g.ok && !g.failed) {
      long f = g_frame.fetch_add(1);
      rvk_fps_tick("fast");   // distinct tag (2026-07-27): fast-path presents vs inline "legacy"
      static uint32_t maxWinA = std::getenv("RVK_MAXWINDOW") ? (uint32_t)std::strtoul(std::getenv("RVK_MAXWINDOW"), nullptr, 16) : 0x40000u;
      bool winOk = frame_start && frame_end > frame_start && frame_end - frame_start <= maxWinA;
      // decoupling diagnostics (2026-07-27): prove where in-stage presents flow — fast-path
      // liveness incl. field flag, and any window the dispatch drops as oversized.
      { static long fpN = 0; long q = ++fpN;
        if (q <= 3 || (q % 300) == 0)
          std::fprintf(stderr, "[rvk][fast] present#%ld f%ld field=%u winOk=%d winsz=0x%X\n",
                       q, f, faA, (int)winOk, frame_end - frame_start);
        if (!winOk) { static long badN = 0;
          if ((badN++ % 120) == 0)
            std::fprintf(stderr, "[rvk][fast] WARN win NOT dispatched (start=0x%X end=0x%X sz=0x%X max=0x%X)\n",
                         frame_start, frame_end, frame_end - frame_start, maxWinA); } }
      // EVERY winOk window is enqueued (2026-07-17 state-continuity): the walker's register/const
      // shadow only stays correct if every window is walked in order — the worker state-walks any
      // backlog and renders the newest (see g_rwQueue). No rate gate: pacing is the drain policy.
      if (winOk) rvkAsyncDispatch(f, frame_start, frame_end, base);
      // paced handoff (see g_showMtx block above): wait briefly for frame f-LAT before blitting.
      // LAT is ADAPTIVE with hysteresis (2026-07-27 rev 2): a fixed f-1 target flapped between
      // age-1 and age-2 when render cost neared the 16.7ms grid ([pace] 150/140 mixed) — mixed
      // ages ARE the judder. Fast worker (<14.5ms EWMA) → LAT 1; near-budget (>15.5ms) → LAT 2
      // (steady one-extra-frame latency with EVEN delivery beats oscillation). Over-budget
      // (>17ms) → no wait (content already dropping; never tax the tick). RVK_PACE=0 reverts.
      { static int paceMode = std::getenv("RVK_PACE") ? atoi(std::getenv("RVK_PACE")) : 1;
        uint32_t c10 = g_workerCostMs10.load(std::memory_order_relaxed);
        static long curLat = 1;
        if (c10 > 155) curLat = 2; else if (c10 < 145) curLat = 1;
        if (paceMode == 1 && g_showReady.load(std::memory_order_acquire) && c10 < 170) {
          long want = f - curLat;
          if (g_showFrame.load(std::memory_order_acquire) < want) {
            std::unique_lock<std::mutex> sl(*g_showMtx);
            g_showCv->wait_for(sl, std::chrono::milliseconds(8),
                               [&]{ return g_showFrame.load(std::memory_order_acquire) >= want; });
          } } }
      // [pace] (2026-07-27 judder leg, user-verified vs SDK): quantify frame DELIVERY, not
      // frame count — per present, the age of the shown frame (f - shownFrame), plus repeats
      // (same frame shown twice) and skips (frames never shown). Even 100% average content
      // can judder if delivery is uneven. Every-300 histogram; always on (few atomics).
      { long s = g_showFrame.load(std::memory_order_acquire);
        static long lastS = -1; static long hist[9] = {0}; static long reps = 0, skips = 0, pN = 0;
        long age = s >= 0 ? f - s : 0; if (age < 0) age = 0; if (age > 8) age = 8;
        // ★ RVK_SHOWSEQ (C3-s1 alternation hunt, 2026-07-28): per-present sequence — shown
        // generation + age, presents [from, from+200). The glass A/B/A = shown-gen alternating;
        // this names whether it's the 8ms wait losing every other present or curLat flapping.
        { static long ssFrom = std::getenv("RVK_SHOWSEQ") ? std::strtol(std::getenv("RVK_SHOWSEQ"), nullptr, 10) : -1;
          static long ssN = 0;
          if (ssFrom >= 0 && ++ssN >= ssFrom && ssN < ssFrom + 200)
            std::fprintf(stderr, "[showseq] p%ld f=%ld shown=%ld age=%ld\n", ssN, f, s, age); }
        hist[age]++;
        if (s >= 0 && lastS >= 0) { if (s == lastS) reps++; else if (s - lastS >= 2) skips += (s - lastS - 1); }
        lastS = s;
        if (++pN % 300 == 0) {
          std::fprintf(stderr, "[pace] p%ld age{1:%ld 2:%ld 3:%ld 4+:%ld} repeats=%ld skips=%ld\n",
                       pN, hist[1], hist[2], hist[3], hist[4]+hist[5]+hist[6]+hist[7]+hist[8], reps, skips);
          for (int i = 0; i < 9; i++) hist[i] = 0; reps = 0; skips = 0;
        } }
      rvkWindowPresent(true);
      return;
    }
  }
  std::lock_guard<std::mutex> lk(g_mtx);
  if (g.failed) return;
  if (!g.ok && !initVk()) {
    std::fprintf(stderr, "[rvk] init failed; disabling\n");
    // ★ 2026-07-27 survivability: same as the hooked path — no renderer will ever come up.
    if (!rvkDiehardOn()) rvkDieLoud("Vulkan init failed on the legacy path (no renderer will ever come up)", 5);
    return;
  }
  rvkTestDieMaybe();
  if (g.failed) return;
  g_base = base;
  rvk_fps_tick("legacy");
  // decoupling diagnostics (2026-07-27): mirror of [rvk][fast] — which presents run INLINE and why
  { static long inN = 0; long q = ++inN;
    if (q <= 3 || (q % 300) == 0) {
      uint32_t faI = base ? __builtin_bswap32(*(const uint32_t*)(base + GA_FIELD_ACTIVE)) : 0;
      std::fprintf(stderr, "[rvk][inline] present#%ld field=%u win=[0x%X,0x%X) sz=0x%X\n",
                   q, faI, frame_start, frame_end, frame_end - frame_start); } }
  rvkServiceInvalidations();   // CODE_REVIEW_0804: before this path's white guards (swap reset rebuilds them)
  bool passthrough = std::getenv("RVK_PASSTHROUGH") != nullptr;
  if (passthrough && !g.white.set) {
    ((uint32_t*)g.stagingMap)[0] = 0xFFFFFFFFu;
    if (!uploadTexToDesc(1, 1, g.white)) { g.failed = true; return; }
  }
  if (!passthrough && g.rNextTexIndex == 1 && g.rTexRecords.empty()) {
    // build the bindless white texture once (fixed index 0, per design doc)
    ((uint32_t*)g.stagingMap)[0] = 0xFFFFFFFFu;
    RTex wt{};
    if (!uploadTexToBindless(1, 1, wt)) { g.failed = true; return; }
    g.rTexRecords.push_back(wt);
    VkDescriptorImageInfo dii{VK_NULL_HANDLE, wt.view, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL};
    VkWriteDescriptorSet wr{VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET};
    wr.dstSet = g.rSets[0]; wr.dstBinding = 0; wr.dstArrayElement = 0; wr.descriptorCount = 1;
    wr.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE; wr.pImageInfo = &dii;
    vkUpdateDescriptorSets(g.dev, 1, &wr, 0, nullptr);
  }

  long f = g_frame.fetch_add(1);
  static bool every = std::getenv("RVK_EVERY") != nullptr;
  static std::vector<long> wantFrames = [] {
    std::vector<long> v;
    if (const char* s = std::getenv("RVK_FRAMES")) {
      while (*s) { char* e = nullptr; long x = std::strtol(s, &e, 10); if (e == s) break; v.push_back(x); s = (*e == ',') ? e + 1 : e; }
    }
    if (v.empty()) v = {8, 16, 24, 40, 60};
    return v;
  }();
  bool sampled = every || std::find(wantFrames.begin(), wantFrames.end(), f) != wantFrames.end();
  if (passthrough && !sampled) return;
  // sanity on the frame window. The default 256KB cap rejects the FIELD kick-arena (bigger than the
  // menu's), which blocked RVK_ARENADUMP from ever seeing a field frame. RVK_MAXWINDOW raises it for
  // capture runs (e.g. 0x800000). Default unchanged so normal runs are byte-identical.
  static uint32_t maxWin = std::getenv("RVK_MAXWINDOW") ? (uint32_t)std::strtoul(std::getenv("RVK_MAXWINDOW"), nullptr, 16) : 0x40000u;
  if (!frame_start || frame_end <= frame_start || frame_end - frame_start > maxWin) {
    if (sampled) std::fprintf(stderr, "[rvk] frame%ld: bad window [0x%X,0x%X) — skipping\n", f, frame_start, frame_end);
    return;
  }
  // RVK_RENDERBUDGET_MS=<n> (2026-07-17 attract-pacing fix): the FULL legacy decode+render costs
  // 60-100ms during ROM scenes (measured [perflog]: decode ~16-20ms + render tail ~45ms), and the
  // shell's per-present frame tick is the game's msg-5 LOGIC CLOCK — so game logic ran at render
  // speed (~10-13 presents/s -> attract task family 6-10 ticks/s = the whole attract 6-10x slow
  // vs the SDK oracle). With a budget, presents arriving within n ms of the last full render SKIP
  // the decode+render and re-present the previous image: the present cadence (and the logic
  // clock riding it) runs at full rate while frames render as often as the budget allows —
  // console-accurate TIMING with frame-skipped rendering. Sampled/diagnostic frames still render.
  // Default (2026-07-17 attract-1:1): 2000ms during the ROM ATTRACT only (g_rt_romactive set,
  // field not live). Measured at 2000: attract presents 57-58.3/s (vs 48-52 at 500, 10-13 at 0) and
  // filmstrip segment timings within ~1.1x of the SDK-oracle rdc frame numbers; the budget-elapse
  // frame's ~100ms walk+segment-render is the remaining loss. Menus/field keep no-budget behavior so gameplay
  // presents are untouched. RVK_RENDERBUDGET_MS always wins when set (0 disables everywhere).
  static long rbudgetEnv = std::getenv("RVK_RENDERBUDGET_MS") ? std::atol(std::getenv("RVK_RENDERBUDGET_MS")) : -1;
  uint32_t rbFieldActive = base ? __builtin_bswap32(*(const uint32_t*)(base + GA_FIELD_ACTIVE)) : 0;
  long rbudget = rbudgetEnv >= 0 ? rbudgetEnv
               : (g_rt_romactive != 0 && rbFieldActive == 0) ? 2000 : 0;
  if (!passthrough && rbudget > 0 && !sampled) {
    static std::chrono::steady_clock::time_point lastFull{};
    auto nowt = std::chrono::steady_clock::now();
    if (std::chrono::duration<double, std::milli>(nowt - lastFull).count() < (double)rbudget) {
      static std::atomic<long> skipped{0}; long sk = skipped.fetch_add(1) + 1;
      if (sk <= 3 || (sk % 1800) == 0) std::fprintf(stderr, "[rvk][budget] present f%ld re-presents last frame (#%ld skipped)\n", f, sk);
      rvkWindowPresent();
      return;
    }
    lastFull = nowt;
  }
  if (passthrough) renderFrameOld(f, frame_start, frame_end);
  else renderFrameReal(f, frame_start, frame_end, sampled);  // real path walks EVERY frame for state
  static bool presentTraceL = std::getenv("RVK_PRESENTTRACE") != nullptr;
  if (presentTraceL) {
    uint32_t fa = base ? __builtin_bswap32(*(const uint32_t*)(base + GA_FIELD_ACTIVE)) : 0;
    std::fprintf(stderr, "[present] src=LEGACY realRendered=%d realDraws=%d field_active=%u (g.image %s)\n",
      (int)g_realLastRendered, g_realLastDraws, fa, g_realLastRendered ? "OVERWRITTEN-this-frame" : "STALE-holds-last");
  }
  rvkWindowPresent();  // RVK_WINDOW: blit this frame to the on-screen window (no-op if off)
}

// RT_HYBRID (2026-07-12) state-continuity shim. renderFrameReal's PM4 packet walk is what keeps
// the persistent register shadow (g_regFile, ALU consts, VTE regs -- see the writeReg lambda
// above) warm; normally that walk runs on EVERY present via rvk_present() above (see its comment
// "real path walks EVERY frame for state"). Under hybrid routing, hookrender-routed (shell)
// presents never call rvk_present(), so without this the shadow would go stale/zero for anything
// the guest sets once and doesn't re-emit on the first legacy-routed gameplay frame. renderFrameReal
// with render=false is GPU-submission-free (see the doRender/wantLast gate: with RVK_RENDER_FROM
// unset it walks the packet stream -- including every writeReg -- and returns before touching the
// shared offscreen image, so this cannot clobber whatever rvk_present_hooked() just drew). We call
// renderFrameReal directly (not rvk_present()) so this doesn't perturb rvk_present's own g_frame /
// RVK_FRAMES sampling counters; a very-negative sentinel frame number keeps it out of range of any
// frame-indexed diagnostic (RVK_DEBUG_OPS / RVK_IBTRACE / RVK_DEBUG_OPS_FIELD) gates.
extern "C" void rvk_shadow_update(uint8_t* base, uint32_t start, uint32_t end) {
  std::lock_guard<std::mutex> lk(g_mtx);
  if (g.failed || !g.ok) return;   // only keep-warm once hookrender's own init has already run
  static uint32_t shMaxWin = std::getenv("RVK_MAXWINDOW") ? (uint32_t)std::strtoul(std::getenv("RVK_MAXWINDOW"), nullptr, 16) : 0x40000u;
  if (!start || end <= start || end - start > shMaxWin) return;
  g_base = base;
  renderFrameReal(-1000000, start, end, false);
}

extern "C" void rvk_shutdown(void) {
  std::lock_guard<std::mutex> lk(g_mtx);
  if (!g.ok) return;
  vkDeviceWaitIdle(g.dev);
  vkDestroyDevice(g.dev, nullptr);
  vkDestroyInstance(g.instance, nullptr);
  g.ok = false;
  std::fprintf(stderr, "[rvk] shutdown\n");
}

// ============================================================================
// ★ HARD PIVOT stage 1 (2026-07-28): nvk — the wrapper-altitude renderer.
// Input = an NvkFrame recorded by decomp/shell/nvk.cpp from the guest's own D3D wrapper calls
// (RT_NVK=2). No PM4 walking, no window inference, no persist heuristics — the frame is exactly
// the call stream: clear (guest colour), then one host draw per DrawVerticesUP, in order.
// Reuses the existing primitives only: initVk device/offscreen, bindless textures
// (getTexIndexReal), the baked shader table via matchImLoad (fed the microcode addresses read
// register-true from the bound shader objects — replaces IM_LOAD), getOrCreateRealPipeline,
// the BDA constants arena, and rvkWindowPresent. The old frame builder never runs at RT_NVK=2
// (rt.cpp Present short-circuit), so g.image/arena/staging are single-consumer here.
// This section lives in this TU because every primitive has internal linkage (anon namespace).
// ============================================================================
#include "nvk_api.h"

// ---- s2B leg 6: per-render-target host images ------------------------------------------------
// The guest's field/ROM passes bind their own EDRAM colour target (SetRenderTarget) before
// drawing, resolve it to a texture, and only the compose quads touch the screen. The single
// g.image model leaked those passes onto the visible frame (attract staircase). Each offscreen
// surface gets its own image+framebuffer (mirrors getOrCreateResolveTex; kept TRANSFER_SRC
// between passes = g.passLoad's declared initialLayout, valid don't-care for g.pass/CLEAR).
// Display-bound segments (surf == back buffer) keep rendering into g.image exactly as before.
struct NvkRT { VkImage image = VK_NULL_HANDLE; VkDeviceMemory mem = VK_NULL_HANDLE;
               VkImageView view = VK_NULL_HANDLE; VkFramebuffer fb = VK_NULL_HANDLE;
               uint32_t w = 0, h = 0;
               // s2B leg 9 class-B instrument: the guest identity of this target, carried so the
               // resolve site can name it (RT_NVKRTDUMP match + the [nvkfmt] format pair log).
               uint32_t surf = 0, info = 0, colorInfo = 0;
               // s2B leg 10 item 1: host colour format chosen from RB_COLOR_INFO.color_format, and
               // the {CLEAR,LOAD} pass pair that framebuffer/pipelines must agree with.
               VkFormat fmt = VK_FORMAT_UNDEFINED;
               VkRenderPass passClear = VK_NULL_HANDLE, passLoad = VK_NULL_HANDLE; };
static std::unordered_map<uint32_t, NvkRT> g_nvkRT;   // guest surface ptr -> host target
// ★ L5 module swap: drop the guest-surface->target map.  Keyed on a guest address, so a module
// swap invalidates every entry.  Like the rest of rvk_module_swap_invalidate's drops the targets
// themselves are intentionally leaked rather than destroyed under a possibly-in-flight worker
// (this map "never destroys the target it replaces" today anyway — see the comment at its use).
static size_t rvkSwapDropNvkRT() { size_t n = g_nvkRT.size(); g_nvkRT.clear(); return n; }
// CODE_REVIEW_0804: destroy variant, called only from rvkServiceInvalidations after
// vkDeviceWaitIdle. passClear/passLoad come from the shared per-format pass cache — NOT owned.
static size_t rvkSwapDestroyNvkRT() {
  size_t n = g_nvkRT.size();
  for (auto& kv : g_nvkRT) { NvkRT& t = kv.second;
    if (t.fb)    vkDestroyFramebuffer(g.dev, t.fb, nullptr);
    if (t.view)  vkDestroyImageView(g.dev, t.view, nullptr);
    if (t.image) vkDestroyImage(g.dev, t.image, nullptr);
    if (t.mem)   vkFreeMemory(g.dev, t.mem, nullptr); }
  g_nvkRT.clear();
  return n;
}
static NvkRT* getNvkRT(uint32_t surf, uint32_t w, uint32_t h, uint32_t sinfo, uint32_t scinfo) {
  auto it = g_nvkRT.find(surf);
  // Cache hit is keyed on (surf, w, h) only — colorInfo is DELIBERATELY not part of it. The map
  // never destroys the target it replaces, so every extra rebuild trigger is a leak trigger, and
  // the ring's cfmt is stable in the evidence (RB_COLOR_INFO = 0x00030710 on all 91 [nvkfmt]
  // lines of the t3 bank). If a surface is ever seen changing colour format in place, the
  // [nvkrt] create line is where that would show up.
  if (it != g_nvkRT.end() && it->second.w == w && it->second.h == h) return &it->second;
  // ★ REGISTER-TRUE TARGET FORMAT (s2B leg 10 item 1) — the ring's RB_COLOR_INFO says 7e3 float.
  // Falls back to g_rtFmt on the lever, under HDR, on an unlisted cfmt, or if the device can't
  // do the format; a pass-pair creation failure also falls back (never fatal).
  VkFormat wantFmt = nvkRtFormatFor(scinfo);
  NvkPassPair pp = nvkPassesFor(wantFmt);
  if (!pp.clear || !pp.load) { wantFmt = g_rtFmt; pp = nvkPassesFor(g_rtFmt); }
  NvkRT t{}; t.w = w; t.h = h; t.surf = surf; t.info = sinfo; t.colorInfo = scinfo;
  t.fmt = wantFmt; t.passClear = pp.clear; t.passLoad = pp.load;
  VkImageCreateInfo ii{VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO}; ii.imageType = VK_IMAGE_TYPE_2D; ii.format = wantFmt;
  ii.extent = {w, h, 1}; ii.mipLevels = 1; ii.arrayLayers = 1; ii.samples = VK_SAMPLE_COUNT_1_BIT; ii.tiling = VK_IMAGE_TILING_OPTIMAL;
  ii.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
  ii.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
  if (vkCreateImage(g.dev, &ii, nullptr, &t.image) != VK_SUCCESS) return nullptr;
  VkMemoryRequirements mr{}; vkGetImageMemoryRequirements(g.dev, t.image, &mr);
  VkMemoryAllocateInfo ai{VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO}; ai.allocationSize = mr.size;
  ai.memoryTypeIndex = findMem(mr.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
  if (vkAllocateMemory(g.dev, &ai, nullptr, &t.mem) != VK_SUCCESS) { vkDestroyImage(g.dev, t.image, nullptr); return nullptr; }
  vkBindImageMemory(g.dev, t.image, t.mem, 0);
  // clear to opaque black, park in TRANSFER_SRC (the between-passes steady state)
  segBatchFlush();
  rvkRingNext("nvkrtnew");   // CODE_REVIEW_0804 A3: see the twin comment in getOrCreateResolveTex
  vkResetCommandBuffer(g.cmd, 0);
  VkCommandBufferBeginInfo bi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO}; bi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT; vkBeginCommandBuffer(g.cmd, &bi);
  VkImageMemoryBarrier b{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER}; b.srcQueueFamilyIndex = b.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
  b.image = t.image; b.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  b.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED; b.newLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL; b.srcAccessMask = 0; b.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
  vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b);
  VkClearColorValue cc{}; cc.float32[3] = 1.f; VkImageSubresourceRange sr{VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  vkCmdClearColorImage(g.cmd, t.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, &cc, 1, &sr);
  b.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL; b.newLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL; b.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT; b.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
  vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b);
  vkEndCommandBuffer(g.cmd);
  VkSubmitInfo subi{VK_STRUCTURE_TYPE_SUBMIT_INFO}; subi.commandBufferCount = 1; subi.pCommandBuffers = &g.cmd;
  vkResetFences(g.dev, 1, &g.fence); rvkQueueSubmit(g.queue, 1, &subi, g.fence); rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 5000000000ull);
  VkImageViewCreateInfo iv2{VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO}; iv2.image = t.image; iv2.viewType = VK_IMAGE_VIEW_TYPE_2D; iv2.format = wantFmt; iv2.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
  vkCreateImageView(g.dev, &iv2, nullptr, &t.view);
  VkFramebufferCreateInfo fbi{VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO}; fbi.renderPass = t.passClear; fbi.attachmentCount = 1; fbi.pAttachments = &t.view; fbi.width = w; fbi.height = h; fbi.layers = 1;
  vkCreateFramebuffer(g.dev, &fbi, nullptr, &t.fb);
  std::fprintf(stderr, "[nvkrt] target surf=0x%X %ux%u created vkfmt=%d (guest RB_COLOR_INFO=%08X cfmt=%u)%s\n",
               surf, w, h, (int)wantFmt, scinfo, (scinfo >> 16) & 0xFu,
               nvkRing8On() ? " [RT_NVKRING8]" : (wantFmt == g_rtFmt ? "" : " REGISTER-TRUE"));
  return &(g_nvkRT[surf] = t);
}

// ★★ NVK COMPOSE CENSUS (2026-07-31, SHELL COMPOSE 1:1 leg on the CAMPAIGN renderer).
// BACKLOG #0 requires a MISSING-draw census (drawtrip/`[census]` on the legacy path only ever
// counted EXTRA draws, and the legacy census at :4337 is STRUCTURALLY DEAD under RT_NVK=2 —
// rt.cpp:2476 returns from Present before rt_render_maybe(), so renderFrameReal never runs).
// This is the same instrument re-hosted at the nvk altitude, where the frame is the guest's own
// wrapper-call stream (NvkFrame) instead of a decoded PM4 window.
//
// SCOPE: DISPLAY-target draws on SHELL frames (curRT == nullptr && GA_FIELD_ACTIVE == 0). An
// offscreen render target has its own recompose cadence, so mixing it into one clock would fake
// drops; offscreen content reaches the screen through composite quads, which ARE display draws.
// IDENTITY = (stage-0 texture base, vsIdx, psIdx). A steady identity (>= K consecutive censused
// frames) that vanishes for <= R frames and RETURNS = a one-frame-class DROPOUT (the user's
// multi-element transient flicker). Identities that never return are legit dismissals (dropped
// silently). Scene transitions (draw total jumps 3x either way) reset all streaks.
//
// ⚠ READ BEFORE BELIEVING A DROPOUT (2026-07-31 alpha2 cadence leg): a DROPOUT-CONFIRMED line
// says an identity vanished and came back — it does NOT say the guest misbehaved. The shell has
// AUTHORED hide-byte square waves (SPEC_shell_compose_1to1 §13), and this census cannot see them
// as such because its own K/R filters hide the surrounding rhythm. The PRESS START prompt is the
// worked example: its 2-on/2-off x7 burst reads here as 7 dropouts and is 100% authentic (the
// title item's post-accept D=2 strobe, 30 ticks, sub_821CBF58). ALWAYS pair a dropout with
// RVK_TITLEPROBE=1, which reports the identity's full run-length series with no thresholds — an
// authored square wave has regular runs, a real hole does not.
// LEVERS (all default OFF; counting only at level 1-2, nothing rendered differently):
//   RVK_DRAWCENSUS=1   census on (DROPOUT lines only)
//   RVK_DRAWCENSUS=2   + a [census] status heartbeat every 120 censused frames
//   RVK_DRAWCENSUS_K   steady threshold (default 8)   RVK_DRAWCENSUS_R  max gap (default 3)
//   RVK_CENSUSTEST=1   POSITIVE CONTROL A: stop COUNTING the longest-steady identity on every
//                      250th censused frame -> must print DROPOUT-CONFIRMED len=1
//   RVK_CENSUSTEST=2   POSITIVE CONTROL B: actually SKIP RENDERING those draws on the same
//                      cadence -> a genuine one-frame element dropout on glass (visible in a
//                      PNG dump) that the census must also catch. Test only, never ship-on.
// Lessons carried over from the 2026-07-28 legacy build (3 control failures): the injection
// target is the CURRENTLY longest-steady identity (a first-steady lock dies with its boot
// phase), injection runs on the census's OWN frame clock (frame%N is unreachable under pacing),
// and every injected frame is MARKED in the log (unmarked injections are indistinguishable from
// organic dropouts).
struct NvkCensusEnt {
  long streak = 0;        // consecutive censused frames seen
  int  cnt = 0;           // display draws counted this frame
  int  steadyCnt = 0;     // typical per-frame count while steady
  long missSince = -1;    // census clock when it went missing (-1 = present)
  long missStreak = 0;    // streak at the moment of loss (reported)
  int  missTotal = -1;    // display-draw total on the MISSING frame
  uint32_t base = 0; int vs = 0, ps = 0;
  float v0x = 0, v0y = 0; uint32_t vte = 0;
  // ★ ALIASING DISCRIMINATOR (2026-07-31): a guest that double-buffers an atlas would swap the
  // stage-0 base under the same element, and a (base,vs,ps) identity would read that as a
  // dropout. The roster of every identity present on the MISSING frame settles it: a twin base
  // carrying the vanished identity's draw count = aliasing (benign); no twin = a real hole.
  char missRoster[160] = {0};
  long missBuild = 0, missNoScratch = 0, missSpliced = 0;   // recorder counters on the MISSING frame
};
// Recorder-side per-frame drop/divert counters (decomp/shell/nvk.cpp). They answer the FIRST
// question a dropout raises: did the GUEST stop emitting the element, or did the RECORDER divert
// it into the static cmd-blob (build mode) / drop it for a null scratch?
extern "C" { extern long g_nvk_fBuild, g_nvk_fNoScratch, g_nvk_fSpliced; }
static std::unordered_map<uint64_t, NvkCensusEnt> g_ncMap;
static long g_ncPc = 0;              // censused-frame counter (the census clock)
static int  g_ncLastTotal = -1;      // scene-transition guard
static uint64_t g_ncTestKey = 0;     // fault-injection target (longest-steady identity)
static long g_ncDropouts = 0, g_ncClearMiss = 0, g_ncClearOk = 0;
static inline uint64_t nvkCensusKey(uint32_t base, int vs, int ps) {
  return ((uint64_t)base << 20) ^ ((uint64_t)(vs & 0x3FF) << 10) ^ (uint64_t)(ps & 0x3FF);
}

// ★★ RVK_TITLEPROBE — GLASS-SIDE HALF of the title cadence probe (2026-07-31 alpha2 leg).
// DEFAULT OFF; counting + printing only, nothing rendered differently.
//
// The census proper is a DROPOUT detector: it only speaks when an identity vanishes for <= R
// frames AND was steady for >= K frames first, so it is structurally blind to the very signal
// this leg needs — the AUTHENTIC blink, whose off-runs are ~20 frames (> R) and whose on-runs
// reset the streak below K. That blindness is exactly why the 2/2 post-accept strobe read as a
// "1 boot in 24 intermittent" when the guest does it on every boot (see the ledger). This
// tracker sits beside the census with NO thresholds at all: for each display identity it
// records the length of every PRESENT run and every ABSENT run, in censused frames, and prints
// one line per transition. Feed it a title hold and it must print run=20 / run=20 — the oracle
// cadence (SDK + Xbox 360, banked 07-21) — which is this instrument's POSITIVE CONTROL: an
// instrument that cannot see the known-true blink cannot be trusted about anything else.
// Entries are never erased on absence (that is the whole point), so it is capped hard.
//   RVK_TITLEPROBE=1  transition lines           RVK_TITLEPROBE=2  + per-frame roster line
//   RVK_TITLEPROBE_MIN  (default 2) minimum run length to report — 1 reports everything
struct TProbeEnt { uint64_t key = 0; uint32_t base = 0; int vs = 0, ps = 0;
                   int cnt = 0; int steady = 0; long run = 0; bool on = false; bool seen = false; };
static TProbeEnt g_tpEnt[24];
static int  g_tpN = 0;
static long g_tpLines = 0;
static inline int tprobeLvl() { static int v = std::getenv("RVK_TITLEPROBE") ? atoi(std::getenv("RVK_TITLEPROBE")) : 0; return v; }
static inline int tprobeMin() { static int v = std::getenv("RVK_TITLEPROBE_MIN") ? atoi(std::getenv("RVK_TITLEPROBE_MIN")) : 2; return v; }
static TProbeEnt* tprobeSlot(uint64_t key) {
  for (int i = 0; i < g_tpN; ++i) if (g_tpEnt[i].key == key) return &g_tpEnt[i];
  if (g_tpN >= (int)(sizeof g_tpEnt / sizeof g_tpEnt[0])) return nullptr;
  TProbeEnt* e = &g_tpEnt[g_tpN++]; e->key = key; return e;
}

// ===== COPY-AT-RECORD (2026-08-07) ======================================================
// THE DEFECT: our texture decode reads GUEST RAM at Present, but the guest issued the draw
// earlier in the frame and may free/recycle those bytes in between. On the char/shot select
// FIRST ENTRY that window lands on the streamed stone plates and they decode as grey noise.
// The 08-04 workaround was allocator quarantine (RT_FREEPOOL_QUAR_MS=250), which cures the eyes
// but FAILS the P7 512MB gate — measured 08-07: the streamer's ~16ms hot rotation is shorter
// than any quarantine long enough to cover our late read, so quarantine IS the climb engine.
// Ledger has the numbers.
//
// ⚠⚠ DEFAULT OFF (2026-08-07, same day): THIS DID NOT FIX THE MOTIVATING DEFECT. User A/B on the
// 360 select screens: corruption is IDENTICAL with the prefetch on and off, so read-time is not
// the variable. The premise it was built on was also stale — the ledger's "deferred walker reads
// ~50ms late" is WRONG for RT_NVK=2: nvk_frame_submit is called SYNCHRONOUSLY on the guest thread
// and this renderer has no async decoupling at all (BACKLOG item 1's 07-29 carry-forward already
// said so). Kept in-tree, levered OFF, because it is self-contained and is a one-env A/B
// instrument for any future staleness question — NOT because it is believed to help.
// Current lead suspect for that corruption is host texture/resolve IDENTITY keyed on guest base
// colliding under address reuse, which read-time cannot affect.
//
// WHY THIS IS A PREFETCH AND NOT AN ARENA: the decode+upload path (rvkUploadBindless, the
// `submit(rupl)` block) is fully self-contained — it fills g.staging, records a ONE_TIME_SUBMIT
// buffer on g.cmd, submits and WAITS on g.fence. It needs no render pass and no frame context.
// And nvk_frame_submit is called SYNCHRONOUSLY from the Present hook on the guest render thread
// (nvk has no async decoupling — RVK_DECOUPLE is inert under RT_NVK=2), so during the guest's
// frame g.cmd/g.staging are idle and the recorder and executor never race. Calling the executor's
// own decode at record time therefore costs no new memory, duplicates no decode logic, and needs
// no changes to the untile loops — the bytes simply get read while they are still live.
//
// COST IS BOUNDED BY CACHE MISSES, NOT DRAWS: getTexIndexReal returns immediately on a hit
// without touching guest RAM, so the steady state is one map lookup per draw. Only a texture
// being decoded for the FIRST time does work — which is exactly the window that corrupts.
//
// RT_NVKPREFETCH=0 reverts to the old read-at-Present behaviour.
extern "C" void nvk_tex_prefetch(uint32_t base, uint32_t w, uint32_t h, uint32_t fmt,
                                 uint32_t tf0, uint32_t blendReg, uint32_t tf3) {
  static int on = [] { const char* e = std::getenv("RT_NVKPREFETCH"); return e ? std::atoi(e) : 0; }();
  if (!on || !base || !w || !h) return;
  std::lock_guard<std::mutex> lk(g_mtx);
  // Never INITIALISE Vulkan from the recorder — if the device is not up yet, leave the decode to
  // nvk_frame_submit exactly as before. Prefetch is an optimisation of WHEN, never of WHETHER.
  if (!g.ok || g.failed) return;
  // A resolve-backed base samples the rendered resolve image, not guest RAM (getTexIndexReal
  // routes it on its first lookup) — there are no guest bytes to race, so skip it.
  if (g_resolveTex.count(base)) return;
  // Already resident: the executor will not read guest RAM for it again. This is the steady-state
  // early-out and it must mirror getTexIndexReal's own key exactly.
  if (g.rTexIndex.count(((uint64_t)base << 8) | fmt)) return;
  static long n = 0;
  if ((n++ % 500) == 0)
    std::fprintf(stderr, "[nvkprefetch] #%ld base=0x%X %ux%u fmt=%u (decode at record)\n",
                 n, base, w, h, fmt);
  getTexIndexReal(base, w, h, fmt, tf0, blendReg, tf3);
}

extern "C" void nvk_frame_submit(uint8_t* basePtr, NvkFrame* nf) {
  // ★ RT_PRESENT_THROTTLE_MS=<n> (08-12 tick/present lane, DIAGNOSTIC ONLY, default off):
  // sleep n ms per present on the guest render thread — simulates a slow GPU (Deck-class) so
  // the welded-vs-decoupled question is answerable on this fast box: if the [evt34] frame-grant
  // rate follows the throttled present rate, guest logic is welded to the present path.
  // ⚠ FIELD-GATED (08-12): only throttle when the GAMEPLAY FIELD is active — otherwise the slow
  // present breaks card-panel/menu FIFO input timing and the scripted 360 selection can't land
  // (measured: the LEFT-to-360 press dropped, drive fell back to arcade). Menus present full
  // speed; only gameplay is slowed, which is exactly the regime the decoupling proof needs.
  { static const int thrMs = std::getenv("RT_PRESENT_THROTTLE_MS") ? atoi(std::getenv("RT_PRESENT_THROTTLE_MS")) : 0;
    if (thrMs > 0 && g_base && __builtin_bswap32(*(const uint32_t*)(g_base + GA_FIELD_ACTIVE)) != 0u)
      std::this_thread::sleep_for(std::chrono::milliseconds(thrMs)); }
  std::lock_guard<std::mutex> lk(g_mtx);
  if (g.failed) return;
  if (!g.ok && !initVk()) {
    g.failed = true;
    if (!rvkDiehardOn()) rvkDieLoud("Vulkan init failed on the nvk path (no renderer will ever come up)", 5);
    return;
  }
  g_base = basePtr;
  rvkWindowInit();
  rvkServiceInvalidations();   // CODE_REVIEW_0804: before the white guard, so a swap reset rebuilds cleanly
  // bindless white texture at fixed index 0 (same lazy build as the legacy path)
  if (g.rNextTexIndex == 1 && g.rTexRecords.empty()) {
    ((uint32_t*)g.stagingMap)[0] = 0xFFFFFFFFu;
    RTex wt{};
    if (!uploadTexToBindless(1, 1, wt)) { g.failed = true; return; }
    g.rTexRecords.push_back(wt);
    VkDescriptorImageInfo dii{VK_NULL_HANDLE, wt.view, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL};
    VkWriteDescriptorSet wr{VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET};
    wr.dstSet = g.rSets[0]; wr.dstBinding = 0; wr.dstArrayElement = 0; wr.descriptorCount = 1;
    wr.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE; wr.pImageInfo = &dii;
    vkUpdateDescriptorSets(g.dev, 1, &wr, 0, nullptr);
  }
  static long renderedFrames = 0;
  static int pngEvery = std::getenv("RT_NVKPNG") ? std::atoi(std::getenv("RT_NVKPNG")) : 0;
  // RT_NVKRESEVERY / RT_NVKRESONLY (2026-07-29 de-aliasing levers): both RT_NVKDBG resolve dumps
  // (the per-BLIT nvkpre_* snapshot and the end-of-frame nvkres_* sweep) were hardcoded to
  // `frame % 600 == 0`. That period aliases against the guest's own cadences, and the sweep
  // dumps EVERY registered surface at once so the PNGs cannot be told apart. RT_NVKRESEVERY=<n>
  // retunes the period (0 = dumps off); RT_NVKRESONLY=<hex surface base> restricts the sweep to
  // one resolve target. Unset = the shipped 600 / all surfaces.
  static long resEvery = std::getenv("RT_NVKRESEVERY") ? std::atol(std::getenv("RT_NVKRESEVERY")) : 600;
  // ★ RT_NVKDBGEVERY (s2B leg 10 item 2 — THE CENSUS BLIND SPOT). The [nvkseg]/[nvkdbg]/[nvkhole]/
  // [nvkvtx] censuses were all hardcoded to `frame % 600 == 0`. The ROM attract loop is EXACTLY
  // 4800 frames long (measured in the t3 bank: the 49-draw CAVELOGO band's heartbeats land on
  // f3301, f8101, f12901 — a 4800 stride), and 4800 % 600 == 0, so the census can only ever fire
  // on the eight fixed phases {0,600,1200,1800,2400,3000,3600,4200}. The cavelogo phase sits at
  // ~3250-3550 and is therefore STRUCTURALLY INVISIBLE to every census in every bank recorded so
  // far — which is why the class-D white-fill draw has never appeared in a [nvkdbg]/[nvkhole]
  // listing. Any value that does NOT divide 4800 walks the whole cycle: RT_NVKDBGEVERY=700 fires
  // at f3500 (phase 3500, inside the cavelogo window) on the FIRST cycle, and gcd(700,4800)=100 so
  // it sweeps every 100-frame phase thereafter. 0 silences the censuses. Unset = 600 = byte-
  // identical to leg 9.
  static long dbgEvery = std::getenv("RT_NVKDBGEVERY") ? std::atol(std::getenv("RT_NVKDBGEVERY")) : 600;
  auto dbgTick = [&]() { return dbgEvery > 0 && (nf->frame % dbgEvery) == 0; };
  static const char* resOnly = std::getenv("RT_NVKRESONLY");   // hex surface base; unset = all
  static uint32_t resOnlyBase = resOnly ? (uint32_t)std::strtoul(resOnly, nullptr, 16) : 0u;
  static bool carryClear = false; static uint32_t carryClearColor = 0;   // resolve clear-after with no draws behind it
  bool render = nf->nDraws > 0 || nf->hasClear;
  // body lambda: VKC's error path `return false`s out of a bool context (macro contract)
  auto renderBody = [&]() -> bool {
    g_nvkFrame.store(nf->frame, std::memory_order_relaxed);   // ★ r23-w17 C1: the join's shared clock
    g.rArenaOffset = 0;   // nvk owns the arena at RT_NVK=2 (all submits below are fence-waited)
    // ★ TEXEL ALIGNMENT (s2B leg 9 class A) — levers shared by the resolve blit and the draw loop.
    // RT_NVKNOALIGN=1 reverts the WHOLE change (1:1 resolve copy + composite sampler snap);
    // RT_NVKCOMPLIN=1 reverts only the composite sampler back to the fetch-constant filter.
    static bool nvkNoAlign = std::getenv("RT_NVKNOALIGN") != nullptr;
    static bool nvkCompLin = std::getenv("RT_NVKCOMPLIN") != nullptr;
    // RT_NVKRTDUMP=<hex surface ptr or resolve dst base> (s2B leg 9 class-B discriminator):
    // dump the CURRENT render-target image immediately BEFORE its resolve blit, so the ring's
    // channel-remap corruption can be attributed to the render pass or to the resolve copy.
    static const char* rtDumpEnv = std::getenv("RT_NVKRTDUMP");
    static uint32_t rtDumpBase = rtDumpEnv ? (uint32_t)std::strtoul(rtDumpEnv, nullptr, 16) : 0u;
    uint32_t* Vraw = (uint32_t*)g.vbufMap;   // 6 dwords / vertex, same layout the pipelines expect
    uint32_t* Iarr = (uint32_t*)g.ibufMap;
    uint32_t nv = 0, ni = 0;
    struct NvkBatch { VkPipeline pipe; uint64_t vs, ps, sh; uint32_t first, count; int vsIdx; VkViewport vp; float vte[4]; uint32_t vteCntl; float bc[4]; };
    std::vector<NvkBatch> nbs; nbs.reserve((size_t)nf->nDraws);
    static long badDrawN = 0, oddPrimN = 0;
    // ---- per-segment recorder (submitSeg idiom; one cmd per segment, fence-waited) ----
    VkClearValue clear{};
    auto setClear = [&](uint32_t c) {
      clear.color = {{((c >> 16) & 0xFF) / 255.f, ((c >> 8) & 0xFF) / 255.f, (c & 0xFF) / 255.f, ((c >> 24) & 0xFF) / 255.f}};
    };
    size_t segStart = 0;
    bool segClear = false;                 // whether the NEXT recorded segment begins with CLEAR
    NvkRT* curRT = nullptr;                // s2B leg 6: current colour target; null = display (g.image)
    // Clear is an ORDERED stream event (NVK_KIND_CLEAR) — no frame-level clear. Only the
    // first-ever frame (image layout) and a carried resolve clear-after seed segClear here.
    if (carryClear) { segClear = true; setClear(carryClearColor); }
    else if (renderedFrames == 0) { segClear = true; setClear(0xFF000000u); }
    carryClear = false;
    auto recordSeg = [&](size_t s0, size_t s1) -> bool {
      // ★ CLEAR-ORDERING RULE (C3-s1 decomp lesson, re-learned here from black resolve dumps):
      // a frame's first event can be the STRADDLED TAIL RESOLVE of the previous guest frame.
      // An empty clear-bearing segment recorded before that blit wipes the EDRAM content the
      // resolve is about to copy. Empty segments are NEVER recorded; a pending clear stays
      // pending until the first draw-bearing segment.
      if (s1 == s0) return true;
      static bool segDbg = std::getenv("RT_NVKDBG") != nullptr;
      if (segDbg && dbgTick())
        std::fprintf(stderr, "[nvkseg] f%ld SEG [%zu,%zu) clear=%d color=%08X\n", nf->frame, s0, s1, (int)segClear, nf->clearARGB);
      segBatchFlush();
      rvkRingNext("nvk"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(nvk)");
      VkCommandBufferBeginInfo cbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO};
      cbi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
      VKC(vkBeginCommandBuffer(g.cmd, &cbi), "begin(nvk)");
      VkRenderPassBeginInfo rpb{VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO};
      // leg 10 item 1: the pass must match the TARGET's format (a framebuffer is only usable with a
      // format-compatible pass). curRT->passClear/passLoad are {g.pass,g.passLoad} whenever the
      // target sits at g_rtFmt, so the default path is unchanged.
      rpb.renderPass = curRT ? (segClear ? curRT->passClear : curRT->passLoad)
                             : (segClear ? g.pass : g.passLoad);
      rpb.framebuffer = curRT ? curRT->fb : g.fb;
      rpb.renderArea = {{0, 0}, {curRT ? curRT->w : kW, curRT ? curRT->h : kH}};
      rpb.clearValueCount = segClear ? 1u : 0u; rpb.pClearValues = segClear ? &clear : nullptr;
      segClear = false;
      vkCmdBeginRenderPass(g.cmd, &rpb, VK_SUBPASS_CONTENTS_INLINE);
      vkCmdBindDescriptorSets(g.cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, g.rPlLayout, 0, 4, g.rSets, 0, nullptr);
      VkDeviceSize voff = 0; vkCmdBindVertexBuffers(g.cmd, 0, 1, &g.vbuf, &voff);
      vkCmdBindIndexBuffer(g.cmd, g.ibuf, 0, VK_INDEX_TYPE_UINT32);
      VkPipeline lastPipe = VK_NULL_HANDLE;
      for (size_t bi = s0; bi < s1; ++bi) {
        auto& b = nbs[bi];
        if (b.pipe != lastPipe) { vkCmdBindPipeline(g.cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, b.pipe); lastPipe = b.pipe; }
        vkCmdSetViewport(g.cmd, 0, 1, &b.vp);
        vkCmdSetBlendConstants(g.cmd, b.bc);   // guest RB_BLEND_RED..ALPHA per batch (RT_NVKNOBC reverts)
        struct { uint64_t vs, ps, shared; float ndc[4]; } pc{b.vs, b.ps, b.sh, {1.f, 1.f, 0.f, 0.f}};
        // ★ SEG-TRANSFORM LADDER, register-true at wrapper altitude (PA_CL_VTE_CNTL is the gate):
        // VTE DISABLED (bit0 off — game field passes run 0x400) means the VS outputs SCREEN-SPACE
        // pixels; map them over the guest viewport (old true48 constants, vp dims). VTE ENABLED:
        // matrix-class clip passes through with the VTE scale-sign orientation rule; the vs48
        // px-class maps through the guest's own scale/offset.
        if ((b.vteCntl & 0x1u) == 0u && b.vp.width > 0.f && b.vp.height > 0.f) {
          pc.ndc[0] = 2.f / b.vp.width;  pc.ndc[2] = -1.f + 1.f / b.vp.width;
          pc.ndc[1] = -2.f / b.vp.height; pc.ndc[3] = 1.f - 1.f / b.vp.height;
        } else if (b.vsIdx != 48 && b.vte[0] != 0.f && b.vte[2] != 0.f) {
          pc.ndc[0] = b.vte[0] > 0.f ? 1.f : -1.f;
          pc.ndc[1] = b.vte[2] < 0.f ? 1.f : -1.f;
        }
        if (b.vsIdx == 48 && (b.vteCntl & 0x1u) != 0u) {
          // px->ndc via the guest's OWN PA_CL_VPORT scale/offset (register-true VTE ladder):
          // hardware screen = clip*scale+offset, so clip = (px - offset)/scale. Shell default
          // {640,640,-360,360} reproduces the old 2/kW,-2/kH constants exactly; game module
          // render-to-texture passes carry different signs — this is what un-flips them.
          float xs = b.vte[0], xo = b.vte[1], ys = b.vte[2], yo = b.vte[3];
          bool sane = xs != 0.f && ys != 0.f && xs > -8192.f && xs < 8192.f && ys > -8192.f && ys < 8192.f;
          if (sane) {
            pc.ndc[0] = 1.f / xs; pc.ndc[2] = -xo / xs;
            pc.ndc[1] = 1.f / ys; pc.ndc[3] = -yo / ys;
          } else {
            pc.ndc[0] = 2.f / (float)kW; pc.ndc[1] = -2.f / (float)kH;
            pc.ndc[2] = -1.f + 1.f / (float)kW; pc.ndc[3] = 1.f - 1.f / (float)kH;
          }
          VkViewport fvp{0.f, 0.f, (float)kW, (float)kH, 0.f, 1.f};   // vte encodes placement
          vkCmdSetViewport(g.cmd, 0, 1, &fvp);
        }
        vkCmdPushConstants(g.cmd, g.rPlLayout, VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT, 0, sizeof(pc), &pc);
        vkCmdDrawIndexed(g.cmd, b.count, 1, b.first, 0, 0);
      }
      vkCmdEndRenderPass(g.cmd);   // offscreen -> TRANSFER_SRC
      VKC(vkEndCommandBuffer(g.cmd), "end(nvk)");
      VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
      VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(nvk)");
      VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(nvk)");
      VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(nvk)");
      g_anyRender = true;
      return true;
    };
    // ---- resolve blit: g.image region -> resolve texture (blitResolve pattern) ----
    auto nvkBlitResolve = [&](NvkDraw& d) -> bool {
      // ★ REGISTER-TRUE RESOLVE DESTINATION (s2B leg 10 item 1). On hardware this copy is EDRAM ->
      // texture memory in the destination's own texel format; the guest then fetches those bits
      // with the format recorded in the fetch constant (dw1 bits 0-5). For the ring that is fmt 54
      // = k_2_10_10_10, so the host destination is A2B10G10R10_UNORM_PACK32 and the blit from the
      // 7e3-analogue F16 render target performs exactly the guest's saturate-to-[0,1] + 10-bit
      // quantize. Every other target keeps g_rtFmt (fetch fmt 6 etc.), unchanged from leg 9.
      // Guard: only trust the fetch shadow when its BASE names this very resolve destination. The
      // [nvkfmt] bank corroborates the identity exactly (dw1=0F08D0B6 -> base 0x0F08D000 == dst
      // 0xF08D000 on every ring slot), so a mismatch means we are looking at some other draw's
      // stage-0 constant and must not let it pick the target's format.
      uint32_t tfBase = ((d.tf[1] >> 12) & 0xFFFFFu) << 12;
      VkFormat wantTexFmt = (d.tf[1] && tfBase == d.resolveDst)
                          ? nvkResolveTexFormatFor(d.tf[1] & 0x3Fu) : VK_FORMAT_UNDEFINED;
      ResolveTex& rt = getOrCreateResolveTex(d.resolveDst, d.resolveW, d.resolveH, wantTexFmt);
      if (!rt.image) return true;
      // register-true 1:1 region: srcRect if the guest passed one, else a dest-sized region at 0,0
      // s2B leg 6: the blit reads from the CURRENTLY BOUND colour target (EDRAM semantics), not
      // always the display image — the field resolve copies from the game's own 640-wide target.
      // (Hoisted above the instruments so [nvkfmt] can report the exact region it describes.)
      VkImage srcImg = curRT ? curRT->image : g.image;
      int32_t srcW = curRT ? (int32_t)curRT->w : (int32_t)kW;
      int32_t srcH = curRT ? (int32_t)curRT->h : (int32_t)kH;
      int32_t sx0 = 0, sy0 = 0, sx1 = (int32_t)d.resolveW, sy1 = (int32_t)d.resolveH;
      if (d.srcRect[2] > d.srcRect[0] && d.srcRect[3] > d.srcRect[1]) {
        sx0 = d.srcRect[0]; sy0 = d.srcRect[1]; sx1 = d.srcRect[2]; sy1 = d.srcRect[3];
      }
      if (sx1 > srcW) sx1 = srcW; if (sy1 > srcH) sy1 = srcH;
      if (sx0 < 0) sx0 = 0; if (sy0 < 0) sy0 = 0;
      static bool blitDbg = std::getenv("RT_NVKDBG") != nullptr;
      if (blitDbg && resEvery > 0 && (nf->frame % resEvery) == 0) {
        std::fprintf(stderr, "[nvkseg] f%ld BLIT dst=0x%07X %ux%u rect={%d,%d,%d,%d} clearAfter=%u cc=%08X\n",
                     nf->frame, d.resolveDst, d.resolveW, d.resolveH,
                     d.srcRect[0], d.srcRect[1], d.srcRect[2], d.srcRect[3], d.clearAfter, d.clearColor);
        // pre-blit g.image snapshot: is the just-rendered segment's content actually here?
        segBatchFlush();
        rvkRingNext("nvkq"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(nvkq)");
        VkCommandBufferBeginInfo cq{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO};
        cq.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
        VKC(vkBeginCommandBuffer(g.cmd, &cq), "begin(nvkq)");
        copyDisplayToReadback(g.cmd);
        VKC(vkEndCommandBuffer(g.cmd), "end(nvkq)");
        VkSubmitInfo sq{VK_STRUCTURE_TYPE_SUBMIT_INFO}; sq.commandBufferCount = 1; sq.pCommandBuffers = &g.cmd;
        VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(nvkq)");
        VKC(rvkQueueSubmit(g.queue, 1, &sq, g.fence), "submit(nvkq)");
        VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(nvkq)");
        void* mq = nullptr;
        VKC(vkMapMemory(g.dev, g.readbackMem, 0, VK_WHOLE_SIZE, 0, &mq), "map(nvkq)");
        char fq[96]; std::snprintf(fq, sizeof fq, "C:/tmp/nvkpre_f%ld_%07X.png", nf->frame, d.resolveDst);
        writePng(fq, (const uint8_t*)mq, kW, kH);
        vkUnmapMemory(g.dev, g.readbackMem);
      }
      // ---- RT_NVKRTDUMP: pre-resolve snapshot of the CURRENT render target (leg 9 class B) ----
      // Matches on either the guest surface pointer or the resolve dest base, so the ring slot
      // can be named from an [nvkrt]/[nvkseg] line either way. The RT parks in TRANSFER_SRC
      // between passes (getNvkRT + the render pass's final layout), so this is a bare
      // image->buffer copy on its own fence-waited cmd — same pattern as the nvkres sweep.
      // leg 10 item 1: writePng reinterprets the readback as RGBA8, so a target that is no longer
      // RGBA8 must be skipped (was: a g_rtFmt check, which no longer speaks for THIS target).
      if (rtDumpBase && curRT && curRT->image &&
          (curRT->surf == rtDumpBase || d.resolveDst == rtDumpBase) &&
          curRT->fmt == VK_FORMAT_R8G8B8A8_UNORM &&
          (uint64_t)curRT->w * curRT->h * 4ull <= (uint64_t)kW * kH * 4ull) {
        segBatchFlush();
        rvkRingNext("nvkrd"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(nvkrd)");
        VkCommandBufferBeginInfo cr{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO};
        cr.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
        VKC(vkBeginCommandBuffer(g.cmd, &cr), "begin(nvkrd)");
        VkBufferImageCopy bic{}; bic.imageSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1};
        bic.imageExtent = {curRT->w, curRT->h, 1};
        vkCmdCopyImageToBuffer(g.cmd, curRT->image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, g.readback, 1, &bic);
        VKC(vkEndCommandBuffer(g.cmd), "end(nvkrd)");
        VkSubmitInfo sr{VK_STRUCTURE_TYPE_SUBMIT_INFO}; sr.commandBufferCount = 1; sr.pCommandBuffers = &g.cmd;
        VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(nvkrd)");
        VKC(rvkQueueSubmit(g.queue, 1, &sr, g.fence), "submit(nvkrd)");
        VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(nvkrd)");
        void* mr2 = nullptr;
        VKC(vkMapMemory(g.dev, g.readbackMem, 0, VK_WHOLE_SIZE, 0, &mr2), "map(nvkrd)");
        char fr[128];
        std::snprintf(fr, sizeof fr, "C:/tmp/nvkrtpre_f%ld_%07X_%ux%u.png",
                      nf->frame, rtDumpBase, curRT->w, curRT->h);
        writePng(fr, (const uint8_t*)mr2, curRT->w, curRT->h);
        vkUnmapMemory(g.dev, g.readbackMem);
        static long rdN = 0;
        if ((++rdN % 300) == 1)
          std::fprintf(stderr, "[nvkrtdump] #%ld f%ld surf=%08X dst=0x%07X %ux%u -> %s\n",
                       rdN, nf->frame, curRT->surf, d.resolveDst, curRT->w, curRT->h, fr);
      }
      // ---- [nvkfmt] one-shot per (source surface, resolve dst) for the 320-wide ring slots ----
      // Splits "the render pass wrote the wrong channels" from "the resolve copy reinterpreted
      // them": prints the host formats on both sides plus the GUEST format words. Ring dest
      // fmt 54 = Xenos k_2_10_10_10_AS_16_16_16_16, which getTexIndexReal has no decoder case for.
      if (d.resolveW == 320u || (curRT && curRT->w == 320u)) {
        static std::set<uint64_t> fmtSeen;
        uint64_t fk = ((uint64_t)(curRT ? curRT->surf : 0u) << 32) | (uint64_t)d.resolveDst;
        if (fmtSeen.insert(fk).second) {
          uint32_t srcCI = curRT ? curRT->colorInfo : 0u;
          bool oneToOne = (sx1 - sx0) == (int32_t)rt.w && (sy1 - sy0) == (int32_t)rt.h;
          std::fprintf(stderr,
            "[nvkfmt] f%ld src=%s surf=%08X %ux%u vkfmt=%d guest RB_COLOR_INFO=%08X (base=%u cfmt=%u) "
            "| dst=0x%07X %ux%u vkfmt=%d guest fetch dw0=%08X dw1=%08X (fmt=%u endian=%u) dw2=%08X "
            "| %s src[%d,%d..%d,%d] -> dst[0,0..%u,%u]\n",
            nf->frame, curRT ? "RT" : "DISPLAY", curRT ? curRT->surf : 0u,
            curRT ? curRT->w : kW, curRT ? curRT->h : kH, (int)(curRT ? curRT->fmt : g_rtFmt),
            srcCI, srcCI & 0xFFFu, (srcCI >> 16) & 0xFu,
            d.resolveDst, rt.w, rt.h, (int)rt.fmt,
            d.tf[0], d.tf[1], d.tf[1] & 0x3Fu, (d.tf[1] >> 6) & 3u, d.tf[2],
            oneToOne ? "blit-1:1(copy)" : "blit-SCALED", sx0, sy0, sx1, sy1, rt.w, rt.h);
        }
      }
      segBatchFlush();
      rvkRingNext("nvkb"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(nvkb)");
      VkCommandBufferBeginInfo cbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO};
      cbi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
      VKC(vkBeginCommandBuffer(g.cmd, &cbi), "begin(nvkb)");
      VkImageMemoryBarrier b{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER};
      b.srcQueueFamilyIndex = b.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
      b.image = rt.image; b.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
      b.oldLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL; b.newLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
      b.srcAccessMask = VK_ACCESS_SHADER_READ_BIT; b.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
      vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b);
      VkImageBlit bl{}; bl.srcSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1};
      bl.srcOffsets[0] = {sx0, sy0, 0}; bl.srcOffsets[1] = {sx1, sy1, 1};
      bl.dstSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1};
      bl.dstOffsets[1] = {(int32_t)rt.w, (int32_t)rt.h, 1};
      // ★ RT_NVKDP (2026-08-03, banner follow-up "not aligned to the border"): when the guest
      // passed a REAL source rect, ResolveEx semantics (XDK 20209.3 resolve.obj decompile) are a
      // REGION copy: src texel (x,y) lands at dest (x - src.x0 + dp.x, y - src.y0 + dp.y). The
      // select screens' scroll cache resolves ONLY the fresh strip into its page at the matching
      // offset each frame — pasting at (0,0) full-stretch shifted the cache = the top-seam smear.
      // No rect (srcRect degenerate) keeps the legacy full-dest stretch — shell resolves all pass
      // NULL rects (reslog) and are byte-identical. RT_NVKDP=0 reverts to the stretch.
      {
        static const bool dpOff = [](){ const char* e = std::getenv("RT_NVKDP"); return e && e[0]=='0' && !e[1]; }();
        bool haveRect = d.srcRect[2] > d.srcRect[0] && d.srcRect[3] > d.srcRect[1];
        // ★ SCOPED (2026-08-03, Score-Attack corruption + RVK_RESLOG shape censuses): apply the
        // region paste ONLY to OFFSET resolves — nonzero rect origin or destPoint (the strip-copy
        // class, e.g. the select screens' scroll-cache strip {512,0,640,512}->page@0,0). The only
        // gameplay shape is rect={0,0,640,480}->640x512 dp=0: an origin-zero window the legacy
        // path has ALWAYS stretched to the full dest, and the entire downstream (self-composite
        // feedback, compose) is proven against that stretch — pasting it 1:1 left 32 stale rows
        // compounding through feedback = the end-of-level tile squares (user A/B: RT_NVKDP=0
        // cured it). Register-truth debt banked: hardware does NOT stretch; our consumers are
        // calibrated to the stretch, revisit as a pair post-beta.
        bool offsetResolve = d.srcRect[0] != 0 || d.srcRect[1] != 0 || d.resolveDpX != 0 || d.resolveDpY != 0;
        // ★ FINAL RULE (2026-08-03 night, complete deduped shape map — 7 shapes at the select
        // screens, one contested): ORIGIN-ZERO rects extend to DEST dims, 1:1 (the pane's
        // {0,0,640,480}->640x512 copies all 512 rows exactly like the months-proven pre-r5
        // NULL-rect default — no stretch, no stale band; the 512x512 full-page copies are
        // identity under this too). OFFSET rects keep the region paste at dp below. NO STRETCH
        // ANYWHERE: the legacy stretch survives only for degenerate no-rect records, where it
        // is an identity blit by construction.
        if (!dpOff && haveRect && !offsetResolve) {
          int32_t ew = (int32_t)rt.w, eh = (int32_t)rt.h;
          if (sx0 + ew > srcW) ew = srcW - sx0;
          if (sy0 + eh > srcH) eh = srcH - sy0;
          if (ew > 0 && eh > 0) {
            bl.srcOffsets[1] = {sx0 + ew, sy0 + eh, 1};
            bl.dstOffsets[1] = {ew, eh, 1};   // 1:1 from origin; unreachable dest tail stays
          }
        }
        if (!dpOff && haveRect && offsetResolve) {
          int32_t dpx = d.resolveDpX, dpy = d.resolveDpY;
          if (dpx < 0) dpx = 0; if (dpy < 0) dpy = 0;
          int32_t dw = sx1 - sx0, dh = sy1 - sy0;
          if (dpx + dw > (int32_t)rt.w) dw = (int32_t)rt.w - dpx;
          if (dpy + dh > (int32_t)rt.h) dh = (int32_t)rt.h - dpy;
          if (dw > 0 && dh > 0) {
            bl.srcOffsets[1] = {sx0 + dw, sy0 + dh, 1};   // keep 1:1 after clamping
            bl.dstOffsets[0] = {dpx, dpy, 0};
            bl.dstOffsets[1] = {dpx + dw, dpy + dh, 1};
          }
        }
      }
      // ★ TEXEL-EXACT RESOLVE (s2B leg 9 class A). An EDRAM resolve is a COPY, not a filtered
      // rescale — the OLD renderer only uses VK_FILTER_LINEAR because its blitResolve always
      // rescales the whole 1280x720 offscreen into the resolve tex (vk_render.cpp:6493-6496,
      // srcOffsets = the full kW x kH frame regardless of rt.w/rt.h). nvk's blit is region-true,
      // so whenever the source region and the destination extent match exactly the filter must be
      // NEAREST: LINEAR at 1:1 is only guaranteed exact for a perfectly aligned sample grid, and
      // this target is re-fed to itself every frame by the vs47/ps46 self-composite — any residual
      // sub-texel weight integrates over dwell (the class-A legal-panel streak). Scaled resolves
      // keep LINEAR. RT_NVKNOALIGN=1 reverts.
      // 1:1 test on the ACTUAL blit geometry (RT_NVKDP region pastes are 1:1 by construction
      // but smaller than the dest — the old dest-extent compare would wrongly pick LINEAR).
      bool res1to1 = (bl.srcOffsets[1].x - bl.srcOffsets[0].x) == (bl.dstOffsets[1].x - bl.dstOffsets[0].x)
                  && (bl.srcOffsets[1].y - bl.srcOffsets[0].y) == (bl.dstOffsets[1].y - bl.dstOffsets[0].y);
      VkFilter resFilter = (!nvkNoAlign && res1to1) ? VK_FILTER_NEAREST : VK_FILTER_LINEAR;
      vkCmdBlitImage(g.cmd, srcImg, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, rt.image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &bl, resFilter);
      b.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL; b.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
      b.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT; b.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
      vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &b);
      VKC(vkEndCommandBuffer(g.cmd), "end(nvkb)");
      VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
      VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(nvkb)");
      VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(nvkb)");
      VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(nvkb)");
      rvkResMarkRendered(rt, nf->frame);
      return true;
    };
    // ---- build batches in stream order; resolves segment the frame ----
    bool anySegRendered = false;
    // ★ NVK COMPOSE CENSUS — per-frame state (contract + levers documented above nvk_frame_submit)
    static int censOn   = std::getenv("RVK_DRAWCENSUS")   ? atoi(std::getenv("RVK_DRAWCENSUS"))   : 0;
    static int censTest = std::getenv("RVK_CENSUSTEST")   ? atoi(std::getenv("RVK_CENSUSTEST"))   : 0;
    static int censK    = std::getenv("RVK_DRAWCENSUS_K") ? atoi(std::getenv("RVK_DRAWCENSUS_K")) : 8;
    static int censR    = std::getenv("RVK_DRAWCENSUS_R") ? atoi(std::getenv("RVK_DRAWCENSUS_R")) : 3;
    const bool censShell = censOn != 0 && g_base && be32(GA_FIELD_ACTIVE) == 0;
    // injection fires on the census's OWN clock (frame%N is unreachable under pacing) and only
    // once a target identity has been elected by a previous frame's close.
    const bool censInjFrame = censShell && censTest != 0 && g_ncTestKey != 0 && (g_ncPc % 250) == 249;
    int censDisp = 0, censClears = 0, censInjHits = 0;
    // ★ RVK_QUADCENSUS (2026-08-11, consume-side attribution leg): one-shot PER-QUAD census of an
    // armed frame — every stream event in order, and for every draw the bound texture base, the
    // served index, the RESOLVE flag, and the XY/UV bbox decoded from the draw's OWN vertex bytes.
    // The 08-07 IDLOG run closed the produce side (bake fires, geometry correct, zero identity
    // collisions at the corrupted screen) — the open question is WHICH page each quad samples vs
    // where its vertices land. Armed by `touch /tmp/rvk_quad_now` (same signal-file discipline as
    // rvk_dump_now: consumed once, fires for the next K frames) because the corrupted screen is
    // only reachable user-driven — the scripted 360 card decide is refused (ledger 08-07).
    static const int qcOn = std::getenv("RVK_QUADCENSUS") ? atoi(std::getenv("RVK_QUADCENSUS")) : 0;
    static const int qcK  = std::getenv("RVK_QUADCENSUS_K") ? atoi(std::getenv("RVK_QUADCENSUS_K")) : 2;
    static int qcArmed = 0;
    if (qcOn) {
      if (FILE* sf = std::fopen("/tmp/rvk_quad_now", "rb")) {
        std::fclose(sf); std::remove("/tmp/rvk_quad_now");
        qcArmed = qcK;
        std::fprintf(stderr, "[quadcensus] armed for %d frame(s) at f%ld\n", qcK, nf->frame);
      }
    }
    const bool qcThis = qcArmed > 0;
    if (qcThis) {
      --qcArmed;
      std::fprintf(stderr, "[quadcensus] f%ld nDraws=%d displaySurf=%08X\n",
                   nf->frame, nf->nDraws, nf->displaySurf);
    }
    for (int di = 0; di < nf->nDraws; ++di) {
      NvkDraw& d = nf->draws[di];
      if (d.kind == NVK_KIND_SETRT) {   // s2B leg 6: colour-target switch segments the frame
        if (!recordSeg(segStart, nbs.size())) return false;
        segStart = nbs.size();
        bool isDisplay = (d.rtSurf == nf->displaySurf);
        if (qcThis)
          std::fprintf(stderr, "[quadcensus] f%ld d%d SETRT surf=%08X %ux%u%s\n",
                       nf->frame, di, d.rtSurf, d.rtW, d.rtH, isDisplay ? " DISPLAY" : "");
        static bool rtDbg = std::getenv("RT_NVKDBG") != nullptr;
        if (rtDbg && dbgTick())
          std::fprintf(stderr, "[nvkseg] f%ld SETRT surf=%08X %ux%u display=%d @nbs=%zu\n",
                       nf->frame, d.rtSurf, d.rtW, d.rtH, (int)isDisplay, nbs.size());
        NvkRT* next = nullptr;
        if (!isDisplay && d.rtW >= 64 && d.rtW <= 4096 && d.rtH >= 64 && d.rtH <= 4096)
          next = getNvkRT(d.rtSurf, d.rtW, d.rtH, d.rtInfo, d.rtColorInfo);   // null on create failure -> display (loud below)
        if (!isDisplay && !next) {
          static long rtFail = 0;
          if ((++rtFail % 300) == 1)
            std::fprintf(stderr, "[nvkrt] offscreen target %08X %ux%u unavailable -> display x%ld\n",
                         d.rtSurf, d.rtW, d.rtH, rtFail);
        }
        curRT = next;
        continue;
      }
      if (d.kind == NVK_KIND_RESOLVE) {
        if (qcThis)
          std::fprintf(stderr, "[quadcensus] f%ld d%d RESOLVE dst=%08X %ux%u rect={%d,%d,%d,%d}%s\n",
                       nf->frame, di, d.resolveDst, d.resolveW, d.resolveH,
                       d.srcRect[0], d.srcRect[1], d.srcRect[2], d.srcRect[3],
                       d.clearAfter ? " clearAfter" : "");
        // ★ RVK_RESLOG segment census (2026-08-03 bake hunt): draws-in-segment for 512x512
        // resolves. Page dumps show the six backdrop pages capture LAST FRAME'S FINISHED PANE
        // ⇒ hypothesis: their bake segments are EMPTY in our recorded stream. This counts it.
        {
          static const bool resLog2 = [](){ const char* e = std::getenv("RVK_RESLOG"); return e && atoi(e) != 0; }();
          if (resLog2 && d.resolveW == 512 && d.resolveH == 512) {
            static long rsn = 0;
            if (++rsn <= 60) {
              std::fprintf(stderr, "[resseg] f%ld dst=0x%08X segDraws=%zu curRT=%s(%ux%u)\n",
                           nf->frame, d.resolveDst, nbs.size() - segStart,
                           curRT ? "off" : "display", curRT ? curRT->w : kW, curRT ? curRT->h : kH);
              // batch detail: which NDC branch will each take? (vteCntl bit0, vsIdx, vte, vp)
              for (size_t bi = segStart; bi < nbs.size() && bi < segStart + 8; ++bi) {
                auto& b = nbs[bi];
                std::fprintf(stderr, "[resseg]   b%zu vs=%d n=%u vteCntl=%X vte={%.1f,%.1f,%.1f,%.1f} "
                                     "vp={%.0f,%.0f,%.0f,%.0f}\n",
                             bi - segStart, b.vsIdx, b.count, b.vteCntl,
                             b.vte[0], b.vte[1], b.vte[2], b.vte[3],
                             b.vp.x, b.vp.y, b.vp.width, b.vp.height);
              }
            }
          }
        }
        if (!recordSeg(segStart, nbs.size())) return false;
        segStart = nbs.size(); anySegRendered = true;
        if (!nvkBlitResolve(d)) return false;
        if (d.clearAfter) { segClear = true; setClear(d.clearColor); }
        continue;
      }
      if (d.kind == NVK_KIND_CLEAR) {   // ordered guest Clear: segment here, clear what follows
        if (qcThis)
          std::fprintf(stderr, "[quadcensus] f%ld d%d CLEAR %08X\n", nf->frame, di, d.clearColor);
        ++censClears;                   // SPEC_shell_compose_1to1 §4 clear-policy check (frame close)
        if (!recordSeg(segStart, nbs.size())) return false;
        segStart = nbs.size();
        segClear = true; setClear(d.clearColor);
        continue;
      }
      if (!d.count) continue;
      // shader identity: the bound objects' microcode through the SAME matcher the old path used
      auto ucodeSane = [](uint32_t a, uint32_t sz) { return a > 0x1000u && a < 0x20000000u && sz >= 16u && sz <= 0x8000u; };
      if (ucodeSane(d.vsUcode, d.vsUcodeSize)) matchImLoad(d.vsUcode, 0u, d.vsUcodeSize / 4u);
      if (ucodeSane(d.psUcode, d.psUcodeSize)) matchImLoad(d.psUcode, 1u, d.psUcodeSize / 4u);
      int vsIdx = g_curVsIdx >= 0 ? g_curVsIdx : 1;   // pre-bind boot frames: early-logo class
      int psIdx = g_curPsIdx >= 0 ? g_curPsIdx : 2;
      // RT_NVKSKIP47=1 (P1 discriminator probe, 2026-07-29): drop the vs47 self-composite quads
      // on VTE-off draws. Separates "d4 PAINTS the flat portal" from "d4 is the only field
      // content there is" — if the flat survives with these gone, d4 is not the painter. The
      // shader match above still ran, so g_curVsIdx/g_curPsIdx state stays register-true.
      static bool nvkSkip47 = std::getenv("RT_NVKSKIP47") && atoi(std::getenv("RT_NVKSKIP47")) != 0;
      if (nvkSkip47 && vsIdx == 47 && (d.vteCntl & 1u) == 0u) {
        static long sk47 = 0;
        if ((sk47++ % 600) == 0)
          std::fprintf(stderr, "[nvkskip47] dropped vs47 VTE-off draw #%ld (f%ld)\n", sk47, nf->frame);
        continue;
      }
      // ★ NVK COMPOSE CENSUS — identity + fault injection. The key is computed here (before any
      // decode) so RVK_CENSUSTEST=2 can drop the draw at exactly the point RT_NVKSKIP47 does,
      // i.e. AFTER matchImLoad, leaving g_curVsIdx/g_curPsIdx register-true.
      const uint32_t censBase = d.tf[1] ? (((d.tf[1] >> 12) & 0xFFFFFu) << 12) : 0u;
      const uint64_t censKey = nvkCensusKey(censBase, vsIdx, psIdx);
      const bool censInjThis = censInjFrame && curRT == nullptr && censKey == g_ncTestKey;
      if (censInjThis) {
        ++censInjHits;
        if (censInjHits == 1)
          std::fprintf(stderr, "[census] INJECT pc=%ld f%ld base=0x%X vs=%d ps=%d mode=%d (%s)\n",
                       g_ncPc, nf->frame, censBase, vsIdx, psIdx, censTest,
                       censTest >= 2 ? "draws SKIPPED - real dropout" : "count skipped");
        // ★ 4th control-failure fix (2026-07-31, caught by the pc2 run): the census clock only
        // advances on frames with >=1 DISPLAY draw, and during the boot-logo phase the injected
        // identity IS the only display class — skipping it left censDisp==0, the clock frozen at
        // pc=249, and the injection latched for 322 consecutive frames (element hidden for ~5s
        // instead of 1 frame). The frame did recompose; only the COUNT is suppressed. So the
        // injected draw still contributes to the frame's display total.
        if (censTest >= 2) { ++censDisp; continue; }   // POSITIVE CONTROL B: real one-frame dropout
      }
      // constants: register-true bank snapshot + shader DEFs on top
      if (d.bank < (uint32_t)nf->nBanks) {
        std::memcpy(g_vsConstF, nf->vsBanks + (size_t)d.bank * 1024, 4096);
        std::memcpy(g_psConstF, nf->psBanks + (size_t)d.bank * 896, 3584);
      }
      // ★ RT_VSXFORM half 2 (§5.7 measurement): the per-draw bound bank — c0..c3 and c10..c13
      // (the shell rect-transform region per the SPEC's RVK_SHADOWDUMP precedent). Paired
      // offline against [vsxf] guest writes on the same held frame.
      { static const bool vx = std::getenv("RT_VSXFORM") != nullptr;
        if (vx) { static long n = 0;
          if (n++ < 400)
            std::fprintf(stderr, "[vsxb] #%ld vs=%d bank=%u c0=%.5f,%.5f,%.5f,%.5f c10=%.5f,%.5f,%.5f,%.5f c12=%.5f,%.5f,%.5f,%.5f\n",
              n, vsIdx, d.bank,
              g_vsConstF[0], g_vsConstF[1], g_vsConstF[2], g_vsConstF[3],
              g_vsConstF[40], g_vsConstF[41], g_vsConstF[42], g_vsConstF[43],
              g_vsConstF[48], g_vsConstF[49], g_vsConstF[50], g_vsConstF[51]); } }
      loadShaderDefs(vsIdx, false);
      // RT_NVKA1 probe: force c14.a=1 on VTE-off (field) draws — isolates the c14.w=0 transparency
      static bool nvkA1 = std::getenv("RT_NVKA1") != nullptr;
      if (nvkA1 && (d.vteCntl & 1u) == 0u) g_psConstF[59] = 1.0f;
      auto vsl = arenaAlloc(4096); std::memcpy(vsl.host, g_vsConstF, 4096);
      auto psl = arenaAlloc(3584); std::memcpy(psl.host, g_psConstF, 3584);
      // texture: stage-0 fetch shadow captured at draw time
      uint32_t texIdx = 0, samplerIdx = 0, tw = 1, th = 1;
      if (d.tf[1]) {
        uint32_t tb = ((d.tf[1] >> 12) & 0xFFFFF) << 12;
        // RVK_FETCHPROBE=1 (2026-07-31 HI background-pipeline RE): the HI stream-page class
        // decodes to structured noise and its raw bytes are INDEX data (entropy 2.95, words
        // 0/1/2/0x5000-dominated) — print the FULL fetch constant + shader pair for every
        // distinct base so the true fetch encoding can be read instead of assumed. Default off.
        { static const bool fprobe = std::getenv("RVK_FETCHPROBE") && atoi(std::getenv("RVK_FETCHPROBE")) != 0;
          if (fprobe) {
            static std::set<uint32_t> seenB;
            if (seenB.insert(tb).second)
              std::fprintf(stderr, "[fetchprobe] tb=0x%08X tf={%08X,%08X,%08X,%08X,%08X,%08X} vs=%d ps=%d vte=%X st=%u\n",
                tb, d.tf[0], d.tf[1], d.tf[2], d.tf[3], d.tf[4], d.tf[5], vsIdx, psIdx, (unsigned)d.vteCntl, (unsigned)d.strideB); } }
        // RVK_ALIASPROBE=1 (2026-07-31, 512MB-alias confirm — hi_pool_fill_re.md PROBE-1):
        // for the first 3 distinct vs45/ps50 fmt3 512x512 field bases, dump raw guest bytes
        // from BOTH tb and tb+0x20000000 (the un-masked twin). If the high copy decodes as a
        // clean background, the aliasing verdict is closed. Diagnostic only, default off.
        { static const bool aprobe = std::getenv("RVK_ALIASPROBE") && atoi(std::getenv("RVK_ALIASPROBE")) != 0;
          if (aprobe && vsIdx == 45 && (d.tf[1] & 0x3F) == 3
              && ((d.tf[2] & 0x1FFF) + 1) == 512 && (((d.tf[2] >> 13) & 0x1FFF) + 1) == 512
              && tb < 0x20000000u && g_base) {
            static std::set<uint32_t> dumpedA;
            if (dumpedA.size() < 3 && dumpedA.insert(tb).second) {
              for (int hi = 0; hi < 2; ++hi) {
                uint32_t a = tb + (hi ? 0x20000000u : 0u);
                char nm[128]; std::snprintf(nm, sizeof nm, "/tmp/alias_%08X.bin", a);
                FILE* f = std::fopen(nm, "wb");
                if (f) { std::fwrite(g_base + a, 1, 0x80000u, f); std::fclose(f);
                  std::fprintf(stderr, "[aliasprobe] %s\n", nm); } } } } }
        tw = (d.tf[2] & 0x1FFF) + 1; th = ((d.tf[2] >> 13) & 0x1FFF) + 1;
        uint32_t fmt = d.tf[1] & 0x3F;
        // RT_NVKFRESH diagnostic: force a re-decode (cache erase, once per base per frame) for
        // VTE-off draw textures — tests the decoded-while-empty staleness verdict. LEAKS bindless
        // slots (~4/frame) by design; diagnostic only, never ship-on.
        static bool nvkFresh = std::getenv("RT_NVKFRESH") != nullptr;
        // RT_NVKFRESH2 diagnostic (s2B leg 5, wallpaper-then-black): same forced re-decode for
        // the SCREEN-SIZE VTE-ON class (settled-menu background quad b0: 1280x720 fmt6 streamed
        // by the CPU movie/bank uploader family 820E3F08.. — leg-3b's staleness probe only ever
        // covered VTE-off draws). If the background turns live with this on, the cure is the
        // dirty-range upload hook (C2 residual risk #3). Diagnostic only, never ship-on.
        static bool nvkFresh2 = std::getenv("RT_NVKFRESH2") != nullptr;
        // every-30th-frame cadence + exact screen-size gate: the first FRESH2 cut (>=512, every
        // frame) re-decoded the 2048x2048 static atlases too and OOM'd device memory in ~600
        // frames (leak is by design; the falsifier only needs ONE post-fade re-decode to speak).
        if (nvkFresh2 && tw == 1280 && th == 720 && !g_resolveTex.count(tb) && (nf->frame % 30) == 0) {
          static std::unordered_map<uint32_t, long> lastRedecode2;
          long& lf2 = lastRedecode2[tb];
          if (lf2 != nf->frame) { lf2 = nf->frame; g.rTexIndex.erase(((uint64_t)tb << 8) | fmt); }
        }
        if (nvkFresh && (d.vteCntl & 1u) == 0u && !g_resolveTex.count(tb)) {
          static std::unordered_map<uint32_t, long> lastRedecode;
          long& lf = lastRedecode[tb];
          if (lf != nf->frame) { lf = nf->frame; g.rTexIndex.erase(((uint64_t)tb << 8) | fmt); }
        }
        texIdx = getTexIndexReal(tb, tw, th, fmt, d.tf[0], d.blendReg, d.tf[3]);
        samplerIdx = (((d.tf[3] >> 19) & 3) == 0) ? 1u : 0u;   // fetch-const POINT filter
        // ★ vs47/ps46 SELF-COMPOSITE TEXEL SNAP (s2B leg 9 class A). The per-frame restore quad
        // (vs=47 ps=46, VTE-off, stride 28, verts (-0.5,-0.5)..(639.5,511.5) uv 0..1, colour
        // FF808080, sampling the RESOLVE-bound base it is about to be resolved into) is a 1:1
        // self-feedback pass at unity gain: whatever sub-texel weight the sampler carries is
        // re-applied every frame and integrates over dwell into the ~45-60 degree glyph smear
        // (measured 23.9 -> 35.5 luma f2172 -> f2353 in the EF4D000 resolves). The OLD renderer
        // never accumulates it because it never renders this pass into a native-sized target and
        // never feeds the result back (its blitResolve rescales the whole frame each time, and
        // the vs47 batch runs with the hardware-true PA_CL_VPORT viewport at vk_render.cpp:5131
        // and the fetch-constant filter at :5160). Register-truth here says a full-coverage 1:1
        // restore samples texel centres, so NEAREST is exact and LINEAR can only ever blur:
        // snap the sampler. RT_NVKCOMPLIN=1 restores the fetch-constant filter for this draw;
        // RT_NVKNOALIGN=1 reverts the whole leg-9 alignment change.
        bool selfComp = (vsIdx == 47) && (d.vteCntl & 1u) == 0u && g_resolveTex.count(tb) != 0;
        if (selfComp && !nvkNoAlign && !nvkCompLin) samplerIdx = 1u;   // bindless slot 1 = NEAREST
        if (selfComp) {
          static std::set<uint32_t> compSeen;
          if (compSeen.insert(tb).second) {
            auto rit = g_resolveTex.find(tb);
            std::fprintf(stderr,
              "[nvkcomp] f%ld vs=%d ps=%d SELF-COMPOSITE tex=0x%07X fetch %ux%u fmt%u filt=%u "
              "resolveImg=%ux%u vp={%.0f,%.0f,%.0f,%.0f} vte={%.0f,%.0f,%.0f,%.0f} blend=%08X "
              "-> sampler=%s%s\n",
              nf->frame, vsIdx, psIdx, tb, tw, th, fmt, (d.tf[3] >> 19) & 3u,
              rit != g_resolveTex.end() ? rit->second.w : 0u,
              rit != g_resolveTex.end() ? rit->second.h : 0u,
              d.vp[0], d.vp[1], d.vp[2], d.vp[3], d.vte[0], d.vte[1], d.vte[2], d.vte[3],
              d.blendReg, samplerIdx ? "NEAREST" : "LINEAR",
              nvkNoAlign ? " [RT_NVKNOALIGN]" : (nvkCompLin ? " [RT_NVKCOMPLIN]" : ""));
          }
        }
        // ★ RVK_TFCLAMP (2026-08-03): honor the fetch constant's ClampX field (tf0 [12:10]).
        // 2+ = clamp family -> CLAMP_TO_EDGE sampler variant (slots 2/3); 0/1 (wrap/mirror)
        // keep the REPEAT slots 0/1 = byte-identical for every draw that tiles. Applied AFTER
        // all filter decisions so the self-composite NEAREST snap keeps its filter, gains clamp.
        static const bool tfClampOff = [](){ const char* e = std::getenv("RVK_TFCLAMP"); return e && e[0]=='0' && !e[1]; }();
        if (!tfClampOff && d.tf[0] && (((d.tf[0] >> 10) & 7u) >= 2u)) samplerIdx += 2u;
      }
      uint8_t sc[512]; std::memset(sc, 0, sizeof sc);
      std::memcpy(sc + 0, &texIdx, 4);
      std::memcpy(sc + 192, &samplerIdx, 4);
      // ★ REGISTER-TRUE ALPHA TEST (2026-07-29, s2B leg-7 candidate 1). rom_ps49/ps50 run
      // `if (oCol.w < xrAthresh) discard;` reading SharedConstants+272 — and this block was a
      // plain memset-0, so athresh was unconditionally 0 on EVERY nvk draw and the guest's
      // fixed-function alpha kill never happened (the old renderer computes it at :5138-5159;
      // the demo's multiplicative shadow/light quads REQUIRE it — they were the attract-demo
      // black boxes). Same two registers, read from the device shadow by nvkReadDrawState
      // (RB_COLORCONTROL dev+0x293C, RB_ALPHA_REF dev+0x2904) instead of the PM4 register file.
      // The ps discard is the GREATEREQUAL family; funcs 4/6 map directly, anything else is
      // logged once and left un-emulated. RT_NVKATHRESH=<f> force-overrides (positive control).
      float athresh = 0.f;
      uint32_t cc = d.colorCtl, fn = cc & 7u;
      if (((cc >> 3) & 1u) && fn != 7u) {
        float aref; std::memcpy(&aref, &d.alphaRef, 4);
        if      (fn == 6u) athresh = aref;                 // GREATEREQUAL: pass a >= ref
        else if (fn == 4u) athresh = aref + 1.f / 512.f;   // GREATER: pass a > ref
        else {
          static std::set<uint32_t> nvkFnWarned;
          if (nvkFnWarned.insert(fn).second)
            std::fprintf(stderr, "[nvkat] unemulated ALPHA_FUNC %u (colorCtl=0x%08X ref=0x%08X) — no discard\n",
                         fn, cc, d.alphaRef);
        }
      }
      static const char* athreshEnv = std::getenv("RT_NVKATHRESH");
      static float athreshForce = athreshEnv ? (float)atof(athreshEnv) : 0.f;
      if (athreshEnv) athresh = athreshForce;
      std::memcpy(sc + 272, &athresh, 4);
      // [nvkat] census: every UNIQUE (colorCtl, alphaRef) pair seen on a VTE-off (field) draw,
      // printed once with the distinct-pair count so far. Cheap, always-on — the whole point is
      // to know from the ship log whether the field pass arms the test at all.
      if ((d.vteCntl & 1u) == 0u) {
        static std::set<uint64_t> nvkAtSeen;
        uint64_t atKey = ((uint64_t)d.colorCtl << 32) | (uint64_t)d.alphaRef;
        if (nvkAtSeen.insert(atKey).second) {
          float aref; std::memcpy(&aref, &d.alphaRef, 4);
          std::fprintf(stderr, "[nvkat] #%zu f%ld vs=%d ps=%d colorCtl=0x%08X (en=%u func=%u) ref=0x%08X (%.4f) -> athresh=%.4f\n",
                       nvkAtSeen.size(), nf->frame, vsIdx, psIdx, d.colorCtl,
                       (d.colorCtl >> 3) & 1u, fn, d.alphaRef, aref, athresh);
        }
      }
      auto shl = arenaAlloc(512); std::memcpy(shl.host, sc, 512);
      // RT_NVKDBG: full-frame batch census every 600th frame — compose-chain truth
      static bool nvkDbg = std::getenv("RT_NVKDBG") != nullptr;
      // ★ r23-w19: RVK_ONWASH lets a [washtrig] FIRE arm this census on the frames the fire
      //   already forces the filmstrip to dump (see the g_rvkWashForce comment at :2478).
      //   dbgTick() keeps the periodic CLEAN-frame population alive through the same code.
      static const bool onWashDbg = std::getenv("RVK_ONWASH") != nullptr;
      if (nvkDbg && (dbgTick() || (onWashDbg && g_rvkWashForce > 0))) {
        uint32_t tb = d.tf[1] ? (((d.tf[1] >> 12) & 0xFFFFF) << 12) : 0u;
        uint32_t tp[4] = {0,0,0,0};
        if (tb && g_base) for (int p = 0; p < 4; ++p) tp[p] = be32(tb + 0x2000u * (uint32_t)p);
        std::fprintf(stderr, "[nvkdbg] f%ld b%zu vs=%d ps=%d prim=%u n=%u st=%u tex=0x%07X(%ux%u fmt%u)->idx%u%s vp=%.0fx%.0f c14={%.3f,%.3f,%.3f,%.3f} texel={%08X,%08X,%08X,%08X}\n",
                     nf->frame, nbs.size(), vsIdx, psIdx, d.prim, d.count, d.strideB,
                     tb, tw, th, d.tf[1] & 0x3F, texIdx, g_resolveTex.count(tb) ? "<RESOLVE" : "",
                     d.vp[2], d.vp[3],
                     g_psConstF[56], g_psConstF[57], g_psConstF[58], g_psConstF[59],
                     tp[0], tp[1], tp[2], tp[3]);
        std::fprintf(stderr, "[nvkdbg]   blendReg=%08X vteCntl=%X\n", d.blendReg, d.vteCntl);
        if (vsIdx == 5)   // s2B leg 5: the settled-menu background quad — ps16's constant window
          std::fprintf(stderr, "[nvkdbg]   ps16 c0-7={%.3f,%.3f,%.3f,%.3f | %.3f,%.3f,%.3f,%.3f} c8-11={%.3f,%.3f,%.3f,%.3f} vs c0-3={%.3f,%.3f,%.3f,%.3f}\n",
                       g_psConstF[0], g_psConstF[1], g_psConstF[2], g_psConstF[3],
                       g_psConstF[4], g_psConstF[5], g_psConstF[6], g_psConstF[7],
                       g_psConstF[32], g_psConstF[33], g_psConstF[34], g_psConstF[35],
                       g_vsConstF[0], g_vsConstF[1], g_vsConstF[2], g_vsConstF[3]);
      }
      // RVK_TFALL=1 (2026-08-01 shadow-box register-truth probe): one-shot dump of ALL SIX fetch-
      // constant dwords per unique sampled base, with the fields our decode is known to ignore
      // decoded out (endian tf1[7:6], tf3 swizzle [11:0] as 4x3-bit dest selects). The ranking
      // shadow/frame atlases decode with wrong ALPHA while their RGB art is intact — the per-
      // texture truth for that has to live in these registers. Diagnostic only, default off.
      {
        static const bool tfAll = std::getenv("RVK_TFALL") && atoi(std::getenv("RVK_TFALL")) != 0;
        if (tfAll && d.tf[1]) {
          static std::unordered_map<uint32_t, int> tfSeen;
          uint32_t tfb = ((d.tf[1] >> 12) & 0xFFFFFu) << 12;
          if (!tfSeen.count(tfb)) {
            tfSeen[tfb] = 1;
            uint32_t sw = d.tf[3] & 0xFFFu;
            static const char* SWC = "XYZW01??";
            std::fprintf(stderr, "[tfall] base=0x%08X %ux%u fmt=%u endian=%u swz=%c%c%c%c "
                                 "tf={%08X %08X %08X %08X %08X %08X} vs=%d ps=%d blend=%08X\n",
                         tfb, (d.tf[2] & 0x1FFFu) + 1, ((d.tf[2] >> 13) & 0x1FFFu) + 1,
                         d.tf[1] & 0x3Fu, (d.tf[1] >> 6) & 3u,
                         SWC[sw & 7], SWC[(sw >> 3) & 7], SWC[(sw >> 6) & 7], SWC[(sw >> 9) & 7],
                         d.tf[0], d.tf[1], d.tf[2], d.tf[3], d.tf[4], d.tf[5],
                         vsIdx, psIdx, d.blendReg);
          }
        }
      }
      // RT_NVKFORCE bisect probe: VTE-off (field) draws get white texture + default alpha blend —
      // separates "geometry never rasterizes" from "content multiplies to black".
      static bool nvkForce = std::getenv("RT_NVKFORCE") != nullptr;
      uint32_t blendUse = d.blendReg;
      // ★ [shtexiso] (2026-08-01, ranking-shadow leg) — read the constants ps50 ACTUALLY consumes,
      // and optionally isolate the class. Must sit HERE, above the getOrCreateRealPipeline call
      // below, or an override lands a frame too late to matter.
      //   ps50 (byte-exact guest microcode, render/tools/xrgen/rom_ps50.hlsl:88-91) is
      //       oC0.xyz = texel.rgb * c14.rgb ;  oC0.w = texel.a * c15.x + c15.y
      //   so c14/c15 (g_psConstF[56..63]) are the only constants that can change this draw's
      //   output. An earlier census line here printed c2 — ps50 never reads c2, so that value was
      //   noise. If c14.rgb is ZERO the colour term vanishes: dst *= (1 - 0) = dst, the shadow
      //   simply does not draw, while oC0.w still writes and the quad's opaque footprint shows up
      //   as a rectangular alpha artefact. That is the user's report exactly — "each scoreboard
      //   has a shadow, it's not showing up, instead we're getting the transparent box".
      // RVK_SHTEXISO=1 → force REPLACE (src ONE / dst ZERO): paint the raw shader output so the
      //                  sampled shape is visible on its own. Tells sampling apart from blending.
      // RVK_SHTEXISO=2 → keep the guest blend but write RGB only (colorMask 0x7), i.e. stop this
      //                  class from touching destination alpha. Candidate fix, not a diagnostic.
      uint32_t shIsoMask = 0xFu;
      {
        static const int shIso = std::getenv("RVK_SHTEXISO") ? std::atoi(std::getenv("RVK_SHTEXISO")) : 0;
        static const uint32_t shIsoBlend = std::getenv("RVK_SHTEXBLEND")
            ? (uint32_t)strtoul(std::getenv("RVK_SHTEXBLEND"), nullptr, 16) : 0x05000500u;
        if (d.blendReg == shIsoBlend) {
          static long shIsoN = 0;
          if ((++shIsoN % 500) == 1)
            std::fprintf(stderr, "[shtexiso] blend=%08X draw#%ld f%ld vs=%d ps=%d "
                                 "c14={%.4f,%.4f,%.4f,%.4f} c15={%.4f,%.4f,%.4f,%.4f} iso=%d\n",
                         d.blendReg, shIsoN, nf->frame, vsIdx, psIdx,
                         g_psConstF[56], g_psConstF[57], g_psConstF[58], g_psConstF[59],
                         g_psConstF[60], g_psConstF[61], g_psConstF[62], g_psConstF[63], shIso);
          // ★ 2026-08-03 shadow-base census: one line per UNIQUE (texBase,texFmt) this class
          // binds. Decides wrong-base vs stale-content: if the shadow class binds the COLOUR
          // atlas base while a separate silhouette atlas exists (capture r7762, black margins),
          // the defect is upstream of any cache revalidation.
          { static std::set<uint64_t> shBases;
            uint32_t shTb  = d.tf[1] ? (((d.tf[1] >> 12) & 0xFFFFFu) << 12) : 0u;
            uint32_t shFmt = d.tf[1] & 0x3Fu;
            uint32_t shTw  = (d.tf[2] & 0x1FFFu) + 1u, shTh = ((d.tf[2] >> 13) & 0x1FFFu) + 1u;
            uint64_t bk = ((uint64_t)shTb << 8) | shFmt;
            if (shBases.size() < 24 && shBases.insert(bk).second)
              std::fprintf(stderr, "[shbase] shadow-class tex base=0x%X fmt=%u %ux%u tf3=%08X f%ld\n",
                           shTb, shFmt, shTw, shTh, d.tf[3], nf->frame); }
          // ★ RVK_RDCCAP=1 (2026-08-01) — SELF-TARGETING RENDERDOC CAPTURE.
          // The remaining question ("which draw authors the rectangular box behind the plaque")
          // is a pixel-history question, and pixel history needs exactly one frame — which
          // dissolves the cross-boot frame-alignment problem that blocked the A/B above. But the
          // ranking screen is a narrow window in the attract cycle and `renderdoccmd capture` has
          // no capture-frame-N option, so an F12 by hand is the only other way to hit it.
          // Instead: trigger from inside, on the condition that IS the frame we want — this blend
          // class drawing with the plaque fade (c15.x) at full. No frame numbers to guess and it
          // survives boot-timing drift. Inert unless the process is hooked (GetModuleHandle
          // returns null when running outside RenderDoc), and inert unless the lever is set.
          // RVK_RDCCAP_FADE overrides the fade threshold; RVK_RDCCAP_N how many frames to grab.
          {
            static const bool rdcCap = std::getenv("RVK_RDCCAP") && atoi(std::getenv("RVK_RDCCAP")) != 0;
            static const float rdcFade = std::getenv("RVK_RDCCAP_FADE") ? (float)atof(std::getenv("RVK_RDCCAP_FADE")) : 0.9f;
            static const uint32_t rdcFrames = std::getenv("RVK_RDCCAP_N") ? (uint32_t)atoi(std::getenv("RVK_RDCCAP_N")) : 3u;
            if (rdcCap && g_psConstF[60] >= rdcFade) {
              static RENDERDOC_API_1_1_2* rdoc = []() -> RENDERDOC_API_1_1_2* {
                HMODULE m = GetModuleHandleA("renderdoc.dll");
                if (!m) { std::fprintf(stderr, "[rdccap] RVK_RDCCAP set but renderdoc.dll is not loaded "
                                               "— launch via _tmpscripts/shadow_rdc.sh\n"); return nullptr; }
                pRENDERDOC_GetAPI getApi = (pRENDERDOC_GetAPI)GetProcAddress(m, "RENDERDOC_GetAPI");
                RENDERDOC_API_1_1_2* a = nullptr;
                if (!getApi || getApi(eRENDERDOC_API_Version_1_1_2, (void**)&a) != 1) {
                  std::fprintf(stderr, "[rdccap] RENDERDOC_GetAPI failed\n"); return nullptr;
                }
                std::fprintf(stderr, "[rdccap] RenderDoc in-app API acquired\n");
                return a;
              }();
              // RVK_RDCCAP_EVERY=<sec> (2026-08-01, play-session repro): re-arm after a cooldown
              // so a REAL play session banks a capture at every ranking visit — the box only
              // manifests after long play, so the LAST captures are the evidence. RVK_RDCCAP_MAX
              // bounds disk (each fire = RVK_RDCCAP_N frames x ~40MB). Unset = one-shot as before.
              static const uint32_t rdcEverySec = std::getenv("RVK_RDCCAP_EVERY") ? (uint32_t)atoi(std::getenv("RVK_RDCCAP_EVERY")) : 0u;
              static const uint32_t rdcMaxFires = std::getenv("RVK_RDCCAP_MAX") ? (uint32_t)atoi(std::getenv("RVK_RDCCAP_MAX")) : 8u;
              static uint32_t rdcFires = 0;
              static uint64_t rdcLastMs = 0;
              const uint64_t rdcNowMs = (uint64_t)std::chrono::duration_cast<std::chrono::milliseconds>(
                  std::chrono::steady_clock::now().time_since_epoch()).count();
              const bool rdcArmed = rdcEverySec
                  ? (rdcFires < rdcMaxFires && rdcNowMs - rdcLastMs >= (uint64_t)rdcEverySec * 1000ull)
                  : (rdcFires == 0);
              if (rdoc && rdcArmed) {
                ++rdcFires; rdcLastMs = rdcNowMs;
                rdoc->TriggerMultiFrameCapture(rdcFrames);
                std::fprintf(stderr, "[rdccap] ★ TRIGGERED %u-frame capture at f%ld — blend=%08X "
                                     "vs=%d ps=%d tb=0x%08X c14=%.4f c15.x=%.4f (fade>=%.2f)\n",
                             rdcFrames, nf->frame, d.blendReg, vsIdx, psIdx,
                             ((d.tf[1] >> 12) & 0xFFFFFu) << 12, g_psConstF[56], g_psConstF[60], rdcFade);
              }
            }
          }
          if (shIso == 1) blendUse = 0x00010001u;      // src ONE / dst ZERO = replace
          else if (shIso == 2) shIsoMask = 0x7u;       // RGB only, leave destination alpha alone
          // ★ iso=3 = the CLEAN A/B arm. RVK_MODOFF `continue`s the draw, which changes the draw
          // count and perturbs frame pacing — its diff against a control came back contaminated by
          // scroll phase. colorMask 0 keeps the draw, the batch and the timing exactly as they
          // were and merely writes no channels, so the control and this arm stay frame-locked
          // (the iso=2 pair produced 5 bit-identical frames) and the diff is the class's exact
          // screen contribution, pixel-for-pixel.
          else if (shIso == 3) shIsoMask = 0x0u;       // write nothing; identical draw + timing
        }
      }
      if (nvkForce && (d.vteCntl & 1u) == 0u) { texIdx = 0; blendUse = 0; std::memcpy(sc + 0, &texIdx, 4); std::memcpy(shl.host, sc, 512); }
      // leg 10 item 1: the target's colour format is part of the pipeline's identity. Batches are
      // always recorded (recordSeg) before curRT changes, so curRT here IS the target this pipeline
      // will be bound in.
      VkPipeline pipe = getOrCreateRealPipeline((uint32_t)vsIdx, (uint32_t)psIdx, blendUse, shIsoMask,
                                                curRT ? curRT->fmt : g_rtFmt);
      if (!pipe) { if ((++badDrawN % 300) == 1) std::fprintf(stderr, "[nvk] no pipeline vs=%d ps=%d x%ld — draw skipped\n", vsIdx, psIdx, badDrawN); continue; }
      // viewport: register-true guest viewport (sanity-clamped)
      VkViewport vp{0.f, 0.f, (float)kW, (float)kH, 0.f, 1.f};
      if (d.vp[2] > 0.f && d.vp[2] <= 4096.f && d.vp[3] > 0.f && d.vp[3] <= 4096.f) {
        vp.x = d.vp[0]; vp.y = d.vp[1]; vp.width = d.vp[2]; vp.height = d.vp[3];
      }
      // ---- vertex decode, keyed on TRUE stride + bound VS class ----
      uint32_t n = d.count;
      uint32_t maxNi = ni + (d.prim == 8 ? (n / 3) * 6 : (n > 2 ? (n - 2) * 3 : 0));
      uint32_t maxNv = nv + (d.prim == 8 ? (n / 3) * 4 : n);
      // ★ SILENT PARTIAL-FRAME CLASS, now LOUD (2026-07-31 compose leg): this `break` abandons
      // EVERY remaining draw of the frame — the exact "element dropout / partial-frame compose"
      // shape BACKLOG #0 suspects — and it had no instrument at all. Logging only (rate-limited);
      // the drop behaviour itself is unchanged (a real fix would grow the buffers or split the
      // frame, and must not be guessed at without evidence that this ever fires).
      if (maxNv > kMaxVerts || maxNi > kMaxIndices) {
        static long vbTrunc = 0;
        if ((++vbTrunc % 100) == 1)
          std::fprintf(stderr, "[nvktrunc] f%ld VERTEX-BUDGET TRUNCATION x%ld: draw %d/%d dropped and ALL after it "
                               "(nv=%u+%u/%u ni=%u+%u/%u) — partial frame\n",
                       nf->frame, vbTrunc, di, nf->nDraws, nv, maxNv - nv, kMaxVerts, ni, maxNi - ni, kMaxIndices);
        break;
      }
      const uint8_t* src = nf->vtxBlob + d.vtxOff;
      auto gbe = [&](uint32_t off) { uint32_t v; std::memcpy(&v, src + off, 4); return __builtin_bswap32(v); };
      bool xyuv = (vsIdx == 48);   // host layout {x,y,u,v,-,-} vs {x,y,z,color,u,v}
      auto looksFloat = [](uint32_t v) { uint32_t e = (v >> 23) & 0xFF; return v == 0 || (e >= 113 && e <= 143); };
      // int32 {x,y,u,v} sprite records are a VTE-OFF (game-field) idiom; VTE-ON st=16 records
      // are float {x,y,u,v} quads (shell window-quad class vs5/ps16 — settled-menu background,
      // field compose). The float sniff alone misfired on them: a fullscreen quad's x0 is guest
      // matrix dust (-3e-5, exponent 112, one below the looksFloat window) -> whole quad decoded
      // as int garbage -> the wallpaper-then-black dark wash (s2B leg 5). Gate on the same
      // register-true PA_CL_VTE_CNTL bit the transform ladder uses.
      // ★ s2B leg 12 — THE SNIFF DWORD MUST CARRY INFORMATION. `gbe(0)` is the x of vertex 0, and
      // an all-zero dword is ambiguous: it is float 0.0 AND int 0, so `looksFloat` answers "float"
      // for it (the `v == 0` clause). The panel-BACKGROUND tile grid (guest FUN_880FFCE8 /
      // FUN_881538C0 id 0x170, 32-px steps starting at x=0,y=0 — one vs45/ps50 prim=8 batch of
      // 480 int32 {x,y,u,v} records = 80 tiles x 2 sprites) therefore presented 00000000 and the
      // WHOLE batch decoded as floats: 0x20/0x40/0x60... became denormals ~0, so all 160 rects
      // collapsed onto the origin and the background fill VANISHED. Banked proof, d1 boot f2100:
      //   [nvkrect] f2100 d5 vs=45 prim=8 n=480 st=16 int16=0 sniff=00000000
      //   r1 ... raw={00000000 00000020 ...}  r8 ... raw={00000020 00000000 ...}
      // Fix: when vertex 0's x is all-zero, walk forward to the first dword that is NOT zero and
      // sniff THAT. Every draw whose gbe(0) is non-zero is bit-identical to before, so nothing
      // that renders today can change class. RT_NVKOLDSNIFF=1 restores the leg-5 single-dword sniff.
      static bool oldSniff = std::getenv("RT_NVKOLDSNIFF") != nullptr;
      uint32_t sniffDw = gbe(0);
      if (!oldSniff && d.strideB == 16 && sniffDw == 0u) {
        uint32_t probeV = d.count < 16u ? d.count : 16u;
        for (uint32_t k = 0; k < probeV && sniffDw == 0u; ++k)
          for (uint32_t c = 0; c < 4u && sniffDw == 0u; ++c) sniffDw = gbe(k * 16u + c * 4u);
      }
      bool i16int = (d.strideB == 16) && (d.vteCntl & 1u) == 0u && !looksFloat(sniffDw);
      auto decodeVert = [&](uint32_t k, uint32_t* dd) {
        uint32_t rb = k * d.strideB;
        if (d.strideB == 16) {
          if (i16int) { for (int c = 0; c < 4; ++c) { float f = (float)(int32_t)gbe(rb + (uint32_t)c * 4); std::memcpy(&dd[c], &f, 4); } }
          else        { for (int c = 0; c < 4; ++c) dd[c] = gbe(rb + (uint32_t)c * 4); }
          if (xyuv) { dd[4] = 0; dd[5] = 0; }
          else {   // {x,y,u,v} float rect for a pos/color/uv shader: z=0, white, uv from 2,3
            uint32_t u = dd[2], v2 = dd[3];
            float zf = 0.f; std::memcpy(&dd[2], &zf, 4); dd[3] = 0xFFFFFFFFu; dd[4] = u; dd[5] = v2;
          }
        } else if (d.strideB == 12) {   // {x,y,color} matte band
          dd[0] = gbe(rb + 0); dd[1] = gbe(rb + 4);
          float zf = 0.f; std::memcpy(&dd[2], &zf, 4);
          dd[3] = gbe(rb + 8); dd[4] = 0; dd[5] = 0;
        } else if (d.strideB == 28) {   // {x,y,z,(w),color,u,v}
          dd[0] = gbe(rb + 0); dd[1] = gbe(rb + 4); dd[2] = gbe(rb + 8);
          dd[3] = gbe(rb + 16); dd[4] = gbe(rb + 20); dd[5] = gbe(rb + 24);
          if (xyuv) { uint32_t u = dd[4], v2 = dd[5]; dd[2] = u; dd[3] = v2; dd[4] = 0; dd[5] = 0; }
        } else if (d.strideB == 24 && xyuv) {   // bsf24: normalized uv -> pixel-space for vs48
          dd[0] = gbe(rb + 0); dd[1] = gbe(rb + 4);
          uint32_t ub = gbe(rb + 16), vb = gbe(rb + 20); float uf, vf;
          std::memcpy(&uf, &ub, 4); std::memcpy(&vf, &vb, 4);
          uf *= (float)tw; vf *= (float)th;
          std::memcpy(&dd[2], &uf, 4); std::memcpy(&dd[3], &vf, 4);
          dd[4] = 0; dd[5] = 0;
        } else {                        // generic: first 6 dwords of the record (pad zeros)
          uint32_t have = d.strideB / 4; if (have > 6) have = 6;
          for (uint32_t c = 0; c < 6; ++c) dd[c] = (c < have) ? gbe(rb + c * 4) : 0;
        }
      };
      // RT_NVKHOLE (s2B leg 7): the gameplay compose hole — census every LARGE draw in
      // offscreen-RT segments (the hole-filler hides deep in the ~449-draw field pass, beyond
      // the di<6 window of [nvkvtx]). Prints decoded rect extents + full sampling identity.
      static bool holeDbg = std::getenv("RT_NVKHOLE") != nullptr;
      if (holeDbg && curRT && dbgTick()) {
        float xmin = 1e9f, xmax = -1e9f, ymin = 1e9f, ymax = -1e9f;
        uint32_t nProbe = d.count < 4 ? d.count : 4;
        for (uint32_t k = 0; k < nProbe; ++k) {
          uint32_t dd[6]; decodeVert(k, dd);
          float fx, fy; std::memcpy(&fx, &dd[0], 4); std::memcpy(&fy, &dd[1], 4);
          if (fx < xmin) xmin = fx; if (fx > xmax) xmax = fx;
          if (fy < ymin) ymin = fy; if (fy > ymax) ymax = fy;
        }
        if (xmax - xmin >= 200.f && ymax - ymin >= 200.f) {
          uint32_t tb = d.tf[1] ? (((d.tf[1] >> 12) & 0xFFFFF) << 12) : 0u;
          std::fprintf(stderr, "[nvkhole] f%ld d%d rect={%.0f,%.0f..%.0f,%.0f} prim=%u n=%u st=%u vs=%d ps=%d tex=0x%07X(%ux%u fmt%u)%s blend=%08X vte=%X vp=%.0fx%.0f\n",
                       nf->frame, di, xmin, ymin, xmax, ymax, d.prim, d.count, d.strideB,
                       vsIdx, psIdx, tb, tw, th, d.tf[1] & 0x3F,
                       g_resolveTex.count(tb) ? "<RESOLVE" : "", d.blendReg, d.vteCntl,
                       d.vp[2], d.vp[3]);
        }
      }
      // ★ RVK_QUADCENSUS per-draw line (armed-frame block above the loop) — EXECUTOR-TRUE
      // geometry: goes through decodeVert (the same per-class decode the batches render with,
      // incl. the int32 {x,y,u,v} st=16 sprite sniff), so the printed bbox is exactly what the
      // GPU will see. pos = dd[0],dd[1]; uv = dd[4],dd[5] (vs48 xyuv keeps uv in dd[2],dd[3]).
      // First vertex also dumped raw so an unknown class is still interpretable offline.
      if (qcThis && nf->vtxBlob && d.strideB >= 8
          && d.vtxOff + (uint64_t)d.count * d.strideB <= nf->vtxBytes) {
        float x0 = 1e9f, y0 = 1e9f, x1 = -1e9f, y1 = -1e9f;
        float u0 = 1e9f, v0 = 1e9f, u1 = -1e9f, v1 = -1e9f;
        for (uint32_t k = 0; k < d.count; ++k) {
          uint32_t dd[6]; decodeVert(k, dd);
          float fx, fy, fu, fv;
          std::memcpy(&fx, &dd[0], 4); std::memcpy(&fy, &dd[1], 4);
          std::memcpy(&fu, &dd[xyuv ? 2 : 4], 4); std::memcpy(&fv, &dd[xyuv ? 3 : 5], 4);
          if (fx < x0) x0 = fx; if (fx > x1) x1 = fx;
          if (fy < y0) y0 = fy; if (fy > y1) y1 = fy;
          if (fu < u0) u0 = fu; if (fu > u1) u1 = fu;
          if (fv < v0) v0 = fv; if (fv > v1) v1 = fv;
        }
        uint32_t qtb = d.tf[1] ? (((d.tf[1] >> 12) & 0xFFFFFu) << 12) : 0u;
        std::fprintf(stderr,
          "[quadcensus] f%ld d%d rt=%s vs=%d ps=%d prim=%u n=%u st=%u tex=0x%07X %ux%u fmt%u idx=%u%s "
          "xy={%.1f,%.1f..%.1f,%.1f} uv={%.1f,%.1f..%.1f,%.1f} vte=%X blend=%08X int16=%d raw0={%08X %08X %08X %08X}\n",
          nf->frame, di, curRT ? "off" : "disp", vsIdx, psIdx, d.prim, d.count, d.strideB,
          qtb, tw, th, d.tf[1] & 0x3Fu, texIdx, (qtb && g_resolveTex.count(qtb)) ? "<RESOLVE" : "",
          x0, y0, x1, y1, u0, v0, u1, v1,
          (unsigned)d.vteCntl, d.blendReg, (int)i16int,
          gbe(0), d.strideB >= 8 ? gbe(4) : 0u, d.strideB >= 12 ? gbe(8) : 0u, d.strideB >= 16 ? gbe(12) : 0u);
      }
      static bool vtxDbg = std::getenv("RT_NVKDBG") != nullptr;
      if (vtxDbg && dbgTick() && di < 6) {
        uint32_t dd0[6]; decodeVert(0, dd0);
        float f0[6]; std::memcpy(f0, dd0, 24);
        uint32_t dd1[6]; decodeVert(d.count > 1 ? 1 : 0, dd1);
        float f1[6]; std::memcpy(f1, dd1, 24);
        std::fprintf(stderr, "[nvkvtx] f%ld d%d vs=%d int16=%d v0={%.1f,%.1f,%.1f,%08X,%.1f,%.1f} v1={%.1f,%.1f,%.1f,%08X,%.1f,%.1f} raw0=%08X %08X %08X %08X\n",
                     nf->frame, di, vsIdx, (int)i16int,
                     f0[0], f0[1], f0[2], dd0[3], f0[4], f0[5],
                     f1[0], f1[1], f1[2], dd1[3], f1[4], f1[5],
                     gbe(0), gbe(4), gbe(8), gbe(12));
      }
      // ★ RT_NVKVTXALL=<vsIdx> (s2B leg 12) — FULL per-RECT census. [nvkvtx] above only ever
      // dumps 2 verts of the first 6 draws per censused frame, so the ~450 LEGAL glyph rects
      // (vs=45) have NEVER been observed in any bank. This prints every rect's three real
      // corners (decoded x/y/u/v) plus the sniff dword the int/float discriminator keyed on.
      // Lever-gated + line-capped; unset => byte-identical to before.
      static const char* vtxAllEnv = std::getenv("RT_NVKVTXALL");
      static int vtxAllVs = vtxAllEnv ? atoi(vtxAllEnv) : -1;
      static long vtxAllLines = 0;
      if (vtxAllVs >= 0 && dbgTick() && vsIdx == vtxAllVs && vtxAllLines < 6000) {
        std::fprintf(stderr, "[nvkrect] f%ld d%d vs=%d ps=%d prim=%u n=%u st=%u int16=%d sniff=%08X vte=%X c14=%.3f\n",
                     nf->frame, di, vsIdx, psIdx, d.prim, d.count, d.strideB, (int)i16int,
                     sniffDw, d.vteCntl, g_psConstF[56]);
        ++vtxAllLines;
        uint32_t nDump = d.count > 240u ? 240u : d.count;
        for (uint32_t k = 0; k + 2 < nDump; k += 3) {
          uint32_t a[6], b[6], c[6]; decodeVert(k, a); decodeVert(k + 1, b); decodeVert(k + 2, c);
          float fa[6], fb[6], fc[6];
          std::memcpy(fa, a, 24); std::memcpy(fb, b, 24); std::memcpy(fc, c, 24);
          std::fprintf(stderr, "[nvkrect]   r%u v0={%.1f,%.1f uv %.1f,%.1f} v1={%.1f,%.1f uv %.1f,%.1f} v2={%.1f,%.1f uv %.1f,%.1f} raw={%08X %08X %08X %08X | %08X %08X %08X %08X | %08X %08X %08X %08X}\n",
                       k / 3, fa[0], fa[1], fa[4], fa[5], fb[0], fb[1], fb[4], fb[5],
                       fc[0], fc[1], fc[4], fc[5],
                       gbe((k + 0) * d.strideB + 0), gbe((k + 0) * d.strideB + 4),
                       gbe((k + 0) * d.strideB + 8), gbe((k + 0) * d.strideB + 12),
                       gbe((k + 1) * d.strideB + 0), gbe((k + 1) * d.strideB + 4),
                       gbe((k + 1) * d.strideB + 8), gbe((k + 1) * d.strideB + 12),
                       gbe((k + 2) * d.strideB + 0), gbe((k + 2) * d.strideB + 4),
                       gbe((k + 2) * d.strideB + 8), gbe((k + 2) * d.strideB + 12));
          if (++vtxAllLines >= 6000) break;
        }
      }
      // ★ [nvkring] s2B leg 11 — PANEL DROP-SHADOW RING census, always on, self-throttled.
      // stride 12 ({x,y,colour}: no UV, no texture — FUN_8209D660(dev,0,0,..) unbinds stage 0)
      // is the ring's unique signature in the entire stream: guest FUN_82182008 is its only
      // author (4 edge tristrips prim=6 n=4 + 4 six-segment corner fans prim=5 n=7, 1x/frame,
      // inner 0xFF080808 at the panel edge, outer 0x00000000 pushed 16px out). Logging vs/ps/
      // blend/target/colour here means a boot log ALONE decides whether the ring can reach
      // pixels — the leg-10 "furniture flows natively" claim died for want of exactly this.
      if (d.strideB == 12) {
        static long ringN = 0; long rn = ringN++;
        // ★ ALIASING FIX (2026-07-31 ranking-square leg): the old period was 4800, and the ring is
        // exactly 8 draws per frame — 4800 % 8 == 0, so EVERY banked sample after #9 was the same
        // strip (the top edge) of the same window, and the leg-11 bank never once showed the other
        // seven. 4793 is prime, so the sample walks all 8 slots. Same line rate, same format.
        if (rn < 10 || (rn % 4793) == 0) {
          uint32_t da[6], db[6]; decodeVert(0, da); decodeVert(d.count > 1 ? d.count - 1 : 0, db);
          float ax, ay, bx, by;
          std::memcpy(&ax, &da[0], 4); std::memcpy(&ay, &da[1], 4);
          std::memcpy(&bx, &db[0], 4); std::memcpy(&by, &db[1], 4);
          std::fprintf(stderr, "[nvkring] #%ld f%ld vs=%d ps=%d prim=%u n=%u blend=%08X vte=%X "
                               "rt=%s v0={%.1f,%.1f,%08X} vN={%.1f,%.1f,%08X}\n",
                       rn, nf->frame, vsIdx, psIdx, d.prim, d.count, blendUse, d.vteCntl,
                       curRT ? "offscreen" : "DISPLAY", ax, ay, da[3], bx, by, db[3]);
        }
      }
      // ★ RVK_SHADOWDUMP=<everyN> (2026-07-31 ranking drop-shadow leg) — SCREEN-SPACE draw dump.
      // [nvkring] above prints GUEST-SPACE vertices only, and it self-throttles on a stride-12
      // counter whose period (4800) is an exact multiple of the 8-draw ring, so every banked
      // sample is the SAME strip of the SAME window: the ranking plaques' own rings have never
      // been observed. This dump applies the shell VS's own transform (c10..c13 = the matrix rows
      // vs15/idx5 dot against, see the spirv-dis of g_futari_spirv_21) plus the batch viewport, so
      // a log line states WHERE ON GLASS a draw lands — the only way to tie a pixel defect to a
      // draw without a frame debugger. Every draw of every Nth frame; stride-12 draws additionally
      // print all their vertices with colour. Default off => byte-identical.
      //   RVK_SHADOWDUMP=<N>    dump all draws of every Nth frame
      //   RVK_SHADOWDUMPST=12   restrict the dump to one vertex stride (0 = all)
      static const char* shDumpEnv = std::getenv("RVK_SHADOWDUMP");
      static long shDumpEvery = shDumpEnv ? atol(shDumpEnv) : 0;
      static long shDumpStride = std::getenv("RVK_SHADOWDUMPST") ? atol(std::getenv("RVK_SHADOWDUMPST")) : 0;
      static long shDumpLines = 0;
      if (shDumpEvery > 0 && shDumpLines < 200000 && (nf->frame % shDumpEvery) == 0 &&
          (shDumpStride == 0 || (long)d.strideB == shDumpStride)) {
        const float* m0 = &g_vsConstF[40];   // c10
        const float* m1 = &g_vsConstF[44];   // c11
        const float* m3 = &g_vsConstF[52];   // c13 (w row)
        // ★ 2026-07-31 TRANSFORM FIX. This dump used to apply the matrix + NDC->viewport mapping
        // unconditionally, which is only correct when the hardware viewport transform is ENABLED
        // (PA_CL_VTE_CNTL bits0-5 = XYZ scale/offset enables, all set). With those bits clear the
        // guest has already emitted WINDOW coordinates for the current target and the hardware
        // applies no viewport mapping at all (same rule the renderer itself uses at the RVK_VTEVP
        // site above), so the old formula reported meaningless positions. That was not a corner
        // case: the entire modulate-blend shadow class of the ranking screen is vte=0x400, i.e.
        // every position this dump has ever printed for the draws under investigation was wrong.
        const bool vpXform = (d.vteCntl & 0x3Fu) == 0x3Fu;
        auto toScreen = [&](const uint32_t* dd, float* sx, float* sy) {
          float x, y, z; std::memcpy(&x, &dd[0], 4); std::memcpy(&y, &dd[1], 4); std::memcpy(&z, &dd[2], 4);
          if (!vpXform) { *sx = x; *sy = y; return; }   // pre-transformed: already window coords
          float X = m0[0]*x + m0[1]*y + m0[2]*z + m0[3];
          float Y = m1[0]*x + m1[1]*y + m1[2]*z + m1[3];
          float W = m3[0]*x + m3[1]*y + m3[2]*z + m3[3];
          if (W == 0.f || W != W) W = 1.f;
          *sx = vp.x + ((X / W) * 0.5f + 0.5f) * vp.width;
          *sy = vp.y + ((-Y / W) * 0.5f + 0.5f) * vp.height;
        };
        float bx0 = 1e9f, by0 = 1e9f, bx1 = -1e9f, by1 = -1e9f;
        uint32_t nProbe = d.count < 64u ? d.count : 64u;
        for (uint32_t k = 0; k < nProbe; ++k) {
          uint32_t dd[6]; decodeVert(k, dd); float sx, sy; toScreen(dd, &sx, &sy);
          if (sx < bx0) bx0 = sx; if (sx > bx1) bx1 = sx;
          if (sy < by0) by0 = sy; if (sy > by1) by1 = sy;
        }
        uint32_t tbD = d.tf[1] ? (((d.tf[1] >> 12) & 0xFFFFFu) << 12) : 0u;
        std::fprintf(stderr, "[shdump] f%ld d%d vs=%d ps=%d prim=%u n=%u st=%u tex=0x%07X blend=%08X vte=%X rt=%s "
                             "scr[%s]={%.1f,%.1f..%.1f,%.1f} size=%.0fx%.0f vp={%.0f,%.0f,%.0f,%.0f} c2={%.3f,%.3f,%.3f,%.3f}\n",
                     nf->frame, di, vsIdx, psIdx, d.prim, d.count, d.strideB, tbD, blendUse, d.vteCntl,
                     curRT ? "offscreen" : "DISPLAY", vpXform ? "vp" : "raw", bx0, by0, bx1, by1,
                     bx1 - bx0, by1 - by0,
                     vp.x, vp.y, vp.width, vp.height,
                     g_psConstF[8], g_psConstF[9], g_psConstF[10], g_psConstF[11]);
        ++shDumpLines;
        if (d.strideB == 12 || d.strideB == 16) {
          uint32_t nv12 = d.count < 16u ? d.count : 16u;
          for (uint32_t k = 0; k < nv12; ++k) {
            uint32_t dd[6]; decodeVert(k, dd); float sx, sy;
            float gx, gy; std::memcpy(&gx, &dd[0], 4); std::memcpy(&gy, &dd[1], 4);
            toScreen(dd, &sx, &sy);
            // ★ 2026-07-31 (2nd instrument fix tonight): print the UVs.
            // The stride-16 layout is {x,y,u,v} — decodeVert() moves dwords 2,3 into the uv slots
            // and SYNTHESISES dd[3]=0xFFFFFFFF white. So the old "col=%08X" printed that
            // hardcoded constant on every vertex, never any real data, while the texture
            // coordinates — the one thing that decides whether the ranking-plaque shadow quads
            // sample a shaped sprite or a flat region — were never shown at all.
            float u, v; std::memcpy(&u, &dd[4], 4); std::memcpy(&v, &dd[5], 4);
            std::fprintf(stderr, "[shdump]   v%u guest={%.1f,%.1f} scr={%.1f,%.1f} uv={%.5f,%.5f} synthcol=%08X\n",
                         k, gx, gy, sx, sy, (double)u, (double)v, dd[3]);
            ++shDumpLines;
          }
        }
      }
      // ★ RVK_SHTEXAUTO=1 (2026-08-01) — drive the [shtex] texel analyser FROM THE DRAW CLASS.
      // RVK_SHTEXBLEND=<hex RB_BLENDCONTROL> selects the class (default 0x05000500, the ranking
      // plaque's modulate shadow: src ZERO / dst ONE_MINUS_SRC_COLOR). Prints a one-line census of
      // the class — which is the difference between "the transparent texels are clean" and "the
      // class never drew in this run", two results the first cut could not tell apart — then arms
      // the analyser with THIS draw's texture base and UV bbox and drops the texture-cache entry so
      // the next sample re-decodes with the request live. Diagnostic only, default off.
      {
        static const bool shTexAuto = std::getenv("RVK_SHTEXAUTO") && atoi(std::getenv("RVK_SHTEXAUTO")) != 0;
        static const uint32_t shTexBlend = std::getenv("RVK_SHTEXBLEND")
            ? (uint32_t)strtoul(std::getenv("RVK_SHTEXBLEND"), nullptr, 16) : 0x05000500u;
        if (shTexAuto && d.blendReg == shTexBlend && d.tf[1]) {
          static long shAutoN = 0, shAutoArmed = 0;
          uint32_t tbA = ((d.tf[1] >> 12) & 0xFFFFFu) << 12;
          uint32_t fmtA = d.tf[1] & 0x3Fu;
          uint32_t twA = (d.tf[2] & 0x1FFF) + 1, thA = ((d.tf[2] >> 13) & 0x1FFF) + 1;
          // UV bbox in whatever units the vertices carry (this class is TEXEL units, 0..dim).
          float u0 = 1e9f, v0 = 1e9f, u1 = -1e9f, v1 = -1e9f;
          uint32_t nP = d.count < 64u ? d.count : 64u;
          for (uint32_t k = 0; k < nP; ++k) {
            uint32_t dd[6]; decodeVert(k, dd);
            float u, v; std::memcpy(&u, &dd[4], 4); std::memcpy(&v, &dd[5], 4);
            if (u < u0) u0 = u; if (u > u1) u1 = u;
            if (v < v0) v0 = v; if (v > v1) v1 = v;
          }
          // Normalized UVs would give a 0..1 bbox; scale those up so the rect is always texels.
          bool normalized = (u1 <= 1.5f && v1 <= 1.5f);
          if (normalized) { u0 *= twA; u1 *= twA; v0 *= thA; v1 *= thA; }
          if ((++shAutoN % 500) == 1)
            std::fprintf(stderr, "[shtexcensus] blend=%08X draw#%ld f%ld vs=%d ps=%d prim=%u n=%u st=%u "
                                 "tb=0x%08X %ux%u fmt=%u vte=%X uv%s=[%.1f,%.1f..%.1f,%.1f] rt=%s\n",
                         d.blendReg, shAutoN, nf->frame, vsIdx, psIdx, d.prim, d.count, d.strideB,
                         tbA, twA, thA, fmtA, d.vteCntl, normalized ? "(norm->texel)" : "(texel)",
                         u0, v0, u1, v1, curRT ? "offscreen" : "DISPLAY");
          // Arm the analyser for the first 3 distinct bases of the class, once each.
          if (tbA && shAutoArmed < 3 && g_shtexReq.base != tbA && u1 > u0 && v1 > v0) {
            static std::set<uint32_t> armedBases;
            if (armedBases.insert(tbA).second) {
              ++shAutoArmed;
              g_shtexReq.base = tbA;
              g_shtexReq.x0 = (uint32_t)(u0 < 0.f ? 0.f : u0);
              g_shtexReq.y0 = (uint32_t)(v0 < 0.f ? 0.f : v0);
              g_shtexReq.x1 = (uint32_t)(u1 + 0.5f);
              g_shtexReq.y1 = (uint32_t)(v1 + 0.5f);
              g.rTexIndex.erase(((uint64_t)tbA << 8) | fmtA);   // force a re-decode with the request live
              std::fprintf(stderr, "[shtexcensus] ARMED analyser: base=0x%08X rect=[%u,%u..%u,%u]\n",
                           tbA, g_shtexReq.x0, g_shtexReq.y0, g_shtexReq.x1, g_shtexReq.y1);
            }
          }
        }
      }
      // ★ RVK_STRIPLOG=1 (2026-08-03, char-select water-band) — log EVERY draw of the opaque
      // strip-copy class (blend 0x00010001) for the first N frames after arm: frame, vs/ps,
      // texture base+dims+fmt, UV bbox. The band author (frame1228 EID 1546/1550) is in this
      // class; the question RVK_TFCLAMP could not answer is whether its UVs leave [0,1]
      // (addressing) or its BASE is the wrong art page vs its neighbours (stale fetch slot).
      // Diagnostic only, default off.
      {
        static const int stripLogN = [](){ const char* e = std::getenv("RVK_STRIPLOG"); return e ? atoi(e) : 0; }();
        if (stripLogN && d.blendReg == 0x00010001u && d.tf[1]) {
          static long stripSeen = 0;
          uint32_t twS0 = (d.tf[2] & 0x1FFF) + 1, thS0 = ((d.tf[2] >> 13) & 0x1FFF) + 1;
          // skip the per-frame pane/compose copies (1280x720 + 640x512 fmt6) — they burned the
          // whole cap in the shell before the ROM select screens appeared (run5 lesson).
          bool paneCopy = (twS0 == 1280 && thS0 == 720) || (twS0 == 640 && thS0 == 512);
          if (stripSeen < stripLogN && !paneCopy) {
            ++stripSeen;
            uint32_t tbS = ((d.tf[1] >> 12) & 0xFFFFFu) << 12;
            uint32_t twS = twS0, thS = thS0;
            float u0 = 1e9f, v0 = 1e9f, u1 = -1e9f, v1 = -1e9f;
            uint32_t nP = d.count < 64u ? d.count : 64u;
            for (uint32_t k = 0; k < nP; ++k) {
              uint32_t dd[6]; decodeVert(k, dd);
              float u, v; std::memcpy(&u, &dd[4], 4); std::memcpy(&v, &dd[5], 4);
              if (u < u0) u0 = u; if (u > u1) u1 = u;
              if (v < v0) v0 = v; if (v > v1) v1 = v;
            }
            std::fprintf(stderr, "[striplog] f%ld #%ld vs=%d ps=%d n=%u tb=0x%08X %ux%u fmt=%u "
                                 "uv=[%.4f,%.4f..%.4f,%.4f] vte=%X res=%d\n",
                         nf->frame, stripSeen, vsIdx, psIdx, d.count, tbS, twS, thS, d.tf[1] & 0x3Fu,
                         u0, v0, u1, v1, d.vteCntl, (int)g_resolveTex.count(tbS));
          }
        }
      }
      // ★ RVK_RINGOFF=1 (2026-07-31) — A/B ARM: drop every stride-12 draw (the drop-shadow ring
      // is their only author in the whole shell stream, see [nvkring] above). This is the
      // discriminator the s2B leg-11 revert lever RVK_NOSHADOWFIX was supposed to be and no
      // longer is (that lever HANGS the boot on the census build — see NOTE_fnf_shell_defects.md):
      // it removes the ring and nothing else, at the draw-record altitude, with no shader-matcher
      // side effects. Diagnostic only — never ship armed.
      // ★ RVK_MODOFF=<hex blendReg> (2026-07-31) — POSITIVE CONTROL for the ranking-square leg.
      // The staircase in the ROM's own 640x512 target is authored by MODULATE-blend draws
      // (RB_BLENDCONTROL 0x05000500 = src ZERO / dst ONE_MINUS_SRC_COLOR: dst *= 1-src, the
      // classic sprite-shadow blend). Skipping exactly that blend class and re-measuring the
      // step is what turns "these draws are the only plausible author" into a measurement.
      // Diagnostic only; unset => byte-identical.
      static const char* modOffEnv = std::getenv("RVK_MODOFF");
      static uint32_t modOffReg = modOffEnv ? (uint32_t)strtoul(modOffEnv, nullptr, 16) : 0u;
      if (modOffReg && d.blendReg == modOffReg) {
        static long modOffN = 0;
        if ((++modOffN % 2000) == 1)
          std::fprintf(stderr, "[shdump] RVK_MODOFF=%08X armed: draw #%ld SKIPPED (f%ld vs=%d ps=%d n=%u)\n",
                       modOffReg, modOffN, nf->frame, vsIdx, psIdx, d.count);
        continue;
      }
      static bool ringOff = std::getenv("RVK_RINGOFF") && atoi(std::getenv("RVK_RINGOFF")) != 0;
      if (ringOff && d.strideB == 12) {
        static long ringOffN = 0;
        if ((++ringOffN % 4800) == 1)
          std::fprintf(stderr, "[nvkring] RVK_RINGOFF armed: stride-12 draw #%ld SKIPPED (f%ld)\n", ringOffN, nf->frame);
        continue;
      }
      uint32_t first = ni;
      uint32_t vbeg = nv;      // ★ r23-w17 C1: first vertex this draw contributes (see [texskip] below)
      if (d.prim == 8) {   // RECTLIST: 3 verts/rect, 4th synthesized v3 = v1 + v2 - v0
        for (uint32_t r = 0; r + 3 <= n; r += 3) {
          uint32_t a0 = nv;
          for (uint32_t k = 0; k < 3; ++k) { decodeVert(r + k, Vraw + (size_t)nv * 6); ++nv; }
          float* f0 = (float*)(Vraw + (size_t)a0 * 6);
          float* f1 = (float*)(Vraw + (size_t)(a0 + 1) * 6);
          float* f2 = (float*)(Vraw + (size_t)(a0 + 2) * 6);
          float* f3 = (float*)(Vraw + (size_t)nv * 6);
          if (xyuv) {
            for (int c = 0; c < 4; ++c) f3[c] = f1[c] + f2[c] - f0[c];
            ((uint32_t*)f3)[4] = ((uint32_t*)f1)[4]; ((uint32_t*)f3)[5] = ((uint32_t*)f1)[5];
          } else {
            for (int c : {0, 1, 2, 4, 5}) f3[c] = f1[c] + f2[c] - f0[c];
            ((uint32_t*)f3)[3] = ((uint32_t*)f1)[3];
          }
          uint32_t v3 = nv++;
          Iarr[ni++] = a0; Iarr[ni++] = a0 + 1; Iarr[ni++] = a0 + 2;
          Iarr[ni++] = a0 + 2; Iarr[ni++] = a0 + 1; Iarr[ni++] = v3;
        }
      } else {
        uint32_t v0 = nv;
        for (uint32_t k = 0; k < n; ++k) { decodeVert(k, Vraw + (size_t)nv * 6); ++nv; }
        if (d.prim == 6) {        // TRISTRIP (culling off: plain strip triangles suffice)
          for (uint32_t k = 0; k + 2 < n; ++k) { Iarr[ni++] = v0 + k; Iarr[ni++] = v0 + k + 1; Iarr[ni++] = v0 + k + 2; }
        } else {                  // TRIANGLEFAN (prim 5) + fan fallback for unseen prims
          if (d.prim != 5 && (++oddPrimN % 500) == 1) std::fprintf(stderr, "[nvk] prim %u via fan fallback x%ld\n", d.prim, oddPrimN);
          for (uint32_t k = 1; k + 1 < n; ++k) { Iarr[ni++] = v0; Iarr[ni++] = v0 + k; Iarr[ni++] = v0 + k + 1; }
        }
      }
      // ★★★ r23-w17 C1 — [texskip]: THE M1 CENSUS  (RVK_TEXSKIP=1, default off)
      //
      // `if (d.tf[1])` above guards the ONLY call to getTexIndexReal on the nvk spine.  When the
      // stage-0 fetch shadow is empty the call is skipped and `texIdx` keeps its initialiser 0 —
      // which is the 1x1 PURE WHITE bindless texture built at :10707.  RVK_TEXWHITE lives INSIDE
      // getTexIndexReal, so it is STRUCTURALLY INCAPABLE of firing on this route: w16's and w17's
      // texwhite zeros exclude the two arms they cover and say nothing whatever about this one.
      // (w17 static lane, `bank/r23/w17/w17_wash_DESIGN.md` §2 M1.)
      //
      // ⚠ WHY A COUNT WOULD PROVE NOTHING, and what is printed instead.  tf[1]==0 is LEGITIMATE
      //   for an untextured colour quad — white is the identity for a modulate — so the census is
      //   dominated by correct draws and a count delta is uninterpretable.  The finding can only
      //   ever be "the skipped draws' BBOXES TILE THE WASHED REGION", so the bbox is the payload
      //   and the count is context.  Same trap LAWS §10 records for the ea_sweep controls.
      // ⚠ THE BBOX IS RAW POST-decodeVert VERTEX SPACE, and this instrument does not pretend
      //   otherwise: for the screen-space vs classes it is screen pixels, for a model-space class
      //   it is not.  vs/ps are printed beside it so a reader can tell which, instead of a
      //   "screen bbox" label that would quietly assert the thing being measured.
      { static const bool tsOn = std::getenv("RVK_TEXSKIP") && atoi(std::getenv("RVK_TEXSKIP")) != 0;
        if (tsOn && d.tf[1] == 0 && nv > vbeg) {
          static long tsFrame = -1; static int tsThisFrame = 0; static long tsTotal = 0;
          if (nf->frame != tsFrame) { tsFrame = nf->frame; tsThisFrame = 0; }
          ++tsTotal;
          if (tsThisFrame < 24) {
            float bx0 = 1e9f, by0 = 1e9f, bx1 = -1e9f, by1 = -1e9f;
            for (uint32_t k = vbeg; k < nv; ++k) {
              const float* fv = (const float*)(Vraw + (size_t)k * 6);
              if (fv[0] < bx0) bx0 = fv[0];  if (fv[0] > bx1) bx1 = fv[0];
              if (fv[1] < by0) by0 = fv[1];  if (fv[1] > by1) by1 = fv[1];
            }
            ++tsThisFrame;
            std::fprintf(stderr, "[texskip] f%ld #%ld vs=%d ps=%d prim=%u n=%u nvtx=%u blend=0x%08X vte=%X "
                                 "bbox=(%.0f,%.0f)-(%.0f,%.0f) c14=(%.3f,%.3f,%.3f,%.3f) c15=(%.3f,%.3f)\n",
              nf->frame, tsTotal, vsIdx, psIdx, d.prim, d.count, nv - vbeg, d.blendReg,
              (unsigned)d.vteCntl, bx0, by0, bx1, by1,
              g_psConstF[56], g_psConstF[57], g_psConstF[58], g_psConstF[59],
              g_psConstF[60], g_psConstF[61]);
          }
        }
      }
      // ★★★ r23-w19 DRIVER — [dcen]: THE FULL PER-DRAW STATE CENSUS (RVK_DCEN=<every>, default off)
      //
      // WHY HERE and not at the [nvkdbg] site 700 lines up.  [nvkdbg] prints before the vertices
      // are decoded, so it can only report the VIEWPORT — and a viewport does not say which draw
      // covers the playfield.  THIS site sits immediately after the decode loop, where vbeg..nv
      // hold this draw's own vertices, so the bbox is REAL (same acquisition [texskip] uses).
      // Naming the playfield-covering draw is the whole job: w18 excluded all three
      // missing-texture->white routes, so the surviving forks are (a) the playfield draw is
      // ABSENT, (b) it samples a RESOLVE target whose contents are white, (c) it samples GUEST
      // memory that is white, (d) source is fine and a RENDER STATE differs.  One census line
      // per draw carries the evidence for all four.
      //
      // ⚠ WHAT EACH FIELD IS, so nothing is read as more than it is:
      //   bbox   RAW post-decodeVert vertex space — screen pixels for the screen-space vs
      //          classes, model space otherwise. vs/ps are printed beside it; the reader decides.
      //   res    1 iff the texture base is a registered RESOLVE DESTINATION. That is the fork-(b)
      //          flag: for res=1 the guest bytes are NOT the source and `guest[...]` says nothing.
      //   guest  min/max/mean/frac-0xFF over up to 512 sampled dwords of the texture's guest
      //          bytes. n= is the SELF-CHECK: n=0 means nothing was sampled and the stat is VOID
      //          (a silent zero here would read as "the source is black", the exact inversion of
      //          the finding). The span estimate assumes 2 B/texel and is capped at 1 MiB — it is
      //          a CONTENT PROBE, not a decode.
      //   v0     the six raw dwords of this draw's first vertex + the xyuv layout flag, because
      //          the vertex COLOUR is dword 3 in the non-xyuv layout and SYNTHESISED 0xFFFFFFFF
      //          in the xyuv one (the 2026-07-31 [shdump] lesson: printing "col" unconditionally
      //          prints a hardcoded constant on half the draws).
      // Default off => byte-identical. Fires on the periodic cadence AND on the RVK_ONWASH arm,
      // through the SAME code, which is what makes the washed/clean diff a like-for-like diff.
      { static const long dcenEvery = std::getenv("RVK_DCEN") ? std::strtol(std::getenv("RVK_DCEN"), nullptr, 10) : 0;
        static const bool dcenOnWash = std::getenv("RVK_ONWASH") != nullptr;
        static const long dcenCap = std::getenv("RVK_DCEN_CAP") ? std::strtol(std::getenv("RVK_DCEN_CAP"), nullptr, 10) : 120000;
        static long dcenLines = 0, dcenIdx = -1; static long dcenFrame = -1;
        if (dcenEvery > 0) {
          bool now = ((nf->frame % dcenEvery) == 0) || (dcenOnWash && g_rvkWashForce > 0);
          if (now && nv > vbeg && dcenLines < dcenCap) {
            if (nf->frame != dcenFrame) { dcenFrame = nf->frame; dcenIdx = 0; } else ++dcenIdx;
            float bx0 = 1e9f, by0 = 1e9f, bx1 = -1e9f, by1 = -1e9f;
            for (uint32_t k = vbeg; k < nv; ++k) {
              const float* fv = (const float*)(Vraw + (size_t)k * 6);
              if (fv[0] < bx0) bx0 = fv[0];  if (fv[0] > bx1) bx1 = fv[0];
              if (fv[1] < by0) by0 = fv[1];  if (fv[1] > by1) by1 = fv[1];
            }
            const uint32_t* v0 = (const uint32_t*)(Vraw + (size_t)vbeg * 6);
            uint32_t tbD = d.tf[1] ? (((d.tf[1] >> 12) & 0xFFFFFu) << 12) : 0u;
            int isRes = tbD ? (int)g_resolveTex.count(tbD) : 0;
            int gN = 0; unsigned gMin = 255u, gMax = 0u; double gSum = 0.0; long gFF = 0;
            if (tbD && g_base) {
              uint64_t span = (uint64_t)tw * (uint64_t)th * 2ull;
              if (span > 0x100000ull) span = 0x100000ull;
              if (span < 4096ull) span = 4096ull;
              uint32_t step = (uint32_t)(span / 512ull); if (step < 4u) step = 4u; step &= ~3u;
              for (uint64_t off = 0; off + 4 <= span; off += step) {
                uint64_t a = (uint64_t)tbD + off;
                if (a + 4ull > 0x20000000ull) break;
                uint32_t w32 = be32((uint32_t)a);
                for (int sh = 24; sh >= 0; sh -= 8) {
                  unsigned bv = (w32 >> sh) & 0xFFu;
                  if (bv < gMin) gMin = bv;  if (bv > gMax) gMax = bv;
                  gSum += (double)bv; ++gN; if (bv == 0xFFu) ++gFF;
                }
              }
            }
            float bcf[4]; for (int c = 0; c < 4; ++c) std::memcpy(&bcf[c], &d.blendConst[c], 4);
            std::fprintf(stderr,
              "[dcen] f%ld #%ld vs=%d ps=%d prim=%u n=%u st=%u vte=%X blend=%08X bc=(%.3f,%.3f,%.3f,%.3f) "
              "cc=%08X ar=%08X tb=%08X %ux%u fmt=%u tex=%u res=%d rt=%s%08X bbox=(%.1f,%.1f)-(%.1f,%.1f) "
              "xyuv=%d v0={%08X,%08X,%08X,%08X,%08X,%08X} c14=(%.3f,%.3f,%.3f,%.3f) c15=(%.3f,%.3f) "
              "guest[n=%d min=%u max=%u mean=%.1f ff=%.3f]\n",
              nf->frame, dcenIdx, vsIdx, psIdx, d.prim, d.count, (unsigned)d.strideB, (unsigned)d.vteCntl,
              d.blendReg, bcf[0], bcf[1], bcf[2], bcf[3], d.colorCtl, d.alphaRef,
              tbD, tw, th, d.tf[1] & 0x3Fu, texIdx, isRes,
              curRT ? "OFFS:" : "DISP:", curRT ? curRT->surf : 0u,
              bx0, by0, bx1, by1, (int)xyuv,
              v0[0], v0[1], v0[2], v0[3], v0[4], v0[5],
              g_psConstF[56], g_psConstF[57], g_psConstF[58], g_psConstF[59],
              g_psConstF[60], g_psConstF[61],
              gN, gN ? gMin : 0u, gMax, gN ? gSum / gN : 0.0, gN ? (double)gFF / gN : 0.0);
            ++dcenLines;
            if (dcenLines == dcenCap)
              std::fprintf(stderr, "[dcen] LINE CAP %ld REACHED — census truncated (a cap, not a zero)\n", dcenCap);
          }
        }
      }
      // Register-true blend constants (RB_BLEND_RED..ALPHA, dev+0x28E0..EC) — attract legal/fade
      // draws use CONSTANT_* factors (the 07-27 legal-panel wash class). RT_NVKNOBC=1 reverts to
      // the old hardcoded zeros. Clamp mirrors the PM4 path (see the RBatch.bc capture).
      float nbc[4] = {0.f, 0.f, 0.f, 0.f};
      static int noBc = getenv("RT_NVKNOBC") ? 1 : 0;
      if (!noBc)
        for (int c = 0; c < 4; ++c) {
          float fv; std::memcpy(&fv, &d.blendConst[c], 4);
          nbc[c] = (fv < 0.f || !(fv == fv)) ? 0.f : (fv > 1.f ? 1.f : fv);
        }
      nbs.push_back({pipe, vsl.addr, psl.addr, shl.addr, first, ni - first, vsIdx, vp,
                     {d.vte[0], d.vte[1], d.vte[2], d.vte[3]}, d.vteCntl,
                     {nbc[0], nbc[1], nbc[2], nbc[3]}});
      // ★ NVK COMPOSE CENSUS count hook — the draw is now certain to be recorded and rendered.
      // DISPLAY target only (see the scope note above nvk_frame_submit). Counting only.
      if (censShell && curRT == nullptr) {
        ++censDisp;
        if (!censInjThis) {
          auto it = g_ncMap.find(censKey);
          if (it == g_ncMap.end() && g_ncMap.size() < 512) it = g_ncMap.emplace(censKey, NvkCensusEnt{}).first;
          if (it != g_ncMap.end()) {
            NvkCensusEnt& e = it->second;
            if (e.cnt == 0) {   // first sighting this frame: record the identity context
              e.base = censBase; e.vs = vsIdx; e.ps = psIdx; e.vte = d.vteCntl;
              const float* fv = (const float*)(Vraw + (size_t)Iarr[first] * 6);
              e.v0x = fv[0]; e.v0y = fv[1];
            }
            e.cnt++;
          }
        }
        // RVK_TITLEPROBE: threshold-free presence tracker (runs beside the census, see above).
        if (tprobeLvl()) {
          if (TProbeEnt* tp = tprobeSlot(censKey)) {
            if (tp->cnt == 0) { tp->base = censBase; tp->vs = vsIdx; tp->ps = psIdx; }
            tp->cnt++;
          }
        }
      }
    }
    if (!recordSeg(segStart, nbs.size())) return false;
    anySegRendered = anySegRendered || nbs.size() > segStart || true;
    if (segClear) { carryClear = true; carryClearColor = nf->clearARGB; }   // trailing clear-after: apply next frame
    ++renderedFrames;
    // ★★ NVK COMPOSE CENSUS — frame close. Only frames that RECOMPOSED THE DISPLAY advance the
    // clock: a frame with no display draws holds the previous image (no visual hole), so counting
    // it would make every steady identity fake a drop (the legacy build's 3rd control failure).
    if (censShell && censDisp > 0) {
      g_ncPc++;
      const bool sceneJump = g_ncLastTotal > 0 && (censDisp > 3 * g_ncLastTotal || 3 * censDisp < g_ncLastTotal);
      g_ncLastTotal = censDisp;
      // SPEC_shell_compose_1to1 §4 clear-policy check: the guest clears the screen ONCE per frame
      // and ONLY when DAT_821EC65B == 1 (the veil pass FUN_82184CC8 owns that byte). The port is
      // register-true by construction here — nvk records the guest's own D3DDevice_Clear as an
      // ordered stream event — so this is a CONFORMANCE COUNTER, not a fix: a persistent mismatch
      // would mean a Clear never reached the recorder (or arrived on the wrong frame). ⚠ Honest
      // caveat: the flag is sampled at Present (frame end) and the guest samples it mid-frame, so
      // isolated mismatches on transition frames are expected; only a sustained rate is evidence.
      { uint8_t cb = *(g_base + 0x821EC65Bu);
        if ((cb != 0) == (censClears > 0)) g_ncClearOk++;
        else { g_ncClearMiss++;
          if ((g_ncClearMiss % 200) == 1)
            std::fprintf(stderr, "[census] CLEAR-POLICY mismatch #%ld f%ld DAT_821EC65B=%u clearEvents=%d (ok=%ld)\n",
                         g_ncClearMiss, nf->frame, cb, censClears, g_ncClearOk); } }
      const uint8_t cbNow = *(g_base + 0x821EC65Bu);
      // roster of THIS frame's live identities (built before the entry walk resets the counts)
      char roster[160]; int rl = 0; roster[0] = 0;
      for (auto& kv : g_ncMap) {
        if (kv.second.cnt <= 0 || rl >= (int)sizeof(roster) - 24) continue;
        rl += std::snprintf(roster + rl, sizeof(roster) - (size_t)rl, "%s%X/%d.%d:%d",
                            rl ? " " : "", kv.second.base, kv.second.vs, kv.second.ps, kv.second.cnt);
      }
      for (auto it = g_ncMap.begin(); it != g_ncMap.end(); ) {
        NvkCensusEnt& e = it->second;
        bool erase = false;
        if (sceneJump) { e.streak = e.cnt > 0 ? 1 : 0; e.missSince = -1; }
        else if (e.cnt > 0) {
          if (e.missSince >= 0) {            // returned after a gap
            long len = g_ncPc - e.missSince;
            if (len <= censR) {
              g_ncDropouts++;
              std::fprintf(stderr, "[census] f%ld DROPOUT-CONFIRMED len=%ld base=0x%X vs=%d ps=%d steady=%d streak=%ld "
                                   "v0=(%.1f,%.1f) clear=%u vte=0x%X missTotal=%d retTotal=%d nDraws=%d%s\n"
                                   "[census]   missRoster=[%s] missRec{build=%ld noscratch=%ld spliced=%ld}\n"
                                   "[census]   retnRoster=[%s] retnRec{build=%ld noscratch=%ld spliced=%ld}\n",
                           nf->frame, len, e.base, e.vs, e.ps, e.steadyCnt, e.missStreak,
                           e.v0x, e.v0y, cbNow, e.vte, e.missTotal, censDisp, nf->nDraws,
                           censTest ? " [CENSUSTEST ARMED]" : "",
                           e.missRoster, e.missBuild, e.missNoScratch, e.missSpliced,
                           roster, g_nvk_fBuild, g_nvk_fNoScratch, g_nvk_fSpliced);
            }
            e.missSince = -1; e.streak++;
          } else { e.streak++; e.steadyCnt = e.cnt; }
        } else {                             // absent on a display-recomposing frame
          if (e.streak >= censK && e.missSince < 0) {
            e.missSince = g_ncPc; e.missStreak = e.streak; e.missTotal = censDisp;
            std::snprintf(e.missRoster, sizeof e.missRoster, "%s", roster);   // aliasing discriminator
            e.missBuild = g_nvk_fBuild; e.missNoScratch = g_nvk_fNoScratch; e.missSpliced = g_nvk_fSpliced;
          }
          else if (e.missSince >= 0 && g_ncPc - e.missSince > censR) erase = true;   // legit dismissal
          else if (e.missSince < 0) { erase = (e.streak == 0); e.streak = 0; }       // never-steady
        }
        e.cnt = 0;
        if (erase) it = g_ncMap.erase(it); else ++it;
      }
      // ★ RVK_TITLEPROBE close: turn per-frame presence into RUN LENGTHS. No streak threshold,
      // no gap ceiling, no erase — the census's own filters are what made the authentic 20/20
      // blink invisible, so this half deliberately has none of them.
      if (int tpl = tprobeLvl()) {
        char tpr[192]; int tl = 0; tpr[0] = 0;
        for (int i = 0; i < g_tpN; ++i) {
          TProbeEnt& tp = g_tpEnt[i];
          bool on = tp.cnt > 0;
          if (tpl >= 2 && tl < (int)sizeof(tpr) - 24)
            tl += std::snprintf(tpr + tl, sizeof(tpr) - (size_t)tl, "%s%X/%d.%d:%d", tl ? " " : "", tp.base, tp.vs, tp.ps, tp.cnt);
          if (!tp.seen) { tp.seen = true; tp.on = on; tp.run = 1; tp.steady = tp.cnt; tp.cnt = 0; continue; }
          if (on == tp.on) { tp.run++; if (on && tp.cnt > tp.steady) tp.steady = tp.cnt; }
          else {
            if (tp.run >= tprobeMin() && g_tpLines < 20000) {
              ++g_tpLines;
              std::fprintf(stderr, "[tprobe] f%ld pc=%ld base=0x%X vs=%d ps=%d %s run=%ld frames -> %s (quads=%d disp=%d)\n",
                           nf->frame, g_ncPc, tp.base, tp.vs, tp.ps,
                           tp.on ? "PRESENT" : "ABSENT ", tp.run, tp.on ? "ABSENT" : "PRESENT",
                           tp.steady, censDisp);
            }
            tp.on = on; tp.run = 1;
          }
          tp.cnt = 0;
        }
        if (tpl >= 2 && g_tpLines < 20000) { ++g_tpLines;
          std::fprintf(stderr, "[tprobe] f%ld pc=%ld roster=[%s]\n", nf->frame, g_ncPc, tpr); }
      }
      // election of the injection target = the CURRENTLY longest-steady identity (a first-steady
      // lock dies with its boot phase — the legacy build's 1st control failure).
      long best = censK - 1; g_ncTestKey = 0; uint32_t bestBase = 0;
      for (auto& kv : g_ncMap)
        if (kv.second.streak > best && kv.second.missSince < 0) { best = kv.second.streak; g_ncTestKey = kv.first; bestBase = kv.second.base; }
      if (censOn >= 2) {
        static long vst = 0;
        if ((vst++ % 120) == 0)
          std::fprintf(stderr, "[census] status pc=%ld ids=%zu maxstreak=%ld testbase=0x%X disp=%d nDraws=%d "
                               "dropouts=%ld clear{ok=%ld miss=%ld} rec{build=%ld noscratch=%ld spliced=%ld}\n",
                       g_ncPc, g_ncMap.size(), best, bestBase, censDisp, nf->nDraws,
                       g_ncDropouts, g_ncClearOk, g_ncClearMiss,
                       g_nvk_fBuild, g_nvk_fNoScratch, g_nvk_fSpliced);
      }
      // recorder-cap truncation: the frame the guest built did not fit the NvkFrame arrays, so
      // the tail of its stream never reached the renderer (partial-frame class, loud + counted).
      if (nf->nDraws >= NVK_MAX_DRAWS) {
        static long capN = 0;
        if ((++capN % 100) == 1)
          std::fprintf(stderr, "[nvktrunc] f%ld RECORDER CAP x%ld: nDraws hit NVK_MAX_DRAWS=%d — stream tail lost\n",
                       nf->frame, capN, NVK_MAX_DRAWS);
      }
    }
    // RT_NVKDBG resolve-content dumps: every registered resolve tex -> PNG (orientation truth)
    static bool nvkDbg2 = std::getenv("RT_NVKDBG") != nullptr;
    // RT_NVKRESWIN=<from>:<to> (s2B leg 12): restrict the resolve PNG series to a frame window.
    // A tight RT_NVKRESEVERY (the legal-band discriminator wants 7) otherwise readbacks the whole
    // boot, which both floods the bank and slows the render loop enough to SHIFT the wall-clock
    // nav drive relative to the attract phase being sampled. Unset = old behaviour.
    static const long resMinW = std::getenv("RT_NVKRESMINW") ? std::atol(std::getenv("RT_NVKRESMINW")) : 0;   // ★ r23-w19
    static const char* resWinEnv = std::getenv("RT_NVKRESWIN");
    static long resWinFrom = resWinEnv ? std::atol(resWinEnv) : -1;
    static long resWinTo = (resWinEnv && std::strchr(resWinEnv, ':')) ? std::atol(std::strchr(resWinEnv, ':') + 1) : -1;
    bool resWinOk = (resWinFrom < 0) || (nf->frame >= resWinFrom && (resWinTo < 0 || nf->frame <= resWinTo));
    // ★ r23-w19: same RVK_ONWASH arm as the [nvkdbg] census — a FIRE dumps the resolve targets
    //   for the forced window, so the composed PNG, the draw census and the layer contents all
    //   describe THE SAME FRAME. The periodic cadence is untouched and supplies the clean twin.
    static const bool onWashRes = std::getenv("RVK_ONWASH") != nullptr;
    bool resPeriodic = resWinOk && resEvery > 0 && (nf->frame % resEvery) == 0;
    bool resOnWash = onWashRes && g_rvkWashForce > 0;
    if (nvkDbg2 && (resPeriodic || resOnWash) && !g_resolveTex.empty()) {
      for (auto& kv : g_resolveTex) {
        ResolveTex& rt = kv.second;
        if (!rt.image || !rt.everRendered) continue;
        if (resOnly && kv.first != resOnlyBase) continue;   // RT_NVKRESONLY: one surface, no aliasing
        // ★ r23-w19: RT_NVKRESMINW=<px> — skip targets narrower than <px>. A w18 leg registers 96
        //   resolve targets, ~90 of them the 320x240 ring; dumping all of them on a CONDITION
        //   trigger costs 90 fence-waited readbacks per armed frame and would change the thing
        //   being measured. The field-layer candidates are the 640x512 self-composite and the
        //   1280x720 pane, so a width floor selects them without naming an address that a
        //   wall-clock allocator is free to move (the menu-flash "no address invariants" lesson).
        //   Unset = 0 = every target, i.e. byte-identical to the old behaviour.
        if (resMinW > 0 && (long)rt.w < resMinW) continue;
        segBatchFlush();
        rvkRingNext("nvkd"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(nvkd)");
        VkCommandBufferBeginInfo cbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO};
        cbi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
        VKC(vkBeginCommandBuffer(g.cmd, &cbi), "begin(nvkd)");
        VkImageMemoryBarrier bar{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER};
        bar.srcQueueFamilyIndex = bar.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        bar.image = rt.image; bar.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
        bar.oldLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL; bar.newLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        bar.srcAccessMask = VK_ACCESS_SHADER_READ_BIT; bar.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &bar);
        VkBufferImageCopy bic{}; bic.imageSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1};
        bic.imageExtent = {rt.w, rt.h, 1};
        vkCmdCopyImageToBuffer(g.cmd, rt.image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, g.readback, 1, &bic);
        bar.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL; bar.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        bar.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT; bar.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
        vkCmdPipelineBarrier(g.cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &bar);
        VKC(vkEndCommandBuffer(g.cmd), "end(nvkd)");
        VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
        VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(nvkd)");
        VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(nvkd)");
        VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(nvkd)");
        void* map = nullptr;
        VKC(vkMapMemory(g.dev, g.readbackMem, 0, VK_WHOLE_SIZE, 0, &map), "map(nvkd)");
        char fp[96];
        // leg 10 item 1: writePng assumes tightly-packed RGBA8 bytes. Check THIS target's format
        // (ring slots are now A2B10G10R10_UNORM_PACK32); the old g_rtFmt test no longer speaks for
        // a single target. The 10-bit case is UNPACKED to 8-bit rather than skipped — the c3
        // acceptance banks depend on the nvkres_* series existing for the 320x240 ring slots, and
        // a dropped series would read as a regression in the verdict script.
        if (rt.fmt == VK_FORMAT_A2B10G10R10_UNORM_PACK32) {
          std::vector<uint8_t> tmp((size_t)rt.w * rt.h * 4u);
          const uint32_t* srcp = (const uint32_t*)map;
          for (size_t i = 0, n2 = (size_t)rt.w * rt.h; i < n2; ++i) {
            uint32_t v = srcp[i];
            tmp[i * 4 + 0] = (uint8_t)(((v >>  0) & 0x3FFu) >> 2);   // R bits 0-9
            tmp[i * 4 + 1] = (uint8_t)(((v >> 10) & 0x3FFu) >> 2);   // G bits 10-19
            tmp[i * 4 + 2] = (uint8_t)(((v >> 20) & 0x3FFu) >> 2);   // B bits 20-29
            tmp[i * 4 + 3] = (uint8_t)(((v >> 30) & 0x3u) * 85u);    // A bits 30-31
          }
          std::snprintf(fp, sizeof fp, "C:/tmp/nvkres_f%ld_%07X_%ux%u.png", nf->frame, kv.first, rt.w, rt.h);
          writePng(fp, tmp.data(), rt.w, rt.h);
        } else if (rt.fmt != VK_FORMAT_R8G8B8A8_UNORM) {   // HDR off in ship env, but stay honest
          std::fprintf(stderr, "[nvkdbg] resolve 0x%07X vkfmt=%d has no png unpacker — skipping\n",
                       kv.first, (int)rt.fmt);
        } else {
          std::snprintf(fp, sizeof fp, "C:/tmp/nvkres_f%ld_%07X_%ux%u.png", nf->frame, kv.first, rt.w, rt.h);
          writePng(fp, (const uint8_t*)map, rt.w, rt.h);
        }
        vkUnmapMemory(g.dev, g.readbackMem);
      }
    }
    // ★★★ r23-w17 C1 — RVK_WASHTRIG: THE CONDITION TRIGGER, evaluated on the COMPOSED IMAGE
    //     BEFORE PRESENT.  (w17 static lane `w17_wash_DESIGN.md` §3.2/§3.3, driver re-derived.)
    //
    // WHY HERE.  This block already performs the exact acquisition a predicate needs —
    // copyDisplayToReadback + submit + fence + map, giving kW*kH tightly-packed RGBA8 of the
    // composed frame — and it sits immediately before rvkWindowPresent().  Reading HERE means a
    // fire simultaneously proves the wash is UPSTREAM OF PRESENT, for free.  Gated on its OWN env,
    // never on pngEvery, so the predicate's cadence and the filmstrip's cadence are independent.
    //
    // WHAT IS SCORED, and why it is not whiteness.  A raw white fraction CANNOT separate this
    // defect: the snow stage (film007) legitimately outscores a real washed frame (film048) on
    // both `w245Pf` and `whitePf`, so no threshold on either works in either direction.  The
    // discriminator is FLATNESS — the wash is a FILL, snow is CONTENT.  Over the playfield minus
    // its top-60 HUD band, 16x16 blocks sampled at stride 4: a block is FLAT-WHITE if >=90% of its
    // samples are near-white (min channel >=210, chroma <=30) AND the block's total dynamic range
    // is <=12.  `tilemax` is the max flat-white fraction over a 4x4 tiling — regional by
    // construction, because the defect is regional.
    //
    // ⚠ EVERY EVALUATION PRINTS, not only the fires.  A threshold calibrated on 3 washed window
    //   PNGs cannot be trusted on renderer readbacks; what transfers is the SHAPE of the statistic,
    //   not the constant.  Emitting the full trace means the threshold can be re-cut offline from
    //   the drive's own data without a rebuild, and a leg that never fires still returns the
    //   calibration curve instead of a silent zero (LAWS §10: a zero that never prints is not
    //   evidence).  w245 is printed alongside precisely BECAUSE it is refuted — carrying the dead
    //   metric costs one float and lets the live data adjudicate rather than this comment.
    //
    // ⚠ ON A FIRE THE NEXT N FRAMES ARE DUMPED UNCONDITIONALLY.  Nobody has established that the
    //   wash persists for more than one frame, and every trigger-then-capture scheme
    //   (RenderDoc's TriggerMultiFrameCapture included) captures the frame AFTER the one the
    //   predicate saw.  Dumping the CURRENT frame here plus the next N sidesteps the persistence
    //   assumption entirely instead of betting on it.
    // ⚠ THE FENCE WAIT SERIALISES THE FRAME.  [fps]/[perflog] from any RVK_WASHTRIG run are VOID.
    static long washEvery = std::getenv("RVK_WASHTRIG") ? std::strtol(std::getenv("RVK_WASHTRIG"), nullptr, 10) : 0;
    static long washNAfter = std::getenv("RVK_WASHTRIG_N") ? std::strtol(std::getenv("RVK_WASHTRIG_N"), nullptr, 10) : 6;
    static double washT = std::getenv("RVK_WASHTRIG_T") ? std::atof(std::getenv("RVK_WASHTRIG_T")) : 0.20;
    static long washForced = 0, washFires = 0;
    bool wantWash = washEvery > 0 && (renderedFrames % washEvery) == 0;
    // PNG readback (display-independent): separate tiny cmd; g.image is TRANSFER_SRC after the last pass
    bool dumpPng = (pngEvery > 0 && (renderedFrames % pngEvery) == 0) || washForced > 0;
    if (dumpPng || wantWash) {
      segBatchFlush();
      rvkRingNext("nvkp"); VKC(vkResetCommandBuffer(g.cmd, 0), "reset(nvkp)");
      VkCommandBufferBeginInfo cbi{VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO};
      cbi.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
      VKC(vkBeginCommandBuffer(g.cmd, &cbi), "begin(nvkp)");
      copyDisplayToReadback(g.cmd);
      VKC(vkEndCommandBuffer(g.cmd), "end(nvkp)");
      VkSubmitInfo si{VK_STRUCTURE_TYPE_SUBMIT_INFO}; si.commandBufferCount = 1; si.pCommandBuffers = &g.cmd;
      VKC(vkResetFences(g.dev, 1, &g.fence), "resetFence(nvkp)");
      VKC(rvkQueueSubmit(g.queue, 1, &si, g.fence), "submit(nvkp)");
      VKC(rvkWaitFences(g.dev, 1, &g.fence, VK_TRUE, 10000000000ull), "wait(nvkp)");
      void* map = nullptr;
      VKC(vkMapMemory(g.dev, g.readbackMem, 0, VK_WHOLE_SIZE, 0, &map), "map(nvkp)");
      if (dumpPng) {
        writePng("C:/tmp/nvk_last.png", (const uint8_t*)map, kW, kH);
        char fp[64]; std::snprintf(fp, sizeof fp, "C:/tmp/nvk_f%ld.png", nf->frame);
        writePng(fp, (const uint8_t*)map, kW, kH);
        if (washForced > 0) --washForced;
        if (g_rvkWashForce > 0) --g_rvkWashForce;   // ★ r23-w19: mirrors washForced exactly
      }
      if (wantWash && map && kW >= 880 && kH >= 680) {
        const uint8_t* px = (const uint8_t*)map;
        // playfield = 480x640 composed 1:1 and CENTRED in 1280x720 -> x[400,880) y[40,680).
        // (1280-480)/2 = 400 and (720-640)/2 = 40: the arithmetic closes, which is the check that
        // no window-to-client offset was smuggled in.  Top 60 rows are the HUD band and are
        // EXCLUDED: they are bright by design and draw correctly during the wash, so they add
        // only noise.  Play area = x[400,880) y[100,680) = 480x580.
        const int PX0 = 400, PY0 = 100, PW = 480, PH = 580;
        // ⚠⚠ NOT `RGB`.  <wingdi.h> defines RGB(r,g,b) as a COLORREF-packing MACRO, so a lambda
        //   named RGB DECLARES fine (the name is not followed by `(` there) and then every CALL
        //   SITE silently expands to the macro instead.  The result is a pure function of the
        //   COORDINATES: the probe never touches the framebuffer and returns the same numbers
        //   forever.  That is exactly what happened on leg c1a -- 2,998 evaluations, every one
        //   reporting w245=0.9866 and flatwhite=0.0000, while the PNG written from the SAME
        //   mapped pointer on the SAME frames varied correctly.  Sibling of the `near` collision
        //   twenty lines up; <windows.h> owns more short uppercase identifiers than it should.
        //   ★ The arm-time border self-check is what exposed it: borderLuma printed 86433.6 when
        //     a luma cannot exceed 255, and 0.299*A + 0.587*(A+65536) + 0.114*(A+131072) with
        //     A = x|(y<<8) reproduces 86065 -- the macro's arithmetic, to within rounding.
        //     A probe with no self-check would have banked "the predicate never fired".
        auto PXV = [&](int x, int y, int c) -> int { return px[((size_t)y * kW + x) * 4 + c]; };
        // ---- arm-time SELF-CHECK, once: if the 4-px border just outside the rect is not the
        //      side wallpaper, the rect is wrong and every number below is void.  Printed, not
        //      assumed, because a silently-misplaced rect is indistinguishable from a clean run.
        static bool washArmed = false;
        if (!washArmed) {
          washArmed = true;
          double bl = 0; int bn = 0;
          for (int y = PY0; y < PY0 + PH; y += 8)
            for (int dx = 1; dx <= 4; ++dx) {
              bl += 0.299 * PXV(PX0 - dx, y, 0) + 0.587 * PXV(PX0 - dx, y, 1) + 0.114 * PXV(PX0 - dx, y, 2);
              bl += 0.299 * PXV(PX0 + PW + dx - 1, y, 0) + 0.587 * PXV(PX0 + PW + dx - 1, y, 1) + 0.114 * PXV(PX0 + PW + dx - 1, y, 2);
              bn += 2;
            }
          std::fprintf(stderr, "[washtrig] ARM rect=(%d,%d)+%dx%d over %ux%u  every=%ld  T=%.3f  N=%ld"
                               "  borderLuma=%.1f (self-check: this must be the side wallpaper, not playfield)\n",
                       PX0, PY0, PW, PH, kW, kH, washEvery, washT, washNAfter, bl / (bn ? bn : 1));
        }
        int blkFlat = 0, blkTot = 0;
        const int NBX = PW / 16, NBY = PH / 16;          // 30 x 36 blocks
        static std::vector<uint8_t> flatBlk; flatBlk.assign((size_t)NBX * NBY, 0);
        long w245 = 0, w245n = 0;
        for (int by = 0; by < NBY; ++by) for (int bx = 0; bx < NBX; ++bx) {
          // ⚠ NOT `near`: <windows.h> still #defines `near`/`far` as empty legacy segment
          //   keywords, so `int near` is a parse error here and nowhere else in the codebase.
          int nearN = 0, ns = 0, smax = 0, smin = 255;
          for (int y = 0; y < 16; y += 4) for (int x = 0; x < 16; x += 4) {
            int r = PXV(PX0 + bx * 16 + x, PY0 + by * 16 + y, 0);
            int g2 = PXV(PX0 + bx * 16 + x, PY0 + by * 16 + y, 1);
            int b = PXV(PX0 + bx * 16 + x, PY0 + by * 16 + y, 2);
            int mx = r > g2 ? (r > b ? r : b) : (g2 > b ? g2 : b);
            int mn = r < g2 ? (r < b ? r : b) : (g2 < b ? g2 : b);
            if (mn >= 210 && (mx - mn) <= 30) ++nearN;
            if (mx > smax) smax = mx;  if (mn < smin) smin = mn;
            if (mn >= 245) ++w245;  ++w245n;  ++ns;
          }
          ++blkTot;
          bool f = (nearN * 10 >= ns * 9) && (smax - smin) <= 12;
          if (f) { ++blkFlat; flatBlk[(size_t)by * NBX + bx] = 1; }
        }
        double flatwhite = blkTot ? (double)blkFlat / blkTot : 0.0;
        // tilemax over a 4x4 tiling of the block grid — the defect is REGIONAL, so a whole-field
        // mean under-reports it by exactly the factor the region is small.
        double tilemax = 0.0; int tbest = -1;
        for (int ti = 0; ti < 4; ++ti) for (int tj = 0; tj < 4; ++tj) {
          int y0 = ti * NBY / 4, y1 = (ti + 1) * NBY / 4, x0 = tj * NBX / 4, x1 = (tj + 1) * NBX / 4;
          int c = 0, t = 0;
          for (int by = y0; by < y1; ++by) for (int bx = x0; bx < x1; ++bx) { t++; c += flatBlk[(size_t)by * NBX + bx]; }
          double v = t ? (double)c / t : 0.0;
          if (v > tilemax) { tilemax = v; tbest = ti * 4 + tj; }
        }
        double w245f = w245n ? (double)w245 / w245n : 0.0;
        bool fire = tilemax >= washT;
        std::fprintf(stderr, "[washtrig] f%ld flatwhite=%.4f tilemax=%.4f tile=%d w245=%.4f blocks=%d/%d%s\n",
                     nf->frame, flatwhite, tilemax, tbest, w245f, blkFlat, blkTot, fire ? "  ***FIRE***" : "");
        if (fire) {
          ++washFires;
          char wp[80]; std::snprintf(wp, sizeof wp, "C:/tmp/nvkwash_f%ld.png", nf->frame);
          writePng(wp, (const uint8_t*)map, kW, kH);      // THIS frame, not the next one
          washForced = washNAfter;                        // and the next N, unconditionally
          std::fprintf(stderr, "[washtrig] FIRE#%ld f%ld tilemax=%.4f -> %s + next %ld frames forced\n",
                       washFires, nf->frame, tilemax, wp, washNAfter);
          // ★ r23-w19: arm the census instruments over EXACTLY the forced window (RVK_ONWASH=<cap>).
          // ⚠ THE CALIBRATION-POPULATION LAW BITES THE *TRIGGER*, not just the predicate (leg d1a,
          //   measured): the first four arms burned on f288/f312/f336/f408 — BOOT LOADING SCREENS,
          //   which are legitimately flat white and fire tilemax=1.0000 every time. A cap spent on
          //   boot is a cap not spent on the phenomenon. Two gates, both default-on when armed:
          //     RVK_ONWASH_FIELD  require the guest gameplay-field flag (GA_FIELD_ACTIVE) — the
          //                       ATTRACT never sets it (see :5264), so this excludes boot, menus,
          //                       the attract loop and the post-game-over replay dialog in one bit.
          //     RVK_ONWASH_FROM   a frame floor, for the case where the field flag is not enough.
          //   RVK_ONWASH_ANY=1 disables the field gate (the honest escape hatch: a leg that wants
          //   the boot-white population can still have it, and says so in its own env).
          { static const long onWashMax = std::getenv("RVK_ONWASH")
                ? std::strtol(std::getenv("RVK_ONWASH"), nullptr, 10) : 0;
            static const bool onWashAny = std::getenv("RVK_ONWASH_ANY") && atoi(std::getenv("RVK_ONWASH_ANY")) != 0;
            static const long onWashFrom = std::getenv("RVK_ONWASH_FROM") ? std::strtol(std::getenv("RVK_ONWASH_FROM"), nullptr, 10) : 0;
            bool fieldOk = onWashAny || (g_base && be32(GA_FIELD_ACTIVE) != 0u);
            bool fromOk = nf->frame >= onWashFrom;
            if (onWashMax > 0 && !(fieldOk && fromOk)) {
              static long gateN = 0;
              if ((++gateN % 25) == 1)
                std::fprintf(stderr, "[onwash] GATED x%ld at f%ld (field=%u from=%ld) — fire not censused\n",
                             gateN, nf->frame, g_base ? be32(GA_FIELD_ACTIVE) : 0u, onWashFrom);
            }
            if (onWashMax > 0 && fieldOk && fromOk && g_rvkWashSets < onWashMax && g_rvkWashForce <= 0) {
              ++g_rvkWashSets; g_rvkWashForce = washNAfter;
              std::fprintf(stderr, "[onwash] ARM set#%ld/%ld at f%ld for %ld frames -> [nvkdbg]+[dcen] census + nvkres dumps\n",
                           g_rvkWashSets, onWashMax, nf->frame, washNAfter);
            } else if (onWashMax > 0 && g_rvkWashSets >= onWashMax) {
              static bool capSaid = false;
              if (!capSaid) { capSaid = true;
                std::fprintf(stderr, "[onwash] CAP REACHED (%ld sets) — later fires are NOT censused (this is a cap, not a zero)\n", onWashMax); }
            }
          }
        }
      }
      vkUnmapMemory(g.dev, g.readbackMem);
    }
    static long sub = 0;
    if ((++sub % 300) == 1)
      std::fprintf(stderr, "[nvk] submit f%ld batches=%zu nv=%u ni=%u\n", nf->frame, nbs.size(), nv, ni);
    return true;
  };
  if (render) renderBody();
  rvkWindowPresent();   // idle presents re-blit the last composed g.image (guest re-present idiom)
}
