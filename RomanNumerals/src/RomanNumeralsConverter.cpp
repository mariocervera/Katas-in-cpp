#include "RomanNumeralsConverter.hpp"

enum class Context {
  Units = 1,
  Tens,
  Hundreds,
  Thousands
};

static string unit(Context context) {
  if(context == Context::Units)
    return "I";
  return "X";
}

static string fifth(Context context) {
  if (context == Context::Units)
    return "V";
  return "L";
}

static string tenth(Context context) {
  if (context == Context::Units)
    return "X";
  return "C";
}

static string getRomanNumeralForDigit(unsigned digit, Context context) {
  string romanNumeral = "";

  if (digit <= 3)
    for (unsigned i = 1; i <= digit; ++i)
      romanNumeral += unit(context);

  if (digit == 4 || digit == 9)
    romanNumeral += unit(context);

  if (4 <= digit && digit <= 8)
    romanNumeral += fifth(context);

  if(6 <= digit && digit <= 8)
    for (unsigned i = 6; i <= digit; ++i)
      romanNumeral += unit(context);

  if (9 == digit)
    romanNumeral += tenth(context);

  return romanNumeral;
}

string RomanNumeralsConverter::getRomanNumeral(unsigned number) {
  return getRomanNumeralForDigit(number, Context::Units);
}
