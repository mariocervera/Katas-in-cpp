#include "RomanNumeralsConverter.hpp"

string RomanNumeralsConverter::getRomanNumeral(unsigned number) {
	string romanNumeral = "";

	if (number <= 3)
		for (unsigned i = 1; i <= number; ++i)
			romanNumeral += "I";

	if (number == 4)
		romanNumeral += "I";

	if (4 <= number && number <= 8)
		romanNumeral += "V";

	if(6 <= number && number <=8)
		for (unsigned i = 6; i <= number; ++i)
			romanNumeral += "I";

	if (number == 9)
		romanNumeral += "I";

	if (9 <= number)
		romanNumeral += "X";

	return romanNumeral;
}
