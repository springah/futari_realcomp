@echo off
rem ===========================================================================
rem  Mushihimesama Futari 1.5 (realcomp) - asset extractor
rem
rem  This port ships no game data. Supply your own copy: drag any of these
rem  onto this file:
rem    - the game folder copied off your console's storage (the "435A07D7"
rem      folder, or anything above it) - the copy is verified against the
rem      console's own integrity hashes first, and your Black Label DLC is
rem      unpacked in the same pass
rem    - your Xbox 360 disc ISO
rem    - a folder where you already extracted the disc
rem
rem  It builds "assets\" next to the game exe - the tree the port reads via
rem  RT_GAME_ROOT - and stages shell\default.xex. Everything it writes is
rem  checked against tools\extract\manifest_v1.tsv before it reports success.
rem
rem  Requires Python 3 (https://www.python.org/downloads/). Thin wrapper
rem  around futari_extract.py.
rem ===========================================================================
setlocal enableextensions
title Mushihimesama Futari 1.5 - Asset Extractor

rem Work from the game root. In the repo this script lives in tools\extract\;
rem in a release zip it sits next to the exe. Handle both.
set "HERE=%~dp0"
if "%HERE:~-1%"=="\" set "HERE=%HERE:~0,-1%"
set "EXTRACTOR="
if exist "%HERE%\futari_extract.py" set "EXTRACTOR=%HERE%\futari_extract.py"
if not defined EXTRACTOR if exist "%HERE%\tools\extract\futari_extract.py" set "EXTRACTOR=%HERE%\tools\extract\futari_extract.py"
if not defined EXTRACTOR (
    echo [ERROR] Could not find futari_extract.py.
    echo         Keep this .bat together with the extractor and its manifest.
    goto :end
)

rem Game root = the folder holding the exe. If we are in tools\extract\, go up two.
set "ROOT=%HERE%"
if exist "%HERE%\tools\extract\futari_extract.py" goto :haveroot
for %%I in ("%HERE%\..\..") do set "ROOT=%%~fI"
:haveroot

rem Find a Python 3 interpreter: prefer the py launcher, then python on PATH.
set "PY="
where py >nul 2>&1
if %errorlevel%==0 set "PY=py -3"
where python >nul 2>&1
if %errorlevel%==0 if not defined PY set "PY=python"
if not defined PY (
    echo [ERROR] Python 3 was not found on this PC.
    echo         Install it from https://www.python.org/downloads/
    echo         ^(tick "Add python.exe to PATH" in the installer^), then re-run this.
    goto :end
)

echo.
if "%~1"=="" (
    echo Nothing was dragged on - looking for a .iso in this folder...
    echo ^(Drag on the "435A07D7" folder copied off your console, or your disc ISO.^)
) else (
    echo Extracting from: %~1
)
echo Output: %ROOT%\assets
echo.

%PY% "%EXTRACTOR%" %1 --out "%ROOT%\assets" --shell "%ROOT%\shell"
set "RC=%errorlevel%"

echo.
if not "%RC%"=="0" (
    echo [FAILED] Extraction did not complete - see the messages above.
    echo          Nothing was harmed; fix the input and run this again.
) else (
    echo [DONE] assets\ matches the reference manifest. You can now run the game.
)

:end
echo.
pause
endlocal
