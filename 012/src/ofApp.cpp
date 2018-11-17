#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(34, 34, 34);
  ofSetFrameRate(60);
  
  int sampleRate = 44100;
  int bufferSize = 512;
  int outChannels = 0;
  int inChannels = 2;

  // setup the sound stream
  soundStream.setup(this, outChannels, inChannels, sampleRate, bufferSize, 3);

  //setup ofxAudioAnalyzer with the SAME PARAMETERS
  audioAnalyzer.setup(sampleRate, bufferSize, inChannels);
  
  // loading shader from data folder
  bar.shader.load("shader_1/shader");
}

//--------------------------------------------------------------
void ofApp::update(){
  grid.cellSetup(consts.rows, consts.cols);
  bar.cell = grid.cell;
  
  smooth = ofClamp(ofGetMouseX() / (float)ofGetWidth(), 0.0, 1.0);
  //get the analysis values
  rms_l = audioAnalyzer.getValue(RMS, 0, smooth);
  rms_r = audioAnalyzer.getValue(RMS, 1, smooth);
  bar.update(rms_r);
}

//--------------------------------------------------------------
void ofApp::draw(){
//  shader.begin();
//  shader.end();
  ofSetColor(ofColor::cyan);
  
  float xpos = ofGetWidth() *.5;
  float ypos = ofGetHeight() - ofGetHeight() * rms_r;
  float radius = 5 + 100 * rms_l;

//  ofDrawCircle(xpos, ypos, radius);
  grid.draw(grid.cell, [&]{bar.draw();}, rms_l);

}
//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer &inBuffer){
  //ANALYZE SOUNDBUFFER:
  audioAnalyzer.analyze(inBuffer);
}

//--------------------------------------------------------------
void ofApp::exit(){
  ofSoundStreamStop();
  audioAnalyzer.exit();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
  
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
  
}
