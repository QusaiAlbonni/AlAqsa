#pragma once

#include "common.h"
#include <learnopengl/shader.h>

void addDirectionalLight(Shader shader, glm::vec3 lightDirection = { 10.0f, -30.0f, -15.0f });
