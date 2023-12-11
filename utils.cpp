#include "utils.h"

vector<sVertex> convertToVertexglmVector(const std::vector<float> dataArray) {
    vector<sVertex> vertices;
    size_t dataSize = dataArray.size();
    size_t numVertices = dataSize / 8;
    for (size_t i = 0; i < numVertices; ++i) {
        size_t baseIndex = 8 * i;

        sVertex vertex;
        vertex.Position = glm::vec3(dataArray[baseIndex], dataArray[baseIndex + 1], dataArray[baseIndex + 2]);
        vertex.Normal = glm::vec3(dataArray[baseIndex + 3], dataArray[baseIndex + 4], dataArray[baseIndex + 5]);
        vertex.TexCoords = glm::vec2(dataArray[baseIndex + 6], dataArray[baseIndex + 7]);

        vertices.push_back(vertex);
    }

    return vertices;
}
void calculateNormalsSmooth(std::vector<sVertex>& vertices, const std::vector<unsigned int>& indices) {
    
    for (sVertex& vertex : vertices) {
        vertex.Normal = glm::vec3(0.0f, 0.0f, 0.0f);
    }

    for (size_t i = 0; i < indices.size(); i += 3) {
        unsigned int index0 = indices[i];
        unsigned int index1 = indices[i + 1];
        unsigned int index2 = indices[i + 2];

        glm::vec3 edge1 = vertices[index1].Position - vertices[index0].Position;
        glm::vec3 edge2 = vertices[index2].Position - vertices[index0].Position;
        glm::vec3 faceNormal = glm::cross(edge1, edge2);
        vertices[index0].Normal += faceNormal;
        vertices[index1].Normal += faceNormal;
        vertices[index2].Normal += faceNormal;
    }
    for (sVertex& vertex : vertices) {
        vertex.Normal = glm::normalize(vertex.Normal);
    }

}