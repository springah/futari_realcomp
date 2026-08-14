# NOTE_campaign_decomp.md — decomp→recomp campaign ledger
## ★★★★★ 08-14 NIGHT-5 — **THE INTRO FSM GOES READABLE (b5d5183): logo fade-in/hold/fade-out
## + indicator tick/show-hide naturalized (5 of 6; Logo_Build stays generated, note §7).**

decomp/shell/logo_indicator.cpp, transcribed from FULL generated-body reads this session (not
the note alone) — which earned TWO corrections now stamped into the note: (1) the float-
constant table was +0x40 off everywhere (real pool base 0x8204F7B0 — the SPEC §1.2-derived
addresses were shifted); (2) CCC48's layout-bit sense was INVERTED (FX+0x5A8 bit CLEAR selects
the wide clip constant). Seams honored: LAB_821D1740/1670 = real functions (plain PPC_FUNC);
CD120/CCC48 = __imp__ override forms (merged_shell + rt.cpp own the outers; taps keep firing);
sub_821796B0 declared locally (the combined build compiles decomp/shell with game include
paths — the neutralized seam, now with its first practical consequence).
**LADDER:** map link-win 5/5 → **canary counts reproduce the spec timeline EXACTLY (61-tick
fade-in / 121-tick hold / 61-tick fade-out / every-frame indicator / exactly 2 show-hide
transitions)** → [expcen] control-vs-pilot steady patterns IDENTICAL modulo heap node
addresses (e0:x0:d1:q0 · e1:x9:d1:q9 · e13:x18:d1:q18 both arms), miss=0 across both entire
runs → day2 full loop PASS. Registry: 5 rows MATCHED (registry now 33).
⚠ Instrument lesson: an inline-fn static in a shared canary = ONE counter across all call
sites — the every-frame indicator ate the print budget and the logo stages looked dead on the
first pilot (LI_CANARY macro = per-callsite counters; "printed nothing ⇒ not taken" struck
again, this time inside the instrument itself).

## ★★★★★★ 08-14 NIGHT-4 — **THE CONSUME SIDE GOES READABLE (471257d): Page_EnsureTexture +
## THE PAGE BAKE + Sprite_EmitQuad naturalized, full ladder green. + the logo/indicator
## naturalization draft banked (a2cb47e).**

Wave-2 agent drafts INTEGRATED same night: sub_8808D838 (asset_upload.cpp) + sub_8808DC10 +
sub_8808E298 (new decomp/game/page_bake.cpp; E298 = __imp__ override form — NVK_GHOOK owns the
outer symbol, checked BEFORE drafting this time). The bake's mechanism preserved verbatim:
BAKE and PASTE read DIFFERENT phases (the G_LAST_PHASE store sits between the halves and the
paste re-derives from it); batch-cache poisoning is load-bearing invalidation; both
Sprite_FlushBatch leftover-r3 sites preserved and loudly commented; vertex-template store
order 3,2,1,0 kept. LADDER: map link-win (3/3 to decomp objects) → RT_UPCANARY (Bake ×139
live phase transitions 2→3→6, Ensure ×88) → declog 398/398 + uplog PASS + arcdiff PASS vs
generated control → stagepix PASS (the display-off trap FIRED on the first pilot run — 6/6
white captures correctly NO-VERDICTed, F15 wake + rerun) → day2 full loop PASS → char+shot
select captures eyeballed CLEAN (banked /c/tmp/pb_select). Registry: 3 rows, MATCHED
(matchlab partials cited as independent semantic cross-check, not ASM-EXACT).
**★★ NEW ABN LAW LIMIT (agent-measured): the ROM float pool (0x88063370) shifts −48 in the
abn image, NOT +0x60 — a different segment with independent drift. A blanket +0x60 literal
patch can NEVER port sub_8808DC10 to abn; the float pool needs its own audit first. (E298 +
D838 touch no float-pool literals — uniform +0x60 class only.) page_bake joined all three
abn/control exclusion lists.**
ALSO BANKED: decomp/shell/NOTE_logo_indicator_naturalization.md (a2cb47e) — the boot-logo +
NOW-LOADING family draft: LAB_821D1740/1670 are REAL FUNCTIONS (recompiler .pdata splits;
0x821CD140 mis-bound re-confirmed from the recomp side), CD120/CCC48 are hook-OWNED (__imp__
form required), zero leftover-arg hazards, new oddity = task+0x68 logo-skip byte cleared ONLY
by fade-in. Integration leg = lower the draft helpers to ctx bridging + the control-vs-pilot
expcen ladder (§6 of the note).

## ★★★★ 08-14 NIGHT-3 — **DECOMP VERIFICATION WAVE: three independent audits came back CLEAN —
## the DLL-side pipeline + driver surface are FULLY naturalized already; the readable frontier
## is the consume side + shell intro. Archive gate hole closed (arcdiff_compare.py).**

Three read-only agent audits (E58-discipline: every callee's r3..r10 walked back through the
generated ground truth) over the surfaces presumed to need naturalizing — all three were
ALREADY DONE in the 08-12/08-13 rounds; the audits re-verified them independently:
- **asset_decode mode-2** (6a2f222, MATCHED): every load-bearing insn re-checked; the pump's
  dispatch bl confirmed clean of the leftover-arg class; sharpened oddity banked — mode 2's
  back-ref window is UNWRAPPED LINEAR into live output (its siblings use ring/scratch dicts).
- **driver_msgs** (12 shapes / 128 clones, 74/74-gated): 18 clones diffed insn-for-insn incl.
  every entry-relative published lr — zero defects. Gate-hole proposal banked: the D1 stream
  cannot see non-message side effects (shape-K array-slot stores; Driver_Init's two back-link
  stores through returned pointers) — cheapest closer = memory-value assertions on the banked
  ctrl/pilot pair + an r3 log on the predicate canary ("executed" → "output-verified").
- **archive** (8 fns): ALL EIGHT leftover-register-as-argument instances in the generated
  bodies already correctly explicit in the C (2 init, 3 companion-open, 3 teardown, 1 chain
  walk — zero unfixed). Oddity re-verified: the disk→memory TOC field SWAP (rec[4..7]→+8,
  rec[8..11]→+4) and the 92B80 unlocked descriptor re-read (a real preserved race window).
**GATE HOLE CLOSED:** archive fns were only ever proven TRANSITIVELY through the decode
stream. New _local/_tmpscripts/arcdiff_compare.py STRICT-diffs the [winit]/[wjob]/[gwork]
lines already present in every decdiff log (masks: wjob-enq r4 dst addr; winit-mgr/gwork
handle fields) — **PASS on today's banked pilot/ctrl pair** (1+1+46+40 sampled entries;
gwork absent = teardown never fires on the select drive, exactly as the audit stated).
⚠ Sampled coverage only — supplements the decode/upload differentials. Still unexercised by
ANY drive: sub_880929C8 teardown + sub_88092668 companion open (needs a quit-to-teardown /
non-empty-suffix drive — banked, not built).
**SEAM QUESTION ASKED AND ANSWERED (do not re-hunt):** decomp/shell/*.cpp compiled with
game-tree -I flags in build_win_dll.sh/build_win_abn.sh DOES resolve the game
ppc_recomp_shared.h — but the forced -include rt_indirect.h #undef's and re-defines
PPC_CALL_INDIRECT_FUNC as the module-aware rt_indirect_call shim BEFORE any header wins (its
own header says so; preprocessor-verified today). The seam is neutralized BY DESIGN.

## ★★★★★ 08-14 NIGHT-2 — **RT_EXPECTCENSUS LANDED (e6ff192): element dropout is finally
## MEASURABLE — the backlog-#0 flicker lane has its acceptance instrument.**

The spec's own §11.5 prescription implemented: emit (FUN_82178E78) vs drain (FUN_82168E58)
paired 1:1 per picture node per frame. Emit half emulates the FULL §5.4 predicate (type
rec+0x08, types 3/4 skipped — guest recursion re-fires the hook; BOTH visibility bytes
0x1B4&&0x1B5; type==0 && rec+0x5C) → expected quads per P; drain half reports queue depth
from merged_shell's [flush] wrapper; [expcen] print+reset at nvk_on_present_frame (present IS
the frame boundary — deliberately NOT the RVK_DRAWTRIP-gated [mvtick] close). Default OFF.
**POSITIVE CONTROL PASS with an internal cross-check better than designed: expected == actual
queue depth EXACTLY per node per frame (x13==q13 x18==q18 x9==q9), 2547/2565 frames paired,
miss=0 across the steady TOP MENU dwell.** A dropout now prints :MISS on its FIRST frame.
Judge MISS against RVK_TITLEPROBE (authored blink square waves are AUTHENTIC). Regression:
day2 arcade full loop PASS. ⚠ Shadow rule re-taught IN BOTH DIRECTIONS today: merged_shell.o
owns PPC_FUNC(sub_82178E78) — the rt.cpp duplicate linked silently DEAD (map-file proof;
e0/x0 while drains ran was the tell) → report-from-the-owner (rt_expcensus_emit), the
rt_picnode_report pattern. Apparatus: _local/_tmpscripts/expcen_boot.sh.
⏭ THE LANE'S NEXT LEGS (delta map, EVE-2 block): user-soak the census over the flicker repro
(MISS lines = the dropout localized guest-vs-port) · veil cover interposer on sub_820B6770
(RVK_VEILCOVER) · canvas→clip §5.7 measurement. Items 2/4/6 remain closed-by-construction.

## ★★★★★★★ 08-14 NIGHT — **THE PUMP RETRY LANDED (1878ef0): natural-C pump back in the tree
## WITH the E58 r5=id fix, every gate green, the instrument caught the bug it was built for.
## OWED: user-eyes final acceptance before any release cut.**

The full retry protocol ran exactly as the revert block demanded: (a) instruments validated
on the known-good pair first (uplog all-fns-fire positive control; ctrl-vs-ctrl learn found
exactly ONE run-noise field = 924E8's alloc-returned r4 — the field theory predicts; stagepix
PASS on known-good with ~200k uniq colors / edge ~41 and my own eyes on the banked PNG);
(b) **NEGATIVE CONTROL: the UNFIXED a15bdbc body FAILS updiff at E58 (STRICT entry 0, CORE
entry 1 — exit cache handles diverge) while declog counts 398 BLIND, reproducing the 08-14
escape mechanically**; (c) fixed body (one line: `ctx.r5.u32=id` before the E58 call): updiff
PASS, declog STRICT 398/398, stagepix PASS (pilot 184k/37.9 vs control 198k/41.0, creep
clean; capture eyeballed — enemy DROP SHADOWS, item gems, explosion art, aura all present =
the exact 08-14 missing classes), day2 arcade full loop PASS. abn arm structurally unaffected
(asset TUs build-excluded there).
**MASK DOCTRINE SETTLED EN ROUTE:** the learned ctrl-vs-ctrl mask is too strict cross-arm
(addresses are deterministic within an arm, shifted across arms), and a learned cross-arm mask
can't distinguish stable-leftover from argument. Final = the ABI READ-SET mask
(uplog_mask_abi.json): judge exactly the registers the callee reads (per the instruction-level
ABI reconstruction), minus the one address-valued read field per fn (decdiff's own precedent);
unread r7/r8 leftovers differing is the natural-C body correctly NOT reproducing dead register
state. Residual accepted + noted: address-valued args (924E8 dst, D640 src) are unjudged by
STRICT — behavior divergence there still lands in CORE/exit + declog + stagepix.
⚠ Fresh trap, cost 5 launches: BACKGROUND Bash shells start from the SESSION cwd, which only
FOREGROUND cd's move — a cd inside a backgrounded chain never persists, and I re-pasted the
same cd-less template four times (two chains then ran the game CONCURRENTLY and taskkilled
each other — those nav fails were collision artifacts, not regressions). Rule: absolute
script paths in every backgrounded chain; the gate scripts cd themselves.
⚠ stagepix compare must pass WINDOWS-style paths to python (MSYS_NO_PATHCONV=1 is exported,
so /c/tmp never gets translated — python read zero captures until fixed).

## ★★★★★★ 08-14 EVE-2 — **RETRY PREREQUISITES BUILT + THE SECOND PUMP BUG NAMED STATICALLY:
## the reverted refactor's sub_88090E58 call omits r5=id (read unconditionally as the
## 500-slot cache index). Commits ae43cbf + 1e2d964.**

(1) **UPLOAD-ARG DIFFERENTIAL** (revert-block requirement #1): `RT_UPLOG=1` covers
sub_88090E58/D50/CB8 + sub_880924E8 (UPLOAD_LOG_WRAP, merged_game.cpp — wrappers win over
generated bodies on the control DLLs and the abn arm) and sub_8808D640/DF70 (identical-format
in-body logs in decomp/game/asset_upload.cpp — the decomp is the pilot link winner, so the
wrapper is dead there BY DESIGN). r3..r8+lr+exit per call. decdiff_arcade.sh exports it;
_local/_tmpscripts/updiff_compare.py judges: STRICT rides a LEARNED noise mask
(`--learn ctrlA ctrlB` — fields differing between two control runs are wall-clock noise),
DF70 = masked multiset (per-frame count legitimately differs), positive control = per-fn
presence must MATCH across arms (absent-one-arm = FAIL; the shadowed-hook lesson).
(2) **STAGE PIXEL GATE** (requirement #2): _local/_tmpscripts/stagepix_{gate.sh,cap.ps1,
metric.py} — day2 legs to the stage, 6-cap PrintWindow burst, richness metrics on the center
crop (uniq colors + edge density + placeholder black/white creep), pilot ≥ 0.70× control.
≥97% white = INVALID not FAIL (the display-off capture trap); control arm not rich =
NO-VERDICT (an instrument that can't see known-good can't judge the pilot).
(3) **STATIC ROOT (agent pass over ppc_recomp ground truth):** the a15bdbc rewrite's E58 call
sets only r3=buf, r4=flag — but sub_88090E58 reads **r5 unconditionally as its first insn**
(`rlwinm r7,r5,2,0,29`, ppc_recomp.5.cpp:2329 — the 500-slot id-cache index); the generated
pump carries id live-through ~85 insns (loaded ppc_recomp.18.cpp:11761, bl :11850) — the SAME
leftover-register-as-argument class as the caught 924E8 r4. E58's branch = plain-resource art
= the missing shadows/items/enemy-art symptom. D50/CB8/924E8 arg setups verified correct
against ground truth. **RETRY RECIPE: a15bdbc + `ctx.r5.u32=id` before the E58 call. Run the
UNFIXED body through updiff FIRST — the instrument must catch the known bug (its own positive
control) — then the fixed body through updiff + stagepix + full loops. Final acceptance stays
USER EYES per the revert block.**
**ALSO BANKED (parallel agent passes):** FrameDelay (save 0x16E4) is REAL and currently
UNHONORED — chain: save→`DAT_821F8558` (FUN_82187ee0 applier, verbatim copy)→FUN_8216B148
(per-frame present tail)→dev+0x5E80/0x35EC present-interval flags→a real PM4 present-interval
packet that nothing walks at RT_NVK=2 (host pacing is frameclock-owned). Honoring = read the
bare shell global into present pacing; WHETHER to honor is a user design call; probe recipe
banked in the agent report. · d3d9.lib register audit: all ~53 D3D-family hooks CLEAN, the r5
resolve fix intact, no clone-bypass risk in the D3D set; 3 known label swaps confirmed
cosmetic. · Shell-compose delta map: §9 items 2/4/6 are implemented BY CONSTRUCTION (the
recompiled guest computes colour multiply/quad geometry/paint order; capture passes them
through — vk_render.cpp:6445 copies vertex bytes verbatim, no reorder pass exists); REAL gaps
= the veil's runtime-PATCHED cover shader (template + `+0x37485157` signature patch can never
match the static ucode table — needs an interposer on sub_820B6770) and the canvas→clip
VS-constant verification (§5.7 measurement BEFORE coding); missing-draw census design banked
(guest-expected walk on sub_82178E78 with the full §5.4 predicate — both 0x1B4&&0x1B5, type 0,
rec+0x5C, element hide byte; RT_MVTICK's predicate is wrong on 3 counts — paired with the
existing NvkCensusEnt renderer half, keyed by texture base, RVK_DRAWCENSUS mode 3).

## ★★★★★★ 08-14 EVE — **rt_phys.cpp LANDED (ae43cbf): THE ALLOCATOR IS SPEC CODE, THE LEVER
## TOWER IS GONE. Full ladder green. The 08-04-ruled rewrite is paid.**

harness.cpp 885→397 lines; out_reco/rt_phys.cpp (~240 lines, both trees) states the five
decomp-proven laws once: (1) kernel never zeroes (rt_alloc_raw raw / rt_alloc = NtVA-zeroing
semantics), (2) LIFO age-0 reuse (copy-at-record e5f4989 retired the quarantine's reason to
exist), (3) every tracked free recycles — no floor, (4) never cross 0x20000000 (hi-addr skip
in normal reuse + frontier retreat 2s/0s + age-0 best-fit line defense — the relax ladder
collapsed to its final rung: with quar dead the earlier rungs only reordered preference),
(5) 16KB granule + insert-time coalescing — which makes EMERGENCY-MERGE dead code (a
maximally-coalesced pool has no adjacent entries): deleted. **DELETED levers (15):**
RT_HEAPGRAN(_SZ) RT_ALLOCZERO RT_HEAPRETREAT RT_POOLNOHI RT_FREEPOOL_QUAR_MS RT_POOLFIFO
RT_FREEPOOL_SPLIT RT_FREEPOOL_LINEMERGE RT_FREEPOOL_BIGRES RT_FREEPOOL_COALESCE
RT_FREEPOOL_MIN RT_FREEPOOL RT_HEAPPAD(_MS) — no script/env sets any (grepped). KEPT:
RT_DECOMMIT(_QUAR_MS) (dormant future-leg feature, not a revert arm). bigReserve deleted
(default-off since 08-04). rt_free_ex keeps its (addr, lr) ABI; lr now unused. Epoch table +
every gate-parsed telemetry string preserved verbatim.
⚠ **REAL DIVERGENCE FIXED IN PASSING:** out_reco_abn/rt.cpp's Mm hook still called zeroing
rt_alloc — the 08-04 HW-true fix was never mirrored ("byte-identical across trees" was false
for that line); standalone-abn research builds were zero-on-reuse until today.
**GATES (all on the rewritten allocator):** swapbounce_0811 P1–P7 PASS (6 swaps, high-water
496MB = baseline-identical, retreats 22 live, epochinval 40 bounded, census clean, proc
alive); day2_validate arcade PASS + 360 PASS (boot→stage→death→shell); decouple proofs abn
65.4/s vs 13.3/s + arcade 65.4/s vs 13.3/s; D1: ctrl relinked from CURRENT objects minus
decomp_driver_msgs.o → ctrl-vs-ctrl 56/56 CANONICAL-IDENTICAL, ctrl-vs-pilot 56/56 ×2 after
normalizing the documented two-arm msg=10 r4 stack pointer. Honest: 56-line streams this pass
(the return leg — nav's documented unreliable branch — didn't capture; day2 loops covered
game-over→shell separately). Logs: /c/tmp/rtphys_gates/ + _local/logs/d1p_*.

## ★★★★★ 08-14 — **2P POLISH ROW CLOSED — co-op is scripted, mapped, and green on both
## modules. Backlog #9 reduced to the user's couch session.**

nav_2p_join()/nav_2p_press() joined futari_nav.sh (P2 = pad FIFO 4th field on user==1;
marker = the join handler '[joinp] 881366D0 WILL-JOIN'). day8_2p_validate.sh = the scripted
co-op drive (boot → land → char select → P2 join → BOTH players through their own selects →
two-ship stage → P1-RIGHT/P2-LEFT hold): **COOP_arcade_PASS + COOP_360_PASS, unattended.**
The 2P SIDE START submenu route mapped: [decide] item=1 fires the SAME join handler (slot=1)
→ Mode Select → char select MIRRORED (1P seat "No Entry", 2P active w/ Palm & Hirow —
screenshot banked). NAV_MAP.md carries the 2P section. Movement distinctness = pad-level
proven (separate user words drove separate seats and separate select picks) + the two-ship
mid-hold visual; the frame-by-frame isolated assert is superseded by those. Remaining on #9:
the user's two-pad couch session (attended acceptance — also the fun part).

## ★★★★★★ 08-14 — **PUMP + SUBMIT REFACTORED TO NATURAL C (the last standing form debt) —
## and the differential earned its keep AGAIN: it caught a real rewrite bug before the gate
## passed. asset_pump.cpp 1380→~460 lines; STRICT 398/398 re-proven.**

sub_8813A738 (the ~650-insn job pump) and sub_8813A4D0 (submit) are now readable natural C —
the ring/chain/state machine written as it IS: one slot per call, the record chain drained
in-call through ARM(0) → DECODE(1) → PRODUCE(2/5) → FINISH(3), async-vs-sync read split on
the submit callback, cell stall parking in state 2, sentinel = negative resId. Preserved
shipped oddities documented in-file (submit's unguarded descriptor read + store order; the
park-resume producing from never-read buffers). C1 = args + ctx.lr per call (the proven
pattern); frame emulated (back-chain + lowered r1).

**THE GATE CAUGHT A REAL BUG (the whole reason the transcriptions waited for it):** first run
FAILED STRICT at decode #47 — exit r3=0, an EMPTY source buffer. Localization: ENQUEUE id
streams identical ⇒ the first ASYNC-delivered record. Root: sub_880924E8 shares B20's
(id, dst, slot) ABI and the generated body's r4 "leftover" from the alloc IS the dest arg —
the rewrite omitted it, so the worker wrote to garbage. One line; re-run: **STRICT 398/398
PASS both tiers, RT_UPCANARY ×16 through the new pump, full-loop validate arcade PASS.**
Registry rows updated (gate strings note the refactor + the caught bug). Transcriptions live
in git (≤ f79a8f1).

## ★★★★★★ 08-14 DAY-7 — **CONSOLIDATION DONE — THE WEEK PLAN IS COMPLETE. D1 full-loop
## re-pair 74/74 ×2 CANONICAL-IDENTICAL (the Day-1 debt paid); next-release bundle staged
## (no game data). Every day of the 08-12 week plan delivered.**

**D1 FULL RE-PAIR (the Day-1 G5 debt):** decomp_d1_gate.sh's return leg swapped to the Day-2
mapped route (nav_gameover_np_to_topmenu) — the drive now fires and captures the QUIT family.
Control = build_win.sh objects relinked minus decomp_driver_msgs.o → build/futari_ctrl.exe.
Four unattended runs, every nav assert green: ctrl-vs-ctrl 74/74 (arms matched);
**ctrl-vs-pilot 74/74 CANONICAL-IDENTICAL in BOTH pairings** — full loop incl. 20 quit-family
lines (msgs 10/11/13). DRIVER_NOTES.md §3 addendum has the table; logs _local/logs/d1r_*.

**BUNDLE STAGED (dist/next_release/):** wizard launcher + README (2P + no-game-data + settings
notes) + STAGING.md (assembly recipe: binaries at release sha, tools/extract, DUMPING.md,
save_freshcard; ⛔ assets\ AND shell\ excluded — default.xex is disc content, the wizard
stages it). Owed before a PUBLIC zip: user wizard run + play sign-off; go-public = user call.

**THE WEEK (08-12 plan → done):** D1 frameclock flip ✅ · D2 game-over map + full loop ✅ ·
D3 honor-settings (closed by re-derivation) ✅ · D4 asset extraction shipped-shape ✅ ·
D5 pump-family deletion + ladder ✅ · D6 2P join working ✅ · D7 this. Standing owed:
pump/submit readable refactor; 2P polish row (#9); attended user acceptances (wizard run,
save round-trip B3, 2-pad couch session).

## ★★★★★★ 08-14 NIGHT-6 — **DAY-6: 2P JOIN OPENED AND WORKING (94030b2) — two-ship co-op
## verified live. The backlog-#9 "no game-side writer" mystery was input starvation.**

The join gates (0x884D763C/7640) never had a mystery: their writer, the join handler
**sub_881366D0**, simply never ran because scripted XamInputGetState served user 0 only.
Physical XInput index 1 → user==1 was ALREADY shipped (the RT_XINPUT leg). Day-6 added the
scripted half: the pad FIFO takes an optional 4th hex field = the P2 word ("<p1> <lt> <rt>
<p2>"; `echo "0 0 0 10"` = P2 START), OR'd into user==1 alongside XInput idx 1. Existing
writers unaffected.

**VERIFIED LIVE (RT_JOINP probes armed, screenshots banked):** 1P at arcade char select →
P2 START → `[joinp] *** 881366D0 ENTER slot=1 ... WILL-JOIN ***` → the 2P frame fills
(Palm & Hirow beside Reco & Kiniro, "No Entry" gone) → both players through char+shot
selects on their OWN pad words → **TWO-SHIP co-op stage** (both ships, both HUDs, Original
Mode) → unattended idle-die → the standard replay-save prompt, cleanly. **The 07-23
post-join freeze (msg-10 pause spin, the RT_NOPAUSE origin story) did NOT reproduce** — the
08-03 proper pause-flow fix retired it. Sequencer chain healthy throughout ([seq] ctxstate
advancing, 0f4=1, [csa] reaching state 11).

⏭ 2P polish remaining (small, backlog #9 row): isolated distinct-movement assert; the 2P
SIDE START menu route; a 360-module 2P pass; nav_2p library leg for unattended co-op drives.

## ★★★★★ 08-13 NIGHT-5 — **DAY-5 SWEEP DONE: THE GATE-3 PUMP FAMILY IS DELETED (Day-1's owed
## retirement leg) — full ladder re-run GREEN on the pump-free build. Score Attack sign-in
## decline re-verified end-to-end (#10).**

**PUMP RETIREMENT (shell/gen/rt.cpp, ~175 lines deleted; tombstones + git carry history):**
RT_GAMETICK, RT_TREEPUMP, RT_GAMEPUMP, RT_GAMEPUMP_VBLANK (vbpump) and the SEVEN bring-up
levers nested inside the pump body (RT_STARTBIT, RT_ACKQUIESCE, RT_RELOADCLR, RT_MODE64,
RT_KICKWORK, RT_DUMPGUEST, RT_LOADSIG) — the 07-06..07-23 scaffolding that drove msg-5 from
the host present path. g_game_tick_modectx KEPT (merged_shell writes it; [fsmlog] banner reads
it). RT_GAMEPUMP=1 dropped from every ACTIVE env (scripts/, dist/next_release launcher,
_local/_tmpscripts ladder+drive scripts); historical probes keep their era's env (a stale set
is a no-op now — the code is gone). NO revert lever, deliberately: G6 proved the natural
vbisr/shell chain, and the frameclock owns the grants.
**FULL LADDER on the pump-free build (the ruling's price, paid):** swapbounce PASS (slotreset
6/6, epochinval 40, alive) · decouple abn 65.2/s vs 13.3/s DECOUPLED · decouple arcade 66.2/s
vs 13.3/s DECOUPLED (0 drains-timeouts, nav 8/8) · day2_validate FULL LOOP arcade PASS + 360
PASS (4/4 each). Five for five.

**#10 SCORE ATTACK SIGN-IN GRACEFUL DECLINE — re-verified scripted on today's build** (08-03
user ruling re-proven): hub A → the guest's own dialog "ランキングにアクセスするには Xbox LIVE
にサインインする必要があります / A:OK" → A → BB298→BA4D8 clean → **the SCORE ATTACK submenu
with only LEADERBOARD greyed** — declined-but-playable, no hang, no crash, screenshots banked.
The unsigned-console stubs produce the authentic flow end-to-end. #10 CLOSED.

Sweep residue folded in: dist/next_release launcher lost its inherited RT_GAMEPUMP line (and
the sed-scar bare 'set' fixed).

## ★★★★★★ 08-13 NIGHT-4 — **DAY-4 DONE: ASSET EXTRACTION IS SHIPPED-SHAPE — user-supplied
## dumps work end-to-end, the DLC entitlement stub is GATED, and the next-release launcher
## carries the first-run wizard. Backlog #13 (the public-release critical-path item) is
## functionally closed.**

Prep merged (day4-extract-prep → main; worktree removed). Everything below ran on main:
- **DLC ENTITLEMENT GATE (the prep's must-fix, shell/gen/stubs.cpp):** g_dlc[] entries are
  served ONLY if their data exists under the asset root — BL keyed on Rom/cg_black(.hi).bin,
  Ver1.01 on the DISC-sourced cg_v102 pair (DESIGN §4: the V101 DLC is an 11-byte license,
  NO data — so data-presence is the only sane key and any full dump owns it). RT_DLCFORCE=1
  reverts. VERIFIED BOTH WAYS live on an extracted tree: both OWNED with DLC; cg_black*
  removed → 'entry 0 MISSING' + only DLC #1 served, shell clean. (In THIS build BL is greyed
  by the modestub hosting mask regardless — the gate's crash-prevention lands when a BL-hosting
  build exists.)
- **EXTRACTION RE-PROVEN ON MAIN:** real GoD container ("360 USB") → 54/54 + staged copies +
  the friendly BL-absent notice; + unpacked DLC (D:\360\00000002\496F…) → 58/58; --verify-only
  clean. CORRUPT-INPUT leg (prep's untested #3): byte-flipped Data0002 → loud fail naming
  file + block ("data block 1213 fails its hash"), EXIT 1, no partial output.
- **ACCEPTANCE (prep's untested #4):** the port BOOTED AND REACHED THE TOP MENU entirely off
  the extracted tree (RT_GAME_ROOT=C:/tmp/day4/assets + the extracted shell/default.xex).
- **INTEGRATION SHAPE (DESIGN §7 rec, adopted):** dist/next_release/"Futari 1.5.bat" = the
  next-bundle launcher template — assets\default.xex missing ⇒ first-run wizard (python check,
  drag-prompt, extractor, optional DLC leg, quote-stripping for typed paths, hard-stop on
  failure). TESTED END-TO-END from a bare staged bundle: main extraction + DLC leg → 58/58.
  Template also DROPS beta1's stray RVK_RESLOG=1 (the instrument-in-ship-config class, 4th
  find). Packaging must stage tools/extract/ + docs/DUMPING.md into bundles.
- **docs/DUMPING.md** written (adapted from futari_recomp's — no dlc/ folder here; BL unpacks
  into assets/media/Rom; manifest_v1.tsv is the ground truth; gate-log line documented).
- **RULINGS TAKEN (autonomous, revisit if wrong):** keep the 23MB never-read files (manifest
  identity beats 2% savings); DEFER the shell/default.xex dedup (the tool stages it — zero
  cost; deleting it churns every launcher/drive script); Python dep accepted for beta
  (futari_recomp precedent).
- **STILL OPEN (honest):** no Futari ISO on this machine (XDVDFS leg inherited-proven only);
  no packed BL STFS of THIS title (reader positive-controlled on 4 others; package-internal
  path fallback untested); a user-driven attended run of the wizard (B3-class acceptance).

## ★★★★★ 08-13 NIGHT-3 — **DAY-3 DONE: HONOR-SETTINGS CLOSED BY RE-DERIVATION — the guest
## honors its OWN settings under RT_NVK=2; backlog #7's premise was legacy-era. B1 verified
## fixed. Save-poke matrix, all green.**

Method = settings_audit.md 0-PRE's own precedent (no checksum ⇒ poke savegame.bin, boot, look;
_local/_tmpscripts/day3_poke.sh, one boot per variant, screenshots + instruments, evidence
/c/tmp/day3/). Blk3 truth re-pinned en route: the recurring 8,8 pairs at 0x16F8 + i*0x80 are
the per-preset ROTATION pairs (stride 0x80 re-confirmed; the audit's +0x34 "zoom pair" claim
was its own retracted guess — zoom/position sub-offsets remain unpinned, N1). Picture presets
@0x1AF8 + i*0x2C carry real factory content.

**MATRIX (ship build b85119b, RT_NVK=2, frameclock default):**
- Rotation/TATE (0x16FC=1): ✓ whole panel quarter-turn, guest-applied (08-01 proof holds today).
- Layout preset idx (0x16F0=1): ✓ the ExtraView MULTI-PANEL layout renders — main panel + 3
  positioned/zoomed sub-views. The "whole family ignored" audit verdict is REFUTED.
- Picture preset idx (0x16F4=3): ✓ full-panel scanline/effect wash renders (Effect/Glare class).
- Brightness (0x16DC 90→30): ✓ visibly dim.
- DropShadow (0x16E0→0): ✓ [shadowring] gate14 1→0 — the guest reads the byte and gates its
  own ring draws. SimplifyDraw (0x16E8→1): ✓ gate18 1→0. (The hook logs entry always; the
  gate dwords are the verdict.)
- B1 (settings-reset-when-replay-exists): the multi-item enumerator fix is IN and VERIFIED
  live with a dual-package root (save_rdcval copy): pkgs=2, 'replaydata.bin' item 1 of 2 +
  'systemdata.bin' item 2 of 2, savegame.bin resolves under systemdata.bin.
**OPEN (small, banked in BACKLOG #7):** FrameDelay untested (pacing); Color/ExtraView
sub-offsets unpinned (N1); oracle-grade effect fidelity post-beta; B3 user menu round-trip =
attended acceptance (user's hands).

## ★★★★★★ 08-13 NIGHT-2 — **DAY-2 DONE: THE GAME-OVER BRANCH IS MAPPED AND THE FULL LOOP IS
## SCRIPTED — boot→stage→death→shell TOP MENU, both modules, 4/4 assertions, unattended.**

**THE 08-11 CONFUSION NAMED: two different game-over flows.** NORMAL PLAY idle-die with a
non-ranking score shows exactly ONE prompt (replay-save; marker-less; the continue "PRESS
START" screen beneath) then goes to the MODULE TITLE — no score-register, no ranking dialog.
The Score-Attack flow (mapped 08-12) has all three prompts and lands on the HUB. The old blind
B,B,A pressed two extra buttons into the title = the "unreliable post-game-over" desyncs.
Mapping method: modified day2 harness to PARK AT DEATH with nothing pressed (the staged
harness's own blind B,B,A would have destroyed the evidence), then screenshot-per-press.

**THE MAPPED NP FLOW (markers all module-agnostic, NAV_MAP.md updated):**
  replay prompt --B--> [gemsg] msg=10 (+ modegate +120 5→0) → TITLE
  --START--> msg=11 + [p0build] 7 items / hub vt=0x820503B0
  --B--> [decide] item=-1 confirm --A--> msg=13 then msg=3 → SHELL vt=0x82050518
Death timing varies + marker-less prompt ⇒ the leg B-POLLS for msg=10 (in-stage B = bomb,
harmless; at-title B = no-op). ⚠ [gemsg] detail = first 3 calls per msg per session.

**DELIVERED:** scripts/futari_nav.sh nav_gameover_np_to_topmenu() (probe-verified retries);
NAV_MAP.md GAME OVER split into the two flows; _local/_tmpscripts/day2_validate.sh = the
FULL-LOOP validation (boot → card → land → selects → stage → idle-die → game-over → shell):
**VALIDATE_arcade_PASS + VALIDATE_360_PASS, 4/4 assertions each, first try, unattended.**
360 mirrors exactly (msg=10/11 same arg shapes, lr +8-shifted). Quit-family live-fire banked
(msgs 10/11/13/3 in /c/tmp/day2/validate_*.log) — the D1 gate's return leg is UNBLOCKED and
unattended full-loop soaks are now possible.
⚠ OPEN EDGE: a RANKING score on NP may add the score-register prompt (unobserved) — the
B-poll would decline it but the msg id is unverified; map it when a scoring drive exists.

## ★★★★★ 08-13 LATE — **MODES 1/3/4 COVERAGE CLOSED BY STATIC PROOF: UNREACHABLE-BY-DATA.
## Every cg archive is 100% mode 2. The round-5 coverage debt is settled, not deferred.**

The question "which drive fires modes 1/3/4?" has a data answer, not a drive answer. The mode
byte is TOC rec[2] (archive.cpp's disk-format writeup: 16B header — magic / totalSize /
dataStart / entryCount — then entryCount × 12-byte records at offset 16, expanded to the 0x14
in-mem TOC; self-check dataStart == 16 + count*12 holds on every file). Static parse of ALL SIX
archives (cg_v154/cg_v102/cg_black × base/hi): **7239/7239 records are mode 2.** Modes 1
(LZ77-ring A248), 3 (9D90) and 4 (9A88) are dead library codecs on this title — no asset can
ever dispatch them, in either module, in any version.

Empirical agreement: extended recon drive (decdiff_recon.sh — selects → stage → 55s gameplay →
game-over prompts): **730/730 [declog] fires mode 2** (also free extra soak on the MATCHED
pipeline: stage streaming + game-over ran the decomp asset path beyond the select gate).

DISPOSITION (registry rows updated in-place): the three decoders stay DRAFT with an
UNREACHABLE-BY-DATA gate note — no live differential is possible, deliberately not promoted.
Modes 3/4 are ops-verbatim transcriptions (behavior-identical by construction); their queued
readable refactor is DEPRIORITIZED as museum work on a dead path. Mode 1's only remaining
promotion path = a matchlab asm-exact entry (none exists for any mode decoder). The pump/submit
readable refactor stays QUEUED — those are live on every decode.

## ★★★★★★ 08-13 NIGHT — **GIG-5 (UPLOAD PATH) LIVE-GATED AND MERGED (b85119b + gate commit).
## sub_8808D640 + sub_8808DF70 MATCHED. Registry: 13 fns promoted today total.**

decomp-gig-5 (cae95e1, natural-C Page_StageUpload/Page_FillFromCpu, mechanical gates green in
the worktree) merged to main, then live-gated on the decdiff apparatus:
- **abn safety FIRST**: the TU hardcodes PAGE_TABLE 0x887518D0 / PAGE_LOCK 0x887398A8 /
  G_DEVICE 0x887AD5D0 — VERIFIED +0x60-shifted in the abn twins (out_reco_abn ppc_recomp.4:
  -10800→-10704, -26456→-26360, 6352→6448; symbols un-shifted, both fns below the split, so the
  agent's nm check couldn't see it). asset_upload joined the abn exclusion in BOTH build scripts
  + the control build's EXCLUDE — the exact landmine the differential caught this afternoon,
  stopped pre-merge this time.
- **Execution proof** (both bodies UNHOOKED ⇒ no existing instrument attests them): RT_UPCANARY
  one-shot canaries added to the TU (default-off, kept). Pilot select drive: Page_StageUpload
  ×5 (upload-descriptor path lr=88090F2C, pages 3-6), Page_FillFromCpu fill-arm ×11 (pages 3-8)
  — the producer→consumer staging mailbox ran live end-to-end.
- **Stream + visual**: RT_DECLOG vs rebuilt control STRICT 398/398 unchanged (RAW src-addr drift
  only, the documented class); char select + shot select (THE page-compose screens) clean, my
  eyes. Control ran 0 canaries (identity proof: generated upload on control).
⇒ both rows DRAFT→MATCHED (gate strings updated in-row; asm_exact sha1s already banked).
⏭ still owed from round 5: modes 1/3/4 live-fire coverage; pump/submit + modes 3/4 readable
refactor; game_abn twins for all 5 excluded asset TUs if abn-side decomp is wanted.

## ★★★★★★★ 08-13 EVE — **THE ASSET-PIPELINE MATCHED DIFFERENTIAL RAN — AND FIRST CAUGHT A
## SHIP-BLOCKER: the decomp asset TUs broke the 360 MODULE (+0x60 .data literals). Fixed by
## abn exclusion; the arcade differential then PASSED every leg. 11 fns DRAFT→MATCHED.**

**THE CATCH.** First pilot card/select drive: 360 card decide fine, abn archive [winit] ok, then
"Now Loading" FOREVER — 0 [wjob], 0 [declog]. Control build (generated DLLs, loaded via
RT_MODDLL_DIR=build/ctl_dlls; built by _local/_tmpscripts/decdiff_build_control.sh =
build_win_dll.sh's DLL half minus the 4 asset TUs) on the identical drive: 86 read-jobs, 213
decodes, module fully alive. MECHANISM (generated-source proof): the normal pump materializes the
TOC ptr as lis -30597 / addi **-11864**; the abn pump (sub_8813A740) uses addi **-11768 = +0x60**
— the game_entry_msgs .data-shift law. The 4 asset TUs hardcode reco_normal literals (ARC_TOC_*,
mode-1's ring dict, archive globals) and rode into the abn DLL, where the +8 map renames FUNCTION
symbols, not embedded data addresses ⇒ the abn job system read/wrote globals 0x60 off ⇒ dead ⇒
every 360 session since the leg merged hung at "Now Loading". The overnight "LIVE-EXECUTED"
evidence was ARCADE-only; ship-build GREEN was link-only. Gate lesson re-taught: a shared-TU
merge's blast radius is BOTH arms — an arcade-only live gate does not cover it.

**THE FIX (build_win_dll.sh + build_win_abn.sh):** asset_decode / asset_pump / archive / mem_util
join game_entry_msgs on the abn exclusion list — the abn arm runs the GENERATED bodies until
decomp/game_abn/ twins are earned. 360 regression re-drive after rebuild: 86 wjob / 213 declog
(count-identical to control), ranking attract renders clean.

**THE DIFFERENTIAL (arcade arm = where the decomp pipeline lives post-fix).** Scripts:
_local/_tmpscripts/decdiff_arcade.sh (nav = scripts/futari_nav.sh legs, all asserts green) +
decdiff_compare.py; evidence banked /c/tmp/decdiff/ (logs, dumps_pilot/, dumps_control/):
- RT_DECLOG stream equality: STRICT (fn,r5,lr,exit-r3) **398/398 IDENTICAL**. RAW diverges only
  at the src-buffer heap address (entry 58: 080D8000 vs 089F8000) = the documented alloc-drift
  class; the DST is identical throughout (staging buffer 0x03DE0000, all 398 decodes).
- RT_DECDUMP byte-compare: **398/398 out.bin BYTE-IDENTICAL** across the two builds.
- Pixel-visual: pilot char select (Reco&Kiniro portrait, gold filigree, No Entry frame) + shot
  select (stone plates) CLEAN — my eyes via computer-use, matching the control-arm screens.
⇒ **11 fns DRAFT→MATCHED** in decomp/registry.toml (mode-2 decoder 8813A118, pump 8813A738,
submit 8813A4D0, completion 8813A6A0, archive 88092ED8/B20/7A8/AA8/B80 + 8813A460, mem_util
88072260); every row carries the full gate string + the abn-scope caveat.

**COVERAGE BOUNDARIES (no silent caps):** only MODE 2 live-fired (all 398) — modes 1/3/4
(A248/9D90/9A88) had ZERO fires on the select drive and stay DRAFT; archive teardown 880929C8 +
companion 88092668 unexercised, stay DRAFT. The abn arms of all 4 TUs are build-excluded — no
abn differential is possible until game_abn twins exist.

**DRIVE-ENV TRAPS BANKED:** (1) card360_probe.sh's RVK_FPS=3 wedges the abn boot under the
frameclock default (one [evt34] grant then starvation) — decdiff_* scripts use the swapnp/proof
env (no present throttle). (2) 'XexLoadImage' as a swap wait-marker false-positives on boot-time
lines — wait on '[modswap] #N DONE' + the module NAME (futari_nav.sh already does this right).
Incidental: the whole session ran on the flipped frameclock default (shell nav, swaps, both
modules' selects) — free soak on top of the Day-1 ladder.

⏭ NEXT: (a) decomp-gig-5 (worktree projects/futari_decomp_gig5, commit cae95e1, UNMERGED) =
upload path sub_8808D640/DF70 as natural C, mechanical gates green — its live differential rides
THIS apparatus (D640 fires in pump state-5 on the same select drive); merge after that gate.
(b) modes 1/3/4 live-fire coverage (find the drive that hits them — stage entry / other screens).
(c) the sanctioned readable refactor of pump/submit + modes 3/4 (the live gate now exists).
(d) game_abn twins for the asset TUs if abn-side decomp is wanted; else the exclusion stands.

## ★★★★★★★ 08-13 — **THE ASSET-PIPELINE LEG: the whole archive→decode→upload chain is now
## human-readable C. 45 fns across 5 files, ship build green, live-executed with 0 failures.**

Driven as a multi-agent leg (4 parallel/sequential Opus rounds + a main-session consolidation),
completing the decomp of Futari's asset-load pipeline end to end. Registry: ~16 gated/MATCHED-track
+ ~130 DRAFT of 247.

**THE FILES (decomp/game/ + decomp/shell/):**
- driver_msgs.{inl,cpp} — GameDriverTask command surface, 16 shapes × 8 clones = 128 fns (rounds 1-2).
- mem_util.cpp — shared guest memcpy sub_88072260 (224 refs; the leaf everything leans on).
- asset_decode.cpp — the decompressor family: mode 1 LZ77 4KB-ring (sub_8813A248, clean C),
  mode 2 LZSS (sub_8813A118), modes 3/4 'ZZ' bit-adaptive (sub_88139D90/9A88, faithful
  transcription — bit-reader byte-boundary IS the spec; readable refactor deferred to the live gate).
- archive.cpp — TOC/file-read layer, 8 fns (sub_88092ED8 init, sub_88092AA8 id→bytes, sub_88092B80
  cache, sub_88092B20 sync-read, sub_880927A8 file-read, sub_880929C8 teardown, sub_88092668 companion,
  sub_8813A460 chain-walk). Archive format derived byte-exact (16B header, count×0x14 in-mem TOC).
- asset_pump.cpp — THE KEYSTONE: sub_8813A738 per-frame job pump (16-slot ring state machine),
  sub_8813A4D0 submit, sub_8813A6A0 completion (natural-C leaf). Ties archive+decode together.

**PIPELINE FLOW (asset_pump.cpp header, addresses cited):** archive-open sub_88092ED8 (handle
0x88252E1C, TOC 0x887AD1A8) → submit sub_8813A460→sub_8813A4D0 arms a 56B slot in the 16-entry
ring 0x884D20E8 from descriptor table 0x88290CD0 → per-frame pump sub_8813A738 walks slots
(cursors 0x887ACDFC/0x887ACE00) through states 0=alloc+read, 1=mode-dispatch, 5=descriptor+upload
(sub_8808D640) → decode (modes 1-4) → completion sub_8813A6A0.

**GATES:** MECHANICAL PASS on every function (build/futari_merged.map: __imp__ → decomp .o wins,
generated __imp__ + strong instrument hooks retained). SHIP BUILD GREEN (combined exe + both DLLs
+ both merged monoliths). LIVE EXECUTION VERIFIED (main session, merged build, arcade→select
drive): [winit] archive-open ×3, [wjob] read-jobs ×86, decode hooks fired, 51 texture uploads,
0 loud failures, game steady @59.94Hz. ⏭ MATCHED-PROMOTION GATE (deliberate awake pass): the
control(generated)-vs-pilot(decomp) byte differential — RT_DECLOG stream equality + RT_DECDUMP
decode-output byte-compare on a card/select drive — plus a pixel-visual of the decoded portraits
(display was asleep for the overnight run).

**BUILD-SYSTEM BUG FIXED (latent, found via the leg):** archive.cpp was the first shared decomp TU
to call a +8-shifted callee (sub_8813A6A0→sub_8813A6A8 in abn). build_win_dll.sh (the SHIP build)
consumed a STALE out_reco_abn/abn_symbol_map.h — only build_win_abn.sh regenerated it. Wired
gen_symbol_map.py into build_win_dll.sh so a fresh scan covers any new shared TU. Would have
silently broken the abn module DLL for every future +8-referencing decomp file.

⏭ LEG-COMPLETE REMAINDER: (1) the MATCHED differential above; (2) fold in the upload path
sub_8808D640/sub_8808DF70 (already ASM-EXACT in matchlab) — the last still-generated pump callee;
(3) refactor the mode 3/4 + submit/pump transcriptions to readable C once the live gate proves it.

## ★★★★★ 08-13 DECOMP SIDE-GIG round 5 (branch `decomp-gig-5`, DRAFT — not merged) — **THE
## UPLOAD PATH IS FOLDED IN: the asset pipeline is now human-readable C from archive byte to
## tiled texel. The pump has ZERO still-generated write-side callees.**

Remainder item (2) of the 08-13 asset-pipeline leg, cashed. **`decomp/game/asset_upload.cpp`** —
the two page-cache writers, both as **human-readable NATURAL C** (no faithful-transcription
fallback was needed, and that is the point: see PROVENANCE below).

- **sub_8808D640 `Page_StageUpload` (PRODUCER, asset-pump thread).** `(pageId, src, sizeState)
  -> 1 staged / 0 refused`. Refuses `pageId >= 0x200` or a null device `[0x887AD5D0]`; else, under
  the page lock `[0x887398A8]`, parks a private CPU copy of the freshly decoded image in the page
  record's staging buffer (`rec = 0x887518D0 + pageId*0x14`, `dim = sizeState<<8`,
  `bytes = dim*dim*2`): a `stageSize` mismatch frees + re-allocates the buffer, then it stores
  stageSize, arms `state = 0` (upload pending) and memcpys. **It touches no GPU state at all** —
  that is the whole design: the streaming/decode thread never calls D3D.
- **sub_8808DF70 `Page_FillFromCpu` (CONSUMER, render side; only caller sub_8808E468, the family
  that also drives the sub_8808DC10 bake).** One sweep of all 512 records under the same lock:
  `state != 0` = release requested (drop texture, re-arm); else `srcBuf != 0` = pending upload →
  ensure the texture at stageSize (sub_8808D838) → **XGTileSurface** the linear staged image into
  the locked texture → unlock → free the staging buffer **on both arms** (an ensure failure must
  not leak it). ⚠ **The copy is a TILE, not a memcpy**: the destination extent comes from
  XGGetTextureDesc (`Pitch/BytesPerBlock`, `HeightInBlocks`), so a padded row pitch is honoured —
  anyone porting this to the native renderer must reproduce the linear→tiled step, not the byte
  count. `dim` is read from `rec.sizeState` **after** the ensure rewrote it, never from stageSize.

**PROVENANCE — the strongest this campaign has had.** Both functions are **ASM-EXACT in
tools/matchlab** (`Page_StageUpload` 63 insn, sha1 d0122ee8…; `Page_FillFromCpu` 81 insn, sha1
26025ea0…): their C rebuilds the *shipped instruction bytes* under XDK 9328 cl.exe. So the record
layout, argument order and XG/D3D signatures are not inferred from the recomp — they are proven.
That is exactly why round 5 could write readable C here while rounds 3-4 had to transcribe the
bit-readers: there is no residual uncertainty for the live differential to resolve, only execution
to witness. (Byte-matching demoted to a verification tool on 08-11 — this is that tool paying out.)

**SEAM (measured, not assumed): BOTH UNHOOKED** → plain `PPC_FUNC` for both. No strong
`PPC_FUNC(sub_8808D640/DF70)` exists anywhere outside the generated tree, so the SHADOWED-HOOK
`__imp__` form was not needed (contrast asset_pump.cpp, where 2 of 3 were hooked).

**GATES.** MECHANICAL PASS — fresh `build/futari_merged.map` (verbatim, 2026-08-13):
```
 0001:00004ab0  ?sub_8808D640@@YAXAEIAUPPCContext@@PEAE@Z  0000000140005ab0  decomp_asset_upload.o
 0001:00004c60  ?sub_8808DF70@@YAXAEIAUPPCContext@@PEAE@Z  0000000140005c60  decomp_asset_upload.o
 0001:0063d7f0  __imp__sub_8808D640                        000000014063e7f0  game_ppc_recomp.4.o
 0001:0063fc80  __imp__sub_8808DF70                        0000000140640c80  game_ppc_recomp.4.o
```
Both strong bodies win (that is the symbol every caller resolves through, incl. asset_pump.cpp's
state-5 `sub_8808D640` call); both generated `__imp__` bodies stay linked as dead rollback bytes.
`llvm-nm build/obj_dll_reco_abnormal/decomp_asset_upload.o` confirms the abn arm too: both `T`
definitions un-shifted, all ten callees + the two Rtl imports `U` un-shifted. `build_win.sh` LINK_OK (objects 93 → **94**);
`build_win_abn.sh` LINK_OK (95); **`build_win_dll.sh` BUILD_OK — combined exe + both module DLLs**.
abn map regen: **no new renames** (all ten callees + both entry addresses are below the 0x880DEF88
split); only the informational count moved 107 → 115 referenced-below-split — committed as the
settle, same as the leg's own abn commit.

**C1 discipline.** Both are non-leaves: 5 bl boundaries in D640, 10 in DF70, each with the exact
generated argument registers + `ctx.lr` = that call's return address, callees invoked through their
plain `sub_*` symbols. Guest frames emulated on both — and in DF70 that is **mandatory, not
cosmetic**: the D3D/XG out-parameters (POINT sp+80, D3DLOCKED_RECT sp+88, RECT sp+96,
XGTEXTURE_DESC sp+112 zero-filled 0x3C as 7×stdu + 1×stw, the generated inline memset) live in the
frame the callees write into.

**⏭ STILL OWED (unchanged in kind — this is a DRAFT branch):**
- LIVE-FIRE / MATCHED differential for both (RT_DECLOG-style control-vs-pilot on a card/select
  drive). D640 fires on every streamed page via the pump's state-5 arm; DF70 runs per frame off
  sub_8808E468, so a plain attract boot should already exercise the sweep — cheap positive control.
- Merge to main (branch `decomp-gig-5` is unmerged, deliberately).
- Round-5 remainder items (1) the MATCHED differential and (3) the mode 3/4 + submit/pump
  transcription refactors are untouched by this round.
- Registry: rows 0x8808D640 / 0x8808DF70 advanced NAMED → **DRAFT** with the map-gate evidence.

## ★★★★★ 08-13 DECOMP SIDE-GIG rounds 2+3 (merged from decomp-gig-3) — **+34 fns: the
## GameDriverTask vtable FINISHED + the asset-codec leaf cluster opened.**
Round 2 (branch decomp-gig-2, commit d97affc): the 4 remaining GameDriverTask vtable slots as
4 shapes × 8 clones = 32 fns — +0x14 Driver_ArmModeExt, +0x34 Driver_SendDescriptor (msg-20),
+0x18 Driver_ArmModeStaged (first wrapper to call a SIBLING vt slot, not GameEntry), +0x70
Driver_Init (boot-path init burst; the writer of the driver+0xB4 state block the predicate
shapes read — closes round-1's open loop). All DRAFT/PENDING-GATE (fire only on a real mode
launch; the background boot can't reliably reach it — leave for attended live-fire via
scripts/_gig2_gate.sh). Clone sets mechanically proven (8 byte-identical members each); map =
32/32 → decomp_driver_msgs.o, generated __imp__ retained as rollback.
Round 3 (commits d20284e, 6a2f222): the asset-codec leaf cluster — sub_88072260 (shared guest
memcpy, 224 refs = highest-value single leaf) → decomp/game/mem_util.cpp; sub_8813A118 (Mode-2
split-stream LZSS decode) → decomp/game/asset_decode.cpp (seeds the decode-family folder + a
durable decode-format writeup in the header). Both pure leaves (natural-C sanctioned). Mechanical
gate PASSED (map: __imp__ → my .o wins, strong instrument hooks + generated rollback both retained,
links green); behavioral gate PENDING (RT_DECLOG stream-equality + RT_DECDUMP byte-compare
wrappers are IN-TREE, ready for a decode-exercising drive). ⏭ round 4: bank the PENDING live-fires;
finish decode modes 1/3/4 (sub_8813A248/9D90/9A88, all non-leaf — C1 register discipline);
then sub_8808CE90 tracked-alloc. Registry now ~13 MATCHED-or-gated + ~124 DRAFT of 247.
⚠ pre-existing registry.toml strict-TOML break (~line 1394, Rom\cg_v154hi.bin) still there.

## ★★★★★★ 08-13 DAY-2 — **GAME-OVER BRANCH MAPPED BY EYE; THE 08-11 "D70 PARKED" DEAD-END WAS A
## MISDIAGNOSIS. Full loop boot→stage→game-over→shell is now a deterministic unattended drive.**

**METHOD (satisfied the 08-11 screenshot-per-press ruling headlessly):** validated a RenderDoc
capture→PNG "eyes" pipeline (rdc_eyes_validate.sh: the in-app RVK_RDCCAP present-count trigger
+ extract_oracle_any.py; attract frame read + identified) AND used direct window screenshots
(grant: Futari_combined, full tier). Rolling capture cleaned up after (4.5G reclaimed — disk).

**THE MAP (arcade NORMAL PLAY game-over):** idle-die → decline both save prompts (B,B) → OK the
ranking-cancelled dialog (A) → the **MODULE HUB** (7-item menu, cursor on SCORE ATTACK) — NOT a
title, NOT a dead state. From the hub: **B** → "トップメニューに戻ります。よろしいですか?" confirm
([decide] item=-1) → **A** (はい) → **shell TOP MENU**. 3 presses, verified on screen.

**ROOT CAUSE of the 08-11 dead-end:** `[engst] D70-PARKED vt=0x8204FDB8` fires CONSTANTLY from a
persistent BACKGROUND object — observed still firing at the shell TOP MENU. It was never a
screen state; gating nav on it was the error. **And** the HUB and the shell TOP MENU BOTH emit
`[mstate] BA4D8(ACTIVE) state 0x82061D50` — the discriminator is the **vt field** (hub arcade
vt=0x820503B0 ; shell TOP MENU vt=0x82050518). Blind BA4D8-matching = the desync source.

**BANKED:** docs/NAV_MAP.md GAME OVER section rewritten; scripts/futari_nav.sh
nav_gameover_to_topmenu() (probe-verified, vt-asserted). **DELIVERABLE GATE: fullloop_gameover.sh
— boot→arcade→stage→game-over→shell TOP MENU, PASS 2/2 runs first-try each.** This unblocks
unattended full-loop soaks and the decomp gates' quit-branch live-fire (round-1/2 debt).


## ★★★★★★★ 08-13 DAY-1 — **THE FRAME CLOCK IS THE SHIP DEFAULT (RT_FRAMECLOCK_VBLANK default
## ON, =0 = welded revert), the D1 decomp batch (96 fns) IS MERGED, and RT_GAMEPUMP IS PROVEN
## UNNECESSARY. Six-gate ladder green.**

**FLIP (67f7f0a):** default-on in shell/gen/rt.cpp (thread creation + skip gate); proof
scripts PIN the lever per-case (unset now means ON); EYEBALL_WELDED launcher + "Futari
Realcomp WELDED" desktop shortcut = the A/B fallback (EYEBALL_FRAMECLOCK superseded/deleted).
**MERGE (fadbb58):** decomp-gig D1 batch — registry now 9 MATCHED / 92 DRAFT (was 3/2).

**GATE LADDER (banked /c/tmp/day1_gates/, all on the merged+flipped build):**
- G1 swapbounce DEFAULT: PASS (rerun). First run FAILED P2 destroyed=4/6 — ⚠ KNOWN VARIANCE,
  NOT a regression: slotreset=6/6 even in the failing run (invalidation ran every swap); the
  "destroyed" line only prints when the map is non-empty at switch, and the frameclock msg-3
  DRAIN can let the renderer empty it first. If P2 flakes again: accept slotreset>=swaps as
  the invalidation evidence (P3+E3+slotreset cover the blast radius).
- G2 swapbounce =0 REVERT: PASS, baseline-identical shape (epochinval 5, the welded numbers).
- G3/G4 throttled proofs, pinned baselines: abn welded 16.6/s≈13.3 vs clock 64.8/s;
  arcade welded 16.4/s≈13.3 vs clock 66.9/s. Both modules decouple ON THE DEFAULT BUILD.
- G5 D1 gate on merged main: pilot leg clean (94 seq lines, 6 nav passes); the RETURN leg
  died at the KNOWN game-over gap (Day-2 target) — full control-vs-pilot re-pair rides Day 7.
- G6 **GAMEPUMP-OFF ARCADE (the retirement experiment): PASS** — RT_GAMEPUMP unset, frameclock
  default: presents 60.0/s, logic 62.9/s, 0 [gamepump] lines, stage reached. **The natural
  vbisr/shell chain dispatches msg-5 on arcade; the pump family is fully retirable** (VBLANK
  variant already superseded outright — no env sets it). Retirement = drop RT_GAMEPUMP from
  every gate env + delete GATE-3/vbpump code: its own leg with a full ladder re-run (Day 5/7),
  NOT a quiet env edit.

⏭ DAY 2 (tonight): game-over branch mapping (plan + harness staged in _local/_tmpscripts/
day2_*) — also unblocks the D1 gate's return leg and the remaining driver-shape live-fires.

## ★★★★★ 08-13 — **DAY-4 PREP BANKED (agent, branch day4-extract-prep, worktree
## projects/futari_extract_prep): ASSET EXTRACTION IS PURE RELOCATION — prototype already
## reproduces the tree 58/58 SHA-256-exact.**
All 58 assets/ files are unmodified byte copies: 54 straight off the disc filesystem (same
relative path, verified against futari_recomp's independent extraction), 3 = Black Label DLC
package-internal Rom/* unwrapped, 1 in-tree duplicate (+ shell/default.xex duplicates
assets/default.xex). Prototype tools/extract/futari_extract.py (adapted from futari_recomp
v1.5.1: XDVDFS + GoD hash-tree + the fs_base−0x10000 fix; NEW: STFS reader for the DLC,
positive-controlled on 4 real packages) ran against the user's real disc install: GoD→54/54,
+DLC→**58/58 full-tree match**, self-verified vs tools/extract/manifest_v1.tsv. Untested legs
+ open rulings in the worktree's DESIGN.md/STATUS.md (integration shape rec: standalone tool +
first-run launcher hook, the save\ pattern).
⚠ **REAL DEFECT FOUND (Day-4 must-fix): shell/gen/stubs.cpp:283-293 hardcodes DLC ownership
"owned" unconditionally** — un-greys Black Label regardless; crash-on-select the moment assets
are user-supplied. Gate g_dlc[] on media/Rom/cg_black*.bin presence. NOTE the repo never
tracked assets (.gitignore) — the 1.1GB lives only in the distributed bundle.

## ★★★★★ 08-12 DECOMP SIDE-GIG (branch `decomp-gig`) — **D1: THE GameDriverTask COMMAND SURFACE
## IS HUMAN-READABLE. 96 guest functions = 12 shapes x 8 clones, gated, 6 shapes live-fired.**

Plan §4 rank 5's promise ("8 near-identical clones collapse into one template + msg-id table —
the largest LOC reduction per effort in the project") is now cashed for the shell→game protocol
wrappers: `decomp/shell/driver_msgs.inl` holds twelve shapes, `driver_msgs.cpp` instantiates
them 96 times. The clone sets are MEASURED (normalise address literals out of every generated
body, group by result → exactly 8 members per shape, no more, no less), not transcribed.
FULL DETAIL: **`decomp/shell/DRIVER_NOTES.md`** (seam, gate, canary counts, next steps) and 96
new per-address rows in `decomp/registry.toml`.
- SEAM: plain `PPC_FUNC` (nothing in `out_reco/merged/*` hooks any of the 96). Fresh map:
  96/96 `sub_*` → `decomp_driver_msgs.o`, 96/96 generated `__imp__` still linked = rollback.
  No build-file change — all three build entry points already glob `decomp/shell/*.cpp`.
- GATE = `_local/_tmpscripts/d1_play_drive.sh`, a nav-driven ARCADE NORMAL PLAY entry drive.
  ⚠ The C1 boot→attract drive is USELESS here — measured zero calls to any of these slots in a
  95s attract run; the command surface only wakes on a real mode launch. Verdict: control-vs-
  pilot **RAW CANONICAL-IDENTICAL 94/94** on the matched arm; protocol stream 68/68 identical on
  every pairing. NEW DRIFT CLASS, proven control-vs-control: the guest-STACK pointer in
  `msg=10 r4` has two arms across runs (4 control runs: 3 + 1) — translation-independent.
- POSITIVE CONTROL (one-shot RT_DRVCANARY, since removed): 6 of the 12 shapes executed on the
  drive — predicate +0x38 **12345x**, msg-15 region 6x, msg-10 arm 3x, msg-11 rank 3x, msg-15
  block 1x, **msg-13 RETURN-TO-MENU 1x** (half of C1's msg-12/13/14 live-fire debt, sender side).
  Registry: those 6 addresses MATCHED, the other 90 DRAFT (linked + seam-proven, no live-fire).
- ⏭ NEXT: live-fire the remaining 6 shapes (msg 16/17/19 setters + msg-12 sender need a combined
  exe / 360 or training path, or the quit branch once nav's post-game-over gap is mapped); then
  the 4 unread slots (+0x14/+0x18/+0x34) and the init driver +0x70 (`FUN_821C30B8`), which is
  the most-exercised function of the family.


## ★★★★★★★ 08-12 EVENING — **FRAME-CLOCK SHIP DEBT CLOSED: swap-safe disarm (drain via ack
## poke) + the ARCADE seam. Both gated; one real parked-thread drain caught in the wild.**

**SWAP-SAFE DISARM (shell/gen/rt.cpp).** The hazard: a module swap while the dedicated
frame-clock thread is parked in FA68's INFINITE ack-wait left it executing dying-DLL code.
Closed with a two-sided handshake + drain:
- Thread side: `g_frameclock_ingrant` published (seq_cst) BEFORE the armed re-check, cleared
  after FA68 returns — so disarm either wins the race (thread sees armed=0 and never enters
  module code) or sees ingrant=1 and drains.
- Disarm side: after dropping armed, POKE THE GAME'S ACK EVENT until ingrant clears (500ms
  bound, loud `DRAIN TIMEOUT` on failure). The ack handle is read from guest **[0x885C657C]**
  — the same slot FA68 itself loads (`lwz r3,25980(r31)`, r31=0x885C0000; same static address
  in both modules, and hot-swap maps module data at identical guest addresses, so the read is
  always the CURRENT module's handle). Two subtleties that are the whole design:
  (a) **REPEATED pokes, not one** — FA68 clear-acks at entry, so a single poke racing the
  clear gets swallowed; (b) the poke goes through **`__imp__NtSetEvent`** so the linker routes
  it to the /FORCE:MULTIPLE WINNER (out_reco/rt.cpp) = the SAME event table the game's wait
  sleeps on — never shell-local rt_setev (possibly a displaced loser copy). Base for the guest
  read is stashed at Vd-callback registration (`g_frameclock_base`). Registry + msg-3 disarm
  call sites unchanged — they now genuinely block (bounded) until the thread is out.

**ARCADE SEAM (decomp/game/game_entry_msgs.cpp).** reco_normal msg-5 gets the identical
`rt_frameclock_present_skip((void*)&sub_8808FA68)` skip and msg-3 `rt_frameclock_disarm`; the
ABI/shim plumbing already carried the helpers for both modules (597f73f). Lever off => both
seams byte-identical to the matched bodies. gen_host_abi notes updated (abn-only wording was
stale); abi_hash UNCHANGED (signature-only hash) so no rebuild ripple.

**GATES, all green (all four build entry points relink):**
- swapbounce lever-OFF: PASS, baseline-identical (6 swaps, P4 19/19, high-water 496MB,
  epochinval 5 bounded, 0 `frameclock` lines — default-off inert confirmed).
- swapbounce **lever-ON** (the swap-while-armed exercise): PASS — 6 swaps armed, both DLLs
  alternate arm/disarm (arcade grantfn ...807E6920 / abn ...7D296920), 9600+ grants, and at
  teardown #4 the hazard actually fired: `DISARM (msg3 teardown): drained via ack poke x1
  (ack=0x50001648)` — the thread WAS parked in the ack-wait and one poke released it. Zero
  drain timeouts. Arcade grant rate from [evt34] wall-ms stamps: **59.9/s exact**.
- decouple_proof re-run post-refactor (the handshake touched the hot loop): welded 17.3/s
  logic ≈ 13.3/s present; frameclock **64.5/s logic vs 13.3/s present** — still decoupled.

✅ 08-12 LATER — **USER PACING-FEEL EYES: PASSED on the desktop PC** ("love it ... no
hitches"; EYEBALL_FRAMECLOCK launcher + desktop shortcut, delegates to EYEBALL_0811 with the
lever on). Session log eyeball_20260812_190348: armed on arcade, clean arcade-seam disarm at
the swap, re-armed on reco_abnormal — user played BOTH modules on the clock, 0 drain
timeouts. NOTE the desktop PC presents at ~60 so this is the no-regression half; the
speed-up half (throttled present) is instrument-proven on abn only.
✅ 08-12 NIGHT — **ARCADE THROTTLED PROOF: DECOUPLED. The last instrumented gap is closed.**
New nav leg `nav_arcade_land_to_hub` (futari_nav.sh): DEMONSTRATION attract → probe-verified
START (the attract is a FIELD scene — throttled+welded-slow, so a START can drop; retried like
the title flow) → hub → NORMAL PLAY → 1P SIDE START; then the module-agnostic selects. 8/8
assertions green on BOTH runs, first try. Proof (_local/_tmpscripts/decouple_proof_arcade.sh,
50ms field-gated throttle, module-verified reco_normal, self-diagnosing field check):
- welded_arc:    logic 15.6/s ≈ present 13.3/s — welded (and throttle engaged ⇒ field reached).
- frameclock_arc: **logic 65.8/s vs present 13.3/s — DECOUPLED**; armed=1, 0 drains, 0 timeouts.
✅ 08-12 LATE — **DECK PACING CHECK DONE (agent, real hardware, Proton Experimental, Desktop
Mode 720p windowed). TWO HEADLINES:**
**(1) The FNF-5 "Deck runs slow by construction" severity thesis did NOT reproduce** at the
measurement point (idle ship, stage 1 Original, 360 module): present ≈59.55/s in BOTH runs;
welded logic 59.81/s ≈ present. Severity revises toward the CORRECTNESS framing. ⚠ Scope
caveats: Desktop Mode (not gamescope), least-demanding scene, 300-frame present sampling —
busy-scene dips are NOT excluded.
**(2) Decoupling held AND the dedicated thread paces CLEANER than the weld on the same box:**
welded per-10s windows 10001–10126ms/600 grants (jittery); frameclock 10009–10011ms — dead
flat 59.94Hz, every window. 1:1 grant↔evt34 adjacency (zero leaked present-path grants, zero
doubles), armed once post-swap, 0 drain timeouts, welded log 0 frameclock lines (default-off
inert). Linux sleep_until ≥ Windows quality. Logs: _local/logs/deck_{welded,frameclock}.log
+ summaries + drive script (deck_run_pacing.sh.txt, traps in header). Deck staging DELETED
(verified; no Proton deployment persists — the native-ports-only ruling stands).
**THREE DECK TRAPS BANKED:** (a) `proton run` DISCARDS the app's stderr (detached launch,
NULL STD_ERROR_HANDLE) — use `proton runinprefix`; (b) ⚠ CARD-PANEL LEFT can be SWALLOWED by
the panel-open animation (~0.7s) → decide silently takes ARCADE; positional assert = 360-card
art load `[res] id=140 … lr=0x821B9D24` (the lr=0x8207BF20 id=140 is unrelated); panel WRAPS —
never re-LEFT after the marker fired; (c) wine interleaves multi-thread stderr MID-LINE — any
Linux-side log assertion must tolerate glued lines.
⇒ **The frame-clock lane is fully gated. RT_FRAMECLOCK_VBLANK default-ON flip is UNBLOCKED**
(next session; user pacing sign-off on the default-on build is the last formality, then retire
the RT_GAMEPUMP lever family). Also still owed from 08-12: game-over branch mapping (nav
library known gap).

## ★★★★★★★★ 08-12 — **TICK/PRESENT WELD SEVERED (360 path): the frame clock now runs on a
## dedicated 59.94Hz thread, DECOUPLED from present. Measured: logic 61.8/s while present 20/s.**

**THE FIX (RT_FRAMECLOCK_VBLANK, default OFF while gating).** The abn frame grant
(NtSetEvent 0x50000034 via sub_8808FA68 = clear-ack → grant → BLOCK on the game's ack) is
rehosted onto a DEDICATED frame-clock thread (shell/gen/rt.cpp) that paces it at 59.94Hz with
an absolute deadline. The abn GameEntry override (decomp/game_abn/game_entry_msgs_abn.cpp,
msg-5) calls rt_frameclock_present_skip(&sub_8808FA68): arms the clock and SKIPS the
present-path grant. Disarm at msg-3 teardown + module swap (host/module_registry.cpp).

**PROOF (decouple_proof.sh, exact counters, field-gated 50ms throttle, both on reco_abnormal):**
- welded (lever off): in-field logic ~16/s ≈ present ~20/s — welded (logic follows present).
- frameclock (lever on): **logic 61.8/s while present 20.0/s** — DECOUPLED. Logic holds ~60
  independent of a throttled present. The panel's FNF-5 correctness fix is DEMONSTRATED.

**THE DEBUGGING ARC — five traps, all banked (this cost the evening; do not re-pay):**
1. CROSS-MODULE rt_lookup: 0x8808FA68 is a GAME-DLL function; the shell's rt_lookup returns
   NULL for it (first cut: armed but 0 grants → game starved). Fix: the DLL hands the host
   &sub_8808FA68 via the ABI helper (void*, so gen_host_abi carries no PPC types).
2. `[nvk] submit` is logged EVERY 300th present (vk_render.cpp `++sub % 300`). Counting log
   lines said "presents frozen at 0.4/s" — a PHANTOM. It cost a whole redesign detour (though
   the dedicated thread is the right design anyway). ALWAYS use the frame-number field (f%ld)
   or a real counter for present rate, never `grep -c` on a rate-limited log line.
3. The self-freeze that motivated the dedicated thread was that same phantom — presents were
   ~60/s all along. The dedicated thread is kept because it correctly isolates the blocking
   ack-wait; it is not a workaround for a freeze that never existed.
4. The present-throttle BREAKS menu FIFO input (the LEFT-to-360 card press drops) → the drive
   silently ran ARCADE while a bare `modswap DONE` check believed it was on 360, POISONING a
   whole measurement. TWO fixes: (a) the throttle is FIELD-GATED (only sleeps when
   GA_FIELD_ACTIVE — menus present full speed); (b) nav_card_decide now verifies the SPECIFIC
   module (reco_abnormal / reco_normal via XexLoadImage), never a bare modswap.
5. rt_setup_thread_ctx ALLOCATES a fresh guest stack (~256KB) per call — the dedicated thread
   sets up its context ONCE and reuses it (FA68 restores r1 net-zero), or it would leak
   ~15MB/s.

⚠ SHIP-PHASE DEBT (lever still default-OFF): if a module swap happens WHILE the dedicated
thread is blocked in FA68's infinite ack-wait, disarm can't unblock it (parked in the host
wait-stub) → crash risk when it returns into unloaded module code. Cannot happen during gating
(lever off; measurement runs never swap-while-armed; swapbounce runs lever-off). Before ship:
give the ack-wait a timeout OR poke the ack event at disarm. Also: ARCADE (reco_normal) is
still welded — the seam is abn-only; the reco_normal override needs the same skip() for arcade
decoupling. And RT_FRAMECLOCK_VBLANK must stay OFF until the swap-debt is closed + gated + user
pacing-feel eyes.

⏭ NEXT: swapbounce gate lever-OFF (regression — default-off must not perturb swaps); then the
ship-phase debt (swap-safe disarm) + arcade seam + user pacing feel before default-on.

## ★★★★★★★ 08-12 — **THE ABN FRAME CLOCK IS FOUND, ATTRIBUTED, AND THE WELD IS MEASURED:
## 59.94Hz free ↔ 15.6Hz at a 15.6/s present. Guest logic follows present 1:1.**

**THE CLOCK:** the abn per-frame grant is NtSetEvent(0x50000034) via sub_88082BF8 (thin
wrapper, lr 0x88082C0C), waiter consumes at lr 0x8808334C — ONE setter, ONE waiter, lockstep
(sets==consumes across every run, no drops/double-grants). The grant family is the SAME
addresses as reco_normal (sub_8808FA68 grant / sub_8808FB90 wait — static map from
out_reco_abn recomp), executed on a SHELL thread on the PRESENT path. The msg-5 pump levers
(RT_GAMEPUMP/RT_GAMEPUMP_VBLANK) never engage on abn (g_game_tick_modectx=0) — they were the
wrong altitude; evt34 was the right one all along.

**THE MEASUREMENT (weld_probe.sh round 3, nav-driven, both cases green end-to-end):**
- [evt34] SET stamped every 600th (wall-ms; out_reco/rt.cpp is the /FORCE:MULTIPLE link winner
  — the out_reco_abn twin carries the same stamp; round-2 lesson: patching only the abn copy
  is INERT in the combined build).
- FREE: 600 grants / 10,010ms x5 consecutive windows = 16.68ms/grant = **59.94Hz exact**.
- RT_PRESENT_THROTTLE_MS=50 (new DIAGNOSTIC lever, vk_render.cpp nvk_frame_submit entry):
  600 grants / ~38.4s x5 = 64ms/grant = **15.6/s at ~15.6 presents/s. WELDED 1:1.**
⇒ The panel's severity thesis is CONFIRMED on the abn path with its real clock: on Deck-class
hardware 360-mode gameplay runs slow by construction. FNF-5 is correctness, not perf.

**NAV LIBRARY hardened en route (round-2 failures were both library robustness):** card-decide
now RETRIES on dwell-refusal (an unfocused/compositor-throttled window stretches the 180-FRAME
gate in wall time — a 3.6s dwell that passed 5x got refused on run 6), and swap evidence
accepts XexLoadImage (the DONE marker lags under throttle). Round 3: 10/10 assertions green
across free AND throttled profiles. NAV_CARD_DWELL/NAV_LAND_SETTLE/NAV_SWAP_WAIT env-tunable.

⏭ NEXT LEG — THE DECOUPLING DESIGN: rehost the 0x50000034 grant onto the 59.94Hz vblank
thread, REPLACING the present-path grant (not adding — the 07-17 vbpump_owns pattern is the
shape). Prereqs to read first: (a) find the present-path call site that reaches sub_8808FA68
(who calls it, from where in the shell present chain); (b) the guest's own catch-up/skip
semantics when a grant is missed (does the setter clamp? does the waiter accumulate?) — the
grant must not double-fire when render is FASTER than 60. Accept via weld_probe: throttled
grants must hold ~59.94 while presents crawl; then full gate stack + user eyes on pacing feel.

## ★★★★★ 08-11 LATE-NIGHT — **TICK/PRESENT LANE OPENED, and the first measurement REFRAMES IT:
## the msg-5 pump machinery is INERT on the 360/abn path.**

**MEASURED (tickrate_probe.sh, nav-library-driven, 60s in-stage windows, both regimes):**
`g_game_tick_modectx=0x00000000` and ZERO [gamepump]/[vbpump] lines under BOTH RT_GAMEPUMP=1
and RT_GAMEPUMP_VBLANK=1 on 360 NORMAL PLAY gameplay. ⇒ The whole msg-5 pump family
(sub_821C8DA8 / g_game_tick_modectx discovery, rt.cpp GATE-3 + the 07-17 vblank decoupling
lever) is **reco_normal-era and never engages for reco_abnormal** — the panel's welded-tick
model can't be evaluated (or fixed) through it on this path. The abn logic clock is
UNATTRIBUTED. Coarse candidates from the same logs: [pump] sub_88090480 (game service cb)
~370/s = multi-per-frame service pump, NOT the tick; [evt34] sets ~47/s session-average =
needs a WINDOWED in-stage rate before it means anything.

⏭ NEXT LEG (fresh session): decomp-attribute the abn per-frame grant — the abn sibling of
reco_normal's sub_8808FB90 wait on event 0x885C6528 (find who waits/sets the per-frame event
in the abn module; reference/ghidra decomp + evt34 lr=0x8808334C is a starting thread) → build
a windowed ticks-vs-wall-clock instrument on THAT → then design the decoupling. Do the same
attribution for the ARCADE path while at it (RT_GAMEPUMP may be engaging there — unverified
since the nvk era).

**NAV LIBRARY (scripts/futari_nav.sh, commit 3fc4c10) field report:** entry path validated
8/8 green on THREE more full runs tonight (validation + tickrate A + tickrate B), including
the active landing probe choosing correctly every time. ⚠ KNOWN GAP: the game-over return
flow after a NORMAL-PLAY-entered stage does NOT reach the hub via the mapped title flow
(engst parks at D70/vt 0x8204FDB8 through 4 probe rounds) — needs a screenshot-mapping
session; documented in the library header.

## ★★★★★★★★ 08-11 NIGHT — **THE HOT-SWAP STALENESS FAMILY IS CLOSED: EPOCH INVALIDATOR LANDED,
## GATED, AND VISUALLY VERIFIED AT THE USER-REPRO CONDITION. Plus: the menu drivers are FIXED
## (docs/NAV_MAP.md) after a full screenshot-per-press mapping session.**

**THE FIX (vk_render.cpp getTexIndexReal): RT_EPOCHINVAL, default ON.** The 08-07 IDLOG
detector's verdict now ACTS: an allocation-epoch mismatch at a cache hit (guest memory freed
since our decode — the NECESSARY event for identity change) forces a re-decode into the SAME
bindless slot (reval3's reuse path). Replaces reval-hash coverage for this class outright (the
reval3 hash samples 64 dwords at the wrong byte size for DXT — the 08-11 HUD corruption slid
through it). Epoch now RECORDED at every upload (was RVK_IDLOG-gated). RT_EPOCHINVAL=0 reverts
to detector-only. Convergent design note: daytona's plume renderer stamps resolve generations
per dest and compares at bind (g_resolve_gen) — same shape from the write side.

**GATES, all green:**
- swapbounce (ported: _local/_tmpscripts/swapbounce_0811.sh): P1-P7 PASS at 6 swaps, high-water
  496MB unchanged, [epochinval]=31 bounded, [idcol]=43.
- USER-REPRO drive (screenshot-per-press, 3 cycles: 360 NORMAL PLAY gameplay → arcade NORMAL
  PLAY gameplay → 360 NORMAL PLAY gameplay, 4 modswaps): [epochinval] fired 40x (incl. the
  256x256 fmt3 HUD-atlas class of the sighting), 0 quadcensus idx collisions across 8 armed
  frames, P7 0 crossings, 0 loud failures — and the top-right corner (the user's corruption
  spot, right of the 2P indicator) VISUALLY CLEAN in post-swap 360 gameplay, checked by
  screenshot at the exact repro condition. Char/shot select ALSO eyeballed clean both modules
  (the alias-fix acceptance, previously owed to user eyes, is now DONE).

**MENU DRIVERS FIXED (user ruling: "check via screenshots at every button press ... get menus
and tools right"):** full verified screen graph + per-screen log markers banked in
docs/NAV_MAP.md. Headline traps that wasted prior sessions: the NORMAL PLAY submenu's 2P SIDE
START row (the blind driver's "2P mode!!!" incident), the card panel resetting to ARCADE every
open, 360 cold-boot landing directly at Mode Select while re-entry shows a title first, RETURN
TO TOP MENU not swapping modules (lazy swap on next decide), and [intap]/[scenelog] being
frozen under the abn module. Drives must assert position from [mcur]/[p0build]/[decide]/
[mstate]/[modswap] before every press.

⏭ NEXT LANE: tick/present atomic frame boundary (panel ship-gate item (a)). Also owed: a
sourceable driver library implementing NAV_MAP.md assertions (the map is banked; the helper
script is mechanical), and the swapbounce_0811 gate re-run periodically now that epochinval is
default-on.

## ★★★★★★★ 08-11 RESUME LEG — **PROJECT RESUMED (user ruling); MODEL RE-REAFFIRMED =
## UNLEASHEDRECOMP (rexglue-free native PC Futari). CONSUME-SIDE LANE OPENED. And the 08-07
## "scripted card-decide refusal" is ROOT-CAUSED: it was OUR OWN modestub L2 VETO — the drive
## ran the WRONG EXE.**

**DIRECTION (Fable verdict, user-accepted):** byte-EXACT matching (matchlab gate grind /
register-allocation hunt) overshoots the UnleashedRecomp model — demoted to a VERIFICATION TOOL
for hand-written native replacements (rt_phys etc.). Ship-shaped order: (1) consume-side
texid→page defect, (2) tick/present frame boundary, (3) hot-swap family. `gate.py` stays a
progress metric, not a ship metric (08-07 ruling reconfirmed).

**NEW INSTRUMENT — `RVK_QUADCENSUS` (vk_render.cpp, nvk draw loop; in BOTH builds).** One-shot
per-quad census of an armed frame: every stream event in order (SETRT/RESOLVE/CLEAR + draws),
and per draw the bound texture base, served idx, `<RESOLVE` flag, and the XY/UV bbox decoded
from the draw's OWN vertex bytes (x,y at +0/+4; u,v at +12/+16 when stride >= 20). Armed by
`touch /tmp/rvk_quad_now` (same discipline as rvk_dump_now), `RVK_QUADCENSUS=1` enables,
`RVK_QUADCENSUS_K` frames (default 2). Purpose: at the corrupted select screen, separate
(a) paste-back strips drawn at WRONG POSITIONS (guest/placement side) from (b) plate-base draws
SERVED a resolve entry (host/serving side). One armed frame decides arm (c)'s split.

**THE 08-07 "SECOND DEFECT" IS NOT AN INPUT DEFECT — MISATTRIBUTION CORRECTED.** Measured
2026-08-11, three probe runs (`_local/_tmpscripts/card360_probe.sh`, eyes-free, log-verdict):
- The FIFO input layer is EXONERATED: all presses generate + deliver keystrokes ([xinput]
  press/delivered pairs), and the guest consumes them (menu transitions follow each press).
- The bounce-to-TOP-MENU on the 360-card decide is **[modestub] L2 VETO** (merged_shell.cpp
  :4011, beta1 07-31, working as designed): `futari_merged.exe` hosts modeIdx mask **0x01**
  (reco_normal only) — the 360 card folds to modeIdx=1, the stub takes the guest's own
  out-of-range branch back to 1D50 (ACTIVE). Log line: `[modestub] L2 VETO#1 7CC0 ...
  modeIdx=1; this build hosts mask 0x01 ... no phase 6, no module load`.
- The user's real-pad successes ran `futari_combined.exe` (EYEBALL launcher) which hosts mask
  **0x03** — same drive on combined shows NO veto. ⇒ **360-path drives MUST use
  build/futari_combined.exe.** Never diff behavior across the two exes without checking the
  hosted-mode mask first.
- ⚠ TWO MORE DRIVE LANDMINES found en route: (i) fixed sleeps misalign on combined (slower DLL
  boot: LEFT landed in load-wait, "decide" A merely opened the panel) — probe now polls the
  guest's own [mstate]/[engst] markers before each press; (ii) `mark`-style `>>` appends into a
  log the exe holds open as stderr get OVERWRITTEN by the exe's tracked offset — probe marks
  must go to stdout, not the log.
- DECOMP BANKED on the way: the card panel (state 0x82061D70) has a **3.0s dwell gate** —
  FUN_8218bad8 (launcher), FUN_821bd1b8 (generic gate), FUN_82186738 all refuse the panel
  advance until obj+0x100 (frames-in-state) >= 0xB4=180; other callers use 0x3C/0x2D/0.
  Scripted decides must dwell >= 3s on the panel.

✅ **SCRIPTED 360 LAUNCH CONFIRMED (same day, state-driven probe on combined):** decide passes
the dwell gate (`[itemsm] 0x82065A78 -> 0x82065A88`) and the module loads —
`[xex] XexLoadImage("game:\media\Module\reco_abnormal.xex") -> resident hmodule=0x88000000`,
entry ord=1 = 0x8824E6A0. **The "Xbox 360" card = reco_abnormal.xex.** Post-load the shell
parks ([modegate] gate=CLOSED mode78=0) until the in-shell nav continues — that is the normal
summon → NORMAL PLAY → join flow, not a wedge.
**EXTENDED DRIVE RESULT (same day, run 4): CENSUS MECHANISM PROVEN, TWO GAPS FOUND.**
`[quadcensus]` armed at f7568 and captured 122 draws in stream order with full identity
(SETRT/RESOLVE segmentation, tex base, served idx, `<RESOLVE` flag, blend). Gaps:
- ⚠ **GEOMETRY HALF NEEDS THE REAL VERTEX LAYOUTS.** The +0/+4 float32 read is right for the
  vs17 display quad (xy 0..1280x720 ✓) and the vs47 restore quad, but every vs45/ps50 st=16
  draw reads xy={0,0..0,0} — that class does NOT carry float32 positions at +0 (s16/packed
  suspected; float-reading s16 pairs prints ~0). Mirror the EXECUTOR'S own per-class vertex
  decode instead of assuming a layout. (d4's uv=±1e9 garbage says the st=28 uv offsets are
  wrong for that class too.)
- ⚠ **POST-LOAD NAV IS BLIND ON THE ABN MODULE:** [intap]/[scenelog] read reco_NORMAL globals
  (merged_game.cpp) — under reco_abnormal they print frozen constants (out=0 forever), so the
  "wait for out=5" gate can never fire and the blind press sequence bounced back to the TOP
  MENU (mode78 2→0 teardown ~#5852, final A re-opened the card panel). The census therefore
  captured a SHELL screen, not char select. Need abn-aware markers (mstate/engst are shell-side
  and fine; an abn [intap] twin is the clean fix).
**RUN 5 (executor-true census, commit after 585f4a3): CHAR SELECT REACHED SCRIPTED AND
CENSUSED — IT IS CLEAN, AND THE PAGE BAKE IS NOT ACTIVE THERE.** Census geometry now goes
through the executor's own decodeVert (st16 int32 {x,y,u,v} sniff incl.) — bboxes/UVs read
true (fixed the all-zero xy of the first cut: float-reading int32 records). Six armed frames
at char select (3 arms x K=2): the screen is identifiable from the draw list alone — 32px
tiled-atlas backdrop wall (0xD440000/0xD4C0000/0xD540000, marching UVs), three card sprites
with layered echoes (0x15EC8000), additive selection flare (0x16528000) — all positions/UVs
coherent, nothing at card positions samples a page, and **[reslog] = 0 for the whole session:
the 512x512 page bake never ran up to char select on the abn path.** ⇒ the paged compose (and
the 08-07 corruption family — stone plates) lives DEEPER: shot select. Full census banked at
/c/tmp/card360/census.txt.
## ★★★★★★★★ 08-11 — **THE CONSUME-SIDE DEFECT IS ROOT-CAUSED, FIXED, AND GATED GREEN — THE
## RVK_RESALIAS 512x512 PROXIMITY HIJACK.** One census frame closed the 5-week select-corruption
## family.

**RUN 6 (shot select, page engine live): THE SMOKING GUN.** f6492: six pages baked per frame
(both documented shapes, restore→overdraw→resolve cycle exactly per NOTES_select_compose.md),
consumer strips COHERENT (x-contiguous, UV-continuous across page seams, two rows = the two
page triplets) — and exactly ONE idx collision in the whole frame: **plate atlas 0x170BC000
(no resolve entry, 9 draws incl. the n=222/156 plate-grid batches) served idx 241 = the page
0x1717C000's resolve image.** Harness's own log agrees:
`[rvk][resalias] base=0x170BC000 512x512 -> resolve sibling (dist=0xC0000 idx=241)`.
⇒ "Blocks of legitimate backdrop-page art where the plates belong, one block = one quad" IS
the RVK_RESALIAS proximity heuristic (closest same-dim resolve entry within ±0x100000)
capturing a genuine guest-streamed atlas that shares the page dims. **This also explains the
allocation-layout dependence** that defeated every quarMs experiment: the hijack needs the
atlas to land within 0x100000 of a page dest — pure allocator accident, run to run.

**FIX (vk_render.cpp getTexIndexReal): 512x512 EXCLUDED from sibling aliasing.** Pages are
always sampled at their exact dest base (identity dest==fetch, bake proven live), so a 512
proximity alias can only ever hijack innocent plate art; the LEG-43 rotation the alias exists
for (pane/downsample pools, 640x480 etc.) keeps aliasing. `RVK_RESALIAS512=1` restores old
behaviour for A/B. **GATE (run 7, fixed build): [resalias] fires ZERO times; idx collisions 0
in all six shot-select frames; six pages still baked + served at exact bases with unique idx;
strips still coherent.** NOTES_select_compose.md's "retire RESALIAS for the pages" TODO is
hereby DONE (measured, not guessed).

⚠ RESIDUAL/GATE-DEBT: (i) VISUAL half needs USER EYES — plates should now show STONE-PLATE art
at char/shot select (drive: combined exe, 360 card, default env), plus the standing 08-07
acceptance list (ranking box, mode select, Ver1.5 NORMAL PLAY, menu chrome/wallpaper/M2 seams
counter-risk); (ii) blast radius = any 512x512 that legitimately relied on proximity aliasing
— none known (the 08-03 "sampled page bases had everRendered=false" era predates the live
bake), but attract/field screens are the place to look if something regresses; (iii) probe
landmine for the ledger: **Bash-tool cwd resets between calls — a bare `bash build_win.sh`
silently builds NOTHING from the wrong cwd; cd every command** (re-learned today, cost one
stale-binary probe run, caught by the build log not the probe).

**08-11 LATE — USER EYES ON THE ALIAS FIX: SELECT SCREENS CLEAN ON FIRST LOAD ✅. NEW SIGHTING
banked: post-swap IN-GAME corruption (arcade→360 re-entry), small rectangular band top-right of
the playfield next to the 2P indicator — coherent FOREIGN ART (blue swoosh fragment), not
noise, "one block = one quad" shape. Screenshot taken live (paused session, eyeball log
eyeball_20260811_222320.log). ATTRIBUTION SO FAR: [resalias] fired ZERO times in that session ⇒
NOT the alias heuristic (fix holds); reco_abnormal.xex loaded 3x (mode swaps); [texreval3]
re-decoded 3 stale atlases but missed this one ⇒ HOT-SWAP STALENESS family (guest re-streams
atlases post-swap; cache serves pre-swap decode where the reval signatures don't cover). This
is the known Beta-2-opener class, now with an in-game HUD instance and a near-scripted repro
(probe reaches 360 gameplay; add mode-swap loop + RVK_IDLOG + RVK_QUADCENSUS at the corrupted
frame — census must be enabled in the drive env, the eyeball env doesn't set it).**
⏭ NEXT LANE: hot-swap staleness (repro scripted → IDLOG/census attribution → fix), then
tick/present atomic frame boundary. Byte-matching stays demoted to verification-tool status.

## ★★★★★★★ 08-07 ATTRIBUTION LEG — **THE IDENTITY-COLLISION SUSPECT IS REFUTED AT THE CORRUPTED
## SCREEN, AND THE DEFECT IS ON THE CONSUME SIDE.** First eyes-free measurement of this class.

**NEW INSTRUMENT — `RVK_IDLOG=1`, an identity-collision detector that needs no eyes.**
`out_reco/harness.cpp` keeps an ALLOCATION EPOCH table (16KB buckets, matching the allocator
granule), bumped on every FREE — a free is the necessary event for any address reuse, so bumping
only there catches every collision at one write per free. `render/vk_render.cpp` records the epoch
at texture UPLOAD (`g_texEpoch`, parallel to `g.rTexIndex` so the cache struct is untouched) and
re-checks it at every sample; a change means the backing guest memory was freed between decode and
sample, i.e. the host cache is serving bytes whose identity is no longer valid. Built because EVERY
prior verdict on this defect was a human looking at a screen, on a defect whose severity moves with
allocation layout — which is how the 08-04 "screen-drive verified clean" survived four days
without being true (08-07: it does not reproduce, and 250 is WORSE than 0).

**MEASURED, user-driven 360 path, through attract → char select → shot select (the corrupted
screen), 9901 frames:**
- ✅ Detector is LIVE and provably fires: **2 collisions** — `0x59E0000` 2048x2048 fmt=6, and
  `0x6960000` 512x512 fmt=3. (Arcade path, separate run: 1, at `0x59A0000`.)
- ⛔ **ZERO collisions at char select or shot select.** The count is 2 before the select screens
  and 2 after. ⇒ **Fable's lead suspect — host texture identity keyed on guest base colliding
  under address reuse — IS NOT THE CAUSE of the select corruption.** Refuted by instrument, not
  by argument.

**THE OTHER TWO ARMS OF THE 08-04 OPEN QUESTION, both settled in the same drive:**
- ⛔ **"bake never fires" REFUTED** — 46,000+ `[reslog]` 512x512 resolves; six page destinations
  dominate at ~7291 resolves EACH (`0x15DA4000 0x166D0000 0x16FAC000 0x1702C000 0x171AC000
  0x1722C000`) = the six select-screen backdrop pages named in Page_EnsureTexture.
- ✅ **RESOLVE GEOMETRY IS CORRECT** — only **7 distinct shapes** in the whole session, and they
  are the documented ones: `{0,0,512,512}` and `{512,0,640,512}` clamp-640, all `dp={0,0}`,
  matching the 08-03 shape census exactly. Nothing anomalous in rect or destPoint.
- Note the asymmetry: each page base appears ~7291x as `dst=` but exactly ONCE as `tex=`. The
  pages are resolve-backed, so draws sample the RENDERED image, not guest RAM — which is itself
  why a guest-RAM staleness fix (copy-at-record) could never have helped them.

⇒ **WHERE THE DEFECT MUST BE: THE CONSUME SIDE — WHICH PAGE EACH QUAD SAMPLES.** The corruption is
rectangular BLOCKS of *legitimate* backdrop-page art sitting where the plates belong. The content
is right and the geometry is right; the PLACEMENT/selection is wrong, and one block = one quad.
NOTES_select_compose.md already names the mechanism: `FUN_8808E298` computes the page phase FROM
THE STRIP QUAD'S TEXID. So the next instrument is the per-quad texid→page selection at the select
screen, compared against the page each quad should sample. That is arm (c), paste-back/consumer.

⚠ SECOND DEFECT FOUND, unrelated and blocking automation: **the 360 card decide is REFUSED on the
scripted-input path.** `_tmpscripts/charsel_dwell_360.sh` (new; the arcade drive plus one LEFT —
NAV TRUTH from the user: the 360 version needs a LEFT on the card panel after Ver1.5, else the
drive silently measures the ARCADE path, which renders FINE) reaches the card panel and flips the
card to "Xbox 360" — screenshot-verified — and then a plain A bounces back to the TOP MENU instead
of launching. No B is ever sent (verified: zero `press 2000` in either drive; FIFO mapping
confirmed against shell/gen/stubs.cpp:765, A=0x1000 B=0x2000 LEFT=0x4). Works fine on
`RT_PAD_HOST=1` with a real controller. ⇒ Until this is fixed the select corruption CANNOT be
gated automatically and every verdict on it stays dependent on the user being at the keyboard.

## ★★★★★★ 08-07 — **COPY-AT-RECORD LANDED AND GATED GREEN (containment half). The quarantine
## shim is no longer needed for P7; the VISUAL half still needs user eyes.**

**The change is a PREFETCH, not an arena** — `nvk_tex_prefetch()` (render/vk_render.cpp, above
`nvk_frame_submit`) called from `nvkReadDrawState()` (decomp/shell/nvk.cpp) once the draw's `tf[]`
is read. It calls the executor's OWN `getTexIndexReal()` at record time, so the texture is decoded
while the guest bytes are still live instead of at Present. `RT_NVKPREFETCH=0` reverts.

Why that shape works, and it is worth keeping because it is not obvious:
- The decode+upload path (`submit(rupl)`) is fully self-contained — fills `g.staging`, records a
  ONE_TIME_SUBMIT buffer on `g.cmd`, submits, waits on `g.fence`. **No render pass, no frame
  context.**
- `nvk_frame_submit` is called **synchronously** from the Present hook on the guest render thread
  (nvk has no async decoupling — RVK_DECOUPLE is inert under RT_NVK=2), so during the guest's
  frame `g.cmd`/`g.staging` are idle and recorder and executor never race. Same thread, no lock
  inversion (prefetch takes `g_mtx`; it is never called from inside submit).
- ⇒ no new memory, no duplicated decode logic, **no changes to any untile loop**. The bytes are
  simply read earlier.
- Cost is bounded by cache MISSES, not draws: `getTexIndexReal` returns on a hit without touching
  guest RAM, so steady state is one map lookup per draw. Early-outs: device not up (leave it to
  submit — prefetch optimises WHEN, never WHETHER), resolve-backed base, already resident.

**GATE: swapbounce PASS, all 7, at the DEFAULT quarMs=0 — no quarantine.**
P1 6 swaps · P2 6/6 · P3 renderer alive after last swap · P4 19/19 threads · P5 0 loud · P6 0
garbage-SETRT · **P7 0 crossings, high-water 496MB** (identical to the pre-change quarMs=0
baseline: 0x1F010000, pooled 277/329MB). Frame count `f13801` in both runs ⇒ no measurable perf
cost from the record-time uploads. `[nvkprefetch]` fires (log is rate-limited 1-in-500).

⚠⚠ **WHAT IS NOT VERIFIED, AND IT IS THE HALF THAT MOTIVATED THE CHANGE.** The gate covers
containment and swap stability only. Nobody has yet looked at the char/shot select plates. The
acceptance drive is unchanged and needs USER EYES: char select → shot select stone plates +
No-entry watermarks → ranking box → mode select → through Ver1.5 NORMAL PLAY, with NO quarantine.

⚠ **AND THE COUNTER-RISK, WHICH IS REAL AND MUST BE EYEBALLED TOO.** Decoding EARLIER can catch a
texture the guest is still streaming — the opposite race from the one being fixed, and the exact
class the RVK_TEXREVAL/REVAL2/REVAL3 family exists for ("decoded while empty"). If menu chrome,
the wallpaper, or the M2 seams regress, that is this change, and `RT_NVKPREFETCH=0` isolates it in
one run. The prefetch deliberately does NOT force-refresh or bypass any reval lever.

## ★★★★★★ 08-07 RUNTIME LANE — **quarMs=250 IS GATED AND IT FAILS P7. THE SHORTCUT IS DEAD;
## THE TRUE FIX IS THE ONLY FIX.** The 08-04 tension is resolved by measurement, not judgement.

Ran `_tmpscripts/swapbounce_gate.sh` with `RT_FREEPOOL_QUAR_MS=250` (no rebuild needed — the
lever is env-read; exe 08-04 18:20 is current against harness.cpp 18:19). Prior quarMs=0 log
banked first at `/c/tmp/swapbounce/boot_PRE0807_quar0.log`.

**P1-P6 GREEN, P7 FAILS.** 6 swaps DONE, destroyed/slotreset 6/6, renderer alive after the last
swap, threads 19/19, zero loud failures, zero garbage-SETRT, process alive at kill. But:

| | pooled blocks | pooled MB | live MB | high-water | P7 breaches |
|---|---|---|---|---|---|
| quarMs=0 (08-04, PASS) | 277 | 328 | 161 | **496MB** | 0 |
| quarMs=250 (08-07, FAIL) | 579 | **101** | 399 | **513MB** | saturated (61 = the 60+1 cap) |

The breach line names the mechanism outright: `[pool] LINE-BREACH asz=0.52MB maxpooled=0.50MB
pooled=604 align=0x4000 (no fit; bumping past 512MB)` — 604 free blocks and the largest is half a
meg. **Quarantine starves the pool of large blocks, so the frontier climbs past 0x20000000.**

★ **AND THE CODE ALREADY PREDICTED IT.** The comment above the lever (harness.cpp:199, written in
the 08-04 third P7 forensics pass) says: *"even 250ms rejected the streamer's ~16ms hot rotation
below the line, so every cycle bumped fresh space — THE climb engine."* The 250ms cure was found
by eyes on a screen drive; the P7 cost was already known and had simply never been re-measured
together. It has now been, on the same gate, and the two requirements are mutually exclusive at
this lever.

⇒ **STEP (2) OF THE 08-04 PLAN IS CANCELLED — do not default 250, and do not sweep for a smaller
value hoping to thread the gap.** The streamer's rotation is ~16ms; any quarantine long enough to
cover the walker's ~50ms late read necessarily rejects that rotation, which IS the climb. The two
numbers are on the wrong sides of each other by construction. (Also: the launcher was never
touched — the user declined that edit on 08-04 and it stays declined.)

⏭ **THE TRUE FIX, NOW THE ONLY ROUTE: RENDERER-SIDE COPY-AT-RECORD.** Scoped this leg:
- The **vertex** path already IS copy-at-record — `decomp/shell/nvk.cpp` "deferred-copy
  discipline" copies a draw's scratch bytes at the NEXT draw-core call into `g_vtxBlob` (2MB),
  precisely because reading at Present loses early draws to arena wrap. That half is done.
- The **texture** path is the late reader. `render/vk_render.cpp` `getTexture()` caches by guest
  base plus a content signature and uploads **at execute time**, so a plate whose guest bytes are
  recycled between record and upload decodes garbage — the char/shot-select first-entry corruption.
- The change: at RECORD time (guest render thread), for any draw whose texture is not already
  cached-and-valid, memcpy the raw guest bytes into a per-frame staging arena, and have the
  executor upload from the copy. Cost is bounded by cache misses, not by draws — the steady state
  is already one-time upload. Note `g_tripSnap` / `RvkAtlasSnap` (vk_render.cpp:661) already keeps
  upload-time raw-byte snapshots for the drawtrip census, so the copy shape and its addressing are
  proven; this promotes that from diagnostic to the real path.
- ACCEPTANCE: swapbounce P1-P7 green at quarMs=0 default, plus the screen drive that 250 was
  curing (char select → shot select plates + No-entry watermarks → ranking box → mode select →
  Ver1.5 NORMAL PLAY) clean with NO quarantine. User eyes are the gate on the visual half.

## ★★★★★ 08-07 — **THE HEADER UNLOCK IS REAL, AND IT NEEDS `_XBOX`.** Clone census + the queued
`Render_SelectBlend` real-header experiment, in one sitting. Selftest ALL PASS, board green
(220 targets, zero DIFF), ship gate unchanged at **588/960, 1/9 exact**.

★★★ **`_XBOX` MUST BE DEFINED OR THE REAL XDK HEADERS ARE THE WRONG COMPILER.** `d3d9.h` gates
`D3DISINTCONST` on it and `cl.exe` does not predefine it — the XDK build system does. Without it
the macro is the literal `FALSE` (the x86 arm), `D3DDevice_SetPixelShaderConstantF` never folds to
the F1 inline and emits `bl SetPixelShaderConstantFN`, and `D3DRESTRICT` expands to nothing.
Measured on a two-line probe: **21 instructions and a call without it, 15 and a leaf with it.**
This is a landmine, not a footnote: 9644f68 landed the header tree, and the very next session
would have concluded "the real headers do not help" while measuring a compiler the title never
used. Recorded in matchlab/README.md.

★★★ **`Render_SelectBlend` MOVES OUT OF THE STATEMENT-STRUCTURE CLASS.** New sibling
`src/game_88070000_Render_SelectBlend_hdr.cpp` builds the same body against the real `<d3d9.h>`.
It scores **LOWER** on the tracked metric — 37/171 vs 56/171 — because it is 3 instructions short
and everything past the custom-blend arms misaligns. But over the **first 80 instructions the
structural mismatches fall 12 → 2**, and what remains there is register numbering. The canonical
file stays canonical (56 is the honest number and the gate must not over-report); the variant is
where the next leg starts. Flag matrix flat (-O2 -Oc == -Ox -Oc == -Ou == -Ot; -Os far worse), and
three staging-array lifetime shapes are byte-identical to it — the array-lifetime lever is dead.
★ Free finding from the header: **D3DBLENDSTATE is a bitfield struct passed BY VALUE**, MSVC lays
bitfields out from the LSB even big-endian, and its widths (SrcBlend:5 / BlendOp:3 / DestBlend:8 /
SrcBlendAlpha:5 / BlendOpAlpha:3 / DestBlendAlpha:8) ARE the guest's `&0x1F` and `&0xFF` masks.
⏭ Remaining, sharply scoped in the variant's header: (1) TAIL MERGING — the guest keeps THREE
pending-tag RMWs and we keep ONE; the guest's custom arm A survives merging only because its
leftover staging store is scheduled BETWEEN the `or` and the `std`, while its arm B and the
default-else arm DO merge. The target is the guest's asymmetric merge, not "no merging".
(2) register rank, two transpositions — ⚠ and it does NOT fall out of ALLOCATOR.md Step 1 as
written: g_batch has 11 machine references to g_render's 9, yet g_render takes the HIGHER
register. Open question, verify by rebuild.

★★ **CLONE CENSUS BANKED — `matchlab/CLONE_BACKLOG.md`.** 124 families, **13,971 instructions in
families with no exact member**. ⚠ "UNCLAIMED" MEANS "NO EXACT MEMBER", NOT "UNSTARTED": the two
biggest shell families are both work in progress — 113x8 = `Driver_Init` at 66/112 (five shapes
ruled out, allocator-blocked) and 22x8 = `Driver_SendStageRecord` at 16/22 (the deliberately
REFUSED `volatile` win). ⚠ The memory note "the GAME module has no clone families" is WRONG —
game holds nearly all the unstarted value. Best ratio on the board is **49 x 5 = 245 at
game 0x880BD4B8**; the biggest single body is 193 x 3 = 579 at game 0x881EEEC0.

## ★★★★★★★ 08-05 NIGHT — **THE SHIP GATE: 422/960 → 596/960, and BACKLOG ITEM 0's ROOT IS EXACT.**

★★★★ **`Compose_Root` 0x821CDBE8 IS ASM-EXACT, 81/81, WRITTEN FROM SCRATCH.** This is the
compositor family root named by BACKLOG "NOW" item 0 — the flicker lane, the thing the
"nothing ships until menus/shell is done" ruling rests on. It had NO source; first compiling
attempt scored 5/81. **It is a C++ CONSTRUCTOR** (`??0CRscBankMgr@@QAA@XZ`), which is why it
needed real class shape rather than a free function. Independently re-verified before promotion:
all 12 reloc-masked fields resolve to the addresses SPEC_shell_compose_1to1.md predicts — two
sub-node vtables, its own vtable, `operator new`, the CRscIndicator ctor, the app-root holder and
its first state fn. `Compose_Veil` 0x82182A68 also went from nothing to **56/89**.

★★★ **NEW ALLOCATOR RULE (ALLOCATOR.md Step 3b): REFERENCES INSIDE A LOOP-BEARING
`static __forceinline` INLINEE ARE RANK-DISCOUNTED.** Found on Page_Bake, **144 → 161/216**, its
largest single jump. Moving the paste loop bodily into such a helper changes **no instruction and
no reference count** yet rewrites the register map — perennial zero → r30 (the image's rank 2),
bakeX → r29, pool base down to r28. Constraints, all measured: the inlinee **must contain a loop**
(straight-line gives NO discount); **`__forceinline` is mandatory** (this cl refuses to auto-inline
a looping callee — 166 insn if you let it decide); nesting does not stack, though two DISTINCT
nested guards compound. **This is the second confirmed source-level lever on rank, and unlike
block frequency it is FREE.** ⏭ It is the obvious thing to try on every other stuck loop-bearing
function.

★ `Page_EnsureTexture` **28 → 35/50, and better on BOTH metrics (structural 9 → 3)** — verified
against the previous body rather than taken on trust. A pointer local plus a deliberate
REDEFINITION gives it a two-def web that blocks the load-CSE folding the reload.

⚖ **A REFUSED WIN, ON PURPOSE.** `Driver_SendStageRecord` reaches **17/22** by reading its two
struct fields through `*(volatile u32*)` casts — semantics identical, rest of the TU still exact,
and it is worth 198 instructions across 8 clones. **REFUSED.** A `volatile` cast is a scheduling
device the original source would not have contained. **A body that scores higher by telling the
compiler something the original never said is not a better decompilation, it is a better-scoring
wrong answer.** 16/22 is the volatile-free ceiling and the file stands on it.

⚠⚠ **AND A CORRECTION TO THE 08-05 EVENING ENTRY: THE BOARD WAS DOUBLE-COUNTING.** Seven exact
duplicate rows sat in functions.json (Deferred_Node, Colour_Fold, Walk_Draw, Walk_Mid, Walk_Tick,
Menu_ChildResult, Logo_Exit). Reported 223 targets / 5074 insn / 0.5811%; **actually 216 / 4856 /
0.5562%**. Deduplicated, and `ppcmatch` now HARD-ERRORS on a repeated (module, addr) — positive-
controlled by re-adding one. **A board that over-reports is worse than a smaller one that is true.**

★ **NEW TOOLING: `gate.py`** prints the ship-gate scoreboard, because the board's whole-image %
is the wrong denominator for "are we close to shipping". THREE denominators, measured: whole image
873,129 insn (misleading — 36% of matched instructions are compiler boilerplate); registry ~26,000
insn (247 functions, ~2% covered); **SHIP GATE 960 insn — the number to track.** Also: 13 registry
rows were stale (matchlab already proved them exact while they sat at NAMED) and now carry
`asm_exact`/`asm_sha1`/`matchlab` cross-references, statuses untouched per the behavioural ruling.


## ★★★★★★★ 08-05 NIGHT — **CLONE MINING: BOARD 97 → 223 TARGETS, 0.2757% → 0.5811%.**
## The board more than DOUBLED in one leg, and none of it came from grinding a parked function.

★★★ **THE LEVER WAS A TOOL, NOT A FUNCTION.** `matchlab/clones.py` finds byte-identical clone
families and ranks them. Its first version only matched EXACT bytes — which quietly threw away the
common case, because two copies of one function at different addresses calling the SAME callee have
DIFFERENT `bl` displacements. **Normalising outbound call displacements (internal branches kept —
masking those would fuse genuinely different functions) is what turned a handful of families into
all of them.** This is sound, not a fudge: our object carries a relocation in that field and
`equal_modulo_relocs` already compares it masked, so one source legitimately claims N addresses.
**Every promotion below was audited by reading the RESOLVED reloc targets, not assumed.**

**+826 instructions from families whose source we ALREADY had, or wrote in minutes:**
 * `Dtor_Deleting` — MSVC's `??_G` scalar deleting destructor. **20 insn × 69 copies = 1380**, the
   largest family in either image. Two modelling devices, both measured: the destructor must be
   DEFINED in the TU (declaring it emits no vtable, hence no `??_G`), and then marked
   `__declspec(noinline)` (else MSVC inlines the trivial body, drops the call, and the thunk
   shrinks to 18 insn / 2-20).
 * ★★ **THE SAME FILE AT `-O1` CLAIMED 20 MORE (19 insn × 20 = 380).** They are one instruction
   shorter because the flags test fuses into the record form (`clrlwi.` + `beq` on cr0 instead of
   `clrlwi` + `cmplwi cr6` + `beq cr6`). Independent corroboration that they really are library
   code: they call a DIFFERENT `operator delete` (0x82114628 vs the -O2 family's 0x8207A630). The
   settled TITLE `-O2 -Oc` / LIBRARY `-O1` split, observed rather than assumed. ⇒ **WHEN A FAMILY
   IS A FEW INSTRUCTIONS SHORT OF A SHAPE YOU ALREADY MATCH, TRY THE OTHER FLAG SET FIRST.**
 * `Logo_Exit` ×10 unclaimed (+200) and `Driver_SendRegionConfig` ×7 unclaimed (+161) — pure free
   growth off sources already on the board, invisible until call normalisation.
 * `Job_Poll` 0x82191D00 ×4 (+152), `Driver_SendConfigBlock` 0x821C2C58 ×8 (+176),
   `Driver_Start` 0x821C3280 ×7 (+210) — **all three EXACT on the first attempt**, every reloc
   resolving to the predicted callee.

★ **`Menu_Cancel` 0x821B9E58 EXACT — A VTABLE CALL MUST BE A REAL C++ VIRTUAL CALL.** It sat at
5/8 with only instructions 0 and 1 SWAPPED across seven source shapes. A hand-rolled
`struct Vtbl { void (*OnCancel)(...); }` makes the compiler load **a pointer the source named**,
scheduled like any user load; declaring `OnCancel` `virtual` hands dispatch to MSVC's own vcall
lowering, which emits the vptr load first. **Applies to every shell function dispatching through
an object's vtable** — the shell is real C++, so a struct-of-function-pointers is not a neutral
transcription.

★★ **NEW TELL — A VALUE HELD IN A *VOLATILE* REGISTER ACROSS A CALL ⇒ THE CALLEE IS `static` IN
THE SAME TU.** `Poll` 0x8810B7B0 keeps `self` in **r5** across a `bl`. Measured, all three states:
`extern` callee ⇒ safe ABI `mr r31,r3` + a nonvolatile save (15 insn, 2/13); `static` but NOT a
leaf ⇒ still the safe ABI; **`static` AND a leaf ⇒ `mr r9,r3`, a volatile — the image's shape,
13/13 insn, 9/13 words.** Ruled out explicitly: this is NOT LTCG. `cl -c -GL` emits an IL object
with no machine code and `coff_function` cannot read one, so a `/GL` function would be permanently
out of reach — none of the 223 needed it. ⏭ Parked at 9/13; the remaining choice of WHICH volatile
follows the real callee's clobber set, so decompile 0x88109180 (37 insn) and both the 13×7 and
17×7 families should fall out together (+210).

⏭ **STILL ON THE TABLE: ~16,000 instructions in unstarted clone families**, biggest first —
113×8 = 904 (the driver init from the backlog, and it is EIGHT copies, not two), 193×3 = 579
(game), 211×2, 203×2, 108×3, 72×4. Cheap ones under 40 insn with ≥3 copies total ~2,100 more.
`Driver_SendStageRecord` (22×8 = 176) remains parked at 16/22 and is still the biggest single
lever among functions we have already analysed.


## ★★★★★★ 08-05 EVENING — **PAGE_ENSURETEXTURE 3 → 28/50**, a NEW ALLOCATOR RULE, and TWO
## LONG-STANDING LEADS KILLED WITH EVIDENCE. Board unchanged at 97 / 2407 insn / 9628 bytes.

★ **NEW TOOL: `matchlab/disas.py`** — side-by-side PPC disassembly, same arguments as
`ppcmatch.py --check` plus `--from/--to`. `ppcmatch` says WHICH words differ; this says WHAT they
do. Built after a whole leg went into hand-decoding `rlwinm` masks — and it paid for itself
immediately on the Page_Bake guard. ⚠ **CORRECTION, same night:** my first reading of that `beq`
— "it is the compiler's own zero-trip guard reusing `addic.`'s CR0, not a source `if`" — was
BACKWARDS, and a Fable review pass overturned it (see the block-frequency entry below). The two
are byte-indistinguishable, which is exactly why the tool has to be paired with an argument about
what the compiler CAN and CANNOT do. **Use it first on every new target, and do not read
provenance straight off the mnemonics.**

★★ **A ZERO EARNS A NONVOLATILE THROUGH CONTROL FLOW, NOT SPELLING** (`ALLOCATOR.md` Step 3 now
refined). `Page_EnsureTexture` was one instruction short for weeks: the image holds a zero in
r26 and reuses it for both `tbl[tex] = 0` and the `return 0` exit. **Eight spellings of a shared
`u32 zero = 0` local are ALL inert** — MSVC constant-propagates and rematerialises every use.
What works is restructuring the function around a **single `result` variable, initialised 0,
assigned 1 on success, returned once**, with the range checks inverted into one positive `if`.
That produces `li r26,0` in the entry block and grows the frame to 0x90 to save it. 3/50 → 28/50,
instructions 0-25 and 42-49 now byte-identical. Second qualifying shape alongside Page_Bake's
loop-carried accumulator. ⇒ **If the image holds a constant in a nonvolatile, look for a
control-flow reason, not a spelling.**

❌ **THE c2.dll / QFE LEAD IS DEAD — do not spend an evening on it.** `Root_Join`'s note proposed
"re-run under a QFE'd c2.dll" and warned that extracting one would trip the R6034 dialog. Both
back-ends were already on disk. A 9328 tree ships **two different compilers**, and matchlab's
`CL` is the **TechPreview March-2009** one, not the XDK default:
    xdk9328/raw + TechPreview/Mar09Compiler   cl 15.00.8327   c2.dll 7f0cdb62   <- matchlab's CL
    XDK/bin/win32 + xdk9328_ship              cl 15.00.8153   c2.dll 01db8e0e
**The whole board was re-run under the other back-end: all 97 targets stay ASM-EXACT, zero
DIFFs**, and every stuck function scores identically. Codegen for this corpus is invariant across
every compiler in the 9328 tree. `MATCHLAB_CL` now overrides the path if it ever needs re-testing.
Also ruled out as scheduling levers: **`/Ou` (prescheduling), `/Og`, `/Oz`** — all no-ops under
`/O2`.

✅✅ **BLOCK FREQUENCY IS SETTLED — the Page_Bake guard is a SOURCE `if`, and it is FREE.**
(Fable review pass, since cheaper lanes had stalled at 46 variants.) The image's three paste-side
float loads sit in the loop PREHEADER, below the guard. **No transform on this cl can put them
there** — LICM ruled out three ways: `extern const` (a call kills the load), internal-linkage
`static` (loads stay in-body in volatile FPRs, 211 insn), `__declspec(noalias)` on the paste
callees (per-iteration loads + a post-call reload, 214 insn). If nothing can move them down, **the
source placed them there**, inside `if (pageCount != 0)` — whose compare FUSES into the record
form of the `addic.` that computes `pageCount`, making the guard cost nothing. The old
"+3 instructions" result came from pairing the `if` with an UPCOUNT `for`, which MSVC re-guards;
paired with a **countdown do/while** (`--n != 0`, matching the image's `addic. -1`/`bne` latch) it
is free. Proof the idioms are interchangeable: with the floats above the guard, the explicit
if+do-while compiles **byte-identical** to the plain `for`.

⚠ **PROMOTED AT A LOWER SCORE, ON PURPOSE: 146 → 144.** The positional score fell only because the
register map rotated. On the metric register renaming cannot fake — **STRUCTURAL mismatches, where
the opcode itself differs — it is strictly better: 14 against 17**, and the guard and preheader are
now byte-exact. Conditional placement demotes the pool base r30 → r29, one slot toward the image's
r25 ⇒ **frequency IS a term in the priority function and is NOT the dominant one.** Residue is two
rank edits (pool 3→7, `zero` above `bakeX`) with no known source lever. ⇒ **Next: pin the
if-region discount synthetically**, ALLOCATOR.md-style — split a value's refs between a
fall-through block and a fused-if block and sweep counts, for ordinary values and address bases.

🐛 **A REAL SEMANTIC BUG THE SCORE COULD NOT SEE.** `Page_Bake`'s paste loop incremented `x` TWICE
— once in the `for` step clause and once in the body — so the cursor advanced **0x400 per strip
where the image advances 0x200** (image insn 198 `addi r30,r30,0x200`; ours emitted `0x400`).
Phase 0 pastes two strips, so its second strip landed at x=1024 instead of 512. Invisible in the
score because that word is register-mismatched either way. **A positional score grades SHAPE, not
SEMANTICS** — this is the second campaign defect it has failed to catch. Fixed; score unchanged.

⏭ **THREE FUNCTIONS ARE NOW STUCK ON THE SAME CLASS: a back-end micro-decision that source shape
cannot reach.** This is the campaign's next real problem, and it is worth naming:
 * `Menu_Cancel` 0x821B9E58 — **5/8**, and the only defect is that instructions 0 and 1 are
   SWAPPED (image loads `n->vtbl` before materialising the state-function address; we do the
   reverse). 7 source shapes measured, all 5/8 or worse.
 * `Driver_SendStageRecord` 0x821C2D68 — **16/22**, register allocation ALREADY equal to the
   image's, single defect is that our `req.aux` store schedules 3 slots late. **37 source
   variants**: the function is binary, 16 (aux stored after the record assignment) or 10 (before),
   nothing between, nothing above. Worth **198 instructions** across its 8 clones — the single
   biggest lever on the board.
 * `Page_EnsureTexture` 0x8808D838 — **28/50**, residue is one addressing decision (image collapses
   base+index with an `add` and uses offset form; we keep `lwzx`/`stwx`). Eight pointer spellings
   are byte-identical, so spelling is inert. The pointer form is **one missing instruction out of
   phase** — its +27..+48 IS the image's +28..+49, encoding for encoding.
Source spelling, statement order, flags and compiler build are now ALL ruled out for this class.
Control-flow restructuring is the one lever that has ever moved it (Page_EnsureTexture, +25).
**Attack it with a model of the scheduler, not more syntax.**


## ★★★★★★ 08-05 — **PAGE_BAKE 130 → 146/216.** Three independent attempts; the same core win
## found by ALL THREE. Two whole classes CLOSED, and `ALLOCATOR.md` CORRECTED by its own targets.

★ **THE VERTEX CONSTANT BLOCKS ARE WRITTEN BACKWARDS.** The image's z / colour / rhw stores walk
`verts[3] → verts[0]`; the u/v block that follows walks `verts[0] → verts[3]`. Reversing exactly
those three blocks (and NOT the u/v one) turns twelve displacement mismatches into exact words.
**All three agents found this independently**, per-sub-block verified (z −4, colour −4, rhw −4,
all eight combinations measured). It was invisible as hex and obvious once the stack
displacements were decoded to field names — ⇒ **decode displacements to FIELD NAMES before
touching anything; a run of "reg/field only" mismatches is often a plain SOURCE-ORDER defect,
not an allocator defect.** Two of the seven clusters on this function were exactly that.

★ **THE BAKE CURSOR IS A STRENGTH-REDUCED INDUCTION VARIABLE, NOT A USER ACCUMULATOR.**
`u32 bx = i * PAGE_DIM;` INSIDE the loop, not `bx = x;` before it plus `bx += PAGE_DIM;` at the
tail. The compiler then seeds it in the PREHEADER (image insn 58) instead of above the zero-trip
guard, and the latch increments become the image's order i, rec, bx.

**TWO WHOLE CLASSES CLOSED — do not re-open on any target built with this compiler:**
1. **The float "pool" is NOT a compiler literal pool.** Spelling the constants as literals scores
   far worse: this `cl.exe` emits a **separate `lis`+`lfs` per distinct float literal** and never
   builds a shared base. A single base with displacements must be a named object or file-scope
   statics.
2. **LICM cannot be used to sink loads into a loop and let the compiler hoist them back.** This
   `cl` treats a CALL as killing an `extern const` load, so in-loop loads stay in the body, drop
   to volatile FPRs, and the function shrinks.

⚠⚠ **`ALLOCATOR.md` IS NOW CORRECTED BY ITS OWN TARGETS** (recorded, not quietly patched):
 * **Priority is NOT simply weighted reference count.** Our access pattern and the image's are
   IDENTICAL — same five loads, same offsets, same loop depth, instruction multisets equal by
   construction — yet the assignment differs. **The difference lives in the IR handed to the
   allocator, not in any statistic of what it emitted.**
 * **Address-base references weigh ~3× value references** (float-pool base: 2 accesses ⇒ r25,
   4 ⇒ r29, 5 ⇒ r30).
 * ★ **THE RESIDUE IS ONE DECISION, NOT A PERMUTATION.** Delete `zero` from the image's priority
   list and `pool` from ours and **both collapse to the same order**. There is exactly ONE
   promoted slot at rank 2; the image gives it to the perennial zero, we give it to the
   float-pool base. Every remaining scheduling scramble is downstream of that single choice.
 * ⏭ **BLOCK FREQUENCY IS THE LIVE SUSPECT.** The image's three paste-side float loads sit in the
   loop PREHEADER (after the zero-trip guard, insns 152/153/156); ours sit ABOVE it. Forcing them
   behind an explicit `if (pageCount != 0)` demotes the pool exactly as predicted (r30 → r26) but
   costs 3 instructions because MSVC adds its own guard on top. **Getting those loads into the
   preheader for free is the single highest-value open question in the matching effort.**

⚠ Setup block 27-49 is **pure knock-on, CONFIRMED — do not re-sweep.** The image materialises its
four address bases in exactly SOURCE order; ours does not, only because our `one` load lands at
insn 53 instead of 44 and the scheduler puts each base next to its first use. Ten statement-order
permutations were inert or worse. Declaration order is DEAD in this function (all six
permutations byte-identical) — global regime, exactly as ALLOCATOR.md predicts.


## ★★★★★★ 08-05 — **THE "STATE THUNK" FAMILY IS COMPILER-GENERATED. 11 fns EXACT
## (97 targets, 0.2757%). Plan §8.1 rank 3 is RETIRED as a translation target.**

The 11 four-instruction thunks (0x82061D50/60/70/80, 0x82063A48/A58, 0x82065A78/A88/A98/AA8/AB8)
that plan §8.1 rank 3 lists as "the state-thunk family" are **not source-level functions at all**.
Each is an **MSVC vcall thunk**, emitted when a program takes the ADDRESS OF A VIRTUAL MEMBER
FUNCTION:

    lwz r12,0(r3) / lwz r11,SLOT(r12) / mtctr r11 / bctr

★ **The r12-then-r11 pair is the giveaway.** Ordinary C++ written as `e->vtbl->slot(e)` allocates
**r11-then-r10** and can NEVER match — that cost the first attempt (1/4 on all eleven). Proof:
compiling `&Element::s30` emits `??_9Element@@$BDA@AA` ("Element::\`vcall'{48}'") with bytes
`81830000 816c0030 7d6903a6 4e800420` — byte-identical to 0x82061D50.
⇒ **Reproduced honestly by declaring the class and taking the member pointers** (one file,
`matchlab/src/shell_state_thunks.cpp`); there is no readable body to write and none was invented.
Slots dispatched: 0x24,0x28,0x2C,0x30,0x34,0x38,0x3C,0x40,0x44,0x50,0x74.

★★ **METHOD CONSEQUENCE — NOT EVERY BYTE HAS A SOURCE FORM.** Some of the binary is compiler
scaffolding (vcall thunks; the `__savegprlr_N`/`__restgprlr_N` millicode already found at
0x88071108-0x880711BC). They are matchable, but by *declaring the construct that emits them*,
never by hand-writing a body. Anyone reading a 4-instruction function and trying to write C for
it directly will fail the same way.

⚠ **HARNESS BUG FIXED (found by this leg):** `compile_target` built the `.obj` filename from the
target NAME, so a mangled C++ symbol (`??_9Element@@$BDA@AA` — `?`, `@`, `$`) produced an illegal
Windows path and the harness reported a bogus "compile failed" while the compiler had actually
succeeded. Object names are now sanitised. **A "compile failed" that shows no compiler diagnostic
is a harness fault, not a source fault.**

These were unblocked by the 08-05 "unreachable tail" extent proof — the boundary table has no
entry for any of them (leaf, no .pdata).


## ★★★★★★★★ 08-05 — **THE NONVOLATILE ALLOCATOR IS CHARACTERISED.** `matchlab/ALLOCATOR.md`.
## Gpu_CreateTexture MATCHED (86 targets, 0.2706%); Page_Bake 48 -> 130 of 216.

Eight functions were blocked with **every instruction present and correct**, differing only in
which nonvolatile held which value; per-function sweeps came back FLAT every time. Five probes
plus a synthesis pass characterised the allocator by experiment. **Full rule + evidence +
limits: `matchlab/ALLOCATOR.md`.** The short version:

★ **TWO REGIMES, and the switch is the whole story.** For each value ask whether its live range
CROSSES A BASIC-BLOCK BOUNDARY (calls do NOT split blocks).
 * **GLOBAL** (crosses a branch) ⇒ ranked by **loop-weighted reference count, descending**.
 * **BB-LOCAL** ⇒ **count is ignored entirely**; rank = **source DECLARATION order**.
 * **Every global outranks every local.** Loop weight is **~2× per level** — not 4×/10×/11×.
 * Tie-break among globals = order of DEFINITION. Rematerializable constants get no register
   unless they are a loop-carried accumulator's init.

**Decisive experiments:** A6 vs A7 — same six values, same counts, same declarations; adding ONE
`if` **inverts** the map from declaration order to descending count. C1 vs C2 — byte-identical
output with two counts swapped 2↔8 ⇒ count is provably inert in straight-line code. A blind
prediction on a fresh function scored 6/6.

★★ **THIS EXPLAINS WHY THE SWEEPS WERE FLAT, MECHANICALLY.** `Sprite_EmitQuad` already matches the
image on instruction count, schedule, definition indices, live ranges AND every per-value
reference count. In the global regime priority is a function of counts and definition order — so
a sweep permuting declarations, statement order and expression shape without changing any count
**is searching a space in which every point is the same point.** Tell #12 now has a mechanism.

⚠ **HONEST LIMIT — the rule does NOT pin the full permutation.** It is exact on regime and
ordering and names the r31 occupant and Page_Bake's top four, but it does not reproduce the 11-way
(EmitQuad) or 13-way (Bake) mapping. Both real cases have a region where image order is
ANTI-correlated with count. **A further ordering term exists and dominates when many
branch-crossing values tie.** Also: "reference kind" (ALU ≫ store ≫ call-arg) did NOT reproduce as
an independent axis — do not build recipes on it. Five of eight edits on real code were inert:
**verify by rebuild, never blind.**

**APPLIED RESULTS (all tool-verified, honestly reported as DIFF where not exact):**
| fn | before | after |
|---|---|---|
| `Gpu_CreateTexture` 0x88079970 | 71/72 | ✅ **EXACT at -O1** (registered) |
| `Page_Bake` 0x8808DC10 | 48/216 | **130/216** |
| `Sprite_FlushBatch` 0x8808E468 | 80/169 | 87/169 (ceiling is 134 — 35 words are relocs) |
| `Sprite_EmitQuad` 0x8808E298 | 58/116 | 63/116 |

★ **`Gpu_CreateTexture` confirms the library/title flag split CONCRETELY:** EXACT at `-O1`,
DIFF (78 insn vs 72) at the title's `-O2 -Oc`. XDK library bodies are `-O1`; title code is
`-O2 -Oc`. Both verified on the same function, both directions.


## ★★★★★ 08-05 — **SECOND EXTENT PROOF: "UNREACHABLE TAIL". The .pdata gap is now solvable
## without outside evidence.** Selftest is 8 checks, ALL PASS.

The boundary table has no entry for LEAF functions, so a leaf sitting after a target makes the
derived extent over-run. The 08-05 fix required the split point to be REFERENCED somewhere. That
works for `Menu_Cancel` but NOT for `Page_EnsureTexture` (0x8808D838, real body 50, derived 53):
`0x8808D900` is referenced by nothing — I checked branch targets, stored code pointers in every
section, AND **`lis`+`addi`/`ori` materialised addresses** (2677 of them in the game .text). Truly
unreferenced.

★ **NEW, INDEPENDENT PROOF PATH — the tail is unreachable from the function's own CFG.** Accept a
declared extent when no instruction in `[0,declared)` can branch into `[declared,derived)` (and
there is no interior computed branch to make the CFG incomplete). This reasons about the
FUNCTION'S OWN control flow rather than outside evidence: if nothing in the body can reach the
tail, the tail cannot be part of its behaviour and no trailing difference can hide there.
**Validated against the 0x820AC018 decoy at BOTH plausible truncations** — declaring 4 has a
branch at +1 into the tail, declaring 14 has one at +10, so both are still refused. The
interior-blr hole stays shut. Both paths now report distinctly: `split-REFERENCED` vs
`split-UNREACHABLE`.
⇒ This also unblocks the 11 four-instruction state thunks (0x82061D50 etc.), whose tails are
likewise unreachable — they need translations written, not more evidence.

⏭ **`Page_EnsureTexture` is now PARKED at 49/50 on shape, not on extent.** The original's extra
word is `li r26,0` at +4: **a SHARED ZERO hoisted into a NONVOLATILE**, reused for both
`tbl[...] = 0` and the `return 0`. Flat-array form (matching the Ghidra `[id*5]` evidence and the
`rlwinm/add/rlwinm` index chain) = 49 insn / 3-of-50; struct-pointer form = 50 insn / 12-of-50,
right length for the wrong reason. **Same hoisted-zero/coalescing pattern as Page_Bake** ⇒ it is
the nonvolatile-allocation rule, not expression shape. Do not re-sweep syntax.
(Duplicate source for this address removed — one file per address.)


## ★★★★★★ 08-05 — **THE FLAG SET IS `-O2 -Oc`, NOT `-O2`. `Page_FillFromCpu` MATCHED (85 targets,
## 0.2624%).** A title-wide flag that is INVISIBLE on 84 of 85 functions.

`Page_FillFromCpu` (0x8808DF70) was the delegated "EXACT" that did not reproduce — 82 instructions
against 81. The extra word was at index 66: **`0cca0000` = `twi 6,r10,0`**, MSVC's
divide-by-zero trap emitted ahead of a `divwu`. The original has the SAME `divwu`
(`7c8b5396`, matching at index 64) but **no trap**.

★ **`/Oc` = "disable divide-by-zero exceptions"** — it was sitting in `cl /?` the whole time next
to `/Ou`. With `-O2 -Oc` the function is **EXACT** (81/81).
**Re-verified across the WHOLE BOARD: all 85 targets pass with `-O2 -Oc`** ⇒ it is not a
per-function special case, it is the title's actual flag set. It changes nothing unless the
function divides, which is exactly why 84 functions matched without it and why it stayed hidden.
`functions.json` now records `-O2 -Oc` as canonical.

**THE FLAG PICTURE IS NOW:**
 * **TITLE code — `-O2 -Oc`.** (`-O1` is never right; `-Ox/-GS-/-Gy/-Ob1` are equivalent here.)
 * **XDK LIBRARY code — `-O1`** (proven on `D3DDevice_CreateTexture` 0x88079970 against the
   symbol-named d3d9.lib body).
 * `/Ou` (prescheduling) and every other `-O` variant: NO effect, already ruled out.

**METHOD NOTE — this is the third time a "flat sweep" was the wrong conclusion to draw.** The
previous agent swept flags, got flat results, and concluded the source shape was wrong. The
actual answer was a flag it had not tried, sitting in the compiler's own `/?` output. ⇒ **When a
sweep goes flat, ALSO re-read `cl /?` for a flag that matches the SYMPTOM** — here, an extra trap
instruction had a flag named after exactly that behaviour. Tell #12 says "stop tuning syntax"; it
should say "stop tuning syntax AND check for a symptom-shaped flag".

⚠ `-Oc` does NOT help the other four parked compose functions (Sprite_EmitQuad, Sprite_FlushBatch,
Page_Bake, Render_SelectBlend) — tested, all unchanged. Those remain register-allocation-blocked.


## ★★★★★★★ 08-05 — **SELECT/COMPOSE FAMILY OPENED: 3 fns ASM-EXACT (84 targets, 0.2531%).
## First GAME-module matches. Plus a CORRECTION to NOTES_select_compose.md itself.**

10-worker fan-out over the family the project burned SEVEN lever-guessing legs on. Verified by
me independently before registering — **1 of the 4 claimed matches did NOT reproduce**, see below.

| guest | fn | insn | |
|---|---|---|---|
| 0x8808D930 | Page_Teardown | 62 | releases all page textures + frees pending srcBufs |
| 0x8808D640 | Page_StageUpload | 63 | staging alloc+copy into the upload table |
| 0x8808DA28 | Scene_ResolveFrame | 122 | the per-frame resolve NOTES calls INNOCENT |

⚠⚠ **`NOTES_select_compose.md` CONTAINED AN ERROR AND IT IS NOW FIXED.** The doc said the bake's
phase arrives "through a BLR-IDENTITY FUN_88071134 — Ghidra hides it". **`0x88071134` is
`std r19,-0x70(r1)` = MSVC's `__savegprlr_19` register-save millicode.** Ghidra renders the
compiler PROLOGUE as `iVar3 = FUN_88071134()`, which merely LOOKS like an identity call. The
conclusion (phase = incoming r3) survives, but there is no callee at all. Verified from the
image bytes myself, not taken on report.
★ **The millicode table (0x88071108-0x880711BC) is a FREE READ ON REGISTER PRESSURE:** the
helper address encodes the lowest nonvolatile saved. dc10 = `__savegprlr_19` ⇒ **13 nonvolatiles**;
D838 = 26 (6), D930 = 29 (3), D640 = 24 (8). Frame follows: 8 NV ⇒ `stwu -0xA0`, 6 ⇒ `-0x90`
(constant part 0x58). You can predict the frame word before writing a line of C.

**NEW TELLS (all worker-found, all generalise):**
1. ★ **`li rX,0; oris rX,rX,0x8000` (TWO insn) vs `lis rX,0x8000` (ONE) = ARGUMENT WIDTH.** The
   li/oris pair is the zero-extended DOUBLEWORD form ⇒ the parameter is 64-bit. Put this beside
   the cmpwi/cmplwi tell: **cmpwi/cmplwi = signedness, lis vs li+oris = WIDTH.** Ghidra's
   `ulonglong` typing was right and believing it paid.
2. **A NEGATIVE displacement proves the anchor object starts ABOVE the accessed word.** MSVC
   never emits one otherwise (probed with 6 scratch builds): a single `extern struct` always
   anchors at symbol+0; file-scope statics share a base but in a NAME-dependent permutation;
   plain globals get no sharing. So `lwz r3,-8(r31)` forces the state block to be declared in
   two pieces. Corroborated across two functions — both anchor at min_accessed + 8.
3. **Do not chase `mr r11,r29` before a store** — plain codegen for storing a hoisted zero.
4. **`stwu rX,0x14(r31)` with the walker biased below the table base** is just
   `rec->field = 0; rec++;` fused into store-with-update. Do not invent a negative-based table.
5. ★ **`0x88079970` is `D3DDevice_CreateTexture` from the statically linked XDK d3d9 library, and
   LIBRARY code is built at `-O1`, not the title's `-O2`.** Confirmed against the symbol-named
   d3d9.lib (archive member '/782', 288 bytes = 72 instructions, instruction-for-instruction
   identical). ⇒ **the -O2 rule is for TITLE code; XDK library bodies need -O1.**
6. **XDK 9328 ships TWO compilers** — 15.00.8327 (`TechPreview\Mar09Compiler`) and 15.00.8153
   (`bin\win32`). Both were tried on the stuck word; identical. 9328.9's compilers are
   MD5-identical to both ⇒ **the QFE question is now closed for this class too.**

⚠ **`Page_FillFromCpu` (0x8808DF70) was reported EXACT but DOES NOT REPRODUCE** — my independent
check gives 82 insn vs 81, 52/81, under every flag (-O2/-Ox/-Ou/-Ob1/-GS-/-O1). NOT registered.
**Re-verify every delegated match before it goes on the board.**
⚠ `Page_EnsureTexture` (0x8808D838): the real body is 50 insn with an unreferenced 3-insn leaf at
0x8808D900; the split is correctly REFUSED (0x8808D900 is referenced by nothing), so it stays off
the board. Same unprovable-extent class as the state thunks.
⏭ Parked with sharp deltas: `Gpu_CreateTexture` **71/72 — ONE word**, `ori` vs `addi` (38 flag
combos + both compilers ruled out); `Sprite_EmitQuad` 58/116; `Sprite_FlushBatch` 80/169;
`Page_Bake` 48/216 (138/216 LCS-aligned — frame, prologue, all 14 call sites and both loop
shapes already agree); `Render_SelectBlend` 56/171.


## ★★★★ 08-05 — SCHEDULING CLASS: **TWO HYPOTHESES KILLED, ONE NEW TELL.** (Still parked.)

The three functions stuck on register-allocation/scheduling (`Driver_SendStageRecord` 16/22 —
worth 176 insn via 8 clones, `Root_Join` 28/46, `Menu_Cancel` 5/8) all have every instruction
present and correct; only ORDER or which nonvolatile differs.

**KILLED #1 — it is not an optimisation flag.** `cl /?` lists a PPC-specific **`/Ou` = enable
prescheduling** which had never been swept. Swept it, plus `/Og /Ot /Oz /Ox`, across all three:
**every flag gives byte-identical output** (16/22, 28/46, 5/8 unchanged). Prescheduling is
already implied at -O2 and the schedule is not flag-controlled. Do not re-try this.

**KILLED #2 — the global is NOT cached in a local.** `Root_Join`'s residue is base→r30/param→r31
in the original vs the reverse in ours. Hoisting `g_appConfig` into a local at the top made it
WORSE and one instruction SHORTER (46→45, 28→18).

★ **NEW TELL (from that failure): a nonvolatile holding a `lis` BASE means the global is read
2+ times and RE-LOADED each time — the source does NOT cache the pointer in a local.** The
nonvolatile holds the address's high half (0x8220 0000), reused by each access, not the loaded
pointer. So `lis rNV,hi` + repeated `lwz rX,lo(rNV)` ⇒ write the global access out in full at
every use; caching it in a local removes an instruction and cannot match.

⏭ What is left for this class: which nonvolatile a value lands in (r30 vs r31) is decided by
allocation order, and neither first-use order nor caching moves it. Needs a different idea —
possibly the number of live ranges, or declaration order of the STRUCT types involved.


## ★★★★★★★★★ 08-05 — **THE LOOP IS CLOSED. `0x820619F0` IS THE FIRST FUNCTION THAT IS BOTH
## ASM-EXACT AND MATCHED: byte-identical to the original AND running in the port.**

Until now matchlab was a scoreboard — 81 byte-exact functions, **none of which executed**. The
port still ran recompiled PPC for every one. This closes that.

**ONE BODY, TWO COMPILATIONS.** `decomp/shell/task_kill.inl` holds the natural C++:
 * `matchlab/src/shell_820619F0_TaskKill.cpp` includes it → XDK 9328 → **ppcmatch EXACT**.
 * `decomp/shell/task_kill.cpp` includes it → clang-cl → `PPC_FUNC(sub_820619F0)` adapter that
   unpacks `ctx.r3` into a guest pointer. ⇒ **the code that RUNS is provably the same program
   the original was.** Nothing else in decomp/ has that property.

★★ **THE ENABLER: `be<T>` IS FREE ON PPC.** `decomp/include/guest_be.h` — identity under the
XDK compiler (guest is big-endian), byte-swapping on the host to match PPC_LOAD/PPC_STORE.
**Verified, not assumed:** `struct Task { be<u32> pad[2]; be<u32> state; }` emits
`39600002 91630008 4e800020` — byte-identical to plain `u32`. This is the UnleashedRecomp trick
and it is what makes shared-source translation possible at all. Without it the matched C++ would
be wrong-endian in the port.

**FOUR-PART PROOF (each part was necessary; the first two are not sufficient):**
1. **ASM-EXACT** — ppcmatch EXACT on the shared .inl.
2. **WINS THE LINK** — fresh map: `?sub_820619F0@@...` → `decomp_task_kill.o`; the generated
   `__imp__sub_820619F0` survives at a different address as dead weight (= the rollback shape).
3. **EXECUTES** — one-shot `RT_TKCANARY` print fired on a live drive, then removed (PILOT_NOTES §3).
4. **BEHAVIOURALLY IDENTICAL** — c1_gate.sh DUR=40, control (generated-only build, adapter moved
   aside) vs pilot: **CANONICAL-IDENTICAL 24/24**, raw 22/24, the 2 deltas being guest-heap
   pointers (the documented C1 drift class).

⚠⚠ **`futari_merged.map` WAS STALE AND I ALMOST BELIEVED IT.** build_win.sh never emitted `/MAP`,
so the map on disk was hours old and reported the seam as NOT taken when it had simply not been
regenerated. **`/MAP:futari_merged.map` is now emitted by every build** — PILOT_NOTES §3 has
depended on that file existing since 07-28 and it silently did not. Same lesson as the capped
logs and the peak meters: **LINK_OK is not seam-took, and a map you did not just generate is not
evidence.**

⚠ **BUILD FIX (pre-existing, latent):** build_win.sh compiled `decomp/shell/*.cpp` with
`$GAME_INC`, but `shell/gen/ppc_config.h` differs from the game's (PPC_IMAGE_BASE 0x82000000 vs
0x88000000, different CODE_BASE/SIZE). `decomp/shell/` was empty until today so nothing had ever
hit it. The shell half now compiles with `$SHELL_INC $XS`.

**REUSABLE:** `_tmpscripts/canon_seq.py` — the heap-pointer masking the C1 gate needs. It had
been done ad hoc in-session, which is why it kept being re-derived; it is a script now.

⏭ **THE PATTERN IS NOW REPEATABLE** for any ASM-EXACT function: move the body to a `.inl`, add a
PPC_FUNC adapter, gate control-vs-pilot. ⚠ Do it DELIBERATELY, not in bulk — these 81 are shell
wrappers that already work, so replacing them buys no user-visible gain and carries regression
risk. Highest value first: functions where readable C++ actually helps a live defect hunt.


## ★★★★★★ 08-05 — **HARNESS: SPLIT-VERIFIED EXTENTS + 4 NEW COMPILER TELLS FROM THE FAN-OUT**

**THE BOUNDARY TABLE IS INCOMPLETE, AND NOW THERE IS A SOUND WAY AROUND IT.** `.pdata` carries
no unwind record for LEAF functions, so any leaf sitting immediately after a target makes the
derived extent OVER-RUN it. Confirmed live: `0x821B9E58` is **8** instructions ending in `bctr`,
but a leaf starts at `0x821B9E78` (absent from shell_funcs.txt) so derivation returned 13.
This always failed SAFE (length mismatch ⇒ DIFF, never a false EXACT) but it blocked matching.

**FIX — a declared extent is now accepted ONLY with independent proof of a function boundary:**
(a) the declared slice must end in blr/bctr/tail, AND (b) the address right after it must be
**REFERENCED elsewhere in the image** — a branch target, or a code pointer stored in any section
(11629 such addresses in the shell). That second condition is what keeps the interior-blr hole
shut: at the `0x820AC018` decoy the interior returns are at +4/+9/+14 and **none of those
addresses is referenced**, so a bogus override is still refused. Both cases are now selftest
cases ("verified split accepted" / "unproven split refused"); selftest is 7 checks, ALL PASS.
⚠ The 11 state thunks stay PARKED: their split points are not referenced either (dispatched
through a table the scan does not see), so they remain unprovable and are correctly refused.

**FOUR TELLS FROM THE 13-WORKER FAN-OUT (all independently re-verified):**
1. ★ **A NON-CONTIGUOUS AND MASK COSTS TWO `rlwinm`s, NOT `andi`.** `x & 9` emits
   `rlwinm r,r,0,28,31` then `rlwinm r,r,0,31,28` (a wrapping mask) — 9 = bits 28|31 is not
   expressible as one rotate-legal mask, and the compiler avoids `andi.` to leave CR0 alone.
   **Do not invent a bitfield to explain the first `&0xF`.** Rule: N back-to-back `rlwinm`s with
   SH=0 == ONE source-level `& K`. Same idiom verbatim at 0x82190AAC.
2. ★ **A dead `blr` after a `bctr` is REAL and expected** — cl 15.00.8327 emits an unreachable
   `blr` at the fall-through label after a tail call. A trailing blr is NOT by itself evidence
   the extent is wrong (contrast the 0x821B9E58 case above, where 5 coherent words follow).
3. **`bXXlr` (conditional return) ⇒ a LEAF function with no frame and a plain early `return;`**
   in the source — not a jump to a shared epilogue.
4. **`if (obj->cnt++ < LIMIT) return;`** reads as lwz / addi / cmpwi-on-the-PRE-increment-reg /
   stw / bltlr. Write it as post-increment inside the condition; no hand-splitting needed.
   Bonus: a same-function `cmpwi` + `cmplwi` pair is a **free signedness oracle** for two fields.
5. **`const int k = 0x78;` folds to an immediate and emits NO data symbol** — named constants are
   free here. (The tell-#2 hazard is specifically a literal bound to a CONST REFERENCE.)
⚠ Ghidra artifact: `piVar1 + 3` on an `int*` means byte offset **+0xC**, not +3.

⚠ **PARKED with sharp deltas:** `Menu_Cancel` 0x821B9E58 — extent now correct at 8, and 5/8 match
with **only idx 0/1 swapped** (`lwz vtbl` vs `lis`), a pure scheduling difference; reordering the
source did not move it. `Root_Join` 0x821CE400 — **46/46 length, every branch displacement
correct**, residue is ONE register-allocation choice (original: base→r30, param→r31; ours the
reverse) plus its cascade at idx 5,6,7,21,25,26. Both are register/schedule-class, not semantics.

## ★★★★★★★★ 08-05 NIGHT — **81 TARGETS, 1963 insn, 7852 bytes = 0.2248%** (from 0.0295% at the
## start of the leg — 7.6x). 16 source files. Full board verified, selftest ALL PASS.

Three things drove it, in descending order of leverage:

**1. THE CLONE SWEEP (35 + 8 + 8 functions for zero extra code).** See the block below. Then
`Driver_ArmSession` (0x821C2E20, **51 insn x 8 instances = 408 instructions from ONE function**)
and `Driver_Query17` (18 x 8 = 144). The shell's 12 clone families are now nearly exhausted.

**2. PARALLEL FAN-OUT.** 13 workers, one function each, iterating against `ppcmatch --check`
(new ad-hoc mode, added so workers never contend on functions.json). **11 of 12 delivered
byte-exact**, every one re-verified by me independently before registering: Deferred_Node,
Colour_Fold (plan §9.1 #1), Walk_Draw/Mid/Small/Tick, Menu_ChildResult, Logo_Tick/Exit/Hold/Hold2.
Root_Join (0x821CE400) came back DIFF at 28/46 and is NOT registered. The logo FSM cross-checks
beautifully: Logo_Exit's relocs resolve to 0x820735C8 + 0x820619F0 — the deferred-action triple
the plan predicted, two thirds of which were already matched independently.

**3. THREE MORE COMPILER TELLS** (from Driver_ArmSession, which took 4 iterations):
 * **`cmpwi` vs `cmplwi` again** — a parameter compared `!= 0` with cmpwi is an `int`, NOT a
   pointer. Second time this tell has paid; it is now the first thing to check on any DIFF.
 * **Branch layout reveals which arm was written first.** The original branches AWAY for
   `kind==3` and keeps `kind==4` inline ⇒ the source is `if (kind != 3) { if (kind == 4) ... }
   else { ... }`, not `if (kind==3) ... else if (kind==4) ...`. Writing it the natural way costs
   ~6 instructions of layout difference.
 * **`||` + ternary goes BRANCHLESS.** `d->x = (kind==3) ? 3 : 4` under `if (a || b)` compiled to
   addi/rlwinm/xori arithmetic and made the match strictly worse (53 insn vs 51). Keep the
   branches explicit.
 * ⚠ **Deref depth is visible.** `extern u32** g` + `*g` emits one lwz too many vs `extern u32* g`.
   The lis/lwz pair IS the first deref — do not add another.

⚠ **PARKED, honestly:** `Driver_SendStageRecord` (0x821C2D68, 22 insn x 8 = 176 instructions) sits
at 16/22 with **all 22 instructions present and only 4 SCHEDULED differently** (the aux store
floats across the mtctr). 12 source shapes tried across two sweeps — assignment order, initializer
lists, separate locals, array form, struct-vs-scalar, signedness — every one identical. This is a
scheduling difference the source shape does not appear to control; it needs a fresh idea, not more
variants. Also parked: `Root_Join` 0x821CE400 (28/46) and `Menu_Cancel` 0x821B9E58 (8 insn
vs 13 — the worker's shape is too short, so it is missing a whole construct).
⚠ **`matchlab/src/` now contains TWO SOURCES THAT DO NOT MATCH** — `shell_821CE400_Root_Join.cpp`
and `shell_821B9E58_Menu_Cancel.cpp`. They are committed as work-in-progress but are **NOT in
functions.json**, so the board never verifies them. Anything not in functions.json is unproven
by construction: `ppcmatch` with no arguments is the only source of truth for what is matched.

## ★★★★★★★★ 08-05 LATER — **CLONE SWEEP: 35 MORE FUNCTIONS FOR ZERO NEW CODE.
## 47 targets, 918 insn, 3672 bytes = 0.1051%** (was 0.0295%). Past 0.1%.

The atlas's "8 near-identical clones" is now **measured, not asserted**: the shell contains
**8 GameDriverTask instances**, each carrying the same five wrappers, and within each family the
bodies are **byte-identical** — same registers, same stack offsets, same immediates. So the
sources already written cover all of them.

| source | insn | exact clones found |
|---|---|---|
| Driver_SetConfig19 | 13 | 7 (0x821C4128/49A8/75B8/7E38/86B8/8F38/97B8) |
| Driver_SetConfig16 | 13 | 7 (0x821C41B8/4A38/7648/7EC8/8748/8FC8/9848) |
| Driver_ArmMode | 20 | 7 (0x821C4248/4AC8/76D8/7F58/87D8/9058/98D8) |
| Driver_ArmModeEx | 25 | 7 (0x821C4298/4B18/7728/7FA8/8828/90A8/9928) |
| Driver_SetRankLevel | 27 | 7 (0x821C2A78/4010/4890/74A0/7D20/85A0/96A0) |

**METHOD — THE CLONE SWEEP IS NOW A STANDING MOVE.** After each match, hash every well-bounded
function of the same length in the module and compare bodies. It cost one script and returned
686 instructions. Anything with N near-identical instances multiplies by N for free, and this
codebase is full of them (8 driver instances, per-mode loaders, state thunks).
⚠ Each clone is a DISTINCT guest function at a distinct address and is counted as such — the
same way decomp.dev counts bytes — but the ledger records that one source satisfies all of them.
Every clone was verified independently by ppcmatch, not asserted from the scan.

**BOUNDARY-TABLE LIMIT FOUND (deliberately not worked around):** the 11 four-instruction state
thunks at 0x82061D50/D60/D70/D80, 0x82063A48/A58, 0x82065A78..AB8 are **absent from
shell_funcs.txt**, because leaf functions get no `.pdata` unwind record — so extent derivation
over-runs them (0x82061D50 derives 16 insn, truth is 4). Every heuristic that would find them
(cut at a terminal whose successor is 16-byte aligned; accept a declared extent whose tail
decomposes into terminal-ended chunks) ALSO re-opens the interior-blr false-EXACT hole — checked
against 0x820AC018 and both fail. ⇒ **thunks are parked, not matched.** 3973 shell functions are
well-bounded, 304 of them reloc-free, so there is no shortage of sound work. Queue banked at
C:/tmp/match_queue.json (132 reloc-free candidates <= 26 insn).

## ★★★★★★★ 08-05 — **SHELL DRIVER FAMILY: 11 MORE FUNCTIONS ASM-EXACT (14 total, 0.0295%).**
## Relocation-aware matching LANDED, so functions with calls/globals are now matchable.
##
## ⏭ **RESUME POINT — the family's 4 BIG members remain, recon already banked:**
## `0x821C2F58` mode LOADER (88 insn, 14 bl, builds the module path string),
## `0x821C30B8` init DRIVER (113 insn, 2 bl + 7 bctrl, 312-byte staging buffer, ~10 external
## symbols) and its near-clone `0x821C8BE0` (**differs in only 3 of 113 words** — match one,
## get both), `0x821C57B8` GameDriverTask ctor (119 insn, 2 bl). These are real grinds, not
## first-try shapes; the msg wrappers and the destructor were the cheap 80%.
## Also still unclaimed: plan §9.1 #1 `FUN_82076C10` (38 insn, leaf-pure) and #2 the logo FSM
## family (8 fns, 322 insn) — both cheaper than the four above.

User: "do the shell driver family next... would still love the byte matched, human readable long
term." Whole GameDriverTask→game message surface is now byte-exact in ONE human-readable file,
`matchlab/src/shell_driver_msgs.cpp` (13 targets total on the board, 232 insn / 928 bytes).

| guest | fn | insn | note |
|---|---|---|---|
| 0x821C2B38 | Driver_SendReturnToMenu (msg 13) | 5 | tail call via `bctr` |
| 0x821C2B50 | Driver_SendArmMode64 (msg 12) | 5 | tail call via `bctr` |
| 0x821C2B90 | Driver_SetConfig19 (msg 19) | 13 | **clone 0x821C8F38 byte-identical** |
| 0x821C2C20 | Driver_SetConfig16 (msg 16) | 13 | **clone 0x821C8FC8 byte-identical** |
| 0x821C2CB0 | Driver_ArmMode (msg 10) | 20 | |
| 0x821C2D00 | Driver_ArmModeEx (msg 10) | 25 | |
| 0x821C2DC0 | Driver_SendRegionConfig (msg 15) | 23 | first RELOC-bearing match |
| 0x821C8E20 | Driver_SetRankLevel (msg 11) | 27 | matched FIRST TRY |
| 0x821C2EF0 | Driver_Destroy (dtor, msg 3 + XexUnload) | 26 | matched FIRST TRY, 4 relocs |

**CLONE DIVIDEND CONFIRMED:** 0x821C8F38≡0x821C2B90 and 0x821C8FC8≡0x821C2C20 are byte-identical,
so one source satisfies two addresses. The atlas's "8 near-identical clones" claim is real and is
exactly why this family was ranked as the biggest LOC-per-effort win (plan §4 rank 5).

**NEW CAPABILITY — RELOCATION-AWARE COMPARE.** A `bl` or a global reference holds a link-time
placeholder in our .obj and a resolved offset in the image, so those words cannot be compared
byte-for-byte. ppcmatch now parses the COFF relocation table, compares every bit EXCEPT the
patched field, and PRINTS the resolved guest target so a human can audit it — e.g. msg 15 reports
`+4 imm=0x8220, +8 imm=0x858c, +10 bl->0x8207dac0` (0x82200000-0x7A74 = 0x821F858C ✓). Verdict is
`EXACT*` (starred) so it is never confused with a full byte match. Types handled: REL24/ADDR24,
REL14/ADDR14, ADDR32, TOCREL16, ADDR16, REFHI/REFLO (+PAIR skipped); an unknown type is a hard
error, never a silent pass. Also: `bctr` added as a function terminator (the tail-call senders).

**THREE MORE COMPILER TELLS (all cost real time; they generalise):**
1. **Passing `&param` spills to the parameter HOME slot (r1+0x7C); a local copy gets a fresh slot
   (r1+0x50).** `d->GameEntry(19, &value)` matches; `u32 a = value; ...&a` does not.
2. **`cmpwi` vs `cmplwi` reveals parameter SIGNEDNESS.** `int mode` matched where `u32 mode` did
   not — one instruction, and the only evidence of the original's type.
3. ★ **0x8207DAC0 IS LIBCMT `memcpy`, and it MUST be declared as `memcpy`.** A look-alike
   3-arg helper sets up r5 before r3; the compiler knows the name `memcpy` and emits r3 first.
   Six source-shape variants were all identical before trying the real name — the flat-sweep rule
   from the ColorMul leg fired again and was again right.

**⚠ QFE QUESTION CLOSED — THE COMPILER IS THE SAME.** The 08-04 caveat ("build XDK had QFE ≥ 4,
base install may not be that state") does NOT affect matching: `cl.exe`, `c1.dll`, `c1xx.dll` and
`c2.dll` are **SHA1-identical between 9328 base and 9328.5**. QFE ships libs, not codegen. Base
9328 is the correct compiler full stop; the r3/r5 ordering was source shape, not toolchain.

## ★★★★★★★★ 08-04 LATE — **BYTE-EXACT MATCHING IS LIVE. THE PERIOD-CORRECT COMPILER IS IN HAND
## AND THREE FUNCTIONS ARE SHA1-IDENTICAL TO THE ORIGINAL.** Workbench: `xr-work/matchlab/`.

Opened by a user research request (decomp.dev / rjkiv's dc3-decomp methodology). The finding that
changes the campaign: **the XEX records the toolchain build.** Two headers say so — imports
(`0x000103FF`) read `xboxkrnl.exe`/`xam.xex` **2.0.9328.0** (version_min 2.0.8498.0), and the
STRONGER record, static libraries (`0x000200FF`), lists the libs actually linked: 15 in
`assets/default.xex`, 5 in `reco_normal.xex`, **all build 9328** (LIBCMT, D3D9, D3DX9, XGRAPHC,
XACT3, XAUDIO2…). That build is in the user's collection at
`Z:\tv\_NEW\xdkcollection\2009\9328 June\`; extracted in ~3 min, banner reads
`Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 15.00.8327 for PowerPC`.
(⚠ `C:/Users/shant/Desktop/projects/_tools/xdk/xdk20209` is Sept 2010 — right for API signatures, WRONG for matching.)

⚠ **CALIBRATION, from the adversarial pass — do not overclaim this.** (a) **It is NOT the plain
June base drop:** `XAUDIO2` and `XAPOBA` carry **QFE 4** (`2.0.9328.4`) while the other 13 read
`.0`, so the build machine had at least QFE 4 applied. The import record's QFE byte is 0
everywhere and cannot separate 9328 from 9328.5/.8/.9 — honest ceiling is "9328, QFE ≥ 4, exact
revision indeterminate". PE timestamps 2009-10-10/11 corroborate a summer-QFE'd install.
(b) **`cl.exe`'s version appears nowhere in the XEX** — the format records linked LIBRARIES. The
warrant for the compiler is EMPIRICAL: base-9328 `cl.exe` reproduces these bodies byte-for-byte.
If a future target resists matching, re-test that assumption before blaming the source; `Z:` has
9328.5/.8/.9. (c) `shell/default.xex` and `assets/default.xex` are byte-identical — two distinct
binaries, not three.

**RESULTS — all three verified by SHA1 over the instruction bytes, entry to blr:**
| guest | fn | insn | verdict |
|---|---|---|---|
| `0x8206D328` | ColorMul (per-channel colour multiply, 0x80==1.0) | 56 | EXACT `eeb202580b31` |
| `0x820619F0` | Task_Kill (`*(task+8)=2`; 70 call sites) | 3 | EXACT `015b3946cb3a` |
| `0x82073638` | Action_Run (`fn(arg)` then self-kill) | 16 | EXACT `b453eb9f39f4` |

ColorMul took a sweep to corner; **the other two matched FIRST ATTEMPT with no iteration** — the
method generalises, it was not luck. `matchlab/ppcmatch.py` is the harness (compile → pull the
symbol out of the COFF → byte-compare vs the module image); `matchlab/functions.json` is the
target registry; `matchlab/README.md` has the re-extraction recipe and the landmines.

⚠⚠ **THE HARNESS'S FIRST VERSION EMITTED TWO FALSE `EXACT`s — found by an adversarial pass
BEFORE commit, fixed, and now permanently positive-controlled via `ppcmatch.py --selftest`.**
The three results above were re-verified after the fix and are unchanged (same SHA1s) — they were
always honest — but v1 could not have told the difference, which is the whole point:
(1) **"extent = up to the first blr" is WRONG.** `0x820AC018` has FOUR unconditional blrs inside
a 25-instruction body (early returns), so v1 read 4 instructions and certified a garbage
4-instruction stub as EXACT. 567/4277 shell blrs and 447/2977 game blrs are interior — 13-15% of
return sites were booby-trapped. Extent is now "to the first padding word, bounded by the next
entry in shell_funcs.txt", and the last word must be a blr/tail.
(2) **Substring symbol lookup graded the wrong symbol** — a helper named `Task_Kill_reference`,
and worse, a `const u32 Task_Kill_golden[]` DATA ARRAY holding hand-typed expected words. Lookup
is now exact-anchored (`name == want` or `?want@…`), requires symbol Type 0x20 FUNCTION in a CODE
section, and hard-errors on ambiguity.
(3) **A declared `insn` was an unvalidated fixed slice** hiding trailing differences; it is now
reconciled against the independently derived extent, and disagreement is a hard error.
**RULE: run `--selftest` after touching ppcmatch.py, and never trust a green from a harness that
has not just refused its decoys.** (Same doctrine as the meter/capped-log lessons: instruments
lie until positive-controlled.)

**WHY THIS MATTERS:** every translation until now needed a behavioural gate — scripted drive,
determinism control, `canon()` pointer masking, usually user eyes — which is exactly why Lane-A
sat still from 07-30 to 08-04. Byte-matching answers the same question offline in under a second.

**METHOD RULES EARNED (these generalise to every future target):**
1. **`std::min` is visible in the asm.** A clamp compiled as `addi p,&a / bgt / addi p,&b / lwz`
   — a POINTER select through stack temporaries, not a value select — means the source called a
   `const T&`-returning `min`. Ghidra renders this as its `puVar = &local_x` aliasing soup.
2. **A literal bound to a const reference materialises a fresh temporary PER CALL SITE.** The
   original stores `0xFF` four times alternating two stack slots; a hoisted `u32 ff = 0xFF`
   stores it once. That one difference was exactly the 3-instruction gap (53 vs 56).
3. **Declaration order of pure locals decides register allocation.** Declaring the byte-extract
   pairs `0,3,2,1` vs `0,1,2,3` moved nothing but which registers channels 1 and 3 landed in —
   45/56 → 56/56.
4. **When a sweep goes flat, stop tuning expression shape.** 432 builds across expression knobs
   collapsed to one identical output; the answer was object lifetime, not syntax.
5. **The title is built at `-O2`-class opt.** `-O2`/`-Ox`/`-O2 -GS-`/`-Ox -GS- -Gy`/`-O2 -Ob1`
   all reproduce exactly; `-O1` does not. That narrows the flag search permanently.
6. ⚠ **Landmines:** `7z e` FLATTENS the XDK tree — fine for `cl.exe`, but `dumpbin`/`link` then
   die with **R6034** (local `msvcr90.dll` vs SxS); use `cl /FAcs` listings instead. `cl.exe`
   needs `1033/clui.dll` or it dies C1510. **Git Bash mangles `/O2` into a path** — use `-O2` or
   pass flags from Python. MSVC puts templates in their own COMDAT `.text`, so extract the
   function by SYMBOL, never "the first .text section" (cost one bogus diff).
7. ⚠ **`C:/tmp` IS NOT DURABLE** (this project already lost `C:\tmp\inventory` and a XenosRecomp
   clone that way). The durable copy is the archive on `Z:`; README has the re-extract recipe.

✅ **LADDER — USER RULED 08-04: "new rung, keep registry.toml behavioural." IMPLEMENTED.**
`ASM-EXACT` now sits between `DRAFT` and `MATCHED` in `decomp/README.md` and plan §2, with a
two-axis table: `MATCHED` = behavioural gate + linked in; `ASM-EXACT` = compiles to the original's
bytes. Neither implies the other — nothing in matchlab is linked, and `GameEntry_Dispatch` is
MATCHED but can never be ASM-EXACT (it is a `PPC_FUNC_IMPL` ctx-shaped body, not natural C++).
`registry.toml`'s `status` still only holds RAW/NAMED/DRAFT/MATCHED/LOCKED; the three functions
were seeded there at **DRAFT** with `asm_exact`/`asm_sha1`/`matchlab` cross-reference fields, and
`matchlab/functions.json` is authoritative for the new rung. Plan §10 documents it in full.
Natural end state = the UnleashedRecomp shape: keep the matched natural-C++ body, verify with
9328 + ppcmatch, and give it a thin adapter unpacking the guest register file for the recomp host
— which is what the C1 "register-file rule" was hand-deriving the expensive way.

## ★★★★★★★ 08-04 NIGHT — **HW-TRUE KERNEL ALLOCATOR (decomp verdict) + 512MB CONTAINMENT
## GATED GREEN. ONE OPEN TENSION = THE RESUME POINT.** Commits 31c6236 + e352e29.
**THE DECOMP VERDICT (user ruled decomp-first, 3x):** shell FUN_82089ed8 / game FUN_880836d0
callers (IDENTICAL XAPI code, default_decomp_all.txt / reco_normal_decomp_all.txt): the 360
kernel does NOT zero physical allocations — guest wrappers memset themselves, only on flag
0x40000000, and those memsets are recompiled code that ALREADY RUNS here. Every historical
poison class (select blanking 07-20, menu-DOWN 07-31, navy) was OUR memset-on-reuse showing
zeros where HW shows stale-but-plausible old bytes. Quarantine/floor/coalescing-ban tower
existed only to contain our own invention.
**LANDED (all in out_reco/harness.cpp, levers per change):** Mm path = rt_alloc_raw, NO zero
on reuse (RT_ALLOCZERO=1 reverts; NtVA commits still zero — real VirtualAlloc semantics);
free floor 1MB→0 (the floor swallowed the shell streamer's 0.3MB frees "live" forever —
~20MB/swap staircase, live hit 471MB); coalescing ON (the 07-31 killer was ZEROED not merged);
frontier retreat RT_HEAPRETREAT (+2s settling floor; at-line age-0) ; RT_POOLNOHI (never
normal-reuse blocks ≥0x20000000); 16KB granule RT_HEAPGRAN/RT_HEAPGRAN_SZ (64KB inflation ≈
the 19MB overshoot); bigres default OFF (diversion hid 4MB+ blocks from coalescing);
**LIFO reuse** (RT_POOLFIFO=1 reverts): exact-fit takes NEWEST in class — FIFO recycled
long-freed compose pages the shell references-after-free (user screenshot: black/displaced
chunks at 360 shot select) — kernel free-lists are LIFO, hot rotation recycles its OWN block;
split = smallest-fit (LIFO-window there cost 17MB), newest tie-break in-class; split scan
floor (≥1MB relic) REMOVED — it made 101MB of sub-1MB shards invisible to all but exact class.
**GATES:** swapbounce ALL 7 GREEN incl. NEW P7 (zero 0x20000000 crossings; high-water 496MB
vs 672 at leg start; P7 counts breach prints — cap is 60+1, don't read "61" as a count);
START counter now split-proof (interleaved stderr splits lines mid-word — count head OR tail
pattern, take max). G1 PASS throughout. 6 gate iterations, forensics-driven each round
(LINE-BREACH cand dumps: age-rejects → near-miss classes → shard invisibility).
**⚠ THE OPEN TENSION (resume here):** default quarMs=0 passes P7 but corrupts char/shot
select on FIRST ENTRY (screen-drive verified — our deferred walker reads ~50ms late; age-0
reuse overwrites decode buffers mid-read). RT_FREEPOOL_QUAR_MS=250 CURES it (screen-drive
verified clean: char select, shot select stone plates + No-entry watermarks authentic,
ranking box, mode select, through Ver1.5 NORMAL PLAY). 250 is NOT P7-gated yet. NEXT LEG:
(1) re-gate swapbounce with quarMs=250; (2) if green, make 250 the default; (3) the TRUE fix
is renderer-side copy-at-record — allocator quarantine is a shim for OUR late reader, not a
HW behavior. ⚠ User DECLINED an edit putting the 250 override into EYEBALL_0804.cmd — ask
before touching the launcher. ⚠ User ruled (4th time): decomp/human-readable FIRST — queued:
rewrite rt_alloc as clean ~150-line rt_phys.cpp implementing these semantics as spec, DELETE
the lever tower (not default-off). Nav truth for drives: 360-mode select is INSIDE Ver1.5
NORMAL PLAY (TOP MENU "Arrange" card = REFUSED, "no message registered" — not the 360 entry).

## ★★★★★★★ 08-04 EVE — **THE WHOLE POST-SWAP VISUAL FAMILY ROOT-CAUSED: THE 512MB PHYSICAL-
## ALIAS IDENTITY BREAK.** One attended screen-controlled session (user: "take screen control,
## validate via screenshots, stop guessing"), full RVK_RESLOG, banked at
## /c/tmp/BANK_wedge_session.log (55677 lines). THE CAUSAL CHAIN, ALL IN ONE LOG:
- 360 select ENTRY #1 (clean, screenshot-verified perfect): page bake FIRES (12k+ 512x512
  resolves, rects {0,0,512,512}/{512,0,640,512} = NOTES_select_compose.md's dc10 exactly),
  page textures at 0x1DF76000-class (~502MB, BELOW 0x20000000).
- swap dance (→arcade→360, swaps #3/#4 CLEAN: slot resets 385→1/293→1, 0 VK fails — today's
  renderer fixes hold under attended play).
- 360 ENTRY #2 post-swap-#4: **title screen renders BLACK but the game is ALIVE — START opens
  the menu instantly.** THE BETA1 "4TH-SWAP HANG" WAS TWO STACKED DEFECTS: renderer slot
  exhaustion (FIXED today) + this black-rendered title (user can't see → presumes hang).
  gemsg frozen at title is NORMAL idle; [modegate] gate=CLOSED = not a wedge, just no input.
- Shot select ENTRY #2: GREY-NOISE plates (user's exact screenshot reproduced under
  instruments). **Bake STILL FIRES (1605 page resolves post-swap!) — but page textures now
  allocate at 0x24320000/0x24420000/0x245A0000/0x24620000 = ABOVE 0x20000000** (heap grew
  across module sessions). Resolve entries get created at the RAW high addresses while the
  strip FETCH side resolves through the physical mask (&0x1FFFFFFF, as hardware does
  UNIFORMLY) ⇒ fetch key 0x043xxxxx misses the 0x243xxxxx entry ⇒ sampler decodes UNRELATED
  guest RAM at the masked address = the grey noise. Same identity break = black title pane.
**⇒ THE FIX SPEC (small, register-true): apply the physical mask (&0x1FFFFFFF) UNIFORMLY to
resolve-dest keys AND fetch-base keys in the executor (hardware's aliasing semantics; renderer
precedent at vk_render.cpp:9332 TranslatePhysical note). Retires: post-swap select staleness,
black title, grey plates, and likely the "fine first N times" whole class. NEEDS: the swap-
bounce gate + fresh-boot oracle + attended eyes (alias collisions hardware also has must
still behave).** ⚠ ALSO REFUTED today: "bake never executes" (08-03) — it executes; the
08-03 zero-page measurements were post-swap sessions in the high-heap regime. RVK_RES100 was
a DIFFERENT resolve class (default off, correct); KEEPRES refuted; RTHIGH default-off pending
the same mask fix (it's the RENDER-TARGET face of the same identity problem).
Screen-control recipe banked: request_access needs "futari_combined.exe" (with .exe); taps
can miss the per-frame GetAsyncKeyState poll — hold_key 0.25s is reliable; Z=A X=B Enter=START.
⚠ NEW BUG (bankable, separate): RT_PAD=1 synthetic pad without RT_NAV_SEQ auto-drives into a
FROZEN mode select on boot (gate=CLOSED, timer stuck) — drive lever, keep out of interactive envs.

## 2026-08-04 AFTERNOON — REVIEW BATCH 2 LANDED (`e77aaa3`/`cd08e43`/`15d9ad8`), gates re-PASS
(swapbounce 6 swaps + G1 gemsg=26 after the batch). All levered/verified:
- **ATOMIC SAVES (E18)**: truncating content-path opens → `<path>.tmp`, NtClose flush+_commit+
  rename. **POSITIVE-CONTROLLED**: empty-mount boot routed the disp=5 create through .tmp,
  `[file] atomic save published` fired, final file present, no orphan tmp. RT_SAVEATOMIC=0.
  ⚠ scripted attract/bounce drives NEVER write saves — a 0-count there is absence of exercise,
  not absence of function (checked before believing).
- **Out-param stubs**: XexGetModuleHandle writes *r4 + negative status on miss (was
  success+garbage-handle); RtlTimeToTimeFields real conversion; RT_XCFGTRACE moved to the
  LINK-WINNING ExGetXConfigSetting (out_reco/stubs.cpp) — was untraceable dead code.
- **Link landmines (C10/C11)**: 4 dead merged_game debug wrappers shadowing the nvk
  Resolve/Clear/slot taps DELETED; 3 dead rt.cpp voice probes DELETED (could never fire).
- **Races**: rt_ev lookup+insert one lock (lost-wakeup class); rt_xwma bank cache call_once;
  RT_S5/RT_STREAMCLASS probes now run on PPCContext COPIES (were clobbering live registers —
  any past finding made WITH those instruments active is suspect); per-handle unresolved-wait
  warns. Hot-path getenvs cached; JT/SPLIT tripwires flood-capped (kept loud).
- **VERIFIED (bounce log): real KeSetBasePriorityThread IS the link winner** (8 [prio] lines,
  0 __imp__ form) — the 08-02 priority fix is live in ship; strike the verification item.
⏭ STILL OPEN on the board: NtCreateSemaphore real-arm default (needs user EARS), register
shadow/queued-RwJob staleness (needs user swap-dance A/B), NtClose non-file object cleanup +
module ownership, ObReferenceObjectByHandle, remaining D-table stubs, resolve dim-change slot
orphan (vk_render.cpp:2536 class — the remaining RSS feeder inside one session).

## 2026-08-04 — ★★★★★★ STABILITY REVIEW → 4TH-SWAP HANG CLOSED (gate: 6 swaps clean) + RESOLVE
## FLAG SEMANTICS + HIGH-HEAP RT GUARD. Board: CODE_REVIEW_0804.md. Gate: swapbounce_gate.sh.
**THE HANG WAS A CONVERGENCE — three verified authors, all at/around swap #4:**
1. **Bindless slot exhaustion** (vk_render): `g.rNextTexIndex` monotonic, never capped vs 1024,
   never reset — swap cleared the MAPS so ~180-240 fresh slots burned per module session
   (hang log: idx 931 right before swap #4's burst). FIX: invalidation service moved OUT of
   getTexIndexReal (mid-frame, dangled curRT) to FRAME BOUNDARIES (rvkServiceInvalidations);
   on swap: vkDeviceWaitIdle → DESTROY dropped objects (texCache/resolveTex/nvkRT/rTexRecords —
   closes the RSS staircase too) → allocator reset to 1 → white texture rebuilt in place.
   Levers: RVK_SWAPDESTROY=0 legacy leak-and-climb; RVK_SWAPKEEPRES still honored (forces
   legacy path — kept entries keep their slots).
2. **Thread table exhaustion** (out_reco/rt.cpp): g_thr[16] slots NEVER freed; 7 shell + 2 game
   per attach ⇒ #4's create failed writing NEITHER out-param (hang log: 18 creates / 16 STARTs
   — the async job worker never started). FIX: slots recycle on thread exit/terminate
   (mutex-serialised), failure path writes 0 to both out-params + screams, table 32
   (handle/tid ranges follow). Lever: RT_THREADRECYCLE=0.
3. **In-flight cmd-buffer reset**: getOrCreateResolveTex + getNvkRT were the ONLY two submit
   sites skipping rvkRingNext — resetting a cmd buf/fence a deferred pass left pending on that
   slot (bursts on swap when all targets recreate; occasional in normal play = partially-landed
   draws). FIX: both rotate the ring now.
   + DIE-LOUD funnel (rvkVkResultCheck): submit results were ignored at 3 sites then fence-
   waited 5-10s; VK_TIMEOUT swallowed everywhere (ringNext cleared pending on timeout!); present
   ate DEVICE_LOST silently. All route loud now; DEVICE_LOST → rvkVkFatal (RVK_DIEHARD honored).
   + SWAP GUARD (A5): registry switch steps 3-6 + bridge section re-image hold g_mtx (taken
   AFTER the ack wait — the worker needs g_mtx to ack). The ack still times out ~every swap
   (presents pause during swap) — the LOCK is the real synchronization now.
**GATE swapbounce_gate.sh: 6 arcade↔360 swaps in one session — PASS** (slot resets logged
236→1,221→1,221→1,181→1,181→1 = the >1000 cumulative that killed beta1; creates==STARTs 18/18;
renderer submitting after swap #6; zero VK failures). G1 fresh-boot PASS (gemsg=26 control).
**P6 DISCOVERY (bounce made it visible): HIGH-HEAP RT GUARD.** nvk_on_setrt's wild-pointer
guard capped surf at 0x20000000 — but the guest heap legitimately crosses 512MB (user real-play
544MB; bounce sessions past 0x24000000). A D3D surface STRUCT up there read dims 0x0 ⇒ getNvkRT
declined ⇒ draws fell to the display target (1501 hits/session) = a live "random glitching"
author in ANY long session, and the same high-heap regime the ranking-box hunts needed.
FIX: bound widened to 0x80000000 (CPU struct pointer, flat-mapped — NO masking). RVK_RTHIGH=0.
**RESOLVE FLAG SEMANTICS (review B8/B9, XDK d3d9types.h:222 PROOF):** 0x100 =
CLEARRENDERTARGET "clear AFTER resolving" — recorder DROPPED those resolves entirely
("setup-only" misread; guest body copies unconditionally, 0x100 only ADDS a clear); clearAfter
was keyed on 0x200 (the DEPTH flag); clear colour read from r1+0x64 = arg11 pParameters (game)
/ hardcoded 0 (shell) — pClearColor is R10, a POINTER to D3DVECTOR4 (4 BE floats), packed via
new nvk_pack_cc (ABI regenerated). ⇒ PRIME SUSPECT for the six never-baked 512x512 pages /
water banner (a scroll-cache bake = resolve+clear-for-next-strip is exactly a 0x100 resolve).
Levers: RVK_RES100=0 (flag semantics), RT_NVKCC=0 (colour source). ⚠ AWAITING USER EYES on
char-select + Score Attack — scripted gates prove boot/logic, not visuals.
⚠ RESIDUALS BANKED (review board C/D/E): register shadow not reset on swap (KEEPRES-debate
class); queued RwJobs walk re-imaged memory (mitigated by guard, not versioned); NtClose leaks
non-file objects; ExTerminateThread orphans held locks; saves truncate-in-place (E18 — fix
before beta2 ships); link-order landmines C10-C12 (dead wrappers shadow renderer taps; dead
instruments RT_VOICESTART*/RT_XCFGTRACE); out-param stub table D13-D17.

## 2026-08-03 (very late) — ⚠ RENDER-WORKER HANG ON 4th HOT-SWAP (user repro; NEW TOP ITEM)
Repeated arcade↔360 bouncing froze the combined exe (user closed the window; no WER record, no
[SIGNAL] — process ALIVE, guest+audio heartbeats to log end ⇒ RENDERER hung, not a crash).
Evidence (futari_beta1_20260803_201252.log): swaps #1-3 complete normally (req → "NOT
acknowledged within 400ms" → [swapinv] MODULE SWAP on next renderer frame; resolveTex 185-189
dropped each, VkImages leaked by design). **req#4 at line 12246: warning fires, renderer never
runs another frame; ~236 lines of guest/audio heartbeats then end.** G2b only ever gated ONE
swap cycle. Suspects: swap-path wedge on the render worker (leak accumulation? fence/layout
after 3 drops?) vs my resolve blit changes racing a swap. NOTE ALSO: user's earlier broken
360-select screenshot likely = POST-SWAP staleness (fresh-boot 360 select "looks great" per
user + capture frame1225; pane target double-creation in the 20:06 log = swap signature) —
possibly the same family. Audio rms=0.0000 through that session tail = secondary oddity, bank.
⏭ Repro is scriptable (FIFO can bounce modes); hunt = instrument the render worker around
swapinv req#4 (where does it block?). BETA1 DECISION: ship with "repeated mode-swaps may hang
after several bounces — restart the app" known issue, or hold for this hunt.

## 2026-08-03 — REPO HYGIENE for GitHub backup (`dd583b8`) — READ BEFORE ANY PUSH
Tip cleaned: dist/ (packaged builds CONTAIN GAME ASSETS), *.exe/dll/lib/map/zip,
out_reco_abn/ppc_recomp gen (now matches out_reco policy), _tmpscripts blobs (.s/.npy/.wav/.csv)
untracked + ignored; tracked payload 2.1GB → 86MB; old root experiment exes → _snapshots/oldbuilds.
⚠⚠ **HISTORY IS NOT CLEAN: .git = 4.8GB, dist zips (asset-bearing) committed at alpha-1 (68d682f);
514 commits. Raw assets/ and *.xex NEVER entered history (verified) but the zips embed assets.
A push of this repo's history uploads game assets. When backing up: EITHER fresh-history mirror
(orphan/new repo from the clean tip — recommended, keeps local history intact) OR git filter-repo
strip of dist/*.zip + *.exe + ppc_recomp gen before push. REPO MUST BE PRIVATE either way.**

## 2026-08-03 (v.late) — ★★ WATER BANNER ROOT FIX: WRONG REGISTER IN THE GAME RESOLVE HOOK (r10→r5)
**The whole chain, closed by READING THE XDK LIB:** reference 512-page dumps showed the pages
hold PANE-REGION COMPOSITES in the SDK too ⇒ the six pages = the select screen's SCROLL CACHE
(draw fresh strip → resolve pane→page → paste pages as strips). Our pre-resolve dump: fresh
content lands at pane x>512, but our executor resolves (0,0)-(512,512) — the fresh strip
EXCLUDED ⇒ every paste serves stale content at the scroll edge = the band. WHY was our window
wrong: **XDK 20209.3 d3d9.lib → resolve.obj (Xenon COFF; llvm rejects it — hand-parsed with
python: machine 0x1F2, symbols at C:/Users/shant/Desktop/projects/_tools/xdk/xdk20209/libx) → D3DDevice_ResolveEx (0x1150 bytes,
sec 220) decompiled via Ghidra raw import (C:/Users/shant/Desktop/projects/_tools/xdk/xdk20209/resolveex_dec.txt, run_resex.bat).**
Signature truth: pSourceRect = **R5** (pDevice r3, Flags r4, R5=rect, r6=destTex, r7=destPoint,
r10=pClearColor). Semantics: src rect = EDRAM window in screen coords; dest base back-computed
from (destPoint − src.origin); NULL rect defaults from DEST SURFACE dims. **Our game hook
(nvk_game_hooks.cpp sub_8807DD88) passed ctx.r10 as pSrcRect — the CLEAR-COLOR pointer — so
every GAME resolve decoded pRect=NULL.** Shell hook (820A2280) always read r5 correctly = why
only ROM screens showed the class. FIX = one word (r10→r5) + comment; gate running.
⚠ NOTE executor still ignores destPoint (r7) — fine while destPoint=0 (static default), banked
as a residual for a rainy day. Instruments added this leg: RVK_RESLOG (entry-altitude resolve
log + 512-seg batch census), RVK_STRIPLOG pane-copy filter, zscan 512x512 gate.

## 2026-08-03 (later night) — WATER BANNER RE-VERDICT: NOT a sampler bug — AN UNWRITTEN PAGE
**RVK_TFCLAMP was register-true but did NOT fix the user's banner ("water banner still shows
up").** Evidence chain that got to the truth:
1. RVK_STRIPLOG (new, gated): 4000 opaque strip-copies at the select screens = SIX 512x512 fmt3
   backdrop pages drawn every frame, **ZERO out-of-bounds UVs** ⇒ addressing theory DEAD.
   (First run burned its cap on shell pane copies — filter 1280x720/640x512 fmt6 out.)
2. RVK_RAWDUMP2=0x08D60000 across 3 pan cycles: **8/8 dumps md5-IDENTICAL and 100.0% ZERO
   BYTES — the page is NEVER WRITTEN.** fmt3 zeros = colorkey-transparent ⇒ wherever that
   page's column draws, the LAYER BEHIND shows through: water layer behind = "water banner";
   nothing behind = the black variant. Explains "been around forever", periodicity (empty
   column enters view at wrap phases), both modes.
**⇒ The defect is a MISSING PAGE WRITER (streaming), not rendering.** Suspect family: the
kernel-stub class (35/47 imports write no out-param — an async stream completion never
signaled?), or a GPU-blt/DMA copy we don't emulate. Next: zscan census (widened to 512x512,
run8) for all six pages' zero-ratios + fill-in behavior; then hunt the intended writer via
ATLAS streaming/loader subsystem + stub audit cross-reference.
**beta1 decision point:** two fixes banked (RVK_TFW user-confirmed; RVK_TFCLAMP register-true,
harmless, kept), banner = pre-existing cosmetic on select screens with a now-known deep cause.
Options: ship beta1 with it as a documented known issue, or hold for the streaming hunt.
**FINAL REFRAME (run9, striplog res column + resolve log): all six pages ARE resolve targets
with res=1 — BUT the entries are created AT FIRST SAMPLE (black-cleared, everRendered=false;
[rvk][resolve] creation lines land the same frame as the first strip fetch, f6529). ⇒ THE
GUEST'S BAKE PASS (render scenery INTO the six 512x512 pages, then fetch as fmt3 textures)
NEVER EXECUTES on our port.** Downstream fully explained: RESREAL skips never-rendered →
RESALIAS stamps the nearest RENDERED 512x512 sibling into every column (pages sit 0x80000
apart, all within the ±1MB alias radius) = WATER EVERYWHERE variant; no rendered sibling =
BLACK variant. Also noted: strips misclassified as vs47 SELF-COMPOSITE (NEAREST snap — benign);
targets created vkfmt=37 RGBA8 vs fmt3 fetch (moot until the bake runs). ⏭ NEXT LEG: find the
bake — is it (a) an RB_COPY mode our PM4 decode drops, (b) draws into a 512x512 RT our nvk
never opens as a render target, or (c) an earlier-boot pass before renderer-up? Start: log RT
opens + RB_COPY dsts at select-screen entry; diff against the six bases; SDK ref capture
frame2759 has the authored bake output for content comparison.

## 2026-08-03 (late night) — CHAR-SELECT "WATER BANNER" (last beta1 item, user-captured both sides)
User F12'd the moment on BOTH engines (C:/tmp/rdc_user frames 1182/1228/1265/1348 + rdc_ref
2737/2759/2784, 14:11). **frame1228 vs sdk_frame2759 = SAME screen, SAME timer (58): ours fills
the pane's top band (behind/beside the Character Select title) with a BRIGHT-CYAN water-surface
texture (left) + BLACK rectangle (right); the reference continues the waterfall scene seamlessly
through that band.** Earlier live-session scan (tmpburst, python band metric): the band content
CYCLES with the backdrop pan (~13s period teal→green) — i.e. the top SEGMENT of the scrolling
backdrop compose picks a WRONG SOURCE (water page / black) at some pan phases. Suspect class:
segment addressing in the pane backdrop (seg-transform ladder). NOT an RVK_TFW regression (user:
"been around forever"). Hunt: rdc_bandauthor.py walks frame1228 counting bright-cyan pixels per
draw on the 640x512/1280x720 RTs → names the band's author draw. ⚠ combined exe has 3 swapchain
images — bb0 may be blank; check bb1/bb2 (banner thumbs lesson).

## 2026-08-03 (night) — BOX AUTHOR FOUND: EID 344 (additive GLOW draw) + RT-ALPHA RECT
**User delivered 13 SDK reference captures** (C:/tmp/rdc_ref, D3D12 driver — the SDK PC build
IS capturable; thumbs in C:/tmp/rdc_ref_out identify ranking frames; frame2344 = plaque on
water = answer-key frame).
**The unexploited lead was our own bandwalk (EID 344 step -120.96, never imaged).** Imaged it:
- ⚠ INSTRUMENT LESSON: RenderDoc PNG SaveTexture composites ALPHA — the "white rects" in RGB
  PNGs are really ALPHA≈0/low regions rendered white. Always dump channelExtract=3 beside RGB.
- EID 339 = the innocent vs45/ps50 shadow class (blend Zero/InvSrcCol, 6 quads) — confirmed live.
- **EID 344 = THE BOX AUTHOR: 4 quads, blend SrcAlpha/One (ADDITIVE GLOW pass), paints the pale
  silhouette PLUS a pale RECTANGLE (texture margins carry RGB+alpha) AND stamps a uniform
  ALPHA≈0.55 RECT into the modulate RT (rtA_344/rtA_1531.png)** — the alpha rect survives to
  end of frame around the silhouette. Box = additive pale wash + compose seeing the alpha rect
  (dark on water, invisible on green — matches user report exactly).
- GetUsage can NOT name bindless textures (descriptor array ⇒ no per-draw attribution). Naming
  lane = our own draw census (RVK_DRAWCENSUS/glow census) on a live attract run, not RenderDoc.
**Verdict pass running (alphaverdict.txt): does the REFERENCE RT also carry the alpha rect
(⇒ our compose wrongly honours alpha — note createRealPipeline blendReg==0 fallback =
SrcAlpha/InvSrcAlpha, NOT opaque) or not (⇒ our alpha decode/asset margins wrong for 344)?**
XDK 20209.3 extracted: d3d9/d3d9i/d3d9d/d3dx9.lib + 292 headers at C:/Users/shant/Desktop/projects/_tools/xdk/xdk20209/extracted.

## 2026-08-03 (night, cont.) — ★★ ROOT CAUSE NAMED + FIX BUILT: IGNORED FETCH-SWIZZLE W←1 (RVK_TFW)
**Chain, fully measured:**
1. alphaverdict: our EID 344 blend (2 consistent reads) = color AND alpha SrcAlpha/One; frame
   tail = 12 compose quads onto swapchain at SrcAlpha/InvSrcAlpha (REAL decoded reg — not the
   blendReg==0 fallback, which is One/InvSrcAlpha on alpha). **REFERENCE r552 pane alpha =
   UNIFORM 1.0 (refrt_r552_A.png): no rect, no silhouette.**
2. TFALL attract census (/c/tmp/tfall_attract.log, 130 uniques; NOTE its printed swz column is
   MISDECODED — tf3&0xFFF instead of (tf3>>1)&0xFFF, ignore it): ROM plaque draws are ALL
   vs45/ps50 over 256x256 fmt3 pages, one page per plaque element, blends 07060706 / 01060106
   (glow) / 05000500 (shadow) / 04000400 / 07010701 — the CLASS is one shader pair + blend reg
   variety. Atlas fetches swizzle {Z,Y,X,W}. **The pane fetches — ROM 640x512 self-composite
   (vs47/ps46 blend 00010001 OPAQUE), shell 1280x720 pane (vs17/ps16), all fmt54 movie frames —
   carry tf3 swizzle {Z,Y,X,1}: HARDWARE FORCES SAMPLED ALPHA TO 1.** We ignore fetch swizzles
   (old line-3146 confession) ⇒ ps50's authentic EDRAM alpha scratch (oC0.w = texel.a*c15.x+c15.y
   over the whole glow quad, margins included) rode the resolve → pane → shell SrcAlpha/InvSrcAlpha
   blend = the TRANSPARENT BOX. (User's own framing was right: "less a shadow, more a transparent
   box".)
**FIX (register-true, minimal):** honor DEST-W select == constant-1 only. resolveIdxA1() makes a
lazy sibling VkImageView (components.a=ONE) + bindless slot per ResolveTex; getTexIndexReal takes
tf3, routes exact/alias resolve hits through it when ((tf3>>1)&0xFFF)>>9 == 5. RGB selects stay
baked in decode (honoring them again would double-swizzle). Atlas fetches (W=W) byte-identical.
Lever RVK_TFW=0 reverts. Both call sites (nvk d.tf[3], walk tf[3]) pass it. Swap-leak policy
unchanged (viewA1 leaks with its image, per [swapinv] design).
⏭ verify_tfw.sh gate running (attract snaps); then combined-arm rebuild + user eyeball + beta1
repackage. ⚠ Blast radius = every pane/movie fetch (menus, gameplay pane, title movie) — the
snaps must check those too, not just ranking.

## 2026-08-03 (later) — SHADOW: RAW BYTES + FRESH DECODE EXONERATED; pivot to REFERENCE CAPTURE
**[shbase]/[shtexcensus]/[shtex] (RVK_SHTEXAUTO auto-targeting — use THIS, not RVK_TEXRECT: the
page base MOVES per session, 0x10A4D000 vs 0x10DDD000):** shadow class = ONE 256x256 fmt3 page,
tf3 swizzle 0x60A = the standard {Z,Y,X,W} net-cancel (bit0 of tf3 is num_format — decode
swizzle as (tf3>>1)&0xFFF; my first read forgot this). **DECISIVE DUMP: raw guest bytes are the
CORRECT silhouette** (rawA0 texels 100% RGB-zero, blend multiplier 1.0 = invisible; margins
opaque-black; only the authored shape darkens) — and the analyser's forced fresh decode DID NOT
remove the box (user: "stayed the whole time"). ⇒ raw content, decode, swizzle, constants,
alpha-test, blend of the vs45/ps50 class ALL measured correct ⇒ **the box author is most
likely NOT the shadow-class draw at all** — the round-1 pixel-history candidates (EID 452/524)
were never trustworthy (flaky). STOP single-renderer forensics.
**⏭ THE NEW LANE (user-directed research): RenderDoc THE REFERENCE BUILD** — the SDK exe is a
capturable PC renderer running the same guest code and drawing the shadow correctly. Launcher
ready: Desktop "Futari SDK REF - RDC.cmd" (runtime injection, D:\ referee untouched). Diff its
ranking draw list vs ours = names the divergence with zero theories. ALSO: era-matched XDK
20209.3 now COMPLETE on the share (1.19GB setup + 330MB recovery-WITH-SYMBOLS) — copying to
C:/Users/shant/Desktop/projects/_tools/xdk/xdk20209 for the naming lane (graphics libs + symbols).
## 2026-08-03 — RANKING-SHADOW RDC LEG (evidence banked; theories 3+4 refuted; NEXT = 2-run matrix)
**Session rig:** "Futari COMBINED - RDC.cmd" (renderdoccmd wrap + RVK_RDCCAP self-capture) = the
keeper glitch-capture workflow. 32 captures banked C:/tmp/rdc_user (ranking visits both modes +
user F12s of the SWAP FLASH: frames 3457/3483/3546 = center pane solid black mid-transition).
**SHADOW EVIDENCE (capture frame1351 + live logs):**
- The box = rectangular wash hugging each plaque quad; user: obvious on WATER, invisible on
  foliage. EXPLAINED BY THE CONSTANTS: shadow class = vs45/ps50 blend 0x05000500
  (dst *= 1 - src*c14), c14={0.3765 grey} ⇒ magenta-margin texels multiply (R,G,B) by
  (0.62,0.96,0.66) — green untouched ⇒ water shows it, foliage hides it. c15.x ramps
  0.03→1.0 = the plaque fade-in (matches [shtexiso] lines in the user's own beta logs).
- Plaque atlas (capture r7917-class, guest 0x134E8000-era): margins = MAGENTA colorkey pixels,
  decoded A=255 on BOTH margins AND art (a=0 only on pure-black regions) ⇒ TEXTURE ALPHA CANNOT
  discriminate; [nvkat] proves the vs45/ps50 class runs WITH alpha test en=1 func=GREATER ref=0
  (athresh 0.002) on nvk — correctly emulated, kills nothing (all w>0).
- ⇒ REFUTED TODAY: (3) blend-aware placeholder as the shadow cause (shadow persists both modes
  after 648c7dd; the flash recolored white→black = flash IS the placeholder draw, but shadow is
  NOT); (4) alpha-test state divergence nvk-vs-old (nvkat shows correct state). Earlier-refuted
  and NOT to be resurrected: FMT16TRUE bit-0 alpha (scrambles terrain; bit15 IS alpha).
**⏭ NEXT (no more theories — the 2-run user matrix):** (a) FRESH-BOOT arcade, NO swap, nvk →
ranking: box? (b) same fresh-boot, OLD renderer (RT_NVK unset) → box? Pins the axis:
swap-scoped (stale-heap family) vs renderer-scoped (old-vs-nvk pair diff applies) vs always
(possibly AUTHENTIC — then Xenia referee decides before any fix). User's original datapoint
"only on 360 mode, now arcade too" came from SWAPPED sessions — fresh-boot discriminates.
**⚠ RDC TOOL LANDMINES (cost half this leg):** ResourceIds are NOT stable across replay
sessions (re-derive in-session); PixelHistory + GetPipelineState are FLAKY on this driver
(returned different results/empty across identical runs — trust only SetFrameEvent+
GetTextureData/SaveTexture); BANK output txt before rerunning a script (boxhunt run#1's
pixel-history detail was overwritten by run#2 that then returned empty). Deterministic
fallback that works: band-walk (per-draw GetTextureData luminance differential), bandwalk.py.
**FLASH (black now):** RVK_SWAPKEEPRES=1 tested by user — NO change ⇒ resolveTex-drop theory
refuted; the F12 flash captures (3457/3483/3546) are the next evidence when that hunt resumes.

## 2026-08-03 — ✅✅ COMBINED EXE G2b PASSED ATTENDED (user: "worked! both modes load and play in one exe.")
Rebuilt the combined lane fresh (it was 07-31-stale, pre music/tid/SDL fixes): ABI gap closed —
`rt_audio_stage_play_volume` added to tools/gen_host_abi.py HELPERS (the round-5 per-play-volume
helper the game module now references). G1+G5 re-PASSED on the fresh build (gemsg=26 crash=0,
audio parity exact). G2b attended: modswap #1 -> reco_normal, in-ROM quit -> RT_REATTACH
re-image, **modswap #2 -> reco_abnormal via RT_GAME_ROOT/media/Module/ (the shipped layout)**,
both modes played (gemsg=62), zero faults. First run failed on MY launcher omitting
RT_GAME_ROOT (env-clone filtered the %HERE% line) — ladder path 2 masked it for reco_normal
(root xex) but not reco_abnormal; fixed, and the die-loud reattach FATAL did its job.
**⇒ THE COMBINED 3-FILE PACKAGE (futari_combined.exe + 2 module DLLs + assets) IS NOW THE
BETA1 SHIP CANDIDATE; the two per-mode exes drop to fallback.** Desktop launcher kept:
"Futari COMBINED - G2b test.cmd". Remaining beta1 board: ranking-plaque shadow ONLY.

## 2026-08-03 — ✅ PAUSE FIXED (user: "pause works now, freezes and resumes properly!")
Never worked in ANY deployed build (user confirmed). Cause: `RT_NOPAUSE=1` shipped in both
alpha bats + playtest.sh — a 07-23 sequencer-era spin-breaker that force-clears the game's
pause flag 0x887AD534 every frame (two hook sites: fb90 entry + the sub_821C5618 [cb2gate]
in-spin clear, both env-gated), so START summoned the shell menu while the ROM kept simulating.
Pause flow (proven): shell msg 10 arg=1 -> 534=1 -> fb90 holds = frozen; resume = msg 10 arg=0.
Gate: scripted boot->attract clean with lever off (zero [nopause] clears needed — the 07-23
hang it papered over is long fixed). Removed from dist bats + Desktop bats + playtest.sh
(`3d090f6`); drive scripts still set it themselves. SHIP-CONFIG LESSON (3rd instance of the
class after RT_CATVOL=0 and RT_AUDIOGAIN=0.8): audit every `set RT_*` in ship bats against
"is this a drive lever?" before beta1.

## 2026-08-03 — ✅ USER EAR VERDICTS: "shots sound right" + "desktop alpha seems good now"
Tid-fix pair DEPLOYED to Desktop/futari_alpha1a (md5-verified; old pair backed up at
dist/futari_alpha1a/_known_good_0802_music/). The transient "music lags/stutters" report was
NOT reproduced: (a) fix-on/fix-off guest renders have IDENTICAL gap structure (wav_gaps.py,
new keeper in _tmpscripts/), (b) the report window coincided with scripted A/B drives that
force-kill futari_merged and grab the audio device while the user was playing — prime suspect.
⚠ Drive-era drift: shotlevel_menu_port.sh no longer produces menu music AT ALL (0 nonzero
meter samples both arms) — do not use it as a music instrument until re-validated.

## 2026-08-04(session dated 08-02) — ★★★ SHOT-SFX GHOST ROOT CAUSE FOUND AND FIXED: DUPLICATE THREAD IDS
**THE BUG (rt.cpp:234, both arms): every guest thread's KTHREAD+0x14C was hardcoded 1.**
XACT's apartment check (`FUN_82137B50`: `GetCurrentThreadId()==engineTid`, tid read via
PCR->0x100->0x14C by `FUN_8208DA10`) therefore passed on EVERY thread; every caller took the
mutate-engine-state-directly path concurrently, and retail 360 XACT's thread safety IS that
identity check (its critsec helpers are compiled empty; the async command queue exists
precisely so non-engine threads never touch engine state). Result: cross-thread use-after-free
on wave descriptors; a pool node (owner=0x36B250, self-linked flink/blink) is read as the loop
triple; `CXAudio2SourceVoice::SubmitPacket` (FUN_8210D8A8) faithfully converts it, the wave
feeder sees loopCount=0x36B2xx (a pointer = 3.5M) and a 75ms one-shot grain re-serves forever
⇒ the ringing ghost voices ⇒ the +16dB shot SFX the user reported vs the SDK.
**FIX: unique per-thread ids `0x30+idx` (matches ExCreateThread's existing tid_out), main
thread keeps 1. Lever RT_TIDUNIQ=0 reverts. Both arms.**
**ACCEPTANCE (same-day digital A/B, attract drive, meterlog):** demo p50 0.486/0.489/0.472/
0.501 (bug) → **0.05803/0.09146/0.05650/0.07206 (fix)** vs reference 0.05808/0.08612/0.05576/
0.06828 — match within fractions of a dB; two segments match to the 4th decimal. The stubborn
2.3s/4.1s "VOICE 2.5x" segments ALSO fell to reference (0.14008→0.05691 = ref exactly) — ghosts
too. [psel] LOOPED collapsed thousands → 9 (stops now execute and kill the rare dirty voice).
**THE HUNT (rounds 21-25, one session, all committed):** enqueue probe [pktenq] → guard page
caught the packet fill = memcpy in client SubmitSourceBuffer FUN_82137D60 (slots this+0x1C/
+0x58, op-5/6 commands) → [srcbuf] lr=0x8210D9F4 = SubmitPacket, builds XAUDIO2_BUFFER from
XACTVoicePacket, garbage enters as vp loop fields → [xvpkt] lr=0x820FE8C4 = FUN_820FE7D8,
fill=FUN_820FE490 fully deterministic, garbage in the r4 WAVE DESCRIPTOR → [wdesc]+[race]
snapshot: descriptor CLEAN at wrapped entries yet dirty packets emitted ⇒ instrument fog (see
landmine below) ⇒ pivoted to the apartment-check decomp + rt.cpp audit ⇒ the tid.
**⚠ OPEN (research, not beta-blocking): 21 DIRTY-VP packets still form per attract** (stale/
freed descriptor read somewhere); with working thread identity they are stopped before
audibility (9 looped renders total). Find the descriptor owner when tokens allow.
**⚠ NEW LANDMINE — PPC_FUNC WRAPPER CLONE BYPASS:** some invocations of a shell function do
NOT pass through its PPC_FUNC wrapper (a /FORCE:MULTIPLE moduleshim link-winner clone is
reachable from some call sites). Proven by [wdesc] never seeing the garbage descriptor that
[xvpkt] provably consumed one call later. Retro-explains round-16 "[submit] printed ZERO
lines". Every past "wrapper printed nothing ⇒ path not taken" conclusion is UNSAFE.
**Decomp assets landed (ghidra_futari_decomp/):** enqueue_addtail.txt (AddTail=FUN_8214FC18,
SubmitPacket client=FUN_821500D0), cmdbuilder.txt (client ctor FUN_82137CE8, 2 inline packet
slots), submitsrc.txt (SubmitSourceBuffer decomp), producer.txt/writer.txt (SubmitPacket +
packet fill), aptcheck.txt (FUN_82137B50 apartment check + FUN_8208DA10 tid read), plus
/MAP relink recipe validated (fresh map C:/tmp/futari_cur.map; stale-map symbolication of
guard hits was WRONG — always relink after instrument churn).

USER DIRECTIVE (2026-07-28): "remember our goals. decomp - recomp. if we need to stop and
decompile the whole game/translate it then we will..." → morning: "PIVOT." Campaign plan =
wf_1fe5ad0b (C0..C9, full text in the session tasks dir; summarized in
[[futari-fnf-beta-goal]] memory). Governing docs: ghidra_futari_decomp/
HUMAN_READABLE_DECOMP_PLAN.md (conventions, status ladder), decomp/registry.toml (the census),
decomp/README.md. Rules: no new renderer heuristics/levers; no flicker forensics (glass truth
banked, C3 moots it); no eyeball acceptance; every conversion behind a texel/behavior gate.

## 2026-07-28 — C0 DONE (substrate durability), C1 IN FLIGHT (pilot gate pending)

**C0 (commits: xr-derisk 8c2feaa; xr-work c8b0f58):**
- xr-derisk (eqv-fixed XenonRecomp checkout) git-initialized: 1294 files. Vendoring hygiene:
  6 stale submodule .git pointers stripped; libmspack cabextract symlinks materialized
  (NTFS-unindexable; the vendored thirdparty/.gitignore starts with `!*` — a negation that
  defeats root-level ignores, landmine for future vendoring).
- **XenosRecomp clone was LOST to a /c/tmp cleanup** — re-cloned from hedge-dev upstream,
  branch glvl-d3d9 pinned at be84413 (exact banked commit), vendored at
  futari_realcomp/tools/XenosRecomp; gen_xrgen.sh XR_SRC default repointed. (The regen-landmine
  class actually fired; C0's whole reason vindicated.)
- decomp/ scaffold: registry.toml 243/243 (139 game + 104 shell; ambiguities + a follow-up
  seeding list documented in the registry agent's report), README with the status ladder,
  build_win.sh compiles decomp/game/*.cpp + decomp/shell/*.cpp (NOT a decomp/*/*.cpp glob --
  game_abn/ is deliberately excluded) and links obj_win/decomp_*.o FIRST (first-def-wins).

**C1 pilot (decomp/game/game_entry_msgs.cpp + PILOT_NOTES.md):** GameEntry 0x8824E698
translated whole (all 20 cases) as PPC_FUNC_IMPL(__imp__sub_8824E698) — the only
shadowed-hook-safe seam: merged_xex.cpp owns the strong sub_8824E698 (= the [gemsg]/RT_MSGLOG
instrument the gate itself needs), so the pilot displaces the GENERATED body underneath it.
Pilot slice msgs 12/13/14 = 3-store semantics (mode64-arm / return-to-menu reload=1 /
credit-arm reload=2 gated on 0x887AD547). Atlas off-by-one found (msg 10/11 rows) — logged in
PILOT_NOTES §7, atlas not edited.

**C1 GATE (in progress):** drive = _tmpscripts/c1_gate.sh (FIFO-pad boot→START→play→B,B→quit;
press codes: START=10, A=1000, B=2000 — my first cut used 20 for B = wrong; bwedge-calibrated
hold/wait timings). Baseline run 1: 99 [gemsg]/[msglog] lines, msgs {1,2,5,6,7,8,9,10,11,15,
16,20} — but ZERO msg 12/13/14 (quit chain didn't land) and OUTER66a8=3 never seen (play entry
failed; msgs flowed via attract demo instead). ⚠ DETERMINISM CONTROL REQUIRED before trusting
byte-equality: two same-build runs of the same drive must produce identical sequences; run 2 in
flight. If nondeterministic → gate becomes per-msg count/semantics comparison + [q] state
snapshots, not raw byte-diff. msg13 live-fire fallback: the user's next quit-path playtest with
RT_MSGLOG armed.

## 2026-07-28 ~09:30 — ★★★★★★ C1 GATE PASS: FIRST MATCHED TRANSLATION (GameEntry 0x8824E698)

**The campaign's first translated function is live in the shipping binary and proven
behaviorally indistinguishable.** Gate history (each failure taught the method):

1. **Gate FAIL #1 (register-file class):** first pilot passed caller garbage in r30/r7-r11 at
   call boundaries; callees CONSUME incidental register state — a guest allocation shifted
   (2-line diff, heap pointer only). FIX = mirror the generated stream's register file wherever
   a bl can observe it (r30=0 + r11=msg at entry with save/restore; msg2 case = verbatim stream
   mirror). **RULE for all future translations: memory effects are NOT enough; the callee-visible
   register file at every call site is part of the contract.**
2. **Pointer-drift discovery:** the residual diff pre-dated GameEntry's first call by 1100+ log
   lines ⇒ exe-image geometry seeds early guest allocator state (host-derived). PROVEN by the
   control experiment: a generated-only rebuild (no pilot object) shows the SAME drift class vs
   the old baseline with ZERO translation difference. **RULE: raw pointer byte-equality can never
   gate across binaries; gates mask guest-heap pointer fields (canon(): 0x2xxxxx/0x3xxxxx/
   0x2xxxxxxx heap ranges → PTR).**
3. **PASS:** determinism control (same-build runs byte-identical) + control-vs-pilot RAW
   identical 41/42 lines, CANONICAL-identical 42/42. Coverage: msgs {1,2,5,6,7,8,9,11,15,20}
   incl. both complex cases (msg1 CONFIG-IN 96-byte copy; msg2 BOOT strcpy/memset/worker-spawn).
   msg 12/13/14 (3 trivial stores) live-fire pending on the user's next quit-path playtest with
   RT_MSGLOG armed.

Registry: 0x8824E698 GameEntry_Dispatch → **MATCHED**. Gate harness = _tmpscripts/c1_gate.sh v2
(no-press + RT_NAV_SEQ deterministic in-engine drive; v1 FIFO drive hung on tail-pipe stdout
inheritance — fixed with explicit </dev/null >/dev/null on the exe). build_win.sh: decomp/game/*.cpp + decomp/shell/*.cpp
compiled + obj_win/decomp_*.o linked FIRST (empty-glob-safe via $(ls ...)).

⏭ NEXT (C2, parallel-safe): Ghidra D3D-wrapper hook census (the decision gate for C3
guest-owned Present — the flicker-mooting altitude move). Then C3.

## 2026-07-28 ~09:50 — ★★★★★★ C2 DONE: WRAPPER-COMPLETE — C3 PROCEEDS AT API ALTITUDE

**Decision (wf_be2fc283, 3 independent closures):** (a) static shell — all 65 ring-writer
callers live inside the linked D3D block 0x82096B28-0x820B3000, Vd import band has zero
out-of-block callers; (b) static game — ZERO cross-module 0x82 calls in all 3960 game fns; the
game links a byte-identical SUBSET of the same D3D lib operating on the SHELL'S DEVICE (handed
over once at GameEntry msg 1 — reco:305000); (c) runtime — primary ring DEAD after boot, all
submission through exactly the two kick fns rt_kick_capture already owns. NO raw PM4 bypass
observed anywhere. **CP-emulation fallback: NOT indicated.**

**C3 hook table + minimal session-1 subset (★ rows): full table in the workflow verdict
(tasks/w3i1tfz8b.output) + ATLAS_d3d_wrapper.md (written by the census, incl. device layout,
game twin map, kick ABI correction r4=descriptor-array r5=COUNT len=word0&0xFFFFFF — the
current rt.cpp:1984 capture carries an accidental r6).** Residual risks C3 must own: (1) the
CreateDevice-time static PM4 blob 8209b180 (~48 DRAW_INDX_2) resubmitted via INDIRECT_BUFFER —
interpret at submission; (2) draw kernel 8209D800 returns an inline-vertex write pointer filled
AFTER return by 6 callers — deferred-write protocol; (3) movie/bank texel uploads are CPU
direct writes — dirty-range upload, not an API hook.

**Gap probes:** #1 ANSWERED inline (both Clear symbols live: sub_820A19F0 x2 callers,
sub_820A1218 x1 — outer/inner pair, hook both, inner translates). Remaining cheap probes
(#2 SDK enum xref, #3 LRBAND 8206bxxx boot, #4 one game-twin logging hook, #5 Present-alt
820A5A68 log grep, #6 8807A1E0 force-decomp) fold into C3 session 1's prep.

⏭ C3 SESSION 1 (staged): hook the ★ subset in a NEW seam (decomp/shell/d3d_hooks.cpp per the
campaign's decomp-tree convention — strong hooks must live shell-side per the link-order
landmine), feeding the EXISTING vk backend; Present = frame-mark; keep kick-capture running in
parallel as the A/B referee. Acceptance: glass_burst zero A/B/A alternation + field-oracle
texel gate + census clean + 59.9 held.

## 2026-07-28 ~10:30 — C3-s1 FIRST SWING: MISS (honest ledger) + the next named probe

**Clear-ordering fix landed but INERT (cleardefer fired 0x):** the "straddled tail resolve at
window head" reading of the roster was WRONG — segpos=1/2 means the empty front-buffer resolve
is the SECOND submit after a full content pass. Deeper dump shows the real shape: flash-class
frames carry a **DOUBLED front-buffer resolve** (r0 and r1 both dst=0x723000 at the SAME
batchIdx, zero draws between; cb65b=1). Code kept (never-silent counter documents the negative;
RVK_NOCLEARDEFER lever exists).

**⚠ [r5pix] SUSPECTED INSTRUMENT ARTIFACT (10th instance of the class):** nonclear counts
px != px[0] — a UNIFORMITY metric, not a content metric. The "low-content flash" modes
(12232/53615 px) line up with FADE frames (mostly-uniform screen). This retro-explains the
RESKEEP=3 user verdict ("same"): the suppressed blits were probably authentic uniform frames,
not flashes. r5pix conclusions DOWNGRADED to unverified pending a content-true re-measure.

**What stays REAL:** the GLASS A/B/A alternation (RenderDoc, artifact-checked — present N ≡ N-2
bit-identical mid-fade, decaying pair gap). **NEXT PROBE (named, direct, no theories):
command-stream diff of consecutive glass captures** — C:/tmp/glass_burst/*.rdc pairs (an
A-frame vs a B-frame): diff their action lists / bound state / constants via qrenderdoc python
(vbslots/deep85 patterns in C:/tmp/flicker are the working idiom). The differing draw/state
names the alternating compose source directly. Doubled-resolve datum likely related (two
front-buffer blits per frame = two content generations available to alternate between).

## 2026-07-28 ~11:00 — ★★★★★★ C3-s1: THE FLICKER'S VULKAN ANATOMY, CAPTURED IN FULL

**Stream-diff of glass captures f254-257 (glass_streamdiff.py, streams banked in
C:/tmp/glass_burst/stream_*.txt) names the mechanism outright:**
- f254 (A): renderpass(Clear+2 draws) -> blit -> present.
- f255 (B): NO COMPOSE — head blit, empty Load/Store pass (+ the r5pix readback), blit -> present.
- f256 (A): head blit -> renderpass(Clear+2 draws) -> blit -> present.
- f257: NO COMPOSE — two blits -> present.
**Every other present skips composition and re-blits; the re-present's source lags one compose
generation (hence present N ≡ N-2 bit-identical). On hardware a re-present shows the unchanged
front buffer (invisible); our re-present shows the PREVIOUS generation -> 30Hz shimmer on
anything animating = THE FLICKER.** The head blit appearing from f255 on (absent in f254's
stream) is the deferred publish of the previous compose — the publish chain
[compose->resolve-tex->g.image->swapchain] runs one present cycle late.

**FIX SCOPE (C3-s1 real deliverable, next leg):** single-cycle publish ordering — in one present
cycle: compose -> publish (resolve->g.image, vk_render.cpp:7326 display fork) -> window blit
(g.image->swapchain, :3606) -> present; empty presents re-blit the SAME g.image (unchanged =
correct hardware re-present semantics). Sites: rvkWindowPresent (:3560-3624, blitSrc selection
:3582-3584) + the walk's display-fork blit placement. Gate: glass_burst — zero N≡N-2 identity
mid-fade, adjacent diffs small+monotone; plus m2hold texel regression + census + 59.9.

(Session artifacts: clear-defer lever inert-but-kept; r5pix downgraded to uniformity-artifact
suspicion; doubled front-buffer resolve datum banked — likely the guest's own double-present
idiom, revisit under the fix.)

## 2026-07-28 ~11:40 — C3-s1 close: SHOW CHAIN EXONERATED AT SPEED; alternation localized to
## COMPOSE-BRANCH level; C4 confirmed as the structural fix

**[showseq] (new, RVK_SHOWSEQ=<from>): per-present shown-generation sequence at NATIVE speed =
age-1 FLAT, perfectly monotone through the fade window.** The publish/present chain does NOT
alternate generations at speed — the glass A/B/A generation-lag reading was exaggerated by
RenderDoc's ~8fps serialization (11th instrument-conditions lesson; the within-capture
artifact check validated capture-internal consistency, which does not transfer to native speed).

**What survives every instrument:** the compose OUTPUT PATH alternates per frame between two
branches — blitmap proof: empty-final-segment frames run 92(offscreen)->166(resolve-tex
refresh) while composed-final frames run 92->96(show publish); the branch choice rides the
f776 trailing-batch lottery (whether draws land after the window's last resolve). Two slightly
different pixel paths alternating at frame rate = shimmer on fades/ramps at ANY speed — the
one mechanism consistent with: draw census clean, r5pix uniformity artifact, glass alternation
under capture, showseq clean, RESKEEP no-change, and 3 failed spot-fixes.

**VERDICT: stop spot-fixing the branches — C4 (canonical compose path, compose 1:1 per
SPEC_shell_compose_1to1.md) IS the fix.** The compose must have ONE output path regardless of
segment/resolve ordering; that is exactly what the campaign's C4 leg builds on the C2/C3
altitude. Next session = C4 with the branch-alternation as its named acceptance target
(discriminating pre-check if desired: glass burst under RVK_DECOUPLE=0 and/or
RVK_LASTRTPRESENT=1 to pin one branch — predicted: pinning removes the shimmer class).
Session artifacts: [showseq] stays in-tree default-off; task #6 closed.

## 2026-07-28 ~12:10 — ★★★★★★ C4-s1 SHIPPED: CANONICAL SHELL COMPOSE PATH (the shimmer's
## structural fix) — GATES GREEN, USER PLAYTEST PENDING

**DIAGNOSIS SEALED at native speed ([cbranch] A/B):** old fork = 300 branch transitions /
3480 shell frames (~1 flip per 11-12 frames — the historic drawtrip-era anomaly cadence);
canonical = C 100%, transitions 0, zero errors.

**THE FIX:** on shell frames the final-composite fork (lastRt-empty vs normal vs re-render-all)
collapses to ONE call: submitSeg(b0, N, readback, LOAD) over the persistent-EDRAM offscreen —
provably identical to both old shell arms in their own domains (empty final: b0==N ≡ the old
lastRt arm; trailing batches ≡ the old normal arm); the segsElsewhere re-render-all arm retired
on shell (documented alpha-overdraw bug; empty-final-over-FIXB2-layers now = correct re-present
of the persisted compose). Field/ROM keep the historic fork bit-for-bit. RVK_NOCANON=1 reverts;
RVK_CBRANCH=1 = the branch census.

**GATES:** [cbranch] transitions 300→0 ✓; texel: all static-window pairs bit-identical, diffs
confined to the known cross-boot transition-offset class ✓; errors 0 ✓. **PENDING: user
playtest — the shimmer (press-start, logo, fades, circles) should be GONE or sharply reduced.
This is swing 4 on the flicker; the first one aimed at a per-frame-alternation mechanism
measured at native speed.**

## 2026-07-28 ~12:30 — C4-s1 FAILED USER ACCEPTANCE ("no, same same") = SWING 4. **USER CALLS
## HARD PIVOT.**

Four instrument-green fixes user-refuted in 24h: wait-path cluster, ghost-draw collapse,
RESKEEP=3, canonical compose. Each fixed a REAL measured defect; none touched the percept.
**Epistemic record, stated plainly: the perceived flicker has NEVER been captured by any
instrument in this arc (11 lying-instrument instances; the percept's ground truth remains the
user's eyes only).** Canonical compose STAYS (register-true, gate-proven, zero-transition
branch census — correct regardless of the percept).

**HARD PIVOT (user directive): the project stops treating the current merged runtime as a
patient.** Defect hunts on it CEASE. The bedtime directive's full form activates: whole-game
matching decomp→recomp — the C9 endgame pulled forward. vk_render.cpp + the window/capture
machinery become REFERENCE ONLY (and the old build remains the behavioral referee). The new
target rides everything this campaign banked: C1's translation machinery + gates, C2's
wrapper-complete verdict + hook table (ATLAS_d3d_wrapper.md), the compose SPEC, the kernel
parity lists. The GPU layer gets WRITTEN FRESH at the wrapper altitude — no PM4 walking, no
window inference, no persist heuristics: the defect class that ate this week has no home in it.

## 2026-07-28 ~12:50 — ★★★★★★ HARD PIVOT SESSION 1: NVK STAGE 0 LIVE — the new renderer's
## API trace captures the guest's D3D program cleanly

**decomp/shell/nvk.cpp (trace sink) + rt.cpp taps/hooks (RT_NVK=1, inert otherwise): 24 wrapper
functions traced.** First boot trace (C:/tmp/nvk_trace.log, 14.5MB, 1417 frames): per frame =
1x Clear (GAP #1 RESOLVED LIVE: callers enter 820A19F0 which falls into 820A1218 — hook both,
outer is the API entry) + ~1 Resolve + ~2 SetRenderTarget/Viewport/Scissor + ~23 draws + state
churn (~26 Src/DestBlend, ~24 SetTexture, ~7.7 SetVSConstantF). ABIs runtime-verified off the
trace: SetVSConstantF(r4=startReg, r5=ptr, r6=vec4Count); RS_* take r4=value with D3DBLEND
encodings (Src=6/Dest=7 = SRCALPHA/INVSRCALPHA); CullMode r4=4; SetScissor inline 720s.
8209AD40/AB80 called with (ptr,0x10,0x20,0,0x30) stream shapes — lane C's
SetStreamSource/SetVertexDeclaration reading favored; final identity falls out in stage 1 when
the translation consumes them. Two build lessons: ab80/ad40 already had rt.cpp hooks (tap, don't
re-hook); collision-check must include rt.cpp itself, not just merged_xex.

**STAGE 1 (next session): translate the traced boot-scene API to Vulkan** — implement the nvk
state block + direct draw translation for the CAVE-logo→M2→title call mix, reusing the existing
device/swapchain/texture-upload primitives; RT_NVK=2 = render mode; old renderer untouched as
referee. Acceptance = the user's eyes on the new output, scene by scene vs the D:\ SDK build.

## HARD PIVOT s2 (2026-07-28 ~13:3x) — nvk STAGE 1 FIRST LIGHT (4c373e8)
RT_NVK=2 renders the ENTIRE BOOT from wrapper calls alone — CAVE logo, M2 card, title +
press-start blink — and all three scenes are VISUALLY IDENTICAL to the old-renderer referee
(side-by-side PNG readbacks, C:/tmp/nvk_f*.png vs rvk_frame*.png; 0 errors, 0 unmatched
shaders, ~57fps avg). The old renderer never runs at RT_NVK=2 (Present short-circuit).
- Recorder decomp/shell/nvk.cpp: vertex bytes at DrawVerticesUP(8209DC98) ENTRY (r6; the
  deferred-scratch protocol is moot on the UP path) + REGISTER-TRUE device reads per draw:
  tex fetch const texObj+28.., PS obj dev+0x3244 / VS obj dev+0x3248 (labels swapped vs
  atlas — body evidence), RB_BLENDCONTROL0 dev+0x2938. SetVSConstantF -> banked c0..255
  snapshots; Clear at 19F0 (r7=ARGB; r8 is garbage, Z rides f1).
- Renderer = nvk section at BOTTOM of vk_render.cpp (anon-namespace linkage constraint):
  matchImLoad fed bound-object microcode (replaces IM_LOAD/PM4 entirely), bindless
  getTexIndexReal, getOrCreateRealPipeline, BDA arena, submitSeg idiom, single ordered
  pass with the guest clear colour, rvkWindowPresent. RT_NVKPNG=<N> readback dumps.
- Reading dev slots at draw time catches the INTERNAL bind path (public SetShader fires
  1/frame but IM_LOAD showed ~2 VS switches/frame — internal callers store to the same slots).
- SCOPE: shell/front-end only (all shell draws funnel DC98). Game-module (0x88) twins are
  NOT hooked yet -> gameplay playfield won't render at RT_NVK=2. Stage 2 = game-twin hooks
  (byte-identical lib subset, C2), DrawIndexed path, Resolve semantics for field compose.
- Recon dossiers (4-agent workflow wf_09d41cd7): scratchpad s1_{trace,vkprim,abi,shaders}.md
  — s1_abi.md §12 = consolidated 40+ device-offset table; keep with the atlas.
USER GATE: run `RT_NVK=2 bash _tmpscripts/playtest.sh` — judge boot/menus by eye vs D:\ SDK.

## HARD PIVOT s2 leg 2 (2026-07-28 ~12:00) — GAME-TWIN RECON (trace = ground truth)
14 game-twin taps live in decomp/game/nvk_game_hooks.cpp (decomp tree = link-first; rt.cpp CANNOT
hook 0x88 — it links after the game tree). 85s drive (boot->attract->TRAINING), 606MB trace:
- ★ GAME DRAW FLOW: SpriteEmit(1.36M) -> BatchQuadRectlist(735K) -> Begin/EndVertices(735K/732K,
  the streamed D800-core twin path). DrawPrimitiveUP fires only 1/frame — the field compose rect,
  paired 1:1:1 with SetRenderTarget(field surf 0x3754B0) + Resolve(->tex 0x3781E0 feedback).
- ★ THE SIMPLIFICATION: G_SetConstantPkt/G_FetchConstPkt args show src ptrs INSIDE the device
  object (0x354D34=dev+0x2934, 0x353B80=dev+0x1780 PS bank, reg bases 0x2000/0x2180/0x2200/0x4400)
  — the game "packet" fns are the FLUSH LADDER emitting FROM the same device shadows the shell
  uses. Register-true device reads work unchanged for game draws; no game-side state hooks needed.
- ABIs from arg shapes: BeginVertices(dev,prim,count,strideB) ≡ D800 core (prim 6 stride 0x1C
  strips; prim 8 RECTLIST stride 0x10 sprite batches up to 240 verts); DrawPrimitiveUP ≡ DC98
  (dev,6,4,0x340530,0x1C); Resolve(dev,0,pSrcRect 0x340520,pDestTex 0x3781E0); SetTexture same;
  G_Clear fired ONCE in 85s (game never clears — EDRAM persistence is load-bearing in-field).
- Stage-2A design: capture at BeginVertices exit (scratch, deferred vertex read at Present) +
  DrawPrimitiveUP entry; constants = DIRTY-GATED device-bank snapshots (dev+0/+8 dirty qwords at
  draw entry; banks dev+0x780/0x1780) — replaces event VSC for shell too; Resolve = ordered event
  -> segment end + blitResolve-pattern into getOrCreateResolveTex (old intercept then feeds the
  shell compose quad automatically). Vertex decode keyed on TRUE stride (28/16/12/24) + prim
  (5 fan/6 strip/8 rectlist w/ synth 4th vert = v1+v2-v0).

## HARD PIVOT s2B (2026-07-28 ~12:40) — GAME MODULE RENDERING (partial; capture DONE)
Stage-2 capture architecture SHIPPED + PERFORMING (60fps @ 578 batches/frame, 0 unmatched, 0
pipeline fails through boot->attract->TRAINING): unified CORE capture (shell D800 + game ECA0
exit, scratch latched, vertex bytes read lazily at Present), dirty-gated device-bank const
snapshots (dev+0/+8 qwords gate; banks dev+0x780/0x1780), resolve-segmented frames (segment
submit -> blitResolve-pattern into getOrCreateResolveTex -> clear-after honored via next-segment
CLEAR), true-stride vertex decoders (28/16int/16f/12/24) + RECTLIST 4th-vert synthesis
(v3=v1+v2-v0), register-true VTE ladder — PA_CL_VPORT shadow at dev+0x2908 (runtime-scanned;
s1_abi's 0x2920 was 0x18 off) {xs,xo,ys,yo}, vs48 ndc from full VTE, matrix-class ndc signs from
VTE signs. Game ABIs: s2_game_abi.md (scratchpad). [nvkdd] census: attract field pass = 640x512
vte{320,320,-256,256} top-left, own shader pair, prim-8 stride-16 int sprites + prim-6 stride-28
quads.
OPEN (next session, evidence-rich):
1. FIELD COMPOSE: screen shows the RAW 640x512 field pass top-left; the compose chain (shell
   window quad sampling the resolve texes) renders black/missing. Probe: which resolve bases the
   shell quads sample vs which nvk registered; wallpaper draws presence in nvk frames.
2. REPLAY PANEL 180°: NOT VTE (census: game uses shell sign convention). Suspects: resolve
   content orientation vs hardware EDRAM row order, or sampling-quad UV decode. Instrument:
   dump resolve tex PNG + panel-quad decoded verts.
USER: boot/title/menus judged GOOD on nvk ("seems so!" flicker verdict + blocky fixed via
fetch-shadow sampler read).

## s2B leg 2 (2026-07-28 ~15:2x) — FIELD HUNT: chain proven, content black (2 named defects left)
Fix ladder this leg (each register-true, all committed): (1) copy-at-next-draw vertex discipline —
Present-bulk reads LOSE early draws to in-field arena wrap (~2MB/present recycle; WASH at wrapper
altitude); scratch is complete+unwrapped at the NEXT core call. [nvkvtx] then showed PERFECT
sprite verts (16px quads, texel uvs). (2) dirty bits read at core ENTRY — the core's flush clears
dev+0/+8 before exit; exit reads = one bank/frame = every draw shared draw-0 constants.
(3) PA_CL_VTE_CNTL gate (dev+0x294C): 0x43F shell / 0x400 field — VTE-off means VS outputs
SCREEN px; map over guest vp (old true48 constants) else clip passthrough w/ vte sign rule.
(4) empty clear segments never recorded (C3-s1 rule).
★ RT_NVKFORCE bisect: white-tex+alpha on VTE-off draws -> FIELD SPRITES RASTERIZE CORRECTLY.
⏭ REMAINING: (a) field content black — fmt3 atlas 0x11227000 decode (streamed content vs cache
revalidation?) or ps50 c14 modulate zero; probe = dump decoded atlas + log c14 at field draws.
(b) per-draw scissor = vp region (sprites spill past 640; static scissor is full-screen).
(c) REPLAY panel 180° — likely same content chain; re-examine after (a).

## s2B leg 3 (2026-07-28 ~15:5x) — CONTENT HUNT NARROWED TO TEXTURE-CACHE STALENESS
Probes ([nvkdbg] c14/texel/blendReg + RT_NVKA1 force-alpha + full-env control):
- c14 = {1.004,1.004,1.004,0.000} at field draws — RGB fine; forcing c14.a=1 changed NOTHING.
- Guest texels at the fmt3 atlases (0x11707000/0x116E7000 256x256) are LIVE NONZERO 1555 data.
- blendReg 07060706/01060106 (SRCALPHA/INVSRCALPHA + additive variants) — plausible.
- RT_NVKFORCE white-tex renders sprites correctly => THE SAMPLE ITSELF IS BLACK with real tex.
VERDICT: prime suspect = getTexIndexReal cache staleness — game streams atlas content AFTER our
first decode (decoded-while-empty => cached transparent black); RVK_TEXREVAL3 revalidation
apparently not refiring for these game-streamed bases at nvk cadence.
⏭ NEXT PROBES: (1) dump decoded RGBA staging for 0x117x7000 vs guest texels at same draw;
(2) check revalHash sampling/period against these bases; (3) blunt A/B: force re-decode
(cache-bypass) for VTE-off draw textures — if field appears, ship a dirty-range/upload-hook
invalidation (the game's texel uploads are CPU-side direct-mapped writes — hookable at the
movie/bank uploader family 820E3F08.. or add per-frame reval for game-module bases).
Also: per-draw scissor=vp still TODO; panel 180° after content fix.

## s2B leg 3b — STALENESS REFUTED; content hunt state for next session
RT_NVKFRESH (per-frame cache-erase re-decode of VTE-off draw textures) changed NOTHING — the
fmt3 atlas decode produces the same (black-ish) result from LIVE texels. Eliminated so far:
c14.a (forced 1 = no change), REALALPHA on/off, cache staleness, geometry/transform (white-tex
probe renders sprites perfectly), constants banking, vertex capture. Remaining hypotheses,
in order: (1) the sampled texels genuinely ARE dark at these uvs and the ATTRACT field is
mostly-dark REPLAY content — compare against the OLD renderer's attract at the same frame
(referee PNG) before assuming a defect; (2) fmt3 decode detail for these game-streamed atlases
(tiling flag tf0 bit31 / pitch bits / 0x117xxxxx range vs the FMT3KEY 0x17xxxxxx gate);
(3) sampler/uv scaling for the i48int class (uv are TEXELS — verify the shader expects texel
uvs at this class; white-probe cannot see uv errors).
NEXT SESSION OPENER: side-by-side old-renderer attract f2400 PNG vs nvk + decoded-atlas dump
(write staging RGBA of 0x11707000 to PNG at decode time). Instruments all in place (RT_NVKDBG,
RT_NVKFORCE, RT_NVKA1, RT_NVKFRESH).

## s2B leg 4 (2026-07-28 ~16:4x) — WALLPAPER-THEN-BLACK DIAGNOSED: THE STATIC UI CMD BLOB
Ordered-clear fix (33190f7) did NOT cure it (user re-test: "same? shows then is gone") —
clear-ordering theory refuted. TRUE cause (fits the symptom exactly + a known architectural
hole): the shell's STATIC UI COMMAND BLOB (C2 census: 8209B180 authors ~24x DRAW_INDX_2 at boot
into dev+0x36A4/13988 in command-list build mode; resubmitted per-frame via INDIRECT_BUFFER).
The transition paints the wallpaper via LIVE wrapper calls (visible for a sec); settled-menu
frames redraw the background ONLY via blob resubmission — which never passes through D800 at
draw time. nvk skips cmdlist-mode draws (dev+0x2ABC bit0 guard) and cannot see resubmissions.
FIX DESIGN (next session): (1) capture blob-authoring draws (cmdlist mode) into a PERSISTENT
blob draw list keyed by blob addr (dev+0x3470/0x36A4) instead of skipping; (2) find the guest's
blob-resubmit site (who emits the INDIRECT_BUFFER — ghidra: readers of dev+0x36A4/13988; likely
in the compose core 8216AD98/8216B148 family or the kick) and hook it as the register-true
replay trigger; (3) replay the blob list at its stream position each time the guest resubmits.
NOTE: mode-select CARD ART renders correctly on nvk (fmt3 shell art fine) — field-black hunt
remains separately (see leg 3b opener).

## s2B leg 5 (2026-07-28 ~18:2x) — ★★★★★ WALLPAPER-THEN-BLACK FIXED AT SOURCE; blob model REFUTED
Instrument-first leg (the leg-4 "fix design" was banked, not proven — and it was WRONG twice over):
1. **Blob machinery built anyway + probe run:** capture of cmdlist-mode draws (persistent list,
   burst-replace) + splice at the REAL resubmit site — static analysis found it: **sub_8209B098
   (SetShaderGPRAllocation) emits the 3 INDIRECT_BUFFER packets** (state @dev+13992/96, fetch
   subrange, draw section @dev+15024/28); per-frame caller = compose core 8216B148 P1 (before its
   Resolve; 2 calls/frame). PROBE VERDICT (blob_probe.sh, deterministic boot→START→settled menu):
   **capture never fires (zero cmdlist draws at runtime) and the blob draw section stays degenerate
   0xC0003600/00010081 placeholders forever** — the blob resubmits STATE, not wallpaper. Leg-4
   model dead. Machinery kept (dormant, faithful altitude; RT_NVKNOBLOB reverts).
2. **Truth (one boot each):** [nvkdbg] showed the settled-menu background drawn LIVE every frame:
   b0 = vs5/ps16 window-quad, tex 0xE5F5000 1280x720 fmt6, blend ONE/ZERO, ps consts all 0.
   RT_NVKFRESH2 (VTE-on screen-size re-decode, 30f cadence — the every-frame >=512 cut OOM'd
   device memory in ~600f, die-loud exit 3 worked) = staleness RE-REFUTED for this class.
   RVK_DUMPTEXBASE=E5F5000 decoded-staging dumps = **decode PERFECT (bright full wallpaper) all
   40 samples**. [nvkvtx] = the kill: raw verts are FLOAT {x,y,u,v} fullscreen rect with x0 =
   guest matrix dust **-3e-5 (exp 112, ONE below the looksFloat window 113..143)** → i16int
   sniffer classified the quad int32 → garbage verts/uvs → the dark wash.
3. **FIX (register-true class split):** int32 {x,y,u,v} sprite records are a VTE-OFF (game-field)
   idiom — i16int sniff now gated on PA_CL_VTE_CNTL bit0 clear; VTE-off path bit-identical.
   VERIFIED: settled TOP MENU wallpaper live+stable f1500..f4800, title/boot clean, 62 draws/f,
   zero errors. ⏭ **The field-compose black window quad (leg-2 open item 1) is the SAME
   vs5/ps16 class — retest attract/field compose next session; REPLAY panel after that.**
⏭ USER GATE: eyeball the menus (RT_NVK=2 playtest) — wallpaper should persist on settled menus.
New default-off instruments: RT_NVKFRESH2, RVK_DUMPTEXBASE=<hex>, [nvkdbg] ps16 const window,
[nvkblob] AUTH/SUBMIT census. Evidence: /c/tmp/blob_probe*.log, texbase_0E5F5000_*.png, nvk_f*.png.

## s2B leg 5b (2026-07-28 ~18:5x) — ATTRACT/FIELD RETEST: black CURED, next gap = RT SEGMENTATION
Retest drive (blob_probe.sh, START+Ax2 -> ROM attract soak 160s, /c/tmp/field_retest.log + nvk_f*.png):
- **The vs5/ps16 window-quad black IS cured on ROM-era frames too** — compose regions now carry
  live content (attract circles/scenery visible inside them); shell wallpaper behind is correct.
  b1 census: vs47/ps46 VTE-off vp=640x512 quad sampling the field resolve 0xEF4D000 <RESOLVE — the
  compose chain samples REGISTERED resolve content now (was black/missing pre-fix).
- **Remaining (now-visible) defect layer on ROM-era frames:** field/ROM passes render at raw
  offsets onto the visible frame (top-left staircase of rects; portal region ~480x640 centered =
  the portrait playfield window) + washed/flat colour frames in the cycle (solid cream f5400,
  pale wash f9000). ROOT SHAPE: **nvk has NO render-target segmentation** — game field passes are
  drawn into a 640x512 EDRAM RT on hardware (SetRenderTarget: shell 82099AD8 / game 88077E78 —
  both already NVK_TAP-hooked, recorder ignores them) then resolved+composed; our single-g.image
  model leaks those passes onto the screen before the resolve blits them out. NEXT LEG (natural
  C3/C4 continuation): record SETRT as an ordered event, per-RT offscreen images sized from the
  bound surface, segments render into the CURRENT RT's image, resolves blit from it. Colour-wash
  triage after RT segmentation (may be the same leak double-composing).

## s2B leg 6 (2026-07-28 ~19:3x) — ★★★★★ RT SEGMENTATION LANDED: attract staircase GONE, frame structure 1:1
- **SETRT ABIs probe-pinned (RT_NVKRTLOG):** both (dev, idx, pSurface). Shell binds default RT
  0x358590 from compose 8216D340; game binds field surface per frame from emitter 8808E4E4.
  Surface object: +0x18 = pitchBytes<<16|width, +0x1C = alloc height (720 game / 0 shell).
- **Display identity lesson: dev+0x3ABC is NOT the default RT** — it holds the resolve-dest
  back-buffer OBJECT (0x...540); the compose's default RT is a different object (0x...590).
  First cut misrouted the whole shell offscreen. REGISTER-TRUE discriminator: the surface bound
  at Present = the frame's display target (NvkFrame.displaySurf, self-calibrating).
- Implementation: ordered SETRT events segment the frame; per-surface images+framebuffers
  (ResolveTex pattern, parked TRANSFER_SRC between passes); resolves blit from the BOUND target.
- **VERIFIED:** staircase leak GONE; frame layout correct (wallpaper + single portrait playfield
  window); field resolve EF4D000 dumps show REAL bright attract scenery (f46200 clean); shell
  TOP MENU bit-clean on the final build. Frame anatomy now legible per census: SETRT(field)->
  ~449 field draws->RESOLVE(EF4D000)->SETRT(display)->SETRT(0x269F320 320x1808?)->1 draw->
  RESOLVE(320x240)->SETRT(display)->34 draws->RESOLVE(front 0x6A1000)->present.
- ⏭ REMAINING content gaps (pre-existing, now cleanly fenced in resolve dumps):
  (1) **inner gameplay-layer compose hole** — stable ~480x384 rect (x 160..640, y 0..384) in the
  field resolve where the ROM composites its gameplay layer; suspects = the 320x240 resolve
  ring (dozens of bases FF*D000/100*D000) / the odd 320x1808 target (dw7 decode suspect for that
  surface type) — likely the old REPLAY-panel class, one draw + resolve per frame;
  (2) ranking-text fmt3 sprites still blank (leg-3b field-content class, atlas pairs idx119/120).
- Evidence: /c/tmp/rtseg_test2.log, rtseg_test3.log, nvkres_f*_EF4D000_*.png, rtseg_menu.log.

## s2B leg 7 (2026-07-28 ~20:1x) — GAMEPLAY COMPOSE HOLE: root NAMED (game float constants), fix PARKED at 2 strikes
**The hole is not a compose defect — there is no missing quad.** [nvkhole] census: the gameplay
sprites ARE in the field pass (vs45/ps50 clusters, center-origin raw coords, fmt3 atlases,
blend 01060106) and vanish; only untextured fills survive. Root chain, instrument-proven:
1. **Bank overflow (FIXED, kept):** NVK_MAX_BANKS 256 overflowed in ROM attract (dirty fires
   per sprite batch; 400-500 draw frames) → 768, overflow loud.
2. **★ THE ROOT: game-module float constants never reach dev+0x780/0x1780.** [nvkdd]: every
   game draw banked the shell's static c0=0.5625 with dirty bits firing. The game supplies ALU
   floats via its OWN packet path (per the old walker's decode: SET_CONSTANT 0x2D /
   LOAD_ALU_CONSTANT 0x32 / type-0 runs). The vte/context shadows DO update (A578 flushes
   FROM dev+0x28xx) — floats don't. This also explains the leg-3b fmt3 content-black class
   (wrong ps50 constants), unifying the two open content defects into ONE root.
3. **Mirror swings (censused, parked):** (a) emitter-window parse at A638/A7B8/A1E0: streams
   clean (510k aligned/119 bad) but VS-range type-0 ONLY — zero 0x2D/0x32; PS consts + inline
   emitters bypass those seams. Partial success: game VS values (c0=56.7, c1.y=0.5635) reached
   banks. (b) naive full-ring incremental ingest at the core-call choke point: correct idea,
   WRONG parser — inline-vertex draw packets misparse (38k misaligned, gen 27M, NaN) → field
   went full black. Both parked behind RT_NVKGF=1 (default off = stable flat-field state).
**⏭ NEXT SESSION (the finishing move): reuse the OLD WALKER'S parser** — renderFrameReal's
packet decode (vk_render ~4035-4310) already handles type-0 bursts, SET_CONSTANT, LOAD_ALU,
draws-with-inline-data, and IBs; refactor its register-write core into a shared
constants-only ingest the recorder can call incrementally (ring window (pos,cur] at each core
call), then flip RT_NVKGF default. Acceptance = gameplay sprites in the field resolve + the
fmt3 text rendering (ranking screen) + demo-play visible in the portal.
Lesson banked: "source of truth" course-correct (user call) — the old renderer's ingestion
code was the answer key all along; device-offset archaeology was two boots of waste.
Evidence: /c/tmp/hole_probe.log, gc_probe*.log, gf_dbg.log, ring_test.log, mg_probe.log.

## s2B leg 7 rounds 3-6 (2026-07-28 ~20:5x) — FLOAT SEAM FOUND: core-ladder callees FDF8/FFB0/B738
Round census (each = one boot):
3. Full-ring ingest at the core call = unfixable at this altitude: inter-call window contains
   raw inline VERTEX blobs (38k misaligned, NaN churn). The old walker's LEG-27/40 lesson, relearned.
4. Old-walker parser rules grafted: **zero dword = 1-dword NO-OP** (round-2's NaN was this exact
   4-byte phase shift), TYPE0 ONE_REG_WR bit15, desync guard, ★ **PS floats = 0x4400-0x477F**
   (0x4800+ = FETCH constants; round-1's "VS-only" verdict was this mapping error — its garbage
   PS file came from fetch dwords).
5. **RVK_FLOATSRC (new instrument, old-renderer walker): the float form = plain TYPE-0 full-bank
   bursts 0x03FF4000/0x03FF4400 (+ small runs 0x000F4430 = ps50 c14 group, value 1.00392).**
   Absent from A578/A638/A7B8/A1E0 windows (bucket census: ~zero float traffic there).
6. **Seam = the three uninspected core-ladder callees 8807FDF8/8807FFB0/8807B738** — hooked with
   the window mirror; float traffic flows (PS bucket 3132/boot), game draws now bank a REAL
   game matrix (c1.y=-1.0 = RT-flipped ortho; was the shell's stale c0=0.5625/c1.y=+1).
⏭ NEXT: (1) long-soak demo-play acceptance — recent samples kept landing on the drive's fade
window (debug overhead slowed presents ~4x; sample later cycle phases or lengthen DUR); (2) the
portal's saturated-green flat suggests constant APPLICATION polish (DEF overlay order vs bank,
c14 semantics — colour unity is 0x80 per SPEC, audit the multiply); (3) identify WHICH of
FDF8/FFB0/B738 carries the banks (drop the other two hooks); (4) then flip RT_NVKGF default ON
+ retire the leg. Instruments: RVK_FLOATSRC (old path), RT_NVKGFDBG buckets, RT_NVKGF arm.

## s2B leg 7 FINAL (2026-07-28 ~22:xx, b454fea) — ★ THE LEG-7 ROOT CLAIM WAS FALSE. RETRACTED.
**RETRACTION (supersedes leg-7 §2 above — do NOT trust that section):** the claim "★ THE ROOT:
game-module float constants never reach dev+0x780/0x1780" is **WRONG**, and it misdirected six
rounds of work. Proof, two independent ways (multi-agent workflow wf_70214edd + adversarial
verify, then confirmed live):
- **STATIC:** sub_8807A910 is the game's TYPE-0 ALU float emitter, called twice from the draw
  core 8807ECA0 (ppc_recomp.2.cpp:19428/19444): `addi r6,r31,1920` -> src = **dev+0x780** (VS,
  reg base 0x4000, mask `ld r4,0(r31)`), `addi r6,r31,6016` -> src = **dev+0x1780** (PS, base
  0x4400, mask dev+8). It FLUSHES the very shadows the recorder snapshots, on the very dirty
  bits it samples. Its header formula ((n-1)<<16|reg, 16 dwords/dirty bit) reproduces all three
  observed forms — full mask -> 0x03FF4000/0x03FF4400, PS bit 3 -> 0x000F4430 = the ps50 c14 group.
- **EMPIRICAL (ps50 c14 census, the ONLY game constant the field reads):** shadow path =
  2219x {1.004,1.004,1.004,0} + animated tail, IDENTICAL to the old working renderer
  (floatsrc2.log). Mirror path (rounds 4-6) = dominated by **{0,0,0,0}** = a black multiply of
  the entire gameplay sprite layer. **The mirror was a black-hole generator, not a fix.**
RETIRED: RT_NVKGF, the constant file, nvk_on_game_pkts/nvkGameReg/nvkRingIngest, all six
NVK_GCONST_HOOKs. (FFB0's r3 is not even the device — dev+13424/13568 sub-structs.) KEPT:
NVK_MAX_BANKS 768 (real overflow), A910 relabeled G_AluFloatFlush.
**★ SCOPE CORRECTION for every future field leg (spirv-cross of the bound shaders): vs45 and
vs47 read NO vertex constants at all** (vs45: pos=xy*2-0.5, uv=xy/256; vs47: passthrough) and
ps46 is a pure texture pass. The ONLY game constants the field pass consumes are ps50's c14
(float idx 56) and c15 (idx 60). Round-6's "real game matrix c1.y=-1.0" success metric was
measuring a value NOTHING READS.
**★★★★★★ REFEREE DATUM BANKED (/c/tmp/REFEREE_field_gameplay.png):** the OLD renderer on the
IDENTICAL deterministic drive renders the full attract DEMONSTRATION — enemies, bullets, score,
banner, playfield. So the content exists, the drive reaches it, and the defect is nvk-only.
A/B soaks (accept_soak vs accept_ctrl, 285s each, same drive): portal is a FLAT drifting fill
in BOTH mirror-on and mirror-off arms ⇒ **the flat portal is NOT a constant defect and never was.**
⏭ NEXT LEG — the field flat, with constants now exonerated. Ranked candidates:
 (1) **nvk drops the register-true ALPHA TEST**: rom_ps50 runs `if (oCol.w < xrAthresh) discard;`
     reading SharedConstants+272, but nvk's sc[512] is memset-0 with only offsets 0 and 192
     written ⇒ athresh is unconditionally 0 on EVERY nvk draw; the old path computes it
     (vk_render.cpp:5138-5158). Cheap discriminator: force sc+272 on VTE-off draws.
 (2) **the vs47 self-composite feedback quad** (d4: full-portal, samples its own resolve
     0xEF4D000, vertex colour FF808080 = 50% gain, blend ONE/ZERO opaque). A feedback loop with
     gain != 1 diverges to flat black OR flat white — the only mechanism proposed that explains
     BOTH observed extremes and the portal colour not correlating with the same frame's c14.
 (3) nvk hardcodes colorWriteMask 0xF (old path uses guest RB_COLOR_MASK 0x2104) and blend
     constants {0,0,0,0} (old path binds RB_BLEND_RED..ALPHA).
 Method note: c15.x/c15.y is the real alpha path (RT_NVKA1 pokes c14.w = idx 59, which ps50
 never reads — discard any conclusion drawn from it).

## s2B leg 8 (2026-07-29, 5-agent adversarial round BEFORE building) — ★★★★★★ FIELD FLAT ROOT-CAUSED + FIXED: missing px→ndc EPILOGUE in baked vs45/vs47
**Method (the leg-7 meta-lesson applied): 3 independent candidate investigators + 1 apparatus
agent + 1 decomp agent, all read-only, BEFORE any build. Two candidates died in review; the
survivor's mechanism was corrected by its own investigator; one build, one gate, PASS.**

**★ THE ROOT (corrected candidate #2):** nvk's VTE-off px→ndc ladder is delivered via push
constants (pc.ndc, vk_render ~9468) that the BAKED vs45/vs47 modules never declare — spirv-dis:
their push blocks stop at offset 16 (vs/ps/shared BDAs); only xrgen modules (48/49/50) carry
the 24/32 ndc members + epilogue. So the vs47 self-composite quad (d4, restores the previous
resolve into the field RT each frame) rendered with clip-space = SCREEN PIXELS: only the
corner survives clipping → ~2x2 texels of its own previous resolve magnified over the portal
= a unity-gain, spatially-degenerate feedback integrator (flat, drifting, both black AND light
extremes, uncorrelated with same-frame c14) — and vs45 sprites became screen-wide washes
("only untextured fills survive"). Zero-boot corroboration: every banked field resolve was
literally a 2x2 block of flat fills (uniqRGB<=4, <=2 distinct rows).
**The STATED #2 mechanism (FF808080 vertex-colour 0.5 gain) was FALSIFIED by its own
investigator: neither vs47 nor ps46 declares a COLOR input — the colour is dead data.**

**FIX-A (shipped): route vs45/vs47 through gen_xrgen** (containers carved byte-exact from
caps_gp cap_gimage.bin @0x9638/@0x98A8; make_vs4547_containers.py; fam_vs96.xvu turns out to
BE the vs47 container). Repoint at getOrCreateModule (vk_render ~1584) NOT the extract_cache
table (regen would silently lose it); lever RT_NVKOLDVS=1 reverts. vs45 c255={2.0,1/256,-0.5,0}
fed via loadShaderDefs from the container DEF (value-identical to the retired baked literals);
vs47 reads no constants. Old-path parity: rvkTrue48 widened to {45,47,48} VTE-off. VTE-ON
strictly unchanged (ladder resolves to identity there). Latent flagged: xrgen shim hardcodes
oC0/oC1=1.0 (baked stored 0) — inert today (no paired PS reads COLOR0).

**Candidate #1 (alpha test) — REAL but SECONDARY, fixed register-true:** sc+272 was never
written on nvk (athresh unconditionally 0). Fix mirrors old path 5138-5159: NvkDraw.colorCtl/
alphaRef ← dev+0x293C/0x2904 (shell sub_82097338/sub_820972D8; game sub_88075C08/sub_88075BA8),
athresh = func6→aref / func4→aref+1/512; RT_NVKATHRESH override lever. [nvkat] census on the
live run: field pass IS armed (0x8700000C func4 ref=0 → athresh 1/512) on vs45/ps50. This
closes the reintroduced "attract black-boxes" class (32x 04000400 multiply + ~996x 07010701
padding leaks). It could NEVER explain the flat: the full-portal draws (ps46/ps20/ps16) have
their alpha test compiled out by specVal=0 in BOTH renderers; athresh=0 only ADDS pixels.
**★ Bonus scope fact: FutariShader.spec_mask is declared and read by NOTHING; createRealPipeline
hardcodes specVal=0 — the old-bake alpha-test spec-branches are dead code in the whole port.**

**Candidate #3 (writemask/blend consts) — STRUCK, transcription error:** ledger's "RB_COLOR_MASK
0x2104" was the REGISTER INDEX not a value (comment "RANK 21 (RB_COLOR_MASK, 0x2104)" lost its
comma). Actual guest value: 0x0000000F on 4744/4744 samples across 17 logs (+1 boot-default
0xFFFF; &0xF = same) = nvk's hardcode is register-true already. Blend constants: no CONSTANT_*
factor ever appears in the field (max factor code 7); the whole candidate refuted 3 independent
ways. BANKED LATENT: some attract-era draw DOES use CONSTANT_* (the 07-27 legal-panel fix
proves it) — nvk's hardcoded {0,0,0,0} blend constants are a real latent regression for THAT
class; register-true patch design (dev+0x28E0..EC floats via sub_88075C38) is in the agent
report, land when the class next surfaces.

**LEDGER RETRACTION (leg-7 line "debug overhead slowed presents ~4x"): FALSE.** Presents held
57.7/s all evening (dump-mtime measurement). The real sampler defect: attract cycle = EXACTLY
4800 presents, resolve dumper hardcoded %600 ⇒ a perfect 8:1 alias (only 8 phases ever
observable). ALSO: dump filenames are frame-indexed only ⇒ RUNS OVERWRITE EACH OTHER (leg-6's
"f46200 clean" evidence was destroyed by a later run); and the field surface base is a
wall-clock bigalloc (EF4D000 one boot, FF5D000 another) — never hardcode it. Fixed: RT_NVKRESEVERY
(coprime periods; 181 used) + RT_NVKRESONLY levers; harness banks per-run.

**THE GATE (new standing apparatus): _tmpscripts/c3_fieldaccept.sh + c3_verdict.py** — A/B
vs the old renderer on the identical deterministic drive, display-independent readbacks only,
per-run banks. Metrics: 8x8 tile-structure fraction + uniqRGB + portal-edge guard (drops
wallpaper-only false-PASS frames), all thresholds RELATIVE to the control arm per phase band
([r5pix]-trap-proof, 4 defences). Controls run FIRST: metric self-test vs referee (tf .982
uniq 20204), old-arm H0 (demo tf .968, 36k colors), unfixed-nvk negative control = FAIL with
res_uniq_med=4 (gate not inverted). **ACCEPTANCE RUN (fixed build): PASS ALL GATES —
G1 demo display tf .966 vs ctrl .968; G3 field resolve uniq 4→27459 med, tf 0→.956;
G2 ranking .83; G4 aligned. Zero VK errors, f16501 in 300s.** Landmine: MSYS_NO_PATHCONV=1
breaks `taskkill //F` (script hung on `wait`) — use PowerShell Stop-Process in harness scripts.

**DECOMP (parallel agent): SPEC_shell_compose_1to1.md honest gaps ALL CLOSED** ("GAPS CLOSED
2026-07-29"): DAT_82051700 blend table = native Xenos D3DBLEND values (0=ZERO legal on 360),
all 6 modes decoded, op=ADD everywhere; ⚠ FUN_820995F0 writes RB_BLENDCONTROL BYPASSING the
dev+0x2EF8 shadow (veil 0x10001 desyncs it; port must model both). NOW-LOADING overlay paints
OVER boot scenes (own top object DAT_821F8568, parallel list). Clear thunk dispatched at
main-loop step 1c; D3DCLEAR bits decoded (0x3F = RT0+Z+stencil; Z/stencil-only clear = no-op;
settles ATLAS_d3d_wrapper GAP 1 — the 820A1218 hook catches all clears). FUN_82182FC8 = 3-level
Gaussian pyramid, full-target passes, +0.5 texel UV bias, off intro path.

⏭ **USER EYEBALL GATE PENDING (doctrine: 4 instrument-green fixes were user-refuted before —
though this is the first CONTENT-TRUE positive/negative-controlled A/B gate of the arc):**
`RT_NVK=2 bash _tmpscripts/playtest.sh` — expect demo-play in the attract portal, sprites in
field, ranking text. ⏭ THEN: fmt3 ranking-text recheck (G2 green suggests cured), REPLAY-panel
class, msg 12/13/14 live-fire debt (RT_MSGLOG armed), RVK_DECOUPLE feel-check still queued.

## s2B leg 8 USER VERDICT (2026-07-29 ~16:0x, playtest_0729_1601.log + 4 screenshots)
**★★★★★★ THE FLAT IS CURED — user-confirmed content on every attract screen** (legal text,
ranking table + CAVE logo overlay, title art, demo). "damn, i thought we had it" = the
remaining defects are TEXTURE-CLASS, not compose/geometry:
1. **Legal-panel gray streak wash** = THE PREDICTED LATENT (leg-8 candidate-#3 report banked
   it): attract legal/fade draws use CONSTANT_* blend factors; nvk hardcodes blend constants
   {0,0,0,0} (old path binds RB_BLEND_RED..ALPHA per batch, vk_render 5177-5180/6394 — the
   07-27 "legal-panel white-wash" fix). PATCH = the banked register-true design (dev+0x28E0..EC
   floats via NvkDraw), landing now behind RT_NVKNOBC revert lever.
2. **Red/green blocky noise in panel background art** (ranking bg, title roses) — new named
   class: game-streamed panel art decodes as noise (fmt3/tiling/pitch decode suspect family,
   0x117xxxxx-era class) OR partially-streamed upload ([zscan] cousin). NOT transient here.
   Awaiting the t1-bank residual audit before a leg.
3. **Panel-bottom white/black block** (ranking screens) — partial quad/texture, may be same
   class as (2).
**★ 13th lying-instrument lesson: the c3_verdict structure metric (8x8 tile tf + uniqRGB)
scores NOISE as content — G1/G3 passed on frames a human fails. The gate proves "not flat",
not "correct". Next iteration needs a correctness term (same-band cross-correlation vs the
control arm / referee) before it can be called an acceptance gate again.**
**msg-13 LIVE-FIRE DEBT BANKED:** user quit via menu — [gemsg] msg=13 → msg=3 →
XexUnloadImage → shell TOP MENU rebuilt, on the MATCHED GameEntry translation, zero errors.
(msg 12/14 not exercised this session.) [nvkat] live: shell vs47/ps46 test DISABLED (0x87000004),
field vs45/ps50 ARMED func4 ref=0 → athresh 1/512 — matches the static prediction exactly.

## save-path recheck (2026-07-29): two-boot persistence proof RE-PASSED on the current NVK-era build
(save_persist_ab.sh: boot1 wallpaper 01->02 + save write fires; boot2 loads wp02.bin from frame 1).
The fe456f6 XamContentGetDeviceData fix holds; playtest savegame.bin mtime 07-25 was benign
(no save-worthy change since). Score Attack sign-in stub decision still pending (backlog #10).

## s2B leg 9 OPENER (2026-07-29 ~16:4x) — RESIDUAL AUDIT (read-only agent, t1/t2/neg1/c1 banks): all four classes cracked
**Class A (legal streaks): blend-const hypothesis REFUTED by t2 A/B (patch changed 0.04% of
pixels — patch KEPT as register-truth, not the fix). TRUE mechanism: the vs47/ps46 self-composite
resamples with a SUB-TEXEL DIAGONAL OFFSET at unity gain — glyph smear ~45-60°, integrates with
dwell (23.9→35.5 luma f2172→f2353), lives in the FIELD RESOLVE (pre-compose). Fix = texel-align
(old-path half-pixel/half-texel bias; NEAREST lever as interim).**
**Class B (panel red/green): NOT noise, NOT texture decode. Field resolve EF4D000 is pixel-CORRECT
vs c1; the corruption is the 320x240 RESOLVE RING (the only surface displayed — vs5/ps34 draw
samples ring slots; NOTHING samples EF4D000 at display vp). Signature = byte-exact channel remap
+ saturating subtract (LUT std 0.0; e.g. dst=(G, R+B-G, R) exact on 92% at f3620) = format
REINTERPRETATION fingerprint; ring fmt54 = k_2_10_10_10_AS_16_16_16_16, nvk has no decoder case.
Probe = pre-resolve RT dump of 0x269FB50 + VkFormat pair log (splits render-pass vs resolve-copy).**
**Class C (bottom band): x-replicated edge-clamped column, cols x=0..45 of the field RT, constant
width. Class D (NEW): CAVE-logo white fill undersized (17% vs 97% of panel; lumCorr 0.000).
★ BOTH game RTs decode WRONG heights ([nvkrt] 640x720 vs true 640x512; 320x1808 vs 320x240) —
leg-6 dw7 alloc-height suspect CONFIRMED LIVE; suspected prerequisite for B/C/D.**
Clean bills: compose hole GONE (neg1 uniq=1 on all 26 = negative control clean); t1 vs neg1
shell frames BIT-IDENTICAL f91..f1183 (ndc fix scope confirmed VTE-off only); t1 log zero
errors. ⚠ heap high-water climbs monotonically to 432MB/240s (pooled 1766 vs live 746 = pool
retention, no plateau) — longer soak required pre-alpha. Gate correctness term validated
(per-band lumCorr vs c1: legal .82 ranking .83 cavelogo .00 title .44 = the numbers to raise).
RANKED: (1) class-B probe instrument, (2) class-A texel align, (3) RT height decode fix,
(4) C retest after 3, (5) D, (6) verdict G5 term. Items 1/2/3/6 implementing now.

## s2B leg 9 LANDED (2026-07-29 ~17:3x) — RT-SIZE ROOT FIX + resampler alignment: class B mostly cured, legal text legible
**★★★★★ [nvkrt] SIZE decode CORRECTED (the audit's "wrong heights" root): the old +0x1C read was
RB_COLOR_INFO's EDRAM TILE BASE (720/1808 = tile addresses, never heights!); true extent =
surf+0x24 packed (W-1)<<18|(H-1)<<3, bit-exact verified, byte-size corroborator agrees (sane=1
on all 3 surfaces: ring 320x1808→320x240, field 640x720→640x512). Lever RT_NVKOLDRTSZ.**
RESULTS (t3 vs c1, visual + G5): ranking panel art = recognizable scenery (was noise);
RANKING lumCorr 0.528 vs control-self 0.367 = at metric ceiling; legal text now CRISP
("MASTER VER. 1.54." legible; was smeared) — residual diagonal texture behind glyphs needs a
referee call (authentic brushwork vs leftover smear). Resampler alignment landed (NEAREST for
1:1 resolve blits + self-composite sampler; levers RT_NVKNOALIGN/RT_NVKCOMPLIN); ★ analytic
finding: the vertex→NDC map is EXACT for the composite quad and sc+264 halfPixel is {0,0} in
BOTH renderers — if smear residue survives, next altitude is SPIR-V/texture-routing.
**[nvkfmt] CLASS-B RESIDUAL FINGERPRINTED: ring RT guest cfmt=3 (2_10_10_10) + fetch fmt54
endian=2, but nvk creates/samples vkfmt=37 (RGBA8) — the remaining chroma fringing. FIX NEXT:
create ring RT as A2B10G10R10 (or decode-correct swizzle) matching cfmt 3.**
**[shadowring] fires call#1 gate14=1 gate18=1 → drop-shadow furniture CONFIRMED emitted+gated-on;
the RVK_PANELFURN replay split (design in BACKLOG 4b) is a GO for next build.**
⚠ G5 BAND LABELS WRONG: band5 edges assign "LEGAL" to the ~49-draw band, but the audit's map
says legal carries ~500 draws (450 glyph sprites) — the names are shifted one phase (the 0.023
"LEGAL" reading is actually CAVELOGO = class D, untouched). Fix band5 names from the audit map
(legal 496-581 / ranking 111 / cavelogo 49 / title 96) before trusting G5 headline numbers.
⏭ LEG 10 QUEUE: (1) ring RT 10-bit format; (2) class D cavelogo white-fill extent; (3)
RVK_PANELFURN furniture replay (drop shadow); (4) band5 relabel; (5) class C bottom-band retest
(may be cured by RT-size fix — check t3 resolves); (6) heap high-water soak. Then user eyeball.

## s2B leg 10 LANDED (2026-07-29) — per-target REGISTER-TRUE formats; class D named+decidable; PANELFURN found MOOT
**★ ITEM 1 — RING RT FORMAT. The brief's premise was WRONG and the tree already knew it: guest
RB_COLOR_INFO=0x00030710 -> cfmt 3 is `2_10_10_10_FLOAT` (7e3: 3-bit exp, 7-bit mantissa, range
[0,32)), NOT `2_10_10_10` unorm — see the tree's own decode table at vk_render.cpp RVK_RTFMT and
the register-true present ruling ("the 7e3 HDR range exists ONLY inside the 320x240 tile passes
(RB_COLOR_INFO fmt=3) and saturates to [0,1] at their k_2_10_10_10 resolve"). So the register-true
host pair is ASYMMETRIC, not "both A2B10G10R10":
  ring RT      cfmt 3  -> VK_FORMAT_R16G16B16A16_SFLOAT      (f16 5e10 strictly contains 7e3 3e7)
  resolve tex  fmt 54  -> VK_FORMAT_A2B10G10R10_UNORM_PACK32 (k_2_10_10_10; `_AS_16_16_16_16` is an
                                                              EDRAM-export tag, not a layout)
and the F16->A2B10 blit IS the guest resolve's own saturate-to-[0,1] + 10-bit quantize, in one step.
MECHANISM the change removes: an 8-bit UNORM target clamps EVERY blend step at 1.0, per channel —
channels that would exceed 1 and come back down are truncated at different points, which is a hue
shift on saturated pixels = the residual chroma fringing. Component order is a NON-ISSUE: the
resolve is an image->image blit (by-NAME component conversion) and the sampler reads by name, so
byte layout and the fetch's endian=2 never enter the host path; A2B10G10R10_UNORM_PACK32 is anyway
bit-identical to D3D R10G10B10A2_UNORM = the Xenos layout. Plumbing: per-format {CLEAR,LOAD} render
pass pair (nvkPassesFor), colour format folded into the pipeline cache key (bits 40-47 —
STALE-CACHE COLLISION otherwise), ResolveTex/NvkRT carry their own fmt, device format-feature check
with silent fallback to g_rtFmt, png dumps unpack 10-bit instead of skipping. Resolve-dst format is
only trusted when the fetch shadow's BASE == resolveDst. **LEVER RT_NVKRING8=1 reverts everything.**
**★ ITEM 2 — CLASS D: NOT CURED by leg 9, and the reason it has never been seen in a census is
STRUCTURAL. Measured (panel rect x400..878 y40..679, luma>=200): c1 cavelogo 97.2-100% white,
bbox = the FULL panel; t3 24.7%, and the white that IS there is exactly the logo's own quad (map
resolve->panel via dst(ox,oy)=src(639-oy,ox): predicted logo-in-resolve x[239,452] y[143,334],
measured white block x230-422 y128-333 = MATCH). So the defect is a MISSING full-panel background
fill, not an undersized one; the logo itself is correct and pixel-aligned with c1. t1 was 17.2% ->
t3 24.7% = leg 9 moved it, did not fix it.
  ⛔ THE BLIND SPOT: every nvk census ([nvkseg]/[nvkdbg]/[nvkhole]/[nvkvtx]) was hardcoded to
  `frame % 600 == 0`. The attract loop is EXACTLY 4800 frames (t3 heartbeats: the 49-draw CAVELOGO
  band lands on f3301, f8101, f12901 — stride 4800) and 4800 % 600 == 0, so the census can only ever
  fire on 8 fixed phases {0,600,...,4200}. Cavelogo sits at ~3250-3550 => INVISIBLE in every bank
  ever recorded. **NEW LEVER RT_NVKDBGEVERY=<n>** (mirrors RT_NVKRESEVERY; unset=600=byte-identical).
  RT_NVKDBGEVERY=700 hits f3500 on the FIRST cycle and gcd(700,4800)=100 sweeps every phase after.
  REFUTED en route: the "leftover CPU-side vs45/47 transform double-transforms the fill" hypothesis —
  nvk's decodeVert has NO per-vs transform at all (only the vs48 xyuv record reshape); the px->ndc
  epilogue is applied once, in recordSeg, from PA_CL_VTE_CNTL. NEXT: one boot with
  RT_NVKDBG=1 RT_NVKDBGEVERY=700 and read the ~49-draw census.
**★ ITEM 3 — RVK_PANELFURN IS MOOT UNDER RT_NVK=2. NO CODE CHANGE. Two independent proofs:
(a) the whole doOverlay/menuLive/pillarbox machinery lives inside renderFrameReal, and rt.cpp's
Present short-circuits with a bare `return;` at RT_NVK>=2 before rt_render_maybe() — it is dead
code on the nvk path; there is no pillarbox, no anti-diagonal transform and no menuLive gate there
at all. (b) the guest composes the window itself under RT_NVK=2 and its furniture draws already
flow through: t3 f3600's FINAL display segment is SEG [53,87) = 34 guest-native vs=1 ps=2 prim=5
n=4 st=24 quads into surf 00358590, i.e. the window furniture IS replayed. Border profiles outside
the panel are pixel-identical between t3 and c1. => BACKLOG 4b's fix design targets the retiring
legacy path; re-scope or close it. Do not build the replay split.**
**★ ITEM 4 — band5 relabelled from GROUND TRUTH, not from the audit prose.** t3's own [nvk]
heartbeats over one cycle: f2401 d496 LEGAL / f2701 d112 RANKING / f3001 d111 RANKING / f3301 d49
CAVELOGO / f3601 d96 TITLE / f3901 d288 DEMO — and c1's filenames carry the guest FSM (every LEGAL
frame fsm1, everything after fsm3) and agree phase-for-phase. New edges: <20 BLANK, <70 CAVELOGO,
<108 TITLE, <141 RANKING, else DEMO. LEGAL cannot be separated from DEMO by draw count (488-573 vs
423-525 OVERLAP) so it is split out by whole-frame luma: **draws>=400 AND fullmean<80**, validated
17/17 against the FSM ground truth (LEGAL max 78.94, DEMO min 87.07 — an 8-point margin).
G5_BANDS gains CAVELOGO: under the old shifted names the 49-draw band was called "LEGAL" and was
already gated, and with names corrected it is the ONLY gated band whose positive control is live in
c1 (self-corr .943 vs LEGAL .658 / RANKING .729 / TITLE .085) — without it `live` is empty and G5
degenerates to unconditional False. Blind-band doctrine untouched.
NEW TABLE (t3 vs c1): CAVELOGO .023/ctrl .943 (LIVE, deciding, = class D) | LEGAL .750/.658 blind |
RANKING .004/.729 blind | TITLE .039/.085 blind | DEMO .437/.286 ungated. VERDICT FAIL, decided by
a positive-controlled band for the first time.
⚠ KNOWN RESIDUE: LEGAL's low-draw opening sub-phase (c1 d52/d91, fsm1, ROI-black) lands in
CAVELOGO/TITLE; those frames are flat so pearson()=0 and they drag both medians. Both bands' fix is
FSM labelling on BOTH arms (the nvk arm's filenames carry no fsm today).
⏭ LEG 11 QUEUE: (1) boot RT_NVKDBG=1 RT_NVKDBGEVERY=700 -> find the class-D fill draw; (2) A/B the
leg-10 format change on the ring (expect chroma fringing to drop; RT_NVKRING8=1 is the control arm);
(3) class C bottom-band retest; (4) heap high-water soak; (5) close/rescope BACKLOG 4b.

## legs 9+10 USER VERDICT (2026-07-29 ~18:3x): banked frames CONFIRMED matching live play.
RANKING ART = CURED by user eyes (vs 16:00 screenshots). STILL OPEN, user-confirmed: (1) legal
diagonal streaks behind glyphs (reduced, not killed - next altitude = SPIR-V/texture routing per
leg-9 analysis); (2) border shadow ABSENT on the nvk path = REAL nvk-stream bug (leg-10 "furniture
flows natively" claim REFUTED by user eyes - re-diagnose on nvk stream: ring drawn with what
colour/blend? [shadowring] fires with gates on, so draws ARE emitted - find where they die);
(3) cavelogo bg fill (class D, census banked in t5). Fringing not disputed = presumed improved.

## s2B leg 11 LANDED (2026-07-29) — BORDER SHADOW FIXED: the VS half of the FNF-3 ambiguity
**★★★★★ ROOT CAUSE (cited, not inferred). The ring draws were never dropped anywhere in the nvk
stream — they were shaded to nothing by the WRONG VERTEX SHADER.** Chain, all on disk:
- Guest (ghidra `default_decomp_all.txt:180059`): `FUN_82182008` sets VS `DAT_821F8548` +
  PS `DAT_821F8378`, then `FUN_8209D660(dev,0,0,0x80000000)` = **unbind stage-0 texture**
  (writes `dev+0x31B0=0`, clears the type bits of the `dev+0x480` fetch const), then 4x
  `FUN_82180978` (edge strips: `FUN_8209D800(dev, prim=6, n=4, stride=12)`) + 4x `FUN_821813A0`
  (corner fans: `prim=5, n=7, stride=12`). Vertex record = **{x, y, colourDWORD} = 12 bytes**,
  inner `DAT_82045504`=0xFF080808, outer `DAT_82045508`=0x00000000 pushed `DAT_8203B364`=16.0f out.
- Recorder/renderer: **stride 12 is the ring's unique signature in the whole stream** (192/192
  `st=12` lines in the t3 bank are it). The draws were recorded, batched, given a pipeline and
  rasterized every frame — banked proof in `/c/tmp/c3accept/t3/boot.log`: `[nvkdbg] f2400 b453..b460
  vs=5 ps=14 prim=6 n=4 st=12` / `prim=5 n=7 st=12`, `blendReg=07060706` (SRC_ALPHA/INV_SRC_ALPHA,
  op ADD), inside `[nvkseg] f2400 SEG [453,487)` = the **display** segment on surf 00358590.
  Zero `[nvk] no pipeline` lines. So (a) recorder skip, (c) blend decode and (d) wrong RT are all
  REFUTED; the death is (b), and it is a shader-identity bug.
- SPIR-V, read out of `render/shaders_futari.h` (spirv-dis by hand, `_tmpscripts/` scratch):
  `PS idx14 (0x8203D338, 36B)` = `out = interpolator16 * psConst.c2` and declares **only**
  input Location 16. `VS idx5 (0x8203BC00)` declares vertex inputs Location 0+4
  (POSITION + TEXCOORD0), writes interpolator 0 and **hard-zeroes interpolator 16**.
  `VS idx15 (0x8203D458)` declares Location 0+**8** (POSITION + **COLOR0**, host attr
  `B8G8R8A8_UNORM @+12`, vk_render.cpp:1794) and writes **interpolator 16 only**. So with idx5
  bound the ring shades to (0,0,0,0) and its own alpha blend leaves the destination bit-identical:
  **emitted, rasterized, invisible.** Exactly the FNF-3 TOP-MENU-background bug, mirrored onto
  the VS side.
- WHY idx5 won: `matchImLoad` keys VERTEX shaders on (first 32 ucode bytes, size) ALONE — the
  FNF-3 full-ucode FNV tiebreak is pixel-only on purpose ("a VS is never byte-equal to its capture:
  the D3D9 runtime patches its vfetch stubs at load time"). **Twelve** 132-byte shell VS share a
  byte-identical 32-byte prefix ({5,7,15,17,19,21,23,25,27,29,35,41}) so the lowest index took
  them all. Measured patch footprint this leg: the runtime blob differs from its OWN capture in
  only **10 of 132 bytes**, and from the sibling it was being confused with in 18-22.
**FIX (register-true, no synthesis — the guest's own draw now renders): full-ucode BYTE-DISTANCE
tiebreak for vertex shaders.** `_tmpscripts/gen_vs_ucode.py` emits `g_futari_vs_ucode[4052]` +
`g_futari_vs_ucode_off[51]` (captured VS ucode, same provenance/controls as `g_futari_ucode_hash`:
CTL-1 prefix+size reproduction 24/24, CTL-2 negative control, CTL-3 distance injective over
distinct programs, CTL-4 all 3 VS prefix-collision groups separated). `matchImLoad` measures the
distance **inside the existing prefix-match body** and only re-picks among candidates that already
passed — still a tiebreak, never a filter, so nothing that renders today can start being skipped.
Equal-distance ties are resolved to the lowest index ONLY when the captured bytes are identical
(the benign duplicate rows 21/25/27/29/41, 31/33, 37/39); a tie between different bytes gives up
and keeps the prefix result. Scoped to `RT_NVK>=2` so the legacy PM4 arm (the A/B control) keeps
its ~14 `g_curVsIdx == 5` predicates untouched. **LEVER `RVK_NOSHADOWFIX=1` reverts.**
New always-on census `[nvkring]` (stride-12 draws: vs/ps/prim/blend/vte/target/first+last vertex)
— a boot log now decides on its own whether the ring can reach pixels.
**RESULT (t6, ARM=nvk DUR=200, vs the c1 control).** `[vsdist]` reassigns exactly 4 runtime VS,
all 132-byte: `0x8CC5000 idx5->idx15` (**the ring**, dist 10 vs 22), `0x8CC3000 ->idx17`,
`0x8CA1000 ->idx21`, `0x8CAD000 ->idx35`; the 156/96/172-byte VS confirm their prefix match
(nearest == prefix winner). `[nvkring] #0..#7 f1810 vs=15 ps=14 blend=07060706 vte=43F rt=DISPLAY
v0={-32,-48,00000000} vN={672,-32,FF080808}` = the gradient is intact and on the display target.
PIXELS (banked `nvk_f*.png`, display-independent readbacks, median over samples, panel x400..878
y40..679; shadow band = 14px outside each edge minus wallpaper 26px further out):
`L +0.6 R -8.7 T +2.3 B +7.1` (t3, no shadow) -> **`L -27.9 R -51.4 T -18.0 B -6.3` (t6)**; the
right-edge profile ramps `8,14,20,26,...,106` over ~15px out of the panel edge = the #080808-class
16px ramp. **GATE: H0/G1/G2/G3/G4 all PASS** (demo tf .973 vs ctrl .968, uniq 157922, field resolve
uniq med 30013 tf .963, drive aligned), **zero VK errors, f11xxx in 200s**.
⚠ HONEST: **G5 still FAILS** — unchanged verdict from leg 10 and NOT this leg's class: the deciding
band is CAVELOGO = the class-D missing full-panel background fill (leg-11 queue item 1, untouched
here). It did move a long way, .023 -> **.523** (ctrl self .943). Other bands t3->t6: DEMO
.437->.422, RANKING .004->.021, TITLE .039->-.053, LEGAL **.750->.540**. The LEGAL drop is
unexplained and is a median over n=4 test samples at a different sampling phase (t6 is DUR=200 vs
t3's 300) — it is NOT attributed either way; if the other three VS reassignments are ever suspected,
`RVK_NOSHADOWFIX=1` is the one-boot A/B.
⛔ **BACKLOG 4b's diagnosis is now WRONG twice over and should be CLOSED**: the ring is not gated
out by `menuLive`/overlay replay (that path is dead at RT_NVK>=2, leg 10 item 3 proved it), and
"the ring is drawn — with what colour/blend?" was the right question with an unexpected answer: the
colour and blend registers were always correct; the *interpolator carrying that colour* was zero.
⏭ LEG 12 QUEUE (leg-11 queue minus the shadow): (1) class-D cavelogo fill (`RT_NVKDBG=1
RT_NVKDBGEVERY=700`, census banked in t5); (2) A/B the leg-10 ring FORMAT change (`RT_NVKRING8=1`
control arm); (3) class-C bottom band retest; (4) heap high-water soak; (5) legal diagonal-streak
residue at SPIR-V/texture-routing altitude — **re-check first**: the `[vsdist]` machinery may have
already moved the vs47 self-composite class, and Class A was always a shader-identity-shaped defect.

**USER VERDICT (live, 07-29 ~19:xx): "woah i see border shadaooooowwww" — ring confirmed on screen. VS-identity tiebreak fix ACCEPTED.**

## legal streaks DIAGNOSED (07-29 late, decomp agent; full note ghidra_futari_decomp/NOTE_legal_streaks.md):
NOT feedback (leg-9 integrator RETRACTED — dwell rise = authentic type-in fade). IN-FRAME smear:
each glyph = 2 sprites (glyph + drop-shadow); the shadow rasterises as a streak. Suspect =
RECTLIST 4th-vertex uv synthesis (vk_render.cpp ~10307-10321). Authentic-art/missing-clear/uv-
offset all REFUTED with evidence. Discriminator (1 boot, no code): RT_NVKRESEVERY=7
RT_NVKDBGEVERY=2100 around f1995-2100 + RT_NVKOLDVS=1 arm. ⚠ [nvkvtx] must be widened first
(glyph rects never observed). Class A may share root with class D (same 0x170 tile grid).

## s2B leg 12 LANDED (2026-07-29) — ★★★★★★ CLASS A **and** CLASS D ARE ONE BUG: the int/float sniff dword
**ROOT (observed, not inferred). `vk_render.cpp` decided int32-vs-float stride-16 vertex records from
ONE dword — `looksFloat(gbe(0))`, the x of vertex 0 — and `looksFloat` answers "float" for
`0x00000000` (its `v == 0` clause). The LEGAL/CAVELOGO panel-BACKGROUND tile grid is one vs45/ps50
`prim=8 n=480 st=16` batch of int32 `{x,y,u,v}` records starting at x=0,y=0 (guest `FUN_880FFCE8` ->
`FUN_881538C0(0x170, ...)`, 32-px steps), so it presented `00000000` and the WHOLE batch decoded as
floats: 0x20/0x40/0x60 became denormals ~0 -> 160 rects collapsed onto the origin -> the background
fill VANISHED.** Banked proof, d1 boot (`/c/tmp/c3accept/d1/boot.log` f2100):
`[nvkrect] f2100 d5 vs=45 ps=50 prim=8 n=480 st=16 int16=0 sniff=00000000` with
`r1 raw={00000000 00000020 ...}` / `r8 raw={00000020 00000000 ...}` — unmistakable integers.
**THE BRIEF'S TARGET-1 SUSPECT IS REFUTED.** The first-ever full census of the glyph rects
(new lever, below) shows all **635** vs45 rects at f2100 are `16x8 px` with `uv extent 16x8`,
axis-aligned, `pos-extent == uv-extent` on every single one and **0** skewed rects: the RECTLIST
4th-vertex synthesis (`vk_render.cpp` ~10330) is exact and was never the carrier. Exactly ONE draw
in the entire vs45 stream was misdecoded — the tile batch.
**MECHANISM OF THE STREAK (why a missing BLACK fill is visible on a black panel).** The guest never
clears (leg-A §2, still true); its wipe IS those 80 opaque tiles, and they run AFTER the vs47/ps46
self-composite restore. With the wipe gone the restore's own slight affine resample is re-applied to
the whole field every frame and never erased, so each glyph leaves a geometric ladder of
progressively displaced ghosts — displacement proportional to position, hence the measured
"angle drifts 10-15 deg across the panel / affine, not a pure translation", and a *converging*
(not growing) ghost series, hence the constant 43% halo/content ratio that retired the leg-9
integrator model. One missing draw explains every measurement in `NOTE_legal_streaks.md`.
**FIX (2 lines of logic).** When vertex 0's x dword is all-zero the sniff walks forward to the first
NON-zero dword (up to 16 verts x 4 dwords) and sniffs that. Any draw whose `gbe(0)` is non-zero is
bit-identical to before, so nothing that renders today can change class; a genuine float quad whose
first corner is (0,0,0,0) still sniffs float on its next corner. **LEVER `RT_NVKOLDSNIFF=1` reverts.**
NEW INSTRUMENTS (both lever-gated, unset = byte-identical): **`RT_NVKVTXALL=<vsIdx>`** = `[nvkrect]`,
the full per-rect census (3 real corners decoded x/y/u/v + the raw guest dwords of all three + the
sniff dword), capped 6000 lines — the ~450 glyph rects had NEVER been observed by any bank;
**`RT_NVKRESWIN=<from>:<to>`** = frame window for the resolve PNG series, so a tight
`RT_NVKRESEVERY` can be aimed at one band instead of readbacking the whole boot (which both floods
the bank and slows the loop enough to shift the wall-clock nav drive off the sampled phase).
**RAW NUMBERS.** Panel rect x400..878 y40..679, display-independent readbacks.
LEGAL (d1 = pre-fix, d2 = post-fix, same drive, both DUR=100):
| frame | mean | p90 | frac>=200 | frac<=2 |
|---|---|---|---|---|
| c1 ref f2170 | 25.61 | 90 | 5.18% | 72.4% |
| d1 f2184 | 47.75 | 130 | 3.94% | **34.2%** |
| d2 f2184 | 26.62 | 115 | 3.82% | **68.6%** |
| c1 ref f2351 (plateau) | 33.81 | 166 | 7.86% | 69.7% |
| d1 f2366 | 59.44 | 156 | 5.71% | **27.5%** |
| d2 f2366 | **33.77** | 144 | 5.55% | **66.4%** |
panel pearson vs the frame-matched referee: **0.818 -> 0.920** (f2170) and **0.828 -> 0.927** (f2261).
CAVELOGO (class D): panel white>=200 **26.3% -> 96.7%** (referee 97.7%), mean **124.08 -> 250.15**
(referee 251.52). Lit content (frac>=200) is UNCHANGED across the fix on LEGAL — only the halo left.
**GATE (t7, ARM=nvk DUR=300 NVKRESEVERY=181, vs c1): H0/G1/G2/G3/G4 PASS and — for the first time —
G5_correctness PASS => `"VERDICT": "PASS"`.** demo tf .959 vs ctrl .968, demo uniq 149964, field
resolve uniq med 31042 tf .959, drive aligned, **zero VK/VUID errors, zero `no pipeline`, f14842 in
300s**. Band lumCorr vs c1 (t6 -> t7): **CAVELOGO .523 -> .971** (ctrl self .943 = above the positive
-control ceiling, and it is the deciding band), **LEGAL .540 -> .921** (ctrl self .658),
TITLE -.053 -> .082 (ctrl self .085), DEMO .422 -> .430 (ctrl self .286), RANKING .021 -> .025
(ctrl self .729 — still the one clearly-wrong gated band). Visual: t7 f2366 legal panel is
referee-indistinguishable (crisp glyphs + tight drop-shadows, streaks gone); t7 f3367 cavelogo panel
is full white with logo + "cave" + "PRESS START BUTTON".
⚠ HONEST: RANKING (.025 vs ctrl self .729) is untouched and is now the worst gated band — G5 passes
on medians, not on RANKING. TITLE's control has no positive control (.085) so it stays blind. The
LEGAL residual is ~3 points of dark-fraction (66.4% vs the referee's 69.7%) — a faint glyph glow,
not a streak. No user eyeball yet on leg 12.
⏭ LEG 13 QUEUE: (1) RANKING band (only clearly-wrong positive-controlled band left); (2) A/B the
leg-10 ring FORMAT change (`RT_NVKRING8=1` control arm) — still never run; (3) class-C bottom-band
retest; (4) heap high-water soak; (5) LEGAL residual glow at the SPIR-V/texture-routing altitude.

## ALPHA-1 CLOSEOUT (2026-07-29 ~20:xx) — heap soak PLATEAUS; RANKING splits into a metric artifact
## PLUS a real chroma defect the gate is blind to; alpha-1 package built + boot-tested. No code changed.
No source edit, no build, no commit this leg. Three items, honest results.

### 1. HEAP SOAK — ★ PLATEAU CONFIRMED. Leg-9's "monotonic climb, no plateau" flag is RETRACTED.
`ARM=nvk TAG=soak1 DUR=1200 NVKPNG=0 NVKRESEVERY=0 RT_NVKDBGEVERY=0 bash _tmpscripts/c3_fieldaccept.sh`
(bank `/c/tmp/c3accept/soak1/boot.log`; all dumps + censuses off so observer cost is ~nil).
The `[heap]` census is a 16MB-boundary print on `g_heap`, the BUMP POINTER (`out_reco/harness.cpp:72`)
— it is guest ADDRESS-SPACE high-water, not host RSS, and it can only ever rise. 27 lines total, tail:

| MB | at frame | live | pooled |
|---|---|---|---|
| 336 | 1801 | 382 | 788 |
| 368 | 2401 | 557 | 1096 |
| 384 | 2401 | 696 | 1152 |
| 400 | 7201 | 729 | 1355 |
| 416 | 7201 | 785 | 1454 |
| **432** | **12001** | 746 | 1766 |

**LAST GROWTH AT f12001 (~200 s). The run reached f71701 (1200 s, 59.7 fps sustained) — 59,700
frames / ~16.7 minutes / ~12 attract cycles of ZERO further growth. Post-plateau rate = 0 MB/h.**
Free pool in steady state at the end: `[pool] freed n=16500 cum=1283MB pooled=1774` — 1.28 GB of
guest allocation recycled through a pool that hovers at ~1800 entries, i.e. the pool is serving
100% of demand. Zero VUID / VK_ERROR / `no pipeline` / FATAL across the whole 20 minutes.
**VERDICT: pool WARM-UP, not a leak. Alpha-safe. No fix needed, no known-issue growth bound required.**
Why leg 9 read it wrong: its DUR=240 window ended almost exactly at the last boundary crossing, so
the entire observation was the warm-up ramp with the plateau one sample beyond the horizon.
⚠ Standing bound for future soaks: 432 MB. A boot that crosses ~450 MB IS new and should be reported.

### 2. RANKING BAND — ★ IT IS **BOTH**, and the second half is the more important finding.
**(a) The .025 headline is ~96% a PAIRING ARTIFACT — and it is a SCROLL phase, not a page cycle.**
The ranking screen is a continuously vertically-SCROLLING list (not Reco/Palm paging as the brief
guessed). Re-pairing each t7 RANKING frame against its best c1 RANKING frame under a vertical-shift
search (dy in [-260,+260], luma pearson) moves the band median **0.025 -> 0.638**, against a control
self-corr ceiling of **0.729**; best individual pairs 0.772 / 0.747 / 0.738 = AT the ceiling.
Required dy runs -234..+4, i.e. the two arms are essentially never at the same scroll offset.
Phase-aligned pairing on `f % 4800` does NOT help (0.033) — cycle phase is not scroll phase.
Structural cause: c1 carries **n=3** RANKING samples for the whole run (the old arm's sampler is
`rvk_state.txt`-change-driven on a 0.4 s poll) against t7's n=24. `nearest()` pairs on timeline
distance and cannot repair this; it needs a per-frame scroll/FSM phase key that **neither arm records
today**. => G5's RANKING number is not trustworthy as stated. Document as a metric limitation; do
NOT chase it as a render defect.

**(b) THE REAL DIVERGENCE — and it is NOT ranking-specific: BACKGROUND-ART CHROMA IS WRONG ON nvk.**
Decisive frame pair (TITLE band, near-static, so alignment is not a confound):
`t7/nvk_f3640.png` vs `c1/disp_t62897_f3615_fsm3_d89.png` — geometry is pixel-aligned (same waves,
same foam, "RANK 2" and "PRESS START BUTTON" in the same place), luma pearson .668, but:

    channel means   T = (136.8, 102.2,  35.7)      C = (31.1, 131.0, 193.8)
    identity MAD 106.9   ->   BGR-permuted MAD 44.8
    corr(t.R,c.G)=.722   corr(t.B,c.R)=.671   corr(t.G,c.G)=-.005   corr(t.R,c.B)=.646

No permutation restores it (best mean-channel .58) — each output channel is a BLEND of two adjacent
input channels. That is a packed-format channel-BOUNDARY mangle, i.e. **exactly the leg-9 CLASS-B
"byte-exact channel remap + saturating subtract = format REINTERPRETATION fingerprint", UNCURED.**
Panel-ROI R-B by band (t7 / c1): TITLE **+70.5 / -95.2** · RANKING **+42.4 / -31.7** ·
DEMO **+55.9 / -46.6** · LEGAL **0.0 / 0.0 (grey)** · CAVELOGO (white fill, chroma-degenerate).
**★★★ 14th LYING-INSTRUMENT LESSON: G5 is a LUMINANCE correlation and is STRUCTURALLY BLIND to this.
The two bands that PASS (LEGAL .921, CAVELOGO .971) are the only two ACHROMATIC bands in the attract;
all three chromatic bands are the ones scoring .025 / .082 / .430. The leg-12 `"VERDICT": "PASS"` was
won on the two frames where colour cannot be measured.** G5 needs a chroma term before it can be
called a content-acceptance gate again.
**NOT A REGRESSION — constant across every nvk bank ever recorded.** TITLE-phase R-B:
`t1 +70.2 · t3 +72.2 · t5 +70.2 · t6 +68.7 · d2 +61.8 · t7 +70.5` vs `c1 -95.2`. Legs 10/11/12 did
not move it; leg 10's ring-format change is therefore NOT implicated as the cause, though its
never-run A/B (`RT_NVKRING8=1`) is still the cheapest first discriminator.
**NO FIX LANDED** — not small, and not yet register-true-diagnosed (the old path's `RVK_WALLBG=4`
file-blit is dead code at `RT_NVK>=2` per leg-10 item 3, so the carrier is nvk's own guest-texture /
resolve decode). Diagnosis banked; this is now the top open visual defect and a plausible alpha
blocker — **USER EYEBALL CALL NEEDED** (the user has played this build and not flagged it, so either
it reads as acceptable in motion or attention was on the panels; do not assume either way).
Probes kept in the session scratchpad: `rank_probe.py`, `rank_probe2.py`, `rank_chroma.py`,
`rank_montage.py`; montages `pair_2639_vs_2623.png` and `title_pair.png`.

### 3. ALPHA-1 F&F PACKAGE — BUILT AND BOOT-TESTED.
`dist/futari_alpha1/` (829 MB, 59 files) and `dist/futari_alpha1.zip` (**686.5 MB, 60 entries**).
Contents: `futari_merged.exe` (07-29 19:10 build, leg-12) · `shell/default.xex` · full `assets/`
(user ruling: early alpha keeps assets in — 54 files, 849,309,632 bytes, count+byte-size verified
against source) · `save_freshcard/` seed · `logs/` · `README_ALPHA1.txt` · `Futari 1.5 ALPHA 1.bat`.
Launcher env MIRRORS the accepted Desktop icon (`Futari 1.5 PLAY TEST.cmd` -> `playtest.sh` MODE=play,
plus `RT_NVK=2`), with dev telemetry dropped (`RVK_PERFLOG` `RVK_FPS` `RT_MSGLOG` `RT_CREDLOG`
`RT_SHIPX` `RT_SCENELOG` `RT_FSMLOG` `RT_LOADPROBE2`). `RT_SAVE=save`, auto-seeded from
`save_freshcard` on first run. Deliberately NOT added: `RVK_DECOUPLE` (playtest.sh does not set it;
its feel-check is still queued). Exe imports only system DLLs (kernel32 / user32 / ole32 / winmm /
vulkan-1 / xinput*) — no redistributable needed.
**★ THE BOOT TEST EARNED ITS KEEP — it caught a real launcher bug on attempt 1:** a bare
`futari_merged.exe ...` invocation is not found when `NoDefaultCurrentDirectoryInExePath=1` (set in
this session's env; would bite any tester who has it). The shipped log read
`'futari_merged.exe' is not recognized...`. FIXED: every path is now built from a trailing-slash-
stripped `%~dp0`. Also replaced the locale-dependent `%DATE%/%TIME%` log stamp (first run emitted
`0729Wed_202620`) with a PowerShell `yyyyMMdd_HHmmss` stamp.
**RE-TEST PASS**, booted from a fresh extraction of the ZIP into a temp dir via the shipped .bat:
`[nvk] submit f1` -> `f6901`; **22/22 `[file] open` resolved into the extracted package's assets/**;
`motion/title.lzx` + `menu_title.lzx` + `logo.lzx` loaded = shell TITLE reached; `save/` auto-seeded;
**zero VUID / VK_ERROR / `no pipeline` / FATAL and zero missing-file complaints**; heap at 222 MB when
killed (on the soak's warm-up curve, as expected).
README_ALPHA1 known-issues list: (1) background/wallpaper chroma — named as the big one, with the
measured numbers, (2) no audio, (3) Score Attack signed-out by design, (4) legal-panel faint glow,
(5) memory settles ~430 MB with a "report it above 450 MB" bound, (6) ranking bg per (1), (7) 1080p
window / 720p compose. Plus a revert-lever table (`RT_NVK=` / `RT_NVKOLDVS` / `RVK_NOSHADOWFIX` /
`RT_NVKOLDSNIFF` / `RT_NVKRING8` / `RT_NVKOLDRTSZ`) so a tester can A/B before filing.

⏭ **LEG 13 QUEUE (re-ranked by this leg):** (1) ★ BACKGROUND CHROMA — one boot with `RT_NVKRING8=1`
as the A/B control arm (never run), then the guest-texture decode path; top defect, needs a user
eyeball call on whether it blocks alpha. (2) add a CHROMA term to G5 (it is luma-only and passed on
the two achromatic bands). (3) RANKING: record a scroll/FSM phase key on the nvk arm so the band can
be paired at all — until then treat G5 RANKING as BLIND, not failing. (4) class-C bottom-band retest.
(5) LEGAL residual glow at SPIR-V / texture-routing altitude.
**RETIRED FROM THE QUEUE:** heap high-water soak (item 4 of legs 10-12) — CLOSED, plateaus at 432 MB.

## s2B leg 13 LANDED (2026-07-29) — ★★★★★★ PANEL-ART CHROMA FIXED: one missing `p0 ? 0.0 :` in XenosRecomp
**THE BRIEF'S PREMISE IS REFUTED.** It is NOT a packed-format channel-boundary mangle, not the
leg-10 A2B10G10R10 ring format, not a fetch swizzle/endian, not the blit, not the nvkres unpacker.
Every one of those converts by name and none can produce a SUBTRACT — and the measured transform
has one. **Nothing in the leg-10 format work is implicated; `RT_NVKRING8=1` was never needed.**

**WHERE IT ENTERS (cited, zero-boot, from the t7 bank alone).** The 320x240 ring RT (surf
`0269F320`, cfmt 3) takes exactly ONE draw per frame — `[nvkdbg] f3600 b52 vs=21 ps=20 prim=8 n=3
st=16 tex=0xEF4D000(640x512 fmt6)->idx108<RESOLVE vp=320x240`, `blendReg=00010001` (ONE/ZERO, no
blend) — then `vkCmdBlitImage`s 1:1 into the ring slot. Its INPUT, the field resolve `EF4D000`, is
colour-correct (`nvkres_f3620_EF4D000_640x512.png` mean (109.2,181.5,225.8), R-B **-116.6**, blue,
= the referee). Its OUTPUT slot `106BD000` is olive/red (178.5,152.6,106.0, R-B **+72.5**). Box-
downsample the field 2:1 and the map is EXACT: `out = (G, R+B-G, R)`, **MAD 0.20/255** over 58k
px (lstsq matrix `[[0,1,0],[1,-1,1],[1,0,0]]`, residual 1.13; identity MAD 66.8). Re-expressed in
HSV terms with `(v,t,p,q)` the ladder's own registers: input sector 3 (max=B) must emit `(p,q,v)`
and emits **`(q,t,p)`** — **MAD 0.0**, i.e. V never reaches the output.

**ROOT CAUSE (one line, provable by symmetry).** ps idx 20 = guest `0x8203DBD8` = the SHELL's copy
of the HSV colour-filter ucode (gen_xrgen.sh's own note: byte-exact `cap_image.bin @0x3DBD8`,
code-after-DEF-pool == the ROM's `0x86D2040` = entry 49). Its HSV->RGB sector select is a
`PRED_SET*_PUSH` / `SETP_INV` predicate-stack chain. `XenosRecomp/shader_recompiler.cpp:815`
emitted **`SetpInv` dest = `{0} == 0.0 ? 1.0 : {0}`** — the ONLY Setp* in that switch without the
`p0 ? 0.0 :` guard (`SetpEq/Ne/Gt/Ge` -> `p0 ? 0.0 : 1.0`, `SetpPop` -> `p0 ? 0.0 : (x-1.0)`,
`SetpRstr` -> `p0 ? 0.0 : x`). SETP_INV is the stack RESTORE step: hardware resets the counter to
0.0 when it reads 1.0. Without the reset the counter sticks at 1.0 and every later `_PUSH` (which
fires only on counter==0) is dead, so the if/else-if chain collapses onto its first two branches.
Symbolic trace of the emitted ladder (`ladder2.py`): **as-built** sector 0 `vtp` OK, 1 `qvp` OK,
2/3/4/5 all `qtp` WRONG; **patched** all six sectors correct. Chromatic-only by construction — the
whole block is under `if (S != 0)`, **which is exactly why LEGAL/CAVELOGO always passed and why
G5 (luma-only) called it PASS in leg 12.**

**FIX (register-true, generated, no hand-synth).** (1) `shader_recompiler.cpp` SETP_INV gets its
`p0 ? 0.0 :` guard. (2) `bash render/gen_xrgen.sh` re-run: HLSL diff is EXACTLY the 5 SETP_INV
lines; SPIR-V diff is `g_xrgen_spirv_rom_ps49` 2879 -> 2975 dwords and **`rom_vs45`/`vs47`/`vs48`/
`ps50` byte-IDENTICAL** (negative control — they contain no SETP_INV). (3) `getOrCreateModule`
repoints idx 20 at `g_xrgen_spirv_rom_ps49` (same ucode, generated translation), mirroring FIX-A's
45/47 pattern. **LEVER `RT_NVKNOCHROMAFIX=1` reverts to the baked module.** Note the fix also
lands on entry 49 = the ROM gameplay HSV filter (same bug, same class) — that is a change in the
shipping gameplay path and is NOT covered by the lever; it is honest debt for a gameplay eyeball.

**NUMBERS (t8 = ARM=nvk DUR=300 NVKRESEVERY=181, vs t7 and c1).**
| pair | before (t7) | after (t8) |
|---|---|---|
| ring vs same-frame field resolve, 70 matched pairs | corr .96-.99, **MAD 18.1-37.2**, R-B **+34..+50** vs field **-29..-2** | corr **1.000**, **MAD 0.0** on every pair, R-B identical to the field |
| TITLE panel vs c1 f3615 | mean (130.1,96.2,29.2) R-B **+100.9**, MAD **104.8**, per-chan corr RR .485 **GG .038** BB .441 | mean (51.4,149.0,211.8) R-B **-160.5** (ctrl **-162.7**), MAD **31.5**, RR .616 **GG .670** BB .512 |
| DEMO band panel R-B median | **+37.5** | **-3.5** (ctrl **+2.4**) |
The ring is now BIT-IDENTICAL to its input: the guest's filter is identity at its own constants,
as the referee always said. R-B sign now matches c1 on every band.
**GATE (`c3_verdict --test t8 --ctrl c1`): H0/G1/G2/G3/G4/G5_correctness ALL PASS => `"VERDICT":
"PASS"`.** demo tf .962 vs ctrl .968, demo uniq 148174, field resolve uniq med 31475 tf .966,
drive aligned, **zero VUID / VK_ERROR / `no pipeline` / FATAL, f14701 in 300 s**. Bands t7->t8:
CAVELOGO .971->.974, LEGAL .921->.886, DEMO .430->.484, TITLE .082->.116, RANKING .025->.016.
⚠ HONEST: those band numbers are **luma** and are therefore blind to the thing this leg fixed — the
G5 chroma term (leg-12 queue item 2) is still not written; the chroma evidence above is the real
gate. LEGAL moved -.035 and RANKING -.009: both are within the sampling noise of achromatic /
scroll-phase-unpaired bands and neither is attributed. **No user eyeball yet on leg 13.**
⏭ LEG 14 QUEUE: (1) ★ user eyeball on leg 13 (panel art AND gameplay — ps49 changed too);
(2) add the chroma term to G5 so this class can never pass blind again; (3) audit the rest of the
BAKED shell shader table (rows 0..47) for SETP_INV — they were all produced by the same
XenosRecomp lineage, so any other shader using the predicate stack carries the same defect;
(4) RANKING scroll/FSM phase key; (5) class-C bottom band; (6) LEGAL residual glow.

**USER VERDICT (07-29 night): chroma fix CONFIRMED — "looks and seem to play great". Alpha-1 packaging deferred by user; continue development.**

## RVK_DECOUPLE DEFAULT FLIP — LANDED (2026-07-29 night). Backlog item 1 CLOSED.
**USER RULING: input feel ACCEPTED on the decoupled env ⇒ the flip is called.**

**CODE (`render/vk_render.cpp` ~9440, the one getenv site).** Default was `-1` (off). Now:
`decouple = getenv("RVK_DECOUPLE") ? atoi(...) : ((asyncRender && rbudgetEnvA != 0) ? 1 : 0)`.
So: **unset ⇒ 1 (decoupled)**; `RVK_DECOUPLE=0` still forces inline everywhere (revert lever,
unchanged); `RVK_DECOUPLE=1` still forces on. The unset default deliberately still HONORS the two
legacy inline pins (`RVK_ASYNCRENDER=0`, `RVK_RENDERBUDGET_MS=0`) so every forensic script that
pins them (fnf1/fnf2/fnf7_*/d1b_*/qa_dieloud/port_rdc_strip2) keeps its inline semantics — only
an env with NO pin at all gets the new default. That is exactly the flip plan's precondition
("they would override the flip"), inverted into a compatibility rule instead of a landmine.

**ENV PINS STRIPPED.** Ship envs turned out to carry NO `RVK_ASYNCRENDER=0` /
`RVK_RENDERBUDGET_MS=0` pin at all — `Desktop/Futari 1.5 PLAY TEST.cmd`, `_tmpscripts/playtest.sh`
and `dist/futari_alpha1/Futari 1.5 ALPHA 1.bat` were already clean, so they inherit the flip for
free with zero edits. Redundant `RVK_DECOUPLE=1` pins removed from `c3_fieldaccept.sh`,
`blob_probe.sh`, `shadow_save_ab.sh`, `c1_gate.sh`, `census_soak.sh`, `circles_hunt.sh`,
`fnf12_segdump.sh`, `m2hold_forensics.sh`. `fnf5_tickrate.sh:47`'s
`RVK_ASYNCRENDER=0 RVK_RENDERBUDGET_MS=0` was a MIRROR of the old ship env and was dropped (it
would have measured a config nobody ships); its bidirectional A/B is still `XLV="RVK_DECOUPLE=0|1"`.
DELIBERATELY LEFT ALONE (they are the A/B instruments themselves): `dec_soak.sh`,
`fnf5_bwedge.sh`, `playtest_decoupled.cmd`.

**GATE 1 — TICKRATE (`MODE=stage fnf5_tickrate.sh`, no XLV = the new default).** 11/11 in-stage
`field=1` windows: **59.926 / 59.944 / 59.971 / 59.934 / 59.926 / 59.935 / 59.957 / 59.931 /
59.964 / 59.927 / 59.938 /s** (welded baseline was 54.7-55). `[rvk][fast] present#1 f1 winOk=1`
with NO env pin = the default flip is live on the wire. PASS.

**GATE 2 — c3_fieldaccept `ARM=nvk TAG=t9 DUR=300`, `c3_verdict --test t9 --ctrl c1`:**
`H0/G1/G2/G3/G4/G5_correctness` all true ⇒ **`"VERDICT": "PASS"`**. demo tf .962 vs ctrl .968,
demo uniq_max 149411, field resolve `EF4D000` uniq med 27832 tf .953, drive aligned.
Bands (luma) CAVELOGO .938 / LEGAL .913 / DEMO .481 / TITLE .137 / RANKING .050 — all within the
leg-13 t8 envelope (.974/.886/.484/.116/.016; RANKING/TITLE remain the known scroll-phase-unpaired
blind bands). **f16501 in 300 s, zero VUID / VK_ERROR / `no pipeline` / FATAL.** 183 display
samples, 2235 resolve sets.

**★ FINDING THE FLIP PLAN DID NOT ANTICIPATE — the flip is INERT ON THE SHIPPING RENDERER.**
Under `RT_NVK=2` (what every ship env sets) `rt.cpp:2450-2457` returns before `rt_render_maybe()`,
so `rvk_present()` — the sole home of `RVK_DECOUPLE`, `asyncRender` and the whole render-worker —
is **never called**: the t9 bank logs **0 `[rvk][fast]` and 0 `[rvk][inline]` presents** across
16501 frames. `nvk_on_present_frame` → `nvk_frame_submit` is synchronous on the guest's Present
thread. Measured consequence, `MODE=stage XLV="RT_NVK=2"`: in-stage ticks **59.905-59.979/s over
11 windows** — nvk is already at rate with no decoupling at all, i.e. the FNF-5 welded clock does
not reproduce there because the nvk submit is cheap, not because it is decoupled. So the flip
(a) fixes the legacy `RT_NVK<2` path, (b) is a no-op for the alpha-1 package, and (c) leaves nvk
with NO decoupling safety margin — if nvk submit cost ever grows the welded clock returns and
`RVK_DECOUPLE` cannot rescue it. Banked as a known structural debt, not a defect today.
NOT COMMITTED (session rule). Build: `bash build_win.sh` LINK_OK, 83 objects.

## 2026-07-30 — OTHER-MODES FIRST LEG steps 1+2: tooling fix + mode-substitution guard + RT_MODEIDX

**§0 TOOLING FIX LANDED (xr-derisk XenonUtils/xex.cpp, BASIC branch):** allocation is now
`max(Σblocks, security->imageSize)` (make_unique value-initializes ⇒ shortfall stays zero).
GATE: kiniro_normal/kiniro_abnormal dump at exactly 0x7B0000 (8060928) and palm_normal at
0x910000 (9502720) — previously 0-byte with exit 0; positive control reco_normal re-dump is
MD5-identical to the banked ghidra_futari_decomp/reco_normal.img.bin (B56D2353…). All 8
modules are now dumpable; kiniro/palm recompiles are unblocked at the tooling layer.
★ SECOND LANDMINE FOUND EN ROUTE: `tools_src/build_xexdump.bat`'s final line
`echo BUILD OK -> %OUTDIR%\xexdump.exe` — cmd parses `->` as `- > file`, i.e. the bat
REDIRECTED "BUILD OK -" INTO THE EXE, clobbering every fresh build to a 12-byte text file
(the on-disk exe only worked because it predated the bat). Fixed (`echo BUILD OK: …`).
NB ghidra_futari_decomp is NOT a git repo — the bat fix lives on disk only.

**MODE-SUBSTITUTION GUARD + RT_MODEIDX (merged_xex.cpp; NOTE_other_modes.md §5/§7 closed):**
`path_is_game` now matches the specific hosted basename `reco_normal` (case-insensitive
contains) instead of "reco"/"Module"; a foreign Module/*.xex request logs
`[xex] XexLoadImage(...) REFUSED: this build hosts reco_normal.xex only (mode-substitution
guard)` and returns 0xC0000135. `RT_LOADGAME` injection gained `RT_MODEIDX` (default 8 →
reco_normal; map in NOTE_other_modes.md §2). modeprobe.sh banked at _tmpscripts/.
GATE A (mp_refuse, title0+DOWN sub → modeIdx=1): the exact P1 line that silently substituted
now REFUSES; NO cg_v154.bin open, NO data-section load follows. Observed failure shape: shell
retry-loops the module load (repeating 1.2MB Mm allocs lr=0x82089F34, [bootsm] cur76=6
want80=5, heap high-water 241MB at 45s, no crash, 0 VK errors) — loud in the log, but an
attended wrong-mode selection will hang at boot, not error out; acceptable for a diagnostic
guard, noted as the UX debt if other modules ever ship.
GATE B (mp_ctrl, default drive → modeIdx=0): unchanged healthy boot — reco_normal DATA
sections + hmodule + ord1, GameEntry msgs 6/7/1/2/8/9/20/5, cg_v154.bin opens, f3301/60s,
zero VUID/VK_ERROR/FATAL. ⚠ Any pre-guard report of "mode X works" remains untrustworthy
(it was Ver 1.5); from this build on, wrong-mode is impossible to hit silently.
⏭ Remaining first-leg steps (NOTE_other_modes.md): (3) recompile reco_abnormal as its own
exe, (4) byte-signature hook census = the real cost estimate for modules 2-7, (5) boot gate.

## 2026-07-30 — G6 CHROMA TERM LANDED (leg-14 item 2) + ★★★★★ SETP_INV AUDIT: 4 MORE INFECTED ROWS

**G6 CHROMA (c3_verdict.py):** per-band MEDIAN of per-frame mean R-B over the ROI, deliberately
UNPAIRED (band means survive scroll-phase misalignment — the thing that blinds lumCorr on
TITLE/RANKING). Rule derived from banked-arm measurement (rb_probe, all numbers in the code
comment): live iff |ctrl_med| >= 10 and n>=3 both arms; FAIL iff test lands firmly in the
OPPOSITE half-plane (sign flip AND |test|>=10). Absolute-delta was proven unusable on the same
data: healthy-t9 TITLE swings to -75.9 vs ctrl -15.7 from phase mixing, and CAVELOGO carries a
standing ~-30 nvk-vs-old offset in EVERY arm incl. post-fix (reported achromatic, not gated —
possibly class-D residue, worth a look someday). VALIDATION: **t7 (the mangled bank that
G1-G5 called a full PASS) now VERDICT: FAIL on G6 alone** (DEMO +52.3 / RANKING +55.8 vs ctrl
-13.6 / -31.2); t8/t9 (user-accepted) stay full PASS; selftest OK. The SETP_INV class can never
pass this gate blind again.

**SETP_INV BAKED-TABLE AUDIT (leg-14 item 3; opus agent, report =
_tmpscripts/setpinv_audit_report.md + setpinv_scan.py + setpinv_audit.json):**
★ ROWS 22, 26, 28, 40 (guest 0x8203E2C8 / 0x8203EE88 / 0x8203F588 / 0x82043A38) CARRY THE
DEFECT — all PS, all variants of the SAME HSV colour-filter (identical ALU ladder, whole block
under the S!=0 CondExecPred; they differ only in sampling front-end: idx22 fetches 9 textures,
28 fetches 3, rest 1). All 44 other baked rows CLEAN; no VS anywhere uses the predicate stack.
Two independent methods agree exactly (ucode parser mirroring shader_recompiler.cpp bitfields
+ SPIR-V pattern match on the shipping modules); positive controls pass (idx20/ps49 flag x5,
vs45/47/48/ps50 clean, post-fix rom_ps49.spv zero unguarded sites); end-to-end control: carving
idx20 + running the FIXED vendored generator reproduces shipping rom_ps49.spv BYTE-IDENTICALLY.
Mapping lesson: shaders_futari.h guest_addr = ShaderContainer addr, ucode = container +
virtualSize + physicalOffset (extract_cache.cpp:121). Remediation DE-RISKED in scratch: all 4
carve byte-exact and translate clean (0 unguarded sites; all have spec_mask==2 so --athresh
applies). Repoint in getOrCreateModule, NOT shaders_futari.h (extract_cache output — hand
edits get silently dropped); separate lever RT_NVKNOCHROMAFIX2 so the accepted idx20 fix stays
independently A/B-able. OPEN: whether 22/26/28/40 are bound in shipping scenes is unproven
(needs a boot with draw census); regenerated DEF-pool constants vs baked counterparts unchecked
(the vs45-c255-class check) — both belong to the remediation leg.
⏭ NEXT: remediate the 4 rows (G6 now exists to gate it), then reco_abnormal recompile
(other-modes step 3) / audio register-true placement / RANKING FSM phase key.

## 2026-07-30 — CHROMA FIX 2 LANDED (rows 22/26/28/40) + GATE t10 FULL PASS incl. G6

Remediation of the audit's 4 infected rows, same shape as the accepted idx-20 fix: containers
carved BYTE-EXACT from cap_image.bin @0x3E2C8/0x3EE88/0x3F588/0x43A38
(render/tools/xrgen/make_shellps_containers.py; identical across caps_gp/caps_gp2/caps_s8, no
synthesis), translated by the FIXED vendored XenosRecomp via gen_xrgen.sh (step 2c; all four
--athresh, spec_mask==2), repointed in getOrCreateModule behind **RT_NVKNOCHROMAFIX2=1** (a
SEPARATE lever so the accepted idx-20 fix stays independently A/B-able) + renumber anchors in
matchImLoad so a reordered table aborts instead of repointing the wrong shader. DEF-pool check
(setpinv_defcheck.py) ALL EXACT: container pool == generated HLSL literals bit-for-bit on all
four + idx20 control; every DEF value already a SPIR-V literal in the baked module (14/14,
11/11, 16/16, 17/17, 11/11) — and loadShaderDefs() early-outs for PS so there is NO constant-
bank plumbing (the pool travels in-module, exactly the ps49 pattern). Regression guard: all
five pre-existing rom_*.spv byte-identical; gen_xrgen idempotent. Characterization from the
pools: row 40 = desaturate+sepia tint variant (BGR luma weights .11448/.29891/.58661, tint
240/200/145), row 28 = multi-tap offset sampler (1/320 offsets, 3 fetches), 22/26 ≈ idx20.

**GATE (c3_fieldaccept t10 ARM=nvk DUR=300; c3_verdict t10 vs c1): FULL PASS — first bank
gated with G6 live.** H0/G1/G2/G3/G4/G5/G6 all true; demo tf .963 vs ctrl .968; rb medians
DEMO -16.2/-13.6, RANKING -9.5/-31.2, TITLE -52.6/-15.7 (all correct half-plane); f16501/300s,
zero VUID/VK_ERROR/no-pipeline/FATAL. ★ BIND CENSUS ANSWER (the audit's open question): ZERO
[rvk][chromafix2] lines in 16501 attract frames — none of rows 22/26/28/40 binds in the
attract cycle; idx 20 remains the attract path's only HSV filter (its chromafix line fired as
always). The 4-row fix is LATENT in attract — correct-by-construction (same generator, same
controls as the accepted idx20) but visually unexercised until a scene binds them (row 40's
sepia suggests pause/continue/damage-flash class scenes; gameplay/menus beyond attract
unprobed). If a future scene shows a chroma defect with these rows bound, RT_NVKNOCHROMAFIX2
is the bisect lever. Hygiene gap kept scoped: idx 20/45/47 still have no renumber anchors.
⏭ NEXT: user eyeball (leg-13 panels + general play); reco_abnormal recompile (other-modes
steps 3-5); audio register-true placement; RANKING FSM phase key (its ctrl n=3 makes both G5
and G6 thin there).

## 2026-07-30 — MODE-SWITCHING RESEARCH VERDICT (2 opus agents: in-repo mechanism + prior art)

Reports: _tmpscripts/namespacing_research_repo.md + namespacing_research_priorart.md. The two
converge independently on ★ ONE DLL PER GAME MODULE, host-owned resolver — not N exes, not
recompiler namespacing.

**The banked "LARGE — new subsystem" sizing was wrong in BOTH directions:**
- WRONG-PESSIMISTIC: the unload→reload cycle ALREADY RUNS IN-PROCESS TODAY (banked logs
  c1_ctrl.log etc: msg13 → msg3 → both game threads self-terminate → XexUnloadImage → menu
  rebuilt → second [modeidx] → XexLoadImage → DllMain call#2 → ROM reopened). "Guest-image
  swap" = removing the `attached` one-shot at merged_xex.cpp:143 around code that already
  re-images .data and re-runs DllMain. The mapping table is RUNTIME DATA (flat PPCFunc* array
  in the guest arena, populated by a host loop); rt_indirect_call (out_reco/rt.cpp:354) already
  range-dispatches two modules with hardcoded bounds — "swappable PPCFuncMappings" = 3
  constants → 3 variables. Generated code never references PPC_IMAGE_BASE (0 of 33 files).
- WRONG-OPTIMISTIC: "every symbol collides" is FALSE and that's WORSE — under /FORCE:MULTIPLE
  a second same-base module links CLEAN on ~1017 shared fn-start names (reco_abnormal) and
  boots running silently-mixed code = the §7 hazard one level deeper. Link-order-as-semantics
  cannot host two 0x88 modules safely; real scoping (DLL link units) can.

**PRIOR ART:** upstream XenonRecomp has NOTHING (verified: full TOML surface has no module/
prefix/base concept; recompiler emits source only — packaging is the consumer's). N64Recomp
solved the identical problem (overlays at same VRAM, issue #78/PR #87: section-index symbol
namespacing + runtime-mutated func map); psxrecomp = existence proof for per-overlay NATIVE
DLLs dispatched at runtime; UnleashedRecomp never faced it (one xex + recompile-time .xexp).
On real HW two modules can't share 0x88000000 either ⇒ table-swap is the AUTHENTIC semantics.
⚠ Licensing: N64ModernRuntime/librecomp is GPL-3 (clean-room only); psxrecomp PolyForm-NC
(cite, never copy); XenonRecomp/N64Recomp MIT.

**COST:** per-module recompile is IDENTICAL under every packaging (~10-14 legs for all 8:
own XenonRecomp run + 57-table switch sweep (dominant) + SDK-oracle harvest + hook
re-derivation + GameEntry re-translation). Packaging delta ≈ 3-4 one-time legs, and the two
big items are NOT namespacing: (1) merged_xex.cpp = 7609-line mixed TU (163 game + 144 shell
hooks) must be cut along the module line; (2) renderer caches keyed by guest address
(0x887518D0, {44,0x880094d0}) must invalidate on swap = the likely first-bite hazard. Hook
census correction: 163 game hooks but only ~4 non-logging + 5 nvk taps (byte-identical in
reco_abnormal, transfer free) + MATCHED GameEntry + ~6 bridge scalars are load-bearing.
Host ABI a game DLL needs ≈ 70 symbols (59 kernel stubs + ~10 helpers); game tree has ZERO
real sub_82 refs = already a clean shared-object candidate. llvm-objcopy --prefix-symbols is
UNSUPPORTED for COFF (probed) — no objcopy shortcut. N-exes rejected: permanently lying
in-game menu (7/8 rows refuse or visible ~20s re-exec) on a menu that provably works, and no
prior art chose it. Single-exe symbol_prefix (~12 fmt::format sites) = fallback, shares ~all
runtime work with the DLL path.

**RULING ADOPTED: build reco_abnormal as a DLL from day one** (retrofit later = ~3 legs + a
throwaway launcher). ⏭ DE-RISK BOOT (cheap, needs no second module): env-lever the `attached`
one-shot, drive msg13 → menu → re-select, verify the forced re-image + re-DllMain is clean.

## 2026-07-30 evening — ★★★★★ RELOAD DE-RISK PASS (user-driven) + ★★★★★★ CENSUS: reco_abnormal = reco_normal+8

**RT_REATTACH LEVER + USER-DRIVEN PROBE (playtest_0730_1933.log): the runtime module-swap
lifecycle is PROVEN CLEAN in-process.** Lever: g_game_unloaded set by __imp__XexUnloadImage
(stubs.cpp), consumed in the XexLoadImage attach block (merged_xex.cpp) — after a genuine
unload, the next load re-runs the FULL attach (fresh .data/.bss re-image + DllMain #2) instead
of the one-shot's stale-state reuse. TWO full cycles user-driven (A,B,A quit → re-select):
msg13 → unload → [xex] RT_REATTACH → re-image 6060812 B → DllMain r3=1 → msgs 6/7/1/2/8/9/20
all call#2 → cg_v154.bin reopened → 59.9fps, ZERO VK errors, clean close. Measured debt: heap
high-water 384→400→416MB = ~16MB CRT-arena leak per reload (re-imaged .data drops arena ptrs;
documented in the lever comment; real swap wants guest-heap reclamation eventually). ⚠ TWO
SCRIPTED ATTEMPTS MISSED the quit (reattach_t1/t2: NAV B-presses never reached the prompt —
the A,B,A quit is state-timing-finicky; manual drive found it immediately. Lesson: attended
probes are cheap where NAV calibration isn't). The DLL-per-module design's riskiest unknown is
retired — the swap point works on the shipping build with the resident module.

**HOOK CENSUS VERDICT (_tmpscripts/abn_hook_census.{md,json,csv}, 462 addrs, positive-control
gated): ★ reco_abnormal IS reco_normal WITH ONE 2-INSTRUCTION INSERTION** (li r11,9 / stw
r11,0x35C(r31) clamp inside sub_880DEF88 — a real ARCADE-vs-HI logic diff) — below 0x880DEF88
same addr, at/above 0x880DF080 EVERYTHING +8, zero violations. NOTE_other_modes.md §3's
28.1%/22.4% figures were DELTA-0-ONLY measurements (methodology artifact) — alignment-aware:
100.0% fn-start coincidence, 93.4% raw / ~97.6% reloc-masked word identity. 251/310 code addrs
re-point mechanically; all 5 nvk draw hooks byte-identical SAME ADDR (draw path transfers with
zero changes); GameEntry → 0x8824E6A0 (C1 MATCHED must be re-earned: 15 callees + 27 globals
shift); 59 NO-MATCH are twins-diverging-at-predicted-addr (median 7 insns in), not missing.
⚠ RISK CLUSTER: 15 unmatched hook_merged fns in 0x8808E740..0x880A3F98 = frame-lock/sound-
queue/scene-publisher band — module 1 likely needs its OWN pacing verdicts. ⚠ 135/152 DATA
rows are ZERO-BOTH (no information — never cite as "literals transfer"). +8 law is a RECO-PAIR
property ONLY; hirow/kiniro/palm need their own rigid-shift re-sweep (same delta-0 flaw
applies to their banked percentages, but no single delta can exist for palm_abnormal's
+0x10000 rebase). Census relayed to the in-flight recompile agent (switch tables via the split
rule instead of signature hunting).

## 2026-07-30 night — ★★★★★★ VER 1.5 HI FIRST LIGHT (modeIdx 1 / reco_abnormal, MODULE 2 BOOTS)

**futari_merged_v154hi.exe boots Ver 1.5 XBOX-360 MODE through the REAL menu and renders the
attract at rate.** (/c/tmp/abn_firstlight.log, 85s probe): [modeidx] modeIdx=1 → guard ACCEPTS
reco_abnormal.xex (basename parameterized) → abn DATA image loaded (5 sections / 8022516 B vs
normal's 4 / 6060812 — genuinely the abn image; ⚠ the "from reco_normal.xex" log string is
hardcoded-cosmetic, fix someday) → ord1 = 0x8824E6A0 (parameterized) → DllMain r3=1 →
★ cg_v154hi.bin OPENED (first time ever) → attract DEMO runs (draws 288-295/f, banks 213-220,
savegame loads) → f4801/85s ~57fps, ZERO VUID/VK_ERROR/FATAL, zero [abnstub] fires (the 75
dead hooks = instruments not exercised in this scene; silence ≠ ported, per the recomp notes).
HOW: merged_xex.cpp gained -D-overridable GAME_ENTRY_ORD1_VAL / GAME_MODULE_BASENAME_STR
(defaults unchanged — normal build byte-equivalent semantics, both exes LINK_OK);
build_win_abn.sh passes 0x8824E6A0u / "reco_abnormal"; data bridge via XR_RECO_NORMAL env
(no code change needed — root reco_normal.xex copy is just the default).
⚠ HONEST SCOPE: this is FIRST LIGHT, not acceptance — [gemsg]/[msglog] instruments are DEAD in
this build (they hook 0x8824E698 = dead code here), the C1 MATCHED GameEntry must be re-earned
at 0x8824E6A0, the .data +0x60 literal sweep is unapplied (host literals read reco_normal
offsets — instruments/QoL mostly), pacing verdicts unowned (census risk band), and packaging
is the interim second-exe, NOT the ruled DLL design. ⏭ NEXT LEGS ranked: (1) DLL packaging of
out_reco_abn per the ruling (mixed-TU split starts here); (2) hook re-derivation via census
+8/+0x60 laws (mechanical, 251/310); (3) GameEntry MATCHED re-earn + c1_gate-class A/B gate on
the abn arm; (4) c3_fieldaccept + G1-G6 verdict vs its own control arm; (5) user eyeball of HI
mode (scoring/slowdown differences are AUTHENTIC content — reference epozzobon research before
calling defects).

**BLACK LABEL DLC LOCATED + STAGED (user pointed at the SDK-project copy):**
D:\360\00000002\496F816DD4B53DAEFF931838B6C69831AAD7663043\ (the exact content ID the
entitlement stub answers OWNED for) = spa.bin + Rom\{cg_black.bin 57.7MB, cg_blackhi.bin
216.9MB, dropprm.bl 3184B}. The 3 Rom files are COPIED into xr-work/assets/media/Rom/ (assets
are untracked — disk only; re-copy from D:\360 if the tree is rebuilt). Modes 4/5 (kiniro) are
NO LONGER ASSET-BLOCKED — NOTE_other_modes.md §6's blocker is cleared; all 8 modules now have
their ROM data on disk. Remaining for modules 2-7: recompiles only (kiniro/palm dumps already
unblocked by today's XenonUtils fix).

**★★★★★★ USER EYEBALL ON FIRST LIGHT (07-30 night): "oof it works!" — Ver 1.5 HI confirmed
working by the user's own eyes on the first-light build. First user-verified second module of
the campaign.**

## 2026-07-30 late night — ABN HOOK REVIVAL LANDED + BOOT GATE CLEAN (instruments live on HI arm)

Mechanical revival via generated rename header (out_reco_abn/abn_symbol_map.h from
tools_abn/gen_symbol_map.py): 85 shifted symbols → 170 #defines (sub_X AND __imp__sub_X — ★
TRAP: ## paste operands are NOT macro-expanded, so renaming only sub_X leaves __imp__##FN
unrenamed; both defines mandatory. #FN stringification keeps reco_normal names in LOG TEXT —
gate parsers unchanged, but name→address mapping must add 8). Census-cross-checked 85/85;
chained-expansion abort guard; ★ 2nd trap: regex comment-stripper ate a /* inside a string
literal, silently losing 8 hooks — only the link caught it; real tokenizer now. Force-included
ONLY on merged_xex.cpp + decomp (minus game_entry_msgs.cpp — EXCLUDED from abn build entirely,
45 reco_normal .data literals would ship wrong stores; generated body owns 0x8824E6A0, renamed
[gemsg]/[msglog] wrapper instruments it). Data literals: 6 macros behind #ifndef GA_DSHIFT
(default 0; abn -DGA_DSHIFT=0x60u): 0x885C1A20 field_active, 0x887AC958 game-main gate,
0x887AC973 write, 0x887AD58C/547/584 mailboxes — all census-range-verified. ★ Agent's judgment
call banked: renderer literals 0x884D66A8/678C EXCLUDED (lever-gated instrumentation only;
~80 sibling fields of the same structs unshifted — partial shift inside one struct worse than
uniform offset). 0x88252504/8/560 left default (differing region). Stub TU now EMPTY
(ABN_NOSTUBS=1 census link = 0 unresolved). Normal build PROVEN unchanged by -S assembly diff
per TU (COFF md5 worthless — 2-byte timestamp delta on identical source, positive-controlled).
**BOOT GATE (abn_revived.log, 85s): [gemsg] LIVE on the abn arm (27 lines, full boot chain
msgs 6/7/1/2... on the GENERATED GameEntry), modeIdx=1, ord1 0x8824E6A0, cg_v154hi.bin, attract
288 draws/f, ZERO errors.** ⚠ STANDING RISK (revive notes, ranked list inside): 17 revived +
17 never-dead hooks execute over census-diverging abn bodies (0x88168C88 gate-clear, 0x88168D50
ROM-main/romactive, sound producers, [fade] FSM, msg-5 pump band) — reco_normal's pacing
verdicts must NOT be inherited; abn arm needs its own FNF-5-class checks before any acceptance.

## 2026-07-30 late night — ★★★★★★ MODULES 2-7 CENSUS: "THERE ARE NO INDEPENDENT BUILDS"

(_tmpscripts/modules_shift_census.{md,json} + modules_shift_match.py; 11 positive controls.)
★ THE ARCADE→HI EDIT IS THE SAME 2-INSN INSERTION IN ALL THREE TITLES (li r11,9 / stw
r11,0x35C(r31), same offset, same 7 branch fixups): reco @sub_880DEF88 (+8 code / +0x60 data),
hirow @sub_880DE3E0 (+8 / +0x60), kiniro @sub_880E1B68 (+8 / +0x100 & +0xF0). Residual words
after the law: 3 per pair (enumerated — 2 .rdata float loads -0x30 + the GameEntry ptr +8 ⇒
residual ZERO). Fn-start coincidence 100.0% vs banked 28.1/1.8/9.4%. Cross-title: 84.7-97.4%
fn coincidence, 85.7-95.0% tail-only identity — the banked §3 figures were wrong by TWO ORDERS
OF MAGNITUDE (same delta-0 flaw). nvk draw path transfers to ALL SEVEN other modules (5/5
hooks full-window identical at +0/+16/+0x10000). palm_abnormal is closer to reco_normal
(84.7%) than to palm_normal (77.3%) — port modeIdx 3 FROM RECO. Millicode anchors §3 table
correct as written, all 8 verified.
★★ RETRACTION (supersedes the abn_hook_census "59 NO-MATCH" and the revival notes' standing
risk): the T1 mask didn't cover load/store displacement LOW-HALVES (compiler puts the low half
of a relocated global in lwz displacement, not just addi) — 59/59 "diverging" functions are
FULL-BODY IDENTICAL at +8. **reco_abnormal's .text differs from reco_normal in EXACTLY ONE
FUNCTION.** The "pacing band needs its own verdicts" risk is RETIRED (msg-5 pump / sound
producers / [fade] FSM / gate-clear all body-identical); FNF-5-class re-verification on the HI
arm downgrades from required to routine.
BOARD: modeIdx 1 MECHANICAL (done); 7 and 5 FREE given 6 and 4 (prediction from the identical
law, not yet measured); 6/4/2/3 SEMI (one leg each, 74-91% hooks + 52-55/57 tables mechanical
via lookup-table law). Caveat: sibling laws robust; cross-title segment boundaries must be
re-derived when porting (151→140 tie-break sensitivity in hirow).

## 2026-07-30 late night — DLL PACKAGING PLAN BANKED (implementation-grade, measured)

_tmpscripts/dll_packaging_plan.md (~965 lines, file:line-cited; llvm-nm/readobj MEASURED, not
grepped): ★ ABI = 64 true externals (59 __imp__ kernel stubs + rt_indirect_call + roundevenf +
3 CRT) via a FutariHostAbi bind-struct pair — DLL imports NOTHING (kills the lld-link
__imp__-vs-COFF-dllimport collision, CRT duplication, interposition classes at once; each DLL
predicted to link WITHOUT /FORCE:MULTIPLE = hard gate). ★ Host→game-tree coupling = 187
symbols concentrated in FOUR TUs (merged_xex 168, nvk_game_hooks 19, game_rt 4, harness 1);
vk_render/stubs/shellkernel = ZERO. ★ merged_xex.cpp split = ~19 cut points (310 defs coarsely
BLOCKED: 9 runs cover 288). Shadowed-hook seam FIXED BY the split (all 3 participants land in
the DLL link unit; PILOT_NOTES map-file recipe survives). ★ CRT stays /MT (measured; argue-row
flagged: two stderr instances vs order-parsing gates, mitigated by MSVC unbuffered stderr).
★ Renderer-cache truth: g.texCache/g_resolveTex/g_nvkRT/g.rModules/imCache have ZERO
invalidation; only rvk_handback_invalidate clears 4 of ~15 structures — L6 is the top risk,
"understated" vs the mechanism report's bet. ★ Two sites no prior report found: rt.cpp:238
guest-thread-entry bounds vs PPC_CODE_BASE (swapped module's threads would never start) +
sub_88083848 _initterm_e replacement (only host PPC_LOOKUP_FUNC on the game table) — both
fixed by construction in the DLL. ★ Q7 flag: dist alpha-1 ships no root reco_normal.xex yet
the bridge resolves one — grep an accepted playtest log. Execution = L0..L6, each LINK_OK +
bootable; risk L6 caches ≫ L3 descriptor-isation > L5 > L2 > L4 > L1/L0; Q1/Q2 answerable in
L0 (~1hr, no tree edit) gate the ABI.

## 2026-07-30 ~midnight — ★★★★★★ HI ARM FULL ACCEPTANCE + MATCHED RE-EARNED AT 0x8824E6A0

**ACCEPTANCE (abn_t1 nvk vs abn_c1 old, SAME HI content, modeIdx-1 drive): FULL PASS all gates
H0/G1-G6.** H0 valid = the band classifier holds on HI content; demo tf .985 vs ctrl .992,
G6 chroma live on DEMO+TITLE both correct half-plane, zero errors both arms. The HI arm now
has its own banked control (c3accept/abn_c1) and acceptance baseline (abn_t1).

**C1-CLASS MATCHED GATE PASS (module 2's GameEntry translation is live):** pilot exe (decomp/
game_abn/game_entry_msgs_abn.cpp) vs banked generated-only ctrl exe (futari_merged_v154hi_
ctrl.exe), identical 120s drives: determinism control PASS (2 pilot runs canonically
identical); ctrl-vs-pilot canonically identical 36/36 (canon widened: bare-hex arg-dump ptrs
02/03xxxxxx are the same heap class — mask them too). Coverage msgs {1,2,5,6,7,8,9,15,20};
12/13/14 live-fire = attended A,B,A quit debt (same shape as original C1). Registry:
0x8824E6A0 GameEntry_Dispatch → **MATCHED** (new `image` key names the module; keyless rows =
reco_normal). The campaign's translation bar now holds on TWO modules with ONE shared TU
lineage — the draft's zero-TODO quality (all addresses direct-evidence) survived the gate
unchanged on the first run.

## 2026-07-30 night — ★★★★★ ALPHA 1a SHIPPED (both modes) + ALPHA-1 CRASH CLASS FIXED (Q7 was real)

**Q7 ANSWERED: the shipped alpha-1 CRASHED AT MODE SELECT** (its own boot-test log
futari_alpha1_20260729_201519.log ends in SIGNAL 0xC0000005 fault at 0 right after [modeidx],
zero [xex] lines) — dist ships no root reco_normal.xex and sets no XR_RECO_NORMAL, so
LoadFile returned empty and ParseImage null-dereferenced. The 07-29 "boot-tested" verdict only
covered boot-to-attract. FIX: rt_load_game_data_sections resolution ladder (XR_RECO_NORMAL →
cwd-local <basename>.xex → RT_GAME_ROOT/media/Module/<basename>.xex) + DIE-LOUD all-fail
(_Exit(7) with the tried-paths list) + the cosmetic "from reco_normal.xex" log string fixed
(prints the chosen path). basename comes from GAME_MODULE_BASENAME ⇒ the HI exe self-resolves
reco_abnormal.xex with NO env.
**dist/futari_alpha1a/ + futari_alpha1a.zip (678 MiB): both exes, two launchers ("Futari 1.5
ARCADE - ALPHA 1a.bat" / "Futari 1.5 XBOX 360 - ALPHA 1a.bat"), README_ALPHA1A (authentic-
slowdown note for HI; in-game cross-mode select refuses by design), shared save folder.
BOOT-TESTED FROM THE SHIPPED LAYOUT: both modes resolve their module from assets/, open their
own ROM (cg_v154.bin / cg_v154hi.bin), attract runs, ZERO VK errors.** Landmine: stray
futari_merged_v154hi_ctrl process survived name-list kills — kill futari* by WILDCARD
(Get-Process -like futari* | Stop-Process), name lists rot as exe variants multiply.

## 2026-07-31 ~0:xx — L2 SPLIT LANDED + BOOT-GATED; HI TEXTURE CORRUPTION: ROOT + MAJOR FIX (residual open)

**L2 (merged_xex 3-way split, agent + boot gates): PASS.** merged_game.cpp (166 sub_88 hooks) /
merged_shell.cpp (157 sub_82 + idle-loop) / merged_bridge.cpp (Xex fns + data bridge +
RT_REATTACH) / merged_common.h; original banked as merged_xex.cpp.bak_l2split. Agent's static
gates: defined-externals 4 explained deltas (g_js_* → C++17 inline, COMDAT-proven single
instance), undefined 428=428 exact, 8/8 disasm-identical spot checks, /MAP 53223-row compare
clean, abn_symbol_map + census regenerate identical, 0 lines lost. ★ ONE GENUINE ENTANGLEMENT
(plan §2.2 missed): g_js_menuState/taskAlive/dlgAlive cross the module line (shell writes,
game reads 1 diagnostic site) — inline-variable fix OK in-exe but BREAKS at E6 DLL boundary;
resolution = move the [jankstate] read shell-side at L3 (it is log-only). Plan corrections:
hook census 326 not 310 (regex missed 4 wrapper families); §1.1's 64-symbol ABI is complete
for the GENERATED tree only — merged_game.o adds rt_audio_bridge_*, rvk_handback_invalidate,
rt_kick_capture(weak), g_import_calls (gen_host_abi.py must scan it too or L4 aborts on
contact). **MY BOOT GATES: A/B instrument-stream diff vs pre-split baseline exes (banked
_tmpscripts/l2_baseline/): both arms canonically identical 69/69** (canon hardened AGAIN:
mask hex tokens by VALUE in the guest-heap window 0x100000..0xFFFFFFF — 0x01-range and
leading-zero pointers slipped the prefix masks; drop rate-limited msg-5 heartbeat repeats =
timing interleave). DllMain/_CRT_INIT green both arms, 0 errors. [jankstate] NOT exercised by
this drive (dialog-path drive debt).

**★★★★★ HI TEXTURE CORRUPTION (user screenshots, in-game): ROOT-CAUSED + MAJORLY FIXED,
residual honestly open.** User report: 360-mode gameplay = shredded/noise background;
ARCADE fine. REPRODUCED in-tree (training drive A/B, PNG dumps: /c/tmp/hi_texhunt/).
INSTRUMENT-SILENT (0 VK errors — lying-instrument roster grows). ROOT: cg_v154hi.bin = 211MB
vs ARCADE 58MB — the HI engine STREAM-CYCLES texture pages through a guest pool (8+
[texreval3] content-change fires on 0x26EE000/0xF32000/0x1284000 per run vs ZERO on ARCADE =
the discriminator); g.rTexIndex's reval3 only hashed every 30th hit → permanent strips-of-
stale. This is C2 residual risk #3 (dirty-range/CPU-upload class) surfacing, and FNF-1's
transient is the same class at ARCADE boot. FIX 1: hash EVERY hit (hash = 64 sampled dwords ≈
free; decode only on real change; RVK_TEXREVAL3THROTTLE=<n> restores old cadence). FIX 2:
adaptive density — pages with >=2 observed changes get 1024-sample hash (partial band rewrites
were invisible to 64 samples). A/B PNGs: gross shredding CURED (hi_texhunt f2879 vs
hi_texfix f2880 — scenery/enemies/waterfall render). ⚠ RESIDUAL: sparse speckle + a few stale
tiles remain; ★ WARM-CACHE CONFOUND discovered — a rerun with the 211MB ROM in OS file cache
fires ZERO revals (streaming wins the race) yet still shows residuals ⇒ the residual class may
NOT be stale-cache at all (candidates: mid-write decode tear, resolve/self-composite class,
or authentic-vs-not unknown). USER COLD-BOOT = WORST CASE of the cured class. ⏭ NEXT PROBES:
cold-cache repro (flush file cache / first-boot-after-copy), RVK_RAWDUMP2=0x26EE000 timeline,
per-band residual classification vs ARCADE control frames. Proper fix long-term = dirty-range
write hook (streamer family, benefits FNF-1 too).

## 2026-07-31 morning — HI BACKGROUND: NOT staleness, NOT tiling — AN UNCAPTURED FILL PIPELINE

User retest on the FIXED build: corruption persists (screenshot; log futari_alpha1a_xbox360_
20260731_052013). EVIDENCE CHAIN (all banked): (1) RVK_REVAL3DUMP (new lever): the decoded
page is 100% structured noise at EVERY re-decode — never valid, never partially valid ⇒ not a
race/staleness class at all. (2) RVK_RAWDUMP2 raw bytes: entropy 2.95 bits, 52% zeros, 16-bit
words dominated by 0/1/2/0x5000 — the page content is NEVER pixel data in guest RAM.
(3) RVK_FETCHPROBE (new lever): ALL vs45/ps50 field draws sample an identical fetch class
tf={84004802,BASE|043,003FE1FF,00000C14,0,200} = fmt3 512x512 pitch=512, bases = a rotating
0x19xxxxxx-0x1Axxxxxx pool (+0xBBAxxxx early) — vs ARCADE-style clean atlases (fmt6 1024²,
tf3 upper bits set, tf4=3). (4) Offline linear-1555 decode of the raw page = ALSO noise
(tiled-vs-linear eliminated). (5) Resolve census: NO resolve/SETRT traffic ever targets the
pool (dsts are 0xF-0x11 range only). ⇒ VERDICT: the HI engine fills its background pool by a
mechanism the port does not capture (candidates: GPU render-into-pool via a resolve/blit path
we don't segment on the abn arm; a CPU blitter/expander from index data (the 0/1/2-word
content = tile indices feeding an expander?); a game-module D3D twin (draw kernel
8209D800-class deferred writes / IB blob) not hooked for this class). ARCADE never exercises
the mechanism (its field pool = captured resolves + resident atlases). The texreval3
improvements from last night remain CORRECT (they cured the genuinely-stale class visible in
the in-tree A/B) but cannot cure pages whose RAM never holds content. Levers added:
RVK_REVAL3DUMP, RVK_FETCHPROBE (both default-off diagnostics). Alpha guidance: ARCADE solid;
360 mode = known-issue until this leg closes.

## 2026-07-31 night — ★★★★★★ HI BACKGROUND CURED AT THE ROOT: 512MB PHYSICAL-ALIAS / ALLOCATOR

**RE VERDICT (agent, _tmpscripts/hi_pool_fill_re.md — zero-boot, evidence-grade): THERE IS NO
MISSING FILL PIPELINE.** The pool IS filled normally, at guest addresses >= 0x20000000; the
game converts pointers to GPU-physical with `& 0x1FFFFFFF` (sub_8807B4B0, out_reco_abn/
ppc_recomp.2.cpp:11004 — a PM4 emitter; 19 fns / 40 sites, byte-identical in ARCADE), which
strips bit 29 and ALIASES those pages onto live low memory. My "noise texture" dumps were
literally a PM4 command buffer (parses clean: 1169 IM_LOAD, 895 LOAD_ALU, 36 INDIRECT_BUFFER,
19 DRAW_INDX_2; its IB targets are the documented static UI blob) sitting at the aliased
address. 31/31 corrupt bases = exact +0x20000000 aliases of already-handed-out heap. Fetch
constants were PERFECT (6061/6062 preceded by TYPE0 header reg 0x4800 cnt=6 — the port's abn
capture was right; the GUEST wrote a masked address). ARCADE peaks 384MB (under the line), HI
832MB (over) ⇒ 100% DATA-DRIVEN divergence, all 3 C2 residual risks EXONERATED, and last
night's "uncaptured fill pipeline" hypothesis is RETRACTED.
**ROOT: rt_alloc (harness.cpp) is a bump allocator whose only recycling is EXACT-SIZE pool
matching — against variable-size stage assets it never reuses, so the pointer climbs past the
Xbox's real 512MB physical limit.**
**FIX (both harness copies, identical): FIX-A' best-fit-with-splitting** — requests >=256KB
take the smallest quarantine-expired pooled block >=asz (>=1MB entries only, preserving the
documented small-block poison rules), carve the front, return the remainder (>=64KB, else
absorb) with the ORIGINAL freedMs; exact accounting so reuse still can't alias a neighbour;
RT_FREEPOOL_SPLIT=0 reverts. **+ FIX-C: one-shot loud 512MB-crossing warning** (the boundary
is physical truth, not a heuristic).
**GATES — ★ HI TRAINING SOAK 240s: BACKGROUNDS CLEAN ON PIXELS** (nvk_f3001/f3301 = real
scenery, enemies, waterfall, GAME OVER + MP shield; vs the same drive's noise pre-fix), 20
SPLIT-REUSE fires, texreval3 fires 0, ZERO VUID/VK_ERROR/FATAL, high-water 832->688MB.
**ARCADE REGRESSION 240s: CLEAN** (f3001 correct, no select-screen/card-art regression — the
allocator's historic poison class), high-water 384->336MB, 0 errors, DATA sections back to 4
(L3's XEXCODESEC fix visible). ⚠ HONEST RESIDUE: the heap still CROSSES 512MB on HI (688MB) —
the visible defect is cured because the field pool now recycles into low memory, but the
hazard is LATENT until high-water stays under 0x20000000 (that is FIX-A, the bounded arena
with coalescing, ~1 leg). The new warning line makes any recurrence self-announcing.

## 2026-07-31 morning — FIX-A: THE 512MB BAR HOLDS (coalescing detour honestly banked)

User's first fixed-build session (log 075844): SPLIT-REUSE live but heap STILL hit 736MB —
explosion-effect pages aliased (late allocations = the class the user saw). FIX-A round:
(1) COALESCING attempt: ★ POISON CLASS FIRED — 3 consecutive boots lost menu DOWN navigation
(mode select stuck on ARCADE with 8 spammed DOWNs; merged small kernel-freed spans reused+
zeroed under live shell references). Default OFF behind RT_FREEPOOL_COALESCE=1; re-arm only
with its own gated leg. (2) ★ 512MB LINE DEFENSE (kept): when the bump would cross 0x20000000,
best-fit ANY pooled block >= asz with progressively relaxed age floors 2000/750/250ms (all >>
the deferred walker's ~50ms window; historic poison was IMMEDIATE reuse), loud
[pool] EMERGENCY-REUSE lines. GATES: two 300s HI runs (menus+attract churn — the training-tail
NAV kept missing on this build's shifted boot pacing; wall-clock NAV fragility again, 3 boots
burned) — **high-water 0x1F001000 = 496MB, UNDER THE LINE, 0 warnings, 40 emergency reuses
holding the boundary, 0 VK errors**; ARCADE 60s sanity clean (336MB, mode-0 loads, 0 errors).
⚠ HONEST: the full-load in-GAME bar on HI = the user's next session (telemetry armed: any
crossing prints the warning; emergency lines show the defense working). PNG-bank hygiene:
frame banks filled the disk (45k PNGs); banks deleted, 8 evidence frames kept in
/c/tmp/evidence_hi. Stuck-at-NOW-LOADING report (user, pre-FIX-A build) = the known pre-ROM
stall lottery class, restart cures; not correlated with today's changes.

## 2026-07-31 morning-2 — USER SESSION VERDICT: line crossed to 544MB; BREACH TELEMETRY armed

User's real full-load session on the FIX-A build (log 083852, stage-4 abnormal run): the
defense FOUGHT (>=40 EMERGENCY-REUSE, print-capped) but the bump STILL crossed —
**high-water 0x2205E080 = 544MB (32MB past the line, vs 224MB pre-fix)**. Symptom shrank to
match: user report = subtle doubled/ghosted gold edges on the ranking-screen plaques (vs
full-screen explosion garbage before). texreval3 fired 40x, 0 VK errors (instrument-silent
class again). DIAGNOSIS: pool held ~850 blocks at breach but takes were 0.0-0.5MB shards —
fragmentation; multi-MB stage-load requests found no block >= asz at ANY relaxed age floor.
FIX CHOICE PENDING DATA: added [pool] LINE-BREACH telemetry (asz, maxpooled, pooled count,
align; 60-print cap) in BOTH harness copies at the defense-exhausted point — next user
session names the exact failure: maxpooled < asz => fragmentation (coalescing re-arm leg,
this time investigating WHY merge poisoned menu input); maxpooled >= asz => age/align filter
bug (cheaper fix). Print-only change; both exes rebuilt LINK_OK, Desktop + dist copies
updated (zip respin deferred until the next real fix). Referee note for the plaque shadows:
ranking screen viewed fresh-from-boot (heap low) = free A/B — clean shadows there confirms
aliasing corruption, identical shadows = authentic art (retract).

## 2026-07-31 morning-3 — ★ ALIGN-CARVE FIX: the breach was an ALIGNMENT bug, not fragmentation

BREACH TELEMETRY verdict (user log 085954, stage-2 training heavy corruption, heap 592MB):
**asz=0.50MB maxpooled=15.00MB x60** — a 15MB block sat in the pool while 0.5MB requests
"found no fit". NOT fragmentation: asz granularity is 16B (harness rt_alloc `(size+15)&~15`),
so every split remainder started at p+asz was UNALIGNED for the align=0x1000 requests that
dominate; once a block was split, it and ALL its progeny became permanently invisible to the
alignment filter. FIX: rt_carveFit/rt_takeCarved — carve AT the aligned offset INSIDE any
candidate (front pad re-pooled >=64KB else leaked untracked; tail remainder start rounded UP
to 4KB so progeny stay usable; taken entry absorbs its own pads = exact accounting). Both
take-loops (split + line defense) converted; alignment REJECT filter removed. Both harness
copies REGION-IDENTICAL; both exes LINK_OK. GATES: (1) HI probe: heap high-water **221MB**
at a phase that ran ~490MB before, split-reuse visibly taking non-exact sizes, 0 LINE-BREACH,
0 warnings, 0 VK errors. (2) Poison-class A/B: probe's modeIdx=0 fired on the CARVE build AND
on the shipped user-verified-good control exe under identical NAV (8 DOWNs injected in both)
=> wall-clock NAV timing artifact, NOT input poison; carve exonerated by A/B, not eyeball.
Deployed to user Desktop + dist. ⏭ Definitive bar: user replays stage-2 training on HI —
expect snow/enemy textures clean and no 512MB warning; LINE-BREACH telemetry still armed if
anything residual crosses. Decomp-truth note (user asked): guest side is EXACT — &0x1FFFFFFF
mask (sub_8807B4B0/PM4, byte-identical all modules) is correct HW-free masking; the defect
class is 100% host rt_alloc; register-true end state = bounded 512MB arena with real free.

## 2026-07-31 morning-4 — EMERGENCY-MERGE + 120ms floor (stage-4 residual classes)

User stage-4 session on the carve build (log 093405): "some glitches otherwise much better" —
crossing only 4MB deep (516MB vs 592/544 prior). Telemetry split the residue into TWO classes:
(1) asz=4.00MB maxpooled=0.51MB = GENUINE fragmentation (multi-MB stage-4 loads vs 0.5MB
shards); (2) asz=0.50MB maxpooled=0.51MB = AGE miss (block big enough, younger than 250ms).
FIXES: 4th relax floor 120ms (>2x the ~50ms walker window; crossing GUARANTEES aliasing) for
(2); ★ EMERGENCY-MERGE for (1): at the line ONLY, merge ADJACENT pool entries that are EACH
individually reusable (>=256KB, >=120ms) into a run big enough to carve. SAFETY ARGUMENT vs
the banked coalescing poison: that class merged small NEVER-individually-reusable kernel
spans at insert time; merging blocks that each already qualify for reuse adds no exposure the
members didn't have alone. RT_FREEPOOL_LINEMERGE=0 reverts. Both copies REGION-IDENTICAL,
both LINK_OK. GATE: regression probe clean (221MB, merge dormant off-line as designed, 0 VK
err, 0 crash); live-fire = user's next stage-4 run (EMERGENCY-MERGE lines self-report; LINE-
BREACH still armed for anything that defeats even the merge). Deployed Desktop + dist.

## 2026-07-31 morning-5 — BIG-RESERVE: the 4MB starvation was split-path CANNIBALIZATION

Session 100006 ("quick play looks good", crossing 4MB deep, ONE breach): logs prove 4MB
blocks ARE freed and pooled early — but SPLIT-REUSE ate them for small requests
("take=1.2MB of 4.0MB"), so the late-stage 4MB align=0x10000 request (lr=0x8208BA10,
snd/doc-adjacent) starved and bumped to exactly 0x20000000. FIX: BIG-RESERVE — frees >=4MB
park in a side pool (cap 6) that only >=2MB requests may draw (normal quarantine); the line
defense may raid it at relaxed age as last resort; remainders >=4MB from carves re-park.
RT_FREEPOOL_BIGRES=0 reverts. Both copies REGION-IDENTICAL, LINK_OK. GATE: probe clean —
4 BIGRES-REUSE live at boot, split unchanged for mid-size, high-water 221MB (no parking
regression), 0 VK err. Deployed Desktop + dist. ⚠ OPEN: [jank] square plaque shadow on the
ranking screen persists on a quick look — needs the authenticity referee (Xenia tie-breaker)
before treating as defect; NOT correlated with heap state so far.

## 2026-07-31 — ★★ 512MB SAGA CLOSED (user play-test + log 101433) → ALPHA2 CAMPAIGN OPENS

User verdict "play tested, seems good". Log 101433: **0 LINE-BREACH, 0 crossing warnings,
high-water 496MB UNDER THE LINE, 4 BIGRES-REUSE, 0 VK errors** on a real play session. The
corruption arc that began with "gah, glitchy" closes: root = host bump allocator crossing the
512MB physical line the guest's &0x1FFFFFFF mask assumes; cure = layered reuse (exact → big-
reserve → align-carve split → line defense: relaxed-age best-fit → adjacent-merge → reserve
raid), each layer telemetry-named by a user session. Ranking-plaque square shadow persists
(uncorrelated with heap) — moved to the authenticity-referee track.

USER DIRECTIVE: **1.5 ARCADE + XBOX 360 at 1:1 ⇒ cut ALPHA2.** Fan-out (3 agents):
(A) SHELL COMPOSE 1:1 next leg per SPEC_shell_compose_1to1.md (BACKLOG #0; owns build+boot
lock; missing-draw census + register-true compose; PID-scoped kills only — user may be
playing). (B) FNF-1 [zscan] streaming-race fix DESIGN (analysis-only, no builds/boots;
deliverable _tmpscripts/fnf1_fix_design.md). (C) ranking-shadow authenticity referee (web
footage hunt; deliverable _tmpscripts/ranking_shadow_referee.md; Xenia = fallback referee).
Alpha2 candidate list beyond those: menu keyboard double-fire (#4, attended), Score Attack
graceful-decline verify (#10, small), D3 wall-dim factor (#6) + honor-settings (#7, oracle
apparatus exists), msgs 12/13/14 MATCHED debt (attended), GA_DSHIFT vk_render cleanup.

## 2026-07-31 — SHELL COMPOSE 1:1 leg (agent A of the alpha2 fan-out): nvk MISSING-DRAW CENSUS

Cross-ref, full ledger in NOTE_fnf_shell_defects.md (same date). BACKLOG #0's census requirement
was unmet because the 07-28 census lives in `renderFrameReal` and `rt.cpp:2476` bypasses it under
`RT_NVK=2` — three days of ship builds had no missing-draw instrument at all. Re-hosted at the
nvk altitude (`RVK_DRAWCENSUS=1|2`, `_K`/`_R`, `RVK_CENSUSTEST=1` count-skip / `=2` real
render-skip; identity = texture base + vs + ps on DISPLAY-target shell frames), plus an aliasing
discriminator (roster of the missing/return frames), per-frame recorder counters in
`decomp/shell/nvk.cpp` (`g_nvk_fBuild/fNoScratch/fSpliced` — cmd-blob diversion vs guest-aborted
draw), and two previously SILENT partial-frame classes made loud (`[nvktrunc]` vertex-budget
truncation, which drops the whole tail of a frame, and the 6144 recorder cap). All default-off;
harness `_tmpscripts/nvkcensus_soak.sh`. Positive controls pass exactly (16 injections -> 16
DROPOUT-CONFIRMED len=1) after fixing the 4th control failure of this family: an injection that
starved its own clock and hid the element for 322 frames instead of 1. GATES over 24 clean-arm boots
(>60k censused shell frames, incl. the HI arm): **0 dropouts, 0 truncations, 0 VK errors, 60.0 fps
with the census armed, and SPEC §4 clear policy 100 % conformant (8881/8881 on the long soak)** —
the first live proof that compose on the campaign renderer is register-true and loses nothing.
TOP MENU frame matches the SDK ground-truth capture element-for-element. ONE organic finding, 1
boot in 23: "PRESS START BUTTON" (18 quads, base 0x4C41000 vs=1 ps=2) strobes 2-frames-off /
2-frames-on seven times over 0.47 s on the title screen. Since nvk replays exactly what the guest
emitted, that is a GUEST-EMISSION / tick-cadence class upstream of compose, not a compositor
defect — same 2-state alternation shape as the 07-28 glass truth. Named, not chased (4 %
intermittent). ⏭ For the user-judged acceptance soak, pin `RVK_DRAWCENSUS=1` in the playtest
launcher: it is free and silent, and it converts the user's own session into the measurement.

## 2026-07-30 late night — ★★★★★★ MODULES 2-7 CENSUS: "THERE ARE NO INDEPENDENT BUILDS"

(_tmpscripts/modules_shift_census.{md,json} + modules_shift_match.py; 11 positive controls.)
★ THE ARCADE→HI EDIT IS THE SAME 2-INSN INSERTION IN ALL THREE TITLES (li r11,9 / stw
r11,0x35C(r31), same offset, same 7 branch fixups): reco @sub_880DEF88 (+8 code / +0x60 data),
hirow @sub_880DE3E0 (+8 / +0x60), kiniro @sub_880E1B68 (+8 / +0x100 & +0xF0). Residual words
after the law: 3 per pair (enumerated — 2 .rdata float loads -0x30 + the GameEntry ptr +8 ⇒
residual ZERO). Fn-start coincidence 100.0% vs banked 28.1/1.8/9.4%. Cross-title: 84.7-97.4%
fn coincidence, 85.7-95.0% tail-only identity — the banked §3 figures were wrong by TWO ORDERS
OF MAGNITUDE (same delta-0 flaw). nvk draw path transfers to ALL SEVEN other modules (5/5
hooks full-window identical at +0/+16/+0x10000). palm_abnormal is closer to reco_normal
(84.7%) than to palm_normal (77.3%) — port modeIdx 3 FROM RECO. Millicode anchors §3 table
correct as written, all 8 verified.
★★ RETRACTION (supersedes the abn_hook_census "59 NO-MATCH" and the revival notes' standing
risk): the T1 mask didn't cover load/store displacement LOW-HALVES (compiler puts the low half
of a relocated global in lwz displacement, not just addi) — 59/59 "diverging" functions are
FULL-BODY IDENTICAL at +8. **reco_abnormal's .text differs from reco_normal in EXACTLY ONE
FUNCTION.** The "pacing band needs its own verdicts" risk is RETIRED (msg-5 pump / sound
producers / [fade] FSM / gate-clear all body-identical); FNF-5-class re-verification on the HI
arm downgrades from required to routine.
BOARD: modeIdx 1 MECHANICAL (done); 7 and 5 FREE given 6 and 4 (prediction from the identical
law, not yet measured); 6/4/2/3 SEMI (one leg each, 74-91% hooks + 52-55/57 tables mechanical
via lookup-table law). Caveat: sibling laws robust; cross-title segment boundaries must be
re-derived when porting (151→140 tie-break sensitivity in hirow).

## 2026-07-31 — ALPHA2 leg results: COMPOSE CENSUS LANDED (agent, d280de9) + FNF-1 CLOSED

(A) Compose 1:1 agent leg: missing-draw census RE-HOSTED on the nvk renderer — the 07-28
census (and [r5pix]/RESKEEP/gdprobe) had been STRUCTURALLY DEAD since the RT_NVK=2 pivot
(rt.cpp:2476 early return). Under nvk the SPEC compose checklist is satisfied BY CONSTRUCTION
(guest's own clear/SetRT/resolve/draw stream replayed; nothing heuristic left to retire).
Census positive-controlled the hard way (4th control failure of the family found+fixed:
injected dropout latched 322 frames when the injected identity was the phase's only display
draw). Gates: 24 boots, >60k censused frames, 0 dropouts/truncations/VK errors, clear policy
8881/8881 conformant (first live register-true proof), TOP MENU matches oracle ground truth.
★ ORGANIC CATCH: PRESS START draws vanish 2-frames-on/2-off x7 over 0.47s (1 boot/24) with
recorder counters clean ⇒ GUEST STOPPED EMITTING — the user's "PRESS START beyond authentic
blink" is upstream of compose (tick-vs-present cadence class, glass-truth shape). Next probe
= shell tick vs present cadence at title. USER PLAYTEST LAUNCHERS now pin RVK_DRAWCENSUS=1
(silent, 0 fps cost) — user sessions ARE the measurement; census exes deployed Desktop+dist.
(B) FNF-1 CLOSED (design agent + R0 boot): never a streaming race — additive accumulation
from uncleared frames, cured 07-28 by the clear-byte 1:1 change. R0 on ship renderer:
readbacks rvk_frame40/60.png inside the f40-105 window = clean rings. BACKLOG #2 rewritten;
instrument debt re-filed as #2b (reval3 warm-up). [zscan] label retired.
(C) Ranking-shadow referee: web agent still out; local Xenia attract run STALLED at title
17 min (this Xenia build does not auto-cycle attract; synthetic input doesn't register) —
needs 30s of user pad time, Xenia left running at title.

## 2026-07-31 — RANKING SQUARE SHADOW: REFEREED = PORT DEFECT (user + ladder, v1.3.6 reference)

Web hunt INCONCLUSIVE (agent report _tmpscripts/ranking_shadow_referee.md — no 360 ranking
footage exists online; honest). Xenia referee unblocked for the future (★ keyboard_mode was 0 =
ALL keyboard input disabled in the game config — the whole 07-28 "synthetic input never
registers" finding was tested against a disabled keyboard; now =1) but its attract never
cycles from title (17+min) so it stayed unused. DECISIVE: D:\ v1.3.6 reference attract ladder
(my capture) + user's manual reference screenshots BOTH show the ranking plaques with NO
square shadow (evidence: /c/tmp/evidence_shadow/ref_v136_ranking_2nd3rd_noshadow.png, same
default score table as the port's screens). Port draws a hard rectangular edge ⇒ DEFECT.
PRIME SUSPECT: the s2B leg 11 drop-shadow ring revival (FUN_82182008: 4 edge strips 16px
extrude 0xFF080808→alpha0 + corner fans = RECTANGULAR by construction, DropShadow-gated) now
drawing around ranking plaques with a HARD edge instead of the soft extruded fade — either
gradient/blend wrong on the ring, or the ring targets these elements when it shouldn't.
NEXT LEG (boot-lock queued behind the cadence agent): port attract→ranking (no NAV needed),
A/B RVK_NOSHADOWFIX=1 vs default + [nvkring] vertex/blend readout on ranking frames vs the
reference frame. NOTE for referee doctrine: v1.3.6 asset-difference caveat (FNF-12) judged
LOW RISK here (same screen, same default table) but record Xenia confirmation if ever cheap.

## 2026-07-31 — ALPHA2 leg: TITLE CADENCE — PRESS START STROBE **CLOSED AS AUTHENTIC** (no fix)

Follow-up to d280de9's organic catch. Detail: NOTE_fnf_shell_defects.md newest entry.

**The 2-on/2-off x7 burst is the guest's own accept animation, not a port defect.** Guest law
read from the binary: `FUN_821CBFF0` (title item tick) does a hide-byte square wave
`hide = (ctr/D)&1` with `ctr=++task[+0x7C]`, and on accept sets `ctr=0, D=2` and hands off to
`sub_821CBF58`, which runs the same wave and **returns early while `ctr < 30`** — an authored
30-tick 2/2 strobe = exactly 7 off-gaps = 0.5 s. The census measured 7 gaps / 0.47 s.

**New instrument `RVK_TITLEPROBE` (default off, both halves, non-perturbing — controlled):**
guest-side hook on `sub_821CBFF0` (+ shared tick fn with the existing `sub_821CBF58` hook) in
merged_shell.cpp logging hide transitions with run length in ticks AND presents, ctr/D, dPres
and the ACCEPT event; glass-side threshold-free run-length tracker beside the nvk census in
vk_render.cpp (no K, no R, no erase — the census's own filters are what hid the authentic
blink); `g_rt_presentN` published from rt.cpp so guest hooks can stamp the present index.
Harness `_tmpscripts/titleprobe_soak.sh`.

**Results.** (a) **Pre-accept divisor read live: D = 20** — closes SPEC_shell_compose_1to1 §13's
open "[GAP] Initial-D ctor needs a runtime read", and it is the oracle value (20-on/20-off, SDK +
Xbox 360). (b) **The port's blink measures 20/20 on glass for 15+ consecutive cycles** — positive
control passed and a 1:1 verdict in one shot. (c) **Tick:present is exactly 1:1 with zero drift**
(`pres - tick = 654` constant over 581 ticks; `dPres=1` everywhere; every guest run
`ticks=N presents=N` on both exes) ⇒ **welded-clock / tick-starvation / FSM double-step are dead
by measurement.** (d) **The "1 boot in 24" was a census reporting threshold**, not an intermittent:
the DROPOUT needs streak >= K=8 at loss, which post-accept 2-frame ON runs can only inherit from
the pre-accept ON phase. The previous leg's own always-on `[cbf58]` probe proves the strobe fired
in **23/23 START boots and 0/1 no-START boots**. This leg: 4/4 boots, both instruments.

**NO FIX LANDED, deliberately** — nothing is unexplained, and the two-strikes rule forbids
swinging at a defect that does not exist. Gates green both arms (build_win.sh 87 obj,
build_win_abn.sh 88 obj; 0 VK errors / 0 truncations / clear policy 2281/2281 / 60 fps;
default-off control emits 0 probe lines and a frame-identical census).

⏭ Residual: census DROPOUT lines cannot self-classify authored square waves — header comment now
directs readers to pair with RVK_TITLEPROBE=1. Open oddity for later: census bank `bounce1` shows
63 `[cbf58]` calls for 12 accepts (advance after ~5 ticks, not 30) ⇒ `task[+0x7C]` may not be
re-zeroed on a title re-entry path.

## 2026-07-31 — SHADOW A/B: A-arm evidence banked; NOSHADOWFIX revert lever HANGS; fix agent out

Attract arming recipe RE-LEARNED from user (was forgotten): ranking screen needs
START,A,LEFT,A from title (legal screen starts the attract loop); NAV
"18000:START,24000:A,26500:LEFT,29000:A", ranking ~130s in. Boot A (default env): square
shadow CAPTURED (evidence /c/tmp/evidence_shadow/port_default_ranking_square.png + crops vs
reference). ★ Ring census on the defect boot: vs=15 ps=14 blend=07060706
v0={0,-16,00000000} vN={640,0,FF080808} — VERTEX GRADIENT CORRECT; defect is downstream
(interp/shader-selection/blend). Boot B (RVK_NOSHADOWFIX=1): ★ HANG at ~f4200 (counters
stop, window gone, process alive, 0 VK err, no die-loud) — the s2B leg 11 revert lever is
NOT clean on the census build; landmine banked, cause TBD. Fix agent launched (H1 shader
nearest-match / H2 vertex-color decode / H3 blend translation vs SDK answer key / H4 c2)
with reference crop as pixel target + no-regression gate on the panel border ring.

## 2026-07-31 — ★★ BETA1 CUT RATIFIED (user): two-mode 1.5, stubs for the rest, audio push today

USER RULINGS: (1) beta1 = 1.5 ARCADE + XBOX 360 modes only; other modes get GRACEFUL STUBS
(clean bounce at mode select, never hang) — hirow/kiniro/palm stay post-beta content lanes.
(2) Beta stays FRIENDS & FAMILY — assets-in packaging fine per existing ruling; no public
release any time soon (extraction step stays banked for that day). (3) AUDIO UNPARKED FOR
TODAY: push as far as possible before the cut; accepted tier = host bridge (register-true
placement post-beta). Beta1 checklist: [stubs] [shadow fix] [kb double-fire, attended]
[Score Attack decline verify, attended] [audio best-effort today].
FAN-OUT (3 opus agents, collision-partitioned): shadow-fix agent OWNS build+boot lock;
audio agent PHASED (phase 1 = analysis/code/standalone-tool only, phase 2 live gates on my
GO after lock frees; targets: T1 BGM fork — BGM bank is PCM so it's delivery plumbing, SDK
referee question = XACT worker thread consolidation suspect; T2 SYS_SE routing — menu click
SE; T3 placement design only); mode-stub agent ANALYSIS-ONLY (design doc, refusal-path
trace, register-true bounce preference; carve_hi log has a live REFUSED event to read).

## 2026-07-31 — ★★★★★ BETA1 AUDIO leg, PHASE 1 (analysis + code, NOT YET BUILT — pre-gate commit)

Audio agent of the beta1 fan-out. Phase-1 charter: analysis + code only; no tree build, no boot
(the shadow-fix agent owns the build+boot lock). Everything below is compiled-clean per TU
(`clang++ -fsyntax-only`) and offline-verified with the standalone `rt_xwma_tool.exe`; the live
gates are `_tmpscripts/beta_audio_gate.sh` (phase 2).

**★ T1 PREMISE CORRECTED — "BGM never plays" is NOT the layer-26 register-true fork for beta.**
The banked 07-29 field capture proves the HOST BRIDGE already plays real BGM: `/c/tmp/showmenu6.log`
lines 33376-44060 show `[crux] cueId=0 bankType=0 waveIdx=0 GATE PASS` -> `[bridge] PLAY bankType=0
waveIdx=0` -> and `/c/tmp/aud/xwma_field.wav` ends with **28 s continuous music at int16 RMS
5817-8076** (ref_BGM_e0.wav = 7560). BGM at the accepted beta tier WORKS. What is broken is three
other things, all found this leg:

1. **THE SHIP CONFIG HAS NO SINK.** `dist/futari_alpha1a/*.bat` set `RT_AUDIOPUMP=1` — which only
   makes the GUEST mixer run — and never set `RT_AUDIO` / `RT_AUDIOBRIDGE`. `rt_audio_submit()`
   early-returns when neither a dump path nor the live backend is armed, so **every shipped build
   so far is silent by construction, on every machine.** This, not the XACT fork, is why the user
   hears nothing. Both launchers now carry an audio block (RT_AUDIO / RT_AUDIOBRIDGE /
   RT_AUDIOXWMA / RT_CUEBRIDGE / RT_AUDIOGAIN=0.8), commented so a silent build is one deletion away.
2. **CUE INDEX != WAVE INDEX (new defect, data-proven).** Everything upstream of the bridge deals in
   XACT SoundBank CUE indices — the game's cue table `0x885C5D14` stores one, and the shell's
   `sub_820EEE00` takes one — and the bridge has been using them as `.xwb` WAVE indices. Parsed out
   of the shipped banks: **BGM 11 of 13 cues mis-map** (cue2 m03_boss -> wave 11, cue3..cue11 all
   off by one) and **SYS_SE is fully reversed** (cue0->wave6 ... cue6->wave0). SE/VOICE happen to be
   identity, which is why the 07-29 leg looked clean. Boss/clear/name-entry music has been playing
   the wrong track whenever the bridge was on.
3. **SYS_SE / SYS_BGM had no path to a speaker at all** (T2) — they are shell-side banks with no
   bankType in the game cue table, so nothing routed them through the game crux.

**★★ THE .xsb IS THE ANSWER TO 2 AND 3.** `sub_820EEE00`'s own bounds check reads `hdr+0x13`
(numSimpleCues) / `hdr+0x15` (numComplexCues) of whatever its bank vtable[+0x48] returns, and the
sibling accessors `FUN_820f0d18`/`FUN_820f0d78` add `hdr+0x22` / `hdr+0x26` — four independent
fields that match the XACT3 `.xsb` header exactly ⇒ **that object is the verbatim SoundBank image**.
New `.xsb` parser in `shell/gen/rt_xwma.cpp` (offline-verified: 225/225 cues across all five banks
parse, every wave index in range) yields cue -> (waveBank, waveIndex) + the cue NAME:

    SYS_SE  cue0 BGM_Sample->w6  cue1 SE_OK01->w5  cue2 SE_Cancel02->w4  cue3 SE_Cancel01->w3
            cue4 SE_Select02->w2 cue5 SE_Select01->w1  cue6 SE_OK02->w0
    BGM     cue0 m01_slct->w0  cue1 m02_stg1->w1  cue2 m03_boss->w11  cue3 m04_cler->w2 ...
    SYS_BGM cue0 mushifuta_Menu02->w0     SE/VOICE: identity (70/134 cues)

⇒ **THE START-PRESS CONFIRM SE IS NAMED AT LAST: `SYS_SE` cue1 `SE_OK01` = wave 5** (the open item
(a) in NOTE_audio_xwma_decoder.md). Cursor move = `SE_Select01` cue5/wave1. Corroboration: cue0
`BGM_Sample` points at wave 6, which is the longest+loudest entry in the bank (4.01 s, rms 6961,
100% nonzero) — exactly what a music sample should be, and nothing else in the bank looks like one.

**IMPLEMENTED (all behind levers, nothing built into the tree yet):**
- `shell/gen/rt_xwma.cpp` — `.xsb` parser (`rt_xsb_identify` / `rt_xsb_cue` / `rt_xsb_wavebank`),
  `rt_xwb_pcm_info` (entry geometry + LOOP REGION), and an `xsb` mode on the standalone tool.
- `shell/gen/rt_audio.cpp` — bridge re-keyed from bankType ints to bank NAMES (so SYS_* work);
  new `rt_audio_bridge_play_cue(soundbank,cueIndex)`; PCM streamer honours the `.xwb` loop point
  (BGM entry0 = {66053,+1396363} samples = intro once then loop the body — it used to replay the
  intro every pass); output gain + soft limiter (`RT_AUDIOGAIN`, `RT_AUDIOLIMIT`); `RT_CUETEST`
  in-process cue harness; **`rt_audio_can_accept()` can no longer wedge the guest audio clock** when
  the sink is absent/stalled (it would have returned 0 forever on a machine with no render endpoint,
  stopping RT_AUDIOPUMP and every clock derived from mix progress — a real hazard now that the
  launcher asks for live audio everywhere).
- `out_reco/merged/merged_shell.cpp` — the dispatch: hook on `sub_820EEE00`, identify the bank by
  its resident `.xsb` ('KBDS' magic + exact byte-prefix match, cue-count fallback), dispatch on
  `ret>=0`. Strict superset of the crux dispatch.
- `out_reco/merged/merged_game.cpp` — crux dispatch suppressed while the cue bridge owns it (else
  every game cue plays twice). `RT_CUEBRIDGE=0` reverts to the pre-07-31 arrangement exactly.
- `dist/futari_alpha1a/*.bat` — the audio block.
- `_tmpscripts/beta_audio_gate.sh` — phase-2 gates (noenv / cue / revert / field / live).

**PHASE 2 (on GO): `bash build_win.sh` then gate `noenv` -> `cue` -> `revert` -> `field` -> `live`.**
Open questions only a boot can answer: (i) does `sub_820EEE00` actually fire for the shell's own
menu cues, or do shell SFX enter through a sibling (fallback: move the dispatch to `sub_820EEC10`,
one line); (ii) is the resident `.xsb` byte-identical to disk (the identify fallback covers it, and
says so in the log); (iii) does anything double now that SYS_BGM menu music can stream.

## 2026-07-31 — ★★★ MODE STUBS: refusal path closed, three guest-native layers landed (PRE-GATE)

Design doc: `_tmpscripts/mode_stub_design.md` (full trace + citations). Code:
`out_reco/merged/merged_shell.cpp` + `host/futari_module_desc.h`. **NOT BUILT, NOT BOOTED** —
committed pre-gate while the render-fix agent holds the build+boot lock; T1–T6 gates below are
PENDING and this is not a verdict.

### The refusal path, answered

**There is NO guest "load failed → back out" flow, and the NTSTATUS is irrelevant.** The eight
per-mode loader ctors (`FUN_821C8A80` + 7 siblings, one per modeIdx, dispatched by `FUN_821C3B90`
on `driver+0x68`) call `FUN_82088E10` = XexLoadImage, which collapses **every** negative status to
`0`; the only consumer of that `0` is `FUN_8210E878`, which is literally `void
FUN_8210e878(void){ return; }` — a retail-stripped assert. So the guest builds a modectx with
`+0xF8` (hmodule) = 0 and `+0xFC` (GameEntry) = 0 and carries on.

**What the player gets today = a PERMANENT SOFT WEDGE, measured twice.** `FUN_821C39A8` (the
driver's running state) advances only if `modectx+0x78 ∈ 1..5` (it is 0) and self-kills only if
`modectx+0x68 != 0` (it is 0) — so it spins forever, the driver task never dies, and the root FSM
join `FUN_821CE400` (early-returns while `[root+0x5C]+0x10 != 0`, i.e. children alive) never
dispatches phase 5. Evidence, two exes / two foreign modeIdx / identical signature:
`/c/tmp/modeprobe/carve_hi/boot.log:1356+` (v154hi, modeIdx 0) and
`/c/tmp/modeprobe/mp_refuse/boot.log:1282+` (normal, modeIdx 1) — both end on
`[bootsm] CE400 … cur76=6 want80=5` with `[modegate] … mode78=0 gate=CLOSED` and
`[lstate] sub_821C39A8#…` still counting, frames still submitting. Positive control in the same
bank: `mp_ctrl` reaches `resident hmodule=0x88000000` + `[gemsg] GameEntry(msg=6)`.

**But the guest has three DECLINE flows, and they are exactly what beta1 needs** — we reach the
game's own machinery and invent nothing.

### What landed (lever `RT_MODESTUB=0` reverts all three; DEFAULT ON)

| layer | hook | mechanism |
|---|---|---|
| **L1** grey + veto foreign TITLE rows | new wrapper `sub_821B80D0` (game-select ctor) | post-impl, call the guest's own `FUN_821BA280(menu, titleIdx, 1)` → item record `+0x20` bit 0. `FUN_821BA4D8` (ACTIVE) then **swallows A** on that row (`(*(uint*)(rec+0x20) & 1) != 0` short-circuits the confirm); cursor still moves, B still exits, the fold is never reached. Identical to the call the ctor already makes — `FUN_821ba280(this,2,1)` — to grey the un-entitled Black Label row. |
| **L2** veto the ARCADE/360 sub-choice | existing wrapper `sub_821B7CC0` (the modeIdx fold) | if `titleIdx*2+sub != hosted_mode_idx`, reproduce the impl's OWN out-of-range branch `LAB_821B7DA8` verbatim — `*(this+0x48) = 0x82061D50` (= vt 0x82050518 +0x30 = `FUN_821BA4D8` = ACTIVE) and nothing else — then skip the impl. Phase (`+0xA4`) and modeIdx (`+0xBC`) untouched ⇒ root never leaves phase 5. |
| **L3** safety net | existing wrapper `sub_821C39A8` | if `modectx+0xF8 == 0` (hmodule; the slot ALL EIGHT ctors write as `puVar3[0x3e]`), set `modectx+0x68 = 1` — the guest's own abort flag. Its tail appends delegate `0x820619F0` (`*(task+8)=2`, the engine's universal kill) ⇒ driver dies ⇒ join unblocks ⇒ `FUN_821CE098` re-dispatches with `root+0x50` already pre-set to 5 by phase 6 ⇒ **fresh TOP MENU**. Same sequence `NOTE_fnf11_handback_decomp.md` PART 2 measured for the in-ROM quit. |

`host/futari_module_desc.h` grew **`hosted_mode_idx`** (reco_normal 0, reco_abnormal 1) — the L4
`mode_idx_mask` slot promised in its own header comment, landed early as a plain index — plus
`FUTARI_MODE_HOSTED` / `FUTARI_TITLE_HOSTED` and three static_asserts (arms differ, both are
title 0, index < 8). Every veto/grey/safety fire prints a `[modestub]` line (positive-control
requirement — a gate log must prove the layer RAN, not infer it from an absence).

**L1 answers the menu-presentation ask for free**: greying is the game's own per-item flag with
its own `TIPS_GAMESELECT_BLACKLABEL_DISABLE`-class treatment — no new art, no new string. Its
limit is granularity: one title row = two modeIdx, and the `arcade_front` panel (`FUN_821D2628`)
is a different class, so the ARCADE/360 sub-choice declines *silently* via L2. Decoding
`FUN_821D2628`'s item model to grey the sub-row too is POST-BETA.

### Landmines / corrections banked

- **⚠MIS `ATLAS_scene_system.md` §8.6** reads `FUN_821C39A8`'s tail as `driverObj+0x68` (= modeIdx)
  and leaves "driverObj+0x68 double-duty unresolved" as an open sub-question. The asm
  double-loads (`shell/gen/ppc_recomp.34.cpp`: `lwz r11,184(r31); lwz r10,104(r11)`), so the
  tested field is **`modectx+0x68`** on the loader object — unrelated to modeIdx. **Gap closed.**
- **⚠ TRAP, deliberately not used:** `FUN_821B7CC0`'s Black-Label entitlement arm sets
  `*(this+0xB8) = LAB_820662C8` and returns WITHOUT advancing `+0x48`. The banked `[gsel]` note
  (2026-07-12, merged_shell.cpp) proves caller `FUN_821BA090` re-invokes vt+0x20 every tick ⇒
  infinite per-tick retry = the `cur76=5 want80=-1` "Now Loading" hang. Mirroring it would swap
  one hang for another.
- **Do NOT "fix" this in `merged_bridge.cpp`.** Changing the refusal's NTSTATUS is cosmetic
  (see above), and suppressing the refusal reinstates the silent-substitution hazard
  (`NOTE_other_modes.md` §5/§7) that makes every "mode X works" report untrustworthy.
- Decline SE deferred: the guest plays none on the swallowed-A path, so L1 is authentic as-is;
  adding one would depend on the audio agent's still-open SYS_SE (T2) lane.

### GATES PENDING (run when the build+boot lock frees) — `_tmpscripts/modeprobe.sh`, `DUR=90`

| # | exe | NAV | expect |
|---|---|---|---|
| T1 | `futari_merged.exe` | `18000:START,24000:Ax2@2500` | **regression**: unchanged, loads reco_normal |
| T2 | `futari_merged_v154hi.exe` | `18000:START,24000:A,25400:DOWN,26800:A` | **regression**: unchanged, loads reco_abnormal |
| T3 | `futari_merged.exe` | `18000:START,24000:A,25400:DOWN,26800:A` | **L2 VETO** (was: wedge, `mp_refuse`) |
| T4 | `futari_merged_v154hi.exe` | `18000:START,24000:Ax2@2500` | **L2 VETO** (was: wedge, `carve_hi`/`merge_hi`/`bigres_hi`) |
| T5 | either | `18000:START,22500:DOWN,24000:A,26800:A` | **L1 GREY**, A swallowed on title row 1 |
| T6 | either | `18000:START,22500:DOWNx3@1200,24000:A,26800:A` | **L1 GREY**, title row 3 (also exercises the 4-row `del1.01` layout) |

PASS = a `[modestub]` line fires, **no `[modeidx]`, no `REFUSED`**, `grep -c "cur76=6 want80=5"`
**= 0**, `[itemsm]` never reaches `0x82065A78` (CLOSING), frames keep submitting, menu still up.
L3 is only reachable deliberately (`XR_RECO_NORMAL=/nonexistent`): expect the `[modestub] L3`
line, `[lstate] sub_821C39A8` to STOP counting, then `cur76=5 want80=5` and a fresh
`[mvt] NEW vt 0x82050518`.

**Two eyeball risks flagged, not pre-coded:** (a) whether the `arcade_front` panel is torn down on
the L2 route — if it lingers, the follow-up is one `FUN_821BC718(*(this+0x80),-1,0)`, the
panel-close the guest itself issues at the top of `FUN_821B7F30`; (b) on the L3 route only, the
post-unload compose gap from `NOTE_fnf11_handback` PART 2 ("solid slate-blue panel"). (b) *should*
not apply — `g_rt_romactive` is set by the GAME-side `sub_88168D48` and the ROM never attached —
but confirm rather than predict.

Pre-commit check performed instead of a build: `clang++ -fsyntax-only` on
`host/futari_module_desc.h` (standalone) and `out_reco/merged/merged_shell.cpp` with
`build_win.sh`'s exact flags, **both arms** (`-DFUTARI_MODULE=0` and `=1`) — clean, zero new
warnings, no artifacts written, no build script run, nothing booted.

## 2026-07-31 — ALPHA2 leg: RANKING SQUARE — ★★★★★ **THE DROP-SHADOW RING IS EXONERATED**

Detail: NOTE_fnf_shell_defects.md newest entry. Supersedes the 07-31 "PRIME SUSPECT: the s2B leg 11
drop-shadow ring revival" line above — that suspicion is now DEAD by measurement.

**All four handed hypotheses falsified.** New instrument `RVK_SHADOWDUMP=<everyN>` (default off,
`render/vk_render.cpp`) applies the shell VS's own c10..c13 matrix + batch viewport, so a log line
says WHERE ON GLASS a draw lands; stride-12 draws print every vertex with colour. Result: the ring
is **8 draws/frame, always around the shell WINDOW**, landing on the 16 px band immediately OUTSIDE
the panel (`scr={383.5,39.5..399.5,679.5}` and the three siblings), **exactly 8 per frame on all 150
dumped frames** — it never draws around a plaque. vs=15/ps=14 selected every time (leg 11's tiebreak
works); `spirv-dis` of idx15 shows Location 0 + Location 8 in, interpolator 16 out, **no `Flat`
decoration** (H1 dead); the per-vertex dump shows 00000000 outer / FF080808 inner all the way into
the vertex buffer with `B8G8R8A8_UNORM` @+12 (H2 dead); 0x07060706 = SRC_ALPHA/INV_SRC_ALPHA ADD
(H3 dead); `c2={1,1,1,1}` on every ring draw (H4 dead). ★ And the ring **renders correctly on
glass**: luma across the left strip fades monotonically 60.4 -> 9.7 over 16 px into the panel edge
(readback f3180). That is the leg-11 win working, and it is this leg's no-regression gate.

**The square is inside the ROM's OWN 640x512 render target**, not the shell: the shell's whole
DISPLAY list on a ranking frame is background + 8 ring strips + ONE panel quad (vs35/ps34, a
RESOLVE) + side text. `nvkres_f3180_045A000_640x512.png` already carries two straight full-height
steps at x=171 and x=443 (Δ=272 = the ranking ROW PITCH), each **+24 %** (median log-ratio
+0.218/+0.213, reproduced +0.221/+0.211 on a second boot) — a cumulative 3-level staircase, ~x0.80
per band, which on glass is the two horizontal steps at screen y=361/633. Negative positive-control
banked: `RVK_MODOFF=05000500` (drop every MODULATE-blend draw, the obvious sprite-shadow class)
leaves the staircase UNCHANGED, so that class is exonerated too.

**Two instrument findings worth more than the leg.** (1) `[nvkring]`'s throttle period was 4800 and
the ring is 8 draws — 4800 % 8 == 0, so EVERY sample since leg 11 was the same strip of the same
window and the corner fans had never appeared in any bank. Now 4793 (prime); the sample walks all 8
slots. (2) **PrintWindow positive-controlled at last**: 45 window captures vs 625 frame-numbered
readbacks in one boot, occluder list logged — mean abs diff **0.000 over full 1280x720 RGB** on
every static-screen pair. PrintWindow is faithful; the earlier "readbacks look clean" was
frame-selection luck (the square only shows while rows 1/2 are on screen).

**⚠ RETRACTION: `RVK_NOSHADOWFIX=1` does NOT hang.** Re-run on the current build, same harness:
clean to f8701 / 150 s / 0 VK errors, log growing throughout. The banked shadow_b log simply ends at
`[nvk] submit f4201` with no error and no die-loud — a harness DUR expiry, not a deadlock (every
fence wait here is bounded at 10 s and would have logged a timeout). Not a landmine.

**NO FIX LANDED, deliberately** — prime suspect dead, true author un-named and in another
subsystem. Gates: both exes rebuilt (87/88 obj, LINK_OK), 6 boots to f18601, **0 VK errors, 0
truncations, 0 census dropouts**, default-off control silent. Harness `_tmpscripts/shadowprobe.sh`
+ `shadowcap.ps1`; evidence `/c/tmp/evidence_shadow/` (8 frames).
⏭ NEXT: fix `[shdump]`'s transform for VTE-OFF draws (its offscreen rects are NOT trustworthy —
`vte=400` draws output screen pixels, the c10..c13 path is matrix-class only), then bisect the ROM
offscreen draw list until the +24 % step at x=443 vanishes.

## 2026-07-31 — ★★★★ MODE STUBS GREEN (T1–T5 + negative control) — and a PASS-CRITERIA RETRACTION

Follow-up to the PRE-GATE commit. Build was the coordinator's (LINK_OK both exes, 13:07); all
runs below are mine under the build+boot lock, `_tmpscripts/modestub_gate.sh`, `DUR=75`,
PID-scoped kills only.

### ⚠ RETRACTION FIRST: the coordinator's "T1 FAIL" was MY BAD CRITERION, not a code defect

The pre-gate design doc told the gate to require **`grep -c "cur76=6 want80=5" == 0`** and *"no
`[modeidx]`, no `[itemsm]`→`0x82065A78`"* on **every** test. Those hold only for the FOREIGN
tests. On the HOSTED regressions the opposite is required — `[modeidx]` MUST fire, the menu MUST
close, the module MUST load — and **`cur76=6 want80=5` is the healthy in-game state**: it only
means "root FSM parked in the join `FUN_821CE400` with a live child", which is true for the whole
time the ROM runs. Measured across the bank:

| log | state | `cur76=6 want80=5` | `[gemsg]` |
|---|---|---|---|
| `mp_ctrl` | HEALTHY | 3 | 24 |
| `gate_T1` | HEALTHY | present | 26 |
| `carve_hi` / `mp_refuse` / `merge_hi` | **WEDGED** | 11 / 2 / 9 | **0 / 0 / 0** |
| `gate_T3` | cleanly declined | 0 | **0** |

The pair appears on **both** sides ⇒ it separates nothing. The reported T1 log
(`/c/tmp/modeprobe/stub_T1/boot.log`) in fact shows `XexLoadImage → resident hmodule=0x88000000`
at line 1277, the full init burst, and `GameEntry(msg=5) call#3000` — **T1 was always passing.**

**THE DISCRIMINATOR IS `[gemsg]`** (the GameEntry stream — the shell's only channel to the ROM):
`>0` ⟺ module loaded + init burst + msg-5 per frame ⟺ game live; `==0` ⟺ nothing launched. It
separates all six banked logs perfectly. Design doc §5 is superseded by **§5-R**; the gate is now
executable (`modestub_gate.sh`, with `VERDICT_ONLY=1` to re-score banked logs).

**Root cause of the error, stated plainly:** I read the "wedge signature" off two *failure* logs
and never ran it against the healthy control sitting in the same directory. That is exactly the
banked rule **"instruments lie until positive-controlled"** — a signature derived from failures
alone is a coincidence, not a signature. Cost: one coordinator debug cycle chasing a non-bug in L1.

### GATE TABLE — all green, both exes

| # | exe | selects | verdict | evidence |
|---|---|---|---|---|
| T1 | `futari_merged.exe` | modeIdx 0 **HOSTED** | **PASS** | grey=3 veto=0 gemsg=26 **msg5=2400** refused=0 err=0 |
| T2 | `futari_merged_v154hi.exe` | modeIdx 1 **HOSTED** | **PASS** | grey=3 veto=0 gemsg=26 **msg5=2400** refused=0 err=0 |
| T3 | `futari_merged.exe` | modeIdx 1 **FOREIGN** | **PASS** | grey=3 **veto=1** gemsg=0 refused=0 modeidx=0 err=0 |
| T4 | `futari_merged_v154hi.exe` | modeIdx 0 **FOREIGN** | **PASS** | grey=3 **veto=1** gemsg=0 refused=0 modeidx=0 err=0 |
| T5 | `futari_merged.exe` | greyed title row 1 | **PASS** | grey=3 **veto=0** gemsg=0 refused=0 modeidx=0 err=0 |
| NEG | `futari_merged_v154hi.exe`, `RT_MODESTUB=0` | modeIdx 0 FOREIGN | **PASS** | **refused=1**, modeidx=1, **zero `[modestub]` lines** — the wedge returns |

Logs: `/c/tmp/modeprobe/gate_T{1,2,3,4,5}/boot.log` + `gate_T4_leveroff/boot.log`.

Readings that matter:

- **L1 does not interfere with the hosted load.** The coordinator's prime suspect is exonerated:
  T1/T2 grey three rows and still reach `msg5=2400` with zero errors, on **both** arms.
- **T5 proves L1 actually vetoes**, not merely "doesn't break": A on a greyed row produces
  `veto=0` — the fold `FUN_821B7CC0` is *never called at all*, because the guest's own
  `FUN_821BA4D8` short-circuit swallowed the confirm. That is the register-true decline working.
- **`REFUSED == 0` on T3/T4** — L2 declines before the loader ctor is ever constructed, so the
  `merged_bridge.cpp` mode-substitution guard is now **dead code on the menu path**. It stays as
  the last line of defence and as L3's trigger; a `REFUSED` on a future gate run means a stub
  layer MISSED.
- **The negative control is the proof the layers are load-bearing**: same exe, same NAV, lever
  off ⇒ the banked wedge returns verbatim.

### Honest gap

**L3 is asm-proven but NOT runtime-exercised.** L1+L2 now prevent any foreign module from
reaching the driver, so nothing on the tested paths can make `modectx+0xF8 == 0` — L3 printed 0
lines in every run, as it should. Its predicate (the hmodule slot all eight loader ctors write)
and its effect (`modectx+0x68` ⇒ the `0x820619F0` kill delegate) are proven at instruction level
in `shell/gen/ppc_recomp.34.cpp`, and the bounce it triggers is the one
`NOTE_fnf11_handback_decomp.md` PART 2 measured — but **that is inference, not a measurement of
this code path**. Reaching it needs a deliberately broken `assets/media/Module/*.xex`. Cheap
post-beta leg; not claimed as verified.

Also still unverified by eyeball (log-only runs, `RT_NVKPNG=0`): what a greyed row actually
*looks* like, and whether the `arcade_front` panel is torn down on the L2 route. Neither can hang
the game — worst case is cosmetic. Attended pass recommended before the beta1 cut.

## 2026-07-31 — ★★★★★★ BETA1 AUDIO **PHASE 2: ALL GATES GREEN, BOTH ARMS**. Beta has sound.

Build: `build_win.sh` + `_tmpscripts/build_win_abn.sh` both LINK_OK on the phase-1 code. Gate ladder
`_tmpscripts/beta_audio_gate.sh`. Boot lock held for the whole ladder; PID-scoped kills only.

| gate | arm | result |
|---|---|---|
| **noenv** | normal | **PASS** — ZERO `[xsb]`/`[cue]`/`[xwma]`/`[bridge]`/`[audio]` lines, no wav, 59.9-60.0 fps. No leak when disarmed. |
| **cue** (in-process harness) | normal | **PASS** — `/c/tmp/aud/beta_cue.wav` 38.9 s, RMS **5804**, 95% continuity, longest window 34 s, **peak 0.910 (no clip)**, dropped=0, 59.8-60.1 fps. |
| **field** (training drive) | normal | **PASS** — `/c/tmp/aud/beta_field.wav` 80.8 s, RMS **5468**, 80% continuity, **longest continuous window 62 s**, peak 0.9987, 59.8-59.9 fps, no SIGFPE/crash. |
| **revert** (same drive, `RT_CUEBRIDGE=0`) | normal | **PASS** — `/c/tmp/aud/beta_revert.wav`; dispatch site inert, crux takes over, SYS_SE silent again. |
| **cue harness** | **HI / v154hi** | **PASS** — `/c/tmp/aud/beta_hi_cue.wav` 40.9 s, RMS **5875**, **98% continuity**, 37 s continuous, peak 0.797, 60.0 fps. |

**★ THE REVERT LEVER DISCRIMINATES PERFECTLY** (same drive, one env var apart):

| signal | field (`RT_CUEBRIDGE=1`) | revert (`=0`) |
|---|---|---|
| `[cue] SoundBank … ->` (dispatch site fired) | **5** | **0** |
| `[cue] SYS_SE …` (menu SFX dispatched) | **16** | **0** |
| `[crux-xwma] … -> bridge dispatch` | **0** (says "cue bridge owns dispatch") | **10** |
| SYS_SE decodes | **19** | **0** |
| wav overall RMS / continuity | **5468 / 80%** | 3036 / 31% |

⇒ the new site is the ONLY reason the shell's menu SFX exist, the crux stands down cleanly with no
double-play, and turning the lever off restores the pre-07-31 behaviour exactly.

**OPEN QUESTIONS FROM PHASE 1, ALL ANSWERED BY THE BOOT:**
1. **Does `sub_820EEE00` fire for the shell's own menu cues? YES.** Live, in the menu drive:
   `[cue] SYS_SE cue5 (SE_Select01) -> SYS_SE wave 1` x11 (cursor moves) and
   `[cue] SYS_SE cue1 (SE_OK01) -> SYS_SE wave 5` x3 (confirms). **The START-press confirm SE is
   audible for the first time in the port's life.** No fallback to `sub_820EEC10` needed.
2. **Is the resident `.xsb` byte-identical to disk? YES — all five banks matched by EXACT byte
   prefix**, zero `prefix mismatch` fallbacks:
   `SYS_SE@0x377F00 · SYS_BGM@0x377CA0 · SE@0x37CC30 · BGM@0x377730 · VOICE@0x436D70`.
   Zero `MISMATCH`, zero `identity-fallback`, 225/225 cues mapped from the banks live.
3. **Any double-play? NO.** Every game cue that reaches the crux logs
   `(cue bridge owns dispatch)` and dispatches exactly once, from the shell site.
4. **BGM cue-STOP still unwired** — the host stream loops until another cue commits.
   `rt_audio_bridge_stop_music()` exists with no caller. **Accepted for beta** (diagnostic tier);
   post-beta item alongside register-true placement.

**NEW THINGS AUDIBLE THAT NEVER WERE:** menu cursor + confirm/cancel SFX (`SYS_SE`), menu music
(`SYS_BGM` `mushifuta_Menu02`, streamed 80.1 s with its real loop point), and the CORRECT BGM track
per cue. Loop points confirmed live and exactly as banked: `BGM[0] loop@264212 (66053,1396363)`,
`BGM[1] loop@1189164 (297291,3790459)`, `SYS_BGM[0] loop@18024 (4506,3838960)` — the intro no longer
replays on every pass. Cue names now print live (`VOICE cue72 (reco_03)`, `SE cue25 (se26c)`,
`BGM cue0 (m01_slct)`), which makes every future audio log self-describing.

**Mis-map fix visible in the field log:** game `cueId=2` -> bank cue 4 -> `[bridge] PLAY BGM[3]`
(m05_govr). Pre-07-31 that played wave 4. 11 of 13 BGM cues were wrong; they are right now.

**Limiter proven:** 07-29 capture peaked **1.376** full-scale (hard clipping into the device); the
field capture peaks **0.9987** with 13k samples routed through the soft knee. No audible clip path.

Evidence: `/c/tmp/aud/beta_{cue,field,revert,hi_cue}.wav`, logs `/c/tmp/beta_aud_*.log`.
NOT deployed to `Desktop/dist` — the main session owns the deploy.

## 2026-07-31 — ★★★ BETA1 CANDIDATE DEPLOYED (stubs green + AUDIO GREEN both arms)

Stub gates: T1-T5+NEG all PASS (agent's T1 "fail" was an un-positive-controlled gate
criterion — "cur76=6 want80=5" occurs in HEALTHY runs; real discriminator = [gemsg];
criterion retracted at source, modestub_gate.sh now executable law). AUDIO phase 2: noenv/
cue/field/revert/hi-cue ALL PASS — menu SFX audible for the first time (SE_OK01 wave5 on
confirm, SE_Select01 on cursor), menu BGM streams with real loops, 11/13 wrong BGM cue→wave
mappings fixed, limiter holds peak 0.9987 (was 1.376 hard-clip), revert lever discriminates
(RT_CUEBRIDGE=0 → site inert, crux path returns). Root historical fact banked: EVERY shipped
alpha was SILENT BY CONSTRUCTION (launchers never armed a sink — RT_AUDIOPUMP only runs the
guest mixer). BGM cue-STOP unwired = accepted beta tier (stream loops until next cue; stop fn
exists uncalled). DEPLOYED: exes + launchers (census + audio + modestub defaults) → user
Desktop + dist, zip respun. ATTENDED CHECKLIST for the user pass (pre-cut): [ears] menu music
+ START click; [eyes] greyed foreign rows, veto bounce leaves menu sane, arcade_front
teardown; [kb double-fire]; [Score Attack decline]. Post-beta debts filed: L3 live-exercise
(needs broken .xex), BGM stop site, register-true audio placement, ranking-RT staircase
(shadow leg — localized, next), [shdump] vte=400 transform fix.

## 2026-07-31 — USER DIRECTIVE: COMBINED EXE for beta1 (L4/L5 lane activated)

User: ship beta1 with ONE combined exe for the two 1.5 modes if effort permits. Assessment:
prerequisites pre-paid (L0-L3 done, reattach live-proven 07-29, stub hosted_mode_idx lands
the descriptor hook). L4 (module DLLs + loading host) + L5 (mode-select-driven swap; the
RT_MODESTUB L2 veto point becomes the load trigger for modeIdx 0/1) launched as a phased
opus agent (phase 1 code-only; audio agent holds the lock for the starvation fix). Hard
problems assigned deliberately: shared guest address space across swap (reattach handles
data, verify code sections), per-module statics audit, per-module GameEntry ordinal,
hosted_mode_idx -> mask semantics. FALLBACK RULING: the two per-module exes stay intact and
remain the beta1 ship if L4/L5 hits a landmine class — combined then becomes beta2 headline.
Meanwhile AUDIO live gate FAILED quality tier (user: "crunchy then slowdown"; telemetry: ring
7->1 drain = production behind sink) — audio agent on it with a starvation gate added.

## 2026-07-31 — AUDIO PACING FIX: live-gate FAIL root-caused, repro'd, fixed, gated

User's attended live gate FAILED ("at first crunchy, and then maybe some slowdown in it"). Root
cause was NOT content — it was the transport clock, plus a second stall on top of it.

**ROOT CAUSE 1 — TWO FREE-RUNNING CLOCKS WITH A ONE-SIDED BRAKE.** The guest mixer was clocked
from the VBLANK thread (RT_AUDIOPUMP accumulator, 187.5 * achieved_vblank / assumed_vblank) while
the audio device consumes at exactly 48000/256 = 187.5 frames/s off its own crystal.
`rt_audio_can_accept()` can only throttle production DOWN when the ring is full; **nothing could
ever let the producer catch up**, so any sustained deficit was permanent and cumulative. The user's
log shows the whole 8-frame buffer draining in ~10 s: depth 7 (frame #1) -> 1 (#188) -> 0 (#1880),
with `dropped=0` throughout — which is why every existing instrument looked healthy. `dropped`
counts ring-FULL, and the ring was never full; it was permanently EMPTY.

**ROOT CAUSE 2 — DECODE UNDER THE MIX LOCK.** `rt_xw_get()` decoded while holding `g_br_mtx`, the
same mutex `rt_bridge_mix()` takes on EVERY submitted frame. A first-play decode is 4-12 ms (user's
log: SYS_SE[0] 11.9 ms) = 2+ device periods where the producer cannot hand over a frame, right at
the moment a new sound starts. That is the "at FIRST crunchy" specifically. `rt_br_start_pcm()` had
the same shape (header read + fopen of a 182 MB bank under the lock).

**FIX (all lever-gated):**
1. `rt_audio_worker_on()` now defaults ON whenever a live sink is open — the dedicated worker
   produces ONE frame per frame the device CONSUMES, primed 8 deep (rexglue AudioSystem parity).
   Demand-driven, so drift is impossible by construction. RT_AUDIOWORKER=0 restores the vblank pump.
2. `rt_audio_worker_wait_token()` is now a BOUNDED wait (250 ms) granting a token on timeout — a
   dead/suspended sink can no longer park the guest render callback and freeze guest audio clocks
   (same hazard `rt_audio_can_accept()` got a watchdog for earlier on 07-31).
3. Decode + bank-open moved OFF `g_br_mtx` (new `g_clip_mtx` for the cache; the lock is held only
   to install a finished voice). Clips returned BY VALUE — a pointer into `g_xw_clips` could dangle
   on a later push_back from another thread.
4. NEW `RT_AUDIOSTARVE`: per-second min/max ring depth + UNDERRUNS (device had room, ring empty),
   plus ring depth on the periodic `[audio]` line. The old telemetry could not see a slow drain at
   all — depth printed only at frames #1/#188/#1880.
5. NEW `RT_AUDIOSTALLTEST=<ms>`: the instrument's positive control (stalls the producer on a
   schedule). Instruments lie until positive-controlled.

**GATE TABLE (normal arm, exe 13:52 — all of these ran against it):**

| gate | result |
|---|---|
| starve-legacy (RT_AUDIOWORKER=0, live, 125 s) — REPRO | ring depth min=0 max=1 every window, **38,795 underruns** (~350/s), dropped=0, 60 fps. The user's defect, quantified. |
| starve-fix (worker default, live, 125 s, with cue traffic) | **124/124 windows min=6 max=7, ZERO underruns**, dropped=0, 60 fps, no 250 ms fallback grants. Decodes logged "off the mix lock" (4.0-7.5 ms) with no depth dip. |
| starve-pc (positive control, RT_AUDIOSTALLTEST=60) | instrument FIRES: 4-20 underruns in stall windows, depth 0; recovers to min=6 between. Not stuck at zero. |
| noenv | zero audio lines, 59.9-60.0 fps |
| cue | RMS 5804.1, peak 29827.6, 95% continuity, 34 s — byte-identical to the pre-refactor run |
| field | RMS 5455.7, peak 32672, 78% continuity, 52 s continuous; 5 banks identified, 16 SYS_SE dispatches, 0 crux double-dispatch, 8 decodes off the lock |

WAVs: `/c/tmp/aud/beta_{cue,field}.wav`; logs `/c/tmp/beta_starve_{legacy,fix,pc}.log`,
`/c/tmp/beta_aud_{noenv,cue,field}.log`. Ship launchers now pin RT_AUDIOWORKER=1 explicitly.
Gated exe preserved at `_tmpscripts/futari_merged.audiogate_1352.exe`.

## 2026-07-31 14:03 — TREE DOES NOT LINK: half-applied L4/E6 global move (NOT the audio leg)

Discovered when the HI rebuild failed DURING my gate run. The L4/L5 lane's uncommitted work edited
`out_reco/merged/merged_common.h` (14:02:34) and `out_reco/merged/merged_game.cpp` (14:03:06): the
definitions of **g_rt_realstage and g_rt_romactive were REMOVED from merged_game.cpp** with the
comment "the DEFINITION moved to merged_bridge.cpp (host side)" — but **merged_bridge.cpp contains
ZERO occurrences of either name.** The move is half-applied, so:

    lld-link: error: undefined symbol: g_rt_realstage
      >>> referenced by merged_game.o (sub_88138F08) and vk_render.o (renderFrameReal)

This breaks BOTH arms (both TUs are in both links). I did NOT touch it — guessing at the intended
home for the storage would be worse than leaving it. Fix = add the two definitions to
merged_bridge.cpp (or revert the removal).

**CONSEQUENCE: futari_merged_v154hi.exe NO LONGER EXISTS** — `build_win_abn.sh` rm -f's its output
before linking, so the failed link deleted it. The newest surviving HI binary is
`dist/futari_alpha1a/futari_merged_v154hi.exe` (13:40), which has the .xsb/cue work but NOT today's
pacing fix. **The HI arm must be rebuilt once the tree links again, before any deploy** — otherwise
the XBOX 360 mode ships the crunchy audio the user just rejected. The normal arm is unaffected
(13:52 exe, backed up).

## 2026-07-31 — L4/L5 lane: ★ BOOT-CRASH POST-MORTEM (my bug, found + fixed + both arms green)

Full detail: `_tmpscripts/l4l5_combined_notes.md` §0. Coordinator bisected an ARCADE boot crash
to my uncommitted shared-file edits. **It was ONE bug, and not the six files the bisect
implicated** — it was the generated shim's LOCATION.

**Root cause.** `tools/gen_host_abi.py` wrote `out_reco/module_shim.cpp`, which
`build_win.sh:49`'s `for f in out_reco/*.cpp` glob sweeps (same for `build_merged.sh:41` and
`build_win_abn.sh:114`). The shim DEFINES all 59 `__imp__<kernel>` symbols as forwards through
`g_host`, a pointer only `FutariModuleBind()` sets — never called in a per-module exe, so null.
The link is `/FORCE:MULTIPLE` over `obj_win/game_*.o`, which expands ALPHABETICALLY, and
`game_module_shim.o` sorts BEFORE `game_rt.o`/`game_stubs.o` ⇒ the null thunks silently displaced
the 129 real kernel stubs. First-def-wins — the very mechanism build_win.sh relies on to make the
game tree beat the shell tree — turned against us.

**Proof by arithmetic, not narrative** (4 independent facts agree):
`offsetof(FutariHostAbi, imp_NtAllocateVirtualMemory)` = **184 = 0xB8** = the reported fault
address exactly (neighbours: `MmFreePhysicalMemory` 0xB0, `NtClearEvent` 0xC0); the guest first
calls it in `_heap_init -> heap_create` = the reported stack; `imports called=0` because the
counter lives in the real stub that was never reached.

**Fix — two defences.** (1) shims moved to `moduleshim/`, a dir NO build script globs (audited);
(2) every generated shim now opens with `#ifndef FUTARI_IN_MODULE_DLL / #error`, POSITIVE-
CONTROLLED both ways — fails with that #error under build_win.sh's flags, compiles under
`-DFUTARI_IN_MODULE_DLL=1`. A recurrence is now a build failure naming the cause, never a silent
link hijack. Generator also deletes any stale `<moddir>/module_shim.cpp`.

**BOTH ARMS REBUILT + BOOT-SMOKED GREEN** (`modeprobe.sh` DUR=60): ARCADE 87 objects, LINK_OK,
**2274 lines = baseline exactly**, gemsg=24, 0 crashes, 0 VK errors, reco_normal loaded. HI 88
objects, LINK_OK, gemsg=24, 0 crashes, 0 VK errors, reco_abnormal loaded. `[modestub]` L1=3 /
L2=0 on both ⇒ the hosted_mode_idx->MASK rewrite reproduces pre-change stub behaviour exactly.
HI's 2134-vs-2138 line delta was POSITIVE-CONTROLLED as noise: same binary re-run gave 2138 and
matched the baseline's per-tag counts exactly; the only movers across three runs were
`[evt14][setev][svc][waitmulti]` (thread/event scheduling) while gemsg/crash/vk were identical.

**LESSON BANKED (new standing rule for this lane, at coordinator's instruction):** `-fsyntax-only`
CANNOT see link-time symbol resolution. Any change to a file shared with the per-module exes is
NOT DONE until both arms are REBUILT and BOOT-SMOKED; discriminator is `[gemsg]` per the 07-31
retraction. "Instruments lie until positive-controlled" applies to BUILD instruments too — a
green syntax check was an instrument I had not controlled against the failure mode I was creating.

**Also banked this leg (all boot-green):** measured ABI = 59 kernel + 15 helpers + 4 globals,
same `abi_hash` on both arms; host-needs-from-DLL is down to **2 symbols** (L2/L3 pre-paid it).
★ `g_rt_romactive`/`g_rt_realstage` MOVED merged_game.cpp -> merged_bridge.cpp: they are written
by the game half and read by the host, and `vk_render.cpp:376`'s `__attribute__((weak))`
definition means a per-DLL copy would have LINKED CLEANLY and left `rt_rom_render()`'s gate and
the TATE pillarbox permanently false — a silent class, killed by construction.
`vk_render.cpp`'s `GA_FIELD_ACTIVE` is now descriptor-driven (the last `-DGA_DSHIFT` consumer,
L3's documented follow-up); `-S` proves each arm folds to its OWN immediate, 21x`0x885C1A20` on A
/ 21x`0x885C1A80` on B, zero crossovers.

NOT YET DONE, no claim made: `build_win_dll.sh`, combined/DLL-arm compile verification, G1-G7
gate plan. **No combined exe has been built or booted.**

## 2026-07-31 — USER EARS VERDICT: pacing ACCEPTED ("sounds fine"); BGM STOP promoted to cut

Two behavior defects, both the known unwired-stop debt, now user-confirmed ground truth:
(1) menu music must STOP on mode-select commit (hand over to ROM sound); (2) ATTRACT HAS NO
MUSIC — SFX only. User requires decomp confirmation of both (find the guest's real stop
sites — Prepare funnel sub_820EEE00's Stop sibling — no host-side fade heuristics). Audio
agent dispatched with gates G1-G4 (stop fires at guest site / attract WAV music-free with SFX
present / menus unaffected / lever isolation). Earlier same hour: L4 boot-crash root-caused
by the agent — generated module_shim.cpp in glob-swept dirs defined 59 __imp__ syms as null
forwards, alphabetical first-def-wins hijack; offsetof(FutariHostAbi, imp_NtAllocateVirtual-
Memory)=0xB8 = the fault address. Fixed (moduleshim/ + #error tripwire, positive-controlled
both ways); shared six files EXONERATED; both arms re-baselined. RULE ADOPTED: -fsyntax-only
is not neutrality; shared-file done = both arms rebuilt + boot-smoked on [gemsg].

## 2026-07-31 — BGM STOP LEG: the menu music was never supposed to be audible (guest-confirmed)

User defects: (1) main-menu music keeps playing after mode select, (2) attract must have NO music,
only SFX. Requirement: confirm both via real guest code. Everything below is measured.

### What the guest actually does — three findings, in the order they were forced

**1. The stop machinery exists and is fully mapped — and the shell never uses it.**
`FUN_820ef018` (the function-table entry immediately after Prepare's `0x820EEE00`) is
`IXACT3SoundBank::Stop(cueIndex, flags)` -> `FUN_820e8b98(engine, bank, cueIndex, immediate, wait)`,
which walks the engine's active-instance list (`piVar3+0x16/0x17` == `engine+0x58/+0x5c`, the list
DoWork walks), matches each node on bank (`+0x134`) and cueIndex (`+0x13C`), and stops it via
`wave->vtable[+0x04]` = **`sub_820EC958`** for the in-memory cue class `0x82014688` (vtables.txt).
`sub_820EC958` decompiles as a textbook Stop (engine lock, state check via `vtable[+0x34]`, sets
`this[0x11]` to 0/2, then `FUN_820f80b0` stops the voices).
**LIVE: all four fire 0x across a full mode-select** (`RT_STOPTRACE` on `820EF018` / `820E8B98` /
`820EC958` / `820F80B0`). The shell stops nothing.

**2. It ends the menu cue by DESTROYING the instance.** The guest's own
`IXACT3Cue::GetState` (`FUN_820ecac8`) reads `inst = *(cue+0x38)` and returns **STOPPED when
`inst == 0`**, else maps `*(inst+0x58)` (1..5 = CREATED/PREPARING/PREPARED/PLAYING/STOPPING).
Mirroring that verbatim on the vblank thread — plus re-checking the identity words the engine's own
walker matches on, so a recycled object can never read as alive — makes the host stream end exactly
when the guest's instance does. Measured: `[cue-stop] guest cue instance ended (SYS_BGM cue0,
obj=0x37E1E0) -> MUSIC STREAM STOPPED`, once, at the mode-select commit. **That alone fixed defect (1).**

**3. ★ THE REAL ANSWER: the shell MUTES the music categories, and always has.**
`IXACT3Engine::SetVolume(category, volume)` = engine vtable slot 18 = `0x820E7628` (engine vtable
dumped live at `0x82013F48`; slot 7 DoWork, 8 CreateSoundBank, 14 RegisterNotification all match the
banked addresses, so the +2-shifted stock layout is confirmed). Exactly five calls per session:

    cat 3 BGM     -> 0.000        cat 4 SE     -> 1.000
    cat 6 SYS_BGM -> 0.000        cat 5 VOICE  -> 1.000
                                  cat 7 SYS_SE -> 1.000

and they REALLY APPLY: the guest gates the write on the category record's `byte+9 & 2`
(disassembly @`0x820e7684`), and replicating its own lookup live gives `flags=0x02 APPLIED=1` for
all five. The index space is `sound.xgs`'s single category table — `0 Global, 1 Default, 2 Music,
3 BGM, 4 SE, 5 VOICE, 6 SYS_BGM, 7 SYS_SE` — which matches the category field of all five `.xsb`
banks **5/5**. So the shell mutes MUSIC and keeps every SFX category: **literally the user's ground
truth**. Our bridge ignored category volume entirely, which is the only reason the menu stream was
ever audible — and why it bled into attract.

### Fix

- **Cue-lifetime mirror** (rt.cpp vblank poll + `rt_audio_bridge_music_liveness`): the host music
  stream ends when the guest's cue instance does. Guest data, guest timing, no host timer, no fade.
- **Category volume honoured** (`rt_audio_set_category_volume`, fed from the `sub_820E7628` hook;
  per-cue category parsed from the `.xsb` sound record +1). Applied to the PCM music stream and to
  every decoded one-shot.
- **Scope `RT_CATVOL`**: default `shell` honours categories **6/7 only** (the shell's own SYS_*
  banks). That kills the menu/attract music — both reported defects — and **cannot** touch the
  game's BGM (cat 3), whose audio the user already accepted. `all` = HW-literal (also silences
  in-game stage music); `0` = off.
- Levers: `RT_CUESTOP=0` (mirror off), `RT_CATVOL=0` (category off), `RT_STOPTRACE=1` (the trace).

### Gates

| gate | result |
|---|---|
| **G1 mode select** (`stop-arcade`, Ax2 -> ARCADE ROM, gemsg=28) | **PASS** — no menu music at any point (RMS 1018, 3% continuity, longest window 2 s); SFX present (2614/1441 Hz clicks); ROM SE cues (`se16a`, `se48b`) audible after handover. Before the leg: 71 s of continuous menu music straight through the ROM load. |
| **G2 attract** (`A,LEFT,A`, 147 s) | **PASS** — **no music**: RMS 812 vs 5697 before, continuity 2%, longest window 2 s, and the only content is SFX (spectral peaks 2614/1441 Hz vs music's 52-58 Hz). |
| **G3 menu music in menus** | **FAILS BY DESIGN — see the conflict below.** |
| **G4 revert** (`RT_CUESTOP=0 RT_CATVOL=0`) | **PASS** — menu music plays and never stops again: RMS 5568, 77% continuity, 71 s continuous. Pre-leg behaviour restored exactly. |
| **non-regression: gameplay music** (`field`, training) | **PASS** — cat 3 logged `outside RT_CATVOL=shell scope`; ROM stage music plays with correct loop points (`BGM[0] loop@264212`, `BGM[1] loop@1189164`, `BGM[3]`), 29 s continuous window. |

WAVs `/c/tmp/aud/beta_{stop_arcade,attract,stop_revert,field}.wav`; logs `/c/tmp/beta_*.log`.

### ⚠ THE ONE CONFLICT — G3, and it needs the user

G3 asked that menu music still play in the menus. **It no longer does, and the guest data says it
never should have**: `SetVolume(cat 6 SYS_BGM, 0.0)` is issued at audio setup, it applies, and
**nothing in any state I drove ever restores it** (menu, mode-select, attract, training field — the
only five SetVolume calls in a whole session are the ones above). The shell cues `mushifuta_Menu02`
into a muted category, so on hardware it is inaudible. The "main-menu music" in the user's report
was our artifact. If the user wants it back, `RT_CATVOL=0` restores it in one env var.

### Open question banked for the next leg

`cat 3 (BGM)` is muted at setup too and **never restored in any state reached**, yet the ROM
demonstrably plays stage music. Either the restore happens on a path none of my drives reach (a real
credited game start), or in-game music is routed past the category gain. Until that is answered,
`RT_CATVOL` deliberately leaves category 3 alone — honouring it literally would silence gameplay
music, which is why the default scope is `shell` and not `all`.

## 2026-07-31 — ★★ CATEGORY-VOLUME TRUTH: the real menus are SILENT (agent 4880cd7)

Stop machinery fully mapped (Stop=FUN_820ef018 sibling of Prepare; engine instance walk;
sub_820EC958 for in-memory cue class) — and the shell NEVER CALLS IT: instead it mutes via
IXACT3Engine::SetVolume (vtable slot 18 = 0x820E7628): cat3 BGM=0, cat6 SYS_BGM=0, cat4 SE=
cat5 VOICE= cat7 SYS_SE=1.0, gate byte+9&2 verified live 5/5. Menu music was OUR artifact
(bridge ignored category gain). FIX: cue-lifetime mirror (guest GetState semantics) +
category volume honored, RT_CATVOL default=shell (cats 6/7 only), RT_CUESTOP/RT_STOPTRACE
levers. Gates G1/G2/G4 + gameplay-music non-regression PASS. ⚠ USER CALL PENDING (G3-by-
design): menus are now authentically SILENT — if user prefers the music enhancement,
RT_CATVOL=0 in launchers restores it. OPEN (banked): how cat3 BGM gets unmuted for gameplay
on real HW (restore path unreached in drives, or in-game bypasses category gain) — until
answered, cat3 exempt from literal honoring. Deployed to Desktop+dist.

## 2026-07-31 — MUSIC VOLUME LIFECYCLE: my "authentically silent menus" call was WRONG; real
## mechanism found (shell-owned category volume), menus fixed, attract still open

Referee (user: real HW + Xenia + SDK all agree) overruled the previous leg's conclusion: **top menu
music IS audible**. Correct. The `cat3/cat6 = 0.0` SetVolume snapshot was real but it is not the
steady state. Here is what the code actually does.

### Hypotheses killed by evidence, not opinion

- **RPC / global-variable curve: RULED OUT from the data.** `sound.xgs` parses as
  `numCategories=8, numVariables=7, numRPCs=0`, and all seven variables are the XACT built-ins
  (NumCueInstances, AttackTime, ReleaseTime, OrientationAngle, DopplerPitchScalar, SpeedOfSound,
  Distance). There is no RPC table and no custom global variable in this project, so no curve can
  be driving category gain.
- **Any XACT Stop: already ruled out last leg** (SoundBank::Stop / engine walker / cue Stop /
  voice stop all 0x).

### ★ THE MECHANISM (decomp + live trace agree)

    FUN_821caa60 = SetCategoryVolume(const char* categoryName, double volume)
       matches the name against the shell's own category table at DAT_821f857c[0x91..0x95]
       (stride 0x1c), caches the value at [0x97]+idx via FUN_82066420, and THEN:
           if (DAT_821f857c[0x9d] != 0) return;      <-- early-out, engine NEVER updated
       otherwise falls through to engine vtable +0x40 GetCategory then +0x48 SetVolume.
    FUN_821cac08 = a PER-FRAME FADE TICK over the same 0x1c-stride table
       (+0x118 ramp source, +0x120 fade duration, +0x124 frames remaining, decremented per tick;
        on completion it snaps to DAT_8204f828) which pushes to the engine at lr=0x821CAE0C.

**Live proof of the split (one attract drive, `RT_STOPTRACE`):**

    SetCategoryVolume("SE",      1.000)  -> ENGINE cat=4 f1=1.000   ✓ reaches the engine
    SetCategoryVolume("SYS_SE",  1.000)  -> ENGINE cat=7 f1=1.000   ✓
    SetCategoryVolume("VOICE",   1.000)  -> ENGINE cat=5 f1=1.000   ✓
    SetCategoryVolume("BGM",     1.000)  -> (no engine call)        <-- gated, cached only
    SetCategoryVolume("SYS_BGM", 1.000)  -> (no engine call)        <-- gated, cached only

So **the shell owns music volume in its own table**; the engine's copy for cat 3/6 is left at
whatever the fade tick last pushed — 0.0 from boot. My previous leg read that stale engine copy and
concluded "music is authentically muted". It is not: the shell's cached value, i.e. the guest's real
intent, is **1.0 for BGM and SYS_BGM in the menus**.

### Implemented

- `sub_821CAA60` hooked by NAME -> `rt_audio_set_category_volume_named()`. Names come straight from
  sound.xgs's category table (Global/Default/Music/BGM/SE/VOICE/SYS_BGM/SYS_SE), so there is zero
  index ambiguity. Both this and the engine-level path feed one table; last writer wins, which is
  exactly "whichever way the guest last spoke".
- `RT_CATVOL` default flipped to **`all`** (was `shell`): with the intent-level signal present,
  honouring every category is correct AND safe for gameplay BGM. `shell` / `0` retained as levers.
- Cue-lifetime mirror and everything from the previous leg unchanged.

### Gates

| gate | result |
|---|---|
| **menus MUSIC ON** | **PASS (regression fixed)** — attract drive shows 85% loud windows / 80 s continuous with `[catvol] (shell intent) SYS_BGM (cat 6) -> 1.000`. Previous leg had menus silent. |
| **gameplay music** | **PASS** — cat 3 reaches 1.000 via the same intent path before the ROM starts, so stage BGM is unaffected. |
| **mode-select handover** | unchanged from the previous leg (cue-lifetime mirror, `[cue-stop]` at the guest's own instance teardown). |
| **attract MUSIC OFF** | **STILL FAILING — see below.** |

### ⚠ ATTRACT: NARROWED, NOT SOLVED (honest status)

With the mechanism above, attract still bleeds (85% loud windows). What is now *excluded* by
measurement, so the next leg does not repeat it:
- It is **not** the volume path: across a full menu -> attract drive, **no music volume change of
  any kind is issued at attract entry** — not by name (`FUN_821caa60`), not at the engine
  (`sub_820E7628`), not by the fade tick (the only fade activity is `idx=26 vol=1.000`, an
  unrelated entry, ticking steadily).
- It is **not** any cue/bank/voice Stop (previous leg, all 0x).
- The cue instance stays alive the whole time (the lifetime mirror correctly does not fire).

Remaining candidates, in priority order for the next leg:
1. **The fade table never gets a music fade-out scheduled.** Find the writer of `+0x118/+0x120/
   +0x124` (stride 0x1c off `DAT_821f857c+0x10c`) and see what state change is supposed to arm it;
   the attract-entry path should be arming a music fade-out and evidently is not.
2. **The port may not reach the same attract state the hardware does** (our attract runs with
   `gemsg=0`, i.e. no module loaded) — worth confirming against the SDK referee at
   `D:\Mushihimesama-Futari-PC-v1.3.6`, whose rexglue runtime is the answer key and which can be
   instrumented via REXAUDDUMP (`projects/rexglue-sdk/src/audio/audio_system.cpp`).

### Config recommendation for the coordinator

Land this build and **drop `RT_CATVOL=0` from the launchers** — the new default (`all`) reproduces
the same user-visible menu behaviour but is driven by the guest's real values, so it will start
doing the right thing automatically the moment the attract fade is understood. Attract bleed is
unchanged versus the user's current pinned config, i.e. no regression relative to what they have.

---

## 2026-07-31 (evening) — XENIA SCRIPTED-REFEREE UNLOCK + REFERENCE AUDIO ENVELOPE (coordinator leg)

**The referee can now be driven and *listened to* by script.** Three capabilities landed, all
verified against the live game, all in the session scratchpad (`xkey3.ps1`, `xshot.ps1`,
`meterlog.ps1`, `xenia_meter_take.ps1`):

1. **Input**: SendInput injection works. Both historical failures explained: the per-game config
   had `keyboard_mode=0` (ALL keyboard dead — now 1), and the old PostMessage script had a
   PowerShell 5.1 `[UIntPtr]$int` cast bug. (Also: `[ushort]` is not a PS type accelerator —
   `[uint16]`.) Verified: title→menu→mode-select→legal→attract, fully scripted, ~10s.
2. **Capture**: PrintWindow(flags=2) returns real frames from Xenia's D3D12 window.
3. **Audio meter**: per-process peak meter via the audio-session API (IAudioMeterInformation
   polled from C# — PowerShell degrades ComImport interfaces to __ComObject and cannot dispatch).
   Positive-controlled at −8.2 dBFS on menu SFX. Measures ONE pid's session, so port and
   reference can coexist.

**REFERENCE AUDIO ENVELOPE (Xenia, 194s driven take, 20 Hz, evidence
`C:\tmp\xenia_ref\xenia_envelope\` — meter.csv + per-mark PNGs):**

| segment | loudness | verdict |
|---|---|---|
| TITLE screen | −120 dBFS flat | **authentically SILENT** (music starts on START→menu transition) |
| TOP MENU | 100% sustained, −6.6 dBFS | **music ON** — user's correction now quantified |
| attract entry (A) | ~1s decision-SE burst | last shell sound |
| legal / ranking / interstitials | −120 dBFS flat | **true digital zero — no fade tail at 20 Hz** |
| demo play | near-continuous SFX | shot loops, no music underneath |

User independently confirmed mid-leg: "attract has sound but yeah, no music." Port's attract
bleed is therefore a REAL DEFECT with an exact acceptance gate: **during legal/ranking segments
the port's session must read digital silence.**

**Mechanism implication (relayed to the audio fix lane):** instant cut + true zero + the fix
lane's own findings (no XACT Stop, no volume change of any kind at attract entry) ⇒ the mute
lives BELOW the XACT category layer. Prime new hypothesis: **streaming starvation** — menu BGM
is a streamed wave; if the shell's per-frame stream-service stops being called at mode handover,
hardware goes silent instantly with the cue instance still alive (exactly what the lifetime
mirror sees), while our bridge decodes independently of the guest pump and keeps playing. Fade
fields +0x118/+0x120/+0x124 demoted (reference shows NO fade).

Also banked: title-silence is a NEW port gate (don't start menu music early). Xenia left running
post-take as a live positive-control source for the loopback-instrument workflow. Memory:
`xenia-scripted-referee-drives.md`.

## 2026-07-31 — ATTRACT-MUTE HUNT: the measurement was CONFOUNDED — the port never reaches attract

Worked the new Xenia ground truth (title silent -> menu music -> instant true-zero at attract entry,
demo play = near-continuous shot SFX). Result: the audio mechanism is not the open question; the
DRIVE is. Findings, all instrument-independent.

### 1. Streaming starvation RULED OUT in our port — the guest streams SYS_BGM continuously

`[xwbread]` (the NtReadFile probe, `RT_AUDIOCRUX`) over a 115 s menu->"attract" drive:
**297 reads of `SYS_BGM.xwb`**, 128 KB windows, offsets marching `0x800 -> 0x20800 -> 0x40800 ->
… -> 0x100800+`, double-buffered between guest buffers `0xDD01000` / `0xDD21000`, and they continue
to the LAST line of the log. The guest's streaming service is alive and healthy the whole time, so
hypothesis (2) — the shell ceasing to service the stream — is **not what happens here**. Nothing
starves, which is consistent with there being no explicit stop to find either.

### 2. ★ THE PORT NEVER LEAVES THE TOP MENU UNDER THE ATTRACT NAV

The same drive, after the last menu SFX at log line 20194: **zero cue dispatches for the remaining
~70,000 lines** — no SE, no VOICE, nothing. The reference says demo-play segments carry
near-continuous shot SFX, so a port that had actually entered attract could not be silent of cues.
Corroborating: `gemsg=0` (no module ever loaded) for the whole run, while the `stop-arcade` drive
(NAV `Ax2`) on the same build reaches the ROM properly (`gemsg=28`, ROM SE cues firing). So NAV
delivery works; the `START,A,LEFT,A` sequence simply does not land the legal->attract loop here.

**Therefore the "attract bleed" has never been observed in a verified attract state** — not in my
runs, and (worth re-checking) possibly not in the 192 s measurement either. What both actually show
is the port sitting in the TOP MENU with menu music playing, which per the new ground truth is
**CORRECT** behaviour (top menu = 100% sustained music, ~-6.6 dBFS).

This retires the whole search for a missing mute mechanism: across three legs we have now excluded
XACT cue/bank/voice Stop (0x), category volume (no change at the transition), the fade tick (no fade
armed), and streaming starvation (reads continue) — because **the guest never performs the
transition at all**. There is nothing to find in the audio layer until the drive reaches attract.

### 3. TITLE-SILENCE gate: PASS

New gate from the reference, checked on banked evidence: the port is silent on the title screen and
music starts only at the title->menu transition. Order in the log is exactly right —
`[cue] SYS_SE cue6 (SE_OK02)` (the START/decision SE) at line 14004, then
`[cue] SYS_BGM cue0 (mushifuta_Menu02)` at 14503 — and the capture is digital zero for the first
20 s (boot + title) before the first music window. We do not start menu music early.

### NEXT STEP (drive, not audio)

Get a **verified** attract state before any further audio work:
1. Re-derive the attract arming sequence against this build (the banked recipe wants the ranking
   screen ~130 s in; our run showed no screen progression at all). Confirm arrival by a
   drive-independent signal — demo-play SE cues appearing in `[cue]`, which is exactly the
   fingerprint the reference predicts.
2. Only once attract is provably entered, re-measure the music. If it then hard-cuts on its own,
   there was never a port defect; if it bleeds, the mechanism hunt resumes with the search space
   already narrowed to whatever the transition does.
3. The coordinator's `meterlog.ps1` / `loopcap.exe` give per-segment truth on our side and should be
   run against the same drive, so port and reference are compared segment-for-segment.

No code change this leg beyond arming `RT_SCENELOG/RT_MENULOG/RT_MSGLOG` in the attract gate mode.
The audio behaviour landed in `a384cbd` (menus music ON, mode-select handover stops it, gameplay
music unaffected) is unchanged and still gated green.

---

## 2026-07-31 (evening, cont.) — ATTRACT "MUSIC BLEED" **RETRACTED** — it was demo-play SFX

**The defect I chased for three legs does not exist.** Segment-for-segment metering of the port
against the Xenia reference, with every loud/silent window mapped to a SCREENSHOT rather than
inferred, shows the port's attract structure already matches hardware:

| attract segment | Xenia (reference) | port (`futari_merged_v154hi`, ship audio config) | verdict |
|---|---|---|---|
| legal screen | −120 dBFS | −120 dBFS | **MATCH** |
| ranking screen | −120 dBFS | −120 dBFS (0.0% loud, m120/m135) | **MATCH** |
| DEMONSTRATION demo play | loud, continuous SFX | loud, continuous SFX (m75/m90/m150–m180) | **MATCH** |

**Root cause of the false defect: loudness was never mapped to screens.** "35% / 85% loud
windows during attract" was read as *music bleeding*; the screenshots show those windows are the
demo-play segments, where the reference is equally loud because the ROM is firing shot SFX. Both
earlier legs (mine and the fix lane's) measured a real signal and mislabelled it. The fix lane's
own follow-up reached the same conclusion from the opposite direction (no cue dispatches, no
starvation: `[xwbread]` shows 297 healthy `SYS_BGM.xwb` reads throughout) and correctly refused
to ship a guessed fix.

⚠ **RULE (new, earned twice today): a loudness number is not a verdict — map every window to a
screenshot before naming it.** This is the audio twin of the 07-28 visual rule (an
instrument-flagged divergence is not a defect until a referee reproduces it). Note again that
the attract bleed was never a USER report; every user-reported audio defect this session was
real, and this instrument-derived one was not.

Also corrected: the fix lane's "the port never reaches attract" (from `gemsg=0` + cue silence) is
**too strong** — screenshots prove the port renders legal → ranking → DEMONSTRATION demo play
normally. `gemsg`/cue-dispatch silence is a *shell-side instrumentation gap* during ROM attract,
not an absence of attract.

### Two REAL divergences the same take exposed (both open, neither user-reported)

1. **TITLE-SCREEN AUDIO.** Port meters ~100% loud on the title screen; Xenia is digitally silent
   there until START. Suspected menu BGM starting one screen early. (The fix lane's log-order
   check — decision SE then music — passed, so this needs the direct measurement, not the log.)
2. **MENU MUSIC CUTS ONE PRESS EARLY.** Xenia holds music through mode-confirm AND the LEFT
   press, cutting only at the real handover (2nd A). The port goes silent immediately at the 1st
   A — the cue-lifetime mirror fires ~5 s early.
3. **LEVEL / CLIPPING (worth a look):** port peaks pin at **0.0 dBFS** repeatedly; Xenia's menu
   music peaks −6.6 dBFS. Possible relation to the user's earlier "crunchy" report.

Confirming probe for 1 and 2 is written and blocked only on the boot lock (`futari_combined`
boot in flight — `modeprobe.sh`'s concurrent-`futari*` guard worked as designed).

**Config note:** the ship-audio config used for this take had **no `RT_CATVOL` pin** (new default
`all`) and behaved correctly on menus and attract, corroborating the fix lane's recommendation to
drop `RT_CATVOL=0` from the launchers when `a384cbd`+ is deployed.

## 2026-07-31 — ★★★★★ COMBINED EXE BUILDS, BOOTS, AND SWAPS MODES AT RUNTIME (L4/L5 phase 2)

Detail + handoff: `_tmpscripts/l4l5_combined_notes.md` §5-§7. WOUND DOWN at coordinator's
request (audio + ranking-shadow are the ship-blockers); per-mode exes remain the beta1 ship.

`bash build_win_dll.sh` -> **BUILD_OK**: `futari_combined.exe` (50 obj) + `futari_game_normal.dll`
(39) + `futari_game_abn.dll` (39). New: `build_win_dll.sh`, `host/module_registry.{h,cpp}`,
`host/futari_dll_globals.h`, `moduleshim/module_shim_reco_{normal,abnormal}.cpp` (generated),
`_tmpscripts/combined_gate.sh`.

**GATES: 6 of 7 RUN, ALL PASS.** G5 (audio parity) NOT RUN — needs 2 boots, lock released first.

| G | proves | result |
|---|---|---|
| G1 | boots, binds BOTH DLLs, loads ARCADE | PASS — bound=2, mask=0x03, gemsg=**24**, msg5=**8**, EXACT parity with the per-mode ARCADE exe; crash=0 vk=0 |
| G2 | ★ **LIVE-FIRE SWAP** normal->abn | PASS — residue=**0**, image window zeroed (8060928B), 8421 slots retired+installed, ordinal **0x8824E698->0x8824E6A0**, code_size 0x1DEEB0->0x1DEEB8, abn .data re-imaged 6060860B, DllMain r3=1, gemsg=25, crash=0 vk=0 |
| G3 | reverse-order boot (RT_STARTMODULE=reco_abnormal) | PASS — gemsg=24, crash=0 vk=0 |
| G4 | foreign rows grey + bounce, never wedge | PASS — grey=3, gemsg=0, refused=0, swaps=1 (boot only) |
| G6 | heap sane across a swap | PASS (see correction) |
| G7 | [modestub] T1-T5 equivalents | PASS — hosted picks veto=0 on BOTH arms (L2 correctly STEPS ASIDE so the swap can fire); foreign grey=3 |

**The three "hard problems" from the brief, all observed solved in G2's log:** (a) shared guest
address space — both modules map at 0x88000000 and share ONE table window; deactivate/zero/install
handles it, residue=0 proves no dangling slot; (c) per-module GameEntry ordinal — the descriptor
carries it and XexGetProcedureAddress returned abn's 0x8824E6A0 after the swap; (d) hosted_mode_idx
-> MASK — combined mask=0x03, so L2 vetoes only true foreigners while modeIdx 0/1 fall through to
become the swap trigger. (b) per-module statics: host-side singletons moved out (see below).

**★ G6 CORRECTION, banked because my first reading was WRONG.** The swap run's heap climbs to
496MB, near the 512MB line. It is NOT swap-induced: g3 (abn boot, NO swap) and the per-mode HI exe
ALSO peak at exactly 496MB, while ARCADE peaks at 336MB on both exes. 496MB is the abn module's
normal high-water. `[pool] EMERGENCY-REUSE (512MB line defense)` fires **40x in the combined swap
run and 40x in the per-mode HI exe** — exact parity. No swap-induced heap regression.

**★ PLAN §4.4 PREDICTION FALSIFIED (the no-/FORCE:MULTIPLE hard gate did its job).** §4.4 predicted
each DLL would link WITHOUT /FORCE:MULTIPLE. It FAILED, naming two strong-over-strong classes:
(1) the DOCUMENTED decomp seam — `decomp/game/game_entry_msgs.cpp` and the generated ppc_recomp.32
BOTH define `__imp__sub_8824E698` (PILOT_NOTES §2 specifies exactly this; the decomp override
mechanism IS first-def-wins and needs the flag wherever it lives); (2) ★ **A PRE-EXISTING SHADOW
NOBODY HAD MEASURED** — `sub_8807A578` / `sub_8807D4F8` / `sub_8807DD88` carry a strong PPC_FUNC in
BOTH `decomp/game/nvk_game_hooks.cpp` AND `merged_game.cpp`; verified in the SHIPPING objects
(llvm-nm obj_win/). decomp_*.o is first on build_win.sh's link line, so decomp wins and
merged_game's wrappers — including `R26_BRACKET_WRAP(sub_8807D4F8)` — are **SILENTLY DEAD in both
shipping exes today**. That is the exact landmine PILOT_NOTES §2 warns about, live on 3 more
functions than documented. NOT fixed here (changing the winner changes shipped behaviour; needs its
own leg + A/B). DLLs now link WITH /FORCE:MULTIPLE, decomp_*.o first = the exe's resolution order.

**KNOWN-BENIGN, flagged so it is not mistaken for a pass:** `[swapinv] req#N NOT acknowledged
within 400ms` fires on every swap — during a swap there is no game, so no draws, so the render
worker never reaches the ack while the guest thread waits. Correctness holds (the consumer sits at
the HEAD of getTexIndexReal; logs confirm `dropped texCache=0 resolveTex=93 nvkRT=2`), cost is
400ms dead time inside a multi-second mode load. Follow-up: shorten the wait + reword. Residual:
`getTexture()`'s RVK_PASSTHROUGH path reads g.texCache without going through getTexIndexReal.

**NOT PROVEN, explicitly:** the quit->top-menu->reselect swap. G2 swaps on the player's FIRST pick,
covering every step except swapping a module that was attached AND torn down. No scripted NAV for
the in-ROM quit exists (the 07-29 RT_REATTACH proof was USER-DRIVEN). G2b is attended work.

**Tree committable + verified:** both fallback arms rebuilt AND boot-smoked after the final
shared-file edits — futari_merged.exe 87 obj LINK_OK 2277 lines **gemsg=24**;
futari_merged_v154hi.exe 88 obj LINK_OK 2141 lines **gemsg=24**; both crash=0 vk=0 grey=3 veto=0.

**Process failure banked:** I chained `tasklist` + two builds in ONE call, so a "LOCK BUSY" warning
printed while another lane's v154hi boot (PID 28072) was live and the build relinked that exe
anyway. No damage (Windows maps exes FILE_SHARE_DELETE: `rm -f` unlinked while the running process
kept its mapped image; both exes verified loadable after). The guard printed and did not stop me —
**check the lock in its own call and act on the result BEFORE starting a build.**

Lock RELEASED, no futari* processes left running.

---

## 2026-07-31 (evening, cont.) — ALL THREE "AUDIO DIVERGENCES" RETRACTED; audio is DONE pending deploy

Single-threaded follow-up (user asked for less fan-out). One properly time-aligned probe
(`title_probe`, PROC-START stamped, meter wall-clock aligned to 24 timestamped screenshots,
`/c/tmp/modeprobe/title_probe/`) plus one sample-level dump killed all three:

| claimed divergence | verdict | evidence |
|---|---|---|
| title screen has audio | **RETRACTED** | frames f00–f07 (pre-START, title on screen) all −120 dBFS; audio begins ~3.6 s AFTER the START press. Port matches the reference exactly. |
| menu music cuts one press early | **RETRACTED** | 100% loud through A#1 (t=21.4), LEFT (24.4) and A#2 (27.4); f18 shows TOP MENU/Arcade still sounding, f23 shows it continuing into "Now Loading". Music holds *past* the presses as the reference does. |
| clipping at 0.0 dBFS | **RETRACTED** | 48.9 s dump, 4.69 M samples: peak 0.99839 (−0.01 dBFS), **0 samples at full scale, 0 flat-topped runs**. Hot, not clipped. |

**Both retracted "divergences" 1 and 2 came from the SAME error I had just written a rule about:**
segment boundaries derived from *arithmetic* (assumed process-start offset) rather than from
timestamped screenshots. The earlier take had no PROC-START stamp, so its alignment was a guess.
**Strengthened rule: never align a meter run by assumed offsets — stamp the process start and the
screenshots with wall clock, and align on those.** (Third instance today of measurement-artifact
defects; every user-reported audio defect has been real, every instrument-derived one has not.)

**Also retired: cross-app absolute LEVEL comparison is not an authenticity test.** The port peaks
−0.01 dBFS vs Xenia's −6.6 dBFS, but Xenia applies its own attenuation, so the difference says
nothing about the hardware. Per-process metering is valid for *structure* (silent / SFX-sparse /
sustained) — not for absolute loudness.

Only real remaining audio divergence found: menu music continues over our "Now Loading" screen,
which the reference passes through faster. Judged NON-DEFECT (longer host load, music covering it
is reasonable) — filed, not fixed.

**AUDIO STATUS: complete at `a384cbd`.** Nothing further to implement; it needs deploying with
`RT_CATVOL=0` dropped from the four launchers (new default `all` is the intent-driven path).

---

## 2026-07-31 (evening, cont.) — SHADOW LEG: instrument fixed; square shadow NOT REPRODUCIBLE on the current build

Single-threaded, using the new 44 s scripted attract repro (no hand-driving needed — this is what
unstalled the leg).

### 1. Author class CONFIRMED, then made moot
`RVK_MODOFF=05000500` (drop the modulate-blend class, dst *= 1−src) A/B'd against default. The
class is authored by `vs=45 ps=50`, `tex=0x134E8000`, `c2={0.9,0.9,0.9}`, 56×120 tiles in the ROM's
640×512 target. Had the defect still been present, `dst *= (1−0.9)` ⇒ near-black rectangles was the
mechanism, and a constant-instead-of-textured source the root cause. It did not get that far.

### 2. `[shdump]` TRANSFORM FIXED (the flagged ~5-line bug) — `render/vk_render.cpp`
The dump applied the matrix + NDC→viewport mapping **unconditionally**. That is only valid when the
hardware viewport transform is ENABLED (`PA_CL_VTE_CNTL` bits0-5 all set). With them clear the guest
has already emitted WINDOW coordinates — the same rule the renderer uses at its own `RVK_VTEVP`
site. **Every modulate-blend shadow draw is `vte=0x400`, so every position this dump ever printed
for the draws under investigation was wrong.** Now branches on `(vteCntl & 0x3F) == 0x3F`, labels
which convention it used (`scr[vp]` / `scr[raw]`), prints the bbox `size=`, and dumps vertices for
stride 16 as well as 12. Before: `scr={60.7,35.2..116.7,205.9}` (meaningless). After:
`scr[raw]={122,110..234,350} size=112x240` — clean integer window coords. Default off ⇒ byte-identical.

### 3. THE DEFECT DOES NOT REPRODUCE
Captured the ranking screen across the whole scroll cycle (4th/5th, 2nd/3rd, **1st/2nd — the exact
page and scores as `evidence_shadow/port_default_ranking_square.png`: 1st KOK 6880571 / 2nd NMR
4000000**) and at the USER'S OWN config, `RVK_WINSIZE=1920x1080` + `RVK_DRAWCENSUS=1` (the launcher
pins these; `modeprobe.sh` does not — a config gap worth remembering when a defect "won't
reproduce"). Plaques render clean in every phase, matching
`evidence_shadow/ref_v136_ranking_2nd3rd_noshadow.png`. Evidence: `C:/tmp/shadow/` (`A2_*`, `sweep/`,
`hd/`).

**Most likely cause of the disappearance: the layered-allocator fix.** The defect capture is
11:52 today, before that landed. Garbage/aliased texture memory returning an opaque block for the
shadow sprite is exactly the "square shadow" signature, and the same fix cured the user's stage-2 /
stage-4 corruption reports. Not proven — offered as the leading hypothesis, not a claim.

⚠ **NOT CLOSED — awaiting the referee.** The user reported this defect repeatedly and recognises it
instantly; three instrument-derived visual/audio calls were retracted today. Their eyes settle it.

---

## 2026-07-31 (evening) — ⚠ DEPLOY REGRESSION, REVERTED; and the HANDOVER FADE found

### ⚠ What I broke, and the revert
The 19:17 deploy (new exes + dropping `RT_CATVOL=0` from the four launchers) produced a
**user-reported SFX regression: "when the ship is shooting its not right"**. Reverted immediately
to the exact state the user played successfully all afternoon: exes restored from
`/c/tmp/deploy_backup_0731` (md5-verified identical) and the `RT_CATVOL=0` pin restored in all
four launchers.

**Process failure to own — I shipped on a gate that did not cover what I changed.** Dropping the
pin switches category volumes from "ignored" to "applied to ALL categories", and every gate I ran
was a MENU-MUSIC gate. Nothing exercised in-ROM gameplay SFX. The lesson is not "the change was
wrong" (it may well be right) but that the gate must cover the blast radius of the lever being
moved, not the symptom being fixed. Launcher comments now say so explicitly.

### ⚠ SECOND, INDEPENDENT REGRESSION FOUND BY A/B — ARCADE arm does not start the ROM
Same NAV, same env, DUR=32: previously-deployed `futari_merged.exe` reaches **gemsg=34**; the
current tree's build reaches **gemsg=0** (`shadow_dump2` corroborates: zero offscreen draws).
The ARCADE arm never enters GameEntry. **This predates my fade change** (shadow_dump2 was built
before it) so the suspects are commit `0d7883b` (L4 combined-exe: `merged_bridge.cpp`,
`module_registry`, `futari_module_desc.h`, `harness.cpp`) or the `[shdump]` change — note the L4
agent reported gemsg=24 on BOTH arms at its own final smoke, so this needs a real bisect.
**NOT YET DIAGNOSED. The ARCADE launcher must not ship until it is.**

### ★ THE HANDOVER FADE — found, implemented, gated (in tree, NOT deployed)
User: "the music.. the cutoff is weird and abrupt" — correct, and a real defect.
Reference (Xenia, 20 Hz per-process meter): the menu music does not hard-stop, it **fades**,
−6.7 dBFS at t=26.14 sliding smoothly to −73 dBFS by t=28.06 (~1.9 s), then digital zero. My
earlier "no fade tail, it's a hard stop" was WRONG — 15 s segment buckets averaged the ramp away.

Mechanism, measured not assumed: the guest fades **category 0 ("Global")**, the XACT root category
that scales all others. `sub_821CA078(idx=0, vol)` is called **43×** from the fade tick
`FUN_821cac08` (lr=0x821CAD14) with vol sliding 1.0000 → 0.0001, and the cue teardown our bridge
was reacting to happens only AFTER the ramp completes. We tracked per-cue categories only and
**never read category 0 at all**, so the whole ramp was invisible and we played at full level into
a hard cut.
Getting there took three filter passes worth recording: the entry layout guess (r3+0x10c stride
0x1c) returned pointers; a raw memory diff drowned in boot noise; and a float-range filter let
**denormals** through (0x00003018 reads as ~1.7e-41, technically in (0,1)). The working filter
requires both readings to be 0 or in [1e-4, 1.0].

Implemented: `rt_master_gain()` in `rt_audio.cpp` follows the guest's category 0 EXACTLY (no
restore logic of our own, so if the guest ramps back up on menu re-entry we follow), applied at
both `rt_cat_gain` sites — which are inside the per-buffer mix, so it ramps an ALREADY-PLAYING
stream. `sub_821CA078` routes the guest's own per-tick value in. Lever **`RT_FADEGAIN=0`**.
Measured result: the port now ramps −3.2 → −78.5 dBFS over ~1.3 s (reference ~1.9 s, same shape),
menu music still full-level up to it. Both arms LINK_OK.

**NOT DEPLOYED** — blocked behind the ARCADE gemsg regression and behind a gameplay-SFX gate.
Also still open, and confirmed by the user against my "not reproducible" call: the **ranking-plaque
square shadow IS still there** (user marked the rectangular edge right of and below the 4th plaque).
My clean captures were the same low-resolution mistake class as the audio ones — I was looking for
the old big dark bands, not a subtle bounding-box edge. Author class is confirmed
(`RVK_MODOFF=05000500` A/B removes it; `vs=45 ps=50`, tex 0x134E8000, 512×512 atlas, 56×120 tiles,
`c2={0.9,0.9,0.9}`, dst *= 1−src). Next: why the tiles darken uniformly instead of taking their
shape from the sampled sprite.

---

## 2026-07-31 — ⚠ RETRACTION: there is NO ARCADE regression (my A/B was invalid)

Claimed two entries ago: "ARCADE arm does not start the ROM — gemsg=0 vs 34". **False.**

**The flaw:** I ran the baseline from a copy named `futari_baseline_check.exe`.
`modeprobe.sh` terminates the game by NAME (`futari_merged`, `futari_merged_v154hi`) at the end
of DUR — so the baseline was never killed and kept running (and kept logging) for ~90 s, while
the new build was killed at DUR=32. I compared a ~90-second run against a 32-second one and read
the difference as a code regression.

**Control:** current build, same NAV/env, DUR=75 → **gemsg=26**. The ARCADE arm is fine. (The
32 s run really does show 0 — GameEntry simply is not reached that early. `shadow_dump2`'s "zero
offscreen draws" has the same explanation: DUR=70 with a different NAV phase.)

**Rule: a probe harness that kills by NAME silently invalidates any A/B run under a different
exe name.** Either copy to one of the killed names, or kill by the PID the harness started.
Both are one line; the wrong one costs a night.

Fifth retraction of the day, and the second and third caught by the user rather than by me
("is there an actual arcade regression tho?", "maybe double check that"). The pattern is
consistent and worth stating plainly in the ledger: **when a measurement disagrees with a
previously working state, suspect the measurement first.** Every user report today was real;
five instrument-derived defects were not.

**Consequences:** the combined exe and the handover-fade deploy are UNBLOCKED — the thing I said
was blocking them does not exist. Still genuinely open and user-confirmed: the ranking-plaque
square shadow, the shot-SFX defect, and music stopping mid-gameplay.

---

## 2026-07-31 (late) — COMBINED EXE gated green; magenta-block defect NOT reproduced; 3 open user defects

**Combined exe built from the current tree (incl. the handover fade + shdump fix): BUILD_OK,
G1 PASS (gemsg=25 msg5=9 modeswap=1 crash=0 vk=0), G5 PASS.**
⚠ Note on G5: it runs WITHOUT audio armed, so every audio counter is 0 on both sides — it asserts
parity of nothing where audio is concerned. Under the "gate the blast radius" rule that is not a
sufficient audio gate for any build carrying audio changes. A real audio-parity run was done
separately (combined, ship audio config): 42 SE cue dispatches, 4 SYS_SE, 18 bridge events.

**MAGENTA-BLOCK GFX DEFECT (user screenshot, demo play): NOT REPRODUCED, and NOT combined-specific.**
Quantitative sweep (new `scratchpad/xmag.ps1` — magenta fraction of the centre panel, so the call
is a number rather than an eyeballed downscale) across a full attract cycle, 16 samples each,
t=40..145 s:
| build | profile |
|---|---|
| per-mode v154hi | 0% mostly; 3.5% at t=68-89 |
| combined | 0% mostly; 3.5% at t=75-89 |
The 3.5% peaks are the TITLE-LOGO screen, where the `虫姫さま` art is legitimately magenta —
verified by opening the frame, not by trusting the metric. **The two builds' profiles are
essentially identical**, so nothing points at the single-exe merge. The user's corruption is
therefore intermittent/frame-local — which a 7-second sampling interval will miss almost every
time. Next attempt needs continuous capture or a much tighter interval during demo play.

### The three OPEN, USER-CONFIRMED defects (all reproduced by the user, none by me yet)
1. **Shot SFX wrong** — present on BOTH per-mode and combined builds (user A/B'd the combined
   probe: "nah still not right"), so it is in the shared audio path, not the merge. Established:
   gameplay SE DOES go through the cue bridge (dozens of dispatches; `SE` bank maps identity
   70/70, so not a mapping error). Most-fired cues during play: **cue15 `se16a` (20x), cue16
   `se17a` (16x)** — the shot candidates. Next: decode those two waves offline and compare
   against how the voice mixer plays them (rate, loop flags, 8-voice stealing).
2. **Music stops mid-gameplay** — both modes. NOT reproduced yet (my training drive never
   dispatched a stage BGM cue). ⚠ Live landmine found meanwhile: **10 of 13 BGM cues are NOT
   identity-mapped** (`m03_boss`→wave 11, `m04_cler`→wave 2, ...) while `rt_xsb_cue` defaults
   `waveIndex = cueIndex` before consulting the bank — any identity fallback plays the wrong
   track or none. Prime suspect.
3. **Ranking-plaque square shadow** — still present (user marked the rectangular edge). Author
   class confirmed via `RVK_MODOFF=05000500`; 56x120 tiles that darken uniformly instead of
   taking shape from the sampled sprite.

**User's deployed build remains the reverted known-good pair (17:07, md5-verified) with the
RT_CATVOL=0 pin. Nothing new has been deployed.**

---

## 2026-07-31 (night) — DECOMP PREP FOR 08-01: two fields the bridge throws away

User: "lets give us the best chance of success tomorrow, decomp". Offline .xsb work only — no
guesswork, no deploys. Tools: `scratchpad/xsb_sound_fields.py`, `scratchpad/xsb_event_decode.py`,
`/c/tmp/xsbdump.exe` (built from `rt_xwma.cpp -DRT_XWMA_MAIN`).

### FINDING 1 — per-sound VOLUME is real, varies a lot, and we discard it
The sound record is `{u8 flags; u16 category; u8 volume; u16 pitch; u16 ?; u8 size; ...}`. The
parser reads `category` and the wave ref and **skips volume and pitch entirely** — every cue plays
at flat gain. Measured across the shipped banks:
| bank | distinct volume bytes | pitch |
|---|---|---|
| SE | **21 values, 160..243** (`se01a`=235, `se16a`=192, `se17a`=180) | all 0 |
| BGM | 165 / 170 / 180 | all 0 |
| SYS_SE | 135 (uniform) | all 0 |
| SYS_BGM | 151 | 0 |
Pitch is 0 everywhere, so pitch is NOT a suspect. Volume is: the two shot candidates differ from
each other (192 vs 180) and we flatten both.
⚠ **Do NOT reverse the byte→dB encoding by guessing** — that is the exact error class that cost
today. `rexglue-sdk` has no XACT bank parsing, so it is not an answer key. **Mirror the guest's
COMPUTED gain instead**, the same technique that solved the handover fade (follow
`sub_821CA078`'s value rather than reimplementing the ramp). Tomorrow's decomp target: the shell
XACT function that turns a sound record's volume byte into a voice gain.

### FINDING 2 — the record-shape split IS the loop flag (implemented, DEFAULT OFF)
`flags=0x00 size=12` = one-shot; `flags=0x01 size=36` = event sound whose trailing PlayWave carries
XACT's `0xFF` infinite-loop marker. Evidence from the shipped data rather than the spec:
**`m05_govr` (game over) is the ONLY size-12 cue in BGM.xsb** — the one stage track that must not
loop — and the L-named SE (`se09La`, `se19Lb`, `se25Lb`) are all size-36. Our voice mixer has
never looped anything (`v.active=false` at end of sample), so every looping SE plays once.
Implemented: `RtXsbCue::loopInfinite` parsed in `rt_xwma.cpp`, plumbed through `rt_xw_start` into
`RtXwVoice::loop`, wrap-around in `rt_xw_mix`. **Lever `RT_SELOOP`, DEFAULT OFF** — it changes
audible behaviour and has not been heard by the user, and the 07-31 rule is that an audio change
ships only on a gate that covers real gameplay SFX. Tomorrow: set `RT_SELOOP=1` with the user
listening. ⚠ `RtXsbCue` is declared TWICE (rt_xwma.cpp + rt_audio.cpp); they must be kept in step.

**Both arms rebuilt and boot-smoked with the lever off, each against its OWN NAV recipe:**
ARCADE `futari_merged.exe` + `START,Ax2` → gemsg=26 (control 26); 360 `futari_merged_v154hi.exe`
+ `START,A,LEFT,A` → gemsg=26 (control 27). crash=0 both.
⚠ Note for the next session: a v154hi run under the ARCADE `Ax2` NAV reads gemsg=0. That is a NAV
mismatch, NOT a regression — **each arm has its own NAV recipe; never cross them in an A/B.**
**USER CORRECTION (07-31 night): ARCADE needs no LEFT — `START, A, A` gets you in.** So
`START,Ax2@2500` (the ARCADE recipe above) is right, and the `START,A,LEFT,A` form is the 360/
mode-select route. The LEFT is only there to move the mode selector off the default entry.

---

## 2026-07-31 (night) — SHADOW: root-cause hypothesis sharpened to ONE testable claim

### Instrument fix #2 tonight: `[shdump]` never printed the UVs
The stride-16 vertex layout is **`{x, y, u, v}`**. `decodeVert()` moves dwords 2,3 into the uv
slots and **synthesises `dd[3]=0xFFFFFFFF`** — so the old per-vertex line's `col=%08X` printed that
hardcoded white on every vertex, never any real data, while the texture coordinates were never
shown at all. Now prints `uv={u,v}` and labels the colour `synthcol`. (Second time tonight the
dump itself was the thing lying — cf. the `vte` transform.)

### What the UVs revealed
| draw class | vs/ps | vte | UV convention | renders |
|---|---|---|---|---|
| shell UI | 17/16 | 0x43F | **normalized** 0..1 | correct |
| ROM main sprites, `blend=07060706` (α-blend) | **45/50** | 0x400 | **TEXEL** (0..32) | **correct** |
| ROM shadow, `blend=05000500` (dst*=1−src) | **45/50** | 0x400 | **TEXEL** (200..256 of the 512² atlas, 1:1 with the 56×120 quad) | **SQUARE** |

**So texel-vs-normalized is NOT the bug** — the working sprite class uses the identical shader
pair, viewport mode and UV convention, and our renderer handles it fine. Geometry, shader and
sampling are all shared. **The ONLY difference between the working class and the broken one is
the blend mode.**

### The one hypothesis left, and how to kill it in one test
`05000500` = src ZERO / dst ONE_MINUS_SRC_COLOR, i.e. `dst *= (1 − src.rgb)`. Under the ordinary
α-blend (`07060706` = SRC_ALPHA / ONE_MINUS_SRC_ALPHA) a texel with **A=0 contributes nothing no
matter what its RGB holds**. Under a COLOUR-modulate blend the RGB matters *even where A=0*.
⇒ **If our decoded texels carry non-zero RGB in the sprite's transparent region, the whole quad
darkens uniformly — a square shadow — while every other draw using the same texture still looks
perfect.** That single asymmetry explains why exactly one blend class is broken.

**TOMORROW'S DECISIVE TEST (no guessing):** dump decoded texels of `tex=0x134E8000` over
`u=[200,256], v=[0,120]` and check whether RGB is zero wherever A is zero. If RGB is non-zero
there, the fix is to premultiply (or zero RGB where A=0) for this blend class — behind a lever,
gated on a screenshot A/B of the ranking plaques against
`evidence_shadow/ref_v136_ranking_2nd3rd_noshadow.png`, plus a no-collateral check that ordinary
sprites and gameplay are untouched. If RGB IS zero there, this hypothesis is dead and the next
suspect is our blend-factor mapping for factor 5.
Blend enum confirmed against the working class: 6=SRC_ALPHA, 7=ONE_MINUS_SRC_ALPHA (so
`07060706` = standard α-blend, consistent), 0=ZERO, 5=ONE_MINUS_SRC_COLOR.

---

## 2026-08-01 — SHADOW LEG: the decisive test ran. Hypothesis REFUTED; the colour path is CLEAN

Single-threaded except one read-only decomp agent. Ran the test the previous entry specified, and
it answered — negatively, which is the useful direction.

### 0. Two banked "facts" were stale — the instrument had to be rebuilt to not depend on them
`tex=0x134E8000`, `512x512 atlas`, `56x120 quad` are all wrong for the current build. A first cut
of the dump keyed on that hardcoded base and returned **zero hits**: guest texture bases are
per-boot wall-clock allocations, so an address banked in this ledger is never an invariant (same
landmine as the menu-flash leg). Re-keyed on the **draw class**, which is invariant. Truth:

| banked | actual (measured this session) |
|---|---|
| tex 0x134E8000 | **tb=0x0EDD9000**, per-boot |
| 512x512 atlas | **256x256**, fmt 3 (k_1_5_5_5), tiled, fpitch 256 |
| one 56x120 quad | **prim=8 RECTLIST, n=6 = TWO 56x120 rects**, UV bbox `[144,0..256,120]` |

=> **RULE (again): never key an instrument on a guest address from the ledger. Key on the class.**
`RVK_SHTEXAUTO=1` now finds the class by RB_BLENDCONTROL (`RVK_SHTEXBLEND`, default 05000500),
takes the UV bbox from the draw's own vertices, and arms the texel analyser for that base. It also
prints a one-line census — the difference between "the texels are clean" and "the class never drew
in this run", two results the address-keyed cut could not tell apart.

### 1. THE DECISIVE TEST — premultiply hypothesis is DEAD
`RVK_TEXRECT` / `RVK_SHTEXAUTO`, decoded texels over the class's own UV rect:

    [shtex] DECISIVE n=13440 rawA0=2400 rawA0_rgbNONZERO=0 (0.00%) rawA0_maxRGB=0
            rawAnz=11040 rawAnz_rgbZero=1807 | decodedA0=2400
    [shtex] blend impact over rawA0 texels: mean dst multiplier (1 - meanRGB/255) = 1.0000

**RGB is exactly zero in 2400/2400 raw-alpha-zero texels.** The transparent region contributes a
dst multiplier of exactly 1.0 — it cannot darken anything. No premultiply is needed and none would
change a pixel. Raw-value histogram over the rect: `0xE312 x8118` (khaki silhouette), `0x0000
x2400` (transparent), `0x8000 x1807` (**opaque black**), 74 others. The art is a khaki silhouette
on black — authored *exactly* for `dst *= (1-src.rgb)`, where black is a no-op and the silhouette
darkens. **The asset is correct.**

WARNING - TRAP THE INSTRUMENT WAS BUILT TO AVOID, worth keeping: `realAlpha` (RVK_REALALPHA)
decides the decode, and with it OFF fmt-3 decodes `A = (px&0x8000) ? 255 : max(R,G,B)` — so "is RGB
zero where A is zero" is a **tautology** on the decoded buffer and always answers yes. The dump
reads the **raw stored alpha bit** and reports it in a separate column. (The ship config does set
RVK_REALALPHA=1, but the dump must not depend on that.)

### 2. The rest of the colour path, verified end to end — all of it correct
- **ps50** (byte-exact guest microcode, `render/tools/xrgen/rom_ps50.hlsl:88-91`):
  `oC0.xyz = texel.rgb * c14.rgb ; oC0.w = texel.a * c15.x + c15.y`. **No alpha->colour path
  exists** — the shadow's shape can only come from texel RGB, and it does.
- CORRECTION: **ps50 never reads c2.** The `c2={0.9,0.9,0.9}` in the previous entry came from a
  census line that printed `g_psConstF[8..10]` unconditionally. It is noise. The constants that
  matter are **c14 (idx56) and c15 (idx60)** — consistent with the leg-7 SCOPE RULE.
- Measured live on the class: `c14={0.3765}` flat on the ranking screen, `c15.x` **ramps 0.0314 ->
  0.1255 -> 1.0000** (the plaque fade-in). Elsewhere `c14=1.7569` (saturates the silhouette to
  black — that is the old "big dark bands" phase) and `c14=0.5020, c15.x=0.0039` in demo play.
- **Blend-factor mapping for factor 5 is CORRECT** (`xenosBlendFactor` case 5 ->
  `ONE_MINUS_SRC_COLOR`, vk_render.cpp:1916). The previous entry's named fallback suspect is
  therefore also cleared, without a build.
- **Alpha test is armed and correct for this class**: `colorCtl=0x8700000C` (en=1 func=4 GREATER)
  ref=0 -> athresh=0.00195. `src.a = 0.0314..1.0` passes; only the fully-transparent margin is
  discarded. It is not eating the shadow.
- **ISOLATE (`RVK_SHTEXISO=1`, replace blend) — the strongest single result.** Painting the raw
  shader output shows a correct **plaque-shaped silhouette** in the dominant colour **(75,75,56)**
  against predicted `khaki(195,195,148) x c14(0.3765) = (73,73,56)`. **Sampling, UVs, texel->uv
  scaling (guest vs45 bakes c255.y=1/256 and the atlas IS 256 wide), geometry and constants are
  all correct.** Nothing in the colour path is broken.

### 3. The alpha asymmetry — found, tested, REFUTED
The one structural difference left between this class and the working sprite class:

    SHADOW  0x05000500  colour src=ZERO      dst=ONE_MINUS_SRC_COLOR
                        alpha  src=ZERO      dst=ONE_MINUS_SRC_COLOR  => dst.a *= (1-src.a)
    WORKING 0x07060706  colour src=SRC_ALPHA dst=ONE_MINUS_SRC_ALPHA
                        alpha  src=SRC_ALPHA dst=ONE_MINUS_SRC_ALPHA  => dst.a = src.a^2 + dst.a(1-src.a)

The shadow class **only ever reduces** destination alpha, never restores it, and it does so across
the opaque-black surround — a **rectangle** where its colour contribution is exactly zero. With
`c15.x` reaching **1.0** on the ranking screen, `dst.a *= (1-1.0) = 0`: destination alpha is zeroed
across a rectangle in a single frame. That is a textbook "transparent box" mechanism and it
matches the user's words ("the shadow's not showing up, instead we're getting the transparent
box") exactly.

**It is still wrong.** `RVK_SHTEXISO=2` (keep the guest blend, colorMask 0x7 = RGB only, do not
touch destination alpha) vs an otherwise-identical control at the user's own
`RVK_WINSIZE=1920x1080`: **two ranking frames came back BIT-IDENTICAL** (cap_003, cap_005; 5 of 25
frames are bit-identical overall — the scripted attract is frame-deterministic across boots, which
is a genuinely useful property for this harness). Nothing downstream consumes this target's alpha.
=> **Destination-alpha writes are NOT the defect. Do not spend another leg on colorMask.**

### 4. Harness notes banked
- **`RVK_WINSIZE=1920x1080` must be pinned in any shadow repro.** `shadowprobe.sh` does not set
  it; the user's launcher does. At the default ~1280x720 the 640x512 panel is downscaled enough to
  smooth a thin bounding-box edge away — the same config gap the 07-31 "not reproducible" call
  fell into. At 1080p the captures are 1936x1119, **the exact size of
  `evidence_shadow/ref_v136_ranking_2nd3rd_noshadow.png`**, so port-vs-reference is a direct diff.
- **Cross-boot frame diffing is only valid on phase-matched frames.** A naive same-index diff
  reports ~110 mean abs error that is pure scroll phase. Align on an anchor region the lever
  cannot touch first (`scratchpad/shadow_ab.py`), or use the bit-identical frames.
- The attract cycle needs **START, A, A** (user correction) — a run with no NAV never enters
  attract and the class never draws.
- The box IS reproduced in-harness at 1080p: it sits around the plaque that is **mid-fade**,
  which is consistent with `c15.x` ramping.

### Levers added (all default-off, unset => byte-identical)
`RVK_TEXRECT=<hexbase>,x0,y0,x1,y1` (explicit texel-rect analyser, raw-alpha aware, PNG crops +
shape map + raw-value histogram) · `RVK_SHTEXAUTO=1` (find the class, arm the analyser from its own
UVs, census) · `RVK_SHTEXBLEND=<hex>` (which class; default 05000500) · `RVK_SHTEXISO=1` (replace
blend = show the raw shader output) · `RVK_SHTEXISO=2` (colorMask 0x7 = no destination-alpha write).

### 5. ADDENDUM — the clean A/B arm, and what it says so far
`RVK_MODOFF=05000500` **drops** the draw, which changes the draw count and perturbs frame pacing:
its diff against a control came back contaminated by scroll phase (mean 22-125 over the panel,
i.e. whole-scene). Added **`RVK_SHTEXISO=3` = colorMask 0** — the draw, the batch and the timing
are untouched and it simply writes no channels. That keeps the two arms frame-locked (`draw#1` at
`f2513` in BOTH arms) so the diff is the class's exact screen contribution, pixel-for-pixel.

On every **phase-matched** frame obtained so far the class's contribution is correctly **SHAPED,
never a rectangle**:
- `cap_014/015` (vs MODOFF): the entire contribution is the **"PRESS START BUTTON" text drop
  shadow** — 435x27, correctly glyph-shaped.
- `cap_005` (vs ISO=3): an 88x80 **round bullet-shadow blob** in demo play, fill 0.486.

Combined with §2 (the shader output is a correct silhouette) and §3 (alpha is inert), **this class
cannot paint a rectangle**: under `dst *= (1-src.rgb)` its opaque-black surround is an exact
no-op in colour, and its only other output channel is proven to be consumed by nothing.
⇒ **The banked attribution "RVK_MODOFF=05000500 removes the box" is now DOUBTFUL and must be
re-derived before another leg is spent inside this class.** The 07-31 MODOFF A/B was almost
certainly reading scroll phase, the same contamination measured directly above.

### ⏭ THE ONE THING STILL MISSING, and the recipe for it
No phase-matched capture yet lands on the **ranking-plaque** screen (the plaque list scrolls
continuously, so wall-clock `PrintWindow` never hits the same frame twice — max plaque-green
fraction across all 5 phase-matched frames was 0.059). That is a HARNESS limit, not a result.

**Fix the harness first next session: capture by FRAME NUMBER in-engine, not by wall clock.**
`shadowprobe.sh` shoots PrintWindow on a wall-clock ladder; the renderer can dump PNGs at named
frames instead (RT_NVKPNG family). With both arms dumping at the same frame indices the A/B is
exact on ANY screen, including the scrolling plaque list, and this leg closes in one run:
`RVK_SHTEXISO=3` vs control, diff at a plaque frame. Shaped ⇒ the class is innocent and the box's
author is elsewhere (next suspects: the plaque sprite class itself, or the panel compose — note
the box tracks the plaque that is MID-FADE). Rectangle ⇒ the divergence is downstream of the
fragment shader, and the live candidate there is RT precision: our nvk target is **RGBA16F
(VkFormat 97)** resolving to A2B10 (64), and with `c14=1.7569` the guest's `1-src.rgb` goes
**negative** (-0.34), which a Xenos 7e3 target clamps at 0 and a float target does not.

### 6. RENDERDOC — and it settles §3 properly, plus one correction to §4

**★ HARNESS UNLOCK: RenderDoc analysis is FULLY SCRIPTABLE HEADLESSLY.** `renderdoccmd` has no
python subcommand, but **`qrenderdoc.exe --python <script.py>`** does, with the whole replay API
including `PixelHistory`, `GetPipelineState`, `SaveTexture`. An earlier note in this leg said
analysis was attended-only — **that was wrong.** Caveat: `--python` does NOT forward extra argv to
the script (qrenderdoc parses them as its own `filename`), so hardcode paths.
Capture is unattended too: `RVK_RDCCAP=1` resolves the in-app API from renderdoc.dll and
self-triggers on the class drawing with `c15.x >= 0.9`. Both arms fired at the SAME fade value
(0.9098), so captures compare exactly with no frame alignment at all.
Scripts: `_tmpscripts/rdc/*.py`. Captures: `C:/tmp/rdc_shadow/`.

**Frame anatomy (rdc_rank_frame2530, the 4th/5th plaque page at 1920x1080):**
- 106 drawcalls. ROM target = **`ResourceId::6365`, 640x512, R8G8B8A8_UNORM.**
  ⇒ ★ **the RGBA16F negative-value lead from §5 is DEAD** — this target is UNORM and clamps.
  (The RGBA16F/fmt97 surface is the 320x240 ring, a different surface entirely.)
- **Exactly TWO modulate draws in the whole frame** (EID 284, 288), writeMask 15. Everything else
  is SrcAlpha/InvSrcAlpha (86 draws) or SrcAlpha/One (15).

**PIXEL HISTORY names what the modulate draw does, exactly (EID 288, in-band pixel):**

    pre=(0.000,0.482,0.584, a=1.000)  shaderOut=(0.292,0.292,0.219, a=0.784)
    post=(0.000,0.341,0.455, a=0.216)

- Colour: `0.482 x (1-0.292) = 0.341` ✓ — the shaped shadow, working exactly as designed.
- Alpha: `1.000 x (1-0.784) = 0.216` — **destination alpha smashed across the quad's rectangle.**
Rendering the target's alpha channel as an image shows those hard rectangular blocks plainly,
while the RGB channel has none. So the alpha destruction of §3 is REAL and now directly observed.

**But §3's verdict stands: it is INERT.** Proven properly this time, with the self-triggered
capture pair (control writeMask 15 vs `RVK_SHTEXISO=2` writeMask 7, both at c15.x=0.9098):
- render target **RGB bit-identical** (max channel delta 0 on R, G and B),
- alpha differs on 119232 px, floor rises 19 -> 167 (the rectangles are gone),
- **presented images produce IDENTICAL coherent-edge lists, value for value.**
⇒ Nothing downstream consumes this target's alpha. ⚠ Note the earlier §3 evidence was INVALID even
though its conclusion was right: the "two bit-identical ranking frames" were cap_003/cap_005, and
cap_005 later turned out to be a demo frame with bullets — the orange-banner detector misfired.
**Right answer, wrong evidence. The capture pair is the evidence that actually holds.**

**★ THE BANDS ARE A REAL DEFECT — first hard confirmation against the reference.**
Same coherent-edge metric over the panel: **port = 33 coherent horizontal edges** including matched
enter/exit pairs (`-8 @378 / +9 @488`, `-14 @777 / +6 @896`); **v1.3.6 reference = 6**, with no
matched pairs at all. Different page and scroll phase, so this is structural not pixel — but 5.5x
the straight-edge count with pairing only on our side is not scene content.

**★ AND THE SHADOW CLASS IS EXONERATED.** Straddling the band edge (pixels a few texels either
side, at rows chosen programmatically to be clean background on BOTH sides — the first attempt
used hand-picked rows that landed on plaque art and gold border, which is why its set-difference
was meaningless): at every clean row the **same draw set covers both sides**, inside-only and
outside-only both empty, yet the final colours differ (e.g. y=47: inside (0.043,0.165,0.188) vs
outside (0.251,0.349,0.345), identical alpha 0.824). **The edge is not a draw-presence boundary.**
The same draws produce different colour across it ⇒ the divergence is in what those draws SAMPLED,
not in which draws ran, and not in the modulate class (only 2 such draws exist in the frame).

### ⏭ NEXT LEG — the background TILE GRID, not the shadow
The band edges in the 640x512 target are VERTICAL (it is transverse) at x = 82, 156, 176, 264,
354, 428 — a near-regular ~88-90px pitch. The draws painting those regions are the opaque
background layer (EIDs 219/227/251/255/267/271/275 in this capture — SrcAlpha/InvSrcAlpha, each
covering a different x-range, i.e. spatially tiled). That matches the ledger's own leg-12 note: the
**panel-BACKGROUND tile grid** (guest `FUN_880FFCE8` / `FUN_881538C0` id 0x170, 32-px steps from
x=0,y=0, one vs45/ps50 prim=8 batch of 480 int32 {x,y,u,v} records = 80 tiles x 2 sprites).
⇒ **Hunt the tile grid's UV/sampling, not the shadow class.** Concretely: for two adjacent
background-tile draws either side of x=156, dump their vertex {x,y,u,v} records and bound texture
and check whether adjacent tiles sample contiguous UVs. A UV or half-texel discontinuity at the
tile seam produces exactly this: straight full-height edges on a regular pitch that the reference
does not have. The capture already on disk answers it — no new run needed.

### 7. TILE-GRID UV CHECK — the §6 "next leg" hypothesis is DEAD (killed before anything was built)

`RVK_SHADOWDUMP=60 RVK_SHADOWDUMPST=16` on a ranking frame (f2520). Panel background = **20 draws
of 32x256 tiles in TWO rows**, all vs45/ps50, blend 07060706, vte=400, into vp={0,0,640,512}:

    row A  y = -22..234    row B  y = 218..474      (each exactly 256 tall)
    columns at x = 0,32,64,...,288  (10 columns, guest coords 0..320)

Tiles bind DIFFERENT texture pages per column and the assignment differs per row
(0xF0D9000 / 0xF0F9000 / 0xF119000) — a streamed/scrolling background.

**★ THE UVs ARE CONTIGUOUS AND CORRECT — no seam discontinuity exists.**

    row A: x=288..320 -> u=224..256 ;  x=0..32 -> u=192..224
           nine 32-texel steps down from 224 wraps to 192 exactly ✓
    row B: x=288..320 -> u=160..192 ;  x=0..32 -> u=128..160   (same, wraps to 128) ✓

Each 32-px column maps to exactly 32 texels of u, wrapping mod 256. So §6's proposed next leg
("check tile UV contiguity, a half-texel discontinuity would give the bands") is **REFUTED by
measurement before any code was written.** Two rows carry different u offsets (224 vs 160 at the
same x) — that is a parallax/scroll layer difference, not an error.

Also banked from the same frame:
- The two rows **OVERLAP by 16px** (row A ends 234, row B starts 218). Real, and worth a look, but
  it cannot author a **74px** band.
- The shadow class is d25 (112x240) + d26 (112x120), tex 0xEDD9000 — matches the RenderDoc census
  (2 modulate draws) and the §0 UV rect.
- A THIRD blend class is present and was not in any earlier census: **0x01060106** (src SRC_ALPHA /
  dst ONE = additive) — d27, d34-d38, d43. d43 is 112x120 on the SAME texture as the shadow.

### ⚠ OPEN CONTRADICTION — resolve this FIRST next session, do not build on either reading
Band edges measured in the saved 640x512 RT are at **x = 82,156 and 354,428** (width 74). But
**every draw in the frame has guest x < 320** (tiles 0..320, plaques -14..250). So:
- either `scr[raw]` guest coords are NOT 1:1 with RT texels (a 2x viewport scale 320->640 would
  put tile columns on a 64px pitch, which is near but not equal to the measured 74), or
- the saved RT's right half is stale content the frame never drew into.
Until that coordinate space is pinned, **any attribution of the bands to a specific draw is
guesswork.** Pin it the cheap way: in the banked capture, `SaveTexture` the RT immediately before
and immediately after ONE known tile draw (e.g. EID for the x=288..320 tile) and diff — the
changed rectangle gives the exact guest->RT mapping, from ground truth, in one script run.

### 8. ★★★★★★ THE BOX'S AUTHOR IS NAMED — and it is NOT the shadow class

All offline off the banked capture, no new game run. Three results, in order.

**(a) The coordinate contradiction of §7 is RESOLVED: `scr[raw]` is a 2x scale.** Replaying draw by
draw and reading the ROM target after each, every 32-px guest background tile changes exactly
**64 RT texels** (x 576..638, 512..574, 448..510, ... 0..62). So guest 0..320 -> RT 0..640.
`scr[raw]` guest coords are NOT 1:1 with RT texels. The saved RT is not stale.

**(b) The shadow class is EXONERATED — properly this time, by before/after, not by the flawed
straddle logic of §6.** Coherent VERTICAL edges in the RT at three stages:

    BEFORE the modulate draws (EID 279): [204, 264, 274]          <- no band edges
    AFTER  both modulate draws (EID 288): [10, 204, 264, 274]     <- still none
    END of frame            (EID 1133): [32, 82, 156, 162, 176, 212, 264, 274, 308, 354, 428]

The band edges 82/156/354/428 do not exist until well after EID 288.
⚠ **§6's exoneration reached the right answer by invalid reasoning and must not be cited.** The
straddle test assumed the author must be ABSENT on one side of the edge. That is false for a
textured draw that covers both sides and merely samples different texels across it — and the
modulate draws' footprints (EID 288 x 0..188, EID 284 x 270..460) do bracket both bands. The
before/after replay is the evidence that actually holds.

**(c) THE AUTHORS, by direct per-draw bisect** (luminance step across each band-edge column,
measured after every draw):

    edge @428  <- EID 298  (+27)   SrcAlpha/InvSrcAlpha
    edge @354  <- EID 348  (-22)   SrcAlpha/InvSrcAlpha
    edge @156  <- EID 370  (+21)   SrcAlpha/InvSrcAlpha
    edge @82   <- EID 420  (-16)   SrcAlpha/InvSrcAlpha

Ordinary alpha-blend sprites, and **perfectly mirrored between the two plaque groups**: each plaque
is drawn by an identical 16-draw sequence (293..360 and 365..432, matching pixel counts draw for
draw); 298 and 370 are both the 2nd of their group (npx 23764 each), 348 and 420 both the 14th.
Changed extents: EID 298 x=368..476 y=144..452, EID 370 x=96..204 y=170..478 (identical size,
mirrored); EID 348 x=314..372, EID 420 x=42..100. In guest units ~54x154 and ~29x130, texture
class **0xEE19000** (the plaque-component sprites, cf. f2520 d28/d40).

⇒ **Each band is the LEFT and RIGHT bounding-box edge of a plaque-component sprite becoming
visible.** That is the user's "transparent box" — a sprite quad showing its own rectangle.

### ⏭ NEXT — one step, and the tooling already exists
Run the §0 texel analyser at the texture these draws bind (**0xEE19000 class**, not 0xEDD9000):
`RVK_SHTEXAUTO` keys on blend, so for this class either add a tex-base arm or use
`RVK_TEXRECT=<base>,x0,y0,x1,y1` with the base read from the [shdump] line. The question is the
same one that cleared the shadow's atlas: **over these sprites' UV rect, is RGB zero wherever the
raw alpha bit is clear, and does the alpha-test threshold actually kill the margin?** Under
SrcAlpha/InvSrcAlpha a margin texel with small-but-nonzero alpha tints the whole quad — which is
exactly a faint rectangle with hard edges. Note athresh for this class is only **0.00195**
(func=4 GREATER, ref=0), so almost nothing is discarded.
⚠ Do NOT re-open the modulate/shadow class: (b) rules it out by direct measurement.

### 9. ⚠⚠ RETRACTION — "the bands are a real defect (33 vs 6)" was a CAPTURE-PATH ARTIFACT

§6 claimed the bands were confirmed a defect because the port showed **33** coherent panel edges
against the v1.3.6 reference's **6**. That comparison was invalid: the port figure came from a raw
1920x1080 RenderDoc backbuffer thumbnail, the reference figure from a **window screenshot** of the
SDK. The screenshot path is softer, so it detects fewer edges regardless of content.

**Like-for-like — both PrintWindow-class screenshots, 1936x1119, identical thresholds:**

    PORT (hd_ctrl cap_011)                8 coherent edges
    REF  (v1.3.6 ranking 2nd/3rd)         6 coherent edges
    (the same port frame via raw backbuffer: 33 — the artifact)

8 vs 6 is not a defect signal. **The claim is withdrawn.** Everything §8 built on top of it — the
per-draw bisect naming EID 298/348/370/420 — correctly identifies *which draws create those
luminance steps*, but those steps are most likely the plaque sprites' own legitimate edges, present
in the reference too. §8's EIDs are therefore NOT established as a defect's author.

**And the texture those four draws sample is clean.** `ResourceId::11824`, 256x256 RGBA8:
**binary alpha only** (30887 texels at a=0, 34649 at a=255, no other value), and **RGB is exactly
zero in all 30887 transparent texels**. No low-alpha margin, so the "margin tint under
SrcAlpha/InvSrcAlpha" mechanism proposed at the end of §8 is dead as well. These are well-formed
sprites.

### WHERE THE LEG HONESTLY STANDS
Everything measured tonight is a **negative**, and the negatives are solid:
- premultiply: refuted (RGB zero in 2400/2400 transparent texels)
- shadow colour path: verified correct end to end, incl. an isolate painting the predicted (75,75,56)
- blend factor 5 mapping: correct
- shadow's destination-alpha write: real, directly observed, and **inert** (capture pair, RT RGB
  bit-identical, presented images identical)
- shadow class as the box's author: ruled out by before/after replay
- background tile UVs: contiguous
- plaque-component texture: clean binary alpha, zero RGB in the transparent region
- **the port-vs-reference edge signal: withdrawn (capture-path artifact)**

⇒ **I cannot presently demonstrate the defect with an instrument.** The user reports it
consistently and this project's record is that every user-reported defect has been real while
instrument-derived ones have repeatedly been retracted (this is the THIRD artifact tonight, after
the address-keyed dump returning zero hits and the cap_005 "bit-identical ranking frame" that was
actually a demo frame). Treat the user's eyes as ground truth, not my metrics.

### ⏭ THE UNBLOCK — turn the user's eyes into coordinates
`C:/tmp/rdc_shadow/thumb_2530.png` is the **exact frame** (4th/5th plaque page, native 1920x1080)
that the fully-working RenderDoc bisect machinery is pointed at. **Ask the user to mark the box on
that image.** Their marked rectangle converts directly into RT columns, and
`_tmpscripts/rdc/rdc_bisect.py` then names the authoring draw in ONE offline run — that pipeline is
proven (it resolved edge authorship to four exact EIDs tonight).
Without that, any further instrument hunt risks a fourth artifact.
⚠ Do NOT re-open: the shadow/modulate class (ruled out by before/after), the tile UVs, the
premultiply idea, or colorMask — all four are closed by direct measurement.

### 10. ★★★★★★ USER VERDICT ON THE CAPTURED FRAME: **CLEAN** — and that is the answer

User, shown `thumb_2530.png` with a coordinate grid: *"no box, this screenshot is clean, rendering
the shadow correctly. this is how it should look."*

**This is not a failed reproduction — it CONFIRMS a prediction already banked on 07-31 and then
overlooked for this entire session:**

> "Free A/B for the plaque shadows: view ranking fresh-from-boot (heap low) — clean there =
>  corruption confirmed."

Every capture and every A/B tonight was a **scripted attract run from a cold boot = HEAP LOW**,
which is exactly the condition that entry predicted would be clean. The user's own sessions that
show the box are real play reaching stage 4, i.e. **HEAP HIGH**.

⇒ **The whole night's negatives cohere: the rendering path is CORRECT, and I was measuring the
healthy state.** Premultiply, the shadow colour path, factor-5 mapping, the alpha write, the tile
UVs, the plaque-component texture — all genuinely clean, because in this state they ARE clean.
⇒ **The box is STATE-DEPENDENT: the allocator / 512MB-alias corruption class, not a rendering-logic
bug.** Consistent with (a) the 07-31 "not reproducible" call from the same scripted-attract method,
(b) the symptom SHRINKING to "subtle ranking-plaque edge ghosting" immediately after the layered
allocator fix rather than vanishing, and (c) the original 11:52 evidence PNG predating that fix.

### ⏭ THE REPRO CONDITION IS THE MISSING VARIABLE — and the tooling already fits it
Do NOT hunt this from attract. Reproduce with a HIGH heap, and let the capture fire itself:
**`_tmpscripts/playtest_rdc.cmd` + `RVK_RDCCAP=1`** — the user plays a normal session (stage 4),
and `TriggerMultiFrameCapture` self-fires the moment the ranking screen's modulate class draws at
full fade. No F12 timing, no scripted NAV. Then `_tmpscripts/rdc/rdc_bisect.py` names the authoring
draw offline in one run against a KNOWN-CLEAN baseline — `rdc_rank_frame2530.rdc`, which the user
has now certified correct. **That baseline is the single most valuable artifact from this session:
a user-verified-good capture of the exact screen, to diff a bad one against.**
Cross-check while doing it: `[pool]` LINE-BREACH telemetry and heap high-water in the same log.

## 2026-08-01 (second session) SHADOW LEG cont. — HEAP-HEIGHT HYPOTHESIS TESTED AND REFUTED

### 11. RT_HEAPPAD experiment: high-heap regime alone does NOT author the box
New lever `RT_HEAPPAD=<MB>` + `RT_HEAPPAD_MS=<ms>` (both harness.cpp copies, default off): one-shot
bump of the heap pointer, delayed so boot-era allocation addresses stay untouched. Run
`TAG=hp256 EXTRA="RT_HEAPPAD=256 RT_HEAPPAD_MS=30000"` — pad engaged, heap pushed past the 512MB
line, the line defense recycled aggressively (EMERGENCY-REUSE on essentially every allocation =
the amplified churn/alias regime), self-capture fired at f2539 with the shadow texture shifted to
tb=0x1EDE8000 as expected. **Presented frame (hp256_frame2527..2529 + thumbs) is visually
IDENTICAL to the user-certified-clean thumb_2530.** ⇒ High heap addresses + line-defense
recycling, in attract, do not produce the box.
★ ALSO BANKED en route: user real-play logs (C:/tmp/playtest_*.log) mostly plateau at
400-432MB — UNDER the 512MB line. The one 544MB crossing (07-31 083852) is the exception.
So "the box = 512MB aliasing" was already inconsistent with the log record: the box has appeared
in sessions that never crossed the line.

### SURVIVING MECHANISM (best fit, untested): texture content corrupted at draw time
The 08-01 "this class can only paint SHAPED, never a rectangle" exoneration was measured in the
HEALTHY state (clean atlas). With a corrupted/reused source texture the same modulate draw
(dst *= 1 - src.rgb) darkens its ENTIRE QUAD = a translucent grey rectangle = the user's box, and
the silhouette is gone = "shadow not showing up". Candidate corruption path: guest frees the atlas
page mid-session; our pool recycles+ZEROES or re-serves it after quarantine while the game still
draws from it (the documented poison class — real HW keeps freed contents until reuse). Attract
never frees those pages ⇒ scripted runs always clean, real play sometimes not. NOTE ALSO the
inverse form: c14.rgb garbage/zero (see the [shtexiso] comment block) — the play-session log's
[shtexiso] lines carry c14/c15 every 500th class draw, so a bad-constant form would show there.

### 12. THE INSTRUMENT FOR THE ATTENDED RUN — re-arming self-capture
`RVK_RDCCAP_EVERY=<sec>` re-arms the ranking-class capture trigger after a cooldown;
`RVK_RDCCAP_MAX` (default 8) bounds fires. Unset = one-shot as before. `playtest_rdc.cmd` now arms
RVK_RDCCAP=1 EVERY=60 N=3 MAX=10: the user just plays; every ranking visit self-banks 3 frames in
C:/tmp/rdc_user/. Analysis: `_tmpscripts/rdc/rdc_thumb_any.py` (tag from thumbtag.txt) extracts
presented-frame PNGs; eyeball for the box, then rdc_bisect/pixel-history the bad capture against
the certified-clean rdc_rank_frame2530.rdc. Cross-check [shtexiso] c14 + [pool]/[heap] lines in
the same log around the bad visit's wall-clock.

### 13. ★★★★★★ USER PLAY RUN DELIVERED THE DEFECT CAPTURE — BOX ANATOMY NAILED (08-01 2nd session)
User session (playtest_rdc 0802, fixed env commit 344a4fa): self-capture fired 3x; user F12'd the
box on the 1st/2nd plaque page (THEIR real stage-4 scores) = C:/tmp/rdc_user/futari_frame2055.rdc.
Same session frames 1499-1501 = 4th/5th page (default-score plaques), clean. Telemetry: shadow-
class tb MOVES between visits in real play (0x0FE29000 -> 0x1249B000; attract never moves it);
heap peak 400MB, ZERO breaches => 512MB story dead for this repro too; c14/c15 sane throughout.
- RT dump of the defect frame (boxhunt_bad_rt.png): WHITE RECTANGLES exactly filling the margins
  around/between/below the plaques. THE BOX IS OPAQUE WHITE IN THE ROM RT.
- Pixel history (rdc_boxhunt.py): inside-only authors EID 452 & 524 (SrcAlpha/InvSrcAlpha plaque-
  component sprites, tex ResourceId::8890). The modulate SHADOW draw (EID 388) RUNS AND WORKS
  (dst *= 1-src correct on both sides); the box draws come AFTER and OVERWRITE the shadowed
  region with opaque warm-white (1.004 x {1.0,0.97,0.94}, alpha=1.0). 1.004 = 2x128/255 vertex
  gain => vertex path healthy.
- rdc_uvprobe.py: the author draws' input VB AND postVS (positions+UVs) are BYTE-IDENTICAL to the
  clean frame's same-texture draws (385/457). Geometry/UV corruption REFUTED.
- rdc_boxtex2.py: tex 8890 content = gold plaque frame + Reco/Palm portrait heads + RAW MAGENTA
  key regions + large WHITE fields around the frame; binary alpha 32861/32675, 1.5% opaque-white.
  The good frame binds the SAME image.
=> **SURVIVING MECHANISM: ALPHA-DECODE SEMANTICS for this atlas class.** The white fields around
the frame art sample OPAQUE in our decode but must be TRANSPARENT on real HW (that is where the
shadow shows through; "transparent regions stored as WHITE" is this shell's documented idiom).
Wrong-alpha candidates: guest fmt mis-key (k_4_4_4_4 vs k_1_5_5_5 alpha-bit semantics), the
fmt3 legacy alpha ladder, or the magenta color-key scoping (FMT3KEY only fires for base in
[0x17000000,0x18000000) — per-boot allocs move this atlas in/out of that window = the state-
dependence WITHOUT any corruption; ALSO likely the magenta-block defect's root).
=> The clean-vs-box difference is likely THE SAVE CARD: every historical "clean" capture used
save_freshcard (default plaques); the box page renders the USER's real entries. Cold-boot
usersave attract run (TAG=usersave, RT_SAVE=save_playtest copy of the deploy save,
RVK_RDCCAP_EVERY=5) is the decisive fork: box from cold boot => deterministic unattended repro.

### 14. ★★★★★★ USER GROUND-TRUTH RESET + REGISTER-TRUTH PROBE (08-01 afternoon)
**USER (standing truth, supersedes all "clean" certifications): the glitch is UNCONDITIONAL —
every ranking screen, ARCADE and 360, any save. The REAL drop shadow is MISSING and a SHADOW BOX
appears instead.** My repeated "this capture is clean" eyeballs were wrong (incl. usersave_2977,
which the user identified as boxed). Stop hunting repro conditions; ANY ranking capture has it.
- **The old renderer is the ORACLE for this class**: the user's morning session that "appears
  fixed" ran the OLD path (pre-nvk playtest env) — that was real data, not a mistake. Old = shadow
  correct; NVK = box. The divergence is contained in our two implementations.
- **RVK_FMT16TRUE=1 global flip = CATASTROPHIC** (whole playfield shreds — most textures genuinely
  use the shipped layout). Env-only experiment, nothing landed. Do not re-try globally.
- **[tfall] register probe landed** (RVK_TFALL=1, one-shot all-6-dword fetch-constant dump per
  base, vk_render nvk draw path, default off). Verdict: the shadow atlas (this boot 0x0EC19000,
  fmt3) has an ORDINARY fetch constant — tf3 low-12 swizzle field IDENTICAL to every working
  texture, endian=1 = correct 8in16 for 16bpp (fmt6/32bpp textures are endian=2, fmt54 ring same),
  only filter bits differ (point vs linear — the known CAVE card class). ⇒ No mis-read register
  field explains the alpha; the guest data's white margins/hollow REALLY carry the fmt3 opaque
  bit (VkImage dump: a=255 there), so authentic hardware would sample them opaque too ⇒ **the
  authentic pipeline must avoid painting them some other way — the prime remaining suspects are
  the CLASS's vertex/UV decode (nvk's synthesized UV rect u=[0.2812,0.5] v=[0,0.9375] = a 56x240
  stripe through frame art + hollow + margin — plausibly NOT what the guest draw actually maps)
  and the draw/shader state our nvk path reconstructs for the vs45/ps50 SrcAlpha(07060706) draws
  on the shadow's own atlas.**
⏭ **NEXT LEG (defined, tooling exists): OLD-vs-NVK divergence bisect on the exact class.**
Capture the SAME ranking page under RenderDoc on BOTH renderers (old: RT_NVK unset — RVK_RDCCAP
lives in the nvk path, so old-arm needs renderdoccmd F12 or a capture-frame trigger added to the
old path; nvk: existing shadow_rdc.sh). Then per-draw diff at the same screen region: does the
old path even EMIT the 07060706/ps50 draws on the shadow atlas, and with what UVs/alpha? Old
path's answer is the oracle spec for the nvk fix (leg-8 lesson: the working implementation is
the answer key). Prime suspect to check FIRST in code: nvk vertex-record UV decode for this
class (texel-uv /256 convention) vs the old walker's decode of the SAME records (vk_render
~4035-4310).

### 15. OLD-vs-NVK CLASS BISECT — the ROM pass does NOT diverge (08-01, finding-only leg)

**VERDICT: on a frame-aligned ranking page, the OLD renderer (the user's oracle) and the nvk
renderer emit the SAME ROM-pass draws with the SAME geometry, the SAME textures and the SAME
per-pixel result — including the Zero/InvSrcCol drop-shadow draw, whose blend multiplier matches
to 8-bit quantisation. Every hypothesis this leg was sent to test (vertex/UV decode divergence,
fmt3 alpha-decode divergence, alpha-test/blend-state divergence, "the old path does not emit the
box draws") is REFUTED by measurement. The only old-vs-nvk differences in the whole frame are
architectural: three draws the OLD path puts in the ROM 640x512 target that nvk does not emit
there at all, and thirty-five window-target (1280x720) draws nvk emits that the old path does not.
Those two seams are where the next leg must look — NOT at the shadow class.**

#### Apparatus added (in tree, default OFF, build green)
- **`RVK_RDCCAP_ATFRAME=<N>`** (+ `RVK_RDCCAP_ATEVERY=<M>`), `render/vk_render.cpp` at the top of
  `rvkWindowPresent()` — a present-count RenderDoc trigger that works on **every** renderer path.
  The existing `RVK_RDCCAP` self-trigger lives inside the nvk draw loop (`[shtexiso]`) and can
  never fire with `RT_NVK` unset, which is exactly the arm needed as the oracle. Resolves the API
  the same way (`GetModuleHandleA("renderdoc.dll")` / `RENDERDOC_GetAPI`), reuses `RVK_RDCCAP_N`
  and `RVK_RDCCAP_MAX`, prints a present heartbeat every 500 so a mis-aimed N is diagnosable from
  the log alone. Unset => byte-identical.
- Scripts: `_tmpscripts/rdc/rdc_oldvsnvk.py` (class + per-draw postVS census, both captures),
  `rdc_rtsteps.py` (per-draw ROM-target step dump), `rdc_winsteps.py` (same for the 1280x720
  window pass), `rdc_texdiff.py` (bound-texture + alpha-histogram diff), `rdc_vtxinv.py`
  (per-rect 1:1 / page-local invariant check on postVS).

#### The captures (frame-aligned, same save, same drive, one present apart)

    TAG=oldref EXTRA="RT_NVK=0 RVK_RDCCAP_ATFRAME=1500 RVK_RDCCAP_ATEVERY=200 RVK_RDCCAP_MAX=10"
    TAG=nvkref EXTRA="RVK_RDCCAP=0 RVK_RDCCAP_ATFRAME=1500 ..."   (RT_NVK=2 from the script)

10 captures per arm at presents 1500..3300. Ranking pages at 2487/2687/2887/3087 (old) and
2488/.../3088 (nvk). **Pair used: `oldref_frame3087.rdc` vs `nvkref_frame3088.rdc`** — the settled
page, verified aligned: 60+ draws have postVS positions equal to 4 decimals. Arms verified from
the logs: oldref has **zero** `[nvk` lines; nvkref logs `RENDER MODE ACTIVE (RT_NVK=2)`.

#### 15.1 The draw streams are the same

| | OLD | NVK |
|---|---|---|
| draws into ROM 640x512 sampling a 256x256 atlas | **67** | **65** |
| SrcAlpha/InvSrcAlpha | 51 | 49 |
| SrcAlpha/One | 15 | 15 |
| **Zero/InvSrcCol (the drop shadow)** | **1** (EID 129, n=48) | **1** (EID 351, n=48) |
| draws into the 1280x720 window | **0** | **35** |

A `difflib` alignment of the two ROM-pass sequences keyed on (blend-class, vertex count, texture
rank, postVS bbox) returns **EQUAL for 61 of 67**; the six "replace" entries are four particle
sprites per plaque whose NDC positions differ by <=0.016 (= the one-frame animation offset that
also shows as the 4-px scroll difference), same UVs, same counts.

#### 15.2 The drop-shadow draw is bit-identical
Per-draw **exact** touched-pixel masks (post != pre, which is destination-independent and therefore
immune to the animated backdrop — the earlier threshold-based read was contaminated and is
retracted):

    OLD  022_eid0129_MOD  touched=147596  x[14,477] y[42,505]
    NVK  021_eid0351_MOD  touched=147592  x[14,477] y[42,505]

Recovering the blend multiplier (`dst *= 1-src`) per pixel over the 147,500 shared pixels:

    OLD mean multiplier 0.756651   NVK mean multiplier 0.756634
    mean |OLD-NVK| = 0.0054   max |OLD-NVK| = 0.0417 ( = 1/24, pure 8-bit rounding on a
                                                       marginally different destination )

**The shadow is not missing on nvk in the ROM target and is not weaker. It is the same draw
producing the same darkening.**

#### 15.3 The 1:1 / page-local invariants — both paths, same answer
Decomp lane's invariants checked on the postVS output (clip -> RT px, normalised uv -> texels):

    OLD EID 129 rect0  px(372.0,32.0)+(112.0,240.0)  tx(200.0,0.0)+(56.0,120.0)
    NVK EID 351 rect0  px(372.0,32.0)+(112.0,240.0)  tx(200.0,0.0)+(56.0,120.0)   (identical
      through rect7, and likewise for EIDs 28/270, 141/361, 208/415)

- **(b) page-local UVs HOLD on every rect of every draw on BOTH paths** (u,v and u+w,v+h all
  within [0,256]).
- **(a) 1:1 texel-to-pixel: every rect on BOTH paths is exactly 2.000x** — 112px/56texel,
  240px/120texel, 64/32, 512/256, 128/64, 320/160. Since the oracle does this too, **the 2x is
  the ROM's 320x256 -> 640x512 viewport scale, not a decode defect**: in *guest* pixel units the
  invariant holds exactly. => The earlier "nvk box draw is a ~2x-scaled 56x240-texel rect, so the
  vertex decode fabricated geometry" reading is **retracted**: the oracle emits the identical
  2x-scaled 56x120-texel rect. **There is no vertex-decode divergence.**
- Vertex ordering does differ (nvk appends each RECTLIST's synthesized 4th vertex contiguously,
  the old walker appends all of them after the n guest verts) — same geometry, different layout;
  detected from the data, not assumed.

#### 15.4 The fmt3 texture decode cannot diverge — one function, and it is measured identical
`getTexIndexReal` is called from **exactly two** sites, `vk_render.cpp:5512` (old walker) and
`vk_render.cpp:10603` (nvk) — there is no second decoder, so the 8-in-16 / k_1_5_5_5 ladder,
`RVK_REALALPHA`, `RVK_FMT3KEY` and the magenta key are shared by construction. Measured on the
bound images of the same draws:

    OLD tex 17444 / NVK tex 11735  alpha hist {255:61440, 0:4096}  identical per-row alpha0 counts
    OLD tex 17439 / NVK tex 11730  alpha hist {255:61440, 0:4096}  identical
    OLD tex 17465 / NVK tex 11906  alpha hist {255:51037, 0:14499} identical, incl. the full
                                   32-row alpha0 profile [197,67,62,65,71,74,95,...,36,0,0]

=> **No "transparent-white 0x7FFF read without the 8-in-16 swap" divergence.** Both paths see the
same bytes. (If the shipped decode is wrong about those margins, it is wrong on the oracle too.)

#### 15.5 Alpha test is armed register-true on nvk

    [nvkat] #2 f1794 vs=45 ps=50 colorCtl=0x8700000C (en=1 func=4 GREATER) ref=0x00000000
            -> athresh=0.0020

Matches the decomp lane's "ref is 0 forever" and matches what the old path computes from PM4
0x2202/0x210E (`vk_render.cpp:5755-5785`). Same state. No divergence.

#### 15.6 The ONLY divergences found — and they are the next leg
1. **OLD emits three draws into the ROM 640x512 target that nvk does not emit there at all:**
   - `EID 22` One/Zero, tex 9801, full target (changed 306595 px, mean RGB delta (+26.9,+7.7,-5.7));
   - **`EID 368` SrcAlpha OVER, n=480 = 160 rects, tex 9796, UV [0,0.125]^2 (one 32x32-texel cell
     tiled over the whole 640x512), changed 147080 px, mean RGB delta (-4.3,-5.6,-4.3)** — a
     uniform dark scrim over the entire ROM image. This is the class ledger sec.7 named (guest
     FUN_880FFCE8 / FUN_881538C0 id 0x170, 480 int32 {x,y,u,v} records = 80 tiles x 2 sprites) —
     the one nvk already had a decode landmine on (the all-zero sniff dword);
   - `EID 373` OVER, n=96, tex 9796, x[160,175] y[96,383].
   The low resource ids (9779/9796/9801 vs the ROM's 17xxx) say these are SHELL-era textures.
2. **NVK emits 35 draws into the 1280x720 window that the old path emits none of**: the window
   frame border (8 draws, EIDs 955-983) and the ROM compose (EID 988, one draw covering
   x[399,878] y[39,678]). The old path composes by blit and/or in the adjacent present, so its
   window pass is not even in this capture.

Net measured consequence in the ROM target, in a band under the plaques
(RT rows[115,329] cols[289,316]): **OLD 38.82 mean luminance vs NVK 40.50** — and the whole
1.68 gap is attributable to OLD's `EID 368` scrim (-1.28 there, -3.56 elsewhere). Every other
draw agrees to <0.2.

#### 15.7 What this leg did NOT establish — read before building on it
- **I could not localise a "shadow box" in this capture pair.** The composed-window OLD-vs-NVK
  signed diff has one strong horizontal band (thumb y~544-584, NVK brighter by up to 21 luminance)
  — but that band is where the animated water caustic sits, the two runs are one animation frame
  apart, and the same band in the *render target* differs by only 1.7. **I am explicitly NOT
  certifying nvkref_frame3088 as clean** (the 07-31 rule: five instrument-derived "clean"
  certifications were retracted and every user report was real). What is certified is narrower and
  destination-independent: *the ROM-pass draws are the same on both renderers*.
- The nvk **window/compose pass has not been bisected against the old path at all**, because the
  old path's window pass is in a different RenderDoc frame. `RVK_RDCCAP_N=3` (instead of the 1
  used here) captures the neighbouring presents and fixes that in one run.
- Cross-capture RT pixel diffs on this screen are worthless (animated backdrop). Only
  **within-capture, per-draw** quantities (exact touched masks, recovered blend multipliers) are
  admissible. Any future instrument on this screen must be built that way.

NEXT LEG: (1) recapture both arms with `RVK_RDCCAP_N=3` and bisect the **compose/window** pass,
which is the one place the two renderers genuinely differ; (2) explain why nvk never emits the
`EID 368` 160-rect scrim class into the ROM target — it is the only ROM-target content nvk is
missing, it is the class with the known sniff landmine, and it darkens the entire ranking image on
the oracle; (3) get a user-marked coordinate on a boxed frame (the sec.10 unblock) before spending
another leg on instrument-chosen regions.

### 16. TROPHY PAGE + COMPOSE-ALPHA: the white boxes live in ALPHA, are AUTHENTIC, and nvk does not consume them (08-01)

**VERDICT (A): the trophy page does NOT diverge either.** The stark-white rectangles of
`boxhunt_bad_rt.png` are the ROM target's **alpha channel** — 39936 texels at a==0 in two hard
rectangles under/right of each plaque, invisible in RGB. On a frame-aligned trophy-page pair the
OLD renderer produces **the same 39936 texels, in the bit-identical mask (XOR = 0 pixels)**, from
the same single `Zero/InvSrcCol` draw with the same n=48 and the same running alpha0 total. The
rectangles are authentic ROM-pass content that the oracle paints too.

**VERDICT (B): the mechanism is live on nvk but currently inert.** nvk's ROM->window compose IS a
draw with colour AND alpha blend `SrcAlpha/InvSrcAlpha` — it consumes source alpha, which the old
path structurally cannot (its ROM->window step is `vkCmdBlitImage`). But the compose has
**descriptor count = 1** and that one resource is the **320x240 R10G10B10A2 playfield resolve**,
whose alpha is 255 x71154 / 170 x5601 / **0 x45 of 76800** — the 39936 zeroed texels do not reach
it. Measured consequence: the compose's exact touched mask on the window is **307200 of 307200
pixels, HOLES = 0**. No punch-through in this capture. The risk is named and testable, not
speculative — see 16.4.

#### 16.1 Apparatus and captures
- Sweep on both arms with the §15 lever: `RVK_RDCCAP_ATFRAME=2400 RVK_RDCCAP_ATEVERY=60
  RVK_RDCCAP_MAX=16`, `RT_SAVE=save_trophy` (a throwaway copy of `save_playtest`, so the user's
  real save is never opened by a test run). 16 captures per arm, presents 2387..3287 (old) /
  2388..3288 (nvk).
- **Pair alignment must be measured, not assumed.** The naive same-index pair
  (troOLD_2927 / troNVK_2928) has ROM-target RGB correlation **0.399** — different pages; its
  alpha masks differ (45824 vs 20348) for that reason alone and that comparison is void. A full
  16x16 correlation sweep of the composed frames picks **troOLD_frame3107 / troNVK_frame3108**
  (corr 0.9696 on the ROM target). All numbers below are that pair.
- New scripts: `_tmpscripts/rdc/rdc_alphacompose.py` (per-draw running alpha0 on the ROM target,
  non-draw pixel-moving actions, window-target draw census with all bound resources),
  `rdc_composesrc.py` / `rdc_composesrc2.py` / `rdc_composesrc3.py` (what the compose samples).

#### 16.2 (A) The alpha rectangles — identical on both renderers

    OLD  eid=127  Zero/InvSrcCol  alphaBlend=Zero/InvSrcCol  n=48  mask=15  -> alpha0 = 178176
    NVK  eid=415  Zero/InvSrcCol  alphaBlend=Zero/InvSrcCol  n=48  mask=15  -> alpha0 = 178176

    final ROM 640x512 target:
      OLD alpha hist [(251,235432), (0,39936), (211,27536), (140,21792), (224,2736)]
      NVK alpha hist [(255,235432), (0,39936), (214,27616), (142,21792), (228,2736)]
      alpha==0 masks bit-identical: True     XOR = 0 pixels
      (user's defect capture boxhunt_bad_rt.png: alpha0 = 39936 — the same count)

The only difference is a uniform ~4/255 offset on the NON-zero alpha bins (251/211/140/224 vs
255/214/142/228). That is the §15 missing-scrim draw (`EID 368` class), which is a SrcAlpha pass
and so also nudges destination alpha down slightly on the old path. It is not a shadow difference.

So: the shadow class writes `dst.a *= (1-src.a)` into the ROM target and leaves hard alpha
rectangles — **on both renderers, in the same places, by the same draw**. Question A's "does the
old path paint the white rectangles too?" answers **yes, identically**. There is no trophy-page
ROM-pass divergence; the §15 parity finding extends to this page.

#### 16.3 (B) How each renderer gets the ROM image to the window

    troOLD (68 draws): non-draw pixel-moving actions = 2 x vkCmdBlitImage;  window-target draws = 0
    troNVK (102 draws): non-draw pixel-moving actions = 4 x vkCmdBlitImage; window-target draws = 35

nvk's window pass, measured (exact touched masks, within-capture):

    eid 1204/1208/1212/1216 ... frame border, 4 strips, no holes
    eid 1237  ROM COMPOSE  colour = SrcAlpha/InvSrcAlpha,  alpha = SrcAlpha/InvSrcAlpha, mask=15
              postVS: dst pos x[-0.3758,0.3742] y[-0.8903,0.8875] (= window x[399,878] y[39,678],
                      480x640), src uv (0,0)-(1,1) with u along -y and v along +x (transverse)
              descriptor count = 1  ->  ResourceId::5905, 320x240 R10G10B10A2_UNORM
              touched = 307200 of 307200 window pixels,  HOLES = 0
    (no window draw after 1237 changes a pixel)

The alpha of what it samples:

    ResourceId::5905 (compose source, 320x240): alpha 255 x71154, 170 x5601, 0 x45  (of 76800)

45 stray zero texels, no rectangles. **The compose therefore never sees the shadow's zeroed
alpha, writes every pixel, and cannot punch through.** The zeroed-alpha rectangles are inert on
the nvk present path in this configuration — the "inert" claim previously proven only for the old
present path now also holds, measured, for nvk's.

The old path's ROM->window step is not in this RenderDoc frame at all (0 window draws), i.e. it
happens in the adjacent present; `rvkWindowPresent()` composes with `vkCmdBlitImage`
(render/vk_render.cpp, the `vkCmdBlitImage(gw.cmd, blitSrc, ...)` in the present path), which
copies and cannot consume alpha. So the two renderers differ in *kind* here even though the
outcome currently matches.

#### 16.4 ⚠ The live risk this measurement DID expose — one test kills it
The zeroed alpha **survives the 640x512 resolve blit**:

    eid=803 vkCmdBlitImage  src=ResourceId::6353 (640x512 ROM EDRAM)  ->  dst=ResourceId::6359 (640x512)
      6353 alpha0 = 39936      6359 alpha0 = 39936

so a 640x512 resolve copy of the box rectangles exists in the frame, fully intact, one bind away
from the compose. The compose consumes source alpha. **If the compose ever samples 6359 (the
640x512 resolve) instead of 5905 (the 320x240 resolve) — a different resolve-alias verdict, an
`RVK_RESALIAS`/`RVK_RESREAL` decision going the other way, a page or arm where the 320x240 path is
not taken — every one of those 39936 texels becomes a transparent hole in the window, which is
exactly "the drop shadow is missing and a translucent box is there instead".** That is a
one-variable falsification for the next leg, not a hypothesis needing new tooling: bind-source of
eid-1237-equivalent + alpha0 of that source, both already printed by `rdc_composesrc.py`.

#### 16.5 Admissibility notes (carried forward and extended)
- Same-index capture pairs across two runs are **not** aligned by construction. Correlate first;
  the §16 pair needed a 16x16 sweep to find. A misaligned pair produced a 45824-vs-20348 alpha
  difference that means nothing.
- RenderDoc's `GetTextureData` on `R10G10B10A2_UNORM` returns packed dwords: byte 3 is
  `(A2<<6)|(B10>>4)`, so "top byte == 0" is NOT "alpha == 0". Counting it that way gave a false
  `alpha0 = 0`; the correct read is `SaveTexture` with `AlphaMapping.Preserve` (or `byte3 >> 6`).
- nvk is bindless: `GetReadOnlyResources(Pixel)[0]` is slot 0 of the descriptor array, not
  necessarily the sampled image. It was reliable for the ROM-pass draws (their reported textures
  matched the old path's byte-for-byte) but must be checked against the descriptor count — the
  compose happens to have count 1, which is why its attribution is trustworthy.

#### 16.6 OPEN ITEM carried from §15 — do not lose this
**nvk never emits the `EID 368` class into the ROM target** (guest id 0x170, `FUN_880FFCE8` /
`FUN_881538C0`; 480 int32 {x,y,u,v} records = 80 tiles x 2 sprites = 160 rects, UV [0,0.125]^2,
one 32x32-texel cell tiled over the whole 640x512). On the oracle it darkens the entire ranking
image by mean RGB (-4.3,-5.6,-4.3) and pulls the ROM target's non-zero alpha bins down ~4/255
(visible in 16.2 as 251/211/140/224 vs 255/214/142/228). **This is a real, separate nvk defect —
missing content, measured on both pages — and it is the class with the known all-zero-sniff decode
landmine (§7). It needs its own fix leg; it is NOT the shadow box.**

⏭ NEXT: the shadow-box hunt has now come back parity on two different ranking pages, in the RGB
pass and in the alpha pass, on the geometry, on the textures and on the compose. Every unattended
instrument says the two renderers agree. Per §10 and the 07-31 blast-radius rule, the next step is
**not** another instrument-chosen leg: get a user-marked coordinate (or a user F12 capture) on a
frame they call boxed, on the current build, and start from that pixel. The apparatus to consume
it — `RVK_RDCCAP_ATFRAME` on either arm, `rdc_alphacompose.py`, `rdc_composesrc.py` — is now in
tree and takes minutes, not a leg.

### 17. COMPOSE-ALPHA THEORY CLOSED NEGATIVE — by the shader's own microcode (08-01 evening)
Direct evidence chain on the punch-through hypothesis (§16 Q-B risk):
- User's defect capture futari_frame2055: downsample EID 905 (ONE/ZERO) DOES import the boxed
  640x512 alpha (39936 zeros) into ring sibling 2630 while compose EID 1065 reads healthy
  sibling 2636 (rdc_compose2055.py). Alias-off run: same shape (EIDs 848/1172), and the burst
  successor frame 2985's compose ALSO reads a healthy sibling (rdc_composeNext.py).
- DECISIVE: ps16 disassembly from the live pipeline (rdc_ps16disasm.py, SPIR-V): out.rgb =
  tex.rgb * c.rgb; **out.a = c.w — the sampled ALPHA IS NEVER READ** (the SampleImplicitLod
  result's .w has no consumers). Punch-through via ring alpha is IMPOSSIBLE through this shader.
  The SrcAlpha/InvSrcAlpha compose blend is armed but its src.a is a constant (measured 1.0).
⇒ Ring/import of boxed alpha is real but INERT end-to-end. The §16 "one bind away" risk is
formally closed. STATUS: every internal measurement (RGB, alpha, geometry, textures, compose,
shaders) shows old ≡ nvk ≡ believed-correct — yet the user consistently sees the box live.
⚠ The old≡nvk parity does NOT prove authenticity: both share getTexIndexReal and vertex-decode
machinery; a COMMON divergence from real hardware would measure as parity. The only referee that
can catch a common-mode defect is the REAL GAME (D:\ v1.3.6 / Xenia — [[futari-referee-lineup]]).
⏭ THE UNBLOCK (per §10's original plan, never executed): user-marked coordinates. Show the user
a captured frame they call boxed (usersave_frame2977 thumb), have them mark the box rectangle;
pixel-history at the marked point in the presented chain names the author in ONE offline run.
In parallel: like-for-like v1.3.6 referee screenshot of the SAME trophy page for the
authenticity verdict on the shadow's shape.

### 18. ★★★★★★ USER REFEREE VERDICT: OLD RENDERER CORRECT — DEFECT IS IN NVK'S PRESENT CHAIN
User ran _tmpscripts/oldrenderer_check.cmd (deploy env minus RT_NVK) and certified WITH SCREENSHOT:
"old renderer is fine, no shadow bug" — proper shaped drop shadows below/right of the plaques
(2nd/3rd plaque page, real save). nvk shows the hard clear rectangle at the same places
(user-marked coordinates banked, rdc_usermark.py: inside the marks the final window color is
UNDARKENED background 0.400 vs properly-dark 0.063 outside; NO window-stage draw distinguishes
in/out — only prepass EID 16 + compose EID 1162 touch those pixels).
⇒ With §15/§16 (ROM pass bit-identical old-vs-nvk), the divergence is squeezed into the ONE
stage the paths do differently: OLD presents the 640x512 ROM target via vkCmdBlitImage; NVK
downsamples 640x512 -> 320x240 ring sibling (rotating) then composes the ring into the window.
The shadow is painted into the ROM target correctly and LOST/BYPASSED on the way to the screen.
Live suspects, in order: (1) ring-sibling ROTATION serving a copy whose downsample predates the
shadow (stale-sibling off-by-N); (2) the downsample draw's source UV rect cropping/missing the
shadow region; (3) compose UV mapping reading the wrong ring region. All three are measurable
in the SAME capture (usersave_frame2977.rdc) with the markmap coordinates.

## §19 (08-01) Shadow-box: double-application theory UNPROVEN — capture pair invalid, leg PAUSED
- Theory: guest double-present applies the Zero/InvSrcCol shadow modulate twice on old/real HW
  (0.708²≈0.50) vs once on nvk (0.708). Motivated by presented-thumb region means on the aligned
  trophy pair (troOLD_frame3107 vs troNVK_frame3108): NVK ~+12/255 brighter in shadow regions only.
  Also suggestive: vk_render.cpp:11473 "idle presents re-blit the last composed g.image (guest
  re-present idiom)" — a re-blit shortcut that would skip a second submission's draws.
- rdc_doubleshadow.py (final ROM-target RGB at the 5 corrected coords, both captures):
  IN_belowP1 OLD (0,39,19) vs NVK (0,17,19); IN_rightP2 ≈equal; IN_belowP2 OLD (6,81,94) vs
  NVK (6,87,110); OUT_ctrl (CONTROL) OLD (0,124,146) vs NVK (0,132,155); OUT_plaque ≈equal.
- VERDICT: incoherent with the theory (one shadow point equal, one OLD-brighter-in-ROM, control
  differs ~6% same as shadow). Cause: the pair is one frame apart DURING the plaque fade-in —
  content/fade phase differ. **A one-frame-apart pair inside an animation cannot A/B shadow
  strength.** The +12 thumb delta (same pair) is contaminated the same way. §15/§16 ROM-pass
  bit-parity still stands. Theory neither confirmed nor refuted.
- RESUME PLAN (cheapest first): user-eyeball F12 pair at STEADY STATE — ranking page held several
  seconds after the fade completes, once per renderer (box is persistent per user screenshots, so
  steady-state captures are valid A/B). Re-run thumb region means + rdc_doubleshadow (edit the two
  hardcoded paths) on that pair. Shadow-only delta at steady state ⇒ chase ring/compose hop;
  equal ⇒ presented-domain theory dies and the box needs a fresh differential. Kill qrenderdoc
  after every --python run (lingers, looks stuck).

## ⚠ 08-14 LATE — **THE PUMP REFACTOR IS REVERTED (acd96cd). USER-SIGHTED playfield regression;
## the stream gate was NECESSARY BUT NOT SUFFICIENT.**
User relaunched after the a15bdbc refactor: ROM playfield elements MISSING (shadows/items/
enemy art thinned; legal + title panels falling to black/white placeholders), menus/borders
fine. A/B same drive same scene: pre-refactor transcription = RICH field (screenshots banked);
refactored = degraded. ROOT NOT ISOLATED — candidates: the produce-arm upload-descriptor
ARGUMENTS (E58/D50/CB8 flag, D640 page packing) which RT_DECLOG cannot see, or a second
register-leftover-as-argument like the r4 one the gate DID catch. The transcription is back
(build rebuilt + attract re-verified rich); the natural-C body is preserved at a15bdbc and
/c/tmp/asset_pump_refactored.cpp. **RETRY REQUIREMENTS: an upload-arg differential (log
E58/D50/CB8/D640 args control-vs-pilot the way declog covers decoders) + a pixel gate on the
STAGE field, not just selects. Gate lesson: STRICT decode-stream equality passed while the
game visibly broke — every produce-arm change needs its own instrument.**

## 🚀 08-14 — **BETA2 F&F ZIP CUT** → Desktop\Futari_Realcomp_BETA2_FNF.zip (898MB, build
## 183b038 = post-revert transcription pipeline, user-eyed playfield-right). Contents: combined
## exe + 2 DLLs, wizard launcher "Futari 1.5.bat", README + README_FNF (assets INCLUDED for
## instant play — private F&F precedent; friend can rename assets\ away to exercise the
## extraction wizard with their own dump), tools/extract, docs/DUMPING.md, shell, save
## template. Public zip stays the no-data shape per dist/next_release/STAGING.md.
