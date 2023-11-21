#include <tictactics_gameplay.h>
#include <iostream>

using namespace std;

Game::Game()
{
    d_Players.clear();
}

std::vector<Player> Game::Players()
{
    return d_Players;
}

Board Game::getBoard()
{
    return d_Board;
}

int Game::addPlayer(Player player)
{
    d_Players.push_back(player);

    return e_SUCCESS;
}

int Game::play()
{
    const int max_turns = getBoard().height() * getBoard().width();
    int move_idx = -1;

    int turn = 0;
    for (; turn < max_turns; turn++) {
        // Print the board
        d_Board.printBoard();

        // Get user input
        move_idx = d_Board.getPlayerMove(d_Players[turn % d_Players.size()]);

        // Update board
        d_Board.updateBoard(d_Players[turn % d_Players.size()], move_idx);

        // Check for win
        if (d_Board.isMoveWin(move_idx)) {
            cout << d_Players[turn % d_Players.size()].name() << " wins!!!" << endl;
            break;
        }
    }

    // Print the final board
    d_Board.printBoard();

    return e_SUCCESS;
}
