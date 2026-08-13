@echo off
setlocal enableextensions enabledelayedexpansion
title Mushihimesama Futari 1.5
echo ================================================================
echo  Mushihimesama Futari 1.5  (combined build)
echo ----------------------------------------------------------------
echo  ONE exe, BOTH modes: pick ARCADE 1.5 or XBOX 360 mode from the
echo  in-game top menu. Quitting back to the menu and picking the
echo  other mode hot-swaps the game module - no relaunch needed.
echo.
echo  Controls: START/Enter = start+confirm, A/Z = shot, B/X = bomb,
echo            D-pad/stick or arrows = move. XInput pad works.
echo            F11 = toggle fullscreen/windowed.
echo  Sound: in-game OPTIONS ^> SOUND sliders are the mixer.
echo  Settings/scores persist in the save folder next to this file.
echo ================================================================
echo.
REM HERE = this folder, no trailing backslash; all paths derive from it.
set "HERE=%~dp0"
if "%HERE:~-1%"=="\" set "HERE=%HERE:~0,-1%"
set "RT_GAME_ROOT=%HERE%\assets"

REM ---- FIRST RUN: this package ships NO game data. Build assets\ from YOUR dump.
REM      (Day-4 2026-08-13: tools\extract\ is the extractor; docs\DUMPING.md is the guide.)
if not exist "%HERE%\assets\default.xex" (
  echo ----------------------------------------------------------------
  echo  No game data found - assets\ is missing or incomplete.
  echo  This port ships NO game data. You need your own dump of
  echo  Mushihimesama Futari Ver 1.5 - Xbox 360, title ID 435A07D7.
  echo  docs\DUMPING.md explains how to copy it off your console.
  echo ----------------------------------------------------------------
  where python >nul 2>&1 || (
    echo  Python 3 is required for the extractor and was not found.
    echo  Install it from https://www.python.org/downloads/ and re-run.
    pause & exit /b 1 )
  set "SRC="
  set /p "SRC=Drag your dump (435A07D7 folder or .iso) onto this window, then Enter: "
  if "!SRC!"=="" ( echo No path given - exiting. & pause & exit /b 1 )
  set "SRC=!SRC:"=!"
  python "%HERE%\tools\extract\futari_extract.py" "!SRC!" --out "%HERE%\assets" --shell "%HERE%\shell" || (
    echo Extraction FAILED - see the messages above. Nothing was launched.
    pause & exit /b 1 )
  echo.
  echo  If you also own the Black Label DLC, drag its folder or package
  set "DLCSRC="
  set /p "DLCSRC=here now (or just press Enter to skip): "
  if not "!DLCSRC!"=="" (
    set "DLCSRC=!DLCSRC:"=!"
    python "%HERE%\tools\extract\futari_extract.py" "!DLCSRC!" --out "%HERE%\assets"
  )
  echo.
)

if not exist "%HERE%\save" (
  echo First run: creating a fresh save from the template...
  xcopy /E /I /Q /Y "%HERE%\save_freshcard" "%HERE%\save" >nul
)
if not exist "%HERE%\logs" mkdir "%HERE%\logs"
for /f "tokens=2 delims==" %%I in ('wmic os get localdatetime /value') do set DT=%%I
set "STAMP=%DT:~0,8%_%DT:~8,6%"
set "LOG=%HERE%\logs\futari_%STAMP%.log"
set "RT_SAVE=save"
set RT_BOOT_SHELL=1
set RT_THREADS=1
set RT_DEFERDRIVER=1
set RT_ASYNCIO=1
set RT_EHCONTAIN=1
set RT_AUDIOPUMP=1
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
echo  This session log: %LOG%
echo.
cd /d "%HERE%"
"%HERE%\futari_combined.exe" 8208A2B8 0 "shell\default.xex" 2>"%LOG%"
echo.
echo === session ended. log: %LOG% ===
pause
endlocal
