cmake_minimum_required(VERSION 3.5)
project(dataset-labeling-tool LANGUAGES CXX)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set (CMAKE_PREFIX_PATH /opt/Qt5.13.2/5.13.2/gcc_64/lib/cmake)
#-------INCLUDING ADDITIONAL LIBs-------#
#first you must clone them from github then build and install using cmake
#after that you find them by find package and link them to your main file
#!--sqlite3 does not need a package because it is a header only library--!

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(OpenCV REQUIRED)

find_package(OpenCV REQUIRED)

add_executable(dataset-labeling-tool
        src/main.cpp
        src/gui.cpp
        include/gui.h
        include/ui_gui.h
        include/LinkedList.h include/exceptions.h)

target_link_libraries(dataset-labeling-tool PRIVATE Qt5::Widgets)

add_subdirectory(test) #comment this to disable tests showing up in target selection

target_link_libraries(dataset-labeling-tool PRIVATE Qt5::Widgets fmt ${OpenCV_LIBS})
add_subdirectory(test)
