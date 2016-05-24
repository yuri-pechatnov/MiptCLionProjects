//
// Created by ura on 12.04.16.
//

#include <ray_tracing/color.h>
#include <ray_tracing/ray.h>
#include <functional>
#include "fig_triangle.h"


namespace ImGen {

    PrimitiveAndRayIntersection Triangle::intersectWithRay(const Ray &ray) {
        Point coords;
        if (!Point::coordInBasis((A >> ray.origin), AB, AC, -ray.dir, coords))
            return PARIntersection::nan();
        if (coords.x() >= 0 && coords.y() >= 0 && coords.x() + coords.y() <= 1) {
            int s = ((norm * ray.dir) > 0 ? -1 : +1);
            Point X = ray.origin + ray.dir * coords.z();
            return PrimitiveAndRayIntersection(
                    this, ray, calcColor(A >> X, AB, AC).invert(s),
                    X, norm * s, ray.dirLen * coords.z()
            );
        }
        else
            return PARIntersection::nan();
    }

    BoundingBox Triangle::getBoundingBox() {
        return BoundingBox().addPoint(A).addPoint(A + AB).addPoint(A + AC);
    }

    Triangle::Triangle(const Point &A, const Point &B, const Point &C) :
            A(A), AB(A >> B), AC(A >> C) {
        norm = (AB ^ AC).norm();
    }

};