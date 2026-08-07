#version 450
// Futari port sprite FS (passthrough — texture * vertex color, alpha-blended).
// Untextured draws bind a 1x1 white texture so this reduces to flat vertex color.
layout(location = 0) in vec2 vUV;
layout(location = 1) in vec4 vColor;
layout(location = 0) out vec4 outColor;
layout(set = 0, binding = 0) uniform sampler2D tex;
void main() {
    vec4 t = texture(tex, vUV);
    outColor = t * vColor;
}
