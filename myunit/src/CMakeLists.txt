include_directories(${CMAKE_CURRENT_SOURCE_DIR})

SET (MYUNIT_SOURCES 
    myunit.c
)

SET (MYUNIT_HEADERS 
    myunit.h  
)

add_library(myunit ${MYUNIT_SOURCES})



