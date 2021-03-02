#include "NumberNamesSpeller.hpp"

static string units[] = {"zero", "one", "two", "three", "four",
                           "five", "six", "seven", "eight", "nine"};

static string firstTen[] = { "ten", "eleven", "twelve", "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen" "nineteen" };

static string tens[] = { "ten", "twenty", "thirty", "forty", "fifty",
                           "sixty", "seventy", "eighty", "ninety"};

static string separator(unsigned number) {
  return (number > 99) ? ", " : " and ";
}

static string handleUnitNumber(unsigned number) {
  return units[number];
}

static string handle2DigitNumber(unsigned number) {
  if (number < 10)
    return handleUnitNumber(number);
  if (number < 20)
    return firstTen[number % 10];

  string _tens = tens[(number / 10) - 1];
  if (number % 10 == 0)
    return _tens;

  return _tens + " " + units[number % 10];
}

static string handleHundredNumber(unsigned number) {
  string result = handleUnitNumber(number/100) + " hundred";

  number %= 100;
  if (number != 0)
    result += separator(number) + handle2DigitNumber(number);

  return result;
}

static string handle3DigitNumber(unsigned number) {
  if (number < 100)
    return handle2DigitNumber(number);

  return handleHundredNumber(number);
}

static string handleThousandNumber(unsigned number) {
  string result = handle3DigitNumber(number/1000) + " thousand";

  number %= 1000;
  if (number != 0) 
    result += separator(number) + handle3DigitNumber(number);

  return result;
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
