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
 A 
)");
}

TEST_F(DiamondPrinterFixture, C_shouldReturnCorrectDiamond) {
  assertDiamond('C', R"(  A  
 B B 
C   C
 B B 
  A  
)");
}

TEST_F(DiamondPrinterFixture, D_shouldReturnCorrectDiamond) {
  assertDiamond('D', R"(   A   
  B B  
 C   C 
D     D
 C   C 
  B B  
   A   
)");
}

TEST_F(DiamondPrinterFixture, Z_shouldReturnCorrectDiamond) {
  assertDiamond('J', R"(         A         
        B B        
       C   C       
      D     D      
     E       E     
    F         F    
   G           G   
  H             H  
 I               I 
J                 J
 I               I 
  H             H  
   G           G   
    F         F    
     E       E     
      D     D      
       C   C       
        B B        
         A         
)");
}

TEST_F(DiamondPrinterFixture, NotCapitalLetter_shouldReturnError) {
  assertDiamond('a', "Error");
  assertDiamond('&', "Error");
  assertDiamond('1', "Error");
}