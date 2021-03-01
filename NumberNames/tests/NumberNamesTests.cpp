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
