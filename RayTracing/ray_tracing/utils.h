//
// Created by ura on 21.04.16.
//

#ifndef RAYTRACING_UTILS_H_H
#define RAYTRACING_UTILS_H_H

#include <iostream>

namespace ImGen {

    template <typename T>
    inline T &upto(T &a, const T &b) {
        if (a < b)
            a = b;
        return a;
    }

    template <typename T>
    inline T &downto(T &a, const T &b) {
        if (a > b)
            a = b;
        return a;
    }

    template <typename T>
    inline T sqr(const T &a) {
        return a * a;
    }

    template <typename T>
    inline T pow3(const T &a) {
        return a * a * a;
    }

    using std::cerr;
    using std::endl;
    using std::min;
    using std::max;

    const double inf = 1e300;
    const double eps = 1e-7;

    inline double max(const double a, const double b) {
        if (a > b)
            return a;
        else
            return b;
    }



};


#endif //RAYTRACING_UTILS_H_H
