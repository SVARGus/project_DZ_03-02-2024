#include "Fraction.h"
#include <iostream>

void Fraction::setNumDen(int num, int den) {
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
int Fraction::GCD(Fraction x1, Fraction x2) {
	int a = x1.Denominator;
	int b = x2.Denominator;
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
int Fraction::LCM(Fraction x1, Fraction x2) {
	return x1.Denominator * x2.Denominator / GCD(Fraction x1, Fraction x2);
}

Fraction Fraction::setPlusNew(Fraction x1, Fraction x2) {
	Fraction Res;
	if (x1.Denominator == x2.Denominator)
	{
		Res.Numeral = x1.Numeral + x2.Numeral;
		Res.Denominator = x1.Denominator;
		Res.GCD();
		return Res;
	}
	Res.Denominator = LCM(Fraction x1, Fraction x2);
	Res.Numeral = x1.Numeral * (Res.Denominator / x1.Denominator) + x2.Numeral * (Res.Denominator / x2.Denominator);
	Res.GCD();
	return Res;
}
Fraction Fraction::setMinusNew(Fraction x1, Fraction x2) {
	Fraction Res;
	if (x1.Denominator == x2.Denominator)
	{
		Res.Numeral = x1.Numeral - x2.Numeral;
		Res.Denominator = x1.Denominator;
		Res.GCD();
		return Res;
	}
	Res.Denominator = LCM(Fraction x1, Fraction x2);
	Res.Numeral = x1.Numeral * (Res.Denominator / x1.Denominator) - x2.Numeral * (Res.Denominator / x2.Denominator);
	Res.GCD();
	return Res;
}
Fraction Fraction::setDivideNew(Fraction x1, Fraction x2) {
	Fraction Res;
	Res.Numeral = x1.Numeral * x2.Denominator;
	Res.Denominator = x1.Denominator * x2.Numeral;
	Res.GCD();
	return Res;
}
Fraction Fraction::setMultiplyNew(Fraction x1, Fraction x2) {
	Fraction Res;
	Res.Numeral = x1.Numeral * x2.Numeral;
	Res.Denominator = x1.Denominator * x2.Denominator;
	Res.GCD();
	return Res;
}
void Fraction::printFraction() {
	std::cout << "Числитель дроби = " << Numeral << std::endl;
	std::cout << "Знаменатель дроби = " << Denominator << std::endl;
}
