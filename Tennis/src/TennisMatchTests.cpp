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
static void test_scorePointsForOnePlayer(unsigned points, const string &result) {
  string player1 = "Player 1";
  auto tennisMatch = createMatchWithPlayer(player1);

  tennisMatch->score(player1, points);

  ASSERT_EQ(tennisMatch->getScore(player1), result);
}

static void test_scorePointsForTwoPlayers(unsigned score1, unsigned score2,
    const string &result1, const string &result2) {
  
  string player1 = "Player 1";
  string player2 = "Player 2";
  auto tennisMatch = createMatchWithPlayers(player1, player2);

  tennisMatch->score(player1, score1);
  tennisMatch->score(player2, score2);

  ASSERT_EQ(tennisMatch->getScore(player1), result1);
  ASSERT_EQ(tennisMatch->getScore(player2), result2);
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

TEST(TennisMatch, getScoreIncorrectPlayer_shouldFail) {
  auto tennisMatch = createMatch();

  ASSERT_EQ(tennisMatch->getScore("IncorrectPlayer"), "Error");
}

TEST(TennisMatch, canScoreBasicPointsForOnePlayer) {
  test_scorePointsForOnePlayer(1, "fifteen");
  test_scorePointsForOnePlayer(2, "thirty");
  test_scorePointsForOnePlayer(3, "forty");
}

TEST(TennisMatch, canGetLoveScore) {
  string player1 = "Player 1";
  auto tennisMatch = createMatchWithPlayer(player1);

  ASSERT_EQ(tennisMatch->getScore(player1), "love");
}

TEST(TennisMatch, canScorePointsForDifferentPlayers) {
  test_scorePointsForTwoPlayers(2, 3, "thirty", "forty");
}

TEST(TennisMatch, canScoreDeuce) {
  test_scorePointsForTwoPlayers(4, 4, "deuce", "deuce");
}

