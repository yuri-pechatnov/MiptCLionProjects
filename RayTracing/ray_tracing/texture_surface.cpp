//
// Created by ura on 30.04.16.
//


#include "texture_surface.h"
#include "utils.h"

namespace ImGen {

    int TextureSurface::normCoordToMod(int x, int mod) {
        return (x % mod + mod) % mod;
    }

    Color TextureSurface::getColor(double x, double y) {
        int w = int(texture->width * (a11 * x + a12 * y));
        int h = int(texture->height * (a21 * x + a22 * y));
        return texture->getColor(normCoordToMod(w, texture->width), normCoordToMod(h, texture->height));
    }
    TextureSurface::TextureSurface(): texture(NULL) {}

    TextureSurface::TextureSurface(PointCRef AB, PointCRef AC, double lenw, double lenh, Texture *texture_) {
        setSurface(AB, AC, lenw, lenh, texture_);
    }

    void TextureSurface::setSurface(PointCRef AB, PointCRef AC, double lenw, double lenh, Texture *texture_) {
        texture = texture_;
        // given AB*x + AC*y
        // OX = AB, OY = AC - (AB * AC) / (AB * AB) AB
        // AC = OY + (AB * AC) / (AB * AB) OX
        // given OX * x + (OY + (AB * AC) / (AB * AB) OX) * y
        // given OX * (x + ((AB * AC) / (AB * AB)) * y) + OY * y
        // given OX.norm() * (OX.len() x + ((AB * AC) / (AB * AB) * OX.len()) y) + OY.norm() * (OY.len() y)
        // given (OX.norm() * lenw) * (OX.len() / lenw x + ((AB * AC) / (AB * AB) * OX.len() / lenw) y) + (OY.norm() * lenh) * (OY.len() / lenh y)
        // given (OX.norm() * lenw) * (a11 x + a12 y) + (OY.norm() * lenh) * (0 x + a22 y)
        double c = (AB * AC) / (AB * AB);
        a11 = AB.len() / lenw;
        a12 = a11 * c;
        a21 = 0;
        a22 = (AC - AB * c).len() / lenh;
        //cerr << a11 << " " <<a22 << " " << a21 << " " << a12 << endl;
    }

};