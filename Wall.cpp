#include "Wall.h"
#include "utils.h"
#include <learnopengl/model.h>
Wall::Wall(Shader shader) : object_(shader){
    init();
}

void Wall::init()
{ 
      shapeUtils::generateRectangle(32, 28, wall.sVertices, wall.indices);
      texture faceDiffuse("res/textures/Wall2/Wall-diff.jpg", "material.diffuse");
      texture faceAmbient("res/textures/Wall2/Wall-ao.jpg", "material.ambient");
      texture faceNormal("res/textures/Wall2/Wall-nor.jpg", "material.normal");
      texture faceHeight("res/textures/Wall2/Wall-rough.jpg", "material.height");
    vector<sTexture> cubeTextures = {
       faceDiffuse.info,
       faceAmbient.info,
       faceNormal.info,
       faceHeight.info
    };
 
    wallmesh = Simplemesh(wall.sVertices, wall.indices, cubeTextures);

}

void Wall::Draw()
{
    glm::mat4 transform(1);
    drawMeshes(transform);
    setMVP(shader);

}

void Wall::DrawDepth(Shader depthShader, bool ortho)
{
    Shader temp = shader;
    shader = depthShader;
    glm::mat4 transform(1);
    drawMeshes(transform);
    shader = temp;
}
void Wall::drawMeshes(glm::mat4 transform, glm::mat4 scaleMat)
{
    shader.use();

    float z1 = 32.0f,z2=32.0f;
    for (int i = 0;i <10;i++)
    {

        glm::mat4 right = glm::mat4(1.0f);

        right = glm::translate(right, glm::vec3(97.0f, 3.0f, -170.0f + z1));
        right = glm::rotate(right, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        z1 += 32.0f;
        shader.setMat4("model", right);
        wallmesh.Draw(shader);
    }
    
    
    for (int i = 0;i <10;i++)
    {

        glm::mat4 left = glm::mat4(1.0f);

        left = glm::translate(left, glm::vec3(-97.0f, 3.0f, -170.0f + z2));
        left = glm::rotate(left, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        z2+= 32.0f;
        shader.setMat4("model", left);
        wallmesh.Draw(shader);
    }

    float x1 = +32.0f,x2=32.0f,x3=32.0f;
    for (int i = 0;i < 7;i++)
    {

        glm::mat4 back = glm::mat4(1.0f);
        back = glm::translate(back, glm::vec3(-115.0f + x1,3.0f, 148.0f));
       
        x1 += 32.0f;
        shader.setMat4("model", back);
        wallmesh.Draw(shader);
    }
    
    
    for (int i = 0;i < 3;i++)
    {
   
         
            glm::mat4 frontL = glm::mat4(1.0f);
            frontL = glm::translate(frontL, glm::vec3(-117.0f + x2, 3.0f, -146.0f));

            x2 += 32.0f;

            shader.setMat4("model", frontL);
            wallmesh.Draw(shader);
        
    }
    for (int i = 0;i < 3;i++)
    {


        glm::mat4 frontR = glm::mat4(1.0f);
        frontR = glm::translate(frontR, glm::vec3(-11.0f + x3, 3.0f, -146.0f));

        x3 += 32.0f;

        shader.setMat4("model", frontR);
        wallmesh.Draw(shader);

    }

}

