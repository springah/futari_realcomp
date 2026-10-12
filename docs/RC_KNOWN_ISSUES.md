KNOWN ISSUES (release candidate; each is documented, not new)
  - A single frame of a menu element can be missing, always at the same moment: the PRESS START text for about half a second after you press START
    on the title, and one card-panel graphic when you press LEFT on the XBOX 360 card screen. The original game does this too (authentic, not a port
    bug). docs/NOTE_fnf_shell_defects.md, entry "RC1 Q9/G11".
  - XBOX 360 MODE "Now Loading" screen: for some button timings one kind of drifting ring sparkle is briefly absent (2-3 frames) between bursts;
    that is the original loading effect, not a missing element. docs/NOTE_fnf_shell_defects.md, entry "360 NOW-LOADING ring particles".
  - Menu flicker you can see in play but that the frame census cannot (a present-timing effect on some displays) is still an eyes-only item: if you
    see it, say WHERE (title, top menu, hub, in play) and on which display. docs/NOTE_fnf_shell_defects.md, 2026-07-28 flicker arc.
  - ARCADE mode memory grows to about 720 MB over the first ~20 minutes of a session and then stays flat (bounded, no crash seen in a 60-minute run).
    docs/PLAN_RC1.md section 2.1, Q5/Q6.
  - Five Xbox 360 system calls the game asks about (display info, display gamma, the system command buffer, the console config settings, the Xbox
    LIVE user id) are stand-ins, so the game reads placeholder values (time-zone names, display size). Nothing visible is known to depend on it.
    docs/AUDIT_kstub_sizes.md, PLAN_RC1 section 0.5.
  - XBOX 360 MODE: the host START shortcut is wired to the ARCADE module's memory address, so it is inert there; START still works through the
    normal pad path, and no leak behind a menu was observed. PLAN_RC1 section 0.5 item 2.
  - Xbox LIVE is out of scope: sign-in, leaderboards and online play are not available (SCORE ATTACK shows the sign-in dialog; decline it).
  - FrameDelay 2V/3V (OPTIONS > GAME) paces correctly on macOS; 1V is the default and recommended.
  - If the window goes black mid-play and the app quits, it was a GPU device loss: send the log.
  - Fixed since beta 3, worth re-checking by eye: START in the hub or in OPTION no longer starts the game behind the shell (G-START); START at the
    CONTINUE? countdown now continues instead of opening PAUSE (DC-2: the START shortcut now waits for the shell's own pause check; fallback lever
    RT_STARTWIRE_RAWLEVEL=1 restores the old timing). docs/NOTE_fnf_shell_defects.md, G-START and DC-2 entries.
