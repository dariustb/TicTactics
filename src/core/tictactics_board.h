// tictactics_board.h
#ifndef INCLUDED_TICTACTICS_CORE
#define INCLUDED_TICTACTICS_CORE

#include <tictactics_player.h>
#include <string>

typedef int RetCode;

class Board {
    public:
        Board();
        Board(const int& width, const int& height);
        
        int width();
        int height();

        RetCode resetBoard();
        RetCode printBoard();
        RetCode updateBoard(Player player, int move_idx);

        int  getPlayerMove(Player player);
        bool isMoveValid(const std::string& user_input);
        bool isMoveWin(int move_idx);

    private:
        int         d_width;
        int         d_height;
        std::string d_board;

        enum ReturnCodes {
            e_SUCCESS,
        };
};

#endif
