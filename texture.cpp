
#include "texture.h"
#include <SOIL2/SOIL2.h>


texture::texture(std::string path,std::string type, GLenum format, GLenum gamma, bool generatMipMapflag)
{
	this->info.path = path;
	this->format = format;
	this->info.type = type;
	this->gamma = gamma;
	this->generatMipMapflag = generatMipMapflag;
	this->make();
	
}

void texture::make() {
	std::string path = info.path;
	glGenTextures(1, &info.id);
	glBindTexture(GL_TEXTURE_2D, info.id);
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = SOIL_load_image(info.path.c_str(), &width, &height, &nrChannels, SOIL_LOAD_AUTO);
	if (format == GL_NONE) {
		if (nrChannels == 1)
			format = GL_RED;
		else if (nrChannels == 3)
			format = GL_RGB;
		else if (nrChannels == 4)
			format = GL_RGBA;
	}
	glTexImage2D(GL_TEXTURE_2D, 0, gamma, width, height, 0, format, GL_UNSIGNED_BYTE, data);

	if (generatMipMapflag)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	}
	else
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	SOIL_free_image_data(data);
}