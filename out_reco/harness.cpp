#include "ppc_recomp_shared.h"
#include <file.h>
#include <image.h>
// L4/E5: in a COMBINED build the game function table arrives from a module DLL, not from this
// image's PPCFuncMappings.  Relative path on purpose — no build script has to gain an -I.
#ifdef FUTARI_COMBINED
#include "../host/module_registry.h"
#include "../host/futari_module_desc.h"
#endif
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <atomic>
#include <mutex>
#include <map>
#include <chrono>
#include <vector>
#include <algorithm>
#ifdef _WIN32
#include "win_compat.h"
#else
#include <csignal>
#include <execinfo.h>
#include <sys/mman.h>
#endif
#ifdef _WIN32
// C23 round-half-to-even the recompiler emits (glibc has it; MSVC UCRT does not).
#include <cmath>
extern "C" float  roundevenf(float x){ return nearbyintf(x); }
extern "C" double roundeven (double x){ return nearbyint(x); }
#endif
extern std::atomic<long> g_import_calls;
static uint8_t* g_base; static uint32_t g_heap=0x00300000;
static uint32_t g_ord1=0;
// futari_merged / RT_SHELL cross-module probe: shell's own PPCFuncMapping table, built
// with -DPPCFuncMappings=PPCFuncMappings_shell so its symbol doesn't collide with the
// game's PPCFuncMappings. Only referenced when RT_SHELL=1 (see main()). Declared WEAK so
// that futari_mode -- which links no shell/gen object defining this symbol -- still links
// cleanly; it will simply resolve to null there (and RT_SHELL is never set for futari_mode).
extern PPCFuncMapping PPCFuncMappings_shell[] __attribute__((weak));
extern "C" uint32_t g_thread_xapi, g_thread_entry, g_thread_ctx;
uint32_t g_thread_xapi=0, g_thread_entry=0, g_thread_ctx=0;
static std::mutex g_heap_mu;
// Free-pool over the bump heap (2026-07-20 late-stage-soak leak fix): the attract cycle leaks
// ~75MB/cycle because the guest's allocator repeatedly grows/releases 8-16MB arenas
// (NtAllocateVirtualMemory lr=0x8208CBD0) and our free stubs were no-ops — 26min soak reached
// 1.98GB RSS with eventual guest-address exhaustion. rt_alloc registers every allocation;
// rt_free returns it to an EXACT-SIZE pool that rt_alloc reuses (exact match only — no
// splitting, so reuse can never alias a neighbour). Unknown/foreign addresses are ignored.
static std::map<uint32_t,uint32_t> g_allocSz;        // addr -> aligned size (live allocations)
// size -> {addr, freedAtMs}. QUARANTINED (2026-07-20 bisect: immediate recycle+zero blanked the
// renderer — our async/deferred walker reads guest memory LATER than a real GPU would, so a
// freshly-freed physical block can still have pending host reads; RT_FREEPOOL=0 run was clean,
// immediate-reuse run was navy). A freed block becomes reusable only after RT_FREEPOOL_QUAR_MS
// (default 5000) — far past any deferred read, far under the ~90s leak cycle.
// ===== ALLOCATION EPOCH TABLE (2026-08-07) ==============================================
// AN EYES-FREE DETECTOR FOR HOST/GUEST IDENTITY COLLISIONS.
//
// The renderer caches decoded textures keyed on GUEST BASE ADDRESS. If the guest frees that
// memory and the allocator hands the same address to a DIFFERENT asset, the cache keeps serving
// the old decode under a base that now means something else — "backdrop pages painted over the
// plates". That is the standing suspect for the 360 select corruption, and it is the same class
// as the 08-04 512MB physical-alias identity break.
//
// Every attempt to judge that defect so far has been a human looking at a screen, on a defect
// whose severity tracks ALLOCATION LAYOUT (it moves with RT_FREEPOOL_QUAR_MS) — so every verdict
// was N=1 on a nondeterministic input, which is how a "screen-drive verified clean" config from
// 08-04 turned out not to reproduce on 08-07. This makes the question mechanical instead.
//
// A FREE is the necessary event: memory cannot be re-handed to another asset without first being
// freed. So bumping only on free catches every collision, and costs one write per free.
// Granularity is 16KB to match the allocator's own granule (RT_HEAPGRAN) — coarser buckets would
// alias distinct small allocations onto one counter and manufacture false positives.
enum { RT_EPOCH_SHIFT = 14 };                     // 16KB buckets
static uint32_t g_memEpoch[1u << 16];             // covers 1GB of guest space (256KB table)
static inline void rt_epochBump(uint32_t addr, uint32_t sz){
  uint32_t a = addr >> RT_EPOCH_SHIFT, b = (addr + (sz ? sz - 1 : 0)) >> RT_EPOCH_SHIFT;
  if (b >= (1u << 16)) b = (1u << 16) - 1;
  for (uint32_t i = a; i <= b; ++i) ++g_memEpoch[i];
}
// Query the epoch covering [addr, addr+bytes). The renderer records this at texture UPLOAD and
// re-checks it at SAMPLE; any change means the backing memory was freed in between.
extern "C" uint32_t rt_mem_epoch(uint32_t addr, uint32_t bytes){
  uint32_t a = addr >> RT_EPOCH_SHIFT, b = (addr + (bytes ? bytes - 1 : 0)) >> RT_EPOCH_SHIFT;
  if (b >= (1u << 16)) b = (1u << 16) - 1;
  uint32_t s = 0;
  for (uint32_t i = a; i <= b; ++i) s = s * 0x01000193u + g_memEpoch[i];
  return s;
}

struct FreeEnt { uint32_t addr; uint64_t freedMs; };
static std::multimap<uint32_t,FreeEnt> g_freePool;
// 2026-07-31 BIG-RESERVE (session 100006): >=4MB frees park here (cap 6), drawable only by
// >=2MB requests — the split path had CANNIBALIZED pooled 4MB blocks for 1.2MB requests
// ("take=1.2MB of 4.0MB"), starving late-stage 4MB align=0x10000 loads into bumping past the
// 512MB line. Line defense may raid it at relaxed age as last resort. RT_FREEPOOL_BIGRES=0 reverts.
static std::multimap<uint32_t,FreeEnt> g_bigReserve;
// 2026-08-04 HW-true: default OFF — the diversion bypasses insert-time coalescing, hiding 4MB+
// blocks from merge chains exactly when the post-swap bulk-free needs them to form big runs.
// Its original job (split-cannibalization starving 4MB asks) is covered by age-0 best-fit now.
static int rt_bigresOn(){ static int v=[](){ const char* e=getenv("RT_FREEPOOL_BIGRES"); return e?atoi(e):0; }(); return v; }
static uint64_t rt_nowms(){ return (uint64_t)std::chrono::duration_cast<std::chrono::milliseconds>(
  std::chrono::steady_clock::now().time_since_epoch()).count(); }
static void rt_decomSweep(uint64_t now);   // defined below (NtVA DECOMMIT quarantine)
// FIX-A part 1 (2026-07-31): COALESCE adjacent pooled blocks on insert so large requests keep
// finding low blocks and the bump pointer stays under the 512MB physical line. O(pool) scan per
// insert — pool is ~1-2k entries and frees are low-rate; cost negligible. A merged block takes
// the YOUNGEST freedMs (conservative: quarantine restarts from the newest constituent).
static void rt_poolInsertCoalesced(uint32_t addr, uint32_t sz, uint64_t freedMs){
  // BIG-RESERVE diversion: park >=4MB blocks away from the split path's cannibalization.
  if(rt_bigresOn() && sz>=0x400000u && g_bigReserve.size()<6){
    g_bigReserve.emplace(sz, FreeEnt{addr, freedMs}); return; }
  // COALESCING history: default OFF 07-31 after menu-DOWN died — "merged small kernel-freed
  // spans reused+ZEROED under live shell references". 2026-08-04 decomp verdict: the killer in
  // that sentence was ZEROED, not merged — the kernel never zeroes, and raw reuse now matches
  // hardware (stale readers see old bytes). Re-armed ON; RT_FREEPOOL_COALESCE=0 reverts.
  static int coalesceOn=[](){ const char* e=getenv("RT_FREEPOOL_COALESCE"); return e?atoi(e):1; }();
  if(!coalesceOn){ g_freePool.emplace(sz, FreeEnt{addr, freedMs}); return; }
  bool merged = true;
  while (merged){
    merged = false;
    for (auto it = g_freePool.begin(); it != g_freePool.end(); ++it){
      uint32_t a = it->second.addr, s = it->first;
      if (a + s == addr){ addr = a; sz += s; if (it->second.freedMs > freedMs) freedMs = it->second.freedMs;
        g_freePool.erase(it); merged = true; break; }
      if (addr + sz == a){ sz += s; if (it->second.freedMs > freedMs) freedMs = it->second.freedMs;
        g_freePool.erase(it); merged = true; break; }
    }
  }
  g_freePool.emplace(sz, FreeEnt{addr, freedMs});
}
// 2026-07-31 ALIGN-CARVE FIX (LINE-BREACH telemetry verdict, user log 085954): asz granularity
// is 16B, so split remainders started at p+asz were UNALIGNED for the align=0x1000 requests
// that dominate — once a block was split, it and ALL its progeny became invisible to every
// future aligned request ("asz=0.50MB maxpooled=15.00MB no fit" x60 while heap bumped to
// 592MB). Cure: carve AT the aligned offset INSIDE any candidate block (front pad re-pooled
// if >=64KB, else leaked untracked — nothing references it), and round the tail remainder's
// start UP to 4KB so progeny stay usable. Accounting stays exact: the taken entry absorbs its
// own alignment pads, so reuse still cannot alias a neighbour.
// 2026-08-04 GRANULE QUANTIZATION (containment part 3 — the near-miss disease): the swapbounce
// P7 run breached 51x with asz=0.50MB vs maxpooled=0.496MB — split progeny land a few KB short
// of the repetitive streaming request sizes, so once a block is split its descendants can NEVER
// serve that size class again and the pool decays into thousands of near-miss fragments
// (2407 pooled, all <=0.5MB, while 0.5MB requests bump past the line). Cure: round every
// allocation >=granule up to a granule multiple (and carve on granule boundaries, and start
// granule blocks granule-ALIGNED so exact reuse never fails the alignment check). Repetitive
// sizes then recycle exact-fit instead of fragmenting. Granule dropped 64KB->16KB 2026-08-04
// (4th P7 pass): 64KB inflation across ~720 live blocks (~23MB) was itself the size of the
// remaining burst-peak overshoot (528MB high-water = 19MB over). RT_HEAPGRAN=0 reverts to
// 16-byte rounding; RT_HEAPGRAN_SZ overrides the granule.
static int rt_granOn(){ static int v=[](){ const char* e=getenv("RT_HEAPGRAN"); return e?atoi(e):1; }(); return v; }
static uint32_t rt_granSz(){ static uint32_t v=[](){ const char* e=getenv("RT_HEAPGRAN_SZ"); return e?(uint32_t)strtoul(e,nullptr,0):0x4000u; }(); return v; }
static inline bool rt_carveFit(uint32_t p,uint32_t bsz,uint32_t asz,uint32_t align,uint32_t& ap){
  ap=(p+align-1)&~(align-1); return (uint64_t)ap+asz<=(uint64_t)p+bsz; }
// 2026-08-04 HARDWARE-TRUE ZEROING (decomp verdict, ends the poison-class era): the shell and
// game allocator wrappers (shell FUN_82089ed8 caller / game FUN_880836d0 caller — IDENTICAL
// XAPI code) memset their physical allocations THEMSELVES, and only when flag 0x40000000 is
// set. The 360 kernel does NOT zero physical allocations — and those caller-side memsets are
// recompiled guest code that already runs in this port. Every historical "poison class"
// (select blanking 07-20, menu-DOWN death 07-31, navy) was OUR memset-on-reuse showing zeros
// where hardware shows stale-but-plausible old bytes. Mm-path allocations therefore reuse RAW
// (rt_alloc_raw); NtVA commits keep zeroing (VirtualAlloc semantics really do zero on 360);
// internal host callers keep the legacy zeroed rt_alloc. RT_ALLOCZERO=1 forces the old
// zero-everything behavior as the master revert lever.
static int rt_zeroForce(){ static int v=[](){ const char* e=getenv("RT_ALLOCZERO"); return e?atoi(e):0; }(); return v; }
static uint32_t rt_takeCarved(uint32_t p,uint32_t bsz,uint64_t fm,uint32_t asz,uint32_t align,int zero){
  uint32_t ap; rt_carveFit(p,bsz,asz,align,ap);
  uint32_t pad=ap-p;
  uint32_t gm=rt_granOn()?rt_granSz():0x1000u;
  if(pad>=gm) rt_poolInsertCoalesced(p,pad,fm);   // re-pool pads down to granule size (was 64KB — leaked)
  uint32_t tgran=gm-1;                            // granule mode: tail progeny stay granule-aligned multiples
  uint32_t tstart=(ap+asz+tgran)&~tgran, bend=p+bsz, take;
  if(bend>tstart && bend-tstart>=gm){ rt_poolInsertCoalesced(tstart,bend-tstart,fm); take=tstart-ap; }
  else take=bend-ap;                        // tail too small to track: absorb (exact accounting)
  g_allocSz[ap]=take; if(g_base && (zero||rt_zeroForce())) std::memset(g_base+ap,0,take);
  return ap; }
// 2026-08-04 ALLOCATOR CONTAINMENT (the sharpened 512MB root, see NOTE_campaign_decomp.md):
// the bump frontier only ever CLIMBS. Blocks freed adjacent to the frontier (the post-swap
// pattern: outgoing module's assets die at the top of the heap) sit in the pool at high
// addresses forever, and every post-swap load burst bumps from the previous session's
// high-water mark until it crosses 0x20000000 — where addresses are UNPHYSICAL on hardware
// (the &0x1FFFFFFF fetch mask aliases them onto low memory; RVK_PHYSKEY fixed the resolve
// keys but streamed guest-RAM decodes above the line are unrecoverable renderer-side).
// FRONTIER RETREAT: when every reuse path misses and we are about to bump, first pop pool /
// big-reserve entries that end EXACTLY at the frontier (quarantine-expired only — same
// deferred-reader hazard ladder as reuse) and lower g_heap through them. Effect = coalescing
// at the frontier only, which sidesteps the insert-time-coalescing poison class (merged small
// kernel spans reused under live shell references — those small frees never enter the pool,
// so they act as live barriers that naturally bound retreat depth). Re-bumped territory is
// memset (bump pages are only fresh-zero the FIRST time — see g_bumpHigh). RT_HEAPRETREAT=0
// reverts to climb-only.
static uint32_t g_bumpHigh=0;    // historic max frontier: bumps below it re-cover old bytes
static int rt_retreatOn(){ static int v=[](){ const char* e=getenv("RT_HEAPRETREAT"); return e?atoi(e):1; }(); return v; }
static bool rt_frontierRetreat(uint64_t now, uint32_t minAgeMs){
  bool any=false;
  for(;;){
    bool popped=false;
    for(auto it=g_freePool.begin(); it!=g_freePool.end(); ++it)
      if(it->second.addr+it->first==g_heap && now-it->second.freedMs>=minAgeMs){
        g_heap=it->second.addr; g_freePool.erase(it); popped=true; any=true; break; }
    if(!popped && rt_bigresOn())
      for(auto it=g_bigReserve.begin(); it!=g_bigReserve.end(); ++it)
        if(it->second.addr+it->first==g_heap && now-it->second.freedMs>=minAgeMs){
          g_heap=it->second.addr; g_bigReserve.erase(it); popped=true; any=true; break; }
    if(!popped) break; }
  return any; }
// 2026-08-04 containment part 2: NEVER hand out pooled blocks at/above the line from the
// normal reuse paths — those addresses cannot exist on hardware, so reusing them perpetuates
// the identity break even when low space is available. They drain only via frontier retreat
// (which removes them from circulation entirely). Emergency at-line paths keep them: at the
// line, a high reuse is no worse than a high bump. RT_POOLNOHI=0 reverts.
static bool rt_poolHiSkip(uint32_t addr){
  static int v=[](){ const char* e=getenv("RT_POOLNOHI"); return e?atoi(e):1; }();
  return v && addr>=0x20000000u; }
static uint32_t rt_alloc_impl(uint32_t size,uint32_t align,int zero){ std::lock_guard<std::mutex> lk(g_heap_mu); if(align<1)align=1;
  // RT_HEAPPAD=<MB> [RT_HEAPPAD_MS=<ms>] (2026-08-01 shadow repro): one-shot bump of the heap
  // pointer so a cold-boot scripted run reaches the HIGH-HEAP regime the ranking-box defect
  // needs (user real-play sessions cross 544MB; scripted attract plateaus ~432MB and stays
  // clean). Delayed engagement leaves boot-era allocation addresses untouched so only the
  // late/streamed allocs shift and the 512MB line defenses engage at ranking time. Default off.
  { static uint32_t padMB=[](){ const char* e=getenv("RT_HEAPPAD"); return e?(uint32_t)atoi(e):0u; }();
    if(padMB){
      static uint32_t padMs=[](){ const char* e=getenv("RT_HEAPPAD_MS"); return e?(uint32_t)atoi(e):0u; }();
      static uint64_t t0=rt_nowms(); static bool padDone=false;
      if(!padDone && rt_nowms()-t0>=padMs){ padDone=true;
        g_heap=(g_heap+0xFFFFu)&~0xFFFFu; uint32_t pp=g_heap; g_heap+=padMB*0x100000u;
        std::fprintf(stderr,"[heap] RT_HEAPPAD engaged: +%uMB hole at 0x%X -> heap now 0x%X (%.0fMB)\n",
          padMB,pp,g_heap,g_heap/(1024.0*1024.0)); } } }
  uint32_t asz; { uint32_t g=rt_granSz();
    if(rt_granOn() && size>=g){ asz=(size+g-1)&~(g-1); if(align<g) align=g; }
    else asz=((size+15)&~15u); }
  // exact-size pool reuse (first entry whose address satisfies the requested alignment)
  // 2026-08-04 HW-true FINAL (third P7 forensics pass): even 250ms rejected the streamer's
  // ~16ms hot rotation below the line, so every cycle bumped fresh space — THE climb engine.
  // Hardware's free-list reuses instantly (LIFO, age 0); with raw no-zero reuse the quarantine
  // no longer protects anything the hardware protects. The async walker's ~50ms late-read is a
  // renderer-timing divergence to be judged by eyes and fixed renderer-side if real.
  // RT_FREEPOOL_QUAR_MS=5000 reverts to the beta1 guard.
  static uint32_t quarMs=[](){ const char* e=getenv("RT_FREEPOOL_QUAR_MS"); return e?(uint32_t)atoi(e):0u; }();
  // 2026-08-04 LIFO REUSE (eyeball verdict on the first HW-true build): serving the OLDEST
  // freed block first (multimap insertion order = FIFO) recycled long-freed select-compose
  // pages the shell still references — black/displaced chunks on the 360 shot select. The
  // kernel's free-list is a LIFO stack: the hot streaming rotation reuses its OWN just-freed
  // block forever and old freed pages survive for minutes, exactly the persistence the game
  // was written against. Pick the NEWEST fitting entry in the size class. RT_POOLFIFO=1 reverts.
  static int lifoOn=[](){ const char* e=getenv("RT_POOLFIFO"); return !(e&&e[0]=='1'); }();
  auto rng=g_freePool.equal_range(asz);
  { uint64_t now=rt_nowms();
    rt_decomSweep(now);
    auto best=g_freePool.end();
    for(auto it=rng.first;it!=rng.second;++it){
      if(rt_poolHiSkip(it->second.addr)) continue;
      if((it->second.addr&(align-1))==0 && now-it->second.freedMs>=quarMs){
        if(best==g_freePool.end() || (lifoOn && it->second.freedMs>best->second.freedMs)) best=it;
        if(!lifoOn) break; } }
    if(best!=g_freePool.end()){
        uint32_t p=best->second.addr; g_freePool.erase(best); g_allocSz[p]=asz;
        if(g_base && (zero||rt_zeroForce())) std::memset(g_base+p,0,asz);   // NtVA-commit semantics only; Mm reuse stays raw (HW-true)
        { static long rn=0; if(rn++<20) std::fprintf(stderr,"[pool] REUSE 0x%X size=%.1fMB\n",p,asz/(1024.0*1024.0)); }
        return p; } }
  // BIG-RESERVE draw: only >=2MB requests may take parked big blocks (normal quarantine age).
  if(rt_bigresOn() && asz>=0x200000u){
    uint64_t now=rt_nowms();
    for(auto bit=g_bigReserve.lower_bound(asz); bit!=g_bigReserve.end(); ++bit){
      if(now-bit->second.freedMs<quarMs) continue;
      if(rt_poolHiSkip(bit->second.addr)) continue;
      uint32_t p=bit->second.addr, bsz=bit->first; uint64_t fm=bit->second.freedMs; uint32_t ap;
      if(!rt_carveFit(p,bsz,asz,align,ap)) continue;
      g_bigReserve.erase(bit);
      uint32_t r=rt_takeCarved(p,bsz,fm,asz,align,zero);
      { static long rn=0; if(rn++<20) std::fprintf(stderr,"[pool] BIGRES-REUSE 0x%X take=%.1fMB of %.1fMB\n",
          r,g_allocSz[r]/(1024.0*1024.0),bsz/(1024.0*1024.0)); }
      return r; } }
  // 2026-07-31 FIX-A' (512MB-alias root fix, _tmpscripts/hi_pool_fill_re.md): exact-size-only
  // reuse never recycles against variable-size stage assets, so the bump pointer climbs past
  // 0x20000000 and the guest's &0x1FFFFFFF physical mask aliases HI field-pool pages onto live
  // low memory (the Xbox has 512MB; addresses above it cannot exist on HW). BEST-FIT WITH
  // SPLITTING: for requests >=256KB, take the smallest quarantine-expired pooled block >= asz
  // (>=1MB pool entries only -- small-free semantics unchanged, see the poison notes above),
  // carve the front, return the remainder (>=64KB, else absorb) to the pool with the ORIGINAL
  // freedMs (already quarantine-aged). Accounting stays exact so reuse still cannot alias a
  // neighbour. RT_FREEPOOL_SPLIT=0 reverts to exact-only.
  { static int splitOn=[](){ const char* e=getenv("RT_FREEPOOL_SPLIT"); return e?atoi(e):1; }();
    if(splitOn && asz>=0x40000u){
      uint64_t now=rt_nowms();
      // Split = SMALLEST-fit first (drains shards; LIFO-windowing here cost 17MB of footprint
      // and re-grazed the line — 5th P7 pass). Newest-first applies only as the tie-break
      // WITHIN the smallest fitting size class; the compose-page protection lives in the
      // exact-fit LIFO above, which serves the hot rotation before split ever runs.
      auto sbest=g_freePool.end(); auto sfall=g_freePool.end();
      // 2026-08-04 6th P7 pass: the old >=1MB scan floor (small-free poison relic, dead since
      // raw reuse) made every sub-1MB pooled block invisible to all but its exact size class —
      // 101MB of 0.48MB shards unservable while 0.50MB asks grazed the line. Scan from asz.
      for(auto bit=g_freePool.lower_bound(asz); bit!=g_freePool.end(); ++bit){
        if(now-bit->second.freedMs<quarMs) continue;
        if(rt_poolHiSkip(bit->second.addr)) continue;
        uint32_t p=bit->second.addr, bsz=bit->first; uint32_t ap;
        if(!rt_carveFit(p,bsz,asz,align,ap)) continue;   // align-carve: block need not START aligned
        if(sfall==g_freePool.end()) sfall=bit;           // first fit = smallest size (map order)
        else if(bit->first!=sfall->first) break;         // left the smallest fitting class: done
        if(lifoOn && bit->second.freedMs>sfall->second.freedMs) sfall=bit;   // newest within class
        if(!lifoOn) break; }
      { auto take=(sbest!=g_freePool.end())?sbest:sfall;
        if(take!=g_freePool.end()){
          uint32_t p=take->second.addr, bsz=take->first; uint64_t fm=take->second.freedMs;
          g_freePool.erase(take);
          uint32_t r=rt_takeCarved(p,bsz,fm,asz,align,zero);
          { static long sn=0; if(sn++<20) std::fprintf(stderr,"[pool] SPLIT-REUSE 0x%X take=%.1fMB of %.1fMB\n",
              r,g_allocSz[r]/(1024.0*1024.0),bsz/(1024.0*1024.0)); }
          return r; } }
    } }
  // FRONTIER RETREAT (2026-08-04 containment; see header comment above rt_frontierRetreat):
  // every reuse path missed and we are about to bump — first walk the frontier back down
  // through quarantine-expired pooled blocks that end exactly at it.
  if(rt_retreatOn()){
    uint64_t now=rt_nowms();
    // 2s floor: a retreated block is re-bumped (= reused) almost immediately, so the normal
    // path only consumes settled frees; the at-line retreat below stays age-0 (desperation).
    if(rt_frontierRetreat(now,2000u)){
      static long rn=0; if(rn++<40) std::fprintf(stderr,"[heap] RETREAT frontier -> 0x%X (%.0fMB) pooled=%zu\n",
        g_heap,g_heap/(1024.0*1024.0),g_freePool.size()); } }
  // FIX-A part 2 (2026-07-31): 512MB LINE DEFENSE. If the bump would cross the physical line,
  // crossing is strictly worse than a relaxed quarantine (the crossing GUARANTEES aliasing;
  // relaxed reuse merely risks a transient stale read, and the floors below stay far above the
  // deferred walker's ~50ms read window — the historic navy poison was IMMEDIATE reuse).
  // Best-fit ANY block >= asz with progressively relaxed age floors, loudly.
  { uint32_t nheap=((g_heap+align-1)&~(align-1))+asz;
    // At-line relaxed retreat (2026-08-04): the post-swap load burst arrives inside the 5s
    // quarantine, so the normal retreat above may not fire yet — at the line, retreat at the
    // ladder's 120ms floor (same age the EMERGENCY-REUSE paths already hand blocks out at;
    // crossing the line GUARANTEES aliasing, a 120ms-old re-bump merely risks a stale read).
    if(nheap>=0x20000000u && rt_retreatOn() && rt_frontierRetreat(rt_nowms(),0u)){
      nheap=((g_heap+align-1)&~(align-1))+asz;
      static long rn=0; if(rn++<40) std::fprintf(stderr,"[heap] RETREAT-LINE frontier -> 0x%X (%.0fMB) %s\n",
        g_heap,g_heap/(1024.0*1024.0),nheap<0x20000000u?"(back under 512MB)":"(still at line)"); }
    if(nheap>=0x20000000u){
      // 2026-07-31 stage-4 verdict (log 093405): added 4th floor 120ms — asz=0.50 vs
      // maxpooled=0.51 breaches were AGE misses, not size; 120ms is still >2x the deferred
      // walker's ~50ms window, and crossing the line GUARANTEES aliasing.
      // 2026-08-04 forensics verdict (swapbounce breach dump): all 61 breaches had low-address
      // carvefit=1 candidates aged 1-37ms — the streamer cycles blocks at ~17ms, faster than
      // every floor. Hardware's free-list reuses instantly; final floor 0ms — at the line a
      // possible one-frame stale read strictly beats guaranteed physical-alias corruption.
      static const uint32_t relax[5] = {2000u, 750u, 250u, 120u, 0u};
      uint64_t now=rt_nowms();
      for (int ri=0; ri<5; ++ri){
        for (auto bit=g_freePool.lower_bound(asz); bit!=g_freePool.end(); ++bit){
          if(now-bit->second.freedMs<relax[ri]) continue;
          uint32_t p=bit->second.addr, bsz=bit->first; uint64_t fm=bit->second.freedMs; uint32_t ap;
          if(!rt_carveFit(p,bsz,asz,align,ap)) continue;   // align-carve: block need not START aligned
          g_freePool.erase(bit);
          uint32_t r=rt_takeCarved(p,bsz,fm,asz,align,zero);
          { static long en=0; if(en++<40) std::fprintf(stderr,"[pool] EMERGENCY-REUSE 0x%X take=%.1fMB age>=%ums (512MB line defense)\n",r,g_allocSz[r]/(1024.0*1024.0),relax[ri]); }
          return r; }
      }
      // Line-defense reserve raid: at the line ANY size may draw the big reserve, relaxed age.
      if(rt_bigresOn()){
        for (int ri=0; ri<5; ++ri){
          for(auto bit=g_bigReserve.lower_bound(asz); bit!=g_bigReserve.end(); ++bit){
            if(now-bit->second.freedMs<relax[ri]) continue;
            uint32_t p=bit->second.addr, bsz=bit->first; uint64_t fm=bit->second.freedMs; uint32_t ap;
            if(!rt_carveFit(p,bsz,asz,align,ap)) continue;
            g_bigReserve.erase(bit);
            uint32_t r=rt_takeCarved(p,bsz,fm,asz,align,zero);
            { static long bn2=0; if(bn2++<20) std::fprintf(stderr,"[pool] EMERGENCY-BIGRES 0x%X take=%.1fMB (512MB line defense)\n",
                r,g_allocSz[r]/(1024.0*1024.0)); }
            return r; } } }
      // 2026-07-31 EMERGENCY-MERGE (stage-4 verdict, log 093405: asz=4.00MB maxpooled=0.51MB —
      // GENUINE fragmentation). At the line only: merge ADJACENT pool entries that are EACH
      // individually reusable (>=256KB, >=120ms) into a run big enough to carve asz. Safe where
      // insert-time coalescing was POISON: that class merged small NEVER-individually-reusable
      // kernel spans; merging blocks that each already qualify for reuse adds no exposure the
      // members didn't have alone. RT_FREEPOOL_LINEMERGE=0 reverts.
      { static int lm=[](){ const char* e=getenv("RT_FREEPOOL_LINEMERGE"); return e?atoi(e):1; }();
        if(lm){
          struct MEnt{ uint32_t addr,sz; uint64_t fm; std::multimap<uint32_t,FreeEnt>::iterator it; };
          std::vector<MEnt> v;
          for(auto it=g_freePool.begin(); it!=g_freePool.end(); ++it)
            if(it->first>=0x40000u && now-it->second.freedMs>=120u)
              v.push_back(MEnt{it->second.addr,it->first,it->second.freedMs,it});
          std::sort(v.begin(),v.end(),[](const MEnt&a,const MEnt&b){ return a.addr<b.addr; });
          for(size_t i=0;i<v.size();){
            size_t j=i; uint32_t rs=v[i].addr, re=rs+v[i].sz; uint64_t fm=v[i].fm;
            while(j+1<v.size() && v[j+1].addr==re){ ++j; re+=v[j].sz; if(v[j].fm>fm) fm=v[j].fm; }
            uint32_t ap=(rs+align-1)&~(align-1);
            if(j>i && (uint64_t)ap+asz<=re){
              for(size_t k=i;k<=j;++k) g_freePool.erase(v[k].it);
              uint32_t r=rt_takeCarved(rs,re-rs,fm,asz,align,zero);
              { static long mn=0; if(mn++<40) std::fprintf(stderr,"[pool] EMERGENCY-MERGE %zu blocks -> %.1fMB run, take=%.1fMB (512MB line defense)\n",
                  j-i+1,(re-rs)/(1024.0*1024.0),g_allocSz[r]/(1024.0*1024.0)); }
              return r; }
            i=j+1; }
        } }
      // 2026-07-31 BREACH TELEMETRY: user session 083852 crossed to 544MB despite the defense --
      // every breach means no pooled block >= asz survived the filters. Name the failure so the
      // next fix (coalescing re-arm vs bigger split floor) is chosen on data, not guess:
      // maxpooled < asz  => fragmentation (coalescing territory); maxpooled >= asz => age/align.
      { static long bn=0; if(bn++<60){ uint32_t maxb=g_freePool.empty()?0:g_freePool.rbegin()->first;
          std::fprintf(stderr,"[pool] LINE-BREACH asz=%.2fMB maxpooled=%.2fMB pooled=%zu align=0x%X (no fit; bumping past 512MB)\n",
            asz/(1024.0*1024.0),maxb/(1024.0*1024.0),g_freePool.size(),align);
          // 2026-08-04 breach forensics: name WHY the top candidates were rejected (age vs
          // align-carve vs size) — the second P7 run rejected 0.56MB blocks for 0.50MB asks
          // 48x and the reason was not derivable from the summary line alone.
          int k=0; uint64_t nw=rt_nowms();
          for(auto cit=g_freePool.rbegin(); cit!=g_freePool.rend() && k<3; ++cit,++k){
            uint32_t cap2; bool cf=rt_carveFit(cit->second.addr,cit->first,asz,align,cap2);
            std::fprintf(stderr,"[pool]   cand sz=0x%X addr=0x%X age=%llums carvefit=%d\n",
              cit->first,cit->second.addr,(unsigned long long)(nw-cit->second.freedMs),(int)cf); } } }
    } }
  g_heap=(g_heap+align-1)&~(align-1); uint32_t p=g_heap; g_heap+=asz; g_allocSz[p]=asz;
  // Re-bumped retreated territory carries old bytes — fresh-zero only holds the first time the
  // frontier passes an address (mmap pages). Zero only for zeroed-semantics callers (HW-true).
  if(p<g_bumpHigh && g_base && (zero||rt_zeroForce())) std::memset(g_base+p,0,asz);
  if(g_heap>g_bumpHigh) g_bumpHigh=g_heap;
  // FIX-C: the 512MB line is a HARD physical boundary on real hardware -- crossing it means
  // guest &0x1FFFFFFF masks alias. Die-loud-adjacent: warn once, unmissable.
  { static bool warned512=false;
    if(!warned512 && g_heap>=0x20000000u){ warned512=true;
      std::fprintf(stderr,"\n[heap] *** WARNING: guest heap crossed 0x20000000 (512MB physical) -- "
        "&0x1FFFFFFF masks now ALIAS onto low memory (see hi_pool_fill_re.md) ***\n\n"); } }
  // Heap high-water census: print each 16MB boundary crossing (post-fix this should plateau
  // once the attract reaches steady state).
  { static uint32_t hwMark=0; if((g_heap>>24)!=(hwMark>>24)){ hwMark=g_heap;
      double lMB=0,pMB=0; for(auto&kv:g_allocSz)lMB+=kv.second; for(auto&kv:g_freePool)pMB+=kv.first;
      std::fprintf(stderr,"[heap] high-water 0x%X (%.0fMB) live=%zu (%.0fMB) pooled=%zu (%.0fMB)\n",
        g_heap,g_heap/(1024.0*1024.0),g_allocSz.size(),lMB/(1024.0*1024.0),g_freePool.size(),pMB/(1024.0*1024.0)); } }
  return p; }
// Legacy zeroed entry (internal host callers + NtVA commit path) and the HW-true raw entry
// for the Mm physical path — see the HARDWARE-TRUE ZEROING block above rt_takeCarved.
extern "C" uint32_t rt_alloc(uint32_t size,uint32_t align){ return rt_alloc_impl(size,align,1); }
extern "C" uint32_t rt_alloc_raw(uint32_t size,uint32_t align){ return rt_alloc_impl(size,align,0); }
// Return an allocation to the pool. Safe no-op for addresses rt_alloc never handed out
// (reqbase-honored NtVA regions, interior pointers, double frees). SIZE-GATED (2026-07-20
// hookcheck regression): pooling SMALL frees blanked the select-screen renderer — the shell
// frees small boot-era Mm blocks it still references (harmless on real HW where freed physical
// memory keeps its contents until reuse); recycling+zeroing them clobbered live render data.
// Only multi-MB blocks (the guest allocator's 8/16MB per-attract-cycle arena churn — the
// actual leak class) are recycled; small frees stay leaked-but-bounded as before.
extern "C" void rt_free_ex(uint32_t addr,uint64_t callerLr){ if(!addr) return;
  static int poolOn=[](){ const char* e=getenv("RT_FREEPOOL"); return e?atoi(e):1; }();
  if(!poolOn) return;                                // RT_FREEPOOL=0: registry-only, no recycling (bisect lever)
  std::lock_guard<std::mutex> lk(g_heap_mu);
  auto it=g_allocSz.find(addr); if(it==g_allocSz.end()) return;
  // KERNEL-LR small-block recycling (2026-07-20 attribution v2): the eternal grower is a
  // kernel-module site (alloc lr=0x8808372C, ~68KB x 16/s forever). Small-block recycling in
  // general is POISON (shell keeps >10s-persistent references into small freed boot blocks —
  // both the 4KB-floor and quarantine-only experiments blanked the select renderer), but
  // kernel-owned buffers are freed BY KERNEL CODE with a proper lifecycle. Discriminate by
  // the FREEING call site: frees from kernel-module addresses (lr>=0x88000000) bypass the
  // size floor; shell/game frees (0x82xxxxxx) keep it.
  bool kernelFree = callerLr>=0x88000000ull && callerLr<0x90000000ull;
  if(kernelFree) goto pool_ok;
  // Floor env-tunable (2026-07-20 attribution v2): the eternal grower is a KERNEL-module site
  // (lr=0x8808372C) Mm-allocating ~68KB blocks ~16/s forever — below the old fixed 1MB floor,
  // so its frees were never recycled. The 1MB floor predates the quarantine (the select
  // breakage was IMMEDIATE-reuse; gate and quarantine were never tested independently) —
  // RT_FREEPOOL_MIN lets the floor drop with the quarantine still protecting deferred readers.
  // 2026-08-04 containment part 4 + HW-true: the 1MB floor swallowed the shell streamer's
  // 0.2-0.3MB frees (alloc lr=0x82089F34, 489MB cumulative) — each stayed registered "live"
  // forever, a ~20MB/swap leak staircase (471MB live, frontier 672MB in swapbounce P7). The
  // floor only ever existed to keep zero-on-reuse away from stale-referenced blocks; with raw
  // reuse (kernel never zeroes — decomp verdict) the kernel-true floor is NONE: every tracked
  // free recycles, exactly like hardware. RT_FREEPOOL_MIN=0x100000 reverts to the beta1 floor.
  { static uint32_t poolMin=[](){ const char* e=getenv("RT_FREEPOOL_MIN"); return e?(uint32_t)strtoul(e,nullptr,0):0u; }();
    if(poolMin && it->second < poolMin) return; }
pool_ok:
  { static long fN=0; static double fMB=0.0; fMB+=it->second/(1024.0*1024.0);
    if((++fN%500)==0) std::fprintf(stderr,"[pool] freed n=%ld cum=%.0fMB pooled=%zu\n",fN,fMB,g_freePool.size()+1); }
  { uint32_t sz=it->second; rt_epochBump(addr,sz); g_allocSz.erase(it); rt_poolInsertCoalesced(addr,sz,rt_nowms()); } }
extern "C" void rt_free(uint32_t addr){ rt_free_ex(addr,0); }
// --- NtVA DECOMMIT handling (2026-07-20 soak6: the attract leak's REAL class) ---
// The guest allocator's 8/16MB arena segments are freed via NtFreeVirtualMemory DECOMMIT
// (0x4000), not RELEASE — the [free] census showed only 0x4000 while RSS kept its
// ~75MB/cycle staircase (soak6: 7700+ live registrations, pool nearly idle). Register-true
// handling: after a quarantine (same deferred-host-reader hazard as the pool — 10s default,
// RT_DECOMMIT_QUAR_MS), VirtualFree(MEM_DECOMMIT) the page-aligned interior so the HOST
// pages are returned (RSS actually drops); a later guest re-commit (NtVA with a requested
// base) re-commits via rt_recommit and cancels any pending overlapping quarantine entry.
// Guest touches of decommitted pages fault loudly (VEH exit 42) — same as real HW.
// RT_DECOMMIT=0 disables the whole path.
struct DecomEnt { uint32_t addr, size; uint64_t t; };
static std::vector<DecomEnt> g_decomQ;
// DEFAULT OFF (2026-07-20 final): every decommit variant (raw MEM_DECOMMIT, registry-gated,
// MEM_RESET+trim) broke a render shape — soak7/8 crashed on late host reads of removed pages,
// and reset+trim blanked the select screen (RESET pages the OS dropped read back as zeros
// under live references the guest legitimately keeps on real HW). The NtVA-arena leak class
// needs the guest allocator's segment-release path decompiled + an UnleashedRecomp-style real
// heap (o1heap) — not page tricks under deferred readers. Lever kept for that future leg.
static bool rt_decommit_on(){ static int v=[](){ const char* e=getenv("RT_DECOMMIT"); return e?atoi(e):0; }(); return v!=0; }
static void rt_decomSweep(uint64_t now){   // caller holds g_heap_mu
  static uint32_t quar=[](){ const char* e=getenv("RT_DECOMMIT_QUAR_MS"); return e?(uint32_t)atoi(e):10000u; }();
  size_t w=0;
  for(size_t i=0;i<g_decomQ.size();++i){ DecomEnt e=g_decomQ[i];
    if(!e.size) continue;
    if(now-e.t>=quar){
#ifdef _WIN32
      // MEM_RESET + VirtualUnlock instead of MEM_DECOMMIT (soak7/8 crashed at guest reads of
      // decommitted pages — OUR deferred readers (texture decode/reval, stale PM4 shadow state)
      // re-read guest bases arbitrarily late, something a real GPU never does, so page REMOVAL
      // is unsafe at any quarantine length. MEM_RESET keeps the pages readable (contents become
      // discardable, reads can never fault) and VirtualUnlock trims them from the working set
      // immediately — RSS drops now, pages soft-fault back zero-cost on any later touch.
      uint32_t a=(e.addr+0xFFFu)&~0xFFFu, end=(e.addr+e.size)&~0xFFFu;
      if(end>a && g_base){ VirtualAlloc(g_base+a,end-a,MEM_RESET,PAGE_READWRITE); VirtualUnlock(g_base+a,end-a);
        static long dn=0; static double dMB=0.0; dMB+=(end-a)/(1024.0*1024.0);
        if((++dn%16)==1) std::fprintf(stderr,"[decommit] reset+trim #%ld 0x%X..0x%X cum=%.0fMB\n",dn,a,end,dMB); }
#endif
    } else g_decomQ[w++]=e;
  }
  g_decomQ.resize(w);
}
extern "C" void rt_decommit_note(uint32_t addr,uint32_t size){
  if(!addr||!rt_decommit_on()) return;
  std::lock_guard<std::mutex> lk(g_heap_mu);
  // Honor ONLY ranges fully inside a REGISTERED live rt_alloc block (the guest allocator's
  // bump-granted 8/16MB arena segments — the leak class). The guest also decommits subranges
  // of its own reqbase-committed layout (0x370000.. boot era) which OVERLAPS our bump arena
  // in the flat world — decommitting those nuked innocent bump allocations (soak7 crash at
  // guest 0x020BB000, exit 42). Unregistered ranges are ignored (no-op, as before).
  auto it=g_allocSz.upper_bound(addr);
  if(it==g_allocSz.begin()) return;
  --it;   // greatest registered base <= addr
  if(!size){ if(it->first!=addr) return; size=it->second; }
  if(addr < it->first || (uint64_t)addr+size > (uint64_t)it->first+it->second) return;
  g_decomQ.push_back(DecomEnt{addr,size,rt_nowms()});
}
extern "C" void rt_recommit(uint32_t addr,uint32_t size){
  if(!addr||!size||!rt_decommit_on()) return;
  std::lock_guard<std::mutex> lk(g_heap_mu);
  for(auto& e:g_decomQ) if(e.size && addr<e.addr+e.size && e.addr<addr+size) e.size=0;   // cancel pending
#ifdef _WIN32
  if(g_base){ uint32_t a=addr&~0xFFFu, end=(addr+size+0xFFFu)&~0xFFFu;
    VirtualAlloc(g_base+a,end-a,MEM_COMMIT,PAGE_READWRITE); }   // idempotent; committed pages arrive zeroed
#endif
}
static int g_samples_left=0;
#ifdef _WIN32
// ---- RT_WATCHTEX guard-page write-watch probe (2026-07-22): catch the CPU writer of a guest
// texture page (char-select art page 0x12634000 / sibling 0x126ED000 — filled once at Character
// Select entry by recompiled loader code). RT_WATCHTEX=<hex>[,<hex>...] arms a PAGE_GUARD over
// g_base+addr for 0x20000 bytes per listed guest address (cap 4). onsig_veh below intercepts the
// resulting STATUS_GUARD_PAGE_VIOLATION: on a WRITE it logs the host RIP + a backtrace
// (rate-limited) so the store can be symbolicated to a guest function (exe+0x offsets, and via a
// /MAP relink like merged_xex.cpp's divide-by-zero path); reads re-arm silently (the renderer
// samples the page every frame). RE-ARM PATTERN: PAGE_GUARD auto-clears on fire and the faulting
// instruction re-executes on CONTINUE_EXECUTION, so re-arming immediately would fault forever.
// Instead we let the instruction complete with the trap flag set and re-arm the guard in the
// ensuing STATUS_SINGLE_STEP — the only correct continuous-watch pattern.
#ifndef STATUS_GUARD_PAGE_VIOLATION
#define STATUS_GUARD_PAGE_VIOLATION ((DWORD)0x80000001L)
#endif
#ifndef STATUS_SINGLE_STEP
#define STATUS_SINGLE_STEP ((DWORD)0x80000004L)
#endif
static constexpr uint32_t RT_WATCH_SPAN=0x20000;
struct WatchEnt { uint32_t base; uint32_t span; long writes; };
static WatchEnt g_watch[4]; static int g_watchN=0;
static thread_local uint32_t g_watch_rearm=0;   // 0 = none pending; else watched base to re-guard on the next single-step
static uintptr_t g_exeBase=0;                    // GetModuleHandle(nullptr) — for exe+0x symbolication anchors
// Arm the guard pages listed in RT_WATCHTEX. Call once after g_base is committed.
static void rt_watchtex_arm(){
  const char* e=std::getenv("RT_WATCHTEX"); if(!e||!*e||!g_base) return;
  g_exeBase=(uintptr_t)GetModuleHandle(nullptr);
  char buf[128]; std::snprintf(buf,sizeof buf,"%s",e);
  for(char* p=std::strtok(buf,","); p && g_watchN<4; p=std::strtok(nullptr,",")){
    uint32_t a=(uint32_t)strtoul(p,nullptr,16); if(!a) continue;
    DWORD old=0;
    if(VirtualProtect(g_base+a,RT_WATCH_SPAN,PAGE_READWRITE|PAGE_GUARD,&old)){
      g_watch[g_watchN++]=WatchEnt{a,RT_WATCH_SPAN,0};
      std::fprintf(stderr,"[watchtex] armed guest=0x%08X..0x%08X (host %p) exeBase=%p\n",
        a,a+RT_WATCH_SPAN,(void*)(g_base+a),(void*)g_exeBase);
    } else std::fprintf(stderr,"[watchtex] VirtualProtect(guest=0x%08X) failed: %lu\n",a,(unsigned long)GetLastError());
  }
}
// Dynamic arm for heap addresses discovered at runtime (2026-07-23 mode-record flags hunt):
// page-aligned span so a small record can be watched without the 128KB env-span heap noise.
// Callable from merged_xex probes (extern "C"). Dedupes by base page; cap shared with env arms.
extern "C" void rt_watch_arm_dyn(uint32_t guestAddr, uint32_t len){
  if(!g_base || g_watchN>=4 || !guestAddr) return;
  if(!g_exeBase) g_exeBase=(uintptr_t)GetModuleHandle(nullptr);
  uint32_t base=guestAddr & ~0xFFFu;
  uint32_t span=((guestAddr+len+0xFFFu)&~0xFFFu)-base;
  for(int i=0;i<g_watchN;i++) if(g_watch[i].base==base) return;   // already armed
  DWORD old=0;
  if(VirtualProtect(g_base+base,span,PAGE_READWRITE|PAGE_GUARD,&old)){
    g_watch[g_watchN++]=WatchEnt{base,span,0};
    std::fprintf(stderr,"[watchtex] DYN armed guest=0x%08X..0x%08X (target 0x%08X len 0x%X)\n",
      base,base+span,guestAddr,len);
  } else std::fprintf(stderr,"[watchtex] DYN VirtualProtect(0x%08X) failed: %lu\n",base,(unsigned long)GetLastError());
}
// Vectored exception handler replacing the POSIX sigaction crash handler: log the
// faulting guest address + a raw stack backtrace, then exit (mirrors onsig()).
static LONG WINAPI onsig_veh(EXCEPTION_POINTERS* ep){
  DWORD code=ep->ExceptionRecord->ExceptionCode;
  // ---- RT_WATCHTEX guard-page write-watch (see rt_watchtex_arm above). Runs BEFORE the crash
  // handling below so a watched guard fault is a continue, not an exit.
  if(g_watchN>0){
    if(code==STATUS_GUARD_PAGE_VIOLATION){
      ULONG_PTR acc=ep->ExceptionRecord->ExceptionInformation[0];                 // 0=read 1=write 8=execute
      long long off=(long long)((uint8_t*)ep->ExceptionRecord->ExceptionInformation[1]-g_base);
      int hit=-1;
      if(off>=0 && off<(long long)0x100000000LL)
        for(int i=0;i<g_watchN;i++)
          if((uint32_t)off>=g_watch[i].base && (uint32_t)off<g_watch[i].base+g_watch[i].span){ hit=i; break; }
      if(hit<0) return EXCEPTION_CONTINUE_SEARCH;   // guard fault outside our ranges (e.g. thread-stack growth) — not ours
      if(acc==1){   // WRITE — the writer we are hunting
        long w=g_watch[hit].writes++;
        bool full=(w<64);                            // full WRITE line for the first 64 writes/page, then just count
        bool bt  =(w<8)||((w&4095)==0);              // backtrace on the first 8, then every 4096th (~2 per full-page
                                                     // fill) so EVERY fill episode gets sampled, incl. select entry
        if(full||bt){
          void* rip=(void*)ep->ContextRecord->Rip;
          std::fprintf(stderr,"[watchtex] WRITE guest=0x%08X host_rip=%p",(uint32_t)off,rip);
          if((uintptr_t)rip>=g_exeBase) std::fprintf(stderr," exe+0x%zX",(size_t)((uintptr_t)rip-g_exeBase));
          std::fprintf(stderr," (#%ld page=0x%08X)\n",w,g_watch[hit].base);
          if(bt){
            void* frames[16]; USHORT nf=RtlCaptureStackBackTrace(0,16,frames,nullptr);
            for(USHORT i=0;i<nf;i++){ uintptr_t f=(uintptr_t)frames[i];
              if(f>=g_exeBase) std::fprintf(stderr,"    #%u %p exe+0x%zX\n",i,frames[i],(size_t)(f-g_exeBase));
              else             std::fprintf(stderr,"    #%u %p\n",i,frames[i]); }
          }
          std::fflush(stderr);
        } else if((w&1023)==0){                      // past the full window: a summary line every 1024 writes
          std::fprintf(stderr,"[watchtex] page=0x%08X writes=%ld (summary)\n",g_watch[hit].base,w);
        }
      }
      // READ or WRITE: PAGE_GUARD has already auto-cleared. Let the faulting instruction complete,
      // then re-arm in the ensuing single-step (trap flag). Re-arming here would fault forever.
      g_watch_rearm=g_watch[hit].base;
      ep->ContextRecord->EFlags |= 0x100u;           // TF — single-step trap after this instruction retires
      return EXCEPTION_CONTINUE_EXECUTION;
    }
    if(code==STATUS_SINGLE_STEP && g_watch_rearm){
      uint32_t b=g_watch_rearm; g_watch_rearm=0;
      uint32_t sp=RT_WATCH_SPAN;
      for(int i=0;i<g_watchN;i++) if(g_watch[i].base==b){ sp=g_watch[i].span; break; }
      DWORD old=0; VirtualProtect(g_base+b,sp,PAGE_READWRITE|PAGE_GUARD,&old);
      ep->ContextRecord->EFlags &= ~0x100u;          // clear TF; guard is live again for the next touch
      return EXCEPTION_CONTINUE_EXECUTION;
    }
  }
  if(code!=EXCEPTION_ACCESS_VIOLATION && code!=EXCEPTION_IN_PAGE_ERROR &&
     code!=EXCEPTION_ILLEGAL_INSTRUCTION && code!=EXCEPTION_PRIV_INSTRUCTION &&
     code!=EXCEPTION_INT_DIVIDE_BY_ZERO && code!=EXCEPTION_FLT_DIVIDE_BY_ZERO &&
     code!=EXCEPTION_FLT_INVALID_OPERATION)
    return EXCEPTION_CONTINUE_SEARCH;
  void* a=(code==EXCEPTION_ACCESS_VIOLATION||code==EXCEPTION_IN_PAGE_ERROR)
    ? (void*)ep->ExceptionRecord->ExceptionInformation[1]
    : (void*)ep->ExceptionRecord->ExceptionAddress;
  long long off=(uint8_t*)a-g_base;
  std::fprintf(stderr,"\n[SIGNAL 0x%lX] fault at %p",(unsigned long)code,a);
  if(off>=0 && off<(long long)0x100000000LL) std::fprintf(stderr," = guest 0x%08lX",(unsigned long)off);
  std::fprintf(stderr,"; imports called=%ld\n",g_import_calls.load());
  void* bt[48]; USHORT nn=RtlCaptureStackBackTrace(0,48,bt,nullptr);
  for(USHORT i=0;i<nn;i++) std::fprintf(stderr,"  #%u %p\n",i,bt[i]);
  std::fflush(stderr);
  _exit(42);
  return EXCEPTION_CONTINUE_SEARCH;
}
#else
static void onsig(int s, siginfo_t* si, void*){
  void* a=si->si_addr; long off=(uint8_t*)a-g_base;
  std::fprintf(stderr,"\n[SIGNAL %d] fault at %p",s,a);
  if(off>=0 && off<(long)0x100000000LL) std::fprintf(stderr," = guest 0x%08lX",(unsigned long)off);
  std::fprintf(stderr,"; imports called=%ld\n",g_import_calls.load());
  void* bt[48]; int nn=backtrace(bt,48); backtrace_symbols_fd(bt,nn,2);
  if(s==SIGALRM && --g_samples_left>0){ alarm(4); return; }  // hang sampling, not a fault
  _exit(42);
}
#endif
// ---- GameEntry driver (RT_DRIVE=1): we play the shell side of the msg protocol.
// msg-9 hands the game 4 callback fn ptrs; we point them at fake guest addrs inside the
// export-table data region (0x8824EEA0.., provably not code) whose lookup slots we bind
// to these host stubs, so every game->shell service call logs itself.
static long g_cb_calls[4];
static void rt_cb_dump(uint8_t* base, uint32_t a, const char* tag){
  std::fprintf(stderr,"[drive]   %s dump @0x%08X:",tag,a);
  for(int i=0;i<16;i++) std::fprintf(stderr," %08X",__builtin_bswap32(*(uint32_t*)(base+a+4*i)));
  std::fprintf(stderr,"\n");
}
#define RT_SVC_CB(n) PPC_FUNC(rt_svc_cb##n){ if(g_cb_calls[n]++<20){ \
  std::fprintf(stderr,"[drive]   svc_cb%d(r3=0x%llX r4=0x%llX r5=0x%llX r6=0x%llX)\n",n, \
    (unsigned long long)ctx.r3.u64,(unsigned long long)ctx.r4.u64,(unsigned long long)ctx.r5.u64,(unsigned long long)ctx.r6.u64); \
  uint32_t a4=ctx.r4.u32; if(g_cb_calls[n]<=2 && a4>=0x88000000u && a4<0x887B0000u) rt_cb_dump(base,a4,"r4"); } \
  { static long v=-1; if(v<0){ char nm[16]; std::snprintf(nm,16,"RT_CB%d_RET",n); const char* e=getenv(nm); v=e?atol(e):0; } ctx.r3.u64=(uint64_t)v; } }
RT_SVC_CB(0) RT_SVC_CB(1) RT_SVC_CB(2) RT_SVC_CB(3)

int main(int argc,char**argv){
#ifdef _WIN32
  AddVectoredExceptionHandler(1, onsig_veh);
#else
  struct sigaction sa; std::memset(&sa,0,sizeof sa); sa.sa_sigaction=onsig; sa.sa_flags=SA_SIGINFO;
  sigaction(SIGSEGV,&sa,0); sigaction(SIGBUS,&sa,0); sigaction(SIGILL,&sa,0); sigaction(SIGFPE,&sa,0); sigaction(SIGALRM,&sa,0);
#endif
  uint64_t target=argc>1?strtoull(argv[1],0,16):0x88070588ull;
  long reason=argc>2?strtol(argv[2],0,0):1;
  const char* xexpath=argc>3?argv[3]:nullptr;
#ifdef _WIN32
  uint8_t* base=xr_guest_arena(0x100000000ull);
  if(!base){std::fprintf(stderr,"VirtualAlloc 4GB failed: %lu\n",(unsigned long)GetLastError());return 1;} g_base=base;
#else
  uint8_t* base=(uint8_t*)mmap(nullptr,0x100000000ull,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS|MAP_NORESERVE,-1,0);
  if(base==MAP_FAILED){std::perror("mmap");return 1;} g_base=base;
#endif
  std::fprintf(stderr,"[harness] base=%p\n",(void*)base);
#ifdef _WIN32
  rt_watchtex_arm();   // RT_WATCHTEX=<hex>[,...] — guard-page write-watch probe (see onsig_veh)
#endif
  if(xexpath){ auto f=LoadFile(xexpath); Image img=Image::ParseImage(f.data(),f.size()); long sc=0; unsigned long long by=0;
    for(const auto& sN: img.sections){ uint64_t b=(uint64_t)sN.base,z=(uint64_t)sN.size;
      std::fprintf(stderr,"  sec base=0x%llX size=0x%llX data=%p\n",(unsigned long long)b,(unsigned long long)z,(const void*)sN.data);
      if(!sN.data||z==0) continue;
      if(b<0x88000000ull||b+z>0x887B0000ull){ std::fprintf(stderr,"   (skip oob)\n"); continue; }
      std::memcpy(base+b,(const void*)sN.data,z); ++sc; by+=z; }
    std::fprintf(stderr,"[harness] XEX: %ld sections %llu bytes\n",sc,by);
    // xex2 export table (ordinal exports): guest addr lives in the (unencrypted)
    // security info at secoff+0x160; the table itself is in the decrypted image.
    // Layout (rexglue xex2_info.h): +0x20 imagebase(<<16), +0x24 count, +0x28 base, +0x2C ordOffset[]
    { const uint8_t* x=f.data();
      uint32_t secoff=__builtin_bswap32(*(const uint32_t*)(x+0x10));
      uint32_t exptab=__builtin_bswap32(*(const uint32_t*)(x+secoff+0x160));
      if(exptab){
        uint32_t ib =__builtin_bswap32(*(uint32_t*)(base+exptab+0x20))<<16;
        uint32_t cnt=__builtin_bswap32(*(uint32_t*)(base+exptab+0x24));
        uint32_t ob =__builtin_bswap32(*(uint32_t*)(base+exptab+0x28));
        std::fprintf(stderr,"[harness] export table @0x%08X imagebase=0x%08X count=%u ordbase=%u\n",exptab,ib,cnt,ob);
        for(uint32_t i=0;i<cnt&&i<64;i++){
          uint32_t off=__builtin_bswap32(*(uint32_t*)(base+exptab+0x2C+4*i));
          if(ob+i==1&&off) g_ord1=off+ib;
          std::fprintf(stderr,"  [export] ordinal %u -> 0x%08X\n",ob+i,off?off+ib:0);
        }
      } else std::fprintf(stderr,"[harness] no xex2 export table\n");
    } }
  // ---- futari_merged: load the SHELL module's XEX into the SAME 4GB guest space and
  // register its function-mapping table at its own (disjoint) flat lookup-table region.
  // Gated behind RT_SHELL=1 (or RT_BOOT_SHELL=1, which implies it -- Gate 1's whole point
  // is booting the shell, so it always needs the shell XEX/table loaded) so futari_mode
  // (no shell tree linked in) is unaffected, and so this standalone game binary doesn't
  // try to load a shell XEX that may not exist for it. Bounds/constants are the literal
  // shell values (shell/gen/ppc_config.h).
  if((getenv("RT_SHELL") || getenv("RT_BOOT_SHELL")) && PPCFuncMappings_shell){
    const char* shellxex=std::getenv("XR_SHELL_XEX")?std::getenv("XR_SHELL_XEX"):"shell/default.xex";
    auto f=LoadFile(shellxex); Image img=Image::ParseImage(f.data(),f.size());
    long sc=0; unsigned long long by=0;
    for(const auto& sN: img.sections){ uint64_t b=(uint64_t)sN.base,z=(uint64_t)sN.size;
      if(!sN.data||z==0) continue;
      if(b<0x82000000ull||b+z>0x822B0000ull){ std::fprintf(stderr,"  [shell] (skip oob) sec base=0x%llX size=0x%llX\n",(unsigned long long)b,(unsigned long long)z); continue; }
      std::memcpy(base+b,(const void*)sN.data,z); ++sc; by+=z; }
    std::fprintf(stderr,"[harness] SHELL XEX: %ld sections %llu bytes loaded into [0x82000000,0x822B0000)\n",sc,by);
    long ns=0; for(PPCFuncMapping* m=PPCFuncMappings_shell; m->guest||m->host; ++m){ if(!m->host)continue; uint32_t g=(uint32_t)m->guest;
      *(PPCFunc**)(base+0x822B0000ull+(uint64_t)(uint32_t)(g-0x82060000u)*2)=m->host; ++ns; }
    std::fprintf(stderr,"[harness] SHELL table: %ld funcs registered\n",ns);
    // Direct sanity self-test: look up sub_821CA5B8 (the game's msg-1 setup target) via
    // the SHELL-table formula and confirm the slot is populated -- proves the shell
    // function is registered/callable even if the natural indirect call path doesn't fire.
    { uint32_t probe=0x821CA5B8u;
      PPCFunc* pf=*(PPCFunc**)(base+0x822B0000ull+(uint64_t)(uint32_t)(probe-0x82060000u)*2);
      std::fprintf(stderr,"[harness] SHELL self-test: slot for 0x%08X = %p (%s)\n",probe,(void*)pf,pf?"REGISTERED":"NULL");
    }
  }
  // ---- GAME function table -----------------------------------------------------------------
  // L4/E5 of _tmpscripts/dll_packaging_plan.md.  In a COMBINED build the generated game tree —
  // and therefore PPCFuncMappings — is no longer in this image at all; it lives in a module DLL.
  // futari_registry_boot() loads and binds every module DLL, then activates the boot module,
  // which registers its slots through exactly this formula.  It is called HERE, at the same
  // point in main() the eager loop occupied, so the table is populated before the shell boots
  // and the boot order is bit-for-bit the per-module exes'.
#ifdef FUTARI_COMBINED
  if(futari_registry_boot(base)!=0){
    std::fprintf(stderr,"[harness] FATAL: no game module bound — cannot continue.\n");
    std::fflush(stderr); return 1;
  }
  long n = (long)futari_desc()->mapping_count;
#else
  long n=0; for(PPCFuncMapping* m=PPCFuncMappings; m->guest||m->host; ++m){ if(!m->host)continue; uint32_t g=(uint32_t)m->guest;
    *(PPCFunc**)(base+PPC_IMAGE_BASE+PPC_IMAGE_SIZE+(uint64_t)(uint32_t)(g-PPC_CODE_BASE)*2)=m->host; ++n; }
#endif
  const uint32_t PCR=0xAB0,TLS=0x100,TEB=0x2E0,STK=0x40000,TOT=PCR+TLS+TEB+STK;
  uint32_t tb=rt_alloc(TOT,0x1000); uint8_t* t=base+tb; std::memset(t,0,TOT);
  *(uint32_t*)t=__builtin_bswap32(tb+PCR); *(uint32_t*)(t+0x100)=__builtin_bswap32(tb+PCR+TLS); t[0x10C]=0;
  *(uint32_t*)(t+PCR+0x10)=0xFFFFFFFF; *(uint32_t*)(t+PCR+TLS+0x14C)=__builtin_bswap32(1);
  PPCContext ctx{}; ctx.r1.u64=tb+PCR+TLS+TEB+STK; ctx.r13.u64=tb; ctx.fpscr.loadFromHost();

  // ---- GATE 1: RT_BOOT_SHELL=1 -- boot the SHELL (not the game) to its live idle-menu
  // steady state, using the SAME unified kernel layer + BOTH XEXs/tables already loaded
  // above. Mirrors shell/gen/harness.cpp's boot convention EXACTLY: the shell's entry
  // (0x8208A2B8) is a plain _xstart-style entry, NOT the game's DllMainCRTStartup -- it
  // takes ctx.r3=reason only (no hinst/reserved in r3/r4/r5 like the game's DllMain ABI
  // set below). The game module stays loaded+registered (co-resident, inert) but is never
  // driven in this mode. Lookup uses the SHELL table region formula (same one
  // rt_indirect_call/harness's RT_SHELL self-test use), NOT the game's PPC_CODE_BASE macros
  // (which resolve to the GAME's bounds in this TU).
  if(getenv("RT_BOOT_SHELL")){
    if(!PPCFuncMappings_shell){
      std::fprintf(stderr,"[boot-shell] no shell function table linked in this binary\n");
      return 1;
    }
    ctx.r3.u64=(uint64_t)reason;   // shell harness convention: r3=reason only
    uint32_t shellTarget=(uint32_t)target;
    PPCFunc* sfn=nullptr;
    if(shellTarget>=0x82060000u && shellTarget<0x82060000u+0x175BF4u)
      sfn=*(PPCFunc**)(base+0x822B0000ull+(uint64_t)(shellTarget-0x82060000u)*2);
    std::fprintf(stderr,"[boot-shell] r13=0x%X r1=0x%llX; call SHELL 0x%X reason=%ld (shell table lookup -> %p)\n",
      tb,(unsigned long long)ctx.r1.u64,shellTarget,reason,(void*)sfn);
    if(!sfn){ std::fprintf(stderr,"[boot-shell] no host fn for shell entry 0x%X\n",shellTarget); return 1; }
    // The shell boot runs its live vblank/menu loop FOREVER (by design, per the shell's
    // known-good standalone behavior) -- arm the SIGALRM hang-sampler exactly as shell/gen
    // harness.cpp does (alarm(6) before the call) so RT_SAMPLES watchdog fires and we get a
    // backtrace + clean _exit(42) instead of hanging forever.
    { const char* se=getenv("RT_SAMPLES"); g_samples_left=se?atoi(se):5; }
    alarm(6);
    sfn(ctx,base);
    std::fprintf(stderr,"\n[boot-shell] RETURNED. imports=%ld r3=0x%llx\n",g_import_calls.load(),(unsigned long long)ctx.r3.u64);
    return 0;
  }

  ctx.r3.u64=0x88000000; ctx.r4.u64=(uint64_t)reason; ctx.r5.u64=0;
  PPCFunc* fn=*(PPCFunc**)(base+PPC_IMAGE_BASE+PPC_IMAGE_SIZE+(uint64_t)(uint32_t)((uint32_t)target-PPC_CODE_BASE)*2);
  std::fprintf(stderr,"[harness] %ld funcs; r13=0x%X r1=0x%llX heap_next=0x%X; call 0x%llX reason=%ld\n\n",n,tb,(unsigned long long)ctx.r1.u64,g_heap,(unsigned long long)target,reason);
  if(!fn){std::fprintf(stderr,"no fn\n");return 1;}
  fn(ctx,base);
  std::fprintf(stderr,"\n[harness] RETURNED cleanly. imports=%ld r3=0x%llx\n",g_import_calls.load(),(unsigned long long)ctx.r3.u64);
  if(reason==1 && ctx.r3.u64==1 && getenv("RT_DRIVE") && g_ord1){
    auto wr32=[&](uint32_t a,uint32_t v){ *(uint32_t*)(base+a)=__builtin_bswap32(v); };
    auto rd32=[&](uint32_t a){ return __builtin_bswap32(*(uint32_t*)(base+a)); };
    PPCFunc* ge=*(PPCFunc**)(base+PPC_IMAGE_BASE+PPC_IMAGE_SIZE+(uint64_t)(uint32_t)(g_ord1-PPC_CODE_BASE)*2);
    if(!ge){ std::fprintf(stderr,"[drive] no host fn for GameEntry 0x%X\n",g_ord1); return 1; }
    static const uint32_t CBADDR[4]={0x8824EEA0,0x8824EEA4,0x8824EEA8,0x8824EEAC};
    PPCFunc* cbs[4]={rt_svc_cb0,rt_svc_cb1,rt_svc_cb2,rt_svc_cb3};
    for(int i=0;i<4;i++) *(PPCFunc**)(base+PPC_IMAGE_BASE+PPC_IMAGE_SIZE+(uint64_t)(uint32_t)(CBADDR[i]-PPC_CODE_BASE)*2)=cbs[i];
    auto call=[&](uint32_t msg,uint32_t arg){
      ctx.r3.u64=msg; ctx.r4.u64=arg; ge(ctx,base);
      std::fprintf(stderr,"[drive] GameEntry(msg=%u,arg=0x%X) -> r3=0x%llX (imports=%ld)\n",msg,arg,(unsigned long long)ctx.r3.u64,g_import_calls.load());
    };
    std::fprintf(stderr,"\n[drive] driving GameEntry @0x%X (shell init msg sequence)\n",g_ord1);
    uint32_t b67=rt_alloc(16,8); wr32(b67,0); wr32(b67+4,0);
    call(6,b67);   uint32_t p6=rd32(b67);   std::fprintf(stderr,"[drive] msg6 out-ptr=0x%X\n",p6);
    call(7,b67+4); uint32_t p7=rd32(b67+4); std::fprintf(stderr,"[drive] msg7 out-ptr=0x%X\n",p7);
    if(p6) wr32(p6,0);
    if(p7) wr32(p7,0);
    uint32_t blk=rt_alloc(304,16);
    uint32_t m1=rt_alloc(28,8);
    wr32(m1+0,0); wr32(m1+4,0); wr32(m1+8,blk); wr32(m1+12,0);
    wr32(m1+16,0x821F80D0); wr32(m1+20,0); wr32(m1+24,0x821CA5B8);
    call(1,m1);
    uint32_t c164=rt_alloc(512,16); call(2,c164);
    uint32_t c180=rt_alloc(512,16); call(8,c180);
    uint32_t cbt=rt_alloc(32,8); uint32_t ctxv=rt_alloc(512,16);
    for(int i=0;i<4;i++){ wr32(cbt+8*i,CBADDR[i]); wr32(cbt+8*i+4,ctxv); }
    call(9,cbt);
    std::fprintf(stderr,"[drive] init sequence complete. imports=%ld cb_calls=%ld/%ld/%ld/%ld\n",
      g_import_calls.load(),g_cb_calls[0],g_cb_calls[1],g_cb_calls[2],g_cb_calls[3]);
    if(getenv("RT_THREADS")){
      // real-thread mode: game threads run themselves (started in msg2). Park the main
      // thread and let them work; SIGALRM sampler still fires for visibility.
      int secs=getenv("RT_RUN_SECS")?atoi(getenv("RT_RUN_SECS")):15;
      const char* se=getenv("RT_SAMPLES"); g_samples_left=se?atoi(se):2;
      std::fprintf(stderr,"\n[drive] RT_THREADS park: letting game threads run %ds\n",secs);
      alarm(6);
      for(int i=0;i<secs*10;i++) usleep(100000);
      std::fprintf(stderr,"[drive] park done. imports=%ld cb=%ld/%ld/%ld/%ld\n",
        g_import_calls.load(),g_cb_calls[0],g_cb_calls[1],g_cb_calls[2],g_cb_calls[3]);
      return 0;
    }
    if(getenv("RT_RUNTHREAD") && g_thread_entry){
      // x360 XAPI thread convention: thread begins at xapi thunk with r3=entry, r4=ctx;
      // without a thunk it begins at entry with r3=ctx. Run inline; SIGALRM samples hangs.
      uint32_t start = g_thread_xapi ? g_thread_xapi : g_thread_entry;
      PPCFunc* tf=*(PPCFunc**)(base+PPC_IMAGE_BASE+PPC_IMAGE_SIZE+(uint64_t)(uint32_t)(start-PPC_CODE_BASE)*2);
      if(!tf){ std::fprintf(stderr,"[drive] no host fn for thread start 0x%X\n",start); return 1; }
      if(g_thread_xapi){ ctx.r3.u64=g_thread_entry; ctx.r4.u64=g_thread_ctx; }
      else             { ctx.r3.u64=g_thread_ctx; }
      const char* se=getenv("RT_SAMPLES"); g_samples_left=se?atoi(se):3;
      std::fprintf(stderr,"\n[drive] running game thread inline: start=0x%X entry=0x%X ctx=0x%X (samples=%d)\n",
        start,g_thread_entry,g_thread_ctx,g_samples_left);
      alarm(6);
      tf(ctx,base);
      alarm(0);
      std::fprintf(stderr,"[drive] game thread RETURNED r3=0x%llX imports=%ld cb=%ld/%ld/%ld/%ld\n",
        (unsigned long long)ctx.r3.u64,g_import_calls.load(),g_cb_calls[0],g_cb_calls[1],g_cb_calls[2],g_cb_calls[3]);
    }
  }
  return 0;
}
