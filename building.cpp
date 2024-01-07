#include "building.h"

void Building::init()
{
	shapeUtils::generateRectangle(15, 20, side.sVertices, side.indices);


	texture diff("res/textures/building-texts/building_diff.jpg","material.diffuse",GL_RGB, GL_SRGB);
	texture ao("res/textures/building-texts/building_ao.jpg", "material.ambient");
	texture nor("res/textures/building-texts/building_nor.png", "material.normal");
	texture spec("res/textures/building-texts/building-spec.jpg", "material.specular");
	vector<sTexture> texts = { diff.info, ao.info, nor.info, spec.info };

	sideMesh = Simplemesh(side.sVertices, side.indices, texts);
}
Building::Building(Shader shader) : object_(shader)
{
	init();
}
void Building::Draw()
{
	glm::mat4 transform(1);
	transform = glm::translate(transform, glm::vec3(100, 10, 200));
	drawMeshes(transform);

}

void Building::drawMeshes(glm::mat4 transform, glm::mat4 scaleMat)
{

	shader.setMat4("model", transform);
	sideMesh.Draw(shader);
}

void Building::DrawDepth(Shader depthShader, bool ortho)
{
}
