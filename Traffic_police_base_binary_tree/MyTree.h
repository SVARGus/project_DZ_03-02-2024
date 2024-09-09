#pragma once
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class BaseViolationsCar // Возможно переделать в класс. Добавить методы для печати - наверное лучше реализовать через "operator <<" (Но уже после упрощенной реализации)
{
public:
    string carNumber{}; // номер машины, будет ключем
    vector<string> violations{}; // список правонарушений реализую через вектор, продумать как добавлять данные через ввод с клавиатуры напрямую в вектор
    BaseViolationsCar* left;
    BaseViolationsCar* right;
    BaseViolationsCar* parent;

    // реализовать различные методы для удобства взаимодействия
    explicit BaseViolationsCar(string carNumber) : carNumber{ carNumber } { left = nullptr; right = nullptr; parent = nullptr; }
    void Print() {
        cout << "Номер машины - " << carNumber << endl;
        cout << "Список правонарушений: " << endl;
        for (auto x : violations)
        {
            int i{ 1 };
            cout << "/t" << i <<") " << x << endl; // проверить корректность вывода
        }
    }
    friend bool operator> (const BaseViolationsCar& node1, const BaseViolationsCar& node2) {
        return node1.carNumber > node2.carNumber;
    }
    friend bool operator< (const BaseViolationsCar& node1, const BaseViolationsCar& node2) {
        return node1.carNumber < node2.carNumber;
    }
    friend bool operator>= (const BaseViolationsCar& node1, const BaseViolationsCar& node2) {
        return !(node1.carNumber < node2.carNumber);
    }
    friend bool operator<= (const BaseViolationsCar& node1, const BaseViolationsCar& node2) {
        return !(node1.carNumber > node2.carNumber);
    }
    friend bool operator== (const BaseViolationsCar& node1, const BaseViolationsCar& node2) {
        return node1.carNumber == node2.carNumber;
    }
    friend bool operator!= (const BaseViolationsCar& node1, const BaseViolationsCar& node2) {
        return !(node1.carNumber == node2.carNumber);
    }
    //перегружены операторы для возможности сравнения в бинарном дереве с ключем
    friend bool operator> (const BaseViolationsCar& node1, const string& node2) {
        return node1.carNumber >node2;
    }
    friend bool operator< (const BaseViolationsCar& node1, const string& node2) {
        return node1.carNumber < node2;
    }
    friend bool operator>= (const BaseViolationsCar& node1, const string& node2) {
        return !(node1.carNumber < node2);
    }
    friend bool operator<= (const BaseViolationsCar& node1, const string& node2) {
        return !(node1.carNumber > node2);
    }
    friend bool operator== (const BaseViolationsCar& node1, const string& node2) {
        return node1.carNumber == node2;
    }
    friend bool operator!= (const BaseViolationsCar& node1, const string& node2) {
        return !(node1.carNumber == node2);
    }
};

class MyTree
{
    BaseViolationsCar* root;
public:
    MyTree() :root{ nullptr } {}
    ~MyTree() { Dell(); }
    void Print(BaseViolationsCar* node); // Печать от указанного узла
    void Print(BaseViolationsCar* node1, BaseViolationsCar* node2); // Печать от указанного первого узла и до указанного второго узла
    BaseViolationsCar* Search(BaseViolationsCar* node, string* key); // поиск от указанного узла посредством ключа: номер машины "carNumber"
    BaseViolationsCar* Min(BaseViolationsCar* node); // поиск минимального значения от указанного узла
    BaseViolationsCar* Max(BaseViolationsCar* node); // поиск максимального значения от указанного узла
    BaseViolationsCar* Next(BaseViolationsCar* node); // следующий для указанного узла (надо изучить как правильно идти по ветке)
    BaseViolationsCar* Previous(BaseViolationsCar* node); // предыдущий от указанного узла
    void Add(BaseViolationsCar* z); // вставка узла
    void Dell(BaseViolationsCar* z = 0); // 0 удаление всего дерева, иначе указываем какой узел удалить
    BaseViolationsCar* GetRoot(); // получение корня
};

