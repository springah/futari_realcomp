#pragma once
#include "ppc_config.h"

#ifndef PPC_CONTEXT_H_INCLUDED
#define PPC_CONTEXT_H_INCLUDED

#ifndef PPC_CONFIG_H_INCLUDED
#error "ppc_config.h must be included before ppc_context.h"
#endif

#include <climits>
#include <cmath>
#include <csetjmp>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <atomic>

#include <x86/avx.h>
#include <x86/sse.h>
#include <x86/sse4.1.h>

// SSE3 constants are missing from simde
#ifndef _MM_DENORMALS_ZERO_MASK
#define _MM_DENORMALS_ZERO_MASK 0x0040
#endif

#define PPC_JOIN(x, y) x##y
#define PPC_XSTRINGIFY(x) #x
#define PPC_STRINGIFY(x) PPC_XSTRINGIFY(x)
#define PPC_FUNC(x) void x(PPCContext& __restrict ctx, uint8_t* base)
#define PPC_FUNC_IMPL(x) extern "C" PPC_FUNC(x)
#define PPC_EXTERN_FUNC(x) extern PPC_FUNC(x)
#define PPC_WEAK_FUNC(x) __attribute__((weak,noinline)) PPC_FUNC(x)

#define PPC_FUNC_PROLOGUE() __builtin_assume(((size_t)base & 0x1F) == 0)

#ifndef PPC_LOAD_U8
#define PPC_LOAD_U8(x) *(volatile uint8_t*)(base + (x))
#endif

#ifndef PPC_LOAD_U16
#define PPC_LOAD_U16(x) __builtin_bswap16(*(volatile uint16_t*)(base + (x)))
#endif

#ifndef PPC_LOAD_U32
#define PPC_LOAD_U32(x) __builtin_bswap32(*(volatile uint32_t*)(base + (x)))
#endif

#ifndef PPC_LOAD_U64
#define PPC_LOAD_U64(x) __builtin_bswap64(*(volatile uint64_t*)(base + (x)))
#endif

// TODO: Implement.
// These are currently unused. However, MMIO loads could possibly be handled statically with some profiling and a fallback.
// The fallback would be a runtime exception handler which will intercept reads from MMIO regions 
// and log the PC for compiling to static code later.
#ifndef PPC_MM_LOAD_U8
#define PPC_MM_LOAD_U8(x)  PPC_LOAD_U8 (x)
#endif

#ifndef PPC_MM_LOAD_U16
#define PPC_MM_LOAD_U16(x) PPC_LOAD_U16(x)
#endif

#ifndef PPC_MM_LOAD_U32
#define PPC_MM_LOAD_U32(x) PPC_LOAD_U32(x)
#endif

#ifndef PPC_MM_LOAD_U64
#define PPC_MM_LOAD_U64(x) PPC_LOAD_U64(x)
#endif

// ══ r23-w56 F1 DRIVER: RT_FLAGTAP — watchpoint census, SHELL-TREE COPY. See out_reco/ppc_context.h
// for the full rationale; this is the identical patch applied to the shell guest tree's own copy
// of this header so the watchpoint has NO BLIND SPOT at the shell/game boundary (LAWS M5: an
// instrument's silence is only evidence for what it can structurally see — the game-only copy of
// this patch left shell/gen/*.cpp's own PPC_STORE_* invisible to the tap, a real coverage gap
// found and closed same-window before trusting the game-only leg's negative). HARNESS-ONLY, NEVER
// SHIP. Default-off (RT_FLAGTAP getenv, cached once per TU, campaign-standard cost).
#ifndef RT_FLAGTAP_LO
#define RT_FLAGTAP_LO 0x887AD528u
#define RT_FLAGTAP_HI 0x887AD540u
static inline bool rt_flagtap_enabled(){
  static int v = std::getenv("RT_FLAGTAP") ? 1 : 0;
  return v != 0;
}
static inline void rt_flagtap_hit(uint32_t ea, uint32_t width, uint32_t val, const char* fn, const void* ra){
  static std::atomic<bool> armed{false};
  if(!armed.exchange(true)) std::fprintf(stderr, "[flagtap] ARMED\n");
  static std::atomic<long long> n{0};
  long long i = n.fetch_add(1) + 1;
  std::fprintf(stderr, "[flagtap] #%lld ea=0x%X w=%u val=0x%X fn=%s ra=%p\n", i, ea, width, val, fn, ra);
  std::fflush(stderr);
}
#define RT_FLAGTAP_HIT(e, sz) ((e) < RT_FLAGTAP_HI && (uint32_t)((e) + (sz)) > RT_FLAGTAP_LO)
#endif

// ══ r23-w74 DRIVER: RT_INSTALLWATCH — the menu-list vtable install-watch. Targets the 6
// vtables NAMER r31/r32 exhausted the static caller-context lever on without a class-noun mint
// (`name_shell_r32_w73.md` section 1; 0x82050088 excluded, architecturally closed same window as
// MenuNodeBase's own base vtable, no distinct class): 0x82050150, 0x820501A8, 0x82050268,
// 0x82050610, 0x82050678, 0x820500F0 (0x8204FDB8, the ReplayPanel-branch sibling that shares
// rowless slots with 0x820500F0, has no separately-identified installer function in the r32
// static work and is NOT tapped here — see PREREG_w74.txt for this scoping note). HARNESS-ONLY,
// NEVER SHIP. Pre-registered bank/r23/w74/PREREG_w74.txt before any scoring drive.
// Placement: an ENTRY tap (RT_WITNESS_ENTRY precedent) at the top of each installer's own
// PPC_FUNC_IMPL body, not a mid-body store tap — every one of these 13 functions IS a vtable
// installer by the roster's own definition (name_shell_r32_w73.md section 1.2's caller-context
// table), so tapping entry (this=ctx.r3, caller=ctx.lr) records "this vtable was installed, by
// whom, when" without needing to re-locate each body's own lis/addi/stw materialisation site --
// lower-risk (no existing line touched, no store macro edited, LAWS T2/T8 untouched) and
// equivalent evidence. Read-only; no guest-visible value/width/order/control-flow change.
// RT_-env-gated (getenv, cached once per TU); ARMED banner per LAWS M+.
#ifndef RT_INSTALLWATCH_ON
static inline bool rt_installwatch_enabled(){
  static int v = std::getenv("RT_INSTALLWATCH") ? 1 : 0;
  return v != 0;
}
#define RT_INSTALLWATCH_ON() (__builtin_expect(rt_installwatch_enabled(), 0))
static inline void rt_installwatch_armed_once(){
  static std::atomic<bool> armed{false};
  if(!armed.exchange(true)) std::fprintf(stderr, "[instwatch] ARMED\n");
}
static inline void rt_installwatch_hit(uint32_t vt, uint32_t installer, uint32_t this_ptr, uint32_t guest_lr){
  rt_installwatch_armed_once();
  static std::atomic<long long> n{0};
  long long i = n.fetch_add(1) + 1;
  std::fprintf(stderr, "[instwatch] #%lld vt=0x%X installer=sub_%X this=0x%X lr=0x%X\n",
               i, vt, installer, this_ptr, guest_lr);
  std::fflush(stderr);
}
#define RT_INSTALLWATCH_HIT(vt, installer) do { \
    if (RT_INSTALLWATCH_ON()) rt_installwatch_hit((uint32_t)(vt), (uint32_t)(installer), \
                                                    (uint32_t)ctx.r3.u32, (uint32_t)ctx.lr); \
  } while (0)

// ══ r23-w78 DRIVER: RT_INSTALLWATCH2 — dedicated ORDER probe for 0x821C5F70's own two-store
// construction-vtable sequence (NAMER r36, name_shell_r36_w77.md sec 4 / "0x821C5F70 mapped,
// soft-reset REFUTED"). Fresh hand-read of ppc_recomp.34.cpp:12967-13071 shows the body writes
// 0x8204FDB8 into [this+0] once, early (right after the prologue, before any other guest store),
// then writes 0x820500F0 into the SAME object's [this+0] again, late (just before the tail call
// to sub_821BE788). The existing w74 RT_INSTALLWATCH_HIT entry tap on this function only records
// that it was CALLED once, with a hardcoded vt=0x820500F0 argument that is not actually read off
// either store — it cannot distinguish the two internal writes or their order (w74 deliberately
// scoped 0x8204FDB8 OUT: "no separately-identified installer function", PREREG_w74.txt). This is
// that installer, found this window. Two NEW taps are placed immediately AFTER each existing
// PPC_STORE_U32 (never before, never touching the store line itself — LAWS T2/T8: no reorder, no
// store width/order change), reporting the ACTUAL stored vt value read back from the same
// register the store just used, the object pointer, and a monotonic per-process sequence number
// — so the log alone can pair each call's early/late writes back into one ordered event.
// Independently RT_-env-gated from RT_INSTALLWATCH so this window's probe cannot perturb or be
// perturbed by the w74 13-vtable roster's own counters. Read-only; zero guest-visible change.
// Pre-registered bank/r23/w78/PREREG_w78.txt (Mission 2) before any scoring drive.
#ifndef RT_INSTALLWATCH2_ON
static inline bool rt_installwatch2_enabled(){
  static int v = std::getenv("RT_INSTALLWATCH2") ? 1 : 0;
  return v != 0;
}
#define RT_INSTALLWATCH2_ON() (__builtin_expect(rt_installwatch2_enabled(), 0))
static inline void rt_installwatch2_armed_once(){
  static std::atomic<bool> armed{false};
  if(!armed.exchange(true)) std::fprintf(stderr, "[instwatch2] ARMED\n");
}
static inline void rt_installwatch2_hit(const char* slot, uint32_t vt, uint32_t this_ptr, uint32_t guest_lr){
  rt_installwatch2_armed_once();
  static std::atomic<long long> n{0};
  long long i = n.fetch_add(1) + 1;
  std::fprintf(stderr, "[instwatch2] #%lld slot=%s vt=0x%X this=0x%X lr=0x%X\n",
               i, slot, vt, this_ptr, guest_lr);
  std::fflush(stderr);
}
#define RT_INSTALLWATCH2_HIT(slot, vt, this_ptr) do { \
    if (RT_INSTALLWATCH2_ON()) rt_installwatch2_hit((slot), (uint32_t)(vt), (uint32_t)(this_ptr), \
                                                      (uint32_t)ctx.lr); \
  } while (0)
#endif
#endif

#ifndef PPC_STORE_U8
#define PPC_STORE_U8(x, y) do { \
    uint32_t _ft_e = (uint32_t)(x); uint8_t _ft_v = (uint8_t)(y); \
    if (__builtin_expect(rt_flagtap_enabled() && RT_FLAGTAP_HIT(_ft_e, 1u), 0)) \
      rt_flagtap_hit(_ft_e, 1u, (uint32_t)_ft_v, __func__, __builtin_return_address(0)); \
    *(volatile uint8_t*)(base + _ft_e) = _ft_v; } while (0)
#endif

#ifndef PPC_STORE_U16
#define PPC_STORE_U16(x, y) do { \
    uint32_t _ft_e = (uint32_t)(x); uint16_t _ft_v = (uint16_t)(y); \
    if (__builtin_expect(rt_flagtap_enabled() && RT_FLAGTAP_HIT(_ft_e, 2u), 0)) \
      rt_flagtap_hit(_ft_e, 2u, (uint32_t)_ft_v, __func__, __builtin_return_address(0)); \
    *(volatile uint16_t*)(base + _ft_e) = __builtin_bswap16(_ft_v); } while (0)
#endif

#ifndef PPC_STORE_U32
#define PPC_STORE_U32(x, y) do { \
    uint32_t _ft_e = (uint32_t)(x); uint32_t _ft_v = (uint32_t)(y); \
    if (__builtin_expect(rt_flagtap_enabled() && RT_FLAGTAP_HIT(_ft_e, 4u), 0)) \
      rt_flagtap_hit(_ft_e, 4u, _ft_v, __func__, __builtin_return_address(0)); \
    *(volatile uint32_t*)(base + _ft_e) = __builtin_bswap32(_ft_v); } while (0)
#endif

#ifndef PPC_STORE_U64
#define PPC_STORE_U64(x, y) do { \
    uint32_t _ft_e = (uint32_t)(x); uint64_t _ft_v = (uint64_t)(y); \
    if (__builtin_expect(rt_flagtap_enabled() && RT_FLAGTAP_HIT(_ft_e, 8u), 0)) \
      rt_flagtap_hit(_ft_e, 8u, (uint32_t)(_ft_v >> 32), __func__, __builtin_return_address(0)); \
    *(volatile uint64_t*)(base + _ft_e) = __builtin_bswap64(_ft_v); } while (0)
#endif

// MMIO Store handling is completely reliant on being preeceded by eieio.
// TODO: Verify if that's always the case.
#ifndef PPC_MM_STORE_U8
#define PPC_MM_STORE_U8(x, y)   PPC_STORE_U8 (x, y)
#endif

#ifndef PPC_MM_STORE_U16
#define PPC_MM_STORE_U16(x, y)  PPC_STORE_U16(x, y)
#endif

#ifndef PPC_MM_STORE_U32
#define PPC_MM_STORE_U32(x, y)  PPC_STORE_U32(x, y)
#endif

#ifndef PPC_MM_STORE_U64
#define PPC_MM_STORE_U64(x, y)  PPC_STORE_U64(x, y)
#endif

#ifndef PPC_CALL_FUNC
#define PPC_CALL_FUNC(x) x(ctx, base)
#endif

#define PPC_MEMORY_SIZE 0x100000000ull

#define PPC_LOOKUP_FUNC(x, y) *(PPCFunc**)(x + PPC_IMAGE_BASE + PPC_IMAGE_SIZE + (uint64_t(uint32_t(y) - PPC_CODE_BASE) * 2))

#ifndef PPC_CALL_INDIRECT_FUNC
#define PPC_CALL_INDIRECT_FUNC(x) (PPC_LOOKUP_FUNC(base, x))(ctx, base)
#endif

typedef void PPCFunc(struct PPCContext& __restrict__ ctx, uint8_t* base);

struct PPCFuncMapping
{
    size_t guest;
    PPCFunc* host;
};

extern PPCFuncMapping PPCFuncMappings[];

union PPCRegister
{
    int8_t s8;
    uint8_t u8;
    int16_t s16;
    uint16_t u16;
    int32_t s32;
    uint32_t u32;
    int64_t s64;
    uint64_t u64;
    float f32;
    double f64;
};

struct PPCXERRegister
{
    uint8_t so;
    uint8_t ov;
    uint8_t ca;
};

struct PPCCRRegister
{
    uint8_t lt;
    uint8_t gt;
    uint8_t eq;
    union
    {
        uint8_t so;
        uint8_t un;
    };

    template<typename T>
    inline void compare(T left, T right, const PPCXERRegister& xer) noexcept
    {
        lt = left < right;
        gt = left > right;
        eq = left == right;
        so = xer.so;
    }

    inline void compare(double left, double right) noexcept
    {
        un = __builtin_isnan(left) || __builtin_isnan(right);
        lt = !un && (left < right);
        gt = !un && (left > right);
        eq = !un && (left == right);
    }

    inline void setFromMask(simde__m128 mask, int imm) noexcept
    {
        int m = simde_mm_movemask_ps(mask);
        lt = m == imm; // all equal
        gt = 0;
        eq = m == 0; // none equal
        so = 0;
    }

    inline void setFromMask(simde__m128i mask, int imm) noexcept
    {
        int m = simde_mm_movemask_epi8(mask);
        lt = m == imm; // all equal
        gt = 0;
        eq = m == 0; // none equal
        so = 0;
    }
};

union alignas(0x10) PPCVRegister
{
    int8_t s8[16];
    uint8_t u8[16];
    int16_t s16[8];
    uint16_t u16[8];
    int32_t s32[4];
    uint32_t u32[4];
    int64_t s64[2];
    uint64_t u64[2];
    float f32[4];
    double f64[2];
};

#define PPC_ROUND_NEAREST 0x00
#define PPC_ROUND_TOWARD_ZERO 0x01
#define PPC_ROUND_UP 0x02
#define PPC_ROUND_DOWN 0x03
#define PPC_ROUND_MASK 0x03

struct PPCFPSCRRegister
{
    uint32_t csr;

    static constexpr size_t HostToGuest[] = { PPC_ROUND_NEAREST, PPC_ROUND_DOWN, PPC_ROUND_UP, PPC_ROUND_TOWARD_ZERO };

    // simde does not handle denormal flags, so we need to implement per-arch.
#if defined(__x86_64__) || defined(_M_X64)
    static constexpr size_t RoundShift = 13;
    static constexpr size_t RoundMask = SIMDE_MM_ROUND_MASK;
    static constexpr size_t FlushMask = SIMDE_MM_FLUSH_ZERO_MASK | _MM_DENORMALS_ZERO_MASK;
    static constexpr size_t GuestToHost[] = { SIMDE_MM_ROUND_NEAREST, SIMDE_MM_ROUND_TOWARD_ZERO, SIMDE_MM_ROUND_UP, SIMDE_MM_ROUND_DOWN };

    inline uint32_t getcsr() noexcept
    {
        return simde_mm_getcsr();
    }

    inline void setcsr(uint32_t csr) noexcept
    {
        simde_mm_setcsr(csr);
    }
#elif defined(__aarch64__) || defined(_M_ARM64)
    // RMode
    static constexpr size_t RoundShift = 22;
    static constexpr size_t RoundMask = 3 << RoundShift;
    // FZ and FZ16
    static constexpr size_t FlushMask = (1 << 19) | (1 << 24);
    // Nearest, Zero, -Infinity, -Infinity
    static constexpr size_t GuestToHost[] = { 0 << RoundShift, 3 << RoundShift, 1 << RoundShift, 2 << RoundShift };

    inline uint32_t getcsr() noexcept
    {
        uint64_t csr;
        __asm__ __volatile__("mrs %0, fpcr" : "=r"(csr));
        return csr;
    }

    inline void setcsr(uint32_t csr) noexcept
    {
        __asm__ __volatile__("msr fpcr, %0" : : "r"(csr));
    }
#else
#   error "Missing implementation for FPSCR."
#endif

    inline uint32_t loadFromHost() noexcept
    {
        csr = getcsr();
        return HostToGuest[(csr & RoundMask) >> RoundShift];
    }
        
    inline void storeFromGuest(uint32_t value) noexcept
    {
        csr &= ~RoundMask;
        csr |= GuestToHost[value & PPC_ROUND_MASK];
        setcsr(csr);
    }

    inline void enableFlushModeUnconditional() noexcept
    {
        csr |= FlushMask;
        setcsr(csr);
    }

    inline void disableFlushModeUnconditional() noexcept
    {
        csr &= ~FlushMask;
        setcsr(csr);
    }

    inline void enableFlushMode() noexcept
    {
        if ((csr & FlushMask) != FlushMask) [[unlikely]]
        {
            csr |= FlushMask;
            setcsr(csr);
        }
    }

    inline void disableFlushMode() noexcept
    {
        if ((csr & FlushMask) != 0) [[unlikely]]
        {
            csr &= ~FlushMask;
            setcsr(csr);
        }
    }
};

struct alignas(0x40) PPCContext
{
    PPCRegister r3;
#ifndef PPC_CONFIG_NON_ARGUMENT_AS_LOCAL
    PPCRegister r0;
#endif
    PPCRegister r1;
#ifndef PPC_CONFIG_NON_ARGUMENT_AS_LOCAL
    PPCRegister r2;
#endif
    PPCRegister r4;
    PPCRegister r5;
    PPCRegister r6;
    PPCRegister r7;
    PPCRegister r8;
    PPCRegister r9;
    PPCRegister r10;
#ifndef PPC_CONFIG_NON_ARGUMENT_AS_LOCAL
    PPCRegister r11;
    PPCRegister r12;
#endif
    PPCRegister r13;
#ifndef PPC_CONFIG_NON_VOLATILE_AS_LOCAL
    PPCRegister r14;
    PPCRegister r15;
    PPCRegister r16;
    PPCRegister r17;
    PPCRegister r18;
    PPCRegister r19;
    PPCRegister r20;
    PPCRegister r21;
    PPCRegister r22;
    PPCRegister r23;
    PPCRegister r24;
    PPCRegister r25;
    PPCRegister r26;
    PPCRegister r27;
    PPCRegister r28;
    PPCRegister r29;
    PPCRegister r30;
    PPCRegister r31;
#endif

#ifndef PPC_CONFIG_SKIP_LR
    uint64_t lr;
#endif
#ifndef PPC_CONFIG_CTR_AS_LOCAL
    PPCRegister ctr;
#endif
#ifndef PPC_CONFIG_XER_AS_LOCAL
    PPCXERRegister xer;
#endif
#ifndef PPC_CONFIG_RESERVED_AS_LOCAL
    PPCRegister reserved;
#endif
#ifndef PPC_CONFIG_SKIP_MSR
    uint32_t msr = 0x200A000;
#endif
#ifndef PPC_CONFIG_CR_AS_LOCAL
    PPCCRRegister cr0;
    PPCCRRegister cr1;
    PPCCRRegister cr2;
    PPCCRRegister cr3;
    PPCCRRegister cr4;
    PPCCRRegister cr5;
    PPCCRRegister cr6;
    PPCCRRegister cr7;
#endif
    PPCFPSCRRegister fpscr;

#ifndef PPC_CONFIG_NON_ARGUMENT_AS_LOCAL
    PPCRegister f0;
#endif
    PPCRegister f1;
    PPCRegister f2;
    PPCRegister f3;
    PPCRegister f4;
    PPCRegister f5;
    PPCRegister f6;
    PPCRegister f7;
    PPCRegister f8;
    PPCRegister f9;
    PPCRegister f10;
    PPCRegister f11;
    PPCRegister f12;
    PPCRegister f13;
#ifndef PPC_CONFIG_NON_VOLATILE_AS_LOCAL
    PPCRegister f14;
    PPCRegister f15;
    PPCRegister f16;
    PPCRegister f17;
    PPCRegister f18;
    PPCRegister f19;
    PPCRegister f20;
    PPCRegister f21;
    PPCRegister f22;
    PPCRegister f23;
    PPCRegister f24;
    PPCRegister f25;
    PPCRegister f26;
    PPCRegister f27;
    PPCRegister f28;
    PPCRegister f29;
    PPCRegister f30;
    PPCRegister f31;
#endif

    PPCVRegister v0;
    PPCVRegister v1;
    PPCVRegister v2;
    PPCVRegister v3;
    PPCVRegister v4;
    PPCVRegister v5;
    PPCVRegister v6;
    PPCVRegister v7;
    PPCVRegister v8;
    PPCVRegister v9;
    PPCVRegister v10;
    PPCVRegister v11;
    PPCVRegister v12;
    PPCVRegister v13;
#ifndef PPC_CONFIG_NON_VOLATILE_AS_LOCAL
    PPCVRegister v14;
    PPCVRegister v15;
    PPCVRegister v16;
    PPCVRegister v17;
    PPCVRegister v18;
    PPCVRegister v19;
    PPCVRegister v20;
    PPCVRegister v21;
    PPCVRegister v22;
    PPCVRegister v23;
    PPCVRegister v24;
    PPCVRegister v25;
    PPCVRegister v26;
    PPCVRegister v27;
    PPCVRegister v28;
    PPCVRegister v29;
    PPCVRegister v30;
    PPCVRegister v31;
#endif
#ifndef PPC_CONFIG_NON_ARGUMENT_AS_LOCAL
    PPCVRegister v32;
    PPCVRegister v33;
    PPCVRegister v34;
    PPCVRegister v35;
    PPCVRegister v36;
    PPCVRegister v37;
    PPCVRegister v38;
    PPCVRegister v39;
    PPCVRegister v40;
    PPCVRegister v41;
    PPCVRegister v42;
    PPCVRegister v43;
    PPCVRegister v44;
    PPCVRegister v45;
    PPCVRegister v46;
    PPCVRegister v47;
    PPCVRegister v48;
    PPCVRegister v49;
    PPCVRegister v50;
    PPCVRegister v51;
    PPCVRegister v52;
    PPCVRegister v53;
    PPCVRegister v54;
    PPCVRegister v55;
    PPCVRegister v56;
    PPCVRegister v57;
    PPCVRegister v58;
    PPCVRegister v59;
    PPCVRegister v60;
    PPCVRegister v61;
    PPCVRegister v62;
    PPCVRegister v63;
#endif
#ifndef PPC_CONFIG_NON_VOLATILE_AS_LOCAL
    PPCVRegister v64;
    PPCVRegister v65;
    PPCVRegister v66;
    PPCVRegister v67;
    PPCVRegister v68;
    PPCVRegister v69;
    PPCVRegister v70;
    PPCVRegister v71;
    PPCVRegister v72;
    PPCVRegister v73;
    PPCVRegister v74;
    PPCVRegister v75;
    PPCVRegister v76;
    PPCVRegister v77;
    PPCVRegister v78;
    PPCVRegister v79;
    PPCVRegister v80;
    PPCVRegister v81;
    PPCVRegister v82;
    PPCVRegister v83;
    PPCVRegister v84;
    PPCVRegister v85;
    PPCVRegister v86;
    PPCVRegister v87;
    PPCVRegister v88;
    PPCVRegister v89;
    PPCVRegister v90;
    PPCVRegister v91;
    PPCVRegister v92;
    PPCVRegister v93;
    PPCVRegister v94;
    PPCVRegister v95;
    PPCVRegister v96;
    PPCVRegister v97;
    PPCVRegister v98;
    PPCVRegister v99;
    PPCVRegister v100;
    PPCVRegister v101;
    PPCVRegister v102;
    PPCVRegister v103;
    PPCVRegister v104;
    PPCVRegister v105;
    PPCVRegister v106;
    PPCVRegister v107;
    PPCVRegister v108;
    PPCVRegister v109;
    PPCVRegister v110;
    PPCVRegister v111;
    PPCVRegister v112;
    PPCVRegister v113;
    PPCVRegister v114;
    PPCVRegister v115;
    PPCVRegister v116;
    PPCVRegister v117;
    PPCVRegister v118;
    PPCVRegister v119;
    PPCVRegister v120;
    PPCVRegister v121;
    PPCVRegister v122;
    PPCVRegister v123;
    PPCVRegister v124;
    PPCVRegister v125;
    PPCVRegister v126;
    PPCVRegister v127;
#endif
};

inline uint8_t VectorMaskL[] =
{
    0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00,
    0xFF, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01,
    0xFF, 0xFF, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02,
    0xFF, 0xFF, 0xFF, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03,
    0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0E, 0x0D, 0x0C,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0E, 0x0D,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0E,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F,
};

inline uint8_t VectorMaskR[] =
{
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x03, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x04, 0x03, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF,
    0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xFF, 0xFF,
    0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xFF,
};

inline uint8_t VectorShiftTableL[] =
{
    0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00,
    0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01,
    0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02,
    0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03,
    0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04,
    0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05,
    0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06,
    0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07,
    0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08,
    0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09,
    0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A,
    0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B,
    0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C,
    0x1C, 0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D,
    0x1D, 0x1C, 0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E,
    0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F,
};

inline uint8_t VectorShiftTableR[] =
{
    0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10,
    0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F,
    0x1D, 0x1C, 0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E,
    0x1C, 0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D,
    0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C,
    0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B,
    0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A,
    0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09,
    0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08,
    0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07,
    0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06,
    0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05,
    0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04,
    0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03,
    0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02,
    0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01,
};

inline simde__m128i simde_mm_adds_epu32(simde__m128i a, simde__m128i b)
{
    return simde_mm_add_epi32(a, simde_mm_min_epu32(simde_mm_xor_si128(a, simde_mm_cmpeq_epi32(a, a)), b));
}

inline simde__m128i simde_mm_avg_epi8(simde__m128i a, simde__m128i b)
{
    simde__m128i c = simde_mm_set1_epi8(char(128));
    return simde_mm_xor_si128(c, simde_mm_avg_epu8(simde_mm_xor_si128(c, a), simde_mm_xor_si128(c, b)));
}

inline simde__m128i simde_mm_avg_epi16(simde__m128i a, simde__m128i b)
{
    simde__m128i c = simde_mm_set1_epi16(short(32768));
    return simde_mm_xor_si128(c, simde_mm_avg_epu16(simde_mm_xor_si128(c, a), simde_mm_xor_si128(c, b)));
}

inline simde__m128 simde_mm_cvtepu32_ps_(simde__m128i src1)
{
    simde__m128i xmm1 = simde_mm_add_epi32(src1, simde_mm_set1_epi32(127));
    simde__m128i xmm0 = simde_mm_slli_epi32(src1, 31 - 8);
    xmm0 = simde_mm_srli_epi32(xmm0, 31);
    xmm0 = simde_mm_add_epi32(xmm0, xmm1);
    xmm0 = simde_mm_srai_epi32(xmm0, 8);
    xmm0 = simde_mm_add_epi32(xmm0, simde_mm_set1_epi32(0x4F800000));
    simde__m128 xmm2 = simde_mm_cvtepi32_ps(src1);
    return simde_mm_blendv_ps(xmm2, simde_mm_castsi128_ps(xmm0), simde_mm_castsi128_ps(src1));
}

inline simde__m128i simde_mm_perm_epi8_(simde__m128i a, simde__m128i b, simde__m128i c)
{
    simde__m128i d = simde_mm_set1_epi8(0xF);
    simde__m128i e = simde_mm_sub_epi8(d, simde_mm_and_si128(c, d));
    return simde_mm_blendv_epi8(simde_mm_shuffle_epi8(a, e), simde_mm_shuffle_epi8(b, e), simde_mm_slli_epi32(c, 3));
}

inline simde__m128i simde_mm_cmpgt_epu8(simde__m128i a, simde__m128i b)
{
    simde__m128i c = simde_mm_set1_epi8(char(128));
    return simde_mm_cmpgt_epi8(simde_mm_xor_si128(a, c), simde_mm_xor_si128(b, c));
}

inline simde__m128i simde_mm_cmpgt_epu16(simde__m128i a, simde__m128i b)
{
    simde__m128i c = simde_mm_set1_epi16(short(32768));
    return simde_mm_cmpgt_epi16(simde_mm_xor_si128(a, c), simde_mm_xor_si128(b, c));
}

inline simde__m128i simde_mm_vctsxs(simde__m128 src1)
{
    simde__m128 xmm2 = simde_mm_cmpunord_ps(src1, src1);
    simde__m128i xmm0 = simde_mm_cvttps_epi32(src1);
    simde__m128i xmm1 = simde_mm_cmpeq_epi32(xmm0, simde_mm_set1_epi32(INT_MIN));
    xmm1 = simde_mm_andnot_si128(simde_mm_castps_si128(src1), xmm1);
    simde__m128 dest = simde_mm_blendv_ps(simde_mm_castsi128_ps(xmm0), simde_mm_castsi128_ps(simde_mm_set1_epi32(INT_MAX)), simde_mm_castsi128_ps(xmm1));
    return simde_mm_andnot_si128(simde_mm_castps_si128(xmm2), simde_mm_castps_si128(dest));
}

inline simde__m128i simde_mm_vsr(simde__m128i a, simde__m128i b)
{
    b = simde_mm_srli_epi64(simde_mm_slli_epi64(b, 61), 61);
    return simde_mm_castps_si128(simde_mm_insert_ps(simde_mm_castsi128_ps(simde_mm_srl_epi64(a, b)), simde_mm_castsi128_ps(simde_mm_srl_epi64(simde_mm_srli_si128(a, 4), b)), 0x10));
}

#if defined(__aarch64__) || defined(_M_ARM64)
inline uint64_t __rdtsc()
{
    uint64_t ret;
    asm volatile("mrs %0, cntvct_el0\n\t"
                 : "=r"(ret)::"memory");
    return ret;
}
#elif !defined(__x86_64__) && !defined(_M_X64)
#   error "Missing implementation for __rdtsc()"
#endif

// ---------------------------------------------------------------------------
// PPC non-trapping integer-divide helpers.
//
// PowerISA v2.07 Book I specifies divw/divwu/divd/divdu as NON-TRAPPING: on
// divisor==0 (and, for the signed forms, on most-negative / -1) the target
// register is architecturally UNDEFINED but NO interrupt is raised. x86/x86-64
// IDIV/DIV instead raise #DE (delivered as SIGFPE) on both a zero divisor and
// the signed INT_MIN/-1 overflow. XenonRecomp emits a raw `a / b`, which turns
// a benign guest divide into a hard host crash. These guards restore PPC
// semantics with minimal divergence: every divisor that is neither 0 nor the
// -1 overflow case falls straight through to `a / b` with identical operand
// types, so all currently-correct sites stay byte-identical. Float divides are
// intentionally NOT routed here: SSE float divide-by-zero yields +/-inf with no
// trap and already matches PPC fdiv. INT32_MIN/INT64_MIN are already in scope
// via <climits>/<cstdint> included near the top of this header.
// ---------------------------------------------------------------------------

static inline int32_t ppc_divw(int32_t a, int32_t b) noexcept
{
    if (b == 0) [[unlikely]]
        return 0;                       // divide-by-zero: undefined but non-trapping -> 0
    if (b == -1 && a == INT32_MIN) [[unlikely]]
        return INT32_MIN;               // overflow: truncated quotient INT32_MIN; avoid x86 #DE
    return a / b;                       // all valid inputs: byte-identical to plain `a / b`
}

static inline uint32_t ppc_divwu(uint32_t a, uint32_t b) noexcept
{
    if (b == 0) [[unlikely]]
        return 0;                       // divide-by-zero: undefined but non-trapping -> 0
    return a / b;                       // no unsigned overflow trap exists
}

static inline int64_t ppc_divd(int64_t a, int64_t b) noexcept
{
    if (b == 0) [[unlikely]]
        return 0;                       // divide-by-zero: undefined but non-trapping -> 0
    if (b == -1 && a == INT64_MIN) [[unlikely]]
        return INT64_MIN;               // overflow: truncated quotient INT64_MIN; avoid x86 #DE
    return a / b;                       // all valid inputs: byte-identical to plain `a / b`
}

static inline uint64_t ppc_divdu(uint64_t a, uint64_t b) noexcept
{
    if (b == 0) [[unlikely]]
        return 0;                       // divide-by-zero: undefined but non-trapping -> 0
    return a / b;                       // no unsigned overflow trap exists
}
#endif
