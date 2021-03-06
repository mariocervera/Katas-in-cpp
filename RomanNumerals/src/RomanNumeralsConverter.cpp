#include "RomanNumeralsConverter.hpp"

enum class Context {
  Units = 1,
  Tens,
  Hundreds,
  Thousands
};

static string unit(Context context) {
  if (context == Context::Units)
    return "I";
  else if (context == Context::Tens)
    return "X";
  else if (context == Context::Hundreds)
    return "C";
  return "M";
}

static string fifth(Context context) {
  if (context == Context::Units)
    return "V";
  else if (context == Context::Tens)
    return "L";
  return "D";
}

static string tenth(Context context) {
  if (context == Context::Units)
    return "X";
  else if (context == Context::Tens)
    return "C";
  return "M";
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

  string romanNumberal = "";
  unsigned context = 4;

  for (int i = 1000; i > 0; i /= 10) {
    unsigned nextDigit = number / i;
    if(nextDigit != 0)
      romanNumberal += getRomanNumeralForDigit(nextDigit, static_cast<Context>(context));
    number %= i;
    --context;
  }
  return romanNumberal;
}
