#pragma once
#include "common.h"
#include <learnopengl/shader.h>
#include <learnopengl/simplemesh.h>
#include "object_.h"


class DepthMap
{
public:
	unsigned int FBO;
	unsigned int depthMap;
	glm::mat4 lightSpaceMatrix;
	float near_plane = 1.0f, far_plane = 350.0f;
	Shader depthShader;
	Shader debugDepthQuad;
	DepthMap(Shader shader);
	void init();
	void renderQuad();
	unsigned int render(std::vector<std::reference_wrapper<object_>> objects, Simplemesh terrain);
private:
	const unsigned int SHADOW_WIDTH = 3160, SHADOW_HEIGHT = 3160;
};

