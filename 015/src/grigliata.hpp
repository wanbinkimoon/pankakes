//
//  grigliata.hpp
//  006
//
//  Created by nicola bertelloni on 02/11/2018.
//

#include "ofMain.h"
#include "cell.h"

class Grid : public ofBaseApp{
public:
  Cell cell;
  Cell cellSetup(int rows, int cols);
  void draw(Cell cell, std::function<void()> element, float sound);
};
