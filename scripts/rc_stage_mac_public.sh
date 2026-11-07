#!/bin/bash
# rc_stage_mac_public.sh <version>  -- stage the PUBLIC (asset-free) macOS release folder + zip: the macOS twin of
# scripts/rc_stage_win_public.sh (the GitHub-release form). Run ON THE MAC, from the futari_realcomp checkout, AFTER rc_cut_mac.sh <version>
# has cut and gated the bundle (~/Desktop/projects/_rc/<version>/Futari Realcomp.app, SMOKE.md ALL-PASS). Nothing is rebuilt: the public
# bundle is a COPY of the gated one with the game data taken out --
#   * Contents/Resources/assets (the player's dump) removed; the in-bundle README replaced by the public one;
#   * the bundle re-sealed ad hoc (outer seal only: codesign --force --sign -  WITHOUT --deep), so the engine futari_merged, every module
#     dylib and both Frameworks stay BYTE-IDENTICAL to the gated bundle -- checked here against _rc/<version>/MACHO_MD5.txt. Only the
#     launcher's signature blob + _CodeSignature/CodeResources change (the seal covers the resources, and the resources changed);
#   * the gated bundle under _rc/<version>/ and its F&F zip are never touched (read-only input).
# Beside the .app, in the release folder: the extractor (tools/extract/futari_extract.py + manifest + extract_assets.sh) with a
# double-clickable "Extract Game Data.command" that builds assets/ NEXT TO the .app from the tester's own dump -- the launcher's existing
# beside-the-app fallback (mac-build/launcher.c) picks it up, and until then the launcher's own "No game data found" dialog says so.
# (A first-run wizard INSIDE the launcher would be a launcher.c change = a new rc; this form changes no code in the cut bundle.)
#
#   bash scripts/rc_stage_mac_public.sh 0.3.0-rc4
#
# Output: ../_rc/<version>-mac-public/Futari-Realcomp-macOS-v<version>/   (one folder inside the zip)
#         ../_rc/Futari-Realcomp-macOS-v<version>-public.zip  (+ .sha256 / .md5)   BUILD.txt + MD5.txt inside the folder.
# Refuses: no gated bundle / SMOKE.md not ALL-PASS / Mach-Os differing from MACHO_MD5.txt / tag v<version> missing or not stamped into the
# engine / dirty worktree (untracked files ignored; ALLOW_DIRTY=1 overrides) / a re-seal that does not verify, and -- after staging -- ANY
# game-data-shaped path in the output tree (assets/, shell/, media/, *.xex, *.xgs/.xwb/.xsb/.xma/.bin/.lzx/.bl, every manifest basename).
# Then: bash scripts/rc_smoke_mac_public.sh <zip> <dump>  (unzip fresh -> extractor -> manifest 58/58 -> app_smoke_mac.sh boot).
set -u
cd "$(dirname "$0")/.."
REPO="$PWD"; PROJ="$(cd .. && pwd)"
VER="${1:?usage: rc_stage_mac_public.sh <version>}"
DECOMP_REPO="${DECOMP_REPO:-$PROJ/futari_decomp}"
RC="$PROJ/_rc"; SRC_RD="$RC/$VER"; SRC_APP="$SRC_RD/Futari Realcomp.app"
RD="$RC/$VER-mac-public"; NAME="Futari-Realcomp-macOS-v$VER"; ST="$RD/$NAME"; APP="$ST/Futari Realcomp.app"
die(){ echo "[stage-mac-public] STOP: $*" >&2; exit 1; }
log(){ echo "[stage-mac-public] $*"; }
[ "$(uname)" = Darwin ] || die "run this on the Mac (codesign / ditto / md5)"

# ---- preflight: the gated bundle, its smoke verdict, its Mach-O hashes
[ -x "$SRC_APP/Contents/MacOS/futari_merged" ] || die "no gated bundle at $SRC_APP (run rc_cut_mac.sh $VER first)"
[ -f "$SRC_RD/SMOKE.md" ] || die "no $SRC_RD/SMOKE.md"
grep -q "ENGINE FAILED STEPS: none" "$SRC_RD/SMOKE.md" && ! grep -q '\*\*FAIL\*\*' "$SRC_RD/SMOKE.md" || die "$SRC_RD/SMOKE.md is not ALL-PASS"
[ -f "$SRC_RD/MACHO_MD5.txt" ] || die "no $SRC_RD/MACHO_MD5.txt"
codesign --verify --deep --strict "$SRC_APP" 2>/dev/null || die "the gated bundle's signature does not verify"
( cd "$SRC_APP" && while read -r h f; do [ "$(md5 -q "$f")" = "$h" ] || { echo "$f: $(md5 -q "$f") != $h"; exit 1; }; done < "$SRC_RD/MACHO_MD5.txt" ) || die "gated bundle Mach-Os differ from MACHO_MD5.txt"
[ -d "$SRC_APP/Contents/Resources/assets" ] || die "the gated bundle has no Contents/Resources/assets (already stripped?)"
for f in tools/extract/futari_extract.py tools/extract/extract_assets.sh tools/extract/manifest_v1.tsv docs/DUMPING.md docs/RC_KNOWN_ISSUES.md docs/RC1_HANDS_CHECKLIST.md docs/SWITCHING_FROM_FUTARI_RECOMP.md tools/settings/futari_settings.py tools/settings/futari.ini.template; do
  [ -e "$f" ] || die "missing $f"; done
HR=$(git rev-parse HEAD); HRS=$(git rev-parse --short HEAD)
DIRTY=$(git status --porcelain | grep -v '^?? ')
[ -z "$DIRTY" ] || { echo "$DIRTY"; [ "${ALLOW_DIRTY:-0}" = 1 ] || die "realcomp worktree dirty (ALLOW_DIRTY=1 to override)"; }
TAGV="v$VER"; TAGC=$(git rev-list -n1 "$TAGV" 2>/dev/null) || die "no tag $TAGV in this checkout (the cut pushes it; git fetch --tags)"
TAGS=$(git rev-parse --short "$TAGC")
grep -a -q "$TAGS" "$SRC_APP/Contents/MacOS/futari_merged" || die "the gated engine does not carry the build id of tag $TAGV ($TAGS)"
if [ "$TAGC" != "$HR" ]; then
  # nothing is rebuilt here, so HEAD may sit above the tag; the engine bytes are proven to be the gated ones below (MACHO_MD5.txt)
  git merge-base --is-ancestor "$TAGC" HEAD 2>/dev/null || die "tag $TAGV ($TAGS) is not an ancestor of HEAD $HRS"
  NONDOC=$(git diff --name-only "$TAGC" HEAD | grep -v -E '^(docs/|scripts/|dist/|tools/extract/|tools/settings/|STATUS\.md$|README\.md$)' | tr '\n' ' ')
  log "HEAD $HRS is above tag $TAGV ($TAGS): tree recorded as-is, engine commit = the tag${NONDOC:+ (sources touched since the tag, NOT in these bytes: $NONDOC)}"
fi
ENGINE_COMMIT="$TAGS"
HD=$(git -C "$DECOMP_REPO" rev-list -n1 "realcomp-$TAGV" 2>/dev/null || git -C "$DECOMP_REPO" rev-parse HEAD 2>/dev/null || echo unknown)
SMOKE_HD=$(grep -o 'futari_decomp `[0-9a-f]*`' "$SRC_RD/SMOKE.md" | head -1 | grep -o '[0-9a-f]\{40\}')
[ -z "$SMOKE_HD" ] || [ "$SMOKE_HD" = "$HD" ] || log "WARNING: decomp tag realcomp-$TAGV ($HD) != the decomp hash the cut recorded ($SMOKE_HD); recording the cut's"
[ -n "$SMOKE_HD" ] && HD="$SMOKE_HD"
NMOD=$(ls "$SRC_APP/Contents/MacOS"/futari_game_*.dylib | wc -l | tr -d ' ')
BL_FILES=""; [ -f "$SRC_APP/Contents/MacOS/futari_game_kiniro.dylib" ] && BL_FILES="$BL_FILES"$'\n'"    futari_game_kiniro.dylib     Black Label ARCADE module (grey in the menu until your Black Label DLC data is found)"
[ -f "$SRC_APP/Contents/MacOS/futari_game_kiniro_abn.dylib" ] && BL_FILES="$BL_FILES"$'\n'"    futari_game_kiniro_abn.dylib Black Label XBOX 360 mode module (same DLC gate)"
log "gated bundle: $SRC_APP ($(du -sh "$SRC_APP" | cut -f1)); engine commit $ENGINE_COMMIT (tag $TAGV); HEAD $HRS; decomp ${HD:0:12}; $NMOD module dylibs"

# ---- layout: a copy of the gated bundle minus the game data, plus the extractor + docs
rm -rf "$RD"; mkdir -p "$ST/docs" "$ST/tools/extract"
ditto "$SRC_APP" "$APP" || die "ditto of the bundle failed"
rm -rf "$APP/Contents/Resources/assets"
cp tools/extract/futari_extract.py tools/extract/manifest_v1.tsv tools/extract/extract_assets.sh "$ST/tools/extract/"
chmod +x "$ST/tools/extract/extract_assets.sh"
cp docs/DUMPING.md docs/RC_KNOWN_ISSUES.md docs/RC1_HANDS_CHECKLIST.md docs/SWITCHING_FROM_FUTARI_RECOMP.md "$ST/docs/"
# futari.ini (2026-11-07): the settings tool + template beside the app; the launcher keeps the live file in
# ~/Library/Application Support/Futari Realcomp/futari.ini (created from the bundle's own copy of the template)
mkdir -p "$ST/tools/settings"; cp tools/settings/futari_settings.py tools/settings/futari.ini.template "$ST/tools/settings/"
cat > "$ST/Settings.command" <<'EOC'
#!/bin/bash
# Double-click me: edits ~/Library/Application Support/Futari Realcomp/futari.ini (window size, fullscreen, vsync,
# rotation, keyboard, save folder). Needs Python 3.8+; without it, open that file in TextEdit -- every key is explained.
cd "$(dirname "$0")" || exit 1
PY=""; for c in python3 /opt/homebrew/bin/python3 /usr/local/bin/python3 /usr/bin/python3; do command -v "$c" >/dev/null 2>&1 && { PY="$c"; break; }; done
INI="$HOME/Library/Application Support/Futari Realcomp/futari.ini"
if [ -z "$PY" ]; then mkdir -p "$(dirname "$INI")"; [ -f "$INI" ] || cp tools/settings/futari.ini.template "$INI"; open -e "$INI"; exit 0; fi
"$PY" tools/settings/futari_settings.py "$@"
echo; echo "The new settings apply the next time you start Futari Realcomp."
EOC
chmod +x "$ST/Settings.command"
cat > "$ST/Extract Game Data.command" <<'EOC'
#!/bin/bash
# Double-click me (Finder opens a Terminal window): builds assets/ next to "Futari Realcomp.app" from YOUR dump of
# Mushihimesama Futari Ver 1.5. Thin wrapper around tools/extract/extract_assets.sh (which wraps futari_extract.py).
# Blocked by Gatekeeper after a download? Right-click > Open, or in Terminal:  xattr -dr com.apple.quarantine "<this folder>"
cd "$(dirname "$0")" || exit 1
exec bash "tools/extract/extract_assets.sh" "$@"
EOC
chmod +x "$ST/Extract Game Data.command"

# ---- README (the public Windows README's shape with the Mac bundle's own sections; also replaces the in-bundle F&F README).
# The Black Label paragraph is built as a variable: a here-document inside a command substitution inside the README here-document
# does not parse on macOS bash 3.2 (mac-build/build_mac_app.sh learned that on the rc3 dry run).
BL_TEXT=""
if [ -n "$BL_FILES" ]; then
BL_TEXT="
BLACK LABEL (your own DLC)
  This build also contains the Black Label engine (ARCADE and XBOX 360 MODE). The row stays greyed until the game
  finds YOUR Black Label download content; no DLC data is included. \"Extract Game Data.command\" offers to take it
  right after the disc (point it at the folder holding your 496F816D... DLC package, or the console folder above it)
  and unpacks the three files it needs into assets/media/Rom/. Black Label has had far less testing than Ver 1.5.
"
fi
cat > "$ST/README.txt" <<EOR
Mushihimesama Futari Ver 1.5 -- futari_realcomp, native macOS build $VER (RELEASE CANDIDATE, test build).
Release candidate, not a final release. Engine build id: $ENGINE_COMMIT

THIS PACKAGE SHIPS NO GAME DATA
  You supply your own copy of the game. Before the first launch, double-click "Extract Game Data.command" (next to
  the app): it asks for either the game folder copied off your own console's storage (the "435A07D7" folder) or your
  disc ISO, and builds assets/ next to the app from it, verified against the console's own integrity hashes and a
  reference manifest (58 files). The one-time extraction needs Python 3.10 or newer
  (https://www.python.org/downloads/macos/ or "brew install python"). Full dumping instructions: docs/DUMPING.md.
  From Terminal instead:  bash "tools/extract/extract_assets.sh" /path/to/your/dump
  Until assets/ exists next to the app, the app only shows "No game data found".

REQUIREMENTS
  Apple silicon Mac (M1 or later) running macOS 13 Ventura or newer. No Intel build. Python 3.10+ for the extraction only.

FIRST LAUNCH ON A NEW MAC
  The app and the .command are self-signed, so macOS will refuse them once. Either run this in Terminal (replace
  the path with wherever you unzipped this folder) -- it covers the app and the extractor in one go:
      xattr -dr com.apple.quarantine "/path/to/$NAME"
  or open each, dismiss the warning, then System Settings > Privacy & Security > scroll down > "Open Anyway".
  (On macOS 13 and 14, right-click > Open also works.)
  On the first launch macOS may also ask whether the app may access the folder you unzipped to (Downloads, Desktop or
  Documents): click Allow -- that is how it reads assets/ next to itself. Until you answer, the window stays blank.

MODES
  Both Ver 1.5 modes are in this build: ARCADE (1.5 Original) and XBOX 360 MODE. Pick one at the in-game title
  select; going back to the top menu and picking the other switches live, no relaunch. Ver 1.01 stays greyed.
${BL_TEXT}

RUN
  Double-click "Futari Realcomp.app" (keep it next to assets/). Quit with Cmd-Q, the window's close button, or B / Esc
  on the title screen. Saves and the session log land under your home folder (below), nothing is written into this
  folder after the extraction.

CONTROLS
  Keyboard: arrows = D-pad, Z = A (shot), X = B (bomb), C = X, V = Y, Enter = START, Right Shift = BACK,
  F11 = fullscreen on/off. The game window must have focus.
  Controllers: anything SDL3 knows (PlayStation / Xbox / Switch pads, USB or Bluetooth). A second pad is
  PLAYER 2: press START on it at the character select, or pick 2P SIDE START.
  Button remapping, screen rotation (TATE), layout, picture and sound settings are the game's own
  OPTIONS menus and persist in the save.

$(cat docs/RC_KNOWN_ISSUES.md)

SETTINGS
  ~/Library/Application Support/Futari Realcomp/futari.ini: window size, fullscreen, vsync, rotation, keyboard, save
  folder. Double-click "Settings.command" or edit the file; every key is explained inside. Coming from futari_recomp:
  point "Extract Game Data.command" at the folder holding its Futari-*.app (game data, DLC and save come over);
  docs/SWITCHING_FROM_FUTARI_RECOMP.md has the details.

SAVES AND LOGS
  Saves:  ~/Library/Application Support/Futari Realcomp/save    (back this up to keep settings + scores)
  Logs:   ~/Library/Logs/Futari Realcomp/                        (one file per session)

BUG REPORTS
  https://github.com/springah/futari_realcomp/issues -- attach the newest log file, say which mode (ARCADE or
  XBOX 360), keyboard or pad, and what you were doing. docs/RC1_HANDS_CHECKLIST.md is the test checklist.

FILES
  Futari Realcomp.app          the game (both modes); inside Contents/MacOS:
    futari_merged                the engine
    futari_game_normal.dylib     ARCADE 1.5 module
    futari_game_abn.dylib        XBOX 360 mode module$BL_FILES
  Extract Game Data.command    first-run extraction (double-click)
  Settings.command             window size, fullscreen, vsync, rotation, keyboard, save folder (writes futari.ini)
  tools/extract/               the asset extractor + reference manifest (+ extract_assets.sh, the Terminal form)
  tools/settings/              the settings tool + the futari.ini template
  docs/                        DUMPING.md, RC_KNOWN_ISSUES.md, RC1_HANDS_CHECKLIST.md, SWITCHING_FROM_FUTARI_RECOMP.md
  assets/                      built by the extractor from YOUR dump (not shipped)

BUILD (docs/PLAN_RC1.md section 6; public form of the macOS $VER cut: the gated bundle minus its game data)
  Version:            $VER (macOS, asset-free)
  Staged:             $(date '+%Y-%m-%d %H:%M %Z')
  futari_realcomp:    $HR   (tree at staging; engine built at $ENGINE_COMMIT = tag $TAGV @ ${TAGC:0:12})
  futari_decomp:      $HD   (tag realcomp-$TAGV)
  Engine:             the $VER cut's own futari_merged + $NMOD module dylibs + Frameworks, byte-identical to the gated bundle
                      (rc_cut_mac.sh smoke ALL-PASS); bundle re-sealed ad hoc after the game data was removed. macOS 13.0
                      minimum, MoltenVK/SDL3 bundled. Launcher environment: mac-build/launcher.c.
EOR
cp "$ST/README.txt" "$APP/Contents/Resources/README.txt"; cp "$ST/README.txt" "$RD/README.txt"

# ---- re-seal (outer only) + prove the engine bytes are the gated ones
LAUNCHER_MD5_BEFORE=$(md5 -q "$APP/Contents/MacOS/Futari Realcomp")
codesign --force --sign - "$APP" 2>"$RD/codesign.txt" || { cat "$RD/codesign.txt"; die "re-seal failed"; }
codesign --verify --deep --strict "$APP" 2>>"$RD/codesign.txt" || { cat "$RD/codesign.txt"; die "re-sealed bundle does not verify"; }
MACHO_DIFF=""
while read -r h f; do
  case "$f" in "./Contents/MacOS/Futari Realcomp") continue;; esac
  [ "$(cd "$APP" && md5 -q "$f")" = "$h" ] || MACHO_DIFF="$MACHO_DIFF $f"
done < "$SRC_RD/MACHO_MD5.txt"
[ -z "$MACHO_DIFF" ] || die "engine/module/framework bytes changed by the re-seal:$MACHO_DIFF"
LAUNCHER_MD5_AFTER=$(md5 -q "$APP/Contents/MacOS/Futari Realcomp")
( cd "$APP" && find . -type f \( -perm -u+x -o -name '*.dylib' \) | sort | while read -r f; do file "$f" | grep -q Mach-O && echo "$(md5 -q "$f")  $f"; done ) > "$RD/MACHO_MD5.txt"
log "re-sealed: signature verifies; engine + $NMOD module dylibs + Frameworks byte-identical to $SRC_RD/MACHO_MD5.txt; launcher $LAUNCHER_MD5_BEFORE -> $LAUNCHER_MD5_AFTER (signature blob only)"

# ---- hashes + build block
( cd "$ST" && md5 -r "Futari Realcomp.app/Contents/MacOS/futari_merged" "Futari Realcomp.app/Contents/MacOS/"futari_game_*.dylib "Futari Realcomp.app/Contents/MacOS/Futari Realcomp" \
  "Futari Realcomp.app/Contents/Frameworks/"*.dylib "Extract Game Data.command" tools/extract/extract_assets.sh tools/extract/futari_extract.py tools/extract/manifest_v1.tsv "Settings.command" tools/settings/futari_settings.py tools/settings/futari.ini.template ) > "$ST/MD5.txt"
{ echo "version=$VER platform=macos form=public-asset-free"; echo "realcomp=$HR"; echo "engine_commit=$ENGINE_COMMIT"; echo "decomp=$HD"; echo "tag=$TAGV@$TAGC"
  echo "gated_bundle=$SRC_APP"; echo "gated_smoke=ALL-PASS ($SRC_RD/SMOKE.md)"; echo "engine_bytes=identical-to-gated (MACHO_MD5.txt, launcher re-signed $LAUNCHER_MD5_BEFORE->$LAUNCHER_MD5_AFTER)"
  echo "staged=$(date -Iseconds 2>/dev/null || date '+%Y-%m-%dT%H:%M:%S%z')"; } > "$ST/BUILD.txt"
cp "$ST/MD5.txt" "$RD/MD5.txt"; cp "$ST/BUILD.txt" "$RD/BUILD.txt"
cat "$ST/MD5.txt"

# ---- GAME-DATA SCAN: refuse to zip if anything disc-shaped is in the tree
BAD=$(cd "$RD" && find . \( -iname '*.xex' -o -iname 'media' -o -iname 'assets' -o -iname 'shell' -o -iname 'Rom' -o -iname '*.xgs' -o -iname '*.xwb' -o -iname '*.xsb' \
      -o -iname '*.xma' -o -iname '*.bin' -o -iname '*.lzx' -o -iname '*.bl' -o -iname 'nxeart' -o -iname 'AvatarAssetPack' -o -iname '$SystemUpdate' \) -print)
[ -z "$BAD" ] || { echo "$BAD"; die "game-data-shaped paths in the public tree"; }
MANI_HIT=""
while IFS=$'\t' read -r p _s _h; do case "$p" in \#*|path|"") continue;; esac; b=$(basename "$p")
  [ -z "$(cd "$RD" && find . -name "$b" -print)" ] || MANI_HIT="$MANI_HIT $p"; done < tools/extract/manifest_v1.tsv
[ -z "$MANI_HIT" ] || { echo "$MANI_HIT"; die "manifest file names present in the public tree"; }
BIG=$(cd "$RD" && find . -type f -size +60M ! -name futari_merged ! -name 'futari_game_*.dylib' -print)
[ -z "$BIG" ] || { echo "$BIG"; die "unexpected large files in the public tree"; }
NMANI=$(grep -c -v -E '^(#|path\b|$)' tools/extract/manifest_v1.tsv)
log "game-data scan: clean ($(find "$ST" -type f | wc -l | tr -d ' ') files, $(du -sh "$ST" | cut -f1); none of the $NMANI manifest names, no assets/shell/media, no .xex/.xgs/.xwb/.xsb/.bin/.lzx)"

# ---- zip (ditto keeps the xattrs + the seal; --norsrc would break it)
ZIP="$RC/$NAME-public.zip"; rm -f "$ZIP"
ditto -c -k --keepParent "$ST" "$ZIP" || die "ditto zip failed"
( cd "$RC" && shasum -a 256 "$(basename "$ZIP")" | tee "$(basename "$ZIP").sha256" && md5 -r "$(basename "$ZIP")" > "$(basename "$ZIP").md5" )
log "staged folder: $ST"; log "zip: $ZIP ($(du -h "$ZIP" | cut -f1))"
echo; echo "PUBLIC form (no game data). Smoke it: bash scripts/rc_smoke_mac_public.sh \"$ZIP\" \"$SRC_APP/Contents/Resources/assets\""
