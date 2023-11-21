#include <tictactics_player.h>

Player::Player(const std::string &name, const char &piece)
: d_name(name)
, d_piece(piece)
{
}

std::string Player::name()
{
    return d_name;
}

char Player::piece()
{
    return d_piece;
}
