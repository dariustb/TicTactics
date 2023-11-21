#include <tictactics_player.h>
#include <gtest/gtest.h>

TEST(TictacticsPlayer, ArgConstructorPopulatesArgValues) {
    // Given
    const std::string test_name  = "test";
    const char        test_piece = 'X';

    // When
    Player TPlayer(test_name, test_piece);

    // Then
    EXPECT_EQ("test", TPlayer.name());
    EXPECT_EQ('X',    TPlayer.piece());
}

TEST(TictacticsPlayer, NameReturnsName) {
    // Given
    const std::string test_name  = "test";
    const char        test_piece = 'X'; 

    // When
    Player TPlayer(test_name, test_piece);
    
    // Then
    EXPECT_EQ("test", TPlayer.name());
}

TEST(TictacticsPlayer, PieceReturnsPiece) {
    // Given
    const std::string test_name  = "test";
    const char        test_piece = 'X'; 

    // When
    Player TPlayer(test_name, test_piece);
    
    // Then
    EXPECT_EQ('X', TPlayer.piece());
}
