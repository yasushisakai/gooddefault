#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  ofSetVerticalSync(true);

  // logo
  ofMesh mesh;
  mesh.load("mlcs.ply");
  logo = of3dPrimitive(mesh);

  // light
  light.setGlobalPosition(ofVec3f(3, 4, 5));

  // cam
  cam.setTarget(ofVec3f());
  cam.setDistance(30);

  // set variable for shaders
  shader.load("shader/default");
  shader.begin();
    shader.setUniform3f("lightPos", light.getPosition());
    shader.setUniform1f("attenuation", 0.25f);
  shader.end();

  }

//--------------------------------------------------------------
void ofApp::update(){
  logo.rotateDeg(0.5, ofVec3f(0, 1, 0));
}

//--------------------------------------------------------------
void ofApp::draw(){

  ofEnableDepthTest();

  shader.begin();
    cam.begin();
    ofSetColor(10);
    ofFill();
      logo.draw();
    shader.end();

    ofSetColor(255, 255, 0);

    ofDrawAxis(5.0f);
    ofPoint lightScreenPos = cam.worldToScreen(light.getPosition());
    cam.end();
  shader.end();

  ofDisableDepthTest();

  ofSetColor(255);
  stringstream ss;
  ss << "framerate: " << ofGetFrameRate() << endl;

  ofDrawBitmapString(ss.str().c_str(), 10, 20);
  ss.str(string()); // clear ss

  // draw * for light
  ofDrawLine(lightScreenPos.x +  5, lightScreenPos.y +  5, lightScreenPos.x + -5, lightScreenPos.y + -5);
  ofDrawLine(lightScreenPos.x + -5, lightScreenPos.y +  5, lightScreenPos.x +  5, lightScreenPos.y + -5);
  ofDrawLine(lightScreenPos.x, lightScreenPos.y +  5, lightScreenPos.x, lightScreenPos.y + -5);
  ofDrawLine(lightScreenPos.x + -5, lightScreenPos.y, lightScreenPos.x +  5, lightScreenPos.y);


  ss << "light" << endl;
  ofDrawBitmapString(ss.str().c_str(), lightScreenPos.x + 10, lightScreenPos.y + 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::drawLine(ofVec3f s, ofVec3f e) {
  ofGetCurrentRenderer() -> drawLine(s.x, s.y, s.z, e.x, e.y, e.z);
}
