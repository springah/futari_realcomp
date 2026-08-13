# Dumping your own copy

This port ships no game data. You provide it from a copy you own — a retail
**Mushihimesama Futari Ver. 1.5** disc (title ID `435A07D7`) and, optionally, the
**Black Label** DLC bought on that console.

Everything below reads data off hardware you own. Nothing here involves
downloading game files.

(Adapted from futari_recomp's `docs/DUMPING.md` — same game, same title ID, same
routes; only the extractor and layout differ.)

## What the port actually needs

| Goes in | What it is | Required |
|---------|-----------|----------|
| `assets\` | the disc contents — `default.xex` plus the `media\` tree | yes |
| `assets\media\Rom\cg_black*.bin` + `dropprm.bl` | the Black Label DLC's data, unpacked in place | no — only for Black Label mode |

Unlike futari_recomp there is no `dlc\` folder: the extractor unpacks the Black
Label package's contents directly into the `assets\media\Rom\` tree. The Ver 1.01
DLC contains **no game data** (it is an 11-byte unlock license); Ver 1.01's
archives ship on the disc, so Ver 1.01 works from any full dump.

## What you'll need

- Your Xbox 360 and the game disc.
- A way to read console-formatted (FATX) storage on a PC — either an **Xbox 360 HDD
  transfer cable / SATA-to-USB adapter** for the internal drive, or a **USB stick
  formatted by the console** that you copy content onto from the dashboard
  (*Settings → System → Storage*).
- On the PC: [FATXplorer](https://fatxplorer.eaton-works.com/) to browse FATX
  storage, and Python 3. The extractor reads the console's own formats directly,
  so no conversion tools are needed.

## Route A — the game installed on the console (easiest)

Install the disc to the console first (*Settings → System → Storage → select your
disc → Install*). The install — and any marketplace DLC bought on the console —
lives under one folder named after the game's title ID:

```
Content\0000000000000000\435A07D7\
├── 00007000\   the installed disc (a "Games on Demand" container)
└── 00000002\   the marketplace DLC packages, if you have them
```

1. Connect the console's drive (or the USB stick you copied the install onto) to
   your PC and open it in FATXplorer.
2. Copy the whole `435A07D7` folder out to your PC.
3. Drag that folder onto `tools\extract\extract_assets.bat` — or run:

   ```sh
   python tools/extract/futari_extract.py "path/to/435A07D7" --out assets --shell shell
   ```

The copy is verified against the container's own integrity hashes first (a bad
copy is caught immediately, with the file and block named), the game is extracted
into `assets\`, and every written file is checked against
`tools\extract\manifest_v1.tsv` before the tool reports success. A corrupt or
incomplete copy cannot slip through.

## Route B — dumping the disc directly

Reading an Xbox 360 disc at full size needs a PC optical drive whose firmware can
read the XGD layout, which in practice means a handful of specific Lite-On /
BenQ / Samsung models. If you have one set up, dump the disc to an ISO and drag
the `.iso` onto `extract_assets.bat`. If you don't, Route A is far less trouble —
a disc install reads the same data using the console's own drive.

## Black Label DLC

Point the tool at the package (or at an already-unpacked copy of it) after the
main extraction:

```sh
python tools/extract/futari_extract.py "path/to/00000002/496F816D..." --out assets
```

The retail package is ~264 MB; its three data files (`cg_black.bin`,
`cg_blackhi.bin`, `dropprm.bl`) land in `assets\media\Rom\`. The top menu greys
Black Label out until those files exist — the launch log says which way it went:

```
[xenum] DLC gate: entry 0 ('496F816D...') -> OWNED (data present)
```

## Checking you got the right files

The full ground truth is `tools\extract\manifest_v1.tsv` — path, size and SHA-256
for every file — and the extractor verifies against it on every run. To re-check
an existing tree without extracting anything:

```sh
python tools/extract/futari_extract.py --verify-only --out assets
```

## If something's wrong

- **"data block N fails its hash — the copy is corrupt"** — the copy off the
  console's storage went bad (loose adapter, interrupted copy). Nothing was
  harmed: re-copy the `435A07D7` folder and run it again.
- **"can't find the XDVDFS volume descriptor"** on an ISO — the file isn't a
  plain XDVDFS ISO; some dumps are split or truncated. `extract-xiso` is a useful
  second opinion.
- **Black Label stays greyed out** — look for the `[xenum] DLC gate` line in the
  session log; `MISSING` means `assets\media\Rom\cg_black.bin` / `cg_blackhi.bin`
  aren't there. Re-run the DLC step above.
- **Wrong title** — the extractor names the title ID it found vs `435A07D7`; you
  pointed it at a different game's folder.
