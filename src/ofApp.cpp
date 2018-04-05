#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  ofSetVerticalSync(true);
  ofEnableDepthTest();

  // logo
  ofMesh mesh;
  mesh.load("mlcs.ply");
  
  // add vertex colors
  for (int i = 0; i < mesh.getNumIndices(); i++) {
    mesh.addColor(ofColor(240, 240, 240, 255));
  }

  logo = of3dPrimitive(mesh);

  // geomFbo
  
  ofFbo::Settings s;
  s.width = ofGetWidth();
  s.height = ofGetHeight();
  s.minFilter = GL_NEAREST;
  s.maxFilter = GL_NEAREST;
  s.colorFormats.push_back(GL_RGB); // BUFFER_TYPE_COLOR
  s.colorFormats.push_back(GL_RGB); // BUFFER_TYPE_NORMAL
  s.colorFormats.push_back(GL_RGB); // BUFFER_TYPE_DEPTH

  s.depthStencilAsTexture = true; // TODO: what is this?
  s.useDepth = true;
  // s.useStencil = true; // TODO: what is this?
  geomFbo.allocate(s);

  // light
  light.setGlobalPosition(ofVec3f(3, 4, 5));

  // cam
  cam.setTarget(ofVec3f());
  cam.setDistance(30);
  // cam.setNearClip(0.1);
  // cam.setFarClip(10);

  shader.load("shader/geom");
  shader.begin();
    shader.setUniform1f("nearClip", cam.getNearClip());
    shader.setUniform1f("farClip", cam.getFarClip());
  shader.end();

  ofLogNotice() << cam.getNearClip() << endl;
  ofLogNotice() << cam.getFarClip() << endl;

}

//--------------------------------------------------------------
void ofApp::update(){
  logo.rotateDeg(0.5, ofVec3f(0, 1, 0));

  ofEnableDepthTest();
  
  geomFbo.begin();
    vector<int> bufferId;
    bufferId.push_back(BUFFER_TYPE_COLOR);
    bufferId.push_back(BUFFER_TYPE_NORMAL);
    bufferId.push_back(BUFFER_TYPE_DEPTH);
    geomFbo.setActiveDrawBuffers(bufferId);
    ofClear(0);
    shader.begin();
      cam.begin();
        logo.draw();
      cam.end();
    shader.end();
  geomFbo.end();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

  geomFbo.getTexture(2).draw(0, 0);
  // geomFbo.getDepthTexture().draw(0, 0);

  ofDisableDepthTest();

  ofSetColor(255);
  stringstream ss;
  ss << "framerate: " << ofGetFrameRate() << endl;

  ofDrawBitmapString(ss.str().c_str(), 10, 20);
  ss.str(string()); // clear ss

}

//--------------------------------------------------------------
void ofApp::drawLine(ofVec3f s, ofVec3f e) {
  ofGetCurrentRenderer() -> drawLine(s.x, s.y, s.z, e.x, e.y, e.z);
}
