
#include"texture.h"
#include "GameLoop.h"
#include "lighting.h"
#include"MosqueCarbet.h"
float width = 1.0f;
float height = 1.0f;
MosqueCarbet::MosqueCarbet(Shader shader) :object_(shader) {
    init();
}
void MosqueCarbet::init() {
    texture floor1("res/textures/MosqueCarbet/prayercarpter_AmbientOcclusion.jpg", "material.ambient");
    texture floor2("res/textures/MosqueCarbet/prayercarpter_Normal.jpg", "material.normal");
    texture floor3("res/textures/MosqueCarbet/prayercarpter_Roughness.jpg", "material.specular");
    texture floor4("res/textures/MosqueCarbet/prayercarpter_BaseColor.jpg", "material.diffuse");
    texture floor5("res/textures/MosqueCarbet/prayercarpter_Height.jpg", "material.height");
    vector<sTexture> texts = { floor1.info,floor2.info ,floor3.info, floor4.info, floor5.info };
    shapeUtils::generateRectangle(width, height, square.sVertices, square.indices);
    squareMesh = Simplemesh(square.sVertices, square.indices, texts);
}
void MosqueCarbet::Draw() {
    glm::mat4 trans(1.0f);
    trans = glm::translate(trans, glm::vec3(-29.6f,  1.1f, -17.4f));
    //trans = glm::rotate(trans, glm::radians(360.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    //trans = glm::rotate(trans, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    shader.setMat4("model", trans);
    glm::mat4 scalemat = glm::scale(glm::mat4(1), glm::vec3(1.0f, 1.0f, 1.0f));
    drawMeshes(trans, scalemat);

}
void MosqueCarbet::drawMeshes(glm::mat4 transform, glm::mat4 scaleMat4) {
    glm::mat4 trans = transform;
    shader.use();
    //transform = glm::mat4(1.0f);
    //transform = transform * trans;
    ////transform = glm::translate(transform, glm::vec3(-10.0f, 0.0f, -20.0f));
    //transform = glm::rotate(transform ,glm::radians(90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
    //shader.setMat4("model", transform);
    //squareMesh.Draw(shader);
    float x = 0.0f;
    float z = 0.0f;
    for (size_t i = 0; i < 22; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-28.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 24; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }

    //3
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-27.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 26; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //4
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-26.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 28; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));

        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //5
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-25.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 30; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }

    //6
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-24.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 32; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }

    //7
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-23.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 34; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //8
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-22.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 36; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //9
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-21.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 38; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //10
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-20.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 40; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }

    //10
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-19.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 42; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //11
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-18.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 44; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //12
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-17.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 46; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //13
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-17.2f, 1.1f, -17.4f));
    for (size_t i = 0; i < 47; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //14
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-16.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 48; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //15
    for (size_t i = 0; i < 18; i++)
    {
        x = 0.0f;
        z -= 1.0f;
        trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(-17.3f, 1.1f, -17.4f));
        for (size_t i = 0; i < 47; i++)
        {
            transform = glm::mat4(1.0f);
            transform = transform * trans;
            transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
            transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
            transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
            shader.setMat4("model", transform);
            squareMesh.Draw(shader);
            x -= 1.0f;
        }
    }
    //14*2
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-17.6f, 1.1f, -17.4f));
    for (size_t i = 0; i < 46; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //9
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-18.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 44; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //10
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-19.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 42; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-20.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 40; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //6
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-21.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 38; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }

    //5
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-22.6f, 1.1f, -17.4f));
    for (size_t i = 0; i < 36; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //5
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-23.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 34; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //5
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-24.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 32; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //5
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-25.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 30; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    //3
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-26.6f, 1.1f, -17.4f));
    for (size_t i = 0; i < 28; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }

    //3
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-27.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 26; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-28.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 24; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-29.4f, 1.1f, -17.4f));
    for (size_t i = 0; i < 22; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }
    x = 0.0f;
    z -= 1.0f;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-30.5f, 1.1f, -17.4f));
    for (size_t i = 0; i < 20; i++)
    {
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(x, 0.0f, z));
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(-90.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.setMat4("model", transform);
        squareMesh.Draw(shader);
        x -= 1.0f;
    }

}