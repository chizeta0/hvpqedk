cmake_minimum_required(VERSION 3.0)

project(hvpqedk)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wpedantic -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Werror -Wpedantic -O2")

if(IS_ABSOLUTE "${CMAKE_INSTALL_PREFIX}")
  set(INSTALL_PATH ${CMAKE_INSTALL_PREFIX})
else()
  get_filename_component(INSTALL_PATH ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_PREFIX} ABSOLUTE)
endif()
message(STATUS "found absolute install path '${INSTALL_PATH}'") 

add_definitions(-DC_FLAGS="${CMAKE_C_FLAGS}")
add_definitions(-DCXX_FLAGS="${CMAKE_CXX_FLAGS}")

set(ENABLE_TESTS ON)
find_package(GTest)
if(GTest_FOUND)
  include_directories(${GTEST_INCLUDE_DIRS})
else()
  set(ENABLE_TESTS OFF)
endif()
find_package(Threads)
if(NOT Threads_FOUND)
  set(ENABLE_TESTS OFF)
endif()

if(ENABLE_TESTS)
  enable_testing()
endif()

add_subdirectory(src)
