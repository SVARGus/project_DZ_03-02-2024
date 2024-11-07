#include <iostream>
#include "HomePet.h"
#include "Shape.h"
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "Тестовый вывод задания #2 про животных" << endl;

    Dog* dog = new Dog("Шарик", "Черно белый", 15, 5);
    Cat* cat = new Cat("Мурзик", "Рыжий", 5, 3);
    Parrot* parrot = new Parrot("Кеша", "зелено голубой", 0.3, 1);
    dog->printPet();
    cout << endl;
    cat->printPet();
    cout << endl;
    parrot->printPet();
    cout << endl;

    cout << "Тестовый вывод задания #3 про фигуры" << endl;
    vector<Shape*> shapes{};
    // Добавление фигур в вектор
    shapes.push_back(new Square(5, 6, 15));
    shapes.push_back(new Rectangle(9, 4, 5, 10));
    shapes.push_back(new Circle(4, 2, 7));
    shapes.push_back(new Ellipse(0, 1, 5, 6));
    // Вывод фигур на экран
    for (auto* shape : shapes)
    {
        shape->Show();
    }
    SaveShapes(&shapes, "shapes.txt");
    cout << "\t---------------------------" << endl;
    vector<Shape*> newShapes{};
    LoadShapes(&newShapes, "shapes.txt");
    // Вывод фигур на экран из нового массива
    for (auto* shape : newShapes)
    {
        shape->Show();
    }

    return 0;
}