//#include "imageloader.h"
//#ifndef STB_IMAGE_IMPLEMENTATION
//#define STB_IMAGE_IMPLEMENTATION
//#include <stb_image.h>
//#endif
//
//
//unsigned char* loadImage(std::string path,int* width, int* height, int* nrChannels, bool flipFlag) {
//
//    stbi_set_flip_vertically_on_load(flipFlag);
//    unsigned char* data = stbi_load(path.c_str(), width, height, nrChannels, 0);
//    if (!data)
//    {
//        std::cout << "Failed to load texture " + path << std::endl;
//    }
//    return data;
//}
//void freeImageData(unsigned char* data) {
//    stbi_image_free(data);
//}