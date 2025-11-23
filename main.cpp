#include "Logger.h"

int main() {
    auto& logger = Logger::getInstance();
    logger.setLevel(Logger::Level::DEBUG);

    logger.log("start", Logger::Level::INFO);
    logger.log("debug", Logger::Level::DEBUG);
    logger.log("Error", Logger::Level::ERROR);

    return 0;
}