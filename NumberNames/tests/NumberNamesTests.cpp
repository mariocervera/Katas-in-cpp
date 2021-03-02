#include "NumberNamesSpeller.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace std;

///
/// Fixture setup code: instantiation of the NumberNamesSpeller.
///
class NumberNamesSpellerFixture : public ::testing::Test {
protected:
  void SetUp() override {
    speller = make_unique<NumberNamesSpeller>();
  }

  // Custom assertion.
  void assertNumberName(unsigned number, const string &expectedNumberName) {
    ASSERT_EQ(speller->getNumberName(number), expectedNumberName);
  }

  unique_ptr<NumberNamesSpeller> speller;
};

///
/// Tests
/// 
TEST_F(NumberNamesSpellerFixture, zero_shouldReturnNumberName) {
  assertNumberName(0, "zero");
}

TEST_F(NumberNamesSpellerFixture, singleDigit_shouldReturnNumberName) {
  assertNumberName(1, "one");
  assertNumberName(5, "five");
  assertNumberName(7, "seven");
}

TEST_F(NumberNamesSpellerFixture, twoDigitsEndingInZero_shouldReturnNumberName) {
  assertNumberName(20, "twenty");
  assertNumberName(40, "forty");
  assertNumberName(80, "eighty");
}

TEST_F(NumberNamesSpellerFixture, twoDigitsNotStartingAtOne_shouldReturnNumberName) {
  assertNumberName(21, "twenty one");
  assertNumberName(63, "sixty three");
  assertNumberName(99, "ninety nine");
}

TEST_F(NumberNamesSpellerFixture, twoDigitsStartingAtOne_shouldReturnNumberName) {
  assertNumberName(11, "eleven");
  assertNumberName(14, "fourteen");
  assertNumberName(16, "sixteen");
}

TEST_F(NumberNamesSpellerFixture, threeDigitsEndingAllZeros_shouldReturnNumberName) {
  assertNumberName(100, "one hundred");
  assertNumberName(400, "four hundred");
  assertNumberName(700, "seven hundred");
}

TEST_F(NumberNamesSpellerFixture, threeDigitsWithoutIntermediateZeros_shouldReturnNumberName) {
  assertNumberName(111, "one hundred and eleven");
  assertNumberName(554, "five hundred and fifty four");
  assertNumberName(833, "eight hundred and thirty three");
}

TEST_F(NumberNamesSpellerFixture, threeDigitsWithIntermediateZeros_shouldReturnNumberName) {
  assertNumberName(101, "one hundred and one");
  assertNumberName(505, "five hundred and five");
  assertNumberName(907, "nine hundred and seven");
}

TEST_F(NumberNamesSpellerFixture, fourDigitsEndingAllZeros_shouldReturnNumberName) {
  assertNumberName(1000, "one thousand");
  assertNumberName(2000, "two thousand");
  assertNumberName(5000, "five thousand");
}

TEST_F(NumberNamesSpellerFixture, fourDigitsWithoutIntermediateZeros_shouldReturnNumberName) {
  assertNumberName(1111, "one thousand, one hundred and eleven");
  assertNumberName(2412, "two thousand, four hundred and twelve");
  assertNumberName(6178, "six thousand, one hundred and seventy eight");
  assertNumberName(9449, "nine thousand, four hundred and forty nine");
}

TEST_F(NumberNamesSpellerFixture, fourDigitsWithIntermediateZeros_shouldReturnNumberName) {
  assertNumberName(1011, "one thousand and eleven");
  assertNumberName(1501, "one thousand, five hundred and one");
  assertNumberName(2002, "two thousand and two");
  assertNumberName(3056, "three thousand and fifty six");
}

TEST_F(NumberNamesSpellerFixture, fiveDigitsEndingAllZeros_shouldReturnNumberName) {
  assertNumberName(10000, "ten thousand");
  assertNumberName(53000, "fifty three thousand");
  assertNumberName(87000, "eighty seven thousand");
}

TEST_F(NumberNamesSpellerFixture, fiveDigitsWithoutIntermediateZeros_shouldReturnNumberName) {
  assertNumberName(11111, "eleven thousand, one hundred and eleven");
  assertNumberName(23545, "twenty three thousand, five hundred and forty five");
  assertNumberName(77946, "seventy seven thousand, nine hundred and forty six");
}

TEST_F(NumberNamesSpellerFixture, fiveDigitsWithIntermediateZeros_shouldReturnNumberName) {
  assertNumberName(12609, "twelve thousand, six hundred and nine");
  assertNumberName(20022, "twenty thousand and twenty two");
  assertNumberName(33001, "thirty three thousand and one");
}

TEST_F(NumberNamesSpellerFixture, sixDigits_shouldReturnNumberName) {
  assertNumberName(512607, "five hundred and twelve thousand, six hundred and seven");
  assertNumberName(500007, "five hundred thousand and seven");
  assertNumberName(601109, "six hundred and one thousand, one hundred and nine");
}

TEST_F(NumberNamesSpellerFixture, MoreThanSixDigits_shouldReturnError) {
  assertNumberName(1234567, "Error");
  assertNumberName(12345678, "Error");
  assertNumberName(123456789, "Error");
}
