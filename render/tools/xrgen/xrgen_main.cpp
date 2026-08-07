// xrgen_main.cpp — minimal driver for the XenosRecomp glvl-d3d9 ShaderRecompiler.
// Reads a Xenos shader container (.xvu/.xpu) and writes the generated D3D9-style HLSL text.
// No FXC: we only want recompiler.out (the HLSL), which we transpile to SPIR-V ourselves.
//   usage: xrgen <container-in> <hlsl-out> <shader_common.h>
#include "shader_recompiler.h"

static std::string readFile(const char* p) {
    FILE* f = fopen(p, "rb");
    if (!f) { fprintf(stderr, "cannot open %s\n", p); exit(2); }
    fseek(f, 0, SEEK_END); long n = ftell(f); fseek(f, 0, SEEK_SET);
    std::string s; s.resize(n);
    fread(s.data(), 1, n, f); fclose(f);
    return s;
}

int main(int argc, char** argv) {
    if (argc < 4) { fprintf(stderr, "usage: xrgen <container> <out.hlsl> <shader_common.h>\n"); return 1; }
    std::string blob = readFile(argv[1]);
    std::string include = readFile(argv[3]);
    ShaderRecompiler r;
    r.recompile(reinterpret_cast<const uint8_t*>(blob.data()), include);
    FILE* o = fopen(argv[2], "wb");
    fwrite(r.out.data(), 1, r.out.size(), o);
    fclose(o);
    fprintf(stderr, "wrote %s (%zu bytes, %s)\n", argv[2], r.out.size(), r.isPixelShader ? "pixel" : "vertex");
    return 0;
}
