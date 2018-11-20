//
//  barretta.cpp
//  006
//
//  Created by nicola bertelloni on 02/11/2018.
//

#include "barretta.hpp"


void BarrettaClass::update(float sound){
  soundLocal = sound;
}

//--------------------------------------------------------------

void BarrettaClass::draw(){

//  ofSetColor(255, 100, 150);
  ofSetLineWidth(2);
  
//  int soundImpact = sound.scaledVol * 1000;
  int maxRadius = min(cell.width / 2, cell.height / 2);
  int radius = ofMap(soundLocal, 0, 1, 0, maxRadius);
  for (unsigned int i = 0; i < 48; i += 4) {
    ofNoFill();
    ofDrawCircle(0, 0, radius - i);
    ofFill();
  }
  
}

//--------------------------------------------------------------
