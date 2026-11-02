#!/bin/bash
# ===========================================================================
#  Mushihimesama Futari 1.5 (realcomp) - asset extractor, macOS / Linux twin of extract_assets.bat
#
#  This port ships no game data. Supply your own copy of Mushihimesama Futari
#  Ver 1.5 (Xbox 360, title 435A07D7): either of these, as the one argument or
#  picked in the dialog this script shows when run with none:
#    - the game folder copied off your console's storage (the "435A07D7"
#      folder, or anything above it) - the copy is verified against the
#      console's own integrity hashes first, and your Black Label DLC is
#      unpacked in the same pass
#    - your Xbox 360 disc ISO
#    - a folder where you already extracted the disc
#
#  It builds "assets/" NEXT TO "Futari Realcomp.app" (in the repo: at the repo
#  root) - the tree the app's launcher finds beside itself (mac-build/launcher.c,
#  RT_GAME_ROOT). Everything it writes is checked against manifest_v1.tsv
#  before it reports success. Thin wrapper around futari_extract.py.
#
#  Requires Python 3.10 or newer (https://www.python.org/downloads/macos/).
#  In the public zip, "Extract Game Data.command" at the top of the folder is
#  the double-click entry to this script; with no argument it asks for the dump
#  with Finder dialogs, with an argument it runs without any dialog (scripted
#  use: scripts/rc_smoke_mac_public.sh).
# ===========================================================================
set -u
HERE="$(cd "$(dirname "$0")" && pwd)"
if [ -f "$HERE/futari_extract.py" ]; then EXTRACTOR="$HERE/futari_extract.py"; ROOT="$(cd "$HERE/../.." && pwd)"
elif [ -f "$HERE/tools/extract/futari_extract.py" ]; then EXTRACTOR="$HERE/tools/extract/futari_extract.py"; ROOT="$HERE"
else echo "[ERROR] Could not find futari_extract.py. Keep this script together with the extractor and its manifest."; exit 2; fi
OUT="$ROOT/assets"
GUI=0; [ $# -eq 0 ] && [ "$(uname)" = Darwin ] && GUI=1

say(){ echo "$*"; }
ask(){ # ask <text> <button1> <button2> [default]  -> prints the button pressed; empty = dialog unavailable; "CANCEL" = cancelled
  local out; out=$(osascript -e "button returned of (display dialog \"$1\" with title \"Futari Realcomp - game data\" buttons {\"$2\", \"$3\"} default button \"${4:-$3}\")" 2>&1)
  case "$out" in *-128*) echo CANCEL;; *"execution error"*|*"syntax error"*) echo "";; *) echo "$out";; esac; }

# ---- Python 3.10+ (the extractor uses 3.10 syntax). The Xcode Command Line Tools' /usr/bin/python3 is 3.9 on macOS 13-15.
PY=""
for c in python3 python3.14 python3.13 python3.12 python3.11 python3.10 /opt/homebrew/bin/python3 /usr/local/bin/python3; do
  command -v "$c" >/dev/null 2>&1 || continue
  "$c" -c 'import sys; sys.exit(0 if sys.version_info >= (3, 10) else 1)' >/dev/null 2>&1 && { PY="$c"; break; }
done
if [ -z "$PY" ]; then
  say "[ERROR] Python 3.10 or newer was not found on this Mac."
  say "        Install it from https://www.python.org/downloads/macos/ (or: brew install python), then run this again."
  [ $GUI = 1 ] && ask "Python 3.10 or newer is needed for the one-time extraction and was not found.\n\nInstall it from python.org (https://www.python.org/downloads/macos/) and run this again." "OK" "OK" >/dev/null
  exit 3
fi

# ---- the dump: argument, else Finder dialogs, else a typed/dragged path
SRC="${1:-}"
if [ -z "$SRC" ]; then
  CHOICE=""
  [ $GUI = 1 ] && CHOICE=$(ask "This port ships NO game data. Point it at your own copy of Mushihimesama Futari Ver 1.5 (Xbox 360, title 435A07D7):\n\n  - the 435A07D7 folder copied off your console (or any folder above it)\n  - your disc ISO\n\ndocs/DUMPING.md explains how to copy it off the console." "Disc ISO..." "Console folder...")
  case "$CHOICE" in
    CANCEL) say "Cancelled - nothing extracted."; exit 1;;
    "Console folder...") SRC=$(osascript -e 'POSIX path of (choose folder with prompt "Pick the 435A07D7 folder copied off your console (or the folder above it)")' 2>/dev/null);;
    "Disc ISO...")       SRC=$(osascript -e 'POSIX path of (choose file with prompt "Pick your Mushihimesama Futari Ver 1.5 disc ISO")' 2>/dev/null);;
  esac
  if [ -z "$SRC" ]; then
    [ "$CHOICE" = "Console folder..." ] || [ "$CHOICE" = "Disc ISO..." ] && { say "Cancelled - nothing extracted."; exit 1; }
    printf 'Drag your dump (the 435A07D7 folder or the .iso) into this window, then press Return: '
    IFS= read -r SRC
    SRC="${SRC//\\ / }"; SRC="${SRC#\'}"; SRC="${SRC%\'}"; SRC="${SRC#\"}"; SRC="${SRC%\"}"   # Terminal drag-and-drop escapes spaces
    SRC="${SRC%"${SRC##*[! ]}"}"
  fi
fi
SRC="${SRC%/}"
[ -n "$SRC" ] && [ -e "$SRC" ] || { say "[ERROR] No such path: '$SRC'"; exit 1; }

say ""; say "Extracting from: $SRC"; say "Output:          $OUT"; say "Python:          $PY ($("$PY" -c 'import platform; print(platform.python_version())'))"; say ""
"$PY" "$EXTRACTOR" "$SRC" --out "$OUT"; RC=$?
say ""
if [ $RC != 0 ]; then
  say "[FAILED] Extraction did not complete - see the messages above. Nothing was harmed; fix the input and run this again."
  [ $GUI = 1 ] && ask "Extraction FAILED - see the messages in the Terminal window.\n\nNothing was harmed; fix the input and run Extract Game Data again." "OK" "OK" >/dev/null
  exit $RC
fi
say "[DONE] assets/ matches the reference manifest."

# ---- optional: the Black Label DLC (its three files go into assets/media/Rom/; the Black Label menu row un-greys)
if [ $GUI = 1 ] && [ ! -f "$OUT/media/Rom/cg_black.bin" ]; then
  if [ "$(ask "assets/ is built and verified.\n\nIf you also own the Black Label DLC, point the extractor at it now (the folder or package you copied off the console) - or skip it." "Skip" "Pick DLC...")" = "Pick DLC..." ]; then
    DLC=$(osascript -e 'POSIX path of (choose folder with prompt "Pick the folder holding your Black Label DLC package (00000002, or the folder above it)")' 2>/dev/null)
    [ -n "$DLC" ] && "$PY" "$EXTRACTOR" "${DLC%/}" --out "$OUT"
  fi
fi

# ---- launch
if [ $GUI = 1 ] && [ -d "$ROOT/Futari Realcomp.app" ]; then
  [ "$(ask "Done. assets/ matches the reference manifest.\n\nLaunch Mushihimesama Futari now?" "Not now" "Launch")" = "Launch" ] && open "$ROOT/Futari Realcomp.app"
else
  say "You can now run the game (double-click \"Futari Realcomp.app\" next to assets/)."
fi
exit 0
