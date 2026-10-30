// RT_ROTATE present pass, vertex stage (render/vk_render.cpp, rvkRotate*). Fullscreen triangle from
// SV_VertexID (no vertex buffer); the viewport is the aspect-fit rectangle of the ROTATED frame, so
// t in [0,1]^2 spans exactly that rectangle. The push constant picks the rotation and the shader
// emits the SOURCE uv for each output position (affine, so per-vertex interpolation is exact):
//   rot == 90  (clockwise):         src = (t.y, 1 - t.x)  -> frame top lands on the RIGHT edge
//   rot == 270 (counter-clockwise): src = (1 - t.y, t.x)  -> frame top lands on the LEFT edge
// Rebuild: python -I tools/gen_rotate_spirv.py (needs dxc; see render/rotate_spirv.h).
struct PC { uint rot; };
[[vk::push_constant]] PC pc;

struct VSOut {
  float4 pos : SV_Position;
  [[vk::location(0)]] float2 uv : TEXCOORD0;
};

VSOut main(uint id : SV_VertexID) {
  float2 t = float2((float)((id << 1) & 2u), (float)(id & 2u));
  VSOut o;
  o.pos = float4(t * 2.0 - 1.0, 0.0, 1.0);
  o.uv = (pc.rot == 270u) ? float2(1.0 - t.y, t.x) : float2(t.y, 1.0 - t.x);
  return o;
}
