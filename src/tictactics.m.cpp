#include <tictactics_board.h>
#include <tictactics_player.h>
#include <tictactics_gameplay.h>

#include <iostream>
#include <string>
#include <vector>

int main() {
    Game GGame;
    
    GGame.addPlayer(Player("Player 1", 'X'));
    GGame.addPlayer(Player("Player 2", 'O'));

    GGame.play();

    return 0;
}
