#!/bin/bash
# fnf15_funcbisect_mac.sh — FUNCTION-level bisect inside menu_base_states.cpp (the TU fnf15_bisect_mac.sh named).
# For each body the TU defines, compile a copy of the TU with ONLY that definition line renamed to <sym>__ro, so
# every caller (the vtable dispatch table and the TU's own direct calls alike) resolves to the GENERATED body
# while the other 13 readable bodies stay live. Link from build/obj_pristine, drive to the panel, score.
#   prerequisites: COMPILE_ONLY=1 OBJ=build/obj_pristine bash build_mac.sh ; a save in _local/saves/save_mac
#   FUNCS="sub_821B6D20 ..." to run a subset. Results: _local/fnf15_mac/fn_<sym>/{panel.png,metric.txt,...}
set -u
cd "$(dirname "$0")/../.."
TU="${DECOMP_DIR:-../futari_decomp/decomp}/shell/menu_base_states.cpp"
FUNCS="${FUNCS:-sub_821B6D20 sub_821BE810 sub_821BE3B8 sub_821BE398 sub_821BE378 sub_821BE4B0 sub_821BE210 sub_821B5D28 sub_821BC718 sub_8219FEC8 sub_821A0580 sub_821A0760 __imp__sub_821BE500 __imp__sub_821BEED8}"
BREW="$(brew --prefix)"; CXX="$BREW/opt/llvm/bin/clang++"; NM="$BREW/opt/llvm/bin/llvm-nm"; D=external/xr-derisk
STD="-std=c++20 -O2 -Wno-macro-redefined -DFUTARI_MODULE=0"
SHELL_INC="-I shell/gen -I out_reco -I $D/thirdparty/simde"
XS="-D_xstart=_xstart_shell -D__imp___xstart=__imp___xstart_shell"
R=_local/fnf15_mac; mkdir -p "$R"
press(){ osascript -e "tell application \"System Events\"
  key down $1
  delay 0.15
  key up $1
end tell" 2>/dev/null; }
metric(){ python3 - "$1" <<'PY'
import sys,subprocess,struct,os
src=sys.argv[1]; bmp=src+'.bmp'
subprocess.run(['sips','-s','format','bmp',src,'--out',bmp],capture_output=True)
d=open(bmp,'rb').read(); os.remove(bmp)
off=struct.unpack('<I',d[10:14])[0]; w,h=struct.unpack('<ii',d[18:26]); bpp=struct.unpack('<H',d[28:30])[0]; h=abs(h)
Bpp=bpp//8; row=(w*Bpp+3)&~3; sx=w/2560.0; x0,x1,y0,y1=int(800*sx),int(1760*sx),int(140*sx),int(1180*sx)
blk=tot=0
for y in range(y0,y1,2):
    r=off+(h-1-y)*row
    for x in range(x0,x1,2):
        b,g,rr=d[r+x*Bpp],d[r+x*Bpp+1],d[r+x*Bpp+2]; tot+=1
        if b<40 and g<40 and rr<40: blk+=1
print("%.4f"%(blk/tot if tot else 0))
PY
}
for fn in $FUNCS; do
  arm="fn_$fn"; Dd="$R/$arm"; mkdir -p "$Dd"; OBJ=build/obj_$arm; BIN=build/ctl_$arm; PROC="ctl_$arm"
  echo "== $arm: readable definition of $fn renamed to ${fn}__ro (generated body wins)"
  rm -rf "$OBJ"; cp -R build/obj_pristine "$OBJ"
  python3 - "$TU" "$Dd/menu_base_states.cpp" "$fn" <<'PY'
import sys,re
src,dst,fn=sys.argv[1:4]; t=open(src).read()
if fn.startswith('__imp__'): pat=re.compile(r'^(PPC_FUNC_IMPL\()'+re.escape(fn)+r'(\)\s*\n\s*\{)',re.M)
else:                        pat=re.compile(r'^(PPC_FUNC\()'+re.escape(fn)+r'(\)\s*\n\s*\{)',re.M)
t2,n=pat.subn(lambda m:m.group(1)+fn+'__ro'+m.group(2),t)
open(dst,'w').write(t2); print("definitions renamed:",n)
PY
  "$CXX" $STD $SHELL_INC -I . $XS -include out_reco/rt_indirect.h -c "$Dd/menu_base_states.cpp" -o "$OBJ/decomp_menu_base_states.o" 2>"$Dd/cc.err" \
    || { echo "   COMPILE FAILED"; grep error "$Dd/cc.err" | head -3; continue; }
  echo "   knocked-out symbol present: $($NM "$OBJ/decomp_menu_base_states.o" | grep -c "${fn}__ro")"
  OBJ="$OBJ" OUT="$BIN" LINK_ONLY=1 bash build_mac.sh > "$Dd/link.log" 2>&1; grep -q LINK_OK "$Dd/link.log" || { echo "   LINK FAILED"; tail -5 "$Dd/link.log"; continue; }
  pkill -x "ctl_.*" 2>/dev/null; sleep 1
  BIN="$BIN" RUN_SECS=60 bash scripts/run_mac.sh > "$Dd/run.log" 2>&1 &
  sleep 14
  osascript -e "tell application \"System Events\" to set frontmost of (first process whose name is \"$PROC\") to true" 2>/dev/null; sleep 1
  press return; sleep 5; press '"z"'; sleep 5; press '"z"'; sleep 5; press '"z"'; sleep 5
  press '(ASCII character 31)'; sleep 1; press '(ASCII character 31)'; sleep 2; press '"z"'; sleep 6
  B=$(osascript -e "tell application \"System Events\" to tell (first process whose name is \"$PROC\") to get {position, size} of window 1" 2>/dev/null)
  screencapture -x "$Dd/full.png"
  python3 - "$Dd/full.png" "$Dd/panel.png" "$B" <<'PY'
import sys,subprocess,re
src,dst,b=sys.argv[1],sys.argv[2],sys.argv[3]; n=[int(x) for x in re.findall(r'-?\d+',b)]
if len(n)==4:
    x,y,w,h=[v*2 for v in n]; subprocess.run(['sips','-c',str(h),str(w),'--cropOffset',str(y),str(x),src,'--out',dst],capture_output=True)
PY
  pkill -x "$PROC" 2>/dev/null
  L=$(ls -t _local/logs/mac_*.log | head -1); cp "$L" "$Dd/guest.log"
  reached=$(grep -c '\[tstate\] 96660(load)' "$Dd/guest.log")
  m=$( [ -f "$Dd/panel.png" ] && metric "$Dd/panel.png" || echo "n/a")
  echo "$arm panel_loaded=$reached black_fraction=$m" | tee "$Dd/metric.txt"
  wait
done
echo "== SUMMARY =="; cat "$R"/fn_*/metric.txt
