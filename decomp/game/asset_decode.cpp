// decomp/game/asset_decode.cpp — the game module's asset-decompression family (mode 1..4).
//
// The asset job pump FUN_8813a738 dispatches a compressed record to one of four decoders by its
// mode byte (1→sub_8813A248, 2→sub_8813A118, 3→sub_88139D90, 4→sub_88139A88; see the RT_DECLOG
// comment at out_reco/merged/merged_game.cpp:3563). This file translates them one mode at a time.
//
// TRANSLATED SO FAR:  mode 2 — sub_8813A118 (split-stream LZSS).
// STILL GENERATED   :  modes 1/3/4 (see DRIVER_NOTES §next / registry). Modes 1/3/4 are NOT leaves
//                      (mode 1 keeps a global 4KB ring dict + a memset via sub_88073BD0; modes 3/4
//                      call sub_88072260 + sub_880707F0), so they carry call boundaries and need
//                      the C1 register-file discipline — left for a session that can bank the
//                      RT_DECDUMP differential gate (below).
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
