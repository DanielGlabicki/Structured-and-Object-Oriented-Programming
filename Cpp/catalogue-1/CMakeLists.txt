cmake_minimum_required(VERSION 3.24)
project(catalogue_1)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors)

include_directories(include)

set(SOURCE_FILES
        src/catalogue.cpp
        include/catalogue.hpp)

add_executable(catalogue_1 ${SOURCE_FILES} main.cpp)

set(SOURCES_FILES_TESTS
        test/test_product.cpp
        test/test_catalogue.cpp
        )

add_executable(catalogue_1__test ${SOURCE_FILES} ${SOURCES_FILES_TESTS} test/main_gtest.cpp)

# TODO: Poniższe ścieżki prawdopodobnie musisz zmienić...
target_include_directories(catalogue_1__test PUBLIC
        ../../googletest-master/googlemock/include
        ../../googletest-master/googletest/include
        ) #do czego sie te sciezki odnosza wgl?

# TODO: Poniższą ścieżkę prawdopodobnie musisz zmienić...
add_subdirectory(../../googletest-master googletest-master)

target_link_libraries(catalogue_1__test gmock)
