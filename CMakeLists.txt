cmake_minimum_required(VERSION 3.20)
project(HW2)

set(CMAKE_CXX_STANDARD 17)
file(GLOB SOURCES *.cpp *.h)

add_executable(HW2 ${SOURCES}
        Logger.cpp
        TrackedString.cpp
        Wrapper.cpp)