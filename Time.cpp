#include "Time.h"

float deltaTime = 0.0f;
float lastFrame = 0;
bool firstFrame = 1;

void refreshTime() {
    float currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    if (firstFrame)
    {
        deltaTime = 0;
        firstFrame = 0;
    }
    lastFrame = currentFrame;
}