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

// ══ r23-w68 DRIVER: THE ABN INSTRUMENT PORT — RT_TRIOTAP + RT_WITNESS + RT_WITNESS2 ported
// VERBATIM (byte-identical macro/function bodies, ARM-SYMMETRIC with out_reco/ppc_context.h
// lines 121-292) from the reco_normal tree into reco_abnormal, closing the w67-found
// instrumentation gap (bank/r23/w67/drive_w67_SCORE.md SS1.2, RULINGS_DOCKET_w67.md item 3):
// futari_game_abn.dll carried 0/6 witness tags and 0 triotap strings — not even the shared
// positive control — so the 360-card route class was structurally unobservable. HARNESS-ONLY,
// NEVER SHIP; env-gated exactly like the originals (RT_TRIOTAP/RT_WITNESS/RT_WITNESS2 getenv
// checks unchanged). Mission: bank/r23/w68/PREREG_w68.txt (written before any scoring drive).
//
// ⚠ ONE TAP SITE NEEDED AN ADDRESS REMAP, NOT A COPY: sub_881500D0 (the RT_WITNESS2 [w2fld]
// PageTransition-defaults tap) DOES NOT EXIST in out_reco_abn under that name — verified absent
// by grep (`grep -rn sub_881500D0 out_reco_abn/` = 0 hits) before any porting began, per this
// window's mission instruction. Its abn twin is sub_881500D8 (out_reco_abn/ppc_recomp.19.cpp) —
// confirmed the SAME body by a byte-for-byte structural diff against reco_normal's sub_881500D0
// (identical instruction stream; the ONLY difference is the DSTBASE2 .data literal, -24056 in
// reco_normal vs -23960 in reco_abnormal, a delta of exactly 96 = 0x60, matching LAWS I3's
// documented +0x60 abn .data-literal shift precisely). The other eight tapped addresses
// (0x8808ECC0, 0x8808FB90, 0x88091600, 0x880917C0, 0x88094970, 0x880B7A60, 0x880B7CD8,
// 0x880B9320) exist in out_reco_abn at the IDENTICAL numeric address with an IDENTICAL
// instruction stream (data literals, where present, differing by the same +0x60 — verified
// per-site, not assumed, before writing each tap call). All nine insertion points preserve
// LAWS T2/T8 exactly as the originals do: read-only observations of already-computed
// values/flags, no existing line edited, no store macro touched, no guest-visible
// value/width/order/control-flow change.
//
// The macro/function definitions below are UNMODIFIED from out_reco/ppc_context.h (same tag
// strings, same env vars, same ARMED-banner mechanism per LAWS M+) — arm-symmetry requires the
// SAME instrument in both trees, not a recolour.

// ══ r23-w58 DRIVER: RT_TRIOTAP — in-edge (caller) census for the stuck 0x880B9320 /
// 0x880B7A60 / 0x880B7CD8 trio (400 insns; static root-hunt exhausted r23-w56/w57 across three
// independent methods -- pairtbl membership, data-dword single-ref [failed its own negative
// control], vtable-slot/T1++; see bank/r23/w57/RULINGS_DOCKET_w57.md item 1 and
// bank/r23/w57/read_SCORE_w57.md Mission 3). HARNESS-ONLY, NEVER SHIP.
// Mission: bank/r23/w58/PREREG_w58.txt (written before any drive).
// This is an ENTRY tap on the body itself (inserted as the first executable line after each of
// the three PPC_FUNC_IMPL's own PPC_FUNC_PROLOGUE()), NOT a call-site wrapper -- so the PPC_FUNC
// WRAPPER CLONE BYPASS (LAWS I2, "printed nothing => not taken" is UNSAFE) does not apply here:
// PREREG_w58.txt §1 records that all three symbols were grepped across BOTH out_reco/ and
// shell/gen/ before writing this tap and each is defined in exactly ONE PPC_FUNC_IMPL, in
// exactly one TU, with no other definition anywhere -- there is no clone to bypass, and an entry
// tap inside the sole body fires on every invocation whether the caller reached it by a direct
// `sub_X(ctx,base)` call or by PPC_CALL_INDIRECT_FUNC through the shared PPCFuncMappings table
// (out_reco/ppc_func_mapping.cpp), because both paths call the identical host function.
// Reports ctx.lr -- the guest return address the CALLER set immediately before its `bl`, read
// BEFORE anything in the callee's own body can overwrite it (this macro's call site is the very
// first statement in each tapped PPC_FUNC_IMPL) -- which pinpoints the exact call-site
// instruction, strictly stronger evidence than a bare function name. __builtin_return_address(0)
// is also captured (the host caller frame) as a cross-reference field, the same role RT_FLAGTAP's
// `ra=` played. RT_-env-gated (getenv, cached once per TU, identical pattern to RT_FLAGTAP);
// ARMED banner (LAWS M+) fires once so a genuine zero is distinguishable from a dead/unlinked tap.
// A fourth tap site (sub_8808FB90, out_reco/ppc_recomp.4.cpp) is the POSITIVE CONTROL named in
// PREREG_w58.txt §2 -- it has exactly one static caller in the whole tree, so its expected value
// (lr=0x88093428) is known before flying.
#ifndef RT_TRIOTAP_ON
static inline bool rt_triotap_enabled(){
  static int v = std::getenv("RT_TRIOTAP") ? 1 : 0;
  return v != 0;
}
#define RT_TRIOTAP_ON() (__builtin_expect(rt_triotap_enabled(), 0))
static inline void rt_triotap_hit(const char* callee, uint32_t guest_lr, const void* host_ra,
                                   uint32_t r3, uint32_t r4, uint32_t r5){
  static std::atomic<bool> armed{false};
  if(!armed.exchange(true)) std::fprintf(stderr, "[triotap] ARMED\n");
  static std::atomic<long long> n{0};
  long long i = n.fetch_add(1) + 1;
  std::fprintf(stderr, "[triotap] #%lld callee=%s lr=0x%X ra=%p r3=0x%X r4=0x%X r5=0x%X\n",
               i, callee, guest_lr, host_ra, r3, r4, r5);
  std::fflush(stderr);
}
#define RT_TRIOTAP_HIT(callee) do { \
    if (RT_TRIOTAP_ON()) rt_triotap_hit((callee), (uint32_t)ctx.lr, __builtin_return_address(0), \
                                         ctx.r3.u32, ctx.r4.u32, ctx.r5.u32); \
  } while (0)
#endif

// ══ r23-w62 DRIVER: RT_WITNESS — the runtime-witness leg for three R4/R5 static-exhaustion
// holds named in bank/r23/w61/RULINGS_DOCKET_w61.md item 2 and read_SCORE_w61.md/w60.md:
// 0x880917C0's this[0] cull-dispatch type field, 0x88094970's paired (-40,280)/(240) window-test
// operands, and 0x88091600's 9-arm Defect-7 dispatch selector (arm map already fully derived
// statically, bank/r23/w60/read_SCORE_w60.md — this tap witnesses WHICH value actually arrives
// at runtime, it does not re-derive the map). HARNESS-ONLY, NEVER SHIP. Pre-registered in
// bank/r23/w62/PREREG_w62.txt before any scoring drive.
// Same ENTRY/MID-BODY-TAP shape as RT_TRIOTAP (LAWS I2 checked, not assumed: all three symbols
// grepped across out_reco/ and shell/gen/ before writing this tap — each defined in exactly one
// PPC_FUNC_IMPL, in exactly one TU, no other definition anywhere; a tap inside the sole body is
// immune to the clone-bypass by construction). The three 0x88094970 mid-body taps are placed
// immediately AFTER each cmpw/cmpwi's compare<>() call sets ctx.cr6 and BEFORE the following
// branch — they only READ the already-computed flags/operands and print; no existing line is
// edited, no store macro touched, no guest-visible value/width/order/control-flow changes
// (LAWS T2/T8 preserved). RT_-env-gated (getenv, cached once per TU); shared ARMED banner across
// all four tap functions per LAWS M+ (one instrument, one banner, four tagged hit lines).
#ifndef RT_WITNESS_ON
static inline bool rt_witness_enabled(){
  static int v = std::getenv("RT_WITNESS") ? 1 : 0;
  return v != 0;
}
#define RT_WITNESS_ON() (__builtin_expect(rt_witness_enabled(), 0))
static inline void rt_witness_armed_once(){
  static std::atomic<bool> armed{false};
  if(!armed.exchange(true)) std::fprintf(stderr, "[witness] ARMED\n");
}
// 0x880917C0 — this[0] cull-dispatch type field + caller.
static inline void rt_witness_typefield_hit(uint32_t guest_lr, uint32_t this_ptr, uint32_t type0){
  rt_witness_armed_once();
  static std::atomic<long long> n{0};
  long long i = n.fetch_add(1) + 1;
  std::fprintf(stderr, "[wtype] #%lld lr=0x%X this=0x%X type0=0x%X\n", i, guest_lr, this_ptr, type0);
  std::fflush(stderr);
}
#define RT_WITNESS_TYPEFIELD(this_ptr, type0) do { \
    if (RT_WITNESS_ON()) rt_witness_typefield_hit((uint32_t)ctx.lr, (uint32_t)(this_ptr), (uint32_t)(type0)); \
  } while (0)
// 0x88094970 — entry args (r3-r8) + caller, before any transformation.
static inline void rt_witness_entry_hit(uint32_t guest_lr, uint32_t r3v, uint32_t r4v, uint32_t r5v,
                                         uint32_t r6v, uint32_t r7v, uint32_t r8v){
  rt_witness_armed_once();
  static std::atomic<long long> n{0};
  long long i = n.fetch_add(1) + 1;
  std::fprintf(stderr, "[wentry] #%lld lr=0x%X r3=0x%X r4=0x%X r5=0x%X r6=0x%X r7=0x%X r8=0x%X\n",
               i, guest_lr, r3v, r4v, r5v, r6v, r7v, r8v);
  std::fflush(stderr);
}
#define RT_WITNESS_ENTRY(r3v, r4v, r5v, r6v, r7v, r8v) do { \
    if (RT_WITNESS_ON()) rt_witness_entry_hit((uint32_t)ctx.lr, (uint32_t)(r3v), (uint32_t)(r4v), \
                                               (uint32_t)(r5v), (uint32_t)(r6v), (uint32_t)(r7v), (uint32_t)(r8v)); \
  } while (0)
// 0x88094970 — the paired (-40,280)/(240) window-test operands, tagged per decision point.
// 'taken' is the already-computed cr6 flag for that compare (read-only, not a new branch).
static inline void rt_witness_window_hit(const char* tag, uint32_t guest_lr, uint32_t a, uint32_t b, int taken){
  rt_witness_armed_once();
  static std::atomic<long long> n{0};
  long long i = n.fetch_add(1) + 1;
  std::fprintf(stderr, "[wwin] #%lld tag=%s lr=0x%X a=0x%X(%.4f) b=0x%X(%.4f) taken=%d\n",
               i, tag, guest_lr, a, (double)(int32_t)a / 65536.0, b, (double)(int32_t)b / 65536.0, taken);
  std::fflush(stderr);
}
#define RT_WITNESS_WINDOW(tag, a, b, taken) do { \
    if (RT_WITNESS_ON()) rt_witness_window_hit((tag), (uint32_t)ctx.lr, (uint32_t)(a), (uint32_t)(b), (taken) ? 1 : 0); \
  } while (0)
// 0x88091600 — the 9-arm Defect-7 dispatch selector (arm map already derived, bank/r23/w60).
static inline void rt_witness_arm_hit(uint32_t guest_lr, uint32_t this_ptr, uint32_t sel){
  rt_witness_armed_once();
  static std::atomic<long long> n{0};
  long long i = n.fetch_add(1) + 1;
  std::fprintf(stderr, "[warm] #%lld lr=0x%X this=0x%X sel=%u\n", i, guest_lr, this_ptr, sel);
  std::fflush(stderr);
}
#define RT_WITNESS_ARM(this_ptr, sel) do { \
    if (RT_WITNESS_ON()) rt_witness_arm_hit((uint32_t)ctx.lr, (uint32_t)(this_ptr), (uint32_t)(sel)); \
  } while (0)
#endif

// ══ r23-w65 DRIVER: RT_WITNESS2 — runtime witnesses for the held-negative roster named in
// bank/r23/w64/RULINGS_DOCKET_w64.md item 3 + read_SCORE_w64.md/read_refusal_w64.md:
// 0x8808ECC0's unresolved table byte/dword reads (TBLBASE+0x9E44C, TBLBASE+72) and 0x881500D0's
// §24-declined PageTransition defaults-record caller. HARNESS-ONLY, NEVER SHIP. Pre-registered
// in bank/r23/w65/PREREG_w65.txt before any scoring drive. Same ENTRY/MID-BODY-TAP shape as
// RT_WITNESS (LAWS I2 checked, not assumed: both symbols grepped across out_reco/ and shell/
// gen/ before writing this tap — each defined in exactly one PPC_FUNC_IMPL, in exactly one TU,
// zero hits in shell/gen/; a tap inside the sole body is immune to the clone-bypass by
// construction). Neither tap edits an existing line, touches a store macro, or changes any
// guest-visible value/width/order/control-flow (LAWS T2/T8 preserved) — both are read-only
// observations inserted after the loads/address-computation they witness. RT_-env-gated
// (getenv, cached once per TU); shared ARMED banner across both tap functions per LAWS M+.
#ifndef RT_WITNESS2_ON
static inline bool rt_witness2_enabled(){
  static int v = std::getenv("RT_WITNESS2") ? 1 : 0;
  return v != 0;
}
#define RT_WITNESS2_ON() (__builtin_expect(rt_witness2_enabled(), 0))
static inline void rt_witness2_armed_once(){
  static std::atomic<bool> armed{false};
  if(!armed.exchange(true)) std::fprintf(stderr, "[witness2] ARMED\n");
}
// 0x8808ECC0 — the unresolved table: effective address (TBLBASE+0x9E44C), the byte loaded from
// it, the dword loaded from TBLBASE+72, and the caller.
static inline void rt_witness2_tblread_hit(uint32_t guest_lr, uint32_t ea, uint32_t byteval, uint32_t dwordval){
  rt_witness2_armed_once();
  static std::atomic<long long> n{0};
  long long i = n.fetch_add(1) + 1;
  std::fprintf(stderr, "[w2tbl] #%lld lr=0x%X ea=0x%X byte=0x%X dword=0x%X\n", i, guest_lr, ea, byteval, dwordval);
  std::fflush(stderr);
}
#define RT_WITNESS2_TBLREAD(ea, byteval, dwordval) do { \
    if (RT_WITNESS2_ON()) rt_witness2_tblread_hit((uint32_t)ctx.lr, (uint32_t)(ea), (uint32_t)(byteval), (uint32_t)(dwordval)); \
  } while (0)
// 0x881500D0 — the §24-declined PageTransition defaults record: the resolved base address
// (DSTBASE2) and the caller — the field VALUES are already fully known compile-time literals
// (LAWS T7), the missing fact is only who invokes this defaults writer and when.
static inline void rt_witness2_fldwrite_hit(uint32_t guest_lr, uint32_t base_addr){
  rt_witness2_armed_once();
  static std::atomic<long long> n{0};
  long long i = n.fetch_add(1) + 1;
  std::fprintf(stderr, "[w2fld] #%lld lr=0x%X base=0x%X\n", i, guest_lr, base_addr);
  std::fflush(stderr);
}
#define RT_WITNESS2_FLDWRITE(base_addr) do { \
    if (RT_WITNESS2_ON()) rt_witness2_fldwrite_hit((uint32_t)ctx.lr, (uint32_t)(base_addr)); \
  } while (0)
#endif

#ifndef PPC_STORE_U8
#define PPC_STORE_U8(x, y) *(volatile uint8_t*)(base + (x)) = (y)
#endif

#ifndef PPC_STORE_U16
#define PPC_STORE_U16(x, y) *(volatile uint16_t*)(base + (x)) = __builtin_bswap16(y)
#endif

#ifndef PPC_STORE_U32
#define PPC_STORE_U32(x, y) *(volatile uint32_t*)(base + (x)) = __builtin_bswap32(y)
#endif

#ifndef PPC_STORE_U64
#define PPC_STORE_U64(x, y) *(volatile uint64_t*)(base + (x)) = __builtin_bswap64(y)
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
