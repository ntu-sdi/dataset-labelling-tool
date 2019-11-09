cmake_minimum_required(VERSION 3.5)
project(dataset-labeling-tool LANGUAGES CXX)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

#-------INCLUDING ADDITIONAL LIBs-------#
#first you must clone them from github then build and install using cmake
#after that you find them by find package and link them to your main file
#!--sqlite3 does not need a package because it is a header only library--!
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(dataset-labeling-tool
        src/main.cpp
        src/gui.cpp
        include/gui.h
        )

target_link_libraries(dataset-labeling-tool PRIVATE Qt5::Widgets sqlite3 fmt nlohmann_json)

add_subdirectory(test) #comment this to disable tests showing up in target selection

