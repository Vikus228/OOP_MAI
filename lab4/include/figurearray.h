#ifndef FIGUREARRAY_H
#define FIGUREARRAY_H

#include "figure.h"
#include "concepts.h"
#include <memory>

template <Number T>
class FigureArray {
public:
    FigureArray();
    ~FigureArray();

    void add(std::shared_ptr<Figure<T>> figure);
    void remove(size_t index);
    std::shared_ptr<Figure<T>> operator[](size_t index) const;
    T totalArea() const;
    size_t size() const;

private:
    std::unique_ptr<std::shared_ptr<Figure<T>>[]> array;
    size_t capacity;
    size_t count;

    void resize(size_t newCapacity);
};



#endif // FIGUREARRAY_H
