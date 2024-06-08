#pragma once

class Fraction
{
	int Numeral; // числитель
	int Denominator; // знаменатель

public:

	void setNumDen(int, int); // Запись числителя и знаменателя
	int getNumeral(); // вывод числителя
	int getDenominator(); // вывод знаменателя
	int GCD(); // Нахождение НОД
	int GCD(Fraction x1, Fraction x2); // Нахождение НОД знаменателей двух дробей
	int LCM(); // Нахождение НОК
	int LCM(Fraction x1, Fraction x2); // Нахождение НОК знаменателей двух дробей
	void setPlusNew(Fraction x1, Fraction x2); // сложение дробей с выводом резултатов в новый объект
	void setMinusNew(Fraction x1, Fraction x2); // вычетание дробей с выводом резултатов в новый объект
	void setDivideNew(Fraction x1, Fraction x2); // деление дробей с выводом резултатов в новый объект
	void setMultiplyNew(Fraction x1, Fraction x2); // умножение дробей с выводом резултатов в новый объект

	//void setPlus(Fraction x1); // сложение дробей в исходную дробь
	//void setMinus(Fraction x1); // вычетание дробей в исходную дробь
	//void setDivide(Fraction x1); // деление дробей в исходную дробь
	//void setMultiply(Fraction x1); // умножение дробей в исходную дробь
	
	void printFraction(); // Вывод на печать делителя
};