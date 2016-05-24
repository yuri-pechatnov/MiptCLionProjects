//
// Created by ura on 13.04.16.
//

#include <cmath>
#include <algorithm>
#include "utils.h"
#include "color.h"
#include "fig_primitive.h"

namespace ImGen {
    PrimitiveAndRayIntersection::PrimitiveAndRayIntersection(
            Primitive *it, RayCRef ray, MetaColor color, Point X, Point norm, double distance):
            MetaColor(color), it(it), ray(ray.origin, ray.dir / ray.dirLen, 1.0), X(X), norm(norm), distance(distance) {
    }


    bool PrimitiveAndRayIntersection::betterThan(const PrimitiveAndRayIntersection &intersection) const {
        if (isNan())
            return false;
        return (distance < intersection.distance);
    }

    Ray PrimitiveAndRayIntersection::getDeflected(RayCRef ray) {
        return Ray(X, ray.dir + norm * (-2.0 * (norm * ray.dir)));
    }
    Ray PrimitiveAndRayIntersection::getDeflected() {
        return getDeflected(ray);
    }

    Ray PrimitiveAndRayIntersection::getRefracted() {
        double cosAlpha = -(norm * ray.dir);
        double cos2Beta = 1.0 - (1.0 - sqr(cosAlpha)) / sqr(refractiveIndex);
        //cerr << ray.dir << " | " << refractiveIndex << endl;
        if (cos2Beta <= 0)
            return getDeflected();
        else
            //return Ray(X, ray.dir);
            return Ray(X, ray.dir - norm * (refractiveIndex * sqrt(cos2Beta) - cosAlpha));

    }

    PrimitiveAndRayIntersection PrimitiveAndRayIntersection::nan() {
        return PrimitiveAndRayIntersection(NULL, Ray(), MetaColor(Color::nan()), Point(), Point(), 1e300);
    }

    Primitive* Primitive::setColor(const MetaColor &color_) {
        color = color_;
        return this;
    }

    Primitive::Primitive() { }

    void Primitive::calculateBoundingBox() {
        boundingBox = getBoundingBox();
    }

    Primitive::~Primitive() { }

    /*    TreePart *left, *right;
        BoundingBox boundingBox;
        std::vector<Primitive*> figures; */
    PARIntersection TreePart::findNearestObstacle(const Ray &ray, double upperLimit) {
        if (boundingBox.distIntersect(ray, upperLimit + eps) >= upperLimit)
            return PARIntersection::nan();
        PARIntersection ans = PARIntersection::nan();
        for (Primitive *fig : figures) {
            PARIntersectionCRef intersection = fig->intersectWithRay(ray);
            if (intersection.distance > eps && intersection.distance <= upperLimit && intersection.betterThan(ans))
                ans = intersection;
        }
        if (ans.distance < upperLimit)
            upperLimit = ans.distance;
        std::vector<TreePart*> children = {left, right};
        if (left != NULL && right != NULL && left->boundingBox.distIntersect(ray, upperLimit) >
                                                     right->boundingBox.distIntersect(ray, upperLimit))
            std::swap(children[0], children[1]);
        for (TreePart *son : children) {
            if (son == NULL)
                continue;
            PARIntersection intersection = son->findNearestObstacle(ray, upperLimit);
            if (intersection.betterThan(ans))
                ans = intersection;
            if (ans.distance < upperLimit)
                upperLimit = ans.distance;
        }
        return ans;
    }


    void TreePart::trySplitBetter(const std::vector<Primitive*> &figures, int axis,
                                  int &bestAxis, double &bestEdge, double &bestTimeExpectation) {
        std::vector<std::pair<double, int> > events;
        for (Primitive *figure : figures) {
            events.push_back(std::pair<double, int>(figure->boundingBox.minCoord.x(axis), -1));
            events.push_back(std::pair<double, int>(figure->boundingBox.maxCoord.x(axis), 1));
        }
        std::sort(events.begin(), events.end());
        Point deltaCoord = boundingBox.maxCoord - boundingBox.minCoord;
        double xMin = boundingBox.minCoord.x(axis), xMax = boundingBox.maxCoord.x(axis);
        //double coefYZ = sqr(deltaCoord.y(axis)) + sqr(deltaCoord.z(axis));
        //double coefXYZ = sqrt(coefYZ + sqr(deltaCoord.x(axis)));
        int amount = (int)figures.size(), amountLeft = 0, amountRight = amount;

        for (size_t i = 0; i < events.size(); i++) {
            const std::pair<double, int> &event = events[i];
            if (event.second == -1)
                amountRight--;
            else
                amountLeft++;
            double x = event.first;
            double newTimeExpectation =
                    3 + (amount - amountLeft - amountRight) + (amountLeft * (x - xMin) + amountRight * (xMax - x)) / deltaCoord.x(axis);
                            //(amountLeft * sqrt(sqr(x - xMin) + coefYZ) + amountRight * sqrt(sqr(xMax - x) + coefYZ)) / coefXYZ;
            if (newTimeExpectation < bestTimeExpectation) {
                bestTimeExpectation = newTimeExpectation;
                bestEdge = x;
                bestAxis = axis;
            }
        }
    }

    TreePart::TreePart(std::vector<Primitive*> &fs): left(NULL), right(NULL) {
        for (Primitive *figure : fs)
            boundingBox.addBoundingBox(figure->boundingBox);
        int bestAxis = -1;
        double bestTimeExpectation = fs.size() + 1;
        double bestEdge = 0;
        for (int axis = 0; axis < 3; axis++)
            trySplitBetter(fs, axis, bestAxis, bestEdge, bestTimeExpectation);
        if (bestAxis == -1) {
            //cerr << fs.size() << endl;
            swap(figures, fs);
            return;
        }
        //static int t = 0;
        std::vector<Primitive*> leftFigures, rightFigures;
        for (Primitive *figure : fs) {
            //cerr << "ff " << fs.size() <<  endl;
            //if (++t % 100 == 0)
            //    cerr << t << endl;
            if (figure->boundingBox.maxCoord.x(bestAxis) <= bestEdge) {
                leftFigures.push_back(figure);
                continue;
            }
            if (figure->boundingBox.minCoord.x(bestAxis) >= bestEdge) {
                rightFigures.push_back(figure);
                continue;
            }
            figures.push_back(figure);
        }
        if (leftFigures.size() == fs.size() || rightFigures.size() == fs.size()){
            //cerr << fs.size() << endl;
            swap(figures, fs);
            return;
        }
        fs.clear();
        left = new TreePart(leftFigures);
        right = new TreePart(rightFigures);
    }


    PARIntersection KDTreeOfPrimitives::findNearestObstacle(const Ray &ray, double upperLimit) {
        return root->findNearestObstacle(ray, upperLimit);
    }
    void KDTreeOfPrimitives::init(std::vector<Primitive*> figures) {
        if (root != NULL)
            delete root;
        for (Primitive *figure : figures)
            figure->calculateBoundingBox();
        root = new TreePart(figures);
    }
    KDTreeOfPrimitives::KDTreeOfPrimitives() {
        root = NULL;
    }

};
