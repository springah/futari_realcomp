#!/bin/bash
# drive_w75_replayprobe.sh <tag>
#
# r23-w75 DRIVER -- SECONDARY MISSION feasibility probe: can the NORMAL PLAY death flow save a
# replay (the prompt scripts/futari_nav.sh already maps at lines 171-186: リプレイを保存します
# か / A=はい(save) B=いいえ(decline) -- every existing nav function presses B). The ACCEPT branch
# has NO existing log marker (nav_gameover_np_to_topmenu's msg=10 poll is decline-branch-only) --
# genuinely unmapped territory, so this is a SINGLE bounded probe (ONE A-press, not a blind
# repeated-press poll loop like the decline path uses) rather than a scored leg: idle to death,
# press A ONCE, wait, screenshot, report whatever the log shows. Not a mission-1 deliverable --
# mission 1 (RT_TABREAD retry) already resolved this window; this only runs because budget
# remained. If this probe is inconclusive or ambiguous, it is named as such, not forced.
set -u
TAG="${1:?usage: drive_w75_replayprobe.sh <tag>}"

ROOT_DIR="C:/Users/shant/Desktop/projects/futari_realcomp"; cd "$ROOT_DIR" || exit 1
export MSYS_NO_PATHCONV=1
BANK="C:/Users/shant/Desktop/projects/futari_decomp/bank/r23/w75"; mkdir -p "$BANK/eyes"; mkdir -p /c/tmp

BIN="${BIN:-./build/futari_combined.exe}"
[ -x "$BIN" ] || { echo "!! missing host exe $BIN"; exit 1; }
CARDSAVE="${CARDSAVE:-save_freshcard}"
[ -d "$CARDSAVE" ] || { echo "!! missing card $CARDSAVE"; exit 1; }

export LOG="$BANK/${TAG}.log"
: > "$LOG"

export RT_GAME_ROOT="$ROOT_DIR/assets"
export RT_BOOT_SHELL=1 RT_THREADS=1 RT_DEFERDRIVER=1 RT_ASYNCIO=1 RT_EHCONTAIN=1 RT_AUDIOPUMP=1
export RT_VK=1 RT_NVK=2 RVK_PERSIST=1 RVK_RENDER_FROM=1 RVK_NOHALVE=1 RVK_FIXVP=1 RVK_BLEND=1 RVK_REALALPHA=1
export RT_WALLPAPER=1 RVK_TEXPITCH=1 RVK_FMT3KEY=1 RVK_GPFIELD=1 RVK_C255=0.00625:0.00390625:-1:0
export RVK_RESALIAS=1 RVK_RESFRESH=1 RVK_FIXB2=1 RVK_RESREAL=1 RVK_HDR=0 RVK_WINDOW=1 RVK_WINSIZE=1280x720
export RT_NAVREAL=1 RT_SNDQFREE=1 RT_NOPAUSE=1 RT_RESCACHE=1 RT_HEAPLOCK=1
export RT_MSGLOG=1 RT_STARTWIRE=1 RT_INPUTFORCE=1 RT_MENULOG=1 RVK_DIMFIX=1
export RVK_DIEHARD=1
export RT_PAD=1 RT_PAD_FIFO=1 RT_PAD_FIFO_PATH="/tmp/futari_pad_r23w75rp" RT_NAV_SEQ="9999999:START" RT_NOXINPUT=1
export FIFO="/c/tmp/futari_pad_r23w75rp"
export RT_SAVE="save_r23w75_${TAG}"
export RT_TRIOTAP=1

echo "[r23w75rp] tag=$TAG"

LOCKF="/c/tmp/.w75_drive.lock"
if [ -e "$LOCKF" ]; then
  OTHER="$(cat "$LOCKF" 2>/dev/null)"
  if kill -0 "$OTHER" 2>/dev/null; then echo "!! another w75 drive is LIVE (pid $OTHER) -- REFUSING."; exit 1; fi
  echo "[r23w75rp] stale lock from dead pid $OTHER -- reclaiming"
fi
echo $$ > "$LOCKF"
trap 'rm -f "$LOCKF"' EXIT

MYSTART="$(powershell -NoProfile -Command "(Get-Date).AddSeconds(-5).ToString('yyyy-MM-dd HH:mm:ss')" | tr -d '\r')"
kill_mine(){ powershell -NoProfile -Command "
    Get-CimInstance Win32_Process -Filter \"Name='futari_combined.exe'\" |
      Where-Object { \$_.CreationDate -ge [datetime]'$MYSTART' } |
      ForEach-Object { Stop-Process -Id \$_.ProcessId -Force -ErrorAction SilentlyContinue }" >/dev/null 2>&1; }
FOREIGN="$(powershell -NoProfile -Command "
  @(Get-CimInstance Win32_Process -Filter \"Name='futari_combined.exe'\" |
     Where-Object { \$_.CreationDate -lt [datetime]'$MYSTART' }).Count" 2>/dev/null | tr -d '\r ')"
if [ "${FOREIGN:-0}" != "0" ]; then echo "!! $FOREIGN futari_combined process(es) predate this script -- REFUSING."; exit 1; fi
XEN="$(powershell -NoProfile -Command "@(Get-Process | Where-Object { \$_.ProcessName -like 'xenia*' -or \$_.ProcessName -like 'XeniaManager*' }).Count" 2>/dev/null | tr -d '\r ')"
[ "${XEN:-0}" != "0" ] && { echo "!! $XEN xenia process(es) live -- REFUSING (never concurrent)."; exit 1; }
kill_mine; sleep 2

echo 0 > "$FIFO"
rm -rf "$RT_SAVE"; cp -r "$CARDSAVE" "$RT_SAVE"
"$BIN" 8208A2B8 0 shell/default.xex 2>"$LOG" </dev/null >/dev/null & PID=$!
T0=$(date +%s)
echo "[r23w75rp] pid=$PID log=$LOG"

source scripts/futari_nav.sh
alive(){ kill -0 "$PID" 2>/dev/null; }
SHOTPS1="C:\\Users\\shant\\Desktop\\projects\\futari_decomp\\bank\\r23\\w7fix\\shot.ps1"
shot(){ powershell -NoProfile -File "$SHOTPS1" -Out "$(cygpath -w "$BANK/eyes/${TAG}_$1.png")" 2>&1; }
phase(){ local t=$(( $(date +%s) - T0 )); echo "t+${t}s $1"; }

nav_boot_to_topmenu             || { echo "FAIL boot"; kill "$PID" 2>/dev/null; exit 1; }
phase "boot -> top menu"
nav_card_decide arcade 0        || { echo "FAIL card decide"; kill "$PID" 2>/dev/null; exit 1; }
phase "card decide arcade"
nav_arcade_land_to_hub          || { echo "FAIL hub"; kill "$PID" 2>/dev/null; exit 1; }
phase "hub -> NORMAL PLAY submenu"
nav_selects_to_stage            || { echo "FAIL selects->stage"; kill "$PID" 2>/dev/null; exit 1; }
phase "entered stage"

nav_say "idling in stage until game over (NORMAL PLAY route; death timing varies 30-60s per nav script's own comment)"
sleep 62
phase "62s dwell -- expect death by now"
shot "prestage_deathcheck"

echo "[r23w75rp] pressing A ONCE at the (unmarked) replay-save prompt -- SINGLE bounded probe, not a blind mash"
nav_base
nav_press 1000 0.25 5.0   # A (はい / yes -- accept the replay save), then a generous 5s settle
phase "post-A press (t+5s settle)"
shot "post_a_press_1"
sleep 8
phase "post-A +8s"
shot "post_a_press_2"

echo "=== PROBE LOG TAIL (last 40 lines) ==="
tail -n 40 "$LOG"
echo "=== gemsg / decide / msg markers since stage entry ==="
grep -a 'gemsg\|\[decide\]\|msg=1[0-9]\|save\|replay' "$LOG" | tail -30

kill "$PID" 2>/dev/null; sleep 1
kill_mine
echo "[r23w75rp] save dir contents:"
find "$RT_SAVE" -newer "$CARDSAVE" -type f 2>/dev/null | head -20
echo "[r23w75rp] done, alive=$(alive && echo yes || echo no)"
