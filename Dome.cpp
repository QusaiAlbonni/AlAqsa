#include "Dome.h"
#include "rectangle.h"
#include "prism.h"
#include "sphere.h"

Dome::Dome(Shader shader) : object_(shader) {
	init();
}
void Dome::init(){
	createRectangle(2.0f, 1.0f, face.sVertices, face.indices);
	texture faceDiffuse("res/textures/domeWall/domeWall_diffuse.jpg", "material.diffuse", GL_NONE, GL_SRGB_ALPHA);
	texture faceSpecular("res/textures/domeWall/domeWall_rough.jpg", "material.specular");
	texture faceAmbient("res/textures/domeWall/domeWall_ao.jpg", "material.ambient");
	texture faceNormal("res/textures/domeWall/domeWall_nor.jpg", "material.normal");
	texture faceHeight("res/textures/domeWall/domeWall_height.jpg", "material.height");

	vector<sTexture> faceTextures= {
		faceDiffuse.info,
		faceSpecular.info,
		faceAmbient.info,
		faceNormal.info,
		faceHeight.info
	};

	faceMesh = Simplemesh(face.sVertices, face.indices, faceTextures);
	
	buildCircle(base.sVertices, base.indices, 2.613f, 8);
	texture baseDiffuse("res/textures/domeWall/base_diffuse.jpg", "material.diffuse", GL_RGB, GL_SRGB);
	texture baseSpecular("res/textures/domeWall/base_rough.jpg", "material.specular");
	texture baseAmbient("res/textures/domeWall/base_ao.jpg", "material.ambient");
	texture baseNormal("res/textures/domeWall/base_nor.jpg", "material.normal");
	texture baseHeight("res/textures/domeWall/base_height.jpg", "material.height");

	vector<sTexture> baseTextures = {
		baseDiffuse.info,
		baseSpecular.info,
		baseAmbient.info,
		baseNormal.info,
		baseHeight.info
	};
	baseMesh = Simplemesh(base.sVertices,base.indices, baseTextures);
	
	buildSphere(sphere.sVertices, sphere.indices, true);
	texture domeDiffuse("res/textures/domeWall/dome/dome_diffuse.jpg", "material.diffuse", GL_RGB, GL_SRGB);
	texture domeSpecular("res/textures/domeWall/dome/dome_spec.jpg", "material.specular");
	texture domeAmbient("res/textures/domeWall/dome/dome_ao.jpg", "material.ambient");
	texture domeNormal("res/textures/domeWall/dome/dome_nor.jpg", "material.normal");
	texture domeHeight("res/textures/domeWall/dome/dome_height.jpg", "material.height");
	vector<sTexture> domeTextures = { domeDiffuse.info , domeSpecular.info, domeAmbient.info, domeNormal.info, domeHeight.info };
	sphereMesh = Simplemesh(sphere.sVertices, sphere.indices, domeTextures);



	generateCylinder(1.0f, 0.3f, 50, 20, domeBase.sVertices, domeBase.indices);
	texture domebaseDiffuse("res/textures/domeWall/domeBase_diffuse.jpg", "material.diffuse", GL_RGB, GL_SRGB);
	texture domebaseSpecular("res/textures/domeWall/domeBase_spec.jpg", "material.specular");
	texture domebaseAmbient("res/textures/domeWall/domeBase_ao.jpg", "material.ambient");
	texture domebaseNormal("res/textures/domeWall/domeBase_nor.jpg", "material.normal");
	texture domebaseHeight("res/textures/domeWall/domeBase_height.jpg", "material.height");
	vector<sTexture> domebaseTextures = {
		domebaseDiffuse.info,
		domebaseSpecular.info,
		domebaseAmbient.info,
		domebaseNormal.info,
		domebaseHeight.info
	};
	domeBaseMesh = Simplemesh(domeBase.sVertices, domeBase.indices, domebaseTextures);

}



//draw final scene that will be drawn for viewer
void Dome::Draw() {
	glm::mat4 transform(1);
	transform = glm::translate(transform, glm::vec3(-40.0f, 0.0f, -40.0f));
	addDirectionalLight(shader, {-10.0f, -60.0f, 10.0f});
	shader.setFloat("material.shininess", 32.0f);
	setMVP(shader);
	drawMeshes(transform);
}

//This is to draw scene for depth map (shadow map)
void Dome::DrawDepth(Shader depthShader, bool ortho)
{
}


//This is a function that draws the scene at 0,0,0 world position DO NOT setMVP here this is just to render the scene 
void Dome::drawMeshes(glm::mat4 transform, glm::mat4 scaleMat) {
	using namespace glm;
	shader.use();

	float apothem = 2.0f / (2.0f * std::tan(glm::pi<float>() / 8));
	for (size_t i = 0; i < 8; i++)
	{
		glm::mat4 faceTransform(1);
		float directionOfFace = (static_cast<float>(i + 1) * (45.0f));
		float angle = (static_cast<float>(i) * (45.0f)) - 45.0f;
		float x = apothem * std::cos(glm::radians(directionOfFace));
		float z = -apothem * std::sin(glm::radians(directionOfFace));
		faceTransform = faceTransform * transform;
		faceTransform = glm::scale(faceTransform, glm::vec3(10.0f, 10.0f, 10.0f));
		faceTransform = faceTransform * scaleMat;
		faceTransform = glm::rotate(faceTransform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		faceTransform = glm::translate(faceTransform, glm::vec3(x, 0.5f, z));
		faceTransform = glm::rotate(faceTransform, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
		shader.setBool("noparallax", true);
		shader.setMat4("model", faceTransform);
		faceMesh.Draw(shader);
	}
	

	mat4 baseTransform(1);
	baseTransform = baseTransform * transform;
	baseTransform = scale(baseTransform, vec3(10.0f, 10.0f,10.0f));
	baseTransform = baseTransform * scaleMat;
	baseTransform = rotate(baseTransform, radians(22.5f), vec3(0.0f, 1.0f, 0.0f));
	baseTransform = translate(baseTransform, vec3(0.0f, 0.9f, 0.0f));
	baseTransform = rotate(baseTransform, radians(90.0f), vec3(1.0f, 0.0f, 0.0f));
	//shader.setBool("noparallax", false);
	shader.setMat4("model", baseTransform);
	baseMesh.Draw(shader, GL_TRIANGLE_FAN);

	mat4 sphereTransform(1);
	sphereTransform = sphereTransform * transform;
	sphereTransform = scale(sphereTransform, vec3(12.0f, 13.5f, 12.0f));
	sphereTransform = sphereTransform * scaleMat;
	sphereTransform = translate(sphereTransform, vec3(0.0f, 1.0f, 0.0f));
	shader.setMat4("model", sphereTransform);
	addDirectionalLight(shader, { 10.0f, -60.0f, -10.0f });
	sphereMesh.Draw(shader, GL_TRIANGLE_STRIP);


	mat4 domeBaseTransform(1);
	domeBaseTransform = domeBaseTransform * transform;
	domeBaseTransform = scale(domeBaseTransform, vec3(12.2f, 12.2f, 12.2f));
	domeBaseTransform = domeBaseTransform * scaleMat;
	domeBaseTransform = translate(domeBaseTransform, vec3(0.0f, 1.104599f, 0.0f));
	domeBaseTransform = rotate(domeBaseTransform, radians(180.0f), vec3(1.0f, 0.0f, 0.0f));
	shader.setMat4("model", domeBaseTransform);
	addDirectionalLight(shader, { 10.0f, -60.0f, -10.0f });
	domeBaseMesh.Draw(shader); 


	for (size_t i = 0; i < 7; i++)
	{
		glm::mat4 faceTransform(1);
		float directionOfFace = (static_cast<float>(i + 1) * (45.0f));
		float angle = (static_cast<float>(i) * (45.0f)) - 45.0f;
		float x = apothem * std::cos(glm::radians(directionOfFace));
		float z = -apothem * std::sin(glm::radians(directionOfFace));
		faceTransform = faceTransform * transform;
		faceTransform = glm::scale(faceTransform, glm::vec3(9.0f, 10.0f, 9.0f));
		faceTransform = faceTransform * scaleMat;
		faceTransform = glm::rotate(faceTransform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		faceTransform = glm::translate(faceTransform, glm::vec3(x, 0.5f, z));
		faceTransform = glm::rotate(faceTransform, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
		shader.setBool("noparallax", true);
		shader.setMat4("model", faceTransform);
		faceMesh.Draw(shader);
	}

}


