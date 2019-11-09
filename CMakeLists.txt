cmake_minimum_required(VERSION 3.0)
project(dataset-labeling-tool)
include_directories(include)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(test) #comment this to disable tests showing up in target selection

add_executable(dataset-labeling-tool src/main.cpp
        src/dummyclass.cpp
        )

#-------INCLUDING ADDITIONAL LIBs-------#
#first you must clone them from github then build and install using cmake
#after that you find them by find package and link them to your main file
#!--sqlite3 does not need a package because it is a header only library--!

find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)
set(CMAKE_PREFIX_PATH /opt/Qt5.13.2/5.13.2/gcc_64)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
target_link_libraries(dataset-labeling-tool sqlite3 fmt nlohmann_json Qt5::Widgets)