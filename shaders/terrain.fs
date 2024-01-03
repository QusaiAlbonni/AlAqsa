#version 330 core
//#extension GL_ARB_shader_derivative : enable

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

struct pointLight {
    vec3 position;  
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
	
    float constant;
    float linear;
    float quadratic;
};

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;
  
    float constant;
    float linear;
    float quadratic;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;       
};



in vec3 FragPos;
in vec3 geoDir;
in vec3 geoViewPos;  
in vec3 geoPointPos;
in vec3 geoSpotPos;
in vec3 geoSpotDir;
in vec3 Normal;  
in vec2 TexCoords;
in mat3 tbn;
in vec4 FragPosLightSpace;
vec4 FragPosLightSpace2;
in vec3 normalFragPos;


uniform bool spotOn;
uniform vec3 viewPos;
uniform Material material;
uniform Light light;
uniform SpotLight spotLight;
uniform pointLight point;
uniform mat4 model;
uniform bool isModel;
uniform bool noparallax;
uniform bool noNor;
uniform bool noSpec;
uniform bool noAo;
uniform bool hasPointLight;
uniform sampler2D shadowMap1;
uniform sampler2D shadowMap2;


float ShadowCalculation(vec4 fragPosLightSpace, vec3 norm)
{
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    // transform to [0,1] range
    projCoords = projCoords * 0.5 + 0.5;
    // get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
    float closestDepth = texture(shadowMap1, projCoords.xy).r; 
    // get depth of current fragment from light's perspective
    float currentDepth = projCoords.z;
    // calculate bias (based on depth map resolution and slope)
    vec3 normal = normalize(norm);
    vec3 lightDir = normalize(geoDir - FragPos);
    float bias = max(0.005 * (1.0 - dot(normal, lightDir)), 0.005);
    // check whether current frag pos is in shadow
    // float shadow = currentDepth - bias > closestDepth  ? 1.0 : 0.0;
    // PCF
    float shadow = 0.0;
    int sampleRadius = 2;
    vec2 texelSize = 1.0 / textureSize(shadowMap1, 0);
    for(int x = -sampleRadius; x <= sampleRadius; ++x)
    {
        for(int y = -sampleRadius; y <= sampleRadius; ++y)
        {
            float pcfDepth = texture(shadowMap1, projCoords.xy + vec2(x, y) * texelSize).r; 
            shadow += currentDepth - bias > pcfDepth  ? 1.0 : 0.0;        
        }    
    }
    shadow /= pow((sampleRadius * 2 + 1), 2);
    
    // keep the shadow at 0.0 when outside the far_plane region of the light's frustum.
    if(projCoords.z > 1.0)
        shadow = 0.0;
        
    return shadow;
}

float ShadowCalculation2(vec4 fragPosLightSpace, vec3 norm)
{
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    // transform to [0,1] range
    projCoords = projCoords * 0.5 + 0.5;
    // get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
    float closestDepth = texture(shadowMap2, projCoords.xy).r; 
    // get depth of current fragment from light's perspective
    float currentDepth = projCoords.z;
    // calculate bias (based on depth map resolution and slope)
    vec3 normal = normalize(norm);
    vec3 lightDir = normalize(geoDir - FragPos);
    float bias = max(0.005 * (1.0 - dot(normal, lightDir)), 0.005);
    // check whether current frag pos is in shadow
    // float shadow = currentDepth - bias > closestDepth  ? 1.0 : 0.0;
    // PCF
    float shadow = 0.0;
    int sampleRadius = 2;
    vec2 texelSize = 1.0 / textureSize(shadowMap2, 0);
    for(int x = -sampleRadius; x <= sampleRadius; ++x)
    {
        for(int y = -sampleRadius; y <= sampleRadius; ++y)
        {
            float pcfDepth = texture(shadowMap2, projCoords.xy + vec2(x, y) * texelSize).r; 
            shadow += currentDepth - bias > pcfDepth  ? 1.0 : 0.0;        
        }    
    }
    shadow /= pow((sampleRadius * 2 + 1), 2);
    
    // keep the shadow at 0.0 when outside the far_plane region of the light's frustum.
    if(projCoords.z > 1.0)
        shadow = 0.0;
        
    return shadow;
}


vec3 CalcSpotLight(SpotLight spotlight, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(geoSpotPos - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // attenuation
    float distance = length(geoSpotPos - fragPos);
    float attenuation = 1.0 / (spotlight.constant + spotlight.linear * distance + spotlight.quadratic * (distance * distance));    
    // spotlight intensity
    float theta = dot(lightDir, normalize(-geoSpotDir)); 
    float epsilon = spotlight.cutOff - spotlight.outerCutOff;
    float intensity = clamp((theta - spotlight.outerCutOff) / epsilon, 0.0, 1.0);
    // combine results
    float aoValue = noAo ? 1.0 : texture(material.ambient1, TexCoords).r;;
    vec3 ambient = aoValue * spotlight.ambient * vec3(texture(material.diffuse1, TexCoords));
    vec3 diffuse = spotlight.diffuse * diff * vec3(texture(material.diffuse1, TexCoords));
    vec3 specular = spotlight.specular * spec * vec3(texture(material.specular1, TexCoords).r);
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    float shadow = ShadowCalculation2(FragPosLightSpace2, normal);

    return (ambient + (diffuse + specular) * (1.0 - shadow));
}




vec3 CalcPointLight(pointLight pointl, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 pointPos)
{
    vec3 lightDir = normalize(pointPos - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // attenuation
    float distance = length(pointPos - fragPos);
    float attenuation = 1.0 / (pointl.constant + pointl.linear * distance + pointl.quadratic * (distance * distance));    
    // combine results
    float aoValue = noAo ? 1.0 : texture(material.ambient1, TexCoords).r;;
    vec3 ambient = aoValue * pointl.ambient * vec3(texture(material.diffuse1, TexCoords));
    vec3 diffuse = pointl.diffuse * diff * vec3(texture(material.diffuse1, TexCoords));
    float t = texture(material.specular1, TexCoords).r;
    vec3 specular = pointl.specular * spec * vec3(t, t, t);
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + (diffuse + specular));
}


void main()
{


    if(texture(material.diffuse1, TexCoords).a < 0.1)
        discard;
    //vec3 normalMapValue = texture(material.normal1, TexCoords).rgb ;
    //vec3 norm = normalize(Normal + normalMapValue);

    //vec3 dx = dFdx(FragPos);
    //vec3 dy = dFdy(FragPos);
    //vec3 norm = normalize(cross(dx, dy) + normalMapValue);
    vec3 norm;
    norm = normalize(texture(material.normal1, TexCoords).xyz * 2.0f - 1.0f);
    
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
	vec2 S = viewDirection.xy / viewDirection.z *   heightScale; 
    vec2 deltaUVs = S / numLayers;
	
	vec2 UVs = TexCoords;
	float currentDepthMapValue = 1.0f - texture(material.height1, UVs).r;
	if(!noparallax){
	// Loop till the point on the heightmap is "hit"
	while(currentLayerDepth < currentDepthMapValue)
    {
        UVs -= deltaUVs;
        currentDepthMapValue = 1.0f - texture(material.height1, UVs).r;
        currentLayerDepth += layerDepth;
    }

	// Apply Occlusion (interpolation with prev value)
	vec2 prevTexCoords = UVs + deltaUVs;
	float afterDepth  = currentDepthMapValue - currentLayerDepth;
	float beforeDepth = 1.0f - texture(material.height1, prevTexCoords).r - currentLayerDepth + layerDepth;
	float weight = afterDepth / (afterDepth - beforeDepth);
	UVs = prevTexCoords * weight + UVs * (1.0f - weight);

	// Get rid of anything outside the normal range
	if(UVs.x > 1.0 || UVs.y > 1.0 || UVs.x < 0.0 || UVs.y < 0.0)
		discard;
    }

    //vec3 dx = dFdx(FragPos);
    //vec3 dy = dFdy(FragPos);
    //vec3 norm = normalize(cross(dx, dy));



    // ambient
    float aoValue = noAo ? 1.0 : texture(material.ambient1, TexCoords).r;
    vec3 ambient = aoValue * light.ambient * texture(material.diffuse1, TexCoords).rgb;
  	
    // diffuse 
    // vec3 lightDir = normalize(light.position - FragPos);
    vec3 lightDir = normalize(lightDirection);  
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse1, UVs).rgb;  
    
    // specular
    vec3 viewDir = normalize(camPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 t = texture(material.specular1, UVs).rgb;
    vec3 specular = light.specular * spec * (noSpec ? vec3(1.0) : vec3(t.x,t.x,t.x));  
    
    float shadow = ShadowCalculation(FragPosLightSpace, norm);
    vec3 resultdir = (ambient + (diffuse + specular)* (1.0 - shadow));

    vec3 resultpoint;
    vec3 resultspot;
    if(hasPointLight)
        resultpoint = CalcPointLight(point, norm, FragPos, viewDir, geoPointPos);
    else
        resultpoint = vec3(0, 0, 0);


    if(spotOn)
        resultspot = CalcSpotLight(spotLight,norm,FragPos,viewDir);
    else
        resultspot = vec3(0);
    vec3 result = resultdir + resultpoint + resultspot;
    if(!gl_FrontFacing){
        result = result * 0.1;
    }

    FragColor = vec4(result, 1.0); 
    
} 