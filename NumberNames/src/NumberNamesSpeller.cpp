#include "NumberNamesSpeller.hpp"

static string units[] = {"zero", "one", "two", "three", "four",
                           "five", "six", "seven", "eight", "nine"};

static string tens[] = { "ten", "twenty", "thirty", "forty", "fifty",
                           "sixty", "seventy", "eighty", "ninety"};

string NumberNamesSpeller::getNumberName(unsigned number) {
  const string numberStr = to_string(number);
  
  if (numberStr.size() == 2) {
    return tens[(number / 10) - 1];
  }

  return units[number];
}
