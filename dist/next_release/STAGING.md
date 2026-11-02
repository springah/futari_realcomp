# next_release staging checklist (Day-7 2026-08-14)

The versioned pieces live HERE (launcher, README, this checklist). Assemble a shippable
folder/zip like so — **NO GAME DATA GOES IN**:

1. Rebuild at the release commit: `bash build_win_dll.sh` → copy
   `build/futari_combined.exe` + every `build/futari_game_*.dll` (the Ver 1.5 pair; from 0.3.0-rc4 also
   `futari_game_kiniro.dll` / `futari_game_kiniro_abn.dll` = Black Label, built when `out_kiniro*/` exist;
   the host prints `[modreg] N/N module DLL(s) bound` and the smoke asserts N == N).
2. Copy `Futari 1.5.bat` + `README.txt` (this folder).
3. Copy `tools/extract/` → `tools\extract\` (futari_extract.py, extract_assets.bat,
   manifest_v1.tsv — DESIGN.md is a dev doc, optional).
4. Copy `docs/DUMPING.md` → `docs\DUMPING.md`.
5. Copy `save_freshcard/` (runtime-generated template, not disc content).
6. ⛔ Do NOT copy: assets\ (user-supplied via the wizard), shell\ (default.xex IS disc
   content — the wizard stages it), logs, saves other than the template.
7. Smoke: run the bat in the staged folder with assets absent → the wizard must come up;
   feed a real dump → 58/58 manifest verify → game boots to the top menu.
   (Wizard tested end-to-end 08-13 from a bare staged folder; re-smoke per release.)
8. The exe's `[env] build=` banner must name the release sha, not -dirty.

Attended acceptance still owed before a PUBLIC bundle: one user-driven wizard run (B3-class)
+ the user's own play sign-off. Go-public remains the user's call.

**2026-11-01: steps 1-6 + the game-data scan are scripted** -- `bash scripts/rc_stage_win_public.sh <version>` (the public twin of
`rc_stage_win.sh`) builds `../_rc/<version>-win-public/Futari-Realcomp-Windows-v<version>/` + `../_rc/Futari-Realcomp-Windows-v<version>-public.zip`
from the gated `build/` bytes and refuses any `.xex` / `media` / `assets` / `shell` path in the output. Step 7 recipe without a console dump:
copy the staged folder, run `tools/extract/futari_extract.py <gated F&F assets folder> --out <copy>/assets --shell <copy>/shell` (the
"already-extracted disc folder" input), expect `Done. assets/ matches the reference manifest.` (58 files) + `shell/default.xex`, then
`bash scripts/rc_smoke_win.sh <copy>`. First public form: 0.3.0-rc3 (GitHub pre-release).
