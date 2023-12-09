#pragma once
#include "common.h"



unsigned char* loadImage(std::string path, int* width, int* height, int* nrChannels, bool flipFlag = true);

void freeImageData(unsigned char* data);