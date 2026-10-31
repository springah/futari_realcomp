#!/bin/bash
# app_smoke_mac.sh [APP] -- the BUNDLE smoke (beta 3 todo item 4): launches the .app the way a tester does (LaunchServices,
# `open -a`), drives it through the pad FIFO (title -> top menu -> card panel -> ARCADE -> hub -> back to the top menu),
# quits it through the app's own Quit (SDL_EVENT_QUIT), then checks: the session log landed in ~/Library/Logs, the save
# landed in ~/Library/Application Support, both modules bound, no FATAL; relaunches and checks the save is read back.
# The pad FIFO reaches a LaunchServices-started process through launchctl setenv (cleared again at the end).
#   bash scripts/app_smoke_mac.sh "$HOME/Desktop/projects/Futari Realcomp.app"
# TWO bundles can be on disk (the desktop dev .app and an _rc/<ver> bundle, same CFBundleIdentifier): everything here targets $APP BY PATH --
# `open -a "$APP"`, quit through `tell application "<path>"`, and kill/wait only engines whose command line is inside $APP (never the other
# bundle's futari_merged). The caller (scripts/rc_cut_mac.sh) holds /tmp/futari_drive.lock and has checked no other futari_merged runs.
set -u
cd "$(dirname "$0")/.."
APP="${1:-$HOME/Desktop/projects/Futari Realcomp.app}"
[ -x "$APP/Contents/MacOS/Futari Realcomp" ] || { echo "no launcher in $APP"; exit 2; }
LOGS="$HOME/Library/Logs/Futari Realcomp"; SAVE="$HOME/Library/Application Support/Futari Realcomp/save"
FIFO=/tmp/futari_pad_app; echo 0 > "$FIFO"
trap 'launchctl unsetenv RT_PAD_HOST_FIFO' EXIT   # the one sanctioned launchctl use: always cleared, also on an early exit
ENG="$(cd "$APP" && pwd -P)/Contents/MacOS/futari_merged"   # the launcher execs the realpath
mine(){ local p; for p in $(pgrep -f -- "$ENG" 2>/dev/null); do ps -o command= -p "$p" 2>/dev/null | grep -qF -- "$ENG" && echo "$p"; done; }
if [ -n "$(mine)" ]; then kill $(mine) 2>/dev/null; sleep 2; fi   # a stale engine of THIS bundle only
FAIL=0; say(){ echo "[app] $*"; }
press(){ echo "$1" > "$FIFO"; sleep 0.25; echo 0 > "$FIFO"; say "pad $1"; }
waitlog(){ local pat="$1" n="${2:-40}" i; for ((i=0;i<n;i++)); do grep -q "$pat" "$LOG" 2>/dev/null && { say "marker: $pat"; return 0; }; sleep 0.5; done; say "TIMEOUT: $pat"; FAIL=1; return 1; }
launch(){ # $1 = tag
  PREV=$(ls -t "$LOGS"/futari_*.log 2>/dev/null | head -1)
  # 2026-10-31 (rc3 dry run): the launchctl route alone did NOT reach the bundle this time (the engine's [padhost] line came
  # up without "+ host FIFO" and every press timed out), so the variable also rides on `open --env`, which hands it to the
  # launched process directly (macOS 13+). launchctl stays for older `open`s; the trap still clears it.
  launchctl setenv RT_PAD_HOST_FIFO "$FIFO"
  say "launchctl getenv RT_PAD_HOST_FIFO -> '$(launchctl getenv RT_PAD_HOST_FIFO)'"
  open --env "RT_PAD_HOST_FIFO=$FIFO" -a "$APP" || open -a "$APP" || { say "open failed"; exit 1; }
  for ((i=0;i<40;i++)); do LOG=$(ls -t "$LOGS"/futari_*.log 2>/dev/null | head -1); [ -n "$LOG" ] && [ "$LOG" != "$PREV" ] && break; sleep 0.5; done
  [ -n "$LOG" ] && [ "$LOG" != "$PREV" ] || { say "no new log in $LOGS"; FAIL=1; return 1; }
  say "$1: log $LOG"
  waitlog "name='motion/title.lzx'" 120; sleep 4
  grep -a -q "padhost\] ACTIVE.*host FIFO" "$LOG" && say "pad FIFO wired ($(grep -a -o 'host FIFO [^ ]*' "$LOG" | head -1))" || { say "FAIL pad FIFO NOT wired into the app (no '+ host FIFO' on the [padhost] line) -- every press below will time out"; FAIL=1; }
}
quit(){ osascript -e "tell application \"$APP\" to quit" >/dev/null 2>&1; for ((i=0;i<20;i++)); do [ -z "$(mine)" ] && break; sleep 0.5; done
  if [ -n "$(mine)" ]; then say "FAIL: engine still running after Quit (path-targeted AppleScript quit)"; FAIL=1; kill $(mine) 2>/dev/null; sleep 2; else say "quit clean (no process left)"; fi; }

say "== launch 1: fresh"
launch first || exit 1
press 10; waitlog "SYS_BGM cue0 (mushifuta_Menu02)"; sleep 3
press 1000; waitlog "SYS_SE cue1 (SE_OK01)"; sleep 3.6   # the card panel honours no decide for 3.0 s (NAV_MAP)
press 1000; waitlog "\[modeidx\] .*ARCADE"; sleep 3
press 1000; waitlog "\[p0build\] menu_game_title" 60; sleep 2
press 2000; sleep 2; press 1000; waitlog "\[decide\].*item=-1\|vt=0x82050518" 30; sleep 4
quit
# every module the bundle carries must bind: "N/N module DLL(s) bound" (2/2 for the Ver 1.5 pair, 4/4 with Black Label, 2026-10-31)
grep -a -E "\[modreg\] ([0-9]+)/\1 module DLL\(s\) bound" "$LOG" | grep -q . && say "PASS all modules bound ($(grep -a -o -E '[0-9]+/[0-9]+ module DLL' "$LOG" | head -1))" || { say "FAIL modules not all bound ($(grep -a -o -E '[0-9]+/[0-9]+ module DLL' "$LOG" | head -1))"; FAIL=1; }
[ "$(grep -c FATAL "$LOG")" = 0 ] && say "PASS no FATAL" || { say "FAIL FATAL in log"; FAIL=1; }
grep -q "window closed by user\|SDL_EVENT_QUIT\|RETURNED" "$LOG" && say "PASS clean exit logged" || say "note: no exit marker in log"
ls "$SAVE"/435A07D7/00000001/systemdata.bin/savegame.bin >/dev/null 2>&1 && say "PASS save written under Application Support" || { say "FAIL no savegame.bin under $SAVE"; FAIL=1; }

say "== launch 2: the save must be read back"
launch second || exit 1
press 10; waitlog "SYS_BGM cue0 (mushifuta_Menu02)"; sleep 2
grep -q "existed=1" "$LOG" && say "PASS save read back (existed=1)" || { say "FAIL save not found on relaunch"; FAIL=1; }
quit
launchctl unsetenv RT_PAD_HOST_FIFO
[ $FAIL = 0 ] && echo "APP SMOKE: PASS" || echo "APP SMOKE: FAIL"
exit $FAIL
