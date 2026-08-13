# next_release staging checklist (Day-7 2026-08-14)

The versioned pieces live HERE (launcher, README, this checklist). Assemble a shippable
folder/zip like so — **NO GAME DATA GOES IN**:

1. Rebuild at the release commit: `bash build_win_dll.sh` → copy
   `build/futari_combined.exe`, `build/futari_game_normal.dll`, `build/futari_game_abn.dll`.
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
