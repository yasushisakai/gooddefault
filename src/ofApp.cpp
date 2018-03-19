#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  ofSetVerticalSync(true);

  ofEnableDepthTest();

  // mlcsLogo.loadModel("mlcs.obj");
  mesh.load("mlcs.ply");

  shader.load("shaders/default");

  light.setPosition(0, 100, 100);
  
  // ofRotateDeg(90, 1, 0, 0);
  //
  // mlcsLogo.setRotation(0, 180, 1, 0, 0);
  // mlcsLogo.setRotation(1, 180, 0, 1, 0);
  //
  // mesh.setRotation(0, 180, 1, 0, 0);
  
  // float logoHeight = mlcsLogo.getSceneCenter().y;
  // ofLogNotice() << mlcsLogo.getSceneCenter() << endl;
  // mlcsLogo.setPosition(0, - logoHeight, 0);


  // ofLogNotice() << ofGetHeight() << endl;
  // mlcsLogo.setPosition(0 , - ofGetHeight() * 0.5, 0);
  
}

//--------------------------------------------------------------
void ofApp::update(){
  // mesh.setRotation(1, 270 + ofGetElapsedTimef() * 60, 0, 1, 0);
  // mlcsLogo.setRotation(1, 270 + ofGetElapsedTimef() * 60, 0, 1, 0);
}

//--------------------------------------------------------------
void ofApp::draw(){

  cam.begin();

  ofDrawAxis(32);
  ofSetColor(255);
  shader.begin();
  // mlcsLogo.drawFaces();
  ofPushMatrix();
  ofRotateZDeg(90);
  ofRotateXDeg(90);
  mesh.draw();
  ofPopMatrix();
  // ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  shader.end();
  cam.end();

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
