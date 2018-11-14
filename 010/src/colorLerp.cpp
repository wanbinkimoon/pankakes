//
//  colorLerp.cpp
//  010
//
//  Created by nicola bertelloni on 14/11/2018.
//

#include "colorLerp.hpp"

ofColor ColorLerp::steps(vector <ofColor> stepColors, int steps, int actual){
  int stepsPerColor =  stepColors.size() / steps;
  float jump = 1.0 / stepsPerColor;
  
  for (unsigned int i; i < stepColors.size(); i++) {
    for (unsigned int j = 0; j < stepsPerColor; j++) {
      ofColor newColor = stepColors[i].lerp(stepColors[2], jump * j);
      colors.push_back(newColor);
    }
  }

  return colors[actual];
}
