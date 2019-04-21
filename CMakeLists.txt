cmake_minimum_required(VERSION 3.13)
project(testgene)

set(CMAKE_CXX_STANDARD 14)
add_executable(test test.cpp)
add_executable(testgene generationByCubitect/generator.cpp generationByCubitect/layers.cpp generationByCubitect/finders.cpp main.cpp)