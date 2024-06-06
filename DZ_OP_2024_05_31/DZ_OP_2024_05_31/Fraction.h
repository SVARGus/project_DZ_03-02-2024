#pragma once

class Fraction
{
	int Numeral; // числитель
	int Denominator; // знаменатель

public:

	void setNumDem(int, int); // Запись числителя и знаменателя
	int getNumeral(); // вывод числителя
	int getDenominator(); // вывод знаменателя
	int GCD(); // Нахождение НОД
	int GCD(Fraction x1, Fraction x2); // Нахождение НОД знаменателей двух дробей
	int LCM(); // Нахождение НОК
	int LCM(Fraction x1, Fraction x2); // Нахождение НОК знаменателей двух дробей
	Fraction setPlusNew(Fraction x1, Fraction x2); // сложение дробей с выводом резултатов в новый объект
	Fraction setMinusNew(Fraction x1, Fraction x2); // вычетание дробей с выводом резултатов в новый объект
	Fraction setDivideNew(Fraction x1, Fraction x2); // деление дробей с выводом резултатов в новый объект
	Fraction setMultiplyNew(Fraction x1, Fraction x2); // умножение дробей с выводом резултатов в новый объект

	void setPlus(Fraction x1); // сложение дробей в исходную дробь
	void setMinus(Fraction x1); // вычетание дробей в исходную дробь
	void setDivide(Fraction x1); // деление дробей в исходную дробь
	void setMultiply(Fraction x1); // умножение дробей в исходную дробь
	
	void printPlus(Fraction x1, Fraction x2); // сложение дробей и вывод результата на экран
	void printMinus(Fraction x1, Fraction x2); // вычетание дробей и вывод результата на экран
	void printDivide(Fraction x1, Fraction x2); // деление дробей и вывод результата на экран
	void printMultiply(Fraction x1, Fraction x2); // умножение дробей и вывод результата на экран
};