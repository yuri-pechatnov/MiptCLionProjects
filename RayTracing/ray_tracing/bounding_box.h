//
// Created by ura on 09.04.16.
//

#ifndef RAYTRACING_BOUNDING_BOX_H
#define RAYTRACING_BOUNDING_BOX_H

#include "point.h"
#include "ray.h"

namespace ImGen {

class BoundingBox {
    static constexpr double inf = 1e300;
public:
    Point minCoord, maxCoord;

    BoundingBox &addPoint(PointCRef x);
    BoundingBox &addBoundingBox(const BoundingBox &box);
    bool isIntersect(RayCRef ray, double upperLimit);
    double distIntersect(RayCRef ray, double upperLimit);
    BoundingBox();
};

};

#endif //RAYTRACING_BOUNDING_BOX_H
