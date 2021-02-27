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
  assertCombinedNumber({105, 52, 23, 331, 8}, "85233123105");
}

TEST_F(CombinedNumberCalculatorFixture, DuplicateNumbers_shouldReturnCorrectCombinedNumber) {
  assertCombinedNumber({4, 25, 4, 73}, "734425");
  assertCombinedNumber({56, 1, 32, 1}, "563211");
}

TEST_F(CombinedNumberCalculatorFixture, WholeNumberIsPrefixAndRemainderIsSmaller_shouldReturnCorrectCombinedNumber) {
  assertCombinedNumber({4, 42}, "442");
  assertCombinedNumber({538, 5, 52}, "553852");
  assertCombinedNumber({632, 6754, 67}, "676754632");
  assertCombinedNumber({420, 42, 423}, "42423420");
}

TEST_F(CombinedNumberCalculatorFixture, WholeNumberIsPrefixAndRemainderIsBigger_shouldReturnCorrectCombinedNumber) {
  assertCombinedNumber({5, 50, 56}, "56550");
  assertCombinedNumber({670, 88, 61, 6}, "88670661");
  assertCombinedNumber({66, 667, 2, 9}, "9667662");
  assertCombinedNumber({66, 661, 2, 9}, "9666612");
}

TEST_F(CombinedNumberCalculatorFixture, WholeNumberIsPrefixAndRemainderStartsWithSameDigit_shouldReturnCorrectCombinedNumber) {
  assertCombinedNumber({4, 445, 2, 7}, "744542");
  assertCombinedNumber({4, 441, 2, 7}, "744412");
  assertCombinedNumber({332, 3, 10}, "333210");
  assertCombinedNumber({45, 3, 336}, "453363");
  assertCombinedNumber({53, 5356, 6}, "6535653");
  assertCombinedNumber({53, 5355, 6}, "6535553");
  assertCombinedNumber({53, 5351, 6}, "6535351");
}

TEST_F(CombinedNumberCalculatorFixture, WholeNumberIsPrefixAndRemainderStartsAndEndsWithSameDigit_shouldReturnCorrectCombinedNumber) {
  assertCombinedNumber({53, 535, 1}, "535531");
  assertCombinedNumber({53, 535, 6}, "653553");
  assertCombinedNumber({53, 535, 5}, "553553");
}

TEST_F(CombinedNumberCalculatorFixture, AcceptanceTest) {
  assertCombinedNumber({105, 3, 420, 336, 52, 8, 42, 423, 535, 5, 667, 23, 331, 8, 53, 66}, "88667665535535242423420336333123105");
}