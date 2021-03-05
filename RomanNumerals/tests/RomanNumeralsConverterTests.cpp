#include "RomanNumeralsConverter.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace std;

///
/// Fixture setup code: instantiation of the RomanNumeralsConverter.
///
class RomanNumeralsConverterFixture : public ::testing::Test {
protected:
  void SetUp() override {
    converter = make_unique<RomanNumeralsConverter>();
  }

  // Custom assertion.
  void assertRomanNumeral(unsigned number, const string &expectedRomanNumeral) {
    ASSERT_EQ(converter->getRomanNumeral(number), expectedRomanNumeral);
  }

  unique_ptr<RomanNumeralsConverter> converter;
};

///
/// Tests
///
TEST_F(RomanNumeralsConverterFixture, 1_shouldReturnI) {
  assertRomanNumeral(1, "I");
}
