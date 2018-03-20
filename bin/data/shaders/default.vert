// vertex shader
#version 150


in vec4 position;
in vec4 normal;

uniform mat4 modelViewProjectionMatrix;
uniform mat4 MV;
uniform vec3 lightP;

out float lightNormalDot;

void main ()
{
  
  mat4 m = transpose(inverse(MV));
  vec4 n = normalize(m * normal);

  vec3 lightPosition = lightP - position.xyz;
  lightNormalDot = max(dot(n.xyz, lightPosition), 0.0);
  gl_Position = modelViewProjectionMatrix * position;
}
