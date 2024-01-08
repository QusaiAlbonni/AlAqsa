#pragma once
#include "object_.h"
#include <learnopengl/shape.h>
class InnerDome :
    public object_
{
public:
    shape circle;
    Simplemesh circleMesh;
    void init() override;
    InnerDome(Shader shader);
    void Draw() override;
    void drawMeshes(glm::mat4 transform, glm::mat4 scaleMat = glm::mat4(1)) override;
    void DrawDepth(Shader depthShader, bool ortho = true) override;

};

