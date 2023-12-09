#include "Time.h"

float deltaTime = 0.0f;
float lastFrame = 0.0f;

void refreshTime() {
    float currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}