#include <set>
#ifndef _WIN32
#include <execinfo.h>
#endif
#include "ppc_recomp_shared.h"
#include <cstdio>
#include <atomic>
#include <cstdint>
#include <cstdlib>
#include <mutex>
#include <unordered_map>
// L3/E4 (dll_packaging_plan §3.4): the load-bearing guest .data addresses below are
// MODULE properties.  They migrate one at a time out of this -DGA_DSHIFT literal block
// into the descriptor, the single place a swapped module's layout is described.  A
// converted macro keeps its name, so no use site changes.
#include "../../host/futari_module_desc.h"
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
#define GA_DSHIFT 0u
#endif
// GA_FIELD_ACTIVE  gameplay-field-active flag: present routing / pillarbox / compose + clear gating (vk_render), romactive clear (stubs.cpp XexUnloadImage). No sibling field is referenced anywhere.
#define GA_FIELD_ACTIVE  (futari_desc()->addrs.field_active)   // L3: was (0x885C1A20u + GA_DSHIFT)
// GA_ASSET_COMMIT  asset-commit flag byte; RT_LOADDONE WRITES bit 0x02 here — a wrong-address write is the most dangerous class.
#define GA_ASSET_COMMIT  (futari_desc()->addrs.asset_commit)   // L3: was (0x887AC973u + GA_DSHIFT)
// GA_MB_RELOAD     RETURN-TO-MENU / reload mailbox; parsed out of [msglog] and rt.cpp handback logs by the boot gates.
#define GA_MB_RELOAD     (futari_desc()->addrs.mb_reload)   // L3: was (0x887AD58Cu + GA_DSHIFT)
// GA_MB_MODE64     mode64 mailbox; msg-12 arm target, read by [msglog] and rt.cpp.
#define GA_MB_MODE64     (futari_desc()->addrs.mb_mode64)   // L3: was (0x887AD584u + GA_DSHIFT)
// ---- end guest .data parameterization ----
extern std::atomic<long> g_import_calls;
extern "C" uint32_t rt_alloc(uint32_t size, uint32_t align);   // bump allocator (in harness)
extern "C" uint32_t rt_alloc_raw(uint32_t size, uint32_t align); // HW-true no-zero-on-reuse (Mm path)
extern "C" void rt_impcall(const char* n);
#define LOGN(n) do{static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] " n "\n");}g_import_calls++;rt_impcall(n);}while(0)
// --- memory ---
PPC_FUNC_IMPL(__imp__MmAllocatePhysicalMemoryEx){ LOGN("MmAllocatePhysicalMemoryEx"); uint32_t sz=ctx.r4.u32; ctx.r3.u32=rt_alloc_raw(sz?sz:0x1000,0x1000); (void)base; }
PPC_FUNC_IMPL(__imp__NtAllocateVirtualMemory){ LOGN("NtAllocateVirtualMemory");
  // 360 convention: r3=&BaseAddress (in/out), r4=&RegionSize (in/out), r5=AllocType, r6=Protect
  uint32_t baseptr=ctx.r3.u32, sizeptr=ctx.r4.u32;
  uint32_t reqbase = baseptr? __builtin_bswap32(*(uint32_t*)(base+baseptr)) : 0;
  uint32_t sz = sizeptr? __builtin_bswap32(*(uint32_t*)(base+sizeptr)) : 0x1000;
  if(!sz) sz=0x1000; sz=(sz+0xFFF)&~0xFFFu;
  uint32_t p = reqbase ? reqbase : rt_alloc(sz,0x10000); // whole 4GB is mapped RW: commit-in-place is a no-op
  if(baseptr) *(uint32_t*)(base+baseptr)=__builtin_bswap32(p);
  if(sizeptr) *(uint32_t*)(base+sizeptr)=__builtin_bswap32(sz);
  ctx.r3.u32=0; /* STATUS_SUCCESS */ }
// --- TLS ---
static uint32_t g_tls_next=1; static thread_local uint32_t g_tls[256];
PPC_FUNC_IMPL(__imp__KeTlsAlloc){ LOGN("KeTlsAlloc"); ctx.r3.u32=g_tls_next++; (void)base; }
PPC_FUNC_IMPL(__imp__KeTlsFree){ LOGN("KeTlsFree"); ctx.r3.u32=1; (void)base; }
PPC_FUNC_IMPL(__imp__KeTlsGetValue){ LOGN("KeTlsGetValue"); uint32_t i=ctx.r3.u32; ctx.r3.u32=(i<256)?g_tls[i]:0; (void)base; }
PPC_FUNC_IMPL(__imp__KeTlsSetValue){ LOGN("KeTlsSetValue"); uint32_t i=ctx.r3.u32; if(i<256)g_tls[i]=ctx.r4.u32; ctx.r3.u32=1; (void)base; }
// --- REAL critical sections (stub-audit HIGH; see out_reco/rt.cpp for the full rationale) ---
// This shell copy loses the merged link to the game rt.cpp copy (game objects link first), so it is
// effectively dead in futari_merged.exe — but ATLAS_threading_kernel.md flags RtlEnter/Leave as a
// no-op in BOTH rt.cpp copies, so both are fixed to keep them consistent and to stay correct if the
// standalone shell ever links without the game copy. Keyed guest-address -> recursive_mutex, lazy,
// process-lifetime. RT_NOLOCKS (opt-out) reverts to the historical no-op.
static bool sh_nolocks(){ static bool off=getenv("RT_NOLOCKS")!=nullptr; return off; }
static std::mutex g_sh_locktab_m;
static std::unordered_map<uint32_t,std::recursive_mutex*> g_sh_locktab;
static std::recursive_mutex* sh_lock_for(uint32_t key){
  std::lock_guard<std::mutex> l(g_sh_locktab_m);
  auto it=g_sh_locktab.find(key); if(it!=g_sh_locktab.end()) return it->second;
  std::recursive_mutex* m=new std::recursive_mutex(); g_sh_locktab[key]=m; return m;
}
PPC_FUNC_IMPL(__imp__RtlInitializeCriticalSection){ LOGN("RtlInitializeCriticalSection"); ctx.r3.u32=0; (void)base; }
PPC_FUNC_IMPL(__imp__RtlInitializeCriticalSectionAndSpinCount){ LOGN("RtlInitializeCriticalSectionAndSpinCount"); ctx.r3.u32=0; (void)base; }
PPC_FUNC_IMPL(__imp__RtlEnterCriticalSection){ LOGN("RtlEnterCriticalSection");
  if(!sh_nolocks() && ctx.r3.u32) sh_lock_for(ctx.r3.u32)->lock(); (void)base; }
PPC_FUNC_IMPL(__imp__RtlLeaveCriticalSection){ LOGN("RtlLeaveCriticalSection");
  if(!sh_nolocks() && ctx.r3.u32) sh_lock_for(ctx.r3.u32)->unlock(); (void)base; }
// --- misc ---
PPC_FUNC_IMPL(__imp__KeGetCurrentProcessType){ LOGN("KeGetCurrentProcessType"); ctx.r3.u32=1; (void)base; }
PPC_FUNC_IMPL(__imp__RtlInitAnsiString){ LOGN("RtlInitAnsiString");
  { static bool t=getenv("RT_TRACEIMP")!=nullptr; if(t&&ctx.r4.u32) std::fprintf(stderr,"    [ansi] %.300s%c",(const char*)(base+ctx.r4.u32),10); }
  uint32_t dst=ctx.r3.u32, src=ctx.r4.u32; uint16_t len=0; if(src){const char*s=(const char*)(base+src); while(s[len]&&len<0xFFFE)++len;}
  if(dst){ *(uint16_t*)(base+dst)=__builtin_bswap16(len); *(uint16_t*)(base+dst+2)=__builtin_bswap16(src?len+1:0); *(uint32_t*)(base+dst+4)=__builtin_bswap32(src);} (void)base; }
// --- game-loop status watcher: r31 global @0x821F85A0, loop obj @r31+152, status int @obj+8 ---
static uint32_t rt_be32(uint8_t* base,uint32_t a){ return __builtin_bswap32(*(uint32_t*)(base+a)); }
static void rt_wr32(uint8_t* base,uint32_t a,uint32_t v){ *(uint32_t*)(base+a)=__builtin_bswap32(v); }
// --- loopobj raw field / pointer-chase dumper (diagnostic) ---
static void rt_dump_mem(uint8_t* base,const char* tag,uint32_t p,int words){
  if(!p){ std::fprintf(stderr,"[tree]   %-10s = 0 (null)\n",tag); return; }
  std::fprintf(stderr,"[tree]   %-10s @0x%08X:",tag,p);
  for(int i=0;i<words*4;i+=4) std::fprintf(stderr," +%02X=%08X",i,rt_be32(base,p+i));
  std::fprintf(stderr,"\n");
}
static void rt_dump_tree(uint8_t* base,const char* when){
  uint32_t r31g=rt_be32(base,0x821F85A0); if(!r31g||r31g>=0x40000000u){ std::fprintf(stderr,"[tree] @%s no root (r31g=0x%08X)\n",when,r31g); return; }
  uint32_t lo=rt_be32(base,r31g+152); if(!lo){ std::fprintf(stderr,"[tree] @%s no loopobj\n",when); return; }
  std::fprintf(stderr,"[tree] ==== @%s r31g=0x%08X loopobj=0x%08X status(+8)=%u ====\n",when,r31g,lo,rt_be32(base,lo+8));
  rt_dump_mem(base,"loopobj",lo,20);           // 0x50 bytes of the gate object
  rt_dump_mem(base,"vptr[+0]",rt_be32(base,lo+0),16);   // what +0 points to (vtable? type?)
  rt_dump_mem(base,"p[+16]",rt_be32(base,lo+16),16);    // the 0x8204FA8C image ptr
  rt_dump_mem(base,"p[+60]",rt_be32(base,lo+60),16);    // *(r31+60) the loop dispatches on
  rt_dump_mem(base,"r31g",r31g,40);            // the global controller (0x821F85A0 target)
}
static void rt_watch(uint8_t* base,uint32_t site,const char* when){
  uint32_t r31g=rt_be32(base,0x821F85A0); if(!r31g||r31g>=0x40000000u) return;
  uint32_t obj=rt_be32(base,r31g+152); if(!obj||obj>=0x40000000u) return;
  uint32_t st=rt_be32(base,obj+8);
  static uint32_t lastObj=0, lastSt=0xDEADBEEF;
  if(obj!=lastObj||st!=lastSt){
    std::fprintf(stderr,"  [watch] loopobj=0x%08X status=%d (%s indirect 0x%08X)\n",obj,(int)st,when,site);
    lastObj=obj; lastSt=st; }
}
// --- CRT-heap diagnostics: strong overrides of the weak recompiled funcs ---
PPC_FUNC_IMPL(__imp__sub_8208F530); // _heap_init
PPC_FUNC(sub_8208F530){
  std::fprintf(stderr,"  [hook] _heap_init ENTER xexhdrptr=0x%08X%c",rt_be32(base,0x820404F0),10);
  __imp__sub_8208F530(ctx,base);
  std::fprintf(stderr,"  [hook] _heap_init EXIT r3=%u crtheap=0x%08X%c",(unsigned)ctx.r3.u32,rt_be32(base,0x821FA5DC),10);
}
PPC_FUNC_IMPL(__imp__sub_8208BE88); // heap create
PPC_FUNC(sub_8208BE88){
  std::fprintf(stderr,"  [hook] heap_create(r3=%u r4=%u size=%u r6=%u r7=%u)%c",(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,(unsigned)ctx.r5.u32,(unsigned)ctx.r6.u32,(unsigned)ctx.r7.u32,10);
  __imp__sub_8208BE88(ctx,base);
  std::fprintf(stderr,"  [hook] heap_create -> 0x%08X%c",(unsigned)ctx.r3.u32,10);
}
PPC_FUNC_IMPL(__imp__sub_820A7DF8); // graphics interrupt handler
PPC_FUNC(sub_820A7DF8){
  static std::atomic<int> n{0}; int k=n++;
  uint32_t src=ctx.r3.u32, pool=ctx.r4.u32;
  if(k<8||(k<200&&k%50==0)){
    uint32_t obj=rt_be32(base,pool+10900);
    uint32_t startp=rt_be32(base,pool+10896);
    std::fprintf(stderr,"  [gint] #%d src=%u pool=0x%08X obj10900=0x%08X obj16=0x%08X obj20=0x%08X rdcurptr=0x%08X rdcur=0x%X wrcur=0x%X wb=0x%X%c",
      k,src,pool,obj,obj?rt_be32(base,obj+16):0,obj?rt_be32(base,obj+20):0,
      startp,startp?rt_be32(base,startp):0,rt_be32(base,pool+10908),rt_be32(base,0x0069B03C),10);
  }
  __imp__sub_820A7DF8(ctx,base);
}
PPC_FUNC_IMPL(__imp__sub_820A8220); // pool walker
PPC_FUNC(sub_820A8220){
  static std::atomic<int> n{0}; int k=n++;
  uint32_t pool=ctx.r3.u32;
  if(k<40){
    uint32_t ptr=ctx.r4.u32;
    uint32_t startp=rt_be32(base,pool+10896), endv=rt_be32(base,pool+10908);
    uint32_t startv=startp?rt_be32(base,startp):0;
    std::fprintf(stderr,"  [walk] pool=0x%08X ptr=0x%08X r5=0x%X start=0x%08X end=0x%08X flag13408=0x%X%c",
      pool,ptr,(unsigned)ctx.r5.u32,startv,endv,rt_be32(base,pool+13408),10);
  }
  __imp__sub_820A8220(ctx,base);
  // RT_MARKERSPIN=1 restores the authentic wait (default: fast-retire). The per-frame present
  // path sub_8216B148 -> sub_820A9268 inserts a CP marker then busy-spins `do{} while
  // (dev+0x2B04 != 0)` until the CP interrupt retires it — which in this port only fires on the
  // 59.94Hz vblank thread's source-1 tick. That rounds EVERY shell frame up to the next vblank
  // boundary (body 18ms -> 33ms period -> ~30-35 loop iterations/s -> attract logic ~2x slow
  // even with the RT_VBISR gate fixed). Null-GPU semantics: submitted work retires instantly
  // (same doctrine as the sub_820A4590 RT_NODRAIN force), so clear the marker-pending flag at
  // kick time; the vsync gate (sub_8216AD38's 0x821F8560 counter) stays the sole 59.94Hz pacer.
  static bool markerspin = getenv("RT_MARKERSPIN")!=nullptr;
  if(!markerspin && rt_be32(base,pool+0x2B04)!=0){
    *(uint32_t*)(base+pool+0x2B04)=0;
    static std::atomic<int> mc{0}; int m=mc++;
    if(m<3) std::fprintf(stderr,"  [fastmarker] cleared dev+0x2B04 at kick #%d%c",m,10);
  }
}
PPC_FUNC_IMPL(__imp__sub_820A4590); // GPU-drain "still pending?" step; 1=keep waiting, 0=drained
PPC_FUNC(sub_820A4590){
  __imp__sub_820A4590(ctx,base);
  // Null-GPU model: all submitted work retires instantly -> always report drained.
  static bool force = getenv("RT_NODRAIN")==nullptr; // on by default; RT_NODRAIN=1 disables
  if(force) ctx.r3.u32=0;
}
// RT_LRBAND leg-35 run-4: sub_82164E68 / sub_82168E58 (the text + sprite emit methods above the
// generic draw) are NEVER called directly by the recompiled code -- they are virtual, reached only
// through rt_indirect -- which is why a PPC_FUNC override of them never fires. So the VIRTUAL call
// stack is recorded here instead: every indirect dispatch pushes (target, callerLR, r3=this) and
// the draw hook snapshots the innermost frames. This is the only walkable call stack in the port
// (the guest PPC back chain carries no usable LR save slots under XenonRecomp).
static const bool g_lb_on = getenv("RT_LRBAND")!=nullptr;  // hot path: no guarded-static check
struct LbFrm{ uint32_t t,lr,r3; };
static thread_local LbFrm g_lb_stk[64]; static thread_local int g_lb_sd=0;
extern "C" void rt_indirect(uint32_t t, PPCContext& ctx, uint8_t* base){
  static bool trace = getenv("RT_TRACE")!=nullptr;
  if(trace){ static std::atomic<int> tc{0}; int n=tc++; if(n<2000000) std::fprintf(stderr,"  [ind] 0x%08X\n",t); }
  if(t>=PPC_CODE_BASE && t<PPC_CODE_BASE+PPC_CODE_SIZE){
    PPCFunc* f=*(PPCFunc**)(base+PPC_IMAGE_BASE+PPC_IMAGE_SIZE+(uint64_t)(uint32_t)(t-PPC_CODE_BASE)*2);
    if(f){ rt_watch(base,t,"before");
      if(g_lb_on){
        if(g_lb_sd>=0 && g_lb_sd<64){ g_lb_stk[g_lb_sd].t=t; g_lb_stk[g_lb_sd].lr=(uint32_t)ctx.lr; g_lb_stk[g_lb_sd].r3=ctx.r3.u32; }
        g_lb_sd++; f(ctx,base); g_lb_sd--;
      } else f(ctx,base);
      rt_watch(base,t,"after"); return; }
  }
  static std::atomic<int> c{0}; if(c++<15) std::fprintf(stderr,"  [indirect unresolved 0x%08X]\n",t);
}
PPC_FUNC_IMPL(__imp__XGetVideoMode){ LOGN("XGetVideoMode");
  uint32_t p=ctx.r3.u32;
  if(p){ uint8_t* v=base+p; for(int i=0;i<0x50;i++) v[i]=0;
    auto W=[&](uint32_t o,uint32_t val){ *(uint32_t*)(v+o)=__builtin_bswap32(val); };
    W(0,1280);W(4,720);W(8,0);W(0xC,1);W(0x10,1);W(0x14,0x42700000);W(0x18,1); }
  ctx.r3.u32=0; (void)base; }
#include <thread>
#include <mutex>
#include <condition_variable>
#include <unordered_map>
#include <chrono>
#include <cstring>
#include <algorithm>
struct RtObj{ virtual ~RtObj(){} };
struct RtEvent:RtObj{ std::mutex m; std::condition_variable cv; bool sig=false, manual=false; };
struct RtThread:RtObj{ std::thread th; std::atomic<bool> done{false}, suspended{false}; std::mutex m; std::condition_variable cv; };
static std::mutex g_htm; static std::unordered_map<uint32_t,RtObj*> g_ht; static uint32_t g_nh=0x40000000;
static uint32_t rt_add(RtObj*o){ std::lock_guard<std::mutex> l(g_htm); uint32_t h=g_nh; g_nh+=4; g_ht[h]=o; return h; }
static RtObj* rt_get(uint32_t k){ std::lock_guard<std::mutex> l(g_htm); auto it=g_ht.find(k); return it==g_ht.end()?nullptr:it->second; }
static RtEvent* rt_ev(uint32_t k,bool create){ RtObj*o=rt_get(k); if(auto*e=dynamic_cast<RtEvent*>(o))return e; if(!create)return nullptr;
  RtEvent*e=new RtEvent(); { std::lock_guard<std::mutex> l(g_htm); g_ht[k]=e; } return e; }
static void rt_setup_thread_ctx(PPCContext& ctx, uint8_t* base){
  const uint32_t PCR=0xAB0,TLS=0x100,TEB=0x2E0,STK=0x40000,TOT=PCR+TLS+TEB+STK;
  uint32_t tb=rt_alloc(TOT,0x1000); uint8_t* t=base+tb; std::memset(t,0,TOT);
  *(uint32_t*)t=__builtin_bswap32(tb+PCR); *(uint32_t*)(t+0x100)=__builtin_bswap32(tb+PCR+TLS);
  *(uint32_t*)(t+PCR+0x10)=0xFFFFFFFF;
  static std::atomic<uint32_t> g_tid{2}; // main thread = 1 (set by harness)
  *(uint32_t*)(t+PCR+TLS+0x14C)=__builtin_bswap32(g_tid++);
  ctx.r1.u64=tb+PCR+TLS+TEB+STK; ctx.r13.u64=tb; ctx.fpscr.loadFromHost(); }
static PPCFunc* rt_lookup(uint8_t* base,uint32_t a){ if(a>=PPC_CODE_BASE&&a<PPC_CODE_BASE+PPC_CODE_SIZE)
  return *(PPCFunc**)(base+PPC_IMAGE_BASE+PPC_IMAGE_SIZE+(uint64_t)(uint32_t)(a-PPC_CODE_BASE)*2); return nullptr; }
#ifdef _WIN32
// Minimal decls instead of <windows.h> (which collides with the recomp headers' macros in this TU)
// and instead of a -lwinmm link change: kernel32 is already linked implicitly, so resolve winmm's
// timeBeginPeriod dynamically.
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char*);
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void*, const char*);
#endif
// Raise the OS timer resolution to 1ms so a ~16.7ms sleep deadline is actually reachable.
// WHY (2026-07-16): Windows' DEFAULT sleep granularity is ~15.6ms and nothing in this codebase ever
// called timeBeginPeriod — see the vblank pump below for what that silently did to game speed. On
// Linux the monotonic timers are already fine-grained, so this is a no-op there.
static void rt_timer_precision_begin(){
#ifdef _WIN32
  static bool done=false; if(done) return; done=true;
  typedef unsigned long (__stdcall *tbp_t)(unsigned int);
  void* wm=LoadLibraryA("winmm.dll");
  if(!wm){ std::fprintf(stderr,"  [vblank] WARN winmm.dll load failed -- sleeps stay ~15.6ms, pacing WILL be wrong\n"); return; }
  tbp_t tbp=(tbp_t)GetProcAddress(wm,"timeBeginPeriod");
  if(!tbp){ std::fprintf(stderr,"  [vblank] WARN timeBeginPeriod not found -- pacing WILL be wrong\n"); return; }
  unsigned long r=tbp(1);
  std::fprintf(stderr,"  [vblank] timeBeginPeriod(1) -> %lu (0=OK); sleep granularity now ~1ms\n",r);
#endif
}
// --- vblank pump: fire the registered graphics-interrupt callback at the console's 59.94Hz ---
// (Xenia semantics: guest cb(r3=source, r4=user_data); source 0 = vblank.)
static std::atomic<uint32_t> g_vd_cb{0}, g_vd_cb_ctx{0};
static std::atomic<uint32_t> g_rb_base{0}, g_rb_log2{0}, g_wb_addr{0};
// D3D device handle (CreateDevice hook result) -- defined here (not at the D3D9 hook set
// below) because the VdSwap impl samples the device ring cursor (dev+0x30) for the
// LEG-27/40 ring-window fix.
static uint32_t g_d3d_device=0;
// LEG-27/40 ring-window truncation: the gameplay draw stream is written DURING Present
// (RT_GAMEPUMP ticks the game from inside the VdSwap impl), i.e. AFTER the Present-entry
// cursor sample the old decode window used as its end. Sample the cursor at VdSwap
// entry / after the game pump / at VdSwap exit and let the Present hook take the furthest.
static std::atomic<uint32_t> g_vk_vd_pre{0}, g_vk_vd_pump{0}, g_vk_vd_post{0};
// RT_HKDUP diagnostic (2026-07-12, menu text-duplication investigation): total VdSwap invocations
// since the last hooked Present, exposed globally so sub_820A5408 can log the VdSwap:Present ratio.
// If VdSwap (the guest's real per-frame kernel swap / GATE-3 pump tick) fires more than once per
// hooked Present, this present's g_hkd list has accumulated draws from >1 real guest frame.
static std::atomic<long> g_vdswap_since_present{0};
// Global present counter (bumped once per VdSwap) + wall-clock epoch, so the FSM-log probe can be
// read from EITHER pump site (present-path VdSwap or the 59.94Hz vblank thread) and correlated with
// window snaps taken at the same instant. (2026-07-22 select-FSM determinism leg.)
extern "C" { std::atomic<uint32_t> g_rt_present_ctr{0}; }
static const std::chrono::steady_clock::time_point g_rt_epoch = std::chrono::steady_clock::now();
static inline uint16_t rt_be16(uint8_t* B,uint32_t a){ return (uint16_t)((B[a]<<8)|B[a+1]); }
// RT_FSMLOG=1: once per game-logic tick, log the select-FSM state block + present counter + wall-ms.
// Logs on ANY tracked-field change AND at most ~1/sec otherwise. `src` = "pres" (VdSwap pump) or
// "vbl" (vblank pump) so the two pacing regimes are distinguishable in one log. The addresses are
// the decoded select FSM (FUN_881378a0/FUN_88137498, reco_normal decomp): 678e=driver state,
// 6790=browse 0x40 countdown (int, underflow=auto-advance), 54e=subscreen latch, 6794/6798=slot
// selectors, 6878=confirm flag, 688c=input-activity, 6890=8-tick grace, 449a0f=auto-branch gate.
static void rt_fsmlog(uint8_t* B, const char* src){
  static bool on = getenv("RT_FSMLOG")!=nullptr;
  if(!on) return;
  uint16_t st   = rt_be16(B,0x884D678Eu);
  uint8_t  latch= B[0x887AD54Eu];
  int32_t  t    = (int32_t)rt_be32(B,0x884D6790u);
  uint32_t s94  = rt_be32(B,0x884D6794u), s98 = rt_be32(B,0x884D6798u);
  uint32_t cfrm = rt_be32(B,0x884D6878u), act = rt_be32(B,0x884D688Cu), grc = rt_be32(B,0x884D6890u);
  uint8_t  ab   = B[0x88449A0Fu];
  uint32_t d76  = rt_be32(B,0x884D66A0u);   // per-slot timeout trigger latch (FUN_88137498 tail)
  uint32_t pc   = g_rt_present_ctr.load();
  // change-detect over the whole tracked tuple
  static uint16_t l_st=0xFFFF; static uint8_t l_latch=0xFF,l_ab=0xFF; static int32_t l_t=0x7FFFFFFF;
  static uint32_t l_s94=~0u,l_s98=~0u,l_cfrm=~0u,l_act=~0u,l_grc=~0u,l_d76=~0u;
  static long l_ms=-100000;
  long ms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-g_rt_epoch).count();
  bool chg = st!=l_st||latch!=l_latch||ab!=l_ab||s94!=l_s94||s98!=l_s98||cfrm!=l_cfrm||act!=l_act||grc!=l_grc||d76!=l_d76;
  if(!chg && (ms-l_ms)<1000) { l_t=t; return; }
  l_st=st; l_latch=latch; l_ab=ab; l_t=t; l_s94=s94; l_s98=s98; l_cfrm=cfrm; l_act=act; l_grc=grc; l_d76=d76; l_ms=ms;
  std::fprintf(stderr,"[fsmlog:%s] ms=%ld pres=%u state678e=%u timer6790=%d latch54e=%u slot6794=%u slot6798=%u confirm6878=%u act688c=%u grace6890=%u autobr449a0f=%u trig66a0=%u%c",
    src, ms, pc, (unsigned)st, t, (unsigned)latch, s94, s98, cfrm, act, grc, (unsigned)ab, d76, 10);
}
// RT_REVEALLOG=1 (2026-07-22, charcard reveal-wedge leg): sample the Character-Select CARD WIDGET
// phase at 60Hz alongside the OVER/ADDITIVE overlog. The card widget is a fixed-address 0xf8-byte
// struct at &DAT_8844A6A8 + slot*0xf8 (built by FUN_8814ddc8; its event handler FUN_8814bf10 reads
// +0x54). FUN_8814d400 (per-frame card driver) branches on that +0x54: if +0x54 != 0 it runs the
// animation machine FUN_8814bfb0 and RETURNS EARLY (settled art draw never emitted); if +0x54 == 0
// it runs the settled path -> FUN_8814b378 which emits the OVER (0x7060706) character-art draw.
// So +0x54 != 0 for the whole card window == "OVER never fires" (the measured wedge). The sprite-anim
// struct for the slot is at &DAT_8844A898 + slot*0xa0; DAT_8844A8AC/B0 = its state ints (6 = confirmed),
// DAT_8844A8F8 = confirm-particle active. widget +0xf4 = the auto-idle counter (FUN_8814d400 ~139378,
// fires FUN_8808d1b8(0x29) at 300). Logs both slots, change-detected + >=1/s heartbeat, present-tagged.
static void rt_reveallog(uint8_t* B){
  static bool on = getenv("RT_REVEALLOG")!=nullptr;
  if(!on) return;
  const uint32_t W0=0x8844A6A8u, WS=0xF8u, A0=0x8844A898u, AS=0xA0u;
  uint8_t  p0 = B[W0+0x54], p1 = B[W0+WS+0x54];          // widget +0x54 phase (byte), slot0/slot1
  uint32_t idle0 = rt_be32(B,W0+0xF4);                   // widget +0xf4 auto-idle counter (slot0)
  uint32_t as14 = rt_be32(B,A0+0x14), as18 = rt_be32(B,A0+0x18); // anim state ints (6=confirmed)
  uint32_t as50 = rt_be32(B,A0+0x50), as54 = rt_be32(B,A0+0x54); // anim active flag / frame idx
  uint32_t asf8 = rt_be32(B,A0+0x60);                    // DAT_8844A8F8 confirm-particle active
  uint32_t pc  = g_rt_present_ctr.load();
  static uint8_t l_p0=0xFF,l_p1=0xFF; static uint32_t l_i=~0u,l14=~0u,l18=~0u,l50=~0u,l54=~0u,lf8=~0u;
  static long l_ms=-100000;
  long ms=(long)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-g_rt_epoch).count();
  bool chg = p0!=l_p0||p1!=l_p1||as14!=l14||as18!=l18||as50!=l50||as54!=l54||asf8!=lf8;
  if(!chg && (ms-l_ms)<1000){ l_i=idle0; return; }
  l_p0=p0; l_p1=p1; l_i=idle0; l14=as14; l18=as18; l50=as50; l54=as54; lf8=asf8; l_ms=ms;
  std::fprintf(stderr,"[reveallog] ms=%ld pres=%u wphase0=%u wphase1=%u idle0=%u anim14=%u anim18=%u anim_active50=%u anim_frame54=%u particle_f8=%u%c",
    ms, pc, (unsigned)p0, (unsigned)p1, idle0, as14, as18, as50, as54, asf8, 10);
}
// RT_HKDUP diagnostic (2026-07-12): count of KeQuerySystemTime calls since the last hooked Present.
// KeQuerySystemTime (below) is a FAKE deterministic clock that advances a fixed 100000 (10ms) per
// CALL, not per elapsed wall-time -- if the guest's per-widget slide/ease animation re-queries this
// clock and runs a delta-time "catch-up" sub-step loop, an abnormally high call count in one present
// would explain the same widget being update-and-drawn (immediate-mode) more than once per frame.
static std::atomic<long> g_qst_since_present{0};
// RVK_RINGPROBE diagnostics: vblank-thread sampler stats for dev+0x30 motion between presents.
static std::atomic<uint32_t> g_rp_moves{0}, g_rp_back{0}, g_rp_maxcur{0};
static int rvk_ringprobe(){ static int v=getenv("RVK_RINGPROBE")?atoi(getenv("RVK_RINGPROBE")):0; return v; }
// ---- LEG-27/40 kick-capture (RVK_RINGFULL>=2, the default) ----
// Kick-probe finding (2026-07-10): the d3d9 command-buffer body [rb+0x8000, ...) is built
// and SUBMITTED in several kicks per frame (shell kick sub_820A8638 / game kick
// sub_88080298), and after a submitted pass completes (gameplay scene + resolve) the D3D
// RESETS the body cursor (dev+0x30) to body+0x3C and REBUILDS the next pass (shell overlay,
// then Present/swap) over the same bytes. Decoding one [body, cursor-at-present) window can
// therefore only ever see the LAST pass (the overlay) -- that is the LEG-27/40 truncation
// (18 decoded vs ~80 emitted draws; black playfield). Fix: capture each segment's bytes at
// kick time (before the rebuild overwrites them) into a guest scratch arena; Present decodes
// the arena = the whole frame's PM4 in submission order.
static uint32_t g_ks_arena=0;                    // guest scratch (lazily rt_alloc'd)
// RING conversion (2026-07-17 async render worker): the arena used to be one 192KB window,
// reset+reused every present — the async worker walks a window for ~75-135ms (≈6-8 presents),
// so the reuse rewrote the bytes UNDER the walk (torn PM4 → register spray → the run-K
// 0xC0000005). Now a 6MB ring: each present CLOSES the current window [wstart,off) and hands
// it to the renderer; kicks keep appending after it. A 100ms-old window's bytes survive until
// the ring wraps (~30+ windows later). Per-window bytes stay capped at 192KB (the renderer's
// 0x40000 window sanity bound).
static const uint32_t g_ks_size=0x600000;        // 6MB ring
static const uint32_t g_ks_wcap=0x30000;         // per-WINDOW cap (renderer maxWin is 0x40000)
static uint32_t g_ks_off=0;                      // ring write offset
static uint32_t g_ks_wstart=0;                   // current (open) window's start offset
static uint32_t g_ks_last30=0;                   // body cursor at the previous kick
static long g_ks_drops=0, g_ks_kicks=0;
static const uint32_t g_ks_magic=0xB000DEADu;    // reset sentinel (parses as a PM4 type-2 NOP)
static bool rt_vk_on();
static int rvk_ringfull(){ static int v=getenv("RVK_RINGFULL")?atoi(getenv("RVK_RINGFULL")):2; return v; }
// Game-field-active flag (0x885C1A20 -- set to 1 by the id46 factory sub_880E3888 when the
// gameplay field RT is simulating; 0 for the shell/front-end = title/menu/dialog). The
// RINGFULL kick-capture is only correct for the gameplay ring/rebuild pattern; on shell
// frames the accumulated-segment arena corrupts the menu composite (BISECTED 2026-07-11:
// drops the menu-item gold panels, streaks the dialog). So SCOPE kick-capture to gameplay --
// front-end frames fall back to the legacy [rb+0x8000, cursor-at-entry) window. RVK_RINGFULL_ALL
// forces capture on every frame (old always-on behavior, for A/B).
static bool rvk_ringfull_all(){ static bool v=getenv("RVK_RINGFULL_ALL")!=nullptr; return v; }
static bool rt_game_field_active(uint8_t* base){ return rt_be32(base,GA_FIELD_ACTIVE)!=0; }
// RT_ROMRENDER (2026-07-15, attract-render — cross-lane change, coord w/ audio later): route the ROM's
// PM4 render to the LEGACY spine whenever the arcade ROM MAIN is live (g_rt_romactive, defined in
// merged_xex.cpp sub_88168D48), not just on the guest field_active flag (0x885C1A20) — which the
// legal/ranking ATTRACT screens never set, leaving the attract black (hook renders the stale menu).
// DEFAULT ON as of 2026-07-16: with it off the 1.5 attract renders BLACK out of the box, which is a
// product defect, not a diagnostic default. Verified the shell front-end is unaffected (g_rt_romactive
// is false until ROM main is entered, so boot/title/top-menu keep the hook render byte-identical);
// what changes is attract-onward frames, which now reach the legacy spine and actually draw.
// RT_ROMRENDER=0 restores the old routing. ORed into the 3 field_active gates: (1) the
// kick-capture scope below, (2) the runLegacyPresent full-arena decode, (3) the hook->legacy present
// routing. g_rt_romactive is FALSE during the shell front-end (ROM main not entered) so the top-menu
// keeps its clean hook render — only attract-onward frames flip to the legacy spine.
extern "C" { extern volatile int g_rt_romactive; }
static bool rt_romrender_on(){ static int v=getenv("RT_ROMRENDER")?atoi(getenv("RT_ROMRENDER")):1; return v>0; }
// ★ FNF-11 part 2 (2026-07-27, decomp-grounded — ATLAS_scene_system §8 / NOTE_fnf11_handback
// PART 2): the menu-level quit (B == RETURN TO TOP MENU byte-for-byte, per FUN_821D0CB0(-1))
// sends msg 13 + msg 3 and XexUnloadImage — the ROM is UNLOADED and the SHELL's own TOP MENU
// (vt 0x82050518, movie menu_title_menu) starts ticking. g_rt_romactive is set once at ROM
// main entry and never cleared (our XexUnloadImage is a no-op stub), so presents stayed routed
// to the dead ROM spine = the stuck slate/green compose. REGISTER-TRUE gate from the guest:
// FUN_821CE400 keeps [[0x821F8588]+0x64] == 1 exactly while the shell front-end owns the
// screen (root FSM phases 4..6). Honor it: shell-owns-screen forces hook (shell) routing
// regardless of the stale romactive flag. Pre-ROM behavior is unchanged (romactive==0 there
// already); ROM-live frames are unchanged (byte==0 outside phases 4..6). Logs each ownership
// transition. RT_NOSHELLOWNS=1 reverts to the old routing for A/B.
static bool rt_shell_owns_screen(uint8_t* base){
  static bool off = getenv("RT_NOSHELLOWNS") && atoi(getenv("RT_NOSHELLOWNS"))!=0;
  if(off || !base) return false;
  uint32_t p = rt_be32(base, 0x821F8588u);
  bool owns = p && p < 0x20000000u && *(base + p + 0x64) == 1;
  static int last = -1;
  if((int)owns != last){ last = (int)owns;
    std::fprintf(stderr, "[shellowns] [0x821F8588]+0x64 -> %d (romactive=%d)\n", (int)owns, g_rt_romactive); }
  return owns;
}
static bool rt_rom_render(uint8_t* base){
  if(rt_shell_owns_screen(base)) return false;   // guest says: shell front-end owns the display
  return rt_game_field_active(base) || (rt_romrender_on() && g_rt_romactive!=0);
}
// ★ RVK_PREROMWIN (2026-07-26) — SCOPED pre-ROM kick-capture window. DEFAULT ON (defect fix).
// The pre-ROM half of the front end (boot dialogs, shell title, TOP MENU, card carousel) was
// decoding a FIXED-START byte window [rb+0x8000, dev+0x30-at-Present) of what a census
// (RVK_RINGPROBE, 2026-07-25) measured to be a ~2 MB ROLLING command arena: the cursor advances
// ~34 KB/present and wraps every ~56 presents, so the window grows past the renderer's 256 KB
// sanity clamp (vk_render.cpp maxWin) within ~7 presents of each wrap and is then REJECTED —
// 290 of 343 sampled windows (84.5 %), i.e. only ~9.3 % of pre-ROM presents ever produced a fresh
// render, and the ~15 batches that did survive were an arbitrary prefix of the arena rather than
// the frame's display list (TOP MENU decoded ≈ one 38-quad dialog layer out of ~99 draws).
// Post-ROM the SAME shell menu code composes correctly because it gets the KICK-CAPTURE window
// (234 batches on SYSMENU vs 15 on the TOP MENU) — the arena of exactly the segments the guest
// submitted to the CP, which is the command processor's own view and strictly MORE register-true
// than a packet-blind byte span. This lever removes the pre-ROM scope-out at rt_kick_capture and
// in runLegacyPresent so the front end gets that same window.
// SCOPED, not merely unscoped (the difference vs the old RVK_RINGFULL_ALL A/B lever):
//   (1) the kick ring is REWOUND at the pre->post-ROM edge (rt_pw_rom_reset) so the post-ROM path
//       starts from the byte-for-byte state it starts from today (empty ring, legacy-window
//       fallback on the first ROM present);
//   (2) RT_VTXSNAP stays OUT of the pre-ROM path (RVK_PREROMVTX, default off) — measured
//       2026-07-26 (`ab9_ringall_novtx`) to change nothing on the shell (card page mean 33.62 /
//       ink 16.21 %, identical to the vtxsnap-on run), so the 16 MB snapshot ring is neither
//       allocated nor advanced before the ROM, and reaches the handoff virgin exactly as today;
//   (3) the raw-span reset SENTINEL is not stamped into the guest's live command arena pre-ROM
//       (see runLegacyPresent) — it is only consumed by the RT_KICKSEG=0 path.
// RVK_PREROMWIN=0 = the escape lever: every site below goes inert and the pre-ROM path is
// byte-identical to the 2026-07-25 ship build. RVK_RINGFULL_ALL keeps its old unscoped meaning
// (capture everywhere, no reset) so the recon A/B stays reproducible.
static bool rvk_preromwin(){ static int v=getenv("RVK_PREROMWIN")?atoi(getenv("RVK_PREROMWIN")):1; return v>0; }
static bool rvk_preromvtx(){ static int v=getenv("RVK_PREROMVTX")?atoi(getenv("RVK_PREROMVTX")):0; return v>0; }
static std::atomic<int> g_pw_romreset{0};   // 0 = the ROM-handoff rewind has not run yet
// ---- RT_VTXSNAP (2026-07-12): kick-time VERTEX snapshot for the kick-capture arena ----------
// The kick-capture arena makes the PM4 PACKETS self-contained, but not the VERTEX BUFFERS the
// captured draws reference: the guest reuses one small (~10KB) dynamic vertex-scratch window
// (observed ~0xACB000-0xACD5E0, 105 rebinds of one base per frame per RVK_RESCLS) for many
// draws per frame, so by the time the legacy decoder (renderFrameReal) reads a draw's vertices
// at PRESENT time they have been overwritten by later draws -- degenerate triangles that smear
// bright HUD-atlas texels into the "white-wash" / vertical streak bands over gameplay (the lossy
// re-decode class noted at the RT_DRAWTRACE comment below). Fix, applied per captured segment
// inside rt_kick_capture: walk the segment's PM4 (reusing rt_ringcount_scan's walker in snapshot
// mode), and for each content draw copy its vertex bytes [va, va+n*24+slack) out of the volatile
// guest scratch into a snapshot heap, then REWRITE the payload dword that set the vertex-fetch
// base (reg 0x48BE, via SET_CONSTANT type-1 or a type-0 reg write) in the ARENA COPY so it
// points at the snapshot. Present-time decode then sees the vertices as they were AT KICK TIME.
// Encoding matches the decoder exactly: renderFrameReal reads va = g_regFile[0x48BE] & ~3u
// (byte address, low 2 bits = fetch type), so the rewrite keeps the low 2 bits and swaps only
// the address bits. Setters inside INDIRECT_BUFFERs are live guest memory (not our copy) --
// never rewritten; such draws (and any draw whose setter wasn't seen in this capture window)
// are left pointing at guest RAM rather than risking a bad copy. Default OFF (RT_VTXSNAP=1
// enables); only touches the kick-capture path, i.e. gameplay-field-active frames -- the
// title/menu hookrender path is unaffected.
// DEFAULT-ON (2026-07-22): select-compose flicker fix (was flipped via a putenv hack in
// vk_render.cpp static-init while rt.cpp was session-locked; that lock is stale, default now lives
// here). Unset => ON; RT_VTXSNAP=0 still forces the old behavior byte-for-byte.
static bool rt_vtxsnap_on(){ static int v=getenv("RT_VTXSNAP")?atoi(getenv("RT_VTXSNAP")):1; return v>0; }
static uint32_t g_vtxsnap_arena=0;                // guest snapshot heap (lazily rt_alloc'd RING)
// RING (2026-07-17 async render worker): was 2×1MB halves flipped per window — the worker walks a
// window ~100ms (≈6-8 windows) late, by which time the half had flipped 3-4× and its snapshots
// were recycled → the run-O torn legal text / scrambled title. 16MB ring ≈ 80+ windows of
// survival at typical usage; snapshots stay contiguous (wrap to 0 when the tail can't fit one).
static const uint32_t g_vtxsnap_size=0x1000000u;  // 16MB ring (~58 draws/present, <=24KB each)
static uint32_t g_vtxsnap_off=0;                  // ring write offset
static uint32_t g_vtxsnap_half=0;                 // double-buffer: RT_GAMEPUMP runs the game DURING
                                                  // Present, so window N+1's first kicks can land
                                                  // while rvk_present still decodes window N --
                                                  // flip halves per window so N's snapshots survive
static uint32_t g_vs_vf0=0, g_vs_setter=0, g_vs_snaplen=0;  // walker state, carried ACROSS the
                                                  // segments of one window (a setter seen in an
                                                  // earlier segment is still a valid arena addr)
static long g_vs_snaps=0, g_vs_skips=0, g_vs_full=0;
static void rt_ringcount_scan(uint8_t* base, uint32_t start, uint32_t end, long& pm4draws,
                              long& resolves, bool vtxsnap=false);  // defined below (RT_RINGCOUNT)
// ★ RT_KICKSEG (2026-07-16) — capture EXACTLY the kicked segment, not a raw arena span.
// THE WASH FIX. The old path below memcpy'd the raw byte range [prev dev+0x30 cursor, cur) of the
// d3d9 command arena, PACKET-BLIND. But command segments and RAW FLOAT DATA BLOCKS are suballocated
// from that SAME arena, interleaved in memory (decomp sub_820A8638 :51731-51797; bucket-1 float
// allocs FUN_820a8138 :51495; proof at :48344 where the resolve writes 6 screen-space floats into the
// arena, referenced ONLY by a vertex-fetch constant and never walked by the PM4 stream). So our span
// handed the decoder [cmdseg][floats][cmdseg]… and it read 1.0f (0x3F800000) as a TYPE0 header
// (base=0, cnt=16257) → sprayed 16257 dwords across the register file → RB_BLENDCONTROL0 got float
// colours → alpha-ignoring opaque quads → glow sprites became solid white blobs = the wash.
// The real CP never sees those blocks: it executes exactly the submitted IBs.
// The kick ARGS give us the segment exactly (verified against the primary-ring triples):
//   r4 = segment descriptor object; r4[0] = 0x81000000|len_dw, **r4[1] = segment guest ADDRESS**
//   r6 = **segment length in DWORDS**
// e.g. kick#0 r4[1]=0x0046A040 r6=0xB  vs ring "C0013F00 0046A040 0000000B" — exact, for every kick.
// This is sourced from the kick rather than the ring ON PURPOSE: measured, the primary ring is DEAD
// after early boot (write index dev+0x2ACC advanced only 4 times ever, all on the first ring
// 0x452000; CP_RB_WPTR MMIO 0x7FC80714 pinned at 0x1F; 985 later kicks show idx:19->19) — so walking
// [rptr,wptr) would capture NOTHING for exactly the frames that matter. The kick args stay correct.
// `seg` MUST be dereferenced by the caller AFTER the original kick returns (the dev+0x5c10 callback
// can relocate a segment, decomp:51772-51779), while r4/r6 are read BEFORE (volatile registers).
// RT_KICKSEG=0 restores the old raw-span capture.
static bool rt_kickseg_on(){ static int v=getenv("RT_KICKSEG")?atoi(getenv("RT_KICKSEG")):1; return v>0; }
// Ring append shared by both capture variants: wraps the ring when the tail is reached
// (relocating the current OPEN window's bytes to offset 0 so a window is always contiguous),
// enforces the per-window cap, flips the vtxsnap half on a window's FIRST segment.
// Ring bookkeeping lock: appends run on the ROM/kick thread, window-closes on the shell present
// thread. Unsynchronized, a wrap racing a close can leave wstart>off — the offset math then wraps
// to a wild segA and the append memcpy faults the ROM thread (EHCONTAIN parks it = the run-M
// silent attract wedge). Critical sections are tiny (pointer math + <=192KB memcpy).
static std::mutex g_ks_mtx;
// allowVtx: RT_VTXSNAP participation for THIS segment. Always true on the historic paths
// (post-ROM, and the RVK_RINGFULL_ALL A/B lever); false for RVK_PREROMWIN's pre-ROM captures
// unless RVK_PREROMVTX=1 — see the RVK_PREROMWIN block above for why.
// ★ RT_SEGTAB (FNF-7 decisive experiment, 2026-07-26) — MEASUREMENT ONLY, DEFAULT OFF.
// Per-window table of the segments that were actually memcpy'd into the kick arena, so the
// renderer can classify WHERE a decoded packet came from. The FNF-7 verdict leaves two sites:
//   Site A — relocation race at the kick (rt.cpp ~1806): ks_len is latched from r6 BEFORE the
//            original kick while the segment ADDRESS is dereferenced from ks_obj+4 AFTER it,
//            and this file's own comment says the dev+0x5c10 callback can relocate a segment.
//            Signature: a segment whose pre-kick address differs from the post-kick one.
//   Site B — the PM4 walk running past the window (vk_render.cpp ~3667): only the packet HEADER
//            is bounds-checked. Signature: a decoded packet at an offset >= the end of the last
//            captured segment.
// Recording both the PRE- and POST-kick address is what separates them; everything else here is
// bookkeeping the append already had. Nothing is written back into guest memory and no capture
// decision changes — g_seg_* is write-only from this side, read by vk_render's RVK_DRAWTRIP dump.
// ⚠ appends run on the ROM/kick thread and the renderer reads on the present thread (the same
// unsynchronized pairing this file already documents for g_ks_off); for a measurement that is
// acceptable, but a torn read is possible and the analysis must tolerate it.
#define KS_SEGMAX 64
extern "C" {
  volatile int      g_seg_n = 0;               // segments in the CURRENT window
  volatile unsigned g_seg_wbase = 0;           // window base guest addr (arena + wstart)
  volatile unsigned g_seg_off[KS_SEGMAX] = {0};// this segment's offset within the window
  volatile unsigned g_seg_len[KS_SEGMAX] = {0};// bytes
  volatile unsigned g_seg_src[KS_SEGMAX] = {0};// guest source actually copied from (post-kick)
  volatile unsigned g_seg_pre[KS_SEGMAX] = {0};// segment address read BEFORE the kick (Site A)
  volatile unsigned g_seg_obj[KS_SEGMAX] = {0};// ks_obj (r4)
  volatile unsigned g_seg_lat[KS_SEGMAX] = {0};// latched ks_len (r6, dwords)
  // ★ 2026-07-26: the GUEST'S OWN declared length, `*(uint*)r4 & 0x00FFFFFF`, snapshotted AT KICK
  // TIME. It MUST be read here, not at dump time: a first attempt read the descriptor from
  // vk_render's dump and got 0 / 3,409,888 / other nonsense on 4 of 6 segments, because by then the
  // guest has reused the descriptor memory — the same "read it in the wrong window" trap that
  // already bit the g_seg_* snapshot itself. Zero means "not captured", not "guest said zero".
  volatile unsigned g_seg_objdw[KS_SEGMAX] = {0};
}
// Set by the kick hook immediately before rt_kick_capture so the append can stamp them.
extern "C" { volatile unsigned g_ks_curObj = 0, g_ks_curLatLen = 0, g_ks_curPreAddr = 0, g_ks_curObjDw = 0; }
static bool rt_segtab_on(){ static int v = getenv("RT_SEGTAB") ? atoi(getenv("RT_SEGTAB")) : 0; return v > 0; }
static bool rt_ks_append(uint8_t* base, uint32_t s, uint32_t len, bool allowVtx){
  std::lock_guard<std::mutex> l(g_ks_mtx);
  if(!g_ks_arena) g_ks_arena=rt_alloc(g_ks_size,0x1000);
  if(g_ks_off+len>g_ks_size){                    // ring wrap
    uint32_t wlen=g_ks_off-g_ks_wstart;
    if(wlen && wlen+len<=g_ks_wcap)
      std::memmove(base+g_ks_arena, base+g_ks_arena+g_ks_wstart, wlen);   // carry the open window
    else wlen=0;                                 // open window unmovable — drop its partial bytes
    g_ks_wstart=0; g_ks_off=wlen;
  }
  if(g_ks_off-g_ks_wstart+len>g_ks_wcap){        // window cap (was: arena FULL)
    if((g_ks_drops++%2000)==0) std::fprintf(stderr,"[kickcap] window FULL (w=%u +%u) drop#%ld\n",g_ks_off-g_ks_wstart,len,g_ks_drops);
    return false;
  }
  bool windowFirstSeg = (g_ks_off==g_ks_wstart);
  uint32_t segA=g_ks_arena+g_ks_off;
  if(rt_segtab_on()){                       // ★ RT_SEGTAB: stamp before g_ks_off advances
    if(windowFirstSeg){ g_seg_n=0; g_seg_wbase=g_ks_arena+g_ks_wstart; }
    int k=g_seg_n;
    if(k>=0 && k<KS_SEGMAX){
      g_seg_off[k]=g_ks_off-g_ks_wstart; g_seg_len[k]=len; g_seg_src[k]=s;
      g_seg_pre[k]=g_ks_curPreAddr; g_seg_obj[k]=g_ks_curObj; g_seg_lat[k]=g_ks_curLatLen;
      g_seg_objdw[k]=g_ks_curObjDw;
      g_seg_n=k+1;
    }
  }
  std::memcpy(base+segA, base+s, len);
  g_ks_off+=len;
  if(rt_vtxsnap_on() && allowVtx){
    if(windowFirstSeg){ g_vs_vf0=0; g_vs_setter=0; g_vs_snaplen=0; }   // ring: off keeps advancing
    long vd=0,vr=0; rt_ringcount_scan(base,segA,segA+len,vd,vr,true);
  }
  return true;
}
// ★ RVK_PREROMWIN ROM-HANDOFF REWIND (2026-07-26). Runs ONCE, on the present thread, at the first
// present for which rt_rom_render() is true — i.e. before the post-ROM path has consumed anything.
// The reset set is not a guess: it is exactly the state this file has at the first ROM present in
// the shipped (RVK_PREROMWIN=0) build, item for item.
//   g_ks_arena           — stays allocated. Today it is rt_alloc'd at the first ROM kick; with
//                          pre-ROM capture it is rt_alloc'd during boot. That 6 MB shift of the
//                          shared bump heap (out_reco/harness.cpp rt_alloc) is the one state
//                          difference that CANNOT be undone, and is why RVK_PREROMVTX defaults
//                          off — it keeps the shift at 6 MB instead of 22 MB.
//   g_ks_off/g_ks_wstart — rewound to 0 (today: 0, ring never touched). This also DISCARDS the
//                          open window, so the transition present falls through the
//                          `g_ks_off-g_ks_wstart>=8` guard to the legacy [rb+0x8000, entry)
//                          window — byte-identical to today's first ROM present, where the guard
//                          fails because g_ks_arena is still null. The rewind is safe here and
//                          only here: pre-ROM rendering is INLINE (rvk_present's async path needs
//                          g_rt_romactive!=0), so no worker is walking ring bytes at this instant,
//                          and the async window queue is still empty.
//   g_ks_last30/kicks/drops — the raw-span cursor + counters (today: 0/0/0).
//   g_vtxsnap_* / g_vs_*    — already virgin under the default (PREROMVTX off, arena never
//                          allocated, off/half/walker/counters all 0); reset anyway so the
//                          invariant holds when RVK_PREROMVTX=1 is used for A/B.
static void rt_pw_rom_reset(){
  std::lock_guard<std::mutex> l(g_ks_mtx);
  std::fprintf(stderr,"[preromwin] ROM handoff rewind: ks arena=0x%08X off=%u wstart=%u kicks=%ld drops=%ld | vtx arena=0x%08X off=%u snaps=%ld skips=%ld full=%ld\n",
    (unsigned)g_ks_arena,(unsigned)g_ks_off,(unsigned)g_ks_wstart,g_ks_kicks,g_ks_drops,
    (unsigned)g_vtxsnap_arena,(unsigned)g_vtxsnap_off,g_vs_snaps,g_vs_skips,g_vs_full);
  g_ks_off=0; g_ks_wstart=0; g_ks_last30=0; g_ks_kicks=0; g_ks_drops=0;
  g_vtxsnap_off=0; g_vtxsnap_half=0; g_vs_vf0=0; g_vs_setter=0; g_vs_snaplen=0;
  g_vs_snaps=0; g_vs_skips=0; g_vs_full=0;
}
extern "C" void rt_kick_capture(uint8_t* base, uint32_t dev, uint32_t seg, uint32_t lenDw){
  if(rvk_ringfull()<2 || !rt_vk_on() || !dev) return;
  bool romr = rt_rom_render(base);
  // front-end: use legacy window (RT_ROMRENDER: also capture the ROM attract) — unless
  // RVK_PREROMWIN, which is the whole point of this leg.
  if(!rvk_ringfull_all() && !romr && !rvk_preromwin()) return;
  // vtxsnap scope: unchanged (on) for the historic paths; off for pre-ROM captures by default.
  bool allowVtx = rvk_ringfull_all() || romr || rvk_preromvtx();
  if(rt_kickseg_on() && seg && lenDw && lenDw<0x100000u){
    uint32_t s=seg&0x1FFFFFFFu, len=lenDw*4u;
    g_ks_kicks++;
    rt_ks_append(base,s,len,allowVtx);
    return;
  }
  uint32_t rb=g_rb_base.load(); if(!rb) return;
  uint32_t body=rb+0x8000u;
  uint32_t cur=rt_be32(base,dev+0x30);
  if(cur<=body || cur-body>0x18000u){            // outside the 0x18000 ring body (alloc 0x20000 - 0x8000 primary)
    if(rvk_ringprobe() && cur) std::fprintf(stderr,"[kickcap] REJECT cursor=0x%X body=0x%X\n",cur,body);
    return; }
  g_ks_kicks++;
  // Reset sentinel: a mid-frame reset rebuilds from body+0x3C. If our stamped dword there
  // was overwritten, a reset+rebuild happened since the previous kick, so this segment runs
  // from the body start (a cursor comparison alone misses rebuilds that grow PAST the
  // previous kick's cursor).
  uint32_t last=g_ks_last30; g_ks_last30=cur;
  bool sentinelIntact = rt_be32(base,body+0x3Cu)==g_ks_magic;
  uint32_t s=body;
  if(sentinelIntact && last>body && last<=cur) s=last;
  if(cur>s){
    rt_ks_append(base,s,cur-s,allowVtx);
  }
  *(uint32_t*)(base+body+0x3Cu)=__builtin_bswap32(g_ks_magic);  // arm for the next interval
}
PPC_FUNC_IMPL(__imp__VdInitializeRingBuffer){ LOGN("VdInitializeRingBuffer");
  g_rb_base=ctx.r3.u32; g_rb_log2=ctx.r4.u32;
  std::fprintf(stderr,"  [ring] init base=0x%08X log2=%u%c",(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,10);
  ctx.r3.u32=0; (void)base; }
PPC_FUNC_IMPL(__imp__VdEnableRingBufferRPtrWriteBack){ LOGN("VdEnableRingBufferRPtrWriteBack");
  g_wb_addr=ctx.r3.u32;
  std::fprintf(stderr,"  [ring] writeback addr=0x%08X r4=%u%c",(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,10);
  ctx.r3.u32=0; (void)base; }
// RT_KICK: per-vblank, kick the shell "service thread" event so it doesn't spin forever
// unsignaled. singleton = PPC_LOAD_U32(0x821F857C); the event HANDLE guest-side lives at
// singleton+568. Signaling it drives whatever native shell code kicks per frame. Gated by
// env so it's a no-op unless explicitly requested (harmless in the standalone shell build
// too -- singleton will just be null until the shell reaches that code path).
extern "C" void __imp__NtSetEvent(PPCContext& __restrict ctx, uint8_t* base);
extern "C" int rt_audio_can_accept(void);   // rt_audio.cpp (audiopump pacing gate)
// forward decls for the vblank-thread game pump (defined/declared further down in this file)
extern "C" uint32_t g_game_tick_modectx;
extern "C" void __imp__sub_821C8DA8(PPCContext& __restrict, uint8_t*);
static void rt_setup_thread_ctx(PPCContext&, uint8_t*);

// ===================================================================================
// RT_AUDIOWORKER — pump-clock parity (2026-07-25). Host-transport half lives in
// rt_audio.cpp (the counting semaphore + consumption clock); this side owns the worker
// THREAD (it needs the guest render-driver-callback machinery: rt_lookup / rt_alloc /
// rt_setup_thread_ctx / g_xaudio_cb). Mirrors rexglue AudioSystem::WorkerThreadMain:
// prime queued_frames_, then run the guest callback once per CONSUMED frame instead of
// bursting it from the vblank thread.
extern "C" int  rt_audio_worker_on(void);
extern "C" void rt_audio_worker_init(void);
extern "C" int  rt_audio_worker_wait_token(void);   // blocks until sink consumes a frame
extern "C" int  rt_audio_worker_prime_count(void);
extern "C" unsigned rt_audio_bridge_music_cueobj(unsigned* bankPtrOut, int* cueOut);
extern "C" void     rt_audio_bridge_music_liveness(unsigned cueObj, int alive);
extern "C" uint32_t g_xaudio_cb, g_xaudio_cb_ctx;   // stubs.cpp (registered render-driver client)

// Set on the dedicated audio worker thread only. Read by rt_audio_fire_cb_once (logging)
// and by KeWaitForMultipleObjects: on the worker thread the render-driver callback's
// WaitAny{shutdown,frame_ready} may block long enough for the guest engine-worker
// handshake to land, instead of the vblank thread's aggressive 3ms clamp.
static thread_local bool t_on_audio_worker=false;

// Fire the guest XAudio render-driver callback exactly once (produce one mixed frame).
// This is the same work the legacy RT_AUDIOPUMP block does per tick; factored out so the
// worker thread reuses it verbatim. Optional RT_XACTDOWORK (default-OFF) pumps the XACT3
// engine first, identical to the legacy path.
static void rt_audio_fire_cb_once(PPCContext& c, uint8_t* B){
  static int xdw = [](){ const char* e=getenv("RT_XACTDOWORK"); return (e && atoi(e)!=0)?1:0; }();
  if(xdw){
    uint32_t eng = rt_be32(B, 0x887AD50Cu);
    if(eng && eng < 0xF0000000u){
      if(PPCFunc* dw = rt_lookup(B, 0x820E8F88u)){
        c.r3.u64 = eng; dw(c,B);
        static std::atomic<long> dn{0}; long d=dn.fetch_add(1)+1;
        if(d<=3) std::fprintf(stderr,"  [xactdowork] DoWork(0x820E8F88) engine=0x%X ret=0x%X #%ld\n",eng,(unsigned)c.r3.u32,d);
      }
    }
  }
  static uint32_t argcell = 0;
  if(!argcell){ argcell = rt_alloc(4,4); *(uint32_t*)(B+argcell)=__builtin_bswap32(g_xaudio_cb_ctx); }
  if(PPCFunc* afn=rt_lookup(B,g_xaudio_cb)){
    static std::atomic<long> an{0}; long a=an.fetch_add(1)+1;
    if(a<=3||a==500||(a%4000)==0)
      std::fprintf(stderr,"  [audiopump] firing #%ld cb=0x%08X argcell=0x%X (*=0x%X)%s\n",
                   a,g_xaudio_cb,argcell,g_xaudio_cb_ctx, t_on_audio_worker?" [worker]":"");
    c.r3.u64=argcell; afn(c,B);
  }
}

// The dedicated audio worker thread. Clocked by real consumption via
// rt_audio_worker_wait_token() (WASAPI-per-consumed-frame in live mode, or the 48kHz
// pacer in dump mode). Prime N, then produce-per-consumption -- rexglue parity.
// ★ RT_VOICECENSUS (2026-08-02, default-OFF): once per second, walk the game's 8-entry
// active-voice slot array 0x885C5C50 (stride 0x18; ATLAS_audio.md:365 — +0=waveHandle,
// +4=active flag) and print the live count. Motive: the digital A/B vs the SDK put the shot
// demo at x6.2-6.5 IN THE GUEST MIX with 8 slots — the overlapped-voices hypothesis needs a
// count, on both sides (SDK side = the same walk via futari-test memread). Pure guest-memory
// READ on the worker thread; zero output unless the lever is set.
// ★ 2026-08-03 BANK-ENTRY TRUTH CHECK (ghost-voice hunt round 8). Disk truth (SE.xwb parsed
// with the DXSDK xact3wb.h structs): the shot waves 8/18/24 are PLAIN ONE-SHOTS — flags=0,
// LOOP(0,0), durations 3590/9474/14348 samples, play regions (46836,7180)/(107544,18948)/
// (162176,28696). A one-shot cannot ring for 30 s, so either the guest's IN-MEMORY copy of
// these entries differs (host-side corruption -> end never reached) or the mixer's end-check
// is gated on a divergent input. This scans guest memory for the SE bank ('DNBW', 70 entries)
// once and prints entries 8/18/24 raw for comparison against the disk numbers above.
static void rt_bankscan(uint8_t* B){
  static int state=0;                              // 0=searching, 1=done
  if(state) return;
  for(uint32_t a=0x10000u; a<0x20000000u; a+=4){
    if(*(uint32_t*)(B+a)!=0x57424E44u && *(uint32_t*)(B+a)!=0x444E4257u){  // 'DNBW' either order
      // fast path: check 4 bytes directly (loop is memcmp-free; ~128M iters ~0.4s, one-shot)
      continue;
    }
    uint8_t* h=B+a;
    if(std::memcmp(h,"DNBW",4)!=0) continue;
    uint32_t bd_off=__builtin_bswap32(*(uint32_t*)(h+12));
    uint32_t em_off=__builtin_bswap32(*(uint32_t*)(h+20));
    if(bd_off>0x1000u||em_off>0x100000u) continue;
    uint32_t count=__builtin_bswap32(*(uint32_t*)(h+bd_off+4));
    if(count!=70) continue;                        // SE bank has exactly 70 entries
    std::fprintf(stderr,"[bankscan] SE bank in guest mem at 0x%X (bd=0x%X em=0x%X)\n",a,bd_off,em_off);
    for(int w : {8,18,24}){
      uint8_t* e=h+em_off+w*24;
      uint32_t fad=__builtin_bswap32(*(uint32_t*)(e+0));
      uint32_t po =__builtin_bswap32(*(uint32_t*)(e+8));
      uint32_t pl =__builtin_bswap32(*(uint32_t*)(e+12));
      uint32_t ls =__builtin_bswap32(*(uint32_t*)(e+16));
      uint32_t ll =__builtin_bswap32(*(uint32_t*)(e+20));
      std::fprintf(stderr,"[bankscan] wave%d flags=0x%X dur=%u play(%u,%u) loop(%u,%u)\n",
                   w,fad&0xF,fad>>4,po,pl,ls,ll);
    }
    state=1; return;
  }
  // not found this pass (bank not loaded yet) — try again next tick
}
extern "C" uint32_t g_rt_watch_voice;   // defined in merged_shell.cpp (round-10 voice watch)
static void rt_voice_census(uint8_t* B){
  static bool on = [](){ const char* e=getenv("RT_VOICECENSUS"); return e && e[0]=='1' && !e[1]; }();
  if(!on) return;
  static long n=0;
  if((++n % 188)!=0) return;                       // ~1s of 187.5Hz frames
  if((n/188)%10==5) rt_bankscan(B);                // scan every 10th second until found
  const uint32_t SLOTS=0x885C5C50u, STRIDE=0x18; int live=0;
  char buf[256]; int off=0;
  for(int i=0;i<8;i++){
    uint32_t wave   = __builtin_bswap32(*(uint32_t*)(B+SLOTS+i*STRIDE+0));
    uint32_t active = __builtin_bswap32(*(uint32_t*)(B+SLOTS+i*STRIDE+4));
    if(active) live++;
    off += std::snprintf(buf+off,sizeof buf-off," %X:%u",wave,active);
  }
  std::fprintf(stderr,"[vcensus] live=%d |%s\n",live,buf);
  // Round 10b: capture a watch target when live>=4 (the demo's signature; menus never reach 4):
  // first active slot's cue object; dump cue[0x60] + its wave (cue+0x38) [0x60] per second.
  // Wave fields (decomp): +0x58 state (3=prep 4=playing 5=stopping 6=stopped), +0x2C/+0x30
  // instance list, +0x3C flag byte. Wave stuck at state 4 with a moving cursor = the
  // end-of-data branch never fires; state 5/6 while audibly ringing = mixer ignores state.
  { static uint32_t wcue=0;
    if(!wcue && live>=4){
      for(int i=0;i<8;i++){
        uint32_t active=__builtin_bswap32(*(uint32_t*)(B+SLOTS+i*STRIDE+4));
        uint32_t v     =__builtin_bswap32(*(uint32_t*)(B+SLOTS+i*STRIDE+0));
        if(active && v && v<0xF0000000u){ wcue=v;
          std::fprintf(stderr,"[vwatch] WATCH cue=0x%X (slot %d, live=%d)\n",wcue,i,live); break; }
      }
    }
    if(wcue){
      char wb[560]; int woff=0;
      for(int i=0;i<0x60;i+=4)
        woff+=std::snprintf(wb+woff,sizeof wb-woff,"%08X ",__builtin_bswap32(*(uint32_t*)(B+wcue+i)));
      std::fprintf(stderr,"[vwatch] cue 0x%X: %s\n",wcue,wb);
      uint32_t wv=__builtin_bswap32(*(uint32_t*)(B+wcue+0x38));
      if(wv && wv<0xF0000000u){
        woff=0;
        for(int i=0;i<0x60;i+=4)
          woff+=std::snprintf(wb+woff,sizeof wb-woff,"%08X ",__builtin_bswap32(*(uint32_t*)(B+wv+i)));
        std::fprintf(stderr,"[vwatch] wav 0x%X: %s\n",wv,wb);
      }
    } }
}
static void rt_audio_worker_main(uint8_t* B){
  t_on_audio_worker=true;
  PPCContext c{}; rt_setup_thread_ctx(c,B);
  rt_audio_worker_init();
  std::fprintf(stderr,"  [audioworker] thread up: cb=0x%08X prime=%d\n",g_xaudio_cb,rt_audio_worker_prime_count());
  for(;;){
    if(!rt_audio_worker_wait_token()) break;   // blocks until the sink consumes a frame
    if(!g_xaudio_cb) continue;
    rt_audio_fire_cb_once(c,B);
    rt_voice_census(B);
  }
  std::fprintf(stderr,"  [audioworker] thread exiting\n");
}
static void rt_audio_worker_start(uint8_t* B){
  static std::once_flag once;
  std::call_once(once,[B](){
    std::thread(rt_audio_worker_main,B).detach();
    std::fprintf(stderr,"  [audioworker] started (RT_AUDIOWORKER pump-clock parity; vblank pump idle)\n");
  });
}
// Infinite-wait budget for the render-driver callback WHEN it runs on the worker thread.
// The vblank clamp (3ms) is too tight for the ~5.3ms engine-worker frame cadence; a
// dedicated thread can afford to block for the handshake. Bounded so a dead producer can
// never wedge the worker (worst case: the worker just produces slower). RT_AUDIOWORKER_WAITMS.
static int64_t rt_audio_worker_waitus(){
  static int64_t v = [](){ const char* e=getenv("RT_AUDIOWORKER_WAITMS"); long ms=e?atol(e):16;
                           if(ms<1)ms=1; if(ms>500)ms=500; return (int64_t)ms*1000; }();
  return v;
}

// RT_VOICESTART residual check (2026-07-25 pump-clock leg): CreateSourceVoice sub_821000A0
// is the concrete "a source voice was created/attached" signal. The SDK referee measured
// every in-memory voice create from lr=0x820F344C. This hook logs each call (lr + key regs)
// so we can confirm the in-memory BGM looping voice actually STARTS in the port — BEFORE
// attributing silence to the pump clock. Default-OFF => pure pass-through, byte-identical.
// ★ RT_LOADPROBE (2026-07-27, FNF-12 evidence leg — decomp: force_intro_0727.txt / ATLAS_scene
// §8): sub_821CD4B0 builds the NOW-LOADING overlay's element records onto its incoming task
// context r3 (the FUN_8207c978 "call" in the decomp is savegpr millicode — r3 passes through):
// ctx+0x4C/+0x50/+0x58/+0x5C hold the element/movie objects, each with the +0x0C HIDE byte the
// dismissal contract rides on (built: +0x58 -> hide=0 SHOWN, +0x5C -> hide=1 HIDDEN). This
// probe captures the pointers at build and a 250ms watcher thread logs every +0x0C transition,
// answering WHO (if anyone) ever re-hides the loading element in our port. Default-OFF =>
// byte-identical pass-through.
PPC_FUNC_IMPL(__imp__sub_821CD4B0);
static std::atomic<uint32_t> g_ldElem[4];
PPC_FUNC(sub_821CD4B0){
  uint32_t tctx = ctx.r3.u32;
  __imp__sub_821CD4B0(ctx,base);
  static bool on = getenv("RT_LOADPROBE") && atoi(getenv("RT_LOADPROBE"))!=0;
  if(on && tctx){
    // OFFSETS CORRECTED (2026-07-28, decomp round 2 — NOTE_fnf12_loading_overlay.md): the real
    // ELEMENTS are ctx+0x5C(loading/now_loading)/+0x60(connecting)/+0x64(accessing)/+0x68
    // (replay); +0x4C/+0x50 are list nodes and +0x58 is the container (its +0x0C=0 is correct
    // forever) — the first probe's readings on those carried no signal. Watch hide +0x0C AND
    // the packed colour +0xFC (low byte = the per-element ALPHA that is the real dismissal).
    uint32_t p[4] = { rt_be32(base,tctx+0x5c), rt_be32(base,tctx+0x60),
                      rt_be32(base,tctx+0x64), rt_be32(base,tctx+0x68) };
    std::fprintf(stderr,"[loadprobe] built ctx=0x%X elems loading=0x%X connecting=0x%X accessing=0x%X replay=0x%X\n",
                 tctx,p[0],p[1],p[2],p[3]);
    for(int i=0;i<4;i++) g_ldElem[i].store(p[i]);
    static std::once_flag once;
    std::call_once(once,[base]{ std::thread([base]{
      uint8_t lastH[4]={0xEE,0xEE,0xEE,0xEE}; uint32_t lastC[4]={1,1,1,1};
      for(;;){ std::this_thread::sleep_for(std::chrono::milliseconds(250));
        for(int i=0;i<4;i++){ uint32_t q=g_ldElem[i].load(); if(!q||q>=0x20000000u) continue;
          uint8_t h=*(base+q+0xC); uint32_t c=rt_be32(base,q+0xFC);
          if(h!=lastH[i]||c!=lastC[i]){ lastH[i]=h; lastC[i]=c;
            std::fprintf(stderr,"[loadprobe] elem%d(0x%X) hide=%u colorFC=0x%08X (alpha=%u)\n",
                         i,q,h,c,c&0xFFu); } } }
    }).detach(); });
  }
}
// ★ RT_LOADPROBE2 (2026-07-28, flicker-truth workflow wf_e3c67137 probe spec — DEFAULT OFF):
// event-driven, ms-stamped tracing of the NOW-LOADING indicator cluster. The 250ms-sampled
// RT_LOADPROBE above is BLIND to sub-250ms pulses; the workflow verdict says the M2 flicker is
// the accessing/connecting indicator element shown for the exact lifetime of a kind-tagged async
// task (loading itself is structurally one-shot). These hooks catch every show/hide call with the
// caller LR (0x821CD474 = the legit boot show; sub_821BD670/BD5B8-range = task show/hide) and
// every async-task ctor/dtor with kind + name + lifetime — one cold boot with RT_LOADPROBE2=1
// names the creator and proves multi-frame pendency. No instrumented-boot visual judgments!
static bool lp2_on(){ static bool on = getenv("RT_LOADPROBE2") && atoi(getenv("RT_LOADPROBE2"))!=0; return on; }
static double lp2_ms(){ static auto t0 = std::chrono::steady_clock::now();
  return std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-t0).count(); }
#define LP2_SHOWHIDE(NAME) \
  PPC_FUNC_IMPL(__imp__##NAME); \
  PPC_FUNC(NAME){ \
    if(!lp2_on()){ __imp__##NAME(ctx,base); return; } \
    uint32_t self=ctx.r3.u32, arg=ctx.r4.u32, lr=(uint32_t)ctx.lr; \
    uint8_t b0=self?*(base+self+0x71):0xEE, b1=self?*(base+self+0x72):0xEE, b2=self?*(base+self+0x73):0xEE; \
    __imp__##NAME(ctx,base); \
    uint8_t a0=self?*(base+self+0x71):0xEE, a1=self?*(base+self+0x72):0xEE, a2=self?*(base+self+0x73):0xEE; \
    std::fprintf(stderr,"[lp2] t=%.1fms %s self=0x%X r4=0x%X lr=0x%08X en71/72/73 %u%u%u -> %u%u%u\n", \
                 lp2_ms(), #NAME, self, arg, lr, b0,b1,b2, a0,a1,a2); \
  }
LP2_SHOWHIDE(sub_821CCC48)
LP2_SHOWHIDE(sub_821CC9A8)
LP2_SHOWHIDE(sub_821CCAF8)
// ⚠ The TASK ctor/dtor lane (sub_821BD670/sub_821BD5B8) does NOT live here: those symbols have
// strong wrappers in out_reco/merged/merged_xex.cpp which link FIRST (/FORCE:MULTIPLE keeps the
// first definition) — a duplicate here is SILENTLY DEAD (review wf_ea22499a, all 3 lenses; the
// audio-arc shadowed-hook landmine). The [lp2] TASK-CTOR/TASK-DTOR logging is folded into the
// merged_xex wrappers themselves.
// ★ [modeidx] (2026-07-28, task #23 / alpha-1 gate — decomp ATLAS_scene_system §8): the GAME
// SELECT fold stores modeIdx = titleIdx*2 + sub (sub: arcade_front menu answer) via
// sub_821C3F38(mem, modeIdx) -> parked at driverObj+0x68. EVEN = ARCADE, ODD = XBOX 360 mode
// for the selected title (Ver1.5 = title 0 => 0 arcade / 1 x360). Always-on one-line log per
// call (rare: once per game entry) so every boot names the mode it actually launched — answers
// the user's "are we loading the 360 one?" question per session, permanently.
PPC_FUNC_IMPL(__imp__sub_821C3F38);
PPC_FUNC(sub_821C3F38){
  uint32_t mi = ctx.r4.u32;
  std::fprintf(stderr,"[modeidx] sub_821C3F38 modeIdx=%u (%s, title=%u) lr=0x%08X\n",
               mi, (mi & 1u) ? "XBOX-360 MODE" : "ARCADE", mi >> 1, (uint32_t)ctx.lr);
  __imp__sub_821C3F38(ctx,base);
}
// ★ CODE_REVIEW_0804 C11: the RT_VOICESTART / RT_VOICESTART2 probe wrappers that lived here
// (sub_821000A0, sub_821009E0, sub_820F7F88) are DELETED. All three symbols are also defined
// in merged_shell.cpp, which links FIRST under /FORCE:MULTIPLE — these probes could never fire.
// An instrument that silently loses the link reads as "path not taken" (the exact landmine the
// ledger warns about). The hunts they served (voice-start attribution, shot-SFX ghosts) closed
// 08-03/04 via the thread-id fix; if a future hunt needs them, put the probe INSIDE the
// merged_shell definitions (the link winners).
// RT_VOICESTART2 (2026-07-25 voice-start leg): sub_821000A0 fires 0x in BOTH training and
// credited-join fields yet SE audibly plays -> voices must be created via the RENDERER
// CreateSourceVoice sub_820FEA40 through a caller OTHER than sub_821000A0. Hook it directly
// (catches every virtual dispatch through renderer vt+0x10=0x820F06C8, regardless of caller)
// and log the lr so the alternate SE voice path is named. Also hook the wave-START gate
// sub_820F7F88 to log the per-instance state (+0x58 must==3 to attach; <4 sets defer flag
// +0x3c|0x40) + send-list head — the field where the BGM wave diverges from the SE wave.
// Default-OFF => pure pass-through, byte-identical to no-env.
// Hook the renderer vt+0x10 CreateSourceVoice slot (FUN_820F06C8) itself, so lr = the TRUE
// caller. sub_820FEA40 (one level down) always shows lr=0x820F0A64 (internal), useless for
// path attribution. FUN_820F06C8 is documented reachable only via FUN_821000A0 (source-voice
// vt+0x90) — but that fires 0x while voices DO get created, so the caller lr here NAMES the
// alternate voice path the port actually uses (the one BGM should also take).
PPC_FUNC_IMPL(__imp__sub_820F06C8);
PPC_FUNC(sub_820F06C8){
  static bool on = getenv("RT_VOICESTART2")!=nullptr;
  if(on){
    static std::atomic<long> rn{0}; long v=rn.fetch_add(1)+1;
    std::fprintf(stderr,"  [rvoice] renderer.CreateSourceVoice #%ld caller_lr=0x%08X r3=0x%08X r4=0x%08X r5=0x%08X r6=0x%08X r7=0x%08X\n",
                 v,(unsigned)(uint32_t)ctx.lr,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,
                 (unsigned)ctx.r5.u32,(unsigned)ctx.r6.u32,(unsigned)ctx.r7.u32);
  }
  __imp__sub_820F06C8(ctx,base);
}
// (sub_821009E0 [svoice] and sub_820F7F88 [wavestart] probe wrappers deleted — both symbols
//  lose the /FORCE:MULTIPLE link to merged_shell.cpp's definitions, so these probes could never
//  fire; see the C11 note above. sub_820F06C8 above is NOT duplicated and stays live.)
// rt_mftb (2026-07-17 attract task-starvation fix): the recompiler emitted guest `mftb` as raw
// __rdtsc(). The x86 TSC ticks at the CPU base clock (~GHz); the Xbox 360 timebase ticks at
// 49.875MHz — so every guest elapsed-ticks measurement read ~70x too large. Measured casualty:
// the ROM's time-budgeted task scheduler (game module, the two mftb sites in
// out_reco/ppc_recomp.3.cpp: stamp @+16/+20, then elapsed-compare) saw its per-frame time budget
// instantly exhausted and STARVED the attract task family to ~6-10 ticks/s against a healthy
// ~60Hz ROM render loop ([tickrate] gamekick 67/s vs glyphstep 6.3/s) — the whole attract ran
// ~6-10x slow (legal 87s vs the oracle's ~10s). QPC rescaled to 49.875MHz restores real
// timebase semantics for all 16 emitted mftb sites (both trees). RT_MFTB_RAW=1 restores rdtsc.
extern "C" unsigned long long rt_mftb(void){
  static int raw = getenv("RT_MFTB_RAW") ? atoi(getenv("RT_MFTB_RAW")) : 0;
  if(raw) return __builtin_ia32_rdtsc();
  static const std::chrono::steady_clock::time_point t0 = std::chrono::steady_clock::now();
  unsigned long long us = (unsigned long long)std::chrono::duration_cast<std::chrono::microseconds>(
      std::chrono::steady_clock::now() - t0).count();
  return us * 49875ULL / 1000ULL;   // 49.875 ticks/us; overflow-safe for ~11 years of uptime
}
static bool rt_kick_on(){ static bool on=getenv("RT_KICK")!=nullptr; return on; }
static void rt_kick_service_event(uint8_t* B){
  uint32_t sing=rt_be32(B,0x821F857Cu);
  if(!sing) return;
  uint32_t h=rt_be32(B,sing+568);
  if(!h) return;
  static bool logged=false;
  if(!logged){ logged=true; std::fprintf(stderr,"  [kick] pumping service event h=0x%08X\n",h); }
  PPCContext k{}; k.r3.u64=h; k.r4.u64=0;
  __imp__NtSetEvent(k,B);
}
PPC_FUNC_IMPL(__imp__VdSetGraphicsInterruptCallback){ LOGN("VdSetGraphicsInterruptCallback");
  g_vd_cb=ctx.r3.u32; g_vd_cb_ctx=ctx.r4.u32;
  std::fprintf(stderr,"  [vblank] registered cb=0x%08X ctx=0x%08X%c",(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,10);
  static std::atomic<bool> started{false};
  if(!started.exchange(true)){
    uint8_t* B=base;
    std::thread([B](){
      PPCContext c{}; rt_setup_thread_ctx(c,B);
      static bool kick_on=rt_kick_on();
      // RT_SIGEV=<hex guest event handle>: signal this event every vblank tick. Diagnostic
      // lever for "game main waits on a frame event nobody signals" (e.g. the msg-2 FDF8
      // event array 0x885C651C — game main wait-any's {idx3=0x50000028, idx4=0x5000002C}).
      static uint32_t sigev = [](){ const char* e=getenv("RT_SIGEV"); return e?(uint32_t)strtoul(e,nullptr,16):0u; }();
      // --- 59.94Hz vblank pacing (2026-07-16) ---------------------------------------------------
      // This loop USED to be `sleep_for(2ms)` per iteration. On Windows that lands on the DEFAULT
      // ~15.6ms timer granularity (nothing called timeBeginPeriod), so the guest's vblank fired at
      // ~64Hz BY ACCIDENT rather than at the console's 59.94Hz. RT_GAMEPUMP ticks the game from
      // inside VdSwap, so vblank rate == GAME LOGIC SPEED, and the port was never running at the
      // right speed: measured 62.5 presents/sec uncapped (== 1000/16, the granularity showing
      // through), and under FIFO vsync that ~64Hz producer beats against the 60Hz refresh and
      // collapses to ~32fps = HALF SPEED. Proof it was granularity and not design: forcing
      // timeBeginPeriod(1) took the same build to ~150 presents/sec (2.5x console speed).
      // Fix = 1ms timer resolution (above) + an ABSOLUTE deadline so jitter cannot accumulate into
      // drift. Everything in the loop body keeps its per-iteration (== per-vblank) behavior and the
      // rate only moves ~64Hz -> 59.94Hz, so the `s%64` "once/s" assumptions below still hold, and
      // the RT_AUDIOPUMP call keeps being paced by its own rt_audio_can_accept() gate as before.
      //   RT_VBLANK_HZ=<float>  override the rate (default 59.94 = NTSC, what this game shipped at)
      //   RT_VBLANK_LEGACY=1    restore the old sleep_for(2ms) behavior (regression escape hatch)
      rt_timer_precision_begin();
      static double vb_hz = [](){ const char* e=getenv("RT_VBLANK_HZ"); double v=e?atof(e):59.94;
                                  return (v>1.0&&v<1000.0)?v:59.94; }();
      static bool vb_legacy = getenv("RT_VBLANK_LEGACY")!=nullptr;
      const auto vb_period = std::chrono::nanoseconds((long long)(1e9/vb_hz));
      auto vb_next = std::chrono::steady_clock::now() + vb_period;
      std::fprintf(stderr,"  [vblank] pacing %.2f Hz (%.3f ms/frame)%s\n",
                   vb_hz, 1000.0/vb_hz, vb_legacy?"  [LEGACY sleep_for(2ms) -- pacing WILL be wrong]":"");
      for(;;){
        if(vb_legacy) std::this_thread::sleep_for(std::chrono::milliseconds(2));
        else {
          std::this_thread::sleep_until(vb_next);
          auto vb_now=std::chrono::steady_clock::now();
          vb_next += vb_period;
          // Debt banking (2026-07-17 attract-pacing): the old clamp reset the deadline on ANY
          // overrun, so a single slow iteration (guest ISR/audio work >16.7ms) permanently lost
          // that vblank AND rephased — sustained ~2-3ms-over spikes cap the effective rate at
          // ~50Hz. Bank up to RT_VBDEBT periods of debt (default 4): sleep_until returns
          // immediately while behind, so the next iterations burst to catch up and the AVERAGE
          // holds 59.94Hz. Debt beyond the cap (a real stall — debugger, page-fault storm) is
          // still forgiven so it cannot flood a burst of stale frames. RT_VBDEBT=0 = old clamp.
          static long vb_debt_max = [](){ const char* e=getenv("RT_VBDEBT"); long v=e?atol(e):4;
                                          return (v>=0&&v<=32)?v:4; }();
          if(vb_next < vb_now - vb_debt_max*vb_period){
            static std::atomic<long> vb_forgiven{0}; long fg=vb_forgiven.fetch_add(1)+1;
            if(fg<=3||(fg%600)==0) std::fprintf(stderr,"  [vblank] stall: deadline forgiven #%ld (debt>%ldT)%c",fg,vb_debt_max,10);
            vb_next = vb_now + vb_period;
          }
        }
        if(kick_on) rt_kick_service_event(B);
        if(sigev){ static bool logged=false; if(!logged){ logged=true; std::fprintf(stderr,"  [sigev] signaling 0x%08X each vblank\n",sigev); }
          PPCContext k{}; k.r3.u64=sigev; __imp__NtSetEvent(k,B); }
        // RT_SIGEV2: second per-vblank signal (diagnostic — e.g. wake the parked streaming
        // worker at *(0x887ACD30) to observe what it drains; see merged RT_PUMPFIX notes).
        static uint32_t sigev2 = [](){ const char* e=getenv("RT_SIGEV2"); return e?(uint32_t)strtoul(e,nullptr,16):0u; }();
        if(sigev2){ static bool logged2=false; if(!logged2){ logged2=true; std::fprintf(stderr,"  [sigev2] signaling 0x%08X each vblank\n",sigev2); }
          PPCContext k{}; k.r3.u64=sigev2; __imp__NtSetEvent(k,B); }
        // ---- CUE-LIFETIME MIRROR (2026-07-31): stop the host music stream exactly when the guest's
        // own cue instance ends. The shell never calls any XACT Stop for its menu BGM (traced:
        // SoundBank::Stop 0x820EF018, the engine walker 0x820E8B98, cue Stop 0x820EC958 and the
        // voice stop 0x820F80B0 ALL fire 0x across a full mode-select) — it ends the music by
        // destroying the cue instance. So we mirror IXACT3Cue::GetState (FUN_820ecac8) verbatim:
        //     inst = *(cue+0x38); inst == 0                  => STOPPED
        //     st   = *(inst+0x58); st outside 1..5           => STOPPED
        // plus the identity words the engine's own stop-walker matches on (bank at cue+0x134,
        // cueIndex at cue+0x13C) so a recycled or freed object can never read as "still playing".
        // Guest data, guest timing; no host-side timer and no synthetic fade. RT_CUESTOP=0 disables.
        {
          unsigned bankPtr=0; int cueIdx=-1;
          uint32_t co = rt_audio_bridge_music_cueobj(&bankPtr,&cueIdx);
          if(co && co<0xF0000000u){
            uint32_t inst = rt_be32(B, co+0x38u);
            int alive = 0;
            if(inst && inst<0xF0000000u){
              uint32_t st = rt_be32(B, inst+0x58u);
              uint32_t bk = rt_be32(B, co+0x134u);
              uint32_t ci = rt_be32(B, co+0x13Cu) >> 16;      // u16 at +0x13C (big-endian half)
              alive = (st>=1u && st<=5u) && bk==bankPtr && (int)ci==cueIdx;
            }
            rt_audio_bridge_music_liveness(co, alive);
          }
        }
        // RT_AUDIOPUMP: drive the registered XAudio render-driver client. On HW the audio
        // engine invokes it every 256 samples (~5.3ms); XACT wave-bank preparation (and the
        // shell's boot phase-3 sound-bank completion) only advances from inside it. ABI per
        // rexglue audio_system.cpp RegisterClient/pump: callback(r3 = ptr to a 4-byte BE
        // cell holding the registered callback_arg).
        {
          static bool audpump = getenv("RT_AUDIOPUMP")!=nullptr;
          if(rt_audio_worker_on()){
          // RT_AUDIOWORKER: the render-driver callback is clocked by a dedicated,
          // consumption-paced worker thread (pump-clock parity). Start it once the
          // client is registered; do NOT fire it here — that would double-drive the mixer.
          if(audpump && g_xaudio_cb) rt_audio_worker_start(B);
          } else {
          // rt_audio_can_accept (rt_audio.cpp, decl at file scope above): ring-depth pacing
          // gate — always 1 unless RT_AUDIO=1, where it holds the callback while the live
          // backend's ring is full so the guest mixes at consumption rate (~187.5Hz).
          // RT_AUDIOPUMP_HZ=<float> (2026-07-17 attract-pacing): on HW the audio engine invokes
          // this client every 256 samples = 48000/256 = 187.5Hz, ~3.13x per 59.94Hz vblank. We
          // fired it ONCE per vblank (~60Hz), so every clock derived from mix progress — XACT cue
          // position, music-synced screen timers — ran ~3x slow; the ROM attract's screen
          // durations (legal/ranking) measured ~6x long vs the SDK oracle (compounded by sub-60
          // capture fps). With HZ set, an accumulator fires the callback floor(acc) times per
          // vblank (3,3,3,4,...) so mix progress tracks wall clock; the rt_audio_can_accept gate
          // still bounds each call when the live backend is on. Unset = legacy 1/vblank.
          // Default 187.5 (2026-07-17 attract-1:1): the HW rate — the audio engine invokes the
          // client every 256 samples at 48kHz. Every verified pacing run uses it; audio-derived
          // clocks (XACT cues, music-synced screen timers) are ~3x slow without. RT_AUDIOPUMP_HZ=0
          // restores the legacy 1/vblank cadence.
          static double ap_hz = [](){ const char* e=getenv("RT_AUDIOPUMP_HZ"); double v=e?atof(e):187.5;
                                      return (v>0.0&&v<=2000.0)?v:0.0; }();
          static double ap_acc = 0.0;
          int ap_fires = 1;
          if(ap_hz>0.0){ ap_acc += ap_hz/vb_hz; ap_fires = (int)ap_acc; ap_acc -= (double)ap_fires; }
          for(int fi=0; fi<ap_fires; ++fi){
            if(!(audpump && g_xaudio_cb && rt_audio_can_accept())) break;
            // RT_XACTDOWORK (register-true SHIP-fix component, default-OFF pending completion; =1 to
            // A/B): pump the XACT3 engine's
            // DoWork = IXACT3Engine::DoWork = engine(DAT_887ad50c=0x360BD0)->vtable[+0x1c] = 0x820E8F88.
            // On HW XACT's internal audio worker thread drives DoWork every few ms; the port dropped
            // that thread, so NOTHING serviced the streaming/voice-create step — prepared PCM cues
            // (crux sub_88090588 PREPARE ok) never got their ring (0x11891000) filled from the staged
            // .xwb nor a source voice created/started/routed into the ticked submix (0x36A090) ->
            // digital silence (Phase-3 B1 verdict). Driving DoWork lets prepared cues self-materialize
            // a real XACT source voice (volume/category/loop/DSP all authentic) with NO host bridge.
            // Run it on the audiopump thread, right BEFORE the mix callback below, so the engine is
            // serviced then the XAudio2 mix reads the voices (XACT DoWork is single-threaded; the
            // engine's own critical sections guard concurrent notification/prepare on other threads).
            // Guard: non-null engine (mirrors the guest's own `if(DAT_887ad50c)` gate) => no-op pre-init.
            {
              // DEFAULT-OFF: driving DoWork is register-true and advances streaming (ring fills), but
              // ALONE it is not yet audible — the wave Play's source-voice create+submix-attach still
              // dead-ends (Phase-3b B1-plus). Keep the tree byte-identical without the env until that
              // second half lands; enable with RT_XACTDOWORK=1 to A/B the streaming advance.
              static int xdw = [](){ const char* e=getenv("RT_XACTDOWORK"); return (e && atoi(e)!=0)?1:0; }();
              if(xdw){
                uint32_t eng = rt_be32(B, 0x887AD50Cu);
                if(eng && eng < 0xF0000000u){
                  if(PPCFunc* dw = rt_lookup(B, 0x820E8F88u)){
                    c.r3.u64 = eng; dw(c,B);
                    uint32_t ret = c.r3.u32;
                    static std::atomic<long> dn{0}; long d=dn.fetch_add(1)+1;
                    // B1-plus dead-end trace (RT_AUDIOCRUX): does DoWork EVER fill the wave ring or
                    // attach a source voice to the ticked submix (0x372F10)? Scan over time.
                    if(getenv("RT_AUDIOCRUX") && (d<=3||(d%4000)==0)){
                      uint32_t wt=rt_be32(B,0x887AD504u);
                      uint32_t ring=(wt&&wt<0xF0000000u)?rt_be32(B,wt+12):0;
                      int nz=0; if(ring&&ring<0xF0000000u){ for(int b=0;b<16384;b+=4) if(rt_be32(B,ring+(uint32_t)b)) nz++; }
                      uint32_t sub=0x372F10u, ch=rt_be32(B,sub+556); int cc=0; uint32_t nd=ch;
                      while(nd&&nd<0xF0000000u&&cc<64){ nd=rt_be32(B,nd+4); ++cc; }
                      std::fprintf(stderr,"  [xactdowork] #%ld ret=0x%X engine=0x%X ring=0x%X nz=%d/4096 submix0x372F10.children=%d\n",d,ret,eng,ring,nz,cc);
                    } else if(d<=3){
                      std::fprintf(stderr,"  [xactdowork] DoWork(0x820E8F88) engine=0x%X ret=0x%X #%ld\n", eng, ret, d);
                    }
                  }
                }
              }
            }
            static uint32_t argcell = 0;
            if(!argcell){ argcell = rt_alloc(4,4); *(uint32_t*)(B+argcell)=__builtin_bswap32(g_xaudio_cb_ctx); }
            if(PPCFunc* afn=rt_lookup(B,g_xaudio_cb)){
              static std::atomic<long> an{0}; long a=an.fetch_add(1)+1;
              if(a<=3||a==500) std::fprintf(stderr,"  [audiopump] firing #%ld cb=0x%08X argcell=0x%X (*=0x%X) hz=%.1f\n",a,g_xaudio_cb,argcell,g_xaudio_cb_ctx,ap_hz);
              c.r3.u64=argcell; afn(c,B);
            }
          }
          } // end else (legacy vblank audiopump)
        }
        if(rvk_ringprobe() && g_d3d_device){ // LEG-27/40: observe dev+0x30 motion between presents
          static uint32_t rp_prev=0;
          uint32_t rp_cur=rt_be32(B,g_d3d_device+0x30);
          if(rp_prev && rp_cur!=rp_prev){ g_rp_moves++; if(rp_cur<rp_prev) g_rp_back++; }
          uint32_t rp_mx=g_rp_maxcur.load();
          while(rp_cur>rp_mx && !g_rp_maxcur.compare_exchange_weak(rp_mx,rp_cur)) {}
          rp_prev=rp_cur;
        }
        static std::atomic<int> shots{0}; int s=shots++;
        if(s%64==5){ // once/s: scan GPU MMIO block for registers the game wrote
          for(uint32_t off=0;off<0x8000;off+=4){ uint32_t v=rt_be32(B,0x7FC80000+off);
            if(v) std::fprintf(stderr,"  [mmio] +0x%04X = 0x%08X%c",off,v,10); } }
        if(s==1500||s==2500||s==4000) rt_dump_tree(B,"idle");
        uint32_t wb=g_wb_addr.load();
        if(wb){ // null GPU: CP has always caught up — read pointer := write pointer
          uint32_t wptr=rt_be32(B,0x7FC80714);
          *(uint32_t*)(B+wb)=__builtin_bswap32(wptr); }
        uint32_t pctx=g_vd_cb_ctx.load();
        if(pctx){ // null GPU: retire all queued work — fence := newest sequence
          uint32_t fptr=rt_be32(B,pctx+10896), wr=rt_be32(B,pctx+10908);
          if(fptr&&fptr<0x40000000u) *(uint32_t*)(B+fptr)=__builtin_bswap32(wr); }
        uint32_t cb=g_vd_cb.load(); if(!cb) continue;
        PPCFunc* fn=rt_lookup(B,cb); if(!fn) continue;
        if(s<3||s==60) std::fprintf(stderr,"  [vblank] firing #%d cb=0x%08X%c",s,cb,10);
        // RT_VBISR (2026-07-17 attract-pacing, default ON, =0 reverts): make the source-0 fire
        // reach the REAL vblank ISR. sub_820A7DF8's vblank branch is
        //     if (src==0 && (_DAT_7fc86544 & 1)) sub_820A4C08(dev);
        // and nothing in the port ever set display-interrupt-status bit0 at 0x7FC86544 — so for
        // the port's whole life the source-0 fire was a NO-OP: dev.vblankCount(+0x4174) never
        // ticked, queued swaps never retired (+0x4188), and the swap callback slot (+0x4170,
        // = sub_8216AD38, registered via sub_820A4F78) was never invoked with real args. The
        // shell main loop (sub_821706E8 -> FUN_8216ea68 -> sub_8216B148 mode-1 gate) busy-spins
        // on DAT_821F8550 changing, which ONLY sub_8216AD38 writes; on HW that chain fires at
        // 59.94Hz unconditionally. Setting the bit lets the authentic chain run every vblank.
        static bool vbisr = !(getenv("RT_VBISR") && atoi(getenv("RT_VBISR"))==0);
        uint32_t devp=g_vd_cb_ctx.load();
        uint32_t vbc_pre = (vbisr&&devp)?rt_be32(B,devp+0x4174):0;
        if(vbisr){ uint32_t dis=rt_be32(B,0x7FC86544);
          if(!(dis&1)) *(uint32_t*)(B+0x7FC86544)=__builtin_bswap32(dis|1); }
        c.r3.u64=0; c.r4.u64=devp; fn(c,B);          // vblank
        c.r3.u64=1; c.r4.u64=devp; fn(c,B);          // CP interrupt
        // Fallback raw tick: before the device/swap-callback registration exists the real ISR
        // can't run, but the boot spin in sub_8216B148 still needs DAT_821F8550 to move. Only
        // fire it when the real chain did NOT advance vblankCount this tick (with RT_VBISR=0
        // this is always taken = the legacy behavior).
        bool isr_ran = vbisr && devp && rt_be32(B,devp+0x4174)!=vbc_pre;
        if(vbisr && isr_ran){ static bool once=false;
          if(!once){ once=true; std::fprintf(stderr,"  [vbisr] real vblank ISR chain LIVE: dev=0x%08X vbc=%u swc=%u swapcb=0x%08X 8550=0x%08X%c",
            devp,rt_be32(B,devp+0x4174),rt_be32(B,devp+0x4188),rt_be32(B,devp+0x4170),rt_be32(B,0x821F8550),10); } }
        if(!isr_ran){ if(PPCFunc* tick=rt_lookup(B,0x8216AD38)) tick(c,B); }
        // RT_GAMEPUMP_VBLANK (2026-07-17 attract-pacing DECOUPLING): the game's logic clock is
        // the GameEntry(msg=5) handshake (ROM: sub_8808FB90 waits event 0x885C6528, granted by
        // sub_8808FA68 from the msg-5 handler). The msg-5 pump lived only in the VdSwap impl —
        // i.e. on the SHELL PRESENT PATH — so game logic ran at the legacy renderer's present
        // rate (~10-15fps during the ROM attract; measured chain: render tail ~45ms + decode
        // ~20ms -> presents 10/s -> msg-5 10/s -> task family 6-10/s -> the whole attract 6-10x
        // slow). Hardware granted the tick per VBLANK. Pump it HERE, on the 59.94Hz vblank
        // thread, so logic runs at console speed regardless of how fast we render. The VdSwap
        // pump is skipped while this is on (double-granting would run logic >60Hz).
        {
          static bool vbpump = getenv("RT_GAMEPUMP_VBLANK")!=nullptr;
          if(vbpump && g_game_tick_modectx){
            static thread_local bool in_vbpump=false;
            if(!in_vbpump){
              in_vbpump=true;
              PPCContext pc2{}; rt_setup_thread_ctx(pc2,B); pc2.r3.u32=g_game_tick_modectx;
              __imp__sub_821C8DA8(pc2,B);
              in_vbpump=false;
              rt_fsmlog(B,"vbl");   // vblank-path pump: FSM timers tick at the fixed 59.94Hz

              static std::atomic<long> vp{0}; long v=vp.fetch_add(1)+1;
              if(v<=3||(v%600)==0) std::fprintf(stderr,"  [vbpump] msg5 tick #%ld @59.94Hz%c",v,10);
            }
          }
        }
        // (08-12 tick/present decoupling: the frame grant was FIRST tried here on the vblank
        // thread — but FA68 BLOCKS on the game's ack, monopolizing this thread and starving the
        // present/audio/graphics-int duties it also drives (measured: presents collapsed to
        // ~0.4/s). The grant now lives on a DEDICATED frame-clock thread started below, so this
        // thread keeps its cadence. See g_frameclock_* + rt_frameclock_present_skip.)
        // RT_FSMLOG independent 60Hz sampler: the select FSM state block is sampled from the vblank
        // thread every tick REGARDLESS of where the game is actually pumped (present-path RT_GAMEPUMP,
        // vblank RT_GAMEPUMP_VBLANK, or the natural vbisr/shell chain). This is the decoupling probe:
        // it timestamps FSM state (wall-ms) alongside the global present counter, so a window snap
        // taken at a known wall-ms can be checked against the FSM state at that same instant.
        { static bool mreport=false; if(!mreport){ mreport=true;
            std::fprintf(stderr,"[fsmlog] g_game_tick_modectx=0x%08X RT_GAMEPUMP=%s RT_GAMEPUMP_VBLANK=%s%c",
              g_game_tick_modectx, getenv("RT_GAMEPUMP")?"1":"0", getenv("RT_GAMEPUMP_VBLANK")?"1":"0",10); }
          rt_fsmlog(B,"s60"); rt_reveallog(B); }
      }
    }).detach();

    // ★ DEDICATED FRAME-CLOCK THREAD (2026-08-12 tick/present decoupling). Started once alongside
    // the vblank pump; idles until armed. When armed it paces the ABN frame grant (sub_8808FA68:
    // set frame event + BLOCK on the game's ack) at 59.94Hz on ITS OWN thread, so the blocking
    // ack-wait never touches the vblank/present/audio thread. An absolute deadline prevents drift;
    // if a game frame runs long (>16.68ms) the clock degrades gracefully (no debt accumulation),
    // exactly as the console's vblank-paced logic would. The context is set up ONCE and reused —
    // rt_setup_thread_ctx allocates a fresh guest stack per call (~256KB), so per-grant setup would
    // leak; FA68 restores r1 (stwu/addi net-zero) so reuse is safe.
    // ⚠ LEVER-GATED CREATION (08-12): only spawn this thread when the lever is on. With it off
    // (ship default / swapbounce), creating an idle extra thread perturbed the thread-count gate
    // (P4 18/19). Default-off must be byte-for-behavior identical to before the frameclock existed.
    if(getenv("RT_FRAMECLOCK_VBLANK") && atoi(getenv("RT_FRAMECLOCK_VBLANK"))!=0)
    std::thread([B](){
      PPCContext fc{}; rt_setup_thread_ctx(fc,B);
      typedef void (*FrameGrantFn)(PPCContext&, uint8_t*);
      extern std::atomic<int> g_frameclock_armed;
      extern std::atomic<void*> g_frameclock_grantfn;
      const auto period = std::chrono::nanoseconds(16683350);   // 1/59.94 s
      auto next = std::chrono::steady_clock::now();
      long long n=0;
      for(;;){
        if(!g_frameclock_armed.load(std::memory_order_acquire)){
          std::this_thread::sleep_for(std::chrono::milliseconds(2));
          next = std::chrono::steady_clock::now();               // reset cadence on re-arm
          continue;
        }
        void* gf = g_frameclock_grantfn.load(std::memory_order_acquire);
        if(!gf){ std::this_thread::sleep_for(std::chrono::milliseconds(1)); next=std::chrono::steady_clock::now(); continue; }
        // reset the guest stack pointer each grant (FA68 restores it, but a stale r1 from a
        // disarm/re-arm across a module swap must not leak downward)
        fc.r1.u64 = fc.r13.u64 + (0xAB0+0x100+0x2E0+0x40000);    // PCR+TLS+TEB+STK top (matches setup)
        ((FrameGrantFn)gf)(fc,B);                                // grant + block on game ack HERE
        ++n; if(n<=3||(n%600)==0) std::fprintf(stderr,"  [frameclock] grant #%lld @59.94Hz%c",n,10);
        next += period;
        auto now = std::chrono::steady_clock::now();
        if(next > now) std::this_thread::sleep_until(next);
        else next = now;                                         // fell behind: don't accumulate debt
      }
    }).detach();
  }
  ctx.r3.u32=0; (void)base; }
// ★ frame-clock ownership state (2026-08-12 tick/present decoupling). Armed = the DEDICATED
// frame-clock thread (above) owns the ABN frame grant; the present path's msg-5 handshake is
// skipped. Lever RT_FRAMECLOCK_VBLANK (default OFF while gating). The DLL reaches these through
// the generated host ABI (tools/gen_host_abi.py HELPERS).
std::atomic<int> g_frameclock_armed{0};
std::atomic<void*> g_frameclock_grantfn{nullptr};   // &sub_8808FA68 from the abn override (cross-module)
// grantfn: the game module's own frame-grant function (&sub_8808FA68), passed as void* so the
// generated host ABI stays free of PPC types. The dedicated thread casts it back and calls it.
extern "C" int rt_frameclock_present_skip(void* grantfn){
  static int on = -1;
  if(on<0){ const char* e=getenv("RT_FRAMECLOCK_VBLANK"); on=(e&&atoi(e)!=0)?1:0; }
  if(!on) return 0;                       // lever off: byte-identical behavior, grant stays put
  if(!g_frameclock_armed.load(std::memory_order_acquire)){
    g_frameclock_grantfn.store(grantfn,std::memory_order_release);   // publish BEFORE arming
    g_frameclock_armed.store(1,std::memory_order_release);
    std::fprintf(stderr,"  [frameclock] ARMED — dedicated thread owns the frame grant (grantfn=%p)\n", grantfn);
  }
  // ALWAYS skip the present-path grant once the lever is on (even the first call): the dedicated
  // thread owns ALL grants. If the present path also granted the first frame, two threads would
  // race the same frame/ack events. The frame event is a flag, not a rendezvous, so the dedicated
  // thread's grant is safe even before the game main enters its wait loop (the ack just lands late
  // on the first frame). Matches the proven RT_GAMEPUMP_VBLANK "skip the present pump" pattern.
  return 1;
}
extern "C" void rt_frameclock_disarm(const char* why){
  if(g_frameclock_armed.exchange(0)){
    g_frameclock_grantfn.store(nullptr,std::memory_order_release);
    std::fprintf(stderr,"  [frameclock] DISARM (%s)\n", why?why:"?");
  }
}
PPC_FUNC_IMPL(__imp__ExCreateThread){ LOGN("ExCreateThread");
  uint32_t hp=ctx.r3.u32, tip=ctx.r5.u32, start=ctx.r7.u32, sctx=ctx.r8.u32, flags=ctx.r9.u32;
  RtThread* th=new RtThread(); th->suspended=(flags&1)!=0; uint32_t h=rt_add(th); uint8_t* B=base;
  th->th=std::thread([th,B,start,sctx](){ { std::unique_lock<std::mutex> l(th->m); th->cv.wait(l,[&]{return !th->suspended.load();}); }
    PPCContext c{}; rt_setup_thread_ctx(c,B); c.r3.u64=sctx; PPCFunc* fn=rt_lookup(B,start); if(fn) fn(c,B); th->done=true; });
  th->th.detach();
  if(hp)*(uint32_t*)(base+hp)=__builtin_bswap32(h); if(tip)*(uint32_t*)(base+tip)=__builtin_bswap32(h); ctx.r3.u32=0; (void)base; }
PPC_FUNC_IMPL(__imp__NtResumeThread){ LOGN("NtResumeThread"); if(auto*t=dynamic_cast<RtThread*>(rt_get(ctx.r3.u32))){ {std::lock_guard<std::mutex> l(t->m); t->suspended=false;} t->cv.notify_all(); } ctx.r3.u32=0; (void)base; }
// ============================================================================================
// RT_PAIRTRACE (frame-pairing leg, layer 26, default-OFF) — instrument the render-driver client
// producer/consumer handshake. The transpose sub_821396C0 (consumer of 0x36FA90 / producer of the
// device frame) does, register-true (ppc_recomp.21:30926):
//   if(*(client+0x38)>0) KeSetEvent(*(client+0x28))                          // signal CONSUMED  [lr 0x821396F4]
//   KeWaitForMultipleObjects({*(client+0x30)=shutdown,*(client+0x2c)=ready}, ANY, NULL)  [lr 0x82139740]
//   if result==1(ready): read *(client+0x18)=0x36FA90 and XAudioSubmitRenderDriverFrame
// Answers: which registry each client event lives in + who creates it; does the transpose wait BLOCK
// on ready or free-run; does ANYONE wait on consumed (is the summer paced by consumption); real
// signal/wait rates + phase. Caller-lr tags: consumed-set 0x821396F4, transpose-wait 0x82139740,
// engine-worker-wait 0x821361C4. Zero cost / zero output unless RT_PAIRTRACE is set.
static bool rt_pt_on(){ static bool v=std::getenv("RT_PAIRTRACE")!=nullptr; return v; }
static const std::chrono::steady_clock::time_point g_pt_epoch = std::chrono::steady_clock::now();
static inline long rt_pt_us(){ return (long)std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now()-g_pt_epoch).count(); }
static int rt_pt_tid(){ static std::atomic<int> next{1}; thread_local int id=next.fetch_add(1); return id; }
static std::atomic<uint32_t> g_pt_consumed{0}, g_pt_ready{0}, g_pt_shutdown{0};
static const char* rt_pt_name(uint32_t k){
  if(k && k==g_pt_consumed.load()) return "CONSUMED+28";
  if(k && k==g_pt_ready.load())    return "READY+2c";
  if(k && k==g_pt_shutdown.load()) return "SHUTDN+30";
  return "other";
}
static std::mutex g_pt_mtx;
static void rt_pt_create_log(const char* reg, uint32_t key, int manual, int state, uint32_t lr){
  if(!rt_pt_on()) return; std::lock_guard<std::mutex> l(g_pt_mtx);
  static int n=0; if(n<80){ n++;
    std::fprintf(stderr,"[pairtrace] CREATE %s key/h=0x%08X manual=%d state=%d lr=0x%08X tid=%d us=%ld\n",
      reg,key,manual,state,lr,rt_pt_tid(),rt_pt_us()); }
}
static std::atomic<uint64_t> g_pt_set_consumed{0}, g_pt_set_ready{0}, g_pt_set_shutdown{0};
static std::atomic<long>     g_pt_ready_first{-1}, g_pt_ready_last{0};
static void rt_pt_setev_log(uint32_t k, uint32_t lr){
  if(!rt_pt_on()) return;
  if(lr==0x821396F4u && k) g_pt_consumed.store(k);   // capture consumed from the transpose set site
  uint32_t rc=g_pt_consumed.load(), rr=g_pt_ready.load(), rs=g_pt_shutdown.load();
  bool client=false;
  if(k && k==rc){ g_pt_set_consumed.fetch_add(1); client=true; }
  else if(k && k==rr){ if(g_pt_ready_first.load()<0) g_pt_ready_first.store(rt_pt_us()); g_pt_ready_last.store(rt_pt_us()); g_pt_set_ready.fetch_add(1); client=true; }
  else if(k && k==rs){ g_pt_set_shutdown.fetch_add(1); client=true; }
  const char* nm=rt_pt_name(k);
  std::lock_guard<std::mutex> l(g_pt_mtx);
  static uint32_t seen_lr[48]={0}; static int seen_n=0;
  bool s=false; for(int i=0;i<seen_n;i++) if(seen_lr[i]==lr) s=true;
  if(!s && seen_n<48){ seen_lr[seen_n++]=lr;
    std::fprintf(stderr,"[pairtrace] SETEV first-from lr=0x%08X key=0x%08X %s us=%ld tid=%d\n",lr,k,nm,rt_pt_us(),rt_pt_tid()); }
}
// transpose-wait phase histogram + summer-pacing counters
static std::atomic<uint64_t> g_pt_tw_imm{0}, g_pt_tw_blk{0}, g_pt_tw_tmo{0}, g_pt_tw_tot{0};
static std::atomic<uint64_t> g_pt_cw{0};        // KeWaitForMultipleObjects calls that INCLUDED consumed
static std::atomic<uint64_t> g_pt_cw_single{0}; // single-object waits on consumed
static std::atomic<long>     g_pt_tw_first{-1}, g_pt_tw_last{0};
PPC_FUNC_IMPL(__imp__NtCreateEvent){ LOGN("NtCreateEvent"); uint32_t hp=ctx.r3.u32,type=ctx.r5.u32,state=ctx.r6.u32;
  RtEvent*e=new RtEvent(); e->manual=(type==0); e->sig=(state!=0); uint32_t h=rt_add(e); if(hp)*(uint32_t*)(base+hp)=__builtin_bswap32(h);
  rt_pt_create_log("Nt(handle)",h,(int)e->manual,(int)e->sig,(uint32_t)ctx.lr); ctx.r3.u32=0; (void)base; }
PPC_FUNC_IMPL(__imp__KeInitializeEvent){ LOGN("KeInitializeEvent"); RtEvent*e=rt_ev(ctx.r3.u32,true); e->manual=(ctx.r4.u32==0); e->sig=(ctx.r5.u32!=0);
  rt_pt_create_log("Ke(addr)",ctx.r3.u32,(int)e->manual,(int)e->sig,(uint32_t)ctx.lr); ctx.r3.u32=0; (void)base; }
// ★ 2026-08-01 MULTI-WAIT WAKEUP GENERATION. KeWaitForMultipleObjects cannot wait on N per-event
// CVs at once, so it used to POLL at 300us — on the 5.33ms audio frame clock that is up to ~6% of
// a frame of wake-up jitter on the guest's audio threads, and jittered parameter/voice updates
// land as level-proportional steps exactly at frame seams (measured: our seam concentration 3.0x
// vs the rexglue SDK's 1.39x on the same metric/machine). One global generation counter + CV lets
// the multi-wait block on a real edge and re-scan only when SOMETHING was signalled.
static std::mutex              g_evsig_m;
static std::condition_variable g_evsig_cv;
static std::atomic<uint64_t>   g_evsig_gen{0};
static void rt_setev(uint32_t k){ if(auto*e=rt_ev(k,true)){
  { std::lock_guard<std::mutex> l(e->m); e->sig=true; e->cv.notify_all(); }
  { std::lock_guard<std::mutex> l(g_evsig_m); g_evsig_gen.fetch_add(1,std::memory_order_release); }
  g_evsig_cv.notify_all(); } }
static void rt_rstev(uint32_t k){ if(auto*e=rt_ev(k,true)){ std::lock_guard<std::mutex> l(e->m); e->sig=false; } }
PPC_FUNC_IMPL(__imp__KeSetEvent){ LOGN("KeSetEvent"); if(rt_pt_on()) rt_pt_setev_log(ctx.r3.u32,(uint32_t)ctx.lr); rt_setev(ctx.r3.u32); ctx.r3.u32=0; (void)base; }
PPC_FUNC_IMPL(__imp__NtSetEvent){ LOGN("NtSetEvent"); if(rt_pt_on()) rt_pt_setev_log(ctx.r3.u32,(uint32_t)ctx.lr); rt_setev(ctx.r3.u32); ctx.r3.u32=0; (void)base; }
PPC_FUNC_IMPL(__imp__KeResetEvent){ LOGN("KeResetEvent"); rt_rstev(ctx.r3.u32); ctx.r3.u32=0; (void)base; }
PPC_FUNC_IMPL(__imp__NtClearEvent){ LOGN("NtClearEvent"); rt_rstev(ctx.r3.u32); ctx.r3.u32=0; (void)base; }
// ★ rank 23 (ELIMINATION backlog, 2026-07-27): honor the guest's TIMEOUT and RETURN CODE.
// The old rt_wait ignored the timeout argument entirely (hard 10s cap on events) and every
// caller returned 0 (SUCCESS) even when the wait TIMED OUT — an unsignaled event cost a 10s
// stall and then LIED to the guest. ABI (SDK xeKeWaitForSingleObject, rex threading.h:29):
// r3=Object r4=WaitReason r5=Mode r6=Alertable r7=Timeout ptr — BE s64: negative = relative
// in 100ns, 0 = poll, NULL ptr = infinite. Infinite keeps a WATCHDOG (RT_WAITMAX_MS, default
// 10000 = the old cap) so a producer starved by one of OUR stubs can never wedge a guest
// thread forever; expiry returns STATUS_TIMEOUT 0x102 (honest) with a one-shot stderr warn
// (visibility — on hardware an infinite wait would simply hang, so any watchdog expiry means
// a port defect upstream). RT_WAITLEGACY=1 restores the old ignore-and-lie behaviour.
static int64_t rt_waitmax_us(){ static int64_t v=[](){ const char* e=std::getenv("RT_WAITMAX_MS");
  long ms=e?atol(e):10000; if(ms<1)ms=1; return (int64_t)ms*1000; }(); return v; }
static uint32_t rt_wait_to(uint32_t k, uint8_t* base, uint32_t timeoutp, uint32_t lr=0){ RtObj*o=rt_get(k);
  if(rt_pt_on() && k && k==g_pt_consumed.load()) g_pt_cw_single.fetch_add(1);
  bool dbg = std::getenv("RT_DBGSPAWN")!=nullptr;
  if(dbg) std::fprintf(stderr,"[e8] rt_wait ENTER k=0x%X o=%p is_event=%d is_thread=%d top=0x%X\n",k,(void*)o,
    (int)(dynamic_cast<RtEvent*>(o)!=nullptr),(int)(dynamic_cast<RtThread*>(o)!=nullptr),timeoutp);
  static bool legacy = std::getenv("RT_WAITLEGACY") && atoi(std::getenv("RT_WAITLEGACY"))!=0;
  bool infinite=true; int64_t us=rt_waitmax_us();
  if(!legacy && timeoutp){ int64_t t=(int64_t)__builtin_bswap64(*(uint64_t*)(base+timeoutp));
    infinite=false;
    if(t<0) us=(-t)/10;
    else if(t==0) us=0;
    else { // absolute system-time deadline: rare on this shell; poll once + one-shot note
      us=0; static bool w=false; if(!w){ w=true;
        std::fprintf(stderr,"[rt] KeWait ABSOLUTE timeout seen (0x%llX) — treated as poll\n",(unsigned long long)t); } } }
  uint32_t rc=0;
  if(auto*e=dynamic_cast<RtEvent*>(o)){ std::unique_lock<std::mutex> l(e->m);
    bool sig;
    if(us<=0) sig=e->sig;
    else sig=e->cv.wait_for(l,std::chrono::microseconds(us),[&]{return e->sig;});
    if(sig){ if(!e->manual)e->sig=false; rc=0; }
    else { rc = legacy ? 0u : 0x102u;
      // FAITHFUL-IDLE whitelist (2026-07-27, decomp-closed — ATLAS_threading_kernel §7): the
      // D3D multi-core command-buffer replay worker pool (thread body 0x820B4248) waits on its
      // per-thread KEVENT that only a predicated-tiling pass ever signals — Futari never runs
      // one, so this wait starves ON REAL HARDWARE TOO. Expiries from its two wait LRs are
      // expected forever; keep them out of the starved-producer warning (which exists to flag
      // NEW defects). RT_WAITWARN_ALL=1 restores the unfiltered warning for A/B.
      static bool warnAll = std::getenv("RT_WAITWARN_ALL") && atoi(std::getenv("RT_WAITWARN_ALL"))!=0;
      bool faithfulIdle = !warnAll && (lr==0x820B42E4u || lr==0x820B438Cu);
      if(infinite && !legacy && !faithfulIdle){ static long iw=0; if(iw++<8)
        std::fprintf(stderr,"[rt] WARN infinite KeWait k=0x%X lr=0x%08X hit the %lldms watchdog -> 0x102 (starved producer upstream?)\n",
                     k,lr,(long long)(rt_waitmax_us()/1000)); }
      if(dbg) std::fprintf(stderr,"[e8] rt_wait TIMEOUT k=0x%X\n",k); } }
  else if(auto*t=dynamic_cast<RtThread*>(o)){ int64_t left = us>0?us:rt_waitmax_us();
    while(left>0 && !t->done.load()){ std::this_thread::sleep_for(std::chrono::milliseconds(1)); left-=1000; }
    rc = (t->done.load()||legacy) ? 0u : 0x102u; }
  if(dbg) std::fprintf(stderr,"[e8] rt_wait EXIT k=0x%X rc=0x%X\n",k,rc);
  return rc; }
static void rt_wait(uint32_t k){ (void)rt_wait_to(k,nullptr,0); }   // legacy internal callers: infinite+watchdog
PPC_FUNC_IMPL(__imp__KeWaitForSingleObject){ LOGN("KeWaitForSingleObject"); ctx.r3.u32=rt_wait_to(ctx.r3.u32,base,ctx.r7.u32,(uint32_t)ctx.lr); }
// __imp__KeWaitForMultipleObjects — real WaitAny, moved here from stubs.cpp (2026-07-13, audio).
// Exactly two shell callers, both XAudio (ppc_recomp.21.cpp): sub_821396C0 (render-driver
// callback: WaitAny {shutdown_ev, frame_ready_ev}, submits the mixed frame to
// XAudioSubmitRenderDriverFrame ONLY on result==1) and sub_82136138 (engine worker: WaitAny x3
// with ms timeout, loops on 1, maps 0x102/2 -> "keep running"). The old return-0 stub therefore
// made the render callback's submit branch UNREACHABLE — the port was silent by construction —
// and fed the worker a constant "object 0" result. Gated on the audio levers (RT_AUDIO /
// RT_AUDIODUMP): without them legacy return-0, byte-identical runs.
// ABI: r3=Count r4=Object[] (BE guest KEVENT addrs -> rt_ev keyed by address) r5=WaitType(1=any;
// no shell caller uses WaitAll) r9=Timeout ptr (BE s64, negative = relative in 100ns, NULL =
// infinite). Infinite is CLAMPED (3ms): this runs on the audiopump/vblank thread and a dead
// producer must never wedge it (nor inflate the 2ms tick much while the mixer isn't up yet —
// a healthy mixer, woken by KeSetEvent at callback entry, signals in microseconds); on expiry
// return STATUS_TIMEOUT (0x102) — benign to both callers.
PPC_FUNC_IMPL(__imp__KeWaitForMultipleObjects){ LOGN("KeWaitForMultipleObjects");
  static bool real = getenv("RT_AUDIO")!=nullptr || getenv("RT_AUDIODUMP")!=nullptr;
  if(!real){ ctx.r3.u64=0; (void)base; return; }
  uint32_t cnt=ctx.r3.u32, arr=ctx.r4.u32;
  uint32_t lr=(uint32_t)ctx.lr;
  // On the RT_AUDIOWORKER thread the render-driver callback's infinite WaitAny{shutdown,
  // frame_ready} may block for the guest engine-worker handshake (~5.3ms cadence); the
  // vblank thread's 3ms clamp is too tight and starves it. Bounded (RT_AUDIOWORKER_WAITMS,
  // default 16ms) so a dead producer only slows the worker, never wedges it.
  int64_t max_us = t_on_audio_worker ? rt_audio_worker_waitus() : 3000;
  // RT_FRAMEPAIR (frame-pairing leg, layer 26, default-OFF): make the transpose's frame-ready wait
  // (caller lr 0x82139740) TRULY BLOCKING. On HW the render-driver client callback's WaitAny is
  // NULL=infinite and only advances when the mix summer signals READY (client+0x2c) for the exact
  // frame just produced. The port's 3ms/16ms clamp lets it free-run: it returns index-1 on a STALE
  // ready and reads a 0x36FA90 the next summer pass already overwrote (=> sustained BGM never lands).
  // Under RT_FRAMEPAIR we let this one wait block up to a GENEROUS watchdog (RT_FRAMEPAIR_WAITMS,
  // default 250ms) rather than a short free-run timeout -- deadlock-guarded, never a hard hang.
  static bool     fp_on = getenv("RT_FRAMEPAIR")!=nullptr;
  static int64_t  fp_wus = [](){ const char* e=getenv("RT_FRAMEPAIR_WAITMS"); long ms=e?atol(e):250; if(ms<1)ms=1; if(ms>2000)ms=2000; return (int64_t)ms*1000; }();
  bool is_transpose_wait = (lr==0x82139740u);
  if(ctx.r9.u32){ int64_t t=(int64_t)__builtin_bswap64(*(uint64_t*)(base+ctx.r9.u32));
    if(t<0) max_us=std::min<int64_t>((-t)/10, t_on_audio_worker?200000:100000); else if(t==0) max_us=0; }
  // The guest passes NULL timeout (infinite) at the transpose site; only when fp_on AND the transpose
  // runs on the dedicated audio worker thread do we honour a long blocking budget (safe to block that
  // thread). On the vblank/pump thread we KEEP the 3ms clamp so the render thread is never stalled by
  // this wait (video safety) -- the RT_FRAMEPAIR producer rendezvous already paces the summer so a
  // fresh READY is available within the clamp.
  if(fp_on && is_transpose_wait && ctx.r9.u32==0 && t_on_audio_worker) max_us = fp_wus;
  // ★ RT_ENGINEWAIT (2026-08-01, default ON; =0 reverts). Honours the XACT ENGINE thread's wait on
  // the 'consumed' event (client+0x28, obj 0x36A748) at lr=0x821361C4, which the guest issues as
  // NULL=infinite; our generic 3ms clamp returned STATUS_TIMEOUT instead. Register-true either way
  // (the guest asked to block), watchdog-bounded via RT_FRAMEPAIR_WAITMS so a dead consumer can
  // only slow this thread, never wedge it — KEEP for that reason alone.
  // ⚠ RETRACTED 2026-08-01 (workflow wf_52146add, 21 agents): the original claim here — "producer
  // 263Hz vs consumer 187.5Hz => ~1 in 3 delivered frames TORN => the overlap crunch" — is FALSE.
  // Measured: callback firings == submits to within 0.5% of 25432, and the [gqc] repeat counter is
  // 0, so no frame is dropped or duplicated. The crunch was NOT cured by this. Do not cite the
  // torn-frame model; _tmpscripts/native_mix_crunch_research.md is retracted with it.
  static bool ew_on = [](){ const char* e=getenv("RT_ENGINEWAIT"); return !(e&&e[0]=='0'&&!e[1]); }();
  if(ew_on && lr==0x821361C4u && ctx.r9.u32==0) max_us = fp_wus;
  // ---- RT_PAIRTRACE: capture the transpose client events + entry snapshot ----
  bool pt = rt_pt_on();
  long pt_t0=0; bool pt_has_consumed=false;
  if(pt && cnt && cnt<=16 && arr){
    pt_t0=rt_pt_us();
    if(is_transpose_wait && cnt>=2){
      uint32_t k0=__builtin_bswap32(*(uint32_t*)(base+arr+0));   // shutdown  (*(client+0x30))
      uint32_t k1=__builtin_bswap32(*(uint32_t*)(base+arr+4));   // ready     (*(client+0x2c))
      g_pt_shutdown.store(k0); g_pt_ready.store(k1);
    }
    uint32_t rc=g_pt_consumed.load();
    for(uint32_t i=0;i<cnt;i++){ uint32_t k=__builtin_bswap32(*(uint32_t*)(base+arr+i*4));
      if(k && k==rc) pt_has_consumed=true; }
    if(pt_has_consumed) g_pt_cw.fetch_add(1);
  }
  if(!cnt||cnt>16||!arr){ ctx.r3.u64=0x102; return; }
  static std::atomic<int> kwm_logs{0};
  if(kwm_logs.load()<4){ kwm_logs++;
    std::fprintf(stderr,"  [kwaitm] cnt=%u wtype=%u tmo=%lldus lr=0x%08X objs:",(unsigned)cnt,(unsigned)ctx.r5.u32,(long long)max_us,lr);
    for(uint32_t i=0;i<cnt;i++) std::fprintf(stderr," %08X",(unsigned)__builtin_bswap32(*(uint32_t*)(base+arr+i*4)));
    std::fprintf(stderr,"\n"); }
  auto deadline=std::chrono::steady_clock::now()+std::chrono::microseconds(max_us);
  uint64_t result=0x102;
  // RT_KWAITPOLL=1 restores the pre-08-01 300us polling loop (A/B arm for the seam metric).
  static bool kwpoll = [](){ const char* e=getenv("RT_KWAITPOLL"); return e && e[0]=='1' && !e[1]; }();
  for(;;){
    // Read the wakeup generation BEFORE scanning: a signal that lands mid-scan bumps it, so the
    // wait below returns immediately instead of sleeping through the edge we just missed.
    uint64_t gen0 = g_evsig_gen.load(std::memory_order_acquire);
    bool got=false;
    for(uint32_t i=0;i<cnt;i++){
      uint32_t k=__builtin_bswap32(*(uint32_t*)(base+arr+i*4));
      if(RtEvent*e=rt_ev(k,true)){ std::lock_guard<std::mutex> l(e->m);
        if(e->sig){ if(!e->manual)e->sig=false; result=i; got=true; break; } } }
    if(got) break;
    if(std::chrono::steady_clock::now()>=deadline){ result=0x102; break; }
    if(kwpoll){ std::this_thread::sleep_for(std::chrono::microseconds(300)); continue; }
    std::unique_lock<std::mutex> lk(g_evsig_m);
    g_evsig_cv.wait_until(lk,deadline,[&]{ return g_evsig_gen.load(std::memory_order_acquire)!=gen0; });
  }
  // ---- RT_PAIRTRACE: transpose-wait phase histogram + periodic summary ----
  if(pt && is_transpose_wait){
    long el=rt_pt_us()-pt_t0;
    uint64_t tot=g_pt_tw_tot.fetch_add(1)+1;
    if(g_pt_tw_first.load()<0) g_pt_tw_first.store(pt_t0); g_pt_tw_last.store(rt_pt_us());
    if(result==0x102) g_pt_tw_tmo.fetch_add(1);
    else if(result==1){ if(el<200) g_pt_tw_imm.fetch_add(1); else g_pt_tw_blk.fetch_add(1); }
    if(tot<=6 || (tot%4000)==0){
      long rf=g_pt_ready_first.load(), rl=g_pt_ready_last.load();
      double rrate=(rf>=0 && rl>rf)? (double)g_pt_set_ready.load()*1e6/(double)(rl-rf) : 0.0;
      long tf=g_pt_tw_first.load(), tl=g_pt_tw_last.load();
      double trate=(tf>=0 && tl>tf)? (double)tot*1e6/(double)(tl-tf) : 0.0;
      std::fprintf(stderr,"[pairtrace] TW #%llu result=%llu el=%ldus | imm=%llu blk=%llu tmo=%llu (imm=free-run,blk=paced) | setReady=%llu(%.1fHz) setConsumed=%llu setShutdn=%llu | consumedWaits(multi=%llu single=%llu) | twRate=%.1fHz tid=%d\n",
        (unsigned long long)tot,(unsigned long long)result,el,
        (unsigned long long)g_pt_tw_imm.load(),(unsigned long long)g_pt_tw_blk.load(),(unsigned long long)g_pt_tw_tmo.load(),
        (unsigned long long)g_pt_set_ready.load(),rrate,
        (unsigned long long)g_pt_set_consumed.load(),(unsigned long long)g_pt_set_shutdown.load(),
        (unsigned long long)g_pt_cw.load(),(unsigned long long)g_pt_cw_single.load(),trate,rt_pt_tid());
    }
  }
  ctx.r3.u64=result; (void)base; return;
}
// rank 23: honors r6 = Timeout ptr (Nt ABI: Handle r3, WaitMode r4, Alertable r5, Timeout r6).
// NOTE: in the MERGED link the game's out_reco/rt.cpp definition WINS this symbol (separate
// Nt registry, already timeout-faithful since the audio arc) — this shell copy serves
// shell-only builds; kept consistent anyway.
PPC_FUNC_IMPL(__imp__NtWaitForSingleObjectEx){ LOGN("NtWaitForSingleObjectEx"); ctx.r3.u32=rt_wait_to(ctx.r3.u32,base,ctx.r6.u32); }
// Shared real-wall-clock helper (100ns units, anchored to the same in-era 0x01C6... epoch
// KeQuerySystemTime uses) for KeDelayExecutionThread's absolute-interval branch below. An
// absolute delay target has to be measured against real elapsed time regardless of whichever
// KeQuerySystemTime mode (rank 2) is currently active.
static uint64_t rt_realtime_100ns() {
  static const uint64_t ep = 0x01C6000000000000ULL;
  static const std::chrono::steady_clock::time_point t0 = std::chrono::steady_clock::now();
  return ep + (uint64_t)(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - t0).count() / 100);
}
// RANK 20 (register-true default, 2026-07-18): honor the guest's requested interval instead of a
// fixed 1ms sleep. ABI (KeDelayExecutionThread / SDK XThread::Delay, xthread.cpp:1000): r3=WaitMode
// (ignored, matches SDK), r4=Alertable, r5=PLARGE_INTEGER Interval (BE s64, 100ns units). interval<0
// = relative (sleep -interval/10000 ms); ==0 = yield; >0 = absolute vs system time, sleep the
// remainder. Same relative-100ns decode the neighboring KeWaitForMultipleObjects (above) already
// uses for its r9 timeout. No guest-APC delivery is modeled anywhere in this port, so alertable
// interruption never fires here (SDK returns X_STATUS_USER_APC only on that path) -- normal
// completion is X_STATUS_SUCCESS in every branch.
PPC_FUNC_IMPL(__imp__KeDelayExecutionThread){ LOGN("KeDelayExecutionThread");
  uint32_t alertable = ctx.r4.u32; (void)alertable;   // read for ABI fidelity; no guest-APC path to honor it with
  uint32_t ip = ctx.r5.u32;
  if (!ip) { std::this_thread::yield(); ctx.r3.u32 = 0; (void)base; return; }
  int64_t interval = (int64_t)__builtin_bswap64(*(uint64_t*)(base + ip));
  if (interval < 0) {
    int64_t us = (-interval) / 10;   // 100ns ticks -> microseconds
    if (us > 0) std::this_thread::sleep_for(std::chrono::microseconds(us));
    else std::this_thread::yield();
  } else if (interval > 0) {
    uint64_t now = rt_realtime_100ns();
    if ((uint64_t)interval > now) std::this_thread::sleep_for(std::chrono::microseconds(((uint64_t)interval - now) / 10));
  } else {
    std::this_thread::yield();
  }
  ctx.r3.u32 = 0; (void)base;
}
PPC_FUNC_IMPL(__imp__NtClose){ LOGN("NtClose"); ctx.r3.u32=0; (void)base; }
PPC_FUNC_IMPL(__imp__KeQueryPerformanceFrequency){ LOGN("KeQueryPerformanceFrequency"); ctx.r3.u64=50000000ULL; (void)base; }
// KeQuerySystemTime (RANK 2, register-true default as of 2026-07-18): the shipped clock used to be a
// FAKE deterministic advance of a fixed 10ms PER CALL — guest wall-time flowed only as fast as the
// guest polled it, so any ROM logic timing screens off SystemTime deltas ran at (calls_per_sec * 10ms)
// of real speed (the ROM attract's legal/ranking screens measured ~6-9x slow vs the SDK oracle). This
// now always returns REAL wall time as a proper FILETIME (100ns units, steady, anchored to the same
// in-era 0x01C6... epoch the old fake used so absolute-date checks stay in-era) via the shared
// rt_realtime_100ns() helper (defined above, also used by KeDelayExecutionThread's absolute-interval
// branch). The old RT_REALTIME env gate + per-call fake are retired — this was proven as non-regressing
// via the RT_REALTIME=1 A/B lever before being made the default.
PPC_FUNC_IMPL(__imp__KeQuerySystemTime){ LOGN("KeQuerySystemTime"); uint32_t p=ctx.r3.u32;
  uint64_t t = rt_realtime_100ns();
  if(p)*(uint64_t*)(base+p)=__builtin_bswap64(t); g_qst_since_present++; (void)base; }
PPC_FUNC_IMPL(__imp__DbgPrint){ LOGN("DbgPrint"); uint32_t p=ctx.r3.u32; if(p) std::fprintf(stderr,"  [DbgPrint] %.200s | r4=%d r5=%d r6=%d\n",(const char*)(base+p),(int)ctx.r4.u32,(int)ctx.r5.u32,(int)ctx.r6.u32); (void)base; }
PPC_FUNC_IMPL(__imp__XamLoaderTerminateTitle){ LOGN("XamLoaderTerminateTitle");
  std::fprintf(stderr,"  === XamLoaderTerminateTitle CALLED — who? ===\n");
#ifndef _WIN32
  void* bt[24]; int n=backtrace(bt,24); backtrace_symbols_fd(bt,n,2);
#endif
  ctx.r3.u32=0; (void)base; }

// ================= notification listeners (added: unblock shell boot idle) =================
// Shell idles in sub_821706E8 while status(loopobj+8)==0; its boot child widgets complete only
// after consuming the XAM startup notification burst. Shipped rexglue enqueues that burst on the
// first system-area listener and XNotifyGetNext dequeues BY HANDLE. Our old stubs returned handle
// 0 / empty queue, so the guest stored handle 0 and every per-frame XNotifyGetNext(0) failed the
// lookup -> infinite idle. Model listener + startup burst + by-handle dequeue here.
#include <deque>
#include <vector>
#include <utility>
#include <map>
// ★ HARD PIVOT (2026-07-28): nvk API-trace sinks (decomp/shell/nvk.cpp). RT_NVK=1 traces every
// D3D wrapper call; inert otherwise. NVK_TAP goes at hook ENTRY (pre-__imp__ args).
extern "C" void nvk_ev(const char*, unsigned long long, unsigned long long, unsigned long long,
                       unsigned long long, unsigned long long, unsigned long long, unsigned long long);
extern "C" void nvk_present();
// ★ HARD PIVOT stage 1 (RT_NVK=2): recorder callbacks (decomp/shell/nvk.cpp). nvk_mode() reads
// RT_NVK once; at >=2 the load-bearing hooks below feed the recorder and the Present hook
// short-circuits the old renderer entirely.
extern "C" int  nvk_mode();
extern "C" void nvk_on_draw_core(uint8_t* base, unsigned dev, unsigned prim, unsigned count, unsigned strideB, unsigned scratch, unsigned dirtyPre, unsigned isGame);
extern "C" void nvk_on_resolve(uint8_t* base, unsigned dev, unsigned flags, unsigned pDestTex, unsigned pSrcRect, unsigned clearColor, unsigned pDestPoint);
extern "C" unsigned nvk_pack_cc(uint8_t* base, unsigned pcc);
extern "C" void nvk_on_clear(unsigned colorARGB);
extern "C" void nvk_on_blob_submit(uint8_t* base, unsigned dev);
extern "C" void nvk_on_present_frame(uint8_t* base);
#define NVK_TAP(name) nvk_ev(name, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64)
struct RtListener { uint32_t handle; uint64_t areas; std::deque<std::pair<uint32_t,uint32_t>> q; };
static std::mutex g_lstm; static std::vector<RtListener*> g_lst; static uint32_t g_lnext=0xF0000001u;
PPC_FUNC_IMPL(__imp__XamNotifyCreateListener){ LOGN("XamNotifyCreateListener");
  uint64_t areas=ctx.r3.u64; // qwAreas bitmask; bit0 = XNOTIFY_SYSTEM
  std::lock_guard<std::mutex> l(g_lstm);
  RtListener* L=new RtListener(); L->handle=g_lnext; g_lnext+=4; L->areas=areas;
  bool first_sys=true; for(auto* o:g_lst) if(o->areas&1) first_sys=false;
  if((areas&1) && first_sys){ // rexglue RegisterNotifyListener startup burst (kernel_state.cpp:1031)
    const uint32_t burst[8][2]={{0x9,1},{0x9,0},{0xA,1},{0xA,1},{0x12,0},{0x12,0},{0x13,0},{0x13,0}};
    for(int i=0;i<8;i++) L->q.emplace_back(burst[i][0],burst[i][1]); }
  g_lst.push_back(L);
  std::fprintf(stderr,"  [notify] CreateListener areas=0x%llX -> handle=0x%08X queued=%zu\n",(unsigned long long)areas,L->handle,L->q.size());
  ctx.r3.u32=L->handle; (void)base; }
// Post a notification to every system-area listener (rexglue BroadcastNotification
// equivalent) — used by the XAM UI headless dispatch (device selector etc.).
extern "C" void rt_notify_broadcast(uint32_t id, uint32_t param){
  std::lock_guard<std::mutex> l(g_lstm);
  size_t n=0;
  for(auto* L:g_lst) if(L->areas & 1){ L->q.emplace_back(id,param); n++; }
  std::fprintf(stderr,"  [notify] broadcast id=0x%X param=0x%X -> %zu listeners\n",id,param,n);
}
PPC_FUNC_IMPL(__imp__XNotifyGetNext){ LOGN("XNotifyGetNext");
  uint32_t handle=ctx.r3.u32, match=ctx.r4.u32, idp=ctx.r5.u32, parp=ctx.r6.u32;
  if(parp) PPC_STORE_U32(parp,0);
  if(!idp){ ctx.r3.u32=0; (void)base; return; }
  PPC_STORE_U32(idp,0);
  std::lock_guard<std::mutex> l(g_lstm);
  RtListener* L=nullptr; for(auto* o:g_lst) if(o->handle==handle){ L=o; break; }
  static std::atomic<int> lg{0}; int k=lg++;
  if(!L){ if(k<40) std::fprintf(stderr,"  [notify] GetNext h=0x%08X match=0x%08X -> NO LISTENER\n",handle,match); ctx.r3.u32=0; (void)base; return; }
  int idx=-1;
  for(size_t i=0;i<L->q.size();i++){ uint32_t id=L->q[i].first;
    if(match==0 || id==match || id==(match&0xFFFFu)){ idx=(int)i; break; } }
  if(idx<0){ if(k<40) std::fprintf(stderr,"  [notify] GetNext h=0x%08X match=0x%08X qsz=%zu -> no match\n",handle,match,L->q.size()); ctx.r3.u32=0; (void)base; return; }
  std::pair<uint32_t,uint32_t> e=L->q[idx]; L->q.erase(L->q.begin()+idx);
  PPC_STORE_U32(idp,e.first); if(parp) PPC_STORE_U32(parp,e.second);
  if(k<80) std::fprintf(stderr,"  [notify] GetNext h=0x%08X match=0x%08X -> id=0x%X param=0x%X (qsz=%zu)\n",handle,match,e.first,e.second,L->q.size());
  ctx.r3.u32=1; (void)base; }

// --- VdSwap: decode the D3D9 texture-fetch header for the frontbuffer, log
// lowmem verdict for the first frames, and on the 8th call dump raw guest
// memory regions (ring, low 32MB, image region) + a manifest for offline
// replay through rexglue's GPU. ---
//
// xe_gpu_texture_fetch_t (rex/graphics/xenos.h), dword_1 (index 1, byte +4):
//   format:6 (+0), endianness:2 (+6), request_size:2 (+8), stacked:1 (+10),
//   nearest_clamp_policy:1 (+11), base_address:20 (+12, "base address >> 12")
// dword_2 (index 2, byte +8), size_2d union:
//   width:13 (+0) height:13 (+13) stack_depth:6 (+26); stored as (actual-1)
// GATE 3 per-frame game tick target: set by merged_xex.cpp after GameEntry init completes.
// Defined HERE (not in merged_xex.cpp) so futari_shell — which does not link merged_xex.cpp —
// still resolves the symbol (it stays 0 there, so the tick below never fires).
extern "C" uint32_t g_game_tick_modectx = 0;
extern "C" void __imp__sub_821C3278(PPCContext& __restrict, uint8_t*);  // shell per-frame game-mode tick
extern "C" void __imp__sub_82173900(PPCContext& __restrict, uint8_t*);  // base task child-render pass
// GATE 3 (2026-07-06, SDK-oracle finding): the game module renders its title/menu ONLY when
// pumped GameEntry(msg=5) every frame. The SDK sends it from sub_821C8DA8(r3=modectx) — the mode
// object's per-frame vtable update method (dispatched over the ACTIVE mode object in the app-state
// tree). sub_821C3278/sub_821C69F0 above is the shell's UI tick and does NOT send msg 5, and can't
// reach sub_821C8DA8 because our injected inner modectx is not registered in the loopobj tree. So
// under RT_GAMEPUMP we call sub_821C8DA8(inner) directly each present to drive the game per-frame.
extern "C" void __imp__sub_821C8DA8(PPCContext& __restrict, uint8_t*);  // per-frame GameEntry(msg=5) pump
// GATE 3 (2026-07-06): the SDK's loading-complete signal. After the game has pumped msg-5 for a
// while (assets loaded), the shell sends GameEntry msg 15, msg 11 (state 4), msg 15 — the trigger
// that flips the game from "loading" to "build/render menu". Senders build their own args from the
// modectx + shell state; sub_821C85A0's r4 = lifecycle state (4 = menu; derived: 1<<(4-4)=arg[0]=1,
// matches the SDK oracle). Armed with RT_LOADSIG; fires once after RT_LOADSIG (default 300) presents.
extern "C" void __imp__sub_821C88E8(PPCContext& __restrict, uint8_t*);  // sends GameEntry(msg=15)
extern "C" void __imp__sub_821C85A0(PPCContext& __restrict, uint8_t*);  // sends GameEntry(msg=11, state r4)

PPC_FUNC_IMPL(__imp__VdSwap){ LOGN("VdSwap");
  uint32_t buffer_ptr=ctx.r3.u32, fetch_ptr=ctx.r4.u32, writeback_ptr=ctx.r5.u32;
  uint32_t cmdbuf6=ctx.r6.u32, cmdbuf7=ctx.r7.u32, frontbuffer_ptr=ctx.r8.u32;
  uint32_t fmt=ctx.r9.u32, color_space=ctx.r10.u32;

  uint32_t fetch_dw[6]={0,0,0,0,0,0};
  for(int i=0;i<6;i++) fetch_dw[i]=rt_be32(base,fetch_ptr+ (uint32_t)i*4);

  uint32_t base_address=(fetch_dw[1]>>12)&0xFFFFFu;      // dword_1 bits[12:31]
  uint32_t fb_virtual=base_address<<12;
  uint32_t w=((fetch_dw[2]>>0)&0x1FFFu)+1;                // size_2d.width
  uint32_t h=((fetch_dw[2]>>13)&0x1FFFu)+1;               // size_2d.height
  int lowmem=(fb_virtual<0x20000000u)?1:0;

  uint32_t fb_ptr_target=frontbuffer_ptr? rt_be32(base,frontbuffer_ptr) : 0;

  static std::atomic<int> g_vdswap_calls{0};
  int n=g_vdswap_calls++;
  g_vdswap_since_present++;  // RT_HKDUP: counts real guest swaps between hooked Presents
  g_rt_present_ctr.fetch_add(1);  // global present counter for RT_FSMLOG correlation

  // LEG-27/40 ring-window: cursor before any game tick/pump runs in this impl.
  if(g_d3d_device) g_vk_vd_pre.store(rt_be32(base,g_d3d_device+0x30));

  // GATE 3: drive the game's per-frame update once per present when armed. Reentrancy-guarded
  // (the tick must never re-enter VdSwap); copy ctx so VdSwap's own registers are untouched.
  if(g_game_tick_modectx && getenv("RT_GAMETICK") && !getenv("RT_TREEPUMP")){
    static thread_local bool in_tick=false;
    if(!in_tick){
      in_tick=true;
      PPCContext ic=ctx; ic.r3.u32=g_game_tick_modectx;
      __imp__sub_821C3278(ic,base);
      in_tick=false;
      static std::atomic<int> tk{0}; int t=tk++;
      if(t<5||(t%300)==0)
        std::fprintf(stderr,"[gametick] present#%d ticked sub_821C3278(modectx=0x%08X)%c",n,g_game_tick_modectx,10);
    }
  }
  // RT_TREEPUMP (2026-07-23 pump-hunt leg): register-true replacement for RT_GAMETICK's bare
  // 69F0 call. The natural per-frame path (sub_8216EA68 on the wrapper the fake LOADGAME scene
  // never pumps) calls modectx vt+0x04 = sub_82173B98 = the TASK-TREE TICK (runs the +0x48 state
  // fn ONLY when modal child-list A is empty, then ticks child nodes A/B — the page/dialog tasks),
  // and the walker's render pass renders the children. We deliver both: vt+0x04, then the base
  // task child-render FUN_82173900(modectx, 0). Supersedes RT_GAMETICK when set.
  if(g_game_tick_modectx && getenv("RT_TREEPUMP")){
    static thread_local bool in_tp=false;
    if(!in_tp){
      in_tp=true;
      uint32_t mc=g_game_tick_modectx;
      uint32_t vt=rt_be32(base,mc), f04=vt?rt_be32(base,vt+4):0;
      if(f04>=0x82000000u && f04<0x82200000u){
        PPCContext ic=ctx; ic.r3.u32=mc;
        (PPC_LOOKUP_FUNC(base, f04))(ic, base);
      }
      { PPCContext ir=ctx; ir.r3.u32=mc; ir.r4.u64=0;
        __imp__sub_82173900(ir,base); }
      in_tp=false;
      static std::atomic<int> tp{0}; int t=tp++;
      if(t<5||(t%300)==0)
        std::fprintf(stderr,"[treepump] present#%d vt04=0x%08X tick+render (modectx=0x%08X)%c",n,f04,mc,10);
    }
  }

  // GATE 3: the actual per-frame GameEntry(msg=5) pump (sub_821C8DA8), armed with RT_GAMEPUMP.
  // RT_GAMEPUMP_VBLANK moves this grant to the 59.94Hz vblank thread (attract-pacing decoupling —
  // see the vblank loop); pumping from BOTH would over-grant, so VdSwap steps aside.
  static bool vbpump_owns = getenv("RT_GAMEPUMP_VBLANK")!=nullptr;
  if(g_game_tick_modectx && !vbpump_owns && getenv("RT_GAMEPUMP")){
    static thread_local bool in_pump=false;
    if(!in_pump){
      in_pump=true;
      PPCContext pc=ctx; pc.r3.u32=g_game_tick_modectx;
      __imp__sub_821C8DA8(pc,base);
      in_pump=false;
      rt_fsmlog(base,"pres");   // present-path pump: FSM timers tick at the (variable) present rate
      static std::atomic<int> pk{0}; int p=pk++;
      if(p<5||(p%300)==0)
        std::fprintf(stderr,"[gamepump] present#%d pumped sub_821C8DA8(modectx=0x%08X) msg5%c",n,g_game_tick_modectx,10);

      // GATE 3 visibility: game lifecycle state on change (cb2 buf, boot-FSM state 0x884D66A8,
      // assets-committed flag byte 0x887AC973, lifecycle flags, input gate).
      { static uint32_t ls=0xFFFFFFFFu, lf=0xFFFFFFFFu, lg=0xFFFFFFFFu, lfsm=0xFFFFFFFFu, l973=0xFFFFFFFFu;
        uint32_t sc=rt_be32(base,0x88699894u), fl=rt_be32(base,0x88652DD8u), gt=rt_be32(base,g_game_tick_modectx+152);
        uint32_t fsm=rt_be32(base,0x884D66A8u), f973=*(uint8_t*)(base+GA_ASSET_COMMIT);
        uint32_t fctr=rt_be32(base,0x884D673Cu); // FSM global frame counter (88138F00 tail) — DE58 gates on bit 4
        if(sc!=ls||fl!=lf||gt!=lg||fsm!=lfsm||f973!=l973){ ls=sc; lf=fl; lg=gt; lfsm=fsm; l973=f973;
          std::fprintf(stderr,"[gstate] present#%d cb2buf=0x%X fsm=0x%X flag973=0x%X flags=0x%X inputgate=0x%X fctr=%u\n",p,sc,fsm,f973,fl,gt,fctr); }
        static std::atomic<int> fc{0}; if((fc++%600)==0)
          std::fprintf(stderr,"[fctr] present#%d fctr673C=%u (bit4=%u)\n",p,fctr,(fctr>>4)&1u); }

      // RT_STARTBIT=<present>: inject the START button the way the TITLE FSM reads it —
      // bit 0x8000 of guest words 0x885C33D8 / 0x885C3430 (sub_88138F00 state-3 handler tests
      // these; on set it runs the NATURAL title->menu transition that constructs the menu's
      // per-frame drawer). Held for RT_STARTHOLD frames (default 4) starting at the given present.
      if(const char* sbe=getenv("RT_STARTBIT")){
        int at=atoi(sbe); const char* she=getenv("RT_STARTHOLD"); int hold=she?atoi(she):4;
        if(p>=at && p<at+hold){
          auto orbit=[&](uint32_t a){ uint32_t v=rt_be32(base,a)|0x00008000u; *(uint32_t*)(base+a)=__builtin_bswap32(v); };
          orbit(0x885C33D8u); orbit(0x885C3430u);
          static int once=0; if(!once++){ std::fprintf(stderr,"[startbit] injecting START (0x8000) @0x885C33D8/3430 at present#%d hold=%d\n",p,hold); }
        }
      }

      // LEG-15 quiesce/mode-load levers (bisect the state-2 menu-load wedge; workflow wf_9f3bce65).
      // RT_ACKQUIESCE=1: each present, if the state-2 quiesce flag *(0x887AD1AC)!=0, clear it to 0
      // (the ACK the game worker sub_88092C28 owes but doesn't deliver in merged). Optionally memset
      // the worker's 6144-byte buffer @0x88299CC0 (RT_ACKQUIESCE>=2) to mimic the full ACK.
      if(getenv("RT_ACKQUIESCE")){
        if(rt_be32(base,0x887AD1ACu)!=0){
          *(uint32_t*)(base+0x887AD1ACu)=0;
          if(atoi(getenv("RT_ACKQUIESCE"))>=2) std::memset(base+0x88299CC0u,0,6144);
          static std::atomic<int> ac{0}; int q=ac++;
          if(q<3||(q%500)==0) std::fprintf(stderr,"[ackq] present#%d cleared quiesce flag 0x887AD1AC #%d\n",p,q);
        }
      }
      // RT_RELOADCLR=1: each present, clear the scene reload flag *(0x887AD58C) so sub_88138F00
      // state-6 takes the r28!=1 path (menu tick) instead of jamming back to state-2 teardown.
      if(getenv("RT_RELOADCLR")){
        if(rt_be32(base,GA_MB_RELOAD)!=0){ *(uint32_t*)(base+GA_MB_RELOAD)=0;
          static std::atomic<int> rc{0}; int q=rc++;
          if(q<3||(q%500)==0) std::fprintf(stderr,"[reloadclr] present#%d cleared 0x887AD58C #%d\n",p,q); }
      }
      // RT_MODE64=<v>: seed the session-mode selector *(0x887AD584)=v (1=NORMAL PLAY) before/while
      // the menu is forced, so dispatch-1 snapshots a real mode and sub_88137708 avoids the d76=8
      // hang body (goes to d76=7, id=48 factory). Held every present until observed nonzero.
      if(const char* m64=getenv("RT_MODE64")){
        uint32_t v=(uint32_t)strtoul(m64,nullptr,0);
        if(rt_be32(base,GA_MB_MODE64)!=v){ *(uint32_t*)(base+GA_MB_MODE64)=__builtin_bswap32(v);
          static std::atomic<int> mc{0}; int q=mc++;
          if(q<3||(q%500)==0) std::fprintf(stderr,"[mode64] present#%d set 0x887AD584=%u #%d\n",p,v,q); }
      }

      // RT_KICKWORK=<present>:<hexhandle>: from that present on, signal the given event each
      // present. Deferred variant of RT_SIGEV (which fires from the FIRST vblank and pre-vivifies
      // the handle via rt_ev(k,true) — colliding with the deterministic boot handle order and
      // wedging shell boot; cost 4 flaked runs 2026-07-07). Use for the game worker event
      // (0x50000044 in the canonical boot order) to test the fsm-2 teardown wedge.
      if(const char* kw=getenv("RT_KICKWORK")){
        static int kw_at=-1; static uint32_t kw_h=0;
        if(kw_at<0){ kw_at=atoi(kw); const char* c=strchr(kw,':'); kw_h=c?(uint32_t)strtoul(c+1,nullptr,16):0x50000044u; }
        if(p>=kw_at && kw_h){
          PPCContext k{}; k.r3.u64=kw_h; __imp__NtSetEvent(k,base);
          static std::atomic<int> kc{0}; int q=kc++;
          if(q<3||(q%2000)==0) std::fprintf(stderr,"[kickwork] present#%d SetEvent(0x%X) #%d\n",p,kw_h,q);
        }
      }

      // RT_DUMPGUEST: one-shot guest heap+phys dump at present 12000 (asset-shader container
      // hunt — XenosRecomp scans the dump for ShaderContainer blobs).
      if(getenv("RT_DUMPGUEST")){ static bool dg_done=false;
        if(!dg_done && n>=12000){ dg_done=true;
          FILE* f=fopen("/tmp/guestheap.bin","wb");
          if(f){ fwrite(base+0x0C000000u,1,0x0C000000u,f); fclose(f); }
          FILE* g2=fopen("/tmp/guestphys.bin","wb");
          if(g2){ fwrite(base+0x38000000u,1,0x08000000u,g2); fclose(g2); }
          std::fprintf(stderr,"[dump] guest heap (0x0C000000+192MB) + phys (0x38000000+128MB) written\n"); } }

      // GATE 3: fire the SDK's loading-complete signal once, after the game has loaded assets.
      if(const char* ls=getenv("RT_LOADSIG")){
        static bool fired=false; int thresh=atoi(ls); if(thresh<=0) thresh=300;
        if(!fired && p>=thresh){
          fired=true;
          std::fprintf(stderr,"[loadsig] firing load-complete signal (msg15/msg11-state4/msg15) on modectx=0x%08X at present#%d\n",g_game_tick_modectx,p);
          { PPCContext c=ctx; c.r3.u32=g_game_tick_modectx;            __imp__sub_821C88E8(c,base); }  // msg 15
          { PPCContext c=ctx; c.r3.u32=g_game_tick_modectx; c.r4.u32=4; __imp__sub_821C85A0(c,base); }  // msg 11 state 4
          { PPCContext c=ctx; c.r3.u32=g_game_tick_modectx;            __imp__sub_821C88E8(c,base); }  // msg 15
          std::fprintf(stderr,"[loadsig] load-complete signal sent\n");
        }
      }
    }
  }

  // LEG-27/40 ring-window: cursor after the game pump -- the game's draw stream
  // (terrain + sprites) has been written into the ring by this point.
  if(g_d3d_device) g_vk_vd_pump.store(rt_be32(base,g_d3d_device+0x30));

  // --- RT_FORCEGATE: drive the shell past the idle modal so it re-authors a
  // content-bearing screen. loopobj = *(*(0x821F85A0)+152); the main loop
  // sub_821706E8 spins while status(loopobj+8)==0. Zeroing loopobj+0x3C makes
  // the guest's own sub_82173220 write status=2, exiting the loop -> next
  // screen. We repeat every ~40 frames while idle to advance several screens,
  // and log every loopobj/status transition. ---
  {
    static bool forcegate = getenv("RT_FORCEGATE")!=nullptr;
    if(forcegate){
      uint32_t r31g=rt_be32(base,0x821F85A0);
      uint32_t lo=(r31g&&r31g<0x40000000u)?rt_be32(base,r31g+152):0;
      if(lo&&lo<0x40000000u){
        uint32_t st=rt_be32(base,lo+8), v3c=rt_be32(base,lo+0x3C);
        static uint32_t last_lo=0, last_st=0xFFFFFFFF;
        if(lo!=last_lo||st!=last_st){
          std::fprintf(stderr,"[forcegate] frame=%d loopobj=0x%08X status=%u +3C=0x%08X%c",n,lo,st,v3c,10);
          last_lo=lo; last_st=st;
        }
        static int last_force=-1000;
        if(n>=20 && (n-last_force)>=40 && st==0){
          rt_wr32(base,lo+0x3C,0);
          std::fprintf(stderr,"[forcegate] frame=%d FORCED loopobj+0x3C 0x%08X->0 (advance screen)%c",n,v3c,10);
          last_force=n;
        }
      } else {
        static bool warned=false;
        if(!warned){ std::fprintf(stderr,"[forcegate] frame=%d no loopobj yet (r31g=0x%08X)%c",n,r31g,10); warned=true; }
      }
    }
  }
  static int capframe = [](){ const char* e=getenv("RT_CAPFRAME"); return e?atoi(e):7; }();

  // Dump the candidate stack slots (args 9+ live on the caller's stack per
  // PPC ABI; r1 = stack pointer). We scan +0x38.. +0x54 looking for the
  // width/height pair.
  char stackbuf[512]; int sp=0;
  uint32_t stackvals[8];
  for(int i=0;i<8;i++){ uint32_t off=0x38+ (uint32_t)i*4; stackvals[i]=rt_be32(base,ctx.r1.u32+off); }
  for(int i=0;i<8;i++){ sp+=std::snprintf(stackbuf+sp,sizeof(stackbuf)-sp," +%02X=0x%08X(%u)",0x38+i*4,stackvals[i],stackvals[i]); }

  if(n<8){
    std::fprintf(stderr,
      "[vdswap] #%d fb=0x%08X (r8*=0x%08X) w=%u h=%u fmt=0x%X lowmem=%d | stackargs r1+38..54:%s%c",
      n,fb_virtual,fb_ptr_target,w,h,fmt,lowmem,stackbuf,10);
    std::fprintf(stderr,
      "[vdswap] #%d raw: r3=0x%08X r4=0x%08X r5=0x%08X r6=0x%08X r7=0x%08X r8=0x%08X r9=0x%08X r10=0x%08X | fetch dwords: %08X %08X %08X %08X %08X %08X%c",
      n,buffer_ptr,fetch_ptr,writeback_ptr,cmdbuf6,cmdbuf7,frontbuffer_ptr,fmt,color_space,
      fetch_dw[0],fetch_dw[1],fetch_dw[2],fetch_dw[3],fetch_dw[4],fetch_dw[5],10);
  }

  // RT_CAPONPLAY=1: instead of a fixed present-count, capture the first frame where the
  // gameplay FSM (0x884D66A8) is in state 5 — so a lucky (flaky) gameplay run auto-captures a
  // complete, replayable game frame. Pair with RT_CAPLOW_MB=256 to include the >64MB textures.
  static bool g_capDone = false;
  bool capGate;
  if (getenv("RT_CAPONPLAY")) {
    uint32_t gfsm = rt_be32(base, 0x884D66A8u);
    // RT_CAPDELAY = number of FSM=5 frames to skip before capturing, so we grab a SETTLED
    // gameplay frame (green playfield + sprites) rather than the first (text/transitional) one.
    static int capDelay = getenv("RT_CAPDELAY") ? atoi(getenv("RT_CAPDELAY")) : 0;
    static long fsm5n = 0;
    if (gfsm == 5) { if (fsm5n++ == 0) std::fprintf(stderr,"[capture] gameplay FSM=5 reached at present#%d — arming (delay=%d)%c",n,capDelay,10); }
    capGate = (gfsm == 5 && (long)fsm5n > capDelay && n >= capframe && !g_capDone);
  } else {
    capGate = (n == capframe);
  }
  if(capGate){ g_capDone = true; // capture once for offline replay
    uint32_t rb_base=g_rb_base.load(), rb_log2=g_rb_log2.load();
    uint32_t rb_size_a=(1u<<(rb_log2+3))*4u; // formula per task: (1<<(log2+3))*4
    uint32_t rb_size_b=(1u<<rb_log2)*4u;     // alternate formula: (1<<log2)*4
    uint32_t wptr=rt_be32(base,0x7FC80714);

    auto dump=[&](const char* path,uint32_t addr,uint32_t len){
      FILE* f=std::fopen(path,"wb");
      if(!f){ std::fprintf(stderr,"[capture] FAILED to open %s%c",path,10); return; }
      std::fwrite(base+addr,1,len,f);
      std::fclose(f);
      std::fprintf(stderr,"[capture] wrote %s addr=0x%08X len=0x%X (%u bytes)%c",path,addr,len,len,10);
    };

    std::fprintf(stderr,"[capture] === capturing frame #%d for offline replay ===%c",n,10);
    std::fprintf(stderr,"[capture] ring_base=0x%08X ring_log2=%u ring_size_formula_a(1<<(log2+3))*4=0x%X ring_size_formula_b(1<<log2)*4=0x%X wptr=0x%08X%c",
      rb_base,rb_log2,rb_size_a,rb_size_b,wptr,10);

    // Primary: dump using formula A (task's stated formula). Guard against
    // absurd sizes (ring log2 is normally small, e.g. 12-20).
    uint32_t ring_dump_size=rb_size_a;
    if(ring_dump_size==0 || ring_dump_size>0x2000000u){ // cap at 32MB sanity
      std::fprintf(stderr,"[capture] WARNING ring_size_formula_a=0x%X looks implausible, capping dump%c",ring_dump_size,10);
      ring_dump_size = ring_dump_size? std::min(ring_dump_size,(uint32_t)0x2000000u) : rb_size_b;
    }
    dump("/tmp/cap_ring.bin", rb_base, ring_dump_size);
    // RT_CAPLOW_MB: how much low guest memory to dump (default 32MB). The GAME frame's draw
    // sources (VBs, textures, shader ucode, fetch data) live in the rt_alloc/phys heap up to
    // ~0x10000000 — use 256 for game-frame captures.
    { static uint32_t lowmb = [](){ const char* e=getenv("RT_CAPLOW_MB"); return e?(uint32_t)atoi(e):32u; }();
      dump("/tmp/cap_low.bin", 0x00000000u, lowmb*0x100000u); }
    dump("/tmp/cap_image.bin", 0x82000000u, 0x002B0000u);
    dump("/tmp/cap_gimage.bin", 0x88000000u, 0x007B0000u);   // game image (statics/ucode may be referenced)

    FILE* mf=std::fopen("/tmp/cap_manifest.txt","w");
    if(mf){
      std::fprintf(mf,"ring_base=0x%08X\n",rb_base);
      std::fprintf(mf,"ring_log2=%u\n",rb_log2);
      std::fprintf(mf,"ring_size_formula_a_1<<(log2+3)_times4=0x%X\n",rb_size_a);
      std::fprintf(mf,"ring_size_formula_b_1<<log2_times4=0x%X\n",rb_size_b);
      std::fprintf(mf,"ring_size_dumped=0x%X\n",ring_dump_size);
      std::fprintf(mf,"wptr=0x%08X\n",wptr);
      std::fprintf(mf,"fb_virtual=0x%08X\n",fb_virtual);
      std::fprintf(mf,"width=%u\n",w);
      std::fprintf(mf,"height=%u\n",h);
      std::fprintf(mf,"fmt=0x%X\n",fmt);
      std::fprintf(mf,"color_space=0x%X\n",color_space);
      std::fprintf(mf,"lowmem=%d\n",lowmem);
      std::fprintf(mf,"buffer_ptr=0x%08X\n",buffer_ptr);
      std::fprintf(mf,"fetch_ptr=0x%08X\n",fetch_ptr);
      std::fprintf(mf,"writeback_ptr=0x%08X\n",writeback_ptr);
      std::fprintf(mf,"frontbuffer_ptr=0x%08X\n",frontbuffer_ptr);
      std::fprintf(mf,"frontbuffer_ptr_target=0x%08X\n",fb_ptr_target);
      std::fprintf(mf,"fetch_dword_0=0x%08X\n",fetch_dw[0]);
      std::fprintf(mf,"fetch_dword_1=0x%08X\n",fetch_dw[1]);
      std::fprintf(mf,"fetch_dword_2=0x%08X\n",fetch_dw[2]);
      std::fprintf(mf,"fetch_dword_3=0x%08X\n",fetch_dw[3]);
      std::fprintf(mf,"fetch_dword_4=0x%08X\n",fetch_dw[4]);
      std::fprintf(mf,"fetch_dword_5=0x%08X\n",fetch_dw[5]);
      // The REAL ring cursor for the ACTIVE ring lives in the D3D device (r7 of VdSwap):
      // +0x30=ring write cursor (guest ptr), +0x38=ring end. The 0x7FC80714 MMIO mirror can be
      // stale (it tracks the FIRST ring). wptr_dwords = (ring_cur - ring_base)/4.
      { uint32_t dev=cmdbuf7;
        uint32_t rcur=rt_be32(base,dev+0x30), rend=rt_be32(base,dev+0x38);
        std::fprintf(mf,"device=0x%08X\n",dev);
        std::fprintf(mf,"ring_cur=0x%08X\n",rcur);
        std::fprintf(mf,"ring_end=0x%08X\n",rend);
        if(rcur>=rb_base) std::fprintf(mf,"wptr_dwords_from_cursor=0x%X\n",(rcur-rb_base)/4);
      }
      std::fclose(mf);
      std::fprintf(stderr,"[capture] wrote /tmp/cap_manifest.txt%c",10);
    } else {
      std::fprintf(stderr,"[capture] FAILED to open /tmp/cap_manifest.txt%c",10);
    }
    std::fprintf(stderr,"[capture] === capture complete ===%c",10);
  }

  // LEG-27/40 ring-window: cursor at VdSwap exit (after everything this impl ran).
  if(g_d3d_device) g_vk_vd_post.store(rt_be32(base,g_d3d_device+0x30));

  ctx.r3.u32=0; (void)base; }

// ================= D3D9 hook set (logging-only, no behavior change) =================
// Minimal UnleashedRecomp-style interception: every hook below just logs and then
// calls through to the original recompiled body via __imp__. Gated behind RT_D3D9
// so default runs stay quiet. Throttle: full detail for first ~8 calls per hook,
// then 1-in-500 thereafter, to keep the log bounded across a long run.
static bool rt_d3d9_on(){ static bool on=getenv("RT_D3D9")!=nullptr; return on; }
// returns true if this call index k should be logged in full
static bool rt_d3d9_throttle(long k){ return k<8 || (k%500==0); }

PPC_FUNC_IMPL(__imp__sub_820A4AC0); // D3D9 CreateDevice
PPC_FUNC(sub_820A4AC0){
  static std::atomic<long> n{0}; long k=n++;
  bool log = rt_d3d9_on() && rt_d3d9_throttle(k);
  if(log){
    std::fprintf(stderr,"[d3d9] CreateDevice #%ld pre r3=0x%08X r4=0x%08X r5=0x%08X r6=0x%08X r7=0x%08X r8=0x%08X r9=0x%08X r10=0x%08X%c",
      k,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,(unsigned)ctx.r5.u32,(unsigned)ctx.r6.u32,
      (unsigned)ctx.r7.u32,(unsigned)ctx.r8.u32,(unsigned)ctx.r9.u32,(unsigned)ctx.r10.u32,10);
  }
  uint32_t out_r7=ctx.r7.u32, out_r8=ctx.r8.u32;
  __imp__sub_820A4AC0(ctx,base);
  if(log){
    // ppOutDevice candidate: whichever of r7/r8 (pre-call) points at a slot that now
    // holds a plausible heap pointer. stw r11,0(r8) at entry showed r8 is the out-ptr
    // in the observed body, but check both defensively.
    uint32_t dev_r7 = out_r7? rt_be32(base,out_r7) : 0;
    uint32_t dev_r8 = out_r8? rt_be32(base,out_r8) : 0;
    std::fprintf(stderr,"[d3d9] CreateDevice #%ld post r3(status)=0x%08X *r7(0x%08X)=0x%08X *r8(0x%08X)=0x%08X%c",
      k,(unsigned)ctx.r3.u32,out_r7,dev_r7,out_r8,dev_r8,10);
  }
  if(ctx.r3.u32==0){ // S_OK
    uint32_t dev = out_r8? rt_be32(base,out_r8) : 0;
    if(!dev && out_r7) dev = rt_be32(base,out_r7);
    if(dev && dev<0x40000000u){
      g_d3d_device=dev;
      if(log) std::fprintf(stderr,"[d3d9] CreateDevice #%ld -> g_d3d_device=0x%08X%c",k,dev,10);
    }
  }
}


// ===== RT_RENDER: minimal host renderer — one-shot software composite at the 8th Present =====
// Proves the hook->parse->translate->rasterize loop: clear-color background + the static
// PM4 blob's draws rendered as flat quads. No shaders/textures yet (that needs XenosRecomp).
static bool rt_render_on(){ static bool on=getenv("RT_RENDER")!=nullptr; return on; }
static void rt_rect(uint8_t* img,int W,int H,int x0,int y0,int x1,int y1,uint32_t rgb,bool fill){
  if(x0>x1){int t=x0;x0=x1;x1=t;} if(y0>y1){int t=y0;y0=y1;y1=t;}
  if(x0<0)x0=0; if(y0<0)y0=0; if(x1>W-1)x1=W-1; if(y1>H-1)y1=H-1;
  for(int y=y0;y<=y1;y++)for(int x=x0;x<=x1;x++){
    if(!fill && x!=x0 && x!=x1 && y!=y0 && y!=y1) continue;
    uint8_t* p=img+(size_t)(y*W+x)*3; p[0]=(rgb>>16)&0xFF; p[1]=(rgb>>8)&0xFF; p[2]=rgb&0xFF; }
}
static void rt_render_maybe(uint8_t* base){
  if(!rt_render_on()||!g_d3d_device) return;
  static std::atomic<int> pc{0}; int k=pc++;
  if(k!=8) return; // one-shot
  const int W=1280,H=720; uint32_t dev=g_d3d_device;
  std::fprintf(stderr,"[render] one-shot at Present #%d dev=0x%08X\n",k,dev);
  // --- 1. clear color: inspect the two structs Clear() receives (fixed guest addrs) ---
  uint32_t cand=0, c1=0x003409D0, c2=0x00340A40;
  for(int i=0;i<8;i++){ std::fprintf(stderr,"[render] clearA+%02X=0x%08X clearB+%02X=0x%08X\n",i*4,rt_be32(base,c1+i*4),i*4,rt_be32(base,c2+i*4)); }
  for(int i=0;i<16 && !cand;i++){ uint32_t v=rt_be32(base,(i<8?c1:c2)+(i%8)*4);
    uint8_t a=v>>24; if((a==0xFF||a==0x00)&&(v&0x00FFFFFF)!=0x00FFFFFF&&v!=0) cand=v; }
  uint32_t bg = 0x101018; (void)cand; // neutral dark canvas; clear candidates logged (0x500/0x2D0 are dims, not color)
  std::fprintf(stderr,"[render] clear-color candidate=0x%08X -> bg=0x%06X %s\n",cand,bg,cand?"":"(fallback)");
  // --- 2. parse the static PM4 blob ---
  uint32_t blob=rt_be32(base,dev+13988);
  std::fprintf(stderr,"[render] blob=0x%08X\n",blob);
  int n_t0=0,n_t2=0,n_t3=0,n_draw=0; uint32_t draw_payload[64]; int op_count[128]={0};
  auto walk=[&](uint32_t at,uint32_t max_dw){
    uint32_t p=at,end=at+max_dw*4;
    while(p<end){ uint32_t h=rt_be32(base,p); uint32_t typ=h>>30;
      if(typ==0){ uint32_t cnt=((h>>16)&0x3FFF)+1; n_t0++; p+=4+cnt*4; }
      else if(typ==2){ n_t2++; p+=4; }
      else if(typ==3){ uint32_t op=(h>>8)&0x7F, cnt=((h>>16)&0x3FFF)+1; n_t3++; if(op<128)op_count[op]++;
        if(op==0x36||op==0x22){ if(n_draw<64) draw_payload[n_draw]=rt_be32(base,p+4); n_draw++; }
        p+=4+cnt*4; }
      else break; }
  };
  if(blob&&blob<0x02000000u){ walk(blob,0x800); }
  walk(0x006E1980,48); // the leaf draw IB
  std::fprintf(stderr,"[render] census: T0=%d T2=%d T3=%d draws=%d\n",n_t0,n_t2,n_t3,n_draw);
  for(int i=0;i<128;i++) if(op_count[i]) std::fprintf(stderr,"[render]   op 0x%02X x%d\n",i,op_count[i]);
  if(n_draw) std::fprintf(stderr,"[render] draw payload[0]=0x%08X (VGT_DRAW_INITIATOR: prim=%u srcsel=%u count=%u)\n",
    draw_payload[0],draw_payload[0]&0x3F,(draw_payload[0]>>6)&3,draw_payload[0]>>16);
  // --- 3. geometry recon: VB wrapper + vdecl ---
  uint32_t vbw=0x00358D70, vdecl=0x00359200, vbdata=0;
  for(int i=0;i<16;i++){ uint32_t v=rt_be32(base,vbw+i*4);
    std::fprintf(stderr,"[render] vbw+%02X=0x%08X\n",i*4,v);
    if(!vbdata && v>=0x00200000 && v<0x02000000 && (v&0xFFF)==0) vbdata=v; }
  for(int i=0;i<8;i++) std::fprintf(stderr,"[render] vdecl+%02X=0x%08X\n",i*4,rt_be32(base,vdecl+i*4));
  int got_pos=0; float px[128],py[128];
  if(vbdata){
    std::fprintf(stderr,"[render] vbdata=0x%08X first floats:",vbdata);
    for(int i=0;i<24;i++){ uint32_t v=rt_be32(base,vbdata+i*4); float f; std::memcpy(&f,&v,4);
      std::fprintf(stderr," %g",f); }
    std::fprintf(stderr,"\n");
    // heuristic: look for (x,y) pairs in screen range with common strides (2..8 floats)
    for(int stride=2;stride<=8 && !got_pos;stride++){
      int ok=0,nz=0; for(int i=0;i<48;i++){ uint32_t o=vbdata+(uint32_t)i*stride*4;
        uint32_t vx=rt_be32(base,o), vy=rt_be32(base,o+4); float fx,fy; std::memcpy(&fx,&vx,4); std::memcpy(&fy,&vy,4);
        if(fx>=-1400&&fx<=1400&&fy>=-800&&fy<=800){ if(ok<128){px[ok]=fx; py[ok]=fy;} ok++; if(fx!=0.f||fy!=0.f) nz++; } else break; }
      if(ok>=8 && nz>=ok/2){ got_pos=ok>128?128:ok; std::fprintf(stderr,"[render] positions: stride=%d floats, %d verts (%d nonzero)\n",stride,ok,nz); }
    }
    if(!got_pos && vbdata){
      std::fprintf(stderr,"[render] no position run at vbdata; floats 24..64:");
      for(int i=24;i<64;i++){ uint32_t v=rt_be32(base,vbdata+(uint32_t)i*4); float f; std::memcpy(&f,&v,4); std::fprintf(stderr," %g",f); }
      std::fprintf(stderr,"\n"); }
  }
  // --- 4. rasterize ---
  static uint8_t img[(size_t)1280*720*3];
  rt_rect(img,W,H,0,0,W-1,H-1,bg,true);
  const uint32_t pal[8]={0xE64545,0x45E645,0x4575E6,0xE6E645,0xE645E6,0x45E6E6,0xE69045,0x9045E6};
  if(got_pos>=8){
    float mx=0; for(int i=0;i<got_pos;i++){ float ax=px[i]<0?-px[i]:px[i], ay=py[i]<0?-py[i]:py[i]; if(ax>mx)mx=ax; if(ay>mx)mx=ay; }
    bool clip = mx<=2.0f;
    std::fprintf(stderr,"[render] path=REAL-POSITIONS (%d point sprites, %s space, max=%g)\n",got_pos,clip?"clip":"screen",mx);
    for(int i=0;i<got_pos;i++){
      int sx = clip ? (int)((px[i]*0.5f+0.5f)*W) : (int)px[i];
      int sy = clip ? (int)((-py[i]*0.5f+0.5f)*H) : (int)py[i];
      rt_rect(img,W,H,sx-12,sy-12,sx+12,sy+12,pal[i&7],true); }
  } else {
    std::fprintf(stderr,"[render] path=FALLBACK-GRID (positions not recoverable without shader constants)\n");
    int nd=n_draw?n_draw:24;
    for(int i=0;i<nd&&i<24;i++){ int gx=i%6, gy=i/6;
      int x0=40+gx*200, y0=80+gy*150;
      rt_rect(img,W,H,x0,y0,x0+180,y0+130,pal[i&7],false);
      rt_rect(img,W,H,x0+4,y0+4,x0+40,y0+24,pal[i&7],true); }
  }
  // --- 5. write PPM ---
  FILE* f=fopen("/tmp/menu_hookrender.ppm","wb");
  if(f){ std::fprintf(f,"P6\n%d %d\n255\n",W,H); fwrite(img,1,(size_t)W*H*3,f); fclose(f);
    std::fprintf(stderr,"[render] wrote /tmp/menu_hookrender.ppm\n"); }
  else std::fprintf(stderr,"[render] FAILED to open output\n");
}

// RT_VK: our own live Vulkan renderer (render/vk_render.cpp). The UnleashedRecomp-style
// integration point — the shell's guest D3D9 Present drives a real GPU. Step 1 = live
// clear-to-color; later this consumes the decoded Draw stream. Weakly declared so builds
// that don't link the renderer (futari_mode/futari_shell) still resolve to a no-op.
extern "C" void rvk_present(uint8_t* base, uint32_t frame_start, uint32_t frame_end) __attribute__((weak));
static bool rt_vk_on(){ static bool on=getenv("RT_VK")!=nullptr; return on; }

// [kick] LEG-27/40 ring-window: sub_820A8638 = the SHELL d3d9 primary-ring writer + kick
// (twin of the game's sub_88080298 -- see merged_xex.cpp). Every kick feeds
// rt_kick_capture(); the packet/index logging below is RVK_RINGPROBE-gated.
PPC_FUNC_IMPL(__imp__sub_820A8638);
PPC_FUNC(sub_820A8638){
  uint32_t dev=ctx.r3.u32;
  // RT_KICKARGS (2026-07-16): the primary ring is DEAD after early boot -- measured, the write index
  // (dev+0x2ACC) advanced only 4 times ever (all on the first ring 0x452000) and CP_RB_WPTR
  // (MMIO 0x7FC80714) is pinned at 0x1F across the whole run, while 985 later kicks show idx:19->19.
  // So submissions do NOT go through the ring; the kick itself must carry the segment. Log its args.
  if(getenv("RT_KICKARGS")){
    static std::atomic<long> ka{0}; long kn=ka.fetch_add(1);
    if(kn<24){
      // r6 == the ring triple's LEN (verified: kick#0 r6=0xB vs ring "C0013F00 0046A040 0000000B";
      // #1 0x44 vs 0045A000/00000044; #3 0x10D vs 0045A120/0000010D). So r4 must be the segment
      // OBJECT and one of its slots holds the buffer ADDRESS. Dump them to find which.
      char sb[240]; int o=0;
      for(int q=0;q<10 && o<220;q++) o+=std::snprintf(sb+o,sizeof(sb)-o," [%d]=%08X",q,rt_be32(base,ctx.r4.u32+4u*q));
      sb[o]=0;
      std::fprintf(stderr,"[kickargs] #%ld r4=0x%08X r5=0x%X r6(len_dw)=0x%X |%s\n",
        kn,(unsigned)ctx.r4.u32,(unsigned)ctx.r5.u32,(unsigned)ctx.r6.u32,sb);
    }
  }
  // r4/r6 are VOLATILE - read them BEFORE the original kick. The segment ADDRESS (r4[1]) is
  // dereferenced AFTER it returns, because the dev+0x5c10 callback can relocate the segment.
  uint32_t ks_obj=ctx.r4.u32, ks_len=ctx.r6.u32;
  // ★ RT_SEGTAB (FNF-7, 2026-07-26, measurement only): read the segment address BEFORE the kick
  // too. The shipped path deliberately dereferences ks_obj+4 only AFTER the kick because the
  // dev+0x5c10 callback can relocate the segment — so pre != post is exactly the Site-A
  // relocation race, and it is invisible unless both are recorded. This read has no side effect
  // and the value passed to rt_kick_capture is unchanged (still the post-kick deref).
  g_ks_curObj=ks_obj; g_ks_curLatLen=ks_len;
  g_ks_curPreAddr = (rt_segtab_on() && ks_obj) ? rt_be32(base,ks_obj+4u) : 0u;
  // ★ 2026-07-26 (FNF-7): the guest's OWN declared length, read HERE while the descriptor is live.
  // Real ABI of sub_820A8638 from raw PPC (asm_vtables.txt:149338+, corroborated by the vendored
  // Xenia CP in rexglue-sdk): r4 = array of 8-byte descriptors {word0, addr}, r5 = segment COUNT,
  // length = `lwz r11,0(r26); rlwinm r5,r11,0,8,31` = word0 & 0x00FFFFFF. r6 is NOT a parameter —
  // the callee assigns it (li r6,0x1) — so `ks_len = ctx.r6.u32` above is right only by accident on
  // this call path. Measurement only: nothing downstream consumes this yet.
  g_ks_curObjDw = (rt_segtab_on() && ks_obj) ? (rt_be32(base,ks_obj+0u) & 0x00FFFFFFu) : 0u;
  if(!rvk_ringprobe()){ __imp__sub_820A8638(ctx,base);
    rt_kick_capture(base,dev, ks_obj?rt_be32(base,ks_obj+4u):0u, ks_len); return; }
  uint32_t pre30=rt_be32(base,dev+0x30), preIdx=rt_be32(base,dev+10956);
  uint32_t ring=rt_be32(base,dev+15104), mask=rt_be32(base,dev+15108);
  __imp__sub_820A8638(ctx,base);
  rt_kick_capture(base,dev, ks_obj?rt_be32(base,ks_obj+4u):0u, ks_len);
  uint32_t post30=rt_be32(base,dev+0x30), postIdx=rt_be32(base,dev+10956);
  static std::atomic<long> n{0}; long k=n.fetch_add(1);
  if(k<400 || (k%97)==0){
    char buf[560]; int o=0; int guard=0;
    for(uint32_t i=preIdx; i!=postIdx && o<480 && guard<40; i=(i+1)&mask, ++guard)
      o+=std::snprintf(buf+o,sizeof(buf)-o," %08X",rt_be32(base,ring+4*(i&mask)));
    buf[o]=0;
    std::fprintf(stderr,"[kick] S#%ld dev=0x%X 30:0x%X->0x%X idx:%u->%u ring=0x%X mask=0x%X |%s\n",
      k,dev,pre30,post30,preIdx,postIdx,ring,mask,buf);
  }
}

// RT_DRAWTRACE state + helper (used by the Present latch below and the D3D draw/resolve hooks
// further down). See the block above sub_8209D800 for the full mechanism description.
static bool rt_drawtrace_on(){ static bool v=getenv("RT_DRAWTRACE")!=nullptr; return v; }
static long rt_drawtrace_at(){ static long v=getenv("RT_DRAWTRACE")?atol(getenv("RT_DRAWTRACE")):-1; return v; }
static bool g_dt_active=false, g_dt_done=false, g_dt_indexed=false;
static uint32_t g_dt_scratch=0,g_dt_prim=0,g_dt_count=0,g_dt_stride=0,g_dt_ic=0,g_dt_iw=0;
static void dt_flush(uint8_t* base){
  if(!g_dt_scratch || g_dt_scratch>=0x40000000u) { g_dt_scratch=0; return; }
  int nf=(int)(g_dt_stride/4); if(nf>8)nf=8; if(nf<0)nf=0;
  char b[320]; int o=0;
  for(int v=0; v<2 && v<(int)g_dt_count; ++v){ o+=std::snprintf(b+o,(size_t)(sizeof b-o)," v%d[",v);
    for(int k2=0;k2<nf;k2++){ union{uint32_t u; float f;} c; c.u=rt_be32(base,g_dt_scratch+(uint32_t)(v*(int)g_dt_stride)+(uint32_t)(4*k2));
      o+=std::snprintf(b+o,(size_t)(sizeof b-o),"%.1f ",(double)c.f);} o+=std::snprintf(b+o,(size_t)(sizeof b-o),"]"); }
  if(g_dt_indexed) std::fprintf(stderr,"[drawtrace] IDX prim=%u vtx=%u strideB=%u idxCount=%u idx%ub%s\n",g_dt_prim,g_dt_count,g_dt_stride,g_dt_ic,g_dt_iw,b);
  else             std::fprintf(stderr,"[drawtrace] prim=%u count=%u strideB=%u%s\n",g_dt_prim,g_dt_count,g_dt_stride,b);
  g_dt_scratch=0;
}
// ---- RT_HOOKRENDER: decode-free path — accumulate EVERY D3D-hooked draw + render via Vulkan ----
// Bypasses the PM4 window entirely (which sees only ~5-13 of ~99 menu draws). Each draw's exact
// verts (deferred read from the scratch VB) + its M2LibMatrix (device+0x780) are accumulated, and
// on Present the whole frame is handed to rvk_present_hooked(). Struct matches render/vk_render.h.
// Layout must match render/vk_render.h exactly (passed by pointer across the C ABI).
struct RvkHookDraw { uint32_t prim, count, stride, voff; float mtx[16]; uint32_t tf[6]; uint32_t blend; uint32_t rtwh; float vp[4]; };
extern "C" void rvk_present_hooked(uint8_t* base, const uint32_t* vpool, uint32_t vpoolDwords, const RvkHookDraw* draws, int nDraws) __attribute__((weak));
static bool rt_hookrender(){ static bool v=getenv("RT_HOOKRENDER")!=nullptr; return v; }
// RT_HYBRID (2026-07-12): per-present routing between the two renderers. RT_HOOKRENDER's D3D9-
// wrapper hooks see only shell/menu/dialog draws (they never observe the gameplay ring's real
// EDRAM tile-resolves -- avg 58 draws/present during the stage phase per RT_RINGCOUNT/RT_RINGDUMP,
// vs. the 35-quad dialog the hooks accumulate). The legacy PM4 decoder (renderFrameReal, driven
// from the non-hookrender branch below) implements the full ring decode + EDRAM resolve/composite
// pipeline and is what rendered this game's playfield on Linux -- but its GAMEPLAY output is
// UNPROVEN on Windows (only its menu decode is proven there). So: default off; when both
// RT_HOOKRENDER and RT_HYBRID are set, route gameplay-field-active presents to the legacy branch
// (exactly the code the non-hookrender path already runs) and everything else through hookrender.
static bool rt_hybrid_on(){ static bool v=getenv("RT_HYBRID")!=nullptr; return v; }
// GPU-submission-free register/ALU-const/VTE shadow-state keep-warm (render/vk_render.cpp). Weakly
// declared like rvk_present/rvk_present_hooked so non-renderer builds still link.
extern "C" void rvk_shadow_update(uint8_t* base, uint32_t start, uint32_t end) __attribute__((weak));
// device offset of the CURRENT sampler-0 texture fetch constant (6 dwords); env-tunable so we can
// probe the value the decomp finds without rebuilding. 0 => no texture (white).
static uint32_t rt_hktexoff(){ static uint32_t v=getenv("RT_HKTEXOFF")?(uint32_t)strtoul(getenv("RT_HKTEXOFF"),nullptr,0):0; return v; }
static RvkHookDraw g_hkd[8192]; static int g_hkdN=0;
static uint32_t* g_hkv=nullptr; static uint32_t g_hkvCap=0, g_hkvN=0;
static uint32_t g_hk_scratch=0, g_hk_count=0, g_hk_stride=0; static float g_hk_mtx[16]; static uint32_t g_hk_tf[6]; static uint32_t g_hk_blend=0;
// RT_COMPOSE render-target/viewport capture (2026-07-13, RT_VPPROBE device-diff findings):
// dev+0x28C8 = current render-target dims packed (h<<16|w); dev+0x2908..0x2914 = the viewport
// VTE floats {scaleX, offsetX, scaleY(neg), offsetY} in screen pixels. Wallpaper draw carries
// RT=1280x720 vp=(640,640,-360,360)=full screen; the playfield bloom-chain passes carry
// RT=320x240 — i.e. they render OFFSCREEN into the post-processing ring, not to the screen.
static uint32_t g_hk_rtwh=0; static float g_hk_vp[4]={640.f,640.f,-360.f,360.f};
// RT_WALLPAPER quad investigation (2026-07-13): the true D3D9 primitive type (ctx.r4, masked to
// the 6-bit Xenos prim field) was NEVER captured -- hk_flush() hardcoded RvkHookDraw.prim=5 (fan)
// unconditionally. A 3-vertex D3DPT_RECTLIST draw (hardware auto-derives the 4th rect corner as
// v3=v1+v2-v0, exactly like the already-proven legacy PM4 RECTLIST path in render/vk_render.cpp
// ~line 1744) would be silently mis-tagged as a degenerate 3-vertex fan and dropped by
// renderHookedFrame's "count<4" fan-quad-only filter. Capture the real value so the renderer can
// tell the two apart.
static uint32_t g_hk_prim=5;
static long g_hk_present=0;
// RT_HKTRACE diagnostic (Windows-vs-Linux draw-sustain investigation 2026-07-12): raw count of
// sub_8209D800 (D3D9 Draw) invocations since the last Present, to disambiguate "guest stopped
// drawing" (calls->0 = control-flow/threading divergence) from "hook rejected the draws"
// (calls high but accepted g_hkdN->0 = guest-memory-read/validation divergence).
static std::atomic<long> g_hk_calls{0};
// RT_HKDUP2 investigation (2026-07-12, blank stage phase): count of sub_8209DCE0 (D3D9
// DrawIndexedVertices core) calls since the last Present. The RT_HOOKRENDER capture hooks ONLY
// sub_8209D800 (non-indexed Draw) -- if the gameplay/stage scene issues its playfield through
// the INDEXED path, those draws are invisible to the hook while [hktrace] still reports the
// non-indexed chrome. A nonzero idx count during the blank phase confirms hypothesis 3.
static std::atomic<long> g_hk_idx_calls{0};
// RB_BLENDCONTROL (reg 0x2201) shadow offset on g_d3d_device; env-tunable (RT_HKBLENDOFF) like the
// texture offset so we can probe without rebuilding. 0 => don't capture (renderer uses default blend).
static uint32_t rt_hkblendoff(){ static uint32_t v=getenv("RT_HKBLENDOFF")?(uint32_t)strtoul(getenv("RT_HKBLENDOFF"),nullptr,0):0x2938u; return v; }
static void hk_read_blend(uint8_t* base){
  uint32_t dev=g_d3d_device, off=rt_hkblendoff();
  g_hk_blend = (dev && off) ? rt_be32(base, dev+off) : 0u;
  static int dbg=getenv("RT_HKBLENDDBG")?atoi(getenv("RT_HKBLENDDBG")):0; static int dn=0;
  if(dbg && dn++<dbg) std::fprintf(stderr,"[hkblend] p=%ld blend=0x%08X\n",g_hk_present,g_hk_blend);
}
static void hk_read_matrix(uint8_t* base){
  uint32_t dev=g_d3d_device;
  if(!dev){ for(int i=0;i<16;i++) g_hk_mtx[i]=(i%5==0)?1.f:0.f; return; }
  for(int i=0;i<16;i++){ union{uint32_t u;float f;}c; c.u=rt_be32(base,dev+0x780u+(uint32_t)i*4); g_hk_mtx[i]=c.f; }
}
static void hk_read_vprt(uint8_t* base){
  uint32_t dev=g_d3d_device;
  if(!dev){ g_hk_rtwh=(720u<<16)|1280u; g_hk_vp[0]=640.f; g_hk_vp[1]=640.f; g_hk_vp[2]=-360.f; g_hk_vp[3]=360.f; return; }
  g_hk_rtwh=rt_be32(base,dev+0x28C8u);
  for(int i=0;i<4;i++){ union{uint32_t u;float f;}c; c.u=rt_be32(base,dev+0x2908u+(uint32_t)i*4); g_hk_vp[i]=c.f; }
}
static long rt_hktexafter(){ static long v=getenv("RT_HKTEXAFTER")?atol(getenv("RT_HKTEXAFTER")):0; return v; }
static void hk_read_tex(uint8_t* base){
  uint32_t dev=g_d3d_device, off=rt_hktexoff();
  if(!dev||!off || g_hk_present<rt_hktexafter()){ for(int i=0;i<6;i++) g_hk_tf[i]=0; return; }
  for(int i=0;i<6;i++) g_hk_tf[i]=rt_be32(base,dev+off+(uint32_t)i*4);
  static int dbg=getenv("RT_HKTEXDBG")?atoi(getenv("RT_HKTEXDBG")):0; static int dn=0;
  if(dbg && dn++<dbg){ uint32_t b=((g_hk_tf[1]>>12)&0xFFFFF)<<12, w=(g_hk_tf[2]&0x1FFF)+1, h=((g_hk_tf[2]>>13)&0x1FFF)+1, f=g_hk_tf[1]&0x3F;
    // tf0 = fetch dword_0: bit31 = tiled, bits 22..30 = linear row pitch in 32-texel units
    // (RVK_HKTILEFLAG wallpaper-banding investigation 2026-07-13).
    std::fprintf(stderr,"[hktex] p=%ld tf0=0x%08X tf1=0x%08X tf2=0x%08X -> base=0x%X %ux%u fmt=%u tiled=%u pitch=%u\n",
      g_hk_present,g_hk_tf[0],g_hk_tf[1],g_hk_tf[2],b,w,h,f,(unsigned)(g_hk_tf[0]>>31),(unsigned)(((g_hk_tf[0]>>22)&0x1FFu)<<5)); }
}
// ---- RT_LRBAND (2026-07-26, D1-B provenance INSTRUMENT — not a gate) --------------------------
// Logs each DISTINCT (caller LR, texBase, vtxCount) of the shell D3D Draw cores with the draw's
// first two vertex XYs (deferred read from the scratch VB at the NEXT hook entry — same mechanism
// as dt_flush) plus the M2LibMatrix translation. Purpose: NAME the guest emitter of the D1-B
// 加速×1 strip text by joining these rows against [ovbatch] output (cnt + v0 XY + atlas).
// RT_LRBAND_X0/X1/Y0/Y1 optionally filter the LOG by v0 position — doctrine permits position in
// instruments, never in shipped gates (NOTE_field_gfx_defects.md leg-35+). Needs RT_HKTEXOFF=0x480
// for texBase. EXCLUSIVE with RT_HOOKRENDER / RT_DRAWTRACE (each takes its own branch + return).
// Default OFF; zero overhead when unset.
static bool rt_lrband(){ static bool v=getenv("RT_LRBAND")!=nullptr; return v; }
static float rt_lrband_f(const char* nm, float d){ const char* e=getenv(nm); return e?(float)atof(e):d; }
static uint32_t g_lb_scratch=0,g_lb_count=0,g_lb_stride=0,g_lb_lr=0,g_lb_tex=0; static int g_lb_idx=0;
static uint32_t g_lb_lr2=0,g_lb_lr3=0;
static float g_lb_tx=0.f,g_lb_ty=0.f;
// Every sprite quad reaches sub_8209D800 with lr=0x8209DCBC — an internal call site inside the
// D3D lib's public wrapper pair sub_8209DC94/sub_8209DC98 (leg-35 first-run lesson: ctx.lr at the
// core names that wrapper, not the emitter; a PPC back-chain walk returned heap garbage — the lib
// keeps no walkable ABI frame there). So the wrappers below latch THEIR caller's LR (= the real
// emitter return address) into g_lb_wraplr, and lb_stash logs it as lr2.
static uint32_t g_lb_wraplr=0;
// leg-35 stage-1: NODE identity. sub_8216DAA0 is the generic sprite/quad draw method that owns the
// bl at 0x8216DD58 (-> the universal lr2=0x8216DD5C). Its entry regs are latched here: r3 = the
// object the method is invoked on (decomp FUN_8216daa0 param_1), r4 = the per-quad descriptor
// (param_2: +0 texobj, +4 flags, +8/+0xC src w/h, verts from +0x14), and ctx.lr = the CALLER of the
// generic method (3 known direct sites 0x82164FDC / 0x82169208 / 0x82169374 + a dispatch-table
// entry at 0x82057CA8) -> the emitter one level above the shared draw core, logged as lr3.
static uint32_t g_lb_node=0,g_lb_qd=0,g_lb_nlr=0;          // latched at sub_8216DAA0 entry
static uint32_t g_lb_nodep=0,g_lb_qdp=0;                    // copied per-draw by lb_stash
// leg-35 run-2: r3 at sub_8216DAA0 turned out to be the *renderer singleton* (decomp:
// *(DAT_821F85B0+0x9c)) and lr3 a single site 0x8216920C inside sub_82168E58 -> no identity there.
// So (a) latch r3/lr at sub_82168E58 (the virtual glyph/sprite emit method, dispatch-table entry
// 0x82057B10) whose r3 IS a per-object instance, and (b) walk the guest PPC back chain from that
// frame for the callers above it. Xenon linkage: [sp]=back chain, LR save slot is +4 or +8 -> both
// candidates are probed and the one that looks like shell text (0x82xxxxxx) wins.
static uint32_t g_lb_obj=0,g_lb_objlr=0,g_lb_chain[5]={0,0,0,0,0},g_lb_sp=0,g_lb_sp2=0;
// Innermost 5 VIRTUAL-dispatch frames (target fn @ this-pointer) captured at the draw core.
static uint32_t g_lb_vt[5]={0,0,0,0,0},g_lb_vr[5]={0,0,0,0,0};
static uint32_t g_lb_vtp[5]={0,0,0,0,0},g_lb_vrp[5]={0,0,0,0,0};
static int g_lb_vd=0,g_lb_vdp=0;
static uint32_t g_lb_objp=0,g_lb_objlrp=0,g_lb_chainp[5]={0,0,0,0,0};
// Arming: RT_LRBAND_ARM=1 keeps the probe silent until the SYSTEM MENU is built (merged_xex.cpp's
// [p0build] sub_821D05E8 hook sets g_lb_armed) so the row budget is spent on the held-menu window
// instead of on attract.
extern "C" { volatile int g_lb_armed = 0; }
static bool rt_lrband_arm(){ static bool v=getenv("RT_LRBAND_ARM")!=nullptr; return v; }
static bool lb_code(uint32_t a){ return a>=0x82000000u && a<0x82400000u; }
static void lb_walk(uint8_t* base, uint32_t sp, uint32_t* out, int n){
  for(int i=0;i<n;i++) out[i]=0;
  // NB: guest THREAD STACKS are not in the <0x40000000 heap window the other probes assume, so the
  // bound here is the whole low guest map; the monotonic + max-frame-size checks keep a garbage
  // back chain from walking off into unmapped pages.
  for(int i=0;i<n;i++){
    if(sp<0x1000u || sp>=0x80000000u || (sp&3)) return;
    uint32_t a=rt_be32(base,sp+4), b=rt_be32(base,sp+8);
    out[i]= lb_code(a)?a : (lb_code(b)?b:0);
    uint32_t nx=rt_be32(base,sp);
    if(nx<=sp || nx-sp>0x20000u || nx>=0x80000000u) return;
    sp=nx;
  }
}
// std::string SSO convention, proven by the [p0build] item dump in merged_xex.cpp:
//   obj+0x00 = inline char[16] OR char* (when capacity >= 0x10); obj+0x10 = size; obj+0x14 = cap.
static bool lb_name_at(uint8_t* base, uint32_t so, char* out, size_t n){
  if(!so || so>=0x40000000u || (so&3)) return false;
  uint32_t len=rt_be32(base,so+0x10), cap=rt_be32(base,so+0x14);
  if(len<1 || len>23 || cap<len || cap>0x400) return false;
  uint32_t p=(cap<0x10)?so:rt_be32(base,so);
  if(!p || p>=0x40000000u) return false;
  size_t i=0; for(; i<len && i+1<n; i++){ char c=(char)base[p+i]; if(c<0x20||c>0x7e) return false; out[i]=c; }
  out[i]=0; return i>0;
}
static bool lb_find_name(uint8_t* base, uint32_t obj, char* out, size_t n, uint32_t* offOut){
  if(!obj || obj>=0x40000000u) return false;
  for(uint32_t o=0;o<=0x1fcu;o+=4) if(lb_name_at(base,obj+o,out,n)){ if(offOut)*offOut=o; return true; }
  return false;
}
static void lb_flush(uint8_t* base){
  if(!g_lb_scratch || g_lb_scratch>=0x40000000u){ g_lb_scratch=0; return; }
  float xy[4]={0.f,0.f,0.f,0.f};
  int nv=(int)g_lb_count; if(nv>2)nv=2; if(g_lb_stride<8) nv=0;
  for(int v=0;v<nv;v++) for(int k2=0;k2<2;k2++){ union{uint32_t u;float f;}c;
    c.u=rt_be32(base,g_lb_scratch+(uint32_t)v*g_lb_stride+(uint32_t)(4*k2)); xy[v*2+k2]=c.f; }
  static float bx0=rt_lrband_f("RT_LRBAND_X0",-1e9f),bx1=rt_lrband_f("RT_LRBAND_X1",1e9f),
               by0=rt_lrband_f("RT_LRBAND_Y0",-1e9f),by1=rt_lrband_f("RT_LRBAND_Y1",1e9f);
  if((!rt_lrband_arm()||g_lb_armed) && xy[0]>=bx0&&xy[0]<=bx1&&xy[1]>=by0&&xy[1]<=by1){
    static std::set<uint64_t> seen; static long budget=0;
    // key = (lr2, lr3, node, cnt, quantized v0 XY) so distinct NODES and distinct text runs at
    // distinct screen positions each print once (position in an INSTRUMENT key is doctrine-legal).
    uint64_t key=((uint64_t)g_lb_lr2<<32)^((uint64_t)g_lb_lr3<<8)^((uint64_t)g_lb_objp)
               ^((uint64_t)g_lb_count<<44)^((uint64_t)g_lb_idx<<63)^((uint64_t)g_lb_stride<<52)
               ^((uint64_t)(int32_t)(xy[0]*4.f)<<20)^((uint64_t)(int32_t)(xy[1]*4.f)<<36);
    if(seen.insert(key).second && budget++<20000){
      char vb[400]; int vp=0; vb[0]=0;
      for(int i=0;i<5;i++){
        char vn[32]; uint32_t vo=0; const char* vns="-";
        if(lb_find_name(base,g_lb_vrp[i],vn,sizeof vn,&vo)) vns=vn; else vo=0xFFFF;
        vp+=std::snprintf(vb+vp,sizeof(vb)-(size_t)vp,"%s%08X@%08X<%X:%s",i?" | ":"",g_lb_vtp[i],g_lb_vrp[i],vo,vns);
        if(vp>=(int)sizeof(vb)-1) break;
      }
      char nm[32]; uint32_t no=0; const char* nms="-";
      if(lb_find_name(base,g_lb_objp,nm,sizeof nm,&no)) nms=nm; else no=0xFFFF;
      // one-shot raw field dump per distinct text-path emitter object (stage-2 gate hunt)
      if(g_lb_lr3==0x82164FE0u && g_lb_objp && g_lb_objp<0x40000000u){
        static std::set<uint32_t> dumped;
        if(dumped.insert(g_lb_objp).second){
          for(uint32_t r=0;r<0x40;r+=8){
            std::fprintf(stderr,"[lrbobj] 0x%08X +%02X:",g_lb_objp,r*4);
            for(uint32_t c=0;c<8;c++) std::fprintf(stderr," %08X",rt_be32(base,g_lb_objp+(r+c)*4));
            std::fprintf(stderr,"\n");
          }
        }
      }
      std::fprintf(stderr,"[lrband]%s lr3=0x%08X sp=0x%08X obj=0x%08X nm@%X=%s olr=0x%08X d=%d vstk=[%s] cnt=%u strideB=%u tex=0x%07X v0=(%.1f,%.1f) v1=(%.1f,%.1f) tx=%.1f ty=%.1f\n",
        g_lb_idx?" IDX":"",g_lb_lr3,g_lb_sp2,g_lb_objp,no,nms,g_lb_objlrp,g_lb_vdp,vb,
        g_lb_count,g_lb_stride,g_lb_tex,
        (double)xy[0],(double)xy[1],(double)xy[2],(double)xy[3],(double)g_lb_tx,(double)g_lb_ty);
    }
  }
  g_lb_scratch=0;
}
static void lb_stash(uint8_t* base, PPCContext& ctx, uint32_t lr, uint32_t sp, uint32_t count, uint32_t strideB, int indexed){
  (void)base; (void)sp;
  g_lb_scratch=ctx.r3.u32; g_lb_count=count; g_lb_stride=strideB; g_lb_lr=lr; g_lb_idx=indexed;
  g_lb_lr2=g_lb_wraplr; g_lb_lr3=g_lb_nlr; g_lb_wraplr=0;  // lr2 = wrapper latch (0 = direct call)
  g_lb_nodep=g_lb_node; g_lb_qdp=g_lb_qd;                  // lr3/node/qd = sub_8216DAA0 entry latch
  g_lb_objp=g_lb_obj; g_lb_objlrp=g_lb_objlr; g_lb_sp2=g_lb_sp; g_lb_vdp=g_lb_vd;
  for(int i=0;i<5;i++){ g_lb_vtp[i]=g_lb_vt[i]; g_lb_vrp[i]=g_lb_vr[i]; }              // obj/olr/up = sub_82168E58 entry latch
  for(int i=0;i<5;i++) g_lb_chainp[i]=g_lb_chain[i];
  g_lb_tex = g_hk_tf[1] ? (((g_hk_tf[1]>>12)&0xFFFFF)<<12) : 0u;
  g_lb_tx=g_hk_mtx[3]; g_lb_ty=g_hk_mtx[7];
}
static void hk_flush(uint8_t* base){
  if(!g_hk_scratch || g_hk_scratch>=0x40000000u){ g_hk_scratch=0; return; }
  uint32_t sd=g_hk_stride/4;
  if(sd<1||sd>32||g_hk_count<1||g_hk_count>4096){ g_hk_scratch=0; return; }
  uint32_t need=g_hk_count*sd;
  if(!g_hkv){ g_hkvCap=(8u<<20); g_hkv=(uint32_t*)malloc((size_t)g_hkvCap*4); if(!g_hkv){ g_hk_scratch=0; return; } }
  if(g_hkvN+need>g_hkvCap || g_hkdN>=8192){ g_hk_scratch=0; return; }
  uint32_t off=g_hkvN;
  for(uint32_t k=0;k<need;k++) g_hkv[g_hkvN++]=rt_be32(base,g_hk_scratch+k*4);
  RvkHookDraw hd; hd.prim=g_hk_prim; hd.count=g_hk_count; hd.stride=sd; hd.voff=off; hd.blend=g_hk_blend;
  for(int i=0;i<16;i++) hd.mtx[i]=g_hk_mtx[i];
  for(int i=0;i<6;i++) hd.tf[i]=g_hk_tf[i];
  hd.rtwh=g_hk_rtwh; for(int i=0;i<4;i++) hd.vp[i]=g_hk_vp[i];
  g_hkd[g_hkdN++]=hd; g_hk_scratch=0;
}
// ---- RT_RINGCOUNT (2026-07-12): count-only PM4-ring probe, run ALONGSIDE RT_HOOKRENDER --------
// Discriminator for the Windows-stage-phase "~35 draws/present" plateau: does the guest genuinely
// stop drawing (progression), or does gameplay content flow through the PM4 command RING (which
// RT_HOOKRENDER's D3D9-wrapper hooks never see -- they only capture per-call Draw()/DrawIndexed()
// args) instead of through the hooked D3D calls? Walks the SAME ring window the legacy (non-
// hookrender) decode path would have used -- the LEG-27/40 kick-capture arena when this present
// had kicks, else the [rb+0x8000, cursor-at-entry) fallback -- but only COUNTS packets (DRAW_INDX
// / DRAW_INDX_2 draws + RB_COPY-classified resolves), mirroring renderFrameReal's packet walk
// (render/vk_render.cpp) and resolve-shape classification 1:1, without touching Vulkan. Default
// off (an extra full ring walk every present is not free); gated behind RT_RINGCOUNT.
static bool rt_ringcount_on(){ static bool v=getenv("RT_RINGCOUNT")!=nullptr; return v; }
// vtxsnap=true (RT_VTXSNAP, 2026-07-12, see rt_kick_capture): the SAME walk, but additionally
// tracks the vertex-fetch base (reg 0x48BE) and, per content draw, snapshots its vertex bytes
// and rewrites the tracked setter dword in the arena copy (details at the RT_VTXSNAP comment).
static void rt_ringcount_scan(uint8_t* base, uint32_t start, uint32_t end, long& pm4draws, long& resolves, bool vtxsnap){
  uint32_t modectl=0;   // shadow of RB_MODECONTROL (reg 0x2208) -- feeds the resolve-shape gate
  uint32_t i=start; int guard=0;
  uint64_t ibStack[8]; int ibDepth=0;   // (return_i<<32)|return_end, mirrors renderFrameReal's ibStack
  // RT_VTXSNAP walker state: last-seen vf0 (0x48BE) value, the arena address of the dword that
  // set it (0 = unknown / inside an IB / already rewritten -> not rewritable), and the byte span
  // of the last snapshot (for shared-setter accounting). Seeded from / stored back to globals so
  // a setter in an earlier SEGMENT of the same capture window still gets rewritten.
  uint32_t vf0 = vtxsnap? g_vs_vf0 : 0;
  uint32_t setter = vtxsnap? g_vs_setter : 0;
  uint32_t snapLen = vtxsnap? g_vs_snaplen : 0;
  while(guard++<60000){
    if(i+4>end){
      if(ibDepth==0) break;
      uint64_t v=ibStack[--ibDepth]; i=(uint32_t)(v>>32); end=(uint32_t)v; continue;
    }
    uint32_t w=rt_be32(base,i); uint32_t t=w>>30;
    if(t==0){
      uint32_t reg=w&0x7fffu, cnt=((w>>16)&0x3fffu)+1;
      if(i+4+cnt*4>end+64) break;
      if(reg<=0x2208u && reg+cnt>0x2208u) modectl=rt_be32(base,i+4+(0x2208u-reg)*4);
      if(vtxsnap && reg<=0x48BEu && reg+cnt>0x48BEu){  // type-0 write covering the vfetch base
        uint32_t at=i+4+(0x48BEu-reg)*4;
        vf0=rt_be32(base,at); setter=(ibDepth==0)?at:0; snapLen=0;
      }
      i+=4*(1+cnt);
    } else if(t==3){
      uint32_t op=(w>>8)&0x7fu, cnt=((w>>16)&0x3fffu)+1;
      if(vtxsnap && op==0x2Du && cnt>=2){  // SET_CONSTANT: type 1 = fetch consts @0x4800 shadow
        uint32_t offType=rt_be32(base,i+4);
        uint32_t idx=offType&0x7FFu, ctype=(offType>>16)&0xFFu;
        if(ctype==1u){
          uint32_t rbase=0x4800u+idx;      // payload dwords start at i+8, count = cnt-1
          if(rbase<=0x48BEu && rbase+(cnt-1)>0x48BEu){
            uint32_t at=i+8+(0x48BEu-rbase)*4;
            vf0=rt_be32(base,at); setter=(ibDepth==0)?at:0; snapLen=0;
          }
        }
        i+=4*(1+cnt);
      } else if(vtxsnap && op==0x32u && cnt>=3){  // LOAD_ALU_CONSTANT covering 0x48BE: the value
        uint32_t maddr=rt_be32(base,i+4)&0x3FFFFFFFu;  // is fetched from guest memory at DECODE
        uint32_t offType=rt_be32(base,i+8);            // time -- nothing in the arena to rewrite,
        uint32_t idx=offType&0x7FFu, ctype=(offType>>16)&0xFFu;  // so mark unrewritable (skip).
        uint32_t szDw=rt_be32(base,i+12)&0xFFFu;
        if(ctype==1u){
          uint32_t rbase=0x4800u+idx;
          if(rbase<=0x48BEu && rbase+szDw>0x48BEu && maddr){
            vf0=rt_be32(base,maddr+(0x48BEu-rbase)*4); setter=0; snapLen=0;
          }
        }
        i+=4*(1+cnt);
      } else if(op==0x22u||op==0x36u){ // DRAW_INDX / DRAW_INDX_2 (see renderFrameReal for the offset note)
        uint32_t initOff=(op==0x36u)?4u:8u;
        uint32_t initw=rt_be32(base,i+initOff);
        uint32_t n=(initw>>16)&0xFFFFu, prim=initw&0x3Fu;
        bool isResolve=((modectl&7u)==6u) && (n>2048u||prim==0u);  // same shape gate as vk_render.cpp
        if(isResolve) resolves++; else pm4draws++;
        if(vtxsnap && !isResolve){
          // RT_VTXSNAP: snapshot this draw's vertices + retarget the setter in the arena copy.
          // Span mirrors the decoder's worst-case per-draw read: n records at stride <=24
          // (renderFrameReal reads 24B float records; vs=48 int records are 16B; +32 slack for
          // the RECTLIST 4th-corner derivation / dump reads past the last record). Gates mirror
          // the decoder's content gate (va nonzero, 3<=n<=1024=RVK_NMAX default); anything that
          // can't be bounded safely is SKIPPED (left pointing at guest RAM), never mis-copied.
          uint32_t va=vf0&~3u;
          uint32_t need=n*24u+32u;
          if(va && va<0xFF000000u && n>=3u && n<=1024u){
            if(setter){
              if(!g_vtxsnap_arena) g_vtxsnap_arena=rt_alloc(g_vtxsnap_size,0x1000);
              uint32_t off=(g_vtxsnap_off+15u)&~15u;
              if(off+need>g_vtxsnap_size) off=0;               // ring wrap (each snapshot contiguous)
              if(g_vtxsnap_arena){
                std::memcpy(base+g_vtxsnap_arena+off, base+va, need);
                uint32_t nvf0=(g_vtxsnap_arena+off)|(vf0&3u);  // keep low 2 bits (fetch type):
                *(uint32_t*)(base+setter)=__builtin_bswap32(nvf0);  // decoder does va=vf0&~3u
                g_vtxsnap_off=off+need;
                vf0=nvf0; setter=0; snapLen=need;  // a later draw reusing this setter reads the
                g_vs_snaps++;                      // same snapshot (same kick-time bytes) -- correct
                if(g_vs_snaps<=3||(g_vs_snaps%50000)==0)
                  std::fprintf(stderr,"[vtxsnap] snap#%ld va=0x%X n=%u -> 0x%X (ringoff=%u skips=%ld)\n",
                    g_vs_snaps,va,n,nvf0&~3u,g_vtxsnap_off,g_vs_skips);
              }
            } else if(snapLen && need>snapLen){ g_vs_skips++; }  // shared setter, larger span: can't extend
          } else if(va) g_vs_skips++;
        }
        // RT_RINGDUMP=N (2026-07-12, companion to RT_RINGCOUNT): print up to N raw draw-packet
        // headers (op/n/prim/modectl) so the pm4draws count can be characterized, not just sized.
        // Gated to the gameplay-field-active window (0x885C1A20) so the dump samples the STAGE
        // phase's ring content, not shell-boot/menu draws that also flow through the same window.
        static long dumpBudget = getenv("RT_RINGDUMP")?atol(getenv("RT_RINGDUMP")):0;
        if(dumpBudget>0 && rt_game_field_active(base)){ --dumpBudget;
          std::fprintf(stderr,"[ringdump] op=0x%02X n=%u prim=%u cnt=%u modectl=0x%08X isResolve=%d\n",
            op,n,prim,cnt,modectl,(int)isResolve); }
        i+=4*(1+cnt);
      } else if(op==0x3Fu){ // INDIRECT_BUFFER: descend so ring-linked content isn't missed
        uint32_t ibBase=rt_be32(base,i+4)&~3u, ibSize=rt_be32(base,i+8)&0xFFFFFu;
        uint32_t next=i+4*(1+cnt);
        if(ibBase && ibSize && ibSize<0x100000u && ibDepth<8){
          ibStack[ibDepth++]=((uint64_t)next<<32)|end; i=ibBase; end=ibBase+ibSize*4;
        } else i=next;
        continue;
      } else i+=4*(1+cnt);
    } else if(t==2){ i+=4; }
    else break;
  }
  // RT_VTXSNAP: persist walker state for the NEXT segment of this capture window (reset in
  // rt_kick_capture when a fresh window starts).
  if(vtxsnap){ g_vs_vf0=vf0; g_vs_setter=setter; g_vs_snaplen=snapLen; }
}
// ★ g_rt_presentN (2026-07-31, alpha2 TITLE-CADENCE leg): the guest-Present counter, published
// so GUEST-SIDE tick hooks can stamp themselves with the present index. This is the only way to
// measure the tick-vs-present cadence at the altitude where a "welded clock" class would show:
// the shell's main loop is tick->draw->present welded (SPEC §10, FUN_821706E8 -> FUN_8216EA68 ->
// FUN_8216B148), so a guest state fn that ticks N times while Present advances != N is, by
// construction, a pacing defect. Always maintained (one store per present, no branch); read by
// the RVK_TITLEPROBE hooks in out_reco/merged/merged_shell.cpp.
extern "C" { long g_rt_presentN = 0; }
PPC_FUNC_IMPL(__imp__sub_820A5408); // D3D9 Present
PPC_FUNC(sub_820A5408){
  NVK_TAP("Present");
  static std::atomic<long> n{0}; long k=n++;
  g_rt_presentN = k + 1;
  // RT_DRAWTRACE window latch: capture presents [RT_DRAWTRACE, RT_DRAWTRACE+120). Each present
  // flushes the draws of the frame that just ended (they run between presents), so a menu frame
  // (many draws) shows all its geometry between its markers. Grep for a present with many draws.
  if(rt_drawtrace_on()){
    if(g_dt_active){ dt_flush(base); std::fprintf(stderr,"[drawtrace] --- end present#%ld ---\n",k-1); }
    long at=rt_drawtrace_at();
    g_dt_active = (k>=at && k<at+120);
    if(g_dt_active) std::fprintf(stderr,"[drawtrace] === frame present#%ld ===\n",k);
    (void)g_dt_done;
  }
  bool log = rt_d3d9_on() && rt_d3d9_throttle(k);
  if(log) std::fprintf(stderr,"[d3d9] Present frame=%ld r3=0x%08X%c",k,(unsigned)ctx.r3.u32,10);
  // Capture the ring write cursor BEFORE Present — Present submits the built frame then
  // resets device+0x30 back to the frame-body start, so reading it after gives an empty window.
  uint32_t vk_entry = (rt_vk_on() && g_d3d_device)? rt_be32(base,g_d3d_device+0x30) : 0;
  __imp__sub_820A5408(ctx,base);
  nvk_present();   // nvk frame boundary (Present-exit)
  // ★ HARD PIVOT (RT_NVK=2): nvk owns the frame — the old renderer is fully bypassed. The kick
  // window is closed (not consumed: nvk gets its draws from the wrapper calls, not the arena) so
  // the capture ring can't grow unboundedly; hookrender accumulators are drained for the same
  // reason. The RT_KICKSEG=0 0xB000DEAD sentinel is NOT armed (guest-memory hygiene: that
  // belongs to the raw-span capture path only). RT_NVK<=1 behavior is untouched.
  if(nvk_mode()>=2){
    { std::lock_guard<std::mutex> l(g_ks_mtx); g_ks_wstart=g_ks_off; }
    g_ks_last30=0; g_ks_kicks=0;
    nvk_on_present_frame(base);
    g_hkdN=0; g_hkvN=0;
    if(log) std::fprintf(stderr,"[d3d9] Present frame=%ld done (nvk) r3=0x%08X%c",k,(unsigned)ctx.r3.u32,10);
    return;
  }
  rt_render_maybe(base);
  // Live Vulkan renderer decode window -- RVK_RINGFULL lever (LEG-27/40 truncation fix):
  //   0 = legacy: [rb+0x8000, cursor-at-present-entry). Only ever sees the LAST pass built
  //       in the command-buffer body (the shell overlay) -- gameplay scene passes are kicked
  //       and their bytes REBUILT-OVER before Present (probe 2026-07-10), hence the old
  //       989-dword windows / black playfield.
  //   1 = widest in-frame cursor sample (Present entry, VdSwap pre/pump/exit, post-Present).
  //       Better only if no mid-frame rebuild happened; kept for A/B.
  //   2 = DEFAULT: kick-capture. rt_kick_capture() copied every kicked segment into the
  //       guest scratch arena as it was submitted; decode the arena instead of the body.
  // RT_HYBRID (2026-07-12) routing decision: reuse the same rt_game_field_active(0x885C1A20)
  // predicate that already scopes RT_RINGDUMP's sampling and rt_kick_capture's kick-capture arena
  // to the gameplay window (see the comment above rt_game_field_active, ~line 202) -- it is set to
  // 1 by the id46 gameplay-field factory and 0 for the shell/title/menu/dialog front-end, i.e.
  // exactly the "gameplay field active" split this lever needs. hybridToLegacy only matters (and
  // is only ever true) when hookrender itself is eligible this present.
  // RT_COMPOSE (2026-07-13, gameplay-composition pivot — supersedes RT_HYBRID's either/or):
  // user-confirmed X360 model, PROVEN by RT_COMPOSEPROBE + decomp (sub_8218xxxx layer family):
  // the playfield renders OFFSCREEN (EDRAM pass -> tile-resolve) and the SHELL then composites
  // the visible frame itself — wallpaper, frame chrome, HUD, and a RECTLIST window quad textured
  // by the resolve destination (0xEEAD000 640x512 == "[rvk][resolve] target dst=" match; plus the
  // 320x240 wallpaper-transform ring). So on gameplay presents run the LEGACY decoder FIRST (it
  // fills g_resolveTex from the ring/kick-capture; its own g.image composite gets cleared over)
  // and then the HOOKRENDER branch with the accumulated shell draws — whose resolve-base textures
  // now sample the rendered resolves via getTexture's g_resolveTex lookup (render/vk_render.cpp).
  // Fixes the hybrid-era classes in one move: wallpaper vanishing in gameplay, surround
  // white-wash, mirrored HUD text (all were legacy-full-frame artifacts).
  bool compose = getenv("RT_COMPOSE") && rt_hookrender() && rvk_present_hooked && rt_vk_on()
                 && rvk_present && rt_rom_render(base);
  bool hybridToLegacy = !compose && rt_hookrender() && rvk_present_hooked && rt_hybrid_on() && rt_vk_on() && rvk_present
                         && rt_rom_render(base);
  // RT_ROMRENDER diag: log when the ROM-scene gate (not field_active) is what routes this present to
  // legacy — i.e. the attract engaging the PM4 spine. One line per ~120 presents so it's cheap.
  if(rt_romrender_on() && (compose||hybridToLegacy) && !rt_game_field_active(base)){
    static long rr=0; if((rr++ % 120)==0)
      std::fprintf(stderr,"[romrender] present#%ld routed to LEGACY via g_rt_romactive (field_active=0) compose=%d hybrid=%d\n", rr, (int)compose, (int)hybridToLegacy);
  }
  // The D3D9 draw hooks (sub_8209D800 etc., below) accumulate into g_hkd/g_hkv on EVERY draw call
  // regardless of which Present branch runs, and are only reset by the rvk_present_hooked() call
  // at the end of the hookrender branch. If this present is diverted to legacy instead, that branch
  // never runs -- so without an explicit reset here the draws accumulated THIS present would carry
  // over unreset into the next hookrender-routed present, corrupting it with stale/merged geometry
  // (regression risk flagged in the RT_HYBRID task brief). Drop them; they were never going to be
  // presented via the hooked path this frame anyway.
  // RT_COMPOSEPROBE (2026-07-13, gameplay-composition pivot): the draws discarded here are the
  // SHELL's own gameplay-frame composite (user-confirmed model: wallpaper stays, playfield renders
  // offscreen via EDRAM resolve, and the shell draws it back as a textured WINDOW quad + frame
  // chrome + HUD). Before discarding, log each distinct texture base once — if one matches a
  // legacy-branch "[rvk][resolve] target dst=" address, the playfield-window link is PROVEN and
  // the composed-frame architecture (legacy fills resolves, hookrender composes) replaces hybrid.
  if(hybridToLegacy && getenv("RT_COMPOSEPROBE")){
    static std::set<uint32_t> seenTb; static int probes=0;
    if(probes<40){ probes++;
      for(int i=0;i<g_hkdN;i++){
        uint32_t tb = g_hkd[i].tf[1] ? (((g_hkd[i].tf[1]>>12)&0xFFFFF)<<12) : 0u;
        if(seenTb.insert(tb).second){
          uint32_t tw=(g_hkd[i].tf[2]&0x1FFF)+1, th=((g_hkd[i].tf[2]>>13)&0x1FFF)+1;
          float vx=0,vy=0;
          if((uint64_t)g_hkd[i].voff+2<=g_hkvN){ union{uint32_t u;float f;}c1,c2; c1.u=g_hkv[g_hkd[i].voff]; c2.u=g_hkv[g_hkd[i].voff+1]; vx=c1.f; vy=c2.f; }
          std::fprintf(stderr,"[composeprobe] gameplay hooked draw tex=0x%07X %ux%u cnt=%u prim=%u v0=(%.1f,%.1f)\n",
            tb,tw,th,g_hkd[i].count,g_hkd[i].prim,(double)vx,(double)vy);
        }
      }
    }
  }
  if(hybridToLegacy){ g_hkdN=0; g_hkvN=0; }
  // The legacy PM4-decode present, extracted so RT_COMPOSE can run it BEFORE the hookrender
  // composite in the same present (resolves must be filled before the window quad samples them).
  // Body unchanged from the old `else if(rt_vk_on() && rvk_present)` branch below.
  auto runLegacyPresent = [&](){
    uint32_t rb=g_rb_base.load();
    uint32_t start=rb?rb+0x8000u:0u;
    uint32_t vk_post = g_d3d_device? rt_be32(base,g_d3d_device+0x30) : 0;
    uint32_t vd_pre=g_vk_vd_pre.exchange(0), vd_pump=g_vk_vd_pump.exchange(0), vd_post=g_vk_vd_post.exchange(0);
    int ringFull = rvk_ringfull();
    bool romr = rt_vk_on() && rt_rom_render(base);
    // ★ RVK_PREROMWIN ROM handoff: rewind the kick ring ONCE, here, before the post-ROM path
    // consumes anything (see rt_pw_rom_reset for the reset set and why this is the safe site).
    if(rvk_preromwin() && !rvk_ringfull_all() && romr && g_pw_romreset.exchange(1)==0)
      rt_pw_rom_reset();
    // SCOPE kick-capture to gameplay (see rt_kick_capture): on shell/front-end frames the
    // arena decode corrupts the menu composite, so fall back to the legacy entry-only window.
    // ...that 2026-07-11 bisect was against the RAW-SPAN capture; RT_KICKSEG/RT_VTXSNAP retired
    // it, and RVK_PREROMWIN (default on) now keeps the kick window pre-ROM. RVK_PREROMWIN=0
    // restores this downgrade exactly.
    if(ringFull>=2 && !rvk_ringfull_all() && !romr && !rvk_preromwin()){
      ringFull=0;                                    // legacy: [rb+0x8000, cursor-at-entry)
      { std::lock_guard<std::mutex> l(g_ks_mtx); g_ks_wstart=g_ks_off; }  // discard stale partial window (ring: skip, don't rewind)
      g_ks_last30=0; g_ks_kicks=0;
    }
    uint32_t vk_end = vk_entry;
    if(ringFull>=1){
      uint32_t cands[4]={vd_pre,vd_pump,vd_post,vk_post};
      for(int ci=0;ci<4;ci++){ uint32_t v=cands[ci];
        if(start && v>start && v-start<0x18000u){ if(v>vk_end) vk_end=v; }
        else if(v && rvk_ringprobe()){ static std::atomic<long> rj{0}; long r=rj++;
          if(r<20||(r%997)==0) std::fprintf(stderr,"[ringprobe] REJECT cand%d=0x%08X start=0x%08X\n",ci,v,start); } }
    }
    uint32_t capBytes; long capKicks=g_ks_kicks;
    { std::lock_guard<std::mutex> l(g_ks_mtx); capBytes=g_ks_off-g_ks_wstart; }
    if(ringFull>=2){
      // kick-capture mode (default): decode the window (all segments kicked since the last
      // present, in submission order). Idle presents (no kicks) fall back to the sampled
      // window -- same stale-overlay re-decode the old code did every frame.
      // Ring semantics: CLOSE the window (advance wstart past it) instead of rewinding the
      // arena — the async worker may still be walking an older window's bytes.
      { std::lock_guard<std::mutex> l(g_ks_mtx);
        if(g_ks_arena && g_ks_off-g_ks_wstart>=8){ start=g_ks_arena+g_ks_wstart; vk_end=g_ks_arena+g_ks_off; }
        // ★ R6 counter (compose-1:1 Leg 1b, 2026-07-28, never-silent): idle present falls back
        // to re-decoding the sampled window = stale-overlay recompose candidate. Counting only.
        else { static std::atomic<long> r6n{0}; long v6=++r6n;
          if((v6%64)==1) std::fprintf(stderr,"[r6idle] x%ld idle-present stale-window fallback (cap=%u)\n",v6,(unsigned)(g_ks_off-g_ks_wstart)); }
        g_ks_wstart=g_ks_off; }
      g_ks_last30=0; g_ks_kicks=0;
      uint32_t rb2=g_rb_base.load();
      // Arm the raw-span reset sentinel. GUEST-MEMORY HYGIENE (2026-07-26, RVK_PREROMWIN): this
      // writes 0xB000DEAD into the guest's LIVE d3d9 command arena at rb+0x803C, and it is only
      // ever CONSUMED by the RT_KICKSEG=0 raw-span capture path. Post-ROM (and under the old
      // RVK_RINGFULL_ALL lever) it is armed exactly as before; pre-ROM under RVK_PREROMWIN the
      // shell owns that arena and is the only thing rendering, so with RT_KICKSEG on (default)
      // we leave its bytes alone. RT_KICKSEG=0 still arms everywhere — that path needs it.
      if(rb2 && (romr || rvk_ringfull_all() || !rt_kickseg_on()))
        *(uint32_t*)(base+rb2+0x803Cu)=__builtin_bswap32(g_ks_magic);
    }
    if(rvk_ringprobe()){
      static std::atomic<long> rp{0}; long q=rp++;
      if(q<40 || (q%8)==0)
        std::fprintf(stderr,"[ringprobe] f%ld entry=0x%08X vdpre=0x%08X vdpump=0x%08X vdpost=0x%08X post=0x%08X -> end=0x%08X | cap=%uB kicks=%ld | moves=%u back=%u maxcur=0x%08X\n",
          k, vk_entry, vd_pre, vd_pump, vd_post, vk_post, vk_end, capBytes, capKicks,
          g_rp_moves.exchange(0), g_rp_back.exchange(0), g_rp_maxcur.exchange(0));
    }
    rvk_present(base, start, vk_end);
  };
  // RT_COMPOSE: fill the resolves from this present's ring content BEFORE compositing.
  if(compose) runLegacyPresent();
  if(rt_hookrender() && rvk_present_hooked && !hybridToLegacy){
    // decode-free path: render the frame's full accumulated D3D-hooked draw list, bypassing PM4.
    // Architecture (RT_HYBRID, 2026-07-12): this is the SHELL-SCENES renderer -- correct for
    // title/menu/dialog frames, blind to gameplay ring content. Gameplay-field-active presents are
    // diverted (see hybridToLegacy above) to the PM4-decode branch below instead, which walks the
    // ring/kick-capture window and understands EDRAM tile-resolves the D3D9-hook capture never sees.
    g_hk_present++;
    hk_flush(base);
    long vdswaps = g_vdswap_since_present.exchange(0);
    long qstcalls = g_qst_since_present.exchange(0);
    // RT_RINGCOUNT (2026-07-12): run the count-only PM4-ring scan ALONGSIDE the hookrender
    // decode-free path (does not affect rendering). Prefer this present's kick-capture arena
    // (the LEG-27/40 fix — sees every kicked segment, gameplay or shell) when it has content;
    // else fall back to the legacy [rb+0x8000, cursor-at-entry) sample. hookdraws is read here
    // (before hk_flush's g_hkdN is zeroed below) so it matches the hktrace accepted count.
    if(rt_ringcount_on()){
      uint32_t rb=g_rb_base.load();
      uint32_t rc_start = rb? rb+0x8000u : 0u, rc_end = vk_entry;
      { std::lock_guard<std::mutex> l(g_ks_mtx);
        if(g_ks_arena && g_ks_off-g_ks_wstart>=8){ rc_start=g_ks_arena+g_ks_wstart; rc_end=g_ks_arena+g_ks_off; } }
      long pm4draws=0, resolves=0;
      if(rc_start && rc_end>rc_start) rt_ringcount_scan(base,rc_start,rc_end,pm4draws,resolves);
      std::fprintf(stderr,"[ringcount] present=%ld pm4draws=%ld resolves=%ld hookdraws=%d\n",
        g_hk_present,pm4draws,resolves,g_hkdN);
      // Close the window for the next present (the legacy Present branch does this same
      // close+rearm when it consumes the arena; that branch never runs while hookrender is active,
      // so without this the window would silently accumulate/drop for the whole run instead of
      // reflecting a per-present window).
      { std::lock_guard<std::mutex> l(g_ks_mtx); g_ks_wstart=g_ks_off; }
      g_ks_last30=0; g_ks_kicks=0;
      uint32_t rb2=g_rb_base.load();
      if(rb2) *(uint32_t*)(base+rb2+0x803Cu)=__builtin_bswap32(g_ks_magic);
    }
    static bool hktrace = getenv("RT_HKTRACE")!=nullptr;
    if(hktrace){ long c=g_hk_calls.exchange(0); long ic=g_hk_idx_calls.exchange(0);
      std::fprintf(stderr,"[hktrace] present=%ld drawCalls=%ld idxCalls=%ld accepted=%d vpoolDW=%u dev=0x%08X vdswaps=%ld qst=%ld\n",
        g_hk_present,c,ic,g_hkdN,g_hkvN,(unsigned)g_d3d_device,vdswaps,qstcalls); }
    // RT_HKDUP diagnostic (2026-07-12, menu text-duplication investigation): dump the FULL
    // accumulated draw list (un-deduped) for ONE representative menu-band present, to discriminate
    // hypothesis A (this present legitimately contains 2-3 real passes of the same glyph at
    // different NDC positions -- e.g. an offscreen composite or shadow pass the hook flattens)
    // from hypothesis B (this present's list accumulated draws from >1 real guest frame because
    // some guest frames' VdSwap/pump cycle didn't produce a corresponding hooked Present). Fires
    // once, on the first present whose accepted draw count falls in the ambiguous menu band
    // (95-150 quads per the task brief -- single-copy text is plausibly ~40-50 quads).
    // NOTE: hd.mtx translation (mtx[3]/mtx[7]) is a SHARED per-draw M2LibMatrix, not the glyph's
    // screen position -- that lives in the per-VERTEX (x,y), transformed by the matrix like
    // renderHookedFrame() does. So this dump replicates that exact transform on vertex 0 of each
    // quad (same math as render/vk_render.cpp renderHookedFrame) to get the real NDC placement.
    static bool hkdup = getenv("RT_HKDUP")!=nullptr;
    if(hkdup){
      // Dump every menu-band present (up to a cap) rather than just the first -- the menu
      // slide-in animation grows the quad count present-over-present, and the specific frame
      // saved to rvk_menu.png is whichever hits the HIGHEST count in [95,150] (see the
      // MENU-BAND logic in renderHookedFrame), which may not be the first one in-band.
      static int nfired=0;
      if(nfired<12 && g_hkdN>=130 && g_hkdN<=150){
        ++nfired;
        std::fprintf(stderr,"[hkdup] === present=%ld draws=%d vdswapsSincePrev=%ld qstSincePrev=%ld (full dump) ===\n",
          g_hk_present,g_hkdN,vdswaps,qstcalls);
        for(int i=0;i<g_hkdN;i++){
          const RvkHookDraw& d=g_hkd[i];
          uint32_t tb = d.tf[1] ? (((d.tf[1]>>12)&0xFFFFF)<<12) : 0u;
          uint32_t tfmt = d.tf[1] & 0x3Fu;
          float ndx=0,ndy=0,vx=0,vy=0,vu=0,vv=0;
          if((uint64_t)d.voff + d.stride <= g_hkvN){
            const uint32_t* vp = g_hkv + d.voff;
            union{uint32_t u;float f;} cx,cy,cu,cvv; cx.u=vp[0]; cy.u=vp[1]; cu.u=vp[4]; cvv.u=vp[5];
            vx=cx.f; vy=cy.f; vu=cu.f; vv=cvv.f;
            const float* m=d.mtx;
            float clx=m[0]*vx+m[1]*vy+m[3], cly=m[4]*vx+m[5]*vy+m[7], clw=m[12]*vx+m[13]*vy+m[15];
            if(clw==0.f) clw=1.f;
            ndx=clx/clw; ndy=cly/clw;
          }
          std::fprintf(stderr,"[hkdup] i=%d prim=%u tex=0x%07X tfmt=%u cnt=%u stride=%u v0=(%.2f,%.2f) uv0=(%.3f,%.3f) ndc0=(%.3f,%.3f) blend=0x%08X\n",
            i,d.prim,tb,tfmt,d.count,d.stride,(double)vx,(double)vy,(double)vu,(double)vv,(double)ndx,(double)ndy,d.blend);
          // RT_WALLPAPER quad investigation (2026-07-13): raw hex dwords for the first two vertex
          // RECORDS (not the hardcoded [0,1,4,5] field-offset reads above, which assume a 6-dword
          // {x,y,z,color,u,v} record and misread anything with a smaller stride -- e.g. a 4-dword
          // {x,y,u,v} record, where dwords 4/5 actually belong to VERTEX 1, not vertex 0's u/v).
          // Dumped for small-count draws (RECTLIST candidates: count==3) so the true field layout
          // and int-vs-float encoding (cf. the legacy i48int heuristic, vk_render.cpp ~line 1710)
          // can be read directly off the wire.
          if(d.count==3 && (uint64_t)d.voff + 2u*d.stride <= g_hkvN){
            const uint32_t* vp0 = g_hkv + d.voff;
            const uint32_t* vp1 = g_hkv + d.voff + d.stride;
            std::fprintf(stderr,"[hkdup]   raw v0=[%08X %08X %08X %08X] v1=[%08X %08X %08X %08X]\n",
              vp0[0],vp0[1],vp0[2],vp0[3],vp1[0],vp1[1],vp1[2],vp1[3]);
            std::fprintf(stderr,"[hkdup]   mtx r0=[%.4f %.4f %.4f %.4f] r1=[%.4f %.4f %.4f %.4f] r3=[%.4f %.4f %.4f %.4f]\n",
              (double)d.mtx[0],(double)d.mtx[1],(double)d.mtx[2],(double)d.mtx[3],
              (double)d.mtx[4],(double)d.mtx[5],(double)d.mtx[6],(double)d.mtx[7],
              (double)d.mtx[12],(double)d.mtx[13],(double)d.mtx[14],(double)d.mtx[15]);
          }
        }
        std::fprintf(stderr,"[hkdup] === end dump ===\n");
      }
    }
    rvk_present_hooked(base, g_hkv, g_hkvN, g_hkd, g_hkdN); g_hkdN=0; g_hkvN=0;
    // RT_HYBRID state-continuity keep-warm (2026-07-12): the legacy decoder's persistent register
    // shadow (g_regFile / ALU consts / VTE -- render/vk_render.cpp) is normally kept fresh by
    // renderFrameReal's packet walk running on EVERY present (see rvk_present's own comment);
    // under hybrid routing that walk is skipped whenever THIS branch runs instead. Without this,
    // the first gameplay-routed present after a long shell/menu stretch would decode against a
    // stale/zero shadow for anything the guest sets once and doesn't re-emit. rvk_shadow_update is
    // GPU-submission-free (render=false path) so it cannot disturb the frame rvk_present_hooked
    // just produced. kick-capture is scoped to gameplay-active frames (rt_kick_capture), so on
    // this (non-gameplay) branch the arena is empty/stale -- use the same legacy [rb+0x8000,
    // cursor-at-entry) window the non-hybrid legacy branch falls back to for front-end frames.
    if(rt_hybrid_on() && rt_vk_on() && rvk_shadow_update){
      uint32_t rb=g_rb_base.load();
      uint32_t sh_start = rb? rb+0x8000u : 0u;
      if(sh_start && vk_entry>sh_start) rvk_shadow_update(base, sh_start, vk_entry);
    }
  } else if(rt_vk_on() && rvk_present && !compose){
    runLegacyPresent();   // body extracted above (RT_COMPOSE runs it pre-composite instead)
  }
  if(log) std::fprintf(stderr,"[d3d9] Present frame=%ld done r3=0x%08X%c",k,(unsigned)ctx.r3.u32,10);
  // Authoring-path research: once per ~64 frames, dump the ring cursor/end and the
  // static command-list blob (device+13988, expected to hold guest 0x006E0000, the
  // 8KB buffer sub_8209B180 authored at boot) to catch its per-frame INDIRECT_BUFFER
  // resubmission from the ring.
  if(rt_d3d9_on() && (k%64)==0 && g_d3d_device){
    uint32_t dev=g_d3d_device;
    uint32_t ring_cur=rt_be32(base,dev+0x30);
    uint32_t ring_end=rt_be32(base,dev+0x38);
    uint32_t blob=rt_be32(base,dev+13988);
    std::fprintf(stderr,"[d3d9] Present-blob frame=%ld dev=0x%08X ring_cur(+0x30)=0x%08X ring_end(+0x38)=0x%08X blob(+13988)=0x%08X%c",
      k,dev,ring_cur,ring_end,blob,10);
    if(blob && blob<0x02000000u){
      std::fprintf(stderr,"[d3d9] Present-blob frame=%ld dwords@0x%08X:",k,blob);
      for(int i=0;i<8;i++) std::fprintf(stderr," [%d]=0x%08X",i,rt_be32(base,blob+(uint32_t)i*4));
      std::fprintf(stderr,"%c",10);
    }
  }
}

// ===== RT_DRAWTRACE: source-level D3D ground-truth trace (decomp w5jmpxave) =====
// Read EXACT draw args from the shell's D3D funcs instead of re-decoding the guest PM4 (lossy ->
// streaks). sub_8209D800 (extended below): r4=prim, r5=vtxCount, r6=vtxStrideBytes; it returns
// r3=a scratch VB the CALLER fills right after, so the real vertex bytes are read (DEFERRED) at
// the NEXT draw-hook / at Present. sub_8209DCE0 = indexed core (r4=prim,r6=stride,r7=idxCount,
// r8 bit2=32-bit,r9=vtxCount). sub_820A2280 = Resolve (r5=pSrcRect D3DRECT* the blitResolve
// currently ignores, r6=pDestTex). Gated RT_DRAWTRACE=<present#>; arms for ONE frame at/after it.
// Device is g_d3d_device (NOT r3 — the core re-fetches from TLS). Diagnostic only, default off.
PPC_FUNC_IMPL(__imp__sub_8209DCE0); // D3D9 DrawIndexedVertices core
PPC_FUNC(sub_8209DCE0){
  NVK_TAP("DrawIndexedVerticesUP");
  if(rt_hookrender()) g_hk_idx_calls++;  // RT_HKDUP2 investigation: indexed draws bypass the hook capture
  if(rt_lrband()){ lb_flush(base);
    uint32_t lr=(uint32_t)ctx.lr, vc=ctx.r9.u32, strideB=ctx.r6.u32, sp=ctx.r1.u32;
    hk_read_matrix(base); hk_read_tex(base);
    __imp__sub_8209DCE0(ctx,base);
    lb_stash(base,ctx,lr,sp,vc,strideB,1); return; }
  if(rt_drawtrace_on() && g_dt_active){ dt_flush(base);
    uint32_t prim=ctx.r4.u32&0x3f,strideB=ctx.r6.u32,ic=ctx.r7.u32,iw=((ctx.r8.u32>>2)&1)?32u:16u,vc=ctx.r9.u32;
    __imp__sub_8209DCE0(ctx,base);
    g_dt_scratch=ctx.r3.u32; g_dt_prim=prim; g_dt_count=vc; g_dt_stride=strideB; g_dt_indexed=true; g_dt_ic=ic; g_dt_iw=iw; return; }
  __imp__sub_8209DCE0(ctx,base);
}
PPC_FUNC_IMPL(__imp__sub_820A2280); // D3D9 Resolve / RB_COPY
PPC_FUNC(sub_820A2280){
  NVK_TAP("Resolve");
  // shell Resolve ABI (s1_abi §3): r4=flags, r5=pSrcRect, r6=pDestTex, r7=pDestPoint,
  // r10=pClearColor (CODE_REVIEW_0804 B9: was hardcoded 0 — clear-after resolves cleared BLACK
  // regardless of the guest's colour; read the D3DVECTOR4 like the game hook now does).
  if(nvk_mode()>=2) nvk_on_resolve(base, ctx.r3.u32, ctx.r4.u32, ctx.r6.u32, ctx.r5.u32,
                                   (ctx.r4.u32 & 0x300u) ? nvk_pack_cc(base, ctx.r10.u32) : 0, ctx.r7.u32);
  if(rt_drawtrace_on() && g_dt_active){ uint32_t flags=ctx.r4.u32,pr=ctx.r5.u32,pd=ctx.r6.u32;
    if(pr && pr<0x40000000u) std::fprintf(stderr,"[drawtrace] RESOLVE flags=0x%X srcRect=(%d,%d,%d,%d) destTex=0x%08X\n",flags,(int)rt_be32(base,pr),(int)rt_be32(base,pr+4),(int)rt_be32(base,pr+8),(int)rt_be32(base,pr+0xC),pd);
    else std::fprintf(stderr,"[drawtrace] RESOLVE flags=0x%X srcRect=WHOLE destTex=0x%08X\n",flags,pd); }
  __imp__sub_820A2280(ctx,base);
}
// RT_LRBAND emitter-LR latch: the public draw wrapper pair every shell sprite/text emit calls.
// Pure pass-through when the probe is off; when on, remembers the caller LR for lb_stash's lr2.
PPC_FUNC_IMPL(__imp__sub_8209DC94);
PPC_FUNC(sub_8209DC94){
  NVK_TAP("DrawVerticesUP94dead");   // s1_abi §4: DC94 is a null stub — never executes; tap kept as tripwire
  if(rt_lrband()) g_lb_wraplr=(uint32_t)ctx.lr;
  __imp__sub_8209DC94(ctx,base);
}
// ★ sub_8209DC98 is the REAL public DrawVerticesUP (s1_abi §4: r3=dev, r4=prim, r5=vtxCount,
// r6=pVertexData, r7=strideBytes; it memcpys into the D800 scratch then publishes the cursor).
// The vertex bytes are complete at ENTRY (r6 = caller's buffer) — the nvk recorder copies them
// here, plus register-true device-object state (bound texture/shaders/blend) read at call time.
PPC_FUNC_IMPL(__imp__sub_8209DC98);
PPC_FUNC(sub_8209DC98){
  NVK_TAP("DrawVerticesUP");
  // (stage-2 unification: capture moved to the D800 core exit — DC98 calls it internally)
  if(rt_lrband()) g_lb_wraplr=(uint32_t)ctx.lr;
  __imp__sub_8209DC98(ctx,base);
}
// RT_LRBAND node latch: the shell's generic sprite/quad draw method (owns the 0x8216DD58 bl whose
// return 0x8216DD5C is the lr2 EVERY shell quad reports). Pass-through when the probe is off.
PPC_FUNC_IMPL(__imp__sub_8216DAA0);
PPC_FUNC(sub_8216DAA0){
  if(rt_lrband()){ g_lb_node=ctx.r3.u32; g_lb_qd=ctx.r4.u32; g_lb_nlr=(uint32_t)ctx.lr; g_lb_sp=ctx.r1.u32;
    // ctx.r1 here IS the caller's (sub_82168E58 / sub_82164E68) frame SP, so the back-chain walk
    // starts one level above lr3 and names the widget that asked for this quad.
    lb_walk(base,ctx.r1.u32,g_lb_chain,5);
    g_lb_vd=g_lb_sd;
    for(int i=0;i<5;i++){ int d=g_lb_sd-1-i;
      if(d>=0&&d<64){ g_lb_vt[i]=g_lb_stk[d].t; g_lb_vr[i]=g_lb_stk[d].r3; } else { g_lb_vt[i]=0; g_lb_vr[i]=0; } } }
  __imp__sub_8216DAA0(ctx,base);
}
// LINK-ORDER LANDMINE (leg-35): do NOT hook sub_82168E58 here -- merged_xex.cpp already defines a
// PPC_FUNC(sub_82168E58) ([flush] loader queue flush) and the MERGED object wins the link, so an
// rt.cpp duplicate silently never runs. sub_82164E68 (the text/glyph emit, lr3=0x82164FE0) has no
// competing definition, so its hook below is live. r3 = the emitting object; ctx.lr = its caller.
PPC_FUNC_IMPL(__imp__sub_82164E68);
PPC_FUNC(sub_82164E68){
  if(rt_lrband()){ g_lb_obj=ctx.r3.u32; g_lb_objlr=(uint32_t)ctx.lr; }
  __imp__sub_82164E68(ctx,base);
}
// ---------------------------------------------------------------------------------------------
// RT_TXTNODE (leg-35 stage-2). sub_8216E510 = decomp FUN_8216e510, slot +0x08 ("draw") of the TEXT
// NODE vtable 0x820516D4 (ctor sub_8216E790). It is the ONLY caller of the string-draw helper
// FUN_8216f0a0, whose per-glyph virtual call at 0x8216F254 is the universal olr seen by [lrband].
// Layout proven by the ctor + FUN_8216f0a0's accesses:
//   +0x00 vtable(0x820516D4)  +0x50 font object (the [lrband] "obj", vtable 0x82051698)
//   +0x54 std::wstring : buf/ptr @+0x58, size @+0x68, cap @+0x6C (SSO when cap<=7, UTF-16BE)
//   +0x70/+0x74 spacing pair (ctor param_3)   +0x78/+0x7C pen origin (ctor: 0,0)
// Base-node ctor FUN_8216a4d8 (vtable 0x82051794) sets the candidate visibility bytes:
//   +0x0C=1, +0x1C=0 +0x1D=1 +0x1E=0 +0x1F=0, +0x38=0 +0x39=1 +0x3A=0 +0x3B=0
// Logs the decoded text so the "加速[Y]:x1" strip node can be named, one 0x90-byte dump per
// distinct node for offline diffing against the legit menu-label node. Default OFF.
static bool rt_txtnode(){ static bool v=getenv("RT_TXTNODE")!=nullptr; return v; }
static uint16_t tn_be16(uint8_t* b, uint32_t a){ return (uint16_t)((b[a]<<8)|b[a+1]); }
// sub_82173978 = decomp FUN_82173978, the CHILD-LIST DRAW WALK and the sole dispatcher of the
// node draw slot (its bctrl at 0x821739BC -> the lr=0x821739C0 every [txtnode] row reports):
//   for(c = *(list+0x10); c; c = *(c+0x04))  if(*(uint8_t*)(c+0x0C) == 0)  c->vt[0x08](c, arg);
// => +0x0C is the node's HIDE byte (1 = skip). r3 here is the list SUB-OBJECT embedded in the
// owner node at owner+0x10 or owner+0x2C, so the stack below is the live ancestor chain.
static thread_local uint32_t g_tn_lst[24]; static thread_local int g_tn_ld=0;
static thread_local uint32_t g_tn_lr[24];
PPC_FUNC_IMPL(__imp__sub_8216E510);
PPC_FUNC(sub_8216E510){
  if(rt_txtnode() && (!rt_lrband_arm()||g_lb_armed)){
    uint32_t n=ctx.r3.u32;
    { // time series: replay_speed widget state, sampled off the live ancestor stack
      static long rs=0;
      if((rs++ % 900)==0){
        for(int i=g_tn_ld-1;i>=0;i--){
          uint32_t L=g_tn_lst[i]; if(L<0x2Cu) continue; uint32_t W=L-0x2C;
          if(rt_be32(base,W)!=0x8204FDB8u) continue;
          uint32_t col=rt_be32(base,W+0xD8);
          std::fprintf(stderr,"[rspeedT] #%ld w=0x%08X hide0C=%02X awake8C=%02X fade90=0x%08X t134=%u step138=%d rgba=0x%08X st48=0x%08X g20=0x%08X child F4=0x%08X\n",
            rs,W,base[W+0x0C],base[W+0x8C],rt_be32(base,W+0x90),rt_be32(base,W+0x134),
            (int)rt_be32(base,W+0x138),(col&&col<0x40000000u)?rt_be32(base,col+8):0u,
            rt_be32(base,W+0x48),rt_be32(base,W+0x20),rt_be32(base,W+0xF4));
        }
      }
    }
    if(n && n<0x40000000u && !(n&3)){
      uint32_t sz=rt_be32(base,n+0x68), cap=rt_be32(base,n+0x6C);
      if(sz<=4096u && cap<=0x10000u){
        uint32_t p=(cap>7u)?rt_be32(base,n+0x58):(n+0x58);
        char txt[192]; int tp=0;
        if(p && p<0x40000000u){
          for(uint32_t i=0;i<sz && i<40u && tp+10<(int)sizeof(txt);i++){
            uint16_t w=tn_be16(base,p+i*2);
            if(w>=0x20&&w<0x7f) txt[tp++]=(char)w;
            else tp+=std::snprintf(txt+tp,sizeof(txt)-(size_t)tp,"\\u%04X",w);
          }
        }
        txt[tp]=0;
        static std::set<uint64_t> seen; static std::set<uint32_t> dumped; static int budget=4000;
        uint64_t h=1469598103934665603ull; for(int i=0;i<tp;i++){ h^=(uint8_t)txt[i]; h*=1099511628211ull; }
        uint64_t key=((uint64_t)n<<32)^h;
        if(budget>0 && seen.insert(key).second){
          --budget;
          union { uint32_t u; float f; } px,py,sx,sy;
          px.u=rt_be32(base,n+0x78); py.u=rt_be32(base,n+0x7C);
          sx.u=rt_be32(base,n+0x70); sy.u=rt_be32(base,n+0x74);
          std::fprintf(stderr,
            "[txtnode] node=0x%08X vt=0x%08X lr=0x%08X font=0x%08X len=%u pen=(%.1f,%.1f) sp=(%.1f,%.1f)"
            " b0C=%02X b1C=%02X%02X%02X%02X b38=%02X%02X%02X%02X p08=%08X p18=%08X p2C=%08X p34=%08X txt='%s'\n",
            n,rt_be32(base,n),(uint32_t)ctx.lr,rt_be32(base,n+0x50),sz,
            (double)px.f,(double)py.f,(double)sx.f,(double)sy.f,
            base[n+0x0C],base[n+0x1C],base[n+0x1D],base[n+0x1E],base[n+0x1F],
            base[n+0x38],base[n+0x39],base[n+0x3A],base[n+0x3B],
            rt_be32(base,n+0x08),rt_be32(base,n+0x18),rt_be32(base,n+0x2C),rt_be32(base,n+0x34),txt);
          { // live ancestor chain: innermost list first (list, and the two candidate owner bases)
            std::fprintf(stderr,"[txtanc] node=0x%08X depth=%d",n,g_tn_ld);
            for(int i=g_tn_ld-1;i>=0 && i>=g_tn_ld-8;i--){
              uint32_t L=g_tn_lst[i];
              std::fprintf(stderr," | L=0x%08X clr=0x%08X o10vt=0x%08X o2Cvt=0x%08X o10hide=%02X o2Chide=%02X",
                L,g_tn_lr[i],
                (L>=0x10u)?rt_be32(base,L-0x10):0u,(L>=0x2Cu)?rt_be32(base,L-0x2C):0u,
                (L>=0x10u)?base[L-0x10+0x0C]:0xFFu,(L>=0x2Cu)?base[L-0x2C+0x0C]:0xFFu);
            }
            std::fprintf(stderr,"\n");
            // If any ancestor is the `replay_speed` widget (ctor sub_821C6238 writes vtable
            // 0x8204FDB8; name "replay_speed" @+0x58, REPLAY_NAVI_OPE_SHORT @+0xEC,
            // REPLAY_NAVI_SPEEDx1 @+0x108), dump the state its own show/hide method
            // sub_821C5998 owns: +0x8C awake bool, +0x90 fade-task ptr, +0x134 auto-hide
            // countdown (set to 0x78 on wake), +0x138 speed step, +0xD8 -> +8 RGBA.
            static long rsn=0;
            for(int i=g_tn_ld-1;i>=0;i--){
              uint32_t L=g_tn_lst[i]; if(L<0x2Cu) continue; uint32_t W=L-0x2C;
              if(rt_be32(base,W)!=0x8204FDB8u) continue;
              (void)rsn;
              uint32_t col=rt_be32(base,W+0xD8);
              std::fprintf(stderr,"[rspeed] w=0x%08X hide0C=%02X awake8C=%02X fade90=0x%08X"
                " t134=%u step138=%d n130=%d colobj=0x%08X rgba=0x%08X nodes=%08X/%08X/%08X\n",
                W,base[W+0x0C],base[W+0x8C],rt_be32(base,W+0x90),rt_be32(base,W+0x134),
                (int)rt_be32(base,W+0x138),(int)rt_be32(base,W+0x130),col,
                (col&&col<0x40000000u)?rt_be32(base,col+8):0u,
                rt_be32(base,W+0xE0),rt_be32(base,W+0xE4),rt_be32(base,W+0xE8));
            }
          }
          if(dumped.insert(n).second){
            for(uint32_t r=0;r<0x24u;r+=8){
              std::fprintf(stderr,"[txtobj] 0x%08X +%02X:",n,r*4);
              for(uint32_t c=0;c<8;c++) std::fprintf(stderr," %08X",rt_be32(base,n+(r+c)*4));
              std::fprintf(stderr,"\n");
            }
          }
        }
      }
    }
  }
  __imp__sub_8216E510(ctx,base);
}
// ---- RT_WMAB (2026-07-26, RECON TASK B) -- A/B INSTRUMENT, DEFAULT OFF, NEVER SHIPPED ---------
// Purpose: establish by snap A/B which child of the `replay_speed` widget paints the port-only
// bottom-right "REPLAY" plate. Grounded in the widget's own build method FUN_821c7060 @0x821C7060
// (vt+0x2C of the widget whose vtable is 0x8204FDB8, ctor FUN_821c6238 @0x821C6238), which creates
// FIVE children and appends every one of them to the widget's child list:
//   +0xE0 / +0xE4 / +0xE8 -> text nodes (FUN_8216e790)  = the legend + the two "×1再生" runs
//   +0x128 -> 0x90-byte node (FUN_8217a960, bound by FUN_8217b6a8 to the shell resource at
//             *(*(DAT_821F856C+0x1F0)+0x54))
//   +0x124 -> 0x22C-byte MOTION-CLIP node: FUN_8217aa80(mem, *(this+0x128), "replay" @0x8204EB94)
//             then FUN_8217c468(node+0x10, "replay" @0x8204EB9C, 0) = play clip labelled "replay"
// RT_WMAB=<hex child offset> (124/128/E0/E4/E8) forces that ONE child's hide byte (+0x0C) to 1 for
// the frame; RT_WMAB=1 only dumps the roster and hides nothing. The poke is applied at the top of
// the widget's own subtree walk, so it is re-established every frame and cannot race the descent.
// It WRITES guest memory and is therefore an A/B measurement lever only -- it is not, and must not
// become, a shipped gate (NOTE_field_gfx_defects.md doctrine: a fix may gate only on guest state
// the emitting code owns, and hardware holds these very bytes at 0).
static int rt_wmab(){ static int v=getenv("RT_WMAB")?(int)strtol(getenv("RT_WMAB"),nullptr,16):0; return v; }
// RT_PICNODE (RECON TASK B) -- read-only. sub_82168E58 is slot +0x08 ("draw") of the PICTURE-node
// vtable 0x82051478 (proven from the image: vt+8 == 0x82168E58; it is also the function that owns
// the universal sprite lr3 = 0x8216920C seen by [lrband]). Same trick as RT_TXTNODE, for sprites:
// print each distinct picture node with its live ancestor chain so the bottom-right "REPLAY" plate
// can be attributed to an owning widget class. Default OFF.
static bool rt_picnode(){ static bool v=getenv("RT_PICNODE")!=nullptr; return v; }
// LINK-ORDER LANDMINE honoured: merged_xex.cpp owns PPC_FUNC(sub_82168E58) ([flush]); a duplicate
// here would be silently shadowed. So the probe body lives here and merged_xex.cpp's existing hook
// calls it -- one definition, no duplicate PPC_FUNC.
extern "C" void rt_picnode_report(uint32_t n, uint8_t* base){
  if(rt_picnode()){
    if(n && n<0x40000000u && !(n&3)){
      static std::set<uint32_t> seen; static int budget=400;
      if(budget>0 && seen.insert(n).second){
        --budget;
        std::fprintf(stderr,"[picnode] node=0x%08X vt=0x%08X hide0C=%02X p08=%08X p10=%08X p14=%08X p18=%08X p50=%08X depth=%d",
          n,rt_be32(base,n),base[n+0x0C],rt_be32(base,n+0x08),rt_be32(base,n+0x10),
          rt_be32(base,n+0x14),rt_be32(base,n+0x18),rt_be32(base,n+0x50),g_tn_ld);
        for(int i=g_tn_ld-1;i>=0 && i>=g_tn_ld-8;i--){
          uint32_t L=g_tn_lst[i];
          std::fprintf(stderr," | L=0x%08X o2Cvt=0x%08X o10vt=0x%08X",
            L,(L>=0x2Cu)?rt_be32(base,L-0x2C):0u,(L>=0x10u)?rt_be32(base,L-0x10):0u);
        }
        std::fprintf(stderr,"\n");
      }
    }
  }
}
PPC_FUNC_IMPL(__imp__sub_82173978);
PPC_FUNC(sub_82173978){
  if(int wm=rt_wmab()){
    uint32_t L=ctx.r3.u32;
    if(L>=0x2Cu && L<0x40000000u && rt_be32(base,L-0x2Cu)==0x8204FDB8u){
      uint32_t W=L-0x2Cu;
      static const uint32_t kOff[5]={0xE0,0xE4,0xE8,0x124,0x128};
      { static std::set<uint64_t> once;
        if(once.insert(((uint64_t)W<<32)^rt_be32(base,W+0x124)^((uint64_t)rt_be32(base,W+0xE0)<<8)).second){
          std::fprintf(stderr,"[wmab] widget=0x%08X roster:",W);
          for(int i=0;i<5;i++){ uint32_t c=rt_be32(base,W+kOff[i]);
            std::fprintf(stderr," +%03X=0x%08X(vt=0x%08X,hide=%02X)",kOff[i],c,
              (c&&c<0x40000000u)?rt_be32(base,c):0u,(c&&c<0x40000000u)?base[c+0x0C]:0xFFu); }
          std::fprintf(stderr,"\n");
        } }
      if(wm>=0x10){ uint32_t c=rt_be32(base,W+(uint32_t)wm);
        if(c && c<0x40000000u){ base[c+0x0C]=1;
          static long pk=0; if((pk++ % 600)==0)
            std::fprintf(stderr,"[wmab] poke #%ld W=0x%08X +%X node=0x%08X vt=0x%08X hide->1\n",
              pk,W,(unsigned)wm,c,rt_be32(base,c)); } }
    }
  }
  if(!rt_txtnode() && !rt_picnode()){ __imp__sub_82173978(ctx,base); return; }
  if(g_tn_ld>=0 && g_tn_ld<24){ g_tn_lst[g_tn_ld]=ctx.r3.u32; g_tn_lr[g_tn_ld]=(uint32_t)ctx.lr; }
  ++g_tn_ld; __imp__sub_82173978(ctx,base); --g_tn_ld;
}
PPC_FUNC_IMPL(__imp__sub_8209D800); // D3D9 Draw
PPC_FUNC(sub_8209D800){
  NVK_TAP("DrawKernel");
  // ★ RT_NVK=2: capture at CORE exit (scratch VB in r3; vertex bytes read lazily at Present).
  // The old-renderer diagnostic branches below (lrband/hookrender/drawtrace) are moot here.
  if(nvk_mode()>=2){
    uint32_t dv=ctx.r3.u32, pr=ctx.r4.u32, ct=ctx.r5.u32, st=ctx.r6.u32;
    uint32_t dp=(rt_be32(base,dv)||rt_be32(base,dv+4)?1u:0u)|(rt_be32(base,dv+8)||rt_be32(base,dv+12)?2u:0u);
    __imp__sub_8209D800(ctx,base);
    nvk_on_draw_core(base, dv, pr, ct, st, ctx.r3.u32, dp, 0);
    return;
  }
  static std::atomic<long> n{0}; long k=n++;
  if(rt_lrband()){ lb_flush(base);
    uint32_t lr=(uint32_t)ctx.lr, count=ctx.r5.u32, strideB=ctx.r6.u32, sp=ctx.r1.u32;
    hk_read_matrix(base); hk_read_tex(base);
    __imp__sub_8209D800(ctx,base);
    lb_stash(base,ctx,lr,sp,count,strideB,0); return; }
  bool log = rt_d3d9_on() && rt_d3d9_throttle(k);
  if(log){
    std::fprintf(stderr,"[d3d9] Draw #%ld r3=0x%08X primType=%u r5=%u r6=%u count~=%u r7=0x%08X r8=0x%08X r9=0x%08X r10=0x%08X%c",
      k,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,(unsigned)ctx.r5.u32,(unsigned)ctx.r6.u32,
      (unsigned)(ctx.r5.u32*ctx.r6.u32),(unsigned)ctx.r7.u32,(unsigned)ctx.r8.u32,(unsigned)ctx.r9.u32,(unsigned)ctx.r10.u32,10);
  }
  if(rt_d3d9_on() && k<3 && ctx.r3.u32 && ctx.r3.u32<0x40000000u){
    // Scan the device object for dwords that look like plausible heap pointers.
    // Reveals VB/IB base slots and other resource bindings for offline research.
    uint32_t devp=ctx.r3.u32; int printed=0;
    std::fprintf(stderr,"[d3d9] Draw #%ld device-scan base=0x%08X size=0x5F00%c",k,devp,10);
    for(uint32_t off=0; off<0x5F00 && printed<120; off+=4){
      uint32_t v=rt_be32(base,devp+off);
      if(v>=0x00100000u && v<=0x01FFFFFFu){
        std::fprintf(stderr,"[d3d9]   off=0x%04X -> 0x%08X%c",off,v,10);
        ++printed;
      }
    }
    std::fprintf(stderr,"[d3d9] Draw #%ld device-scan done (%d hits, capped at 120)%c",k,printed,10);
  }
  if(rt_hookrender()){ g_hk_calls++; hk_flush(base);
    uint32_t count=ctx.r5.u32, strideB=ctx.r6.u32, primType=ctx.r4.u32&0x3Fu;
    hk_read_matrix(base); hk_read_tex(base); hk_read_blend(base); hk_read_vprt(base);
    // RT_VPPROBE (2026-07-13, playfield-window placement): the blit-class RECTLIST composite
    // draws (wallpaper / playfield window / 320x240 ring) carry SCALE-ONLY matrices — their
    // screen placement almost certainly rides the D3D VIEWPORT rect (StretchRect-style blit:
    // viewport = destination rectangle). To find the viewport's device-struct mirror, dump the
    // raw device struct at the WALLPAPER draw (known viewport 0,0,1280,720) and at the PLAYFIELD
    // WINDOW draw (expected ~centered 3:4 rect) and diff offline for viewport-shaped values.
    if(getenv("RT_VPPROBE") && g_d3d_device && primType==8 && count==3){
      uint32_t tb = g_hk_tf[1] ? (((g_hk_tf[1]>>12)&0xFFFFF)<<12) : 0u;
      uint32_t tw=(g_hk_tf[2]&0x1FFF)+1, th=((g_hk_tf[2]>>13)&0x1FFF)+1;
      static bool gotWall=false, gotWin=false;
      const char* which = nullptr;
      if(!gotWall && tw==1280 && th==720){ gotWall=true; which="/tmp/dev_wall.bin"; }
      else if(!gotWin && tw==640 && th==512){ gotWin=true; which="/tmp/dev_win.bin"; }
      if(which){
        if(FILE* f=fopen(which,"wb")){
          for(uint32_t off=0; off<0x6000; off+=4){ uint32_t v=rt_be32(base,g_d3d_device+off); fwrite(&v,4,1,f); }
          fclose(f);
          std::fprintf(stderr,"[vpprobe] dumped %s (draw tex=0x%07X %ux%u)\n",which,tb,tw,th);
        }
      }
    }
    // RT_HKCALLERS: log each DISTINCT (caller LR, bound texture) once — the caller of the card quad
    // IS the guest card-draw function (decompile it). Also logs the matrix translation (tx,ty) so a
    // draw placed off the right edge is visible as a mispositioned card. Menu-only: gate on present.
    static bool hkcallers=getenv("RT_HKCALLERS")!=nullptr;
    if(hkcallers && g_hk_present>=(getenv("RT_HKCALLERS_AFTER")?atol(getenv("RT_HKCALLERS_AFTER")):350)){
      static std::set<uint64_t> seen;
      uint32_t tb = g_hk_tf[1] ? (((g_hk_tf[1]>>12)&0xFFFFF)<<12) : 0u;
      uint64_t key = ((uint64_t)(uint32_t)ctx.lr<<20) ^ tb;
      if(seen.insert(key).second)
        std::fprintf(stderr,"[hkcaller] lr=0x%08X tex=0x%07X count=%u stride=%u tx=%.2f ty=%.2f\n",
          (unsigned)ctx.lr, tb, count, strideB, (double)g_hk_mtx[3], (double)g_hk_mtx[7]);
    }
    __imp__sub_8209D800(ctx,base);
    g_hk_scratch=ctx.r3.u32; g_hk_count=count; g_hk_stride=strideB; g_hk_prim=primType; return; }
  if(rt_drawtrace_on() && g_dt_active){ dt_flush(base);
    uint32_t prim=ctx.r4.u32&0x3f,count=ctx.r5.u32,strideB=ctx.r6.u32;
    __imp__sub_8209D800(ctx,base);
    g_dt_scratch=ctx.r3.u32; g_dt_prim=prim; g_dt_count=count; g_dt_stride=strideB; g_dt_indexed=false; return; }
  __imp__sub_8209D800(ctx,base);
}

// --- RT_CARDTRACE: the menu's right-side mode CARD build chain (the one element missing on Windows).
// sub_821B7F30 dispatches by selected mode (r4=0..3 => build card via menu_game_select_panel[_mode];
// 4/5=EXIT => no card). sub_821D2628 allocates+builds the panel (r5=mode) and returns the panel obj.
// Tells us if the card build is even invoked on Windows and whether it succeeds (ret!=0).
PPC_FUNC_IMPL(__imp__sub_821B7F30);
PPC_FUNC(sub_821B7F30){
  static bool on=getenv("RT_CARDTRACE")!=nullptr;
  if(on){ static std::atomic<int> n{0}; int k=n++;
    if(k<40||(k%97)==0) std::fprintf(stderr,"[card] sub_821B7F30 dispatch obj=0x%08X mode=%lld #%d\n",(unsigned)ctx.r3.u32,(long long)(int64_t)ctx.r4.u64,k); }
  __imp__sub_821B7F30(ctx,base);
}
PPC_FUNC_IMPL(__imp__sub_821D2628);
PPC_FUNC(sub_821D2628){
  static bool on=getenv("RT_CARDTRACE")!=nullptr;
  uint32_t mode=ctx.r5.u32;
  __imp__sub_821D2628(ctx,base);
  if(on){ static std::atomic<int> n{0}; int k=n++;
    if(k<40||(k%97)==0) std::fprintf(stderr,"[card] sub_821D2628 BUILD mode=%u -> panel=0x%08X #%d\n",mode,(unsigned)ctx.r3.u32,k); }
}
PPC_FUNC_IMPL(__imp__sub_8209ECB0); // D3D9 SetVertexShaderConstantF flush (dirty-mask driven)
PPC_FUNC(sub_8209ECB0){
  static std::atomic<long> n{0}; long k=n++;
  bool log = rt_d3d9_on() && rt_d3d9_throttle(k);
  if(log) std::fprintf(stderr,"[d3d9] VSConstF-flush #%ld r3=0x%08X dirtymask(r4)=0x%08X%c",k,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,10);
  __imp__sub_8209ECB0(ctx,base);
}

PPC_FUNC_IMPL(__imp__sub_8209E428); // D3D9 per-register constant write (reg base ~0x4800+6*i)
PPC_FUNC(sub_8209E428){
  static std::atomic<long> n{0}; long k=n++;
  bool log = rt_d3d9_on() && rt_d3d9_throttle(k);
  if(log){
    uint32_t regbase=ctx.r4.u32, srcptr=ctx.r5.u32;
    float f[4]={0,0,0,0};
    if(srcptr){
      for(int i=0;i<4;i++){ uint32_t bits=rt_be32(base,srcptr+(uint32_t)i*4); std::memcpy(&f[i],&bits,4); }
    }
    std::fprintf(stderr,"[d3d9] VSConstF-write #%ld r3=0x%08X regbase=0x%X src=0x%08X floats=[%g,%g,%g,%g]%c",
      k,(unsigned)ctx.r3.u32,(unsigned)regbase,(unsigned)srcptr,f[0],f[1],f[2],f[3],10);
  }
  __imp__sub_8209E428(ctx,base);
}

PPC_FUNC_IMPL(__imp__sub_8209E6D8); // D3D9 texture-stage flush
PPC_FUNC(sub_8209E6D8){
  static std::atomic<long> n{0}; long k=n++;
  bool log = rt_d3d9_on() && rt_d3d9_throttle(k);
  if(log) std::fprintf(stderr,"[d3d9] TexStage-flush #%ld r3=0x%08X r4=0x%08X r5=0x%08X%c",k,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,(unsigned)ctx.r5.u32,10);
  __imp__sub_8209E6D8(ctx,base);
}
// sub_820A8FC0: checked -- no existing hook and not required by the task's minimal
// set (CreateDevice/Present/Draw/VSConstF/TexStage cover the requested capture);
// skipped per task instruction ("if not, skip").


// ================= D3D9 command-list AUTHORING hooks (added this session) =================
// Research target: the shell menu draws are believed to be authored ONCE at boot into
// a static 8KB command blob (device+13988), not rebuilt per-frame. These hooks trace
// the authoring call graph: sub_8209B180 (list builder, ~24x DRAW_INDX_2) which calls
// sub_8209A928 (fetch-constant/texture packet builder, reg 0x8d00) in a loop, plus the
// state-binding calls (SetStreamSource/SetVertexDeclaration/SetIndices), Clear, and the
// CreateTexture/resource-ctor candidates. All hooks are pass-through: original body is
// always invoked, only logging is added, gated on RT_D3D9.

PPC_FUNC_IMPL(__imp__sub_8209B180); // command-list builder (authors the static menu draw list at boot)
PPC_FUNC(sub_8209B180){
  static std::atomic<long> n{0}; long k=n++;
  bool log = rt_d3d9_on(); // expect very few calls (boot-time only) -- log all of them
  if(log){
    std::fprintf(stderr,"[d3d9] CmdListBuild #%ld pre r3=0x%08X r4=0x%08X r5=0x%08X r6=0x%08X r7=0x%08X r8=0x%08X r9=0x%08X r10=0x%08X%c",
      k,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,(unsigned)ctx.r5.u32,(unsigned)ctx.r6.u32,
      (unsigned)ctx.r7.u32,(unsigned)ctx.r8.u32,(unsigned)ctx.r9.u32,(unsigned)ctx.r10.u32,10);
  }
  __imp__sub_8209B180(ctx,base);
  if(log){
    uint32_t blobptr = g_d3d_device? rt_be32(base,g_d3d_device+13988) : 0;
    std::fprintf(stderr,"[d3d9] CmdListBuild #%ld post r3(ret)=0x%08X device+13988(blob)=0x%08X%c",
      k,(unsigned)ctx.r3.u32,blobptr,10);
  }
}

PPC_FUNC_IMPL(__imp__sub_8209A928); // fetch-constant/texture packet builder (reg 0x8d00), called in a loop by CmdListBuild
PPC_FUNC(sub_8209A928){
  static std::atomic<long> n{0}; long k=n++;
  // ~112 calls expected: full detail for first 12, then every 16th, to bound log size.
  bool log = rt_d3d9_on() && (k<12 || (k%16)==0);
  if(log){
    std::fprintf(stderr,"[d3d9] FetchConstBuild #%ld pre r3=0x%08X r4=0x%08X r5=0x%08X r6=0x%08X r7=0x%08X r8=0x%08X%c",
      k,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,(unsigned)ctx.r5.u32,(unsigned)ctx.r6.u32,
      (unsigned)ctx.r7.u32,(unsigned)ctx.r8.u32,10);
  }
  __imp__sub_8209A928(ctx,base);
  if(log){
    std::fprintf(stderr,"[d3d9] FetchConstBuild #%ld post r3=0x%08X%c",k,(unsigned)ctx.r3.u32,10);
  }
}

PPC_FUNC_IMPL(__imp__sub_8209B098); // D3D9 SetShaderGPRAllocation — ALSO the static-blob resubmit
// site (s2B leg 4): emits 3 INDIRECT_BUFFER packets re-executing the CmdListBuild blob (state
// section dev+13992/96, fetch-const subrange, draw section dev+15024/28). Per-frame runtime
// caller = compose core sub_8216B148 P1, right before its Resolve. At RT_NVK=2 the recorder
// splices the captured cmdlist-authored draws at this stream position (wallpaper-then-black fix).
PPC_FUNC(sub_8209B098){
  NVK_TAP("SetShaderGPRAlloc_blobIB");
  uint32_t dv=ctx.r3.u32;
  __imp__sub_8209B098(ctx,base);
  if(nvk_mode()>=2 && dv && dv<0x40000000u) nvk_on_blob_submit(base, dv);
}

PPC_FUNC_IMPL(__imp__sub_8209AD40); // D3D9 SetStreamSource
PPC_FUNC(sub_8209AD40){
  NVK_TAP("q_ad40_StreamOrPS");
  static std::atomic<long> n{0}; long k=n++;
  bool log = rt_d3d9_on() && rt_d3d9_throttle(k);
  if(log) std::fprintf(stderr,"[d3d9] SetStreamSource #%ld device(r3)=0x%08X vb(r4)=0x%08X%c",k,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,10);
  __imp__sub_8209AD40(ctx,base);
  if(log){
    uint32_t devp=ctx.r3.u32;
    uint32_t bound = (devp && devp<0x40000000u)? rt_be32(base,devp+12872) : 0;
    std::fprintf(stderr,"[d3d9] SetStreamSource #%ld post device+12872=0x%08X%c",k,bound,10);
  }
}

PPC_FUNC_IMPL(__imp__sub_8209AB80); // D3D9 SetVertexDeclaration
PPC_FUNC(sub_8209AB80){
  NVK_TAP("q_ab80_VtxDeclOrVS");
  static std::atomic<long> n{0}; long k=n++;
  bool log = rt_d3d9_on() && rt_d3d9_throttle(k);
  if(log) std::fprintf(stderr,"[d3d9] SetVertexDecl #%ld device(r3)=0x%08X decl(r4)=0x%08X%c",k,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,10);
  __imp__sub_8209AB80(ctx,base);
  if(log){
    uint32_t devp=ctx.r3.u32;
    uint32_t bound = (devp && devp<0x40000000u)? rt_be32(base,devp+12868) : 0;
    std::fprintf(stderr,"[d3d9] SetVertexDecl #%ld post device+12868=0x%08X%c",k,bound,10);
  }
}

PPC_FUNC_IMPL(__imp__sub_820ABB60); // D3D9 SetIndices
PPC_FUNC(sub_820ABB60){
  static std::atomic<long> n{0}; long k=n++;
  bool log = rt_d3d9_on() && rt_d3d9_throttle(k);
  if(log) std::fprintf(stderr,"[d3d9] SetIndices #%ld device(r3)=0x%08X ib(r4)=0x%08X%c",k,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,10);
  __imp__sub_820ABB60(ctx,base);
  if(log){
    uint32_t devp=ctx.r3.u32;
    uint32_t bound = (devp && devp<0x40000000u)? rt_be32(base,devp+12884) : 0;
    std::fprintf(stderr,"[d3d9] SetIndices #%ld post device+12884=0x%08X%c",k,bound,10);
  }
}

PPC_FUNC_IMPL(__imp__sub_820A1218); // D3D9 Clear
PPC_FUNC(sub_820A1218){
  NVK_TAP("Clear1218");
  static std::atomic<long> n{0}; long k=n++;
  bool log = rt_d3d9_on() && rt_d3d9_throttle(k); // throttled: may fire per frame
  if(log){
    std::fprintf(stderr,"[d3d9] Clear #%ld r3=0x%08X r4=0x%08X r5=0x%08X r6=0x%08X r7=0x%08X r8=0x%08X r9=0x%08X r10=0x%08X%c",
      k,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,(unsigned)ctx.r5.u32,(unsigned)ctx.r6.u32,(unsigned)ctx.r7.u32,
      (unsigned)ctx.r8.u32,(unsigned)ctx.r9.u32,(unsigned)ctx.r10.u32,10);
    // Convention (matches VSConstF-write hook): bits=rt_be32(...); float f; memcpy(&f,&bits,4).
    // Log f1..f4 raw doubles (PPCContext floats are stored as f64 internally) plus a
    // best-effort reinterpretation, in case a plausible clear-color/Z float shows up here.
    std::fprintf(stderr,"[d3d9] Clear #%ld floats f1=%g f2=%g f3=%g f4=%g%c",
      k,ctx.f1.f64,ctx.f2.f64,ctx.f3.f64,ctx.f4.f64,10);
    // Two struct-ish pointers implicated by the current body (verified at runtime to be
    // r5=0x003409D0-ish and r6=0x00340A40-ish addresses per prior notes) -- dump 8 dwords
    // each via rt_be32, mimicking rt_dump_mem's format. r7 (0x00358590-ish) dumped too since
    // it is also a plausible heap pointer logged alongside r5/r6.
    if(ctx.r5.u32 && ctx.r5.u32<0x40000000u) rt_dump_mem(base,"Clear-r5",ctx.r5.u32,8);
    if(ctx.r6.u32 && ctx.r6.u32<0x40000000u) rt_dump_mem(base,"Clear-r6",ctx.r6.u32,8);
    if(ctx.r7.u32 && ctx.r7.u32<0x40000000u) rt_dump_mem(base,"Clear-r7",ctx.r7.u32,8);
  }
  if(log && k==0){
    // One-shot broad scan (first call only) for a plausible packed ARGB clear color
    // (alpha byte 0xFF, or fully-opaque dark value) anywhere in device+0..0x400 and in
    // the r5/r6/r7 structs out to 0x40 bytes -- cheap best-effort search, read-only.
    std::fprintf(stderr,"[d3d9] Clear #0 color-hunt: scanning device+0..0x400 and r5/r6/r7+0..0x40 for 0xFFxxxxxx-shaped dwords%c",10);
    auto scan=[&](const char* tag,uint32_t p,uint32_t len){
      if(!p||p>=0x40000000u) return;
      for(uint32_t off=0; off<len; off+=4){
        uint32_t v=rt_be32(base,p+off);
        if((v>>24)==0xFF) std::fprintf(stderr,"[d3d9]   color-hunt %s+0x%03X = 0x%08X (alpha=0xFF candidate)%c",tag,off,v,10);
      }
    };
    scan("device",ctx.r3.u32,0x400);
    scan("r5",ctx.r5.u32,0x40);
    scan("r6",ctx.r6.u32,0x40);
    scan("r7",ctx.r7.u32,0x40);
  }
  __imp__sub_820A1218(ctx,base);
}

PPC_FUNC_IMPL(__imp__sub_8209D2E0); // resource-ctor (VB-family?) -- generic buffer/texture-family constructor,
                                     // NOT confirmed CreateTexture (see sub_8209D400 below); kept per original
                                     // research request but relabeled after cross-check against ppc_recomp.28.cpp
PPC_FUNC(sub_8209D2E0){
  static std::atomic<long> n{0}; long k=n++;
  bool log = rt_d3d9_on() && k<12;
  if(log){
    std::fprintf(stderr,"[d3d9] ResCtor(VB-family?) #%ld pre r3=0x%08X r4=0x%08X r5=0x%08X r6=0x%08X r7=0x%08X r8=0x%08X r9=0x%08X%c",
      k,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,(unsigned)ctx.r5.u32,(unsigned)ctx.r6.u32,
      (unsigned)ctx.r7.u32,(unsigned)ctx.r8.u32,(unsigned)ctx.r9.u32,10);
  }
  __imp__sub_8209D2E0(ctx,base);
  if(log) std::fprintf(stderr,"[d3d9] ResCtor(VB-family?) #%ld post r3(ret/ptr)=0x%08X%c",k,(unsigned)ctx.r3.u32,10);
}

PPC_FUNC_IMPL(__imp__sub_8209D400); // D3D9 CreateTexture (confirmed: ppc_recomp.28.cpp:31584-31652 calls it 5x
                                     // with literal mip-chain widths 320/240/80/60/40/30/20/15)
PPC_FUNC(sub_8209D400){
  NVK_TAP("CreateTexture");
  static std::atomic<long> n{0}; long k=n++;
  bool log = rt_d3d9_on() && k<12;
  if(log){
    std::fprintf(stderr,"[d3d9] CreateTexture #%ld pre r3=0x%08X r4=0x%08X r5=0x%08X r6=0x%08X r7=0x%08X r8=0x%08X r9=0x%08X r10=0x%08X%c",
      k,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,(unsigned)ctx.r5.u32,(unsigned)ctx.r6.u32,
      (unsigned)ctx.r7.u32,(unsigned)ctx.r8.u32,(unsigned)ctx.r9.u32,(unsigned)ctx.r10.u32,10);
  }
  __imp__sub_8209D400(ctx,base);
  if(log) std::fprintf(stderr,"[d3d9] CreateTexture #%ld post r3(ret/texptr)=0x%08X%c",k,(unsigned)ctx.r3.u32,10);
}

// ★ RT_MVTICK (FNF-7 mid-tick discriminator, 2026-07-26) — MEASURE ONLY, DEFAULT OFF.
// sub_8217F948 @0x8217F948 is the M2Lib movie TICK: it reads the frame delta out of the time
// singleton DAT_821F85A0 and then runs three sequential stages —
//   FUN_8217DC10 (advance +0xB4 by +0xC0)  ->  FUN_8217F318 (per-part visibility +0x1B5)
//   ->  FUN_82177318.
// The 07-26 dt trace proved the delta is a HARD CONSTANT 1 (singleton +0x04 = 1 and +0x1C = 0,
// both written only by the ctor FUN_82170880 @0x82170880 and by nothing else in the image), so
// the timeline is TICK-COUNTED and cannot phase-drift from a jittery host clock. That refutes the
// "sub-frame dt divergence" model and leaves exactly one divergence channel: how many times this
// tick runs per RENDERED frame, and what part-visibility state we sample when we walk the scene.
// This hook exports that state; vk_render's RVK_DRAWTRIP block prints one line per rendered frame
// (see RVK_MVLOG there) so ticks and draws are paired on the same line.
// The counters are reset by the renderer, not here — the renderer owns the frame boundary.
// Cost when armed: ~60 guest byte reads per tick, no I/O on this side. Nothing is written back
// into guest memory, and the original is always called.
// ROSTER, not a single watched object. First cut used a sticky "widest movie" watch on the
// assumption the TOP MENU is one ~60-part instance; MEASURED FALSE — every ticked movie carries
// only 10/11/15 parts, i.e. the menu is a top container plus NESTED sub-movies (each nested player
// is ticked separately through this same entry, ~6 per frame). A single watch therefore reads the
// wrong object and any null it produces is meaningless. Track them all and let the correlation
// against the draw count name the one whose visible-part count moves.
#define MV_MAX 12
extern "C" {
  volatile int      g_mv_calls = 0;        // ticks (all objects) since the renderer last reset
  volatile int      g_mv_n     = 0;        // roster slots in use
  volatile unsigned g_mv_o[MV_MAX] = {0};  // object (guest addr)
  volatile int      g_mv_p[MV_MAX] = {0};  // parts in the vector
  volatile int      g_mv_t[MV_MAX] = {0};  // +0x10C total frames in the clip
  volatile int      g_mv_b[MV_MAX] = {0};  // +0xB4 position (raw float bits)
  volatile int      g_mv_v[MV_MAX] = {0};  // parts with +0x1B5 (effective visibility) set
  volatile int      g_mv_c[MV_MAX] = {0};  // ticks of THIS object since the renderer last reset
}
PPC_FUNC_IMPL(__imp__sub_8217F948);   // M2Lib movie tick (advance + visibility + stage 3)
PPC_FUNC(sub_8217F948){
  static const bool on = std::getenv("RT_MVTICK") != nullptr;
  uint32_t obj = ctx.r3.u32;
  __imp__sub_8217F948(ctx, base);         // ALWAYS run the guest first: we read the settled state
  if(!on) return;
  ++g_mv_calls;
  int s = -1;
  for(int i = 0; i < g_mv_n && i < MV_MAX; ++i) if(g_mv_o[i] == obj){ s = i; break; }
  if(s < 0){ if(g_mv_n >= MV_MAX) return; s = g_mv_n++; g_mv_o[s] = obj; }
  ++g_mv_c[s];
  // parts vector: +0xFC = begin, +0x100 = end, element stride 0x20C (emitter report §1.6).
  uint32_t pb = rt_be32(base, obj + 0xFC), pe = rt_be32(base, obj + 0x100);
  int n = 0;
  if(pb && pe > pb && (pe - pb) < 0x40000u && (pe - pb) % 0x20Cu == 0) n = (int)((pe - pb) / 0x20Cu);
  int vis = 0;
  for(int i = 0; i < n; ++i) if(*(uint8_t*)(base + pb + (size_t)i * 0x20Cu + 0x1B5)) ++vis;
  g_mv_p[s] = n; g_mv_v[s] = vis;
  g_mv_b[s] = (int)rt_be32(base, obj + 0xB4);
  g_mv_t[s] = (int)rt_be32(base, obj + 0x10C);
}

// ===== HARD PIVOT (2026-07-28): nvk stage-0 trace hooks for the previously-unhooked wrapper
// functions (C2 census, ATLAS_d3d_wrapper.md). Pure taps: log at entry, call through. The
// q_-prefixed pair carries the lane-A/lane-C identity conflict; the trace resolves it.
#define NVK_HOOK(addr, name)   PPC_FUNC_IMPL(__imp__sub_##addr);   PPC_FUNC(sub_##addr){ NVK_TAP(name); __imp__sub_##addr(ctx,base); }
// SetRenderTarget: probe (s2B leg 6, RT segmentation) — RT_NVKRTLOG=1 dumps args + surface
// object dwords to identify the dims/base fields; nvk_on_setrt feeds the recorder.
extern "C" void nvk_on_setrt(uint8_t* base, unsigned dev, unsigned idx, unsigned surf);
PPC_FUNC_IMPL(__imp__sub_82099AD8);
PPC_FUNC(sub_82099AD8){
  NVK_TAP("SetRenderTarget");
  uint32_t dv=ctx.r3.u32, ix=ctx.r4.u32, sf=ctx.r5.u32;
  static bool rtlog = std::getenv("RT_NVKRTLOG")!=nullptr;
  if(rtlog){
    static long n=0;
    if(n++<40){
      std::fprintf(stderr,"[nvkrt] S_SetRT #%ld r3=%08X r4=%08X r5=%08X r6=%08X lr=%08X\n",
        n,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,(unsigned)ctx.r5.u32,(unsigned)ctx.r6.u32,(unsigned)ctx.lr);
      for(uint32_t p: {ix, sf}) if(p>0x1000u && p<0x20000000u){
        std::fprintf(stderr,"[nvkrt]   obj %08X:",p);
        for(int i=0;i<14;i++) std::fprintf(stderr," %08X",rt_be32(base,p+(uint32_t)i*4));
        std::fprintf(stderr,"\n");
      }
    }
  }
  __imp__sub_82099AD8(ctx,base);
  if(nvk_mode()>=2) nvk_on_setrt(base, dv, ix, sf);
}
NVK_HOOK(820999A8, "SetViewport")
NVK_HOOK(820990E0, "SetScissorRect")
NVK_HOOK(8209D660, "SetTexture")
NVK_HOOK(8209B2B0, "CreateVS")   // ★ label swapped per s1_abi §8/§9: 8209B2B0 body = CreatePIXELShader (kept for trace continuity)
NVK_HOOK(8209B498, "CreatePS")   // ★ label swapped: 8209B498 body = CreateVERTEXShader
NVK_HOOK(820995F0, "RS_BlendControl")
NVK_HOOK(82096EB0, "RS_AlphaBlendEnable")
NVK_HOOK(82096FD0, "RS_SrcBlend")
NVK_HOOK(82097060, "RS_DestBlend")
NVK_HOOK(82097338, "RS_CullMode")
NVK_HOOK(820972D8, "RS_AlphaTest")   // ★ s1_abi §14: actually D3DRS_ALPHAREF (enable lives elsewhere)
NVK_HOOK(820975E8, "RS_ZEnable")
// SetVSConstantF (8209A998: r4=StartReg, r5=src, r6=Vec4Count) and Clear (820A19F0: r7=ARGB;
// Z rides f1, r8 is garbage — s1_abi §2) get explicit bodies so the RT_NVK=2 recorder sees them.
PPC_FUNC_IMPL(__imp__sub_8209A998);
PPC_FUNC(sub_8209A998){
  NVK_TAP("SetVSConstantF");
  // (stage-2: consts now snapshot register-true from dev+0x780/0x1780 at draw time, dirty-gated)
  __imp__sub_8209A998(ctx,base);
}
PPC_FUNC_IMPL(__imp__sub_820A19F0);
PPC_FUNC(sub_820A19F0){
  NVK_TAP("Clear19F0");
  if(nvk_mode()>=2) nvk_on_clear(ctx.r7.u32);
  __imp__sub_820A19F0(ctx,base);
}
