#pragma once

class Fraction
{
	int Numeral; // ���������
	int Denominator; // �����������

public:

	void setNumDem(int, int); // ������ ��������� � �����������
	int getNumeral(); // ����� ���������
	int getDenominator(); // ����� �����������
	int GCD(); // ���������� ���
	int GCD(Fraction x1, Fraction x2); // ���������� ��� ������������ ���� ������
	int LCM(); // ���������� ���
	int LCM(Fraction x1, Fraction x2); // ���������� ��� ������������ ���� ������
	Fraction setPlusNew(Fraction x1, Fraction x2); // �������� ������ � ������� ���������� � ����� ������
	Fraction setMinusNew(Fraction x1, Fraction x2); // ��������� ������ � ������� ���������� � ����� ������
	Fraction setDivideNew(Fraction x1, Fraction x2); // ������� ������ � ������� ���������� � ����� ������
	Fraction setMultiplyNew(Fraction x1, Fraction x2); // ��������� ������ � ������� ���������� � ����� ������

	void setPlus(Fraction x1); // �������� ������ � �������� �����
	void setMinus(Fraction x1); // ��������� ������ � �������� �����
	void setDivide(Fraction x1); // ������� ������ � �������� �����
	void setMultiply(Fraction x1); // ��������� ������ � �������� �����
	
	void printPlus(Fraction x1, Fraction x2); // �������� ������ � ����� ���������� �� �����
	void printMinus(Fraction x1, Fraction x2); // ��������� ������ � ����� ���������� �� �����
	void printDivide(Fraction x1, Fraction x2); // ������� ������ � ����� ���������� �� �����
	void printMultiply(Fraction x1, Fraction x2); // ��������� ������ � ����� ���������� �� �����
};