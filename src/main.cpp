#include <iostream>
#include <function.h>

int main()
{
    unsigned int devider, bound;
    std::cin >> devider >> bound;

    try
    {
        int answer = findMaxDividend(devider, bound);
        std::cout << answer << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "No answer" << std::endl;
    }

    return 0;
}