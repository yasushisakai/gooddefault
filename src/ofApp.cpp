#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

  ofBackground(0);
  ofSetVerticalSync(true);
  ofEnableDepthTest();

  shader.load("shader/default");
  shader.bindDefaults();

  // mesh
  glm::vec3 a{};
  glm::vec3 b{1.0, 0.0, 0.0};
  glm::vec3 c{0.0, 0.0, 1.0};
  glm::vec3 d{0.0, 1.0, 0.0};

  glm::vec3 normal = glm::triangleNormal(a, c, b);
  glm::vec3 normal2 = glm::triangleNormal(a, d, c);
  ofLogNotice() << "normal glm: " << normal << endl;

  // ofVec3f normal = ((b - a).cross(c - a)).normalize();

  mesh.addVertex(a);
  mesh.addNormal(normal);
  mesh.addVertex(b);
  mesh.addNormal(normal);
  mesh.addVertex(c);
  mesh.addNormal(normal);
  mesh.addVertex(a);
  mesh.addNormal(normal2);
  mesh.addVertex(d);
  mesh.addNormal(normal2);
  mesh.addVertex(c);
  mesh.addNormal(normal2);

  mesh.addIndex(0);
  mesh.addIndex(1);
  mesh.addIndex(2);
  mesh.addIndex(3);
  mesh.addIndex(4);
  mesh.addIndex(5);

  // light (just a node)
  light.setPosition(ofVec3f(3, 4, 5));
  shader.begin();
  shader.setUniform3f("lightPos", light.getPosition());
  shader.end();

  glm::vec3 center{(glm::vec3)mesh.getCentroid()};
  ofLogNotice() << "center: " << center << endl;

  ofLogNotice() << light.getPosition() << endl;

  // ofLogNotice() << mesh.getNormal(0) << endl;

  glm::vec3 lightDir{glm::normalize((glm::vec3)light.getPosition() - center)};

  cosTheta = dot(lightDir, normal);
  ofLogNotice() << "cosTheta: " << cosTheta << " angle: " << glm::acos(cosTheta) / PI * 180.0 << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

  cam.begin();
  // ofSetColor((int)(cosTheta * 255));
  ofSetColor(255);
  ofFill();
  shader.begin();
  // mesh.draw();
  ofDrawSphere(0, 0, 0, 2);
  shader.end();

  ofSetColor(255, 255, 0);

  ofVec3f c{mesh.getCentroid()};
  ofVec3f n{0, 1, 0};

  ofDrawAxis(5.0f);
  ofPoint lightScreenPos = cam.worldToScreen(light.getPosition());
  cam.end();

  ofSetColor(255);
  stringstream ss;
  ss << "framerate: " << ofGetFrameRate() << endl;
  ss << "cosTheta: " << cosTheta << endl;

  ofDrawBitmapString(ss.str().c_str(), 10, 20);
  ss.str(string());

  ofDrawCircle(lightScreenPos.x, lightScreenPos.y, 3);

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
