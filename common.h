#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <learnopengl/camera.h>
#include <learnopengl/model.h>
#include <SFML/Audio.hpp>
#include "Time.h"

extern unsigned int SCR_WIDTH;
extern unsigned int SCR_HEIGHT;
extern const GLenum DIRECTIONAL_TEXTURE;
extern const GLenum SPOTLIGHT_TEXTURE;
extern const glm::vec3 initCameraPos;


extern glm::vec3 lightPos;
extern glm::vec3 domePointlightPos;
extern glm::vec3 mosquePointlightPos;
extern const glm::vec3 cornerLight;
extern Camera camera;
extern bool spotLight;
extern bool night;




