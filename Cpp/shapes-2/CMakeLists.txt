cmake_minimum_required(VERSION 3.24)
project(shapes_2)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors)

include_directories(include)

set(SOURCE_FILES
        src/shapes.cpp
        include/shapes.hpp)

add_executable(shapes_1 ${SOURCE_FILES} main.cpp)

set(SOURCES_FILES_TESTS
        test/test_shapes.cpp
        )

add_executable(shapes_1__test ${SOURCE_FILES} ${SOURCES_FILES_TESTS} test/main_gtest.cpp)

target_include_directories(shapes_1__test PUBLIC
        ../../googletest-master/googlemock/include
        ../../googletest-master/googletest/include
        )

add_subdirectory(../../googletest-master googletest-master)

target_link_libraries(shapes_1__test gmock)