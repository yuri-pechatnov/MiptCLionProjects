//
// Created by ura on 12.04.16.
//

#include <cmath>
#include "bounding_box.h"
#include "utils.h"

namespace ImGen {

    BoundingBox &BoundingBox::addPoint(const Point &x) {
        for (int i = 0; i < 3; i++) {
            if (x.coords[i] < minCoord.coords[i])
                minCoord.coords[i] = x.coords[i];
            if (x.coords[i] > maxCoord.coords[i])
                maxCoord.coords[i] = x.coords[i];
        }
        return *this;
    }


    BoundingBox &BoundingBox::addBoundingBox(const BoundingBox &box) {
        for (int i = 0; i < 3; i++) {
            if (box.minCoord.coords[i] < minCoord.coords[i])
                minCoord.coords[i] = box.minCoord.coords[i];
            if (box.maxCoord.coords[i] > maxCoord.coords[i])
                maxCoord.coords[i] = box.maxCoord.coords[i];
        }
        return *this;
    }
    bool BoundingBox::isIntersect(RayCRef ray, double upperLimit) {
        PointCRef X = ray.origin, dir = ray.dir;
        double len = ray.dir.len();
        for (PointCRef bound : {minCoord, maxCoord}) {
            for (int axis = 0; axis < 3; axis++) {
                if (fabs(dir.z(axis)) > eps) {
                    double tMin = (bound.z(axis) - X.z(axis)) / dir.z(axis);
                    Point H = X + dir * tMin;
                    if (minCoord.x(axis) <= H.x(axis) && H.x(axis) <= maxCoord.x(axis)
                        && minCoord.y(axis) <= H.y(axis) && H.y(axis) <= maxCoord.y(axis)
                        && len * tMin < upperLimit + eps)
                        return true;
                }
            }
        }
        return false;
    }
    double BoundingBox::distIntersect(RayCRef ray, double upperLimit) {
        PointCRef X = ray.origin, dir = ray.dir;
        double len = ray.dir.len();
        for (PointCRef bound : {minCoord, maxCoord}) {
            for (int axis = 0; axis < 3; axis++) {
                if (fabs(dir.z(axis)) > eps) {
                    double tMin = (bound.z(axis) - X.z(axis)) / dir.z(axis);
                    Point H = X + dir * tMin;
                    if (minCoord.x(axis) <= H.x(axis) && H.x(axis) <= maxCoord.x(axis)
                        && minCoord.y(axis) <= H.y(axis) && H.y(axis) <= maxCoord.y(axis)
                        && len * tMin < upperLimit + eps)
                        upperLimit = len * tMin;

                }
            }
        }
        return upperLimit;
    }

    BoundingBox::BoundingBox(): minCoord(inf, inf, inf), maxCoord(-inf, -inf, -inf) { }

};
