#include "Fraction.h"
#include <iostream>

void Fraction::setNumDem(int num, int den) {
	Numeral = num;
	Denominator = den;
	if (Denominator < 0)
	{
		Denominator *= -1;
		Numeral *= -1;
	}
	Numeral /= GCD();
	Denominator /= GCD();
}
int Fraction::getNumeral() {
	return Numeral;
}
int Fraction::getDenominator() {
	return Denominator;
}
int Fraction::GCD() {
	int a = Numeral;
	int b = Denominator;
	if (b > a)
		std::swap(a, b);
	while (a % b)
	{
		std::swap(a %= b, b);
	};
	return b;
}
int Fraction::LCM() {
	return Numeral * Denominator / GCD();
}
