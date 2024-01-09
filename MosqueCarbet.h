#pragma once
#include "object_.h"
#include "lighting.h"
#include "utils.h"
#include <learnopengl/shape.h>
class MosqueCarbet
	:public object_
{
public:
	shape square;
	Simplemesh squareMesh;
	void init() override;
	MosqueCarbet(Shader shader);
	void Draw() override;
	void drawMeshes(glm::mat4 transform, glm::mat4 scaleMat = glm::mat4(1)) override;


};

