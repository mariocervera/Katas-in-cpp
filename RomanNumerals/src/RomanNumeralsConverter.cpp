#include "RomanNumeralsConverter.hpp"
#include <math.h>

static string unit[] = {"I", "X", "C", "M"};
static string fifth[] = {"V", "L", "D"};
static string tenth[] = {"X", "C", "M"};

static string getNUnits(unsigned n, unsigned position) {
  string units = "";
  for (int i = 0; i < n; ++i)
    units += unit[position];
  return units;
}

static string getRomanNumeralForDigitAtPosition(unsigned digit, unsigned position) {
  string roman = "";

  if (digit <= 3)
    roman += getNUnits(digit, position);

  if (digit == 4)
    roman += unit[position];

  if (4 <= digit && digit <= 8)
    roman += fifth[position];

  if (6 <= digit && digit <= 8)
    roman += getNUnits(digit - 5, position);

  if (digit == 9)
    roman += (unit[position] + tenth[position]);

  return roman;
}

static string getRomanNumeralForDigit(unsigned digit, unsigned magnitude) {
  if (digit == 0)
    return "";

  unsigned position = log10(magnitude);
  return getRomanNumeralForDigitAtPosition(digit, position);
}

string RomanNumeralsConverter::getRomanNumeral(unsigned number) {
  if (number > 3000)
    return "Error";

  string romanNumeral = "";
  for (unsigned magnitude = 1000; magnitude > 0; magnitude /= 10) {
    unsigned digit = number/magnitude;
    romanNumeral += getRomanNumeralForDigit(digit, magnitude);
    number %= magnitude;
  }

  return romanNumeral;
}
