cmake_minimum_required(VERSION 3.17)
project(Vector_Polyline)
set(OpenGlLinkers -lglut -lGLU -lGL)
set(CMAKE_CXX_STANDARD 17)

add_executable(Vector_Polyline polyline.cpp)
target_link_libraries(Vector_Polyline ${OpenGlLinkers})