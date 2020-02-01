cmake_minimum_required(VERSION 3.5)

project(gui LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(src/ include/)
add_executable(gui
  src/main.cpp
  src/gui.cpp
  src/maincontroller.cpp
  include/gui.ui
  include/gui.h
  include/maincontroller.h
 
)

target_link_libraries(gui PRIVATE Qt5::Widgets)


#this only runs on pasing cmake file, how to make it run on build?
