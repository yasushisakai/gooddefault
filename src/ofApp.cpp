#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  ofSetVerticalSync(true);
  ofEnableDepthTest();

  ofFbo::Settings settings;
  settings.width = ofGetWidth();
  settings.height = ofGetHeight();
  settings.internalformat = GL_RGB;
  settings.useDepth = true;
  settings.depthStencilAsTexture = true;
  fbo.allocate(settings);
  
  // mesh
  mesh.load("mlcs.ply");

  // cam
  cam.setTarget(ofVec3f());
  cam.setDistance(15);

  // set variable for shaders
  shader.load("shader/depth");
  shader.begin();
  shader.setUniform1f("height", (float)ofGetHeight());
  shader.end();

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

  ofSetColor(255);

  fbo.begin();
    cam.begin();
      ofClear(0);
      mesh.draw();
    cam.end();
  fbo.end();

  shader.begin();
    shader.setUniformTexture("dTex", fbo.getDepthTexture(),1);
    fbo.draw(0, 0);
  shader.end();

  stringstream ss;

  ss << "framerate: " << ofGetFrameRate() << endl;

  ofDrawBitmapString(ss.str().c_str(), 10, 20);

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
