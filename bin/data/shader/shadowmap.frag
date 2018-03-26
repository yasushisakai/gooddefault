#version 330

out vec3 depth;

void main()
{
  depth = vec3(gl_FragCoord.z, 0.0, 0.0);
}
