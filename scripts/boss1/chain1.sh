#!/bin/bash
# chain1.sh — FNF-15 single-TU arms (rows metric) then the three old builds to the boss. Detached; log = /c/tmp/boss1/chain1.log
S="/c/Users/shant/AppData/Local/Temp/claude/C--Users-shant-Desktop/6855b48b-d165-4248-bcba-716400370c43/scratchpad"
cd /c/Users/shant/Desktop/projects/futari_realcomp || exit 1
for A in mbs tvd opb oph mns mct odb tcf; do
  E=build/futari_combined_ctl_$A.exe; n=0
  until [ -f "$E" ] && [ -z "$(pgrep -f build_host_ctlarm 2>/dev/null)" ] || [ $n -ge 60 ]; do powershell -NoProfile -Command "Start-Sleep -Seconds 10"; n=$((n+1)); done
  echo "===== ARM $A ($E) training route NRIGHT=0 DUR=12  $(date +%H:%M:%S)"
  BIN="./$E" ROUTE=training NRIGHT=0 DUR=12 bash "$S/boss1_drive2.sh" arm_$A 2>&1 | grep -E 'GAVE UP|FAIL|DONE|stuck' | tail -4
  python "$S/panelcheck.py" arm_$A 2>&1 | grep -v -i 'warning\|getdata'
done
for run in 0807:_local/build-output/futari_merged.exe 0814:build/futari_ctrl.exe 0827:./futari_merged_v154hi.exe; do T=${run%%:*}; B=${run#*:}
  echo "===== OLD BUILD tr_$T  BIN=$B  $(date +%H:%M:%S)"
  BIN="$B" ROUTE=training NRIGHT=1 DUR=150 bash "$S/boss1_drive2.sh" tr_$T 2>&1 | grep -E 'GAVE UP|FAIL|DONE|stuck' | tail -6
  echo "--- markers"; grep -a -E '\[decide\]|\[tstate\] 96660|\[dclose\].*0F00|\[xinput\] press pad=0x0008' /c/tmp/boss1/tr_$T/drive.log | head -6
  python "$S/panelcheck.py" tr_$T 2>&1 | grep -v -i 'warning\|getdata' | head -3
  python "$S/headframes.py" tr_$T /c/tmp/boss1/tr_${T}_sheet.png 2>&1 | tail -2
done
echo "CHAIN1 DONE $(date +%H:%M:%S)"
