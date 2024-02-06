#version 330

layout(location = 3) in vec2 aVertexPosition;
layout(location = 8) in vec3 aVertexColor;

out vec3 vColor;

uniform float uTime;

mat3 rotate(int alpha){
    return mat3(
        vec3(cos(alpha), -sin(alpha), 0),
        vec3(sin(alpha), cos(alpha), 0),
        vec3(0, 0, 1)
    );
}





void main()
{
    mat3 M = rotate(int(uTime));
    vColor      = aVertexColor;
    gl_Position = vec4((M * vec3(aVertexPosition, 1.)).xy, 0., 1.);
}