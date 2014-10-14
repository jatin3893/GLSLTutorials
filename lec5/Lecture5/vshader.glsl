#version 330
// Vertex Shader

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec3 vertexColor;

uniform mat4 projection;
uniform mat4 camera;
uniform mat4 model;

out vec3 fragColor;
out vec3 fragNormal;
out vec3 fragVert;

void main()
{
    // Calculate vertex position in screen space
    gl_Position = projection * camera * model * vec4(vertexPosition, 1);

    fragColor = vertexColor;
    fragNormal = vertexNormal;
    fragVert = vec3(model * vec4(vertexPosition, 1));
}
