#include "ppc_recomp_shared.h"
#include <cstdio>
#ifndef _WIN32
#include <execinfo.h>
#endif
#include <atomic>
#include <mutex>
#include <deque>
#include <vector>
#include <cstring>
#include <algorithm>   // std::sort (POSIX libstdc++ does not pull it in transitively)
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
// ---- end guest .data parameterization ----
std::atomic<long> g_import_calls{0};
extern "C" uint32_t g_xaudio_cb=0, g_xaudio_cb_ctx=0;
extern "C" void rt_audio_submit(uint8_t* base, uint32_t samples_ptr); // rt_audio.cpp sink
#include <cstdlib>
extern "C" void rt_impcall(const char* n){ static bool t=getenv("RT_TRACEIMP")!=nullptr; if(t) std::fprintf(stderr,"  [imp] %s\n",n); }
extern "C" void __imp__NtSetEvent(PPCContext& __restrict, uint8_t*);
// ★ ExGetXConfigSetting(category, setting, buffer, size, &required) — SYSTEM CONFIG.
// Flagged by the 2026-08-02 stub audit as one of the remaining "return SUCCESS, write nothing"
// imports the guest actually calls, i.e. the same shape as the XMP bug that muted all music.
// ⚠ 2026-08-02 RETRACTED AS AN AUDIO SUSPECT. I flagged this as the prime cause of "SFX sound
// off" on the theory that the XConfig USER category carries AUDIO_FLAGS (speaker mode / Dolby) and
// that garbage there would pick a wrong downmix. A call-site sweep killed it: all 19 sites pass
// their setting id as an `li` immediate and NOT ONE requests 0x0B (AUDIO_FLAGS) — the guest only
// ever asks this for video/timezone-class settings. The write-nothing gap is real and worth
// closing eventually, but it cannot affect audio, and no audio finding may cite it.
// RT_XCFGTRACE stays: it logs what is actually asked for, so the remaining (video) gap can be
// closed from evidence rather than by inventing values for settings the guest never queries.
PPC_FUNC_IMPL(__imp__ExGetXConfigSetting){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__ExGetXConfigSetting\n");}g_import_calls++;rt_impcall(__func__);
  if(std::getenv("RT_XCFGTRACE")){
    static std::atomic<long> n{0}; long k=n.fetch_add(1)+1;
    if(k<=64) std::fprintf(stderr,"[xcfg] #%ld category=0x%X setting=0x%X buf=0x%X size=%u req=0x%X lr=0x%X\n",
                           k,ctx.r3.u32,ctx.r4.u32,ctx.r5.u32,ctx.r6.u32,ctx.r7.u32,(uint32_t)ctx.lr);
  }
  ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__ExRegisterTitleTerminateNotification){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__ExRegisterTitleTerminateNotification\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__ExTerminateThread){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__ExTerminateThread\n");}g_import_calls++;rt_impcall(__func__);std::fprintf(stderr,"  [thread] TERMINATE via ExTerminateThread r3=0x%X\n",(unsigned)ctx.r3.u32);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__HalReturnToFirmware){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__HalReturnToFirmware\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeAcquireSpinLockAtRaisedIrql){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeAcquireSpinLockAtRaisedIrql\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeBugCheck){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeBugCheck\n");}g_import_calls++;rt_impcall(__func__);std::fprintf(stderr,"  [KeBugCheck] code=0x%X r4=0x%X%c",(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,10);
#ifndef _WIN32
 void*bt[16];int nn=backtrace(bt,16);backtrace_symbols_fd(bt,nn,2);
#endif
 ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeBugCheckEx){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeBugCheckEx\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeEnterCriticalRegion){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeEnterCriticalRegion\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeInitializeDpc){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeInitializeDpc\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeLeaveCriticalRegion){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeLeaveCriticalRegion\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeLockL2){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeLockL2\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeQueryBasePriorityThread){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeQueryBasePriorityThread\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeReleaseSpinLockFromRaisedIrql){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeReleaseSpinLockFromRaisedIrql\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeSetAffinityThread){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeSetAffinityThread\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeSetBasePriorityThread){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeSetBasePriorityThread\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KeUnlockL2){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KeUnlockL2\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
// __imp__KeWaitForMultipleObjects moved to rt.cpp (real WaitAny on RtEvents; the return-0 stub
// starved the XAudio render callback's submit branch -> silent port)
PPC_FUNC_IMPL(__imp__KfAcquireSpinLock){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KfAcquireSpinLock\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KfReleaseSpinLock){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KfReleaseSpinLock\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__KiApcNormalRoutineNop){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__KiApcNormalRoutineNop\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__MmFreePhysicalMemory){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__MmFreePhysicalMemory\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__MmGetPhysicalAddress){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__MmGetPhysicalAddress\n");}g_import_calls++;rt_impcall(__func__);/* identity: guest VA == PA in our flat 4GB map */ (void)base;}
PPC_FUNC_IMPL(__imp__MmMapIoSpace){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__MmMapIoSpace\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__MmQueryAddressProtect){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__MmQueryAddressProtect\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NetDll_WSACleanup){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NetDll_WSACleanup\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NetDll_WSACloseEvent){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NetDll_WSACloseEvent\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NetDll_WSACreateEvent){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NetDll_WSACreateEvent\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NetDll_WSAResetEvent){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NetDll_WSAResetEvent\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NetDll_WSAStartup){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NetDll_WSAStartup\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NetDll_WSAWaitForMultipleEvents){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NetDll_WSAWaitForMultipleEvents\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NetDll_XNetCleanup){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NetDll_XNetCleanup\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NetDll_XNetGetEthernetLinkStatus){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NetDll_XNetGetEthernetLinkStatus\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NetDll_XNetQosRelease){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NetDll_XNetQosRelease\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NetDll_XNetQosServiceLookup){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NetDll_XNetQosServiceLookup\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NetDll_XNetStartup){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NetDll_XNetStartup\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtCreateFile){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtCreateFile\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtCreateSemaphore){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtCreateSemaphore\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtDuplicateObject){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtDuplicateObject\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtFlushBuffersFile){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtFlushBuffersFile\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtFreeVirtualMemory){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtFreeVirtualMemory\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtOpenFile){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtOpenFile\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtQueryDirectoryFile){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtQueryDirectoryFile\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtQueryFullAttributesFile){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtQueryFullAttributesFile\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtQueryInformationFile){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtQueryInformationFile\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtQueryVirtualMemory){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtQueryVirtualMemory\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtQueryVolumeInformationFile){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtQueryVolumeInformationFile\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtReadFile){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtReadFile\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtReadFileScatter){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtReadFileScatter\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtReleaseSemaphore){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtReleaseSemaphore\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtSetInformationFile){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtSetInformationFile\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtWaitForMultipleObjectsEx){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtWaitForMultipleObjectsEx\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__NtWriteFile){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__NtWriteFile\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__ObCreateSymbolicLink){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__ObCreateSymbolicLink\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__ObDeleteSymbolicLink){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__ObDeleteSymbolicLink\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__ObDereferenceObject){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__ObDereferenceObject\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__ObReferenceObjectByHandle){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__ObReferenceObjectByHandle\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__RtlCaptureContext){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlCaptureContext\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__RtlCompareMemoryUlong){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlCompareMemoryUlong\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__RtlFillMemoryUlong){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlFillMemoryUlong\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__RtlImageXexHeaderField){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlImageXexHeaderField\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__RtlMultiByteToUnicodeN){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlMultiByteToUnicodeN\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__RtlNtStatusToDosError){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlNtStatusToDosError\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__RtlRaiseException){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlRaiseException\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__RtlTimeFieldsToTime){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlTimeFieldsToTime\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__RtlTimeToTimeFields){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlTimeToTimeFields\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__RtlTryEnterCriticalSection){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlTryEnterCriticalSection\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__RtlUnicodeToMultiByteN){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlUnicodeToMultiByteN\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__RtlUnwind){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__RtlUnwind\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdCallGraphicsNotificationRoutines){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdCallGraphicsNotificationRoutines\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdEnableDisableClockGating){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdEnableDisableClockGating\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdGetCurrentDisplayGamma){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdGetCurrentDisplayGamma\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdGetCurrentDisplayInformation){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdGetCurrentDisplayInformation\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdGetSystemCommandBuffer){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdGetSystemCommandBuffer\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdInitializeEngines){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdInitializeEngines\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdInitializeScalerCommandBuffer){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdInitializeScalerCommandBuffer\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdIsHSIOTrainingSucceeded){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdIsHSIOTrainingSucceeded\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdPersistDisplay){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdPersistDisplay\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdQueryVideoFlags){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdQueryVideoFlags\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdQueryVideoMode){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdQueryVideoMode\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdRetrainEDRAM){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdRetrainEDRAM\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdRetrainEDRAMWorker){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdRetrainEDRAMWorker\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdSetDisplayMode){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdSetDisplayMode\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdSetSystemCommandBufferGpuIdentifierAddress){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdSetSystemCommandBufferGpuIdentifierAddress\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__VdShutdownEngines){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__VdShutdownEngines\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
// __imp__VdSwap moved to rt.cpp (frame capture instrumentation)
PPC_FUNC_IMPL(__imp__XAudioGetSpeakerConfig){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XAudioGetSpeakerConfig\n");}g_import_calls++;rt_impcall(__func__);PPC_STORE_U32(ctx.r3.u32,0x00010001u);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XAudioGetVoiceCategoryVolume){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XAudioGetVoiceCategoryVolume\n");}g_import_calls++;rt_impcall(__func__);PPC_STORE_U32(ctx.r4.u32,0x3F800000u);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XAudioRegisterRenderDriverClient){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XAudioRegisterRenderDriverClient\n");}g_import_calls++;rt_impcall(__func__);uint32_t cb=PPC_LOAD_U32(ctx.r3.u32);uint32_t cbarg=PPC_LOAD_U32(ctx.r3.u32+4);g_xaudio_cb=cb;g_xaudio_cb_ctx=cbarg;std::fprintf(stderr,"[xaudio] register cb=%08X ctx=%08X\n",cb,cbarg);PPC_STORE_U32(ctx.r4.u32,0x41550001u);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XAudioSubmitRenderDriverFrame){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XAudioSubmitRenderDriverFrame\n");}g_import_calls++;rt_impcall(__func__);/* r4 = mixed frame: 256 samples x 6ch f32 BE channel-major (SDK xboxkrnl_audio.cpp ABI) */rt_audio_submit(base,ctx.r4.u32);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XAudioUnregisterRenderDriverClient){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XAudioUnregisterRenderDriverClient\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XGetAVPack){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XGetAVPack\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XGetLanguage){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XGetLanguage\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XMACreateContext){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XMACreateContext\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XMAReleaseContext){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XMAReleaseContext\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XMsgCancelIORequest){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XMsgCancelIORequest\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
// ★ XMsgInProcessCall — XMP (custom soundtrack) STATUS. THE MUSIC ROOT CAUSE (2026-08-01).
// This was a bare "return SUCCESS, touch nothing" stub, and that single gap is why the port has
// never had guest-side music and why the whole host audio bridge exists.
//
// THE CHAIN, measured end to end:
//   FUN_82191640 (the shell's system-state monitor ctor, vtable 0x82051048) calls
//   FUN_8215a928(&this[0xb])                                  <- this+0x2c, the gate word
//     -> FUN_8215a878(2,&a,&b) builds a 3-dword block {2, &a, &b} and calls
//        XMsgInProcessCall(app=0xFA, msg=0x7001B, block, 0)   <- 0xFA is the XMP app id
//     -> the gate word is set to 1 ONLY IF BOTH out-words come back zero, i.e. only if no custom
//        soundtrack is playing. On a real 360 the user can play their own music over any title and
//        the title is REQUIRED to mute its own BGM while keeping SFX.
//   Then every frame, the audio tick FUN_821cac08 reads that gate word and, while it is 0, pushes
//   0.0 to every category the shell owns (BGM cat 3, SYS_BGM cat 6) and latches
//   DAT_821f857c[0x9d]=1 so it only does it once.
// Returning SUCCESS without writing the out-words left them as UNINITIALISED STACK, so the guest
// read garbage as "a soundtrack is playing", muted its music, and never un-muted. It also explains
// the long-standing SE-audible-but-music-silent asymmetry exactly: cats 4/5/7 are not in the
// shell's table and were never touched.
// Measured proof of causality before this fix: forcing the gate word to 1 (RT_MUTEPROBE, a probe,
// now removed) took the guest-only tap from p50 0.000000 to p50 0.057622 sustained — the guest
// rendering its own music for the first time in the project.
//
// WHAT WE DO NOW: answer the query truthfully for a machine with no custom soundtrack — write 0 to
// both out-words and return success. That is the hardware default state, and it is a kernel API
// being implemented, not an audio behaviour being emulated. Scoped hard to (app 0xFA, msg 0x7001B,
// block[0]==2); every other XMsg call keeps the old do-nothing behaviour.
// Lever: RT_XMP=0 restores the old stub exactly (the revert arm for any regression).
PPC_FUNC_IMPL(__imp__XMsgInProcessCall){
  static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XMsgInProcessCall\n");}
  g_import_calls++;rt_impcall(__func__);
  static const bool xmp = [](){ const char* e=std::getenv("RT_XMP"); return !(e && e[0]=='0' && !e[1]); }();
  const uint32_t app=ctx.r3.u32, msg=ctx.r4.u32, blk=ctx.r5.u32;
  if(xmp && app==0xFAu && msg==0x7001Bu && blk && blk<0xF0000000u){
    uint32_t sub=PPC_LOAD_U32(blk), pa=PPC_LOAD_U32(blk+4u), pb=PPC_LOAD_U32(blk+8u);
    if(sub==2u){
      if(pa && pa<0xF0000000u) PPC_STORE_U32(pa,0u);   // no soundtrack playing
      if(pb && pb<0xF0000000u) PPC_STORE_U32(pb,0u);   // no override behaviour
      static bool once=false;
      if(!once){ once=true; std::fprintf(stderr,"  [xmp] GetStatus(app=0xFA msg=0x7001B sub=2) -> not playing (a@0x%X b@0x%X); RT_XMP=0 reverts\n",pa,pb); }
    }
  }
  ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XMsgStartIORequest){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XMsgStartIORequest\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XNetLogonGetTitleID){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XNetLogonGetTitleID\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
// __imp__XNotifyGetNext moved to rt.cpp (notification listener model)
PPC_FUNC_IMPL(__imp__XNotifyPositionUI){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XNotifyPositionUI\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XamAlloc){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamAlloc\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XamBackgroundDownloadSetMode){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamBackgroundDownloadSetMode\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
// ================= save-data subsystem (RT_SAVE) =================
// Host-directory-backed XAM content implementation. Default-off: when RT_SAVE is unset every
// function below falls straight through to the ORIGINAL stub behavior (checked first thing in
// each function), so a build without RT_SAVE set is byte-identical to before this subsystem
// existed. See SAVE_DESIGN.md for the full design; this is the implementation of that design
// plus ground truth from a real SDK-build save capture (reference_screenshots/sdk/sdk_savedlg_*):
// the real container layout is Documents\futari\<xuid>\435A07D7\<content_type8hex>\<file_name>\...
// with file_name="systemdata.bin" (savegame) / "replaydata.bin" (post-game replay). We don't need
// to reproduce that exact host layout bit-for-bit (the game never sees host paths, only guest
// paths relative to whatever root_name it mounted) — the game's own I/O writes/reads the actual
// container bytes; our job is just real mount/enumerate/write plumbing.
#include <set>
#include <map>
#include <string>
#include <filesystem>
#include <cctype>
namespace rt_savefs = std::filesystem;
static bool rt_save_on(){ static bool on=[]{ const char* e=getenv("RT_SAVE"); return e&&*e; }(); return on; }
static std::string rt_save_dir(){ static std::string d=[]{ const char* e=getenv("RT_SAVE"); return std::string((e&&*e)?e:"save"); }(); return d; }
// Implemented in out_reco/rt.cpp (owns the NT file layer + the root_name->host-dir map that
// rt_open_host()/rt_create_common() consult for every NtCreateFile/NtOpenFile call).
extern "C" void rt_content_register_root(const char* root_name, const char* host_dir);
extern "C" void rt_content_register_root_ro(const char* root_name, const char* host_dir);   // DLC data: read-only mount (rt.cpp)
extern "C" void rt_content_unregister_root(const char* root_name);
// open device sessions (device ids currently valid per SAVE_DESIGN.md §4). Populated by
// XamShowDeviceSelectorUI / XamContentCreateEx success, erased by XamContentClose — this is what
// lets XamContentGetDeviceData distinguish an open session from a stale/closed one (§2's fix).
static std::mutex g_devm; static std::set<uint32_t> g_devopen;
// per-open-content-session bookkeeping keyed by the (uppercased) root_name the game mounted
// under — XamContentClose's real ABI takes root_name (not a handle), so this is how it finds
// what to release.
struct RtContentSession{ uint32_t device_id; bool is_save; };
static std::mutex g_sessm; static std::map<std::string,RtContentSession> g_sessions;
static std::string rt_upper(const char* s){ std::string r(s?s:""); for(auto& c:r) c=(char)std::toupper((unsigned char)c); return r; }
// Scan <RT_SAVE>/435A07D7/00000001/ for existing save package directories (each subdir = a
// content item created by a prior CreateEx). Collects ALL of them.
// ★ 2026-08-01 (settings audit B1): this used to return only the FIRST directory, and
// XamEnumerate served only that one record. Replay Data Saving defaults ON, so as soon as a
// replay is written the tree holds BOTH replaydata.bin/ and systemdata.bin/ — and 'r' sorts
// before 's'. The guest's name-match walk (FUN_82194438) then exhausted without ever seeing
// systemdata.bin, its settings LOAD failed, and EVERY option silently reverted to factory
// defaults on the next boot. Real XAM enumerates every item; so do we now. Ordering is not
// relied upon (we serve all of them), but sort for run-to-run determinism.
// Reference contract: rexglue-sdk/src/kernel/xam/xam_content.cpp ListContent appends every item.
static bool rt_save_scan(std::vector<std::string>& file_names_out){
  file_names_out.clear();
  if(!rt_save_on()) return false;
  rt_savefs::path root = rt_savefs::path(rt_save_dir())/"435A07D7"/"00000001";
  std::error_code ec;
  if(!rt_savefs::exists(root,ec) || ec) return false;
  for(auto& e: rt_savefs::directory_iterator(root,ec)){
    if(ec) break;
    if(e.is_directory()) file_names_out.push_back(e.path().filename().string());
  }
  std::sort(file_names_out.begin(), file_names_out.end());
  return !file_names_out.empty();
}
// (root_name r3, overlapped r4). Real XAM ABI (rexglue xam_content.cpp XamContentClose_entry):
// closes a mount by root_name, NOT a handle. Releases the session + (if it was the SAVE mount)
// erases its device_id from the open-set, which is the trigger that lets §2's game-select poll
// succeed instead of free-spinning forever.
PPC_FUNC_IMPL(__imp__XamContentClose){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamContentClose\n");}g_import_calls++;rt_impcall(__func__);
  if(!rt_save_on()){ ctx.r3.u64=0;(void)base; return; }   // preserve exact old behavior when off
  uint32_t rnp=ctx.r3.u32, ov=ctx.r4.u32;
  char root_name[64]={0};
  if(rnp && rnp<0xF0000000u){ const char* s=(const char*)(base+rnp); size_t i=0; for(;i<63&&s[i];++i) root_name[i]=s[i]; }
  if(root_name[0]){
    std::string key=rt_upper(root_name);
    uint32_t dev_to_close=0; bool was_save=false, found=false;
    { std::lock_guard<std::mutex> l(g_sessm); auto it=g_sessions.find(key);
      if(it!=g_sessions.end()){ dev_to_close=it->second.device_id; was_save=it->second.is_save; found=true; g_sessions.erase(it); } }
    if(was_save){ std::lock_guard<std::mutex> l(g_devm); g_devopen.erase(dev_to_close?dev_to_close:1u); }
    rt_content_unregister_root(root_name);
    std::fprintf(stderr,"[content] Close root='%s' found=%d was_save=%d dev=%u\n",root_name,(int)found,(int)was_save,dev_to_close);
  }
  if(ov){
    PPC_STORE_U32(ov+0x00,0); PPC_STORE_U32(ov+0x04,0); PPC_STORE_U32(ov+0x18,0);
    uint32_t ev=PPC_LOAD_U32(ov+0x0C); if(ev){ PPCContext k{}; k.r3.u64=ev; __imp__NtSetEvent(k,base); }
    ctx.r3.u64=997; (void)base; return;
  }
  ctx.r3.u64=0;(void)base;}
// ---- DLC content enumeration (Black Label + Ver1.01) ----
// The TOP MENU greys Black Label / Ver1.01 until it sees them owned via a TYPE-2 (marketplace)
// content enumeration. Present both with their JP display-names + content-id file_names (from the
// SDK's registered .header files) so the menu un-greys them. XCONTENT_DATA (0x134): device_id@0,
// content_type@4, display_name(utf16-BE,128)@8, file_name(42)@0x108.
static const uint16_t g_dlc_bl_name[]   = {0x866B,0x59EB,0x3055,0x307E,0x3075,0x305F,0x308A,0x3000,0x30D6,0x30E9,0x30C3,0x30AF,0x30EC,0x30FC,0x30D9,0x30EB}; // 虫姫さまふたり　ブラックレーベル
static const uint16_t g_dlc_v101_name[] = {0x866B,0x59EB,0x3055,0x307E,0x3075,0x305F,0x308A,0x3000,0x0056,0x0065,0x0072,0x0031,0x002E,0x0030,0x0031};        // 虫姫さまふたり　Ver1.01
static const struct DlcEntry { const char* file_name; const uint16_t* name; int name_len; const char* req[2]; } g_dlc[] = {
  {"496F816DD4B53DAEFF931838B6C69831AAD7663043", g_dlc_bl_name,   16, {"media/Rom/cg_black.bin", "media/Rom/cg_blackhi.bin"}},
  {"9893A78CA6062B935BD1F53EA43CFD546B7246DF43", g_dlc_v101_name, 15, {"media/Rom/cg_v102.bin",  "media/Rom/cg_v102hi.bin"}},
};
static const int g_ndlc = 2;
// 2026-08-13 Day-4 (user-supplied dumps): a DLC entry is served ONLY if its data files exist
// under the asset root. Unconditionally answering "owned" un-greys Black Label even when the
// dump has no DLC — crash-on-select the moment assets are user-extracted (tools/extract/).
// Ver1.01's archives are DISC-sourced, so it stays owned on any full dump. Black Label also
// ships Rom/dropprm.bl; the two cg archives are the load-bearing check. RT_DLCFORCE=1 restores
// the old unconditional behaviour (revert arm).
// The player's DLC folder (second root; see rt_dlc_owned). RT_DLC_ROOT wins; otherwise "<RT_SAVE>/../dlc" when a save
// dir is set (the bundle puts saves in ~/Library/Application Support/Futari Realcomp/save, so the DLC goes beside them
// in .../Futari Realcomp/dlc); otherwise "dlc" in the cwd (the developer shape).
static const char* rt_dlc_root(){
  static std::string d=[]{
    const char* e=std::getenv("RT_DLC_ROOT"); if(e&&*e) return std::string(e);
    const char* s=std::getenv("RT_SAVE");
    if(s&&*s){ std::string p(s); while(p.size()>1 && (p.back()=='/'||p.back()=='\\')) p.pop_back();
      size_t k=p.find_last_of("/\\"); return (k==std::string::npos? std::string(".") : p.substr(0,k)) + "/dlc"; }
    return std::string("dlc");
  }();
  return d.c_str();
}
static std::string g_dlc_dir[8];   // the root rt_dlc_owned found entry ci in ("" = forced / not found)
static bool rt_dlc_owned(int ci){
  static int owned[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
  if(owned[ci]<0){
    const char* e=std::getenv("RT_DLCFORCE");
    if(e && e[0]=='1' && !e[1]){ owned[ci]=1; }
    else {
      // 2026-10-31 (Black Label data-path decision): the DLC's files may live in a SECOND root, the player's DLC
      // folder (RT_DLC_ROOT, default <save dir>/../dlc -- beside the saves, outside the app bundle / assets tree),
      // laid out exactly as tools/extract writes it (<root>/media/Rom/cg_black.bin ...). It is searched FIRST; the
      // game root second (a developer's private root). The first root that has EVERY required file wins and is the
      // one the type-2 mount below maps "<dlcroot>:\" onto. Nothing is ever copied into assets/.
      owned[ci]=0;
      const char* roots[2]={ rt_dlc_root(), nullptr };
      { const char* groot=std::getenv("RT_GAME_ROOT"); if(!groot||!*groot) groot="assets"; roots[1]=groot; }
      for(int r=0; r<2 && !owned[ci]; ++r){
        if(!roots[r]||!*roots[r]) continue;
        bool all=true;
        for(int f=0; f<2 && g_dlc[ci].req[f]; ++f){
          char p[1024]; std::snprintf(p,sizeof p,"%s/%s",roots[r],g_dlc[ci].req[f]);
          FILE* fp=std::fopen(p,"rb"); if(!fp){ all=false; break; } std::fclose(fp);
        }
        if(all){ owned[ci]=1; g_dlc_dir[ci]=roots[r]; }
      }
    }
    std::fprintf(stderr,"[xenum] DLC gate: entry %d ('%.8s...') -> %s%s%s\n",ci,g_dlc[ci].file_name,
                 owned[ci] ? "OWNED (data present" : "MISSING (stays grey; RT_DLCFORCE=1 overrides; looked in RT_DLC_ROOT '",
                 owned[ci] ? (g_dlc_dir[ci].empty()? ", forced)" : (" in " + g_dlc_dir[ci] + ")").c_str()) : rt_dlc_root(),
                 owned[ci] ? "" : "' and the game root)");
  }
  return owned[ci]==1;
}
// per-enumerator content_type + consumed-item count, indexed by (handle>>2)&0x3FF
static uint32_t g_enumType[1024];
static int      g_enumConsumed[1024];
static bool     g_enumHasSave[1024];   // RT_SAVE: type==1 enumerator found an existing save on host
static std::vector<std::string> g_enumSaveFiles[1024];   // ALL save packages found (see rt_save_scan)

// rexglue parity (xam_content.cpp:64): (user r3, device r4, ctype r5, cflags r6,
// items_per r7, buffer_size_ptr r8, handle_out r9). Empty-content enumerator: write a
// real handle + buffer size (items * 0x308 = sizeof XCONTENT_DATA), return 0.
PPC_FUNC_IMPL(__imp__XamContentCreateEnumerator){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamContentCreateEnumerator\n");}g_import_calls++;rt_impcall(__func__);
  uint32_t items=ctx.r7.u32, szp=ctx.r8.u32, hp=ctx.r9.u32;
  static uint32_t next=0xE1000000u;
  if(szp) PPC_STORE_U32(szp, (items?items:1)*0x308u);
  if(hp){
    PPC_STORE_U32(hp,next); uint32_t ei=(next>>2)&0x3FF; g_enumType[ei]=ctx.r5.u32; g_enumConsumed[ei]=0;
    g_enumHasSave[ei]=false;
    // RT_SAVE: for a type-1 (SAVEGAME) enumerator, check whether a real save package already
    // exists on host (2nd+ boot) so XamEnumerate below can report it instead of "0 items".
    if(ctx.r5.u32==1 && rt_save_on()){
      g_enumHasSave[ei]=rt_save_scan(g_enumSaveFiles[ei]);
    }
    std::fprintf(stderr,"[xenum] content enumerator -> h=0x%X (dev=%u type=0x%X items=%u save=%d pkgs=%zu)\n",
                 next,ctx.r4.u32,ctx.r5.u32,items,(int)g_enumHasSave[ei],g_enumSaveFiles[ei].size());
    next+=4;
  }
  ctx.r3.u64=0;(void)base;}
// (user r3, root_name r4, content_data r5, flags r6, disposition_ptr r7, license_mask_ptr r8,
// cache r9, content_size r10, overlapped [stack arg9]). The DLC-ownership task (sub_82192A00)
// mounts the matched package and sets the card's OWNED flag ONLY if this returns 997
// (ERROR_IO_PENDING) with a completed overlapped; a bare 0 -> error path -> card stays greyed.
PPC_FUNC_IMPL(__imp__XamContentCreateEx){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamContentCreateEx\n");}g_import_calls++;rt_impcall(__func__);
  uint32_t rnp=ctx.r4.u32, cdp=ctx.r5.u32, flags=ctx.r6.u32, dispp=ctx.r7.u32, licp=ctx.r8.u32;
  uint32_t ctype = cdp ? PPC_LOAD_U32(cdp+0x04) : 0;
  // TYPE-2 (marketplace/DLC) mount ONLY: the DLC-ownership task (sub_82192A00) sets the card's
  // OWNED flag (object+108=1) iff this returns 997 (ERROR_IO_PENDING) + a completed overlapped.
  // The SAVE (type-1) mount MUST stay the plain sync success (return 0) or the pre-menu save
  // flow loops and the menu never displays.
  if(ctype==2){
    uint32_t ov = PPC_LOAD_U32(ctx.r1.u32 + 0x54);   // overlapped = stack arg9
    if(dispp) PPC_STORE_U32(dispp, 2u);              // XCONTENT_DISPOSITION = OPENED
    if(licp)  PPC_STORE_U32(licp, 1u);               // license mask = 1 (owned)
    // Black Label step 3 (2026-10-31): the mount is REAL now. The shell names the DLC root ("bldata" for Black
    // Label) and then opens "bldata:\Rom\cg_black.bin" (seen on the first kiniro boot: `[file] open
    // "bldata:\Rom\cg_black.bin" ... -> MISS` and the shell's "DLC cannot be read, download again" dialog).
    // tools/extract relocates a package's Rom/ under <asset root>/media/Rom/, so the root maps READ-ONLY onto
    // <RT_GAME_ROOT>/media (rt.cpp rt_content_register_root_ro). Byte-inert for the reco pair: nothing ever
    // opens a "<dlcroot>:\" path there. The DLC files themselves never live in assets/ (bundle law): the
    // step-3 drives point RT_GAME_ROOT at a private root.
    {
      char root_name[64]={0};
      if(rnp && rnp<0xF0000000u){ const char* s=(const char*)(base+rnp); size_t i=0; for(;i<63&&s[i];++i) root_name[i]=s[i]; }
      if(root_name[0]){
        // Which root holds this package's files: the one rt_dlc_owned found (RT_DLC_ROOT first, then the game root);
        // with RT_DLCFORCE or an unknown root name, fall back to the game root (the old behaviour).
        const char* groot=std::getenv("RT_GAME_ROOT"); if(!groot||!*groot) groot="assets";   // mirrors rt_game_root()
        const char* dir=groot;
        for(int ci=0; ci<g_ndlc; ++ci) if(rt_dlc_owned(ci) && !g_dlc_dir[ci].empty()){
          // match the package by its content-id file_name when the shell passes it in XCONTENT_DATA (cdp+0x108)
          char fn[43]={0}; if(cdp){ for(int i=0;i<42;++i){ uint8_t b=PPC_LOAD_U8(cdp+0x108+i); if(!b) break; fn[i]=(char)b; } }
          if(!fn[0] || !std::strncmp(fn,g_dlc[ci].file_name,42)){ dir=g_dlc_dir[ci].c_str(); break; }
        }
        char hostdir[1100]; std::snprintf(hostdir,sizeof hostdir,"%s/media",dir);
        rt_content_register_root_ro(root_name, hostdir);
      }
    }
    static int n=0; if(n++<8) std::fprintf(stderr,"[content] DLC CreateEx (type2) ov=0x%X -> 997+complete (OWNED)\n",ov);
    if(ov>0x1000 && ov<0xFFFF0000){
      PPC_STORE_U32(ov+0x00,0); PPC_STORE_U32(ov+0x04,0); PPC_STORE_U32(ov+0x18,0);
      uint32_t ev=PPC_LOAD_U32(ov+0x0C); if(ev){ PPCContext k{}; k.r3.u64=ev; __imp__NtSetEvent(k,base); }
    }
    ctx.r3.u64=997; (void)base; return;
  }
  // TYPE-1 (SAVEGAME) real mount, RT_SAVE only. MUST stay sync (no overlapped) — see comment
  // above; that constraint is unrelated to RT_SAVE and is preserved here too.
  if(ctype==1 && rt_save_on()){
    char root_name[64]={0};
    if(rnp && rnp<0xF0000000u){ const char* s=(const char*)(base+rnp); size_t i=0; for(;i<63&&s[i];++i) root_name[i]=s[i]; }
    char file_name[43]={0};
    if(cdp){ for(int i=0;i<42;++i){ uint8_t b=PPC_LOAD_U8(cdp+0x108+i); if(!b) break; file_name[i]=(char)b; } }
    if(!file_name[0]) std::snprintf(file_name,sizeof file_name,"systemdata.bin"); // SDK-capture ground truth default
    uint32_t device_id = cdp? PPC_LOAD_U32(cdp+0):1u; if(!device_id) device_id=1u;
    rt_savefs::path hostdir = rt_savefs::path(rt_save_dir())/"435A07D7"/"00000001"/file_name;
    std::error_code ec; bool existed = rt_savefs::exists(hostdir,ec) && !ec;
    // Standard XAM disposition-request semantics (flags&0xF): 1=CREATE_NEW(fail if exists),
    // 2=CREATE_ALWAYS, 3=OPEN_EXISTING(fail if missing), 4=OPEN_ALWAYS(create if needed),
    // 5=TRUNCATE_EXISTING. Best-effort mirror of rexglue xam_content.cpp xeXamContentCreate.
    uint32_t df = flags & 0xFu;
    bool ok = !(df==1 && existed) && !((df==3||df==5) && !existed);
    uint32_t out_disp = 0;
    if(ok){
      std::error_code mkec; rt_savefs::create_directories(hostdir,mkec);
      out_disp = existed? 2u/*OPENED*/ : 1u/*CREATED*/;
      rt_content_register_root(root_name[0]?root_name:"SAVEDATA", hostdir.string().c_str());
      { std::lock_guard<std::mutex> l(g_devm); g_devopen.insert(device_id); }
      { std::lock_guard<std::mutex> l(g_sessm); g_sessions[rt_upper(root_name[0]?root_name:"SAVEDATA")]={device_id,true}; }
    }
    if(dispp) PPC_STORE_U32(dispp, out_disp);
    if(licp)  PPC_STORE_U32(licp, 1u);
    // 2026-07-12 (save-write proof task diagnostic): dump the args SAVE_DESIGN.md flagged as
    // "unconfirmed" (cache r9 / content_size r10 / overlapped stack-arg9 @ r1+0x54) plus the
    // first bytes of content_data (cdp), so a stuck/failed post-gameplay "save replay" flow
    // (which never reaches NtCreateFile at all -- confirmed via zero content=1 [file] lines)
    // can be diagnosed without guessing. Capped so boot-time polling doesn't spam the log.
    uint32_t ov=PPC_LOAD_U32(ctx.r1.u32+0x54);   // overlapped = stack arg9 (same slot as type-2's)
    {
      uint32_t cache=ctx.r9.u32, csize=ctx.r10.u32;
      static int cn=0; if(cn++<60){
        std::fprintf(stderr,"[content] SAVE CreateEx#%d args: cache(r9)=0x%X content_size(r10)=0x%X overlapped=0x%X\n",
          cn,cache,csize,ov);
        if(cdp){
          std::fprintf(stderr,"[content] content_data[0..0x20)=");
          for(int i=0;i<0x20;i+=4) std::fprintf(stderr," %08X",PPC_LOAD_U32(cdp+i));
          std::fprintf(stderr,"\n");
        }
      }
    }
    std::fprintf(stderr,"[content] SAVE CreateEx root='%s' file='%s' flags=0x%X dev=%u existed=%d -> disp=%u ok=%d ov=0x%X host='%s'\n",
      root_name,file_name,flags,device_id,(int)existed,out_disp,(int)ok,ov,hostdir.string().c_str());
    // 2026-07-12 FIX (save-write proof task): the pre-menu boot flow's SAVE CreateEx call
    // passes ov==0 and genuinely needs the old plain-sync-0 return (SAVE_DESIGN.md's warning
    // — going overlapped unconditionally loops the pre-menu flow). But the POST-GAMEPLAY
    // "save replay?" flow's SAVE CreateEx call (confirmed via diagnostic dump above) passes a
    // REAL nonzero overlapped every time and got a bare synchronous 0 back with the overlapped
    // left completely untouched -- the caller (which drives an "Accessing..." UI off that
    // overlapped, same pattern as the type-2 DLC branch above) never saw a valid pending/
    // completion state and gave up with "リプレイデータの保存に失敗しました" (replay data
    // save failed), confirmed via zero NtWriteFile/NtCreateFile calls ever reaching the save
    // mount in two full end-to-end runs. Fix: when ov is a real pointer, take the SAME
    // 997+immediate-complete path already used for type-2/XamContentClose/XamShowMessageBoxUIEx
    // in this file, instead of ignoring it.
    if(ok && ov>0x1000 && ov<0xFFFF0000u){
      PPC_STORE_U32(ov+0x00,0); PPC_STORE_U32(ov+0x04,0); PPC_STORE_U32(ov+0x18,0);
      uint32_t ev=PPC_LOAD_U32(ov+0x0C); if(ev){ PPCContext k{}; k.r3.u64=ev; __imp__NtSetEvent(k,base); }
      ctx.r3.u64=997; (void)base; return;
    }
    ctx.r3.u64 = ok?0:2u/*ERROR_FILE_NOT_FOUND*/; (void)base; return;
  }
  ctx.r3.u64=0;(void)base;}   // save (type-1) with RT_SAVE off, or any other type: plain sync success
PPC_FUNC_IMPL(__imp__XamContentGetCreator){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamContentGetCreator\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
// (device_id r3, device_data r4). The front-end reads this to validate the save device + its
// free space; a bare success with an UNWRITTEN buffer reads back garbage/zero free-space ->
// "invalid device" -> the shell re-shows the device selector (the pre-menu loop). Fill a real
// X_CONTENT_DEVICE_DATA {device_id@0, device_type@4, total_bytes@8 u64, free_bytes@0x10 u64,
// name@0x18 utf16} with a dummy HDD (20GB total / 3GB free), matching rexglue.
PPC_FUNC_IMPL(__imp__XamContentGetDeviceData){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamContentGetDeviceData\n");}g_import_calls++;rt_impcall(__func__);
  uint32_t dev=ctx.r3.u32, dd=ctx.r4.u32;
  // 2026-07-23 SAVE-WRITE ROOT-CAUSE FIX (workflow wf_68db01d7-067, live-log-proven):
  // GetDeviceData must track DEVICE CONNECTIVITY, not content-container lifetime. The old §2
  // shape failed dev-1 whenever the save container was closed — but the boot-time save READ
  // closes its container, so from :1054 on every GetDeviceData(1) returned 0x48F, the guest's
  // validity checkers zeroed the cached device id at storage-state+0x34, and every later save
  // attempt died at FUN_82187820's +0x34!=0 precheck BEFORE any file call (the "settings never
  // write" defect). Real XAM: closing a container does NOT disconnect the HDD.
  // New semantics: device 1 (the HDD) stays CONNECTED for the whole session once the save
  // system is on; only device 0 / unknown ids fail. ⚠ The §2 game-select release-latch
  // (FUN_82191a28, latches on GetDeviceData FAILURE — merged_xex [gsel]) may have depended on
  // the old failure; caller-LR logged below to discriminate, and the acceptance run's card
  // DECIDE exercises that path (a starved latch = boot hangs pre-ROM, immediately visible).
  if(rt_save_on()){
    uint32_t d = dev ? dev : 1u;
    if(d != 1u){
      bool open; { std::lock_guard<std::mutex> l(g_devm); open = g_devopen.count(d)!=0; }
      if(!open){ std::fprintf(stderr,"[devdata] device %u -> CLOSED/STALE -> 0x48F (lr=0x%X)\n",dev,(uint32_t)ctx.lr); ctx.r3.u64=0x48F; (void)base; return; }
    }
  }
  if(dd){
    for(int i=0;i<0x50;i++) PPC_STORE_U8(dd+i,0);
    PPC_STORE_U32(dd+0x00, dev?dev:1u);   // device_id (HDD=1)
    PPC_STORE_U32(dd+0x04, 1u);           // device_type = HDD
    PPC_STORE_U32(dd+0x08, 5u); PPC_STORE_U32(dd+0x0C, 0u);          // total_bytes = 0x500000000 (20GB)
    PPC_STORE_U32(dd+0x10, 0u); PPC_STORE_U32(dd+0x14, 0xC0000000u); // free_bytes  = 0xC0000000 (3GB)
    { const char* nm="Dummy HDD"; int i=0; for(; nm[i]; ++i) PPC_STORE_U16(dd+0x18+i*2,(uint16_t)(uint8_t)nm[i]); PPC_STORE_U16(dd+0x18+i*2,0); }
    // 2026-07-12 (save-write proof task diagnostic): was a static-once print (only the FIRST
    // ever call was visible in logs). Cap raised to 40 so repeat calls around the post-game
    // "save replay?" flow are visible too (need to confirm this keeps succeeding, not just
    // the boot-time call).
    static int dn=0; if(dn++<40) std::fprintf(stderr,"[devdata] device %u -> id=1 type=HDD total=20GB free=3GB (#%d lr=0x%X)\n",dev,dn,(uint32_t)ctx.lr);
  }
  ctx.r3.u64=0;(void)base;}
// rexglue parity (xam_enum.cpp:94): (handle r3, flags r4, buffer r5, buflen r6,
// items_returned r7, overlapped r8). Our enumerators are EMPTY: X_ERROR_NO_MORE_FILES
// (0x12); with an overlapped, complete it with 0x12 and return 997 (IO_PENDING).
PPC_FUNC_IMPL(__imp__XamEnumerate){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamEnumerate\n");}g_import_calls++;rt_impcall(__func__);
  uint32_t h=ctx.r3.u32, buf=ctx.r5.u32, itp=ctx.r7.u32, ov=ctx.r8.u32;
  // TYPE-2 (marketplace) enumerator: hand back the installed DLC packages so the TOP MENU
  // un-greys Black Label / Ver1.01. One item per call (Futari uses items_per=1), then SUCCESS+0.
  uint32_t ei=(h>>2)&0x3FF;
  if(g_enumType[ei]==2 && buf){
    int ci=g_enumConsumed[ei];
    while(ci<g_ndlc && !rt_dlc_owned(ci)) ++ci;   // Day-4 gate: skip entries with no data on host
    if(ci<g_ndlc){
      g_enumConsumed[ei]=ci+1;
      for(int i=0;i<0x308;i++) PPC_STORE_U8(buf+i,0);   // zero the FULL item slot (XCONTENT_AGGREGATE_DATA + pad)
      PPC_STORE_U32(buf+0x00,1u);   // device_id = HDD
      PPC_STORE_U32(buf+0x04,2u);   // content_type = marketplace
      for(int i=0;i<g_dlc[ci].name_len;i++) PPC_STORE_U16(buf+0x08+i*2,g_dlc[ci].name[i]);
      { int i=0; for(; g_dlc[ci].file_name[i] && i<42; ++i) PPC_STORE_U8(buf+0x108+i,(uint8_t)g_dlc[ci].file_name[i]); }
      // XCONTENT_AGGREGATE_DATA tail: xuid@0x134(u64)=0, title_id@0x13C(u32) — the game matches
      // packages by device_id/title_id/content_type/file_name, so set the running title id.
      PPC_STORE_U32(buf+0x13C, 0x435A07D7u); PPC_STORE_U32(buf+0x140, 0x435A07D7u);
      std::fprintf(stderr,"[xenum] enumerate h=0x%X -> DLC #%d (type-2, un-grey)\n",h,ci);
      if(itp) PPC_STORE_U32(itp,1);
      if(ov){
        PPC_STORE_U32(ov+0x00,0); PPC_STORE_U32(ov+0x04,1u); PPC_STORE_U32(ov+0x18,0); // InternalHigh = item count (1)
        uint32_t ev=PPC_LOAD_U32(ov+0x0C);
        if(ev){ PPCContext k{}; k.r3.u64=ev; __imp__NtSetEvent(k,base); }
        ctx.r3.u64=997; (void)base; return;
      }
      ctx.r3.u64=0; (void)base; return;
    }
  }
  // RT_SAVE: TYPE-1 (SAVEGAME) enumerator that found real save packages on host (rt_save_scan(),
  // see XamContentCreateEnumerator above) -- report ONE XCONTENT_DATA record PER CALL, for EVERY
  // package, then fall through to the SUCCESS+0-items terminator. A 2nd boot's save-check then
  // sees "save exists" instead of "0 items", and — critically — the guest's name-match walk gets
  // to see systemdata.bin even when replaydata.bin enumerates first (settings audit B1: serving
  // only the first package silently reverted every option to factory defaults once a replay
  // existed, because 'r' sorts before 's').
  if(g_enumType[ei]==1 && g_enumHasSave[ei] && buf){
    int ci=g_enumConsumed[ei];
    if(ci<(int)g_enumSaveFiles[ei].size()){
      g_enumConsumed[ei]=ci+1;
      for(int i=0;i<0x308;i++) PPC_STORE_U8(buf+i,0);
      PPC_STORE_U32(buf+0x00,1u);   // device_id = HDD
      PPC_STORE_U32(buf+0x04,1u);   // content_type = SAVEGAME
      { const char* nm="SAVEDATA"; int i=0; for(; nm[i]; ++i) PPC_STORE_U16(buf+0x08+i*2,(uint16_t)(uint8_t)nm[i]); }
      { const std::string& fn=g_enumSaveFiles[ei][ci]; size_t i=0; for(; i<fn.size()&&i<42; ++i) PPC_STORE_U8(buf+0x108+i,(uint8_t)fn[i]); }
      PPC_STORE_U32(buf+0x13C, 0x435A07D7u); PPC_STORE_U32(buf+0x140, 0x435A07D7u);
      std::fprintf(stderr,"[xenum] enumerate h=0x%X -> SAVEGAME '%s' (type-1, item %d of %zu)\n",
                   h,g_enumSaveFiles[ei][ci].c_str(),ci+1,g_enumSaveFiles[ei].size());
      if(itp) PPC_STORE_U32(itp,1);
      if(ov){
        PPC_STORE_U32(ov+0x00,0); PPC_STORE_U32(ov+0x04,1u); PPC_STORE_U32(ov+0x18,0);
        uint32_t ev=PPC_LOAD_U32(ov+0x0C);
        if(ev){ PPCContext k{}; k.r3.u64=ev; __imp__NtSetEvent(k,base); }
        ctx.r3.u64=997; (void)base; return;
      }
      ctx.r3.u64=0; (void)base; return;
    }
  }
  // ⚠ Futari treats NO_MORE_FILES(0x12) as a FATAL abort of its save-check and bounces back to
  // the device selector (= the observed pre-menu loop). It expects SUCCESS + 0 items as the
  // "no more entries, proceed" terminator (rexglue xam_enum.cpp remaps 0x12->SUCCESS for THIS
  // title by name). So return SUCCESS/0-items, not 0x12.
  std::fprintf(stderr,"[xenum] enumerate h=0x%X ov=0x%X -> SUCCESS 0 items\n",h,ov);
  if(itp) PPC_STORE_U32(itp,0);
  if(ov){
    PPC_STORE_U32(ov+0x00,0); PPC_STORE_U32(ov+0x04,0); PPC_STORE_U32(ov+0x18,0);
    uint32_t ev=PPC_LOAD_U32(ov+0x0C);
    if(ev){ PPCContext k{}; k.r3.u64=ev; __imp__NtSetEvent(k,base); }
    ctx.r3.u64=997; (void)base; return;
  }
  ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XamFree){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamFree\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XamGetExecutionId){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamGetExecutionId\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XamGetSystemVersion){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamGetSystemVersion\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
// ============ synthetic scripted input (RT_PAD) ============
// One shared timeline feeds BOTH the raw-pad path (XamInputGetState, 16B X_INPUT_STATE)
// and the buffered-keystroke path (XamInputGetKeystrokeEx, 8B X_INPUT_KEYSTROKE). The
// attract/title/menu uses one or the other depending on the screen, so we drive both.
// ⚠ Timeline is WALL-CLOCK based (steady_clock), NOT a per-call frame counter. Reason:
// XamInputGetState is called MANY times per real frame (4 users × several pollers), so a
// per-call counter desynced — different callers within one frame saw different buttons, and
// the caller that latches to the input record (sub_821905A0) almost never landed in a press
// window. Time-based => every caller in a given ms-window agrees. Buttons: START (advance
// title/attract), A (confirm). VK_PAD_A=0x5800, VK_PAD_START=0x5814.
#include <chrono>
static std::mutex g_syn_m;
static uint16_t g_syn_last=0;           // last button mask (edge detect)
static uint32_t g_syn_pkt=0;            // X_INPUT_STATE packet number
static std::deque<uint32_t> g_syn_ks;   // packed keystroke: vk<<16 | flags
static std::deque<std::chrono::steady_clock::time_point> g_syn_ts;  // push time per entry (stale-replay fix)
static std::chrono::steady_clock::time_point g_syn_t0;
static bool g_syn_init=false;
static uint16_t syn_pad_to_vk(uint16_t pad){
  switch(pad){ case 0x1000: return 0x5800; /*A*/ case 0x0010: return 0x5814; /*START*/
               case 0x2000: return 0x5801; /*B*/
               case 0x4000: return 0x5802; /*X*/ case 0x8000: return 0x5803; /*Y*/
               case 0x0001: return 0x5810; /*DPAD UP*/ case 0x0002: return 0x5811; /*DPAD DOWN*/
               case 0x0004: return 0x5812; /*DPAD LEFT*/ case 0x0008: return 0x5813; /*DPAD RIGHT*/
               case 0x0020: return 0x5815; /*BACK*/
               default: return 0; }
}
// Time-based schedule: let titles play ~4s, then pulse START 300ms every 2s, and A 300ms
// offset by 1s (in case a menu wants A). RT_PAD_HOLD/RT_PAD_WAIT tunable via env.
// LEG-39: quiet latch — set to 1 by the game side (merged_xex natplay, at the in-game-menu
// submit) to silence ALL synthetic pad output. The pulses' job (save dialogs, TOP MENU
// confirm) is done by then, and stray confirm-class bits (0x10/0x20/0x40 in the staged
// direction words) insta-kill the stage-intro fade overlay -> gameplay renders black.
std::atomic<int> g_syn_quiet{0};
// JOIN leg (2026-07-23): the arcade 1P-START line = game bit 0x8000 (host EXCH bit 0x08 via encoder
// FUN_8808e7d8). The shell input object's button remapper (cb3 FUN_821c5618 -> vtable[0x6c]) only
// produces the joystick/dpad host bits (0x10-0x80); it has NO producer for host-0x08, so no physical
// button ever reaches the game's 1P-START/JOIN line (confirmed: only D-pad reaches 0x88699894, and
// two decide-sweeps never saw game 0x8000). That is a genuine host mapping gap — the arcade cabinet
// wired a physical START button to that line. This atomic exports the START button LEVEL (P1) so the
// game-side encoder seam (merged_xex sub_8808F2C0, RT_STARTWIRE) can complete the wiring. Inert until
// RT_STARTWIRE consumes it; the value is always tracked (cheap, read-only).
std::atomic<int> g_rt_startline{0};
// G-START (RC1, 2026-10-12): the game-input FOCUS the real shell already enforces. cb3 FUN_821c5618
// (shell/gen/ppc_recomp.34.cpp:11603) hands the game its pad ONLY while *(inputctx+152)==0: with +152!=0
// it stores 0 instead of the remapped mask (loc 821C5664 -> li r3,0). The shell raises +152 when it takes
// the screen for itself (hub / hub submenus / pause; [cb2gate] INPUT-IGNORED right after the msg 15/11
// hub hand-over) -- so on hardware NO button reaches the game behind a shell menu. The STARTWIRE line above
// is a port-side wire that bypassed that gate (START leaked: the ARCADE module coined+advanced to mode
// select behind the OPTION submenu, user eyes 10-11). merged_shell.cpp's cb3 hook publishes the gate here
// every game frame; syn_sample drops the START line while it is closed. 1 = live (pre-first-cb3 default:
// identical to the old behaviour). RT_STARTWIRE_NOGATE=1 restores the ungated wire (A/B repro lever).
std::atomic<int> g_rt_gamefocus{1};
// DC-2 (RC1, 2026-10-12): the START line may only reach the game AFTER the shell has evaluated the same press.
// The shell's in-stage pause trigger (driver tick sub_821C69F0, loc 821C6D00..821C6DAC) reads user-0's processed EDGE
// word (rec+68 & 0x8) and opens PAUSE for player i only while the game's own status byte st[1+i] (0x887AD545 =
// "P1 at the CONTINUE countdown", written by the game's FUN_88137708) is still 0 and the player is active. Any input
// the real shell hands the game (cb3) is consumed by the game AFTER that tick, so at "CONTINUE?" the shell sees
// p1cont=1 (no pause) and the game continues. The port's START wire sampled the host button directly, so the game
// could take the continue (p1cont 1->0, player active again) one or two frames BEFORE the shell's tick saw the edge --
// which then found p1cont=0 and opened PAUSE on top of the continue (ARCADE 3/4 first presses, Q5 rc_chain item C).
// g_rt_startedge is latched by the driver-tick hook (merged_shell.cpp sub_821C69F0, after the guest body) when that
// tick has seen the START edge; syn_sample asserts the line only while START is held AND the latch is set; release
// clears it. RT_STARTWIRE_RAWLEVEL=1 restores the old host-level timing (A/B lever).
std::atomic<int> g_rt_startedge{0};
std::atomic<int> g_rt_startheld{0};   // START held && game focus (the line before the DC-2 ordering latch)
static uint16_t syn_buttons_now(){
  // Synthetic output requires explicit opt-in (2026-07-17 desktop-launch fix): without this, the
  // built-in fallback schedule below (START pulse every 2s + A offset 1s) fired on ANY run —
  // a bare keyboard session (RT_PAD_HOST only) auto-advanced menus and force-skipped the ROM
  // attract's legal notice. Scripted runs all set one of these envs already.
  static bool synOn = getenv("RT_PAD")||getenv("RT_NAV_SEQ")||getenv("RT_PAD_STARTONCE")||getenv("RT_PAD_NAV");
  if(!synOn) return 0;
  if(g_syn_quiet.load(std::memory_order_relaxed)) return 0;
  if(!g_syn_init){ g_syn_t0=std::chrono::steady_clock::now(); g_syn_init=true; }
  long ms=(long)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-g_syn_t0).count();
  static long wait=[]{ const char* e=getenv("RT_PAD_WAIT"); return e?atol(e):4000L; }();
  static long hold=[]{ const char* e=getenv("RT_PAD_HOLD"); return e?atol(e):300L; }();
  if(ms<wait) return 0;
  long t=ms-wait;
  // RT_NAV_SEQ (LEG-35): explicit timed input script, highest precedence. Comma-separated
  // events "<ms>:<BTN>[xN[@P]]" — BTN in {START,A,B,UP,DOWN}; N pulses (default 1) of
  // RT_PAD_HOLD ms starting at <ms> (relative to RT_PAD_WAIT), period P ms (default 1500).
  // e.g. RT_NAV_SEQ="0:START,2000:Ax20@1500,45000:DOWN,47000:A,50000:Ax8@2500" =
  // START once, A-pulse through save dialogs + TOP MENU confirm, then at the in-game menu
  // DOWN (SCORE ATTACK -> NORMAL PLAY), confirm, then confirm through the player/style
  // selects. Deterministic + tunable via env, no rebuild per timing tweak.
  struct NavEv{ long t; uint16_t btn; int n; long per; };
  static std::vector<NavEv> navSeq=[]{
    std::vector<NavEv> v; const char* e=getenv("RT_NAV_SEQ"); if(!e) return v;
    char buf[512]; std::snprintf(buf,sizeof buf,"%s",e);
    for(char* tok=strtok(buf,","); tok; tok=strtok(nullptr,",")){
      long tt=atol(tok); char* c=strchr(tok,':'); if(!c) continue; c++;
      uint16_t b=0;
      // RIGHT/LEFT added 2026-07-12 (save/options recipe: BG Wallpaper No. is adjusted with
      // dpad left/right). Checked before the single-letter A/B tests so "RIGHT"/"LEFT" don't
      // fall through (they don't start with 'A' or 'B' so order vs A/B doesn't matter, but
      // keep them grouped with the other multi-char names for clarity).
      if(!strncmp(c,"START",5)) b=0x0010; else if(!strncmp(c,"DOWN",4)) b=0x0002;
      else if(!strncmp(c,"RIGHT",5)) b=0x0008; else if(!strncmp(c,"LEFT",4)) b=0x0004;
      else if(!strncmp(c,"UP",2)) b=0x0001; else if(*c=='A') b=0x1000; else if(*c=='B') b=0x2000;
      if(!b) continue;
      int n=1; long per=1500;
      if(char* x=strchr(c,'x')){ n=atoi(x+1); if(char* p=strchr(x,'@')) per=atol(p+1); }
      v.push_back({tt,b,n<1?1:n,per<1?1500L:per});
      std::fprintf(stderr,"  [navseq] +%ldms %s x%d @%ldms\n",tt,
        b==0x10?"START":b==0x1000?"A":b==0x2000?"B":b==0x2?"DOWN":b==0x1?"UP":b==0x8?"RIGHT":b==0x4?"LEFT":"?",n,per);
    }
    return v; }();
  if(!navSeq.empty()){
    for(const auto& ev: navSeq){
      if(t<ev.t) continue;
      long dt=t-ev.t; long k=dt/ev.per;
      if(k<ev.n && (dt%ev.per)<hold) return ev.btn;
    }
    return 0;
  }
  // RT_PAD_STARTONCE=1: press START exactly once (title advance), then press A only, so the
  // per-frame confirm reaches the shell's create-save/confirm dialog WITHOUT a repeated START
  // re-triggering the device-selector each cycle (which resets the pre-menu save-check loop).
  static bool startOnce = getenv("RT_PAD_STARTONCE") != nullptr;
  if(startOnce){
    if(t<hold) return 0x0010;                          // START (once)
    long p=t%1500;
    if(p<hold) return 0x1000;                          // A repeatedly (answer dialogs)
    return 0;
  }
  // RT_PAD_NAV=1: prove TOP MENU interactivity — press START once (title->menu), then pulse
  // DPAD DOWN every ~3s to walk the cursor through the menu items. DOWN never confirms, so it
  // stays shell-side (no game-module load / asset-streaming stall). Each item shows different
  // card art + dialog, so a moving cursor is visible across sampled frames.
  static bool navMode = getenv("RT_PAD_NAV") != nullptr;
  if(navMode){
    // START once -> A pulses to answer the save-check dialogs and REACH the menu (same as
    // STARTONCE, proven) -> after RT_NAV_AFTER ms (default 50s, past menu build), switch to
    // DPAD DOWN pulses to walk the cursor. Tunable via env so timing needs no rebuild.
    static long navAfter=[]{ const char* e=getenv("RT_NAV_AFTER"); return e?atol(e):50000L; }();
    if(t<hold) return 0x0010;                          // START (once)
    if(t<navAfter){ long p=t%1500; return (p<hold)?0x1000:0; }  // A: answer dialogs -> menu
    long p=t%3000; return (p<hold)?0x0002:0;            // DPAD DOWN: navigate the menu
  }
  long p=t%2000;
  if(p<hold) return 0x0010;               // START
  if(p>=1000 && p<1000+hold) return 0x1000; // A
  return 0;
}
// ============ RT_PAD_HOST (LEG-42): host-keyboard -> guest pad bridge ============
// XQueryKeymap polling on $DISPLAY via dlopen(libX11.so.6) -- no new link deps, and
// XTEST-visible (xdotool keydown/keyup shows up in XQueryKeymap) so the bridge is
// self-testable without a human. A 4ms poller thread caches the mapped button word;
// XamInputGetState OR-merges it with the synthetic RT_PAD timeline. Host input
// deliberately BYPASSES the natplay g_syn_quiet fade-protection silencer (that latch
// exists to stop the SYNTHETIC pulse timeline from strobing confirm bits into the
// stage-intro fade; a human pressing keys is exactly what the joined run wants).
// Key map (logged at startup): arrows = D-pad + full-deflection left stick,
// Z=A(shot), X=B(bomb), C=X, V=Y, Enter=START, RightShift=BACK. Esc is NOT mapped.
#ifdef _WIN32
#include "win_compat.h"
#else
#include <dlfcn.h>
// SDL-window arm (macOS; Linux under RVK_WINDOW too): the renderer's main-thread event pump owns the
// keyboard and keeps the pad word (render/vk_render.cpp). Weak so the standalone shell / module
// builds that carry no renderer still link and fall through to the X11 poller below.
extern "C" uint16_t rvk_sdl_host_buttons(void) __attribute__((weak));
#endif
#include <thread>
static std::atomic<uint16_t> g_host_buttons{0};
// ★ RT_PAD_HOST_FIFO frame-scheduled press (2026-10-05, r23-w136 S16: the phase-controlled shell gate). A FIFO word of
// the form "<frame>:<hexpad>" (e.g. "2131:1000") arms ONE press that the GUEST-THREAD read below applies while the
// renderer's frame counter (rvk_frame_now(), stamped at nvk_frame_submit) is in [frame, frame+12) -- i.e. for exactly
// 12 guest ticks starting the tick after frame <frame> was submitted. The 4 ms poll thread only ARMS it hundreds of
// frames ahead, so the press no longer races the guest's input read (the +-1-frame residual that quantised the
// w136 A/B legs into phases). Plain "<hexpad>" words keep their old meaning. Harness-only; default inert.
static std::atomic<long>     g_sched_frame{-1};
static std::atomic<uint16_t> g_sched_pad{0};
static std::atomic<bool>     g_sched_by_tick{false};   // r23-w136 S18: "t<tick>:<pad>" keys the window on g_rt_presentN (guest presents)
extern "C" long rvk_frame_now(void) __attribute__((weak));
extern "C" long g_rt_presentN; extern "C" long g_rt_dumpTick;   // shell/gen/rt.cpp (the Present hook)
static uint16_t rt_sched_buttons(){
  long f=g_sched_frame.load(std::memory_order_relaxed); if(f<0) return 0;
  const bool byTick=g_sched_by_tick.load(std::memory_order_relaxed);
  if(!byTick && !rvk_frame_now) return 0;
  long now = byTick ? g_rt_presentN : rvk_frame_now();
  if(now<f) return 0;
  if(now>=f+12){ g_sched_frame.store(-1,std::memory_order_relaxed); return 0; }
  static long lastlog=-1; if(lastlog!=f){ lastlog=f; std::fprintf(stderr,"[padhost] sched %c%ld pad=%x fires (%s now %ld)\n",byTick?'t':'f',f,(unsigned)g_sched_pad.load(),byTick?"present":"frame",now); }
  return g_sched_pad.load(std::memory_order_relaxed);
}
static std::atomic<int16_t>  g_host_lx{0}, g_host_ly{0};
static bool rt_pad_host_on(){ static bool on=getenv("RT_PAD_HOST")!=nullptr; return on; }
// RT_PAD_HOST_FIFO=<file> token reader, shared by every host-poll arm (2026-10-29: the Windows arm joins -- until then the
// file-driven host channel existed only under SDL, so the Mac's gstart / census / rc_chain gates could not run on Windows).
// Whitespace-separated tokens: "<hex>" plain word OR'd into the host channel · "<frame>:<hex>" press at renderer frame ·
// "t<tick>:<hex>" press at guest present #tick (r23-w136 S18) · "d<tick>" tick-tagged one-shot PNG dump (rt.cpp Present hook ->
// vk_render). Same edge/level semantics as a human on the keyboard; no RT_PAD synthetic timeline, no g_syn_quiet silencer.
// Distinct from RT_PAD_FIFO, which rides the SYNTHETIC channel. Harness-only; inert unless the variable is set.
static void rt_host_fifo_merge(const char* hf, uint16_t& b){
  if(!hf) return;
  FILE* f=std::fopen(hf,"r"); if(!f) return;
  char tok[64];
  while(std::fscanf(f,"%63s",tok)==1){ long fr=-1; unsigned v=0;
    if(tok[0]=='t' && std::sscanf(tok+1,"%ld:%x",&fr,&v)==2 && fr>=0){ g_sched_pad.store((uint16_t)v,std::memory_order_relaxed); g_sched_by_tick.store(true,std::memory_order_relaxed); g_sched_frame.store(fr,std::memory_order_relaxed); }
    else if(tok[0]=='d' && std::sscanf(tok+1,"%ld",&fr)==1 && fr>=0){ static long lastDump=-1; if(fr!=lastDump){ lastDump=fr; g_rt_dumpTick=fr; } }   // arm ONCE per distinct tick (the token stays in the file; the hook consumes the arm)
    else if(std::sscanf(tok,"%ld:%x",&fr,&v)==2 && fr>=0){ g_sched_pad.store((uint16_t)v,std::memory_order_relaxed); g_sched_by_tick.store(false,std::memory_order_relaxed); g_sched_frame.store(fr,std::memory_order_relaxed); }
    else if(std::sscanf(tok,"%x",&v)==1) b|=(uint16_t)v; }
  std::fclose(f);
}
static void rt_host_poll_thread(){
#ifdef _WIN32
  struct KM{ int vk; uint16_t btn; const char* name; };
  static const KM km[]={
    {VK_LEFT,0x0004,"Left=DPAD_LEFT"},  {VK_RIGHT,0x0008,"Right=DPAD_RIGHT"},
    {VK_UP,0x0001,"Up=DPAD_UP"},        {VK_DOWN,0x0002,"Down=DPAD_DOWN"},
    {'Z',0x1000,"Z=A(shot)"},           {'X',0x2000,"X=B(bomb)"},
    {'C',0x4000,"C=X"},                 {'V',0x8000,"V=Y"},
    {VK_RETURN,0x0010,"Enter=START"},   {VK_RSHIFT,0x0020,"RShift=BACK"},
  };
  enum{ NKM=(int)(sizeof(km)/sizeof(km[0])) };
  const char* hf=getenv("RT_PAD_HOST_FIFO");   // the Windows arm of the file-driven host channel (see rt_host_fifo_merge)
  std::fprintf(stderr,"[padhost] ACTIVE (GetAsyncKeyState) -- arrows+ZXCV+Enter+RShift (Esc ignored)%s%s\n",
    hf?" + host FIFO ":"", hf?hf:"");
  for(;;){
    uint16_t b=0;
    for(int i=0;i<NKM;i++) if(GetAsyncKeyState(km[i].vk)&0x8000) b|=km[i].btn;
    rt_host_fifo_merge(hf,b);
    g_host_buttons.store(b,std::memory_order_relaxed);
    int16_t lx=0,ly=0;
    if(b&0x0004) lx=-32767; else if(b&0x0008) lx=32767;
    if(b&0x0001) ly=32767;  else if(b&0x0002) ly=-32767;
    g_host_lx.store(lx,std::memory_order_relaxed); g_host_ly.store(ly,std::memory_order_relaxed);
    std::this_thread::sleep_for(std::chrono::milliseconds(4));
  }
#else
  if(getenv("RVK_WINDOW") && rvk_sdl_host_buttons){
    // RT_PAD_HOST_FIFO=<file>: a hex pad word OR'd into THIS host channel (same edge/level semantics as a
    // human on the keyboard; no RT_PAD synthetic timeline, no g_syn_quiet silencer) -- the Mac boss driver's
    // focus-independent input. "0" releases. Distinct from RT_PAD_FIFO, which rides the SYNTHETIC channel.
    const char* hf=getenv("RT_PAD_HOST_FIFO");
    std::fprintf(stderr,"[padhost] ACTIVE via the SDL window (focus it) -- arrows+ZXCV+Enter+RShift (Esc ignored)%s%s\n",
      hf?" + host FIFO ":"", hf?hf:"");
    for(;;){
      uint16_t b=rvk_sdl_host_buttons();
      rt_host_fifo_merge(hf,b);   // token grammar: see rt_host_fifo_merge above (unchanged behaviour, now shared with the Windows arm)
      g_host_buttons.store(b,std::memory_order_relaxed);
      int16_t lx=0,ly=0;                       // arrows also drive the left stick, full deflection
      if(b&0x0004) lx=-32767; else if(b&0x0008) lx=32767;
      if(b&0x0001) ly=32767;  else if(b&0x0002) ly=-32767;   // XInput Y is up-positive
      g_host_lx.store(lx,std::memory_order_relaxed); g_host_ly.store(ly,std::memory_order_relaxed);
      std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }
  }
  typedef void* (*XOpenDisplay_t)(const char*);
  typedef int   (*XQueryKeymap_t)(void*, char[32]);
  typedef unsigned char (*XKeysymToKeycode_t)(void*, unsigned long);
  void* x11=dlopen("libX11.so.6",RTLD_NOW);
  if(!x11) x11=dlopen("libX11.so",RTLD_NOW);
  if(!x11){ std::fprintf(stderr,"[padhost] dlopen libX11 FAILED (%s) -- host pad disabled\n",dlerror()); return; }
  XOpenDisplay_t xOpen=(XOpenDisplay_t)dlsym(x11,"XOpenDisplay");
  XQueryKeymap_t xQuery=(XQueryKeymap_t)dlsym(x11,"XQueryKeymap");
  XKeysymToKeycode_t xKs2Kc=(XKeysymToKeycode_t)dlsym(x11,"XKeysymToKeycode");
  if(!xOpen||!xQuery||!xKs2Kc){ std::fprintf(stderr,"[padhost] libX11 symbols missing -- host pad disabled\n"); return; }
  void* dpy=xOpen(nullptr);  // honors $DISPLAY
  if(!dpy){ std::fprintf(stderr,"[padhost] XOpenDisplay(%s) FAILED -- host pad disabled\n",
              getenv("DISPLAY")?getenv("DISPLAY"):"(unset)"); return; }
  struct KM{ unsigned long ks; uint16_t btn; const char* name; };
  static const KM km[]={
    {0xFF51,0x0004,"Left=DPAD_LEFT"},  {0xFF53,0x0008,"Right=DPAD_RIGHT"},
    {0xFF52,0x0001,"Up=DPAD_UP"},      {0xFF54,0x0002,"Down=DPAD_DOWN"},
    {0x007A,0x1000,"Z=A(shot)"},       {0x0078,0x2000,"X=B(bomb)"},
    {0x0063,0x4000,"C=X"},             {0x0076,0x8000,"V=Y"},
    {0xFF0D,0x0010,"Enter=START"},     {0xFFE2,0x0020,"RShift=BACK"},
  };
  enum{ NKM=(int)(sizeof(km)/sizeof(km[0])) };
  unsigned char kc[NKM]; char names[320]; int off=0;
  for(int i=0;i<NKM;i++){ kc[i]=xKs2Kc(dpy,km[i].ks);
    off+=std::snprintf(names+off,sizeof(names)-off,"%s%s",i?", ":"",km[i].name); }
  std::fprintf(stderr,"[padhost] ACTIVE on DISPLAY=%s -- %s (Esc ignored)\n",
    getenv("DISPLAY")?getenv("DISPLAY"):"(default)",names);
  char keys[32];
  for(;;){
    xQuery(dpy,keys);
    uint16_t b=0;
    for(int i=0;i<NKM;i++){ unsigned char k=kc[i]; if(k && (keys[k>>3]&(1u<<(k&7)))) b|=km[i].btn; }
    g_host_buttons.store(b,std::memory_order_relaxed);
    int16_t lx=0,ly=0;                       // arrows also drive the left stick, full deflection
    if(b&0x0004) lx=-32767; else if(b&0x0008) lx=32767;
    if(b&0x0001) ly=32767;  else if(b&0x0002) ly=-32767;   // XInput Y is up-positive
    g_host_lx.store(lx,std::memory_order_relaxed); g_host_ly.store(ly,std::memory_order_relaxed);
    std::this_thread::sleep_for(std::chrono::milliseconds(4));
  }
#endif
}
static uint16_t rt_host_buttons(){
  if(!rt_pad_host_on()) return 0;
  static bool started=false;
  if(!started){ started=true; std::thread(rt_host_poll_thread).detach(); }
  return (uint16_t)(g_host_buttons.load(std::memory_order_relaxed) | rt_sched_buttons());
}
// RT_PAD_FIFO: file-driven debug input. OR a button word read each frame from a control file
// (RT_PAD_FIFO_PATH, default /tmp/futari_pad) into the guest pad. Drives input deterministically
// WITHOUT keyboard/XTEST synthesis (which on Xwayland only routes to the focused window and drops
// synthesized letter keys) -- so tests/tools can steer the game with zero desktop disruption.
// Write a hex button word to press, "0" to release, e.g. `echo 1000 > /tmp/futari_pad` (=A).
// Words: A=1000 B=2000 X=4000 Y=8000 START=10 BACK=20 DPAD L/R/U/D=4/8/1/2.
static std::atomic<uint8_t> g_fifo_lt{0}, g_fifo_rt{0};   // FIFO-injected analog triggers (P1)
static std::atomic<uint16_t> g_fifo_p2{0};                // FIFO-injected P2 pad word (Day-6 2P join)
static uint16_t rt_fifo_buttons(){
  static bool on = getenv("RT_PAD_FIFO")!=nullptr;
  if(!on) return 0;
  static const char* path = getenv("RT_PAD_FIFO_PATH") ? getenv("RT_PAD_FIFO_PATH") : "/tmp/futari_pad";
  FILE* f = std::fopen(path,"r");
  if(!f) return 0;
  // 2026-07-23 rapid-fire A/B: optional 2nd/3rd hex fields = LT/RT analog (0x00-0xFF).
  // "<buttons> [<lt> <rt>]" — e.g. `echo "0 0 20" > fifo` holds RT past the shell's >0x1e
  // threshold with no buttons. Single-field writes behave exactly as before (triggers 0).
  // 2026-08-13 Day-6 (2P join): optional 4th hex field = the P2 pad word, served on the
  // user==1 XamInputGetState LEVEL channel exactly like a physical XInput index-1 pad.
  // "<p1> <lt> <rt> <p2>" — e.g. `echo "0 0 0 10" > fifo` = P2 START, P1 idle.
  unsigned v=0, lt=0, rt=0, p2=0; int n=std::fscanf(f,"%x %x %x %x",&v,&lt,&rt,&p2);
  if(n<1) v=0; std::fclose(f);
  g_fifo_lt.store(n>=2?(uint8_t)lt:0,std::memory_order_relaxed);
  g_fifo_rt.store(n>=3?(uint8_t)rt:0,std::memory_order_relaxed);
  g_fifo_p2.store(n>=4?(uint16_t)p2:0,std::memory_order_relaxed);
  return (uint16_t)v;
}
// ============ RT_XINPUT: host XInput controllers -> guest pad (SHIP feature) ============
// Default-ON when a controller is connected; opt out with RT_NOXINPUT (PRESENCE only, per
// project convention `=0` is NOT a disable). Dynamic-load ONLY (no import-lib / link-line
// change): xinput1_4.dll -> xinput9_1_0.dll -> xinput1_3.dll, GetProcAddress("XInputGetState").
// The guest is an Xbox 360 title, so XINPUT_GAMEPAD.wButtons IS the guest logical PAD MASK
// 1:1 (A=0x1000 B=0x2000 X=0x4000 Y=0x8000, dpad 0x000F, START 0x10, BACK 0x20 — same table
// RT_PAD_HOST's km[] uses). P1 (index 0) is OR-merged inside syn_sample() below, so it inherits
// RT_PAD_HOST's exact LEVEL pad + keystroke EDGE channel behavior (menu double-fire included, by
// design — not fixed here). P2 (index 1) feeds only the user==1 XamInputGetState LEVEL word
// (shell menus are P1-only, so no EDGE channel for P2 — matching RT_PAD_HOST which is P1-only).
// Left stick past the XInput standard deadzone (7849) -> directional bits; analog also passed
// through so the guest's own stick->digital decode (FUN_82190b38) sees it too. No new thread:
// polled inline at the same per-frame site/cadence as the other host sources (syn_sample /
// XamInputGetState). Disconnected XInput polls are slow, so a DEVICE_NOT_CONNECTED result backs
// that index off to ~1 poll/sec until it reconnects.
#ifdef _WIN32
typedef struct { unsigned short wButtons; unsigned char bLeftTrigger, bRightTrigger;
  short sThumbLX, sThumbLY, sThumbRX, sThumbRY; } XI_GAMEPAD;
typedef struct { unsigned int dwPacketNumber; XI_GAMEPAD Gamepad; } XI_STATE;
typedef DWORD (WINAPI *XInputGetState_t)(DWORD, XI_STATE*);
static XInputGetState_t g_XInputGetState = nullptr;
#else
// Non-Windows host controllers (2026-10-03, SDL3 window swap): SDL3's gamepad subsystem stands
// in for XInput. Same contract as the Windows arm — this function returns the guest PAD MASK
// in XInput wButtons layout, sticks/triggers go to g_xi_*; pad index = order of SDL's gamepad
// list. SDL_UpdateGamepads() is polled here (documented for apps that do not run SDL's event
// loop on this thread); the window's SDL_PollEvent pump, when it runs, takes the same joystick
// lock. Disconnected indices back off to ~1 re-scan/sec like the XInput arm.
#include <SDL3/SDL.h>
static SDL_Gamepad* g_sdl_pad[2] = {nullptr, nullptr};
#endif
static std::atomic<int16_t> g_xi_lx[2], g_xi_ly[2];   // per-pad analog stick for XamInputGetState
static std::atomic<uint8_t> g_xi_lt[2], g_xi_rt[2];   // per-pad analog triggers (rapid-fire binding reads these)
static bool rt_xinput_on(){
#ifdef _WIN32
  static bool inited=false, usable=false;
  if(!inited){ inited=true;
    if(getenv("RT_NOXINPUT")){ std::fprintf(stderr,"[xinput] disabled by RT_NOXINPUT\n"); }
    else {
      static const char* dlls[]={"xinput1_4.dll","xinput9_1_0.dll","xinput1_3.dll"};
      for(const char* d : dlls){ HMODULE h=LoadLibraryA(d); if(!h) continue;
        g_XInputGetState=(XInputGetState_t)GetProcAddress(h,"XInputGetState");
        if(g_XInputGetState){ usable=true;
          std::fprintf(stderr,"[xinput] host controllers ENABLED via %s (set RT_NOXINPUT to disable)\n",d);
          break; }
      }
      if(!usable) std::fprintf(stderr,"[xinput] no XInput DLL loadable -- host controllers off\n");
    }
  }
  return usable;
#else
  static bool inited=false, usable=false;
  if(!inited){ inited=true;
    if(getenv("RT_NOXINPUT")){ std::fprintf(stderr,"[xinput] disabled by RT_NOXINPUT\n"); }
    else if(!SDL_InitSubSystem(SDL_INIT_GAMEPAD)){ std::fprintf(stderr,"[xinput] SDL_InitSubSystem(GAMEPAD) FAILED: %s -- host controllers off\n",SDL_GetError()); }
    else { usable=true; std::fprintf(stderr,"[xinput] host controllers ENABLED via SDL3 gamepad (set RT_NOXINPUT to disable)\n"); }
  }
  return usable;
#endif
}
// Poll one XInput pad index; return the guest PAD MASK (0 if off/disconnected). Cheap when
// disconnected: DEVICE_NOT_CONNECTED backs the index off to ~1/sec. Updates g_xi_lx/ly[idx].
static uint16_t rt_xinput_buttons(int idx){
#ifdef _WIN32
  if(idx<0 || idx>1 || !rt_xinput_on()) return 0;
  static std::atomic<long long> next_try[2];   // steady-clock ms; skip polls until then
  long long nowms=std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::steady_clock::now().time_since_epoch()).count();
  if(nowms < next_try[idx].load(std::memory_order_relaxed)){
    g_xi_lx[idx].store(0,std::memory_order_relaxed); g_xi_ly[idx].store(0,std::memory_order_relaxed);
    g_xi_lt[idx].store(0,std::memory_order_relaxed); g_xi_rt[idx].store(0,std::memory_order_relaxed);
    return 0;
  }
  XI_STATE st{};
  DWORD r=g_XInputGetState((DWORD)idx,&st);
  if(r!=0 /*ERROR_SUCCESS*/){
    if(r==1167 /*ERROR_DEVICE_NOT_CONNECTED*/) next_try[idx].store(nowms+1000,std::memory_order_relaxed);
    g_xi_lx[idx].store(0,std::memory_order_relaxed); g_xi_ly[idx].store(0,std::memory_order_relaxed);
    g_xi_lt[idx].store(0,std::memory_order_relaxed); g_xi_rt[idx].store(0,std::memory_order_relaxed);
    return 0;
  }
  const XI_GAMEPAD& g=st.Gamepad;
  // wButtons layout == guest PAD MASK. 2026-07-23 RT-rapid leg: pass LB/RB/thumb-clicks
  // through too (0xF3FF = every standard 360 button; 0x0400/0x0800 stay masked — reserved/
  // guide). The old 0xF03F mask silently ate LB/RB, so a shoulder rapid-fire binding could
  // never fire. Unknown bits produce no keystroke edge (syn_pad_to_vk -> 0) — LEVEL only.
  uint16_t b=(uint16_t)(g.wButtons & 0xF3FF);
  // left stick -> directional bits (XInput standard left-stick deadzone). XInput Y is up-positive.
  const int DZ=7849;
  if(g.sThumbLX<=-DZ) b|=0x0004; else if(g.sThumbLX>=DZ) b|=0x0008;   // LEFT / RIGHT
  if(g.sThumbLY>= DZ) b|=0x0001; else if(g.sThumbLY<=-DZ) b|=0x0002;  // UP   / DOWN
  g_xi_lx[idx].store(g.sThumbLX,std::memory_order_relaxed);
  g_xi_ly[idx].store(g.sThumbLY,std::memory_order_relaxed);
  g_xi_lt[idx].store(g.bLeftTrigger,std::memory_order_relaxed);
  g_xi_rt[idx].store(g.bRightTrigger,std::memory_order_relaxed);
  return b;
#else
  if(idx<0 || idx>1 || !rt_xinput_on()) return 0;
  static std::atomic<long long> next_try[2];   // steady-clock ms; re-scan for a pad no sooner than this
  long long nowms=std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::steady_clock::now().time_since_epoch()).count();
  auto zero=[&](){ g_xi_lx[idx].store(0,std::memory_order_relaxed); g_xi_ly[idx].store(0,std::memory_order_relaxed);
                   g_xi_lt[idx].store(0,std::memory_order_relaxed); g_xi_rt[idx].store(0,std::memory_order_relaxed); };
  SDL_UpdateGamepads();
  if(g_sdl_pad[idx] && !SDL_GamepadConnected(g_sdl_pad[idx])){ SDL_CloseGamepad(g_sdl_pad[idx]); g_sdl_pad[idx]=nullptr;
    std::fprintf(stderr,"[xinput] pad %d disconnected\n",idx); }
  if(!g_sdl_pad[idx]){
    if(nowms < next_try[idx].load(std::memory_order_relaxed)){ zero(); return 0; }
    next_try[idx].store(nowms+1000,std::memory_order_relaxed);
    int n=0; SDL_JoystickID* ids=SDL_GetGamepads(&n);
    if(ids){ if(idx<n){ g_sdl_pad[idx]=SDL_OpenGamepad(ids[idx]);
               if(g_sdl_pad[idx]) std::fprintf(stderr,"[xinput] pad %d = \"%s\"\n",idx,SDL_GetGamepadName(g_sdl_pad[idx])); }
             SDL_free(ids); }
    if(!g_sdl_pad[idx]){ zero(); return 0; }
  }
  SDL_Gamepad* p=g_sdl_pad[idx];
  // SDL_GamepadButton -> XInput wButtons bit (the guest PAD MASK). Same 0xF3FF coverage as the
  // Windows arm: every standard 360 button; 0x0400/0x0800 (reserved/guide) never set.
  static const struct { SDL_GamepadButton sb; uint16_t bit; } map[]={
    {SDL_GAMEPAD_BUTTON_DPAD_UP,0x0001},{SDL_GAMEPAD_BUTTON_DPAD_DOWN,0x0002},
    {SDL_GAMEPAD_BUTTON_DPAD_LEFT,0x0004},{SDL_GAMEPAD_BUTTON_DPAD_RIGHT,0x0008},
    {SDL_GAMEPAD_BUTTON_START,0x0010},{SDL_GAMEPAD_BUTTON_BACK,0x0020},
    {SDL_GAMEPAD_BUTTON_LEFT_STICK,0x0040},{SDL_GAMEPAD_BUTTON_RIGHT_STICK,0x0080},
    {SDL_GAMEPAD_BUTTON_LEFT_SHOULDER,0x0100},{SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER,0x0200},
    {SDL_GAMEPAD_BUTTON_SOUTH,0x1000},{SDL_GAMEPAD_BUTTON_EAST,0x2000},
    {SDL_GAMEPAD_BUTTON_WEST,0x4000},{SDL_GAMEPAD_BUTTON_NORTH,0x8000},
  };
  uint16_t b=0;
  for(const auto& m : map) if(SDL_GetGamepadButton(p,m.sb)) b|=m.bit;
  // SDL axes are down-positive on Y; XInput is up-positive. Triggers: SDL 0..32767 -> XInput 0..255.
  const int16_t lx=SDL_GetGamepadAxis(p,SDL_GAMEPAD_AXIS_LEFTX);
  const int16_t lyRaw=SDL_GetGamepadAxis(p,SDL_GAMEPAD_AXIS_LEFTY);
  const int16_t ly=(int16_t)(lyRaw==-32768 ? 32767 : -lyRaw);
  const uint8_t lt=(uint8_t)(SDL_GetGamepadAxis(p,SDL_GAMEPAD_AXIS_LEFT_TRIGGER)>>7);
  const uint8_t rt=(uint8_t)(SDL_GetGamepadAxis(p,SDL_GAMEPAD_AXIS_RIGHT_TRIGGER)>>7);
  const int DZ=7849;   // XInput standard left-stick deadzone, same as the Windows arm
  if(lx<=-DZ) b|=0x0004; else if(lx>=DZ) b|=0x0008;   // LEFT / RIGHT
  if(ly>= DZ) b|=0x0001; else if(ly<=-DZ) b|=0x0002;  // UP   / DOWN
  g_xi_lx[idx].store(lx,std::memory_order_relaxed); g_xi_ly[idx].store(ly,std::memory_order_relaxed);
  g_xi_lt[idx].store(lt,std::memory_order_relaxed); g_xi_rt[idx].store(rt,std::memory_order_relaxed);
  return b;
#endif
}
// sample the timeline; on edge, push keystroke + bump packet. Call under g_syn_m.
static uint16_t syn_sample(){
  uint16_t b=(uint16_t)(syn_buttons_now()|rt_host_buttons()|rt_fifo_buttons()|rt_xinput_buttons(0));
  { static const bool nogate = getenv("RT_STARTWIRE_NOGATE")!=nullptr;   // G-START: honour the shell's game-input gate
    static const bool rawlevel = getenv("RT_STARTWIRE_RAWLEVEL")!=nullptr; // DC-2: old host-level timing (A/B lever)
    const bool focus = nogate || g_rt_gamefocus.load(std::memory_order_relaxed)!=0;
    const bool held = (b & 0x0010)!=0;
    if(!held) g_rt_startedge.store(0, std::memory_order_relaxed);          // DC-2: a release re-arms the ordering latch
    g_rt_startheld.store((held && focus)?1:0, std::memory_order_relaxed);
    const bool seen = rawlevel || g_rt_startedge.load(std::memory_order_relaxed)!=0;
    g_rt_startline.store((held && focus && seen)?1:0, std::memory_order_relaxed); }   // START (wButton 0x10) = 1P-START line
  if(b!=g_syn_last){
    if(b){ uint16_t vk=syn_pad_to_vk(b); if(vk){ g_syn_ks.push_back((uint32_t)vk<<16 | 0x0001); // KEYDOWN
        std::fprintf(stderr,"  [xinput] press pad=0x%04X vk=0x%04X\n",b,vk); } }
    else { uint16_t vk=syn_pad_to_vk(g_syn_last); if(vk) g_syn_ks.push_back((uint32_t)vk<<16 | 0x0002); } // KEYUP
    g_syn_last=b; g_syn_pkt++;
    // STALE-REPLAY FIX (2026-07-21): record push time per edge; the CONSUMER drops entries
    // older than 2s (GetKeystrokeEx below). The unbounded deque replayed minutes-old NAV_SEQ
    // START edges into the select menus (timer auto-confirm -> overshoot) and delayed live
    // FIFO presses by seconds. Age-at-consume (NOT a size cap: NAV_SEQ pushes every 500ms,
    // a cap evicts fresh harness presses before slow screens poll them).
    while(g_syn_ts.size()<g_syn_ks.size()) g_syn_ts.push_back(std::chrono::steady_clock::now());
  }
  return b;
}
PPC_FUNC_IMPL(__imp__XamInputGetKeystrokeEx){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamInputGetKeystrokeEx\n");}g_import_calls++;rt_impcall(__func__);
  // (user_index_ptr r3, flags r4, keystroke r5[8B]). Default X_ERROR_EMPTY (0x10D2) so
  // the shell doesn't consume a garbage keystroke every frame. Under RT_PAD, deliver the
  // next scripted keystroke as a KEYDOWN edge and return SUCCESS.
  uint32_t uip=ctx.r3.u32, ksp=ctx.r5.u32;
  if(!ksp){ ctx.r3.u64=0xA0; (void)base; return; } // X_ERROR_BAD_ARGUMENTS
  static bool pad_on = getenv("RT_PAD")!=nullptr;
  if(pad_on || rt_pad_host_on()){
    std::lock_guard<std::mutex> l(g_syn_m);
    syn_sample();  // advance time-based edge detection so keystrokes get generated
    // STALE-REPLAY FIX: drop edges older than 2s (paired press/release age together, so a
    // stale pair vanishes atomically; a fresh press behind stale entries is reached now).
    {
      auto now=std::chrono::steady_clock::now();
      while(!g_syn_ks.empty() && !g_syn_ts.empty() &&
            std::chrono::duration_cast<std::chrono::milliseconds>(now-g_syn_ts.front()).count()>2000){
        g_syn_ks.pop_front(); g_syn_ts.pop_front();
      }
    }
    if(!g_syn_ks.empty()){
      uint32_t e=g_syn_ks.front(); g_syn_ks.pop_front();
      if(!g_syn_ts.empty()) g_syn_ts.pop_front();
      uint16_t vk=(uint16_t)(e>>16), fl=(uint16_t)(e&0xFFFF);
      PPC_STORE_U16(ksp+0,vk); PPC_STORE_U16(ksp+2,0); PPC_STORE_U16(ksp+4,fl);
      PPC_STORE_U8(ksp+6,0); PPC_STORE_U8(ksp+7,0);
      if(uip) PPC_STORE_U32(uip,0);
      std::fprintf(stderr,"  [xinput] keystroke vk=0x%04X flags=0x%X delivered\n",vk,fl);
      ctx.r3.u64=0; (void)base; return; // X_ERROR_SUCCESS
    }
  }
  ctx.r3.u64=0x10D2; (void)base;} // X_ERROR_EMPTY
PPC_FUNC_IMPL(__imp__XamInputGetState){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamInputGetState (synthetic pad0)\n");}g_import_calls++;rt_impcall(__func__);
  uint32_t user=ctx.r3.u32, sp=ctx.r5.u32;
  { static bool d=false; if(!d){ d=true; std::fprintf(stderr,"  [xinput] first call user=%u r4=0x%X statep=0x%08X\n",(unsigned)user,(unsigned)ctx.r4.u32,(unsigned)sp); } }
  ctx.r3.u64=0; // X_ERROR_SUCCESS (device connected)
  if(sp){ uint8_t* s=base+sp;
    static bool pad_on = getenv("RT_PAD")!=nullptr;
    uint16_t buttons=0; uint32_t pkt=0;
    if(user==0 && (pad_on || rt_pad_host_on() || rt_xinput_on())){ std::lock_guard<std::mutex> l(g_syn_m); buttons=syn_sample(); pkt=g_syn_pkt; }
    else if(user==1){ // P2 pad LEVEL only (no keystroke EDGE channel): physical XInput idx 1
                      // OR the scripted FIFO 4th field (Day-6 2P join; unattended drives).
      buttons=(uint16_t)(rt_xinput_buttons(1) | g_fifo_p2.load(std::memory_order_relaxed));
      static std::atomic<int> j{0};
      if(buttons && (j.fetch_add(1)<6)) std::fprintf(stderr,"  [xinput] P2 buttons=0x%04X (user=1)\n",buttons);
    }
    *(uint32_t*)s=__builtin_bswap32(pkt); *(uint16_t*)(s+4)=__builtin_bswap16(buttons);
    // analog triggers (XINPUT_GAMEPAD bLeft/RightTrigger, single bytes — no swap). The shell's
    // rapid-fire binding reads these; they were hardcoded 0 until the 2026-07-23 RT-rapid leg.
    // P1 also merges the FIFO-injected triggers (scripted rapid-fire A/B; max = OR-like merge).
    if(user<2){ uint8_t lt=g_xi_lt[user].load(std::memory_order_relaxed);
                uint8_t rt=g_xi_rt[user].load(std::memory_order_relaxed);
                if(user==0){ uint8_t fl=g_fifo_lt.load(std::memory_order_relaxed);
                             uint8_t fr=g_fifo_rt.load(std::memory_order_relaxed);
                             if(fl>lt) lt=fl; if(fr>rt) rt=fr; }
                s[6]=lt; s[7]=rt; }
    else { s[6]=0; s[7]=0; }
    // left stick: host-keyboard (arrows, full deflection) takes priority; else the XInput analog
    // stick for this pad index (0 for both when no source is active) -- same wire format as before.
    int16_t sx=g_host_lx.load(std::memory_order_relaxed), sy=g_host_ly.load(std::memory_order_relaxed);
    if(user<2){ if(!sx) sx=g_xi_lx[user].load(std::memory_order_relaxed);
                if(!sy) sy=g_xi_ly[user].load(std::memory_order_relaxed); }
    *(uint16_t*)(s+8) =__builtin_bswap16((uint16_t)sx);
    *(uint16_t*)(s+10)=__builtin_bswap16((uint16_t)sy);
    *(uint16_t*)(s+12)=0; *(uint16_t*)(s+14)=0;
  }
  (void)base;}
// __imp__XamNotifyCreateListener moved to rt.cpp (notification listener model)
PPC_FUNC_IMPL(__imp__XamSessionCreateHandle){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamSessionCreateHandle\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XamSessionRefObjByHandle){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamSessionRefObjByHandle\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
// Headless device selector, rexglue parity (xam_ui.cpp:531 XamShowDeviceSelectorUI ->
// xeXamDispatchHeadless -> kernel_state CompleteOverlappedEx). Args: r3=user,
// r4=content_type, r5=content_flags, r6=total_requested(u64), r7=&device_id,
// r8=&XOVERLAPPED{result@0,length@4,ctx@8,event@0xC,routine@0x10,rctx@0x14,exterr@0x18}.
// device_id:=1 (rexglue's dummy device), broadcast XN_SYS_UI open+close, complete the
// overlapped SUCCESS + signal its event, return 997 (ERROR_IO_PENDING).
extern "C" void rt_notify_broadcast(uint32_t,uint32_t);
PPC_FUNC_IMPL(__imp__XamShowDeviceSelectorUI){g_import_calls++;rt_impcall(__func__);
  uint32_t devp=ctx.r7.u32, ov=ctx.r8.u32;
  std::fprintf(stderr,"[devsel] user=%u type=0x%X flags=0x%X req=0x%llX devp=0x%X ov=0x%X\n",
    ctx.r3.u32,ctx.r4.u32,ctx.r5.u32,(unsigned long long)ctx.r6.u64,devp,ov);
  if(devp) PPC_STORE_U32(devp,1);
  // RT_SAVE §4: a successful device-selector pick opens the session — device 1 becomes valid
  // for XamContentGetDeviceData until something closes it.
  if(rt_save_on()){ std::lock_guard<std::mutex> l(g_devm); g_devopen.insert(1u); }
  rt_notify_broadcast(0x9,1);
  rt_notify_broadcast(0x9,0);
  if(ov){
    PPC_STORE_U32(ov+0x00,0);   // result = ERROR_SUCCESS
    PPC_STORE_U32(ov+0x04,0);   // length
    PPC_STORE_U32(ov+0x18,0);   // extended_error
    uint32_t cr=PPC_LOAD_U32(ov+0x10);
    if(cr) std::fprintf(stderr,"[devsel] WARNING: completion routine 0x%X not dispatched\n",cr);
    uint32_t ev=PPC_LOAD_U32(ov+0x0C);
    if(ev){ PPCContext k{}; k.r3.u64=ev; __imp__NtSetEvent(k,base); std::fprintf(stderr,"[devsel] signaled ov event 0x%X\n",ev); }
    ctx.r3.u64=997; (void)base; return;  // ERROR_IO_PENDING
  }
  ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XamShowGamerCardUIForXUID){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamShowGamerCardUIForXUID\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XamShowMarketplaceDownloadItemsUI){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamShowMarketplaceDownloadItemsUI\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
// (user_index r3, title_ptr r4, text_ptr r5, button_count r6, button_ptrs r7, active_button r8,
// flags r9, unknown_unused r10, result_ptr [stack arg9 @ r1+0x54], overlapped [stack arg10 @
// r1+0x5C]) — real XAM ABI (rexglue xam_ui.cpp XamShowMessageBoxUIEx_entry / XamShowMessageBoxUICommon).
// This is the "しますか？" (Yes/No) save-confirm dialog per TITLE_SCREEN_NOTES.md:34-37. The old
// bare no-op stub never touched an overlapped or signaled its event, so a caller that waits on
// the overlapped event hangs forever (the "stuck しますか？ dialog" TITLE_SCREEN_NOTES reports).
// Headless answer = auto-pick the caller's own focused/default button (active_button), matching
// real XAM's xeXamDispatchHeadless behavior exactly (not a hardcoded "Yes").
PPC_FUNC_IMPL(__imp__XamShowMessageBoxUIEx){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamShowMessageBoxUIEx\n");}g_import_calls++;rt_impcall(__func__);
  if(!rt_save_on()){ ctx.r3.u64=0;(void)base; return; }   // preserve exact old behavior when off
  uint32_t user=ctx.r3.u32, titlep=ctx.r4.u32, textp=ctx.r5.u32, btncount=ctx.r6.u32,
           btnptrs=ctx.r7.u32, active=ctx.r8.u32, flags=ctx.r9.u32;
  uint32_t resultp = PPC_LOAD_U32(ctx.r1.u32 + 0x54);   // stack arg9
  uint32_t ov       = PPC_LOAD_U32(ctx.r1.u32 + 0x5C);  // stack arg10
  uint32_t chosen = btncount ? (active<btncount? active : btncount-1) : 0;
  std::fprintf(stderr,"[msgbox] user=%u title=0x%X text=0x%X btns=%u ptrs=0x%X active=%u flags=0x%X resultp=0x%X ov=0x%X -> chosen=%u\n",
    user,titlep,textp,btncount,btnptrs,active,flags,resultp,ov,chosen);
  if(resultp) PPC_STORE_U32(resultp,chosen);
  rt_notify_broadcast(0x9,1);
  rt_notify_broadcast(0x9,0);
  if(ov){
    PPC_STORE_U32(ov+0x00,0); PPC_STORE_U32(ov+0x04,0); PPC_STORE_U32(ov+0x18,0);
    uint32_t ev=PPC_LOAD_U32(ov+0x0C); if(ev){ PPCContext k{}; k.r3.u64=ev; __imp__NtSetEvent(k,base); }
    ctx.r3.u64=997; (void)base; return;
  }
  ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XamShowSigninUI){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamShowSigninUI\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XamUserAreUsersFriends){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamUserAreUsersFriends\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XamUserCheckPrivilege){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamUserCheckPrivilege\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XamUserCreateStatsEnumerator){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamUserCreateStatsEnumerator\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
// XamUserGetName(user r3, buf r4, buflen r5): write a real name (was return-0 w/o output).
PPC_FUNC_IMPL(__imp__XamUserGetName){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamUserGetName\n");}g_import_calls++;rt_impcall(__func__);
  uint32_t buf=ctx.r4.u32, len=ctx.r5.u32;
  if(buf&&len){ const char* nm="Player1"; uint32_t i=0; for(;nm[i]&&i<len-1;i++) PPC_STORE_U8(buf+i,(uint8_t)nm[i]); PPC_STORE_U8(buf+i,0); }
  ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XamUserGetSigninState){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamUserGetSigninState (user0=SignedInLocally)\n");}g_import_calls++;rt_impcall(__func__);uint32_t _u=ctx.r3.u32;ctx.r3.u64=(_u==0)?1:0;(void)base;}
PPC_FUNC_IMPL(__imp__XamUserGetXUID){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamUserGetXUID\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XamUserReadProfileSettings){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XamUserReadProfileSettings\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XexCheckExecutablePrivilege){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XexCheckExecutablePrivilege\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XexGetModuleHandle){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XexGetModuleHandle\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XexGetProcedureAddress){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XexGetProcedureAddress\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__XexLoadImage){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__XexLoadImage\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
// ★ FNF-11 part 2 (2026-07-27, decomp-grounded — NOTE_fnf11_handback PART 2): the menu-level
// quit (B == RETURN TO TOP MENU) sends msg 13 + msg 3 and unloads the ROM image; the shell's
// own TOP MENU then owns the display. g_rt_romactive was set once at ROM main entry and never
// cleared, so present routing stayed on the dead ROM spine = the stuck slate compose. Clear it
// here — the unload IS the register-true "ROM no longer owns the screen" event. Guarded on
// field-inactive so a hypothetical mid-play module unload can't flip routing during gameplay.
// (First attempt used the [0x821F8588]+0x64 shell-owns byte from FUN_821CE400; measured 07-27:
// that byte never becomes 1 in our port — setter path not reached — so the gate stays as a
// harmless extra check in rt_rom_render and THIS clear is the working half.)
// RT_NOUNLOADCLEAR=1 reverts. Every unload logs (not once-only) — routing changes must be loud.
PPC_FUNC_IMPL(__imp__XexUnloadImage){g_import_calls++;rt_impcall(__func__);
  extern volatile int g_rt_romactive;
  { extern volatile int g_game_unloaded; g_game_unloaded = 1; }  // RT_REATTACH lever input (merged_xex.cpp)
  static bool noClear = getenv("RT_NOUNLOADCLEAR") && atoi(getenv("RT_NOUNLOADCLEAR"))!=0;
  uint32_t fa = base ? __builtin_bswap32(*(uint32_t*)(base + GA_FIELD_ACTIVE)) : 0;
  std::fprintf(stderr,"  [import] __imp__XexUnloadImage r3=0x%X field=%u romactive=%d%s\n",
               ctx.r3.u32, fa, g_rt_romactive,
               (!noClear && fa==0 && g_rt_romactive) ? " -> CLEAR romactive (shell owns display)" : "");
  if(!noClear && fa==0 && g_rt_romactive) g_rt_romactive = 0;
  ctx.r3.u64=0;}
PPC_FUNC_IMPL(__imp____C_specific_handler){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp____C_specific_handler\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp___vsnprintf){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp___vsnprintf\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
PPC_FUNC_IMPL(__imp__sprintf){static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] __imp__sprintf\n");}g_import_calls++;rt_impcall(__func__);ctx.r3.u64=0;(void)base;}
