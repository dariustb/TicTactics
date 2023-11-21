#include <tictactics_board.h>
#include <string>
#include <iostream>

using namespace std;

namespace {
    const int DEFAULT_BOARD_WIDTH  = 3;
    const int DEFAULT_BOARD_HEIGHT = 3;
}

Board::Board()
: Board(DEFAULT_BOARD_WIDTH, DEFAULT_BOARD_HEIGHT)
{
    resetBoard();
}

Board::Board(const int &width, const int &height)
: d_width(width)
, d_height(height)
{
}

int Board::width()
{
    return d_width;
}

int Board::height()
{
    return d_height;
}

int Board::resetBoard()
{
    d_board = "123456789";

    return e_SUCCESS;
}

int Board::printBoard()
{
    cout <<
    "     |     |     \n"
    "  " << d_board[0] << "  |  " << d_board[1] << "  |  " << d_board[2] << "  \n"
    "_____|_____|_____\n"
    "     |     |     \n"
    "  " << d_board[3] << "  |  " << d_board[4] << "  |  " << d_board[5] << "  \n"
    "_____|_____|_____\n"
    "     |     |     \n"
    "  " << d_board[6] << "  |  " << d_board[7] << "  |  " << d_board[8] << "  \n"
    "     |     |     \n"
    << endl;

    return e_SUCCESS;
}

int Board::updateBoard(Player player, int move_idx)
{
    d_board[move_idx] = player.piece();
    
    return e_SUCCESS;
}

int Board::getPlayerMove(Player player)
{
    std::string user_input = "";
    bool is_valid_move = false;
    
    do {
        std::cout << player.name() << ", choose a square to move into: ";
        std::getline(std::cin, user_input);
        std::cout << std::endl;

        is_valid_move = isMoveValid(user_input);
        if (!is_valid_move) {
            std::cout << "Invalid move, please try again." << std::endl;
        }
    } while (!is_valid_move);

    return (user_input[0] - '1');
}

bool Board::isMoveValid(const std::string &user_input)
{
    bool conflict_found = false;
    
    // Check for junk input
    if (user_input.size() != 1) {
        return false;
    }

    // Check if move is in the scope of the board
    if (user_input[0] < '1' || user_input[0] > '9') {
        return false;
    }

    // Check if move is taken on the board 
    for (int idx = 0; idx < d_board.size(); idx++) {
        if (d_board[idx] == user_input[0]) {
            return true;
        }
    }
    return false;
}

bool Board::isMoveWin(int move_idx)
{
    return (
        (d_board[0] == d_board[1] && d_board[1] == d_board[2]) ||
        (d_board[3] == d_board[4] && d_board[4] == d_board[5]) ||
        (d_board[6] == d_board[7] && d_board[7] == d_board[8]) ||

        (d_board[0] == d_board[3] && d_board[3] == d_board[6]) ||
        (d_board[1] == d_board[4] && d_board[4] == d_board[7]) ||
        (d_board[2] == d_board[5] && d_board[5] == d_board[8]) ||

        (d_board[0] == d_board[4] && d_board[4] == d_board[8]) ||
        (d_board[2] == d_board[4] && d_board[4] == d_board[6])
    );
}
