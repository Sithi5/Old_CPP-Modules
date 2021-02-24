#ifndef OLD_CPP_MODULE_LOGGER_HPP
#define OLD_CPP_MODULE_LOGGER_HPP

#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>

class Logger {
public:
    Logger(const std::string &filename);
    ~Logger();
    const std::string &getFilename() const;

    void setFilename(const std::string &filename);
    void log(std::string const &dest, std::string const &message);


private:
    void logToConsole(std::string const &log);
    void logToFile(std::string const &log);
    std::string makeLogEntry(std::string const &log);
    std::string _filename;

};


#endif //OLD_CPP_MODULE_LOGGER_HPP
