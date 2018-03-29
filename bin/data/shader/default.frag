#version 330

uniform vec3 lightPos;
uniform float lightIntensity;

in vec3 normalCam;
in vec3 lightDirCam;
in vec3 eyeCam;
in vec3 vPos;

out vec4 color;

void main()
{
  
  // should this be uniform??
  vec3 matColor = vec3(1.0);

  //================================================== 
  // ambient
  vec3 ambient = matColor * 0.05;

  //================================================== 
  // diffuse
  vec3 n = normalize(normalCam);
  vec3 l = normalize(lightDirCam);
  
  float cosTheta = clamp(dot(n, l), 0, 1);
  float d = length(lightPos - vPos); //light to frag pos
  float a = lightIntensity * cosTheta / (d * d);
  vec3 diffuse = matColor * a;

  color = vec4(ambient + diffuse, 1.0);
}
