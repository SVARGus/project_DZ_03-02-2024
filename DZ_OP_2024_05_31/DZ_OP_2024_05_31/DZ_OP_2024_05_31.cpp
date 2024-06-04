// Домашнее задание по ОП от 31.05.2024

/*
Задание №1
Реализуйте класс Дробь. ...
*/

#include <iostream>
#include <string>

class Fraction
{
    int Numeral; // Числитель дроби
    int Denominator; // Знаменатель дроби
    int WholePart; // целая часть выделенная из неправельной дроби
public:
    void SetNumDen(int Num, int Den) // привидение из неправильной дроби в правильную надо выделить в отдельный метод (функцию)
    {
        int varibl{ 1 };
        if (Num < 0 && Den < 0) // -x/-y = x/y, также -x/y = x/-y, но в нашем случае лучше чтобы знаменатель был положительный всегда, так как пры вычитании и сложении дробей знаменатели обоих дробей должны быть приведены к общему знаменателю!
        {
            Num *= -1;
            Den *= -1;
        }
        else if (Num < 0)
        {
            Num *= -1;
            varibl = -1;
        }
        else if (Den < 0)
        {
            Den *= -1;
            varibl = -1;
        }
        if (Num >= Den)
        {
            WholePart = Num / Den;
            Numeral = Num - WholePart;
            Denominator = Den;
        }
        else
        {
            WholePart = 0;
            Numeral = Num;
            Denominator = Den;
        }
        ReductionFraction();
        if (WholePart > 0)
            WholePart *= varibl;
        else
            Numeral *= varibl;
    }
    void ReductionFraction() // сокращение дроби (например дроб 2/4 сократим до 1/2, при этом 2/4 = 1/2.
    {
        for (int i = 2; i <= Numeral; )
        {
            if (Numeral % i == 0 && Denominator % i == 0)
            {
                Numeral /= i;
                Denominator /= i;
            }
            else
                ++i;
        }
    }
    void WrongFraction() // приведение к неправильной дроби если есть целое число
    {
        if (WholePart > 0)
            Numeral *= WholePart;
    }
    double GetResFraction() // для необходимости вывода числа с плавающей запятой
    {
        if (WholePart > 0)
            return (WholePart * Numeral) / Denominator;
        return Numeral / Denominator;
    }
    void PrintNumDen() {
        std::cout << "Числитель = " << Numeral << std::endl;
        std::cout << "Знаменатель = " << Denominator << std::endl;
        if (WholePart > 0)
        {
            std::cout << "Челое число = " << WholePart << std::endl;
        }
    }
    enum calculate { PLUS = 1, MINUS, DIVIDE, MULTIPLY };
    int Calculated(int calculate, int Num1, int Den1, int Whol1, int Num2, int Den2, int Whol2) {
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
    Fraction Les2;
    int Num1{};
    int Num2{};
    std::cout << "Давайте укажем Числитель дроби: ";
    std::cin >> Num1;
    std::cout << "Давайте укажем Знаменатель дроби: ";
    std::cin >> Num2;
    Les1.SetNumDen(Num1, Num2);
    Les1.PrintNumDen();
    std::cout << "Давайте укажем Числитель дроби: ";
    std::cin >> Num1;
    std::cout << "Давайте укажем Знаменатель дроби: ";
    std::cin >> Num2;
    Les2.SetNumDen(Num1, Num2);
    Les2.PrintNumDen();
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