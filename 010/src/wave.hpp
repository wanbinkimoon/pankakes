//
//  wave.hpp
//  009
//
//  Created by nicola bertelloni on 13/11/2018.
//

#ifndef wave_hpp
#define wave_hpp

#include "ofMain.h"
#include "colorLerp.hpp"

class WaveVertex {
public:
  ofVec2f topLeft;
  ofVec2f bottomLeft;
  ofVec2f topRight;
  ofVec2f bottomRight;
};

class Wave : public ofBaseApp{
public:
  void update(int rows);
  void draw(int points, vector <ofColor> stepColors);
  int rowH;
  int rowNumb;
  vector <WaveVertex> verts;
  ColorLerp color;
};

#endif /* wave_hpp */
