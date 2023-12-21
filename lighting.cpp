#include "lighting.h"

void addDirectionalLight(Shader shader, glm::vec3 lightDirection) {
    shader.use();
    shader.setVec3("light.direction", lightDirection);
    shader.setVec3("viewPos", camera.Position);

    // light properties
    shader.setVec3("light.ambient", 0.14f, 0.14f, 0.14f);
    shader.setVec3("light.diffuse", 0.9f, 0.9f, 0.9f);
    shader.setVec3("light.specular", 0.3f, 0.3f, 0.2f);
}