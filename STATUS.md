# STATUS — futari_realcomp (pointer, 2026-10-12)

**2026-11-07 ~21:50 AEST (PC seat, banker) -- 🎉 0.3.0-rc6 CUT ON BOTH SEATS FROM 4969ba6: ALL 8 MODULES IN THE DEFAULT BUILD · Windows pool release ON · futari.ini. Owner rulings "Cut rc6, default on" then "Ship rc6".**
- Mac (rc_cut_mac.sh, attempt 1, no reruns): app_smoke · gstart (10/9 probes, 0 leaks) · q1_ctest 60/60 · q1_census PASS both modes (0 underruns) · rc_chain 352/0. Tags pushed: v0.3.0-rc6 = cd2076ce -> 4969ba6; decomp realcomp-v0.3.0-rc6 -> 1d79e208.
  Arrange leg on the cut engine 15/15. Public zip 44,055,589 B sha256 fa09ffbb1e0cfabe1738b788ebca2cdc7d1c35dd8d60fdf5c116cda1734d0f45 (re-staged 21:34 for the README MODES text; byte-identical binaries; rc_smoke_mac_public PASS twice).
- Windows (build 4969ba6, exe md5 0ac1e5d4..., `[modreg] 8/8 ... mask=0xFF`): boot_smoke · gstart · q1_ctest · rc_chain 418/0 PASS; q1_census ARCADE PASS x2, XBOX 360 FAIL x2 (one 60 s interval short 20-27 frames) = the gate record.
  WIN-PACE re-measure on the byte-identical exe, pre-registered: pool release OFF x2 PASS, ON x2 PASS, 24/24 intervals 59.88-59.97 fps, no loss adjacent to any [poolrelease] event -> H1 (pool release) REFUTED. The two FAILs: attempt 2 = one 37-present second
  carrying `[padhost] window FOCUSED` (6 focus events in that log vs 1 in every quiet run = desktop interaction during the leg); attempt 1 log overwritten. The driver lane's earlier x360 "FAIL" was a HIGH interval = the census sampler's stale first read at the module swap.
  Arrange leg on the staged exe 14/15 (rung 12 = known 0x1C9C000 NOW-LOADING-shaped pair; key unchanged). Public zip 42,791,696 B sha256 54c1b9a62a6724d49c9334b1d20a600961131f8173d7e712113e65afdcda5dfd (re-staged 21:33; file list + binaries identical to the gated stage; 0 game-data entries).
  F&F zip (contains game data) -> Desktop/NSP/Futari-Realcomp-Windows-v0.3.0-rc6.zip sha256 ee51605a...; Mac F&F zip stays in the Mac's _rc/ (sha256 ec002725...).
- Owner decisions "Ship rc6" + "Yes, upload": PUBLISHED ~22:50 as GitHub pre-release https://github.com/springah/futari_realcomp/releases/tag/v0.3.0-rc6 (both public zips + .sha256; digests verified on GitHub). Stage/cut README text fixed d987615; rc_chain frame-dump prune a625b23 (disk: 36 GB free found, 21.5 GB of dumps trashed).
- Banks: _local/rc/0_3_0_rc6/ (both seats), _local/rc/w1107_{maccut,wincut,pace}/, projects/_rc/0.3.0-rc6-win/SMOKE.md (PC), ~/Desktop/projects/_rc/0.3.0-rc6/SMOKE.md (Mac). OWED: census sampler stale first read at the swap (mechanism known: last [tick] outside the 20 KB tail); x360 census leg = nobody at the desktop; rc6 hands checklist both seats -> 0.3.0; LICENSE; w1107-perf merge; dropout key.

**2026-11-07 ~19:50 AEST (PC seat, banker) -- 🎉 FACTORY WINDOW w1107 CLOSED: 8/8 MODULE PARITY ON BOTH SEATS (opt-in) · Windows RT_POOLRELEASE gated + DEFAULT ON (owner ruling) · futari.ini + wizard settings + futari_recomp import.**
Seven lanes over the day (banker + WIN-DRIVER, MAC-MODULES, CONFIG, MAC-CONFIG-VERIFY, WIN-MODULES, MAC-PERF, WIN-CONFIG-CHECK), every claim below spot-verified by the banker:
- WIN-DRIVER (PC): getenv hot-path caching `RT_ENVC` in 7 TUs (3cdd26b) + the Windows RT_POOLRELEASE arm (d7f2db0: decommit + immediate recommit; PC1 positive control crashes as designed). 12-min ARCADE
  census: control +193 MB vs arm +32 MB (264 MB released, 0 underruns); x360 +69 vs +31 from t+1; gstart 0 leaks; rc_chain PASS both arms on a quiet box. OWNER "sure flip on" -> default ON on Windows
  (5d56f8e, docs 4ce4ba3; `RT_POOLRELEASE=0` reverts). P1/P2/P4 bands missed on their DEFINITIONS (Windows ramps ~18 MB/min; sawtooth endpoint; pre-load t+0) -> re-band proposal in _local/rc/w1107_driver.
  Census-sampler stale end-of-file read: unexplained TODO (BACKLOG).
- MAC-MODULES (Mac, 6f0e4ad a83c67a): hirow_normal(6) hirow_abnormal(7) palm_normal(2) palm_abnormal(3) HOSTED-AND-PLAY, gates 15/15 each, swap-back 11/11 x4 with the new UNION-ZERO registry fix,
  0 FATAL/VK_ERROR/UNMAPPED; ARCADE + x360 non-regression clean. FINDING (not changed): the shipped x360 RT_DIVGUARD watches 0x887ACE14 but reco_abnormal's twin divides by 0x887ACE74 (+0x60).
  OPEN: Arrange/Novice play no music cue after the stage-1 track on the gate route (authentic vs defect unverified, no reference run).
- WIN-MODULES (PC, 0a6a6c9): the same four on Windows -- `[modreg] 8/8 bound mask=0xFF`; hirow x2 + palm_abnormal 15/15, palm_normal 14/15 x2 (rung 12 = a NOW-LOADING-ring-shaped dropout pair on page
  0x1C?C000, outside the key `0x1C?[48]000`; scored FAIL as pre-registered, key NOT widened -> owner). Generated trees tarred from the Mac (Windows XenonRecomp lacks mulhdu + the xex size fix); COFF
  arm for the `_HCH` chain-break labels in the symbol maps; win_port.sh now ports nav/boot/gate/swap scripts. Non-regression ARCADE + x360 census PASS on the 8-module build with pool release ON.
- CONFIG (PC worktree, branch w1107-config d6931d7 a3fd761) + MAC-CONFIG-VERIFY (Mac, 48d4aaa d9a4792 f41f551) -> merged 1ed512a: `futari.ini` -> existing RT_*/RVK_* levers, env > ini > launcher
  defaults, applied before EVERY static initializer (.CRT$XCT on Windows; a pre-init TU first on the Mach-O link line -- Mach-O ignores constructor priority); new `RVK_FULLSCREEN`; wizard settings step +
  Settings.bat/.command + tools/settings/; `futari_extract.py --from-recomp` (recomp's assets/ consumed directly, 58/58 manifest + DLC; saves are the same container: byte-identical copy, a recomp
  replay plays back); docs/SWITCHING_FROM_FUTARI_RECOMP.md; docs/DESIGN_settings_overlay.md (F2 overlay ~2.3-2.5k lines, DESIGN-ONLY). WIN-CONFIG-CHECK re-proved the merged main on Windows
  (build 1ed512a clean 3m34s, [ini] log line 1, env wins, invalid value reported, default shape 4/4, pool release ON in the census). F11 toggle-back on Windows after RVK_FULLSCREEN=1: UNTESTED (hands).
- MAC-PERF (Mac, branch w1107-perf, UNMERGED): on the Mac the XAudio engine frame is 0.10-0.17 ms mean vs the 5.33 ms budget, 0 overruns, ~2.8 % of a core; process 0.67 cores at 59.9 fps, ~85 %
  renderer incl. the deliberate fence spin (RVK_FENCESPIN=0 is WORSE; RVK_FENCEPOLL prototype = null). Host xWMA decode ceiling ~1.2 % of a core -> not worth it. docs/PLAN_perf_w1107.md on the branch.
- Merges: af12cb5 (mac/main), 1ed512a (w1107-config). Landmine: `source futari_decomp/bank/r23/w30/w30_toolchain_env.sh` before build_win_dll.sh (else 'cstdint' not found + the pre-clean deletes the exe).
OWNER DECISIONS OWED: (1) ship the 4 new modules default or opt-in in the next rc (both seats opt-in now); (2) widen the NOW-LOADING dropout key for the moved page or keep Arrange at 14/15;
(3) a LICENSE file for this repo (none; recomp launcher code is BSD-3 by the same owner); (4) merge w1107-perf (all default-OFF instruments + plan) or leave it; (5) ini template defaults + the new
"preset env var beats the .bat" precedence; (6) rc5 hands checklist both seats ("Later") -> promote rc5 to 0.3.0. Next cut = 0.3.0-rc6 or 0.3.1 with all of the above.

**2026-11-04 22:40 (Mac seat) -- CORRECTION to the ssh "landmine" below: the key is FINE.** `ssh -T git@github.com` now answers "Hi springah!
You've successfully authenticated" and `git ls-remote` over ssh works, with nothing changed on the Mac; githubstatus.com showed Git Operations
+ API Requests DEGRADED during the cut's tag push, the docs push (one 500) and the release upload (one vanished release) and OPERATIONAL now.
So the cut's `git push origin v0.3.0-rc5` died on GitHub's outage, not on `~/.ssh/id_rsa`, and the global https->ssh insteadOf is not a
problem. The HTTPS+gh push recipe still works as a fallback; the rc_cut_mac.sh TODO shrinks to "retry the tag push a few times before dying".
Spotlight Privacy exclusion STILL not effective at 22:40 (`mdfind` count 29,808 PNGs under `_local/`, rising).


**2026-11-04 22:25 AUSEST (Mac seat) -- 🚀 rc5 UPLOADED on the user's yes ("Yes, upload rc5"): GitHub pre-release `v0.3.0-rc5`
https://github.com/springah/futari_realcomp/releases/tag/v0.3.0-rc5** on the pushed tag, title "v0.3.0-rc5 — Windows + macOS test builds (no game
data, bring your own dump)", notes = the rc4 notes updated (WIN-AUDIO-1 fixed -> all five gates PASS on BOTH platforms; build table b299957 /
1d79e208; both digests). Assets: `Futari-Realcomp-Windows-v0.3.0-rc5-public.zip` (33,574,452 B, sha256 `2d0dfa38…1cbc`, fetched from the PC's
`_rc/` by scp and re-hashed) + `.sha256`, `Futari-Realcomp-macOS-v0.3.0-rc5-public.zip` (33,412,658 B, sha256 `440dbf85…7017`) + `.sha256`; ALL
FOUR re-downloaded with `gh release download` and `shasum -c` OK against the uploaded .sha256 files and the notes. GitHub was DEGRADED (API +
Git Operations) during the upload: one HTTP 500 on create, then a created release id 433819908 whose asset upload 404'd and which then vanished
(no draft left behind; checked via the API) -- the third try (create without assets, then `gh release upload --clobber` per asset, retry loops)
succeeded. rc4 + rc3 pre-releases left in place. F&F (with game data, never public): on the PC `Desktop\NSP\` now holds
`Futari-Realcomp-Windows-v0.3.0-rc5.zip` (964,017,522 B, sha256 `301832b4…8e2c` verified after the copy) + `.md5/.sha256` + the staged folder's
README as `Futari-Realcomp-Windows-v0.3.0-rc5.README.txt`, AND the Mac F&F zip `Futari-Realcomp-macOS-v0.3.0-rc5.zip` (741,268,897 B, sha256
`5dcca523…b698`, scp'd from the Mac, `sha256sum -c` OK there) + `.md5/.sha256`; rc4's four NSP files moved to `NSP\_superseded_rc4\`. The PC's
`_rc/` copies were left in place (copied, not moved). Scratch on the Mac: `_rc/rc5_upload/notes_rc5.md` (the notes as posted). OWED: hands
checklist both seats (`RC1_HANDS_CHECKLIST.md`), tester triage, the rc_cut_mac.sh HTTPS-push fix, Spotlight exclusion, the Linux build (none).


**2026-11-04 21:20 AUSEST (Mac seat) -- 🎉 0.3.0-rc5 CUT ON THE MAC, ALL-PASS, BOTH TAGS PUSHED, PUBLIC macOS ZIP STAGED + SMOKED. NOT UPLOADED.**
User ruling 11-04 ("rerun as is"): no episode rule, the one-window forgive rule of f5b00c6 stays. Attempt 7 of `rc_cut_mac.sh 0.3.0-rc5`
(20:04-21:11, box quiet, mediaanalysisd/mds idle at launch): app_smoke PASS, gstart PASS (ARCADE 10 probes / 360 9 probes, 0 leaks), q1_ctest PASS
(60 DROPOUT-CONFIRMED / 60 INJECT), q1_census PASS BOTH MODES with `UNDERRUN=0 SINKSTALL=0` and ZERO `[vblank] stall` markers (ARCADE 0 named /
0 other; XBOX 360 1 named / 0 other; nothing forgiven, nothing to forgive), rc_chain 352 PASS / 0 FAIL. Engine realcomp `b299957e15b7` + decomp
`1d79e20871bc` (300 decomp TUs; same pair as Windows rc5), bundle 924 MB, `futari_merged` md5 `7d7798ee4e4cab0714bc18f0db3ed032`,
`_rc/0.3.0-rc5/SMOKE.md`. LANDMINE: the script's own (d) step died at `git push origin v0.3.0-rc5` with `git@github.com: Permission denied
(publickey)` -- the detached nohup shell offers `~/.ssh/id_rsa` and GitHub refuses it, and the global `url.git@github.com:springah/.insteadOf`
rewrites every https URL to ssh -- so the remainder of (d) was done BY HAND, step for step: tags `v0.3.0-rc5` (realcomp -> b299957e) and
`realcomp-v0.3.0-rc5` (decomp -> 1d79e208, same tag message) pushed over HTTPS (`GIT_CONFIG_GLOBAL=/dev/null git -c
credential.helper='!gh auth git-credential' push https://github.com/springah/<repo>.git <tag>`), both verified on the remotes via the API;
F&F zip `_rc/Futari-Realcomp-macOS-v0.3.0-rc5.zip` 720 MB sha256 `5dcca5239529a6671c9f450a48b2378fce4c1ef68eb8de72f4ca4cd98d52b698`
md5 `9cd46d1d7577e2738440cd610b5e7dd2` (CONTAINS GAME DATA, F&F only) + `.sha256`/`.md5`, symlinked into `_serve/`. PUBLIC asset-free form:
`rc_stage_mac_public.sh 0.3.0-rc5` -> `_rc/Futari-Realcomp-macOS-v0.3.0-rc5-public.zip` 33 MB sha256
`440dbf8548f1a11dc32fa183b4715392dae70ed98a7e3a11738dd70058a97017` (re-sealed ad hoc; engine + 4 module dylibs + Frameworks byte-identical to
`MACHO_MD5.txt`, only the launcher's signature blob changed; game-data scan clean, 24 files / 114 MB); `rc_smoke_mac_public.sh` ALL-PASS
(unzip, seal, nodata, extractor 58/58 sha-verified incl. the 3 DLC rows from `_local/blroot`, app_smoke 4/4 modules + save round-trip, log
build=b299957 0 FATAL / 0 VK_ERROR / 0 MoltenVK-Metal, 30 lines naming the beside-the-app assets/; record
`_rc/Futari-Realcomp-macOS-v0.3.0-rc5-public.zip.SMOKE.md`, evidence `_local/rc/pubsmoke_mac_20261104_211834/`). A first smoke run with a
RELATIVE `<dlc>` path failed only its extract step (the extractor runs from the cache work folder) -- pass ABSOLUTE paths; that run's evidence
`_local/rc/pubsmoke_mac_20261104_211715/`. Windows rc5 public zip (sha256 `2d0dfa38…1cbc`) is on the PC at `_rc/`. **OWED: the owner's upload
call** (GitHub pre-release `v0.3.0-rc5` on the pushed tag = Windows public zip + macOS public zip + `.sha256`; F&F zips to `Desktop/NSP`);
the hands checklist on both seats (`RC1_HANDS_CHECKLIST.md`, check the Game Mode badge on the Mac); the Spotlight Privacy exclusion is STILL
not effective (`mdfind` count 29,565 under `_local/` before the cut -- the box was simply quiet at 8 pm); the episode rule stays docketed, unused.


**2026-11-03 ~12:45 (PC seat) — rc5 HANDOFF TO THE MAC: read `docs/NOTES_rc5_mac_handoff.md` FIRST.** Windows rc5 = all five gates PASS, F&F + public zips staged (NOT uploaded, no tag). Mac rc5 = NOT CUT after six attempts, all stopped at q1_census by box stall episodes (`[vblank] stall` marker + one underrun burst; mediaanalysisd on the Photos library), never an rc5 defect; A5/A6 passed XBOX 360 clean. ⚖ OPEN for the user: forgive one stall EPISODE per run (draft awk in the handoff) vs keep rerunning. Mac checkout must `git pull --ff-only` before the next cut (preflight). Upload of rc5 = ASK THE USER.

**2026-11-03 (PC seat): 🎉 WIN-AUDIO-1 FIXED (0f23859) -- the cost was a `getenv()` on EVERY indirect dispatch in `rt_indirect_call`, not the
recompiled DSP.** A new sampling profiler of the engine thread (`RT_ENGSAMP=1`, out_reco/rt_engsamp.cpp) + the host link map named
`common_getenv_nolock`/`_strnicmp` under the xWMA software decoder the SFX voices run (thousands of indirect dispatches per packet). Cached:
sub_82150338 0.7 -> 0.25 ms per voice (max 20 -> 3.4 ms), the engine frame 3.0 -> 1.1 ms avg in the loudest minute, 6-min ARCADE census
underruns 143 -> 2 unprofiled; the last 2 (first second of every leg, the SDL first-callback drain before the worker refills the ring, rms=0)
are now a bounded startup transient (`RT_AUDIOSTARTGRACE=0` reverts). **aud1103c: UNDERRUN=0, RESULT: PASS -- the first Windows ARCADE census
PASS.** 0.3.0-rc5 staged + gated (`STEPS="q1_ctest q1_census"`): **BOTH PASS** (SMOKE.md 2026-11-03 07:31-07:53): q1_ctest PASS (positive control 60 DROPOUT-CONFIRMED for 60 INJECT, 262 s); q1_census PASS -- ARCADE `UNDERRUN=0 SINKSTALL=0` (8 named-class dropouts, 0 other), XBOX 360 `UNDERRUN=0 SINKSTALL=0` (1 named, 0 other; rc4 had 247 here), fpm-off 0 in both (1050 s). Staged folder `_rc/0.3.0-rc5-win/` (1.2 GB, exe build id 0f23859, engine md5 21ee5112...), F&F zip `_rc/Futari-Realcomp-Windows-v0.3.0-rc5.zip` (920 MB, sha256 `301832b4a6c0b323fb440834e225d72c86c1acc166fa9e358d4e5ac973578e2c`). **Remaining gates re-run 07:57-08:43 on the same engine copy (md5 21ee5112 IDENTICAL): boot_smoke PASS (76 s, 4 PASS lines), gstart PASS (217 s; arcade 10 probes 0 leaks, x360 9 probes 0 leaks), rc_chain PASS (2515 s; all T2 CX, 418 PASS lines, FAIL 0) -- ALL FIVE rc5 Windows gates PASS, ENGINE FAILED STEPS: none.** PUBLIC asset-free zip staged 08:44 by `rc_stage_win_public.sh 0.3.0-rc5`: `_rc/Futari-Realcomp-Windows-v0.3.0-rc5-public.zip` (33 MB, sha256 `2d0dfa38ef4b8cc0381587a96bb7e1eac75dbacf3f11b1cc343fc419fda81cbc`, md5 `56a95666255a6655cea86bafa94610ae`; realcomp d0dd58d, engine_commit 0f23859, 16 files, game-data scan clean), wizard smoke PASS (`_rc/0.3.0-rc5-win-public/wizard_copy/`: extractor fed the gated tree's assets/ as an already-extracted disc folder -> "assets/ matches the reference manifest", `--verify-only` every file present and matches, staged shell/default.xex md5-identical to the gated tree's; `rc_smoke_win.sh` on the copy: build=0f23859, 4/4 module DLLs bound, 0 FATAL, 0 VK_ERROR; log `_local/logs/wizard_rc5.txt`). NEITHER zip uploaded, NO Windows tag (the Mac cut at main d0dd58d makes the v0.3.0-rc5 tag; same engine sources). Residual cost named for the record (sub_821536C0,
the codec's VMX128 transform, 44 % self of the loudest minute; next lever = native transform or host xWMA decode at submit; not needed).
Evidence: BACKLOG.md 2026-11-03, NOTE_fnf_shell_defects.md 2026-11-03, `_local/rc/census/aud1103{a,b,c}_arcade/`, `_rc/0.3.0-rc5-win/SMOKE.md`.

**2026-11-02 (PC seat): CLEAN QUIT landed · WIN-AUDIO-1 root cause measured · Black Label Windows build arms · rc4 cuts.** B / Esc on the
TITLE screen exits cleanly (heartbeat-gated edge in the pad merge -> renderer `rvk_request_quit`; `RT_NOTITLEQUIT=1` disables; control + quit
acceptance PASS). WIN-AUDIO-1 is no longer a mystery: `RT_WAITPROF=1` lock-holder profiling shows the XAudio engine thread's per-frame processing
(`sub_82137218`, under engine section 0x36A0D4) overrunning its 5.33 ms period by 5-36 ms thousands of times per 6-min census at SFX-dense demo
moments (same demo frames every run); thread priority is not the lever (register-true routing via the new ObReferenceObjectByHandle token,
RT_OBJREF=1 default / =2 / =0, leaves the count at ~143); the first-second "4 underruns" were SDL device-buffer prefill (fixed). VERDICT 11-03: the
engine frame is CPU-BOUND recompiled DSP -- holds >= 5 ms are 0.98 CPU by QueryThreadCycleTime, 0 ms inside kernel imports, the four named
callees < 5 % of it; the time is the per-voice render calls (voice vtable[0] = sub_8214E3E0 / sub_82150338 / sub_8214E5C0, `[engslow]`);
SPLIT (census aud1102i, per 60 s): sub_82150338 (the SFX source-voice render) is 75-77 % of the outer frame time -- 0.67-0.82 ms PER VOICE PER 5.33 ms FRAME (23k-31k calls/min, max 9-20 ms for ONE call), so 5-7 live SFX voices alone spend 4-5 ms of the 5.33 ms budget; sub_8214E3E0 (the always-present voice, likely the BGM/submix path) is 0.03-0.07 ms per call and sub_8214E5C0 0.07 ms. THE TARGET IS sub_82150338 (ppc_recomp.23.cpp, 287 lines: sub_82150148, sub_8214F080, 6 indirect calls) and its callees. Fix direction = make that render cheaper (vector path) or take the engine frame off the lock; no fix in rc4. Windows build_win_dll.sh gains the kiniro / kiniro_abn module arms (auto when
the trees exist); stage/smoke/gates follow every `futari_game_*.dll`. Evidence: BACKLOG.md 2026-11-02, NOTE_fnf_shell_defects.md 2026-11-02.
**rc4 CUT ON BOTH SEATS (2026-11-03 00:15); WINDOWS PUBLIC ZIP UPLOADED 2026-11-03 06:44 AUSEST** (user: "Yes, upload rc4") = GitHub
pre-release `v0.3.0-rc4` https://github.com/springah/futari_realcomp/releases/tag/v0.3.0-rc4 on the pushed tag, assets
`Futari-Realcomp-Windows-v0.3.0-rc4-public.zip` (digest 72cf9e04...9c79 confirmed by re-download) + `.sha256`; rc3 pre-release left in place.
The Windows F&F zip (with data) + README went to the F&F folder `Desktop/NSP/` (rc3 moved to `_superseded_rc3/`). The macOS asset-free zip was
ATTACHED to the same pre-release at 07:25 AUSEST (user: "Yes, attach macOS"; digest e553fa15...f3b2 confirmed by re-download; notes retitled
"Windows + macOS test builds", macOS section = Apple silicon only, self-signed -> quarantine/Open Anyway, Extract Game Data.command; Black Label
row greyed until the wizard takes your own DLC, both platforms). Same engine `1b03038` + decomp `1d79e20871bc` on both. Mac: `rc_cut_mac.sh
0.3.0-rc4` ALL-PASS (app_smoke, gstart, q1_ctest, q1_census PASS in both modes, rc_chain 352 PASS / 0 FAIL), 4-module bundle (Black Label
dylibs in), tags `v0.3.0-rc4` (realcomp) + `realcomp-v0.3.0-rc4` (decomp) pushed, F&F zip `_rc/Futari-Realcomp-macOS-v0.3.0-rc4.zip`
(720 MB, sha256 `5bba81f7ca8f18e5e019b51c6af4801ce67f95084fdd8c8ea194a77c7121af3e`, contains game data). Windows: `rc_stage_win.sh` +
`rc_gates_win.sh 0.3.0-rc4` -- boot_smoke / gstart / q1_ctest / rc_chain (418 PASS, 0 FAIL) PASS, q1_census FAIL on the known WIN-AUDIO-1
underruns only (ARCADE 156 / 360 247; 0 dropouts outside the named classes; `_rc/0.3.0-rc4-win/SMOKE.md`); FIRST WINDOWS BLACK LABEL BOOT
PASS (`_local/rc/bl_boot_win.sh`: modreg 4/4, modeIdx 4, swap to kiniro_normal, hub, 0 FATAL / UNMAPPED / kdrop); F&F zip
`_rc/Futari-Realcomp-Windows-v0.3.0-rc4.zip` (920 MB, sha256 `110609cf8c0a792a3d150476cd67800eb028c215825a2ffd2ae3c37d0afa1844`);
PUBLIC asset-free zip `_rc/Futari-Realcomp-Windows-v0.3.0-rc4-public.zip` (32 MB, sha256
`72cf9e0473367c42941a1b882d4288678cccaddec34dc43ee93100529b4d1c79`, game-data scan clean, wizard smoke PASS: extractor fed the gated tree ->
manifest match, 4/4 modules bound, 0 FATAL, 0 VK_ERROR). The Windows tree carries no rc4 tag of its own (the Mac cut's tag is the rc4 tag;
the Windows exe is the same commit). Owed: the hands checklist on both seats, the Mac F&F zip to whoever gets it, tester triage.

**macOS PUBLIC (asset-free) rc4 zip STAGED + SMOKED 2026-11-03 07:15 AUSEST -- UPLOADED 07:25 on the user's yes (see above).** New
`scripts/rc_stage_mac_public.sh` (twin of `rc_stage_win_public.sh`): copies the gated rc4 bundle minus `Contents/Resources/assets`, re-seals it ad hoc
(outer seal only: engine + 4 module dylibs + Frameworks BYTE-IDENTICAL to `_rc/0.3.0-rc4/MACHO_MD5.txt`, only the launcher's signature blob and
CodeResources change), ships the extractor with a macOS first-run path (`Extract Game Data.command` -> `tools/extract/extract_assets.sh`, the
`.bat` twin: Finder dialogs, or a path argument for scripted use; builds `assets/` BESIDE the .app, where `mac-build/launcher.c` already looks --
no code in the cut bundle changes; an in-launcher wizard would be a launcher.c change = rc5), README/BUILD/MD5 with `form=public-asset-free`,
the same docs; game-data scan clean (24 files, 114 MB; none of the 58 manifest names, no assets/shell/media, no .xex/.xgs/.xwb/.xsb/.bin/.lzx).
Output `~/Desktop/projects/_rc/Futari-Realcomp-macOS-v0.3.0-rc4-public.zip` (33 MB, sha256
`e553fa15a5076a3eebf0217851528e9c65c29f2b97f4205a41a1cb899532f3b2`) + `.sha256` / `.md5` / `.SMOKE.md`. Smoke `scripts/rc_smoke_mac_public.sh`
(new) ALL-PASS: unzip fresh -> seal verifies -> no game data -> the SHIPPED extractor fed the gated bundle's assets tree, then `_local/blroot` for
the DLC pass -> manifest 58/58 -> `app_smoke_mac.sh` on the unzipped .app PASS (4/4 modules bound, save written + read back) -> session log
build=1b03038, 0 FATAL, 0 VK_ERROR, 0 MoltenVK/Metal errors, game root = the beside-the-app assets/. Two landmines on the way: (1) a re-signed
bundle has a NEW cdhash, so macOS TCC prompts for Desktop/Downloads/Documents access on its first file read and the guest thread sits behind the
prompt (9 log lines, title never loads) -- the smoke unzips under `~/Library/Caches` and the README tells testers to click Allow; (2) the Mac's
gated assets tree carries no Black Label DLC (55/58 on its own; the extractor treats those 3 rows as optional), hence the DLC pass. The gated
bundle, its SMOKE.md and the F&F zip are untouched (Nov 2 mtimes). NOT attached to the `v0.3.0-rc4` pre-release: uploading is the owner's decision.

**🎉 BLACK LABEL RUNS, BOTH MODES (2026-10-31, Mac, opt-in build):** kiniro_normal (Black Label ARCADE, modeIdx 4) and kiniro_abnormal
(Black Label XBOX 360 MODE, modeIdx 5) boot as third/fourth module dylibs and play: title -> hub -> Mode Select (Original/Maniac/God) ->
Character Select (Reco & Kiniro) -> stage 1 -> GAME OVER -> replay prompt, 0 FATAL / 0 UNMAPPED / 0 kdrop on every drive. Needs
`MODULES="normal abn kiniro kiniro_abn"` and a PRIVATE game root with the user-extracted DLC (never assets/). 5 of 8 descriptor values are
live-controlled per module (entry, START EXCH, field_active, gm_frame_gate, mb_credited); asset_commit / mb_reload / mb_mode64 are structural.
Nav set (scene_fsm, select_d76, slot0, credit) live-controlled on both modules (`RT_NAVMOD`, identical 17-edge sequence vs the reco control).
Regression gate `scripts/kiniro_gate_mac.sh` (13 asserts + 2 pixel rungs, `KIN_MODEIDX=4|5`). The three calls were taken 2026-10-31 on
the user's "all three unattended": DATA PATH = player DLC folder `RT_DLC_ROOT` (default beside the saves) · BUILD SHAPE = Black Label
modules in the default Mac build when their trees exist (grey without data) · QUALITY BAR = the scorecard in PLAN_kiniro_bringup.md.
Still not in any cut; the next Mac cut (rc3) would carry Black Label unless the user reverts the build-shape call. **rc3 DRY RUN 2026-10-31
(`DRY=1 rc_cut_mac.sh 0.3.0-rc3-dry`, 4-module bundle): ALL-PASS after two script fixes (app_smoke pad delivery via `open --env`; N/N module
count in rc_chain/app_smoke) -- gstart, q1_ctest, q1_census both modes, rc_chain 15/15, app_smoke. Both Black Label attract soaks FLAT.
A real `0.3.0-rc3` cut needs only the owner's go (the ladder is the cut's smoke) plus the hands checklist afterwards.**

**Engine after rc2 (2026-10-30, unattended Mac seat):** G5-fix landed (`RT_POOLRELEASE`, ARCADE RSS ramp FLAT; DEFAULT ON for macOS/Linux by user ruling 10-30, `=0` reverts),
360 START-wire dshift fix (PLAN_RC1 §0.5 item 2 closed), RT_ROTATE=90|270 rotated present (iPad half 1), Black Label kiniro trees
regenerated (steps 0-2, docs/PLAN_kiniro_bringup.md). Evidence: NOTE_fnf_shell_defects.md 2026-10-30, BACKLOG.md 2026-10-30. None of
it is in a cut; rc2 stays the RC pointer below until the user signs it off; these ship with rc3 / the next cut.

**RC pointer (2026-10-24):** `0.3.0-rc2` CUT, scripted smoke ALL-PASS (app_smoke, gstart, q1_ctest, q1_census, rc_chain), awaiting hands sign-off. futari_realcomp `e3ccb8a5f633` (tag `v0.3.0-rc2`) + futari_decomp `1d79e20871bc` (tag `realcomp-v0.3.0-rc2`); bundle `~/Desktop/projects/_rc/0.3.0-rc2/Futari Realcomp.app`; zip `_rc/Futari-Realcomp-macOS-v0.3.0-rc2.zip` sha256 `10e652009c16ae42644762edf44ea87325f3a23cbaf546a28ed5e90f67f354a9`. (0.3.0-rc1 = realcomp `9aed8d4` + decomp `0ff2927d`, superseded.) Never edit or re-zip a cut bundle; a fix means rc3.

**Windows rc2 (2026-10-29, PC seat) -- STAGED + GATED, untagged:** `scripts/rc_stage_win.sh 0.3.0-rc2` from realcomp `adfaaf6` (= e3ccb8a + the
Windows build-loop fix 34a9402 + the RT_PAD_HOST_FIFO Windows arm, host-only, inert by default) against the same futari_decomp `1d79e208` ->
`../_rc/0.3.0-rc2-win/Futari-Realcomp-Windows-v0.3.0-rc2/` + `../_rc/Futari-Realcomp-Windows-v0.3.0-rc2.zip` (915 MB, assets inside: F&F only).
Decomp objects shell 244 / arcade 55 / 360 9, identical to the Mac cut. **The Mac RC gates now run on Windows** (`scripts/rc_gates_win.sh <ver>`;
`*_win.sh` generated from the Mac originals by `scripts/win_port.sh`; table `../_rc/0.3.0-rc2-win/SMOKE.md`): boot_smoke PASS, gstart PASS (10 + 9
probes, 0 leaks), q1_ctest PASS (60/60), rc_chain PASS on every leg once the harness shim gaps were fixed (A swap x5, B, C, D, E remap, T2, CX, both
modes; 350+ PASS lines), q1_census: **FAIL on AUDIO RING UNDERRUNS in the hands-off demo loop** (ARCADE 6/6 legs: 3,507 / 205 / 129 / 276; WASAPI sink 5,618;
RT_VBSLEEP=0 206; XBOX 360 1/3 legs: 311; Mac 0; pacing/dropouts clean) -- an OPEN engine finding, bursts at the attract loop's scene changes coinciding with texture re-decode storms:
docs/NOTE_fnf_shell_defects.md 2026-10-29. USER RULING 10-29: not audible -> KNOWN ISSUE (docs/RC_KNOWN_ISSUES.md, Windows-only line), investigation
PARKED (BACKLOG WIN-AUDIO-1). No `v0.3.0-rc2-win` tag until the user signs the Windows bundle off; a fix is rc3. Why the Windows build had been broken since w159:
build_win_dll.sh compiled decomp/shell TUs with the game tree's include set (34a9402).

**Windows rc3 PUBLIC PRE-RELEASE (2026-11-01 night):** tag `v0.3.0-rc3` @ 0484a3b (docs/scripts-only above engine b559e8c) -> https://github.com/springah/futari_realcomp/releases/tag/v0.3.0-rc3 -- asset-free zip `Futari-Realcomp-Windows-v0.3.0-rc3-public.zip` (28 MB, sha256 `95d07d7b53cf1c350cf1d2a06be8b2927996099d8ad324dacbe319218357fc58`) staged by `scripts/rc_stage_win_public.sh` (STAGING.md form: launcher + wizard extractor + manifest + docs + save template; NO assets/ or shell/). Wizard-smoked: extractor fed the gated F&F assets tree -> 58/58 manifest, shell/default.xex staged, `rc_smoke_win.sh` PASS (both modules bound, 0 FATAL, 0 VK_ERROR). Same engine bytes as the F&F zip below. macOS stays at rc2.

**Windows rc3 (2026-11-01, PC seat) -- STAGED + GATED, untagged, in Desktop/NSP as a friends-and-family zip:** `scripts/rc_stage_win.sh 0.3.0-rc3`
from realcomp `b559e8c` against futari_decomp `1d79e208` (same decomp as rc2) -> `../_rc/0.3.0-rc3-win/Futari-Realcomp-Windows-v0.3.0-rc3/` +
`../_rc/Futari-Realcomp-Windows-v0.3.0-rc3.zip` (915 MB, assets inside: F&F only; sha256 `32124b1c9dbb6cda645c96a7b308c3bd34a8515cf0e62d81faeadf2e8c6dab09`).
Two-module shape (ARCADE + XBOX 360 MODE); Black Label is NOT in the Windows build (build_win_dll.sh has no module-4/5 arm). What rc3-win carries over
rc2-win: the 360 START-wire fix, RT_ROTATE, the read-only DLC-root plumbing (inert without data), and two Windows-seat fixes: (1) **the Windows build had
been REFUSED since the 10-31 Black Label divide-guard twin** -- `out_reco_abn/tools_abn/gen_symbol_map.py` scans merged_game.cpp textually and the
`#if FUTARI_MODULE == 4 || 5` twin (sub_88225C28/30, +8 apart) tripped CHAINED EXPANSION; 6638c00 `strip_foreign_modules()` drops branches that only
other modules compile (emitted map byte-identical to the checked-in one, negative control reproduces the abort); (2) **keyboard input is ignored while
the game window is not in front** (user todo 11-01; b559e8c: GetAsyncKeyState is global, so a parked game fired on ordinary typing; host FIFO still merged,
`RT_PAD_UNFOCUSED=1` restores the global read, focus edges logged). RT_POOLRELEASE is **always off on Windows** (rt_phys.cpp `#ifdef _WIN32`), so the
ARCADE memory ramp known issue still applies there (RC_KNOWN_ISSUES says so). Gates `scripts/rc_gates_win.sh 0.3.0-rc3` on the final bytes
(`../_rc/0.3.0-rc3-win/SMOKE.md`): boot_smoke PASS, gstart PASS (10 + 9 probes, 0 leaks), q1_ctest PASS (60/60), rc_chain PASS (all T2 CX, 418 PASS /
0 FAIL), q1_census **FAIL on the Windows-only audio ring underruns only** (ARCADE 282, 360 345; pacing 59.7-59.97 fps every minute in both modes,
0 dropouts outside the named classes) -- the same known-issue class rc2-win failed on (user ruling 10-29, WIN-AUDIO-1). A FIRST gate run on the
6638c00 engine had shown XBOX 360 MODE at ~52 fps for six minutes: an A/B census (rc3 engine vs the rc2 engine, `_local/rc/ab_1101/AB_VERDICT.md`)
and the final run put it down to MACHINE CONTENTION (the user's futari_recomp F&F copy was running alongside), not an rc3 regression. No `v0.3.0-rc3`
tag (the owner's / the Mac cut's act). Still open from the Windows seat: CLEAN QUIT from the title (user todo 10-31), WIN-AUDIO-1.

**RC1 state (2026-10-12):** the release-candidate state for the two hosted modes (ARCADE 1.5 Original + XBOX 360 MODE) is
`docs/PLAN_RC1.md` **§0 RC1 SCORECARD** (per-criterion status, what is left, rulings recorded/open); the proposed cut is
§6 FREEZE & SHIP PLAN (version `0.3.0-rc1`; tag `v0.3.0-rc1` plus both repos' hashes recorded here and in the bundle README
when cut). Engine commit today: futari_realcomp `main` @ `d3c9b23` (KSTUB-OVERCLEAR fix; includes the G-START fix 619a190),
futari_decomp @ `6fc61986`. No RC1 cut exists yet; the `.app` on disk predates both fixes.

**Other modes (2026-10-12):** scoped in `docs/PLAN_other_modes.md` (Arrange/Novice, Ver 1.01, Black Label; start after the RC1 cut).

**Where the live state is:** the campaign ledger in the sibling repo,
`../futari_decomp/docs/NOTE_campaign_decomp.md` (top block = current state, then the ranked
owed list for the next window). The scoreboard is `../futari_decomp/docs/progress_treemap.html`
(metric definitions: `PLAN_FULL_READABLE.md` §1.1 — headline is DONE = MATCHED+CONVERTED over
AUTHORED insns).

**Beta 3 (10-04 late):** the first macOS family-and-friends build, TWO modes (`build_mac_dll.sh` host + module dylibs;
the Xbox 360 tree regenerated here with the reconstructed eqv-fixed recompiler, `scripts/regen_abn_mac.sh`), all
bundle checks PASS -- docs/PLAN_beta3_mac.md and NOTE_fnf_shell_defects.md 2026-10-04. Zip on the Desktop; SHARED owed.

**This repo today (10-05):** the port now lives on the user's Mac (arm64, MoltenVK, SDL3; `build_mac.sh`,
`scripts/run_mac.sh`) and ships as a double-clickable family-and-friends bundle (`mac-build/build_mac_app.sh` ->
`~/Desktop/projects/Futari Realcomp.app`, game data inside). Since 10-03: boss-1 head and FNF-15 root-caused and
fixed, three constant typos + one missing-register miss + an arm3 operand slip found by the two new audits
(futari_decomp tools/instruments/constpool_audit.py, regcontract_audit.py) and fixed, the RT_TXTNODE hook
restored, FrameDelay 2V/3V un-pacing fixed (RT_FDPACE), FNF-14's in-game half measured (PLEASE WAIT, not black),
D3 wall-dim moot on the ship path, the save card's layout/FrameDelay bytes pinned, B3 round-trip passing.
Gates that run unattended here: the boss plate gate (`scripts/boss1/boss_plate_gate.sh`, pixel + structural, last
all-game sweep PASS), the stage pixel gate (`scripts/stagepix_mac.sh`, PASS), both audits (0 DRIFT / 0 MISSING).
Still not shippable for the same reason as 09-04 -- the F&F gate is closed on shell-compose fidelity (flicker,
BACKLOG #0), whose ratified fix is the shell compositor decomp (Phase 2).

**This repo on 09-04 was:** the working native port — attract, menus, Normal Play, Training,
saves and native audio all run. Not shippable: the friends-and-family gate (07-26) is closed on
shell-compose fidelity (flicker), and the ratified fix is the shell compositor decomp. Game logic
has been untouched since 08-25; commits since then are harness-only instruments for the decomp
campaign. From r23-w86 realcomp carries a lane again (user ruling 09-04) — slate in the ledger.

**Hygiene conventions (09-04):** save directories for drives live under `_local/saves/`
(`RT_SAVE=_local/saves/save_<tag>`); only the three copy-from templates stay at the root
(`save_freshcard`, `save_r17_boss`, `save_eyeball`). Nothing under `_local/` is needed to build
or run.

The July asset-extraction prep note that used to live here is preserved unchanged at
`tools/extract/STATUS_day4_extract_prep.md`.
