#pragma once
#include "object_.h"
#include<learnopengl/shape.h>
class mosque :
    public object_
{
public:
    shape rectangleback;
    Simplemesh rectanglebackmesh;

    shape rectanglebackside;
    Simplemesh rectanglebacksidemesh;

    shape rectanglefrontside;
    Simplemesh rectanglefrontsidemesh;

    shape rectangleright;
    Simplemesh rectanglerightmesh;

    shape rectanglerightside;
    Simplemesh rectanglerightsidemesh;

    shape rectangleleft;
    Simplemesh rectangleleftmesh;

    shape rectangleleftside;
    Simplemesh rectangleleftsidemesh;

    shape rectangleroof;
    Simplemesh rectangleroofmesh;

    shape rectangleroofside;
    Simplemesh rectangleroofsidemesh;

    shape rectangleup;
    Simplemesh rectangleupmesh;

    shape rectangleupside;
    Simplemesh rectangleupsidemesh;

    shape rectanglefront;
    Simplemesh rectanglefrontmesh;

    shape rectanglefront2;
    Simplemesh rectanglefrontmesh2;

    shape halfcylinder;
    Simplemesh halfcylindermesh;

    shape cylinder;
    Simplemesh cylindermesh;

    shape dome;
    Simplemesh domeMesh;

    shape rectanglecylinder;
    Simplemesh rectanglecylindermesh;

    shape rectanglesideside;
    Simplemesh rectanglesidesidemesh;


    shape rectangle;
    Simplemesh rectanglemesh;

    shape face;
    Simplemesh faceMesh;
    shape base;
    Simplemesh baseMesh;
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



    shape MEM;
    Simplemesh MEMMesh;

    void init() override;
    mosque(Shader shader);
    void Draw() override;
    void DrawDepth(Shader depthShader, bool ortho) override;
    void drawMeshes(glm::mat4 transform, glm::mat4 scaleMat = glm::mat4(1)) override;
   // void drawDepth(Shader depth, bool ortho) override;
};

