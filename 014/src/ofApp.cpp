#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//  ofBackground(34, 34, 34);
  ofSetFrameRate(60);
  
  int sampleRate = 44100;
  int bufferSize = 512;
  int outChannels = 0;
  int inChannels = 2;

  // setup the sound stream
  soundStream.setup(this, outChannels, inChannels, sampleRate, bufferSize, 3);

  //setup ofxAudioAnalyzer with the SAME PARAMETERS
  audioAnalyzer.setup(sampleRate, bufferSize, inChannels);
  shader.load("shader_2/shader");

  // loading shader from data folder

//  bar.shader.setUniform4f("color", 200.0, 155.0, 100.0, 255.0);
//  bar.shader.setUniform2f("center", ofGetWidth() / 2, ofGetHeight() / 2);
//  bar.shader.setUniform1f("radius", ofGetHeight() / 2);
//  bar.shader.setUniform1f("expand", 0.25f);
//  bar.shader.setUniform1f("windowHeight", ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
  grid.cellSetup(consts.rows, consts.cols);
  bar.cell = grid.cell;
  
  smooth = ofClamp(ofGetMouseX() / (float)ofGetWidth(), 0.0, 1.0);
  //get the analysis values
  rms_l = audioAnalyzer.getValue(RMS, 0, smooth);
  rms_r = audioAnalyzer.getValue(RMS, 1, smooth);
  melBands = audioAnalyzer.getValues(MEL_BANDS, 0, smooth);
  
  bar.update(rms_r);
}

//--------------------------------------------------------------
void ofApp::draw(){
  shader.begin();
  shader.setUniform1f("u_time", ofGetElapsedTimef());
  shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
  shader.setUniform1f("u_sound", rms_l);
  float xpos = ofGetWidth() *.5;
  float ypos = ofGetHeight() - ofGetHeight() * rms_r;
  float radius = 5 + 100 * rms_l;
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  shader.end();

  shader.begin();
  for (int i = 0; i < melBands.size(); i += 2){
    
    shader.setUniform1f("u_time", ofGetElapsedTimef() * - 1);
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    shader.setUniform1f("u_sound", rms_l * - (0.2 * i));
    
    float scaledValue = ofMap(melBands[i], DB_MIN, DB_MAX, 0.0, 1.0, true);
    float radius = ((scaledValue * 100) - ((melBands.size() - i) * 20));
    
    ofSetCircleResolution(rms_r * 100);
    ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, radius);
  }
  shader.end();
  ofSetColor(255);
//  grid.draw(grid.cell, [&]{bar.draw();}, rms_l);
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
