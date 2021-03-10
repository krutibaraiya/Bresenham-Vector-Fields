cmake_minimum_required(VERSION 3.17)
project(Line)
set(OpenGlLinkers -lglut -lGLU -lGL)
set(CMAKE_CXX_STANDARD 17)

add_executable(Line line.cpp)
target_link_libraries(Line ${OpenGlLinkers})