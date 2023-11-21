#include <tictactics_gameplay.h>
#include <gtest/gtest.h>

TEST(TictacticsGameplay, DefaultConstructorPopulatesDefaultValues) {
    // Given
    Game TGame;

    // When
    const int default_num_of_players = TGame.Players().size();

    // Then
    EXPECT_EQ(0, default_num_of_players);
}

TEST(TictacticsGameplay, AddPlayerUpdatesPlayers) {
    // Given
    Game TGame;

    // When / Then
    ASSERT_EQ(0, TGame.Players().size());

    ASSERT_EQ(0, TGame.addPlayer(Player("test1", 'A')));
    EXPECT_EQ(1, TGame.Players().size());
    
    ASSERT_EQ(0, TGame.addPlayer(Player("test1", 'B')));
    EXPECT_EQ(2, TGame.Players().size());
    
    ASSERT_EQ(0, TGame.addPlayer(Player("test1", 'C')));
    EXPECT_EQ(3, TGame.Players().size());
}