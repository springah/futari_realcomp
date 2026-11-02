#!/bin/bash
# rc_smoke_mac_public.sh <public zip> <dump>  -- WIZARD + BOOT SMOKE of a public (asset-free) macOS zip: the Mac twin of the Windows
# wizard smoke (rc_stage_win_public.sh's closing hint + rc_smoke_win.sh). Run ON THE MAC from the futari_realcomp checkout.
#   1 unzip     the zip into a FRESH folder under _local/rc/pubsmoke_mac_<ts>/ (ditto -x -k, xattrs kept)
#   2 seal      codesign --verify --deep --strict on the unzipped .app
#   3 nodata    no game-data-shaped path anywhere in the unzipped folder (assets/ shell/ media/ *.xex *.xwb *.xgs *.xsb *.lzx *.bin)
#   4 extract   the SHIPPED extractor exactly as a tester would from Terminal: tools/extract/extract_assets.sh <dump> (no dialogs) ->
#               assets/ next to the .app; PASS = exit 0 + "matches the reference manifest" + every manifest row present (N/N)
#   5 app_smoke scripts/app_smoke_mac.sh on the unzipped .app (LaunchServices launch, pad FIFO drive title -> top menu -> card -> ARCADE
#               -> hub -> back, Quit, relaunch): all module dylibs bound (N/N), 0 FATAL, save written + read back
#   6 log       the first session's log: build id names a commit, 0 VK_ERROR, 0 MoltenVK/Metal error lines, game root = the beside-the-app assets/
# Writes SMOKE.md into the work folder AND next to the zip as <zip>.SMOKE.md (the record the release notes cite). The zip, the gated bundle and
# everything else under _rc/ are read-only here. The <dump> for a seat smoke is the gated bundle's own Contents/Resources/assets (an
# already-extracted disc folder, DLC files included), which is what the Windows wizard smoke fed its extractor too.
# Refuses to launch while any other futari_merged runs (the drive lock discipline of rc_cut_mac.sh); kills nothing but a stale engine of THIS .app.
set -u
ZIP="${1:?usage: rc_smoke_mac_public.sh <public zip> <dump path>}"; DUMP="${2:?usage: rc_smoke_mac_public.sh <public zip> <dump path>}"
cd "$(dirname "$0")/.."
[ -f "$ZIP" ] || { echo "no zip $ZIP"; exit 2; }; [ -e "$DUMP" ] || { echo "no dump $DUMP"; exit 2; }
ZIP="$(cd "$(dirname "$ZIP")" && pwd)/$(basename "$ZIP")"
TS=$(date +%Y%m%d_%H%M%S); W="$PWD/_local/rc/pubsmoke_mac_$TS"; mkdir -p "$W"; SM="$W/SMOKE.md"
say(){ echo "[pubsmoke] $(date +%H:%M:%S) $*"; }; FAIL=0; ROWS=""
row(){ ROWS="$ROWS| $1 | **$2** | $(( $(date +%s) - T0 )) | ${3//|/\/} |"$'\n'; say "$2 $1: $3"; [ "$2" = PASS ] || FAIL=1; T0=$(date +%s); }
T0=$(date +%s); STARTED="$(date '+%F %T')"
SHA=$(cut -d' ' -f1 "$ZIP.sha256" 2>/dev/null || shasum -a 256 "$ZIP" | cut -d' ' -f1)

# 1 unzip
ditto -x -k "$ZIP" "$W" 2>"$W/unzip.txt" || row unzip FAIL "ditto -x -k failed: $(tr '\n' ' ' < "$W/unzip.txt")"
F=$(ls -d "$W"/Futari-Realcomp-macOS-v*/ 2>/dev/null | head -1); F="${F%/}"; APP="$F/Futari Realcomp.app"
if [ -x "$APP/Contents/MacOS/Futari Realcomp" ]; then row unzip PASS "$(basename "$F"): $(find "$F" -type f | wc -l | tr -d ' ') files, $(du -sh "$F" | cut -f1)"
else row unzip FAIL "no launcher at $APP"; fi

finish(){
  { echo "# SMOKE -- public (asset-free) macOS zip"; echo
    echo "- started $STARTED; zip \`$ZIP\` ($(du -h "$ZIP" | cut -f1)); sha256 \`$SHA\`"
    echo "- dump fed to the shipped extractor: \`$DUMP\`"; echo "- unzipped to \`$W\` (fresh); .app launched from there with assets/ beside it"
    echo "- scripts: rc_smoke_mac_public.sh -> tools/extract/extract_assets.sh (shipped) + scripts/app_smoke_mac.sh"
    echo; echo "| step | result | secs | detail |"; echo "|---|---|---|---|"; printf '%s' "$ROWS"
    echo; echo "finished $(date '+%F %T'); PUBLIC MAC SMOKE: $([ $FAIL = 0 ] && echo PASS || echo FAIL)"; } > "$SM"
  cp "$SM" "$ZIP.SMOKE.md" 2>/dev/null; echo; cat "$SM"; echo; say "record: $SM (copy: $ZIP.SMOKE.md)"
  [ $FAIL = 0 ] && echo "PUBLIC MAC SMOKE: PASS" || { echo "PUBLIC MAC SMOKE: FAIL"; exit 1; }; }
[ -x "$APP/Contents/MacOS/Futari Realcomp" ] || finish

# 2 seal   3 nodata
codesign --verify --deep --strict "$APP" 2>"$W/codesign.txt" && row seal PASS "codesign --verify --deep --strict OK; $(ls "$APP/Contents/MacOS"/futari_game_*.dylib | wc -l | tr -d ' ') module dylibs" \
  || row seal FAIL "$(tr '\n' ' ' < "$W/codesign.txt")"
GD=$(cd "$F" && find . \( -iname assets -o -iname shell -o -iname media -o -iname '*.xex' -o -iname '*.xwb' -o -iname '*.xgs' -o -iname '*.xsb' -o -iname '*.lzx' -o -iname '*.bin' \) -print)
[ -z "$GD" ] && row nodata PASS "no game-data-shaped path in the unzipped folder" || row nodata FAIL "$(echo "$GD" | tr '\n' ' ')"

# 4 extract (the shipped script, scripted mode = no dialogs)
say "extractor: tools/extract/extract_assets.sh \"$DUMP\" -> $F/assets"
( cd "$F" && bash "tools/extract/extract_assets.sh" "$DUMP" ) > "$W/extract.log" 2>&1; rc=$?
MANI="$F/tools/extract/manifest_v1.tsv"; NM=$(grep -c -v -E '^(#|path\b|$)' "$MANI"); HAVE=0
while IFS=$'\t' read -r p _s _h; do case "$p" in \#*|path|"") continue;; esac; [ -f "$F/assets/$p" ] && HAVE=$((HAVE+1)); done < "$MANI"
if [ $rc = 0 ] && grep -q "matches the reference manifest" "$W/extract.log" && [ "$HAVE" = "$NM" ]; then
  row extract PASS "exit 0; manifest $HAVE/$NM present, sha256-verified by the extractor ($(grep -c '  copied ' "$W/extract.log") files copied); python $(grep -o 'Python:.*' "$W/extract.log" | head -1 | sed 's/Python: *//')"
else row extract FAIL "exit $rc; manifest $HAVE/$NM; $(grep -a -E 'FAILED|MISSING|DO NOT MATCH|ERROR|No such|Traceback' "$W/extract.log" | head -3 | tr '\n' ' ')"; fi
[ -f "$F/assets/default.xex" ] || finish

# 5 app_smoke (refuse while another engine runs: never kill someone else's drive)
OTHER=$(pgrep -x futari_merged 2>/dev/null | tr '\n' ' ')
if [ -n "$OTHER" ]; then row app_smoke FAIL "another futari_merged is running (pids $OTHER); not launching"; finish; fi
LOGS="$HOME/Library/Logs/Futari Realcomp"; PREV=$(ls -t "$LOGS"/futari_*.log 2>/dev/null | head -1)
bash scripts/app_smoke_mac.sh "$APP" > "$W/app_smoke.log" 2>&1; rc=$?
NP=$(grep -a -c '^\[app\] PASS' "$W/app_smoke.log"); NF=$(grep -a -c '^\[app\] FAIL' "$W/app_smoke.log")
MOD=$(grep -a -o -E 'all modules bound \([0-9]+/[0-9]+ module DLL' "$W/app_smoke.log" | head -1 | grep -o -E '[0-9]+/[0-9]+')
if [ $rc = 0 ] && grep -a -q 'APP SMOKE: PASS' "$W/app_smoke.log"; then row app_smoke PASS "APP SMOKE: PASS; $NP PASS lines, 0 FAIL; modules ${MOD:-?}; save written + read back"
else row app_smoke FAIL "exit $rc; $NP PASS / $NF FAIL lines: $(grep -a -E '^\[app\] (FAIL|TIMEOUT)' "$W/app_smoke.log" | head -3 | tr '\n' ' ')"; fi

# 6 the first session's log
LOG1=$(grep -a -o 'first: log .*' "$W/app_smoke.log" | head -1 | sed 's/first: log //')
[ -n "$LOG1" ] && [ -f "$LOG1" ] || LOG1=$(ls -t "$LOGS"/futari_*.log 2>/dev/null | grep -v -F -x "${PREV:-/none}" | head -1)
if [ -n "$LOG1" ] && [ -f "$LOG1" ]; then
  cp "$LOG1" "$W/session1.log"
  BID=$(grep -a -o -m1 "build=[^ ]*" "$LOG1" | head -1); NV=$(grep -a -c "VK_ERROR" "$LOG1"); NMTL=$(grep -a -c -i -E 'mvk-error|MTL[A-Za-z]*Error|Metal.*error' "$LOG1")
  NFAT=$(grep -a -c FATAL "$LOG1"); ROOT_OK=$(grep -a -c -F "$F/assets" "$LOG1"); D=""
  case "$BID" in build=unknown|build=*-dirty|"") D="$D build id ${BID:-missing} FAIL;"; FAIL=1;; *) D="$D $BID;";; esac
  D="$D FATAL x$NFAT; VK_ERROR x$NV; MoltenVK/Metal errors x$NMTL; lines naming the beside-the-app assets/: $ROOT_OK; slowframe x$(grep -a -c '\[slowframe\]' "$LOG1"); $(wc -l < "$LOG1" | tr -d ' ') lines -> $LOG1"
  if [ "$NV" = 0 ] && [ "$NMTL" = 0 ] && [ "$NFAT" = 0 ] && [ "$ROOT_OK" != 0 ] && [ $FAIL = 0 ]; then row log PASS "$D"; else row log FAIL "$D"; fi
else row log FAIL "no session log found under $LOGS"; fi
finish
