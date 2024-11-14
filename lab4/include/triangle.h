#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdexcept>
#include "point.h"
#include "figure.h"
#include <memory>

template <Number T>
class Triangle : public Figure<T> {
private:
    Point<T> p1;
    Point<T> p2;
    Point<T> p3;

public:
    Triangle();
    Triangle(Point<T> p1, Point<T> p2, Point<T> p3);
    Triangle(const Triangle<T> &other);
    Triangle(Triangle<T> &&other) noexcept;
    Triangle& operator= (const Triangle<T> &other);
    Triangle& operator= (Triangle<T> &&other) noexcept;

    std::pair<T, T> Center() const override;

    explicit operator double() const override;

    bool operator==(const Figure<T> &other) const override;

    void Print(std::ostream &os) const override;

    Figure<T>* Clone() const override;

    template <Number U>
    friend std::istream &operator>>(std::istream &is, Triangle<U> &r);
};



#endif