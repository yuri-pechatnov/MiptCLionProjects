//
// Created by ura on 13.04.16.
//

#include "ray.h"

namespace ImGen {

    Ray Ray::rayFromAB(const Point &A, const Point &B) {
        return Ray(A, A >> B);
    }

    Ray Ray::normedRayFromAB(const Point &A, const Point &B) {
        return Ray(A, (A >> B).norm(), 1.0);
    }

    Ray::Ray(const Point &origin, const Point &dir): origin(origin), dir(dir), dirLen(dir.len()) { }

    Ray::Ray(const Point &origin, const Point &dir, double dirLen): origin(origin), dir(dir), dirLen(dirLen) { }

};