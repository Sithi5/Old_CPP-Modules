#include "Logger.hpp"

Logger::Logger() {}

Logger::~Logger() {

}

void Logger::logToConsole(std::string log) {
    std::cout << log << std::endl;
}

void Logger::logToFile(std::string log) {

}
