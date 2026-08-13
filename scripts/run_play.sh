#!/bin/bash
# ============================================================================
# Futari — PLAY IT. Native SDK-free static recompilation, human-playable build.
#
# Boots the shell -> title -> auto-navigates the menus -> performs the REAL
# player-join (RT_PJOIN=2) so you drop into a genuine INTERACTIVE run (no REPLAY
# watermark), then hands control to YOUR KEYBOARD via the RT_PAD_HOST bridge.
#
# The renderer presents OFFSCREEN to /tmp/rvk_last.png; this pops a feh window
# that auto-reloads that frame ~7x/sec. Keep the feh window FOCUSED so the
# keyboard bridge (X11 XQueryKeymap on this display) sees your keys.
#
#   KEY MAP (also printed by the engine at startup as "[padhost] ACTIVE ..."):
#     Arrow keys .... move (D-pad + left stick)
#     Z ............. A  (SHOT)
#     X ............. B  (BOMB)
#     C ............. X  (spare)
#     V ............. Y  (spare)
#     Enter ......... START
#     Right Shift ... BACK
#     Esc ........... ignored (won't quit the game)
#   Close the feh window to stop everything.
#
# The shell boot is ~1/3 flaky; this watchdog restarts merged until it reaches
# a live gameplay join, so just wait a few seconds if the first attempt stalls.
# ============================================================================
cd "$HOME/xr-work" || { echo "no ~/xr-work"; exit 1; }
export DISPLAY="${DISPLAY:-:1}"
F=/tmp/rvk_last.png
LOG="${LOG:-/tmp/futari_play.log}"

pkill -9 -x futari_merged 2>/dev/null; sleep 0.3
# dark placeholder so the feh window opens instantly while it boots
python3 -c "from PIL import Image; Image.new('RGB',(1280,720),(0,0,26)).save('$F')" 2>/dev/null

cat <<'KEYS'
==================== FUTARI - controls ====================
  Arrows = move      Z = shot (A)     X = bomb (B)
  C = X   V = Y      Enter = START    RShift = BACK
  (Esc is ignored.)  Close the window to quit.
  Keep the game window FOCUSED for the keyboard to work.
===========================================================
KEYS

start_merged() {
  # leg59 canonical config + RVK_RINGFULL ring fix (default on) + RT_PJOIN=2 real
  # interactive join + RT_PAD_HOST=1 host-keyboard bridge. The synthetic RT_PAD path
  # still self-drives the title/menus unattended; host keys OR-merge and take over at
  # gameplay (host input is NOT muted by the natplay fade-protection silencer).
  RT_GAME_ROOT="$HOME/xr-work/assets" \
  VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.json \
  RT_BOOT_SHELL=1 RT_THREADS=1 RT_DEFERDRIVER=1 RT_ASYNCIO=1 RT_EHCONTAIN=1 RT_AUDIOPUMP=1 \
  RT_VK=1 RVK_GPFIELD=1 RVK_C255=0.00625:0.00390625:-1:0 RVK_RENDER_FROM=1 RVK_NOHALVE=1 RVK_FIXVP=1 RVK_REALALPHA=1 RVK_BLEND=1 \
  RVK_COMPSEG=1 RVK_RESALIAS=1 RVK_RESFRESH=1 \
  RT_PAD=1 RT_PAD_HOST=1 RT_PAD_STARTONCE=1 RT_PAD_NAV=1 \
  RT_SNDQFREE=1 RT_NOPAUSE=1 RT_RESCACHE=1 RT_HEAPLOCK=1 RT_S5=1 RT_TRACERES=1 \
  RT_NATPLAY=1 RT_NATPLAY_ONESHOT=1 RT_STAY5=1 RT_PJOIN=2 \
  RT_SAMPLES=100000 \
  ./futari_merged 8208A2B8 0 shell/default.xex >"$LOG" 2>&1 &
  echo $!
}

# watchdog: (re)start merged until it reaches the interactive join. Boot is ~1/3
# flaky; give each attempt ~40s.
(
  for attempt in 1 2 3 4 5 6; do
    pkill -9 -x futari_merged 2>/dev/null; sleep 0.3
    MPID=$(start_merged)
    ok=0
    for i in $(seq 1 80); do
      sleep 0.5
      kill -0 "$MPID" 2>/dev/null || break
      grep -aq "REAL JOIN side0 OK" "$LOG" 2>/dev/null && { ok=1; break; }
    done
    if [ "$ok" = 1 ]; then
      echo "[run_play] interactive join reached (attempt $attempt) - take the keyboard!" >&2
      wait "$MPID"; break
    fi
    echo "[run_play] attempt $attempt stalled before join - retrying..." >&2
    kill "$MPID" 2>/dev/null
  done
) &
WATCH=$!

feh --title "Futari - PLAY (arrows=move Z=shot X=bomb Enter=start - close to quit)" \
    --reload 0.15 --zoom fill -g 1280x720 "$F" 2>/dev/null

kill "$WATCH" 2>/dev/null; pkill -9 -x futari_merged 2>/dev/null
