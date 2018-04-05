#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
                void drawLine(ofVec3f, ofVec3f);
                of3dPrimitive logo;

                float angle;
                ofEasyCam cam;
                ofShader shader;
                ofNode light;

                ofFbo geomFbo;
                enum BUFFER_TYPES {
                  BUFFER_TYPE_COLOR = 0,
                  BUFFER_TYPE_NORMAL,
                  BUFFER_TYPE_DEPTH
                };

};

