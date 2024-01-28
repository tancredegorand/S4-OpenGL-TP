#version 330 core

in vec3 vFragColor;
float Color_grey = (vFragColor.r + vFragColor.g + vFragColor.b) / 3.0;

out vec4 fFragColor;

void main() {
    fFragColor = vec4(Color_grey, Color_grey, Color_grey, 1.);

}