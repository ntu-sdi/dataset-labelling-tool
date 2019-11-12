zcmake_minimum_required(VERSION 3.5)

project(gui LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(gui
  main.cpp
  gui.cpp
  gui.h
  gui.ui
)

target_link_libraries(gui PRIVATE Qt5::Widgets)
execute_process (
    COMMAND bash -c "cp gui_autogen/include/ui_gui.h ../include"
)

#this only runs on pasing cmake file, how to make it run on build?
