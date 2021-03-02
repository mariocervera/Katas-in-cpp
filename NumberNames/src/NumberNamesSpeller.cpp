#include "NumberNamesSpeller.hpp"

static string units[] = {"zero", "one", "two", "three", "four",
                           "five", "six", "seven", "eight", "nine"};

static string firstTen[] = { "ten", "eleven", "twelve", "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen" "nineteen" };

static string tens[] = { "ten", "twenty", "thirty", "forty", "fifty",
                           "sixty", "seventy", "eighty", "ninety"};

static string handle1DigitNumber(unsigned number) {
  return units[number];
}

static string handle2DigitNumber(unsigned number) {
  const string inputNumber = to_string(number);

  if (inputNumber.size() == 1)
    return handle1DigitNumber(number);

  if (inputNumber[0] == '1')
    return firstTen[number % 10];

  string result = "";
  result += tens[(number / 10) - 1] + " ";
  if (number % 10 != 0)
    result += units[number % 10] + " ";
  
  return result.substr(0, result.size() - 1);
}

static string handle3DigitNumber(unsigned number) {
  if (number < 100)
    return handle2DigitNumber(number);

  string result = units[number / 100] + " hundred";
  if (number % 100 != 0)
    result += " and " + handle2DigitNumber(number % 100);

  return result;
}

static string handle4DigitNumber(unsigned number) {
  string result = units[number / 1000] + " thousand";

  number %= 1000;
  
  if (number != 0) {
    if (number > 99)
      result += ", ";
    else
      result += " and ";
    
    result += handle3DigitNumber(number);
  }

  return result;
}

string NumberNamesSpeller::getNumberName(unsigned number) {
  const string inputNumber = to_string(number);

  if (inputNumber.size() == 4)
    return handle4DigitNumber(number);
  if (inputNumber.size() == 3)
    return handle3DigitNumber(number);
  if (inputNumber.size() == 2)
    return handle2DigitNumber(number);
  
  return handle1DigitNumber(number);
}
