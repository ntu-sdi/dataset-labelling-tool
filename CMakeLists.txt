cmake_minimum_required(VERSION 3.0)
project(dataset-labeling-tool)
include_directories(include)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(test)
add_executable(dataset-labeling-tool src/main.cpp
        src/dummyclass.cpp
        )
