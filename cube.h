#pragma once
#include "shape.h"
#include <learnopengl/simplemesh.h>
#include "utils.h"

shape cube({
    -0.5f, 0.5f, -0.5f,0.0f, 1.0f, 0.0f ,0.0f, 1.0f,
    0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f,0.0f, 1.0f, 0.0f,1.0f, 0.0f,
    -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,

    -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
    0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f
}, {
    0, 1, 2, 2, 3, 0,
    4, 5, 6, 6, 7, 4,
    3, 2, 6, 6, 7, 3,
    0, 1, 5, 5, 4, 0,
    0, 3, 7, 7, 4, 0,
    1, 2, 6, 6, 5, 1
});

void initcube() {
    cube.sVertices = convertToVertexglmVector(cube.vertices);
}