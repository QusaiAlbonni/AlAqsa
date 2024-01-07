#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <learnopengl/simplemesh.h>
#include <vector>
#include "texture.h"

#define PI 3.14159265359f

struct shape
{
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
	std::vector<sVertex> sVertices;
	std::vector<texture> Textures;
	shape() {};
	shape(const std::vector<float>& initVertices, const std::vector<unsigned int>& initIndices)
		: vertices(initVertices), indices(initIndices) {}

	void clearData() {
		vertices.clear();
		indices.clear();
		sVertices.clear();
		Textures.clear();
	}
};
class shapeUtils {
public:
    void  static generatePrism(std::vector<sVertex>& vertices, std::vector<unsigned int>& indices, const int sides) {
        const float height = 0.5f;
        const float radius = 0.5f;

        // Generate vertices for the top and bottom faces
        for (int i = 0; i < sides; ++i) {
            float angle = static_cast<float>(i) * (2.0f * 3.14159f) / static_cast<float>(sides);
            float x = radius * std::cos(angle);
            float z = radius * std::sin(angle);

            // Top face vertex
            vertices.push_back({ { x, height / 2.0f, z }, { 0.0f, 1.0f, 0.0f }, {  0.5f + 0.5f * std::cos(angle), 0.5f + 0.5f * std::sin(angle)}
                });

            // Bottom face vertex
            vertices.push_back({ { x, -height / 2.0f, z}, {0.0f, -1.0f, 0.0f},{0.5f + 0.5f * std::sin(angle), 0.5f + 0.5f * std::sin(angle)} });
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
    void static generateCircle(vector<sVertex>& vertices, vector<unsigned int>& indices, float radius, int vCount, glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f), bool halfCircle = false)
    {
        float angle = 360.0f / vCount;

        int triangleCount = vCount - 2;


        vertices.push_back({ center, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.5f, 1.0f) });
        // vertices
        for (int i = 0; i < vCount + 1; i++)
        {
            float currentAngle = -angle * i;
            float x = radius * cos(glm::radians(currentAngle));
            float y = radius * sin(glm::radians(currentAngle));
            float z = 0.0f;

            vertices.push_back({ glm::vec3(x, y, z), glm::vec3(0.0f, 0.0f, 1.0f),glm::vec2(static_cast<float>(i) / static_cast<float>(vCount - 1), 0.5f) });
        }
        // indices
        int i = 0;
        for (i = 0; i < ((vCount) / (halfCircle ? 2 : 1) + 2); i++)
        {
            indices.push_back(i);
        }
    }


    void static generateCylinder(float radius, float height, int sectors, int stacks,
        std::vector<sVertex>& vertices, std::vector<unsigned int>& indices, bool halfCylinder = false) {
        float sectorStep = 2 * PI / sectors;
        float stackStep = height / stacks;

        for (int i = 0; i <= stacks; ++i) {
            float y = -height / 2.0f + i * stackStep;
            float radiusCurr = radius - radius * i / stacks;

            for (int j = 0; j <= sectors; ++j) {
                float x = radius * cos(j * sectorStep);
                float z = radius * sin(j * sectorStep);

                float nx = x / radius;
                float ny = y / height;
                float nz = z / radius;

                float s = (float)j / sectors;
                float t = 1.0f - (float)i / stacks;

                vertices.push_back({ { x , y , z},{nx, ny, nz}, {s, t} });
            }
        }

        for (int i = 0; i < stacks; ++i) {
            for (int j = 0; j < sectors / (halfCylinder ? 2 : 1); ++j) {
                int k1 = i * (sectors + 1) + j;
                int k2 = k1 + 1;
                int k3 = (i + 1) * (sectors + 1) + j;
                int k4 = k3 + 1;

                indices.push_back(k1);
                indices.push_back(k3);
                indices.push_back(k2);

                indices.push_back(k2);
                indices.push_back(k3);
                indices.push_back(k4);
            }
        }
    }

    void static generateRectangle(float length, float width,
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
    void static generateRectangle1(float length, float width,
        std::vector<sVertex>& vertices,
        std::vector<unsigned int>& indices) {

        // Calculate half-length and half-width
        float halfLength = length / 2.0f;
        float halfWidth = width / 2.0f;

        // Define vertices
        vertices.push_back({ glm::vec3(halfLength, halfWidth, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.3f, 0.9f) });
        vertices.push_back({ glm::vec3(halfLength, -halfWidth, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.3f, 0.0f) });
        vertices.push_back({ glm::vec3(-halfLength, -halfWidth, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f) });
        vertices.push_back({ glm::vec3(-halfLength, halfWidth, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.9f) });

        // Define indices
        indices = { 0, 1, 3, 1, 2, 3 };
    }
    void static generateRectangle2(float length, float width,
        std::vector<sVertex>& vertices,
        std::vector<unsigned int>& indices) {

        // Calculate half-length and half-width
        float halfLength = length / 2.0f;
        float halfWidth = width / 2.0f;

        // Define vertices
        vertices.push_back({ glm::vec3(halfLength, halfWidth, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.4f) });
        vertices.push_back({ glm::vec3(halfLength, -halfWidth, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f) });
        vertices.push_back({ glm::vec3(-halfLength, -halfWidth, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f) });
        vertices.push_back({ glm::vec3(-halfLength, halfWidth, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.4f) });

        // Define indices
        indices = { 0, 1, 3, 1, 2, 3 };
    }
    void static generateSphere(vector<sVertex>& vertices, vector<unsigned int>& indices, bool hemisphereFlag = false)
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
};
#endif