#include "RomanNumeralsConverter.hpp"

static string unit[] = {"I", "X", "C", "M"};
static string fifth[] = {"V", "L", "D"};
static string tenth[] = {"X", "C", "M"};

static string getRomanNumeralForDigit(unsigned digit, unsigned digitPosition) {
  string digitInRoman = "";

  if (digit <= 3)
    for (unsigned i = 1; i <= digit; ++i)
      digitInRoman += unit[digitPosition];

  if (digit == 4 || digit == 9)
    digitInRoman += unit[digitPosition];

  if (4 <= digit && digit <= 8)
    digitInRoman += fifth[digitPosition];

  if(6 <= digit && digit <= 8)
    for (unsigned i = 6; i <= digit; ++i)
      digitInRoman += unit[digitPosition];

  if (9 == digit)
    digitInRoman += tenth[digitPosition];

  return digitInRoman;
}

string RomanNumeralsConverter::getRomanNumeral(unsigned number) {
  string romanNumeral = "";
  
  unsigned digitPosition = 3;
  for (int magnitude = 1000; magnitude > 0; magnitude /= 10) {
    unsigned digit = number/magnitude;
    if(digit != 0)
      romanNumeral += getRomanNumeralForDigit(digit, digitPosition);
    number %= magnitude;
    --digitPosition;
  }

  return romanNumeral;
}
