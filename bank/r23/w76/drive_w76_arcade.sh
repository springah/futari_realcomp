#!/bin/bash
# drive_w76_arcade.sh <tag>
#
# r23-w76 DRIVER -- THE SCORING LEG for RT_TABREAD2 (0x880E4860's active-voice-table reads,
# clusters F/G/H) + RT_WITNESS3 (TASKQ = sub_881526C0 entry, called from 0x88136D60's two
# id=39/40 branches; GATE = sub_88133A60's throttle decision point). Standard arcade route
# (w75's own shape), with an extended character-select dwell (Menu_PerSlotMachine's own
# per-slot draw is TASKQ's expected fire point) and stage dwell (PoolE1A0_Kind3_NodeCallback's
# own sound-pool tick is GATE's expected fire point; Outer_Fsm's own settings-commit block is
# table F/G/H's expected fire point via 0x880E4860). Pre-registration: bank/r23/w76/PREREG_w76.txt.
#
# DERIVED FROM bank/r23/w75/drive_w75_menutour.sh (env block/lock/kill-verify/single-instance
# discipline, HUB/nav shape) + docs/NAV_MAP.md + scripts/futari_nav.sh.
set -u
TAG="${1:?usage: drive_w76_arcade.sh <tag>}"

ROOT_DIR="C:/Users/shant/Desktop/projects/futari_realcomp"; cd "$ROOT_DIR" || exit 1
export MSYS_NO_PATHCONV=1
BANK="C:/Users/shant/Desktop/projects/futari_decomp/bank/r23/w76"; mkdir -p "$BANK/eyes"; mkdir -p /c/tmp

BIN="${BIN:-./build/futari_combined.exe}"
[ -x "$BIN" ] || { echo "!! missing host exe $BIN"; exit 1; }
[ -f "build/futari_game_normal.dll" ] || { echo "!! missing build/futari_game_normal.dll"; exit 1; }
[ -f "build/futari_game_abn.dll" ]    || { echo "!! missing build/futari_game_abn.dll"; exit 1; }
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
export RT_PAD=1 RT_PAD_FIFO=1 RT_PAD_FIFO_PATH="/tmp/futari_pad_r23w76" RT_NAV_SEQ="9999999:START" RT_NOXINPUT=1
export FIFO="/c/tmp/futari_pad_r23w76"
export RT_SAVE="save_r23w76_${TAG}"
# ---- ★★★★★ THE MISSION INSTRUMENTS ----
export RT_TRIOTAP=1                 # drive-alive liveness control (unchanged, re-armed every leg)
export RT_TABREAD=1                 # w75's clusters A-E, RE-ARMED for cluster E ONLY (control layer)
export RT_TABREAD2=1                # r23-w76 -- clusters F/G/H, 0x880E4860's tables + gating flag
export RT_WITNESS3=1                # r23-w76 -- TASKQ + GATE

echo "[r23w76] tag=$TAG"
echo "[r23w76] exe md5 $(md5sum "$BIN" | cut -c1-12)"
echo "[r23w76] normal dll md5 $(md5sum build/futari_game_normal.dll | cut -c1-12)"
echo "[r23w76] abn dll md5    $(md5sum build/futari_game_abn.dll | cut -c1-12)"

# ---- SINGLE-INSTANCE LOCK ----------------------------------------------------------------------
LOCKF="/c/tmp/.w76_drive.lock"
if [ -e "$LOCKF" ]; then
  OTHER="$(cat "$LOCKF" 2>/dev/null)"
  if kill -0 "$OTHER" 2>/dev/null; then echo "!! another w76 drive is LIVE (pid $OTHER) -- REFUSING."; exit 1; fi
  echo "[r23w76] stale lock from dead pid $OTHER -- reclaiming"
fi
echo $$ > "$LOCKF"
trap 'rm -f "$LOCKF"' EXIT

# ---- ORPHAN KILL-VERIFY (hard gate) -------------------------------------------------------------
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
echo "[r23w76] pid=$PID log=$LOG"

source scripts/futari_nav.sh
alive(){ kill -0 "$PID" 2>/dev/null; }
FAILS=0
die(){ echo "[r23w76] FAIL: $*"; FAILS=$((FAILS+1)); }
SHOTPS1="C:\\Users\\shant\\Desktop\\projects\\futari_decomp\\bank\\r23\\w7fix\\shot.ps1"
shot(){ powershell -NoProfile -File "$SHOTPS1" -Out "$(cygpath -w "$BANK/eyes/${TAG}_$1.png")" 2>&1; }
tab2_now(){ grep -ac '\[tabread2\] #' "$LOG" 2>/dev/null || echo 0; }
tab2_F(){ grep -ac '\[tabread2\].*cluster=F' "$LOG" 2>/dev/null || echo 0; }
tab2_G(){ grep -ac '\[tabread2\].*cluster=G' "$LOG" 2>/dev/null || echo 0; }
tab2_H(){ grep -ac '\[tabread2\].*cluster=H' "$LOG" 2>/dev/null || echo 0; }
ctrlE_now(){ grep -ac '\[tabread\].*cluster=E-ctrl' "$LOG" 2>/dev/null || echo 0; }
taskq_now(){ grep -ac '\[witness3-taskq\]' "$LOG" 2>/dev/null || echo 0; }
gate_now(){ grep -ac '\[witness3-gate\]' "$LOG" 2>/dev/null || echo 0; }
ctrlok_now(){ grep -ac '\[triotap\].*callee=sub_8808FB90.*lr=0x88093428' "$LOG" 2>/dev/null || echo 0; }
phase(){ local t=$(( $(date +%s) - T0 ))
  printf 't+%-5ss %-34s triotap-ctrl=%-6s ctrl(E)=%-5s tab2(F/G/H)=%s/%s/%s taskq=%-5s gate=%-5s\n' \
    "$t" "$1" "$(ctrlok_now)" "$(ctrlE_now)" "$(tab2_F)" "$(tab2_G)" "$(tab2_H)" "$(taskq_now)" "$(gate_now)" \
    | tee -a "$BANK/${TAG}_phases.txt"
}

# ============================== THE LEG =======================================================
nav_boot_to_topmenu             || die "boot -> top menu"
phase "boot -> top menu"

nav_card_decide arcade 0        || die "card decide arcade"
phase "card decide arcade"

nav_arcade_land_to_hub          || die "arcade hub (lands on NORMAL PLAY submenu)"
phase "arcade attract -> hub -> NORMAL PLAY submenu"
nav_press 2000 0.25 2.0; nav_press 2000 0.25 2.0    # back out to hub root (matches w75 shape)
phase "backed out to hub root"

# ---- into arcade gameplay: 1P SIDE START -> Original -> char select (TASKQ expected) -> stage (GATE/table expected)
nav_base
nav_press 1 0.15 1.0    # up back toward NORMAL PLAY row if walk drifted
nav_press 1000 0.2 2.5  # A -> NORMAL PLAY submenu
nav_press 1000 0.2 3.0  # A -> 1P SIDE START -> MODE SELECT
nav_press 1000 0.2 3.0  # A -> Original
phase "mode select -> Original"

# character select: Menu_PerSlotMachine's own per-slot draw runs here every frame the panel is up --
# dwell BEFORE pressing through, so TASKQ has time to fire if this screen is its trigger.
sleep 6
phase "character select dwell (TASKQ expected point)"
shot "charselect"

nav_press 1000 0.2 3.0   # A character
nav_base; nav_press 1000 0.2 4.0   # A shot -> stage streams assets
nav_wait_new 'epochinval\|nvk\] f\|\[emit\]' 15 "stage activity"
phase "entered stage (GATE + table F/G/H expected point)"
shot "instage"
sleep 60
phase "60s into stage (extended dwell for GATE/table corroboration)"

echo "[r23w76] stopping"
kill "$PID" 2>/dev/null; sleep 1
kill_mine

echo "=== VERDICT ==="
echo "triotap ctrl(exact)=$(ctrlok_now) ctrl(E)=$(ctrlE_now) tabread2 F=$(tab2_F) G=$(tab2_G) H=$(tab2_H) taskq=$(taskq_now) gate=$(gate_now) fails=$FAILS"
echo "[tabread2] lines:"; grep -a '\[tabread2\]' "$LOG" | head -80
echo "[witness3-taskq] lines:"; grep -a '\[witness3-taskq\]' "$LOG" | head -40
echo "[witness3-gate] lines (first 40):"; grep -a '\[witness3-gate\]' "$LOG" | head -40
echo "[witness3-gate] total count:"; grep -ac '\[witness3-gate\]' "$LOG"
