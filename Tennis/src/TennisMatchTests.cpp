#include "pch.h"
#include "TennisMatch.h"

static unique_ptr<TennisMatch> createMatchWithPlayers(const string& player1, const string& player2) {
  return make_unique<TennisMatch>(player1, player2);
}

static unique_ptr<TennisMatch> createMatch() {
  return createMatchWithPlayers("DummyPlayer1", "DummyPlayer2");
}

static unique_ptr<TennisMatch> createMatchWithPlayer(const string& player) {
  return createMatchWithPlayers(player, "DummyPlayer");
}

//
// Parameterized tests.
//
static void test_scorePointsReturnsCorrectResult(unsigned score1, unsigned score2, const string &result) {
  string player1 = "Player 1";
  string player2 = "Player 2";
  auto tennisMatch = createMatchWithPlayers(player1, player2);

  tennisMatch->score(player1, score1);
  tennisMatch->score(player2, score2);

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
