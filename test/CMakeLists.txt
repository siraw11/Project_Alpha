project(test)

add_subdirectory(gtest_src)

set(TEST_SRC_DIRECTORY gtest_src/googletest)

include_directories(${TEST_SRC_DIRECTORY}/include ${TEST_SRC_DIRECTORY})

include_directories(sfml/include)

set(TEST_FILES test.cpp)


add_executable(test ${TEST_FILES})

target_link_libraries(test gtest gtest_main)

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)
if (SFML_FOUND)
    link_libraries(Project_Alpha_ROOT sfml-graphics sfml-window sfml-system)

endif ()