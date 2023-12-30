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


in DATA
{
    vec3 Normal;
	vec2 texCoord;
    mat4 projection;
    mat4 model;
    vec3 lightPos;
	vec3 camPos;
    vec4 FragPosLightSpace;
} data_in[];


in vec3 fragPos[];


out vec3 geoDir;
out vec3 geoViewPos;  
out vec3 geoPointPos;
out vec2 TexCoords;
out vec3 FragPos;  
out vec3 normalFragPos;
out vec3 Normal;
out mat3 tbn; 
out vec4 FragPosLightSpace;

uniform float time;
uniform vec3 viewPos;
uniform mat4 model;
uniform Light light;
uniform pointLight point;

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
    vec3 N = normalize(vec3(data_in[0].model * vec4(GetNormal(), 0.0f)));

    mat3 TBN = mat3(T, B, N);
    tbn = TBN;
    // TBN is an orthogonal matrix and so its inverse is equal to its transpose
    TBN = transpose(TBN);



    Normal = mat3(transpose(inverse(model))) * GetNormal();
    for (int i = 0; i < gl_in.length(); i++)
    {
        TexCoords = data_in[i].texCoord;
        FragPos = TBN * fragPos[i];
        normalFragPos = fragPos[i];
        geoDir = TBN * normalize(data_in[i].lightPos);
        geoViewPos = TBN * data_in[i].camPos;
        geoPointPos = TBN * point.position;
        FragPosLightSpace = data_in[i].FragPosLightSpace;
        gl_Position = data_in[i].projection * model * gl_in[i].gl_Position;
        EmitVertex();
       
    }
    EndPrimitive();
    
}