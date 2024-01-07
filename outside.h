#pragma once
#include "object_.h"
#include "utils.h"
#include "lighting.h"
#include <learnopengl/shape.h>
class outside :public object_
{
public:

    shape square;
    Simplemesh squarem;
    shape squareF;
    Simplemesh squaremF;
    shape squareRoad;
    Simplemesh squareRoad1;
    shape squareRoads;
    Simplemesh squareRoad2;
    shape cylendr;
    Simplemesh cylendrm;
    shape cylendrQ;
    Simplemesh cylendrQm;
    shape circle;
    Simplemesh circlem;
    shape carbit;
    Simplemesh carbitm;
    shape grass;
    Simplemesh grassm;
    outside(Shader shader);
    void init() override;
    void Draw() override;
    void drawMeshes(glm::mat4 transform, glm::mat4 scaleMat = glm::mat4(1)) override;
    void DrawDepth(Shader depthShader, bool ortho = true) override;
};

