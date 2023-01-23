cmake_minimum_required(VERSION 3.23)
project(Story_Maker)

set(CMAKE_CXX_STANDARD 20)

add_executable(Story_Maker main.cpp Page.cpp Book.cpp Page.h Script/Script.h Script/AssignmentScript.h Book.h Variable/Equation.cpp Variable/Equation.h Script/AssignmentScript.h Script/BoolScript.h Script/BoolScript.cpp Script/DisplayScript.h Script/ScriptVector.h Script/DisplayScript.cpp Script/IfScript.cpp Script/IfScript.h Script/WhileScript.h Script/ScriptVector.cpp)
