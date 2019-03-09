cmake_minimum_required(VERSION 3.13)
project(testingplace)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab4 main.cpp Vehicle.cpp Vehicle.h Vector.cpp Vector.h Car.cpp Car.h)
