cmake_minimum_required(VERSION 3.0)

project(hvpqedk)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wpedantic -O2")

if(IS_ABSOLUTE "${CMAKE_INSTALL_PREFIX}")
  set(INSTALL_PATH ${CMAKE_INSTALL_PREFIX})
else()
  get_filename_component(INSTALL_PATH ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_PREFIX} ABSOLUTE)
endif()
message(STATUS "found absolute install path '${INSTALL_PATH}'") 

add_definitions(-DC_FLAGS="${CMAKE_C_FLAGS}")

add_subdirectory(src)
