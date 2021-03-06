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

TEST_F(RomanNumeralsConverterFixture, 25_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(25, "XXV");
}

TEST_F(RomanNumeralsConverterFixture, 34_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(34, "XXXIV");
}

TEST_F(RomanNumeralsConverterFixture, 47_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(47, "XLVII");
}

TEST_F(RomanNumeralsConverterFixture, 53_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(53, "LIII");
}

TEST_F(RomanNumeralsConverterFixture, 59_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(59, "LIX");
}

TEST_F(RomanNumeralsConverterFixture, 70_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(70, "LXX");
}

TEST_F(RomanNumeralsConverterFixture, 81_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(81, "LXXXI");
}

TEST_F(RomanNumeralsConverterFixture, 87_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(87, "LXXXVII");
}

TEST_F(RomanNumeralsConverterFixture, 92_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(92, "XCII");
}

TEST_F(RomanNumeralsConverterFixture, 99_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(99, "XCIX");
}

TEST_F(RomanNumeralsConverterFixture, 100_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(100, "C");
}

TEST_F(RomanNumeralsConverterFixture, 105_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(105, "CV");
}

TEST_F(RomanNumeralsConverterFixture, 147_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(147, "CXLVII");
}

TEST_F(RomanNumeralsConverterFixture, 502_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(502, "DII");
}

TEST_F(RomanNumeralsConverterFixture, 633_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(633, "DCXXXIII");
}

TEST_F(RomanNumeralsConverterFixture, 870_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(870, "DCCCLXX");
}

TEST_F(RomanNumeralsConverterFixture, 988_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(988, "CMLXXXVIII");
}

TEST_F(RomanNumeralsConverterFixture, 1234_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(1234, "MCCXXXIV");
}

TEST_F(RomanNumeralsConverterFixture, 1990_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(1990, "MCMXC");
}

TEST_F(RomanNumeralsConverterFixture, 2008_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(2008, "MMVIII");
}

TEST_F(RomanNumeralsConverterFixture, 2500_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(2500, "MMD");
}

TEST_F(RomanNumeralsConverterFixture, 2601_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(2601, "MMDCI");
}

TEST_F(RomanNumeralsConverterFixture, 3000_shouldReturnCorrectRomanNumeral) {
  assertRomanNumeral(3000, "MMM");
}

TEST_F(RomanNumeralsConverterFixture, HigherThan3000_shouldReturnError) {
  assertRomanNumeral(3001, "Error");
  assertRomanNumeral(12345, "Error");
  assertRomanNumeral(543210, "Error");
}
