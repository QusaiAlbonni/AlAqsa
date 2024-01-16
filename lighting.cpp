#include "lighting.h"
#include "imageloader.h"
#include <SOIL2/SOIL2.h>

void addDirectionalLight(Shader shader, glm::vec3 lightDirection) {
    shader.use();
    shader.setVec3("light.direction", lightDirection);
    shader.setVec3("viewPos", camera.Position);

    // light properties
    if (!night)
    {
        if (pbr) {
            shader.setVec3("light.ambient", 5, 5, 4);
            shader.setVec3("light.diffuse", 8, 8, 7);
        }
        else{
            shader.setVec3("light.ambient", 0.14f, 0.14f, 0.14f);
            shader.setVec3("light.diffuse", 0.9f, 0.9f, 0.9f);
        }
        shader.setVec3("light.specular", 0.3f, 0.3f, 0.2f);
    }
    else {
        if (pbr) {
            shader.setVec3("light.ambient", 0.1, 0.1, 0.2f);
            shader.setVec3("light.diffuse", 0.5, 0.5, 0.75);
        }
        else {
            shader.setVec3("light.ambient", 0.0028f, 0.0028f, 0.028f);
            shader.setVec3("light.diffuse", 0.04f, 0.04f, 0.1f);
        }
        shader.setVec3("light.specular", 0.06f, 0.06f, 0.06f);
    }
}

void addPointLight(Shader lightingShader, glm::vec3 lightPos) {
    if (lightPos == mosquePointlightPos)
    {
        lightingShader.setVec3("point.position", lightPos);
        lightingShader.setVec3("viewPos", camera.Position);
        if (pbr)
        {
            lightingShader.setVec3("point.ambient", 60, 60, 50);
            lightingShader.setVec3("point.diffuse", 200, 200, 150);
        }
        else {
            lightingShader.setVec3("point.ambient", 0.3, 0.3, 0.2);
            lightingShader.setVec3("point.diffuse", 0.9, 0.9, 0.7);
        }
            lightingShader.setVec3("point.specular", 0.2f, 0.2f, 0.2f);
            lightingShader.setFloat("point.constant", 1.0f);
        if(pbr)
        {
            lightingShader.setFloat("point.linear", 0.14f);
            lightingShader.setFloat("point.quadratic", 0.07f);
        }
        else 
        {
            lightingShader.setFloat("point.linear", 0.00000014f);
            lightingShader.setFloat("point.quadratic", 0.007f);
        }
    }
    else if (lightPos == domePointlightPos) {
        lightingShader.setVec3("point.position", lightPos);
        lightingShader.setVec3("viewPos", camera.Position);
        if(pbr)
        {
        lightingShader.setVec3("point.ambient", 60, 60, 50);
        lightingShader.setVec3("point.diffuse", 200, 200, 150);
        }
        else {
            lightingShader.setVec3("point.ambient", 0.3, 0.3, 0.2);
            lightingShader.setVec3("point.diffuse", 0.9, 0.9, 0.7);
        }
        lightingShader.setVec3("point.specular", 0.2f, 0.2f, 0.2f);
        lightingShader.setFloat("point.constant", 1.0f);
        if (pbr) {
            lightingShader.setFloat("point.linear", 0.14f);
            lightingShader.setFloat("point.quadratic", 0.014f);
        }
        else {
            lightingShader.setFloat("point.linear", 0.0000014f);
            lightingShader.setFloat("point.quadratic", 0.014f);
        }
    }
    else {
        lightingShader.setVec3("point.position", lightPos);
        lightingShader.setVec3("viewPos", camera.Position);
        if (pbr) {
            lightingShader.setVec3("point.ambient", 50, 50, 40);
            lightingShader.setVec3("point.diffuse", 150, 150, 110);
        }
        else {
            lightingShader.setVec3("point.ambient", 0.3f, 0.3f, 0.3f);
            lightingShader.setVec3("point.diffuse", 0.9f, 0.9f, 0.7f);
        }
        lightingShader.setVec3("point.specular", 0.2f, 0.2f, 0.2f);
        lightingShader.setFloat("point.constant", 1.0f);
        if (pbr) {
            lightingShader.setFloat("point.linear", 0.32f);
            lightingShader.setFloat("point.quadratic", 0.014f);
        }
        else {
            lightingShader.setFloat("point.linear", 0.14f);
            lightingShader.setFloat("point.quadratic", 0.014f);
        }
    }
    if (!night)
    {
        lightingShader.setVec3("point.position", lightPos);
        lightingShader.setVec3("viewPos", camera.Position);
        lightingShader.setVec3("point.ambient", 0.0f, 0.0f, 0.0f);
        lightingShader.setVec3("point.diffuse", 0.0f, 0.0f, 0.0f);
        lightingShader.setVec3("point.specular", 0.0f, 0.0f, 0.0f);
        lightingShader.setFloat("point.constant", 1.0f);
        lightingShader.setFloat("point.linear", 0.14f);
        lightingShader.setFloat("point.quadratic", 0.014f);
    }
}

void addSpotLight(Shader lightingShader, glm::vec3 lightPos, glm::vec3 direction) {
    lightingShader.setVec3("spotLight.position", lightPos);
    lightingShader.setVec3("viewPos", camera.Position);
    lightingShader.setVec3("spotLight.direction", direction);
    lightingShader.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
    lightingShader.setVec3("spotLight.diffuse", 0.7f, 0.7f, 0.7f);
    lightingShader.setVec3("spotLight.specular", 0.4f, 0.4f, 0.4f);
    lightingShader.setFloat("spotLight.constant", 1.0f);
    lightingShader.setFloat("spotLight.linear", 0.09f);
    lightingShader.setFloat("spotLight.quadratic", 0.032f);
    lightingShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    lightingShader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
}

unsigned int enviromentMap(bool day)
{
    vector<std::string> faces;
    if (day)
    {
        faces =
        {
            "res/textures/envMapDay/left.jpg",
            "res/textures/envMapDay/right.jpg",
            "res/textures/envMapDay/top.jpg",
            "res/textures/envMapDay/bottom.jpg",
            "res/textures/envMapDay/back.jpg",
            "res/textures/envMapDay/front.jpg",
        };

    }
    else {
        faces =
        {
            "res/textures/envMap/left.jpg",
            "res/textures/envMap/right.jpg",
            "res/textures/envMap/top.jpg",
            "res/textures/envMap/bottom.jpg",
            "res/textures/envMap/back.jpg",
            "res/textures/envMap/front.jpg",
        };
    }
    unsigned int cubemapTexture = loadEnvCubemap(faces);

    return cubemapTexture;
}


unsigned int loadEnvCubemap(vector<std::string> faces)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    int width, height, nrChannels;
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        stbi_set_flip_vertically_on_load(false);
        unsigned char* data = SOIL_load_image(faces[i].c_str(), &width, &height, &nrChannels, SOIL_LOAD_AUTO);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_SRGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            SOIL_free_image_data(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
            SOIL_free_image_data(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
}