cmake_minimum_required(VERSION 3.0)
set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

SET(AUTOGEN_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/../MainView_autogen/include")
include_directories(../include ../src ${AUTOGEN_BUILD_DIR})

add_executable (Tests
                Tests.cpp
                LinkedLists-tests.cpp
                AnnotationController-Tests.cpp
                AnnotationModel-Tests.cpp
                ClassController-Tests.cpp
                ClassModel-Tests.cpp
                ImageController-Tests.cpp
                ImageModel-Tests.cpp
                ${AUTOGEN_BUILD_DIR}/ui_MainView.h
        )

target_link_libraries (Tests PRIVATE ${Boost_LIBRARIES} Qt5::Widgets )
