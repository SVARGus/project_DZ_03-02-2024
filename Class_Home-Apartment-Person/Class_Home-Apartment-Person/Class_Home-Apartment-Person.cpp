// Class_Home-Apartment-Person.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "HomeApartmentPerson.h"

int Apartment::count = 0;

int main()
{
    setlocale(LC_ALL, "ru");

    // Блок теста Персоны - позже закоментировать
    //Person First{ "Kuznetsov Pavel Nikolatvich", 35 }; // OK
    //First.print(); // OK
    //std::cout << First.getFIO() << " " << First.getAge() << std::endl; // OK
    //std::cout << "Введите ФИО и возраст: "; // OK
    //std::cin >> First; // OK
    //First.print(); // OK
    //Person Second = First; // OK
    //Second.print(); // OK
    
    // Конец блока теста Персоны
    //------------------------------------------------------------------
    // Блок теста Квартиры - позже закоментировать
    /*Person F1{ "Arg A G", 33 };
    Person F2{ "Kuz A G", 25 };
    Person F3{ "Lot A G", 15 };
    Person F4{ "Fiv A G", 27 };
    Person F5{ "Fist A G", 20 };
    Person F6{ "Arg V G", 56 };
    Person F7{ "Kuz T G", 12 };
    Person F8{ "Lot B G", 89 };
    Person F9{ "Fiv E G", 69 };
    Person F10{ "Fist U G", 45 };*/
    //Apartment First{ 2 }; // OK
    //First.freeRegistrPerson(F1);// OK
    //First.freeRegistrPerson(F2); // OK
    //First.freeRegistrPerson(F3); // OK
    //First.freeRegistrPerson(F4); // OK
    //First.freeRegistrPerson(F5); // OK
    //First.print(); // OK

    // Конец блока теста Квартиры

    // Блок теста Дома - позже закоментировать
    // 
    //std::string Street = "Nevsky";
    //int NumberHous{ 25 };
    //int floor{ 3 };
    //const int roomInFloor{ 5 }; // заменить позже на неконстантное значение
    //int numRoomApartFloor[roomInFloor]{ 2, 3, 1, 2, 1 }; // заменить на динамический массив
    //Home Hous1(Street, NumberHous, floor, roomInFloor, numRoomApartFloor); // OK
    //Hous1.print(); // OK
    // выше уже проверено ранее
    //Person* Register = new Person[10]{ { "Arg A G", 33 } ,{ "Gerald A F", 25 } ,{ "Mitchel N V", 45 } ,{ "Coins A G", 78 } ,{ "Kolt A G", 15 } ,{ "Keny A G", 5 } ,{ "Misisipy A G", 36 } ,{ "Rost A G", 16 } ,{ "Kent A G", 49 } ,{ "Karlos A G", 35 } };
    //Hous1.freeRegistrPersonInHome(F1, 1, 1);
    //F1.print(); // проверить на обнуление после прописки в дом // OK
    //Hous1.print(); // проверить прописался ли человек в квартиру (позже сделать метод для вывода конкретной квартиры) // OK
    //Hous1.freeRegistrPersonInHome(F1, 1, 1); // проверка попытки записи уже пустой персоны - должно выдать предупреждающее сообщение и не записать // OK
    //Hous1.print(); // повторная проверка

    // Конец теста блока Дома

    //Начало работы программы

    std::string Street{};
    int NumberHous{};
    int floor{};
    int roomInFloor{};
    int* numRoomApartFloor{};
    std::cout << "Укажите улицу дома: ";
    std::getline(std::cin, Street);
    std::cout << "Какой номер дома: ";
    std::cin >> NumberHous;
    std::cout << "Сколько этажей в доме: ";
    std::cin >> floor;
    std::cout << "Сколько квартир на этаже: ";
    std::cin >> roomInFloor;
    numRoomApartFloor = new int [roomInFloor] {};
    std::cout << "Укажитесколько комнат у каждой квартиры на этаже (от 1 до 3 комнат): ";
    for (int i = 0; i < roomInFloor; ++i)
    {
        std::cin >> numRoomApartFloor[i];
        while (numRoomApartFloor[i] < 1 || numRoomApartFloor[i] > 3)
        {
            std::cout << "Вы не корректно ввели количество комнат, укажите количество комнат в квартире от 1 до 3: ";
            std::cin >> numRoomApartFloor[i];
        }
    }
    Home Hous1(Street, NumberHous, floor, roomInFloor, numRoomApartFloor);
    std::string fio{};
    int age{};
    int appartNumber{};
    int menu{};
    Person personToRegister{"", 0};
    do
    {
        std::cout << "1 - Прописать новую личность в конкретную квартиру\n";
        std::cout << "2 - выписать личность для следующей записи в другую квартиру\n";
        std::cout << "3 - выписать личноть из дома\n";
        std::cout << "4 - Напечатать список прописанных в доме\n";
        std::cout << "5 - Напечатать список прописанных в конкретной квартире\n";
        std::cout << "0 - Выход\n";
        std::cin >> menu;
        switch (menu)
        {
        case 1:
            std::cout << "Напишите ФИО будущего квартиранта: ";
            std::getline(std::cin, fio);
            personToRegister.setFIO(fio);
            std::cout << "Сколько ему лет: ";
            std::cin >> age;
            personToRegister.setAge(age);
            std::cout << "Укажите номер квартиры: ";
            std::cin >> appartNumber;
            do
            {
                if (appartNumber > 0 && appartNumber <= Hous1.getApartmentInHous())
                    Hous1.freeRegistrPersonInHome(&personToRegister, appartNumber);
                else
                    std::cout << "Не верно указан номер квартиры" << std::endl;
            } while (appartNumber < 1 || appartNumber > Hous1.getApartmentInHous());
            //personToRegister.print(); // для проверки
            break;
        case 2:
            std::cout << "Укажите номер квартиры: ";
            std::cin >> appartNumber;
            do
            {
                if (appartNumber > 0 && appartNumber <= Hous1.getApartmentInHous())
                    Hous1.discharPersonInHome(personToRegister, appartNumber);
                else
                    std::cout << "Не верно указан номер квартиры" << std::endl;
            } while (appartNumber < 1 || appartNumber > Hous1.getApartmentInHous());
            std::cout << "Укажите номер квартиры куда записать персону: ";
            std::cin >> appartNumber;
            do
            {
                if (appartNumber > 0 && appartNumber <= Hous1.getApartmentInHous())
                    Hous1.freeRegistrPersonInHome(&personToRegister, appartNumber);
                else
                    std::cout << "Не верно указан номер квартиры" << std::endl;
            } while (appartNumber < 1 || appartNumber > Hous1.getApartmentInHous());
            //personToRegister.print(); // для проверки
            break;
        case 3:
            std::cout << "Укажите номер квартиры: ";
            std::cin >> appartNumber;
            do
            {
                if (appartNumber > 0 && appartNumber <= Hous1.getApartmentInHous())
                    Hous1.discharPersonInHome(appartNumber);
                else
                    std::cout << "Не верно указан номер квартиры" << std::endl;
            } while (appartNumber < 1 || appartNumber > Hous1.getApartmentInHous());
            break;
        case 4:
            Hous1.print();
            break;
        case 5:
            std::cout << "Укажите номер квартиры: "; 
            std::cin >> appartNumber;
            if (appartNumber > 0 && appartNumber <= Hous1.getApartmentInHous())
                Hous1[appartNumber].print();
            else
                std::cout << "Не верно указан номер квартиры" << std::endl;
            break;
        }
    } while (menu != 0);

    return 0;
}