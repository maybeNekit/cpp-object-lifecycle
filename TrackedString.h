#pragma once
#include <string>
#include <iostream>

class TrackedString {
public:
    TrackedString();
    TrackedString(const std::string& str);
    TrackedString(const char* str);
    TrackedString(const TrackedString& other);
    ~TrackedString();

    friend std::ostream& operator<<(std::ostream& os, const TrackedString& ts);
    friend bool operator==(const TrackedString& a, const TrackedString& b);
    friend bool operator!=(const TrackedString& a, const TrackedString& b);
    friend TrackedString operator+(const TrackedString& a, const TrackedString& b);

private:
    std::string value;
    int id;
    static int objectsCount;
};