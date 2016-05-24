//
// Created by ura on 09.04.16.
//

#include "point.h"
#include "utils.h"
#include <cmath>
#include <iomanip>

namespace ImGen {



    Point Point::operator+(PointCRef a) const { return Point(x() + a.x(), y() + a.y(), z() + a.z()); }
    Point Point::operator-(PointCRef a) const { return Point(x() - a.x(), y() - a.y(), z() - a.z()); }
    Point Point::operator-() const { return Point(-x(), -y(), -z()); }
    Point Point::operator>>(PointCRef a) const { return Point(a.x() - x(), a.y() - y(), a.z() - z()); }
    double Point::operator*(PointCRef a) const { return x() * a.x() + y() * a.y() + z() * a.z(); }
    Point Point::operator^(PointCRef a) const {
        return Point(
                y() * a.z() - z() * a.y(),
                z() * a.x() - x() * a.z(),
                x() * a.y() - y() * a.x()
        );
    }
    Point Point::operator*(double k) const { return Point(x() * k, y() * k, z() * k); }
    Point Point::operator/(double k) const { return Point(x() / k, y() / k, z() / k); }

    double Point::len2() const {
        return sqr(x()) + sqr(y()) + sqr(z());
    }

    double Point::len() const {
        return sqrt(len2());
    }

    Point Point::norm() const {
        return operator/(len());
    }


    std::ostream &operator<<(std::ostream &out, PointCRef a) {
        return out << std::setprecision(4) << a.x() << " " << a.y() << " " << a.z();
    }

    std::istream &operator>>(std::istream &inp, Point &a) {
        return inp >> a.x() >> a.y() >> a.z();
    }

    inline double Point::det2(double a, double b, double c, double d) {
        return a * d - b * c;
    }

    inline double Point::det3(const Point &A, const Point &B, const Point &C) {
        return A.x() * det2(B.y(), C.y(), B.z(), C.z()) +
               A.y() * det2(B.z(), C.z(), B.x(), C.x()) +
               A.z() * det2(B.x(), C.x(), B.y(), C.y());

    }

    bool Point::coordInBasis(const Point &X, const Point &A, const Point &B, const Point &C, Point &coord) {
        // Kramer method, not rational, but...
        double detABC = det3(A, B, C);
        if (fabs(detABC) < eps)
            return false;
        double oDetABC = 1.0 / detABC;
        coord.x() = det3(X, B, C) * oDetABC;
        coord.y() = det3(A, X, C) * oDetABC;
        coord.z() = det3(A, B, X) * oDetABC;
        return true;
    }

};