#pragma once
#include "object_.h"
#include "lighting.h"
#include <learnopengl/shape.h>

class Albaika
	:public object_
{
public:
	shape albaikaRec;
	Simplemesh albaikaRecmesh;
	static float width;
	static float height;
	shape baikCyl;
	Simplemesh baikCylmesh;
	shape rect;
	Simplemesh rectmesh;
	shape toprect;
	Simplemesh toprectmesh;
	void init() override;
	Albaika(Shader shader);
	void Draw() ;
	void DrawDepth(Shader depthShader, bool ortho) override;
	void drawMeshes(glm::mat4 transform, glm::mat4 scaleMat) override;


};

