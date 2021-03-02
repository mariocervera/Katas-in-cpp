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

TEST_F(NumberNamesSpellerFixture, zero_shouldReturnNamedNumber) {
  assertNumberName(0, "zero");
}

TEST_F(NumberNamesSpellerFixture, singleDigit_shouldReturnNamedNumber) {
  assertNumberName(1, "one");
  assertNumberName(5, "five");
  assertNumberName(7, "seven");
}

TEST_F(NumberNamesSpellerFixture, twoDigitsEndingInZero_shouldReturnNamedNumber) {
  assertNumberName(20, "twenty");
  assertNumberName(40, "forty");
  assertNumberName(80, "eighty");
}

TEST_F(NumberNamesSpellerFixture, twoDigitsNotStartingAtOne_shouldReturnNamedNumber) {
  assertNumberName(21, "twenty one");
  assertNumberName(63, "sixty three");
  assertNumberName(99, "ninety nine");
}

TEST_F(NumberNamesSpellerFixture, twoDigitsStartingAtOne_shouldReturnNamedNumber) {
  assertNumberName(11, "eleven");
  assertNumberName(14, "fourteen");
  assertNumberName(16, "sixteen");
}

TEST_F(NumberNamesSpellerFixture, threeDigitsEndingAllZeros_shouldReturnNamedNumber) {
  assertNumberName(100, "one hundred");
  assertNumberName(400, "four hundred");
  assertNumberName(700, "seven hundred");
}

TEST_F(NumberNamesSpellerFixture, threeDigitsWithoutIntermediateZeros_shouldReturnNamedNumber) {
  assertNumberName(111, "one hundred and eleven");
  assertNumberName(554, "five hundred and fifty four");
  assertNumberName(833, "eight hundred and thirty three");
}

TEST_F(NumberNamesSpellerFixture, threeDigitsWithIntermediateZeros_shouldReturnNamedNumber) {
  assertNumberName(101, "one hundred and one");
  assertNumberName(505, "five hundred and five");
  assertNumberName(907, "nine hundred and seven");
}

TEST_F(NumberNamesSpellerFixture, fourDigitsEndingAllZeros_shouldReturnNamedNumber) {
  assertNumberName(1000, "one thousand");
  assertNumberName(2000, "two thousand");
  assertNumberName(5000, "five thousand");
}

TEST_F(NumberNamesSpellerFixture, fourDigitsWithoutIntermediateZeros_shouldReturnNamedNumber) {
  assertNumberName(1111, "one thousand, one hundred and eleven");
  assertNumberName(2412, "two thousand, four hundred and twelve");
  assertNumberName(6178, "six thousand, one hundred and seventy eight");
}

TEST_F(NumberNamesSpellerFixture, fourDigitsWithIntermediateZeros_shouldReturnNamedNumber) {
  assertNumberName(1101, "one thousand, one hundred and one");
  assertNumberName(1011, "one thousand and eleven");
  assertNumberName(2002, "two thousand and two");
  assertNumberName(3056, "three thousand and fifty six");
  assertNumberName(9449, "nine thousand, four hundred and forty nine");
}


