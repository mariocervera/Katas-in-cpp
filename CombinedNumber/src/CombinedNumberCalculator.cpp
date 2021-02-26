#include "CombinedNumberCalculator.hpp"
#include <algorithm> 

// A greater-than comparator causes std::sort to sort in decreasing order.
bool greaterThanAsString(unsigned i, unsigned j) {
	string s1 = to_string(i);
	string s2 = to_string(j);
	
	return (s1 > s2);
}

string CombinedNumberCalculator::getCombinedNumber(vector<unsigned> &numbers) {
	string combinedNumber = "";

	sort(numbers.begin(), numbers.end(), greaterThanAsString);

	for (unsigned number : numbers) {
		combinedNumber += to_string(number);
	}

	return combinedNumber;
}