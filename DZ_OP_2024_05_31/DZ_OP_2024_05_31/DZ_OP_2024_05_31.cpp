// Домашнее задание по ОП от 31.05.2024

/*
Задание №1
Реализуйте класс Дробь. ...
*/

#include <iostream>
#include <string>
#include "Fraction.h"


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
    std::cout << "Давайте укажем Числитель дроби 1: ";
    std::cin >> Num1;
    std::cout << "Давайте укажем Знаменатель дроби 1: ";
    std::cin >> Num2;
    Les1.setNumDen(Num1, Num2);
    Les1.printFraction();
    std::cout << "Давайте укажем Числитель дроби 2: ";
    std::cin >> Num1;
    std::cout << "Давайте укажем Знаменатель дроби 2: ";
    std::cin >> Num2;
    Les2.setNumDen(Num1, Num2);
    Les2.printFraction();
    std::cout << "Давайте произведем вычисления с двумя дробями и запишем результат в новую дробь.\n1) Сложение.\n2) Вычитание.\n3) Деление.\n4) Умножение.\n0) Выход" << std::endl;
    Fraction Les3;
    enum Menu {EXIT, SUM, MINUS, DIVIDE, MULTIPLY};
    int Menu{};
    do
    {
        std::cin >> Menu;
        switch (Menu)
        {
        case EXIT:
            break;
        case SUM:
            Les3.setPlusNew(Les1, Les2);
            std::cout << "Результат вычислений:\n";
            Les3.printFraction;
            break;
        case MINUS:
            Les3.setMinusNew(Les1, Les2);
            std::cout << "Результат вычислений:\n";
            Les3.printFraction;
            break;
        case DIVIDE:
            Les3.setDivideNew(Les1, Les2);
            std::cout << "Результат вычислений:\n";
            Les3.printFraction;
            break;
        case MULTIPLY:
            Les3.setMultiplyNew(Les1, Les2);
            std::cout << "Результат вычислений:\n";
            Les3.printFraction;
            break;
        }
    } while (Menu != 0);

    return 0;
}

int main_2() // Задание 2 - Телефонная книга (приложение)
{
    setlocale(LC_ALL, "ru");



    return 0;
}