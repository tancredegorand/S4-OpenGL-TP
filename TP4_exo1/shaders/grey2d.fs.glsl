#version 330 core

in vec3 vFragColor;

out vec4 fFragColor;

void main() {
  float gray = (vFragColor.r + vFragColor.g + vFragColor.b)/3.0; 
  fFragColor = vec4(vec3(gray), 1.);
}