#pragma once
#include "object_.h"
#include <learnopengl/shape.h>
class Wall :
    public object_
{
public:

    shape wall;
    Simplemesh wallmesh;
    Model Gate;
    shape Gaterec;
    Simplemesh Gatemesh;

    shape blendTest;
    Simplemesh blendmesh;
    shape GateD;
    Simplemesh GateDmesh;
    void init() override;
    Wall(Shader shader);
    void Draw() override;
    void drawMeshes(glm::mat4 transform, glm::mat4 scaleMat = glm::mat4(1)) override;
    void DrawDepth(Shader depthShader, bool ortho = true) override;
};

