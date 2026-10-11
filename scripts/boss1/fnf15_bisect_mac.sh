#!/bin/bash
# fnf15_bisect_mac.sh — the FNF-15 single-TU bisect (NOTE_fnf_shell_defects.md 2026-09-20), run on the Mac.
# Symptom: the TRAINING config panel draws no rows (only the tips caption). Control-proven: skipping the eight
# shell decomp TUs below draws the whole dialog. This links one arm per TU from a pristine object set, drives
# each to the panel (START A A A DOWN DOWN A on a card with a save), captures the window and scores the
# black-pixel fraction of the panel box (pilot ~0.0x = rows missing; the drawn dialog's black panel >> that).
#   prerequisites: COMPILE_ONLY=1 OBJ=build/obj_pristine bash build_mac.sh ; a save in _local/saves/save_mac
#   ARMS="pilot ctlshell mbs ..." to run a subset. Results: _local/fnf15_mac/<arm>/{panel.png,metric.txt,run.log}
set -u
cd "$(dirname "$0")/../.."
declare -A TU=( [mbs]=menu_base_states [tvd]=textview_draw [opb]=options_panel_base [oph]=options_panel_hooks
                [mns]=menunode_states [mct]=menu_containers [odb]=options_decide_builders [tcf]=training_config )
ALL8="menu_base_states menunode_states menu_containers options_panel_base options_panel_hooks options_decide_builders training_config textview_draw"
ARMS="${ARMS:-pilot ctlshell mbs tvd opb oph mns mct odb tcf}"
R=_local/fnf15_mac; mkdir -p "$R"
press(){ osascript -e "tell application \"System Events\"
  key down $1
  delay 0.15
  key up $1
end tell" 2>/dev/null; }
metric(){ # $1=window png -> black fraction of the panel box (x 800-1760, y 140-1180 of a 2560x1504 capture)
  python3 - "$1" <<'PY'
import sys,subprocess,struct,os
src=sys.argv[1]; bmp=src+'.bmp'
subprocess.run(['sips','-s','format','bmp',src,'--out',bmp],capture_output=True)
d=open(bmp,'rb').read(); os.remove(bmp)
off=struct.unpack('<I',d[10:14])[0]; w,h=struct.unpack('<ii',d[18:26]); bpp=struct.unpack('<H',d[28:30])[0]; h=abs(h)
Bpp=bpp//8; row=(w*Bpp+3)&~3
sx=w/2560.0; x0,x1,y0,y1=int(800*sx),int(1760*sx),int(140*sx),int(1180*sx)
blk=tot=0
for y in range(y0,y1,2):
    r=off+(h-1-y)*row
    for x in range(x0,x1,2):
        b,g,rr=d[r+x*Bpp],d[r+x*Bpp+1],d[r+x*Bpp+2]; tot+=1
        if b<40 and g<40 and rr<40: blk+=1
print("%.4f"%(blk/tot if tot else 0))
PY
}
for arm in $ARMS; do
  D="$R/$arm"; mkdir -p "$D"
  case $arm in pilot) skip="";; ctlshell) skip="$ALL8";; *) skip="${TU[$arm]}";; esac
  OBJ=build/obj_$arm; BIN=build/ctl_$arm
  echo "== $arm: skip=[$skip]"
  rm -rf "$OBJ"; cp -R build/obj_pristine "$OBJ"; for s in $skip; do rm -f "$OBJ/decomp_$s.o"; done
  OBJ="$OBJ" OUT="$BIN" LINK_ONLY=1 bash build_mac.sh > "$D/link.log" 2>&1 || { echo "   LINK FAILED"; tail -5 "$D/link.log"; continue; }
  grep -q LINK_OK "$D/link.log" || { echo "   LINK not OK"; tail -5 "$D/link.log"; continue; }
  pkill -x "ctl_.*" 2>/dev/null; sleep 1
  BIN="$BIN" RUN_SECS=60 bash scripts/run_mac.sh > "$D/run.log" 2>&1 &
  sleep 14
  osascript -e "tell application \"System Events\" to set frontmost of (first process whose name is \"ctl_$arm\") to true" 2>/dev/null; sleep 1
  press return; sleep 5; press '"z"'; sleep 5; press '"z"'; sleep 5; press '"z"'; sleep 5
  press '(ASCII character 31)'; sleep 1; press '(ASCII character 31)'; sleep 2; press '"z"'; sleep 6
  B=$(osascript -e "tell application \"System Events\" to tell (first process whose name is \"ctl_$arm\") to get {position, size} of window 1" 2>/dev/null)
  screencapture -x "$D/full.png"
  python3 - "$D/full.png" "$D/panel.png" "$B" <<'PY'
import sys,subprocess,re
src,dst,b=sys.argv[1],sys.argv[2],sys.argv[3]; n=[int(x) for x in re.findall(r'-?\d+',b)]
if len(n)==4:
    x,y,w,h=[v*2 for v in n]; subprocess.run(['sips','-c',str(h),str(w),'--cropOffset',str(y),str(x),src,'--out',dst],capture_output=True)
PY
  pkill -x "ctl_$arm" 2>/dev/null
  L=$(ls -t _local/logs/mac_*.log | head -1); cp "$L" "$D/guest.log"
  reached=$(grep -c '\[tstate\] 96660(load)' "$D/guest.log")
  m=$( [ -f "$D/panel.png" ] && metric "$D/panel.png" || echo "n/a")
  echo "$arm skip=[$skip] panel_loaded=$reached black_fraction=$m" | tee "$D/metric.txt"
  wait
done
echo "== SUMMARY =="; cat "$R"/*/metric.txt
