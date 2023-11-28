cmake_minimum_required(VERSION 3.26)
project(staffSystem)

set(CMAKE_CXX_STANDARD 23)

include_directories(
        src/work.h
        src/workManger.h
        sre/boss.h
        src/manager.h
        src/employee.h
)

add_executable(staffSystem
        src/main.cpp
        src/workManger.cpp
        src/boss.cpp
        src/employee.cpp
        src/manager.cpp
)
