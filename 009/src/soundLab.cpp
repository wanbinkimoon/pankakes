//
//  soundLab.cpp
//  003
//
//  Created by nicola bertelloni on 28/10/2018.
//

#include "soundLab.hpp"

// --------------------------------------------------------------

void SoundLab::audioIn(ofSoundBuffer &input){
  float curVol = 0.0;
  
  // samples are "interleaved"
  int numCounted = 0;
  
  //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
  for (size_t i = 0; i < input.getNumFrames(); i++){
    mono[i]    = input[i * 2] * 0.5;
    curVol += mono[i] * mono[i];
    numCounted += 2;
  }
  
  //this is how we get the mean of rms :)
  curVol /= (float)numCounted;
  
  // this is how we get the root of rms :)
  curVol = sqrt(curVol);
  
  smoothedVol *= 0.93;
  smoothedVol += 0.07 * curVol;
}

// --------------------------------------------------------------

void SoundLab::setup(){
  int bufferSize = 256;
  ofSoundStreamSettings settings;
  // soundStream.printDeviceList();
  auto devices = soundStream.getMatchingDevices("default");
  
  if(!devices.empty()){
    settings.setInDevice(devices[0]);
  }
  
  mono.assign(bufferSize, 0.0);
  volHistory.assign(400, 0.0);
  
  settings.setInListener(this);
  settings.sampleRate = 44100;
  settings.numOutputChannels = 0;
  settings.numInputChannels = 2;
  settings.bufferSize = bufferSize;
  soundStream.setup(settings);
}

// --------------------------------------------------------------

void SoundLab::update(){
  
  // Map the volume
  scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0);
  
  // Records the volume in an array
  volHistory.push_back(scaledVol);
  
  //  If we are bigger the the size we want to record - lets drop the oldest value
  if(volHistory.size() >= 400){
    volHistory.erase(volHistory.begin(), volHistory.begin()+1);
  }
}

// --------------------------------------------------------------

void SoundLab::drawLine(){
   ofDrawBitmapString(ofToString(scaledVol), 1000, 60);
}
