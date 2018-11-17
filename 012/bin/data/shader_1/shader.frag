#version 150

out vec4 outputColor;
//uniform vec4 color;
//uniform float expand;
//uniform vec2 center;
//uniform float radius;
//uniform float windowHeight;

    // gl_FragCoord contains the window relative coordinate for the fragment.
    // we use gl_FragCoord.x position to control the red color value.
    // we use gl_FragCoord.y position to control the green color value.
    // please note that all r, g, b, a values are between 0 and 1.
    
void main(){
  vec2 p = (gl_FragCoord.xy - vec2(400, 400)) / 100;
  float rad = sqrt(dot(p, p));
  float r;
  float g;
  float b;
  float a;
  
  if (rad < 1.0){
    r = gl_FragCoord.x / 800;
    g = gl_FragCoord.y / 800;
    b = 1.0;
    a = 1.0;
  } else {
    r = 1.0;
    g = gl_FragCoord.x / 800;
    b = 1.0;
    a = gl_FragCoord.y / 800;
  }

  
//  float windowWidth = 1024.0;
//  float windowHeight = 768.0;
//
//  float r = gl_FragCoord.x / windowWidth;
//  float g = gl_FragCoord.y / windowHeight;
//  float b = 1.0;
//  float a = 1.0;

  outputColor = vec4(r, g, b, a);;
}
