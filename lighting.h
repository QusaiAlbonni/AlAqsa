#pragma once

#include "common.h"
#include <learnopengl/shader.h>




void addDirectionalLight(Shader shader, glm::vec3 lightDirection = lightPos);
void addPointLight(Shader shader, glm::vec3 lightPos);
void addSpotLight(Shader lightingShader, glm::vec3 lightPos = glm::vec3(camera.Position.x, camera.Position.y - 0.3f, camera.Position.z), glm::vec3 direction = camera.Front);
unsigned int enviromentMap(bool day = false);
unsigned int loadEnvCubemap(vector<std::string> faces);
