// 0x8206D328 (shell module, default.xex) — per-channel colour multiply, 0x80 == 1.0.
// MATCHED against the original: 56/56 instructions byte-identical.
// Compiler: XDK 9328 (June 2009) "Microsoft (R) 32-bit C/C++ Optimizing Compiler
//           Version 15.00.8327 for PowerPC", flags: -O2 -TP
//
// Notes on the shape (each of these is load-bearing for the match):
//   * `tmin` returns a const reference (std::min's signature). Binding the literal
//     0xFF to it materialises a *fresh stack temporary per call site* — that is why
//     the original stores 0xFF four times and alternates two stack slots, and why the
//     clamp is a pointer-select (addi/bgt/addi/lwz) rather than a value select.
//   * The byte-extraction pairs are declared in the order 0, 3, 2, 1. That ordering
//     alone decides which physical registers channels 1 and 3 land in.
//   * 0x80 is unity, so the product is >> 7, and a multiplier byte of 0xFF is ~1.99x
//     (over-bright, saturating) — hence the clamp.

typedef unsigned int u32;

template <class T>
static inline const T& tmin(const T& a, const T& b) { return b < a ? b : a; }

u32 ColorMul(u32 c, u32 m)
{
    if (m == 0x80808080)
        return c;

    u32 c0 = (c      ) & 0xFF, m0 = (m      ) & 0xFF;
    u32 c3 = (c >> 24) & 0xFF, m3 = (m >> 24) & 0xFF;
    u32 c2 = (c >> 16) & 0xFF, m2 = (m >> 16) & 0xFF;
    u32 c1 = (c >>  8) & 0xFF, m1 = (m >>  8) & 0xFF;

    u32 b0 = tmin((c0 * m0) >> 7, 0xFFu);
    u32 b3 = tmin((c3 * m3) >> 7, 0xFFu);
    u32 b2 = tmin((c2 * m2) >> 7, 0xFFu);
    u32 b1 = tmin((c1 * m1) >> 7, 0xFFu);

    return (((b3 << 8 | b2) << 8 | b1) << 8) | b0;
}
