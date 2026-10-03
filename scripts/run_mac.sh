#!/bin/bash
# run_mac.sh — attended-session drive of build/futari_merged on macOS (2026-10-03 bring-up).
# The env set is scripts/EYEBALL_0811.cmd's (the Windows attended session) minus the levers that
# are Windows-only (RT_INDCENSUS, the decomp-campaign harvest, is opt-in: RT_INDCENSUS=1). Keyboard:
# arrows = D-pad, Z=A(shot) X=B(bomb) C=X V=Y, Enter=START, RShift=BACK -- the window must have focus.
# Controllers come through SDL3. Sound: PCM BGM through the SDL3 sink (CoreAudio); compressed xWMA
# SE/voice through libavcodec when build_mac.sh found Homebrew ffmpeg. Game data: assets/ (RT_GAME_ROOT) and the shell
# xex at assets/default.xex (XR_SHELL_XEX -- the Windows scripts use a duplicate at shell/default.xex).
#   RUN_SECS=<n>   kill after n seconds (default: run until the window closes)
#   RT_SAVE=...    override the save dir (default _local/saves/save_mac, created fresh if absent)
#   BIN=<exe>      run a different executable (bisect control arms)
set -u
cd "$(dirname "$0")/.."
BIN="${BIN:-build/futari_merged}"   # control-arm executables (scripts/boss1/fnf15_bisect_mac.sh) pass their own
[ -x "$BIN" ] || { echo "no $BIN -- bash build_mac.sh first"; exit 2; }
[ -f assets/default.xex ] || { echo "no assets/default.xex -- see docs/DUMPING.md"; exit 2; }
mkdir -p _local/logs _local/saves
export RT_GAME_ROOT="$PWD/assets"
export XR_SHELL_XEX="${XR_SHELL_XEX:-assets/default.xex}"
export RT_SAVE="${RT_SAVE:-_local/saves/save_mac}"; mkdir -p "$RT_SAVE"
STAMP=$(date +%Y%m%d_%H%M%S); LOG="_local/logs/mac_$STAMP.log"
export RT_BOOT_SHELL=1 RT_THREADS=1 RT_DEFERDRIVER=1 RT_ASYNCIO=1 RT_EHCONTAIN=1 RT_AUDIOPUMP=1
export RT_AUDIO=1 RT_AUDIOWORKER=1 RT_AUDIOBRIDGE=1 RT_CUEBRIDGE=1
export RT_VK=1 RT_NVK=2 RVK_PERSIST=1 RVK_RENDER_FROM=1 RVK_NOHALVE=1 RVK_FIXVP=1 RVK_BLEND=1 RVK_REALALPHA=1
export RT_WALLPAPER=1 RVK_TEXPITCH=1 RVK_FMT3KEY=1 RVK_GPFIELD=1 RVK_C255=0.00625:0.00390625:-1:0
export RVK_RESALIAS=1 RVK_RESFRESH=1 RVK_FIXB2=1 RVK_RESREAL=1 RVK_HDR=0
export RVK_WINDOW=1 RVK_WINSIZE="${RVK_WINSIZE:-1280x720}" RVK_DIMFIX=1
export RT_NAVREAL=1 RT_STARTWIRE=1 RT_SNDQFREE=1 RT_RESCACHE=1 RT_HEAPLOCK=1
export RT_PAD_HOST=1 RT_AUDIOXWMA=1   # keyboard via the SDL window (focus it); xWMA SE/voice via libavcodec
export RT_TRAINPROBE=1                 # logs the shell->game training-flow payload ([trainprobe], two lines per launch; byte-inert)
export RT_SAMPLES="${RT_SAMPLES:-0}"   # 0 = attended: no SIGALRM hang sampler (harness.cpp RT_BOOT_SHELL arm)
echo "log: $LOG"
"$BIN" 8208A2B8 0 "$XR_SHELL_XEX" 2>"$LOG" &
PID=$!
if [ -n "${RUN_SECS:-}" ]; then
  ( sleep "$RUN_SECS"; kill -TERM "$PID" 2>/dev/null ) &
fi
wait "$PID"; echo "exit=$? log: $LOG"
