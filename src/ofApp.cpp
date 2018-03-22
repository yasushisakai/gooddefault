#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  ofSetVerticalSync(true);
  light = ofNode();

  light.setPosition(100, 100, 100);

  mesh.load("mlcs.ply");
  shader.load("shaders/default");
  shader.setUniform3f("lightPos", light.getPosition());


  //------------------------------ 
  // camera
  cam.setFov(60);
  cam.setAspectRatio((float)ofGetWidth() / (float)ofGetHeight());
  cam.setNearClip(0.1);
  cam.setFarClip(500.0);
  cam.setPosition(0, 0, 500.0);
  cam.lookAt(ofVec3f());

  ofLogNotice() << "mvp: \n" << cam.getProjectionMatrix() << endl;

  glm::mat4 mvp = ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_PROJECTION);

  ofLogNotice() << "mvp: \n" << mvp << endl;
  // ofLogNotice() << "mv(cam): \n" << cam.getProjectionMatrix() << endl;

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

  // inefficient but lets do this in draw
  
  shader.setUniformMatrix4f("P", ofGetCurrentMatrix(OF_MATRIX_PROJECTION));
  shader.setUniformMatrix4f("MV", ofGetCurrentMatrix(OF_MATRIX_MODELVIEW));

  cam.begin();
  ofSetColor(255);
  shader.begin();
  mesh.draw();
  shader.end();
  ofDrawAxis(100);
  ofVec3f lightScreenPos = cam.worldToScreen(light.getPosition());
  cam.end();

  // fps
  stringstream fpss;

  fpss << "fps: " << ofGetFrameRate();
  ofDrawBitmapString(fpss.str().c_str(), 10, 20);

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
