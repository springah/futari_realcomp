#!/bin/bash
# rc_stage_win.sh <version>  -- stage the WINDOWS family-and-friends release-candidate folder + zip (the Windows twin of
# the Mac's rc_cut_mac.sh step (b)+(d); docs/PLAN_RC1.md §6).  Run from git-bash AFTER `bash build_win_dll.sh` at the RC commit.
#
#   bash scripts/rc_stage_win.sh 0.3.0-rc2
#
# Output: ../_rc/<version>-win/Futari-Realcomp-Windows-v<version>/   (one folder inside the zip, assets INCLUDED: F&F only,
#         people who own the game -- never public; the public form ships zero game content, dist/next_release/STAGING.md)
#         ../_rc/Futari-Realcomp-Windows-v<version>.zip  (+ .sha256 / .md5)   BUILD.txt + MD5.txt inside the folder.
# Refuses: a dirty or -dirty-stamped build (the exe's build id must name the commit), missing DLLs, missing assets.
set -u
cd "$(dirname "$0")/.."
REPO="$PWD"; PROJ="$(cd .. && pwd)"
VER="${1:?usage: rc_stage_win.sh <version>}"
DECOMP_REPO="${DECOMP_REPO:-$PROJ/futari_decomp}"
RC="$PROJ/_rc"; RD="$RC/$VER-win"; NAME="Futari-Realcomp-Windows-v$VER"; ST="$RD/$NAME"
die(){ echo "[stage] STOP: $*" >&2; exit 1; }
log(){ echo "[stage] $*"; }

# ---- preflight: build outputs + the build id they carry
for f in build/futari_combined.exe build/futari_game_normal.dll build/futari_game_abn.dll; do [ -f "$f" ] || die "missing $f (run build_win_dll.sh)"; done
[ -f assets/default.xex ] || die "assets/default.xex missing (the F&F folder ships the game data)"
[ -f shell/default.xex ]  || die "shell/default.xex missing"
HR=$(git rev-parse HEAD); HRS=$(git rev-parse --short HEAD)
HD=$(git -C "$DECOMP_REPO" rev-parse HEAD)
DIRTY=$(git status --porcelain | grep -v '^?? ')
[ -z "$DIRTY" ] || { echo "$DIRTY"; [ "${ALLOW_DIRTY:-0}" = 1 ] || die "realcomp worktree dirty (ALLOW_DIRTY=1 to override; the build id would read -dirty)"; }
# the exe carries FUTARI_BUILD_ID as a string literal (build_win_dll.sh BUILD_ID = short sha [+ -dirty]); it must be HEAD, clean
if grep -a -q "$HRS-dirty" build/futari_combined.exe; then BID="$HRS-dirty"; elif grep -a -q "$HRS" build/futari_combined.exe; then BID="$HRS"; else BID=""; fi
log "exe build id: ${BID:-NOT HEAD}  HEAD: $HRS  decomp: ${HD:0:12}"
case "$BID" in "$HRS") ;; "$HRS-dirty") [ "${ALLOW_DIRTY:-0}" = 1 ] || die "exe stamped -dirty: commit, rebuild";; *) [ "${ALLOW_DIRTY:-0}" = 1 ] || die "exe does not carry HEAD's build id ($HRS): rebuild";; esac
TAGV="v$VER"; TAGC=$(git rev-list -n1 "$TAGV" 2>/dev/null || echo none)
TU_SH=$(ls "$DECOMP_REPO"/decomp/shell/*.cpp | wc -l | tr -d ' '); TU_G=$(ls "$DECOMP_REPO"/decomp/game/*.cpp | wc -l | tr -d ' '); TU_A=$(ls "$DECOMP_REPO"/decomp/game_abn/*.cpp 2>/dev/null | wc -l | tr -d ' ')

# ---- layout
rm -rf "$RD"; mkdir -p "$ST/docs" "$ST/shell" "$ST/logs"
cp build/futari_combined.exe build/futari_game_normal.dll build/futari_game_abn.dll "$ST/"
# the launcher ships CRLF whatever the checkout has (git autocrlf vs tool-written LF): cmd.exe parses LF-only .bat files with known quirks
tr -d '' < "dist/next_release/Futari 1.5.bat" | sed 's/$//' > "$ST/Futari 1.5.bat"
cp shell/default.xex "$ST/shell/"
cp -r save_freshcard "$ST/save_freshcard"
cp docs/RC_KNOWN_ISSUES.md docs/RC1_HANDS_CHECKLIST.md "$ST/docs/"
log "copying assets (1.1 GB) ..."; cp -r assets "$ST/assets"

# ---- README: the Mac RC text, Windows-adapted (dist/next_release/README.txt is the asset-free public form -- not this)
cat > "$ST/README.txt" <<EOF
Mushihimesama Futari Ver 1.5 -- futari_realcomp, native Windows build $VER (RELEASE CANDIDATE, family-and-friends).
Release candidate, not a final release. Engine build id: $BID

REQUIREMENTS
  64-bit Windows 10/11 with a Vulkan 1.1+ GPU driver (any current NVIDIA / AMD / Intel driver). No installer.

MODES
  Both Ver 1.5 modes are in this build: ARCADE (1.5 Original) and XBOX 360 MODE. Pick one at the in-game title
  select; going back to the top menu and picking the other switches live, no relaunch. Ver 1.01 and Black Label
  stay greyed (not included).

RUN
  Double-click "Futari 1.5.bat". It writes the session log to logs\ and the save to save\ (created from
  save_freshcard\ on first run). Quit with the window's close button or the game's own exit.
  This folder already contains the game data (assets\) -- it is for people who own the game. Do not pass it on.

CONTROLS
  Keyboard: arrows = D-pad, Z = A (shot), X = B (bomb), C = X, V = Y, Enter = START, Right Shift = BACK,
  F11 = fullscreen on/off. The game window must have focus.
  Controllers: XInput pads (Xbox-style). A second pad is PLAYER 2: press START on it at the character select,
  or pick 2P SIDE START. Button remapping, screen rotation (TATE), layout, picture and sound settings are the
  game's own OPTIONS menus and persist in the save.

$(cat docs/RC_KNOWN_ISSUES.md | sed 's/macOS/this build/g')

SAVES AND LOGS
  Saves:  save\      (next to the .bat; back this up to keep settings + scores)
  Logs:   logs\      (one file per session)

BUG REPORTS
  Attach the newest log file, say which mode (ARCADE or XBOX 360), keyboard or pad, and what you were doing.

BUILD (docs/PLAN_RC1.md section 6; Windows twin of the macOS $VER cut)
  Version:            $VER (Windows)
  Built:              $(date '+%Y-%m-%d %H:%M %Z')
  futari_realcomp:    $HR   (tag $TAGV @ ${TAGC:0:12})
  futari_decomp:      $HD
  Decomp TUs:         shell $TU_SH, game/ARCADE $TU_G, game_abn/360 $TU_A source TUs in the sibling tree at build time
  Engine:             combined host exe (shell + kernel + renderer + bridge) + 2 module DLLs, Win32 window + XInput,
                      SDL3 audio sink (static), Vulkan via the system loader. Launch environment: see "Futari 1.5.bat".
EOF
cp "$ST/README.txt" "$RD/README.txt"

# ---- hashes + build block
( cd "$ST" && md5sum futari_combined.exe futari_game_normal.dll futari_game_abn.dll "Futari 1.5.bat" shell/default.xex ) > "$ST/MD5.txt"
{ echo "version=$VER platform=windows"; echo "realcomp=$HR"; echo "decomp=$HD"; echo "exe_build_id=$BID"; echo "tag=$TAGV@$TAGC"; echo "staged=$(date -Iseconds)"; } > "$ST/BUILD.txt"
cp "$ST/MD5.txt" "$RD/MD5.txt"; cp "$ST/BUILD.txt" "$RD/BUILD.txt"
cat "$ST/MD5.txt"

# ---- zip (7-Zip if present, else PowerShell)
ZIP="$RC/$NAME.zip"; rm -f "$ZIP"
if [ -x "/c/Program Files/7-Zip/7z.exe" ]; then
  ( cd "$RD" && "/c/Program Files/7-Zip/7z.exe" a -tzip -mx=1 -bso0 -bsp0 "$ZIP" "$NAME" ) || die "7z failed"
else
  powershell -NoProfile -Command "Compress-Archive -Path '$(cygpath -w "$ST")' -DestinationPath '$(cygpath -w "$ZIP")' -CompressionLevel Fastest" || die "Compress-Archive failed"
fi
sha256sum "$ZIP" | tee "$ZIP.sha256"; md5sum "$ZIP" | tee "$ZIP.md5"
log "staged folder: $ST"; log "zip: $ZIP ($(du -h "$ZIP" | cut -f1))"
echo; echo "F&F only (contains game data). Smoke: bash scripts/rc_smoke_win.sh \"$ST\""
