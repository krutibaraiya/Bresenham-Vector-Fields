cmake_minimum_required(VERSION 3.17)
project(Vector_Line)
set(OpenGlLinkers -lglut -lGLU -lGL)
set(CMAKE_CXX_STANDARD 17)

add_executable(Vector_Line main.cpp)
target_link_libraries(Vector_Line ${OpenGlLinkers})