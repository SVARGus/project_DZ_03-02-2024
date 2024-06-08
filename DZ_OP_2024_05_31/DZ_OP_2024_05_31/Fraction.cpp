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
	return x1.Denominator * x2.Denominator / GCD(x1, x2);
}

void Fraction::setPlusNew(Fraction x1, Fraction x2) {
	if (x1.Denominator == x2.Denominator)
	{
		Numeral = x1.Numeral + x2.Numeral;
		Denominator = x1.Denominator;
	}
	else
	{
		Denominator = LCM(x1, x2);
		Numeral = x1.Numeral * (Denominator / x1.Denominator) + x2.Numeral * (Denominator / x2.Denominator);
	}
	int x = GCD();
	if (x > 1)
	{
		Numeral /= x;
		Denominator /= x;
	}
}
void Fraction::setMinusNew(Fraction x1, Fraction x2) {
	if (x1.Denominator == x2.Denominator)
	{
		Numeral = x1.Numeral - x2.Numeral;
		Denominator = x1.Denominator;
	}
	else
	{
		Denominator = LCM(x1, x2);
		Numeral = x1.Numeral * (Denominator / x1.Denominator) - x2.Numeral * (Denominator / x2.Denominator);
	}
	int x = GCD();
	if (x > 1)
	{
		Numeral /= x;
		Denominator /= x;
	}
}
void Fraction::setDivideNew(Fraction x1, Fraction x2) {
	Numeral = x1.Numeral * x2.Denominator;
	Denominator = x1.Denominator * x2.Numeral;
	int x = GCD();
	if (x > 1)
	{
		Numeral /= x;
		Denominator /= x;
	}
}
void Fraction::setMultiplyNew(Fraction x1, Fraction x2) {
	Numeral = x1.Numeral * x2.Numeral;
	Denominator = x1.Denominator * x2.Denominator;
	int x = GCD();
	if (x > 1)
	{
		Numeral /= x;
		Denominator /= x;
	}
}
void Fraction::printFraction() {
	std::cout << "Числитель дроби = " << Numeral << std::endl;
	std::cout << "Знаменатель дроби = " << Denominator << std::endl;
}
