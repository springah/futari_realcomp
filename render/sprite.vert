#version 450
// Futari port sprite VS (passthrough — positions are pre-transformed to NDC on the CPU).
// Replaced later by XenosRecomp-translated guest vertex shaders.
layout(location = 0) in vec2 inPos;   // NDC
layout(location = 1) in vec2 inUV;
layout(location = 2) in vec4 inColor;  // D3DCOLOR, already RGBA float
layout(location = 0) out vec2 vUV;
layout(location = 1) out vec4 vColor;
void main() {
    gl_Position = vec4(inPos, 0.0, 1.0);
    vUV = inUV;
    vColor = inColor;
}
