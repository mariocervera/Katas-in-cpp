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

TEST_F(RomanNumeralsConverterFixture, 6_7_8_shouldReturnCorrectRomanNumeral) {
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

TEST_F(RomanNumeralsConverterFixture, 11_12_13_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(11, "XI");
  assertRomanNumeral(12, "XII");
  assertRomanNumeral(13, "XIII");
}

TEST_F(RomanNumeralsConverterFixture, 14_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(14, "XIV");
}

TEST_F(RomanNumeralsConverterFixture, 15_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(15, "XV");
}

TEST_F(RomanNumeralsConverterFixture, 16_17_18_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(16, "XVI");
  assertRomanNumeral(17, "XVII");
  assertRomanNumeral(18, "XVIII");
}

TEST_F(RomanNumeralsConverterFixture, 19_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(19, "XIX");
}

TEST_F(RomanNumeralsConverterFixture, 20_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(20, "XX");
}

