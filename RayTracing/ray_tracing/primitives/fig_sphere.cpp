//
// Created by ura on 17.04.16.
//

#include <ray_tracing/color.h>
#include <ray_tracing/ray.h>
#include <functional>
#include <cmath>
#include <ray_tracing/utils.h>
#include "fig_sphere.h"


namespace ImGen {

    PARIntersection Sphere::intersectWithRay(const Ray &ray) {
        Point X = ray.origin - O, dir = ray.dir;
        double a = dir.len2(), b = 2.0 * (X * dir), c = X.len2() - sqr(R);
        double D = sqr(b) - 4.0 * a * c;
        if (D < eps)
            return PARIntersection::nan();
        Point ans;
        D = sqrt(D);
        double oa = 0.5 / a;
        double t = (-b - D) * oa;
        if (t < eps)
            t = (-b + D) * oa;
        if (t < eps) {
            return PARIntersection::nan();
        }
        ans = X + dir * t;
        int s = ((fabs(c) < eps) ? (ans * ray.dir > 0 ? -1 : 1) : (c < 0.0 ? -1 : +1));
        return PARIntersection(this, ray, color.invert(s), ray.origin + dir * t, ans * s / R, ray.dirLen * t);
    }

    BoundingBox Sphere::getBoundingBox() {
        return BoundingBox().addPoint(O + Point(R, R, R)).addPoint(O - Point(R, R, R));
    }

    Sphere::Sphere(const Point &O, double R) :
            Primitive(), O(O), R(R) {
    }

};