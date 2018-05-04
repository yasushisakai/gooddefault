# version 400

uniform sampler2DRect colorTex;
uniform sampler2DRect normalTex;
uniform sampler2DRect depthTex;

in vec3 lightDir;

out vec4 resultColor;

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

vec3 remapNormal (vec3 normal) {
  return vec3(
      map(normal.x, 0.0, 1.0, -1.0, 1.0),
      map(normal.y, 0.0, 1.0, -1.0, 1.0),
      map(normal.z, 0.0, 1.0, -1.0, 1.0)
      );
}

void main () {

  float y =  768 - gl_FragCoord.y; // TODO: hardcoding the height (it's flipped)

  vec3 color = texture(colorTex, vec2(gl_FragCoord.x, y)).rbg;
  vec3 normal = remapNormal(texture(normalTex, vec2(gl_FragCoord.x, y)).rbg);
  float depth = texture(depthTex, vec2(gl_FragCoord.x, y)).r;

  float vCosTheta = max(0.0, dot(normalize(lightDir), normalize(normal)));

  resultColor = vec4(color * vCosTheta, 1.0);

}
