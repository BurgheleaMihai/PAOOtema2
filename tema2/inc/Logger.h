#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger
{
public:
    Logger() = default;
    ~Logger() = default;

    void log(const std::string& msg);

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

#endif
