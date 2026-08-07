// ---------------------------------------------------------------------------
// game_88079970_Gpu_CreateTexture.cpp
//
// GUEST : 0x88079970, game module (base 0x88000000), 72 instructions.
// WHAT  : allocates a D3D texture object plus its physical base/mip memory and
//         patches the two GPU fetch-constant addresses into the header.
//         Called by Page_EnsureTexture (0x8808D838) as
//             Gpu_CreateTexture(512, 512, 1, 1, 0, 0x18280143, 0, 3)
//         to make each of the six 512x512 select-screen scroll-cache pages
//         (NOTES_select_compose.md, "FUN_8808D838 — page-texture ensure").
// BUILD : -O1.  NOT -O2.  See "Which compiler flags" below — this is library
//         code, so the title's own -O2 rule does not apply to it.
//
// IDENTITY IS PROVEN, NOT INFERRED.  This is Microsoft's own
// D3DDevice_CreateTexture out of the statically linked D3D9 2.0.9328 runtime.
// The symbol-named XDK 20209.3 library
//     C:/Users/shant/Desktop/projects/_tools/xdk/xdk20209/extracted/XDK/lib/xbox/d3d9.lib
// (Xenon COFF: machine 0x01F2, struct fields little-endian, code big-endian —
// the same hand-parse that identified D3DDevice_Resolve on 2026-08-03) carries
// `D3DDevice_CreateTexture` in archive member '/782', section 243, 288 bytes =
// 72 instructions.  That body is instruction-for-instruction IDENTICAL to the
// bytes at 0x88079970; only the relocated branch targets differ.  Its eight
// COFF relocations name every callee outright, which is where the declarations
// below come from — none of these names were guessed:
//     __savegprlr_22 / __restgprlr_22 -> 0x88071140 / 0x88071190
//                       (confirmed by disassembly: std r22..r31 + stw r12, and
//                        the matching ld / lwz / mtlr mirror)
//     XMemAlloc  (x3)                 -> 0x880861D0
//     XMemFree   (x2)                 -> 0x88086268
//     ?SetTextureHeader@D3D@@YAXW4_D3DRESOURCETYPE@@IIIIKW4_D3DFORMAT@@
//       W4MIPPACKINGTYPE@1@KHIPAUD3DBaseTexture@@PAK4@Z  -> 0x88079648
// That last decorated name is a complete parameter list, including the
// otherwise-invisible D3D::MIPPACKINGTYPE argument, so the callee prototype
// below is transcribed from the linker rather than reverse-engineered.
//
// The public prototype is the period-correct XDK 9328 header, d3d9.h:2091:
//     __out D3DBaseTexture* WINAPI D3DDevice_CreateTexture(
//         DWORD Width, DWORD Height, DWORD Depth, DWORD Levels, DWORD Usage,
//         D3DFORMAT Format, D3DPOOL UnusedPool, D3DRESOURCETYPE D3DType);
// `UnusedPool` really is unused: r9 is the one incoming argument register the
// prologue never spills to a non-volatile.
//
// The symbol is spelled `Gpu_CreateTexture` only because that is the name the
// campaign's Page_EnsureTexture translation already calls; every other name
// here is Microsoft's, so the two can be reconciled later.
//
// ---------------------------------------------------------------------------
// STATUS: ASM-EXACT.  All 72 words reproduce (2026-08-05).  The last residual —
// `addi` where the image has `ori` — was closed by the MemoryProtect spelling
// below; read that comment before touching this file, and note that the
// spelling is load-bearing in TWO independent ways, not one.
//
// VERIFY (the -O1 is not optional; the default -O2 gives 78 instructions):
//   python matchlab/ppcmatch.py --check game 0x88079970 Gpu_CreateTexture \
//          src/game_88079970_Gpu_CreateTexture.cpp --flags=-O1
// ---------------------------------------------------------------------------
//
// Which compiler flags.  The title's own code is -O2 and -O1 is never right for
// it, but this function is not the title's code: it is a Microsoft library
// object that the game merely linked.  At -O2 the body comes out 78
// instructions and diverges from the 16th word, because the epilogue gets
// tail-duplicated at each of the three `return NULL` sites.  At -O1 it shares a
// single `li r3,0; b epilogue` block exactly as the original does.  -O1 is not
// merely the best of the set, it is the ONLY member of it: a 37-way flag sweep
// (-O1/-Os/-Ot/-Og/-Ox/-O2 crossed with -Ob0/1/2 and with -Oa -Ow -Oi -Oy -Oy-
// -Op -Oc -Oc- -Gy -GS- -Zl -Gs -GF -GR- -Gz -Gr -QVMXn) produces exactly three
// body lengths — 72 for -O1 / -O1 -Ob* / -Og -Os*, 78 for -Og/-Ox/-O2, and 115
// for -Os/-Ot — and every 72-instruction member is byte-identical to plain -O1.
// No flag anywhere in that sweep changes a single word of this function.
// ---------------------------------------------------------------------------

typedef unsigned long  DWORD;   // 'K' in the decorated callee name
typedef unsigned int   UINT;    // 'I' in the decorated callee name
typedef int            INT;     // 'H' in the decorated callee name
typedef unsigned int   SIZE_T;

#define NULL    0
#define TRUE    1
#define FALSE   0

// ---------------------------------------------------------------------------
// XMemAlloc / XMemFree attribute word  (xbox.h:698 of the 9328 XDK, verbatim)
// ---------------------------------------------------------------------------
#define MAKE_XALLOC_ATTRIBUTES(ObjectType,            \
                               HeapTracksAttributes,  \
                               MustSucceed,           \
                               FixedSize,             \
                               AllocatorId,           \
                               Alignment,             \
                               MemoryProtect,         \
                               ZeroInitialize,        \
                               MemoryType)            \
    ((DWORD)( (ObjectType)                      |     \
             ((HeapTracksAttributes)   << 13)   |     \
             ((MustSucceed)            << 14)   |     \
             ((FixedSize)              << 15)   |     \
             ((AllocatorId)            << 16)   |     \
             ((Alignment)              << 24)   |     \
             ((MemoryProtect)          << 28)   |     \
             ((ZeroInitialize)         << 30)   |     \
             ((MemoryType)             << 31)))

#define XALLOC_MEMTYPE_HEAP                 0
#define XALLOC_MEMTYPE_PHYSICAL             1

#define XALLOC_MEMPROTECT_READWRITE         2
#define XALLOC_MEMPROTECT_WRITECOMBINE      3

#define XALLOC_ALIGNMENT_4                  0x1
#define XALLOC_ALIGNMENT_16                 0x4
#define XALLOC_PHYSICAL_ALIGNMENT_4K        0xC

#define eXALLOCAllocatorId_D3D              128

// The 0x34-byte texture object itself: cached, zero-filled, 16-byte aligned
// heap memory owned by the D3D allocator id.                    => 0x64800000
#define D3D_TEXTURE_ALLOC_ATTRIBUTES                                        \
    MAKE_XALLOC_ATTRIBUTES(0, 0, 0, 0, eXALLOCAllocatorId_D3D,              \
                           XALLOC_ALIGNMENT_16,                             \
                           XALLOC_MEMPROTECT_READWRITE,                     \
                           TRUE, XALLOC_MEMTYPE_HEAP)

// The same block on the way out; XMemFree has no use for the zero-fill bit.
//                                                               => 0x24800000
#define D3D_TEXTURE_FREE_ATTRIBUTES                                         \
    MAKE_XALLOC_ATTRIBUTES(0, 0, 0, 0, eXALLOCAllocatorId_D3D,              \
                           XALLOC_ALIGNMENT_16,                             \
                           XALLOC_MEMPROTECT_READWRITE,                     \
                           FALSE, XALLOC_MEMTYPE_HEAP)

// Texel memory is PHYSICAL, 4K aligned (D3DTEXTURE_ALIGNMENT) and never
// zeroed.  Memory-protect is the only run-time part of the word.
//                                            => 0x8C800000 | (Protect << 28)
#define D3D_TEXELS_ALLOC_ATTRIBUTES(Protect)                                \
    MAKE_XALLOC_ATTRIBUTES(0, 0, 0, 0, eXALLOCAllocatorId_D3D,              \
                           XALLOC_PHYSICAL_ALIGNMENT_4K,                    \
                           (Protect),                                       \
                           FALSE, XALLOC_MEMTYPE_PHYSICAL)

// The free-side word for texel memory, and note it is NOT the alloc word
// replayed: the image has memory-protect hard-wired to write-combine and the
// alignment field reading 1, i.e. XMemFree only needs the physical/protect pair
// to find the block.  Decoded straight from the `lis r4,0xB180` at 0x88079A60.
//                                                               => 0xB1800000
#define D3D_TEXELS_FREE_ATTRIBUTES                                          \
    MAKE_XALLOC_ATTRIBUTES(0, 0, 0, 0, eXALLOCAllocatorId_D3D,              \
                           XALLOC_ALIGNMENT_4,                              \
                           XALLOC_MEMPROTECT_WRITECOMBINE,                  \
                           FALSE, XALLOC_MEMTYPE_PHYSICAL)

extern "C" void* XMemAlloc(SIZE_T dwSize, DWORD dwAllocAttributes);   // 0x880861D0
extern "C" void  XMemFree(void* pAddress, DWORD dwAllocAttributes);   // 0x88086268

// ---------------------------------------------------------------------------
// d3d9types.h
// ---------------------------------------------------------------------------
enum _D3DFORMAT { D3DFMT_FORCE_DWORD = 0x7FFFFFFF };
typedef enum _D3DFORMAT D3DFORMAT;

enum _D3DPOOL { D3DPOOL_DEFAULT = 0, D3DPOOL_FORCE_DWORD = 0x7FFFFFFF };
typedef enum _D3DPOOL D3DPOOL;

enum _D3DRESOURCETYPE { D3DRTYPE_TEXTURE = 3, D3DRTYPE_FORCE_DWORD = 0x7FFFFFFF };
typedef enum _D3DRESOURCETYPE D3DRESOURCETYPE;

// Texel memory sits on a 4K boundary, which is exactly why the two address
// fields below only have room for bits 31..12 of the pointer.
#define D3DTEXTURE_ALIGNMENT        4096

#define D3DUSAGE_CPU_CACHED_MEMORY  0x00000004L   // Xbox 360 extension

// ---------------------------------------------------------------------------
// The hardware texture fetch constant (d3d9gpu.h).  Six DWORDs.  This function
// only writes DWORD 1 (BaseAddress) and DWORD 5 (MipAddress) — everything else
// is D3D::SetTextureHeader's job — so the untouched words stay opaque with
// their real contents named in the comment.
//
// The PPC compiler lays bitfields out MSB-first, so, exactly as xbox.h does for
// XALLOC_ATTRIBUTES, the ordering is flipped for the duration of the struct.
// Getting this wrong is visible: the two `rlwimi rD,rS,0,0,19` / `0,20,31`
// inserts at 0x88079A78/7C are what a 20-bit field based at bit 12 compiles to.
// ---------------------------------------------------------------------------
#pragma bitfield_order(push)
#pragma bitfield_order(lsb_to_msb)

struct GPUTEXTURE_FETCH_CONSTANT
{
    DWORD Dword0;                   // +0x00  Type/Sign/Clamp/Pitch/Tiled

    DWORD DataFormat        : 6;    // +0x04  GPUTEXTUREFORMAT
    DWORD Endian            : 2;
    DWORD RequestSize       : 2;
    DWORD Stacked           : 1;
    DWORD ClampPolicy       : 1;
    DWORD BaseAddress       : 20;   //        physical base >> 12

    DWORD Dword2;                   // +0x08  Size (1D/2D/3D/stack union)
    DWORD Dword3;                   // +0x0C  NumFormat/Swizzle/ExpAdjust/filters
    DWORD Dword4;                   // +0x10  VolFilter/Min+MaxMipLevel/LODBias

    DWORD BorderColor       : 2;    // +0x14  GPUBORDERCOLOR
    DWORD ForceBCWToMax     : 1;
    DWORD TriClamp          : 2;
    INT   AnisoBias         : 4;
    DWORD Dimension         : 2;
    DWORD PackedMips        : 1;
    DWORD MipAddress        : 20;   //        physical mip base >> 12
};

#pragma bitfield_order(pop)

// D3DResource header + MipFlush + the fetch constant = 0x34 bytes, which is the
// literal the allocation site uses.  D3DTexture derives from this and adds no
// data members, so sizeof() is the same for both (d3d9.h).
struct D3DBaseTexture
{
    DWORD Common;                       // +0x00
    DWORD ReferenceCount;               // +0x04
    DWORD Fence;                        // +0x08
    DWORD ReadFence;                    // +0x0C
    DWORD Identifier;                   // +0x10
    DWORD BaseFlush;                    // +0x14
    DWORD MipFlush;                     // +0x18
    GPUTEXTURE_FETCH_CONSTANT Format;   // +0x1C .. +0x33
};

// ---------------------------------------------------------------------------
// 0x88079648 — the internal header builder shared by every D3DDevice_Create*
// entry point.  Types are transcribed from the decorated name in d3d9.lib.  The
// names of the three constant-zero slots follow XGSetTextureHeaderEx, whose
// parameter list is the same idea in the same order (Flags, ExpBias, Pitch) and
// whose types line up one for one (K, H, I) — that part is analogy, not proof.
//
// MIPPACKINGTYPE is internal, so its constants are named from what 0x88079648
// actually does with the argument: 0 and 1 are stored straight through as the
// packed/unpacked flag, and 2 means "decide for me", whereupon the callee
// derives packed = (Levels > 1) at 0x880796E8.
// ---------------------------------------------------------------------------
namespace D3D
{
    enum MIPPACKINGTYPE
    {
        MIPPACKING_UNPACKED = 0,
        MIPPACKING_PACKED   = 1,
        MIPPACKING_DEFAULT  = 2     // pack iff the texture has mip levels
    };

    void SetTextureHeader(D3DRESOURCETYPE D3DType,
                          UINT            Width,
                          UINT            Height,
                          UINT            Depth,
                          UINT            Levels,
                          DWORD           Usage,
                          D3DFORMAT       Format,
                          MIPPACKINGTYPE  MipPacking,
                          DWORD           Flags,
                          INT             ExpBias,
                          UINT            Pitch,
                          D3DBaseTexture* pTexture,
                          DWORD*          pBaseSize,
                          DWORD*          pMipSize);
}

// ---------------------------------------------------------------------------
// D3DDevice_CreateTexture
// ---------------------------------------------------------------------------
D3DBaseTexture* Gpu_CreateTexture(DWORD           Width,
                                  DWORD           Height,
                                  DWORD           Depth,
                                  DWORD           Levels,
                                  DWORD           Usage,
                                  D3DFORMAT       Format,
                                  D3DPOOL         UnusedPool,
                                  D3DRESOURCETYPE D3DType)
{
    D3DBaseTexture* pTexture;
    void*           pBaseAddress;
    void*           pMipAddress = NULL;
    DWORD           BaseSize;
    DWORD           MipSize;
    DWORD           AllocAttributes;
    DWORD           MemoryProtect;

    pTexture = (D3DBaseTexture*)XMemAlloc(sizeof(D3DBaseTexture),
                                          D3D_TEXTURE_ALLOC_ATTRIBUTES);
    if (pTexture == NULL)
        return NULL;

    // Fills in the whole fetch constant except the two memory addresses, and
    // reports how much physical memory the base image and the mip chain need.
    D3D::SetTextureHeader(D3DType, Width, Height, Depth, Levels, Usage, Format,
                          D3D::MIPPACKING_DEFAULT, 0, 0, 0,
                          pTexture, &BaseSize, &MipSize);

    // Uncached texels are write-combined; a texture the CPU means to read back
    // is mapped read/write instead.  WRITECOMBINE is READWRITE + 1, so this one
    // selection is the whole difference between the two attribute words.
    //
    // *** DO NOT "SIMPLIFY" THIS SWITCH.  It is the load-bearing statement of
    // the whole file and it is carrying TWO separate constraints at once.
    //
    // (1) It is what makes index 39 (0x88079A0C) come out as `ori r11,r11,2`.
    //     Any expression that reaches the shift as a plain OR gets distributed
    //     — the optimizer applies (a|c) << n == (a << n) | (c << n) and folds
    //     2 << 28 into the trailing constant, yielding `oris ...,0xAC80` and a
    //     70- or 71-instruction body.  Confirmed dead, do not retry: `RW | !x`,
    //     `RW | (x == 0)`, `RW | ((~Usage >> 2) & 1)`,
    //     `RW | ((~Usage & D3DUSAGE_CPU_CACHED_MEMORY) >> 2)`, `^`, `-`, `|=`,
    //     the ternary, the if/`|= 1` form, the same set behind a helper
    //     function / a pointer / a bitfield read, `(mp & 3) << 28`,
    //     `(mp & 0xF) << 28`, an `unsigned char` intermediate, and
    //     `mp * 0x10000000`.  `+` survives the distribution but selects `addi`.
    //     A two-arm `switch` is the construct that does neither: the arms stay
    //     real basic blocks past the expression optimizer, and the if-conversion
    //     that collapses them afterwards emits the common bits with `ori`.  A
    //     `do { ... break; ... } while (0)` if-converts the same way and also
    //     yields `ori` in 72 instructions, but it lands in the 63/72 group
    //     described under (2).  `if`/`else` and any 3-arm `switch` if-convert
    //     too late and leave a real branch — 73 or 74 instructions.
    //
    // (2) The CONDITION must be `!(Usage & ...)`, not `Usage & ...`, and the
    //     arms must be in this order.  Every switch spelling below emits the
    //     same 72 instructions and the same `ori`, but they differ in ONE word
    //     pair at the very end of the function, because the shape of the join
    //     perturbs the nonvolatile ranking:
    //         switch (Usage & D3DUSAGE_CPU_CACHED_MEMORY)  -> 63/72: swaps
    //             r29/r30 between AllocAttributes and pBaseAddress, which drags
    //             indices 41,42,44,53,61 and the whole rlwimi tail with it
    //         switch ((Usage >> 2) & 1)                    -> 70/72
    //         switch ((Usage & D3DUSAGE_CPU_CACHED_MEMORY) >> 2)  -> 70/72
    //         switch ((Usage & D3DUSAGE_CPU_CACHED_MEMORY) != 0)  -> 70/72
    //         switch ((Usage << 29) >> 31)                 -> 70/72
    //         switch (Cached) via a local                  -> 70/72
    //     the 70/72 group all lose indices 67 and 69: the MipAddress insert
    //     comes out `rlwimi r10,r22,0,0,19` + `stw r10` instead of the image's
    //     `rlwimi r22,r10,0,20,31` + `stw r22`.  Only the `!` form leaves
    //     pMipAddress' insert coalesced into r22, which is what the image does.
    //
    //   * It is not a flag and not the compiler revision.  The earlier 38-flag
    //     sweep and the 37-flag sweep recorded at the top of this file both come
    //     back with every 72-instruction configuration byte-identical, and both
    //     compilers shipped in XDK 9328 were tried — 15.00.8327
    //     (TechPreview\Mar09Compiler) and 15.00.8153 (bin\win32).  XDK 9328.9
    //     from Z: has cl.exe / c1.dll / c1xx.dll / c2.dll MD5-identical to
    //     those, so the QFE line changes nothing here.  (That also retires
    //     matchlab/README.md's open "QFE >= 4, exact revision indeterminate"
    //     question for this class of difference.)
    //   * RETRACTED: the previous revision of this comment concluded that the
    //     compiler emits `ori` only for an operand it cannot range-analyse and
    //     that "no legitimate source spelling reaches that state".  That was
    //     wrong on both counts — the operand here is a fully known 0/1 and the
    //     spelling below is ordinary C.  The mistake was assuming the choice is
    //     made in the expression optimizer; it is made after if-conversion.
    switch (!(Usage & D3DUSAGE_CPU_CACHED_MEMORY))
    {
    case 0:  MemoryProtect = XALLOC_MEMPROTECT_READWRITE;    break;
    default: MemoryProtect = XALLOC_MEMPROTECT_WRITECOMBINE; break;
    }

    AllocAttributes = D3D_TEXELS_ALLOC_ATTRIBUTES(MemoryProtect);

    pBaseAddress = XMemAlloc(BaseSize, AllocAttributes);
    if (pBaseAddress == NULL)
    {
        XMemFree(pTexture, D3D_TEXTURE_FREE_ATTRIBUTES);
        return NULL;
    }

    // A packed mip tail lives inside the base allocation, so MipSize is often 0
    // — for the single-level 512x512 scroll-cache pages it always is.
    if (MipSize != 0)
    {
        pMipAddress = XMemAlloc(MipSize, AllocAttributes);
        if (pMipAddress == NULL)
        {
            XMemFree(pTexture, D3D_TEXTURE_FREE_ATTRIBUTES);
            XMemFree(pBaseAddress, D3D_TEXELS_FREE_ATTRIBUTES);
            return NULL;
        }
    }

    // Both allocations are 4K aligned, so the low 12 bits of the two fetch
    // constant words survive the insert untouched — which is the whole reason
    // these compile to a pair of rlwimi rather than a shift and an OR.
    //
    // These two lines must stay in THIS order.  Swapping them still gives 72
    // instructions, but the compiler emits the two load/insert/store chains in
    // source order, and whichever chain is written first has its insert
    // coalesced into the pointer register — which changes the reference count
    // of that pointer and re-sorts the nonvolatile ranking above it.  Mip-first
    // costs indices 63,65,66,67,68,69.  Also ruled out and equally inert or
    // worse: hoisting either address into a temp before the writes, a
    // `GPUTEXTURE_FETCH_CONSTANT*` local (73 instructions), `/ 4096` instead of
    // `>> 12`, a `UINT` cast, declaring the two addresses as DWORD instead of
    // void*, and hand-writing the read-modify-write against the raw DWORDs with
    // either operand order (the compiler canonicalises the OR, so the source
    // operand order does not reach instruction selection at all).
    pTexture->Format.BaseAddress = (DWORD)pBaseAddress >> 12;
    pTexture->Format.MipAddress  = (DWORD)pMipAddress  >> 12;

    return pTexture;
}
