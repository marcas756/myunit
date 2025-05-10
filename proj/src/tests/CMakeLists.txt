include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(myunit_selftest myunit_selftest.c )
#target_compile_definitions(myunit_selftest PRIVATE  MYUNIT_VERBOSE=MYUNIT_VERB3_ALL_ASSERTS)
target_link_libraries(myunit_selftest myunit)
