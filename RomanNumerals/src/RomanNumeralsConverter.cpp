#include "RomanNumeralsConverter.hpp"

static string unit[] = {"I", "X", "C", "M"};
static string fifth[] = {"V", "L", "D"};
static string tenth[] = {"X", "C", "M"};

static string getRomanNumeralFor(unsigned digit, unsigned position) {
  string digitInRoman = "";

  if (digit == 0)
    return digitInRoman;

  if (digit <= 3)
    for (unsigned i = 1; i <= digit; ++i)
      digitInRoman += unit[position];

  if (digit == 4 || digit == 9)
    digitInRoman += unit[position];

  if (4 <= digit && digit <= 8)
    digitInRoman += fifth[position];

  if(6 <= digit && digit <= 8)
    for (unsigned i = 6; i <= digit; ++i)
      digitInRoman += unit[position];

  if (9 == digit)
    digitInRoman += tenth[position];

  return digitInRoman;
}

string RomanNumeralsConverter::getRomanNumeral(unsigned number) {
  if (number > 3000)
    return "Error";

  string romanNumeral = "";

  for (unsigned magnitude = 1000, position = 3; magnitude > 0; magnitude /= 10, --position) {
    unsigned digit = number/magnitude;
    romanNumeral += getRomanNumeralFor(digit, position);
    number %= magnitude;
  }

  return romanNumeral;
}
