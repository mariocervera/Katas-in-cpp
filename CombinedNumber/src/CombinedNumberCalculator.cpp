#include "CombinedNumberCalculator.hpp"
#include <algorithm> 

static unsigned getMaximumPrefixLength(string& s1, string& s2) {
  return s1.size() > s2.size() ? s2.size() : s1.size();
}

string getCommonPrefix(string& s1, string& s2) {
  string prefix = "";
  unsigned max_length = getMaximumPrefixLength(s1, s2);
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

const char& getFirstDifferentDigit(string& s, const char& ch) {
  for (char& c : s)
    if (c != ch)
      return c;
  return ch;
}

bool compareContainedPrefix(string& s1, string& s2, string& prefix) {
  const char &highestOrderDigit = prefix[0];
  if (s1.size() == 0)
    return !(getFirstDifferentDigit(s2, highestOrderDigit) > highestOrderDigit);
  else if (s2.size() == 0)
    return (getFirstDifferentDigit(s1, highestOrderDigit) > highestOrderDigit);

  return (s1 > s2);
}

// A function that compares two numbers as strings. Returns true when s1 is greater than
// or equal to s2. If one of the numbers if a prefix of the other, it is handled as a
// special case. This function causes the 'sort' function to sort in decreasing order. 
bool compareNumbers(unsigned i, unsigned j) {
  if (i == j)
    return true;

  string s1 = to_string(i);
  string s2 = to_string(j);

  string prefix = removeCommonPrefix(s1, s2);
  if (s1.size() == 0 || s2.size() == 0)
    return compareContainedPrefix(s1, s2, prefix);
  
  return (s1 > s2);
}

string CombinedNumberCalculator::getCombinedNumber(vector<unsigned> &numbers) {
  sort(numbers.begin(), numbers.end(), compareNumbers);

  string combinedNumber = "";
  for (unsigned number : numbers) {
    combinedNumber += to_string(number);
  }

  return combinedNumber;
}