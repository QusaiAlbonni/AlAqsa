#version 450 core
layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 aTexCoords;

uniform mat4 lightSpaceMatrix;
uniform mat4 model;

out vec2 TexCoords;


void main()
{
    TexCoords = aTexCoords;
    gl_Position = lightSpaceMatrix * model * vec4(aPos, 1.0);
}