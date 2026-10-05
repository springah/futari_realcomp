# PLAN — beta 3: the first macOS family-and-friends build (two modes)

Ratified 2026-10-04 (user: "two modes for macos pls. flicker will need retesting anyway. otherwise do the
recommended"). Beta 1 (07-26) and beta 2 (08-15) were Windows; this is the first Mac cut. The gate that closed
F&F on 07-26 (shell-compose flicker, BACKLOG #0) is consciously shipped as a KNOWN ISSUE for testers to
characterise; its ratified fix stays Phase 2 (the shell compositor decomp).

## Decisions
- **Two modes.** The Mac bundle hosts ARCADE 1.5 (reco_normal) AND XBOX 360 MODE (reco_abnormal) through the
  module arm (host/module_registry.cpp, now with a dlopen arm; `build_mac_dll.sh`), the same shape as the
  Windows beta-2 combined exe. Ver 1.01 and Black Label stay greyed ([modestub]).
- **Flicker ships as a known issue**, named in the bundle README with a reporting recipe.
- **Apple silicon + macOS 13 Ventura or newer.** No Intel slice.

## Todo (status in brackets)
1. [DONE] Deployment target: `MACOSX_DEPLOYMENT_TARGET=13.0` in `build_mac.sh`, `build_mac_dll.sh` and the bundle
   script (which refuses a binary stamped otherwise); SDL3 reconfigured with `-DCMAKE_OSX_DEPLOYMENT_TARGET=13.0`.
   The 10-04 bundle had minos 27.0 on the engine, the launcher and SDL3 (MoltenVK 12.0).
2. [DONE] The XBOX 360 tree on the Mac: `out_reco_abn/` regenerated with the eqv-fixed recompiler
   (`tools/xenonrecomp_mac_eqv_fixes.patch`, `scripts/regen_abn_mac.sh`); validated against the tracked
   reco_normal tree (residual = exactly the 41 FIX-2026 hand patches, now emitted mechanically, + 24 harness
   tap hunks). The regenerated abn tree carries all 41 fixes; the Windows beta-2 abn DLL carried only the
   handful ported into its five tapped TUs.
3. [DONE] `build_mac_dll.sh`: combined host + two module dylibs link and boot; `[modreg]` binds both; ARCADE and
   XBOX 360 both reach stage 1; A -> B -> A swap cycle clean (the Windows D1 full-loop re-pair, on the Mac).
4. [DONE] The bundle itself (`mac-build/build_mac_app.sh`, VER 0.2.0-beta3): Finder launch -> title -> both modes
   -> game over -> top menu -> quit; the save lands in Application Support and reads back next launch.
5. [DONE, re-run 10-05 noon on the RT_VBSLEEP engine] Soaks on the bundle: shell title 30 min (RSS 268->277 MB flat, 0 errors,
   ~25% of a core) AND the ARCADE demonstration 20 min (15 attract cycles, RSS cycling 202-425 MB, 0 errors;
   scripts/demo_soak_mac.sh); FrameDelay 1V/2V/3V paced.
6. [DONE, re-run 10-05 noon] Gates on the final tree: both audits clean (0 DRIFT / 0 MISSING); stagepix bundle-vs-merged in
   the chain; boss plate gate A/B of RT_VBSLEEP=0 vs default PASS (both witnesses); all-game sweep (38 TUs, without the renderer bridge) PASS
   (both witnesses) on the RT_VBSLEEP tree -- _local/boss1_mac/gates_vbsleep.txt.
7. [PART] README (in the bundle), Gatekeeper steps for macOS 15+, `ditto -c -k --keepParent` zip. Distribution: Google Drive
   via rclone (`scripts/upload_gdrive.sh`, remote `gdrive` = springah@gmail.com scope drive.file, folder
   Futari-Realcomp/<VER>/; set up 10-05 while the NAS was down) -- the SHARED share copy stays owed for the archive.
   Game data inside: never public (F&F links only).
8. [USER] Eyes: boot overlay feel; 3V feel; two-pad couch session; fullscreen/Retina on a smaller display.

Results: NOTE_fnf_shell_defects.md 2026-10-04 beta-3 entry (all PASS; the zip is on the Desktop, SHARED owed until
the NAS is reachable).

## Steam Deck (added 10-04 night, user "go")
- [DONE] Linux two-mode engine built from the Mac in a Rosetta container (`mac-build/deck/`, `build_linux_dll.sh`);
  headless boot binds both modules; package staged + zipped (`Futari-Realcomp-Deck-v0.2.0-beta3.zip`).
- [DONE 10-05] First boot on the Deck: failed on the undefined Wayland surface extent, fixed (vk_render.cpp,
  e3512aa); renderer up on RADV, frames at full rate. SEEING it needs a Steam-launched run: docs/DECK.md.
- [USER] Steam shortcut launch with eyes on it; controller under Steam Input; pacing retest.
- [DONE 10-05] Upload route: Cloudflare quick tunnel over a loopback http.server (`~/Desktop/projects/_serve/`),
  AppImage (`mac-build/deck/make_appimage.sh`) alongside the zip; the Deck pacing retest under RVK_DECOUPLE stays
  (BACKLOG #12's first measurement).
- [DONE 10-05 noon] Artefacts re-checked against the RT_VBSLEEP host (79b314e): the AppImage (10:39) and the Mac zip
  (10:50) already carried it; the Deck zip (09:55) did not and was re-zipped from the staging tree (same 59-file set).
  md5: Deck zip eca8474b…, AppImage 30b876e8…, Mac zip 93089b95… -- the set to copy to SHARED when the NAS answers.

## Post-beta (not blocking)
- Phase 2 compositor decomp (the flicker).
- MoltenVK device-loss behaviour (die-loud path exists; never exercised here).
- Port the five tracked abn TUs' harness taps forward if the abn tree is ever regenerated upstream.
