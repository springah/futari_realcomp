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
echo  Window/vsync/keyboard settings: futari.ini (or Settings.bat).
echo ================================================================
echo.
REM HERE = this folder, no trailing backslash; all paths derive from it.
set "HERE=%~dp0"
if "%HERE:~-1%"=="\" set "HERE=%HERE:~0,-1%"

REM ---- futari.ini (2026-11-07): the player settings file. The engine reads it itself at start-up
REM      (host/futari_ini.h); this script only creates it from the template the first time.
if not exist "%HERE%\futari.ini" if exist "%HERE%\tools\settings\futari.ini.template" (
  copy /Y "%HERE%\tools\settings\futari.ini.template" "%HERE%\futari.ini" >nul
)

REM ---- game data: assets\ next to this file, unless futari.ini [storage] game_data names another folder
set "GAMEDATA=%HERE%\assets"
if not exist "%GAMEDATA%\default.xex" if exist "%HERE%\futari.ini" (
  where python >nul 2>&1 && for /f "usebackq delims=" %%G in (`python "%HERE%\tools\settings\futari_settings.py" --ini "%HERE%\futari.ini" --abs get storage.game_data 2^>nul`) do (
    if exist "%%G\default.xex" set "GAMEDATA=%%G"
  )
)

REM ---- FIRST RUN: this package ships NO game data. Build assets\ from YOUR dump (or from a futari_recomp install).
REM      (Day-4 2026-08-13: tools\extract\ is the extractor; docs\DUMPING.md is the guide.
REM       2026-11-07: a futari_recomp folder is accepted too -- docs\SWITCHING_FROM_FUTARI_RECOMP.md.)
if not exist "%GAMEDATA%\default.xex" (
  echo ----------------------------------------------------------------
  echo  No game data found - assets\ is missing or incomplete.
  echo  This port ships NO game data. You need your own dump of
  echo  Mushihimesama Futari Ver 1.5 - Xbox 360, title ID 435A07D7.
  echo  docs\DUMPING.md explains how to copy it off your console.
  echo  Already play futari_recomp? Drag ITS folder ^(the one with
  echo  futari.exe and assets^) instead: game data, DLC and save come over.
  echo ----------------------------------------------------------------
  where python >nul 2>&1 || (
    echo  Python 3 is required for the extractor and was not found.
    echo  Install it from https://www.python.org/downloads/ and re-run.
    pause & exit /b 1 )
  set "SRC="
  set /p "SRC=Drag your dump (435A07D7 folder or .iso) or futari_recomp folder onto this window, then Enter: "
  if "!SRC!"=="" ( echo No path given - exiting. & pause & exit /b 1 )
  set "SRC=!SRC:"=!"
  if "!SRC:~-1!"=="\" set "SRC=!SRC:~0,-1!"
  if exist "!SRC!\assets\default.xex" (
    echo.
    echo  That is a futari_recomp install. Its game data is linked ^(no extra disk space
    echo  on the same drive^) and its Black Label DLC is taken if it has it.
    set "IMPSAVE="
    set /p "IMPSAVE=Also bring over its save (settings, high scores, replay)? [Y/n]: "
    set "SAVEARGS=--saves-to "%HERE%\save""
    if /i "!IMPSAVE!"=="n" set "SAVEARGS="
    python "%HERE%\tools\extract\futari_extract.py" --from-recomp "!SRC!" --link --out "%HERE%\assets" --shell "%HERE%\shell" !SAVEARGS! || (
      echo Import FAILED - see the messages above. Nothing was launched.
      pause & exit /b 1 )
  ) else (
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
  )
  set "GAMEDATA=%HERE%\assets"
  echo.
  REM ---- settings step: window size, fullscreen, vsync, keyboard, save folder, written into futari.ini
  set "DOSET="
  set /p "DOSET=Change the display/input settings now (window size, fullscreen, vsync)? [y/N]: "
  if /i "!DOSET!"=="y" python "%HERE%\tools\settings\futari_settings.py" --ini "%HERE%\futari.ini"
  echo.
)

if not exist "%HERE%\save" (
  echo First run: creating a fresh save from the template...
  xcopy /E /I /Q /Y "%HERE%\save_freshcard" "%HERE%\save" >nul
)
if not exist "%HERE%\logs" mkdir "%HERE%\logs"
REM 2026-10-29: wmic is gone from Windows 11 24H2+, so the old `wmic os get localdatetime` stamp came back empty and
REM every session overwrote logsutari__.log. PowerShell is always present; fall back to %RANDOM% if even that fails.
set "STAMP="
for /f "usebackq delims=" %%I in (`powershell -NoProfile -Command "Get-Date -Format yyyyMMdd_HHmmss"`) do set "STAMP=%%I"
if not defined STAMP set "STAMP=session_%RANDOM%%RANDOM%"
set "LOG=%HERE%\logs\futari_%STAMP%.log"
REM Player-facing defaults: applied by the engine ONLY where neither the environment nor futari.ini decided
REM the variable (precedence: environment > futari.ini > these). Everything below them is the fixed engine set.
set "FUTARI_DEFAULTS=RT_GAME_ROOT=%HERE%\assets;RT_SAVE=save;RVK_WINSIZE=1920x1080;RT_PAD_HOST=1"
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
set RVK_DIMFIX=1
set RT_NAVREAL=1
set RT_STARTWIRE=1
set RT_SNDQFREE=1
set RT_RESCACHE=1
set RT_HEAPLOCK=1
set "SHELLXEX=shell\default.xex"
if not exist "%HERE%\%SHELLXEX%" set "SHELLXEX=%GAMEDATA%\default.xex"
echo  This session log: %LOG%
echo.
cd /d "%HERE%"
"%HERE%\futari_combined.exe" 8208A2B8 0 "%SHELLXEX%" 2>"%LOG%"
echo.
echo === session ended. log: %LOG% ===
pause
endlocal
