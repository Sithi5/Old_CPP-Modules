#include "Logger.hpp"

Logger::Logger(const std::string &filename) : _filename(filename) {}
Logger::~Logger() {}
const std::string &Logger::getFilename() const {return _filename;}
void Logger::setFilename(const std::string &filename) {_filename = filename;}



void Logger::logToConsole(std::string const &log) {
    std::cout << this->makeLogEntry(log) << std::endl;
}


void Logger::logToFile(std::string const &log) {
    std::ofstream ofs(this->getFilename().c_str(), std::ios::app);
    if (!ofs.is_open()) {
        throw std::runtime_error("error when opening a file.");
    }
    ofs << this->makeLogEntry(log) << std::endl;
    ofs.close();
}

std::string Logger::makeLogEntry(std::string const &log) {
    time_t now = time(0);
    std::stringstream sstr;
    tm *ltm = localtime(&now);

    sstr << std::setfill('0') << "[" << 1900 + ltm->tm_year << std::setw(2) << ltm->tm_mon + 1 << std::setw(2) << ltm->tm_mday << "_";
    sstr << std::setfill('0') <<std::setw(2) << ltm->tm_hour << std::setw(2) << ltm->tm_min << std::setw(2) << ltm->tm_sec << "]";
    sstr << " " << log;
    return (sstr.str());
}


void Logger::log(const std::string &dest, const std::string &message) {
    void (Logger::*p[2])(std::string const & target) = {
            &Logger::logToConsole,
            &Logger::logToFile,
    };
    std::string key[2] = {
            "logToConsole",
            "logToFile",
    };
    int key_size = sizeof(key) / sizeof(*key);

    for(int i = 0; i < key_size; i++){
        if (!key[i].compare(dest)){
            (this->*p[i])(message);
            return;
        }
    }
    throw std::runtime_error("method is unavailable.");
}

