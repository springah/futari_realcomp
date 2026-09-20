import re, sys, os, collections
from PIL import Image
run = sys.argv[1]; out = sys.argv[2]
log = f'C:/tmp/boss1/{run}/drive.log'
hdr = re.compile(r'\[nvkrect\] f(\d+) d(\d+) vs=45')
rl  = re.compile(r'\[nvkrect\]\s+r(\d+) v0=\{([-\d.]+),([-\d.]+) uv ([-\d.]+),([-\d.]+)\} v1=\{([-\d.]+),([-\d.]+) uv ([-\d.]+),([-\d.]+)\} v2=\{([-\d.]+),([-\d.]+) uv ([-\d.]+),([-\d.]+)\}')
frames = collections.OrderedDict(); cur=None
for line in open(log, encoding='utf-8', errors='replace'):
    m = hdr.match(line)
    if m: cur=int(m.group(1)); frames.setdefault(cur, []); continue
    m = rl.match(line)
    if m and cur is not None:
        f=[float(x) for x in m.groups()[1:]]
        x0,y0,u0,v0,x1,y1,u1,v1,x2,y2,u2,v2=f
        frames[cur].append((x0,y0,x1-x0,y2-y0,min(u0,u1),max(u0,u1),min(v0,v2),max(v0,v2),v2<v0))
picks=[]
for fr,rects in frames.items():
    big=[r for r in rects if r[2]>=96 and r[3]>=64]
    for r in big:
        if r[8]:
            tw=[t for t in big if not t[8] and t[4:8]==r[4:8]]
            if tw: picks.append((fr, r, tw[0]))
print("frames with a big mirrored pair:", [(p[0], f"flipped@({p[1][0]:.0f},{p[1][1]:.0f}) unflipped@({p[2][0]:.0f},{p[2][1]:.0f}) {p[1][2]:.0f}x{p[1][3]:.0f} u{p[1][4]:.0f}-{p[1][5]:.0f} v{p[1][6]:.0f}-{p[1][7]:.0f}") for p in picks][:8])
tiles=[]
for fr,r,t in picks[:4]:
    p=f'C:/tmp/boss1/{run}/png/nvk_f{fr}.png'
    if os.path.exists(p): tiles.append((fr, Image.open(p).crop((400,80,880,440))))
if tiles:
    sh=Image.new('RGB',(480*len(tiles),360))
    for i,(fr,im) in enumerate(tiles): sh.paste(im,(i*480,0))
    sh.save(out); print("wrote", out, [t[0] for t in tiles])
