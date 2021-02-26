#include "CombinedNumberCalculator.hpp"
#include <algorithm> 

string CombinedNumberCalculator::getCombinedNumber(vector<unsigned> &numbers) {
	string combinedNumber = "";
	
	if (numbers.empty())
		return combinedNumber;

	sort(numbers.begin(), numbers.end());

	for (unsigned number : numbers) {
		combinedNumber += to_string(number);
	}

	return combinedNumber;
}