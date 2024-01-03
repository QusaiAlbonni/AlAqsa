#pragma once
#ifndef CUSTOMMODEL_H
#define CUSTOMMODEL_H

#include<learnopengl/simplemesh.h>
#include <learnopengl/shader.h>

class customTexts
{

public:
	void static addTexts(Shader shader, std::vector<sTexture> textures){
        unsigned int diffuseNr = 1;
        unsigned int specularNr = 1;
        unsigned int normalNr = 1;
        unsigned int heightNr = 1;
        unsigned int ambientNr = 1;
        for (unsigned int i = 0; i < textures.size(); i++)
        {
            glActiveTexture(GL_TEXTURE0 + i);
            string number;
            string name = textures[i].type;
            if (name == "material.diffuse")
                number = std::to_string(diffuseNr++);
            else if (name == "material.specular")
                number = std::to_string(specularNr++);
            else if (name == "material.normal")
                number = std::to_string(normalNr++);
            else if (name == "material.height")
                number = std::to_string(heightNr++);
            else if (name == "material.ambient")
                number = std::to_string(ambientNr++);
            glUniform1i(glGetUniformLocation(shader.ID, (name + number).c_str()), i);

            glBindTexture(GL_TEXTURE_2D, textures[i].id);

        }
	}
};

#endif