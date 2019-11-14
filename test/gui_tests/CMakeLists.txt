set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

# 'Boost_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests

include_directories(../../include)
add_executable (gui_test gui_test.cpp
        )

set_target_properties(
        gui_test
        PROPERTIES
        SUFFIX ".o"
)

target_link_libraries (gui_test ${Boost_LIBRARIES})
