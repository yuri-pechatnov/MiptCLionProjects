//
// Created by ura on 09.04.16.
//

#ifndef RAYTRACING_RAY_H
#define RAYTRACING_RAY_H

#include "point.h"

namespace ImGen {

class Ray {
public:
    Point origin, dir;
    double dirLen;
    Ray(PointCRef origin = Point(0, 0), PointCRef dir = Point(0, 0));
    Ray(PointCRef origin, PointCRef dir, double dirLen);
    static Ray rayFromAB(PointCRef A, PointCRef B);
    static Ray normedRayFromAB(PointCRef A, PointCRef B);
};

typedef const Ray &RayCRef;

};

#endif //RAYTRACING_RAY_H
