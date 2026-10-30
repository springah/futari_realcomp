// RT_ROTATE present pass, fragment stage: sample the 1280x720 compose at the rotated uv produced by
// rotate_vs.hlsl. Set 0 binding 0 = combined image sampler (NEAREST or LINEAR chosen host-side,
// mirroring the present blit's RVK_UPFILTER auto rule). Alpha forced to 1 like the blit's opaque
// swapchain. Rebuild: python -I tools/gen_rotate_spirv.py (needs dxc; see render/rotate_spirv.h).
[[vk::combinedImageSampler]][[vk::binding(0, 0)]] Texture2D<float4> tex;
[[vk::combinedImageSampler]][[vk::binding(0, 0)]] SamplerState smp;

float4 main(float4 pos : SV_Position, [[vk::location(0)]] float2 uv : TEXCOORD0) : SV_Target0 {
  return float4(tex.Sample(smp, uv).rgb, 1.0);
}
