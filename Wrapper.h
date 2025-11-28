#pragma once
#include <string>
#include "TrackedString.h"

class WrapperA {
public:
    WrapperA(const std::string& s);
private:
    TrackedString str;
};

class WrapperB {
public:
    WrapperB(const std::string& s);
private:
    TrackedString str;
};