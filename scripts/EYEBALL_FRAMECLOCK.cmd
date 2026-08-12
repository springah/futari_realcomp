@echo off
REM EYEBALL_FRAMECLOCK — the 08-12 pacing-feel A/B: identical to EYEBALL_0811 (it delegates,
REM so the audited env can't drift) plus RT_FRAMECLOCK_VBLANK=1 — the dedicated 59.94Hz
REM frame-clock thread owns the frame grant on BOTH modules (abn + arcade seams, commit
REM 52317ba). Compare against the stock "Futari Realcomp" shortcut (welded baseline).
set RT_FRAMECLOCK_VBLANK=1
call "%~dp0EYEBALL_0811.cmd"
