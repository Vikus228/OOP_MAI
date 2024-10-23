#include "class.hpp"
#include <stdexcept>

void Decimal::checking_digit(unsigned char digit)
{
    if (digit < '0' || digit > '9')
    {
        throw std::invalid_argument("Wrong digit, it must be between 0 and 9");
    }
}
Decimal::Decimal() : _size(0), _array{nullptr} {}
Decimal::Decimal(const size_t &n, unsigned char t)
{
    checking_digit(t);
    _array = new unsigned char[n];
    for (size_t i = 0; i < n; ++i)
        _array[i] = t;
    _size = n;
}

Decimal::Decimal(const std::initializer_list<unsigned char> &spiso4ek)
{
    _array = new unsigned char[spiso4ek.size()];
    size_t i{0};
    for (auto &simvolik : spiso4ek)
    {
        checking_digit(simvolik);
        _array[i++] = simvolik;
    }
    _size = spiso4ek.size();
}

Decimal::Decimal(const std::string &stringi)
{
    _array = new unsigned char[stringi.size()];
    _size = stringi.size();
    for (size_t i = 0; i < _size; ++i)
    {
        checking_digit(stringi[i]);
        _array[i] = stringi[i];
    }
}

Decimal::Decimal(const Decimal &other)
{
    _size = other._size;
    _array = new unsigned char[_size];
    for (size_t i = 0; i < _size; ++i)
    {
        _array[i] = other._array[i];
    }
}

Decimal::Decimal(Decimal &&other) noexcept
{
    _size = other._size;
    _array = other._array;
    other._size = 0;
    other._array = nullptr;
}

using razmer4ik = size_t;

razmer4ik Decimal::get_size()
{
    return _size;
}

unsigned char *Decimal::get_char4iki() const
{
    return _array;
}

bool Decimal::operator==(const Decimal &other) const
{
    if (_size != other._size)
    {
        return false;
    }
    for (size_t i = 0; i < _size; ++i)
    {
        if (_array[i] != other._array[i])
        {
            return false;
        }
    }
    return true;
}
bool Decimal::operator!=(const Decimal &other) const
{
    if (_size != other._size)
    {
        return true;
    }
    for (size_t i = 0; i < _size; ++i)
    {
        if (_array[i] != other._array[i])
        {
            return true;
        }
    }
    return false;
}
std::ostream &operator<<(std::ostream &os, const Decimal &obj)
{
    for (size_t i = 0; i < obj._size; ++i)
        os << obj._array[i];
    return os;
}

Decimal &Decimal::operator+=(const Decimal &other)
{
    int carry = 0;
    size_t maxSize = std::max(_size, other._size);
    unsigned char *newData = new unsigned char[maxSize + 1];

    for (size_t i = 0; i < maxSize; ++i)
    {
        int sum = carry;
        if (i < _size)
        {
            sum += _array[_size - i - 1] - '0';
        }
        if (i < other._size)
        {
            sum += other._array[other._size - i - 1] - '0';
        }
        newData[maxSize - i - 1] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry > 0)
    {
        newData[0] = carry + '0';
        maxSize++;
    }
    delete[] _array;
    _array = new unsigned char[maxSize];
    for (size_t i = 0; i < maxSize; ++i)
    {
        _array[i] = newData[i];
    }
    _size = maxSize;

    delete[] newData;
    return *this;
}

Decimal &Decimal::operator-=(const Decimal &other)
{
    if (_size < other._size)
    {
        throw std::invalid_argument("Right value is more than left, the answer will be less than 0");
    }

    int par = 0;
    for (size_t i = 0; i < _size; ++i)
    {
        int first_digit = (i < other._size) ? (other._array[other._size - 1 - i] - '0') : 0;
        int diff = (_array[_size - 1 - i] - '0') - first_digit - par;

        if (diff < 0)
        {
            _array[_size - 1 - i] = diff + 10 + '0';
            par = 1;
        }
        else
        {
            _array[_size - 1 - i] = diff + '0';
            par = 0;
        }
    }

    if (par != 0)
    {
        throw std::invalid_argument("Subtraction result is negative");
    }
    size_t first_non_zero = 0;
    while (first_non_zero < _size && _array[first_non_zero] == '0')
    {
        ++first_non_zero;
    }

    size_t new_size = _size - first_non_zero;
    if (new_size == 0)
    {
        new_size = 1;
        _array[0] = '0';
    }
    else
    {

        unsigned char *new_array = new unsigned char[new_size];
        for (size_t i = 0; i < new_size; ++i)
        {
            new_array[i] = _array[first_non_zero + i];
        }

        delete[] _array;
        _array = new_array;
    }

    _size = new_size;

    return *this;
}

Decimal &Decimal::operator=(const Decimal &other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] _array;
    _size = other._size;
    _array = new unsigned char[_size];
    for (size_t i = 0; i < _size; ++i)
    {
        _array[i] = other._array[i];
    }
    return *this;
}

Decimal &Decimal::operator=(Decimal &&other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    delete[] _array;

    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;

    return *this;
}

bool Decimal::operator>(const Decimal &other) const
{
    if (this == &other)
    {
        return false;
    }
    if (_size > other._size)
    {
        return true;
    }
    else if (_size < other._size)
    {
        return false;
    }
    else
    {
        for (size_t i = 1; i < _size; ++i)
        {
            if (_array[i] > other._array[i])
            {
                return true;
            }
            else if (_array[i] < other._array[i])
            {
                return false;
            }
        }
    }
    return false;
}
bool Decimal::operator<(const Decimal &other) const
{
    if (this == &other)
    {
        return false;
    }
    if (_size < other._size)
    {
        return true;
    }
    else if (_size > other._size)
    {
        return false;
    }
    else
    {
        for (size_t i = 1; i < _size; ++i)
        {
            if (_array[i] > other._array[i])
            {
                return false;
            }
            else if (_array[i] < other._array[i])
            {
                return true;
            }
        }
    }
    return false;
}
Decimal::~Decimal() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}