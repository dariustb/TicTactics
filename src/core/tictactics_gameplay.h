// tictactics_gameplay.h
#ifndef INCLUDED_TICTACTICS_GAMEPLAY
#define INCLUDED_TICTACTICS_GAMEPLAY

#include <tictactics_board.h>
#include <tictactics_player.h>
#include <vector>

class Game {
    public:
        Game();

        std::vector<Player> Players();
        Board               getBoard();

        int addPlayer(Player player);
        int play();
        
    private:
        std::vector<Player> d_Players;
        Board d_Board;

        enum ReturnCodes {
            e_SUCCESS,
        };
};

#endif
