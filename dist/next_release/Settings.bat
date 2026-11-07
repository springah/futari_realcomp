@echo off
setlocal enableextensions
title Mushihimesama Futari - settings
REM Settings.bat (2026-11-07): edits futari.ini next to this file (window size, fullscreen, vsync, rotation,
REM keyboard, sound output, save folder). Game options are the game's own OPTIONS menus. Needs Python 3, like the
REM first-run extractor. Without Python: open futari.ini in Notepad -- every key is explained inside it.
set "HERE=%~dp0"
if "%HERE:~-1%"=="\" set "HERE=%HERE:~0,-1%"
if not exist "%HERE%\futari.ini" if exist "%HERE%\tools\settings\futari.ini.template" copy /Y "%HERE%\tools\settings\futari.ini.template" "%HERE%\futari.ini" >nul
where python >nul 2>&1 || (
  echo Python 3 was not found. Opening futari.ini in Notepad instead - every setting is explained inside.
  start "" notepad "%HERE%\futari.ini"
  exit /b 0 )
python "%HERE%\tools\settings\futari_settings.py" --ini "%HERE%\futari.ini" %*
echo.
echo The new settings apply the next time you start "Futari 1.5.bat".
pause
endlocal
