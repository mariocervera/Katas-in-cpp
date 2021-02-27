#include "CombinedNumberCalculator.hpp"
#include <algorithm> 

// Helper functions.

static unsigned getMaxLength(string& s1, string& s2) {
  return s1.size() > s2.size() ? s2.size() : s1.size();
}

static string getCommonPrefix(string& s1, string& s2) {
  string prefix = "";
  unsigned len = getMaxLength(s1, s2); 
  
  for (int i = 0; i < len && s1[i] == s2[i]; ++i)
    prefix += s1[i];

  return prefix;
}

static string removeCommonPrefix(string &s1, string &s2) {
  string prefix = getCommonPrefix(s1, s2);
  s1.erase(0, prefix.size());
  s2.erase(0, prefix.size());

  return prefix;
}

static char getFirstCharDifferentFrom(string &inputStr, const char &charToCompare) {
  for (char& c : inputStr)
    if (c != charToCompare)
      return c;
  return '-';
}

static bool compareContainedPrefix(string &s, string &prefix) {
  const char &highestOrderPrefixDigit = prefix[0];
  char firstDifferentDigit = getFirstCharDifferentFrom(s, highestOrderPrefixDigit);
  if (firstDifferentDigit == '-')
    return true;
  return (firstDifferentDigit > highestOrderPrefixDigit);
}

static bool compareContainedPrefix(string& s1, string& s2, string& prefix) {
  if (s1.size() == 0)
    return !compareContainedPrefix(s2, prefix);
  else
    return compareContainedPrefix(s1, prefix);
}

static bool compareNumbers(unsigned i, unsigned j) {
  if (i == j)
    return false;

  string s1 = to_string(i);
  string s2 = to_string(j);

  string prefix = removeCommonPrefix(s1, s2);
  if (s1.size() == 0 || s2.size() == 0)
    return compareContainedPrefix(s1, s2, prefix);
  
  return (s1 > s2);
}

// This is the main function of the program.
// It calculates the combined number given the array of input numbers.
// The function executes a sorting preprocessing step. The comparator function returns true
// when i > j. This sorts in decreasing order. If one of the numbers if a prefix of the
// other, it is handled as a special case.
string CombinedNumberCalculator::getCombinedNumber(vector<unsigned> &numbers) {
  sort(numbers.begin(), numbers.end(), compareNumbers);

  string combinedNumber = "";
  for (unsigned number : numbers) {
    combinedNumber += to_string(number);
  }

  return combinedNumber;
}