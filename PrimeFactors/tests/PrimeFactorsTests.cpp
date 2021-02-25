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
TEST_F(PrimeFactorsCalculatorFixture, 0_and_1_shouldReturnEmptyList) {
    assertFactors(0, {});
    assertFactors(1, {});
}
