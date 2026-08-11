@echo off
setlocal
title Futari Realcomp - EYEBALL (repo build)
REM EYEBALL_0811 — successor to EYEBALL_0804 after the 08-07 restructure: the repo root is the
REM project folder, binaries live in build\, logs go to the gitignored _local\logs. Same audited
REM env otherwise. For the 360 card this build hosts BOTH modules (combined exe, mask 0x03).
set "HERE=%~dp0.."
for %%I in ("%HERE%") do set "HERE=%%~fI"
set "RT_GAME_ROOT=%HERE%\assets"
if not exist "%HERE%\save_eyeball" (
  echo Creating fresh eyeball save from template...
  xcopy /E /I /Q /Y "%HERE%\save_freshcard" "%HERE%\save_eyeball" >nul
)
if not exist "%HERE%\_local\logs" mkdir "%HERE%\_local\logs"
for /f "tokens=2 delims==" %%I in ('wmic os get localdatetime /value') do set DT=%%I
set "STAMP=%DT:~0,8%_%DT:~8,6%"
set "LOG=%HERE%\_local\logs\eyeball_%STAMP%.log"
set "RT_SAVE=save_eyeball"
set RT_BOOT_SHELL=1
set RT_THREADS=1
set RT_DEFERDRIVER=1
set RT_ASYNCIO=1
set RT_EHCONTAIN=1
set RT_AUDIOPUMP=1
set RT_GAMEPUMP=1
set RT_AUDIO=1
set RT_AUDIOWORKER=1
set RT_AUDIOBRIDGE=1
set RT_AUDIOXWMA=1
set RT_CUEBRIDGE=1
set RT_VK=1
set RT_NVK=2
set RVK_PERSIST=1
set RVK_RENDER_FROM=1
set RVK_NOHALVE=1
set RVK_FIXVP=1
set RVK_BLEND=1
set RVK_REALALPHA=1
set RT_WALLPAPER=1
set RVK_TEXPITCH=1
set RVK_FMT3KEY=1
set RVK_GPFIELD=1
set RVK_C255=0.00625:0.00390625:-1:0
set RVK_RESALIAS=1
set RVK_RESFRESH=1
set RVK_FIXB2=1
set RVK_RESREAL=1
set RVK_HDR=0
set RVK_WINDOW=1
set RVK_WINSIZE=1920x1080
set RVK_DIMFIX=1
set RT_NAVREAL=1
set RT_STARTWIRE=1
set RT_PAD_HOST=1
set RT_SNDQFREE=1
set RT_RESCACHE=1
set RT_HEAPLOCK=1
echo Session log: %LOG%
echo.
cd /d "%HERE%"
"%HERE%\build\futari_combined.exe" 8208A2B8 0 "shell\default.xex" 2>"%LOG%"
echo.
echo === session ended. log: %LOG% ===
pause
endlocal
