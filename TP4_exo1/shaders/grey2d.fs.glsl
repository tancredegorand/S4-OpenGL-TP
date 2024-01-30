#version 330 core

in vec3 vFragColor;

out vec4 fFragColor;

void main()
{
    float grey = (vFragColor.r +  vFragColor.g + vFragColor.b) / 3;
    fFragColor = vec4(vec3(grey), 1.);
}