// colour vertex shader
// Simple geometry pass
// texture coordinates and normals will be ignored.

cbuffer MatrixBuffer : register(b0)
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
};

struct InputType
{
	float4 position : POSITION;
	float2 uv       : TEXCOORD0;
};

struct OutputType
{
	float4 position : SV_POSITION;
	float2 uv       : TEXCOORD0;
};

OutputType main(InputType input)
{
	OutputType output;

	// v1
	float4x4 scaleMatrix = worldMatrix; // worldMatrix is an identity matrix
	scaleMatrix._11_22_33 *= 2.0f;
	
	// v2
	/*
	float4x4 scaleMatrix = (float4x4) 0;
	scaleMatrix._11_22_33 = 2.0f;
	scaleMatrix._44 = 1.0f;
	*/
	
	// Change the position vector to be 4 units for proper matrix calculations.
	input.position.w = 1.0f;
    
	// Calculate the position of the vertex against the world, view, and projection matrices.
	output.position = mul(input.position, scaleMatrix);
	output.position = mul(output.position, worldMatrix);
	output.position = mul(output.position, viewMatrix);
	output.position = mul(output.position, projectionMatrix);

	output.uv = input.uv;

	return output;
}