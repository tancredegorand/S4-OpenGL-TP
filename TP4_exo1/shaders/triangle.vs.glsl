#version 330 core

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vFragColor;
out vec2 vFragPosition;

mat3 translate(int tx, int ty){
    return mat3(
    vec3(1, 0, 0),
    vec3(0, 1, 0),
    vec3(tx, ty, 1)
);
}

mat3 scale(int tx, int ty){
    return  mat3(
    vec3(tx, 0, 0),
    vec3(0, ty, 0),
    vec3(0, 0, 1)
);
}

mat3 rotate(int alpha){
    return mat3(
    vec3(cos(alpha), -sin(alpha), 0),
    vec3(sin(alpha), cos(alpha), 0),
    vec3(0, 0, 1)
);
}

void main() {
    mat3 M = rotate(45);
    gl_Position = vec4((M * vec3(aVertexPosition, 1.)).xy, 0., 1.);
  vFragColor = aVertexColor;
  vFragPosition = aVertexPosition;
  //gl_Position = vec4(aVertexPosition*vec2(0.5,0.5), 0., 1.);
}
