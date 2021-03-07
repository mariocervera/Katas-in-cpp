#pragma once

using namespace std;

static string getNonBasicResult(const string &player, unsigned playerScore, unsigned rivalScore) {
  if (playerScore > 3) {
    if (rivalScore < playerScore - 1)
      return player + " wins";
    if (rivalScore == playerScore - 1)
      return "Advantage " + player;
    if (rivalScore == playerScore)
      return "Deuce";
  }

  return "";
}

class TennisMatch {

public:
  TennisMatch(const string& player1, const string& player2) :
    player1(player1), player2(player2), player1Score(0), player2Score(0){}

public:
  bool score(const string& player, unsigned points = 1) {
    if (player != player1 && player != player2)
      return false;
    
    if (player == player1)
      player1Score += points;
    else if (player == player2)
      player2Score += points;
    
    return true;
  }

  string getResult() {
    string result = getNonBasicResult(player1, player1Score, player2Score);
    
    if (result == "")
      result = getNonBasicResult(player2, player2Score, player1Score);

    if (result == "")
      result = translate(player1Score) + " - " + translate(player2Score);

    return result;
  }

private:
  string translate(unsigned score) {
    if (score == 0)
      return "Love";
    if (score == 1)
      return "Fifteen";
    else if (score == 2)
      return "Thirty";
    else
      return "Forty";
  }

private:
  const string player1;
  const string player2;
  unsigned player1Score;
  unsigned player2Score;
};