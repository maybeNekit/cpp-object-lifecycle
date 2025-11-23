#pragma once

#include <string>
#include <fstream>

class Logger {
public:
    enum class Level {
        ERROR,
        WARNING,
        INFO,
        DEBUG
    };

    static Logger& getInstance();

    void log(const std::string& message, Level level);
    void setLevel(Level level);

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

private:
    Logger();
    ~Logger();

    static std::string levelToString(Level level) ;

    std::ofstream logFile;
    Level currentLevel = Level::DEBUG;
};