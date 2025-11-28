#include "TrackedString.h"
#include "Logger.h"

int TrackedString::objectsCount = 0;

TrackedString::TrackedString() : TrackedString("") {
    Logger::getInstance().log("[delegation] default -> char*", Logger::Level::INFO);
}

TrackedString::TrackedString(const std::string& str) {
    value = str;
    objectsCount++;
    id = objectsCount;
    std::string msg = "[ctor string] id=" + std::to_string(id) +
                      " this=" + std::to_string((long long)this) +
                      " val=" + value;
    Logger::getInstance().log(msg, Logger::Level::INFO);
}

TrackedString::TrackedString(const char* str) : TrackedString(std::string(str)) {
    Logger::getInstance().log("[delegation] char* -> string", Logger::Level::INFO);
}

TrackedString::TrackedString(const TrackedString& other) {
    value = other.value;
    objectsCount++;
    id = objectsCount;
    std::string msg = "[ctor copy] id=" + std::to_string(id) +
                      " this=" + std::to_string((long long)this) +
                      " from=" + std::to_string(other.id);
    Logger::getInstance().log(msg, Logger::Level::INFO);
}

TrackedString::~TrackedString() {
    std::string msg = "[dtor] id=" + std::to_string(id) +
                      " this=" + std::to_string((long long)this);
    Logger::getInstance().log(msg, Logger::Level::INFO);
}

std::ostream& operator<<(std::ostream& os, const TrackedString& ts) {
    Logger::getInstance().log("[operator<<] printing value", Logger::Level::INFO);
    os << ts.value;
    return os;
}

bool operator==(const TrackedString& a, const TrackedString& b) {
    Logger::getInstance().log("[operator==] compare", Logger::Level::INFO);
    return a.value == b.value;
}

bool operator!=(const TrackedString& a, const TrackedString& b) {
    Logger::getInstance().log("[operator!=] compare", Logger::Level::INFO);
    return a.value != b.value;
}

TrackedString operator+(const TrackedString& a, const TrackedString& b) {
    Logger::getInstance().log("[operator+] adding", Logger::Level::INFO);
    return TrackedString(a.value + b.value);
}