# PLAN — after the boss-1 head fix (written 2026-09-20, user-ratified: "it all makes sense to me")

Context: the 09-20 attended realcomp day found FNF-14 (NOW LOADING black) was a decomp-TU regression
(float pool anchored 0x40 low in decomp/shell/logo_indicator.cpp, fixed b346eb1) — the SAME class as
the 08-15 logo-key fix. The boss-1 head L/R swap is still open at the time of writing; both control
DLL arms (boss-vein TU reverted; asset-pipeline TUs reverted) reproduce it, the vertex stream is
guest-faithful, and the user remembers it correct in an earlier build ⇒ a port regression to bisect.

## Phase 0 — close the boss-1 head (in flight)
1. Finish the training-mode boss route (hub TRAINING → mode → stage select RIGHT → START → char → shot);
   it makes every drive ~2 min instead of ~5. Bank the recipe in scripts/futari_nav.sh + NAV_MAP.md.
2. Bisect by build: _local/build-output/futari_merged.exe (08-07), build/futari_ctrl.exe (08-14),
   build/futari_combined_ada145c1_w19ref.exe (08-22), futari_merged_v154hi.exe (08-27), then git
   bisect realcomp between the last-good and first-bad dates. Every point = one training drive +
   the mirrored-twin rect signature + a head crop (scratch tooling: boss1_drive.sh, headframes.py).
3. Root-cause, fix, verify with the same instruments, ledger it in NOTE_fnf_shell_defects.md, close
   the BACKLOG FIDELITY DEBT line, memory update. Owed to user eyes: the fixed head on their build.

**STATUS 09-20 21:40 (USER STOP — "bank and pivot back to decomp"):** Phase 0 step 1 DONE (route works, scripts/boss1/); step 2 NOT run (old builds need the cursor-tracking driver); step 3 open. New defect FNF-15 (training panel rows not drawn) found on the way, control-proven readable-C, single-TU arms built, bisect unrun. Both parked in NOTE_fnf_shell_defects.md 2026-09-20 FNF-15. Next lane per the user: DECOMP (Phase 2).
**10-03 (Mac):** FNF-15 CLOSED — TU bisect → function knock-out → read → one-line fix (NOTE_fnf_shell_defects.md
2026-10-03). Boss-1 head still open; the Mac's 48 s builds make the Phase 0 step-2 bisect cheap now.
**10-04 (Mac, overnight):** BOSS-1 HEAD CLOSED — Phase 0 done. Culprit objaction_queue.cpp (two operand slips in the
straight-ahead pose's second mosaic pair), named by the all-game revert arm + per-push trace diff; see
NOTE_fnf_shell_defects.md 2026-10-04. The boss plate gate (Phase 1 item 2) now has its reference frames in _local/boss1_mac/.

## Phase 1 — realcomp (attended, small)
1. **Constant-pool audit tool** (Sonnet-tier, mechanical, HIGHEST YIELD). For every readable-C TU
   in futari_decomp (shell + game): re-derive each `lis/addi(s)/ori`-anchored constant from the
   generated body it transliterates (the TU cites its ppc_recomp file:line), diff against the TU's
   constexpr table, and read the pool value out of reference/ghidra_futari_decomp/default.img.bin
   / reco_normal.img.bin. Output = one TSV row per constant: TU, name, TU addr, generated addr,
   delta, value-at-each. Acceptance: reproduces BOTH known defects (logo keys 0x40, float pool 0x40)
   as positive controls; zero deltas elsewhere or a named list to fix. Run it BEFORE any further
   shell promotion, and make it part of the promotion gate (LAWS entry).
   **✅ DONE 10-04 (Mac):** `futari_decomp/tools/instruments/constpool_audit.py` — selftest PASS on both
   positive controls (+ a third, famk1) and the HEAD negative; sweep = 0 DRIFT across 62 TUs, but
   **3 live constant typos in promoted TUs** (famk1 G_RNG_SEED/G_JUMPTAB high half, famk9 G_HALT
   −0x20) — fixes owed, then re-gate those families. LAWS T7/M4 carry the gate. Ledger 10-04.
2. **Boss plate gate for game-side promotions.** A training-mode stage-1 boss drive on pilot +
   control arms, scored by (a) the mirrored-twin rect signature (same cell, same flip, same
   positions) and (b) a head-crop pixel diff. Costs ~5 min per gate. Add to the DRIVER gate
   ladder next to the stage pixel gate, which only ever saw early-stage frames.
   **✅ DONE 10-04 (Mac):** `scripts/boss1/boss_plate_gate.sh <tag> <tu>...` (+ `boss_plate_gate.py`, ~6 min/gate): pilot vs
   generated-body control, head-symmetry pixel plate + anchor-relative per-push signature on lockstep frames (QUIET=10
   input-free intro), M4 controls (`--selftest`, `NEGCTL=1`). First run: pixel PASS but structural FAIL = a second
   objaction_queue defect (sel==3 indexed sub-arm: 9-px sense inverted ×2, dropped G-15600 word) — fixed, plate_v3 PASS
   with famk1/famk9 in the control arm (their constant fixes re-gated). NOTE_fnf_shell_defects.md 2026-10-04 (later).
3. **FNF-14 follow-ups (user eyes):** boot overlay feel (≈1.5 s + 1 s fade because the port loads
   fast; any hold is a ruling, never a silent fix); whether in-GAME stage loads show NOW LOADING
   (game-module path, unmeasured). If black, re-run the FNF-14 ladder on that path.
4. **Parked debts, in order, ~1 h each:** FrameDelay 3V feel check (ring positive control) ·
   D3 wall-dim 0.875 vs 0.90 quantisation · Color/ExtraView sub-offsets (doc) · B3 menu save
   round-trip (user's hands).
5. **Leave alone:** flicker (superseded by compose 1:1) · title blink / card fragment (authentic) ·
   swap-stale heap descriptors (post-beta research).

## Phase 2 — decomp campaign (resume the slate)
1. Resume **w130 as slated**: two game lanes by parity, Sonnet, mechanical classes only; the shell
   Sonnet pools are exhausted (savegprlr → Opus).
2. Next **Opus window**, in order: `__savegprlr_NN` convention (21 shell hits, unblocks a class) ·
   built-TU seam probe (10 probes) · swapped-register lever · cost estimate for ≥ 6 families.
3. **Rulings owed by the user** (one line each): ⚖ w121-1 · ⚖ w125-1 · ⚖ w117-2 · ⚖ w129-U1.
4. **Header harvest** owed (input bank/r23/w127/toolsn_m4_reconciled_w127).

## Process change (applies to both repos)
A TU promotion that touches constants, orientation, or a mirrored/paired draw carries TWO extra
artefacts: the constant-audit TSV for that TU (Phase 1.1) and a content-specific plate that
exercises the thing it draws (Phase 1.2). The generic census/runtime gate stays; it is necessary,
not sufficient — it passed both 0x40 regressions.

## Landmines to carry (bank/r23/w30 + 09-20)
`source bank/r23/w30/w30_toolchain_env.sh` before any build · Git-Bash `sed -i` strips CR from CRLF
files · `taskkill //F` is not slash-converted under MSYS_NO_PATHCONV=1 (use Stop-Process) ·
`sleep` is blocked in foreground tool calls · PrintWindow sees no window from the harness — use
`RT_NVKPNG=N` (nvk path), not RVK_PNGEVERY · `RT_NVKVTXALL` is capped at 6000 lines per session —
gate with `RT_NVKDBGFROM=<frame>` (added 09-20) · RT_MODDLL_DIR takes forward slashes.
