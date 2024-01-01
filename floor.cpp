
#include"texture.h"
#include "GameLoop.h"
#include "lighting.h"
#include "floor.h"
square::square(Shader shader) :object_(shader) {
    init();
}
void square::init() {
    texture floor1("res/textures/floor/ao.jpg", "material.ambient");
    texture floor2("res/textures/floor/nor.jpg", "material.normal");
    texture floor3("res/textures/floor/rough.jpg", "material.specular");
    texture floor4("res/textures/floor/diff.jpg", "material.diffuse");
    texture floor5("res/textures/floor/height.jpg", "material.height");

    vector<sTexture> texts = { floor1.info,floor2.info ,floor3.info, floor4.info, floor5.info };
    shapeUtils::generateRectangle(1.0f, 1.0f, squares.sVertices, squares.indices);
    squaremesh = Simplemesh(squares.sVertices, squares.indices, texts);
}
void square::Draw() {
    //20 ->-120
    glm::mat4 trans(1.0f);
    trans = glm::translate(trans, glm::vec3(20.0f, 1.0f, 0.0f));
    shader.setMat4("model", trans);
    drawMeshes(trans);

}
void square::drawMeshes(glm::mat4 transform, glm::mat4 scaleMat4) {
    float x = 20.0f;
    float z = 15.0f;
    shader.use();
    //draw floor like a paper 
    for (size_t i = 0; i < 11; i++)
    {
        for (size_t j = 0; j < 11; j++)
        {
            if (j == 5 && i == 0) {
                transform = glm::mat4(1.0f);
                transform = glm::translate(transform, glm::vec3(x-1, 1.0f, z));
                transform = glm::scale(transform, glm::vec3(9.0f, 9.0f, 10.0f));
                transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                shader.setMat4("model", transform);
                squaremesh.Draw(shader);
                transform = glm::mat4(1.0f);
                transform = glm::translate(transform, glm::vec3(25.0f, -4.0f, z));
                transform = glm::scale(transform, glm::vec3(9.0f, 9.0f, 10.0f));
                transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                shader.setMat4("model", transform);
                squaremesh.Draw(shader);
                z -= 10.0f;
                continue;
            }
            if (j == 5 && i == 10) {
                transform = glm::mat4(1.0f);
                transform = glm::translate(transform, glm::vec3(x+1, 1.0f, z));
                transform = glm::scale(transform, glm::vec3(9.0f, 9.0f, 10.0f));
                transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                shader.setMat4("model", transform);
                squaremesh.Draw(shader);
                transform = glm::mat4(1.0f);
                transform = glm::translate(transform, glm::vec3(25.0f, -4.0f, z));
                transform = glm::scale(transform, glm::vec3(9.0f, 9.0f, 10.0f));
                transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                shader.setMat4("model", transform);
                squaremesh.Draw(shader);
                z -= 10.0f;
                continue;
            }
            if (j == 0 && i == 5) {
                transform = glm::mat4(1.0f);
                transform = glm::translate(transform, glm::vec3(x, 1.0f, z-1));
                transform = glm::scale(transform, glm::vec3(10.0f, 9.0f, 10.0f));
                transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                shader.setMat4("model", transform);
                squaremesh.Draw(shader);
                transform = glm::mat4(1.0f);
                transform = glm::translate(transform, glm::vec3(25.0f, -4.0f, z));
                transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
                transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                shader.setMat4("model", transform);
                squaremesh.Draw(shader);
                z -= 10.0f;
                continue;
            }

            if (j == 10 && i == 5) {
                transform = glm::mat4(1.0f);
                transform = glm::translate(transform, glm::vec3(x, 1.0f, z + 1));
                transform = glm::scale(transform, glm::vec3(10.0f, 9.0f, 10.0f));
                transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                shader.setMat4("model", transform);
                squaremesh.Draw(shader);
                transform = glm::mat4(1.0f);
                transform = glm::translate(transform, glm::vec3(25.0f, -4.0f, z));
                transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
                transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                shader.setMat4("model", transform);
                squaremesh.Draw(shader);
                z -= 10.0f;
                continue;
            }

            else {
                transform = glm::mat4(1.0f);
                transform = glm::translate(transform, glm::vec3(x, 1.0f, z));
                transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
                transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                shader.setMat4("model", transform);
                squaremesh.Draw(shader);
                z -= 10.0f;
            }
        }
        x -= 10.0f;
        z = 15.0f;
    }
    //make floor 3d by close the all side

    float var1 = 20.0f;
    for (size_t i = 0; i < 11; i++)
    {
        if (i == 5) {
            transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(var1+5.0f, -4.0f, 15.0f));
            transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
            transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            //transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            shader.setMat4("model", transform);
            squaremesh.Draw(shader);
            transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(var1- 5.0f, -4.0f, 15.0f));
            transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
            transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
          //  transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            shader.setMat4("model", transform);
            squaremesh.Draw(shader);

            var1 -= 10.0f;
            continue;
        }
        transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(var1, -4.0f, 20.0f));
        transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
        transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.setMat4("model", transform);
        squaremesh.Draw(shader);
        var1 -= 10.0f;
    }
    //right side
    float var2 = 15.0f;
    for (size_t i = 0; i < 11; i++)
    {
        if (i == 5) {
            transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(20.0f, -4.0f, var2+5.0f));
            transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
            transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            shader.setMat4("model", transform);
            squaremesh.Draw(shader);
            transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(20.0f, -4.0f, var2 - 5.0f));
            transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
            transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            shader.setMat4("model", transform);
            squaremesh.Draw(shader);
            var2 = var2 - 10.0f;
            continue;
        }
        transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(25.0f,-4.0f, var2));
        transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
        transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.setMat4("model", transform);
        squaremesh.Draw(shader);
        var2 = var2 - 10.0f;
    }
    //top
    float var3 = 20.0f;
    for (size_t i = 0; i < 11; i++)
    {
        if (i == 5) {
            transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(var3 + 5.0f, -4.0f, -85.0f));
            transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
            transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            //transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            shader.setMat4("model", transform);
            squaremesh.Draw(shader);
            transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(var3 - 5.0f, -4.0f, -85.0f));
            transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
            transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            //  transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            shader.setMat4("model", transform);
            squaremesh.Draw(shader);
            var3 -= 10.0f;
            continue;
        }
        transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(var3, -4.0f, -90.0f));
        transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
        transform = glm::rotate(transform, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.setMat4("model", transform);
        squaremesh.Draw(shader);
        var3 -= 10.0f;
    }
    //LEFT SIDE
    float var4 = 15.0f;
    for (size_t i = 0; i < 11; i++)
    {
        if (i == 5) {
            transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(-80.0f, -4.0f, var4 + 5.0f));
            transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
            transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            shader.setMat4("model", transform);
            squaremesh.Draw(shader);
            transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(-80.0f, -4.0f, var4 - 5.0f));
            transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
            transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            shader.setMat4("model", transform);
            squaremesh.Draw(shader);
            var4 = var4 - 10.0f;
            continue;
        }
        transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(-85.0f, -4.0f, var4));
        transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
        transform = glm::rotate(transform, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.setMat4("model", transform);
        squaremesh.Draw(shader);
        var4 = var4 - 10.0f;
    }
    //east stairs
    transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(23.5f,-4.0f, -35.0f));
    transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
    transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", transform);
    squaremesh.Draw(shader);
    //str
    transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(20.0f, 0.5f, -35.0f));
    transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
    transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.setMat4("model", transform);
    squaremesh.Draw(shader);
    /////south stairs
    transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(-30.0f, -4.0f, 19.0f));
    transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
    transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", transform);
    squaremesh.Draw(shader);
    //str
    transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(-30.0f, 0.5f, 15.0f));
    transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
    transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.setMat4("model", transform);
    squaremesh.Draw(shader);

    transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(-30.0f, -4.5f, 20.0f));
    transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
    transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", transform);
    squaremesh.Draw(shader);
    //west stairs
    transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(-83.5f, -4.0f, -35.0f));
    transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
    transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", transform);
    squaremesh.Draw(shader);
    //str
    transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(-80.0f, 0.5f, -35.0f));
    transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
    transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.setMat4("model", transform);
    squaremesh.Draw(shader);
    //
    transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(-85.0f, -4.5f, -35.0f));
    transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
    transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", transform);
    squaremesh.Draw(shader);
    //north stairs
    transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(-30.0f, -4.0f, -89.0f));
    transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
    transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.setMat4("model", transform);
    squaremesh.Draw(shader);
    //str
    transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(-30.0f, 0.5f, -85.0f));
    transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
    transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.setMat4("model", transform);
    squaremesh.Draw(shader);

    transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(-30.0f, -4.5f, -90.0f));
    transform = glm::scale(transform, glm::vec3(10.0f, 10.0f, 10.0f));
    transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.setMat4("model", transform);
    squaremesh.Draw(shader);

}
