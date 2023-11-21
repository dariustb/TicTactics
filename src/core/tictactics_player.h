// tictactics_player.h
#ifndef INCLUDED_TICTACTICS_PLAYER
#define INCLUDED_TICTACTICS_PLAYER

#include <string>

class Player {
    public:
        Player(const std::string& name, const char& piece);

        std::string name();
        char        piece();

    private:
        std::string d_name;
        char        d_piece;
};

#endif
