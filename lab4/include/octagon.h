#ifndef OCTAGON_H
#define OCTAGON_H

#include <iostream>
#include <cmath>
#include <array>
#include "figure.h"
#include "point.h"
#include "concepts.h"

template <Number T>
class Octagon : public Figure<T> {
private:
    std::array<Point<T>, 8> points;

public:
    Octagon();
    Octagon(const std::array<Point<T>, 8>& pts);
    Octagon(const Octagon<T>& other);
    Octagon(Octagon<T>&& other) noexcept;

    Octagon<T>& operator=(const Octagon<T>& other);
    Octagon<T>& operator=(Octagon<T>&& other) noexcept;

    std::pair<T, T> Center() const override;

    explicit operator double() const override;

    bool operator==(const Figure<T>& other) const override;

    void Print(std::ostream& os) const override;

    Figure<T>* Clone() const override;

    template <Number U>
    friend std::istream& operator>>(std::istream& is, Octagon<U>& o);
};


#endif // OCTAGON_H
