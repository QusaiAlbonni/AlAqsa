#pragma once
#include <iostream>
#include <vector>

struct shape
{
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
	std::vector<sVertex> sVertices;
	shape() {};
	shape(const std::vector<float>& initVertices, const std::vector<unsigned int>& initIndices)
		: vertices(initVertices), indices(initIndices) {}
};