cmake_minimum_required(VERSION 3.0)
set (Boost_USE_STATIC_LIBS OFF)




find_package (Boost REQUIRED COMPONENTS unit_test_framework)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(../include ../src ../build/Dataset-Labelling-Tool_autogen/include)
 
add_executable (Tests
                Tests.cpp
                LinkedListsTests.cpp
                ImageModelTests.cpp
                ClassModelTests.cpp
                AnnotationModelTests.cpp

                ../../src/ClassModel.cpp
                ../../include/ClassModel.h
                ../../src/ImageModel.cpp
                ../../include/ImageModel.h
                ../../src/AnnotationModel.cpp
                ../../include/AnnotationModel.h
                ../build/Dataset-Labelling-Tool_autogen/include/ui_MainView.h
        )

target_link_libraries (Tests PRIVATE ${Boost_LIBRARIES} Qt5::Widgets )

