# EVIDENCE_INDEX.md — map of C:\tmp evidence dirs → the findings they support

Purpose (from the 07-26 "what would actually help" ranking, item 4): `C:\tmp` holds ~138
evidence directories that the ledgers reference by bare path. This index maps each to the
finding + ledger section it supports, so a cold session (or another machine) can locate the
apparatus without re-deriving it. **`C:\tmp` does NOT survive a disk cleanup and does not
sync** — anything listed as LOAD-BEARING should be treated as re-derivable via the named
script, not as an archive.

Convention: entries newest-first within each campaign. "Ledger" = `NOTE_fnf_shell_defects.md`
unless another note is named. Drives referenced live in `_tmpscripts/`.

## F&F menu campaign + decoupling (2026-07-26 .. 07-27) — ACTIVE

| Dir / file | Finding it supports | Ledger section / script |
|---|---|---|
| `dec_soak_summary.log`, `soak_bwedge_*.log`, `soak_stage_*.log`, `soak_long_attract.log` | Unattended decoupled stability soak (pre-flip evidence): wedge hunt ×5, stage content ×5, 30-min aging run | FNF-5 worker perf leg; `dec_soak.sh` |
| `fnf5_bwedge_dec1/` | B→TOP-MENU wedge repro (healthy; overflow warn = transient stall class) + [wperf] profiles incl. the 260ms transition spikes and the VOID 1.4ms run | FNF-5 worker perf leg; `fnf5_bwedge.sh` |
| `d1b_shellreg_walklite_reg/` | Walk-lite shell regression PASS (4_legal bit-identical vs fnf1_ship) | FNF-5 worker perf leg; `d1b_shellreg.sh` |
| `d1b_shellreg_decouple_reg/` | Pre-walklite decouple shell regression PASS | FNF-5 decoupling acceptance |
| `fnf5_tick_stage/`, `fnf5_tick_menu/`, `fnf5_tick_slow/` | Tick-rate measurements: welded 54.7-55/s baseline, RVK_SLOWPRESENT/SLOWRENDER falsifiers (21/s lockstep), decoupled 59.9 flat, content % per phase | FNF-5 tick measurement + decoupling; `fnf5_tickrate.sh` |
| `ab_port_v5/p_*.png` | In-stage visual acceptance under decoupled worker (clean playfield/HUD) | FNF-5 decoupling acceptance; `ab_instage_port4.sh` |
| `playtest_0727_0949/0953/0956.log` (files) | USER playtest verdict: content collapse 33-41%, traceless wedge kill, vtxsnap 154k skips | FNF-5 "NOT PLAY-READY" section (superseded by perf leg) |
| `qa_dieloud/`, `qa_crashfilter.log` | Survivability positive controls: die-loud 4/4 (exit 3), DIEHARD corpse, WM_CLOSE exit, TESTCRASH → onsig [SIGNAL]+backtrace exit 42 | SURVIVABILITY CLUSTER section; `qa_dieloud.sh` |
| `fnf1_blob_port/`, `fnf1_blob_sdk/` | FNF-1 blob: port vs SDK oracle snap ladders (hardware = clean rings), [fetchraw] vertex-typed constant tf0=0x0110037B, post-fix crisp text + residual ring mass | FNF-1 partial-fix section; `fnf1_blob_evidence.sh` |
| `fnf2_hunt_pre_ab2/` | VALID FNF-2 pre-fix control 0/12 (romok=1 ×12) ⇒ both arms 0 ⇒ harness shape doesn't reach the path | FNF-2 A/B COMPLETE section; `fnf2_devloss_hunt.sh` |
| `fnf2_hunt_pre_ab/` | ★VOID control (kill-guard exact-match incident, 12 concurrent instances) — kept as the incident record | FNF-2 CONTROL INVALID section |
| `fnf2_hunt_post_fnf10/` | Post-FNF-10 rate soak 0/12 (romok=1 ×12) | FNF-2 rate-soak section |
| `fnf2_hunt_cdl1/`, `fnf2_hunt_accept1/`, `fnf2_hunt_soak1/`, `fnf2_hunt_smoke/` | Earlier FNF-2 lottery hunts (CDL instrument era; semaphore-fix acceptance 8/8 validated) | FNF-2 earlier sections |
| `d1b_shellreg_fnf1_ship/` | FNF-1 fix regression baseline (also walklite/decouple diff baseline) | FNF-1 partial-fix acceptance |
| `d1b_shellreg_fnf10_post/`, `persist/`, `persist_ab_*.log` | FNF-10 wallpaper-cache fix acceptance (reloads 7→2, border bit-identical) + persistence gate re-verified PASS | FNF-10 FIXED section; `save_persist_ab.sh` |
| `fnf3_fix/` (incl. `futari_merged_prefix.exe`) | FNF-3 shipped fix workspace + **the preserved PRE-FIX binary** (the A/B control exe — keep!) | FNF-3 FIXED section |
| `d1b_shellreg_fnf3_ship/`, `_ship2/`, `_pre/`, `_bgfix/` | FNF-3 acceptance drives (topmenu luma 9.7→74.3; proof-lever 81.4 too bright) | FNF-3 FIXED section |
| `fnf3_scope/FNF3_SCOPE.md` | FNF-3 root-cause scope (prefix-collision, wrong PS bound) | FNF-3 07-26 diagnosis |
| `fnf7_menutrip.log` (file), `fnf7_atlas/`, `fnf7_sdkref/`, `fnf7_emitter_candidates.md` | FNF-7 extra-quad tripwire soaks (incl. 07-27 decoupled soak: quad SURVIVES at baseline rate ⇒ not present-coupling), SDK-referee 60-quads result, atlas/emitter hunts | FNF-7 sections + FNF-5 thesis-refutation note |
| `flicker_falsify/FALSIFIER.md`, `flicker/`, `flashregress/` | FNF-7 falsifier: extra quad UNIQUE not duplicate (barrier would be no-op); 07-25 flash-hunt baselines (⚠ measured with LUMATRACE compiled in) | FNF-7 + menu-flash hunt notes |
| `wallpaper_audit/WALLPAPER_AUDIT.md` | Wallpaper subsystem audit (cache thrash discovery, one-byte save fact +0x16DB) | FNF-10 original entry |
| `rdc_user/` | User RenderDoc captures (F12 loop) — blob mechanism frames 40/85/105, FNF-7 black quad | FNF-1/FNF-7; `playtest_rdc.cmd` |
| `futari_fnf/`, `futari_fnf_qa/`, `alpha_prep/` | F&F 829MB staged package + launch QA (P1/P2 findings) — packaging DEFERRED by user ruling | FNF-8 section |

## D1-B / repairMatrix arc (07-26)
| Dir | Finding | Note |
|---|---|---|
| `d1b_shellreg_fnf_new*/`, `_old*/`, `_semfix/`, `_len*/`, `d1b_cshell_*/`, `d1b_census_*` | D1-B narrowing A/B, blast-radius census (9955/23373 degen sets), semaphore-fix drive | `NOTE_field_gfx_defects.md` legs 39-42 |

## Older campaigns (grouped — see their topic notes for detail)
| Group | Era / finding | Note |
|---|---|---|
| `lottery*/`, `titleblink/`, `lottery_tex/`, `lottery_nr/` | Title-blink lottery + PNG-readback trap era (07-2x) | memory: futari-title-blink-lottery |
| `soak*_frames/` | Attract pacing/parity soak filmstrips | futari-attract-* memories |
| `rdc_user/`, `rdc_oracle*/`, `oracle_tex*/` | RenderDoc oracle compose ground truth | futari-renderdoc-oracle-compose |
| `portcard*/`, `parity/`, `ab_rectall/`, `xrswap/`, `kicksem/`, `persistAB/` | Char-card hunt, parity apparatus, shader-swap era | respective topic memories |
| `m2hold/` (regenerated 07-28 + `prefix_dumps/ postfix_dumps/ reskeep_dumps/` + baseline logs) | ghost-draw fix texel A/B + RESKEEP A/B | NOTE_fnf_shell_defects 07-28 |
| `census1-5.log`, `r5pix1-3.log` | draw census (clean) + [r5pix] bimodal flash proof + RESKEEP arms | NOTE_fnf_shell_defects 07-28 overnight |
| `armA_t32.png armB_t*.png ctrl_t*.png` | screen-off PrintWindow artifact (all-white; instrument-lies lesson) | NOTE_fnf_shell_defects 07-28 overnight |
| `glass_burst/` (66 rdc + png/ + allswap/) | GLASS TRUTH: present-path A/B/A alternation = the flicker; C3 acceptance apparatus | NOTE_fnf_shell_defects 07-28 glass section |
| everything else unlisted | pre-F&F legs; if a ledger references it, trust the ledger's local description | — |

Maintenance rule: when a leg banks a new evidence dir into a ledger, add a row here in the
same commit. When C:\tmp is cleaned, this file is the recovery recipe (script + env per row).
