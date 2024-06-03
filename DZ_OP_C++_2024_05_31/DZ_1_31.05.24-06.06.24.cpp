// �������� ������� �� �� �� 31.05.2024

/*
������� �1
���������� ����� �����. ...
*/

#include <iostream>
#include <string>

class Fraction
{
    int Numeral;
    int Denominator;
public:
    void SetNumDen(int Num, int Den) {
        Numeral = Num;
        Denominator = Den;
    }
    void GetPrintNumDen() {
        std::cout << "��������� = " << Numeral << std::endl;
        std::cout << "����������� = " << Denominator << std::endl;
    }
    enum calculate { PLUS = 1, MINUS, DIVIDE, MULTIPLY };
    double Calculated(int calculate) {
        switch (calculate)
        {
        case PLUS:
            return Numeral + Denominator;
        case MINUS:
            return Numeral - Denominator;
        case DIVIDE:
            return (double)Numeral / Denominator;
        case MULTIPLY:
            return Numeral * Denominator;
        }
    }
};

class PhonePage // �������������� ������� ��� ���������� �����
{
    std::string Name;
    std::string Phone;
    unsigned short BirthDay : 6; // ��������� ������� ���� ��� �������� ������, ����� ����� �������� � ��������� ���������
    unsigned short BirthMounth : 5;
    unsigned short BirthYear : 12; // �������� �� ����������� ������������ ������� ����, ���� ������ ����� ��������� ������ ���� � ������������ ������� ��������

public:
    PhonePage() // ������������� ������������ ��� ������� �������������
    {
        Name = "NOT Name";
        Phone = "NOT Phone";
        BirthDay = 0;
        BirthMounth = 0;
        BirthYear = 0;
    }
    void SetName(std::string name) {
        Name = name;
    }
    void SetPhone(std::string phone) {
        Phone = phone;
    }
    void PrintPhonePage() {
        std::cout << "���: " << Name << std::endl;
        std::cout << "�������: " << Phone << std::endl;
        std::cout << "���� ��������: " << BirthDay << "." << BirthMounth << "." << BirthYear << std::endl;
    }
};


int main() // ������� 1 (���������)
{
    setlocale(LC_ALL, "ru");

    Fraction Les1;
    int Num1{};
    int Num2{};
    std::cout << "������� ������ ��������� �����: ";
    std::cin >> Num1;
    std::cout << "������� ������ ����������� �����: ";
    std::cin >> Num2;
    Les1.SetNumDen(Num1, Num2);
    Les1.GetPrintNumDen();
    std::cout << "������� ���������� ���������� � ����������� � �������������.\n1) ��������.\n2) ���������.\n3) �������.\n4) ���������.\n0) �����" << std::endl;
    int Menu{};
    do
    {
        std::cin >> Menu;
        std::cout << "��������� ���������� = " << Les1.Calculated(Menu) << std::endl;
    } while (Menu != 0);

    return 0;
}

int main_2() // ������� 2 - ���������� ����� (����������)
{
    setlocale(LC_ALL, "ru");



    return 0;
}