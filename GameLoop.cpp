#include "GameLoop.h"
#include "texture.h"
#include "imageloader.h"
#include <vector>
#include "terrain.h"
#include "skybox.h"
#include "Dome.h"
#include "floor.h"
#include "DepthMap.h"
#include "audio.h"
#include "InputHandle.h"
#include "customModelTexts.h"
#include "backpack.h"
#include "GUI.h"
#include "mosque.h"
#include "AyaModel.h"
#include "outside.h"
#include "building.h"
#include "Wall.h"
#include "mirror.h"
#include "InnerDome.h"


void startGame(GLFWwindow* window) {

 
    Shader dshader("shaders/terrain.vs", "shaders/terrain.fs", "shaders/terrain.gs" );
    Shader dshaderInstance("shaders/terrain-instance.vs", "shaders/terrain-instance.fs", "shaders/terrain-instance.gs");
    Shader skyboxShader("shaders/skyboxday.vs", "shaders/skyboxday.fs");

    unsigned int skybox = setupSkyBox();
    unsigned int skyboxTex = initSkyBoxTextures();


    unsigned int skyboxNight = setupSkyBoxNight();
    unsigned int skyboxTexNight = initSkyBoxTexturesNight();

    Simplemesh terrain = terrainSetup(dshader);

    AudioManager::init();

    Dome dome(dshader);
    square floor(dshader);
    mosque Mosque(dshader);
    AyaModel md(dshader);
    outside out(dshader);
    Building building(dshader);
    Wall fence(dshader);
    Mirror mirror(dshader);



    Shader depthShader("shaders/depth.vs", "shaders/depth.fs");
    DepthMap depthmap(depthShader, "direc");
    DepthMap depthmapSpot(depthShader, "spot");
    dshader.use();
    dshader.setMat4("lightSpaceMatrix", depthmap.lightSpaceMatrix);
    camera.fps = true;


    sTexture depthMapTex = { depthmap.render(
            {
                dome,
                Mosque,
                md,
                fence

            }), "shadowMap", "" };


    while (!glfwWindowShouldClose(window))
    {
        refreshTime();
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        Collision::CollisionDetector::updateCamPos();
        GUI::UIupdate();

        AudioManager::playBackGround();
        unsigned int depthmapspotTex = depthmapSpot.render({ dome});
        dshader.use();
        dshader.setBool("isModel", false);
        dshader.setMat4("lightSpaceMatrix2", depthmapSpot.lightSpaceMatrix);
        dshader.setBool("spotOn", spotLight);
        dshader.setBool("noparallax", true);
        drawTerrain(terrain, dshader, depthMapTex.id, depthmapspotTex);
        dshader.setBool("noparallax", true);

        dome.Draw();
        floor.Draw();
        Mosque.Draw();
        out.Draw();
        dshader.setBool("isModel", true);
        md.Draw();
        dshader.setBool("isModel", false);
        dshader.setBool("noparallax", false);
        fence.Draw();
        dshader.setBool("noparallax", true);
        building.Draw();
        mirror.Draw();
        dshader.setMat4("model", glm::translate(glm::mat4(1), glm::vec3(0.0, 0.0, 10.0f)));

        if (night) {
            drawSkyBoxNight(skyboxShader, skyboxNight, skyboxTexNight);
        }
        else
            drawSkyBox(skyboxShader, skybox, skyboxTex);
        //depthmap.renderQuad();
        //depthmapSpot.renderQuad();
        GUI::UIrender();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}










