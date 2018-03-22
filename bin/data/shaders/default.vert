// vertex shader
#version 150


in vec4 position;
in vec4 normal;

uniform mat4 modelViewProjectionMatrix;
uniform vec3 lightP; // this is model pos

out float lightNormalDot;

void main ()
{
  
  vec3 lightVec = normalize(position.xyz - lightP);
  lightNormalDot = max(dot(normal.xyz, lightVec), 0.0);
  gl_Position = modelViewProjectionMatrix * position;

}
