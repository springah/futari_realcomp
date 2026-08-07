#!/usr/bin/env bash
# Build + run the build-time XenosRecomp shader-cache extractor.
#
# Produces:
#   ~/xr-work/render/shaders_futari.h        (embeddable shader table)
#   ~/xr-work/shaders/spv/<vs|ps>_<addr>.spv  (per-shader raw SPIR-V dumps)
#
# Libraries used (all already on disk, nothing downloaded):
#   - smolv:   ~/UnleashedRecomp/tools/XenosRecomp/thirdparty/smol-v/source/smolv.cpp
#   - xxHash:  ~/UnleashedRecomp/tools/XenosRecomp/thirdparty/xxHash (header-only, XXH_INLINE_ALL)
#   - zstd:    system libzstd-dev (/usr/include/zstd.h, /usr/lib/x86_64-linux-gnu/libzstd.so)

set -euo pipefail

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
XENOS="$HOME/UnleashedRecomp/tools/XenosRecomp"
SHADERS_DIR="$HOME/xr-work/shaders"

mkdir -p "$HOME/xr-work/shaders/spv"

clang++ -O2 -std=c++17 \
    -I "$HERE" \
    -I "$SHADERS_DIR" \
    -I "$XENOS/thirdparty/smol-v/source" \
    -I "$XENOS/thirdparty/xxHash" \
    "$HERE/extract_cache.cpp" \
    "$XENOS/thirdparty/smol-v/source/smolv.cpp" \
    -lzstd \
    -o "$HERE/extract_cache"

"$HERE/extract_cache" \
    "$HOME/xr-work/caps_s8/cap_image.bin" \
    "$HOME/xr-work/caps_s8/cap_gimage.bin"
