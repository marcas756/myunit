cmake_minimum_required (VERSION 3.8)
project(myunit C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(platform)


SET (MYUNIT_HEADERS 
    myunit.h  
)

SET (MYUNIT_OBJECTS
    $<TARGET_OBJECTS:myunit_platform>
    )

add_library(myunit ${MYUNIT_OBJECTS})

add_executable(myunit_selftest myunit_selftest.c )
#target_compile_definitions(myunit_selftest PRIVATE  MYUNIT_VERBOSE=MYUNIT_VERB3_ALL_ASSERTS)
target_link_libraries(myunit_selftest myunit)
