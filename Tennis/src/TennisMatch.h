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

	string getScore(const string& player) {
		if (player == player1) 
			return translateScore(player1Score);
		if (player == player2)
			return translateScore(player2Score);

		return "Error";
	}

private:
	string translateScore(unsigned score) {
		if (score == 1)
			return "fifteen";
		else if (score == 2)
			return "thirty";
		else
			return "forty";
	}

private:
	const string player1;
	const string player2;
	unsigned player1Score;
	unsigned player2Score;
};