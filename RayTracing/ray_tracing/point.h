//
// Created by ura on 09.04.16.
//

#ifndef RAYTRACING_POINT_H
#define RAYTRACING_POINT_H

#include <iostream>

namespace ImGen {

inline double sqr(const double &x) {
    return x * x;
}

class Point;

typedef const Point &PointCRef;

class Point {
public:
    double coords[3];
    inline explicit Point(double x = 0, double y = 0, double z = 0) {
        coords[0] = x;
        coords[1] = y;
        coords[2] = z;
    }

    inline double &x() { return coords[0]; }
    inline double &y() { return coords[1]; }
    inline double &z() { return coords[2]; }
    inline double &x(int shift) { return coords[shift % 3]; }
    inline double &y(int shift) { return coords[(shift + 1) % 3]; }
    inline double &z(int shift) { return coords[(shift + 2) % 3]; }


    inline const double &x() const { return coords[0]; }
    inline const double &y() const { return coords[1]; }
    inline const double &z() const { return coords[2]; }
    inline const double &x(int shift) const { return coords[shift % 3]; }
    inline const double &y(int shift) const { return coords[(shift + 1) % 3]; }
    inline const double &z(int shift) const { return coords[(shift + 2) % 3]; }

    Point operator+(PointCRef a) const;
    Point operator-(PointCRef a) const;
    Point operator-() const;
    Point operator>>(PointCRef a) const;
    double operator*(PointCRef a) const;
    Point operator^(PointCRef a) const;
    Point operator*(double k) const;
    Point operator/(double k) const;
    double len() const;
    double len2() const;
    Point norm() const;

    friend std::ostream &operator<<(std::ostream &out, PointCRef a);
    friend std::istream &operator>>(std::istream &inp, Point &a);

    inline static double det2(double a, double b, double c, double d);
    inline static double det3(PointCRef A, PointCRef B, PointCRef C);
    static bool coordInBasis(PointCRef X, PointCRef A, PointCRef B, PointCRef C, Point &coord);
};

};


#endif //RAYTRACING_POINT_H
