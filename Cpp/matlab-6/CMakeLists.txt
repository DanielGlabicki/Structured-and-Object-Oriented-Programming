cmake_minimum_required(VERSION 3.13)

set(PROJECT_ID matlab_5)

set(SOURCE_FILES
        src/matlab.cpp
        include/matlab.hpp
        )

set(SOURCES_FILES_TESTS
        test/test_vector.cpp
        )

include(../SetCommonConfig.cmake)
