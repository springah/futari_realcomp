# run_menu_win.ps1 — Windows equivalent of run_menu.sh: boot futari_merged.exe to the
# clean TOP MENU with the renderer calibration flags. Frames land in C:\tmp\rvk_last.png
# (+ rvk_frame*.png).
# 2026-07-12: the old wall-clock "0:START,5000:A,8000:A,11000:A" script (copied from Linux'
# run_menu.sh) was ~1/3 flaky here because the shell's boot-asset pump (sub_821CE400,
# [bootsm] cur76/want80) only accepts a title-skip START on a single-tick command-bit edge;
# a lone START pulse lands on an essentially random tick and usually misses it. See the
# matching comment + fix in run_hktrace.sh for the full root-cause writeup. Reusing the same
# empirically-verified mash-then-wait recipe here: spam START for ~13s, then confirm with A
# after an 11s+ gap. Sleep is extended to cover the longer script + settle time.
$ErrorActionPreference = 'SilentlyContinue'
Set-Location $PSScriptRoot
$root = $PSScriptRoot
Remove-Item C:\tmp\rvk_last.png, C:\tmp\rvk_frame*.png, C:\tmp\rvk_state.txt -Force
$env:RT_GAME_ROOT          = "$root\assets"
$env:RT_BOOT_SHELL=1; $env:RT_THREADS=1; $env:RT_DEFERDRIVER=1; $env:RT_ASYNCIO=1
$env:RT_EHCONTAIN=1; $env:RT_AUDIOPUMP=1; $env:RT_GAMEPUMP=1
$env:RT_VK=1; $env:RVK_PERSIST=1; $env:RVK_RENDER_FROM=1; $env:RVK_NOHALVE=1
$env:RVK_FIXVP=1; $env:RVK_REALALPHA=1; $env:RVK_BLEND=1
$env:RT_PAD=1; $env:RT_NAV_SEQ="0:STARTx26@500,24000:Ax10@1000"; $env:RT_PAD_HOST=1
$env:RT_SNDQFREE=1; $env:RT_NOPAUSE=1; $env:RT_RESCACHE=1; $env:RT_HEAPLOCK=1
$env:RT_SAMPLES=100000
$p = Start-Process .\futari_merged.exe -ArgumentList '8208A2B8','0','shell/default.xex' `
     -RedirectStandardOutput C:\tmp\futari_menu_win.log -RedirectStandardError C:\tmp\futari_menu_win.err -PassThru -NoNewWindow
Start-Sleep -Seconds 45
Stop-Process -Id $p.Id -Force
Get-Content C:\tmp\rvk_state.txt
