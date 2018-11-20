#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  points = 36;
  radius = 80;
}

//--------------------------------------------------------------
void ofApp::update(){
  
  float angle = TWO_PI / points;
  float time = ofGetElapsedTimef() * .025;

  blob.clear();
  for (unsigned int i = 0; i < points; i++){
    float x = radius * sin(angle * i) * (ofNoise(time * (i + 1 * ofNoise(time * ofNoise(time)))) * 4);
    float y = radius * cos(angle * i) * (ofNoise(time * (i + 1 * ofNoise(time * ofNoise(time)))) * 4);
    blob.addVertex(x, y);
  }
  
  
  //  float x = radius * sin(0) * (ofNoise(time) * 4);
  //  float y = radius * cos(0) * (ofNoise(time) * 4);
  //  blob.curveTo(x, y);
  
  blob.getSmoothed(20, 1);
//  blob.close();
  
  path.clear();
  for( int i = 0; i < blob.getVertices().size(); i++) {
    if(i == 0) path.newSubPath();
    path.curveTo(blob.getVertices()[i] );
  }
  path.close();
  path.simplify();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofPushMatrix();
  ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
  
//  ofNoFill();
  
  ofSetColor(124, 200, 150);
  path.draw();
  ofPopMatrix();
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
