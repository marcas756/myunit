include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(platform)
add_subdirectory(tests)

SET (MYUNIT_HEADERS 
    myunit.h  
)

SET (MYUNIT_OBJECTS
    $<TARGET_OBJECTS:myunit_platform>
    )

add_library(myunit ${MYUNIT_OBJECTS})

