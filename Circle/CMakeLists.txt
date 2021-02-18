cmake_minimum_required(VERSION 3.17)
project(Circle)

set(CMAKE_CXX_STANDARD 17)
set(OpenGlLinkers -lglut -lGLU -lGL)
add_executable(Circle main.cpp)
target_link_libraries(Circle ${OpenGlLinkers})