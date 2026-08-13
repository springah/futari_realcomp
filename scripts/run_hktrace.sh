#!/bin/bash
# run_hktrace.sh — RT_HOOKRENDER menu recipe matching the Linux reference (verify_menu.sh) +
# the AUTHORITATIVE texture offset RT_HKTEXOFF=0x480 (from futari-multipass-composite-rootcause)
# + RT_HKTRACE per-present diagnostic + RT_HKTEXDBG to confirm the fetch-constant reads.
cd "$(dirname "$0")"
export MSYS_NO_PATHCONV=1
mkdir -p /c/tmp
rm -f /c/tmp/rvk_last.png /c/tmp/rvk_peak.png /c/tmp/rvk_menu.png /c/tmp/rvk_frame*.png /c/tmp/hktrace.log /c/tmp/cand_*.png 2>/dev/null
ROOT="$(pwd -W 2>/dev/null || pwd)"
export RT_GAME_ROOT="$ROOT/assets"
export RT_BOOT_SHELL=1 RT_THREADS=1 RT_DEFERDRIVER=1 RT_ASYNCIO=1 RT_EHCONTAIN=1 RT_AUDIOPUMP=1
export RT_VK=1 RVK_PERSIST=1 RVK_RENDER_FROM=1 RVK_NOHALVE=1 RVK_FIXVP=1 RVK_REALALPHA=1 RVK_BLEND=1
export RT_HOOKRENDER=1 RVK_HKFLIPY=1 RT_HKTEXOFF=0x480 RT_HKTRACE=1 RT_HKTEXDBG=25
export RVK_PNGEVERY="${RVK_PNGEVERY:-12}"   # rate-limit PNG -> ~23fps -> real-time-ish nav timing
# 2026-07-12 (Windows boot-reliability fix): the shell's boot-asset pump (sub_821CE400,
# [bootsm] cur76/want80) parks at cur76=3 waiting for a SINGLE-TICK command-bit edge (rec0+68
# briefly gets bit 0x8 OR'd in for exactly one CE400 tick before something clears it — see
# [bootsm] logs) to arrive from a title-skip START press. A single wall-clock START pulse
# lands on an essentially random CE400 tick and almost always misses that edge; the confirmed
# working manual recipe (repeated START presses over ~9-13s, then an ~11s+ gap before the first
# A) simply raises the odds of overlapping the edge by spamming it across a wide window instead
# of hitting it once. RT_STARTFSM (tick-gated injection in the GAME's scene FSM, sub_88138F00)
# does NOT apply here: that function never runs during shell boot ([smf]/[startfsm] log lines
# are absent until well after the TOP MENU, confirmed via hktrace.log) — this is purely a SHELL
# state machine, so its own [bootsm] tick counter has no race-free injection point exposed yet.
# Until one exists, encode the empirically-reliable mash-then-wait shape as the default script:
# STARTx26@500 spams START every 500ms for ~13s (26 pulses), then Ax4@1500 confirms the save
# dialog/menu-enter A starting at t=24s (an 11s+ gap after the START spam ends).
# Ax4@1500 (2026-07-13): PARKS on the settled TOP MENU — the old Ax10@1000 kept confirming
# past it (version card -> Now Loading), so the run's final candidates were post-menu frames.
export RT_PAD=1 RT_PAD_HOST=1 RT_NAV_SEQ="${2:-0:STARTx26@500,24000:Ax4@1500}"
export RT_SNDQFREE=1 RT_NOPAUSE=1 RT_RESCACHE=1 RT_HEAPLOCK=1
export RT_SAMPLES=100000
DUR="${1:-60}"
# seed rvk_last.png with the clear color so a failed run is distinguishable
python -c "from PIL import Image; Image.new('RGB',(1280,720),(0,0,26)).save(r'C:\tmp\rvk_last.png')" 2>/dev/null
./futari_merged.exe 8208A2B8 0 shell/default.xex >/c/tmp/hktrace.out 2>/c/tmp/hktrace.log &
PID=$!
# sample rvk_last.png every ~250ms keeping every snapshot as a candidate (menu animates in;
# PM4 blanks between presents so we score the richest afterward)
n=0
for i in $(seq 1 $((DUR*4))); do
  python -c "import time;time.sleep(0.25)" 2>/dev/null
  kill -0 "$PID" 2>/dev/null || { echo "process exited near $((i/4))s"; break; }
  cp /c/tmp/rvk_last.png "/c/tmp/cand_$(printf %04d $n).png" 2>/dev/null; n=$((n+1))
done
kill "$PID" 2>/dev/null; sleep 1; kill -9 "$PID" 2>/dev/null
echo "captured $n candidates"
echo "=== hktrace: draw-call growth (every 10th present + last) ==="
grep -a '\[hktrace\]' /c/tmp/hktrace.log | awk 'NR%10==1' | tail -20
grep -a '\[hktrace\]' /c/tmp/hktrace.log | tail -1
echo "=== hktex: fetch-constant reads (first 8) — base/dims/fmt should be SANE not 0 ==="
grep -a '\[hktex\]' /c/tmp/hktrace.log | head -8
echo "=== richest candidate by distinct colors ==="
python - <<'PY'
from PIL import Image; import glob,os
best=(-1,None)
for f in sorted(glob.glob(r'C:\tmp\cand_*.png')):
    try:
        c=len(Image.open(f).convert('RGB').getcolors(maxcolors=1000000))
        if c>best[0]: best=(c,f)
    except Exception: pass
if best[1]:
    print(f'BEST {best[1]} colors={best[0]}')
    Image.open(best[1]).save(r'C:\tmp\hkbest.png')
    im=Image.open(best[1]).convert('RGB'); im.thumbnail((640,360)); im.save(r'C:\tmp\hkbest_thumb.png')
else: print('NO CANDIDATES')
PY
echo "=== PEAK-draw menu frame (rvk_peak.png) ==="
grep -a 'NEW PEAK' /c/tmp/hktrace.log | tail -3
python - <<'PY'
from PIL import Image; import os
p=r'C:\tmp\rvk_peak.png'
if os.path.exists(p):
    im=Image.open(p).convert('RGB'); c=len(im.getcolors(maxcolors=1000000))
    print(f'rvk_peak.png colors={c}')
    t=im.copy(); t.thumbnail((640,360)); t.save(r'C:\tmp\peak_thumb.png')
else: print('NO PEAK FRAME')
PY
echo "=== MENU-BAND clean single-frame menu (rvk_menu.png) ==="
grep -a 'MENU-BAND' /c/tmp/hktrace.log | tail -3
python - <<'PY'
from PIL import Image; import os
p=r'C:\tmp\rvk_menu.png'
if os.path.exists(p):
    im=Image.open(p).convert('RGB'); c=len(im.getcolors(maxcolors=1000000))
    print(f'rvk_menu.png colors={c}')
    t=im.copy(); t.thumbnail((640,360)); t.save(r'C:\tmp\menu_thumb.png')
else: print('NO MENU-BAND FRAME')
PY