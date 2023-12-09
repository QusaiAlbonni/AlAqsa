#pragma once
#include "shape.h"
#include <learnopengl/simplemesh.h>

shape prism;

void generateOctagonalPrism(std::vector<sVertex>& vertices, std::vector<unsigned int>& indices) {
    const int sides = 8;
    const float height = 0.5f;
    const float radius = 0.5f;

    // Generate vertices for the top and bottom faces
    for (int i = 0; i < sides; ++i) {
        float angle = static_cast<float>(i) * (2.0f * 3.14159f) / static_cast<float>(sides);
        float x = radius * std::cos(angle);
        float z = radius * std::sin(angle);

        // Top face vertex
        vertices.push_back({{ x, height / 2.0f, z }, { 0.0f, 1.0f, 0.0f }, {  i % 2 == 0? 1.0f : 0.0f, 1.0f }
    });

        // Bottom face vertex
        vertices.push_back({ { x, -height / 2.0f, z}, {0.0f, -1.0f, 0.0f},{i % 2 == 0 ? 1.0f : 0, 0.0f} });
    }

    // Generate indices for the sides
    for (int i = 0; i < sides; ++i) {
        int nextIndex = (i + 1) % sides;

        // Top face indices
        indices.push_back(i * 2);
        indices.push_back(nextIndex * 2);
        indices.push_back(nextIndex * 2 + 1);

        indices.push_back(i * 2);
        indices.push_back(nextIndex * 2 + 1);
        indices.push_back(i * 2 + 1);

        // Bottom face indices
        indices.push_back(i * 2 + 1 + sides * 2);
        indices.push_back(nextIndex * 2 + 1 + sides * 2);
        indices.push_back(nextIndex * 2 + sides * 2);

        indices.push_back(i * 2 + 1 + sides * 2);
        indices.push_back(nextIndex * 2 + sides * 2);
        indices.push_back(i * 2 + sides * 2);
    }
}