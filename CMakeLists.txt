cmake_minimum_required (VERSION 2.8.12)
#-------------------------------------------------------------------------------
project (AlgorithmicToolbox)
#-------------------------------------------------------------------------------
SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread" )
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
#-------------------------------------------------------------------------------
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
#-------------------------------------------------------------------------------
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeTools")
#-------------------------------------------------------------------------------
add_subdirectory(week1_programming_challenges)
add_subdirectory(week2_algorithmic_warmup)
add_subdirectory(week3_greedy_algorithms)
#add_subdirectory(week4_divide_and_conquer)
#add_subdirectory(week5_dynamic_programming1)
#add_subdirectory(week6_dynamic_programming2)
