#version 330
// Fragment Shader
uniform vec3 lightPosition;
uniform vec3 lightIntensity;
uniform mat4 model;

in vec3 fragColor;
in vec3 fragNormal;
in vec3 fragVert;

out vec4 FragColor;

float det(mat2 inputMat)
{
    return inputMat[0][0] * inputMat[1][1] - inputMat[0][1] * inputMat[1][0];
}

float det(mat3 i)
{
    return i[0][0] * det(mat2(i[1][1], i[1][2], i[2][1], i[2][2]))
            -i[0][1] * det(mat2(i[1][0], i[1][2], i[2][0], i[2][2]))
            +i[0][2] * det(mat2(i[1][0], i[1][2], i[2][0], i[2][2]));
}

mat3 inverse(mat3 i)
{
    mat3 outputMat;
    outputMat[0][0] = det(mat2(i[1][1], i[1][2], i[2][1], i[2][2])) / det(i);
    outputMat[0][1] = det(mat2(i[0][2], i[0][1], i[2][2], i[2][1])) / det(i);
    outputMat[0][2] = det(mat2(i[0][1], i[0][2], i[1][1], i[1][2])) / det(i);

    outputMat[1][0] = det(mat2(i[1][2], i[1][0], i[2][2], i[2][0])) / det(i);
    outputMat[1][1] = det(mat2(i[0][0], i[0][2], i[2][0], i[2][2])) / det(i);
    outputMat[1][2] = det(mat2(i[0][2], i[0][0], i[1][2], i[1][0])) / det(i);

    outputMat[2][0] = det(mat2(i[1][0], i[1][1], i[2][0], i[2][1])) / det(i);
    outputMat[2][1] = det(mat2(i[0][1], i[0][0], i[2][1], i[2][0])) / det(i);
    outputMat[2][2] = det(mat2(i[0][0], i[0][1], i[1][0], i[1][1])) / det(i);

    return outputMat;
}

void main()
{
    //calculate normal in world coordinates
    mat3 normalMatrix = transpose(inverse(mat3(model)));
    vec3 normal = normalize(normalMatrix * fragNormal);

    //calculate the location of this fragment (pixel) in world coordinates
    vec3 fragPosition = fragVert;

    //calculate the vector from this pixels surface to the light source
    vec3 surfaceToLight = normalize(lightPosition - fragPosition);

    //calculate the cosine of the angle of incidence (brightness)
    float brightness = abs(dot(normal, surfaceToLight));
    brightness = clamp(brightness, 0, 1);

    //calculate final color of the pixel, based on:
    // 1. The angle of incidence: brightness
    // 2. The color/intensities of the light: light.intensities
    // 3. The texture and texture coord: texture(tex, fragTexCoord)
    FragColor = brightness * vec4(lightIntensity, 1.0) * vec4(fragColor, 1.0);
}
