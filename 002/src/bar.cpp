//
//  bar.cpp
//  001
//
//  Created by nicola bertelloni on 26/10/2018.
//

#include "bar.h"

void BarClass::setup(){
  
}

void BarClass::update(){
  
}

void BarClass::draw(int x, int timing, int length){
  float time = ofGetFrameNum() * 0.002;
  float rotation = time * (x * 0.025);
  int y = timing;
  length = length * sin(time + x);
  x = x + (length / 2);
  int tickness = width * sin(time * 0.01);
  
  ofPushMatrix();
    ofTranslate(x,y);
    ofRotateDeg(rotation);
    ofSetColor(125, 100, 200);
    ofDrawRectangle(0, 0, length + 32, tickness + 32);
  
    ofTranslate(+16,+16);
    ofSetColor(255, 200, 100);
    ofDrawRectangle(0, 0, length + 8, tickness + 8);
  ofPopMatrix();
  

}
