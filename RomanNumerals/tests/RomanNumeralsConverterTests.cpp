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
TEST_F(RomanNumeralsConverterFixture, 1_2_3_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(1, "I");
  assertRomanNumeral(2, "II");
  assertRomanNumeral(3, "III");
}

TEST_F(RomanNumeralsConverterFixture, 4_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(4, "IV");
}

TEST_F(RomanNumeralsConverterFixture, 5_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(5, "V");
}

TEST_F(RomanNumeralsConverterFixture, 6_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(6, "VI");
  assertRomanNumeral(7, "VII");
  assertRomanNumeral(8, "VIII");
}

TEST_F(RomanNumeralsConverterFixture, 9_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(9, "IX");
}

TEST_F(RomanNumeralsConverterFixture, 10_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(10, "X");
}
