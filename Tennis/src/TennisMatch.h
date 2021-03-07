#pragma once

using namespace std;

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
		if (player1Score > 3) {
			if (player2Score == player1Score - 1)
				return "Advantage " + player1;
			else if (player2Score == player1Score)
				return "Deuce";
		}
		
		if (player2Score > 3) {
			if (player1Score == player2Score - 1)
				return "Advantage " + player2;
			else if (player2Score == player1Score)
				return "Deuce";
		}

		return translate(player1Score) + " - " + translate(player2Score);
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