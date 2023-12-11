#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;



out DATA
{
    vec3 Normal;
	vec2 texCoord;
    mat4 projection;
	mat4 model;
    vec3 lightPos;
	vec3 camPos;
} data_out;

struct Light {
    //vec3 position;
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};


out vec3 fragPos;

uniform Light light;
uniform vec3 viewPos;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main()
{
    
    
    fragPos = vec3(model * vec4(aPos, 1.0)); 
    data_out.Normal = aNormal;
	data_out.texCoord = aTexCoords;
	data_out.projection = projection * view;
	data_out.model = model;
    data_out.lightPos = light.direction;
	data_out.camPos = viewPos;
    
    gl_Position = vec4(fragPos, 1.0);
}