//
// Created by ura on 09.04.16.
//

#ifndef RAYTRACING_SCREEN_H
#define RAYTRACING_SCREEN_H

#include "ray_tracing/primitives/fig_parallelogram.h"
#include "point.h"

namespace ImGen {

    class Screen : public Parallelogram {
    public:
        int width, height;

        Point pixelCoordinatesToPoint(double x, double y);

        Screen();

        Screen(ParallelogramCRef screen, int width, int height);
    };

    typedef const Screen &ScreenCRef;

};

#endif //RAYTRACING_SCREEN_H
