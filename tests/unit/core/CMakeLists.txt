target_include_directories(test_tictactics PUBLIC ./)
target_sources(test_tictactics
    PRIVATE
    tictactics_board.t.cpp
    tictactics_gameplay.t.cpp
    tictactics_player.t.cpp
)
