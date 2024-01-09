#include "outersquare.h"
#include"texture.h"
#include "GameLoop.h"
 


outersquare::outersquare(Shader shader) : object_(shader),

birds("res/models/bird/DOVE.OBJ"),
fountain("res/models/fountain/Fountain N070612.3DS")
{
	init();
}
void outersquare::init() {
 

 
 
}

void outersquare::Draw() {
	shader.use();
	glm::mat4 transform(1.0f);
	transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
	setMVP(shader);
	drawMeshes(transform);




}


void outersquare::drawMeshes(glm::mat4 transform, glm::mat4 scaleMat) {

	




	glm::mat4 Fountain(1.0f);
	Fountain= glm::translate(Fountain, glm::vec3(-29.8f, 0.5f, 40.0f));
	Fountain = glm::scale(Fountain, glm::vec3(0.015f, 0.015f, 0.015f));
	 
	shader.setMat4("model", Fountain);
	fountain.Draw(shader);

	float x = 2.5f;
	for(int i=0;i<4;i++){
		glm::mat4 bird(1.0f);
		bird = glm::translate(bird,glm::vec3(-50*sin(glfwGetTime()) + x,18.0f,50*cos(glfwGetTime())));
		bird = glm::rotate(bird, glm::radians(60.0f) * (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
		bird = glm::scale(bird, glm::vec3(5.0f, 5.0f, 5.0f));
		shader.setMat4("model", bird);
		birds.Draw(shader);
		x += 2.5;
	}
	float z = 2.0f;
	for(int i=0;i<6;i++){
		glm::mat4 bird(1.0f);
		bird = glm::translate(bird,glm::vec3(28 + z, 30.0f,100.0f * sin(glfwGetTime())));
		bird = glm::rotate(bird, glm::radians(90.0f) * (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
		bird = glm::scale(bird, glm::vec3(7.0f, 7.0f, 7.0f));
		shader.setMat4("model", bird);
		birds.Draw(shader);
		z += 2.5;
	}

	



	 



}








