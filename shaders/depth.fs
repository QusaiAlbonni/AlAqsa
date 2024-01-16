#version 450 core
struct Material {
    sampler2D diffuse1;
    sampler2D specular1;
    sampler2D normal1;
    sampler2D height1;
    sampler2D ambient1;
    sampler2D emission1;
    float shininess;
};

uniform Material material;


in vec2 TexCoords;

void main() {
    if(texture(material.diffuse1, TexCoords).a < 0.1) {
        discard;
    }
    // gl_FragDepth = gl_FragCoord.z;
}