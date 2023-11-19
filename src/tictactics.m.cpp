#include <iostream>
#include <string>
#include <vector>

int printBoard(const std::string& b) {
    std::cout <<
    "     |     |     " << std::endl <<
    "  " << b[0] << "  |  " << b[1] << "  |  " << b[2] << "  " << std::endl <<
    "_____|_____|_____" << std::endl <<
    "     |     |     " << std::endl <<
    "  " << b[3] << "  |  " << b[4] << "  |  " << b[5] << "  " << std::endl <<
    "_____|_____|_____" << std::endl <<
    "     |     |     " << std::endl <<
    "  " << b[6] << "  |  " << b[7] << "  |  " << b[8] << "  " << std::endl <<
    "     |     |     " << std::endl << std::endl;
    return 0;
}

bool isMoveValid(const std::string& b, const std::string& user_input) {
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
    for (int idx = 0; idx < b.size(); idx++) {
        if (b[idx] == user_input[0]) {
            return true;
        }
    }
    return false;
}

int getPlayerMove(const std::string& b) {
    std::string user_input = "";
    bool is_valid_move = false;
    
    do {
        std::cout << "Player, choose a square to move into: ";
        std::getline(std::cin, user_input);
        std::cout << std::endl;

        is_valid_move = isMoveValid(b, user_input);
        if (!is_valid_move) {
            std::cout << "Invalid move, please try again." << std::endl;
        }
    } while (!is_valid_move);

    return (user_input[0] - '1');
}

int updateBoard(std::string& b, const int& move_idx, const char& piece) {
    b[move_idx] = piece;

    return 0;
}

bool isMoveWin(const std::string &b, const int move_idx) {
    return (
        (b[0] == b[1] && b[1] == b[2]) ||
        (b[3] == b[4] && b[4] == b[5]) ||
        (b[6] == b[7] && b[7] == b[8]) ||

        (b[0] == b[3] && b[3] == b[6]) ||
        (b[1] == b[4] && b[4] == b[7]) ||
        (b[2] == b[5] && b[5] == b[8]) ||

        (b[0] == b[4] && b[4] == b[8]) ||
        (b[2] == b[4] && b[4] == b[6])
    );
}


int main() {
    std::string board = "123456789";
    const std::vector<char> Players = {'X', 'O'};

    const int max_turns = 9;
    int move_idx = -1;
    bool is_game_won  = false;

    int turn = 0;
    for (; turn < max_turns; turn++) {
        // Show board
        printBoard(board);
        
        // Get player's input + validate move
        move_idx = getPlayerMove(board);

        // Update board
        updateBoard(board, move_idx, Players[turn % Players.size()]);

        // Check for win
        if(isMoveWin(board, move_idx)) {
            is_game_won  = true;
            break;
        }
    }

    std::cout << "Game Over!" << std::endl;
    if (is_game_won) {
        std::cout << "Player " << Players[turn % Players.size()] << " wins!" << std::endl << std::endl;
    }
    
    printBoard(board);

    return 0;
}
