#include <string>

using namespace std;

class BalanceChecker {
public: 
	// Only accepts strings that are composed of '(', ')', '[', ']', '{', or '}'.
	bool check(const string &);
};