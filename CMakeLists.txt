cmake_minimum_required(VERSION 3.5)

project(dataset-labeling-tool LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(src/ include/)
add_executable(MainView
  src/main.cpp
  src/MainView.cpp
  src/MainController.cpp
  src/ImageController.cpp
  src/ClassController.cpp
  src/AnnotationController.cpp
  src/ImageModel.cpp
  src/ClassModel.cpp
  src/AnnotationModel.cpp
  include/MainView.ui
  include/MainView.h
  include/MainController.h
  include/ImageController.h
  include/ClassController.h
  include/AnnotationController.h
  include/ImageModel.h
  include/ClassModel.h
  include/AnnotationModel.h
  include/LinkedList.h
  include/exceptions.h
)

target_link_libraries(MainView PRIVATE Qt5::Widgets)
add_subdirectory(tests)


#this only runs on pasing cmake file, how to make it run on build?
