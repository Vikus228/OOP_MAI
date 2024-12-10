#include "Logger.h"

FileLogger::FileLogger() : file("log.txt", std::ios::app) {}

void FileLogger::update(const std::string &message)
{
    if (file.is_open())
    {
        file << message << std::endl;
    }
}

void ConsoleLogger::update(const std::string &message)
{
    std::cout << message << std::endl;
}