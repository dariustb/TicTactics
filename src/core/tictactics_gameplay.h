// tictactics_gameplay.h
#ifndef INCLUDED_TICTACTICS_GAMEPLAY
#define INCLUDED_TICTACTICS_GAMEPLAY

#include <tictactics_board.h>
#include <tictactics_player.h>
#include <vector>

typedef int RetCode;

class Game {
    public:
        Game();

        std::vector<Player> Players();
        Board               getBoard();

        RetCode addPlayer(Player player);
        RetCode play();
        
    private:
        std::vector<Player> d_Players;
        Board d_Board;

        enum ReturnCodes {
            e_SUCCESS,
        };
};

#endif
