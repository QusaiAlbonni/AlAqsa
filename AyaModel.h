#pragma once
#include "object_.h"
#include "utils.h"
#include "include/learnopengl/model.h"
#include "lighting.h"
class AyaModel :
	public object_
{
public:
    Model tree;
   
    AyaModel(Shader shader);
    void init() override;
    void Draw() override;
    void DrawDepth(Shader depthShader, bool ortho) override;
    void drawMeshes(glm::mat4 transform, glm::mat4 scaleMat = glm::mat4(1)) override;
    //void DrawDepth(Shader depthShader, bool ortho = true) override;
    

   
};

