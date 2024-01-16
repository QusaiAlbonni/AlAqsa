#include "common.h"


unsigned int SCR_WIDTH = 1920;
unsigned int SCR_HEIGHT = 1080;
const GLenum DIRECTIONAL_TEXTURE = GL_TEXTURE20;
const GLenum SPOTLIGHT_TEXTURE = GL_TEXTURE21;
const glm::vec3 initCameraPos = glm::vec3(-37.0f, 1.5f, 70.0f);

Camera camera(initCameraPos);
glm::vec3 lightPos(100.0f, 100.0f, 100.0f);
glm::vec3 domePointlightPos(-40.0f, 10.0f, -40.0f);
glm::vec3 mosquePointlightPos(0.0f, 10.0f, 117.0f);
const glm::vec3 cornerLight(94.0f, 14.0f, 144.0f);
bool spotLight = false;
bool night = false;
bool pbr = false;
