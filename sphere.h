#pragma once
#include "shape.h"

void buildSphere(vector<sVertex>& vertices, vector<unsigned int>& indices, bool hemisphereFlag = false)
{
    const unsigned int X_SEGMENTS = 64;
    const unsigned int Y_SEGMENTS = 64;
    for (unsigned int x = 0; x <= X_SEGMENTS; ++x)
    {
        for (unsigned int y = 0; y <= Y_SEGMENTS; ++y)
        {
            float xSegment = (float)x / (float)X_SEGMENTS;
            float ySegment = (float)y / (float)Y_SEGMENTS;
            float xPos = std::cos(xSegment * 2.0f * PI) * std::sin(ySegment * PI);
            float yPos = std::cos(ySegment * PI);
            float zPos = std::sin(xSegment * 2.0f * PI) * std::sin(ySegment * PI);

            vertices.push_back({ glm::vec3(xPos, yPos, zPos), glm::vec3(xPos, yPos, zPos), glm::vec2(xSegment, ySegment) });
        }
    }

    bool oddRow = false;
    for (unsigned int y = 0; y < Y_SEGMENTS; ++y)
    {
        int limit = hemisphereFlag ? X_SEGMENTS / 2 : X_SEGMENTS;
            if (!oddRow) // even rows: y == 0, y == 2; and so on
            {

                
                for (unsigned int x = 0; x <= limit; ++x)
                {
                    
                        indices.push_back(y * (X_SEGMENTS + 1) + x);
                        indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
                }
            }
            else
            {
                for (int x = X_SEGMENTS; x >= 0; --x)
                {
                    if (x < limit) {
                        indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
                        indices.push_back(y * (X_SEGMENTS + 1) + x);
                    }
                }
            }
            oddRow = !oddRow;
        
    }

}