// 0x8810B7B0 (game) — poll: run a gate check, and act on the object only if it passes.
// 7 copies (0x8810B7B0 + 0x80 apart), and a 17-instruction sibling family at 0x8810B7E8 x7 that
// is this function plus a fixup on the returned pointer.  91 + 119 = 210 instructions.
//
// ★ THE POINT OF THIS FILE IS A NEW TELL, NOT THE SCORE. ★
//
// A VALUE HELD IN A *VOLATILE* REGISTER ACROSS A CALL MEANS THE CALLEE IS `static` IN THE SAME
// TRANSLATION UNIT.
//
// The image keeps `self` in r5 across `bl 0x88109180`:
//     mr r5, r3  /  bl 0x88109180  /  cmpwi cr6,r3,0  /  beq  /  mr r3, r5  /  bl 0x8810AFB8
// r5 is a VOLATILE parameter register.  Nothing in the PowerPC ABI lets a caller expect it to
// survive a call, so this looked at first like whole-program optimisation — and if it were, these
// functions would be permanently out of matchlab's reach, because `cl -c -GL` emits an IL object
// with no machine code in it (verified: the harness cannot read one at all).
//
// It is not LTCG.  It is MSVC's CUSTOM CALLING CONVENTION for functions with internal linkage:
// when the compiler can see the whole callee, it tracks exactly which volatiles that callee
// leaves alone and lets the caller keep live values in them.  Measured here, all three states:
//     callee declared `extern`               -> caller uses the safe ABI: `mr r31,r3`, and pays
//                                               for a nonvolatile save.  15 insn, 2/13.
//     callee `static` but NOT a leaf          -> same safe ABI.  MSVC will not promise anything
//                                               through a call it cannot see.
//     callee `static` AND a leaf              -> `mr r9,r3` — A VOLATILE, exactly the image's
//                                               shape.  13/13 instructions, 9/13 words.
//
// ⇒ WHEN A FUNCTION HOLDS SOMETHING IN r4-r10 ACROSS A `bl`, DO NOT DECLARE THAT CALLEE EXTERN.
//   Put it in the same file as `static`.  An extern declaration cannot produce those bytes, and
//   no amount of tuning the caller will fix it.
//
// PARKED at 9/13.  The four remaining words are the two masked `bl`s and the CHOICE of volatile:
// the image uses r5, we get r9 or r10 depending on how much register pressure the callee body
// creates (measured: 3/5 globals -> r9, 7 globals -> r10).  That choice is a function of the real
// callee's clobber set, so it is not tunable from this file — 0x88109180 (37 insn) has to be
// decompiled first, and then this caller should fall out for free.  That is the next step here,
// and it is worth doing: it unlocks both families at once.

typedef unsigned int u32;

struct Self;

extern u32 g_gateA, g_gateB;

// 0x8810AFB8 — the action taken when the gate passes.
extern "C" void Act(Self* s);

// 0x88109180 — the gate.  MUST be `static` here (see above); it is 37 instructions in the image
// and this stand-in only reproduces the property the caller depends on, namely which volatile
// registers survive it.  Replace it with the real decompilation to finish the family.
__declspec(noinline) static int Check()
{
    if (g_gateA == 2)
        return 0;
    if (g_gateB == 0)
        return 0;
    return 1;
}

extern "C" void Poll(Self* s)
{
    if (Check() != 0)
        Act(s);
}
