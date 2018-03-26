#version 330

in vec4 position;

uniform mat4 shadowMVP;

void main()
{
  gl_Position = shadowMVP * position; 
}
