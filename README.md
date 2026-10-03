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
poller. Windows keeps its Win32 window and XInput untouched. Still missing here: the xWMA
decoder. This is **not** the shipping recipe; `build_win.sh` is.

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

## Documentation

- `STATUS.md` — where the live state is (one paragraph; points at the decomp repo's ledger)
- `docs/BACKLOG.md` — ranked open work (last re-ranked 2026-08-03; the ledger's owed list is fresher)
- `../futari_decomp/docs/NOTE_campaign_decomp.md` — the campaign ledger; newest entries at the top
- `tools/matchlab/README.md` — the matching toolchain, its rules, and its landmines

## Layout conventions

- Durable inputs (compilers, SDKs, references) never live in a temp directory.
- Anything regenerable — captures, logs, objects, saves — goes under `_local/` and is gitignored.
- Shared tooling used by more than one project lives in `../_tools/`, not here.
