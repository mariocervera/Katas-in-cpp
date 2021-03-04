#include "DiamondPrinter.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace std;

///
/// Fixture setup code: instantiation of the DiamondPrinter.
///
class DiamondPrinterFixture : public ::testing::Test {
protected:
  void SetUp() override {
    diamondPrinter = make_unique<DiamondPrinter>();
  }

  // Custom assertion.
  void assertDiamond(char letter, const string &expectedDiamond) {
    ASSERT_EQ(diamondPrinter->getDiamond(letter), expectedDiamond);
  }

  unique_ptr<DiamondPrinter> diamondPrinter;
};

///
/// Tests
/// 
TEST_F(DiamondPrinterFixture, A_shouldReturnCorrectDiamond) {
  assertDiamond('A', "A");
}

TEST_F(DiamondPrinterFixture, B_shouldReturnCorrectDiamond) {
  assertDiamond('B', R"( A 
B B
 A )");
}