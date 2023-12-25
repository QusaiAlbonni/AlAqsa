#pragma once
#include "object_.h"
#include "lighting.h"
#include "utils.h"
#include <learnopengl/shape.h>


class Dome :
    public object_
{
public:
    shape face;
    Simplemesh faceMesh;
    shape base;
    Simplemesh baseMesh;
    shape sphere;
    Simplemesh sphereMesh;
    shape domeBase;
    Simplemesh domeBaseMesh;
    shape cone;
    Simplemesh coneMesh;
    Simplemesh frontFaceMesh;
    shape innerSideWall;
    Simplemesh innerSideWallMesh;
    shape halfCylinder;
    Simplemesh halfCylinderMesh;
    shape halfCircle;
    Simplemesh halfCircleMesh;
    shape column;
    Simplemesh columnMesh;
    shape cylBase;
    Simplemesh cylBaseMesh;

    void init() override;
    Dome(Shader shader);
    void Draw() override;
    void drawMeshes(glm::mat4 transform, glm::mat4 scaleMat = glm::mat4(1)) override;
    void DrawDepth(Shader depthShader, bool ortho = true) override;
};

