#pragma once
#include "object_.h"
#include <learnopengl/simplemesh.h>
#include <learnopengl/shape.h>

class Mirror :
    public object_
{
public:

    unsigned int envMap;
    Shader mirrorShader;
    shape mirrorShape;
    Simplemesh mirrorMesh;
    void init() override;
    Mirror(Shader shader);
    void Draw() override;
    void drawMeshes(glm::mat4 transform, glm::mat4 scaleMat = glm::mat4(1)) override;
    void DrawDepth(Shader depthShader, bool ortho = true) override;
};

