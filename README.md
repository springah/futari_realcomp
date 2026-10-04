# futari_realcomp

A static recompilation of the Xbox 360 release of **Mushihimesama Futari Ver 1.5** to native
Windows (macOS and Linux planned).

The goal is a **matching decompilation**: the game's own recompiled code plus a thin, faithful
kernel and GPU layer, in the mould of UnleashedRecomp. Output should be explainable by the
original code and hardware semantics rather than approximated — renderer heuristics are treated as
temporary scaffolding, not solutions.

> **Status:** in development, not shippable. A beta has run end-to-end (attract, menus, Normal
> Play, Training, saves, native audio), but known defects remain — see `docs/BACKLOG.md`.

> **Game data is not included and never will be.** `assets/` and every `.xex` are gitignored. You
> must supply your own dump of a game you own.

## Layout

| path | what it is |
|---|---|
| `decomp/` | Hand-written **matching decompilations** of guest functions (`game/`, `shell/`). The real work. |
| `out_reco/`, `out_reco_abn/` | Recompiler **output** for the two game modules, plus the hand-written `harness.cpp` (kernel/allocator) and `rt.cpp` (runtime) that live alongside it. |
| `shell/` | The shell executable's recompiled tree and its kernel layer (vblank, notify, sign-in, D3D9). |
| `render/` | The Vulkan renderer (`vk_render.cpp`) and the `nvk` wrapper-altitude recorder API. |
| `host/` | Host ABI, module registry, and the descriptors the module DLLs are built against. |
| `moduleshim/` | Host-facing shim for the per-mode module DLLs. |
| `shaders/` | Shader sources and the generated shader table. |
| `config/` | Recompiler codegen configs (`*.toml`) — inputs to the recompiler, not to the build. |
| `external/` | Third-party build dependencies: `xr-derisk` (XenonUtils + simde headers) and `XenosRecomp` (shader compiler). |
| `thirdparty/` | Vendored libraries linked into the port. |
| `tools/matchlab/` | Byte-exact matching workbench — compiles a candidate decompilation with the period-correct XDK compiler and diffs it against the original image. See `tools/matchlab/README.md`. |
| `scripts/` | Drive, capture and legacy build scripts. |
| `docs/` | Design notes, specs, and the campaign ledger. |
| `reference/` | Reference material: Ghidra databases, audio references, reference screenshots. |
| `build/` | **Gitignored.** Every build product: object dirs, executables, module DLLs. Delete it freely; it regenerates. |
| `_local/` | **Gitignored.** Captures, logs, drive save directories (`_local/saves/`), build output, banked evidence, and archived scratch. Nothing here is needed to build or run. |

## Building (Windows)

Requires Git Bash and clang/lld. The matching workbench additionally needs the XDK 9328 compiler
at `../_tools/xdk/xdk9328` (override with `MATCHLAB_CL`).

```bash
bash build_win.sh        # combined executable
bash build_win_dll.sh    # combined executable + the two module DLLs
```

All build products — objects, executables, DLLs — land in `build/`, which is gitignored.

## Building (Linux)

The Linux build is the proving ground for the macOS/Deck ports (BACKLOG #12): everything but the
GPU surface and the audio device is the same code. It builds the combined executable
`build/futari_merged`. On this build SDL3 provides the on-screen window and Vulkan surface
(`RVK_WINDOW`, F11 fullscreen, close-to-quit — same levers as Windows) and the host controllers
(the XInput slot; `RT_NOXINPUT` disables); host keyboard (`RT_PAD_HOST`) is the X11 keymap
poller, or the SDL window's own keys under `RVK_WINDOW`. Windows keeps its Win32 window and XInput
untouched. The SDL3 audio sink runs here too (since 2026-10-03; before that the live sink was
Windows-only). This is **not** the shipping recipe; `build_win.sh` is.

The SDL window path has a standalone smoke test that needs no game data (Xvfb + Mesa llvmpipe
is enough): see the `RVK_SDL_SMOKE` block at the end of `render/vk_render.cpp` for the one-line
build and run.

```bash
bash build_linux.sh      # combined executable, build/futari_merged
LINK_ONLY=1 bash build_linux.sh   # relink the existing object dir
```

Requires clang, lld, `libvulkan-dev`, and under the gitignored `external/`: a XenonRecomp
checkout built with CMake (`external/xr-derisk`, for XenonUtils + simde) and a static SDL3 build
with audio, video, Vulkan and joystick on (`external/SDL`). The exact cmake lines are in the header of `build_linux.sh`,
which also checks for every dependency before compiling. The decomp tree is picked up from
`../futari_decomp/decomp` exactly as on Windows (`DECOMP_DIR` overrides). The merge semantics are
the same as `build_win.sh`: ELF's `--allow-multiple-definition` keeps the first definition, so the
object order carries over unchanged.
The repository root holds the README, `STATUS.md` (a pointer to the live campaign state), the
three build scripts, and exactly three save-directory templates that the drive scripts copy
from (`save_freshcard`, `save_r17_boss`, `save_eyeball`). Every other save directory a drive
creates goes under `_local/saves/` — set `RT_SAVE=_local/saves/save_<tag>` (convention since
2026-09-04; the runtime uses the value verbatim, relative to the repo root).

## Building (macOS)

`build_mac.sh` is the macOS counterpart (arm64, Homebrew llvm + molten-vk + vulkan-headers, SDL3
shared) and **builds and boots the shell to the title screen on an M3 Max (2026-10-03)**. The
four macOS-specific designs (main-thread window, duplicate-symbol merge without
`--allow-multiple-definition`, MoltenVK plumbing, and the weak-stub rewrite of the
`__attribute__((alias))` lines Mach-O cannot take), the recipe, and what is still open are in
`docs/PLAN_macos_bringup.md`. `scripts/run_mac.sh` is the attended-session drive: keyboard
(arrows, Z=A, X=B, C=X, V=Y, Enter=START, RShift=BACK) and SDL controllers, sound through the SDL3
CoreAudio sink, saves under `_local/saves/save_mac/`. Compressed xWMA banks decode through
libavcodec when Homebrew `ffmpeg` is installed (only the bridge/A-B arms use it).

```bash
bash build_mac.sh            # single merged executable, build/futari_merged (~50 s on an M3 Max) — the drive/gate target
LINK_ONLY=1 bash build_mac.sh
bash build_mac_dll.sh        # the shipping shape (beta 3): build/futari_combined + futari_game_{normal,abn}.dylib (both modes)
bash mac-build/build_mac_app.sh   # -> "Futari Realcomp.app" (game data inside: family-and-friends only)
bash scripts/run_mac.sh      # boot the shell in a window (BIN=build/futari_combined for the two-mode host)
```

`bash mac-build/deck/build_deck.sh` builds the same two-mode engine for the Steam Deck (x86_64 Linux) inside a Rosetta
container on the Mac (`mac-build/deck/Dockerfile`, `build_linux_dll.sh`) and stages `Futari-Realcomp-Deck/`.

The Xbox 360 tree (`out_reco_abn/`, gitignored) is regenerated on the Mac with `scripts/regen_abn_mac.sh`, which applies
`tools/xenonrecomp_mac_eqv_fixes.patch` (the codegen fixes of the Windows-side recompiler fork, reconstructed and
validated against the tracked reco_normal tree) to the upstream XenonRecomp checkout. The beta-3 checklist is
`docs/PLAN_beta3_mac.md`.

## Documentation

- `STATUS.md` — where the live state is (one paragraph; points at the decomp repo's ledger)
- `docs/BACKLOG.md` — ranked open work (last re-ranked 2026-08-03; the ledger's owed list is fresher)
- `docs/PLAN_macos_bringup.md` — the macOS port handoff (2026-10-03): what is done, what is blind, the order to look
- `../futari_decomp/docs/NOTE_campaign_decomp.md` — the campaign ledger; newest entries at the top
- `tools/matchlab/README.md` — the matching toolchain, its rules, and its landmines

## Layout conventions

- Durable inputs (compilers, SDKs, references) never live in a temp directory.
- Anything regenerable — captures, logs, objects, saves — goes under `_local/` and is gitignored.
- Shared tooling used by more than one project lives in `../_tools/`, not here.
