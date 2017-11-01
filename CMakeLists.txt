cmake_minimum_required (VERSION 2.6)
project (neurons)

set(CMAKE_CXX_FLAGS "-W -Wall -pedantic -std=c++11")
enable_testing()

add_subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable (neurons Neuron.cpp main_neuron.cpp Network.cpp)
add_executable (test_main Neuron.cpp test_main.cpp)

target_link_libraries(test_main gtest gtest_main ${GTEST_BOTH_LIBRAIRIES}pthread)
add_test(test_main test_main)

