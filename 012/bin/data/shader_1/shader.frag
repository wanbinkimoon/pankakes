#version 150

out vec4 outputColor;

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

vec3 colorA = vec3(0.149,0.141,0.912);
vec3 colorB = vec3(1.000,0.833,0.224);

void main() {
  vec3 color = vec3(0.0);
  
  float pct = abs(sin(u_time));
  
  // Mix uses pct (a value from 0-1) to
  // mix the two colors
  float r = gl_FragCoord.x / 800;
  float g = gl_FragCoord.y / 800;
  float b = 1.0 / sin(u_time * 10);
  float a = 1.0;
  outputColor = vec4(r, g, b, a);
  
//  outputColor = vec4(color, 1.0);
//  outputColor = vec4(.24, .54, .7, 1);
}

