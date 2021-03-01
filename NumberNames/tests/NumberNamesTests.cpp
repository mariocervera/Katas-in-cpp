#include "NumberNamesCalculator.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace std;

///
/// Fixture setup code: instantiation of the NumberNamesCalculator.
///
class CombinedNumberCalculatorFixture : public ::testing::Test {
protected:
  void SetUp() override {
    calculator = make_unique<NumberNamesCalculator>();
  }

  // Custom assertion.
  void assertNumberName(unsigned number, const string &expectedNumberName) {
    ASSERT_EQ(calculator->getNumberName(number), expectedNumberName);
  }

  unique_ptr<NumberNamesCalculator> calculator;
};

///
/// Tests
/// 

TEST_F(CombinedNumberCalculatorFixture, zero_shouldReturnNamedNumber) {
  assertNumberName(0, "zero");
}
