#!/bin/bash
# kiniro_deck.sh <tag> [4|5] -- the BLACK LABEL play drive ON THE STEAM DECK (port of scripts/kiniro_gate_mac.sh's log
# asserts; runs on the Deck over ssh, invisible in Gaming Mode: the log is the witness). Drives nav_deck.sh on the
# extracted AppImage (~/squashfs-root/AppRun, a 4-module host): title -> START -> DOWN, DOWN (Black Label row) -> A
# (arcade_front; LEFT first for modeIdx 5 = XBOX 360 MODE) -> A (decide modeIdx 4|5) -> module swap -> START (module
# title) -> hub -> DOWN -> A x5 (NORMAL PLAY, 4 s gaps) -> stage 1 -> idle death -> GAME OVER. The DLC data must sit in
# the engine's second root, ~/.local/share/futari-realcomp/dlc/media/Rom/ (RT_DLC_ROOT default = <save dir>/../dlc).
#   ssh deck 'bash ~/scripts/kiniro_deck.sh bl4 4'      bank ~/futari_nav/<tag>/guest.log, verdict ~/futari_nav/<tag>_VERDICT.txt
# No pixel rungs here (no frame dumps on the Deck drive): PIX-RICH / PIX-REGRESS stay Mac-side (docs/PLAN_kiniro_bringup.md).
set -u
TAG="${1:?tag}"; K="${2:-4}"; D="$(dirname "$0")"; V="$HOME/futari_nav/${TAG}_VERDICT.txt"; mkdir -p "$HOME/futari_nav"; : > "$V"
case "$K" in 4) MODNAME=kiniro_normal; SUB="ARCADE"; SUBSTEPS=();; 5) MODNAME=kiniro_abnormal; SUB="XBOX-360 MODE"; SUBSTEPS=(4 's:3.6');; *) echo "mode must be 4 or 5"; exit 2;; esac
note(){ echo "$*" | tee -a "$V"; }; FAIL=0
ok(){ note "  PASS $1"; }; bad(){ note "  FAIL $1"; FAIL=1; }
note "== kiniro_deck $TAG modeIdx=$K ($MODNAME) $(date '+%F %T') session=$(pgrep -x gamescope-wl >/dev/null && echo gaming || echo desktop) dlc=$(ls "$HOME/.local/share/futari-realcomp/dlc/media/Rom" 2>/dev/null | tr '\n' ' ')"
# DROPOUT census + title probe armed like the Mac gate (nav_deck.sh passes NAV_ENV through to the service)
NAV_ENV="RVK_DRAWCENSUS=2 RVK_TITLEPROBE=1" bash "$D/nav_deck.sh" "$TAG" -- \
  10 'w:SYS_BGM cue0 (mushifuta_Menu02)' 's:4' 2 's:1.5' 2 's:2.5' \
  1000 'w:SYS_SE cue1 (SE_OK01)' 's:3' "${SUBSTEPS[@]}" \
  1000 "w:\[modeidx\] sub_821C3F38 modeIdx=$K" 's:2' \
  'W:\[modswap\] #[0-9]* DONE' 's:5' 'log:\[modswap\]\|\[loadgame\]\|\[xenum\] DLC gate\|BLDATA' \
  10 'w:\[p0build\] menu_game_title' 's:3' 2 's:1.5' 1000 's:4' 1000 's:4' 1000 's:4' 1000 's:4' 1000 's:4' \
  'W:BGM cue1 (m02_stg1)' 's:5' 'W:BGM cue4 (m05_govr)' 'W:BGM cue4 (m05_govr)' 's:4' 2>&1 | grep "\[nav\]\|^      " | cut -c1-150
G="$HOME/futari_nav/$TAG/guest.log"; [ -s "$G" ] || { note "FAIL no guest log ($G)"; note "VERDICT FAIL"; exit 1; }
chk(){ local name="$1" pat="$2"; grep -q -- "$pat" "$G" && ok "$name" || bad "$name (no '$pat')"; }
zero(){ local name="$1" pat="$2" c; c=$(grep -c -- "$pat" "$G"); [ "$c" = 0 ] && ok "$name (0)" || bad "$name ($c x '$pat')"; }
chk "all modules bound (N/N)" '\[modreg\] \([0-9]*\)/\1 module DLL(s) bound'
chk "kiniro modules bound" "\[modreg\] .*BOUND  $MODNAME"
chk "DLC gate OWNED (dlc root)" '\[xenum\] DLC gate: entry 0 .* OWNED (data present in .*/dlc)'
chk "BLDATA mounted" "mount 'BLDATA:'"
chk decide   "\[modeidx\] sub_821C3F38 modeIdx=$K ($SUB, title=2)"
chk swap     "\[modswap\] #2 DONE .* $MODNAME"
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
DC=$(tail -n +"$SW" "$G" | grep -c 'DROPOUT-CONFIRMED'); [ "$DC" = 0 ] && ok "dropout after swap (0)" || bad "dropout after swap ($DC)"
HB=$(tail -n +"$SW" "$G" | grep -n '\[p0build\] menu_game_title' | head -1 | cut -d: -f1); HB=${HB:-1}
note "  NOTE dropouts before the swap (shell title residual): $(head -n "$SW" "$G" | grep -c 'DROPOUT-CONFIRMED'); after the swap: $(tail -n +"$SW" "$G" | head -n "$HB" | grep -c 'DROPOUT-CONFIRMED') at the module title (before the hub), $(tail -n +"$SW" "$G" | tail -n +"$HB" | grep -c 'DROPOUT-CONFIRMED') after the hub  frames: $(grep -o 'submit f[0-9]*' "$G" | tail -1)"
grep -E '\[modreg\] [0-9]+/|\[xenum\] DLC gate|BLDATA|\[modeidx\]|\[modswap\] #2 DONE' "$G" | cut -c1-170 | sed 's/^/  | /' | tee -a "$V"
[ $FAIL = 0 ] && note "VERDICT PASS" || note "VERDICT FAIL"
exit $FAIL
