cmake_minimum_required(VERSION 4.1)
project(claude)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(claude
        CampusMap.cpp
        CampusMap.h
        FileManager.cpp
        main.cpp
        "StudentList (1).cpp"
        StudentList.cpp
        StudentList.h)
