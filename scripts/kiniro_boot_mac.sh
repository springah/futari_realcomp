#!/bin/bash
# kiniro_boot_mac.sh <tag> <host> [hold_secs]   -- Black Label step 3 FIRST-BOOT / HARVEST drive (docs/PLAN_kiniro_bringup.md "Step 3").
#
# Takes the drive lock, points the engine at a PRIVATE game root that holds the extracted Black Label DLC data
# (KIN_ROOT, default _local/blroot: symlinks into assets/ plus media/Rom/{cg_black.bin,cg_blackhi.bin,dropprm.bl};
# the data NEVER goes into assets/, which the bundle copies), then drives scripts/nav_mac.sh on <host> (a 3-slot
# futari_combined): title -> START (top menu) -> DOWN, DOWN (cursor on the Black Label row) -> shot -> A (arcade_front
# panel) -> A (decide Black Label ARCADE = modeIdx 4) -> wait for the module swap to kiniro_normal -> hold, shooting
# every 15 s. Then the HARVEST lines are pulled out of the guest log into $B/harvest.txt:
#   [indirect] UNMAPPED guest target=0x88...   -> functions XenonRecomp's analysis missed: add to config/futari_kiniro.toml
#   [kdrop]                                     -> a live hook called a reco_normal hook symbol with no kiniro twin (exit 97
#                                                  unless RT_KDROP_CONT=1)
#   [kgate]                                     -> a reco-literal lever refused on module 4 (merged_common.h rt_kgate)
#   FATAL / IS THE WRONG MODULE / [modswap] / [modeidx] / [xenum] DLC gate / [loadgame] / [startwire]
#   bash scripts/kiniro_boot_mac.sh k3_boot1 build/kin/futari_combined 90
#   RT_KDROP_CONT=1 bash scripts/kiniro_boot_mac.sh k3_cont1 build/kin/futari_combined 120
#   KIN_STEPS="10 w:\[p0build\]\ menu_game_title s:3 shot 1000 s:4 shot" bash scripts/kiniro_boot_mac.sh k3_play1 build/kin/futari_combined 120
# KIN_STEPS = extra nav_mac.sh steps run AFTER the module swap (whitespace-split; escape spaces inside a step with
# a backslash), i.e. the inputs that take the Black Label module past its title: START -> hub -> A ... The hold
# with its shots and harvest greps follows them.
# Bank: _local/nav_mac/<tag>/{shot_N.png, guest.log, steps.txt, harvest.txt}. Private save copy per tag.
set -u
cd "$(dirname "$0")/.."
TAG="${1:?tag}"; BIN="${2:?host binary}"; HOLD="${3:-90}"
KIN_ROOT="${KIN_ROOT:-$PWD/_local/blroot}"
for f in media/Rom/cg_black.bin media/Rom/cg_blackhi.bin media/Rom/dropprm.bl media/Module/kiniro_normal.xex default.xex; do
  [ -r "$KIN_ROOT/$f" ] || { echo "KIN_ROOT=$KIN_ROOT lacks $f (extract the DLC into a private root first)"; exit 2; }
done
LOCK=/tmp/futari_drive.lock
until mkdir "$LOCK" 2>/dev/null; do sleep 20; done
trap 'rmdir "$LOCK" 2>/dev/null' EXIT
while pgrep -x futari_combined >/dev/null || pgrep -x futari_merged >/dev/null; do sleep 30; done
SAVE="_local/saves/save_kin_$TAG"; rm -rf "$SAVE"; cp -R _local/saves/save_mac "$SAVE"
# hold = N x (15 s + shot); the module's cold boot is inside the W: ceiling (240 s)
HOLDSTEPS=(); n=$(( HOLD / 15 )); [ "$n" -lt 1 ] && n=1
for ((i=0;i<n;i++)); do HOLDSTEPS+=('s:15' shot 'log:\[indirect\] UNMAPPED\|\[kdrop\]\|\[kgate\]\|FATAL\|IS THE WRONG MODULE\|\[startwire\]'); done
# KIN_STEPS: whitespace-split, "\ " = a literal space inside one step
EXTRA=(); if [ -n "${KIN_STEPS:-}" ]; then
  _s="${KIN_STEPS//\\ /$'\x01'}"; for w in $_s; do EXTRA+=("${w//$'\x01'/ }"); done; fi
# Control arm (KIN_MODEIDX=0): the same drive on Ver 1.5 ARCADE = title row 0 (no DOWNs), decide = modeIdx 0, and no
# module swap to wait for (reco_normal is the boot module). Same KIN_STEPS, same harvest greps -> an A/B pair.
KIN_MODEIDX="${KIN_MODEIDX:-4}"
ROWSTEPS=(2 's:1.5' 2 's:2.5'); SWAPSTEPS=('W:\[modswap\] #[0-9]* DONE' 's:5')
if [ "$KIN_MODEIDX" = 0 ]; then ROWSTEPS=('s:2'); SWAPSTEPS=('s:8'); fi
# odd modeIdx = the XBOX 360 MODE card: LEFT on the arcade_front panel first (the panel honours no decide for 3 s)
SUBSTEPS=(); case "$KIN_MODEIDX" in 1|3|5|7) SUBSTEPS=(4 's:3.6');; esac
# RSS sampler (G5-style soak figure for the module): one line per 30 s, "t_s,rss_mb", from the first engine process seen
B="_local/nav_mac/$TAG"; mkdir -p "$B"; : > "$B/rss.csv"
( T0=$(date +%s); for ((k=0;k<400;k++)); do P=$(pgrep -x "$(basename "$BIN")" | head -1); if [ -n "$P" ]; then R=$(ps -o rss= -p "$P" 2>/dev/null | tr -d ' '); [ -n "$R" ] && echo "$(( $(date +%s)-T0 )),$((R/1024))" >> "$B/rss.csv"; fi; sleep 30; done ) &
SAMPLER=$!
RT_GAME_ROOT="$KIN_ROOT" RT_SAVE="$SAVE" RUN_SECS="${RUN_SECS:-$(( 260 + HOLD ))}" bash scripts/nav_mac.sh "$TAG" "$BIN" -- \
  10 'w:SYS_BGM cue0 (mushifuta_Menu02)' 's:4' "${ROWSTEPS[@]}" shot \
  1000 'w:SYS_SE cue1 (SE_OK01)' 's:3' "${SUBSTEPS[@]}" shot \
  1000 "w:\\[modeidx\\] sub_821C3F38 modeIdx=$KIN_MODEIDX" 's:2' \
  "${SWAPSTEPS[@]}" shot 'log:\[modswap\]\|\[loadgame\]\|\[xenum\] DLC gate' \
  "${EXTRA[@]}" \
  "${HOLDSTEPS[@]}"
kill "$SAMPLER" 2>/dev/null
{
  echo "== kiniro step-3 harvest: $TAG  host=$BIN  root=$KIN_ROOT  hold=${HOLD}s  $(date '+%F %T') =="
  echo "-- rss (t_s,rss_mb; first / at 2 min / at 10 min / last) --"
  head -1 "$B/rss.csv"; awk -F, '$1>=115&&$1<=125' "$B/rss.csv" | head -1; awk -F, '$1>=595&&$1<=605' "$B/rss.csv" | head -1; tail -1 "$B/rss.csv"
  echo "-- summary --"
  for p in '\[modreg\]' '\[xenum\] DLC gate' '\[modeidx\]' '\[loadgame\]' '\[modswap\] #' 'IS THE WRONG MODULE' '\[kgate\]' '\[kdrop\]' '\[indirect\] UNMAPPED' 'FATAL' 'VK_ERROR\|VUID' '\[startwire\]'; do
    printf '%6d  %s\n' "$(grep -c "$p" "$B/guest.log")" "$p"
  done
  echo "-- distinct UNMAPPED targets (count target first-lr) --"
  grep -o 'UNMAPPED guest target=0x[0-9A-F]* (lr=0x[0-9A-F]*)' "$B/guest.log" | sed 's/UNMAPPED guest target=//' | awk '{c[$1]++; if(!($1 in l)) l[$1]=$2} END{for(k in c) printf "%6d  %s %s\n", c[k], k, l[k]}' | sort -k2
  echo "-- [kdrop] / [kgate] / WRONG MODULE / FATAL lines --"
  grep -E '\[kdrop\]|\[kgate\]|IS THE WRONG MODULE|FATAL' "$B/guest.log" | cut -c1-200 | sort | uniq -c | sort -rn | head -40
  echo "-- module lines --"
  grep -E '\[modreg\]|\[modswap\]|\[modeidx\]|\[loadgame\]|\[xenum\] DLC gate|\[startwire\]' "$B/guest.log" | cut -c1-220 | head -40
  echo "-- [descprobe] (RT_DESCPROBE=1: the six descriptor fields, edge-logged by the pump hook) --"
  grep '\[descprobe\]' "$B/guest.log" | cut -c1-260 | head -60
  echo "-- [navmod] (RT_NAVMOD=1: the nav observer set, edge-logged by the pump hook) --"
  grep '\[navmod\]' "$B/guest.log" | cut -c1-200 | head -80
  echo "-- BGM / hub markers --"
  grep -E '\[cue\] BGM|\[p0build\] menu_game_title|\[mcur\]|\[decide\]' "$B/guest.log" | grep -v native | cut -c1-160 | head -30
  echo "-- engine exit --"; tail -5 "$B/run_out.txt" 2>/dev/null
} > "$B/harvest.txt"
cat "$B/harvest.txt"
