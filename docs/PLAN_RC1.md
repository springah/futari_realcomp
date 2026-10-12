# PLAN — RC1 for the two hosted modes: ARCADE (Ver 1.5 Original) + XBOX 360 MODE

Reading order: **§0 scorecard** (state + what is left) -> **§6 freeze & ship plan** (how it gets cut) -> §1 definition -> §2 per-criterion detail -> §3 gaps -> §4 queue + measurement log -> §5 rulings. Tidied 2026-10-12 (docs seat); no evidence pointer was removed -- superseded cells are kept verbatim in the collapsed blocks of §2 and §3 and in §4.2.

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

## §0 RC1 SCORECARD (2026-10-12; engine `main` @ d3c9b23)

This is the decision page; §1-§5 are the definition and the evidence behind it. Status legend: **PASS** (bar met, measured) ·
**PASS-WITH-NOTE** (met with a named residual that does not block) · **USER-HANDS** (the scripted half is done or impossible;
only the user's play/eyes can close it) · **OPEN** (a scripted/agent item remains, queue id given) · **N/A**. Where a row
has both a user part and a scripted part, the row shows the blocking one and the other is in the Note.

**Counts** (21 criteria per mode): ARCADE: PASS 9 / PASS-WITH-NOTE 5 / USER-HANDS 5 / OPEN 2 / N/A 0. XBOX 360 MODE: PASS 9 / PASS-WITH-NOTE 3 / USER-HANDS 5 / OPEN 4 / N/A 0.

**Caveat that applies to every PASS:** nothing below was measured on the commit that will be frozen. The measurements
ran on probe builds between db1df9c and 939b638; d3c9b23 (KSTUB-OVERCLEAR fix, no screen changed on the probe A/B) is on
main but not in the user's .app, and the .app on disk predates the G-START fix (619a190). The frozen bundle therefore
has to pass the §6 smoke before any row here counts for the release.

### 0.1 ARCADE (1.5 Original) -- modeIdx 0, `futari_game_normal.dylib`

| # | Criterion | Status | Window | Evidence | Engine commit measured on | Note |
|---|---|---|---|---|---|---|
| R1 | Boot, 2/2 modules bound | **PASS** | M1 + app smoke 10-11 | `build/app_smoke_1011c.log`; `_local/rc1/nav/rc1m_VERDICT.txt` | db1df9c-era 68-TU .app (10-11 13:28) | 2/2 bound, 0 FATAL, 59.94 Hz |
| R2 | Title -> mode -> module | **PASS** | M1 10-11; b4 10-05 | `_local/nav_mac/b4_VERDICT.txt`; `_local/rc1/nav/` | db1df9c-era 68-TU .app (10-11 13:28) |  |
| R3 | Every hosted menu path | **PASS-WITH-NOTE** | decomp gates w143-w148; Q7/Q3 legs | futari_decomp NOTE_campaign_decomp.md w143-w148; NAV_MAP.md; `_local/rc1/q7/` | decomp gate routes w143-w148 (per-route builds) | hub, NORMAL PLAY+CONFIG, TRAINING, SA decline dialog, REPLAY list, every OPTION sub-panel driven on the Mac by the decomp gates (byte-identical shots), not by an RC1 window; re-confirm on the frozen bundle |
| R4a | Stage 1 reached + playable | **PASS** | M1; Q7 | `_local/rc1/q7/` | f7542f9 + decomp 4a3033fa (build/w153_control) |  |
| R4b | Stages 2-5 + bosses, all difficulties | **PASS** | Q7 10-12 (Original); Q3-sweep 10-12 (Maniac, Ultra) | `_local/rc1/q7/` (rc1_facts_q7.txt, contact_q7_stages.png); _local/rc1/q3s/ (REPORT_q3s.md, rc1_facts_q3s.txt, contact_q3s.png) | Original: f7542f9 + decomp 4a3033fa (build/w153_control); Maniac/Ultra: d3c9b23 (build/q3s_probe) | Original stages 1-5 each reached + boss + stage end (136/213/275/305/446 s); Maniac + Ultra stages 1-5 each reached + boss + stage end, 10/10 legs, 0 errors (Ultra stage 5 boss needs ~1,300 s of infinite-stock autofire); via TRAINING infinite-stock options (not a no-cheat clear), difficulty = TRAINING Mode row; stage 5 = m11_lbs1 only |
| R4c | Full clear (1-ALL + ending) | **USER-HANDS** | Q6 (user) | -- (no record of a port 1-ALL in any doc) | - | no-cheat Original 1-ALL + ending, replay saved; m12_lbs2/m13_endg never played |
| R5a | Settings round-trip | **PASS** | Q3 10-12 | `_local/rc1/q3/{A_p1a,A_p1b}/`; REPORT_q3.md | w152_q2 binary (pre-619a190) | Picture preset + Bomb Stock; savegame.bin diff = 3 bytes; read back on relaunch |
| R5b | High score / ranking persists | **USER-HANDS** | Q3 10-12 (BLOCKED-FOR-SCRIPT) | `_local/rc1/q3/A_p2/`; REPORT_q3.md | w152_q2 binary (pre-619a190) | idle death scores 0 -> no register prompt; table (1st 6,880,571 ... ) not in savegame.bin/replaydata.bin; play past the 5th row, enter name, relaunch, read Original Ranking |
| R5c | Replay save -> playback | **PASS** | Q3 10-12 | `_local/rc1/q3/{A_p3d,A_p3f,A_p3g}/`; scripts/markframes.py | w152_q2 binary (pre-619a190) | replaydata.bin 2444->4062; relaunch lists it; 2 playbacks identical timeline within one 30-frame step |
| R6 | Game-over flows | **PASS-WITH-NOTE** | Q7 10-12 (C7 legs); b3 10-04 | `_local/rc1/q7/`; NAV_MAP.md | f7542f9 + decomp 4a3033fa (build/w153_control) | NP game over -> replay-save prompt -> save/decline -> module title -> hub PASS; USER-HANDS part: NP stage clear + results, continue-by-START, name entry; SA game-over chain -> queue id Q5 (rc_chain) Q5 10-12 (d3c9b23, q5c_probe): SA chain PASS (sign-in dialog -> A:OK -> SCORE ATTACK submenu -> offline SA stage 1 -> idle death -> replay B -> register B -> cancelled-OK A -> module TITLE, then START -> hub); NP idle death -> CONTINUE? 9..0 countdown -> game-over -> replay prompt measured; ARCADE continue-by-START is FLAKY: START during the countdown opened the PAUSE menu on the first press in 3 of 4 tries (continued once) and a continued run did not die again in 300 s (second-death leg BLOCKED-FOR-SCRIPT) -> defect candidate DC-2 in `_local/rc1/q5c/` (REPORT_q5c.md, rc1_facts_q5c.txt, contact_q5c.png) |
| R7 | Pause / resume / restart / return | **PASS** | Q7 10-12; Q3 A_p4 | `_local/rc1/q7/`; `_local/rc1/q3/A_p4/` | f7542f9 + decomp 4a3033fa (build/w153_control) | RESUME (A) and RETURN TO TITLE PASS; RESTART unmeasured -> Q5 Q5 10-12: RESTART PASS (TRAINING pause -> RESTART -> confirm A -> d76 4->3->4, stage BGM again) + PREVIOUS MENU (training) / RETURN TO TITLE (NP) -> hub; defect candidate DC-1 (second TRAINING start dead) is outside this row -- `_local/rc1/q5c/` (REPORT_q5c.md, rc1_facts_q5c.txt, contact_q5c.png) |
| R8 | Mode swap, >= 5 cycles | **PASS** | M1 10-11 (1 cycle) | `_local/rc1/nav/rc1m_VERDICT.txt` | db1df9c + decomp a959478f (build/rc1_probe) | 1 cycle PASS (residue=0 x2); >= 5 cycles with stage-1 shots -> queue id Q5 (G6) Q5 10-12 (f5_A, d3c9b23): 5 cycles ARCADE<->XBOX 360 in ONE process, [modswap] #2..#10 DONE alternate reco_abnormal/reco_normal, residue=0 x9, [modreg] 2/2 once, hub reached every time (both modules), RSS 398 -> 514 -> ... plateau 702-704 MB (<= 740), 0 FATAL/VK_ERROR/slowframe/underrun -- `_local/rc1/q5c/` (REPORT_q5c.md, rc1_facts_q5c.txt, contact_q5c.png) |
| R9 | Co-op | **USER-HANDS** | Q3 10-12 (scripted PASS) | `_local/rc1/q3/A_p4/` | w152_q2 binary (pre-619a190) | P2 START via RT_PAD_FIFO 4th field -> [joinp] WILL-JOIN, two ships + dual HUD, pause/resume/return; couch two-pad session owed (Q6) |
| R10 | Input (pads, remap, fullscreen) | **USER-HANDS** | -- (keyboard PASS earlier) | PLAN_macos_bringup.md; README | - | pads per class, P2 pad, remap persistence, F11 + Retina/ProMotion; scripted remap round-trip also owed (Q5/G9) Q5 10-12: scripted remap round-trip PASS (OPTION -> Controller Setting: SHOT A -> B, BOMB B -> A; savegame.bin b07c47.. -> fe4dbb.. persisted; relaunch panel shows SHOT=B BOMB=A; B held = shot stream, single A = bomb; Default Setting restores the icons); pads per class, P2 pad, F11 stay the user's -- `_local/rc1/q5c/` (REPORT_q5c.md, rc1_facts_q5c.txt, contact_q5c.png) |
| R11 | Audio | **PASS** | RC1 M2/M3 10-11; RT_AUDIODUMP 10-03 | PLAN_macos_bringup.md; `_local/rc1/rc1_*/soak.txt` | db1df9c + decomp a959478f (build/rc1_probe) | guest-native CoreAudio sink; 0 underruns / 0 sink stalls in 10 min; content by ear is part of the eyes/ears pass |
| R12 | 60 fps pacing | **PASS** | Q1, Q7 10-11/12 | `_local/rc1/q1/REPORT_q1.md`; `q7/` | db1df9c + decomp a959478f (build/rc1_probe) | 3,600 frames/min, 0 slowframe; 3,592-3,601 presents/min in stage legs |
| R13 | Soak: crash-free + memory bounded (plateau <= 740 MB) | **PASS-WITH-NOTE** | Q1 + Q5 + Q6 10-11 | `_local/rc1/q1/REPORT_q1.md`, `q5/REPORT_q5.md`, `q6/REPORT_q6.md` | db1df9c + decomp a959478f (build/rc1_probe) | shell 30 min 285->292; ARCADE 60 min RSS 426 (min 2)/572 (10)/708 (25)/719 (60), slope 0.32 MB/min last 30 min, heap high-water pinned 496 MB, 0 alloc failure -> BOUNDED (ruled); Darwin page-release fix post-RC1 (G5-fix) |
| R14 | Visual fidelity gates | **PASS-WITH-NOTE** | b3/10-05 gates; audits | `_local/boss1_mac/gates_vbsleep.txt` | beta-3 bundle 10-04/10-05 (host 79b314e) | stagepix + boss plate all-game sweep PASS, both audits 0 DRIFT/0 MISSING (18-TU era; re-run on the frozen bundle); eyes pass for FNF-class defects = USER-HANDS Q5 10-12 on the bundle engine (q5c_probe d3c9b23, decomp 6fc61986): stagepix PASS (identical-link control), both audits --selftest PASS + sweep: constpool 0 DRIFT/0 NOTE_MISMATCH/0 UNANCHORED; regcontract 11 MISSING (all compose_frame_walks.cpp r10 upper-bound rows, banked); boss plate gate (famk1) on the dylib engine: RAN, pixel witness equal (sym p50 0.861 vs 0.862), structural NO-VERDICT after RETRIES=2 (lockstep coin flip, boss y 345.69 vs 343.03) -- rerun with more RETRIES for a PASS -- `_local/rc1/q5c/` (REPORT_q5c.md, rc1_facts_q5c.txt, contact_q5c.png) |
| R15 | Flicker | **USER-HANDS** | Q1 10-11 (census); user eyes 10-11 | `_local/rc1/q1/REPORT_q1.md`; NOTE_fnf_shell_defects.md 2026-10-05 | db1df9c + decomp a959478f (build/rc1_probe) | census PASS: 0 dropouts in 30 min shell + 20 min + 25 min ARCADE; 6/6 hand-overs only the authentic PRESS START strobe; eyes retest on the frozen bundle incl. the G-START check |
| R16 | Quit | **PASS** | app smoke 10-11 | `build/app_smoke_1011c.log` | db1df9c-era 68-TU .app (10-11 13:28) | Quit leaves no process, save read back |
| R17 | Packaging | **OPEN** | -- (Q10) | PLAN_beta3_mac.md todo 7; sec. 6 below | - | VER still 0.2.0-beta3, README is BETA 3 text; SHARED copy owed (NAS offline since 10-07 renumber) |

### 0.2 XBOX 360 MODE -- modeIdx 1, `futari_game_abn.dylib`

| # | Criterion | Status | Window | Evidence | Engine commit measured on | Note |
|---|---|---|---|---|---|---|
| R1 | Boot, 2/2 modules bound | **PASS** | M1 + app smoke 10-11 | same | db1df9c-era 68-TU .app (10-11 13:28) | cold boot ~40 s |
| R2 | Title -> mode -> module | **PASS** | M1 10-11; Q2b 10-12 | `_local/rc1/q2b/` | 87c21ea + RT_NAV360 lever (build/w152_q2, decomp a54c40a8) | card LEFT + dwell; lands at module TITLE, not MODE SELECT |
| R3 | Every hosted menu path | **OPEN** | Q2 10-11 / Q2b 10-12; Q3; Q7-360 | `_local/rc1/q2/r2/`, `q2b/{q2a4,q2b}/`, `q3/X_*`, `q7x/` | 87c21ea + RT_NAV360 lever (build/w152_q2, decomp a54c40a8) | PASS: NORMAL PLAY route x2, TRAINING (Q7-360), REPLAY DATA list (Q3), OPTION/NP CONFIG settings (Q3). NOT driven: SCORE ATTACK decline dialog, remaining OPTION sub-panels -> queue id Q3-X tour Q5 10-12: SCORE ATTACK sign-in decline dialog + the offline SA submenu and its game-over chain DRIVEN in x360 (identical to ARCADE), OPTION -> Controller Setting panel driven; remaining OPTION sub-panels still Q3-X. |
| R4a | Stage 1 reached + playable | **PASS** | M1; Q7-360 | `_local/rc1/q7x/` | 939b638 (build/q7x_probe, incl. 619a190) |  |
| R4b | Stages 2-5 + bosses, all difficulties | **PASS** | Q7-360 10-12 (Original); Q3-sweep 10-12 (Maniac, Ultra) | `_local/rc1/q7x/` (REPORT_q7x.md, contact_q7x_stages.png); _local/rc1/q3s/ (REPORT_q3s.md, rc1_facts_q3s.txt, contact_q3s.png) | Original: 939b638 (build/q7x_probe); Maniac/Ultra: d3c9b23 (build/q3s_probe) | Original stages 1-5 each reached + boss + tally + end (134/209/287/307/450 s); Maniac + Ultra stages 1-5 each reached + boss + stage end, 10/10 legs, 0 errors (+ the known card-LEFT DROPOUT per leg); Ultra stage 5 end at 1,624 s |
| R4c | Full clear (1-ALL + ending) | **USER-HANDS** | Q6 (user) | -- | - | same, in XBOX 360 MODE |
| R5a | Settings round-trip | **PASS** | Q3 10-12 | `_local/rc1/q3/{X_p1a,X_p1b}/` | w152_q2 binary (pre-619a190) | same 3 bytes, shell-owned |
| R5b | High score / ranking persists | **USER-HANDS** | Q3 10-12 (not run separately) | REPORT_q3.md | w152_q2 binary (pre-619a190) | same shell/save path |
| R5c | Replay save -> playback | **PASS** | Q3 10-12 | `_local/rc1/q3/{X_L1,X_L2}/` | w152_q2 binary (pre-619a190) | same save sizes; 2 playbacks identical [nav360] timelines; playback ends on REPLAY LOAD MENU |
| R6 | Game-over flows | **PASS-WITH-NOTE** | Q3 10-12 (replay save); b3 10-04 | `_local/rc1/q3/X_*`; PLAN_beta3_mac.md todo 4 | w152_q2 binary (pre-619a190) | NP game over -> replay-save PASS; same USER-HANDS part; SA chain -> Q5; 360 "replay-save trap" of Q2 r2 did not reproduce (open ruling) Q5 10-12: x360 continue-by-START PASS 3/3 (START at CONTINUE 6-8 -> play resumes, cred 0->3, 2nd death -> cred 3..0 -> d76 4->5->6->8 -> replay prompt B -> title -> hub); SA chain PASS both prompts; no name entry (0 score) -- `_local/rc1/q5c/` (REPORT_q5c.md, rc1_facts_q5c.txt, contact_q5c.png) |
| R7 | Pause / resume / restart / return | **PASS** | Q2b 10-12 x2 | `_local/rc1/q2b/{q2a4,q2b}/` | 87c21ea + RT_NAV360 lever (build/w152_q2, decomp a54c40a8) | pause, RESUME (A), RETURN TO TITLE (lands on hub, msg=11) PASS; RESTART / OPTION-in-pause unmeasured -> Q5 Q5 10-12: RESTART PASS in x360 (same d76=4 -> 3 -> 4 re-entry), pause RESUME/RETURN already PASS -- `_local/rc1/q5c/` (REPORT_q5c.md, rc1_facts_q5c.txt, contact_q5c.png) |
| R8 | Mode swap, >= 5 cycles | **PASS** | M1 10-11 (1 cycle) | same | db1df9c + decomp a959478f (build/rc1_probe) | same cycle; >= 5 -> Q5 same 5-cycle run (one process covers both modules) -- `_local/rc1/q5c/` (REPORT_q5c.md, rc1_facts_q5c.txt, contact_q5c.png) |
| R9 | Co-op | **USER-HANDS** | Q4b 10-12 (scripted PASS x2) | `_local/rc1/q4b/{v3_1,v3_3}/`; REPORT_q4b.md | 9b9dd8c (build/q4b_probe, incl. 619a190) | [joinp] ENTER slot=1 + [xinput] P2 buttons=0x0010; couch session owed (Q6) |
| R10 | Input (pads, remap, fullscreen) | **USER-HANDS** | -- | same | - | same Q5 10-12: scripted remap round-trip PASS in x360 (same bytes, same panel) -- `_local/rc1/q5c/` (REPORT_q5c.md, rc1_facts_q5c.txt, contact_q5c.png) |
| R11 | Audio | **PASS-WITH-NOTE** | M3 10-11; Q1; Q7-360 | `_local/rc1/q1/`, `q7x/` | db1df9c + decomp a959478f (build/rc1_probe) | 0 underruns; content by ear only on Windows beta 2 -> covered by the eyes/ears pass |
| R12 | 60 fps pacing | **PASS** | Q1, Q7-360 | `_local/rc1/q1/`; `q7x/` | 939b638 (build/q7x_probe, incl. 619a190) | 3,600/min; 3,575-3,627 presents/min in stage legs |
| R13 | Soak: crash-free + memory bounded (plateau <= 740 MB) | **PASS** | Q1 10-11 | `_local/rc1/q1/REPORT_q1.md` | db1df9c + decomp a959478f (build/rc1_probe) | 20 min, RSS 545->619 flat from min ~5; 0 FATAL/VK_ERROR/slow/underruns |
| R14 | Visual fidelity gates | **PASS-WITH-NOTE** | Q7v 10-12 | `_local/rc1/q7v/` (REPORT_q7v.md, rc1_facts_q7v.txt, contact_q7v.png) | d3c9b23 (build/q7v_probe) | stagepix360 PASS (26304 colours / 25.1 edges vs control 26653 / 25.0; ARCADE 24081 / 28.1); boss plate PASS (pixel p90 0.902 vs 0.912, structural 46/46 lockstep frames identical); NOTE: the 360 module links no objaction_queue TU (no TU A/B to catch), eyes pass for FNF-class defects = USER-HANDS |
| R15 | Flicker | **USER-HANDS** | Q1 10-11 (census); user eyes | same | db1df9c + decomp a959478f (build/rc1_probe) | census PASS-WITH-NOTE: one deterministic unattributed card-LEFT loss (base 0x34E0000, len=1, LEFT+13 presents, 7/7); eyes retest on the frozen bundle |
| R16 | Quit | **PASS** | app smoke 10-11; b3 10-04 | same | db1df9c-era 68-TU .app (10-11 13:28) | same engine |
| R17 | Packaging | **OPEN** | -- (Q10) | same | - | same |

### 0.3 What stands between us and RC1

Two columns. (A) is work an agent seat can do unattended; (B) is verbatim from the measurements and needs the user.

| (A) Scripted / agent items still OPEN (queue id) | (B) USER-HANDS (verbatim from the measurements) |
|---|---|
| ~~Q3 sweep~~ DONE 2026-10-12 (R4b PASS both modes, d3c9b23) | Eyes pass on the current .app, including the G-START check (START pressed on the hub and in OPTION must not start the game behind the shell) (R15, R14 FNF-class) |
| **Q5 rc_chain** -- DONE 2026-10-12 (`scripts/rc_chain_mac.sh`; REPORT `_local/rc1/q5c/REPORT_q5c.md`): swap x5 PASS, RESTART PASS, SA chain PASS, remap PASS, 360 continue PASS; OPEN from it: DC-1 second TRAINING start dead (both modes), DC-2 ARCADE START-at-CONTINUE opens PAUSE; was:  swap x5 with a stage-1 shot after each (R8, G6), RESTART and continue countdown (R7/G10), SA game-over chain (R6), scripted remap round-trip (R10/G9), stagepix + boss plate + audits on the bundle engine (R14), pkill -x only | Ranking entry per mode: "play Original past the 5th row, enter a name, relaunch, read Original Ranking" (R5b) |
| ~~Q7 360 visual gate~~ DONE 2026-10-12 (stage-1 stagepix + boss plate PASS, `_local/rc1/q7v/`; bosses 2-5 not plated) | No-cheat Original 1-ALL + ending with the replay saved, per mode (R4c; Q6) |
| **Q3-X tour** -- 360 SCORE ATTACK decline dialog and the remaining OPTION sub-panels (R3-X) | Normal Play stage clear + results, continue-by-START (not driven), name entry (R6) |
| ~~Q9 / G11~~ DONE 2026-10-12 (positive control 60/60 + 60/60; card-LEFT quad and w136 pair both AUTHENTIC, `_local/rc1/q7v/`) | Maniac / Ultra play (only the stage+boss reach is scripted) |
| **Q8 replay regression** -- after the user's two 1-ALL replays exist: play back on the RC engine, same ending + score (R4c closure) | Couch two-pad co-op session (R9, both modes) |
| **Q10 RC cut** -- VER bump, README rewrite, tag, rebuild, zip, md5, share copy (R17; §6) | Pads per class, P2 pad, in-game remap persistence, F11 fullscreen on the built-in (ProMotion) and an external display, keyboard-only session (R10, G9) |
| **Frozen-bundle smoke** -- `scripts/app_smoke_mac.sh` + the Q1 census criterion on the cut .app (§6.5) | Sign-off on the frozen bundle (§6.5) |

Not on the RC1 path (A-side, post-RC1): G5-fix Darwin page release, Q1b shadow-mode harness, Phase-2 compositor decomp.

### 0.4 Rulings recorded

- **2026-10-11 ~14:10 -- flicker:** "clean measurement is good for RC1." Eyes-clean + census-clean on the RC build closes BACKLOG #0 for RC1 (§1 R15); compose 1:1 moves to the long-term decomp lane. The census cannot see the present/glass alternation class (07-28 Windows RenderDoc); the user's eyes cover it.
- **2026-10-11 -- memory = bounded:** R13 re-baselined to plateau <= 740 MB, no allocation failure over 60 min; the Darwin page-release fix (G5-fix) is post-RC1 (Q6 evidence).
- **Co-op is IN RC1** (scripted proof both modes done; couch session is the user's).
- **Steam Deck/Linux is a follow-on**, rebuilt from the RC1 tag; it does not gate RC1.
- **Clears are the user's, Original only, no cheats:** one Original 1-ALL per mode with the replay saved; no invincibility lever; Maniac/Ultra = every stage + boss reached.
- **Distribution = the SHARED release share on the NAS, NOT Google Drive** (supersedes PLAN_beta3 todo 7's Drive route). F&F only; the public form ships zero game content.
- **Version `0.3.0-rc1` + the freeze rule of §6.2.**

(The last five were relayed to this docs seat in the 2026-10-12 brief; the repo carries their recommendations in §5, now annotated, but not the user's original wording or exact time.)

### 0.5 Open rulings

1. **The 5 UNDER kernel stubs that feed the game garbage** (docs/AUDIT_kstub_sizes.md §3): `VdGetCurrentDisplayInformation` (X_DISPLAY_INFO 0x58 read at 820AB528/820B1E80/820B22D0 into device display w/h), `VdGetCurrentDisplayGamma` (820A9CA8), `VdGetSystemCommandBuffer` (820A5408, feeds the VdSwap hook argument), `ExGetXConfigSetting` (time-zone names are stack garbage), `XamUserGetXUID` (online; out of scope under no-Xbox-LIVE). Plus 6 UNKNOWN (XamAlloc, RtlFillMemoryUlong, RtlMultiByteToUnicodeN, RtlUnicodeToMultiByteN, RtlCaptureContext, XamGetExecutionId). **Recommendation: document as known-divergence in the RC1 README/NOTE and fix post-RC1, one stub per window with a pixel gate (B1/B4 + stagepix) -- the 2026-07-22 RT_HDMODE A/B blacked out the menu when display-info fields took true HD values, so a blind fix is the riskier path to RC1.** Options: (a) as recommended, (b) fix before RC1 with their own A/B windows.
2. **360 START-wire wrong address (side finding of G-START, NOTE_fnf_shell_defects.md 2026-10-12):** the RT_STARTWIRE hook writes the reco_normal EXCH address; reco_abnormal .data sits +0x60 higher (NAV_MAP), so in the 360 module the wire is probably inert/misaddressed. No leak was observed in 360 (bug4_x360, fix4_x360) and every 360 drive started via the ordinary pad path. Recommendation: leave for RC1, record as a known divergence, dshift-rebase the address post-RC1.
3. **Maniac/Ultra bar:** §1 R4 asks for stage+boss reach on all three difficulties; O5 recommends it. Confirm that the scripted Q3 sweep (not a user clear) satisfies it.
4. **Unattributed deterministic losses:** the 360 card-LEFT quad (0x34E0000, len=1, 7/7) and the w136 menu-atlas pair (G11, base 0x49C4000). Both are deterministic and the user has not reported them; recommendation: accept as PASS-WITH-NOTE for RC1, attribute in Q9. **[Q9 10-12: both attributed AUTHENTIC (game-issued stream gaps; renderer, nvk recorder and decomp layer excluded) -- `_local/rc1/q7v/`.]**
5. **Q2 r2 "replay-save trap" (360):** unattributed; did not reproduce at the ~4 s cadence; hypothesis = an ordering bug in the script marker, not a game defect. Accept as closed unless it recurs on the frozen bundle.
6. **Allowed-known-issues text for the README** (§1 list) -- confirm, and add the item-1 and item-2 divergences if accepted.
7. **ARCADE RSS discrepancy:** the 10-05 bundle's ps-RSS read 202-425 MB while the same heap trajectory shows a 496 MB high-water (unresolved, Q5). Not blocking under the bounded ruling; note only.

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
| R13 | Soak | crash-free: shell title+top menu 30 min; ARCADE demo 20 min; XBOX 360 module 20 min; memory **bounded (plateau ≤ 740 MB, no alloc failure over 60 min; Darwin page-release fix post-RC1)** (RULED 2026-10-11, re-baselined from "RSS flat after minute ~15"; ARCADE plateaus at the 512 MB guest-heap ceiling, Q6; G5-fix = post-RC1); 0 FATAL / VK_ERROR |
| R14 | Visual fidelity | stage pixel gate + boss plate gate PASS (ARCADE today; XBOX 360 needs its own); no OPEN user-reported defect in FNF-x class |
| R15 | Flicker | **USER RULING 2026-10-11 ~14:10: "clean measurement is good for RC1."** BACKLOG #0 closes for RC1 on a pre-registered measurement on the RC build: user eyes clean + the w136 draw census (RVK_DRAWCENSUS=2) clean over the soak in BOTH modes = zero DROPOUT-CONFIRMED outside named classes that are SHOWN deterministic (identical frame/base/v0 across legs and binaries); the decomp-grounded compose 1:1 leaves the RC1 gate for the long-term decomp lane |
| R16 | Quit | app-menu Quit and window close leave no process; save intact |
| R17 | Packaging | VER bumped (proposal `0.3.0-rc1`), README rewritten for RC (known issues current, no beta text), Gatekeeper steps, every Mach-O minos 13.0, md5 recorded, F&F only; distribution = the SHARED release share (ruled; not Google Drive) |

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

## §2 WHERE EACH MODE STANDS (2026-10-12)

Same data as §0, one row per criterion, both modes side by side. Every cell reads `STATUS · window · pointer — note`; the commit each was measured on is in §0.1/§0.2. Status vocabulary as §0. (The pre-tidy cells, with their full history, are kept verbatim below.)

| # | Item | ARCADE (status · window · pointer) | XBOX 360 (status · window · pointer) |
|---|---|---|---|
| R1 | Boot, 2/2 modules bound | **PASS** · M1 + app smoke 10-11 · `build/app_smoke_1011c.log`; `_local/rc1/nav/rc1m_VERDICT.txt` — 2/2 bound, 0 FATAL, 59.94 Hz | **PASS** · M1 + app smoke 10-11 · same — cold boot ~40 s |
| R2 | Title -> mode -> module | **PASS** · M1 10-11; b4 10-05 · `_local/nav_mac/b4_VERDICT.txt`; `_local/rc1/nav/` | **PASS** · M1 10-11; Q2b 10-12 · `_local/rc1/q2b/` — card LEFT + dwell; lands at module TITLE, not MODE SELECT |
| R3 | Every hosted menu path | **PASS-WITH-NOTE** · decomp gates w143-w148; Q7/Q3 legs · futari_decomp NOTE_campaign_decomp.md w143-w148; NAV_MAP.md; `_local/rc1/q7/` — hub, NORMAL PLAY+CONFIG, TRAINING, SA decline dialog, REPLAY list, every OPTION sub-panel driven on the Mac by the decomp gates (byte-identical shots), not by an RC1 window; re-confirm on the frozen bundle | **OPEN** · Q2 10-11 / Q2b 10-12; Q3; Q7-360 · `_local/rc1/q2/r2/`, `q2b/{q2a4,q2b}/`, `q3/X_*`, `q7x/` — PASS: NORMAL PLAY route x2, TRAINING (Q7-360), REPLAY DATA list (Q3), OPTION/NP CONFIG settings (Q3). NOT driven: SCORE ATTACK decline dialog, remaining OPTION sub-panels -> queue id Q3-X tour |
| R4a | Stage 1 reached + playable | **PASS** · M1; Q7 · `_local/rc1/q7/` | **PASS** · M1; Q7-360 · `_local/rc1/q7x/` |
| R4b | Stages 2-5 + bosses, all difficulties | **OPEN** · Q7 10-12 (Original done) · `_local/rc1/q7/` (rc1_facts_q7.txt, contact_q7_stages.png) — Original stages 1-5 each reached + boss + stage end (136/213/275/305/446 s), via TRAINING infinite-stock options (not a no-cheat clear); Maniac/Ultra NOT driven -> queue id Q3 (sweep); stage 5 = m11_lbs1 only | **OPEN** · Q7-360 10-12 (Original done) · `_local/rc1/q7x/` (REPORT_q7x.md, contact_q7x_stages.png) — Original stages 1-5 each reached + boss + tally + end (134/209/287/307/450 s); Maniac/Ultra NOT driven -> Q3 sweep |
| R4c | Full clear (1-ALL + ending) | **USER-HANDS** · Q6 (user) · -- (no record of a port 1-ALL in any doc) — no-cheat Original 1-ALL + ending, replay saved; m12_lbs2/m13_endg never played | **USER-HANDS** · Q6 (user) · -- — same, in XBOX 360 MODE |
| R5a | Settings round-trip | **PASS** · Q3 10-12 · `_local/rc1/q3/{A_p1a,A_p1b}/`; REPORT_q3.md — Picture preset + Bomb Stock; savegame.bin diff = 3 bytes; read back on relaunch | **PASS** · Q3 10-12 · `_local/rc1/q3/{X_p1a,X_p1b}/` — same 3 bytes, shell-owned |
| R5b | High score / ranking persists | **USER-HANDS** · Q3 10-12 (BLOCKED-FOR-SCRIPT) · `_local/rc1/q3/A_p2/`; REPORT_q3.md — idle death scores 0 -> no register prompt; table (1st 6,880,571 ... ) not in savegame.bin/replaydata.bin; play past the 5th row, enter name, relaunch, read Original Ranking | **USER-HANDS** · Q3 10-12 (not run separately) · REPORT_q3.md — same shell/save path |
| R5c | Replay save -> playback | **PASS** · Q3 10-12 · `_local/rc1/q3/{A_p3d,A_p3f,A_p3g}/`; scripts/markframes.py — replaydata.bin 2444->4062; relaunch lists it; 2 playbacks identical timeline within one 30-frame step | **PASS** · Q3 10-12 · `_local/rc1/q3/{X_L1,X_L2}/` — same save sizes; 2 playbacks identical [nav360] timelines; playback ends on REPLAY LOAD MENU |
| R6 | Game-over flows | **PASS-WITH-NOTE** · Q7 10-12 (C7 legs); b3 10-04 · `_local/rc1/q7/`; NAV_MAP.md — NP game over -> replay-save prompt -> save/decline -> module title -> hub PASS; USER-HANDS part: NP stage clear + results, continue-by-START, name entry; SA game-over chain -> queue id Q5 (rc_chain) | **PASS-WITH-NOTE** · Q3 10-12 (replay save); b3 10-04 · `_local/rc1/q3/X_*`; PLAN_beta3_mac.md todo 4 — NP game over -> replay-save PASS; same USER-HANDS part; SA chain -> Q5; 360 "replay-save trap" of Q2 r2 did not reproduce (open ruling) |
| R7 | Pause / resume / restart / return | **PASS-WITH-NOTE** · Q7 10-12; Q3 A_p4 · `_local/rc1/q7/`; `_local/rc1/q3/A_p4/` — RESUME (A) and RETURN TO TITLE PASS; RESTART unmeasured -> Q5 | **PASS-WITH-NOTE** · Q2b 10-12 x2 · `_local/rc1/q2b/{q2a4,q2b}/` — pause, RESUME (A), RETURN TO TITLE (lands on hub, msg=11) PASS; RESTART / OPTION-in-pause unmeasured -> Q5 |
| R8 | Mode swap, >= 5 cycles | **OPEN** · M1 10-11 (1 cycle) · `_local/rc1/nav/rc1m_VERDICT.txt` — 1 cycle PASS (residue=0 x2); >= 5 cycles with stage-1 shots -> queue id Q5 (G6) | **OPEN** · M1 10-11 (1 cycle) · same — same cycle; >= 5 -> Q5 |
| R9 | Co-op | **USER-HANDS** · Q3 10-12 (scripted PASS) · `_local/rc1/q3/A_p4/` — P2 START via RT_PAD_FIFO 4th field -> [joinp] WILL-JOIN, two ships + dual HUD, pause/resume/return; couch two-pad session owed (Q6) | **USER-HANDS** · Q4b 10-12 (scripted PASS x2) · `_local/rc1/q4b/{v3_1,v3_3}/`; REPORT_q4b.md — [joinp] ENTER slot=1 + [xinput] P2 buttons=0x0010; couch session owed (Q6) |
| R10 | Input (pads, remap, fullscreen) | **USER-HANDS** · -- (keyboard PASS earlier) · PLAN_macos_bringup.md; README — pads per class, P2 pad, remap persistence, F11 + Retina/ProMotion; scripted remap round-trip also owed (Q5/G9) | **USER-HANDS** · -- · same — same |
| R11 | Audio | **PASS** · RC1 M2/M3 10-11; RT_AUDIODUMP 10-03 · PLAN_macos_bringup.md; `_local/rc1/rc1_*/soak.txt` — guest-native CoreAudio sink; 0 underruns / 0 sink stalls in 10 min; content by ear is part of the eyes/ears pass | **PASS-WITH-NOTE** · M3 10-11; Q1; Q7-360 · `_local/rc1/q1/`, `q7x/` — 0 underruns; content by ear only on Windows beta 2 -> covered by the eyes/ears pass |
| R12 | 60 fps pacing | **PASS** · Q1, Q7 10-11/12 · `_local/rc1/q1/REPORT_q1.md`; `q7/` — 3,600 frames/min, 0 slowframe; 3,592-3,601 presents/min in stage legs | **PASS** · Q1, Q7-360 · `_local/rc1/q1/`; `q7x/` — 3,600/min; 3,575-3,627 presents/min in stage legs |
| R13 | Soak: crash-free + memory bounded (plateau <= 740 MB) | **PASS-WITH-NOTE** · Q1 + Q5 + Q6 10-11 · `_local/rc1/q1/REPORT_q1.md`, `q5/REPORT_q5.md`, `q6/REPORT_q6.md` — shell 30 min 285->292; ARCADE 60 min RSS 426 (min 2)/572 (10)/708 (25)/719 (60), slope 0.32 MB/min last 30 min, heap high-water pinned 496 MB, 0 alloc failure -> BOUNDED (ruled); Darwin page-release fix post-RC1 (G5-fix) | **PASS** · Q1 10-11 · `_local/rc1/q1/REPORT_q1.md` — 20 min, RSS 545->619 flat from min ~5; 0 FATAL/VK_ERROR/slow/underruns |
| R14 | Visual fidelity gates | **PASS-WITH-NOTE** · b3/10-05 gates; audits · `_local/boss1_mac/gates_vbsleep.txt` — stagepix + boss plate all-game sweep PASS, both audits 0 DRIFT/0 MISSING (18-TU era; re-run on the frozen bundle); eyes pass for FNF-class defects = USER-HANDS | **PASS-WITH-NOTE** · Q7v 10-12 · `_local/rc1/q7v/` — stagepix360 PASS (26304 / 25.1 vs control 26653 / 25.0) + 360 stage-1 boss plate PASS (p90 0.902 vs 0.912; structural 46/46 lockstep identical); no objaction_queue TU in the 360 module; eyes pass USER-HANDS |
| R15 | Flicker | **USER-HANDS** · Q1 10-11 (census); user eyes 10-11 · `_local/rc1/q1/REPORT_q1.md`; NOTE_fnf_shell_defects.md 2026-10-05 — census PASS: 0 dropouts in 30 min shell + 20 min + 25 min ARCADE; 6/6 hand-overs only the authentic PRESS START strobe; eyes retest on the frozen bundle incl. the G-START check | **USER-HANDS** · Q1 10-11 (census); user eyes · same — census PASS-WITH-NOTE: one deterministic unattributed card-LEFT loss (base 0x34E0000, len=1, LEFT+13 presents, 7/7); eyes retest on the frozen bundle |
| R16 | Quit | **PASS** · app smoke 10-11 · `build/app_smoke_1011c.log` — Quit leaves no process, save read back | **PASS** · app smoke 10-11; b3 10-04 · same — same engine |
| R17 | Packaging | **OPEN** · -- (Q10) · PLAN_beta3_mac.md todo 7; sec. 6 below — VER still 0.2.0-beta3, README is BETA 3 text; SHARED copy owed (NAS offline since 10-07 renumber) | **OPEN** · -- (Q10) · same — same |

<details><summary>§2 pre-tidy table, verbatim (2026-10-11/12 accretion; nothing removed)</summary>

Status: PASS / FAIL / UNMEASURED / KNOWN-ISSUE / PARTIAL. "today" = measured this window on build/rc1_probe
(numbers in §2.1). A = ARCADE, X = XBOX 360 MODE.

| # | Item | ARCADE | XBOX 360 | Evidence pointer |
|---|---|---|---|---|
| R1 | Boot to title, 2/2 modules bound | **PASS** | **PASS** | app smoke 13:29 today on the 68-TU .app (`build/app_smoke_1011c.log`: 2/2 bound, 0 FATAL, 59.94 Hz); today: §2.1 M1/M2 |
| R2 | Title → mode → module | **PASS** | **PASS** (cold boot ~40 s) | `_local/nav_mac/b4_VERDICT.txt` (10-05, bundle engine); today §2.1 M1 |
| R3 | Every hosted menu path | **PARTIAL** — hub, NORMAL PLAY+CONFIG, TRAINING (rows visible since FNF-15 fix), SCORE ATTACK decline dialog, REPLAY list, every OPTION sub-panel driven on the Mac by the decomp gate routes v5/B1/B2/B4 (futari_decomp ledger w143-w148, byte-identical shots) | **Q2b 10-12: 360 menu route PASS x2** (hub -> NORMAL PLAY -> mode/char/shot -> stage 1 -> pause/resume -> RETURN TO TITLE -> hub -> top menu; `_local/rc1/q2b/{q2a4,q2b}/`); TRAINING/REPLAY/OPTION/SCORE ATTACK still not driven. Earlier **Q2 10-11: PARTIAL** — card decide → 360 title/attract → HUB → NORMAL PLAY submenu → 1P SIDE START → MODE/CHARACTER/SHOT select screens, and HUB B → return-to-top → shell TOP MENU, marker-asserted 1x (`_local/rc1/q2/r2/`); the cold boot lands at the module TITLE (not MODE SELECT). TRAINING/REPLAY/OPTION/SCORE ATTACK not driven. (was: UNMEASURED) | NOTE_campaign_decomp.md w144/w145; NAV_MAP.md |
| R4a | Stage 1 reached + playable | **PASS** | **PASS** | b4/m2 verdicts; today M1 |
| R4b | Stages 2-5 + bosses, all difficulties | **Q7 10-12 (route C, `_local/rc1/q7/`): ORIGINAL stages 1-5 each REACHED + BOSS + stage end on the Mac, scripted** -- TRAINING with the game's own options (Shot Power Max, Bomb Stock Infinity, Player Stock Infinity = infinite lives/bombs, NOT a no-cheat clear) + autofire/bomb: entry (`[navreal] d76 3->4`) / boss BGM / boss-defeat `[fade]` / end (`d76 4->8`): st1 t3856/m03_boss/t11320/t12024 (136 s), st2 t3921/m03_boss/-/t16642 (213 s), st3 t4016/m03_boss/t19874/t20542 (275 s), st4 t4115/m03_boss/t21875/t22452 (305 s), st5 t4209/m11_lbs1/t30257/t30979 (446 s); the training STAGE RESULTS TALLY shows after each boss; 0 FATAL / VK_ERROR / slowframe / underrun, 3,592-3,601 presents per wall minute, census = only the authentic PRESS START strobe (7 lines/leg). Maniac/Ultra not driven; stage 5 = m11_lbs1 only (m12_lbs2 / m13_endg = a continuous 1-ALL, user Q6). Was: UNMEASURED on the Mac (boss 1 only: boss plate gate); Deck: "several stages" by the user 10-05 | **UNMEASURED** | **Q7-360 10-12 (`_local/rc1/q7x/`): ORIGINAL stages 1-5 each REACHED + BOSS + results tally + stage end on the Mac in XBOX 360 MODE, scripted** (`scripts/stages360_mac.sh`; TRAINING panel identical to ARCADE, same infinite-stock options, `[trainprobe]` word1 0x0007FFFF): st1 entry f5101 / boss +105 s / end +134 s, st2 +147 / +209, st3 +184 / +287, st4 +247 / +307, st5 +318 (m11_lbs1) / +450 s; 0 FATAL / VK_ERROR / slowframe / underrun, 3,575-3,627 presents per wall minute, one known 0x34E0000 dropout per leg; stage 5 ends at the boss like ARCADE (no m12_lbs2 / m13_endg); Maniac/Ultra not driven. Was: **UNMEASURED** |
| R4c | Full clear (1-ALL + ending) | **UNMEASURED** (no record of a port 1-ALL in any doc) | **UNMEASURED** | — |
| R5a | Settings round-trip | **Q3 10-12 PASS (Mac, 2 launches on one save dir)**: Picture preset #A->#B + Bomb Stock 3->4 via hub OPTION / NP CONFIG; savegame.bin diff = exactly 3 bytes (+0x0D..0E 0303->0404, +0x16F7 00->01), written at change time; panels read back on relaunch (earlier: **PASS** (B3, 10-05, scripted; four bytes, atomic publish, read back)) | **Q3 10-12 PASS (same 3 bytes, same panels; shell-owned)** (earlier: **UNMEASURED** (same shell save path; not driven in 360)) | _local/rc1/q3/{A_p1a,A_p1b,X_p1a,X_p1b}/; NAV_MAP "OPTION / REPLAY ..." Q3; NOTE_fnf_shell_defects.md 2026-10-05 |
| R5b | High score / ranking persist | **BLOCKED-FOR-SCRIPT (Q3 10-12)**: idle death scores 0 -> no register prompt, ranking unchanged (A_p2); a ranking needs a real score above the 5th row (millions); table values are not in savegame.bin/replaydata.bin. USER HANDS: play past the 5th row, name entry, relaunch, read the title attract (earlier: **UNMEASURED**) | **BLOCKED-FOR-SCRIPT (Q3 10-12)** (same shell/save path; not run separately) (earlier: **UNMEASURED**) | _local/rc1/q3/A_p2/, REPORT_q3.md; — |
| R5c | Replay save → playback | **Q3 10-12 PASS**: replay SAVED (slot 02, replaydata.bin 2444->4062) then RELAUNCH -> REPLAY DATA lists it -> playback x2 = identical marker timeline (cred 3->0, death) within one 30-frame step of the original recording; saves untouched by playback | **Q3 10-12 PASS**: same save (2444->4062); relaunch -> REPLAY DATA lists it -> 2 playbacks in one launch with IDENTICAL [nav360] timelines (+150/330/690/1080/2070/2460 from msg=17), original within +30 frames; playback ends on the REPLAY LOAD MENU (earlier: **UNMEASURED**) | _local/rc1/q3/{A_p3d,A_p3f,A_p3g,X_L1,X_L2}/, scripts/markframes.py; NOTE_campaign_decomp.md w144 |
| R6 | Game-over flows | **Q7 10-12 Mac: NP game over → replay-save prompt (msg=10) → save or decline → module title/ranking → hub PASS scripted (P2, C7 legs); continue countdown seen in replay playback, START-continue + name entry not driven (score never a ranking score)**; **PASS on Windows** (NP + SA, 08-12/08-13, NAV_MAP) + Mac bundle 10-04 ("game over -> top menu"); continue countdown UNMEASURED | **PARTIAL**: 10-04 bundle check covered both modes to game over → top menu; SA flow UNMEASURED. ⚠ Q2 r2: a 1P start at a ~13 s select cadence went straight to the replay-save prompt (d76 4→5→6→8, slot0 1→0, st 5→2) instead of stage 1 — unattributed (NAV_MAP 360 "replay-save trap") | PLAN_beta3_mac.md todo 4; NAV_MAP.md |
| R7 | Pause / resume | **Q7 10-12: in-stage START pause → A on RESUME → play continues, scripted on the Mac (route C1, every leg; TRAINING pause menu = RESUME / RESTART / OPTION / PREVIOUS MENU)**; RESTART / RETURN TO TITLE still UNMEASURED. Was **PARTIAL**: pause opens (shot); RESTART / RETURN TO TITLE UNMEASURED. Q2: resume input = **A on RESUME** (START does not resume), seen working on the Mac 10-03 (`_local/boss1_mac/gamectl/guest.log`: A → pause model `0x82061D50->0x82061D70`, play continues, next START re-pauses) | **PASS in 360 x2 (Q2b 10-12)**: pause opens, RESUME = A (play advances), RETURN TO TITLE (DOWN x3, A, A) lands on the hub — `_local/rc1/q2b/{q2a4,q2b}/`; RESTART / OPTION-in-pause / continue UNMEASURED; ARCADE leg not rerun | `_local/rc1/nav/rc1m_*/shot_3.png` |
| R8 | Swap cycle | **PASS** 1 cycle (10-05 and today on the 68-TU sources, residue=0 x2); ≥ 5 cycles UNMEASURED | same | `_local/rc1/nav/rc1m_VERDICT.txt` |
| R9 | Co-op | **Q3 10-12 PASS on the Mac scripted**: P2 START (RT_PAD_FIFO 4th field) at char select -> `[joinp] WILL-JOIN slot=1`, dual selects, stage 1 with PLAYER-1+PLAYER-2 HUD and two ships, pause/resume/RETURN TO TITLE, 0 FATAL (A_p4); couch session still owed (Q6). NB: RT_PAD_HOST_FIFO merges ALL tokens into P1 -- P2 must use RT_PAD_FIFO (earlier: **PASS on Windows** scripted (COOP_arcade_PASS 08-14); Mac UNMEASURED; couch session owed (eyes)) | **Q4b 10-12 PASS x2 on the Mac scripted, first 360 drive on the G-START-fixed engine (9b9dd8c): `[joinp] ENTER slot=1 WILL-JOIN` + `[xinput] P2 buttons=0x0010` in the 360 module (D=0x60), 2P panel, two ships + PLAYER-1/PLAYER-2 HUD in stage 1, pause, resume (A), RETURN TO TITLE, 0 FATAL/VK_ERROR; couch session still owed (Q6)** (earlier: NOT RUN Q3 lock starvation; X_L1 used the wrong P2 channel) (earlier: **PASS on Windows** (COOP_360_PASS); Mac UNMEASURED) | _local/rc1/q3/A_p4/, _local/rc1/q4b/{v3_1,v3_3}/ (REPORT_q4b.md); NAV_MAP "CO-OP" Q3; BACKLOG #9; NAV_MAP.md 2P |
| R10 | Input | keyboard **PASS** (README map, FIFO drives ride the same host channel); SDL pads used by the user; P2 pad + remap persistence UNMEASURED on the Mac | same | PLAN_macos_bringup.md top block; README |
| R11 | Audio | **PASS** (guest-native, CoreAudio sink; RT_AUDIODUMP 10-03); today 0 underruns / 0 sink stalls in 10 min | **PASS** today: 0 underruns / 0 stalls in 10 min; content by ear on Windows beta 2 only | PLAN_macos_bringup.md |
| R12 | 60 fps pacing | **PASS**: 3,600 frames every minute in shell, attract and demo today, 0 [slowframe]; in-stage per-minute rate not separately sampled (stage-1 legs PASS) | **PASS** today: 3,600/min in the module attract, 0 [slowframe] | PLAN_beta3_mac.md todo 5; NOTE 2026-10-05 noon |
| R13 | Soak | **Q6 10-11 (60-min ARCADE ceiling soak, `_local/rc1/q6/REPORT_q6.md`): PASS -- RSS 426 (min 2) / 572 (10) / 708 (25) / 713 (40) / 719 (60), slope 0.32 MB/min over the last 30 min, heap high-water pinned at 496 MB from min ~18, live 200 MB, pooled 291 MB, 0 FATAL / VK_ERROR / allocation failure, 3,600 frames/min, 0 slow, 0 underruns, 15 demo cycles per 20 min throughout -> R13 ARCADE re-baselined to BOUNDED; G5-fix queued post-RC1.** **Q5 10-11 BISECTED: the ARCADE RSS ramp is NOT the decomp link (all 132 linkable decomp TUs skipped still +129 MB min2->10 vs +133 full) -- it is the guest physical allocator (out_reco/rt_phys.cpp) bump frontier advancing over pooled-but-unreused freed blocks (heap high-water 17->352 MB in 10 min, live flat ~160 MB, pooled 14->181 MB; plateau = the 512 MB law-4 line; same allocator trajectory on 10-05); no page release on macOS (decommit is _WIN32-only); fix-or-rebaseline ruling owed (G13).** **Q1 10-11 (single-instance, `_local/rc1/q1/REPORT_q1.md`): shell 30 min PASS (285→292, flat); ARCADE 20 min FAIL as pre-registered (395→707 MB, slope 15.2 MB/min last 10 min; BUT a 25-min extension saturates at ~708 MB by min ~21 = bounded ramp, not an unbounded leak; needs ruling); perf 3,600/min, 0 slow, 0 underruns, 0 FATAL/VK_ERROR.** shell 30 min **PASS** (10-05, RSS 268→277 MB flat), ARCADE demo 20 min **PASS** (10-05, 15 cycles) — both on the 18-TU-era engine; today 10 min on the 68-TU sources: 0 errors but **RSS rising 399→553 MB** (10-05: cycling 202-425 over 20 min) → G13 | **Q1: 20 min PASS (545→619, flat from min ~5; 0 FATAL/VK_ERROR/slow/underruns, 3,600/min).** **PARTIAL** today: first 360-module soak ever, 10 min, 0 errors, RSS flat from minute 5 (615 MB); 20 min owed | soak_20261005_120159.txt, demosoak_20261005_131716.txt; today §2.1 |
| R14 | Visual gates | stagepix **PASS**, boss plate all-game sweep **PASS** (10-05); both audits 0 DRIFT / 0 MISSING | **Q7v MEASURED 10-12 (`_local/rc1/q7v/`): 360 stagepix PASS + 360 stage-1 boss plate PASS (see §4.2)**; was **UNMEASURED** — the boss plate and stagepix gates only ever drove ARCADE; the 31 ABN-EXCLUDED game TUs mean the 360 module runs generated code there (fine), but the 360-only regenerated tree (eqv-fix recompiler) has had no content gate beyond stage 1 | `_local/boss1_mac/gates_vbsleep.txt` |
| R15 | Shell flicker | **Q1 10-11 single-instance census: PASS — 0 dropouts in R1 30 min shell + R2 20 min + R2b 25 min ARCADE; 6/6 hand-over legs = only the authentic PRESS START strobe (class a); the triage len=3 f1641 NOT reproduced in 8 hand-overs (contention artefact).** **user eyes 2026-10-11: "not seen in a while" (beta 3 → today's 68-TU .app); UNMEASURED on the current build before today** — w136 census (10-05) ZERO over 12 min; **today: shell 0 dropouts / 10 min; ARCADE module 1 unreproduced len=3 at the hand-over (1 of 2 legs) → criterion NOT met yet** | **Q1: PASS-WITH-NOTE — R3 20 min + 6 legs: only the card-LEFT loss (base 0x34E0000, LEFT+13 presents, len=1), identical in 7/7 = deterministic, unattributed (R5).** **today: 1 deterministic press-coincident loss on the card panel (2 of 2 legs), unattributed** → PENDING Q1 | NOTE_fnf_shell_defects.md 2026-10-05; coordinator relay of the user's words |
| R16 | Quit | **PASS** (app smoke: Quit leaves no process, save read back) | **PASS** (same engine; 10-04 bundle check) | app_smoke_1011c.log |
| R17 | Packaging | **PARTIAL**: bundle builds, minos 13.0, README is BETA 3 text, VER 0.2.0-beta3; zip + Drive route exist; SHARED copy OWED (NAS offline, LAN renumbered 10-07) | same | PLAN_beta3_mac.md todo 7 |


</details>

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

## §3 GAP LIST (ranked by RC1-blocking severity)  — open gaps first; closed gaps in §3.2

Severity: **B** = blocks RC1 for that mode · **B?** = blocks unless the user rules it allowed · **M** = must be
measured before RC1 (cheap, expected to pass) · **P** = polish/packaging. Cost: S = Sonnet window (~30-45 min,
scripted, pre-registered), O = Opus window, E = user eyes/hands, R = user ruling.

### §3.1 Open gaps

| G | Gap (what remains) | Sev / modes | Queue | Cost |
|---|---|---|---|---|
| G1 | Full-game coverage: Maniac/Ultra stage+boss reach (both modes); no-cheat Original 1-ALL + ending per mode (user, Q6). Original stages 1-5 + bosses reached by script (Q7, Q7-360) | B · A+X | Q3 sweep; Q6; Q8 | S + E |
| G3 | Persistence: only the high-score/ranking entry remains (BLOCKED-FOR-SCRIPT; user hands) | B · A+X | Q6 | E |
| G4 | Flicker: draw-census half PASS (Q1); eyes retest on the frozen bundle owed | B? · A+X | Q6 / §6.5 | E |
| G5 | RC regression chain: `scripts/rc_chain_mac.sh` not written (swap x5, RESTART, continue, SA chain, stagepix/boss plate/audits on the bundle engine). Memory half closed (see 3.2) | M · A+X | Q5 | S |
| G6 | Mode swap at scale (>= 5 cycles, stale-descriptor class) | M · A+X | Q5 | S |
| G7 | **[Q7v 10-12: CLOSED for stage 1 + boss 1, `_local/rc1/q7v/`]** 360 visual gates absent (boss plate / stagepix only drove ARCADE) | B · X | Q7 (design O, gate S) | O then S |
| G8 | Co-op: couch two-pad session (scripted PASS both modes) | M · A+X | Q6 | E |
| G9 | Input breadth: pad classes, P2 pad, remap persistence, F11 + Retina/ProMotion, keyboard-only | M · A+X | Q6 + Q5 (remap round-trip) | E + S |
| G10 | Continue / RESTART / SA game-over chain on the Mac; 360 SCORE ATTACK + remaining OPTION sub-panels (Q3-X tour) | M · A+X | Q5, Q3-X | S |
| G11 | **[Q9 10-12: CLOSED -- both AUTHENTIC]** w136 owed (4): press-coincident menu-atlas pair (base 0x49C4000) + the 360 card-LEFT quad (0x34E0000) (both deterministic) | M · shell | Q9 | S |
| G12 | RC packaging: VER/README, tag, md5, SHARED copy (NAS offline since 10-07) | P · A+X | Q10 / §6 | S + E |

### §3.2 Closed gaps

- **G2** (360 drive-blind past the card) — CLOSED for the NORMAL PLAY route by Q2b 10-12 (route PASS x2; lever RT_NAV360 in f7542f9, route proof 3df934d); TRAINING/REPLAY/OPTION/SCORE ATTACK tours remain as Q3-X (G10).
- **G3** persistence minus ranking entry — CLOSED by Q3 10-12 (9b9dd8c): settings + replay save/playback PASS both modes.
- **G4 census half** — CLOSED by Q1 10-11 (00c0e29).
- **G5 memory half / G13** (ARCADE RSS growth) — bisected by Q5 10-11 (87c21ea: guest allocator rt_phys.cpp, not decomp), RULED bounded after Q6 10-11 (5c056c4); Darwin page-release fix = post-RC1 G5-fix.
- **G8 scripted co-op** — ARCADE PASS Q3 (9b9dd8c); XBOX 360 PASS x2 Q4b (afe66da).
- **G1 Original stage sweep** — ARCADE Q7 (cb32247, f7542f9 build); XBOX 360 Q7-360 (5549eac, 939b638 build).
- **G-START** — FIXED 10-12 in 619a190 (RT_STARTWIRE gated on the shell's cb3 input gate); user's .app needs the rebuild to carry it.
- **KSTUB-OVERCLEAR** — FIXED 10-12 in d3c9b23 (XGetVideoMode / VdQueryVideoMode over-clear, 0x50 -> 0x30); the 5 READ-UNDER stubs are NOT fixed (§0.5 item 1); user's .app needs the rebuild to carry it.

<details><summary>§3 pre-tidy table, verbatim (original rows with all bracketed history)</summary>

| G | Gap | Sev / modes | Evidence | Lane (suspected cause) | Cost | Depends on |
|---|---|---|---|---|---|---|
| G1 | **[Q7 MEASURED 10-12 (ARCADE, Original): stages 1-5 + bosses + stage-end tally reached by script via TRAINING with the game's own infinite-stock options; Maniac/Ultra and the no-cheat 1-ALL + ending (user, Q6) remain; Q7-360 10-12: the same 5 stages + bosses + tally reached in XBOX 360 MODE Original, `_local/rc1/q7x/`]** **No full-game coverage**: stages 2-5 + bosses never driven on the Mac; no 1-ALL / ending on any platform in the record | B · A+X | §2 R4b/R4c | drive (harness), then whatever it finds (decomp game TUs = the boss-1-head class; renderer) | S (training-select sweep: 10 stage/boss entries x 3 difficulties x 2 modes, shots + error counts) + E (one Original 1-ALL per mode, replay saved) | G3 for the replay half |
| G2 | **[CLOSED for the NORMAL PLAY route by Q2b 10-12 (RT_NAV360 markers; route PASS x2); TRAINING/REPLAY/OPTION/SCORE ATTACK tours = Q3-X seed]** was: **XBOX 360 module is drive-blind past the card**: no route has entered a 360 hub/menu; the drive markers `[intap]`/`[scenelog]`/`[navreal]`/`[gemsg]` read reco_normal globals and are garbage under reco_abnormal (NAV_MAP), so a scripted 360 drive cannot assert screens | B · X | NAV_MAP.md instruments; w144 "360 card route NOT measured" | harness: abn-aware markers (the +8 relocation already exists as `abn_symbol_map.h`; GameEntry 0x8824E6A0 in abn) | O (marker parity + 360 NAV_MAP section), then S (360 menu-path tour = R3 for X) | — |
| G3 | **Persistence not proven end-to-end**: scripted REPLAY save never proven ("inconclusive", w75); high score / ranking persistence never measured; 360-mode save untouched | B · A+X | §2 R5b/R5c | shell kernel save path (XamContent*, SAVE_DESIGN.md) or nothing (may just pass) | S (play → save replay → relaunch → play it back → compare outcome; score register → relaunch → ranking table), O only on failure | G2 for X |  **[Q3 10-12: settings PASS both modes; replay save + relaunch playback PASS both modes (2 playbacks, identical timeline); HIGH SCORE still open = BLOCKED-FOR-SCRIPT (needs a real ranking score by hand), so G3 is CLOSED except the ranking-entry half]**
| G4 | **[Q1 MEASURED 10-11: draw-census half PASS(+note) both modes, evidence `_local/rc1/q1/`; eyes retest on the RC build still owed]** **[Q9 10-12 ATTRIBUTION of the 360 card-LEFT quad: AUTHENTIC. One-shot RVK_QUADCENSUS on 5 arms: base 0x34E0000 (2048x1024 card-panel atlas, 2 card draws) is absent on exactly LEFT+12 presents, 1 frame; the raw guest draw count falls 99 -> 97 -> 101 (the guest issued no draw), the nvk recorder counters build/noscratch/spliced are 0, the carousel tween moves a constant 44.7 px/frame through the hidden frame, and a host with 94 of 96 decomp shell TUs removed reproduces it identically. Original shell code as lifted; no port-side drop. Evidence `_local/rc1/q7v/`.]** **Shell flicker (BACKLOG #0)** — acceptance RULED 10-11 (clean measurement suffices): user eyes "not seen in a while"; draw census 10-05 zero; today shell 0, but ARCADE hand-over 1 unreproduced dropout + 360 card-panel deterministic press-coincident loss (§2.1). The glass/present-alternation class (07-28 Windows RenderDoc) has never been looked for on the Mac | B? · A+X | §2 R15 | renderer present path (if anything) | S (census soak at RC length, both modes, pre-registered) + E (one eyes retest on the RC build) (ruled 10-11: clean measurement closes it) | — |
| G5 | **[Q6 PASS 10-11: the ARCADE memory item (G13/R13) is NON-BLOCKING for RC1; the Darwin page-release fix is the post-RC1 G5-fix, see Q6 entry in §4]** **No RC regression chain**: the gates exist (app smoke, modes, stagepix, boss plate, audits, soaks, fdpace, B3) but nothing runs them as one, on the bundle engine copy, at RC lengths; several Mac scripts `pkill -f` patterns that would hit the user's .app engine (soak_mac.sh, demo_soak_mac.sh match `Contents/MacOS/futari_merged`) | M · A+X | scripts/*.sh headers | harness | S (`scripts/rc_chain_mac.sh`, pkill -x only, one verdict file) | — |
| G6 | **Mode swap at scale**: one A→B→A cycle proven; the stale-heap-descriptor class (BACKLOG post-beta) is the known risk of repeated swaps | M · A+X | b4_VERDICT; BACKLOG "Swap-stale heap descriptors" | module registry / bridge re-image | S (≥ 5 cycles with stage-1 shots after each swap, black-placeholder counter) | G5 |
| G7 | **[Q7v MEASURED 10-12: 360 stagepix PASS (26304 / 25.1 vs control 26653 / 25.0), 360 stage-1 boss plate PASS (pixel p90 0.902 vs 0.912; structural 46/46 lockstep, identical); the plate wrappers transferred with no address change; limit = no objaction_queue TU in the 360 module; bosses 2-5 and a 360 shell A/B gate not built; `_local/rc1/q7v/`]** **360 visual gates absent**: stagepix and the boss plate only ever drove ARCADE; the 360 tree is regenerated with a reconstructed recompiler (validated by diff, not by content) | B · X | §2 R14 | recompiler / generated code (not decomp: the 31 ABN-EXCLUDED TUs run generated bodies) | O (design a 360 plate: symmetry plate + training-boss route under abn markers; no oracle needed for symmetry), then S | G2 |
| G8 | **Co-op on the Mac**: scripted COOP_*_PASS is Windows 08-14; Mac never driven; couch session never done | M (B if O2 = in) · A+X | BACKLOG #9 | input / shell | S (port day8_2p_validate to nav_mac, P2 FIFO field) + E (couch) | G2 for X |  **[Q3 10-12: scripted co-op ARCADE PASS on the Mac; 360: Q4b 10-12 scripted PASS x2; couch session still owed]**
| G9 | **Input breadth**: pad classes, P2 pad, in-game remap persistence, F11 fullscreen + Retina/ProMotion display, keyboard-only full session | M · A+X | README; PLAN_beta3 todo 8 | SDL3 host input / presenter | E (20-min attended checklist) + S (remap save round-trip scripted) | — |
| G10 | **Continue / pause sub-flows**: RESTART, RETURN TO TITLE, continue countdown, SA game-over chain on the Mac | M · A+X | NAV_MAP (Windows-mapped) | shell/game | S (fold into the G5 chain) | G2 for X |
| G11 | **[Q9 MEASURED 10-12: AUTHENTIC both -- card-LEFT quad = a game-issued one-frame draw gap at LEFT+12 presents (raw nDraws 99 -> 97 -> 101, recorder counters 0, tween continuous through the hidden frame, reproduced with 94 decomp shell TUs removed, 5/5); w136 pair = the 2-frame panel hand-off (outgoing 9-slice frame gone 2 frames while nDraws 790 -> 524, 5/5); `_local/rc1/q7v/`]** **w136 owed ④**: five press-coincident 2-frame losses of a menu-atlas quad pair (base 0x49C4000) on the Options tour, deterministic, binary-independent, unattributed | M · shell | NOTE_fnf_shell_defects.md 2026-10-05 | authored hide flip (likely) vs port | S (one-shot `RVK_QUADCENSUS` armed on the press; compare the hide byte) | — |
| G13 | **[Q5 BISECTED 10-11, `_local/rc1/q5/REPORT_q5.md`: NOT decomp (S1 all-skipped +129 MB vs full +133); engine-side = guest physical allocator rt_phys.cpp: freed blocks pooled but not reused so the frontier advances until the 512 MB line; no macOS page release. Options: Darwin arm of rt_decomSweep (MADV_*, gated, re-run stage gates), pool-reuse change, or re-baseline R13 to bounded <= ~720 MB]** [Q1 MEASURED 10-11 single-instance: REAL, not contention — ramp 395→707 MB over 20 min (~17 MB/min, +23 MB per ~80 s demo cycle) then plateau ~708 MB by min ~21 (R2b 25 min, last-5 slope 0.6); +283 MB over the 10-05 envelope; bisect (DECOMP_SKIP halves) or re-baseline R13 — ruling owed]** **ARCADE demo-loop RSS growth on the 68-TU sources**: 399 → 553 MB over 10 min, ~17 MB/min, no plateau yet (10-05 bundle: cycling 202-425 MB over 20 min, no monotonic growth) — either the 10-05 cycling with a longer period, a regression from the 50 TUs linked since, or 4-instance contention | M (B if it keeps growing) · A | §2.1 table | decomp shell TUs (asset/bank release paths) or allocator churn | S (fold into Q1: 30-min single-instance ARCADE soak; if monotonic, bisect by DECOMP_SKIP halves, 2 legs each) | — |
| G12 | **RC packaging**: VER/README still beta 3; SHARED copy owed (NAS offline since the 10-07 renumber); RC md5 set; Deck follow-on build | P · A+X | PLAN_beta3_mac.md todo 7 | packaging | S (README + bump + zip + Drive) + E (NAS back) | everything above |
| G-START | **[FIXED 10-12]** Pad START pressed on the hub or inside a hub submenu (OPTION) reached the ARCADE module ticking behind the shell: the game took it as 1P-START (`[navreal] d76 1->2 field=1 cred=3` = mode select) while the shell menu stayed up (user eyes 10-11) | M · A (360: no leak observed) | NOTE_fnf_shell_defects.md 2026-10-12; `_local/gstart/` | port: RT_STARTWIRE bypassed the shell's game-input gate (cb3 0x821C5618 zeroes the game pad while *(ctx+152)!=0) -> wire now gated (host, default ON) | done | .app rebuild to ship |
| KSTUB-OVERCLEAR | **[FIXED 10-12]** Host `XGetVideoMode` (shell/gen/rt.cpp) and `VdQueryVideoMode` (out_reco/rt.cpp) zero-filled 0x50 bytes into 0x30-byte guest buffers (X_VIDEO_MODE = 48 B), zeroing callers' saved non-volatiles (8216AD98 r26-r28/f31; 820B0890 f30/f31/r14; ...) -- found by the decomp diff-harness (w156H D1) | M · A+X (shell) | NOTE_fnf_shell_defects.md 2026-10-12; docs/AUDIT_kstub_sizes.md; `_local/kstub/` | engine thin kernel layer: wrong struct size | done (no screen changed: B1 14/14, B4 within same-build band) | .app rebuild to ship; 5 READ-UNDER stubs listed in the audit (own A/B window each) |


</details>

---

## §4 THE WORK QUEUE

Ordered for the orchestrator. Every window: build its own binary (`OUTDIR=build/<name> OBJSFX=_<name>
build_mac_dll.sh`, copy the host to a unique process name, kill only by `pkill -x <name>`), never touch the .app /
build/futari_merged / Application Support, bank under `_local/rc1/<window>/`, pre-register the pass criteria before
the first drive, and serialize GPU drives with any decomp gate window. **[S]** = Sonnet-able as written.

### §4.1 Measurement log (chronological, one line each; detail in §4.2)

| When | Window | Result | Evidence |
|---|---|---|---|
| 10-11 18:02 | M1/M2/M3 (triage window, build/rc1_probe) | modes drive PASS (swap residue=0 x2); shell 10 min clean; ARCADE 10 min RSS 399->553 rising; 360 10 min flat, 1 deterministic card-LEFT dropout | `_local/rc1/nav/rc1m_VERDICT.txt`, `rc1_*/soak.txt` (§2.1) |
| 10-11 18:21-20:13 | Q1 flicker census + RC soaks | shell 30 min PASS; 360 20 min PASS; ARCADE 20 min RSS 395->707 (bounded, plateau ~708); census ARCADE PASS, 360 PASS-WITH-NOTE | `_local/rc1/q1/REPORT_q1.md` |
| 10-11 20:15-20:58 | Q5 ARCADE RSS bisect | not decomp (S1 +129 MB vs full +133); guest allocator rt_phys.cpp, no macOS page release | `_local/rc1/q5/REPORT_q5.md` |
| 10-11 21:29-22:30 | Q6 60-min ARCADE ceiling soak | PASS: RSS 426/572/708/713/719, heap high-water pinned 496 MB, 0 alloc failure -> bounded | `_local/rc1/q6/REPORT_q6.md` |
| 10-11 21:00 -> 10-12 00:35 | Q2 (Opus) 360 drive parity | PARTIAL: lever RT_NAV360, NAV_MAP 360 section, nav360_mac.sh; nodes 0-10 + 15 once | `_local/rc1/q2/` |
| 10-12 00:36-01:05 | Q2b 360 route | PASS x2 (stage 1, pause, RESUME, RETURN TO TITLE, hub, top menu); NOLEVER inertness run | `_local/rc1/q2b/` |
| 10-12 00:40-03:40 | Q7 ARCADE stage sweep (Opus, route C) | Original stages 1-5 + boss + tally reached via TRAINING infinite-stock options; pause/RESUME; NP game-over -> replay-save | `_local/rc1/q7/` |
| 10-12 ~01:00-04:30 | Q3/Q4 persistence + co-op | settings PASS x2 modes; replay save + playback PASS x2; ARCADE co-op PASS; high score BLOCKED-FOR-SCRIPT | `_local/rc1/q3/`, REPORT_q3.md |
| 10-12 (Opus defect seat) | G-START | reproduced + fixed (619a190), 0 leaks in fixed arms | `_local/gstart/` |
| 10-12 04:40-05:30 | Q4b 360 co-op | PASS x2 on the G-START-fixed engine (9b9dd8c) | `_local/rc1/q4b/`, REPORT_q4b.md |
| 10-12 ~05:00-05:55 | Q7-360 360 stage sweep | Original stages 1-5 + boss + tally reached, 0 errors (939b638) | `_local/rc1/q7x/` |
| 10-12 05:20-06:30 | KSTUB-OVERCLEAR (Opus) | 2 OVER stubs fixed (d3c9b23); 5 READ-UNDER listed; no screen changed | `_local/kstub/`, docs/AUDIT_kstub_sizes.md |
| 10-12 06:45-09:57 | Q3-sweep Maniac + Ultra, both modes | 20/20 cells PASS: stages 1-5 + boss + stage end, 0 errors, d3c9b23 (R4b both modes PASS) | `_local/rc1/q3s/` |
| 10-12 10:00-14:10 | Q5 rc_chain (Sonnet, build/q5c_probe d3c9b23 + decomp 6fc61986) | A swap x5 PASS (#2..#10, residue 0 x9, RSS plateau 703 MB); B RESTART PASS x2; C 360 continue PASS, ARCADE START-at-CONTINUE flaky (opens PAUSE 3/4) + second death not reached; D SA decline chain PASS x2 (ends on module TITLE); E remap round-trip PASS x2; stagepix PASS; plate NO-VERDICT (lockstep); audits: constpool 0 DRIFT, regcontract 11 MISSING (compose_frame_walks); DC-1 second TRAINING start dead | `_local/rc1/q5c/REPORT_q5c.md` |

| 10-12 10:10-10:50 | Q7v 360 visual gate + Q9/G11 quad census + positive control | stagepix360 PASS, 360 boss plate PASS (46/46 lockstep), CENSUSTEST 60/60 + 60/60, card-LEFT quad + w136 pair AUTHENTIC, no engine change (d3c9b23) | `_local/rc1/q7v/` |

Not run (designed only): Q1b shadow-mode harness (not an RC1 blocker); Q5 rc_chain script; Q8; Q9 co-op half (day8_2p_validate port); Q10.

### §4.2 Queue definitions and measurement detail (verbatim)

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

**Q7-360 measured -- XBOX 360 STAGE SWEEP via TRAINING (2026-10-12 ~05:00-05:55, Sonnet seat, unattended, drive lock; fresh build/q7x_probe from main 939b638 incl. the G-START fix 619a190; evidence `_local/rc1/q7x/` -- PREREG_q7x.txt, REPORT_q7x.md, rc1_facts_q7x.txt, contact_q7x_stages.png, st1..st5/).** `scripts/stages360_mac.sh <tag> <stage>`: nav360 prefix to the hub, hub DOWN x2 + A = TRAINING, route C's option recipe (Shot Power Max / Bomb Stock Infinity / Player Stock Infinity; `[trainprobe]` msg=18 word1 0x0007FFFF in every leg), Stage k = RIGHT x 2(k-1), A, A, wall-clock autofire + bomb every ~4 s via the host FIFO. **Every Original stage 1-5 was entered (`[nav360] d76=4` + stage BGM), its boss reached (cuetally BGM cue2 = m03_boss; cue10 = m11_lbs1 on stage 5), the results tally shown and the stage ended (`d76=8`)**: 134 / 209 / 287 / 307 / 450 s (ARCADE 136 / 213 / 275 / 305 / 446). 0 FATAL / VK_ERROR / slowframe / audio-underrun in the 5 counted legs, 3,575-3,627 presents per wall minute, census = exactly the known single 0x34E0000 len=1 loss per leg (none during stage play); lock waits 0 s on the counted legs. **The 360 TRAINING panel is identical to ARCADE's (same shell code; infinite stock available).** Differences that matter to a script: the ARCADE stop marker (boss-defeat `[fade]`) does not print in 360, so autofire stops on `[nav360] d76=8`; the `[cue]` detail cap hides boss cues (read `[cuetally]`); a stray A after d76=8 hits the re-opened training panel (cursor on Start Training) and restarts training, so autofire must die the moment d76=8 shows. **Stage 5 in 360 ends at the boss (m11_lbs1 only; no m12_lbs2 / m13_endg), like ARCADE.** Not driven: Maniac/Ultra, the no-cheat 1-ALL + ending (user, Q6), the 360 replay-save trap check (C7-X).

*Sonnet seed -- the 360 mirror of route C (Q7-X):* nav360_mac.sh to the 360 HUB (node 6), then this window's TRAINING recipe verbatim (hub
DOWN x2 + A -> panel; DOWN x3 RIGHT x8, DOWN RIGHT x8, DOWN RIGHT x7, UP x5, RIGHT x 2(k-1) for Stage k; A 開始; A) -- assert the panel by shot
and `[trainprobe] msg=18` word1 = 0x0007FFFF; stage entry = `[nav360] ... d76=4` (RT_NAV360=1; [navreal] is blind under abn); autofire A 12/12 +
A+B every 10th press through `bank/r23/w153/drive_w153.sh` F:/U: steps; stop on the first `[fade]` after entry; stage end = `[nav360]` st 5->2;
then B (the panel re-opens itself) -> hub. One cold-boot leg per stage (the re-opened panel keeps its cursor on Start Training: a chained
RIGHT x2 flips 1P/2P Side). Bank shots at entry +4 s, every 30 s, the tally; RC1 cells R4b-X per stage. Then C7-X: NP game over (idle ship, no
autofire) -> replay save -> playback, watching for the 360 replay-save trap (NAV_MAP).

**Q3/Q4 measured -- persistence + co-op smoke, both modes (2026-10-12 ~01:00-04:30, Sonnet seat, build/w152_q2 as build/q3_run/futari_q3; lock waits 25-39 min per leg behind the w153 sweep chain; evidence `_local/rc1/q3/`, report REPORT_q3.md).** Script `scripts/persist_mac.sh` (marker-driven legs, shared save dir across a test, save-dir md5 snapshots, P2 pad), `bindiff.py`, `markframes.py`. **Settings PASS both modes** (3 bytes: bomb stock +0x0D/+0x0E, picture preset +0x16F7; read back on relaunch). **Replay save + playback PASS both modes** (replaydata.bin 2444->4062; relaunch; two playbacks, identical timeline, within one 30-frame step of the original). **Co-op ARCADE PASS; XBOX 360: NOT RUN in Q3 (lock starvation) -- see Q4b below.** Finding: the Mac host FIFO (RT_PAD_HOST_FIFO) ORs every token into P1 -- the day8 `echo "0 0 0 10"` is P1 START there; P2 needs RT_PAD_FIFO=1 + RT_PAD_FIFO_PATH (4th field). **BLOCKED-FOR-SCRIPT (user hands):** high-score entry both modes (an idle death never reaches the ranking table: 1st 6,880,571, 2nd 4,000,000, 3rd 3,000,000...; play Original past the 5th row, enter a name, relaunch, read "Original Ranking"); couch two-pad session (Q6). Not run: a second 360 game over (ranking/decline path) -- same shell path. No game-side defect found; the pre-619a190 binary was used (G-START fix not included).
**Q4b 2026-10-12 ~04:40-05:30 (Sonnet seat): XBOX 360 co-op PASS x2** on a fresh build of 9b9dd8c (build/q4b_probe, includes 619a190; first 360 drive on the G-START-fixed engine): `[joinp] ENTER slot=1 WILL-JOIN` + `[xinput] P2 buttons=0x0010` at char select, two ships + PLAYER-1/2 HUD, pause, resume, return to title, 0 FATAL/VK_ERROR (v3_1, v3_3; v3_2 timing flake on the 2nd pause). persist_coop_mac.sh retimed (pause at ~11 s: idle ships die ~20-28 s, START then = CONTINUE). Evidence `_local/rc1/q4b/`, REPORT_q4b.md.

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
engine, zip, md5 set, publish to the SHARED share when the NAS answers on 10.0.0.x (quick-tunnel fallback; NOT Drive -- see §6); Deck follow-on per O3.
Model: Sonnet.

Parallelism: Q2 (Opus, harness code) can run while Q1/Q3/Q4-ARCADE (Sonnet, drives) run only if they never drive
the GPU at the same time — serialize the drives, not the reading. Q6 can happen any time the user is at the Mac.


**G-START fixed (2026-10-12, Opus defect seat, unattended, drive lock; probe `build/gstart_probe` = 3df934d + fix; evidence
`_local/gstart/`).** User eyes 10-11: START in the hub's OPTION submenu started the ARCADE game behind the shell. Reproduced by script
(`scripts/gstart_mac.sh`, bug arm `RT_STARTWIRE_NOGATE=1`): ARCADE START on the hub root and in OPTION -> `[startwire]` + `[navreal] d76 1->2
field=1 cred=3` (the user's exact signature); DOWN/UP/A/B never leak; the 360 module never leaked; top menu / card panel have no module ticking.
Ground truth = the shell's own pad provider cb3 0x821C5618 (`shell/gen/ppc_recomp.34.cpp:11649-11678`): it strips START (mask bit 0x8) and
hands the game 0 while *(inputctx+152) != 0, the flag the shell raises at the hub hand-over (msg 15/11) and in pause (msg 10). The port's
RT_STARTWIRE (merged_game.cpp:470-503, default ON) ORed 1P-START into the game's EXCH word regardless of that gate. Fix: the cb3 hook
publishes the gate (`g_rt_gamefocus`), the START line is asserted only while it is open (faithful; default ON). Proof on the probe:
0 leaks in all fixed arms; nav360 q2 route VERDICT PASS; nav_mac hub route PASS; boss1 drive PASS (title START, training stage 1 -> boss BGM);
app_smoke shell steps vs the probe PASS (modules bound, 0 FATAL, save read back). The user's .app needs a rebuild to carry it.

**KSTUB-OVERCLEAR fixed (2026-10-12 ~05:20-06:30, Opus defect seat, unattended, drive lock; probes build/kstub_probe (build_mac_dll.sh, afe66da + fix), build/kstub_pre / kstub_post (build_mac.sh, B4 A/B), build/kstub_cap (harness capture); evidence `_local/kstub/`).** The decomp diff-harness (r23-w156H D1) showed `__imp__XGetVideoMode` zero-filling 0x50 bytes into the caller's 0x30-byte XVIDEO_MODE (Xenia X_VIDEO_MODE = 48 B), wiping sub_8216AD98's saved f31/r26/r27/r28; the game-tree `__imp__VdQueryVideoMode` had the same over-clear (820B0890's saved f30/f31/r14). Both now clear exactly 0x30 with unchanged field values; `docs/AUDIT_kstub_sizes.md` checks every stub that writes a guest out-pointer: 2 live OVER (fixed), 12 UNDER (5 read uninitialised on live paths -- display info, gamma, system command buffer, time-zone names, XUID -- listed, not fixed: value changes needing their own A/B), 6 UNKNOWN. Proof: harness record now keeps r28 = 0xFFFFFFFF821F8660 across the call and the w156H callee-clobber oracle finds nothing for 8216B0A0 / 8216C400 (EQUIV-STRICT); nav_mac hub PASS, nav360 q2 VERDICT PASS, boss1 PASS, app-smoke steps vs the probe PASS, 12-min ARCADE soak RSS 425 -> 557 (+132, Q5 control +133), 0 FATAL/VK_ERROR, 0 dropouts, 59.94 Hz. **No screen changed** (B1 14/14 byte-identical vs w156H; B4 pre/post within the same-build band) -> decomp control baselines unchanged. The user's .app needs a rebuild to carry it.
---

**Q7v / Q9 measured -- 360 VISUAL GATE + QUAD CENSUS + POSITIVE CONTROL (2026-10-12 ~10:10-10:50, Sonnet seat, unattended, drive lock; fresh build/q7v_probe from main 73ea6a5 = engine d3c9b23, build/q7v_control = same objects relinked (identical md5), build/q7v_nodecomp = host with 94/96 decomp shell TUs skipped; evidence `_local/rc1/q7v/` -- REPORT_q7v.md, rc1_facts_q7v.txt, contact_q7v.png, nav_band.txt).** Q7v: `scripts/stagepix360.py` (nav360_mac.sh with the new `STAGE_DWELL` env, frames entry+260..entry+1000) pilot 26304 colours / 25.1 edges vs control 26653 / 25.0 = PASS (ARCADE 24081 / 28.1); `scripts/boss360_mac.sh` (nav360 prefix -> TRAINING Stage row RIGHT x1 = stage-1 boss, QUIET=10 s, 100 s dwell) scored by boss_plate_gate.py (`BOSSPLATE_BANK`): pixel p90 0.902 vs 0.912 (skin 0.30 vs 0.29), structural 46/46 lockstep frames IDENTICAL (11,834 emit + 426 dcd70 keys) -> PASS; RT_EMITTRACE `lr:880DCD70-880DEE68` needed no change in the abn module; the 360 module links no objaction_queue TU, so this gate cannot catch a TU regression there; `scripts/nav360band.py` over 3 nav360 legs: of 25 shots 2 byte-identical, 5 <=1.0, 18 vary 1.2-9.5 (wall-clock shots). Q9: `RVK_CENSUSTEST` positive control (shell title idle 240 s): level 1 60 INJECT -> 60 DROPOUT-CONFIRMED, level 2 60 -> 60, all marked; env-off legs (12) print no CENSUSTEST line and reproduce Q1 (strobe + exactly one 0x34E0000 len=1 per 360 leg). One-shot RVK_QUADCENSUS (`scripts/q7v_run.sh`, armed from the host 2 presents after the LEFT press, K=16, 5 arms, `scripts/quadgap.py`): the card-LEFT quad is absent at exactly LEFT+12 presents; raw nDraws 99 -> 97 -> 101; census missRec{build,noscratch,spliced} = 0; tween x -92.5, -47.8, [hidden], 41.5 = constant 44.7 px/frame; reproduced on the lift-only host -> **AUTHENTIC (game-issued)**. w136 pair (`scripts/q7v_w136_route.sh`, the w136 Options-tour route with host-armed quad census at the five banked frames): reproduces 5/5 (frames moved +90..+400 with the engine), each = a 9-slice panel frame (base 0x49C4000, 18 or 9 draws) absent 2 frames at a panel switch while the outgoing panel's whole list disappears (nDraws 790 -> 524) -> **AUTHENTIC panel hand-off**. No renderer fix, no new gap. Not covered: bosses 2-5 plates, a real-360 reference trace, the Q9 co-op half.

**Q3-sweep measured -- MANIAC + ULTRA, STAGES 1-5, BOTH MODES (2026-10-12 06:45-09:57, Sonnet seat, unattended).** Binary: build/q3s_probe/q3s_probe, fresh build_mac_dll.sh from main 0305440 = engine d3c9b23 (first stage sweep on the KSTUB-OVERCLEAR-fixed engine). Difficulty = the TRAINING panel's row 1 `Mode` (Original/Maniac/Ultra; no unlock gate): from row 0, DOWN, RIGHT x1 (Maniac) / x2 (Ultra), UP, then the Q7 option recipe; proof = `[trainprobe] msg=18` word0 = stage<<24 | mode<<8 (0x100 / 0x200) + the panel and in-stage `Ultra Mode` banner. 20 counted legs (ARCADE and 360 x Maniac/Ultra x stage 1-5), 20/20 PASS with no retry: every stage entered, every boss BGM reached (m03_boss stages 1-4, m11_lbs1 stage 5), every stage end d76=8; 0 FATAL/VK_ERROR/slowframe/underrun (360: the known one card-LEFT DROPOUT per leg); ~3,580 presents/min. Maniac stage-end 138-499 s (ARCADE) / 137-493 s (360); Ultra 146-342 s for stages 1-4 and ~1,630 s for stage 5 (boss ~325 s, then ~1,300 s of infinite-stock autofire to defeat it; the 2x ceiling of 1800 s was needed). Scripts: scripts/stages_mac.sh (ARCADE, new) and scripts/stages360_mac.sh with a DIFF env (0 = unchanged Original). Evidence `_local/rc1/q3s/` (REPORT_q3s.md, rc1_facts_q3s.txt, contact_q3s.png). Still not covered: a no-cheat Maniac/Ultra clear (user-hands), the Normal Play mode-select path, the §6.5 frozen-bundle re-confirmation. R4b both modes -> PASS; open ruling 3 (scripted sweep satisfies the Maniac/Ultra bar) is applied provisionally.

**Q5 rc_chain measured (2026-10-12 ~10:00-14:10, Sonnet seat, unattended).** Binary build/q5c_probe/q5c_probe = fresh build_mac_dll.sh from main 73ea6a5 (engine d3c9b23) + futari_decomp HEAD 6fc61986 (`git archive`); control = identical link. `scripts/rc_chain_mac.sh <tag> <bin> A|B|C|D|E|all [mode]` (one process per leg; shell-side markers; RT_INDCENSUS on every leg per the coordinator). **A** 5 ARCADE<->XBOX 360 cycles in one process: [modswap] #1 boot + #2..#10, residue=0 x9, [modreg] 2/2 once, hub every time, RSS 398/514 -> plateau 702-704 MB, 0 FATAL/VK_ERROR (PASS). **B** TRAINING stage 1 -> pause -> RESTART -> confirm -> d76 4->3->4 + stage BGM -> pause -> PREVIOUS MENU (training's 4th row) -> hub, PASS both. **C** NP idle death -> CONTINUE? (9..0) -> START: 360 PASS 3/3 incl. second expiry -> game over -> replay prompt B -> title (no name entry, score 0); ARCADE: START opened the PAUSE menu on 3 of 4 first presses (DC-2), second-death leg not reached. **D** SCORE ATTACK: sign-in dialog -> A:OK -> SA submenu (offline SA playable) -> stage 1 -> idle death -> replay B -> register B -> cancelled-OK A -> module TITLE (not the hub) -> START -> hub, PASS both. **E** OPTION -> Controller Setting: SHOT A->B, BOMB B->A, saved (savegame.bin b07c47..->fe4dbb..), quit path, relaunch same save: panel shows SHOT=B BOMB=A, B held = shot stream, A = bomb, Default Setting restores; PASS both. **F** stagepix PASS (identical-link control); boss plate famk1 via scripts/rc_plate_dll_mac.sh (dylib-engine wrapper): pixel witness equal, structural NO-VERDICT after RETRIES=2 (lockstep coin flip); audits --selftest PASS x2, constpool sweep 0 DRIFT/0 NOTE_MISMATCH/0 UNANCHORED, regcontract sweep 11 MISSING (compose_frame_walks.cpp bctrl upper-bound rows, banked). **Defect candidates:** DC-1 the second TRAINING start in a process is dead in both modules (panel ignores A/START/B/UP after PREVIOUS MENU, game-over or SA game-over; `[pidx] rawbtn=0x1000 -> mask=0x0`), DC-2 ARCADE START-at-CONTINUE flaky, DC-4 the 11 regcontract rows. Evidence `_local/rc1/q5c/` (REPORT_q5c.md, rc1_facts_q5c.txt, contact_q5c.png).

## §5 RULINGS (history; the current lists are §0.4 recorded and §0.5 open)

- **RULED 2026-10-11 ~14:10 (was O1) — flicker acceptance:** "clean measurement is good for RC1." Eyes-clean +
  census-clean on the current build closes BACKLOG #0 for RC1 (§1 R15); the 07-26/07-28 compose-1:1 acceptance moves to
  the long-term decomp lane. Note for the record: the census cannot see the present/glass alternation class (07-28,
  Windows RenderDoc); the user's eyes cover that class.
- **O2 Co-op in RC1? — RULED IN (§0.4).** Recommendation was: IN (scripted proof is cheap, Q9; the couch session is the only eyes cost).
- **O3 Steam Deck arm — RULED follow-on (§0.4).** Recommendation was: NOT gating RC1; an RC1-follow AppImage/zip from the same tag, validated by
  `modes_deck.sh` + one Steam-shortcut session including XBOX 360 mode on screen and Steam Input.
- **O4 Full-clear requirement — RULED: the user's Original clears, no cheats, no lever (§0.4).** Does RC1 require a 1-ALL per mode, and is it yours (Q6) or a scripted one? A scripted
  clear would need a harness-only invincibility lever (guest RAM poke, default off, never in the bundle) — allowed or
  not? Recommendation: your two Original clears with replays saved; no invincibility lever.
- **O5 Difficulty scope — see §0.5 item 3 (confirm).** Recommendation: 1-ALL on Original only; Maniac/Ultra = every stage+boss reached (Q3).
- **O6 Distribution (standing rule, restated for sign-off).** The port ships ZERO game content publicly; F&F bundles
  carry your dump and go only to people who own the game. **RULED (per the 2026-10-12 brief): the channel is the SHARED release share, NOT Google Drive** (§0.4, §6.6).
  Still yours: who gets RC1.
- **O7 Version name + freeze — RULED `0.3.0-rc1` + freeze rule (§0.4, §6).** `0.3.0-rc1` (recommended) vs `1.0.0-rc1`; and the freeze rule in §1 (decomp
  promotions continue on main; the bundle is only re-cut from a tagged realcomp+decomp pair after the Q5 chain).
- Carried from the decomp ledger, not RC1-blocking: PNG history purge (ruled NO today), band-tightening (ruled today:
  Ruling A), task_w106 delete (ruled YES today).

---

## §6 FREEZE & SHIP PLAN (proposal for the user -- extends docs/PLAN_beta3_mac.md)

PLAN_beta3_mac.md defined beta 3 as two modes, Apple silicon + macOS 13+, built by `mac-build/build_mac_app.sh`, zipped with
`ditto -c -k --keepParent`, flicker shipped as a known issue. RC1 reuses that machinery unchanged; what changes is the
bar (§0), the version, the freeze discipline and the distribution channel.

### 6.1 Version
`0.3.0-rc1` (recommended over `1.0.0-rc1`): `VER=0.3.0-rc1` feeds both Info.plist keys and the README.

### 6.2 Freeze rule
1. Decide the cut only when §0.3 column (A) is empty and column (B) has a date.
2. Tag **`v0.3.0-rc1`** on futari_realcomp `main`. Record **both** hashes -- the realcomp tag commit and the exact futari_decomp
   commit the linked TUs come from (the `decomp/` tree the build used, i.e. `git -C ../futari_decomp rev-parse HEAD` at build time,
   with a clean decomp worktree) -- in the bundle README (build-id line, which today prints only the realcomp short hash) and in
   `STATUS.md`. A dirty tree (`-dirty` in the build id) is not a cut.
3. Decomp promotions continue on main after the cut; the bundle is only re-cut from a new tagged pair after the chain passes on it.
4. After the tag: no engine change enters RC1 except a fix for a FATAL or a blocking-list defect, which makes the next candidate rc2 (§6.7).

### 6.3 Build recipe
- macOS: `VER=0.3.0-rc1 bash mac-build/build_mac_app.sh` (checks every Mach-O minos 13.0, MoltenVK/SDL3 bundled, README + licences,
  icon, self-signed ad-hoc signature; output `~/Desktop/projects/Futari Realcomp.app`). Before running it: rewrite the README heredoc in the
  script (it still says BETA 3, "Not a release", and lists the beta-3 known issues) to the RC text -- the §1 allowed-known-issues list plus
  the §0.5 accepted divergences -- and add the two commit hashes of §6.2.
- Steam Deck / Linux: the PLAN_beta3 recipe (`mac-build/deck/`, `build_linux_dll.sh` in a Rosetta container, AppImage via
  `make_appimage.sh`, upload via the `_serve` tunnel) is a **follow-on**, rebuilt from the same tag after the Mac RC1 is signed off (ruling O3);
  it is not part of this cut.

### 6.4 What the RC1 zip contains
The `.app` made by `ditto -c -k --keepParent` -- engine + both module dylibs + SDL3 + MoltenVK + licences + README, **and the user's own
game data inside** (`Contents/Resources/assets`). Therefore: **family-and-friends only, to people who own the game, never public.**
The public form of this project ships zero game content (the UnleashedRecomp model); an RC1 zip must never be posted to a public place. Record the md5 of the
zip and of every Mach-O in the cut notes.

### 6.5 Smoke and sign-off on the frozen bundle
Must pass on the cut `.app` itself (not a probe), launched from Finder:
1. `scripts/app_smoke_mac.sh` -- boot, 2/2 modules bound, 0 FATAL, 59.9-60.0 Hz, Quit leaves no process, save read back.
2. The Q1 census criterion: 0 DROPOUT-CONFIRMED outside the named deterministic classes (PRESS START strobe; the 360 card-LEFT quad), 0 FATAL/VK_ERROR, 3,600 frames/min, 0 underruns, shell + both modules at RC length (Q1 recipe, `_local/rc1/PREREG_rc1.txt`, with the RVK_CENSUSTEST positive control this time: `scripts/q7v_run.sh <tag> <bin> ctest 240 1` must print 60 DROPOUT-CONFIRMED for 60 INJECT; the two named classes are now attributed AUTHENTIC, Q9 10-12).
3. The G-START check: ARCADE, START on the hub root and inside OPTION -> no `[navreal] d76 1->2`, the shell menu stays up (`scripts/gstart_mac.sh`).
4. The 5-swap cycle and the 360 nav route (`scripts/nav360_mac.sh`) once each on the bundle engine -- now `bash scripts/rc_chain_mac.sh <tag> <bundle host copy> all` (A swap x5, B restart, C continue, D score-attack decline chain, E remap round-trip, both modes; expect only the known DC-1/DC-2 deviations until fixed) plus the gate wrappers listed in its header (`scripts/rc_stagepix_lock_mac.sh`, `scripts/rc_plate_dll_mac.sh`, the two audits).
5. The 360 visual gates on the bundle engine (Q7v): `scripts/stagepix360.py compare` over two nav360 legs run with `STAGE_DWELL=14 NVKPNG=20` (PASS = >= 0.70 x control on colours and edges; reference 26.3k / 25.1) and `scripts/boss360_mac.sh` x2 + `BOSSPLATE_BANK=_local/rc1/q7v python3 scripts/boss1/boss_plate_gate.py compare <pilot> <control>`.
**Sign-off: the user, by eyes** -- the §0.3(B) list on this exact .app. An agent PASS does not sign off RC1.

### 6.6 Distribution
The **SHARED release share on the NAS** (nginx :8088 + cloudflared, see the arch-vm notes) once the NAS is back online -- it has been offline since the
10-07 LAN renumber to 10.0.0.x and the share copy of beta 3 is still owed. **Fallback for F&F:** the cloudflared quick tunnel over a loopback
`http.server` from `~/Desktop/projects/_serve/` (the route used for the Deck artefacts on 10-05), link sent only to named testers. Google Drive
(`scripts/upload_gdrive.sh`) is not the RC1 channel.

### 6.7 RC1 -> RC2 versus RC1 -> 1.0
- **RC1 -> RC2:** any FATAL or hang in tester use; any new defect class not in §1's allowed list (save loss, missing menu rows, wrong-mode substitution, sprite/texture defect, missing audio, non-60 pacing); any regression of a §0 PASS found on the frozen bundle; any engine change after the tag (even a fix).
- **RC1 -> 1.0:** a tester round (agree the length with the user) with no new defect class and no FATAL, all §0.3 items closed, the post-RC1 list triaged (G5-fix, the five UNDER stubs, the 360 START-wire address, Deck/Linux follow-on), and the public form still ships zero game content. 1.0 is a re-cut with `VER=1.0.0` from a new tagged pair, not a rename of rc1.
