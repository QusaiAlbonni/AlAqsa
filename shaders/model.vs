#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 texCoords;
out vec3 fragPos;
out vec3 normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    normal = mat3(transpose(inverse(model))) * aNormal;

    fragPos = vec3(model * vec4(aPos, 1.0)); 
    texCoords = aTexCoords;
    
    gl_Position = projection * view * vec4(FragPos, 1.0);
}