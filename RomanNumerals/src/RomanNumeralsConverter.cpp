#include "RomanNumeralsConverter.hpp"

static string unit() {
		return "I";
}

static string fifth() {
	return "V";
}

static string tenth() {
	return "X";
}

string RomanNumeralsConverter::getRomanNumeral(unsigned number) {
	string romanNumeral = "";

	if (number <= 3)
		for (unsigned i = 1; i <= number; ++i)
			romanNumeral += unit();

	if (number == 4 || number == 9)
		romanNumeral += unit();

	if (4 <= number && number <= 8)
		romanNumeral += fifth();

	if(6 <= number && number <= 8)
		for (unsigned i = 6; i <= number; ++i)
			romanNumeral += unit();

	if (9 <= number)
		romanNumeral += tenth();

	return romanNumeral;
}
