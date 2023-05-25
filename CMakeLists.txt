cmake_minimum_required(VERSION 3.14)
project(benchmark-issue-1604)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
set(CMAKE_BUILD_TYPE "Release")

include(FetchContent)
FetchContent_Declare(
    googlebenchmark
    URL https://github.com/google/benchmark/archive/refs/tags/v1.8.0.zip
)
FetchContent_MakeAvailable(googlebenchmark)

add_executable(example example.cpp)
target_link_libraries(example benchmark::benchmark_main)
