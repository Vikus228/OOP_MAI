#include <iostream>
#include "class.hpp"

int main()
{
    try
    {
        std::string first_num, second_num;
        std::cout << "Enter first number: ";
        std::cin >> first_num;
        std::cout << "Enter second number: ";
        std::cin >> second_num;
        Decimal first(first_num);
        Decimal second(second_num);
        first -= second;
        std::cout << "result of subtraction: ";
        for (size_t i = 0; i < first.get_size(); ++i)
        {
            std::cout << first.get_char4iki()[i];
        }
        std::cout << std::endl;
        first += second;
        first += second;
        std::cout << "result of addition " << first << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
    try
    {
        std::initializer_list<unsigned char> first_one{'2', '8', '2'};
        std::initializer_list<unsigned char> second_two{'2', '2', '8'};
        Decimal new_first(first_one);
        Decimal new_second(second_two);
        Decimal result("123");
        result += new_second;
        std::cout << "result of addition: ";
        for (size_t i = 0; i < result.get_size(); ++i)
        {
            std::cout << result.get_char4iki()[i];
        }
        std::cout << std::endl;
        if (new_first != new_second)
        {
            std::cout << new_first << " and " << new_second << " are not equal" << std::endl;
        }
        Decimal just_two("2");
        new_second += just_two;
        std::cout << new_first;
        std::cout << std::endl;
        std::cout << new_second;
        std::cout << std::endl;
        if (new_first == new_second)
        {
            std::cout << "now they are equal" << std::endl;
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
    return 0;
}