cmake_minimum_required(VERSION 3.0)
set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(../include ../src)
add_executable (Tests
                Tests.cpp
                LinkedLists-tests.cpp
                AnnotationController-Tests.cpp
                AnnotationModel-Tests.cpp
                ClassController-Tests.cpp
                ClassModel-Tests.cpp
                ImageController-Tests.cpp
                ImageModel-Tests.cpp
        )

target_link_libraries (Tests PRIVATE ${Boost_LIBRARIES} )
