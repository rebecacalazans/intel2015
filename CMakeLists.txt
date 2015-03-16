cmake_minimum_required(VERSION 2.8)

project("RoboIME Intel 2015")

set(INTEL_VERSION_MAJOR 0)
set(INTEL_VERSION_MINOR 1)
set(INTEL_VERSION_PATCH 0)

set(PROTOCOL_VERSION 1)
configure_file(
  "${PROJECT_SOURCE_DIR}/include/protocol_version.h.in"
  "${PROJECT_SOURCE_DIR}/include/protocol_version.h")

# For YouCompleteMe integration
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

# Set C++11 as standard compilation
#add_definitions("-str=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${PROJECT_SOURCE_DIR}/include)

# Output configuration
include(${PROJECT_SOURCE_DIR}/cmake/Utils.cmake)
standard_paths(${PROJECT_BINARY_DIR} bin lib)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(src)
