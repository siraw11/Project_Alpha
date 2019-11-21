cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/googletest)

set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} /)


set(TEST_SOURCE_FILES runAllTests.cpp PlayerTest.cpp PlayerFixture.cpp BikeTest.cpp BikeFixture.cpp MapTest.cpp MapFixture.cpp)
add_executable(runTests ${TEST_SOURCE_FILES})
target_link_libraries(runTests gtest gtest_main core)


#include SFML
find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)
if (SFML_FOUND)
    include_directories(/usr/local/include)
    target_link_libraries(runTests sfml-graphics sfml-window sfml-system)
endif ()
set(SFML_STATIC_LIBRARIES TRUE)
#-----------


#Add Box2D
target_link_libraries(runTests ${CMAKE_SOURCE_DIR}/Box2D/libBox2D.a)
#--------------------