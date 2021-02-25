#include "CombinedNumberCalculator.hpp"
#include <gtest/gtest.h>
#include <memory>

///
/// Fixture setup code: instantiation of the CombinedNumberCalculator.
///
class CombinedNumberCalculatorFixture : public ::testing::Test {
protected:
  void SetUp() override {
    calculator = std::make_unique<CombinedNumberCalculator>();
  }

  std::unique_ptr<CombinedNumberCalculator> calculator;
};

///
/// Tests
/// 
TEST_F(CombinedNumberCalculatorFixture, aaa) {
  ASSERT_TRUE(true);
}
