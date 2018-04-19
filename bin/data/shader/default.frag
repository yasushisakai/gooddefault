# version 400

uniform sampler2DRect colorTex;

in vec4 gl_FragCoord;
out vec4 color;


void main () {

  vec3 texColor = texture(colorTex, gl_FragCoord.xy).rbg;

  color = vec4(texColor, 1.0);

}
