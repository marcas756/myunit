cmake_minimum_required (VERSION 3.8)
project(myunit C)

set_property(DIRECTORY APPEND PROPERTY
  COMPILE_DEFINITIONS $<$<CONFIG:Debug>:DEBUG=1>
)
  
set(CMAKE_C_FLAGS "-std=c99 -Wall -pedantic-errors -O1")


add_subdirectory(src)

include_directories (
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/src
    )

add_executable(myunit_selftest myunit_selftest.c myunit_platform_template.c)
#set_target_properties(myunit_slist PROPERTIES COMPILE_DEFINITIONS "UNITTEST_LIST_TYPE=UNITTEST_LIST_TYPE_SLIST")
target_link_libraries(myunit_selftest myunit)
