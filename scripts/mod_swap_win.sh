#!/bin/bash
# WINDOWS PORT -- generated from scripts/mod_swap_mac.sh by scripts/win_port.sh (2026-11-07); edit the Mac original and regenerate. Differences: win_shim.sh
# (pkill/pgrep/ps/md5), run_win.sh as the launcher, /c/tmp for the FIFO + drive lock. Engine copy: a uniquely named .exe beside the module DLLs.
# mod_swap_mac.sh <tag> <host> <modeIdx>  -- w1107 (2026-11-07) SWAP-BACK gate for a non-reco module (the registry-swap
# hazard, PLAN_other_modes §1.4 / §3.6): boot (reco_normal) -> TOP MENU -> the module's row -> decide modeIdx K ->
# [modswap] #2 to the module -> its title -> START -> hub -> B, A (back to the shell TOP MENU, whose cursor RESETS to
# Ver 1.5: measured h6_swap1 shot_4, and UP wraps 0 -> EXIT -> Ver 1.01) -> A -> A (decide Ver 1.5 ARCADE) -> [modswap] #3 back to reco_normal -> START -> hub -> NORMAL PLAY ->
# stage 1. Asserts: both swaps DONE, residue=0 at both, the UNION-ZERO line at both (registry fix present), modeIdx 0
# decided after the module, stage BGM m02_stg1 AFTER swap #3, 0 FATAL / VK_ERROR / UNMAPPED / kdrop / wrong-module.
# Takes the drive lock; game root KIN_ROOT (default assets). Bank: _local/nav_mac/<tag>/{verdict.txt,guest.log,...}
set -u
source "$(dirname "$0")/win_shim.sh"   # Windows: pkill/pgrep/ps/md5 shims, /c/tmp
cd "$(dirname "$0")/.."
TAG="${1:?tag}"; BIN="${2:?host}"; K="${3:?modeIdx}"
ROW=$(( K / 2 )); KIN_ROOT="${KIN_ROOT:-$PWD/assets}"
DOWNS=(); UPS=(); for ((r=0;r<ROW;r++)); do DOWNS+=(2 's:1.5'); UPS+=(1 's:1.5'); done
SUB=(); case "$K" in 1|3|5|7) SUB=(4 's:3.6');; esac
LOCK=/c/tmp/futari_drive.lock
until mkdir "$LOCK" 2>/dev/null; do sleep 20; done
trap 'rmdir "$LOCK" 2>/dev/null' EXIT
while pgrep -x futari_combined >/dev/null; do sleep 30; done
SAVE="_local/saves/save_kin_$TAG"; rm -rf "$SAVE"; cp -R save_freshcard "$SAVE"
STAGE=( 2 's:0.5' 1000 's:3' 1000 's:3' 1000 's:3' 1000 's:3' 1000 'W:m02_stg' 's:6' shot )
RT_GAME_ROOT="$KIN_ROOT" RT_SAVE="$SAVE" NVKPNG=60 RUN_SECS="${RUN_SECS:-420}" bash scripts/nav_win.sh "$TAG" "$BIN" -- \
  10 'w:SYS_BGM cue0 (mushifuta_Menu02)' 's:4' "${DOWNS[@]}" 's:1' shot \
  1000 'w:SYS_SE cue1 (SE_OK01)' 's:3' "${SUB[@]}" 1000 "w:\[modeidx\] sub_821C3F38 modeIdx=$K" 'W:\[modswap\] #2 DONE' 's:8' shot \
  10 'W:\[p0build\] menu_game_title' 's:3' shot \
  2000 's:2' 1000 'w:\[decide\].*item=-1\|vt=0x82050518' 's:5' shot \
  's:1' shot 1000 'w:SYS_SE cue1 (SE_OK01)' 's:4' 1000 'w:\[modeidx\] sub_821C3F38 modeIdx=0' 'W:\[modswap\] #3 DONE' 's:8' shot \
  10 's:4' 10 's:4' 'log:\[p0build\]\|\[modswap\]\|FATAL' "${STAGE[@]}" 's:10' shot \
  'log:m02_stg\|\[modswap\]\|FATAL\|VK_ERROR'
B="_local/nav_mac/$TAG"; G="$B/guest.log"; V="$B/verdict.txt"; : > "$V"; FAIL=0
ok(){ echo "PASS $1" | tee -a "$V"; }; bad(){ echo "FAIL $1" | tee -a "$V"; FAIL=1; }
cnt(){ grep -a -c -- "$1" "$G" 2>/dev/null || true; }
[ -s "$G" ] || { bad "no guest log"; exit 1; }
MOD=$(grep -a -o "\[modswap\] #2 DONE .* live module is now [a-z_]*" "$G" | awk '{print $NF}')
grep -q "\[modeidx\] sub_821C3F38 modeIdx=$K " "$G" && ok "decide modeIdx=$K" || bad "decide modeIdx=$K"
[ -n "$MOD" ] && ok "swap #2 -> $MOD" || bad "swap #2"
grep -q "\[modswap\] #3 DONE .* live module is now reco_normal" "$G" && ok "swap #3 -> reco_normal (swap back)" || bad "swap #3 back to reco_normal"
R=$(cnt 'residue=0'); [ "$R" -ge 2 ] && ok "residue=0 at both retirements ($R)" || bad "residue=0 x$R (want 2); $(grep -a -o 'residue=[0-9]*' "$G" | tr '\n' ' ')"
U=$(cnt 'UNION-ZERO'); [ "$U" -ge 2 ] && ok "UNION-ZERO at both swaps ($U)" || bad "UNION-ZERO x$U (want 2)"
S3=$(grep -a -n '\[modswap\] #3 DONE' "$G" | head -1 | cut -d: -f1)
if [ -n "$S3" ]; then tail -n +"$S3" "$G" | grep -a -q 'BGM cue1 (m02_stg1)' && ok "reco_normal stage 1 after swap back (m02_stg1)" || bad "no m02_stg1 after swap #3"; fi
for p in 'FATAL' 'VK_ERROR\|VUID' '\[indirect\] UNMAPPED' '\[kdrop\]' 'IS THE WRONG MODULE'; do c=$(cnt "$p"); [ "$c" = 0 ] && ok "zero '$p'" || bad "$c x '$p'"; done
echo "== $TAG: $(grep -a -c '^PASS' "$V") PASS / $(grep -a -c '^FAIL' "$V") FAIL ($(date '+%F %T'))" | tee -a "$V"
exit $FAIL
