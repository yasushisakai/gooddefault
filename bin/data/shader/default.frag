#version 330

uniform vec3 lightPos;
uniform float lightIntensity;

in vec3 lightDir;
in vec3 vNormal;
in vec3 vPos;

out vec4 color;

void main()
{
  
  // should this be uniform??
  vec3 matColor = vec3(1.0);

  //================================================== 
  // ambient
  vec3 ambient = matColor * 0.1;

  //================================================== 
  // diffuse
  float cosTheta = max(0.0, dot(normalize(lightDir), normalize(vNormal)));
  float d = distance(lightPos, vPos); //light to frag pos
  float a = lightIntensity * cosTheta / (d * d);
  vec3 diffuse = matColor * a;

  color = vec4(ambient + diffuse, 1.0);

}
