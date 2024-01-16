#pragma once

#include <learnopengl/shape.h>
#include <learnopengl/simplemesh.h>
#include <glm/gtc/noise.hpp>
#include "lighting.h"
#include "utils.h"


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
            float elevation;
            elevation = glm::perlin(glm::vec2(xPos * 0.2f, zPos * 0.2f)) * 0.30f;
            vertices.push_back({{ xPos, elevation, zPos }, { 0.0f, 1.0f, 0.0f }, { xPos / 6 , zPos / 6}
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

    texture Text2("res/textures/rocky_trail_diff.jpg",  "material.diffuse", GL_RGB, GL_SRGB);
    texture Text3("res/textures/rocky_trail_spec.jpg", "material.specular");
    texture Text7("res/textures/rocky_trail_rough.jpg", "material.rough");
    texture Text4("res/textures/rocky_trail_nor.jpg","material.normal");
    texture Text5("res/textures/rocky_trail_ao.jpg","material.ambient");
    texture Text8("res/textures/rocky_trail_arm.jpg", "material.metallic");
    texture Text6("res/textures/rocky_trail_disp.jpg", "material.height");
    vector<sTexture> texts2 = { Text2.info , Text3.info, Text4.info , Text5.info, Text6.info, Text7.info , Text8.info};

    generateTerrain(terrain.sVertices, terrain.indices, 200, 300, 1.0f);

    Simplemesh myterrain(terrain.sVertices, terrain.indices, texts2);
    terrain.clearData();
    return myterrain;
}
void drawTerrain(Simplemesh terrain, Shader dshader, unsigned int depthmap, unsigned int depth2) {
    
    addDirectionalLight(dshader);
    addPointLight(dshader, domePointlightPos);
    glm::vec3 spot(45.0f, 10.0f, 40.0f);
    glm::vec3 tar(35.0f, 10.0f, 40.0f);
    addSpotLight(dshader);
    // material properties
    dshader.setFloat("material.shininess", 32.0f);
    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
    setMVP(dshader, transform);
    terrain.Draw(dshader, GL_TRIANGLES, depthmap, depth2);
}

