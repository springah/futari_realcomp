# NOTE — boot-logo + NOW-LOADING overlay family: naturalization draft (2026-08-14, agent pass)

Status: **FULLY INTEGRATED 2026-08-14 NIGHT — ALL SIX fns (decomp/shell/logo_indicator.cpp).**
Logo_Build lowered same night from a full generated-body read; §7 is PAID. Further corrections
earned there: the element name/clip addresses also carry the +0x40 shift (real: cave
0x8204F794/0x8204F79C, M2 0x8204F73C/0x8204F7A4, r28=0x8204F7A4) and sub_8217AA80 takes THREE
args (elem, container, stack-copied name via sub_82060190) — §3's two-arg row was wrong.
⚠ TWO CORRECTIONS earned by the integration's full generated-body read (trust the TU over §1):
(1) the §1 float-constant table is +0x40 OFF — real pool base 0x8204F7B0 (step 0x8204F838,
logo scale 0x8204F8D4, indicator alpha scale 0x8204F868, clip consts 0x8204F824/28/2C, unity
0x8203AAB4, zero 0x82045508); (2) §2.6's layout-bit sense is INVERTED — the A/wide clip
constant is selected when FX+0x5A8 bit0 is CLEAR. Ground truth = the
generated recomp (never Ghidra alone), E58 discipline applied (every callee's r3..r10 walked
back). Companion docs: NOTE_fnf12_loading_overlay.md, ATLAS_scene_system.md §8.5-8.10,
SPEC_shell_compose_1to1.md.

## 0. Ground truth + TRUE BOUNDARIES (recompiler is the authority, and it disagrees with Ghidra)

| symbol | file | lines | role |
|---|---|---|---|
| sub_821D1890 | shell/gen/ppc_recomp.36.cpp | 7424-7822 | BUILD |
| sub_821D1780 | ppc_recomp.36.cpp | 7267-7415 | FADE-IN 60f |
| sub_821D1740 | ppc_recomp.36.cpp | 7229-7264 | HOLD 120f |
| sub_821D1670 | ppc_recomp.36.cpp | 7105-7220 | FADE-OUT 60f |
| sub_821CCC48 | ppc_recomp.35.cpp | 12478-12643 | indicator SHOW/HIDE (LEAF, zero calls) |
| sub_821CD120 | ppc_recomp.35.cpp | 13209-13412 | indicator per-frame ramp/hider |

**Ghidra's `LAB_821D1740` / `LAB_821D1670` are REAL FUNCTIONS** — the recompiler (driven by
the real .pdata table) materializes each as its own PPC_FUNC_IMPL with prologue/epilogue/blr.
The 4-byte `.long 0x0` gap stubs (sub_821D173C, sub_821D188C, sub_821CD11C) mark the true
boundaries from the recompiler side and independently re-confirm **no function exists at
0x821CD140** (the known Ghidra mis-bound; real entry 0x821CD120).

## 1. Field/constant tables

Indicator: +0x5C elem(loading) · +0x70 built · +0x71 enable · +0x78 f32 alpha.
Logo task: +0x48 state-fn · +0x58 container · +0x5C cave · +0x60 M2 · +0x64 count ·
+0x68 skip/restart byte (see oddity 4.3).
Element: +0x0C hide · +0xFC packed RGBA (LOW BYTE = alpha) · +0x10C/+0x110 record begin/end
(stride 0x20C). Record: +0x1DD clip-running · +0x1E0/+0x1E4 clip start/end (f32).
Float consts: 0x8204F878=1/60 · 0x8204F914=128.0f (logo byte scale, 0x80=unity) ·
0x8204F8A8=255.0f (indicator alpha scale) · clip window 0x8204F864=384.0f(wide) /
0x8204F86C=256.0f(narrow) / 0x8204F868=296.0f(end, both). Widescreen byte DAT_821ECF39;
layout bit = ((*(DAT_821F858C)+0xC)+0x5A8)&1.

## 2. Behavioral drafts (agent-verified against generated bodies; helpers must be lowered to
## concrete ctx bridging at integration — see §7)

- **Logo_Build (821D1890)**: 4× sub_82079FD8 allocs (28/144/72/~20) → identity-matrix group
  (vt 0x820514B4, 0x1C) + transform+clip group (vt 0x820514C0, 0x48, SPEC §2.1/2.2 shapes
  byte-exact) as generic scaffolding; ONE movie container (144B, ctor sub_8217A960, bind
  sub_8217B6A8 to task+0x4C asset, hide=0 PERMANENT); elements "cave"(name 0x8204F7D4, clip
  0x8204F7DC) → task+0x5C and "M2"(0x8204F77C, 0x8204F7E4) → task+0x60 via sub_8217AA80 +
  sub_8217C468(elem+0x10, clip, 0) — BOTH born hidden (elem+0x0C=1) with clip stopped
  (rec+0x1DD=0). Ends cnt=0, state=0x821D1780. Published LRs per call banked in the agent
  report (0x821D18A8/198C/19D8/1A78 allocs; 1998 ctor; 19AC bind; 1A08/1AA0 elems;
  1A28/1AC0 clips). Task-local scaffold slots +0x40/+0x50/+0x54 = naming gap (behavior exact).
- **Logo_FadeIn (821D1780)**: cnt==0 → unhide cave + rec+0x1DD=1. Skip byte task+0x68: if set,
  CLEAR it + cnt=60. a=(u8)(cnt·(1/60)·128.0f) [fctidz truncation]; modulate cave via
  sub_821796B0(cave+0x10, (a,a,a,0x80)) lr=0x821D1850. cnt>60 → cnt=0, state=0x821D1740.
- **Logo_Hold (821D1740)**: skip byte read, cnt=120 forced, NOT cleared. cnt<120 return;
  else cnt=0, state=0x821D1670. No colour writes.
- **Logo_FadeOut (821D1670)**: skip byte read, cnt=60 forced, NOT cleared. a'=(u8)(0x80-a)
  (subfic-exact); modulate lr=0x821D1700; cnt>60 → state=0x821D1540 (CAVE→M2 swap, out of
  scope). No hide/unhide.
- **Indicator_Tick (821CD120)**: elem=self+0x5C, null-guard. enable(+0x71)!=0: ramp alpha UP
  by 1/60 clamp 1.0, modulate. else if alpha>0: ramp DOWN clamp 0.0, modulate; at EXACT 0.0f:
  elem reload (lwz r10,92(r31)), hide=1 + rec+0x1DD=0 — the authentic-unreachable store, DO
  NOT "FIX". Modulate = sub_821796B0(elem+0x10, (u8)(alpha·255.0f) | (elem+0xFC&0xFFFFFF00));
  lr = entry+0x90 (up) / entry+0x100 (down).
- **Indicator_ShowHide (821CCC48)**: LEAF. Idempotent on +0x71. ALWAYS re-derives clip window
  (wide&&layoutBit ? 384 : 256 → rec+0x1E0; 296 → rec+0x1E4) on SHOW **and** HIDE. HIDE
  returns without touching hide byte (arms the ramp only); SHOW: hide=0 + rec+0x1DD=1
  instantly. The asymmetry is intentional (ATLAS §8.10.3).

## 3. ABI verdicts

sub_821796B0 takes (r3=elemCtx, r4=packedRGBA) ONLY — r5..r11 at every call site are dead
leftovers (each caller reloads what it needs from memory after; SPEC §5.5 confirms 2 params).
Per the task_kill/driver-shape-A precedent, drafts deliberately do NOT mirror the dead
volatiles — documented deviation, not an oversight. Logo_Build's r29/r30/r31 nonvolatile
carries mirror 1:1. **Zero leftover-consumed-argument hazards found in this cluster.**

## 4. Preserved oddities (do not fix)

1. Empty 4-byte gap stubs before three entries (recompiler artifacts, uncallable).
2. The record-count `twi` trap: the recompiler EMITS NO INSTRUCTION for it anywhere in this
   cluster (9+ sites verified) — control falls through. Drafts match (doc-only no-op).
3. ★ task+0x68 skip byte: CLEARED only by FADE-IN; HOLD and FADE-OUT force the fast-forward
   but never clear — once set during hold/fade-out it stays set (setter not decoded this
   pass; reads as the press-START-skip arm). Preserve the asymmetry exactly.
4. 0x80-unity (logo RGB multiply) vs 0xFF-alpha (indicator) scales are two REAL different
   mechanisms — never unify.

## 5. Hook ownership (the link-shadow rule — checked BEFORE drafting this time)

- sub_821CD120: OWNED by out_reco/merged/merged_shell.cpp:4273 (RT_D1PROBE wrapper) →
  decomp must be **PPC_FUNC_IMPL(__imp__sub_821CD120)**.
- sub_821CCC48: OWNED by shell/gen/rt.cpp:894-910 (LP2_SHOWHIDE macro) →
  decomp must be **PPC_FUNC_IMPL(__imp__sub_821CCC48)**.
- The four logo fns: unowned → plain PPC_FUNC. decomp_*.o links FIRST so all six win; the
  owners' telemetry keeps firing around the natural bodies. Rollback = delete the TU.

## 6. Gate plan

(1) map-file link-win check (all six resolve to the new decomp_*.o — DRIVER_NOTES §2
technique). (2) nav_boot_to_topmenu drive (the logo FSM + indicator SHOW→ramp→HIDE run on
every boot). (3) RT_EXPECTCENSUS control-vs-pilot: [expcen] stream canonical-identical;
a pilot-only MISS on cave/M2/loading = regression — EXCEPT misses aligned with the
821D1670→821D1540 swap boundary or a CCC48 HIDE arm (authored transients; pair with
RVK_TITLEPROBE). (4) one-shot live-fire canary on all six before trusting stream equality
(positive control). (5) control build = relink minus the new TU, DRIVER_NOTES §3 style.
⚠ expcen_boot.sh drives futari_combined.exe — fine for the ship gate; a merged-exe arm needs
its own driver if ever wanted. ⚠ The M2-side stages (821D1540/1500/1408) run one stage later
on the same boot — out of scope; don't let their divergence fail THIS cluster's gate.

## 7. Integration TODO (the actual leg)

Lower the draft helpers to house-style ctx bridging (exact r3..r6 + published lr at each of
Logo_Build's 9 boundaries, from the generated lines cited in §0's table); new TU
decomp/shell/logo_indicator.cpp; registry rows; run the §6 ladder; ledger.
