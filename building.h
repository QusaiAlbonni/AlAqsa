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


	Simplemesh sideMesh2;


	void init() override;
	Building(Shader shader);
	void Draw() override;
	void drawMeshes(Simplemesh building, glm::mat4 transform, glm::mat4 scaleMat = glm::mat4(1));
	void DrawDepth(Shader depthShader, bool ortho = true) override;
	
};

