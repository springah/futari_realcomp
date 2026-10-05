# DECK.md — running futari_realcomp on the Steam Deck (what actually works, 2026-10-05)

Build: `bash mac-build/deck/build_deck.sh` on the Mac (Rosetta container) → `Futari-Realcomp-Deck/` + `make_appimage.sh`
→ `Futari-Realcomp-x86_64.AppImage`. Both carry the same engine (`futari_combined` + the two module `.so`).

## The two sessions, and why SSH launches look like success and are not
SteamOS runs one of two sessions: **Gaming Mode = gamescope** (`gamescope-wl`, Wayland socket
`/run/user/1000/gamescope-0`, an XWayland on `:0`/`:1`) or **Desktop Mode = Plasma**. Switch with
`steamos-session-select plasma|gamescope` (never `desktop`), with `XDG_RUNTIME_DIR=/run/user/1000
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus`; it drops the SSH session.

In Gaming Mode gamescope hands a VISIBLE surface only to the app Steam launched and focused. A client started
over SSH (`WAYLAND_DISPLAY=gamescope-0 SDL_VIDEODRIVER=wayland ./AppRun`) DOES get a Vulkan surface, creates a
swapchain, submits frames at full rate and logs like a healthy boot -- and shows NOTHING on the screen. It is a
headless smoke, nothing more. The 10-05 first boot was exactly this: `swapchain 1280x800 x5`, `SDL3 window up
(video=wayland)`, f8701 after ~2.5 min, 0 errors -- and an empty Deck screen. Treat an SSH launch as proof of
renderer bring-up only; never as "it runs on the Deck".

To SEE it: register it as a **Non-Steam game** (Desktop Mode: Steam > Add a Non-Steam Game > the AppImage or
`futari-realcomp`; Compatibility = none) and launch it from Steam, or from SSH with the shortcut's id:
`steam steam://rungameid/<id>` as an isolated call (the id is in
`~/.steam/steam/userdata/<user>/config/shortcuts.vdf`; the earlier recomp entries "Mushihime-Sama Futari" /
"futari-linux" live there too). Desktop Mode alternative: source `/run/user/1000/gamescope-environment` for
`DISPLAY=:0` and run it there (visible, but the GPU idles at 200 MHz: not a speed test).

## What the Deck needs from the renderer (fixed 10-05)
gamescope/Wayland surfaces report `currentExtent = 0xFFFFFFFF` ("the swapchain decides"). The renderer used the
raw value → `[rvk][win] swapchain create FAILED` → die-loud exit code 4 on every launch (the 10-04 AppImage).
`rvkWindowCreateSwapchain` now sizes the swapchain from the SDL window's pixel size, clamped to the surface's
min/max extent (render/vk_render.cpp; commit e3512aa). Win32, X11 and MoltenVK report a defined extent and
never take that arm. RADV VANGOGH: Vulkan 1.4.350, present modes MAILBOX/FIFO/IMMEDIATE, format 44
(B8G8R8A8_UNORM), min 3 images; the renderer's feature checks all passed.

## SSH hygiene (both bit me on 10-05)
- Kill with `pkill -9 -x futari_combined`. **Never `pkill -f futari…`**: the pattern matches the SSH shell's own
  command line and kills your session (exit 255, no output).
- Background the launch with `setsid nohup … > /tmp/x.out 2>&1 < /dev/null & disown`, in a SEPARATE ssh call from
  the one that reads the log; an ssh call that both launches and waits hangs on the inherited descriptors.
- The AppImage mounts under `/tmp/.mount_Futari*`; `--appimage-extract` into `~/squashfs-root` gives a tree you can
  patch binaries into (that is how the fixed host was tested before the AppImage was rebuilt).
- Logs: `~/.local/share/futari-realcomp/logs/`, saves beside them; the zip layout uses `./logs` and `./save`.
- FUSE2 is present on SteamOS 3.9 (`/usr/lib/libfuse.so.2`), AppImages run unextracted. glibc 2.43 on the Deck;
  the engine needs ≤ 2.34.
- Screenshots in Gaming Mode: `WAYLAND_DISPLAY=gamescope-0 gamescopectl screenshot /tmp/x.png`; synthetic input:
  xdotool on `DISPLAY=:1` (held keys, no `--window`) or uinput (see the daytona Deck notes).

## Desktop Mode launch over SSH that is actually visible (verified 10-05 10:01, _local/captures/deck_desktop_title_20261005.png)
`setsid nohup … & disown` from an ssh `bash -c` did NOT survive (the AppImage died before writing a line); a
foreground run worked; the robust detached form is a user service:
```
P=$(pgrep -u deck -x plasmashell | head -1); tr "\0" "\n" < /proc/$P/environ | grep -E "^(DISPLAY|WAYLAND_DISPLAY|XDG_RUNTIME_DIR|XAUTHORITY)=" > /tmp/plasma.env
systemd-run --user --unit=futari-realcomp --collect --setenv=DISPLAY=:0 --setenv=WAYLAND_DISPLAY=wayland-0 \
  --setenv=XDG_RUNTIME_DIR=/run/user/1000 --setenv=XAUTHORITY=<from plasma.env> --working-directory=/home/deck \
  /home/deck/Downloads/Futari-Realcomp-x86_64.AppImage
systemctl --user stop futari-realcomp        # to end it
```
Plasma on SteamOS 3.9 is a Wayland session (`XDG_SESSION_TYPE=wayland`, `WAYLAND_DISPLAY=wayland-0`, XWayland on
`:0`); SDL picked Wayland (`video=wayland`), swapchain 1280x800 x4. Screenshot from ssh with the same env:
`spectacle -b -n -o /tmp/x.png`. The title appeared in a 1280x800 window at full rate (f1501 at ~25 s), 0 errors.
A gamescope SIGABRT coredump at 09:56 coincides with the session switch to Desktop Mode (not the game's process).

## Performance: the spinning vsync gate (found and fixed 10-05, user: "a little slower than the rexglue port")
Measured in Gaming Mode through the Steam shortcut, before the fix: 60 frames/s in menus AND in stage, GPU 1040 MHz
at 23% busy -- but the process's main thread at 96% of a core even at the title, user-space PC inside
`sub_8216B148` (+0x636): the shell's mode-1 vsync gate, `do { v = *(u64*)0x821F8550 } while (v == *(u64*)0x821F8560)`,
a pure memory poll for the next vblank (8550 = written by the vblank ISR chain, 8560 = last value the gate consumed).
Register-true, free on a 360, a pinned host core on a port; on the Deck's shared 15 W APU budget that core competes
with the GPU for boost. Fix = RT_VBSLEEP (shell/gen/rt.cpp + the sub_8216B148 wrapper in merged_shell.cpp): block on
a condition variable the vblank thread notifies, only while the loop's own condition holds, 40 ms guard, guest loop
untouched. After: main thread 28-30%, process 40-46%, 60 frames/s, GPU idling at 200 MHz in menus and boosting on
demand (M3 Max: 97% -> 27%). `RT_VBSLEEP=0` reverts. Tooling that got these numbers over ssh: frames from the
`[nvk] submit fN` counter delta, CPU from `/proc/<pid>/stat` utime+stime deltas and `ps -L -o tid,pcpu`,
GPU from `/sys/class/drm/card0/device/pp_dpm_sclk` + `gpu_busy_percent`, the hot PC from `sudo eu-stack -p`
(sudo password needed: `echo 1 | sudo -S`) mapped through `llvm-nm` on the Linux binary (PIE: vaddr = pc - map
start + segment vaddr).

## Verdict (10-05, user at the Deck, Gaming Mode via the Steam shortcut, RT_VBSLEEP build)
"seems ok now i think?" -- tentative parity with the SDK port after the vsync-gate fix; several stages and four
game overs played in one session at 60 frames/s, 0 errors.

## Unattended validation on the Deck (10-05, RT_VBSLEEP build, Gaming Mode, invisible ssh runs; scripts/deck/)
`modes_deck.sh d1`: XBOX 360 MODE to stage 1 PASS (first ever on an AMD GPU), ARCADE to stage 1 PASS, swap cycle
arcade -> x360 -> arcade `#2 DONE` / `#3 DONE` with residue=0 twice and the hub ACTIVE after the return swap,
0 FATAL / 0 VK_ERROR. `soak_deck.sh 30`: 10 samples at 60 frames/s, RSS flat at 195 MB from the first minute, main
thread 17%, GPU idling at 200 MHz between boosts, 0 errors -- then the Deck dropped off the network at t+10 min
(ssh "closed by remote host", unreachable after): Gaming Mode's idle suspend, which an invisible ssh-launched client
does not inhibit. Lesson: a Deck soak over ssh needs the suspend timer off (Settings > Power) or a Steam-launched run.

## Still owed
A longer play session for a firm verdict; the pacing retest under RVK_DECOUPLE (BACKLOG #12) if "a little slower"
ever comes back; the controller mapping check under Steam Input; Xbox 360 mode on the Deck (not yet selected there).
