#version 330

uniform vec3 lightPos;
uniform float attenuation;

in vec3 vPos;
in float vCosTheta;

out vec4 color;

void main()
{
  
  // should this be uniform??
  vec3 matColor = vec3(1.0);

  //================================================== 
  // ambient
  vec3 ambient = matColor * 0.002;

  //================================================== 
  // diffuse
  float d = length(vPos - lightPos);
  float a = 1.0 / (1.0 + attenuation * pow(d, 2));
  vec3 diffuse = matColor * vCosTheta;

  //================================================== 
  // gamma correction
  vec3 linear = ambient + diffuse * a;
  vec3 gamma = vec3(0.6); // usually 1/2.2 but...

  color = vec4(pow(linear, gamma), 1.0);
}
