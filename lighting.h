#pragma once

#include "common.h"
#include <learnopengl/shader.h>




void addDirectionalLight(Shader shader, glm::vec3 lightDirection = lightPos);
void addPointLight(Shader shader, glm::vec3 lightPos);
void addSpotLight(Shader lightingShader, glm::vec3 lightPos = camera.Position, glm::vec3 direction = camera.Front);
