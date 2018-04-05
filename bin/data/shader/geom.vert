#version 400

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;

uniform float farClip;
uniform float nearClip;

in vec4 position; 
in vec4 color;
in vec4 normal;

out vec4 vColor; 
out vec4 vNormal;
out vec4 camPos;
out float vDepth;

void main ()
{
  gl_Position = modelViewProjectionMatrix * position;

  vColor = color;  
  vNormal = normal;

  camPos = modelViewMatrix * position;
  vDepth = camPos.z / (farClip - nearClip);
}
