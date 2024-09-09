#include <function.h>
#include <cstdint>
#include <stdexcept>

unsigned int findMaxDividend(unsigned int devider, unsigned int bound)
{
    unsigned int result = bound / devider * devider;
    if (!result)
    {
        throw std::runtime_error("");
    }

    return result;
}