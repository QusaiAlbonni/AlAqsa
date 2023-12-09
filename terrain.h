#pragma once

#include "shape.h"
#include <learnopengl/simplemesh.h>
#include <glm/gtc/noise.hpp>


shape terrain;


void generateTerrain(std::vector<sVertex>& vertices, std::vector<unsigned int>& indices, int iwidth, int iheight, float scale) {
    // Generate heightmap using Perlin noise
    float halfWidth = static_cast<float>(iwidth) / 2.0f;
    float halfHeight = static_cast<float>(iheight) / 2.0f;
    float width = static_cast<float>(iwidth);
    float height = static_cast<float>(iheight);

    for (int z =0; z < height; ++z) {
        for (int x = 0; x < width; ++x) {
            float xPos = (static_cast<float>(x) - halfWidth) * scale;
            float zPos = (static_cast<float>(z) - halfHeight) * scale;

            float elevation = glm::simplex(glm::vec2(xPos, zPos)) * 0.15f;
            vertices.push_back({{ xPos, elevation, zPos }, { 0.0f, 1.0f, 0.0f }, { xPos / 6, zPos /6 }
        });
        }
    }

    // Generate indices for the terrain grid
    for (int z = 0; z < height - 1; ++z) {
        for (int x = 0; x < width - 1; ++x) {
            int topLeft = z * width + x;
            int topRight = topLeft + 1;
            int bottomLeft = (z + 1) * width + x;
            int bottomRight = bottomLeft + 1;

            // Triangle 1
            indices.push_back(topLeft);
            indices.push_back(bottomLeft);
            indices.push_back(topRight);

            // Triangle 2
            indices.push_back(topRight);
            indices.push_back(bottomLeft);
            indices.push_back(bottomRight);
        }
    }
    
}

Simplemesh terrainSetup(Shader shader) {

    texture Text2("res/textures/rocky_trail_diff.jpg", GL_RGB, "material.diffuse", true);
    texture Text3("res/textures/rocky_trail_spec.jpg", GL_RED, "material.specular", false);
    texture Text4("res/textures/rocky_trail_nor.jpg", GL_RGB, "material.normal");
    texture Text5("res/textures/rocky_trail_ao.jpg", GL_RGB, "material.ambient");
    vector<sTexture> texts2 = { Text2.info , Text3.info, Text4.info , Text5.info };

    generateTerrain(terrain.sVertices, terrain.indices, 150, 200, 1.0f);
    Simplemesh myterrain(terrain.sVertices, terrain.indices, texts2);
    return myterrain;
}
void drawTerrain(Simplemesh terrain, Shader dshader) {
    dshader.use();
    dshader.setVec3("light.direction", -0.2f, -20.0f, -0.3f);
    dshader.setVec3("viewPos", camera.Position);

    // light properties
    dshader.setVec3("light.ambient", 0.5f, 0.5f, 0.5f);
    dshader.setVec3("light.diffuse", 0.8f, 0.8f, 0.8f);
    dshader.setVec3("light.specular", 0.4f, 0.4f, 0.4f);

    // material properties
    dshader.setFloat("material.shininess", 32.0f);
    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
    setMVP(dshader, transform);
    terrain.Draw(dshader);
}
