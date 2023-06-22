
add_executable(ktest kernel_test.cc)
add_dependencies(ktest hvpqedk)
target_link_libraries(ktest ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} hvpqedk)
add_test(NAME ktest COMMAND ktest)
