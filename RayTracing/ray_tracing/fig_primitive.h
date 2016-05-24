//
// Created by ura on 09.04.16.
//

#ifndef RAYTRACING_FIG_PRIMIRIVE_H_H
#define RAYTRACING_FIG_PRIMIRIVE_H_H

#include <functional>
#include <vector>
#include "ray.h"
#include "color.h"
#include "bounding_box.h"

namespace ImGen {
    class Primitive;

    class PrimitiveAndRayIntersection : public MetaColor {
    public:
        Primitive *it;
        Ray ray;
        Point X, norm;
        double distance;
        static PrimitiveAndRayIntersection nan();
        bool betterThan(const PrimitiveAndRayIntersection &intersection) const;
        Ray getDeflected(RayCRef ray);
        Ray getDeflected();
        Ray getRefracted();
        PrimitiveAndRayIntersection(Primitive *it, RayCRef ray, MetaColor color, Point X, Point norm, double distance);
    };

    typedef PrimitiveAndRayIntersection PARIntersection;
    typedef const PARIntersection &PARIntersectionCRef;

    class Primitive {
    public:
        MetaColor color;
        BoundingBox boundingBox;
        virtual PARIntersection intersectWithRay(RayCRef ray) = 0;
        virtual BoundingBox getBoundingBox() = 0;
        void calculateBoundingBox();
        Primitive* setColor(MetaColorCRef color);
        Primitive();
        virtual ~Primitive();
    };

    class KDTreeOfPrimitives;

    class TreePart {
    private:
        friend class KDTreeOfPrimitives;
        TreePart *left, *right;
        BoundingBox boundingBox;
        std::vector<Primitive*> figures;
        void trySplitBetter(const std::vector<Primitive*> &figures, int axis,
                            int &bestAxis, double &bestEdge, double &bestTimeExpectation);
        PARIntersection findNearestObstacle(const Ray &ray, double upperLimit);
        TreePart(std::vector<Primitive*> &figures);
    };

    class KDTreeOfPrimitives {
    public:
        TreePart *root;
        PARIntersection findNearestObstacle(const Ray &ray, double upperLimit);
        void init(std::vector<Primitive*> figures_);
        KDTreeOfPrimitives();

    };

};

#endif //RAYTRACING_FIG_PRIMIRIVE_H_H
