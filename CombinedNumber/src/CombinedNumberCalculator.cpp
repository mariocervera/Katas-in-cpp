#include "CombinedNumberCalculator.hpp"
#include <algorithm> 

string getCommonPrefix(string& s1, string& s2) {
  unsigned max_length = s1.size() > s2.size() ? s2.size() : s1.size();
  if (max_length == 0)
    return "";

  string prefix = "";
  int i = 0;
  while (i < max_length && s1[i] == s2[i]) {
    prefix += s1[i];
    ++i;
  }

  return prefix;
}

string removeCommonPrefix(string &s1, string &s2) {
  string prefix = getCommonPrefix(s1, s2);
  s1.erase(0, prefix.size());
  s2.erase(0, prefix.size());

  return prefix;
}

// A function that compares two numbers (as strings) by length and value.
// If one of the numbers if a prefix of the other, it appears first in sorted order.
bool compareByLengthAndValue(unsigned i, unsigned j) {
  string s1 = to_string(i);
  string s2 = to_string(j);

  string prefix = removeCommonPrefix(s1, s2);

  if (s1.size() == 0)
    return true;
  else if (s2.size() == 0)
    return false;
  
  return (s1 > s2);
}

string CombinedNumberCalculator::getCombinedNumber(vector<unsigned> &numbers) {
  string combinedNumber = "";

  sort(numbers.begin(), numbers.end(), compareByLengthAndValue);

  for (unsigned number : numbers) {
    combinedNumber += to_string(number);
  }

  return combinedNumber;
}