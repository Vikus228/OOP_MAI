#ifndef HEXAGON_H
#define HEXAGON_H

#include <iostream>
#include <cmath>
#include "figure.h"
#include "point.h"
#include "concepts.h"
#include <memory>

template <Number T>
class Hexagon : public Figure<T> {
private:
    std::array<Point<T>, 6> points;

public:
    Hexagon();
    Hexagon(const std::array<Point<T>, 6>& pts);
    Hexagon(const Hexagon<T>& other);
    Hexagon(Hexagon<T>&& other) noexcept;

    Hexagon<T>& operator=(const Hexagon<T>& other);
    Hexagon<T>& operator=(Hexagon<T>&& other) noexcept;

    std::pair<T, T> Center() const override;

    explicit operator double() const override;

    bool operator==(const Figure<T>& other) const override;

    void Print(std::ostream& os) const override;

    Figure<T>* Clone() const override;

    template <Number U>
    friend std::istream& operator>>(std::istream& is, Hexagon<U>& h);
};


#endif // HEXAGON_H
