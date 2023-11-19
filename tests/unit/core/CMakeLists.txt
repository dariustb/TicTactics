add_executable(tictactics_utest)
target_sources(tictactics_utest
  PRIVATE
    smoke_test.t.cpp
    # tictactics_board.t.cpp
)
target_link_libraries(tictactics_utest
  PUBLIC
    GTest::gtest_main
    # tictactics_core
)
target_include_directories(tictactics_utest PUBLIC ./)
