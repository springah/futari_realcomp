#!/bin/bash
# soak_mac.sh <minutes> [BIN] -- attract-loop soak with memory sampling (beta 3 todo item 5).
# Boots the engine to the title and leaves it in attract for <minutes>, sampling RSS every 60 s; prints the growth and
# the FATAL/VK_ERROR counts. A healthy soak: RSS flat after the first few minutes, zero errors, process alive at the end.
#   bash scripts/soak_mac.sh 40 build/futari_combined
set -u
cd "$(dirname "$0")/.."
MIN="${1:?minutes}"; BIN="${2:-build/futari_combined}"
pkill -f "build/futari_merged|build/futari_combined|Contents/MacOS/futari_merged" 2>/dev/null; sleep 1
PREV=$(ls -t _local/logs/mac_*.log 2>/dev/null | head -1)
BIN="$BIN" RUN_SECS=$((MIN*60+90)) RT_SAVE=_local/saves/save_soak bash scripts/run_mac.sh >/dev/null 2>&1 &
sleep 8; L=$(ls -t _local/logs/mac_*.log | head -1)
PID=$(pgrep -f "$BIN" | head -1); [ -n "$PID" ] || { echo "engine not running"; exit 1; }
OUT=_local/logs/soak_$(date +%Y%m%d_%H%M%S).txt; echo "soak $MIN min bin=$BIN pid=$PID log=$L" | tee "$OUT"
for ((m=1; m<=MIN; m++)); do
  sleep 60
  rss=$(ps -o rss= -p "$PID" 2>/dev/null | tr -d ' '); [ -n "$rss" ] || { echo "t+${m}m: PROCESS GONE" | tee -a "$OUT"; break; }
  f=$(grep -o "submit f[0-9]*" "$L" | tail -1 | tr -dc 0-9)
  echo "t+${m}m rss=$((rss/1024))MB frames=$f fatal=$(grep -c 'FATAL' "$L") vkerr=$(grep -c 'VK_ERROR\|VUID' "$L")" | tee -a "$OUT"
done
first=$(sed -n 2p "$OUT" | grep -o "rss=[0-9]*" | tr -dc 0-9); last=$(tail -1 "$OUT" | grep -o "rss=[0-9]*" | tr -dc 0-9)
echo "RSS first->last: ${first}MB -> ${last}MB  (growth $(( ${last:-0} - ${first:-0} ))MB)" | tee -a "$OUT"
pkill -f "$BIN" 2>/dev/null
