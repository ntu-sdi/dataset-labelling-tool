cmake_minimum_required(VERSION 3.0)
set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
find_package(OpenCV REQUIRED)
find_package(fmt CONFIG REQUIRED)

include_directories(../include ../src)
add_executable (Tests
                TheAbsoluteUnit.cpp
                linkedListTest.cpp
                ImageBrowserTests.cpp
                ../src/ImageBrowser.cpp
        )

target_link_libraries (Tests PRIVATE fmt::fmt fmt::fmt-header-only ${OpenCV_LIBS} ${Boost_LIBRARIES} )