#pragma once
#include "object_.h"
#include "lighting.h"
#include "utils.h"
#include <learnopengl/shape.h>
class square
	:public object_
{
public:
	shape squares;
	Simplemesh squaremesh;
	void init() override;
	square(Shader shader);
	void Draw() override;
	void drawMeshes(glm::mat4 transform, glm::mat4 scaleMat = glm::mat4(1)) override;

};

