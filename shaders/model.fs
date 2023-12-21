#version 330 core
#extension GL_ARB_shader_derivative : enable

out vec4 FragColor;


uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform sampler2D texture_normal1;  
uniform sampler2D texture_height1;
uniform sampler2D texture_ambient1;  
uniform float shininess;

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
uniform Light light;
uniform mat4 model;
uniform bool noparallax;

void main()
{



    //vec3 normalMapValue = texture(material.normal1, TexCoords).rgb ;
    //vec3 norm = normalize(Normal + normalMapValue);

    //vec3 dx = dFdx(FragPos);
    //vec3 dy = dFdy(FragPos);
    //vec3 norm = normalize(cross(dx, dy) + normalMapValue);


    vec3 norm = normalize(texture(texture_normal1, TexCoords).xyz * 2.0f - 1.0f);


    vec3 lightDirection = geoDir;
    //lightDirection = vec3(-light.direction.x, light.direction.y, -light.direction.z);
    vec3 camPos = geoViewPos;



    vec3 viewDirection = normalize(camPos - FragPos);
	
	// Variables that control parallax occlusion mapping quality
	float heightScale = 0.05f;
	const float minLayers = 8.0f;
    const float maxLayers = 64.0f;
    float numLayers = mix(maxLayers, minLayers, abs(dot(vec3(0.0f, 0.0f, 1.0f), viewDirection)));
	float layerDepth = 1.0f / numLayers;
	float currentLayerDepth = 0.0f;
	
	// Remove the z division if you want less aberated results
	vec2 S = viewDirection.xy / viewDirection.z * heightScale; 
    vec2 deltaUVs = S / numLayers;
	
	vec2 UVs = TexCoords;
	float currentDepthMapValue = 1.0f - texture(texture_height1, UVs).r;
	if(!noparallax){
	// Loop till the point on the heightmap is "hit"
	while(currentLayerDepth < currentDepthMapValue)
    {
        UVs -= deltaUVs;
        currentDepthMapValue = 1.0f - texture(texture_height1, UVs).r;
        currentLayerDepth += layerDepth;
    }
	// Apply Occlusion (interpolation with prev value)
	vec2 prevTexCoords = UVs + deltaUVs;
	float afterDepth  = currentDepthMapValue - currentLayerDepth;
	float beforeDepth = 1.0f - texture(texture_height1, prevTexCoords).r - currentLayerDepth + layerDepth;
	float weight = afterDepth / (afterDepth - beforeDepth);
	UVs = prevTexCoords * weight + UVs * (1.0f - weight);

	// Get rid of anything outside the normal range
	//if(UVs.x > 1.0 || UVs.y > 1.0 || UVs.x < 0.0 || UVs.y < 0.0)
	//	discard;
    }





    // ambient
    float aoValue = texture(texture_ambient1, TexCoords).r;
    vec3 ambient = aoValue * light.ambient * texture(texture_diffuse1, TexCoords).rgb;
  	
    // diffuse 
    // vec3 lightDir = normalize(light.position - FragPos);
    vec3 lightDir = normalize(lightDirection);  
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(texture_diffuse1, UVs).rgb;  
    
    // specular
    vec3 viewDir = normalize(camPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 t = texture(texture_specular1, UVs).rgb;
    vec3 specular = light.specular * spec * vec3(t.x,t.x,t.x);  
        
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
} 