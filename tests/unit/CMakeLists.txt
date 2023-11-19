add_executable(test_tictactics)
target_link_libraries(test_tictactics
  PUBLIC
    GTest::gtest_main
    tictactics_core
)

add_subdirectory(core)

include(GoogleTest)
gtest_discover_tests(test_tictactics)
