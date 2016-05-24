//
// Created by ura on 09.04.16.
//

#include "screen.h"
#include "color.h"

namespace ImGen {

    Point Screen::pixelCoordinatesToPoint(double x, double y) {
        return A + AB * x + AC * y;
    }

    Screen::Screen() : Parallelogram(Point(), Point(), Point()), width(0), height(0) { }

    Screen::Screen(ParallelogramCRef screen, int width, int height) :
            Parallelogram(screen.A, screen.A + screen.AB / width, screen.A + screen.AC / height),
            width(width), height(height) { }
};