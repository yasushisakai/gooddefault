#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  ofSetVerticalSync(true);
  light = ofNode();

  light.setPosition(200, 200, 200);

  mesh.load("mlcs.ply");
  // mesh.enableNormals();
  shader.load("shaders/default");
  shader.setUniform3f("lightPos", light.getPosition());
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  ofSetColor(255);
  shader.begin();
  
  ofPushMatrix();
  ofScale(50, 50, 50);
  ofRotateYDeg(180);
  ofRotateYRad(sin(ofGetElapsedTimef()) + PI * 0.25);
  ofTranslate(0.0, -3.5, 0.0);
  shader.setUniformMatrix4f("MV", cam.getModelViewMatrix());
  mesh.draw();
  ofPopMatrix();

  shader.end();

  ofDrawAxis(100);
  ofVec3f lightScreenPos = cam.worldToScreen(light.getPosition());
  cam.end();

  // indicating the light position
  ofNoFill();
  ofDrawLine(lightScreenPos.x - 5, lightScreenPos.y, lightScreenPos.x + 5, lightScreenPos.y);
  ofDrawLine(lightScreenPos.x, lightScreenPos.y -5 , lightScreenPos.x, lightScreenPos.y + 5);
  stringstream ss;

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
