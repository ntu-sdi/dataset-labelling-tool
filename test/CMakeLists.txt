cmake_minimum_required(VERSION 3.15)
set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

find_package(OpenCV REQUIRED)
include_directories(../include ../src)
add_executable (Tests
                TheAbsoluteUnit.cpp
                linkedListTest.cpp
                ImageBrowserTests.cpp
                ../src/ImageBrowser.cpp
        )

set_target_properties(
        Tests
        PROPERTIES
        SUFFIX ".o"
)

target_link_libraries (Tests fmt ${OpenCV_LIBS} ${Boost_LIBRARIES} )
