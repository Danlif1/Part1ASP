cmake_minimum_required(VERSION 3.14)
project("Part1ASP")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch Google Test.
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# Enable testing.
enable_testing()

# Source files for test.
set(SOURCE_FILES_TEST
        src/BloomFilter.cpp
        src/BloomFilter.h
        src/HashOnce.cpp
        src/HashTwice.cpp
        src/HashFunction.h
        )

# Test files.
set(TEST_FILES
        tests/test_main.cpp
        tests/BloomFilter_test.cpp
        src/HashFunction.h
        src/HashOnce.h
        src/HashTwice.h
        )

# Source files for manual running.
set(SOURCE_FILES
        src/BloomFilter.cpp
        src/BloomFilter.h
        src/HashOnce.cpp
        src/HashTwice.cpp
        src/HashFunction.h
        src/main.cpp
        )

# Create the test executable.
add_executable(BloomFilterTests ${TEST_FILES} ${SOURCE_FILES_TEST})

# Create the manual executable.
add_executable(MainExecutable ${SOURCE_FILES})

# Link Google Test to the test executable.
target_link_libraries(BloomFilterTests PRIVATE gtest gtest_main)

# Include the source directory for tests.
target_include_directories(BloomFilterTests PRIVATE src)

# Additional configuration for macOS.
if(APPLE)
    find_package(Threads REQUIRED)
    target_link_libraries(BloomFilterTests PRIVATE Threads::Threads)
endif()

# Discover and run tests using Google Test.
include(GoogleTest)
gtest_discover_tests(BloomFilterTests)