#include "Logger.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

Logger::Logger() {
    logFile.open("log.txt");
    if (!logFile.is_open()) {
        std::cerr << "errror" << '\n';
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::setLevel(Level level) {
    currentLevel = level;
}

void Logger::log(const std::string& message, Level level) {
    if (level > currentLevel) {
        return;
    }

    auto now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(now);

    if (logFile.is_open()) {
        logFile << "[" << std::put_time(std::localtime(&time_t_now), "%H:%M:%S") << "] "
                << "[" << levelToString(level) << "] "
                << message << std::endl;
    }
}

std::string Logger::levelToString(Level level) {
    switch (level) {
        case Level::ERROR:   return "ERROR";
        case Level::WARNING: return "WARNING";
        case Level::INFO:    return "INFO";
        case Level::DEBUG:   return "DEBUG";
        default: return "UNKNOWN";
    }
}