// fragment shader
#version 150

out vec4 outputColor;
in float lightNormalDot;

void main ()
{
  outputColor = vec4(1.0 * lightNormalDot, 0.0, 0.0, 1.0);
}
