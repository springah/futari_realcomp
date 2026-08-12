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

// ════════════════════════════════════════════════════════════════════════════════════════════════
// mode 3 — 0x88139D90 — 'ZZ'-magic bit-plane adaptive LZ77.  NON-LEAF (memcpy + memmove).
//
// Ground truth: out_reco/ppc_recomp.18.cpp:9887-10402 (register-exact recomp). Dispatched at
// ppc_recomp.18.cpp:11679/11691 with r3=dst, r4=src, r5=compressed input length (a per-descriptor
// size, or 0x20000 default). Returns the decoded size (BE32 of src+4) in r3; 8 on a magic mismatch;
// 0 on the "block bigger than output" raw-copy shortcut. DECODER_LOG_WRAP reads that exit r3.
//
// FORMAT (derived; the transcribed body below preserves it bit-for-bit):
//   header (8 bytes): src[0]=src[1]='Z'(0x5A) magic; src[2]=s2, src[3]=s3 are bit-field WIDTHS;
//                     src[4..7]=decodedSize (BE u32, the return value).  blockA = 1<<s2 = the LZ
//                     window size; the length-field width is s3 and the offset-field width is s2.
//   scratch dictionary: a module-global work buffer at 0x884D6530 (lis -30643 + 25904). Zeroed for
//                     blockA + (1<<s3) + 2 bytes, then primed: scratch[0..blockA-1] = src[8..] (the
//                     first blockA payload bytes, also copied straight to the output).
//   SHORTCUT: if blockA > decodedSize the whole output is one block — memcpy(dst, src+8, decodedSize)
//                     and return 0 (no token stream).
//   token stream (bit-serial from src[8+blockA] onward, MSB-first): one flag bit per token —
//        flag 0 → LITERAL: an 8-bit byte follows; emit it.
//        flag 1 → MATCH:   an s2-bit OFFSET field then an s3-bit LENGTH field; copy length = LEN+3
//                          bytes from the window at scratch[offset] forward.
//   Every token appends the produced byte(s) at scratch[blockA..], then slides the window left by
//   the number of bytes produced via memmove(scratch, scratch+produced, blockA) and zeroes the
//   (1<<s3)+2-byte append/lookahead tail. The output cursor is dst+blockA-1 (stbu pre-increment).
//
// ⚠ WHY A FAITHFUL TRANSCRIPTION, NOT NATURAL C (round-4 decision): the 4×-unrolled MSB-first bit
// reader carries (bitPos+1) between reads and its byte-boundary wrap is NON-OBVIOUS (a clean
// readBits() diverges from the generated reader exactly at byte crossings — the encoder was built
// against these quirks, so they ARE the spec). Reproducing them requires the live RT_DECLOG/RT_DECDUMP
// differential to validate, which this background session cannot boot. So this body is the generated
// __imp__ operations verbatim (behavior-identical by construction — the byte-boundary semantics are
// preserved exactly), carrying the derived writeup above; round 5 refactors it into readable C once
// the gate can prove the bit-reader equivalence.  All call boundaries (the two priming/ shortcut
// memcpys via sub_88072260 and the per-token window-slide memmoves via sub_880707F0) keep the exact
// generated register file and ctx.lr — C1 discipline is automatic here since the ops are unchanged.
//
// SEAM: strong-hooked by DECODER_LOG_WRAP (merged_game.cpp:3595) → takes __imp__sub_88139D90; the
// decomp object links first so this body wins over the generated __imp__ (rollback = drop the obj).
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC_IMPL(__imp__sub_88139D90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071130
	ctx.lr = 0x88139D98;
	__savegprlr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r19,r5
	ctx.r19.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// beq cr6,0x88139dc0
	if (ctx.cr6.eq) goto loc_88139DC0;
loc_88139DB4:
	// li r3,8
	ctx.r3.s64 = 8;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
loc_88139DC0:
	// lbz r11,1(r27)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r27.u32 + 1);
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// bne cr6,0x88139db4
	if (!ctx.cr6.eq) goto loc_88139DB4;
	// lbz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r27.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// lbz r9,5(r27)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r27.u32 + 5);
	// rotlwi r8,r11,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r21,3(r27)
	ctx.r21.u64 = PPC_LOAD_U8(ctx.r27.u32 + 3);
	// lbz r7,6(r27)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r27.u32 + 6);
	// or r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 | ctx.r9.u64;
	// lbz r20,2(r27)
	ctx.r20.u64 = PPC_LOAD_U8(ctx.r27.u32 + 2);
	// slw r11,r10,r21
	ctx.r11.u64 = ctx.r21.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r21.u8 & 0x3F));
	// lbz r5,7(r27)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r27.u32 + 7);
	// rlwinm r4,r6,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// slw r25,r10,r20
	ctx.r25.u64 = ctx.r20.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r20.u8 & 0x3F));
	// or r3,r4,r7
	ctx.r3.u64 = ctx.r4.u64 | ctx.r7.u64;
	// addi r24,r11,2
	ctx.r24.s64 = ctx.r11.s64 + 2;
	// rlwinm r9,r3,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// add. r11,r24,r25
	ctx.r11.u64 = ctx.r24.u64 + ctx.r25.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// or r18,r9,r5
	ctx.r18.u64 = ctx.r9.u64 | ctx.r5.u64;
	// addi r26,r10,25904
	ctx.r26.s64 = ctx.r10.s64 + 25904;
	// ble 0x88139e38
	if (!ctx.cr0.gt) goto loc_88139E38;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r26,-1
	ctx.r10.s64 = ctx.r26.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88139e38
	if (ctx.cr6.eq) goto loc_88139E38;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_88139E30:
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x88139e30
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88139E30;
loc_88139E38:
	// cmpw cr6,r25,r18
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r18.s32, ctx.xer);
	// ble cr6,0x88139e5c
	if (!ctx.cr6.gt) goto loc_88139E5C;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// addi r4,r27,8
	ctx.r4.s64 = ctx.r27.s64 + 8;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88072260
	ctx.lr = 0x88139E50;
	sub_88072260(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
loc_88139E5C:
	// addi r31,r27,8
	ctx.r31.s64 = ctx.r27.s64 + 8;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// bl 0x88072260
	ctx.lr = 0x88139E70;
	sub_88072260(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88072260
	ctx.lr = 0x88139E80;
	sub_88072260(ctx, base);
	// addi r30,r25,8
	ctx.r30.s64 = ctx.r25.s64 + 8;
	// add r11,r25,r29
	ctx.r11.u64 = ctx.r25.u64 + ctx.r29.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmpw cr6,r30,r19
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r19.s32, ctx.xer);
	// bge cr6,0x8813a108
	if (!ctx.cr6.lt) goto loc_8813A108;
	// addi r22,r19,-1
	ctx.r22.s64 = ctx.r19.s64 + -1;
	// addi r23,r11,-1
	ctx.r23.s64 = ctx.r11.s64 + -1;
loc_88139E9C:
	// cmpw cr6,r30,r22
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r22.s32, ctx.xer);
	// bne cr6,0x88139eb4
	if (!ctx.cr6.eq) goto loc_88139EB4;
	// subfic r11,r21,8
	ctx.xer.ca = ctx.r21.u32 <= 8;
	ctx.r11.s64 = 8 - ctx.r21.s64;
	// subf r10,r20,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r20.s64;
	// cmpw cr6,r31,r10
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x8813a108
	if (ctx.cr6.gt) goto loc_8813A108;
loc_88139EB4:
	// subfic r11,r31,7
	ctx.xer.ca = ctx.r31.u32 <= 7;
	ctx.r11.s64 = 7 - ctx.r31.s64;
	// lbzx r10,r30,r27
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// srw r8,r10,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x88139ffc
	if (!ctx.cr6.eq) goto loc_88139FFC;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r31,7
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 7, ctx.xer);
	// ble cr6,0x88139ee8
	if (!ctx.cr6.gt) goto loc_88139EE8;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_88139EE8:
	// li r11,2
	ctx.r11.s64 = 2;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_88139EF0:
	// subfic r10,r31,7
	ctx.xer.ca = ctx.r31.u32 <= 7;
	ctx.r10.s64 = 7 - ctx.r31.s64;
	// lbzx r7,r30,r27
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// clrlwi r9,r28,24
	ctx.r9.u64 = ctx.r28.u32 & 0xFF;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// srw r6,r7,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r8.u8 & 0x3F));
	// rlwimi r6,r9,1,24,30
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r9.u32, 1) & 0xFE) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFF01);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// ble cr6,0x88139f20
	if (!ctx.cr6.gt) goto loc_88139F20;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_88139F20:
	// subfic r8,r11,7
	ctx.xer.ca = ctx.r11.u32 <= 7;
	ctx.r8.s64 = 7 - ctx.r11.s64;
	// lbzx r5,r30,r27
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r6,r8,24
	ctx.r6.u64 = ctx.r8.u32 & 0xFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srw r4,r5,r6
	ctx.r4.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 >> (ctx.r6.u8 & 0x3F));
	// rlwimi r4,r7,1,24,30
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r7.u32, 1) & 0xFE) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFF01);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// ble cr6,0x88139f50
	if (!ctx.cr6.gt) goto loc_88139F50;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_88139F50:
	// subfic r8,r11,7
	ctx.xer.ca = ctx.r11.u32 <= 7;
	ctx.r8.s64 = 7 - ctx.r11.s64;
	// lbzx r5,r30,r27
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r6,r8,24
	ctx.r6.u64 = ctx.r8.u32 & 0xFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srw r4,r5,r6
	ctx.r4.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 >> (ctx.r6.u8 & 0x3F));
	// rlwimi r4,r7,1,24,30
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r7.u32, 1) & 0xFE) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFF01);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// ble cr6,0x88139f80
	if (!ctx.cr6.gt) goto loc_88139F80;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_88139F80:
	// subfic r8,r11,7
	ctx.xer.ca = ctx.r11.u32 <= 7;
	ctx.r8.s64 = 7 - ctx.r11.s64;
	// lbzx r5,r30,r27
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r6,r8,24
	ctx.r6.u64 = ctx.r8.u32 & 0xFF;
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// srw r4,r5,r6
	ctx.r4.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 >> (ctx.r6.u8 & 0x3F));
	// rlwimi r4,r7,1,24,30
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r7.u32, 1) & 0xFE) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFF01);
	// cmpwi cr6,r31,7
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 7, ctx.xer);
	// clrlwi r28,r4,24
	ctx.r28.u64 = ctx.r4.u32 & 0xFF;
	// ble cr6,0x88139fb0
	if (!ctx.cr6.gt) goto loc_88139FB0;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_88139FB0:
	// bdnz 0x88139ef0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88139EF0;
	// stbx r28,r25,r26
	PPC_STORE_U8(ctx.r25.u32 + ctx.r26.u32, ctx.r28.u8);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// addi r4,r26,1
	ctx.r4.s64 = ctx.r26.s64 + 1;
	// add r29,r25,r26
	ctx.r29.u64 = ctx.r25.u64 + ctx.r26.u64;
	// bl 0x880707f0
	ctx.lr = 0x88139FCC;
	sub_880707F0(ctx, base);
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// ble cr6,0x88139ff0
	if (!ctx.cr6.gt) goto loc_88139FF0;
	// addi r11,r29,-1
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x88139ff0
	if (ctx.cr6.eq) goto loc_88139FF0;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
loc_88139FE8:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x88139fe8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88139FE8;
loc_88139FF0:
	// stb r28,1(r23)
	PPC_STORE_U8(ctx.r23.u32 + 1, ctx.r28.u8);
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// b 0x8813a100
	goto loc_8813A100;
loc_88139FFC:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r31,7
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 7, ctx.xer);
	// ble cr6,0x8813a010
	if (!ctx.cr6.gt) goto loc_8813A010;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_8813A010:
	// lbz r10,2(r27)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r27.u32 + 2);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8813a050
	if (!ctx.cr6.gt) goto loc_8813A050;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8813A020:
	// subfic r10,r31,7
	ctx.xer.ca = ctx.r31.u32 <= 7;
	ctx.r10.s64 = 7 - ctx.r31.s64;
	// lbzx r9,r30,r27
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// cmpwi cr6,r31,7
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 7, ctx.xer);
	// srw r7,r9,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// rlwimi r7,r11,1,0,30
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r11.u32, 1) & 0xFFFFFFFE) | (ctx.r7.u64 & 0xFFFFFFFF00000001);
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// ble cr6,0x8813a04c
	if (!ctx.cr6.gt) goto loc_8813A04C;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_8813A04C:
	// bdnz 0x8813a020
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813A020;
loc_8813A050:
	// lbz r9,3(r27)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r27.u32 + 3);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x8813a094
	if (!ctx.cr6.gt) goto loc_8813A094;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8813A064:
	// subfic r9,r31,7
	ctx.xer.ca = ctx.r31.u32 <= 7;
	ctx.r9.s64 = 7 - ctx.r31.s64;
	// lbzx r8,r30,r27
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// cmpwi cr6,r31,7
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 7, ctx.xer);
	// srw r6,r8,r7
	ctx.r6.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r7.u8 & 0x3F));
	// rlwimi r6,r10,1,0,30
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r10.u32, 1) & 0xFFFFFFFE) | (ctx.r6.u64 & 0xFFFFFFFF00000001);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// ble cr6,0x8813a090
	if (!ctx.cr6.gt) goto loc_8813A090;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_8813A090:
	// bdnz 0x8813a064
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813A064;
loc_8813A094:
	// addi r8,r10,3
	ctx.r8.s64 = ctx.r10.s64 + 3;
	// add r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 + ctx.r11.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8813a0c8
	if (!ctx.cr6.lt) goto loc_8813A0C8;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// subf r9,r11,r25
	ctx.r9.s64 = ctx.r25.s64 - ctx.r11.s64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8813A0B0:
	// add r10,r11,r26
	ctx.r10.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// stbx r7,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u8);
	// stbu r7,1(r23)
	ea = 1 + ctx.r23.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r23.u32 = ea;
	// bdnz 0x8813a0b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813A0B0;
loc_8813A0C8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// add r4,r8,r26
	ctx.r4.u64 = ctx.r8.u64 + ctx.r26.u64;
	// bl 0x880707f0
	ctx.lr = 0x8813A0D8;
	sub_880707F0(ctx, base);
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// ble cr6,0x8813a100
	if (!ctx.cr6.gt) goto loc_8813A100;
	// add r11,r25,r26
	ctx.r11.u64 = ctx.r25.u64 + ctx.r26.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// beq cr6,0x8813a100
	if (ctx.cr6.eq) goto loc_8813A100;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
loc_8813A0F8:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8813a0f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813A0F8;
loc_8813A100:
	// cmpw cr6,r30,r19
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r19.s32, ctx.xer);
	// blt cr6,0x88139e9c
	if (ctx.cr6.lt) goto loc_88139E9C;
loc_8813A108:
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// mode 4 — 0x88139A88 — 'ZZ'-magic bit-serial adaptive LZ77.  NON-LEAF (memcpy + memmove).
//
// Ground truth: out_reco/ppc_recomp.18.cpp:9423-9877 (register-exact recomp). Dispatched at
// ppc_recomp.18.cpp:11727 with r3=dst, r4=src, r5=compressed input length. Returns the decoded size
// (BE32 of src+4) in r3; 8 on a magic mismatch. DECODER_LOG_WRAP reads that exit r3.
//
// FORMAT (derived; the transcribed body below preserves it bit-for-bit):
//   header (8 bytes): src[0]=src[1]='Z'(0x5A) magic; src[2]=s2, src[3]=s3 are bit-field WIDTHS
//                     (offset field = s2 bits, length field = s3 bits); src[4..7]=decodedSize (BE u32,
//                     the return value).  blockA = 1<<s2, blockB = 1<<s3.
//   scratch dictionary: a module-global work buffer at 0x884D3468 (lis -30643 + 13416). Zeroed for
//                     blockA + blockB + 2 bytes. Unlike mode 3 (which slides every token), mode 4
//                     lets a write cursor WALK FORWARD through the buffer and bulk-FLUSHes: whenever
//                     the bytes-since-flush counter exceeds 2*(blockA+blockB+2), memmove the live
//                     window (blockA bytes at the cursor) back to the base and reset the cursor.
//   token stream (bit-serial from src[8] onward, MSB-first, via a shift-accumulator 'current byte'
//        r28 with a mod-8 bit index r30): one flag bit per token (top bit of the current byte) —
//        flag 0 → LITERAL: read an 8-bit byte (straddling byte boundaries via the accumulator); emit.
//        flag 1 → MATCH:   read an s2-bit OFFSET then an s3-bit LENGTH; length = LEN+3; the match
//                          source is scratch[cursor + blockA - offset - 2]; the length bytes are
//                          appended at scratch[cursor+blockA..] and memcpy'd to the output.
//
// ⚠ WHY A FAITHFUL TRANSCRIPTION, NOT NATURAL C (round-4 decision): same reason as mode 3 — the
// shift-accumulator bit reader (a 'current byte' shifted left with a mod-8 index, refilled across
// byte boundaries by OR-ing a shifted next byte) has intricate straddle handling whose exact
// behavior IS the spec and which needs the live RT_DECLOG/RT_DECDUMP differential to validate. This
// body is the generated __imp__ operations verbatim (behavior-identical by construction), carrying
// the derived writeup above; round 5 refactors to readable C once the gate can prove equivalence.
// All call boundaries (the flush memmoves via sub_880707F0 and the match-output memcpys via
// sub_88072260) keep the exact generated register file and ctx.lr — C1 is automatic (ops unchanged).
//
// SEAM: strong-hooked by DECODER_LOG_WRAP (merged_game.cpp:3594) → takes __imp__sub_88139A88; the
// decomp object links first so this body wins over the generated __imp__ (rollback = drop the obj).
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC_IMPL(__imp__sub_88139A88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071124
	ctx.lr = 0x88139A90;
	__savegprlr_15(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r19,r3
	ctx.r19.u64 = ctx.r3.u64;
	// mr r16,r5
	ctx.r16.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// beq cr6,0x88139ab4
	if (ctx.cr6.eq) goto loc_88139AB4;
loc_88139AA8:
	// li r3,8
	ctx.r3.s64 = 8;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
loc_88139AB4:
	// lbz r11,1(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// bne cr6,0x88139aa8
	if (!ctx.cr6.eq) goto loc_88139AA8;
	// lbz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// lbz r8,5(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// rotlwi r7,r9,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// lbz r23,2(r4)
	ctx.r23.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// lbz r21,3(r4)
	ctx.r21.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// addi r22,r11,13416
	ctx.r22.s64 = ctx.r11.s64 + 13416;
	// or r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 | ctx.r8.u64;
	// lbz r5,6(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 6);
	// slw r24,r10,r23
	ctx.r24.u64 = ctx.r23.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r23.u8 & 0x3F));
	// lbz r3,7(r4)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + 7);
	// rlwinm r11,r6,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// slw r10,r10,r21
	ctx.r10.u64 = ctx.r21.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r21.u8 & 0x3F));
	// or r9,r11,r5
	ctx.r9.u64 = ctx.r11.u64 | ctx.r5.u64;
	// add r8,r10,r24
	ctx.r8.u64 = ctx.r10.u64 + ctx.r24.u64;
	// rlwinm r7,r9,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// addic. r11,r8,2
	ctx.xer.ca = ctx.r8.u32 > 4294967293;
	ctx.r11.s64 = ctx.r8.s64 + 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
	// or r15,r7,r3
	ctx.r15.u64 = ctx.r7.u64 | ctx.r3.u64;
	// rlwinm r20,r11,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// ble 0x88139b34
	if (!ctx.cr0.gt) goto loc_88139B34;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r22,-1
	ctx.r10.s64 = ctx.r22.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88139b34
	if (ctx.cr6.eq) goto loc_88139B34;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_88139B2C:
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x88139b2c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88139B2C;
loc_88139B34:
	// subfic r11,r21,8
	ctx.xer.ca = ctx.r21.u32 <= 8;
	ctx.r11.s64 = 8 - ctx.r21.s64;
	// lbz r28,8(r4)
	ctx.r28.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// addi r29,r4,8
	ctx.r29.s64 = ctx.r4.s64 + 8;
	// li r27,8
	ctx.r27.s64 = 8;
	// li r30,0
	ctx.r30.s64 = 0;
	// subf r18,r23,r11
	ctx.r18.s64 = ctx.r11.s64 - ctx.r23.s64;
	// addi r17,r16,-1
	ctx.r17.s64 = ctx.r16.s64 + -1;
	// li r25,0
	ctx.r25.s64 = 0;
	// cmpwi cr6,r16,8
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 8, ctx.xer);
	// ble cr6,0x88139d80
	if (!ctx.cr6.gt) goto loc_88139D80;
loc_88139B5C:
	// cmpw cr6,r27,r17
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r17.s32, ctx.xer);
	// bne cr6,0x88139b6c
	if (!ctx.cr6.eq) goto loc_88139B6C;
	// cmpw cr6,r30,r18
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r18.s32, ctx.xer);
	// bgt cr6,0x88139d80
	if (ctx.cr6.gt) goto loc_88139D80;
loc_88139B6C:
	// rlwinm r10,r28,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x80;
	// clrlwi r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88139c00
	if (!ctx.cr6.eq) goto loc_88139C00;
	// addi r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 1;
	// rlwinm r11,r11,1,24,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFE;
	// clrlwi r30,r10,29
	ctx.r30.u64 = ctx.r10.u32 & 0x7;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x88139ba0
	if (!ctx.cr6.eq) goto loc_88139BA0;
	// lbzu r31,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r31.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// addi r27,r27,2
	ctx.r27.s64 = ctx.r27.s64 + 2;
	// lbzu r28,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r28.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// b 0x88139bc8
	goto loc_88139BC8;
loc_88139BA0:
	// subfic r9,r30,8
	ctx.xer.ca = ctx.r30.u32 <= 8;
	ctx.r9.s64 = 8 - ctx.r30.s64;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lbzu r11,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// clrlwi r5,r30,24
	ctx.r5.u64 = ctx.r30.u32 & 0xFF;
	// srw r4,r11,r7
	ctx.r4.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r7.u8 & 0x3F));
	// slw r3,r11,r5
	ctx.r3.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r5.u8 & 0x3F));
	// or r31,r4,r10
	ctx.r31.u64 = ctx.r4.u64 | ctx.r10.u64;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// clrlwi r28,r3,24
	ctx.r28.u64 = ctx.r3.u32 & 0xFF;
loc_88139BC8:
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// stbx r31,r26,r24
	PPC_STORE_U8(ctx.r26.u32 + ctx.r24.u32, ctx.r31.u8);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// cmpw cr6,r25,r20
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r20.s32, ctx.xer);
	// ble cr6,0x88139bf4
	if (!ctx.cr6.gt) goto loc_88139BF4;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// bl 0x880707f0
	ctx.lr = 0x88139BF0;
	sub_880707F0(ctx, base);
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
loc_88139BF4:
	// stb r31,0(r19)
	PPC_STORE_U8(ctx.r19.u32 + 0, ctx.r31.u8);
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// b 0x88139d78
	goto loc_88139D78;
loc_88139C00:
	// addi r9,r30,1
	ctx.r9.s64 = ctx.r30.s64 + 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// clrlwi r30,r9,29
	ctx.r30.u64 = ctx.r9.u32 & 0x7;
	// rlwinm r28,r11,1,24,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFE;
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
	// cmpwi cr6,r23,8
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 8, ctx.xer);
	// blt cr6,0x88139c68
	if (ctx.cr6.lt) goto loc_88139C68;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x88139c38
	if (!ctx.cr6.eq) goto loc_88139C38;
	// lbzu r10,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r10.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// addi r27,r27,2
	ctx.r27.s64 = ctx.r27.s64 + 2;
	// addi r9,r23,-8
	ctx.r9.s64 = ctx.r23.s64 + -8;
	// lbzu r28,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r28.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// b 0x88139c78
	goto loc_88139C78;
loc_88139C38:
	// subfic r10,r30,8
	ctx.xer.ca = ctx.r30.u32 <= 8;
	ctx.r10.s64 = 8 - ctx.r30.s64;
	// lbzu r8,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// clrlwi r9,r30,24
	ctx.r9.u64 = ctx.r30.u32 & 0xFF;
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r6,r28,24
	ctx.r6.u64 = ctx.r28.u32 & 0xFF;
	// slw r4,r8,r9
	ctx.r4.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// srw r5,r8,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r7.u8 & 0x3F));
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// or r10,r5,r6
	ctx.r10.u64 = ctx.r5.u64 | ctx.r6.u64;
	// clrlwi r28,r4,24
	ctx.r28.u64 = ctx.r4.u32 & 0xFF;
	// addi r9,r23,-8
	ctx.r9.s64 = ctx.r23.s64 + -8;
	// b 0x88139c78
	goto loc_88139C78;
loc_88139C68:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x88139c78
	if (!ctx.cr6.eq) goto loc_88139C78;
	// lbzu r28,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r28.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_88139C78:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x88139cc4
	if (!ctx.cr6.gt) goto loc_88139CC4;
	// lbz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_88139C88:
	// subfic r9,r30,7
	ctx.xer.ca = ctx.r30.u32 <= 7;
	ctx.r9.s64 = 7 - ctx.r30.s64;
	// clrlwi r8,r11,24
	ctx.r8.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// addi r6,r30,1
	ctx.r6.s64 = ctx.r30.s64 + 1;
	// srw r5,r8,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r7.u8 & 0x3F));
	// rlwimi r5,r10,1,0,30
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r10.u32, 1) & 0xFFFFFFFE) | (ctx.r5.u64 & 0xFFFFFFFF00000001);
	// clrlwi r30,r6,29
	ctx.r30.u64 = ctx.r6.u32 & 0x7;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// rlwinm r28,r28,1,24,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFE;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x88139cc0
	if (!ctx.cr6.eq) goto loc_88139CC0;
	// lbzu r11,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
loc_88139CC0:
	// bdnz 0x88139c88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88139C88;
loc_88139CC4:
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// ble cr6,0x88139d14
	if (!ctx.cr6.gt) goto loc_88139D14;
	// lbz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// mtctr r21
	ctx.ctr.u64 = ctx.r21.u64;
loc_88139CD8:
	// subfic r8,r30,7
	ctx.xer.ca = ctx.r30.u32 <= 7;
	ctx.r8.s64 = 7 - ctx.r30.s64;
	// clrlwi r7,r11,24
	ctx.r7.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r6,r8,24
	ctx.r6.u64 = ctx.r8.u32 & 0xFF;
	// addi r5,r30,1
	ctx.r5.s64 = ctx.r30.s64 + 1;
	// srw r4,r7,r6
	ctx.r4.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r6.u8 & 0x3F));
	// rlwimi r4,r9,1,0,30
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r9.u32, 1) & 0xFFFFFFFE) | (ctx.r4.u64 & 0xFFFFFFFF00000001);
	// clrlwi r30,r5,29
	ctx.r30.u64 = ctx.r5.u32 & 0x7;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// rlwinm r28,r28,1,24,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFE;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x88139d10
	if (!ctx.cr6.eq) goto loc_88139D10;
	// lbzu r11,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
loc_88139D10:
	// bdnz 0x88139cd8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88139CD8;
loc_88139D14:
	// addic. r31,r9,3
	ctx.xer.ca = ctx.r9.u32 > 4294967292;
	ctx.r31.s64 = ctx.r9.s64 + 3;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// add r4,r26,r24
	ctx.r4.u64 = ctx.r26.u64 + ctx.r24.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// ble 0x88139d40
	if (!ctx.cr0.gt) goto loc_88139D40;
	// subf r10,r10,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r10.s64;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
loc_88139D30:
	// lbzu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbx r9,r4,r11
	PPC_STORE_U8(ctx.r4.u32 + ctx.r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x88139d30
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88139D30;
loc_88139D40:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x88072260
	ctx.lr = 0x88139D4C;
	sub_88072260(ctx, base);
	// add r25,r31,r25
	ctx.r25.u64 = ctx.r31.u64 + ctx.r25.u64;
	// add r19,r31,r19
	ctx.r19.u64 = ctx.r31.u64 + ctx.r19.u64;
	// add r26,r31,r26
	ctx.r26.u64 = ctx.r31.u64 + ctx.r26.u64;
	// cmpw cr6,r25,r20
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r20.s32, ctx.xer);
	// ble cr6,0x88139d78
	if (!ctx.cr6.gt) goto loc_88139D78;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// bl 0x880707f0
	ctx.lr = 0x88139D74;
	sub_880707F0(ctx, base);
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
loc_88139D78:
	// cmpw cr6,r27,r16
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r16.s32, ctx.xer);
	// blt cr6,0x88139b5c
	if (ctx.cr6.lt) goto loc_88139B5C;
loc_88139D80:
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
}
