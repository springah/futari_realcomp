#ifndef SHADER_COMMON_H_INCLUDED
#define SHADER_COMMON_H_INCLUDED

struct CubeMapData
{
    float3 cubeMapDirections[2];
    uint cubeMapIndex;
};

float4 texCUBE(samplerCUBE s, float3 texCoord, inout CubeMapData cubeMapData)
{
    return texCUBE(s, cubeMapData.cubeMapDirections[texCoord.z]);
}

float4 cube(float4 value, inout CubeMapData cubeMapData)
{
    uint index = cubeMapData.cubeMapIndex;
    cubeMapData.cubeMapDirections[index] = value.xyz;
    ++cubeMapData.cubeMapIndex;
    
    return float4(0.0, 0.0, 0.0, index);
}

float4 dst(float4 src0, float4 src1)
{
    float4 dest;
    dest.x = 1.0;
    dest.y = src0.y * src1.y;
    dest.z = src0.z;
    dest.w = src1.w;
    return dest;
}

float4 max4(float4 src0)
{
    return max(max(src0.x, src0.y), max(src0.z, src0.w));
}

#endif

float4 g_PSC_F1_ColorHSV : register(c0);
float4 g_PSC_F1_ColorRGB : register(c1);
float4 g_PSC_F1_MaterialAmbient : register(c2);
float4 g_PSC_F1_TextureSize : register(c20);
sampler2D smpColorMap : register(s0);

void main(
	in float4 iPos : VPOS,
	in float4 iTexCoord0 : TEXCOORD0,
	out float4 oC0 : COLOR0)
{
	float4 c252 = float4(2, 3, 0, 0);
	float4 c253 = float4(1, -0.5, 0, 0.125);
	float4 c254 = float4(6, 5, 0.5, 4);
	float4 c255 = float4(0.6666667, 0.33333334, 0.1, 0.4);

	float4 r0 = iTexCoord0;
	float4 r1 = 0.0;
	float4 r2 = 0.0;
	float4 r3 = 0.0;
	float4 r4 = 0.0;
	float4 r5 = 0.0;
	float4 r6 = 0.0;
	float4 r7 = 0.0;
	float4 r8 = 0.0;
	float4 r9 = 0.0;
	float4 r10 = 0.0;
	float4 r11 = 0.0;
	float4 r12 = 0.0;
	float4 r13 = 0.0;
	float4 r14 = 0.0;
	float4 r15 = 0.0;
	float4 r16 = 0.0;
	float4 r17 = 0.0;
	float4 r18 = 0.0;
	float4 r19 = 0.0;
	float4 r20 = 0.0;
	float4 r21 = 0.0;
	float4 r22 = 0.0;
	float4 r23 = 0.0;
	float4 r24 = 0.0;
	float4 r25 = 0.0;
	float4 r26 = 0.0;
	float4 r27 = 0.0;
	float4 r28 = 0.0;
	float4 r29 = 0.0;
	float4 r30 = 0.0;
	float4 r31 = 0.0;
	int a0 = 0;
	int aL = 0;
	bool p0 = false;
	float ps = 0.0;
	CubeMapData cubeMapData = (CubeMapData)0;

	r1.z = r0.x + g_PSC_F1_TextureSize.z;
	ps = max(r0.y, r0.y);
	r1.w = ps;
	r1.y = max(r0.y, r0.y);
	ps = max(r0.x, r0.x);
	r6.x = ps;
	r6.yzw = r0.yyx + g_PSC_F1_TextureSize.ywz;
	ps = max(r0.x, r0.x);
	r8.xyzw = r0.xyyx + g_PSC_F1_TextureSize.xywz;
	ps = g_PSC_F1_TextureSize.x + ps;
	r1.x = ps;
	r0.xyzw = tex2D(smpColorMap, r0.xy).wxyz;
	r2.xyz = tex2D(smpColorMap, r8.wz).xyz;
	r3.xyz = tex2D(smpColorMap, r1.zw).xyz;
	r4.xyz = tex2D(smpColorMap, r6.wy).xyz;
	r5.xyz = tex2D(smpColorMap, r6.xz).xyz;
	r6.xyz = tex2D(smpColorMap, r6.xy).xyz;
	r7.xyz = tex2D(smpColorMap, r8.xz).xyz;
	r8.xyz = tex2D(smpColorMap, r8.xy).xyz;
	r1.xyz = tex2D(smpColorMap, r1.xy).xyz;
	r1.xyz = r8.zyx + r1.zyx;
	r1.xyz = r1.xyz + r7.zyx;
	r1.xyz = r1.xyz + r6.zyx;
	r1.xyz = r1.xyz + r5.zyx;
	r1.xyz = r1.xyz + r4.zyx;
	r1.xyz = r1.xyz + r3.zyx;
	r1.xyz = r1.xyz + r2.zyx;
	r0.yzw = -r1.xyz * c253.www + r0.wzy;
	r0.z = dot(abs(r0.ywz), c253.xxx);
	r0.yw = r0.zz * c255.zw;
	r0.z = r0.z + r0.z;
	ps = log2(abs(r0.y));
	r0.y = ps;
	ps = log2(abs(r0.z));
	r0.z = ps;
	ps = log2(abs(r0.w));
	r0.w = ps;
	r0.yzw = r0.wyz * g_PSC_F1_ColorRGB.yyy;
	ps = exp2(r0.w);
	r0.w = ps;
	r1.x = g_PSC_F1_ColorHSV.x + -c253.x;
	ps = exp2(r0.y);
	r0.y = ps;
	r1.y = min(r0.w, r0.y);
	ps = exp2(r0.z);
	r0.z = ps;
	r1.z = max(r0.w, r0.y);
	ps = r0.w - r0.y;
	r3.x = ps;
	r2.x = max(r1.z, r0.z);
	ps = r0.z - r0.w;
	r3.y = ps;
	r1.y = min(r1.y, r0.z);
	ps = r0.y - r0.z;
	r3.z = ps;
	r0.y = r2.x + -r1.y;
	ps = rcp(r2.x);
	r1.y = ps;
	r1.y = r0.y * r1.y;
	ps = c254.x * r0.y;
	r1.z = ps;
	r0.y = r2.x == 0.0 ? c253.z : r1.y;
	r2.yz = r0.zw == r2.xx;
	ps = rcp(r1.z);
	r0.z = ps;
	r1.yz = r3.yz * r0.zz + c255.xy;
	r0.y = r0.y * g_PSC_F1_ColorHSV.y;
	ps = max(r3.x, r3.x);
	p0 = c253.z == 0.0 && r0.y != 0.0;
	r1.w = p0 ? 0.0 : c253.z + 1.0;
	ps = r0.z * ps;
	r0.z = ps;
	r0.w = r2.z == 0.0 ? r1.y : r1.z;
	r0.z = r2.y == 0.0 ? r0.w : r0.z;
	ps = c253.x + r0.z;
	r0.w = ps;
	r0.z = -r0.z > 0.0 ? r0.w : r0.z;
	ps = g_PSC_F1_ColorHSV.x + r0.z;
	r0.w = ps;
	if (p0)
	{
		r0.z = r1.x + r0.z;
	}
	if (p0)
	{
		r1.x = r0.w >= c253.x;
	}
	if (p0)
	{
		r0.z = r1.x == 0.0 ? r0.w : r0.z;
	}
	if (p0)
	{
		ps = c254.x * r0.z;
		r1.x = ps;
	}
	if (p0)
	{
		ps = floor(r1.x);
		r0.z = ps;
	}
	if (p0)
	{
		r1.y = r1.x + -r0.z;
	}
	if (p0)
	{
		r1.x = c253.x > r0.z;
	}
	if (p0)
	{
		r1.z = -r1.y + c253.x;
		ps = c253.x - r0.y;
		r2.y = ps;
	}
	if (p0)
	{
		r2.zw = -r0.yy * r1.yz + c253.xx;
	}
	if (p0)
	{
		r2.yzw = r2.wyz * r2.xxx;
	}
	p0 = r1.w == 0.0 && r1.x == 0.0;
	r1.w = p0 ? 0.0 : r1.w + 1.0;
	if (p0)
	{
		r1.x = c252.x > r0.z;
	}
	p0 = r1.w == 0.0 && r1.x != 0.0;
	r1.w = p0 ? 0.0 : r1.w + 1.0;
	if (p0)
	{
		ps = max(r2.x, r2.x);
		r2.y = ps;
	}
	p0 = r1.w == 1.0;
	ps = p0 ? 0.0 : (r1.w == 0.0 ? 1.0 : r1.w);
	r1.w = ps;
	if (p0)
	{
		r1.x = c252.y > r0.z;
	}
	p0 = r1.w == 0.0 && r1.x != 0.0;
	r1.w = p0 ? 0.0 : r1.w + 1.0;
	if (p0)
	{
		r2.zw = max(r2.yz, r2.yz);
	}
	p0 = r1.w == 1.0;
	ps = p0 ? 0.0 : (r1.w == 0.0 ? 1.0 : r1.w);
	r1.w = ps;
	if (p0)
	{
		r1.x = c254.w > r0.z;
	}
	p0 = r1.w == 0.0 && r1.x != 0.0;
	r1.w = p0 ? 0.0 : r1.w + 1.0;
	if (p0)
	{
		r2.xzw = max(r2.wxz, r2.wxz);
	}
	p0 = r1.w == 1.0;
	ps = p0 ? 0.0 : (r1.w == 0.0 ? 1.0 : r1.w);
	r1.w = ps;
	if (p0)
	{
		r1.x = c254.y > r0.z;
	}
	p0 = r1.w == 0.0 && r1.x != 0.0;
	r1.w = p0 ? 0.0 : r1.w + 1.0;
	if (p0)
	{
		r2.xw = max(r2.yx, r2.yx);
	}
	p0 = r1.w == 1.0;
	ps = p0 ? 0.0 : (r1.w == 0.0 ? 1.0 : r1.w);
	r1.w = ps;
	if (p0)
	{
		r2.xw = max(r2.xw, r2.xw);
	}
	p0 = r1.w - 1.0 <= 0.0;
	ps = p0 ? 0.0 : (r1.w - 1.0);
	r1.w = ps;
	if (p0)
	{
		r2.xzw = max(r2.zwx, r2.zwx);
	}
	p0 = r1.w - 1.0 <= 0.0;
	ps = p0 ? 0.0 : (r1.w - 1.0);
	r1.w = ps;
	p0 = r1.w - 1.0 <= 0.0;
	ps = p0 ? 0.0 : (r1.w - 1.0);
	r1.w = ps;
	if (p0)
	{
		ps = max(r2.x, r2.x);
		r2.y = ps;
	}
	p0 = r1.w - 1.0 <= 0.0;
	ps = p0 ? 0.0 : (r1.w - 1.0);
	r1.w = ps;
	if (p0)
	{
		ps = max(r2.w, r2.w);
		r2.x = ps;
	}
	p0 = r1.w - 1.0 <= 0.0;
	ps = p0 ? 0.0 : (r1.w - 1.0);
	r1.w = ps;
	p0 = r1.w == 1.0;
	ps = p0 ? 0.0 : (r1.w == 0.0 ? 1.0 : r1.w);
	r1.w = ps;
	if (p0)
	{
		r2.yz = max(r2.xx, r2.xx);
	}
	r0.y = g_PSC_F1_ColorHSV.z + c254.z;
	r1.xyz = r2.xyz + c253.yyy;
	r0.yzw = r1.xyz * g_PSC_F1_ColorRGB.xxx + r0.yyy;
	oC0.xyz = r0.yzw * g_PSC_F1_MaterialAmbient.xyz;
	ps = g_PSC_F1_MaterialAmbient.w * r0.x;
	oC0.w = ps;
	return;
}