#include <tictactics_board.h>
#include <gtest/gtest.h>

TEST(TictacticsBoard, DefaultConstructorPopulatesDefaultValues) {
    // Given
    Board TBoard;

    // When
    const int default_width  = TBoard.width();
    const int default_height = TBoard.height();

    // Then
    EXPECT_EQ(3, default_width);
    EXPECT_EQ(3, default_height);
}

TEST(TictacticsBoard, ArgConstructorPopulatesArgValues) {
    // Given
    const int test_width = 6;
    const int test_height = 13;

    // When
    Board TBoard(test_width, test_height);
    const int arg_width = TBoard.width();
    const int arg_height = TBoard.height();

    // Then
    EXPECT_EQ(6,  arg_width);
    EXPECT_EQ(13, arg_height);
}

TEST(TictacticsBoard, ResetBoardReturnsSuccess) {
    // Given
    Board TBoard;

    // When
    const RetCode rcode = TBoard.resetBoard();

    // Then
    ASSERT_EQ(0, rcode);
}

TEST(TictacticsBoard, PrintBoardReturnsSuccess) {
    // Given
    Board TBoard;

    // When
    ::testing::internal::CaptureStdout(); // Captures cout text
    const RetCode rcode = TBoard.printBoard();
    ::testing::internal::GetCapturedStdout();

    // Then
    ASSERT_EQ(0, rcode);
}

TEST(TictacticsBoard, PrintBoardPrintsDefaultBoard) {
    // Given
    Board TBoard;
    const std::string default_board = "     |     |     \n  1  |  2  |  3  \n_____|_____|_____\n     |     |     \n  4  |  5  |  6  \n_____|_____|_____\n     |     |     \n  7  |  8  |  9  \n     |     |     \n\n";

    // When
    ::testing::internal::CaptureStdout(); // Captures cout text
    TBoard.printBoard();
    const std::string test_board = ::testing::internal::GetCapturedStdout();
    
    // Then
    EXPECT_EQ(default_board, test_board);
}

TEST(TictacticsBoard, IsMoveValidReturnsTrueWhenValid) {
    // Given
    Board             TBoard;
    const std::string valid_input = "1";

    // When
    const bool valid_return = TBoard.isMoveValid(valid_input);

    // Then
    ASSERT_TRUE(valid_return);
}

TEST(TictacticsBoard, IsMoveValidReturnsFalseWhenJunkInput) {
    // Given
    Board TBoard;
    const std::string junk_input = "!@#$%^";

    // When
    const bool junk_return = TBoard.isMoveValid(junk_input);

    // Then
    ASSERT_FALSE(junk_return);
}

TEST(TictacticsBoard, IsMoveValidReturnsFalseWhenOutOfScope) {
    // Given
    Board TBoard;
    const std::string out_scope_input = "0";

    // When
    const bool out_scope_return = TBoard.isMoveValid(out_scope_input);

    // Then
    ASSERT_FALSE(out_scope_return);
}

TEST(TictacticsBoard, IsMoveValidReturnsFalseWhenSpaceTaken) {
    // Given
    Board             TBoard;
    Player            TPlayer("test", 'T');
    const std::string taken_input = "5";

    // When
    ASSERT_EQ(0, TBoard.updateBoard(TPlayer, 4));
    const bool taken_return  = TBoard.isMoveValid(taken_input);

    // Then
    ASSERT_FALSE(taken_return);
}

TEST(TictacticsBoard, IsMoveWinReturnsTrueWhenWinVertical) {
    // Given
    Board     TBoard;
    Player    TPlayer("test", 'T');
    const int vert_win_idx[3] = {0, 3, 6};
    const int winning_idx = 6;

    // When
    for (int idx: vert_win_idx) {
        ASSERT_EQ(0, TBoard.updateBoard(TPlayer, idx));
    }
    const bool vertical_win = TBoard.isMoveWin(winning_idx);

    // Then
    ASSERT_TRUE(vertical_win);
}

TEST(TictacticsBoard, IsMoveWinReturnsTrueWhenWinHorizontal) {
    // Given
    Board     TBoard;
    Player    TPlayer("test", 'T');
    const int horz_win_idx[3] = {0, 1, 2};
    const int winning_idx = 2;

    // When
    for (int idx: horz_win_idx) {
        ASSERT_EQ(0, TBoard.updateBoard(TPlayer, idx));
    }
    const bool horizontal_win = TBoard.isMoveWin(winning_idx);

    // Then
    ASSERT_TRUE(horizontal_win);
}

TEST(TictacticsBoard, IsMoveWinReturnsTrueWhenWinDiagonalLeft) {
    // Given
    Board     TBoard;
    Player    TPlayer("test", 'T');
    const int horz_win_idx[3] = {0, 4, 8};
    const int winning_idx = 2;

    // When
    for (int idx: horz_win_idx) {
        ASSERT_EQ(0, TBoard.updateBoard(TPlayer, idx));
    }
    const bool horizontal_win = TBoard.isMoveWin(winning_idx);

    // Then
    ASSERT_TRUE(horizontal_win);
}

TEST(TictacticsBoard, IsMoveWinReturnsTrueWhenWinDiagonalRight) {
    // Given
    Board     TBoard;
    Player    TPlayer("test", 'T');
    const int horz_win_idx[3] = {2, 4, 6};
    const int winning_idx = 2;

    // When
    for (int idx: horz_win_idx) {
        ASSERT_EQ(0, TBoard.updateBoard(TPlayer, idx));
    }
    const bool horizontal_win = TBoard.isMoveWin(winning_idx);

    // Then
    ASSERT_TRUE(horizontal_win);
}

TEST(TictacticsBoard, IsMoveWinReturnsFalseWhenGameOngoing) {
    // Given
    Board        TBoard;
    const Player TPlayer("test", 'T');
    const int    ongoing_idx = 2;

    // When
    ASSERT_EQ(0, TBoard.updateBoard(TPlayer, ongoing_idx));
    const bool ongoing_return = TBoard.isMoveWin(ongoing_idx);

    // Then
    ASSERT_FALSE(ongoing_return);
}

TEST(TictacticsBoard, IsMoveWinReturnsFalseWhenGameTied) {
    // Given
    Board TBoard;
    std::vector TPlayers = {Player("test1", 'X'), Player("test2", 'O')};
    const int game_move_idxs[9] = {0, 4, 8, 1, 7, 6, 2, 5, 3};
    const int tie_move_idx = game_move_idxs[8];

    // When
    for (int idx: game_move_idxs) {
        ASSERT_EQ(0, TBoard.updateBoard(TPlayers[idx % TPlayers.size()], idx));
    }
    const bool tied_return = TBoard.isMoveWin(tie_move_idx);

    // Then
    ASSERT_TRUE(tied_return);
}
