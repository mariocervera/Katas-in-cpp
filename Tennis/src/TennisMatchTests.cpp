#include "pch.h"
#include "TennisMatch.h"

static unique_ptr<TennisMatch> createMatch() {
  return make_unique<TennisMatch>("DummyPlayer1", "DummyPlayer2");
}

static unique_ptr<TennisMatch> createMatchWithPlayer(const string& player) {
  return make_unique<TennisMatch>(player, "DummyPlayer");
}

TEST(TennisMatch, scorePointIncorrectPlayer_shouldFail) {
  auto tennisMatch = createMatch();

  bool success = tennisMatch->score("Incorrect Player");

  ASSERT_FALSE(success);
}

TEST(TennisMatch, canScorePoint) {
  string player1 = "Player 1";
  auto tennisMatch = createMatchWithPlayer(player1);

  bool success = tennisMatch->score(player1);

  ASSERT_TRUE(success);
}

TEST(TennisMatch, cannotScoreForNonExistentPlayer) {
  auto tennisMatch = createMatch();

  ASSERT_EQ(tennisMatch->getScore("IncorrectPlayer"), "Error");
}

TEST(TennisMatch, canScoreFifteenForOnePlayer) {
  string player1 = "Player 1";
  auto tennisMatch = createMatchWithPlayer(player1);

  tennisMatch->score(player1);

  ASSERT_EQ(tennisMatch->getScore(player1), "fifteen");
}

TEST(TennisMatch, canScoreThirtyForOnePlayer) {
  string player1 = "Player 1";
  auto tennisMatch = createMatchWithPlayer(player1);

  tennisMatch->score(player1, 2);

  ASSERT_EQ(tennisMatch->getScore(player1), "thirty");
}

