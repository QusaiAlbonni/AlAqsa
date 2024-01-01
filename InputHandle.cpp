#include "InputHandle.h"
#include "audio.h"
#include "Collision.h"


bool spotLightKeyPressed = false;
bool nightKeyPressed = false;
bool noclipKeyPressed = false;

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

   
    float moveSpeed = (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS) ? 8.0f : 3.0f;
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            camera.ProcessKeyboard(FORWARD, deltaTime * moveSpeed);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            camera.ProcessKeyboard(BACKWARD, deltaTime * moveSpeed);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            camera.ProcessKeyboard(LEFT, deltaTime * moveSpeed);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            camera.ProcessKeyboard(RIGHT, deltaTime * moveSpeed);
        
        
        
        glm::vec3 colnorm;
        float coldepth;
        if (Collision::CollisionDetector::checkPlayerCol(colnorm, coldepth) && camera.fps)
        {
            camera.Position -= 1.1f * coldepth * colnorm;
        }
        
        
        if ((glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) ||
            (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) ||
            (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) ||
            (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS))
        {
            float delay = (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS) ? 0.3f : 0.35f;
            if ((glfwGetTime() - AudioManager::lastFootstep > delay) && camera.fps)
                AudioManager::playFootSteps();
        }
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && !spotLightKeyPressed)
    {
        spotLight = !spotLight;
        spotLightKeyPressed = true;
    }
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_RELEASE)
    {
        spotLightKeyPressed = false;
    }
    if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS && !nightKeyPressed)
    {
        night = !night;
        nightKeyPressed = true;
    }
    if (glfwGetKey(window, GLFW_KEY_N) == GLFW_RELEASE)
    {
        nightKeyPressed = false;
    }
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS && !noclipKeyPressed)
    {
        camera.fps = !camera.fps;
        noclipKeyPressed = true;
    }
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_RELEASE)
    {
        noclipKeyPressed = false;
    }

}