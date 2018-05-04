#version 400

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelMatrix;
uniform vec3 lightPos;

in vec4 position;
out vec3 lightDir;

void main () {
  gl_Position = modelViewProjectionMatrix * position;

  vec4 vPos = modelMatrix * position;
  lightDir = vPos.xyz - lightPos;
}
