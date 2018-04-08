#version 400


in vec4 vColor;
in vec4 vNormal;
in vec4 camPos;
in float vDepth;

uniform float farClip;
uniform float nearClip;

layout (location = 0) out vec4 outputColor0;
layout (location = 1) out vec4 outputColor1;
layout (location = 2) out vec4 outputColor2;
layout (location = 3) out vec4 outputColor3;


float map(
    float a, 
    float rangeMin,
    float rangeMax,
    float newRangeMin,
    float newRangeMax
    ){
  float p = (a - rangeMin) / (rangeMax - rangeMin);
  return (newRangeMax - newRangeMin) * p + newRangeMin;
}

void main () {

  outputColor0 = vColor; // BUFFER_TYPE_COLOR

  vec3 n = normalize(vNormal.xyz);

  n = vec3(
      map(n.x, -1.0, 1.0, 0.0, 1.0),
      map(n.y, -1.0, 1.0, 0.0, 1.0),
      map(n.z, -1.0, 1.0, 0.0, 1.0)
      );

  outputColor1 = vec4(n, 1.0); // BUFFER_TYPE_NORMAL

  outputColor2 = vec4(vec3(abs(camPos.z / (farClip - nearClip))), 1.0); // BUFFER_TYPE_DEPTH
}
