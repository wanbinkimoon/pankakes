//
//  colorLerp.cpp
//  010
//
//  Created by nicola bertelloni on 14/11/2018.
//

#include "colorLerp.hpp"

void ColorLerp::clear(){
//  colors.clear();
}

//----------------------------

ofColor ColorLerp::steps(vector <ofColor> stepColors, int steps, int actual){
  int stepsPerColor =  steps /  stepColors.size();
  float jump = 1.0 / stepsPerColor;
  for (unsigned int i = 0; i < stepColors.size(); i++) {
    for (unsigned int j = 0; j < stepsPerColor; j++) {
      ofColor newColor = stepColors[i].lerp(stepColors[i+1], jump * j);
      colors.push_back(newColor);
    }
  }
  return colors[actual];
}
