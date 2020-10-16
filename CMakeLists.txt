cmake_minimum_required(VERSION 3.10)
project(testgene)

set(CMAKE_CXX_STANDARD 14)
add_executable(GenSpeed main.cpp generationByCubitect/finders.c generationByCubitect/generator.h generationByCubitect/layers.h generationByCubitect/generator.c generationByCubitect/layers.c)
#add_executable(GenSpeed2 main2.cpp generationByCubitect/finders.c generationByCubitect/generator.h generationByCubitect/layers.h generationByCubitect/generator.c generationByCubitect/layers.c)