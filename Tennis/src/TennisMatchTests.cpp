#include "pch.h"
#include "TennisMatch.h"

static const string PLAYER_1 = "Player 1";
static const string PLAYER_2 = "Player 2";

static unique_ptr<TennisMatch> createMatchWithPlayers(const string &player1, const string &player2) {
  return make_unique<TennisMatch>(player1, player2);
}

static unique_ptr<TennisMatch> createMatchWithPlayer(const string &player) {
  return createMatchWithPlayers(player, "Dummy Player");
}

static unique_ptr<TennisMatch> createMatch() {
  return createMatchWithPlayers("Dummy Player 1", "Dummy Player 2");
}

//
// Parameterized test.
//
static void test_scoreReturnsCorrectResult(unsigned scoreP1, unsigned scoreP2, const string &expectedResult) {
  auto tennisMatch = createMatchWithPlayers(PLAYER_1, PLAYER_2);

  tennisMatch->score(PLAYER_1, scoreP1);
  tennisMatch->score(PLAYER_2, scoreP2);

  ASSERT_EQ(tennisMatch->getMatchResult(), expectedResult);
}

//
// Tests.
//
TEST(TennisMatch, scorePointForIncorrectPlayer_shouldFail) {
  auto tennisMatch = createMatch();

  bool success = tennisMatch->score("Incorrect Player");

  ASSERT_FALSE(success);
}

TEST(TennisMatch, scorePointForCorrectPlayer_shouldSucceed) {
  auto tennisMatch = createMatchWithPlayer(PLAYER_1);

  bool success = tennisMatch->score(PLAYER_1);

  ASSERT_TRUE(success);
}

TEST(TennisMatch, getResultWithoutScoring_shouldReturnLove) {
  auto tennisMatch = createMatch();

  ASSERT_EQ(tennisMatch->getMatchResult(), "Love - Love");
}

TEST(TennisMatch, scoreRawPoints_shouldReturnCorrectResult) {
  test_scoreReturnsCorrectResult(1, 0, "Fifteen - Love");
  test_scoreReturnsCorrectResult(2, 0, "Thirty - Love");
  test_scoreReturnsCorrectResult(3, 2, "Forty - Thirty");
  test_scoreReturnsCorrectResult(1, 1, "Fifteen - Fifteen");
  test_scoreReturnsCorrectResult(1, 2, "Fifteen - Thirty");
  test_scoreReturnsCorrectResult(0, 3, "Love - Forty");
}

TEST(TennisMatch, scoreDeuce_shouldReturnCorrectResult) {
  test_scoreReturnsCorrectResult(3, 3, "Deuce");
  test_scoreReturnsCorrectResult(4, 4, "Deuce");
  test_scoreReturnsCorrectResult(5, 5, "Deuce");
  test_scoreReturnsCorrectResult(20, 20, "Deuce");
}

TEST(TennisMatch, scoreAdvantage_shouldReturnCorrectResult) {
  test_scoreReturnsCorrectResult(4, 3, "Advantage " + PLAYER_1);
  test_scoreReturnsCorrectResult(6, 5, "Advantage " + PLAYER_1);
  test_scoreReturnsCorrectResult(3, 4, "Advantage " + PLAYER_2);
  test_scoreReturnsCorrectResult(8, 9, "Advantage " + PLAYER_2);
}

TEST(TennisMatch, scoreWinningGame_shouldReturnCorrectResult) {
  test_scoreReturnsCorrectResult(4, 0, PLAYER_1 + " wins");
  test_scoreReturnsCorrectResult(4, 2, PLAYER_1 + " wins");
  test_scoreReturnsCorrectResult(5, 3, PLAYER_1 + " wins");
  test_scoreReturnsCorrectResult(1, 4, PLAYER_2 + " wins");
  test_scoreReturnsCorrectResult(4, 6, PLAYER_2 + " wins");
  test_scoreReturnsCorrectResult(5, 7, PLAYER_2 + " wins");
}

TEST(TennisMatch, scoreIncorrectValues_shouldReturnError) {
  test_scoreReturnsCorrectResult(5, 0, "Incorrect score");
  test_scoreReturnsCorrectResult(6, 2, "Incorrect score");
  test_scoreReturnsCorrectResult(0, 5, "Incorrect score");
  test_scoreReturnsCorrectResult(5, 8, "Incorrect score");
}

