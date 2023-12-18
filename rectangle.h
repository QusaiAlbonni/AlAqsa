#pragma once
#include "shape.h"

bool lala = true;

void createRectangle(float length, float width,
    std::vector<sVertex>& vertices,
    std::vector<unsigned int>& indices) {

    // Calculate half-length and half-width
    float halfLength = length / 2.0f;
    float halfWidth = width / 2.0f;

    // Define vertices
    vertices.push_back({ glm::vec3(halfLength, halfWidth, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f) });
    vertices.push_back({ glm::vec3(halfLength, -halfWidth, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f) });
    vertices.push_back({ glm::vec3(-halfLength, -halfWidth, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f) });
    vertices.push_back({ glm::vec3(-halfLength, halfWidth, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f) });

    // Define indices
    indices = { 0, 1, 3, 1, 2, 3 };
}
