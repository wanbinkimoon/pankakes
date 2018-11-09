//
//  bar.h
//  001
//
//  Created by nicola bertelloni on 26/10/2018.
//

#include "ofMain.h"

class BarClass : public ofBaseApp{

public:
  void setup();
  void update();
  void draw(int x, int timing, int length);
  
  int width = 8;
};
