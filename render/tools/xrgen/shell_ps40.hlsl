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
	float4 c248 = float4(0, 0, 0, 0);
	float4 c249 = float4(0, 0, 0, 0);
	float4 c250 = float4(0, 0, 0, 0);
	float4 c251 = float4(6, 1, 0, 3);
	float4 c252 = float4(0.6666667, 0.33333334, -0.5, 0.5);
	float4 c253 = float4(0.11448, 0.29891, 0.58661, 4);
	float4 c254 = float4(0.9411765, 0.78431374, 0.5686275, 5);
	float4 c255 = float4(2, 0, 0, 0);

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

	r1.xyzw = tex2D(smpColorMap, r0.xy).wxyz;
	r0.x = dot(r1.wyz, c253.xyz);
	r0.xyz = r0.xxx * c254.xyz;
	ps = log2(abs(r0.x));
	r0.x = ps;
	ps = log2(abs(r0.y));
	r0.y = ps;
	ps = log2(abs(r0.z));
	r0.z = ps;
	r0.xyw = r0.zxy * g_PSC_F1_ColorRGB.yyy;
	ps = exp2(r0.w);
	r1.w = ps;
	r0.w = g_PSC_F1_ColorHSV.x + -c251.y;
	ps = exp2(r0.x);
	r1.z = ps;
	r0.x = min(r1.w, r1.z);
	ps = exp2(r0.y);
	r1.y = ps;
	r0.y = max(r1.w, r1.z);
	ps = r1.w - r1.z;
	r3.x = ps;
	r2.x = max(r0.y, r1.y);
	ps = r1.y - r1.w;
	r3.y = ps;
	r0.x = min(r0.x, r1.y);
	ps = r1.z - r1.y;
	r3.z = ps;
	r0.y = r2.x + -r0.x;
	ps = rcp(r2.x);
	r0.x = ps;
	r0.x = r0.y * r0.x;
	ps = c251.x * r0.y;
	r0.y = ps;
	r0.x = r2.x == 0.0 ? c251.z : r0.x;
	r2.yz = r1.yw == r2.xx;
	ps = rcp(r0.y);
	r0.y = ps;
	r1.yz = r3.yz * r0.yy + c252.xy;
	r0.x = r0.x * g_PSC_F1_ColorHSV.y;
	ps = max(r3.x, r3.x);
	p0 = c251.z == 0.0 && r0.x != 0.0;
	r1.w = p0 ? 0.0 : c251.z + 1.0;
	ps = r0.y * ps;
	r0.y = ps;
	r0.z = r2.z == 0.0 ? r1.y : r1.z;
	r0.z = r2.y == 0.0 ? r0.z : r0.y;
	ps = c251.y + r0.z;
	r0.y = ps;
	r0.y = -r0.z > 0.0 ? r0.y : r0.z;
	ps = g_PSC_F1_ColorHSV.x + r0.y;
	r0.z = ps;
	if (p0)
	{
		r0.y = r0.w + r0.y;
	}
	if (p0)
	{
		r0.w = r0.z >= c251.y;
	}
	if (p0)
	{
		r0.y = r0.w == 0.0 ? r0.z : r0.y;
	}
	if (p0)
	{
		ps = c251.x * r0.y;
		r0.z = ps;
	}
	if (p0)
	{
		ps = floor(r0.z);
		r0.y = ps;
	}
	if (p0)
	{
		r2.z = r0.z + -r0.y;
	}
	if (p0)
	{
		r0.z = c251.y > r0.y;
	}
	if (p0)
	{
		r2.w = -r2.z + c251.y;
		ps = c251.y - r0.x;
		r2.y = ps;
	}
	if (p0)
	{
		r2.zw = -r0.xx * r2.zw + c251.yy;
	}
	if (p0)
	{
		r2.yzw = r2.wyz * r2.xxx;
	}
	p0 = r1.w == 0.0 && r0.z == 0.0;
	r1.w = p0 ? 0.0 : r1.w + 1.0;
	if (p0)
	{
		r0.x = c255.x > r0.y;
	}
	p0 = r1.w == 0.0 && r0.x != 0.0;
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
		r0.x = c251.w > r0.y;
	}
	p0 = r1.w == 0.0 && r0.x != 0.0;
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
		r0.x = c253.w > r0.y;
	}
	p0 = r1.w == 0.0 && r0.x != 0.0;
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
		r0.x = c254.w > r0.y;
	}
	p0 = r1.w == 0.0 && r0.x != 0.0;
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
	r0.x = g_PSC_F1_ColorHSV.z + c252.w;
	r0.yzw = r2.xyz + c252.zzz;
	r0.xyz = r0.yzw * g_PSC_F1_ColorRGB.xxx + r0.xxx;
	oC0.xyz = r0.xyz * g_PSC_F1_MaterialAmbient.xyz;
	ps = g_PSC_F1_MaterialAmbient.w * r1.x;
	oC0.w = ps;
	return;
}