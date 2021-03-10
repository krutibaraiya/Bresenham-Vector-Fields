cmake_minimum_required(VERSION 3.17)
project(Vector_Circle)
set(OpenGlLinkers -lglut -lGLU -lGL)
set(CMAKE_CXX_STANDARD 17)

add_executable(Vector_Circle vector_circle.cpp)
target_link_libraries(Vector_Circle ${OpenGlLinkers})