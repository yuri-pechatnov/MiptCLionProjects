//
// Created by ura on 09.04.16.
//

#ifndef RAYTRACING_FIG_TRIANGLE_H_H
#define RAYTRACING_FIG_TRIANGLE_H_H

#include <ray_tracing/fig_primitive.h>
#include <ray_tracing/texture_surface.h>
#include "fig_plain.h"

namespace ImGen {

    class Triangle : public PlainSurface {
    public:
        Point A, AB, AC, norm;

        virtual PrimitiveAndRayIntersection intersectWithRay(RayCRef ray);

        virtual BoundingBox getBoundingBox();

        Triangle(PointCRef A, PointCRef B, PointCRef C);

    };

};

#endif //RAYTRACING_FIG_TRIANGLE_H_H
