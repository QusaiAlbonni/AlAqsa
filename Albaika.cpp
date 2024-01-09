
#include"texture.h"
#include "utils.h"
#include"Albaika.h"
float Albaika::width = 1.6f;
float Albaika::height = 9.0f;
Albaika::Albaika(Shader shader) :object_(shader) {
    init();
}
void Albaika::init(){

    shapeUtils::generateRectangle(14.0, 4, rect.sVertices, rect.indices);
    texture Diffuse("res/textures/baika/byk.png", "material.diffuse", GL_RGBA, GL_SRGB8_ALPHA8);
    texture nor("res/textures/baika/byk_Normal.png", "material.normal");
    texture ao("res/textures/baika/byk_AmbientOcclusion.png", "material.ambient");
    texture rough("res/textures/baika/byk_Roughness.png", "material.height");

    vector<sTexture> albaikatexts = {
        Diffuse.info,
        nor.info,
        ao.info,
        rough.info
    };
    rectmesh = Simplemesh(rect.sVertices, rect.indices, albaikatexts);


    texture floor4("res/textures/baika/diffuse.jpg", "material.diffuse",GL_RGB,GL_SRGB);
    texture floor1("res/textures/baika/ao.jpg", "material.ambient");
    texture floor2("res/textures/baika/normal.jpg", "material.normal");
    texture floor3("res/textures/baika/rough.jpg", "material.specular");
 
    vector<sTexture> texts = { floor1.info,floor2.info ,floor3.info, floor4.info};
    shapeUtils::generateRectangle(width, height, albaikaRec.sVertices, albaikaRec.indices);
    albaikaRecmesh= Simplemesh(albaikaRec.sVertices, albaikaRec.indices,texts);

    shapeUtils::generateCylinder(0.4, 7,100,50,baikCyl.sVertices,baikCyl.indices);
    baikCylmesh = Simplemesh(baikCyl.sVertices, baikCyl.indices,texts);

    shapeUtils::generateRectangle(1.6f, 10.8f, toprect.sVertices, toprect.indices);
    toprectmesh = Simplemesh(toprect.sVertices, toprect.indices, texts);
}
void Albaika::Draw() {
    shader.use();
    glm::mat4 transform(1.0f);
    transform = glm::translate(transform, glm::vec3(0.0f, ((height / 2)+1), 0.0f));
    shader.setMat4("model", transform);
    glm::mat4 scalemat = glm::scale(glm::mat4(1), glm::vec3(1.0f, 1.0f, 1.0f));
    drawMeshes(transform,scalemat);

}

void Albaika::DrawDepth(Shader depthShader, bool ortho) {
    Shader temp = shader;
    shader = depthShader;
    glm::mat4 transform(1.0f);
    transform = glm::translate(transform, glm::vec3(0.0f, ((height / 2) + 1), 0.0f));
    shader.setMat4("model", transform);
    glm::mat4 scalemat = glm::scale(glm::mat4(1), glm::vec3(1.0f, 1.0f, 1.0f));
    drawMeshes(transform, scalemat);
    shader = temp;
}
void Albaika::drawMeshes(glm::mat4 transform, glm::mat4 scaleMat4) {

    shader.use();
    float translateX = 0.0f;
    float translateY = 0.0f;
    float translateZ = 0.0f;

    glm::mat4 trans(1.0f);
    trans = glm::translate(trans, glm::vec3(-36.0f, 5.4f, 16.0f));
    for (size_t i = 0; i < 2; i++)
    {
 
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(0.0f + translateX, 0.0f + translateY, 0.0f + translateZ));
        transform = transform * scaleMat4;
        shader.setMat4("model", transform);
        albaikaRecmesh.Draw(shader,5);


       
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(0.0f + translateX, 0.0f + translateY, width + translateZ));
        transform = transform * scaleMat4;

         
        transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.setMat4("model", transform);
        albaikaRecmesh.Draw(shader,5);


     
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(width / 2 + translateX, 0.0f + translateY, (width / 2) + translateZ));
        transform = transform * scaleMat4;
        transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.setMat4("model", transform);
        albaikaRecmesh.Draw(shader,5);

 
        transform = glm::mat4(1.0f);
        transform = transform * trans;
        transform = glm::translate(transform, glm::vec3(-(width/2) + translateX, 0.0f + translateY, (width/2) + translateZ));
        transform = transform * scaleMat4;
        transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.setMat4("model", transform);
        albaikaRecmesh.Draw(shader);
 
        translateX += (width +  10.8f);
        translateY += (0.0f);
        translateZ += 0.0f;
        glm::mat4 top(1.0f);
        top = top * trans;
        top = glm::translate(top, glm::vec3(6.0f, 3.5f, 0.8f));
        top = glm::rotate(top, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        top = glm::rotate(top, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        shader.setMat4("model", top);
        toprectmesh.Draw(shader);

    }
    float x = 0.0f;
    glm::mat4 cylinder(1.0f);
    for (int i = 0;i < 2;i++) {
        glm::mat4 cylinder(1.0f);
        cylinder = cylinder ;
        cylinder = glm::translate(cylinder, glm::vec3(-31.7f+x, 4.0f, 17.0f));
        shader.setMat4("model", cylinder);
        baikCylmesh.Draw(shader);
        x += 3.75;

        
    }
   for(int i=0;i<2;i++) {
       if (i != 0) {
           glm::mat4 Rect(1.0f);
           Rect = glm::translate(Rect, glm::vec3(-29.82f, 8.0f, 17.61f));
           Rect = glm::rotate(Rect, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
           shader.setMat4("model", Rect);
           rectmesh.Draw(shader);
       }
       else {
           glm::mat4 Rect(1.0f);
           Rect = glm::translate(Rect, glm::vec3(-29.82f, 8.0f, 15.99f));
           shader.setMat4("model", Rect);
           rectmesh.Draw(shader);
       }
    }
   ////////////////////////////////////
   float translateX2 = 0.0f;
   float translateY2 = 0.0f;
   float translateZ2 = 0.0f;

   glm::mat4 trans2(1.0f);
   trans2 = glm::translate(trans2, glm::vec3(-36.0f, 5.4f, -88.5f));
   for (size_t i = 0; i < 2; i++)
   {

       transform = glm::mat4(1.0f);
       transform = transform * trans2;
       transform = glm::translate(transform, glm::vec3(0.0f + translateX2, 0.0f + translateY2, 0.0f + translateZ2));
       transform = transform * scaleMat4;
       shader.setMat4("model", transform);
       albaikaRecmesh.Draw(shader, 5);



       transform = glm::mat4(1.0f);
       transform = transform * trans2;
       transform = glm::translate(transform, glm::vec3(0.0f + translateX2, 0.0f + translateY2, width + translateZ2));
       transform = transform * scaleMat4;


       transform = glm::rotate(transform, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
       shader.setMat4("model", transform);
       albaikaRecmesh.Draw(shader, 5);



       transform = glm::mat4(1.0f);
       transform = transform * trans2;
       transform = glm::translate(transform, glm::vec3(width / 2 + translateX2, 0.0f + translateY2, (width / 2) + translateZ2));
       transform = transform * scaleMat4;
       transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
       shader.setMat4("model", transform);
       albaikaRecmesh.Draw(shader, 5);


       transform = glm::mat4(1.0f);
       transform = transform * trans2;
       transform = glm::translate(transform, glm::vec3(-(width / 2) + translateX2, 0.0f + translateY2, (width / 2) + translateZ2));
       transform = transform * scaleMat4;
       transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
       shader.setMat4("model", transform);
       albaikaRecmesh.Draw(shader);

       translateX2 += (width + 10.8f);
       translateY2 += (0.0f);
       translateZ2 += 0.0f;
       glm::mat4 top(1.0f);
       top = top * trans2;
       top = glm::translate(top, glm::vec3(6.0f, 3.5f, 0.8f));
       top = glm::rotate(top, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
       top = glm::rotate(top, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
       shader.setMat4("model", top);
       toprectmesh.Draw(shader);
   }
   float southX = 0.0f;
  
   for (int i = 0;i < 2;i++) {
       glm::mat4 cylinder(1.0f);
       cylinder = cylinder;
       cylinder = glm::translate(cylinder, glm::vec3(-31.7f + southX, 4.0f, -88.0f));
       shader.setMat4("model", cylinder);
       baikCylmesh.Draw(shader);
       southX += 3.75;


   }
   for (int i = 0;i < 2;i++) {
       if (i != 0) {
           glm::mat4 Rect(1.0f);
           Rect = glm::translate(Rect, glm::vec3(-29.82f, 8.0f, -86.8f));
           Rect = glm::rotate(Rect, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
           shader.setMat4("model", Rect);
           rectmesh.Draw(shader);
       }
       else {
           glm::mat4 Rect(1.0f);
           Rect = glm::translate(Rect, glm::vec3(-29.82f, 8.0f, -88.51f));
           shader.setMat4("model", Rect);
           rectmesh.Draw(shader);
       }
   }
}

