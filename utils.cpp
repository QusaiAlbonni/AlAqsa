#include "utils.h"

vector<sVertex> convertToVertexglmVector(const std::vector<float> dataArray, size_t dataSize) {
    vector<sVertex> vertices;
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