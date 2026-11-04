# NOTES — 0.3.0-rc5 handoff to the Mac seat (written on the PC seat, 2026-11-03 ~12:45 AUSEST)

> **DONE 2026-11-04 21:20 AUSEST on the Mac — attempt 7 ALL-PASS on the current (one-window) rule, user ruling "rerun as is"; the §3 episode rule was
> not needed and stays undecided. Tags pushed, F&F + public macOS zips staged, public smoke PASS, NOTHING UPLOADED. Record: `STATUS.md` top block,
> `BACKLOG.md` 2026-11-04, `NOTE_fnf_shell_defects.md` 2026-11-04. New landmine for §6: the script's tag push fails over ssh from a detached shell
> (publickey refused; global insteadOf rewrites https→ssh) — push tags over HTTPS with `GIT_CONFIG_GLOBAL=/dev/null git -c credential.helper='!gh auth git-credential'`.**


The user is moving to the Mac to finish rc5 there. This file is the complete state so the Mac session needs nothing from the PC
transcript. Detail per attempt lives in `NOTE_fnf_shell_defects.md` (entries dated 2026-11-03, newest first) and `BACKLOG.md`
(the 2026-11-03 morning bullet); this is the operational summary + the open decision + the exact next commands.

## 1. Where rc5 stands

| Seat | State |
|---|---|
| Windows | **DONE, not uploaded.** All five gates PASS on engine 0f23859 (`_rc/0.3.0-rc5-win/SMOKE.md`). F&F zip `_rc/Futari-Realcomp-Windows-v0.3.0-rc5.zip` sha256 `301832b4…78c2` (964 MB, HAS game data, F&F only). Public asset-free zip `_rc/Futari-Realcomp-Windows-v0.3.0-rc5-public.zip` sha256 `2d0dfa38…1cbc` (33.5 MB), wizard-smoked. No Windows tag (the Mac cut makes `v0.3.0-rc5`). |
| macOS | **NOT CUT.** Six attempts of `scripts/rc_cut_mac.sh 0.3.0-rc5`; every one stopped at `q1_census`, never an rc5 defect. The last two (A5 11:26, A6 12:03) passed app_smoke, gstart, q1_ctest and the XBOX 360 census CLEAN, and failed ARCADE on ONE stall episode each. No tags exist for rc5 on either remote. |

Engine sources are identical on both seats (realcomp main, decomp 1d79e208). The Mac checkout `~/Desktop/projects/futari_realcomp`
was at 5dc987b when A6 ran; main is now ahead (docs only). **The cut's preflight refuses unless HEAD == origin/main in BOTH repos
and the tree is clean**, so the first command on the Mac is a pull (section 4).

## 2. What is failing and why it is the box, not rc5

- Marker: `[vblank] stall: deadline forgiven #N (debt>4T)` (shell/gen/rt.cpp:1118) = the present loop fell >4 frame periods (67 ms)
  behind = the whole process was off the CPU/GPU. The audio ring is ~10 × 5.3 ms = 53 ms, so every such stall drains it and the census
  prints one `[starve] 1s window … underruns=N` burst next to the marker (A6 showed a window can flush up to 3 log lines BEFORE its marker).
- Every Mac underrun burst today sits next to a marker; the clean runs have neither. A back-to-back same-box A/B (rc4 vs rc5 engine)
  put the burst on rc4 and 0 on rc5. Windows rc5 censuses are 0/0 in both modes.
- The box: macOS 27.2, 36 GB (≈34 used). `mediaanalysisd` was caught at 108 % CPU 30 s after A6 ended, working on
  `~/Library/Photos/Libraries/Syndication.photoslibrary` + `~/Library/MediaAnalysis/*.sqlite` (log: `MADServiceTextProcessingTask`,
  EmbeddingCore) = the user's Photos/Messages media, NOT our keyframes (the morning "census PNGs feed it" hypothesis is WITHDRAWN).
  `mds_stores` / `mdworker_shared` also active in bursts. The user's Spotlight Privacy exclusions (added 11:40 for `projects/_rc`,
  `projects/_local`, `futari_realcomp/_local`) were NOT effective at 12:03 — verify with
  `mdfind -onlyin ~/Desktop/projects/futari_realcomp/_local 'kMDItemFSName == "*.png"' | wc -l` (was 41,640; effective = 0).
- Game Mode (user, 11-03): real play in full screen engages macOS Game Mode (bundle declares `public.app-category.games`; F11 =
  `SDL_SetWindowFullscreen`) which deprioritises those daemons. The gates run the raw engine copy windowed, so they never get it: the
  census measures a harsher box than a player sees. A census/soak variant launched through the .app in full screen is docketed in BACKLOG
  (not for rc5).

Already landed on main (f5b00c6, ⚖ both): the Mac census forgives ONE stall-adjacent underrun window per run (first `underruns=[1-9]`
window within 40 lines AFTER a marker; `RT_CENSUS_NOFORGIVE=1` scores everything; Windows twin unchanged) and census/G-START keyframes
go to `png.noindex` on both seats. That rule is why A5 scored 26 (forgave 12 of 38) and A6 scored 5 (forgave 21 of 26).

## 3. The OPEN decision (⚖, user's call) — asked at 12:40, not yet answered

**"Forgive one stall EPISODE per run instead of one window?"**

- **Yes, one episode** → amend `scripts/rc_census_mac.sh` `verdict()` so the first marker cluster (markers within 40 lines of each other)
  forgives every underrun window from 10 lines before its first marker to 40 lines after its last; a second cluster, or a window with
  no marker near it, is still scored. DRAFT replacement for the awk (two passes over `$L`; UNVALIDATED — validate before use):

  ```
  read -r ufg ufw <<<"$(awk 'NR==FNR{ if(/\[vblank\] stall: deadline forgiven/){ if(!m0){m0=NR;m1=NR} else if(NR-m1<=40){m1=NR} } next }
       /underruns=[1-9]/ && m0 && FNR>=m0-10 && FNR<=m1+40 { match($0,/underruns=[0-9]+/); fg+=substr($0,RSTART+10,RLENGTH-10); fw++ }
       END{print fg+0, fw+0}' "$L" "$L")"
  ```

  Also change the INFO line text ("…in $ufw window(s) around the first [vblank] stall episode…") and the header comment. Validation set
  (expected scored UNDERRUN after the rule): A5 ARCADE `_local/rc/0_3_0_rc5_attempt5/census/arcade/guest.log` 38→0 · A6 ARCADE
  `…attempt6/census/arcade/guest.log` 26→0 · A3 x360 `…attempt3/census/x360/guest.log` 41→0 · rc4 A/B `_local/rc/ab1103/rc4/arcade/guest.log`
  23→0 · A4 x360 `…attempt4/census/x360/guest.log` (3 markers, 6 windows spread over the run: should still FAIL — two episodes) ·
  any clean log 0→0. Run the awk alone on each log first, then docket ⚖ in NOTE + BACKLOG, commit, push, then section 4.
- **No, keep rerunning** → section 4 as is, on the current rule.

## 4. Exact next commands on the Mac (login shell is fish — run these in `bash`)

```
cd ~/Desktop/projects/futari_realcomp && git pull --ff-only && git -C ../futari_decomp pull --ff-only && git status --short
# optional quiet gate: wait until mediaanalysisd/mds_stores/mdworker_shared are all < 5 % CPU for 60 s (top -l 1 | grep -E 'mediaanalysisd|mds_stores|mdworker')
nohup bash scripts/rc_cut_mac.sh 0.3.0-rc5 > ~/Desktop/projects/_rc/cut_0.3.0-rc5.out 2>&1 < /dev/null & disown
# wait on it with:   pgrep -f '[r]c_cut_mac.sh 0.3.0-rc5'      (NOT `pgrep -f rc_cut_mac.sh` — that matches the waiter itself)
```

The cut has no resume and stops on the first FAIL; a failed attempt's census bank is in `_local/rc/0_3_0_rc5/{census,chain}` and the
previous attempts are banked as `_local/rc/0_3_0_rc5_attempt{3,4,5,6}/` + `_rc/cut_0.3.0-rc5.attempt{1..6}.out`. Bank a failed attempt
the same way before relaunching (`mv _local/rc/0_3_0_rc5 _local/rc/0_3_0_rc5_attempt7; cp _rc/0.3.0-rc5/SMOKE.md …/SMOKE.attempt7.md`).

## 5. On ALL-PASS

1. Check `~/Desktop/projects/_rc/0.3.0-rc5/SMOKE.md` (every step PASS), the F&F zip + its sha256, and that tags `v0.3.0-rc5` (realcomp)
   and `realcomp-v0.3.0-rc5` (decomp) are on both remotes.
2. Stage the public macOS form: `bash scripts/rc_stage_mac_public.sh 0.3.0-rc5` then `bash scripts/rc_smoke_mac_public.sh 0.3.0-rc5`
   (asset-free, re-sealed ad hoc; expect the TCC prompt landmine on the re-signed .app, see STATUS 2026-11-03).
3. Record rc5 in STATUS.md / BACKLOG.md / NOTE (cut time, HEAD, zip shas, tags).
4. **STOP and ASK THE USER before uploading anything.** Upload is not approved for rc5. On a yes: new GitHub pre-release `v0.3.0-rc5`
   with the Windows public zip (sha above, on the PC at `_rc/`) + the macOS public zip + `.sha256` files; F&F zips to `Desktop/NSP`
   on the PC. Game data must never reach a public artefact (`rc_stage_*_public.sh` scan it; keep that).

## 6. Owed / parked (unchanged)

- User's hands checklist both seats (`RC1_HANDS_CHECKLIST.md`); verify the menu-bar Game Mode badge during the Mac hands run.
- Effective Spotlight Privacy exclusions (mdfind check above) and deleting `~/Desktop/projects/_trash_2026-11-03/` (user deletes).
- Game-Mode census variant (BACKLOG); q1_ctest bank `_local/rc1/...` (52 PNGs) and gstart `shot_*.png` still land in indexed folders.
- Landmines: `MSYS_NO_PATHCONV` (Windows launches); PowerShell-timed pad presses auto-repeat; `ssh mbp bash -s < /dev/null <<'EOF'`
  for remote bash (fish login shell); a docs commit on one seat makes the other seat's preflight refuse until pulled.
