#!/bin/bash
# nav_deck.sh <tag> -- <step>...   marker-driven menu navigation ON THE STEAM DECK (runs on the Deck over ssh).
# Port of scripts/nav_mac.sh: boots the extracted AppImage (~/squashfs-root/AppRun) as a transient user service with
# the gamescope/plasma display env and the pad FIFO, waits for the title, then executes the steps:
#   <pad> | w:<regex> | W:<regex> (120 s) | s:<secs> | log:<regex> | hub (TITLE -> HUB)     NAV_ENV="VAR=val ..." = extra engine env
# In Gaming Mode the window is INVISIBLE (no Steam focus; docs/DECK.md) -- the log is the witness, which is all a
# drive needs. Bank: ~/futari_nav/<tag>/{guest.log,steps.txt}.
set -u
TAG="${1:?tag}"; shift; [ "${1:-}" = "--" ] && shift
APPRUN="${APPRUN:-$HOME/squashfs-root/AppRun}"; B="$HOME/futari_nav/$TAG"; rm -rf "$B"; mkdir -p "$B"
FIFO=/tmp/futari_pad_deck; echo 0 > "$FIFO"
LOGS="$HOME/.local/share/futari-realcomp/logs"
pkill -9 -x futari_combined 2>/dev/null; systemctl --user stop futari-nav 2>/dev/null; sleep 1
if pgrep -x gamescope-wl >/dev/null; then ENV=(--setenv=XDG_RUNTIME_DIR=/run/user/1000 --setenv=WAYLAND_DISPLAY=gamescope-0 --setenv=SDL_VIDEODRIVER=wayland)
else P=$(pgrep -u deck -x plasmashell | head -1); ENV=(--setenv=XDG_RUNTIME_DIR=/run/user/1000 --setenv=DISPLAY=:0 --setenv=WAYLAND_DISPLAY=wayland-0)
     X=$(tr "\0" "\n" < /proc/$P/environ | grep "^XAUTHORITY=" | cut -d= -f2); [ -n "$X" ] && ENV+=(--setenv=XAUTHORITY=$X); fi
PREV=$(ls -t "$LOGS"/*.log 2>/dev/null | head -1)
for kv in ${NAV_ENV:-}; do ENV+=(--setenv="$kv"); done   # NAV_ENV="RVK_DRAWCENSUS=2 ..." = extra engine env (kiniro_deck.sh)
systemd-run --user --unit=futari-nav --collect "${ENV[@]}" --setenv=RT_PAD_HOST=1 --setenv=RT_PAD_HOST_FIFO="$FIFO" --working-directory="$HOME" "$APPRUN" >/dev/null 2>&1
T0=$(date +%s); LOGF=""
for ((i=0;i<60;i++)); do L=$(ls -t "$LOGS"/*.log 2>/dev/null | head -1); [ -n "$L" ] && [ "$L" != "$PREV" ] && { LOGF="$L"; break; }; sleep 0.5; done
[ -n "$LOGF" ] || { echo "no new log"; exit 1; }
say(){ echo "[nav] t+$(( $(date +%s)-T0 ))s $*" | tee -a "$B/steps.txt"; }
press(){ echo "$1" > "$FIFO"; sleep 0.2; echo 0 > "$FIFO"; say "pad $1"; }
MARK=0; mark(){ MARK=$(wc -l < "$LOGF" | tr -d ' '); }
waitnew(){ local pat="$1" n="${2:-20}" i; for ((i=0;i<n;i++)); do tail -n +"$((MARK+1))" "$LOGF" | grep -q "$pat" && { say "marker: $pat"; return 0; }; sleep 0.5; done; say "TIMEOUT: $pat"; return 1; }
step(){ local pad="$1" pat="$2" settle="${3:-1}" try; for try in 1 2; do mark; press "$pad"; waitnew "$pat" && { sleep "$settle"; return 0; }; say "retry"; done; return 1; }
for ((i=0;i<90;i++)); do grep -q "name='motion/title.lzx'" "$LOGF" && break; sleep 1; done; say "title loaded"; sleep 4
for st in "$@"; do
  case "$st" in
    hub) step 10 'SYS_BGM cue0 (mushifuta_Menu02)' 4; step 1000 'SYS_SE cue1 (SE_OK01)' 3; step 1000 '\[modeidx\] .*ARCADE' 3; step 1000 '\[p0build\] menu_game_title' 2; say "HUB";;
    w:*) waitnew "${st#w:}";;
    W:*) waitnew "${st#W:}" 240;;
    s:*) sleep "${st#s:}";;
    log:*) say "log lines matching ${st#log:} since last step:"; tail -n +"$((MARK+1))" "$LOGF" | grep "${st#log:}" | head -40 | sed 's/^/      /' | cut -c1-160;;
    *) mark; press "$st"; sleep 0.8;;
  esac
done
sleep 1; systemctl --user stop futari-nav 2>/dev/null; pkill -9 -x futari_combined 2>/dev/null; sleep 1; cp "$LOGF" "$B/guest.log"; say "DONE -> $B"
