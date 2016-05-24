//
// Created by ura on 09.04.16.
//

#ifndef RAYTRACING_FIG_SPHERE_H
#define RAYTRACING_FIG_SPHERE_H


#include <ray_tracing/color.h>
#include <ray_tracing/bounding_box.h>
#include <ray_tracing/ray.h>
#include <ray_tracing/fig_primitive.h>

namespace ImGen {

    class Sphere : public Primitive {
    public:
        Point O;
        double R;

        virtual PrimitiveAndRayIntersection intersectWithRay(RayCRef ray);

        virtual BoundingBox getBoundingBox();

        Sphere(PointCRef O, double center);

    };
    typedef const Sphere &SphereCRef;
};

#endif //RAYTRACING_FIG_SPHERE_H
