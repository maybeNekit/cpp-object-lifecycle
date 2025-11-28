#include <iostream>
#include <vector>
#include "Logger.h"
#include "TrackedString.h"
#include "Wrapper.h"

void testTask2() {
    Logger::getInstance().log("--- TASK 2: Constructors ---", Logger::Level::INFO);
    TrackedString a;
    TrackedString b("hello");
    std::string s = "world";
    TrackedString c(s);
    TrackedString d = c;
}

void testTask3() {
    Logger::getInstance().log("--- TASK 3: Init Lists ---", Logger::Level::INFO);
    Logger::getInstance().log("Variant A (Bad):", Logger::Level::INFO);
    {
        WrapperA wa("bad");
    }
    Logger::getInstance().log("Variant B (Good):", Logger::Level::INFO);
    {
        WrapperB wb("good");
    }
}

void testTask5() {
    Logger::getInstance().log("--- TASK 5: Vector ---", Logger::Level::INFO);
    std::vector<TrackedString> vec;

    Logger::getInstance().log("1. Push_back (temp):", Logger::Level::INFO);
    vec.push_back(TrackedString("temp"));

    Logger::getInstance().log("2. Push_back (existing):", Logger::Level::INFO);
    TrackedString ts("str");
    vec.push_back(ts);

    Logger::getInstance().log("3. Emplace_back:", Logger::Level::INFO);
    vec.emplace_back("emplaced");
}

void testTask6() {
    Logger::getInstance().log("--- TASK 6: Operators ---", Logger::Level::INFO);
    TrackedString a("Hello");
    TrackedString b("World");

    if (a != b) {
        Logger::getInstance().log("Strings are not equal", Logger::Level::INFO);
    }

    TrackedString c = a + b;
    std::cout << "Output test: " << c << std::endl;
}

int main() {
    auto& logger = Logger::getInstance();
    logger.setLevel(Logger::Level::INFO);

    logger.log("=== STARTING HOMEWORK 2 ===", Logger::Level::INFO);

    testTask2();
    testTask3();
    testTask5();
    testTask6();

    logger.log("=== FINISHED HOMEWORK 2 ===", Logger::Level::INFO);
    return 0;
}