# RC1 hands checklist -- your own session on the RC bundle

Bundle: `~/Desktop/projects/_rc/<version>/Futari Realcomp.app` (open it from Finder; first launch: right-click > Open). Play it as a tester would.
Nothing needs screenshots: every step leaves its evidence on disk by itself.

- Session logs: `~/Library/Logs/Futari Realcomp/futari_*.log` (one per launch; newest = last session)
- Saves + replays: `~/Library/Application Support/Futari Realcomp/save` (settings, ranking, `replaydata.bin`)
- Build ids + hashes: `_rc/<version>/SMOKE.md`, `_rc/<version>/MACHO_MD5.txt`, and the README inside the bundle (Contents/Resources/README.txt)

Do the steps in order. Note anything odd in one line as you go (mode, what you were doing, where on screen).

1. **Eyes pass (2 min).** Title, top menu, card panel, hub: do the circles / PRESS START / logo flicker (known, say WHERE)? In the hub press
   START, then open OPTION and press START there: the shell menu must stay up and the game must NOT start behind it (G-START).
   Evidence: log has no `[navreal] d76 1->2` after those presses.
2. **ARCADE, Original, no cheats, 1-ALL.** Play through, SAVE THE REPLAY at the end, enter a ranking name, quit, relaunch, open
   Original Ranking: your name is there. Evidence: `replaydata.bin` grows in the save dir; the ranking is read back from `savegame.bin`.
3. **XBOX 360 MODE, same as 2.** Switch via the top menu (no relaunch needed), 1-ALL, save replay, name, relaunch, check Original Ranking.
4. **Game over -> CONTINUE (DC-2).** In Normal Play Original die on purpose once, press START at the CONTINUE? countdown: play must
   continue (no PAUSE menu). Do it in both modes. Evidence: `[pauseprobe]`/`GameEntry(msg=10` absent after the press.
5. **TRAINING twice in one session (DC-1).** Start TRAINING, play 20 s, pause, PREVIOUS MENU, start TRAINING again from the panel that
   reopens: it must enter the stage. Evidence: two `GameEntry(msg=18,` lines in one log.
6. **Couch co-op.** Two pads: join with P2 START at the character select, play 20 s, pause, resume. Do it once per mode if you can.
   Evidence: `[joinp] WILL-JOIN slot=1`.
7. **Quit with the app's own quit** (Cmd-Q or the window close button), not Force Quit. Evidence: the log ends with the exit marker, no
   `futari_merged` left in Activity Monitor.

Pass = 1-7 done with nothing in the "not allowed" classes of docs/PLAN_RC1.md section 6.7 (FATAL or hang, save loss, missing menu rows, wrong-mode
substitution, sprite/texture defect, missing audio, non-60 pacing). Known and fine: docs/RC_KNOWN_ISSUES.md.

## What to tell me
- Verdict per step (1-7): OK / odd / broken.
- Mode (ARCADE or XBOX 360), keyboard or pad (which pad), what you were doing, where on screen.
- The name of the newest log in `~/Library/Logs/Futari Realcomp/` (and the save folder untouched until I have read it).
- Then say "RC1 signed off" or list the broken steps; a fix means the next candidate is rc2.
