# Code review 2026-08-04 — stability sweep before beta2

Four-lane read-only review of the hand-written host layer (~26k lines: vk_render.cpp,
merged_*.cpp, nvk hooks, out_reco/rt.cpp + stubs, rt_audio/rt_xwma, module_registry,
moduleshim). Lenses: renderer lifetime/staleness, renderer concurrency, hook register
maps vs XDK signatures, kernel runtime + swap path. Findings marked ★VERIFIED were
re-checked line-by-line in the main session; the rest carry quoted evidence from the
review lane and should be re-verified at fix time.

**Headline: the 4th-swap hang is almost certainly a CONVERGENCE, not one bug.** Two
independent resource tables both cross their hard cap at exactly swap #4, and a third
defect fires in bursts on every swap. Separately, a certain resolve-flag misread is the
best candidate yet for both the random glitching and the missing-bake research item.

## A. The swap-hang family (beta2 opener)

1. ★VERIFIED [CRITICAL] **Bindless slot exhaustion at ~swap 4.**
   `g.rNextTexIndex` only increments (vk_render.cpp:2532, :2563, :2855, :3496); no site
   compares it to `kMaxBindlessImages` (1024) and nothing resets it. The swap consumer
   (:2980-3001) clears `texCache`/`g_resolveTex`/`rTexIndex` — forcing the whole working
   set (~250 slots incl. ~185 resolve targets + idxA1 siblings) into FRESH slots per
   module session. ~250×4 crosses 1024 at swap #3-4 → `vkUpdateDescriptorSets` with
   `dstArrayElement ≥ 1024` = OOB descriptor write → device fault. Matches the observed
   signature exactly (renderer dead, guest+audio alive).
   Also feeds without swaps: dim-changed resolve dst overwrites its map entry (:2536),
   orphaning image + slot.

2. ★VERIFIED [CRITICAL] **Thread table exhaustion at swap 4.**
   `g_thr[16]` (out_reco/rt.cpp:224); `used` set at :292 and NEVER cleared (comment:
   "16 slots, never reused"). Census from shipped logs: 7 shell threads at boot + 2 game
   threads per module attach → swap #4's second create hits `idx<0` (:291) and returns
   0xC0000001 with BOTH out-params (handle r3, tid r5) unwritten — the XMsgInProcessCall
   stub class, on the thread path. Guest reads stack garbage as a handle; the garbage
   handle then feeds the always-succeed unresolved-wait path (:880-886) = 1kHz spin.

3. ★VERIFIED [HIGH] **In-flight command-buffer/fence reset — bursts on every swap.**
   `getOrCreateResolveTex` (:2508) and `getNvkRT` (:10242) do
   `vkResetCommandBuffer(g.cmd)` + `vkResetFences(g.fence)` WITHOUT `rvkRingNext()`.
   `segBatchFlush()` (:363) only retires its own private segCmd/segFence — it does not
   clear `ringPending`. Eleven pass sites defer with `ringPending[g.ringIdx]=true`; a
   create call on that slot resets a pending buffer/fence (VUID-00045/-01123). Fires N
   times per swap (all RTs recreated) and occasionally in normal play = partially-landed
   draws → random glitching; on intolerant drivers → device loss.

4. ★VERIFIED [HIGH] **Mid-frame swap invalidation dangles `curRT`.**
   The swap request is consumed INSIDE `getTexIndexReal` (:2980), i.e. per-draw
   mid-frame; it calls `rvkSwapDropNvkRT()` → `g_nvkRT.clear()` (:10213) while `curRT`
   (raw pointer into that map, set :10749) is still used for
   framebuffer/renderpass/image for the rest of the frame (:10459-10538). Freed-heap
   reads on swap frames.

5. [HIGH] **No renderer quiesce on swap; ack is best-effort.**
   `rvk_module_swap_invalidate` polls ≤400ms for an ack that only lands if the worker
   happens to reach a texture lookup; on timeout module_registry proceeds to memset +
   re-image 8MB of guest memory concurrently with worker reads. Queued `g_rwQueue`
   RwJobs recorded from the OUTGOING module are then walked against re-imaged memory.
   Also: `g_regFile`/`g_vsConstF`/`g_psConstF` register shadow never reset on swap →
   stale fetch-constants (the black-flash upstream); `everRendered`/`renderedFrames`
   statics mean the incoming module composites onto the outgoing module's pixels
   (post-swap staleness), and drop-oldest + coalescing means stall damage outlives the
   stall as register-shadow skew.

6. [HIGH] **Failures are silent — the hang has no log line by design.**
   Submit results ignored then fence-waited (vk_render.cpp:372, :2520, :10254); every
   10s `rvkWaitFences` timeout swallowed and `ringPending` cleared as if success (:350);
   present path swallows DEVICE_LOST/acquire failures and retries forever (:4404,
   :4466) — never routes through the existing `rvkVkFatal`. Die-loud these first; they
   convert the mystery hang into a one-line diagnosis.

7. [HIGH] **Kernel objects have no module ownership; terminate orphans locks.**
   `NtClose` (out_reco/rt.cpp:774) frees only file handles — events/semaphores/thread
   handles leak forever. `ExTerminateThread` `_endthreadex`s without releasing held
   `g_locktab` mutexes; table keyed by guest address survives the swap, so the incoming
   module's `RtlEnterCriticalSection` at a reused address can block forever. Outgoing
   threads parked in infinite `NtWaitForSingleObjectEx` (:894) are never joined before
   re-image (the live out_reco copy lacks the RT_WAITMAX_MS watchdog the DEAD shell/gen
   copy has).

Repro instrumentation (cheap, do BEFORE fixing): log `g.rNextTexIndex` in
`rvk_module_swap_invalidate` + per-frame; grep hang logs for `ExCreateThread` count vs
`[thread] START` count; one FIFO-bounce run under VK_LAYER_KHRONOS_validation; log
`ringPending[ringIdx]` on entry to the two create paths; make fence timeouts print.

## B. Resolve semantics (random glitching + the missing-bake suspect)

8. ★VERIFIED [CRITICAL] **Colour-clear resolves silently dropped; clear flags swapped.**
   XDK d3d9types.h:222-223 (era-matched, authoritative):
   0x100 = CLEARRENDERTARGET "clear AFTER resolving", 0x200 = CLEARDEPTHSTENCIL.
   decomp/shell/nvk.cpp:469 `if (flags & 0x100) return;` treats 0x100 as "setup-only,
   no copy" — every clear-after-colour resolve NEVER REACHES the recorder → surface
   never updates. :481 sets `clearAfter` from 0x200 (a depth clear, no colour involved).
   Guest body (ppc_recomp.2.cpp loc_8807E130 area) shows the copy is unconditional and
   0x100 only ADDS a clear. Prime suspect for the six 512x512 bake pages reading 100%
   zero (a scroll-cache bake = resolve + clear-for-next-strip is exactly this shape).
   Fix: record the resolve always; clearAfter = (flags & 0x100); route 0x200 to a
   depth-clear if/when modeled.

9. [HIGH] **Clear colour read from the wrong argument.**
   nvk_game_hooks.cpp:54 reads `r1+0x64` (= arg 11, pParameters) as the clear colour.
   Per the Resolve signature, pClearColor is r10 and is a POINTER to a D3DVECTOR4
   (4 BE floats), not packed ARGB. Shell twin (shell/gen/rt.cpp:2937) hardcodes 0.
   Downstream `setClear(d.clearColor)` consumes ARGB — needs conversion.

## C. Link-order landmines (the /FORCE:MULTIPLE census)

10. [HIGH] **Renderer Resolve/Clear taps shadowed only by object order.**
    `sub_8807DD88`/`sub_8807D4F8` (+ `sub_8807A1E0`/`sub_8807A578`) are ALSO defined as
    dead debug wrappers in merged_game.cpp:3453-3454/:3510-3511. decomp_*.o links first
    today; one glob reorder in build_win.sh and the nvk renderer stops seeing game
    resolves with zero diagnostics. Delete the dead wrappers.
11. [MED] **Dead instruments that lie:** RT_VOICESTART/RT_VOICESTART2 probes in
    shell/gen/rt.cpp (:929/:969/:981) lose to merged_shell definitions — levers print
    nothing = "path not taken" trap. RT_XCFGTRACE lives in shell/gen/stubs.cpp but
    out_reco/stubs.cpp's traceless `ExGetXConfigSetting` wins — the ONE open
    stub-audit suspect cannot be observed in this build. Move traces to the winning TU.
12. NOTE: shell/gen/rt.cpp is NOT the live kernel for threads/files/semaphores —
    out_reco/rt.cpp + out_reco/stubs.cpp win those. shell/gen/harness.cpp is dead on
    Windows. Any fix must land in the WINNING TU (this review found one watchdog and
    one trace already applied to losing copies).

## D. Out-param stub class (live, ranked)

13. `XexGetModuleHandle` (merged_bridge.cpp:311): never writes *r4 (guest reads
    uninitialised stack as module handle) and returns 0=STATUS_SUCCESS on the FAILURE
    path. Guest call-site shape proven (ppc_recomp.23.cpp:24561+).
14. `NtCreateSemaphore`/`NtReleaseSemaphore` run the write-nothing no-op arm in SHIP
    config (RT_AUDIOSEM unset in dist bats); real impl sits right below, unused.
15. `ObReferenceObjectByHandle` returns SUCCESS + garbage *Object (called!).
16. `ExGetXConfigSetting` still returns SUCCESS writing nothing (called; video/timezone
    class) — and its tracer is dead (#11).
17. Lower: RtlTimeToTimeFields, VdGetCurrentDisplayInformation, XamContentGetCreator,
    XMsgStartIORequest (never signals its overlapped — dialog-wedge class),
    VdIsHSIOTrainingSucceeded (status inverted vs rexglue), __imp__sprintf (writes
    NOTHING — deserves die-loud). Struck as fixed: KeQuerySystemTime,
    MmQueryAddressProtect, RtlTryEnterCriticalSection, KeSetBasePriorityThread (verify
    live log prints bare `KeSetBasePriorityThread`, not `__imp__` form).

## E. Durability + misc

18. [HIGH] **Save writes are truncate-in-place** (out_reco/rt.cpp:579-624: OVERWRITE →
    "w+b", no temp+rename, no flush-to-disk). A kill during save (which the hang
    encourages!) destroys systemdata.bin. Fix: tmp + _commit + MoveFileEx REPLACE.
19. [MED] SDL3 sink has no device-loss detection — `g_live_state` latches 1 forever;
    device death degrades production to 250ms-timeout grants (~4Hz audio clock).
20. [MED] rt_xwma `rx_banks()` lazy population is unsynchronised (call_once needed).
21. [MED] Ship-enabled unconditional `fprintf`+`fflush` per call: merged_game.cpp
    JT-UNRESOLVED wrappers (:3595-3611, :3438-3441), `[scene] PUBLISH` (:148 — sibling
    is throttled, this isn't). Uncached `getenv` on hot paths: merged_shell.cpp:149/:157
    (pause-spin, ×2 per iteration!), merged_game.cpp:977 (input decode), :923.
22. [MED] `sub_820FD530` hook (merged_shell.cpp:724): RT_STREAMCLASS "diag" lever
    changes behaviour AND the reentrant call runs on the live ctx (clobbers r3 return).
    Same live-ctx issue in merged_game.cpp:1833/:2127 (RT_S5 — instrument not
    read-only). Divide-guard at merged_game.cpp:3651 writes guest state with no lever.
23. [LOW] Renderer never destroys anything (RSS staircase 371MB→1.98GB/26min banked);
    UPDATE_AFTER_BIND without UPDATE_UNUSED_WHILE_PENDING while mid-frame descriptor
    rewrites hit pending cmd buffers (glitch class); present-blit reads imageShow with
    no barrier coverage; semAcquire leaked on submit-failure return (F11 path);
    swapchain semaphores destroyed after only QueueWaitIdle; hand-rolled
    `__savegprlr_29` bodies restore only r30/r31 (r29/r12/lr gap — the documented
    sub_8808DA28 r26 class); message pump + F11 resize run under g_mtx (worker
    starvation); `gw.inited`/`g.ok`/`g_anyRender` plain-bool races.

## Suggested batches

- **Batch 1 (beta2 opener, = the hot-swap board):** A1 slot reset/cap + A2 thread-slot
  recycle + A3 ringNext at the two create sites + A4 move swap-consume to frame
  boundary + A6 die-loud. Gate: FIFO bounce ×6 swaps clean + fresh-boot field oracle.
- **Batch 2:** B8+B9 resolve semantics (may close the bake/water research item).
  Gate: full field oracle + user eyes on char-select + Score Attack end.
- **Batch 3 (cheap hygiene, near-zero risk):** C10 delete dead wrappers, C11 move
  traces to winning TUs, E21 lever/throttle the ship logs + cache getenvs.
- **Batch 4 (durability):** E18 atomic saves, D13/D14 out-params, A7 NtClose + module
  ownership.
