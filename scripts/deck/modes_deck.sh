#!/bin/bash
# modes_deck.sh <tag> -- the two-mode drive ON THE STEAM DECK (port of scripts/modes_mac.sh; runs on the Deck):
# XBOX 360 MODE to stage 1, ARCADE to stage 1, the arcade -> x360 -> arcade swap cycle; verdict from the logs.
#   ssh deck 'bash ~/scripts/modes_deck.sh d1'      bank ~/futari_nav/<tag>_*/, verdict ~/futari_nav/<tag>_VERDICT.txt
set -u
TAG="${1:?tag}"; D="$(dirname "$0")"; V="$HOME/futari_nav/${TAG}_VERDICT.txt"; mkdir -p "$HOME/futari_nav"; : > "$V"
note(){ echo "$*" | tee -a "$V"; }; FAIL=0
chk(){ local n; n=$(grep -c "$3" "$HOME/futari_nav/$1/guest.log" 2>/dev/null); n=${n:-0}; if [ "$n" -ge "${4:-1}" ]; then note "  PASS $2 ($n x)"; else note "  FAIL $2 ($n x $3)"; FAIL=1; fi; }
STAGE=( 2 's:0.5' 1000 's:3' 1000 's:3' 1000 's:3' 1000 's:3' 1000 'W:m02_stg' 's:6' )
note "== modes_deck $TAG $(date '+%F %T') session=$(pgrep -x gamescope-wl >/dev/null && echo gaming || echo desktop)"
note "-- 1. XBOX 360 MODE to stage 1"
bash "$D/nav_deck.sh" "${TAG}_x360" -- 10 'w:SYS_BGM cue0 (mushifuta_Menu02)' 's:3' 1000 'w:SYS_SE cue1 (SE_OK01)' 's:2' 4 's:3.6' 1000 'w:\[modeidx\] .*XBOX-360' 'W:\[modswap\] #2 DONE' 's:45' 10 's:3' "${STAGE[@]}" 2>&1 | grep "\[nav\]" | cut -c1-110
chk "${TAG}_x360" "both modules bound" '\[modreg\] .*BOUND' 2; chk "${TAG}_x360" "XBOX-360 decided" '\[modeidx\] .*XBOX-360'; chk "${TAG}_x360" "abn module loaded" 'XexLoadImage.*reco_abnormal'; chk "${TAG}_x360" "stage 1 reached" 'm02_stg'
[ "$(grep -c FATAL "$HOME/futari_nav/${TAG}_x360/guest.log")" = 0 ] && note "  PASS no FATAL" || { note "  FAIL FATAL"; FAIL=1; }
note "-- 2. ARCADE to stage 1"
bash "$D/nav_deck.sh" "${TAG}_arcade" -- hub "${STAGE[@]}" 2>&1 | grep "\[nav\]" | cut -c1-110
chk "${TAG}_arcade" "ARCADE decided" '\[modeidx\] .*ARCADE'; chk "${TAG}_arcade" "stage 1 reached" 'm02_stg'
note "-- 3. SWAP CYCLE"
bash "$D/nav_deck.sh" "${TAG}_swap" -- hub 2000 's:2' 1000 'w:\[decide\].*item=-1\|vt=0x82050518' 's:4' 1000 'w:SYS_SE cue1 (SE_OK01)' 's:2' 4 's:3.6' 1000 'w:\[modeidx\] .*XBOX-360' 'W:\[modswap\] #2 DONE' 's:45' 10 's:4' 2000 's:2' 1000 's:4' 1000 'w:SYS_SE cue1 (SE_OK01)' 's:4' 1000 'w:\[modeidx\] .*ARCADE' 'W:\[modswap\] #3 DONE' 's:45' 10 's:4' 2>&1 | grep "\[nav\]" | cut -c1-110
chk "${TAG}_swap" "swap #2 DONE" '\[modswap\] #2 DONE'; chk "${TAG}_swap" "swap #3 DONE" '\[modswap\] #3 DONE'; chk "${TAG}_swap" "residue 0 twice" 'residue=0' 2
n3=$(sed -n "$(grep -n '\[modswap\] #3 DONE' "$HOME/futari_nav/${TAG}_swap/guest.log" | cut -d: -f1),\$p" "$HOME/futari_nav/${TAG}_swap/guest.log" 2>/dev/null | grep -c 'BA4D8(ACTIVE).*vt=0x820503B0'); [ "${n3:-0}" -ge 1 ] && note "  PASS hub ACTIVE after swap #3" || { note "  FAIL no hub after swap #3"; FAIL=1; }
[ "$(grep -c 'FATAL\|VK_ERROR' "$HOME/futari_nav/${TAG}_swap/guest.log")" = 0 ] && note "  PASS no FATAL/VK_ERROR" || { note "  FAIL FATAL/VK_ERROR"; FAIL=1; }
[ $FAIL = 0 ] && note "VERDICT PASS" || note "VERDICT FAIL"
