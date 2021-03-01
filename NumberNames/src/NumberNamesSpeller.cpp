#include "NumberNamesSpeller.hpp"

static string units[] = {"zero", "one", "two", "three", "four",
                           "five", "six", "seven", "eight", "nine"};

static string tens[] = { "ten", "twenty", "thirty", "forty", "fifty",
                           "sixty", "seventy", "eighty", "ninety"};

string NumberNamesSpeller::getNumberName(unsigned number) {

  const string inputNumber = to_string(number);
  string result = "";

  if (inputNumber.size() == 2) {
    result += tens[(number / 10) - 1] + " ";
    if (number % 10 != 0)
      result += units[number % 10] + " ";

    return result.substr(0, result.size() - 1);
  }
  else
    result += units[number];

  return result;
}
