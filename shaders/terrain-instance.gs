#version 330 core
layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;


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


in DATA
{
    vec3 Normal;
	vec2 texCoord;
    mat4 projection;
	mat4 model;
    vec3 lightPos;
	vec3 camPos;
    vec4 FragPosLightSpace;
    vec4 FragPosLightSpace2;
} data_in[];


in vec3 fragPos[];


out vec3 geoDir;
out vec3 geoViewPos;  
out vec3 geoPointPos;
out vec3 geoSpotPos;
out vec3 geoSpotDir;
out vec2 TexCoords;
out vec3 FragPos;  
out vec3 normalFragPos;
out vec3 Normal;
out mat3 tbn; 
out vec4 FragPosLightSpace;
out vec4 FragPosLightSpace2;

uniform float time;
uniform vec3 viewPos;
uniform mat4 model;
uniform bool isModel;
uniform Light light;
uniform pointLight point;
uniform SpotLight spotLight;

vec3 GetNormal()
{
    vec3 a = vec3(gl_in[0].gl_Position) - vec3(gl_in[1].gl_Position);
    vec3 b = vec3(gl_in[2].gl_Position) - vec3(gl_in[1].gl_Position);
    return normalize(cross(b, a));
}

void main() {


    

    vec3 edge0 = gl_in[1].gl_Position.xyz - gl_in[0].gl_Position.xyz;
    vec3 edge1 = gl_in[2].gl_Position.xyz - gl_in[0].gl_Position.xyz;

    // Lengths of UV differences
    vec2 deltaUV0 = data_in[1].texCoord - data_in[0].texCoord;
    vec2 deltaUV1 = data_in[2].texCoord - data_in[0].texCoord;

    // one over the determinant
    float invDet = 1.0f / (deltaUV0.x * deltaUV1.y - deltaUV1.x * deltaUV0.y);

    vec3 tangent = vec3(invDet * (deltaUV1.y * edge0 - deltaUV0.y * edge1));
    vec3 bitangent = vec3(invDet * (-deltaUV1.x * edge0 + deltaUV0.x * edge1));

    vec3 T = normalize(vec3(data_in[0].model * vec4(tangent, 0.0f)));
    vec3 B = normalize(vec3(data_in[0].model * vec4(bitangent, 0.0f)));
    vec3 N = normalize(vec3(data_in[0].model * vec4(isModel ? data_in[0].Normal : GetNormal(), 0.0f)));

    mat3 TBN = mat3(T, B, N);
    tbn = TBN;
    // TBN is an orthogonal matrix and so its inverse is equal to its transpose
    TBN = transpose(TBN);



    for (int i = 0; i < gl_in.length(); i++)
    {
        TexCoords = data_in[i].texCoord;
        FragPos = TBN * fragPos[i];
        normalFragPos = fragPos[i];
        geoDir = TBN * normalize(data_in[i].lightPos);
        geoViewPos = TBN * data_in[i].camPos;
        geoPointPos = TBN * point.position;
        geoSpotPos = TBN * spotLight.position;
        geoSpotDir = TBN * spotLight.direction;
        FragPosLightSpace = data_in[i].FragPosLightSpace;
        FragPosLightSpace2 = data_in[i].FragPosLightSpace2;
        Normal = normalize(mat3(transpose(inverse(data_in[i].model))) *(isModel ? data_in[i].Normal : GetNormal()));
        gl_Position = data_in[i].projection * data_in[i].model * gl_in[i].gl_Position;
        EmitVertex();
       
    }
    EndPrimitive();
    
}