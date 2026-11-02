// rt_engsamp.cpp -- RT_ENGSAMP=1: a host-side SAMPLING profiler of ONE guest thread (the XAudio engine thread),
// WIN-AUDIO-1 round 5 (2026-11-03).  Windows only; the TU is empty elsewhere and merged_shell.cpp binds to it weakly.
//
// WHY: the engine frame sub_82137218 is CPU-bound (cpu ~= wall under the 0x36A0D4 hold) and 75 % of it is the SFX
// source-voice render sub_82150338 at 0.7 ms per voice per 5.33 ms frame, single calls up to 20 ms.  Timing hooks
// (`[engprof]`) can only name functions that were hooked in advance, and the render's work is behind six indirect
// calls (the decoder / SRC / filter objects' vtables).  A sampler needs no roster: every ~1 ms it suspends the engine
// thread, reads RIP + unwinds its stack (the exe's own .pdata, RtlVirtualUnwind -- no loader lock, no allocation while
// the target is suspended), resumes it, and attributes the sample to the recompiled body it was in (symbols from the
// shell's PPCFuncMappings table: host fn pointer -> guest address -> `sub_8XXXXXXX`; hooked bodies are added by name
// through rt_engsamp_add_sym since the table holds the HOOK's address for those).  Every 60 s it prints
//   [engsamp] 60s samples=N inframe=M (K% of wall)        -- M = samples taken while sub_82137218 was on the stack
//   [engsamp] self  <pct> <n> <name>                         -- top self (leaf) buckets, in-frame only
//   [engsamp] incl  <pct> <n> <name>                         -- top inclusive buckets (name anywhere on the stack)
//   [engsamp] exe+<rva> ...                                 -- unresolved exe addresses (resolve with build/futari_combined.map)
// Cost: SuspendThread/GetThreadContext/ResumeThread ~10-20 us per sample on the TARGET thread (a 1-2 % tax); never on
// by default.  A profiled census is never a verdict count (BACKLOG 2026-11-02: instruments perturb).
#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <mmsystem.h>   // timeBeginPeriod (excluded by WIN32_LEAN_AND_MEAN); winmm is already on the link line
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <atomic>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <mutex>

struct PPCFuncMapping { size_t guest; void* host; };         // the shell table has C++ linkage and its mangled name carries this struct name
extern PPCFuncMapping PPCFuncMappings_shell[] __attribute__((weak));

namespace {
struct Sym { uint64_t addr; std::string name; };
std::vector<Sym> g_syms;                                     // sorted by addr once the sampler starts
std::mutex g_sym_mtx;
std::atomic<int> g_inframe{0};
std::atomic<int> g_started{0};
HANDLE g_target=nullptr; DWORD g_target_tid=0;
HMODULE g_exe=nullptr; uint64_t g_exe_lo=0, g_exe_hi=0;
RUNTIME_FUNCTION* g_rf=nullptr; size_t g_nrf=0;
std::atomic<long> g_nsamp{0}, g_ninframe{0};

bool es_on(){ static bool on=std::getenv("RT_ENGSAMP")!=nullptr; return on; }
int es_hz(){ static int hz=[]{ const char* e=std::getenv("RT_ENGSAMP"); int v=e?std::atoi(e):0; return v>=100?v:1000; }(); return hz; }

RUNTIME_FUNCTION* es_lookup(uint64_t rip){
  if(!g_rf || rip<g_exe_lo || rip>=g_exe_hi) return nullptr;
  DWORD rva=(DWORD)(rip-g_exe_lo); size_t lo=0, hi=g_nrf;
  while(lo<hi){ size_t mid=(lo+hi)/2; const RUNTIME_FUNCTION& f=g_rf[mid];
    if(rva<f.BeginAddress) hi=mid; else if(rva>=f.EndAddress) lo=mid+1; else return &g_rf[mid]; }
  return nullptr;
}
// nearest preceding symbol; -1 if before the first (or outside the exe)
int es_sym(uint64_t a){
  if(a<g_exe_lo||a>=g_exe_hi) return -2;
  auto it=std::upper_bound(g_syms.begin(),g_syms.end(),a,[](uint64_t v,const Sym& s){ return v<s.addr; });
  if(it==g_syms.begin()) return -1;
  return (int)(it-g_syms.begin())-1;
}

struct Acc { std::vector<long> self, incl; std::unordered_map<uint32_t,long> unres; long ext=0, unresn=0; };
Acc g_acc;

void es_report(){
  long n=g_nsamp.exchange(0), m=g_ninframe.exchange(0);
  std::fprintf(stderr,"[engsamp] 60s samples=%ld inframe=%ld (%.1f%% of wall) target tid=%lu\n",n,m,n?100.0*m/n:0.0,(unsigned long)g_target_tid);
  auto top=[&](const char* tag, std::vector<long>& v){
    std::vector<int> idx; for(int i=0;i<(int)v.size();i++) if(v[i]) idx.push_back(i);
    std::sort(idx.begin(),idx.end(),[&](int a,int b){ return v[a]>v[b]; });
    int shown=0; for(int i: idx){ if(shown++>=32) break;
      std::fprintf(stderr,"[engsamp] %s %5.1f%% %6ld %s\n",tag,m?100.0*v[i]/m:0.0,v[i],g_syms[i].name.c_str()); v[i]=0; }
  };
  top("self",g_acc.self); top("incl",g_acc.incl);
  if(g_acc.ext||g_acc.unresn) std::fprintf(stderr,"[engsamp] other: outside-exe(self)=%ld exe-unresolved(self)=%ld\n",g_acc.ext,g_acc.unresn);
  g_acc.ext=0; g_acc.unresn=0;
  { std::vector<std::pair<uint32_t,long>> u(g_acc.unres.begin(),g_acc.unres.end());
    std::sort(u.begin(),u.end(),[](auto&a,auto&b){ return a.second>b.second; });
    for(size_t i=0;i<u.size()&&i<12;i++) std::fprintf(stderr,"[engsamp] exe+0x%X %ld\n",u[i].first,u[i].second);
    g_acc.unres.clear(); }
}

DWORD WINAPI es_thread(LPVOID){
  { std::lock_guard<std::mutex> lk(g_sym_mtx);
    if(PPCFuncMappings_shell) for(PPCFuncMapping* p=PPCFuncMappings_shell; p->host; ++p){ char b[32]; std::snprintf(b,sizeof b,"sub_%08X",(unsigned)p->guest); g_syms.push_back({(uint64_t)p->host,b}); }
    g_syms.push_back({(uint64_t)(void*)&memcpy,"host:memcpy"}); g_syms.push_back({(uint64_t)(void*)&memset,"host:memset"});
    std::sort(g_syms.begin(),g_syms.end(),[](const Sym&a,const Sym&b){ return a.addr<b.addr; });
    g_acc.self.assign(g_syms.size(),0); g_acc.incl.assign(g_syms.size(),0); }
  std::fprintf(stderr,"[engsamp] sampler up: %zu symbols, %zu unwind entries, exe %p..%p, %d Hz\n",g_syms.size(),g_nrf,(void*)g_exe_lo,(void*)g_exe_hi,es_hz());
  timeBeginPeriod(1);
  LARGE_INTEGER qf; QueryPerformanceFrequency(&qf); LARGE_INTEGER t_last_rep; QueryPerformanceCounter(&t_last_rep);
  const int64_t period_us=1000000/es_hz(); std::vector<int> stack; stack.reserve(64);
  for(;;){
    LARGE_INTEGER t0; QueryPerformanceCounter(&t0);
    bool inframe=g_inframe.load(std::memory_order_relaxed)!=0;
    uint64_t rips[64]; int nr=0; bool ok=false;
    if(SuspendThread(g_target)!=(DWORD)-1){
      CONTEXT c; std::memset(&c,0,sizeof c); c.ContextFlags=CONTEXT_CONTROL|CONTEXT_INTEGER;
      if(GetThreadContext(g_target,&c)){ ok=true;
        for(int d=0; d<64; ++d){
          uint64_t rip=c.Rip; rips[nr++]=rip;
          if(rip<g_exe_lo||rip>=g_exe_hi) break;                               // cannot unwind foreign modules lock-free; stop
          RUNTIME_FUNCTION* rf=es_lookup(rip);
          if(rf){ void* hd=nullptr; DWORD64 est=0;
            RtlVirtualUnwind(UNW_FLAG_NHANDLER,(DWORD64)g_exe_lo,rip,rf,&c,&hd,&est,nullptr); }
          else { if(c.Rsp==0) break; c.Rip=*(uint64_t*)c.Rsp; c.Rsp+=8; }     // leaf: return address on top of the stack
          if(c.Rip==0) break;
        } }
      ResumeThread(g_target);
    }
    if(ok){
      g_nsamp.fetch_add(1);
      if(inframe){ g_ninframe.fetch_add(1);
        int s=es_sym(rips[0]);
        if(s>=0) g_acc.self[s]++; else if(s==-2) g_acc.ext++; else { g_acc.unresn++; }
        if(s==-1 || (s>=0 && rips[0]-g_syms[s].addr>0x20000)) g_acc.unres[(uint32_t)(rips[0]-g_exe_lo)]++;
        stack.clear();
        for(int i=0;i<nr;i++){ int k=es_sym(rips[i]); if(k<0) continue; if(std::find(stack.begin(),stack.end(),k)==stack.end()){ stack.push_back(k); g_acc.incl[k]++; } }
      }
    }
    LARGE_INTEGER t1; QueryPerformanceCounter(&t1);
    if((t1.QuadPart-t_last_rep.QuadPart)*1000000/qf.QuadPart>=60000000){ t_last_rep=t1; es_report(); }
    int64_t spent=(t1.QuadPart-t0.QuadPart)*1000000/qf.QuadPart; int64_t rest=period_us-spent;
    if(rest>1500) Sleep((DWORD)(rest/1000)); else if(rest>0){ LARGE_INTEGER t2; do{ YieldProcessor(); QueryPerformanceCounter(&t2);}while((t2.QuadPart-t0.QuadPart)*1000000/qf.QuadPart<period_us); }
  }
  return 0;
}
} // namespace

extern "C" void rt_engsamp_add_sym(void* addr, const char* name){
  if(!es_on()) return; std::lock_guard<std::mutex> lk(g_sym_mtx);
  if(g_started.load()) return;                                  // table is frozen once the sampler runs
  g_syms.push_back({(uint64_t)addr,name});
}
// enter=1 from the calling thread at the top of the outermost engine frame, 0 on leave. The FIRST call adopts the caller
// as the target thread and starts the sampler.
extern "C" void rt_engsamp_frame(int enter){
  if(!es_on()) return;
  if(!g_started.load(std::memory_order_acquire)){
    std::lock_guard<std::mutex> lk(g_sym_mtx);
    if(!g_started.load()){
      g_target_tid=GetCurrentThreadId();
      DuplicateHandle(GetCurrentProcess(),GetCurrentThread(),GetCurrentProcess(),&g_target,0,FALSE,DUPLICATE_SAME_ACCESS);
      g_exe=GetModuleHandleW(nullptr); auto* dos=(IMAGE_DOS_HEADER*)g_exe; auto* nt=(IMAGE_NT_HEADERS*)((BYTE*)g_exe+dos->e_lfanew);
      g_exe_lo=(uint64_t)g_exe; g_exe_hi=g_exe_lo+nt->OptionalHeader.SizeOfImage;
      auto& dir=nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXCEPTION];
      if(dir.VirtualAddress&&dir.Size){ g_rf=(RUNTIME_FUNCTION*)((BYTE*)g_exe+dir.VirtualAddress); g_nrf=dir.Size/sizeof(RUNTIME_FUNCTION); }
      g_started.store(1,std::memory_order_release);
      CreateThread(nullptr,0,es_thread,nullptr,0,nullptr);
    }
  }
  g_inframe.store(enter,std::memory_order_relaxed);
}
#else
extern "C" void rt_engsamp_add_sym(void*, const char*){}
extern "C" void rt_engsamp_frame(int){}
#endif
