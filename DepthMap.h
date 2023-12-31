#pragma once
#include "common.h"
#include <learnopengl/shader.h>
#include <learnopengl/simplemesh.h>
#include "object_.h"


class DepthMap
{
private:
	unsigned int FBO;
	const unsigned int SHADOW_WIDTH = 6000, SHADOW_HEIGHT = 6000;
	const unsigned int SHADOW_WIDTH_POINT = 1024, SHADOW_HEIGHT_POINT = 1024;
public:
	unsigned int depthMap;
	unsigned int depthCubeMap;
	string type;
	glm::mat4 lightSpaceMatrix;
	float near_plane, far_plane;
	GLfloat pnear_plane = 0.2f, pfar_plane = 100.0f;
	float top = 200.0f, bottom = -200.0f, left = -300.0f, right = 300.0f;
	Shader depthShader;
	Shader debugDepthQuad;
	DepthMap(Shader shader, string type);
	void initDirec();
	void renderQuad();
	unsigned int render(std::vector<std::reference_wrapper<object_>> objects, glm::vec3 plightPos = glm::vec3(0));
};

