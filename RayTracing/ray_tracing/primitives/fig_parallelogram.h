//
// Created by ura on 09.04.16.
//

#ifndef RAYTRACING_PARALLELOGRAM_H
#define RAYTRACING_PARALLELOGRAM_H

#include <ray_tracing/texture_surface.h>
#include "ray_tracing/fig_primitive.h"
#include "ray_tracing/point.h"
#include "fig_plain.h"

namespace ImGen {

    class Parallelogram : public PlainSurface {
    public:
        Point A, AB, AC, norm;

        virtual PrimitiveAndRayIntersection intersectWithRay(RayCRef ray);

        virtual BoundingBox getBoundingBox();

        Parallelogram(PointCRef A, PointCRef B, PointCRef C);
    };
    typedef const Parallelogram &ParallelogramCRef;
};

#endif //RAYTRACING_PARALLELOGRAM_H
