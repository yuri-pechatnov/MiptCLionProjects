//
// Created by ura on 09.04.16.
//

#ifndef RAYTRACING_FIG_RECTANGLE_H
#define RAYTRACING_FIG_RECTANGLE_H

#include <ray_tracing/color.h>
#include <ray_tracing/bounding_box.h>
#include <ray_tracing/ray.h>
#include <ray_tracing/fig_primitive.h>
#include <vector>
#include <ray_tracing/texture_surface.h>
#include "fig_plain.h"

namespace ImGen {

    class Polygon : public PlainSurface {
        bool lieInPolygon(PointCRef X);
    public:
        Point A, X1, Y1, norm;
        std::vector<Point> ps;

        virtual PrimitiveAndRayIntersection intersectWithRay(RayCRef ray);

        virtual BoundingBox getBoundingBox();

        Polygon(PointCRef A, PointCRef X1, PointCRef Y1, const std::vector<Point> &ps);

    };

};
#endif //RAYTRACING_FIG_RECTANGLE_H
