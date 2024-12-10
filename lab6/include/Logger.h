#ifndef LOGGER_H
#define LOGGER_H

#include "Observer.h"
#include <fstream>
#include <iostream>

class FileLogger : public Observer
{
public:
    FileLogger();
    void update(const std::string &message) override;

private:
    std::ofstream file;
};

class ConsoleLogger : public Observer
{
public:
    void update(const std::string &message) override;
};

#endif // LOGGER_H