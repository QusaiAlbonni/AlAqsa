#include "lighting.h"

void addDirectionalLight(Shader shader, glm::vec3 lightDirection) {
    shader.use();
    shader.setVec3("light.direction", lightDirection);
    shader.setVec3("viewPos", camera.Position);

    // light properties
    shader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
    shader.setVec3("light.diffuse", 0.7f, 0.7f, 0.7f);
    shader.setVec3("light.specular", 0.8f, 0.8f, 0.8f);
}