# STATUS — futari_realcomp (pointer, 2026-10-12)

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
