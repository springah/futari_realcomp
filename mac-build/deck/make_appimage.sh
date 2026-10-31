#!/bin/bash
# make_appimage.sh -- assemble Futari-Realcomp-x86_64.AppImage from the staged Deck folder, inside the build container
# (mksquashfs + the type2 runtime; no FUSE, no appimagetool). Game data inside the image, read-only; saves/logs under
# ~/.local/share/futari-realcomp. squashfs with zstd level 3: the dump is mostly LZX-compressed already, so this is
# about read speed, not size.
#   bash mac-build/deck/make_appimage.sh     (after build_deck.sh staged ~/Desktop/projects/Futari-Realcomp-Deck)
set -eu
cd "$(dirname "$0")/../.."
STAGE="${STAGE:-$HOME/Desktop/projects/Futari-Realcomp-Deck}"; OUT="${OUT:-$HOME/Desktop/projects/Futari-Realcomp-x86_64.AppImage}"
[ -x "$STAGE/futari_combined" ] || { echo "no staged Deck folder at $STAGE (bash mac-build/deck/build_deck.sh)"; exit 2; }
A=build/appdir; rm -rf "$A"; mkdir -p "$A/usr/lib/futari" "$A/usr/share/futari" "$A/usr/share/icons/hicolor/256x256/apps"
cp "$STAGE"/futari_combined "$STAGE"/futari_game_*.so "$A/usr/lib/futari/"   # the Ver 1.5 pair, plus Black Label when staged (2026-10-31)
cp mac-build/deck/AppRun "$A/AppRun"; chmod +x "$A/AppRun"
cp mac-build/deck/futari-realcomp.desktop "$A/"; cp "$STAGE/README.txt" "$A/usr/share/futari/README.txt"
ICNS="$HOME/Desktop/projects/Futari.app/Contents/Resources/AppIcon.icns"
if [ -f "$ICNS" ]; then sips -s format png -z 256 256 "$ICNS" --out "$A/futari-realcomp.png" >/dev/null 2>&1 || true; fi
[ -f "$A/futari-realcomp.png" ] || python3 -c "import zlib,struct;w=h=256;raw=b''.join(b'\x00'+bytes([40,120,80,255])*w for _ in range(h));
def ch(t,d): return struct.pack('>I',len(d))+t+d+struct.pack('>I',zlib.crc32(t+d)&0xffffffff)
open('$A/futari-realcomp.png','wb').write(b'\x89PNG\r\n\x1a\n'+ch(b'IHDR',struct.pack('>IIBBBBB',w,h,8,6,0,0,0))+ch(b'IDAT',zlib.compress(raw))+ch(b'IEND',b''))"
cp "$A/futari-realcomp.png" "$A/usr/share/icons/hicolor/256/apps/futari-realcomp.png" 2>/dev/null || cp "$A/futari-realcomp.png" "$A/usr/share/icons/hicolor/256x256/apps/"
ln -sf futari-realcomp.png "$A/.DirIcon"
echo "   game data -> usr/share/futari/assets (case kept verbatim)"; ditto "$STAGE/assets" "$A/usr/share/futari/assets"
[ -d save_freshcard ] && cp -r save_freshcard "$A/usr/share/futari/save_freshcard"
ROOT="$PWD"
docker run --rm --platform linux/amd64 -v "$ROOT:/work/futari_realcomp" -w /work/futari_realcomp futari-deck-build bash -c '
  set -e; rm -f build/appdir.sqfs
  mksquashfs build/appdir build/appdir.sqfs -root-owned -noappend -comp zstd -Xcompression-level 3 -quiet
  cat /usr/local/lib/appimage-runtime-x86_64 build/appdir.sqfs > build/Futari-Realcomp-x86_64.AppImage
  chmod +x build/Futari-Realcomp-x86_64.AppImage; ls -la build/Futari-Realcomp-x86_64.AppImage
  echo "== headless boot of the AppImage (extract-and-run: no FUSE in the container) =="
  HOME=/tmp FUTARI_HEADLESS=1 APPIMAGE_EXTRACT_AND_RUN=1 timeout -s KILL 60 build/Futari-Realcomp-x86_64.AppImage || true
  L=$(ls -t /tmp/.local/share/futari-realcomp/logs/*.log | head -1); grep -m4 "\[modreg\].*BOUND\|2/2 module\|FATAL\|menu_title.lzx" "$L" | cut -c1-120'
cp build/Futari-Realcomp-x86_64.AppImage "$OUT"; ls -la "$OUT"
