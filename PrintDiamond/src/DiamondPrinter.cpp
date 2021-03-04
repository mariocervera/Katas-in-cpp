#include "DiamondPrinter.hpp"

static char letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
                           'O','P','Q','R','S','T','U','V','W','X','Y','Z'};

static bool isCapitalLetter(const char letter) {
  int letterCode = letter - 'A';
  return (0 <= letterCode && letterCode < 26);
}

static string spaces(unsigned numSpaces) {
  string result = "";
  for (int i = 0; i < numSpaces; ++i)
    result += " ";
  return result;
}

static string getRow_A(unsigned n) {
  return spaces(n) + letters[0] + spaces(n);
}

static string getIntermediateRow(unsigned n, unsigned row) {
  return spaces(n-row) + letters[row] + spaces(row*2 - 1) +
    letters[row] + spaces(n-row) + "\n";
}

static string doGetDiamond(unsigned n) {
  string diamond = getRow_A(n) + "\n";
  
  for (unsigned i = 1; i <= n; ++i)
    diamond += getIntermediateRow(n, i);
  
  for(unsigned i = n-1; i > 0; --i)
    diamond += getIntermediateRow(n, i);
  
  diamond += getRow_A(n);

  return diamond;
}

string DiamondPrinter::getDiamond(char letter) {
  if(!isCapitalLetter(letter))
    return "Error";

  if(letter == 'A')
    return "A";

  const unsigned numLettersInDiamond = letter - 'A';
  return doGetDiamond(numLettersInDiamond);
}
