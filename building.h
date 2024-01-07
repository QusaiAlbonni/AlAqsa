#pragma once
#include "common.h"
#include <learnopengl/shape.h>
#include "object_.h"
class Building : public object_
{
public:
	shape side;
	Simplemesh sideMesh;

	shape top;
	Simplemesh topMesh;


	void init() override;
	Building(Shader shader);
	void Draw() override;
	void drawMeshes(glm::mat4 transform, glm::mat4 scaleMat = glm::mat4(1)) override;
	void DrawDepth(Shader depthShader, bool ortho = true) override;
	
};

