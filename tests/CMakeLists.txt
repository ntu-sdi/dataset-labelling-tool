cmake_minimum_required(VERSION 3.0)
set (Boost_USE_STATIC_LIBS OFF)


if(UNIX)
	set (CMAKE_PREFIX_PATH /opt/Qt5.13.2/5.13.2/gcc_64/lib/cmake)
endif(UNIX)


find_package (Boost REQUIRED COMPONENTS unit_test_framework)
find_package(Qt5 COMPONENTS Widgets REQUIRED)



SET(AUTOGEN_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/MainView_autogen/include")
include_directories(../include ../src ${AUTOGEN_BUILD_DIR})

add_executable (Tests
                Tests.cpp
                LinkedListsTests.cpp
                ${AUTOGEN_BUILD_DIR}/ui_MainView.h
        )

target_link_libraries (Tests PRIVATE ${Boost_LIBRARIES} Qt5::Widgets )

