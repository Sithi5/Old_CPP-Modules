#ifndef OLD_CPP_MODULE_LOGGER_HPP
#define OLD_CPP_MODULE_LOGGER_HPP

#include <iostream>

class Logger {
public:
    Logger();
    ~Logger();

private:
    void logToConsole(std::string log);
    void logToFile(std::string log);
};


#endif //OLD_CPP_MODULE_LOGGER_HPP
