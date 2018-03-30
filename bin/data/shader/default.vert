#version 330

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform vec3 lightPos;

in vec4 normal;
in vec4 position;

out vec3 vPos;
out float vCosTheta;

void main()
{
  gl_Position = modelViewProjectionMatrix * position;
  // p * v * m works 
  
  vPos = (modelMatrix * position).xyz;
  vec3 lightdir = lightPos - vPos;
  vec3 vNormal = (modelMatrix * normal).xyz;
  
  vCosTheta = max(0.0, dot(normalize(lightdir), normalize(vNormal)));
}
