#include "common.h"


const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;
const GLenum DIRECTIONAL_TEXTURE = GL_TEXTURE20;
const GLenum SPOTLIGHT_TEXTURE = GL_TEXTURE22;
const glm::vec3 initCameraPos = glm::vec3(0.0f, 1.5f, 0.0f);

Camera camera(initCameraPos);
glm::vec3 lightPos(-60.0f, 60.0f, -60.0f);
glm::vec3 domePointlightPos(-40.0f, 10.0f, -40.0f);
bool spotLight = false;
bool night = true;
