#!/bin/bash
# run_window.sh (2026-07-13) — PLAY THE PORT ON SCREEN.
# Launches futari_merged.exe with the on-screen swapchain window (RVK_WINDOW=1) and your real
# keyboard (RT_PAD_HOST GetAsyncKeyState bridge): arrows = D-pad/stick, Z = A(shot), X = B(bomb),
# Enter = START, RShift = BACK. No synthetic input at all (RT_PAD_WAIT mutes the auto timeline);
# you press START at the title like a human. RT_SAVE=save gives the real save flow (existing save
# silent-loads; a fresh save/ dir asks the real create dialog — answer with Z).
# The offscreen PNG pipeline still runs (heavily throttled) so diagnostics stay available.
ROOT_DIR="C:/Users/shant/Desktop/projects/futari_realcomp/xr-work"
cd "$ROOT_DIR" || { echo "FATAL: cannot cd to $ROOT_DIR"; exit 1; }
export MSYS_NO_PATHCONV=1
mkdir -p /c/tmp
ROOT="$(pwd -W 2>/dev/null || pwd)"
export RT_GAME_ROOT="$ROOT/assets"

# proven boot + hookrender + wallpaper lever set (run_hktrace.sh lineage)
export RT_BOOT_SHELL=1 RT_THREADS=1 RT_DEFERDRIVER=1 RT_ASYNCIO=1 RT_EHCONTAIN=1 RT_AUDIOPUMP=1
export RT_VK=1 RVK_PERSIST=1 RVK_RENDER_FROM=1 RVK_NOHALVE=1 RVK_FIXVP=1 RVK_REALALPHA=1 RVK_BLEND=1
export RT_HOOKRENDER=1 RVK_HKFLIPY=1 RT_HKTEXOFF=0x480
export RT_WALLPAPER=1

# gameplay: hybrid routing + calibration levers (stage runner lineage) so entering a game works
export RT_HYBRID=1 RT_SLOT2FIX=2 RT_VTXSNAP=1 RVK_TEXPITCH=1
export RVK_GPFIELD=1 RVK_C255=0.00625:0.00390625:-1:0
export RVK_RESALIAS=1 RVK_RESFRESH=1
# RVK_DISPLAYALL (2026-07-14): render the whole frame's batch list in guest order to the display,
# bypassing the resolve-segmentation + the stale vs=47 self-composite. Verified live on-window:
# renders the TOP MENU / in-game menu CRISP (no fade-in doubling) AND shows the live field
# content (the vs=48 0x120F7000 cave terrain) instead of the pure-white COMPSEG wash. Supersedes
# RVK_COMPSEG for the display. (Residual: field shows a cyan tint — a texture channel/untile
# artifact, the next refinement.) Override with RVK_DISPLAYALL=0 to go back to COMPSEG.
if [ "${RVK_DISPLAYALL:-1}" != "0" ]; then export RVK_DISPLAYALL=1; else export RVK_COMPSEG=1; fi

# RVK_HDR (2026-07-14): FIXES the field overexposure. The X360 renders the additive bloom into
# 7e3-FLOAT EDRAM ([0,32) HDR); our old UNORM8 targets clipped it to white. RVK_HDR renders the field
# in R16F and tonemaps on present (field frames only — menus/title stay bright via clamp). ACES +
# exposure 0.5 is a clean default; override RVK_HDR=0 for the old UNORM8 path, or tune RVK_TONEMAP
# (0=Reinhard 1=ACES 2=clamp) / RVK_EXPOSURE.
if [ "${RVK_HDR:-1}" != "0" ]; then
  export RVK_HDR=1 RVK_TONEMAP="${RVK_TONEMAP:-1}" RVK_EXPOSURE="${RVK_EXPOSURE:-0.5}"
else unset RVK_HDR; fi

# THE WINDOW + your keyboard. RT_PAD_WAIT mutes the synthetic pulse timeline: human input only.
export RVK_WINDOW=1
export RT_PAD=1 RT_PAD_HOST=1 RT_PAD_WAIT=9999999

# real save subsystem (existing save silent-loads straight to TOP MENU)
export RT_SAVE="${RT_SAVE:-_local/saves/save}"   # 09-04 hygiene: RT_SAVE dirs live under _local/saves/ (templates save_freshcard / save_r17_boss / save_eyeball stay at root)

# PNG pipeline throttled way down — the window is the display now
export RVK_PNGEVERY=600

# RT_NOPAUSE=1 below is HARNESS-ONLY, NEVER SHIP (w50 adjudication D7: ship default is env-unset = the authentic pause, w45-measured; np1 exists because an unattended leg cannot press RESUME and the orphaned post-run pause -- w47, never rare -- would wedge every leg)
export RT_SNDQFREE=1 RT_NOPAUSE=1 RT_RESCACHE=1 RT_HEAPLOCK=1
export RT_SAMPLES=100000

echo "window controls: arrows=D-pad  Z=A(shot)  X=B(bomb)  Enter=START  RShift=BACK"
exec ./futari_merged.exe 8208A2B8 0 shell/default.xex 2>/c/tmp/window.log
