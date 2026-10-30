// rt_phys.cpp — the guest PHYSICAL-memory allocator, written as the spec the decomp proved.
// This is the 08-04-ruled rewrite (NOTE_campaign_decomp.md 08-04 blocks): the semantics that
// survived the P7 containment ladder, stated once, with the losing arms and their lever tower
// deleted. History and the elimination evidence live in the ledger, not here.
//
// THE FIVE LAWS (each measured against decomp or hardware behavior, none guessed):
//  1. THE KERNEL NEVER ZEROES PHYSICAL ALLOCATIONS. The guest's own wrappers (shell
//     FUN_82089ed8 caller / game FUN_880836d0 caller — identical XAPI code) memset when flag
//     0x40000000 asks, and that memset is recompiled code already running in this port. Only
//     VirtualAlloc-semantics callers get zeroed memory: rt_alloc = zeroing entry (NtVA commit
//     + internal host), rt_alloc_raw = the Mm physical path, raw.
//  2. THE FREE-LIST IS LIFO AND REUSES INSTANTLY. The hot streaming rotation reuses its own
//     just-freed block forever; long-freed pages persist for minutes; the game is written
//     against exactly that persistence. (The deferred-host-reader hazard that once demanded a
//     quarantine ended when the renderer moved to copy-at-record, e5f4989.)
//  3. EVERY TRACKED FREE RECYCLES — no size floor. Floors only ever existed to keep
//     zero-on-reuse away from stale-referenced blocks; with raw reuse there is nothing to
//     protect. Foreign/interior/double frees are safe no-ops (registry lookup).
//  4. THE HEAP MUST NEVER CROSS 0x20000000. A 360 has 512MB; the guest's &0x1FFFFFFF masks
//     alias anything above the line onto low memory, so crossing GUARANTEES corruption while
//     reuse below it merely reproduces hardware-identical staleness. Normal reuse skips
//     high-address pool entries (they drain via frontier retreat); at the line, anything goes.
//  5. 16KB GRANULE QUANTIZATION: sizes >= 16KB round to granule multiples and granule
//     alignment, so repetitive streaming sizes recycle exact-fit instead of decaying the pool
//     into near-miss shards. The pool is kept maximally coalesced at insert (which is also why
//     no separate at-line merge pass exists: adjacent entries cannot coexist).
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <map>
#include <mutex>
#include <chrono>
#include <vector>
#ifdef _WIN32
#include "win_compat.h"
#else
#include <sys/mman.h>
#include <unistd.h>
#endif

namespace {
constexpr uint32_t GRANULE   = 0x4000u;      // law 5
constexpr uint32_t LINE      = 0x20000000u;  // law 4: the 512MB physical boundary
constexpr uint32_t SPLIT_MIN = 0x40000u;     // requests below 256KB never carve (small-free semantics)

uint8_t* g_base;                             // guest arena; harness owns the mapping
uint32_t g_heap = 0x00300000;                // bump frontier
uint32_t g_bumpHigh = 0;                     // historic max frontier: bumps below it re-cover old bytes
std::mutex g_mu;
std::map<uint32_t, uint32_t> g_live;         // addr -> aligned size
struct FreeEnt { uint32_t addr; uint64_t freedMs; bool released; };   // released: pages handed back (RT_POOLRELEASE)
std::multimap<uint32_t, FreeEnt> g_pool;     // size -> entries; freedMs feeds only the retreat settle floor

uint64_t nowMs(){ return (uint64_t)std::chrono::duration_cast<std::chrono::milliseconds>(
  std::chrono::steady_clock::now().time_since_epoch()).count(); }
}

// ===== ALLOCATION EPOCH TABLE ==============================================================
// Eyes-free detector for host/guest identity collisions: the renderer records the epoch over a
// texture's bytes at UPLOAD and re-checks at SAMPLE; any change means the backing memory was
// freed in between (a FREE is the necessary event for identity change). 16KB buckets match the
// allocator granule — coarser would alias distinct allocations onto one counter.
enum { RT_EPOCH_SHIFT = 14 };
static uint32_t g_memEpoch[1u << 16];        // covers 1GB of guest space (256KB table)
static inline void epochBump(uint32_t addr, uint32_t sz){
  uint32_t a = addr >> RT_EPOCH_SHIFT, b = (addr + (sz ? sz - 1 : 0)) >> RT_EPOCH_SHIFT;
  if (b >= (1u << 16)) b = (1u << 16) - 1;
  for (uint32_t i = a; i <= b; ++i) ++g_memEpoch[i];
}
extern "C" uint32_t rt_mem_epoch(uint32_t addr, uint32_t bytes){
  uint32_t a = addr >> RT_EPOCH_SHIFT, b = (addr + (bytes ? bytes - 1 : 0)) >> RT_EPOCH_SHIFT;
  if (b >= (1u << 16)) b = (1u << 16) - 1;
  uint32_t s = 0;
  for (uint32_t i = a; i <= b; ++i) s = s * 0x01000193u + g_memEpoch[i];
  return s;
}

// ===== POOL PRIMITIVES =====================================================================
static void rt_decomSweep(uint64_t now);     // NtVA decommit quarantine, bottom of file

// Insert with coalescing: merge with any adjacent entries (merged block keeps the NEWEST
// freedMs so the retreat settle floor stays conservative). Keeps the pool maximally coalesced.
static void poolInsert(uint32_t addr, uint32_t sz, uint64_t freedMs){
  bool merged = true;
  while (merged){
    merged = false;
    for (auto it = g_pool.begin(); it != g_pool.end(); ++it){
      uint32_t a = it->second.addr, s = it->first;
      if (a + s == addr || addr + sz == a){
        if (a + s == addr) addr = a;
        sz += s; if (it->second.freedMs > freedMs) freedMs = it->second.freedMs;
        g_pool.erase(it); merged = true; break; }
    }
  }
  g_pool.emplace(sz, FreeEnt{addr, freedMs, false});   // a merged/new entry is re-released after its own quarantine
}

// Align-carve inside a candidate block: the block need not START aligned. Front pad re-pools
// when it is at least a granule (else leaked untracked — nothing references it); the tail
// remainder starts granule-aligned so progeny stay usable. The taken entry absorbs its own
// alignment pads, so accounting stays exact and reuse can never alias a neighbour.
static inline bool carveFit(uint32_t p, uint32_t bsz, uint32_t asz, uint32_t align, uint32_t& ap){
  ap = (p + align - 1) & ~(align - 1); return (uint64_t)ap + asz <= (uint64_t)p + bsz; }
static uint32_t takeCarved(uint32_t p, uint32_t bsz, uint64_t fm, uint32_t asz, uint32_t align, int zero){
  uint32_t ap; carveFit(p, bsz, asz, align, ap);
  uint32_t pad = ap - p;
  if (pad >= GRANULE) poolInsert(p, pad, fm);
  uint32_t tstart = (ap + asz + GRANULE - 1) & ~(GRANULE - 1), bend = p + bsz, take;
  if (bend > tstart && bend - tstart >= GRANULE){ poolInsert(tstart, bend - tstart, fm); take = tstart - ap; }
  else take = bend - ap;                       // tail too small to track: absorb (exact accounting)
  g_live[ap] = take; if (g_base && zero) std::memset(g_base + ap, 0, take);
  return ap; }

// FRONTIER RETREAT: pop pool entries that end exactly at the frontier and lower g_heap through
// them — coalescing at the frontier only. minAgeMs=2000 on the normal path (a retreated block
// is re-bumped almost immediately, so only settled frees are consumed); 0 at the line
// (desperation: crossing guarantees aliasing).
static bool frontierRetreat(uint64_t now, uint32_t minAgeMs){
  bool any = false, popped = true;
  while (popped){
    popped = false;
    for (auto it = g_pool.begin(); it != g_pool.end(); ++it)
      if (it->second.addr + it->first == g_heap && now - it->second.freedMs >= minAgeMs){
        g_heap = it->second.addr; g_pool.erase(it); popped = true; any = true; break; }
  }
  return any; }

// ===== ALLOC ===============================================================================
static uint32_t allocImpl(uint32_t size, uint32_t align, int zero){
  std::lock_guard<std::mutex> lk(g_mu);
  if (align < 1) align = 1;
  uint32_t asz;                               // law 5: granule-quantize big sizes
  if (size >= GRANULE){ asz = (size + GRANULE - 1) & ~(GRANULE - 1); if (align < GRANULE) align = GRANULE; }
  else asz = (size + 15) & ~15u;
  uint64_t now = nowMs();
  rt_decomSweep(now);
  // 1) exact-fit, LIFO (law 2): newest fitting entry in the size class; high addresses skipped
  //    (law 4 — they drain via retreat only).
  { auto rng = g_pool.equal_range(asz); auto best = g_pool.end();
    for (auto it = rng.first; it != rng.second; ++it){
      if (it->second.addr >= LINE) continue;
      if ((it->second.addr & (align - 1)) != 0) continue;
      if (best == g_pool.end() || it->second.freedMs > best->second.freedMs) best = it; }
    if (best != g_pool.end()){
      uint32_t p = best->second.addr; g_pool.erase(best); g_live[p] = asz;
      if (g_base && zero) std::memset(g_base + p, 0, asz);   // NtVA-commit semantics only (law 1)
      { static long rn = 0; if (rn++ < 20) std::fprintf(stderr, "[pool] REUSE 0x%X size=%.1fMB\n", p, asz/(1024.0*1024.0)); }
      return p; } }
  // 2) split, smallest-fit (drains shards; LIFO applies only within the smallest fitting size
  //    class — the compose-page protection lives in the exact-fit LIFO above, which serves the
  //    hot rotation before split ever runs).
  if (asz >= SPLIT_MIN){
    auto cand = g_pool.end();
    for (auto it = g_pool.lower_bound(asz); it != g_pool.end(); ++it){
      if (it->second.addr >= LINE) continue;
      uint32_t ap; if (!carveFit(it->second.addr, it->first, asz, align, ap)) continue;
      if (cand == g_pool.end()) cand = it;                       // first fit = smallest class (map order)
      else if (it->first != cand->first) break;                  // left the smallest fitting class: done
      else if (it->second.freedMs > cand->second.freedMs) cand = it; }
    if (cand != g_pool.end()){
      uint32_t p = cand->second.addr, bsz = cand->first; uint64_t fm = cand->second.freedMs;
      g_pool.erase(cand);
      uint32_t r = takeCarved(p, bsz, fm, asz, align, zero);
      { static long sn = 0; if (sn++ < 20) std::fprintf(stderr, "[pool] SPLIT-REUSE 0x%X take=%.1fMB of %.1fMB\n",
          r, g_live[r]/(1024.0*1024.0), bsz/(1024.0*1024.0)); }
      return r; } }
  // 3) every reuse path missed and we are about to bump: settle-aged frontier retreat first.
  if (frontierRetreat(now, 2000u)){
    static long rn = 0; if (rn++ < 40) std::fprintf(stderr, "[heap] RETREAT frontier -> 0x%X (%.0fMB) pooled=%zu\n",
      g_heap, g_heap/(1024.0*1024.0), g_pool.size()); }
  // 4) 512MB LINE DEFENSE (law 4): if the bump would cross, retreat at age 0, then best-fit
  //    ANY pooled block (any age, any address — at the line a high reuse is no worse than a
  //    high bump). If nothing fits, name the failure before bumping past the line.
  { uint32_t nheap = ((g_heap + align - 1) & ~(align - 1)) + asz;
    if (nheap >= LINE && frontierRetreat(nowMs(), 0u)){
      nheap = ((g_heap + align - 1) & ~(align - 1)) + asz;
      static long rn = 0; if (rn++ < 40) std::fprintf(stderr, "[heap] RETREAT-LINE frontier -> 0x%X (%.0fMB) %s\n",
        g_heap, g_heap/(1024.0*1024.0), nheap < LINE ? "(back under 512MB)" : "(still at line)"); }
    if (nheap >= LINE){
      for (auto it = g_pool.lower_bound(asz); it != g_pool.end(); ++it){
        uint32_t p = it->second.addr, bsz = it->first; uint64_t fm = it->second.freedMs; uint32_t ap;
        if (!carveFit(p, bsz, asz, align, ap)) continue;
        g_pool.erase(it);
        uint32_t r = takeCarved(p, bsz, fm, asz, align, zero);
        { static long en = 0; if (en++ < 40) std::fprintf(stderr, "[pool] EMERGENCY-REUSE 0x%X take=%.1fMB age>=0ms (512MB line defense)\n",
            r, g_live[r]/(1024.0*1024.0)); }
        return r; }
      { static long bn = 0; if (bn++ < 60){ uint32_t maxb = g_pool.empty() ? 0 : g_pool.rbegin()->first;
          std::fprintf(stderr, "[pool] LINE-BREACH asz=%.2fMB maxpooled=%.2fMB pooled=%zu align=0x%X (no fit; bumping past 512MB)\n",
            asz/(1024.0*1024.0), maxb/(1024.0*1024.0), g_pool.size(), align);
          int k = 0;
          for (auto cit = g_pool.rbegin(); cit != g_pool.rend() && k < 3; ++cit, ++k){
            uint32_t cap2; bool cf = carveFit(cit->second.addr, cit->first, asz, align, cap2);
            std::fprintf(stderr, "[pool]   cand sz=0x%X addr=0x%X age=%llums carvefit=%d\n",
              cit->first, cit->second.addr, (unsigned long long)(nowMs() - cit->second.freedMs), (int)cf); } } } } }
  // 5) bump. Fresh territory arrives OS-zeroed; re-bumped retreated territory carries old
  //    bytes, so zero it only for zeroed-semantics callers (law 1).
  g_heap = (g_heap + align - 1) & ~(align - 1); uint32_t p = g_heap; g_heap += asz; g_live[p] = asz;
  if (p < g_bumpHigh && g_base && zero) std::memset(g_base + p, 0, asz);
  if (g_heap > g_bumpHigh) g_bumpHigh = g_heap;
  { static bool warned512 = false;
    if (!warned512 && g_heap >= LINE){ warned512 = true;
      std::fprintf(stderr, "\n[heap] *** WARNING: guest heap crossed 0x20000000 (512MB physical) -- "
        "&0x1FFFFFFF masks now ALIAS onto low memory (see hi_pool_fill_re.md) ***\n\n"); } }
  { static uint32_t hwMark = 0; if ((g_heap >> 24) != (hwMark >> 24)){ hwMark = g_heap;
      double lMB = 0, pMB = 0; for (auto& kv : g_live) lMB += kv.second; for (auto& kv : g_pool) pMB += kv.first;
      std::fprintf(stderr, "[heap] high-water 0x%X (%.0fMB) live=%zu (%.0fMB) pooled=%zu (%.0fMB)\n",
        g_heap, g_heap/(1024.0*1024.0), g_live.size(), lMB/(1024.0*1024.0), g_pool.size(), pMB/(1024.0*1024.0)); } }
  return p; }

extern "C" uint32_t rt_alloc(uint32_t size, uint32_t align){ return allocImpl(size, align, 1); }
extern "C" uint32_t rt_alloc_raw(uint32_t size, uint32_t align){ return allocImpl(size, align, 0); }

// ===== FREE (law 3) ========================================================================
// callerLr kept for ABI stability with the NtFreeVirtualMemory hook; the kernel-LR floor
// discrimination it fed is gone with the floor itself.
extern "C" void rt_free_ex(uint32_t addr, uint64_t /*callerLr*/){
  if (!addr) return;
  std::lock_guard<std::mutex> lk(g_mu);
  auto it = g_live.find(addr); if (it == g_live.end()) return;   // foreign/interior/double: no-op
  { static long fN = 0; static double fMB = 0.0; fMB += it->second/(1024.0*1024.0);
    if ((++fN % 500) == 0) std::fprintf(stderr, "[pool] freed n=%ld cum=%.0fMB pooled=%zu\n", fN, fMB, g_pool.size() + 1); }
  uint32_t sz = it->second; epochBump(addr, sz); g_live.erase(it); poolInsert(addr, sz, nowMs()); }
extern "C" void rt_free(uint32_t addr){ rt_free_ex(addr, 0); }

// ===== NtVA DECOMMIT (dormant future leg — NOT part of the allocator spec) =================
// The guest allocator's 8/16MB arena segments are freed via NtFreeVirtualMemory DECOMMIT.
// Every page-removal variant broke a render shape under this port's deferred host readers, so
// the path is DEFAULT OFF; the real cure is the guest segment-release path decompiled + a real
// heap. RT_DECOMMIT=1 arms the MEM_RESET+trim variant after RT_DECOMMIT_QUAR_MS (default 10s).
struct DecomEnt { uint32_t addr, size; uint64_t t; };
static std::vector<DecomEnt> g_decomQ;
static bool decommitOn(){ static int v = [](){ const char* e = getenv("RT_DECOMMIT"); return e ? atoi(e) : 0; }(); return v != 0; }

// ===== POOL PAGE RELEASE (G5-fix, 2026-10-30; PLAN_RC1 Q5/Q6, BACKLOG post-RC1) ==============
// Q5 (10-11) bisected the ARCADE RSS ramp to THIS allocator: each demo cycle frees blocks that
// law 2 keeps in g_pool (freed, retained, instantly reusable), the next cycle's sizes miss them,
// the frontier bumps into fresh pages, and nothing on macOS/Linux ever hands the pooled pages
// back (rt_decomSweep below is _WIN32-only and serves a different queue). Plateau ~720 MB RSS at
// the 512 MB line (Q6). This arm returns the page-aligned interior of every pool entry that has
// sat unreused for RT_POOLRELEASE milliseconds, and keeps the ALLOCATOR SPEC intact:
//   law 2 (persistence): a block is released only after the quarantine (default 10 s); the hot
//     rotation reuses its own block within a frame, so it is never touched; a just-freed block a
//     deferred guest reader still looks at keeps its bytes for the whole quarantine.
//   law 1 (no kernel zeroing): a released block comes back ZERO-FILLED (fresh anonymous pages),
//     which is what law 1 already allows for fresh bump territory ("OS-zeroed"); only re-bumped
//     retreated territory carried old bytes, and a released block is exactly that case made
//     deterministic. The zeroing-semantics memset for rt_alloc callers is unchanged.
//   laws 3-5 untouched: pool membership, coalescing, LIFO/exact-fit/split, the LINE defense.
// Mechanism: Darwin/Linux mmap(MAP_FIXED|MAP_ANONYMOUS|MAP_PRIVATE|MAP_NORESERVE) over the interior
// (deterministic zeros, pages non-resident until touched, RSS drops at once; the arena is itself
// such a mapping, harness.cpp). RT_POOLRELEASE_MODE=1 uses madvise instead (Darwin
// MADV_FREE_REUSABLE / Linux MADV_DONTNEED) for A/B. Windows: no-op (its decommit lever exists).
// Lever: RT_POOLRELEASE=<quarantine ms> (0/unset = OFF, today's behaviour byte-for-byte).
// Oracle (PREREG_q5): 12-min ARCADE demo-loop RSS@10 - RSS@2, control +133 MB (GROWING > 60,
// FLAT < 25); stage pixel gate + boss plate gate re-run on the arm. Log: [poolrelease].
// RT_POOLRELEASE_MIN=<bytes> (default 0): only pool entries at least this large are released. The RSS lives in the
// big asset blocks; a floor keeps the small, frequently recycled granule entries untouched (A/B lever, 10-30).
static uint32_t poolReleaseMs(){ static uint32_t v = [](){ const char* e = getenv("RT_POOLRELEASE"); return e ? (uint32_t)atoi(e) : 0u; }(); return v; }
static int poolReleaseMode(){ static int v = [](){ const char* e = getenv("RT_POOLRELEASE_MODE"); return e ? atoi(e) : 0; }(); return v; }
static uint32_t poolReleaseMin(){ static uint32_t v = [](){ const char* e = getenv("RT_POOLRELEASE_MIN"); return e ? (uint32_t)strtoul(e, nullptr, 0) : 0u; }(); return v; }
static void rt_poolReleaseSweep(uint64_t now){   // caller holds g_mu
  const uint32_t quar = poolReleaseMs(); if (!quar || !g_base) return;
  static uint64_t lastSweep = 0; if (now - lastSweep < 1000) return; lastSweep = now;
#ifdef _WIN32
  (void)now;
#else
  static const uint32_t PG = (uint32_t)sysconf(_SC_PAGESIZE);
  static long rn = 0, rfail = 0; static double rMB = 0.0;
  for (auto& kv : g_pool){
    FreeEnt& e = kv.second;
    if (e.released || now - e.freedMs < quar) continue;
    uint32_t a = (e.addr + PG - 1) & ~(PG - 1), end = (e.addr + kv.first) & ~(PG - 1);
    e.released = true;                        // small/unaligned/under-floor entries: nothing to release, never retried
    if (end <= a || kv.first < poolReleaseMin()) continue;
    bool ok;
    if (poolReleaseMode() == 1){
#ifdef __APPLE__
      ok = madvise(g_base + a, end - a, MADV_FREE_REUSABLE) == 0;
#else
      ok = madvise(g_base + a, end - a, MADV_DONTNEED) == 0;
#endif
    } else {
      void* r = mmap(g_base + a, end - a, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE, -1, 0);
      ok = (r == (void*)(g_base + a));
    }
    if (!ok){ if (rfail++ < 8) std::fprintf(stderr, "[poolrelease] FAILED 0x%X..0x%X errno=%d\n", a, end, errno); continue; }
    rMB += (end - a)/(1024.0*1024.0);
    if ((++rn % 32) == 1 || end - a >= 0x100000u)   // every 32nd, plus every block of 1 MB or more (the size histogram)
      std::fprintf(stderr, "[poolrelease] #%ld 0x%X..0x%X (%.1fMB) cum=%.0fMB pooled=%zu mode=%d quar=%ums min=0x%X\n",
        rn, a, end, (end - a)/(1024.0*1024.0), rMB, g_pool.size(), poolReleaseMode(), quar, poolReleaseMin());
  }
#endif
}

static void rt_decomSweep(uint64_t now){     // caller holds g_mu
  rt_poolReleaseSweep(now);
  static uint32_t quar = [](){ const char* e = getenv("RT_DECOMMIT_QUAR_MS"); return e ? (uint32_t)atoi(e) : 10000u; }();
  size_t w = 0;
  for (size_t i = 0; i < g_decomQ.size(); ++i){ DecomEnt e = g_decomQ[i];
    if (!e.size) continue;
    if (now - e.t >= quar){
#ifdef _WIN32
      // MEM_RESET keeps pages readable (deferred readers can never fault); VirtualUnlock trims
      // them from the working set now; they soft-fault back zero-cost on any later touch.
      uint32_t a = (e.addr + 0xFFFu) & ~0xFFFu, end = (e.addr + e.size) & ~0xFFFu;
      if (end > a && g_base){ VirtualAlloc(g_base + a, end - a, MEM_RESET, PAGE_READWRITE); VirtualUnlock(g_base + a, end - a);
        static long dn = 0; static double dMB = 0.0; dMB += (end - a)/(1024.0*1024.0);
        if ((++dn % 16) == 1) std::fprintf(stderr, "[decommit] reset+trim #%ld 0x%X..0x%X cum=%.0fMB\n", dn, a, end, dMB); }
#endif
    } else g_decomQ[w++] = e;
  }
  g_decomQ.resize(w);
}
extern "C" void rt_decommit_note(uint32_t addr, uint32_t size){
  if (!addr || !decommitOn()) return;
  std::lock_guard<std::mutex> lk(g_mu);
  // Honor ONLY ranges fully inside a registered live block: the guest also decommits subranges
  // of its reqbase-committed boot layout, which overlaps our bump arena in the flat world.
  auto it = g_live.upper_bound(addr);
  if (it == g_live.begin()) return;
  --it;                                       // greatest registered base <= addr
  if (!size){ if (it->first != addr) return; size = it->second; }
  if (addr < it->first || (uint64_t)addr + size > (uint64_t)it->first + it->second) return;
  g_decomQ.push_back(DecomEnt{addr, size, nowMs()});
}
extern "C" void rt_recommit(uint32_t addr, uint32_t size){
  if (!addr || !size || !decommitOn()) return;
  std::lock_guard<std::mutex> lk(g_mu);
  for (auto& e : g_decomQ) if (e.size && addr < e.addr + e.size && e.addr < addr + size) e.size = 0;   // cancel pending
#ifdef _WIN32
  if (g_base){ uint32_t a = addr & ~0xFFFu, end = (addr + size + 0xFFFu) & ~0xFFFu;
    VirtualAlloc(g_base + a, end - a, MEM_COMMIT, PAGE_READWRITE); }   // idempotent; committed pages arrive zeroed
#endif
}

// ===== HARNESS GLUE ========================================================================
extern "C" void rt_phys_init(uint8_t* base){ g_base = base; }
extern "C" uint32_t rt_phys_frontier(){ std::lock_guard<std::mutex> lk(g_mu); return g_heap; }
