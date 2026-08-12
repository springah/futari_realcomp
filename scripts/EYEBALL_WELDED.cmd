@echo off
REM EYEBALL_WELDED — the A/B fallback since the 08-13 Day-1 default flip: the stock launcher
REM (EYEBALL_0811, "Futari Realcomp" shortcut) now runs the dedicated 59.94Hz frame clock BY
REM DEFAULT; this wrapper pins RT_FRAMECLOCK_VBLANK=0 to get the old welded present-path clock
REM for comparison. Supersedes EYEBALL_FRAMECLOCK.cmd (whose lever is now the default).
set RT_FRAMECLOCK_VBLANK=0
call "%~dp0EYEBALL_0811.cmd"
