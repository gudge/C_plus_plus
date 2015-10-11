set(CMAKE_LEGACY_CYGWIN_WIN32 0)
cmake_minimum_required (VERSION 2.8)
project (prog)

#version number
#set (CMakeHelloWorld_VERSION_MAJOR 1)
#set (CMakeHelloWorld_VERSION_MINOR 0)

#include the subdirectory containing our libs
#add_subdirectory (Hello)
#include_directories(Hello)
#indicate the entry point for the executable
#add_executable (Hello HelloWorld.cpp)
#SET (CMAKE_CXX_COMPILER = "/usr/bin/g++")
#SET (CMAKE_C_COMPILER = "/usr/bin/gcc")
#SET(GXX_14_FLAGS "--std=c++14")
#SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GXX_14_FLAGS}" )
add_executable (test_executable Test.cpp)

# Indicate which libraries to include during the link process.
#target_link_libraries (d Hello)

#install (TARGETS Hello DESTINATION bin)
