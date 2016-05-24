//
// Created by ura on 30.04.16.
//

#ifndef RAYTRACING_CIMG_TEXTURE_LOADER_H
#define RAYTRACING_CIMG_TEXTURE_LOADER_H

#include <CImg.h>
#include "color.h"
#include "texture_surface.h"

namespace cmg = cimg_library;

namespace ImGen {

    class CImgTexture : public Texture {
    public:
        cmg::CImg<unsigned char> img;
        virtual Color getColor(int w, int h);
        CImgTexture(const cmg::CImg<unsigned char> &img);
    };

    class CImgTextureLoader : public TextureLoader {
    public:
        virtual Texture *getTexture(const char *fileName);
        CImgTextureLoader();
    };
}


#endif //RAYTRACING_CIMG_TEXTURE_LOADER_H
