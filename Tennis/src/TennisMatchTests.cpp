#include "pch.h"
#include "TennisMatch.h"

static const string PLAYER_1 = "Player 1";
static const string PLAYER_2 = "Player 2";

static unique_ptr<TennisMatch> createMatchWithPlayers(const string& player1, const string& player2) {
  return make_unique<TennisMatch>(player1, player2);
}

static unique_ptr<TennisMatch> createMatch() {
  return createMatchWithPlayers("Dummy Player 1", "Dummy Player 2");
}

static unique_ptr<TennisMatch> createMatchWithPlayer(const string& player) {
  return createMatchWithPlayers(player, "Dummy Player");
}

//
// Parameterized tests.
//
static void test_scorePointsReturnsCorrectResult(unsigned score1, unsigned score2, const string &result) {
  auto tennisMatch = createMatchWithPlayers(PLAYER_1, PLAYER_2);

  tennisMatch->score(PLAYER_1, score1);
  tennisMatch->score(PLAYER_2, score2);

  ASSERT_EQ(tennisMatch->getResult(), result);
}

//
// Tests.
//
TEST(TennisMatch, scorePointIncorrectPlayer_shouldFail) {
  auto tennisMatch = createMatch();

  bool success = tennisMatch->score("Incorrect Player");

  ASSERT_FALSE(success);
}

TEST(TennisMatch, scorePointCorrectPlayer_shouldSucceed) {
  string player1 = "Player 1";
  auto tennisMatch = createMatchWithPlayer(player1);

  bool success = tennisMatch->score(player1);

  ASSERT_TRUE(success);
}

TEST(TennisMatch, getResultWithoutScoring_shouldReturnLove) {
  auto tennisMatch = createMatch();

  ASSERT_EQ(tennisMatch->getResult(), "Love - Love");
}

TEST(TennisMatch, canScoreBasicPoints) {
  test_scorePointsReturnsCorrectResult(1, 0, "Fifteen - Love");
  test_scorePointsReturnsCorrectResult(2, 0, "Thirty - Love");
  test_scorePointsReturnsCorrectResult(3, 0, "Forty - Love");
  test_scorePointsReturnsCorrectResult(1, 1, "Fifteen - Fifteen");
  test_scorePointsReturnsCorrectResult(1, 2, "Fifteen - Thirty");
  test_scorePointsReturnsCorrectResult(0, 3, "Love - Forty");
}

TEST(TennisMatch, canScoreDeuce) {
  test_scorePointsReturnsCorrectResult(4, 4, "Deuce");
  test_scorePointsReturnsCorrectResult(5, 5, "Deuce");
  test_scorePointsReturnsCorrectResult(6, 6, "Deuce");
  test_scorePointsReturnsCorrectResult(20, 20, "Deuce");
}

TEST(TennisMatch, canScoreAdvantage) {
  test_scorePointsReturnsCorrectResult(4, 3, "Advantage " + PLAYER_1);
  test_scorePointsReturnsCorrectResult(6, 5, "Advantage " + PLAYER_1);
  test_scorePointsReturnsCorrectResult(3, 4, "Advantage " + PLAYER_2);
  test_scorePointsReturnsCorrectResult(8, 9, "Advantage " + PLAYER_2);
}

TEST(TennisMatch, getResultOfWinningGame_shouldReturnWinningPlayer) {
  test_scorePointsReturnsCorrectResult(4, 2, PLAYER_1 + " wins");
  test_scorePointsReturnsCorrectResult(6, 4, PLAYER_1 + " wins");
  test_scorePointsReturnsCorrectResult(1, 4, PLAYER_2 + " wins");
  test_scorePointsReturnsCorrectResult(5, 7, PLAYER_2 + " wins");
}
