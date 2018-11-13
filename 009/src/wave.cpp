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
  rowH = (ofGetHeight() + 20) / rows;
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
  float waver = ofGetFrameNum() * 0.005;
  
  
  
  for (unsigned int i = 0; i < rowNumb; i++) {
    
    ofSetColor(200, 200, 100, 20 * i);

    ofBeginShape();
    ofVertex(verts[i].topLeft);
    for (unsigned int j = 0; j < points + 1; j++) {
      int x = (ofGetWidth() / points) * j;
      float y = verts[i].topLeft.y + (sin((j + waver) * TWO_PI * 2 / points) * 10);
//      ofVertex(x, y);
      ofCurveVertex(x, y);
    }
    ofVertex(verts[i].topRight);
    ofVertex(verts[i].bottomRight);
    for (unsigned int j = points; j + 1 > 0; j--) {
      int x = (ofGetWidth() / points) * j;
      float y = verts[i].bottomRight.y + (sin((j + waver) * TWO_PI * 2 / points) * 10);
//      ofVertex(x, y);
      ofCurveVertex(x, y);
    }
    ofVertex(verts[i].bottomLeft);
    ofEndShape(true);
    
  }
}
