include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(platform)

SET (MYUNIT_SOURCES 
    myunit.c  
)


SET (MYUNIT_HEADERS 
    myunit.h  
)

SET (MYUNIT_OBJECTS
    $<TARGET_OBJECTS:myunit_platform>
    )

add_library(myunit ${MYUNIT_SOURCES} ${MYUNIT_OBJECTS})
message(STATUS "MY_VARIABLE: ${MYUNIT_PLATFORM_SOURCES}")