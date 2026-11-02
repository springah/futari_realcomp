#!/bin/bash
# rc_stage_win_public.sh <version>  -- stage the PUBLIC (asset-free) Windows release folder + zip: the GitHub-release form of
# rc_stage_win.sh. Ships ZERO game data (dist/next_release/STAGING.md): the tester supplies their own dump and the launcher's
# first-run wizard builds assets\ + shell\ with tools\extract\. Run from git-bash AFTER `bash build_win_dll.sh` at the RC commit
# (or with the gated build/ bytes still in place: the exe build id must name HEAD or a docs/scripts-only ancestor of it).
#
#   bash scripts/rc_stage_win_public.sh 0.3.0-rc3
#
# Output: ../_rc/<version>-win-public/Futari-Realcomp-Windows-v<version>/   (one folder inside the zip)
#         ../_rc/Futari-Realcomp-Windows-v<version>-public.zip  (+ .sha256 / .md5)   BUILD.txt + MD5.txt inside the folder.
# Refuses: dirty / -dirty build id (same rules as rc_stage_win.sh), and -- after staging -- ANY .xex, media/, assets/ or shell/
# content in the output tree (the game-data scan is the point of this script).
set -u
cd "$(dirname "$0")/.."
REPO="$PWD"; PROJ="$(cd .. && pwd)"
VER="${1:?usage: rc_stage_win_public.sh <version>}"
DECOMP_REPO="${DECOMP_REPO:-$PROJ/futari_decomp}"
RC="$PROJ/_rc"; RD="$RC/$VER-win-public"; NAME="Futari-Realcomp-Windows-v$VER"; ST="$RD/$NAME"
die(){ echo "[stage-public] STOP: $*" >&2; exit 1; }
log(){ echo "[stage-public] $*"; }

# ---- preflight: build outputs + the build id they carry (same acceptance as rc_stage_win.sh)
for f in build/futari_combined.exe build/futari_game_normal.dll build/futari_game_abn.dll; do [ -f "$f" ] || die "missing $f (run build_win_dll.sh)"; done
# module DLLs: the Ver 1.5 pair always; the Black Label pair when build_win_dll.sh produced them (2026-11-02, Windows arms for modules 4/5;
# inert without the player's DLC data). Everything below that lists or hashes DLLs uses this set.
MODDLLS=$(ls build/futari_game_*.dll); NMOD=$(echo $MODDLLS | wc -w | tr -d ' ')
BL_FILES=""; [ -f build/futari_game_kiniro.dll ] && BL_FILES="$BL_FILES"$'\n'"  futari_game_kiniro.dll     Black Label ARCADE module (grey in the menu until your Black Label DLC data is found: RT_DLC_ROOT)"
[ -f build/futari_game_kiniro_abn.dll ] && BL_FILES="$BL_FILES"$'\n'"  futari_game_kiniro_abn.dll Black Label XBOX 360 mode module (same DLC gate)"
for f in tools/extract/futari_extract.py tools/extract/extract_assets.bat tools/extract/manifest_v1.tsv docs/DUMPING.md \
         docs/RC_KNOWN_ISSUES.md docs/RC1_HANDS_CHECKLIST.md "dist/next_release/Futari 1.5.bat" save_freshcard; do
  [ -e "$f" ] || die "missing $f"; done
HR=$(git rev-parse HEAD); HRS=$(git rev-parse --short HEAD)
HD=$(git -C "$DECOMP_REPO" rev-parse HEAD 2>/dev/null || echo unknown)
DIRTY=$(git status --porcelain | grep -v '^?? ')
[ -z "$DIRTY" ] || { echo "$DIRTY"; [ "${ALLOW_DIRTY:-0}" = 1 ] || die "realcomp worktree dirty (ALLOW_DIRTY=1 to override)"; }
if grep -a -q "$HRS-dirty" build/futari_combined.exe; then BID="$HRS-dirty"; elif grep -a -q "$HRS" build/futari_combined.exe; then BID="$HRS"; else BID=""; fi
ENGINE_COMMIT="$HRS"
if [ -z "$BID" ]; then for c in $(git rev-list --max-count=40 HEAD~1 2>/dev/null); do cs=$(git rev-parse --short "$c"); if grep -a -q "$cs" build/futari_combined.exe; then BID="$cs"; break; fi; done; fi
case "$BID" in
  "$HRS") ;;
  "$HRS-dirty") [ "${ALLOW_DIRTY:-0}" = 1 ] || die "exe stamped -dirty: commit, rebuild";;
  "") [ "${ALLOW_DIRTY:-0}" = 1 ] || die "exe carries no recent commit's build id: rebuild";;
  *) if git merge-base --is-ancestor "$BID" HEAD 2>/dev/null && [ -z "$(git diff --name-only "$BID" HEAD | grep -v -E '^(docs/|scripts/|dist/|STATUS\.md$|README\.md$)')" ]; then
       ENGINE_COMMIT="$BID"; log "exe build id $BID is an ancestor of HEAD $HRS with docs/scripts-only changes between: accepted (engine commit $BID)"
     else [ "${ALLOW_DIRTY:-0}" = 1 ] || die "exe build id ($BID) is not HEAD ($HRS) and engine sources changed since: rebuild"; fi;;
esac
log "exe build id: $BID  HEAD: $HRS  decomp: ${HD:0:12}"
TAGV="v$VER"; TAGC=$(git rev-list -n1 "$TAGV" 2>/dev/null || echo none)
TU_SH=$(ls "$DECOMP_REPO"/decomp/shell/*.cpp 2>/dev/null | wc -l | tr -d ' '); TU_G=$(ls "$DECOMP_REPO"/decomp/game/*.cpp 2>/dev/null | wc -l | tr -d ' '); TU_A=$(ls "$DECOMP_REPO"/decomp/game_abn/*.cpp 2>/dev/null | wc -l | tr -d ' ')

# ---- layout (STAGING.md steps 1-6; NO assets/, NO shell/)
rm -rf "$RD"; mkdir -p "$ST/docs" "$ST/tools/extract" "$ST/logs"
cp build/futari_combined.exe $MODDLLS "$ST/"
tr -d '\r' < "dist/next_release/Futari 1.5.bat" | sed 's/$/\r/' > "$ST/Futari 1.5.bat"
tr -d '\r' < tools/extract/extract_assets.bat | sed 's/$/\r/' > "$ST/tools/extract/extract_assets.bat"
cp tools/extract/futari_extract.py tools/extract/manifest_v1.tsv "$ST/tools/extract/"
cp docs/DUMPING.md docs/RC_KNOWN_ISSUES.md docs/RC1_HANDS_CHECKLIST.md "$ST/docs/"
cp -r save_freshcard "$ST/save_freshcard"

# ---- README (the rc_stage_win.sh text with the F&F "data included" paragraph replaced by the first-run wizard)
cat > "$ST/README.txt" <<EOR
Mushihimesama Futari Ver 1.5 -- futari_realcomp, native Windows build $VER (RELEASE CANDIDATE, test build).
Release candidate, not a final release. Engine build id: $BID

THIS PACKAGE SHIPS NO GAME DATA
  You supply your own copy of the game. On first run the launcher asks for it: drag in either the game folder copied
  off your own console's storage (the "435A07D7" folder) or your disc ISO, and the built-in extractor builds assets\\
  from it, verified against the console's own integrity hashes and a reference manifest (58 files). The one-time
  extraction needs Python 3 (https://www.python.org/downloads/ -- tick "Add python.exe to PATH").
  Full dumping instructions: docs\\DUMPING.md.  You can also drag your dump onto tools\\extract\\extract_assets.bat.

REQUIREMENTS
  64-bit Windows 10/11 with a Vulkan 1.1+ GPU driver (any current NVIDIA / AMD / Intel driver). No installer.

MODES
  Both Ver 1.5 modes are in this build: ARCADE (1.5 Original) and XBOX 360 MODE. Pick one at the in-game title
  select; going back to the top menu and picking the other switches live, no relaunch. Ver 1.01 and Black Label
  stay greyed (not included in the Windows build).

RUN
  Double-click "Futari 1.5.bat". First run: the extraction wizard above, then a fresh save is copied from
  save_freshcard\\ to save\\. It writes the session log to logs\\. Quit with the window's close button or the
  game's own exit.

CONTROLS
  Keyboard: arrows = D-pad, Z = A (shot), X = B (bomb), C = X, V = Y, Enter = START, Right Shift = BACK,
  F11 = fullscreen on/off. The game window must have focus (keys are ignored while another window is in front).
  Controllers: XInput pads (Xbox-style). A second pad is PLAYER 2: press START on it at the character select,
  or pick 2P SIDE START. Button remapping, screen rotation (TATE), layout, picture and sound settings are the
  game's own OPTIONS menus and persist in the save.

$(sed 's/macOS/this build/g' docs/RC_KNOWN_ISSUES.md)

SAVES AND LOGS
  Saves:  save\\      (next to the .bat; back this up to keep settings + scores)
  Logs:   logs\\      (one file per session)

BUG REPORTS
  https://github.com/springah/futari_realcomp/issues -- attach the newest log file, say which mode (ARCADE or
  XBOX 360), keyboard or pad, and what you were doing. docs\\RC1_HANDS_CHECKLIST.md is the test checklist.

FILES
  futari_combined.exe        the game (both modes)
  futari_game_normal.dll     ARCADE 1.5 module
  futari_game_abn.dll        XBOX 360 mode module$BL_FILES
  Futari 1.5.bat             launcher (+ first-run extraction wizard)
  tools\\extract\\             the asset extractor + reference manifest
  docs\\                      DUMPING.md, RC_KNOWN_ISSUES.md, RC1_HANDS_CHECKLIST.md
  assets\\ + shell\\           built by the wizard from YOUR dump (not shipped)
  save_freshcard\\            fresh-save template (used on first run)

BUILD (docs/PLAN_RC1.md section 6; public form of the Windows $VER cut, dist/next_release/STAGING.md)
  Version:            $VER (Windows, asset-free)
  Built:              $(date '+%Y-%m-%d %H:%M %Z')
  futari_realcomp:    $HR   (tree at staging; engine built at $ENGINE_COMMIT; tag $TAGV @ ${TAGC:0:12})
  futari_decomp:      $HD
  Decomp TUs:         shell $TU_SH, game/ARCADE $TU_G, game_abn/360 $TU_A source TUs in the sibling tree at build time
  Engine:             combined host exe (shell + kernel + renderer + bridge) + $NMOD module DLLs ($(echo $MODDLLS | sed 's|build/futari_game_||g;s|\.dll||g')), Win32 window + XInput,
                      SDL3 audio sink (static), Vulkan via the system loader. Launch environment: see "Futari 1.5.bat".
EOR
sed -i 's/$/\r/' "$ST/README.txt"; cp "$ST/README.txt" "$RD/README.txt"

# ---- hashes + build block
( cd "$ST" && md5sum futari_combined.exe futari_game_*.dll "Futari 1.5.bat" tools/extract/futari_extract.py tools/extract/manifest_v1.tsv ) > "$ST/MD5.txt"
{ echo "version=$VER platform=windows form=public-asset-free"; echo "realcomp=$HR"; echo "engine_commit=$ENGINE_COMMIT"; echo "decomp=$HD"; echo "exe_build_id=$BID"; echo "tag=$TAGV@$TAGC"; echo "staged=$(date -Iseconds)"; } > "$ST/BUILD.txt"
cp "$ST/MD5.txt" "$RD/MD5.txt"; cp "$ST/BUILD.txt" "$RD/BUILD.txt"
cat "$ST/MD5.txt"

# ---- GAME-DATA SCAN: refuse to zip if anything disc-shaped is in the tree
BAD=$(cd "$RD" && find . -path "*/save_freshcard" -prune -o \( -iname '*.xex' -o -iname 'media' -o -iname 'assets' -o -iname 'shell' -o -iname '*.bin' -o -iname '*.xma' -o -iname '*.xwb' -o -iname '*.xsb' \) -print)  # save_freshcard = runtime-generated template (STAGING.md step 5), not disc content
[ -z "$BAD" ] || { echo "$BAD"; die "game-data-shaped paths in the public tree"; }
BIG=$(cd "$RD" && find . -type f -size +60M ! -name futari_combined.exe ! -name 'futari_game_*.dll' -print)
[ -z "$BIG" ] || { echo "$BIG"; die "unexpected large files in the public tree"; }
log "game-data scan: clean ($(find "$ST" -type f | wc -l | tr -d ' ') files, $(du -sh "$ST" | cut -f1))"

# ---- zip
ZIP="$RC/$NAME-public.zip"; rm -f "$ZIP"
if [ -x "/c/Program Files/7-Zip/7z.exe" ]; then
  ( cd "$RD" && "/c/Program Files/7-Zip/7z.exe" a -tzip -mx=5 -bso0 -bsp0 "$ZIP" "$NAME" ) || die "7z failed"
else
  powershell -NoProfile -Command "Compress-Archive -Path '$(cygpath -w "$ST")' -DestinationPath '$(cygpath -w "$ZIP")' -CompressionLevel Optimal" || die "Compress-Archive failed"
fi
sha256sum "$ZIP" | tee "$ZIP.sha256"; md5sum "$ZIP" | tee "$ZIP.md5"
log "staged folder: $ST"; log "zip: $ZIP ($(du -h "$ZIP" | cut -f1))"
echo; echo "PUBLIC form (no game data). Wizard smoke: copy the folder, run tools/extract against a dump, then bash scripts/rc_smoke_win.sh <copy>"
