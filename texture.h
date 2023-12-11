#pragma once
#include "common.h"
#include <learnopengl/simplemesh.h>

class texture
{
public:
	sTexture info;
	GLenum format;
	bool generatMipMapflag;
	texture(std::string path, std::string type, bool generatMipMapflag = true, GLenum format = GL_NONE);

	void make();

private:

};