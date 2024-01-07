#include "Dome.h"
#include "texture.h"



Dome::Dome(Shader shader) : object_(shader) {
	init();
}
void Dome::init(){
	shapeUtils::generateRectangle(2.0f, 1.0f, face.sVertices, face.indices);
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
	
	shapeUtils::generateCircle(base.sVertices, base.indices, 2.613f, 8, glm::vec3(0, 0.0f, -0.5f));
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
	
	shapeUtils::generateSphere(sphere.sVertices, sphere.indices, true);
	texture domeDiffuse("res/textures/domeWall/dome/dome_diffuse.jpg", "material.diffuse", GL_RGB, GL_SRGB);
	texture domeSpecular("res/textures/domeWall/dome/dome_spec.jpg", "material.specular");
	texture domeAmbient("res/textures/domeWall/dome/dome_ao.jpg", "material.ambient");
	texture domeNormal("res/textures/domeWall/dome/dome_nor.jpg", "material.normal");
	texture domeHeight("res/textures/domeWall/dome/dome_height.jpg", "material.height");
	vector<sTexture> domeTextures = { domeDiffuse.info , domeSpecular.info, domeAmbient.info, domeNormal.info, domeHeight.info };
	sphereMesh = Simplemesh(sphere.sVertices, sphere.indices, domeTextures);



	shapeUtils::generateCylinder(1.0f, 0.3f, 50, 20, domeBase.sVertices, domeBase.indices);
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

	texture frontFacediffuse("res/textures/domeWall/front_face/front_face_diffuse.png", "material.diffuse", GL_RGBA, GL_SRGB8_ALPHA8);
	vector<sTexture> frontfaceTexts = {
		frontFacediffuse.info,
		faceAmbient.info,
		faceHeight.info,
		faceNormal.info,
		faceSpecular.info

	};
	frontFaceMesh = Simplemesh(face.sVertices, face.indices, frontfaceTexts);

	shapeUtils::generateRectangle(0.096f, 1.0f, innerSideWall.sVertices, innerSideWall.indices);
	texture wallDiff("res/textures/concrete_wall_diff.jpg", "material.diffuse");
	texture wallAo("res/textures/concrete_wall_ao.jpg", "material.ambient");
	texture wallSpec("res/textures/concrete_wall_rough.jpg", "material.specular");
	texture wallNorm("res/textures/concrete_wall_nor.jpg", "material.normal");
	texture wallHeight("res/textures/concrete_wall_height.jpg", "material.height");
	vector<sTexture> wallTexts = {
		wallDiff.info,
		wallAo.info,
		wallSpec.info,
		wallNorm.info,
		wallHeight.info
	};
	innerSideWallMesh = Simplemesh(innerSideWall.sVertices, innerSideWall.indices, wallTexts);



	shapeUtils::generateCylinder(0.3f, 0.5f, 400, 100, halfCylinder.sVertices, halfCylinder.indices, true);
	halfCylinderMesh = Simplemesh(halfCylinder.sVertices, halfCylinder.indices, wallTexts);


	shapeUtils::generateCircle(halfCircle.sVertices, halfCircle.indices, 0.3f, 200, { 0, 0, 0 }, true);
	halfCircleMesh = Simplemesh(halfCircle.sVertices, halfCircle.indices, wallTexts);
	
	shapeUtils::generateCylinder(0.05f, 0.7f, 100, 200, column.sVertices, column.indices);
	columnMesh = Simplemesh(column.sVertices, column.indices, wallTexts);

	shapeUtils::generateRectangle(0.5f, 0.6f, cylBase.sVertices, cylBase.indices);
	cylBaseMesh = Simplemesh(cylBase.sVertices, cylBase.indices, wallTexts);





	roofWall.vertices = {

		-0.5f, -0.5f, -0.3f,0,0,0,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.3f,0,0,0,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.3f,0,0,0,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.3f,0,0,0,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.3f,0,0,0,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.3f,0,0,0,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.3f,0,0,0,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.3f,0,0,0,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.3f,0,0,0,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.3f,0,0,0,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.3f,0,0,0,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.3f,0,0,0,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.3f,0,0,0,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.3f,0,0,0,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.3f,0,0,0,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.3f,0,0,0,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.3f,0,0,0,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.3f,0,0,0,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.3f,0,0,0,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.3f,0,0,0,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.3f,0,0,0,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.3f,0,0,0,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.3f,0,0,0,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.3f,0,0,0,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.3f,0,0,0,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.3f,0,0,0,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.3f,0,0,0,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.3f,0,0,0,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.3f,0,0,0,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.3f,0,0,0,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.3f,0,0,0,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.3f,0,0,0,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.3f,0,0,0,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.3f,0,0,0,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.3f,0,0,0,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.3f,0,0,0,  0.0f, 1.0f
	};
	for (int i = 0; i < 36; i++) {

		roofWall.indices.push_back(i);
	}
	roofWall.sVertices = convertToVertexglmVector(roofWall.vertices);
	roofWallmesh = Simplemesh(roofWall.sVertices, roofWall.indices, wallTexts);

	shapeUtils::generateCylinder(0.3f, 5.0f, 100, 50, DoorCylinder.sVertices, DoorCylinder.indices);
	DoorCylindermesh = Simplemesh(DoorCylinder.sVertices, DoorCylinder.indices, wallTexts);

	shapeUtils::generateCylinder(0.3f, 0.5f, 200, 100, halfcylinder.sVertices, halfcylinder.indices, true);
	halfcylindermesh = Simplemesh(halfcylinder.sVertices, halfcylinder.indices, wallTexts);
	shapeUtils::generateRectangle(1, 0.5, square.sVertices, square.indices);
	squaremesh = Simplemesh(square.sVertices, square.indices, wallTexts);
}



//draw final scene that will be drawn for viewer
void Dome::Draw() {
	glm::mat4 transform(1);
	transform = glm::translate(transform, glm::vec3(-40.0f, 1.0f, -40.0f));
	addDirectionalLight(shader);
	shader.setFloat("material.shininess", 32.0f);
	addPointLight(shader, domePointlightPos);
	shader.setBool("hasPointLight", true);
	shader.setFloat("material.shininess", 32.0f);
	setMVP(shader);
	glm::mat4 scalemat = glm::scale(glm::mat4(1), glm::vec3(1.0f, 1.2f, 1.0f));
	drawMeshes(transform, scalemat);
}

//This is to draw scene for depth map (shadow map)
void Dome::DrawDepth(Shader depthShader, bool ortho)
{
	Shader temp = shader;
	shader = depthShader;
	glm::mat4 transform(1);
	transform = glm::translate(transform, glm::vec3(-40.0f, 1.0f, -40.0f));
	glm::mat4 scalemat = glm::scale(glm::mat4(1), glm::vec3(1.0f, 1.2f, 1.0f));
	drawMeshes(transform, scalemat);
	shader = temp;
}


//This is a function that draws the scene at 0,0,0 world position DO NOT setMVP here this is just to render the scene 
void Dome::drawMeshes(glm::mat4 transform, glm::mat4 scaleMat) {
	using namespace glm;
	shader.use();

	float apothem = 2.0f / (2.0f * std::tan(glm::pi<float>() / 8));
	float doorX = 0.0f;
	float doorZ = 0.0f;
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
		if (i == 7)
		{
			doorX = x;
			doorZ = z;
			frontFaceMesh.Draw(shader);
			break;
		}
		else if (i == 1)
		{
			frontFaceMesh.Draw(shader);
		}
		else
			faceMesh.Draw(shader);

	}


	// 1

	glm::mat4 innerWallTrans(1);
	innerWallTrans = innerWallTrans * transform;
	innerWallTrans = glm::scale(innerWallTrans, glm::vec3(10.0f, 10.0f, 10.0f));
	innerWallTrans = innerWallTrans * scaleMat;
	innerWallTrans = glm::rotate(innerWallTrans, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	innerWallTrans = glm::translate(innerWallTrans, glm::vec3(doorX - 0.048f, 0.5f, doorZ + 0.284f));
	shader.setMat4("model", innerWallTrans);
	innerSideWallMesh.Draw(shader);

	innerWallTrans = glm::mat4(1);
	innerWallTrans = innerWallTrans * transform;
	innerWallTrans = glm::scale(innerWallTrans, glm::vec3(10.0f, 10.0f, 10.0f));
	innerWallTrans = innerWallTrans * scaleMat;
	innerWallTrans = glm::rotate(innerWallTrans, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	innerWallTrans = glm::translate(innerWallTrans, glm::vec3(doorX - 0.048f, 0.5f, doorZ - 0.275f));
	innerWallTrans = glm::rotate(innerWallTrans, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	shader.setMat4("model", innerWallTrans);
	innerSideWallMesh.Draw(shader);

	innerWallTrans = glm::mat4(1);
	innerWallTrans = innerWallTrans * transform;
	innerWallTrans = glm::scale(innerWallTrans, glm::vec3(10.0f, 10.0f, 10.0f));
	innerWallTrans = innerWallTrans * scaleMat;
	innerWallTrans = glm::rotate(innerWallTrans, glm::radians(-90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	innerWallTrans = glm::rotate(innerWallTrans, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	innerWallTrans = glm::translate(innerWallTrans, glm::vec3(doorX - 0.048f, 0.0f, doorZ + 0.4f));
	shader.setMat4("model", innerWallTrans);
	innerSideWallMesh.Draw(shader);
	
	
	//

	// 2

	innerWallTrans = glm::mat4(1);
	innerWallTrans = innerWallTrans * transform;
	innerWallTrans = glm::scale(innerWallTrans, glm::vec3(10.0f, 10.0f, 10.0f));
	innerWallTrans = innerWallTrans * scaleMat;
	innerWallTrans = glm::translate(innerWallTrans, glm::vec3(doorX - 0.048f, 0.5f, doorZ + 0.284f));
	shader.setMat4("model", innerWallTrans);
	innerSideWallMesh.Draw(shader);

	innerWallTrans = glm::mat4(1);
	innerWallTrans = innerWallTrans * transform;
	innerWallTrans = glm::scale(innerWallTrans, glm::vec3(10.0f, 10.0f, 10.0f));
	innerWallTrans = innerWallTrans * scaleMat;
	innerWallTrans = glm::translate(innerWallTrans, glm::vec3(doorX - 0.048f, 0.5f, doorZ - 0.275f));
	innerWallTrans = glm::rotate(innerWallTrans, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	shader.setMat4("model", innerWallTrans);
	innerSideWallMesh.Draw(shader);

	innerWallTrans = glm::mat4(1);
	innerWallTrans = innerWallTrans * transform;
	innerWallTrans = glm::scale(innerWallTrans, glm::vec3(10.0f, 10.0f, 10.0f));
	innerWallTrans = innerWallTrans * scaleMat;
	innerWallTrans = glm::rotate(innerWallTrans, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	innerWallTrans = glm::translate(innerWallTrans, glm::vec3(doorX - 0.048f, 0.0f, doorZ + 0.4f));
	shader.setMat4("model", innerWallTrans);
	innerSideWallMesh.Draw(shader);

	//


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
	sphereTransform = scale(sphereTransform, vec3(12.0f, 12.5f, 12.0f));
	sphereTransform = sphereTransform * scaleMat;
	sphereTransform = translate(sphereTransform, vec3(0.0f, 1.0f, 0.0f));
	shader.setMat4("model", sphereTransform);
	shader.setFloat("material.shininess", 64.0f);
	sphereMesh.Draw(shader, GL_TRIANGLE_STRIP);
	shader.setFloat("material.shininess", 32.0f);

	mat4 domeBaseTransform(1);
	domeBaseTransform = domeBaseTransform * transform;
	domeBaseTransform = scale(domeBaseTransform, vec3(12.2f, 12.2f, 12.2f));
	domeBaseTransform = domeBaseTransform * scaleMat;
	domeBaseTransform = translate(domeBaseTransform, vec3(0.0f, 1.104599f, 0.0f));
	domeBaseTransform = rotate(domeBaseTransform, radians(180.0f), vec3(1.0f, 0.0f, 0.0f));
	shader.setMat4("model", domeBaseTransform);
	domeBaseMesh.Draw(shader); 


	for (size_t i = 0; i < 8; i++)
	{

		glm::mat4 faceTransform(1);
		float directionOfFace = (static_cast<float>(i + 1) * (45.0f));
		float angle = (static_cast<float>(i) * (45.0f)) - 45.0f;
		float x = apothem * std::cos(glm::radians(directionOfFace));
		float z = -apothem * std::sin(glm::radians(directionOfFace));
		faceTransform = faceTransform * transform;
		if (i == 7)
		{
			faceTransform = glm::scale(faceTransform, glm::vec3(10.2f, 10.0f, 9.6f));
			faceTransform = glm::translate(faceTransform, glm::vec3(-0.015f, 0, 0.0f));
		}
		else if (i == 1) {
			faceTransform = glm::scale(faceTransform, glm::vec3(9.6f, 10.0f, 10.2f));
			faceTransform = glm::translate(faceTransform, glm::vec3(0, 0, 0.01f));
		}
		else
			faceTransform = glm::scale(faceTransform, glm::vec3(9.6f, 10.0f, 9.6f));
		faceTransform = faceTransform * scaleMat;
		faceTransform = glm::rotate(faceTransform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		faceTransform = glm::translate(faceTransform, glm::vec3(x, 0.5f, z));
		faceTransform = glm::rotate(faceTransform, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
		faceTransform = glm::rotate(faceTransform, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		shader.setBool("noparallax", true);
		shader.setMat4("model", faceTransform);
		if (i == 7)
		{
			doorX = x;
			doorZ = z;
			frontFaceMesh.Draw(shader);
			break;
		}
		else if(i == 1)
		{
			frontFaceMesh.Draw(shader);
		}
		else
			faceMesh.Draw(shader);
	}



	



	//addDirectionalLight(shader, glm::vec3(lightPos.x, lightPos.y, -lightPos.z));
	glm::mat4 cylTransform(1);
	cylTransform = cylTransform * transform;
	cylTransform = glm::scale(cylTransform, glm::vec3(10.0f, 10.0f, 10.0f));
	cylTransform = cylTransform * scaleMat;
	cylTransform = glm::rotate(cylTransform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	cylTransform = glm::translate(cylTransform, glm::vec3(doorX + 0.2f, 0.5f, doorZ));
	cylTransform = glm::rotate(cylTransform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	cylTransform = glm::rotate(cylTransform, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	shader.setMat4("model", cylTransform);
	halfCylinderMesh.Draw(shader);


	glm::mat4 circTransform(1);
	circTransform = circTransform * transform;
	circTransform = glm::scale(circTransform, glm::vec3(10.0f, 10.0f, 10.0f));
	circTransform = circTransform * scaleMat;
	circTransform = glm::rotate(circTransform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	circTransform = glm::translate(circTransform, glm::vec3(doorX + 0.45f, 0.5f, doorZ));
	circTransform = glm::rotate(circTransform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	circTransform = glm::rotate(circTransform, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	shader.setMat4("model", circTransform);
	halfCircleMesh.Draw(shader, GL_TRIANGLE_FAN);

	glm::mat4 columnTrans(1);
	columnTrans = columnTrans * transform;
	columnTrans = glm::scale(columnTrans, glm::vec3(10.0f, 10.0f, 10.0f));
	columnTrans = columnTrans * scaleMat;
	columnTrans = glm::rotate(columnTrans, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	columnTrans = glm::translate(columnTrans, glm::vec3(doorX + 0.4f, 0.16f, doorZ + 0.245f));
	shader.setMat4("model", columnTrans);
	columnMesh.Draw(shader);

	columnTrans = glm::mat4(1);
	columnTrans = columnTrans * transform;
	columnTrans = glm::scale(columnTrans, glm::vec3(10.0f, 10.0f, 10.0f));
	columnTrans = columnTrans * scaleMat;
	columnTrans = glm::rotate(columnTrans, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	columnTrans = glm::translate(columnTrans, glm::vec3(doorX + 0.4f, 0.16f, doorZ - 0.245f));
	shader.setMat4("model", columnTrans);
	columnMesh.Draw(shader);



	glm::mat4 lastTrans(1);
	lastTrans = lastTrans * transform;
	lastTrans = glm::scale(lastTrans, glm::vec3(10.0f, 10.0f, 10.0f));
	lastTrans = lastTrans * scaleMat;
	lastTrans = glm::rotate(lastTrans, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	lastTrans = glm::translate(lastTrans, glm::vec3(doorX + 0.2f, 0.5f, doorZ));
	lastTrans = glm::rotate(lastTrans, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	lastTrans = glm::rotate(lastTrans, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	shader.setMat4("model", lastTrans);
	cylBaseMesh.Draw(shader);


	float xk = 0.0f;
	float zf = -7.3f;
	float xf = 28.0f;
	for (int i = 1; i <= 6; i++) {
		glm::mat4 bak = glm::mat4(1.0f);
		bak = bak * transform;
		bak = bak * scaleMat;
		if (i == 3) {
			bak = glm::translate(bak, glm::vec3(xf, 2.0f, zf + xk));
			xk += 6.3f;
			shader.setMat4("model", bak);
			DoorCylindermesh.Draw(shader);
			continue;
		}
		if (i & 1) {

			bak = glm::translate(bak, glm::vec3(xf, 2.0f, zf + xk));
			xk += 1.5f;
			shader.setMat4("model", bak);
			DoorCylindermesh.Draw(shader);
		}
		else {

			bak = glm::translate(bak, glm::vec3(xf, 2.0f, zf + xk));
			xk += 2.7f;
			shader.setMat4("model", bak);
			DoorCylindermesh.Draw(shader);
		}
	}



	glm::mat4 hcylinder = glm::mat4(1.0f);
	hcylinder = hcylinder * transform;
	hcylinder = hcylinder * scaleMat;
	hcylinder = glm::translate(hcylinder, glm::vec3(26.1, 4.5f, 0.0f));
	hcylinder = glm::rotate(hcylinder, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	hcylinder = glm::rotate(hcylinder, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	hcylinder = glm::scale(hcylinder, glm::vec3(9.0f, 9.0f, 9.0f));
	shader.setMat4("model", hcylinder);
	halfcylindermesh.Draw(shader);

	//hcylinder = glm::translate(hcylinder, glm::vec3(-12.7f, 4.4f, -39.7f));
	//hcylinder = glm::rotate(hcylinder, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//hcylinder = glm::rotate(hcylinder, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	//hcylinder = glm::scale(hcylinder, glm::vec3(7.2f, 7.5f, 7.5f));
	//shader.setMat4("model", hcylinder);
	//halfcylindermesh.Draw(shader);


	float az = 0.0f;
	float xd = 26.2;
	for (int i = 0; i < 2; i++) {


		glm::mat4 model = glm::mat4(1.0f);
		model = model * transform;
		model = model * scaleMat;
		model = glm::translate(model, glm::vec3(xd, 4.7f, 5.2f - az));

		model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

		model = glm::scale(model, glm::vec3(4.3f, 5.0f, 0.8f));

		shader.setMat4("model", model);
		roofWallmesh.Draw(shader);
		az += 10.4f;



	}
	float frontz = 0.0f;
	for (int i = 0; i < 2; i++) {

		glm::mat4 squared = glm::mat4(1.0f);
		squared = squared * transform;
		squared = squared * scaleMat;
		squared = glm::translate(squared, glm::vec3(28.4f, 4.7f, 5.2f - frontz));
		squared = glm::rotate(squared, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		squared = glm::rotate(squared, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		squared = glm::scale(squared, glm::vec3(0.5f, 10.0f, 1.0f));
		shader.setMat4("model", squared);
		squaremesh.Draw(shader);
		frontz += 10.4;
	}
}


