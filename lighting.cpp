#include "lighting.h"

void addDirectionalLight(Shader shader, glm::vec3 lightDirection) {
    shader.use();
    shader.setVec3("light.direction", lightDirection);
    shader.setVec3("viewPos", camera.Position);

    // light properties
    if (!night)
    {
        shader.setVec3("light.ambient", 0.14f, 0.14f, 0.14f);
        shader.setVec3("light.diffuse", 0.9f, 0.9f, 0.9f);
        shader.setVec3("light.specular", 0.3f, 0.3f, 0.2f);
    }
    else {
        shader.setVec3("light.ambient", 0.0028f, 0.0028f, 0.028f);
        shader.setVec3("light.diffuse", 0.04f, 0.04f, 0.1f);
        shader.setVec3("light.specular", 0.06f, 0.06f, 0.06f);
    }
}

void addPointLight(Shader lightingShader, glm::vec3 lightPos) {
    lightingShader.setVec3("point.position", lightPos);
    lightingShader.setVec3("viewPos", camera.Position);
    lightingShader.setVec3("point.ambient", 0.3f, 0.3f, 0.3f);
    lightingShader.setVec3("point.diffuse", 0.9f, 0.9f, 0.7f);
    lightingShader.setVec3("point.specular", 0.2f, 0.2f, 0.2f);
    lightingShader.setFloat("point.constant", 1.0f);
    lightingShader.setFloat("point.linear", 0.0000014f);
    lightingShader.setFloat("point.quadratic", 0.014f);
}

void addSpotLight(Shader lightingShader, glm::vec3 lightPos, glm::vec3 direction) {
    lightingShader.setVec3("spotLight.position", lightPos);
    lightingShader.setVec3("viewPos", camera.Position);
    lightingShader.setVec3("spotLight.direction", direction);
    lightingShader.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
    lightingShader.setVec3("spotLight.diffuse", 0.7f, 0.7f, 0.7f);
    lightingShader.setVec3("spotLight.specular", 0.4f, 0.4f, 0.4f);
    lightingShader.setFloat("spotLight.constant", 1.0f);
    lightingShader.setFloat("spotLight.linear", 0.09f);
    lightingShader.setFloat("spotLight.quadratic", 0.032f);
    lightingShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    lightingShader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
}