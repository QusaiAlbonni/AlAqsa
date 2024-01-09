#include "mosque.h"
#include"utils.h"
#include "lighting.h"

mosque::mosque(Shader shader) :object_(shader){

	init();
	}

void mosque::init() {




    shapeUtils::generateRectangle(40.0f, 15.0f, rectanglecylinder.sVertices, rectanglecylinder.indices);
    texture rectanglecylinderDiffuse("res/textures/mosque/41.png", "material.diffuse", GL_NONE, GL_SRGB_ALPHA);
    //texture rectanglecylinderSpecular("res/textures/mosque/pavement_03_4k/gh.png", "material.specular");
    //texture rectanglecylinderAmbient("res/textures/mosque/pavement_03_4k/ao.png", "material.ambient");
    //texture rectanglecylinderNormal("res/textures/mosque/pavement_03_4k/no.png", "material.normal");
    vector<sTexture> frectanglecylinderTexture = {
       rectanglecylinderDiffuse.info,
       /* rectanglecylinderSpecular.info,
        rectanglecylinderAmbient.info,
        rectanglecylinderNormal.info,*/

    };
    rectanglecylindermesh = Simplemesh(rectanglecylinder.sVertices, rectanglecylinder.indices, frectanglecylinderTexture);





    shapeUtils::generateRectangle(76.0f, 15.0f, rectangleright.sVertices, rectangleright.indices);
    texture rectanglerightDiffuse("res/textures/mosque/right/right.png", "material.diffuse", GL_NONE, GL_SRGB_ALPHA);
    texture rectanglerightSpecular("res/textures/mosque/right/right_Specular.png", "material.specular");
    texture rectanglerightAmbient("res/textures/mosque/right/right_AmbientOcclusion.png", "material.ambient");
    texture rectanglerightNormal("res/textures/mosque/right/right_Normal.png", "material.normal");
    texture rectanglerightHeight("res/textures/mosque/right/right_Height.png", "material.height");
    vector<sTexture> rectanglerightTexture = {
       rectanglerightDiffuse.info,
        rectanglerightSpecular.info,
        rectanglerightAmbient.info,
        rectanglerightNormal.info,
        rectanglerightHeight.info
    };
    rectanglerightmesh = Simplemesh(rectangleright.sVertices, rectangleright.indices, rectanglerightTexture);


    shapeUtils::generateRectangle(54.0f, 11.0f, rectangleup.sVertices, rectangleup.indices);
    texture rectangleupDiffuse("res/textures/mosque/UP/UP.png", "material.diffuse", GL_NONE, GL_SRGB_ALPHA);
    texture rectangleupSpecular("res/textures/mosque/UP/UP_Specular.png", "material.specular");
    texture rectangleupAmbient("res/textures/mosque/UP/UP_AmbientOcclusion.png", "material.ambient");
    texture rectangleupNormal("res/textures/mosque/UP/UP_Normal.png", "material.normal");
    texture rectangleupHeight("res/textures/mosque/UP/UP_Height.png", "material.height");
    vector<sTexture> rectangleupTexture = {
       rectangleupDiffuse.info,
        rectangleupSpecular.info,
        rectangleupAmbient.info,
        rectangleupNormal.info,
        rectangleupHeight.info
    };
    rectangleupmesh = Simplemesh(rectangleup.sVertices, rectangleup.indices, rectangleupTexture);

    shapeUtils::generateCylinder(7.0f, 5.0f, 100, 50, cylinder.sVertices, cylinder.indices);

    cylindermesh = Simplemesh(cylinder.sVertices, cylinder.indices, rectangleupTexture);


    shapeUtils::generateRectangle(40.0f, 20.0f, rectanglefrontside.sVertices, rectanglefrontside.indices);
    texture rectanglefrontsideDiffuse("res/textures/mosque/front/front0.png", "material.diffuse", GL_NONE, GL_SRGB_ALPHA);
    texture rectanglefrontsideSpecular("res/textures/mosque/front/front_Specular.png", "material.specular");
    texture rectanglefrontsideAmbient("res/textures/mosque/front/front_AmbientOcclusion.png", "material.ambient");
    texture rectanglefrontsideNormal("res/textures/mosque/front/front_Normal.png", "material.normal");
    texture rectanglefrontsideHeight("res/textures/mosque/front/front_Height.png", "material.height");

    vector<sTexture> rectanglefrontsideTexure = {
        rectanglefrontsideDiffuse.info,
        rectanglefrontsideSpecular.info,
        rectanglefrontsideAmbient.info,
        rectanglefrontsideNormal.info,
        rectanglefrontsideHeight.info
    };

    rectanglefrontsidemesh = Simplemesh(rectanglefrontside.sVertices, rectanglefrontside.indices, rectanglefrontsideTexure);


    shapeUtils::generateRectangle(76.0f, 20.0f, rectangleleft.sVertices, rectangleleft.indices);
    texture rectangleleftDiffuse("res/textures/mosque/left/left.png", "material.diffuse", GL_NONE, GL_SRGB_ALPHA);
    texture rectangleleftSpecular("res/textures/mosque/left/left_Specular.png", "material.specular");
    texture rectangleleftAmbient("res/textures/mosque/left/left_AmbientOcclusion.png", "material.ambient");
    texture rectangleleftNormal("res/textures/mosque/left/left_Normal.png", "material.normal");
    texture rectangleleftHeight("res/textures/mosque/left/left_Height.png", "material.height");

    vector<sTexture> rectangleleftTexure = {
        rectangleleftDiffuse.info,
        rectangleleftSpecular.info,
        rectangleleftAmbient.info,
        rectangleleftNormal.info,
        rectangleleftHeight.info
    };
    rectangleleftmesh = Simplemesh(rectangleleft.sVertices, rectangleleft.indices, rectangleleftTexure);


    shapeUtils::generateRectangle(76.0f, 12.0f, rectanglesideside.sVertices, rectanglesideside.indices);

    texture rectanglesidesideDiffuse("res/textures/mosque/sideside1/sideside.png", "material.diffuse", GL_NONE, GL_SRGB_ALPHA);
    texture rectanglesidesideSpecular("res/textures/mosque/sideside1/sideside1_Specular.png", "material.specular");
    texture rectanglesidesideAmbient("res/textures/mosque/sideside1/sideside1_AmbientOcclusion.png", "material.ambient");
    texture rectanglesidesideNormal("res/textures/mosque/sideside1/sideside1_Normal.png", "material.normal");
    texture rectanglesidesideHeight("res/textures/mosque/sideside1/sideside1_Height.png", "material.height");

    vector<sTexture> rectanglesidesideTexure = {
        rectanglesidesideDiffuse.info,
        rectanglesidesideSpecular.info,
        rectanglesidesideAmbient.info,
        rectanglesidesideNormal.info,
        rectanglesidesideHeight.info
    };

    rectanglesidesidemesh = Simplemesh(rectanglesideside.sVertices, rectanglesideside.indices, rectanglesidesideTexure);

    shapeUtils::generateRectangle(40.0f, 20.0f, rectangleback.sVertices, rectangleback.indices);
    texture rectanglebackDiffuse("res/textures/mosque/back/dif.png", "material.diffuse", GL_NONE, GL_SRGB_ALPHA);
    texture rectanglebackSpecular("res/textures/mosque/back/ro.png", "material.specular");
    texture rectanglebackAmbient("res/textures/mosque/back/ao.png", "material.ambient");
    texture rectanglebackNormal("res/textures/mosque/back/no.png", "material.normal");


    vector<sTexture> rectanglebackTextures = {
        rectanglebackDiffuse.info,
         rectanglebackSpecular.info,
         rectanglebackAmbient.info,
         rectanglebackNormal.info,
    };

    rectanglebackmesh = Simplemesh(rectangleback.sVertices, rectangleback.indices, rectanglebackTextures);


    shapeUtils::generateRectangle(40.0f, 20.0f, rectanglebackside.sVertices, rectanglebackside.indices);

    rectanglebacksidemesh = Simplemesh(rectanglebackside.sVertices, rectanglebackside.indices, rectanglebackTextures);

    shapeUtils::generateRectangle(74.0f, 20.0f, rectangleleftside.sVertices, rectangleleftside.indices);

    rectangleleftsidemesh = Simplemesh(rectangleleftside.sVertices, rectangleleftside.indices, rectanglebackTextures);


    shapeUtils::generateRectangle(11.0, 24.66666f, rectangleroof.sVertices, rectangleroof.indices);//10  //20
    texture Text2("res/textures/mosque/RoofingTiles013A_1K-PNG_Color.png", "material.diffuse", GL_NONE, GL_SRGB_ALPHA);
    texture Text3("res/textures/mosque/RoofingTiles013A_1K-PNG_Roughness.png", "material.specular");
    texture Text4("res/textures/mosque/RoofingTiles013A_1K-PNG_NormalGL.png", "material.normal");
    texture Text5("res/textures/mosque/RoofingTiles013A_1K-PNG_AmbientOcclusion.png", "material.ambient");
    texture Text6("res/textures/mosque/RoofingTiles013A_1K-PNG_Displacement.png", "material.height");

    vector<sTexture> Textures = {
     Text2.info,
      Text3.info,
       Text4.info,
       Text5.info,
       Text6.info
    };

    rectangleroofmesh = Simplemesh(rectangleroof.sVertices, rectangleroof.indices, Textures);


    shapeUtils::generateSphere(dome.sVertices, dome.indices, true);
    domeMesh = Simplemesh(dome.sVertices, dome.indices, Textures);


    shapeUtils::generateRectangle(24.0f, 15.0f, rectanglefront.sVertices, rectanglefront.indices);//10  //12
    texture rectanglefrontDIF("res/textures/mosque/pavement_03_4k/pavement_03_diff_4k.png", "material.diffuse", GL_NONE, GL_SRGB_ALPHA);
    texture rectanglefrontSP("res/textures/mosque/pavement_03_4k/pavement_03_rough_4k.png", "material.specular");
    texture rectanglefrontMO("res/textures/mosque/pavement_03_4k/pavement_03_ao_4k.png", "material.ambient");
    texture rectanglefrontNO("res/textures/mosque/pavement_03_4k/pavement_03_nor_gl_4k.png", "material.normal");


    vector<sTexture> rectanglefronttEXTURE = {
        rectanglefrontDIF.info,
        rectanglefrontSP.info,
        rectanglefrontMO.info,
        rectanglefrontNO.info,
    };
    rectanglefrontmesh = Simplemesh(rectanglefront.sVertices, rectanglefront.indices, rectanglefronttEXTURE);


    shapeUtils::generateRectangle(54.0f, 12.0f, rectangleupside.sVertices, rectangleupside.indices);

    rectangleupsidemesh = Simplemesh(rectangleupside.sVertices, rectangleupside.indices, rectanglefronttEXTURE);


    shapeUtils::generateRectangle1(24.0f, 15.0f, rectanglefront2.sVertices, rectanglefront2.indices);//2  //11
    rectanglefrontmesh2 = Simplemesh(rectanglefront2.sVertices, rectanglefront2.indices, rectanglefronttEXTURE);


    shapeUtils::generateCylinder(0.3f, 2.3f, 400, 100, halfcylinder.sVertices, halfcylinder.indices, true);
    halfcylindermesh = Simplemesh(halfcylinder.sVertices, halfcylinder.indices, rectanglefronttEXTURE);









    shapeUtils::generateRectangle2(24.0f, 15.0f, rectangle.sVertices, rectangle.indices);//10  //12
    rectanglemesh = Simplemesh(rectangle.sVertices, rectangle.indices, rectanglefronttEXTURE);






    shapeUtils::generateRectangle(2.0f, 4.0f, carpat.sVertices, carpat.indices);//10  //12
    texture rectanglecarpatDIF("res/textures/mosque/carpat/ca.png", "material.diffuse", GL_NONE, GL_SRGB_ALPHA);
    texture carpatSpecular("res/textures/mosque/carpat/carpat_Specular.png", "material.specular");
    texture carpatAmbient("res/textures/mosque/carpat/carpat_AmbientOcclusion.png", "material.ambient");
    texture carpatNormal("res/textures/mosque/carpat/carpat_Normal.png", "material.normal");
    texture carpatHeight("res/textures/mosque/carpat/carpat_Height.png", "material.height");
    vector<sTexture>carpatEXTURE = {
        rectanglecarpatDIF.info,
        carpatSpecular.info,
        carpatAmbient.info,
        carpatNormal.info,
        carpatHeight.info
    };
    carpatMesh = Simplemesh(carpat.sVertices, carpat.indices, carpatEXTURE);


    shapeUtils::generateRectangle2(2.0f, 2.0f, carpat1.sVertices, carpat1.indices);
    carpatMesh1 = Simplemesh(carpat1.sVertices, carpat1.indices, carpatEXTURE);




    shapeUtils::generateRectangle(2.0f, 8.0f, door.sVertices, door.indices);
    texture doorDIF("res/textures/mosque/door1.png", "material.diffuse", GL_NONE, GL_SRGB_ALPHA);
    vector<sTexture>doorEXTURE = {
    doorDIF.info,
    };
    doorMesh = Simplemesh(door.sVertices, door.indices, doorEXTURE);

    tringle = shape(
        {
                -7.0f,  25.0f, -0.0f,     0.0f, 0.0f, 0.0f,	0.0f, 0.0f,
                0.0f,  30.0f, -0.0f,    0.0f, 0.0f, 0.0f,	    0.5f, 1.0f,
                 7.0f,  25.0f, 0.0f,     0.0f, 0.0f, 0.0f,	    1.0f, 0.0f,
        },
    {
      0, 1, 2,
    }

    );



    tringle.sVertices = convertToVertexglmVector(tringle.vertices);

    tringleMesh = Simplemesh(tringle.sVertices, tringle.indices, rectanglefronttEXTURE);










    texture RoofDIF("res/textures/mosque/roofside.png", "material.diffuse", GL_NONE, GL_SRGB_ALPHA);
    vector<sTexture>roofEXTURE = {
    RoofDIF.info,
        rectanglefrontSP.info,
        rectanglefrontMO.info,
        rectanglefrontNO.info,
    };

    rectangleroofsidemesh = Simplemesh(rectangleroof.sVertices, rectangleroof.indices, roofEXTURE);
}
void mosque::Draw() {
    addPointLight(shader, mosquePointlightPos);
    glm::mat4 transform(1);
    transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 147.0f));
    transform = glm::scale(transform, glm::vec3(0.75f, 1.0f, 0.75f));
    transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    drawMeshes(transform);
}
void mosque::DrawDepth(Shader depthShader, bool ortho) {
    Shader temp = shader;
    shader = depthShader;
    glm::mat4 transform(1);
    transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 148.0f));
    transform = glm::scale(transform, glm::vec3(0.75f, 1.0f, 0.75f));
    transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    drawMeshes(transform);
    shader = temp;
}
//11 //24.6666
void mosque::drawMeshes(glm::mat4 transform, glm::mat4 scalemat) {
    shader.use();


    {
        glm::mat4 door1, door2, doorside, door1side;
        if (l == false) {
            door1 = glm::mat4(1.0f) * transform;

            door1 = glm::translate(door1, glm::vec3(50.0f, 3.5f, 53.0f));
            door1 = glm::rotate(door1, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            door1 = glm::scale(door1, glm::vec3(3.3f, 1.0f, 1.0f));
            shader.setMat4("model", door1);
            doorMesh.Draw(shader);


            door2 = glm::mat4(1.0f) * transform;

            door2 = glm::translate(door2, glm::vec3(50.0f, 3.5f, 59.6));
            door2 = glm::rotate(door2, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            door2 = glm::scale(door2, glm::vec3(3.3f, 1.0f, 1.0f));
            shader.setMat4("model", door2);
            doorMesh.Draw(shader);

        }
        else {
            door1 = glm::mat4(1.0f) * transform;

            door1 = glm::translate(door1, glm::vec3(53.3f, 3.5f, 49.7f));
            door1 = glm::rotate(door1, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            door1 = glm::scale(door1, glm::vec3(3.3f, 1.0f, 1.0f));
            shader.setMat4("model", door1);
            doorMesh.Draw(shader);


            door2 = glm::mat4(1.0f) * transform;

            door2 = glm::translate(door2, glm::vec3(53.3f, 3.5f, 62.9f));
            // door2 = glm::rotate(door2, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            door2 = glm::scale(door2, glm::vec3(3.3f, 1.0f, 1.0f));
            shader.setMat4("model", door2);
            doorMesh.Draw(shader);
        }
    }




    {
        float x = 0.0f, y = 0.0f;
        for (int i = 0; i < 5; i++) {
            x = 0.0f;
            for (int j = 0; j < 25; j++) {

                glm::mat4 carpat = glm::mat4(1.0f) * transform;

                carpat = glm::translate(carpat, glm::vec3(21.0f + x, 0.4f, 3.0f + y));
                carpat = glm::rotate(carpat, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                carpat = glm::rotate(carpat, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                carpat = glm::rotate(carpat, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                shader.setMat4("model", carpat);
                carpatMesh.Draw(shader);

                x += 2;
            }

            y += 4;
        }
    }




    {
        float x = 0.0f, y = 0.0f;
        for (int i = 0; i < 19; i++) {
            x = 0.0f;
            if (i == 18) {
                for (int j = 0; j < 10; j++) {
                    glm::mat4 carpat = glm::mat4(1.0f) * transform;

                    carpat = glm::translate(carpat, glm::vec3(51.0f + x, 0.4f, 22.0f + y));
                    carpat = glm::rotate(carpat, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                    carpat = glm::rotate(carpat, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                    carpat = glm::rotate(carpat, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                    shader.setMat4("model", carpat);
                    carpatMesh1.Draw(shader);
                    x += 2;
                }
                continue;
            }
            for (int j = 0; j < 10; j++) {

                glm::mat4 carpat = glm::mat4(1.0f) * transform;

                carpat = glm::translate(carpat, glm::vec3(51.0f + x, 0.4f, 23.0f + y));
                carpat = glm::rotate(carpat, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                carpat = glm::rotate(carpat, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                carpat = glm::rotate(carpat, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                shader.setMat4("model", carpat);
                carpatMesh.Draw(shader);

                x += 2;
            }

            y += 4;
        }
    }






    {
        float x = 0.0f, y = 0.0f;
        for (int i = 0; i < 19; i++) {
            x = 0.0f;
            if (i == 18) {
                for (int j = 0; j < 19; j++) {
                    glm::mat4 carpat = glm::mat4(1.0f) * transform;

                    carpat = glm::translate(carpat, glm::vec3(-18.0f + x, 0.4f, 74.0f - y));
                    carpat = glm::rotate(carpat, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                    carpat = glm::rotate(carpat, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                    carpat = glm::rotate(carpat, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                    shader.setMat4("model", carpat);
                    carpatMesh1.Draw(shader);
                    x += 2;
                }
                continue;
            }
            for (int j = 0; j < 19; j++) {

                glm::mat4 carpat = glm::mat4(1.0f) * transform;

                carpat = glm::translate(carpat, glm::vec3(-18.0f + x, 0.4f, 73.0f - y));
                carpat = glm::rotate(carpat, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                carpat = glm::rotate(carpat, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                carpat = glm::rotate(carpat, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                shader.setMat4("model", carpat);
                carpatMesh.Draw(shader);

                x += 2;
            }

            y += 4;
        }
    }

    {

        glm::mat4 door1, door2, doorside, door1side;
        if (t == false) {
            door1 = glm::mat4(1.0f) * transform;

            door1 = glm::translate(door1, glm::vec3(-1.05f, 4.0f, 76.0f));

            shader.setMat4("model", door1);
            doorMesh.Draw(shader);


            door2 = glm::mat4(1.0f) * transform;

            door2 = glm::translate(door2, glm::vec3(0.95f, 4.0f, 76.0f));

            shader.setMat4("model", door2);
            doorMesh.Draw(shader);


            doorside = glm::mat4(1.0f) * transform;

            doorside = glm::translate(doorside, glm::vec3(-1.05f, 4.0f, 75.0f));
            doorside = glm::rotate(doorside, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            shader.setMat4("model", doorside);
            doorMesh.Draw(shader);


            door1side = glm::mat4(1.0f) * transform;

            door1side = glm::translate(door1side, glm::vec3(0.95f, 4.0f, 75.0f));
            door1side = glm::rotate(door1side, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            shader.setMat4("model", door1side);
            doorMesh.Draw(shader);
        }
        else {
            door1 = glm::mat4(1.0f) * transform;

            door1 = glm::translate(door1, glm::vec3(-1.6f, 4.0f, 73.0f));
            door1 = glm::rotate(door1, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            door1 = glm::scale(door1, glm::vec3(3.0f, 1.0f, 1.0f));
            shader.setMat4("model", door1);
            doorMesh.Draw(shader);


            door2 = glm::mat4(1.0f) * transform;

            door2 = glm::translate(door2, glm::vec3(1.5f, 4.0f, 73.0f));
            door2 = glm::rotate(door2, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            door2 = glm::scale(door2, glm::vec3(3.0f, 1.0f, 1.0f));
            shader.setMat4("model", door2);
            doorMesh.Draw(shader);


            doorside = glm::mat4(1.0f) * transform;

            doorside = glm::translate(doorside, glm::vec3(-2.0f, 4.0f, 73.0f));
            doorside = glm::rotate(doorside, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            doorside = glm::scale(doorside, glm::vec3(3.0f, 1.0f, 1.0f));
            shader.setMat4("model", doorside);
            doorMesh.Draw(shader);


            door1side = glm::mat4(1.0f) * transform;

            door1side = glm::translate(door1side, glm::vec3(1.9f, 4.0f, 73.0f));
            door1side = glm::rotate(door1side, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            door1side = glm::scale(door1side, glm::vec3(3.0f, 1.0f, 1.0f));
            shader.setMat4("model", door1side);
            doorMesh.Draw(shader);


            glm::mat4 model = glm::mat4(1.0f) * transform;

            model = glm::translate(model, glm::vec3(1.75f, 4.0f, 70.0f));
            model = glm::rotate(model, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::scale(model, glm::vec3(0.03636363636363636363636363636364, 0.32432441197957080528940683497482f, 1.0f));
            shader.setMat4("model", model);
            rectangleroofmesh.Draw(shader);



            glm::mat4 model1 = glm::mat4(1.0f) * transform;

            model1 = glm::translate(model1, glm::vec3(1.75f, 4.0f, 76.0f));
            model1 = glm::rotate(model1, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            model1 = glm::scale(model1, glm::vec3(0.03636363636363636363636363636364, 0.32432441197957080528940683497482f, 1.0f));
            shader.setMat4("model", model1);
            rectangleroofmesh.Draw(shader);

            glm::mat4 model0 = glm::mat4(1.0f) * transform;

            model0 = glm::translate(model0, glm::vec3(-1.8f, 4.0f, 70.0f));
            model0 = glm::rotate(model0, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            model0 = glm::scale(model0, glm::vec3(0.03636363636363636363636363636364, 0.32432441197957080528940683497482f, 1.0f));
            shader.setMat4("model", model0);
            rectangleroofmesh.Draw(shader);



            glm::mat4 model10 = glm::mat4(1.0f) * transform;

            model10 = glm::translate(model10, glm::vec3(-1.8f, 4.0f, 76.0f));
            model10 = glm::rotate(model10, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            model10 = glm::scale(model10, glm::vec3(0.03636363636363636363636363636364, 0.32432441197957080528940683497482f, 1.0f));
            shader.setMat4("model", model10);
            rectangleroofmesh.Draw(shader);

            t = false;
        }





    }


    {

        glm::mat4 door1, door2, doorside, door1side;
        if (l == false) {
            door1 = glm::mat4(1.0f) * transform;

            door1 = glm::translate(door1, glm::vec3(19.0f, 2.55f, 7.95f));
            door1 = glm::rotate(door1, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            door1 = glm::scale(door1, glm::vec3(2.1f, 0.8f, 1.0f));
            shader.setMat4("model", door1);
            doorMesh.Draw(shader);


            door2 = glm::mat4(1.0f) * transform;

            door2 = glm::translate(door2, glm::vec3(19.0f, 2.55f, 12.15f));
            door2 = glm::rotate(door2, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            door2 = glm::scale(door2, glm::vec3(2.1f, 0.8f, 1.0f));
            shader.setMat4("model", door2);
            doorMesh.Draw(shader);


            doorside = glm::mat4(1.0f) * transform;

            doorside = glm::translate(doorside, glm::vec3(20.0f, 2.55f, 7.95f));
            doorside = glm::rotate(doorside, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            doorside = glm::scale(doorside, glm::vec3(2.1f, 0.8f, 1.0f));
            shader.setMat4("model", doorside);
            doorMesh.Draw(shader);


            door1side = glm::mat4(1.0f) * transform;

            door1side = glm::translate(door1side, glm::vec3(20.0f, 2.55f, 12.15f));
            door1side = glm::rotate(door1side, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            door1side = glm::scale(door1side, glm::vec3(2.1f, 0.8f, 1.0f));
            shader.setMat4("model", door1side);
            doorMesh.Draw(shader);
        }
        else {
            door1 = glm::mat4(1.0f) * transform;

            door1 = glm::translate(door1, glm::vec3(22.0f, 2.55f, 5.9f));
            door1 = glm::rotate(door1, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            door1 = glm::scale(door1, glm::vec3(3.0f, 0.8f, 1.0f));
            shader.setMat4("model", door1);
            doorMesh.Draw(shader);


            door2 = glm::mat4(1.0f) * transform;

            door2 = glm::translate(door2, glm::vec3(22.0f, 2.55f, 13.75));
            //door2 = glm::rotate(door2, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            door2 = glm::scale(door2, glm::vec3(3.0f, 0.8f, 1.0f));
            shader.setMat4("model", door2);
            doorMesh.Draw(shader);


            doorside = glm::mat4(1.0f) * transform;

            doorside = glm::translate(doorside, glm::vec3(22.0f, 2.55f, 6.3f));
            doorside = glm::rotate(doorside, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            doorside = glm::scale(doorside, glm::vec3(3.0f, 0.8f, 1.0f));
            shader.setMat4("model", doorside);
            doorMesh.Draw(shader);


            door1side = glm::mat4(1.0f) * transform;

            door1side = glm::translate(door1side, glm::vec3(22.0f, 2.55f, 14.15f));
            //door1side = glm::rotate(door1side, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            door1side = glm::scale(door1side, glm::vec3(3.0f, 0.8f, 1.0f));
            shader.setMat4("model", door1side);
            doorMesh.Draw(shader);


            glm::mat4 model = glm::mat4(1.0f) * transform;

            model = glm::translate(model, glm::vec3(19.0f, 2.6f, 6.1f));
            model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::scale(model, glm::vec3(0.03636363636363636363636363636364, 0.25945952958365664423152546797986f, 1.0f));
            shader.setMat4("model", model);
            rectangleroofmesh.Draw(shader);



            glm::mat4 model1 = glm::mat4(1.0f) * transform;

            model1 = glm::translate(model1, glm::vec3(25.0f, 2.6f, 6.1f));
            model1 = glm::rotate(model1, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            model1 = glm::scale(model1, glm::vec3(0.03636363636363636363636363636364, 0.25945952958365664423152546797986f, 1.0f));
            shader.setMat4("model", model1);
            rectangleroofmesh.Draw(shader);

            glm::mat4 model0 = glm::mat4(1.0f) * transform;

            model0 = glm::translate(model0, glm::vec3(19.0f, 2.6f, 13.95f));
            model0 = glm::rotate(model0, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            model0 = glm::scale(model0, glm::vec3(0.03636363636363636363636363636364, 0.25945952958365664423152546797986f, 1.0f));
            shader.setMat4("model", model0);
            rectangleroofmesh.Draw(shader);



            glm::mat4 model10 = glm::mat4(1.0f) * transform;

            model10 = glm::translate(model10, glm::vec3(25.0f, 2.6f, 13.95));
            model10 = glm::rotate(model10, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            model10 = glm::scale(model10, glm::vec3(0.03636363636363636363636363636364, 0.25945952958365664423152546797986f, 1.0f));
            shader.setMat4("model", model10);
            rectangleroofmesh.Draw(shader);

            l = false;
        }





    }
    //11  //24.66666
    {
        glm::mat4 model = glm::mat4(1.0f) * transform;

        model = glm::translate(model, glm::vec3(45.0f, 12.0f, 0.5f));
        model = glm::rotate(model, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));

        model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(4.5454545454545454545454545454545f, 0.04054055149744635066117585437185f, 1.0f));
        shader.setMat4("model", model);
        rectangleroofmesh.Draw(shader);



        glm::mat4 model1 = glm::mat4(1.0f) * transform;

        model1 = glm::translate(model1, glm::vec3(35.0f, 12.0f, 20.5f));
        model1 = glm::rotate(model1, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));

        model1 = glm::rotate(model1, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        model1 = glm::scale(model1, glm::vec3(2.7272727272727272727272727272727f, 0.04054055149744635066117585437185f, 1.0f));
        shader.setMat4("model", model1);
        rectangleroofmesh.Draw(shader);

        glm::mat4 model2 = glm::mat4(1.0f) * transform;

        model2 = glm::translate(model2, glm::vec3(69.5f, 12.0f, 48.5f));
        model2 = glm::rotate(model2, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model2 = glm::rotate(model2, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model2 = glm::rotate(model2, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        model2 = glm::scale(model2, glm::vec3(8.6363636363636363636363636363636f, 0.04054055149744635066117585437185f, 1.0f));
        shader.setMat4("model", model2);
        rectangleroofmesh.Draw(shader);
    }


    {
        glm::mat4 model = glm::mat4(1.0f) * transform;

        model = glm::translate(model, glm::vec3(20.0f, 17.5f, 0.5f));
        model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(0.09090909090909090909090909090909f, 0.20270275748723175330587927185926f, 1.0f));
        shader.setMat4("model", model);
        rectangleroofmesh.Draw(shader);


        glm::mat4 model1 = glm::mat4(1.0f) * transform;

        model1 = glm::translate(model1, glm::vec3(20.0f, 17.5f, 75.5f));
        model1 = glm::rotate(model1, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model1 = glm::scale(model1, glm::vec3(0.09090909090909090909090909090909f, 0.20270275748723175330587927185926f, 1.0f));
        shader.setMat4("model", model1);
        rectangleroofmesh.Draw(shader);



        glm::mat4 model2 = glm::mat4(1.0f) * transform;

        model2 = glm::translate(model2, glm::vec3(7.5f, 20.0f, 13.0f));
        model2 = glm::rotate(model2, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model2 = glm::rotate(model2, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        model2 = glm::scale(model2, glm::vec3(2.1818181818181818181818181818182f, 0.04054055149744635066117585437185f, 1.0f));
        shader.setMat4("model", model2);
        rectangleroofmesh.Draw(shader);
    }

    {
        glm::mat4 model = glm::mat4(1.0f) * transform;

        model = glm::translate(model, glm::vec3(0.0f, 20.0f, 0.5f));
        model = glm::rotate(model, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));

        model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(3.6363636363636363636363636363636f, 0.04054055149744635066117585437185f, 1.0f));
        shader.setMat4("model", model);
        rectangleroofmesh.Draw(shader);


        glm::mat4 model1 = glm::mat4(1.0f) * transform;

        model1 = glm::translate(model1, glm::vec3(0.0f, 20.0f, 75.5f));
        model1 = glm::rotate(model1, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));

        model1 = glm::rotate(model1, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        model1 = glm::scale(model1, glm::vec3(3.6363636363636363636363636363636f, 0.04054055149744635066117585437185f, 1.0f));
        shader.setMat4("model", model1);
        rectangleroofmesh.Draw(shader);
    }



    {

        glm::mat4 model = glm::mat4(1.0f) * transform;

        model = glm::translate(model, glm::vec3(19.5f, 15.0f, 38.0f));
        model = glm::rotate(model, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(6.7272727272727272727272727272727f, 0.04054055149744635066117585437185f, 1.0f));
        shader.setMat4("model", model);
        rectangleroofmesh.Draw(shader);

        glm::mat4 model1 = glm::mat4(1.0f) * transform;

        model1 = glm::translate(model1, glm::vec3(-19.5f, 20.0f, 38.0f));
        model1 = glm::rotate(model1, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model1 = glm::rotate(model1, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model1 = glm::rotate(model1, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        model1 = glm::scale(model1, glm::vec3(6.7272727272727272727272727272727f, 0.04054055149744635066117585437185f, 1.0f));
        shader.setMat4("model", model1);
        rectangleroofmesh.Draw(shader);


        glm::mat4 model2 = glm::mat4(1.0f) * transform;

        model2 = glm::translate(model2, glm::vec3(19.5f, 15.0f, 88.0f));
        model2 = glm::rotate(model2, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model2 = glm::rotate(model2, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model2 = glm::rotate(model2, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        model2 = glm::scale(model2, glm::vec3(2.181818f, 0.04054055149744635066117585437185f, 1.0f));
        shader.setMat4("model", model2);
        rectangleroofmesh.Draw(shader);

        glm::mat4 model3 = glm::mat4(1.0f) * transform;

        model3 = glm::translate(model3, glm::vec3(-19.5f, 15.0f, 88.0f));
        model3 = glm::rotate(model3, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model3 = glm::rotate(model3, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model3 = glm::rotate(model3, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        model3 = glm::scale(model3, glm::vec3(2.181818f, 0.04054055149744635066117585437185f, 1.0f));
        shader.setMat4("model", model3);
        rectangleroofmesh.Draw(shader);


        glm::mat4 side = glm::mat4(1.0f) * transform;

        side = glm::translate(side, glm::vec3(50.0f, 6.0f, 58.0f));
        side = glm::rotate(side, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        side = glm::rotate(side, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.setMat4("model", side);
        rectanglesidesidemesh.Draw(shader);
    }




    int dotx = 0, dotz = 0, dot = 0, l = 0;
    for (size_t i = 0; i < 5; i++)
    {
        if (i == 0 || i == 1) {

            glm::mat4 front = glm::mat4(1.0f) * transform;
            front = glm::translate(front, glm::vec3(55.0f + dot, 6.0f, 96.0f));
            front = glm::scale(front, glm::vec3(0.41666666f, 0.8f, 1.0f));
            front = glm::rotate(front, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            shader.setMat4("model", front);
            rectanglefrontmesh.Draw(shader);


            glm::mat4 front1 = glm::mat4(1.0f) * transform;
            front1 = glm::translate(front1, glm::vec3(55.0f + dot, 6.0f, 95.0f));
            front1 = glm::scale(front1, glm::vec3(0.41666666f, 0.8f, 1.0f));
            front1 = glm::rotate(front1, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            shader.setMat4("model", front1);
            rectanglefrontmesh.Draw(shader);
            dot += 10;
        }
        if (i == 3 || i == 4) {

            glm::mat4 back = glm::mat4(1.0f) * transform;
            back = glm::translate(back, glm::vec3(25.0f + dotx, 6.0f, 0.0f));
            back = glm::scale(back, glm::vec3(0.41666666f, 0.8f, 1.0f));
            shader.setMat4("model", back);
            rectanglefrontmesh.Draw(shader);


            glm::mat4 back1 = glm::mat4(1.0f) * transform;
            back1 = glm::translate(back1, glm::vec3(25.0f + dotx, 6.0f, 1.0f));
            back1 = glm::scale(back1, glm::vec3(0.41666666f, 0.8f, 1.0f));
            shader.setMat4("model", back1);
            rectanglefrontmesh.Draw(shader);

            glm::mat4 roof = glm::mat4(1.0f) * transform;
            roof = glm::translate(roof, glm::vec3(25.0f + dotx, 10.0f, 10.0f));
            roof = glm::rotate(roof, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            roof = glm::rotate(roof, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            roof = glm::scale(roof, glm::vec3(0.90909090909090909090909090909091f, 0.81081102994892701322351708743705f, 1.0f));
            shader.setMat4("model", roof);
            rectangleroofmesh.Draw(shader);

            glm::mat4 roofside = glm::mat4(1.0f) * transform;
            roofside = glm::translate(roofside, glm::vec3(25.0f + dotx, 9.0f, 10.0f));
            roofside = glm::rotate(roofside, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            roofside = glm::rotate(roofside, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            roofside = glm::scale(roofside, glm::vec3(0.90909090909090909090909090909091f, 0.81081102994892701322351708743705f, 1.0f));
            shader.setMat4("model", roofside);
            rectangleroofsidemesh.Draw(shader);

            if (i == 3) {
                glm::mat4 sideright = glm::mat4(1.0f) * transform;
                sideright = glm::translate(sideright, glm::vec3(70.0f, 6.0f, 12.0f + dotz));
                sideright = glm::scale(sideright, glm::vec3(0.41666666f, 0.8f, 1.0f));
                sideright = glm::rotate(sideright, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                shader.setMat4("model", sideright);
                rectanglefrontmesh.Draw(shader);


                glm::mat4 sideright1 = glm::mat4(1.0f) * transform;
                sideright1 = glm::translate(sideright1, glm::vec3(69.0f, 6.0f, 12.0f + dotz));
                sideright1 = glm::scale(sideright1, glm::vec3(0.41666666f, 0.8f, 1.0f));
                sideright1 = glm::rotate(sideright1, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                shader.setMat4("model", sideright1);
                rectanglefrontmesh.Draw(shader);

                glm::mat4 roofy = glm::mat4(1.0f) * transform;
                roofy = glm::translate(roofy, glm::vec3(55.0f, 10.0f, 29.0f + l));
                roofy = glm::rotate(roofy, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                roofy = glm::rotate(roofy, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                roofy = glm::scale(roofy, glm::vec3(0.90909090909090909090909090909091f, 0.72973170197757291235922259249349f, 1.0f));
                shader.setMat4("model", roofy);
                rectangleroofmesh.Draw(shader);

                glm::mat4 roofyside = glm::mat4(1.0f) * transform;
                roofyside = glm::translate(roofyside, glm::vec3(55.0f, 9.0f, 29.0f + l));
                roofyside = glm::rotate(roofyside, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                roofyside = glm::rotate(roofyside, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                roofyside = glm::scale(roofyside, glm::vec3(0.90909090909090909090909090909091f, 0.72973170197757291235922259249349f, 1.0f));
                shader.setMat4("model", roofyside);
                rectangleroofsidemesh.Draw(shader);

                glm::mat4 roofy1 = glm::mat4(1.0f) * transform;
                roofy1 = glm::translate(roofy1, glm::vec3(65.0f, 10.0f, 29.0f + l));
                roofy1 = glm::rotate(roofy1, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                roofy1 = glm::rotate(roofy1, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                roofy1 = glm::scale(roofy1, glm::vec3(0.90909090909090909090909090909091f, 0.72973170197757291235922259249349f, 1.0f));
                shader.setMat4("model", roofy1);
                rectangleroofmesh.Draw(shader);

                glm::mat4 roofyside1 = glm::mat4(1.0f) * transform;
                roofyside1 = glm::translate(roofyside1, glm::vec3(65.0f, 9.0f, 29.0f + l));
                roofyside1 = glm::rotate(roofyside1, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                roofyside1 = glm::rotate(roofyside1, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                roofyside1 = glm::scale(roofyside1, glm::vec3(0.90909090909090909090909090909091f, 0.72973170197757291235922259249349f, 1.0f));
                shader.setMat4("model", roofyside1);
                rectangleroofsidemesh.Draw(shader);

            }

            dotx += 10;

            continue;
        }

        {
            glm::mat4 g = glm::mat4(1.0f) * transform;

            g = glm::translate(g, glm::vec3(47.0f, 21.0f, 16.5f));
            g = glm::rotate(g, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            g = glm::rotate(g, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            g = glm::scale(g, glm::vec3(0.2727272f, 0.12162165449233905198352756311556f, 1.0f));
            shader.setMat4("model", g);
            rectangleroofmesh.Draw(shader);


            glm::mat4 g1 = glm::mat4(1.0f) * transform;

            g1 = glm::translate(g1, glm::vec3(45.5f, 15.5f, 16.5f));
            g1 = glm::rotate(g1, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            g1 = glm::scale(g1, glm::vec3(0.125f, 0.73333333333333333333333333333333f, 1.0f));
            shader.setMat4("model", g1);
            rectanglefrontmesh2.Draw(shader);

            glm::mat4 g2 = glm::mat4(1.0f) * transform;


            g2 = glm::translate(g2, glm::vec3(48.5f, 15.5f, 16.5f));
            g2 = glm::rotate(g2, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            g2 = glm::scale(g2, glm::vec3(0.125f, 0.73333333333333333333333333333333f, 1.0f));
            shader.setMat4("model", g2);
            rectanglefrontmesh2.Draw(shader);



            glm::mat4 g3 = glm::mat4(1.0f) * transform;

            g3 = glm::translate(g3, glm::vec3(47.0f, 15.5f, 15.0f));
            g3 = glm::rotate(g3, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            g3 = glm::scale(g3, glm::vec3(0.125f, 0.73333333333333333333333333333333f, 1.0f));
            shader.setMat4("model", g3);
            rectanglefrontmesh2.Draw(shader);

            glm::mat4 g4 = glm::mat4(1.0f) * transform;

            g4 = glm::translate(g4, glm::vec3(47.0f, 15.5f, 18.0f));
            g4 = glm::rotate(g4, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            g4 = glm::scale(g4, glm::vec3(0.125f, 0.73333333333333333333333333333333f, 1.0f));
            shader.setMat4("model", g4);
            rectanglefrontmesh2.Draw(shader);
        }

        {

            glm::mat4 dome = glm::mat4(1.0f) * transform;
            dome = glm::translate(dome, glm::vec3(47.0f, 26.4f, 16.5f));
            dome = glm::scale(dome, glm::vec3(1.0f, 1.0f, 1.0f));
            shader.setMat4("model", dome);
            domeMesh.Draw(shader, GL_TRIANGLE_STRIP);


            glm::mat4 g = glm::mat4(1.0f) * transform;

            g = glm::translate(g, glm::vec3(47.0f, 26.5f, 16.5f));
            g = glm::rotate(g, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            g = glm::rotate(g, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            g = glm::scale(g, glm::vec3(0.18181818181818181818181818181818f, 0.08108110299489270132235170874371f, 1.0f));
            shader.setMat4("model", g);
            rectangleroofmesh.Draw(shader);


            glm::mat4 g1 = glm::mat4(1.0f) * transform;

            g1 = glm::translate(g1, glm::vec3(46.0f, 23.5f, 16.5f));
            g1 = glm::rotate(g1, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            g1 = glm::scale(g1, glm::vec3(0.083333f, 0.4f, 1.0f));
            shader.setMat4("model", g1);
            rectanglefrontmesh2.Draw(shader);

            glm::mat4 g2 = glm::mat4(1.0f) * transform;


            g2 = glm::translate(g2, glm::vec3(48.0f, 23.5f, 16.5f));
            g2 = glm::rotate(g2, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            g2 = glm::scale(g2, glm::vec3(0.083333f, 0.4f, 1.0f));
            shader.setMat4("model", g2);
            rectanglefrontmesh2.Draw(shader);



            glm::mat4 g3 = glm::mat4(1.0f) * transform;

            g3 = glm::translate(g3, glm::vec3(47.0f, 23.5f, 15.5f));
            g3 = glm::rotate(g3, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            g3 = glm::scale(g3, glm::vec3(0.083333f, 0.4f, 1.0f));
            shader.setMat4("model", g3);
            rectanglefrontmesh2.Draw(shader);

            glm::mat4 g4 = glm::mat4(1.0f) * transform;

            g4 = glm::translate(g4, glm::vec3(47.0f, 23.5f, 17.5f));
            g4 = glm::rotate(g4, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            g4 = glm::scale(g4, glm::vec3(0.083333f, 0.4f, 1.0f));
            shader.setMat4("model", g4);
            rectanglefrontmesh2.Draw(shader);
        }


        glm::mat4 roof = glm::mat4(1.0f) * transform;
        roof = glm::translate(roof, glm::vec3(25.0f + dotx, 10.0f, 10.0f));
        roof = glm::rotate(roof, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        roof = glm::rotate(roof, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        roof = glm::scale(roof, glm::vec3(0.90909090909090909090909090909091f, 0.81081102994892701322351708743705f, 1.0f));
        shader.setMat4("model", roof);
        rectangleroofmesh.Draw(shader);

        glm::mat4 roofside = glm::mat4(1.0f) * transform;
        roofside = glm::translate(roofside, glm::vec3(25.0f + dotx, 9.0f, 10.0f));
        roofside = glm::rotate(roofside, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        roofside = glm::rotate(roofside, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        roofside = glm::scale(roofside, glm::vec3(0.90909090909090909090909090909091f, 0.81081102994892701322351708743705f, 1.0f));
        shader.setMat4("model", roofside);
        rectangleroofsidemesh.Draw(shader);


        glm::mat4 roofy = glm::mat4(1.0f) * transform;
        roofy = glm::translate(roofy, glm::vec3(55.0f, 10.0f, 29.5f + l));
        roofy = glm::rotate(roofy, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        roofy = glm::rotate(roofy, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        roofy = glm::scale(roofy, glm::vec3(0.90909090909090909090909090909091f, 0.7702704784514806625623412330652f, 1.0f));
        shader.setMat4("model", roofy);
        rectangleroofmesh.Draw(shader);

        glm::mat4 roofyside = glm::mat4(1.0f) * transform;
        roofyside = glm::translate(roofyside, glm::vec3(55.0f, 9.0f, 29.5f + l));
        roofyside = glm::rotate(roofyside, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        roofyside = glm::rotate(roofyside, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        roofyside = glm::scale(roofyside, glm::vec3(0.90909090909090909090909090909091f, 0.7702704784514806625623412330652f, 1.0f));
        shader.setMat4("model", roofyside);
        rectangleroofsidemesh.Draw(shader);


        glm::mat4 roofy1 = glm::mat4(1.0f) * transform;
        roofy1 = glm::translate(roofy1, glm::vec3(65.0f, 10.0f, 29.5f + l));
        roofy1 = glm::rotate(roofy1, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        roofy1 = glm::rotate(roofy1, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        roofy1 = glm::scale(roofy1, glm::vec3(0.90909090909090909090909090909091f, 0.7702704784514806625623412330652f, 1.0f));
        shader.setMat4("model", roofy1);
        rectangleroofmesh.Draw(shader);

        glm::mat4 roofyside1 = glm::mat4(1.0f) * transform;
        roofyside1 = glm::translate(roofyside1, glm::vec3(65.0f, 9.0f, 29.5f + l));
        roofyside1 = glm::rotate(roofyside1, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        roofyside1 = glm::rotate(roofyside1, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        roofyside1 = glm::scale(roofyside1, glm::vec3(0.90909090909090909090909090909091f, 0.7702704784514806625623412330652f, 1.0f));
        shader.setMat4("model", roofyside1);
        rectangleroofsidemesh.Draw(shader);



        glm::mat4 back = glm::mat4(1.0f) * transform;
        back = glm::translate(back, glm::vec3(25.0f + dotx, 6.0f, 0.0f));
        back = glm::scale(back, glm::vec3(0.41666666f, 0.8f, 1.0f));
        shader.setMat4("model", back);
        rectanglefrontmesh.Draw(shader);


        glm::mat4 back1 = glm::mat4(1.0f) * transform;
        back1 = glm::translate(back1, glm::vec3(25.0f + dotx, 6.0f, 1.0f));
        back1 = glm::scale(back1, glm::vec3(0.41666666f, 0.8f, 1.0f));
        shader.setMat4("model", back1);
        rectanglefrontmesh.Draw(shader);


        glm::mat4 front = glm::mat4(1.0f) * transform;
        front = glm::translate(front, glm::vec3(25.0f + dotx, 6.0f, 20.0f));
        front = glm::scale(front, glm::vec3(0.41666666f, 0.8f, 1.0f));
        front = glm::rotate(front, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.setMat4("model", front);
        rectanglefrontmesh.Draw(shader);


        glm::mat4 front1 = glm::mat4(1.0f) * transform;
        front1 = glm::translate(front1, glm::vec3(25.0f + dotx, 6.0f, 21.0f));
        front1 = glm::scale(front1, glm::vec3(0.41666666f, 0.8f, 1.0f));
        front1 = glm::rotate(front1, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.setMat4("model", front1);
        rectanglefrontmesh.Draw(shader);


        glm::mat4 sideright = glm::mat4(1.0f) * transform;
        sideright = glm::translate(sideright, glm::vec3(70.0f, 6.0f, 12.0f + dotz));
        sideright = glm::scale(sideright, glm::vec3(0.41666666f, 0.8f, 1.0f));
        sideright = glm::rotate(sideright, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.setMat4("model", sideright);
        rectanglefrontmesh.Draw(shader);


        glm::mat4 sideright1 = glm::mat4(1.0f) * transform;
        sideright1 = glm::translate(sideright1, glm::vec3(69.0f, 6.0f, 12.0f + dotz));
        sideright1 = glm::scale(sideright1, glm::vec3(0.41666666f, 0.8f, 1.0f));
        sideright1 = glm::rotate(sideright1, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.setMat4("model", sideright1);
        rectanglefrontmesh.Draw(shader);

        //
        glm::mat4 dome = glm::mat4(1.0f) * transform;
        dome = glm::translate(dome, glm::vec3(60.0f, 9.7f, 50.0f));
        dome = glm::scale(dome, glm::vec3(7.0f, 7.0f, 7.0f));
        shader.setMat4("model", dome);
        domeMesh.Draw(shader, GL_TRIANGLE_STRIP);

        //

        dotx += 10;
        dotz += 24;
        l = dotz - (5 * (i + 1));
    }


    /*glm::mat4 back = glm::mat4(1.0f) * transform;
    back = glm::translate(back, glm::vec3(70.0f, 6.0f, 12.0f));
    back = glm::scale(back, glm::vec3(0.41666666f, 0.8f, 1.0f));
    back = glm::rotate(back, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", back);
    rectanglefrontmesh.Draw(shader);*/


    glm::mat4 model = glm::mat4(1.0f) * transform;

    model = glm::translate(model, glm::vec3(0.0f, 10.0f, -0.0f));
    model = glm::rotate(model, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", model);
    rectanglebackmesh.Draw(shader);


    //
    glm::mat4 dome = glm::mat4(1.0f) * transform;
    dome = glm::translate(dome, glm::vec3(0.0f, 23.5f, 10.6f));
    dome = glm::scale(dome, glm::vec3(7.0f, 7.0f, 7.0f));
    shader.setMat4("model", dome);
    domeMesh.Draw(shader, GL_TRIANGLE_STRIP);

    //




    glm::mat4 modelfront = glm::mat4(1.0f) * transform;

    modelfront = glm::translate(modelfront, glm::vec3(0.0f, 10.0f, 76.0f));
    modelfront = glm::rotate(modelfront, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", modelfront);
    rectanglefrontsidemesh.Draw(shader);





    glm::mat4 modelside = glm::mat4(1.0f) * transform;

    modelside = glm::translate(modelside, glm::vec3(0.0f, 10.0f, 1.0f));
    modelside = glm::rotate(modelside, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", modelside);
    rectanglebacksidemesh.Draw(shader);




    glm::mat4 modelfrontside = glm::mat4(1.0f) * transform;

    modelfrontside = glm::translate(modelfrontside, glm::vec3(0.0f, 10.0f, 75.0f));
    modelfrontside = glm::rotate(modelfrontside, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", modelfrontside);
    rectanglefrontsidemesh.Draw(shader);



    glm::mat4 right = glm::mat4(1.0f) * transform;

    right = glm::translate(right, glm::vec3(20.0f, 7.5f, 38.0f));
    right = glm::rotate(right, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", right);
    rectanglerightmesh.Draw(shader);


    glm::mat4 rightside = glm::mat4(1.0f) * transform;

    rightside = glm::translate(rightside, glm::vec3(19.0f, 7.5f, 38.0f));
    rightside = glm::rotate(rightside, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", rightside);
    rectanglerightmesh.Draw(shader);


    glm::mat4 left = glm::mat4(1.0f) * transform;

    left = glm::translate(left, glm::vec3(-20.0f, 10.0f, 38.0f));
    left = glm::rotate(left, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", left);
    rectangleleftmesh.Draw(shader);


    glm::mat4 leftside = glm::mat4(1.0f) * transform;

    leftside = glm::translate(leftside, glm::vec3(-19.0f, 10.0f, 38.0f));
    leftside = glm::rotate(leftside, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    shader.setMat4("model", leftside);
    rectangleleftsidemesh.Draw(shader);

    float h = 0, r = 0, f = 0, m = 0;
    for (size_t i = 0; i < 4; i++)
    {
        if (i == 3) {
            f += 13;
            h = 0;
            for (size_t j = 0; j < 3; j++)
            {
                glm::mat4 roofside = glm::mat4(1.0f) * transform;

                roofside = glm::translate(roofside, glm::vec3(-12.5f + f, 18.0f, 13.3333f + h));
                roofside = glm::rotate(roofside, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                roofside = glm::scale(roofside, glm::vec3(1.1818181818181818181818181818182f, 1.0f, 1.0f));
                shader.setMat4("model", roofside);
                rectangleroofsidemesh.Draw(shader);


                h += 24.6633f;
            }

        }
        if (i == 0 || i == 1) {

            glm::mat4 form1 = glm::mat4(1.0f) * transform;
            form1 = glm::translate(form1, glm::vec3(-4.75f, 27.0f, 61.55f - m));
            form1 = glm::rotate(form1, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            form1 = glm::rotate(form1, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

            form1 = glm::rotate(form1, glm::radians(120.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            form1 = glm::scale(form1, glm::vec3(1.0f, 1.1027030007305407379839832389144f, 1.0f));
            shader.setMat4("model", form1);
            rectangleroofmesh.Draw(shader);


            glm::mat4 form2 = glm::mat4(1.0f) * transform;
            form2 = glm::translate(form2, glm::vec3(4.75f, 27.0f, 61.55f - m));
            form2 = glm::rotate(form2, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            form2 = glm::rotate(form2, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

            form2 = glm::rotate(form2, glm::radians(-120.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            form2 = glm::scale(form2, glm::vec3(1.0f, 1.1027030007305407379839832389144f, 1.0f));
            shader.setMat4("model", form2);
            rectangleroofmesh.Draw(shader);
        }
        if (i == 3) {
            glm::mat4 roof4 = glm::mat4(1.0f) * transform;

            roof4 = glm::translate(roof4, glm::vec3(-15.0 + r, 14.0f, 87.7f));
            roof4 = glm::rotate(roof4, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            roof4 = glm::scale(roof4, glm::vec3(0.90909090909090909090909090909091f, 1.0f, 1.0f));
            shader.setMat4("model", roof4);
            rectangleroofmesh.Draw(shader);
            continue;
        }
        glm::mat4 roof = glm::mat4(1.0f) * transform;

        roof = glm::translate(roof, glm::vec3(-13.5f, 19.0f, 13.3333f + h));
        roof = glm::rotate(roof, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        shader.setMat4("model", roof);
        rectangleroofmesh.Draw(shader);

        glm::mat4 roofside = glm::mat4(1.0f) * transform;

        roofside = glm::translate(roofside, glm::vec3(-12.5f, 18.0f, 13.3333f + h));
        roofside = glm::rotate(roofside, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        roofside = glm::scale(roofside, glm::vec3(1.1818181818181818181818181818182f, 1.0f, 1.0f));
        shader.setMat4("model", roofside);
        rectangleroofsidemesh.Draw(shader);



        glm::mat4 roof1 = glm::mat4(1.0f) * transform;

        roof1 = glm::translate(roof1, glm::vec3(13.5f, 14.0f, 13.3333f + h));
        roof1 = glm::rotate(roof1, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        shader.setMat4("model", roof1);
        rectangleroofmesh.Draw(shader);


        glm::mat4 roofside1 = glm::mat4(1.0f) * transform;

        roofside1 = glm::translate(roofside1, glm::vec3(13.5f + f, 13.0f, 13.3333f + h));
        roofside1 = glm::rotate(roofside1, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        roofside1 = glm::scale(roofside1, glm::vec3(1.1818181818181818181818181818182f, 1.0f, 1.0f));
        shader.setMat4("model", roofside1);
        rectangleroofsidemesh.Draw(shader);


        glm::mat4 roof2 = glm::mat4(1.0f) * transform;

        roof2 = glm::translate(roof2, glm::vec3(-0.0f, 25.0f, 48.0f));
        roof2 = glm::rotate(roof2, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        roof2 = glm::scale(roof2, glm::vec3(1.454545f, 2.18918978086210293570349613608f, 1.0f));
        shader.setMat4("model", roof2);
        rectangleroofmesh.Draw(shader);


        glm::mat4 roof3 = glm::mat4(1.0f) * transform;

        roof3 = glm::translate(roof3, glm::vec3(-0.0f, 19.0f, 13.3333f));
        roof3 = glm::rotate(roof3, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        roof3 = glm::scale(roof3, glm::vec3(1.454545f, 1.0f, 1.0f));
        shader.setMat4("model", roof3);
        rectangleroofmesh.Draw(shader);



        glm::mat4 roof4 = glm::mat4(1.0f) * transform;

        roof4 = glm::translate(roof4, glm::vec3(-15.0 + r, 14.0f, 87.7f));
        roof4 = glm::rotate(roof4, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        roof4 = glm::scale(roof4, glm::vec3(0.90909090909090909090909090909091f, 1.0f, 1.0f));
        shader.setMat4("model", roof4);
        rectangleroofmesh.Draw(shader);



        h += 24.6633f;
        m += 27.1f;
        r += 10.0f;
    }





    glm::mat4 right1 = glm::mat4(1.0f) * transform;

    right1 = glm::translate(right1, glm::vec3(8.0f, 19.5f, 48.0f));
    right1 = glm::rotate(right1, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", right1);
    rectangleupmesh.Draw(shader);


    glm::mat4 rightside1 = glm::mat4(1.0f) * transform;

    rightside1 = glm::translate(rightside1, glm::vec3(7.0f, 19.0f, 48.0f));
    rightside1 = glm::rotate(rightside1, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", rightside1);
    rectangleupsidemesh.Draw(shader);



    glm::mat4 left1 = glm::mat4(1.0f) * transform;

    left1 = glm::translate(left1, glm::vec3(-8.0f, 21.8f, 48.0f));
    left1 = glm::rotate(left1, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    left1 = glm::scale(left1, glm::vec3(1.0f, 0.583f, 1.0f));
    shader.setMat4("model", left1);
    rectangleupmesh.Draw(shader);


    glm::mat4 leftside1 = glm::mat4(1.0f) * transform;

    leftside1 = glm::translate(leftside1, glm::vec3(-7.0f, 21.5f, 48.0f));
    leftside1 = glm::rotate(leftside1, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    leftside1 = glm::scale(leftside1, glm::vec3(1.0f, 0.583f, 1.0f));
    shader.setMat4("model", leftside1);
    rectangleupsidemesh.Draw(shader);



    glm::mat4 rightfront = glm::mat4(1.0f) * transform;

    rightfront = glm::translate(rightfront, glm::vec3(20.0f, 7.5f, 88.0f));
    rightfront = glm::rotate(rightfront, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", rightfront);
    rectanglefrontmesh.Draw(shader);

    glm::mat4 rightfrontside = glm::mat4(1.0f) * transform;

    rightfrontside = glm::translate(rightfrontside, glm::vec3(19.0f, 7.5f, 88.0f));
    rightfrontside = glm::rotate(rightfrontside, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", rightfrontside);
    rectanglefrontmesh.Draw(shader);


    glm::mat4 leftfront = glm::mat4(1.0f) * transform;

    leftfront = glm::translate(leftfront, glm::vec3(-20.0f, 7.5f, 88.0f));
    leftfront = glm::rotate(leftfront, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", leftfront);
    rectanglefrontmesh.Draw(shader);

    glm::mat4 leftfrontside = glm::mat4(1.0f) * transform;

    leftfrontside = glm::translate(leftfrontside, glm::vec3(-19.0f, 7.5f, 88.0f));
    leftfrontside = glm::rotate(leftfrontside, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", leftfrontside);
    rectanglefrontmesh.Draw(shader);


    glm::mat4 r1 = glm::mat4(1.0f) * transform;

    r1 = glm::translate(r1, glm::vec3(17.5f, 7.0f, 100.0f));
    r1 = glm::rotate(r1, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    r1 = glm::scale(r1, glm::vec3(0.208f, 0.93333f, 1.0f));
    shader.setMat4("model", r1);
    rectanglefrontmesh2.Draw(shader);
    ///////2
    glm::mat4 r2 = glm::mat4(1.0f) * transform;

    r2 = glm::translate(r2, glm::vec3(17.5f, 7.0f, 97.0f));
    r2 = glm::rotate(r2, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    r2 = glm::scale(r2, glm::vec3(0.208f, 0.93333f, 1.0f));
    shader.setMat4("model", r2);
    rectanglefrontmesh2.Draw(shader);

    /////l
    glm::mat4 l1 = glm::mat4(1.0f) * transform;

    l1 = glm::translate(l1, glm::vec3(-17.5f, 7.0f, 100.0f));
    l1 = glm::rotate(l1, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    l1 = glm::scale(l1, glm::vec3(0.208f, 0.93333f, 1.0f));
    shader.setMat4("model", l1);
    rectanglefrontmesh2.Draw(shader);


    glm::mat4 l2 = glm::mat4(1.0f) * transform;

    l2 = glm::translate(l2, glm::vec3(-17.5f, 7.0f, 97.0f));
    l2 = glm::rotate(l2, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    l2 = glm::scale(l2, glm::vec3(0.208f, 0.93333f, 1.0f));
    shader.setMat4("model", l2);
    rectanglefrontmesh2.Draw(shader);


    glm::mat4 rr2 = glm::mat4(1.0f) * transform;

    rr2 = glm::translate(rr2, glm::vec3(15.0f, 7.0f, 98.5f));
    rr2 = glm::rotate(rr2, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    rr2 = glm::scale(rr2, glm::vec3(0.125f, 0.93333f, 1.0f));
    shader.setMat4("model", rr2);
    rectanglefrontmesh2.Draw(shader);


    glm::mat4 ll2 = glm::mat4(1.0f) * transform;

    ll2 = glm::translate(ll2, glm::vec3(-15.0f, 7.0f, 98.5f));
    ll2 = glm::rotate(ll2, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    ll2 = glm::scale(ll2, glm::vec3(0.125f, 0.93333f, 1.0f));
    shader.setMat4("model", ll2);
    rectanglefrontmesh2.Draw(shader);

    glm::mat4 rectanglel = glm::mat4(1.0f) * transform;

    rectanglel = glm::translate(rectanglel, glm::vec3(-17.0f, 9.0f, 86.5f));
    rectanglel = glm::rotate(rectanglel, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    rectanglel = glm::rotate(rectanglel, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    rectanglel = glm::scale(rectanglel, glm::vec3(0.875f, 0.26666f, 1.0f));
    shader.setMat4("model", rectanglel);
    rectanglefrontmesh2.Draw(shader);


    glm::mat4 rectangler = glm::mat4(1.0f) * transform;

    rectangler = glm::translate(rectangler, glm::vec3(17.0f, 9.0f, 86.5f));
    rectangler = glm::rotate(rectangler, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    rectangler = glm::rotate(rectangler, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    rectangler = glm::scale(rectangler, glm::vec3(0.875f, 0.26666f, 1.0f));
    shader.setMat4("model", rectangler);
    rectanglefrontmesh2.Draw(shader);


    int x = 0.5, c = 0;
    for (size_t i = 1; i <= 5; i++)
    {
        if (i == 4) {
            c = 0; x += 1;
        }
        if (i == 5) {
            glm::mat4 hcylinder = glm::mat4(1.0f) * transform;

            hcylinder = glm::translate(hcylinder, glm::vec3(-13.0f + x, 9.0f, 87.5f));
            hcylinder = glm::rotate(hcylinder, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            hcylinder = glm::scale(hcylinder, glm::vec3(7.0f, 10.0f, 10.0f));
            shader.setMat4("model", hcylinder);
            halfcylindermesh.Draw(shader);
            continue;
        }
        if (i == 2) {
            glm::mat4 rectanglerG = glm::mat4(1.0f) * transform;

            rectanglerG = glm::translate(rectanglerG, glm::vec3(-10.0f + x, 9.0f, 86.5f));
            rectanglerG = glm::rotate(rectanglerG, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            rectanglerG = glm::rotate(rectanglerG, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            rectanglerG = glm::scale(rectanglerG, glm::vec3(0.875f, 0.1333333f, 1.0f));
            shader.setMat4("model", rectanglerG);
            rectanglefrontmesh2.Draw(shader);

            glm::mat4 hcylinder = glm::mat4(1.0f) * transform;

            hcylinder = glm::translate(hcylinder, glm::vec3(-13.0f + x, 9.0f, 87.5f));
            hcylinder = glm::rotate(hcylinder, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            hcylinder = glm::scale(hcylinder, glm::vec3(7.0f, 10.0f, 10.0f));
            shader.setMat4("model", hcylinder);
            halfcylindermesh.Draw(shader);

            glm::mat4 g1 = glm::mat4(1.0f) * transform;

            g1 = glm::translate(g1, glm::vec3(-11.0f + x, 7.0f, 98.5f));
            g1 = glm::rotate(g1, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            g1 = glm::scale(g1, glm::vec3(0.125f, 0.93333f, 1.0f));
            shader.setMat4("model", g1);
            rectanglefrontmesh2.Draw(shader);

            glm::mat4 g2 = glm::mat4(1.0f) * transform;


            g2 = glm::translate(g2, glm::vec3(-9.0f + x, 7.0f, 98.5f));
            g2 = glm::rotate(g2, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            g2 = glm::scale(g2, glm::vec3(0.125f, 0.93333f, 1.0f));
            shader.setMat4("model", g2);
            rectanglefrontmesh2.Draw(shader);



            glm::mat4 g3 = glm::mat4(1.0f) * transform;

            g3 = glm::translate(g3, glm::vec3(-10.0f + x, 7.0f, 100.0f));
            g3 = glm::rotate(g3, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            g3 = glm::scale(g3, glm::vec3(0.083333f, 0.93333f, 1.0f));
            shader.setMat4("model", g3);
            rectanglefrontmesh2.Draw(shader);

            glm::mat4 g4 = glm::mat4(1.0f) * transform;

            g4 = glm::translate(g4, glm::vec3(-10.0f + x, 7.0f, 97.0f));
            g4 = glm::rotate(g4, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            g4 = glm::scale(g4, glm::vec3(0.083333f, 0.93333f, 1.0f));
            shader.setMat4("model", g4);
            rectanglefrontmesh2.Draw(shader);

            x += 8;
            continue;
        }
        glm::mat4 rectanglerG = glm::mat4(1.0f) * transform;

        rectanglerG = glm::translate(rectanglerG, glm::vec3(-10.0f + x, 9.0f, 86.5f));
        rectanglerG = glm::rotate(rectanglerG, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        rectanglerG = glm::rotate(rectanglerG, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        rectanglerG = glm::scale(rectanglerG, glm::vec3(0.875f, 0.1333333f, 1.0f));
        shader.setMat4("model", rectanglerG);
        rectanglefrontmesh2.Draw(shader);
        glm::mat4 g1 = glm::mat4(1.0f) * transform;

        g1 = glm::translate(g1, glm::vec3(-11.0f + x, 7.0f, 98.5f));
        g1 = glm::rotate(g1, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        g1 = glm::scale(g1, glm::vec3(0.125f, 0.93333f, 1.0f));
        shader.setMat4("model", g1);
        rectanglefrontmesh2.Draw(shader);

        glm::mat4 g2 = glm::mat4(1.0f) * transform;


        g2 = glm::translate(g2, glm::vec3(-9.0f + x, 7.0f, 98.5f));
        g2 = glm::rotate(g2, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        g2 = glm::scale(g2, glm::vec3(0.125f, 0.93333f, 1.0f));
        shader.setMat4("model", g2);
        rectanglefrontmesh2.Draw(shader);



        glm::mat4 g3 = glm::mat4(1.0f) * transform;

        g3 = glm::translate(g3, glm::vec3(-10.0f + x, 7.0f, 100.0f));
        g3 = glm::rotate(g3, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        g3 = glm::scale(g3, glm::vec3(0.083333f, 0.93333f, 1.0f));
        shader.setMat4("model", g3);
        rectanglefrontmesh2.Draw(shader);

        glm::mat4 g4 = glm::mat4(1.0f) * transform;

        g4 = glm::translate(g4, glm::vec3(-10.0f + x, 7.0f, 97.0f));
        g4 = glm::rotate(g4, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        g4 = glm::scale(g4, glm::vec3(0.083333f, 0.93333f, 1.0f));
        shader.setMat4("model", g4);
        rectanglefrontmesh2.Draw(shader);

        if (i == 3) {
            c = 3; x -= 1;
        }

        glm::mat4 hcylinder = glm::mat4(1.0f) * transform;

        hcylinder = glm::translate(hcylinder, glm::vec3(-13.0f + x, 9.0f, 87.5f));
        hcylinder = glm::rotate(hcylinder, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        hcylinder = glm::scale(hcylinder, glm::vec3(7.0f + c, 10.0f, 10.0f));
        shader.setMat4("model", hcylinder);
        halfcylindermesh.Draw(shader);


        x += 6;

    }





    glm::mat4 rectanglecylinder = glm::mat4(1.0f) * transform;

    rectanglecylinder = glm::translate(rectanglecylinder, glm::vec3(-0.0f, 7.3f, 100.11199f));
    rectanglecylinder = glm::rotate(rectanglecylinder, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", rectanglecylinder);
    rectanglecylindermesh.Draw(shader);




    glm::mat4 trans = glm::mat4(1.0f) * transform;

    trans = glm::translate(trans, glm::vec3(-0.0f, 21.5f, 10.6f));
    trans = glm::rotate(trans, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    shader.setMat4("model", trans);
    cylindermesh.Draw(shader);



    glm::mat4 wall1 = glm::mat4(1.0f) * transform;

    wall1 = glm::translate(wall1, glm::vec3(-0.0f, 22.0f, 21.0f));
    wall1 = glm::rotate(wall1, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    wall1 = glm::scale(wall1, glm::vec3(0.666666f, 0.4f, 1.0f));
    shader.setMat4("model", wall1);
    rectanglemesh.Draw(shader);


    glm::mat4 wall2 = glm::mat4(1.0f) * transform;

    wall2 = glm::translate(wall2, glm::vec3(-0.0f, 22.5f, 75.0f));
    wall2 = glm::rotate(wall2, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    wall2 = glm::scale(wall2, glm::vec3(0.666666f, 0.33333f, 1.0f));
    shader.setMat4("model", wall2);
    rectanglemesh.Draw(shader);




    glm::mat4 wallright = glm::mat4(1.0f) * transform;

    wallright = glm::translate(wallright, glm::vec3(8.0f, 17.0f, 11.0f));
    wallright = glm::rotate(wallright, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    wallright = glm::scale(wallright, glm::vec3(0.83333f, 0.4f, 1.0f));
    shader.setMat4("model", wallright);
    rectanglemesh.Draw(shader);


    glm::mat4 wallrightside = glm::mat4(1.0f) * transform;

    wallrightside = glm::translate(wallrightside, glm::vec3(7.0f, 16.5f, 11.0f));
    wallrightside = glm::rotate(wallrightside, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    wallrightside = glm::scale(wallrightside, glm::vec3(0.83333f, 0.46666666f, 1.0f));
    shader.setMat4("model", wallrightside);
    rectanglemesh.Draw(shader);



}
//void mosque::drawDepth(Shader depth, bool ortho)
//{
//    Shader temp = shader;
//    shader = depth;
//    glm::mat4 transform(1);
//    transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, -200.0f));
//    transform = glm::scale(transform, glm::vec3(1.5f, 1.0f, 1.0f));
//    drawMeshes(transform);
//    shader = temp;
//    
//}
