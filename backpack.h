#pragma once
#include "object_.h"
#include "lighting.h"
#include "utils.h"
class backpack :
    public object_
{
public:
    Model model;

    void init() override;
    backpack(Shader shader);
    void Draw() override;
    void drawMeshes(glm::mat4 transform, glm::mat4 scaleMat = glm::mat4(1)) override;
    void DrawDepth(Shader depthShader, bool ortho = true) override;
};

