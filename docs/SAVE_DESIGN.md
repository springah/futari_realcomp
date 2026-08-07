# Save-Data Subsystem — Design (read-only planning, not implemented)

Scope: replace ad-hoc XAM content/save stubs with host-directory-backed real saves,
and make boot deterministic (no blind timed A-presses through save dialogs).

## 0. Architecture context (must-know before touching anything)

`futari_merged` links **two** kernel trees with symbol arbitration via `objcopy
--weaken-symbol` (see `build_merged.sh`):

- **Game kernel** (`out_reco/rt.cpp` + `out_reco/stubs.cpp`) wins for the 59 imports
  shared between game/shell. It already has a **real, host-backed, READ-ONLY** NT
  file layer: `NtCreateFile`/`NtOpenFile`/`NtReadFile`/`NtQueryInformationFile`/
  `NtSetInformationFile`/`NtQueryVolumeInformationFile`/`NtQueryFullAttributesFile`/
  `NtClose` all work today, rooted at `RT_GAME_ROOT` (default `assets`). Handle range
  `0xF100..0xF140` (64 slots), table `g_files[64]` in `out_reco/rt.cpp:311`.
  `NtWriteFile` and `NtFlushBuffersFile` are still bare no-op stubs in
  `out_reco/stubs.cpp` — **writing has never been exercised in this codebase**.
- **Shell kernel** (`shell/gen/rt.cpp` + `shell/gen/stubs.cpp`) supplies the 108
  shell-only imports — this is where **every** `Xam*` content/UI function lives
  (the game module imports none of them; all save/UI flow is shell-driven).

Consequence for this design: the Xam layer (shell) and the NT file layer (game) are
different translation units linked with different symbol strength. The save
subsystem touches both: shell's `Xam*` stubs become the "mount" layer, and
`out_reco/rt.cpp`'s file layer needs write support + a second root.

There is already a working handle-table pattern to copy for any new object type:
`RtObj`/`rt_add`/`rt_get` (events, threads) in `shell/gen/rt.cpp` — same idea as
`g_files[]`, just polymorphic. New code should follow whichever pattern (flat array
vs RtObj) matches the file it lands in.

## 1. Call-site inventory

All in `shell/gen/stubs.cpp` unless noted. Line numbers as of 2026-07-12.

| Function | Args observed | Current stub behavior | Required real behavior |
|---|---|---|---|
| `XamShowDeviceSelectorUI` (:500) | user=0 type=0x1(SAVEGAME) flags=0x300 req=0x1E000 | Headless: `*devp=1`, broadcasts XN_SYS_UI open/close, completes overlapped SUCCESS+signals event, returns 997 | Keep headless pattern (correct); device_id must match the id used consistently by GetDeviceData below |
| `XamContentCreateEnumerator` (:142) | user,device,ctype,cflags,items_per,&bufsize,&handle | Allocates a fake handle (`0xE1000000+`), records `(type,consumed=0)` per handle, no real scan | For ctype==1 (SAVEGAME): scan the host save directory for a title save package and report items=1 if present, 0 if not |
| `XamEnumerate` (:192) | handle,flags,buf,buflen,&items_returned,overlapped | For type-2 (DLC) yields the 2 hardcoded packages; for type-1 (SAVE) **always returns SUCCESS+0 items** (i.e. "no save exists") | For type-1: if the enumerator (above) found a save package, write one XCONTENT_DATA record (device_id, content_type=1, display_name, file_name = save-id) then SUCCESS; else SUCCESS+0 as today |
| `XamContentCreateEx` (:152) | user,root_name,content_data(→ctype@+4),flags,&disposition,&license_mask,cache,size,overlapped | ctype==2 (DLC): returns 997 + completes overlapped, disposition=OPENED, license=1. **ctype==1 (SAVE): plain sync success (return 0), does nothing else** — `root_name` is read nowhere | For SAVE: create the host directory if disposition requests CREATE/CREATE_ALWAYS, register `root_name` → host save dir mapping (see §3), set disposition (OPENED vs CREATED), return sync success (comment at :157 says this must stay non-overlapped or the pre-menu flow loops — keep that) |
| `XamContentGetDeviceData` (:177) | device_id (r3), &X_CONTENT_DEVICE_DATA (r4) | **Always fills a dummy 20GB/3GB HDD record and returns 0**, regardless of device id | Must distinguish an **open/valid** device id (return 0 + real record) from a **closed/stale** one (return `0x48F`, no record) — see §2 for why this is load-bearing, not cosmetic |
| `XamContentClose` (:122) | handle | Returns 0, no bookkeeping | Release the enumerator/content-session entry; if it was the active SAVE mount, mark its device id "closed" so a subsequent `GetDeviceData` on that id fails (see §2) |
| `XamContentGetCreator` (:171) | — | Returns 0 (no output written) | Low priority; not observed on the critical path. Fill xuid=0/exists=0 if a struct pointer convention is confirmed later |
| `XamShowMessageBoxUIEx` (:520) | — | **Bare no-op**, returns 0 immediately. Never touches an overlapped, never signals an event | This is the "しますか？(Yes/No)" save-confirm dialog per `TITLE_SCREEN_NOTES.md:34-37`. Needs headless auto-answer: pick a button index (default "Yes"/index 0), complete the overlapped, signal the event — same pattern as `XamShowDeviceSelectorUI` |
| `XamShowSigninUI` | — | Bare no-op | Not on the observed save path (XamUserGetSigninState already reports user0 signed-in-locally); leave as-is unless a call site appears |
| `XamNotifyCreateListener` / `rt_notify_broadcast` (rt.cpp:387) | — | Real, working listener+queue model | No change needed; reuse `rt_notify_broadcast` for any new save-related notification ids if discovered |

Not present in the import table at all (confirmed via `imports_need.txt`):
`XamContentGetDeviceState`, `XamContentDelete`, `XamContentFlush`. The task brief's
mention of `XamContentGetDeviceState` does not apply to this title — skip it.

## 2. The confirm-path bug (already diagnosed by a prior agent, confirmed here)

`out_reco/merged/merged_xex.cpp:2603-2652` (`[gsel]` block) documents and the
`hktrace_run5_verified_20260712.log` reproduces the actual hang:

- Game-select confirm parks at a per-tick poll (`sub_821B7CC0` → `sub_821897C0` →
  `sub_82191A28`) that is trying to confirm a **storage-session release**: it only
  advances when `XamContentGetDeviceData(dev)` returns **nonzero** (error) for the
  *specific device id the session was using* — real XAM fails with `0x48F` for a
  stale/closed device. Our stub returns 0 (success) unconditionally, so the release
  never confirms, and the state machine free-spins forever incrementing
  `[bootsm] CE400#...` (confirmed live: `hktrace` log ends stuck at `cur76=6
  want80=5`, repeating every 600 ticks for 14000+ ticks — never posts `want80`).
- A diagnostic lever `RT_DEVFREE=1` exists (merged_xex.cpp:2617) that force-returns
  1 from `sub_821897C0` for one specific call site (`lr==0x821B7DF0`) — it is a
  **point hack for one call site**, not a fix to `GetDeviceData` itself, and it was
  not observed as invoked in the traced runs (grep found zero `RT_DEVFREE` log
  lines in either boot log or the hktrace log — the wedge is live in default runs).
- **Real fix**: give `XamContentGetDeviceData` actual session-validity semantics
  (open-set membership check), so *any* future caller — not just this one polling
  site — gets XAM-correct behavior. This also makes `RT_DEVFREE` unnecessary and
  removable once shipped.

## 3. Boot save-flow state machine (as observed)

```
title screen (START pressed)
  -> XamShowDeviceSelectorUI(type=1/SAVEGAME)                  [devsel] log
       real XAM: user picks a device; headless: device_id=1 always
  -> XamContentCreateEnumerator(dev=1,type=1,items=1) x1-3      [xenum] "content enumerator"
  -> XamEnumerate(handle) -> SUCCESS/0 items (today: ALWAYS "no save found")
  -> XamContentGetDeviceData(dev=1) -> dummy 20GB/3GB, id=1     [devdata]
  -> (2x more empty type-1 enumerators — game re-checks)
  -> XamContentCreateEx(type=2, DLC Black Label)  -> 997+OWNED  [content] DLC CreateEx
  -> XamContentCreateEx(type=2, DLC Ver1.01)      -> 997+OWNED
  -> XamContentClose
  -> [ ... boots into title/attract loop; TITLE_SCREEN_NOTES.md reports a stuck
       "しますか？" Yes/No save-create dialog at this point in some runs — XamShow-
       MessageBoxUIEx never completes, so any progress past it today is an accident
       of the synthetic-pad timing (RT_PAD) landing an A-press on whatever screen
       is showing, not a real dialog answer ]
  -> ... game-select screen reached, confirm pressed ...
  -> [gsel] 7CC0 per-tick poll: storage-session release check via GetDeviceData
       -> HANGS FOREVER today (see §2) — this is the "Now Loading" freeze
```

**No-save-exists path** (today, always, because the enumerator never finds
anything real): game proceeds past the empty enumerator into DLC checks; whether
it silently treats "0 items" as "make a fresh save" or just "no save, continue
without one" is unconfirmed — no type-1 `XamContentCreateEx` call was observed in
either boot log or the hktrace log (only the two type-2 DLC calls fire). This
means **the real save-create call site has never been reached in a traced run** —
it is downstream of the game-select confirm hang in §2. Treat this as an open
unknown to re-verify once §2 is fixed (see §6 testing plan, step 1).

**Valid-save-exists path**: not observed at all (no on-disk save has ever existed
for this title in this tree — `assets/` has no save-like directory; see §5).

## 4. Proposed host layout

```
<RT_SAVE_ROOT, default "save">/
  <titleid=435A07D7>/
    device1/                      # matches dummy device_id=1 from GetDeviceData
      savegame/                   # content_type=1 (SAVEGAME)
        <file_name>/              # 42-byte content-id string, same convention as
          data.bin                # the DLC entries in stubs.cpp:130-133 (unknown
          headers.bin             # exact name/shape until a real CreateEx(type=1)
                                   # call is captured — see §6 step 1)
```

Rationale: mirrors the existing DLC record shape (`device_id`, `content_type`,
`file_name`) already hardcoded in `stubs.cpp:130-133`, so the same
`XCONTENT_DATA`-shaped bookkeeping serves both DLC (read-only, baked-in) and SAVE
(read-write, host-backed) content types with one code path in the enumerator/
`CreateEx`/`GetDeviceData` trio. `device1` is a fixed subdir (not literally the
device id number bit-packed) purely for host-side readability.

**Device-data semantics** (`XamContentGetDeviceData`, the load-bearing part):
- Maintain a small `std::set<uint32_t>` (or similar) of **currently-open** device
  sessions, populated by `XamShowDeviceSelectorUI`/`XamContentCreateEx` success and
  erased by `XamContentClose`.
- `device_id = 1` (HDD), `total_bytes = 0x500000000` (20GB), `free_bytes =
  0xC0000000` (3GB) — keep these existing dummy values (they already "always
  satisfy" any free-space threshold check; no evidence in the logs of the game
  reading free_bytes for a decision, only that the *record itself* must be
  well-formed, which it already is).
- Return **0** (success, filled record) if `device_id` is in the open-set.
  Return **0x48F** (no record written, matches real-hardware stale-device error
  per the merged_xex.cpp comment) if it is not — this is what unblocks §2 without
  the `RT_DEVFREE` point-hack.

## 5. API-by-API implementation spec

Overlapped/async completion convention already established and must be reused
exactly (see `XamShowDeviceSelectorUI` at :500 and the DLC branch of
`XamContentCreateEx` at :152): write `ov+0x00=status`, `ov+0x04=length/info`,
`ov+0x18=extended_error`, then `NtSetEvent` on `ov+0x0C` if nonzero, then return
997 (`ERROR_IO_PENDING`) to the caller. Non-overlapped calls just return the
status directly in r3. **Do not** make the SAVE-type `XamContentCreateEx` go
overlapped — the existing comment at stubs.cpp:157 explicitly warns this loops the
pre-menu flow; keep it synchronous.

- `XamContentCreateEnumerator(type=1)`: `stat()`/`opendir()` the host save dir for
  this title; if a package directory exists, remember "1 real save available" on
  the enumerator record (extend `g_enumType[]`/`g_enumConsumed[]` with a bool);
  else behave as today (empty).
- `XamEnumerate` (type=1 branch): if the enumerator found a save, emit one
  XCONTENT_DATA record (reuse the exact field layout already used for DLC at
  stubs.cpp:201-210: device_id@0, content_type@4, display_name utf16@8,
  file_name@0x108) with content_type=1; else SUCCESS+0 as today.
- `XamContentCreateEx(type=1)`: read `disposition` request semantics from flags
  (CREATE vs OPEN vs OPEN_ALWAYS — exact bit meanings TBD, standard XAM
  disposition values apply); `mkdir -p` the host directory if creating; register
  `root_name` (r4, currently ignored) in a small map `string -> host dir`; add
  `device_id` to the open-set from §4; write `*disposition` (1=CREATED/2=OPENED),
  return sync 0 (not overlapped, not 997).
- File I/O against the mounted root: teach `rt_open_host()`
  (`out_reco/rt.cpp:322`) to check the registered root_name map **before** falling
  through to the `RT_GAME_ROOT`-relative logic, and to open in `"r+b"`/`"w+b"`
  (create) instead of `"rb"` when the path resolves under a save root. Add real
  `NtWriteFile` (mirror `NtReadFile`'s structure at :355, `fwrite` instead of
  `fread`, extend the sync/pending logic identically) and `NtFlushBuffersFile`
  (`fflush`) in `out_reco/stubs.cpp` → promote both out of stubs.cpp into rt.cpp
  alongside `NtReadFile`.
- `XamContentGetDeviceData`: open-set check per §4.
- `XamContentClose`: erase enumerator/session bookkeeping; if it was the SAVE
  mount, remove `device_id` from the open-set (this is the trigger that lets §2's
  poll succeed).
- `XamShowMessageBoxUIEx`: headless auto-answer. Args are unconfirmed (never
  logged — add a one-time arg dump on first call before implementing); assume the
  standard XAM signature (title,text,button_count,button_ptrs,default,&result,
  overlapped) and default to selecting index 0 (typically "Yes"/"OK"), complete
  overlapped per the standard pattern above.

## 6. Seeding strategy

**Recommend: let the game create its own first save** via the now-real write path,
rather than importing a save from the SDK/Xenia. Reasons: (a) no evidence any
emulator/SDK save for this exact title+region is on hand, and importing a
foreign-format save risks checksum/version mismatches the game's own loader would
reject; (b) the whole point of this subsystem is that `XamContentCreateEx`
CREATE + `NtWriteFile` now work, so exercising that path on first boot is also the
integration test. Empty `save/` directory on first run -> enumerator reports 0
items -> game (presumably) offers/does a create -> `XamContentCreateEx` makes the
directory -> subsequent writes populate it -> second boot's enumerator finds it.

Fallback if the game turns out not to auto-create (e.g. it only *reads* and
expects the platform/dashboard to have created the container beforehand, which is
how real XAM often works): pre-create an empty but well-formed directory +
zero-length placeholder files matching whatever shape is captured in testing
step 1 below, so the enumerator's "exists" check passes trivially even with no
real payload yet.

## 7. Migration / testing plan

- **Lever**: `RT_SAVE_ROOT=<path>` (default `save`, same convention as
  `RT_GAME_ROOT`), gates the new mount/write code paths so a build without it set
  still behaves like today (empty enumerator, no writes) for safe bisection.
- **Step 1 (must happen before finishing the CreateEx/GetDeviceData write-up
  above)**: run with `RT_TRACEIMP=1` and instrument the currently-blind
  `XamShowMessageBoxUIEx`/type-1 `XamContentCreateEx` call sites to dump their raw
  register args once, driven through the currently-stuck confirm point using the
  existing `RT_DEVFREE=1` diagnostic lever to get *past* §2's hang far enough to
  observe what a real save-create call looks like. This closes the "unconfirmed
  root_name / disposition bit / message-box args" gaps flagged above.
- **Step 2**: boot with `RT_SAVE_ROOT` pointed at an empty temp dir -> confirm the
  game reaches the TOP MENU with **zero or one** synthetic A-press for the save
  dialog (down from the current blind-timed-press sequence) -> confirm a save
  directory now exists on host disk.
  boot with the SAME dir -> confirm the enumerator reports 1 item, `GetDeviceData`
  round-trips through the open/close lifecycle without the `[bootsm]` free-spin,
  and no create-dialog is shown (silent load).
- **What could regress**: the existing `RT_NAV_SEQ`/`RT_PAD_STARTONCE`/timed A-press
  recipes (stubs.cpp:262-320) assume specific dialogs appear at specific wall-clock
  offsets; once dialogs auto-answer headlessly (message box) or disappear
  entirely (silent load on 2nd boot), those fixed-timing scripts will press A into
  the wrong screen. Recipes will need re-tuning per boot-log observation, not a
  code change — flag this to whoever owns `RT_NAV_SEQ` before landing.
- Remove `RT_DEVFREE` once `GetDeviceData`'s open-set fix (§4) is shipped and
  verified to unblock §2 without it.

## 8. Estimated size of change

- `shell/gen/stubs.cpp`: ~120-180 LOC changed/added (5 functions: enumerator,
  XamEnumerate save branch, CreateEx save branch, GetDeviceData, Close,
  MessageBoxUIEx) + a small open-set/session map (~20 LOC) + a root_name map
  (~15 LOC).
- `out_reco/rt.cpp`: ~60-90 LOC (real `NtWriteFile` mirroring `NtReadFile`, real
  `NtFlushBuffersFile`, `mkdir -p` helper, root_name-aware `rt_open_host`
  extension, write-mode `fopen`).
- `out_reco/stubs.cpp`: delete the 2 promoted stub lines (`NtWriteFile`,
  `NtFlushBuffersFile`).
- `futari_switches.toml`: register the new `RT_SAVE_ROOT` lever (and remove
  `RT_DEVFREE` once superseded) — a few lines.
- No changes needed to `out_reco/merged/merged_xex.cpp` beyond eventually
  deleting the `RT_DEVFREE` workaround block (~35 LOC removed) once verified.

Total: roughly **200-280 LOC net across 3-4 files**, plus one manual instrumented
run (step 1) to fill the two remaining unknowns (message-box arg layout,
type-1 CreateEx disposition/root_name values) before the implementation can be
written with full confidence instead of best-guess XAM defaults.
