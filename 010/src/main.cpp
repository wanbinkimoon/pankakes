#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
  ofSetupOpenGL(800,800,OF_WINDOW);      // <-------- setup the GL context

//  ofGLWindowSettings settings;
//  settings.setGLVersion(3,2);
//  settings.setSize(800, 800);
//  ofCreateWindow(settings);

  // this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
