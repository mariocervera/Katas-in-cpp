#include "PrimeFactorsCalculator.hpp"
#include <gtest/gtest.h>
#include <memory>

///
/// Fixture setup code: instantiation of the PrimeFactorsCalculator.
///
class PrimeFactorsCalculatorFixture : public ::testing::Test {
protected:
  void SetUp() override {
    calculator = std::make_unique<PrimeFactorsCalculator>();
  }

  // Custom assertion
  void assertFactors(unsigned num, const vector<unsigned> &factors) {
    ASSERT_TRUE(calculator->getPrimeFactors(num) == factors);
  }

  std::unique_ptr<PrimeFactorsCalculator> calculator;
};

///
/// Tests
/// 
TEST_F(PrimeFactorsCalculatorFixture, 0_and_1_shouldReturn_None) {
  assertFactors(0, {});
  assertFactors(1, {});
}

TEST_F(PrimeFactorsCalculatorFixture, 2_shouldReturn_2) {
  assertFactors(2, {2});
}

TEST_F(PrimeFactorsCalculatorFixture, 3_shouldReturn_3) {
  assertFactors(3, {3});
}

TEST_F(PrimeFactorsCalculatorFixture, 4_shouldReturn_2_2) {
  assertFactors(4, {2, 2});
}

TEST_F(PrimeFactorsCalculatorFixture, 6_shouldReturn_2_3) {
  assertFactors(6, {2, 3});
}

TEST_F(PrimeFactorsCalculatorFixture, 8_shouldReturn_2_2_2) {
  assertFactors(8, {2, 2, 2});
}

TEST_F(PrimeFactorsCalculatorFixture, 9_shouldReturn_3_3) {
  assertFactors(9, {3, 3});
}

TEST_F(PrimeFactorsCalculatorFixture, AcceptanceTest) {
  assertFactors(2*2*3*5*5*7*7*11, {2, 2, 3, 5, 5, 7, 7, 11});
}
