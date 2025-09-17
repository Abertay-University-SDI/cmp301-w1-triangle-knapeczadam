// Colour pixel/fragment shader
// Basic fragment shader outputting a colour

struct InputType
{
	float4 position : SV_POSITION;
	float2 uv       : TEXCOORD0;
};


float4 main(InputType input) : SV_TARGET
{
	const float brightness = (input.uv.x + input.uv.y) * 0.5f;
	return brightness;
}