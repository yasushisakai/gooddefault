#version 330

uniform sampler2DRect dTex;
uniform float height;

in vec2 tCoord;

out vec4 color;

void main()
{
  float depth = texture(dTex, tCoord).r;
  color = vec4(vec3(depth), 1.0);
}
