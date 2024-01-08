#include "mirror.h"
#include "lighting.h"
Mirror::Mirror(Shader shader) : object_(shader) , mirrorShader("shaders/enviromentmap.vs", "shaders/enviromentmap.fs")
{
	this->init();
}

void Mirror::init()
{
	vector<sTexture> texts= {};
	envMap = enviromentMap();
	envMapDay = enviromentMap(true);
    
	shapeUtils::generateRectangle(1.0, 2.0f, mirrorShape.sVertices, mirrorShape.indices);

	mirrorMesh = Simplemesh(mirrorShape.sVertices, mirrorShape.indices, texts);
}


void Mirror::Draw()
{
	drawMeshes(glm::translate(glm::mat4(1), glm::vec3(-37.0f, 1.5f, 70.0f)));
}

void Mirror::drawMeshes(glm::mat4 transform, glm::mat4 scaleMat)
{
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = camera.GetViewMatrix();
	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
	model = model * transform;
	mirrorShader.use();
	model = glm::rotate(model, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	mirrorShader.setMat4("model", model);
	mirrorShader.setMat4("view", view);
	mirrorShader.setMat4("projection", projection);
	mirrorShader.setVec3("cameraPos", camera.Position);
	glActiveTexture(GL_TEXTURE31);
	glBindTexture(GL_TEXTURE_CUBE_MAP, night? envMap : envMapDay);
	mirrorShader.setInt("skybox", 31);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, envMap);
	mirrorMesh.Draw(mirrorShader);
}

void Mirror::DrawDepth(Shader depthShader, bool ortho)
{
}
