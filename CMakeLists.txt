cmake_minimum_required(VERSION 3.10)
project(testgene)

set(CMAKE_CXX_STANDARD 14)
add_executable(GenSpeed generationByCubitect/generator.cpp generationByCubitect/layers.cpp generationByCubitect/finders.cpp main.cpp)