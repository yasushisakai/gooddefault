// fragment shader
#version 150

in float lightNormalDot;
out vec4 color;

void main ()
{
 // outputColor = vec4(1.0 * lightNormalDot, 0.0, 0.0, 1.0);
  vec4 ambient = vec4(1.0, 1.0, 1.0, 1.0);
  vec3 matColor = vec3(1.0, 0.0, 0.0);
  vec4 diffuse = vec4(matColor * lightNormalDot, 1.0);
  color = ambient * 0.1 + diffuse * 0.9;
}
