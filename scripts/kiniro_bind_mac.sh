#!/bin/bash
# kiniro_bind_mac.sh <tag> <host>   -- Black Label step 4a BIND PROOF drive (docs/PLAN_kiniro_bringup.md "Step 4a").
#
# Takes the drive lock, then runs scripts/nav_mac.sh on <host> (a futari_combined with its module dylibs beside it):
# shell title -> START (top menu = the game-select task, movie menu_title_menu, whose rows L1 greys) -> shot_1 ->
# DOWN, DOWN (cursor onto title row 2 = Black Label; a disabled row still takes the cursor) -> shot_2. Nothing is
# decided: the module is never entered. The [modreg] / [modestub] / [xenum] lines are pulled out of the guest log.
#   RT_DLCFORCE=1 bash scripts/kiniro_bind_mac.sh k4a_force build/kin/futari_combined   (DLC gate forced OWNED)
#   bash scripts/kiniro_bind_mac.sh k4a_nodlc build/kin/futari_combined                (no Black Label data in assets/)
# Bank: _local/nav_mac/<tag>/{shot_1.png, shot_2.png, guest.log, binding.txt}. Private save copy per tag.
set -u
cd "$(dirname "$0")/.."
TAG="${1:?tag}"; BIN="${2:?host binary}"
LOCK=/tmp/futari_drive.lock
until mkdir "$LOCK" 2>/dev/null; do sleep 60; done
trap 'rmdir "$LOCK" 2>/dev/null' EXIT
while pgrep -x futari_combined >/dev/null || pgrep -x futari_merged >/dev/null; do sleep 30; done
SAVE="_local/saves/save_kin_$TAG"; rm -rf "$SAVE"; cp -R _local/saves/save_mac "$SAVE"
RT_SAVE="$SAVE" RUN_SECS="${RUN_SECS:-150}" bash scripts/nav_mac.sh "$TAG" "$BIN" -- \
  10 'w:SYS_BGM cue0 (mushifuta_Menu02)' 's:4' shot 2 's:1.5' 2 's:2.5' shot
B="_local/nav_mac/$TAG"
grep -E '\[modreg\]|\[modestub\]|\[xenum\] DLC gate|IS THE WRONG MODULE|\[kdrop\]|FATAL' "$B/guest.log" | cut -c1-220 > "$B/binding.txt"
cat "$B/binding.txt"
