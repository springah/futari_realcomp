#!/bin/bash
# soak_deck.sh <minutes> -- attract-loop soak ON THE DECK (runs on the Deck over ssh; invisible in Gaming Mode, which is
# fine: RSS, frame counter and error counts are the witnesses). Launches the extracted AppImage as a user service.
set -u
MIN="${1:?minutes}"; APPRUN="${APPRUN:-$HOME/squashfs-root/AppRun}"; LOGS="$HOME/.local/share/futari-realcomp/logs"
pkill -9 -x futari_combined 2>/dev/null; systemctl --user stop futari-soak 2>/dev/null; sleep 1
if pgrep -x gamescope-wl >/dev/null; then ENV=(--setenv=XDG_RUNTIME_DIR=/run/user/1000 --setenv=WAYLAND_DISPLAY=gamescope-0 --setenv=SDL_VIDEODRIVER=wayland)
else ENV=(--setenv=XDG_RUNTIME_DIR=/run/user/1000 --setenv=DISPLAY=:0 --setenv=WAYLAND_DISPLAY=wayland-0); fi
PREV=$(ls -t "$LOGS"/*.log 2>/dev/null | head -1)
systemd-run --user --unit=futari-soak --collect "${ENV[@]}" --working-directory="$HOME" "$APPRUN" >/dev/null 2>&1
sleep 10; L=$(ls -t "$LOGS"/*.log | head -1); P=$(pgrep -x futari_combined | head -1)
OUT="$HOME/futari_nav/soak_$(date +%Y%m%d_%H%M%S).txt"; mkdir -p "$HOME/futari_nav"
echo "soak $MIN min pid=$P log=$L session=$(pgrep -x gamescope-wl >/dev/null && echo gaming || echo desktop)" | tee "$OUT"
for ((m=1; m<=MIN; m++)); do
  sleep 60; rss=$(ps -o rss= -p "$P" 2>/dev/null | tr -d ' '); [ -n "$rss" ] || { echo "t+${m}m: PROCESS GONE" | tee -a "$OUT"; break; }
  echo "t+${m}m rss=$((rss/1024))MB frames=$(grep -o "submit f[0-9]*" "$L" | tail -1 | tr -dc 0-9) fatal=$(grep -c FATAL "$L") vkerr=$(grep -c 'VK_ERROR\|VUID' "$L") gpu=$(grep '\*' /sys/class/drm/card0/device/pp_dpm_sclk | tr -d ' ') main=$(ps -L -p $P -o tid=,pcpu= | awk -v p=$P '$1==p{print $2}')%" | tee -a "$OUT"
done
systemctl --user stop futari-soak 2>/dev/null; pkill -9 -x futari_combined 2>/dev/null
first=$(sed -n 2p "$OUT" | grep -o "rss=[0-9]*" | tr -dc 0-9); last=$(grep "rss=" "$OUT" | tail -1 | grep -o "rss=[0-9]*" | tr -dc 0-9)
echo "RSS first->last: ${first}MB -> ${last}MB" | tee -a "$OUT"
