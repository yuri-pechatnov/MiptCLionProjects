//
// Created by ura on 08.05.16.
//

#ifndef RAYTRACING_FIG_PLAIN_H
#define RAYTRACING_FIG_PLAIN_H

#include <ray_tracing/texture_surface.h>
#include "ray_tracing/fig_primitive.h"
#include "ray_tracing/point.h"

namespace ImGen {

    class PlainSurface : public Primitive {
    public:
        TextureSurface *textureSurface;
        PlainSurface* setTextureSurface(TextureSurface *textureSurface_);
        MetaColor calcColor(PointCRef X, PointCRef AB, PointCRef AC);
        PlainSurface();
    };
    typedef const PlainSurface &PlainSurfaceCRef;
};


#endif //RAYTRACING_FIG_PLAIN_H
