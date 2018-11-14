#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
//  shader.load("shader_1/shader");
  
//  stepColors.push_back(ofColor(255, 150, 200));
//  stepColors.push_back(ofColor(0, 255, 242));
//  stepColors.push_back(ofColor(0, 255, 100));
//  stepColors.push_back(ofColor(255, 250, 0));
}

//--------------------------------------------------------------
void ofApp::update(){
  wave.update(4);
  stepColors.push_back(ofColor(255, 150, 200));
  stepColors.push_back(ofColor(0, 255, 242));
  stepColors.push_back(ofColor(0, 255, 100));
  stepColors.push_back(ofColor(255, 250, 0));
}

//--------------------------------------------------------------
void ofApp::draw(){
//  shader.begin();
//  shader.end();
  ofSetColor(255, 125, 100);
  
  wave.draw(10, stepColors);
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
