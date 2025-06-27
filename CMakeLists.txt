cmake_minimum_required(VERSION 3.18.4)

project(
  ErrorDebugLogger
  VERSION 0.0.0.1
  DESCRIPTION "Logger My Way"
  LANGUAGES CXX Fortran C
  )

set(CMAKE_VERBOSE_MAKEFILE "ON" CACHE STRING "" FORCE)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib CACHE STRING "" FORCE)
set(CMAKE_BUILD_RPATH /home/kmdetullio/working/Boost/boost/stage/lib)

add_definitions(-DGLOBAL_LOG_ENABLED -DREENTRANT -DBOOST_ERROR_CODE_HEADER_ONLY -DBOOST_LOG_DYN_LINK -DBOOST_ENABLE_ASSERT_HANDLER -DBOOST_SYSTEM_NO_DEPRECATED)

add_compile_options(-std=c++20 -isystem)
add_compile_options(-Wall -Wswitch -Wdeprecated-declarations -Wempty-body -Wconversion -Wreturn-type -Wparentheses -Wformat -Wuninitialized -Wunreachable-code -Wunused-function -Wunused-value -Wunused-variable)
add_compile_options(-fstrict-aliasing -fno-omit-frame-pointer -fthreadsafe-statics -fexceptions -frtti)

add_compile_options(-ggdb3)
find_package(Boost 1.74.0 REQUIRED COMPONENTS log unit_test_framework)

set(CMAKE_BUILD_RPATH ${Boost_LIBRARY_DIRS})
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
set(GLOBAL_LOG_ENABLED true)
add_library(KDeTLogger Logger.cpp Assertions.cpp)
add_executable(LoggerTests TestDriver.cpp TestSuite.cpp)
add_dependencies(LoggerTests KDeTLogger)

target_link_libraries(LoggerTests KDeTLogger ${Boost_LIBRARIES} ${CMAKE_DL_LIBS} stdc++fs)



