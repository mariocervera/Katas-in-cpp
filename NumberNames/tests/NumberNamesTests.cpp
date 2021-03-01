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
