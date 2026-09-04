# STATUS — futari_realcomp (pointer, 2026-09-04)

**Where the live state is:** the campaign ledger in the sibling repo,
`../futari_decomp/docs/NOTE_campaign_decomp.md` (top block = current state, then the ranked
owed list for the next window). The scoreboard is `../futari_decomp/docs/progress_treemap.html`
(metric definitions: `PLAN_FULL_READABLE.md` §1.1 — headline is DONE = MATCHED+CONVERTED over
AUTHORED insns).

**This repo today (09-04):** the working native port — attract, menus, Normal Play, Training,
saves and native audio all run. Not shippable: the friends-and-family gate (07-26) is closed on
shell-compose fidelity (flicker), and the ratified fix is the shell compositor decomp. Game logic
has been untouched since 08-25; commits since then are harness-only instruments for the decomp
campaign. From r23-w86 realcomp carries a lane again (user ruling 09-04) — slate in the ledger.

**Hygiene conventions (09-04):** save directories for drives live under `_local/saves/`
(`RT_SAVE=_local/saves/save_<tag>`); only the three copy-from templates stay at the root
(`save_freshcard`, `save_r17_boss`, `save_eyeball`). Nothing under `_local/` is needed to build
or run.

The July asset-extraction prep note that used to live here is preserved unchanged at
`tools/extract/STATUS_day4_extract_prep.md`.
