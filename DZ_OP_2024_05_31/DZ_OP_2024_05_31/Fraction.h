#pragma once

class Fraction
{
	int Numeral; // ���������
	int Denominator; // �����������

public:

	void setNumDen(int, int); // ������ ��������� � �����������
	int getNumeral(); // ����� ���������
	int getDenominator(); // ����� �����������
	int GCD(); // ���������� ���
	int GCD(Fraction x1, Fraction x2); // ���������� ��� ������������ ���� ������
	int LCM(); // ���������� ���
	int LCM(Fraction x1, Fraction x2); // ���������� ��� ������������ ���� ������
	void setPlusNew(Fraction x1, Fraction x2); // �������� ������ � ������� ���������� � ����� ������
	void setMinusNew(Fraction x1, Fraction x2); // ��������� ������ � ������� ���������� � ����� ������
	void setDivideNew(Fraction x1, Fraction x2); // ������� ������ � ������� ���������� � ����� ������
	void setMultiplyNew(Fraction x1, Fraction x2); // ��������� ������ � ������� ���������� � ����� ������

	//void setPlus(Fraction x1); // �������� ������ � �������� �����
	//void setMinus(Fraction x1); // ��������� ������ � �������� �����
	//void setDivide(Fraction x1); // ������� ������ � �������� �����
	//void setMultiply(Fraction x1); // ��������� ������ � �������� �����
	
	void printFraction(); // ����� �� ������ ��������
};