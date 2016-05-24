//
// Created by ura on 17.04.16.
//

#include <cmath>
#include "ray_tracing/primitives/fig_polygon.h"
#include "ray_tracing/fig_primitive.h"

namespace ImGen {

    bool Polygon::lieInPolygon(PointCRef X) {
        double angle = 0;
        //std::cerr << "Yihi" << std::endl;
        for (size_t i = 0; i < ps.size(); i++) {
            Point A = (X >> ps[i]), B = (X >> ps[(i + 1) % ps.size()]);
            A.z() = B.z() = 0;
            angle += atan2((A ^ B).z(), A * B);
        }
        //std::cerr << "(" << X << "), (" << ps[0] << "), (" << ps[1] << "), (" << ps[2] << ")" << std::endl;
        return (fabs(angle) > 3.14);

    }

    PrimitiveAndRayIntersection Polygon::intersectWithRay(const Ray &ray) {
        Point coords;
        if (!Point::coordInBasis((A >> ray.origin), X1, Y1, -ray.dir, coords))
            return PARIntersection::nan();
        if (lieInPolygon(coords)) {
            int s = ((norm * ray.dir) > 0 ? -1 : +1);
            Point X = ray.origin + ray.dir * coords.z();
            return PrimitiveAndRayIntersection(
                    this, ray, calcColor(A >> X, X1, Y1).invert(s),
                    X, norm * s, ray.dirLen * coords.z()
            );
        }
        else
            return PARIntersection::nan();

    }

    BoundingBox Polygon::getBoundingBox() {
        BoundingBox bb;
        for (PointCRef p : ps)
            bb.addPoint(A + X1 * p.x() + Y1 * p.y());
        return bb;
    }

    Polygon::Polygon(PointCRef A, PointCRef X1, PointCRef Y1, const std::vector<Point> &ps) :
            A(A), X1(X1), Y1(Y1), norm((X1 ^ Y1).norm()), ps(ps) {
    }
};