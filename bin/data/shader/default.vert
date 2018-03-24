#version 330

uniform mat4 modelViewProjectionMatrix;
uniform vec3 lightPos;

in vec4 normal;
in vec4 position;

out vec3 lightDir;
out vec3 vNormal;
out vec3 vPos;

void main()
{

  lightDir = lightPos - position.xyz; 
  vPos = position.xyz;
  vNormal = normal.xyz;

  gl_Position = modelViewProjectionMatrix * position;
}
