cmake_minimum_required(VERSION 3.17)

project(tdd-mcpp)
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    built_binary
    gtest_eg.cc
)

target_link_libraries(
    built_binary
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(built_binary)
