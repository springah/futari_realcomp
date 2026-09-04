#!/bin/bash
# scripts/decomp_d1_gate.sh — MatchHarness drive for the "driver command surface" gate class
# (HUMAN_READABLE_DECOMP_PLAN §6 tooling gap 3; used to gate decomp/shell/driver_msgs.cpp on
# 2026-08-12 — see decomp/shell/DRIVER_NOTES.md §3).
#
# WHAT IT DRIVES: a nav-driven ARCADE NORMAL PLAY *entry* run — boot → top menu → arcade card →
# land → selects → stage → idle death — i.e. a real mode LAUNCH, which is where the GameDriverTask
# message wrappers actually fire. ⚠ The C1 boot→attract drive does NOT call them at all (measured:
# zero canary hits in a 95 s attract run), so never gate this family on it. The post-game-over
# return is attempted last and is the nav library's documented unreliable branch; its failure does
# not invalidate the message stream already captured.
#
# USAGE
#   EXE=./build/futari_ctrl.exe  LOG=_local/logs/d1_ctrl_a.log  bash scripts/decomp_d1_gate.sh
#   EXE=./build/futari_pilot.exe LOG=_local/logs/d1_pilot_a.log bash scripts/decomp_d1_gate.sh
#   python scripts/canon_seq.py _local/logs/d1_ctrl_a_seq.txt _local/logs/d1_pilot_a_seq.txt
# Protocol-only verdict (drops the render thread's msg-5 heartbeat, whose interleaving against the
# menu thread is meaningless): grep -av 'msg=5' each _seq.txt into new files, then canon_seq.py.
#
# ⚠ Run at least TWO control builds before believing a delta: the guest-STACK pointer printed as
# "msg=10 r4" has two arms across runs and is translation-INDEPENDENT (proven control-vs-control).
# Compare matched arms.
#
# Unattended-safe: FIFO pad only, own save dir, aborts if any futari process is already running.
set -u
cd "$(dirname "$0")/.." || exit 1
export MSYS_NO_PATHCONV=1
ROOT="$(pwd -W 2>/dev/null || pwd)"
export RT_GAME_ROOT="${RT_GAME_ROOT:-$ROOT/assets}"
export RT_SAVE="${RT_SAVE:-_local/saves/save_d1gate}"   # 09-04 hygiene: RT_SAVE dirs live under _local/saves/
export LOG="${LOG:-_local/logs/d1_gate.log}"
export FIFO="${FIFO:-/c/tmp/futari_pad_d1}"
mkdir -p _local/logs /c/tmp

PRE=$(powershell -NoProfile -Command "((Get-Process | Where-Object { \$_.ProcessName -like 'futari*' }).Id) -join ','" 2>/dev/null | tr -d '\r')
[ -z "$PRE" ] || { echo "!!! ABORT: a futari process is already running (pids=$PRE)" >&2; exit 1; }

export RT_BOOT_SHELL=1 RT_THREADS=1 RT_DEFERDRIVER=1 RT_ASYNCIO=1 RT_EHCONTAIN=1 RT_AUDIOPUMP=1
export RT_VK=1 RT_NVK=2 RVK_PERSIST=1 RVK_RENDER_FROM=1 RVK_NOHALVE=1 RVK_FIXVP=1 RVK_BLEND=1 RVK_REALALPHA=1
export RT_WALLPAPER=1 RVK_TEXPITCH=1 RVK_FMT3KEY=1 RVK_GPFIELD=1 RVK_C255=0.00625:0.00390625:-1:0
export RVK_RESALIAS=1 RVK_RESFRESH=1 RVK_FIXB2=1 RVK_RESREAL=1 RVK_HDR=0 RVK_WINDOW=1 RVK_WINSIZE=960x540
# RT_NOPAUSE=1 below is HARNESS-ONLY, NEVER SHIP (w50 adjudication D7: ship default is env-unset = the authentic pause, w45-measured; np1 exists because an unattended leg cannot press RESUME and the orphaned post-run pause -- w47, never rare -- would wedge every leg)
export RT_NAVREAL=1 RT_SNDQFREE=1 RT_NOPAUSE=1 RT_RESCACHE=1 RT_HEAPLOCK=1 RVK_DIMFIX=1
export RT_MSGLOG=1 RT_STARTWIRE=1 RT_INPUTFORCE=1 RT_MENULOG=1
export RT_PAD=1 RT_PAD_FIFO=1 RT_PAD_FIFO_PATH="${RT_PAD_FIFO_PATH:-/tmp/futari_pad_d1}" RT_NAV_SEQ="9999999:START" RT_NOXINPUT=1

echo 0 > "$FIFO"
rm -rf "$RT_SAVE"; cp -r save_freshcard "$RT_SAVE"
: > "$LOG"
"${EXE:-./build/futari_merged.exe}" 8208A2B8 0 shell/default.xex 2>"$LOG" </dev/null >/dev/null &
PID=$!
source scripts/futari_nav.sh

nav_boot_to_topmenu           || { kill $PID 2>/dev/null; exit 1; }
nav_card_decide arcade 1      || { kill $PID 2>/dev/null; exit 1; }
nav_360_land_to_modeselect    || { kill $PID 2>/dev/null; exit 1; }
nav_selects_to_stage          || { kill $PID 2>/dev/null; exit 1; }
# RETURN leg (Day-7 re-pair): the Day-2 MAPPED NP game-over route replaces the old unreliable
# title flow — idle-die, B-poll the replay prompt (msg=10), START->hub (msg=11), B+A quit
# (msg=13, msg=3) -> shell TOP MENU. Fires the whole quit family into the captured stream.
sleep 50
nav_gameover_np_to_topmenu
nav_verdict; RC=$?

kill $PID 2>/dev/null; sleep 1
powershell -NoProfile -Command "Stop-Process -Id $PID -Force -ErrorAction SilentlyContinue" >/dev/null 2>&1
sleep 1
grep -a 'gemsg\|msglog' "$LOG" > "${LOG%.log}_seq.txt"
echo "[d1gate] seq lines=$(wc -l < "${LOG%.log}_seq.txt")"
echo "[d1gate] distinct sender lr values:"; grep -ao 'lr=0x[0-9A-F]*' "$LOG" | sort | uniq -c | sort -rn | head -20
echo "[d1gate] drvcanary:"; grep -a 'drvcanary' "$LOG" | sort | uniq -c
exit $RC
