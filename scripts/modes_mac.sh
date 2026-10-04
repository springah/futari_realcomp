#!/bin/bash
# modes_mac.sh <tag> [BIN] -- the TWO-MODE drive on the Mac (beta 3): proves the combined host binds both module
# dylibs, that each mode reaches stage 1, and that the A -> B -> A module swap cycle is clean (the Windows D1
# full-loop re-pair, on the Mac). Routes are docs/NAV_MAP.md's, marker-asserted per press through nav_mac.sh.
#
#   bash scripts/modes_mac.sh m1                       (BIN defaults to build/futari_combined)
#   bank: _local/nav_mac/<tag>_{x360,arcade,swap}/ ; verdict printed at the end and written to _local/nav_mac/<tag>_VERDICT.txt
#   LEGS="x360 arcade swap" (default all) picks legs; SCORE_ONLY=1 re-scores existing banks without driving.
#
# CARD PANEL law (NAV_MAP): TOP MENU -A-> card panel, which ALWAYS resets to the ARCADE card; LEFT = the Xbox 360 card;
# a 3.0 s dwell gate before any decide is honoured (3.6 s used); A = decide -> [modeidx] names the mode, and the
# module swap (lazy, on decide) prints [modswap] #N DONE -- #1 is the boot activation, so the first real swap is #2.
# 360 cold boot ~40 s (may land at MODE SELECT directly).
set -u
cd "$(dirname "$0")/.."
TAG="${1:?tag}"; BIN="${2:-build/futari_combined}"
[ -x "$BIN" ] || { echo "no $BIN -- bash build_mac_dll.sh first"; exit 2; }
V="_local/nav_mac/${TAG}_VERDICT.txt"; mkdir -p _local/nav_mac; : > "$V"
note(){ echo "$*" | tee -a "$V"; }
chk(){ # chk <bank> <label> <regex> [min]
  local n; n=$(grep -c "$3" "_local/nav_mac/$1/guest.log" 2>/dev/null); n=${n:-0}
  if [ "$n" -ge "${4:-1}" ]; then note "  PASS $2 ($n x $3)"; else note "  FAIL $2 ($n x $3)"; FAIL=1; fi
}
FAIL=0; LEGS="${LEGS:-x360 arcade swap}"; has(){ case " $LEGS " in *" $1 "*) return 0;; esac; return 1; }
drive(){ [ "${SCORE_ONLY:-0}" = "1" ] && return 0; bash scripts/nav_mac.sh "$@" 2>&1 | grep "\[nav\]" | cut -c1-120; }
STAGE=( 2 's:0.5' 1000 's:3' 1000 's:3' 1000 's:3' 1000 's:3' 1000 'W:m02_stg' 's:6' shot )   # hub -> NORMAL PLAY -> 1P -> Original -> char -> shot -> stage 1

note "== modes_mac $TAG  bin=$BIN  $(date '+%F %T')"
if has x360; then
note "-- 1. XBOX 360 MODE to stage 1"
NVKPNG=60 RUN_SECS=300 drive "${TAG}_x360" "$BIN" -- \
  10 'w:SYS_BGM cue0 (mushifuta_Menu02)' 's:3' 1000 'w:SYS_SE cue1 (SE_OK01)' 's:2' 4 's:3.6' 1000 'w:\[modeidx\] .*XBOX-360' \
  'W:\[modswap\] #2 DONE\|\[xex\] XexLoadImage.*reco_abnormal' 's:45' shot 10 's:3' 'log:\[p0build\] menu_game_title\|MODE SELECT\|\[modeidx\]' \
  "${STAGE[@]}" 'log:m02_stg\|\[modswap\]\|FATAL\|VK_ERROR'
chk "${TAG}_x360" "both modules bound"      '\[modreg\] .*BOUND' 2
chk "${TAG}_x360" "XBOX-360 mode decided"   '\[modeidx\] .*XBOX-360'
chk "${TAG}_x360" "abn module loaded"       'XexLoadImage.*reco_abnormal'
chk "${TAG}_x360" "stage 1 reached (m02_stg)" 'm02_stg'
[ "$(grep -c FATAL _local/nav_mac/${TAG}_x360/guest.log)" = 0 ] && note "  PASS no FATAL" || { note "  FAIL FATAL in log"; FAIL=1; }

fi
if has arcade; then
note "-- 2. ARCADE to stage 1"
NVKPNG=60 RUN_SECS=240 drive "${TAG}_arcade" "$BIN" -- hub "${STAGE[@]}" 'log:m02_stg\|\[modeidx\]\|FATAL'
chk "${TAG}_arcade" "ARCADE mode decided"   '\[modeidx\] .*ARCADE'
chk "${TAG}_arcade" "stage 1 reached"       'm02_stg'
fi
if has swap; then
note "-- 3. SWAP CYCLE arcade -> x360 -> arcade (hub B,A = back to the shell top menu; card panel resets to ARCADE)"
NVKPNG=0 RUN_SECS=420 drive "${TAG}_swap" "$BIN" -- hub \
  2000 's:2' 1000 'w:\[decide\].*item=-1\|vt=0x82050518' 's:4' \
  1000 'w:SYS_SE cue1 (SE_OK01)' 's:2' 4 's:3.6' 1000 'w:\[modeidx\] .*XBOX-360' 'W:\[modswap\] #2 DONE' 's:45' 10 's:4' 'log:\[p0build\]\|\[modswap\]' \
  2000 's:2' 1000 's:4' \
  1000 'w:SYS_SE cue1 (SE_OK01)' 's:4' 1000 'w:\[modeidx\] .*ARCADE' 'W:\[modswap\] #3 DONE' 's:45' 10 's:4' 'log:\[p0build\]\|\[modswap\]\|FATAL'
# [modswap] #1 is the BOOT activation ((none) -> reco_normal); the first real swap is #2.
chk "${TAG}_swap" "swap #2 (normal -> abn) DONE"   '\[modswap\] #2 DONE'
chk "${TAG}_swap" "swap #3 (abn -> normal) DONE"   '\[modswap\] #3 DONE'
chk "${TAG}_swap" "table residue 0 at both swaps" 'residue=0' 2
chk "${TAG}_swap" "hub built at boot and rebuilt after swap #2" '\[p0build\] menu_game_title' 2
# after swap #3 the arcade module re-enters on its EXISTING hub model (no [p0build]); the hub is proven by the menu
# engine's ACTIVE state with the HUB vtable (NAV_MAP: HUB vt=0x820503B0, shell TOP MENU vt=0x82050518) after the swap.
n3=$(sed -n "$(grep -n '\[modswap\] #3 DONE' _local/nav_mac/${TAG}_swap/guest.log | cut -d: -f1),\$p" _local/nav_mac/${TAG}_swap/guest.log 2>/dev/null | grep -c 'BA4D8(ACTIVE).*vt=0x820503B0')
[ "${n3:-0}" -ge 1 ] && note "  PASS hub ACTIVE after swap #3 ($n3 x)" || { note "  FAIL no hub ACTIVE after swap #3"; FAIL=1; }
[ "$(grep -c 'FATAL\|VK_ERROR' _local/nav_mac/${TAG}_swap/guest.log)" = 0 ] && note "  PASS no FATAL/VK_ERROR in the swap run" || { note "  FAIL FATAL/VK_ERROR in the swap run"; FAIL=1; }
fi
[ $FAIL = 0 ] && note "VERDICT PASS" || note "VERDICT FAIL"
exit $FAIL
