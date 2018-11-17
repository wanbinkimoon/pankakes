//
//  colorLerp.hpp
//  010
//
//  Created by nicola bertelloni on 14/11/2018.
//

#ifndef colorLerp_hpp
#define colorLerp_hpp
#include "ofMain.h"

class ColorLerp : public ofBaseApp{
public:
  void clear();
  ofColor steps(vector <ofColor> stepColors, int steps, int actual);
  vector <ofColor> colors;
};

#endif /* colorLerp_hpp */
