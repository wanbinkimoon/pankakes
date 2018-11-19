//
//  barretta.hpp
//  006
//
//  Created by nicola bertelloni on 02/11/2018.
//


#include "ofMain.h"
#include "cell.h"

class BarrettaClass : public ofBaseApp{
  
public:
  void update(float sound);
  void draw();
  Cell cell;
  float soundLocal;
};

