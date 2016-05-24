//
// Created by ura on 17.04.16.
//

#ifndef RAYTRACING_LIGHT_SOURCE_H
#define RAYTRACING_LIGHT_SOURCE_H

#include "point.h"

namespace ImGen {

    class LightSource : public Point {
    public:
        int r, g, b;
        LightSource(Point point = Point(), int r = 0, int g = 0, int b = 0): Point(point), r(r), g(g), b(b) {}
    };

    typedef const LightSource &LightSourceCRef;

};

#endif //RAYTRACING_LIGHT_SOURCE_H
