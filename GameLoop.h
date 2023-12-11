#pragma once
//#include "common.h"
#include <learnopengl/shader.h>
#include <learnopengl/simplemesh.h>
#include "PreRender.h"
#include "InputHandle.h"
#include "utils.h"


void startGame(GLFWwindow* window);
glm::mat4 setMVP(Shader shader, glm::mat4 transform);