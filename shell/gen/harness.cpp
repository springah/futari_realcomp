#include "ppc_recomp_shared.h"
#include <file.h>
#include <image.h>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <atomic>
#include <csignal>
#include <execinfo.h>
#include <unistd.h>
#include <sys/mman.h>
#include <mutex>
extern std::atomic<long> g_import_calls;
static uint8_t* g_base; static uint32_t g_heap=0x00300000;
extern "C" uint32_t rt_alloc(uint32_t size,uint32_t align){ static std::mutex _am; std::lock_guard<std::mutex> _al(_am); if(align<1)align=1; g_heap=(g_heap+align-1)&~(align-1); uint32_t p=g_heap; g_heap+=((size+15)&~15u); return p; }
static void onsig(int s, siginfo_t* si, void*){ void* a=si->si_addr; long off=(uint8_t*)a-g_base;
  std::fprintf(stderr,"\n[SIGNAL %d] fault at %p",s,a);
  if(off>=0 && off<(long)0x100000000LL) std::fprintf(stderr," = guest 0x%08lX",(unsigned long)off);
  std::fprintf(stderr,"; imports called=%ld\n",g_import_calls.load());
  void* bt[48]; int nn=backtrace(bt,48); backtrace_symbols_fd(bt,nn,2);
  if(s==SIGALRM){ // periodic sampler: re-arm up to RT_SAMPLES times (default 5), then exit
    static int left=-1; if(left<0){ const char* e=getenv("RT_SAMPLES"); left=e?atoi(e):5; }
    if(--left>0){ alarm(3); return; } }
  _exit(42); }
int main(int argc,char**argv){
  struct sigaction sa; std::memset(&sa,0,sizeof sa); sa.sa_sigaction=onsig; sa.sa_flags=SA_SIGINFO;
  sigaction(SIGSEGV,&sa,0); sigaction(SIGBUS,&sa,0); sigaction(SIGILL,&sa,0); sigaction(SIGFPE,&sa,0); sigaction(SIGALRM,&sa,0);
  uint64_t target=argc>1?strtoull(argv[1],0,16):PPC_CODE_BASE;
  long reason=argc>2?strtol(argv[2],0,0):0;
  const char* xexpath=argc>3?argv[3]:nullptr;
  uint8_t* base=(uint8_t*)mmap(nullptr,0x100000000ull,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS|MAP_NORESERVE,-1,0);
  if(base==MAP_FAILED){std::perror("mmap");return 1;} g_base=base;
  const uint64_t IMG_LO=PPC_IMAGE_BASE, IMG_HI=(uint64_t)PPC_IMAGE_BASE+PPC_IMAGE_SIZE;
  if(xexpath){ auto f=LoadFile(xexpath); Image img=Image::ParseImage(f.data(),f.size()); long sc=0; unsigned long long by=0;
    for(const auto& sN: img.sections){ uint64_t b=(uint64_t)sN.base,z=(uint64_t)sN.size;
      if(!sN.data||z==0||b<IMG_LO||b+z>IMG_HI) continue;
      std::memcpy(base+b,(const void*)sN.data,z); ++sc; by+=z; }
    std::fprintf(stderr,"[harness] XEX: %ld sections %llu bytes into [%llX,%llX)\n",sc,by,(unsigned long long)IMG_LO,(unsigned long long)IMG_HI); }
  long n=0; for(PPCFuncMapping* m=PPCFuncMappings; m->guest||m->host; ++m){ if(!m->host)continue; uint32_t g=(uint32_t)m->guest;
    *(PPCFunc**)(base+PPC_IMAGE_BASE+PPC_IMAGE_SIZE+(uint64_t)(uint32_t)(g-PPC_CODE_BASE)*2)=m->host; ++n; }
  const uint32_t PCR=0xAB0,TLS=0x100,TEB=0x2E0,STK=0x40000,TOT=PCR+TLS+TEB+STK;
  uint32_t tb=rt_alloc(TOT,0x1000); uint8_t* t=base+tb; std::memset(t,0,TOT);
  *(uint32_t*)t=__builtin_bswap32(tb+PCR); *(uint32_t*)(t+0x100)=__builtin_bswap32(tb+PCR+TLS); t[0x10C]=0;
  *(uint32_t*)(t+PCR+0x10)=0xFFFFFFFF; *(uint32_t*)(t+PCR+TLS+0x14C)=__builtin_bswap32(1);
  PPCContext ctx{}; ctx.r1.u64=tb+PCR+TLS+TEB+STK; ctx.r13.u64=tb; ctx.fpscr.loadFromHost();
  ctx.r3.u64=(uint64_t)reason;
  PPCFunc* fn=*(PPCFunc**)(base+PPC_IMAGE_BASE+PPC_IMAGE_SIZE+(uint64_t)(uint32_t)((uint32_t)target-PPC_CODE_BASE)*2);
  std::fprintf(stderr,"[harness] %ld funcs; r13=0x%X r1=0x%llX; call 0x%llX reason=%ld\n\n",n,tb,(unsigned long long)ctx.r1.u64,(unsigned long long)target,reason);
  if(!fn){std::fprintf(stderr,"no fn\n");return 1;}
  alarm(6); fn(ctx,base);
  std::fprintf(stderr,"\n[harness] RETURNED. imports=%ld r3=0x%llx\n",g_import_calls.load(),(unsigned long long)ctx.r3.u64);
  return 0;
}
