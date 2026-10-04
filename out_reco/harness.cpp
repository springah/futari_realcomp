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
#include <unistd.h>   // alarm/usleep/_exit (macOS libc++ does not pull it in transitively)
#endif
#if defined(_WIN32) || defined(__APPLE__)
// C23 round-half-to-even the recompiler emits (glibc has it; MSVC UCRT and Apple libm do not --
// the combined host's ABI table takes &roundevenf, so macOS needs the definition too, 2026-10-04).
#include <cmath>
extern "C" float  roundevenf(float x){ return nearbyintf(x); }
extern "C" double roundeven (double x){ return nearbyint(x); }
#endif
extern std::atomic<long> g_import_calls;
static uint8_t* g_base;
static uint32_t g_ord1=0;
// futari_merged / RT_SHELL cross-module probe: shell's own PPCFuncMapping table, built
// with -DPPCFuncMappings=PPCFuncMappings_shell so its symbol doesn't collide with the
// game's PPCFuncMappings. Only referenced when RT_SHELL=1 (see main()). Declared WEAK so
// that futari_mode -- which links no shell/gen object defining this symbol -- still links
// cleanly; it will simply resolve to null there (and RT_SHELL is never set for futari_mode).
extern PPCFuncMapping PPCFuncMappings_shell[] __attribute__((weak));
extern "C" uint32_t g_thread_xapi, g_thread_entry, g_thread_ctx;
uint32_t g_thread_xapi=0, g_thread_entry=0, g_thread_ctx=0;
// ---- PHYSICAL ALLOCATOR: rt_phys.cpp (the 08-04-ruled spec rewrite; the five laws and
// their decomp provenance are documented there). The harness keeps only the arena mapping
// and hands the base over at boot.
extern "C" void rt_phys_init(uint8_t* base);
extern "C" uint32_t rt_phys_frontier();
extern "C" uint32_t rt_alloc(uint32_t size, uint32_t align);
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
// RT_WATCHTEX / rt_watch_arm_dyn are the PAGE_GUARD + single-step watch (Windows-only above);
// the merged_shell.cpp probes call rt_watch_arm_dyn unconditionally, so POSIX gets a no-op
// that says so once. A mprotect+SIGSEGV port is possible but is harness-only instrumentation.
extern "C" void rt_watch_arm_dyn(uint32_t guestAddr, uint32_t len){
  static bool said=false;
  if(!said){ said=true; std::fprintf(stderr,"[watchtex] DYN arm requested (guest 0x%08X len 0x%X) — guard-page watch is Windows-only; ignored\n",guestAddr,len); }
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

#ifndef _WIN32
#ifndef MAP_NORESERVE
#define MAP_NORESERVE 0   // macOS has no MAP_NORESERVE; anonymous mappings are lazily committed anyway
#endif
#endif
#if defined(__APPLE__)
// macOS (2026-10-03 handoff): Cocoa requires the window and its event pump on the process's main
// thread, and the guest (and its presents) run on whatever thread calls into it. So under
// RVK_WINDOW the real main() hands the whole harness to rvk_run_on_main_thread (vk_render.cpp),
// which runs guest_main on a big-stack thread while the main thread owns SDL. Headless runs are
// unchanged. Weak so a vk_render-less link still resolves.
extern "C" int rvk_run_on_main_thread(int (*fn)(int, char**), int argc, char** argv) __attribute__((weak));
static int guest_main(int argc,char**argv);
int main(int argc,char**argv){
  if(std::getenv("RVK_WINDOW") && rvk_run_on_main_thread) return rvk_run_on_main_thread(guest_main,argc,argv);
  return guest_main(argc,argv);
}
static int guest_main(int argc,char**argv){
#else
int main(int argc,char**argv){
#endif
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
  if(!base){std::fprintf(stderr,"VirtualAlloc 4GB failed: %lu\n",(unsigned long)GetLastError());return 1;} g_base=base; rt_phys_init(base);
#else
  uint8_t* base=(uint8_t*)mmap(nullptr,0x100000000ull,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS|MAP_NORESERVE,-1,0);
  if(base==MAP_FAILED){std::perror("mmap");return 1;} g_base=base; rt_phys_init(base);
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
    // RT_SAMPLES=0 = ATTENDED session (scripts/run_mac.sh): no alarm at all, the window's close
    // button ends the run. Before this the only way to run the shell for longer than ~22 s on a
    // POSIX host was an absurd sample count printing a backtrace every 4 s.
    { const char* se=getenv("RT_SAMPLES"); g_samples_left=se?atoi(se):5; }
    if(!(getenv("RT_SAMPLES") && std::strcmp(getenv("RT_SAMPLES"),"0")==0)) alarm(6);
    sfn(ctx,base);
    std::fprintf(stderr,"\n[boot-shell] RETURNED. imports=%ld r3=0x%llx\n",g_import_calls.load(),(unsigned long long)ctx.r3.u64);
    return 0;
  }

  ctx.r3.u64=0x88000000; ctx.r4.u64=(uint64_t)reason; ctx.r5.u64=0;
  PPCFunc* fn=*(PPCFunc**)(base+PPC_IMAGE_BASE+PPC_IMAGE_SIZE+(uint64_t)(uint32_t)((uint32_t)target-PPC_CODE_BASE)*2);
  std::fprintf(stderr,"[harness] %ld funcs; r13=0x%X r1=0x%llX heap_next=0x%X; call 0x%llX reason=%ld\n\n",n,tb,(unsigned long long)ctx.r1.u64,rt_phys_frontier(),(unsigned long long)target,reason);
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
