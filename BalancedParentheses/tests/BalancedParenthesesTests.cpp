#include "BalancedParentheses.hpp"
#include <gtest/gtest.h>
#include <memory>

///
/// Fixture setup code: instantiation of the BalanceChecker.
/// 
class BalanceChecherFixture : public ::testing::Test {
protected:
  void SetUp() override {
    checker = std::make_unique<BalanceChecker>();
  }

  std::unique_ptr<BalanceChecker> checker;
};

///
/// Tests
/// 
TEST_F(BalanceChecherFixture, EmptyStringShouldReturnTrue) {
  EXPECT_TRUE(checker->check(""));
}

TEST_F(BalanceChecherFixture, OddNumberOfSymbolsShouldReturnFalse) {
  EXPECT_FALSE(checker->check("("));
  EXPECT_FALSE(checker->check("()("));
  EXPECT_FALSE(checker->check("(]{"));
  EXPECT_FALSE(checker->check("}]{())"));
}

TEST_F(BalanceChecherFixture, TwoBalancedSymbolsShouldReturnTrue) {
  EXPECT_TRUE(checker->check("()"));
  EXPECT_TRUE(checker->check("[]"));
  EXPECT_TRUE(checker->check("{}"));
}

TEST_F(BalanceChecherFixture, TwoUnbalancedSymbolsShouldReturnFalse) {
  EXPECT_FALSE(checker->check("(("));
  EXPECT_FALSE(checker->check("[{"));
}

TEST_F(BalanceChecherFixture, FourSequentiallyBalancedSymbolsShouldReturnTrue) {
  EXPECT_TRUE(checker->check("(){}"));
  EXPECT_TRUE(checker->check("{}[]"));
  EXPECT_TRUE(checker->check("[]()"));
}

TEST_F(BalanceChecherFixture, FourMixedBalancedSymbolsShouldReturnTrue) {
  EXPECT_TRUE(checker->check("({})"));
  EXPECT_TRUE(checker->check("{[]}"));
  EXPECT_TRUE(checker->check("[()]"));
}

TEST_F(BalanceChecherFixture, AcceptanceTest) {
  EXPECT_TRUE(checker->check("{()}[[{}]]"));
  EXPECT_FALSE(checker->check("{()}[[{]]]"));
}