#version 330 core

in vec3 vFragColor;

out vec4 fFragColor;

in vec2 vFragPosition;

//atténuation

float alpha = 1;
float beta = 50;
float dist = distance(vec2(0.0, 0.0), vFragPosition);
float a = alpha*exp(-beta*dist*dist);

void main() {
  fFragColor = vec4(vFragColor*a, 1.);
}