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


void main(
	in float4 iPosition0 : POSITION0,
	in float4 iTexCoord0 : TEXCOORD0,
	out float4 oTexCoord0 : TEXCOORD0,
	out float4 oPos : POSITION)
{
	float4 c255 = float4(2, 0.00390625, -0.5, 0);

	float4 r0 = 0.0;
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

	r1.xy = iPosition0.xy;
	r1.z = 0.0;
	r1.w = 1.0;
	r0.xy = iTexCoord0.xy;
	oPos.zw = max(r1.zw, r1.zw);
	oPos.xy = r1.xy * c255.xx + c255.zz;
	oTexCoord0.xy = r0.xy * c255.yy;
	return;
}