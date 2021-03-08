project(test)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Game_test RunAllTest.cpp CollisionTest.cpp HeroTest.cpp EnemyTest.cpp)

target_link_libraries(Game_test gtest gtest_main core sfml-graphics sfml-system sfml-audio sfml-window)


