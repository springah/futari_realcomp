#!/bin/bash
# upload_gdrive.sh [VER] -- push the beta artefacts to Google Drive with rclone (set up 2026-10-05).
# Remote "gdrive" = springah@gmail.com, scope drive.file (rclone sees ONLY what it uploaded itself; nothing else in the
# Drive is visible to it). Files land in  Futari-Realcomp/<VER>/  with Drive's own md5 check on every transfer.
#   bash scripts/upload_gdrive.sh                 # VER defaults to 0.2.0-beta3; the AppImage from ~/Desktop/projects
#   LINK=1 bash scripts/upload_gdrive.sh          # also print anyone-with-the-link URLs (game data inside: F&F only)
#   FILES="x.zip y.AppImage" bash scripts/upload_gdrive.sh   # explicit list
# One-time setup (opens the browser for the Google sign-in):  rclone config create gdrive drive scope drive.file
# NOTE (rclone 1.75 notice): the remote uses rclone's SHARED Google client_id, which Google retires during 2026. When
# uploads start failing with auth errors, make a personal client_id (https://rclone.org/drive/#making-your-own-client-id)
# and re-create the remote with client_id/client_secret set; the folder and script stay the same.
set -u
VER="${1:-0.2.0-beta3}"; SRC="$HOME/Desktop/projects"; DST="gdrive:Futari-Realcomp/$VER"
FILES="${FILES:-Futari-Realcomp-x86_64.AppImage}"   # user 10-05: only the Deck AppImage goes on Drive (the Mac build is handed over directly)
rclone listremotes | grep -q '^gdrive:' || { echo "no rclone remote 'gdrive' -- run: rclone config create gdrive drive scope drive.file"; exit 1; }
for f in $FILES; do
  [ -f "$SRC/$f" ] || { echo "missing $SRC/$f"; exit 1; }
  echo "== $f ($(du -h "$SRC/$f" | cut -f1)) -> $DST/  $(date +%T)"
  rclone copy "$SRC/$f" "$DST/" --progress --stats-one-line --stats 30s --drive-chunk-size 64M || { echo "UPLOAD FAILED: $f"; exit 1; }
done
echo "== on Drive:"; rclone ls "$DST/"
echo "== local md5 (Drive verified each transfer against its own md5):"; (cd "$SRC" && md5 -r $FILES)
if [ "${LINK:-0}" = "1" ]; then echo "== links (anyone with the link):"; for f in $FILES; do echo "$f  $(rclone link "$DST/$f")"; done; fi
