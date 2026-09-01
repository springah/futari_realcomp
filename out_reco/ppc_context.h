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

// ══ r23-w75 DRIVER: RT_TABREAD (retry) — narrower mechanism than w74's crashing global 4-width
// load-watch (bank/r23/w74/drive_w74_SCORE.md sec 3: PPC_LOAD_U8/U16/U32/U64 all hooked, one wide
// lo/hi span across three disjoint address clusters, built clean but SEGFAULTED the host twice,
// reproducibly, before any target address could plausibly be touched — differentially isolated to
// this header's PPC_LOAD_* edit specifically, REVERTED not shipped). HARNESS-ONLY, NEVER SHIP.
// Pre-registered in bank/r23/w75/PREREG_w75.txt before any build or drive.
// THIS retry narrows on BOTH axes at once (mission preference (a)+(b)):
//   (a) SINGLE WIDTH — only PPC_LOAD_U32 below is touched. All 10 mission target fields are
//       4-byte-aligned dwords at 4-byte stride (w72's read, read_SCORE_w72.md, documents the
//       writer 0x8815CAF0 storing small integer literals into them — an stw/lwz shape). PPC_LOAD_U8/
//       U16/U64 are UNCHANGED, unedited, below — zero risk from those call sites, and roughly a
//       4x cut in edited call-site count vs w74's all-four-widths shape (a plausible driver of
//       w74's own 23.4MB->~38MB size blowup, out_reco/ppc_recomp's own per-TU code growth).
//   (b) FIVE NARROW RANGES, not one wide span — RT_FLAGTAP's own proven store-side tightness
//       (24-byte window, stable ~20 windows) applied here: four mission clusters (max 16 bytes
//       each) plus a fifth POSITIVE-CONTROL cluster (pauseLatch 0x887AD538, THIS header's own
//       RT_FLAGTAP comment above already documents it as read+self-cleared every normal-running
//       frame — see PREREG_w75.txt sec 2 for why w74's own control, 0x883E009C, was invalid).
// Implementation is a GNU statement-expression (`({ ... })`, already an established extension in
// this tree via __builtin_expect/__builtin_bswap32/__builtin_assume elsewhere in this same file):
// the EA is computed once, the volatile load happens exactly once, the 5-cluster guard is checked
// behind __builtin_expect(...,0) (cheap, false on every unwatched load), and only on a rare hit is
// a logging helper called with __func__ + __builtin_return_address(0) captured AT THE MACRO'S
// INLINE EXPANSION SITE — RT_FLAGTAP's own already-proven __func__/return-address shape (the fix
// w74 sec 3.2 found after ctx.lr broke the build at call sites with no `ctx` in scope), not
// repeated here as a mistake. Purely additive: the returned value/type/width/order of the load is
// completely unchanged — the log is a side observation taken after the value is already computed
// (LAWS T2/T8 preserved). A hard per-run hit cap (2000) forecloses a runaway-stderr-I/O crash
// vector even if a cluster is hotter than expected — pure defense, does not affect data quality
// (a handful of hits per address already answers the consumer question).
#ifndef RT_TABREAD_ON
static inline bool rt_tabread_enabled(){
  static int v = std::getenv("RT_TABREAD") ? 1 : 0;
  return v != 0;
}
// cluster A: 0x883889DC/E4 (0x8815CAF0 dest). cluster B: 0x8838A930 (0x8815CAF0 dest).
// cluster C: 0x883E0098/9C/A0/A4 (0x8815CAF0 dest, the 4-field set). cluster D: 0x884D7688/8C/90
// (0x88132858 dest, struct base 0x884D7674 + 0x14/0x18/0x1C). cluster E: 0x887AD538 (pauseLatch,
// POSITIVE CONTROL ONLY — not a mission target, see header comment above).
//
// ══ r23-w77 DRIVER CONSOLIDATION (bank/r23/w77/CONSOLIDATION_w77.md): clusters A-D are ANSWERED
// (0x8815CAF0 MINTED w76 off A/B/C's own runtime evidence; 0x88132858 re-derived+re-confirmed
// held w76, no further live watch owed this window) — compiled OUT of the per-call-site OR chain
// via RT_TABREAD_FULL below, since PPC_LOAD_U32 inlines this chain at EVERY load site tree-wide
// (the w75/w76 SCORE docs' own flagged size driver — w76 sec 4's working hypothesis). Cluster E
// is the sole POSITIVE CONTROL for the shared hook (still required this window to trust
// RT_TABREAD2's cluster H, the w77 ride-along) and stays unconditional. Bounds are byte-for-byte
// UNEDITED — only the #if gate is new (LAWS T2/T8: measurement-config only, zero guest-visible
// change). Build with -DRT_TABREAD_FULL=1 to restore A-D for a future re-verification pass.
#ifndef RT_TABREAD_FULL
#define RT_TABREAD_FULL 0
#endif
// r23-w82 DRIVER: a cluster-I addition here (0x88352950, hold #10) was DESIGNED, BUILT, and
// MEASURED this window, then REVERTED before any drive — bisected (git-stash isolation, two
// controlled rebuilds) to a +16,492,544 B / +35.05% futari_game_normal.dll cost from ONE more
// unconditional OR-term alone (merged_game.cpp's own RT_S6 wrappers, tested separately, cost
// near-zero — see drive_w82_SCORE.md sec 3). PPC_LOAD_U32 inlines RT_TABREAD_HIT at every one of
// 71,042 call sites tree-wide (out_reco); this file's own r23-w77 CONSOLIDATION comment above
// already named this exact mechanism as the size driver behind clusters A-D/F/G, and this window
// reproduced it from a SINGLE new 4-byte-window term, disproportionately larger than cluster E's
// own already-priced-in cost. DECLINED per the standing w79/w77 precedent (LAWS G6-adjacent:
// re-rank rather than ship a disproportionate instrument) — hold #10 stays on the static dead-end
// disposition; PREREG_w82.txt sec 3 amendment records the measurement.
#define RT_TABREAD_HIT(e) ( \
    (RT_TABREAD_FULL && ( \
    ((e) >= 0x883889DCu && (e) <  0x883889E8u) || \
    ((e) >= 0x8838A930u && (e) <  0x8838A934u) || \
    ((e) >= 0x883E0098u && (e) <  0x883E00A8u) || \
    ((e) >= 0x884D7688u && (e) <  0x884D7694u) )) || \
    ((e) >= 0x887AD538u && (e) <  0x887AD53Cu) )
static inline const char* rt_tabread_cluster(uint32_t ea){
  if (ea >= 0x883889DCu && ea < 0x883889E8u) return "A";
  if (ea >= 0x8838A930u && ea < 0x8838A934u) return "B";
  if (ea >= 0x883E0098u && ea < 0x883E00A8u) return "C";
  if (ea >= 0x884D7688u && ea < 0x884D7694u) return "D";
  if (ea >= 0x887AD538u && ea < 0x887AD53Cu) return "E-ctrl";
  return "?";
}
static inline void rt_tabread_hit(uint32_t ea, uint32_t val, const char* fn, const void* ra){
  static std::atomic<bool> armed{false};
  if(!armed.exchange(true)) std::fprintf(stderr, "[tabread] ARMED\n");
  static std::atomic<long long> n{0};
  long long i = n.fetch_add(1) + 1;
  if (i > 2000) return; // hard cap, see header comment (runaway-I/O defense)
  std::fprintf(stderr, "[tabread] #%lld cluster=%s ea=0x%X val=0x%X fn=%s ra=%p\n",
               i, rt_tabread_cluster(ea), ea, val, fn, ra);
  std::fflush(stderr);
}
#endif

// ══ r23-w76 DRIVER: RT_TABREAD2 — a SECOND, independently env-gated cluster set riding the SAME
// PPC_LOAD_U32 hook w75's RT_TABREAD already shipped (LAWS I4: one macro definition per symbol,
// so a NEW PPC_LOAD_U32 redefinition is not possible — this extends the existing body instead,
// additively, with zero edits to RT_TABREAD's own clusters A-E or its counter). Targets 0x880E4860's
// two fixed tables + gating flag (bank/r23/w76/PREREG_w76.txt sec 0.1(b) — re-derived directly from
// out_reco/ppc_recomp.12.cpp:2149-2277, corrects read_refusal_w75's own prose base which pointed at
// an unrelated address). HARNESS-ONLY, NEVER SHIP. Pre-registered before any build/drive.
#ifndef RT_TABREAD2_ON
static inline bool rt_tabread2_enabled(){
  static int v = std::getenv("RT_TABREAD2") ? 1 : 0;
  return v != 0;
}
// cluster F: 0x885C5C54..0x885C5CFC, stride 8, the 8-iter loop's first (nonzero-check) table read.
// cluster G: 0x885C1A24..0x885C1A78, stride 4, the second (==64 check) table read.
// cluster H: 0x885AD50C, the -10996(r27) flag gating the conditional call to sub_880901B8.
//
// ══ r23-w77 DRIVER CONSOLIDATION (bank/r23/w77/CONSOLIDATION_w77.md): clusters F/G are ANSWERED
// (w76's own consumer census — dominant reader sub_88090480 + Outer_Fsm direct reads — routed to
// READ/NAMER as new evidence, not a live question this window) — compiled OUT via RT_TABREAD2_FULL
// below. Cluster H (the release-gating flag) stayed SILENT both w76 legs with no independent
// combat content on either route — THIS window re-arms it under the SAME combat leg as
// RT_WITNESS3_GATE (0x88133A60), since both are "may be combat-gated" hypotheses sharing one
// dwell (mission step 3 ride-along) — stays unconditional. Bounds byte-for-byte UNEDITED.
// Build with -DRT_TABREAD2_FULL=1 to restore F/G.
#ifndef RT_TABREAD2_FULL
#define RT_TABREAD2_FULL 0
#endif
#define RT_TABREAD2_HIT(e) ( \
    (RT_TABREAD2_FULL && ( \
    ((e) >= 0x885C5C50u && (e) <  0x885C5D00u) || \
    ((e) >= 0x885C1A20u && (e) <  0x885C1A80u) )) || \
    ((e) >= 0x885AD50Cu && (e) <  0x885AD510u) )
static inline const char* rt_tabread2_cluster(uint32_t ea){
  if (ea >= 0x885C5C50u && ea < 0x885C5D00u) return "F";
  if (ea >= 0x885C1A20u && ea < 0x885C1A80u) return "G";
  if (ea >= 0x885AD50Cu && ea < 0x885AD510u) return "H";
  return "?";
}
static inline void rt_tabread2_hit(uint32_t ea, uint32_t val, const char* fn, const void* ra){
  static std::atomic<bool> armed{false};
  if(!armed.exchange(true)) std::fprintf(stderr, "[tabread2] ARMED\n");
  static std::atomic<long long> n{0};
  long long i = n.fetch_add(1) + 1;
  if (i > 2000) return; // hard cap, same defense as RT_TABREAD
  std::fprintf(stderr, "[tabread2] #%lld cluster=%s ea=0x%X val=0x%X fn=%s ra=%p\n",
               i, rt_tabread2_cluster(ea), ea, val, fn, ra);
  std::fflush(stderr);
}
#endif

// ══ r23-w76 DRIVER: RT_WITNESS3 — two ENTRY/MID-BODY register taps (RT_WITNESS_ENTRY's own proven
// shape: ctx.lr + __builtin_return_address(0) + explicit args, no address guard needed since the
// targets are per-object/register values, not fixed memory — PREREG_w76.txt sec 0.1(c)/(d)). Call
// sites are ONE LINE each, inserted at their own function's top/merge point in out_reco/
// ppc_recomp.19.cpp (sub_881526C0 entry) and ppc_recomp.17.cpp (sub_88133A60 loc_88133A9C) — pure
// read-only observation of already-computed values, zero altered guest state (LAWS T2/T8).
// HARNESS-ONLY, NEVER SHIP.
#ifndef RT_WITNESS3_ON
static inline bool rt_witness3_enabled(){
  static int v = std::getenv("RT_WITNESS3") ? 1 : 0;
  return v != 0;
}
#define RT_WITNESS3_ON() (__builtin_expect(rt_witness3_enabled(), 0))
static inline void rt_witness3_taskq_hit(uint32_t guest_lr, uint32_t fn, uint32_t id, uint32_t arg,
                                          const void* host_ra){
  static std::atomic<bool> armed{false};
  if(!armed.exchange(true)) std::fprintf(stderr, "[witness3] TASKQ ARMED\n");
  std::fprintf(stderr, "[witness3-taskq] lr=0x%X fn=0x%X id=%u arg=0x%X ra=%p\n",
               guest_lr, fn, id, arg, host_ra);
  std::fflush(stderr);
}
#define RT_WITNESS3_TASKQ(fn, id, arg) do { \
    if (RT_WITNESS3_ON()) rt_witness3_taskq_hit((uint32_t)ctx.lr, (uint32_t)(fn), (uint32_t)(id), \
                                                 (uint32_t)(arg), __builtin_return_address(0)); \
  } while (0)
static inline void rt_witness3_gate_hit(uint32_t guest_lr, uint32_t this_ptr, uint32_t count,
                                         const void* host_ra){
  std::fprintf(stderr, "[witness3-gate] lr=0x%X this=0x%X count=%u ra=%p\n",
               guest_lr, this_ptr, count, host_ra);
  std::fflush(stderr);
}
#define RT_WITNESS3_GATE(this_ptr, count) do { \
    if (RT_WITNESS3_ON()) rt_witness3_gate_hit((uint32_t)ctx.lr, (uint32_t)(this_ptr), \
                                                (uint32_t)(count), __builtin_return_address(0)); \
  } while (0)
#endif

// ══ r23-w79 DRIVER: RT_WITNESS4 — ONE mid-body tap in Class127_Ctor (0x881286D0,
// out_reco/ppc_recomp.16.cpp, loc_881288DC) reporting the frame-arm literal (632/692/800/850/
// 966/1032) the compare-ladder just assigned into state_block[156] — the SAME read already
// computed by the existing, untouched `stw r11,156(r31)` (LAWS T2/T8: tap AFTER, never before or
// instead). Answers bank/r23/w79/read_class127_w79.md sec 4 recommendation (a) directly: arm
// literal 1032 corresponds EXACTLY to the this[116]==977 compare (loc_881288CC) that also sets
// state_block[168]=1 (the ONE gate condition that makes a kind=3 AllocRecord call reachable at
// all, per the READ lane's own full-body read) — so a leg that sees arms 632/692/800/850/966 but
// NEVER 1032 directly falsifies (or narrows) the join's "continues reset the stage clock, never
// reaching frame 977" hypothesis without needing the countdown-rate unknown resolved at all.
// Read-only, zero altered guest state (LAWS T2/T8) — the object pointer (this=r30 at Ctor entry,
// still live in r31's caller-frame companion r30 at this program point) and the assigned arm
// literal are reported per hit with no cap needed (construction is rare — at most 8 possible
// Class127 spawns exist in the WHOLE stage-0 timeline per read_classid_id127_w79.log, so this can
// never be a hot loop). HARNESS-ONLY, NEVER SHIP.
#ifndef RT_WITNESS4_ON
static inline bool rt_witness4_enabled(){
  static int v = std::getenv("RT_WITNESS4") ? 1 : 0;
  return v != 0;
}
#define RT_WITNESS4_ON() (__builtin_expect(rt_witness4_enabled(), 0))
static inline void rt_witness4_ladder_hit(uint32_t guest_lr, uint32_t this_ptr, uint32_t arm,
                                           const void* host_ra){
  static std::atomic<bool> armed{false};
  if(!armed.exchange(true)) std::fprintf(stderr, "[witness4] ARMED\n");
  const char* frame =
    (arm == 632) ? "592" : (arm == 692) ? "644" : (arm == 800) ? "719" :
    (arm == 850) ? "776" : (arm == 966) ? "899" : (arm == 1032) ? "977(THE ONE)" : "?";
  std::fprintf(stderr, "[witness4-ladder] lr=0x%X this=0x%X arm=%u frame=%s ra=%p\n",
               guest_lr, this_ptr, arm, frame, host_ra);
  std::fflush(stderr);
}
#define RT_WITNESS4_LADDER(this_ptr, arm) do { \
    if (RT_WITNESS4_ON()) rt_witness4_ladder_hit((uint32_t)ctx.lr, (uint32_t)(this_ptr), \
                                                  (uint32_t)(arm), __builtin_return_address(0)); \
  } while (0)
#endif

// ══ r23-w81 DRIVER: RT_VALTAP — the value-tap chain on the frame-977 Class127 instance
// (bank/r23/w81/PREREG_w81.txt). Extends w79's RT_WITNESS4 registration point (Class127_Ctor,
// 0x881286D0, loc_881288DC — SAME line, SAME two already-computed registers, RT_WITNESS4 itself
// left byte-for-byte untouched) with an independent identity table mapping each constructed
// instance's `this` pointer to the timeline frame that produced it. Four independent runtime taps
// land inside Class127_Ctor_Act (0x88126298, out_reco/ppc_recomp.16.cpp), each an unconditional
// read of an already-computed value at its own existing compare/load site — LAWS T2/T8: no
// existing store, width or order changed anywhere. Reported for EVERY Act call of EVERY
// registered instance (arm-symmetric — LAWS G2/M5, never filtered to 977 in the tap itself, so
// the instrument cannot be silently blind to the other five arms and the 977 reading can be
// checked against a live population rather than reasoned from a single starved sample). The
// suppress tap is the instrument's OWN positive control (LAWS M4/M5): it is UNCONDITIONAL, so it
// MUST fire on every Act call if Act ticks at all (already independently proven by RT_INDCENSUS,
// w78/w80) — a leg where it prints zero total hits means the tap itself is dead/misplaced, not
// that Class127 is quiet. Identity note (source-verified this window, not inherited): ctx.r30 is
// REASSIGNED mid-body in Class127_Ctor_Act (`add r30,r11,r24`) well before the tail conditions,
// so it is UNSAFE as a runtime-tap identity register; ctx.r31 (the state_block pointer) is
// assigned exactly once, at entry, and never reassigned anywhere in the body (verified by
// exhaustive grep of the function's own line range) — the stable identity source used by every
// runtime tap is a single extra RT_VALTAP-gated load of `state_block[0]`, which the Ctor itself
// already writes as `this` (`stw r30,0(r31)`, read_class127_w79.md sec 1.1/1.3) — same numeric
// identity space as the Ctor-side registration, recovered without touching ctx.r30 at all.
// HARNESS-ONLY, NEVER SHIP.
#ifndef RT_VALTAP_ON
static inline bool rt_valtap_enabled(){
  static int v = std::getenv("RT_VALTAP") ? 1 : 0;
  return v != 0;
}
#define RT_VALTAP_ON() (__builtin_expect(rt_valtap_enabled(), 0))

struct RtValtapSlot { std::atomic<uint32_t> this_ptr{0}; const char* frame = "?"; };
static inline RtValtapSlot* rt_valtap_table(){
  static RtValtapSlot table[16]; // 2x headroom over the 8 possible Class127 spawns (read_classid_id127_w79.log)
  return table;
}
static inline const char* rt_valtap_frame_of_arm(uint32_t arm){
  return (arm == 632) ? "592" : (arm == 692) ? "644" : (arm == 800) ? "719" :
         (arm == 850) ? "776" : (arm == 966) ? "899" : (arm == 1032) ? "977" : "?";
}
static inline const char* rt_valtap_lookup(uint32_t this_ptr){
  RtValtapSlot* t = rt_valtap_table();
  for (int i = 0; i < 16; i++) {
    if (t[i].this_ptr.load(std::memory_order_relaxed) == this_ptr) return t[i].frame;
  }
  return "UNREG";
}
static inline void rt_valtap_register(uint32_t this_ptr, uint32_t arm){
  const char* frame = rt_valtap_frame_of_arm(arm);
  RtValtapSlot* t = rt_valtap_table();
  for (int i = 0; i < 16; i++) {
    uint32_t expect = 0;
    if (t[i].this_ptr.compare_exchange_strong(expect, this_ptr, std::memory_order_relaxed)) {
      t[i].frame = frame;
      std::fprintf(stderr, "[valtap-register] slot=%d this=0x%X frame=%s\n", i, this_ptr, frame);
      std::fflush(stderr);
      return;
    }
    if (expect == this_ptr) return; // already registered -- record once
  }
  std::fprintf(stderr, "[valtap-register] TABLE FULL this=0x%X frame=%s -- NOT RECORDED\n", this_ptr, frame);
  std::fflush(stderr);
}
#define RT_VALTAP_REGISTER(this_ptr, arm) do { \
    if (RT_VALTAP_ON()) rt_valtap_register((uint32_t)(this_ptr), (uint32_t)(arm)); \
  } while (0)

// ── r23-w82 DRIVER: CONSOLIDATION — w81's own SCORE (drive_w81_SCORE.md sec 1.5) closed all
// eight program-order conditions definitively ("THE FULL GATE CHAIN CLOSES... ending in the
// kind=3 PoolE1A0_AllocRecord call itself actually firing"); the five runtime-hit taps below have
// answered their own question. Per the mission brief's own OWED w82 item ④ ("weigh RT_VALTAP
// consolidation before any new instrument"), their BODIES are compiled out by default this window
// — zero runtime env-check branch, zero string-literal cost, zero call overhead in the shipped
// binary — leaving only a one-line flip to restore them verbatim if a future window needs this
// exact chain again on a different route. RT_VALTAP_REGISTER (the identity table) is UNCHANGED
// and stays live — it is a no-cost mechanism a future window may still want. PREREG_w82.txt sec 3.
#ifndef RT_VALTAP_KEEP_W81_TAPS
#define RT_VALTAP_KEEP_W81_TAPS 0
#endif
#if RT_VALTAP_KEEP_W81_TAPS
static inline void rt_valtap_hit(const char* tag, uint32_t this_ptr, int64_t v1, int64_t v2){
  static std::atomic<bool> armed{false};
  if(!armed.exchange(true)) std::fprintf(stderr, "[valtap] ARMED\n");
  static std::atomic<long long> n{0};
  long long i = n.fetch_add(1) + 1;
  const char* frame = rt_valtap_lookup(this_ptr);
  std::fprintf(stderr, "[valtap] #%lld tag=%s this=0x%X frame=%s v1=%lld v2=%lld\n",
               i, tag, this_ptr, frame, (long long)v1, (long long)v2);
  std::fflush(stderr);
}
// (a) this[0]&0x400, unconditional -- THE POSITIVE CONTROL.
#define RT_VALTAP_SUPPRESS(this_ptr, bit) do { \
    if (RT_VALTAP_ON()) rt_valtap_hit("suppress", (uint32_t)(this_ptr), (int64_t)(bit), 0); \
  } while (0)
// (b) state_block[112] entry value (v1) and post-decrement value (v2) -- condition (3)'s program point.
#define RT_VALTAP_COUNTDOWN(this_ptr, entryv, postv) do { \
    if (RT_VALTAP_ON()) rt_valtap_hit("countdown", (uint32_t)(this_ptr), (int64_t)(entryv), (int64_t)(postv)); \
  } while (0)
// (c) state_block[168] -- condition (5)'s own compare site.
#define RT_VALTAP_GATE168(this_ptr, v168) do { \
    if (RT_VALTAP_ON()) rt_valtap_hit("gate168", (uint32_t)(this_ptr), (int64_t)(v168), 0); \
  } while (0)
// (d) scene[1460] (v1) / scene[1656] (v2, sentinel -1 = "not reached this call") -- conditions (6)/(7).
#define RT_VALTAP_SCENE(this_ptr, s1460, s1656) do { \
    if (RT_VALTAP_ON()) rt_valtap_hit("scene", (uint32_t)(this_ptr), (int64_t)(s1460), (int64_t)(s1656)); \
  } while (0)
// (e) reaching the existing, untouched sub_880FE1A0 kind=3 call -- condition (8), the mission target.
#define RT_VALTAP_ALLOC(this_ptr) do { \
    if (RT_VALTAP_ON()) rt_valtap_hit("ALLOC_FIRED", (uint32_t)(this_ptr), 0, 0); \
  } while (0)
#else
#define RT_VALTAP_SUPPRESS(this_ptr, bit) do {} while (0)
#define RT_VALTAP_COUNTDOWN(this_ptr, entryv, postv) do {} while (0)
#define RT_VALTAP_GATE168(this_ptr, v168) do {} while (0)
#define RT_VALTAP_SCENE(this_ptr, s1460, s1656) do {} while (0)
#define RT_VALTAP_ALLOC(this_ptr) do {} while (0)
#endif
#endif

#ifndef PPC_LOAD_U8
#define PPC_LOAD_U8(x) *(volatile uint8_t*)(base + (x))
#endif

#ifndef PPC_LOAD_U16
#define PPC_LOAD_U16(x) __builtin_bswap16(*(volatile uint16_t*)(base + (x)))
#endif

#ifndef PPC_LOAD_U32
#define PPC_LOAD_U32(x) ({ \
    uint32_t _tr_e = (uint32_t)(x); \
    uint32_t _tr_v = __builtin_bswap32(*(volatile uint32_t*)(base + _tr_e)); \
    if (__builtin_expect(rt_tabread_enabled() && RT_TABREAD_HIT(_tr_e), 0)) \
      rt_tabread_hit(_tr_e, _tr_v, __func__, __builtin_return_address(0)); \
    if (__builtin_expect(rt_tabread2_enabled() && RT_TABREAD2_HIT(_tr_e), 0)) \
      rt_tabread2_hit(_tr_e, _tr_v, __func__, __builtin_return_address(0)); \
    _tr_v; })
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

// ══ r23-w56 F1 DRIVER: RT_FLAGTAP — watchpoint census of every guest store touching the
// 0x887AD500-0x887AD560 neighbourhood (pauseFlag 0x887AD534 / pauseLatch 0x887AD538 / the
// present-fnptr pair at 0x887AD524/28, with margin). HARNESS-ONLY, NEVER SHIP.
// Mission: bank/r23/w55/f1_drive_PLAN_w55.md (the second-writer watchpoint plan); pre-registered
// in bank/r23/w56/PREREG_w56.txt before any drive. Default-off — RT_FLAGTAP_ON() below is a
// getenv check cached once per translation unit (the same pattern as every other RT_ tap in this
// tree, e.g. merged_game.cpp's RT_NOPAUSE/RT_FB90 static-local caches); with the env unset this
// costs one already-cached branch per store, campaign-standard overhead. Purely additive: no
// guest-visible value/width/order changes (the tap observes `x`/`y` and prints, then the original
// store executes exactly as before — LAWS T2/T8 preserved).
// Identification uses __func__ (the compile-time name of the enclosing PPC_FUNC — exact, no
// symbol table needed, correct at every one of this macro's expansion sites including host-side
// helpers that never see `ctx`, e.g. merged_shell.cpp's rt_stf32) for WHO PERFORMS THE STORE, plus
// __builtin_return_address(0) (the host address inside whichever function CALLED the storing
// function) for cross-reference against the already-banked ctx.lr evidence
// (f1_secondwriter_read_w55.md §1). ARMED banner (LAWS M+) fires once, the same gate as any hit,
// so a leg with zero extra hits is distinguishable from a dead/unlinked tap.
// ⚠ CALIBRATED, THIS WINDOW (r23-w56 leg m1arc_w56): the plan's original 96-byte margin
// (0x887AD500-0x887AD560) swept in two hot, UNRELATED per-frame fields — 0x887AD518 (a
// monotonic counter inside sub_88090480, ~200K hits in one partial arcade leg) and 0x887AD540
// (a per-frame toggle inside sub_8808FB90, ~53K hits) — neither in the pauseFlag/pauseLatch
// neighbourhood the mission cares about. Narrowed to the plan's own core range with a small
// margin (0x887AD528-0x887AD53C inclusive => half-open to 0x887AD540), which still covers the
// present-fnptr pair (524/528 — note 524 itself is JUST outside; widen back if a future leg
// needs it) and both mission words (534/538). This ALSO still captures the ALREADY-KNOWN,
// expected per-frame self-clear of pauseLatch (538=0) inside sub_8808FB90 on every normal-running
// frame (read_train_mechanism_w52.md §4's own consumer code) — that is harmless, high-volume, and
// declared here so it is not mistaken for a novel finding when it recurs.
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
