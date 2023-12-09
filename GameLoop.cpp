#include "GameLoop.h"
#include "texture.h"
#include "imageloader.h"
#include <vector>
#include "square.h"
#include "prism.h"
#include "terrain.h"
#include "skybox.h"


void startGame(GLFWwindow* window) {

 
    Shader dshader("shaders/try.vs", "shaders/try.fs");
    Shader skyboxShader("shaders/6.1.skybox.vs", "shaders/6.1.skybox.fs");
    texture text("res/textures/container.jpg", GL_RGB,"material.diffuse");
    vector<sTexture> texts = {text.info};

    unsigned int skybox = setupSkyBox();
    unsigned int skyboxTex = initSkyBoxTextures();

    Simplemesh terrain = terrainSetup(dshader);
    Simplemesh box(convertToVertexglmVector(square.vertices, square.vertices.size()),square.indices, texts );

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