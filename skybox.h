#pragma once
#include "common.h"
#include <learnopengl/shader_m.h>

unsigned int loadCubemap(std::vector<std::string> faces);
unsigned int setupSkyBox();
unsigned int initSkyBoxTextures();
void drawSkyBox(Shader shader, unsigned int VAO, unsigned int texture);


unsigned int loadCubemapNight(std::vector<std::string> faces);
unsigned int setupSkyBoxNight();
unsigned int initSkyBoxTexturesNight();
void drawSkyBoxNight(Shader shader, unsigned int VAO, unsigned int texture);

