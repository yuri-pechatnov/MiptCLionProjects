//
// Created by ura on 30.04.16.
//

#include "cimg_texture_loader.h"
#include "utils.h"

namespace ImGen {


    Color CImgTexture::getColor(int w, int h) {
        return Color(img(w, h, 0, 0), img(w, h, 0, 1), img(w, h, 0, 2));
    }
    CImgTexture::CImgTexture(const cmg::CImg<unsigned char> &img): img(img) {
        width = img.width();
        height = img.height();
    }


    Texture *CImgTextureLoader::getTexture(const char *fileName) {
        //cerr << "Hoho " << fileName << endl;
        //for (int i = 0; fileName[i]; i++)
        //    cerr << i << ": <" << fileName[i] << ">" << endl;
        return new CImgTexture(cmg::CImg<unsigned char>(fileName));
    }

    CImgTextureLoader::CImgTextureLoader() {}

}