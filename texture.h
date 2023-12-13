#pragma once
#include "common.h"
#include <learnopengl/simplemesh.h>

class texture
{
public:
	sTexture info;
	GLenum format;
	bool generatMipMapflag;
	GLenum gamma;
	texture(std::string path, std::string type, bool generatMipMapflag = true, GLenum format = GL_NONE, GLenum gamma = GL_RGB);

	void make();

private:

};