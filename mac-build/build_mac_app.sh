#!/bin/bash
# build_mac_app.sh -- assemble a double-clickable "Futari Realcomp.app" from the native macOS build.
#
#   bash mac-build/build_mac_app.sh                 -> ~/Desktop/projects/Futari Realcomp.app (with game data)
#   APP=/path/Out.app SKIP_ASSETS=1 ...             -> verification bundle without game data
#   ASSETS_SRC=/path/to/assets                      -> which extracted dump to ship (default: ./assets)
#   REUSE_OBJ=1                                     -> skip the compile, relink the app object dirs as they are
#   VER=0.2.0-beta3                                 -> the version string (Info.plist + README)
#
# What the bundle is (beta 3, 2026-10-04: TWO MODES): the COMBINED host (build_mac_dll.sh: shell + kernel +
# renderer + bridge, -DFUTARI_COMBINED=1) plus the two per-mode module dylibs (futari_game_normal.dylib =
# ARCADE 1.5, futari_game_abn.dylib = XBOX 360 mode) beside it in Contents/MacOS, where
# host/module_registry.cpp's dlopen arm finds them by the executable's own directory; SDL3 and MoltenVK
# copied into Contents/Frameworks with the load commands rewritten to @rpath / @executable_path so nothing
# points at Homebrew or this checkout; a tiny exec-launcher (mac-build/launcher.c) as CFBundleExecutable that
# sets scripts/run_mac.sh's environment and the bundle-relative paths; and the user's extracted assets/ under
# Contents/Resources/assets. Saves land in ~/Library/Application Support/Futari Realcomp/save, the guest
# log in ~/Library/Logs/Futari Realcomp/. Everything in it is built with MACOSX_DEPLOYMENT_TARGET=13.0 (the
# beta-2 bundle was built against the host SDK alone and would only launch on macOS 27).
#
# The engine inside is linked WITHOUT libavcodec (FFM disabled): the shipping audio path is guest-native
# (docs/PLAN_macos_bringup.md, "Sound was never a decoder problem"); libavcodec only served the bridge/A-B
# arms (RT_BRIDGESE=1, RT_XWMATEST), and bundling Homebrew ffmpeg's dependency tree is not worth it.
#
# THIS BUNDLE CONTAINS YOUR GAME DATA (family-and-friends build, same rule as futari_recomp's local
# Futari.app): it is for your own machines and people who own the game. It is ad-hoc signed, so on another
# Mac it must be opened with right-click > Open once (or `xattr -dr com.apple.quarantine`).
set -euo pipefail
cd "$(dirname "$0")/.."
APP="${APP:-$HOME/Desktop/projects/Futari Realcomp.app}"
ASSETS_SRC="${ASSETS_SRC:-$PWD/assets}"
VER="${VER:-0.2.0-beta3}"
export MACOSX_DEPLOYMENT_TARGET="${MACOSX_DEPLOYMENT_TARGET:-13.0}"
C="$APP/Contents"
BREW="$(brew --prefix 2>/dev/null || echo /opt/homebrew)"
CXX="${CXX:-$BREW/opt/llvm/bin/clang++}"; [ -x "$CXX" ] || CXX=clang++
INT="$BREW/opt/llvm/bin/llvm-install-name-tool"; [ -x "$INT" ] || INT=install_name_tool

echo "[1/8] engine: combined host + 2 module dylibs (self-contained link: no libavcodec, SDL told to dlopen the bundled MoltenVK)"
# build_mac_dll.sh with OUTDIR=build/app OBJSFX=_app: the bundle's engine (MoltenVK path @executable_path-relative, no
# libavcodec) lives apart from the drive/gate binaries under build/, which keep running from the checkout.
if [ "${REUSE_OBJ:-0}" = "1" ] && [ -d build/obj_mac_host_app ]; then
  FFM=/nonexistent MVK_LOADPATH="@executable_path/../Frameworks/libMoltenVK.dylib" OUTDIR=build/app OBJSFX=_app LINK_ONLY=1 bash build_mac_dll.sh > build/app_build.log 2>&1 || { tail -30 build/app_build.log; exit 1; }
else
  FFM=/nonexistent MVK_LOADPATH="@executable_path/../Frameworks/libMoltenVK.dylib" OUTDIR=build/app OBJSFX=_app bash build_mac_dll.sh > build/app_build.log 2>&1 || { tail -30 build/app_build.log; exit 1; }
fi
grep -q "BUILD_OK" build/app_build.log || { echo "engine build not OK"; tail -20 build/app_build.log; exit 1; }
OUT=build/app/futari_combined
otool -L "$OUT" | grep -q avcodec && { echo "ERROR: engine still links libavcodec"; exit 1; }
for f in "$OUT" build/app/futari_game_normal.dylib build/app/futari_game_abn.dylib; do
  m=$(otool -l "$f" | awk '/LC_BUILD_VERSION/{f=1} f&&/minos/{print $2; exit}'); echo "   $(basename "$f"): minos $m"
  [ "$m" = "$MACOSX_DEPLOYMENT_TARGET" ] || { echo "ERROR: $f built for macOS $m, want $MACOSX_DEPLOYMENT_TARGET"; exit 1; }
done

echo "[2/8] launcher"
mkdir -p build
"$CXX" -std=c++17 -O2 -o build/app_launcher mac-build/launcher.c

echo "[3/8] bundle skeleton"
rm -rf "$APP"; mkdir -p "$C/MacOS" "$C/Frameworks" "$C/Resources"
cp build/app_launcher "$C/MacOS/Futari Realcomp"
cp "$OUT" "$C/MacOS/futari_merged"            # the engine keeps its historical name inside the bundle (launcher.c execs it)
cp build/app/futari_game_normal.dylib build/app/futari_game_abn.dylib "$C/MacOS/"

echo "[4/8] dylibs -> Contents/Frameworks, load commands rewritten"
SDL_DYLIB=$(ls external/SDL/build/libSDL3.*.dylib | head -1)
MVK_REAL="$(readlink -f "$BREW/opt/molten-vk/lib/libMoltenVK.dylib")"
m=$(otool -l "$SDL_DYLIB" | awk '/LC_BUILD_VERSION/{f=1} f&&/minos/{print $2; exit}'); [ "$m" = "$MACOSX_DEPLOYMENT_TARGET" ] || { echo "ERROR: SDL3 built for macOS $m (reconfigure external/SDL with -DCMAKE_OSX_DEPLOYMENT_TARGET=$MACOSX_DEPLOYMENT_TARGET)"; exit 1; }
cp "$SDL_DYLIB" "$C/Frameworks/libSDL3.0.dylib"
cp "$MVK_REAL"  "$C/Frameworks/libMoltenVK.dylib"
E="$C/MacOS/futari_merged"
"$INT" -change "$BREW/opt/molten-vk/lib/libMoltenVK.dylib" "@rpath/libMoltenVK.dylib" "$E"
for rp in $(otool -l "$E" | awk '/LC_RPATH/{f=1} f&&/path /{print $2; f=0}'); do "$INT" -delete_rpath "$rp" "$E" 2>/dev/null || true; done
"$INT" -add_rpath "@executable_path/../Frameworks" "$E"
"$INT" -id "@rpath/libSDL3.0.dylib" "$C/Frameworks/libSDL3.0.dylib"
"$INT" -id "@rpath/libMoltenVK.dylib" "$C/Frameworks/libMoltenVK.dylib"
echo "   deps now:"; otool -L "$E" | grep -v "/usr/lib/\|/System/" | sed 's/^/   /'
if otool -L "$E" "$C/Frameworks/"*.dylib "$C/MacOS/"*.dylib | grep -q "/opt/homebrew\|$PWD"; then echo "ERROR: a Homebrew/checkout path survives in the load commands"; exit 1; fi

echo "[5/8] licences + README"
MVK_LIC="$(dirname "$MVK_REAL")/../share/doc/molten-vk/LICENSE"; [ -f "$MVK_LIC" ] || MVK_LIC="$(brew --prefix molten-vk)/LICENSE"
cp "$MVK_LIC" "$C/Resources/LICENSE-MoltenVK.txt"
cp external/SDL/LICENSE.txt "$C/Resources/LICENSE-SDL3.txt" 2>/dev/null || true
cat > "$C/Resources/README.txt" <<EOF
Mushihimesama Futari Ver 1.5 -- futari_realcomp, native macOS build $VER (BETA 3, family-and-friends).
Not a release. Engine build id: $(git rev-parse --short HEAD 2>/dev/null)$(git diff --quiet 2>/dev/null || echo -dirty)

REQUIREMENTS
  Apple silicon Mac (M1 or later) running macOS 13 Ventura or newer. No Intel build.

MODES
  Both Ver 1.5 modes are in this build: ARCADE (1.5 Original) and XBOX 360 MODE. Pick one at the
  in-game title select; going back to the top menu and picking the other switches live, no relaunch.
  Ver 1.01 and Black Label stay greyed (not included).

CONTROLS
  Keyboard: arrows = D-pad, Z = A (shot), X = B (bomb), C = X, V = Y, Enter = START, Right Shift = BACK,
  F11 = fullscreen on/off. The game window must have focus.
  Controllers: anything SDL3 knows (PlayStation / Xbox / Switch pads, USB or Bluetooth). A second pad is
  PLAYER 2: press START on it at the character select, or pick 2P SIDE START.
  Button remapping, screen rotation (TATE), layout, picture and sound settings are the game's own
  OPTIONS menus and persist in the save.

FIRST LAUNCH ON A NEW MAC
  The app is self-signed, so macOS will refuse it once. Either run this in Terminal (replace the path
  with wherever you put the app):
      xattr -dr com.apple.quarantine "/Applications/Futari Realcomp.app"
  or open it, dismiss the warning, then System Settings > Privacy & Security > scroll down > "Open Anyway".
  (On macOS 13 and 14, right-click > Open also works.)

KNOWN ISSUES (beta 3)
  - Some shell/menu elements (the top-menu circles, PRESS START, the title logo) can flicker briefly.
    This is known and being worked on; please say WHERE you see it and whether it was in a menu or in play.
  - FrameDelay 2V/3V (OPTIONS > GAME) now paces correctly on macOS; 1V is the default and recommended.
  - If the window goes black mid-play and the app quits, it was a GPU device loss: send the log.

SAVES AND LOGS
  Saves:  ~/Library/Application Support/Futari Realcomp/save    (back this up to keep settings + scores)
  Logs:   ~/Library/Logs/Futari Realcomp/                        (one file per session)

BUG REPORTS
  Attach the newest log file, say which mode (ARCADE or XBOX 360), keyboard or pad, and what you were doing.
EOF

echo "[6/8] icon"
if [ -f "$HOME/Desktop/projects/Futari.app/Contents/Resources/AppIcon.icns" ]; then
  cp "$HOME/Desktop/projects/Futari.app/Contents/Resources/AppIcon.icns" "$C/Resources/AppIcon.icns"
elif [ -f "$HOME/Desktop/projects/Mushihimesama-Futari-PC-v1.2.0/icon1.ico" ]; then
  W=$(mktemp -d); sips -s format png "$HOME/Desktop/projects/Mushihimesama-Futari-PC-v1.2.0/icon1.ico" --out "$W/b.png" >/dev/null
  mkdir -p "$W/AppIcon.iconset"; for s in 16 32 64 128 256 512; do sips -z $s $s "$W/b.png" --out "$W/AppIcon.iconset/icon_${s}x${s}.png" >/dev/null; sips -z $((s*2)) $((s*2)) "$W/b.png" --out "$W/AppIcon.iconset/icon_${s}x${s}@2x.png" >/dev/null; done
  iconutil -c icns "$W/AppIcon.iconset" -o "$C/Resources/AppIcon.icns"; rm -rf "$W"
else echo "   (no icon source; generic icon)"; fi

if [ "${SKIP_ASSETS:-0}" = "1" ]; then echo "[7/8] game data -- SKIPPED"; else
  echo "[7/8] game data: $ASSETS_SRC -> Contents/Resources/assets ($(du -sh "$ASSETS_SRC" | cut -f1))"
  [ -f "$ASSETS_SRC/default.xex" ] || { echo "ERROR: $ASSETS_SRC has no default.xex"; exit 1; }
  ditto "$ASSETS_SRC" "$C/Resources/assets"
fi

echo "[8/8] Info.plist + ad-hoc signature"
cat > "$C/Info.plist" <<PLIST
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleName</key>                  <string>Futari Realcomp</string>
    <key>CFBundleDisplayName</key>           <string>Mushihimesama Futari (realcomp)</string>
    <key>CFBundleIdentifier</key>            <string>com.springah.futari-realcomp</string>
    <key>CFBundleExecutable</key>            <string>Futari Realcomp</string>
    <key>CFBundleIconFile</key>              <string>AppIcon</string>
    <key>CFBundlePackageType</key>           <string>APPL</string>
    <key>CFBundleInfoDictionaryVersion</key> <string>6.0</string>
    <key>CFBundleShortVersionString</key>    <string>${VER}</string>
    <key>CFBundleVersion</key>               <string>${VER}</string>
    <key>LSMinimumSystemVersion</key>        <string>13.0</string>
    <key>NSHighResolutionCapable</key>       <true/>
    <key>LSApplicationCategoryType</key>     <string>public.app-category.games</string>
</dict>
</plist>
PLIST
codesign --force --deep --sign - "$APP" 2>&1 | tail -2 || true
codesign --verify --deep --strict "$APP" && echo "   signature verifies"
echo "DONE -> $APP ($(du -sh "$APP" | cut -f1))"
