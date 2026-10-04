#!/bin/bash
# fdpace_check_mac.sh [BIN] -- FrameDelay pacing check (beta 3 todo item 5). The card's FrameDelay is applied when the
# SAVE is loaded (START at the title -> the save dialog), not at the title, so each arm boots, presses START + A, and then
# idles 60 s in the top menu on a 1V card and on a 3V card (_local/saves/save_fd3, byte +0x16E7 = 3). Verdict from the
# renderer's frame counter at exit: paced 3V ~55-60 presents/s, i.e. within 0.8-1.3x the 1V arm. Before RT_FDPACE
# (10-05) the 3V arm ran ~210/s (NOTE_fnf_shell_defects.md 2026-10-05) = ~3.6x the 1V arm.
#   bash scripts/fdpace_check_mac.sh build/futari_combined
set -u
cd "$(dirname "$0")/.."
BIN="${1:-build/futari_combined}"
[ -d _local/saves/save_fd3 ] || { echo "no _local/saves/save_fd3 (the 3V card)"; exit 2; }
arm(){ local tag="$1" save="$2"
  pkill -f "build/futari_merged|build/futari_combined|Contents/MacOS/futari_merged" 2>/dev/null; sleep 1
  RT_SAVE="$save" NVKPNG=0 RUN_SECS=100 bash scripts/nav_mac.sh "fd_$tag" "$BIN" -- 10 'w:SYS_BGM cue0 (mushifuta_Menu02)' 's:3' 1000 'w:SYS_SE cue1 (SE_OK01)' 's:60' 'log:framedelay' > /dev/null 2>&1
  local L=_local/nav_mac/fd_$tag/guest.log
  F[$tag]=$(grep -o "submit f[0-9]*" "$L" | tail -1 | tr -dc 0-9)
  printf "%-3s %-24s frames_at_exit=%-6s [fdpace] lines=%-4s %s\n" "$tag" "$save" "${F[$tag]}" "$(grep -c '\[fdpace\]' "$L")" "$(grep 'framedelay=' "$L" | tail -1 | cut -c1-70)"
}
declare -A F
arm 1V _local/saves/save_mac
arm 3V _local/saves/save_fd3
r=$(python3 -c "print(round(${F[3V]:-0}/max(${F[1V]:-1},1),2))")
python3 -c "import sys; r=$r; print('ratio 3V/1V =', r, '->', 'PASS (paced)' if 0.8<=r<=1.3 else 'FAIL (3V un-paced or arm broken)'); sys.exit(0 if 0.8<=r<=1.3 else 1)"
