target_include_directories(tictactics_core PUBLIC ./)

target_sources(tictactics_core
    PRIVATE
    tictactics_board.cpp
    tictactics_gameplay.cpp
    tictactics_player.cpp
)
