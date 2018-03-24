#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  ofSetVerticalSync(true);

  // mesh
  mesh.load("mlcs.ply");

  // cam
  cam.setTarget(ofVec3f());
  cam.setDistance(15);

  // light
  light.setPosition(ofVec3f(3, 4, 5));

  // set variable for shaders
  shader.load("shader/default");
  shader.bindDefaults();
  shader.begin();
  shader.setUniform3f("lightPos", light.getPosition());
  shader.setUniform1f("lightIntensity", 5);
  shader.end();

  }

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

  ofEnableDepthTest();

  cam.begin();
  ofSetColor(255);
  ofFill();
  shader.begin();
  // ofDrawSphere(0, 0, 0, 2);
  mesh.draw();
  shader.end();

  ofSetColor(255, 255, 0);

  ofDrawAxis(5.0f);
  ofPoint lightScreenPos = cam.worldToScreen(light.getPosition());
  cam.end();

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
