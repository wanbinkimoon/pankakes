//
//  grigliata.cpp
//  006
///Users/nicolabertelloni/Developer/of_v0.10.0/apps/everyday/008/src/barretta.hpp
//  Created by nicola bertelloni on 02/11/2018.
//

#include "grigliata.hpp"

//--------------------------------------------------------------
Cell Grid::cellSetup(int rows, int cols){

  cell.rows = rows;
  cell.cols = cols;
  cell.width = ofGetHeight() / rows;
  cell.height = ofGetWidth() / cols;
  cell.centerX = cell.width / 2;
  cell.centerY = cell.height / 2;
 
  return cell;
}

//--------------------------------------------------------------
void Grid::draw(Cell cell, std::function<void()> element, float sound){
  float waver = ofGetFrameNum() * 0.05;
  for (unsigned int i = 0; i < cell.rows; i++) {
    for (unsigned int j = 0; j < cell.cols; j++) {
      // int index = i + j * cell.width;
      // float x = i * cell.width + cell.centerX + (sin(j * sound) * 10);
      // float y = j * cell.height + cell.centerY + (sin(i + waver) * 10);
      
      float x = i * cell.width + cell.centerX;
      float y = j * cell.height + cell.centerY;

      ofPushMatrix();
        ofTranslate(x, y);
        element();
      ofPopMatrix();
    }
  }
}
