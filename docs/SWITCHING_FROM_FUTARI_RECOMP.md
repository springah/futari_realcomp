# Switching from futari_recomp to futari_realcomp

Two separate ports of the same game (Mushihimesama Futari Ver 1.5, Xbox 360, title `435A07D7`) by the same owner, both
maintained:

- **futari_recomp** (github.com/springah/futari_recomp): the game's code recompiled onto the rexglue SDK, a
  Xenia-derived runtime (kernel, emulated Xenos GPU, XMA audio). Optional Renut renderer.
- **futari_realcomp** (this project): the game's code recompiled onto a small hand-written kernel and a native Vulkan
  renderer, on the way to a matching decompilation.

You can keep both installed. Nothing below writes into futari_recomp's folders; the importer only reads them.

## Quick start

**Windows.** Unzip the realcomp release anywhere. Double-click `Futari 1.5.bat`. When it asks for your dump, drag the
**futari_recomp folder** (the one holding `futari.exe` and `assets\`) into the window and press Enter, then answer `Y` to
bring over your save. It links the game data (no second 1 GB copy on the same drive; a copy on another drive), takes the
Black Label DLC futari_recomp installed, checks everything against the 58-file manifest, and starts the game. Python 3 is
needed for this one step, as for any first run.

**macOS.** Unzip, double-click `Extract Game Data.command`, choose **Console folder...** and pick the folder that holds
your `Futari-<version>.app` (futari_recomp keeps its game data inside the app). Say Yes to the save question.

**Command line** (either platform, from the realcomp folder):

```sh
python tools/extract/futari_extract.py --from-recomp "<futari_recomp folder or .app>" --link \
    --out assets --shell shell --saves-to save              # Windows release layout
python3 tools/extract/futari_extract.py --from-recomp "/Applications/Futari-1.5.7.app" --link --out assets \
    --saves-to "$HOME/Library/Application Support/Futari Realcomp/save"   # macOS
```

`--saves-only` imports just the save, `--dry-run` shows what would be imported, `--profile <16 hex digits>` picks a
profile when there are several, `--recomp-user-data <dir>` points at futari_recomp's save folder when it is not the
default.

## What carries over

| | futari_recomp keeps it in | realcomp needs it in | carried over by |
|---|---|---|---|
| game data | `assets\` next to `futari.exe` (macOS: `Futari-<v>.app/Contents/MacOS/assets`): the whole extracted disc | `assets\` next to the exe / the app: 58 files checked against `tools/extract/manifest_v1.tsv` | the importer: recomp's `assets\` is an already-extracted disc; realcomp adds one derived copy (`reco_normal.xex`) and `shell\default.xex` (Windows), then verifies every file by SHA-256 |
| Black Label DLC | raw packages in `dlc\` beside the exe, which it installs on first launch into its user-data folder as `0000000000000000\435A07D7\00000002\496F816D...\Rom\` | three files in `assets/media/Rom/` (`cg_black.bin`, `cg_blackhi.bin`, `dropprm.bl`) | the importer unpacks `dlc\` packages and copies the installed copy; either is enough |
| save (options, high scores, unlocks) | user-data folder `<profile>\435A07D7\00000001\systemdata.bin\savegame.bin` | `<save folder>\435A07D7\00000001\systemdata.bin\savegame.bin` | `--saves-to`: a straight copy (same game code wrote both; same 8192-byte container) |
| saved replay | `...\00000001\replaydata.bin\replaydata.bin` | same, under the save folder | the same copy |
| settings (`futari.ini`) | next to `futari.exe` | realcomp's own `futari.ini` (different keys) | not converted: see the table below |

futari_recomp's user-data folder is `[Storage] user_data_path` from its `futari.ini` if set, else `Documents\futari` on
Windows and `~/futari` (or `$XDG_DATA_HOME/futari`) on macOS. `<profile>` is a 16-hex-digit folder (the SDK's profile id).
The SDK also writes a `Headers\` folder beside the save; realcomp does not use it and the importer skips it.

What was checked (Windows, 2026-11-07, copies of a real futari_recomp save, never the original): the importer copies the
two items byte for byte; realcomp enumerates both, opens `savegame.bin` and boots past the title without rewriting it; the
replay plays (below). What was not: that every option and score shows up as it was in futari_recomp (look at OPTIONS and
the ranking once after importing). A deliberately corrupted copy was also read without complaint at boot, so the boot
alone does not prove the game checked the contents.

A save already in realcomp's save folder is never deleted: the importer renames `435A07D7\00000001` to
`00000001.before-recomp-import-<date>` first.

**The replay** records the profile it was made under: futari_recomp's replay carries the gamer name `User` and the
profile id `B13EBABEBABEBABE` (offsets 0x320-0x347 in the samples looked at); realcomp's carry `Player1` and 0. realcomp
plays it anyway: checked 2026-11-07 on Windows with a copy of a futari_recomp save (REPLAY DATA, slot 1: the playback
starts, `GameEntry(msg=17)`, the stage runs and ends on the replay's own game over; evidence in the w1107 config lane's
`_local/rc/w1107_cfg/t4_replay_recomp/`). Not checked on macOS.

**Going back** (realcomp save into futari_recomp) is the same copy in reverse, into
`<user data>\<profile>\435A07D7\00000001\`. Not scripted and not tested; futari_recomp also expects its `Headers\` files,
so keep its own `Headers\` folder in place.

## Settings: futari_recomp key -> realcomp key

| futari_recomp `futari.ini` | realcomp `futari.ini` | note |
|---|---|---|
| `[Display] resolution` | `[display] window_size` | same `WxH` meaning (window size; the game is scaled into it) |
| `[Display] fullscreen` | `[display] fullscreen` | realcomp: borderless fullscreen; F11 toggles in both |
| `[Display] present_vsync` | `[display] vsync` | realcomp `auto` (the default) = Vulkan MAILBOX where offered: tear-free and does not block |
| `[Display] vsync`, `refresh_rate` | none | realcomp paces the game with its own 60 Hz clock |
| `futari_renderer`, `renut_vsync` | none | realcomp has one renderer |
| `[Display] letterbox` | none | realcomp always fits the 16:9 picture into the window |
| `[Graphics] upscaler`, `cas_sharpness`, `dither` | none | |
| `[Storage] user_data_path` | `[storage] save_dir` | realcomp's folder holds only the save (no profile level, no cache) |
| `[Storage] cache_path` | none | realcomp has no shader cache to place |
| `[Diagnostics] log_level` | none | realcomp always writes its full log to `logs\` (Windows) / `~/Library/Logs/Futari Realcomp/` |
| (no equivalent) | `[display] rotate`, `gpu`, `f11_fullscreen`; `[audio] sink`; `[input] keyboard`, `background_input`, `xinput`; `[storage] game_data`, `dlc_dir`; `[memory] pool_release_ms`; `[env]` | each line in realcomp's `futari.ini` names the engine variable it sets |

Both games keep the game's own options (difficulty, buttons, TATE/yoko, volumes) in the save, so those come over with it.

## What differs

- **Modes.** futari_recomp runs all 8 game modules. realcomp hosts 4: ARCADE (1.5 Original), XBOX 360 MODE, and Black
  Label ARCADE and XBOX 360 MODE (with your DLC). Arrange, Novice and Ver 1.01 ARCADE / XBOX 360 stay greyed in
  realcomp's menu until those modules are brought up.
- **Platforms.** Both: Windows 10/11 64-bit and macOS on Apple silicon. Neither ships Linux / Steam Deck builds now
  (for futari_recomp, futari-linux by cerroverb is the Linux port; realcomp's Deck build is a developer-only script).
- **Renderer and GPU.** realcomp needs a Vulkan 1.1 driver on Windows (MoltenVK, bundled, on macOS); futari_recomp's
  default renderer is Direct3D 12 on Windows.
- **Settings screen.** futari_recomp has one in the game (F2). realcomp has `futari.ini`, `Settings.bat` /
  `Settings.command`, and a settings question in the first-run wizard; an in-game screen is a proposal
  (`docs/DESIGN_settings_overlay.md`).
- **First run.** realcomp's extractor is a Python script (Python 3 on Windows, 3.10+ on macOS); futari_recomp's is
  built into its exe.
- **Where things live.** realcomp on Windows keeps saves in `save\` and logs in `logs\` next to the exe; on macOS in
  `~/Library/Application Support/Futari Realcomp/` (save, futari.ini) and `~/Library/Logs/Futari Realcomp/`.
- **Quitting.** realcomp: the window's close button, Cmd-Q on macOS, or B / Esc on the title screen.
- **Xbox LIVE.** Neither port has it.

## Known gaps

- Only 4 of the 8 modes (above).
- Importing a save was checked on Windows only; the macOS paths (futari_recomp `~/futari`, realcomp
  `~/Library/Application Support/Futari Realcomp/save`, `Extract Game Data.command`) follow the same code but were not run.
- A futari_recomp install whose game data lives somewhere other than `assets/` (its `--game_data_root` option) is not
  found by `--from-recomp`; pass that folder as the extractor's ordinary input instead (it is an already-extracted
  disc), and the DLC folder as a second run.
- realcomp release candidates are test builds: `docs/RC_KNOWN_ISSUES.md`.
