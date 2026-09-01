#!/bin/bash
# drive_w74_menutour.sh <tag>
#
# r23-w74 DRIVER -- THE MENU-LIST INSTALL-WATCH leg + the mapped-table source tap's positive
# control + measurement leg, COMBINED into one drive (DISK: frugal law -- one leg serves both
# instruments; RT_INSTALLWATCH and RT_TABREAD are independent, cheap, env-gated taps that can be
# armed simultaneously). Pre-registration: bank/r23/w74/PREREG_w74.txt.
#
# DERIVED FROM bank/r23/w73/drive_w73_360census.sh (env block/lock/kill-verify/single-instance
# discipline) + docs/NAV_MAP.md (HUB item list + return-to-top confirm) + scripts/futari_nav.sh.
set -u
TAG="${1:?usage: drive_w74_menutour.sh <tag>}"

ROOT_DIR="C:/Users/shant/Desktop/projects/futari_realcomp"; cd "$ROOT_DIR" || exit 1
export MSYS_NO_PATHCONV=1
BANK="C:/Users/shant/Desktop/projects/futari_decomp/bank/r23/w74"; mkdir -p "$BANK/eyes"; mkdir -p /c/tmp

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
export RT_PAD=1 RT_PAD_FIFO=1 RT_PAD_FIFO_PATH="/tmp/futari_pad_r23w74" RT_NAV_SEQ="9999999:START" RT_NOXINPUT=1
export FIFO="/c/tmp/futari_pad_r23w74"
export RT_SAVE="save_r23w74_${TAG}"
# ---- ★★★★★ THE MISSION INSTRUMENTS ----
export RT_TRIOTAP=1                 # RE-ARM: drive-alive liveness control (LAWS: liveness = a counter advancing)
export RT_INSTALLWATCH=1            # NEW this window -- menu-list vtable install-watch (shell)
export RT_TABREAD=1                 # NEW this window -- mapped-table source tap (out_reco/reco_normal)

echo "[r23w74] tag=$TAG"
echo "[r23w74] exe md5 $(md5sum "$BIN" | cut -c1-12)"
echo "[r23w74] normal dll md5 $(md5sum build/futari_game_normal.dll | cut -c1-12)"
echo "[r23w74] abn dll md5    $(md5sum build/futari_game_abn.dll | cut -c1-12)"

# ---- SINGLE-INSTANCE LOCK ----------------------------------------------------------------------
LOCKF="/c/tmp/.w74_drive.lock"
if [ -e "$LOCKF" ]; then
  OTHER="$(cat "$LOCKF" 2>/dev/null)"
  if kill -0 "$OTHER" 2>/dev/null; then echo "!! another w74 drive is LIVE (pid $OTHER) -- REFUSING."; exit 1; fi
  echo "[r23w74] stale lock from dead pid $OTHER -- reclaiming"
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
echo "[r23w74] pid=$PID log=$LOG"

source scripts/futari_nav.sh
alive(){ kill -0 "$PID" 2>/dev/null; }
FAILS=0
die(){ echo "[r23w74] FAIL: $*"; FAILS=$((FAILS+1)); }
SHOTPS1="C:\\Users\\shant\\Desktop\\projects\\futari_decomp\\bank\\r23\\w7fix\\shot.ps1"
shot(){ powershell -NoProfile -File "$SHOTPS1" -Out "$(cygpath -w "$BANK/eyes/${TAG}_$1.png")" 2>&1; }
instw_now(){ grep -ac '\[instwatch\] #' "$LOG" 2>/dev/null || echo 0; }
tabr_now(){ grep -ac '\[tabread\] #' "$LOG" 2>/dev/null || echo 0; }
ctrlok_now(){ grep -ac '\[triotap\].*callee=sub_8808FB90.*lr=0x88093428' "$LOG" 2>/dev/null || echo 0; }
phase(){ local t=$(( $(date +%s) - T0 ))
  printf 't+%-5ss %-30s triotap-ctrl=%-6s instwatch=%-6s tabread=%-6s\n' "$t" "$1" "$(ctrlok_now)" "$(instw_now)" "$(tabr_now)" | tee -a "$BANK/${TAG}_phases.txt"
}

# ============================== THE LEG =======================================================
nav_boot_to_topmenu             || die "boot -> top menu"
phase "boot -> top menu"

nav_card_decide arcade 0        || die "card decide arcade"
phase "card decide arcade"

nav_arcade_land_to_hub          || die "arcade hub (lands on NORMAL PLAY submenu)"
phase "arcade attract -> hub -> NORMAL PLAY submenu"
# nav_arcade_land_to_hub already pressed A,A into 1P SIDE START -- back out to the hub root
# with B twice (submenu -> hub) before walking to other hub rows.
nav_press 2000 0.25 2.0; nav_press 2000 0.25 2.0
phase "backed out to hub root"

# ---- HUB row walk: SCORE ATTACK(0)/NORMAL PLAY(1)/TRAINING(2)/REPLAY DATA(3)/OPTION(4)/CLOSE(5)/RETURN(6)
nav_base
nav_press 2 0.15 1.0   # 0->1 NORMAL PLAY (already here typically, harmless if no-op)
nav_press 2 0.15 1.0   # 1->2 TRAINING
nav_press 2 0.15 1.0   # 2->3 REPLAY DATA
nav_press 1000 0.2 2.5 # A -> open REPLAY DATA panel (ReplayList / vt 0x82050610 family)
phase "REPLAY DATA panel opened"
shot "replaydata"
nav_press 2000 0.25 2.0   # B -> back to hub
phase "REPLAY DATA closed"

nav_base
nav_press 2 0.15 1.0   # 3->4 OPTION
nav_press 1000 0.2 2.5 # A -> open OPTION panel (OptionsPanelBase / vt 0x82050268,0x82050678 family)
phase "OPTION panel opened"
shot "options"
nav_press 2000 0.25 2.0   # B -> back to hub
phase "OPTION closed"

# ---- message-box dialog: the return-to-top confirm (shares the "dialog" vtable siblings) ----
nav_base
nav_press 2000 0.25 2.0   # B on hub root -> return-to-top confirm dialog
phase "return-to-top confirm dialog open"
shot "confirmdialog"
nav_press 2000 0.25 2.0   # B -> CANCEL the confirm, stay in hub (do not actually leave)
phase "confirm dialog cancelled, still in hub"

# ---- into arcade gameplay: 1P SIDE START -> Original -> char -> shot -> stage (RT_TABREAD leg) ----
nav_base
nav_press 1 0.15 1.0   # up back toward NORMAL PLAY row if walk drifted
nav_press 1000 0.2 2.5 # A -> NORMAL PLAY submenu
nav_press 1000 0.2 3.0 # A -> 1P SIDE START -> MODE SELECT
nav_selects_to_stage   || die "selects -> stage"
phase "entered stage (arcade route, RT_TABREAD live)"
shot "instage"
sleep 45
phase "45s into stage (dwell for tabread + install-watch corroboration)"

echo "[r23w74] stopping"
kill "$PID" 2>/dev/null; sleep 1
kill_mine

echo "=== VERDICT ==="
echo "triotap ctrl(exact)=$(ctrlok_now) instwatch=$(instw_now) tabread=$(tabr_now) fails=$FAILS died=$(alive && echo no || echo no)"
echo "[instwatch] lines:"; grep -a '\[instwatch\]' "$LOG" | head -60
echo "[tabread] lines:"; grep -a '\[tabread\]' "$LOG" | head -60
