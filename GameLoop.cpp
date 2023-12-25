#include "GameLoop.h"
#include "texture.h"
#include "imageloader.h"
#include <vector>
#include "terrain.h"
#include "skybox.h"
#include "Dome.h"
#include <learnopengl/model.h>
#include "DepthMap.h"
#include "audio.h"


void startGame(GLFWwindow* window) {

 
    Shader dshader("shaders/terrain.vs", "shaders/terrain.fs", "shaders/terrain.gs" );
    Shader mshader("shaders/model.vs", "shaders/model.fs", "shaders/model.gs");
    Shader lshader("shaders/default.vs", "shaders/default.fs", "shaders/default.gs");
    Shader skyboxShader("shaders/skyboxday.vs", "shaders/skyboxday.fs");
    texture text("res/textures/container.jpg","material.diffuse");
    texture cubeText("res/textures/Orange.jpg","material.diffuse");
    vector<sTexture> cubeTexts = { cubeText.info };
    vector<sTexture> texts = {text.info};

    unsigned int skybox = setupSkyBox();
    unsigned int skyboxTex = initSkyBoxTextures();

    Simplemesh terrain = terrainSetup(dshader);

 
    sf::SoundBuffer sb;
    sb.loadFromFile("res/audio/whoosh.wav");
    sf::Sound lala(sb);



    AudioManager::init();

    Dome dome(dshader);
    

    //Model ourModel("res/models/backpack/backpack.obj");



    Shader depthShader("shaders/depth.vs", "shaders/depth.fs");
    DepthMap depthmap(depthShader);
    dshader.use();
    dshader.setMat4("lightSpaceMatrix", depthmap.lightSpaceMatrix);
    //camera.fps = true;
    sTexture depthMapTex = { depthmap.render(
            {
                dome,

            }), "shadowMap", "" };
    while (!glfwWindowShouldClose(window))
    {
        refreshTime();
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //AudioManager::stepsSounds[0]->play();
        //lala.play();

        terrain.addDepthTexture(depthMapTex);
        dshader.setBool("noparallax", false);
        drawTerrain(terrain, dshader);
        dshader.use();
        glm::mat4 transform = glm::mat4(1);
        transform = glm::translate(transform, glm::vec3(0, 2.0f, 0));
        transform = glm::scale(transform, glm::vec3(4.0f, 4.0f ,4.0f));
        dshader.setMat4("model", transform);


        //xs -= (deltaTime * 0.000001f);
        //lightPos.x += xs;
        //lightPos.z += xs;



        lshader.use();
        glm::mat4 cubeTrasform = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
         cubeTrasform = glm::translate(cubeTrasform, glm::vec3(-4.0f, 2.0f, 0.0f));
        addDirectionalLight(lshader);
        setMVP(lshader, cubeTrasform);
        lshader.setFloat("material.shininess",  32.0f);


        dome.Draw();



        addDirectionalLight(mshader);
        mshader.setFloat("shininess", 32.0f);
        mshader.setBool("noparallax", true);
        setMVP(mshader, glm::translate(glm::mat4(1), glm::vec3(2.0f,2.0f,2.0f)));
        //ourModel.Draw(mshader);



        drawSkyBox(skyboxShader, skybox, skyboxTex);


        //depthmap.renderQuad();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}










