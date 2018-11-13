//
//  wave.hpp
//  009
//
//  Created by nicola bertelloni on 13/11/2018.
//

#ifndef wave_hpp
#define wave_hpp

#include "ofMain.h"

class WaveVertex {
public:
  ofVec2f topLeft;
  ofVec2f bottomLeft;
  ofVec2f topRight;
  ofVec2f bottomRight;
};

class Wave : public ofBaseApp{
public:
  void setup();
  void update(int rows);
  void draw(int points);
  int rowH;
  int rowNumb;
  vector <WaveVertex> verts;
};

#endif /* wave_hpp */
