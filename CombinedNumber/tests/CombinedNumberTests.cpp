#include "CombinedNumberCalculator.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace std;

///
/// Fixture setup code: instantiation of the CombinedNumberCalculator.
///
class CombinedNumberCalculatorFixture : public ::testing::Test {
protected:
  void SetUp() override {
    calculator = std::make_unique<CombinedNumberCalculator>();
  }

  // Custom assertion.
  void assertCombinedNumber(vector<unsigned> numbers, const string &expectedCombinedNumber) {
    ASSERT_EQ(calculator->getCombinedNumber(numbers), expectedCombinedNumber);
  }

  std::unique_ptr<CombinedNumberCalculator> calculator;
};

///
/// Tests
/// 
TEST_F(CombinedNumberCalculatorFixture, EmptyList_shouldReturnEmptyString) {
  assertCombinedNumber({}, "");
}

TEST_F(CombinedNumberCalculatorFixture, OneNumber_shouldReturnTheNumberAsString) {
  assertCombinedNumber({4}, "4");
}

TEST_F(CombinedNumberCalculatorFixture, TwoNumbersInRightPosition_shouldReturnCorrectCombinedNumber) {
  assertCombinedNumber({4, 20}, "420");
  assertCombinedNumber({20, 1}, "201");
}

TEST_F(CombinedNumberCalculatorFixture, SeveralNumbersWithDistinctHighestDigit_shouldReturnCorrectCombinedNumber) {
  assertCombinedNumber({50, 2, 1, 9}, "95021");
  assertCombinedNumber({105, 52, 23, 331, 8 }, "85233123105");
}
