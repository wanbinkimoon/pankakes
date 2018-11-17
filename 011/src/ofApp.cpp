#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  ofColor color1 = ofColor(38, 70, 83);
  stepColors.push_back(color1);
  ofColor color2 = ofColor(42, 157, 143);
  stepColors.push_back(color2);
  ofColor color3 = ofColor(233, 196, 106);
  stepColors.push_back(color3);
  ofColor color4 = ofColor(244, 162, 97);
  stepColors.push_back(color4);
  ofColor color5 = ofColor(231, 11, 81);
  stepColors.push_back(color5);
}

//--------------------------------------------------------------
void ofApp::update(){
  wave.update(20);
}

//--------------------------------------------------------------
void ofApp::draw(){
//  shader.begin();
//  shader.end();
  ofSetColor(255, 125, 100);
  
  wave.draw(20, stepColors);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
