#!/bin/bash
cd ~/xr-work || exit 1
clang++ -O2 -std=c++20 obj_merged/*.o -o futari_merged \
  -Wl,--start-group \
  ~/xr-derisk/build/XenonUtils/libXenonUtils.a \
  ~/xr-derisk/build/XenonAnalyse/libLibXenonAnalyse.a \
  ~/xr-derisk/build/thirdparty/disasm/libdisasm.a \
  ~/xr-derisk/build/thirdparty/xxHash/cmake_unofficial/libxxhash.a \
  ~/xr-derisk/build/thirdparty/fmt/libfmt.a \
  -Wl,--end-group -lpthread 2>/tmp/link2.err
echo "exit=$?"
grep -oP "multiple definition of \`\K[^']+" /tmp/link2.err | sort -u > /tmp/dupsyms.txt
wc -l /tmp/dupsyms.txt
grep -oP "undefined reference to \`\K[^']+" /tmp/link2.err | sort -u > /tmp/undefsyms.txt
wc -l /tmp/undefsyms.txt
echo "--- dup categories ---"
sed -E 's/_[0-9]+$//' /tmp/dupsyms.txt | sed 's/^__imp__//' | sort -u
echo "--- undef syms ---"
cat /tmp/undefsyms.txt
