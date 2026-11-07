KNOWN ISSUES (release candidate; each is documented, not new)
  - A single frame of a menu element can be missing, always at the same moment: the PRESS START text for about half a second after you press START
    on the title, and one card-panel graphic when you press LEFT on the XBOX 360 card screen. The original game does this too (authentic, not a port
    bug). docs/NOTE_fnf_shell_defects.md, entry "RC1 Q9/G11".
  - XBOX 360 MODE "Now Loading" screen: for some button timings one kind of drifting ring sparkle is briefly absent (2-3 frames) between bursts;
    that is the original loading effect, not a missing element. docs/NOTE_fnf_shell_defects.md, entry "360 NOW-LOADING ring particles".
  - Menu flicker you can see in play but that the frame census cannot (a present-timing effect on some displays) is still an eyes-only item: if you
    see it, say WHERE (title, top menu, hub, in play) and on which display. docs/NOTE_fnf_shell_defects.md, 2026-07-28 flicker arc.
  - ARCADE mode memory grows to about 720 MB over the first ~20 minutes of a session and then stays flat (bounded, no crash seen in a 60-minute run).
    docs/PLAN_RC1.md section 2.1, Q5/Q6. From 0.3.0-rc3 on macOS/Linux the engine hands idle pool pages back and the ramp is flat (RT_POOLRELEASE,
    default on there; =0 reverts). WINDOWS: the same lever is on by default from 0.3.0-rc6 (owner ruling 2026-11-07; 12-minute
    ARCADE attract run: +32 MB with it vs +193 MB without, no audio or frame-rate cost); RT_POOLRELEASE=0 reverts to the rc5 allocator.
  - Five Xbox 360 system calls the game asks about (display info, display gamma, the system command buffer, the console config settings, the Xbox
    LIVE user id) are stand-ins, so the game reads placeholder values (time-zone names, display size). Nothing visible is known to depend on it.
    docs/AUDIT_kstub_sizes.md, PLAN_RC1 section 0.5.
  - (rc2 and earlier only; FIXED from 0.3.0-rc3) XBOX 360 MODE: the host START shortcut is wired to the ARCADE module's memory address, so it is inert there; START still works through the
    normal pad path, and no leak behind a menu was observed. PLAN_RC1 section 0.5 item 2.
  - (rc4 and earlier only; FIXED from 0.3.0-rc5) WINDOWS ONLY: in the attract (demo) loop the audio ring buffer logged short bursts of
    underruns at sound-effect-dense moments (instrumented, not audible: the user listened on 2026-10-29 and heard nothing). Cause: a host-side
    per-call environment lookup in the recompiled code's indirect-call path, paid thousands of times per compressed sound-effect packet;
    removed 2026-11-03, the 6-minute ARCADE census now reports 0 underruns. docs/NOTE_fnf_shell_defects.md entries "2026-11-02 WIN-AUDIO-1"
    and "2026-11-03 WIN-AUDIO-1 CLOSED".
  - B or Esc on the TITLE screen (PRESS START) quits the game cleanly from 0.3.0-rc4 (RT_NOTITLEQUIT=1 restores the old no-op); elsewhere B is
    still BACK / bomb and Esc is ignored.
  - Xbox LIVE is out of scope: sign-in, leaderboards and online play are not available (SCORE ATTACK shows the sign-in dialog; decline it).
  - FrameDelay 2V/3V (OPTIONS > GAME) paces correctly on macOS; 1V is the default and recommended.
  - If the window goes black mid-play and the app quits, it was a GPU device loss: send the log.
  - Fixed since beta 3, worth re-checking by eye: START in the hub or in OPTION no longer starts the game behind the shell (G-START); START at the
    CONTINUE? countdown now continues instead of opening PAUSE (DC-2: the START shortcut now waits for the shell's own pause check; fallback lever
    RT_STARTWIRE_RAWLEVEL=1 restores the old timing). docs/NOTE_fnf_shell_defects.md, G-START and DC-2 entries.
  - NEW in 0.3.0-rc6: all eight of the disc's game modes are hosted -- Ver 1.5 ARCADE and XBOX 360 MODE, Black Label ARCADE and XBOX 360 MODE (your DLC),
    and now Ver 1.01 ARCADE / XBOX 360 MODE, Arrange and Novice (disc data, no DLC). Each new mode was driven to game over and back to the top menu on both
    seats (docs/PLAN_other_modes.md section 6). Two things to listen and look for in the new modes: in Arrange and Novice the scripted runs heard no new
    music cue after the stage-1 track (no boss or game-over track); whether the original does the same is not yet known, so say if you hear music there.
    In Arrange, one NOW-LOADING-shaped sparkle dropout (2-3 frames) after the module switch is expected (the same effect as the XBOX 360 MODE note above).
  - NEW in 0.3.0-rc6: player settings live in futari.ini (Windows: next to the exe, created by the launcher; macOS: ~/Library/Application Support/Futari
    Realcomp/futari.ini). Settings.bat / Settings.command edit it; a lever set in the environment always wins over the file. Moving from futari_recomp:
    docs/SWITCHING_FROM_FUTARI_RECOMP.md (assets, DLC, saves and replays import as they are). Windows: starting full screen (display.fullscreen = true)
    is proven; pressing F11 to go back to the window size has not been checked by hand yet -- say if it misbehaves. macOS: F11 may need fn+F11.
  - From 0.3.0-rc6 the Windows engine also hands idle pool pages back (RT_POOLRELEASE on by default, as on macOS since rc3): ARCADE memory now stays
    near 400 MB instead of ramping to ~720 MB. RT_POOLRELEASE=0 restores the rc5 allocator if anything looks wrong.
