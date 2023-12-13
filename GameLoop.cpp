#include "GameLoop.h"
#include "texture.h"
#include "imageloader.h"
#include <vector>
#include "square.h"
#include "prism.h"
#include "terrain.h"
#include "skybox.h"
#include "cube.h"


void startGame(GLFWwindow* window) {

 
    Shader dshader("shaders/terrain.vs", "shaders/terrain.fs", "shaders/terrain.gs" );
    Shader lshader("shaders/default.vs", "shaders/default.fs", "shaders/default.gs");
    Shader skyboxShader("shaders/skyboxday.vs", "shaders/skyboxday.fs");
    texture text("res/textures/container.jpg","material.diffuse");
    texture cubeText("res/textures/Orange.jpg","material.diffuse");
    vector<sTexture> cubeTexts = { cubeText.info };
    vector<sTexture> texts = {text.info};

    unsigned int skybox = setupSkyBox();
    unsigned int skyboxTex = initSkyBoxTextures();

    Simplemesh terrain = terrainSetup(dshader);



    square.sVertices = convertToVertexglmVector(square.vertices);
    Simplemesh box(square.sVertices,square.indices, texts );

    initcube();
    Simplemesh cubes(cube.sVertices, cube.indices, cubeTexts);


    //camera.fps = true;
    while (!glfwWindowShouldClose(window))
    {
        refreshTime();
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    

        drawTerrain(terrain, dshader);
        dshader.use();
        glm::mat4 transform = glm::mat4(1);
        transform = glm::translate(transform, glm::vec3(0, 2.0f, 0));
        transform = glm::scale(transform, glm::vec3(4.0f, 4.0f ,4.0f));
        dshader.setMat4("model", transform);
        box.Draw(dshader);







        float x = 4.0f;
        for (size_t i = 0; i < 10; i++)
        {
            transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(0 + x, 2.0f, 0));
            transform = glm::scale(transform, glm::vec3(4.0f, 4.0f, 4.0f));
            dshader.setMat4("model", transform);
            box.Draw(dshader);
            x += 4.0f;
        }



        lshader.use();
        glm::mat4 cubeTrasform = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
         cubeTrasform = glm::translate(cubeTrasform, glm::vec3(-4.0f, 2.0f, 0.0f));
        addDirectionalLight(lshader);
        setMVP(lshader, cubeTrasform);
        lshader.setFloat("material.shininess",  32.0f);
        cubes.Draw(lshader);




        drawSkyBox(skyboxShader, skybox, skyboxTex);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}











glm::mat4 setMVP(Shader shader, glm::mat4 transform) {
    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    shader.setMat4("projection", projection);

    glm::mat4 view = camera.GetViewMatrix();
    shader.setMat4("view", view);

    shader.setMat4("model", transform);

    return projection * view * transform;
}