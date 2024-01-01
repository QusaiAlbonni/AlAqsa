#include "backpack.h"


backpack::backpack(Shader shader) : object_(shader), model("res/models/backpack/backpack.obj")
{
	init();
}

void backpack::Draw()
{
	addDirectionalLight(shader);
	setMVP(shader);
	glm::mat4 transform = glm::translate(glm::mat4(1), glm::vec3(-0.f, 4.0f, -0.0f));
	drawMeshes(transform);
}

void backpack::drawMeshes(glm::mat4 transform, glm::mat4 scaleMat)
{

	shader.setMat4("model", transform);
	model.Draw(shader);
}

void backpack::DrawDepth(Shader depthShader, bool ortho)
{
	Shader temp = shader;
	shader = depthShader;
	glm::mat4 transform = glm::translate(glm::mat4(1), glm::vec3(0.0f, 4.0f, 0.0f));
	drawMeshes(transform);
	shader = temp;
}

void backpack::init()
{
}

