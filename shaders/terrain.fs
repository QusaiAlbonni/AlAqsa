#version 330 core
#extension GL_ARB_shader_derivative : enable

out vec4 FragColor;

struct Material {
    sampler2D diffuse1;
    sampler2D specular1;
    sampler2D normal1;  
    sampler2D height1;
    sampler2D ambient1;  
    float shininess;
}; 

struct Light {
    //vec3 position;
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;
in vec3 geoDir;
in vec3 geoViewPos;  
in vec3 Normal;  
in vec2 TexCoords;
in mat3 tbn;
  
uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{



    //vec3 normalMapValue = texture(material.normal1, TexCoords).rgb ;
    //vec3 norm = normalize(Normal + normalMapValue);

    //vec3 dx = dFdx(FragPos);
    //vec3 dy = dFdy(FragPos);
    //vec3 norm = normalize(cross(dx, dy) + normalMapValue);


    vec3 norm = normalize(texture(material.normal1, TexCoords).xyz * 2.0f - 1.0f);


    vec3 lightDirection = geoDir;
    //lightDirection = vec3(-light.direction.x, light.direction.y, -light.direction.z);
    vec3 camPos = geoViewPos;

    // ambient
    float aoValue = texture(material.ambient1, TexCoords).r;
    vec3 ambient = aoValue * light.ambient * texture(material.diffuse1, TexCoords).rgb;
  	
    // diffuse 
    // vec3 lightDir = normalize(light.position - FragPos);
    vec3 lightDir = normalize(-lightDirection);  
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse1, TexCoords).rgb;  
    
    // specular
    vec3 viewDir = normalize(camPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 t = texture(material.specular1, TexCoords).rgb;
    vec3 specular = light.specular * spec * vec3(t.x,t.x,t.x);  
        
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
} 