#pragma once

using namespace std;

static string rawScores[4] = {"Love", "Fifteen", "Thirty", "Forty"};

class TennisMatch {

public:
  TennisMatch(const string &player1, const string &player2) :
    player1(player1), player2(player2), scorePlayer1(0), scorePlayer2(0) { }

public:
  bool score(const string &player, unsigned points = 1) {
    if (!isCorrectPlayer(player))
      return false;
    
    if (player == player1)
      scorePlayer1 += points;
    else
      scorePlayer2 += points;
    
    return true;
  }

  string getMatchResult() {
    if (isIncorrectResult())
      return "Incorrect score";

    if (isRawResult())
      return getRawResult();
    
    if (scorePlayer1 == scorePlayer2)
      return "Deuce";

    return handleAdvantageOrWin();
  }

private:
  bool isCorrectPlayer(const string &player) {
    return player == player1 || player == player2;
  }

  bool isIncorrectResult() {
    if (scorePlayer1 > scorePlayer2)
      return (scorePlayer1 > 4 && scorePlayer1 - scorePlayer2 > 2);
    
    if (scorePlayer2 > scorePlayer1)
      return (scorePlayer2 > 4 && scorePlayer2 - scorePlayer1 > 2);

    return false;
  }

  bool isRawResult() {
    bool bothPlayersFortyOrLess = scorePlayer1 < 4 && scorePlayer2 < 4;
    bool atLeastOnePlayerIsNotForty = scorePlayer1 < 3 || scorePlayer2 < 3;
    
    return bothPlayersFortyOrLess && atLeastOnePlayerIsNotForty;
  }

  string getRawResult() {
    return rawScores[scorePlayer1] + " - " + rawScores[scorePlayer2];
  }

  string handleAdvantageOrWin() {
    string result = getAdvantageOrWinResult(player1, scorePlayer1, scorePlayer2);
    
    if (result != "")
      return result;
    
    return getAdvantageOrWinResult(player2, scorePlayer2, scorePlayer1);
  }

  string getAdvantageOrWinResult(const string &player, unsigned playerScore, unsigned rivalScore) {
    if (rivalScore == playerScore - 1)
      return "Advantage " + player;
    if (rivalScore < playerScore - 1)
      return player + " wins";
    
    return "";
  }

private:
  const string player1;
  const string player2;
  unsigned scorePlayer1;
  unsigned scorePlayer2;
};