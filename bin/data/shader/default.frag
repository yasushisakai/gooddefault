#version 330

uniform vec3 lightPos;
uniform float attenuation;

uniform vec4 gl_FragCoord;
uniform sampler2DRect noiseTex;
uniform int kernelSize;
uniform vec3 kernel[18];

in vec3 vPos;
in vec3 cPos;
in float vCosTheta;
in vec3 vNormal;

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
  // SSAO
  vec2 whichP = mod(gl_FragCoord.xy, 4);
  vec3 rvec = (texture(noiseTex, whichP)).rgb; // random rotation vector
  vec3 tangent = normalize(rvec - vNormal * dot(rvec, vNormal));
  vec3 bitTangent = cross(vNormal, tangent);
  mat3 tbn = mat3(tangent, bitTangent, vNormal);

  float occlusion = 0.0;
  for(int i = 0; i < kernelSize; i++) {

    vec3 sample = tbn * kernel[i]; // position of the sample
    sample = sample * 5.0 + cPos // 5.0 is radius;
    
  }


  //================================================== 
  // gamma correction
  vec3 linear = ambient + diffuse * a;
  vec3 gamma = vec3(0.6); // usually 1/2.2 but...

  color = vec4(pow(linear, gamma), 1.0);
}
