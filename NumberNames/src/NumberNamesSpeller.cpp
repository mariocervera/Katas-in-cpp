#include "NumberNamesSpeller.hpp"

static string zeroToTen[] = {"zero", "one", "two", "three", "four",
                           "five", "six", "seven", "eight", "nine"};

static string tenToNineteen[] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen" "nineteen"};

static string tens[] = {"zero", "ten", "twenty", "thirty", "forty", "fifty",
                           "sixty", "seventy", "eighty", "ninety"};

static string tensSeparator() { return " "; }

static string hundredSeparator() { return " and "; }

static string thousandSeparator(unsigned leastSignificantDigits) {
  return (leastSignificantDigits > 99) ? ", " : " and ";
}

static string suffix(const string &separator, string(*handleNumberFunction)(unsigned),
                     unsigned number) {
  if (number != 0)
    return separator + handleNumberFunction(number);
  return "";
}

static string handleUnitNumber(unsigned number) {
  if(number < 10)
    return zeroToTen[number];
  return tenToNineteen[number%10];
}

static string handleTensNumber(unsigned number) {
  string result = tens[number/10];
  number %= 10;
  return result + suffix(tensSeparator(), &handleUnitNumber, number);
}

static string handle2DigitNumber(unsigned number) {
  if (number < 20)
    return handleUnitNumber(number);
  return handleTensNumber(number);
}

static string handleHundredNumber(unsigned number) {
  string result = handleUnitNumber(number/100) + " hundred";
  number %= 100;
  return result + suffix(hundredSeparator(), &handle2DigitNumber, number);
}

static string handle3DigitNumber(unsigned number) {
  if (number < 100)
    return handle2DigitNumber(number);
  return handleHundredNumber(number);
}

static string handleThousandNumber(unsigned number) {
  string result = handle3DigitNumber(number/1000) + " thousand";
  number %= 1000;
  return result + suffix(thousandSeparator(number), &handle3DigitNumber, number);
}

string NumberNamesSpeller::getNumberName(unsigned number) {
  if (number < 10)
    return handleUnitNumber(number);
  if(number < 100)
    return handle2DigitNumber(number);
  if (number < 1000)
    return handle3DigitNumber(number);

  return handleThousandNumber(number);
}
