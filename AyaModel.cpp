#include "AyaModel.h"
#include"texture.h"
#include "GameLoop.h"
#include "lighting.h"


AyaModel::AyaModel(Shader shader) : object_(shader), tree("res/models/Tree 02/Tree.obj")

{
	init();
}
void AyaModel::init() {
   
}

void AyaModel::Draw() {
	glm::mat4 transform(1.0f);
	transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
	setMVP(shader);
    drawMeshes(transform);

}
void AyaModel::DrawDepth(Shader depthShader, bool ortho) {
    Shader temp = shader;
    shader = depthShader;
    glm::mat4 transform(1.0f);
    transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
    setMVP(shader);
    drawMeshes(transform);
    shader = temp;
}
//This is to draw scene for depth map (shadow map)
//void AyaModel::DrawDepth(Shader depthShader, bool ortho)
//{
//    Shader temp = shader;
//    shader = depthShader;
//    glm::mat4 transform(1);
//    transform = glm::translate(transform, glm::vec3(-40.0f, 0.0f, -40.0f));
//    drawMeshes(transform);
//    shader = temp;
//}

void AyaModel::drawMeshes(glm::mat4 transform, glm::mat4 scaleMat) {

    shader.use();
    using namespace glm;

    //side left
    float trz = 5.0f;
    float trx = 0.0f;
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                glm::mat4 tree1 = glm::mat4(1.0f) * transform;
                tree1 = glm::translate(tree1, glm::vec3(-96.0f + trx, 0.0f, -100.0f + trz));
                tree1 = glm::scale(tree1, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
                shader.setMat4("model", tree1);
                tree.Draw(shader);
                trx += 10.0f;
            }
            // Reset X-axis offset for the next iteration of the outer loop
            trx = 0.05f;
            // Adjust Z-axis offset for the next iteration
            trz += 15.0f;
        }

        // After completing the double loop, add an offset on Z-axis for the next repetition
        transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 7.0f));


    }
    //side right 
    trz = 5.0f;
    trx = 0.0f;
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                glm::mat4 tree6 = glm::mat4(1.0f) * transform;
                tree6 = glm::translate(tree6, glm::vec3(30.0f + trx, 0.0f, -113.0f + trz));
                tree6 = glm::scale(tree6, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
                shader.setMat4("model", tree6);
                tree.Draw(shader);
                trx += 17.0f;
            }

            // Reset X-axis offset for the next iteration of the outer loop
            trx = 0.05f;

            // Adjust Z-axis offset for the next iteration
            trz += 15.0f;
        }

        // After completing the double loop, add an offset on Z-axis for the next repetition
        transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 7.0f));

    }
    //side right 2
    trz = 5.0f;
    trx = 0.0f;
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                glm::mat4 tree6 = glm::mat4(1.0f) * transform;
                tree6 = glm::translate(tree6, glm::vec3(67.0f + trx, 0.0f, -160.0f + trz));
                tree6 = glm::scale(tree6, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
                shader.setMat4("model", tree6);
               //  tree.Draw(shader);
                trx += 17.0f;
            }

            // Reset X-axis offset for the next iteration of the outer loop
            trx = 0.05f;

            // Adjust Z-axis offset for the next iteration
            trz += 15.0f;
        }

        // After completing the double loop, add an offset on Z-axis for the next repetition
        transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 8.0f));

    }

    //side top side 1
    trz = 0.0f;
    trx = 5.0f;
    for (int k = 0; k < 4; k++) {
       for (int i = 0; i < 2; i++) {
            trz = 0;
            for (int j = 0; j < 2; j++) {
                glm::mat4 tree3 = glm::mat4(1.0f) * transform;
                tree3 = glm::translate(tree3, glm::vec3(-95.0f + trx, 0.0f, -196.0f+ trz));
                tree3 = glm::scale(tree3, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
                shader.setMat4("model", tree3);
                tree.Draw(shader);
                trz += 15.0f;
            }

       // Adjust x-axis offset for the next iteration
            trx += 15.0f;

        }

     // After completing the double loop, add an offset on Z-axis for the next repetition
        transform = glm::translate(transform, glm::vec3(7.0f, 0.0f, 0.0f));
   }

    //side top 2
    trz = 0.0f;
    trx = 5.0f;
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < 2; i++) {
            trz = 0;
            for (int j = 0; j < 2; j++) {
                glm::mat4 tree5 = glm::mat4(1.0f) * transform;
                tree5 = glm::translate(tree5, glm::vec3(-125.0f + trx, 0.0f, -230.0f + trz));
                tree5 = glm::scale(tree5, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
                shader.setMat4("model", tree5);
              //  tree.Draw(shader);
                trz += 15.0f;
           }

    //        // Adjust Z-axis offset for the next iteration
            trx += 15.0f;

        }

    //    // After completing the double loop, add an offset on Z-axis for the next repetition
       transform = glm::translate(transform, glm::vec3(7.0f, 0.0f, 0.0f));

    }

         //side bottom
             trz = 0.0f;
             trx = 5.0f;
            for (int k = 0; k < 2; k++) {
               for (int i = 0; i < 3; i++) {
                    trz = 0;
                    for (int j = 0; j < 3; j++) {
                        glm::mat4 tree4 = glm::mat4(1.0f) * transform;
                        tree4 = glm::translate(tree4, glm::vec3(-130.0f + trx, 0.0f,-67.0f + trz));
                         tree4 = glm::scale(tree4, glm::vec3(2.0f, 2.0f, 2.0f)); // Scale if needed
                        shader.setMat4("model", tree4);
                      //  tree.Draw(shader);
                        trz += 15.0f;
                   }

           // Adjust Z-axis offset for the next iteration
                   trx += 15.0f;
              }

           //After completing the double loop, add an offset on Z-axis for the next repetition
              transform = glm::translate(transform, glm::vec3(7.0f, 0.0f, 0.0f));
            }







               }

                
              





