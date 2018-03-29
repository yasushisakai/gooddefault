#version 330

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform vec3 lightPos;

in vec4 normal;
in vec4 position;

// out vec3 lightDir;
out vec3 normalCam;
out vec3 lightDirCam;
out vec3 eyeCam;
out vec3 vPos;

void main()
{
  gl_Position = modelViewProjectionMatrix * position;
  // p * v * m works 

  vPos = (modelMatrix * position).xyz;

  vec3 vPosCam = (modelViewMatrix * position).xyz;
  eyeCam = vec3(0,0,0) - vPos;

  vec3 lightPosCam = (viewMatrix * vec4(lightPos, 1.0)).xyz;
  lightDirCam = lightPosCam + eyeCam;

  normalCam = (modelViewMatrix * normal).xyz;
}
