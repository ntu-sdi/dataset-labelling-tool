cmake_minimum_required(VERSION 3.0)
project(dataset-labeling-tool LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(UNIX)
	set (CMAKE_PREFIX_PATH /opt/Qt5.13.2/5.13.2/gcc_64/lib/cmake)
endif(UNIX)

find_package(OpenCV REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(fmt CONFIG REQUIRED)


include_directories(include)
add_executable(dataset-labeling-tool
        src/main.cpp
        src/gui.cpp
        include/gui.h
        include/ui_gui.h
        src/ImageBrowser.cpp
        include/ImageBrowser.h
        include/LinkedList.h
		include/exceptions.h
		include/win_dirent.h)

add_subdirectory(test) #comment this to disable tests showing up in target selection
target_link_libraries(dataset-labeling-tool PRIVATE ${OpenCV_LIBS} fmt::fmt fmt::fmt-header-only Qt5::Widgets)
