#include"outside.h"
#include"texture.h"
#include "GameLoop.h"
#include "lighting.h"


outside::outside(Shader shader) : object_(shader)
{
    init();
}
void outside::init() {


   texture floor1("res/textures/floor/ao.jpg", "material.ambient");
    texture floor2("res/textures/floor/nor.jpg", "material.normal");
    texture floor3("res/textures/floor/rough.jpg", "material.specular");
    texture floor4("res/textures/floor/diff.jpg", "material.diffuse");
    texture floor5("res/textures/floor/height.jpg", "material.height");

    vector<sTexture> texts = { floor1.info,floor2.info ,floor3.info, floor4.info, floor5.info };
    shapeUtils::generateRectangle(27.1f, 100.0f, square.sVertices, square.indices);
    squarem = Simplemesh(square.sVertices, square.indices, texts);


    shapeUtils::generateRectangle(190.0f, 20.0f, squareF.sVertices, squareF.indices);
    squaremF = Simplemesh(squareF.sVertices, squareF.indices, texts);


    shapeUtils::generateRectangle(70.0f, 10.0f, squareRoad.sVertices, squareRoad.indices);
    squareRoad1 = Simplemesh(squareRoad.sVertices, squareRoad.indices, texts);


    shapeUtils::generateRectangle(10.0f, 80.0f, squareRoads.sVertices, squareRoads.indices);
    squareRoad2 = Simplemesh(squareRoads.sVertices, squareRoads.indices, texts);

    shapeUtils::generateCylinder(7.0f, 1.0f, 400, 100, cylendr.sVertices, cylendr.indices, false);
    cylendrm = Simplemesh(cylendr.sVertices, cylendr.indices, texts);

    shapeUtils::generateCylinder(0.5f, 15.0f, 100, 5, cylendrQ.sVertices, cylendrQ.indices, false);
    cylendrQm = Simplemesh(cylendrQ.sVertices, cylendrQ.indices, texts);

  
    shapeUtils::generateCircle(circle.sVertices, circle.indices, 7.0f, 700, { 0, 0, 0 }, false);
    circlem = Simplemesh(circle.sVertices, circle.indices, texts);

 
    texture G("res/textures/grass.png", "material.diffuse", GL_NONE, GL_SRGB_ALPHA);
    vector<sTexture> Grass = { G.info };
    shapeUtils::generateRectangle(5.0f, 5.0f, grass.sVertices, grass.indices);
    grassm = Simplemesh(grass.sVertices, grass.indices, Grass);


}

void outside::Draw() {
    glm::mat4 transform(1.0f);
    transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
    setMVP(shader);
    drawMeshes(transform);
}
//This is to draw scene for depth map (shadow map)
void outside::DrawDepth(Shader depthShader, bool ortho)
{
    Shader temp = shader;
    shader = depthShader;
    glm::mat4 transform(1);
    transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
    drawMeshes(transform);
    shader = temp;
}


void outside::drawMeshes(glm::mat4 transform, glm::mat4 scaleMat) {

    shader.use();
    using namespace glm;
    //squers
    float tri = 0.0f;
    for (int i = 0; i < 8; i++) {
        glm::mat4 square = glm::mat4(1.0f) * transform;
        square = glm::translate(square, glm::vec3(-90.0f + tri, 0.3f, 105.0f));
        square = glm::rotate(square, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        shader.setMat4("model", square);
        squarem.Draw(shader);
        tri += 25.0f;
    }

    //the front of the outsidesquare
    glm::mat4 squareF = glm::mat4(1.0f) * transform;
    squareF = glm::translate(squareF, glm::vec3(0.0f, -9.7f, 55.0f));
    shader.setMat4("model", squareF);
    squaremF.Draw(shader);




    ////Road1 side 1s 
    glm::mat4 squarfront = glm::mat4(1.0f) * transform;
    squarfront = glm::translate(squarfront, glm::vec3(-30.0f, 0.3f, 15.0f));
    squarfront = glm::rotate(squarfront, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.setMat4("model", squarfront);
    squareRoad2.Draw(shader);

    ////the left side
    glm::mat4 squarefront_l = glm::mat4(1.0f) * transform;
    squarefront_l = glm::translate(squarefront_l, glm::vec3(-25.0f, -4.7f, 40.0f));
    squarefront_l = glm::rotate(squarefront_l, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    squarefront_l = glm::rotate(squarefront_l, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", squarefront_l);
    squareRoad2.Draw(shader);

    ////the right side
    glm::mat4 squarefront_r = glm::mat4(1.0f) * transform;
    squarefront_r = glm::translate(squarefront_r, glm::vec3(-35.0f, -4.7f, 40.0f));
    squarefront_r = glm::rotate(squarefront_r, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    squarefront_r = glm::rotate(squarefront_r, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", squarefront_r);
    squareRoad2.Draw(shader);





    //Road2 side 2
    glm::mat4 squareTop = glm::mat4(1.0f) * transform;
    squareTop = glm::translate(squareTop, glm::vec3(-30.0f, 0.3f, -110.0f));
    squareTop = glm::rotate(squareTop, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.setMat4("model", squareTop);
    squareRoad2.Draw(shader);

    ////the left side
    glm::mat4 squareTop_l = glm::mat4(1.0f) * transform;
    squareTop_l = glm::translate(squareTop_l, glm::vec3(-25.0f, -4.7f, -110.0f));
    squareTop_l = glm::rotate(squareTop_l, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    squareTop_l = glm::rotate(squareTop_l, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", squareTop_l);
    squareRoad2.Draw(shader);

    ////the right side
    glm::mat4 squareTop_r = glm::mat4(1.0f) * transform;
    squareTop_r = glm::translate(squareTop_r, glm::vec3(-35.0f, -4.7f, -110.0f));
    squareTop_r = glm::rotate(squareTop_r, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    squareTop_r = glm::rotate(squareTop_r, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", squareTop_r);
    squareRoad2.Draw(shader);



    //Road2
    glm::mat4 squareleft = glm::mat4(1.0f) * transform;
    squareleft = glm::translate(squareleft, glm::vec3(45.0f, 0.3f, -35.0f));
    squareleft = glm::rotate(squareleft, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    squareleft = glm::scale(squareleft, glm::vec3(1.40f, 1.0f, 1.0f)); // Scale if needed
    shader.setMat4("model", squareleft);
    squareRoad1.Draw(shader);
    //THE LEFT squar of side two
    glm::mat4 squareleft_l = glm::mat4(1.0f) * transform;
    squareleft_l = glm::translate(squareleft_l, glm::vec3(45.0f, -4.7f, -40.0f));
    squareleft_l = glm::scale(squareleft_l, glm::vec3(1.40f, 1.0f, 1.0f)); // Scale if needed
    shader.setMat4("model", squareleft_l);
    squareRoad1.Draw(shader);

    //THE right squar of side two
    glm::mat4 squareleft_r = glm::mat4(1.0f) * transform;
    squareleft_r = glm::translate(squareleft_r, glm::vec3(45.0f, -4.7f, -30.0f));
    squareleft_r = glm::scale(squareleft_r, glm::vec3(1.40f, 1.0f, 1.0f)); // Scale if needed
    shader.setMat4("model", squareleft_r);
    squareRoad1.Draw(shader);


    //Road3 side 1
    glm::mat4 square_left_left = glm::mat4(1.0f) * transform;
    square_left_left = glm::translate(square_left_left, glm::vec3(60.0f, 0.3f, 12.5f));
    square_left_left = glm::scale(square_left_left, glm::vec3(1.0f, 1.0f, 1.063f));
    square_left_left = glm::rotate(square_left_left, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.setMat4("model", square_left_left);
    squareRoad2.Draw(shader);

    ////the left side
    glm::mat4 square_left_left_l = glm::mat4(1.0f) * transform;
    square_left_left_l = glm::translate(square_left_left_l, glm::vec3(55.0f, -4.7f, 10.0f));
    square_left_left_l = glm::scale(square_left_left_l, glm::vec3(1.0f, 1.0f, 1.125f));
    square_left_left_l = glm::rotate(square_left_left_l, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    square_left_left_l = glm::rotate(square_left_left_l, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", square_left_left_l);
    squareRoad2.Draw(shader);

    ////the right side
    glm::mat4 square_left_left_r = glm::mat4(1.0f) * transform;
    square_left_left_r = glm::translate(square_left_left_r, glm::vec3(65.0f, -4.7f, 10.0f));
    square_left_left_r = glm::scale(square_left_left_r, glm::vec3(1.0f, 1.0f, 1.125f));
    //transform = glm::scale(transform, glm::vec3(3.0f, 3.0f, 3.0f));
    square_left_left_r = glm::rotate(square_left_left_r, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    square_left_left_r = glm::rotate(square_left_left_r, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", square_left_left_r);
    squareRoad2.Draw(shader);


    //Road 4
    glm::mat4 square_left_right = glm::mat4(1.0f) * transform;
    square_left_right = glm::translate(square_left_right, glm::vec3(60.0f, 0.3f, -80.0f));
    // transform = glm::scale(transform, glm::vec3(5.0f, 10.0f, 5.0f));
    square_left_right = glm::rotate(square_left_right, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.setMat4("model", square_left_right);
    squareRoad2.Draw(shader);

    ////the left side
    glm::mat4 square_left_right_l = glm::mat4(1.0f) * transform;
    square_left_right_l = glm::translate(square_left_right_l, glm::vec3(55.0f, -4.7f, -80.0f));
    //transform = glm::scale(transform, glm::vec3(3.0f, 3.0f, 3.0f));
    square_left_right_l = glm::rotate(square_left_right_l, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    square_left_right_l = glm::rotate(square_left_right_l, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", square_left_right_l);
    squareRoad2.Draw(shader);
    ////the right side
    glm::mat4 square_left_right_r = glm::mat4(1.0f) * transform;
    square_left_right_r = glm::translate(square_left_right_r, glm::vec3(65.0f, -4.7f, -80.0f));
    //transform = glm::scale(transform, glm::vec3(3.0f, 3.0f, 3.0f));
    square_left_right_r = glm::rotate(square_left_right_r, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    square_left_right_r = glm::rotate(square_left_right_r, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", square_left_right_r);
    squareRoad2.Draw(shader);

    //Raod 5
    glm::mat4 top_right = glm::mat4(1.0f) * transform;
    top_right = glm::translate(top_right, glm::vec3(15.0f, 0.3f, -115.0f));
    top_right = glm::scale(top_right, glm::vec3(1.145f, 1.0f, 1.0f));
    top_right = glm::rotate(top_right, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.setMat4("model", top_right);
    squareRoad1.Draw(shader);

    ////THE LEFT squar 
    glm::mat4 top_right_l = glm::mat4(1.0f) * transform;
    top_right_l = glm::translate(top_right_l, glm::vec3(15.0f, -4.7f, -120.0f));
    top_right_l = glm::scale(top_right_l, glm::vec3(1.337f, 1.0f, 1.0f));
    shader.setMat4("model", top_right_l);
    squareRoad1.Draw(shader);

    ////THE right squar 
    glm::mat4 top_right_r = glm::mat4(1.0f) * transform;
    top_right_r = glm::translate(top_right_r, glm::vec3(15.0f, -4.7f, -110.0f));
    top_right_r = glm::scale(top_right_r, glm::vec3(1.337f, 1.0f, 1.0f));
    shader.setMat4("model", top_right_r);
    squareRoad1.Draw(shader);

    //Raod 6=6 of up 
    glm::mat4 top_left = glm::mat4(1.0f) * transform;
    top_left = glm::translate(top_left, glm::vec3(-69.9f, 0.3f, -115.0f));
    //top_left = glm::scale(top_left, glm::vec3(1.3f, 1.0f, 1.0f));
    top_left = glm::rotate(top_left, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.setMat4("model", top_left);
    squareRoad1.Draw(shader);
    ////THE LEFT squar of side two
    glm::mat4 top_left_l = glm::mat4(1.0f) * transform;
    top_left_l = glm::translate(top_left_l, glm::vec3(-67.5f, -4.7f, -120.0f));
    top_left_l = glm::scale(top_left_l, glm::vec3(1.f, 1.0f, 1.0f));
    shader.setMat4("model", top_left_l);
    squareRoad1.Draw(shader);

    ////THE right squar of side two
    glm::mat4 top_left_r = glm::mat4(1.0f) * transform;
    top_left_r = glm::translate(top_left_r, glm::vec3(-67.5f, -4.7f, -110.0f));
    top_left_r = glm::scale(top_left_r, glm::vec3(1.1448f, 1.0f, 1.0f));
    shader.setMat4("model", top_left_r);
    squareRoad1.Draw(shader);


    //cylender
    glm::mat4 cyle = glm::mat4(1.0f) * transform;
    cyle = glm::translate(cyle, glm::vec3(-30.0f, 0.0f, 40.0f));
    shader.setMat4("model", cyle);
    cylendrm.Draw(shader);
    //circle
    glm::mat4 cie = glm::mat4(1.0f) * transform;
    cie = glm::translate(cie, glm::vec3(-30.0f, 0.5f, 40.0f));
    cie = glm::rotate(cie, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.setMat4("model", cie);
    circlem.Draw(shader, GL_TRIANGLE_FAN);

   
    // the column of Qibili mosque 
    float trz1 = 0.0f;
    for (int i = 0; i < 7; i++) {
        glm::mat4 cy1 = glm::mat4(1.0f) * transform;
        cy1 = glm::translate(cy1, glm::vec3(10.0f, 0.0f, 85.0f+trz1));
        shader.setMat4("model", cy1);
        //cylendrQm.Draw(shader);
        trz1 += 10.0f;
    }
    float trz2 = 0.0f;
    for (int i = 0; i < 7; i++) {
        glm::mat4 cy2 = glm::mat4(1.0f) * transform;
        cy2 = glm::translate(cy2, glm::vec3(20.0f, 0.0f, 85.0f + trz2));
        shader.setMat4("model", cy2);
        //cylendrQm.Draw(shader);
        trz2 += 10.0f;
    }
    float trz3 = 0.0f;
    for (int i = 0; i < 7; i++) {
        glm::mat4 cy3 = glm::mat4(1.0f) * transform;
        cy3 = glm::translate(cy3, glm::vec3(-20.0f, 0.0f, 85.0f + trz3));
        shader.setMat4("model", cy3);
        //cylendrQm.Draw(shader);
        trz3 += 10.0f;
    }
    float trz4 = 0.0f;
    for (int i = 0; i < 7; i++) {
        glm::mat4 cy4 = glm::mat4(1.0f) * transform;
        cy4 = glm::translate(cy4, glm::vec3(-10.0f, 0.0f, 85.0f + trz4));
        shader.setMat4("model", cy4);
        //cylendrQm.Draw(shader);
        trz4 += 10.0f;
    }
    // Grass square
     //grass top 1
 float  trx = 0.5f;
 float trz = 0.0f;

 for (int k = 0; k < 2; k++) {
     for (int i = 0; i < 19; i++) {
         trz = 0;
         for (int j = 0; j < 95; j++) {
             glm::mat4 G1 = glm::mat4(1.0f) * transform;
             G1 = glm::translate(G1, glm::vec3(-98.0f + trx, 2.0f, -110.0f + trz));
            // G1 = glm::scale(G1, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
             shader.setMat4("model", G1);
            //  grassm.Draw(shader);
             trz += 0.2f;
         }

 //        // Adjust x-axis offset for the next iteration
        trx += 1.5f;

    }

 //    // After completing the double loop, add an offset on Z-axis for the next repetition
     transform = glm::translate(transform, glm::vec3(5.0f, 0.0f, 0.0f));
 }
 ////grass top 2
   float trx1 = 0.5f;

 for (int k = 0; k < 2; k++) {
     for (int i = 0; i < 19; i++) {
         trz1 = 0;
         for (int j = 0; j < 95; j++) {
             glm::mat4 G2 = glm::mat4(1.0f) * transform;
             G2 = glm::translate(G2, glm::vec3(-109.0f + trx1, 2.0f, -140.0f + trz1));
             // G1 = glm::scale(G1, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
             shader.setMat4("model", G2);
            // grassm.Draw(shader);
             trz1 += 0.2f;
         }

 //        // Adjust x-axis offset for the next iteration
        trx1 += 1.5f;

     }

    // After completing the double loop, add an offset on Z-axis for the next repetition
 //    transform = glm::translate(transform, glm::vec3(5.0f, 0.0f, 0.0f));
 }
 // grass top left2
 float trx2 = 0.5f;

 for (int k = 0; k < 4; k++) {
     for (int i = 0; i < 19; i++) {
         trz2 = 0;
         for (int j = 0; j < 95; j++) {
             glm::mat4 G3 = glm::mat4(1.0f) * transform;
             G3 = glm::translate(G3, glm::vec3(-43.0f + trx2, 2.0f, -140.0f + trz2));
             // G1 = glm::scale(G1, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
             shader.setMat4("model", G3);
             //grassm.Draw(shader);
             trz2 += 0.2f;
         }

 //        // Adjust x-axis offset for the next iteration
         trx2 += 1.5f;

    }

 //    // After completing the double loop, add an offset on Z-axis for the next repetition
    transform = glm::translate(transform, glm::vec3(7.0f, 0.0f, 0.0f));
 //}

 // grass top left2
    float trx3 = 0.5f;
    float trz3 = 0.0f;

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 15; i++) {
            trz3 = 0;
            for (int j = 0; j < 95; j++) {
                glm::mat4 G4 = glm::mat4(1.0f) * transform;
                G4 = glm::translate(G4, glm::vec3(-72.0f + trx3, 2.0f, -110.0f + trz3));
                // G1 = glm::scale(G1, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
                shader.setMat4("model", G4);
                //  grassm.Draw(shader);
                trz3 += 0.2f;
            }

            //        // Adjust x-axis offset for the next iteration
            trx3 += 1.5f;

        }

        //    // After completing the double loop, add an offset on Z-axis for the next repetition
        transform = glm::translate(transform, glm::vec3(5, 0.0f, 0.0f));
    }
    ////grass bottm left

    float trx4 = 0.5f;
    float trz4 = 0.0f;

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < 17; i++) {
            trz4 = 0;
            for (int j = 0; j < 120; j++) {
                glm::mat4 G5 = glm::mat4(1.0f) * transform;
                G5 = glm::translate(G5, glm::vec3(-96.0f + trx4, 2.0f, 25.0f + trz4));
                // G1 = glm::scale(G1, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
                shader.setMat4("model", G5);
                //grassm.Draw(shader);
                trz4 += 0.2f;
            }

            //        // Adjust x-axis offset for the next iteration
            trx4 += 1.5f;

        }

        //    // After completing the double loop, add an offset on Z-axis for the next repetition
        transform = glm::translate(transform, glm::vec3(5.0f, 0.0f, 0.0f));
    }


    // the right of bottom
    float trx5 = 0.5f;
    float trz5 = 0.0f;

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < 19; i++) {
            trz5 = 0;
            for (int j = 0; j < 120; j++) {
                glm::mat4 G6 = glm::mat4(1.0f) * transform;
                G6 = glm::translate(G6, glm::vec3(-27.0f + trx5, 2.0f, 25.0f + trz5));
                // G1 = glm::scale(G1, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
                shader.setMat4("model", G6);
                // grassm.Draw(shader);
                trz5 += 0.2f;
            }

            //        // Adjust x-axis offset for the next iteration
            trx5 += 1.5f;

        }

        //    // After completing the double loop, add an offset on Z-axis for the next repetition
        // 
        transform = glm::translate(transform, glm::vec3(5.0f, 0.0f, 0.0f));
    }


    //the right top 1 
    float trx6 = 0.5f;
    float trz6 = 0.0f;

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 100; j++) {
                glm::mat4 G7 = glm::mat4(1.0f) * transform;
                G7 = glm::translate(G7, glm::vec3(11.0f + trx6, 2.0f, -87.0f + trz6));
                G7 = glm::scale(G7, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
                G7 = glm::rotate(G7, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                shader.setMat4("model", G7);
                // grassm.Draw(shader);
                trx6 += 0.2f;
            }

            // Reset X-axis offset for the next iteration of the outer loop
            trx6 = 0.05f;

            // Adjust Z-axis offset for the next iteration
            trz6 += 1.5f;
        }

        // After completing the double loop, add an offset on Z-axis for the next repetition
        transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 5.0f));

    }

    //the right bottom1
    float trx7 = 0.5f;
    float trz7 = 0.0f;

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 100; j++) {
                glm::mat4 G8 = glm::mat4(1.0f) * transform;
                G8 = glm::translate(G8, glm::vec3(11.0f + trx7, 2.0f, -33.0f + trz7));
                G8 = glm::scale(G8, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
                G8 = glm::rotate(G8, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                shader.setMat4("model", G8);
                // grassm.Draw(shader);
                trx7 += 0.2f;
            }

            // Reset X-axis offset for the next iteration of the outer loop
            trx7 = 0.05f;

            // Adjust Z-axis offset for the next iteration
            trz7 += 1.5f;
        }

        // After completing the double loop, add an offset on Z-axis for the next repetition
        transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 8.0f));

    }

    //the right bottom2
    float trx8 = 0.5f;
    float trz8 = 0.0f;

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 100; j++) {
                glm::mat4 G9 = glm::mat4(1.0f) * transform;
                G9 = glm::translate(G9, glm::vec3(50.0f + trx8, 2.0f, -50.0f + trz8));
                G9 = glm::scale(G9, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
                G9 = glm::rotate(G9, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                shader.setMat4("model", G9);
                //grassm.Draw(shader);
                trx8 += 0.2f;
            }

            // Reset X-axis offset for the next iteration of the outer loop
            trx8 = 0.05f;

            // Adjust Z-axis offset for the next iteration
            trz8 += 1.5f;
        }

        // After completing the double loop, add an offset on Z-axis for the next repetition
        transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 8.0f));

    }


    //the right top2
    float trx9 = 0.5f;
    float trz9 = 0.0f;

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 100; j++) {
                glm::mat4 G10 = glm::mat4(1.0f) * transform;
                G10 = glm::translate(G10, glm::vec3(50.0f + trx9, 2.0f, -100.0f + trz9));
                G10 = glm::scale(G10, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
                G10 = glm::rotate(G10, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                shader.setMat4("model", G10);
                // grassm.Draw(shader);
                trx9 += 0.2f;
            }

            // Reset X-axis offset for the next iteration of the outer loop
            trx9 = 0.05f;

            // Adjust Z-axis offset for the next iteration
            trz9 += 1.5f;
        }

        // After completing the double loop, add an offset on Z-axis for the next repetition
        transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 8.0f));

    }
   
}
}










