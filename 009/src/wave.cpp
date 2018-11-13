//
//  wave.cpp
//  009
//
//  Created by nicola bertelloni on 13/11/2018.
//

#include "wave.hpp"

//--------------------------------------------------------------
void Wave::setup(){
}

//--------------------------------------------------------------
void Wave::update(int rows){
  rowNumb = rows;
  rowH = ofGetHeight() / rows;
  for (unsigned int i = 0; i < rows; i++) {
    WaveVertex vert;
    vert.topLeft = ofVec2f(0, rowH * i);
    vert.bottomLeft = ofVec2f(0, rowH * (i + 1));
    vert.topRight = ofVec2f(ofGetWidth() + 1, rowH * i);
    vert.bottomRight = ofVec2f(ofGetWidth() + 1, rowH * (i + 1));
    verts.push_back(vert);
  }
}

//--------------------------------------------------------------
void Wave::draw(int points){
  ofSetColor(200, 200, 100);
  ofNoFill();
  for (unsigned int i = 0; i < rowNumb; i++) {
    ofBeginShape();
    ofVertex(verts[i].topLeft);
    
    for (unsigned int j = 0; j < points; j++) {
      int x = (ofGetWidth() / points) * j;
      int y = verts[i].topLeft.y;
      ofVertex(x, y);
    }
    
    ofVertex(verts[i].topRight);
    ofVertex(verts[i].bottomRight);
    
    for (unsigned int j = 0; j < points; j++) {
      int x = ((ofGetWidth() / points) * j) - ofGetWidth();
      int y = verts[i].bottomRight.y;
      ofVertex(x, y);
    }
    
    ofVertex(verts[i].bottomLeft);
    ofEndShape();
  }
}
