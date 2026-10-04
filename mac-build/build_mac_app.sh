#!/bin/bash
# build_mac_app.sh -- assemble a double-clickable "Futari Realcomp.app" from the native macOS build.
#
#   bash mac-build/build_mac_app.sh                 -> ~/Desktop/projects/Futari Realcomp.app (with game data)
#   APP=/path/Out.app SKIP_ASSETS=1 ...             -> verification bundle without game data
#   ASSETS_SRC=/path/to/assets                      -> which extracted dump to ship (default: ./assets)
#   REUSE_OBJ=1                                     -> skip the compile, relink build/obj_app as it is
#
# What the bundle is: the COMBINED engine (build/futari_merged shape: every readable TU + the recompiled
# shell/game, one Mach-O; the per-mode module-dylib arm is not needed), SDL3 and MoltenVK copied into
# Contents/Frameworks and the load commands rewritten to @rpath / @executable_path so nothing points at
# Homebrew or this checkout, a tiny exec-launcher (mac-build/launcher.c) as CFBundleExecutable that sets
# scripts/run_mac.sh's environment and the bundle-relative paths, and the user's extracted assets/ under
# Contents/Resources/assets. Saves land in ~/Library/Application Support/Futari Realcomp/save, the guest
# log in ~/Library/Logs/Futari Realcomp/.
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
VER="${VER:-0.1.0-ff}"
C="$APP/Contents"
BREW="$(brew --prefix 2>/dev/null || echo /opt/homebrew)"
CXX="${CXX:-$BREW/opt/llvm/bin/clang++}"; [ -x "$CXX" ] || CXX=clang++
INT="$BREW/opt/llvm/bin/llvm-install-name-tool"; [ -x "$INT" ] || INT=install_name_tool

echo "[1/8] engine (self-contained link: no libavcodec, SDL told to dlopen the bundled MoltenVK)"
OBJ=build/obj_app; OUT=build/app_futari_merged
if [ "${REUSE_OBJ:-0}" = "1" ] && [ -d "$OBJ" ]; then
  FFM=/nonexistent OBJ="$OBJ" OUT="$OUT" LINK_ONLY=1 bash build_mac.sh > build/app_link.log 2>&1 || { tail -20 build/app_link.log; exit 1; }
else
  FFM=/nonexistent MVK_LOADPATH="@executable_path/../Frameworks/libMoltenVK.dylib" OBJ="$OBJ" OUT="$OUT" bash build_mac.sh > build/app_build.log 2>&1 || { tail -30 build/app_build.log; exit 1; }
fi
grep -q LINK_OK build/app_link.log build/app_build.log 2>/dev/null || { echo "engine link not OK"; exit 1; }
otool -L "$OUT" | grep -q avcodec && { echo "ERROR: engine still links libavcodec"; exit 1; }

echo "[2/8] launcher"
mkdir -p build
"$CXX" -std=c++17 -O2 -o build/app_launcher mac-build/launcher.c

echo "[3/8] bundle skeleton"
rm -rf "$APP"; mkdir -p "$C/MacOS" "$C/Frameworks" "$C/Resources"
cp build/app_launcher "$C/MacOS/Futari Realcomp"
cp "$OUT" "$C/MacOS/futari_merged"

echo "[4/8] dylibs -> Contents/Frameworks, load commands rewritten"
SDL_DYLIB=$(ls external/SDL/build/libSDL3.*.dylib | head -1)
MVK_REAL="$(readlink -f "$BREW/opt/molten-vk/lib/libMoltenVK.dylib")"
cp "$SDL_DYLIB" "$C/Frameworks/libSDL3.0.dylib"
cp "$MVK_REAL"  "$C/Frameworks/libMoltenVK.dylib"
E="$C/MacOS/futari_merged"
"$INT" -change "$BREW/opt/molten-vk/lib/libMoltenVK.dylib" "@rpath/libMoltenVK.dylib" "$E"
for rp in $(otool -l "$E" | awk '/LC_RPATH/{f=1} f&&/path /{print $2; f=0}'); do "$INT" -delete_rpath "$rp" "$E" 2>/dev/null || true; done
"$INT" -add_rpath "@executable_path/../Frameworks" "$E"
"$INT" -id "@rpath/libSDL3.0.dylib" "$C/Frameworks/libSDL3.0.dylib"
"$INT" -id "@rpath/libMoltenVK.dylib" "$C/Frameworks/libMoltenVK.dylib"
echo "   deps now:"; otool -L "$E" | grep -v "/usr/lib/\|/System/" | sed 's/^/   /'
if otool -L "$E" "$C/Frameworks/"*.dylib | grep -q "/opt/homebrew\|$PWD"; then echo "ERROR: a Homebrew/checkout path survives in the load commands"; exit 1; fi

echo "[5/8] licences + README"
MVK_LIC="$(dirname "$MVK_REAL")/../share/doc/molten-vk/LICENSE"; [ -f "$MVK_LIC" ] || MVK_LIC="$(brew --prefix molten-vk)/LICENSE"
cp "$MVK_LIC" "$C/Resources/LICENSE-MoltenVK.txt"
cp external/SDL/LICENSE.txt "$C/Resources/LICENSE-SDL3.txt" 2>/dev/null || true
cat > "$C/Resources/README.txt" <<EOF
Mushihimesama Futari -- futari_realcomp, native macOS (arm64) build $VER, family-and-friends test build.
Not a release. Engine build id: $(git rev-parse --short HEAD 2>/dev/null)$(git diff --quiet 2>/dev/null || echo -dirty)

Keyboard: arrows = D-pad, Z = A (shot), X = B (bomb), C = X, V = Y, Enter = START, Right Shift = BACK, F11 = fullscreen.
Controllers: anything SDL3 knows (PlayStation / Xbox / Switch pads over USB or Bluetooth).
Only the Original (reco_normal) mode is hosted in this build; the other modes stay greyed in the menu.

Saves:  ~/Library/Application Support/Futari Realcomp/save
Logs:   ~/Library/Logs/Futari Realcomp/   (attach the newest one when reporting a problem)

First launch on a new Mac: right-click the app > Open (it is self-signed), or in Terminal:
  xattr -dr com.apple.quarantine "/Applications/Futari Realcomp.app"
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
