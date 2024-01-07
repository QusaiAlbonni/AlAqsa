#include "building.h"

void Building::init()
{
	shapeUtils::generateRectangle(20, 30, side.sVertices, side.indices);


	texture diff("res/textures/building-texts/building_diff.jpg","material.diffuse",GL_RGB, GL_SRGB);
	texture ao("res/textures/building-texts/building_ao.jpg", "material.ambient");
	texture nor("res/textures/building-texts/building_nor.png", "material.normal");
	texture spec("res/textures/building-texts/building_spec.jpg", "material.specular");
	vector<sTexture> texts = { diff.info, ao.info, nor.info, spec.info };

	sideMesh = Simplemesh(side.sVertices, side.indices, texts);

	texture diff2("res/textures/building-texts/building2_diff.jpg", "material.diffuse", GL_RGB, GL_SRGB);
	texture ao2("res/textures/building-texts/building2_ao.jpg", "material.ambient");
	texture nor2("res/textures/building-texts/building2_nor.png", "material.normal");
	texture spec2("res/textures/building-texts/building2_spec.jpg", "material.specular");
	vector<sTexture> texts2 = { diff2.info, ao2.info, nor2.info, spec2.info };

	sideMesh2 = Simplemesh(side.sVertices, side.indices, texts2);
}
Building::Building(Shader shader) : object_(shader)
{
	init();
}
void Building::Draw()
{
	glm::mat4 transform(1);
	transform = glm::translate(transform, glm::vec3(110, 12, 200));
	drawMeshes(sideMesh, transform);

	transform = glm::mat4(1);
	transform = glm::translate(glm::mat4(1), glm::vec3(130, 20, 150));
	drawMeshes(sideMesh, transform);

	transform = glm::mat4(1);
	transform = glm::translate(glm::mat4(1), glm::vec3(120, 15, 100));
	drawMeshes(sideMesh2, transform);

	transform = glm::mat4(1);
	transform = glm::translate(glm::mat4(1), glm::vec3(140, 13, 50));
	drawMeshes(sideMesh2, transform);

	transform = glm::mat4(1);
	transform = glm::translate(glm::mat4(1), glm::vec3(150, 17, 0));
	drawMeshes(sideMesh, transform);

	transform = glm::mat4(1);
	transform = glm::translate(glm::mat4(1), glm::vec3(115, 12, -50));
	drawMeshes(sideMesh, transform);


	transform = glm::mat4(1);
	transform = glm::translate(glm::mat4(1), glm::vec3(130, 10, -100));
	drawMeshes(sideMesh2, transform);




	
	transform = glm::translate(glm::mat4(1), glm::vec3(-110, 20, 200));
	drawMeshes(sideMesh, transform);

	transform = glm::mat4(1);
	transform = glm::translate(glm::mat4(1), glm::vec3(-130, 15, 150));
	drawMeshes(sideMesh, transform);

	transform = glm::mat4(1);
	transform = glm::translate(glm::mat4(1), glm::vec3(-120, 13, 100));
	drawMeshes(sideMesh2, transform);

	transform = glm::mat4(1);
	transform = glm::translate(glm::mat4(1), glm::vec3(-140, 16, 50));
	drawMeshes(sideMesh2, transform);

	transform = glm::mat4(1);
	transform = glm::translate(glm::mat4(1), glm::vec3(-150, 18, 0));
	drawMeshes(sideMesh, transform);

	transform = glm::mat4(1);
	transform = glm::translate(glm::mat4(1), glm::vec3(-115, 21, -50));
	drawMeshes(sideMesh, transform);


	transform = glm::mat4(1);
	transform = glm::translate(glm::mat4(1), glm::vec3(0, 21, -180));
	drawMeshes(sideMesh, transform);

	transform = glm::mat4(1);
	transform = glm::translate(glm::mat4(1), glm::vec3(50, 27, -200));
	drawMeshes(sideMesh2, transform);

	transform = glm::mat4(1);
	transform = glm::translate(glm::mat4(1), glm::vec3(-25, 29, 170));
	drawMeshes(sideMesh, transform);

	transform = glm::mat4(1);
	transform = glm::translate(glm::mat4(1), glm::vec3(25, 27, 180));
	drawMeshes(sideMesh2, transform);
}

void Building::drawMeshes(Simplemesh building, glm::mat4 transform, glm::mat4 scaleMat)
{
	glm::mat4 trans(1);
	trans = trans * transform;
	trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, -10.0f));
	shader.setMat4("model", trans);
	building.Draw(shader);

	trans = glm::mat4(1);
	trans = trans * transform;
	trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, 10.0f));
	trans = glm::rotate(trans, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	shader.setMat4("model", trans);
	building.Draw(shader);

	trans = glm::mat4(1);
	trans = trans * transform;
	trans = glm::translate(trans, glm::vec3(-10.0f, 0.0f, 0.0f));
	trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	shader.setMat4("model", trans);
	building.Draw(shader);


	trans = glm::mat4(1);
	trans = trans * transform;
	trans = glm::translate(trans, glm::vec3(10.0f, 0.0f, 0.0f));
	trans = glm::rotate(trans, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	shader.setMat4("model", trans);
	building.Draw(shader);

}

void Building::DrawDepth(Shader depthShader, bool ortho)
{
}
