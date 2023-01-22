cmake_minimum_required(VERSION 3.20)
project(CAssociation_CStudentList)

set(CMAKE_CXX_STANDARD 14)

add_executable(CAssociation_CStudentList main.cpp MyString.h MyString.cpp CStudent.cpp CStudent.h CStudentList.cpp CStudentList.h)
