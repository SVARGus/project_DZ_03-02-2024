/*
Сконструируйте классы и отношения, описывающие следующие объекты:
транспортное средство как таковое vehicle
велосипед bicycle
спортивный велосипед sport_bicycle
классический велосипед classic_bicycle
детский велосипед children_bicycle
автосредство automobile
легковая машина car
автобус bus
грузовик truck

Дальше на ваше усмотрение и фантазию!

Для данной архитектуры определите общие и различные признаки.
Постройте иерархию классов, определите виртуальные функции,
методы и поля классов.

Создайте класс человек, который сможет хранить гараж транспортных средств
и сможет ими пользоваться, обслуживать, смотреть технические характеристики.

Наполните свое приложение необходимыми экземплярами и
продемонстрируйте работу ваших классов.
*/

#include <iostream>
#include "vehicle.h"
#include "person.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    setlocale(LC_ALL, "ru");

    person people{};
    //список транспортных средств для теста
    vehicle* bike1 = new sport_bicycle("Colnaga");
    vehicle* bike2 = new classic_bicycle("roller", 15);
    vehicle* bike3 = new children_bicycle("MiniBike");
    vehicle* car1 = new automobile_car("Honda", 5, 180, "read");
    vehicle* car2 = new automobile_bus("TrevelLine", 45, 100, "blue");
    vehicle* car3 = new automobile_truck("AmericanTrak", 3, 110, "orange");
    // добавление в гараж
    people.addGarage(bike1);
    people.addGarage(bike2);
    people.addGarage(bike3);
    people.addGarage(car1);
    people.addGarage(car2);
    people.addGarage(car3);
    // Тестовая реализация проверки корректности вывода информации о транспорте в гараже, его обслуживание и использование до реализации отдельных методов в классе person
    cout << "Выведем список транспортных средст из гаража: " << endl;
    for (auto it = people.garage.begin(); it != people.garage.end(); ++it)
    {
        (*it)->DisplaySpecifications();
        cout << endl;
    }
    cout << "-------------------------------------------" << endl;
    cout << "проведем обслуживание транспортных средст из гаража: " << endl;
    for (auto it = people.garage.begin(); it != people.garage.end(); ++it)
    {
        (*it)->ServiceVehicle();
        cout << endl;
    }
    int useVehicle{};
    cout << "Какое транспортное средство желаете использовать? (Укажите индекс) ";
    cin >> useVehicle;
    if (useVehicle >= 0 && useVehicle < people.garage.size())
    {
        people.garage[useVehicle]->UseVehicle();
    }
    else
    {
        cout << "Такого тнранспорта нету в гараже" << endl;
    }

    return 0;
}
