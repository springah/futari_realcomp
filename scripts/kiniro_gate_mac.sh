#!/bin/bash
# kiniro_gate_mac.sh <tag> <host>   -- Black Label SMOKE GATE (docs/PLAN_kiniro_bringup.md "Step 3b").
#
# Runs the step-3 play drive (scripts/kiniro_boot_mac.sh: title -> Black Label row -> arcade_front -> decide modeIdx 4
# -> module swap -> START -> hub -> DOWN -> NORMAL PLAY -> A x5 -> stage 1 -> idle death -> GAME OVER) with the DROPOUT
# census armed, then turns the guest log into PASS/FAIL lines. It is a REGRESSION gate for the engine on the Black Label
# module, not a quality gate: no reference pixels exist for this module yet, so the pixel comparison the Ver 1.5 gates do
# (stagepix / boss plate) has no counterpart here. What it asserts:
#   decide   [modeidx] modeIdx=4 (ARCADE, title=2)           swap    [modswap] #2 DONE -- live module is now kiniro_normal
#   hub      [p0build] menu_game_title after the swap         stage   BGM cue1 (m02_stg1)   gameover  BGM cue4 (m05_govr)
#   draws    a [nvk] heartbeat with >= 150 draws between the stage and game-over cues (the field rendered)
#   clean    0 FATAL, 0 VK_ERROR/VUID, 0 [indirect] UNMAPPED, 0 [kdrop], 0 IS THE WRONG MODULE
#   dropout  0 DROPOUT-CONFIRMED AFTER the swap (title dropouts before it are the known RT_POOLRELEASE shell residual)
#   kgate    [kgate] lines name ONLY levers the audit listed (any other name = a new literal writer slipped in)
#   bash scripts/kiniro_gate_mac.sh k3gate1 build/kin/futari_combined
# Bank: _local/nav_mac/<tag>/{verdict.txt,harvest.txt,guest.log,shot_N.png}. Exit 0 = all PASS.
set -u
cd "$(dirname "$0")/.."
TAG="${1:?tag}"; BIN="${2:?host binary}"
STEPS='10 w:\[p0build\]\ menu_game_title s:3 shot 2 s:1.5 1000 s:4 shot 1000 s:4 shot 1000 s:4 shot 1000 s:4 shot 1000 s:4 shot'
# KIN_MODEIDX=4 (default) = Black Label ARCADE / kiniro_normal; 5 = Black Label XBOX 360 MODE / kiniro_abnormal (step 4c)
KIN_MODEIDX="${KIN_MODEIDX:-4}"; export KIN_MODEIDX
case "$KIN_MODEIDX" in 4) MODNAME=kiniro_normal; SUB="ARCADE";; 5) MODNAME=kiniro_abnormal; SUB="XBOX-360 MODE";; *) echo "KIN_MODEIDX must be 4 or 5"; exit 2;; esac
mkdir -p _local/kin3
RVK_DRAWCENSUS=2 RVK_TITLEPROBE=1 KIN_STEPS="$STEPS" bash scripts/kiniro_boot_mac.sh "$TAG" "$BIN" "${HOLD:-120}" > "_local/kin3/${TAG}_drive.out" 2>&1
B="_local/nav_mac/$TAG"; G="$B/guest.log"; V="$B/verdict.txt"; : > "$V"
[ -s "$G" ] || { echo "FAIL no guest log ($G)" | tee -a "$V"; exit 1; }
FAIL=0
ok(){ echo "PASS $1" | tee -a "$V"; }
bad(){ echo "FAIL $1" | tee -a "$V"; FAIL=1; }
chk(){ local name="$1" pat="$2"; grep -q -- "$pat" "$G" && ok "$name" || bad "$name (no '$pat')"; }
zero(){ local name="$1" pat="$2" c; c=$(grep -c -- "$pat" "$G"); [ "$c" = 0 ] && ok "$name (0)" || bad "$name ($c x '$pat')"; }
chk decide   "\\[modeidx\\] sub_821C3F38 modeIdx=$KIN_MODEIDX ($SUB, title=2)"
chk swap     "\\[modswap\\] #2 DONE .* $MODNAME"
SW=$(grep -n '\[modswap\] #2 DONE' "$G" | head -1 | cut -d: -f1); SW=${SW:-1}
tail -n +"$SW" "$G" | grep -q '\[p0build\] menu_game_title' && ok hub || bad "hub (no menu_game_title after the swap)"
ST=$(tail -n +"$SW" "$G" | grep -n 'BGM cue1 (m02_stg1)' | head -1 | cut -d: -f1)
GO=$(tail -n +"$SW" "$G" | grep -n 'BGM cue4 (m05_govr)' | head -1 | cut -d: -f1)
[ -n "$ST" ] && ok "stage (m02_stg1)" || bad "stage (no m02_stg1 BGM)"
[ -n "$GO" ] && ok "gameover (m05_govr)" || bad "gameover (no m05_govr BGM)"
if [ -n "$ST" ] && [ -n "$GO" ]; then
  MX=$(tail -n +"$SW" "$G" | sed -n "${ST},${GO}p" | grep -o '^\[nvk\] f[0-9]* draws=[0-9]*' | sed 's/.*draws=//' | sort -n | tail -1)
  [ "${MX:-0}" -ge 150 ] && ok "draws (max $MX/frame in the stage)" || bad "draws (max ${MX:-0}/frame between stage and game over)"
fi
zero fatal 'FATAL'
zero vkerr 'VK_ERROR\|VUID'
zero unmapped '\[indirect\] UNMAPPED'
zero kdrop '\[kdrop\]'
zero wrongmodule 'IS THE WRONG MODULE'
# Post-swap dropouts: FAIL unless the frame belongs to one of rc_census_mac.sh's NAMED AUTHENTIC classes (the same keys it uses:
# PRESS START strobe base 0x2530000 / v0=(-190.5,181.5); 360 card-LEFT quad 0x34E0000 / len=1 v0=(41.5,-284.5); w136 menu-atlas
# pair 0x49C4000; NOW-LOADING ring particles base 0x1C?4000 with v0=(253.5,273.6) or v0=(251.0,-5.4)). The Black Label module's own
# title/loading shows the ring-particle class at a fixed frame (f2068 in m1gate4 and dg_gate4b, base 0x1C54000 len=3 v0=(251.0,-5.4)),
# deterministic run to run, so it is INFO here exactly as the census treats it (2026-10-31).
NAMED='base=0x2530000\|v0=(-190.5,181.5)\|base=0x34E0000\|v0=(41.5,-284.5)\|base=0x49C4000\|base=0x1C.4000.*v0=(253.5,273.6)\|base=0x1C.4000.*v0=(251.0,-5.4)'
DCALL=$(tail -n +"$SW" "$G" | grep 'DROPOUT-CONFIRMED'); DCN=$(printf '%s\n' "$DCALL" | grep -c 'DROPOUT-CONFIRMED')
DCU=$(printf '%s\n' "$DCALL" | grep 'DROPOUT-CONFIRMED' | grep -v -c -- "$NAMED"); DCK=$(( DCN - DCU ))
[ "$DCU" = 0 ] && ok "dropout after swap outside the named classes (0; named-class INFO: $DCK)" || bad "dropout after swap outside the named classes ($DCU; named-class INFO: $DCK)"
[ "$DCK" -gt 0 ] && printf '%s\n' "$DCALL" | grep -- "$NAMED" | cut -c1-120 | sed 's/^/INFO named-class dropout after swap: /' | tee -a "$V"
PRE=$(head -n "$SW" "$G" | grep -c 'DROPOUT-CONFIRMED'); echo "NOTE dropouts before the swap (shell title residual): $PRE" | tee -a "$V"
UNK=$(grep -o '\[kgate\] [A-Z0-9_]* REFUSED' "$G" | awk '{print $2}' | sort -u | grep -v -x -e RT_SNDQFREE -e RT_PUMPFIX -e RT_CLEAR312 -e RT_NOPAUSE -e RT_TICKGP -e RT_FIXSPAWN -e RT_FORCEPLAYER -e RT_JOINMARK || true)
[ -z "$UNK" ] && ok "kgate levers known" || bad "kgate unknown lever(s): $(echo $UNK)"
# ---- pixel rungs (scripts/kiniro_pix.py; PLAN "Quality bar") ----
#   richness: the richest post-hub frame (shot_5 onward = select screens and the stage) must clear stagepix's control
#   floor (colours >= 15000, edges >= 15) -- a textured stage frame exists.
#   regress:  the hub frame (shot_4, 3 s after START at the module title) against a banked reference per mode; the first
#   run BANKS it (_local/kiniro/ref/mode<K>/hub.png), later runs must stay within 6 % differing pixels.
source "$(dirname "$0")/pymac.sh"
R=$("$PYTHON" scripts/kiniro_pix.py richness "$TAG" 5 2>&1 | tail -1); echo "$R" | tee -a "$V"; echo "$R" | grep -q "PIX-RICH PASS" || FAIL=1
R=$("$PYTHON" scripts/kiniro_pix.py regress "$TAG" 4 "_local/kiniro/ref/mode$KIN_MODEIDX/hub.png" 2>&1 | tail -1); echo "$R" | tee -a "$V"; echo "$R" | grep -q "PIX-REGRESS \(PASS\|BANKED\)" || FAIL=1
echo "== $TAG: $(grep -c '^PASS\|PIX-[A-Z]* \(PASS\|BANKED\)' "$V") PASS / $(grep -c '^FAIL\|PIX-[A-Z]* FAIL\|PIX-[A-Z]* NO-' "$V") FAIL  ($(date '+%F %T'))" | tee -a "$V"
exit $FAIL
