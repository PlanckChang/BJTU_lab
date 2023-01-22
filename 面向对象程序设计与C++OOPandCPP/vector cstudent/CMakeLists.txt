cmake_minimum_required(VERSION 3.20)
project(vector_cstudent)

set(CMAKE_CXX_STANDARD 14)

add_executable(vector_cstudent main.cpp MyString.cpp MyString.h student.cpp student.h studentlist.h studentlist.cpp)
