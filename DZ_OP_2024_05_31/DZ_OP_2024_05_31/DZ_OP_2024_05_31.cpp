// Домашнее задание по ОП от 31.05.2024

/*
Задание №1
Реализуйте класс Дробь. ...
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
        std::cout << "Числитель = " << Numeral << std::endl;
        std::cout << "Знаменатель = " << Denominator << std::endl;
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

class PhonePage // Проектирование Объекта для телефонной книги
{
    std::string Name;
    std::string Phone;
    unsigned short BirthDay : 6; // использую битовые поля для экономия памяти, может стоит выделить в отдельную структуру
    unsigned short BirthMounth : 5;
    unsigned short BirthYear : 12; // возможно не обязательно использовать битовые поля, если только позже добавятся другие поля с определенным битовым размером

public:
    PhonePage() // Использование конструктора для нулевой инициализации
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
        std::cout << "Имя: " << Name << std::endl;
        std::cout << "Телефон: " << Phone << std::endl;
        std::cout << "Дата рождения: " << BirthDay << "." << BirthMounth << "." << BirthYear << std::endl;
    }
};


int main() // Задание 1 (ЗАВЕРШЕНО)
{
    setlocale(LC_ALL, "ru");

    Fraction Les1;
    int Num1{};
    int Num2{};
    std::cout << "Давайте укажем Числитель дроби: ";
    std::cin >> Num1;
    std::cout << "Давайте укажем Знаменатель дроби: ";
    std::cin >> Num2;
    Les1.SetNumDen(Num1, Num2);
    Les1.GetPrintNumDen();
    std::cout << "Давайте произведем вычисления с Числителями и Знаменателями.\n1) Сложение.\n2) Вычитание.\n3) Деление.\n4) Умножение.\n0) Выход" << std::endl;
    int Menu{};
    do
    {
        std::cin >> Menu;
        std::cout << "Результат вычисления = " << Les1.Calculated(Menu) << std::endl;
    } while (Menu != 0);

    return 0;
}

int main_2() // Задание 2 - Телефонная книга (приложение)
{
    setlocale(LC_ALL, "ru");



    return 0;
}