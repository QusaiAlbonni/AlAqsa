#pragma once
#include "object_.h"
#include "utils.h"
#include "learnopengl/model.h"
#include "lighting.h"
#include <learnopengl/shape.h>
class outersquare :
	public object_
{
public:
    //Model tree;
    Model fountain;
    Model birds;
    shape Gaterec;
    Simplemesh Gatemesh;
 

    
 
    outersquare(Shader shader);
    void init() override;
    void Draw() override;
    void drawMeshes(glm::mat4 transform, glm::mat4 scaleMat = glm::mat4(1)) override;
    

   
};

