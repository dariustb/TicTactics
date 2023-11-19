set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(
    tictactics
    tictactics.m.cpp
)

add_library(tictactics_core)
add_subdirectory(core)
target_link_libraries(tictactics PUBLIC tictactics_core)
