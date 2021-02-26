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
TEST_F(CombinedNumberCalculatorFixture, EmptyList_shouldReturn_EmptyString) {
  assertCombinedNumber({}, "");
}

TEST_F(CombinedNumberCalculatorFixture, OneNumber_shouldReturn_TheNumberAsString) {
  assertCombinedNumber({4}, "4");
}

TEST_F(CombinedNumberCalculatorFixture, TwoOrderedNumbers_shouldReturn_ConcatenatedNumbers) {
  assertCombinedNumber({4, 20}, "420");
}

TEST_F(CombinedNumberCalculatorFixture, TwoUnorderedNumbers_shouldReturn_ReversedConcatenation) {
  assertCombinedNumber({ 20, 4 }, "420");
}