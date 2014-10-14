#version 330
// Vertex Shader

layout(location = 1) in vec3 vert;

uniform mat4 mvp_matrix;

void main()
{
	// Calculate vertex position in screen space
        gl_Position = mvp_matrix * vec4(vert, 1);
}
