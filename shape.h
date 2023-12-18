#pragma once
#include <iostream>
#include <learnopengl/simplemesh.h>
#include <vector>
#include "texture.h"

#define PI 3.14159265359f


struct shape
{
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
	std::vector<sVertex> sVertices;
	std::vector<texture> Textures;
	shape() {};
	shape(const std::vector<float>& initVertices, const std::vector<unsigned int>& initIndices)
		: vertices(initVertices), indices(initIndices) {}

	void clearData() {
		vertices.clear();
		indices.clear();
		sVertices.clear();
		Textures.clear();
	}
};