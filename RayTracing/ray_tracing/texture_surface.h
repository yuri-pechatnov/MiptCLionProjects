//
// Created by ura on 30.04.16.
//

#ifndef RAYTRACING_TEXTURE_SURFACE_H
#define RAYTRACING_TEXTURE_SURFACE_H


#include "point.h"
#include "color.h"
#include "fig_primitive.h"

namespace ImGen {

    class Texture {
    public:
        int width, height;
        virtual Color getColor(int w, int h) = 0;
    };

    class TextureLoader {
    public:
        virtual Texture* getTexture(const char *fileName) = 0;
    };


    class TextureSurface {
        int normCoordToMod(int x, int mod);
    public:
        Texture *texture;
        double a11, a12, a21, a22;

        Color getColor(double x, double y);
        void setSurface(PointCRef AB, PointCRef AC, double lenw, double lenh, Texture *texture);
        TextureSurface();
        TextureSurface(PointCRef AB, PointCRef AC, double lenw, double lenh, Texture *texture);
    };
};


#endif //RAYTRACING_TEXTURE_SURFACE_H
