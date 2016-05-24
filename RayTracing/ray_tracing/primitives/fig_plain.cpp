//
// Created by ura on 08.05.16.
//

#include <ray_tracing/texture_surface.h>
#include "fig_plain.h"

namespace ImGen {

    PlainSurface* PlainSurface::setTextureSurface(TextureSurface *textureSurface_) {
        textureSurface = textureSurface_;
        return this;
    }
    MetaColor PlainSurface::calcColor(PointCRef X, PointCRef A, PointCRef B) {
        if (textureSurface == NULL)
            return color;
        Point coords;
        Point::coordInBasis(X, A, B, A ^ B, coords);
        MetaColor new_color = color;
        Color texture_color = textureSurface->getColor(coords.x(), coords.y());
        new_color.r = texture_color.r;
        new_color.g = texture_color.g;
        new_color.b = texture_color.b;
        return new_color;

    }
    PlainSurface::PlainSurface(): textureSurface(NULL) {}
};
