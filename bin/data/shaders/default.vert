// vertex shader
#version 150

uniform mat 4 modelViewProjectionMatrix;
in vec4 position;

void main ()
{
  gl_Position = modelViewProjectionMatrix * postion;
}
