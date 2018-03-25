#version 330

uniform mat4 modelViewProjectionMatrix;
in vec4 position;
in vec2 texcoord;

out vec2 tCoord;

void main()
{ 
  gl_Position = modelViewProjectionMatrix * position;
  tCoord = texcoord; // this needs to be after gl_Position
}
