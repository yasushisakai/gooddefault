#version 150

uniform vec3 lightPos;

in vec3 lightDir;
in vec3 vNormal;
in vec3 vPos;

out vec4 color;

void main()
{
  vec3 matColor = vec3(1.0);


  float cosTheta = max(0.0, dot(normalize(lightDir), normalize(vNormal)));

  float d = distance(lightPos, vPos);

  vec3 ambientColor = matColor * 0.2 / d;

  float attenuation = 3 * cosTheta / d;

  // color = vec4(matColor*cosTheta, 1.0);
  // color = vec4(1.0 * cosTheta, 1.0 * cosTheta, 1.0 * cosTheta, 1.0);
  color = vec4(ambientColor + matColor * attenuation, 1.0);

}
