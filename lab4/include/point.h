#ifndef POINT_H
#define POINT_H

#include "concepts.h"

template <Number T>
class Point {
private:
    T x;
    T y;
public:
    Point() : x(0), y(0) {}

    Point(T xVal, T yVal) : x(xVal), y(yVal) {}

    T getX() const;
    T getY() const;

    void setX(T xVal);
    void setY(T yVal);

    bool operator==(const Point<T>& other) const;
};



#endif // POINT_H
