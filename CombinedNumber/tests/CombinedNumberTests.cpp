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

TEST_F(CombinedNumberCalculatorFixture, SeveralNumbersWithoutCommonPrefix_shouldReturnCorrectCombinedNumber) {
  assertCombinedNumber({50, 2, 1, 9}, "95021");
  assertCombinedNumber({105, 63, 331, 8}, "863331105");
}

TEST_F(CombinedNumberCalculatorFixture, DuplicateNumbers_shouldReturnCorrectCombinedNumber) {
  assertCombinedNumber({78, 78}, "7878");
  assertCombinedNumber({4, 25, 4, 73}, "734425");
  assertCombinedNumber({56, 11, 32, 11}, "56321111");
}

TEST_F(CombinedNumberCalculatorFixture, PrefixNumberWhoseHighestOrderDigitIsGreaterThanSuffix_shouldReturnCorrectCombinedNumber) {
  assertCombinedNumber({4, 42}, "442");
  assertCombinedNumber({538, 5, 52}, "553852");
  assertCombinedNumber({420, 42, 423}, "42423420");
  assertCombinedNumber({66, 661, 2, 9}, "9666612");
  assertCombinedNumber({817, 81, 2, 9 }, "9818172");
}

TEST_F(CombinedNumberCalculatorFixture, PrefixNumberWhoseHighestOrderDigitIsLessThanSuffix_shouldReturnCorrectCombinedNumber) {
  assertCombinedNumber({5, 58, 56}, "58565");
  assertCombinedNumber({682, 675, 6}, "6826756");
  assertCombinedNumber({670, 88, 69, 6}, "88696706");
  assertCombinedNumber({66, 667, 2, 9}, "9667662");
  assertCombinedNumber({66, 667, 668, 9}, "966866766");
}

TEST_F(CombinedNumberCalculatorFixture, PrefixNumberWhoseHighestOrderDigitIsEqualToBeginningOfSuffix_shouldReturnCorrectCombinedNumber) {
  assertCombinedNumber({4, 445, 2, 7}, "744542");
  assertCombinedNumber({4, 441, 2, 7}, "744412");
  assertCombinedNumber({332, 3, 10}, "333210");
  assertCombinedNumber({45, 3, 336}, "453363");
  assertCombinedNumber({53, 5356, 6}, "6535653");
  assertCombinedNumber({53, 5351, 6}, "6535351");
}

TEST_F(CombinedNumberCalculatorFixture, PrefixNumberWhoseHighestOrderDigitIsEqualToSuffix_shouldReturnCorrectCombinedNumber) {
  assertCombinedNumber({53, 535, 1}, "535531");
  assertCombinedNumber({53, 535, 6}, "653553");
  assertCombinedNumber({53, 535, 5}, "553553");
  assertCombinedNumber({53, 5355, 6}, "6535553");
  assertCombinedNumber({373, 37}, "37373");
  assertCombinedNumber({626, 62}, "62662");
}

TEST_F(CombinedNumberCalculatorFixture, AcceptanceTest) {
  assertCombinedNumber({105, 62, 3, 78, 420, 336, 50, 8, 42, 626, 373, 423, 535, 78, 5, 667, 37, 23, 331, 8, 56, 66, 78}, "887878786676662662565535504242342037373336333123105");
}
