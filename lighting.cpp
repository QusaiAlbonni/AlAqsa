#include "lighting.h"

void addDirectionalLight(Shader shader) {
    shader.use();
    shader.setVec3("light.direction", 10.2f, -10.0f, 10.3f);
    shader.setVec3("viewPos", camera.Position);

    // light properties
    shader.setVec3("light.ambient", 0.5f, 0.5f, 0.5f);
    shader.setVec3("light.diffuse", 0.8f, 0.8f, 0.8f);
    shader.setVec3("light.specular", 0.7f, 0.7f, 0.7f);
}