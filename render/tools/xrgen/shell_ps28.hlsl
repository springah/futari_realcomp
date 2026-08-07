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
sampler2D smpColorMap : register(s0);

void main(
	in float4 iPos : VPOS,
	in float4 iTexCoord0 : TEXCOORD0,
	out float4 oC0 : COLOR0)
{
	float4 c252 = float4(6, 1, 3, 0.5);
	float4 c253 = float4(2, 5, 4, -0.5);
	float4 c254 = float4(0, 0.003125, 0.6666667, 0.33333334);
	float4 c255 = float4(0.005, -0.0046875, -0.009166666, 0.0015625);

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

	r0.z = r0.y + c254.y;
	r1.xyzw = r0.xyxy + c255.xyzw;
	ps = max(r0.x, r0.x);
	r0.x = ps;
	r0.w = tex2D(smpColorMap, r1.zw).z;
	r0.y = tex2D(smpColorMap, r0.xz).y;
	r0.x = tex2D(smpColorMap, r1.xy).x;
	ps = log2(abs(r0.x));
	r0.x = ps;
	ps = log2(abs(r0.y));
	r0.y = ps;
	ps = log2(abs(r0.w));
	r0.z = ps;
	r0.xzw = r0.zxy * g_PSC_F1_ColorRGB.yyy;
	ps = exp2(r0.w);
	r0.w = ps;
	r1.x = g_PSC_F1_ColorHSV.x + -c252.y;
	ps = exp2(r0.x);
	r0.x = ps;
	r0.y = min(r0.w, r0.x);
	ps = exp2(r0.z);
	r0.z = ps;
	r1.y = max(r0.w, r0.x);
	ps = r0.w - r0.x;
	r2.y = ps;
	r2.x = max(r1.y, r0.z);
	ps = r0.z - r0.w;
	r2.z = ps;
	r0.y = min(r0.y, r0.z);
	ps = r0.x - r0.z;
	r2.w = ps;
	r0.y = r2.x + -r0.y;
	ps = rcp(r2.x);
	r0.x = ps;
	r0.x = r0.y * r0.x;
	ps = c252.x * r0.y;
	r0.y = ps;
	r0.x = r2.x == 0.0 ? c254.x : r0.x;
	r1.zw = r0.zw == r2.xx;
	ps = rcp(r0.y);
	r0.w = ps;
	r0.yz = r2.zw * r0.ww + c254.zw;
	r0.x = r0.x * g_PSC_F1_ColorHSV.y;
	ps = max(r2.y, r2.y);
	p0 = c254.x == 0.0 && r0.x != 0.0;
	r1.y = p0 ? 0.0 : c254.x + 1.0;
	ps = r0.w * ps;
	r0.w = ps;
	r0.y = r1.w == 0.0 ? r0.y : r0.z;
	r0.z = r1.z == 0.0 ? r0.y : r0.w;
	ps = c252.y + r0.z;
	r0.y = ps;
	r0.y = -r0.z > 0.0 ? r0.y : r0.z;
	ps = g_PSC_F1_ColorHSV.x + r0.y;
	r0.z = ps;
	if (p0)
	{
		r0.y = r1.x + r0.y;
	}
	if (p0)
	{
		r0.w = r0.z >= c252.y;
	}
	if (p0)
	{
		r0.y = r0.w == 0.0 ? r0.z : r0.y;
	}
	if (p0)
	{
		ps = c252.x * r0.y;
		r0.z = ps;
	}
	if (p0)
	{
		ps = floor(r0.z);
		r0.y = ps;
	}
	if (p0)
	{
		r1.z = r0.z + -r0.y;
	}
	if (p0)
	{
		r0.z = c252.y > r0.y;
	}
	if (p0)
	{
		r1.w = -r1.z + c252.y;
		ps = c252.y - r0.x;
		r1.x = ps;
	}
	if (p0)
	{
		r1.zw = -r0.xx * r1.zw + c252.yy;
	}
	if (p0)
	{
		r2.yzw = r1.wxz * r2.xxx;
	}
	p0 = r1.y == 0.0 && r0.z == 0.0;
	r1.y = p0 ? 0.0 : r1.y + 1.0;
	if (p0)
	{
		r0.x = c253.x > r0.y;
	}
	p0 = r1.y == 0.0 && r0.x != 0.0;
	r1.y = p0 ? 0.0 : r1.y + 1.0;
	if (p0)
	{
		ps = max(r2.x, r2.x);
		r2.y = ps;
	}
	p0 = r1.y == 1.0;
	ps = p0 ? 0.0 : (r1.y == 0.0 ? 1.0 : r1.y);
	r1.y = ps;
	if (p0)
	{
		r0.x = c252.z > r0.y;
	}
	p0 = r1.y == 0.0 && r0.x != 0.0;
	r1.y = p0 ? 0.0 : r1.y + 1.0;
	if (p0)
	{
		r2.zw = max(r2.yz, r2.yz);
	}
	p0 = r1.y == 1.0;
	ps = p0 ? 0.0 : (r1.y == 0.0 ? 1.0 : r1.y);
	r1.y = ps;
	if (p0)
	{
		r0.x = c253.z > r0.y;
	}
	p0 = r1.y == 0.0 && r0.x != 0.0;
	r1.y = p0 ? 0.0 : r1.y + 1.0;
	if (p0)
	{
		r2.xzw = max(r2.wxz, r2.wxz);
	}
	p0 = r1.y == 1.0;
	ps = p0 ? 0.0 : (r1.y == 0.0 ? 1.0 : r1.y);
	r1.y = ps;
	if (p0)
	{
		r0.x = c253.y > r0.y;
	}
	p0 = r1.y == 0.0 && r0.x != 0.0;
	r1.y = p0 ? 0.0 : r1.y + 1.0;
	if (p0)
	{
		r2.xw = max(r2.yx, r2.yx);
	}
	p0 = r1.y == 1.0;
	ps = p0 ? 0.0 : (r1.y == 0.0 ? 1.0 : r1.y);
	r1.y = ps;
	if (p0)
	{
		r2.xw = max(r2.xw, r2.xw);
	}
	p0 = r1.y - 1.0 <= 0.0;
	ps = p0 ? 0.0 : (r1.y - 1.0);
	r1.y = ps;
	if (p0)
	{
		r2.xzw = max(r2.zwx, r2.zwx);
	}
	p0 = r1.y - 1.0 <= 0.0;
	ps = p0 ? 0.0 : (r1.y - 1.0);
	r1.y = ps;
	p0 = r1.y - 1.0 <= 0.0;
	ps = p0 ? 0.0 : (r1.y - 1.0);
	r1.y = ps;
	if (p0)
	{
		ps = max(r2.x, r2.x);
		r2.y = ps;
	}
	p0 = r1.y - 1.0 <= 0.0;
	ps = p0 ? 0.0 : (r1.y - 1.0);
	r1.y = ps;
	if (p0)
	{
		ps = max(r2.w, r2.w);
		r2.x = ps;
	}
	p0 = r1.y - 1.0 <= 0.0;
	ps = p0 ? 0.0 : (r1.y - 1.0);
	r1.y = ps;
	p0 = r1.y == 1.0;
	ps = p0 ? 0.0 : (r1.y == 0.0 ? 1.0 : r1.y);
	r1.y = ps;
	if (p0)
	{
		r2.yz = max(r2.xx, r2.xx);
	}
	r0.x = g_PSC_F1_ColorHSV.z + c252.w;
	r0.yzw = r2.xyz + c253.www;
	r0.xyz = r0.yzw * g_PSC_F1_ColorRGB.xxx + r0.xxx;
	oC0.xyz = r0.xyz * g_PSC_F1_MaterialAmbient.xyz;
	ps = max(g_PSC_F1_MaterialAmbient.w, g_PSC_F1_MaterialAmbient.w);
	oC0.w = ps;
	return;
}