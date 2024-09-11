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
        int i{ 1 };
        for (auto x : violations)
        {
            cout << "\t" << i++ <<") " << x << endl; // корректный вывод
            
        }
    }
    BaseViolationsCar operator= (const BaseViolationsCar & node){ // оператор копирования, копирует только значения, но не указатели на родителей и ветки дерева
        this->carNumber = node.carNumber;
        this->violations = node.violations;
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
    ////перегружены операторы для возможности сравнения в бинарном дереве с ключем
    //friend bool operator> (const BaseViolationsCar& node1, const string& node2) {
    //    return node1.carNumber >node2;
    //}
    //friend bool operator< (const BaseViolationsCar& node1, const string& node2) {
    //    return node1.carNumber < node2;
    //}
    //friend bool operator>= (const BaseViolationsCar& node1, const string& node2) {
    //    return !(node1.carNumber < node2);
    //}
    //friend bool operator<= (const BaseViolationsCar& node1, const string& node2) {
    //    return !(node1.carNumber > node2);
    //}
    //friend bool operator== (const BaseViolationsCar& node1, const string& node2) {
    //    return node1.carNumber == node2;
    //}
    //friend bool operator!= (const BaseViolationsCar& node1, const string& node2) {
    //    return !(node1.carNumber == node2);
    //}
};

class MyTree
{
    BaseViolationsCar* root;
public:
    MyTree() :root{ nullptr } {}
    ~MyTree() { Dell(); }
    void Print(); // печать всего дерева
    void Print(BaseViolationsCar* node); // Печать от указанного узла
    void Print(string* key1, string* key2); // Печать диапазона
    BaseViolationsCar* Search(string* key); // Поиск начиная от корня дерева
    BaseViolationsCar* Search(BaseViolationsCar* node, string* key); // поиск от указанного узла посредством ключа: номер машины "carNumber"
    BaseViolationsCar* Min(); // поиск минимального значения от корня дерева
    BaseViolationsCar* Min(BaseViolationsCar* node); // поиск минимального значения от указанного узла
    BaseViolationsCar* Max(); // поиск максимального значения от корня дерева
    BaseViolationsCar* Max(BaseViolationsCar* node); // поиск максимального значения от указанного узла
    BaseViolationsCar* Next(BaseViolationsCar* node); // следующий для указанного узла (надо изучить как правильно идти по ветке)
    BaseViolationsCar* Previous(BaseViolationsCar* node); // предыдущий от указанного узла
    void Add(BaseViolationsCar* z); // вставка узла
    void Dell(BaseViolationsCar* z = nullptr); // 0 удаление всего дерева, иначе указываем какой узел удалить
    BaseViolationsCar* GetRoot() { return root; }; // получение корня
};

