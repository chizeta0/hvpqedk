
include_directories(${CMAKE_SOURCE_DIR}/src)

set(hvpqedk_SOURCES
  ${CMAKE_SOURCE_DIR}/src/kernel.c
  ${CMAKE_SOURCE_DIR}/src/rratio.c
  )

add_library(hvpqedk_obj
  ${hvpqedk_SOURCES}
  )

set_target_properties(hvpqedk_obj PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

add_library(hvpqedk SHARED
  $<TARGET_OBJECTS:hvpqedk_obj>
  )
set_target_properties(hvpqedk PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

install(TARGETS hvpqedk LIBRARY DESTINATION ${INSTALL_PATH}/lib)
install(DIRECTORY ./ DESTINATION ${INSTALL_PATH}/include/hvpqedk FILES_MATCHING PATTERN "*.h")

if(ENABLE_TESTS)
  add_subdirectory(tests)
endif()

