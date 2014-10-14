#version 330
// Vertex Shader

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec3 vertexColor;

uniform mat4 projection;
uniform mat4 camera;
uniform mat4 model;

out vec3 color;

void main()
{
    // Calculate vertex position in screen space
    gl_Position = projection * camera * model * vec4(vertexPosition, 1);

    color = vertexColor;
}
