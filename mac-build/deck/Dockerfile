# The Steam Deck build container (2026-10-04): x86_64 Debian 12 (glibc 2.36 < SteamOS 3.8's 2.41, so the binaries are
# portable to the Deck) + clang/lld 18 from apt.llvm.org + the headers SDL3 needs to compile its X11/Wayland/PipeWire/
# PulseAudio/ALSA backends (all dlopen'ed at runtime, nothing extra is linked). Run on the Mac through colima/Rosetta:
#   docker build --platform linux/amd64 -t futari-deck-build mac-build/deck
#   bash mac-build/deck/build_deck.sh            (mounts this checkout + ../futari_decomp, builds everything)
FROM --platform=linux/amd64 debian:bookworm
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y --no-install-recommends \
      ca-certificates curl gnupg git cmake ninja-build python3 pkg-config file \
      libvulkan-dev libx11-dev libxext-dev libxrandr-dev libxcursor-dev libxi-dev libxfixes-dev libxss-dev libxkbcommon-dev \
      libwayland-dev wayland-protocols libdecor-0-dev libdrm-dev libgbm-dev libegl-dev \
      libasound2-dev libpulse-dev libpipewire-0.3-dev libdbus-1-dev libudev-dev libusb-1.0-0-dev \
    && curl -fsSL https://apt.llvm.org/llvm-snapshot.gpg.key | gpg --dearmor -o /usr/share/keyrings/llvm.gpg \
    && echo "deb [signed-by=/usr/share/keyrings/llvm.gpg] http://apt.llvm.org/bookworm/ llvm-toolchain-bookworm-18 main" > /etc/apt/sources.list.d/llvm.list \
    && apt-get update && apt-get install -y --no-install-recommends clang-18 lld-18 llvm-18 libc++-18-dev libc++abi-18-dev \
    && for t in clang clang++ lld ld.lld llvm-nm llvm-objcopy llvm-cxxfilt; do ln -sf /usr/bin/$t-18 /usr/local/bin/$t; done \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /work/futari_realcomp
# AppImage tooling (added 10-04 night): mksquashfs + the type2 AppImage runtime (static, x86_64). The AppImage is
# runtime + squashfs(AppDir), assembled by mac-build/deck/make_appimage.sh without FUSE (no appimagetool needed).
RUN apt-get update && apt-get install -y --no-install-recommends squashfs-tools && rm -rf /var/lib/apt/lists/* \
    && curl -fsSL -o /usr/local/lib/appimage-runtime-x86_64 https://github.com/AppImage/type2-runtime/releases/download/continuous/runtime-x86_64 \
    && file /usr/local/lib/appimage-runtime-x86_64 | grep -q ELF && chmod 755 /usr/local/lib/appimage-runtime-x86_64
