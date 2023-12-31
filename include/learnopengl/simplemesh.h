#ifndef SIMPLEMESH_H
#define SIMPLEMESH_H
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <learnopengl/shader_m.h>

#include <string>
#include <vector>
using namespace std;

#define MAX_BONE_INFLUENCE 4

struct sVertex {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;
};

struct sTexture {
    unsigned int id;
    string type;
    string path;
};

class Simplemesh {
public:
    // mesh Data
    vector<sVertex>       vertices;
    vector<unsigned int> indices;
    vector<sTexture>      textures;
    unsigned int VAO;
    bool depth = false;
    bool depthCube = false;

    // constructor
    Simplemesh() {};

    Simplemesh(vector<sVertex> vertices, vector<unsigned int> indices, vector<sTexture> textures)
    {
        this->vertices = vertices;
        this->indices = indices;
        this->textures = textures;

        // now that we have all the required data, set the vertex buffers and its attribute pointers.
        setupMesh();
    }

    void addDepthTexture(Shader shader, unsigned int d) {
        glActiveTexture(GL_TEXTURE20);
        shader.setInt("shadowMap1", 20);
        glBindTexture(GL_TEXTURE_2D, d);
    };
    void addDepthTexture2(Shader shader, unsigned int d) {
        glActiveTexture(GL_TEXTURE21);
        shader.setInt("shadowMap2", 21);
        glBindTexture(GL_TEXTURE_2D, d);
    }
    // render the mesh
    void Draw(Shader& shader, GLenum primitive = GL_TRIANGLES, unsigned int d = 0, unsigned int c = 0)
    {

        
        // bind appropriate textures
        unsigned int diffuseNr = 1;
        unsigned int specularNr = 1;
        unsigned int normalNr = 1;
        unsigned int heightNr = 1;
        unsigned int ambientNr = 1;
        for (unsigned int i = 0; i < textures.size(); i++)
        {
            glActiveTexture(GL_TEXTURE0 + i); // active proper texture unit before binding
            // retrieve texture number (the N in diffuse_textureN)
            string number;
            string name = textures[i].type;
            if (name == "material.diffuse")
                number = std::to_string(diffuseNr++);
            else if (name == "material.specular")
                number = std::to_string(specularNr++); // transfer unsigned int to string
            else if (name == "material.normal")
                number = std::to_string(normalNr++); // transfer unsigned int to string
            else if (name == "material.height")
                number = std::to_string(heightNr++); // transfer unsigned int to string
            else if (name == "material.ambient")
                number = std::to_string(ambientNr++); // transfer unsigned int to string

            // now set the sampler to the correct texture unit
            glUniform1i(glGetUniformLocation(shader.ID, (name + number).c_str()), i);
       
            glBindTexture(GL_TEXTURE_2D, textures[i].id);
            
        }
        if(d != 0)
            addDepthTexture(shader, d);
        if (c != 0)
            addDepthTexture2(shader, c);
 
        // draw mesh
        glBindVertexArray(VAO);
        glDrawElements(primitive, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        // always good practice to set everything back to defaults once configured.
        glActiveTexture(GL_TEXTURE0);
    }

private:
    // render data 
    unsigned int VBO, EBO;

    // initializes all the buffer objects/arrays
    void setupMesh()
    {
        // create buffers/arrays
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
        // load data into vertex buffers
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        // A great thing about structs is that their memory layout is sequential for all its items.
        // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
        // again translates to 3/2 floats which translates to a byte array.
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(sVertex), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

        // set the vertex attribute pointers
        // vertex Positions
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)0);
        // vertex normals
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)offsetof(sVertex, Normal));
        // vertex texture coords
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)offsetof(sVertex, TexCoords));
        glBindVertexArray(0);

        

    }
};
#endif
