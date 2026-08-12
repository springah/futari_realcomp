// decomp/game/asset_decode.cpp — the game module's asset-decompression family (mode 1..4).
//
// The asset job pump FUN_8813a738 dispatches a compressed record to one of four decoders by its
// mode byte (1→sub_8813A248, 2→sub_8813A118, 3→sub_88139D90, 4→sub_88139A88; see the RT_DECLOG
// comment at out_reco/merged/merged_game.cpp:3563). This file translates them one mode at a time.
//
// THE FAMILY (one function per mode; per-mode status lives in decomp/registry.toml + each § below):
//   mode 1 — sub_8813A248  LZ77 over a global 4KB ring dictionary        NON-LEAF (memset)
//   mode 2 — sub_8813A118  split-stream LZSS                             LEAF
//   mode 3 — sub_88139D90  'ZZ'-magic bit-plane adaptive LZ             NON-LEAF (memcpy + memmove)
//   mode 4 — sub_88139A88  'ZZ'-magic bit-serial adaptive LZ            NON-LEAF (memcpy + memmove)
// Dispatch: the job pump (out_reco/ppc_recomp.18.cpp:11616-11729) reads the mode byte from the
// resource descriptor and calls the decoder with r3=dst, r4=src (compressed record); modes 3/4 also
// pass r5=compressed input length. Each returns the decoded size (BE32 of src+4) in r3 — except a
// leading-byte/'ZZ' magic mismatch returns 8, and mode 3/4's "block larger than output" shortcut
// returns 0. Non-leaves mirror the generated register file at every call boundary (C1, PILOT §2);
// the shared memcpy is sub_88072260 (decomp/game/mem_util.cpp), memmove is sub_880707F0, memset is
// sub_88073BD0.
//
// ── SEAM (PILOT_NOTES §2 — SHADOWED-HOOK form) ─────────────────────────────────────────────────
// Every decoder is already strong-hooked by DECODER_LOG_WRAP in merged_game.cpp:3594-3597 (the
// RT_DECLOG / RT_DECDUMP char-card instrument). So translations take the __imp__ symbol: the
// wrapper keeps its strong PPC_FUNC(sub_XXXX) and this body displaces the generated __imp__ body
// underneath it. decomp/game/*.cpp links FIRST (build_win.sh), so this wins; the generated
// __imp__ stays as dead bytes. ROLLBACK = delete this file / drop obj_win/decomp_asset_decode.o.
//
// ── THE GATE (a gift already wired) ────────────────────────────────────────────────────────────
// The DECODER_LOG_WRAP reads r3..r6 + lr at entry and r3 at EXIT, and RT_DECDUMP=<hex dst> writes
// the compressed input + the decode OUTPUT to disk at decode time. So the acceptance gate for any
// decoder here is a real output diff, exercised whenever the decoder fires:
//   * RT_DECLOG=1 stream equality (control=generated vs pilot=this) — the [declog] line carries
//     the exit r3, which the generated body leaves = header word 0 (decoded size); this body
//     reproduces it (see below), so a passing translation is [declog]-identical.
//   * RT_DECDUMP=<dst> byte-compare of the *_out.bin the two builds write for the same asset.
// Because the wrapper observes exit r3, r3 is part of the contract here even though the decoder is
// a leaf — this body sets it explicitly rather than leaving a volatile leftover.

#include "ppc_recomp_shared.h"   // ppc_config.h (base 0x88000000) + ppc_context.h (-I out_reco)

// ════════════════════════════════════════════════════════════════════════════════════════════════
// mode 2 — 0x8813A118 — split-stream LZSS.  Leaf (no bl / bctrl).
//
// Ground truth: out_reco/ppc_recomp.18.cpp:10411-10585 (register-exact recomp, entry → blr).
//
// Layout of the compressed record at src (r4), all header words BIG-ENDIAN:
//   [0..3]  decodedSize   — the uncompressed length. Read but only used as the return value here
//                           (the recomp keeps it in r3 to the blr; the job pump reads it back).
//   [4..7]  tokenCount    — number of tokens to emit (signed; <=0 ⇒ emit nothing).
//   [8..11] dataOffset    — byte offset from src to the DESCRIPTOR/LITERAL stream.
//   [12..]  flag stream   — one bit per token, MSB first; 1 = back-reference, 0 = literal.
//
// The two streams advance independently: flag bits come from src+12 upward; literal bytes AND the
// 2-byte match descriptors both come from the src+dataOffset stream. A back-reference descriptor is
// a 16-bit big-endian value split distance:11 (high) / length-3:5 (low); the copy source is the
// current output pointer minus distance (an LZ77 window into the bytes just emitted).
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC_IMPL(__imp__sub_8813A118)
{
    PPC_FUNC_PROLOGUE();
    const uint32_t src         = ctx.r4.u32;
    const uint32_t decodedSize = PPC_LOAD_U32(src + 0);          // header word 0 — returned in r3
    const int32_t  tokenCount  = (int32_t)PPC_LOAD_U32(src + 4); // header word 1 (signed compare)
    uint32_t       data        = src + PPC_LOAD_U32(src + 8);    // descriptor/literal stream
    uint32_t       flags       = src + 12;                       // flag-bit stream
    uint32_t       out         = ctx.r3.u32;                     // output cursor (r3 = dst)

    uint32_t curFlag = 0;   // current flag byte; the bit under test is always its MSB
    int      bits    = 0;   // flag bits left in curFlag

    for (int32_t tok = 0; tok < tokenCount; ++tok)
    {
        if (bits == 0) { curFlag = PPC_LOAD_U8(flags++); bits = 8; }

        if (curFlag & 0x80)
        {
            // back-reference: 16-bit big-endian descriptor from the data stream
            const uint32_t desc   = ((uint32_t)PPC_LOAD_U8(data) << 8) | PPC_LOAD_U8(data + 1);
            data += 2;
            const uint32_t length = (desc & 0x1F) + 3;   // low 5 bits + 3
            const uint32_t dist   = desc >> 5;           // high 11 bits
            uint32_t from = out - dist;                  // window into already-emitted output
            for (uint32_t i = 0; i < length; ++i)
                PPC_STORE_U8(out++, PPC_LOAD_U8(from++));
        }
        else
        {
            // literal: one byte straight from the data stream
            PPC_STORE_U8(out++, PPC_LOAD_U8(data++));
        }

        curFlag = (curFlag << 1) & 0xFF;   // shift the consumed bit out (MSB-first)
        --bits;
    }

    ctx.r3.u64 = decodedSize;   // the generated body leaves r3 = header word 0; DECODER_LOG_WRAP reads it
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// mode 1 — 0x8813A248 — LZ77 over a global 4KB ring dictionary.  NON-LEAF (one call: memset).
//
// Ground truth: out_reco/ppc_recomp.18.cpp:10588-10794 (register-exact recomp, entry → __restgprlr_27
// tail). Dispatched by the job pump at ppc_recomp.18.cpp:11635 with r3=dst, r4=src (no length reg —
// the decoded size is header word 0). Returns that size in r3 (read by DECODER_LOG_WRAP at exit).
//
// SHAPE OF THE COMPRESSED RECORD (src = r4):
//   [0..3]   decodedSize — total output length, BIG-ENDIAN u32. Also the return value and the
//            token-loop terminator (the loop emits until outPos == decodedSize).
//   [4..1027] 1024 raw preamble bytes — copied verbatim to the output AND used to prime the low
//            1024 slots of the ring dictionary. (So mode 1 is only used when decodedSize >= 1024;
//            the generated body has no guard for a shorter output and neither does this one.)
//   [1028..]  a stream of fixed 2-byte tokens. Byte0's top bit is the type flag:
//              * flag 0  → LITERAL: emit byte1 (byte0's low 7 bits are unused padding).
//              * flag 1  → MATCH:   desc = ((byte0 & 0x7F) << 8) | byte1   (15-bit, MSB-first)
//                          count    = (desc & 0x1F) + 1      (low 5 bits + 1, so 1..32 bytes)
//                          distance =  desc >> 5             (high 10 bits, 0..1023)
//                          copy `count` bytes from the ring at (readCursor + distance) forward.
//
// THE RING (a module-global 4KB scratch dictionary, base 0x884D2468 = lis -30643 + 9320):
//   Zeroed each call via sub_88073BD0 (memset). Two cursors walk it, both masked to 0xFFF (4KB wrap):
//     writeCursor — where the next emitted byte lands in the ring; starts at 1024 (after preamble).
//     readCursor  — the match window's origin; starts at 0.  Both advance by 1 per literal and by
//                   `count` per match, so writeCursor - readCursor stays == 1024: a match reads the
//                   previously-emitted 1024-byte window and can self-overlap (LZ run fill).
//   A match's source index is (readCursorAtTokenStart + distance + k) & 0xFFF for k in 0..count-1 —
//   the origin is FROZEN at the token's entry readCursor while readCursor itself advances alongside.
//
// PERSISTED CURSORS (written but never re-read inside this function — a resumable-decode handoff):
//   0x887ACE08 (-12792 rel 0x887B0000) = readCursor    0x887ACE0C (-12788) = writeCursor.
//   Order matches the recomp: readCursor(0) stored before the preamble, writeCursor after it, then
//   both re-stored at the end of every token. Reproduced for byte-true observable memory.
//
// ── C1 boundary (PILOT_NOTES §2, the memset call) ───────────────────────────────────────────────
// sub_88073BD0 is the guest memset(dst=r3,val=r4,len=r5) — a LEAF that reads only r3/r4/r5. At the
// bl we set exactly those (ring, 0, 4096) plus ctx.lr = 0x8813A2A4 (its generated return address),
// then call it through ctx so the real (and any hooked) memset runs and the call graph / [gmstage]
// stack sampler is unchanged. The generated body's other live regs at that boundary (header scratch
// r6..r11, r27..r31) are NOT mirrored: memset neither reads them nor allocates, so no guest address
// can shift — same deliberately-accepted residual class as decomp/game/mem_util.cpp. The ctx
// nonvolatiles r27..r31 are left as the caller's values (never clobbered → no save/restore needed,
// strictly more conservative than the generated __savegprlr_27/__restgprlr_27 pair).
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC_IMPL(__imp__sub_8813A248)
{
    PPC_FUNC_PROLOGUE();
    const uint32_t src         = ctx.r4.u32;
    const uint32_t dst         = ctx.r3.u32;
    const uint32_t decodedSize = PPC_LOAD_U32(src + 0);   // header word 0, BE — output length + terminator

    const uint32_t RING       = 0x884D2468;   // module-global 4KB LZ dictionary (lis -30643 + 9320)
    const uint32_t G_READ     = 0x887ACE08;   // persisted readCursor  (-12792 rel 0x887B0000)
    const uint32_t G_WRITE    = 0x887ACE0C;   // persisted writeCursor (-12788 rel 0x887B0000)

    // ── zero the ring, then persist readCursor = 0 (the -12792 store precedes the preamble) ──
    ctx.r3.u64 = RING; ctx.r4.u64 = 0; ctx.r5.u64 = 4096; ctx.lr = 0x8813A2A4;
    sub_88073BD0(ctx, base);                  // memset(ring, 0, 4096)
    PPC_STORE_U32(G_READ, 0);

    uint32_t writeCursor = 1024;              // ring write cursor (starts past the preamble window)
    uint32_t readCursor  = 0;                 // ring read/window origin
    uint32_t outPos      = 1024;              // output byte index (preamble fills [0..1023])

    // ── preamble: 1024 raw bytes from src+4 → ring[0..1023] and dst[0..1023] ──
    for (uint32_t i = 0; i < 1024; ++i)
    {
        const uint8_t b = PPC_LOAD_U8(src + 4 + i);
        PPC_STORE_U8(RING + i, b);            // ring slot i (writeCursor walks 0..1023 here)
        PPC_STORE_U8(dst  + i, b);            // straight to output
    }
    PPC_STORE_U32(G_WRITE, writeCursor);      // persist writeCursor = 1024 (the -12788 store)

    // ── token loop (skipped entirely when the whole output is the 1024-byte preamble) ──
    uint32_t in = src + 1028;                 // fixed 2-byte tokens start right after the preamble
    while (outPos != decodedSize)
    {
        const uint8_t ctrl = PPC_LOAD_U8(in++);
        if ((ctrl & 0x80) == 0)
        {
            // LITERAL: byte1 is the datum; ctrl's low 7 bits are unused.
            const uint8_t lit = PPC_LOAD_U8(in++);
            PPC_STORE_U8(RING + writeCursor, lit);
            PPC_STORE_U8(dst  + outPos,      lit);
            writeCursor = (writeCursor + 1) & 0xFFF;
            readCursor  = (readCursor  + 1) & 0xFFF;
            ++outPos;
        }
        else
        {
            // MATCH: 15-bit descriptor split distance:10 (high) / length-1:5 (low).
            const uint32_t desc     = ((uint32_t)(ctrl & 0x7F) << 8) | PPC_LOAD_U8(in++);
            const uint32_t count    = (desc & 0x1F) + 1;   // 1..32 bytes
            const uint32_t distance =  desc >> 5;          // 0..1023
            const uint32_t origin   = readCursor + distance;   // frozen window origin for this token
            for (uint32_t k = 0; k < count; ++k)
            {
                const uint8_t b = PPC_LOAD_U8(RING + ((origin + k) & 0xFFF));
                PPC_STORE_U8(RING + writeCursor, b);
                PPC_STORE_U8(dst  + outPos,      b);
                writeCursor = (writeCursor + 1) & 0xFFF;
                readCursor  = (readCursor  + 1) & 0xFFF;
                ++outPos;
            }
        }
        PPC_STORE_U32(G_WRITE, writeCursor);  // persist both cursors after every token
        PPC_STORE_U32(G_READ,  readCursor);
    }

    ctx.r3.u64 = outPos;   // == decodedSize at exit; DECODER_LOG_WRAP reads this
}
