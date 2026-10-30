// xexflat -- dump the flat guest image of an XEX2 exactly as XenonRecomp sees it (XenonUtils Image::ParseImage),
// plus its PE section table. Mac replacement for ghidra_futari_decomp/xexdump.exe (Windows-only, and it writes a
// 0-byte image for kiniro_*/palm_normal -- NOTE_other_modes §0). Needs a XenonUtils built WITH the futari
// xex-size-fix (tools/xenonrecomp_mac_eqv_fixes.patch), otherwise kiniro_* over-reads 32 KB past the heap block.
//   build: see scripts/regen_kiniro_mac.sh (it builds this next to XenonRecomp)
//   usage: xexflat <in.xex> <out.img.bin>
#include <image.h>
#include <cstdio>
#include <fstream>
#include <iterator>
#include <vector>

int main(int argc, char** argv)
{
    if (argc < 3) { std::fprintf(stderr, "usage: xexflat <in.xex> <out.img.bin>\n"); return 2; }
    std::ifstream f(argv[1], std::ios::binary);
    std::vector<uint8_t> d((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    if (d.empty()) { std::fprintf(stderr, "cannot read %s\n", argv[1]); return 1; }
    Image img = Image::ParseImage(d.data(), d.size());
    if (!img.data) { std::fprintf(stderr, "ParseImage failed for %s\n", argv[1]); return 1; }
    FILE* o = std::fopen(argv[2], "wb");
    if (!o || std::fwrite(img.data.get(), 1, img.size, o) != img.size) { std::fprintf(stderr, "write failed\n"); return 1; }
    std::fclose(o);
    std::printf("base=0x%zX size=0x%X entry=0x%zX\n", img.base, img.size, img.entry_point);
    for (const auto& s : img.sections)
        std::printf("section %-8s 0x%08zX..0x%08zX flags=%u\n", s.name.c_str(), s.base, s.base + s.size, unsigned(s.flags));
    return 0;
}
