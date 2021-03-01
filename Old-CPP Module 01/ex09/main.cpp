#include "Logger.hpp"

int     main(void){
    Logger logger = Logger("log.txt");

    logger.log("logToFile", "This is a log.");
    logger.log("logToConsole", "This is a file log.");
    logger.log("logToFile", "This is another log.");
    logger.log("logToConsole", "This is another file log.");

    try{
        logger.log("logToStderr", "This is an error log");
    }
    catch (std::exception &error){
        std::cerr << error.what() << std::endl;
    }

    return (0);
}