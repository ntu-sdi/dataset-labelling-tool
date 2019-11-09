set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

# 'Boost_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests

include_directories(../include)
add_executable (Boost_Tests test1.cpp
        ../src/dummyclass.cpp
        )

set_target_properties(
        Boost_Tests
        PROPERTIES
        SUFFIX ".o"
)

target_link_libraries (Boost_Tests ${Boost_LIBRARIES})
