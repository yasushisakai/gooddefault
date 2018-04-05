# Good Default shaders

shader files and it's parameters for a good "enough" 3d realtime rendering

- easy to use for different programs using glsl
  - openframeworks
  - processing
  - Three.js
  - etc...

1. distance attenuation lighting
2. shadow mapping
3. [SSAO](http://john-chapman-graphics.blogspot.nl/2013/01/ssao-tutorial.html)

TODO: consider [deferred rendering approach?](https://github.com/nama-gatsuo/ofxDeferredShading)

## memo
 
- blender -> ply 
  - -Z Forward
  - Y Up

- [ofProgrammableShader uniforms](https://forum.openframeworks.cc/t/ofshader-given-glsl-variables/16567/2)

- how many passes do I need?
  - geom pass
    - first pass to get the position, normal, depth, albedo? <- do we need this??
  - shadow pass
    - second pass makes the shadow map (which creates an ortho projection)
  - SSAO and integration pass
    - third pass applies SSAO and calculates the overall color (ambient + diffuse)
