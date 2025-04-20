include_directories(${CMAKE_CURRENT_SOURCE_DIR})

SET (MYUNIT_PLATFORM_SOURCES
    myunit_platform_linux.c
)


add_library(myunit_platform OBJECT ${MYUNIT_PLATFORM_SOURCES})