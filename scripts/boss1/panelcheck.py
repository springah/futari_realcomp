# panelcheck.py <run-tag> — FNF-15 metric: for the frames dumped while the Training panel was open
# (between the [tstate] 96660(load) and the first [dclose] vt=0x82050F00 line of drive.log), the
# fraction of near-black pixels inside the panel box (x 330..950, y 110..490 of the 1280x720 dump).
# Rows drawn => the black dialog body dominates (frac > 0.5). Rows missing => key art shows (frac < 0.2).
import sys, re, os
from PIL import Image
tag = sys.argv[1]; bank = f"C:/tmp/boss1/{tag}"
frames = []; state = 0
for line in open(f"{bank}/drive.log", encoding="utf-8", errors="replace"):
    if state == 0 and "96660(load)" in line: state = 1
    elif state == 1:
        if "[dclose]" in line and "0x82050F00" in line: break
        m = re.search(r"wrote C:/tmp/nvk_f(\d+)\.png", line)
        if m: frames.append(int(m.group(1)))
if not frames: print(f"{tag}: NO frames dumped while the panel was open (state={state})"); sys.exit(1)
for f in frames:
    p = f"{bank}/png/nvk_f{f}.png"
    if not os.path.exists(p): print(f"{tag}: f{f} missing"); continue
    im = Image.open(p).convert("RGB").crop((330, 110, 950, 490))
    px = im.getdata(); n = len(px)
    black = sum(1 for r, g, b in px if r < 24 and g < 24 and b < 24)
    frac = black / n
    verdict = "ROWS DRAWN" if frac > 0.5 else ("ROWS MISSING" if frac < 0.2 else "ambiguous")
    print(f"{tag}: f{f} black_frac={frac:.3f} -> {verdict}")
