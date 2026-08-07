#!/bin/bash
# Futari — native, SDK-free static recompilation. Launches the merged binary and shows its
# render LIVE. Note: the renderer currently presents OFFSCREEN to /tmp/rvk_last.png (on-screen
# present via the plume RHI is still planned), so this pops a feh window that auto-reloads that
# frame ~4x/sec. Boots the shell -> the animated title screen (虫姫さまふたり). Close the window
# to stop. (The TOP MENU / DLC / in-game menu screens are in "Futari — Screens".)
cd "$HOME/xr-work" || { echo "no ~/xr-work"; exit 1; }
export DISPLAY="${DISPLAY:-:1}"
F=/tmp/rvk_last.png
LOG=/tmp/futari_run.log

pkill -9 -x futari_merged 2>/dev/null; sleep 0.3
# dark placeholder so the window opens instantly while it boots
python3 -c "from PIL import Image; Image.new('RGB',(1280,720),(0,0,26)).save('$F')" 2>/dev/null

start_merged() {
  RT_GAME_ROOT="$HOME/xr-work/assets" \
  VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.json \
  RT_BOOT_SHELL=1 RT_THREADS=1 RT_DEFERDRIVER=1 RT_ASYNCIO=1 RT_EHCONTAIN=1 RT_AUDIOPUMP=1 RT_GAMEPUMP=1 \
  RT_VK=1 RVK_RENDER_FROM=1 RVK_NOHALVE=1 RVK_FIXVP=1 RVK_REALALPHA=1 RVK_BLEND=1 \
  ./futari_merged 8208A2B8 0 shell/default.xex >"$LOG" 2>&1 &
  echo $!
}

nonclear() { python3 -c "from PIL import Image;from collections import Counter;im=Image.open('$F').convert('RGB');d=list(im.getdata());print(len(d)-Counter(d).most_common(1)[0][1])" 2>/dev/null || echo 0; }

# watchdog: (re)start merged until it boots to a non-blank title (the shell boot is ~1/3 flaky)
(
  for attempt in 1 2 3 4 5; do
    pkill -9 -x futari_merged 2>/dev/null; sleep 0.3
    MPID=$(start_merged)
    booted=0
    for i in $(seq 1 26); do
      sleep 0.5
      kill -0 "$MPID" 2>/dev/null || break
      [ "$(nonclear)" -gt 150000 ] && { booted=1; break; }
    done
    if [ "$booted" = 1 ]; then wait "$MPID"; break; fi
    kill "$MPID" 2>/dev/null
  done
) &
WATCH=$!

feh --title "Futari — native SDK-free recompilation (live offscreen render — close to stop)" \
    --reload 0.25 --zoom fill -g 1280x720 "$F" 2>/dev/null

kill "$WATCH" 2>/dev/null; pkill -9 -x futari_merged 2>/dev/null
