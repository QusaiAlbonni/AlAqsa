#pragma once
#include "common.h"
#include <learnopengl/simplemesh.h>

class texture
{
public:
	sTexture info;
	GLenum format;
	bool generatMipMapflag;
	texture(std::string path, GLenum format, std::string type, bool generatMipMapflag = true);

	void make();

private:

};