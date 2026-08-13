Mushihimesama Futari Ver 1.5 - native PC port (realcomp)
=========================================================

WHAT THIS IS
  A native Windows build of the Xbox 360 release, statically recompiled.
  ONE exe hosts BOTH game modes as hot-swappable modules:
    - ARCADE 1.5    (reco_normal)
    - XBOX 360 mode (reco_abnormal / Ver 1.5 hi)
  Pick a mode at the in-game top menu. Quit back to the menu to switch
  modes - the module swaps live, no relaunch.

THIS PACKAGE SHIPS NO GAME DATA
  You supply your own copy of the game. On first run the launcher walks
  you through it: drag in either the game folder copied off your own
  console's storage (the "435A07D7" folder) or your disc ISO, and the
  built-in extractor builds assets\ from it - verified byte-for-byte
  against the console's own integrity hashes and a reference manifest.
  If you own the Black Label DLC, it can be added in the same step and
  unlocks Black Label on the top menu.
  Full dumping instructions: docs\DUMPING.md.  Requires Python 3
  (python.org) for the one-time extraction.

RUN
  Double-click "Futari 1.5.bat".
  First run: the extraction wizard above, then a fresh save is copied
  from save_freshcard\ to save\.

CONTROLS
  START/Enter = start + confirm, A/Z = shot, B/X = bomb,
  D-pad/stick or arrows = move. XInput pads supported.
  A second XInput pad is PLAYER 2: press START on it at the character
  select (or pick 2P SIDE START) to join.
  F11 = toggle fullscreen/windowed (aspect kept, bars on ultrawide).

SOUND
  The in-game OPTIONS > SOUND > BGM/SE sliders are the mixer and they
  persist in the save. Levels mirror the original game data 1:1.

SETTINGS
  The in-game OPTIONS menus are fully live: screen rotation (TATE),
  layout/extra-view presets, picture effects, brightness, drop shadow,
  controller remap - all applied by the game itself and saved.

NEW SINCE BETA 1
  - The game data now comes from YOUR dump (extraction wizard above);
    nothing copyrighted ships in this package.
  - 2-player co-op works: second pad joins at character select.
  - Frame pacing: game logic now runs on a dedicated 59.94 Hz clock
    exactly like the console, independent of render speed.
  - The mode-switch freeze from BETA 1 is fixed (several swap bugs
    root-caused: texture identity across swaps + a parked-thread drain).
  - Full-loop stability: boot -> play -> game over -> menus validated
    unattended on both modes.

KNOWN ISSUES
  - Report anything with the session log (see below).

FILES
  futari_combined.exe        the game (both modes)
  futari_game_normal.dll     ARCADE 1.5 module
  futari_game_abn.dll        XBOX 360 mode module
  Futari 1.5.bat             launcher (+ first-run extraction wizard)
  tools\extract\             the asset extractor + reference manifest
  docs\DUMPING.md            how to dump your game + DLC
  assets\                    built by the wizard from YOUR dump
  save\                      your settings + scores (safe to back up)
  save_freshcard\            fresh-save template (used on first run)
  logs\                      one log per session - attach to bug reports

BUG REPORTS
  Attach the newest file from logs\ and say which mode you were in and
  what you were doing.
