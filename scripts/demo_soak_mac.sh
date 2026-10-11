#!/bin/bash
# demo_soak_mac.sh <minutes> [BIN] -- ARCADE-module demonstration soak (the gameplay attract, not the shell title).
# Boots the shell, drives TITLE -> top menu -> card panel -> ARCADE decide (NAV_MAP's route, marker-asserted per
# press), then leaves the module title alone: it rolls into DEMONSTRATION on its own and cycles demo -> title -> demo.
# Samples RSS every 60 s like soak_mac.sh and counts demo cycles by the module's outer state field: `[navreal] d76 0->3`
# (go=1) = the ROM attract gameplay starts, `d76 4->0` = back to the title (~80 s per cycle). The arcade module is the
# CV1000 ROM under the emulator layer: its attract has NO XACT BGM cue (the first cut keyed on m02_stg and counted 0
# through 15 real cycles -- 10-05). RT_NVKPNG frame dumps give a visual witness: shot_<minute>.png in the bank.
# Healthy: RSS flat, zero FATAL/VK_ERROR, demo count rising, process alive at the end.
#   bash scripts/demo_soak_mac.sh 20 "Futari Realcomp.app/Contents/MacOS/futari_merged"
set -u
cd "$(dirname "$0")/.."
MIN="${1:?minutes}"; BIN="${2:-build/futari_combined}"
pkill -f "build/futari_merged|build/futari_combined|Contents/MacOS/futari_merged" 2>/dev/null; sleep 1
FIFO=/tmp/futari_pad_demosoak; echo 0 > "$FIFO"
BANK=_local/nav_mac/demosoak_$(date +%Y%m%d_%H%M%S); mkdir -p "$BANK/png"
export RT_PAD_HOST=1 RT_PAD_HOST_FIFO="$FIFO" RT_NVKPNG="${NVKPNG:-300}" RVK_DUMPDIR="$PWD/$BANK/png"
PREV=$(ls -t _local/logs/mac_*.log 2>/dev/null | head -1)
BIN="$BIN" RUN_SECS=$((MIN*60+150)) RT_SAVE="${RT_SAVE:-_local/saves/save_mac}" bash scripts/run_mac.sh >/dev/null 2>&1 &
L=""; for ((i=0;i<60;i++)); do l=$(ls -t _local/logs/mac_*.log 2>/dev/null | head -1); [ -n "$l" ] && [ "$l" != "$PREV" ] && { L="$l"; break; }; sleep 0.5; done
[ -n "$L" ] || { echo "no new log"; exit 1; }
PID=$(pgrep -f "$BIN" | head -1); [ -n "$PID" ] || { echo "engine not running"; exit 1; }
OUT=_local/logs/demosoak_$(date +%Y%m%d_%H%M%S).txt; echo "demo soak $MIN min bin=$BIN pid=$PID log=$L" | tee "$OUT"
T0=$(date +%s); say(){ echo "t+$(( $(date +%s)-T0 ))s $*" | tee -a "$OUT"; }
press(){ echo "$1" > "$FIFO"; sleep 0.2; echo 0 > "$FIFO"; }
MARK=0; mark(){ MARK=$(wc -l < "$L" | tr -d ' '); }
waitnew(){ local pat="$1" i; for ((i=0;i<20;i++)); do tail -n +"$((MARK+1))" "$L" | grep -q "$pat" && return 0; sleep 0.5; done; return 1; }
step(){ local pad="$1" pat="$2" settle="$3" try; for try in 1 2; do mark; press "$pad"; waitnew "$pat" && { say "pad $pad -> $pat"; sleep "$settle"; return 0; }; done; say "FAIL: no $pat after pad $pad"; pkill -x "$(basename "$BIN")"; exit 1; }
for ((i=0;i<60;i++)); do grep -q "name='motion/title.lzx'" "$L" && break; sleep 1; done; say "shell title loaded"; sleep 4
step 10   'SYS_BGM cue0 (mushifuta_Menu02)' 4
step 1000 'SYS_SE cue1 (SE_OK01)' 3
step 1000 '\[modeidx\] .*ARCADE' 2
say "ARCADE module decided; hands off -- the module title rolls into DEMONSTRATION by itself"
demo(){ grep -c 'navreal\] d76 0->3' "$L"; }
back(){ grep -c 'navreal\] d76 4->0' "$L"; }
for ((m=1; m<=MIN; m++)); do
  sleep 60
  rss=$(ps -o rss= -p "$PID" 2>/dev/null | tr -d ' '); [ -n "$rss" ] || { say "t+${m}m: PROCESS GONE"; break; }
  f=$(grep -o "submit f[0-9]*" "$L" | tail -1 | tr -dc 0-9)
  echo "t+${m}m rss=$((rss/1024))MB frames=$f demos=$(demo) back=$(back) fatal=$(grep -c 'FATAL' "$L") vkerr=$(grep -c 'VK_ERROR\|VUID' "$L")" | tee -a "$OUT"
  cp "$BANK/png/nvk_last.png" "$BANK/shot_${m}.png" 2>/dev/null
  [ "$m" = 3 ] && [ "$(demo)" = 0 ] && say "WARNING: no demonstration (d76 0->3) after 3 min (still on the module title?)"
done
first=$(grep -m1 -o "rss=[0-9]*" "$OUT" | tr -dc 0-9); last=$(tail -1 "$OUT" | grep -o "rss=[0-9]*" | tr -dc 0-9)
echo "RSS first->last: ${first}MB -> ${last}MB  (growth $(( ${last:-0} - ${first:-0} ))MB)  demo cycles=$(demo) (back to title $(back))  shots=$BANK  fatal=$(grep -c FATAL "$L") vkerr=$(grep -c 'VK_ERROR\|VUID' "$L")" | tee -a "$OUT"
pkill -x "$(basename "$BIN")" 2>/dev/null
