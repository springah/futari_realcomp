# PLAN — RC1 for the two hosted modes: ARCADE (Ver 1.5 Original) + XBOX 360 MODE

Triage window 2026-10-11 (user: "let's get 1.5 arcade and xbox360 at RC1"). Docs + measurements only: no engine,
decomp or TU change was made to write this. RC1 builds on docs/PLAN_beta3_mac.md (the beta-3 definition and checklist);
everything beta 3 proved is cited, not re-proved, unless the measurement below says otherwise.
Sources read: STATUS.md, BACKLOG.md (all), NOTE_fnf_shell_defects.md (beta-3 entries, 10-03..10-05, the 07-28 flicker
arc), NOTE_other_modes.md, PLAN_beta3_mac.md, PLAN_after_boss1_0920.md, PLAN_macos_bringup.md, SAVE_DESIGN.md,
NAV_MAP.md, EVIDENCE_INDEX.md, DECK.md, the Mac drive/soak/gate scripts, host/module_registry.cpp, and
futari_decomp docs/NOTE_campaign_decomp.md (w148 top block, the w136 block).

Evidence produced by this window is banked under `_local/rc1/` (gitignored; recipe + PREREG in the same folder):
`PREREG_rc1.txt`, `build_rc1_probe.log`, `nav/` (modes drive), `rc1_shell/`, `rc1_arcade/`, `rc1_x360/` (soaks).
The probe binary is `build/rc1_probe/rc1_probe` = `build_mac_dll.sh` from realcomp db1df9c + futari_decomp a959478f
(`decomp/` via `git archive`, i.e. the same 68-TU source set as today's 13:28 .app; FFM off as in the bundle).

---

## §1 RC1 DEFINITION (proposed — the user ratifies or edits)

"Release candidate" here means: **the family-and-friends .app could be handed to a tester with no caveat other than
the listed allowed known issues, and nothing on the BLOCKING list below is open for either mode.** It is a
behavioural bar on the shipped bundle, NOT a decomp-completeness bar (the matching decomp is the long game and
keeps running; see the freeze rule R9).

Per mode (ARCADE = `futari_game_normal.dylib`, modeIdx 0; XBOX 360 = `futari_game_abn.dylib`, modeIdx 1), on the
bundle's own engine, launched from Finder:

| # | Requirement | Bar |
|---|---|---|
| R1 | Boot | Finder launch → logos → shell title, both module dylibs bound (`[modreg] 2/2`), 0 FATAL / VK_ERROR |
| R2 | Title → mode | card panel decide reaches the module (ARCADE straight; XBOX 360 via LEFT + dwell); module title/attract runs |
| R3 | Every hosted menu path | hub's 7 rows (SCORE ATTACK incl. the LIVE-decline dialog, NORMAL PLAY 1P/2P/CONFIG, TRAINING incl. stage select, REPLAY DATA, OPTION and every sub-panel, CLOSE, RETURN TO TOP MENU) open, render their rows, and back out, in BOTH modules |
| R4 | Full game | one **full clear (1-ALL incl. the ending/staff roll) on Original** per mode, plus stage start + boss of every stage 1-5 reached on Original/Maniac/Ultra (training stage select is enough for the per-stage part) |
| R5 | Persistence round-trip | settings (B3 class), high score / ranking table, and a saved REPLAY written in one launch and read back (replay **played back to the same outcome**) in the next |
| R6 | Game over flows | NORMAL PLAY (replay-save prompt) and SCORE ATTACK (replay + score-register + ranking-cancelled) both return to a live hub; continue countdown works |
| R7 | Pause | in-stage START pause → RESUME, RESTART, RETURN TO TITLE all work |
| R8 | Mode switching | A→B→A swap cycle clean (`residue=0`), repeated ≥ 5 cycles with no stale-texture class (BACKLOG "swap-stale heap descriptors") |
| R9 | Co-op | 2P join at char select + 2P SIDE START → two-ship stage → 2P game over clean (scripted), plus one two-pad couch session (eyes) |
| R10 | Input | keyboard map as README; SDL pads (PS / Xbox / Switch at least one each class the user owns); in-game remap persists; P2 pad = player 2 |
| R11 | Audio | BGM + SE + voice audible and correct in shell and both modules; 0 audio underruns in the soaks (`RT_AUDIOSTARVE`) |
| R12 | Performance | 59.9-60.0 frames/s in shell, menus and stage in both modes (submit counter per minute), 0 `[slowframe]` > 100 ms outside loads; ≤ 30 % of a core idle (RT_VBSLEEP); FrameDelay 1V/2V/3V paced |
| R13 | Soak | crash-free: shell title+top menu 30 min; ARCADE demo 20 min; XBOX 360 module 20 min; memory **bounded** (RULED 2026-10-11, re-baselined from "RSS flat after minute ~15": plateau <= 740 MB, no allocation failure over 60 min; ARCADE plateaus at the 512 MB guest-heap ceiling, Q6); the Darwin page-release fix = post-RC1 (G5-fix); 0 FATAL / VK_ERROR |
| R14 | Visual fidelity | stage pixel gate + boss plate gate PASS (ARCADE today; XBOX 360 needs its own); no OPEN user-reported defect in FNF-x class |
| R15 | Flicker | **USER RULING 2026-10-11 ~14:10: "clean measurement is good for RC1."** BACKLOG #0 closes for RC1 on a pre-registered measurement on the RC build: user eyes clean + the w136 draw census (RVK_DRAWCENSUS=2) clean over the soak in BOTH modes = zero DROPOUT-CONFIRMED outside named classes that are SHOWN deterministic (identical frame/base/v0 across legs and binaries); the decomp-grounded compose 1:1 leaves the RC1 gate for the long-term decomp lane |
| R16 | Quit | app-menu Quit and window close leave no process; save intact |
| R17 | Packaging | VER bumped (proposal `0.3.0-rc1`), README rewritten for RC (known issues current, no beta text), Gatekeeper steps, every Mach-O minos 13.0, md5 recorded, F&F link only; SHARED copy for the archive |

**Allowed known issues in RC1 (if listed in the README):** FNF-2-class GPU device loss (die-loud, never seen on the
Mac); FNF-7 one-frame menu quad (Windows-era, not seen on the Mac); authentic behaviours (PRESS START strobe, title
blink, card-page fragment, M2 cross/seams = 360 content); FrameDelay 3V latency feel; Score Attack leaderboard greyed.
**Not allowed:** any crash/hang, any wrong-mode silent substitution, any missing menu rows (FNF-15 class), any
gameplay-visible sprite/texture defect (boss-1-head class), save loss, audio missing, non-60 pacing.

**Explicitly OUT of RC1:** Ver 1.01 (hirow, modeIdx 6/7), Arrange/Novice (palm, 2/3) and Black Label (kiniro, 4/5;
DLC data absent) — all stay greyed (`[modestub]`); Xbox LIVE / online leaderboards (decline path only); the decomp
completeness numbers (shell DONE %, MATCHED rows); the Phase-2 compositor decomp as such (only its user-facing symptom
is R15); Intel Macs / macOS < 13; any public build containing game data. **Steam Deck/Linux arm: NOT gating RC1** —
DECK.md shows it ships the same engine and passed unattended two-mode validation on 10-05, so it is proposed as an
"RC1-follow" artefact rebuilt from the RC1 tag (open ruling O3).

**Freeze rule (R-freeze):** RC1 = one realcomp commit + one futari_decomp commit, tagged together. Decomp promotions
continue on main, but the bundle is only re-cut after the full RC chain (§4 Q1) passes on the new pair.

---

## §2 WHERE EACH MODE STANDS TODAY (2026-10-11)

Status: PASS / FAIL / UNMEASURED / KNOWN-ISSUE / PARTIAL. "today" = measured this window on build/rc1_probe
(numbers in §2.1). A = ARCADE, X = XBOX 360 MODE.

| # | Item | ARCADE | XBOX 360 | Evidence pointer |
|---|---|---|---|---|
| R1 | Boot to title, 2/2 modules bound | **PASS** | **PASS** | app smoke 13:29 today on the 68-TU .app (`build/app_smoke_1011c.log`: 2/2 bound, 0 FATAL, 59.94 Hz); today: §2.1 M1/M2 |
| R2 | Title → mode → module | **PASS** | **PASS** (cold boot ~40 s) | `_local/nav_mac/b4_VERDICT.txt` (10-05, bundle engine); today §2.1 M1 |
| R3 | Every hosted menu path | **PARTIAL** — hub, NORMAL PLAY+CONFIG, TRAINING (rows visible since FNF-15 fix), SCORE ATTACK decline dialog, REPLAY list, every OPTION sub-panel driven on the Mac by the decomp gate routes v5/B1/B2/B4 (futari_decomp ledger w143-w148, byte-identical shots) | **Q2b 10-12: 360 menu route PASS x2** (hub -> NORMAL PLAY -> mode/char/shot -> stage 1 -> pause/resume -> RETURN TO TITLE -> hub -> top menu; `_local/rc1/q2b/{q2a4,q2b}/`); TRAINING/REPLAY/OPTION/SCORE ATTACK still not driven. Earlier **Q2 10-11: PARTIAL** — card decide → 360 title/attract → HUB → NORMAL PLAY submenu → 1P SIDE START → MODE/CHARACTER/SHOT select screens, and HUB B → return-to-top → shell TOP MENU, marker-asserted 1x (`_local/rc1/q2/r2/`); the cold boot lands at the module TITLE (not MODE SELECT). TRAINING/REPLAY/OPTION/SCORE ATTACK not driven. (was: UNMEASURED) | NOTE_campaign_decomp.md w144/w145; NAV_MAP.md |
| R4a | Stage 1 reached + playable | **PASS** | **PASS** | b4/m2 verdicts; today M1 |
| R4b | Stages 2-5 + bosses, all difficulties | **Q7 10-12 (route C, `_local/rc1/q7/`): ORIGINAL stages 1-5 each REACHED + BOSS + stage end on the Mac, scripted** -- TRAINING with the game's own options (Shot Power Max, Bomb Stock Infinity, Player Stock Infinity = infinite lives/bombs, NOT a no-cheat clear) + autofire/bomb: entry (`[navreal] d76 3->4`) / boss BGM / boss-defeat `[fade]` / end (`d76 4->8`): st1 t3856/m03_boss/t11320/t12024 (136 s), st2 t3921/m03_boss/-/t16642 (213 s), st3 t4016/m03_boss/t19874/t20542 (275 s), st4 t4115/m03_boss/t21875/t22452 (305 s), st5 t4209/m11_lbs1/t30257/t30979 (446 s); the training STAGE RESULTS TALLY shows after each boss; 0 FATAL / VK_ERROR / slowframe / underrun, 3,592-3,601 presents per wall minute, census = only the authentic PRESS START strobe (7 lines/leg). Maniac/Ultra not driven; stage 5 = m11_lbs1 only (m12_lbs2 / m13_endg = a continuous 1-ALL, user Q6). Was: UNMEASURED on the Mac (boss 1 only: boss plate gate); Deck: "several stages" by the user 10-05 | **UNMEASURED** | DECK.md verdict; `scripts/boss1/` |
| R4c | Full clear (1-ALL + ending) | **UNMEASURED** (no record of a port 1-ALL in any doc) | **UNMEASURED** | — |
| R5a | Settings round-trip | **PASS** (B3, 10-05, scripted; four bytes, atomic publish, read back) | **UNMEASURED** (same shell save path; not driven in 360) | NOTE_fnf_shell_defects.md 2026-10-05 |
| R5b | High score / ranking persist | **UNMEASURED** | **UNMEASURED** | — |
| R5c | Replay save → playback | **Q7 10-12: scripted replay SAVE PROVEN** (route C7: NORMAL PLAY stage 1 → GAME OVER → 「リプレイを保存しますか?」 A → REPLAY SAVE MENU → slot 01 overwrite → 「保存が完了しました」 OK; `[content] SAVE CreateEx replaydata.bin` + atomic publish, 0x986 bytes) **and same-launch PLAYBACK of the new replay** (REPLAY LOAD MENU lists 83648 Stage1 → plays to CONTINUE? → GAME OVER); relaunch read-back + outcome compare still UNMEASURED (Q4). Was: **PARTIAL**: playback of the stored replay PASS (w144 route B4: Stage 1 → GAME OVER → back to the list); scripted replay SAVE never proven ("replay-save probe inconclusive", ledger w75) | **UNMEASURED** | NOTE_campaign_decomp.md w144 |
| R6 | Game-over flows | **Q7 10-12 Mac: NP game over → replay-save prompt (msg=10) → save or decline → module title/ranking → hub PASS scripted (P2, C7 legs); continue countdown seen in replay playback, START-continue + name entry not driven (score never a ranking score)**; **PASS on Windows** (NP + SA, 08-12/08-13, NAV_MAP) + Mac bundle 10-04 ("game over -> top menu"); continue countdown UNMEASURED | **PARTIAL**: 10-04 bundle check covered both modes to game over → top menu; SA flow UNMEASURED. ⚠ Q2 r2: a 1P start at a ~13 s select cadence went straight to the replay-save prompt (d76 4→5→6→8, slot0 1→0, st 5→2) instead of stage 1 — unattributed (NAV_MAP 360 "replay-save trap") | PLAN_beta3_mac.md todo 4; NAV_MAP.md |
| R7 | Pause / resume | **Q7 10-12: in-stage START pause → A on RESUME → play continues, scripted on the Mac (route C1, every leg; TRAINING pause menu = RESUME / RESTART / OPTION / PREVIOUS MENU)**; RESTART / RETURN TO TITLE still UNMEASURED. Was **PARTIAL**: pause opens (shot); RESTART / RETURN TO TITLE UNMEASURED. Q2: resume input = **A on RESUME** (START does not resume), seen working on the Mac 10-03 (`_local/boss1_mac/gamectl/guest.log`: A → pause model `0x82061D50->0x82061D70`, play continues, next START re-pauses) | **PASS in 360 x2 (Q2b 10-12)**: pause opens, RESUME = A (play advances), RETURN TO TITLE (DOWN x3, A, A) lands on the hub — `_local/rc1/q2b/{q2a4,q2b}/`; RESTART / OPTION-in-pause / continue UNMEASURED; ARCADE leg not rerun | `_local/rc1/nav/rc1m_*/shot_3.png` |
| R8 | Swap cycle | **PASS** 1 cycle (10-05 and today on the 68-TU sources, residue=0 x2); ≥ 5 cycles UNMEASURED | same | `_local/rc1/nav/rc1m_VERDICT.txt` |
| R9 | Co-op | **PASS on Windows** scripted (COOP_arcade_PASS 08-14); Mac UNMEASURED; couch session owed (eyes) | **PASS on Windows** (COOP_360_PASS); Mac UNMEASURED | BACKLOG #9; NAV_MAP.md 2P |
| R10 | Input | keyboard **PASS** (README map, FIFO drives ride the same host channel); SDL pads used by the user; P2 pad + remap persistence UNMEASURED on the Mac | same | PLAN_macos_bringup.md top block; README |
| R11 | Audio | **PASS** (guest-native, CoreAudio sink; RT_AUDIODUMP 10-03); today 0 underruns / 0 sink stalls in 10 min | **PASS** today: 0 underruns / 0 stalls in 10 min; content by ear on Windows beta 2 only | PLAN_macos_bringup.md |
| R12 | 60 fps pacing | **PASS**: 3,600 frames every minute in shell, attract and demo today, 0 [slowframe]; in-stage per-minute rate not separately sampled (stage-1 legs PASS) | **PASS** today: 3,600/min in the module attract, 0 [slowframe] | PLAN_beta3_mac.md todo 5; NOTE 2026-10-05 noon |
| R13 | Soak | **Q6 10-11 (60-min ARCADE ceiling soak, `_local/rc1/q6/REPORT_q6.md`): PASS -- RSS 426 (min 2) / 572 (10) / 708 (25) / 713 (40) / 719 (60), slope 0.32 MB/min over the last 30 min, heap high-water pinned at 496 MB from min ~18, live 200 MB, pooled 291 MB, 0 FATAL / VK_ERROR / allocation failure, 3,600 frames/min, 0 slow, 0 underruns, 15 demo cycles per 20 min throughout -> R13 ARCADE re-baselined to BOUNDED; G5-fix queued post-RC1.** **Q5 10-11 BISECTED: the ARCADE RSS ramp is NOT the decomp link (all 132 linkable decomp TUs skipped still +129 MB min2->10 vs +133 full) -- it is the guest physical allocator (out_reco/rt_phys.cpp) bump frontier advancing over pooled-but-unreused freed blocks (heap high-water 17->352 MB in 10 min, live flat ~160 MB, pooled 14->181 MB; plateau = the 512 MB law-4 line; same allocator trajectory on 10-05); no page release on macOS (decommit is _WIN32-only); fix-or-rebaseline ruling owed (G13).** **Q1 10-11 (single-instance, `_local/rc1/q1/REPORT_q1.md`): shell 30 min PASS (285→292, flat); ARCADE 20 min FAIL as pre-registered (395→707 MB, slope 15.2 MB/min last 10 min; BUT a 25-min extension saturates at ~708 MB by min ~21 = bounded ramp, not an unbounded leak; needs ruling); perf 3,600/min, 0 slow, 0 underruns, 0 FATAL/VK_ERROR.** shell 30 min **PASS** (10-05, RSS 268→277 MB flat), ARCADE demo 20 min **PASS** (10-05, 15 cycles) — both on the 18-TU-era engine; today 10 min on the 68-TU sources: 0 errors but **RSS rising 399→553 MB** (10-05: cycling 202-425 over 20 min) → G13 | **Q1: 20 min PASS (545→619, flat from min ~5; 0 FATAL/VK_ERROR/slow/underruns, 3,600/min).** **PARTIAL** today: first 360-module soak ever, 10 min, 0 errors, RSS flat from minute 5 (615 MB); 20 min owed | soak_20261005_120159.txt, demosoak_20261005_131716.txt; today §2.1 |
| R14 | Visual gates | stagepix **PASS**, boss plate all-game sweep **PASS** (10-05); both audits 0 DRIFT / 0 MISSING | **UNMEASURED** — the boss plate and stagepix gates only ever drove ARCADE; the 31 ABN-EXCLUDED game TUs mean the 360 module runs generated code there (fine), but the 360-only regenerated tree (eqv-fix recompiler) has had no content gate beyond stage 1 | `_local/boss1_mac/gates_vbsleep.txt` |
| R15 | Shell flicker | **Q1 10-11 single-instance census: PASS — 0 dropouts in R1 30 min shell + R2 20 min + R2b 25 min ARCADE; 6/6 hand-over legs = only the authentic PRESS START strobe (class a); the triage len=3 f1641 NOT reproduced in 8 hand-overs (contention artefact).** **user eyes 2026-10-11: "not seen in a while" (beta 3 → today's 68-TU .app); UNMEASURED on the current build before today** — w136 census (10-05) ZERO over 12 min; **today: shell 0 dropouts / 10 min; ARCADE module 1 unreproduced len=3 at the hand-over (1 of 2 legs) → criterion NOT met yet** | **Q1: PASS-WITH-NOTE — R3 20 min + 6 legs: only the card-LEFT loss (base 0x34E0000, LEFT+13 presents, len=1), identical in 7/7 = deterministic, unattributed (R5).** **today: 1 deterministic press-coincident loss on the card panel (2 of 2 legs), unattributed** → PENDING Q1 | NOTE_fnf_shell_defects.md 2026-10-05; coordinator relay of the user's words |
| R16 | Quit | **PASS** (app smoke: Quit leaves no process, save read back) | **PASS** (same engine; 10-04 bundle check) | app_smoke_1011c.log |
| R17 | Packaging | **PARTIAL**: bundle builds, minos 13.0, README is BETA 3 text, VER 0.2.0-beta3; zip + Drive route exist; SHARED copy OWED (NAS offline, LAN renumbered 10-07) | same | PLAN_beta3_mac.md todo 7 |

Other standing items checked against RC1:
- **FNF-2 device loss** — Windows lottery ~1/10 drives; never seen on MoltenVK; die-loud path never exercised on
  the Mac → KNOWN-ISSUE (allowed).
- **w148's "7 dropouts per leg" are NOT transients**: all 63 lines across the 9 w148 legs (pilot and control alike)
  are the same single quad, base 0x2530000, v0 (-190.5,181.5), len=2 at f833/837/…/857 — the 25 frames right after the
  START press scheduled at t826 = the authored PRESS START post-accept strobe (07-31 TITLE-CADENCE leg: authentic).
  They are not the w136 press-coincident menu-atlas pair (base 0x49C4000), which the B4 route does not press into.
- **w136 owed ④ (the five press-coincident 2-frame menu-atlas quad losses on the Options tour)**: still unattributed
  (authored hide flip vs port-deterministic). Not user-visible as far as anyone has reported → low, but it is the
  one census line the flicker closure must explain (§3 G6).
- **Swap-stale heap descriptors** (BACKLOG post-beta research): mitigated by a black placeholder; repeated two-mode
  swapping is exactly what RC1 users do → R8's ≥ 5-cycle requirement.
- **Deck arm**: two-mode unattended PASS 10-05 (modes_deck d1, 30-min soak to the suspend cut-off), user "seems ok";
  360 mode never on the Deck screen; Steam Input mapping owed → follow-on (O3).

### §2.1 Measurements this window

All on `build/rc1_probe` (68-TU sources), 18:02-18:16 AEDT, after the w149 arms had been quiet for 3 polls; a
watchdog would have killed only the probes had a w149 arm reappeared (it never fired). **Four instances ran
concurrently** (three soaks + the modes drive) — pacing held at 60 frames/s regardless. PREREG: `_local/rc1/PREREG_rc1.txt`.

**M1 modes drive** (`_local/rc1/modes_rc1.sh` = scripts/modes_mac.sh with own FIFO/bank/kill; verdict
`_local/rc1/nav/rc1m_VERDICT.txt`): **VERDICT PASS** — XBOX 360 to stage 1 (2/2 bound, abn loaded, m02_stg, 0 FATAL),
ARCADE to stage 1, swap cycle arcade→x360→arcade `#2 DONE`/`#3 DONE`, `residue=0` x2, hub rebuilt and ACTIVE after the
return swap, 0 FATAL/VK_ERROR. In-stage START opened the pause menu (RESUME / RESTART / OPTION / RETURN TO TITLE) in
**both** modes (shots `nav/rc1m_{x360,arcade}/shot_3.png`); a second START did **not** resume — the menu's own caption
says A = 決定 / B = 戻る, so START is not the resume button there (the drive used the wrong button; resume itself is
UNMEASURED, not failed). Contact sheet: `_local/rc1/contact_rc1.png`.

**M2/M3 soaks** (`_local/rc1/rc1_soak.sh`, hands off after the decide, RVK_DRAWCENSUS=2 + RVK_TITLEPROBE=1 +
RT_AUDIOSTARVE=1; per-minute lines in `_local/rc1/<tag>/soak.txt`, census lines in `census_lines.txt`):

| soak | length | frames/min | RSS first→last | FATAL | VK_ERROR/VUID | [slowframe] | audio underruns | DROPOUT-CONFIRMED | what ran |
|---|---|---|---|---|---|---|---|---|---|
| shell (title 5 + START + top menu 5) | 10 min | 3,600 every minute (60.0/s) | 285 → 290 MB, flat | 0 | 0 | 0 | 0 | **0** (36,901 frames) | title, top menu |
| ARCADE module | 10 min | 3,600 | **399 → 553 MB, rising ~17 MB/min** | 0 | 0 | 0 | 0 | **0** | 7 demo cycles (`d76 0->3` x7, back x7): DEMONSTRATION → ranking → title |
| XBOX 360 module | 10 min | 3,600 | 546 → 615 MB, flat from minute 5 | 0 | 0 | 0 | 0 | **1** (see below) | 360 title ↔ Original Ranking attract (no demo gameplay seen in the per-minute shots) |
| ARCADE try 1 (killed at ~2.5 min by this window's own kill-pattern bug, kept as evidence) | 2.5 min | 3,600 | 400 → 425 MB | 0 | 0 | 0 | 0 | **1** | decide → module title |
| XBOX 360 try 1 (stopped at 155 s by a script bug in the swap wait) | 2.5 min | — | — | 0 | 0 | — | — | **1** | card panel → decide |

Census reading against the pre-registered criterion (zero dropouts outside classes SHOWN deterministic):
- **XBOX 360, 2 of 2 legs:** one `len=1` loss of the same quad, base 0x34E0000 v0 (41.5,-284.5), at f1404 / f1374, in
  both legs just BEFORE `[modeidx]` — i.e. during the card panel's LEFT press + 3.6 s dwell (the leg whose presses came
  earlier saw it earlier). Same quad, same length, same press phase in both legs = a deterministic press-coincident
  class, the twin of the w136 menu-atlas pair (G11). Not pre-registered → by the letter it is a new class to attribute,
  not a pass.
- **ARCADE, 1 of 2 legs:** one `len=3` loss, base 0x1C54000 v0 (251.0,-5.4), f1641, ~140 frames after the ARCADE
  decide (module boot / ROM title fade-in), nDraws=581; **absent** from the second leg at the same phase. One
  non-reproduced dropout = **non-deterministic until shown otherwise** → the pre-registered criterion is **NOT met**
  today. Caveats: 4 concurrent instances; it sits on the shell→module hand-over, not on the title/top menu the user
  ever reported. Q1 must repeat this phase ≥ 5 times single-instance.
- **w148's 7 dropouts per leg** (re-read this window): 63/63 lines across 9 legs of 2 binaries are one quad, base
  0x2530000 v0 (-190.5,181.5), len=2, f833-857 right after START at t826 = the authentic PRESS START post-accept strobe
  (07-31). Deterministic, excluded.
- shell title + top menu: **0 dropouts in 36,901 frames** (and 0 in the killed try's 2.5 min) — the screens the user
  reported clean by eye are census-clean on the 68-TU sources.
**Flicker verdict today: NOT YET CLOSED — shell CLEAN; module hand-over has 1 unreproduced dropout (ARCADE) and 1
deterministic unattributed press-coincident class (360 card). Numbers above; Q1 decides.**

---

## §3 GAP LIST (ranked by RC1-blocking severity)

Severity: **B** = blocks RC1 for that mode · **B?** = blocks unless the user rules it allowed · **M** = must be
measured before RC1 (cheap, expected to pass) · **P** = polish/packaging. Cost: S = Sonnet window (~30-45 min,
scripted, pre-registered), O = Opus window, E = user eyes/hands, R = user ruling.

| G | Gap | Sev / modes | Evidence | Lane (suspected cause) | Cost | Depends on |
|---|---|---|---|---|---|---|
| G1 | **[Q7 MEASURED 10-12 (ARCADE, Original): stages 1-5 + bosses + stage-end tally reached by script via TRAINING with the game's own infinite-stock options; Maniac/Ultra, XBOX 360 and the no-cheat 1-ALL + ending (user, Q6) remain]** **No full-game coverage**: stages 2-5 + bosses never driven on the Mac; no 1-ALL / ending on any platform in the record | B · A+X | §2 R4b/R4c | drive (harness), then whatever it finds (decomp game TUs = the boss-1-head class; renderer) | S (training-select sweep: 10 stage/boss entries x 3 difficulties x 2 modes, shots + error counts) + E (one Original 1-ALL per mode, replay saved) | G3 for the replay half |
| G2 | **[CLOSED for the NORMAL PLAY route by Q2b 10-12 (RT_NAV360 markers; route PASS x2); TRAINING/REPLAY/OPTION/SCORE ATTACK tours = Q3-X seed]** was: **XBOX 360 module is drive-blind past the card**: no route has entered a 360 hub/menu; the drive markers `[intap]`/`[scenelog]`/`[navreal]`/`[gemsg]` read reco_normal globals and are garbage under reco_abnormal (NAV_MAP), so a scripted 360 drive cannot assert screens | B · X | NAV_MAP.md instruments; w144 "360 card route NOT measured" | harness: abn-aware markers (the +8 relocation already exists as `abn_symbol_map.h`; GameEntry 0x8824E6A0 in abn) | O (marker parity + 360 NAV_MAP section), then S (360 menu-path tour = R3 for X) | — |
| G3 | **Persistence not proven end-to-end**: scripted REPLAY save never proven ("inconclusive", w75); high score / ranking persistence never measured; 360-mode save untouched | B · A+X | §2 R5b/R5c | shell kernel save path (XamContent*, SAVE_DESIGN.md) or nothing (may just pass) | S (play → save replay → relaunch → play it back → compare outcome; score register → relaunch → ranking table), O only on failure | G2 for X |
| G4 | **[Q1 MEASURED 10-11: draw-census half PASS(+note) both modes, evidence `_local/rc1/q1/`; eyes retest on the RC build still owed]** **Shell flicker (BACKLOG #0)** — acceptance RULED 10-11 (clean measurement suffices): user eyes "not seen in a while"; draw census 10-05 zero; today shell 0, but ARCADE hand-over 1 unreproduced dropout + 360 card-panel deterministic press-coincident loss (§2.1). The glass/present-alternation class (07-28 Windows RenderDoc) has never been looked for on the Mac | B? · A+X | §2 R15 | renderer present path (if anything) | S (census soak at RC length, both modes, pre-registered) + E (one eyes retest on the RC build) (ruled 10-11: clean measurement closes it) | — |
| G5 | **[Q6 PASS 10-11: the ARCADE memory item (G13/R13) is NON-BLOCKING for RC1; the Darwin page-release fix is the post-RC1 G5-fix, see Q6 entry in §4]** **No RC regression chain**: the gates exist (app smoke, modes, stagepix, boss plate, audits, soaks, fdpace, B3) but nothing runs them as one, on the bundle engine copy, at RC lengths; several Mac scripts `pkill -f` patterns that would hit the user's .app engine (soak_mac.sh, demo_soak_mac.sh match `Contents/MacOS/futari_merged`) | M · A+X | scripts/*.sh headers | harness | S (`scripts/rc_chain_mac.sh`, pkill -x only, one verdict file) | — |
| G6 | **Mode swap at scale**: one A→B→A cycle proven; the stale-heap-descriptor class (BACKLOG post-beta) is the known risk of repeated swaps | M · A+X | b4_VERDICT; BACKLOG "Swap-stale heap descriptors" | module registry / bridge re-image | S (≥ 5 cycles with stage-1 shots after each swap, black-placeholder counter) | G5 |
| G7 | **360 visual gates absent**: stagepix and the boss plate only ever drove ARCADE; the 360 tree is regenerated with a reconstructed recompiler (validated by diff, not by content) | B · X | §2 R14 | recompiler / generated code (not decomp: the 31 ABN-EXCLUDED TUs run generated bodies) | O (design a 360 plate: symmetry plate + training-boss route under abn markers; no oracle needed for symmetry), then S | G2 |
| G8 | **Co-op on the Mac**: scripted COOP_*_PASS is Windows 08-14; Mac never driven; couch session never done | M (B if O2 = in) · A+X | BACKLOG #9 | input / shell | S (port day8_2p_validate to nav_mac, P2 FIFO field) + E (couch) | G2 for X |
| G9 | **Input breadth**: pad classes, P2 pad, in-game remap persistence, F11 fullscreen + Retina/ProMotion display, keyboard-only full session | M · A+X | README; PLAN_beta3 todo 8 | SDL3 host input / presenter | E (20-min attended checklist) + S (remap save round-trip scripted) | — |
| G10 | **Continue / pause sub-flows**: RESTART, RETURN TO TITLE, continue countdown, SA game-over chain on the Mac | M · A+X | NAV_MAP (Windows-mapped) | shell/game | S (fold into the G5 chain) | G2 for X |
| G11 | **w136 owed ④**: five press-coincident 2-frame losses of a menu-atlas quad pair (base 0x49C4000) on the Options tour, deterministic, binary-independent, unattributed | M · shell | NOTE_fnf_shell_defects.md 2026-10-05 | authored hide flip (likely) vs port | S (one-shot `RVK_QUADCENSUS` armed on the press; compare the hide byte) | — |
| G13 | **[Q5 BISECTED 10-11, `_local/rc1/q5/REPORT_q5.md`: NOT decomp (S1 all-skipped +129 MB vs full +133); engine-side = guest physical allocator rt_phys.cpp: freed blocks pooled but not reused so the frontier advances until the 512 MB line; no macOS page release. Options: Darwin arm of rt_decomSweep (MADV_*, gated, re-run stage gates), pool-reuse change, or re-baseline R13 to bounded <= ~720 MB]** [Q1 MEASURED 10-11 single-instance: REAL, not contention — ramp 395→707 MB over 20 min (~17 MB/min, +23 MB per ~80 s demo cycle) then plateau ~708 MB by min ~21 (R2b 25 min, last-5 slope 0.6); +283 MB over the 10-05 envelope; bisect (DECOMP_SKIP halves) or re-baseline R13 — ruling owed]** **ARCADE demo-loop RSS growth on the 68-TU sources**: 399 → 553 MB over 10 min, ~17 MB/min, no plateau yet (10-05 bundle: cycling 202-425 MB over 20 min, no monotonic growth) — either the 10-05 cycling with a longer period, a regression from the 50 TUs linked since, or 4-instance contention | M (B if it keeps growing) · A | §2.1 table | decomp shell TUs (asset/bank release paths) or allocator churn | S (fold into Q1: 30-min single-instance ARCADE soak; if monotonic, bisect by DECOMP_SKIP halves, 2 legs each) | — |
| G12 | **RC packaging**: VER/README still beta 3; SHARED copy owed (NAS offline since the 10-07 renumber); RC md5 set; Deck follow-on build | P · A+X | PLAN_beta3_mac.md todo 7 | packaging | S (README + bump + zip + Drive) + E (NAS back) | everything above |

---

## §4 THE WORK QUEUE

Ordered for the orchestrator. Every window: build its own binary (`OUTDIR=build/<name> OBJSFX=_<name>
build_mac_dll.sh`, copy the host to a unique process name, kill only by `pkill -x <name>`), never touch the .app /
build/futari_merged / Application Support, bank under `_local/rc1/<window>/`, pre-register the pass criteria before
the first drive, and serialize GPU drives with any decomp gate window. **[S]** = Sonnet-able as written.

**Q1 [S] FLICKER CENSUS + RC SOAKS (G4 measurement, G5 seed).** Goal: settle R13 + the draw half of R15 on the RC
sources at RC lengths. Inputs: `_local/rc1/rc1_soak.sh` + `PREREG_rc1.txt` (this window's recipe), the w136 census
method. Fix first: rc1_soak.sh already waits correctly for the 360 swap; give each leg its own process name. Run,
SINGLE-INSTANCE: shell title 15 + top menu 15 min; ARCADE module 30 min (also settles G13's RSS slope); XBOX 360
module 20 min; plus ≥ 5 short legs per mode of the card → decide → module-title hand-over (the phase where today's two
census lines sit, §2.1) to classify them deterministic vs not; one 4-min `RVK_CENSUSTEST=1` positive control; then a
one-shot quad census on the card-panel LEFT press (base 0x34E0000) and the w136 pair (G11) to attribute them. PASS = 0 DROPOUT-CONFIRMED outside the two named
deterministic classes, 60 inject → 60 confirmed in the control, 0 FATAL/VK_ERROR, RSS flat, 59.9-60.0 frames/s, 0 audio
underruns. Model: Sonnet.

**Q1 measured (2026-10-11, 18:21-20:13, Sonnet seat, single-instance, drive lock, pre-registered in `_local/rc1/q1/PREREG_q1.txt`; report `_local/rc1/q1/REPORT_q1.md`).** Binary build/rc1_probe reused (sources unchanged: realcomp docs-only since, decomp w149 touched no compiled TU). Soaks (0 FATAL / 0 VK_ERROR / 0 slowframe / 0 underruns, 3,600 frames every minute): shell 30 min RSS 285→292 flat, 0 dropouts; ARCADE 20 min RSS 395→707, 0 dropouts; ARCADE extension 25 min RSS 396→709, 0 dropouts; XBOX 360 20 min RSS 545→619 (flat from min ~5), 1 dropout. Hand-over census (6 ARCADE + 6 XBOX 360 tick-scheduled legs): ARCADE = only the authentic PRESS START strobe (0x2530000, START+3..+31, 6/6), nothing at/after the decide, the triage len=3 0x1C54000 line did not recur in 8 hand-overs; XBOX 360 = strobe + exactly one 0x34E0000 len=1 loss at LEFT+13 presents in 6/6 legs and the R3 soak (7/7 deterministic). **Verdicts: flicker (draw census) ARCADE PASS, shell PASS, XBOX 360 PASS-WITH-NOTE (deterministic, unattributed card-LEFT loss; R5 documented PASS, attribution needs the G11 one-shot quad census); perf PASS; memory: shell PASS, XBOX 360 PASS, ARCADE FAIL as pre-registered (end 707 > 425 envelope, last-10 slope 15.2 MB/min) but bounded — plateau ~708 MB from min ~21 in two runs (G13: real, not contention).** Notes for the next window: the PRESS START strobe appears only under tick-scheduled presses (RT_TICKLOG legs), not in the wall-clock FIFO soaks; ARCADE RSS needs a ruling (re-baseline to a bounded ~720 MB plateau vs bisect the ~23 MB/demo-cycle growth by DECOMP_SKIP halves); the RVK_CENSUSTEST positive control and the one-shot quad census were not run (out of this seat's order).

**Q5 bisected (2026-10-11, 20:15-20:58, Sonnet seat, single-instance, drive lock, pre-registered `_local/rc1/q5/PREREG_q5.txt`; report `_local/rc1/q5/REPORT_q5.md`).** Oracle RSS@min10 - RSS@min2 of a 12-min ARCADE demo-loop soak (GROWING > 60, FLAT < 25). S0 full link +133 MB (425->558, control valid); S1 ALL decomp TUs skipped (132 of 134; nvk + xnotifycensus must stay to link) +129 MB (396->525); S1 repeated with vmmap +132 -> GROWING, so the decomp link is exonerated and no TU bisection was needed. vmmap min2 vs min10: the whole +127 MB is the Untagged guest-arena region (pages touched inside an existing mapping); malloc zones, IOSurface/IOAccelerator, code/data flat. The `[heap]` log names the mechanism: guest heap high-water 17->352 MB while LIVE stays ~160 MB and POOLED (freed, retained, not reused) grows 14->181 MB; the plateau at ~708 MB is the rt_phys.cpp 512 MB line (law 4). The 10-05 .app log shows the same heap trajectory (high-water 496 MB, pooled 306 MB), so this is not a regression; macOS never releases pooled pages (rt_decomSweep is _WIN32-only); why 10-05 ps-RSS read 202-425 is unresolved. **Not fixed.** Fix window (Opus, rt_phys.cpp): Darwin page-release arm gated by RT_DECOMMIT with the stage/pixel gates re-run, or pool-reuse tuning with a per-size alloc/free histogram first, or re-baseline R13 to a bounded <= ~720 MB plateau.

**Q6 measured (2026-10-11, 21:29-22:30, Sonnet seat, single-instance, drive lock after a 28-min wait, pre-registered `_local/rc1/q6/PREREG_q6.txt`; report `_local/rc1/q6/REPORT_q6.md`).** One 60-min ARCADE demo-loop soak on the reused build/rc1_probe: RSS 426 MB @ min 2, 572 @ 10, 708 @ 25, 713 @ 40, 719 @ 60 (max 719; last-30-min slope 0.32 MB/min). `[heap]` high-water 17 MB at boot -> 368 MB @ min 10 -> 496 MB (0x1F008000) from min ~18 and never advancing again; live 185-200 MB, pooled 291 MB; no crossing of the 0x20000000 line. 0 FATAL / VK_ERROR / allocation-failure lines, 3,600 frames every minute, 0 slow frames, 0 underruns, 0 dropouts, 45 demo cycles (15 per 20 min, cadence unchanged first vs last 20 min). **Verdict PASS: ARCADE memory is BOUNDED; R13 re-baselined (see §1); G5/G13 non-blocking for RC1.** Residual: a 0.3 MB/min creep inside the plateau and 291 MB of pooled pages macOS never returns.

**G5-fix (Opus, post-RC1): Darwin MADV_FREE arm in rt_decomSweep gated RT_DECOMMIT, or pool-reuse tuning from a per-size alloc/free histogram; regression oracle = the Q5 12-min RSS@10 minus RSS@2 (S0 control +133 MB, GROWING > 60, FLAT < 25), with the stage/pixel gates re-run.**

**Q1b [O] PER-FUNCTION DIFFERENTIAL HARNESS ("shadow mode") — DESIGN WINDOW (user-approved 2026-10-11 ~14:40).**
Serves RC1 confidence AND the long-term decomp lane; NOT an RC1 blocker by itself. Goal: the method for the witnessing
gap — the 117 stay-DRAFT rows (80 w148 + 35 w145 + 2 w146), incl. the directly-called main-loop / present / draw bodies
the indirect-call census (RT_INDCENSUS) cannot see. Mechanism: at function entry on the control routes, snapshot the
registers + the memory the function touches; run the generated body and the readable body from the same snapshot;
compare final GPRs/FPRs/VRs, CR/XER and the memory-write set; then mutate snapshots to reach inputs the routes never
produce. Inputs: futari_realcomp shell/gen/rt.cpp + out_reco/rt.cpp dispatch (PPC_FUNC / __imp__ override forms,
rt_lookup), the PPCContext model (out_reco/ppc_context.h), futari_decomp bank/r23/w148/seam_map_w148.tsv (which bodies
are plain / override / wrapper / kernel-called). Pass criteria (positive + negative controls before any sweep): the
harness reproduces a known-good MATCHED TU as EQUIVALENT, and a known-bad pre-fix TU as NOT equivalent — the
objaction_queue sel==3 / straight-ahead-pose defects caught by the boss plate gate (10-04) or famk1 at its pre-fix
G_RNG_SEED revision; only then run it over the 117 rows and emit per-row verdicts + the write-set diffs. Analogue:
PCodeTrans, arXiv 2603.14855. Model: Opus (design + controls); the sweep itself can then be Sonnet.

**Q2 [O] XBOX 360 DRIVE PARITY (G2).** Goal: abn-aware markers so a scripted drive can assert 360 screens; a 360
section in NAV_MAP. Inputs: NAV_MAP.md instruments list, `out_reco_abn/abn_symbol_map.h`, the [gemsg]/[navreal]/
[intap] sources in merged_game.cpp / decomp game_entry_msgs (ABN-EXCLUDED), NOTE_other_modes.md correction (1) (+8
above 0x880DF080). Harness-only levers, default inert, A/B-proven byte-inert on ARCADE. PASS = the same hub→NORMAL
PLAY→stage→pause→game-over route asserted marker-by-marker in BOTH modules, 3 legs each, 0 desync. Model: Opus.

**Q2 done — PARTIAL (2026-10-11 21:00 → 10-12 00:35, Opus seat, build/w152_q2 = build_mac_dll.sh from realcomp 87c21ea +
the lever, decomp a54c40a8 via git archive, FFM off; evidence `_local/rc1/q2/`).** Finding: the 360 module is NOT
drive-blind at the shell — the hub/submenu/pause/return-to-top are the same shell models and [mstate]/[mcur]/[decide]/
[p0build]/[modswap]/[gemsg] hold unchanged; what is blind is every MODULE-side observer ([navreal] & co) because the
scene/select/death/slot cluster is read at reco_normal addresses and sits +0x60 in reco_abnormal (only six globals were
descriptorised). Delivered: lever **RT_NAV360** (merged_game.cpp, default OFF, read-only, dshift-rebased [navreal] twin;
defect note NOTE_fnf_shell_defects.md 2026-10-11 Q2; inert by construction — a static bool gate around the only new
code, no write, no line unless set; a no-lever runtime A/B was NOT run, owed), NAV_MAP "XBOX 360 MODE" (16-node graph,
markers, ceilings, the fresh-save dialog, the [cue]-prints-once trap, the 360 replay-save trap), `scripts/nav360_mac.sh`
(lock, save seed, own FIFO, `pkill -x`, verdict). Measured: 2 legs only (the drive lock was held by Q6/w151/w150 sweeps
for ~2 h 40 min of the window): r1 desynced on the fresh-save dialog (fixed: SEED); r2 proved nodes 0-10 + 15 once. NOT
proven: stage 1 via the script (r2 hit the replay-save trap at a slow select cadence; the script now uses the triage's
~4 s cadence), pause → RESUME(A) → RETURN TO TITLE in 360, and the 2-consecutive-run bar. **Next (Sonnet, 15 min of
lock):** `bash scripts/nav360_mac.sh q2a build/w152_q2/w152_q2` then `q2b` (STRICT=1); both VERDICT PASS closes Q2's
route and flips R7-X; if node stage1/stage1_go fails again, bank it as the 360 replay-save defect (hand to Opus).

**Q2b done — PASS (2026-10-12 00:36-01:05, Sonnet seat, drive lock free, no wait, build/w152_q2 unchanged).** `nav360_mac.sh`
VERDICT PASS x2 consecutive (q2a4, q2b: card -> 360 title -> hub -> NORMAL PLAY -> mode/char/shot -> stage 1
(`d76=4` + m02_stg1) -> PAUSE -> RESUME (A) -> pause -> RETURN TO TITLE -> hub -> B -> shell top menu, 0 FATAL/VK_ERROR);
evidence `_local/rc1/q2b/{q2a,q2a2,q2a3,q2a4,q2b,q2n}/` (q2a-q2a3 = script-marker fixes, see NAV_MAP 360 "Q2b"; PNG dump
dirs deleted, shots kept). Inertness: `NOLEVER=1` run q2n = 0 `[nav360]` lines, route PASS on shell markers. The Q2 r2
"replay-save trap" did NOT reproduce at the ~4 s cadence; the unattended-death signature (cred 3->0, slot0 1->0, d76
4->5->6->8, msg=10, st 5->2) was reproduced by simply idling in stage 1 (q2a), so hypothesis = r2 reached stage 1 and
died while its marker (d76=3 ordering bug) was timing out; no new gap opened. Two-line caveat: RETURN TO TITLE goes to
the hub (msg=11), not the module title.

**Sonnet seeds on the Q2 markers (each: own binary name, drive lock, SEED save copy, RT_NAV360=1):**
- *360 stage sweep (Q3-X):* NAV_MAP TRAINING applies to the 360 hub (same shell rows): hub DOWN×2 (`[mcur] 1->2`) + A →
  STAGE SELECT, RIGHT×N, START → MODE → char → shot; assert stage entry by `[nav360] ... field=1` + a stage BGM cue new
  to the run (m02_stg1..5 / boss cues) and shots at entry + 30 s; 10 entries × Original first. Training gives no
  invincibility: bank the replay-save prompt as the end marker (`GameEntry(msg=10,` + `[nav360] st=2`).
- *360 persistence (Q4-X):* settings: hub OPTION change → relaunch with the SAME RT_SAVE (no SEED re-copy) → read back;
  replay: play to the replay-save prompt, A → REPLAY SAVE MENU slot → relaunch → hub REPLAY DATA lists it → play back;
  scores: the 360 Original Ranking attract (node 5) shows the table — shot it before/after. Diff the save dir per step.
- *360 co-op (Q9-X):* nav360 route to node 8, P2 START via FIFO field 4 (`echo "0 0 0 10"`) → `[joinp] ... WILL-JOIN`,
  `[nav360] slot0=1` and both seats' selects → two-ship stage shot; COOP_360_PASS = stage reached with both ships.

**Q7 measured -- ARCADE STAGE SWEEP via route C (2026-10-12, 00:40-03:40, Opus seat, unattended, drive lock; build/w153_control = a fresh
build_mac.sh link of realcomp f7542f9 + futari_decomp 4a3033fa = the current 69-TU state; evidence `_local/rc1/q7/` (steps, shots, gz guest
logs, `rc1_facts_q7.txt`, `contact_q7_stages.png`); route scripts + PREREG in futari_decomp `bank/r23/w153/`).** The training panel's own
options make a scripted clear possible: **Shot Power = Max, Bomb Stock = Infinity, Player Stock = Infinity** (decomp training_config.cpp;
set by menu presses DOWNx3 RIGHTx8 / DOWN RIGHTx8 / DOWN RIGHTx7, UPx5; [trainprobe] msg=18 word1 0x0007FFFF) -- this is the game's infinite
stock, NOT a no-cheat clear and NOT the O4 lever (no RAM poke, no env lever). With autofire (A 12 on / 12 off on the guest-tick clock) + a bomb
every 4 s, **every ORIGINAL stage 1-5 was entered, its boss fought and defeated, and the stage ended**, one cold-boot leg each (stage 2-3 in a
chained leg): entry `[navreal] d76 3->4`, stage BGM ([cuetally] m02_stg1 / m07_stg2 / m08_stg3 / m09_stg4 / m10_stg5), boss BGM (m03_boss
x4, m11_lbs1 on stage 5), the boss-defeat `[fade]`, the TRAINING STAGE RESULTS TALLY, end `d76 4->8` = 136 / 213 / 275 / 305 / 446 s of game
time; then training re-opens its panel (cursor on Start Training) and B returns to the hub. **0 FATAL / VK_ERROR / slowframe / audio-underrun
lines in every leg of the window (30 launches); 3,592-3,601 presents per wall minute; draw census = only the authentic PRESS START strobe (0x2530000,
7 lines per leg).** Also measured: in-stage pause (START) -> A on RESUME -> play continues (every C1 leg; the TRAINING pause menu reads RESUME /
RESTART / OPTION / PREVIOUS MENU); NORMAL PLAY stage 1 game over (3 lives, idle or autofire) -> replay-save prompt -> REPLAY SAVE MENU -> overwrite
slot 01 -> save complete (`replaydata.bin` atomic publish) -> module title -> hub -> REPLAY DATA lists the new replay (83648 Stage1) -> playback
reaches CONTINUE? -> GAME OVER (C7 legs). **NOT reached by script:** a NORMAL PLAY stage clear / its results (3 lives + stage bombs die on stage 1),
continue-by-START, name entry (no ranking score), Maniac / Ultra, the 1-ALL ending (m12_lbs2 / m13_endg never played: training ends at the
stage-5 boss), relaunch read-back of the saved replay -> **owed to the user's hands (Q6: one no-cheat Original 1-ALL per mode, replay saved)
and to Q4 (relaunch read-back).** Findings: (1) autofire into a stage whose entry is logged +-1 present apart is chaotic -> gameplay shots are
not byte-reproducible across legs (stage end t12024 vs t12204 on the same route), so a gameplay route needs input-free segments or outcome
markers, not pixels; (2) [gemsg] stops printing a msg after call#3 and [p0build] after #3 -- long routes must gate on [navreal] st/d76 lines.

*Sonnet seed -- the 360 mirror of route C (Q7-X):* nav360_mac.sh to the 360 HUB (node 6), then this window's TRAINING recipe verbatim (hub
DOWN x2 + A -> panel; DOWN x3 RIGHT x8, DOWN RIGHT x8, DOWN RIGHT x7, UP x5, RIGHT x 2(k-1) for Stage k; A 開始; A) -- assert the panel by shot
and `[trainprobe] msg=18` word1 = 0x0007FFFF; stage entry = `[nav360] ... d76=4` (RT_NAV360=1; [navreal] is blind under abn); autofire A 12/12 +
A+B every 10th press through `bank/r23/w153/drive_w153.sh` F:/U: steps; stop on the first `[fade]` after entry; stage end = `[nav360]` st 5->2;
then B (the panel re-opens itself) -> hub. One cold-boot leg per stage (the re-opened panel keeps its cursor on Start Training: a chained
RIGHT x2 flips 1P/2P Side). Bank shots at entry +4 s, every 30 s, the tally; RC1 cells R4b-X per stage. Then C7-X: NP game over (idle ship, no
autofire) -> replay save -> playback, watching for the 360 replay-save trap (NAV_MAP).

**Q3 [S] FULL-GAME SWEEP via training stage select (G1 part 1).** Goal: every stage start and boss (10 entries) on
Original, Maniac, Ultra, in ARCADE (then XBOX 360 after Q2), with shots at entry + 30 s, error counts, fps.
Inputs: `scripts/boss1/boss1_drive2.sh` (ROUTE=training NRIGHT=0..9), NAV_MAP TRAINING section. PASS = 60 drives,
0 FATAL/VK_ERROR, every shot shows the expected stage/boss (eyeball sheet for the user), fps ≥ 59.9. Model: Sonnet.

**Q4 [S] PERSISTENCE ROUND-TRIP (G3).** Goal: replay save → relaunch → replay list shows it → playback reaches the
same outcome; score register → relaunch → ranking table shows it; both modes (X after Q2). Inputs: NAV_MAP game-over
flows, SAVE_DESIGN.md, the B3 recipe (nav_mac.sh b3write2/b3read2). PASS = files under the save dir change
atomically, read back, playback outcome (game-over frame / score) identical across 2 playbacks. On failure: stop,
bank, hand to an Opus window. Model: Sonnet.

**Q5 [S] RC CHAIN SCRIPT (G5, G6, G10).** Goal: `scripts/rc_chain_mac.sh <tag> <bin_dir>` = app-smoke-equivalent on
a bin copy, modes (with pause/resume shots), swap ×5 with a stage-1 shot after each swap, stagepix, boss plate,
both audits, fdpace, B3, NP + SA game-over chains, continue countdown; one verdict file; `pkill -x` only; also fix
soak_mac.sh / demo_soak_mac.sh / nav_mac.sh kill patterns to `pkill -x`. PASS = chain green on the rc1 probe.
Model: Sonnet.

**Q6 [E] USER ATTENDED SESSION (G1 part 2, G4 eyes, G8 couch, G9).** One sitting, checklist: one Original 1-ALL per
mode with the replay SAVED (that replay becomes the permanent full-game regression asset: Q8), flicker eyes on
title/top menu/card, two-pad co-op stage, pad + remap, F11 fullscreen on the built-in display (ProMotion) and an
external one, Quit. ~90 min of the user's time; can be split per mode.

**Q7 [O→S] XBOX 360 VISUAL GATE (G7).** Design (Opus) a 360 boss/stage plate (head-symmetry + per-push structure
need no oracle) on the Q2 markers, then gate it (Sonnet) on stage 1-5 bosses. PASS = all bosses symmetric/structurally
consistent, stagepix richness in band with ARCADE. Model: Opus then Sonnet.

**Q8 [S] REPLAY REGRESSION (G1 closure).** After Q6: play the user's two 1-ALL replays back on the RC engine,
dump frames at fixed ticks, compare to the first playback (determinism) and to the user's run (outcome). PASS = both
replays reach the ending with identical score; becomes a permanent rung of the Q5 chain. Model: Sonnet.

**Q9 [S] CO-OP + G11 ON THE MAC.** Port day8_2p_validate (P2 = FIFO 4th field) → COOP_arcade_PASS + COOP_360_PASS on
the Mac; one-shot quad census on the w136 press-coincident pair. Model: Sonnet.

**Q10 [S] RC1 CUT (G12).** Only after Q1-Q9 are green and O2-O7 ruled: tag realcomp + decomp pair, rebuild the .app
with VER=0.3.0-rc1 (or the ruled name), rewrite README known issues from §1's allowed list, run Q5 on the bundle
engine, zip, Drive F&F link, SHARED archive copy when the NAS answers on 10.0.0.x, md5 set; Deck follow-on per O3.
Model: Sonnet.

Parallelism: Q2 (Opus, harness code) can run while Q1/Q3/Q4-ARCADE (Sonnet, drives) run only if they never drive
the GPU at the same time — serialize the drives, not the reading. Q6 can happen any time the user is at the Mac.

---

## §5 OPEN RULINGS FOR THE USER

- **RULED 2026-10-11 ~14:10 (was O1) — flicker acceptance:** "clean measurement is good for RC1." Eyes-clean +
  census-clean on the current build closes BACKLOG #0 for RC1 (§1 R15); the 07-26/07-28 compose-1:1 acceptance moves to
  the long-term decomp lane. Note for the record: the census cannot see the present/glass alternation class (07-28,
  Windows RenderDoc); the user's eyes cover that class.
- **O2 Co-op in RC1?** Recommendation: IN (scripted proof is cheap, Q9; the couch session is the only eyes cost).
- **O3 Steam Deck arm.** Recommendation: NOT gating RC1; an RC1-follow AppImage/zip from the same tag, validated by
  `modes_deck.sh` + one Steam-shortcut session including XBOX 360 mode on screen and Steam Input.
- **O4 Full-clear requirement.** Does RC1 require a 1-ALL per mode, and is it yours (Q6) or a scripted one? A scripted
  clear would need a harness-only invincibility lever (guest RAM poke, default off, never in the bundle) — allowed or
  not? Recommendation: your two Original clears with replays saved; no invincibility lever.
- **O5 Difficulty scope.** Recommendation: 1-ALL on Original only; Maniac/Ultra = every stage+boss reached (Q3).
- **O6 Distribution (standing rule, restated for sign-off).** The port ships ZERO game content publicly; F&F bundles
  carry your dump and go only to people who own the game (Drive F&F link); the SHARED share holds the archive copy.
  Who gets RC1, and is the Drive route still the channel?
- **O7 Version name + freeze.** `0.3.0-rc1` (recommended) vs `1.0.0-rc1`; and the freeze rule in §1 (decomp
  promotions continue on main; the bundle is only re-cut from a tagged realcomp+decomp pair after the Q5 chain).
- Carried from the decomp ledger, not RC1-blocking: PNG history purge (ruled NO today), band-tightening (ruled today:
  Ruling A), task_w106 delete (ruled YES today).
