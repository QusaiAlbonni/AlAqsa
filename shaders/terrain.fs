#version 450 core
#extension GL_ARB_shader_derivative : enable

precision highp float;  // This line sets single precision for regular float variables

out vec4 FragColor;

struct Material {
    sampler2D diffuse1;
    sampler2D specular1;
    sampler2D normal1;
    sampler2D height1;
    sampler2D ambient1;
    sampler2D emission1;
    sampler2D rough1;
    sampler2D metallic1;
    sampler2D arm1;
    float shininess;
};

struct Light {
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

const float PI = 3.141592653589;

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
in vec4 FragPosLightSpace2;
in vec3 normalFragPos;

uniform Material material;
uniform Light light;
uniform SpotLight spotLight;
uniform pointLight point;

uniform vec3 viewPos;
uniform mat4 model;

uniform bool spotOn;
uniform bool isModel;
uniform bool noparallax;
uniform bool noNor;
uniform bool noSpec;
uniform bool noAo;
uniform bool hasPointLight;
uniform bool isMosque;
uniform bool hasEmissive;
uniform bool isPBR;

uniform sampler2D shadowMap1;
uniform sampler2D shadowMap2;



float DistributionGGX(vec3 N, vec3 H, float roughness) {
    float a = roughness;
    float a2 = a * a;
    float NdotH = max(dot(N, H), 0.0);
    float NdotH2 = NdotH * NdotH;

    float nom = a2;
    float denom = (NdotH2 * (a2 - 1.0) + 1.0);
    denom = PI * denom * denom;

    return nom / denom;
}
// ----------------------------------------------------------------------------
float GeometrySchlickGGX(float NdotV, float roughness) {
    float r = (roughness + 1.0);
    float k = (r * r) / 8.0;

    float nom = NdotV;
    float denom = NdotV * (1.0 - k) + k;

    return nom / denom;
}
// ----------------------------------------------------------------------------
float GeometrySmith(vec3 N, vec3 V, vec3 L, float roughness) {
    float NdotV = max(dot(N, V), 0.0);
    float NdotL = max(dot(N, L), 0.0);
    float ggx2 = GeometrySchlickGGX(NdotV, roughness);
    float ggx1 = GeometrySchlickGGX(NdotL, roughness);

    return ggx1 * ggx2;
}
// ----------------------------------------------------------------------------
vec3 fresnelSchlick(float cosTheta, vec3 F0) {
    return F0 + (1.0 - F0) * pow(clamp(1.0 - cosTheta, 0.0, 1.0), 5.0);
}



float ShadowCalculation(vec4 fragPosLightSpace, vec3 norm) {
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;

    projCoords = projCoords * 0.5 + 0.5;

    float closestDepth = texture(shadowMap1, projCoords.xy).r;

    float currentDepth = projCoords.z;

    vec3 normal = normalize(norm);
    vec3 lightDir = normalize(geoDir - FragPos);
    float bias = max(0.005 * (1.0 - dot(normal, lightDir)), 0.005);

    float shadow = 0.0;
    int sampleRadius = 2;
    vec2 texelSize = 1.0 / textureSize(shadowMap1, 0);
    for(int x = -sampleRadius; x <= sampleRadius; ++x) {
        for(int y = -sampleRadius; y <= sampleRadius; ++y) {
            float pcfDepth = texture(shadowMap1, projCoords.xy + vec2(x, y) * texelSize).r;
            shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;
        }
    }
    shadow /= pow((sampleRadius * 2 + 1), 2);

    if(projCoords.z > 1.0)
        shadow = 0.0;

    return shadow;
}

float ShadowCalculation2(vec4 fragPosLightSpace, vec3 norm) {
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;

    projCoords = projCoords * 0.5 + 0.5;

    float closestDepth = texture(shadowMap2, projCoords.xy).r;

    float currentDepth = projCoords.z;

    vec3 normal = normalize(norm);
    vec3 lightDir = normalize(geoDir - FragPos);
    float bias = max(0.005 * (1.0 - dot(normal, lightDir)), 0.005);

    float shadow = 0.0;
    int sampleRadius = 2;
    vec2 texelSize = 1.0 / textureSize(shadowMap2, 0);
    for(int x = -sampleRadius; x <= sampleRadius; ++x) {
        for(int y = -sampleRadius; y <= sampleRadius; ++y) {
            float pcfDepth = texture(shadowMap2, projCoords.xy + vec2(x, y) * texelSize).r;
            shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;
        }
    }
    shadow /= pow((sampleRadius * 2 + 1), 2);

    if(projCoords.z > 1.0)
        shadow = 0.0;

    return shadow;
}

vec3 CalcSpotLight(SpotLight spotlight, vec3 normal, vec3 fragPos, vec3 viewDir, vec2 UVs) {
    vec3 lightDir = normalize(geoSpotPos - fragPos);

    float diff = max(dot(normal, lightDir), 0.0);

    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

    float distance = length(geoSpotPos - fragPos);
    float attenuation = 1.0 / (spotlight.constant + spotlight.linear * distance + spotlight.quadratic * (distance * distance));

    float theta = dot(lightDir, normalize(-geoSpotDir));
    float epsilon = spotlight.cutOff - spotlight.outerCutOff;
    float intensity = clamp((theta - spotlight.outerCutOff) / epsilon, 0.0, 1.0);

    float aoValue = noAo ? 1.0 : texture(material.ambient1, UVs).r;
    ;
    vec3 ambient = aoValue * spotlight.ambient * vec3(texture(material.diffuse1, UVs));
    vec3 diffuse = spotlight.diffuse * diff * vec3(texture(material.diffuse1, UVs));
    vec3 specular = spotlight.specular * spec * vec3(texture(material.specular1, UVs).r);
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    float shadow = ShadowCalculation2(FragPosLightSpace2, normal);

    return (ambient + (diffuse + specular) * (1.0 - shadow));
}

vec3 CalcPointLight(pointLight pointl, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 pointPos, vec2 UVs) {
    vec3 lightDir = normalize(pointPos - fragPos);
    vec3 final;
    if(isPBR) {
        vec3 albedo = texture(material.diffuse1, UVs).rgb;
        float metallic = 0.4;
        float roughness = texture(material.rough1, UVs).r;
        float ao = texture(material.ambient1, UVs).r;

        vec3 N = normal;
        vec3 V = viewDir;
    
        vec3 F0 = vec3(0.04);
        F0 = mix(F0, albedo, metallic);

        vec3 Lo = vec3(0.0);

        vec3 L = normalize(lightDir);
        vec3 H = normalize(V + L);
        float distance = length(pointPos - fragPos);
        float attenuation = 1.0 / (distance * distance);
        vec3 radiance = pointl.diffuse * attenuation;

        float NDF = DistributionGGX(N, H, roughness);
        float G = GeometrySmith(N, V, L, roughness);
        vec3 F = fresnelSchlick(max(dot(H, V), 0.0), F0);

        vec3 numerator = NDF * G * F;
        float denominator = 4.0 * max(dot(N, V), 0.0) * max(dot(N, L), 0.0) + 0.0001; // + 0.0001 to prevent divide by zero
        vec3 specular = numerator / denominator;

        vec3 kS = F;

        vec3 kD = vec3(1.0) - kS;

        kD *= 1.0 - metallic;	  

        float NdotL = max(dot(N, L), 0.0);        

        Lo += (kD * albedo / PI + specular) * radiance * NdotL;

        vec3 ambient = vec3(0.03) *  albedo * ao * pointl.ambient;
        ambient *= attenuation;

        vec3 color = ambient + Lo;

        color = color / (color + vec3(1.0));

        final = color;
    } else {

        float diff = max(dot(normal, lightDir), 0.0);

        vec3 reflectDir = reflect(-lightDir, normal);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

        float distance = length(pointPos - fragPos);
        float attenuation = 1.0 / (pointl.constant + pointl.linear * distance + pointl.quadratic * (distance * distance));

        float aoValue = noAo ? 1.0 : texture(material.ambient1, UVs).r;
        ;
        vec3 ambient = aoValue * pointl.ambient * vec3(texture(material.diffuse1, UVs));
        vec3 diffuse = pointl.diffuse * diff * vec3(texture(material.diffuse1, UVs));
        float t = texture(material.specular1, UVs).r;
        vec3 specular = pointl.specular * spec * vec3(t, t, t);
        ambient *= attenuation;
        diffuse *= attenuation;
        specular *= attenuation;
        final = (ambient + (diffuse + specular));
    }
    return final;
}

void main() {

    if(texture(material.diffuse1, TexCoords).a < 0.1) {
        discard;
    }

    vec3 lightDirection = geoDir;
    vec3 camPos = geoViewPos;

    vec3 viewDirection = normalize(camPos - FragPos);

    float heightScale = 0.05;
    const float minLayers = 8.0;
    const float maxLayers = 512.0;
    float numLayers = mix(maxLayers, minLayers, abs(dot(vec3(0.0, 0.0, 1.0), viewDirection)));
    float layerDepth = 1.0 / numLayers;
    float currentLayerDepth = 0.0;

    vec2 S = viewDirection.xy / viewDirection.z * heightScale;
    vec2 deltaUVs = S / numLayers;

    vec2 UVs = TexCoords;
    float currentDepthMapValue = 1.0 - texture(material.height1, UVs).r;
    if(!noparallax) {
        while(currentLayerDepth < currentDepthMapValue) {
            UVs -= deltaUVs;
            currentDepthMapValue = 1.0 - texture(material.height1, UVs).r;
            currentLayerDepth += layerDepth;
        }

        vec2 prevTexCoords = UVs + deltaUVs;
        float afterDepth = currentDepthMapValue - currentLayerDepth;
        float beforeDepth = 1.0 - texture(material.height1, prevTexCoords).r - currentLayerDepth + layerDepth;
        float weight = afterDepth / (afterDepth - beforeDepth);
        UVs = prevTexCoords * weight + UVs * (1.0 - weight);

	//if(UVs.x > 1.0 || UVs.y > 1.0 || UVs.x < 0.0 || UVs.y < 0.0)
	//	discard;
    }

    vec3 norm;
    norm = normalize(texture(material.normal1, UVs).xyz * 2.0 - 1.0);

    vec3 viewDir = viewDirection;
    vec3 resultdir;
    float shadow = ShadowCalculation(FragPosLightSpace, norm);
    if(isPBR) {
        vec3 albedo = texture(material.diffuse1, UVs).rgb;
        float roughness = texture(material.rough1, UVs).r;
        float metallic = texture(material.metallic1, UVs).r;
        float ao = texture(material.ambient1, UVs).r;

        vec3 N = norm;
        vec3 V = viewDir;
 
        vec3 F0 = vec3(0.04);
        F0 = mix(F0, albedo, metallic);


        vec3 Lo = vec3(0.0);

        vec3 L = normalize(lightDirection);
        vec3 H = normalize(V + L);
        float distance = length(lightDirection);
        float attenuation = 1.0 / (distance * distance);
        vec3 radiance = light.diffuse;

        float NDF = DistributionGGX(N, H, roughness);
        float G = GeometrySmith(N, V, L, roughness);
        vec3 F = fresnelSchlick(max(dot(H, V), 0.0), F0);

        vec3 numerator = NDF * G * F;
        float denominator = 4 * max(dot(N, V), 0.0) * max(dot(N, L), 0.0) + 0.0001; // + 0.0001 to prevent divide by zero
        vec3 specular = numerator / denominator;

        vec3 kS = F;

        vec3 kD = vec3(1.0) - kS;

        kD *= 1.0 - metallic;	  

        float NdotL = max(dot(N, L), 0.0);        

        Lo += (kD * albedo / PI + specular) * radiance * NdotL;

        vec3 ambient = vec3(0.03) * albedo * ao * light.ambient;

        vec3 color = ambient + Lo * (1.0 - shadow);

        color = color / (color + vec3(1.0));

        resultdir = color;
    } else {

        float aoValue = noAo ? 1.0 : texture(material.ambient1, UVs).r;
        vec3 ambient = aoValue * light.ambient * texture(material.diffuse1, UVs).rgb;

    // diffuse 
        vec3 lightDir = normalize(lightDirection);
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = light.diffuse * diff * texture(material.diffuse1, UVs).rgb;  

    // specular
        viewDir = normalize(camPos - FragPos);
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
        vec3 t = texture(material.specular1, UVs).rgb;
        vec3 specular = light.specular * spec * (noSpec ? vec3(1.0) : vec3(t.x, t.x, t.x));

        
        resultdir = (ambient + (diffuse + specular) * (1.0 - shadow));
    }

    vec3 resultpoint;
    vec3 resultspot;
    if(hasPointLight)
        resultpoint = CalcPointLight(point, norm, FragPos, viewDir, geoPointPos, UVs);
    else
        resultpoint = vec3(0, 0, 0);

    if(spotOn)
        resultspot = CalcSpotLight(spotLight, norm, FragPos, viewDir, UVs);
    else
        resultspot = vec3(0);
    vec3 result = resultdir + resultpoint + resultspot;
    if(!gl_FrontFacing) {
        result = result * 0.1;
    }

    if(hasEmissive) {
        vec3 emission = texture(material.emission1, UVs).rgb;
        result += emission;
    }
    float alpha = texture(material.diffuse1, TexCoords).a;
    FragColor = vec4(result, 1.0);

}