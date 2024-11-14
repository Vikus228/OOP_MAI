#include <utility>
#include <stdexcept>
#include <iostream>
#include "concepts.h"
#include "point.h"
#include "concepts.h"

template <Number T>
std::ostream &operator<<(std::ostream &os, const Figure<T> &figure) {
    figure.Print(os);
    return os;
}