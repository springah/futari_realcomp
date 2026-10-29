#!/bin/bash
# rc_cut_mac.sh [<version>]  -- cut a futari_realcomp RELEASE CANDIDATE bundle on this Mac in ONE command (docs/PLAN_RC1.md §6).
#   bash scripts/rc_cut_mac.sh 0.3.0-rc1            # the real cut: preflight -> build -> frozen-bundle smoke -> tag + push -> zip -> sign-off block
#   DRY=1 bash scripts/rc_cut_mac.sh 0.3.0-rc1-dry   # (a)+(b)+(c) only: no tag, no zip; dirty/unpushed trees are WARNINGS, every smoke step runs
# Idempotent: re-running rebuilds the bundle, rewrites SMOKE.md (the old one is kept as SMOKE.prev.md), skips a tag that already points at HEAD,
# overwrites the zip. Fail-loud: any FAIL in a real cut stops it with the step named (DRY runs every step so the table is complete).
#
# (a) PREFLIGHT  futari_realcomp AND futari_decomp: worktree clean (`git status --porcelain` empty; the decomp check ignores untracked files OUTSIDE decomp/ --
#     the campaign banks evidence under bank/), branch main, HEAD == origin/main after `git fetch`. Both HEAD hashes are recorded.
# (b) BUILD      -> ~/Desktop/projects/_rc/<version>/Futari Realcomp.app via mac-build/build_mac_app.sh with APP=, VER=, RC_OUTDIR=build/rc_app,
#     RC_OBJSFX=_rc (its own object dirs: never build/app, obj_mac_host_app, build/futari_merged or the desktop "Futari Realcomp.app"). The decomp
#     tree compiled is a `git archive` snapshot of futari_decomp HEAD (so the recorded hash IS what was built even if the campaign keeps committing).
#     The README gets a Build block (version, date, both hashes, decomp TU count, engine flags) + docs/RC_KNOWN_ISSUES.md.
# (c) SMOKE      against THAT bundle, results into _rc/<version>/SMOKE.md, logs in _rc/<version>/logs/:
#       1 app_smoke    scripts/app_smoke_mac.sh on the .app itself (LaunchServices `open -a <path>`, AppleScript quit by path), under the DRIVE LOCK
#       2 gstart       scripts/gstart_mac.sh ARCADE (HUBSTART=1) + XBOX 360 -- no LEAK=YES row
#       3 q1_ctest     scripts/q7v_run.sh ... ctest 240 1 : RVK_CENSUSTEST positive control must report 60 DROPOUT-CONFIRMED / 60 injected
#       4 q1_census    scripts/rc_census_mac.sh arcade + x360 : single launch, dropouts only in the named AUTHENTIC classes, 0 FATAL/VK/slow/underrun, 3600 fpm
#       5 rc_chain     scripts/rc_chain_mac.sh all (swap x5, restart, continue, score-attack decline, remap; both modes) + T2 (DC-1) + CX (DC-2)
#     WHY an engine copy for steps 2-5: gstart/census/chain feed pads through a per-process FIFO, seed saves and read assets from the checkout, which a
#     LaunchServices launch cannot do per run. They therefore run a BYTE-IDENTICAL copy of the bundle's own futari_merged (cmp-checked, recorded in
#     SMOKE.md) staged with the bundle's module dylibs + Frameworks under _rc/<version>/smoke_engine/ and renamed `rcut_eng` so `pkill -x rcut_eng`
#     can only ever hit it. Same bytes = same code; the bundle-only properties (Info.plist, signature, bundle paths, Quit) are covered by step 1.
# (d) CUT        (real only, all-PASS, HEADs unchanged since preflight): annotated tag v<version> in futari_realcomp + realcomp-v<version> in futari_decomp
#     (at the decomp hash built), push both; zip `ditto -c -k --keepParent` -> _rc/Futari-Realcomp-macOS-v<version>.zip (+ .sha256/.md5), symlink into
#     ~/Desktop/projects/_serve/ (quick tunnel), print the sign-off block.
# DRIVE LOCK: /tmp/futari_drive.lock is taken only around step 1 here (sub-scripts take their own per leg); waits (60 s polls, up to LOCKWAIT s = 7200) while any
# futari_merged outside this bundle runs; a lock is rmdir'd only if THIS process made it. Kills: only `rcut_eng` / processes whose command is inside _rc/<version>.
set -u
cd "$(dirname "$0")/.."
REPO="$PWD"; PROJ="$(cd .. && pwd)"
VER="${1:-0.3.0-rc1}"; DRY="${DRY:-0}"
DECOMP_REPO="${DECOMP_REPO:-$PROJ/futari_decomp}"
RC="$PROJ/_rc"; RD="$RC/$VER"; APP="$RD/Futari Realcomp.app"; SMOKE="$RD/SMOKE.md"; LG="$RD/logs"
ENGDIR="$RD/smoke_engine"; PN=rcut_eng; ENG="$ENGDIR/MacOS/$PN"
SAFE="$(echo "$VER" | tr -c 'A-Za-z0-9\n' '_')"; BANK="_local/rc/$SAFE"
LOCK=/tmp/futari_drive.lock; HAVE=0; LOCKWAIT="${LOCKWAIT:-7200}"
rel(){ [ "$HAVE" = 1 ] && rmdir "$LOCK" 2>/dev/null; HAVE=0; }
trap 'rel; pkill -x "$PN" 2>/dev/null' EXIT
die(){ echo "[cut] STOP: $*" >&2; exit 1; }
log(){ echo "[cut] $(date +%H:%M:%S) $*"; }
[ "$DRY" = 1 ] && MODE_TXT="DRY RUN (no tag, no zip)" || MODE_TXT="REAL CUT"
echo "rc_cut_mac.sh $VER -- $MODE_TXT -- $(date '+%F %T')"

# ------------------------------------------------------------------------------------------------ (a) preflight
WARN=""
chk_repo(){ # name path ; fills RHASH_<name>, WARN
  local n="$1" p="$2" dirty br head up
  [ -d "$p/.git" ] || [ -f "$p/.git" ] || die "$n: $p is not a git repo"
  git -C "$p" fetch -q origin 2>/dev/null || WARN="$WARN$n: git fetch failed; "
  if [ "$n" = decomp ]; then dirty=$(git -C "$p" status --porcelain | grep -v '^?? ' ; git -C "$p" status --porcelain | grep '^?? decomp/')
  else dirty=$(git -C "$p" status --porcelain); fi
  br=$(git -C "$p" rev-parse --abbrev-ref HEAD); head=$(git -C "$p" rev-parse HEAD); up=$(git -C "$p" rev-parse origin/main 2>/dev/null || echo none)
  eval "H_$n=$head"
  [ -n "$dirty" ] && { WARN="$WARN$n: dirty worktree; "; echo "[preflight] $n DIRTY:"; echo "$dirty" | sed 's/^/    /'; }
  [ "$br" != main ] && WARN="$WARN$n: on branch $br not main; "
  [ "$head" != "$up" ] && WARN="$WARN$n: HEAD ${head:0:9} != origin/main ${up:0:9} (unpushed or behind); "
  echo "[preflight] $n: branch=$br HEAD=${head:0:12} origin/main=${up:0:12}"
  eval "D_$n=\"\$dirty\""
}
chk_repo realcomp "$REPO"; chk_repo decomp "$DECOMP_REPO"
if [ -n "$WARN" ]; then
  if [ "$DRY" = 1 ]; then echo "[preflight] DRY: continuing despite: $WARN"; else die "preflight refused: $WARN"; fi
fi
HR="$H_realcomp"; HD="$H_decomp"; TREE=CLEAN; [ -n "$WARN" ] && TREE="NOT CLEAN ($WARN)"
log "realcomp ${HR:0:12}  decomp ${HD:0:12}"
if [ "$DRY" != 1 ]; then
  git -C "$REPO" rev-parse -q --verify "refs/tags/v$VER" >/dev/null && [ "$(git -C "$REPO" rev-list -n1 "v$VER")" != "$HR" ] && die "tag v$VER exists on another commit"
fi
mkdir -p "$RD" "$LG"; [ -f "$SMOKE" ] && mv -f "$SMOKE" "$RD/SMOKE.prev.md"

# ------------------------------------------------------------------------------------------------ (b) build
log "decomp snapshot: git archive of ${HD:0:12} -> $RD/src/decomp"
rm -rf "$RD/src"; mkdir -p "$RD/src"; git -C "$DECOMP_REPO" archive "$HD" decomp | tar -x -C "$RD/src" || die "decomp archive failed"
DD="$RD/src/decomp"
TUS=$( (ls "$DD"/shell/*.cpp "$DD"/game/*.cpp "$DD"/game_abn/*.cpp 2>/dev/null) | wc -l | tr -d ' ')
TU_SH=$(ls "$DD"/shell/*.cpp 2>/dev/null | wc -l | tr -d ' '); TU_G=$(ls "$DD"/game/*.cpp 2>/dev/null | wc -l | tr -d ' '); TU_A=$(ls "$DD"/game_abn/*.cpp 2>/dev/null | wc -l | tr -d ' ')
TU_U=$( (cd "$DD" && ls shell/*.cpp game/*.cpp game_abn/*.cpp 2>/dev/null | xargs -n1 basename | sort -u) | wc -l | tr -d ' ')
LAUNCH_ENV=$(grep -o 'setenv("[A-Z_0-9]*", *"[^"]*"' mac-build/launcher.c | sed 's/setenv("//;s/", *"/=/;s/"$//' | tr '\n' ' ')
cat > "$RD/build_block.txt" <<EOF
BUILD (docs/PLAN_RC1.md section 6)
  Version:            $VER
  Built:              $(date '+%Y-%m-%d %H:%M %Z')
  futari_realcomp:    $HR   (main; tag v$VER$([ "$DRY" = 1 ] && echo ", NOT tagged: dry run"))
  futari_decomp:      $HD   (tag realcomp-v$VER$([ "$DRY" = 1 ] && echo ", NOT tagged: dry run"); the decomp/ tree compiled into this bundle is a snapshot of exactly this commit)
  Decomp TUs:         $TU_U distinct source TUs in the snapshot (shell $TU_SH, game/ARCADE $TU_G, game_abn/360 $TU_A), all compiled and linked
  Source tree state:  $TREE
  Engine:             combined host (shell + kernel + renderer + bridge) + 2 module dylibs, libavcodec NOT linked (FFM off), MoltenVK/SDL3 bundled,
                      macOS 13.0 minimum, ad-hoc signed. Launcher environment defaults: ${LAUNCH_ENV:-see mac-build/launcher.c}
EOF
log "build -> $APP"
( APP="$APP" VER="$VER" RC_OUTDIR=build/rc_app RC_OBJSFX=_rc DECOMP_DIR="$DD" RC_LABEL="RELEASE CANDIDATE" \
  RC_KNOWN_ISSUES_FILE="$REPO/docs/RC_KNOWN_ISSUES.md" RC_BUILD_BLOCK_FILE="$RD/build_block.txt" REUSE_OBJ="${REUSE_OBJ:-0}" \
  bash mac-build/build_mac_app.sh ) > "$LG/build.log" 2>&1 || { tail -40 "$LG/build.log"; die "bundle build failed (see $LG/build.log)"; }
tail -3 "$LG/build.log"
[ -x "$APP/Contents/MacOS/futari_merged" ] || die "no engine in the bundle"
# bundle facts: md5 of every Mach-O, signature
( cd "$APP" && find . -type f \( -perm -u+x -o -name '*.dylib' \) | sort | while read -r f; do file "$f" | grep -q Mach-O && echo "$(md5 -q "$f")  $f"; done ) > "$RD/MACHO_MD5.txt"
codesign --verify --deep --strict "$APP" 2>"$LG/codesign.txt" && SIG=OK || SIG="FAILED: $(cat "$LG/codesign.txt")"
OBJ_SH=$(ls build/obj_mac_host_rc/decomp_*.o 2>/dev/null | wc -l | tr -d ' ')
OBJ_G=$(ls build/obj_mac_mod_reco_normal_rc/decomp_*.o 2>/dev/null | wc -l | tr -d ' '); OBJ_A=$(ls build/obj_mac_mod_reco_abnormal_rc/decomp_*.o 2>/dev/null | wc -l | tr -d ' ')
# stage the engine copy for the script-driven steps
rm -rf "$ENGDIR"; mkdir -p "$ENGDIR"
cp -Rp "$APP/Contents/MacOS" "$ENGDIR/MacOS"; cp -Rp "$APP/Contents/Frameworks" "$ENGDIR/Frameworks"
mv "$ENGDIR/MacOS/futari_merged" "$ENG"; rm -f "$ENGDIR/MacOS/Futari Realcomp"
cmp -s "$ENG" "$APP/Contents/MacOS/futari_merged" && CMP=IDENTICAL || die "staged engine differs from the bundle's"
ENGMD5=$(md5 -q "$ENG")
{ echo "# SMOKE -- $VER ($MODE_TXT)"; echo
  echo "- started $(date '+%F %T'); bundle \`$APP\` ($(du -sh "$APP" | cut -f1)); signature $SIG"
  echo "- futari_realcomp \`$HR\`; futari_decomp \`$HD\`; tree: $TREE"
  echo "- decomp TUs: snapshot $TU_U distinct (shell $TU_SH / arcade $TU_G / 360 $TU_A); objects linked: shell $OBJ_SH / arcade $OBJ_G / 360 $OBJ_A"
  echo "- script-driven steps run \`$ENG\` = a copy of the bundle's futari_merged ($CMP, md5 $ENGMD5) with the bundle's dylibs + Frameworks"
  echo; echo "| step | result | secs | detail |"; echo "|---|---|---|---|"; } > "$SMOKE"

# ------------------------------------------------------------------------------------------------ (c) smoke
FAILED=""; DETAIL=""
others(){ local p c; for p in $(pgrep -x futari_merged 2>/dev/null); do c=$(ps -o command= -p "$p" 2>/dev/null); case "$c" in *"$RD"*) ;; *) echo "$p";; esac; done; }
wait_quiet(){ local w=0; while [ -n "$(others)" ]; do [ $w -ge "$LOCKWAIT" ] && return 1; [ $((w%600)) = 0 ] && log "waiting: another futari_merged is running ($(others | tr '\n' ' '))"; sleep 60; w=$((w+60)); done; return 0; }
run_step(){ local name="$1" fn="$2" t0 r; t0=$(date +%s); log ">>> step $name"; DETAIL=""
  wait_quiet || { DETAIL="another futari_merged ran for ${LOCKWAIT}s"; r=FAIL; }
  if [ -z "${r:-}" ]; then "$fn" > "$LG/$name.log" 2>&1 && r=PASS || r=FAIL; fi
  echo "| $name | **$r** | $(( $(date +%s)-t0 )) | ${DETAIL//|/\/} |" >> "$SMOKE"; log "<<< step $name: $r  ${DETAIL}"
  if [ $r = FAIL ]; then FAILED="$FAILED $name"; [ "$DRY" != 1 ] && { echo >> "$SMOKE"; echo "**CUT STOPPED at step $name**" >> "$SMOKE"; die "smoke step '$name' FAILED -- see $LG/$name.log and $SMOKE"; }; fi; }

s_app_smoke(){ local w=0
  while :; do if mkdir "$LOCK" 2>/dev/null; then HAVE=1; if [ -z "$(others)" ]; then break; fi; rel; fi
    [ $w -ge "$LOCKWAIT" ] && { DETAIL="no drive lock after ${w}s"; return 1; }; sleep 60; w=$((w+60)); done
  bash scripts/app_smoke_mac.sh "$APP"; local rc=$?
  rel   # our own lock, released the instant the smoke process is gone
  [ -z "$(pgrep -f -- "$(cd "$APP" && pwd -P)/Contents/MacOS/futari_merged")" ] || { echo "engine of this bundle still running"; pkill -f -- "$(cd "$APP" && pwd -P)/Contents/MacOS/futari_merged"; rc=1; }
  DETAIL="$(grep -a 'APP SMOKE:' "$LG/app_smoke.log" | tail -1 | tr -d '\n'); $(grep -a -c '^\[app\] PASS' "$LG/app_smoke.log") PASS lines"; return $rc; }

s_gstart(){ local rc=0 m tag tbl
  for m in arcade x360; do tag="rc_${SAFE}_$m"
    if [ $m = arcade ]; then HUBSTART=1 bash scripts/gstart_mac.sh "$tag" "$ENG" arcade; else bash scripts/gstart_mac.sh "$tag" "$ENG" x360; fi
    tbl="_local/gstart/$tag/TABLE.txt"
    if [ ! -s "$tbl" ]; then echo "gstart $m: no TABLE (run failed)"; rc=1; DETAIL="$DETAIL $m: NO TABLE;"; continue; fi
    if grep -q ' YES$' "$tbl"; then echo "gstart $m: LEAK rows:"; grep ' YES$' "$tbl"; rc=1; DETAIL="$DETAIL $m: LEAK ($(grep -c ' YES$' "$tbl") rows);"
    else DETAIL="$DETAIL $m: $(wc -l < "$tbl" | tr -d ' ') probes, 0 leaks;"; fi
    [ "$(grep -c FATAL "_local/gstart/$tag/guest.log" 2>/dev/null)" = 0 ] || { rc=1; DETAIL="$DETAIL $m: FATAL;"; }
  done; return $rc; }

s_q1_ctest(){ LOCKWAIT_MIN=$((LOCKWAIT/60)) bash scripts/q7v_run.sh "rc_$SAFE" "$ENG" ctest 240 1; local o="_local/rc1/q7v/rc_$SAFE/steps.txt" e
  e=$(grep -a 'END ' "$o" | tail -1); echo "$e"
  # PASS = every injected dropout confirmed (dropout == testmarks) and at least 60 in the 240 s window; the count itself is not fixed at 60 --
  # the injector arms per guest frame from the title load, so a run that reaches the title a little earlier arms 61 (Windows rc2 twin, 2026-10-29).
  local d t; d=$(echo "$e" | grep -o 'dropout=[0-9]*' | tr -dc 0-9); t=$(echo "$e" | grep -o 'testmarks=[0-9]*' | tr -dc 0-9)
  if [ -n "$d" ] && [ "$d" = "$t" ] && [ "$d" -ge 60 ] && echo "$e" | grep -q 'fatal=0 vkerr=0'; then DETAIL="positive control $d DROPOUT-CONFIRMED for $t INJECT"; return 0; fi
  DETAIL="control off: ${e#*END }"; return 1; }

s_q1_census(){ local rc=0 m
  for m in arcade x360; do LOCKWAIT="$LOCKWAIT" RCC_ROOT="$BANK/census" SHELL_SECS="${SHELL_SECS:-120}" bash scripts/rc_census_mac.sh "$m" "$ENG" "$m" "${CENSUS_MIN:-6}"; local r=$?
    local v="$BANK/census/$m/VERDICT.txt"; DETAIL="$DETAIL $m: $(grep -a '^RESULT' "$v" 2>/dev/null | tail -1) ($(grep -a '^INFO named' "$v" 2>/dev/null | sed 's/INFO named-class dropouts: //;s/ (.*//') named, $(grep -a 'outside the named' "$v" 2>/dev/null | sed 's/.*: //') other);"
    [ $r = 0 ] || rc=1; done; return $rc; }

s_rc_chain(){ local rc=0 root="$BANK/chain" t V bad
  run_chain(){ local tg="$1" item="$2"; shift 2; env "$@" RCC_ROOT="$root" SAVEPFX="rc_$SAFE" LOCKWAIT="$LOCKWAIT" bash scripts/rc_chain_mac.sh "$tg" "$ENG" "$item"; return $?; }
  run_chain rc all X=1 || rc=1
  if grep -q 'body_T2()' scripts/rc_chain_mac.sh; then run_chain rc_t2 T2 X=1 || rc=1; else echo "T2 item absent in this rc_chain_mac.sh -- SKIPPED"; DETAIL="$DETAIL T2 SKIPPED (item absent);"; fi
  if grep -q 'body_CX()' scripts/rc_chain_mac.sh; then run_chain rc_cx CX RT_PAUSEPROBE=1 || rc=1; else echo "CX item absent in this rc_chain_mac.sh -- SKIPPED"; DETAIL="$DETAIL CX SKIPPED (item absent);"; fi
  bad=$(grep -a -H '^FAIL' "$root"/rc*_*/VERDICT.txt 2>/dev/null)
  local npass; npass=$(cat "$root"/rc*_*/VERDICT.txt 2>/dev/null | grep -a -c '^PASS')
  if [ -n "$bad" ]; then echo "FAIL lines:"; echo "$bad"; rc=1; fi
  DETAIL="$npass PASS lines; FAIL: $(echo "$bad" | grep -c . | tr -d ' ')$( [ -n "$bad" ] && echo " -- $(echo "$bad" | sed 's|.*/rc[a-z0-9_]*_\([A-Za-z0-9_]*\)/VERDICT.txt:FAIL |\1: |' | cut -c1-110 | head -6 | tr '\n' ';')");$DETAIL"
  return $rc; }

run_step app_smoke   s_app_smoke
run_step gstart      s_gstart
run_step q1_ctest    s_q1_ctest
run_step q1_census   s_q1_census
run_step rc_chain    s_rc_chain
{ echo; echo "finished $(date '+%F %T'); ENGINE FAILED STEPS:${FAILED:- none}"; } >> "$SMOKE"
echo; cat "$SMOKE"

# ------------------------------------------------------------------------------------------------ (d) cut
if [ "$DRY" = 1 ]; then
  echo; echo "[cut] DRY RUN complete: smoke $([ -z "$FAILED" ] && echo ALL-PASS || echo "FAILED:$FAILED"). Nothing tagged, nothing zipped. Bundle: $APP   Table: $SMOKE"
  [ -z "$FAILED" ]; exit $?
fi
[ -z "$FAILED" ] || die "smoke failed:$FAILED"
[ "$(git -C "$REPO" rev-parse HEAD)" = "$HR" ] && [ "$(git -C "$DECOMP_REPO" rev-parse HEAD)" = "$HD" ] || die "a HEAD moved during the smoke -- the built pair is no longer the checked-out pair; re-run"
TM="futari_realcomp $VER -- release candidate. realcomp $HR, futari_decomp $HD ($TU_U decomp TUs). Frozen-bundle smoke ALL-PASS: $SMOKE"
if git -C "$REPO" rev-parse -q --verify "refs/tags/v$VER" >/dev/null; then log "tag v$VER already at HEAD"; else git -C "$REPO" tag -a "v$VER" -m "$TM" "$HR" || die "tag failed"; fi
git -C "$REPO" push origin "v$VER" || die "push tag (realcomp) failed"
if git -C "$DECOMP_REPO" rev-parse -q --verify "refs/tags/realcomp-v$VER" >/dev/null; then log "decomp tag already exists"; else git -C "$DECOMP_REPO" tag -a "realcomp-v$VER" -m "$TM" "$HD" || die "decomp tag failed"; fi
git -C "$DECOMP_REPO" push origin "realcomp-v$VER" || die "push tag (decomp) failed"
ZIP="$RC/Futari-Realcomp-macOS-v$VER.zip"; rm -f "$ZIP"
ditto -c -k --keepParent "$APP" "$ZIP" || die "zip failed"
( cd "$RC" && shasum -a 256 "$(basename "$ZIP")" > "$(basename "$ZIP").sha256" && md5 "$(basename "$ZIP")" > "$(basename "$ZIP").md5" )
mkdir -p "$PROJ/_serve"; ln -sf "$ZIP" "$PROJ/_serve/$(basename "$ZIP")"
cat <<EOF

================================================================ RC $VER CUT -- SIGN-OFF BLOCK
 bundle : $APP
 zip    : $ZIP  ($(du -h "$ZIP" | cut -f1))
 sha256 : $(cut -d' ' -f1 "$ZIP.sha256")      md5: $(md5 -q "$ZIP")
 tags   : futari_realcomp v$VER @ ${HR:0:12}   futari_decomp realcomp-v$VER @ ${HD:0:12}   (both pushed)
 smoke  : ALL-PASS  -> $SMOKE   (logs $LG, evidence $BANK)
 served : $PROJ/_serve/$(basename "$ZIP")  (symlink; start the quick tunnel from $PROJ/_serve for friends-and-family)

 NOW, BY HAND (an agent PASS does not sign off an RC):
  1. Play the bundle with docs/RC1_HANDS_CHECKLIST.md (7 steps; logs land in ~/Library/Logs/Futari Realcomp/, saves in
     ~/Library/Application Support/Futari Realcomp/save). Tell the next seat: mode, keyboard or pad, what you were doing, newest log name.
  2. If it is good: say "RC1 signed off". Then (docs only): add to STATUS.md
       RC $VER: realcomp ${HR:0:12} + decomp ${HD:0:12}; bundle md5 list _rc/$VER/MACHO_MD5.txt; zip sha256 $(cut -c1-16 "$ZIP.sha256")...
     and copy the zip to the SHARED release share when the NAS is back (10.0.0.x; nginx :8088), or give testers the _serve tunnel link.
  3. If it is not: any engine fix = next candidate rc2 (PLAN_RC1 6.7). Never edit or re-zip this bundle.
  F&F only, people who own the game: the zip contains the game data. Never post it publicly.
================================================================
EOF
