# AUDIT_kstub_sizes.md — host kernel/XAM stub write sizes vs the real structures (KSTUB-OVERCLEAR, 2026-10-12)

Trigger: r23-w156H (futari_decomp `docs/PLAN_diffharness.md` §9.1, debt D1) found `__imp__XGetVideoMode` zero-filling
0x50 bytes into a 0x30-byte guest buffer, wiping the caller's saved non-volatile registers. This audit lists every host stub
that WRITES into a guest pointer argument, the bytes it writes, and the size of the real structure (XDK / Xenia
`src/xenia/xbox.h`, `kernel/xboxkrnl/*`, `kernel/xam/*` as the public reference; rexglue where the stub cites it).

Scope (what the Mac builds compile): `shell/gen/rt.cpp`, `shell/gen/stubs.cpp` (host `shellkernel_*`), the game-tree kernel
copies `out_reco/rt.cpp`, `out_reco/stubs.cpp`, `out_reco/harness.cpp`, `out_reco/rt_phys.cpp` (host `game_*`, LINK FIRST:
for the 66 shared `__imp__X` the game copy wins, the shell copy is renamed away — `dup_renames.txt`), `out_reco/merged/*.cpp`,
`host/*.cpp`/`host/*.inc`. `out_reco_abn/rt.cpp` is compiled by no script (dead twin) but was kept in step.

Verdicts: **OK** = writes == the real size (or is bounded by a caller-supplied length); **OVER** = writes more than the real
structure; **UNDER** = the real kernel writes an output the stub leaves untouched; **UNKNOWN** = no public layout / not decided.
"dead" = that copy loses the link (the other file's copy runs).

## 1. OVER — fixed in this window

| stub | file:line | wrote | real size (source) | callers / what the extra bytes hit | verdict |
|---|---|---|---|---|---|
| XGetVideoMode | shell/gen/rt.cpp:220 | 0x50 | XVIDEO_MODE = X_VIDEO_MODE 48 = 0x30 (Xenia xbox.h `static_assert_size(X_VIDEO_MODE, 48)`) | 5 shell callers, every one reserves exactly 0x30 directly below its save area: 8216AD98 r1+112 (f31/r26/r27/r28 saves zeroed — the w156H D1 r28), 8216EBE8 r1+144 (r25-r28), 82181C60 r1+128 (r29-r31 + LR slot), 82185758 r1+80 (r31 + LR slot + 16 B of the parent frame header), 821CB2E0 r1+96 (LR slot + parent back chain) | **OVER → fixed (0x30)** |
| VdQueryVideoMode (game copy, the one that links) | out_reco/rt.cpp:104 | 0x50 | X_VIDEO_MODE 0x30 (same; Xenia xboxkrnl_video.cc memsets sizeof) | 3 shell callers: 820B0890 r1+112 (its saved f30/f31/r14 at r1+168..192 zeroed), 820AB1D0 r1+80 (32 B of locals r1+128..160), 820AEC38 device+21912 (32 B of the D3D device object past the mode struct) | **OVER → fixed (0x30)** |
| VdQueryVideoMode (abn twin) | out_reco_abn/rt.cpp:89 | 0x50 | 0x30 | not compiled by any build script | OVER → fixed for consistency |

Field values are unchanged (XGetVideoMode still writes 1280/720/0/1/1/60.0f/1 at 0x00..0x18 and zeros 0x1C..0x2F;
VdQueryVideoMode still zero-fills unless RT_HDMODE). Xenia additionally sets unknown_0x8a = 0x4A and unknown_0x01 = 1 —
deliberately NOT adopted (behaviour-preserving fix).

## 2. OK — size matches the real structure (or is bounded by the caller's length)

| stub | file:line | wrote | real size (source) | verdict |
|---|---|---|---|---|
| NtAllocateVirtualMemory | shell/gen/rt.cpp:46 (dead) · out_reco/rt.cpp:134 | *base 4, *size 4 | PVOID / SIZE_T, 4 + 4 | OK |
| RtlInitAnsiString | shell/gen/rt.cpp:84 (dead) · out_reco/rt.cpp:440 | 8 | ANSI_STRING {u16 Length, u16 MaximumLength, ptr Buffer} = 8 | OK |
| ExCreateThread | shell/gen/rt.cpp:1407 (dead) · out_reco/rt.cpp:329 | *handle 4, *thread_id 4 | 4 + 4 | OK |
| NtResumeThread | out_reco/rt.cpp:367 | 4 | ULONG previous suspend count | OK |
| NtCreateEvent / NtCreateSemaphore | shell/gen/rt.cpp:1466 (dead) · out_reco/rt.cpp:1331, 1371 | 4 | HANDLE | OK |
| NtReleaseSemaphore | out_reco/rt.cpp:1383 | 4 | LONG previous count | OK |
| KeInitializeEvent | shell/gen/rt.cpp:1469 | 0 (host object keyed by address) | X_KEVENT 0x10 (header) | UNDER, NOT-READ by guest (Ke* waits are host-side) |
| KeQuerySystemTime | out_reco/stubs.cpp:40 (shell copy rt.cpp:1707 dead) | 8 | LARGE_INTEGER 8 | OK |
| RtlTimeToTimeFields | out_reco/stubs.cpp:101 | 16 | TIME_FIELDS 8 x s16 = 16 | OK |
| XNotifyGetNext | shell/gen/rt.cpp:1769 | *id 4, *param 4 | DWORD + ULONG_PTR, 4 + 4 | OK |
| NtCreateFile / NtOpenFile | out_reco/rt.cpp:1156/1158 | *handle 4, IO_STATUS_BLOCK 8 | 4; X_IO_STATUS_BLOCK {status, info} 8 | OK |
| NtReadFile / NtWriteFile | out_reco/rt.cpp:1159/1218 | buffer <= caller length; IOSB 8 | caller length; 8 | OK |
| NtQueryInformationFile | out_reco/rt.cpp:1247 | memset(len) + class 5 (24) / 14 (8) / 34 (56), each gated len >= size | caller length; FILE_STANDARD_INFORMATION 24, FILE_POSITION 8, FILE_NETWORK_OPEN 56 | OK (bounded by len) |
| NtQueryVolumeInformationFile | out_reco/rt.cpp:1273 | memset(len) + class 3 (24) / 1 (18) | caller length; FILE_FS_SIZE 24, FILE_FS_VOLUME 18 | OK (bounded by len) |
| NtQueryFullAttributesFile | out_reco/rt.cpp:1288 | 56 | X_FILE_NETWORK_OPEN_INFORMATION 0x38 = 56 | OK |
| XAudioGetSpeakerConfig | shell/gen/stubs.cpp:145 | 4 | DWORD | OK |
| XAudioGetVoiceCategoryVolume | shell/gen/stubs.cpp:146 | 4 | float | OK |
| XMsgInProcessCall (XMP GetStatus) | shell/gen/stubs.cpp:183 | 2 x 4 | two DWORD outs (Xenia xmp GetStatus) | OK |
| XamContentClose / CreateEx / ShowDeviceSelectorUI / ShowMessageBoxUIEx / Enumerate (overlapped completion) | shell/gen/stubs.cpp:264, 350, 1091, 1122, 478 | XOVERLAPPED +0x00, +0x04, +0x18 | XOVERLAPPED 0x1C (InternalLow, InternalHigh, InternalContext, hEvent, pCompletionRoutine, dwCompletionContext, dwExtendedError) | OK |
| XamContentCreateEx | shell/gen/stubs.cpp:350 | *disposition 4, *license_mask 4 | DWORD, DWORD | OK |
| XamContentCreateEnumerator | shell/gen/stubs.cpp:329 | *buffer_size 4, *handle 4 | DWORD, HANDLE | OK |
| XamContentGetDeviceData | shell/gen/stubs.cpp:440 | 0x50 | X_CONTENT_DEVICE_DATA 0x50 (Xenia `static_assert_size(..., 0x50)`: id, type, u64 total, u64 free, wchar name[28]) | OK |
| XamEnumerate (DLC + SAVEGAME items) | shell/gen/stubs.cpp:478 | 0x308 per item | the stub's OWN contract: CreateEnumerator reports items x 0x308 and the guest (82192C30 / 821945A0) passes exactly that stored size back as buflen (`lwz r5,104(r31)` = the slot CreateEnumerator wrote). Real XCONTENT_DATA is 0x134 / XCONTENT_AGGREGATE_DATA 0x148, so the guest buffer is >= what is written | OK (self-consistent; not over the guest buffer) |
| XamInputGetKeystrokeEx | shell/gen/stubs.cpp:1015 | 8 (+ *user 4) | XINPUT_KEYSTROKE 8 (VirtualKey, Unicode, Flags u16; UserIndex, HidCode u8) | OK |
| XamInputGetState | shell/gen/stubs.cpp:1046 | 16 | XINPUT_STATE = dwPacketNumber 4 + XINPUT_GAMEPAD 12 = 0x10 (the brief's "0x14" is XINPUT_CAPABILITIES) | OK |
| XamShowDeviceSelectorUI | shell/gen/stubs.cpp:1091 | *device_id 4 | DWORD | OK |
| XamShowMessageBoxUIEx | shell/gen/stubs.cpp:1122 | *result 4 | DWORD | OK |
| XamUserGetName | shell/gen/stubs.cpp:1145 | <= buflen (NUL-terminated within len) | caller length (XUSER_NAME_SIZE 16) | OK |
| XexLoadImage / XexGetProcedureAddress / XexGetModuleHandle | out_reco/merged/merged_bridge.cpp:189/309/323 | 4 each | HANDLE / PVOID / HANDLE | OK |
| XGetLanguage / XGetAVPack / XamUserGetSigninState / KeTlsAlloc / VdQueryVideoFlags / XamGetSystemVersion | stubs.cpp:151/150/1149, rt.cpp:58, stubs.cpp:137/551 | scalar return only | scalar | OK (no pointer) |
| VdEnableRingBufferRPtrWriteBack / VdSetGraphicsInterruptCallback (rptr / fence write-back) | shell/gen/rt.cpp | 4 per write-back slot | u32 | OK |
| out_reco/merged/*, host/*, harness.cpp, rt_phys.cpp memsets | merged_shell.cpp:4800, 4943, 5142; module_registry.cpp:259; harness.cpp:257/291/322; rt_phys.cpp:109/144/197 | host-owned allocations / image sections / allocator zeroing | n/a (no guest out-pointer argument) | OK (not a stub-into-caller write) |

No host import in `out_reco/merged/*.cpp` or `host/*` writes through a guest out-pointer argument.
XamInputGetCapabilities, XamContentGetLicenseMask, XeKeys*, XamContentCreate (non-Ex) are not imported by either module.

## 3. UNDER — the real kernel writes an output the stub leaves untouched (NOT changed in this window)

Call-site evidence (subagent read of every call site, PPC level): READ-UNINITIALISED = the caller reads the location afterwards
with no pre-store.

| stub | file:line | real output | callers / reads | verdict |
|---|---|---|---|---|
| VdGetCurrentDisplayInformation | shell/gen/stubs.cpp:131 | X_DISPLAY_INFO 0x58 | 820AB528 (lhz r1+152/154/166 -> device +21752/+21756/+21760 = display w/h), 820B1E80, 820B22D0 | **UNDER, READ-UNINITIALISED** — NOT fixed: writes the same device display-mode fields the 2026-07-22 RT_HDMODE A/B showed break the panel compose path when given true HD values; needs its own A/B window with the pixel gates |
| VdGetCurrentDisplayGamma | shell/gen/stubs.cpp:130 | u32 type, float power | 820A9CA8 (lfs/lwz r1+80/84 -> cached gamma) | **UNDER, READ-UNINITIALISED** — not fixed (renderer-path value; same A/B requirement) |
| VdGetSystemCommandBuffer | shell/gen/stubs.cpp:132 | two u32 outs | 820A5408 (lwz r1+116 -> dev[10896]+8 and VdSwap r7) | **UNDER, READ-UNINITIALISED** — not fixed (feeds the VdSwap hook's argument; hook-side check owed) |
| ExGetXConfigSetting | out_reco/stubs.cpp:25 (shell copy dead) | setting bytes (buf, size) + *required size | 8208FBF8 / 88086B68 time-zone read: biases pre-zeroed by the caller, the name/date bytes are not | UNDER, partly READ (time-zone names = stack garbage) — not fixed (no value to invent; RT_XCFGTRACE exists) |
| XamUserGetXUID | shell/gen/stubs.cpp:1150 | u64 XUID | 8 callers (stats / online) | UNDER, READ — out of scope (no Xbox LIVE) |
| ObReferenceObjectByHandle | out_reco/stubs.cpp:74 | *object | 6 callers pass the result to Ke*Thread / ObDereferenceObject stubs that ignore it | UNDER, read but harmless |
| NtQueryVirtualMemory | out_reco/stubs.cpp:70 | X_MEMORY_BASIC_INFORMATION 0x1C | RtlCreateHeap path needs HeapBase != 0; every caller passes 0 | UNDER, dead path |
| XMACreateContext | shell/gen/stubs.cpp:152 | *context | 8210C190 pre-zeroes the slot | UNDER, pre-initialised (0) |
| XamUserReadProfileSettings, XMsgStartIORequest, XamGetSystemVersion, VdQueryVideoFlags | stubs.cpp | results / overlapped | return-checked only | UNDER, not read |
| RtlInitializeCriticalSection(AndSpinCount) | rt.cpp:76 (dead) · out_reco/rt.cpp | CRITICAL_SECTION 0x1C | no reads at 20 call sites (host mutex keyed by address) | UNDER, not read |
| XamAlloc, RtlFillMemoryUlong, RtlMultiByteToUnicodeN, RtlUnicodeToMultiByteN, RtlCaptureContext, XamGetExecutionId | shell/gen/stubs.cpp:202/118/120/126/116/550 | out pointer / filled memory | not swept | UNKNOWN |
| NtQueryDirectoryFile | out_reco/stubs.cpp:69 | FILE_DIRECTORY_INFORMATION | no call sites | n/a |

## 4. Summary

Checked every `__imp__` body that writes through a guest pointer in the compiled copies (≈ 40 writing stubs; 77 + 132 + 41 +
28 import bodies scanned in shell/gen/rt.cpp, shell/gen/stubs.cpp, out_reco/rt.cpp, out_reco/stubs.cpp) and every guest-pointer
memset/memcpy in the listed files. **OVER: 2 live (XGetVideoMode, VdQueryVideoMode) + 1 dead twin — all fixed to 0x30.** UNDER: 12, of which
READ-UNINITIALISED on a live path: VdGetCurrentDisplayInformation, VdGetCurrentDisplayGamma, VdGetSystemCommandBuffer,
ExGetXConfigSetting (time-zone names), XamUserGetXUID (online) — none fixed here (each changes a value the game uses: a
behaviour change needing its own A/B, not a stack-safety fix); UNKNOWN: 6 (§3 "not swept" row). (The subagent's XexGetProcedureAddress/XexLoadImage READ-UNINITIALISED finding was against the dead shell copies; the linked merged_bridge.cpp copies write every out.)
Proof of the fix: docs/NOTE_fnf_shell_defects.md "KSTUB-OVERCLEAR".

## 5. Proof (2026-10-12, `_local/kstub/`)

- Harness (route B1 capture, build/kstub_cap): 8216B0A0 -> 8216AD98: r28 FFFFFFFF821F8660 -> FFFFFFFF821F8660 (w156H pre-fix
  record: -> 0); r26 / r27 / f31 unchanged; `[callee-clobber]` gone for 8216B0A0 / 8216C400, both EQUIV-STRICT (`harness_proof.txt`).
- Screens: route B1 14/14 byte-identical to the w156H pre-fix leg; route B4 pre/post legs within the same-build band (`cmp_b4.py`).
- Non-regression on build/kstub_probe: nav hub PASS, nav360 q2 VERDICT PASS, boss1 PASS, app-smoke steps PASS, 12-min ARCADE
  soak +132 MB (Q5 control +133), 0 FATAL / VK_ERROR / dropouts, 59.94 Hz.
