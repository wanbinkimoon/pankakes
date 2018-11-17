//
//  soundLab.hpp
//  003
//
//  Created by nicola bertelloni on 28/10/2018.
//

#include "ofMain.h"

class SoundLab : public ofBaseApp{
  
public:
  void audioIn(ofSoundBuffer &input);
  void setup();
  void update();
  void drawLine();
  float smoothedVol;
  float scaledVol;
  vector <float> volHistory;
  vector <float> mono;
  ofSoundStream soundStream;
};

