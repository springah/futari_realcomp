# NOTE_fnf_shell_defects.md — friends-and-family shell defect inventory

Goal (user directive 2026-07-26): shell/menus/interface good enough to ship a test build to
friends & family and collect their logs. This note is the running defect ledger for that goal.
Method per doctrine: ship-path first, oracle in hand before theorizing, instruments presumed
lying until positive-controlled, texel-diff acceptance.

## 2026-09-06 — FNF-14 (USER OBS, unattributed): "I miss the loading screens"
- User note during r23-w93: the NOW LOADING screens are missed in current builds — either absent or too brief
  to register. No ledger entry records a deliberate removal; the element is a PERMANENT shell task (FNF-12 work).
- FIRST STEP = MEASURE, not fix: (a) RT_INDCENSUS witness of the NOW LOADING task's tick/draw on a boot + a
  stage-transition route; (b) PrintWindow burst at boot and at the first stage handoff (display ON); (c) the same
  route on the 360 oracle (Xenia scripted drive) for frame counts. Then classify: not drawn (defect) vs drawn but
  short because the port loads faster (a FEEL decision for the user — an artificial hold is never a silent fix;
  360 pacing is authentic per epozzobon).
- **USER CLARIFIED 09-06: NOT "too brief" — "any of the now loading — they seem to not appear even when loading,
  instead it's black screen."** So the load phase still takes visible time and the screen is BLACK during it: the
  NOW LOADING element is not drawn, or is drawn but not presented/composed, during load phases. Reclassified as a
  DEFECT (was: feel question). Attended item stays (which loads: boot, stage handoff, stage→stage, replay?).
- Suspect classes (from the FNF-12 history, unverified): (1) the layer-seg compose never covering loading-phase
  pixels (the 07-28 "stale persisted loading-phase pixels" note points at the compose treating the load phase as
  empty); (2) the loading task's draw gated on a flag the port never sets during its (faster) load; (3) a
  fade-to-black that starts before the load draw and is never released until the next scene's first frame.
  Measure (a)/(b)/(c) above discriminates these: if the task ticks AND draws but the frame is black → compose/
  present; if it ticks but does not draw → gate flag; if it never ticks → scheduling.

## 2026-09-20 — ★★★★★ FNF-14 CLOSED: NOW LOADING black screen = a 0x40-LOW FLOAT POOL in the readable-C
## logo/indicator TU (decomp regression, 08-14), NOT a compose defect. Fix = six constants. Logos fade again too.
**Attended realcomp day (user pick: FNF-14 first, unattended measurement). Measure-first plan (a)/(b) executed on the
shipped build/futari_combined.exe (Sep 13):**
- RT_LOADPROBE2: guest lifecycle intact — SHOW at t=0 (lr 0x821CD478), HIDE at t=1.5–1.8 s (lr 0x821CE504, root
  boot-wait). No watchdog hide. Same as the 07-28 measurement.
- RT_NVKPNG=2 frame dumps (display-independent; PrintWindow cannot see the window from this harness — `no window`):
  EVERY frame f2..f236 mean luma 0.00; positive control = CAVE logo frames at 253.29. The load phase is black on glass.
- RT_NVK=1 trace: the guest DOES emit the overlay — 13 textured quads/frame from f12 (atlas 0x1810000, prim 5, n=4, st 24).
- RT_NVKDBG=1 RT_NVKDBGEVERY=5: the renderer DOES batch them (SEG [0,13) on the display target) — but every vertex
  colour is 00FFFFFF: **alpha 0**. Not a compose/persist class (suspect 1 REFUTED); the element is drawn transparent.
- RT_LOADPROBE: elem0(+0x5C) hide=0 colorFC=0x80808000 (alpha=0) for the whole window, then hide=1 at alpha 0. On 07-28
  the same probe read a full 8→255→0 ramp. **The per-frame ramp stopped ramping between 07-28 and now.**
- RT_D1PROBE + RT_UPCANARY: sub_821CD120 (Indicator_AlphaRamp, readable C in futari_decomp decomp/shell/
  logo_indicator.cpp) IS called every frame (cd120 #74 by the hide), ind+71=1, ind+78 stays 0.000. The body runs and adds
  nothing ⇒ the STEP it reads is ~0.
**ROOT CAUSE (script-verified, not inferred):** the generated body materialises its float pool as `lis r11,-32251 ;
addi r11,r11,-2064` = 0x82050000 − 0x810 = **0x8204F7F0**. The 08-14 TU header claimed "real pool base 0x8204F7B0"
(0x40 low — the SAME shift class commit e127c14 fixed on 08-15 for Logo_Build's four name keys, but never for the six
float constants). default.img.bin at the TU's addresses: F_FADESTEP 0x8204F838 = **2.3e-10** (real 0x8204F878 = 1/60),
F_ALPHASCALE 0x8204F868 = 296.0 (real 0x8204F8A8 = 255.0), F_LOGOSCALE 0x8204F8D4 = 40.0 (real 0x8204F914 = 128.0), clip
window 0.0/−1.0/4.0 (real 0x8204F864/68/6C = 384/296/256). So the indicator alpha grew by 2.3e-10 per frame: never
visible. The logo FSM used the same step ⇒ logos popped instead of fading (this fix restores their 60-frame ramps).
Every other shell TU that touches this pool anchors it at 0x8204F7F0 (menu_base_states FTAB, options_panel_base,
options_maniac_hub, psb_core) — isolated to logo_indicator.cpp.
**FIX (futari_decomp, decomp/shell/logo_indicator.cpp):** the six F_* constants moved +0x40 to the lis/addi-derived
addresses; the Logo_Build +56 read (−1.0f no-clip x1/y1), which the 08-15 fix had aliased to F_CLIP_END only because
the wrong base happened to land on 0x8204F828, gets its own F_NOCLIP = 0x8204F828. Registry provenance (0x821CD120) and
NOTE_logo_indicator_naturalization.md carry the correction. No renderer change. Host exe rebuilt (host-only stage of
build_win_dll.sh; module DLLs untouched — shell-only TU).
**VERIFIED (same instruments, rebuilt exe):** RT_LOADPROBE elem0 alpha 51→102→148→199→237→254→255 (hold) → after HIDE
233→165→106→38→0 then hide=1 (the authentic 07-28 lifecycle). Frame dumps: f20–f100 lit (Now Loading ··· + ring
cluster, bottom-right, /c/tmp/fnf14/g/png/nvk_f60.png), CAVE fade-in f100→f160 (8→253, 60 frames), hold, fade-out
f280→f340, M2 fade-in f350→f410, hold, fade-out f530→f590, title f600→f660. Both boots' hide timing unchanged (1.56/1.81 s).
**OPEN / user eyes:** (1) the boot overlay now shows for ≈1.5 s + 1 s fade-out because the port loads fast — on the 360
it holds longer; that is a FEEL question (epozzobon: pacing is authentic, no artificial hold without a ruling). (2) The
user said "ANY of the now loading" — stage-transition loads inside the GAME module were not measured today; if they are
still black, that is a separate path (game-module loader), re-measure with the same ladder. (3) The 08-15 commit's
verification ("CAVE f285-330") was taken with the wrong step — its timings are superseded by the ones above.
**Harness notes:** Git-Bash `sed -i` strips CR from CRLF files (re-add with `sed 's/$/
/'` or edit via python bytes);
`taskkill //F` under MSYS_NO_PATHCONV=1 is NOT converted — use PowerShell Stop-Process; the MSVC INCLUDE env must be
sourced (bank/r23/w30/w30_toolchain_env.sh) before build_win_dll.sh or every TU fails on <cstdint>.

## 2026-07-31 — ★★★★★ RANKING SQUARE: THE DROP-SHADOW RING IS **EXONERATED**; the square lives
## INSIDE THE ROM'S OWN RENDER TARGET (all four handed hypotheses falsified)

**Handed to this leg:** "the shell's window drop-shadow (FUN_82182008, s2B leg 11) renders as a
HARD-EDGED dark rectangle around the ranking plaques", with H1 (VS idx15 not exactly right),
H2 (stride-12 colour decode), H3 (blend 0x07060706 translation), H4 (PS c2 wrong) to
discriminate. **ALL FOUR ARE FALSIFIED, by direct measurement, not by argument.** The defect is
real (it reproduces in display-independent readbacks — see below), but the ring is not its author
and never touches a plaque.

### THE INSTRUMENT THAT SETTLED IT — `RVK_SHADOWDUMP=<everyN>` (default off, `render/vk_render.cpp`)

`[nvkring]` only ever printed GUEST-space vertices, and it self-throttled on a stride-12 counter
whose period (4800) is an **exact multiple of the 8-draw ring**, so *every banked sample since leg
11 was the same strip of the same window* — the plaques' own rings had never been observed because
the census could not see them. (Fixed this leg: period 4800 -> **4793**, prime, so the sample walks
all 8 slots. The corner fans appear in a bank for the first time.) The new `[shdump]` applies the
shell VS's **own** transform — c10..c13, read straight out of the per-draw bank, exactly the matrix
`g_futari_spirv_21` dots against (spirv-dis'd for this leg) — plus the batch viewport, so a log line
states **where on glass** a draw lands. Stride-12 draws additionally print every vertex with colour.
Companion A/B arms: `RVK_RINGOFF=1` (drop every stride-12 draw) and `RVK_MODOFF=<hex blendReg>`
(drop one blend class). All default-off and byte-identical when unset.

### VERDICT — the ring is REGISTER-TRUE AND CORRECT, on glass, measured

Ranking frame f13200/f7680, `RT_NVK=2`, DISPLAY target:
```
d13 vs=15 ps=14 prim=6 n=4 st=12 blend=07060706 vte=43F scr={383.5,39.5..399.5,679.5}
  v0 guest={0.0,-16.0}   scr={383.5,679.5} col=00000000
  v3 guest={640.0,0.0}   scr={399.5,39.5}  col=FF080808     (+ 3 more strips, + 4 corner fans)
d21 vs=35 ps=34 (the ranking PANEL)          scr={399.5,39.5..879.5,679.5}
```
- The ring is **8 draws, once per frame, always around the shell WINDOW** — the four strips land on
  the 16 px band immediately OUTSIDE the panel (383.5-399.5, 879.5-895.5, 23.5-39.5, 679.5-695.5).
  On the ranking screen there are **exactly 8 stride-12 draws per frame on every one of the 150
  dumped frames** — zero extra rings, so the ring never draws around a plaque. (The guest's tate
  space is rotated: guest x -> screen y. 16 guest px = 16 screen px, 1:1, authentic.)
- **H1 dead:** vs=15 / ps=14 are selected on every ring draw; the leg-11 tiebreak is doing its job.
  `spirv-dis` of idx15 (`g_futari_spirv_21`): inputs Location 0 + **Location 8**, writes
  interpolator 16 = `max(colour,colour)`, **no `Flat` decoration anywhere** — the gradient is
  smooth-interpolated by construction. idx14 (`g_futari_spirv_13`) is exactly `out = interp16 * c2`.
- **H2 dead:** the stride-12 decode puts the colour dword at Vraw+12 and the pipeline reads it as
  `VK_FORMAT_B8G8R8A8_UNORM` at offset 12 — correct for a big-endian D3DCOLOR after `gbe`. The
  per-vertex dump shows **00000000 on both outer verts and FF080808 on both inner verts** of every
  strip, i.e. the gradient survives all the way to the vertex buffer.
- **H3 dead:** 0x07060706 decodes to SRC_ALPHA / INV_SRC_ALPHA, ADD, on both colour and alpha —
  the textbook alpha blend, and it matches the SDK's translation of the same register.
- **H4 dead:** `c2 = {1.000, 1.000, 1.000, 1.000}` on every ring draw on every ranking frame.
- ★ **AND IT IS VISIBLE, SOFT, AND 16 px WIDE ON GLASS.** Luma across the left strip, readback
  f3180, median of rows 200-500: `x=383:60.4  387:42.8  391:31.0  395:17.2  398:9.7 | x=399 panel`.
  A monotone 16 px fade to near-black at the panel edge. **That is the leg-11 win rendering exactly
  as designed** — it is also the no-regression gate for this leg, and it passes.

### WHERE THE SQUARE ACTUALLY IS — inside the ROM's own 640x512 target, at the row pitch

The shell's DISPLAY draw list on a ranking frame is: background quad, 8 ring strips, **one** panel
quad (vs35/ps34, tex = a RESOLVE, covering the panel exactly), and the rotated side-text glyphs.
There is no shell draw anywhere near the square. So the square must already be in the panel
TEXTURE — and it is. Dumping the chain (`RT_NVKDBG=1 RT_NVKRESWIN=3100:3400 RT_NVKRESEVERY=60`):

- `nvkres_f3180_045A000_640x512.png` — **the ROM's own render target** — carries two straight
  full-height vertical steps at **x=171 and x=443** (Δ = **272**), each a **+24 % brightness jump to
  the right** (median log-ratio +0.218 / +0.213; reproduced at +0.221 / +0.211 on a second boot).
  Nothing else in the frame exceeds 0.10. It is a **cumulative 3-level staircase**, not a shadow:
  x<171 darkest, 171-443 mid, >443 clean, each band ~x0.80 of the next.
- 272 is exactly the ranking **row pitch**: the same Δ shows up on glass as the two horizontal
  steps at screen y = 361 and 633 in the readback.
- Same square in the shell's downstream 640x480 filtered resolve (steps at 177 / 449) and in the
  final display readback -> the whole visible defect is inherited, not added.
- **Positive control (negative result, banked honestly):** `RVK_MODOFF=05000500` skips every
  MODULATE-blend draw (src ZERO / dst ONE_MINUS_SRC_COLOR — the classic sprite-shadow blend, and
  the obvious suspect). The staircase is **UNCHANGED** (+0.221/+0.211 with the class removed).
  That blend class is exonerated too. The author is some other ROM-offscreen draw at the row pitch.

### PRINTWINDOW POSITIVE CONTROL (the instrument this leg's evidence chain rests on)

Because the readbacks first looked clean, PrintWindow was suspected. Controlled in one boot
(`_tmpscripts/shadowprobe.sh` + `shadowcap.ps1`, which also logs z-ordered occluders): 45 window
captures against 625 frame-numbered readbacks. On every static screen the match is **EXACT — mean
abs diff 0.000 over the full 1280x720 RGB** (cap_007/f12330, cap_011/f3570, cap_034/f7710,
cap_038/f13260, cap_043/f14190), occluder list empty throughout. **PrintWindow is faithful here.**
The earlier "clean readback" impression was frame-selection luck: the square only shows while the
1st/2nd rows are on screen, and those phases had not been sampled.

### NO FIX LANDED — deliberately

The prime suspect is dead and the true author is in a different subsystem (a ROM-module draw inside
the game's own offscreen pass), un-named. Per milestone discipline, no swing at an unproven
mechanism. What landed is the instrument that makes the next leg cheap, the census de-aliasing, and
the falsification.

⏭ **NEXT LEG (rewrite BACKLOG accordingly).** Dump the ROM 640x512 target draw-by-draw with a
screen-space transform that is correct for **VTE-OFF** draws (`[shdump]`'s c10..c13 path is only
valid for `vte&1` = matrix class; the ROM's `vte=400` draws output screen pixels directly and this
leg's offscreen rects are therefore NOT trustworthy — fix that first, it is ~5 lines). Then bisect
the staircase by skipping draws until the +24 % step at x=443 vanishes. Suspect shape: a per-row
quad that should hug its row but extends to the target edge, so N rows stack N modulations.

### GATES (final build, both arms)

`bash build_win.sh` 87 obj / `bash _tmpscripts/build_win_abn.sh` 88 obj, both LINK_OK. Six boots
(shadow_c..i, 115-310 s each, up to f18601): **0 VK errors, 0 `[nvktrunc]` truncations, 0 census
dropouts** on every one. Default-off control: unset levers emit 0 `[shdump]` lines.
`RVK_NOSHADOWFIX=1` **DOES NOT HANG on this build** — see below.

### ⚠ THE "NOSHADOWFIX HANGS" REPORT — **NOT REPRODUCED, retract it**

Handed as "a revert lever that hangs is a landmine (~f4200, frame counters stop, window gone,
process alive, no VK errors, no die-loud)". Re-run on the current build, same harness, same NAV:
**RVK_NOSHADOWFIX=1 ran clean to f8701 (150 s), 0 VK errors, no stall, log growing the whole way**
(t=85 f4201 -> t=135 f7201, sampled every 10 s). The banked `shadow_b` log ends at `[nvk] submit
f4201` with no error line and no die-loud — i.e. it looks exactly like a run whose harness DUR
expired and killed the process mid-stream, which is the far cheaper explanation than a deadlock
(all fence waits in this renderer are bounded at 10 s and would have logged a timeout). Treating it
as a landmine is not justified by the evidence. The lever is fine; use `RVK_RINGOFF=1` anyway when
the question is "is the ring the author" — it removes the ring and nothing else, with no
shader-matcher side effects.


<!-- RECOVERED 2026-08-07: this block existed only in a stray copy of this note sitting
     loose on the Desktop, and was never merged here. Its 07-28 strike-2 pivot is cited by
     the project memory but was missing from the tracked note. Merged in date order. -->


## 2026-07-28 latest — user re-test: TWO residuals named precisely
1. **M2-hold ghost persists** (user + re-scan: stationary dark ring, ~150 px constant through the
   bright hold t=6.5-8.4s, one cyan flash f00248; becomes the fade ghost). Guest dismissal proven
   + per-frame clear proven ⇒ mechanism = SELF-SUSTAINING RESTORE LOOP: guest restore draw
   samples resolve 0x723000; our LAYER-SEG resolves write it only PARTIALLY (compdbg: 2-batch
   segs, nonclear=53k px) so the loading-phase ring never leaves the resolve; each frame re-
   imprints it. On hardware the resolve carries the FULL accumulated EDRAM frame. Fix lane:
   make the shell resolve carry the full composed frame (resolve AFTER full accumulation, or
   clear-init the resolve target when the clear byte fires). NEXT INSTRUMENT: RVK_DUMPRES of
   0x723000 during the M2 hold — the ring should be visibly baked in it.
2. **Stray text glyph on TOP MENU** (user screenshot: single 「を」 from the description string
   floating beside Ver1.01) = FNF-7 extra-draw class; RVK_DRAWTRIP instrument is purpose-built
   for it (buffer shell-frame draws, dump when count exceeds N).
Everything else user-confirmed good ("otherwise yep nice").

## 2026-07-28 ~02:05 — GHOST-DRAW FIX FAILED USER ACCEPTANCE = STRIKE 2 ⇒ BACKLOG; PIVOT

User playtest on the fixed build (fix VERIFIED LIVE in the session log: per-draw A fired,
collapse honored — playtest_0728_0201.log): **flicker unchanged. STRIKE 2** on the flicker item
(strike 1 = wait-path cluster 01eee6a). Per the two-strikes rule: NO further legs; item to
backlog for re-ranking. The ghost-draw fix STAYS (register-true, instrument-verified — the
collapse-class draws were real defects; they are not the user-perceived term. Same shape as
strike 1: real fix, wrong dominant term.)

**★ NEW USER CHARACTERIZATION (materially reshapes the item):** flicker is NOT circle-specific —
"press start button flashing also flickers", "main logo sometimes". So: M2 circles + TOP MENU
glyph + PRESS START + title logo = **element-level transient flicker across MANY shell elements**.
The extra-draw arm is now closed (fixed above); what remains is most plausibly element DROPOUT /
partial-frame compose (no missing-draw census was ever run — drawtrip counted EXTRA only), i.e.
the compose-atomicity class. NOTE: user knows this game deeply — the press-start report means
flicker BEYOND its authentic rhythmic blink (do not re-chase the authentic blink, see title-blink
ledger).

**RE-RANK OUTCOME (BACKLOG.md updated):** flicker is no longer chased as its own defect. It is
FOLDED INTO the already-ratified **shell compose 1:1 campaign** (user 07-28 "decomp 1:1 time";
SPEC_shell_compose_1to1.md = the bible; decomp FUN_821CDBE8 family + veil FUN_82182A68,
implement intro/shell compose register-true, retire the heuristic persist/layer-seg compose) —
whose acceptance criteria now explicitly include: no transient flicker on press-start/logo/
circles/glyph over a full intro+TOP MENU soak, judged by the user. Correct-by-construction
replaces whack-a-mole; that honors both the two-strikes rule (different approach) and the ship
gate (menus/shell must be right).

## 2026-07-28 MORNING — RESKEEP=3 FAILED USER ACCEPTANCE ("nope same"); FLICKER PARKED; **PIVOT**

The pixel-proven flash class ([r5pix] partial-frame deliveries) is REAL and is suppressed by
RESKEEP=3 — and the user's perceived flicker is UNCHANGED. **The measured class ≠ the perceived
defect.** RESKEEP=3 unpinned from playtest.sh (lever + census + r5pix + gdprobe all stay in-tree,
default-off, positive-controlled).

**HONEST INSTRUMENT GAP for whoever reopens this:** every overnight instrument observed up to the
resolve/compose layer. The GLASS layer (swapchain present, the 720p->1080p/1920 RVK_WINSIZE window
blit, present-timing interaction) was NEVER directly observed — the display was off all night and
PrintWindow captures white (the banked trap). The perceived flicker may live between resolve and
glass. Do NOT chase this now — recorded as the top lead for whenever the item reopens.

**STATUS: flicker PARKED (not another leg).** Dossier: draw census clean; [r5pix] flash class
proven + suppressible; frame-straddle roster datum for atomic windows (e9c4339); glass layer
unobserved. Per USER DIRECTIVE (bedtime 07-28 + this morning's "PIVOT"): the project moves to the
**decomp→recomp campaign** — wholesale matching decomp/translation (UnleashedRecomp model,
[[futari-matching-decomp-goal]]), where compose correctness arrives by construction instead of
by renderer forensics. Shell-compose 1:1 (SPEC + presence contracts + Leg-2 datum) folds into
that campaign as the compositor subsystem's spec, not as standalone renderer legs.

## 2026-07-26 leg 1 — user report triage (blob / flashing / missing wallpaper)

User-reported symptoms and where they landed:

### ★★★★ FNF-1 — 07-27 PARTIAL FIX SHIPPED (phantom-constant class closed register-true); residual = streaming-race class
**ROOT CAUSE (measured, register-true):** the blob window's "texture" fetch constant is
`tf={0110037B 10000056 0 0 0 0}` — **type bits[1:0] = 3 = FetchConstantType::kVertex (SDK
xenos.h:1093)**. The decode read a VERTEX fetch constant as a texture → phantom 1x1 fmt-22
(k_24_8 = depth-stencil, xenos.h:492) @0x10000000 → unsupported-fmt → WHITE fallback. A full
32-slot shadow scan at that moment finds NO kTexture-typed constant anywhere — the guest's
texture-setter kick is not yet decoded (port converges to correct rings ~frame 105).
**ORACLE (fnf1_blob_evidence.sh MODE=sdk, snaps read):** hardware shows clean cyan rings +
crisp "Now Loading…" from t1 — the blob is a port defect, not authentic.
**FIX SHIPPED:** fetch constants not typed kTexture now bind a transparent-BLACK 1x1 instead of
white, in BOTH getTexIndexReal (bindless idx, fired live: `[rvk][fnf1] type=3 -> idx=3`) and
getTexture (desc path; legacy call site now passes tf[0]). tf0==0 keeps old behaviour
byte-identical; `RVK_NOTYPEBLACK=1` reverts. **MEASURED: the "Now Loading…" TEXT went from
garbled white shapes to crisp+correct.** Regression gate PASS (d1b_shellreg fnf1_ship vs
fnf10_post: 4_legal bit-identical 0px; topmenu mean 74.06 FNF-3-intact, 1.4% animated-FX px;
attract = the known 305,948-px animated-centre confound).
**RESIDUAL (do not conflate):** one white mass remains at t1 — position matches the SDK's ring
CLUSTER, unchanged by the type fix and NOT via any white fallback (no fallback fired for it).
It is the ring ATLAS decoding white-saturated garbage from partially-streamed guest RAM — the
KNOWN [zscan]/RT_ASYNCIO streaming-race class (vk_render zscan instrument: "FILLING IN (RACE)").
That is a separate, pre-documented defect reservoir; per two-strikes + panel ordering it goes to
the backlog behind the frame-boundary work, NOT another leg now. Evidence kit stays runnable:
`_tmpscripts/fnf1_blob_evidence.sh` MODE=port|sdk; RVK_FETCHRAW dumps + slot scan in-tree.

### FNF-1 "Now Loading" corrupted white blob — MECHANISM CAPTURED (07-26 eve), fix pending
- User played under RenderDoc (playtest_rdc.cmd, F12 overlay) → 88 captures in C:/tmp/rdc_user
  (+ png/ contact sheet via _tmpscripts/rdc_user_sheet.py).
- **CAPTURED MECHANISM:** frames 40/85 (first seconds of boot) show the loading-ring spinner
  sprites rendered as SOLID WHITE masses w/ cyan fringes (the blob); frame 105 — same screen,
  moments later — shows the SAME sprites drawing correctly as rings. Session log line 653:
  `[rvk] unsupported texture fmt=22 base=0x10000000 1x1 — using white` = the renderer's
  index-0 white fallback (vk_render.cpp:1935-1942) taken during exactly that window. So the
  blob = ring quads sampling the white fallback until the real texture is available.
- Note base=0x10000000 carries the physical-alias-bit shape (cf. RVK_ALIASPROBE comment) and
  claims 1x1 fmt=22 — possibly a placeholder/unresolved fetch-constant state, not a real
  1x1 asset. DO NOT band-aid (e.g. skip-draw-on-white): register-true next steps:
  (1) map Xenos fmt 22 semantics from SDK texture-decode source; (2) identify what the guest
  actually has at that fetch-constant during those frames (RVK_DUMP_ON_WHITE arms a per-draw
  ops dump); (3) SDK oracle loading-screen capture to see what hardware shows in the same
  window (if hardware shows clean rings from frame 1, the port's texture-availability timing
  or fmt-22 decode is the defect; if hardware also flashes, it's authentic).
- Bindless caveat for rdc analysis: per-draw texture identity is NOT in pipeline state
  (descriptor-indexed); rdc_blob_draws.py's GetReadOnlyResources approach returns nothing —
  use the game's own logs / RVK_DUMP_ON_WHITE instead.

### ✅ SURVIVABILITY CLUSTER SHIPPED 07-27 (FNF-8 P1 + FNF-2 fallback; ship-gate items (b))
Renderer death is now LOUD + nonzero exit, and the window X actually quits. All in
render/vk_render.cpp; 4/4 positive controls PASS (`_tmpscripts/qa_dieloud.sh`, /c/tmp/qa_dieloud/):
- **FNF-2 fallback:** `rvkDieLoud()`/`rvkVkFatal()` — any VKC failure AFTER a healthy init
  (`g.ok`) prints a RENDERER FATAL banner, flushes, `std::_Exit(3)`. Init failures on hooked and
  legacy paths exit 5 (an invisible windowless process is also unexitable); window bring-up
  failure exits 4 via a choke point in the present path. `RVK_DIEHARD=1` restores the old
  disabled-but-running corpse — **both instrument harnesses (fnf2_devloss_hunt.sh,
  d1b_shellreg.sh) now pin RVK_DIEHARD=1** so measured drive shapes stay comparable across builds.
- **FNF-8 P1:** WM_CLOSE → flush + `_Exit(0)` (verified exit; there is no host main loop, so
  flush+_Exit IS the orderly path — same semantics as arcade power-off, save validator covers a
  torn write). `RVK_NOEXITONCLOSE=1` restores flag-only. CloseMainWindow control PASS.
- **`RVK_TESTDIE=1` fault injection (default-off)** landed as the standing positive control for
  the death path — a safety feature that has never fired is presumed broken (5 ledger instances).
  Verified: banner + exit code 3; with DIEHARD=1 the corpse survives 10s with no banner.
- **FNF-8 P2 is REFUTED as a defect:** stderr has been unbuffered since 07-21
  (vk_render.cpp:62 static init, in the ship link). Direct measurement on the ship exe: 925
  bytes of log CONTENT within 3s of launch. The QA agent's "log stays 0 bytes ~40s" was a
  stale-directory-metadata artifact (NTFS dir enumeration lags open-handle sizes) — read file
  CONTENT, not `dir` size, when checking log liveness. No code change made or needed.
- Healthy-boot regression control: 20s boot, presents at 60, zero banners (CTL-4).
⚠ Post-this-commit, any NEW drive script that wants to observe a wedged process must set
RVK_DIEHARD=1 — the default now exits on the first renderer failure.

### FNF-2 — 07-27 morning: PRE-FIX CONTROL COMPLETED BUT IS ★INVALID★ — draw NO conclusion from it
The `EXE=/c/tmp/fnf3_fix/futari_merged_prefix.exe OUTTAG=pre_ab` control finished 07:20: 0 FAIL-submit
hits / 12 boots — **but every one of the 12 boots has romok=0**. The control boots never entered the
failure window at all: zero `OUTER66a8=3` markers, **zero `[scenelog]` lines despite RT_SCENELOG=1
exported by the same harness** (post-fix iter_1: 44 scenelog lines), zero wallfile/wp01 lines, and
1 `[resolve]` line vs 94 post-fix. So this is NOT the "both 0 ⇒ harness doesn't exercise the path"
branch of the pre-agreed interpretation — the control arm simply never ran the experiment.
**ROOT CAUSE (established in the 07-27 morning session, "Futarirealcomp status summary"): the
harness's cleanup guard matched process name `futari_merged` EXACTLY; the control binary is
`futari_merged_prefix.exe`, so cleanup matched NOTHING and all 12 control instances stayed ALIVE
CONCURRENTLY (~4.9GB) — a 5th instance of the silent-no-op-safety-check class** (tripwire that
suppressed its defect; wrong-window descriptor read; post-fix-dead proof lever; sampled-frame
census). Matchers since fixed to wildcards in fnf2_devloss_hunt.sh (working tree). The 12-way
contention also explains the boots looping in early-boot state machines (`[bootsm]`/`[lzxsm]`).
⏭ Rerun the control on the FIXED harness before interpreting anything; if it still can't drive the
prefix exe, move the A/B to the snap-drive shape (d1b_shellreg.sh), which incidental evidence
(3 hits/8 drives) already shows DOES exercise the path.

### FNF-2 — 07-27 A/B COMPLETE ON THE FIXED HARNESS: **BOTH ARMS 0/12 ⇒ this drive shape does not exercise the failing path**
Control rerun (`OUTTAG=pre_ab2`, EXE=futari_merged_prefix.exe, fixed wildcard harness): **0 hits /
12 boots, all 12 romok=1** — a VALID control this time. Combined with post-fix 0/12 (also all
romok=1), the pre-agreed rule fires: **this harness's drive shape (fast boot→ROM→30s aftermath)
does not reach the failing path; no FNF-10↔FNF-2 conclusion is possible from it.** The rate
measurement, if anyone resumes it, must move to the snap-drive shape (d1b_shellreg.sh — which
holds longer, PrintWindow-snaps and reaches the system menu; incidental evidence 3 hits/8 drives
07-27 mixed builds). d1b_shellreg.sh now supports `EXE=<path>` + wildcard matchers for exactly
that A/B. **Per the Fable panel STOP-DOING ruling + the two-strikes rule, FNF-2 root-cause work
now STOPS here**: the survivability cluster (above) is the shipped mitigation — a lottery hit is
loud + fatal instead of a silent hang, and tester GPUs will surface the real rate. PrintWindow
snap load is a plausible ingredient of the failing shape (the one localized hit fired at the
wallpaper upload submit during a snap-heavy drive) — noted for whoever resumes.

### FNF-2 device-loss lottery — 07-27 RATE SOAK: 0 hits / 12 boots on the fixed build (⚠ NOT YET A WIN)
`ITERS=12 VALIDATE=0 RATE=1 OUTTAG=post_fnf10 bash _tmpscripts/fnf2_devloss_hunt.sh` → **0/12**,
every boot reaching the ROM handoff (romok=1) with 30s of aftermath.
⚠ **DO NOT BANK THIS AS A FIX YET.** The 2-hits-in-5 baseline came from the SNAP drives
(d1b_shellreg.sh), which hold longer, take PrintWindow snaps and reach the system menu — a
DIFFERENT drive shape from this harness. Comparing a rate across drive shapes is the same
apples-to-oranges error that produced the retracted burst-vs-heartbeat reading. The control now
running is the SAME harness against the preserved pre-fix binary
(`EXE=/c/tmp/fnf3_fix/futari_merged_prefix.exe`, captured before the FNF-3 and FNF-10 changes).
Interpretation rules agreed in advance: pre-fix hits several times & fixed stays 0 ⇒ the
descriptor leak (FNF-10) was feeding the device loss; BOTH 0 ⇒ this harness does not exercise the
failing path and the measurement must move to the snap drives; both hit similarly ⇒ independent
defects. **12 boots per side can only detect a LARGE effect** — one or two pre-fix hits is
suggestive, not conclusive, and must be reported as such.
Incidental 07-27 evidence (snap drives, mixed builds): 3 hits / 8 drives, one of them surfacing at
the wallpaper upload submit (`FAIL submit(upl) = -4`) — the path FNF-10 thrashed.
**Harness hardened 07-27** (it had the landmines this project keeps re-learning): kill-by-name
replaced with PID-only + abort-if-a-game-is-already-running; the real Windows PID is now resolved
after launch (MSYS `$!` is the shell job id); `RATE=1` keeps the loop running after a hit (stopping
on the first one makes it a hunt and destroys any rate estimate); `EXE=<path>` runs another binary
through the identical harness so before/after is same-drive-shape.

### FNF-2 (earlier) VK_ERROR_DEVICE_LOST lottery at ROM handoff — OPEN; semaphore fix shipped but DID NOT close it
- **STATUS UPDATE (07-26 eve):** the per-image blit-semaphore fix (below) eliminated real
  spec-UB (VUID-vkQueueSubmit-pSignalSemaphores-00067, caught live; plus the
  suboptimal-reacquire double-signal) and passed 8/8 validated boots — but the lottery
  RECURRED on the fixed build (shellreg semfix drive: FAIL submit(upl)=-4 at the same
  handoff spot, window hung, logic ran on). **VUID = real-but-not-root-cause.** Tally:
  2 wedges / 5 unvalidated drives; 0 / 16 validated boots — validation timing SUPPRESSES
  the race (heisenbug). First-failing submit differs between hits (rseg vs upl) ⇒ the loss
  happens asynchronously earlier; -4 merely surfaces on the next submit. Next instrument:
  VK_LAYER_LUNARG_crash_diagnostic (installed, SDK 1.4.350.0) — postmortem dump of GPU
  progress at the loss, lighter timing footprint than validation.
- Reproduced 1/4 driven boots (d1b_shellreg.sh, ship env + snap instrumentation):
  run `fnf_new` hit it, `fnf_old`/`fnf_old2`/`fnf_new2` clean.
- **NOT the repairMatrix lever**: order-swapped rerun with both lever states was clean both
  ways. Per-boot lottery, same class as the Fix A era intermittent (was 1/3 pre-1cfbfc3,
  0/8 in its acceptance; still alive at some rate).
- Log signature (all in /c/tmp/d1b_shellreg_fnf_new.log): first failure at ROM handoff right
  after `[rvk][resolve] target dst=0xE0280200 640x512` + first ROM-era IM_LOADs →
  `[rvk] FAIL submit(rseg) = -4` (x6: rseg/rblt/upl/pbxA) → `[rvk][wallfile] read/upload
  FAILED wp01.bin` → window goes HUNG (IsHungAppWindow true, PrintWindow blocks forever)
  → degen counter plateaus (renderer dead) while guest logic runs on for minutes
  (scenelog reached f15949, FIFO input still worked, summon succeeded).
- User-visible translation: game keeps "running" with dead/frozen/black visuals after a
  transition — very plausibly the user's "menus glitchy / flashing when left running".
- For F&F this is a top blocker: silent renderer death on a lottery boot = unplayable session
  with no error surfaced. Next: (a) root-cause the lost-device submit (validation layers on a
  loop-until-hit boot farm; aftermath of the handoff rewind is the prime suspect zone), and/or
  (b) detect -4 and surface it loudly + attempt device recreate; never hang the window.
- Repro harness: `_tmpscripts/d1b_shellreg.sh` (MODE=new|old, OUTTAG=x) — snaps + hung-window
  detection via snapdbg.log; drive it in a loop until FAIL submit appears.

### ★★★★★★ FNF-3 **FIXED AND SHIPPED 07-27** — full-ucode tiebreak in matchImLoad
**THE 07-26 DIAGNOSIS BELOW WAS RIGHT ABOUT THE MECHANISM AND WRONG ABOUT THE ENTRY.** Direct byte
measurement (C:/tmp/fnf3_fix/, prep workflow): the runtime background PS is **byte-exact to table
entry 16 (0x8203D5E8, `out = sample * c2`), distance 0** — vs 9 to idx18 and 10 to idx2/idx6.
Entry 6 has **no multiply at all**; the SDK's own background PS ends `mul r2, r0, CB3[0]` =
sample * const. So the 07-26 proof lever (force ps=6) produced a correct-LOOKING picture **for the
wrong reason**: it dropped a multiply the hardware performs, and c2 measured **0.9000** (the guest's
own wall-dim factor), so it rendered ~11% too bright.
**SHIPPED (07-27):** full-ucode FNV-1a-64 tiebreak in matchImLoad as a **SCORE TIER (4), never a
filter** — it sits inside the prefix-match body after every `continue` and only RAISES a score, so
the candidate set is bit-identical to the old matcher and `bestIdx` can never go from >=0 to -1:
**a draw that renders today cannot start being skipped.** Pixel shaders only by default
(`RVK_UCODEMATCH=0` old matcher / `=1` PS only, DEFAULT / `=2` PS+VS, EXPERIMENTAL): VS ucode is
PATCHED at load time by the D3D9 runtime (vfetch stubs get format/stride/offset filled in), measured
0/6 VS vs 6/6 PS runtime dumps byte-exact — keeping VS off makes the ~14 `g_curVsIdx == 5`
predicates provably unchanged. Hash 0 = no capture provenance (ROM rows 48/49/50) = never boosted.
Generator: `_tmpscripts/gen_ucode_hash.py` (in-repo, append-only, 4 controls: CTL-1 48/48 rows
reproduce their own prefix+size; CTL-2 corruption detected; CTL-3 hash injective over distinct
programs; CTL-4 all 7 collision groups separated). Table block appended to shaders_futari.h with two
`static_assert`s + a runtime anchor check in matchImLoad that ABORTS on a renumbered table.
⚠ **DO NOT re-run render/tools/extract_cache to refresh the header** — it emits a 9-field struct vs
this file's 7, sorts by guest_addr, and emits only capture-matched containers ⇒ a 48-row RENUMBERED
table with ROM rows 48/49/50 DELETED, against ~40 hardcoded index predicates. Its toolchain does not
exist on this machine and the checked-in binary is a stale Linux ELF. Use gen_ucode_hash.py.
⚠ **THE ENTRY-50 TAIL HACK MUST STAY** — the runtime ROM PS at 0x11720000 is BYTE-IDENTICAL to entry
44 (0/72 diffs): one guest shader, two independent translations. No ucode rule can separate them;
removing the override hands the draw to 44 by lowest-index and reverts the shipped attract
legal-panel wash fix. Score 5 > the new score 4.
**MEASURED RESULT (drive OUTTAG=fnf3_ship, snap C:/tmp/d1b_shellreg_fnf3_ship/2_topmenu.png):
client-area mean luma 9.716 (broken) → 81.443 (07-26 proof lever) → **74.302 (shipped)**.
74.302/81.443 = 0.912 ≈ the measured c2 = 0.9 — independent confirmation that entry 16 is right and
the lever was too bright. **Zero `[rvk][skip]` lines, zero tripwire aborts.**
Dry-run gate G1 (offline, before any edit): changed 2/15 runtime dumps, **regressions 0**; newly
reachable entries [6, 16, 18, 32, 38, 46] (**22 of 51 were unreachable, not 31** — the 07-26 figure
is corrected). G2 on FRESH dumps (the old ones were 10 days stale and every address had rotated):
the 60-byte background PS recovers EXACT=[16]; VS dumps reproduce their known non-exactness
(positive control for the patch-mechanism premise).
RVK_BGPSFIX is KEPT and WIDENED to take the target index as its value (`=6` passthrough, `=2`
reproduce the defect) — left unwidened it could never fire again after the fix, becoming a control
that looks live and silently does nothing.

### (07-26 diagnosis, superseded on the entry number — kept for the trail) FNF-3 ROOT-CAUSED — **WE BIND THE WRONG TRANSLATED PIXEL SHADER**
Full scope: C:/tmp/fnf3_scope/FNF3_SCOPE.md. Verdict (d) — NOT a traversal gate, NOT unloaded art,
NOT a compose-ordering problem (all three prior hypotheses refuted). Confidence HIGH ~0.9.
- **SDK:** the entire illustration is ONE draw (eid 28), a Xenos rectangle-list fullscreen primitive,
  opaque, sampling a single 1280x720 texture that is **bit-exact `assets/media/wall/wp01.bin`**
  (128-byte header skipped; np.array_equal True, maxdiff 0). Its PS declares ONE input
  (`dcl_input_ps linear v0`) and ends `mov o0, r1`.
- **Port:** emits the SAME draw with the CORRECT texture (ResourceId::10595, mean 91.813 == SDK's),
  correct fullscreen NDC geometry, correct UVs, opaque blend, inside the normal render pass —
  37,190 frames sample `1280x720 base=0xE5F5000` in /c/tmp/fnf7_menutrip.log. **The art is there and
  the draw happens.**
- **The defect:** the port binds `ps=ResourceId::209` — *the same PS as all 60 menu quads* — which
  computes `sample(tex,uv) * interpolator16`. The background's VS writes NOTHING to interpolator 16
  (o16 = (0,0,0,0); menu quads carry (1,1,1,1)). **So our own background draw multiplies by zero and
  WIPES THE RENDER TARGET TO BLACK** — measured `d00_pre_e17 mean=9.894 → d00_post_e18 mean=0.000`.
- **Why:** `matchImLoad()` (render/vk_render.cpp:1285-1311) identifies guest shaders by **first 32
  ucode bytes + size ONLY**, with `score > bestScore` so the LOWEST index wins. Table entries **2**
  (0x8203A508, `out = sample * colour`) and **6** (0x8203BD90, `out = sample` — the SDK's exact shape)
  have BYTE-IDENTICAL 32-byte prefixes and identical size 60. Entry 6 is unreachable dead code. The
  background's VS is table idx 5 (0x8203BC00), whose address-adjacent paired PS is idx 6.
- ⚠ **SYSTEMIC — this is the SECOND instance of the prefix-collision class the file itself documents at
  :1296-1307 (the attract legal-panel wash). 31 of 51 shader-table entries are currently UNREACHABLE**
  (incl. 12 of the 132-byte VS group) — a latent reservoir well beyond FNF-3. Suspect it for any
  "wrong-looking shading" defect.
- **FIX:** emit a FULL-UCODE HASH from extract_cache.cpp:351 (it already has the bytes) and match
  exactly; retire the entry-50 tail hack. **No shader regeneration needed** — `g_futari_spirv_2` is
  already in the binary. **Prove it first with a ~5-line DEFAULT-OFF lever forcing psIdx=6 when
  vsIdx==5.**
- ★★★★★★ **DIAGNOSIS PROVEN LIVE (07-26 late, RVK_BGPSFIX=1 default-off lever landed in
  vk_render.cpp at the pipeline-selection site; drive `_tmpscripts/d1b_shellreg.sh` OUTTAG=bgfix):
  THE TOP MENU NOW RENDERS THE FULL ILLUSTRATION** — cave/forest background, Reco character art,
  ring FX, glowing logo. Client-area mean luma **9.716 → 81.443** (SDK ground-truth PNG full-frame
  mean 68.647; the port figure is higher because the GT includes window chrome/letterbox in its
  larger frame — compare crops, not raw means, for the formal gate). Snap:
  C:/tmp/d1b_shellreg_bgfix/2_topmenu.png. The lever fires exactly on (vs=5, ps=2) → ps=6.
  ⇒ The prefix-collision diagnosis is CONFIRMED end-to-end. **Remaining work is the SHIPPING fix**
  (full-ucode hash so entry 6 is reachable, retiring the lever), plus the blast-radius check on the
  other 30 newly-reachable entries.
- **ACCEPTANCE:** the RT immediately after the bg draw must equal `wp01.bin[128:][:,:,[2,1,0]]`
  (mean **91.813**; today **0.000**) — harness `port_bg.py`. End-to-end: window mean luma 9.88 →
  oracle 65.44, bg-region channel ordering G>B>R. Effort ≈ one 4-6h session, mostly verification;
  blast radius (31 unreachable entries becoming reachable) is the real cost.
- **TWO RETRACTIONS BANKED (agent's own, mid-pass):** the "1x1 placeholder" reading was a BOOT-ERA
  frame, not the menu; and **`wp01.bin` is NOT RGBX — the `[rvk][wallfile]` BGRX→RGBA swizzle is
  CORRECT** (the SDK stores guest bytes verbatim and swizzles in-shader, xenia-style; the authoritative
  ground-truth snap has B > R in the background region). **DO NOT "fix" that loader.**
- Supersedes the earlier "compose gate" reading from the wallpaper lane (that lane was right that the
  art is loaded pre-ROM; it is the SHADER BINDING, not the compose gate, that blanks it).

### FNF-3 (original entry) TOP MENU illustrated background missing — KNOWN OPEN (not a regression)
- Confirmed again today on fresh save, BOTH repair-lever states: pre-ROM TOP MENU + card
  carousel render menu elements over black.
- This is the known "illustrated background" workstream from the 07-25/26 menu-flash hunt:
  SDK ground truth (reference_captures/oracle_rdc/sdk_topmenu_*_GROUND_TRUTH.png) is FULLY
  ILLUSTRATED (cave wallpaper, Reco art, glowing logo, ring FX; oracle mean 65.44 vs port
  9.88). Port has NEVER rendered it pre-ROM; the 07-08 "known-good" navy was clear-color.
  User perceives it as "wallpaper missing again" — it is the single biggest visual gap
  between port and hardware on the first screens a tester sees.
- Machinery exists post-ROM (`RVK_WALLBG`, `g_rt_wpindex` wallfile upload works — proven in
  today's clean boots). Work = drive the illustrated bg pre-ROM (compose context exists since
  RVK_PREROMWIN).

### FNF-4 save_playtest byte-identical to save_freshcard — OBSERVATION, ambiguous
- cmp: 0 differing bytes, yet mtime 07-25 21:11 (written during the playtest session).
- Either nothing save-worthy changed that session, or the known "play_shellnative save-reset
  clobbers settings" debt fired. NOT concluded. Discriminator when wanted: change a setting
  in a playtest session, quit cleanly, re-cmp.

## Regression checks banked this leg (2026-07-26)
- D1-B fix intact on ship default: sysmenu snap has NO replay-speed strip / 加速 text / REPLAY
  plate (fnf_new2/8_sysmenu.png); lever state restores them (fnf_old/8_sysmenu.png). As designed.
- Fix A (1cfbfc3) intact: TOP MENU + card carousel compose all menu elements on every clean
  boot today (fnf_new/old/old2/new2 snaps 2-3).
- Wallpaper file path healthy on clean boots: wp01.bin loaded+swizzled in both lever states.
- Snap corpus: /c/tmp/d1b_shellreg_fnf_{new,old,old2,new2}/ + snapdbg.log traces.

### ★★★★ TRANSITION SPIKES — 07-27 ROOT-CAUSED AND FIXED: **WC-read wallpaper swizzle (the pbxA lesson class, 2nd instance)**
[slowframe] attribution (new always-on instrument: any frame >100ms prints decode/texUp/
pipeCreate/fences split) proved the 250-265ms transition frames were NONE of those (decode
17-19ms, uploads 4-8, pipelines ≤1, fences 10-13) — and worker thread priority didn't help
(not preemption). The tell was in the log: `[rvk][wallfile] loaded wp01.bin` immediately
precedes every spike. **ROOT CAUSE: the wallpaper load fread THE FILE INTO g.stagingMap and
the BGRX→RGBA+dim swizzle did read-modify-write ON the write-combined mapping — ~2.7M
uncached reads ≈ 230ms.** Every dim-fade quantum step at a menu/stage transition pays one
full reload (the FNF-10 (idx,q) cache makes repeats free, but each NEW quantum loads).
Second instance of the banked pbxA lesson ("before blaming the GPU, check for CPU reads of
mapped Vulkan memory"). **FIX: fread → heap buffer; staging gets only sequential writes.
MEASURED: zero [slowframe] lines, zero >133ms drains on the full bwedge drive** (was 2×
~260ms every run). Content-neutral by construction (identical bytes/outputs; traffic
reordering only). ✅ Texel gate PASSED (07-27, unlock-watcher automation): attract BORDER
diffpx=0 maxdiff=0, 4_legal diffpx=0 maxdiff=0 vs the fnf1_ship baseline — measured
bit-identical, gate closed. D3 exact-dim-at-blit (task: kill the 1/16
quantization) remains open but demoted: reloads are now cheap and cached; the blit-modulate
surgery on the fragile compose path should be attended.

### ★★★★★ FNF-5 — 07-27 UNATTENDED STABILITY SOAK (dec_soak.sh, build 30046dd, 12:00-12:58): **PRE-FLIP EVIDENCE GREEN**
11 drives + one 30-min session, all decoupled, zero human attention:
- **5/5 bwedge (TRAINING→5×B-backout→60s watch): alive, window responsive, content 98%, 0
  overflows** — the wedge class did not reproduce once on the walk-lite build.
- **5/5 stage: ticks 59.16-59.35 (field windows), content 96%** — the per-run slowdrains=2 are
  the two known one-off transition spikes.
- **stage5 took a LIVE FNF-2 LOTTERY HIT (`FAIL submit(upl) = -4` at the wallpaper upload,
  snap-taking drive shape again) and the survivability path fired PERFECTLY in the field for
  the first time: RENDERER FATAL banner, exit 3, no hang.** Content was 99% up to the hit.
  Tally: ~1 lottery hit per ~10 game drives today. Note for the flip: under decouple a hit =
  instant clean exit mid-play (lost run, honest failure) — vs the old frozen-window ruin.
- **30-min attract session: worker flat 13.4-13.5ms across 112k frames — NO walk-cost aging**
  (the 6.9→14.4ms growth from the user's session did NOT reproduce in attract; the aging
  suspect moves to stage-texture/cache behavior or the user's profile — still open, lower
  priority). 0 overflows, content 98%, alive throughout.
⚠ dec_soak.sh summary formatting: `grep -c ... || echo 0` double-prints on zero matches
(cosmetic; counts on continuation lines belong to the PRECEDING tag). Fix before reuse.

### ★★★★★ FNF-5 WORKER PERF LEG — 07-27: **CONTENT COLLAPSE FIXED (walk-lite + queue 24): in-stage content 99-100% at 59.9 ticks**
[wperf] worker-cycle instrument (always-on-lite: lock/walks/render/publish split per drain,
summary /300, immediate line for any drain >133ms) found the whole story in one drive:
- **Transition spikes:** single renders of 250-263ms at training-panel entry and stage load
  (texture decode+upload bursts) — one spike backlogs ~15 windows; old queue depth 8 dropped 7.
- **THE DEATH SPIRAL (the user's 33-41%):** a "state-only" backlog walk cost the SAME as a full
  render minus GPU (14.2 vs 14.8ms) because renderFrameReal ran the ENTIRE content-draw body
  (vertex extract, texture lookups, batch build) on walks. Once any spike created a backlog,
  each drain cost walk+render ≈ 31ms vs 16.7ms arrivals — a stable degraded attractor (content
  1 render/31-50ms = 33-41%) that never recovers until the scene gets cheap. Matches the user's
  phase pattern exactly (legal slow → ROM menu fine → training/stage collapsed).
**FIX (walk-lite):** on frame==-1000000 calls (backlog walks + keep-warm) skip the content-draw
body; type-0 register/constant writes, IM_LOAD shader identity, and resolve classification+
registration all still run (they ARE the cross-window state). `RVK_WALKFULL=1` reverts.
Queue depth 8→24 (kickseg ring 6MB/192KB ≈ 31-window guaranteed history; deeper would read
recycled ring = worse than dropping). ⚠ **7th silent-instrument lesson:** first walk-lite gate
keyed on the `render` PARAM — but the worker passes render=false on its RENDER call too
(rendering fires via wantLast = real-frame + ndraw>0), so renders were starved to 1.4ms empty
frames and one profiled run was VOID (caught by implausible-speed check). The discriminator is
the FRAME SENTINEL. MEASURED AFTER FIX: steady drains 16.7ms (render 14.2 + publish 2.5),
post-spike walks 0.1-0.8ms, recovery ≤2 cycles, ZERO overflow warns.
**RE-ACCEPTANCE (all PASS):** in-stage ticks 59.91-59.97 with content **99-100%** (was 33-41%
collapse class); bwedge TRAINING→5×B-backout→60s watch healthy (no wedge, no overflow); shell
regression 4_legal bit-identical, topmenu byte-class identical to pre-walklite decouple run;
in-stage snap read clean. Residual: the 2 one-off 250-263ms transition spikes remain (brief
content hiccup at menu/stage transitions, absorbed by the deep queue; optimization lane =
texture-upload batching, NOT urgent). ⏭ user re-test via the decoupled icon; flip decision
after feel-check.

### ⚠⚠ FNF-5 DECOUPLING — 07-27 USER PLAYTEST VERDICT: **NOT PLAY-READY — content collapse in heavy phases + a wedge class** (superseded by the perf leg above)
User played the decoupled icon (3 sessions, logs playtest_0727_0949/0953/0956): input OK at
first, legal scroll slow, ROM menus fine, TRAINING menu "ultra slow", in-stage "way too slow"
(not the authentic CAVE slowdown), and B→TOP MENU "crashed".
**MEASURED from their 0953 log:** presents held 59.9 fast-path THE WHOLE SESSION (the clock fix
works) — but **worker CONTENT rate collapsed to 33-41% in the heavy phases** (per-300-frame
worker/present ratio: shell 100% → training/stage 33-41%, drained up to 8) = display updates
~20-25Hz while logic runs 60 ⇒ the "way too slow" FEEL is display starvation, not simulation
rate. Worker walk cost DOUBLED over the session (6.9→14.4ms avg) + fences ~5ms/frame;
**vtxsnap ring exhausted: skips=154,492** (every window now walked ⇒ 16MB ring insufficient;
skipped snapshots = worker reads recycled vertex scratch = the torn-content class).
**THE "CRASH" IS A WEDGE, NOT A CRASH:** 0953 ends mid-stream with NO [SIGNAL] (the harness
onsig prints one for real AVs — verified by RVK_TESTCRASH control, exit 42 + backtrace), no
window-close, no FATAL ⇒ process was killed by hand (console close kills the child tracelessly).
Frozen-frame wedge = worker permanently stalled while blit keeps showing stale imageShow.
Scripted repro (fnf5_bwedge.sh DEC=1: boot→TRAINING→dwell→5×B-backout→60s watch): NO wedge,
window responsive, 60fps — but **"WARN window queue overflow (worker stalled?)" fired**, same
as the user's log: the transient stall class is real and reproducible; the permanent form needs
the user's heavier state. New: SetUnhandledExceptionFilter crash banner (backstop; onsig is
primary), RVK_TESTCRASH worker-AV control.
**⏭ NEXT LEG (the real work before any default flip):** (1) worker frame-cost profiling in
training/stage (RVK_PERFLOG on a decoupled heavy drive; banked lanes: cheapen the CPU walk,
batch submissions — the attract-era pass got 72-90ms→12.5ms once); (2) stall root-cause (what
holds the worker >133ms: a fence, g_qMtx contention with the blit, or a pathological drain);
(3) vtxsnap/kickseg ring sizing or back-pressure for walk-every-window mode; (4) walk-cost
aging (6.9→14.4ms growth = cache/map growth suspect). Until then: **user plays the NORMAL
icon; decoupled icon is a test vehicle.**

### ★★★★★★ FNF-5 — 07-27 **DECOUPLING BUILT AND ACCEPTED (RVK_DECOUPLE=1, default-off): in-stage ticks 54.7 → 59.94-59.97/s**
The welded clock is FIXED under the lever. Mechanism: the async render worker (65b3bbe infra)
was gated to post-ROM menus/attract only — `rvk_present`'s rbudget selector EXCLUDED the field
phase (`faA==0` term) and every ship env pinned `RVK_ASYNCRENDER=0 RVK_RENDERBUDGET_MS=0`, so
in-stage renders ran INLINE inside the guest logic loop (update→render→vblank-gate) and the
vblank gate could only cap, never rescue. `RVK_DECOUPLE=1` forces the worker path in ALL phases
(present call = enqueue+blit; wall-clock RT_VBISR gate paces logic; worker absorbs render cost);
`=0` forces inline (bidirectional).
**ACCEPTANCE (all PASS, 07-27):**
- In-stage NORMAL PLAY: ticks flat **59.94-59.97/s** every field window (baseline 54.7-55).
- Falsifier `RVK_SLOWRENDER=30` (new lever, sleeps in renderFrameReal, skips backlog walks):
  inline ticks 21/s (welded, reproduced); decoupled ticks **59.9 flat** while the worker drains
  3-4 windows/pass — render cost provably no longer touches the simulation clock. Attract:
  decoupled = TRUE 60.0 (inline baseline was 56.1 even undisturbed).
- In-stage visuals through the worker: clean (ab_port_v5 snaps read — playfield/HUD/border
  correct, score advancing, no tearing).
- Shell regression (d1b_shellreg decouple_reg vs fnf1_ship): **4_legal bit-identical**;
  title/topmenu/card diffs = known animated classes; 8_sysmenu eyeballed clean (live attract
  behind dialog = the confound).
- Worker keeps up in-stage: drained-1 steady state ≈ 92% content rate at full speed.
**⚠ FNF-7 COMPONENT OF THE PANEL THESIS REFUTED:** identical 5-min DRAWTRIP menu soak under
decouple: 5,970 hold frames at exactly 61 draws, **9 anomalous frames (5×62, 4×64 draws) ≈ the
inline baseline rate (22/12min ≈ 1.8/min)**. The transient extra quad SURVIVES the
atomic-window worker ⇒ it is NOT a mid-tick traversal/present-coupling artifact. FNF-7 stays a
distinct, backlogged defect (guest-state or decode class; identity lines in
/c/tmp/fnf7_menutrip.log: n=4 menu-atlas quads, base=0x1DB1000 vs=1 ps=2). The panel's FNF-5
severity ruling stands (proven independently); its FNF-7 unification does not.
**DEFAULT REMAINS OFF.** Flip plan: user plays with `RVK_DECOUPLE=1` (playtest icon env) to
feel input latency (content lags ≤1 worker frame); if good, flip the default and strip
`RVK_ASYNCRENDER=0 RVK_RENDERBUDGET_MS=0` from the ship envs (they would override the flip).
Diagnostics kept default-on (cheap): `[rvk][fast]`/`[rvk][inline]` every-300 present logs, fps
tag now distinguishes "fast" vs "legacy". ⚠ fnf5_tickrate.sh MODE=stage XLV merge bug fixed —
3 earlier "decoupled stage" runs were silently BASELINE (the 6th silent-no-op instance; the
59.9 blip in run dec3 win11 was stage-content variance, not decoupling).

### ★★★★★★ FNF-5 — 07-27 TICK MEASUREMENT COMPLETE: **WELDED CLOCK PROVEN; game simulates 8-9% SLOW in-stage**
Panel ordered-plan item 1 executed (ticks, not frames). Instrument: `RT_TICKRATE` block in the
outer scene-FSM pump hook (`sub_88138F00`, merged_xex.cpp) — one pump = one guest logic frame;
5s windows log rate + gameplay-field flag (0x885C1A20) + outer state. Note the env name was
ALREADY used by a 07-2x ring-kick instrument (`[tickrate] gamekick`, sub_88080298 kicks/sec ≈
260/s = multiple ring kicks per frame) — both fire, tags distinguish them; do not read gamekick
as a frame rate. Drive: `_tmpscripts/fnf5_tickrate.sh` (MODE=menu|slow|stage).
**RESULTS (this box, RTX 3080, shipped-current build 07-27):**
- ROM attract: ticks **56.1/s**, presents 56.2/s — locked, and BELOW 60. The 60→56 decay in
  attract also appears in both fnf2 soak arms **including the pre-fix binary** — pre-existing,
  not a today regression.
- **IN-STAGE (field=1, real NORMAL PLAY via ab_instage drive): ticks 54.7-55.0/s — the game
  runs 8-9% slow motion in stage.** The user's FNF-5 report is a measured simulation-rate
  deficit, not a feel artifact.
- **FALSIFIER (the direct proof): `RVK_SLOWPRESENT=30` (new default-off lever, sleeps in every
  present call) forced presents to ~21/s → guest ticks followed to ~21/s in lockstep.** Guest
  logic rate is a FUNCTION of host present throughput. The panel's welded-clock thesis is no
  longer inference — it is an experimental result with a controlled lever.
- Instrument positive control: ticks==presents in every phase and mode (same clock observed two
  ways); shell-title idle produces ZERO game-module ticks (pump doesn't run pre-ROM — a
  shell-idle "menu" control is invalid, use ROM attract).
**SEVERITY CONFIRMED: correctness class.** On slower hardware (Deck) the whole game is slow by
construction; on THIS box it is already 8-9% slow in stage. The tick/present decoupling (atomic
frame boundary) is therefore the top item of the menu campaign — it is simultaneously the FNF-7
flicker mechanism and the FNF-5 fix, exactly as the panel ruled.
⚠ Drive-script landmines re-learned (all now documented in fnf5_tickrate.sh): pwd -W is
REQUIRED with MSYS_NO_PATHCONV=1 (else RT_GAME_ROOT reaches the exe in MSYS form and asset
loading dies pre-render — 3 silent no-boot runs); presses are calibrated for the FRESHCARD flow
(reset save_train from save_freshcard); first press at 60s not 45s.

### FNF-5 playtest running SLOW (user report 07-26) — OPEN, measured real
- [fps] present-rate distribution across all playtest logs (median presents/sec):
  07-25 sessions ~59.9 steady (2111: med 59.9; 2114: med 58.9); TODAY 0726_1645 (the long
  play session): **med 45.2, p25 41.9, min 6.7** — a real, recent slowdown, worst today.
- A 6.7-presents/sec dip is visible jank — plausibly the user's "flashing" on an otherwise
  healthy boot (all 6 playtest logs have ZERO FAIL-submit: the DEVICE_LOST lottery never hit
  a live session; FNF-2 and FNF-5 are distinct defects).
- GPU pick is correct (RTX 3080 chosen over UHD 730, checked 0726_1652 log) — not the
  hybrid-GPU trap. Playtest env carries RVK_PERFLOG + MSGLOG/SCENELOG/FSMLOG/CREDLOG log
  streams (absent from a shippable build) — instrument-cost vs real regression NOT yet split.
- **Per-phase histogram DONE (fnf5_phase_fps.py, scratchpad):** the slow phase is IN-STAGE
  GAMEPLAY (scenelog OUTER66a8=5 stage66b4=0x4): today med 44.4 / min 6.7 / 76 of 87 samples
  <55. Menus/loading/boot hold ~60 in BOTH sessions. Last night's "fast" session was ALREADY
  in-stage med 50.7 (35/55 samples <55) — a pre-existing gameplay-phase deficit, worse today,
  NOT introduced by the 07-26 commits. Consequence: menu slowness does NOT explain the user's
  "menus flashing"; FNF-2 aftermath (or something unmeasured) is back as the lead for that.
- Next: reproduce in-stage under the harness (qa_playab.sh real-play drive) with RVK_PERFLOG
  (⚠ 32-frame accumulator — divide, never read raw) + SDK referee side-by-side per doctrine;
  attribute the frame cost (tile passes? readback? overlay?) before naming suspects.

### ★★★★★★ FNF-7 ROOT CAUSE (07-26 night, 9-agent workflow) — STALE PM4 IN A TRAILING DECODE WINDOW
**FULL DOCUMENT: C:/tmp/flicker/FLICKER_VERDICT.md (571 lines) — READ IT FIRST; it supersedes the
running commentary below, which is kept for the lesson trail.**
VERDICT (confidence HIGH ~0.85 on class, MED-HIGH ~0.6 on site): the port's PM4 decode window for a
TRAILING kick segment covers command-arena bytes the current present did not write; the walk executes
the stale packet(s) there. They carry their own SET_CONSTANT/register writes and their own vertex-fetch
base (0x48BE) pointing into a permanent ENTRY-ERA reservoir, so they render as coherent frozen art at an
entry-era transform, in a render pass opened AFTER the menu pass was ended and blitted. Same shape as
D1-B: guest faithful, OUR host layer at fault. vk_render.cpp already says it (~L3721-3726): "the cure is
upstream: stop the decode window from covering non-command memory".
**RETRACTIONS THIS FORCES (bank them):**
- "GENUINE GUEST EMIT (contiguous VB record)" — OVERTURNED. RenderDoc event lists show the extra draw in
  a LATER command buffer/pass than all 60 menu quads (events_2682_2710.txt, events_2781_3501.txt); a
  guest 61st sprite would be quad #61 of the same batch. Guest-emission family + mid-tick/keyframe
  hypotheses are STRUCTURALLY EXCLUDED for this defect.
- "54-frame beat = animation cycle" — it is the ARENA LAP: 2,097,152 B / ~38,880 B-per-present = 53.94
  → 54, wrap phase pinned (crit_wrap.py). Three stale spots per lap = the 6/1/47 triple.
- "Black box is a separate defect (FNF-9)" — **RE-MERGED INTO FNF-7**: same structural signature (extra
  62nd quad, trailing decode window, own constant upload, vertices from unwritten memory), different
  stale payload. Keep the residue-population caveat (0x8A71000 never appears as an extra in the 48
  sampled soak anomalies).
- **RETRACT "both menu atlases contain ZERO opaque-black texels"** → true only of the two atlases
  censused (0x4C41000, 0x6921000). The **128x128 UI nine-patch atlas (tex=14, base=0x8A71000,
  rdc ResourceId::10582) is 32.7% opaque black**, and EID 85's sampled cell is **53.1%** opaque black.
- **RETRACT "the ONLY renderer source of solid (0,0,0,1) is the never-rendered resolve-target clear"** —
  FALSE. The black is a FAITHFUL TEXEL SAMPLE of that nine-patch cell. **The resolve-target lead is
  CLOSED for FNF-7/FNF-9** (it remains live only for FNF-1's white-fallback sibling class).
- **CORRECT the black box footprint:** measured render-target diff = **30x66 px at x[217,246]
  y[326,391]** (VB positions give 32x66) — not the earlier 18x66 at x216-232.
- **TERMINOLOGY (bank it):** say "SDK referee" or "the futari_recomp D3D12 build" — **never "hardware"**.
  It is a second recompilation, not silicon. Its census is 62 D3D12 draws = 1 bg + 60 quads + 1 host
  composite (eid 285, different PSO); the port's 61 PM4 draws map exactly, its composite being
  vkCmdBlitImage. **The port is not missing a draw.**
- **REGRESSION BASELINE for any fix: 1 anomaly per 18.0 frames in the DORMANT config** (1219 / ~21.9k).
  ⚠ RVK_TRIPUV is ALSO an observer effect (halves the rate, shifts phase) — dormant is the only honest
  regime. ⚠ [drawtrip] is CAPPED AT 64 (vk_render.cpp:5105): every `draws=64` is a SATURATION MARKER,
  not a count; the uncapped tripuv census shows those entry frames reaching **278**.
- ⚠ **INSTRUMENT LANDMINES FOUND TONIGHT (do not repeat):** `ibT` is hard-gated to frames 6000-6030
  (vk_render.cpp:3665) — a guaranteed FALSE NEGATIVE on any shell soak; `RVK_PREROMWIN=0` is NOT a valid
  control (it downgrades the shell to a window that rejects 84.5% of frames, rt.cpp:368-378).
- **OPEN CHEAP LEAD:** who reserves the **16,560-byte hole between d37 and d38**? Present in EVERY menu
  frame (clean and anomalous); 16/22 extras are allocated inside it. Never investigated.
- **BANK (independent of FNF-7, corrects the decomp atlases):** `0x8207C95C/964/974/984/98C` are
  `__savegprlr_17/19/23/27/29` (shell/gen/ppc_func_mapping.cpp:932-944), **NOT context getters** — every
  decomp line `iVar = FUN_8207c9xx();` actually means `iVar = param_1`. Fix force_sweep_d1b.txt and
  ATLAS_INDEX.md. Also: **XenonRecomp DROPS every guest `twi` trap**, so guest bounds asserts are silent
  no-ops in the port — kills any "the guest would have caught this" reasoning.
- **BANK:** `rt_menu_family_vt()` (out_reco/merged/merged_xex.cpp:5993-5997) OMITS `0x82050518` — the
  version-select TOP MENU's own vtable. The heartbeat/census does not cover the screen FNF-7 lives on.
- **KEEP SEPARATE:** the boot-era `n=3 tex=0 fmt=22 base=0x10000000` strays — their signature is `va` ==
  the PREVIOUS frame's last `va` (2166/2441), which NEVER occurs in the menu anomalies (0/22). Related
  disclosure: a renderer-side heuristic already sits on that path —
  `[dimfix] 1x1 fmt=22 white-fallback veil: blend 0x10001 -> 0x7060706`.
- Vertex evidence: 16/22 anomalies fetch from the frame's own skipped 16,560-byte gap; 4/22 past the
  cursor, ALL v0=(0,0); one NaN. Zero/NaN v0 never occurs in ~2.2M clean draw records.
**★ FALSIFIER RESULT (07-26 night, agent; C:/tmp/flicker_falsify/FALSIFIER.md) — THE EXTRA QUAD IS
UNIQUE, NOT A DUPLICATE ⇒ THE "SNAPSHOT THE DRAW LIST AT END OF TICK" BARRIER FIX IS A NO-OP.**
n=5,279 anomaly frames across 7 logs: **5,106 (96.7%) unique**; 173 (3.3%) strict duplicates, 171 of
which are one beat class in one run and are ALIASING not re-emission (the extra's fetch address is a
per-run CONSTANT — 3 distinct `va` in 44,928 presents — while legit draws' `va` sweep the 2MB ring, so
at a 54-present lap a legit slot is periodically allocated ONTO the frozen address). **UV corpus:
0/1080 duplicates.** Control C (score extras against OTHER frames): position matches carry ZERO
within-frame information (null == observed to 3 decimals); VA null 0.111 at the same lap phase vs
0.003 at random phase = 37x phase enrichment = aliasing. Positive control PASSED (synthetic injection,
3 cases, 631/631 each, incl. same-art-different-position correctly NOT flagged).
**BONUS REPLICATION at 240x the verdict's sample size: 96.7% of extras fetch from memory the present
never wrote** (2,129 in the frame's own skipped 16KB gap, 2,865 past its last allocation, 110 small
gaps, 175 aliased) — §1.3 of the verdict confirmed.
**Non-circular confirmation that the extra is LAST:** two content-based identification methods (neighbour
multiset difference; clean-corpus key-budget) both return exactly one extra per frame and it is slot d61
in 5,279/5,279 — settled without using slot index as the identifier.
⚠ **LANDMINE: `tex` in [drawtrip] is a HOST BINDING-SLOT id and is NOT stable across runs** — keying on
it fabricates ~11 fake extras per frame. **Key on `base`.**
⇒ Sites A and B (verdict §3.4) remain the live candidates; the packet-offset instrument is still the
decisive measurement. The Fable panel's "knob A" barrier is dead on arrival — do not build it.

**★★★★★★ DECISIVE EXPERIMENT RESULT (07-26 late, agent; 338 anomaly windows, FIFO, dormant class) —
BOTH NAMED SITES ARE DEAD; IT IS THE THIRD OUTCOME.** Data: C:/tmp/fnf7_atlas/seg/sweep_{segtab,segctrl}.log,
classify_seg.py. Instruments (default-off): RT_SEGTAB (segment table in rt_ks_append + pre-kick address
capture at the kick hook), RT_MVTICK (movie-tick roster on sub_8217F948), `pkt`/`ibd` in TripRec.
- **Site A (relocation race) DEAD:** `pre == src` in ALL 2,028 segments across 338 windows. Zero relocations.
- **Site B (walk overrun) DEAD:** the extra draw's packet is INSIDE captured segment coverage in 337/338
  frames; distance from END of coverage min 208 / median 240 / max 288 bytes — never past it.
- **THIRD OUTCOME 337/338 (99.7%): the packet lies in a properly bounded, address-consistent segment the
  guest itself kicked.** Every anomaly window: exactly 6 segments / 21,428 bytes; the extra is ALWAYS in
  the last segment s5, which is ALWAYS exactly 1,252 bytes (latDw=313 x4 — declared == copied, they agree);
  normal inter-draw gap is exactly 160 B (338/338), but d60→d61 is 1,168 B (270x) / 1,160 B (65x) ≈ 7x.
- **GUEST-SIDE CORROBORATION (movie roster, 7,256 clean vs 279 anomaly frames): the guest's scene state is
  IDENTICAL** — 37 visible parts on both, per-object visible counts identical across all 10 live movie
  objects, 6 ticks/frame on both with every object advancing exactly +1.00. **The guest NEVER reaches a
  61-visible-part state**, so the extra packet corresponds to NO live guest widget. This confirms the
  capture-side exclusion of guest emission from the guest side, independently.
⇒ **NEW SYNTHESIS (the surviving question is narrow):** the guest kicks a final 1,252-byte segment
declaring 313 dwords; we copy and decode exactly that; inside its TAIL sits a well-formed draw packet
matching no live widget. The bytes WERE submitted — they are **stale tail content within a guest-declared
length**, and our walk has no notion of where the guest's LIVE content ends. Target for the next leg:
**length/terminator semantics of the final kicked segment** — does `r6` declare BUFFER CAPACITY rather
than content, and/or does the real command processor stop at a terminator inside s5 that our walk ignores?
Narrow: fixed 1,252-byte segment, stale draw at a near-constant ~240 B from its end.
⚠ **CONTROL-GATE CORRECTION (bank it):** the "within 20% of the 1-per-18.0 dormant baseline" observer-effect
gate is the WRONG gate — FIFO run-to-run variance alone spans 209-349 anomalies in nominally identical runs.
The VALID control is armed-vs-unarmed pairing in the SAME configuration: measured 221 vs 219 trips (~1%),
and the 54-frame period survives at autocorr 0.98 both ways (vs the DRAWTRIP=8 failure mode which collapsed
autocorr to 0.36 and the rate to 0.09%). Also: reading `g_seg_*` at dump time yields the NEXT window — the
table must be snapshotted at the buffered frame's first draw (this bug was caught and fixed mid-leg).

**★★★★★ TAIL FORENSICS (07-26 late, agent; 23 ANOM + 24 CLEAN dumps of s5, RVK_TAILDUMP instrument,
data C:/tmp/fnf7_atlas/seg/sweep_tail.log, analyzer tail_forensics.py):**
- **THE BYTES GENUINELY DIFFER — not "same bytes, different decode".** Head dw0..188 is structurally
  identical in every pair (same TYPE3 opcodes at the same indices); after dw188 they diverge: under a
  linear walk, ANOM tails carry **two complete draw sequences (0x22 DRAW_INDX → 0x27 → reg writes) in
  23/23**, CLEAN tails carry **none in 22/24**. ⇒ the stale packet is ABSENT from clean frames' s5.
- ⚠ **RED HERRING flagged by the agent:** the first differing dword is always dw167, but dw166 =
  `00054800` = a TYPE0 write of 6 dwords to reg **0x4800 (texture fetch constant)** — so dw167 is a
  texture base that legitimately changes every frame. The diff range [167,312] is mostly rotating
  addresses, not stale content.
- **NO TERMINATOR EXISTS** between live and dead content: no TYPE2 NOP run, no 0x00000000/0xFFFFFFFF
  padding run, no end-of-content marker (2 zero dwords, 5 scattered 0xFFFFFFFF). The "CP stops at X"
  hypothesis is UNSUPPORTED by this leg.
- ⚠ **CAVEAT THE AGENT RAISED AND COULD NOT RESOLVE (weigh before designing):** a linear walk from s5's
  start is NOT the parse the engine performs — the engine walks the six concatenated segments as ONE
  continuous stream, so alignment inside s5 depends on everything before it. Proofs: d60's packet maps
  to dw89 by offset arithmetic but a linear walk from dw0 finds no TYPE3 there; and the linear walk finds
  TWO 0x22 while the engine decoded only ONE extra draw. "Which bytes are executable" is alignment-dependent.
- **LENGTH SEMANTICS TRACED (sub_820A8638 @0x820A8638, decomp :51731; caller :51961-51964):** each kicked
  segment is written to the ring as **`{0xC0013F00, addr, len}` = a PM4 INDIRECT_BUFFER**; the authoritative
  values are `len = *(uint*)param_2 & 0x00FFFFFF` (dwords) and `addr = ((uint*)param_2)[1]`. **The contract
  is `[r4+0] & 0x00FFFFFF`, NOT r6** — `rt.cpp`'s `ks_len = ctx.r6.u32` is correct only by a caller-specific
  coincidence (this caller always passes count=1 and leaves the length in r6). ⚠ **LATENT BUG worth
  hardening independently of FNF-7:** any other caller leaving something else in r6 silently mis-sizes a
  capture. Also: s5's declared length is 313 dwords in 47/47 (a FIXED-SIZE trailing buffer) while s1 varies
  frame to frame (4070/4088, content-sized).
- ★★ **LEADING FIX DIRECTION (evidence points here; NOT yet tested):** hardware executes each kicked
  segment as its OWN bounded INDIRECT_BUFFER with its own size; **our port CONCATENATES all six into one
  linear window and walks it as a single stream.** That is a genuine semantic difference, it explains the
  alignment divergence above, and "walk each kicked segment as a bounded IB, exactly as the ring triple
  says" is a RESTORE-THE-GUEST-MECHANISM fix, not a heuristic. The SDK-runtime lane is checking how
  rexglue bounds the same kick — corroborate before building.
- ★ **SECOND LEAD (cheap, one-line):** the anomaly tracks WHICH POOLED SOURCE BUFFER s5 is read from —
  18/23 ANOM read s5 from guest buffer **0x1147AC0**, 18/24 CLEAN from **0x1151160**. The guest cycles a
  small pool of segment buffers and the extra draws live in one of them. ⚠ sampling is biased (consecutive
  frames, pool rotates per frame) — confirm with per-frame `src` logging across ALL frames; **this could
  explain the 54-frame period outright.**

**★★★★★ KICK-LENGTH HYPOTHESIS **REFUTED** (07-26 late, measured): `objDw == latDw` in **ALL 2,152
segments / 359 windows, ZERO mismatches** (RT_SEGTAB + the new kick-time `g_seg_objdw` snapshot;
log /c/tmp/d1b_shellreg_len2.log). The guest really does declare 313 dwords for s5, and our capture
length equals it exactly. So the SDK-runtime lane's "r6 is stale, we copy past the guest's content"
prediction is DEAD on this path — even though its ABI analysis was right that r6 is not the contract.
⚠ **INSTRUMENT LESSON (4th time tonight): the FIRST version of this check read the descriptor at DUMP
time and returned garbage** (objDw = 0 / 3,409,888 / 11 on different segments of the same window) —
the guest reuses descriptor memory, so it MUST be snapshotted at KICK time. A confident wrong verdict
was one build away. Zero now means "not captured", never "the guest said zero".
⇒ **LAST HYPOTHESIS STANDING — WALK ALIGNMENT ACROSS SEGMENT BOUNDARIES.** Hardware (and the vendored
Xenia CP in rexglue-sdk) executes EACH kicked segment as its own bounded INDIRECT_BUFFER, restarting
the parse at that segment's base; **our port concatenates all 6 segments into one linear window and
walks them as a single stream**. If a packet at the tail of s4 declares a length that overruns the
boundary, our walk resumes INSIDE s5 at the wrong offset and reinterprets real-but-stale guest bytes
as packets — which matches every measurement: right lengths, right addresses, no relocation, no
terminator, phantom at a near-constant offset, bytes genuinely differing between clean/anom frames,
and the tail agent's direct evidence that d60's packet maps to dw89 by offset arithmetic while a
linear walk from dw0 finds no TYPE3 there. **DECISIVE TEST: instrument the walk at each segment
boundary — does the walk position `i` equal the segment's base offset when it enters it? Any entry
at `i != seg.off` is proof.** Fix if proven = walk each kicked segment as a bounded IB from its own
base (restore the ring triple's own semantics), NOT a heuristic.

**★★★★★ WALK-ALIGNMENT HYPOTHESIS **REFUTED** (07-26 late, RVK_SEGALIGN instrument, 180s FIFO drive,
14,175 instrumented frames): the walk lands EXACTLY on each kicked segment's base **every time** —
2,060/2,060 boundary crossings on anomaly frames and 53,375/53,375 on clean frames, delta=0, **zero
MISALIGNED lines in the whole run**. Concatenating the six segments is already parse-equivalent to
hardware's per-IB restart. (Controls: signal intact in the armed run — 413 anomalies, period 54,
autocorr 0.99; legit draws in-segment 25,132/25,193 with the 61 exceptions all one ring-wrap frame.
The discriminator is an INTERNAL contrast — 413 anomaly vs 10,712 clean frames in the SAME process —
so it never depended on matching rates between runs.)
⚠ **AGENT SELF-RETRACTION (bank it):** the earlier "d60 maps to dw89 but a linear walk finds no TYPE3
there / 2 vs 0 DRAW_INDX" tail evidence came from an OFFLINE walker that advanced TYPE0 by `cnt+2`
dwords where the engine uses `i += 4*(1+cnt)` = `cnt+1` — it diverges from the engine BY CONSTRUCTION.
Those structural counts are indicative only; the engine's own instrumented measurement is authoritative.
The raw byte-difference between clean and anomalous tails still stands (alignment-independent scan).

★★★★★★ **NEW LEADING HYPOTHESIS WITH DIRECT POSITIVE EVIDENCE — THE TYPE3 PREDICATE BIT / BIN MASKS
(the "§5b" lane).** Measured in the existing tail images:
- **Every `op=0x22` DRAW_INDX header in s5 has BIT 0 SET — 52/52**; the phantom's header is
  `C0012201` (type 3, op 0x22, **predicate bit = 1**) in **23/23** anomaly frames.
- **`op=0x60` appears exactly once per s5 image (47/47)** = `PM4_SET_BIN_MASK_LO`
  (rexglue-sdk/include/rex/graphics/xenos.h:1614). **The guest is actively programming bin masks.**
- **The port's TYPE3 decode (vk_render.cpp:3272 and :3807) extracts only `op=(w>>8)&0x7F` and `cnt` —
  it NEVER tests bit 0 — and implements NONE of PM4_SET_BIN_MASK/SELECT[_LO/_HI] (0x50/0x51/0x60-0x63).**
  The SDK CP skips a predicated TYPE3 entirely when `(bin_select_ & bin_mask_) == 0`
  (rexglue-sdk/src/graphics/command_processor.cpp:876-886).
⇒ Consistent with EVERY surviving measurement: correct lengths (objDw==latDw), correct addresses, no
relocation, no terminator, correct alignment, phantom inside a properly bounded guest-declared segment,
and the guest's scene state showing NO extra visible part (37 on both classes) — **because the guest
legitimately EMITS these draws and hardware simply SKIPS them.** It would also explain the steady-state
61-vs-60 gap, not just the intermittent 62nd.
⚠ **NOT YET PROVEN — the one-field-wide test:** every 0x22 sampled so far lives in s5, and s5 contains
no legit draws, so it is not yet shown that legit draws differ. If the game predicates ALL DRAW_INDX
packets, the discriminator is not the bit but the **bin_mask/bin_select STATE** at that point in the
stream. NEXT (single cheap drive): log `be32(pkt)` for every draw in the [drawtrip] line and compare
bit 0 across d0-d60 vs d61, and decode the 0x60/0x50/0x51 payloads to track mask/select state. Proves
or kills it outright.
FIX IF PROVEN (register-true by construction): implement the bin mask/select registers and honour the
TYPE3 predicate bit exactly as the SDK CP does — restoring guest mechanism, not guarding a symptom —
with an escape lever and the 4-part acceptance test.

**★★★★★ §5b (PREDICATE BIT / BIN MASKS) **REFUTED** — the fix would have been a NO-OP** (07-26 late,
RVK_PREDLOG, 180s FIFO, 14,172 frames). The port now tracks bin_mask/bin_select exactly as the SDK CP
does (0x50/0x51/0x60-0x63, both init 0xFFFFFFFF) and evaluates `(bin_select & bin_mask) != 0` per draw:
- clean frames: predicated 61/61 EVERY frame, **wouldSkip = 0**; anomaly frames: predicated 62/62,
  **wouldSkip = 0**. End state `binMask = binSelect = 0xFFFFFFFF` in both.
- **Outcome (b): the predicate bit is set on EVERY draw, legit and phantom alike — not a discriminator**;
  and the guest programs the mask to all-ones, so the SDK CP would EXECUTE all 62, phantom included.
- **BLAST RADIUS = ZERO** (not "more than the phantom" — none). Implementing predication would be a
  behavioural no-op on this screen and cannot close any part of the 61-vs-60 gap.
- Instrument positive control INDEPENDENT of the engine: re-read from the raw s5 byte images — `op=0x60`
  PM4_SET_BIN_MASK_LO with payload **0xFFFFFFFF in 47/47**, and predicate bit 1 in 52/52 headers. Rate
  control: armed 220 trips vs unarmed 220, identical.
★ **EVERY CP-SIDE ROUTE IS NOW ELIMINATED BY MEASUREMENT:** no length over-declaration (objDw==latDw,
2,152/2,152), no relocation (0/2,028), no terminator (SDK runs the whole declared range), no walk
misalignment (55,435/55,435 at delta 0), no predication, no bin mask. The packet sits in the guest's own
correctly-declared, correctly-aligned, correctly-bounded stream, and the guest's scene graph shows no
extra visible part (37 on both classes).
⚠ **TWO-STRIKES RULE FIRES (agent raised it against its own lane, correctly):** the last two legs (walk
alignment, §5b) each produced a clean positive discrimination but NEITHER produced a fix direction, and
the verdict's candidate list is now exhausted. **Do NOT open a third mechanism leg.**
★★ **NEXT AND ONLY SANCTIONED FNF-7 STEP — PROVE VISIBILITY FIRST (cheap, one drive):** the SDK-parity
comparison that started this whole lane was on DRAW COUNT, not pixels, and verdict §3.3 already lists
"no beat draw has been shown to reach a pixel" as unexplained. The periodic extras sample transparent
black or a small teal chip — plausibly INERT. Settle it: readback with/without the 62nd draw's
contribution, or pixel-history a beat frame. **If no beat draw reaches a pixel, the 61-vs-60 lane is
cosmetic bookkeeping** and the real user-visible artifact is the FNF-9 black box (30x66px opaque, at a
bar's left edge, from the 32.7%-opaque-black nine-patch atlas) — which is where the effort belongs.
Remaining non-CP possibility if visibility IS proven: the referee's guest is genuinely in a different
state (submits 60 where we submit 61) ⇒ divergence is upstream in guest state, not the CP.

**★ VISIBILITY TEST — INCONCLUSIVE, METHOD CONFOUNDED (07-26 late; agent reported it as a non-result
rather than dressing up the numbers).** Route (a) neighbour-diffing assumed the held menu is STATIC and
it is NOT: the static control (61 vs 61) is non-zero in **7/10 bursts**, same magnitude AND same bounding
box (~x216-679, y99-197) as the beat diff. Worse, in the 3 bursts where the control is 0 the animation can
still step between the beat frame and its neighbour — the clip advances one tick/frame and the extra draw
appears at specific clip phases, so **animation step and phantom are correlated by construction**;
neighbour-diffing cannot separate them. Honest bound: deltas of 11.5k-14.4k px over a ~422x88 band are far
too large for any payload class (21.9x21.9 ≈ 480px; 31x32 ≈ 990px), so **≥92% of every delta is menu
animation** and the phantom's contribution is not resolvable at this resolution. **Per-class visibility:
NOT REPORTABLE.** The decisive form NOT run (deliberately, one contained lever): a true same-frame A/B —
render the frame twice, once with the last batch dropped, diff the two readbacks; removes the animation
confound entirely, but requires double-rendering a fragile path (resolve/blit side effects could
double-apply).
**★★ FNF-7 AND FNF-9 ARE ONE POPULATION — MEASURED, and this CORRECTS verdict §3.3.** Extra-draw payload
census across every drive this session, **n = 5,524 anomaly frames**: 0x6921000 2048x1024 = 5,505 (99.7%);
0x4C41000 = 5; 0x57F1000 = 5; **0x8A71000 128x128 (the nine-patch the user's BLACK BOX sampled) = 5
(0.1%)**; 0x1981000 = 2; 0x10000000 1x1 = 2. Verdict §3.3's "0x8A71000 never appears as an extra in any of
the 48 sampled anomalies" was a **small-sample artifact** — at 0.1% incidence you need ~1,000 samples.
⇒ **The re-merge is supported by measurement: same emitter, sampling whatever atlas the phantom packet
references; the black box is the rare-but-VISIBLE tail of the same distribution. So the lane is NOT purely
cosmetic bookkeeping — one member was photographed by the user.**
### ⛔ FNF-7 → BACKLOG (07-26, the two-strikes rule applied)
Three consecutive legs (walk alignment, §5b predication, visibility) each produced a clean discrimination
but NO fix direction, and the verdict's candidate list is exhausted. Per the 07-26 LESSON rule this item
goes back for re-ranking rather than earning a fourth leg. **RESUME RECIPE when it is re-ranked:** the
single cheap experiment that closes it is the **drop-last-batch same-frame A/B** described above; if that
shows the phantom reaches pixels, the remaining non-CP possibility is that the referee's guest is genuinely
in a different state (submits 60 where we submit 61) ⇒ divergence is upstream in guest state, not the CP.
Everything measured is in this file plus C:/tmp/fnf7_atlas/, C:/tmp/flicker/, C:/tmp/flicker_falsify/.

**DEFINING SIGNATURE (use this to recognise the defect class anywhere in the shell):** the extra draw is
issued in a **TRAILING DECODE WINDOW** — a render pass opened AFTER the menu pass was ended and blitted
(evidence C:/tmp/flicker/events_2682_2710.txt, events_2781_3501.txt). ⚠ An extra EMPTY window is BENIGN
(clean frame 2781 has three pass/blit cycles); the defect is a window that DECODES A DRAW.
**TWO SURVIVING SITES + the decisive one-drive experiment + fix designs with escape levers and a 4-part
acceptance test: verdict §3.4 and §4.** Site A = kick-segment relocation race (rt.cpp:1806-1814: ks_len
latched BEFORE the kick, address dereferenced AFTER; the file's own comment notes the dev+0x5c10 callback
can relocate the segment). Site B = walk overrun (vk_render.cpp:3667-3673 bounds only the HEADER; the
payload advance i += 4*(1+cnt) and the TYPE3 initw read at :3778-3780 are unchecked against `end`).
⚠ FORBIDDEN FIXES (§4.1, some already tried and reverted): draw-count clamp, position/texture filter,
break-on-implausible-packet, resync-by-scan, any ordering predicate gating emission. Detection only.
Ship-nothing rule status: FNF-7 has had ZERO ship-nothing legs (SDK referee, atlas poison control, and
the capture work each produced a positive discrimination) — the two-strikes rule does not fire yet.

### FNF-7 transient BLACK QUAD over TOP MENU — CAPTURED 07-26 eve (user F12 burst); = the "menu flashing"
- User capture futari_frame2682.rdc shows a one-frame solid-black rectangle (~x225-255,
  y325-390) over the Ver1.01 bar's left edge; neighbors 2587/2749 clean. PIXEL-HISTORY PROOF
  (rdc_pixhist_2682.py → pixhist2682.txt): the box = **EID 85, an EXTRA n=6 (one-quad) draw
  writing opaque (0,0,0,1)**, absent from the clean frame (its stream ends at EID 40 — same
  8 draws otherwise; rdc_blackbox.py → blackbox.txt). Layers beneath are normal (menu-stack
  n=108 draw; background veil alpha 0.902 at control pixel).
- **Pipeline ID DONE (rdc_eid85_id.py → eid85_id.txt): EID 85 = the NORMAL menu-sprite
  pipeline** (ResourceId 210, VS 208/PS 209, SrcAlpha/InvSrcAlpha), identical to the n=108
  menu-stack draw (EID 40) — NOT the opaque background/veil pipeline (EID 18 = 10594,
  One/Zero). So the menu system emitted ONE EXTRA sprite quad that sampled opaque black
  (black atlas region or a should-be-hidden widget). Reflected uniform blocks read all-zero
  (BDA-fetched constants — reflection can't chase them; the zeros are NOT real values).
- **TRIPWIRE LEG DONE (07-26 late): RVK_DRAWTRIP=N landed in vk_render.cpp** (at the :4905
  ndraw++ site; buffers per-draw n/va/v0/tex/fmt/base/dims/vs/ps on shell frames, dumps any
  frame exceeding N). ⚠ guest-draw count ≠ Vulkan batch count: held version-select = **61
  guest draws** steady (37088/39597 frames), not 8 — set RVK_DRAWTRIP=61 for this screen.
  12-min soak (fnf7_menutrip_soak.sh, log /c/tmp/fnf7_menutrip.log 236MB): **22 frames with
  draws=62 — exactly ONE extra quad each**, position-free multiset diff (scratchpad
  fnf7_diff62.py) says the extra is n=4 vs=1 from the NORMAL menu atlases: x10 tex15
  base=0x6921000, x9 tex9 base=0x4C41000, x1 tex12, x1 tex10. Anomalies CLUSTER right after
  menu entry (f3039-3115 within ~1.3s), not uniform.
- **SDK REFEREE DISCRIMINATOR DONE (07-26 night, agent): VERDICT (b) — the extra quad is
  PORT-ONLY.** SDK settled version-select = 62 D3D12 draws EVERY frame with zero variance
  (60 menu-sprite n=6 quads + 1 bg triangle + 1 host composite blit); 257 frames sampled
  incl. two ~110-consecutive-frame bursts spanning menu entry + 6 spot bursts over a 57s
  hold: ZERO anomalies. Structural license: port baseline {n3×1,n4×60} = same 60 quads +
  triangle. Positive controls held (census PNG reproduces GROUND_TRUTH; detector demonstrated
  ±1 sensitivity on transition frames). Evidence: C:/tmp/fnf7_sdkref/ (caps, per-frame PNGs,
  census json, analysis; repro commands in logs).
- **"Authentic periodic FX / stale-atlas sampling" hypothesis KILLED twice over:** port
  anomalies are NOT periodic — all 22 in ONE ~2.6s burst starting 6 frames after menu entry
  (f3039-3188), zero in the next ~37k menu frames; the extra quad's v0 drifts smoothly
  (-404→-423 = an ANIMATING element), atlas 0x6921000. Position (corrected 07-26 late): centered
  (-404..-423, -258..-263) ≈ screen (217..236, ~97..102) = the HEADER's left-edge zone; the
  user-captured black box shares the x-column but sat at a BAR's left edge (y 325-390) —
  same left-ornament class, DIFFERENT height. Don't assume one fixed widget; the element
  (or per-bar siblings) animates. New shape: during the menu-entry animation window
  the port emits ONE EXTRA animating ornament-class quad that hardware does not — an
  emission/visibility-timing defect in the entry transition, not a texture defect. Nothing
  should render there.
- **ATLAS-STALENESS DISCRIMINATOR DONE (07-26 night, agent): VERDICT (b) REFUTED — not the
  stale-cache class.** 1080 anomaly frames censused, 1080/1080 live-guest-RAM signature ==
  upload-time snapshot (zero stale); both atlases uploaded exactly once, zero re-decodes;
  poison control 4/4 detected an injected 1-bit flip, so the null is real, and an independent
  RVK_DUMPTEX offline decode reproduced every census number. **Crucially: `opaqueBlack = 0`
  atlas-wide** — every black texel is TRANSPARENT black (0x00000000), which under
  RVK_REALALPHA samples A=0 (invisible). **So the atlas cannot produce the captured
  opaque-(0,0,0,1) box: that blackness came from DRAW STATE or a DIFFERENT texture.**
  Instrument: RVK_TRIPUV=1|2 / _BASES / _POISON (vk_render.cpp, default-off); evidence
  C:/tmp/fnf7_atlas/ (verdict_final.txt, verdict_poison.txt, logs, analyze_tripuv.py).
- ★ **NEW LEAD for the opaque black (untested):** the renderer HAS a source of opaque black —
  the never-rendered resolve-target path returns a BLACK-CLEARED image (RGB=0,A=1;
  vk_render.cpp RVK_RESREAL/nrBlackIdx region ~L1859-1935), the exact sibling of the
  index-0-white fallback that produces the FNF-1 blob. If the captured extra draw sampled a
  resolve target rather than the atlas, that yields (0,0,0,1) exactly. TEST: the captured
  frame (C:/tmp/rdc_user/futari_frame2682.rdc) is at a BAR's y; the soak's periodic extra is
  at the HEADER's y with atlas UVs — they may be DIFFERENT draws. Re-census the capture's
  extra draw's texture identity (RVK_DUMP_ON_WHITE-class logging on a repro, or read the
  rdc's descriptor state) before assuming one defect.
- ★★★★★★ **DISCREPANCY RESOLVED (07-26 night, agent) — IT WAS AN OBSERVER EFFECT OF MY OWN
  INSTRUMENT, and the resolution is itself the strongest evidence for the root cause.**
  Controlled A/B, one exe, one drive, only RVK_DRAWTRIP differing (_tmpscripts/fnf7_beat_ab.sh):
  DRAWTRIP=8 (my config: ~61 stderr lines EVERY frame, 236MB log, **~17% frame-time cost,
  51 vs 61 fps**) → 14 anomalies, one ~2s burst, then 15,281 frames of pure 61. DRAWTRIP=61
  (light) → **1219 anomalies spread across the whole hold, gaps repeating 6,1,47 (=54-frame
  beat, three quads per group, ~0.9s)**. My raw log re-parsed unfiltered confirms my run really
  was burst-shaped (33 frames >61; f≥4000 min=max=61) — so the analysis filter was innocent;
  **the heavy per-frame logging SUPPRESSED the defect.**
  ⇒ **THE ANOMALY IS FRAME-TIMING SENSITIVE: lengthen frame time ~17% and it disappears.**
  That is exactly what C1 (sub-frame keyframe-PHASE divergence in the movie evaluator) predicts
  and is very hard to reconcile with C2 (a structural flag/lifetime bug would not care about dt).
  ⚠ CONSEQUENCES: (1) the "burst at menu entry" shape is RETRACTED — the true shape is the
  continuous 54-frame beat; the SDK lane's port-side characterization was read off my perturbed
  log (its SDK-side result — hardware = exactly 60 quads, 257 frames — is unaffected and stands).
  (2) Do NOT drive repeated re-entry; a plain hold yields ~200 anomalies/min. (3) ANY instrument
  attached here must be CHEAP PER FRAME or it erases its own signal. Evidence:
  C:/tmp/fnf7_atlas/{fnf7_beat_dormant.log,fnf7_beat_trip8.log}.
- ★★★★★ **BLACK BOX IS A SECOND, DISTINCT DEFECT (confirmed, RenderDoc post-VS,
  C:/tmp/fnf7_atlas/eid85_verts.txt).** EID 85 = an 18x66px quad at screen x216-232, y327-393
  (matches the photo), UV u[0.0078125,0.2578125] v[0.5390625,0.7890625] (exact 1/128 multiples).
  That UV rect censused against EVERY menu atlas contains white glyph texels in all cases —
  no atlas region there is uniformly opaque black, and both menu atlases contain ZERO opaque-black
  texels overall. **The ONLY renderer source of a solid (0,0,0,1) quad is the never-rendered
  resolve-target clear** (`getOrCreateResolveTex`, vk_render.cpp ~L1859: `VkClearColorValue cc{};
  cc.float32[3]=1.f` → RGB=0,A=1 regardless of UV) — the opaque-black sibling of the index-0
  WHITE fallback behind the FNF-1 blob. It did NOT fire in held-menu sessions (1 resolve target
  registered, zero [resreal]/[resalias]) ⇒ reproducing it needs the CAPTURE SESSION's drive
  (user play path), not a held menu. Geometry also separates the populations: black box 18x66px
  vs periodic extras 21.9x21.9 and 31x32. **Track as FNF-9 (distinct from FNF-7).**
- Periodic extra ART identified (crops in C:/tmp/fnf7_atlas/art/): 8x8 solid **teal #00A69B**
  chip (0x6921000 x[1745,1753) y[1,9), opaque, luma 122) drawn as a 21.9x21.9 quad w/ vertex
  colour 80FFFFFF, plus two 31x32 white GLYPHS from 0x4C41000 — three quads per 54-frame group.
  (Earlier "grey chip" wording corrected to teal.)
- ⚠ (superseded, kept for the lesson) **MEASUREMENT DISCREPANCY — resolved above as an observer
  effect; original framing:** the
  first soak (/c/tmp/fnf7_menutrip.log) showed 22 anomalies in ONE 2.6s post-entry burst and
  none in ~37k later frames; the atlas agent's soak (/c/tmp/fnf7_atlas/fnf7_tripuv.log,
  instrumented build) showed 1080 anomalies STRICTLY PERIODIC at a 54-frame beat (~0.9s),
  always the LAST draw, 3 fixed UV rects, colors FFFFFFFF/80FFFFFF. Both were 12-min held
  version-select soaks. Possible causes: different builds (TRIPUV instrument), different
  DRAWTRIP thresholds/eligibility, my diff script's 62-only + preceding-61-within-5-frames
  filter undercounting, or genuine run-to-run variance. RESOLVE THIS FIRST in the next leg —
  the anomaly's true rate/shape decides whether the periodic quad and the black box are one
  defect or two. (SDK lane is unaffected: hardware never exceeded 60 quads in 257 frames.)
- ★★★★★ **DECOMP MINING DONE (07-26 night, agent) — full report C:/tmp/fnf7_emitter_candidates.md.
  STRUCTURAL FINDING THAT REVERSES THE HOST-EMISSION SUSPICION:** the extra quad's vertex record
  is CONTIGUOUS with the last legit quad (d60 va=0x11D6B80 → d61 va=0x11D6BE0, +0x60) ⇒ **a
  GENUINE GUEST EMIT, not a stale/replayed renderer record.** The guest itself decided to draw
  it. So the divergence is in GUEST-VISIBLE STATE (movie timeline phase), not in our draw walk.
- **The whole TOP MENU is ONE M2Lib movie instance** (`menu_title_menu`, layer key 5 =
  motion/menu_title.lzx; page vtable 0x82050518, ctor sub_821B80D0 UNDUMPED) — header, all 5
  bars, every wing ornament are PARTS of that one movie (2 scene nodes under 1 transform), all
  from atlas 0x6921000. "Which widget" therefore = "which PART/nested sub-movie".
- Entry animation = motion clip literally named **"open"** (12 frames, port-measured);
  FUN_821BB3A8 builds+plays it, FUN_821BB298 is the entry-anim wait state. Per-part draw gate:
  `part+0x1B5 = part+0x1DD && parent+0x1B5` (FUN_8217F318 :178784); timeline advance by +0xC0,
  keyframe interpolator FUN_82179168.
- ★★★★★★ **PACING SWEEP + dt-SOURCE TRACE DONE (07-26 night, agent). C1 IS REFUTED — AND THE
  REPLACEMENT MECHANISM IS NAMED: TICK-vs-PRESENT DECOUPLING.**
  (i) **There is no clock in the movie evaluator's dt: it is a hard-coded 1.0.** Chain (all
  default_decomp_all.txt): sub_8217F948 @0x8217F948 (per-frame tick) reads the DAT_821F85A0
  singleton — `+0x1C==0` selects the INTEGER path → `dt = *(uint*)(DAT_821F85A0+4)`; the
  ctor FUN_82170880 @0x82170880 sets `+0x04 = 1` and `+0x1C = 0`; sub_821706E8 only MIRRORS
  those; an exhaustive scan of all 23 DAT_821f85a0 refs found NO other writer. sub_8217DC10
  @0x8217DC10 then does `+0xC0 = +0xBC * dt` and `+0xB4 += +0xC0`, in FRAME units.
  ⇒ no wall-clock delta exists to jitter, so "sub-frame dt divergence" is impossible.
  ⇒ **the 9e8deda real-clock/KeDelay work does NOT feed this path and cannot fix FNF-7.**
  (ii) Sweep (4 configs x 150s hold, _tmpscripts/fnf7_pacing_sweep.sh, parse in
  C:/tmp/fnf7_atlas/sweep/): **period is FRAME-LOCKED at 54 (autocorr ≥0.98) in every config —
  it never moves.** Frame time was pinned 16.69-16.81ms throughout (the 59.94Hz vblank pump
  owns the rate), yet the anomaly RATE swung 4x with PRESENT MODE: async 3.72% (3 phase slots),
  IMMEDIATE 5.55% (6), MAILBOX 7.83% (8), **FIFO 14.83% (30)**. Heavy per-frame I/O = 0.09%
  and destroys the 54-period entirely (sampling collapse, not event suppression).
  ⇒ the guest animation state cycles rigidly every 54 ticks; what varies is **how many of those
  tick phases our PRESENT samples**. The remaining divergence channel is the relationship
  between guest LOGIC TICKS and RENDERED FRAMES — not any timing value inside the guest.
- ★ **LIVE HYPOTHESIS (next leg): we render a MID-TICK state hardware never displays.** The
  tick is three sequential stages — sub_8217F948 calls FUN_8217DC10 (advance) → FUN_8217F318
  (per-part visibility: `+0x1B5 = +0x1DD && parent+0x1B5`) → FUN_82177318. If our
  capture/present samples the scene graph BETWEEN stages (or the evaluator runs a different
  number of times per rendered frame), we can draw a transient state that on hardware is always
  overwritten before its single per-frame draw. Fits every measurement: frame-locked 54-tick
  guest cycle, rate governed by present mode, suppression under load. TEST (agent spec): hook
  sub_8217F948 (NOT F318 — F948 is the tick entry), emit ONE line per rendered frame:
  nEvalCalls, container+0xB4 at frame end, +0x10C, count of parts with +0x1B5; anomaly frames
  should show nEvalCalls != 1 or +0xB4 advancing by != 1. Positive-control vs the 61-draw steady
  state and the 54-period first; budget to one line/frame (trip8 proved the observer effect).
  Ready-but-unrun: _tmpscripts/fnf7_vblank_sweep.sh (RT_VBLANK_HZ 30/45/90) directly tests
  tick-vs-present coupling.
- ⚠ **FNF-5 RE-CLASSIFIED AS POTENTIALLY NON-COSMETIC (agent lead, unmeasured):** rt.cpp:779-781
  documents RT_GAMEPUMP ticking the game from inside VdSwap — i.e. **present rate == game logic
  rate**. If in-stage logic also ticks from the present path, the measured 45fps in-stage median
  is not merely a frame-rate deficit but **~25% SLOW GAMEPLAY LOGIC** (a CAVE shmup running at
  3/4 speed). Verify before treating FNF-5 as a rendering-cost problem.
- (superseded) **Former leading candidate (C1): keyframe-PHASE divergence** — a sub-frame dt difference into
  FUN_8217DC10/FUN_8217F318 samples one keyframe boundary late ⇒ exactly ONE extra part visible.
  Fits a low, phase-dependent rate. NOTE the implication: if true, the root cause is our
  CLOCK/PACING feeding the movie evaluator (host layer, timing domain), not the draw path.
  (C2): FUN_821BB298's settle branch never clears container+0x0C / parts[0]+0x1DD, unlike every
  other exit path — an asymmetry landing exactly at the 12-frame hand-off.
- **The periodic extra quad is an 8x8 texel GREY CHIP** (atlas 1745..1753,1..9; uv
  [0.85205,0.85596]x[0.00098,0.00879]; luma≈122, opaque, rgbBlack=0) — **NOT black, NOT wing
  art.** ⇒ the photographed OPAQUE BLACK box is probably a DIFFERENT phenomenon; a minority of
  extras are 31x32 font glyphs from 0x4C41000 (third population). Corpus lane is arbitrating.
- Decomp gaps to target next (ranked): 0x82179E68 container emit (⚠ MIS-BOUNDED by 8 bytes —
  same class of Ghidra error as D1-B's FUN_821c5f30; highest value), 0x82168E58 picnode emit,
  0x821BA4D8 ACTIVE state (mis-bounded), 0x821B80D0 ctor, rest of page FSM.
- ⚠ Link-order landmine restated: hooks on 0x82xxxxxx shell functions MUST live in
  shell/gen/rt.cpp; sub_82168E58 is already owned by merged_xex.cpp ([flush]) and reachable via
  rt_picnode_report — reuse that seam.
- Next: emitter identification at the entry burst — re-enter the menu repeatedly with node
  identity instruments (RT_TXTNODE class) + the atlas-agent's UV dump (names the art the quad
  references even though its emission is the defect). Atlas-staleness leg result folds in as
  art-identification, not cause.
- Still unresolved (separate): boot-era stray `n=3 tex=0 fmt=22 base=0x10000000` d0 records
  (2442 in log, va = previous frame's last record) — same placeholder-texture class as the
  FNF-1 blob; possibly a frame-boundary stale-record mechanism, measure before merging defects.
- ⚠ Instrument knowledge banked: multi-frame RenderDoc = qrenderdoc --python +
  ExecuteAndInject + TargetControl.TriggerCapture(N) (renderdoccmd CANNOT queue bursts);
  qrenderdoc python is 3.6 (SyntaxError fails SILENTLY); hard ~116-captures-per-process
  ceiling (E_OUTOFMEMORY) — keep bursts ≤115.
  Evidence: C:/tmp/rdc_user/{futari_frame2682.rdc,pixhist2682.txt,blackbox.txt,eid85_id.txt,png/},
  /c/tmp/fnf7_menutrip.log.
- Title-screen burst (2262-2323): PRESS-START blink + glow ramp = AUTHENTIC (oracle-banked),
  not a defect. Card-page clipped-text fragment (frame 3631 bottom-right) = the KNOWN Fix A
  residual (corner-origin class), do not double-count.

### FNF-6 keyboard dead in playtests — FIXED 07-26 (harness gap, not a regression)
- Agent audit verdict: keyboard lives behind RT_PAD_HOST (stubs.cpp:573/638; GetAsyncKeyState,
  focus-independent) and NO playtest harness ever set it — the launcher banners advertised
  bindings the env never enabled. Controller (XInput) was always fine (press edges in logs).
- FIX: `export RT_PAD_HOST=1` added to playtest.sh MODE=play; `set RT_PAD_HOST=1` added to
  playtest_rdc.cmd, package_fnf.sh's PLAY.cmd heredoc, and the staged C:/tmp/futari_fnf/PLAY.cmd.
- Acceptance: session log shows `[padhost] ACTIVE (GetAsyncKeyState)`. Known side effects
  (documented, accepted): keystroke edge channel wakes (historical menu double-fire), and
  GetAsyncKeyState is system-global (typing in other windows reaches the game).

### FNF-8 alpha-package QA (07-26 late, agent) — LAUNCH PASSES; 2 code fixes queued
- Full launch QA PASS on C:/tmp/futari_fnf: double-click boots to 59.9fps, [padhost] ACTIVE,
  log lands in dist, SEND_LOGS zip valid, README keymap matches engine km[] table.
- **P1 HIGH (code, QUEUED): window X does not quit** — rvkWndProc WM_CLOSE only sets gw.closed
  (read at vk_render:~3124 to skip presents); process runs on, holds the log handle, and a
  relaunch contends on save_playtest. Fix: WM_CLOSE → orderly exit (PostQuitMessage + a host
  exit path). Our own README tells testers to close-and-relaunch — currently broken advice.
- **P2 MED (code, QUEUED): stderr block-buffered** — log stays 0 bytes ~40s; early-crash logs
  (the ones we want from testers) are lost. Fix: setvbuf(stderr, nullptr, _IONBF, 0) at boot.
- P3/P4/P5 (launcher scripts) FIXED in package_fnf.sh 07-26: absolute exe path (survives
  NoDefaultCurrentDirectoryInExePath), SEND_LOGS error handling + no-logs guard, seconds+
  fallback in log timestamp. Dist NOT re-staged yet — wait for final exe (atlas-agent
  instrument + P1/P2), then `bash _tmpscripts/package_fnf.sh` + quick re-QA.
- ⚠ P1/P2 edits touch render/vk_render.cpp — DO NOT apply while the atlas-discriminator agent
  owns that file/build.

### ✅ FNF-10 **FIXED AND SHIPPED 07-27** (56939c6) — 8-slot LRU cache keyed on (idx, quantum)
REPRODUCED on the ship path first (doctrine step 0): `_tmpscripts/save_persist_ab.sh` boot 1 —
the drive that walks the OPTION menu — logs the alternation directly: q=14,16,14,16,14,16,14.
⚠ My first repro attempt used `run_options_save.sh` and saw only 1 load; the audit's number came
from save_persist_ab.sh. Check a claim's PROVENANCE before either trusting or dismissing it.
MEASURED: boot-1 reloads **7 → 2** (audit's acceptance was ≤2), cache hits **0 → 7**, persistence
**PASS → PASS**. No visual regression: 4_legal bit-identical; topmenu/card mean +0.014/+0.005;
**6_attract's WALLPAPER BORDER bit-identical (0 differing px, masked to x outside [395,885))** —
all 305,948 differing pixels were the centre panel at a different animation phase (CAVE logo fade
+ press-start), i.e. the known animated-content confound, not a regression.
Leak now CAPPED at 8 slots (eviction still cannot vkDestroy — may be blit-in-flight). Lever
`RVK_WALLQKEY=0` restores the old index-only key.
★ **PERSISTENCE GATE RE-VERIFIED on the current build: PASS** (boot 2 loads wp02.bin). The earlier
"never re-verified" framing is retired — it was 5 commits stale, and it now isn't.

### (original entry, kept for the trail) FNF-10 — WALLPAPER DIM CACHE THRASH + DESCRIPTOR LEAK
Full audit: C:/tmp/wallpaper_audit/WALLPAPER_AUDIT.md.
`menuLive` flips the wallpaper dim 0.900↔1.000, which flips the 1/16 quantum 14↔16, which invalidates
the wallpaper cache (vk_render.cpp:6678-6681) and forces a FULL 3.6MB re-read + swizzle + fresh
`uploadTexToDesc` **on every menu open and close**. MEASURED: **50 reloads in one scripted options walk**,
25 in an RDC session. Line :6680 drops the old texture WITHOUT destroying it ("leak-by-design"), so each
reload permanently burns a descriptor set from a pool of 256 (:2868) that is **SHARED WITH THE GUEST
TEXTURE PATH**. Exhaustion → VKC fail → `g.failed = true` → **silent renderer death, visually
indistinguishable from FNF-2**. ⚠ Do NOT merge with FNF-2 without evidence (FNF-2's signature is
`FAIL submit = -4` = VK_ERROR_DEVICE_LOST; pool exhaustion would surface a different code) — but a
long options session is now a PRIME suspect for user-visible "it just froze".
CHEAP FIX (a decision, not a rewrite): key the cache on `(idx, q)`, or move the dim multiply to blit
time — the latter also dissolves the D3 quantization debt for free.

### Wallpaper (pillarbox border) — audit verdicts 07-26
- **Load/upload WORKS; the one observed failure was DOWNSTREAM of device loss — CONFIRMED by the submit
  TAG, not by timing**: `d1b_shellreg_fnf_new.log:1755` is `FAIL submit(upl) = -4`, `upl` being the tag
  inside `uploadTexToDesc` (vk_render.cpp:2483); VKC (:428-429) returns false and :1756 is that return.
  The file itself read fine.
- **In-session switching VERIFIED end-to-end** (persist/boot1.log 1065→1068→3096→3099→3112: guest
  decides → guest opens → host tracker → host reloads).
- **PERSISTENCE ALREADY PASSED — my "never re-verified" framing was too pessimistic.** /c/tmp/persist/
  boot2.log is dated 07-23 21:55, one minute before fe456f6 landed: those logs ARE that commit's
  acceptance run, and boot 2 shows `[wpidx] wallpaper -> wp02`. The gate is **5 commits STALE, not
  never-run** (re-run cost ~4 min, ranked W4 = highest value/cost of the wallpaper items).
- **The wallpaper setting is ONE BYTE: `savegame.bin +0x16DB`** (freshcard vs persist diff = exactly one
  byte, 0x00→0x01). ⇒ the WRITE half of the persistence gate is now a one-line `xxd` check instead of a
  two-boot drive, and it separates a write regression from a READ regression. Retires the
  ATLAS_save_settings.md:379 hypothesis that the wallpaper edit may never dirty the compared blocks.
- **D3 dim quantified exactly:** every RVK_WALLDIMLOG sample reads `tgt=cur=0.900 fade=1.0 flash=0.0`;
  port renders `lround(0.9*16)/16 = 0.875` = **−2.78%**; quantization enters at ONE line,
  vk_render.cpp:6677. Formula confirmed register-true vs decomp (default_decomp_all.txt:181891, :181866).
- **Pre-ROM: never composed** — the whole wallpaper block is nested inside `pillarbox >= 2` (:6520),
  which auto-resolves to 0 pre-ROM (:6421). ⇒ **FNF-3 is a COMPOSE GATE, not missing state: the guest
  already has the correct wallpaper LOADED pre-ROM** (guest opens wp02 at boot1.log:1068; renderer first
  touches it at :1946, ROM handoff in between).
- ⚠ **CLOBBER DEBT IS REAL AND FIRED DURING THIS AUDIT:** `play_shellnative.sh:95` wipes the save card
  unconditionally every boot ⇒ any persistence test run through that script FAILS FALSELY. `playtest.sh:111`
  already has the corrected guard. **This resolves FNF-4 benignly:** save_playtest matched freshcard
  because nothing save-worthy changed, NOT because of a clobber.

## Not-yet-triaged user symptoms
- "Menus flashing when left running": leading candidate = FNF-2 aftermath; the 07-25 hunt's
  fenced-luma verdict (NO frame flashing on healthy boots) still stands. If user reports
  flashing on a session whose log has no -4, THAT is new evidence — collect the log.

## 2026-07-27 evening — LIVE-DRIVE SESSION (computer-use eyes + FIFO pad): perf unified, FNF-11 repro'd

### Perf story UNIFIED (task #17): every "slow" complaint is ONE defect — worker render vs the 16.6ms budget
- Worker render cost by phase (wperf/perflog2, decoupled, this session's live drive /c/tmp/live_backout.log):
  shell/pre-ROM menus ~5.3ms (pace PERFECT age-1 300/300); in-stage idle ~10-13ms; in-stage COMBAT
  (50s scripted fire+weave) 17.7-19.6ms; **TRAINING MENU 17-19.6ms sustained** — its PM4 window is
  0x1B5F0-0x1CA7C (112KB+), BIGGER than combat windows (0x9A88-0x175D4): attract scene renders
  UNDER the menu overlay. Any excursion past 16.6ms collapses [pace] age-1 to ~0 with repeats/skips
  50-87/300 == the judder/slow feel. Guest ticks hold 59.9 throughout (decouple itself is sound).
- perflog2/3 attribution in-stage: tex lookups ~2ms(n=285), cst/vtx negligible, **other(PM4 walk/
  extract/batch) 5-6.4ms**, tail (tail-misc+segflush+pbxA) ~4ms, publish ~2.5ms, ~10 fence waits/frame.
  No single hot spot — distributed CPU cost. Fix lanes: PM4-walk/extract optimization, fence-wait
  reduction (staging ring), publish cost, pbxA (WC-read class crept back to 1.35-2.05ms).
- **"now loading" streaming theory REFUTED**: menu-phase decode 0.2-2ms; texcensus flat at 100
  uploads/~84MB all session — nothing re-streams per frame. Menu "glitching" = the repeats/skips
  above (+ FNF-7 quad class).
- **No-coalesce drain (f9eae87) REGRESSED and was reverted to default-off (334c99f)**: rendering
  every window at >budget cost backs the queue to ages 4+, repeats/skips 40-85, and starved ticks
  to 42.7/s (playtest_0727_1942). Coalescing is the pacing mechanism until render cost is under
  budget. RVK_NOCOALESCE=1 remains as the A/B lever — retest after the cost fix.

### FNF-11 (NEW): RETURN TO TOP MENU handback = stuck broken compose ("the crash" — it isn't one)
- **Deterministic scripted repro** (this session, watched live): training panel -> Start Training
  (live stage-3 play, field=1) -> B, B (confirm dialog トップメニューに戻ります) -> **A (confirm)**
  -> screen freezes on broken compose: solid bright-GREEN center panel where menu banners should
  be, misplaced border fragments, attract rings + character art still composed around it. Matches
  the user's 1917 frozen screenshot exactly. My earlier bwedge runs never CONFIRMED the dialog —
  that's why 5xB alone showed healthy dialogs on both arms.
- **Engine stays fully healthy**: presents 59.9-60/s, worker 8.7ms, pace age-1 300/300, process
  alive, NO fatal/signal. Guest LOGIC responds to input (mstate 0x82061D50->0x82061D70 + new model
  bind on A/START/B presses) but the PICTURE never changes. Survivability correctly saw no death.
- Log signature at the freeze: [navreal] st 5->2 then 2->5 (handback bounces back), OUTER66a8
  stays 5, SESS678c 4->1, [mstate] BA4D8(ACTIVE) stable, and **[rvk] degenerate M2LibMatrix
  WARNING firing continuously** (x25600, x25856... every 256 draws, tx=146.25 ty=-280.00,
  repair=OFF register-true) — D1-B-adjacent: guest parks transforms during the transition and
  never unparks, OR the menu model's textures are torn down while draws continue (green = suspect
  uninit/misformat sample, possibly YUV-zero-ish).
- Evidence: /c/tmp/fnf_backout_repro/live_backout.log + computer-use screenshots (saved to disk).
- Next leg: SDK referee A/B — drive futari_ref through the same RETURN TO TOP MENU confirm and
  read what its scene/state does (does hardware hand the display back to a shell scene our port
  never composes?). Then name the green quad's texture binding (RVK fetch-const dump at the
  freeze) before touching any code.

## 2026-07-27 late — PERF LEG LANDED (task #17): worker under budget in BOTH heavy phases
Three fixes, each measured before built ([perflog2] im/pipe/reg sub-timers added 4404b2f):
1. **IM_LOAD result cache** (4404b2f): matchImLoad full-ucode FNV + 51-entry scan ran on all
   ~575 IM_LOAD/frame = 2.3ms. Cached by (addr,size,stype), validated per hit on first-32 +
   last-16 ucode bytes. im 2.3 -> 0.02ms. RVK_NOIMCACHE=1.
2. **getTexIndexReal getenv hot fix** (4404b2f): RVK_RAWDUMP2/RVK_ZSCAN getenv per call
   (~1060 CRT-locked calls/frame) — third instance of the regprobe class.
3. **RVK_RESALIAS verdict cache** (4dddf59): sibling scan = ~530 lookups x ~94 resolve targets
   = ~50K map iters/frame (tex bucket 3.0ms). Gen-stamped (g_resolveGen: entry creation +
   everRendered flips via rvkResMarkRendered). tex 3.0 -> 0.05ms. RVK_NOALIASCACHE=1.
RESULT (decoupled, scripted drive + live-play combat): training menu render 18.1 -> 10.6ms
tot 13.2; in-stage combat render 8.3-9.0 tot 10.7-11.5; [pace] age-1 300/300 with repeats/
skips 0 in BOTH; ticks 59.9 flat. The judder/slow-feel mechanism (render > 16.6 budget ->
age collapse) is closed at these loads. OWED: full field-oracle texel diff before ship gate
(alias/im caches are memoization — staleness windows argued closed, not texel-proven);
re-test RVK_NOCOALESCE=1 now that cost is under budget (may buy age-1 at zero drops under
transient spikes); user feel test at stage 3.
Residual (not blocking): "other" 3.4-5.1ms walk machinery, publish 2.5ms, pbxA sync readback
~1.9ms + segflush 1.6-2.0ms tail — next candidates if heavier scenes ever exceed budget.

## 2026-07-27 late — FNF-11 part 1 SHIPPED (3ab79e3); part 2 OPEN; FNF-12 logged
- Part 1 (decomp-grounded, NOTE_fnf11_handback_decomp.md): guest state-2 teardown now signals
  rvk_handback_invalidate (sub_8813A5F0 wrapper) -> render worker drops rTexIndex/reval maps +
  bumps g_resolveGen. Accepted live: [hbinv] 159 entries at st 5->2, rebuild renders CORRECTLY
  where the green freeze used to be. RVK_NOHBINV=1 reverts.
- Part 2 OPEN: user recipe "select 1.5 arcade, A, B, A to quit" — menu-level quit breaks compose
  (slate-blue solid panel, matches user's original frozen screen class) WITHOUT st 5->2, teardown,
  or hbinv. Engine healthy (age-1 300/300, 59.9 pres/s), continuous degen-matrix warns. NOT
  texture staleness. Suspects: menu scene transform/state rebuild; a different quit route (CLOSE
  item? shell-level?). Evidence: fnf_backout_repro/fnf11_fix_partial.log + screenshots.
- FNF-12 (new, user obs): NOW LOADING pic flickers during boot-logo fades (CAVE->M2 fade-to-black).
  Task #20.

## 2026-07-27 night — FNF-12 CAPTURED (17.3fps PrintWindow burst, /c/tmp/fnf12_evidence/)
Burst harness: _tmpscripts/burst_capture.ps1 (PrintWindow PW_RENDERFULLCONTENT loop; 950 frames/55s).
THREE distinct artifacts visible in the boot-logo sequence:
- **(a) Loading spinner exempt from fades** = the user-reported flicker. f00168 (t=6.0s, CAVE
  fade-out) and f00277 (t=9.6s, M2 fade-out): the cyan NOW-LOADING spinner renders FULL
  BRIGHTNESS while the whole scene dims — it pops into view against the darkened frame. On
  hardware the fade covers all layers; our compose draws the spinner above/outside the fade.
- **(b) Tile seams on flat frames**: f00277/f00293 show the scene composed as 2x2 tiles
  (boundaries ~x=512, ~y=480) with BLACK GAP LINES between them, visible whenever the frame is
  a flat color mid-fade. Compose misalignment/gap in the EDRAM-tile reassembly.
- **(c) Black parallelogram during title fade-in**: f00305 (t=11.08s) — a huge rotated solid-
  black quad slashes across the composed title logo. Park/matrix-class transition quad drawn
  when it should be invisible.
Opus decomp agent (running) is mapping the loading-pic scene + hide chain — pair (a) with its
findings before coding. (b) and (c) are renderer-side compose defects, likely independent.

## 2026-07-27 night 2 — FNF-12 ROOT NATURE REFINED + REFEREE A/B (defect CONFIRMED port-side)
- f00053 (t=2.19s): the ENTIRE NOW-LOADING scene ("Now Loading・・・" text + ring-cluster anim)
  composes OVER the CAVE logo scene, full-bright. f00067 (t=2.65s): still present, ghosting
  through the full-white CAVE screen. The loading scene is NEVER DISMISSED when the logo
  sequence starts — it lingers through boot (spinner flashes at 5.5s/9.6s are its anim cycle
  peaking through the fades). NOT a fade-exemption: a scene-dismissal miss (user's long-standing
  "now loading animation still going" instinct = correct).
- REFEREE A/B (clean D:\ v1.3.6, same burst harness, 35s): fade windows SPOTLESS (max 17-53 vs
  port 134-255). Confirms port defect. Ref burst /c/tmp/fnf12_burst_ref; key frames in
  fnf12_evidence/ref/.
- Fix awaits the Opus decomp agent's loading-scene hide-chain map (running). Artifacts (b) tile
  seams + (c) black parallelogram remain separate renderer compose defects.

## 2026-07-27 night 3 — FNF-12 sub-artifacts (b)/(c): geometry measured, instrument plans set
- (b) TILE SEAMS (f00277): vertical gap x=513-523 (11px), horizontal gap y=447-456 in-frame
  (10px) — boundaries at 512/448; right/bottom segments placed ~11px too far. Per-tile means
  ALSO differ (TR 111.7 vs BL/TL 117.1, BR 119.0) => placement AND per-seg dim both off during
  fades. Plan: hold a logo frame (RVK_COMPDBG + seg-rect dump) and read the seg dst rects
  directly — no eyeball fixes (seg-transform doctrine). Likely same seg arithmetic serves the
  menus fine (no visible seams there) — fade-specific layer? verify which scene emits 512x448.
- (c) BLACK PARALLELOGRAM (f00305, t=11.08s title fade-in): large rotated quad (~68 deg edge
  slope) drawn solid black across the composed title. Pixel isolation is noisy on the dark bg;
  needs a draw-level dump in the fade window (RVK_DEBUG_OPS at the title fade frame range) to
  name vs/ps/matrix. Park-class suspect (transform mid-unpark drawn visible).
- Watchdog whitelist landed (bdeb0a9). Texel gate for the perf caches RUNNING (qa_playab
  MODE=lever, caches-off as lever; expect aa-floor MAE if pure memoization).

## 2026-07-27 night 4 — TEXEL GATE PASSED for the perf caches (owed item closed)
qa_playab MODE=lever (side B = RVK_NOIMCACHE=1 RVK_NOALIASCACHE=1 RVK_NOHBINV=1) vs same-day
MODE=aa floor: lever WHOLE MAE 33.7 vs aa floor 24.7 — but per-pair analysis is decisive, not
the means: lever MAE grows monotonically 12.7->51.7 across the stage (temporal drift as sprite
density rises), early pairs AT the floor, diff heatmaps pure edge/sprite motion (pair2 read:
identical frames, no structured/static regions); aa per-pair spans 8.2-42.9 with the same
late-drift shape (distributions overlap; lever run drew worse pairing margins 44.9% vs 61.6%).
A flat-offset or structured signature (what a stale-cache defect produces) is ABSENT.
VERDICT: im/alias/hbinv caches are texel-neutral. Runs: /c/tmp/qa_ab/0727_111838_lever +
0727_112249_aa. (Doctrine note: single-run lever MEANS are drift-luck; judge lever A/Bs by
per-pair shape + early-pair floor from now on.)

## 2026-07-27 night 5 — FNF-12(c) draw-level candidate captured
fnf12_segdump.sh (RVK_DEBUG_OPS=640 = title fade-in window) caught, first in the dump: a
RECTLIST quad vp={0,0,1280,720}, corners (-356.5,-261.5)/(411.5,-261.5)/(411.5,50.5), vertex
color 0xFFB5B5B5 (grey — dims to black under the fade), vfetch op=0x36 va=0x129D4B0. Shape+
timing match the black parallelogram if its VS matrix carries rotation mid-transition. Full
attribution (which scene, what matrix, why visible) awaits the Opus intro-chain map — dump
parked at fnf12_evidence/segdump_boot.log. COMPDBG note: wallbg/seg lines don't fire in the
shell logo path (0 lines) — seam analysis (b) needs a different instrument (seg dst-rect log
for the logo scene's compose, TBD after the scene map).

## 2026-07-27 night 6 — FNF-11 CLOSED (part 2 fixed: 1fe6b39); NOCOALESCE retest equivalent
- Opus decomp verdict: menu-level quit is NOT a handback — B == RETURN TO TOP MENU byte-for-byte
  (FUN_821D0CB0(-1)); confirm sends msg 13 + msg 3 + XexUnloadImage. ROM UNLOADS; shell TOP MENU
  (vt 0x82050518, menu_title_menu) owns the display. Port defect: g_rt_romactive never cleared +
  XexUnloadImage a no-op => presents stuck on the dead ROM spine.
- FIX: clear g_rt_romactive in the XexUnloadImage handler (field-inactive guard, loud per-call
  log; RT_NOUNLOADCLEAR=1 reverts). Note: the guest's [0x821F8588]+0x64 shell-owns byte NEVER
  sets in our port (FUN_821CE400 path unreached — flag for a future faithfulness pass); the
  rt_rom_render check for it remains as inert extra safety (RT_NOSHELLOWNS=1).
- ACCEPTED: quit -> composed shell TOP MENU (screenshots); Ver 1.5 re-entry -> ROM re-boots into
  healthy attract ranking. Full round trip. Logs /c/tmp/fnf11p2_fix2.log.
- Degen-matrix spam during these transitions = new top-menu items born hidden at scale 0 —
  FAITHFUL (D1-B rule holds, repair stays off).
- NOCOALESCE retest under new perf: age-1 300/300, repeats 0, drained 1.00, ticks 59.9 — but the
  coalescing default measures identically at this load; NO default flip (no measured benefit),
  lever retained for spike investigation.

## 2026-07-28 early — FNF-12: hider PROVEN never to run (RT_LOADPROBE)
Element records (ctx+0x4C/50/58/5C from sub_821CD4B0; millicode passthrough r3): ALL FOUR go
+0x0C hide=0 early in boot; ZERO transitions back to 1 over 40s spanning every logo fade.
The dismissal path (whatever sets hide=1 / runs the FUN_821CD140 ramp) never executes in the
port. Decomp agent resumed to name the exact condition chain (FUN_821cd490/821cdb08 ticks,
the loading-done flag they poll, FUN_821CD140 callers). Probe committed default-off.

## 2026-07-28 — FNF-12(b) widened: edge margins on title/top-menu (user-spotted, "it's the wallpaper")
User playtest: ~8-10px of the UNDER-WALLPAPER shows along the right + bottom window edges on the
shell TITLE and TOP MENU screens — the scene compose falls short of the window edges and the
full-window wp blit peeks through. THIRD sighting of the placement-arithmetic class: interior
seams x=513-523 / y=447-456 during fades (burst f00277/f00293) + this outer-edge shortfall.
One defect family: shell-scene seg/compose placement off by ~10-11px at tile boundaries AND at
the outer edge. Fix needs the actual seg dst rects on a held shell frame (planned instrument,
ledger night-3) — no eyeball scaling fudge (doctrine). Alpha-1 polish item.

## 2026-07-28 — CORRECTION (user evidence): edge margins are POST-QUIT ONLY, not the seam class
User: "on a fresh boot theyre gone, only show up when i back out" + clean title screenshot.
The right/bottom wallpaper margins appear ONLY after ROM quit -> shell return (the new FNF-11
part-2 path). RETRACT the "one placement class" merge (579db6f): interior fade-seams DO occur
on fresh boot (burst evidence); edge margins are post-quit state divergence — the shell compose
consumes ROM-era register/display state after XexUnloadImage (sticky register file; hardware's
shell would re-init). New defect id: FNF-13 (post-quit shell compose margins). Repro: quit to
top menu, look at right/bottom edges. Fix lane: identify which regs/state our shell compose
placement reads (viewport/PA/scale) and what the shell re-inits on hardware vs our sticky file.
### FNF-12 fix contract (Opus decomp, NOTE_fnf12_loading_overlay.md): hide byte is a RED
HERRING — hardware also never sets it for the loading elem; elements are BUILT at alpha 0 and
hidden by per-element alpha (low byte of elem+0xFC via FUN_821796B0/FUN_821CD120 ramp; probe
addrs +0x5C/60/64/68 are the real elements — my earlier probe read +0x4C/50/58 = list nodes/
container, no signal). Port contract: honor per-element packed alpha AND the +0x0C skip (logo
fades need the latter). DO NOT force-hide (fudge). Suspect our port resurrects alpha-0 draws
via a zero-constant repair lever (RVK_C255-class) or by ignoring the alpha channel the guest
supplies — needs the draw-level measurement (OPS dump at overlay-visible frame; blocked while
user plays). Constants: fade = exactly 60 frames (1/60 steps).

## 2026-07-28 — user theory (fits burst evidence): loading "blob" = missing BACKGROUND + persist trails
The ring CLUSTER in f00053 (~10 overlapping spinners) = TRAILS: if the loading screen's bg
element doesn't render (alpha-0 mishandling, same contract class), RVK_PERSIST's EDRAM model
accumulates each ring position over the last — nothing wipes. When a logo scene's bg paints
(f00147+), old rings get covered each frame and only the live ring shows. Connects FNF-1's
original "blob" naming to the FNF-12 alpha contract — one honoring fix may clear both faces.

## 2026-07-28 — FNF-12 VERDICT: GUEST IS FAITHFUL; ghost = COMPOSE/PERSIST class (probe2)
Corrected RT_LOADPROBE (elems +0x5C/60/64/68, watching hide + colorFC alpha): elem0(loading)
runs the FULL correct lifecycle in our port — unhide, ramp 8->255, hold, ramp ->0, RE-HIDE at
alpha=0 (~t=2.6s; matches reference timeline). connecting/accessing/replay stay hidden always.
=> The guest dismisses the overlay CORRECTLY. The spinner seen at t=5.5/9.6/11s is NOT drawn
by the guest — it is STALE PERSISTED CONTENT from the legit loading phase (user's trails
theory, generalized): our RVK_PERSIST/layer-seg compose keeps loading-phase pixels alive and
the logo scenes' fade quads (fullscreen FF8D8D8D vertex-ramp quads on layer-segs, compdbg
LAYER-SEG 0/1) do not cover them the way hardware EDRAM stacking would.
UNIFIED CLASS: ghost spinner + fade tile-seams + title-fade black slash = one defect family:
the port's heuristic compose/persist model vs hardware layer semantics in the shell intro.
### DIRECTION (user-ratified "decomp 1:1 time"): decomp the shell compositor/layer pipeline
(FUN_821CDBE8 manager family: layer stacking, clear policy, segment targets, veil interaction
FUN_82182A68) and implement the intro compose 1:1 — retire the heuristic persist/seg model for
shell scenes. This IS the alpha-1 intro-1:1 leg. Evidence: /c/tmp/loadprobe2.log,
fnf12_segdump (OPS=300: spinner-position draws @ centered x 370-475 carry the CLIP's own
vertex alpha pulses DC/B6/FF; logo ramps ride vertex colors FF8D8D8D — both faithful).

## 2026-07-28 late — SEAM hunt: scale theory DEAD (measured); tiling-boundary suspect
M2-fade draws dumped WITH live VS matrices (new c0/c1/c3 rows in the ops dump): every draw
carries the clean constant screen transform c0.x=0.5625, c1.y=-1, c3={0,0,-1,360}; the white bg
is ONE fullscreen quad (-640.5..639.5 with the uniform -0.5 bias). No 2% anywhere in geometry
=> SPEC #3's "canvas->clip scale error" hypothesis for OUR port is REFUTED by measurement.
Seam boundaries 512=16x32 / 448=14x32 are Xenos MACRO-TILE aligned; seams appear ONLY in the
M2 fade (the phase that exercises the frame-restore chain: veil active -> clear byte 0 -> LOAD
+ the guest's restore draw sampling the 0x723000 1280x720 resolve). Suspect: our tiled-texture
decode/copy at macro boundaries in that chain (RVK_TEXPITCH class). NEXT INSTRUMENT: on a
seamed frame, RVK_DUMPRES the 0x723000 resolve + the composed output — if the seam is IN the
resolve texture readback, it is the untiler; if only in the compose, it is the restore draw.
STATUS AFTER TONIGHT: ghost ✓ slash ✓ (54fa244); seams = M2-fade-only cosmetic (~1s), OPEN.

## 2026-07-28 latest — user re-test: TWO residuals named precisely
1. **M2-hold ghost persists** (user + re-scan: stationary dark ring, ~150 px constant through the
   bright hold t=6.5-8.4s, one cyan flash f00248; becomes the fade ghost). Guest dismissal proven
   + per-frame clear proven ⇒ mechanism = SELF-SUSTAINING RESTORE LOOP: guest restore draw
   samples resolve 0x723000; our LAYER-SEG resolves write it only PARTIALLY (compdbg: 2-batch
   segs, nonclear=53k px) so the loading-phase ring never leaves the resolve; each frame re-
   imprints it. On hardware the resolve carries the FULL accumulated EDRAM frame. Fix lane:
   make the shell resolve carry the full composed frame (resolve AFTER full accumulation, or
   clear-init the resolve target when the clear byte fires). NEXT INSTRUMENT: RVK_DUMPRES of
   0x723000 during the M2 hold — the ring should be visibly baked in it.
2. **Stray text glyph on TOP MENU** (user screenshot: single 「を」 from the description string
   floating beside Ver1.01) = FNF-7 extra-draw class; RVK_DRAWTRIP instrument is purpose-built
   for it (buffer shell-frame draws, dump when count exceeds N).
Everything else user-confirmed good ("otherwise yep nice").

## 2026-07-28 ~00:40 — FNF-12 CLOSED: the M2 cross/seams are AUTHENTIC 360 CONTENT (Xenia referee)

Night arc, 3 refuted hypotheses, then the verdict:

1. **Restore-loop theory (f8d7af5) DEAD.** DUMPRES=2 multi-shot across the intro (m2hold_forensics.sh)
   showed resolve 0x723000 healthy and updating (CAVE clean → M2-with-cross → title clean). No frozen
   buffer, no self-sustaining ring. There is NO restore draw during the M2 hold at all — persistence is
   our offscreen `persist` (correct).
2. **Guest-clear-colour theory DEAD** (but the honor SHIPPED anyway): spec §4.1 Color=*(R+0x218) is now
   honored on shell frames ([rvk][gclrcol], RVK_NOGCLRCOL=1 reverts). Measured value = 0xFF000000
   (black, never changes) — so the seams were never clear-show-through. Kept: it is decomp-true.
3. **Stale-texture-cache theory DEAD.** RVK_REVALFORCE=1 (new lever, default off: per-hit re-decode of
   fmt-6 w>=2048 atlases) — cross survives per-frame re-decode from guest RAM.
   (Side finding, real but now moot for this defect: reval3Hash uses bpt=4 for fmt 6 — if fmt 6 were
   compressed that byte-size is wrong; for 8888 it is correct. The 64-sample sparse hash CAN miss
   small-band changes; noted as instrument-debt only.)
4. **RAM truth:** RVK_RAWDUMP=3 + RVK_RAWDUMP_LEN + RVK_RAWDUMP_AT (new: Nth-decode capture; the
   FIRST decode races streaming IO and dumps 128KB stripe holes — landmine for future dumps) captured
   the full 16MB 2048x2048 ARGB8888 TILED atlas at the M2 hold. Offline untile with the renderer's
   exact tiledOff (C:\tmp\m2hold\untile_check.py): the cross is IN the image content — opaque
   0xFF040000, vertical ~8px at content-relative x=512, horizontal ~6px at y=448, full span, flush
   with the logo's left edge/baseline. Authored-looking, not a tiling artifact (both swizzle variants
   agree; opus decomp agent corroborated before standing down).
5. **★ VERDICT — Xenia Canary referee:** same 360 dump (assets/default.xex) run in Xenia renders the
   IDENTICAL cross on the M2 screen (C:\tmp\fnf12_burst\f00240_008407.png), same position, bolder.
   Two independent implementations agree ⇒ the cross is the authentic M2 logo-screen design (their
   crosshair/registration-mark motif). The "clean" reference was the PC SDK build — DIFFERENT intro
   assets. FNF-12 residuals (b)/(c) (seams, M2-hold "ghost") are NOT defects. Port renders it
   slightly thinner than Xenia (bilinear vs point upscale polish item, unchanged).
6. **Loading circles during fades (user report):** Xenia's dark between-logo fades show NO circles.
   Port faithful-timing boot (circles_hunt.sh, RT_LOADPROBE): overlay does ONE clean cycle at boot
   start (alpha 59→255→0, re-hide) and is gone before the CAVE fade — matches Xenia. The circles the
   user saw were during COMPDBG-instrumented forensics boots (banned for visual judgment — the worker
   runs ~40% slow there, loading legitimately extends into the fades). On a normal boot the port shows
   the authentic "Now Loading ···" at boot start only. Watch on next user playtest; if circles appear
   on THEIR normal boots, measure IO completion timing vs guest dismiss (not compose).
7. **Xenia input for future referee drives:** config keybinds (xenia-canary.config.toml [HID.WinKey]):
   START=X, A=';'(0xBA), B='''(0xDE), dpad=Ctrl+WASD, guide=Backspace. NOTE: synthetic input
   (SendKeys, keybd_event incl. 180ms holds, --hid=winkey/any, focus+click first) did NOT register
   in this Xenia build — five attempts. Needs real keyboard or deeper investigation; user asked to
   press X manually.
8. REMAINING REAL DEFECT (last intro/menu 1:1 item): stray 「を」 glyph beside Ver1.01 on TOP MENU
   (FNF-7 class; f445 ops draw2 = quad sampling the 1024x1024 font atlas with va pointing at
   non-vertex memory — contains 0x723000 + command-like words). Pending Xenia TOP MENU screenshot to
   confirm it's not ALSO authentic before hunting (tonight's lesson, twice-burned).

## 2026-07-28 ~01:30 — FLICKER TRUTH (workflow wf_e3c67137, 4 agents) + FIX CLUSTER

**Attribution correction first (user-raised):** the "M2 cross" was MY instrument-derived phantom —
the user never reported it. Every defect the user DID report was real: circles overlapping M2
(this section), the flickering TOP MENU glyph (varying chars, NOT one static 「を」 — task #25),
FNF-13 margins (user-confirmed vs reference — task #22).

**VERDICT (3-lane workflow, HIGH confidence on mechanism):** the M2-window flicker is NOT the
loading element (structurally ONE-SHOT: single show site 0x821CD474, full caller census) — it is
the **accessing/connecting sibling indicators** (taskctx +0x64/+0x60), shown INSTANTLY at full
brightness for exactly the lifetime of any kind-1/2/3 async task (prime suspect FUN_821C2198
"ACCESSING_STORAGE" settings/save read), with ZERO filtering of short pulses. On SDK/Xenia the
task completes sub-frame -> never rasterized. On the port, three latency sources stretched it
across presents on unlucky/cold boots: (1) completion-event COALESCING on the shared auto-reset
event (RT_EVCOUNT was off — unbounded, boot-variable, the only "sometimes"-shaped source);
(2) 1ms usleep poll hops in NtWaitForMultipleObjectsEx; (3) 100us KeDelay floor on zero-interval
yields. The boot-start show/dismiss cycle is faithful (measured port 0.04-1.9s vs SDK 0.5-2.1s).

**FIX CLUSTER (register-true: make loads fast, NEVER hide the element):** out_reco/rt.cpp —
(a) evcount() DEFAULT ON (RT_EVCOUNT=0 reverts); (b) global wake condvar g_mwCv notified by every
event/semaphore signal; multi-wait blocks on it with 1ms bounded fallback + clock-based timeout
(RT_REALWAIT=0 reverts to pure poll); (c) KeDelayExecutionThread zero-interval -> yield (same
gate). Smoke: full boot 60fps, indicator cycle correct.

**PROBE:** RT_LOADPROBE2 (shell/gen/rt.cpp, default OFF) — ms-stamped hooks on the three
show/hide fns (sub_821CCC48/9A8/AF8: r4, caller LR, enable bytes +0x71..73 before->after) + async
task ctor/dtor (sub_821BD670/BD5B8: kind, name, LIFETIME). Positive control: boot cycle logged
(show t=0 lr=0x821CD478, hide t=1497ms). ⚠ Task ctor/dtor lane UNVALIDATED (zero events on a warm
menu-less boot — needs a save-touching drive). The old RT_LOADPROBE (250ms sampling) is BLIND to
sub-250ms pulses — do not use it for flicker claims.

**Acceptance = task #24:** user cold boots (no M2 re-raise) + save-touching drive under
RT_LOADPROBE2 showing task lifetimes sub-frame. Adversarial review workflow on the wait-path diff
ran before commit (results folded in below if any).
**Review outcome (wf_ea22499a, 3 lenses):** 1 confirmed defect — the LP2 task ctor/dtor hooks were
SILENTLY DEAD (shadowed by merged_xex.cpp's strong [ptask]/[cancellife] wrappers; audio-arc
landmine) → logging folded INTO those wrappers. 2 hardenings: rt_rstev now drains e->count
(NtClearEvent on a counting event could hot-spin post-clear waits); RT_REALWAIT=0 KeDelay opt-out
now restores the historical 1000us for v==0 (first cut gave 100us — wrong A/B baseline). Cleared
as harmless-by-design: missed-notify (1ms bounded), lock ordering (wake always after unlock),
clock-based timeouts, evcount+NtSetEvent mixing. Re-smoked: 60fps, show/hide lane fires (0→1480ms
boot cycle), task lane zero on warm boot (expected; positive control = save-touching drive, #24).
**2026-07-28 ~01:50 ACCEPTANCE FAILED (user playtest):** circles STILL re-raise at M2 with the full
fix cluster live (EVCOUNT on + real multi-wait + yield). This does NOT refute the indicator≡task-
lifetime mechanism, but it REFUTES "wait-path hop latency was the dominant term". Strike 1 on this
item. The discriminator is already built: one boot with RT_LOADPROBE2=1 reproducing the flicker →
if a TASK-CTOR/DTOR pair (with name) brackets the visible pulses, the named load is genuinely slow
(chase ITS time: LZX decompress? file read size?); if NO task pulse coincides, it is verdict
alternative (B): the RENDERER draws the indicator element at guest alpha≈0 because per-element
modulate (elem+0xFC low byte) is unhonored in the element draw path — fix would be honoring it
(renderer correctness, not a fudge). Fix cluster STAYS (timing-fidelity positive, review-hardened,
no regressions observed). Two-strikes: one more ship-nothing on this item ⇒ back to backlog.
**2026-07-28 ~02:00 — ALT-B CONFIRMED, NIGHT CLOSED.** User saw the flicker on the SAME armed boot
(playtest_0728_0112.log) whose [lp2] trace shows the guest dismissed the indicator at t=1465.8ms
with zero re-shows and zero task births ⇒ the port renders content the guest has hidden (verdict
alternative B). Unification suspicion with FNF-7: the m2hold COMPDBG boot carries intermittent
EXTRA third batches during the M2 hold (f410/421/423/432/434/443, varying texIdx 2/4/5, f445 ops
draw2 va reads non-vertex bytes incl. 0x00723000) — decoder consuming draws hardware never
executes. A 3-lane ghost-draw workflow (guest emission gating / anomaly mining / port decode
candidates) was launched and STOPPED at user request — resumable: runId wf_a7757c52-a1d, script
altb-ghost-draw-truth-wf_a7757c52-a1d.js in the session workflows dir (completed lanes replay from
cache). Resume point + full state in task #24.

## 2026-07-28 ~02:00 — GHOST-DRAW FIX SHIPPED (alt-B closed, FNF-7 unified; Arm A)

**Workflow wf_b8847446 (relaunch of the stopped 3-lane truth workflow; m2hold evidence
REGENERATED same night — old log lost, fresh boot reproduced 13-21 anomaly frames/boot).**
VERDICT: M2 circles ≡ FNF-7 glyph, ONE mechanism — the guest genuinely submits stale one-quad
tail draws for dismissed content; hardware kills them AT RASTER via degenerate state; the port
un-nullified them. Capture fidelity verified (alignment 0/55,435; predication refuted).

**[gdprobe] DISCRIMINATOR BOOT named Arm A decisively:** every anomaly draw (vs=1 ps=2 n=4
prim=5 fmt=6, menu-atlas bases 0x1DB1000/0x21B1000/0x21F2000/0x2232000) carries **vte=0x300
(viewport transform DISABLED) + guest c255 ALL-ZERO** — the guest's hide idiom (D1-B scale-0
at the VS-constant level) — and our **c255 zero-rescue substituted the ship values and un-hid
them** (rescued=1 on all; clob=0 — vs=48 clobber uninvolved). Every legit rescue client carries
vte bit0 SET (0x43F). The register-true predicate = the existing RVK_TRUE48 class test,
generalized: **vte bit0 clear + zero c255 ⇒ hardware-true collapse; keep the guest zero.**

**FIX (vk_render.cpp, 2 legs):** (1) build-time gate on the zero-rescue — FAILED acceptance
alone: all 16 collapse-class draws REUSE a snapshot built for an earlier vport draw (the
never-silent MISMATCH-A counter caught it in one boot). (2) **per-draw enforcement at the bind
site** (same per-window patch-cache pattern as the idx48 clobber): direction A restores the
guest's own c255 for collapse-class draws (the ghost fix); direction B enforces the substitute
for vport draws on kept-zero snapshots (protects legit sprites). `RVK_C255ZRESCUE=1` = exact
pre-fix pipeline (lever positive-controlled: 23 anomaly draws re-appear substituted under it).

**ACCEPTANCE (_tmpscripts/qa_ghostdraw.sh, PASS):** G1 all 16 collapse-class probe draws bind
c255now={0,0,0,0}; G2 zero mismatches; G3 legit rescue alive (loading text); G4 fix exercised.
⚠ seg[2,3) batch count does NOT drop (the draws still decode — no draw-count clamp, per the
forbidden list); they now collapse to zero pixels exactly as hardware. Draw-count instruments
(DRAWTRIP census etc.) will still see them — expected, documented. TEXEL REGRESSION: 6/8
M2-hold resolve dumps bit-identical pre-vs-post; the 2 differing pairs sit across scene
transitions that differ by the identical 919,601 px WITHIN a single run = frame-offset
artifact, not regression. Evidence: /c/tmp/m2hold/{boot_baseline_0728_0128.log,
boot_gdprobe_prefix_0146.log, prefix_dumps/, postfix_dumps/}.

**[gdprobe] instrument stays in-tree (RVK_GDPROBE=<fromframe>, default off).** PENDING: user
playtest = the real acceptance (M2 circles gone; TOP MENU stray glyph gone — same class,
identity matches). If user-confirmed: flip RT_LOADPROBE2 back to default-off in playtest
launcher (7a760e3 set it on "until #24 closes").

## 2026-07-28 OVERNIGHT (~02:15-03:20, user asleep) — FLICKER MECHANISM PIXEL-PROVEN; MITIGATION STAGED

Compose-1:1 phase-1 workflow (wf_9bf1bc43; plan + SPEC addendum appended to
SPEC_shell_compose_1to1.md with synthesis deltas) then Leg 1 executed end-to-end:

**1. MISSING-DRAW CENSUS built + validated (RVK_DRAWCENSUS=1|2, _K/_R, RVK_CENSUSTEST
fault-injection).** Three control failures fixed en route (first-steady target dies with its boot
phase; frame%N unreachable under pacing -> census-clock injection; unmarked injections
indistinguishable from organic). VERDICT: **flicker is NOT missing draws** — 120-150s ship-env
soaks show zero legit-element dropouts (only a periodic phantom-base blip at the 632/688-frame
attract cycle, authentic-scene-boundary shaped; and multi-quad identities straddle window slices
so draw counts survive). R6 idle-fallback counter: zero. gdfix cross-check: per-draw B inert.

**2. [r5pix] PIXEL PROBE = THE PROOF.** Every empty-segment front-buffer blit on shell frames
(~10/s) reads back the offscreen and counts nonclear px. **BIMODAL: 1443x 921,555px (innocent
persisted-content re-blits) vs 22x 53,615px + 22x 12,232px = 44 LOW-CONTENT PARTIAL-FRAME
DELIVERIES per 150s (~1 flash / 3.4s)** — the user's multi-element one-frame flicker, measured.
Chain: guest clears+redraws every frame; window slicing (host-Present close vs kick-thread
appends) leaves the offscreen partially drawn; an orphaned empty segment triggers the
front-buffer blit of that partial state. Draw census stays clean because slices leave >=1 quad
of each steady identity per window.

**3. MITIGATION STAGED: RVK_RESKEEP=3 (new, shell-scoped empty-seg blit skip; 1/2 semantics
untouched, default off).** A/B: mechanism rate unchanged (52 low-content states), deliveries
0/1537 (100% suppressed), resolve texels clean vs baseline (5/8 bit-identical; diffs = the known
919,601px transition-alignment class), zero errors across 5 soaks. PINNED in playtest.sh for the
MORNING USER A/B (unset to revert). NOT register-true (hardware copies EDRAM regardless) — the
cure is Leg 2 guest-frame-atomic windows (close at guest frame mark FUN_820A2280/FUN_820A5408,
same thread as kicks); RESKEEP=3 stops the bleeding until that lands.

**⚠ NEW INSTRUMENT TRAP (variant of the LOCKED-workstation PrintWindow trap): with the DISPLAY
POWERED OFF, PrintWindow captures solid white — futari_snap is BLIND while the user's screen
sleeps.** Cost tonight: a false "RESKEEP freezes the display white" conclusion, retracted after
the known-good control also snapped white. Resolve-dump (DUMPRES) readbacks are display-
independent and remain the overnight texel instrument. 9th instrument-lies instance this arc.

⏭ MORNING: (1) user A/B the playtest icon (RESKEEP=3 pinned) — flicker on press-start/logo/
circles/glyph should be GONE or sharply reduced; (2) if accepted: keep pin, schedule Leg 2
(atomic windows) as the register-true replacement, then Legs 3-4 per the plan; (3) if rejected:
the [r5pix] instrument is the truth meter — measure, don't argue.

**OVERNIGHT ADDENDUM (~03:40) — LEG-2 DESIGN DATUM CAPTURED ([r5pix] FLASH rosters, r5pix4.log):**
every flash window is STEREOTYPED: nseg=4 (occ. 6), sequence s0[44B resolve-only, lat=11]
s1[10728B main content, lat=2682] s2[44B, lat=11] s3[1252B, lat=313]; the empty front-buffer
resolve fires at segpos 1/2 with only 2-3 batches decoded. Mechanism named: **frame-straddle —
frame N's FINAL front-buffer resolve is kicked during/after guest Present and lands at the HEAD
of window N+1; the honored clear-every-frame then wipes the offscreen BEFORE a resolve hardware
executed AFTER the full frame.** (Discovery en route: the window close already runs in the
GUEST's Present hook sub_820A5408 rt.cpp:2409-2428 — the plan's "host-Present close" premise was
stale; the defect is close-at-hook-entry vs Present's own trailing kicks.) LEG 2 = move/extend
the close to include trailing resolve-only segments kicked during Present (or close after the
final resolve), the f776 post-hoc migration machinery (vk_render ~7856) is the same class
patched downstream. Attended leg, instrument gates: [r5pix] low-content states -> 0 AT SOURCE
(vs RESKEEP=3 which only cuts delivery), census clean, texels vs oracle unchanged, 59.9 held.

## 2026-07-28 MORNING — RESKEEP=3 FAILED USER ACCEPTANCE ("nope same"); FLICKER PARKED; **PIVOT**

The pixel-proven flash class ([r5pix] partial-frame deliveries) is REAL and is suppressed by
RESKEEP=3 — and the user's perceived flicker is UNCHANGED. **The measured class ≠ the perceived
defect.** RESKEEP=3 unpinned from playtest.sh (lever + census + r5pix + gdprobe all stay in-tree,
default-off, positive-controlled).

**HONEST INSTRUMENT GAP for whoever reopens this:** every overnight instrument observed up to the
resolve/compose layer. The GLASS layer (swapchain present, the 720p->1080p/1920 RVK_WINSIZE window
blit, present-timing interaction) was NEVER directly observed — the display was off all night and
PrintWindow captures white (the banked trap). The perceived flicker may live between resolve and
glass. Do NOT chase this now — recorded as the top lead for whenever the item reopens.

**STATUS: flicker PARKED (not another leg).** Dossier: draw census clean; [r5pix] flash class
proven + suppressible; frame-straddle roster datum for atomic windows (e9c4339); glass layer
unobserved. Per USER DIRECTIVE (bedtime 07-28 + this morning's "PIVOT"): the project moves to the
**decomp→recomp campaign** — wholesale matching decomp/translation (UnleashedRecomp model,
[[futari-matching-decomp-goal]]), where compose correctness arrives by construction instead of
by renderer forensics. Shell-compose 1:1 (SPEC + presence contracts + Leg-2 datum) folds into
that campaign as the compositor subsystem's spec, not as standalone renderer legs.

## 2026-07-28 — ★★★★★★ GLASS TRUTH (user-directed RenderDoc lane): THE FLICKER IS PRESENT-PATH
## ALTERNATION — two compose states cycling on the swapchain

**Apparatus (rebuilt from the banked recipe; fnf7_sdkref was cleaned):** _tmpscripts/glass_burst.py
(qrenderdoc --python; ExecuteAndInject + TargetControl.TriggerCapture(55)x2 across the M2 hold,
ship env + RVK_WINSIZE=1920x1080 = the user's real glass config), glass_sheet.py (backbuffer per
capture), glass_allswap.py (ALL swapchain images per capture — the artifact discriminator).
66 captures -> C:/tmp/glass_burst/.

**FINDING (artifact-checked):** consecutive presents ALTERNATE A,B,A,B between two compose
states: adjacent-present diff large (760 units at fade start), **present N bit-identical to
present N-2 (d=0.0)**, pair-gap decaying 760->164 across the fade. Within every capture, exactly
2 of the 3 swapchain images are identical and the pairing rotates with the round-robin — the
just-written image genuinely alternates content ⇒ REAL on glass, not the index-0 extractor trap.
Correct behavior (hardware): every present shows the newest compose; adjacent diffs small and
monotone; N vs N-2 NEVER exactly zero mid-fade.

**READ:** the present/publish path alternates between a current and a stale image slot (fits the
[pace] age{4+} repeats data and the front-buffer alias pair 0x723000/0x6A1000). At 60fps this is
a 30Hz shimmer on every pixel where the two states disagree — fades (logo), blink ramps (PRESS
START), and stale-step content (the "circles that continue forever"). This unifies the user's
whole symptom list at the layer every overnight instrument was blind to.

**NO FORENSICS LEG FOLLOWS (campaign rule):** the decomp→recomp campaign's C3 (guest-owned
Present, Unleashed-shape) rebuilds exactly this path; this finding gives C3 a SHARP OBJECTIVE
GATE — rerun glass_burst.py: zero A/B/A alternation (no N≡N-2 identity mid-fade; adjacent diffs
small+monotone). The burst apparatus is the acceptance instrument.

## 2026-07-31 — ★★★★★★ COMPOSE LEG 2 (nvk arm): MISSING-DRAW CENSUS RE-HOSTED ON THE CAMPAIGN
## RENDERER, POSITIVE-CONTROLLED TWICE, AND RUN — port-side compose is CLEAN; one intermittent
## GUEST-EMISSION strobe on PRESS START BUTTON named and evidenced

**WHY THIS LEG (the gap nobody had noticed).** BACKLOG #0 requires a MISSING-draw census
(drawtrip / the 07-28 `[census]` only ever counted EXTRA draws). That census was built inside
`renderFrameReal` — and `shell/gen/rt.cpp:2476` returns from the Present hook **before**
`rt_render_maybe()` whenever `nvk_mode() >= 2`. Since the HARD PIVOT the ship configuration IS
`RT_NVK=2`, so **the acceptance instrument for the top backlog item has been structurally dead
for three days** (so are `[r5pix]`, RESKEEP, gdprobe and the rest of the legacy forensics kit).
The census is therefore re-hosted at the nvk altitude, where the frame is the guest's own
wrapper-call stream (`NvkFrame`), not a decoded PM4 window.

**WHAT "MISSING" MEANS NOW — the reframing that matters.** Under RT_NVK=2 the guest composes
natively: SPEC_shell_compose_1to1 §4 clear policy, §5.5 colour, §2 paint order and §5.6 geometry
arrive by construction (the port replays the guest's own Clear / SetRT / Resolve / draw events in
order — there is no persist heuristic, no layer-seg, no overlay replay, no menuLive gate; s2B leg
10 already found PANELFURN moot for the same reason). A census dropout on this arm therefore
CANNOT mean "the compositor lost an element": it means the GUEST did not emit it, or the RECORDER
diverted/dropped it. The instrument is now an emission-truth probe and reports on both halves.

**IMPLEMENTATION** (`render/vk_render.cpp` nvk section + `decomp/shell/nvk.cpp`; all default-off):
- `RVK_DRAWCENSUS=1|2` — census (2 adds a 120-frame status heartbeat). `RVK_DRAWCENSUS_K` (8)
  steady threshold, `RVK_DRAWCENSUS_R` (3) max gap. Identity = (stage-0 texture base, vsIdx,
  psIdx); scope = DISPLAY-target draws on SHELL frames (`curRT == nullptr && GA_FIELD_ACTIVE==0`)
  — an offscreen RT has its own recompose cadence and would fake drops if mixed into one clock.
  The clock advances only on frames that recompose the display. Scene-jump guard = 3x draw-total
  step. Same lever names as the legacy census (mutually exclusive at runtime; scripts carry over).
- `RVK_CENSUSTEST=1` positive control A (stop COUNTING the elected identity every 250 censused
  frames); `=2` positive control B (**actually skip rendering** those draws = a genuine one-frame
  element dropout on glass). Every injected frame is marked in the log.
- **ALIASING DISCRIMINATOR** (new, mandatory before any dropout is believed): each dropout prints
  the full identity roster of the MISSING frame and of the RETURN frame. A guest that
  double-buffers an atlas would swap the base under one element and read as a dropout; a twin base
  carrying the vanished draw count settles it. No twin appeared in any roster this leg.
- **RECORDER COUNTERS** `g_nvk_fBuild / fNoScratch / fSpliced` (nvk.cpp, per frame, reset at the
  frame flush): draws diverted into the static cmd-blob (build mode, dev+0x2ABC bit0), draws the
  guest itself aborted (scratch/count/stride == 0), blob draws spliced back in. Printed on every
  dropout (missing frame AND return frame) and in the status line — this is what separates "guest
  stopped emitting" from "recorder swallowed it".
- **TWO SILENT PARTIAL-FRAME CLASSES MADE LOUD** (logging only, behaviour unchanged):
  `[nvktrunc] VERTEX-BUDGET TRUNCATION` — vk_render's `if (maxNv > kMaxVerts || maxNi >
  kMaxIndices) break;` abandons EVERY remaining draw of the frame (exactly the partial-frame shape
  BACKLOG #0 suspects) and had no instrument at all; and `[nvktrunc] RECORDER CAP` when `nDraws`
  hits `NVK_MAX_DRAWS` (6144). Neither ever fired in this leg's runs.
- Harness: `_tmpscripts/nvkcensus_soak.sh` — ship-env parity with the alpha1a ARCADE launcher,
  `EXE/NAV/TAG/DUR/TEST/PNG` overrides, pre-boot process check, PID-scoped kill.

**★ 4th CONTROL FAILURE OF THIS INSTRUMENT FAMILY — found and fixed before any verdict.** The
first control run (`pc2`) printed 335 INJECT lines for 13 dropouts: under control B the injected
identity was, during the boot-logo phase, the ONLY display draw, so skipping it left the frame
with zero display draws — the census clock never advanced, the injection condition `pc%250==249`
stayed true, and the element stayed hidden for **322 consecutive frames (~5 s)** instead of one.
Fix: an injected draw still contributes to the frame's display TOTAL (the frame did recompose;
only its COUNT is suppressed). Re-run `pc2b`: **16 INJECT -> 16 DROPOUT-CONFIRMED len=1**, exactly
one per injection, clean 250-frame spacing (f263, f513, f775 ... f4027), 0 VK errors. Re-validated
after the roster/recorder additions (`pc2c`: 9 -> 9). Control A (`pc1`): 10 -> 10. The legacy-arm
control failures were (1) first-steady target dies with its boot phase, (2) `frame%N` unreachable
under pacing, (3) unmarked injections. This is #4 — an injection that starves its own clock. Any
future re-host of this census inherits all four.

**GATES (clean arm, `RVK_CENSUSTEST` unset).** 24 clean-arm boots, ship env, RT_NVK=2, intro -> title
-> TOP MENU (`18000:START`), plus one 12x title<->TOP MENU bounce drive and one no-START
title-hold drive: `soak1` 150 s (pc=8881), `soak2`/`soak3` 100 s, `bounce1` 100 s, `title1` 28 s,
`rep1..rep10` and `h11..h18` 32 s each, `hi1` = the **HI arm** (futari_merged_v154hi.exe) 45 s.
Totals: **>60,000 censused display-recomposing shell frames; 0 vertex-budget truncations;
0 recorder-cap truncations; 0 VK_ERROR / VUID / FATAL in any run; 60.0 fps held with the census
armed** (soak1: 30 submit heartbeats x 300 frames / 150 s). **SPEC §4 CLEAR-POLICY CONFORMANCE:
100 %** — `DAT_821EC65B != 0` agreed with "a guest Clear event reached this frame" on 8881/8881
(soak1) and on every frame of every other run; 0 mismatches total, which is the first live
confirmation that the port's clear policy is register-true on the campaign renderer. Recorder
counters read `build=0 noscratch=0 spliced=0` on every status frame of the title/TOP-MENU phase
(the cmd-blob diversion path is not exercised there).

**REFEREE CHECK (not instrument-zero alone).** The censused TOP MENU frame
(`/c/tmp/nvkcensus/evidence/topmenu_censusclean_f3600.png`) was compared element-for-element with
the SDK-lineage ground truth
`reference_captures/oracle_rdc/sdk_topmenu_versionselect_GROUND_TRUTH.png`: header plaque, all
four version rows + EXIT, the description bar with the A/B button glyphs, the bottom-left logo,
the character art and the M2 ring cluster — **all present, same layout, same ordering**. A title
frame is banked alongside (`title_pressstart_f1350.png`).

**★ THE ONE ORGANIC FINDING (1 boot in 24, ~4 %) — and it is NOT a compositor defect.** `rep2`
(no injection) reproduced a class that had also shown once under control A:

    [census] f1266 DROPOUT-CONFIRMED len=2 base=0x4C41000 vs=1 ps=2 steady=18 streak=8
             v0=(-190.5,181.5) clear=1 vte=0x43F missTotal=28 retTotal=46 nDraws=49
    ... f1270, f1274, f1278, f1282, f1286, f1290 — 7 events, STRICT 4-frame period

Read: one identity of **18 draws** disappears for exactly 2 frames, returns for 2, seven times
over ~0.47 s (a 15 Hz strobe) while every other identity is untouched (display total
46 -> 28 -> 46 = exactly the 18 missing draws). Scene = the TITLE screen (nDraws=49). The
position `v0=(-190.5,181.5)` and a count of 18 quads identify it as **"PRESS START BUTTON"**
(17 glyphs + 1) — the user's own report item *"PRESS START beyond authentic blink"*, measured for
the first time. Because nvk renders exactly what the guest submitted, **the guest stopped emitting
those quads**: this lives upstream of compose (guest logic / tick-vs-present cadence / recorder),
NOT in the compositor. The strict 2-on/2-off period is the same shape as the 07-28 glass-truth
A/B/A alternation, which fits a cadence class rather than a renderer class. The aliasing
discriminator and recorder counters were added AFTER this capture and did not fire in the 16
subsequent boots; they are armed in-tree for the next occurrence. NOT chased further this leg
(campaign rule: name the probe, do not swing at a 4 % intermittent).

**⏭ WHAT REMAINS FOR THE BACKLOG-#0 ACCEPTANCE.** (1) The user-judged intro+TOP MENU soak is the
only open half — the instrument half is DONE and green. **Recommendation: pin `RVK_DRAWCENSUS=1`
in the playtest launcher for that soak**: it is silent in steady state, costs no frame rate, and
turns the user's own session into the measurement — if the user sees a flicker and the log shows
no DROPOUT, the defect is downstream of emission (the glass/present layer that every 07-28
instrument was blind to). (2) On the next DROPOUT, read `missRoster` / `missRec` FIRST:
`build>0` on the missing frame = cmd-blob diversion (port bug, fix at the recorder); `noscratch>0`
= the guest aborted the draw itself (register-true, chase the guest predicate); both zero and no
twin base = a guest-emission/pacing class, and the next probe is the shell tick vs present cadence
around the title blink.
Evidence: `/c/tmp/nvkcensus/{pc1,pc2,pc2b,pc2c,soak1,soak2,soak3,bounce1,title1,rep*,h*,hi1}/boot.log`;
PNGs in `/c/tmp/nvkcensus/evidence/`.

## 2026-07-31 — ★★★★★★ TITLE-CADENCE LEG: THE PRESS START STROBE IS **AUTHENTIC** — guest law
## read live, tick:present proven 1:1, and the "4% intermittent" exposed as a CENSUS THRESHOLD
## ARTIFACT (the guest does it on EVERY boot)

**WHAT WAS HANDED TO THIS LEG.** The compose census (d280de9) caught the PRESS START identity
(`base=0x4C41000 vs=1 ps=2`, 18 quads, `v0=(-190.5,181.5)`) vanishing **2 frames on / 2 off,
seven times over 0.47 s**, in 1 boot of 24, recorder counters clean => "the guest stopped
emitting". The named next probe was shell tick vs present cadence at the title. Result: the
cadence is perfect and the emission stop is **authored guest behaviour**.

**THE GUEST LAW, READ OUT OF THE BINARY (not inferred).** `FUN_821CBFF0` @0x821CBFF0
(decomp `default_decomp_all.txt:222569`) is the title item's per-tick state:

    D = task[+0x80]; ctr = ++task[+0x7C];
    if (ctr % D != 0) hide( *(task+0x58) + 0x0C ) = (ctr / D) & 1;      // hide-byte square wave
    cmd = FUN_82190A90(pad); task[+0x6C] = cmd;
    if (cmd < 4) { task[+0x7C] = 0; task[+0x80] = 2; task[+0x48] = 0x821CBF58; }   // ACCEPT

and its successor `sub_821CBF58` (generated PPC, `shell/gen/ppc_recomp.35.cpp:10539`) runs the
**same** square wave with the now-D=2 divisor and **returns early while `ctr < 30`**, doing the
scene handoff only at `ctr >= 30`. So the accept animation is an **authored 30-tick, 2-on/2-off
strobe = exactly 7 complete off-gaps = 0.5 s at 60 Hz.** The census measured 7 gaps over 0.47 s.
The number the instrument found was not approximately the guest's number; it was the guest's
number.

**MEASURED (new instrument `RVK_TITLEPROBE`, both halves, 4 boots this leg).**
- **Pre-accept divisor read LIVE for the first time: `D = 20`** — `[tprobe] CBFF0 tick=1 ctr=1
  D=20`. This **CLOSES SPEC_shell_compose_1to1 §13's open gap** ("Initial-D ctor still [GAP]
  (needs a runtime read)") and it is the ORACLE value: 20-on/20-off, SDK + Xbox 360 confirmed
  07-21 ([[futari-title-blink-lottery]]).
- **The port's authentic blink IS 20/20 on glass.** `test_18s`, 15+ consecutive cycles, every
  one of them `run=20 frames`: f676/696/716/756/776/796/816/836/856/876/896/916/936/956/976/
  996/1016/1036/1056/1076/1096/1116/1136/1156/1176/1196/1216/1236/1256. Not 19, not 21 — 20,
  every time. This is the instrument's POSITIVE CONTROL (it reports the known-true cadence)
  and simultaneously a 1:1 verdict on the blink itself.
- **TICK:PRESENT IS EXACTLY 1:1, ZERO DRIFT.** Guest-side heartbeats over 581 ticks:
  tick=61/pres=715, 161/815, 261/915, 361/1015, 480/1134, 581/1235 — **`pres - tick = 654`,
  constant to the frame across the entire title hold**; `dPres=1` at every sample; and every
  guest RUN line reads `lasted ticks=N presents=N` (N=20 pre-accept, N=2 post-accept) on BOTH
  exes. **The welded-clock / tick-starvation / double-step hypotheses are dead by measurement**,
  not by argument.
- **Accept -> strobe, in lockstep:** `[tprobe] ACCEPT (cmd<4): statefn 0x821CBFF0 -> 0x821CBF58,
  ctr reset to 0, D := 2 @pres=1263`, then the ON run truncates (`run=11`) and the series goes
  `2,2,2,2,2,2,2` — the same 7 gaps the census reports at f1269..f1293. Guest hide byte and
  glass presence agree frame-for-frame, which is also the **organic proof of the identity
  attribution**: `0x4C41000/1.2/18quads` IS the element `*(task+0x58)` whose hide byte this law
  toggles. No PNG was needed (and per the 4 banked PNG traps, none was trusted).

**★ THE "1 BOOT IN 24" WAS THE INSTRUMENT, NOT THE GAME.** A DROPOUT is only printed when the
identity's streak is `>= K` (8) at the moment of loss. Post-accept ON runs are 2 frames, so the
streak must be **inherited from the pre-accept 20-frame ON phase** — i.e. the accept has to land
>= ~6 frames into an ON phase or the census stays mute for the whole authored strobe. Proof that
the strobe itself is universal, from the PREVIOUS leg's own bank (the always-on `[cbf58]` probe,
`out_reco/merged/merged_shell.cpp:3166`): **exactly 30 calls with `per=2` and one ADVANCED in
23/23 START boots** (rep1..rep10, h11/h12, soak1, hi1 ...) — and **0 calls in the one no-START
boot (`title1`)**. The behaviour was in every boot; only the report was a lottery. On this leg's
build the accept happens to land 11 frames in, so the census reports it **4/4**.

**REPRODUCTION STATS.** 4 boots this leg (`ctl_hold`, `ctl_hold2`, `test_18s`, `hi_tp` = HI arm)
+ 1 default-off control (`defoff`): strobe observed by `[tprobe]` **4/4**, by the census **4/4**;
`ctl_hold`/`ctl_hold2` byte-identical to each other (determinism control). Plus the 23/23 + 1/1
banked `[cbf58]` evidence above. **27/27 START boots strobe; 1/1 no-START boot does not.** No
soak was needed — the "4% intermittent" premise dissolved on contact with the guest log.

**VERDICT: NO PORT DEFECT IN THE TITLE-PROMPT PATH; NO FIX LANDED (deliberately).** Every
ON/OFF run in the entire title scene is now accounted for by the guest law: 20/20 while holding,
a truncated ON run at accept, then 7x 2/2, then the handoff. There is no unexplained transient
left to fix, and the campaign's two-strikes rule forbids swinging at one that does not exist.
⚠ Honest scope: this is the scripted-nav drive at 1920x1080 windowed. The mechanism is
input-independent (the law lives in the guest tick, and `[cbf58]`/`[tprobe]` fire identically
under the in-engine `[navreal]` driver and the 18 s FIFO press), but the user's own session is
the referee for what they SAW. **What to tell the user:** after you press START the prompt
strobes at 15 Hz for half a second before the menu comes up — that is the arcade's own accept
animation, and the port reproduces it tick-exact; the blink you see while waiting is 20-on/20-off,
also exact. If the user reports flicker on the title **without pressing anything**, that is a
DIFFERENT report and `RVK_TITLEPROBE=1` will show it as runs that are not 20.

**THE INSTRUMENT (`RVK_TITLEPROBE`, default OFF, both halves; 0 lines when unset — controlled).**
- *Guest half* (`out_reco/merged/merged_shell.cpp`): new hook on `sub_821CBFF0` + a `tprobe_tick`
  shared with the existing `sub_821CBF58` hook. Logs hide-byte transitions with run length in
  **ticks AND presents**, ctr/D/elem, `dPres`, the ACCEPT event, first-3-ticks (the ctor's D
  before the guest can change it) and a 120-tick heartbeat. `=2` dumps every tick.
- *Glass half* (`render/vk_render.cpp`, beside the census): a threshold-free per-identity
  presence tracker — **no K, no R, no erase-on-absence**, because those three filters are
  precisely what made the authentic blink invisible to the census. One line per PRESENT/ABSENT
  transition with the run length. `=2` adds a per-frame roster. Capped at 20k lines.
- `g_rt_presentN` published from `shell/gen/rt.cpp` (one store per Present) so guest-side hooks
  can stamp themselves with the present index — that is what makes tick-vs-present measurable
  at all.
- Harness `_tmpscripts/titleprobe_soak.sh` (process guard, PID-scoped kill, ship-env parity).
  ⚠ Landmine found and fixed in it: **`RT_NAVREAL=0` does NOT disarm the in-engine nav driver**
  — `merged_game.cpp:2746` gates on `getenv` PRESENCE, so the first "no-press" control pressed
  START anyway at present 364 and came out byte-identical to the non-control. `HOLD=1` now
  UNSETs it. (Another instance of the silent-no-op-safety-check class.)

**GATES (probe armed, ship env, RT_NVK=2, both exes).** `bash build_win.sh` LINK_OK 87 objects;
`bash _tmpscripts/build_win_abn.sh` LINK_OK 88 objects (futari_merged_v154hi.exe). test_18s:
2281 censused frames, **0 VK_ERROR / VUID / FATAL / no-pipeline, 0 nvktrunc, clear policy
2281/2281 conformant, recorder `build=0 noscratch=0 spliced=0`**, 60 fps held. HI arm: 0 VK
errors, `ticks=20 presents=20` on every run. Default-off control `defoff`: **0 `[tprobe]` lines**
and the census output identical frame-for-frame to the armed run => the probe is non-perturbing.
Evidence: `/c/tmp/titleprobe/{ctl_hold,ctl_hold2,test_18s,hi_tp}/boot.log`,
`/c/tmp/nvkcensus/defoff/boot.log`. No PNGs produced.

**⏭ WHAT REMAINS.** (1) The census's DROPOUT line still cannot self-classify authored square
waves; the header comment now tells the reader to pair it with `RVK_TITLEPROBE=1` (a run-length
series is the discriminator). Consider pinning TITLEPROBE=1 in the playtest launcher only after
measuring its line rate in the TOP MENU (animated elements transition often). (2) `bounce1` in
the census bank shows **63 `[cbf58]` calls for 12 accepts** — the state advanced after ~5 ticks
on re-entries instead of 30, which the `ctr >= 30` gate should forbid unless `task[+0x7C]` is not
being re-zeroed on a re-entry path. Unchased, low priority, but it is a real inconsistency with
the law as read. (3) Nothing else in the title scene is unaccounted for.

## 2026-09-20 — ★★★★ FNF-15 (NEW, user-confirmed): TRAINING config panel draws NO rows in the port — a readable-C
## regression in one of eight shell TUs (control proven); single-TU bisect built, not run (user stop). Boss-1 route works.
**Symptom.** Hub TRAINING → the training/in-game config panel (object 0x19C, vt 0x82050F00, ctor sub_821966D0,
training_config.cpp) shows only the tips caption 「ステージを選択します。」 + ⬅➡:選択 START:開始 B:戻る. The 360 draws the
"Training" dialog above it: Stage / Mode / Character / Shot Power / Bomb Stock / Player Stock / Total Counter / Stage
Counter / Survival Rank / Start Training / EXIT. Pilot frame: futari_decomp/bank/r23/attended_0920/fnf15/
pilot_tr5_f4140_panel_rows_missing.png. The panel IS live (invisible): RIGHT moves the Stage row, START launches.
**Markers (pilot AND control identical):** [tstate] 96660(load)#1 → 95AB0(commit)#1..4, never BE500(ACTIVE) — the
opener parks the panel INTERACTIVE straight after the first stateBuild frame (no slide-in), then START → [dclose]
slide-out kind=15. So the state ring is not the difference; the drawing of the built row views is.
**Control (build/futari_combined_ctlshell.exe = host build with DECOMP_SKIP="menu_base_states menunode_states
menu_containers options_panel_base options_panel_hooks options_decide_builders training_config textview_draw"):** the
whole dialog draws (frame f4080 viewed: title Training, Stage = Stage 1 ▸, Mode Original, Character Reco/Normal, Shot
Power / Bomb Stock Stage Default, Player Stock ◂3▸, counters 0, Survival Rank Stage Default, Start Training 1P Side,
EXIT). Markers banked (control_ctlpanel_markers.txt); the frame file was lost — see landmine 1 below.
⇒ **FNF-15 = readable-C regression inside those eight TUs.** Prior: menu_base_states.cpp (stateBuild sub_821B6D20
builds the row textViews and clears V_HIDDEN; stateSlideIn is the only un-hider of the container) or textview_draw.cpp.
**Bisect prepared, NOT run:** eight single-TU control exes (each reverts ONE TU): build/futari_combined_ctl_{mbs,tvd,
opb,oph,mns,mct,odb,tcf}.exe (mbs=menu_base_states tvd=textview_draw opb=options_panel_base oph=options_panel_hooks
mns=menunode_states mct=menu_containers odb=options_decide_builders tcf=training_config), built by
scripts/boss1/build_host_ctlarm.sh (ARM=<tag> DECOMP_SKIP=<tu>). Verdict metric: scripts/boss1/panelcheck.py <run>
(black-pixel fraction of the panel box on the frames dumped between load and dclose: pilot 0.015 = ROWS MISSING;
drawn dialog ⇒ > 0.5). Driver: scripts/boss1/boss1_drive2.sh (ROUTE=training NRIGHT=0 DUR=12, BIN=<arm exe>); chain
= scripts/boss1/chain1.sh. The whole-shell-revert arm (ctlsh1/ctlsh2) is NOT usable as a control: it boots ~4× slower
and the nav lib's fixed waits misfire on it.
**Boss-1 route (Phase 0 of PLAN_after_boss1_0920.md) — WORKS, head verdict NOT reached:** marker-gated driver
(press → wait for its marker → re-press; hub DOWN tracked by [mcur]) reached the stage-1 boss on the shipped exe at
~f10200, ~100 s after START (bank tr5: pilot_tr5_sheet.png, pilot_tr5_boss_head_strip.png, pilot_tr5_markers.txt).
NAV_MAP's "LEFT/RIGHT changes NOTHING on a fresh card" is WRONG: the Stage row is a kind-3 choice list of 10 entries
(training_config.cpp kRowsB[0], kStage10), the base clamp is [0, n) (options_panel_base.cpp loc_821B574C), the value
lands in rec@368/369 (options_decide_builders.cpp sub_82196358 case 0) and onDecide maps it through kStageLut — no
save gate. The earlier "no effect" runs were DROPPED PRESSES: a 0.15–0.2 s hold falls inside a frame stall when the
[nvkrect]/[nvkdbg] vertex census dumps (RT_NVKVTXALL) fire on that frame ⇒ new harness lever RT_NVKDBGFROM=<frame>
(render/vk_render.cpp) defers the census until the stage. Old-build bisect (08-07 / 08-14 / 08-27 exes) NOT done:
the 08-07 exe turns one 0.15 s DOWN into six cursor moves (different pad repeat), the cursor-tracking hub_row that
handles it was written but unrun. Training death shows a RESUME/RESTART overlay and loops at the boss (useful).
**Landmines (new, 09-20 evening):** (1) NEVER edit a bash driver while a run is executing it — bash reads scripts
incrementally; the ctlpanel run lost its banking tail. (2) TaskStop on a background chain does NOT kill the child
driver/exe — two instances then share the pad FIFO and log (user saw "2 instances"); kill by pid + Stop-Process
futari*. (3) The Bash tool caps at 10 min: long chains must be `nohup … & disown` with their own log. (4) Menu key
repeat = 20-frame delay then every 3 frames (stateBuild's pad reconfig, DO-NOT-FIX 8): any hold ≥ 0.33 s overshoots.
**USER STOP 21:40:** "not sure you're understanding the training menu, boss 1 selection, etc at all. please stop."
+ "bank and pivot back to decomp." Both items PARKED here with their tooling; nothing fixed; no renderer change.

## 2026-10-04 — ★★★★★ BOSS-1 HEAD CLOSED (Mac, overnight lane): TWO OPERAND SLIPS in the readable boss-1 draw body
## (futari_decomp decomp/game/objaction_queue.cpp sub_880DCE90, "straight ahead" head pose, second face-mosaic pair)
**Symptom (user, 09-06 + 10-03, confirmed against the HG101 arcade shot):** the stage-1 boss's front-on head rendered
inside-out — eyes at the centre line, cheeks outside; "left texture on the right". **Root cause:** in the a == 128
("straight ahead") sub-arm of the second bdzf dispatch, the second mosaic pair (descriptor 0x8827AF30, call sites
0x880DE77C / 0x880DE7A0) was emitted with the int8 DY byte at G-15281 added into the X half-offset instead of Y, and
with the pair's base word at G-15584 dropped. Measured against the generated TU: 44-tile group ids 26875..26918,
delta (+/-9, -40) px (G-15584 = 0x1F, DY = 0x28) -> both face halves 9 px too far out and 40 px too high. Fix = two
lines (ctx.r27 gains Fx16(i8 G-15281); ctx.r26 = Fx16(i8 G-15282) + Fx16(u32 G-15584)); the same dropped G-15584
term was also restored in arm 0 and arm 1/2's second pair (ppc_recomp.11.cpp loc_880DE24C / loc_880DE51C), which the
front-on pose does not exercise.
**Method (what finally worked, ~3 h of instruments after a long detour):**
1. Route: `scripts/boss1/boss1_drive_mac.sh` reaches the boss in ~100 s (Training > Stage row RIGHT > 開始 with A).
2. **Single-unit reverts do NOT compose:** seven readable units knocked out one at a time (famk2, bossvein_object,
   actor3pose_draw, page_bake, asset_decode, asset_upload, nvk_game_hooks) all rendered the head identically — because
   none of them was the culprit. The decisive arm was **ALL readable game units at once except the renderer bridge
   (nvk_game_hooks) and the hook/memory helpers**: it rendered the head correctly. Then objaction_queue alone did too.
   Lesson: when single-unit arms are all negative, run the whole-side revert BEFORE reading anything.
3. **Per-push trace diff** named the exact emit: `RT_EMITTRACE=lr:<lo>-<hi>` (merged_game.cpp sub_881538C0 wrapper,
   arms at the first boss-1 head push) logs every Sprite_Emit with its caller and record; `RT_DCD70TRACE=1` logs the
   composite plate drawer sub_880DCD70's call site + args; `RT_SPRITETRACE=<extent>` (nvk_game_hooks.cpp) logs the
   emitter's quads. Diffing the readable vs the generated-unit build frame by frame (scratch emitdiff.py, frames split
   at the id-20649 push) showed every push identical except one 2x44-tile group at (+/-9, -40). The generated listing
   at those call sites then read in five minutes.
**Detours banked so they are not repeated:** the vertex census, texture-page dumps (RVK_DUMPTEX), HUD-glyph orientation
and the Xenos RECTLIST / tiledOff reads were all faithful and all irrelevant — the geometry the game emits IS what the
renderer draws; the question was only which unit emits it. The "texture page V-flipped" hypothesis is refuted by the
all-game arm. Harness-only levers added (never ship armed): RT_EMITTRACE, RT_DCD70TRACE, RT_SPRITETRACE.
**NEW READ-REFUSAL CLASS (companion to 10-03's implicit-register class):** in a 1,200-line body with a dozen
near-identical mirrored-pair blocks, a transcription can route an operand to the wrong register (DY byte -> x) and drop
a term, while every store/branch/constant still matches. Reads of such bodies must be checked block-by-block against
the generated listing's final `add rN,...` for EACH argument register at EACH bl, or better, measured with the
per-push trace diff above — a 4-minute instrument that beats any read.

## 2026-10-04 (beta 3 cut, user: "two modes for macos pls. flicker will need retesting anyway. otherwise do the recommended")
## THE MODULE ARM PORTED TO macOS; THE XBOX 360 TREE REGENERATED HERE WITH A RECONSTRUCTED, VALIDATED RECOMPILER
**Plan:** docs/PLAN_beta3_mac.md. The 07-26 F&F gate (shell-compose flicker, BACKLOG #0) ships as a KNOWN ISSUE in the
bundle README by this ruling; everything else on the recommended list was done unattended.

**1. Deployment target.** The 10-04 bundle was stamped `minos 27.0` on the engine, the launcher and the bundled SDL3
(MoltenVK 12.0): nothing set a target, so clang used the host SDK's own version and the .app would launch on no other
Mac. `MACOSX_DEPLOYMENT_TARGET=13.0` is now exported by build_mac.sh, build_mac_dll.sh and build_mac_app.sh (which
refuses any binary stamped otherwise); SDL3 rebuilt with `-DCMAKE_OSX_DEPLOYMENT_TARGET=13.0`. build/futari_merged
rebuilt through the refactored script: same merge (182 duplicate groups, 185 renames), minos 13.0.

**2. The XBOX 360 tree was not on this Mac and could not be fetched.** `out_reco_abn/ppc_recomp.*.cpp` are gitignored
("regenerable"); the recompiler that made them is the eqv-fixed XenonRecomp fork, a never-pushed local git repo on
the Windows box, which was unreachable (iacon down, NAS down). Regenerating with the Mac's upstream XenonRecomp
checkout and diffing against the TRACKED reco_normal tree (1.1M lines) showed the fork's codegen differed in exactly
these classes (classified mechanically, `bank` = this session's scratch): divw/divwu/divd/divdu emitted as raw `a / b`
(1,425 sites; the fork routes them through the non-trapping ppc_div* helpers in out_reco/ppc_context.h), lhzu / sthu /
stfsu / bdzf / eqv / addc / addme / lwzux SILENTLY DROPPED (the asm comment is emitted, no C follows; 30 + 41 sites),
and mftb emitted as `__rdtsc()` instead of `rt_mftb()`. Those cases were added to upstream recompiler.cpp
(`tools/xenonrecomp_mac_eqv_fixes.patch`, applied + regenerated by `scripts/regen_abn_mac.sh`) and VALIDATED by
regenerating reco_normal: residual vs the tracked tree = the 41 "FIX 2026-07-24" hand patches (the patch now emits the
same expressions mechanically -- addme/addc/eqv/lwzux were exactly those 41) + the 24 r23-w6x harness-tap hunks,
nothing else; the silently-dropped census is 0 on both regenerated trees (the only comment-without-code lines left are
`b` to a function start, db16cyc, cctpl/cctpm). out_reco_abn/ now = 28 regenerated TUs + the 5 tracked tapped TUs
(4/5/6/8/19, which already carried the fixes by hand). Consequence worth knowing: the Windows beta-2 abn DLL ran the
41 dropped-instruction sites UNFIXED outside those five TUs; the Mac abn module does not.

**3. The module arm on Mach-O** (`build_mac_dll.sh`, the twin of build_win_dll.sh): host/module_registry.cpp dlopen arm
(futari_game_<mod>.dylib; RT_MODDLL_DIR, then the executable's directory, then dlopen's search; RTLD_LOCAL),
tools/gen_host_abi.py Mach-O arm (Homebrew llvm-nm, leading underscore stripped, the four globals seen as the shim's
futari_p_* pointers, libc++/libSystem as CRT; the abort-on-unknown tripwire kept). The measurement found ONE helper the
Windows ABI never had: `rt_kick_capture`, a weak reference in merged_game.cpp's sub_88080298 wrapper -- dead in the
Windows DLLs (null weak), live in the merged exe every Mac gate ran on -- now ABI member #20 (hash 0xECFBA58AD25409D9,
identical for both modules). Two Mach-O lessons: a weak extern to a symbol defined NOWHERE is a hard link error
(weak_import does not cover it) -> rt_audio_module_swap gets a weak empty definition on Apple; Apple libm has no
roundevenf -> harness.cpp defines it on Apple as on Windows. The modules link through the same rename-on-duplicate pass
as the merged exe (normal: 20 duplicate groups = the decomp __imp__ overrides + the nvk_game_hooks/merged_game shadow;
abn: 1), -dynamiclib, deps = libc++ + libSystem only.

**4. First boot of build/futari_combined:** `[modreg] 2/2 module DLL(s) bound, hosted modeIdx mask=0x03`, title at
60 fps, 0 FATAL. `scripts/modes_mac.sh` (NAV_MAP routes, marker-asserted): the card panel's LEFT + 3.6 s dwell + A
decides XBOX-360 MODE (`[modeidx] modeIdx=1`), `[modswap] #2 DONE` (#1 is the boot activation), the abn module
boots to its own Ver1.5 title, and stage 1 is reached (m02_stg) -- _local/nav_mac/m1_x360/shot_2.png is the first
XBOX 360 MODE stage frame rendered on a Mac. Full drive (m2, all three legs): XBOX 360 to stage 1 PASS, ARCADE to
stage 1 PASS, swap cycle arcade -> x360 -> arcade `[modswap] #2 DONE` + `#3 DONE` with `residue=0` at both
retirements, hub rebuilt after the swap, 0 FATAL / 0 VK_ERROR (the only red line was the script's own 20 s wait for the
third hub, since raised to 45 s). The two audits on the final decomp tree: constpool 0 DRIFT, regcontract 0 MISSING.

**5. The bundle** (`mac-build/build_mac_app.sh`, VER 0.2.0-beta3, 900 MB with the data): combined engine + both dylibs
in Contents/MacOS, every Mach-O stamped minos 13.0 (the script now refuses otherwise), README rewritten for testers
(requirements, both modes, controls, the macOS 15+ Gatekeeper steps -- right-click > Open no longer suffices there --
the flicker as a known issue, where the logs are). Bundle builds now go to build/app + *_app object dirs so they never
overwrite the drive/gate binaries. Validation on the bundle itself: `scripts/app_smoke_mac.sh` (LaunchServices launch,
pad through launchctl setenv, app-menu Quit, save under Application Support read back on relaunch), the modes drive on
the bundle's engine, `scripts/fdpace_check_mac.sh`, stagepix pilot=bundle engine vs control=build/futari_merged, and
`scripts/soak_mac.sh`. RESULTS (all on the bundle's own engine, 2026-10-04 18:35-19:20):
- app smoke PASS: LaunchServices launch, 2/2 modules bound, hub reached, Quit from the app menu leaves no process, the
  save lands in ~/Library/Application Support/Futari Realcomp/save and reads back (existed=1) on the second launch.
- modes drive (b3) PASS: XBOX 360 to stage 1, ARCADE to stage 1, swap cycle `#2 DONE` / `#3 DONE`, residue=0 at both
  retirements, hub ACTIVE after the return swap (the arcade module re-enters on its existing hub model: no [p0build],
  the proof is the menu engine's ACTIVE state with the HUB vtable 0x820503B0), 0 FATAL / 0 VK_ERROR.
- FrameDelay PASS: the card is applied at the save load, not at the title (the first version of the check idled at the
  title and saw 1V on both arms -- fixed); 60 s in the top menu on the 3V card = `framedelay=3V -> +2 frame(s)`, one
  [fdpace] line, frames at exit 4801 vs 4801 on the 1V card (ratio 1.00; the 10-05 defect was ~3.6x).
- stagepix PASS: pilot = bundle engine 24,312 colours / 28.7 edges vs control = build/futari_merged 23,598 / 28.2.
- soak: 29 samples over 30 min in attract, RSS 268 MB flat from the first minute, ~3,600 frames/min, 0 FATAL, 0 VK
  errors (the "PROCESS GONE" at t+30m is the run's own RUN_SECS kill; the script now adds 90 s of slack).
- The zip: ~/Desktop/projects/Futari-Realcomp-macOS-v0.2.0-beta3.zip (734 MB, `ditto -c -k --keepParent`). NOT yet on
  the SHARED share: the NAS (10.0.1.77), arch-vm (10.0.1.7) and iacon were all unreachable from this Mac the whole evening.
Owed to the user's eyes (unchanged): boot overlay feel, 3V feel, a two-pad couch session, fullscreen/Retina on a
smaller display; and the flicker retest this beta exists for.

**6. The Steam Deck build, from the Mac (user: "could we build a steam deck version?" -> "go"; then "i've got the deck
with me away, i can test if we can package it up").** No Linux host was reachable (iacon/WSL, archbox, arch-vm all
down), so the build runs in an x86_64 Debian 12 container under colima + Rosetta on this Mac (profile `futari`, vz,
10 CPU / 16 GB; mac-build/deck/Dockerfile = glibc 2.36 + clang/lld 18 from apt.llvm.org + SDL's X11/Wayland/PipeWire/
Pulse/ALSA headers; SDL built with -DSDL_X11_XTEST=OFF). `build_linux_dll.sh` is the ELF twin of build_mac_dll.sh
(-Wl,--allow-multiple-definition is the whole merge; modules -fPIC -shared --no-undefined; -march=x86-64-v3 for the
Deck's Zen 2); host/module_registry.cpp's POSIX arm already dlopens futari_game_<mod>.so from the executable's dir.
Result: build/linux/futari_combined (22 MB, PIE, max GLIBC_2.34 < SteamOS's 2.41) + futari_game_normal.so (45 MB) +
futari_game_abn.so (9.7 MB). Headless smoke in the container: `[modreg] 2/2 module DLL(s) bound, mask=0x03`, the shell
XEX + 9,554 funcs registered, the guest runs and opens `game:\media\motion\menu_title.lzx -> assets/media/motion/...`
(the file layer maps guest paths 1:1 under RT_GAME_ROOT: the dump's case must be kept verbatim on the Deck's
case-sensitive disk -- the lowercase-`module` rule belongs to the ReXGlue recomp, not here; a first stage step that
re-cased the folder was reverted). Staged: ~/Desktop/projects/Futari-Realcomp-Deck/ (884 MB: engine + both modules +
assets + `futari-realcomp` launcher script with the attended env, saves in ./save, logs in ./logs, README) and the zip
Futari-Realcomp-Deck-v0.2.0-beta3.zip. NOT yet run on a real AMD GPU: the Deck (10.0.1.154) was away/unreachable;
first-boot risk = RADV disagreeing with a renderer feature, which `[rvk]` names before the first present. Upload: no
Google Drive client, rclone or cloudflared on this Mac; the user is choosing the route.

**7. (10-05, the Deck in hand) Two Deck findings.** (a) "fails to load": gamescope/Wayland surfaces report
currentExtent 0xFFFFFFFF; the swapchain now takes the window's pixel size (e3512aa). (b) "a little slower than the
rexglue port" (in Gaming Mode): 60 frames/s everywhere, but the main thread at 96% of a core at the TITLE -- the
shell's vsync gate sub_8216B148 polls 0x821F8550 vs 0x821F8560 for the next vblank (register-true; a pinned core on
any port, and on the Deck's shared APU budget a competitor for GPU boost). RT_VBSLEEP (79b314e): the wrapper blocks on
the vblank thread's condition variable while the loop's own condition holds. Main thread 96% -> 28-30%, process 107%
-> 40-46%, still 60 frames/s; Mac 97% -> 27%. Full method in docs/DECK.md. Note for the ledger: the Mac beta-3 bundle
on the Desktop pre-dates this (same behaviour, one hot core) -- rebuilt after the Deck validation.

**8. (10-05 noon, unattended) The rebuilt bundle re-validated on the RT_VBSLEEP engine.** The whole chain re-ran on
the 10:49 bundle engine (scripts/app_smoke_mac.sh, modes_mac.sh, fdpace_check_mac.sh, stagepix_mac.sh: all PASS as
before) and then three things the chain had not covered: (a) **shell-title soak 30 min** (soak_mac.sh): 60 frames/s
throughout, RSS 268 -> 277 MB and flat from minute 14, 0 FATAL / VK_ERROR, the engine at ~25% of a core for the
whole half hour (the spin gate's 97% is gone on the shipped binary). (b) **Boss plate gate A/B of the two waits** on
the same build/futari_merged (RT_VBSLEEP=0 vs default; scripts/boss1/boss_plate_gate.py compare): PASS on both
witnesses -- pixel plate within margin, IDENTICAL push sets over 20 lockstep frames (4860 emit + 166 dcd70 keys); the
first try was a lockstep NO-VERDICT from the known intro coin-flip (y 343.03 / 345.69), the retry locked. The blocking
wait changes nothing the guest can see. (c) **ARCADE demonstration soak 20 min** (new scripts/demo_soak_mac.sh:
START, A, A to the ARCADE decide, then hands off): the ROM attract ran **15 cycles at exactly 4800 frames (80 s)
each**, 14 returns to the title, 60 frames/s, 0 FATAL / VK_ERROR, RSS cycling 202-425 MB with the attract's own
asset churn and no monotonic growth. Two instrument lessons banked in the scripts: the arcade module is the CV1000 ROM
under the emulator layer, so its attract fires NO XACT BGM cue -- the demo counter is the module's outer state field
`[navreal] d76 0->3` (go=1, attract gameplay starts) / `d76 4->0` (back to the title), not `m02_stg`; and the
all-game plate sweep must NOT list `nvk_game_hooks` -- knocking out the renderer bridge changes what the dump is
(skin 0.55, 115 "boss" frames from f1560, the exact signature boss_plate_gate.py already excludes), which produced a
false pixel FAIL at 12:42 with the structural witness identical; boss_plate_gate.sh now refuses that TU up front.
The corrected all-game sweep (38 game TUs, pilot = every TU linked, control = all of them skipped) then PASSED on
both witnesses: pixel plate within margin (skin 0.28 vs 0.26, p90 0.917 vs 0.917), IDENTICAL push sets over 46
lockstep frames (11834 emit + 426 dcd70 keys); results _local/boss1_mac/gates_vbsleep.txt, chain
_local/nav_mac/beta3_chain_vbsleep.txt. Beta 3 is validated on the engine it ships with.

## 2026-10-05 — Phase 1 item 4 measured unattended: B3 round-trip PASSES, the save's layout/FrameDelay bytes PINNED,
## D3 wall-dim MOOT on the ship path -- and a NEW DEFECT: FrameDelay 2V/3V UN-PACES THE PORT ON macOS
**B3 (menu save round-trip) — CLOSED, scripted (scripts/nav_mac.sh b3write2 / b3read2):** Screen Setting (Maniac) >
Layout Setting #1: Zoom +3, Position-X +2, Position-Y +1; Extra Setting: FrameDelay 1V > 3V; back out to the hub.
The guest wrote the card itself (`[file] atomic save published`, three SAVE CreateEx/Close cycles) and EXACTLY FOUR bytes
changed; a fresh boot read them back (Extra panel shows 3V, renderer logs `framedelay=3V -> +2 frame(s)` at boot).
**Save layout pinned (closes the N1 "zoom/position sub-offsets unpinned" doc debt):** FrameDelay = `+0x16E7` (the LOW
byte of the u32 at +0x16E4 -- a poke of +0x16E4 itself does nothing, that is the high byte); layout preset #1 record at
`+0x16F8` (stride 0x80): +0x00/+0x04 the (8,8) rotation pair, **+0x08 Zoom, +0x18 Position-X, +0x1C Position-Y** (u32,
big-endian; the in-memory cfg layout the TUs read -- elem = cfg + idx*128 + 32, X/Y at elem+24/+28, zoom at +40 -- is a
different structure from the card record). Diff: _local/savegame_before_b3.bin vs the live card; the 3V card is kept at
_local/savegame_3v_repro.bin.
**D3 wall-dim 0.875 vs 0.90 — CLOSED, moot:** both wall-dim blocks live in `renderFrameReal` (vk_render.cpp:6677 and
:9218), the legacy compose path that `shell/gen/rt.cpp:2560` skips at `nvk_mode() >= 2`; `RVK_WALLDIMLOG=1` through the
hub + Options under the attended env = 0 samples in 97 presents. BACKLOG #6 closed with the citation.
**★ NEW DEFECT — FrameDelay 2V/3V un-paces the port on macOS (the "3V feel check" is not a feel question):** with the
card at 3V every drive after the boot ran at **~206-224 presents/s** (nvk_f counters: b3read2 12,180 frames in 59 s;
plate_final control 34,140 in 152 s; pilot 42,780 in 201 s) against **~57/s at 1V** (walldim run 2,910 in 51 s), and the
menus dropped or repeated presses (DOWN x4 on the hub landed on NORMAL PLAY; the boss drives wandered into stage 4).
The ring's own comment (vk_render.cpp:5028) claims "zero contact with the frameclock" -- on this path the pacing evidently
came from the 1V blocking present, and presenting from the ring slot returns without that wait. Not fixed here (a
present-path change is an attended lane); the live card is restored to 1V. Repro: copy _local/savegame_3v_repro.bin
over the card, boot, count nvk_f frames per second.
**→ FIXED the same session (RT_FDPACE, shell/gen/rt.cpp VdSwap hook):** the mechanism was not the ring at all. The
shell's mode-1 gate (sub_8216B148) turns the device's vsync-wait flag OFF for 2V/3V (arms 0x8216B344/0x8216B364:
`sub_820A4F80(dev, 0)` then `sub_82098688(dev, 1)`) and relies on queued-swap back-pressure for pacing -- which this
port's instant-retire GPU ([fastmarker], null-GPU semantics) never produces, so VdSwap returned at once. The hook now
paces modes >= 2 on the 59.94 Hz vblank counter (0x821F8560), the same software wait the guest's own 0V mode performs,
with a 40 ms guard; the composed-frame ring keeps adding the N frames. Measured: 3V card **~55 presents/s** (was ~210),
the hub route lands on OPTION again, `framedelay=3V -> +2 frame(s)` at boot, `[fdpace]` armed; 1V card unchanged at
~58/s with 0 `[fdpace]` lines. `RT_FDPACE=0` reverts. The 3V FEEL (+2 frames of latency) is now a real question for
your eyes again.

## 2026-10-04 (night) — the REGISTER-CONTRACT AUDIT exists, and its first sweep found one more FNF-15-class miss
`futari_decomp/tools/instruments/regcontract_audit.py` (the 10-03 lesson made mechanical: per call, the registers the
generated caller rewrote since its previous call that the callee reads, minus what the readable body assigns). Positive
controls = FNF-15's bctrl at 2507022b^ and the new catch at e7bfc9c2; sweep = 1,427 calls clean, one miss:
**menu_base_states.cpp sub_821A0580 (Screen Setting (Simple) panel tick) never set r4 = cfg before `bl sub_82187EE0`**,
the settings-changed notify that fires after a nudge; the generated body's `addi r4,r3,360` is live there and the
callee reads r4 (Layout/Picture pass `lwz r4,360(r28)` at the same call). Fixed (ctx.r4.u32 = cfg). The audit is the
witness (row present at e7bfc9c2, gone at HEAD); a drive that exercises the Simple panel's nudge path (BTN_NUDGE_*)
would be the plate if one is ever needed. 22 indirect-call sites remain with an upper-bound contract because the TU
does not name the slot's callee -- the audit lists them; naming the callee in a comment closes each.

## 2026-10-04 (evening) — FNF-14's open half MEASURED: in-game stage loads never go black and show "PLEASE WAIT"
Route (scripts/nav_mac.sh np_load, build/opt_pilot, frames every 10 ticks): HUB > NORMAL PLAY > 1P SIDE START > Original >
Reco > Normal shot > stage 1. Playfield blackness (RGB < 24, box 408..880 x 40..680) over f2300..f3100 never exceeds 0.07;
the only transition is the Shot Type Select screen itself: at f2890 its corner caption flips from "PRESS 2P START" to
"PLEASE WAIT" (the game module's own load indicator), f2920 begins the fade into the stage, BGM cue m02_stg1 lands at
f2985, the stage is fully up by f2950. Roughly 20 frames of "PLEASE WAIT" -- the load is fast, like the shell's. So the
game-module path has no NOW LOADING screen to miss: the FNF-14 ladder does not apply there, and the Phase 1 item 3
"if black, re-run the ladder" branch is closed as not-black. Still owed to user eyes: the boot overlay feel (any hold is
a ruling), and whether ~20 frames of PLEASE WAIT reads as authentic or as "too fast" -- a feel question, not a defect.
Bank: _local/nav_mac/np_load/ (386 frames, shot_1..5 = the five select screens).

## 2026-10-04 (evening) — the two 10-03 side findings CLOSED: sub_821A0760's static RowSpec table + sub_821A0580's double clamp
**sub_821A0760 (menu_base_states.cpp, the "Zoom(xN.NN DbD)" panel tick, vt 0x82050BC0):** against ppc_recomp.32.cpp
0x821A0948..0x821A0A7C the readable table had the four captions rotated one slot (entry 0 is `addi r4,r30,-16` = "Zoom",
then "-----", "Zoom-X", "Zoom-Y"), entry 1's +32/+36 as 6/2 instead of 2/0, entries 2-3's +32 as 8 instead of 0, every
template-call return address 4-8 too high, the r9..r11 state at each `bl 0x82060F40` zeroed where the body leaves
r9 = mn / r11 = mx live, and the first patchRow call's lr set to an instruction address (0x821A0AE8) instead of the
arm's real return (0x821A0AB8 DbD-on / 0x821A0AE0 off). The `moved` arm now uses layoutNudge's own flag (r7) instead
of re-reading the pad. **sub_821A0580 (Simple panel):** cfg = this+360, so `lwz r11,384(r3)` IS cfg+24 -- one word,
one clamp; the pre-clamp before layoutNudge is gone and the "two different words" comment with it.
**Verified (scripts/nav_mac.sh + the new RT_PEEK=<addr>:<len>:<vt|0> lever in merged_shell.cpp, fires at every
dialog slide-out):** route HUB > OPTION > Screen Setting > "Maniac" Menu Mode (A, A) > first Maniac entry; the
320-byte table at 0x821F9698 peeked on the readable arm (build/opt_pilot) and the generated-body arm (opt_ctl,
decomp_menu_base_states.o dropped) is IDENTICAL except the four caption-buffer heap pointers (+038/+088/+0D8/+128,
different heap layouts, the FNF-15 "P" class). Banks: _local/nav_mac/pic_{pilot,ctl}/.
**Why no drive ever saw it:** the templates are only consumed when the display mode flips to/from DbD (patchRow),
and nobody toggled DbD under the readable TU. The table BUILD, though, runs on the first tick of that panel --
which is why a memory peek, not a screenshot, is the right witness for a function-local static.

## 2026-10-04 (later) — ★★★ BOSS-1 ARM3 RESIDUAL: the indexed 32-direction sub-arm had the 9-px sense INVERTED and a
## dropped word — found by the new BOSS PLATE GATE's structural witness, invisible to eyes and to the symmetry plate
**Found by:** `scripts/boss1/boss_plate_gate.sh v1 objaction_queue famk1 famk9` (the first end-to-end run of the Phase 1.2 gate,
pilot = all readable TUs, control = those three handed back to the generated bodies, both driven under
`RT_EMITTRACE=lr:880DCD70-880DEE68 RT_DCD70TRACE=1`). The pixel plate PASSED (head symmetry p90 0.909 vs 0.905) — the
front-on head is right since the morning fix — but the per-push diff on 13 lockstep frames showed every push from call
sites `0x880DE888` (+9.00 px in x, dcd70 desc 0x8827ACxx, prio 122) and `0x880DE958` (+5.00 px, desc 0x8827ADxx, prio 125)
from frame 3 on, y identical to the 16.16 bit. Those sites are the `sel == 3` **indexed** sub-arm (the head aimed at the
player, mirrored directions), not the straight-ahead pair the morning fix repaired.
**Root cause (futari_decomp decomp/game/objaction_queue.cpp, arm3 indexed sub-arm):** (1) generated `loc_880DE7C0`:
`cmpwi cr6,r23,-1 ; bne cr6,0x880DE800 ; subf r26,r21,r26` — the 9.0 (lis r21,9) is subtracted when sign == -1; the TU had
`if (sign != -1)`. (2) `loc_880DE8C0`: same shape for the second call (`subf r5,r21,r5`), same inversion. (3) the second
call's x term: generated `mullw r4,r5,r23 ; rlwinm r9,r4,16 ; add r5,r9,r7` with r7 = Fx16(lwz G-15600) — ONE Fx16 over
(byte×sign + word); the TU wrote `Fx16(byte×sign + Fx16(word))`, and Fx16's `& 0xFFFF` turns the already-shifted word into 0.
G-15600 = 4 in the image, so the second site measured +9 − 4 = +5. Fix = three lines, applied 10-04; verified by the gate's
re-run (plate_v3, see the ledger) with IDENTICAL push sets on lockstep frames.
**Method lessons:** (a) a mirrored-pair body has to be measured in EVERY pose arm — eyes and the symmetry plate only ever saw
the front-on pose; the indexed arm is reached when the boss aims off-centre, which the gate's trace window covered because
the boss turns toward the (static) player within its first 13 frames. (b) the structural witness only means something on
LOCKSTEP frames: two arms whose boss paths diverged at frame 2 (plate_v2 / plate_neg, shots landing a frame apart) produce
thousands of spurious set differences; the scorer now compares frame-by-frame only while the anchor push sits at the
identical 16.16 position, and the drive holds fire through the boss intro (`QUIET=10`). (c) relative offsets must be kept
in exact 16.16 units — flooring x and the anchor separately manufactures ±1 px rows.

## 2026-10-03 — ★★★★ FNF-15 CLOSED (Mac bisect + read, same evening the macOS port went green): ONE MISSING
## REGISTER ARGUMENT in the readable stateBuild — `r4 = renderer` before the font-measure bctrl (menu_base_states.cpp)
**Method (all on the M3 Max; builds are 48 s, a link is 10 s, a drive to the panel is 60 s):**
1. TU-level bisect, `scripts/boss1/fnf15_bisect_mac.sh` (links each arm from one pristine object set, drives
   START A A A DOWN DOWN A on a card with a save, scores the black-pixel fraction of the panel box on a window
   capture): pilot 0.154 = rows missing; ctlshell (all eight skipped) 0.758 = dialog drawn; **mbs (menu_base_states
   alone) 0.758**; tvd/opb/oph/mns/mct/odb/tcf 0.154 each. Verdict: menu_base_states.cpp alone.
2. Function-level knock-out inside the TU, `scripts/boss1/fnf15_funcbisect_mac.sh` (renames ONLY the readable
   definition line of one body to `<sym>__ro`, so every caller — vtable dispatch and the TU's own direct calls —
   resolves to the generated weak body): of the 14 bodies, **only sub_821B6D20 (stateBuild) flips to 0.758**; the
   other 13 knock-outs stay 0.154.
3. Two independent instruction-level reads of sub_821B6D20 vs ppc_recomp.33.cpp:1170. The first called it clean
   (every constant, every +12 store, every loop bound, every lr). The second, told the knock-out verdict and asked
   for register state at every call site, found it: at the renderer-measure bctrl (lr 0x821B6D7C) the generated
   body does `lwz r4,200(r30)` (33.cpp:1216) — r4 = the renderer — and the callee sub_8216EFD0 (renderer vt+4,
   27.cpp:1008) reads the glyph size THROUGH r4 (`lwz r11,20(r4); lwz r10,24(r4)`). The readable set r3 (out
   struct) and ctr but never r4, so r4 still held sub_821BF3D8's last value, 0x82061D50 (the ST_SLIDE_IN thunk),
   and the font metrics were read out of CODE BYTES: pitchX ≈ 0, pitchY ≈ +1.9e37 → every row setPos'd to
   Y ≈ 1e37, off-screen. Container un-hidden correctly ⇒ panel live but invisible, title/tips (positioned without
   pitch) still drawn. Explains every FNF-15 observation, and why both pilot/control marker rings were identical.
4. Memory corroboration (RT_FNF15DUMP=1, merged_shell.cpp commit hook): the panel, backdrop and all 29 child
   views have identical vtables, hidden bytes, extents, colours and inline strings on both arms — the damage is in
   the positions set through the vtable, not in the view bodies. (A raw image diff was useless: heap layouts differ.)
5. **Fix**: futari_decomp decomp/shell/menu_base_states.cpp, one line `ctx.r4.u32 = renderer;` before the bctrl,
   with the root cause in the comment. Verified: pilot (readable, fixed) scores **0.758**, the dialog is drawn
   (_local/captures/mac_training_panel_FIXED_20261003.png: Training / Stage 1 ▸ / Mode Original / Character
   Reco/Normal / Shot Power / Bomb Stock / Player Stock ◂3▸ / counters / Survival Rank / Start Training 1P Side / EXIT).
**Lesson for the LAWS (new refusal class for reads):** a readable body can be instruction-faithful in every store,
constant and branch and still diverge in a REGISTER it never writes — the implicit argument the generated code loads
for a callee that reads it. A read must list the register state at every bl/bctrl, not just the arguments the
readable author believed the callee takes. The constant-pool audit (PLAN_after_boss1 Phase 1) would NOT have caught
this; a "register contract at call sites" audit would, and it is mechanical: for each call, the set of rN the
generated body wrote since the previous call.
**Side findings banked:** textview_draw.cpp's promotion (09-13) silently shadowed shell/gen/rt.cpp's RT_TXTNODE
hook (strong PPC_FUNC(sub_8216E510) wins over the kernel's) — that instrument no longer fires. **→ CLOSED 10-04:
the body now ships in the __imp__ override form (futari_decomp 902329af), rt.cpp's wrapper owns the plain symbol again;
proven by dup_renames + llvm-nm + an RT_TXTNODE=1 drive ([txtnode]/[rspeedT] rows at the hub). LAWS I1 now names the
shell kernel files in the hook grep.** Two real divergences
OFF the Training path in the same TU: sub_821A0760's static RowSpec table (captions rotated Zoom/-----/Zoom-X/
Zoom-Y, +32/+36 values, every lr +8 — Picture panel, vt 0x82050BC0) and sub_821A0580's double clamp in
layoutNudge (Simple panel). Both unfixed; both owed a drive.

## 2026-10-05 (user out) — THE FLICKER CENSUS ON THE MAC: 12 idle minutes, ZERO missing draws, positive control exact
BACKLOG #0's acceptance instrument (the nvk compose census, `RVK_DRAWCENSUS=2` + `RVK_TITLEPROBE=1`, vk_render.cpp
~11007) run on the beta-3 engine's source (futari_decomp bank/r23/w136, soak_w136_census.sh, verdict log S7):
* **Soak A** — TITLE idle 6 min, START, TOP MENU idle 6 min: 43,800 frames, 367 census heartbeats, **0 DROPOUT-CONFIRMED**,
  0 FATAL / VK_ERROR, RSS 286 → 291 MB. 3,473 `[tprobe]` run-length lines banked.
* **Soak B** — `RVK_CENSUSTEST=1`, TITLE 4 min: **60 `[census] INJECT` → 60 `DROPOUT-CONFIRMED len=1`**, one every 250
  censused frames exactly, every one marked, zero unmarked. The instrument sees a one-frame loss on this build/path.
* Across the window's 11 scripted Options-tour drives (two binaries, 140 s each) the only dropouts were the authored
  PRESS START post-accept D=2 strobe (reported or not by the K=8 steady threshold) and **five press-coincident 2-frame
  losses of two menu-atlas quads** (base 0x49C4000, v0 (-392.5,-33.5) ×3 / (-280.5,-124.5) ×2, ~f2370/4170/7130/7495/7757
  of the route) at the SAME frames on EVERY arm — deterministic and binary-independent: either authored hide-byte
  flips at panel transitions or a port-level deterministic dropout. Next instrument: a one-shot `RVK_QUADCENSUS`
  armed on the press (touch /tmp/rvk_quad_now) to attribute the two quads.
READING: what the census can see, the Mac nvk path does not drop on the two screens the user named. The 07-28 GLASS
TRUTH leg put the perceived flicker on the PRESENT path, which a draw census cannot see by construction — the beta-3
eyes retest stands; this measurement narrows it, it does not close BACKLOG #0.
Also this window (decomp lane, same bank): the w86 compose spine `compose_frame_walks.cpp` is now LINKED into the Mac
build (decomp/shell/, 14 bodies, A/B-gated PASS, 4 rows MATCHED) — with sub_82173978 under the `__imp__` form because
shell/gen/rt.cpp:3122 wraps it (the RT_TXTNODE ancestor stack); the plain form had displaced that wrapper in the first
pilot link. The shipped `build/futari_merged` and the .app were NOT rebuilt; the next `build_mac.sh` will carry the TU.

## 2026-10-05 (evening) — frame-scheduled pad press (harness lever, default inert) and the w136 batch-2 re-gate
`RT_PAD_HOST_FIFO` now also accepts `"<frame>:<hexpad>"`: the 4 ms host pad thread only ARMS it; the guest-thread pad
read (stubs.cpp `rt_host_buttons` → `rt_sched_buttons`) applies the word while `rvk_frame_now()` (vk_render.cpp,
= `g_nvkFrame` stamped at `nvk_frame_submit`) is in `[frame, frame+12)` — twelve guest ticks starting the tick after
that frame was submitted, regardless of when the FIFO was written. Logs `[padhost] sched f<N> pad=<x> fires`. Built
for the decomp campaign's shell A/B gate (futari_decomp bank/r23/w136, PREREG S16): with it, 11/16 Options-tour
screenshots were byte-identical across five legs of two binaries. Residual seen: at a few indices ONE leg's scrolling
background art is one frame ahead (≤ 1.6 mean units) with identical press frames — an occasional guest-tick/present
slip; next lever = a guest-tick counter in the VdSwap hook for both the press schedule and the shot pick.
Also: the card-panel decide must not be scheduled exactly 180 frames after `[modeidx]` (the 0xB4 dwell gate).

## 2026-10-05 (night) — the GUEST-TICK clock closes the shell A/B gate (r23-w136b: batch 2 PASS, 40 rows MATCHED)
Three harness levers, all default inert, all in the kernel objects (arm-symmetric by construction):
* `RT_TICKLOG=1` — rt.cpp's Present hook prints `[tick] p<N>` at the entry of present #N (the scripted drive's clock).
* `RT_PAD_HOST_FIFO` token `t<N>:<hexpad>` — press applied in the guest-thread pad read while the present count is in
  `[N, N+12)` (stubs.cpp `rt_sched_buttons`, now tick- or frame-keyed); token `d<N>` — the Present hook hands the renderer
  a one-shot tag at the entry of present #N and the frame submitted inside that Present is written as `nvk_t<N>.png`
  (`[rvk] tickdump t<N> = frame <F>`; F == N throughout). Tokens are whitespace-separated; a `d` arm fires once per
  distinct value (the first cut re-armed every 4 ms and dumped 606 frames).
Result: four legs across the pilot and control binaries byte-identical at 15/16 Options-tour screens; the only deviating
leg was the FIRST launch of the freshly linked binary (also true of the two earlier recipes) — warm a new binary with one
uncounted launch. Recipe: futari_decomp bank/r23/w136/{drive_w136_shellgate_v5.sh, route_w136_v5.sh}.
Promoted and linked as of this close: compose_frame_walks.cpp, shell_table_821e0014_mechanisms.cpp,
panelbase_class_w105.cpp, save_class_w105_2.cpp (decomp/shell/). `build/futari_merged` and the .app are NOT rebuilt;
the next `build_mac.sh` carries all four (gated PASS).
