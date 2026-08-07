#include "ppc_recomp_shared.h"
#include <cstdio>
#include <cstdlib>
#include <atomic>
#include <chrono>
#ifndef _WIN32
#include <unistd.h>
#endif
std::atomic<long> g_import_calls{0};
// Monotonic guest system time in 100ns units, anchored to the same in-era 0x01C6... epoch the
// shell/gen/rt.cpp KeQuerySystemTime + rt_realtime_100ns helper use (so absolute-date checks stay
// in-era and the two modules agree on the clock). (2026-07-22 mixed-signal fix — see below.)
static uint64_t game_realtime_100ns(){
  static const uint64_t ep = 0x01C6000000000000ULL;
  static const std::chrono::steady_clock::time_point t0 = std::chrono::steady_clock::now();
  return ep + (uint64_t)(std::chrono::duration_cast<std::chrono::nanoseconds>(
                std::chrono::steady_clock::now() - t0).count() / 100);
}
PPC_FUNC_IMPL(__imp__DbgPrint){g_import_calls++;uint32_t p=ctx.r3.u32;
  if(p) std::fprintf(stderr,"  [DbgPrint] %.300s | r4=0x%X r5=0x%X r6=0x%X\n",(const char*)(base+p),ctx.r4.u32,ctx.r5.u32,ctx.r6.u32);
  ctx.r3.u64=0;(void)base;}
// ★ CODE_REVIEW_0804 C11: THIS is the def that wins the /FORCE:MULTIPLE link (game_stubs.o
// links before shell TUs) — the RT_XCFGTRACE tracer lived only in the DEAD shell/gen/stubs.cpp
// copy, so the one open stub-audit suspect could never be observed. Tracer lives here now.
PPC_FUNC_IMPL(__imp__ExGetXConfigSetting){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__ExGetXConfigSetting\n");}g_import_calls++;
  if(std::getenv("RT_XCFGTRACE")){
    static std::atomic<long> n{0}; long k=n.fetch_add(1)+1;
    if(k<=64) std::fprintf(stderr,"[xcfg] #%ld category=0x%X setting=0x%X buf=0x%X size=%u req=0x%X lr=0x%X\n",
                           k,ctx.r3.u32,ctx.r4.u32,ctx.r5.u32,ctx.r6.u32,ctx.r7.u32,(uint32_t)ctx.lr);
  }
  ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__ExRegisterTitleTerminateNotification){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__ExRegisterTitleTerminateNotification\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeBugCheck){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeBugCheck\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeBugCheckEx){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeBugCheckEx\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
// MIXED-SIGNAL FIX (2026-07-22, stub audit MS1): this game-module def LINKS FIRST and shadows the
// real shell/gen/rt.cpp impl for BOTH modules. The old body left the u64 out-param (*r3) UNWRITTEN
// (only set r3=0), so every guest KeQuerySystemTime call — from either module — read a garbage/stale
// 64-bit time (RNG seeds, save timestamps, elapsed-time deltas). Now writes a real monotonic
// FILETIME (100ns units, BE) to *r3, matching the shell impl. ABI: r3 = PLARGE_INTEGER out.
PPC_FUNC_IMPL(__imp__KeQuerySystemTime){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeQuerySystemTime (real clock)\n");}g_import_calls++;
  uint32_t p=ctx.r3.u32; uint64_t t=game_realtime_100ns();
  if(p)*(uint64_t*)(base+p)=__builtin_bswap64(t); ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeSetAffinityThread){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeSetAffinityThread\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeSetBasePriorityThread){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeSetBasePriorityThread\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KfAcquireSpinLock){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KfAcquireSpinLock\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KfReleaseSpinLock){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KfReleaseSpinLock\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
// Real frees (2026-07-20 late-stage-soak leak fix): the guest allocator grows/releases 8-16MB
// arenas per attract cycle; no-op frees leaked ~75MB/cycle (26min soak -> 1.98GB RSS). rt_free
// returns tracked rt_alloc regions to an exact-size reuse pool (harness.cpp); foreign/interior
// addresses are safely ignored. SDK ABI (rexglue xboxkrnl_memory.cpp): MmFreePhysicalMemory
// (r3=type, r4=guest addr); NtFreeVirtualMemory(r3=&base in/out, r4=&size in/out, r5=free_type)
// — only X_MEM_RELEASE (0x8000) frees; DECOMMIT keeps the address space (re-commit expects the
// same base, and our flat mapping keeps it valid).
extern "C" void rt_free(uint32_t addr);
extern "C" void rt_free_ex(uint32_t addr, uint64_t callerLr);
PPC_FUNC_IMPL(__imp__MmFreePhysicalMemory){g_import_calls++;
  static long fn=0; if(fn++<8) std::fprintf(stderr,"  [free] Mm type=%u addr=0x%X lr=0x%llX\n",ctx.r3.u32,ctx.r4.u32,(unsigned long long)ctx.lr);
  rt_free_ex(ctx.r4.u32,(uint64_t)ctx.lr); ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtDuplicateObject){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtDuplicateObject\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
extern "C" void rt_decommit_note(uint32_t addr,uint32_t size);
PPC_FUNC_IMPL(__imp__NtFreeVirtualMemory){g_import_calls++;
  uint32_t baseptr=ctx.r3.u32, sizeptr=ctx.r4.u32, ftype=ctx.r5.u32;
  uint32_t addr = baseptr ? __builtin_bswap32(*(uint32_t*)(base+baseptr)) : 0;
  uint32_t rsz  = sizeptr ? __builtin_bswap32(*(uint32_t*)(base+sizeptr)) : 0;
  static long fn=0; if(fn++<12) std::fprintf(stderr,"  [free] NtVA base=0x%X size=0x%X type=0x%X\n",addr,rsz,ftype);
  if(addr && (ftype & 0x8000u)) rt_free(addr);             // X_MEM_RELEASE: back to the reuse pool
  else if(addr && (ftype & 0x4000u)) rt_decommit_note(addr,rsz);   // X_MEM_DECOMMIT: quarantined host decommit
  ctx.r3.u64=0;}
PPC_FUNC_IMPL(__imp__NtQueryDirectoryFile){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtQueryDirectoryFile\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtQueryVirtualMemory){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtQueryVirtualMemory\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtReadFileScatter){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtReadFileScatter\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
// __imp__NtWriteFile / __imp__NtFlushBuffersFile moved to out_reco/rt.cpp (RT_SAVE real host writes)
PPC_FUNC_IMPL(__imp__ObDereferenceObject){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__ObDereferenceObject\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__ObReferenceObjectByHandle){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__ObReferenceObjectByHandle\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__RtlCompareMemoryUlong){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlCompareMemoryUlong\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__RtlImageXexHeaderField){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlImageXexHeaderField\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
// Real mapping (rexglue xboxkrnl_error.cpp parity for the statuses our kernel emits).
// The return-0 stub broke the shell's async-I/O poll loop: sub_82089890 returns 0 on
// STATUS_PENDING and its caller (sub_82192218) checks GetLastError()==997 to keep
// waiting — error 0 made every streaming request record status -1 (failed).
PPC_FUNC_IMPL(__imp__RtlNtStatusToDosError){g_import_calls++;
  uint32_t s=ctx.r3.u32, r;
  if(!s || (s & 0x20000000u)) r=s;
  else if((s>>16)==0x8007u) r=s&0xFFFFu;
  else switch(s){
    case 0x00000103u: r=997; break;   // STATUS_PENDING -> ERROR_IO_PENDING
    case 0x00000102u: r=1460; break;  // STATUS_TIMEOUT -> ERROR_TIMEOUT
    case 0xC0000011u: r=38; break;    // END_OF_FILE -> ERROR_HANDLE_EOF
    case 0xC0000034u: r=2; break;     // OBJECT_NAME_NOT_FOUND -> FILE_NOT_FOUND
    case 0xC0000008u: r=6; break;     // INVALID_HANDLE
    case 0xC000000Du: r=87; break;    // INVALID_PARAMETER
    default: r=((s>>16)==0xC001u)?(s&0xFFFFu):317; break; // ERROR_MR_MID_NOT_FOUND
  }
  static long n=0; if(n++<12) std::fprintf(stderr,"  [nt2dos] 0x%X -> %u\n",s,r);
  ctx.r3.u64=r;(void)base;}
PPC_FUNC_IMPL(__imp__RtlRaiseException){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlRaiseException\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__RtlTimeFieldsToTime){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlTimeFieldsToTime\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
// ★ CODE_REVIEW_0804 D17: was "return 0, write nothing" — the TIME_FIELDS out-struct (save
// timestamps / date display) read back as stale guest memory. Real conversion now: r3 =
// PLARGE_INTEGER (BE FILETIME, 100ns since 1601), r4 = PTIME_FIELDS (8 BE int16: Y,M,D,H,Min,S,ms,Weekday).
PPC_FUNC_IMPL(__imp__RtlTimeToTimeFields){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlTimeToTimeFields (real conversion)\n");}g_import_calls++;
  uint32_t tp=ctx.r3.u32, fp=ctx.r4.u32;
  if(tp&&fp){
    uint64_t t=__builtin_bswap64(*(uint64_t*)(base+tp));
    uint64_t days=t/864000000000ull, rem=t%864000000000ull;
    uint32_t ms=(uint32_t)((rem/10000ull)%1000ull), sec=(uint32_t)((rem/10000000ull)%60ull),
             min=(uint32_t)((rem/600000000ull)%60ull), hr=(uint32_t)(rem/36000000000ull);
    uint32_t wd=(uint32_t)((days+1)%7);                       // 1601-01-01 was a Monday
    uint32_t y=1601; for(;;){ uint32_t dy=((y%4==0&&y%100!=0)||y%400==0)?366u:365u; if(days<dy)break; days-=dy; ++y; }
    static const uint32_t mdn[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    uint32_t mo=0; bool leap=((y%4==0&&y%100!=0)||y%400==0);
    for(;mo<12;++mo){ uint32_t dm=mdn[mo]+((mo==1&&leap)?1u:0u); if(days<dm)break; days-=dm; }
    auto w16=[&](uint32_t off,uint32_t v){ *(uint16_t*)(base+fp+off)=__builtin_bswap16((uint16_t)v); };
    w16(0,y); w16(2,mo+1); w16(4,(uint32_t)days+1); w16(6,hr); w16(8,min); w16(10,sec); w16(12,ms); w16(14,wd);
  }
  ctx.r3.u64=0;}
PPC_FUNC_IMPL(__imp__VdShutdownEngines){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdShutdownEngines\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp____C_specific_handler){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp____C_specific_handler\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp___vsnprintf){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp___vsnprintf\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__sprintf){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__sprintf\n");}g_import_calls++;ctx.r3.u64=0;(void)base;}
